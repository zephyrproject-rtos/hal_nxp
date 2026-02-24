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
**         CMSIS Peripheral Access Layer for DISPLAY_MIPI_DSI_PHY
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
 * @file PERI_DISPLAY_MIPI_DSI_PHY.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DISPLAY_MIPI_DSI_PHY
 *
 * CMSIS Peripheral Access Layer for DISPLAY_MIPI_DSI_PHY
 */

#if !defined(PERI_DISPLAY_MIPI_DSI_PHY_H_)
#define PERI_DISPLAY_MIPI_DSI_PHY_H_             /**< Symbol preventing repeated inclusion */

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
   -- DISPLAY_MIPI_DSI_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_MIPI_DSI_PHY_Peripheral_Access_Layer DISPLAY_MIPI_DSI_PHY Peripheral Access Layer
 * @{
 */

/** DISPLAY_MIPI_DSI_PHY - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12288];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_0;      /**< offset: 0x3000 */
       uint8_t RESERVED_1[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_1;      /**< offset: 0x3004 */
       uint8_t RESERVED_2[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_2;      /**< offset: 0x3008 */
       uint8_t RESERVED_3[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_3;      /**< offset: 0x300C */
       uint8_t RESERVED_4[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_4;      /**< offset: 0x3010 */
       uint8_t RESERVED_5[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_5;      /**< offset: 0x3014 */
       uint8_t RESERVED_6[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_6;      /**< offset: 0x3018 */
       uint8_t RESERVED_7[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_7;      /**< offset: 0x301C */
       uint8_t RESERVED_8[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_8;      /**< offset: 0x3020 */
       uint8_t RESERVED_9[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_9;      /**< offset: 0x3024 */
       uint8_t RESERVED_10[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_A;      /**< offset: 0x3028 */
       uint8_t RESERVED_11[22];
  __IO uint16_t PPI_STARTUP_RW_COMMON_DPHY_10;     /**< offset: 0x3040 */
       uint8_t RESERVED_12[2];
  __IO uint16_t PPI_STARTUP_RW_COMMON_STARTUP_1_1; /**< offset: 0x3044 */
       uint8_t RESERVED_13[58];
  __IO uint16_t PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0; /**< offset: 0x3080 */
       uint8_t RESERVED_14[2];
  __I  uint16_t PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_1; /**< offset: 0x3084 */
       uint8_t RESERVED_15[2];
  __I  uint16_t PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2; /**< offset: 0x3088 */
       uint8_t RESERVED_16[2];
  __I  uint16_t PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_3; /**< offset: 0x308C */
       uint8_t RESERVED_17[2];
  __I  uint16_t PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_4; /**< offset: 0x3090 */
       uint8_t RESERVED_18[2];
  __I  uint16_t PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5; /**< offset: 0x3094 */
       uint8_t RESERVED_19[2];
  __IO uint16_t PPI_CALIBCTRL_RW_COMMON_BG_0;      /**< offset: 0x3098 */
       uint8_t RESERVED_20[2];
  __IO uint16_t PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_7; /**< offset: 0x309C */
       uint8_t RESERVED_21[2];
  __IO uint16_t PPI_CALIBCTRL_RW_ADC_CFG_0;        /**< offset: 0x30A0 */
       uint8_t RESERVED_22[2];
  __IO uint16_t PPI_CALIBCTRL_RW_ADC_CFG_1;        /**< offset: 0x30A4 */
       uint8_t RESERVED_23[2];
  __I  uint16_t PPI_CALIBCTRL_R_ADC_DEBUG;         /**< offset: 0x30A8 */
       uint8_t RESERVED_24[1882];
  __IO uint16_t PPI_RW_LPDCOCAL_TIMEBASE;          /**< offset: 0x3804 */
       uint8_t RESERVED_25[2];
  __IO uint16_t PPI_RW_LPDCOCAL_NREF;              /**< offset: 0x3808 */
       uint8_t RESERVED_26[2];
  __IO uint16_t PPI_RW_LPDCOCAL_NREF_RANGE;        /**< offset: 0x380C */
       uint8_t RESERVED_27[6];
  __IO uint16_t PPI_RW_LPDCOCAL_TWAIT_CONFIG;      /**< offset: 0x3814 */
       uint8_t RESERVED_28[2];
  __IO uint16_t PPI_RW_LPDCOCAL_VT_CONFIG;         /**< offset: 0x3818 */
       uint8_t RESERVED_29[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_RB;           /**< offset: 0x381C */
       uint8_t RESERVED_30[2];
  __IO uint16_t PPI_RW_LPDCOCAL_COARSE_CFG;        /**< offset: 0x3820 */
       uint8_t RESERVED_31[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_COARSE_RB;    /**< offset: 0x3824 */
       uint8_t RESERVED_32[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_0_RB; /**< offset: 0x3828 */
       uint8_t RESERVED_33[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_1_RB; /**< offset: 0x382C */
       uint8_t RESERVED_34[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB; /**< offset: 0x3830 */
       uint8_t RESERVED_35[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_MEASURE_CURR_ERROR; /**< offset: 0x3834 */
       uint8_t RESERVED_36[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR; /**< offset: 0x3838 */
       uint8_t RESERVED_37[2];
  __I  uint16_t PPI_R_LPDCOCAL_DEBUG_VT;           /**< offset: 0x383C */
       uint8_t RESERVED_38[2];
  __IO uint16_t PPI_RW_LB_TIMEBASE_CONFIG;         /**< offset: 0x3840 */
       uint8_t RESERVED_39[2];
  __IO uint16_t PPI_RW_LB_STARTCMU_CONFIG;         /**< offset: 0x3844 */
       uint8_t RESERVED_40[2];
  __I  uint16_t PPI_R_LBPULSE_COUNTER_RB;          /**< offset: 0x3848 */
       uint8_t RESERVED_41[2];
  __I  uint16_t PPI_R_LB_START_CMU_RB;             /**< offset: 0x384C */
       uint8_t RESERVED_42[2];
  __IO uint16_t PPI_RW_LB_DPHY_BURST_START;        /**< offset: 0x3850 */
       uint8_t RESERVED_43[2];
  __IO uint16_t PPI_RW_LB_CPHY_BURST_START;        /**< offset: 0x3854 */
       uint8_t RESERVED_44[42];
  __IO uint16_t PPI_RW_DDLCAL_CFG_0;               /**< offset: 0x3880 */
       uint8_t RESERVED_45[2];
  __IO uint16_t PPI_RW_DDLCAL_CFG_1;               /**< offset: 0x3884 */
       uint8_t RESERVED_46[2];
  __IO uint16_t PPI_RW_DDLCAL_CFG_2;               /**< offset: 0x3888 */
       uint8_t RESERVED_47[2];
  __IO uint16_t PPI_RW_DDLCAL_CFG_3;               /**< offset: 0x388C */
       uint8_t RESERVED_48[2];
  __IO uint16_t PPI_RW_DDLCAL_CFG_4;               /**< offset: 0x3890 */
       uint8_t RESERVED_49[2];
  __IO uint16_t PPI_RW_DDLCAL_CFG_5;               /**< offset: 0x3894 */
       uint8_t RESERVED_50[2];
  __IO uint16_t PPI_RW_DDLCAL_CFG_6;               /**< offset: 0x3898 */
       uint8_t RESERVED_51[2];
  __IO uint16_t PPI_RW_DDLCAL_CFG_7;               /**< offset: 0x389C */
       uint8_t RESERVED_52[2];
  __I  uint16_t PPI_R_DDLCAL_DEBUG_0;              /**< offset: 0x38A0 */
       uint8_t RESERVED_53[2];
  __I  uint16_t PPI_R_DDLCAL_DEBUG_1;              /**< offset: 0x38A4 */
       uint8_t RESERVED_54[26];
  __IO uint16_t PPI_RW_PARITY_TEST;                /**< offset: 0x38C0 */
       uint8_t RESERVED_55[2];
  __IO uint16_t PPI_RW_STARTUP_OVR_0;              /**< offset: 0x38C4 */
       uint8_t RESERVED_56[2];
  __IO uint16_t PPI_RW_STARTUP_STATE_OVR_1;        /**< offset: 0x38C8 */
       uint8_t RESERVED_57[2];
  __IO uint16_t PPI_RW_DTB_SELECTOR;               /**< offset: 0x38CC */
       uint8_t RESERVED_58[2];
  __IO uint16_t PPI_RW_HSTX_FIFO_CFG;              /**< offset: 0x38D0 */
       uint8_t RESERVED_59[2];
  __IO uint16_t PPI_RW_DPHY_CLK_SPARE;             /**< offset: 0x38D4 */
       uint8_t RESERVED_60[2];
  __IO uint16_t PPI_RW_COMMON_CFG;                 /**< offset: 0x38D8 */
       uint8_t RESERVED_61[38];
  __IO uint16_t PPI_RW_TERMCAL_CFG_0;              /**< offset: 0x3900 */
       uint8_t RESERVED_62[2];
  __I  uint16_t PPI_R_TERMCAL_DEBUG_0;             /**< offset: 0x3904 */
       uint8_t RESERVED_63[58];
  __IO uint16_t PPI_RW_OFFSETCAL_CFG_0;            /**< offset: 0x3940 */
       uint8_t RESERVED_64[2];
  __I  uint16_t PPI_R_OFFSETCAL_DEBUG_LANE0;       /**< offset: 0x3944 */
       uint8_t RESERVED_65[2];
  __I  uint16_t PPI_R_OFFSETCAL_DEBUG_LANE1;       /**< offset: 0x3948 */
       uint8_t RESERVED_66[2];
  __I  uint16_t PPI_R_OFFSETCAL_DEBUG_LANE2;       /**< offset: 0x394C */
       uint8_t RESERVED_67[2];
  __I  uint16_t PPI_R_OFFSETCAL_DEBUG_LANE3;       /**< offset: 0x3950 */
       uint8_t RESERVED_68[2];
  __I  uint16_t PPI_R_OFFSETCAL_DEBUG_LANE4;       /**< offset: 0x3954 */
       uint8_t RESERVED_69[42];
  __IO uint16_t PPI_RW_PLL_STARTUP_CFG_0;          /**< offset: 0x3980 */
       uint8_t RESERVED_70[2];
  __IO uint16_t PPI_RW_PLL_STARTUP_CFG_1;          /**< offset: 0x3984 */
       uint8_t RESERVED_71[2];
  __IO uint16_t PPI_RW_PLL_STARTUP_CFG_2;          /**< offset: 0x3988 */
       uint8_t RESERVED_72[54];
  __IO uint16_t PPI_RW_TX_HIBERNATE_CFG_0;         /**< offset: 0x39C0 */
       uint8_t RESERVED_73[1726];
  __IO uint16_t CORE_DIG_IOCTRL_RW_AFE_LANE0_CTRL_2_0; /**< offset: 0x4080 */
       uint8_t RESERVED_74[382];
  __IO uint16_t CORE_DIG_RW_TRIO0_0;               /**< offset: 0x4200 */
       uint8_t RESERVED_75[2];
  __IO uint16_t CORE_DIG_RW_TRIO0_1;               /**< offset: 0x4204 */
       uint8_t RESERVED_76[2];
  __IO uint16_t CORE_DIG_RW_TRIO0_2;               /**< offset: 0x4208 */
       uint8_t RESERVED_77[1654];
  __IO uint16_t CORE_DIG_IOCTRL_RW_AFE_LANE1_CTRL_2_0; /**< offset: 0x4880 */
       uint8_t RESERVED_78[382];
  __IO uint16_t CORE_DIG_RW_TRIO1_0;               /**< offset: 0x4A00 */
       uint8_t RESERVED_79[2];
  __IO uint16_t CORE_DIG_RW_TRIO1_1;               /**< offset: 0x4A04 */
       uint8_t RESERVED_80[2];
  __IO uint16_t CORE_DIG_RW_TRIO1_2;               /**< offset: 0x4A08 */
       uint8_t RESERVED_81[1654];
  __IO uint16_t CORE_DIG_IOCTRL_RW_AFE_LANE2_CTRL_2_0; /**< offset: 0x5080 */
       uint8_t RESERVED_82[382];
  __IO uint16_t CORE_DIG_RW_TRIO2_0;               /**< offset: 0x5200 */
       uint8_t RESERVED_83[2];
  __IO uint16_t CORE_DIG_RW_TRIO2_1;               /**< offset: 0x5204 */
       uint8_t RESERVED_84[2];
  __IO uint16_t CORE_DIG_RW_TRIO2_2;               /**< offset: 0x5208 */
       uint8_t RESERVED_85[1654];
  __IO uint16_t CORE_DIG_IOCTRL_RW_AFE_LANE3_CTRL_2_0; /**< offset: 0x5880 */
       uint8_t RESERVED_86[2046];
  __IO uint16_t CORE_DIG_IOCTRL_RW_AFE_LANE4_CTRL_2_0; /**< offset: 0x6080 */
       uint8_t RESERVED_87[4222];
  __IO uint16_t CORE_DIG_RW_COMMON_0;              /**< offset: 0x7100 */
       uint8_t RESERVED_88[2];
  __IO uint16_t CORE_DIG_RW_COMMON_1;              /**< offset: 0x7104 */
       uint8_t RESERVED_89[2];
  __IO uint16_t CORE_DIG_RW_COMMON_2;              /**< offset: 0x7108 */
       uint8_t RESERVED_90[2];
  __IO uint16_t CORE_DIG_RW_COMMON_3;              /**< offset: 0x710C */
       uint8_t RESERVED_91[2];
  __IO uint16_t CORE_DIG_RW_COMMON_4;              /**< offset: 0x7110 */
       uint8_t RESERVED_92[2];
  __IO uint16_t CORE_DIG_RW_COMMON_5;              /**< offset: 0x7114 */
       uint8_t RESERVED_93[2];
  __IO uint16_t CORE_DIG_RW_COMMON_6;              /**< offset: 0x7118 */
       uint8_t RESERVED_94[2];
  __IO uint16_t CORE_DIG_RW_COMMON_7;              /**< offset: 0x711C */
       uint8_t RESERVED_95[2];
  __IO uint16_t CORE_DIG_RW_COMMON_8;              /**< offset: 0x7120 */
       uint8_t RESERVED_96[2];
  __IO uint16_t CORE_DIG_RW_COMMON_9;              /**< offset: 0x7124 */
       uint8_t RESERVED_97[2];
  __IO uint16_t CORE_DIG_RW_COMMON_10;             /**< offset: 0x7128 */
       uint8_t RESERVED_98[2];
  __IO uint16_t CORE_DIG_RW_COMMON_11;             /**< offset: 0x712C */
       uint8_t RESERVED_99[2];
  __IO uint16_t CORE_DIG_RW_COMMON_12;             /**< offset: 0x7130 */
       uint8_t RESERVED_100[2];
  __IO uint16_t CORE_DIG_RW_COMMON_13;             /**< offset: 0x7134 */
       uint8_t RESERVED_101[2];
  __IO uint16_t CORE_DIG_RW_COMMON_14;             /**< offset: 0x7138 */
       uint8_t RESERVED_102[2];
  __IO uint16_t CORE_DIG_RW_COMMON_15;             /**< offset: 0x713C */
       uint8_t RESERVED_103[642];
  __IO uint16_t CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0; /**< offset: 0x73C0 */
       uint8_t RESERVED_104[2];
  __IO uint16_t CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1; /**< offset: 0x73C4 */
       uint8_t RESERVED_105[6];
  __IO uint16_t CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3; /**< offset: 0x73CC */
       uint8_t RESERVED_106[3058];
  __IO uint16_t CORE_DIG_COMMON_RW_DESKEW_FINE_MEM; /**< offset: 0x7FC0 */
       uint8_t RESERVED_107[2];
  __I  uint16_t CORE_DIG_COMMON_R_DESKEW_FINE_MEM; /**< offset: 0x7FC4 */
       uint8_t RESERVED_108[62];
  __IO uint16_t PPI_RW_DPHY_LANE0_LBERT_1;         /**< offset: 0x8004 */
       uint8_t RESERVED_109[2];
  __I  uint16_t PPI_R_DPHY_LANE0_LBERT_0;          /**< offset: 0x8008 */
       uint8_t RESERVED_110[2];
  __I  uint16_t PPI_R_DPHY_LANE0_LBERT_1;          /**< offset: 0x800C */
       uint8_t RESERVED_111[2];
  __IO uint16_t PPI_RW_DPHY_LANE0_SPARE;           /**< offset: 0x8010 */
       uint8_t RESERVED_112[2034];
  __IO uint16_t PPI_RW_DPHY_LANE1_LBERT_1;         /**< offset: 0x8804 */
       uint8_t RESERVED_113[2];
  __I  uint16_t PPI_R_DPHY_LANE1_LBERT_0;          /**< offset: 0x8808 */
       uint8_t RESERVED_114[2];
  __I  uint16_t PPI_R_DPHY_LANE1_LBERT_1;          /**< offset: 0x880C */
       uint8_t RESERVED_115[2];
  __IO uint16_t PPI_RW_DPHY_LANE1_SPARE;           /**< offset: 0x8810 */
       uint8_t RESERVED_116[2034];
  __IO uint16_t PPI_RW_DPHY_LANE2_LBERT_1;         /**< offset: 0x9004 */
       uint8_t RESERVED_117[2];
  __I  uint16_t PPI_R_DPHY_LANE2_LBERT_0;          /**< offset: 0x9008 */
       uint8_t RESERVED_118[2];
  __I  uint16_t PPI_R_DPHY_LANE2_LBERT_1;          /**< offset: 0x900C */
       uint8_t RESERVED_119[2];
  __IO uint16_t PPI_RW_DPHY_LANE2_SPARE;           /**< offset: 0x9010 */
       uint8_t RESERVED_120[2034];
  __IO uint16_t PPI_RW_DPHY_LANE3_LBERT_1;         /**< offset: 0x9804 */
       uint8_t RESERVED_121[2];
  __I  uint16_t PPI_R_DPHY_LANE3_LBERT_0;          /**< offset: 0x9808 */
       uint8_t RESERVED_122[2];
  __I  uint16_t PPI_R_DPHY_LANE3_LBERT_1;          /**< offset: 0x980C */
       uint8_t RESERVED_123[2];
  __IO uint16_t PPI_RW_DPHY_LANE3_SPARE;           /**< offset: 0x9810 */
       uint8_t RESERVED_124[10222];
  __IO uint16_t CORE_DIG_DLANE_0_RW_CFG_0;         /**< offset: 0xC000 */
       uint8_t RESERVED_125[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_CFG_1;         /**< offset: 0xC004 */
       uint8_t RESERVED_126[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_CFG_2;         /**< offset: 0xC008 */
       uint8_t RESERVED_127[246];
  __IO uint16_t CORE_DIG_DLANE_0_RW_LP_0;          /**< offset: 0xC100 */
       uint8_t RESERVED_128[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_LP_1;          /**< offset: 0xC104 */
       uint8_t RESERVED_129[58];
  __I  uint16_t CORE_DIG_DLANE_0_R_LP_0;           /**< offset: 0xC140 */
       uint8_t RESERVED_130[2];
  __I  uint16_t CORE_DIG_DLANE_0_R_LP_1;           /**< offset: 0xC144 */
       uint8_t RESERVED_131[122];
  __I  uint16_t CORE_DIG_DLANE_0_R_HS_TX_0;        /**< offset: 0xC1C0 */
       uint8_t RESERVED_132[62];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_0;       /**< offset: 0xC200 */
       uint8_t RESERVED_133[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_1;       /**< offset: 0xC204 */
       uint8_t RESERVED_134[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_2;       /**< offset: 0xC208 */
       uint8_t RESERVED_135[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_3;       /**< offset: 0xC20C */
       uint8_t RESERVED_136[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_4;       /**< offset: 0xC210 */
       uint8_t RESERVED_137[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_5;       /**< offset: 0xC214 */
       uint8_t RESERVED_138[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_6;       /**< offset: 0xC218 */
       uint8_t RESERVED_139[6];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_RX_8;       /**< offset: 0xC220 */
       uint8_t RESERVED_140[30];
  __I  uint16_t CORE_DIG_DLANE_0_R_HS_RX_0;        /**< offset: 0xC240 */
       uint8_t RESERVED_141[2];
  __I  uint16_t CORE_DIG_DLANE_0_R_HS_RX_1;        /**< offset: 0xC244 */
       uint8_t RESERVED_142[2];
  __I  uint16_t CORE_DIG_DLANE_0_R_HS_RX_2;        /**< offset: 0xC248 */
       uint8_t RESERVED_143[2];
  __I  uint16_t CORE_DIG_DLANE_0_R_HS_RX_3;        /**< offset: 0xC24C */
       uint8_t RESERVED_144[2];
  __I  uint16_t CORE_DIG_DLANE_0_R_HS_RX_4;        /**< offset: 0xC250 */
       uint8_t RESERVED_145[430];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_0;       /**< offset: 0xC400 */
       uint8_t RESERVED_146[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_1;       /**< offset: 0xC404 */
       uint8_t RESERVED_147[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_2;       /**< offset: 0xC408 */
       uint8_t RESERVED_148[6];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_4;       /**< offset: 0xC410 */
       uint8_t RESERVED_149[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_5;       /**< offset: 0xC414 */
       uint8_t RESERVED_150[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_6;       /**< offset: 0xC418 */
       uint8_t RESERVED_151[6];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_8;       /**< offset: 0xC420 */
       uint8_t RESERVED_152[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_9;       /**< offset: 0xC424 */
       uint8_t RESERVED_153[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_10;      /**< offset: 0xC428 */
       uint8_t RESERVED_154[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_11;      /**< offset: 0xC42C */
       uint8_t RESERVED_155[2];
  __IO uint16_t CORE_DIG_DLANE_0_RW_HS_TX_12;      /**< offset: 0xC430 */
       uint8_t RESERVED_156[974];
  __IO uint16_t CORE_DIG_DLANE_1_RW_CFG_0;         /**< offset: 0xC800 */
       uint8_t RESERVED_157[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_CFG_1;         /**< offset: 0xC804 */
       uint8_t RESERVED_158[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_CFG_2;         /**< offset: 0xC808 */
       uint8_t RESERVED_159[246];
  __IO uint16_t CORE_DIG_DLANE_1_RW_LP_0;          /**< offset: 0xC900 */
       uint8_t RESERVED_160[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_LP_1;          /**< offset: 0xC904 */
       uint8_t RESERVED_161[58];
  __I  uint16_t CORE_DIG_DLANE_1_R_LP_0;           /**< offset: 0xC940 */
       uint8_t RESERVED_162[2];
  __I  uint16_t CORE_DIG_DLANE_1_R_LP_1;           /**< offset: 0xC944 */
       uint8_t RESERVED_163[122];
  __I  uint16_t CORE_DIG_DLANE_1_R_HS_TX_0;        /**< offset: 0xC9C0 */
       uint8_t RESERVED_164[62];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_0;       /**< offset: 0xCA00 */
       uint8_t RESERVED_165[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_1;       /**< offset: 0xCA04 */
       uint8_t RESERVED_166[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_2;       /**< offset: 0xCA08 */
       uint8_t RESERVED_167[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_3;       /**< offset: 0xCA0C */
       uint8_t RESERVED_168[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_4;       /**< offset: 0xCA10 */
       uint8_t RESERVED_169[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_5;       /**< offset: 0xCA14 */
       uint8_t RESERVED_170[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_6;       /**< offset: 0xCA18 */
       uint8_t RESERVED_171[6];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_RX_8;       /**< offset: 0xCA20 */
       uint8_t RESERVED_172[30];
  __I  uint16_t CORE_DIG_DLANE_1_R_HS_RX_0;        /**< offset: 0xCA40 */
       uint8_t RESERVED_173[2];
  __I  uint16_t CORE_DIG_DLANE_1_R_HS_RX_1;        /**< offset: 0xCA44 */
       uint8_t RESERVED_174[2];
  __I  uint16_t CORE_DIG_DLANE_1_R_HS_RX_2;        /**< offset: 0xCA48 */
       uint8_t RESERVED_175[2];
  __I  uint16_t CORE_DIG_DLANE_1_R_HS_RX_3;        /**< offset: 0xCA4C */
       uint8_t RESERVED_176[2];
  __I  uint16_t CORE_DIG_DLANE_1_R_HS_RX_4;        /**< offset: 0xCA50 */
       uint8_t RESERVED_177[430];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_0;       /**< offset: 0xCC00 */
       uint8_t RESERVED_178[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_1;       /**< offset: 0xCC04 */
       uint8_t RESERVED_179[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_2;       /**< offset: 0xCC08 */
       uint8_t RESERVED_180[6];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_4;       /**< offset: 0xCC10 */
       uint8_t RESERVED_181[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_5;       /**< offset: 0xCC14 */
       uint8_t RESERVED_182[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_6;       /**< offset: 0xCC18 */
       uint8_t RESERVED_183[6];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_8;       /**< offset: 0xCC20 */
       uint8_t RESERVED_184[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_9;       /**< offset: 0xCC24 */
       uint8_t RESERVED_185[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_10;      /**< offset: 0xCC28 */
       uint8_t RESERVED_186[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_11;      /**< offset: 0xCC2C */
       uint8_t RESERVED_187[2];
  __IO uint16_t CORE_DIG_DLANE_1_RW_HS_TX_12;      /**< offset: 0xCC30 */
       uint8_t RESERVED_188[974];
  __IO uint16_t CORE_DIG_DLANE_2_RW_CFG_0;         /**< offset: 0xD000 */
       uint8_t RESERVED_189[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_CFG_1;         /**< offset: 0xD004 */
       uint8_t RESERVED_190[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_CFG_2;         /**< offset: 0xD008 */
       uint8_t RESERVED_191[246];
  __IO uint16_t CORE_DIG_DLANE_2_RW_LP_0;          /**< offset: 0xD100 */
       uint8_t RESERVED_192[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_LP_1;          /**< offset: 0xD104 */
       uint8_t RESERVED_193[58];
  __I  uint16_t CORE_DIG_DLANE_2_R_LP_0;           /**< offset: 0xD140 */
       uint8_t RESERVED_194[2];
  __I  uint16_t CORE_DIG_DLANE_2_R_LP_1;           /**< offset: 0xD144 */
       uint8_t RESERVED_195[122];
  __I  uint16_t CORE_DIG_DLANE_2_R_HS_TX_0;        /**< offset: 0xD1C0 */
       uint8_t RESERVED_196[62];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_0;       /**< offset: 0xD200 */
       uint8_t RESERVED_197[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_1;       /**< offset: 0xD204 */
       uint8_t RESERVED_198[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_2;       /**< offset: 0xD208 */
       uint8_t RESERVED_199[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_3;       /**< offset: 0xD20C */
       uint8_t RESERVED_200[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_4;       /**< offset: 0xD210 */
       uint8_t RESERVED_201[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_5;       /**< offset: 0xD214 */
       uint8_t RESERVED_202[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_6;       /**< offset: 0xD218 */
       uint8_t RESERVED_203[6];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_RX_8;       /**< offset: 0xD220 */
       uint8_t RESERVED_204[30];
  __I  uint16_t CORE_DIG_DLANE_2_R_HS_RX_0;        /**< offset: 0xD240 */
       uint8_t RESERVED_205[2];
  __I  uint16_t CORE_DIG_DLANE_2_R_HS_RX_1;        /**< offset: 0xD244 */
       uint8_t RESERVED_206[2];
  __I  uint16_t CORE_DIG_DLANE_2_R_HS_RX_2;        /**< offset: 0xD248 */
       uint8_t RESERVED_207[2];
  __I  uint16_t CORE_DIG_DLANE_2_R_HS_RX_3;        /**< offset: 0xD24C */
       uint8_t RESERVED_208[2];
  __I  uint16_t CORE_DIG_DLANE_2_R_HS_RX_4;        /**< offset: 0xD250 */
       uint8_t RESERVED_209[430];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_0;       /**< offset: 0xD400 */
       uint8_t RESERVED_210[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_1;       /**< offset: 0xD404 */
       uint8_t RESERVED_211[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_2;       /**< offset: 0xD408 */
       uint8_t RESERVED_212[6];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_4;       /**< offset: 0xD410 */
       uint8_t RESERVED_213[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_5;       /**< offset: 0xD414 */
       uint8_t RESERVED_214[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_6;       /**< offset: 0xD418 */
       uint8_t RESERVED_215[6];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_8;       /**< offset: 0xD420 */
       uint8_t RESERVED_216[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_9;       /**< offset: 0xD424 */
       uint8_t RESERVED_217[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_10;      /**< offset: 0xD428 */
       uint8_t RESERVED_218[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_11;      /**< offset: 0xD42C */
       uint8_t RESERVED_219[2];
  __IO uint16_t CORE_DIG_DLANE_2_RW_HS_TX_12;      /**< offset: 0xD430 */
       uint8_t RESERVED_220[974];
  __IO uint16_t CORE_DIG_DLANE_3_RW_CFG_0;         /**< offset: 0xD800 */
       uint8_t RESERVED_221[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_CFG_1;         /**< offset: 0xD804 */
       uint8_t RESERVED_222[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_CFG_2;         /**< offset: 0xD808 */
       uint8_t RESERVED_223[246];
  __IO uint16_t CORE_DIG_DLANE_3_RW_LP_0;          /**< offset: 0xD900 */
       uint8_t RESERVED_224[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_LP_1;          /**< offset: 0xD904 */
       uint8_t RESERVED_225[58];
  __I  uint16_t CORE_DIG_DLANE_3_R_LP_0;           /**< offset: 0xD940 */
       uint8_t RESERVED_226[2];
  __I  uint16_t CORE_DIG_DLANE_3_R_LP_1;           /**< offset: 0xD944 */
       uint8_t RESERVED_227[122];
  __I  uint16_t CORE_DIG_DLANE_3_R_HS_TX_0;        /**< offset: 0xD9C0 */
       uint8_t RESERVED_228[62];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_0;       /**< offset: 0xDA00 */
       uint8_t RESERVED_229[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_1;       /**< offset: 0xDA04 */
       uint8_t RESERVED_230[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_2;       /**< offset: 0xDA08 */
       uint8_t RESERVED_231[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_3;       /**< offset: 0xDA0C */
       uint8_t RESERVED_232[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_4;       /**< offset: 0xDA10 */
       uint8_t RESERVED_233[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_5;       /**< offset: 0xDA14 */
       uint8_t RESERVED_234[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_6;       /**< offset: 0xDA18 */
       uint8_t RESERVED_235[6];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_RX_8;       /**< offset: 0xDA20 */
       uint8_t RESERVED_236[30];
  __I  uint16_t CORE_DIG_DLANE_3_R_HS_RX_0;        /**< offset: 0xDA40 */
       uint8_t RESERVED_237[2];
  __I  uint16_t CORE_DIG_DLANE_3_R_HS_RX_1;        /**< offset: 0xDA44 */
       uint8_t RESERVED_238[2];
  __I  uint16_t CORE_DIG_DLANE_3_R_HS_RX_2;        /**< offset: 0xDA48 */
       uint8_t RESERVED_239[2];
  __I  uint16_t CORE_DIG_DLANE_3_R_HS_RX_3;        /**< offset: 0xDA4C */
       uint8_t RESERVED_240[2];
  __I  uint16_t CORE_DIG_DLANE_3_R_HS_RX_4;        /**< offset: 0xDA50 */
       uint8_t RESERVED_241[430];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_0;       /**< offset: 0xDC00 */
       uint8_t RESERVED_242[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_1;       /**< offset: 0xDC04 */
       uint8_t RESERVED_243[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_2;       /**< offset: 0xDC08 */
       uint8_t RESERVED_244[6];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_4;       /**< offset: 0xDC10 */
       uint8_t RESERVED_245[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_5;       /**< offset: 0xDC14 */
       uint8_t RESERVED_246[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_6;       /**< offset: 0xDC18 */
       uint8_t RESERVED_247[6];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_8;       /**< offset: 0xDC20 */
       uint8_t RESERVED_248[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_9;       /**< offset: 0xDC24 */
       uint8_t RESERVED_249[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_10;      /**< offset: 0xDC28 */
       uint8_t RESERVED_250[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_11;      /**< offset: 0xDC2C */
       uint8_t RESERVED_251[2];
  __IO uint16_t CORE_DIG_DLANE_3_RW_HS_TX_12;      /**< offset: 0xDC30 */
       uint8_t RESERVED_252[974];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_CFG_0;       /**< offset: 0xE000 */
       uint8_t RESERVED_253[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_CFG_1;       /**< offset: 0xE004 */
       uint8_t RESERVED_254[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_CFG_2;       /**< offset: 0xE008 */
       uint8_t RESERVED_255[246];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_LP_0;        /**< offset: 0xE100 */
       uint8_t RESERVED_256[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_LP_1;        /**< offset: 0xE104 */
       uint8_t RESERVED_257[58];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_LP_0;         /**< offset: 0xE140 */
       uint8_t RESERVED_258[2];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_LP_1;         /**< offset: 0xE144 */
       uint8_t RESERVED_259[122];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_HS_TX_0;      /**< offset: 0xE1C0 */
       uint8_t RESERVED_260[62];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_0;     /**< offset: 0xE200 */
       uint8_t RESERVED_261[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_1;     /**< offset: 0xE204 */
       uint8_t RESERVED_262[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_2;     /**< offset: 0xE208 */
       uint8_t RESERVED_263[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_3;     /**< offset: 0xE20C */
       uint8_t RESERVED_264[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_4;     /**< offset: 0xE210 */
       uint8_t RESERVED_265[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_5;     /**< offset: 0xE214 */
       uint8_t RESERVED_266[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_6;     /**< offset: 0xE218 */
       uint8_t RESERVED_267[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_7;     /**< offset: 0xE21C */
       uint8_t RESERVED_268[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_RX_8;     /**< offset: 0xE220 */
       uint8_t RESERVED_269[30];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_HS_RX_0;      /**< offset: 0xE240 */
       uint8_t RESERVED_270[2];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_HS_RX_1;      /**< offset: 0xE244 */
       uint8_t RESERVED_271[2];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_HS_RX_2;      /**< offset: 0xE248 */
       uint8_t RESERVED_272[2];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_HS_RX_3;      /**< offset: 0xE24C */
       uint8_t RESERVED_273[2];
  __I  uint16_t CORE_DIG_DLANE_CLK_R_HS_RX_4;      /**< offset: 0xE250 */
       uint8_t RESERVED_274[430];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_0;     /**< offset: 0xE400 */
       uint8_t RESERVED_275[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_1;     /**< offset: 0xE404 */
       uint8_t RESERVED_276[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_2;     /**< offset: 0xE408 */
       uint8_t RESERVED_277[6];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_4;     /**< offset: 0xE410 */
       uint8_t RESERVED_278[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_5;     /**< offset: 0xE414 */
       uint8_t RESERVED_279[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_6;     /**< offset: 0xE418 */
       uint8_t RESERVED_280[6];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_8;     /**< offset: 0xE420 */
       uint8_t RESERVED_281[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_9;     /**< offset: 0xE424 */
       uint8_t RESERVED_282[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_10;    /**< offset: 0xE428 */
       uint8_t RESERVED_283[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_11;    /**< offset: 0xE42C */
       uint8_t RESERVED_284[2];
  __IO uint16_t CORE_DIG_DLANE_CLK_RW_HS_TX_12;    /**< offset: 0xE430 */
       uint8_t RESERVED_285[23502];
  __IO uint16_t CORE_DIG_CLANE_0_RW_CFG_0;         /**< offset: 0x14000 */
       uint8_t RESERVED_286[1046];
  __IO uint16_t CORE_DIG_CLANE_0_RW_HS_TX_6;       /**< offset: 0x14418 */
       uint8_t RESERVED_287[998];
  __IO uint16_t CORE_DIG_CLANE_1_RW_CFG_0;         /**< offset: 0x14800 */
       uint8_t RESERVED_288[1046];
  __IO uint16_t CORE_DIG_CLANE_1_RW_HS_TX_6;       /**< offset: 0x14C18 */
       uint8_t RESERVED_289[998];
  __IO uint16_t CORE_DIG_CLANE_2_RW_CFG_0;         /**< offset: 0x15000 */
       uint8_t RESERVED_290[1046];
  __IO uint16_t CORE_DIG_CLANE_2_RW_HS_TX_6;       /**< offset: 0x15418 */
} DISPLAY_MIPI_DSI_PHY_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_MIPI_DSI_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_MIPI_DSI_PHY_Register_Masks DISPLAY_MIPI_DSI_PHY Register Masks
 * @{
 */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_0_PWR_DWN_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_0_PWR_DWN_addr_SHIFT (0U)
/*! PWR_DWN_addr - Configures behavior of PWR_DWN state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_0_PWR_DWN_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_0_PWR_DWN_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_0_PWR_DWN_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_1_BG_ON_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_1_BG_ON_addr_SHIFT (0U)
/*! BG_ON_addr - Configures behavior of BG_ON_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_1_BG_ON_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_1_BG_ON_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_1_BG_ON_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_2_RCAL_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_2_RCAL_addr_SHIFT (0U)
/*! RCAL_addr - Configures behavior of RCAL_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_2_RCAL_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_2_RCAL_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_2_RCAL_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_3_PLL_START_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_3_PLL_START_addr_SHIFT (0U)
/*! PLL_START_addr - Configures behavior of PLL_START_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_3_PLL_START_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_3_PLL_START_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_3_PLL_START_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_4_HS_DCO_CAL_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_4_HS_DCO_CAL_addr_SHIFT (0U)
/*! HS_DCO_CAL_addr - Configures behavior of HS_DCO_CAL_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_4_HS_DCO_CAL_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_4_HS_DCO_CAL_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_4_HS_DCO_CAL_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_5_OFFSET_CAL_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_5_OFFSET_CAL_addr_SHIFT (0U)
/*! OFFSET_CAL_addr - Configures behavior of OFFSET_CAL_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_5_OFFSET_CAL_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_5_OFFSET_CAL_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_5_OFFSET_CAL_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_6_LP_DCO_CAL_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_6_LP_DCO_CAL_addr_SHIFT (0U)
/*! LP_DCO_CAL_addr - Configures behavior of LP_DCO_CAL_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_6_LP_DCO_CAL_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_6_LP_DCO_CAL_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_6_LP_DCO_CAL_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_7 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_7_DPHY_DDL_CAL_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_7_DPHY_DDL_CAL_addr_SHIFT (0U)
/*! DPHY_DDL_CAL_addr - Configures behavior of DPHY_DDL_CAL_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_7_DPHY_DDL_CAL_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_7_DPHY_DDL_CAL_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_7_DPHY_DDL_CAL_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_8_CPHY_DDL_CAL_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_8_CPHY_DDL_CAL_addr_SHIFT (0U)
/*! CPHY_DDL_CAL_addr - Configures behavior of CPHY_DDL_CAL_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_8_CPHY_DDL_CAL_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_8_CPHY_DDL_CAL_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_8_CPHY_DDL_CAL_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_9 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_9_DESKEW_1P1_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_9_DESKEW_1P1_addr_SHIFT (0U)
/*! DESKEW_1P1_addr - Configures behavior of DESKEW_1P1_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_9_DESKEW_1P1_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_9_DESKEW_1P1_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_9_DESKEW_1P1_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_A -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_A_HIBERNATE_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_A_HIBERNATE_addr_SHIFT (0U)
/*! HIBERNATE_addr - Configures behavior of HIBERNATE_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_A_HIBERNATE_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_A_HIBERNATE_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_A_HIBERNATE_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_DPHY_10 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_10_PHY_READY_addr_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_10_PHY_READY_addr_SHIFT (0U)
/*! PHY_READY_addr - Configures behavior of PHY_READY_addr state. */
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_10_PHY_READY_addr(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_10_PHY_READY_addr_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_DPHY_10_PHY_READY_addr_MASK)
/*! @} */

/*! @name PPI_STARTUP_RW_COMMON_STARTUP_1_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_STARTUP_1_1_PHY_READY_DLY_MASK (0xFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_STARTUP_1_1_PHY_READY_DLY_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_STARTUP_1_1_PHY_READY_DLY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_STARTUP_1_1_PHY_READY_DLY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_STARTUP_RW_COMMON_STARTUP_1_1_PHY_READY_DLY_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_LAST_MASK (0x1FU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_LAST_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_LAST(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_LAST_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_LAST_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_EN_MASK (0x3E0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_EN_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_LANE_CALIB_OFFSETCAL_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_OFFSETCAL_RECALIBRATION_EN_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_OFFSETCAL_RECALIBRATION_EN_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_OFFSETCAL_RECALIBRATION_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_OFFSETCAL_RECALIBRATION_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_OFFSETCAL_RECALIBRATION_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_TERMCAL_RECALIBRATION_EN_MASK (0x800U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_TERMCAL_RECALIBRATION_EN_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_TERMCAL_RECALIBRATION_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_TERMCAL_RECALIBRATION_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_0_TERMCAL_RECALIBRATION_EN_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_1_DDL_COUNTER_TARGET_OBS_LSBs_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_1_DDL_COUNTER_TARGET_OBS_LSBs_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_1_DDL_COUNTER_TARGET_OBS_LSBs(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_1_DDL_COUNTER_TARGET_OBS_LSBs_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_1_DDL_COUNTER_TARGET_OBS_LSBs_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_TARGET_OBS_MSBs_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_TARGET_OBS_MSBs_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_TARGET_OBS_MSBs(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_TARGET_OBS_MSBs_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_TARGET_OBS_MSBs_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_MULT_OBS_LSBs_MASK (0xFFF0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_MULT_OBS_LSBs_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_MULT_OBS_LSBs(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_MULT_OBS_LSBs_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_2_DDL_COUNTER_MULT_OBS_LSBs_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_3_DDL_COUNTER_MULT_OBS_MSBs_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_3_DDL_COUNTER_MULT_OBS_MSBs_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_3_DDL_COUNTER_MULT_OBS_MSBs(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_3_DDL_COUNTER_MULT_OBS_MSBs_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_3_DDL_COUNTER_MULT_OBS_MSBs_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_4_DDL_COUNTER_SUM_OBS_MASK (0x7FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_4_DDL_COUNTER_SUM_OBS_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_4_DDL_COUNTER_SUM_OBS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_4_DDL_COUNTER_SUM_OBS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_4_DDL_COUNTER_SUM_OBS_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS0_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS0_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS0(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS0_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS0_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS1_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS1_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS1(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS1_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS1_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS2_MASK (0xF00U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS2_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS2(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS2_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS2_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS3_MASK (0xF000U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS3_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS3(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS3_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_COMMON_CALIBCTRL_2_5_DDL_CAL_STATUS3_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_RW_COMMON_BG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_BG_0_BG_MAX_COUNTER_MASK (0x1FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_BG_0_BG_MAX_COUNTER_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_BG_0_BG_MAX_COUNTER(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_BG_0_BG_MAX_COUNTER_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_BG_0_BG_MAX_COUNTER_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_7 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_7_STATE_DONE_TIMER_THRES_MASK (0x1FU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_7_STATE_DONE_TIMER_THRES_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_7_STATE_DONE_TIMER_THRES(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_7_STATE_DONE_TIMER_THRES_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_COMMON_CALIBCTRL_2_7_STATE_DONE_TIMER_THRES_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_RW_ADC_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_0_ADC_ENB_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_0_ADC_ENB_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_0_ADC_ENB(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_0_ADC_ENB_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_0_ADC_ENB_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_RW_ADC_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T1_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T1_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T1(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T1_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T1_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T2_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T2_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T2(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T2_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_RW_ADC_CFG_1_ADC_WAIT_THRESH_T2_MASK)
/*! @} */

/*! @name PPI_CALIBCTRL_R_ADC_DEBUG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_CB_ATB_SEL_DAC_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_CB_ATB_SEL_DAC_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_CB_ATB_SEL_DAC(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_CB_ATB_SEL_DAC_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_CB_ATB_SEL_DAC_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_ADC_DONE_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_ADC_DONE_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_ADC_DONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_ADC_DONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_CALIBCTRL_R_ADC_DEBUG_ADC_DONE_MASK)
/*! @} */

/*! @name PPI_RW_LPDCOCAL_TIMEBASE -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TIMEBASE_LPCDCOCAL_TIMEBASE_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TIMEBASE_LPCDCOCAL_TIMEBASE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TIMEBASE_LPCDCOCAL_TIMEBASE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TIMEBASE_LPCDCOCAL_TIMEBASE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TIMEBASE_LPCDCOCAL_TIMEBASE_MASK)
/*! @} */

/*! @name PPI_RW_LPDCOCAL_NREF -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_LPCDCOCAL_NREF_MASK (0x7FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_LPCDCOCAL_NREF_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_LPCDCOCAL_NREF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_LPCDCOCAL_NREF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_LPCDCOCAL_NREF_MASK)
/*! @} */

/*! @name PPI_RW_LPDCOCAL_NREF_RANGE -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_RANGE_LPCDCOCAL_NREF_RANGE_MASK (0x1FU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_RANGE_LPCDCOCAL_NREF_RANGE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_RANGE_LPCDCOCAL_NREF_RANGE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_RANGE_LPCDCOCAL_NREF_RANGE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_NREF_RANGE_LPCDCOCAL_NREF_RANGE_MASK)
/*! @} */

/*! @name PPI_RW_LPDCOCAL_TWAIT_CONFIG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_COARSE_MASK (0x1FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_COARSE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_COARSE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_COARSE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_COARSE_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_PON_MASK (0xFE00U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_PON_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_PON(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_PON_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_TWAIT_CONFIG_LPCDCOCAL_TWAIT_PON_MASK)
/*! @} */

/*! @name PPI_RW_LPDCOCAL_VT_CONFIG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_TRACKING_EN_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_TRACKING_EN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_TRACKING_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_TRACKING_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_TRACKING_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_USE_IDEAL_NREF_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_USE_IDEAL_NREF_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_USE_IDEAL_NREF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_USE_IDEAL_NREF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_USE_IDEAL_NREF_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_NREF_RANGE_MASK (0x7CU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_NREF_RANGE_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_NREF_RANGE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_NREF_RANGE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_VT_NREF_RANGE_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_TWAIT_FINE_MASK (0xFF80U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_TWAIT_FINE_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_TWAIT_FINE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_TWAIT_FINE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_VT_CONFIG_LPCDCOCAL_TWAIT_FINE_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_RB -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_MASK (0x7FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_RB_MASK (0x800U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_RB_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_RB(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_RB_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_RB_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_CAL_DONE_MASK (0x1000U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_CAL_DONE_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_CAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_CAL_DONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_CAL_DONE_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_DONE_MASK (0x2000U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_DONE_SHIFT (13U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_DONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_DONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_N_MEAS_DONE_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_VT_RB_MASK (0x4000U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_VT_RB_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_VT_RB(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_VT_RB_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_RB_LPDCOCAL_ERROR_VT_RB_MASK)
/*! @} */

/*! @name PPI_RW_LPDCOCAL_COARSE_CFG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_START_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_START_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_START(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_START_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_START_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_DIAG_MASK (0xCU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_DIAG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_DIAG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_DIAG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_NCOARSE_DIAG_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_SCALE_REF_MASK (0x1F0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_SCALE_REF_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_SCALE_REF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_SCALE_REF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LPDCOCAL_COARSE_CFG_SCALE_REF_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_COARSE_RB -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_BOUND_STATUS_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_BOUND_STATUS_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_BOUND_STATUS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_BOUND_STATUS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_BOUND_STATUS_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_COARSE_HIT_MASK (0x3CU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_COARSE_HIT_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_COARSE_HIT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_COARSE_HIT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_CAL_COARSE_HIT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_PON_STATE_MASK (0x3C0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_PON_STATE_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_PON_STATE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_PON_STATE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_RB_LPDCOCAL_PON_STATE_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_0_RB -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_0_RB_LPDCOCAL_STORED_MEAS_0_MASK (0x7FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_0_RB_LPDCOCAL_STORED_MEAS_0_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_0_RB_LPDCOCAL_STORED_MEAS_0(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_0_RB_LPDCOCAL_STORED_MEAS_0_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_0_RB_LPDCOCAL_STORED_MEAS_0_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_1_RB -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_1_RB_LPDCOCAL_STORED_MEAS_1_MASK (0x7FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_1_RB_LPDCOCAL_STORED_MEAS_1_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_1_RB_LPDCOCAL_STORED_MEAS_1(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_1_RB_LPDCOCAL_STORED_MEAS_1_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_MEAS_1_RB_LPDCOCAL_STORED_MEAS_1_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_0_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_0_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_0(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_0_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_0_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_1_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_1_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_1(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_1_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_COARSE_FWORD_RB_LPDCOCAL_STORED_FWORD_1_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_MEASURE_CURR_ERROR -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_CURR_ERROR_LPDCOCAL_MEAS_CURR_ERROR_MASK (0xFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_CURR_ERROR_LPDCOCAL_MEAS_CURR_ERROR_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_CURR_ERROR_LPDCOCAL_MEAS_CURR_ERROR(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_CURR_ERROR_LPDCOCAL_MEAS_CURR_ERROR_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_CURR_ERROR_LPDCOCAL_MEAS_CURR_ERROR_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_LAST_MEAS_ERROR_MASK (0xFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_LAST_MEAS_ERROR_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_LAST_MEAS_ERROR(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_LAST_MEAS_ERROR_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_LAST_MEAS_ERROR_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_VT_STATE_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_VT_STATE_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_VT_STATE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_VT_STATE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_MEASURE_LAST_ERROR_LPDCOCAL_VT_STATE_MASK)
/*! @} */

/*! @name PPI_R_LPDCOCAL_DEBUG_VT -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_WITHIN_RANGE_VT_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_WITHIN_RANGE_VT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_WITHIN_RANGE_VT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_WITHIN_RANGE_VT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_WITHIN_RANGE_VT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_BELOW_RANGE_VT_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_BELOW_RANGE_VT_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_BELOW_RANGE_VT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_BELOW_RANGE_VT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_BELOW_RANGE_VT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_ABOVE_RANGE_VT_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_ABOVE_RANGE_VT_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_ABOVE_RANGE_VT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_ABOVE_RANGE_VT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_N_ABOVE_RANGE_VT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_MEAS_ADJ_P0_VT_MASK (0x3FF8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_MEAS_ADJ_P0_VT_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_MEAS_ADJ_P0_VT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_MEAS_ADJ_P0_VT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LPDCOCAL_DEBUG_VT_LPDCOCAL_MEAS_ADJ_P0_VT_MASK)
/*! @} */

/*! @name PPI_RW_LB_TIMEBASE_CONFIG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_TIMEBASE_CONFIG_LOOPBACK_TIMEBASE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_TIMEBASE_CONFIG_LOOPBACK_TIMEBASE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_TIMEBASE_CONFIG_LOOPBACK_TIMEBASE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_TIMEBASE_CONFIG_LOOPBACK_TIMEBASE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_TIMEBASE_CONFIG_LOOPBACK_TIMEBASE_MASK)
/*! @} */

/*! @name PPI_RW_LB_STARTCMU_CONFIG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_STARTCMU_CONFIG_LB_START_CMU_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_STARTCMU_CONFIG_LB_START_CMU_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_STARTCMU_CONFIG_LB_START_CMU(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_STARTCMU_CONFIG_LB_START_CMU_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_STARTCMU_CONFIG_LB_START_CMU_MASK)
/*! @} */

/*! @name PPI_R_LBPULSE_COUNTER_RB -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LBPULSE_COUNTER_RB_LB_PULSE_COUNTER_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LBPULSE_COUNTER_RB_LB_PULSE_COUNTER_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LBPULSE_COUNTER_RB_LB_PULSE_COUNTER(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LBPULSE_COUNTER_RB_LB_PULSE_COUNTER_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LBPULSE_COUNTER_RB_LB_PULSE_COUNTER_MASK)
/*! @} */

/*! @name PPI_R_LB_START_CMU_RB -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_LB_START_CMU_RB_LB_STOP_CMU_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LB_START_CMU_RB_LB_STOP_CMU_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_LB_START_CMU_RB_LB_STOP_CMU(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_LB_START_CMU_RB_LB_STOP_CMU_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_LB_START_CMU_RB_LB_STOP_CMU_MASK)
/*! @} */

/*! @name PPI_RW_LB_DPHY_BURST_START -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_CLK_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_CLK_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_CLK(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_CLK_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_CLK_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_DATA_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_DATA_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_DATA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_DATA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXREQUESTHS_DATA_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXDATATRANSFERENHS_DATA_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXDATATRANSFERENHS_DATA_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXDATATRANSFERENHS_DATA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXDATATRANSFERENHS_DATA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXDATATRANSFERENHS_DATA_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXSKEWCALHS_DATA_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXSKEWCALHS_DATA_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXSKEWCALHS_DATA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXSKEWCALHS_DATA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXSKEWCALHS_DATA_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXALTERNATECALHS_DATA_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXALTERNATECALHS_DATA_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXALTERNATECALHS_DATA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXALTERNATECALHS_DATA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_DPHY_BURST_START_LBERT_DPHY_TXALTERNATECALHS_DATA_MASK)
/*! @} */

/*! @name PPI_RW_LB_CPHY_BURST_START -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXREQUESTHS_DATA_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXREQUESTHS_DATA_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXREQUESTHS_DATA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXREQUESTHS_DATA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXREQUESTHS_DATA_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXDATATRANSFERENHS_DATA_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXDATATRANSFERENHS_DATA_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXDATATRANSFERENHS_DATA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXDATATRANSFERENHS_DATA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_LB_CPHY_BURST_START_LBERT_CPHY_TXDATATRANSFERENHS_DATA_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_0_DDLCAL_TIMEBASE_TARGET_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_0_DDLCAL_TIMEBASE_TARGET_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_0_DDLCAL_TIMEBASE_TARGET(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_0_DDLCAL_TIMEBASE_TARGET_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_0_DDLCAL_TIMEBASE_TARGET_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_MAX_PHASE_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_MAX_PHASE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_MAX_PHASE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_MAX_PHASE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_MAX_PHASE_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_DISABLE_TIME_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_DISABLE_TIME_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_DISABLE_TIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_DISABLE_TIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_1_DDLCAL_DISABLE_TIME_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_ENABLE_WAIT_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_ENABLE_WAIT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_ENABLE_WAIT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_ENABLE_WAIT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_ENABLE_WAIT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_DDL_DLL_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_DDL_DLL_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_DDL_DLL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_DDL_DLL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_DDL_DLL_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_UPDATE_SETTINGS_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_UPDATE_SETTINGS_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_UPDATE_SETTINGS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_UPDATE_SETTINGS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_UPDATE_SETTINGS_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_TUNE_MODE_MASK (0xC00U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_TUNE_MODE_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_TUNE_MODE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_TUNE_MODE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_TUNE_MODE_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_WAIT_MASK (0xF000U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_WAIT_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_WAIT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_WAIT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_2_DDLCAL_WAIT_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_3_DDLCAL_COUNTER_REF_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_3_DDLCAL_COUNTER_REF_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_3_DDLCAL_COUNTER_REF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_3_DDLCAL_COUNTER_REF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_3_DDLCAL_COUNTER_REF_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_4_DDLCAL_STUCK_THRESH_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_4_DDLCAL_STUCK_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_4_DDLCAL_STUCK_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_4_DDLCAL_STUCK_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_4_DDLCAL_STUCK_THRESH_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DDL_COARSE_BANK_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DDL_COARSE_BANK_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DDL_COARSE_BANK(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DDL_COARSE_BANK_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DDL_COARSE_BANK_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DLL_FBK_MASK (0x3F0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DLL_FBK_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DLL_FBK(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DLL_FBK_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_5_DDLCAL_DLL_FBK_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_MAX_DIFF_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_MAX_DIFF_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_MAX_DIFF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_MAX_DIFF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_MAX_DIFF_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_CLEAR_COUNT_THRESH_MASK (0xFC00U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_CLEAR_COUNT_THRESH_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_CLEAR_COUNT_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_CLEAR_COUNT_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_6_DDLCAL_CLEAR_COUNT_THRESH_MASK)
/*! @} */

/*! @name PPI_RW_DDLCAL_CFG_7 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_START_DELAY_MASK (0x7FU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_START_DELAY_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_START_DELAY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_START_DELAY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_START_DELAY_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_DECR_WAIT_MASK (0x1F80U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_DECR_WAIT_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_DECR_WAIT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_DECR_WAIT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DDLCAL_CFG_7_DDLCAL_DECR_WAIT_MASK)
/*! @} */

/*! @name PPI_R_DDLCAL_DEBUG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_0_DDLCAL_COUNTER0_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_0_DDLCAL_COUNTER0_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_0_DDLCAL_COUNTER0(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_0_DDLCAL_COUNTER0_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_0_DDLCAL_COUNTER0_MASK)
/*! @} */

/*! @name PPI_R_DDLCAL_DEBUG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_1_DDLCAL_COUNTERX_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_1_DDLCAL_COUNTERX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_1_DDLCAL_COUNTERX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_1_DDLCAL_COUNTERX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DDLCAL_DEBUG_1_DDLCAL_COUNTERX_MASK)
/*! @} */

/*! @name PPI_RW_PARITY_TEST -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTCLEAR_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTCLEAR_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTCLEAR(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTCLEAR_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTCLEAR_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTSET_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTSET_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTSET(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTSET_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_PARITY_TEST_CR_PARITY_TESTSET_MASK)
/*! @} */

/*! @name PPI_RW_STARTUP_OVR_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_OVR_0_STARTUP_STATE_OVR_VAL_MASK (0x1FU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_OVR_0_STARTUP_STATE_OVR_VAL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_OVR_0_STARTUP_STATE_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_OVR_0_STARTUP_STATE_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_OVR_0_STARTUP_STATE_OVR_VAL_MASK)
/*! @} */

/*! @name PPI_RW_STARTUP_STATE_OVR_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_STARTUP_STATE_OVR_EN_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_STARTUP_STATE_OVR_EN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_STARTUP_STATE_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_STARTUP_STATE_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_STARTUP_STATE_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_TXCLKESC_BYPASS_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_TXCLKESC_BYPASS_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_TXCLKESC_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_TXCLKESC_BYPASS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_STARTUP_STATE_OVR_1_TXCLKESC_BYPASS_MASK)
/*! @} */

/*! @name PPI_RW_DTB_SELECTOR -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SELECT_ADDR_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SELECT_ADDR_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SELECT_ADDR(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SELECT_ADDR_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SELECT_ADDR_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SOURCE_SELECT_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SOURCE_SELECT_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SOURCE_SELECT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SOURCE_SELECT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DTB_SELECTOR_DTB_SOURCE_SELECT_MASK)
/*! @} */

/*! @name PPI_RW_HSTX_FIFO_CFG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXDATATRANSFERENHS_SEL_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXDATATRANSFERENHS_SEL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXDATATRANSFERENHS_SEL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXDATATRANSFERENHS_SEL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXDATATRANSFERENHS_SEL_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_WADDR_INIT_MASK (0xEU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_WADDR_INIT_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_WADDR_INIT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_WADDR_INIT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_WADDR_INIT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXSYMBOLCLKHS_SEL_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXSYMBOLCLKHS_SEL_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXSYMBOLCLKHS_SEL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXSYMBOLCLKHS_SEL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_HSTX_FIFO_CFG_TXSYMBOLCLKHS_SEL_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_CLK_SPARE -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_CLK_SPARE_DPHY_CLK_LANE_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_CLK_SPARE_DPHY_CLK_LANE_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_CLK_SPARE_DPHY_CLK_LANE_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_CLK_SPARE_DPHY_CLK_LANE_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_CLK_SPARE_DPHY_CLK_LANE_SPARE_MASK)
/*! @} */

/*! @name PPI_RW_COMMON_CFG -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_COMMON_CFG_CFG_CLK_DIV_FACTOR_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_COMMON_CFG_CFG_CLK_DIV_FACTOR_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_COMMON_CFG_CFG_CLK_DIV_FACTOR(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_COMMON_CFG_CFG_CLK_DIV_FACTOR_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_COMMON_CFG_CFG_CLK_DIV_FACTOR_MASK)
/*! @} */

/*! @name PPI_RW_TERMCAL_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_TERMCAL_CFG_0_TERMCAL_TIMER_MASK (0x7FU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_TERMCAL_CFG_0_TERMCAL_TIMER_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_TERMCAL_CFG_0_TERMCAL_TIMER(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_TERMCAL_CFG_0_TERMCAL_TIMER_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_TERMCAL_CFG_0_TERMCAL_TIMER_MASK)
/*! @} */

/*! @name PPI_R_TERMCAL_DEBUG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_COMP_UNCHANGED_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_COMP_UNCHANGED_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_COMP_UNCHANGED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_COMP_UNCHANGED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_COMP_UNCHANGED_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_CAL_ERROR_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_CAL_ERROR_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_CAL_ERROR(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_CAL_ERROR_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_TERMCAL_DEBUG_0_TERMCAL_CAL_ERROR_MASK)
/*! @} */

/*! @name PPI_RW_OFFSETCAL_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_WAIT_THRESH_MASK (0x1FU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_WAIT_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_WAIT_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_WAIT_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_WAIT_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_CALIB_MODE_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_CALIB_MODE_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_CALIB_MODE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_CALIB_MODE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_OFFSETCAL_CFG_0_OFFSETCAL_CALIB_MODE_MASK)
/*! @} */

/*! @name PPI_R_OFFSETCAL_DEBUG_LANE0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_RIGHT_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_RIGHT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_LEFT_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_LEFT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE0_OFFSETCAL_ERRCAL_LEFT_MASK)
/*! @} */

/*! @name PPI_R_OFFSETCAL_DEBUG_LANE1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_RIGHT_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_RIGHT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_LEFT_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_LEFT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE1_OFFSETCAL_ERRCAL_LEFT_MASK)
/*! @} */

/*! @name PPI_R_OFFSETCAL_DEBUG_LANE2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_RIGHT_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_RIGHT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_LEFT_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_LEFT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE2_OFFSETCAL_ERRCAL_LEFT_MASK)
/*! @} */

/*! @name PPI_R_OFFSETCAL_DEBUG_LANE3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_RIGHT_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_RIGHT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_LEFT_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_LEFT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE3_OFFSETCAL_ERRCAL_LEFT_MASK)
/*! @} */

/*! @name PPI_R_OFFSETCAL_DEBUG_LANE4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_RIGHT_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_RIGHT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_LEFT_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_LEFT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_OFFSETCAL_DEBUG_LANE4_OFFSETCAL_ERRCAL_LEFT_MASK)
/*! @} */

/*! @name PPI_RW_PLL_STARTUP_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_0_PLL_RST_TIME_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_0_PLL_RST_TIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_0_PLL_RST_TIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_0_PLL_RST_TIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_0_PLL_RST_TIME_MASK)
/*! @} */

/*! @name PPI_RW_PLL_STARTUP_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_1_PLL_GEAR_SHIFT_TIME_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_1_PLL_GEAR_SHIFT_TIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_1_PLL_GEAR_SHIFT_TIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_1_PLL_GEAR_SHIFT_TIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_1_PLL_GEAR_SHIFT_TIME_MASK)
/*! @} */

/*! @name PPI_RW_PLL_STARTUP_CFG_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_2_PLL_LOCK_DET_TIME_MASK (0x3FFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_2_PLL_LOCK_DET_TIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_2_PLL_LOCK_DET_TIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_2_PLL_LOCK_DET_TIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_PLL_STARTUP_CFG_2_PLL_LOCK_DET_TIME_MASK)
/*! @} */

/*! @name PPI_RW_TX_HIBERNATE_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_TX_HIBERNATE_CFG_0_HIBERNATE_EXIT_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_TX_HIBERNATE_CFG_0_HIBERNATE_EXIT_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_TX_HIBERNATE_CFG_0_HIBERNATE_EXIT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_TX_HIBERNATE_CFG_0_HIBERNATE_EXIT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_TX_HIBERNATE_CFG_0_HIBERNATE_EXIT_MASK)
/*! @} */

/*! @name CORE_DIG_IOCTRL_RW_AFE_LANE0_CTRL_2_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE0_CTRL_2_0_OA_LANE0_SPARE_IN_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE0_CTRL_2_0_OA_LANE0_SPARE_IN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE0_CTRL_2_0_OA_LANE0_SPARE_IN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE0_CTRL_2_0_OA_LANE0_SPARE_IN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE0_CTRL_2_0_OA_LANE0_SPARE_IN_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO0_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DATA_EN_DELAY_THRESH_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DATA_EN_DELAY_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DATA_EN_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DATA_EN_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DATA_EN_DELAY_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_THRESH_MASK (0x38U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_THRESH_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_MASK (0x1C0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_POST_RECEIVED_RESET_THRESH_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_POST_RECEIVED_RESET_THRESH_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_POST_RECEIVED_RESET_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_POST_RECEIVED_RESET_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_0_POST_RECEIVED_RESET_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO0_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_1_POST_DET_DELAY_THRESH_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_1_POST_DET_DELAY_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_1_POST_DET_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_1_POST_DET_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_1_POST_DET_DELAY_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO0_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_2_DESERIALIZER_EN_DELAY_DEASS_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO0_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_IOCTRL_RW_AFE_LANE1_CTRL_2_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE1_CTRL_2_0_OA_LANE1_SPARE_IN_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE1_CTRL_2_0_OA_LANE1_SPARE_IN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE1_CTRL_2_0_OA_LANE1_SPARE_IN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE1_CTRL_2_0_OA_LANE1_SPARE_IN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE1_CTRL_2_0_OA_LANE1_SPARE_IN_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO1_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DATA_EN_DELAY_THRESH_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DATA_EN_DELAY_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DATA_EN_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DATA_EN_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DATA_EN_DELAY_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_THRESH_MASK (0x38U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_THRESH_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_MASK (0x1C0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_POST_RECEIVED_RESET_THRESH_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_POST_RECEIVED_RESET_THRESH_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_POST_RECEIVED_RESET_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_POST_RECEIVED_RESET_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_0_POST_RECEIVED_RESET_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO1_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_1_POST_DET_DELAY_THRESH_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_1_POST_DET_DELAY_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_1_POST_DET_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_1_POST_DET_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_1_POST_DET_DELAY_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO1_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_2_DESERIALIZER_EN_DELAY_DEASS_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO1_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_IOCTRL_RW_AFE_LANE2_CTRL_2_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE2_CTRL_2_0_OA_LANE2_SPARE_IN_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE2_CTRL_2_0_OA_LANE2_SPARE_IN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE2_CTRL_2_0_OA_LANE2_SPARE_IN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE2_CTRL_2_0_OA_LANE2_SPARE_IN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE2_CTRL_2_0_OA_LANE2_SPARE_IN_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO2_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DATA_EN_DELAY_THRESH_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DATA_EN_DELAY_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DATA_EN_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DATA_EN_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DATA_EN_DELAY_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_THRESH_MASK (0x38U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_THRESH_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_MASK (0x1C0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_DESERIALIZER_DIV_EN_DELAY_DEASS_THRESH_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_POST_RECEIVED_RESET_THRESH_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_POST_RECEIVED_RESET_THRESH_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_POST_RECEIVED_RESET_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_POST_RECEIVED_RESET_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_0_POST_RECEIVED_RESET_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO2_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_1_POST_DET_DELAY_THRESH_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_1_POST_DET_DELAY_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_1_POST_DET_DELAY_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_1_POST_DET_DELAY_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_1_POST_DET_DELAY_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_RW_TRIO2_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_2_DESERIALIZER_EN_DELAY_DEASS_THRESH(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_TRIO2_2_DESERIALIZER_EN_DELAY_DEASS_THRESH_MASK)
/*! @} */

/*! @name CORE_DIG_IOCTRL_RW_AFE_LANE3_CTRL_2_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE3_CTRL_2_0_OA_LANE3_SPARE_IN_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE3_CTRL_2_0_OA_LANE3_SPARE_IN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE3_CTRL_2_0_OA_LANE3_SPARE_IN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE3_CTRL_2_0_OA_LANE3_SPARE_IN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE3_CTRL_2_0_OA_LANE3_SPARE_IN_MASK)
/*! @} */

/*! @name CORE_DIG_IOCTRL_RW_AFE_LANE4_CTRL_2_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE4_CTRL_2_0_OA_LANE4_SPARE_IN_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE4_CTRL_2_0_OA_LANE4_SPARE_IN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE4_CTRL_2_0_OA_LANE4_SPARE_IN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE4_CTRL_2_0_OA_LANE4_SPARE_IN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_IOCTRL_RW_AFE_LANE4_CTRL_2_0_OA_LANE4_SPARE_IN_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_0_DPHY_PREAMBLE_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_0_DPHY_PREAMBLE_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_0_DPHY_PREAMBLE_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_0_DPHY_PREAMBLE_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_0_DPHY_PREAMBLE_EN_REG_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_1_OCLA_DATA_SEL_MASK (0x1FFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_1_OCLA_DATA_SEL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_1_OCLA_DATA_SEL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_1_OCLA_DATA_SEL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_1_OCLA_DATA_SEL_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_2_OCLA_DATA_SEL_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_2_OCLA_DATA_SEL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_2_OCLA_DATA_SEL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_2_OCLA_DATA_SEL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_2_OCLA_DATA_SEL_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_3_OCLA_CLK_SEL_MASK (0x1FFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_3_OCLA_CLK_SEL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_3_OCLA_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_3_OCLA_CLK_SEL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_3_OCLA_CLK_SEL_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_4_OCLA_CLK_SEL_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_4_OCLA_CLK_SEL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_4_OCLA_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_4_OCLA_CLK_SEL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_4_OCLA_CLK_SEL_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_INPUT_SAMPLING_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_INPUT_SAMPLING_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_INPUT_SAMPLING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_INPUT_SAMPLING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_INPUT_SAMPLING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_DTB_SELECT_MASK (0x1FEU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_DTB_SELECT_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_DTB_SELECT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_DTB_SELECT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_DTB_SELECT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_HSRX_DPHY_DLL_EN_DRV_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_HSRX_DPHY_DLL_EN_DRV_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_HSRX_DPHY_DLL_EN_DRV(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_HSRX_DPHY_DLL_EN_DRV_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_HSRX_DPHY_DLL_EN_DRV_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_DLANE_MASK (0xC00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_DLANE_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_DLANE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_DLANE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_DLANE_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_CLANE_MASK (0x3000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_CLANE_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_CLANE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_CLANE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_5_WORD_CLK_SEL_CLANE_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_DIV_EN_DELAY_THRESH_D_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_DIV_EN_DELAY_THRESH_D_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_DIV_EN_DELAY_THRESH_D(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_DIV_EN_DELAY_THRESH_D_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_DIV_EN_DELAY_THRESH_D_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_EN_DEASS_COUNT_THRESH_D_MASK (0x38U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_EN_DEASS_COUNT_THRESH_D_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_EN_DEASS_COUNT_THRESH_D(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_EN_DEASS_COUNT_THRESH_D_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_6_DESERIALIZER_EN_DEASS_COUNT_THRESH_D_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_7 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE0_HSRX_WORD_CLK_SEL_GATING_REG_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE0_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE0_HSRX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE0_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE0_HSRX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE1_HSRX_WORD_CLK_SEL_GATING_REG_MASK (0xCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE1_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE1_HSRX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE1_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE1_HSRX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE2_HSRX_WORD_CLK_SEL_GATING_REG_MASK (0x30U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE2_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE2_HSRX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE2_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE2_HSRX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE3_HSRX_WORD_CLK_SEL_GATING_REG_MASK (0xC0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE3_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE3_HSRX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE3_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE3_HSRX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE4_HSRX_WORD_CLK_SEL_GATING_REG_MASK (0x300U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE4_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE4_HSRX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE4_HSRX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_7_LANE4_HSRX_WORD_CLK_SEL_GATING_REG_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_EN_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_VAL_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE0_HSRX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_VAL_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE1_HSRX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_EN_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_VAL_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE2_HSRX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_EN_MASK (0x40U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_VAL_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE3_HSRX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_EN_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_VAL_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_8_LANE4_HSRX_WORD_CLK_GATING_OVR_VAL_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_9 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_EN_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_EN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_VAL_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_VAL_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_SEL_GATING_REG_MASK (0xCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_SEL_GATING_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_LP_DCO_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_EN_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_EN_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_VAL_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_VAL_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_SEL_GATING_REG_MASK (0xC0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_SEL_GATING_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_9_HSTXLB_DCO_CLK_SEL_GATING_REG_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_10 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE0_CDROSC_CLK_SEL_GATING_REG_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE0_CDROSC_CLK_SEL_GATING_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE0_CDROSC_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE0_CDROSC_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE0_CDROSC_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE2_CDROSC_CLK_SEL_GATING_REG_MASK (0xCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE2_CDROSC_CLK_SEL_GATING_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE2_CDROSC_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE2_CDROSC_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE2_CDROSC_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE3_CDROSC_CLK_SEL_GATING_REG_MASK (0x30U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE3_CDROSC_CLK_SEL_GATING_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE3_CDROSC_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE3_CDROSC_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_10_LANE3_CDROSC_CLK_SEL_GATING_REG_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_11 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_EN_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_EN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_VAL_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_VAL_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE0_CDROSC_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_VAL_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_VAL_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE2_CDROSC_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_EN_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_EN_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_VAL_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_VAL_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_11_LANE3_CDROSC_CLK_GATING_OVR_VAL_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_12 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE0_DDL_OSC_SEL_GATING_REG_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE0_DDL_OSC_SEL_GATING_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE0_DDL_OSC_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE0_DDL_OSC_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE0_DDL_OSC_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE1_DDL_OSC_SEL_GATING_REG_MASK (0xCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE1_DDL_OSC_SEL_GATING_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE1_DDL_OSC_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE1_DDL_OSC_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE1_DDL_OSC_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE2_DDL_OSC_SEL_GATING_REG_MASK (0x30U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE2_DDL_OSC_SEL_GATING_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE2_DDL_OSC_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE2_DDL_OSC_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE2_DDL_OSC_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE3_DDL_OSC_SEL_GATING_REG_MASK (0xC0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE3_DDL_OSC_SEL_GATING_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE3_DDL_OSC_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE3_DDL_OSC_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE3_DDL_OSC_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE4_DDL_OSC_SEL_GATING_REG_MASK (0x300U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE4_DDL_OSC_SEL_GATING_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE4_DDL_OSC_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE4_DDL_OSC_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_12_LANE4_DDL_OSC_SEL_GATING_REG_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_13 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_EN_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_EN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_VAL_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_VAL_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE0_DDL_OSC_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_VAL_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_VAL_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE1_DDL_OSC_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_EN_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_EN_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_VAL_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_VAL_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE2_DDL_OSC_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_EN_MASK (0x40U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_EN_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_VAL_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_VAL_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE3_DDL_OSC_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_EN_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_EN_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_VAL_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_VAL_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_13_LANE4_DDL_OSC_GATING_OVR_VAL_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_14 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE0_HSTX_WORD_CLK_SEL_GATING_REG_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE0_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE0_HSTX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE0_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE0_HSTX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE1_HSTX_WORD_CLK_SEL_GATING_REG_MASK (0xCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE1_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE1_HSTX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE1_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE1_HSTX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE2_HSTX_WORD_CLK_SEL_GATING_REG_MASK (0x30U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE2_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE2_HSTX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE2_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE2_HSTX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE3_HSTX_WORD_CLK_SEL_GATING_REG_MASK (0xC0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE3_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE3_HSTX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE3_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE3_HSTX_WORD_CLK_SEL_GATING_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE4_HSTX_WORD_CLK_SEL_GATING_REG_MASK (0x300U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE4_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE4_HSTX_WORD_CLK_SEL_GATING_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE4_HSTX_WORD_CLK_SEL_GATING_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_14_LANE4_HSTX_WORD_CLK_SEL_GATING_REG_MASK)
/*! @} */

/*! @name CORE_DIG_RW_COMMON_15 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_EN_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_VAL_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE0_HSTX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_VAL_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE1_HSTX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_EN_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_VAL_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE2_HSTX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_EN_MASK (0x40U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_VAL_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE3_HSTX_WORD_CLK_GATING_OVR_VAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_EN_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_EN_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_VAL_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_VAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_VAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_RW_COMMON_15_LANE4_HSTX_WORD_CLK_GATING_OVR_VAL_MASK)
/*! @} */

/*! @name CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_DSK_CLK_MODE_CFG_MASK (0x3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_DSK_CLK_MODE_CFG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_DSK_CLK_MODE_CFG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_DSK_CLK_MODE_CFG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_DSK_CLK_MODE_CFG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_EN_DLY_MASK (0xFCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_EN_DLY_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_EN_DLY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_EN_DLY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_EN_DLY_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_CLK_EN_DLY_MASK (0x3F00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_CLK_EN_DLY_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_CLK_EN_DLY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_CLK_EN_DLY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_LP_DCO_CLK_EN_DLY_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_CHOP_CLK_DIV_SEL_MASK (0xC000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_CHOP_CLK_DIV_SEL_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_CHOP_CLK_DIV_SEL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_CHOP_CLK_DIV_SEL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_0_CB_CHOP_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_CB_LP_DCO_CLK_EN_DLY_MASK (0x3FU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_CB_LP_DCO_CLK_EN_DLY_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_CB_LP_DCO_CLK_EN_DLY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_CB_LP_DCO_CLK_EN_DLY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_CB_LP_DCO_CLK_EN_DLY_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_HSRX_DLY_MASK (0x1C0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_HSRX_DLY_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_HSRX_DLY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_HSRX_DLY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_1_HSRX_DLY_MASK)
/*! @} */

/*! @name CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HSTX_DIV_EN_CNTR_DLY_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HSTX_DIV_EN_CNTR_DLY_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HSTX_DIV_EN_CNTR_DLY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HSTX_DIV_EN_CNTR_DLY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HSTX_DIV_EN_CNTR_DLY_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HIBERNATE_DLY_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HIBERNATE_DLY_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HIBERNATE_DLY(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HIBERNATE_DLY_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_ANACTRL_RW_COMMON_ANACTRL_3_HIBERNATE_DLY_MASK)
/*! @} */

/*! @name CORE_DIG_COMMON_RW_DESKEW_FINE_MEM -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_ADDR_MASK (0x3F8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_ADDR_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_ADDR(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_ADDR_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_ADDR_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_WR_EN_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_WR_EN_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_WR_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_WR_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_RW_DESKEW_FINE_MEM_DESKEW_FINE_MEM_WR_EN_MASK)
/*! @} */

/*! @name CORE_DIG_COMMON_R_DESKEW_FINE_MEM -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_R_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_R_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_R_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_R_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_COMMON_R_DESKEW_FINE_MEM_DESKEW_FINE_MEM_VALUE_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE0_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_LBERT_1_LBERT_PG_USER_PATTERN_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_LBERT_1_LBERT_PG_USER_PATTERN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_LBERT_1_LBERT_PG_USER_PATTERN_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE0_LBERT_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_0_LBERT_PM_ERROR_COUNTER(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE0_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_1_LBERT_PG_ENABLED_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_1_LBERT_PG_ENABLED_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_1_LBERT_PG_ENABLED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_1_LBERT_PG_ENABLED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE0_LBERT_1_LBERT_PG_ENABLED_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE0_SPARE -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_SPARE_DPHY_LANE_0_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_SPARE_DPHY_LANE_0_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_SPARE_DPHY_LANE_0_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_SPARE_DPHY_LANE_0_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE0_SPARE_DPHY_LANE_0_SPARE_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE1_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_LBERT_1_LBERT_PG_USER_PATTERN_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_LBERT_1_LBERT_PG_USER_PATTERN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_LBERT_1_LBERT_PG_USER_PATTERN_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE1_LBERT_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_0_LBERT_PM_ERROR_COUNTER(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE1_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_1_LBERT_PG_ENABLED_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_1_LBERT_PG_ENABLED_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_1_LBERT_PG_ENABLED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_1_LBERT_PG_ENABLED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE1_LBERT_1_LBERT_PG_ENABLED_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE1_SPARE -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_SPARE_DPHY_LANE_1_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_SPARE_DPHY_LANE_1_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_SPARE_DPHY_LANE_1_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_SPARE_DPHY_LANE_1_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE1_SPARE_DPHY_LANE_1_SPARE_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE2_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_LBERT_1_LBERT_PG_USER_PATTERN_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_LBERT_1_LBERT_PG_USER_PATTERN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_LBERT_1_LBERT_PG_USER_PATTERN_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE2_LBERT_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_0_LBERT_PM_ERROR_COUNTER(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE2_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_1_LBERT_PG_ENABLED_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_1_LBERT_PG_ENABLED_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_1_LBERT_PG_ENABLED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_1_LBERT_PG_ENABLED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE2_LBERT_1_LBERT_PG_ENABLED_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE2_SPARE -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_SPARE_DPHY_LANE_2_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_SPARE_DPHY_LANE_2_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_SPARE_DPHY_LANE_2_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_SPARE_DPHY_LANE_2_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE2_SPARE_DPHY_LANE_2_SPARE_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE3_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_LBERT_1_LBERT_PG_USER_PATTERN_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_LBERT_1_LBERT_PG_USER_PATTERN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_LBERT_1_LBERT_PG_USER_PATTERN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_LBERT_1_LBERT_PG_USER_PATTERN_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE3_LBERT_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_0_LBERT_PM_ERROR_COUNTER(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_0_LBERT_PM_ERROR_COUNTER_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_0_LBERT_PM_ERROR_COUNTER_MASK)
/*! @} */

/*! @name PPI_R_DPHY_LANE3_LBERT_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_1_LBERT_PG_ENABLED_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_1_LBERT_PG_ENABLED_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_1_LBERT_PG_ENABLED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_1_LBERT_PG_ENABLED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_R_DPHY_LANE3_LBERT_1_LBERT_PG_ENABLED_MASK)
/*! @} */

/*! @name PPI_RW_DPHY_LANE3_SPARE -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_SPARE_DPHY_LANE_3_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_SPARE_DPHY_LANE_3_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_SPARE_DPHY_LANE_3_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_SPARE_DPHY_LANE_3_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_PPI_RW_DPHY_LANE3_SPARE_DPHY_LANE_3_SPARE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_PREAMBLE_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_SOT_DETECTION_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_CFG_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_2_CFG_2_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_2_CFG_2_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_2_CFG_2_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_2_CFG_2_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_CFG_2_CFG_2_SPARE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGET_REG_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGET_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGET_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGET_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGET_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTASURE_REG_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTASURE_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTASURE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTASURE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTASURE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGO_REG_MASK (0xF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGO_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_TTAGO_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_ITMINRX_REG_MASK (0xF000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_ITMINRX_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_ITMINRX_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_ITMINRX_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_0_LP_0_ITMINRX_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_LPTX_PON_TIMER_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_HSACTIVERX_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_HSACTIVERX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_HSACTIVERX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_HSACTIVERX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_HSACTIVERX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_RXHSRQST_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_RXHSRQST_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_RXHSRQST(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_RXHSRQST_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_0_LP_0_RXHSRQST_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_BTA_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_BTA_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_BTA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_BTA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_BTA_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPRX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPRX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPRX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPRX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPRX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPTX_MASK (0x1F00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPTX_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_LP_1_LP_1_STATE_LPTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DHSTX_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DHSTX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DHSTX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DCO_DHSTX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DCO_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_TX_0_STATE_DCO_DHSTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK (0x18U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK (0x60U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK (0x1E00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK (0x2000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT (13U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK (0x4000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK (0x1F8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_RX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK (0x1FEU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_START_DELAY_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALDONE_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALDONE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALDONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALDONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALDONE_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALFAILED_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALFAILED_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALFAILED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALFAILED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEWCALFAILED_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEW_CAL_STATUS_MASK (0x3FCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEW_CAL_STATUS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_0_DESKEW_CAL_STATUS_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_1_DESKEWCALTIME_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_1_DESKEWCALTIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_1_DESKEWCALTIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_1_DESKEWCALTIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_1_DESKEWCALTIME_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_2_DESKEW_STATE_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_2_DESKEW_STATE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_2_DESKEW_STATE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_2_DESKEW_STATE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_2_DESKEW_STATE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_ACTION_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_RESULT_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_RESULT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_PREV_RESULT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_CURR_ACTION_MASK (0x1E0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_CURR_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_CURR_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_ALL_DIFF_MASK (0x800U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_ALL_DIFF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_3_DESKEW_ALL_DIFF_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_R_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE1POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE2POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_1_HS_TX_1_THSZERO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_9 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_10 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_11 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_0_RW_HS_TX_12 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_0_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_PREAMBLE_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_SOT_DETECTION_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_CFG_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_2_CFG_2_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_2_CFG_2_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_2_CFG_2_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_2_CFG_2_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_CFG_2_CFG_2_SPARE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGET_REG_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGET_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGET_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGET_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGET_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTASURE_REG_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTASURE_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTASURE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTASURE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTASURE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGO_REG_MASK (0xF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGO_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_TTAGO_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_ITMINRX_REG_MASK (0xF000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_ITMINRX_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_ITMINRX_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_ITMINRX_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_0_LP_0_ITMINRX_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_LPTX_PON_TIMER_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_HSACTIVERX_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_HSACTIVERX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_HSACTIVERX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_HSACTIVERX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_HSACTIVERX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_RXHSRQST_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_RXHSRQST_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_RXHSRQST(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_RXHSRQST_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_0_LP_0_RXHSRQST_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_BTA_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_BTA_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_BTA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_BTA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_BTA_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPRX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPRX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPRX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPRX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPRX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPTX_MASK (0x1F00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPTX_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_LP_1_LP_1_STATE_LPTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DHSTX_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DHSTX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DHSTX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DCO_DHSTX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DCO_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_TX_0_STATE_DCO_DHSTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK (0x18U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK (0x60U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK (0x1E00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK (0x2000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT (13U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK (0x4000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK (0x1F8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_RX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK (0x1FEU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_START_DELAY_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALDONE_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALDONE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALDONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALDONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALDONE_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALFAILED_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALFAILED_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALFAILED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALFAILED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEWCALFAILED_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEW_CAL_STATUS_MASK (0x3FCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEW_CAL_STATUS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_0_DESKEW_CAL_STATUS_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_1_DESKEWCALTIME_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_1_DESKEWCALTIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_1_DESKEWCALTIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_1_DESKEWCALTIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_1_DESKEWCALTIME_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_2_DESKEW_STATE_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_2_DESKEW_STATE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_2_DESKEW_STATE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_2_DESKEW_STATE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_2_DESKEW_STATE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_ACTION_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_RESULT_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_RESULT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_PREV_RESULT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_CURR_ACTION_MASK (0x1E0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_CURR_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_CURR_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_ALL_DIFF_MASK (0x800U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_ALL_DIFF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_3_DESKEW_ALL_DIFF_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_R_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE1POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE2POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_1_HS_TX_1_THSZERO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_9 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_10 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_11 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_1_RW_HS_TX_12 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_1_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_PREAMBLE_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_SOT_DETECTION_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_CFG_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_2_CFG_2_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_2_CFG_2_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_2_CFG_2_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_2_CFG_2_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_CFG_2_CFG_2_SPARE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGET_REG_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGET_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGET_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGET_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGET_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTASURE_REG_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTASURE_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTASURE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTASURE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTASURE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGO_REG_MASK (0xF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGO_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_TTAGO_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_ITMINRX_REG_MASK (0xF000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_ITMINRX_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_ITMINRX_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_ITMINRX_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_0_LP_0_ITMINRX_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_LPTX_PON_TIMER_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_HSACTIVERX_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_HSACTIVERX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_HSACTIVERX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_HSACTIVERX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_HSACTIVERX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_RXHSRQST_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_RXHSRQST_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_RXHSRQST(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_RXHSRQST_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_0_LP_0_RXHSRQST_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_BTA_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_BTA_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_BTA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_BTA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_BTA_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPRX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPRX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPRX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPRX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPRX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPTX_MASK (0x1F00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPTX_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_LP_1_LP_1_STATE_LPTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DHSTX_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DHSTX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DHSTX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DCO_DHSTX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DCO_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_TX_0_STATE_DCO_DHSTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK (0x18U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK (0x60U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK (0x1E00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK (0x2000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT (13U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK (0x4000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK (0x1F8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_RX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK (0x1FEU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_START_DELAY_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALDONE_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALDONE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALDONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALDONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALDONE_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALFAILED_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALFAILED_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALFAILED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALFAILED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEWCALFAILED_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEW_CAL_STATUS_MASK (0x3FCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEW_CAL_STATUS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_0_DESKEW_CAL_STATUS_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_1_DESKEWCALTIME_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_1_DESKEWCALTIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_1_DESKEWCALTIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_1_DESKEWCALTIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_1_DESKEWCALTIME_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_2_DESKEW_STATE_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_2_DESKEW_STATE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_2_DESKEW_STATE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_2_DESKEW_STATE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_2_DESKEW_STATE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_ACTION_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_RESULT_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_RESULT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_PREV_RESULT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_CURR_ACTION_MASK (0x1E0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_CURR_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_CURR_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_ALL_DIFF_MASK (0x800U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_ALL_DIFF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_3_DESKEW_ALL_DIFF_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_R_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE1POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE2POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_1_HS_TX_1_THSZERO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_9 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_10 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_11 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_2_RW_HS_TX_12 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_2_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_PREAMBLE_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_SOT_DETECTION_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_CFG_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_2_CFG_2_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_2_CFG_2_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_2_CFG_2_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_2_CFG_2_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_CFG_2_CFG_2_SPARE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGET_REG_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGET_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGET_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGET_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGET_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTASURE_REG_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTASURE_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTASURE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTASURE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTASURE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGO_REG_MASK (0xF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGO_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_TTAGO_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_ITMINRX_REG_MASK (0xF000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_ITMINRX_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_ITMINRX_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_ITMINRX_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_0_LP_0_ITMINRX_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_LPTX_PON_TIMER_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_HSACTIVERX_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_HSACTIVERX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_HSACTIVERX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_HSACTIVERX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_HSACTIVERX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_RXHSRQST_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_RXHSRQST_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_RXHSRQST(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_RXHSRQST_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_0_LP_0_RXHSRQST_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_BTA_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_BTA_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_BTA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_BTA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_BTA_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPRX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPRX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPRX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPRX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPRX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPTX_MASK (0x1F00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPTX_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_LP_1_LP_1_STATE_LPTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DHSTX_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DHSTX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DHSTX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DCO_DHSTX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DCO_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_TX_0_STATE_DCO_DHSTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK (0x18U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK (0x60U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK (0x1E00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK (0x2000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT (13U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK (0x4000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK (0x1F8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_RX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK (0x1FEU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_START_DELAY_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALDONE_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALDONE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALDONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALDONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALDONE_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALFAILED_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALFAILED_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALFAILED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALFAILED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEWCALFAILED_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEW_CAL_STATUS_MASK (0x3FCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEW_CAL_STATUS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_0_DESKEW_CAL_STATUS_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_1_DESKEWCALTIME_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_1_DESKEWCALTIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_1_DESKEWCALTIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_1_DESKEWCALTIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_1_DESKEWCALTIME_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_2_DESKEW_STATE_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_2_DESKEW_STATE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_2_DESKEW_STATE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_2_DESKEW_STATE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_2_DESKEW_STATE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_ACTION_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_RESULT_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_RESULT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_PREV_RESULT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_CURR_ACTION_MASK (0x1E0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_CURR_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_CURR_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_ALL_DIFF_MASK (0x800U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_ALL_DIFF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_3_DESKEW_ALL_DIFF_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_R_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE1POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE2POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_1_HS_TX_1_THSZERO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_9 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_10 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_11 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_3_RW_HS_TX_12 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_3_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_CFG_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_PREAMBLE_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_PREAMBLE_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_BACKWARDS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK (0x4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_DESKEW_SUPPORTED_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_SOT_DETECTION_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_SOT_DETECTION_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_1_CFG_1_SOT_DETECTION_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_CFG_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_2_CFG_2_SPARE_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_2_CFG_2_SPARE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_2_CFG_2_SPARE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_2_CFG_2_SPARE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_CFG_2_CFG_2_SPARE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGET_REG_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGET_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGET_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGET_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGET_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTASURE_REG_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTASURE_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTASURE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTASURE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTASURE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGO_REG_MASK (0xF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGO_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_TTAGO_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_ITMINRX_REG_MASK (0xF000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_ITMINRX_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_ITMINRX_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_ITMINRX_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_0_LP_0_ITMINRX_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_ERRCONTENTION_THRES_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_LPTX_PON_TIMER_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_LP_1_LP_1_LPTX_PON_TIMER_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_LP_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_HSACTIVERX_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_HSACTIVERX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_HSACTIVERX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_HSACTIVERX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_HSACTIVERX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_RXHSRQST_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_RXHSRQST_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_RXHSRQST(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_RXHSRQST_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_0_LP_0_RXHSRQST_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_LP_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_BTA_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_BTA_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_BTA(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_BTA_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_BTA_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPRX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPRX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPRX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPRX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPRX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPTX_MASK (0x1F00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPTX_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_LP_1_LP_1_STATE_LPTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DHSTX_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DHSTX_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DHSTX_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DCO_DHSTX_MASK (0xF0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DCO_DHSTX(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DCO_DHSTX_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_TX_0_STATE_DCO_DHSTX_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_TCLKSETTLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_0_HS_RX_0_THSSETTLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_1_HS_RX_1_FILTER_SIZE_SKEWCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK (0x18U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_LATENCY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK (0x60U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_JUMP2STEPS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_POLARITY_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_RECAL_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK (0x1E00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_WINDOW_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK (0x2000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT (13U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK (0x4000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_UPDATE_SETTINGS_SKEWCAL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_2_HS_RX_2_IGNORE_ALTERNCAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_STEP_SIZE_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK (0x1F8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_FJUMP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHIFT_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_SHRINK_STEP_DESKEW_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK (0x8000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT (15U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_3_HS_RX_3_ROUNDUP_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_4_HS_RX_4_MAX_ITERATIONS_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_LEFT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_5_HS_RX_5_DDL_MID_INIT_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_DDL_RIGHT_INIT_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_6_HS_RX_6_MIN_EYE_OPENING_DESKEW_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_7 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_TCLKMISS_REG_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_TCLKMISS_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_TCLKMISS_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_TCLKMISS_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_TCLKMISS_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INVORDER_RX_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INVORDER_RX_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INVORDER_RX_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INVORDER_RX_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INVORDER_RX_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INITIAL_CALIBRATION_REG_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INITIAL_CALIBRATION_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INITIAL_CALIBRATION_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INITIAL_CALIBRATION_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_INITIAL_CALIBRATION_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_THSEXIT_MIN_REG_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_THSEXIT_MIN_REG_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_THSEXIT_MIN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_THSEXIT_MIN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_THSEXIT_MIN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_CNF_REG_MASK (0x1800U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_CNF_REG_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_CNF_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_CNF_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_CNF_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_AUTO_ALGO_SEL_REG_MASK (0x2000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_AUTO_ALGO_SEL_REG_SHIFT (13U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_AUTO_ALGO_SEL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_AUTO_ALGO_SEL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_AUTO_ALGO_SEL_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_REARM_INITIAL_REG_MASK (0x4000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_REARM_INITIAL_REG_SHIFT (14U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_REARM_INITIAL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_REARM_INITIAL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_7_HS_RX_7_DESKEW_REARM_INITIAL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_RX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_FILTER_DITHERING_EN_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK (0x1FEU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_START_DELAY_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_RX_8_HS_RX_8_START_DELAY_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_HS_RX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALDONE_MASK (0x1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALDONE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALDONE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALDONE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALDONE_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALFAILED_MASK (0x2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALFAILED_SHIFT (1U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALFAILED(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALFAILED_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEWCALFAILED_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEW_CAL_STATUS_MASK (0x3FCU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT (2U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEW_CAL_STATUS(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEW_CAL_STATUS_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_0_DESKEW_CAL_STATUS_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_HS_RX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_1_DESKEWCALTIME_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_1_DESKEWCALTIME_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_1_DESKEWCALTIME(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_1_DESKEWCALTIME_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_1_DESKEWCALTIME_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_HS_RX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_2_DESKEW_STATE_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_2_DESKEW_STATE_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_2_DESKEW_STATE(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_2_DESKEW_STATE_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_2_DESKEW_STATE_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_HS_RX_3 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_ACTION_MASK (0xFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_RESULT_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_RESULT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_RESULT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_PREV_RESULT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_CURR_ACTION_MASK (0x1E0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_CURR_ACTION(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_CURR_ACTION_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_CURR_ACTION_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_LEFT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_LEFT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_LEFT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_RIGHT_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_FAILED_RIGHT_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_ALL_DIFF_MASK (0x800U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT (11U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_ALL_DIFF(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_ALL_DIFF_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_3_DESKEW_ALL_DIFF_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_R_HS_RX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK (0xFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE1POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE1POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE1POINTER_SKEWCAL_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK (0xFF00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE2POINTER_SKEWCAL(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE2POINTER_SKEWCAL_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_R_HS_RX_4_EDGE2POINTER_SKEWCAL_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_0_HS_TX_0_THSTRAIL_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_1 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_1_HS_TX_1_THSZERO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_1_HS_TX_1_THSZERO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_1_HS_TX_1_THSZERO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_2 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_2_HS_TX_2_TCLKPRE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_4 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_4_HS_TX_4_TLPX_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_5 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_5_HS_TX_5_THSTRAIL_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_6_HS_TX_6_TLP11END_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_8 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_8_HS_TX_8_TCLKPOST_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_9 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_9_HS_TX_9_THSPRPR_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_10 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_10_HS_TX_10_TLP11INIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_11 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_11_HS_TX_11_TPREAMBLE_REG_MASK)
/*! @} */

/*! @name CORE_DIG_DLANE_CLK_RW_HS_TX_12 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK (0xFFFFU)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_DLANE_CLK_RW_HS_TX_12_HS_TX_12_THSEXIT_DCO_REG_MASK)
/*! @} */

/*! @name CORE_DIG_CLANE_0_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_MASK (0x40U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_ALP_ENABLE_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_ALP_ENABLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_ALP_ENABLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_ALP_ENABLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_ALP_ENABLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_SWAP_ENCODE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_CLANE_0_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_MASK (0x38U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_MASK (0x1C0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_0_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_MASK)
/*! @} */

/*! @name CORE_DIG_CLANE_1_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_MASK (0x40U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_ALP_ENABLE_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_ALP_ENABLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_ALP_ENABLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_ALP_ENABLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_ALP_ENABLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_SWAP_ENCODE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_CLANE_1_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_MASK (0x38U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_MASK (0x1C0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_1_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_MASK)
/*! @} */

/*! @name CORE_DIG_CLANE_2_RW_CFG_0 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_LP_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK (0x8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_PIN_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_MASK (0x10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_SHIFT (4U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ORDER_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_MASK (0x20U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_SHIFT (5U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_DECODE_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_MASK (0x40U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_ALIGNER_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_MASK (0x80U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_SHIFT (7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_HS_SYNC_DET_SWAP_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_ALP_ENABLE_REG_MASK (0x100U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_ALP_ENABLE_REG_SHIFT (8U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_ALP_ENABLE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_ALP_ENABLE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_ALP_ENABLE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_MASK (0x200U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_SWAP_ENCODE_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_CFG_0_SWAP_ENCODE_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_MASK (0x400U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT (10U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_LOOPBACK_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_CFG_0_LOOPBACK_MODE_EN_MASK)
/*! @} */

/*! @name CORE_DIG_CLANE_2_RW_HS_TX_6 -  */
/*! @{ */

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_MASK (0x7U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_SHIFT (0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB10_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_MASK (0x38U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_SHIFT (3U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB11_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_MASK (0x1C0U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_SHIFT (6U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB12_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_MASK (0xE00U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_SHIFT (9U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PROGSEQSYMB13_REG_MASK)

#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_MASK (0x7000U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_SHIFT (12U)
#define DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG(x) (((uint16_t)(((uint16_t)(x)) << DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_SHIFT)) & DISPLAY_MIPI_DSI_PHY_CORE_DIG_CLANE_2_RW_HS_TX_6_HS_TX_6_PIN_SWAP_REG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_MIPI_DSI_PHY_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_MIPI_DSI_PHY_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLAY_MIPI_DSI_PHY_H_ */

