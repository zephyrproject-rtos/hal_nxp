/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XCVR_PLL_DIG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file XCVR_PLL_DIG.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_PLL_DIG
 *
 * CMSIS Peripheral Access Layer for XCVR_PLL_DIG
 */

#if !defined(XCVR_PLL_DIG_H_)
#define XCVR_PLL_DIG_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- XCVR_PLL_DIG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PLL_DIG_Peripheral_Access_Layer XCVR_PLL_DIG Peripheral Access Layer
 * @{
 */

/** XCVR_PLL_DIG - Register Layout Typedef */
typedef struct {
  __IO uint32_t HPM_BUMP;                          /**< PLL HPM Analog Bump Control, offset: 0x0 */
  __IO uint32_t MOD_CTRL;                          /**< PLL Modulation Control, offset: 0x4 */
  __IO uint32_t CHAN_MAP;                          /**< PLL Channel Mapping, offset: 0x8 */
  __IO uint32_t LOCK_DETECT;                       /**< PLL Lock Detect Control, offset: 0xC */
  __IO uint32_t HPM_CTRL;                          /**< PLL High Port Modulator Control, offset: 0x10 */
  __IO uint32_t HPMCAL_CTRL;                       /**< PLL High Port Calibration Control, offset: 0x14 */
  __IO uint32_t HPM_CAL1;                          /**< PLL High Port Calibration Result 1, offset: 0x18 */
  __IO uint32_t HPM_CAL2;                          /**< PLL High Port Calibration Result 2, offset: 0x1C */
  __IO uint32_t HPM_SDM_RES;                       /**< PLL High Port Sigma Delta Results, offset: 0x20 */
  __IO uint32_t LPM_CTRL;                          /**< PLL Low Port Modulator Control, offset: 0x24 */
  __IO uint32_t LPM_SDM_CTRL1;                     /**< PLL Low Port Sigma Delta Control 1, offset: 0x28 */
  __IO uint32_t LPM_SDM_CTRL2;                     /**< PLL Low Port Sigma Delta Control 2, offset: 0x2C */
  __IO uint32_t LPM_SDM_CTRL3;                     /**< PLL Low Port Sigma Delta Control 3, offset: 0x30 */
  __I  uint32_t LPM_SDM_RES1;                      /**< PLL Low Port Sigma Delta Result 1, offset: 0x34 */
  __I  uint32_t LPM_SDM_RES2;                      /**< PLL Low Port Sigma Delta Result 2, offset: 0x38 */
  __IO uint32_t DELAY_MATCH;                       /**< PLL Delay Matching, offset: 0x3C */
  __IO uint32_t CTUNE_CTRL;                        /**< PLL Coarse Tune Control, offset: 0x40 */
  __I  uint32_t CTUNE_CNT6;                        /**< PLL Coarse Tune Count 6, offset: 0x44 */
  __I  uint32_t CTUNE_CNT5_4;                      /**< PLL Coarse Tune Counts 5 and 4, offset: 0x48 */
  __I  uint32_t CTUNE_CNT3_2;                      /**< PLL Coarse Tune Counts 3 and 2, offset: 0x4C */
  __I  uint32_t CTUNE_CNT1_0;                      /**< PLL Coarse Tune Counts 1 and 0, offset: 0x50 */
  __I  uint32_t CTUNE_RES;                         /**< PLL Coarse Tune Results, offset: 0x54 */
} XCVR_PLL_DIG_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_PLL_DIG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PLL_DIG_Register_Masks XCVR_PLL_DIG Register Masks
 * @{
 */

/*! @name HPM_BUMP - PLL HPM Analog Bump Control */
/*! @{ */

#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_MASK    (0x7U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_SHIFT   (0U)
/*! HPM_VCM_TX - rfctrl_tx_dac_bump_vcm[2:0] during Transmission
 *  0b000..432 mV
 *  0b001..328 mV
 *  0b010..456 mV
 *  0b011..473 mV
 *  0b100..488 mV
 *  0b101..408 mV
 *  0b110..392 mV
 *  0b111..376 mV
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_TX_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_MASK   (0x70U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_SHIFT  (4U)
/*! HPM_VCM_CAL - rfctrl_tx_dac_bump_vcm[2:0] during Calibration
 *  0b000..432 mV
 *  0b001..328 mV
 *  0b010..456 mV
 *  0b011..473 mV
 *  0b100..488 mV
 *  0b101..408 mV
 *  0b110..392 mV
 *  0b111..376 mV
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_VCM_CAL_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_MASK (0x300U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_SHIFT (8U)
/*! HPM_FDB_RES_TX - rfctrl_tx_dac_bump_fdb_res[1:0] during Transmission
 *  0b00..29 kohms
 *  0b01..58 kohms(gain of 2)
 *  0b10..13 kohms
 *  0b11..23.7 kohms
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_TX_MASK)

#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_MASK (0x3000U)
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_SHIFT (12U)
/*! HPM_FDB_RES_CAL - rfctrl_tx_dac_bump_fdb_res[1:0] during Calibration
 *  0b00..29 kohms
 *  0b01..58 kohms(gain of 2)
 *  0b10..13 kohms
 *  0b11..23.7 kohms
 */
#define XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_SHIFT)) & XCVR_PLL_DIG_HPM_BUMP_HPM_FDB_RES_CAL_MASK)
/*! @} */

/*! @name MOD_CTRL - PLL Modulation Control */
/*! @{ */

#define XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_MASK (0x1FFFU)
#define XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_SHIFT (0U)
/*! MODULATION_WORD_MANUAL - Manual Modulation Word */
#define XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_MODULATION_WORD_MANUAL_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_MASK   (0x8000U)
#define XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_SHIFT  (15U)
/*! MOD_DISABLE - Disable Modulation Word */
#define XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_MOD_DISABLE_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_MASK (0xFF0000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_SHIFT (16U)
/*! HPM_MOD_MANUAL - Manual HPM Modulation */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_MANUAL_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_MASK (0x8000000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_SHIFT (27U)
/*! HPM_MOD_DISABLE - Disable HPM Modulation */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_MOD_DISABLE_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_MASK (0x30000000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_SHIFT (28U)
/*! HPM_SDM_OUT_MANUAL - Manual HPM SDM out */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_MANUAL_MASK)

#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_MASK (0x80000000U)
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_SHIFT (31U)
/*! HPM_SDM_OUT_DISABLE - Disable HPM SDM out */
#define XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_SHIFT)) & XCVR_PLL_DIG_MOD_CTRL_HPM_SDM_OUT_DISABLE_MASK)
/*! @} */

/*! @name CHAN_MAP - PLL Channel Mapping */
/*! @{ */

#define XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_MASK   (0x7FU)
#define XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_SHIFT  (0U)
/*! CHANNEL_NUM - Protocol specific Channel Number for PLL Frequency Mapping */
#define XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_CHANNEL_NUM_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_BOC_MASK           (0x100U)
#define XCVR_PLL_DIG_CHAN_MAP_BOC_SHIFT          (8U)
/*! BOC - BLE Channel Number Override
 *  0b0..BLE channel number comes from the BLE Link Layer
 *  0b1..BLE channel number comes from the CHANNEL_NUM register (BLE protocols 0 and 2)
 */
#define XCVR_PLL_DIG_CHAN_MAP_BOC(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_BOC_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_BOC_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_BMR_MASK           (0x200U)
#define XCVR_PLL_DIG_CHAN_MAP_BMR_SHIFT          (9U)
/*! BMR - BLE MBAN Channel Remap
 *  0b0..BLE channel 39 is mapped to BLE channel 39, 2.480 GHz
 *  0b1..BLE channel 39 is mapped to MBAN channel 39, 2.399 GHz
 */
#define XCVR_PLL_DIG_CHAN_MAP_BMR(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_BMR_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_BMR_MASK)

#define XCVR_PLL_DIG_CHAN_MAP_ZOC_MASK           (0x400U)
#define XCVR_PLL_DIG_CHAN_MAP_ZOC_SHIFT          (10U)
/*! ZOC - 802.15.4 Channel Number Override
 *  0b0..802.15.4 channel number comes from the 802.15.4 Link Layer.
 *  0b1..802.15.4 channel number comes from the CHANNEL_NUM register (802.15.4 protocols 4 and 5)
 */
#define XCVR_PLL_DIG_CHAN_MAP_ZOC(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CHAN_MAP_ZOC_SHIFT)) & XCVR_PLL_DIG_CHAN_MAP_ZOC_MASK)
/*! @} */

/*! @name LOCK_DETECT - PLL Lock Detect Control */
/*! @{ */

#define XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_MASK    (0x1U)
#define XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_SHIFT   (0U)
/*! CT_FAIL - Real time status of Coarse Tune Fail signal */
#define XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CT_FAIL_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_CTFF_MASK       (0x2U)
#define XCVR_PLL_DIG_LOCK_DETECT_CTFF_SHIFT      (1U)
/*! CTFF - CTUNE Failure Flag, held until cleared */
#define XCVR_PLL_DIG_LOCK_DETECT_CTFF(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CTFF_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CTFF_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_CS_FAIL_MASK    (0x4U)
#define XCVR_PLL_DIG_LOCK_DETECT_CS_FAIL_SHIFT   (2U)
/*! CS_FAIL - Real time status of Cycle Slip circuit */
#define XCVR_PLL_DIG_LOCK_DETECT_CS_FAIL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CS_FAIL_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CS_FAIL_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_CSFF_MASK       (0x8U)
#define XCVR_PLL_DIG_LOCK_DETECT_CSFF_SHIFT      (3U)
/*! CSFF - Cycle Slip Failure Flag, held until cleared */
#define XCVR_PLL_DIG_LOCK_DETECT_CSFF(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CSFF_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CSFF_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_MASK    (0x10U)
#define XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_SHIFT   (4U)
/*! FT_FAIL - Real time status of Frequency Target Failure */
#define XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FT_FAIL_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTFF_MASK       (0x20U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTFF_SHIFT      (5U)
/*! FTFF - Frequency Target Failure Flag */
#define XCVR_PLL_DIG_LOCK_DETECT_FTFF(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTFF_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTFF_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_TAFF_MASK       (0x80U)
#define XCVR_PLL_DIG_LOCK_DETECT_TAFF_SHIFT      (7U)
/*! TAFF - TSM Abort Failure Flag */
#define XCVR_PLL_DIG_LOCK_DETECT_TAFF(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_TAFF_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_TAFF_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_MASK (0xF00U)
#define XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_SHIFT (8U)
/*! CTUNE_LDF_LEV - CTUNE Lock Detect Fail Level */
#define XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_CTUNE_LDF_LEV_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_MASK (0x3F000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_SHIFT (12U)
/*! FTF_RX_THRSH - RX Frequency Target Fail Threshold */
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTF_RX_THRSH_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTW_RX_MASK     (0x80000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTW_RX_SHIFT    (19U)
/*! FTW_RX - RX Frequency Target Window time select
 *  0b0..4 us
 *  0b1..8 us
 */
#define XCVR_PLL_DIG_LOCK_DETECT_FTW_RX(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTW_RX_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTW_RX_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_MASK (0x3F00000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_SHIFT (20U)
/*! FTF_TX_THRSH - TX Frequency Target Fail Threshold */
#define XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTF_TX_THRSH_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FTW_TX_MASK     (0x8000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FTW_TX_SHIFT    (27U)
/*! FTW_TX - TX Frequency Target Window time select
 *  0b0..4 us
 *  0b1..8 us
 */
#define XCVR_PLL_DIG_LOCK_DETECT_FTW_TX(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FTW_TX_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FTW_TX_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_MASK (0x10000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_SHIFT (28U)
/*! FREQ_COUNT_GO - Start the Frequency Meter */
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_GO_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_MASK (0x20000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_SHIFT (29U)
/*! FREQ_COUNT_FINISHED - Frequency Meter has finished the Count Time */
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_FINISHED_MASK)

#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_MASK (0xC0000000U)
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_SHIFT (30U)
/*! FREQ_COUNT_TIME - Frequency Meter Count Time
 *  0b00..10 us
 *  0b01..25 us
 *  0b10..50 us
 *  0b11..100 us
 */
#define XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_SHIFT)) & XCVR_PLL_DIG_LOCK_DETECT_FREQ_COUNT_TIME_MASK)
/*! @} */

/*! @name HPM_CTRL - PLL High Port Modulator Control */
/*! @{ */

#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_MASK (0x3FFU)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_SHIFT (0U)
/*! HPM_SDM_IN_MANUAL - Manual High Port SDM Fractional value */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_MANUAL_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPFF_MASK          (0x2000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPFF_SHIFT         (13U)
/*! HPFF - HPM SDM Invalid Flag */
#define XCVR_PLL_DIG_HPM_CTRL_HPFF(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPFF_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPFF_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_MASK (0x4000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_SHIFT (14U)
/*! HPM_SDM_OUT_INVERT - Invert HPM SDM Output */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_OUT_INVERT_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_MASK (0x8000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_SHIFT (15U)
/*! HPM_SDM_IN_DISABLE - Disable HPM SDM Input */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_SDM_IN_DISABLE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_MASK (0x70000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_SHIFT (16U)
/*! HPM_LFSR_SIZE - HPM LFSR Length
 *  0b000..LFSR 9, tap mask 100010000
 *  0b001..LFSR 10, tap mask 1001000000
 *  0b010..LFSR 11, tap mask 11101000000
 *  0b011..LFSR 13, tap mask 1101100000000
 *  0b100..LFSR 15, tap mask 111010000000000
 *  0b101..LFSR 17, tap mask 11110000000000000
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_LFSR_SIZE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_MASK   (0x100000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_SHIFT  (20U)
/*! HPM_DTH_SCL - HPM Dither Scale */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_SCL_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_MASK    (0x800000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_SHIFT   (23U)
/*! HPM_DTH_EN - Dither Enable for HPM LFSR */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_DTH_EN_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_SCALE_MASK (0x3000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_SCALE_SHIFT (24U)
/*! HPM_INTEGER_SCALE - High Port Modulation Integer Scale
 *  0b00..No Scaling
 *  0b01..Multiply by 2
 *  0b10..Divide by 2
 *  0b11..Reserved
 */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_SCALE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_SCALE_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_SCALE_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_MASK (0x8000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_SHIFT (27U)
/*! HPM_INTEGER_INVERT - Invert High Port Modulation Integer */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_INTEGER_INVERT_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_MASK (0x10000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_SHIFT (28U)
/*! HPM_CAL_INVERT - Invert High Port Modulator Calibration */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_CAL_INVERT_MASK)

#define XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_MASK (0x80000000U)
#define XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_SHIFT (31U)
/*! HPM_MOD_IN_INVERT - Invert High Port Modulation */
#define XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_SHIFT)) & XCVR_PLL_DIG_HPM_CTRL_HPM_MOD_IN_INVERT_MASK)
/*! @} */

/*! @name HPMCAL_CTRL - PLL High Port Calibration Control */
/*! @{ */

#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_MASK (0x1FFFU)
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_SHIFT (0U)
/*! HPM_CAL_FACTOR - High Port Modulation Calibration Factor */
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_SHIFT)) & XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_MASK)

#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_NOT_BUMPED_MASK (0x2000U)
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_NOT_BUMPED_SHIFT (13U)
/*! HPM_CAL_NOT_BUMPED - HPM_CAL_NOT_BUMPED */
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_NOT_BUMPED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_NOT_BUMPED_SHIFT)) & XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_NOT_BUMPED_MASK)

#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_COUNT_SCALE_MASK (0x4000U)
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_COUNT_SCALE_SHIFT (14U)
/*! HPM_CAL_COUNT_SCALE - HPM_CAL_COUNT_SCALE */
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_COUNT_SCALE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_COUNT_SCALE_SHIFT)) & XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_COUNT_SCALE_MASK)

#define XCVR_PLL_DIG_HPMCAL_CTRL_HP_CAL_DISABLE_MASK (0x8000U)
#define XCVR_PLL_DIG_HPMCAL_CTRL_HP_CAL_DISABLE_SHIFT (15U)
/*! HP_CAL_DISABLE - Disable HPM Manual Calibration */
#define XCVR_PLL_DIG_HPMCAL_CTRL_HP_CAL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPMCAL_CTRL_HP_CAL_DISABLE_SHIFT)) & XCVR_PLL_DIG_HPMCAL_CTRL_HP_CAL_DISABLE_MASK)

#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_MANUAL_MASK (0x1FFF0000U)
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_MANUAL_SHIFT (16U)
/*! HPM_CAL_FACTOR_MANUAL - Manual HPM Calibration Factor */
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_MANUAL_SHIFT)) & XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_FACTOR_MANUAL_MASK)

