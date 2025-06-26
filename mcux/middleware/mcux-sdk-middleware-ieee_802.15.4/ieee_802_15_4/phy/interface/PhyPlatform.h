/*! *********************************************************************************
* Copyright 2023-2025 NXP
* All rights reserved.
*
* \file Platform specific definitions. This file contains the default values for
* platform files.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef __PHY_PLATFORM_H__
#define __PHY_PLATFORM_H__

/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */

#ifdef PHY_PLATFORM_SPECIFIC_CONFIG_FILE
// Name of the file for defining platform specific macros and functions.
// For example "PhyPlatform_RW610n.h", "PhyPlatform_IW512.h", "PhyPlatform_K32W1.h"
#include PHY_PLATFORM_SPECIFIC_CONFIG_FILE
#endif

/*! *********************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
********************************************************************************** */

#ifndef gPhyIrqPriority_c
#define gPhyIrqPriority_c           (0x80)
#endif

// TODO Should be moved to platform file
#if defined(KW45B41Z83_NBU_SERIES) ||                                          \
    defined(MCXW727C_cm33_core1_SERIES) ||                                     \
    defined(KW43B43ZC7_NBU_SERIES)
    #define gPhyIrqNo_d (ZIGBEE_INT_IRQn)
#elif defined(K32W1480_SERIES) ||                                              \
      defined(MCXW716C_SERIES) || defined(MCXW716A_SERIES) ||                  \
      defined(MCXW727C_cm33_core0_SERIES)
    #define gPhyIrqNo_d (RF_802_15_4_IRQn)
#elif defined(KW43B43ZC7_SERIES)
    #define gPhyIrqNo_d (RF_ZIGBEE_IRQn)
#endif

/*
 * MIN_ENERGY_LEVEL, MAX_ENERGY_LEVEL are parameters used to scale
 * energy level between values 0x00-0xFF
 */
#ifndef MIN_ENERGY_LEVEL
#define MIN_ENERGY_LEVEL            (-80)
#endif
#ifndef MAX_ENERGY_LEVEL
#define MAX_ENERGY_LEVEL            (-3)
#endif

#ifndef CONVERT_ENERGY_LEVEL
/* Convert energy level from dbm into a 0x00-0xFF value */
#define CONVERT_ENERGY_LEVEL(energy)  ((17 * energy) / 5 + 272)
#endif

/* if the external Front End module Power Amplifier is enable, the maximum power level is +20dBm */
#define gPhyMaxTxPowerLevel_With_FEM_PA_enable_d         (0x28)

/* The interval at which the Phy will poll for a new buffer */
#ifndef gPhyRxRetryInterval_c
#define gPhyRxRetryInterval_c         (60) /* [symbols] */
#endif

#ifndef gPhyUseExternalCoexistence_d
#define gPhyUseExternalCoexistence_d  (0)
#endif

/* LQI calculation RSSI compensation value - this value + RX min RSSI should equal 0*/
#ifndef gPhyLqiOffsetCompValue_d
#define gPhyLqiOffsetCompValue_d      (102)
#endif

/* Number of table entries for generic IE data that can be added to an Enhanced ACK */
#ifndef gPhyIeDataTableSize
#define gPhyIeDataTableSize           (2)
#endif

/* Size of HW SAM Table size, RADIO specific */
#define gPhyHwSAMTableSize_d (128)

#ifndef gPhySAPSize_d
#define gPhySAPSize_d (gPhyHwSAMTableSize_d)
#endif

#ifndef gPhySAASize_d
#define gPhySAASize_d (gPhyHwSAMTableSize_d)
#endif

#ifdef gPhyUseHwSAMTable
/* Make sure that SAP Table size is properly configured when HW Table is used */
#if (gPhySAPSize_d > gPhyHwSAMTableSize_d)
#error "Phy SAP size bigger than HW capabilities"
#endif
/* Make sure that SAA Table size is properly configured when HW Table is used */
#if (gPhySAASize_d > gPhyHwSAMTableSize_d)
#error "Phy SAA size bigger than HW capabilities"
#endif

/* TODO: Implement HW SAA */
#error "SAA HW Table is not implemented for to use HW SAM table"
#endif

/* For MAC split we can't know for now whether Dual PAN is enabled.
   Use half of the queue size to avoid any problems */
#define gPhyIndirectQueueSize_d (gPhySAPSize_d / 2)

