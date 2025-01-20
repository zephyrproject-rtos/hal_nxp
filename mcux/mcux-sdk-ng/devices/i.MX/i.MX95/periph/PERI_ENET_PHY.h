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
**         CMSIS Peripheral Access Layer for ENET_PHY
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
 * @file ENET_PHY.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENET_PHY
 *
 * CMSIS Peripheral Access Layer for ENET_PHY
 */

#if !defined(ENET_PHY_H_)
#define ENET_PHY_H_                              /**< Symbol preventing repeated inclusion */

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
   -- ENET_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_Peripheral_Access_Layer ENET_PHY Peripheral Access Layer
 * @{
 */

/** ENET_PHY - Size of Registers Arrays */
#define ENET_PHY_RAWMEM_D_ROM_CMNX_COUNT          64u
#define ENET_PHY_RAWMEM_D_ROM_CMNX_RAWMEM_D_ROM_CMNX_BY_COUNT 8u
#define ENET_PHY_RAWMEM_D_ROM_CMNX_RAWMEM_D_ROM_CMNX_BY_RAWMEM_D_ROM_CMNX_BY_RZ_COUNT 32u
#define ENET_PHY_RAWMEM_D_RAM_CMNX_COUNT          64u
#define ENET_PHY_RAWMEM_D_RAM_CMNX_RAWMEM_D_RAM_CMNX_BY_COUNT 8u
#define ENET_PHY_RAWMEM_D_RAM_CMNX_RAWMEM_D_RAM_CMNX_BY_RAWMEM_D_RAM_CMNX_BY_RZ_COUNT 32u

/** ENET_PHY - Register Layout Typedef */
typedef struct {
  __I  uint16_t SUP_DIG_IDCODE_LO;                 /**< Low 16 Bits of IDCODE, offset: 0x0 */
       uint8_t RESERVED_0[2];
  __I  uint16_t SUP_DIG_IDCODE_HI;                 /**< High 16 Bits of IDCODE, offset: 0x4 */
       uint8_t RESERVED_1[2];
  __IO uint16_t SUP_DIG_REFCLK_OVRD_IN;            /**< Override Values for Incoming REFCLK and RESET Controls from ASIC, offset: 0x8 */
       uint8_t RESERVED_2[2];
  __IO uint16_t SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN;   /**< Override Values for Incoming MPLLA_B_DIV_CLK Controls from ASIC, offset: 0xC */
       uint8_t RESERVED_3[2];
  __IO uint16_t SUP_DIG_SUP_OVRD_IN_0;             /**< Override Values for Support Block ASIC Inputs 0, offset: 0x10 */
       uint8_t RESERVED_4[2];
  __IO uint16_t SUP_DIG_SUP_OVRD_IN_1;             /**< Override Values for Support Block ASIC Inputs 1, offset: 0x14 */
       uint8_t RESERVED_5[2];
  __IO uint16_t SUP_DIG_SUP_OVRD_IN_2;             /**< Override Values for Support Block ASIC Inputs 2, offset: 0x18 */
       uint8_t RESERVED_6[2];
  __IO uint16_t SUP_DIG_SUP_OVRD_OUT;              /**< Override Values for Support Block ASIC Outputs, offset: 0x1C */
       uint8_t RESERVED_7[2];
  __IO uint16_t SUP_DIG_LVL_OVRD_IN;               /**< Override Values for Level Settings, offset: 0x20 */
       uint8_t RESERVED_8[2];
  __IO uint16_t SUP_DIG_DEBUG;                     /**< Debug Controls, offset: 0x24 */
       uint8_t RESERVED_9[2];
  __I  uint16_t SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN;   /**< Current Values for Incoming MPLLA_B_DIV_CLK Controls from ASIC, offset: 0x28 */
       uint8_t RESERVED_10[2];
  __I  uint16_t SUP_DIG_ASIC_IN;                   /**< Current Values for Incoming SUP Control Signals from ASIC, offset: 0x2C */
       uint8_t RESERVED_11[2];
  __I  uint16_t SUP_DIG_LVL_ASIC_IN;               /**< Current Values for Incoming Level Controls from ASIC, offset: 0x30 */
       uint8_t RESERVED_12[2];
  __IO uint16_t SUP_DIG_SUP_OVRD_MISC;             /**< Override Values for Incoming SUP MISC BUS from ASIC, offset: 0x34 */
       uint8_t RESERVED_13[2];
  __IO uint16_t SUP_DIG_CLK_RST_BG_PWRUP_TIME_0;   /**< BG Power UP Time 0, offset: 0x38 */
       uint8_t RESERVED_14[2];
  __IO uint16_t SUP_DIG_CLK_RST_BG_PWRUP_TIME_1;   /**< BG Power UP Time 1, offset: 0x3C */
       uint8_t RESERVED_15[2];
  __IO uint16_t SUP_ANA_RTUNE_CTRL;                /**< RTUNE_CTRL, offset: 0x40 */
       uint8_t RESERVED_16[2];
  __IO uint16_t SUP_ANA_SWITCH_PWR_MEAS;           /**< SWITCH_PWR_MEAS, offset: 0x44 */
       uint8_t RESERVED_17[2];
  __IO uint16_t SUP_ANA_SWITCH_MISC_MEAS;          /**< SWITCH_MISC_MEAS, offset: 0x48 */
       uint8_t RESERVED_18[2];
  __IO uint16_t SUP_ANA_BG;                        /**< BG, offset: 0x4C */
       uint8_t RESERVED_19[2];
  __IO uint16_t SUP_DIG_RTUNE_DEBUG;               /**< Resistor Tuning Debug Controls, offset: 0x50 */
       uint8_t RESERVED_20[2];
  __IO uint16_t SUP_DIG_RTUNE_CONFIG;              /**< Configure Rtune Operation, offset: 0x54 */
       uint8_t RESERVED_21[2];
  __I  uint16_t SUP_DIG_RTUNE_STAT;                /**< Resistor Tuning Register Status, offset: 0x58 */
       uint8_t RESERVED_22[2];
  __IO uint16_t SUP_DIG_RTUNE_RX_SET_VAL;          /**< Set Value of RX Resistor, offset: 0x5C */
       uint8_t RESERVED_23[2];
  __IO uint16_t SUP_DIG_RTUNE_TXDN_SET_VAL;        /**< Set Value of TX-DN Resistor, offset: 0x60 */
       uint8_t RESERVED_24[2];
  __IO uint16_t SUP_DIG_RTUNE_TXUP_SET_VAL;        /**< Set Value of TX-UP Resistor, offset: 0x64 */
       uint8_t RESERVED_25[2];
  __I  uint16_t SUP_DIG_RTUNE_RX_STAT;             /**< RX Resistor Tuning Register Status, offset: 0x68 */
       uint8_t RESERVED_26[2];
  __I  uint16_t SUP_DIG_RTUNE_TXDN_STAT;           /**< TX-DN Resistor Tuning Register Status, offset: 0x6C */
       uint8_t RESERVED_27[2];
  __I  uint16_t SUP_DIG_RTUNE_TXUP_STAT;           /**< TX-UP Resistor Tuning Register Status, offset: 0x70 */
       uint8_t RESERVED_28[2];
  __IO uint16_t SUP_DIG_ANA_RTUNE_OVRD_OUT;        /**< Override Value for RTUNE Signals Going to ANA, offset: 0x74 */
       uint8_t RESERVED_29[2];
  __IO uint16_t SUP_DIG_ANA_RX_TERM_OVRD_OUT;      /**< Override Value for RX Termination Signals Going to ANA, offset: 0x78 */
       uint8_t RESERVED_30[2];
  __I  uint16_t SUP_DIG_ANA_STAT;                  /**< SUP Input Status Register for SUP ANA Outputs, offset: 0x7C */
       uint8_t RESERVED_31[2];
  __IO uint16_t SUP_DIG_ANA_BG_OVRD_OUT;           /**< Override Values for Bandgap Signals Going to ANA, offset: 0x80 */
       uint8_t RESERVED_32[2];
  __I  uint16_t SUP_DIG_FREQ_CNT_PEAK_ASIC_IN;     /**< Current Values for Incoming Level Controls from ASIC, offset: 0x84 */
       uint8_t RESERVED_33[2];
  __I  uint16_t SUP_DIG_TXUP_TERM_OFFSET_ASIC_IN;  /**< Current Values for Incoming Level Controls from ASIC, offset: 0x88 */
       uint8_t RESERVED_34[2];
  __I  uint16_t SUP_DIG_TXDN_TERM_OFFSET_ASIC_IN;  /**< Current Values for Incoming Level Controls from ASIC, offset: 0x8C */
       uint8_t RESERVED_35[2];
  __I  uint16_t SUP_DIG_MISC_ASIC_IN;              /**< Current Values for Incoming Level Controls from ASIC, offset: 0x90 */
       uint8_t RESERVED_36[2];
  __IO uint16_t RAWCMN_DIG_CMN_CTL;                /**< Common Control, offset: 0x94 */
       uint8_t RESERVED_37[2];
  __IO uint16_t RAWCMN_DIG_LANE_FSM_OP_XTND;       /**< Lane FSM OP XTND Control, offset: 0x98 */
       uint8_t RESERVED_38[2];
  __IO uint16_t RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0;  /**< Override Values for Incoming TX Term Offset, offset: 0x9C */
       uint8_t RESERVED_39[2];
  __IO uint16_t RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1;  /**< Override Values for Incoming TX/RX Term Offset, offset: 0xA0 */
       uint8_t RESERVED_40[2];
  __IO uint16_t RAWCMN_DIG_CMN_CTL_1;              /**< Common Control 1, offset: 0xA4 */
       uint8_t RESERVED_41[2];
  __IO uint16_t RAWCMN_DIG_MPLL_OFF_TIME;          /**< Wait Time for Turning MPLL Off, offset: 0xA8 */
       uint8_t RESERVED_42[2];
  __IO uint16_t RAWCMN_DIG_ATE_ALU_CTRL;           /**< ATE ALU Module Control, offset: 0xAC */
       uint8_t RESERVED_43[2];
  __IO uint16_t RAWCMN_DIG_ATE_ALU_ADDR;           /**< Address for Read and Write Command for ATE ALU Module, offset: 0xB0 */
       uint8_t RESERVED_44[2];
  __IO uint16_t RAWCMN_DIG_ATE_ALU_DATA;           /**< Data for Write Command for ATE ALU Module, offset: 0xB4 */
       uint8_t RESERVED_45[2];
  __I  uint16_t RAWCMN_DIG_ATE_ALU_FLAGS;          /**< Flags from ATE ALU Module, offset: 0xB8 */
       uint8_t RESERVED_46[2];
  __I  uint16_t RAWCMN_DIG_ATE_ALU_ACCUM;          /**< Stores the ATE ALU Accumulator Result, offset: 0xBC */
       uint8_t RESERVED_47[2];
  __I  uint16_t RAWCMN_DIG_MPLL_IN;                /**< Current Values for Incoming MPLL Controls from PCS (Pre-Override Input Monitor), offset: 0xC0 */
       uint8_t RESERVED_48[2];
  __IO uint16_t RAWCMN_DIG_FW_PWRUP_DONE;          /**< Firmware Power-up Done Status, offset: 0xC4 */
       uint8_t RESERVED_49[2];
  __IO uint16_t RAWCMN_DIG_MPLL_CLK_ASYNC_EN;      /**< MPLL Output Clocks Asynchronous Control, offset: 0xC8 */
       uint8_t RESERVED_50[2];
  __IO uint16_t RAWCMN_DIG_ATE_ALU_SPARE_0;        /**< Spare Register 1 for ATE ALU Operations, offset: 0xCC */
       uint8_t RESERVED_51[2];
  __IO uint16_t RAWCMN_DIG_ATE_ALU_SPARE_1;        /**< Spare Register 2 for ATE ALU Operations, offset: 0xD0 */
       uint8_t RESERVED_52[2];
  __IO uint16_t RAWCMN_DIG_MPLL_STATE_OVRD_IN;     /**< Override for MPLLA/B State Outputs, offset: 0xD4 */
       uint8_t RESERVED_53[2];
  __IO uint16_t RAWCMN_DIG_AON_SRAM_PGATE_BL_EN;   /**< Enable SRAM Bootloader on Power-Gated Exit, offset: 0xD8 */
       uint8_t RESERVED_54[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD; /**< Override Incoming MPLLA/B_RECAL_BANK_SEL Input, offset: 0xDC */
       uint8_t RESERVED_55[2];
  __IO uint16_t RAWCMN_DIG_AON_PG_OVRD_IN;         /**< Override Values for Incoming Power-Gating Signals, offset: 0xE0 */
       uint8_t RESERVED_56[2];
  __IO uint16_t RAWCMN_DIG_AON_PG_OVRD_OUT;        /**< Override Values for Outgoing Power-Gating Signals, offset: 0xE4 */
       uint8_t RESERVED_57[2];
  __IO uint16_t RAWCMN_DIG_AON_SUP_OVRD_IN;        /**< Override Values for Incoming Support Block Signals, offset: 0xE8 */
       uint8_t RESERVED_58[2];
  __IO uint16_t RAWCMN_DIG_AON_SUP_OVRD_OUT;       /**< Override Values for Out-going Support Block Signals, offset: 0xEC */
       uint8_t RESERVED_59[2];
  __IO uint16_t RAWCMN_DIG_AON_RTUNE_RX_VAL;       /**< Resistor Tune RX Value, offset: 0xF0 */
       uint8_t RESERVED_60[2];
  __IO uint16_t RAWCMN_DIG_AON_RTUNE_TXDN_VAL;     /**< Resistor Tune TX Down Value, offset: 0xF4 */
       uint8_t RESERVED_61[2];
  __IO uint16_t RAWCMN_DIG_AON_RTUNE_TXUP_VAL;     /**< Resistor Tune TX Up Value, offset: 0xF8 */
       uint8_t RESERVED_62[2];
  __IO uint16_t RAWCMN_DIG_AON_CMNCAL_STATUS;      /**< Common Calibration Status, offset: 0xFC */
       uint8_t RESERVED_63[2];
  __IO uint16_t RAWCMN_DIG_AON_SRAM_OVRD_IN;       /**< Override for Incoming SRAM Inputs, offset: 0x100 */
       uint8_t RESERVED_64[2];
  __I  uint16_t RAWCMN_DIG_AON_SRAM_IN;            /**< Monitor for SRAM Inputs, offset: 0x104 */
       uint8_t RESERVED_65[2];
  __I  uint16_t RAWCMN_DIG_AON_SRAM_OUT;           /**< Monitor for SRAM Outputs, offset: 0x108 */
       uint8_t RESERVED_66[2];
  __IO uint16_t RAWCMN_DIG_AON_FW_VERSION_0;       /**< Firmware Version 0, offset: 0x10C */
       uint8_t RESERVED_67[2];
  __IO uint16_t RAWCMN_DIG_AON_FW_VERSION_1;       /**< Firmware Version 1, offset: 0x110 */
       uint8_t RESERVED_68[130798];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_0;           /**< Override Values for Incoming MPLLA Controls from ASIC 0, offset: 0x20000 */
       uint8_t RESERVED_69[2];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_1;           /**< Override Values for Incoming MPLLA Controls from ASIC 1, offset: 0x20004 */
       uint8_t RESERVED_70[2];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_2;           /**< Override Values for Incoming MPLLA Controls from ASIC 2, offset: 0x20008 */
       uint8_t RESERVED_71[2];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_3;           /**< Override Values for Incoming MPLLA Controls from ASIC 3, offset: 0x2000C */
       uint8_t RESERVED_72[2];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_4;           /**< Override Values for Incoming MPLLA Controls from ASIC 4, offset: 0x20010 */
       uint8_t RESERVED_73[2];
  __I  uint16_t SUP_DIG_MPLLA_ASIC_IN_0;           /**< Current Values for Incoming MPLLA Controls from ASIC 0, offset: 0x20014 */
       uint8_t RESERVED_74[2];
  __I  uint16_t SUP_DIG_MPLLA_ASIC_IN_1;           /**< Current Values for Incoming MPLLA Controls from ASIC 1, offset: 0x20018 */
       uint8_t RESERVED_75[2];
  __I  uint16_t SUP_DIG_MPLLA_ASIC_IN_2;           /**< Current Values for Incoming MPLLA Controls from ASIC 2, offset: 0x2001C */
       uint8_t RESERVED_76[2];
  __I  uint16_t SUP_DIG_MPLLA_FREQ_CNT_INIT_ASIC_IN; /**< Current Values for Incoming Level Controls from ASIC, offset: 0x20020 */
       uint8_t RESERVED_77[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL; /**< MPLL Calibration Controls, offset: 0x20024 */
       uint8_t RESERVED_78[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD; /**< MPLL Override Controls, offset: 0x20028 */
       uint8_t RESERVED_79[2];
  __I  uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT;   /**< MPLL Status, offset: 0x2002C */
       uint8_t RESERVED_80[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD; /**< Thresholds for MPLL CAL Update Timer and MPLL VCO Stabilization Timer, offset: 0x20030 */
       uint8_t RESERVED_81[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD; /**< Thresholds for PCLK Enable and MPLL VCO Clock Stabilization Timer, offset: 0x20034 */
       uint8_t RESERVED_82[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH; /**< Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer, offset: 0x20038 */
       uint8_t RESERVED_83[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH; /**< Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer, offset: 0x2003C */
       uint8_t RESERVED_84[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD; /**< Thresholds for MPLL Feedback Clock Enable and MPLL Feedback Digital Clock Disable Timer, offset: 0x20040 */
       uint8_t RESERVED_85[2];
  __I  uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL; /**< MPLL coarse_tune Value, offset: 0x20044 */
       uint8_t RESERVED_86[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE; /**< Value for MPLL coarse_tune When Skipping Calibration, offset: 0x20048 */
       uint8_t RESERVED_87[2];
  __IO uint16_t SUP_DIG_MPLLA_SSC_SS_PHASE;        /**< Current MPLL Phase Selector Value, offset: 0x2004C */
       uint8_t RESERVED_88[2];
  __IO uint16_t SUP_DIG_MPLLA_SSC_SS_FREQ_0;       /**< Frequency Control for Spread Spectrum 0, offset: 0x20050 */
       uint8_t RESERVED_89[2];
  __IO uint16_t SUP_DIG_MPLLA_SSC_SS_FREQ_1;       /**< Frequency Control for Spread Spectrum 1, offset: 0x20054 */
       uint8_t RESERVED_90[2];
  __IO uint16_t SUP_ANA_MPLLA_LOOP_CTRL;           /**< MPLLA_LOOP_CTRL, offset: 0x20058 */
       uint8_t RESERVED_91[2];
  __IO uint16_t SUP_ANA_MPLLA_OVRD;                /**< MPLLA_OVRD, offset: 0x2005C */
       uint8_t RESERVED_92[14];
  __IO uint16_t SUP_DIG_ANA_MPLLA_OVRD_OUT;        /**< Override Value for MPLLA Signals Going to ANA, offset: 0x2006C */
       uint8_t RESERVED_93[2];
  __IO uint16_t SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT;   /**< Override Value for MPLLA PMIX Signals Going to ANA, offset: 0x20070 */
       uint8_t RESERVED_94[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_BW_OVRD_IN;       /**< Override Values for Incoming MPLLA Bandwidth, offset: 0x20074 */
       uint8_t RESERVED_95[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN;  /**< Override Values for Incoming MPLLA SSC Control Settings, offset: 0x20078 */
       uint8_t RESERVED_96[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN;   /**< Override Values for Incoming MPLLA SSC Input Signals, offset: 0x2007C */
       uint8_t RESERVED_97[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_MISC_OVRD_IN;     /**< Override Values for Incoming MPLLA-Related Input Signals, offset: 0x20080 */
       uint8_t RESERVED_98[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0; /**< MPLLA Coarse Tune Value for Bank 0, offset: 0x20084 */
       uint8_t RESERVED_99[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1; /**< MPLLA Coarse Tune Value for Bank 1, offset: 0x20088 */
       uint8_t RESERVED_100[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2; /**< MPLLA Coarse Tune Value for Bank 2, offset: 0x2008C */
       uint8_t RESERVED_101[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3; /**< MPLLA Coarse Tune Value for Bank 3, offset: 0x20090 */
       uint8_t RESERVED_102[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLA_CAL_BANK_SEL; /**< Value for MPLLA Bank Select, offset: 0x20094 */
       uint8_t RESERVED_103[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_DONE; /**< Valid Calibrated Value for MPLLA Calibration Bank, offset: 0x20098 */
       uint8_t RESERVED_104[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLA_COARSE_TUNE;  /**< Selected COARSE TUNE Value for MPLLA, offset: 0x2009C */
       uint8_t RESERVED_105[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLA_IN_RECAL;     /**< MPLLA Re-Calibration, offset: 0x200A0 */
       uint8_t RESERVED_106[2];
  __IO uint16_t RAWCMN_DIG_AON_PMA_MPLLA_RECAL_BANK_SEL; /**< Current Bank Selected for MPLLA Coarse Tune in PMA, offset: 0x200A4 */
       uint8_t RESERVED_107[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLA_BANK_SEL_DONE; /**< Status for MPLLA Re-Calibration or Switching, offset: 0x200A8 */
       uint8_t RESERVED_108[130902];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_0;           /**< Override Values for Incoming MPLLB Controls from ASIC 0, offset: 0x40000 */
       uint8_t RESERVED_109[2];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_1;           /**< Override Values for Incoming MPLLB Controls from ASIC 1, offset: 0x40004 */
       uint8_t RESERVED_110[2];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_2;           /**< Override Values for Incoming MPLLB Controls from ASIC 2, offset: 0x40008 */
       uint8_t RESERVED_111[2];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_3;           /**< Override Values for Incoming MPLLB Controls from ASIC 3, offset: 0x4000C */
       uint8_t RESERVED_112[2];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_4;           /**< Override Values for Incoming MPLLB Controls from ASIC 4, offset: 0x40010 */
       uint8_t RESERVED_113[2];
  __I  uint16_t SUP_DIG_MPLLB_ASIC_IN_0;           /**< Current Values for Incoming MPLLB Controls from ASIC 0, offset: 0x40014 */
       uint8_t RESERVED_114[2];
  __I  uint16_t SUP_DIG_MPLLB_ASIC_IN_1;           /**< Current Values for Incoming MPLLB Controls from ASIC 1, offset: 0x40018 */
       uint8_t RESERVED_115[2];
  __I  uint16_t SUP_DIG_MPLLB_ASIC_IN_2;           /**< Current Values for Incoming MPLLB Controls from ASIC 2, offset: 0x4001C */
       uint8_t RESERVED_116[2];
  __I  uint16_t SUP_DIG_MPLLB_FREQ_CNT_INIT_ASIC_IN; /**< Current Values for Incoming Level Controls from ASIC, offset: 0x40020 */
       uint8_t RESERVED_117[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL; /**< MPLL Calibration Controls, offset: 0x40024 */
       uint8_t RESERVED_118[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD; /**< MPLL Override Controls, offset: 0x40028 */
       uint8_t RESERVED_119[2];
  __I  uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT;   /**< MPLL Status, offset: 0x4002C */
       uint8_t RESERVED_120[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD; /**< Thresholds for MPLL CAL Update Timer and MPLL VCO Stabilization Timer, offset: 0x40030 */
       uint8_t RESERVED_121[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD; /**< Thresholds for PCLK Enable and MPLL VCO Clock Stabilization Timer, offset: 0x40034 */
       uint8_t RESERVED_122[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH; /**< Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer, offset: 0x40038 */
       uint8_t RESERVED_123[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH; /**< Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer, offset: 0x4003C */
       uint8_t RESERVED_124[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD; /**< Thresholds for MPLL Feedback Clock Enable and MPLL Feedback Digital Clock Disable Timer, offset: 0x40040 */
       uint8_t RESERVED_125[2];
  __I  uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL; /**< MPLL coarse_tune Value, offset: 0x40044 */
       uint8_t RESERVED_126[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE; /**< Value for MPLL coarse_tune When Skipping Calibration, offset: 0x40048 */
       uint8_t RESERVED_127[2];
  __IO uint16_t SUP_DIG_MPLLB_SSC_SS_PHASE;        /**< Current MPLL Phase Selector Value, offset: 0x4004C */
       uint8_t RESERVED_128[2];
  __IO uint16_t SUP_DIG_MPLLB_SSC_SS_FREQ_0;       /**< Frequency Control for Spread Spectrum 0, offset: 0x40050 */
       uint8_t RESERVED_129[2];
  __IO uint16_t SUP_DIG_MPLLB_SSC_SS_FREQ_1;       /**< Frequency Control for Spread Spectrum 1, offset: 0x40054 */
       uint8_t RESERVED_130[2];
  __IO uint16_t SUP_ANA_MPLLB_LOOP_CTRL;           /**< MPLLB_LOOP_CTRL, offset: 0x40058 */
       uint8_t RESERVED_131[2];
  __IO uint16_t SUP_ANA_MPLLB_OVRD;                /**< MPLLB_OVRD, offset: 0x4005C */
       uint8_t RESERVED_132[14];
  __IO uint16_t SUP_DIG_ANA_MPLLB_OVRD_OUT;        /**< Override Value for MPLLB Signals Going to ANA, offset: 0x4006C */
       uint8_t RESERVED_133[2];
  __IO uint16_t SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT;   /**< Override Value for MPLLB PMIX Signals Going to ANA, offset: 0x40070 */
       uint8_t RESERVED_134[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_BW_OVRD_IN;       /**< Override Values for Incoming MPLLB Bandwidth, offset: 0x40074 */
       uint8_t RESERVED_135[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN;  /**< Override Values for Incoming MPLLB SSC Control Settings, offset: 0x40078 */
       uint8_t RESERVED_136[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN;   /**< Override Values for Incoming MPLLB SSC Input Signals, offset: 0x4007C */
       uint8_t RESERVED_137[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_MISC_OVRD_IN;     /**< Override Values for Incoming MPLLB-Related Input Signals, offset: 0x40080 */
       uint8_t RESERVED_138[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0; /**< MPLLB Coarse Tune Value for Bank 0, offset: 0x40084 */
       uint8_t RESERVED_139[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1; /**< MPLLB Coarse Tune Value for Bank 1, offset: 0x40088 */
       uint8_t RESERVED_140[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2; /**< MPLLB Coarse Tune Value for Bank 2, offset: 0x4008C */
       uint8_t RESERVED_141[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3; /**< MPLLB Coarse Tune Value for Bank 3, offset: 0x40090 */
       uint8_t RESERVED_142[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLB_CAL_BANK_SEL; /**< Value for MPLLB Bank Select, offset: 0x40094 */
       uint8_t RESERVED_143[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_DONE; /**< Valid Calibrated Value for MPLLB Calibration Bank, offset: 0x40098 */
       uint8_t RESERVED_144[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLB_COARSE_TUNE;  /**< Selected COARSE TUNE Value for MPLLB, offset: 0x4009C */
       uint8_t RESERVED_145[2];
  __IO uint16_t RAWCMN_DIG_AON_MPLLB_IN_RECAL;     /**< MPLLB Re-Calibration, offset: 0x400A0 */
       uint8_t RESERVED_146[2];
  __IO uint16_t RAWCMN_DIG_AON_PMA_MPLLB_RECAL_BANK_SEL; /**< Current Bank Selected for MPLLB Coarse Tune in PMA, offset: 0x400A4 */
       uint8_t RESERVED_147[2];
  __I  uint16_t RAWCMN_DIG_AON_MPLLB_BANK_SEL_DONE; /**< Status for MPLLB Re-Calibration or Switching, offset: 0x400A8 */
       uint8_t RESERVED_148[130902];
  __IO uint16_t LANE0_DIG_ASIC_LANE_OVRD_IN;       /**< Override Values for Incoming LANE Controls from ASIC, offset: 0x60000 */
       uint8_t RESERVED_149[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_0;       /**< Override Values for Incoming TX Controls from ASIC 0, offset: 0x60004 */
       uint8_t RESERVED_150[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_1;       /**< Override Values for Incoming TX Drive Controls from ASIC 1, offset: 0x60008 */
       uint8_t RESERVED_151[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_2;       /**< Override Values for Incoming TX Drive Controls from ASIC 2, offset: 0x6000C */
       uint8_t RESERVED_152[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_OUT;        /**< Override Values for Outgoing TX Controls to ASIC, offset: 0x60010 */
       uint8_t RESERVED_153[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_0;       /**< Override Values for Incoming RX Controls from ASIC 0, offset: 0x60014 */
       uint8_t RESERVED_154[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_1;       /**< Override Values for Incoming RX Controls from ASIC 1, offset: 0x60018 */
       uint8_t RESERVED_155[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_2;       /**< Override Values for Incoming RX Controls from ASIC 2, offset: 0x6001C */
       uint8_t RESERVED_156[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_3;       /**< Override Values for Incoming RX Controls from ASIC 3, offset: 0x60020 */
       uint8_t RESERVED_157[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0;    /**< Override Values for Incoming RX EQ Controls from ASIC 0, offset: 0x60024 */
       uint8_t RESERVED_158[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1;    /**< Override Values for Incoming RX EQ Controls from ASIC 1, offset: 0x60028 */
       uint8_t RESERVED_159[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_OUT_0;      /**< Override Values for Outgoing RX controls to ASIC 0, offset: 0x6002C */
       uint8_t RESERVED_160[2];
  __I  uint16_t LANE0_DIG_ASIC_LANE_ASIC_IN;       /**< Current Values for Incoming LANE Controls from ASIC, offset: 0x60030 */
       uint8_t RESERVED_161[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_IN_0;       /**< Current Values for Incoming TX Controls from ASIC 0, offset: 0x60034 */
       uint8_t RESERVED_162[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_IN_1;       /**< Current Values for Incoming TX Controls from ASIC 1, offset: 0x60038 */
       uint8_t RESERVED_163[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_IN_2;       /**< Current Values for Incoming TX Controls from ASIC 2, offset: 0x6003C */
       uint8_t RESERVED_164[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_OUT;        /**< Current Values for Outgoing TX Status Controls from PHY, offset: 0x60040 */
       uint8_t RESERVED_165[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_ASIC_IN_0;       /**< Current Values for Incoming RX Controls from ASIC 0, offset: 0x60044 */
       uint8_t RESERVED_166[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_ASIC_IN_1;       /**< Current Values for Incoming RX Controls from ASIC 1, offset: 0x60048 */
       uint8_t RESERVED_167[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0;    /**< Current Values for Incoming RX EQ Controls from ASIC 0, offset: 0x6004C */
       uint8_t RESERVED_168[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1;    /**< Current Values for Incoming RX EQ Controls from ASIC 1, offset: 0x60050 */
       uint8_t RESERVED_169[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0; /**< Current Values for Incoming RX CDR VCO Controls from ASIC 0, offset: 0x60054 */
       uint8_t RESERVED_170[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1; /**< Current Values for Incoming RX CDR VCO Controls from ASIC 1, offset: 0x60058 */
       uint8_t RESERVED_171[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_ASIC_OUT_0;      /**< Current Values for Outgoing RX Status Controls from PHY 0, offset: 0x6005C */
       uint8_t RESERVED_172[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2;    /**< Override Values for Incoming RX EQ Controls from ASIC 2, offset: 0x60060 */
       uint8_t RESERVED_173[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3;    /**< Override Values for Incoming RX EQ Controls from ASIC 3, offset: 0x60064 */
       uint8_t RESERVED_174[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_MISC;       /**< Override Values for Incoming TX MISC BUS from ASIC, offset: 0x60068 */
       uint8_t RESERVED_175[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_MISC;       /**< Override Values for Incoming RX MISC BUS from ASIC, offset: 0x6006C */
       uint8_t RESERVED_176[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0;  /**< TX Power State Control for P0, offset: 0x60070 */
       uint8_t RESERVED_177[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S; /**< TX Power State Control for P0S, offset: 0x60074 */
       uint8_t RESERVED_178[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1;  /**< TX Power State Control for P1, offset: 0x60078 */
       uint8_t RESERVED_179[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2;  /**< TX Power State Control for P2, offset: 0x6007C */
       uint8_t RESERVED_180[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0; /**< TX Power UP Time 0, offset: 0x60080 */
       uint8_t RESERVED_181[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1; /**< TX Power UP Time 1, offset: 0x60084 */
       uint8_t RESERVED_182[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2; /**< TX Power UP Time 2, offset: 0x60088 */
       uint8_t RESERVED_183[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3; /**< TX Power UP Time 3, offset: 0x6008C */
       uint8_t RESERVED_184[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4; /**< TX Power UP Time 4, offset: 0x60090 */
       uint8_t RESERVED_185[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_FIFO_BYPASS; /**< TX FIFO Bypass, offset: 0x60094 */
       uint8_t RESERVED_186[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5; /**< TX Power UP Time 4, offset: 0x60098 */
       uint8_t RESERVED_187[2];
  __IO uint16_t LANE0_DIG_TX_LBERT_CTL;            /**< Pattern Generator Controls, offset: 0x6009C */
       uint8_t RESERVED_188[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0;  /**< RX Power State Control for P0, offset: 0x600A0 */
       uint8_t RESERVED_189[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S; /**< RX Power State Control for P0S, offset: 0x600A4 */
       uint8_t RESERVED_190[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1;  /**< RX Power State Control for P1, offset: 0x600A8 */
       uint8_t RESERVED_191[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2;  /**< RX Power State Control for P2, offset: 0x600AC */
       uint8_t RESERVED_192[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0; /**< RX Power UP Time 0, offset: 0x600B0 */
       uint8_t RESERVED_193[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1; /**< RX Power UP Time 1, offset: 0x600B4 */
       uint8_t RESERVED_194[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2; /**< RX Power UP Time 2, offset: 0x600B8 */
       uint8_t RESERVED_195[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3; /**< RX Power UP Control 0, offset: 0x600BC */
       uint8_t RESERVED_196[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0; /**< RX VCO Calibration Controls 0, offset: 0x600C0 */
       uint8_t RESERVED_197[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1; /**< RX VCO Calibration Controls 1, offset: 0x600C4 */
       uint8_t RESERVED_198[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2; /**< RX VCO Calibration Controls 2, offset: 0x600C8 */
       uint8_t RESERVED_199[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0; /**< RX Power UP Time 0, offset: 0x600CC */
       uint8_t RESERVED_200[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1; /**< RX Power UP Time 1, offset: 0x600D0 */
       uint8_t RESERVED_201[2];
  __I  uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0; /**< RX VCO Status 0, offset: 0x600D4 */
       uint8_t RESERVED_202[2];
  __I  uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1; /**< RX VCO Status 1, offset: 0x600D8 */
       uint8_t RESERVED_203[2];
  __I  uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2; /**< RX VCO Status 2, offset: 0x600DC */
       uint8_t RESERVED_204[6];
  __IO uint16_t LANE0_DIG_RX_LBERT_CTL;            /**< Pattern Matcher Controls, offset: 0x600E4 */
       uint8_t RESERVED_205[2];
  __IO uint16_t LANE0_DIG_RX_LBERT_ERR;            /**< Pattern Match Error Counter, offset: 0x600E8 */
       uint8_t RESERVED_206[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_0;        /**< Control Bits for Receiver in Recovered Domain, offset: 0x600EC */
       uint8_t RESERVED_207[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_1;        /**< CDR Control 1, offset: 0x600F0 */
       uint8_t RESERVED_208[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_2;        /**< CDR Control 2, offset: 0x600F4 */
       uint8_t RESERVED_209[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_3;        /**< CDR Control 3, offset: 0x600F8 */
       uint8_t RESERVED_210[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_4;        /**< CDR Control 4, offset: 0x600FC */
       uint8_t RESERVED_211[2];
  __I  uint16_t LANE0_DIG_RX_CDR_STAT;             /**< Current Output Values to DPLL (PHUG, FRUG), offset: 0x60100 */
       uint8_t RESERVED_212[2];
  __IO uint16_t LANE0_DIG_RX_DPLL_FREQ;            /**< Current Frequency Integrator Value, offset: 0x60104 */
       uint8_t RESERVED_213[2];
  __IO uint16_t LANE0_DIG_RX_DPLL_FREQ_BOUND_0;    /**< Frequency Bounds for Incoming Data Stream 0, offset: 0x60108 */
       uint8_t RESERVED_214[2];
  __IO uint16_t LANE0_DIG_RX_DPLL_FREQ_BOUND_1;    /**< Frequency Bounds for Incoming Data Stream 1, offset: 0x6010C */
       uint8_t RESERVED_215[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0;   /**< Adaptation Configuration 0, offset: 0x60110 */
       uint8_t RESERVED_216[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1;   /**< Adaptation Configuration 1, offset: 0x60114 */
       uint8_t RESERVED_217[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2;   /**< Adaptation Configuration 2, offset: 0x60118 */
       uint8_t RESERVED_218[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3;   /**< Adaptation Configuration 3, offset: 0x6011C */
       uint8_t RESERVED_219[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4;   /**< Adaptation Configuration 4, offset: 0x60120 */
       uint8_t RESERVED_220[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5;   /**< Adaptation Configuration 5, offset: 0x60124 */
       uint8_t RESERVED_221[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6;   /**< Adaptation Configuration 6, offset: 0x60128 */
       uint8_t RESERVED_222[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7;   /**< Adaptation Configuration 7, offset: 0x6012C */
       uint8_t RESERVED_223[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8;   /**< Adaptation Configuration 8, offset: 0x60130 */
       uint8_t RESERVED_224[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9;   /**< Adaptation Configuration 9, offset: 0x60134 */
       uint8_t RESERVED_225[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG; /**< Reset Adaptation Configuration, offset: 0x60138 */
       uint8_t RESERVED_226[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_ATT_STATUS;   /**< Value of ATT Adaptation code, offset: 0x6013C */
       uint8_t RESERVED_227[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_VGA_STATUS;   /**< Value of VGA Adaptation Code, offset: 0x60140 */
       uint8_t RESERVED_228[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_CTLE_STATUS;  /**< Value of CTLE Adaptation Code, offset: 0x60144 */
       uint8_t RESERVED_229[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS; /**< Value of DFE Tap1 Adaptation Code, offset: 0x60148 */
       uint8_t RESERVED_230[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS; /**< Value of DFE Tap2 Adaptation Code, offset: 0x6014C */
       uint8_t RESERVED_231[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS; /**< Value of DFE Tap3 Adaptation Code, offset: 0x60150 */
       uint8_t RESERVED_232[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS; /**< Value of DFE Tap4 Adaptation Code, offset: 0x60154 */
       uint8_t RESERVED_233[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS; /**< Value of DFE Tap5 Adaptation Code, offset: 0x60158 */
       uint8_t RESERVED_234[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_HIGH_VDAC_OFST; /**< Offset Values for RX DFE Data Even High vDAC, offset: 0x6015C */
       uint8_t RESERVED_235[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_LOW_VDAC_OFST; /**< Offset Values for RX DFE Data Even Low vDAC, offset: 0x60160 */
       uint8_t RESERVED_236[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_HIGH_VDAC_OFST; /**< Offset Values for RX DFE Data Odd High vDAC, offset: 0x60164 */
       uint8_t RESERVED_237[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_LOW_VDAC_OFST; /**< Offset Values for RX DFE Data Odd Low vDAC, offset: 0x60168 */
       uint8_t RESERVED_238[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN; /**< Sets Values for RX SLICER CTRL EVEN Signals Going to ANA, offset: 0x6016C */
       uint8_t RESERVED_239[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD; /**< Sets Values for RX SLICER CTRL ODD Signals Going to ANA, offset: 0x60170 */
       uint8_t RESERVED_240[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST; /**< Offset Values for RX DFE Error Even vDAC, offset: 0x60174 */
       uint8_t RESERVED_241[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST; /**< Offset Values for RX DFE Error Odd vDAC, offset: 0x60178 */
       uint8_t RESERVED_242[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL; /**< Value of Error Slicer Level, offset: 0x6017C */
       uint8_t RESERVED_243[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_EVEN_VDAC_OFST; /**< Offset Values for RX DFE By-Pass Even vDAC, offset: 0x60180 */
       uint8_t RESERVED_244[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_ODD_VDAC_OFST; /**< Offset Values for RX DFE By-Pass Odd vDAC, offset: 0x60184 */
       uint8_t RESERVED_245[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_RESET;   /**< Adaptation Reset, offset: 0x60188 */
       uint8_t RESERVED_246[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_10;  /**< Adaptation Configuration 10, offset: 0x6018C */
       uint8_t RESERVED_247[2];
  __IO uint16_t LANE0_DIG_RX_STAT_LD_VAL_1;        /**< Stat Load Value for the Sample Counter 1, offset: 0x60190 */
       uint8_t RESERVED_248[2];
  __IO uint16_t LANE0_DIG_RX_STAT_DATA_MSK;        /**< Stat Data Mask Bits [15:0], offset: 0x60194 */
       uint8_t RESERVED_249[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL0;      /**< Stat Match Controls 0, offset: 0x60198 */
       uint8_t RESERVED_250[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL1;      /**< Stat Match Controls 1, offset: 0x6019C */
       uint8_t RESERVED_251[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_CTL0;       /**< Stat Controls 0, offset: 0x601A0 */
       uint8_t RESERVED_252[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_CTL1;       /**< Stat Controls 1, offset: 0x601A4 */
       uint8_t RESERVED_253[2];
  __I  uint16_t LANE0_DIG_RX_STAT_SMPL_CNT1;       /**< Sample Counter 1 Status, offset: 0x601A8 */
       uint8_t RESERVED_254[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_0;      /**< Stat Counter 0 Status, offset: 0x601AC */
       uint8_t RESERVED_255[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_1;      /**< Stat Counter 1 Status, offset: 0x601B0 */
       uint8_t RESERVED_256[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_2;      /**< Stat Counter 2 Status, offset: 0x601B4 */
       uint8_t RESERVED_257[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_3;      /**< Stat Counter 3 Status, offset: 0x601B8 */
       uint8_t RESERVED_258[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_4;      /**< Stat Counter 4 Status, offset: 0x601BC */
       uint8_t RESERVED_259[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_5;      /**< Stat Counter 5 Status, offset: 0x601C0 */
       uint8_t RESERVED_260[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_6;      /**< Stat Counter 6 Status, offset: 0x601C4 */
       uint8_t RESERVED_261[2];
  __IO uint16_t LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL; /**< Calibration Comparator Control, offset: 0x601C8 */
       uint8_t RESERVED_262[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL2;      /**< Stat Match Controls 2, offset: 0x601CC */
       uint8_t RESERVED_263[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL3;      /**< Stat Match Controls 3, offset: 0x601D0 */
       uint8_t RESERVED_264[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL4;      /**< Stat Match Controls 4, offset: 0x601D4 */
       uint8_t RESERVED_265[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL5;      /**< Stat Match Controls 5, offset: 0x601D8 */
       uint8_t RESERVED_266[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_CTL2;       /**< Stat Controls 2, offset: 0x601DC */
       uint8_t RESERVED_267[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_STOP;       /**< Stat Stop, offset: 0x601E0 */
       uint8_t RESERVED_268[2];
  __IO uint16_t LANE0_DIG_ANA_TX_OVRD_OUT;         /**< Override Values for TX Signals Going to ANA, offset: 0x601E4 */
       uint8_t RESERVED_269[2];
  __IO uint16_t LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT; /**< Override Value for TX termination Code Up Going to ANA, offset: 0x601E8 */
       uint8_t RESERVED_270[2];
  __IO uint16_t LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT; /**< Override Value for TX termination Down Code Going to ANA, offset: 0x601EC */
       uint8_t RESERVED_271[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0;    /**< Override Values for TX EQ Signals Going to ANA 0, offset: 0x601F0 */
       uint8_t RESERVED_272[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1;    /**< Override Values for TX EQ Signals Going to ANA 1, offset: 0x601F4 */
       uint8_t RESERVED_273[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2;    /**< Override Values for TX EQ Signals Going to ANA 2, offset: 0x601F8 */
       uint8_t RESERVED_274[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3;    /**< Override Values for TX EQ Signals Going to ANA 3, offset: 0x601FC */
       uint8_t RESERVED_275[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_4;    /**< Override Values for TX EQ Signals Going to ANA 4, offset: 0x60200 */
       uint8_t RESERVED_276[2];
  __IO uint16_t LANE0_DIG_ANA_RX_CTL_OVRD_OUT;     /**< Override Values for RX Control Signals Going to ANA, offset: 0x60204 */
       uint8_t RESERVED_277[2];
  __IO uint16_t LANE0_DIG_ANA_RX_PWR_OVRD_OUT;     /**< Override Values for RX PWR UP/DN Signals Going to ANA, offset: 0x60208 */
       uint8_t RESERVED_278[2];
  __IO uint16_t LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0;   /**< Override Values for RX VCO Signals Going to ANA 0, offset: 0x6020C */
       uint8_t RESERVED_279[2];
  __IO uint16_t LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1;   /**< Override Values for RX VCO Signals Going to ANA 1, offset: 0x60210 */
       uint8_t RESERVED_280[2];
  __IO uint16_t LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2;   /**< Override Values for RX VCO Signals Going to ANA 2, offset: 0x60214 */
       uint8_t RESERVED_281[2];
  __IO uint16_t LANE0_DIG_ANA_RX_CAL;              /**< Sets Values for RX CAL Signals Going to ANA, offset: 0x60218 */
       uint8_t RESERVED_282[2];
  __IO uint16_t LANE0_DIG_ANA_RX_VDAC_RANGE_SEL;   /**< Sets Values for RX DAC CTRL Value Going to ANA, offset: 0x6021C */
       uint8_t RESERVED_283[2];
  __IO uint16_t LANE0_DIG_ANA_RX_DAC_CTRL;         /**< Sets Values for RX DAC CTRL Value Going to ANA, offset: 0x60220 */
       uint8_t RESERVED_284[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_RTRIM;        /**< Set Value for RX RTRIM Going to ANA, offset: 0x60224 */
       uint8_t RESERVED_285[2];
  __IO uint16_t LANE0_DIG_ANA_RX_DAC_CTRL_OVRD;    /**< Overrides RX DAC CTRL Bus (EN/VAL/SEL) Going to ANA, offset: 0x60228 */
       uint8_t RESERVED_286[2];
  __IO uint16_t LANE0_DIG_ANA_RX_DAC_CTRL_SEL;     /**< Sets Values for RX DAC CTRL Select Signal Going to ANA, offset: 0x6022C */
       uint8_t RESERVED_287[2];
  __IO uint16_t LANE0_DIG_ANA_RX_AFE_ATT_VGA;      /**< Value for RX AFE ATT & VGA Signals Going to ANA, offset: 0x60230 */
       uint8_t RESERVED_288[2];
  __IO uint16_t LANE0_DIG_ANA_RX_AFE_CTLE;         /**< Values for RX AFE CTLE Signals Going to ANA, offset: 0x60234 */
       uint8_t RESERVED_289[2];
  __IO uint16_t LANE0_DIG_ANA_RX_SCOPE;            /**< Values for RX SCOPE Signals Going to ANA, offset: 0x60238 */
       uint8_t RESERVED_290[2];
  __IO uint16_t LANE0_DIG_ANA_RX_SLICER_CTRL;      /**< Sets Values for RX Slicer Ctrl Signals Going to ANA, offset: 0x6023C */
       uint8_t RESERVED_291[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST; /**< Sets Values for RX ANA IQ PHASE Adjust Signal Going to ANA, offset: 0x60240 */
       uint8_t RESERVED_292[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN;  /**< Sets Values for RX ANA IQ SENSE Signal, offset: 0x60244 */
       uint8_t RESERVED_293[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN; /**< DAC Control Enable Signal, offset: 0x60248 */
       uint8_t RESERVED_294[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE; /**< AFE Update Enable Signal, offset: 0x6024C */
       uint8_t RESERVED_295[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK; /**< Phase Adjust Clock Signal, offset: 0x60250 */
       uint8_t RESERVED_296[2];
  __I  uint16_t LANE0_DIG_ANA_STATUS_0;            /**< Lane Input Status 0, offset: 0x60254 */
       uint8_t RESERVED_297[2];
  __I  uint16_t LANE0_DIG_ANA_STATUS_1;            /**< Lane Input Status 1, offset: 0x60258 */
       uint8_t RESERVED_298[2];
  __IO uint16_t LANE0_ANA_TX_OVRD_MEAS;            /**< TX_OVRD_MEAS, offset: 0x6025C */
       uint8_t RESERVED_299[2];
  __IO uint16_t LANE0_ANA_TX_PWR_OVRD;             /**< TX_PWR_OVRD, offset: 0x60260 */
       uint8_t RESERVED_300[2];
  __IO uint16_t LANE0_ANA_TX_ALT_BUS;              /**< TX_ALT_BUS, offset: 0x60264 */
       uint8_t RESERVED_301[10];
  __IO uint16_t LANE0_ANA_TX_VBOOST;               /**< TX_VBOOST, offset: 0x60270 */
       uint8_t RESERVED_302[2];
  __IO uint16_t LANE0_ANA_TX_TERM_CODE_DN;         /**< TX_TERM_CODE_DN, offset: 0x60274 */
       uint8_t RESERVED_303[2];
  __IO uint16_t LANE0_ANA_TX_TERM_CODE_UP;         /**< TX_TERM_CODE_UP, offset: 0x60278 */
       uint8_t RESERVED_304[2];
  __IO uint16_t LANE0_ANA_TX_IBOOST_CODE;          /**< TX_IBOOST_CODE, offset: 0x6027C */
       uint8_t RESERVED_305[2];
  __IO uint16_t LANE0_ANA_TX_OVRD_CLK;             /**< TX_OVRD_CLK, offset: 0x60280 */
       uint8_t RESERVED_306[2];
  __IO uint16_t LANE0_ANA_TX_MISC;                 /**< TX_MISC, offset: 0x60284 */
       uint8_t RESERVED_307[6];
  __IO uint16_t LANE0_ANA_RX_DCC_OVRD;             /**< RX_DCC_OVRD, offset: 0x6028C */
       uint8_t RESERVED_308[2];
  __IO uint16_t LANE0_ANA_RX_PWR_CTRL1;            /**< RX_PWR_CTRL1, offset: 0x60290 */
       uint8_t RESERVED_309[6];
  __IO uint16_t LANE0_ANA_RX_CDR_AFE;              /**< RX_CDR_AFE, offset: 0x60298 */
       uint8_t RESERVED_310[2];
  __IO uint16_t LANE0_ANA_RX_PWR_CTRL2;            /**< RX_PWR_CTRL2, offset: 0x6029C */
       uint8_t RESERVED_311[2];
  __IO uint16_t LANE0_ANA_RX_MISC_OVRD;            /**< RX_MISC_OVRD, offset: 0x602A0 */
       uint8_t RESERVED_312[2];
  __IO uint16_t LANE0_ANA_RX_CAL_MUXA;             /**< RX_CAL_MUXA, offset: 0x602A4 */
       uint8_t RESERVED_313[10];
  __IO uint16_t LANE0_ANA_RX_CAL_MUXB;             /**< RX_CAL_MUXB, offset: 0x602B0 */
       uint8_t RESERVED_314[2];
  __IO uint16_t LANE0_ANA_RX_TERM;                 /**< RX_TERM, offset: 0x602B4 */
       uint8_t RESERVED_315[2];
  __IO uint16_t LANE0_ANA_RX_SLC_CTRL;             /**< RX_SLC_CTRL, offset: 0x602B8 */
       uint8_t RESERVED_316[6];
  __IO uint16_t LANE0_ANA_RX_CDR_VCO_CTRL;         /**< RX_CDR_VCO_CTRL, offset: 0x602C0 */
       uint8_t RESERVED_317[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_TX_OVRD_IN;    /**< Override Values for Incoming TX Controls from PCS, offset: 0x602C4 */
       uint8_t RESERVED_318[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1;  /**< Override Values for Incoming TX Controls from PCS 1, offset: 0x602C8 */
       uint8_t RESERVED_319[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_TX_PCS_IN;     /**< Current Values for Incoming TX Controls from PCS (Pre-Override Input Monitor), offset: 0x602CC */
       uint8_t RESERVED_320[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT;   /**< Override Values for Outgoing TX Controls to PCS, offset: 0x602D0 */
       uint8_t RESERVED_321[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_TX_PCS_OUT;    /**< Current Values for Outgoing TX Status Controls from Raw PCS (Pre-Override Output Monitor), offset: 0x602D4 */
       uint8_t RESERVED_322[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN;    /**< Override Values for Incoming RX Controls from PCS, offset: 0x602D8 */
       uint8_t RESERVED_323[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1;  /**< Override Values for Incoming RX Controls from PCS 1, offset: 0x602DC */
       uint8_t RESERVED_324[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2;  /**< Override Values for Incoming RX Controls from PCS 2, offset: 0x602E0 */
       uint8_t RESERVED_325[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2; /**< ATE Override Input to Control Top-Level Inputs 3, offset: 0x602E4 */
       uint8_t RESERVED_326[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN;     /**< Current Values for Incoming RX Controls from PCS (Monitor on Post ATE Override), offset: 0x602E8 */
       uint8_t RESERVED_327[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1;   /**< Current Values for Incoming RX Controls from PCS 1 (Monitor on Pre-Override Signals), offset: 0x602EC */
       uint8_t RESERVED_328[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2;   /**< Current Values for Incoming RX Controls from PCS 2 (Monitor on the Pre-Override Signals), offset: 0x602F0 */
       uint8_t RESERVED_329[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3;   /**< Current Values for Incoming RX Controls from PCS 3 (Monitor on the Pre-Override Signals), offset: 0x602F4 */
       uint8_t RESERVED_330[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4;   /**< Current Values for Incoming RX Controls from PCS 4 (Monitor on the Pre-Override Signals), offset: 0x602F8 */
       uint8_t RESERVED_331[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT;   /**< Override Values for Outgoing RX Controls to PCS, offset: 0x602FC */
       uint8_t RESERVED_332[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_OUT;    /**< Current Values for Outgoing RX Status Controls from Raw PCS, offset: 0x60300 */
       uint8_t RESERVED_333[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK;  /**< RX Adaptation Acknowledge, offset: 0x60304 */
       uint8_t RESERVED_334[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM;  /**< RX Adaptation Figure of Merit, offset: 0x60308 */
       uint8_t RESERVED_335[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR;  /**< RX Calculated Direction for TX-Pre, offset: 0x6030C */
       uint8_t RESERVED_336[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR; /**< RX Calculated Direction for TX-Main, offset: 0x60310 */
       uint8_t RESERVED_337[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR; /**< RX Calculated Direction for TX-Post, offset: 0x60314 */
       uint8_t RESERVED_338[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_LANE_NUMBER;   /**< Current Lane Number, offset: 0x60318 */
       uint8_t RESERVED_339[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN;   /**< ATE Override Input to Control Top-Level Inputs 1, offset: 0x6031C */
       uint8_t RESERVED_340[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1; /**< Overrides the RX Output Clocks during the PHY Initialization 1, offset: 0x60320 */
       uint8_t RESERVED_341[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4;  /**< Override Values for Incoming RX Controls from PCS 4, offset: 0x60324 */
       uint8_t RESERVED_342[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5;  /**< RX Adaptation Mode Override, offset: 0x60328 */
       uint8_t RESERVED_343[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5;   /**< Current Values for Incoming RX Controls from PCS 5, offset: 0x6032C */
       uint8_t RESERVED_344[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6;  /**< Override Register for RX IQ Setting, offset: 0x60330 */
       uint8_t RESERVED_345[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1; /**< Override Values for Incoming RX EQ Controls from PCS 1, offset: 0x60334 */
       uint8_t RESERVED_346[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6;   /**< Current Values for Incoming RX Controls from PCS 6, offset: 0x60338 */
       uint8_t RESERVED_347[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1; /**< ATE Override Input to Control Top-Level Inputs 2, offset: 0x6033C */
       uint8_t RESERVED_348[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2; /**< Override Values for Incoming RX EQ Controls from PCS 2, offset: 0x60340 */
       uint8_t RESERVED_349[2];
  __IO uint16_t RAWLANE0_DIG_FSM_FSM_OVRD_CTL;     /**< FSM Override Control, offset: 0x60344 */
       uint8_t RESERVED_350[2];
  __IO uint16_t RAWLANE0_DIG_FSM_FSM_JMP_BANK;     /**< FSM Jump Bank, offset: 0x60348 */
       uint8_t RESERVED_351[2];
  __IO uint16_t RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0; /**< FSM Breakpoint 0 on SRAM Address for Debugging, offset: 0x6034C */
       uint8_t RESERVED_352[2];
  __IO uint16_t RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1; /**< FSM Breakpoint 1 on SRAM Address for Debugging, offset: 0x60350 */
       uint8_t RESERVED_353[2];
  __I  uint16_t RAWLANE0_DIG_FSM_MEM_ADDR_MON;     /**< Memory Address Monitor, offset: 0x60354 */
       uint8_t RESERVED_354[2];
  __I  uint16_t RAWLANE0_DIG_FSM_STATUS_MON;       /**< FSM Status Monitor, offset: 0x60358 */
       uint8_t RESERVED_355[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL; /**< Status of Fast RX Start Up Calibration, offset: 0x6035C */
       uint8_t RESERVED_356[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_ADAPT;    /**< Status of Fast RX Adaptation, offset: 0x60360 */
       uint8_t RESERVED_357[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_SUP;         /**< Status of Fast Support Block, offset: 0x60364 */
       uint8_t RESERVED_358[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE; /**< Status of Fast TX Common-Mode Charge-Up, offset: 0x60368 */
       uint8_t RESERVED_359[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_TX_RXDET;    /**< Status of Fast TX Detect RX, offset: 0x6036C */
       uint8_t RESERVED_360[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_PWRUP;    /**< Status of Fast RX Power-Up, offset: 0x60370 */
       uint8_t RESERVED_361[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT; /**< Status of Fast RX VCO Wait Times, offset: 0x60374 */
       uint8_t RESERVED_362[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL;  /**< Status of Fast RX VCO Calibration, offset: 0x60378 */
       uint8_t RESERVED_363[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT; /**< Status of Fast RX Continuous Calibration/Adaptation, offset: 0x6037C */
       uint8_t RESERVED_364[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT; /**< Status of Fast RX Continuous Adaptation, offset: 0x60380 */
       uint8_t RESERVED_365[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_CAL; /**< Status of RX AFE Startup Calibration, offset: 0x60384 */
       uint8_t RESERVED_366[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_CAL; /**< Status of RX DFE Startup Calibration, offset: 0x60388 */
       uint8_t RESERVED_367[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_DFE_EXT_STARTUP_CAL; /**< Status of DFE Extended Startup Calibration, offset: 0x6038C */
       uint8_t RESERVED_368[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_IQ_DELTA_STARTUP; /**< Status of RX IQ Fixed Offset, offset: 0x60390 */
       uint8_t RESERVED_369[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_CAL; /**< Status of RX IQ Startup Calibration, offset: 0x60394 */
       uint8_t RESERVED_370[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_ADAPT; /**< Status of RX AFE Startup Adaptation, offset: 0x60398 */
       uint8_t RESERVED_371[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_ADAPT; /**< Status of RX DFE Startup Adaptation, offset: 0x6039C */
       uint8_t RESERVED_372[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_ADAPT; /**< Status of RX IO Startup Adaptation, offset: 0x603A0 */
       uint8_t RESERVED_373[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_CONT_PHASE_CAL; /**< Status of RX Continuous Phase Calibration, offset: 0x603A4 */
       uint8_t RESERVED_374[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_AFE_CONT_CAL; /**< Status of RX AFE Continuous Calibration, offset: 0x603A8 */
       uint8_t RESERVED_375[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_REFLVL_CONT_ADAPT; /**< Status of RX Reference Level Continuous Adaptation, offset: 0x603AC */
       uint8_t RESERVED_376[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_VGA_CONT_ADAPT; /**< Status of RX VGA Continuous Adaptation, offset: 0x603B0 */
       uint8_t RESERVED_377[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_PHS_STARTUP_CAL; /**< Status of RX Phase Startup Calibration, offset: 0x603B4 */
       uint8_t RESERVED_378[2];
  __I  uint16_t RAWLANE0_DIG_FSM_SKIP_RX_PHS_EXT_STARTUP_CAL; /**< Status of RX Phase Extended Startup Calibration, offset: 0x603B8 */
       uint8_t RESERVED_379[2];
  __IO uint16_t RAWLANE0_DIG_FSM_FW_STATES_1;      /**< Stores Various States for Firmware - 2, offset: 0x603BC */
       uint8_t RESERVED_380[2];
  __IO uint16_t RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST; /**< Offset Value for RX AFE ATT iDAC, offset: 0x603C0 */
       uint8_t RESERVED_381[2];
  __IO uint16_t RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST; /**< Offset Value for RX AFE CTLE iDAC, offset: 0x603C4 */
       uint8_t RESERVED_382[2];
  __IO uint16_t RAWLANE0_DIG_AON_AFE_VGA1_IDAC_OFST; /**< Offset Values for RX AFE VGA1 iDAC, offset: 0x603C8 */
       uint8_t RESERVED_383[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST; /**< Offset Values for RX DFE Phase Even vDAC, offset: 0x603CC */
       uint8_t RESERVED_384[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST; /**< Offset Values for RX DFE Phase Odd vDAC, offset: 0x603D0 */
       uint8_t RESERVED_385[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_PHASE_EVEN_LOW_VDAC_OFST; /**< Offset Values for RX DFE Phase Even Low vDAC, offset: 0x603D4 */
       uint8_t RESERVED_386[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_PHASE_ODD_LOW_VDAC_OFST; /**< Offset Values for RX DFE Phase Odd Low vDAC, offset: 0x603D8 */
       uint8_t RESERVED_387[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_PHSADJ_LIN;    /**< RX Phase Adjust Linear Value, offset: 0x603DC */
       uint8_t RESERVED_388[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST; /**< Offset Values for RX DFE Data Even High vDAC, offset: 0x603E0 */
       uint8_t RESERVED_389[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_DATA_EVEN_LOW_VDAC_OFST; /**< Offset Values for RX DFE Data Even Low vDAC, offset: 0x603E4 */
       uint8_t RESERVED_390[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST; /**< Offset Values for RX DFE Data Odd High vDAC, offset: 0x603E8 */
       uint8_t RESERVED_391[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_DATA_ODD_LOW_VDAC_OFST; /**< Offset Values for RX DFE Data Odd Low vDAC, offset: 0x603EC */
       uint8_t RESERVED_392[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST; /**< Offset Values for RX DFE By-Pass Even vDAC, offset: 0x603F0 */
       uint8_t RESERVED_393[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST; /**< Offset Values for RX DFE By-Pass Odd vDAC, offset: 0x603F4 */
       uint8_t RESERVED_394[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST; /**< Offset Values for RX DFE Error Even vDAC, offset: 0x603F8 */
       uint8_t RESERVED_395[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST; /**< Offset Values for RX DFE Error Odd vDAC, offset: 0x603FC */
       uint8_t RESERVED_396[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_CAL_IQ;        /**< Value for RX Calibrated IQ Phase, offset: 0x60400 */
       uint8_t RESERVED_397[6];
  __IO uint16_t RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL; /**< Set to Skip Firmware Mission-Mode Algorithms, offset: 0x60408 */
       uint8_t RESERVED_398[2];
  __IO uint16_t RAWLANE0_DIG_AON_INIT_PWRUP_DONE;  /**< Initial Power-Up Done Status, offset: 0x6040C */
       uint8_t RESERVED_399[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_ATT;      /**< RX Adapted Value of ATT, offset: 0x60410 */
       uint8_t RESERVED_400[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_VGA;      /**< RX Adapted Value of VGA, offset: 0x60414 */
       uint8_t RESERVED_401[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_CTLE;     /**< RX Adapted Value of CTLE, offset: 0x60418 */
       uint8_t RESERVED_402[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1; /**< RX Adapted Value of DFE TAP1, offset: 0x6041C */
       uint8_t RESERVED_403[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2; /**< RX Adapted Value of DFE TAP2, offset: 0x60420 */
       uint8_t RESERVED_404[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3; /**< RX Adapted Value of DFE TAP3, offset: 0x60424 */
       uint8_t RESERVED_405[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4; /**< RX Adapted Value of DFE TAP4, offset: 0x60428 */
       uint8_t RESERVED_406[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5; /**< RX Adapted Value of DFE TAP5, offset: 0x6042C */
       uint8_t RESERVED_407[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_IQ;       /**< RX Adapted Value of IQ for Bank 0, offset: 0x60430 */
       uint8_t RESERVED_408[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_REF_ERR;  /**< RX Adapted Value of Reference Level for Error Slicer for Bank 0, offset: 0x60434 */
       uint8_t RESERVED_409[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADAPT_DONE;    /**< RX Adaptation Done Status, offset: 0x60438 */
       uint8_t RESERVED_410[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_ATT_B1;   /**< RX Adapted Value of ATT for Bank 1, offset: 0x6043C */
       uint8_t RESERVED_411[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_VGA_B1;   /**< RX Adapted Value of VGA for Bank 1, offset: 0x60440 */
       uint8_t RESERVED_412[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1;  /**< RX Adapted Value of CTLE for Bank 1, offset: 0x60444 */
       uint8_t RESERVED_413[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_B1; /**< RX Adapted Value of DFE TAP1 for Bank 1, offset: 0x60448 */
       uint8_t RESERVED_414[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_B1; /**< RX Adapted Value of DFE TAP2 for Bank 1, offset: 0x6044C */
       uint8_t RESERVED_415[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_B1; /**< RX Adapted Value of DFE TAP3 for Bank 1, offset: 0x60450 */
       uint8_t RESERVED_416[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_B1; /**< RX Adapted Value of DFE TAP4 for Bank 1, offset: 0x60454 */
       uint8_t RESERVED_417[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_B1; /**< RX Adapted Value of DFE TAP5 for Bank 1, offset: 0x60458 */
       uint8_t RESERVED_418[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_IQ_B1;    /**< RX Adapted Value of IQ for Bank 1, offset: 0x6045C */
       uint8_t RESERVED_419[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1; /**< RX Adapted Value of Reference Level for Error Slicer for Bank 1, offset: 0x60460 */
       uint8_t RESERVED_420[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1; /**< RX Adaptation Done Status for Bank 1, offset: 0x60464 */
       uint8_t RESERVED_421[6];
  __IO uint16_t RAWLANE0_DIG_AON_FW_STATES_0;      /**< Stores Various States for Firmware - 1, offset: 0x6046C */
       uint8_t RESERVED_422[2];
  __IO uint16_t RAWLANE0_DIG_AON_TXRX_OVRD_IN;     /**< Override Values for Incoming AON TX/RX Controls from PCS, offset: 0x60470 */
       uint8_t RESERVED_423[2];
  __IO uint16_t RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL; /**< Equalization Direction Polarity Setting in PCS RAW, offset: 0x60474 */
       uint8_t RESERVED_424[2];
  __IO uint16_t RAWLANE0_DIG_AON_TX_PRE_DIV;       /**< TX Pre Threshold Div, offset: 0x60478 */
       uint8_t RESERVED_425[2];
  __IO uint16_t RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD; /**< TX Main ATT High and Low Threshold, offset: 0x6047C */
       uint8_t RESERVED_426[2];
  __IO uint16_t RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD; /**< TX Main VGA High and Low Threshold, offset: 0x60480 */
       uint8_t RESERVED_427[2];
  __IO uint16_t RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD; /**< TX Post Boost High and Low Threshold, offset: 0x60484 */
       uint8_t RESERVED_428[2];
  __IO uint16_t RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD; /**< TX Post Tap1 High and Low Threshold, offset: 0x60488 */
       uint8_t RESERVED_429[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_CAL_REF_EE_VDAC_OFST; /**< Value for Reference Level Error Even Slicer, offset: 0x6048C */
       uint8_t RESERVED_430[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_CAL_REF_EO_VDAC_OFST; /**< Value for Reference Level Error Odd Slicer, offset: 0x60490 */
       uint8_t RESERVED_431[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST; /**< Value for DFE Error Even Low and High Slicer in Mission Mode, offset: 0x60494 */
       uint8_t RESERVED_432[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST; /**< Value for DFE Error Odd Low and High Slicer in Mission Mode, offset: 0x60498 */
       uint8_t RESERVED_433[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_ERR_SLC_MODE; /**< RX Adaptation Error Slicer Mode for Reference-Level Calibration, offset: 0x6049C */
       uint8_t RESERVED_434[2];
  __IO uint16_t RAWLANE0_DIG_AON_SETUP_REF_CTLE_IDAC_OFST; /**< Offset Value for AFE CTLE IDAC During Reference-Level Calibration, offset: 0x604A0 */
       uint8_t RESERVED_435[2];
  __IO uint16_t RAWLANE0_DIG_AON_SETUP_REF_VGA1_IDAC_OFST; /**< Offset Value for AFE VGA1 IDAC During Reference-Level Calibration, offset: 0x604A4 */
       uint8_t RESERVED_436[2];
  __IO uint16_t RAWLANE0_DIG_AON_SETUP_SLC_VGA1_IDAC_OFST; /**< Offset Value for AFE VGA1 for Slicer Setup Calibration, offset: 0x604A8 */
       uint8_t RESERVED_437[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL; /**< RX CDR Detector Control, offset: 0x604AC */
       uint8_t RESERVED_438[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_CDR_RECOVERY_TIME; /**< RX CDR Recovery Time in Reference Clock for the Intended PPM, offset: 0x604B0 */
       uint8_t RESERVED_439[2];
  __IO uint16_t RAWLANE0_DIG_AON_MEM_BREAKPOINT_2; /**< FSM Breakpoint 2 on SRAM Address for Debugging, offset: 0x604B4 */
       uint8_t RESERVED_440[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_0;       /**< Adaptation Control 0, offset: 0x604B8 */
       uint8_t RESERVED_441[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_1;       /**< Adaptation Control 1, offset: 0x604BC */
       uint8_t RESERVED_442[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ; /**< Reset Routine Request, offset: 0x604C0 */
       uint8_t RESERVED_443[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ; /**< RX Reset Interrupt, offset: 0x604C4 */
       uint8_t RESERVED_444[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ;   /**< RX Request Interrupt, offset: 0x604C8 */
       uint8_t RESERVED_445[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ;  /**< RX Rate Change Interrupt Request, offset: 0x604CC */
       uint8_t RESERVED_446[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ; /**< RX P-State Change Interrupt Request, offset: 0x604D0 */
       uint8_t RESERVED_447[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ; /**< RX Adaptation Request Interrupt, offset: 0x604D4 */
       uint8_t RESERVED_448[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ; /**< RX Adaptation Disable Interrupt, offset: 0x604D8 */
       uint8_t RESERVED_449[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR; /**< RX-Reset Interrupt Clear, offset: 0x604DC */
       uint8_t RESERVED_450[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR; /**< RX Request Interrupt Clear, offset: 0x604E0 */
       uint8_t RESERVED_451[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR; /**< RX Rate Change Interrupt Clear, offset: 0x604E4 */
       uint8_t RESERVED_452[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR; /**< RX P-State Change Interrupt Clear, offset: 0x604E8 */
       uint8_t RESERVED_453[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR; /**< RX Adaptation Request Interrupt Clear, offset: 0x604EC */
       uint8_t RESERVED_454[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR; /**< RX Adaptation Disable Interrupt Clear, offset: 0x604F0 */
       uint8_t RESERVED_455[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_IRQ_MASK;     /**< Interrupt Mask, offset: 0x604F4 */
       uint8_t RESERVED_456[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ; /**< MPLLA/B Re-Calibration Interrupt, offset: 0x604F8 */
       uint8_t RESERVED_457[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_CLR; /**< MPLL Re-Calibration Interrupt Clear, offset: 0x604FC */
       uint8_t RESERVED_458[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ;    /**< RX IQ Interrupt, offset: 0x60500 */
       uint8_t RESERVED_459[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_CLR; /**< RX IQ Interrupt Clear, offset: 0x60504 */
       uint8_t RESERVED_460[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN;  /**< Override Values for Incoming LANE Controls, offset: 0x60508 */
       uint8_t RESERVED_461[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT; /**< Override Values for Outgoing LANE Controls, offset: 0x6050C */
       uint8_t RESERVED_462[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN;   /**< Override Values for Incoming SUP Controls from PMA, offset: 0x60510 */
       uint8_t RESERVED_463[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_SUP_PMA_IN;    /**< Current Values for Coming SUP Status Controls from PMA, offset: 0x60514 */
       uint8_t RESERVED_464[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT;   /**< Override Values for Outgoing TX Controls to PMA, offset: 0x60518 */
       uint8_t RESERVED_465[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_TX_PMA_IN;     /**< Current Values for Coming TX Status Controls from PMA, offset: 0x6051C */
       uint8_t RESERVED_466[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT;   /**< Override Values for Outgoing RX Controls to PMA, offset: 0x60520 */
       uint8_t RESERVED_467[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_RX_PMA_IN;     /**< Current Values for coming RX Status Controls from PMA, offset: 0x60524 */
       uint8_t RESERVED_468[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL; /**< Lane Rtune Controls, offset: 0x60528 */
       uint8_t RESERVED_469[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_RX_OVRD_IN;    /**< Override Values for Incoming RX Controls from PMA, offset: 0x6052C */
       uint8_t RESERVED_470[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_SRAM_REC_EN;   /**< SRAM Record Enable, offset: 0x60530 */
       uint8_t RESERVED_471[2];
  __IO uint16_t RAWLANE0_DIG_TX_CTL_TX_FSM_CTL;    /**< TX FSM Control, offset: 0x60534 */
       uint8_t RESERVED_472[2];
  __IO uint16_t RAWLANE0_DIG_TX_CTL_TX_CLK_CTL;    /**< Select Clock to Act as TX Input Clock, offset: 0x60538 */
       uint8_t RESERVED_473[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_FSM_CTL;    /**< RX FSM Control, offset: 0x6053C */
       uint8_t RESERVED_474[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL; /**< RX LOS Mask Control, offset: 0x60540 */
       uint8_t RESERVED_475[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL; /**< RX Data Enable Override Control, offset: 0x60544 */
       uint8_t RESERVED_476[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS; /**< RX Continuous Offset Cancellation Status, offset: 0x60548 */
       uint8_t RESERVED_477[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS; /**< RX Continuous Adaptation Status, offset: 0x6054C */
       uint8_t RESERVED_478[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE; /**< RX Adaptation Mode, offset: 0x60550 */
       uint8_t RESERVED_479[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_RX_ADAPT_SEL;  /**< Select Between Two Banks Adaptation Settings for RX Adaptation, offset: 0x60554 */
       uint8_t RESERVED_480[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT;  /**< RX CDR PPM Drift on RX Clock, offset: 0x60558 */
       uint8_t RESERVED_481[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_RX_CDR_DET_STATUS; /**< RX CDR Detector Status, offset: 0x6055C */
       uint8_t RESERVED_482[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL; /**< Values for Outgoing RX Controls to PMA, offset: 0x60560 */
       uint8_t RESERVED_483[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_RX_PMA_EQ_IQ;  /**< RX PMA Equalization IQ Phase Value, offset: 0x60564 */
       uint8_t RESERVED_484[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN; /**< Enable RX Adapt Mode Override, offset: 0x60568 */
       uint8_t RESERVED_485[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_EN; /**< Enable Using Four Different RX Adaptation Modes, offset: 0x6056C */
       uint8_t RESERVED_486[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_ADAPT_MM_FOM; /**< RX Adaptation Mission-Mode Figure of Merit, offset: 0x60570 */
       uint8_t RESERVED_487[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_ADAPT_STARTUP_FOM; /**< RX Adaptation Startup Figure of Merit (Base Mode or Extended Mode), offset: 0x60574 */
       uint8_t RESERVED_488[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_EVEN; /**< RX Adapted Value of Reference Level for Error Even Slicer, offset: 0x60578 */
       uint8_t RESERVED_489[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_ODD; /**< RX Adapted Value of Reference Level for Error Odd Slicer, offset: 0x6057C */
       uint8_t RESERVED_490[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_RX_PHSADJ_MAP; /**< RX Phase Adjust Mapped Value, offset: 0x60580 */
       uint8_t RESERVED_491[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_DAC_IN_USE; /**< State of the DAC Interface, offset: 0x60584 */
       uint8_t RESERVED_492[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_2;       /**< Adaptation Control 2, offset: 0x60588 */
       uint8_t RESERVED_493[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_3;       /**< Adaptation Control 3, offset: 0x6058C */
       uint8_t RESERVED_494[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_4;       /**< Adaptation Control 4, offset: 0x60590 */
       uint8_t RESERVED_495[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_5;       /**< Adaptation Control 5, offset: 0x60594 */
       uint8_t RESERVED_496[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_6;       /**< Adaptation Control 6, offset: 0x60598 */
       uint8_t RESERVED_497[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_7;       /**< Adaptation Control 7, offset: 0x6059C */
       uint8_t RESERVED_498[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_8;       /**< Adaptation Control 8, offset: 0x605A0 */
       uint8_t RESERVED_499[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_9;       /**< Adaptation Control 9, offset: 0x605A4 */
       uint8_t RESERVED_500[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_10;      /**< Adaptation Control 10, offset: 0x605A8 */
       uint8_t RESERVED_501[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_11;      /**< Adaptation Control 11, offset: 0x605AC */
       uint8_t RESERVED_502[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_12;      /**< Adaptation Control 12, offset: 0x605B0 */
       uint8_t RESERVED_503[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_13;      /**< Adaptation Control 13, offset: 0x605B4 */
       uint8_t RESERVED_504[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_14;      /**< Adaptation Control 14, offset: 0x605B8 */
       uint8_t RESERVED_505[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_15;      /**< Adaptation Control 15, offset: 0x605BC */
       uint8_t RESERVED_506[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_16;      /**< Adaptation Control 16, offset: 0x605C0 */
       uint8_t RESERVED_507[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_17;      /**< Adaptation Control 17, offset: 0x605C4 */
       uint8_t RESERVED_508[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_18;      /**< Adaptation Control 18, offset: 0x605C8 */
       uint8_t RESERVED_509[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_19;      /**< Adaptation Control 19, offset: 0x605CC */
       uint8_t RESERVED_510[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_20;      /**< Adaptation Control 20, offset: 0x605D0 */
       uint8_t RESERVED_511[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_21;      /**< Adaptation Control 21, offset: 0x605D4 */
       uint8_t RESERVED_512[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_22;      /**< Adaptation Control 22, offset: 0x605D8 */
       uint8_t RESERVED_513[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_23;      /**< Adaptation Control 23, offset: 0x605DC */
       uint8_t RESERVED_514[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_24;      /**< Adaptation Control 24, offset: 0x605E0 */
       uint8_t RESERVED_515[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_25;      /**< Adaptation Control 25, offset: 0x605E4 */
       uint8_t RESERVED_516[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_26;      /**< Adaptation Control 26, offset: 0x605E8 */
       uint8_t RESERVED_517[2];
  __IO uint16_t RAWLANE0_DIG_AON_SRAM_REC_CTRL;    /**< SRAM Record Control, offset: 0x605EC */
       uint8_t RESERVED_518[2];
  __IO uint16_t RAWLANE0_DIG_AON_SRAM_REC_ADDR;    /**< Current SRAM Recording Address, offset: 0x605F0 */
       uint8_t RESERVED_519[2];
  __IO uint16_t RAWLANE0_DIG_AON_SRAM_REC_ITER;    /**< Current Iteration Count for SRAM Recording, offset: 0x605F4 */
       uint8_t RESERVED_520[6];
  __IO uint16_t RAWLANE0_DIG_AON_RX_IQ_CTL;        /**< RX IQ Adaptation Control 1, offset: 0x605FC */
       uint8_t RESERVED_521[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_IQ_CTL_1;      /**< RX IQ Adaptation Control 2, offset: 0x60600 */
       uint8_t RESERVED_522[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT; /**< RX IQ Adaptation Offset Limit, offset: 0x60604 */
       uint8_t RESERVED_523[129530];
  struct {                                         /* offset: 0x80000, array step: index*0x400, index2*0x80, index3*0x4 */
    __I  uint16_t RAWMEM_D_ROM_CMN_B_R;              /**< Common Memory #0, Bank #0, Reg #0..Common Memory #63, Bank #7, Reg #31, array offset: 0x80000, array step: index*0x400, index2*0x80, index3*0x4 */
         uint8_t RESERVED_0[2];
  } RAWMEM_D_ROM_CMNX_BY_RZ[ENET_PHY_RAWMEM_D_ROM_CMNX_COUNT][ENET_PHY_RAWMEM_D_ROM_CMNX_RAWMEM_D_ROM_CMNX_BY_COUNT][ENET_PHY_RAWMEM_D_ROM_CMNX_RAWMEM_D_ROM_CMNX_BY_RAWMEM_D_ROM_CMNX_BY_RZ_COUNT];
       uint8_t RESERVED_524[65536];
  struct {                                         /* offset: 0xA0000, array step: index*0x400, index2*0x80, index3*0x4 */
    __IO uint16_t RAWMEM_D_RAM_CMN_B_R;              /**< Common Memory #0, Bank #0, Reg #0..Common Memory #63, Bank #7, Reg #31, array offset: 0xA0000, array step: index*0x400, index2*0x80, index3*0x4 */
         uint8_t RESERVED_0[2];
  } RAWMEM_D_RAM_CMNX_BY_RZ[ENET_PHY_RAWMEM_D_RAM_CMNX_COUNT][ENET_PHY_RAWMEM_D_RAM_CMNX_RAWMEM_D_RAM_CMNX_BY_COUNT][ENET_PHY_RAWMEM_D_RAM_CMNX_RAWMEM_D_RAM_CMNX_BY_RAWMEM_D_RAM_CMNX_BY_RZ_COUNT];
} ENET_PHY_Type;

/* ----------------------------------------------------------------------------
   -- ENET_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_Register_Masks ENET_PHY Register Masks
 * @{
 */

/*! @name SUP_DIG_IDCODE_LO - Low 16 Bits of IDCODE */
/*! @{ */

#define ENET_PHY_SUP_DIG_IDCODE_LO_VAL_MASK      (0xFFFFU)
#define ENET_PHY_SUP_DIG_IDCODE_LO_VAL_SHIFT     (0U)
/*! VAL - VAL */
#define ENET_PHY_SUP_DIG_IDCODE_LO_VAL(x)        (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_IDCODE_LO_VAL_SHIFT)) & ENET_PHY_SUP_DIG_IDCODE_LO_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_IDCODE_HI - High 16 Bits of IDCODE */
/*! @{ */

#define ENET_PHY_SUP_DIG_IDCODE_HI_VAL_MASK      (0xFFFFU)
#define ENET_PHY_SUP_DIG_IDCODE_HI_VAL_SHIFT     (0U)
/*! VAL - VAL */
#define ENET_PHY_SUP_DIG_IDCODE_HI_VAL(x)        (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_IDCODE_HI_VAL_SHIFT)) & ENET_PHY_SUP_DIG_IDCODE_HI_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_REFCLK_OVRD_IN - Override Values for Incoming REFCLK and RESET Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_SHIFT (0U)
/*! REF_CLK_EN - Override Value for ref_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_SHIFT (1U)
/*! REF_CLK_DIV2_EN - Override Value for ref_clk_div2_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_MASK (0x4U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_SHIFT (2U)
/*! REF_USE_PAD - Override Value for ref_use_pad
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_SHIFT (3U)
/*! REF_REPEAT_CLK_EN - Override Value for ref_repeat_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_MASK (0x70U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_SHIFT (4U)
/*! REF_CLK_RANGE - Override Value for ref_range */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_VPH_NOMINAL_MASK (0x180U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_VPH_NOMINAL_SHIFT (7U)
/*! VPH_NOMINAL - Override Value for vph_nominal */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_VPH_NOMINAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_VPH_NOMINAL_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_VPH_NOMINAL_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_BG_EN_MASK (0x400U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_BG_EN_SHIFT (10U)
/*! BG_EN - Override Value for bg_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_BG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_BG_EN_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_BG_EN_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLKDET_EN_MASK (0x800U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLKDET_EN_SHIFT (11U)
/*! REF_CLKDET_EN - Override Value for ref_clkdet_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLKDET_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLKDET_EN_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_REF_CLKDET_EN_MASK)

#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_OVRD_EN_MASK (0x1000U)
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_OVRD_EN_SHIFT (12U)
/*! OVRD_EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_REFCLK_OVRD_IN_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN - Override Values for Incoming MPLLA_B_DIV_CLK Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_SHIFT (0U)
/*! MPLLA_DIV_CLK_EN - Override Value for mplla_div_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_MASK (0xFEU)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_SHIFT (1U)
/*! MPLLA_DIV_MULTIPLIER - Override Value for mplla_div_multiplier */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_SHIFT (8U)
/*! MPLLB_DIV_CLK_EN - Override Value for mpllb_div_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_MASK (0xFE00U)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_SHIFT (9U)
/*! MPLLB_DIV_MULTIPLIER - Override Value for mpllb_div_multiplier */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_MASK)
/*! @} */

/*! @name SUP_DIG_SUP_OVRD_IN_0 - Override Values for Support Block ASIC Inputs 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_REQ_MASK (0x1U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_REQ_SHIFT (0U)
/*! RTUNE_REQ - Override Value for rtune_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_REQ_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_REQ_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_OVRD_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_OVRD_EN_SHIFT (1U)
/*! RTUNE_OVRD_EN - Enable override of rtune_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RTUNE_OVRD_EN_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_REQ_IN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_REQ_IN_SHIFT (2U)
/*! RES_REQ_IN - Override Value for res_req_in
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_REQ_IN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_REQ_IN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_REQ_IN_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_ACK_IN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_ACK_IN_SHIFT (3U)
/*! RES_ACK_IN - Override Value for res_ack_in
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_ACK_IN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_ACK_IN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_ACK_IN_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_OVRD_EN_MASK (0x10U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_OVRD_EN_SHIFT (4U)
/*! RES_OVRD_EN - Enable override of res_req_in and res_ack_in
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_0_RES_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_SUP_OVRD_IN_1 - Override Values for Support Block ASIC Inputs 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_SHIFT (0U)
/*! TXUP_TERM_OFFSET - Offset value for TXUP termination */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_OVRD_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_OVRD_EN_SHIFT (9U)
/*! TXUP_TERM_OFFSET_OVRD_EN - Offset enable for TXUP termination
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_TXUP_TERM_OFFSET_OVRD_EN_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_MASK (0x7C00U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_SHIFT (10U)
/*! RX_TERM_OFFSET - Offset value for RX termination */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_SHIFT (15U)
/*! RX_TERM_OFFSET_OVRD_EN - Offset enable for RX termination
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_SUP_OVRD_IN_2 - Override Values for Support Block ASIC Inputs 2 */
/*! @{ */

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_SHIFT (0U)
/*! TXDN_TERM_OFFSET - Offset value for TXDN termination */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_OVRD_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_OVRD_EN_SHIFT (9U)
/*! TXDN_TERM_OFFSET_OVRD_EN - Offset enable for TXDN termination
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_IN_2_TXDN_TERM_OFFSET_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_SUP_OVRD_OUT - Override Values for Support Block ASIC Outputs */
/*! @{ */

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_MASK (0x1U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_SHIFT (0U)
/*! RTUNE_ACK - Override Value for rtune_ack output
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_MASK (0x2U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_SHIFT (1U)
/*! RES_REQ_OUT - Override Value for res_req_out output
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_MASK (0x4U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_SHIFT (2U)
/*! RES_ACK_OUT - Override Value for res_ack_out output
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_MASK (0x8U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_SHIFT (3U)
/*! MPLLA_STATE - Override Value for mplla_state output
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_MASK (0x10U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_SHIFT (4U)
/*! MPLLB_STATE - Override Value for mpllb_state output
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_OVRD_EN_MASK (0x20U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_OVRD_EN_SHIFT (5U)
/*! OVRD_EN - Enable override values for all outputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_OVRD_EN_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_MASK (0x40U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_SHIFT (6U)
/*! BG_LANE_STATE_OVRD - Override Value for bg_lane_state signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_OVRD_EN_MASK (0x80U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_OVRD_EN_SHIFT (7U)
/*! BG_LANE_OVRD_EN - Enable override value for bg_lane_state signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_LANE_OVRD_EN_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_MASK (0x100U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_SHIFT (8U)
/*! BG_SUP_STATE_OVRD - Override Value for bg_sup_state signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_OVRD_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_OVRD_EN_SHIFT (9U)
/*! BG_SUP_OVRD_EN - Enable override value for bg_sup_state signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_OUT_BG_SUP_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_LVL_OVRD_IN - Override Values for Level Settings */
/*! @{ */

#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_MASK (0x1FU)
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_SHIFT (0U)
/*! RX_VREF_CTRL - Override Value for rx_vref_ctrl */
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_SHIFT)) & ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_MASK)

#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_MASK (0x20U)
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_SHIFT (5U)
/*! RX_VREF_CTRL_EN - Enable override value for rx_vref_ctrl
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_SHIFT)) & ENET_PHY_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_MASK)

#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_MASK (0x1C0U)
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_SHIFT (6U)
/*! TX_VBOOST_LVL - Override Value for tx_vboost_lvl */
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_SHIFT)) & ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_MASK)

#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_SHIFT (9U)
/*! TX_VBOOST_LVL_EN - Enable override value for tx_vboost_lvl
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_SHIFT)) & ENET_PHY_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_MASK)
/*! @} */

/*! @name SUP_DIG_DEBUG - Debug Controls */
/*! @{ */

#define ENET_PHY_SUP_DIG_DEBUG_DTB_SEL_MASK      (0x7U)
#define ENET_PHY_SUP_DIG_DEBUG_DTB_SEL_SHIFT     (0U)
/*! DTB_SEL - The lane DTB's are OR'd together with the support DTB signals selected with the below encodings.
 *  0b000..None
 *  0b001..MPLLA DTB output
 *  0b010..MPLLB DTB output
 *  0b011..RTUNE DTB output
 */
#define ENET_PHY_SUP_DIG_DEBUG_DTB_SEL(x)        (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_DEBUG_DTB_SEL_SHIFT)) & ENET_PHY_SUP_DIG_DEBUG_DTB_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN - Current Values for Incoming MPLLA_B_DIV_CLK Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_SHIFT (0U)
/*! MPLLA_DIV_CLK_EN - Value from mplla_div_clk_en */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_MASK (0xFEU)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_SHIFT (1U)
/*! MPLLA_DIV_MULTIPLIER - Value from mplla_div_multiplier */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_SHIFT (8U)
/*! MPLLB_DIV_CLK_EN - Value from mpllb_div_clk_en */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_MASK (0xFE00U)
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_SHIFT (9U)
/*! MPLLB_DIV_MULTIPLIER - Value from mpllb_div_multiplier */
#define ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_B_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_MASK)
/*! @} */

/*! @name SUP_DIG_ASIC_IN - Current Values for Incoming SUP Control Signals from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_ASIC_IN_PHY_RESET_MASK  (0x1U)
#define ENET_PHY_SUP_DIG_ASIC_IN_PHY_RESET_SHIFT (0U)
/*! PHY_RESET - Value from ASIC for phy_reset */
#define ENET_PHY_SUP_DIG_ASIC_IN_PHY_RESET(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_PHY_RESET_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_PHY_RESET_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_EN_SHIFT (1U)
/*! REF_CLK_EN - Value from ASIC for ref_clk_en */
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_EN(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_SHIFT (2U)
/*! REF_CLK_DIV2_EN - Value from ASIC for ref_clk_div2_en */
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_SHIFT (3U)
/*! REF_REPEAT_CLK_EN - Value from ASIC for ref_repeat_clk_en */
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_REF_USE_PAD_MASK (0x10U)
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_USE_PAD_SHIFT (4U)
/*! REF_USE_PAD - Value from ASIC for ref_use_pad */
#define ENET_PHY_SUP_DIG_ASIC_IN_REF_USE_PAD(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_REF_USE_PAD_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_REF_USE_PAD_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_TEST_BURNIN_MASK (0x20U)
#define ENET_PHY_SUP_DIG_ASIC_IN_TEST_BURNIN_SHIFT (5U)
/*! TEST_BURNIN - Value from ASIC for test_burnin */
#define ENET_PHY_SUP_DIG_ASIC_IN_TEST_BURNIN(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_TEST_BURNIN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_TEST_BURNIN_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_TEST_POWERDOWN_MASK (0x40U)
#define ENET_PHY_SUP_DIG_ASIC_IN_TEST_POWERDOWN_SHIFT (6U)
/*! TEST_POWERDOWN - Value from ASIC for test_powerdown */
#define ENET_PHY_SUP_DIG_ASIC_IN_TEST_POWERDOWN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_TEST_POWERDOWN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_TEST_POWERDOWN_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_REQ_MASK  (0x80U)
#define ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_REQ_SHIFT (7U)
/*! RTUNE_REQ - Value from ASIC for rtune_req */
#define ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_REQ(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_REQ_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_REQ_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_ACK_MASK  (0x100U)
#define ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_ACK_SHIFT (8U)
/*! RTUNE_ACK - Value to ASIC for rtune_ack_i */
#define ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_ACK(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_ACK_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_RTUNE_ACK_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_IN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_IN_SHIFT (9U)
/*! RES_REQ_IN - Value from ASIC for res_req_in */
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_IN(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_IN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_IN_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_OUT_MASK (0x400U)
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_OUT_SHIFT (10U)
/*! RES_REQ_OUT - Value to ASIC for res_ack_out_i */
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_OUT(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_OUT_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_RES_REQ_OUT_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_IN_MASK (0x800U)
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_IN_SHIFT (11U)
/*! RES_ACK_IN - Value from ASIC for res_req_in */
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_IN(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_IN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_IN_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_OUT_MASK (0x1000U)
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_OUT_SHIFT (12U)
/*! RES_ACK_OUT - Value to ASIC for res_ack_out_i */
#define ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_OUT(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_OUT_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_RES_ACK_OUT_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_MPLLA_STATE_MASK (0x2000U)
#define ENET_PHY_SUP_DIG_ASIC_IN_MPLLA_STATE_SHIFT (13U)
/*! MPLLA_STATE - Value to ASIC for mplla_state_i */
#define ENET_PHY_SUP_DIG_ASIC_IN_MPLLA_STATE(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_MPLLA_STATE_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_MPLLA_STATE_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_MPLLB_STATE_MASK (0x4000U)
#define ENET_PHY_SUP_DIG_ASIC_IN_MPLLB_STATE_SHIFT (14U)
/*! MPLLB_STATE - Value to ASIC for mpllb_state_i */
#define ENET_PHY_SUP_DIG_ASIC_IN_MPLLB_STATE(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_MPLLB_STATE_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_MPLLB_STATE_MASK)

#define ENET_PHY_SUP_DIG_ASIC_IN_BG_EN_MASK      (0x8000U)
#define ENET_PHY_SUP_DIG_ASIC_IN_BG_EN_SHIFT     (15U)
/*! BG_EN - Value from ASIC for bg_en */
#define ENET_PHY_SUP_DIG_ASIC_IN_BG_EN(x)        (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ASIC_IN_BG_EN_SHIFT)) & ENET_PHY_SUP_DIG_ASIC_IN_BG_EN_MASK)
/*! @} */

/*! @name SUP_DIG_LVL_ASIC_IN - Current Values for Incoming Level Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_MASK (0x1FU)
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_SHIFT (0U)
/*! RX_VREF_CTRL - Value from ASIC for rx_vref_ctrl */
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_SHIFT)) & ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_MASK)

#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_MASK (0xE0U)
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_SHIFT (5U)
/*! TX_VBOOST_LVL - Value from ASIC for tx_vboost_lvl */
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_SHIFT)) & ENET_PHY_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_MASK)

#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_RESULT_MASK (0x100U)
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_RESULT_SHIFT (8U)
/*! REF_CLKDET_RESULT - Value from ASIC for ref_clkdet_result */
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_RESULT_SHIFT)) & ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_RESULT_MASK)

#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_EN_SHIFT (9U)
/*! REF_CLKDET_EN - Value from ASIC for ref_clkdet_en */
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_EN_SHIFT)) & ENET_PHY_SUP_DIG_LVL_ASIC_IN_REF_CLKDET_EN_MASK)

#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_TERM_OFFSET_MASK (0x7C00U)
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_TERM_OFFSET_SHIFT (10U)
/*! RX_TERM_OFFSET - Value from ASIC for */
#define ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_TERM_OFFSET_SHIFT)) & ENET_PHY_SUP_DIG_LVL_ASIC_IN_RX_TERM_OFFSET_MASK)
/*! @} */

/*! @name SUP_DIG_SUP_OVRD_MISC - Override Values for Incoming SUP MISC BUS from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_VAL_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_VAL_SHIFT (0U)
/*! SUP_MISC_OVRD_VAL - Override Value for sup_misc[7:0] */
#define ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_VAL_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_VAL_MASK)

#define ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_EN_SHIFT (8U)
/*! SUP_MISC_OVRD_EN - Override Enable for sup_misc[7:0]
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_SUP_OVRD_MISC_SUP_MISC_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_CLK_RST_BG_PWRUP_TIME_0 - BG Power UP Time 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_SHIFT (0U)
/*! BG_SUP_EN_TIME - Power up time (in ref_range cycles) for bandgap in SUP (spec >= 5 us) */
#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_SHIFT)) & ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_MASK)

#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_MASK (0x200U)
#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_SHIFT (9U)
/*! FAST_BG_WAIT - Enable fast BG times (simulation only)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_SHIFT)) & ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_MASK)
/*! @} */

/*! @name SUP_DIG_CLK_RST_BG_PWRUP_TIME_1 - BG Power UP Time 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_SHIFT (0U)
/*! BG_LANE_EN_TIME - Power up time (in ref_range cycles) for bandgap in LANE (spec >= 5 us) */
#define ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_SHIFT)) & ENET_PHY_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_MASK)
/*! @} */

/*! @name SUP_ANA_RTUNE_CTRL - RTUNE_CTRL */
/*! @{ */

#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_chop_MASK (0x8U)
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_chop_SHIFT (3U)
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_chop(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_chop_SHIFT)) & ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_chop_MASK)

#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_mode_MASK (0x30U)
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_mode_SHIFT (4U)
/*! rt_dac_mode - Margin DAC Mode Control */
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_mode(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_mode_SHIFT)) & ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_dac_mode_MASK)

#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_ibias_1p5x_MASK (0x40U)
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_ibias_1p5x_SHIFT (6U)
/*! rt_ibias_1p5x - Increase Bias Current */
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_ibias_1p5x(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_ibias_1p5x_SHIFT)) & ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_ibias_1p5x_MASK)

#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_en_frcon_MASK (0x80U)
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_en_frcon_SHIFT (7U)
/*! rt_en_frcon - Local Rtune Block Enable Control */
#define ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_en_frcon(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_en_frcon_SHIFT)) & ENET_PHY_SUP_ANA_RTUNE_CTRL_rt_en_frcon_MASK)
/*! @} */

/*! @name SUP_ANA_SWITCH_PWR_MEAS - SWITCH_PWR_MEAS */
/*! @{ */

#define ENET_PHY_SUP_ANA_SWITCH_PWR_MEAS_temp_meas_MASK (0x80U)
#define ENET_PHY_SUP_ANA_SWITCH_PWR_MEAS_temp_meas_SHIFT (7U)
/*! temp_meas - Measure bandgap's PNP diode voltage (temperature)
 *  0b0..Doesn't measure
 *  0b1..Measures
 */
#define ENET_PHY_SUP_ANA_SWITCH_PWR_MEAS_temp_meas(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_SWITCH_PWR_MEAS_temp_meas_SHIFT)) & ENET_PHY_SUP_ANA_SWITCH_PWR_MEAS_temp_meas_MASK)
/*! @} */

/*! @name SUP_ANA_SWITCH_MISC_MEAS - SWITCH_MISC_MEAS */
/*! @{ */

#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_MASK (0x3U)
#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_SHIFT (0U)
/*! hyst_ref - Sets Prescaler Input Buffer Hysteresis
 *  0b00..No hysteresis
 *  0b01..18 mVpp hysteresis
 *  0b10..35 mVpp hysteresis
 *  0b11..50 mVpp hysteresis
 */
#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_SHIFT)) & ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_MASK)

#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p5_MASK (0x1CU)
#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p5_SHIFT (2U)
/*! vref_sel_slowreg_vph1p5 - Sets value of slowreg_vref for VPH=1.5 or 1.8 V
 *  0b000..300 mV
 *  0b001..325 mV
 *  0b010..350 mV
 *  0b011..375 mV
 *  0b100..400 mV
 *  0b101..425 mV
 *  0b110..450 mV
 *  0b111..475 mV
 */
#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p5_SHIFT)) & ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p5_MASK)

#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p2_MASK (0xE0U)
#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p2_SHIFT (5U)
/*! vref_sel_slowreg_vph1p2 - Sets value of slowreg_vref for VPH=1.2 V
 *  0b000..300 mV
 *  0b001..325 mV
 *  0b010..350 mV
 *  0b011..375 mV
 *  0b100..400 mV
 *  0b101..425 mV
 *  0b110..450 mV
 *  0b111..475 mV
 */
#define ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p2_SHIFT)) & ENET_PHY_SUP_ANA_SWITCH_MISC_MEAS_vref_sel_slowreg_vph1p2_MASK)
/*! @} */

/*! @name SUP_ANA_BG - BG */
/*! @{ */

#define ENET_PHY_SUP_ANA_BG_bypass_bg_MASK       (0x1U)
#define ENET_PHY_SUP_ANA_BG_bypass_bg_SHIFT      (0U)
/*! bypass_bg - Bypass Bandgap with VP
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define ENET_PHY_SUP_ANA_BG_bypass_bg(x)         (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_BG_bypass_bg_SHIFT)) & ENET_PHY_SUP_ANA_BG_bypass_bg_MASK)

#define ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p5_MASK (0x6U)
#define ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p5_SHIFT (1U)
/*! vref_sel_fastreg_vph1p5 - Sets value of fastreg_vref for VPH=1.5 or 1.8 V
 *  0b00..525 mV
 *  0b01..550 mV
 *  0b10..575 mV
 *  0b11..600 mV
 */
#define ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p5_SHIFT)) & ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p5_MASK)

#define ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p2_MASK (0x18U)
#define ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p2_SHIFT (3U)
/*! vref_sel_fastreg_vph1p2 - Sets value of fastreg_vref for VPH=1.2 V
 *  0b00..525 mV
 *  0b01..550 mV
 *  0b10..575 mV
 *  0b11..600 mV
 */
#define ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p2_SHIFT)) & ENET_PHY_SUP_ANA_BG_vref_sel_fastreg_vph1p2_MASK)

#define ENET_PHY_SUP_ANA_BG_chop_en_int_MASK     (0x20U)
#define ENET_PHY_SUP_ANA_BG_chop_en_int_SHIFT    (5U)
/*! chop_en_int - Enable chopper clock for bandgap
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_BG_chop_en_int(x)       (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_BG_chop_en_int_SHIFT)) & ENET_PHY_SUP_ANA_BG_chop_en_int_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_DEBUG - Resistor Tuning Debug Controls */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_MASK (0x1U)
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_SHIFT (0U)
/*! FLIP_COMP - Invert Analog Comparator Output
 *  0b0..No invert
 *  0b1..Invert
 */
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_FLIP_COMP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_MASK)

#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_MASK (0x2U)
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_SHIFT (1U)
/*! MAN_TUNE - Write to a 1 to do a manual tuning specified by TYPE field starting a manual tune
 *    while a tune is currently running can cause unpredictable results. For use only when you know
 *    what the part is doing (w.r.t. resistor tuning)
 */
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_MAN_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_MASK)

#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_SET_VAL_MASK (0x4U)
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_SET_VAL_SHIFT (2U)
/*! SET_VAL - Set value Write to a 1 to manually write the register specified by the TYPE field to the value in the VALUE field
 *  0b0..Not set
 *  0b1..Set
 */
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_SET_VAL(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_DEBUG_SET_VAL_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_DEBUG_SET_VAL_MASK)

#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_TYPE_MASK   (0x18U)
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_TYPE_SHIFT  (3U)
/*! TYPE - Type of manual tuning or register read/write to execute 0 - ADC, or read/write rt_value
 *  0b01..RX tune, or read/write rx_cal_val (only 6 bits)
 *  0b10..TX-DN tune, or read/write txdn_cal_val (10 bits)
 *  0b11..TX-UP tune, or read/write txup_cal_val (10 bits) or Resref detect (no affect when triggering SET_VAL field)
 */
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_TYPE(x)     (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_DEBUG_TYPE_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_DEBUG_TYPE_MASK)

#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_VALUE_MASK  (0x7FE0U)
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_VALUE_SHIFT (5U)
/*! VALUE - Value to use when triggering SET_VAL field only the 6 LSB's are used when setting RX or TX cal values */
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_VALUE(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_DEBUG_VALUE_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_DEBUG_VALUE_MASK)

#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_TXUP_GO_MASK (0x8000U)
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_TXUP_GO_SHIFT (15U)
/*! TXUP_GO - Enable TX-UP tune to continue in manual tune mode when TYPE is TX-UP tune
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_RTUNE_DEBUG_TXUP_GO(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_DEBUG_TXUP_GO_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_DEBUG_TXUP_GO_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_CONFIG - Configure Rtune Operation */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_CONFIG_SKIP_RX_CAL_MASK (0x1U)
#define ENET_PHY_SUP_DIG_RTUNE_CONFIG_SKIP_RX_CAL_SHIFT (0U)
/*! SKIP_RX_CAL - Skip Calibration of RX Resistor
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_SUP_DIG_RTUNE_CONFIG_SKIP_RX_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_CONFIG_SKIP_RX_CAL_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_CONFIG_SKIP_RX_CAL_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_STAT - Resistor Tuning Register Status */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_STAT_STAT_MASK    (0x3FFU)
#define ENET_PHY_SUP_DIG_RTUNE_STAT_STAT_SHIFT   (0U)
/*! STAT - Current value of the register specified by the DEBUG.TYPE field */
#define ENET_PHY_SUP_DIG_RTUNE_STAT_STAT(x)      (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_STAT_STAT_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_STAT_STAT_MASK)

#define ENET_PHY_SUP_DIG_RTUNE_STAT_DTB_RTUNE_MASK (0xC00U)
#define ENET_PHY_SUP_DIG_RTUNE_STAT_DTB_RTUNE_SHIFT (10U)
/*! DTB_RTUNE - DTB Sampling for Rtune */
#define ENET_PHY_SUP_DIG_RTUNE_STAT_DTB_RTUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_STAT_DTB_RTUNE_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_STAT_DTB_RTUNE_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_RX_SET_VAL - Set Value of RX Resistor */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_MASK (0x3FU)
#define ENET_PHY_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_SHIFT (0U)
/*! RX_SET_VAL - Set Value of RX Resistor */
#define ENET_PHY_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXDN_SET_VAL - Set Value of TX-DN Resistor */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_MASK (0x3FFU)
#define ENET_PHY_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_SHIFT (0U)
/*! TXDN_SET_VAL - Set Value of TX-DN Resistor */
#define ENET_PHY_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXUP_SET_VAL - Set Value of TX-UP Resistor */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_MASK (0x3FFU)
#define ENET_PHY_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_SHIFT (0U)
/*! TXUP_SET_VAL - Set Value of TX-UP Resistor */
#define ENET_PHY_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_RX_STAT - RX Resistor Tuning Register Status */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_RX_STAT_RX_STAT_MASK (0x3FU)
#define ENET_PHY_SUP_DIG_RTUNE_RX_STAT_RX_STAT_SHIFT (0U)
/*! RX_STAT - Current value of the RX resistor tuning register */
#define ENET_PHY_SUP_DIG_RTUNE_RX_STAT_RX_STAT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_RX_STAT_RX_STAT_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_RX_STAT_RX_STAT_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXDN_STAT - TX-DN Resistor Tuning Register Status */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_MASK (0x3FFU)
#define ENET_PHY_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_SHIFT (0U)
/*! TXDN_STAT - Current value of the TX-DN resistor tuning register */
#define ENET_PHY_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXUP_STAT - TX-UP Resistor Tuning Register Status */
/*! @{ */

#define ENET_PHY_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_MASK (0x3FFU)
#define ENET_PHY_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_SHIFT (0U)
/*! TXUP_STAT - Current value of the TX-UP resistor tuning register */
#define ENET_PHY_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_SHIFT)) & ENET_PHY_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_RTUNE_OVRD_OUT - Override Value for RTUNE Signals Going to ANA */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_MASK (0x1U)
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_SHIFT (0U)
/*! RTUNE_COMP_RST - Overrides the rt_ana_comp_rst signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_SHIFT)) & ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_MASK)

#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_MASK (0x6U)
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_SHIFT (1U)
/*! RTUNE_MODE - Overrides the rt_ana_mode[1:0] signal */
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_SHIFT)) & ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_MASK)

#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_SHIFT (3U)
/*! RTUNE_EN - Overrides the rt_ana_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_MASK (0x3FF0U)
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_SHIFT (4U)
/*! RTUNE_VALUE - Overrides the rt_ana_value[9:0] signal */
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_SHIFT)) & ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_MASK)

#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_SHIFT (14U)
/*! RTUNE_OVRD_EN - Override bit for rtune (rt_ana_* and term) outputs
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_RX_TERM_OVRD_OUT - Override Value for RX Termination Signals Going to ANA */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_RX_TERM_OVRD_OUT_RX_TERM_VAL_MASK (0x3FU)
#define ENET_PHY_SUP_DIG_ANA_RX_TERM_OVRD_OUT_RX_TERM_VAL_SHIFT (0U)
/*! RX_TERM_VAL - Overrides the rx_ana_term_val[5:0] signal */
#define ENET_PHY_SUP_DIG_ANA_RX_TERM_OVRD_OUT_RX_TERM_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_RX_TERM_OVRD_OUT_RX_TERM_VAL_SHIFT)) & ENET_PHY_SUP_DIG_ANA_RX_TERM_OVRD_OUT_RX_TERM_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_STAT - SUP Input Status Register for SUP ANA Outputs */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_MASK (0x1U)
#define ENET_PHY_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_SHIFT (0U)
/*! RT_ANA_COMP_RESULT - Value from ANA for rt_ana_comp_result */
#define ENET_PHY_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_SHIFT)) & ENET_PHY_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_MASK)

#define ENET_PHY_SUP_DIG_ANA_STAT_REF_ANA_CLKDET_RESULT_MASK (0x2U)
#define ENET_PHY_SUP_DIG_ANA_STAT_REF_ANA_CLKDET_RESULT_SHIFT (1U)
/*! REF_ANA_CLKDET_RESULT - Value from ANA for ref_ana_clkdet_result */
#define ENET_PHY_SUP_DIG_ANA_STAT_REF_ANA_CLKDET_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_STAT_REF_ANA_CLKDET_RESULT_SHIFT)) & ENET_PHY_SUP_DIG_ANA_STAT_REF_ANA_CLKDET_RESULT_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_BG_OVRD_OUT - Override Values for Bandgap Signals Going to ANA */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_FAST_START_MASK (0x1U)
#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_FAST_START_SHIFT (0U)
/*! BG_FAST_START - Overrides the bg_ana_vref_fast_start signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_FAST_START(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_FAST_START_SHIFT)) & ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_FAST_START_MASK)

#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_EN_SHIFT (1U)
/*! BG_EN - Overrides the bg_ana_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_OVRD_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_OVRD_EN_SHIFT (2U)
/*! BG_OVRD_EN - Override bit for bandgap outputs
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_BG_OVRD_OUT_BG_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_FREQ_CNT_PEAK_ASIC_IN - Current Values for Incoming Level Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLB_SSC_FREQ_CNT_PEAK_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT (0U)
/*! MPLLB_SSC_FREQ_CNT_PEAK - Value from ASIC for MPLLB_SSC_FREQ_CNT_PEAK */
#define ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLB_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT)) & ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLB_SSC_FREQ_CNT_PEAK_MASK)

#define ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLA_SSC_FREQ_CNT_PEAK_MASK (0xFF00U)
#define ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT (8U)
/*! MPLLA_SSC_FREQ_CNT_PEAK - Value from ASIC for MPLLA_SSC_FREQ_CNT_PEAK */
#define ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLA_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT)) & ENET_PHY_SUP_DIG_FREQ_CNT_PEAK_ASIC_IN_MPLLA_SSC_FREQ_CNT_PEAK_MASK)
/*! @} */

/*! @name SUP_DIG_TXUP_TERM_OFFSET_ASIC_IN - Current Values for Incoming Level Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_TXUP_TERM_OFFSET_ASIC_IN_TXUP_TERM_OFFSET_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_TXUP_TERM_OFFSET_ASIC_IN_TXUP_TERM_OFFSET_SHIFT (0U)
/*! TXUP_TERM_OFFSET - Value from ASIC for txup_term_offset */
#define ENET_PHY_SUP_DIG_TXUP_TERM_OFFSET_ASIC_IN_TXUP_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_TXUP_TERM_OFFSET_ASIC_IN_TXUP_TERM_OFFSET_SHIFT)) & ENET_PHY_SUP_DIG_TXUP_TERM_OFFSET_ASIC_IN_TXUP_TERM_OFFSET_MASK)
/*! @} */

/*! @name SUP_DIG_TXDN_TERM_OFFSET_ASIC_IN - Current Values for Incoming Level Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_TXDN_TERM_OFFSET_ASIC_IN_TXDN_TERM_OFFSET_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_TXDN_TERM_OFFSET_ASIC_IN_TXDN_TERM_OFFSET_SHIFT (0U)
/*! TXDN_TERM_OFFSET - Value from ASIC for txup_term_offset */
#define ENET_PHY_SUP_DIG_TXDN_TERM_OFFSET_ASIC_IN_TXDN_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_TXDN_TERM_OFFSET_ASIC_IN_TXDN_TERM_OFFSET_SHIFT)) & ENET_PHY_SUP_DIG_TXDN_TERM_OFFSET_ASIC_IN_TXDN_TERM_OFFSET_MASK)
/*! @} */

/*! @name SUP_DIG_MISC_ASIC_IN - Current Values for Incoming Level Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_SUP_MISC_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_SUP_MISC_SHIFT (0U)
/*! SUP_MISC - Value from ASIC for sup_misc */
#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_SUP_MISC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MISC_ASIC_IN_SUP_MISC_SHIFT)) & ENET_PHY_SUP_DIG_MISC_ASIC_IN_SUP_MISC_MASK)

#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_STOP_CLK_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_STOP_CLK_EN_SHIFT (8U)
/*! TEST_STOP_CLK_EN - Value from ASIC for test_stop_clk_en */
#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_STOP_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_STOP_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_STOP_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_FLYOVER_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_FLYOVER_EN_SHIFT (9U)
/*! TEST_FLYOVER_EN - Value from ASIC for test_flyover_en */
#define ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_FLYOVER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_FLYOVER_EN_SHIFT)) & ENET_PHY_SUP_DIG_MISC_ASIC_IN_TEST_FLYOVER_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_CMN_CTL - Common Control */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_SHIFT (0U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_SHIFT)) & ENET_PHY_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_MASK)
/*! @} */

/*! @name RAWCMN_DIG_LANE_FSM_OP_XTND - Lane FSM OP XTND Control */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_LANE_FSM_OP_XTND_VAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_LANE_FSM_OP_XTND_VAL_SHIFT (0U)
/*! VAL - Required when accessing the analog CREGs in firmware to prevent timing violations across ANA-DIG interface */
#define ENET_PHY_RAWCMN_DIG_LANE_FSM_OP_XTND_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_LANE_FSM_OP_XTND_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_LANE_FSM_OP_XTND_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0 - Override Values for Incoming TX Term Offset */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_VAL_MASK (0x1FFU)
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_VAL_SHIFT (0U)
/*! TXUP_TERM_OFFSET_OVRD_VAL - Override Value for txup_term_offset[8:0] */
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_EN_MASK (0x200U)
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_EN_SHIFT (9U)
/*! TXUP_TERM_OFFSET_OVRD_EN - Override Enable for txup_term_offset[8:0]
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_0_TXUP_TERM_OFFSET_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1 - Override Values for Incoming TX/RX Term Offset */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_VAL_MASK (0x1FFU)
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_VAL_SHIFT (0U)
/*! TXDN_TERM_OFFSET_OVRD_VAL - Override Value for txdn_term_offset[8:0] */
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_EN_MASK (0x200U)
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_EN_SHIFT (9U)
/*! TXDN_TERM_OFFSET_OVRD_EN - Override Enable for txdn_term_offset[8:0]
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_TXDN_TERM_OFFSET_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_VAL_MASK (0x7C00U)
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_VAL_SHIFT (10U)
/*! RX_TERM_OFFSET_OVRD_VAL - Override Value for rx_term_offset[4:0] */
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_SHIFT (15U)
/*! RX_TERM_OFFSET_OVRD_EN - Override Enable for rx_term_offset[4:0]
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_TERM_OFFSET_OVRD_IN_1_RX_TERM_OFFSET_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_CMN_CTL_1 - Common Control 1 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_SHIFT (0U)
/*! MPLLA_INIT_CAL_DISABLE_OVRD_VAL - Override Value for mplla_init_cal_disable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_SHIFT (1U)
/*! MPLLA_INIT_CAL_DISABLE_OVRD_EN - Override Enable for mplla_init_cal_disable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_SHIFT (2U)
/*! MPLLB_INIT_CAL_DISABLE_OVRD_VAL - Override Value for mpllb_init_cal_disable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_SHIFT (3U)
/*! MPLLB_INIT_CAL_DISABLE_OVRD_EN - Override Enable for mpllb_init_cal_disable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_MASK (0x10U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_SHIFT (4U)
/*! RTUNE_REQ_OVRD_VAL - Override Value for rtune_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_MASK (0x20U)
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_SHIFT (5U)
/*! RTUNE_REQ_OVRD_EN - Override Enable for rtune_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLL_OFF_TIME - Wait Time for Turning MPLL Off */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLL_OFF_TIME_MPLLA_OFF_TIME_MASK (0x3FU)
#define ENET_PHY_RAWCMN_DIG_MPLL_OFF_TIME_MPLLA_OFF_TIME_SHIFT (0U)
/*! MPLLA_OFF_TIME - Wait counter for turning off MPLL */
#define ENET_PHY_RAWCMN_DIG_MPLL_OFF_TIME_MPLLA_OFF_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_OFF_TIME_MPLLA_OFF_TIME_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_OFF_TIME_MPLLA_OFF_TIME_MASK)
/*! @} */

/*! @name RAWCMN_DIG_ATE_ALU_CTRL - ATE ALU Module Control */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_ATE_ALU_CTRL_ATE_ALU_OPCODE_MASK (0xFU)
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_CTRL_ATE_ALU_OPCODE_SHIFT (0U)
/*! ATE_ALU_OPCODE - OPCode for ATE ALU Module
 *  0b0000..ZERO
 *  0b0001..ADD_RD_DATA
 *  0b0010..ADD_DATA
 *  0b0011..SHL1
 *  0b0100..SHR1
 *  0b0101..ASHR1
 *  0b0110..INV
 *  0b0111..NEG
 *  0b1000..ABS
 *  0b1110..READ
 *  0b1111..WRITE
 */
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_CTRL_ATE_ALU_OPCODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_ATE_ALU_CTRL_ATE_ALU_OPCODE_SHIFT)) & ENET_PHY_RAWCMN_DIG_ATE_ALU_CTRL_ATE_ALU_OPCODE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_ATE_ALU_ADDR - Address for Read and Write Command for ATE ALU Module */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_ATE_ALU_ADDR_ADDR_MASK (0xFFFFU)
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_ADDR_ADDR_SHIFT (0U)
/*! ADDR - Address for read and write command for ATE ALU module */
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_ADDR_ADDR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_ATE_ALU_ADDR_ADDR_SHIFT)) & ENET_PHY_RAWCMN_DIG_ATE_ALU_ADDR_ADDR_MASK)
/*! @} */

/*! @name RAWCMN_DIG_ATE_ALU_DATA - Data for Write Command for ATE ALU Module */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_ATE_ALU_DATA_DATA_MASK (0xFFFFU)
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_DATA_DATA_SHIFT (0U)
/*! DATA - Data for read and write command for ATE ALU module */
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_DATA_DATA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_ATE_ALU_DATA_DATA_SHIFT)) & ENET_PHY_RAWCMN_DIG_ATE_ALU_DATA_DATA_MASK)
/*! @} */

/*! @name RAWCMN_DIG_ATE_ALU_FLAGS - Flags from ATE ALU Module */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_ATE_ALU_FLAGS_ATE_ALU_ACCUM_SIGN_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_FLAGS_ATE_ALU_ACCUM_SIGN_SHIFT (0U)
/*! ATE_ALU_ACCUM_SIGN - Indicate the sign of the accumulator in ATE ALU */
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_FLAGS_ATE_ALU_ACCUM_SIGN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_ATE_ALU_FLAGS_ATE_ALU_ACCUM_SIGN_SHIFT)) & ENET_PHY_RAWCMN_DIG_ATE_ALU_FLAGS_ATE_ALU_ACCUM_SIGN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_ATE_ALU_ACCUM - Stores the ATE ALU Accumulator Result */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_ATE_ALU_ACCUM_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_ACCUM_VAL_SHIFT (0U)
/*! VAL - Stores the ATE ALU accumulator result */
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_ACCUM_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_ATE_ALU_ACCUM_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_ATE_ALU_ACCUM_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLL_IN - Current Values for Incoming MPLL Controls from PCS (Pre-Override Input Monitor) */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLA_INIT_CAL_DISABLE_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLA_INIT_CAL_DISABLE_SHIFT (0U)
/*! MPLLA_INIT_CAL_DISABLE - Value from PCS for mplla_init_cal_disable */
#define ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLA_INIT_CAL_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLA_INIT_CAL_DISABLE_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLA_INIT_CAL_DISABLE_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLB_INIT_CAL_DISABLE_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLB_INIT_CAL_DISABLE_SHIFT (1U)
/*! MPLLB_INIT_CAL_DISABLE - Value from PCS for mpllb_init_cal_disable */
#define ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLB_INIT_CAL_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLB_INIT_CAL_DISABLE_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_IN_MPLLB_INIT_CAL_DISABLE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_FW_PWRUP_DONE - Firmware Power-up Done Status */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_FW_PWRUP_DONE_DONE_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_FW_PWRUP_DONE_DONE_SHIFT (0U)
/*! DONE - Firmware power-up status for phy_reset and pg_reset */
#define ENET_PHY_RAWCMN_DIG_FW_PWRUP_DONE_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_FW_PWRUP_DONE_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_FW_PWRUP_DONE_DONE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLL_CLK_ASYNC_EN - MPLL Output Clocks Asynchronous Control */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLA_CLK_EN_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLA_CLK_EN_SHIFT (0U)
/*! MPLLA_CLK_EN - MPLLA Output Clocks Asynchronous Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLA_CLK_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLA_CLK_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLB_CLK_EN_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLB_CLK_EN_SHIFT (1U)
/*! MPLLB_CLK_EN - MPLLB Output Clocks Asynchronous Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLB_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLB_CLK_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_CLK_ASYNC_EN_MPLLB_CLK_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_ATE_ALU_SPARE_0 - Spare Register 1 for ATE ALU Operations */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_0_DATA_MASK (0xFFFFU)
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_0_DATA_SHIFT (0U)
/*! DATA - Spare for ATE ALU operations */
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_0_DATA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_0_DATA_SHIFT)) & ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_0_DATA_MASK)
/*! @} */

/*! @name RAWCMN_DIG_ATE_ALU_SPARE_1 - Spare Register 2 for ATE ALU Operations */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_1_DATA_MASK (0xFFFFU)
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_1_DATA_SHIFT (0U)
/*! DATA - Spare for ATE ALU operations */
#define ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_1_DATA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_1_DATA_SHIFT)) & ENET_PHY_RAWCMN_DIG_ATE_ALU_SPARE_1_DATA_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLL_STATE_OVRD_IN - Override for MPLLA/B State Outputs */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_VAL_SHIFT (0U)
/*! MPLLA_STATE_OVRD_VAL - Override Value for mplla_state
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_EN_SHIFT (1U)
/*! MPLLA_STATE_OVRD_EN - Override Enable for mplla_state
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLA_STATE_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_VAL_SHIFT (2U)
/*! MPLLB_STATE_OVRD_VAL - Override Value for mpllb_state
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_EN_SHIFT (3U)
/*! MPLLB_STATE_OVRD_EN - Override Enable for mpllb_state
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLL_STATE_OVRD_IN_MPLLB_STATE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_SRAM_PGATE_BL_EN - Enable SRAM Bootloader on Power-Gated Exit */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_SHIFT (0U)
/*! SRAM_PGATE_BL_EN - Enable SRAM bootloader on power-gated exit
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD - Override Incoming MPLLA/B_RECAL_BANK_SEL Input */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_VAL_MASK (0x3U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_VAL_SHIFT (0U)
/*! MPLLA_CAL_BANK_SEL_OVRD_VAL - Override Value for incoming input mplla_recal_bank_sel */
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_EN_MASK (0x4U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_EN_SHIFT (2U)
/*! MPLLA_CAL_BANK_SEL_OVRD_EN - Enable Override for mplla_recal_bank_sel
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLA_CAL_BANK_SEL_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_VAL_MASK (0x18U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_VAL_SHIFT (3U)
/*! MPLLB_CAL_BANK_SEL_OVRD_VAL - Override Value for incoming input mpllb_recal_bank_sel */
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_EN_MASK (0x20U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_EN_SHIFT (5U)
/*! MPLLB_CAL_BANK_SEL_OVRD_EN - Enable Override for mplla_cal_bank_sel
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLL_CAL_BANK_SEL_OVRD_MPLLB_CAL_BANK_SEL_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_PG_OVRD_IN - Override Values for Incoming Power-Gating Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_SHIFT (0U)
/*! PMA_PWR_STABLE_OVRD - Enable overriding value for pma_pwr_stable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PMA_PWR_STABLE_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_SHIFT (1U)
/*! PCS_PWR_STABLE_OVRD - Enable overriding value for pcs_pwr_stable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PCS_PWR_STABLE_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_VAL_SHIFT (2U)
/*! PG_RESET_OVRD_VAL - Override Value for pg_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_EN_SHIFT (3U)
/*! PG_RESET_OVRD_EN - Override Enable for pg_reset
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_RESET_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_MASK (0x10U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_SHIFT (4U)
/*! PG_MODE_EN_OVRD_VAL - Override Value for pg_mode_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_MASK (0x20U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_SHIFT (5U)
/*! PG_MODE_EN_OVRD_EN - Override Enable for pg_mode_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_VAL_MASK (0x40U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_VAL_SHIFT (6U)
/*! BG_EN_OVRD_VAL - Override Value for bg_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_EN_MASK (0x80U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_EN_SHIFT (7U)
/*! BG_EN_OVRD_EN - Override Enable for bg_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_IN_BG_EN_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_PG_OVRD_OUT - Override Values for Outgoing Power-Gating Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PMA_PWR_EN_OVRD_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PMA_PWR_EN_OVRD_SHIFT (0U)
/*! PMA_PWR_EN_OVRD - Enable overriding value for pma_pwr_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PMA_PWR_EN_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PMA_PWR_EN_OVRD_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PMA_PWR_EN_OVRD_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PCS_PWR_EN_OVRD_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PCS_PWR_EN_OVRD_SHIFT (1U)
/*! PCS_PWR_EN_OVRD - Enable overriding value for pcs_pwr_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PCS_PWR_EN_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PCS_PWR_EN_OVRD_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PG_OVRD_OUT_PCS_PWR_EN_OVRD_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_SUP_OVRD_IN - Override Values for Incoming Support Block Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_SHIFT (0U)
/*! MPLLA_FORCE_EN_OVRD_VAL - Override Value for mplla_force_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_SHIFT (1U)
/*! MPLLA_FORCE_EN_OVRD_EN - Override Enable for mplla_force_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_SHIFT (2U)
/*! MPLLB_FORCE_EN_OVRD_VAL - Override Value for mpllb_force_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_SHIFT (3U)
/*! MPLLB_FORCE_EN_OVRD_EN - Override Enable for mpllb_force_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_MASK (0x10U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_SHIFT (4U)
/*! REF_CLK_EN_OVRD_VAL - Override Value for ref_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_MASK (0x20U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_SHIFT (5U)
/*! REF_CLK_EN_OVRD_EN - Override Enable for ref_clk_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_SUP_OVRD_OUT - Override Values for Out-going Support Block Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_VAL_SHIFT (0U)
/*! MPLLA_FORCE_ACK_OVRD_VAL - Override Value for Output mplla_force_ack
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_EN_SHIFT (1U)
/*! MPLLA_FORCE_ACK_OVRD_EN - Override Enable for Output mplla_force_ack
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLA_FORCE_ACK_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_VAL_SHIFT (2U)
/*! MPLLB_FORCE_ACK_OVRD_VAL - Override Value for Output mpllb_force_ack
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_EN_SHIFT (3U)
/*! MPLLB_FORCE_ACK_OVRD_EN - Override Enable for Output mpllb_force_ack
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SUP_OVRD_OUT_MPLLB_FORCE_ACK_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_RTUNE_RX_VAL - Resistor Tune RX Value */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_RX_VAL_RTUNE_RX_VAL_MASK (0x3FU)
#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_RX_VAL_RTUNE_RX_VAL_SHIFT (0U)
/*! RTUNE_RX_VAL - Stored resister tune RX value */
#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_RX_VAL_RTUNE_RX_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_RTUNE_RX_VAL_RTUNE_RX_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_RTUNE_RX_VAL_RTUNE_RX_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_RTUNE_TXDN_VAL - Resistor Tune TX Down Value */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXDN_VAL_RTUNE_TXDN_VAL_MASK (0x3FFU)
#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXDN_VAL_RTUNE_TXDN_VAL_SHIFT (0U)
/*! RTUNE_TXDN_VAL - Stored resister tune TX down value */
#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXDN_VAL_RTUNE_TXDN_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXDN_VAL_RTUNE_TXDN_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXDN_VAL_RTUNE_TXDN_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_RTUNE_TXUP_VAL - Resistor Tune TX Up Value */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXUP_VAL_RTUNE_TXUP_VAL_MASK (0x3FFU)
#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXUP_VAL_RTUNE_TXUP_VAL_SHIFT (0U)
/*! RTUNE_TXUP_VAL - Stored resister tune TX up value */
#define ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXUP_VAL_RTUNE_TXUP_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXUP_VAL_RTUNE_TXUP_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_RTUNE_TXUP_VAL_RTUNE_TXUP_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMNCAL_STATUS - Common Calibration Status */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_INIT_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_INIT_SHIFT (0U)
/*! CMNCAL_INIT - Indicates whether common calibration (mpll and rtune) has been started by this lane or not
 *  0b0..Not started
 *  0b1..Started
 */
#define ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_INIT_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_INIT_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_DONE_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_DONE_SHIFT (1U)
/*! CMNCAL_DONE - Indicates whether common calibration (mpll and rtune) has been completed by this lane or not
 *  0b0..Not completed
 *  0b1..Completed
 */
#define ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_CMNCAL_STATUS_CMNCAL_DONE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_SRAM_OVRD_IN - Override for Incoming SRAM Inputs */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_VAL_SHIFT (0U)
/*! SRAM_EXT_LD_DONE_OVRD_VAL - Override Value for input sram_ext_ld_done
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_EN_SHIFT (1U)
/*! SRAM_EXT_LD_DONE_OVRD_EN - Override Enable for Input sram_ext_ld_done
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_EXT_LD_DONE_OVRD_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_VAL_SHIFT (2U)
/*! SRAM_BYPASS_OVRD_VAL - Override Value for Input sram_bypass
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_EN_SHIFT (3U)
/*! SRAM_BYPASS_OVRD_EN - Override Enable for Input sram_bypass
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_OVRD_IN_SRAM_BYPASS_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_SRAM_IN - Monitor for SRAM Inputs */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_BYPASS_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_BYPASS_SHIFT (0U)
/*! SRAM_BYPASS - Value from RAW PCS for sram_bypass */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_BYPASS_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_BYPASS_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_EXT_LD_DONE_MASK (0x2U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_EXT_LD_DONE_SHIFT (1U)
/*! SRAM_EXT_LD_DONE - Value from RAW PCS for sram_ext_ld_done */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_EXT_LD_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_EXT_LD_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_IN_SRAM_EXT_LD_DONE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_SRAM_OUT - Monitor for SRAM Outputs */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OUT_SRAM_INIT_DONE_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OUT_SRAM_INIT_DONE_SHIFT (0U)
/*! SRAM_INIT_DONE - Value from RAW PCS for sram_init_done */
#define ENET_PHY_RAWCMN_DIG_AON_SRAM_OUT_SRAM_INIT_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_SRAM_OUT_SRAM_INIT_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_SRAM_OUT_SRAM_INIT_DONE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_FW_VERSION_0 - Firmware Version 0 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_BRANCH_MASK (0xFU)
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_BRANCH_SHIFT (0U)
/*! BRANCH - BRANCH */
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_BRANCH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_BRANCH_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_BRANCH_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MINOR_VER_MASK (0xFF0U)
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MINOR_VER_SHIFT (4U)
/*! MINOR_VER - Minor update in firmware for any bug fixes of function enhancement */
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MINOR_VER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MINOR_VER_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MINOR_VER_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MAJOR_VER_MASK (0xF000U)
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MAJOR_VER_SHIFT (12U)
/*! MAJOR_VER - A major firmware label which corresponds to significant change in PCS RAW, PMA or firmware algorithm or structure */
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MAJOR_VER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MAJOR_VER_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_0_MAJOR_VER_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_FW_VERSION_1 - Firmware Version 1 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_YEAR_MASK (0x7U)
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_YEAR_SHIFT (0U)
/*! YEAR - Year */
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_YEAR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_YEAR_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_YEAR_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_MONTH_MASK (0x78U)
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_MONTH_SHIFT (3U)
/*! MONTH - Month (1-12) */
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_MONTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_MONTH_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_MONTH_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_DAY_MASK (0xF80U)
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_DAY_SHIFT (7U)
/*! DAY - Day (1-31) */
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_DAY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_DAY_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_DAY_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_FW_EN_MASK (0xF000U)
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_FW_EN_SHIFT (12U)
/*! FW_EN - Selectively enable or disable certain FW features for the same branch */
#define ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_FW_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_FW_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_FW_VERSION_1_FW_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_0 - Override Values for Incoming MPLLA Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_SHIFT (0U)
/*! MPLLA_EN - Override Value for mplla_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLA_DIV2_EN - Override Value for ref_clk_mplla_div2_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLA_DIV8_CLK_EN - Override Value for mplla_div8_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLA_DIV10_CLK_EN - Override Value for mplla_div10_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV16P5_CLK_EN_MASK (0x10U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV16P5_CLK_EN_SHIFT (4U)
/*! MPLLA_DIV16P5_CLK_EN - Override Value for mplla_div16p5_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_MASK (0x1FE0U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_SHIFT (5U)
/*! MPLLA_MULTIPLIER - Override Value for mplla_multiplier */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_MASK (0x6000U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_SHIFT (13U)
/*! MPLLA_TX_CLK_DIV - Override Value for mplla_tx_clk_div */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_SHIFT (15U)
/*! OVRD_EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_1 - Override Values for Incoming MPLLA Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_SHIFT (0U)
/*! MPLLA_SSC_EN - Override Value for mplla_ssc_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_UP_SPREAD_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_UP_SPREAD_SHIFT (1U)
/*! MPLLA_SSC_UP_SPREAD - Override Value for mplla_ssc_up_spread
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_UP_SPREAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_UP_SPREAD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_UP_SPREAD_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_FRACN_CTRL_MASK (0x1FFCU)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_FRACN_CTRL_SHIFT (2U)
/*! MPLLA_FRACN_CTRL - Override Value for mplla_fracn_ctrl */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_FRACN_CTRL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_FRACN_CTRL_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_MASK (0x2000U)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_SHIFT (13U)
/*! MPLLA_SSC_CLK_SEL - Override Value for mplla_ssc_clk_sel[2:0]
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_2 - Override Values for Incoming MPLLA Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! MPLLA_SSC_FREQ_CNT_INIT - Override Value for mplla_ssc_freq_cnt_init[11:0] */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_SSC_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_SSC_FREQ_CNT_INIT_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_3 - Override Values for Incoming MPLLA Controls from ASIC 3 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_3_MPLLA_SSC_FREQ_CNT_PEAK_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_3_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT (0U)
/*! MPLLA_SSC_FREQ_CNT_PEAK - Override Value for mplla_ssc_freq_cnt_peak[7:0] */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_3_MPLLA_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_3_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_3_MPLLA_SSC_FREQ_CNT_PEAK_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_4 - Override Values for Incoming MPLLA Controls from ASIC 4 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_4_MPLLA_BANDWIDTH_MASK (0xFFFFU)
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_4_MPLLA_BANDWIDTH_SHIFT (0U)
/*! MPLLA_BANDWIDTH - Override Value for mplla_bandwidth[15:0] */
#define ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_4_MPLLA_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_4_MPLLA_BANDWIDTH_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_OVRD_IN_4_MPLLA_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_ASIC_IN_0 - Current Values for Incoming MPLLA Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_SHIFT (0U)
/*! MPLLA_EN - Value from ASIC for mplla_en */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLA_DIV2_EN - Value from ASIC for ref_clk_mplla_div2_en */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLA_DIV8_CLK_EN - Value from ASIC for mplla_div8_clk_en */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLA_DIV10_CLK_EN - Value from ASIC for mplla_div10_clk_en */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV16P5_CLK_EN_MASK (0x10U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV16P5_CLK_EN_SHIFT (4U)
/*! MPLLA_DIV16P5_CLK_EN - Value from ASIC for mplla_div16p5_clk_en */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_MASK (0x1FE0U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_SHIFT (5U)
/*! MPLLA_MULTIPLIER - Value from ASIC for mplla_multiplier */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_MASK (0x6000U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_SHIFT (13U)
/*! MPLLA_TX_CLK_DIV - Value from ASIC for mplla_tx_clk_div */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_ASIC_IN_1 - Current Values for Incoming MPLLA Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_SHIFT (0U)
/*! MPLLA_SSC_EN - Value from mplla_ssc_en */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_UP_SPREAD_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_UP_SPREAD_SHIFT (1U)
/*! MPLLA_SSC_UP_SPREAD - Value from mplla_ssc_up_spread */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_UP_SPREAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_UP_SPREAD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_UP_SPREAD_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_FRACN_CTRL_MASK (0x1FFCU)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_FRACN_CTRL_SHIFT (2U)
/*! MPLLA_FRACN_CTRL - Value from mplla_fracn_ctrl */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_FRACN_CTRL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_FRACN_CTRL_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_MASK (0x2000U)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_SHIFT (13U)
/*! MPLLA_SSC_CLK_SEL - Value from mplla_ssc_clk_sel */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_ASIC_IN_2 - Current Values for Incoming MPLLA Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_BANDWIDTH_MASK (0xFFFFU)
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_BANDWIDTH_SHIFT (0U)
/*! MPLLA_BANDWIDTH - Value from ASIC for mplla_bandwidth */
#define ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_BANDWIDTH_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_FREQ_CNT_INIT_ASIC_IN - Current Values for Incoming Level Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_FREQ_CNT_INIT_ASIC_IN_MPLLA_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_SUP_DIG_MPLLA_FREQ_CNT_INIT_ASIC_IN_MPLLA_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! MPLLA_SSC_FREQ_CNT_INIT - Value from ASIC for MPLLA_SSC_FREQ_CNT_INIT */
#define ENET_PHY_SUP_DIG_MPLLA_FREQ_CNT_INIT_ASIC_IN_MPLLA_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_FREQ_CNT_INIT_ASIC_IN_MPLLA_SSC_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_FREQ_CNT_INIT_ASIC_IN_MPLLA_SSC_FREQ_CNT_INIT_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL - MPLL Calibration Controls */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK (0xFU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT (0U)
/*! LOAD_CNT - MSBs for the CHKFRQ FSM ld_val[10:0] load value
 *  0b0000..Gives a ld_val of 0, no PPM difference can be detected
 *  0b1000..Gives a load value of 1024, 3000 PPM resolution possible
 *  0b1010..Gives a load value of 1280, 2343 PPM resolution possible
 *  0b1011..Gives a load value of 1408, 2130 PPM resolution possible
 *  0b1100..Gives a load value of 1536, 1953 PPM resolution possible
 *  0b1111..Gives a load value of 1920, 1600 PPM resolution possible
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK (0x10U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT (4U)
/*! MPLL_SKIPCAL - Skip Automatic (Internal) Calibration of MPLL (and also skip external calibration if it is enabled)
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK (0x20U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT (5U)
/*! MPLL_EXTCAL - Enable external calibration of MPLL
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK (0x40U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT (6U)
/*! EXT_CHKFRQ_EN - Check the frequency of the MPLL */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK (0x7F80U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT (7U)
/*! EXT_COARSE_TUNE - Value of mpll_ana_coarse_tune_i[7:0] in external calibration mode */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK (0x8000U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT (15U)
/*! EXT_CAL_DONE - Set the external calibration status to done
 *  0b0..Not set
 *  0b1..Set to done
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD - MPLL Override Controls */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT (0U)
/*! OVRD_SEL - Override enable bit
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT (1U)
/*! MPLL_FBDIGCLK_EN - Overrides the PWR FSM mpll_fb_dig_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT (2U)
/*! MPLL_PCLK_EN - Overrides the PWR FSM mpll_pclk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK (0x3E0U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT (5U)
/*! DTB_SEL - DTB select for MPLL dtb signals possible values are:
 *  0b00001..> {mpll_fb_clk & ~scan_mode_i,ref_dig_clk & ~scan_mode_i}
 *  0b00010..> {mpll_ana_output_en_i,mpll_pclk_en}
 *  0b00100..> {mpll_cal_rdy,mpll_state}
 *  0b01000..> {mpll_chkfrq_done,mpll_tooslow}
 *  0b10000..> {curr_state[0], mpll_cnt[0]}
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT - MPLL Status */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_MASK (0xFU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT (0U)
/*! FSM_STATE - Current value of the PWR FSM state register */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK (0x10U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT (4U)
/*! MPLL_TOOSLOW - Current value of mpll_tooslow */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK (0x20U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT (5U)
/*! CHKFRQ_DONE - Current value of mpll_chkfrq_done */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK (0x40U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT (6U)
/*! MPLL_CAL_RDY - Current value of mpll_cal_rdy */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK (0x80U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT (7U)
/*! MPLL_R_LANES - Current value of lane_mpll_r */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK (0x100U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT (8U)
/*! MPLL_L_LANES - Current value of lane_mpll_l */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT (9U)
/*! MPLL_PCLK_EN - Current value of mpll_pclk_en */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK (0x400U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT (10U)
/*! MPLL_OUTPUT_EN - Current value of mpll_ana_output_en_i */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK (0x800U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT (11U)
/*! MPLL_FBCLK_EN - Current value of mpll_ana_fb_clk_en_i */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK (0x1000U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT (12U)
/*! MPLL_CAL - Current value of mpll_ana_cal_i */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_MASK (0x2000U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT (13U)
/*! MPLL_RST - Current value of mpll_ana_rst_i */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK (0x4000U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT (14U)
/*! MPLL_ANA_EN - Current value of mpll_ana_en_i */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD - Thresholds for MPLL CAL Update Timer and MPLL VCO Stabilization Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO stabilization timer in terms of number
 *    of reference clock cycles. Here the reference clock means the one that is fed to the phase
 *    detector of the corresponding PLL, not the raw reference clock
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK (0x1E00U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT (9U)
/*! MPLL_CAL_UPDATE_TIME_THRESHOLD - Threshold for the MPLL calibration control word update timer in terms of number of ref_rang_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD - Thresholds for PCLK Enable and MPLL VCO Clock Stabilization Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK (0x7FFU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_CLK_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO clock stabilization timer in terms
 *    of number of reference clock cycles. Here the reference clock means the one that is fed to the
 *    phase detector of the corresponding PLL, not the raw reference clock
 */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK (0xF800U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT (11U)
/*! PCLK_EN_TIME_THRESHOLD - Threshold for the PCLK enable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH - Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_MASK (0x1FU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_SHIFT (0U)
/*! PCLK_DIS_TIME_THRESHOLD - Threshold for the PCLK disable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK (0x3E0U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT (5U)
/*! MPLL_VCO_PWRDN_TIME_THRESHOLD - Threshold for the MPLL VCO power down timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH - Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK (0x7FU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT (0U)
/*! MPLL_ANA_PWRUP_TIME_THRESHOLD - Threshold for the MPLL analog power up timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD - Thresholds for MPLL Feedback Clock Enable and MPLL Feedback Digital Clock Disable Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK (0xFU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT (0U)
/*! MPLL_FBCLK_EN_TIME_THRESHOLD - Threshold for the MPLL feedback clock enable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK (0xF0U)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT (4U)
/*! MPLL_FBDIGCLK_DIS_TIME_THRESHOLD - Threshold for the MPLL feedback digital clock disable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL - MPLL coarse_tune Value */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT (0U)
/*! MPLL_COARSE_TUNE_VAL - Current value of mpll_ana_coarse_tune_i */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune When Skipping Calibration */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT (0U)
/*! MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune when calibration is skipped */
#define ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_SSC_SS_PHASE - Current MPLL Phase Selector Value */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_MASK (0x3U)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_SHIFT (0U)
/*! DTHR - Bits below the useful resolution (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_MASK (0x7FCU)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_SHIFT (2U)
/*! VAL - Phase value from zero reference (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_MASK (0x800U)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_SHIFT (11U)
/*! ZERO_FREQ - Zero Frequency Register */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_FRACN_CTRL_DIV_MASK (0xF000U)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_FRACN_CTRL_DIV_SHIFT (12U)
/*! FRACN_CTRL_DIV - FracN Control Divisor */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_FRACN_CTRL_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_FRACN_CTRL_DIV_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_PHASE_FRACN_CTRL_DIV_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_SSC_SS_FREQ_0 - Frequency Control for Spread Spectrum 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT (0U)
/*! FREQ_CNT_INIT - Initial Frequency Counter Value (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK (0x1000U)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT (12U)
/*! FREQ_0_OVRD - Frequency Register Override */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_SSC_SS_FREQ_1 - Frequency Control for Spread Spectrum 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PEAK_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PEAK_SHIFT (0U)
/*! FREQ_PEAK - Peak Frequency Value (for changing direction) (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PEAK_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PEAK_MASK)

#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK (0x100U)
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT (8U)
/*! FREQ_1_OVRD - Frequency Register Override */
#define ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLA_LOOP_CTRL - MPLLA_LOOP_CTRL */
/*! @{ */

#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_ovrd_pr_bypass_MASK (0x2U)
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_ovrd_pr_bypass_SHIFT (1U)
/*! ovrd_pr_bypass - Enable local control of PR bypass signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_ovrd_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_ovrd_pr_bypass_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_ovrd_pr_bypass_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_mode_old_ssc_MASK (0x4U)
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_mode_old_ssc_SHIFT (2U)
/*! mode_old_ssc - Switch back to 2-bit ssc
 *  0b0..No switch
 *  0b1..Switch back
 */
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_mode_old_ssc(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_mode_old_ssc_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_mode_old_ssc_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pr_bypass_MASK (0x8U)
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pr_bypass_SHIFT (3U)
/*! pr_bypass - Set local pr bypass control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pr_bypass_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pr_bypass_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_meas_iv_23_MASK (0x10U)
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_meas_iv_23_SHIFT (4U)
/*! meas_iv_23 - VCO control buffer bypass (active high) */
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_meas_iv_23(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_meas_iv_23_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_meas_iv_23_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_lpn_vreg_MASK (0x20U)
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_lpn_vreg_SHIFT (5U)
/*! lpn_vreg - vreg_vco draws power from vph instead of vp when asserted */
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_lpn_vreg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_lpn_vreg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_lpn_vreg_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pfd_pw_ctrl_MASK (0xC0U)
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pfd_pw_ctrl_SHIFT (6U)
/*! pfd_pw_ctrl - PFD Reset Pulse Width Control
 *  0b11..Maximum pulse width
 *  0b00..Minimum pulse width
 */
#define ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pfd_pw_ctrl(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pfd_pw_ctrl_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_LOOP_CTRL_pfd_pw_ctrl_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLA_OVRD - MPLLA_OVRD */
/*! @{ */

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_enable_MASK (0x1U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_enable_SHIFT (0U)
/*! ovrd_enable - Enable local control of enable signal (mpll_en)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_enable(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_enable_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_enable_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_enable_reg_MASK (0x2U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_enable_reg_SHIFT (1U)
/*! enable_reg - Set local enable control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_enable_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_enable_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_enable_reg_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_cal_MASK (0x4U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_cal_SHIFT (2U)
/*! ovrd_cal - Enable local control of calibration signal (mpll_cal)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_cal(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_cal_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_cal_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_cal_reg_MASK (0x8U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_cal_reg_SHIFT (3U)
/*! cal_reg - Set local calibration control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_cal_reg(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_cal_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_cal_reg_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_MASK (0x10U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_SHIFT (4U)
/*! ovrd_fb_clk_en - Enable local control of feedback clock control signal (mpll_fb_clk_en)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_MASK (0x20U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_SHIFT (5U)
/*! fb_clk_en_reg - Set local feedback clock control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_reset_MASK (0x40U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_reset_SHIFT (6U)
/*! ovrd_reset - Enable local control of reset signal (mpll_rst)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_reset(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_reset_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_ovrd_reset_MASK)

#define ENET_PHY_SUP_ANA_MPLLA_OVRD_reset_reg_MASK (0x80U)
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_reset_reg_SHIFT (7U)
/*! reset_reg - Set local reset control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLA_OVRD_reset_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLA_OVRD_reset_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLA_OVRD_reset_reg_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLA_OVRD_OUT - Override Value for MPLLA Signals Going to ANA */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_SHIFT (0U)
/*! MPLLA_ANA_EN - Overrides the mplla_ana_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_MASK (0x2U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_SHIFT (1U)
/*! MPLLA_RST - Overrides the mplla_ana_rst signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_MASK (0x4U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_SHIFT (2U)
/*! MPLLA_CAL - Overrides the mplla_ana_cal signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_SHIFT (3U)
/*! MPLLA_OUTPUT_EN - Overrides the mplla_ana_output_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_MASK (0x10U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_SHIFT (4U)
/*! MPLLA_OUTPUT_L_EN - Overrides the mplla_ana_output_l_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_MASK (0x20U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_SHIFT (5U)
/*! MPLLA_OUTPUT_R_EN - Overrides the mplla_ana_output_r_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_MASK (0x40U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_SHIFT (6U)
/*! MPLLA_DIV8_CLK_EN - Overrides the mplla_ana_div8_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_MASK (0x80U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_SHIFT (7U)
/*! MPLLA_DIV10_CLK_EN - Overrides the mplla_ana_div10_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_SHIFT (8U)
/*! MPLLA_FBCLK_EN - Overrides the mplla_fb_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV16P5_CLK_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV16P5_CLK_EN_SHIFT (9U)
/*! MPLLA_DIV16P5_CLK_EN - Overrides the mplla_ana_div16p5_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_MASK (0x400U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_SHIFT (10U)
/*! MPLLA_DIV_CLK_EN - Overrides the mplla_ana_div_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_MASK (0x800U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_SHIFT (11U)
/*! OVRD_SEL - Override bit for mplla_ana outputs
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT - Override Value for MPLLA PMIX Signals Going to ANA */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_SHIFT (0U)
/*! MPLLA_PMIX_SEL - Overrides the mplla_ana_pmix_sel signal */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_SHIFT (8U)
/*! MPLLA_PMIX_SEL_OVRD_EN - Override bit for mplla_ana_pmix_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_SHIFT (9U)
/*! MPLLA_PMIX_EN - Override bit for mplla_ana_pmix_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_OVRD_EN_MASK (0x400U)
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_OVRD_EN_SHIFT (10U)
/*! MPLLA_PMIX_OVRD_EN - Override bit for mplla_ana_pmix_sel signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_BW_OVRD_IN - Override Values for Incoming MPLLA Bandwidth */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_SHIFT (0U)
/*! MPLLA_BW_OVRD_VAL - Override Value for mplla_bandwidth[15:0] */
#define ENET_PHY_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN - Override Values for Incoming MPLLA SSC Control Settings */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_FRACN_CTRL_MASK (0x7FFU)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_FRACN_CTRL_SHIFT (0U)
/*! MPLLA_FRACN_CTRL - Override Value for mplla_fracn_ctrl[10:0] */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_FRACN_CTRL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_FRACN_CTRL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_UP_SPREAD_MASK (0x800U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_UP_SPREAD_SHIFT (11U)
/*! MPLLA_SSC_UP_SPREAD - Override Value for mplla_ssc_up_spread
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_UP_SPREAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_UP_SPREAD_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_UP_SPREAD_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CLK_SEL_MASK (0x1000U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CLK_SEL_SHIFT (12U)
/*! MPLLA_SSC_CLK_SEL - Override Value for mplla_ssc_clk_sel
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CLK_SEL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CLK_SEL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CTL_OVRD_EN_MASK (0x2000U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CTL_OVRD_EN_SHIFT (13U)
/*! MPLLA_SSC_CTL_OVRD_EN - Override Value for MPLLA SSC control settings
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CTL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CTL_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_MPLLA_SSC_CTL_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN - Override Values for Incoming MPLLA SSC Input Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! MPLLA_SSC_FREQ_CNT_INIT - Override Value for mplla_ssc_freq_cnt_init */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_EN_MASK (0x1000U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_EN_SHIFT (12U)
/*! MPLLA_SSC_FREQ_CNT_INIT_EN - Override Value for mplla_ssc_freq_cnt_init
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_FREQ_CNT_INIT_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_VAL_MASK (0x2000U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_VAL_SHIFT (13U)
/*! MPLLA_SSC_EN_OVRD_VAL - Override Value for MPLLA SSC enable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_EN_SHIFT (14U)
/*! MPLLA_SSC_EN_OVRD_EN - Override Enable for MPLLA SSC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_SSC_EN_OVRD_IN_MPLLA_SSC_EN_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_MISC_OVRD_IN - Override Values for Incoming MPLLA-Related Input Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT (0U)
/*! MPLLA_SSC_FREQ_CNT_PEAK - Override Value for mplla_ssc_freq_cnt_peak[7:0] */
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_EN_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_EN_SHIFT (8U)
/*! MPLLA_SSC_FREQ_CNT_PEAK_EN - Override Value for mplla_ssc_freq_cnt_peak
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_SSC_FREQ_CNT_PEAK_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_MASK (0x600U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_SHIFT (9U)
/*! MPLLA_TX_CLK_DIV_OVRD_VAL - Override Value for MPLLA SSC enable */
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_OVRD_EN_MASK (0x800U)
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_OVRD_EN_SHIFT (11U)
/*! MPLLA_OVRD_EN - Override Enable for mplla_bandwidth and mplla_tx_clk_div
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLA_MISC_OVRD_IN_MPLLA_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0 - MPLLA Coarse Tune Value for Bank 0 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_BANK_0_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_BANK_0_SHIFT (0U)
/*! MPLLA_COARSE_TUNE_BANK_0 - Stored bank0 coarse tune value for MPLLA */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_BANK_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_BANK_0_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_BANK_0_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_DONE_BANK_0_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_DONE_BANK_0_SHIFT (8U)
/*! MPLLA_COARSE_TUNE_DONE_BANK_0 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_DONE_BANK_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_DONE_BANK_0_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_0_MPLLA_COARSE_TUNE_DONE_BANK_0_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1 - MPLLA Coarse Tune Value for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_BANK_1_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_BANK_1_SHIFT (0U)
/*! MPLLA_COARSE_TUNE_BANK_1 - Stored bank 1 coarse tune value for MPLLA */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_BANK_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_BANK_1_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_BANK_1_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_DONE_BANK_1_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_DONE_BANK_1_SHIFT (8U)
/*! MPLLA_COARSE_TUNE_DONE_BANK_1 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_DONE_BANK_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_DONE_BANK_1_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_1_MPLLA_COARSE_TUNE_DONE_BANK_1_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2 - MPLLA Coarse Tune Value for Bank 2 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_BANK_2_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_BANK_2_SHIFT (0U)
/*! MPLLA_COARSE_TUNE_BANK_2 - Stored bank 2 coarse tune value for MPLLA */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_BANK_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_BANK_2_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_BANK_2_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_DONE_BANK_2_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_DONE_BANK_2_SHIFT (8U)
/*! MPLLA_COARSE_TUNE_DONE_BANK_2 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_DONE_BANK_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_DONE_BANK_2_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_2_MPLLA_COARSE_TUNE_DONE_BANK_2_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3 - MPLLA Coarse Tune Value for Bank 3 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_BANK_3_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_BANK_3_SHIFT (0U)
/*! MPLLA_COARSE_TUNE_BANK_3 - Stored bank 3 coarse tune value for MPLLA */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_BANK_3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_BANK_3_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_BANK_3_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_DONE_BANK_3_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_DONE_BANK_3_SHIFT (8U)
/*! MPLLA_COARSE_TUNE_DONE_BANK_3 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_DONE_BANK_3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_DONE_BANK_3_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_BANK_3_MPLLA_COARSE_TUNE_DONE_BANK_3_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_CAL_BANK_SEL - Value for MPLLA Bank Select */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_CAL_BANK_SEL_MPLLA_CAL_BANK_SEL_MASK (0x3U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_CAL_BANK_SEL_MPLLA_CAL_BANK_SEL_SHIFT (0U)
/*! MPLLA_CAL_BANK_SEL - Value for MPLLA Bank select */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_CAL_BANK_SEL_MPLLA_CAL_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_CAL_BANK_SEL_MPLLA_CAL_BANK_SEL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_CAL_BANK_SEL_MPLLA_CAL_BANK_SEL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_DONE - Valid Calibrated Value for MPLLA Calibration Bank */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_DONE_MPLLA_COARSE_TUNE_DONE_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_DONE_MPLLA_COARSE_TUNE_DONE_SHIFT (0U)
/*! MPLLA_COARSE_TUNE_DONE - Indicates if the selected MPLLA Calibration bank has the valid calibrated value
 *  0b0..Invalid
 *  0b1..Valid
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_DONE_MPLLA_COARSE_TUNE_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_DONE_MPLLA_COARSE_TUNE_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_DONE_MPLLA_COARSE_TUNE_DONE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_COARSE_TUNE - Selected COARSE TUNE Value for MPLLA */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_SHIFT (0U)
/*! MPLLA_COARSE_TUNE - Selected coarse tune value for MPLLA */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_IN_RECAL - MPLLA Re-Calibration */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_IN_RECAL_MPLLA_IN_RECAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_IN_RECAL_MPLLA_IN_RECAL_SHIFT (0U)
/*! MPLLA_IN_RECAL - Indicates if MPLLA is in re-calibration
 *  0b0..Not in re-calibration
 *  0b1..In re-calibration
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_IN_RECAL_MPLLA_IN_RECAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_IN_RECAL_MPLLA_IN_RECAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_IN_RECAL_MPLLA_IN_RECAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_PMA_MPLLA_RECAL_BANK_SEL - Current Bank Selected for MPLLA Coarse Tune in PMA */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLA_RECAL_BANK_SEL_PMA_MPLLA_RECAL_BANK_SEL_MASK (0x3U)
#define ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLA_RECAL_BANK_SEL_PMA_MPLLA_RECAL_BANK_SEL_SHIFT (0U)
/*! PMA_MPLLA_RECAL_BANK_SEL - Current bank selected for MPLLA coarse tune in PMA */
#define ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLA_RECAL_BANK_SEL_PMA_MPLLA_RECAL_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLA_RECAL_BANK_SEL_PMA_MPLLA_RECAL_BANK_SEL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLA_RECAL_BANK_SEL_PMA_MPLLA_RECAL_BANK_SEL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLA_BANK_SEL_DONE - Status for MPLLA Re-Calibration or Switching */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_BANK_SEL_DONE_DONE_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_BANK_SEL_DONE_DONE_SHIFT (0U)
/*! DONE - Status for MPLLA re-calibration or switching */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLA_BANK_SEL_DONE_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLA_BANK_SEL_DONE_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLA_BANK_SEL_DONE_DONE_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_0 - Override Values for Incoming MPLLB Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_SHIFT (0U)
/*! MPLLB_EN - Override Value for mpllb_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLB_DIV2_EN - Override Value for ref_clk_mpllb_div2_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLB_DIV8_CLK_EN - Override Value for mpllb_div8_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLB_DIV10_CLK_EN - Override Value for mpllb_div10_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_MASK (0xFF0U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_SHIFT (4U)
/*! MPLLB_MULTIPLIER - Override Value for mpllb_multiplier */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_MASK (0x3000U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_SHIFT (12U)
/*! MPLLB_TX_CLK_DIV - Override Value for mpllb_tx_clk_div */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_SHIFT (14U)
/*! OVRD_EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_1 - Override Values for Incoming MPLLB Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_SHIFT (0U)
/*! MPLLB_SSC_EN - Override Value for mpllb_ssc_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_UP_SPREAD_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_UP_SPREAD_SHIFT (1U)
/*! MPLLB_SSC_UP_SPREAD - Override Value for mpllb_ssc_up_spread
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_UP_SPREAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_UP_SPREAD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_UP_SPREAD_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_FRACN_CTRL_MASK (0x1FFCU)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_FRACN_CTRL_SHIFT (2U)
/*! MPLLB_FRACN_CTRL - Override Value for mpllb_fracn_ctrl */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_FRACN_CTRL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_FRACN_CTRL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_MASK (0x2000U)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_SHIFT (13U)
/*! MPLLB_SSC_CLK_SEL - Override Value for mpllb_ssc_clk_sel[2:0]
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_2 - Override Values for Incoming MPLLB Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! MPLLB_SSC_FREQ_CNT_INIT - Override Value for mpllb_ssc_freq_cnt_init[11:0] */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_SSC_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_SSC_FREQ_CNT_INIT_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_3 - Override Values for Incoming MPLLB Controls from ASIC 3 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_3_MPLLB_SSC_FREQ_CNT_PEAK_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_3_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT (0U)
/*! MPLLB_SSC_FREQ_CNT_PEAK - Override Value for mpllb_ssc_freq_cnt_peak[7:0] */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_3_MPLLB_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_3_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_3_MPLLB_SSC_FREQ_CNT_PEAK_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_4 - Override Values for Incoming MPLLB Controls from ASIC 4 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_4_MPLLB_BANDWIDTH_MASK (0xFFFFU)
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_4_MPLLB_BANDWIDTH_SHIFT (0U)
/*! MPLLB_BANDWIDTH - Override Value for mpllb_bandwidth[15:0] */
#define ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_4_MPLLB_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_4_MPLLB_BANDWIDTH_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_OVRD_IN_4_MPLLB_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_ASIC_IN_0 - Current Values for Incoming MPLLB Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_SHIFT (0U)
/*! MPLLB_EN - Value from ASIC for mpllb_en */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLB_DIV2_EN - Value from ASIC for ref_clk_mpllb_div2_en */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLB_DIV8_CLK_EN - Value from ASIC for mpllb_div8_clk_en */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLB_DIV10_CLK_EN - Value from ASIC for mpllb_div10_clk_en */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_MASK (0xFF0U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_SHIFT (4U)
/*! MPLLB_MULTIPLIER - Value from ASIC for mpllb_multiplier */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_MASK (0x3000U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_SHIFT (12U)
/*! MPLLB_TX_CLK_DIV - Value from ASIC for mpllb_tx_clk_div */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_ASIC_IN_1 - Current Values for Incoming MPLLB Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_SHIFT (0U)
/*! MPLLB_SSC_EN - Value from mpllb_ssc_en */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_UP_SPREAD_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_UP_SPREAD_SHIFT (1U)
/*! MPLLB_SSC_UP_SPREAD - Value from mpllb_ssc_up_spread */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_UP_SPREAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_UP_SPREAD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_UP_SPREAD_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_FRACN_CTRL_MASK (0x1FFCU)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_FRACN_CTRL_SHIFT (2U)
/*! MPLLB_FRACN_CTRL - Value from mpllb_fracn_ctrl */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_FRACN_CTRL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_FRACN_CTRL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_MASK (0x2000U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_SHIFT (13U)
/*! MPLLB_SSC_CLK_SEL - Value from mpllb_ssc_clk_sel[2:0] */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_VPH_NOMINAL_MASK (0xC000U)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_VPH_NOMINAL_SHIFT (14U)
/*! VPH_NOMINAL - Value from vph_nominal */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_VPH_NOMINAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_VPH_NOMINAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_1_VPH_NOMINAL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_ASIC_IN_2 - Current Values for Incoming MPLLB Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_BANDWIDTH_MASK (0xFFFFU)
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_BANDWIDTH_SHIFT (0U)
/*! MPLLB_BANDWIDTH - Value from ASIC for mpllb_bandwidth */
#define ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_BANDWIDTH_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_FREQ_CNT_INIT_ASIC_IN - Current Values for Incoming Level Controls from ASIC */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_FREQ_CNT_INIT_ASIC_IN_MPLLB_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_SUP_DIG_MPLLB_FREQ_CNT_INIT_ASIC_IN_MPLLB_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! MPLLB_SSC_FREQ_CNT_INIT - Value from ASIC for MPLLB_SSC_FREQ_CNT_INIT */
#define ENET_PHY_SUP_DIG_MPLLB_FREQ_CNT_INIT_ASIC_IN_MPLLB_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_FREQ_CNT_INIT_ASIC_IN_MPLLB_SSC_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_FREQ_CNT_INIT_ASIC_IN_MPLLB_SSC_FREQ_CNT_INIT_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL - MPLL Calibration Controls */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK (0xFU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT (0U)
/*! LOAD_CNT - MSBs for the CHKFRQ FSM ld_val[10:0] load value
 *  0b0000..Gives a ld_val of 0, no PPM difference can be detected
 *  0b1000..Gives a load value of 1024, 3000PPM resolution possible
 *  0b1010..Gives a load value of 1280, 2343PPM resolution possible
 *  0b1011..Gives a load value of 1408, 2130PPM resolution possible
 *  0b1100..Gives a load value of 1536, 1953PPM resolution possible
 *  0b1111..Gives a load value of 1920, 1600PPM resolution possible
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK (0x10U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT (4U)
/*! MPLL_SKIPCAL - Skip Automatic (Internal) Calibration of MPLL (and also skip external calibration if it is enabled)
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK (0x20U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT (5U)
/*! MPLL_EXTCAL - Enable external calibration of MPLL
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK (0x40U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT (6U)
/*! EXT_CHKFRQ_EN - Check the frequency of the MPLL */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK (0x7F80U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT (7U)
/*! EXT_COARSE_TUNE - Value of mpll_ana_coarse_tune_i[7:0] in external calibration mode */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK (0x8000U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT (15U)
/*! EXT_CAL_DONE - Set the external calibration status to done
 *  0b0..Not set
 *  0b1..Set to done
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD - MPLL Override Controls */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK (0x1U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT (0U)
/*! OVRD_SEL - Override enable bit
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK (0x2U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT (1U)
/*! MPLL_FBDIGCLK_EN - Overrides the PWR FSM mpll_fb_dig_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK (0x4U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT (2U)
/*! MPLL_PCLK_EN - Overrides the PWR FSM mpll_pclk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK (0x3E0U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT (5U)
/*! DTB_SEL - DTB select for MPLL dtb signals possible values are:
 *  0b00001..> {mpll_fb_clk & ~scan_mode_i,ref_dig_clk & ~scan_mode_i}
 *  0b00010..> {mpll_ana_output_en_i,mpll_pclk_en}
 *  0b00100..> {mpll_cal_rdy,mpll_state}
 *  0b01000..> {mpll_chkfrq_done,mpll_tooslow}
 *  0b10000..> {curr_state[0], mpll_cnt[0]}
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT - MPLL Status */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_MASK (0xFU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT (0U)
/*! FSM_STATE - Current value of the PWR FSM state register */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK (0x10U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT (4U)
/*! MPLL_TOOSLOW - Current value of mpll_tooslow */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK (0x20U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT (5U)
/*! CHKFRQ_DONE - Current value of mpll_chkfrq_done */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK (0x40U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT (6U)
/*! MPLL_CAL_RDY - Current value of mpll_cal_rdy */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK (0x80U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT (7U)
/*! MPLL_R_LANES - Current value of lane_mpll_r */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK (0x100U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT (8U)
/*! MPLL_L_LANES - Current value of lane_mpll_l */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT (9U)
/*! MPLL_PCLK_EN - Current value of mpll_pclk_en */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK (0x400U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT (10U)
/*! MPLL_OUTPUT_EN - Current value of mpll_ana_output_en_i */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK (0x800U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT (11U)
/*! MPLL_FBCLK_EN - Current value of mpll_ana_fb_clk_en_i */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK (0x1000U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT (12U)
/*! MPLL_CAL - Current value of mpll_ana_cal_i */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_MASK (0x2000U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT (13U)
/*! MPLL_RST - Current value of mpll_ana_rst_i */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK (0x4000U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT (14U)
/*! MPLL_ANA_EN - Current value of mpll_ana_en_i */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD - Thresholds for MPLL CAL Update Timer and MPLL VCO Stabilization Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK (0x1FFU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO stabilization timer in terms of number
 *    of reference clock cycles. Here the reference clock means the one that is fed to the phase
 *    detector of the corresponding PLL, not the raw reference clock
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK (0x1E00U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT (9U)
/*! MPLL_CAL_UPDATE_TIME_THRESHOLD - Threshold for the MPLL calibration control word update timer in terms of number of ref_rang_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD - Thresholds for PCLK Enable and MPLL VCO Clock Stabilization Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK (0x7FFU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_CLK_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO clock stabilization timer in terms
 *    of number of reference clock cycles. Here the reference clock means the one that is fed to the
 *    phase detector of the corresponding PLL, not the raw reference clock
 */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK (0xF800U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT (11U)
/*! PCLK_EN_TIME_THRESHOLD - Threshold for the PCLK enable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH - Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_MASK (0x1FU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_SHIFT (0U)
/*! PCLK_DIS_TIME_THRESHOLD - Threshold for the PCLK disable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_PCLK_DIS_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK (0x3E0U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT (5U)
/*! MPLL_VCO_PWRDN_TIME_THRESHOLD - Threshold for the MPLL VCO power down timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESH_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH - Thresholds for PCLK Disable and MPLL VCO POWER DOWN and MPLL ANA POWER UP Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK (0x7FU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT (0U)
/*! MPLL_ANA_PWRUP_TIME_THRESHOLD - Threshold for the MPLL analog power up timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_ANA_PWRUP_TIME_THRESH_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD - Thresholds for MPLL Feedback Clock Enable and MPLL Feedback Digital Clock Disable Timer */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK (0xFU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT (0U)
/*! MPLL_FBCLK_EN_TIME_THRESHOLD - Threshold for the MPLL feedback clock enable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK (0xF0U)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT (4U)
/*! MPLL_FBDIGCLK_DIS_TIME_THRESHOLD - Threshold for the MPLL feedback digital clock disable timer in terms of number of ref_range_clk cycles */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL - MPLL coarse_tune Value */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT (0U)
/*! MPLL_COARSE_TUNE_VAL - Current value of mpll_ana_coarse_tune_i */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune When Skipping Calibration */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT (0U)
/*! MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune when calibration is skipped */
#define ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_SSC_SS_PHASE - Current MPLL Phase Selector Value */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_MASK (0x3U)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_SHIFT (0U)
/*! DTHR - Bits below the useful resolution (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_MASK (0x7FCU)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_SHIFT (2U)
/*! VAL - Phase value from zero reference (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_MASK (0x800U)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_SHIFT (11U)
/*! ZERO_FREQ - Zero Frequency Register */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_FRACN_CTRL_DIV_MASK (0xF000U)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_FRACN_CTRL_DIV_SHIFT (12U)
/*! FRACN_CTRL_DIV - FracN Control Divisor */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_FRACN_CTRL_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_FRACN_CTRL_DIV_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_PHASE_FRACN_CTRL_DIV_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_SSC_SS_FREQ_0 - Frequency Control for Spread Spectrum 0 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT (0U)
/*! FREQ_CNT_INIT - Initial Frequency Counter Value (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK (0x1000U)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT (12U)
/*! FREQ_0_OVRD - Frequency Register Override */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_SSC_SS_FREQ_1 - Frequency Control for Spread Spectrum 1 */
/*! @{ */

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PEAK_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PEAK_SHIFT (0U)
/*! FREQ_PEAK - Peak Frequency Value (for changing direction) (volatile and 2 reads needed to read value) */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PEAK_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PEAK_MASK)

#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK (0x100U)
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT (8U)
/*! FREQ_1_OVRD - Frequency Register Override */
#define ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT)) & ENET_PHY_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLB_LOOP_CTRL - MPLLB_LOOP_CTRL */
/*! @{ */

#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_ovrd_pr_bypass_MASK (0x2U)
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_ovrd_pr_bypass_SHIFT (1U)
/*! ovrd_pr_bypass - Enable local control of PR bypass signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_ovrd_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_ovrd_pr_bypass_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_ovrd_pr_bypass_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_mode_old_ssc_MASK (0x4U)
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_mode_old_ssc_SHIFT (2U)
/*! mode_old_ssc - Switch back to 2-bit ssc
 *  0b0..No switch
 *  0b1..Switch back
 */
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_mode_old_ssc(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_mode_old_ssc_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_mode_old_ssc_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pr_bypass_MASK (0x8U)
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pr_bypass_SHIFT (3U)
/*! pr_bypass - Set local pr bypass control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pr_bypass_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pr_bypass_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_meas_iv_23_MASK (0x10U)
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_meas_iv_23_SHIFT (4U)
/*! meas_iv_23 - VCO control buffer bypass (active high) */
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_meas_iv_23(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_meas_iv_23_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_meas_iv_23_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_lpn_vreg_MASK (0x20U)
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_lpn_vreg_SHIFT (5U)
/*! lpn_vreg - vreg_vco draws power from vph instead of vp when asserted */
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_lpn_vreg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_lpn_vreg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_lpn_vreg_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pfd_pw_ctrl_MASK (0xC0U)
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pfd_pw_ctrl_SHIFT (6U)
/*! pfd_pw_ctrl - PFD Reset Pulse Width Control
 *  0b11..Maximum pulse width
 *  0b00..Minimum pulse width
 */
#define ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pfd_pw_ctrl(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pfd_pw_ctrl_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_LOOP_CTRL_pfd_pw_ctrl_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLB_OVRD - MPLLB_OVRD */
/*! @{ */

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_enable_MASK (0x1U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_enable_SHIFT (0U)
/*! ovrd_enable - Enable local control of enable signal (mpll_en)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_enable(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_enable_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_enable_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_enable_reg_MASK (0x2U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_enable_reg_SHIFT (1U)
/*! enable_reg - Set local enable control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_enable_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_enable_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_enable_reg_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_cal_MASK (0x4U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_cal_SHIFT (2U)
/*! ovrd_cal - Enable local control of calibration signal (mpll_cal)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_cal(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_cal_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_cal_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_cal_reg_MASK (0x8U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_cal_reg_SHIFT (3U)
/*! cal_reg - Set local calibration control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_cal_reg(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_cal_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_cal_reg_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_MASK (0x10U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_SHIFT (4U)
/*! ovrd_fb_clk_en - Enable local control of feedback clock control signal (mpll_fb_clk_en)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_MASK (0x20U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_SHIFT (5U)
/*! fb_clk_en_reg - Set local feedback clock control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_reset_MASK (0x40U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_reset_SHIFT (6U)
/*! ovrd_reset - Enable local control of reset signal (mpll_rst)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_reset(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_reset_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_ovrd_reset_MASK)

#define ENET_PHY_SUP_ANA_MPLLB_OVRD_reset_reg_MASK (0x80U)
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_reset_reg_SHIFT (7U)
/*! reset_reg - Set local reset control to ON
 *  0b0..Not set
 *  0b1..Set to ON
 */
#define ENET_PHY_SUP_ANA_MPLLB_OVRD_reset_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_ANA_MPLLB_OVRD_reset_reg_SHIFT)) & ENET_PHY_SUP_ANA_MPLLB_OVRD_reset_reg_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLB_OVRD_OUT - Override Value for MPLLB Signals Going to ANA */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_MASK (0x1U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_SHIFT (0U)
/*! MPLLB_ANA_EN - Overrides the mpllb_ana_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_MASK (0x2U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_SHIFT (1U)
/*! MPLLB_RST - Overrides the mpllb_ana_rst signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_MASK (0x4U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_SHIFT (2U)
/*! MPLLB_CAL - Overrides the mpllb_ana_cal signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_MASK (0x8U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_SHIFT (3U)
/*! MPLLB_OUTPUT_EN - Overrides the mpllb_ana_output_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_MASK (0x10U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_SHIFT (4U)
/*! MPLLB_OUTPUT_L_EN - Overrides the mpllb_ana_output_l_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_MASK (0x20U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_SHIFT (5U)
/*! MPLLB_OUTPUT_R_EN - Overrides the mpllb_ana_output_r_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_MASK (0x40U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_SHIFT (6U)
/*! MPLLB_DIV8_CLK_EN - Overrides the mpllb_ana_div8_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_MASK (0x80U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_SHIFT (7U)
/*! MPLLB_DIV10_CLK_EN - Overrides the mpllb_ana_div10_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_SHIFT (8U)
/*! MPLLB_FBCLK_EN - Overrides the mpllb_fb_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_SHIFT (9U)
/*! MPLLB_DIV_CLK_EN - Overrides the mpllb_ana_div_clk_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_MASK (0x400U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_SHIFT (10U)
/*! OVRD_SEL - Override bit for mpllb_ana outputs
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT - Override Value for MPLLB PMIX Signals Going to ANA */
/*! @{ */

#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_MASK (0xFFU)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_SHIFT (0U)
/*! MPLLB_PMIX_SEL - Overrides the mpllb_ana_pmix_sel signal */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_MASK (0x100U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_SHIFT (8U)
/*! MPLLB_PMIX_SEL_OVRD_EN - Override bit for mplla_ana_pmix_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX__EN_MASK (0x200U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX__EN_SHIFT (9U)
/*! MPLLB_PMIX__EN - Override bit for mpllb_ana_pmix_en signal
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX__EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX__EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX__EN_MASK)

#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_OVRD_EN_MASK (0x400U)
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_OVRD_EN_SHIFT (10U)
/*! MPLLB_PMIX_OVRD_EN - Override bit for mpllb_ana_pmix_sel/en signals
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_OVRD_EN_SHIFT)) & ENET_PHY_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_BW_OVRD_IN - Override Values for Incoming MPLLB Bandwidth */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_SHIFT (0U)
/*! MPLLB_BW_OVRD_VAL - Override Value for mpllb_bandwidth[15:0] */
#define ENET_PHY_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN - Override Values for Incoming MPLLB SSC Control Settings */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_FRACN_CTRL_MASK (0x7FFU)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_FRACN_CTRL_SHIFT (0U)
/*! MPLLB_FRACN_CTRL - Override Value for mpllb_fracn_ctrl[10:0] */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_FRACN_CTRL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_FRACN_CTRL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_UP_SPREAD_MASK (0x800U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_UP_SPREAD_SHIFT (11U)
/*! MPLLB_SSC_UP_SPREAD - Override Value for mpllb_ssc_up_spread
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_UP_SPREAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_UP_SPREAD_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_UP_SPREAD_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CLK_SEL_MASK (0x1000U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CLK_SEL_SHIFT (12U)
/*! MPLLB_SSC_CLK_SEL - Override Value for mpllb_ssc_clk_sel
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CLK_SEL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CLK_SEL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CTL_OVRD_EN_MASK (0x2000U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CTL_OVRD_EN_SHIFT (13U)
/*! MPLLB_SSC_CTL_OVRD_EN - Override Value for MPLLB SSC control settings
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CTL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CTL_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_MPLLB_SSC_CTL_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN - Override Values for Incoming MPLLB SSC Input Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_MASK (0xFFFU)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_SHIFT (0U)
/*! MPLLB_SSC_FREQ_CNT_INIT - Override Value for mpllb_ssc_freq_cnt_init */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_EN_MASK (0x1000U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_EN_SHIFT (12U)
/*! MPLLB_SSC_FREQ_CNT_INIT_EN - Override Value for mpllb_ssc_freq_cnt_init
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_FREQ_CNT_INIT_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_VAL_MASK (0x2000U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_VAL_SHIFT (13U)
/*! MPLLB_SSC_EN_OVRD_VAL - Override Value for MPLLB SSC enable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_EN_SHIFT (14U)
/*! MPLLB_SSC_EN_OVRD_EN - Override Enable for MPLLB SSC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_SSC_EN_OVRD_IN_MPLLB_SSC_EN_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_MISC_OVRD_IN - Override Values for Incoming MPLLB-Related Input Signals */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT (0U)
/*! MPLLB_SSC_FREQ_CNT_PEAK - Override Value for mpllb_ssc_freq_cnt_peak[7:0] */
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_EN_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_EN_SHIFT (8U)
/*! MPLLB_SSC_FREQ_CNT_PEAK_EN - Override Value for mpllb_ssc_freq_cnt_peak
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_SSC_FREQ_CNT_PEAK_EN_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_MASK (0x600U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_SHIFT (9U)
/*! MPLLB_TX_CLK_DIV_OVRD_VAL - Override Value for mpllb_tx_clk_div */
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_MASK)

#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_OVRD_EN_MASK (0x800U)
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_OVRD_EN_SHIFT (11U)
/*! MPLLB_OVRD_EN - Override Enable for mpllb_bandwidth and mpllb_tx_clk_div
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_OVRD_EN_SHIFT)) & ENET_PHY_RAWCMN_DIG_MPLLB_MISC_OVRD_IN_MPLLB_OVRD_EN_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0 - MPLLB Coarse Tune Value for Bank 0 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_BANK_0_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_BANK_0_SHIFT (0U)
/*! MPLLB_COARSE_TUNE_BANK_0 - Stored bank0 coarse tune value for MPLLB */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_BANK_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_BANK_0_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_BANK_0_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_DONE_BANK_0_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_DONE_BANK_0_SHIFT (8U)
/*! MPLLB_COARSE_TUNE_DONE_BANK_0 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_DONE_BANK_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_DONE_BANK_0_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_0_MPLLB_COARSE_TUNE_DONE_BANK_0_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1 - MPLLB Coarse Tune Value for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_BANK_1_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_BANK_1_SHIFT (0U)
/*! MPLLB_COARSE_TUNE_BANK_1 - Stored bank 1 coarse tune value for MPLLB */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_BANK_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_BANK_1_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_BANK_1_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_DONE_BANK_1_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_DONE_BANK_1_SHIFT (8U)
/*! MPLLB_COARSE_TUNE_DONE_BANK_1 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_DONE_BANK_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_DONE_BANK_1_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_1_MPLLB_COARSE_TUNE_DONE_BANK_1_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2 - MPLLB Coarse Tune Value for Bank 2 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_BANK_2_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_BANK_2_SHIFT (0U)
/*! MPLLB_COARSE_TUNE_BANK_2 - Stored bank 2 coarse tune value for MPLLB */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_BANK_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_BANK_2_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_BANK_2_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_DONE_BANK_2_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_DONE_BANK_2_SHIFT (8U)
/*! MPLLB_COARSE_TUNE_DONE_BANK_2 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_DONE_BANK_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_DONE_BANK_2_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_2_MPLLB_COARSE_TUNE_DONE_BANK_2_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3 - MPLLB Coarse Tune Value for Bank 3 */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_BANK_3_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_BANK_3_SHIFT (0U)
/*! MPLLB_COARSE_TUNE_BANK_3 - Stored bank 3 coarse tune value for MPLLB */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_BANK_3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_BANK_3_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_BANK_3_MASK)

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_DONE_BANK_3_MASK (0x100U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_DONE_BANK_3_SHIFT (8U)
/*! MPLLB_COARSE_TUNE_DONE_BANK_3 - Indicates if the coarse tune value is calibrated value
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_DONE_BANK_3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_DONE_BANK_3_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_BANK_3_MPLLB_COARSE_TUNE_DONE_BANK_3_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_CAL_BANK_SEL - Value for MPLLB Bank Select */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_CAL_BANK_SEL_MPLLB_CAL_BANK_SEL_MASK (0x3U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_CAL_BANK_SEL_MPLLB_CAL_BANK_SEL_SHIFT (0U)
/*! MPLLB_CAL_BANK_SEL - Value for MPLL B Bank Select */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_CAL_BANK_SEL_MPLLB_CAL_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_CAL_BANK_SEL_MPLLB_CAL_BANK_SEL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_CAL_BANK_SEL_MPLLB_CAL_BANK_SEL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_DONE - Valid Calibrated Value for MPLLB Calibration Bank */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_DONE_MPLLB_COARSE_TUNE_DONE_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_DONE_MPLLB_COARSE_TUNE_DONE_SHIFT (0U)
/*! MPLLB_COARSE_TUNE_DONE - Indicates if the selected MPLLB calibration bank has the valid calibrated value
 *  0b0..Invalid
 *  0b1..Valid
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_DONE_MPLLB_COARSE_TUNE_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_DONE_MPLLB_COARSE_TUNE_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_DONE_MPLLB_COARSE_TUNE_DONE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_COARSE_TUNE - Selected COARSE TUNE Value for MPLLB */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_MASK (0xFFU)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_SHIFT (0U)
/*! MPLLB_COARSE_TUNE - Selected coarse tune value for MPLLB */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_IN_RECAL - MPLLB Re-Calibration */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_IN_RECAL_MPLLB_IN_RECAL_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_IN_RECAL_MPLLB_IN_RECAL_SHIFT (0U)
/*! MPLLB_IN_RECAL - Indicates if MPLLB is in re-calibration
 *  0b0..Not in re-calibration
 *  0b1..In re-calibration
 */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_IN_RECAL_MPLLB_IN_RECAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_IN_RECAL_MPLLB_IN_RECAL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_IN_RECAL_MPLLB_IN_RECAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_PMA_MPLLB_RECAL_BANK_SEL - Current Bank Selected for MPLLB Coarse Tune in PMA */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLB_RECAL_BANK_SEL_PMA_MPLLB_RECAL_BANK_SEL_MASK (0x3U)
#define ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLB_RECAL_BANK_SEL_PMA_MPLLB_RECAL_BANK_SEL_SHIFT (0U)
/*! PMA_MPLLB_RECAL_BANK_SEL - Current bank selected for MPLLB coarse tune in PMA */
#define ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLB_RECAL_BANK_SEL_PMA_MPLLB_RECAL_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLB_RECAL_BANK_SEL_PMA_MPLLB_RECAL_BANK_SEL_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_PMA_MPLLB_RECAL_BANK_SEL_PMA_MPLLB_RECAL_BANK_SEL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_MPLLB_BANK_SEL_DONE - Status for MPLLB Re-Calibration or Switching */
/*! @{ */

#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_BANK_SEL_DONE_DONE_MASK (0x1U)
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_BANK_SEL_DONE_DONE_SHIFT (0U)
/*! DONE - Status for MPLLB re-calibration or switching */
#define ENET_PHY_RAWCMN_DIG_AON_MPLLB_BANK_SEL_DONE_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWCMN_DIG_AON_MPLLB_BANK_SEL_DONE_DONE_SHIFT)) & ENET_PHY_RAWCMN_DIG_AON_MPLLB_BANK_SEL_DONE_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_LANE_OVRD_IN - Override Values for Incoming LANE Controls from ASIC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_SHIFT (0U)
/*! LANE_TX2RX_SER_LB - Override Value for lane_tx2rx_ser_lb_en_r
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_SHIFT (1U)
/*! LANE_RX2TX_PAR_LB - Override Value for lane_rx2tx_par_lb_en_r
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_SHIFT (2U)
/*! EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_0 - Override Values for Incoming TX Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_CLK_RDY_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_CLK_RDY_SHIFT (0U)
/*! CLK_RDY - Override Value for tx_clk_rdy
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_CLK_RDY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_CLK_RDY_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_CLK_RDY_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RESET_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RESET_SHIFT (1U)
/*! RESET - Override Value for tx_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RESET_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_INVERT_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_INVERT_SHIFT (2U)
/*! INVERT - Override Value for tx_invert
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_INVERT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_INVERT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_INVERT_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_SHIFT (3U)
/*! DATA_EN - Override Value for tx_data_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_SHIFT (4U)
/*! REQ - Override Value for tx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_LPD_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_LPD_SHIFT (5U)
/*! LPD - Override Value for tx_lpd
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_LPD_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_LPD_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_MASK (0xC0U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_SHIFT (6U)
/*! PSTATE - Override Value for tx_pstate[1:0] */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_MASK (0x700U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_SHIFT (8U)
/*! RATE - Override Value for tx_rate[2:0] */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_MASK (0x1800U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_SHIFT (11U)
/*! WIDTH - Override Value for tx_width[1:0] */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_SHIFT (13U)
/*! MPLLB_SEL - Override Value for tx_mpllb_sel
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DETECT_RX_REQ_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DETECT_RX_REQ_SHIFT (14U)
/*! DETECT_RX_REQ - Override Value for tx_detrx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DETECT_RX_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DETECT_RX_REQ_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_DETECT_RX_REQ_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_EN_SHIFT (15U)
/*! EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_0_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_1 - Override Values for Incoming TX Drive Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_SHIFT (0U)
/*! NYQUIST_DATA - Override incoming data to nyquist
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_SHIFT (1U)
/*! DISABLE - Override Value for tx_disable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_SHIFT (2U)
/*! BEACON_EN - Override Value for tx_beacon_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_MASK (0x78U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_SHIFT (3U)
/*! IBOOST_LVL - Override Value for tx_iboost_lvl */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_SHIFT (7U)
/*! VBOOST_EN - Override Value for tx_vboost_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_SHIFT (8U)
/*! EN - Enable override values for inputs below controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_MASK (0x7E00U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_SHIFT (9U)
/*! TX_MAIN_CURSOR - Override Value for tx_eq_main */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_SHIFT (15U)
/*! MAIN_OVRD_EN - Enable override values for TX EQ main input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_2 - Override Values for Incoming TX Drive Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_MASK (0x3FU)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_SHIFT (0U)
/*! TX_PRE_CURSOR - Override Value for tx_eq_pre */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_SHIFT (6U)
/*! PRE_OVRD_EN - Enable override values for TX EQ pre input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_MASK (0x1F80U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_SHIFT (7U)
/*! TX_POST_CURSOR - Override Value for tx_eq_post */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_SHIFT (13U)
/*! POST_OVRD_EN - Enable override values for TX EQ post input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_OUT - Override Values for Outgoing TX Controls to ASIC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_SHIFT (0U)
/*! TX_ACK - Override Value for tx_ack
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_SHIFT (1U)
/*! EN_TX_ACK - Enable for override value for tx_ack
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_SHIFT (2U)
/*! DETRX_RESULT - Override Value for tx_detrx_result
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_SHIFT (3U)
/*! EN_DETRX_RESULT - Enable for override value for tx_detrx_result
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_0 - Override Values for Incoming RX Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESET_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESET_SHIFT (0U)
/*! RESET - Override Value for rx_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESET_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_INVERT_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_INVERT_SHIFT (1U)
/*! INVERT - Override Value for rx_invert
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_INVERT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_INVERT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_INVERT_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_SHIFT (2U)
/*! DATA_EN - Override Value for rx_data_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_SHIFT (3U)
/*! REQ - Override Value for rx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_LPD_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_LPD_SHIFT (4U)
/*! LPD - Override Value for rx_lpd
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_LPD_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_LPD_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_MASK (0x60U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_SHIFT (5U)
/*! PSTATE - Override Value for rx_pstate */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_MASK (0x180U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_SHIFT (7U)
/*! RATE - Override Value for rx_rate */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_MASK (0x600U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_SHIFT (9U)
/*! WIDTH - Override Value for rx_width */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DIV16P5_CLK_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DIV16P5_CLK_EN_SHIFT (11U)
/*! DIV16P5_CLK_EN - Override Value for rx_div16p5_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RX_DFE_BYPASS_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RX_DFE_BYPASS_SHIFT (12U)
/*! RX_DFE_BYPASS - Override Value for rx_dfe_bypass
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RX_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RX_DFE_BYPASS_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_RX_DFE_BYPASS_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_EN_SHIFT (13U)
/*! EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_0_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_1 - Override Values for Incoming RX Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_MASK (0x7FU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_SHIFT (0U)
/*! RX_REF_LD_VAL - Override Value for rx_ref_ld_val[6:0] */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_FREQBAND_1_0_MASK (0x180U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_FREQBAND_1_0_SHIFT (7U)
/*! RX_CDR_VCO_FREQBAND_1_0 - Override Value for rx_cdr_vco_freqband */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_FREQBAND_1_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_FREQBAND_1_0_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_FREQBAND_1_0_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_SHIFT (9U)
/*! EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_TEMP_COMP_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_TEMP_COMP_EN_SHIFT (10U)
/*! RX_CDR_VCO_TEMP_COMP_EN - Override Value for rx_cdr_vco_temp_comp_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_TEMP_COMP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_TEMP_COMP_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_TEMP_COMP_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_STEP_CTRL_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_STEP_CTRL_SHIFT (11U)
/*! RX_CDR_VCO_STEP_CTRL - Override Value for rx_cdr_vco_step_ctrl
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_STEP_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_STEP_CTRL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_STEP_CTRL_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_2 - Override Values for Incoming RX Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_MASK (0x1FFFU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_SHIFT (0U)
/*! RX_VCO_LD_VAL - Override Value for rx_vco_ld_val */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_SHIFT (13U)
/*! EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_3 - Override Values for Incoming RX Controls from ASIC 3 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_SHIFT (0U)
/*! CDR_TRACK_EN - Override Value for rx_cdr_track_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_SHIFT (1U)
/*! CDR_SSC_EN - Override Value for rx_cdr_ssc_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_SHIFT (2U)
/*! ALIGN_EN - Override Value for rx_align_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_SHIFT (3U)
/*! CLK_SHIFT - Override Value for rx_clk_shift
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_SHIFT (4U)
/*! DISABLE - Override Value for rx_disable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_MASK (0xE0U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_SHIFT (5U)
/*! LOS_THRSHLD - Override Value for rx_los_threshold */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_SHIFT (8U)
/*! LOS_LPFS_EN - Override Value for rx_los_lfps_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_EN_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_EN_SHIFT (9U)
/*! TERM_EN - Override Value for rx_term_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_ACDC_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_ACDC_SHIFT (10U)
/*! TERM_ACDC - Override Value for rx_term_acdc
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_ACDC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_ACDC_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_TERM_ACDC_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_EN_SHIFT (11U)
/*! EN - Enable override values for all inputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_IN_3_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0 - Override Values for Incoming RX EQ Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_SHIFT (0U)
/*! EQ_ATT_LVL - Override Value for rx_eq_att_lvl */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA1_GAIN_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA1_GAIN_SHIFT (3U)
/*! EQ_VGA1_GAIN - Override Value for rx_eq_vga1_gain */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA1_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA1_GAIN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA1_GAIN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA2_GAIN_MASK (0x1C0U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA2_GAIN_SHIFT (6U)
/*! EQ_VGA2_GAIN - Override Value for rx_eq_vga2_gain */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA2_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA2_GAIN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_VGA2_GAIN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_MASK (0x3E00U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_SHIFT (9U)
/*! EQ_CTLE_BOOST - Override Value for rx_eq_ctle_boost */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1 - Override Values for Incoming RX EQ Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_CTLE_POLE_MASK (0x3U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_CTLE_POLE_SHIFT (0U)
/*! EQ_CTLE_POLE - Override Value for rx_eq_ctle_pole */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_CTLE_POLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_CTLE_POLE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_CTLE_POLE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_MASK (0x3FCU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_SHIFT (2U)
/*! EQ_DFE_TAP1 - Override Value for rx_eq_dfe_tap1 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_SHIFT (10U)
/*! EQ_OVRD_EN - Enable override value for rx_eq_* inputs
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_OUT_0 - Override Values for Outgoing RX controls to ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_SHIFT (0U)
/*! ACK - Override Value for rx_ack
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_SHIFT (1U)
/*! LOS - Override Value for rx_los
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_MASK (0xCU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_SHIFT (2U)
/*! ADAPT_STS - Override Value for rx_adapt_sts */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_EN_CTL_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_EN_CTL_SHIFT (4U)
/*! EN_CTL - Enable override values for all control outputs of this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_EN_CTL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_OUT_0_EN_CTL_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_LANE_ASIC_IN - Current Values for Incoming LANE Controls from ASIC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_SHIFT (0U)
/*! LANE_TX2RX_SER_LB - Value from ASIC for lane_tx2rx_ser_lb_en_r */
#define ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_SHIFT (1U)
/*! LANE_RX2TX_PAR_LB - Value from ASIC for lane_rx2tx_par_lb_en_r */
#define ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_IN_0 - Current Values for Incoming TX Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_SHIFT (0U)
/*! CLK_RDY - Value from ASIC for tx_clk_rdy */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_SHIFT (1U)
/*! RESET - Value from ASIC for tx_reset */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_SHIFT (2U)
/*! INVERT - Value from ASIC for tx_invert */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_SHIFT (3U)
/*! DATA_EN - Value from ASIC for tx_data_en */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_SHIFT (4U)
/*! REQ - Value from ASIC for tx_req */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_SHIFT (5U)
/*! LPD - Value from ASIC for tx_lpd */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_MASK (0xC0U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_SHIFT (6U)
/*! PSTATE - Value from ASIC for tx_pstate[1:0] */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_MASK (0x700U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_SHIFT (8U)
/*! RATE - Value from ASIC for tx_rate[2:0] */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_MASK (0x1800U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_SHIFT (11U)
/*! WIDTH - Value from ASIC for tx_width[1:0] */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_SHIFT (13U)
/*! MPLLB_SEL - Value from ASIC for tx_mpllb_sel */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_SHIFT (14U)
/*! DETECT_RX_REQ - Value from ASIC for tx_detrx_req */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_SHIFT (15U)
/*! DISABLE - Value from ASIC for tx_disable */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_IN_1 - Current Values for Incoming TX Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_SHIFT (0U)
/*! BEACON_EN - Value from ASIC for tx_beacon_en */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_MASK (0x1EU)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_SHIFT (1U)
/*! IBOOST_LVL - Value from ASIC for tx_iboost_lvl */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_SHIFT (5U)
/*! VBOOST_EN - Value from ASIC for tx_vboost_en */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_MASK (0xFC0U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_SHIFT (6U)
/*! TX_MAIN_CURSOR - Value from ASIC for tx_eq_main */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_IN_2 - Current Values for Incoming TX Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_MASK (0x3FU)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_SHIFT (0U)
/*! TX_PRE_CURSOR - Value from ASIC for tx_eq_pre */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_MASK (0xFC0U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_SHIFT (6U)
/*! TX_POST_CURSOR - Value from ASIC for tx_eq_post */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_OUT - Current Values for Outgoing TX Status Controls from PHY */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_SHIFT (0U)
/*! TX_ACK - Value from PHY for tx_ack */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_SHIFT (1U)
/*! DETRX_RESULT - Value from PHY for tx_detrx_result */
#define ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_ASIC_IN_0 - Current Values for Incoming RX Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_SHIFT (0U)
/*! RESET - Value from ASIC for rx_reset */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_SHIFT (1U)
/*! INVERT - Value from ASIC for rx_invert */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_SHIFT (2U)
/*! DATA_EN - Value from ASIC for rx_data_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_SHIFT (3U)
/*! REQ - Value from ASIC for rx_req */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_SHIFT (4U)
/*! LPD - Value from ASIC for rx_lpd */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_MASK (0x60U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_SHIFT (5U)
/*! PSTATE - Value from ASIC for rx_pstate */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_MASK (0x180U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_SHIFT (7U)
/*! RATE - Value from ASIC for rx_rate */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_MASK (0x600U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_SHIFT (9U)
/*! WIDTH - Value from ASIC for rx_width */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DIV16P5_CLK_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DIV16P5_CLK_EN_SHIFT (11U)
/*! DIV16P5_CLK_EN - Value from ASIC for rx_div16p5_clk_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RX_DFE_BYPASS_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RX_DFE_BYPASS_SHIFT (12U)
/*! RX_DFE_BYPASS - Value from ASIC for rx_dfe_bypass */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RX_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RX_DFE_BYPASS_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_RX_DFE_BYPASS_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_SHIFT (13U)
/*! CDR_TRACK_EN - Value from ASIC for rx_cdr_track_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_ASIC_IN_1 - Current Values for Incoming RX Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_SHIFT (0U)
/*! CDR_SSC_EN - Value from ASIC for rx_cdr_ssc_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_SHIFT (1U)
/*! ALIGN_EN - Value from ASIC for rx_align_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_SHIFT (2U)
/*! CLK_SHIFT - Value from ASIC for rx_clk_shift */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_SHIFT (3U)
/*! DISABLE - Value from ASIC for rx_disable */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_MASK (0x70U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_SHIFT (4U)
/*! LOS_THRSHLD - Value from ASIC for rx_los_threshold */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_SHIFT (7U)
/*! LOS_LPFS_EN - Value from ASIC for rx_los_lfps_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_SHIFT (8U)
/*! RX_TERM_EN - Value from ASIC for rx_term_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_SHIFT (9U)
/*! RX_TERM_ACDC - Value from ASIC for rx_term_acdc */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0 - Current Values for Incoming RX EQ Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_SHIFT (0U)
/*! EQ_ATT_LVL - Value from ASIC for rx_eq_att_lvl */
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA1_GAIN_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA1_GAIN_SHIFT (3U)
/*! EQ_VGA1_GAIN - Value from ASIC for rx_eq_vga1_gain */
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA1_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA1_GAIN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA1_GAIN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA2_GAIN_MASK (0x1C0U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA2_GAIN_SHIFT (6U)
/*! EQ_VGA2_GAIN - Value from ASIC for rx_eq_vga2_gain */
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA2_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA2_GAIN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_VGA2_GAIN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_MASK (0x3E00U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_SHIFT (9U)
/*! EQ_CTLE_BOOST - Value from ASIC for rx_eq_ctle_boost */
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1 - Current Values for Incoming RX EQ Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_CTLE_POLE_MASK (0x3U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_CTLE_POLE_SHIFT (0U)
/*! EQ_CTLE_POLE - Value from ASIC for rx_eq_ctle_pole */
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_CTLE_POLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_CTLE_POLE_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_CTLE_POLE_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_MASK (0x3FCU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_SHIFT (2U)
/*! EQ_DFE_TAP1 - Value from ASIC for rx_eq_dfe_tap1 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0 - Current Values for Incoming RX CDR VCO Controls from ASIC 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_TEMP_COMP_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_TEMP_COMP_EN_SHIFT (0U)
/*! RX_CDR_VCO_TEMP_COMP_EN - Value from ASIC for rx_cdr_vco_temp_comp_en */
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_TEMP_COMP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_TEMP_COMP_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_TEMP_COMP_EN_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_STEP_CTRL_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_STEP_CTRL_SHIFT (1U)
/*! RX_CDR_VCO_STEP_CTRL - Value from ASIC for rx_cdr_vco_step_ctrl */
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_STEP_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_STEP_CTRL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_STEP_CTRL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_FREQBAND_MASK (0xCU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_FREQBAND_SHIFT (2U)
/*! RX_CDR_VCO_FREQBAND - Value from ASIC for rx_cdr_vco_freqband */
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_FREQBAND(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_FREQBAND_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_FREQBAND_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_MASK (0x7F0U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_SHIFT (4U)
/*! RX_REF_LD_VAL - Value from ASIC for rx_ref_ld_val */
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1 - Current Values for Incoming RX CDR VCO Controls from ASIC 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_MASK (0x1FFFU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_SHIFT (0U)
/*! RX_VCO_LD_VAL - Value from ASIC for rx_vco_ld_val */
#define ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_ASIC_OUT_0 - Current Values for Outgoing RX Status Controls from PHY 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_SHIFT (0U)
/*! ACK - Value from PHY for rx_ack */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_SHIFT (1U)
/*! LOS - Value from PHY for rx_los */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_SHIFT (2U)
/*! VALID - Value from PHY for rx_valid */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_MASK (0x18U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_SHIFT (3U)
/*! ADAPT_STS - Value from PHY for rx_adapt_sts */
#define ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2 - Override Values for Incoming RX EQ Controls from ASIC 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP2_MASK (0x7FU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP2_SHIFT (0U)
/*! EQ_DFE_TAP2 - Override Value for rx_eq_dfe_tap2 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP2_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP2_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP3_MASK (0x3F80U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP3_SHIFT (7U)
/*! EQ_DFE_TAP3 - Override Value for rx_eq_dfe_tap3 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP3_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_2_EQ_DFE_TAP3_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3 - Override Values for Incoming RX EQ Controls from ASIC 3 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP4_MASK (0x7FU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP4_SHIFT (0U)
/*! EQ_DFE_TAP4 - Override Value for rx_eq_dfe_tap4 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP4(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP4_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP4_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP5_MASK (0x3F80U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP5_SHIFT (7U)
/*! EQ_DFE_TAP5 - Override Value for rx_eq_dfe_tap5 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP5_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_3_EQ_DFE_TAP5_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_MISC - Override Values for Incoming TX MISC BUS from ASIC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_VAL_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_VAL_SHIFT (0U)
/*! TX_MISC_OVRD_VAL - Override Value for tx_misc[7:0] */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_VAL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_EN_SHIFT (8U)
/*! TX_MISC_OVRD_EN - Override Enable for tx_misc[7:0]
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_TX_OVRD_MISC_TX_MISC_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_MISC - Override Values for Incoming RX MISC BUS from ASIC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_VAL_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_VAL_SHIFT (0U)
/*! RX_MISC_OVRD_VAL - Override Value for rx_misc[7:0] */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_VAL_MASK)

#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_EN_SHIFT (8U)
/*! RX_MISC_OVRD_EN - Override Enable for rx_misc[7:0]
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ASIC_RX_OVRD_MISC_RX_MISC_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0 - TX Power State Control for P0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P0_ANA_REFGEN_EN - Value of TX ANA refgen_en in P0 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P0_ANA_VCM_HOLD - Value of TX ANA vcm_hold in P0 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_SHIFT (2U)
/*! TX_P0_ANA_CLK_EN - Value of TX ANA clk_en in P0 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P0_ANA_WORD_CLK_EN - Value of TX ANA word_clk_en in P0 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_SHIFT (4U)
/*! TX_P0_ANA_RESET - Value of TX ANA reset in P0 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P0_ANA_SERIAL_EN - Value of TX ANA serial_en in P0 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_SHIFT (6U)
/*! TX_P0_DIG_CLK_EN - Enable/Disable TX digital clocks in P0
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_SHIFT (7U)
/*! TX_P0_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_SHIFT (8U)
/*! TX_P0_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S - TX Power State Control for P0S */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P0S_ANA_REFGEN_EN - Value of TX ANA refgen_en in P0S */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P0S_ANA_VCM_HOLD - Value of TX ANA vcm_hold in P0S */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_SHIFT (2U)
/*! TX_P0S_ANA_CLK_EN - Value of TX ANA clk_en in P0S */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P0S_ANA_WORD_CLK_EN - Value of TX ANA word_clk_en in P0S */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_SHIFT (4U)
/*! TX_P0S_ANA_RESET - Value of TX ANA reset in P0S */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P0S_ANA_SERIAL_EN - Value of TX ANA serial_en in P0S */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_SHIFT (6U)
/*! TX_P0S_DIG_CLK_EN - Enable/Disable TX digital clocks in P0S
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_SHIFT (7U)
/*! TX_P0S_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_SHIFT (8U)
/*! TX_P0S_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0S */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1 - TX Power State Control for P1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P1_ANA_REFGEN_EN - Value of TX ANA refgen_en in P1 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P1_ANA_VCM_HOLD - Value of TX ANA vcm_hold in P1 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_SHIFT (2U)
/*! TX_P1_ANA_CLK_EN - Value of TX ANA clk_en in P1 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P1_ANA_WORD_CLK_EN - Value of TX ANA word_clk_en in P1 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_SHIFT (4U)
/*! TX_P1_ANA_RESET - Value of TX ANA reset in P1 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P1_ANA_SERIAL_EN - Value of TX ANA serial_en in P1 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_SHIFT (6U)
/*! TX_P1_DIG_CLK_EN - Enable/Disable TX digital clocks in P1
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_SHIFT (7U)
/*! TX_P1_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_SHIFT (8U)
/*! TX_P1_ALLOW_RXDET - If asserted, then rxdet request is allowed in P1 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2 - TX Power State Control for P2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P2_ANA_REFGEN_EN - Value of TX ANA refgen_en in P2 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P2_ANA_VCM_HOLD - Value of TX ANA vcm_hold in P2 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_SHIFT (2U)
/*! TX_P2_ANA_CLK_EN - Value of TX ANA clk_en in P2 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P2_ANA_WORD_CLK_EN - Value of TX ANA word_clk_en in P2 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_SHIFT (4U)
/*! TX_P2_ANA_RESET - Value of TX ANA reset in P2 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P2_ANA_SERIAL_EN - Value of TX ANA serial_en in P2 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_SHIFT (6U)
/*! TX_P2_DIG_CLK_EN - Enable/Disable TX digital clocks in P2
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_SHIFT (7U)
/*! TX_P2_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_SHIFT (8U)
/*! TX_P2_ALLOW_RXDET - If asserted, then rxdet request is allowed */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0 - TX Power UP Time 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_SHIFT (0U)
/*! TX_REFGEN_EN_TIME - Power up time (in ref_range cycles) for TX ANA refgen enable (spec: >= 1 us) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_MASK (0xFF00U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_SHIFT (8U)
/*! TX_CLK_EN - Power up time (in ref_range cycles) for TX ANA clock enable (spec: >= 1 us) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1 - TX Power UP Time 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_SHIFT (0U)
/*! TX_VCM_HOLD_TIME - Power up time (in ref_range cycles) for TX ANA vreg enable (spec: >= 800 us) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_SHIFT (15U)
/*! SKIP_TX_VCM_HOLD_WAIT - Skip wait for TX common mode hold power up
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2 - TX Power UP Time 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_MASK (0x1FFFU)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_SHIFT (0U)
/*! TX_VBOOST_DIS_TIME - TX vboost disable time (in ref_range cycles) (spec: >= 160 us) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_MASK (0xE000U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_SHIFT (13U)
/*! DTB_SEL - Selects data to drive on DTB
 *  0b000..Disabled
 *  0b001..tx_ack and tx_pwrsm_state[0]
 *  0b010..tx_ana_rxdetp_result_i, tx_ana_rxdetm_result_i
 *  0b011..tx_ana_reset_i, tx_ana_clk_en_i
 *  0b100..Analog/ASIC clocks
 *  0b101..ASIC early signal / clock aligner shift
 *  0b110..tx_clk_state counter / lbert strobe
 *  0b111..ref_dig_rst/tx_dig_rst
 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3 - TX Power UP Time 3 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RXDET_TIME_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RXDET_TIME_SHIFT (0U)
/*! TX_RXDET_TIME - RX Detect up time (in ref_range cycles), starting from asserting rxdet_en (spec: 12 us < time < 26 us) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RXDET_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RXDET_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RXDET_TIME_MASK)

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RESET_TIME_MASK (0x1800U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RESET_TIME_SHIFT (11U)
/*! TX_RESET_TIME - TX Reset deassertion time (in ref_range cycles) (spec: >= 50 ns) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RESET_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RESET_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_RESET_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4 - TX Power UP Time 4 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_SERIAL_EN_TIME_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_SERIAL_EN_TIME_SHIFT (0U)
/*! TX_SERIAL_EN_TIME - Power up time (in ref_range cycles) for TX ANA serial enable (spec: 130 ns < time < 1 us) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_SERIAL_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_SERIAL_EN_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_SERIAL_EN_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_FIFO_BYPASS - TX FIFO Bypass */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_FIFO_BYPASS_TX_FIFO_BYPASS_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_FIFO_BYPASS_TX_FIFO_BYPASS_SHIFT (0U)
/*! TX_FIFO_BYPASS - Bypass TX datapath FIFO
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_FIFO_BYPASS_TX_FIFO_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_FIFO_BYPASS_TX_FIFO_BYPASS_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_FIFO_BYPASS_TX_FIFO_BYPASS_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5 - TX Power UP Time 4 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_VCM_HOLD_GS_TIME_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_VCM_HOLD_GS_TIME_SHIFT (0U)
/*! TX_VCM_HOLD_GS_TIME - TX common mode gear-shift time (in ref range cycles) (spec: >= 400 us) */
#define ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_VCM_HOLD_GS_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_VCM_HOLD_GS_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_VCM_HOLD_GS_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_LBERT_CTL - Pattern Generator Controls */
/*! @{ */

#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_MODE_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_MODE_SHIFT (0U)
/*! MODE - Pattern to Generate
 *  0b0000..Disabled
 *  0b0001..lfsr31: X^31 + X^28 + 1
 *  0b0010..lfsr23: X^23 + X^18 + 1
 *  0b0011..lfsr23: x^23 + x^21 + x^16 + x^8 + x^5 + x^2 + 1
 *  0b0100..lfsr16: x^16 + x^5 + x^4 + x^3 + 1
 *  0b0101..lfsr15: X^15 + X^14 + 1
 *  0b0110..lfsr11: X^11 + X^9 + 1
 *  0b0111..lfsr9: X^9 + X^5 + 1
 *  0b1000..lfsr7: X^7 + X^6 + 1
 *  0b1001..Fixed word (PAT0)
 *  0b1010..DC balanced word (PAT0, ~PAT0)
 *  0b1011..Fixed pattern: (000, PAT0, 3ff, ~PAT0)
 */
#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_MODE(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_LBERT_CTL_MODE_SHIFT)) & ENET_PHY_LANE0_DIG_TX_LBERT_CTL_MODE_MASK)

#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_SHIFT (4U)
/*! TRIGGER_ERR - Insert a Single Error into a lsb */
#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_SHIFT)) & ENET_PHY_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_MASK)

#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_PAT0_MASK (0x7FE0U)
#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_PAT0_SHIFT (5U)
/*! PAT0 - Pattern for modes 3-5 */
#define ENET_PHY_LANE0_DIG_TX_LBERT_CTL_PAT0(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_TX_LBERT_CTL_PAT0_SHIFT)) & ENET_PHY_LANE0_DIG_TX_LBERT_CTL_PAT0_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0 - RX Power State Control for P0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_SHIFT (0U)
/*! RX_P0_ANA_LOS_EN - Value of RX ANA los_en in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_SHIFT (1U)
/*! RX_P0_ANA_AFE_EN - Value of RX ANA afe_en in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P0_ANA_CLK_VREG_EN - Value of RX ANA clk_vreg_en in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DIV16P5_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DIV16P5_CLK_EN_SHIFT (3U)
/*! RX_P0_ANA_DIV16P5_CLK_EN - Value of RX ANA div16p5_clk_en in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_SHIFT (4U)
/*! RX_P0_ANA_CLK_EN - Value of RX ANA clk_en in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P0_ANA_CLK_DCC_EN - Value of RX ANA CLK_DCC_EN in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_SHIFT (6U)
/*! RX_P0_ANA_DESER_EN - Value of RX ANA deserial_en in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_SHIFT (7U)
/*! RX_P0_ANA_CDR_EN - Value of RX ANA cdr_en in P0 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P0_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P0
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_SHIFT (9U)
/*! RX_P0_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P0
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P0_VCO_CONTCAL_EN - Enable/Disable continuous calibration of the RX VCO in P0 If
 *    RX_P0_DIG_CLK_EN and the top-level rx_data_en are both asserted, then continuous calibration is turned off
 *    and this value is ignored
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_SHIFT (11U)
/*! RX_P0_DIG_CLK_EN - Enable/Disable RX digital clocks in P0
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_FORCE_DFE_BYPASS_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_FORCE_DFE_BYPASS_SHIFT (12U)
/*! RX_P0_FORCE_DFE_BYPASS - Enable/Disable RX DFE in P0
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_FORCE_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_FORCE_DFE_BYPASS_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_FORCE_DFE_BYPASS_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S - RX Power State Control for P0S */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_SHIFT (0U)
/*! RX_P0S_ANA_LOS_EN - Value of RX ANA los_en in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_SHIFT (1U)
/*! RX_P0S_ANA_AFE_EN - Value of RX ANA afe_en in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P0S_ANA_CLK_VREG_EN - Value of RX ANA clk_vreg_en in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DIV16P5_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DIV16P5_CLK_EN_SHIFT (3U)
/*! RX_P0S_ANA_DIV16P5_CLK_EN - Value of RX ANA div16p5_clk_en in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_SHIFT (4U)
/*! RX_P0S_ANA_CLK_EN - Value of RX ANA clk_en in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P0S_ANA_CLK_DCC_EN - Value of RX ANA CLK_DCC_EN in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_SHIFT (6U)
/*! RX_P0S_ANA_DESER_EN - Value of RX ANA deserial_en in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_SHIFT (7U)
/*! RX_P0S_ANA_CDR_EN - Value of RX ANA cdr_en in P0S */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P0S_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P0S
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_SHIFT (9U)
/*! RX_P0S_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P0S
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P0S_VCO_CONTCAL_EN - Enable/Disable continuous calibration of the RX VCO in P0S If
 *    RX_P0S_DIG_CLK_EN and the top-level rx_data_en are both asserted, then continuous calibration is turned
 *    off and this value is ignored
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_SHIFT (11U)
/*! RX_P0S_DIG_CLK_EN - Enable/Disable RX digital clocks in P0S
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0s_FORCE_DFE_BYPASS_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0s_FORCE_DFE_BYPASS_SHIFT (12U)
/*! RX_P0s_FORCE_DFE_BYPASS - Enable/Disable RX DFE in P0s
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0s_FORCE_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0s_FORCE_DFE_BYPASS_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0s_FORCE_DFE_BYPASS_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1 - RX Power State Control for P1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_SHIFT (0U)
/*! RX_P1_ANA_LOS_EN - Value of RX ANA los_en in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_SHIFT (1U)
/*! RX_P1_ANA_AFE_EN - Value of RX ANA afe_en in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P1_ANA_CLK_VREG_EN - Value of RX ANA clk_vreg_en in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DIV16P5_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DIV16P5_CLK_EN_SHIFT (3U)
/*! RX_P1_ANA_DIV16P5_CLK_EN - Value of RX ANA div16p5_clk_en in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_SHIFT (4U)
/*! RX_P1_ANA_CLK_EN - Value of RX ANA clk_en in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P1_ANA_CLK_DCC_EN - Value of RX ANA CLK_DCC_EN in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_SHIFT (6U)
/*! RX_P1_ANA_DESER_EN - Value of RX ANA deserial_en in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_SHIFT (7U)
/*! RX_P1_ANA_CDR_EN - Value of RX ANA cdr_en in P1 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P1_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P1
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_SHIFT (9U)
/*! RX_P1_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P1
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P1_VCO_CONTCAL_EN - Enable/Disable continuous calibration of the RX VCO in P1 If
 *    RX_P1_DIG_CLK_EN and the top-level rx_data_en are both asserted, then continuous calibration is turned off
 *    and this value is ignored
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_SHIFT (11U)
/*! RX_P1_DIG_CLK_EN - Enable/Disable RX digital clocks in P1
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_FORCE_DFE_BYPASS_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_FORCE_DFE_BYPASS_SHIFT (12U)
/*! RX_P1_FORCE_DFE_BYPASS - Enable/Disable RX DFE in P1
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_FORCE_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_FORCE_DFE_BYPASS_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_FORCE_DFE_BYPASS_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2 - RX Power State Control for P2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_SHIFT (0U)
/*! RX_P2_ANA_LOS_EN - Value of RX ANA los_en in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_SHIFT (1U)
/*! RX_P2_ANA_AFE_EN - Value of RX ANA afe_en in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P2_ANA_CLK_VREG_EN - Value of RX ANA clk_vreg_en in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DIV16P5_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DIV16P5_CLK_EN_SHIFT (3U)
/*! RX_P2_ANA_DIV16P5_CLK_EN - Value of RX ANA div16p5_clk_en in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_SHIFT (4U)
/*! RX_P2_ANA_CLK_EN - Value of RX ANA clk_en in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P2_ANA_CLK_DCC_EN - Value of RX ANA CLK_DCC_EN in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_SHIFT (6U)
/*! RX_P2_ANA_DESER_EN - Value of RX ANA deserial_en in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_SHIFT (7U)
/*! RX_P2_ANA_CDR_EN - Value of RX ANA cdr_en in P2 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P2_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P2
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_SHIFT (9U)
/*! RX_P2_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P2
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P2_VCO_CONTCAL_EN - Enable/Disable continuous calibration of the RX VCO in P2 If
 *    RX_P2_DIG_CLK_EN and the top-level rx_data_en are both asserted, then continuous calibration is turned off
 *    and this value is ignored
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_SHIFT (11U)
/*! RX_P2_DIG_CLK_EN - Enable/Disable RX digital clocks in P2
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_FORCE_DFE_BYPASS_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_FORCE_DFE_BYPASS_SHIFT (12U)
/*! RX_P2_FORCE_DFE_BYPASS - Enable/Disable RX DFE in P2
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_FORCE_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_FORCE_DFE_BYPASS_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_FORCE_DFE_BYPASS_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0 - RX Power UP Time 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_SHIFT (0U)
/*! RX_LOS_EN_TIME - Power up time (in ref_range cycles) for RX ANA los enable (spec >= 1.1 us) */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_FAST_RX_LOS_EN_WAIT_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_FAST_RX_LOS_EN_WAIT_SHIFT (10U)
/*! FAST_RX_LOS_EN_WAIT - Enable fast wait for RX LOS enable (simulation only)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_FAST_RX_LOS_EN_WAIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_FAST_RX_LOS_EN_WAIT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_FAST_RX_LOS_EN_WAIT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1 - RX Power UP Time 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_RATE_TIME_MASK (0x3U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_RATE_TIME_SHIFT (0U)
/*! RX_RATE_TIME - Power up time (in ref_range cycles) for RX ANA rate or width change */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_RATE_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_RATE_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_RATE_TIME_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_MASK (0x1FCU)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_SHIFT (2U)
/*! RX_VREG_EN_TIME - Power up time (in ref_range cycles divided by 2) for RX ANA vreg enable (spec > 2 us) */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2 - RX Power UP Time 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CDR_EN_TIME_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CDR_EN_TIME_SHIFT (0U)
/*! RX_CDR_EN_TIME - Power up time (in ref_range cycles) for RX ANA CDR (or dfe/dfe_taps) enable (spec 200 ns) */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CDR_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CDR_EN_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CDR_EN_TIME_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_EN_TIME_MASK (0x60U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_EN_TIME_SHIFT (5U)
/*! RX_DESER_EN_TIME - Power up time (in ref_range cycles) for RX ANA deserial enable */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_EN_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_EN_TIME_MASK)

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_DIS_TIME_MASK (0x180U)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_DIS_TIME_SHIFT (7U)
/*! RX_DESER_DIS_TIME - Power down time in (ref_range cycles) for RX ANA deserial enable */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_DIS_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_DIS_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_DESER_DIS_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3 - RX Power UP Control 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CLK_DCC_EN_TIME_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CLK_DCC_EN_TIME_SHIFT (0U)
/*! RX_CLK_DCC_EN_TIME - Power up time (in ref_range cycles) for RX ANA clk dcc enable (spec > 1 us) */
#define ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CLK_DCC_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CLK_DCC_EN_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CLK_DCC_EN_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0 - RX VCO Calibration Controls 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_SHIFT (0U)
/*! INT_GAIN_CAL_BOUNCE_CNT - Number of bounces (i.e. direction changes) on the int_gain code before indicating that the RX VCO calibration is done */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1 - RX VCO Calibration Controls 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_SHIFT (0U)
/*! RX_VCO_OVRD_SEL - Override the calibration Controls from the RX PWRSM
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_SHIFT (1U)
/*! RX_VCO_FREQ_RST - Override Value for the frequency reset from the RX PWRSM
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_SHIFT (2U)
/*! RX_VCO_CAL_RST - Override Value for the calibration reset from the RX PWRSM
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_SHIFT (3U)
/*! RX_VCO_CONTCAL_EN - Override Value for the continuous calibration enable from the RX PWRSM
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_SHIFT (4U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_MASK (0x1E0U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_SHIFT (5U)
/*! DPLL_CAL_UG - DPLL Calibration Update on int_gain code
 *  0b0000..0
 *  *..(1/16)*2^(DPLL_CAL_UG-1) LSB/update
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_MASK (0xFE00U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_SHIFT (9U)
/*! DTB_SEL - DTB Select for RX VCO DTB Signals
 *  0b0000001..{chkfrq_en, ref_dig_clk}
 *  0b0000010..{rx_ana_cdr_vco_en_i, rx_ana_cdr_startup_i}
 *  0b0000100..{rx_vco_up, dpll_freq_rst}
 *  0b0001000..{rx_vco_contcal_en, rx_vco_cal_rst}
 *  0b0010000..{chkfrq_done, vcoclk_too_fast}
 *  0b0100000..{cal_dir, rx_vco_cal_done}
 *  0b1000000..{curr_state[0], rx_vco_cnt[0]}
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2 - RX VCO Calibration Controls 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_START_VAL_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_START_VAL_SHIFT (0U)
/*! FREG_TUNE_START_VAL - Starting value of freq tune code */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_START_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_START_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_START_VAL_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_CAL_STEPS_MASK (0x3C00U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_CAL_STEPS_SHIFT (10U)
/*! FREG_TUNE_CAL_STEPS - Number of cal steps of freq tune */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_CAL_STEPS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_CAL_STEPS_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREG_TUNE_CAL_STEPS_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0 - RX Power UP Time 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_SHIFT (0U)
/*! RX_VCO_UPDATE_TIME - Settle time in (ref_range cycles) for RX ANA VCO update (freq_tune or int_gain) (spec > 350 ns) */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_MASK (0xFF0U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_SHIFT (4U)
/*! RX_VCO_CNTR_PWRUP_TIME - Power up time for RX ANA VCO counter (spec: > 2 us) */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_SHIFT (12U)
/*! FAST_RX_VCO_WAIT - Enable fast RX VCO wait times (simulation only)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1 - RX Power UP Time 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_SHIFT (0U)
/*! RX_VCO_CNTR_SETTLE_TIME - RX VCO counter value settling time in (ref_dig_clk cycles) (spec: 1 ref_dig_clk cycle) */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_FAST_RX_VCO_CAL_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_FAST_RX_VCO_CAL_SHIFT (3U)
/*! FAST_RX_VCO_CAL - Enable fast RX VCO calibration (skips calibration) (simulation only)
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_FAST_RX_VCO_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_FAST_RX_VCO_CAL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_FAST_RX_VCO_CAL_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_STARTUP_TIME_MASK (0x7F0U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_STARTUP_TIME_SHIFT (4U)
/*! RX_VCO_STARTUP_TIME - Power up time in ref_range cycles for RX ANA VCO startup (spec > 250 ns) */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_STARTUP_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_STARTUP_TIME_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_STARTUP_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0 - RX VCO Status 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT (0U)
/*! RX_ANA_CDR_FREQ_TUNE - Current value of rx_ana_cdr_freq_tune_i */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_SHIFT (10U)
/*! RX_ANA_VCO_CNTR_PD - Current value of rx_ana_vco_cntr_pd_i */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_SHIFT (11U)
/*! RX_ANA_VCO_CNTR_EN - Current value of rx_ana_vco_cntr_en_i */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_SHIFT (12U)
/*! RX_ANA_CDR_STARTUP - Current value of rx_ana_cdr_startup_i */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_SHIFT (13U)
/*! RX_ANA_CDR_VCO_EN - Current value of rx_ana_cdr_vco_en_i */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CLK_EN_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CLK_EN_SHIFT (14U)
/*! RX_ANA_CLK_EN - Current value of rx_ana_clk_en_i */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CLK_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1 - RX VCO Status 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_SHIFT (0U)
/*! RX_VCO_FSM_STATE - Value of the RX VCO CAL FSM */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_SHIFT (4U)
/*! RX_VCO_FREQ_RST - Value of the RX VCO frequency reset from the RX PWRSM */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_SHIFT (5U)
/*! RX_VCO_CAL_RST - Value of the calibration reset from the RX PWRSM */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_SHIFT (6U)
/*! RX_VCO_CONTCAL_EN - Value of the continuous calibration enable from the RX PWRSM */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_SHIFT (7U)
/*! RX_VCO_CAL_DONE - Indicates that the RX VCO has completed calibration
 *  0b0..Not completed
 *  0b1..Completed
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_SHIFT (8U)
/*! DPLL_FREQ_RST - Indicates that the RX integral frequency is reset or not
 *  0b0..Not reset
 *  0b1..Reset
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2 - RX VCO Status 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_MASK (0x1FFFU)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_SHIFT (0U)
/*! VCO_CNTR_FINAL - Value of RX VCO counter when refclk counter expired */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_SHIFT (13U)
/*! VCOCLK_TOO_FAST - Indicates that the RX VCO clock frequency is too fast
 *  0b0..Not too fast
 *  0b1..Too fast
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_SHIFT (14U)
/*! RX_VCO_CORRECT - Indicates that the RX VCO clock has the correct frequency
 *  0b0..Incorrect
 *  0b1..Correct
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_MASK)

#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_SHIFT (15U)
/*! RX_VCO_UP - Indicates that the RX VCO is ready
 *  0b0..Not ready
 *  0b1..Ready
 */
#define ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_SHIFT)) & ENET_PHY_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_LBERT_CTL - Pattern Matcher Controls */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_LBERT_CTL_MODE_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_LBERT_CTL_MODE_SHIFT (0U)
/*! MODE - Pattern to Match
 *  0b0000..Disabled
 *  0b0001..lfsr31: X^31 + X^28 + 1
 *  0b0010..lfsr23: X^23 + X^18 + 1
 *  0b0011..lfsr23: x^23 + x^21 + x^16 + x^8 + x^5 + x^2 + 1
 *  0b0100..lfsr16: x^16 + x^5 + x^4 + x^3 + 1
 *  0b0101..lfsr15: X^15 + X^14 + 1
 *  0b0110..lfsr11: X^11 + X^9 + 1
 *  0b0111..lfsr9: X^9 + X^5 + 1
 *  0b1000..lfsr7: X^7 + X^6 + 1
 *  0b1001..d[n] = d[n-10]
 *  0b1010..d[n] = !d[n-10]
 *  0b1011..d[n] = !d[n-20]
 */
#define ENET_PHY_LANE0_DIG_RX_LBERT_CTL_MODE(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_LBERT_CTL_MODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_LBERT_CTL_MODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_LBERT_CTL_SYNC_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_LBERT_CTL_SYNC_SHIFT (4U)
/*! SYNC - Synchronize Pattern Matcher LFSR with Incoming Data */
#define ENET_PHY_LANE0_DIG_RX_LBERT_CTL_SYNC(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_LBERT_CTL_SYNC_SHIFT)) & ENET_PHY_LANE0_DIG_RX_LBERT_CTL_SYNC_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_LBERT_ERR - Pattern Match Error Counter */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_LBERT_ERR_COUNT_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_LBERT_ERR_COUNT_SHIFT (0U)
#define ENET_PHY_LANE0_DIG_RX_LBERT_ERR_COUNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_LBERT_ERR_COUNT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_LBERT_ERR_COUNT_MASK)

#define ENET_PHY_LANE0_DIG_RX_LBERT_ERR_OV14_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_LBERT_ERR_OV14_SHIFT (15U)
#define ENET_PHY_LANE0_DIG_RX_LBERT_ERR_OV14(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_LBERT_ERR_OV14_SHIFT)) & ENET_PHY_LANE0_DIG_RX_LBERT_ERR_OV14_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_0 - Control Bits for Receiver in Recovered Domain */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_MASK (0x3U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_SHIFT (0U)
/*! PHDET_EN - Enable Phase Detector */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_MASK (0xCU)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_SHIFT (2U)
/*! PHDET_EDGE - Edges to Use for Phase Detection
 *  0b10..Use both edges
 *  0b01..Use rising edges only
 *  0b11..Use falling edges only
 *  0b00..Ignore all edges
 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_SHIFT (4U)
/*! PHDET_POL - Reverse polarity of phase error
 *  0b0..No reverse
 *  0b1..Reverse
 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_SHIFT (5U)
/*! PHDET_EN_PR_MODE - Enable partial response phase detector mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_SHIFT (6U)
/*! ALWAYS_REALIGN - Realign on any misaligned comma */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_MASK (0x780U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_SHIFT (7U)
/*! DTB_SEL - Select to Drive Various Signals onto the DTB
 *  0b0000..Disabled
 *  0b0001..rx_pr_stable, rx_afe_stable from rx_ana_ctl
 *  0b0010..com_good, com_bad from rx_align
 *  0b0011..shift_in_prog, ana_odd_data from rx_align
 *  0b0110..error_high, low from lbert_pm
 *  0b0111..ana_los, los_filter from los block
 *  0b1000..eios_state[0], eios_det from los block
 *  0b1001..cdr_valid, msb of FSM state from cdr_ctl
 *  0b1010..2 lsb's of FSM state from cdr_ctl
 *  0b1011..rx_dig_rst,rx_dig_en
 *  0b1100..rx_ana_word_clk_i, rx_ana_dword_clk_i
 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_1 - CDR Control 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_SHIFT (0U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_MASK (0xFC00U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_SHIFT (10U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_2 - CDR Control 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_MASK (0x1FFU)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_SHIFT (0U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_MASK (0xFE00U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_SHIFT (9U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_3 - CDR Control 3 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_SHIFT (0U)
/*! SSC_OFF_PHUG0 - When SSC mode is disabled, the PHUG value in gain stage 0 is SSC_OFF_PHUG0 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_SHIFT (3U)
/*! SSC_OFF_PHUG1 - When SSC mode is disabled, the PHUG value in gain stage 1 is SSC_OFF_PHUG1 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_MASK (0x1C0U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_SHIFT (6U)
/*! SSC_OFF_FRUG0 - When SSC mode is disabled, the drug value in gain stage 0 is SSC_OFF_FRUG0 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_SHIFT (9U)
/*! OVRD_DPLL_GAIN - Override PHUG and FRUG values
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_MASK (0x1C00U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_SHIFT (10U)
/*! PHUG_OVRD_VALUE - Override Value for PHUG (Phase Update Gain)
 *  0b000..0
 *  0b001..1000 ppm
 *  0b010..2000 ppm
 *  0b011..3000 ppm
 *  0b100..4000 ppm
 *  0b101..5000 ppm
 *  0b110..6000 ppm
 *  0b111..7000 ppm
 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_MASK (0xE000U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_SHIFT (13U)
/*! FRUG_OVRD_VALUE - Override Value for FRUG (Frequency Update Gain)
 *  0b000..0
 *  0b001..1/16 LSB/update
 *  0b010..1/8 LSB/update
 *  0b011..1/4 LSB/update
 *  0b100..1/2 LSB/update
 *  0b101..1 LSB/update
 *  0b110..2 LSB/update
 *  0b111..4 LSB/update
 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_4 - CDR Control 4 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_SHIFT (0U)
/*! SSC_OFF_FRUG1 - When SSC mode is disabled, the FRUG value in gain stage 1 is SSC_OFF_FRUG1 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_SHIFT (3U)
/*! SSC_ON_FRUG0 - When SSC mode is enabled, the FRUG value in gain stage 0 is SSC_ON_FRUG0 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_MASK (0x1C0U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_SHIFT (6U)
/*! SSC_ON_FRUG1 - When SSC mode is enabled, the FRUG value in gain stage 1 is SSC_ON_FRUG1 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_MASK (0xE00U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_SHIFT (9U)
/*! SSC_ON_PHUG0 - When SSC mode is enabled, the PHUG value in gain stage 0 is SSC_ON_PHUG0 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_MASK (0x7000U)
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_SHIFT (12U)
/*! SSC_ON_PHUG1 - When SSC mode is enabled, the PHUG value in gain stage 1 is SSC_ON_PHUG1 */
#define ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_STAT - Current Output Values to DPLL (PHUG, FRUG) */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_SHIFT (0U)
/*! PHUG_VALUE - Current value for dpll_phug[2:0] */
#define ENET_PHY_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_MASK)

#define ENET_PHY_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_SHIFT (3U)
/*! FRUG_VALUE - Current value for dpll_frug[2:0] */
#define ENET_PHY_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_DPLL_FREQ - Current Frequency Integrator Value */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_VAL_MASK (0x3FFFU)
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_VAL_SHIFT (0U)
/*! VAL - Freq is 125*VAL ppm from the reference (volatile and 2 reads needed to read value) */
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_VAL(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_VAL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_DPLL_FREQ_BOUND_0 - Frequency Bounds for Incoming Data Stream 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_SHIFT (0U)
/*! FREQ_BOUND_EN - Enable the frequency bounds feature
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_MASK (0x7FEU)
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_SHIFT (1U)
/*! UPPER_FREQ_BOUND - Upper frequency bound in terms of LSBs of the integral control code */
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_SHIFT)) & ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_DPLL_FREQ_BOUND_1 - Frequency Bounds for Incoming Data Stream 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_SHIFT (0U)
/*! LOWER_FREQ_BOUND - Lower frequency bound in terms of LSBs of the integral control code */
#define ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_SHIFT)) & ENET_PHY_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0 - Adaptation Configuration 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_SHIFT (0U)
/*! N_TOP_ASM1 - Number of top level loop iterations for ASM1 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_MASK (0x3C00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_SHIFT (10U)
/*! N_TGG_ASM1 - Number of toggle loop iterations for ASM1 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_SHIFT (14U)
/*! START_ASM1 - Start adaptation state machine #1 (VGA, CTLE, DFE, EYEH)
 *  0b0..Doesn't start
 *  0b1..Starts
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_SHIFT (15U)
/*! ADPT_CLK_DIV4_EN - Set the adaptation clock to be divided by 4 (default is div2)
 *  0b0..Not set
 *  0b1..Set
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1 - Adaptation Configuration 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_MASK (0x7FU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_SHIFT (0U)
/*! N_WAIT_ASM1 - Number of wait cycles for Adaptation SM #1 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_MASK (0x300U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_SHIFT (8U)
/*! CTLE_POLE_OVRD_VAL - CTLE Pole override value to load at start of adaptation */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_SHIFT (10U)
/*! CTLE_POLE_OVRD_EN - Override CTLE pole value (only valid if adaptation is run)
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_DFE_T1_ANA_DIS_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_DFE_T1_ANA_DIS_SHIFT (11U)
/*! DFE_T1_ANA_DIS - Disable updating DFE tap1 analog values during adaptation
 *  0b0..Not disable
 *  0b1..Disable
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_DFE_T1_ANA_DIS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_DFE_T1_ANA_DIS_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_DFE_T1_ANA_DIS_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2 - Adaptation Configuration 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_SHIFT (0U)
/*! TGG_PTTRN_0 - Pattern for the First Toggle Loop */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_MASK (0x3E0U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_SHIFT (5U)
/*! TGG_PTTRN_1 - Pattern for the Second Toggle Loop */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3 - Adaptation Configuration 3 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_SHIFT (0U)
/*! CTLE_EN - Enable CTLE Boost Adaptation */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_SHIFT (5U)
/*! VGA_EN - Enable VGA adaptation
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_SHIFT (6U)
/*! ATT_EN - Enable ATT adaptation
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_MASK (0xF80U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_SHIFT (7U)
/*! DFE_EN - Enable DFE adaptation for taps 5-1 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_SHIFT (12U)
/*! EYEHE_EN - Enable eye height measurement using even error slicer
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_SHIFT (13U)
/*! EYEHO_EN - Enable eye height measurement using odd error slicer
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_SHIFT (14U)
/*! TGG_EN - Enable toggling of the error slicer
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_SHIFT (15U)
/*! ESL_TWICE_DSL - Assert if error slicer has twice the voltage range as the data slicer (for the same 8 bits) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4 - Adaptation Configuration 4 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_SHIFT (0U)
/*! CTLE_TH - CTLE correlation decision threshold (2^N-1) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_MASK (0xF0U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_SHIFT (4U)
/*! VGA_TH - VGA Correlation Decision Threshold (2^N-1) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_MASK (0xF00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_SHIFT (8U)
/*! DFE1_TH - DFE Tap1 correlation decision threshold (2^N-1) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_MASK (0xF000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_SHIFT (12U)
/*! DFE2_TH - DFE Tap2 correlation decision threshold (2^N-1) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5 - Adaptation Configuration 5 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_SHIFT (0U)
/*! DFE3_TH - DFE Tap3 correlation decision threshold (2^N-1) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_MASK (0xF0U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_SHIFT (4U)
/*! DFE4_TH - DFE Tap4 correlation decision threshold (2^N-1) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_MASK (0xF00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_SHIFT (8U)
/*! DFE5_TH - DFE Tap5 correlation decision threshold (2^N-1) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_MASK (0xF000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_SHIFT (12U)
/*! TH_OFFSET - Apply an offset to the decision threshold */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6 - Adaptation Configuration 6 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_SHIFT (0U)
/*! CTLE_MU - CTLE boost code update gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_SHIFT (3U)
/*! VGA_MU - VGA Gain Code Update Gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_MASK (0x1C0U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_SHIFT (6U)
/*! ATT_MU - ATT gain code update gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_MASK (0xE00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_SHIFT (9U)
/*! VGA_SAT_CNT - VGA saturation count */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_SHIFT (12U)
/*! VGA_SAT_CNT_STICKY - If deasserted, then VGA saturation counts must be consecutive to change ATT */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_MASK (0xE000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_SHIFT (13U)
/*! ATT_LOW_TH - ATT low threshold */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7 - Adaptation Configuration 7 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_SHIFT (0U)
/*! VGA_MIN_SAT - VGA minimum saturation limit */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_MASK (0xF0U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_SHIFT (4U)
/*! VGA_LEV_HIGH - VGA level high saturation limit */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_MASK (0xF00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_SHIFT (8U)
/*! VGA_LEV_LOW - VGA level low saturation limit */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8 - Adaptation Configuration 8 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_SHIFT (0U)
/*! DFE1_MU - DFE tap1 code update gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_SHIFT (3U)
/*! DFE2_MU - DFE tap2 code update gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_MASK (0x1C0U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_SHIFT (6U)
/*! DFE3_MU - DFE tap3 code update gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_MASK (0xE00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_SHIFT (9U)
/*! DFE4_MU - DFE tap4 code update gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_MASK (0x7000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_SHIFT (12U)
/*! DFE5_MU - DFE tap5 code update gain (2^N) */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9 - Adaptation Configuration 9 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_SHIFT (0U)
/*! ERR_SLE_ADPT_INIT - The error even slicer is initialized to this value at the start of a new adaptation request */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_MASK (0xFF00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_SHIFT (8U)
/*! ERR_SLO_ADPT_INIT - The error odd slicer is initialized to this value at the start of a new adaptation request */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG - Reset Adaptation Configuration */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_SHIFT (0U)
/*! RST_ADPT_ATT - Reset ATT when turning off AFE adaptation
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_SHIFT (1U)
/*! RST_ADPT_VGA - Reset VGA when turning off AFE adaptation
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_SHIFT (2U)
/*! RST_ADPT_CTLE_BOOST - Reset CTLE Boost when turning off AFE adaptation
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_SHIFT (3U)
/*! RST_ADPT_CTLE_POLE - Reset CTLE Pole when turning off AFE adaptation
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_SHIFT (4U)
/*! RST_ADPT_TAP1 - Reset Data Tap1 when turning off DFE adaptation (Taps 2-5 are always turned off when DFE adaptation is turned off)
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ATT_STATUS - Value of ATT Adaptation code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_SHIFT (0U)
/*! ATT_ADPT_CODE - Value of ATT adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_SHIFT (8U)
/*! ASM1_DON - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_VGA_STATUS - Value of VGA Adaptation Code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_MASK (0x1FFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_SHIFT (0U)
/*! VGA_ADPT_CODE - Value of VGA adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_SHIFT (9U)
/*! ASM1_DONE - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_CTLE_STATUS - Value of CTLE Adaptation Code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_SHIFT (0U)
/*! CTLE_BOOST_ADPT_CODE - Value of CTLE boost adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_MASK (0xC00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_SHIFT (10U)
/*! CTLE_POLE_ADPT_CODE - Value of CTLE pole adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS - Value of DFE Tap1 Adaptation Code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_MASK (0x1FFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP1_ADPT_CODE - Value of DFE tap1 adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_SHIFT (13U)
/*! ASM1_DONE - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS - Value of DFE Tap2 Adaptation Code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_MASK (0xFFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP2_ADPT_CODE - Value of DFE tap2 adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS - Value of DFE Tap3 Adaptation Code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_MASK (0xFFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP3_ADPT_CODE - Value of DFE tap3 adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS - Value of DFE Tap4 Adaptation Code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_MASK (0xFFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP4_ADPT_CODE - Value of DFE tap4 adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS - Value of DFE Tap5 Adaptation Code */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_MASK (0xFFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP5_ADPT_CODE - Value of DFE tap5 adaptation code */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when adaptation state machine #1 is done
 *  0b0..Not done
 *  0b1..Done
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_HIGH_VDAC_OFST - Offset Values for RX DFE Data Even High vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_EVEN_HIGH_VDAC_OFST - Offset value for DFE Data Even High vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_LOW_VDAC_OFST - Offset Values for RX DFE Data Even Low vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_EVEN_LOW_VDAC_OFST - Offset value for DFE Data Even Low vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_HIGH_VDAC_OFST - Offset Values for RX DFE Data Odd High vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_ODD_HIGH_VDAC_OFST - Offset value for DFE Data Odd High vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_LOW_VDAC_OFST - Offset Values for RX DFE Data Odd Low vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_ODD_LOW_VDAC_OFST - Offset value for DFE Data Odd Low vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN - Sets Values for RX SLICER CTRL EVEN Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_E - Value for rx_ana_slicer_ctrl_e[3:0] */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD - Sets Values for RX SLICER CTRL ODD Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_O - Value for rx_ana_slicer_ctrl_o[3:0] */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST - Offset Values for RX DFE Error Even vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_EVEN_VDAC_OFST - Offset value for DFE Error Even vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST - Offset Values for RX DFE Error Odd vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_ODD_VDAC_OFST - Offset value for DFE Error Odd vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL - Value of Error Slicer Level */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_SHIFT (0U)
/*! E_SLO_LVL - Odd Error Slicer Level */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_MASK)

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_MASK (0xFF00U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_SHIFT (8U)
/*! E_SLE_LVL - Even Error Slicer Level */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_EVEN_VDAC_OFST - Offset Values for RX DFE By-Pass Even vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_BYPASS_EVEN_VDAC_OFST - Offset value for DFE By-Pass Even vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_ODD_VDAC_OFST - Offset Values for RX DFE By-Pass Odd vDAC */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_BYPASS_ODD_VDAC_OFST - Offset value for DFE By-Pass Odd vDAC */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_RESET - Adaptation Reset */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_SHIFT (0U)
/*! RESET_ASM1 - Resets adaptation state machine (ASM1) as well as the stats capture block
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_10 - Adaptation Configuration 10 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_10_CTLE_T1_WT_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_10_CTLE_T1_WT_SHIFT (0U)
/*! CTLE_T1_WT - When calculating CTLE correlation, tap1 correlation will be right shifted by CTLE_T1_WT before being used */
#define ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_10_CTLE_T1_WT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_10_CTLE_T1_WT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_10_CTLE_T1_WT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_LD_VAL_1 - Stat Load Value for the Sample Counter 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_SHIFT (0U)
/*! SC1_LD_VAL - Sample counter #1 load value */
#define ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_SHIFT (15U)
/*! SC1_START - Start Sample Counter #1
 *  0b0..Doesn't start
 *  0b1..Starts
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_DATA_MSK - Stat Data Mask Bits [15:0] */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_MASK (0xFFFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_SHIFT (0U)
/*! DATA_MSK_15_0 - Value of data_msk_r[15:0] */
#define ENET_PHY_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL0 - Stat Match Controls 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_SHIFT (0U)
/*! PTTRN_MSK_CR1A_4_0 - Value of pattern A mask for 1st correlator (bits 4:0) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_MASK (0x3E0U)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_SHIFT (5U)
/*! PTTRN_CR1A_4_0 - Value of pattern A for 1st correlator (bits 4:0) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_MASK (0x3C00U)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_SHIFT (10U)
/*! DATA_MSK_19_16 - Value of data_msk_r[19:16] */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_MASK (0xC000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_SHIFT (14U)
/*! SCOPE_DLY - Number of clock cycle delays on scope_data_rx_clk An additional MSB is added in SCOPE_DLY_2 */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL1 - Stat Match Controls 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_SHIFT (0U)
/*! PTTRN_CR1B_EN - Enable pattern B matching for 1st correlator
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_MASK (0x3EU)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_SHIFT (1U)
/*! PTTRN_MSK_CR1B_4_0 - Value of pattern B mask for 1st correlator (bits 4:0) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_MASK (0x7C0U)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_SHIFT (6U)
/*! PTTRN_CR1B_4_0 - Value of pattern B for 1st correlator (bits 4:0) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_SHIFT (11U)
/*! PTTRN_CR1A_ADPT_EN - Enable ORing of adaptation pattern with pattern CR1A
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CTL0 - Stat Controls 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_SHIFT (1U)
/*! CORR_SHFT_SEL_VGA - Select Shift for Error Going to VGA
 *  0b0..None
 *  0b1..>> 1
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_SHIFT (2U)
/*! CORR_SHFT_SEL - Select Shift for Phase
 *  0b0..None
 *  0b1..>> 1
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_MASK (0x18U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_SHIFT (3U)
/*! CORR_SRC_SEL - Select Correlation Input Source
 *  0b00..rx_error[39:0]
 *  0b01..rx_phase[39:0]
 *  0b10..{{20{scope_data_rxclk_dly_s01}},{20{scope_data_rxclk_dly}}}
 *  0b11..No correlation
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_SHIFT (5U)
/*! CORR_MODE_EN - Enable correlation mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_MASK (0x3C0U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_SHIFT (6U)
/*! STAT_SHFT_SEL - Select Stat Source Shift Value
 *  0b0000..Correlate N-1 -> N+3 (use N for offset calibration)
 *  0b0001..Correlate N+1 -> N+5 (for taps1-5)
 *  0b0010..Correlate N+6 -> N+10
 *  0b0011..Correlate N+11 -> N+15
 *  0b0100..Correlate N+16 -> N+20
 *  0b0101..Correlate N+21 -> N+25
 *  0b0110..Correlate N+26 -> N+30
 *  0b0111..Correlate N+31 -> N+35
 *  0b1000..Correlate N+36 -> N+39
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_MASK (0x1C00U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_SHIFT (10U)
/*! STAT_SRC_SEL - Select Stat Source Input
 *  0b000..{20{rx_cal_result}}
 *  0b001..{{20{scope_data_rxclk_dly_s01}},{20{scope_data_rxclk_dly}}}
 *  0b010..rx_phase[39:0]
 *  0b011..rx_error[39:0]
 *  0b100..rx_data[39:0]
 *  0b101..rx_phdir[39:0]
 *  0b110..40'hFF_FFFF_FFFF
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_SHIFT (13U)
/*! STAT_RXCLK_SEL - Select Stat Clock
 *  0b0..ref_range_clk
 *  0b1..rx_dig_clk (i.e. RX dword clk)
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_SHIFT (14U)
/*! SC_TIMER_MODE - Sample Counter Operation Mode
 *  0b0..Counts number of matched samples
 *  0b1..Counts clock cycles (i.e. a timer)
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_SHIFT (15U)
/*! SKIP_EN - Value of skip_en_r */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CTL1 - Stat Controls 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_SHIFT (0U)
/*! STAT_CNT_0_EN - Enable for stat counter 0
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_SHIFT (1U)
/*! STAT_CNT_1_EN - Enable for stat counter 1
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_SHIFT (2U)
/*! STAT_CNT_2_EN - Enable for stat counter 2
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_SHIFT (3U)
/*! STAT_CNT_3_EN - Enable for stat counter 3 Only counter to be enabled by default, since used for offset calibration
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_SHIFT (4U)
/*! STAT_CNT_4_EN - Enable for stat counter 4
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_SHIFT (5U)
/*! STAT_CNT_5_EN - Enable for stat counter 5
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_SHIFT (6U)
/*! STAT_CNT_6_EN - Enable for stat counter 6
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_SHIFT (9U)
/*! SC_PAUSE - Pause the sample counter and stat counters
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_SHIFT (10U)
/*! STAT_CLK_EN - Clock gate enable for stat clock
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_MASK (0x1800U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_SHIFT (11U)
/*! DATA_DLY_SEL - Number of clock cycle delays on rx_data[19:0] An additional MSB is added in DATA_DLY_SEL_2 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_SHIFT (13U)
/*! VLD_LOSS_CLR - Clearing of Stats Collection upon Loss of Valid
 *  0b0..Hold sample and stat counters
 *  0b1..Clear sample and stat counters
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_MASK (0xC000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_SHIFT (14U)
/*! VLD_CTL - Gating Configuration of Stats Collection
 *  0b00..Ignore both cdr_valid and rx_valid
 *  0b01..Gate stats collection with cdr_valid
 *  0b10..Gate stats collection with rx_valid
 *  0b11..Ignore both cdr_valid and rx_valid
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_SMPL_CNT1 - Sample Counter 1 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_SHIFT (0U)
/*! SMPL_CNT1 - Current value of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_0 - Stat Counter 0 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_SHIFT (0U)
/*! STAT_CNT_0 - Current value of stat counter 0 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_1 - Stat Counter 1 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_SHIFT (0U)
/*! STAT_CNT_1 - Current value of stat counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_2 - Stat Counter 2 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_SHIFT (0U)
/*! STAT_CNT_2 - Current value of stat counter 2 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_3 - Stat Counter 3 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_SHIFT (0U)
/*! STAT_CNT_3 - Current value of stat counter 3 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_4 - Stat Counter 4 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_SHIFT (0U)
/*! STAT_CNT_4 - Current value of stat counter 4 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_5 - Stat Counter 5 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_SHIFT (0U)
/*! STAT_CNT_5 - Current value of stat counter 5 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_6 - Stat Counter 6 Status */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_SHIFT (0U)
/*! STAT_CNT_6 - Current value of stat counter 6 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter 1 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL - Calibration Comparator Control */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_SHIFT (0U)
/*! PRECHRGE_CNT - Precharge Count */
#define ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_SHIFT (3U)
/*! REF_DIV_CNT - Ref Range Clock Count */
#define ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL2 - Stat Match Controls 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_SHIFT (0U)
/*! PTTRN_CR1A_19_5 - Value of pattern A for 1st correlator (bits 19:5) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL3 - Stat Match Controls 3 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_SHIFT (0U)
/*! PTTRN_MSK_CR1A_19_5 - Value of pattern A mask for 1st correlator (bits 19:5) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL4 - Stat Match Controls 4 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_SHIFT (0U)
/*! PTTRN_CR1B_19_5 - Value of pattern B for 1st correlator (bits 19:5) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL5 - Stat Match Controls 5 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_MASK (0x7FFFU)
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_SHIFT (0U)
/*! PTTRN_MSK_CR1B_19_5 - Value of pattern B mask for 1st correlator (bits 19:5) */
#define ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CTL2 - Stat Controls 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_SHIFT (0U)
/*! DATA_DLY_SEL_2 - Additional MSB bit for DATA_DLY_SEL to extend the delay range to 0 -> 7 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_MASK)

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_SHIFT (1U)
/*! SCOPE_DLY_2 - Additional MSB bit for SCOPE_DLY to extend the delay range to 0 -> 7 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_STOP - Stat Stop */
/*! @{ */

#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_SHIFT (0U)
/*! SC1_STOP - Stop Sample Counters 1 and Associated Stat Counters
 *  0b0..Doesn't stop
 *  0b1..Stops
 */
#define ENET_PHY_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_SHIFT)) & ENET_PHY_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_OVRD_OUT - Override Values for TX Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_SHIFT (0U)
/*! TX_ANA_CLK_SHIFT - Override Value for tx_ana_clk_shift
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_SHIFT (1U)
/*! TX_ANA_DATA_EN - Override Value for tx_ana_data_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_SHIFT (2U)
/*! TX_ANA_REFGEN_EN - Override Value for tx_ana_refgen_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_SHIFT (3U)
/*! TX_ANA_VCM_HOLD - Override Value for tx_ana_vcm_hold
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_SHIFT (4U)
/*! TX_ANA_CLK_EN - Override Value for tx_ana_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_SHIFT (5U)
/*! TX_ANA_WORD_CLK_EN - Override Value for tx_ana_word_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_SHIFT (6U)
/*! TX_ANA_MPLLA_CLK_EN - Override Value for tx_ana_mplla_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_SHIFT (7U)
/*! TX_ANA_MPLLB_CLK_EN - Override Value for tx_ana_mpllb_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_SHIFT (8U)
/*! TX_ANA_RESET - Override Value for tx_ana_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_SHIFT (9U)
/*! TX_ANA_SERIAL_EN - Override Value for tx_ana_serial_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_MASK (0x1C00U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_SHIFT (10U)
/*! TX_ANA_DATA_RATE - Override Value for tx_ana_data_rate */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_SHIFT (13U)
/*! TX_DIV4_EN - Override Value for tx_ana_div4_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_SHIFT (14U)
/*! TX_RXDET_EN - Override Value for tx_ana_rxdet_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_SHIFT (15U)
/*! TX_OVRD_EN - Enable override values for all outputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT - Override Value for TX termination Code Up Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_CODEP_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_CODEP_SHIFT (0U)
/*! TX_TERM_UP_CODEP - Overrides the tx_ana_term_code_up[9:0] signal */
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_CODEP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_CODEP_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_CODEP_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_OVRD_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_OVRD_EN_SHIFT (10U)
/*! TX_TERM_UP_OVRD_EN - Overrides enable for the tx_ana_term_code_up[9:0] signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_TERM_UP_OVRD_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_CLK_LB_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_CLK_LB_EN_SHIFT (11U)
/*! TX_CLK_LB_EN - Override Value for tx_ana_clk_lb_en (override enabled by TX_OVRD_EN)
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_CLK_LB_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_CLK_LB_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_CLK_LB_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_ANA_VCM_HOLD_GS_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_ANA_VCM_HOLD_GS_SHIFT (12U)
/*! TX_ANA_VCM_HOLD_GS - Override Value for tx_ana_vcm_hold_gs
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_ANA_VCM_HOLD_GS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_ANA_VCM_HOLD_GS_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_TERM_UP_CODE_OVRD_OUT_TX_ANA_VCM_HOLD_GS_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT - Override Value for TX termination Down Code Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_CODE_MASK (0x3FFU)
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_CODE_SHIFT (0U)
/*! TX_TERM_DN_CODE - Overrides the tx_ana_term_code_dn[9:0] signal */
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_CODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_CODE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_CODE_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_OVRD_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_OVRD_EN_SHIFT (10U)
/*! TX_TERM_DN_OVRD_EN - Overrides enable for the tx_ana_term_code_dn[9:0] signal
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_TERM_DN_CODE_OVRD_OUT_TX_TERM_DN_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0 - Override Values for TX EQ Signals Going to ANA 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_SHIFT (0U)
/*! TX_ANA_LOAD_CLK - Override Value for tx_ana_load_clk
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_MASK (0x7FFEU)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_SHIFT (1U)
/*! TX_ANA_CTRL_ATTEN_13_0 - Override Value for tx_ana_ctrl_atten[13:0] */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_SHIFT (15U)
/*! TX_EQ_OVRD_EN - Override Enable for TX EQ Signals
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1 - Override Values for TX EQ Signals Going to ANA 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_29_14_MASK (0xFFFFU)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_29_14_SHIFT (0U)
/*! TX_ANA_CTRL_ATTEN_29_14 - Override Value for tx_ana_ctrl_atten[29:14] */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_29_14(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_29_14_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_29_14_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2 - Override Values for TX EQ Signals Going to ANA 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_ATTEN_34_30_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_ATTEN_34_30_SHIFT (0U)
/*! TX_ANA_CTRL_ATTEN_34_30 - Override Value for tx_ana_ctrl_atten[34:30] */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_ATTEN_34_30(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_ATTEN_34_30_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_ATTEN_34_30_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_UP_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_UP_SHIFT (5U)
/*! TX_ANA_CTRL_HALF_UP - Override Value for tx_ana_ctrl_half_up
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_UP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_UP_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_UP_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_DN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_DN_SHIFT (6U)
/*! TX_ANA_CTRL_HALF_DN - Override Value for tx_ana_ctrl_half_dn
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_DN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_DN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_HALF_DN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_MASK (0xFF80U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_SHIFT (7U)
/*! TX_ANA_CTRL_PRE - Override Value for tx_ana_ctrl_pre[8:0] */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3 - Override Values for TX EQ Signals Going to ANA 3 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_HALF_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_HALF_SHIFT (0U)
/*! TX_ANA_CTRL_PRE_HALF - Override Value for tx_ana_ctrl_pre_half
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_HALF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_HALF_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_HALF_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_QTR_MASK (0x6U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_QTR_SHIFT (1U)
/*! TX_ANA_CTRL_PRE_QTR - Override Value for tx_ana_ctrl_pre_qtr[1:0] */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_QTR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_QTR_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_PRE_QTR_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_HALF_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_HALF_SHIFT (3U)
/*! TX_ANA_CTRL_POST_HALF - Override Value for tx_ana_ctrl_post_half
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_HALF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_HALF_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_HALF_MASK)

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_QTR_MASK (0x30U)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_QTR_SHIFT (4U)
/*! TX_ANA_CTRL_POST_QTR - Override Value for tx_ana_ctrl_post_qtr[1:0] */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_QTR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_QTR_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_QTR_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_4 - Override Values for TX EQ Signals Going to ANA 4 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_4_TX_ANA_CTRL_POST_MASK (0x3FFFU)
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_4_TX_ANA_CTRL_POST_SHIFT (0U)
/*! TX_ANA_CTRL_POST - Override Value for tx_ana_ctrl_post[13:0] */
#define ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_4_TX_ANA_CTRL_POST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_4_TX_ANA_CTRL_POST_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_4_TX_ANA_CTRL_POST_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_CTL_OVRD_OUT - Override Values for RX Control Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV16P5_CLK_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV16P5_CLK_EN_SHIFT (0U)
/*! RX_ANA_DIV16P5_CLK_EN - Override Value for rx_ana_div16p5_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_MASK (0x6U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_SHIFT (1U)
/*! RX_ANA_DATA_RATE - Override Value for rx_ana_data_rate */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_SHIFT (3U)
/*! RX_ANA_WORD_CLK_EN - Override Value for rx_ana_word_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_SHIFT (4U)
/*! RX_ANA_DIV4_EN - Override Value for rx_ana_div4_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_SHIFT (5U)
/*! RX_ANA_DFE_TAPS_EN - Override Value for rx_ana_dfe_taps_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_BYPASS_N_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_BYPASS_N_SHIFT (6U)
/*! RX_ANA_DFE_BYPASS_N - Override Value for rx_ana_dfe_bypass_n
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_BYPASS_N(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_BYPASS_N_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_BYPASS_N_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_SHIFT (7U)
/*! RX_LBK_CLK_EN - Override Value for rx_ana_loopback_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_SHIFT (8U)
/*! RX_CTL_OVRD_EN - Enable override values for outputs [8-0] below
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_PWR_OVRD_OUT - Override Values for RX PWR UP/DN Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_SHIFT (0U)
/*! RX_ANA_LOS_EN - Override Value for rx_ana_los_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_SHIFT (1U)
/*! RX_ANA_AFE_EN - Override Value for rx_ana_afe_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_ANA_CLK_VREG_EN - Override Value for rx_ana_clk_vreg_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_SHIFT (3U)
/*! RX_ANA_CLK_DCC_EN - Override Value for rx_ana_clk_dcc_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_SHIFT (4U)
/*! RX_ANA_CLK_EN - Override Value for rx_ana_clk_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_SHIFT (5U)
/*! RX_ANA_CDR_EN - Override Value for rx_ana_cdr_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_SHIFT (6U)
/*! RX_ANA_DESERIAL_EN - Override Value for rx_ana_deserial_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_SHIFT (7U)
/*! RX_PWR_OVRD_EN - Enable override values for all outputs controlled by this register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0 - Override Values for RX VCO Signals Going to ANA 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_SHIFT (0U)
/*! RX_ANA_CDR_VCO_EN - Override Value for rx_ana_cdr_vco_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_SHIFT (1U)
/*! RX_ANA_CDR_STARTUP - Override Value for rx_ana_cdr_startup
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_SHIFT (2U)
/*! RX_VCO_CDR_OVRD_EN - Enable override values for cdr_vco_en and cdr_startup
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_MASK (0x1FF8U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT (3U)
/*! RX_ANA_CDR_FREQ_TUNE - Override Value for rx_ana_cdr_freq_tune */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_MASK (0x2000U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_SHIFT (13U)
/*! RX_ANA_VCO_CNTR_EN - Override Value for rx_ana_vco_cntr_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_MASK (0x4000U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_SHIFT (14U)
/*! RX_ANA_VCO_CNTR_CLK - Override Value for rx_ana_vco_cntr_clk
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_SHIFT (15U)
/*! RX_CDR_FREQ_TUNE_OVRD_EN - Enable override value for rx_ana_cdr_freq_tune
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1 - Override Values for RX VCO Signals Going to ANA 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_MASK (0x3U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_SHIFT (0U)
/*! RX_ANA_CDR_VCO_FREQBAND - Override Value for rx_ana_cdr_vco_freqband */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_OVRD_EN_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_OVRD_EN_SHIFT (2U)
/*! RX_ANA_CDR_VCO_FREQBAND_OVRD_EN - Override Enable for rx_ana_cdr_vco_freqband
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_FREQBAND_OVRD_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_SHIFT (3U)
/*! RX_ANA_VCO_CNTR_PD - Override Value for rx_ana_vco_cntr_pd
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_OVER_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_OVER_EN_SHIFT (4U)
/*! RX_ANA_VCO_CNTR_OVER_EN - Override Enable for rx_ana_vco_cntr_pd
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_OVER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_OVER_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_OVER_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_EN_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_EN_SHIFT (5U)
/*! RX_ANA_CDR_VCO_TEMP_COMP_EN - Override Value for rx_ana_cdr_vco_temp_comp
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_OVRD_EN_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_OVRD_EN_SHIFT (6U)
/*! RX_ANA_CDR_VCO_TEMP_COMP_OVRD_EN - Override Enable for rx_ana_cdr_vco_temp_comp_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_TEMP_COMP_OVRD_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_SHIFT (7U)
/*! RX_ANA_CDR_VCO_STEP_CTRL - Override Value for rx_ana_cdr_vco_step_ctrl
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_OVRD_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_OVRD_EN_SHIFT (8U)
/*! RX_ANA_CDR_VCO_STEP_CTRL_OVRD_EN - Override Enable for rx_ana_cdr_vco_step_ctrl
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_STEP_CTRL_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2 - Override Values for RX VCO Signals Going to ANA 2 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_SHIFT (0U)
/*! RX_ANA_CDR_FREQ_TUNE_CLK - Override Value for rx_ana_cdr_freq_tune_clk
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_CAL - Sets Values for RX CAL Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_SHIFT (0U)
/*! RX_ANA_CAL_MUXA_SEL - Value for rx_ana_cal_muxa_sel[4:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_MASK (0x3E0U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_SHIFT (5U)
/*! RX_ANA_CAL_MUXB_SEL - Value for rx_ana_cal_muxb_sel[4:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_MASK (0x400U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_SHIFT (10U)
/*! RX_ANA_CAL_LPFBYP_EN - Value for rx_ana_cal_lpfbyp_en */
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_SHORT_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_SHORT_EN_SHIFT (11U)
/*! RX_ANA_CAL_SHORT_EN - Value for rx_ana_cal_short_en */
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_SHORT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_SHORT_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_SHORT_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_MASK (0x1000U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_SHIFT (12U)
/*! RX_ANA_SLICER_CAL_EN - Value for rx_ana_slicer_cal_en */
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_MASK (0x6000U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_SHIFT (13U)
/*! RX_ANA_CAL_MODE - Value for rx_ana_cal_mode[1:0]
 *  0b00..Differential comparison
 *  0b01..Single-ended, positive node to positive node
 *  0b10..Single-ended, negative node to negative node
 *  0b11..Common mode comparison
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_MASK (0x8000U)
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_SHIFT (15U)
/*! RX_ANA_CAL_COMP_EN - Value for rx_ana_cal_comp_en */
#define ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_VDAC_RANGE_SEL - Sets Values for RX DAC CTRL Value Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_PRANGE_SEL_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_PRANGE_SEL_SHIFT (0U)
/*! RX_ANA_CAL_VDAC_PRANGE_SEL - Value for rx_ana_cal_vdac_prange */
#define ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_PRANGE_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_PRANGE_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_PRANGE_SEL_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_DERANGE_SEL_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_DERANGE_SEL_SHIFT (1U)
/*! RX_ANA_CAL_VDAC_DERANGE_SEL - Value for rx_ana_cal_vdac_derange */
#define ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_DERANGE_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_DERANGE_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_VDAC_RANGE_SEL_RX_ANA_CAL_VDAC_DERANGE_SEL_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_DAC_CTRL - Sets Values for RX DAC CTRL Value Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_MASK (0xFFU)
#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_SHIFT (0U)
/*! RX_ANA_CAL_DAC_CTRL - Value for rx_ana_cal_dac_ctrl[7:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_RTRIM - Set Value for RX RTRIM Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_VAL_SHIFT (0U)
/*! RX_ANA_AFE_TRIM_OVRD_VAL - Override Value for rx_ana_afe_trim_ovrd_val
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_VAL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_VAL_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_EN_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_EN_SHIFT (1U)
/*! RX_ANA_AFE_TRIM_OVRD_EN - Override enable rx_ana_afe_trim_ovrd_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_OVRD_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_THRESH_R_MASK (0xFCU)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_THRESH_R_SHIFT (2U)
/*! RX_ANA_AFE_TRIM_THRESH_R - Threshold value for rx_ana_afe_trim */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_THRESH_R(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_THRESH_R_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_ANA_AFE_TRIM_THRESH_R_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_AFE_TRIM_EN_R_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_AFE_TRIM_EN_R_SHIFT (8U)
/*! RX_AFE_TRIM_EN_R - Enable for signal rx_afe_trim_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_AFE_TRIM_EN_R(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_AFE_TRIM_EN_R_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_RTRIM_RX_AFE_TRIM_EN_R_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_DAC_CTRL_OVRD - Overrides RX DAC CTRL Bus (EN/VAL/SEL) Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_SHIFT (0U)
/*! RX_CAL_DAC_CTRL_OVRD - Override Enable for Cal DAC Control
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_DAC_CTRL_SEL - Sets Values for RX DAC CTRL Select Signal Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_MASK (0x1FU)
#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_SHIFT (0U)
/*! RX_ANA_CAL_DAC_CTRL_SEL - Value for rx_ana_cal_dac_ctrl_sel[4:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_AFE_ATT_VGA - Value for RX AFE ATT & VGA Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_MASK (0x7U)
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_SHIFT (0U)
/*! RX_ANA_AFE_ATT_LVL - Value for rx_ana_afe_att_lvl[2:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA1_GAIN_MASK (0x38U)
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA1_GAIN_SHIFT (3U)
/*! RX_ANA_AFE_VGA1_GAIN - Value for rx_ana_afe_vga1_gain[2:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA1_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA1_GAIN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA1_GAIN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA2_GAIN_MASK (0x1C0U)
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA2_GAIN_SHIFT (6U)
/*! RX_ANA_AFE_VGA2_GAIN - Value for rx_ana_afe_vga2_gain[2:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA2_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA2_GAIN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_VGA2_GAIN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_MASK (0x200U)
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_SHIFT (9U)
/*! RX_AFE_OVRD_EN - Override Enable for AFE Control
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_AFE_CTLE - Values for RX AFE CTLE Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_POLE_MASK (0x3U)
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_POLE_SHIFT (0U)
/*! RX_ANA_AFE_CTLE_POLE - Value for rx_ana_afe_ctle_pole[14:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_POLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_POLE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_POLE_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_MASK (0x7CU)
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_SHIFT (2U)
/*! RX_ANA_AFE_CTLE_BOOST - Value for rx_ana_afe_ctle_boost[30:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_BIAS_MT_MASK (0x180U)
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_BIAS_MT_SHIFT (7U)
/*! RX_ANA_AFE_BIAS_MT - Value for rx_ana_afe_bias_mt[1:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_BIAS_MT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_BIAS_MT_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_BIAS_MT_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_SCOPE - Values for RX SCOPE Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_SHIFT (0U)
/*! RX_ANA_SCOPE_EN - Sets value for rx_ana_scope_en
 *  0b0..Not set
 *  0b1..Set
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_SHIFT (1U)
/*! RX_ANA_SCOPE_SEL - Sets value for rx_ana_scope_sel
 *  0b0..Not set
 *  0b1..Set
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_SHIFT (2U)
/*! RX_ANA_SCOPE_PH_CLK - Sets Value for rx_ana_scope_ph_clk
 *  0b0..Not set
 *  0b1..Set
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_MASK (0x7F8U)
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_SHIFT (3U)
/*! RX_ANA_SCOPE_PHASE - Sets value for rx_ana_scope_phase[7:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_MASK (0x800U)
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_SHIFT (11U)
/*! RX_ANA_SCOPE_CLK_EN - Enable the scope clocks going to the scope slicer and the lane digital part
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_SLICER_CTRL - Sets Values for RX Slicer Ctrl Signals Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_MASK (0xFU)
#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_E - Value for rx_ana_slicer_ctrl_e[3:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_MASK (0xF0U)
#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_SHIFT (4U)
/*! RX_ANA_SLICER_CTRL_O - Value for rx_ana_slicer_ctrl_o[3:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_MASK (0x100U)
#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_SHIFT (8U)
/*! RX_ANA_SLICER_CTRL_OVRD_EN - Override Enable for RX ANA Slicer Control
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST - Sets Values for RX ANA IQ PHASE Adjust Signal Going to ANA */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_MASK (0x7FU)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_SHIFT (0U)
/*! RX_ANA_IQ_PHASE_ADJUST - Value for rx_ana_iq_phase_adjust[6:0] */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN - Sets Values for RX ANA IQ SENSE Signal */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_SHIFT (0U)
/*! RX_ANA_IQ_SENSE_EN - Value for rx_ana_iq_sense_en */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN - DAC Control Enable Signal */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_SHIFT (0U)
/*! RX_ANA_CAL_DAC_CTRL_EN - Value for rx_ana_cal_dac_ctrl_en */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! DAC_CTRL_SELF_CLEAR_DISABLE - Disable self-clearing for the rx_ana_cal_dac_ctrl_en register
 *  0b0..Not disable
 *  0b1..Disable
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE - AFE Update Enable Signal */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_SHIFT (0U)
/*! RX_ANA_AFE_UPDATE_EN - Value for rx_ana_afe_update_en */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! AFE_UPDATE_SELF_CLEAR_DISABLE - Disable self-clearing for the rx_ana_afe_update_en register
 *  0b0..Not disable
 *  0b1..Disable
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK - Phase Adjust Clock Signal */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_SHIFT (0U)
/*! RX_ANA_IQ_PHASE_ADJUST_CLK - Value for rx_ana_iq_phase_adjust_clk */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_MASK)

#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! PHASE_ADJUST_SELF_CLEAR_DISABLE - Disable self-clearing for the rx_ana_iq_phase_adjust_clk register
 *  0b0..Not disable
 *  0b1..Disable
 */
#define ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_STATUS_0 - Lane Input Status 0 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_MASK (0x1U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_SHIFT (0U)
/*! TX_ANA_CLK_SHIFT_ACK - Value from ANA for tx_ana_clk_shift_ack */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_MASK)

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_MASK (0x2U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_SHIFT (1U)
/*! TX_ANA_RXDETP_RESULT - Value from ANA for tx_ana_rxdetp_result */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_MASK)

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_MASK (0x4U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_SHIFT (2U)
/*! TX_ANA_RXDETM_RESULT - Value from ANA for tx_ana_rxdetm_result */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_MASK)

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_MASK (0x8U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_SHIFT (3U)
/*! TX_ANA_LOOPBACK_EN - Value of tx_ana_loopback_en */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_MASK (0x10U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_SHIFT (4U)
/*! TX_ANA_CLK_LB_EN - Value of tx_ana_clk_lb_en */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_MASK)

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_MASK (0x20U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_SHIFT (5U)
/*! RX_ANA_LOS - Value from ANA for rx_ana_los */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_MASK)

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_MASK (0x40U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_SHIFT (6U)
/*! RX_ANA_CAL_RESULT - Value from ANA for rx_ana_cal_result */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_MASK)

#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_MASK (0x80U)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_SHIFT (7U)
/*! RX_ANA_SCOPE_DATA - Value from ANA for rx_ana_scope_data */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_STATUS_1 - Lane Input Status 1 */
/*! @{ */

#define ENET_PHY_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_MASK (0x1FFFU)
#define ENET_PHY_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_SHIFT (0U)
/*! RX_ANA_VCO_CNTR - Value from ANA for rx_ana_vco_cntr */
#define ENET_PHY_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_SHIFT)) & ENET_PHY_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_OVRD_MEAS - TX_OVRD_MEAS */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_SHIFT (0U)
/*! ovrd_clk_shift - If asserted, allow analog register to control clock shift function */
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_SHIFT (1U)
/*! clk_shift_reg - Controls clock shift if asserted with bit 0 */
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_SHIFT (4U)
/*! ovrd_vcm_hold - If asserted, bit 5 takes effect on control TX common mode */
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_SHIFT (5U)
/*! vcm_hold_reg - Set TX in common mode if asserted together with bit4 */
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_SHIFT (6U)
/*! pull_up_reg - Pull up TX output if asserted */
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_SHIFT (7U)
/*! pull_dn_reg - Pull down TX output if asserted */
#define ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_PWR_OVRD - TX_PWR_OVRD */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_SHIFT (0U)
/*! ovrd_tx_loopback - Enables TX loopback mode over ridden by analog register if asserted
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_MASK)

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_SHIFT (1U)
/*! loopback_en_reg - Enables TX loopback path to RX if asserted along with bit 0
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_SHIFT (2U)
/*! refgen_en_reg - Enable TX biasing if asserted with bit 7
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_SHIFT (3U)
/*! clk_div_en_reg - Enable TX divider if asserted with bit 7, overrides !tx_reset
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_data_en_reg_int_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_data_en_reg_int_SHIFT (4U)
/*! data_en_reg_int - Enable TX driver data path if asserted with bit 7
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_data_en_reg_int(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_data_en_reg_int_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_data_en_reg_int_MASK)

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_SHIFT (5U)
/*! clk_en_reg - Enable TX clock if asserted with bit 7
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_SHIFT (6U)
/*! serial_en_reg - Enable TX serializer if asserted with bit 7
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_serial_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_en_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_en_SHIFT (7U)
/*! ovrd_en - Enable analog register to take control TX power state if asserted
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_en_SHIFT)) & ENET_PHY_LANE0_ANA_TX_PWR_OVRD_ovrd_en_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_ALT_BUS - TX_ALT_BUS */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_drv_source_reg_MASK (0x3U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_drv_source_reg_SHIFT (0U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_drv_source_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_ALT_BUS_drv_source_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_ALT_BUS_drv_source_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_SHIFT (2U)
/*! ovrd_alt_bus - JTAG data and TX data source selection function is controlled by bit[1:0] and 7 when asserted */
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_SHIFT)) & ENET_PHY_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_MASK)

#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vph_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vph_SHIFT (3U)
/*! osc_vph - VPH powered I/O device ring oscillator outputs from TX when asserted */
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vph(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vph_SHIFT)) & ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vph_MASK)

#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vptx_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vptx_SHIFT (4U)
/*! osc_vptx - VPTX powered core device ring oscillator outputs from TX when asserted */
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vptx(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vptx_SHIFT)) & ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vptx_MASK)

#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_lvt_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_lvt_SHIFT (5U)
/*! osc_vp_lvt - VP powered low threshold core device ring oscillator outputs from TX when asserted */
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_lvt(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_lvt_SHIFT)) & ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_lvt_MASK)

#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_SHIFT (6U)
/*! osc_vp - VP powered high threshold core device ring oscillator outputs from TX when asserted */
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_SHIFT)) & ENET_PHY_LANE0_ANA_TX_ALT_BUS_osc_vp_MASK)

#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_SHIFT (7U)
/*! jtag_data_reg - When bit 2 is asserted, it replace JTAG data */
#define ENET_PHY_LANE0_ANA_TX_ALT_BUS_jtag_data_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_VBOOST - TX_VBOOST */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_SHIFT (5U)
/*! boost_vptx_mode_n - If asserted, TX boost mode becomes a direct boost mode */
#define ENET_PHY_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_SHIFT)) & ENET_PHY_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_MASK)

#define ENET_PHY_LANE0_ANA_TX_VBOOST_vboost_en_reg_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_TX_VBOOST_vboost_en_reg_SHIFT (6U)
/*! vboost_en_reg - If bit 7 is set to 1, analog register takes control of TX vboost enable/disable */
#define ENET_PHY_LANE0_ANA_TX_VBOOST_vboost_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_VBOOST_vboost_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_VBOOST_vboost_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_SHIFT (7U)
/*! ovrd_vboost_en - Enable TX boost mode to be override by bit 6
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_VBOOST_ovrd_vboost_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_SHIFT)) & ENET_PHY_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_TERM_CODE_DN - TX_TERM_CODE_DN */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_ovrd_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_ovrd_SHIFT (0U)
/*! term_code_dn_ovrd - Enable analog register to overdrive TX nmos leg biasing
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_ovrd(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_ovrd_SHIFT)) & ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_ovrd_MASK)

#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_reg_MASK (0xFEU)
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_reg_SHIFT (1U)
/*! term_code_dn_reg - TX nmos leg biasing register (7 MSBs),this is Term_code_dn_reg[9:3] */
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_TERM_CODE_DN_term_code_dn_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_TERM_CODE_UP - TX_TERM_CODE_UP */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_ovrd_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_ovrd_SHIFT (0U)
/*! term_code_up_ovrd - Enable analog register to overdrive TX pmos leg biasing
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_ovrd(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_ovrd_SHIFT)) & ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_ovrd_MASK)

#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_reg_MASK (0xFEU)
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_reg_SHIFT (1U)
/*! term_code_up_reg - TX pmos leg biasing register (7 MSBs), this is Term_code_up_reg[9:3] */
#define ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_TERM_CODE_UP_term_code_up_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_IBOOST_CODE - TX_IBOOST_CODE */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_SHIFT (0U)
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_SHIFT)) & ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_MASK)

#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_up_reg_2_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_up_reg_2_SHIFT (1U)
/*! term_code_up_reg_2 - TX pmos leg biasing register bit 2, this is Term_code_up_reg[2] */
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_up_reg_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_up_reg_2_SHIFT)) & ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_up_reg_2_MASK)

#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_dn_reg_2_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_dn_reg_2_SHIFT (2U)
/*! term_code_dn_reg_2 - TX nmos leg biasing register bit 2, this is Term_code_dn_reg[2] */
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_dn_reg_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_dn_reg_2_SHIFT)) & ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_term_code_dn_reg_2_MASK)

#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_SHIFT (3U)
/*! iboost_code_ovrd - Enable analog register overdrive for TX boost
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_SHIFT)) & ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_MASK)

#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_MASK (0xF0U)
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_SHIFT (4U)
#define ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_OVRD_CLK - TX_OVRD_CLK */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_SHIFT (1U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_SHIFT (2U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_SHIFT (3U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_SHIFT (4U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_SHIFT (5U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_SHIFT (6U)
/*! word_clk_en_reg - TX word clock enable/disable when bit 7 is asserted
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_SHIFT (7U)
#define ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_SHIFT)) & ENET_PHY_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_MISC - TX_MISC */
/*! @{ */

#define ENET_PHY_LANE0_ANA_TX_MISC_osc_pmos_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_TX_MISC_osc_pmos_SHIFT (4U)
/*! osc_pmos - PMOS device ring oscillator outputs from TX when asserted */
#define ENET_PHY_LANE0_ANA_TX_MISC_osc_pmos(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_MISC_osc_pmos_SHIFT)) & ENET_PHY_LANE0_ANA_TX_MISC_osc_pmos_MASK)

#define ENET_PHY_LANE0_ANA_TX_MISC_osc_nmos_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_TX_MISC_osc_nmos_SHIFT (5U)
/*! osc_nmos - NMOS device ring oscillator outputs from TX when asserted */
#define ENET_PHY_LANE0_ANA_TX_MISC_osc_nmos(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_TX_MISC_osc_nmos_SHIFT)) & ENET_PHY_LANE0_ANA_TX_MISC_osc_nmos_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_DCC_OVRD - RX_DCC_OVRD */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_afe_rate_reg_MASK (0x3U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_afe_rate_reg_SHIFT (0U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_afe_rate_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_DCC_OVRD_afe_rate_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_DCC_OVRD_afe_rate_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_word_clk_en_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_word_clk_en_SHIFT (4U)
/*! ovrd_word_clk_en - RX word clock enable/disable when bit 5 is asserted
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_word_clk_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_word_clk_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_word_clk_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_word_clk_en_reg_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_word_clk_en_reg_SHIFT (5U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_word_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_DCC_OVRD_word_clk_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_DCC_OVRD_word_clk_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_SHIFT (6U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_SHIFT (7U)
#define ENET_PHY_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_PWR_CTRL1 - RX_PWR_CTRL1 */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_SHIFT (0U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_SHIFT (1U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_SHIFT (2U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_SHIFT (3U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_SHIFT (4U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_SHIFT (5U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_los_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_pwron_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_pwron_SHIFT (6U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_pwron(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_pwron_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_ovrd_pwron_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_pwron_reg_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_pwron_reg_SHIFT (7U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_pwron_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_pwron_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL1_pwron_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_CDR_AFE - RX_CDR_AFE */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_SHIFT (6U)
/*! phdet_odd_reg - If asserted, CDR phase detector uses odd data path */
#define ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_SHIFT (7U)
/*! phdet_even_reg - If asserted, CDR phase detector uses even data path */
#define ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_even_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_PWR_CTRL2 - RX_PWR_CTRL2 */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_afe_bias_cc_MASK (0x3U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_afe_bias_cc_SHIFT (0U)
/*! afe_bias_cc - Setting of the biasing current for neg-c peaking circuit in AFE */
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_afe_bias_cc(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_afe_bias_cc_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_afe_bias_cc_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_SHIFT (2U)
/*! ovrd_dfe_en - If asserted, bit 3 takes control of RX DFE enable/disable */
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_SHIFT (3U)
/*! dfe_en_reg - If asserted with bit 2, enables RX DFE */
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_des_en_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_des_en_SHIFT (4U)
/*! ovrd_des_en - If asserted, bit 5 takes control of RX deserializer enable/disable */
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_des_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_des_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_des_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_SHIFT (5U)
/*! deserial_en_reg - If asserted with bit 4, enables RX deserializer */
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_SHIFT (6U)
/*! ovrd_loopback_en - If asserted, bit 7 takes control of TX to RX data loopback enable/disable */
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_SHIFT (7U)
/*! loopback_en_reg - If asserted with bit 6, enables TX to RX data loopback */
#define ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_MISC_OVRD - RX_MISC_OVRD */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_loopback_clk_en_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_loopback_clk_en_SHIFT (0U)
/*! ovrd_rx_loopback_clk_en - Overrides loopback en from digital and selects loopback_clk_en from regs
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_loopback_clk_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_loopback_clk_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_loopback_clk_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_loopback_clk_en_reg_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_loopback_clk_en_reg_SHIFT (1U)
/*! rx_loopback_clk_en_reg - Loopback Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_loopback_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_loopback_clk_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_loopback_clk_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_loopback_clk_sel_reg_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_loopback_clk_sel_reg_SHIFT (2U)
/*! loopback_clk_sel_reg - Selects b/w and qv phase for loopback clocks */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_loopback_clk_sel_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_loopback_clk_sel_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_loopback_clk_sel_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_afe_ibias_inc_0_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_afe_ibias_inc_0_SHIFT (3U)
/*! afe_ibias_inc_0 - Bit 0 of the two bit control of the AFE main bias currents */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_afe_ibias_inc_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_afe_ibias_inc_0_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_afe_ibias_inc_0_MASK)

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_SHIFT (4U)
/*! rx_los_lfps_en_reg - If asserted with bit 5, enables true LFPS detection */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_SHIFT (5U)
/*! ovrd_rx_los_lfps_en - If asserted, bit 4 enable/disables RX true LFPS detection */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_shor_en_reg_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_shor_en_reg_SHIFT (6U)
/*! shor_en_reg - If asserted with bit 7, RX input is shorted */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_shor_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_shor_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_shor_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_short_en_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_short_en_SHIFT (7U)
/*! ovrd_short_en - If asserted, bit 6 enable/disables RX front short function */
#define ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_short_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_short_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_MISC_OVRD_ovrd_short_en_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_CAL_MUXA - RX_CAL_MUXA */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_MASK (0x7CU)
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_SHIFT (2U)
/*! cal_muxa_sel_reg - Analog Registers to Control RX Calibration Path A */
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_SHIFT (7U)
/*! ovrd_cal_muxa_sel - If asserted, selects analog register setting to control RX calibration path A */
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_CAL_MUXB - RX_CAL_MUXB */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_SHIFT (0U)
/*! dfe_taps_en_reg - If bit 1 is asserted, controls DFE tap2 to tap5 */
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_pwron_taps_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_pwron_taps_SHIFT (1U)
/*! ovrd_pwron_taps - If 1, allows for bit 0 to control DFE tap2 to tap5 currents */
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_pwron_taps(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_pwron_taps_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_pwron_taps_MASK)

#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_MASK (0x7CU)
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_SHIFT (2U)
/*! cal_muxb_sel_reg - Analog Registers to Control RX Calibration Path B */
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_SHIFT (7U)
/*! ovrd_cal_muxb_sel - If asserted, selects analog register setting to control RX calibration path B */
#define ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_TERM - RX_TERM */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_TERM_afe_att_cm_regs_MASK (0x3U)
#define ENET_PHY_LANE0_ANA_RX_TERM_afe_att_cm_regs_SHIFT (0U)
/*! afe_att_cm_regs - 2 bit control of the vcm_eq voltage to be used as the ATT common mode reference voltage */
#define ENET_PHY_LANE0_ANA_RX_TERM_afe_att_cm_regs(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_TERM_afe_att_cm_regs_SHIFT)) & ENET_PHY_LANE0_ANA_RX_TERM_afe_att_cm_regs_MASK)

#define ENET_PHY_LANE0_ANA_RX_TERM_afe_ibias_inc_1_MASK (0x4U)
#define ENET_PHY_LANE0_ANA_RX_TERM_afe_ibias_inc_1_SHIFT (2U)
/*! afe_ibias_inc_1 - Bit 1 of the two bit control of the AFE main bias currents */
#define ENET_PHY_LANE0_ANA_RX_TERM_afe_ibias_inc_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_TERM_afe_ibias_inc_1_SHIFT)) & ENET_PHY_LANE0_ANA_RX_TERM_afe_ibias_inc_1_MASK)

#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_MASK (0x8U)
#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_SHIFT (3U)
/*! ovrd_iq_phase_adjust - If asserted the iq_phase_adjust value is controlled via registers */
#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_SHIFT)) & ENET_PHY_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_MASK)

#define ENET_PHY_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_MASK (0x10U)
#define ENET_PHY_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_SHIFT (4U)
/*! rx_term_gd_en_reg - If termination override is asserted, controls the ground termination enable */
#define ENET_PHY_LANE0_ANA_RX_TERM_rx_term_gd_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_MASK (0x20U)
#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_SHIFT (5U)
/*! ovrd_rx_term_gd_en - If asserted the ground termination enable value is controlled via registers */
#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_MASK)

#define ENET_PHY_LANE0_ANA_RX_TERM_rx_term_dc_en_reg_MASK (0x40U)
#define ENET_PHY_LANE0_ANA_RX_TERM_rx_term_dc_en_reg_SHIFT (6U)
/*! rx_term_dc_en_reg - If termination override is asserted, controls the DC termination enable */
#define ENET_PHY_LANE0_ANA_RX_TERM_rx_term_dc_en_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_TERM_rx_term_dc_en_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_TERM_rx_term_dc_en_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_dc_en_MASK (0x80U)
#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_dc_en_SHIFT (7U)
/*! ovrd_rx_term_dc_en - If asserted the DC termination enable value is controlled via registers */
#define ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_dc_en(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_dc_en_SHIFT)) & ENET_PHY_LANE0_ANA_RX_TERM_ovrd_rx_term_dc_en_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_SLC_CTRL - RX_SLC_CTRL */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_MASK (0xFU)
#define ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_SHIFT (0U)
/*! rx_slicer_ctrl_o_reg - If ovrd_rx_slicer_ctrl_reg is asserted, controls the odd slicer configuration */
#define ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_MASK)

#define ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_MASK (0xF0U)
#define ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_SHIFT (4U)
/*! rx_slicer_ctrl_e_reg - If ovrd_rx_slicer_ctrl_reg is asserted, controls the even slicer configuration */
#define ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_SHIFT)) & ENET_PHY_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_CDR_VCO_CTRL - RX_CDR_VCO_CTRL */
/*! @{ */

#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_afe_att_cm_regs_ovrd_MASK (0x1U)
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_afe_att_cm_regs_ovrd_SHIFT (0U)
/*! afe_att_cm_regs_ovrd - If asserted, the rx_misc[4:3] is overridden by the afe_att_cm_regs for setting the vcm_eq level */
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_afe_att_cm_regs_ovrd(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_afe_att_cm_regs_ovrd_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_afe_att_cm_regs_ovrd_MASK)

#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_rx_vco_vreg_bypass_MASK (0x2U)
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_rx_vco_vreg_bypass_SHIFT (1U)
/*! creg_rx_vco_vreg_bypass - Forces vreg_rx_vco to vph (regulator bypass) when asserted */
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_rx_vco_vreg_bypass(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_rx_vco_vreg_bypass_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_rx_vco_vreg_bypass_MASK)

#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_lowfreq_MASK (0xCU)
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_lowfreq_SHIFT (2U)
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_lowfreq(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_lowfreq_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_lowfreq_MASK)

#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_misc_ctrl_MASK (0xF0U)
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_misc_ctrl_SHIFT (4U)
#define ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_misc_ctrl(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_misc_ctrl_SHIFT)) & ENET_PHY_LANE0_ANA_RX_CDR_VCO_CTRL_creg_cdr_vco_misc_ctrl_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_OVRD_IN - Override Values for Incoming TX Controls from PCS */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_SHIFT (0U)
/*! PSTATE - Override Value for tx_pstate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_SHIFT (2U)
/*! LPD - Override Value for tx_lpd
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_MASK (0x18U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_SHIFT (3U)
/*! WIDTH - Override Value for tx_width */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_MASK (0xE0U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_SHIFT (5U)
/*! RATE - Override Value for tx_rate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_MASK (0x100U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_SHIFT (8U)
/*! MPLLB_SEL - Override Value for tx_mpllb_sel
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_MASK (0x200U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_SHIFT (9U)
/*! MPLL_EN - Override Value for tx_mpll_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_MASK (0x400U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_SHIFT (10U)
/*! MSTR_MPLLA_STATE - Override Value for tx_master_mplla_state
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_MASK (0x800U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_SHIFT (11U)
/*! MSTR_MPLLB_STATE - Override Value for tx_master_mpllb_state
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_SHIFT (12U)
/*! OVRD_EN - Override Enable for All Input Signals Below
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_OVRD_EN_MASK (0x2000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_OVRD_EN_SHIFT (13U)
/*! MSTR_MPLLA_STATE_OVRD_EN - Override Enable for tx_master_mplla_state
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_OVRD_EN_SHIFT (14U)
/*! MSTR_MPLLB_STATE_OVRD_EN - Override Enable for tx_master_mpllb_state
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1 - Override Values for Incoming TX Controls from PCS 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT (0U)
/*! RESET_OVRD_VAL - Override Value for tx_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_SHIFT (1U)
/*! RESET_OVRD_EN - Override Enable for tx_reset
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT (2U)
/*! REQ_OVRD_VAL - Override Value for tx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_SHIFT (3U)
/*! REQ_OVRD_EN - Override Enable for tx_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_SHIFT (4U)
/*! DETRX_REQ_OVRD_VAL - Override Value for tx_detrx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_MASK (0x20U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_SHIFT (5U)
/*! DETRX_REQ_OVRD_EN - Override Enable for tx_detrx_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_SHIFT (6U)
/*! VBOOST_EN_OVRD_VAL - Override Value for tx_vboost_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_SHIFT (7U)
/*! VBOOST_EN_OVRD_EN - Override Enable for tx_vboost_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_MASK (0xF00U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_SHIFT (8U)
/*! IBOOST_LVL_OVRD_VAL - Override Value for tx_iboost_lvl[3:0] */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_SHIFT (12U)
/*! IBOOST_LVL_OVRD_EN - Override Enable for tx_iboost_lvl[3:0]
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_PCS_IN - Current Values for Incoming TX Controls from PCS (Pre-Override Input Monitor) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_SHIFT (0U)
/*! RESET - Value from PCS for tx_reset */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_SHIFT (1U)
/*! REQ - Value from PCS for tx_req */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_MASK (0xCU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_SHIFT (2U)
/*! PSTATE - Value from PCS for tx_pstate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_SHIFT (4U)
/*! LPD - Value from PCS for tx_lpd */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_MASK (0x60U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_SHIFT (5U)
/*! WIDTH - Value from PCS for tx_width */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_MASK (0x380U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_SHIFT (7U)
/*! RATE - Value from PCS for tx_rate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_MASK (0x400U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_SHIFT (10U)
/*! MPLLB_SEL - Value from PCS for tx_mpllb_sel */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_MASK (0x800U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_SHIFT (11U)
/*! MPLL_EN - Value from PCS for tx_mpll_en */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_SHIFT (12U)
/*! MSTR_MPLLB_STATE - Value from PCS for tx_master_mpllb_state */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_MASK (0x2000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_SHIFT (13U)
/*! MSTR_MPLLA_STATE - Value from PCS for tx_master_mplla_state */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_SHIFT (14U)
/*! DETRX_REQ - Value from PCS for tx_detrx_req */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT - Override Values for Outgoing TX Controls to PCS */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_SHIFT (0U)
/*! ACK - Override Value for tx_ack
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_SHIFT (1U)
/*! DETRX_RESULT - Override Value for tx_detrx_result
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_SHIFT (2U)
/*! EN_CTL - Enable Override Values for All Control Outputs of this Register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_PCS_OUT - Current Values for Outgoing TX Status Controls from Raw PCS (Pre-Override Output Monitor) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_SHIFT (0U)
/*! ACK - Value from Raw PCS for tx_ack */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN - Override Values for Incoming RX Controls from PCS */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_SHIFT (0U)
/*! RATE - Override Value for rx_rate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_MASK (0xCU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_SHIFT (2U)
/*! WIDTH - Override Value for rx_width */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_MASK (0x30U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_SHIFT (4U)
/*! PSTATE - Override Value for rx_pstate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_SHIFT (6U)
/*! LPD - Override Value for rx_lpd
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_SHIFT (7U)
/*! OVRD_EN - Enable Override Values for All Fields in this Register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_DFE_BYPASS_MASK (0x100U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_DFE_BYPASS_SHIFT (8U)
/*! DFE_BYPASS - Override Value for rx_dfe_bypass
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_DFE_BYPASS_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_DFE_BYPASS_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1 - Override Values for Incoming RX Controls from PCS 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT (0U)
/*! RESET_OVRD_VAL - Override Value for rx_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_SHIFT (1U)
/*! RESET_OVRD_EN - Override Enable for rx_reset
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT (2U)
/*! REQ_OVRD_VAL - Override Value for rx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_SHIFT (3U)
/*! REQ_OVRD_EN - Override Enable for rx_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2 - Override Values for Incoming RX Controls from PCS 2 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_MASK (0x1FFFU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_SHIFT (0U)
/*! VCO_LD_VAL_OVRD - Override Value for rx_vco_ld_val */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_MASK (0x2000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_SHIFT (13U)
/*! VCO_LD_VAL_OVRD_EN - Enable Override for rx_vco_ld_val
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2 - ATE Override Input to Control Top-Level Inputs 3 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_VAL_MASK (0x7U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_VAL_SHIFT (0U)
/*! RX_LOS_THRSHLD_OVRD_VAL - Override Value for rx_los_threshold */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_EN_SHIFT (3U)
/*! RX_LOS_THRSHLD_OVRD_EN - Enable Override for rx_los_threshold
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_RX_LOS_THRSHLD_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_SHIFT (4U)
/*! ADAPT_REQ - Override Value for rx_adapt_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_OVRD_EN_MASK (0x20U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_OVRD_EN_SHIFT (5U)
/*! ADAPT_REQ_OVRD_EN - Enable Override Values for rx_adapt_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_REQ_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_CONT_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_CONT_SHIFT (6U)
/*! ADAPT_CONT - Override Value for rx_adapt_cont
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_ADAPT_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_OFFCAN_CONT_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_OFFCAN_CONT_SHIFT (7U)
/*! OFFCAN_CONT - Override Value for rx_offcan_cont
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_OFFCAN_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_OFFCAN_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_OFFCAN_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_CONT_OVRD_EN_MASK (0x100U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_CONT_OVRD_EN_SHIFT (8U)
/*! CONT_OVRD_EN - Enable Override Values for rx_adapt_cont and rx_offcan_cont
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_CONT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_CONT_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_2_CONT_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN - Current Values for Incoming RX Controls from PCS (Monitor on Post ATE Override) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_SHIFT (0U)
/*! REQ - Value from PCS for rx_req */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_MASK (0x6U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_SHIFT (1U)
/*! RATE - Value from PCS for rx_rate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_MASK (0x18U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_SHIFT (3U)
/*! WIDTH - Value from PCS for rx_width */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_MASK (0x60U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_SHIFT (5U)
/*! PSTATE - Value from PCS for rx_pstate */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_SHIFT (7U)
/*! LPD - Value from PCS for rx_lpd */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_FREQBAND_MASK (0x300U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_FREQBAND_SHIFT (8U)
/*! CDR_VCO_FREQBAND - Value from PCS for rx_cdr_vco_freqband */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_FREQBAND(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_FREQBAND_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_FREQBAND_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RX_DFE_BYPASS_MASK (0x400U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RX_DFE_BYPASS_SHIFT (10U)
/*! RX_DFE_BYPASS - Value from PCS for rx_dfe_bypass */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RX_DFE_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RX_DFE_BYPASS_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RX_DFE_BYPASS_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_MASK (0x800U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_SHIFT (11U)
/*! ADAPT_REQ - Value from PCS for rx_adapt_req */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_SHIFT (12U)
/*! ADAPT_CONT - Value from PCS for rx_adapt_cont */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_MASK (0x2000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_SHIFT (13U)
/*! OFFCAN_CONT - Value from PCS for rx_offcan_cont */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_SHIFT (14U)
/*! RESET - Value from PCS for rx_reset */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1 - Current Values for Incoming RX Controls from PCS 1 (Monitor on Pre-Override Signals) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_MASK (0x7FU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_SHIFT (0U)
/*! REF_LD_VAL - Value from PCS for rx_ref_ld_val */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2 - Current Values for Incoming RX Controls from PCS 2 (Monitor on the Pre-Override Signals) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_MASK (0x1FFFU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_SHIFT (0U)
/*! VCO_LD_VAL - Value from PCS for rx_vco_ld_val */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3 - Current Values for Incoming RX Controls from PCS 3 (Monitor on the Pre-Override Signals) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_MASK (0x7U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_SHIFT (0U)
/*! EQ_ATT_LVL - Value from ASIC for rx_eq_att_lvl */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_MASK (0x38U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_SHIFT (3U)
/*! EQ_VGA1_GAIN - Value from ASIC for rx_eq_vga1_gain */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_MASK (0x1C0U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_SHIFT (6U)
/*! EQ_VGA2_GAIN - Value from ASIC for rx_eq_vga2_gain */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_MASK (0x3E00U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_SHIFT (9U)
/*! EQ_CTLE_BOOST - Value from ASIC for rx_eq_ctle_boost */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4 - Current Values for Incoming RX Controls from PCS 4 (Monitor on the Pre-Override Signals) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_SHIFT (0U)
/*! EQ_CTLE_POLE - Value from ASIC for rx_eq_ctle_pole */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_MASK (0x3FCU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_SHIFT (2U)
/*! EQ_DFE_TAP1 - Value from ASIC for rx_eq_dfe_tap1 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT - Override Values for Outgoing RX Controls to PCS */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_SHIFT (0U)
/*! ACK - Override value for rx_ack
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_SHIFT (1U)
/*! EN_CTL - Enable Override Values for All Control Outputs of this Register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_OUT - Current Values for Outgoing RX Status Controls from Raw PCS */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_SHIFT (0U)
/*! ACK - Value from Raw PCS for rx_ack */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK - RX Adaptation Acknowledge */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_SHIFT (0U)
/*! RX_ADAPT_ACK - RX Adaptation Acknowledge */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM - RX Adaptation Figure of Merit */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_SHIFT (0U)
/*! RX_ADAPT_FOM - RX Adaptation Figure of Merit */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR - RX Calculated Direction for TX-Pre */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_SHIFT (0U)
/*! RX_TXPRE_DIR - RX Calculated Direction for TX-Pre
 *  0b00..No change
 *  0b01..Increment
 *  0b10..Decrement
 *  0b11..Reserved
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR - RX Calculated Direction for TX-Main */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_SHIFT (0U)
/*! RX_TXMAIN_DIR - RX Calculated Direction for TX-Main
 *  0b00..No change
 *  0b01..Increment
 *  0b10..Decrement
 *  0b11..Reserved
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR - RX Calculated Direction for TX-Post */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_SHIFT (0U)
/*! RX_TXPOST_DIR - RX Calculated Direction for TX-Post
 *  0b00..No change
 *  0b01..Increment
 *  0b10..Decrement
 *  0b11..Reserved
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_LANE_NUMBER - Current Lane Number */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_MASK (0xFU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_SHIFT (0U)
/*! LANE_NUMBER - Current Lane Number */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN - ATE Override Input to Control Top-Level Inputs 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_SHIFT (0U)
/*! RX_RESET_ATE_OVRD_VAL - ATE Override Value for Top-Level rx_reset Input
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_SHIFT (1U)
/*! RX_RESET_ATE_OVRD_EN - Enable ATE Override Value for rx_reset Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_SHIFT (2U)
/*! TX_RESET_ATE_OVRD_VAL - ATE Override Value for Top-Level tx_reset Input
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_SHIFT (3U)
/*! TX_RESET_ATE_OVRD_EN - Enable ATE Override Value for tx_reset Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_SHIFT (4U)
/*! RX_REQ_ATE_OVRD_VAL - ATE Override Value for Top-Level rx_req Input
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_MASK (0x20U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_SHIFT (5U)
/*! RX_REQ_ATE_OVRD_EN - Enable ATE Override Value for rx_req Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_SHIFT (6U)
/*! TX_REQ_ATE_OVRD_VAL - ATE Override Value for Top-Level tx_req Input
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_SHIFT (7U)
/*! TX_REQ_ATE_OVRD_EN - Enable ATE Override Value for tx_req Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_VAL_MASK (0x100U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_VAL_SHIFT (8U)
/*! RX_DFE_BYPASS_ATE_OVRD_VAL - ATE Override Value for rx_dfe_bypass Input
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_EN_MASK (0x200U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_EN_SHIFT (9U)
/*! RX_DFE_BYPASS_ATE_OVRD_EN - Enable ATE Override Value for rx_dfe_bypass Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_DFE_BYPASS_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_VAL_MASK (0xC00U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_VAL_SHIFT (10U)
/*! RX_RATE_ATE_OVRD_VAL - ATE Override Value for rx_rate Input */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_EN_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_EN_SHIFT (12U)
/*! RX_RATE_ATE_OVRD_EN - Enable ATE Override Value for rx_rate Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RATE_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_VAL_MASK (0x6000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_VAL_SHIFT (13U)
/*! RX_WIDTH_ATE_OVRD_VAL - ATE Override Value for rx_width Input */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_EN_MASK (0x8000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_EN_SHIFT (15U)
/*! RX_WIDTH_ATE_OVRD_EN - Enable ATE Override Value for rx_width Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_WIDTH_ATE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1 - Overrides the RX Output Clocks during the PHY Initialization 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_SHIFT (0U)
/*! RX_CLK_EN - Enable the Outgoing rx_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_DIV16P5_CLK_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_DIV16P5_CLK_EN_SHIFT (1U)
/*! RX_DIV16P5_CLK_EN - Enable the Outgoing rx_div16p5_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_DIV16P5_CLK_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4 - Override Values for Incoming RX Controls from PCS 4 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_VAL_SHIFT (0U)
/*! RX_CDR_VCO_STEP_CTRL_OVRD_VAL - Override Value for rx_cdr_vco_step_ctrl
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_EN_SHIFT (1U)
/*! RX_CDR_VCO_STEP_CTRL_OVRD_EN - Enable Override for rx_cdr_vco_step_ctrl
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_STEP_CTRL_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_VAL_SHIFT (2U)
/*! RX_CDR_VCO_TEMP_COMP_EN_OVRD_VAL - Override Value for rx_cdr_vco_temp_comp_en
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_EN_SHIFT (3U)
/*! RX_CDR_VCO_TEMP_COMP_EN_OVRD_EN - Enable Override for rx_cdr_vco_temp_comp_en
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_RX_CDR_VCO_TEMP_COMP_EN_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_MASK (0x30U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_SHIFT (4U)
/*! VCO_FREQBAND_VAL_OVRD - Override Value for rx_cdr_vco_freqband */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_EN_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_EN_SHIFT (6U)
/*! VCO_FREQBAND_VAL_OVRD_EN - Enable Override for rx_cdr_vco_freqband
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_VCO_FREQBAND_VAL_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_MASK (0x3F80U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_SHIFT (7U)
/*! REF_LD_VAL_OVRD - Override Value for rx_ref_ld_val */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_EN_SHIFT (14U)
/*! REF_LD_VAL_OVRD_EN - Enable Override for rx_ref_ld_val
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_4_REF_LD_VAL_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5 - RX Adaptation Mode Override */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_SHIFT (0U)
/*! RX_ADAPT_SEL_OVRD - Overridden Value for the RX Adaptation Setting */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_EN_SHIFT (1U)
/*! RX_ADAPT_SEL_OVRD_EN - Enable Override the RX Adaptation Setting
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_SEL_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_MASK (0xCU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_SHIFT (2U)
/*! RX_ADAPT_MODE - Overridden Value for RX Adaptation Mode */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_OVRD_EN_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_OVRD_EN_SHIFT (4U)
/*! RX_ADAPT_MODE_OVRD_EN - Enable Override for the RX Adaptation Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_MODE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_MASK (0x3E0U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_SHIFT (5U)
/*! RX_CDR_PPM_MAX_OVRD - Overridden Value for RX CDR PPM Max */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_EN_MASK (0x400U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_EN_SHIFT (10U)
/*! RX_CDR_PPM_MAX_OVRD_EN - Enable Override for the RX CDR PPM Max
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_CDR_PPM_MAX_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_MASK (0x800U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_SHIFT (11U)
/*! RX_ADAPT_IN_PROG_OVRD - Overridden Value for the RX Adaptation in Progress */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_EN_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_EN_SHIFT (12U)
/*! RX_ADAPT_IN_PROG_OVRD_EN - Enable Override for RX Adaptation in Progress
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_RX_ADAPT_IN_PROG_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_MASK (0x2000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_SHIFT (13U)
/*! ADAPT_REQ - Override Value for rx_adapt_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_OVRD_EN_SHIFT (14U)
/*! ADAPT_REQ_OVRD_EN - Enable Override Values for rx_adapt_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_5_ADAPT_REQ_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5 - Current Values for Incoming RX Controls from PCS 5 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_ADAPT_MODE_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_ADAPT_MODE_SHIFT (0U)
/*! ADAPT_MODE - Value from ASIC for rx_adapt_mode */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_ADAPT_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_ADAPT_MODE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_ADAPT_MODE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_SEL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_SEL_SHIFT (2U)
/*! RX_ADAPT_SEL - Value from ASIC for rx_adapt_sel */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_SEL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_SEL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_DELTA_IQ_MASK (0x78U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_DELTA_IQ_SHIFT (3U)
/*! RX_DELTA_IQ - Value from ASIC for rx_delta_iq */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_DELTA_IQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_DELTA_IQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_DELTA_IQ_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_MARGIN_IQ_MASK (0x3F80U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_MARGIN_IQ_SHIFT (7U)
/*! RX_MARGIN_IQ - Value from ASIC for rx_margin_iq */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_MARGIN_IQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_MARGIN_IQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_MARGIN_IQ_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_IN_PROG_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_IN_PROG_SHIFT (14U)
/*! RX_ADAPT_IN_PROG - Value from ASIC for rx_adapt_in_prog */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_IN_PROG(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_IN_PROG_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_5_RX_ADAPT_IN_PROG_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6 - Override Register for RX IQ Setting */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_MASK (0xFU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_SHIFT (0U)
/*! RX_DELTA_IQ_OVRD - Override the RX Delta IQ Setting */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_EN_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_EN_SHIFT (4U)
/*! RX_DELTA_IQ_OVRD_EN - Enable Override the RX Delta IQ Setting
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_DELTA_IQ_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_MASK (0xFE0U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_SHIFT (5U)
/*! RX_MARGIN_DELTA_OVRD - Override the RX margin IQ Setting */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_EN_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_EN_SHIFT (12U)
/*! RX_MARGIN_DELTA_OVRD_EN - Enable Override the RX Margin IQ Setting
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_6_RX_MARGIN_DELTA_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1 - Override Values for Incoming RX EQ Controls from PCS 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA1_GAIN_OVRD_VAL_MASK (0x7U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA1_GAIN_OVRD_VAL_SHIFT (0U)
/*! RX_EQ_VGA1_GAIN_OVRD_VAL - Override Value for rx_eq_vga1_gain[3:0] */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA1_GAIN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA1_GAIN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA1_GAIN_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA2_GAIN_OVRD_VAL_MASK (0x38U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA2_GAIN_OVRD_VAL_SHIFT (3U)
/*! RX_EQ_VGA2_GAIN_OVRD_VAL - Override Value for rx_eq_vga2_gain[3:0] */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA2_GAIN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA2_GAIN_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_VGA2_GAIN_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_MASK (0x1C0U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_SHIFT (6U)
/*! RX_EQ_ATT_LVL_OVRD_VAL - Override Value for rx_eq_att_lvl[2:0] */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_MASK (0x200U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_SHIFT (9U)
/*! RX_EQ_OVRD_EN - Enable Override Values for all RX EQ settings
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6 - Current Values for Incoming RX Controls from PCS 6 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_CDR_PPM_MAX_MASK (0x1FU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_CDR_PPM_MAX_SHIFT (0U)
/*! RX_CDR_PPM_MAX - Value from ASIC for rx_cdr_ppm_max */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_CDR_PPM_MAX(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_CDR_PPM_MAX_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_CDR_PPM_MAX_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_MISC_MASK (0x1FE0U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_MISC_SHIFT (5U)
/*! RX_MISC - Value from ASIC fro rx_misc */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_MISC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_MISC_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_6_RX_MISC_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1 - ATE Override Input to Control Top-Level Inputs 2 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_VAL_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_VAL_SHIFT (0U)
/*! RX_PSTATE_ATE_OVRD_VAL - ATE Override Value for Top-Level rx_pstate Input */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_EN_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_EN_SHIFT (2U)
/*! RX_PSTATE_ATE_OVRD_EN - Enable ATE Override Value for rx_pstate Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_PSTATE_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_VAL_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_VAL_SHIFT (3U)
/*! RX_LPD_ATE_OVRD_VAL - ATE Override Value for Top-Level rx_lpd Input
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_EN_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_EN_SHIFT (4U)
/*! RX_LPD_ATE_OVRD_EN - Enable ATE Override Value for rx_lpd Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_LPD_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_VAL_MASK (0x1E0U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_VAL_SHIFT (5U)
/*! RX_DELTA_IQ_ATE_OVRD_VAL - ATE Override Value for Top-Level rx_delta_iq Input */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_EN_MASK (0x200U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_EN_SHIFT (9U)
/*! RX_DELTA_IQ_ATE_OVRD_EN - Enable ATE Override Value for rx_delta_iq Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_DELTA_IQ_ATE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_VAL_MASK (0x400U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_VAL_SHIFT (10U)
/*! RX_ADAPT_SEL_ATE_OVRD_VAL - ATE Override Value for Top-Level rx_adapt_sel Input
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_EN_MASK (0x800U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_EN_SHIFT (11U)
/*! RX_ADAPT_SEL_ATE_OVRD_EN - Enable ATE Override Value for rx_adapt_sel Input
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_1_RX_ADAPT_SEL_ATE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2 - Override Values for Incoming RX EQ Controls from PCS 2 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_SHIFT (0U)
/*! RX_EQ_DFE_TAP1_OVRD_VAL - Override value for rx_eq_dfe_tap1[7:0] */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_MASK (0x1F00U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_SHIFT (8U)
/*! RX_EQ_CTLE_BOOST_OVRD_VAL - Override Value for rx_eq_ctle_boost[4:0] */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_POLE_OVRD_VAL_MASK (0x6000U)
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_POLE_OVRD_VAL_SHIFT (13U)
/*! RX_EQ_CTLE_POLE_OVRD_VAL - Override Value for rx_eq_ctle_pole[2:0] */
#define ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_POLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_POLE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_POLE_OVRD_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FSM_OVRD_CTL - FSM Override Control */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_SHIFT (0U)
/*! FSM_JMP_ADDR - The jump address used when FSM_JUMP_EN=1. The address is encoded as follows: [11:8] mem_lane, [7:5] bank, [4:0] register */
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_MASK (0x1000U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_SHIFT (12U)
/*! FSM_JMP_EN - Force the FSM to jump to FSM_JMP_ADDR in the program memory. Is applied when FSM_CMD_START is pulsed */
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_MASK (0x2000U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_SHIFT (13U)
/*! FSM_CMD_START - Execute the current command or resume from breakpoint. This is a self-clearing bit */
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_SHIFT (14U)
/*! FSM_OVRD_EN - Enable overriding the FSM execution of commands. Must be asserted to use FSM_CMD_START and FSM_JMP_EN features
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FSM_JMP_BANK - FSM Jump Bank */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_JMP_BANK_BANK_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_JMP_BANK_BANK_SHIFT (0U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FSM_JMP_BANK_BANK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FSM_JMP_BANK_BANK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FSM_JMP_BANK_BANK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0 - FSM Breakpoint 0 on SRAM Address for Debugging */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_ADDR_MASK (0x3FFFU)
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_ADDR_SHIFT (0U)
/*! BREAKPOINT_ADDR - Memory Address for Breakpoint 0 */
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_ADDR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_ADDR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_ADDR_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_EN_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_EN_SHIFT (14U)
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_0_BREAKPOINT_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1 - FSM Breakpoint 1 on SRAM Address for Debugging */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_ADDR_MASK (0x3FFFU)
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_ADDR_SHIFT (0U)
/*! BREAKPOINT_ADDR - Memory Address for Breakpoint 1 */
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_ADDR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_ADDR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_ADDR_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_EN_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_EN_SHIFT (14U)
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_MEM_BREAKPOINT_1_BREAKPOINT_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_MEM_ADDR_MON - Memory Address Monitor */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_SHIFT (0U)
/*! MEM_ADDR - Current value of memory address used in Lane FSM */
#define ENET_PHY_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_STATUS_MON - FSM Status Monitor */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_STATE_MASK (0x1FU)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_STATE_SHIFT (0U)
/*! STATE - Current state of Lane FSM */
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_MASK (0x20U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_SHIFT (5U)
/*! CMD_RDY - New command is ready for execution (applicable when FSM_OVRD_EN=1) */
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_SHIFT (6U)
/*! ALU_OVFLW - Current value of ALU overflow bit */
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_SHIFT (7U)
/*! ALU_RES_EQ0 - Check if ALU result register currently equals zero */
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_MASK (0x100U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_SHIFT (8U)
/*! WAIT_CNT_EQ0 - Check if wait counter currently equals zero */
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_MASK (0x200U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_SHIFT (9U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_MASK)

#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_MASK (0x400U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_SHIFT (10U)
#define ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL - Status of Fast RX Start Up Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_SHIFT (0U)
/*! FAST_RX_STARTUP_CAL - Status of Fast RX Start Up Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_ADAPT - Status of Fast RX Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_SHIFT (0U)
/*! FAST_RX_ADAPT - Status of Fast RX Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_SUP - Status of Fast Support Block */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_SHIFT (0U)
/*! FAST_SUP - Status of Fast Support Block (MPLL and Rtune) */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE - Status of Fast TX Common-Mode Charge-Up */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_SHIFT (0U)
/*! FAST_TX_CMN_MODE - Status of Fast TX Common-Mode Charge-Up */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_TX_RXDET - Status of Fast TX Detect RX */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_SHIFT (0U)
/*! FAST_TX_RXDET - Status of Fast TX Detect RX */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_PWRUP - Status of Fast RX Power-Up */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_SHIFT (0U)
/*! FAST_RX_PWRUP - Status of Fast RX Power-Up (LOS, VREG/AFE and DCC) */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT - Status of Fast RX VCO Wait Times */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_SHIFT (0U)
/*! FAST_RX_VCO_WAIT - Status of Fast RX VCO Wait Times */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL - Status of Fast RX VCO Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_SHIFT (0U)
/*! FAST_RX_VCO_CAL - Status of Fast RX VCO Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT - Status of Fast RX Continuous Calibration/Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_SHIFT (0U)
/*! FAST_RX_CONT_CAL_ADAPT - Status of Fast RX Continuous Calibration/Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT - Status of Fast RX Continuous Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_SHIFT (0U)
/*! FAST_RX_CONT_ADAPT - Status of Fast RX Continuous Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_CAL - Status of RX AFE Startup Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_CAL_SKIP_RX_AFE_STARTUP_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_CAL_SKIP_RX_AFE_STARTUP_CAL_SHIFT (0U)
/*! SKIP_RX_AFE_STARTUP_CAL - Status of RX AFE start-up calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_CAL_SKIP_RX_AFE_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_CAL_SKIP_RX_AFE_STARTUP_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_CAL_SKIP_RX_AFE_STARTUP_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_CAL - Status of RX DFE Startup Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_CAL_SKIP_RX_DFE_STARTUP_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_CAL_SKIP_RX_DFE_STARTUP_CAL_SHIFT (0U)
/*! SKIP_RX_DFE_STARTUP_CAL - Status of RX DFE Startup Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_CAL_SKIP_RX_DFE_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_CAL_SKIP_RX_DFE_STARTUP_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_CAL_SKIP_RX_DFE_STARTUP_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_DFE_EXT_STARTUP_CAL - Status of DFE Extended Startup Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_EXT_STARTUP_CAL_SKIP_RX_DFE_EXT_STARTUP_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_EXT_STARTUP_CAL_SKIP_RX_DFE_EXT_STARTUP_CAL_SHIFT (0U)
/*! SKIP_RX_DFE_EXT_STARTUP_CAL - Status of DFE Extended Startup Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_EXT_STARTUP_CAL_SKIP_RX_DFE_EXT_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_EXT_STARTUP_CAL_SKIP_RX_DFE_EXT_STARTUP_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_EXT_STARTUP_CAL_SKIP_RX_DFE_EXT_STARTUP_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_IQ_DELTA_STARTUP - Status of RX IQ Fixed Offset */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_DELTA_STARTUP_SKIP_RX_IQ_DELTA_STARTUP_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_DELTA_STARTUP_SKIP_RX_IQ_DELTA_STARTUP_SHIFT (0U)
/*! SKIP_RX_IQ_DELTA_STARTUP - Status of RX IQ Fixed Offset */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_DELTA_STARTUP_SKIP_RX_IQ_DELTA_STARTUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_DELTA_STARTUP_SKIP_RX_IQ_DELTA_STARTUP_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_DELTA_STARTUP_SKIP_RX_IQ_DELTA_STARTUP_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_CAL - Status of RX IQ Startup Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_CAL_SKIP_RX_IQ_STARTUP_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_CAL_SKIP_RX_IQ_STARTUP_CAL_SHIFT (0U)
/*! SKIP_RX_IQ_STARTUP_CAL - Status of RX IQ Startup Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_CAL_SKIP_RX_IQ_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_CAL_SKIP_RX_IQ_STARTUP_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_CAL_SKIP_RX_IQ_STARTUP_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_ADAPT - Status of RX AFE Startup Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_ADAPT_SKIP_RX_AFE_STARTUP_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_ADAPT_SKIP_RX_AFE_STARTUP_ADAPT_SHIFT (0U)
/*! SKIP_RX_AFE_STARTUP_ADAPT - Status of RX AFE DAC Startup Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_ADAPT_SKIP_RX_AFE_STARTUP_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_ADAPT_SKIP_RX_AFE_STARTUP_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_STARTUP_ADAPT_SKIP_RX_AFE_STARTUP_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_ADAPT - Status of RX DFE Startup Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_ADAPT_SKIP_RX_DFE_STARTUP_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_ADAPT_SKIP_RX_DFE_STARTUP_ADAPT_SHIFT (0U)
/*! SKIP_RX_DFE_STARTUP_ADAPT - Status of RX DFE DAC Startup Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_ADAPT_SKIP_RX_DFE_STARTUP_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_ADAPT_SKIP_RX_DFE_STARTUP_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_DFE_STARTUP_ADAPT_SKIP_RX_DFE_STARTUP_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_ADAPT - Status of RX IO Startup Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_ADAPT_SKIP_RX_IQ_STARTUP_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_ADAPT_SKIP_RX_IQ_STARTUP_ADAPT_SHIFT (0U)
/*! SKIP_RX_IQ_STARTUP_ADAPT - Status of RX IQ Startup Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_ADAPT_SKIP_RX_IQ_STARTUP_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_ADAPT_SKIP_RX_IQ_STARTUP_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_IQ_STARTUP_ADAPT_SKIP_RX_IQ_STARTUP_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_CONT_PHASE_CAL - Status of RX Continuous Phase Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_CONT_PHASE_CAL_SKIP_RX_CONT_PHASE_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_CONT_PHASE_CAL_SKIP_RX_CONT_PHASE_CAL_SHIFT (0U)
/*! SKIP_RX_CONT_PHASE_CAL - Status of RX Continuous Phase Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_CONT_PHASE_CAL_SKIP_RX_CONT_PHASE_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_CONT_PHASE_CAL_SKIP_RX_CONT_PHASE_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_CONT_PHASE_CAL_SKIP_RX_CONT_PHASE_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_AFE_CONT_CAL - Status of RX AFE Continuous Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_CONT_CAL_SKIP_RX_AFE_CONT_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_CONT_CAL_SKIP_RX_AFE_CONT_CAL_SHIFT (0U)
/*! SKIP_RX_AFE_CONT_CAL - Status of RX AFE Continuous Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_CONT_CAL_SKIP_RX_AFE_CONT_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_CONT_CAL_SKIP_RX_AFE_CONT_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_AFE_CONT_CAL_SKIP_RX_AFE_CONT_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_REFLVL_CONT_ADAPT - Status of RX Reference Level Continuous Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_REFLVL_CONT_ADAPT_SKIP_RX_REFLVL_CONT_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_REFLVL_CONT_ADAPT_SKIP_RX_REFLVL_CONT_ADAPT_SHIFT (0U)
/*! SKIP_RX_REFLVL_CONT_ADAPT - Status of RX Reference Level Continuous Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_REFLVL_CONT_ADAPT_SKIP_RX_REFLVL_CONT_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_REFLVL_CONT_ADAPT_SKIP_RX_REFLVL_CONT_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_REFLVL_CONT_ADAPT_SKIP_RX_REFLVL_CONT_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_VGA_CONT_ADAPT - Status of RX VGA Continuous Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_VGA_CONT_ADAPT_SKIP_RX_VGA_CONT_ADAPT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_VGA_CONT_ADAPT_SKIP_RX_VGA_CONT_ADAPT_SHIFT (0U)
/*! SKIP_RX_VGA_CONT_ADAPT - Status of RX VGA Continuous Adaptation */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_VGA_CONT_ADAPT_SKIP_RX_VGA_CONT_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_VGA_CONT_ADAPT_SKIP_RX_VGA_CONT_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_VGA_CONT_ADAPT_SKIP_RX_VGA_CONT_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_PHS_STARTUP_CAL - Status of RX Phase Startup Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_STARTUP_CAL_SKIP_RX_PHS_STARTUP_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_STARTUP_CAL_SKIP_RX_PHS_STARTUP_CAL_SHIFT (0U)
/*! SKIP_RX_PHS_STARTUP_CAL - Status of RX Phase Startup Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_STARTUP_CAL_SKIP_RX_PHS_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_STARTUP_CAL_SKIP_RX_PHS_STARTUP_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_STARTUP_CAL_SKIP_RX_PHS_STARTUP_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_SKIP_RX_PHS_EXT_STARTUP_CAL - Status of RX Phase Extended Startup Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_EXT_STARTUP_CAL_SKIP_RX_PHS_EXT_STARTUP_CAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_EXT_STARTUP_CAL_SKIP_RX_PHS_EXT_STARTUP_CAL_SHIFT (0U)
/*! SKIP_RX_PHS_EXT_STARTUP_CAL - Status of RX Phase Extended Startup Calibration */
#define ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_EXT_STARTUP_CAL_SKIP_RX_PHS_EXT_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_EXT_STARTUP_CAL_SKIP_RX_PHS_EXT_STARTUP_CAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_SKIP_RX_PHS_EXT_STARTUP_CAL_SKIP_RX_PHS_EXT_STARTUP_CAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FW_STATES_1 - Stores Various States for Firmware - 2 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_FSM_FW_STATES_1_SPARE_STATE_0_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_FSM_FW_STATES_1_SPARE_STATE_0_SHIFT (0U)
/*! SPARE_STATE_0 - Spare Fields to be Used by Firmware */
#define ENET_PHY_RAWLANE0_DIG_FSM_FW_STATES_1_SPARE_STATE_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_FSM_FW_STATES_1_SPARE_STATE_0_SHIFT)) & ENET_PHY_RAWLANE0_DIG_FSM_FW_STATES_1_SPARE_STATE_0_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST - Offset Value for RX AFE ATT iDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_SHIFT (0U)
/*! AFE_ATT_IDAC_OFST - Offset Value for AFE ATT iDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST - Offset Value for RX AFE CTLE iDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_SHIFT (0U)
/*! AFE_CTLE_IDAC_OFST - Offset Value for AFE CTLE iDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_AFE_VGA1_IDAC_OFST - Offset Values for RX AFE VGA1 iDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_AFE_VGA1_IDAC_OFST_AFE_VGA1_IDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_AFE_VGA1_IDAC_OFST_AFE_VGA1_IDAC_OFST_SHIFT (0U)
/*! AFE_VGA1_IDAC_OFST - Offset Value for AFE VGA1 iDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_AFE_VGA1_IDAC_OFST_AFE_VGA1_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_AFE_VGA1_IDAC_OFST_AFE_VGA1_IDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_AFE_VGA1_IDAC_OFST_AFE_VGA1_IDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST - Offset Values for RX DFE Phase Even vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_PHASE_EVEN_VDAC_OFST - Offset Value for DFE Phase Even vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST - Offset Values for RX DFE Phase Odd vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_PHASE_ODD_VDAC_OFST - Offset Value for DFE Phase Odd vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_PHASE_EVEN_LOW_VDAC_OFST - Offset Values for RX DFE Phase Even Low vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_LOW_VDAC_OFST_DFE_PHASE_EVEN_LOW_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_LOW_VDAC_OFST_DFE_PHASE_EVEN_LOW_VDAC_OFST_SHIFT (0U)
/*! DFE_PHASE_EVEN_LOW_VDAC_OFST - Offset Value for DFE Phase Even Low vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_LOW_VDAC_OFST_DFE_PHASE_EVEN_LOW_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_LOW_VDAC_OFST_DFE_PHASE_EVEN_LOW_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_LOW_VDAC_OFST_DFE_PHASE_EVEN_LOW_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_PHASE_ODD_LOW_VDAC_OFST - Offset Values for RX DFE Phase Odd Low vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_LOW_VDAC_OFST_DFE_PHASE_ODD_LOW_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_LOW_VDAC_OFST_DFE_PHASE_ODD_LOW_VDAC_OFST_SHIFT (0U)
/*! DFE_PHASE_ODD_LOW_VDAC_OFST - Offset Value for DFE Phase Odd Low vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_LOW_VDAC_OFST_DFE_PHASE_ODD_LOW_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_LOW_VDAC_OFST_DFE_PHASE_ODD_LOW_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_PHASE_ODD_LOW_VDAC_OFST_DFE_PHASE_ODD_LOW_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_PHSADJ_LIN - RX Phase Adjust Linear Value */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_MASK (0x3FU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_SHIFT (0U)
/*! RX_PHSADJ_LIN - Linear Value for RX Phase Adjust */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST - Offset Values for RX DFE Data Even High vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_EVEN_HIGH_VDAC_OFST - Offset Value for DFE Data Even High vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_DATA_EVEN_LOW_VDAC_OFST - Offset Values for RX DFE Data Even Low vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_EVEN_LOW_VDAC_OFST - Offset Value for DFE Data Even Low vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_EVEN_LOW_VDAC_OFST_DFE_DATA_EVEN_LOW_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST - Offset Values for RX DFE Data Odd High vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_ODD_HIGH_VDAC_OFST - Offset Value for DFE Data Odd High vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_DATA_ODD_LOW_VDAC_OFST - Offset Values for RX DFE Data Odd Low vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_ODD_LOW_VDAC_OFST - Offset Value for DFE Data Odd Low vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_DATA_ODD_LOW_VDAC_OFST_DFE_DATA_ODD_LOW_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST - Offset Values for RX DFE By-Pass Even vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_BYPASS_EVEN_VDAC_OFST - Offset Value for DFE By-Pass Even vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST - Offset Values for RX DFE By-Pass Odd vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_BYPASS_ODD_VDAC_OFST - Offset Value for DFE By-Pass Odd vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST - Offset Values for RX DFE Error Even vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_EVEN_VDAC_OFST - Offset Value for DFE Error Even vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST - Offset Values for RX DFE Error Odd vDAC */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_ODD_VDAC_OFST - Offset Value for DFE Error Odd vDAC */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_CAL_IQ - Value for RX Calibrated IQ Phase */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_IQ_RX_CAL_IQ_MASK (0x7FU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_IQ_RX_CAL_IQ_SHIFT (0U)
/*! RX_CAL_IQ - Value for RX Calibrated IQ Phase */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_IQ_RX_CAL_IQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_IQ_RX_CAL_IQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_IQ_RX_CAL_IQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL - Set to Skip Firmware Mission-Mode Algorithms */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_FOM_CONT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_FOM_CONT_SHIFT (0U)
/*! SKIP_RX_FOM_CONT - Skip RX Continuous FOM Measurement
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_FOM_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_FOM_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_FOM_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_REFLVL_ADAPT_CONT_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_REFLVL_ADAPT_CONT_SHIFT (1U)
/*! SKIP_RX_REFLVL_ADAPT_CONT - Skip RX REF Continuous Adaptation
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_REFLVL_ADAPT_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_REFLVL_ADAPT_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_REFLVL_ADAPT_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_VGA_ADAPT_CONT_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_VGA_ADAPT_CONT_SHIFT (2U)
/*! SKIP_RX_VGA_ADAPT_CONT - Skip RX VGA Continuous Adaptation
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_VGA_ADAPT_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_VGA_ADAPT_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_VGA_ADAPT_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_PHS_CAL_CONT_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_PHS_CAL_CONT_SHIFT (3U)
/*! SKIP_RX_PHS_CAL_CONT - Skip RX Phase Slicer Offset Calibration
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_PHS_CAL_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_PHS_CAL_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_PHS_CAL_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_AFE_CAL_CONT_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_AFE_CAL_CONT_SHIFT (4U)
/*! SKIP_RX_AFE_CAL_CONT - Skip RX AFE DAC Continuous Calibration
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_AFE_CAL_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_AFE_CAL_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_AFE_CAL_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_CAL_CONT_MASK (0x20U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_CAL_CONT_SHIFT (5U)
/*! SKIP_RX_DFE_CAL_CONT - Skip RX DFE Slicer Continuous Calibration
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_CAL_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_CAL_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_CAL_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT25_CONT_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT25_CONT_SHIFT (6U)
/*! SKIP_RX_DFE_ADAPT25_CONT - Skip RX DFE DAC Continuous Adaptation for Tap2 - Tap5
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT25_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT25_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT25_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT1_CONT_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT1_CONT_SHIFT (7U)
/*! SKIP_RX_DFE_ADAPT1_CONT - Skip RX DFE DAC Continuous Adaptation for Tap1
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT1_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT1_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_DFE_ADAPT1_CONT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_CTLE_BOOST_CONT_MASK (0x100U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_CTLE_BOOST_CONT_SHIFT (8U)
/*! SKIP_RX_CTLE_BOOST_CONT - Skip RX CTLE Boost Continuous Adaptation
 *  0b0..No skip
 *  0b1..Skip
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_CTLE_BOOST_CONT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_CTLE_BOOST_CONT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CONT_ALGO_CTL_SKIP_RX_CTLE_BOOST_CONT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_INIT_PWRUP_DONE - Initial Power-Up Done Status */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_SHIFT (0U)
/*! INIT_PWRUP_DONE - Indicates whether initial power-up has completed or not
 *  0b0..Not completed
 *  0b1..Completed
 */
#define ENET_PHY_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_ATT - RX Adapted Value of ATT */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_SHIFT (0U)
/*! ATT_ADPT_VAL - Stored RX Adapted ATT Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_VGA - RX Adapted Value of VGA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_MASK (0x1FFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_SHIFT (0U)
/*! VGA_ADPT_VAL - Stored RX Adapted VGA Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_CTLE - RX Adapted Value of CTLE */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_MASK (0x3FFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_SHIFT (0U)
/*! CTLE_BOOST_ADPT_VAL - Stored RX Adapted CTLE Boost Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_MASK (0xC00U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_SHIFT (10U)
/*! CTLE_POLE_ADPT_VAL - Stored RX Adapted CTLE Pole Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1 - RX Adapted Value of DFE TAP1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_MASK (0x1FFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP1_ADPT_VAL - Stored RX Adapted DFE TAP1 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2 - RX Adapted Value of DFE TAP2 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP2_ADPT_VAL - Stored RX Adapted DFE TAP2 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3 - RX Adapted Value of DFE TAP3 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_DFE_TAP3_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_DFE_TAP3_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP3_ADPT_VAL - Stored DFE TAP3 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_DFE_TAP3_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_DFE_TAP3_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_DFE_TAP3_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4 - RX Adapted Value of DFE TAP4 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_DFE_TAP4_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_DFE_TAP4_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP4_ADPT_VAL - Stored RX Adapted DFE TAP4 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_DFE_TAP4_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_DFE_TAP4_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_DFE_TAP4_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5 - RX Adapted Value of DFE TAP5 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_DFE_TAP5_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_DFE_TAP5_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP5_ADPT_VAL - Stored RX Adapted DFE TAP5 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_DFE_TAP5_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_DFE_TAP5_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_DFE_TAP5_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_IQ - RX Adapted Value of IQ for Bank 0 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_RX_ADPT_IQ_MASK (0x7FU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_RX_ADPT_IQ_SHIFT (0U)
/*! RX_ADPT_IQ - RX Adapted Value of IQ for Bank 0 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_RX_ADPT_IQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_RX_ADPT_IQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_RX_ADPT_IQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_REF_ERR - RX Adapted Value of Reference Level for Error Slicer for Bank 0 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_EVEN_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_EVEN_SHIFT (0U)
/*! RX_ADPT_REF_ERR_EVEN - RX Adapted Value of Reference Level for Error Even Slicer for Bank 0 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_EVEN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_EVEN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_EVEN_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_ODD_MASK (0xFF00U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_ODD_SHIFT (8U)
/*! RX_ADPT_REF_ERR_ODD - RX Adapted Value of Reference Level for Error Odd Slicer for Bank 0 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_ODD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_ODD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_RX_ADPT_REF_ERR_ODD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADAPT_DONE - RX Adaptation Done Status */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_SHIFT (0U)
/*! RX_ADAPT_DONE - Indicates whether RX adaptation has completed or not
 *  0b0..Not completed
 *  0b1..Completed
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADPT_IQ_VLD_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADPT_IQ_VLD_SHIFT (1U)
/*! RX_ADPT_IQ_VLD - Indicates if the RX adapted value of IQ for bank 0 is valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADPT_IQ_VLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADPT_IQ_VLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADPT_IQ_VLD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_ATT_B1 - RX Adapted Value of ATT for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_B1_ATT_ADPT_VAL_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_B1_ATT_ADPT_VAL_SHIFT (0U)
/*! ATT_ADPT_VAL - Stored RX Adapted ATT Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_B1_ATT_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_B1_ATT_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ATT_B1_ATT_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_VGA_B1 - RX Adapted Value of VGA for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_B1_VGA_ADPT_VAL_MASK (0x1FFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_B1_VGA_ADPT_VAL_SHIFT (0U)
/*! VGA_ADPT_VAL - Stored RX Adapted VGA Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_B1_VGA_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_B1_VGA_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_VGA_B1_VGA_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1 - RX Adapted Value of CTLE for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_BOOST_ADPT_VAL_MASK (0x3FFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_BOOST_ADPT_VAL_SHIFT (0U)
/*! CTLE_BOOST_ADPT_VAL - Stored RX Adapted CTLE boost Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_BOOST_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_BOOST_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_BOOST_ADPT_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_POLE_ADPT_VAL_MASK (0xC00U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_POLE_ADPT_VAL_SHIFT (10U)
/*! CTLE_POLE_ADPT_VAL - Stored RX Adapted CTLE Pole Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_POLE_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_POLE_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_CTLE_B1_CTLE_POLE_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_B1 - RX Adapted Value of DFE TAP1 for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_B1_DFE_TAP1_ADPT_VAL_MASK (0x1FFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_B1_DFE_TAP1_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP1_ADPT_VAL - Stored RX Adapted DFE TAP1 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_B1_DFE_TAP1_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_B1_DFE_TAP1_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_B1_DFE_TAP1_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_B1 - RX Adapted Value of DFE TAP2 for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_B1_DFE_TAP2_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_B1_DFE_TAP2_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP2_ADPT_VAL - Stored RX Adapted DFE TAP2 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_B1_DFE_TAP2_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_B1_DFE_TAP2_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_B1_DFE_TAP2_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_B1 - RX Adapted Value of DFE TAP3 for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_B1_DFE_TAP3_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_B1_DFE_TAP3_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP3_ADPT_VAL - Stored RX Adapted DFE TAP3 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_B1_DFE_TAP3_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_B1_DFE_TAP3_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP3_B1_DFE_TAP3_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_B1 - RX Adapted Value of DFE TAP4 for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_B1_DFE_TAP4_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_B1_DFE_TAP4_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP4_ADPT_VAL - Stored RX Adapted DFE TAP4 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_B1_DFE_TAP4_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_B1_DFE_TAP4_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP4_B1_DFE_TAP4_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_B1 - RX Adapted Value of DFE TAP5 for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_B1_DFE_TAP5_ADPT_VAL_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_B1_DFE_TAP5_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP5_ADPT_VAL - Stored RX Adapted DFE TAP5 Value */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_B1_DFE_TAP5_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_B1_DFE_TAP5_ADPT_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP5_B1_DFE_TAP5_ADPT_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_IQ_B1 - RX Adapted Value of IQ for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_B1_RX_ADPT_IQ_B1_MASK (0x7FU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_B1_RX_ADPT_IQ_B1_SHIFT (0U)
/*! RX_ADPT_IQ_B1 - RX Adapted Value of IQ for Bank 1 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_B1_RX_ADPT_IQ_B1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_B1_RX_ADPT_IQ_B1_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_B1_RX_ADPT_IQ_B1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1 - RX Adapted Value of Reference Level for Error Slicer for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_EVEN_B1_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_EVEN_B1_SHIFT (0U)
/*! RX_ADPT_REF_ERR_EVEN_B1 - RX Adapted Value of Reference Level for Error Even Slicer for Bank 1 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_EVEN_B1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_EVEN_B1_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_EVEN_B1_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_ODD_B1_MASK (0xFF00U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_ODD_B1_SHIFT (8U)
/*! RX_ADPT_REF_ERR_ODD_B1 - RX Adapted Value of Reference Level for Error Odd Slicer for Bank 1 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_ODD_B1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_ODD_B1_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_REF_ERR_B1_RX_ADPT_REF_ERR_ODD_B1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1 - RX Adaptation Done Status for Bank 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADAPT_DONE_B1_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADAPT_DONE_B1_SHIFT (0U)
/*! RX_ADAPT_DONE_B1 - Indicates whether bank 1 RX adaptation has completed or not
 *  0b0..Not completed
 *  0b1..Completed
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADAPT_DONE_B1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADAPT_DONE_B1_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADAPT_DONE_B1_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADPT_IQ_VLD_B1_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADPT_IQ_VLD_B1_SHIFT (1U)
/*! RX_ADPT_IQ_VLD_B1 - Indicates if the RX adapted value of IQ for bank 1 is valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADPT_IQ_VLD_B1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADPT_IQ_VLD_B1_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADAPT_DONE_B1_RX_ADPT_IQ_VLD_B1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_FW_STATES_0 - Stores Various States for Firmware - 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_FW_STATES_0_SPARE_STATE_0_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_FW_STATES_0_SPARE_STATE_0_SHIFT (0U)
/*! SPARE_STATE_0 - Spare Fields to be Used by Firmware */
#define ENET_PHY_RAWLANE0_DIG_AON_FW_STATES_0_SPARE_STATE_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_FW_STATES_0_SPARE_STATE_0_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_FW_STATES_0_SPARE_STATE_0_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TXRX_OVRD_IN - Override Values for Incoming AON TX/RX Controls from PCS */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_SHIFT (0U)
/*! RX_DISABLE_OVRD_VAL - Override Value for rx_disable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_SHIFT (1U)
/*! RX_DISABLE_OVRD_EN - Override Enable for rx_disable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_SHIFT (2U)
/*! TX_DISABLE_OVRD_VAL - Override Value for tx_disable
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_SHIFT (3U)
/*! TX_DISABLE_OVRD_EN - Override Enable for tx_disable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL - Equalization Direction Polarity Setting in PCS RAW */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXMAIN_DIR_INV_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXMAIN_DIR_INV_SHIFT (0U)
/*! TXMAIN_DIR_INV - Invert the txmain_dir polarity
 *  0b0..No invert
 *  0b1..Invert
 */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXMAIN_DIR_INV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXMAIN_DIR_INV_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXMAIN_DIR_INV_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPRE_DIR_INV_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPRE_DIR_INV_SHIFT (1U)
/*! TXPRE_DIR_INV - Invert the txpre_dir polarity
 *  0b0..No invert
 *  0b1..Invert
 */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPRE_DIR_INV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPRE_DIR_INV_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPRE_DIR_INV_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPOST_DIR_INV_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPOST_DIR_INV_SHIFT (2U)
/*! TXPOST_DIR_INV - Invert the txpost_dir polarity
 *  0b0..No invert
 *  0b1..Invert
 */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPOST_DIR_INV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPOST_DIR_INV_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_EQ_DIR_POLARITY_CTL_TXPOST_DIR_INV_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TX_PRE_DIV - TX Pre Threshold Div */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_OFF_MULT_MASK (0x1FU)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_OFF_MULT_SHIFT (0U)
/*! TX_PRE_OFF_MULT - TX Pre Offset Mult */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_OFF_MULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_OFF_MULT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_OFF_MULT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_THRESH_DIV_MASK (0x1E0U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_THRESH_DIV_SHIFT (5U)
/*! TX_PRE_THRESH_DIV - TX Pre Threshold Div */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_THRESH_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_THRESH_DIV_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_PRE_DIV_TX_PRE_THRESH_DIV_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD - TX Main ATT High and Low Threshold */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_LOW_THRESHOLD_MASK (0x7U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_LOW_THRESHOLD_SHIFT (0U)
/*! TX_MAIN_ATT_LOW_THRESHOLD - TX Main ATT Low Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_LOW_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_LOW_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_LOW_THRESHOLD_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_HIGH_THRESHOLD_MASK (0x38U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_HIGH_THRESHOLD_SHIFT (3U)
/*! TX_MAIN_ATT_HIGH_THRESHOLD - TX Main ATT High Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_HIGH_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_HIGH_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_ATT_THRESHOLD_TX_MAIN_ATT_HIGH_THRESHOLD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD - TX Main VGA High and Low Threshold */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_LOW_THRESHOLD_MASK (0xFU)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_LOW_THRESHOLD_SHIFT (0U)
/*! TX_MAIN_VGA_LOW_THRESHOLD - TX Main VGA Low Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_LOW_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_LOW_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_LOW_THRESHOLD_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_HIGH_THRESHOLD_MASK (0xF0U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_HIGH_THRESHOLD_SHIFT (4U)
/*! TX_MAIN_VGA_HIGH_THRESHOLD - TX Main VGA High Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_HIGH_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_HIGH_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_MAIN_VGA_THRESHOLD_TX_MAIN_VGA_HIGH_THRESHOLD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD - TX Post Boost High and Low Threshold */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_LOW_THRESHOLD_MASK (0x1FU)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_LOW_THRESHOLD_SHIFT (0U)
/*! TX_POST_BOOST_LOW_THRESHOLD - TX Post Boost Low Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_LOW_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_LOW_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_LOW_THRESHOLD_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_HIGH_THRESHOLD_MASK (0x3E0U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_HIGH_THRESHOLD_SHIFT (5U)
/*! TX_POST_BOOST_HIGH_THRESHOLD - TX Post Boost High Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_HIGH_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_HIGH_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_POST_BOOST_THRESHOLD_TX_POST_BOOST_HIGH_THRESHOLD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD - TX Post Tap1 High and Low Threshold */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_LOW_THRESHOLD_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_LOW_THRESHOLD_SHIFT (0U)
/*! TX_POST_TAP1_LOW_THRESHOLD - TX Post Tap1 Low Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_LOW_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_LOW_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_LOW_THRESHOLD_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_HIGH_THRESHOLD_MASK (0xFF00U)
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_HIGH_THRESHOLD_SHIFT (8U)
/*! TX_POST_TAP1_HIGH_THRESHOLD - TX Post Tap1 High Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_HIGH_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_HIGH_THRESHOLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_TX_POST_TAP1_THRESHOLD_TX_POST_TAP1_HIGH_THRESHOLD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_CAL_REF_EE_VDAC_OFST - Value for Reference Level Error Even Slicer */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EE_VDAC_OFST_RX_CAL_REF_EE_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EE_VDAC_OFST_RX_CAL_REF_EE_VDAC_OFST_SHIFT (0U)
/*! RX_CAL_REF_EE_VDAC_OFST - Value for Reference Level Error Even Slicer */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EE_VDAC_OFST_RX_CAL_REF_EE_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EE_VDAC_OFST_RX_CAL_REF_EE_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EE_VDAC_OFST_RX_CAL_REF_EE_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_CAL_REF_EO_VDAC_OFST - Value for Reference Level Error Odd Slicer */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EO_VDAC_OFST_RX_CAL_REF_EO_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EO_VDAC_OFST_RX_CAL_REF_EO_VDAC_OFST_SHIFT (0U)
/*! RX_CAL_REF_EO_VDAC_OFST - Value for Reference Level Error Odd Slicer */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EO_VDAC_OFST_RX_CAL_REF_EO_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EO_VDAC_OFST_RX_CAL_REF_EO_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CAL_REF_EO_VDAC_OFST_RX_CAL_REF_EO_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST - Value for DFE Error Even Low and High Slicer in Mission Mode */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEH_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEH_VDAC_OFST_SHIFT (0U)
/*! DFE_EEH_VDAC_OFST - Value for DFE Error Even High Slicer in Mission Mode */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEH_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEH_VDAC_OFST_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEL_VDAC_OFST_MASK (0xFF00U)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEL_VDAC_OFST_SHIFT (8U)
/*! DFE_EEL_VDAC_OFST - Value for DFE Error Even Low Slicer in Mission Mode */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEL_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEL_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_EE_VDAC_OFST_DFE_EEL_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST - Value for DFE Error Odd Low and High Slicer in Mission Mode */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOH_VDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOH_VDAC_OFST_SHIFT (0U)
/*! DFE_EOH_VDAC_OFST - Value for DFE Error Odd High Slicer in Mission Mode */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOH_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOH_VDAC_OFST_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOL_VDAC_OFST_MASK (0xFF00U)
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOL_VDAC_OFST_SHIFT (8U)
/*! DFE_EOL_VDAC_OFST - Value for DFE Error Odd Low Slicer in Mission Mode */
#define ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOL_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOL_VDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_DFE_EO_VDAC_OFST_DFE_EOL_VDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_ERR_SLC_MODE - RX Adaptation Error Slicer Mode for Reference-Level Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ERR_SLC_MODE_RX_ADPT_ERR_SLC_MODE_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ERR_SLC_MODE_RX_ADPT_ERR_SLC_MODE_SHIFT (0U)
/*! RX_ADPT_ERR_SLC_MODE - RX Adaptation Error Slicer Mode for Reference-Level Calibration */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ERR_SLC_MODE_RX_ADPT_ERR_SLC_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ERR_SLC_MODE_RX_ADPT_ERR_SLC_MODE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_ERR_SLC_MODE_RX_ADPT_ERR_SLC_MODE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_SETUP_REF_CTLE_IDAC_OFST - Offset Value for AFE CTLE IDAC During Reference-Level Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_CTLE_IDAC_OFST_SETUP_REF_CTLE_IDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_CTLE_IDAC_OFST_SETUP_REF_CTLE_IDAC_OFST_SHIFT (0U)
/*! SETUP_REF_CTLE_IDAC_OFST - Offset Value for AFE CTLE iDAC During Reference-Level Calibration */
#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_CTLE_IDAC_OFST_SETUP_REF_CTLE_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_CTLE_IDAC_OFST_SETUP_REF_CTLE_IDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_CTLE_IDAC_OFST_SETUP_REF_CTLE_IDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_SETUP_REF_VGA1_IDAC_OFST - Offset Value for AFE VGA1 IDAC During Reference-Level Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_VGA1_IDAC_OFST_SETUP_REF_VGA1_IDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_VGA1_IDAC_OFST_SETUP_REF_VGA1_IDAC_OFST_SHIFT (0U)
/*! SETUP_REF_VGA1_IDAC_OFST - Offset Value for AFE CTLE VGA1 During Reference-Level Calibration */
#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_VGA1_IDAC_OFST_SETUP_REF_VGA1_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_VGA1_IDAC_OFST_SETUP_REF_VGA1_IDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SETUP_REF_VGA1_IDAC_OFST_SETUP_REF_VGA1_IDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_SETUP_SLC_VGA1_IDAC_OFST - Offset Value for AFE VGA1 for Slicer Setup Calibration */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_SLC_VGA1_IDAC_OFST_SETUP_SLC_VGA1_IDAC_OFST_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_SLC_VGA1_IDAC_OFST_SETUP_SLC_VGA1_IDAC_OFST_SHIFT (0U)
/*! SETUP_SLC_VGA1_IDAC_OFST - Offset Value for AFE VGA1 for Slicer Setup Calibration */
#define ENET_PHY_RAWLANE0_DIG_AON_SETUP_SLC_VGA1_IDAC_OFST_SETUP_SLC_VGA1_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SETUP_SLC_VGA1_IDAC_OFST_SETUP_SLC_VGA1_IDAC_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SETUP_SLC_VGA1_IDAC_OFST_SETUP_SLC_VGA1_IDAC_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL - RX CDR Detector Control */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_DETECTOR_EN_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_DETECTOR_EN_SHIFT (0U)
/*! RX_CDR_DETECTOR_EN - Enable the CDR Detector in Detector Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_DETECTOR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_DETECTOR_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_DETECTOR_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_PPM_MONITOR_MODE_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_PPM_MONITOR_MODE_SHIFT (1U)
/*! RX_CDR_PPM_MONITOR_MODE - Enable the CDR Detector in Monitor Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_PPM_MONITOR_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_PPM_MONITOR_MODE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_RX_CDR_PPM_MONITOR_MODE_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_DIS_IN_ADAPT_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_DIS_IN_ADAPT_SHIFT (2U)
/*! DIS_IN_ADAPT - Disable the CDR Detector State Machine for During Adaptation
 *  0b0..Not disable
 *  0b1..Disable
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_DIS_IN_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_DIS_IN_ADAPT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_DETECTOR_CTL_DIS_IN_ADAPT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_CDR_RECOVERY_TIME - RX CDR Recovery Time in Reference Clock for the Intended PPM */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_RECOVERY_TIME_RX_CDR_RECOVERY_TIME_MASK (0xFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_RECOVERY_TIME_RX_CDR_RECOVERY_TIME_SHIFT (0U)
/*! RX_CDR_RECOVERY_TIME - RX CDR Recovery Time in Reference Clock for Intended PPM */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_RECOVERY_TIME_RX_CDR_RECOVERY_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_RECOVERY_TIME_RX_CDR_RECOVERY_TIME_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_CDR_RECOVERY_TIME_RX_CDR_RECOVERY_TIME_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_MEM_BREAKPOINT_2 - FSM Breakpoint 2 on SRAM Address for Debugging */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_ADDR_MASK (0x3FFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_ADDR_SHIFT (0U)
/*! BREAKPOINT_ADDR - Memory Address for Breakpoint 2 */
#define ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_ADDR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_ADDR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_ADDR_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_EN_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_EN_SHIFT (14U)
/*! BREAKPOINT_EN - Enables the Breakpoint 2
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_MEM_BREAKPOINT_2_BREAKPOINT_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_0 - Adaptation Control 0 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_1 - Adaptation Control 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ - Reset Routine Request */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_SHIFT (0U)
/*! RESET_RTN_REQ - Reset Routine Request
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ - RX Reset Interrupt */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_SHIFT (0U)
/*! RX_RESET - RX Reset Interrupt */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ - RX Request Interrupt */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_SHIFT (0U)
/*! RX_REQ - RX Request Interrupt */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ - RX Rate Change Interrupt Request */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_SHIFT (0U)
/*! RX_RATE_IRQ - RX Rate Change Interrupt Request */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ - RX P-State Change Interrupt Request */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_SHIFT (0U)
/*! RX_PSTATE_IRQ - RX P-State Change Interrupt Request */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ - RX Adaptation Request Interrupt */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_SHIFT (0U)
/*! RX_ADAPT_REQ_IRQ - RX Adaptation Request Interrupt */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ - RX Adaptation Disable Interrupt */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_SHIFT (0U)
/*! RX_ADAPT_DIS_IRQ - RX Adaptation Disable Interrupt */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR - RX-Reset Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_SHIFT (0U)
/*! RX_RESET_IRQ_CLR - RX Reset Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR - RX Request Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_SHIFT (0U)
/*! RX_REQ_IRQ_CLR - RX Request Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR - RX Rate Change Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_SHIFT (0U)
/*! RX_RATE_IRQ_CLR - RX Rate Change Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR - RX P-State Change Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_SHIFT (0U)
/*! RX_PSTATE_IRQ_CLR - RX P-State Change Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR - RX Adaptation Request Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_SHIFT (0U)
/*! RX_ADAPT_REQ_IRQ_CLR - RX Adaptation Request Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR - RX Adaptation Disable Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_SHIFT (0U)
/*! RX_ADAPT_DIS_IRQ_CLR - RX Adaptation Disable Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_IRQ_MASK - Interrupt Mask */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_SHIFT (0U)
/*! RX_REQ_IRQ_MSK - Mask for RX Request Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_MASK)

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_SHIFT (1U)
/*! RX_RATE_IRQ_MSK - Mask for RX Rate Change Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_MASK)

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_SHIFT (2U)
/*! RX_PSTATE_IRQ_MSK - Mask for RX P-State Change Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_MASK)

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_SHIFT (3U)
/*! RX_ADAPT_REQ_IRQ_MSK - Mask for RX Adaptation Request Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_MASK)

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_MASK (0x10U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_SHIFT (4U)
/*! RX_ADAPT_DIS_IRQ_MSK - Mask for RX Adaptation Disable Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_MASK)

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_MASK (0x20U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_SHIFT (5U)
/*! RX_RESET_IRQ_MSK - Mask for RX Reset Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_MASK)

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_MPLL_RECAL_IRQ_MSK_MASK (0x40U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_MPLL_RECAL_IRQ_MSK_SHIFT (6U)
/*! MPLL_RECAL_IRQ_MSK - Mask for MPLL Re-Calibration Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_MPLL_RECAL_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_MPLL_RECAL_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_MPLL_RECAL_IRQ_MSK_MASK)

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_IQ_IRQ_MSK_MASK (0x80U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_IQ_IRQ_MSK_SHIFT (7U)
/*! RX_IQ_IRQ_MSK - Mask for RX IQ Interrupt
 *  0b0..Cannot interrupt
 */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_IQ_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_IQ_IRQ_MSK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_IQ_IRQ_MSK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ - MPLLA/B Re-Calibration Interrupt */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_MPLL_RECAL_IRQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_MPLL_RECAL_IRQ_SHIFT (0U)
/*! MPLL_RECAL_IRQ - MPLLA/B Re-Calibration Interrupt */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_MPLL_RECAL_IRQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_MPLL_RECAL_IRQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_MPLL_RECAL_IRQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_CLR - MPLL Re-Calibration Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_CLR_MPLL_RECAL_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_CLR_MPLL_RECAL_IRQ_CLR_SHIFT (0U)
/*! MPLL_RECAL_IRQ_CLR - MPLL Re-Calibration Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_CLR_MPLL_RECAL_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_CLR_MPLL_RECAL_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_MPLL_RECAL_IRQ_CLR_MPLL_RECAL_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ - RX IQ Interrupt */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_RX_IQ_IRQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_RX_IQ_IRQ_SHIFT (0U)
/*! RX_IQ_IRQ - RX IQ Interrupt */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_RX_IQ_IRQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_RX_IQ_IRQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_RX_IQ_IRQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_CLR - RX IQ Interrupt Clear */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_CLR_RX_IQ_IRQ_CLR_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_CLR_RX_IQ_IRQ_CLR_SHIFT (0U)
/*! RX_IQ_IRQ_CLR - RX IQ Interrupt Clear (Self-Clearing) */
#define ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_CLR_RX_IQ_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_CLR_RX_IQ_IRQ_CLR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_IRQ_CTL_RX_IQ_IRQ_CLR_RX_IQ_IRQ_CLR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN - Override Values for Incoming LANE Controls */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_SHIFT (0U)
/*! LANE_MPLLA_EN_IN - Override Value for lane_mplla_en_in
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_SHIFT (1U)
/*! LANE_MPLLB_EN_IN - Override Value for lane_mpllb_en_in
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_SHIFT (2U)
/*! LANE_OVRD_EN - Override Enable for Signals in this Register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT - Override Values for Outgoing LANE Controls */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_SHIFT (0U)
/*! LANE_MPLLA_EN_OUT - Override Value for lane_mplla_en_out
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_SHIFT (1U)
/*! LANE_MPLLB_EN_OUT - Override Value for lane_mpllb_en_out
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_SHIFT (2U)
/*! LANE_OVRD_EN - Override Enable for Signals in this Register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN - Override Values for Incoming SUP Controls from PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_SHIFT (0U)
/*! MPLLA_STATE - Override Value for mplla_state
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_SHIFT (1U)
/*! MPLLB_STATE - Override Value for mpllb_state
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_SHIFT (2U)
/*! SUP_STATE_OVRD_EN - Override Enable for Signals in this Register
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_SUP_PMA_IN - Current Values for Coming SUP Status Controls from PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_SHIFT (0U)
/*! MPLLA_STATE - Value from PMA for mplla_state */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_SHIFT (1U)
/*! MPLLB_STATE - Value from PMA for mpllb_state */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RTUNE_ACK_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RTUNE_ACK_SHIFT (2U)
/*! RTUNE_ACK - Value from PMA for rtune_ack */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RTUNE_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RTUNE_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RTUNE_ACK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT - Override Values for Outgoing TX Controls to PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_SHIFT (0U)
/*! TX_REQ_OVRD_VAL - Override Value for tx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_SHIFT (1U)
/*! TX_REQ_OVRD_EN - Override Enable for tx_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_SHIFT (2U)
/*! TX_RESET_OVRD_VAL - Override Value for tx_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_SHIFT (3U)
/*! TX_RESET_OVRD_EN - Override Enable for tx_reset
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_TX_PMA_IN - Current Values for Coming TX Status Controls from PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_SHIFT (0U)
/*! ACK - Value from PMA for tx_ack */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT - Override Values for Outgoing RX Controls to PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_SHIFT (0U)
/*! RX_REQ_OVRD_VAL - Override Value for rx_req
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_SHIFT (1U)
/*! RX_REQ_OVRD_EN - Override Enable for rx_req
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_SHIFT (2U)
/*! RX_RESET_OVRD_VAL - Override Value for rx_reset
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_SHIFT (3U)
/*! RX_RESET_OVRD_EN - Override Enable for rx_reset
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_RX_PMA_IN - Current Values for coming RX Status Controls from PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_SHIFT (0U)
/*! ACK - Value from PMA for rx_ack */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL - Lane Rtune Controls */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_SHIFT (0U)
/*! LANE_RTUNE_REQ - Lane Value for rtune_req */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_RX_OVRD_IN - Override Values for Incoming RX Controls from PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_VAL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_VAL_SHIFT (0U)
/*! RX_ACK_OVRD_VAL - Override Value for rx_ack
 *  0b0..No override
 *  0b1..Override
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_VAL_MASK)

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_EN_SHIFT (1U)
/*! RX_ACK_OVRD_EN - Override Enable for rx_ack
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_RX_OVRD_IN_RX_ACK_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_SRAM_REC_EN - SRAM Record Enable */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SRAM_REC_EN_REC_EN_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SRAM_REC_EN_REC_EN_SHIFT (0U)
/*! REC_EN - Enable the SRAM Recording
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ENET_PHY_RAWLANE0_DIG_PMA_XF_SRAM_REC_EN_REC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_PMA_XF_SRAM_REC_EN_REC_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_PMA_XF_SRAM_REC_EN_REC_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_TX_CTL_TX_FSM_CTL - TX FSM Control */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_SHIFT (0U)
/*! TX_P2_ALLOW_RXDET - If asserted, then rxdet request is allowed in P2 */
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_MASK)

#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_SHIFT (1U)
/*! TX_P1_ALLOW_RXDET - If asserted, then rxdet request is allowed in P1 */
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_MASK)

#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_SHIFT (2U)
/*! TX_P0S_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0S */
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_MASK)

#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_SHIFT (3U)
/*! TX_P0_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0 */
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_SHIFT)) & ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_TX_CTL_TX_CLK_CTL - Select Clock to Act as TX Input Clock */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_SHIFT (0U)
/*! TX_CLK_EN - Enable the tx_clk to pma TX lane TX_CLK_EN must be de-asserted when switching TX_CLK_SEL
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_MASK (0x1EU)
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_SHIFT (1U)
/*! TX_CLK_SEL - Select Clock Source for tx_pma_clk
 *  0b0000..tx_pcs_clk (input clock from PCS)
 *  0b0001..mplla_word_clk
 *  0b0010..mplla_dword_clk
 *  0b0011..mplla_qword_clk
 *  0b0100..mplla_oword_clk
 *  0b0101..mplla_div16p5_clk
 *  0b0110..mplla_div33_clk
 *  0b0111..mplla_div66_clk
 *  0b1000..mplla_div_clk
 *  0b1001..mpllb_word_clk
 *  0b1010..mpllb_dword_clk
 *  0b1011..mpllb_qword_clk
 *  0b1100..mpllb_oword_clk
 *  0b1101..mpllb_div_clk
 *  0b1110..rx_clk (from pma)
 */
#define ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_FSM_CTL - RX FSM Control */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_SHIFT (0U)
/*! EN_RX_CTL_FSM - Enable the RX Control FSM in the Raw PCS
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_SHIFT (1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL - RX LOS Mask Control */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_MASK (0x1FFU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_SHIFT (0U)
/*! RX_LOS_MASK_CNT - Number of Cycles (ref_range_clk) */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL - RX Data Enable Override Control */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_MASK (0x1FU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_SHIFT (0U)
/*! RX_DATA_EN_OVRD_CNT - Number of ref_range cycles to override rx_data_en to 1 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_MASK (0xFFE0U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_SHIFT (5U)
/*! INT_REF_TRCK_CNT - Number of ref_range cycles to wait for integral reference tracking to settle */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS - RX Continuous Offset Cancellation Status */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_SHIFT (0U)
/*! ENABLE - Enable Status for RX Continuous Offset Cancellation
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS - RX Continuous Adaptation Status */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_SHIFT (0U)
/*! ENABLE - Enable Status for RX Continuous Adaptation
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE - RX Adaptation Mode */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_ADAPT_MODE_MASK (0x3U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_ADAPT_MODE_SHIFT (0U)
/*! ADAPT_MODE - RX Adaptation Mode */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_ADAPT_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_ADAPT_MODE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_ADAPT_MODE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADAPT_SEL - Select Between Two Banks Adaptation Settings for RX Adaptation */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_SEL_RX_ADAPT_SEL_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_SEL_RX_ADAPT_SEL_SHIFT (0U)
/*! RX_ADAPT_SEL - Select Between Two Banks Adaptation Settings for RX Adaptation */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_SEL_RX_ADAPT_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_SEL_RX_ADAPT_SEL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_SEL_RX_ADAPT_SEL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT - RX CDR PPM Drift on RX Clock */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_MASK (0x3FFFU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_SHIFT (0U)
/*! RX_PPM_DRIFT - Indicates the amount of drift on RX clock when RX_PPM_DRIFT_VLD is asserted */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_VLD_MASK (0x4000U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_VLD_SHIFT (14U)
/*! RX_PPM_DRIFT_VLD - Indicates if the PPM Drift is valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_VLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_VLD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PPM_DRIFT_RX_PPM_DRIFT_VLD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_CDR_DET_STATUS - RX CDR Detector Status */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_CDR_DET_STATUS_CDR_DET_STATE_MASK (0x7U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_CDR_DET_STATUS_CDR_DET_STATE_SHIFT (0U)
/*! CDR_DET_STATE - Indicate the current state for the state machine in CDR Detector */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_CDR_DET_STATUS_CDR_DET_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_CDR_DET_STATUS_CDR_DET_STATE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_CDR_DET_STATUS_CDR_DET_STATE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL - Values for Outgoing RX Controls to PMA */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CLK_SHIFT_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CLK_SHIFT_SHIFT (0U)
/*! RX_CLK_SHIFT - Value for rx_clk_shift to PMA */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CLK_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CLK_SHIFT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CLK_SHIFT_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_ALIGH_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_ALIGH_EN_SHIFT (1U)
/*! RX_ALIGH_EN - Value for rx_align_en to PMA */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_ALIGH_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_ALIGH_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_ALIGH_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CDR_TRACK_EN_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CDR_TRACK_EN_SHIFT (2U)
/*! RX_CDR_TRACK_EN - Value for rx_cdr_track_en to PMA */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CDR_TRACK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CDR_TRACK_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_CDR_TRACK_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_DFE_TAP1_ADAPT_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_DFE_TAP1_ADAPT_OVRD_EN_SHIFT (3U)
/*! RX_DFE_TAP1_ADAPT_OVRD_EN - Enable override the DFE Tap1 to zero during RX Adaptation
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_DFE_TAP1_ADAPT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_DFE_TAP1_ADAPT_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_MISC_CTL_RX_DFE_TAP1_ADAPT_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_PMA_EQ_IQ - RX PMA Equalization IQ Phase Value */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_EQ_IQ_RX_PMA_EQ_IQ_MASK (0x3FU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_EQ_IQ_RX_PMA_EQ_IQ_SHIFT (0U)
/*! RX_PMA_EQ_IQ - RX PMA Equalization IQ Phase Value */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_EQ_IQ_RX_PMA_EQ_IQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_EQ_IQ_RX_PMA_EQ_IQ_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PMA_EQ_IQ_RX_PMA_EQ_IQ_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN - Enable RX Adapt Mode Override */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_0_OVRD_EN_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_0_OVRD_EN_SHIFT (0U)
/*! RX_ADAPT_MODE_0_OVRD_EN - Enables RX adapt mode override when adapt_mode is 2'b00
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_0_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_0_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_0_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_1_OVRD_EN_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_1_OVRD_EN_SHIFT (1U)
/*! RX_ADAPT_MODE_1_OVRD_EN - Enables RX adapt mode override when adapt_mode is 2'b01
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_1_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_1_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_1_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_2_OVRD_EN_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_2_OVRD_EN_SHIFT (2U)
/*! RX_ADAPT_MODE_2_OVRD_EN - Enables RX adapt mode override when adapt_mode is 2'b10
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_2_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_2_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_2_OVRD_EN_MASK)

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_3_OVRD_EN_MASK (0x8U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_3_OVRD_EN_SHIFT (3U)
/*! RX_ADAPT_MODE_3_OVRD_EN - Enables RX adapt mode override when adapt_mode is 2'b11
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_3_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_3_OVRD_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_OVRD_EN_RX_ADAPT_MODE_3_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_EN - Enable Using Four Different RX Adaptation Modes */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_EN_RX_ADAPT_MODE_EN_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_EN_RX_ADAPT_MODE_EN_SHIFT (0U)
/*! RX_ADAPT_MODE_EN - Enable Using Four Different RX Adaptation Modes
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_EN_RX_ADAPT_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_EN_RX_ADAPT_MODE_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MODE_EN_RX_ADAPT_MODE_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADAPT_MM_FOM - RX Adaptation Mission-Mode Figure of Merit */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MM_FOM_RX_ADAPT_MM_FOM_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MM_FOM_RX_ADAPT_MM_FOM_SHIFT (0U)
/*! RX_ADAPT_MM_FOM - RX Adaptation Mission-Mode Figure of Merit */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MM_FOM_RX_ADAPT_MM_FOM(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MM_FOM_RX_ADAPT_MM_FOM_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_MM_FOM_RX_ADAPT_MM_FOM_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADAPT_STARTUP_FOM - RX Adaptation Startup Figure of Merit (Base Mode or Extended Mode) */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_STARTUP_FOM_RX_ADAPT_STARTUP_FOM_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_STARTUP_FOM_RX_ADAPT_STARTUP_FOM_SHIFT (0U)
/*! RX_ADAPT_STARTUP_FOM - RX Adaptation Startup Figure of Merit (Base Mode or Extended Mode) */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_STARTUP_FOM_RX_ADAPT_STARTUP_FOM(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_STARTUP_FOM_RX_ADAPT_STARTUP_FOM_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADAPT_STARTUP_FOM_RX_ADAPT_STARTUP_FOM_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_EVEN - RX Adapted Value of Reference Level for Error Even Slicer */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_EVEN_RX_ADPT_REF_ERR_EVEN_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_EVEN_RX_ADPT_REF_ERR_EVEN_SHIFT (0U)
/*! RX_ADPT_REF_ERR_EVEN - RX Adapted Value of Reference Level for Error Even Slicer for Bank 0 */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_EVEN_RX_ADPT_REF_ERR_EVEN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_EVEN_RX_ADPT_REF_ERR_EVEN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_EVEN_RX_ADPT_REF_ERR_EVEN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_ODD - RX Adapted Value of Reference Level for Error Odd Slicer */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_ODD_RX_ADPT_REF_ERR_ODD_MASK (0xFFU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_ODD_RX_ADPT_REF_ERR_ODD_SHIFT (0U)
/*! RX_ADPT_REF_ERR_ODD - RX Adapted Value of Reference Level for Error Odd Slicer */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_ODD_RX_ADPT_REF_ERR_ODD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_ODD_RX_ADPT_REF_ERR_ODD_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_ADPT_REF_ERR_ODD_RX_ADPT_REF_ERR_ODD_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_PHSADJ_MAP - RX Phase Adjust Mapped Value */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PHSADJ_MAP_RX_PHSADJ_MAP_MASK (0x3FU)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PHSADJ_MAP_RX_PHSADJ_MAP_SHIFT (0U)
/*! RX_PHSADJ_MAP - Mapped Value for RX Phase Adjust */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PHSADJ_MAP_RX_PHSADJ_MAP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PHSADJ_MAP_RX_PHSADJ_MAP_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_PHSADJ_MAP_RX_PHSADJ_MAP_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_DAC_IN_USE - State of the DAC Interface */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DAC_IN_USE_DAC_IN_USE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DAC_IN_USE_DAC_IN_USE_SHIFT (0U)
/*! DAC_IN_USE - State of the DAC Interface */
#define ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DAC_IN_USE_DAC_IN_USE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DAC_IN_USE_DAC_IN_USE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_RX_CTL_RX_DAC_IN_USE_DAC_IN_USE_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_2 - Adaptation Control 2 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_3 - Adaptation Control 3 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_4 - Adaptation Control 4 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_5 - Adaptation Control 5 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_6 - Adaptation Control 6 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_7 - Adaptation Control 7 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_8 - Adaptation Control 8 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_8_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_8_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_8_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_8_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_8_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_9 - Adaptation Control 9 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_9_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_9_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_9_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_9_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_9_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_10 - Adaptation Control 10 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_10_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_10_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_10_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_10_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_10_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_11 - Adaptation Control 11 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_11_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_11_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_11_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_11_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_11_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_12 - Adaptation Control 12 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_12_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_12_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_12_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_12_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_12_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_13 - Adaptation Control 13 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_13_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_13_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_13_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_13_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_13_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_14 - Adaptation Control 14 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_14_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_14_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_14_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_14_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_14_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_15 - Adaptation Control 15 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_15_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_15_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_15_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_15_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_15_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_16 - Adaptation Control 16 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_16_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_16_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_16_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_16_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_16_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_17 - Adaptation Control 17 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_17_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_17_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_17_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_17_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_17_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_18 - Adaptation Control 18 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_18_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_18_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_18_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_18_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_18_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_19 - Adaptation Control 19 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_19_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_19_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_19_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_19_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_19_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_20 - Adaptation Control 20 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_20_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_20_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_20_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_20_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_20_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_21 - Adaptation Control 21 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_21_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_21_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_21_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_21_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_21_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_22 - Adaptation Control 22 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_22_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_22_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_22_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_22_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_22_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_23 - Adaptation Control 23 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_23_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_23_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_23_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_23_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_23_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_24 - Adaptation Control 24 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_24_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_24_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_24_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_24_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_24_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_25 - Adaptation Control 25 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_25_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_25_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_25_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_25_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_25_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_26 - Adaptation Control 26 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_26_VAL_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_26_VAL_SHIFT (0U)
/*! VAL - Value of Adaptation Control */
#define ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_26_VAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_26_VAL_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_ADPT_CTL_26_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_SRAM_REC_CTRL - SRAM Record Control */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_INIT_DONE_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_INIT_DONE_SHIFT (0U)
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_INIT_DONE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_INIT_DONE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_INIT_DONE_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_MODE_MASK (0x2U)
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_MODE_SHIFT (1U)
/*! REC_MODE - SRAM Recording Mode
 *  0b0..Only the first 16 records will be stored in SRAM
 *  0b1..The most recent 16 records (if there are) will be stored in SRAM
 */
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_MODE_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_MODE_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_EN_MASK (0x4U)
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_EN_SHIFT (2U)
/*! REC_EN - Enable the SRAM Recording
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_EN_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_CTRL_REC_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_SRAM_REC_ADDR - Current SRAM Recording Address */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ADDR_SRAM_REC_ADDR_MASK (0xFFFFU)
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ADDR_SRAM_REC_ADDR_SHIFT (0U)
/*! SRAM_REC_ADDR - Current SRAM Recording Address */
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ADDR_SRAM_REC_ADDR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ADDR_SRAM_REC_ADDR_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ADDR_SRAM_REC_ADDR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_SRAM_REC_ITER - Current Iteration Count for SRAM Recording */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ITER_SRAM_REC_ITER_MASK (0x3FFU)
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ITER_SRAM_REC_ITER_SHIFT (0U)
/*! SRAM_REC_ITER - Current Iteration Count for SRAM Recording */
#define ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ITER_SRAM_REC_ITER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ITER_SRAM_REC_ITER_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_SRAM_REC_ITER_SRAM_REC_ITER_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_IQ_CTL - RX IQ Adaptation Control 1 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_IQ_ADPT_OFST_MASK (0xFU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_IQ_ADPT_OFST_SHIFT (0U)
/*! IQ_ADPT_OFST - Initial IQ Offset for IQ Adaptation */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_IQ_ADPT_OFST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_IQ_ADPT_OFST_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_IQ_ADPT_OFST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_IQ_CTL_1 - RX IQ Adaptation Control 2 */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_CENTER_MASK (0x1U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_CENTER_SHIFT (0U)
/*! DPLL_THRESH_CENTER - Center of the DPLL Threshold Value
 *  0b0..Center is relative to the current value of DPLL frequency
 *  0b1..Absolute center (for example 'h8192)
 */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_CENTER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_CENTER_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_CENTER_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_MASK (0xFFFEU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_SHIFT (1U)
/*! DPLL_THRESH - DPLL Frequency Threshold */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_IQ_CTL_1_DPLL_THRESH_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT - RX IQ Adaptation Offset Limit */
/*! @{ */

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_LEFT_LIMIT_MASK (0x1FU)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_LEFT_LIMIT_SHIFT (0U)
/*! LEFT_LIMIT - Max IQ Offset from Calibrated IQ for Left-Side IQ Sweep */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_LEFT_LIMIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_LEFT_LIMIT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_LEFT_LIMIT_MASK)

#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_RIGHT_LIMIT_MASK (0x3E0U)
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_RIGHT_LIMIT_SHIFT (5U)
/*! RIGHT_LIMIT - Max IQ Offset from Calibrated IQ for Right-Side IQ Sweep */
#define ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_RIGHT_LIMIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_RIGHT_LIMIT_SHIFT)) & ENET_PHY_RAWLANE0_DIG_AON_RX_ADPT_IQ_LIMIT_RIGHT_LIMIT_MASK)
/*! @} */

/*! @name RAWMEM_D_ROM_CMN_B_R - Common Memory #0, Bank #0, Reg #0..Common Memory #63, Bank #7, Reg #31 */
/*! @{ */

#define ENET_PHY_RAWMEM_D_ROM_CMN_B_R_DAT_MASK   (0xFFFFU)
#define ENET_PHY_RAWMEM_D_ROM_CMN_B_R_DAT_SHIFT  (0U)
/*! DAT - Memory Data */
#define ENET_PHY_RAWMEM_D_ROM_CMN_B_R_DAT(x)     (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWMEM_D_ROM_CMN_B_R_DAT_SHIFT)) & ENET_PHY_RAWMEM_D_ROM_CMN_B_R_DAT_MASK)
/*! @} */

/* The count of ENET_PHY_RAWMEM_D_ROM_CMN_B_R */
#define ENET_PHY_RAWMEM_D_ROM_CMN_B_R_COUNT      (64U)

/* The count of ENET_PHY_RAWMEM_D_ROM_CMN_B_R */
#define ENET_PHY_RAWMEM_D_ROM_CMN_B_R_COUNT2     (8U)

/* The count of ENET_PHY_RAWMEM_D_ROM_CMN_B_R */
#define ENET_PHY_RAWMEM_D_ROM_CMN_B_R_COUNT3     (32U)

/*! @name RAWMEM_D_RAM_CMN_B_R - Common Memory #0, Bank #0, Reg #0..Common Memory #63, Bank #7, Reg #31 */
/*! @{ */

#define ENET_PHY_RAWMEM_D_RAM_CMN_B_R_DAT_MASK   (0xFFFFU)
#define ENET_PHY_RAWMEM_D_RAM_CMN_B_R_DAT_SHIFT  (0U)
/*! DAT - Memory Data */
#define ENET_PHY_RAWMEM_D_RAM_CMN_B_R_DAT(x)     (((uint16_t)(((uint16_t)(x)) << ENET_PHY_RAWMEM_D_RAM_CMN_B_R_DAT_SHIFT)) & ENET_PHY_RAWMEM_D_RAM_CMN_B_R_DAT_MASK)
/*! @} */

/* The count of ENET_PHY_RAWMEM_D_RAM_CMN_B_R */
#define ENET_PHY_RAWMEM_D_RAM_CMN_B_R_COUNT      (64U)

/* The count of ENET_PHY_RAWMEM_D_RAM_CMN_B_R */
#define ENET_PHY_RAWMEM_D_RAM_CMN_B_R_COUNT2     (8U)

/* The count of ENET_PHY_RAWMEM_D_RAM_CMN_B_R */
#define ENET_PHY_RAWMEM_D_RAM_CMN_B_R_COUNT3     (32U)


/*!
 * @}
 */ /* end of group ENET_PHY_Register_Masks */

#define ENET_PHY_BASE                            (0x0u)
#define ENET_PHY                                 ((ENET_PHY_Type *)ENET_PHY_BASE)
#define ENET_PHY_BASE_ADDRS                      { ENET_PHY_BASE }
#define ENET_PHY_BASE_PTRS                       { ENET_PHY }


/*!
 * @}
 */ /* end of group ENET_PHY_Peripheral_Access_Layer */


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


#endif  /* ENET_PHY_H_ */