#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_ARRAY_SIZE_MASK (0x40000000U)
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_ARRAY_SIZE_SHIFT (30U)
/*! HPM_CAL_ARRAY_SIZE - High Port Modulation Calibration Array Size
 *  0b0..128
 *  0b1..256
 */
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_ARRAY_SIZE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_ARRAY_SIZE_SHIFT)) & XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_ARRAY_SIZE_MASK)

#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_TIME_MASK (0x80000000U)
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_TIME_SHIFT (31U)
/*! HPM_CAL_TIME - High Port Modulation Calibration Time
 *  0b0..25 us
 *  0b1..50 us
 */
#define XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_TIME_SHIFT)) & XCVR_PLL_DIG_HPMCAL_CTRL_HPM_CAL_TIME_MASK)
/*! @} */

/*! @name HPM_CAL1 - PLL High Port Calibration Result 1 */
/*! @{ */

#define XCVR_PLL_DIG_HPM_CAL1_HPM_COUNT_1_MASK   (0x7FFFFU)
#define XCVR_PLL_DIG_HPM_CAL1_HPM_COUNT_1_SHIFT  (0U)
/*! HPM_COUNT_1 - High Port Modulation Counter Value 1 */
#define XCVR_PLL_DIG_HPM_CAL1_HPM_COUNT_1(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL1_HPM_COUNT_1_SHIFT)) & XCVR_PLL_DIG_HPM_CAL1_HPM_COUNT_1_MASK)