#ifndef FFU_CNS_TX_PWR_TABLE_CALIBRATION
#define FFU_CNS_TX_PWR_TABLE_CALIBRATION 0
#endif

#if (FFU_CNS_TX_PWR_TABLE_CALIBRATION == 1)
/* The power table mapping for the 15.4 is below. The power should be specified as
   absolute value in 1/2 dBm step. The 15.4 LL will send out this power to BCA for
   arbitration with WiFi before sending to BRF. FW doesn't directly write the BRF registers
   unless it is a test mode.

   TX Power Range in dBm : -20dBm to +15 dBm
   Step increase         : 1/2 dB
   ESMAC Tx Power Index  : -40(0xD8) to +30(0x1E) [High precision change in 0.5 dB for validation]
*/
#ifndef gPhyDefaultTxPowerLevel_d
#define gPhyDefaultTxPowerLevel_d     (0)
#endif

#ifndef gPhyMaxTxPowerLevel_d
#define gPhyMaxTxPowerLevel_d         (0x1E)
#endif

#ifndef gPhyMinTxPowerLevel_d
#define gPhyMinTxPowerLevel_d         (0xD8)
#endif

#ifndef gPhyMinTxPowerLevelInt8_d
#define gPhyMinTxPowerLevelInt8_d     (-64)
#endif

#ifndef gPhyMaxTxPowerLevelInt8_d
#define gPhyMaxTxPowerLevelInt8_d     (63)
#endif

/* Tx Power level limit for each individual channel */
#ifndef gChannelTxPowerLimit_c
#define gChannelTxPowerLimit_c { gPhyMaxTxPowerLevel_d,   /* 11 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 12 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 13 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 14 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 15 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 16 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 17 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 18 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 19 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 20 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 21 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 22 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 23 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 24 */ \
                                 gPhyMaxTxPowerLevel_d,   /* 25 */ \
                                 gPhyMaxTxPowerLevel_d }  /* 26 */
#endif

#else /* FFU_CNS_TX_PWR_TABLE_CALIBRATION */

/*
 * Following defines are used when Tx Power is in dBm (signed value)
 *
 * the output TX Power is depending on PA_PWR settings, Analog settings and temperature
 *
 * there are defined 3 sets of defines all of them for 25 C:
 *  - low rf output power = analog setting LDO_ANT_TRIM is at minimum voltage
 *  - medium rf output power = analog setting LDO_ANT_TRIM is at medium voltage
 *  - high rf output power = analog setting LDO_ANT_TRIM is at highiest voltage
 */
#ifndef gPhyMinTxPower_low_rf_dBm_Int8_d
#define gPhyMinTxPower_low_rf_dBm_Int8_d                (-32) // dBm
#endif

#ifndef gPhyMaxTxPower_low_rf_dBm_Int8_d
#define gPhyMaxTxPower_low_rf_dBm_Int8_d                 (+1) // dBm
#endif

#ifndef gPhyMinTxPower_medium_rf_dBm_Int8_d
#define gPhyMinTxPower_medium_rf_dBm_Int8_d             (-24) // dBm
#endif

#ifndef gPhyMaxTxPower_medium_rf_dBm_Int8_d
#define gPhyMaxTxPower_medium_rf_dBm_Int8_d              (+8) // dBm
#endif

#ifndef gPhyMinTxPower_high_rf_dBm_Int8_d
#define gPhyMinTxPower_high_rf_dBm_Int8_d               (-22) // dBm
#endif

#ifndef gPhyMaxTxPower_high_rf_dBm_Int8_d
#define gPhyMaxTxPower_high_rf_dBm_Int8_d               (+10) // dBm
#endif

/*
 * Following defines are used when Tx Power is in number of PA slices (unsigned value)
 * PA slices are used for PA_PWR register settings according with datasheet
 *
 * Note: Odd & Even values
 *  In Ref manual/datasheet are listed mostly even values: 0,1,2,4,6,8,...,62.
 *  However despite all values odd and even are valid and should be legal,
 *  will prefer and try to use only even values except 1.
 */
#ifndef gPhyMinTxPowerLevel_d
#define gPhyMinTxPowerLevel_d         (0x00)   // PA slice 0, minimum no output power
#endif

#ifndef gPhyMaxTxPowerLevel_d
#define gPhyMaxTxPowerLevel_d         (0x3F)   // PA slice 63, maximum output power
#endif