#define XCVR_PLL_DIG_HPM_CAL1_CS_WT_MASK         (0x700000U)
#define XCVR_PLL_DIG_HPM_CAL1_CS_WT_SHIFT        (20U)
/*! CS_WT - Cycle Slip Wait Time
 *  0b000..128 us
 *  0b001..256 us
 *  0b010..384 us
 *  0b011..512 us
 *  0b100..640 us
 *  0b101..768 us
 *  0b110..896 us
 *  0b111..1024 us
 */
#define XCVR_PLL_DIG_HPM_CAL1_CS_WT(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL1_CS_WT_SHIFT)) & XCVR_PLL_DIG_HPM_CAL1_CS_WT_MASK)

#define XCVR_PLL_DIG_HPM_CAL1_CS_FW_MASK         (0x7000000U)
#define XCVR_PLL_DIG_HPM_CAL1_CS_FW_SHIFT        (24U)
/*! CS_FW - Cycle Slip Flag Window
 *  0b000..8 us
 *  0b001..16 us
 *  0b010..24 us
 *  0b011..32 us
 *  0b100..64 us
 *  0b101..96 us
 *  0b110..128 us
 *  0b111..256 us
 */
#define XCVR_PLL_DIG_HPM_CAL1_CS_FW(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL1_CS_FW_SHIFT)) & XCVR_PLL_DIG_HPM_CAL1_CS_FW_MASK)

#define XCVR_PLL_DIG_HPM_CAL1_CS_FCNT_MASK       (0xF0000000U)
#define XCVR_PLL_DIG_HPM_CAL1_CS_FCNT_SHIFT      (28U)
/*! CS_FCNT - Cycle Slip Flag Count */
#define XCVR_PLL_DIG_HPM_CAL1_CS_FCNT(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL1_CS_FCNT_SHIFT)) & XCVR_PLL_DIG_HPM_CAL1_CS_FCNT_MASK)
/*! @} */

/*! @name HPM_CAL2 - PLL High Port Calibration Result 2 */
/*! @{ */

#define XCVR_PLL_DIG_HPM_CAL2_HPM_COUNT_2_MASK   (0x7FFFFU)
#define XCVR_PLL_DIG_HPM_CAL2_HPM_COUNT_2_SHIFT  (0U)
/*! HPM_COUNT_2 - High Port Modulation Counter Value 2 */
#define XCVR_PLL_DIG_HPM_CAL2_HPM_COUNT_2(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL2_HPM_COUNT_2_SHIFT)) & XCVR_PLL_DIG_HPM_CAL2_HPM_COUNT_2_MASK)

#define XCVR_PLL_DIG_HPM_CAL2_CS_RC_MASK         (0x100000U)
#define XCVR_PLL_DIG_HPM_CAL2_CS_RC_SHIFT        (20U)
/*! CS_RC - Cycle Slip Recycle */
#define XCVR_PLL_DIG_HPM_CAL2_CS_RC(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL2_CS_RC_SHIFT)) & XCVR_PLL_DIG_HPM_CAL2_CS_RC_MASK)