/*
 * Default values
 */
#ifndef gPhyDefaultTxPower_dBm_Int8_d
#define gPhyDefaultTxPower_dBm_Int8_d       (0) // set default tx power to 0 dBm (signed value)
#endif

#ifndef gPhyDefaultTxPowerLevel_d
#define gPhyDefaultTxPowerLevel_d           (gPhyDefaultTxPower_dBm_Int8_d)
#endif

#ifndef gPhyMaxTxPowerLimit_dBm_Int8_d
#ifdef gAppMaxTxPowerDbm_c
#define gPhyMaxTxPowerLimit_dBm_Int8_d       (gAppMaxTxPowerDbm_c)  // dBm (signed value)
#else
#define gPhyMaxTxPowerLimit_dBm_Int8_d       (10)  // dBm (signed value)
#endif /* gAppMaxTxPowerDbm_c */
#endif

/* Tx Power level limit for each individual channel */
#ifndef gChannelTxPowerLimit_c
#define gChannelTxPowerLimit_c { gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 11 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 12 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 13 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 14 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 15 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 16 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 17 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 18 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 19 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 20 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 21 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 22 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 23 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 24 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d,   /* 25 */ \
                                 gPhyMaxTxPowerLimit_dBm_Int8_d }  /* 26 */
#endif

#endif /* FFU_CNS_TX_PWR_TABLE_CALIBRATION */

#ifndef mPhyOverhead_d
#define mPhyOverhead_d          (10)       /* [sym] */
#endif

#ifndef LQI_REG_MAX_VAL
#define LQI_REG_MAX_VAL         ((uint8_t)127)    /* Maximum value of LQI from the register*/
#endif
#ifndef LQI_MAX_VAL
#define LQI_MAX_VAL             ((uint8_t)0xFF)   /* Maximum value of LQI*/
#endif
#ifndef CLIP_LQI_VAL
#define CLIP_LQI_VAL            ((int16_t)-20)    /* WSW-21635: Clip 15.4 LQI value to 0xFF for above -20dBm */
#endif

#ifndef gPhyLeniency_c
/* LENIENCY rule 40- allow all possible combinations from iee 802.15.4 2015 table 7.2 */
/* LENIENCY rule 41- allow reception of enh ack frame where PAN ID compression doesn't match
    the sent frame -> Thread issue */
#define gPhyLeniency_c          (0x300)
#endif

/* Front End loss value used for TX power calculation */
#ifndef FE_LOSS_VALUE
#define FE_LOSS_VALUE 0
#endif

/* External Front End module Power Amplifier gain enable */
#ifndef FE_POWER_AMPLIFIER_ENABLE
#define FE_POWER_AMPLIFIER_ENABLE 0
#endif

/* External maximum internal power level Front End Module acceptable (dBm) */
#ifndef FEM_INPUT_MAX_GAIN
#define FEM_INPUT_MAX_GAIN 0
#endif

/* External Front End module Power Amplifier gain (dB) */
#ifndef FE_POWER_AMPLIFIER_GAIN
#define FE_POWER_AMPLIFIER_GAIN 0
#endif

/* External Front End module LNA (Low Noise Attenuator) enable */
#ifndef FEM_LNA_ENABLE
#define FEM_LNA_ENABLE 0
#endif

/* External Front End module LNA (Low Noise Attenuator) gain (dB) */
#ifndef FEM_LNA_GAIN
#define FEM_LNA_GAIN 0
#endif


/*
 * When receiving a frame, the radio will send an acknowledge automatically (if not
 * an enhanced ACK). This flag enables the deactivation of this feature.
 */
#ifndef AUTO_ACK_DISABLE_SUPPORT
#define AUTO_ACK_DISABLE_SUPPORT 0
#endif

/* Enables to configure and get current TX power limit in gPhyChannelTxPowerLimits */
#ifndef TX_POWER_LIMIT_FEATURE
#define TX_POWER_LIMIT_FEATURE 0
#endif


/* Enables to use variable mode of CCA instead of a fixed one (gPhyCCAMode1_c) */
#ifndef CCA_MODE_SELECT_SUPPORT
#define CCA_MODE_SELECT_SUPPORT 0
#endif

/* Calculate RSSI based on LQI value instead of returning last RSSI value */
#ifndef LAST_RSSI_USING_LQI
#define LAST_RSSI_USING_LQI 1
#endif