#define XCVR_PLL_DIG_HPM_CAL2_CS_FT_MASK         (0x1F000000U)
#define XCVR_PLL_DIG_HPM_CAL2_CS_FT_SHIFT        (24U)
/*! CS_FT - Cycle Slip Flag Timeout */
#define XCVR_PLL_DIG_HPM_CAL2_CS_FT(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_CAL2_CS_FT_SHIFT)) & XCVR_PLL_DIG_HPM_CAL2_CS_FT_MASK)
/*! @} */

/*! @name HPM_SDM_RES - PLL High Port Sigma Delta Results */
/*! @{ */

#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_MASK (0x3FFU)
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_SHIFT (0U)
/*! HPM_NUM_SELECTED - High Port Modulator SDM Numerator */
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_SHIFT)) & XCVR_PLL_DIG_HPM_SDM_RES_HPM_NUM_SELECTED_MASK)

#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_MASK  (0x3FF0000U)
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_SHIFT (16U)
/*! HPM_DENOM - High Port Modulator SDM Denominator */
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_SHIFT)) & XCVR_PLL_DIG_HPM_SDM_RES_HPM_DENOM_MASK)

#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_MASK (0xF0000000U)
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_SHIFT (28U)
/*! HPM_COUNT_ADJUST - HPM_COUNT_ADJUST */
#define XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_SHIFT)) & XCVR_PLL_DIG_HPM_SDM_RES_HPM_COUNT_ADJUST_MASK)
/*! @} */