/* Support of ARB GRANT DEASSERTION by the radio. */
#ifndef ARB_GRANT_DEASSERTION_SUPPORT
#define ARB_GRANT_DEASSERTION_SUPPORT 0
#endif

/*
 * Enable radio coex metrics measurements count for Arbitration Grant wait,
 * delayed, immediate...
 */
#ifndef RADIO_COEX_METRICS_ENABLE
#define RADIO_COEX_METRICS_ENABLE 0
#endif

/* Use RSSI and SNR weight for LQI calculation in Phy_LqiConvert */
#ifndef WEIGHT_IN_LQI_CALCULATION
#define WEIGHT_IN_LQI_CALCULATION       0
#endif

/* Support of the use of XCVR misc driver api in ASP.c */
#ifndef  XCVR_MISC_SUPPORT
#if defined (RW610N_BT_CM3_SERIES)
#define  XCVR_MISC_SUPPORT              0
#elif !(RW610_FPGA)
#define  XCVR_MISC_SUPPORT              0
#else
#define  XCVR_MISC_SUPPORT              1
#endif
#endif

/* Add the Front-End loss (in dB) to the RSSI value */
#ifndef RSSI_WITH_FELOSS
#define RSSI_WITH_FELOSS  (0)
#endif


/*
 * PhyHwInit flags to enable default initialisation
*/
/* Select Data Rate to legacy 802.15.4 */
#ifndef HWINIT_CONFIGURE_LEGACY_DATA_RATE
#define HWINIT_CONFIGURE_LEGACY_DATA_RATE       (0)
#endif

/* Set CCA Mode2 Threshold Values */
#ifndef HWINIT_CONFIGURE_CCA2_THRESHOLD
#define HWINIT_CONFIGURE_CCA2_THRESHOLD         (0)
#endif

/* Use the CCA1 information computed by the RX Digital */
#ifndef HWINIT_USE_CCA1_FROM_RX_DIGITAL
#define HWINIT_USE_CCA1_FROM_RX_DIGITAL         (0)
#endif

/* Reset to 0b0 - Use standalone (new) CCA Mode 2 Engine, decoupled from demodulator */
#ifndef HWINIT_USE_CCA2_DECOUPLED_FROM_DEMOD
#define HWINIT_USE_CCA2_DECOUPLED_FROM_DEMOD    (0)
#endif

/* The CCA RSSI must come from RX DIG otherwise the CCA will not work correctly and will report
       last received packet RSSI */
#ifndef HWINIT_CCA1_FROM_RX_DIG
#define HWINIT_CCA1_FROM_RX_DIG()               (XCVR_ZBDEMOD->CCA_LQI_SRC |= XCVR_ZBDEMOD_CCA_LQI_SRC_CCA1_FROM_RX_DIG(0x1U))
#endif

/* Configure RFMC->RF2P4GHZ_COEXT instead of ZLL->COEX_PRIORITY registers */
#ifndef HWINIT_USE_RFMC_COEX
#define HWINIT_USE_RFMC_COEX                    (1)
#endif

/* Set COEX_REQ_DELAY_EN for arb_request is delayed until preamble is detected during R sequence.
   Can be set to 0 or 1 to configure register */
#ifndef HWINIT_COEX_REQ_DELAY_EN_VALUE
#define HWINIT_COEX_REQ_DELAY_EN_VALUE          (0)
#endif

/* Configure DTEST signals for debug */
#ifndef HWINIT_DEBUG_DTEST
#define HWINIT_DEBUG_DTEST                      (0)
#endif

/* Update finetuned RSSI RSSI_ADJ_NB Offset value */
#ifndef HWINIT_SET_RSSI_ADJUSTEMENT
#define HWINIT_SET_RSSI_ADJUSTEMENT 0
#endif

/* RSSI adjustment offset for all channels */
#ifndef HWINIT_RSSI_ADJ_NB
#define HWINIT_RSSI_ADJ_NB 0
#endif

/* Use ZLL_PHY_CTRL_TSM_MSK_MASK for ZLL->PHY_CTRL configuration */
#ifndef HWINIT_MASK_TSM_ZLL
#define HWINIT_MASK_TSM_ZLL                     (0)
#endif

/* Configure ZLL->ACKDELAY register */
#ifndef HWINIT_ACKDELAY_VALUE
#define HWINIT_ACKDELAY_VALUE                   (-4)
#endif