/*! @name LPM_CTRL - PLL Low Port Modulator Control */
/*! @{ */

#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_MASK (0x3FU)
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_SHIFT (0U)
/*! PLL_LD_MANUAL - Manual PLL Loop Divider value */
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_PLL_LD_MANUAL_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_MASK (0x800U)
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_SHIFT (11U)
/*! PLL_LD_DISABLE - Disable PLL Loop Divider */
#define XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_PLL_LD_DISABLE_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPFF_MASK          (0x2000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPFF_SHIFT         (13U)
/*! LPFF - LPM SDM Invalid Flag */
#define XCVR_PLL_DIG_LPM_CTRL_LPFF(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPFF_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPFF_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_MASK   (0x4000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_SHIFT  (14U)
/*! LPM_SDM_INV - Invert LPM SDM */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_INV_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_MASK   (0x8000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_SHIFT  (15U)
/*! LPM_DISABLE - Disable LPM SDM */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_DISABLE_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_MASK   (0xF0000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_SHIFT  (16U)
/*! LPM_DTH_SCL - LPM Dither Scale
 *  0b0000..Reserved
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..-128 to 96
 *  0b0110..-256 to 192
 *  0b0111..-512 to 384
 *  0b1000..-1024 to 768
 *  0b1001..-2048 to 1536
 *  0b1010..-4096 to 3072
 *  0b1011..-8192 to 6144
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_DTH_SCL_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_MASK    (0x400000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_SHIFT   (22U)
/*! LPM_D_CTRL - LPM Dither Control in Override Mode */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_D_CTRL_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_MASK    (0x800000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_SHIFT   (23U)
/*! LPM_D_OVRD - LPM Dither Override Mode Select */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_D_OVRD_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_MASK     (0xF000000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_SHIFT    (24U)
/*! LPM_SCALE - LPM Scale Factor
 *  0b0000..No Scaling
 *  0b0001..Multiply by 2
 *  0b0010..Multiply by 4
 *  0b0011..Multiply by 8
 *  0b0100..Multiply by 16
 *  0b0101..Multiply by 32
 *  0b0110..Multiply by 64
 *  0b0111..Multiply by 128
 *  0b1000..Multiply by 256
 *  0b1001..Multiply by 512
 *  0b1010..Multiply by 1024
 *  0b1011..Multiply by 2048
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_SCALE_MASK)

#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_MASK (0x80000000U)
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_SHIFT (31U)
/*! LPM_SDM_USE_NEG - Use the Negedge of the Sigma Delta clock */
#define XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_SHIFT)) & XCVR_PLL_DIG_LPM_CTRL_LPM_SDM_USE_NEG_MASK)
/*! @} */

/*! @name LPM_SDM_CTRL1 - PLL Low Port Sigma Delta Control 1 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_MASK (0x7FU)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_SHIFT (0U)
/*! LPM_INTG_SELECTED - Low Port Modulation Integer Value Selected */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SELECTED_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_MASK (0x7F00U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_SHIFT (8U)
/*! HPM_ARRAY_BIAS - Bias value for High Port DAC Array Midpoint */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_HPM_ARRAY_BIAS_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_MASK (0x7F0000U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SHIFT (16U)
/*! LPM_INTG - Manual Low Port Modulation Integer Value */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_LPM_INTG_MASK)

#define XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_MASK (0x80000000U)
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_SHIFT (31U)
/*! SDM_MAP_DISABLE - Disable SDM Mapping */
#define XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL1_SDM_MAP_DISABLE_MASK)
/*! @} */

/*! @name LPM_SDM_CTRL2 - PLL Low Port Sigma Delta Control 2 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_MASK  (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_SHIFT (0U)
/*! LPM_NUM - Low Port Modulation Numerator */
#define XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL2_LPM_NUM_MASK)
/*! @} */

/*! @name LPM_SDM_CTRL3 - PLL Low Port Sigma Delta Control 3 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_SHIFT (0U)
/*! LPM_DENOM - Low Port Modulation Denominator */
#define XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_CTRL3_LPM_DENOM_MASK)
/*! @} */

/*! @name LPM_SDM_RES1 - PLL Low Port Sigma Delta Result 1 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_SHIFT (0U)
/*! LPM_NUM_SELECTED - Low Port Modulation Numerator Applied */
#define XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_RES1_LPM_NUM_SELECTED_MASK)
/*! @} */

/*! @name LPM_SDM_RES2 - PLL Low Port Sigma Delta Result 2 */
/*! @{ */

#define XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_MASK (0xFFFFFFFU)
#define XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_SHIFT (0U)
/*! LPM_DENOM_SELECTED - Low Port Modulation Denominator Selected */
#define XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_SHIFT)) & XCVR_PLL_DIG_LPM_SDM_RES2_LPM_DENOM_SELECTED_MASK)
/*! @} */

/*! @name DELAY_MATCH - PLL Delay Matching */
/*! @{ */

#define XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_MASK (0xFU)
#define XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_SHIFT (0U)
/*! LPM_SDM_DELAY - Low Port SDM Delay Matching */
#define XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_SHIFT)) & XCVR_PLL_DIG_DELAY_MATCH_LPM_SDM_DELAY_MASK)

#define XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_MASK (0xF00U)
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_SHIFT (8U)
/*! HPM_SDM_DELAY - High Port SDM Delay Matching */
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_SHIFT)) & XCVR_PLL_DIG_DELAY_MATCH_HPM_SDM_DELAY_MASK)

#define XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_MASK (0xF0000U)
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_SHIFT (16U)
/*! HPM_INTEGER_DELAY - High Port Integer Delay Matching */
#define XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_SHIFT)) & XCVR_PLL_DIG_DELAY_MATCH_HPM_INTEGER_DELAY_MASK)
/*! @} */

/*! @name CTUNE_CTRL - PLL Coarse Tune Control */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_MASK (0xFFFU)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_SHIFT (0U)
/*! CTUNE_TARGET_MANUAL - Manual Coarse Tune Target */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_MANUAL_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_MASK (0x8000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_SHIFT (15U)
/*! CTUNE_TARGET_DISABLE - Disable Coarse Tune Target */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_TARGET_DISABLE_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_MASK (0xF0000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_SHIFT (16U)
/*! CTUNE_ADJUST - Coarse Tune Count Adjustment */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_ADJUST_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_MASK (0x7F000000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_SHIFT (24U)
/*! CTUNE_MANUAL - Manual Coarse Tune Setting */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_MANUAL_MASK)

#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_MASK (0x80000000U)
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_SHIFT (31U)
/*! CTUNE_DISABLE - Coarse Tune Disable */
#define XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_SHIFT)) & XCVR_PLL_DIG_CTUNE_CTRL_CTUNE_DISABLE_MASK)
/*! @} */

/*! @name CTUNE_CNT6 - PLL Coarse Tune Count 6 */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_CNT6_CTUNE_COUNT_6_MASK (0x1FFFU)
#define XCVR_PLL_DIG_CTUNE_CNT6_CTUNE_COUNT_6_SHIFT (0U)
/*! CTUNE_COUNT_6 - CTUNE Count 6 */
#define XCVR_PLL_DIG_CTUNE_CNT6_CTUNE_COUNT_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CNT6_CTUNE_COUNT_6_SHIFT)) & XCVR_PLL_DIG_CTUNE_CNT6_CTUNE_COUNT_6_MASK)
/*! @} */

/*! @name CTUNE_CNT5_4 - PLL Coarse Tune Counts 5 and 4 */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_4_MASK (0x1FFFU)
#define XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_4_SHIFT (0U)
/*! CTUNE_COUNT_4 - CTUNE Count 4 */
#define XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_4_SHIFT)) & XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_4_MASK)

#define XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_5_MASK (0x1FFF0000U)
#define XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_5_SHIFT (16U)
/*! CTUNE_COUNT_5 - CTUNE Count 5 */
#define XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_5_SHIFT)) & XCVR_PLL_DIG_CTUNE_CNT5_4_CTUNE_COUNT_5_MASK)
/*! @} */

/*! @name CTUNE_CNT3_2 - PLL Coarse Tune Counts 3 and 2 */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_2_MASK (0x1FFFU)
#define XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_2_SHIFT (0U)
/*! CTUNE_COUNT_2 - CTUNE Count 2 */
#define XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_2_SHIFT)) & XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_2_MASK)

#define XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_3_MASK (0x1FFF0000U)
#define XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_3_SHIFT (16U)
/*! CTUNE_COUNT_3 - CTUNE Count 3 */
#define XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_3_SHIFT)) & XCVR_PLL_DIG_CTUNE_CNT3_2_CTUNE_COUNT_3_MASK)
/*! @} */

/*! @name CTUNE_CNT1_0 - PLL Coarse Tune Counts 1 and 0 */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_0_MASK (0x1FFFU)
#define XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_0_SHIFT (0U)
/*! CTUNE_COUNT_0 - CTUNE Count 0 */
#define XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_0_SHIFT)) & XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_0_MASK)

#define XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_1_MASK (0x1FFF0000U)
#define XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_1_SHIFT (16U)
/*! CTUNE_COUNT_1 - CTUNE Count 1 */
#define XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_1_SHIFT)) & XCVR_PLL_DIG_CTUNE_CNT1_0_CTUNE_COUNT_1_MASK)
/*! @} */

/*! @name CTUNE_RES - PLL Coarse Tune Results */
/*! @{ */

#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_MASK (0x7FU)
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_SHIFT (0U)
/*! CTUNE_SELECTED - Coarse Tune Setting to VCO */
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_SHIFT)) & XCVR_PLL_DIG_CTUNE_RES_CTUNE_SELECTED_MASK)

#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_MASK (0xFF00U)
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_SHIFT (8U)
/*! CTUNE_BEST_DIFF - Coarse Tune Absolute Best Difference */
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_SHIFT)) & XCVR_PLL_DIG_CTUNE_RES_CTUNE_BEST_DIFF_MASK)

#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_MASK (0xFFF0000U)
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_SHIFT (16U)
/*! CTUNE_FREQ_SELECTED - Coarse Tune Frequency Selected */
#define XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_SHIFT)) & XCVR_PLL_DIG_CTUNE_RES_CTUNE_FREQ_SELECTED_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_PLL_DIG_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_PLL_DIG_Peripheral_Access_Layer */


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


#endif  /* XCVR_PLL_DIG_H_ */