/* Configure ZLL->ACKDELAY register */
#ifndef HWINIT_TXDELAY_VALUE
#define HWINIT_TXDELAY_VALUE                    (0)
#endif

/* Configure ZLL->ACKDELAY register */
#ifndef HWINIT_RXDELAY_VALUE
#define HWINIT_RXDELAY_VALUE                    (0)
#endif

/* Configure corectly LQI reporting by WH -> RSSI calculation starts when preamble is detected */
#ifndef HWINIT_RSSI_STARTS_AT_PREAMBLE
#define HWINIT_RSSI_STARTS_AT_PREAMBLE          (1)
#endif

/* This feature is used for Front End Switching Control.
   These settings used only for Single Antenna & NA for Dual Ant cases */
#ifndef HWINIT_FRONT_END_SWITCHING_SUPPORT
#define HWINIT_FRONT_END_SWITCHING_SUPPORT      (0)
#endif

/* Support the use of BCA_BYPASS register */
#ifndef HWINIT_BCA_BYPASS_SUPPORT
#define HWINIT_BCA_BYPASS_SUPPORT               (1)
#endif


/*
 * Phy IRQ handling functions needed for easier integration in common code.
*/
#ifndef PHY_PhyIrqCreate
#define PHY_PhyIrqCreate()
#endif

#ifndef PHY_PhyIrqClearPending
#define PHY_PhyIrqClearPending()    NVIC_ClearPendingIRQ(gPhyIrqNo_d)
#endif

#ifndef PHY_PhyIrqSetPending
#define PHY_PhyIrqSetPending()      NVIC_SetPendingIRQ(gPhyIrqNo_d)
#endif

#ifndef PHY_PhyIrqEnable
#define PHY_PhyIrqEnable()          NVIC_EnableIRQ(gPhyIrqNo_d);
#endif

#ifndef PHY_PhyIrqDisable
#define PHY_PhyIrqDisable()         NVIC_DisableIRQ(gPhyIrqNo_d);
#endif

#ifndef PHY_PhyIrqSetPriority
#define PHY_PhyIrqSetPriority()     NVIC_SetPriority(gPhyIrqNo_d, gPhyIrqPriority_c >> (8 - __NVIC_PRIO_BITS));
#endif

/* Set a PHY CTRL register field, defined for easier integration in common code.*/
#ifndef SET_PHYCTRL_FIELD
#define SET_PHYCTRL_FIELD(mask)     ZLL->PHY_CTRL |= (mask ## _MASK)
#endif

/* clear a PHY CTRL register field, defined for easier integration in common code.*/
#ifndef CLR_PHYCTRL_FIELD
#define CLR_PHYCTRL_FIELD(mask)     ZLL->PHY_CTRL &= ~(mask ## _MASK)
#endif

/*
 * IsCpuInterruptContext : returns 1 if CPU is in interrupt context and 0 if not.
 * Not define for common case, returns always 0
 */
#ifndef IsCpuInterruptContext
#define IsCpuInterruptContext()     0
#endif

void PhyPlatformHwInit();

/*
 * functions used during FPGA stage
 */
#ifndef FFU_FPGA_INTF
#define FFU_FPGA_INTF           (0)
#endif

#if FFU_FPGA_INTF == 1
void FPGA_SendChannelSwitchCmd(uint32_t channel);
void FPGA_SendSetPwrLevelCmd(uint8_t pwrStep);
#else
#define FPGA_SendChannelSwitchCmd(channel)
#define FPGA_SendSetPwrLevelCmd(pwrStep)
#endif

/*
* Default RSSI offset definition
*/
#ifndef gChannelRssiOffset_c
#define gChannelRssiOffset_c { 0,   /* 11 */ \
                               0,   /* 12 */ \
                               0,   /* 13 */ \
                               0,   /* 14 */ \
                               0,   /* 15 */ \
                               0,   /* 16 */ \
                               0,   /* 17 */ \
                               0,   /* 18 */ \
                               0,   /* 19 */ \
                               0,   /* 20 */ \
                               0,   /* 21 */ \
                               0,   /* 22 */ \
                               0,   /* 23 */ \
                               0,   /* 24 */ \
                               0,   /* 25 */ \
                               0 }  /* 26 */
#endif

#endif /* __PHY_PLATFORM_H__ */
