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
**         CMSIS Peripheral Access Layer for XCVR_RX_DIG
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
 * @file XCVR_RX_DIG.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_RX_DIG
 *
 * CMSIS Peripheral Access Layer for XCVR_RX_DIG
 */

#if !defined(XCVR_RX_DIG_H_)
#define XCVR_RX_DIG_H_                           /**< Symbol preventing repeated inclusion */

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
   -- XCVR_RX_DIG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_RX_DIG_Peripheral_Access_Layer XCVR_RX_DIG Peripheral Access Layer
 * @{
 */

/** XCVR_RX_DIG - Size of Registers Arrays */
#define XCVR_RX_DIG_DCOC_OFFSET_COUNT             27u
#define XCVR_RX_DIG_DCOC_CAL_COUNT                3u

/** XCVR_RX_DIG - Register Layout Typedef */
typedef struct {
  __IO uint32_t RX_DIG_CTRL;                       /**< RX Digital Control, offset: 0x0 */
  __IO uint32_t AGC_CTRL_0;                        /**< AGC Control 0, offset: 0x4 */
  __IO uint32_t AGC_CTRL_1;                        /**< AGC Control 1, offset: 0x8 */
  __IO uint32_t AGC_CTRL_2;                        /**< AGC Control 2, offset: 0xC */
  __IO uint32_t AGC_CTRL_3;                        /**< AGC Control 3, offset: 0x10 */
  __I  uint32_t AGC_STAT;                          /**< AGC Status, offset: 0x14 */
  __IO uint32_t RSSI_CTRL_0;                       /**< RSSI Control 0, offset: 0x18 */
  __I  uint32_t RSSI_CTRL_1;                       /**< RSSI Control 1, offset: 0x1C */
  __I  uint32_t RSSI_DFT;                          /**< RSSI DFT, offset: 0x20 */
  __IO uint32_t DCOC_CTRL_0;                       /**< DCOC Control 0, offset: 0x24 */
  __IO uint32_t DCOC_CTRL_1;                       /**< DCOC Control 1, offset: 0x28 */
  __IO uint32_t DCOC_DAC_INIT;                     /**< DCOC DAC Initialization, offset: 0x2C */
  __IO uint32_t DCOC_DIG_MAN;                      /**< DCOC Digital Correction Manual Override, offset: 0x30 */
  __IO uint32_t DCOC_CAL_GAIN;                     /**< DCOC Calibration Gain, offset: 0x34 */
  __I  uint32_t DCOC_STAT;                         /**< DCOC Status, offset: 0x38 */
  __I  uint32_t DCOC_DC_EST;                       /**< DCOC DC Estimate, offset: 0x3C */
  __IO uint32_t DCOC_CAL_RCP;                      /**< DCOC Calibration Reciprocals, offset: 0x40 */
       uint8_t RESERVED_0[4];
  __IO uint32_t IQMC_CTRL;                         /**< IQMC Control, offset: 0x48 */
  __IO uint32_t IQMC_CAL;                          /**< IQMC Calibration, offset: 0x4C */
  __IO uint32_t LNA_GAIN_VAL_3_0;                  /**< LNA_GAIN Step Values 3..0, offset: 0x50 */
  __IO uint32_t LNA_GAIN_VAL_7_4;                  /**< LNA_GAIN Step Values 7..4, offset: 0x54 */
  __IO uint32_t LNA_GAIN_VAL_8;                    /**< LNA_GAIN Step Values 8, offset: 0x58 */
  __IO uint32_t BBA_RES_TUNE_VAL_7_0;              /**< BBA Resistor Tune Values 7..0, offset: 0x5C */
  __IO uint32_t BBA_RES_TUNE_VAL_10_8;             /**< BBA Resistor Tune Values 10..8, offset: 0x60 */
  __IO uint32_t LNA_GAIN_LIN_VAL_2_0;              /**< LNA Linear Gain Values 2..0, offset: 0x64 */
  __IO uint32_t LNA_GAIN_LIN_VAL_5_3;              /**< LNA Linear Gain Values 5..3, offset: 0x68 */
  __IO uint32_t LNA_GAIN_LIN_VAL_8_6;              /**< LNA Linear Gain Values 8..6, offset: 0x6C */
  __IO uint32_t LNA_GAIN_LIN_VAL_9;                /**< LNA Linear Gain Values 9, offset: 0x70 */
  __IO uint32_t BBA_RES_TUNE_LIN_VAL_3_0;          /**< BBA Resistor Tune Values 3..0, offset: 0x74 */
  __IO uint32_t BBA_RES_TUNE_LIN_VAL_7_4;          /**< BBA Resistor Tune Values 7..4, offset: 0x78 */
  __IO uint32_t BBA_RES_TUNE_LIN_VAL_10_8;         /**< BBA Resistor Tune Values 10..8, offset: 0x7C */
  __IO uint32_t AGC_GAIN_TBL_03_00;                /**< AGC Gain Tables Step 03..00, offset: 0x80 */
  __IO uint32_t AGC_GAIN_TBL_07_04;                /**< AGC Gain Tables Step 07..04, offset: 0x84 */
  __IO uint32_t AGC_GAIN_TBL_11_08;                /**< AGC Gain Tables Step 11..08, offset: 0x88 */
  __IO uint32_t AGC_GAIN_TBL_15_12;                /**< AGC Gain Tables Step 15..12, offset: 0x8C */
  __IO uint32_t AGC_GAIN_TBL_19_16;                /**< AGC Gain Tables Step 19..16, offset: 0x90 */
  __IO uint32_t AGC_GAIN_TBL_23_20;                /**< AGC Gain Tables Step 23..20, offset: 0x94 */
  __IO uint32_t AGC_GAIN_TBL_26_24;                /**< AGC Gain Tables Step 26..24, offset: 0x98 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DCOC_OFFSET[XCVR_RX_DIG_DCOC_OFFSET_COUNT]; /**< DCOC Offset, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t DCOC_BBA_STEP;                     /**< DCOC BBA DAC Step, offset: 0x10C */
  __IO uint32_t DCOC_TZA_STEP_0;                   /**< DCOC TZA DAC Step 0, offset: 0x110 */
  __IO uint32_t DCOC_TZA_STEP_1;                   /**< DCOC TZA DAC Step 1, offset: 0x114 */
  __IO uint32_t DCOC_TZA_STEP_2;                   /**< DCOC TZA DAC Step 2, offset: 0x118 */
  __IO uint32_t DCOC_TZA_STEP_3;                   /**< DCOC TZA DAC Step 3, offset: 0x11C */
  __IO uint32_t DCOC_TZA_STEP_4;                   /**< DCOC TZA DAC Step 4, offset: 0x120 */
  __IO uint32_t DCOC_TZA_STEP_5;                   /**< DCOC TZA DAC Step 5, offset: 0x124 */
  __IO uint32_t DCOC_TZA_STEP_6;                   /**< DCOC TZA DAC Step 6, offset: 0x128 */
  __IO uint32_t DCOC_TZA_STEP_7;                   /**< DCOC TZA DAC Step 7, offset: 0x12C */
  __IO uint32_t DCOC_TZA_STEP_8;                   /**< DCOC TZA DAC Step 5, offset: 0x130 */
  __IO uint32_t DCOC_TZA_STEP_9;                   /**< DCOC TZA DAC Step 9, offset: 0x134 */
  __IO uint32_t DCOC_TZA_STEP_10;                  /**< DCOC TZA DAC Step 10, offset: 0x138 */
       uint8_t RESERVED_2[44];
  __I  uint32_t DCOC_CAL_ALPHA;                    /**< DCOC Calibration Alpha, offset: 0x168 */
  __I  uint32_t DCOC_CAL_BETA_Q;                   /**< DCOC Calibration Beta Q, offset: 0x16C */
  __I  uint32_t DCOC_CAL_BETA_I;                   /**< DCOC Calibration Beta I, offset: 0x170 */
  __I  uint32_t DCOC_CAL_GAMMA;                    /**< DCOC Calibration Gamma, offset: 0x174 */
  __IO uint32_t DCOC_CAL_IIR;                      /**< DCOC Calibration IIR, offset: 0x178 */
       uint8_t RESERVED_3[4];
  __I  uint32_t DCOC_CAL[XCVR_RX_DIG_DCOC_CAL_COUNT]; /**< DCOC Calibration Result, array offset: 0x180, array step: 0x4 */
       uint8_t RESERVED_4[4];
  __IO uint32_t CCA_ED_LQI_CTRL_0;                 /**< RX_DIG CCA ED LQI Control Register 0, offset: 0x190 */
  __IO uint32_t CCA_ED_LQI_CTRL_1;                 /**< RX_DIG CCA ED LQI Control Register 1, offset: 0x194 */
  __I  uint32_t CCA_ED_LQI_STAT_0;                 /**< RX_DIG CCA ED LQI Status Register 0, offset: 0x198 */
       uint8_t RESERVED_5[4];
  __IO uint32_t RX_CHF_COEF_0;                     /**< Receive Channel Filter Coefficient 0, offset: 0x1A0 */
  __IO uint32_t RX_CHF_COEF_1;                     /**< Receive Channel Filter Coefficient 1, offset: 0x1A4 */
  __IO uint32_t RX_CHF_COEF_2;                     /**< Receive Channel Filter Coefficient 2, offset: 0x1A8 */
  __IO uint32_t RX_CHF_COEF_3;                     /**< Receive Channel Filter Coefficient 3, offset: 0x1AC */
  __IO uint32_t RX_CHF_COEF_4;                     /**< Receive Channel Filter Coefficient 4, offset: 0x1B0 */
  __IO uint32_t RX_CHF_COEF_5;                     /**< Receive Channel Filter Coefficient 5, offset: 0x1B4 */
  __IO uint32_t RX_CHF_COEF_6;                     /**< Receive Channel Filter Coefficient 6, offset: 0x1B8 */
  __IO uint32_t RX_CHF_COEF_7;                     /**< Receive Channel Filter Coefficient 7, offset: 0x1BC */
  __IO uint32_t RX_CHF_COEF_8;                     /**< Receive Channel Filter Coefficient 8, offset: 0x1C0 */
  __IO uint32_t RX_CHF_COEF_9;                     /**< Receive Channel Filter Coefficient 9, offset: 0x1C4 */
  __IO uint32_t RX_CHF_COEF_10;                    /**< Receive Channel Filter Coefficient 10, offset: 0x1C8 */
  __IO uint32_t RX_CHF_COEF_11;                    /**< Receive Channel Filter Coefficient 11, offset: 0x1CC */
  __IO uint32_t AGC_MAN_AGC_IDX;                   /**< AGC Manual AGC Index, offset: 0x1D0 */
  __IO uint32_t DC_RESID_CTRL;                     /**< DC Residual Control, offset: 0x1D4 */
  __I  uint32_t DC_RESID_EST;                      /**< DC Residual Estimate, offset: 0x1D8 */
  __IO uint32_t RX_RCCAL_CTRL0;                    /**< RX RC Calibration Control0, offset: 0x1DC */
  __IO uint32_t RX_RCCAL_CTRL1;                    /**< RX RC Calibration Control1, offset: 0x1E0 */
  __I  uint32_t RX_RCCAL_STAT;                     /**< RX RC Calibration Status, offset: 0x1E4 */
  __IO uint32_t AUXPLL_FCAL_CTRL;                  /**< Aux PLL Frequency Calibration Control, offset: 0x1E8 */
  __I  uint32_t AUXPLL_FCAL_CNT6;                  /**< Aux PLL Frequency Calibration Count 6, offset: 0x1EC */
  __I  uint32_t AUXPLL_FCAL_CNT5_4;                /**< Aux PLL Frequency Calibration Count 5 and 4, offset: 0x1F0 */
  __I  uint32_t AUXPLL_FCAL_CNT3_2;                /**< Aux PLL Frequency Calibration Count 3 and 2, offset: 0x1F4 */
  __I  uint32_t AUXPLL_FCAL_CNT1_0;                /**< Aux PLL Frequency Calibration Count 1 and 0, offset: 0x1F8 */
  __IO uint32_t RXDIG_DFT;                         /**< RXDIG DFT, offset: 0x1FC */
} XCVR_RX_DIG_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_RX_DIG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_RX_DIG_Register_Masks XCVR_RX_DIG Register Masks
 * @{
 */

/*! @name RX_DIG_CTRL - RX Digital Control */
/*! @{ */

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_NEGEDGE_MASK (0x1U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_NEGEDGE_SHIFT (0U)
/*! RX_ADC_NEGEDGE - Receive ADC Negative Edge Selection
 *  0b0..Register ADC data on positive edge of clock
 *  0b1..Register ADC data on negative edge of clock
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_NEGEDGE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_NEGEDGE_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_NEGEDGE_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_CH_FILT_BYPASS_MASK (0x2U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_CH_FILT_BYPASS_SHIFT (1U)
/*! RX_CH_FILT_BYPASS - Receive Channel Filter Bypass
 *  0b0..Channel filter is enabled.
 *  0b1..Disable and bypass channel filter.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_CH_FILT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_CH_FILT_BYPASS_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_CH_FILT_BYPASS_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_RAW_EN_MASK (0x4U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_RAW_EN_SHIFT (2U)
/*! RX_ADC_RAW_EN - ADC Raw Mode selection
 *  0b0..Normal operation.
 *  0b1..The decimation filter's 12bit output consists of ADC samples in the 8 LSBs. This is for test purposes
 *       only to observe ADC output via XCVR DMA or DTEST.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_RAW_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_RAW_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_RAW_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_POL_MASK  (0x8U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_POL_SHIFT (3U)
/*! RX_ADC_POL - Receive ADC Polarity
 *  0b0..ADC output of 1'b0 maps to -1, 1'b1 maps to +1 (default)
 *  0b1..ADC output of 1'b0 maps to +1, 1'b1 maps to -1
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_POL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_POL_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_ADC_POL_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_OSR_MASK (0x70U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_OSR_SHIFT (4U)
/*! RX_DEC_FILT_OSR - Decimation Filter Oversampling
 *  0b000..OSR 4
 *  0b001..OSR 8
 *  0b010..OSR 16
 *  0b100..OSR 32
 *  0b011..OSR 6
 *  0b101..OSR 12
 *  0b110..OSR 24
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_OSR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_OSR_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_OSR_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_FSK_ZB_SEL_MASK (0x100U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_FSK_ZB_SEL_SHIFT (8U)
/*! RX_FSK_ZB_SEL - FSK / 802.15.4 demodulator select
 *  0b0..FSK demodulator.
 *  0b1..802.15.4 demodulator.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_FSK_ZB_SEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_FSK_ZB_SEL_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_FSK_ZB_SEL_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_NORM_EN_MASK  (0x200U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_NORM_EN_SHIFT (9U)
/*! RX_NORM_EN - Normalizer Enable
 *  0b0..Normalizer is disabled.
 *  0b1..Normalizer is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_NORM_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_NORM_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_NORM_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_EN_MASK  (0x400U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_EN_SHIFT (10U)
/*! RX_RSSI_EN - RSSI Measurement Enable
 *  0b0..RSSI measurement is disabled.
 *  0b1..RSSI measurement is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_AGC_EN_MASK   (0x800U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_AGC_EN_SHIFT  (11U)
/*! RX_AGC_EN - AGC Global Enable
 *  0b0..AGC is disabled.
 *  0b1..AGC is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_AGC_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_AGC_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_AGC_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_EN_MASK  (0x1000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_EN_SHIFT (12U)
/*! RX_DCOC_EN - DCOC Enable
 *  0b0..DCOC is disabled.
 *  0b1..DCOC is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_CAL_EN_MASK (0x2000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_CAL_EN_SHIFT (13U)
/*! RX_DCOC_CAL_EN - DCOC Calibration Enable
 *  0b0..DCOC calibration is disabled.
 *  0b1..DCOC calibration is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_CAL_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_CAL_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DCOC_CAL_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_IQ_SWAP_MASK  (0x4000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_IQ_SWAP_SHIFT (14U)
/*! RX_IQ_SWAP - RX IQ Swap
 *  0b0..IQ swap is disabled.
 *  0b1..IQ swap is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_IQ_SWAP(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_IQ_SWAP_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_IQ_SWAP_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DC_RESID_EN_MASK (0x8000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DC_RESID_EN_SHIFT (15U)
/*! RX_DC_RESID_EN - DC Residual Enable
 *  0b0..DC Residual block is disabled.
 *  0b1..DC Residual block is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DC_RESID_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DC_RESID_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DC_RESID_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_EN_MASK   (0x10000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_EN_SHIFT  (16U)
/*! RX_SRC_EN - RX Sample Rate Converter Enable
 *  0b0..SRC is disabled.
 *  0b1..SRC is enabled.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_RATE_MASK (0x20000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_RATE_SHIFT (17U)
/*! RX_SRC_RATE - RX Sample Rate Converter Rate Selections
 *  0b0..SRC is configured for a First Order Hold rate of 8/13.
 *  0b1..SRC is configured for a Zero Order Hold rate of 12/13.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_RATE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_RATE_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_SRC_RATE_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DMA_DTEST_EN_MASK (0x40000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DMA_DTEST_EN_SHIFT (18U)
/*! RX_DMA_DTEST_EN - RX DMA and DTEST enable */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DMA_DTEST_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DMA_DTEST_EN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DMA_DTEST_EN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_GAIN_MASK (0x1F00000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_GAIN_SHIFT (20U)
/*! RX_DEC_FILT_GAIN - Decimation Filter Fractional Gain */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_GAIN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_GAIN_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_GAIN_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HZD_CORR_DIS_MASK (0x2000000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HZD_CORR_DIS_SHIFT (25U)
/*! RX_DEC_FILT_HZD_CORR_DIS - Decimator filter hazard correction disable */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HZD_CORR_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HZD_CORR_DIS_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HZD_CORR_DIS_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HAZARD_MASK (0x10000000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HAZARD_SHIFT (28U)
/*! RX_DEC_FILT_HAZARD - Decimator output, hazard condition detected
 *  0b0..A hazard condition has not been detected
 *  0b1..A hazard condition has been detected
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HAZARD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HAZARD_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_HAZARD_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_FILT_HAZARD_MASK (0x20000000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_FILT_HAZARD_SHIFT (29U)
/*! RX_RSSI_FILT_HAZARD - Decimator output for RSSI, hazard condition detected
 *  0b0..A hazard condition has not been detected
 *  0b1..A hazard condition has been detected
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_FILT_HAZARD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_FILT_HAZARD_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_RSSI_FILT_HAZARD_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_I_MASK (0x40000000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_I_SHIFT (30U)
/*! RX_DEC_FILT_SAT_I - Decimator output, saturation detected for I channel
 *  0b0..A saturation condition has not occurred.
 *  0b1..A saturation condition has occurred.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_I_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_I_MASK)

#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_Q_MASK (0x80000000U)
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_Q_SHIFT (31U)
/*! RX_DEC_FILT_SAT_Q - Decimator output, saturation detected for Q channel
 *  0b0..A saturation condition has not occurred.
 *  0b1..A saturation condition has occurred.
 */
#define XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_Q_SHIFT)) & XCVR_RX_DIG_RX_DIG_CTRL_RX_DEC_FILT_SAT_Q_MASK)
/*! @} */

/*! @name AGC_CTRL_0 - AGC Control 0 */
/*! @{ */

#define XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_EN_MASK  (0x1U)
#define XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_EN_SHIFT (0U)
/*! SLOW_AGC_EN - Slow AGC Enable */
#define XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_EN(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_SRC_MASK (0x6U)
#define XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_SRC_SHIFT (1U)
/*! SLOW_AGC_SRC - Slow AGC Source Selection
 *  0b00..Access Address match (for active protocol)
 *  0b01..Preamble Detect (for active protocol)
 *  0b10..Fast AGC expire timer
 *  0b11..Reserved
 */
#define XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_SRC(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_SRC_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_SLOW_AGC_SRC_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_EN_MASK (0x8U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_EN_SHIFT (3U)
/*! AGC_FREEZE_EN - AGC Freeze Enable */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_PRE_OR_AA_MASK (0x10U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_PRE_OR_AA_SHIFT (4U)
/*! AGC_FREEZE_PRE_OR_AA - AGC Freeze Source Selection
 *  0b0..Access Address match (for active protocol)
 *  0b1..Preamble Detect (for active protocol)
 */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_PRE_OR_AA(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_PRE_OR_AA_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_FREEZE_PRE_OR_AA_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_EN_MASK    (0x40U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_EN_SHIFT   (6U)
/*! AGC_UP_EN - AGC Up Enable */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_SRC_MASK   (0x80U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_SRC_SHIFT  (7U)
/*! AGC_UP_SRC - AGC Up Source
 *  0b0..PDET LO
 *  0b1..RSSI
 */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_SRC(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_SRC_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_SRC_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_BBA_STEP_SZ_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_BBA_STEP_SZ_SHIFT (8U)
/*! AGC_DOWN_BBA_STEP_SZ - AGC_DOWN_BBA_STEP_SZ */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_BBA_STEP_SZ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_BBA_STEP_SZ_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_BBA_STEP_SZ_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_LNA_STEP_SZ_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_LNA_STEP_SZ_SHIFT (12U)
/*! AGC_DOWN_LNA_STEP_SZ - AGC_DOWN_LNA_STEP_SZ */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_LNA_STEP_SZ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_LNA_STEP_SZ_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_LNA_STEP_SZ_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_RSSI_THRESH_MASK (0xFF0000U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_RSSI_THRESH_SHIFT (16U)
/*! AGC_UP_RSSI_THRESH - AGC UP RSSI Threshold */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_RSSI_THRESH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_RSSI_THRESH_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_UP_RSSI_THRESH_MASK)

#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_RSSI_THRESH_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_RSSI_THRESH_SHIFT (24U)
/*! AGC_DOWN_RSSI_THRESH - AGC DOWN RSSI Threshold */
#define XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_RSSI_THRESH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_RSSI_THRESH_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_0_AGC_DOWN_RSSI_THRESH_MASK)
/*! @} */

/*! @name AGC_CTRL_1 - AGC Control 1 */
/*! @{ */

#define XCVR_RX_DIG_AGC_CTRL_1_BBA_ALT_CODE_MASK (0xFU)
#define XCVR_RX_DIG_AGC_CTRL_1_BBA_ALT_CODE_SHIFT (0U)
/*! BBA_ALT_CODE - BBA_ALT_CODE */
#define XCVR_RX_DIG_AGC_CTRL_1_BBA_ALT_CODE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_BBA_ALT_CODE_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_BBA_ALT_CODE_MASK)

#define XCVR_RX_DIG_AGC_CTRL_1_LNA_ALT_CODE_MASK (0xFF0U)
#define XCVR_RX_DIG_AGC_CTRL_1_LNA_ALT_CODE_SHIFT (4U)
/*! LNA_ALT_CODE - LNA_ALT_CODE */
#define XCVR_RX_DIG_AGC_CTRL_1_LNA_ALT_CODE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_LNA_ALT_CODE_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_LNA_ALT_CODE_MASK)

#define XCVR_RX_DIG_AGC_CTRL_1_LNA_USER_GAIN_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_CTRL_1_LNA_USER_GAIN_SHIFT (12U)
/*! LNA_USER_GAIN - LNA_USER_GAIN */
#define XCVR_RX_DIG_AGC_CTRL_1_LNA_USER_GAIN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_LNA_USER_GAIN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_LNA_USER_GAIN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_1_BBA_USER_GAIN_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_CTRL_1_BBA_USER_GAIN_SHIFT (16U)
/*! BBA_USER_GAIN - BBA_USER_GAIN */
#define XCVR_RX_DIG_AGC_CTRL_1_BBA_USER_GAIN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_BBA_USER_GAIN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_BBA_USER_GAIN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_1_USER_LNA_GAIN_EN_MASK (0x100000U)
#define XCVR_RX_DIG_AGC_CTRL_1_USER_LNA_GAIN_EN_SHIFT (20U)
/*! USER_LNA_GAIN_EN - User LNA Gain Enable */
#define XCVR_RX_DIG_AGC_CTRL_1_USER_LNA_GAIN_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_USER_LNA_GAIN_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_USER_LNA_GAIN_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_1_USER_BBA_GAIN_EN_MASK (0x200000U)
#define XCVR_RX_DIG_AGC_CTRL_1_USER_BBA_GAIN_EN_SHIFT (21U)
/*! USER_BBA_GAIN_EN - User BBA Gain Enable */
#define XCVR_RX_DIG_AGC_CTRL_1_USER_BBA_GAIN_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_USER_BBA_GAIN_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_USER_BBA_GAIN_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_1_PRESLOW_EN_MASK   (0x400000U)
#define XCVR_RX_DIG_AGC_CTRL_1_PRESLOW_EN_SHIFT  (22U)
/*! PRESLOW_EN - Pre-slow Enable
 *  0b0..Pre-slow is disabled.
 *  0b1..Pre-slow is enabled.
 */
#define XCVR_RX_DIG_AGC_CTRL_1_PRESLOW_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_PRESLOW_EN_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_PRESLOW_EN_MASK)

#define XCVR_RX_DIG_AGC_CTRL_1_LNA_GAIN_SETTLE_TIME_MASK (0xFF000000U)
#define XCVR_RX_DIG_AGC_CTRL_1_LNA_GAIN_SETTLE_TIME_SHIFT (24U)
/*! LNA_GAIN_SETTLE_TIME - LNA_GAIN_SETTLE_TIME */
#define XCVR_RX_DIG_AGC_CTRL_1_LNA_GAIN_SETTLE_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_1_LNA_GAIN_SETTLE_TIME_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_1_LNA_GAIN_SETTLE_TIME_MASK)
/*! @} */

/*! @name AGC_CTRL_2 - AGC Control 2 */
/*! @{ */

#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_RST_MASK (0x1U)
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_RST_SHIFT (0U)
/*! BBA_PDET_RST - BBA PDET Reset */
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_RST(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_RST_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_RST_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_RST_MASK (0x2U)
#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_RST_SHIFT (1U)
/*! TZA_PDET_RST - TZA PDET Reset */
#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_RST(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_RST_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_RST_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_MAN_PDET_RST_MASK (0x4U)
#define XCVR_RX_DIG_AGC_CTRL_2_MAN_PDET_RST_SHIFT (2U)
/*! MAN_PDET_RST - MAN PDET Reset
 *  0b0..The peak detector reset signals are controlled automatically by the AGC.
 *  0b1..The BBA_PDET_RST and TZA_PDET_RST are used to manually control the peak detector reset signals.
 */
#define XCVR_RX_DIG_AGC_CTRL_2_MAN_PDET_RST(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_MAN_PDET_RST_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_MAN_PDET_RST_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_BBA_GAIN_SETTLE_TIME_MASK (0xFF0U)
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_GAIN_SETTLE_TIME_SHIFT (4U)
/*! BBA_GAIN_SETTLE_TIME - BBA Gain Settle Time */
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_GAIN_SETTLE_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_BBA_GAIN_SETTLE_TIME_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_BBA_GAIN_SETTLE_TIME_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_LO_MASK (0x7000U)
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_LO_SHIFT (12U)
/*! BBA_PDET_SEL_LO - BBA PDET Threshold Low
 *  0b000..0.600V
 *  0b001..0.615V
 *  0b010..0.630V
 *  0b011..0.645V
 *  0b100..0.660V
 *  0b101..0.675V
 *  0b110..0.690V
 *  0b111..0.705V
 */
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_LO_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_LO_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_HI_MASK (0x38000U)
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_HI_SHIFT (15U)
/*! BBA_PDET_SEL_HI - BBA PDET Threshold High
 *  0b000..0.600V
 *  0b001..0.795V
 *  0b010..0.900V
 *  0b011..0.945V
 *  0b100..1.005V
 *  0b101..1.050V
 *  0b110..1.095V
 *  0b111..1.155V
 */
#define XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_HI_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_BBA_PDET_SEL_HI_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_LO_MASK (0x1C0000U)
#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_LO_SHIFT (18U)
/*! TZA_PDET_SEL_LO - TZA PDET Threshold Low
 *  0b000..0.600V
 *  0b001..0.615V
 *  0b010..0.630V
 *  0b011..0.645V
 *  0b100..0.660V
 *  0b101..0.675V
 *  0b110..0.690V
 *  0b111..0.705V
 */
#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_LO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_LO_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_LO_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_HI_MASK (0xE00000U)
#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_HI_SHIFT (21U)
/*! TZA_PDET_SEL_HI - TZA PDET Threshold High
 *  0b000..0.60V
 *  0b001..0.63V
 *  0b010..0.66V
 *  0b011..0.69V
 *  0b100..0.72V
 *  0b101..0.75V
 *  0b110..0.78V
 *  0b111..0.81V
 */
#define XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_HI(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_HI_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_TZA_PDET_SEL_HI_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_AGC_FAST_EXPIRE_MASK (0x3F000000U)
#define XCVR_RX_DIG_AGC_CTRL_2_AGC_FAST_EXPIRE_SHIFT (24U)
/*! AGC_FAST_EXPIRE - AGC Fast Expire */
#define XCVR_RX_DIG_AGC_CTRL_2_AGC_FAST_EXPIRE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_AGC_FAST_EXPIRE_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_AGC_FAST_EXPIRE_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_LNA_LG_ON_OVR_MASK (0x40000000U)
#define XCVR_RX_DIG_AGC_CTRL_2_LNA_LG_ON_OVR_SHIFT (30U)
/*! LNA_LG_ON_OVR - LNA_LG_ON override */
#define XCVR_RX_DIG_AGC_CTRL_2_LNA_LG_ON_OVR(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_LNA_LG_ON_OVR_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_LNA_LG_ON_OVR_MASK)

#define XCVR_RX_DIG_AGC_CTRL_2_LNA_HG_ON_OVR_MASK (0x80000000U)
#define XCVR_RX_DIG_AGC_CTRL_2_LNA_HG_ON_OVR_SHIFT (31U)
/*! LNA_HG_ON_OVR - LNA_HG_ON override */
#define XCVR_RX_DIG_AGC_CTRL_2_LNA_HG_ON_OVR(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_2_LNA_HG_ON_OVR_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_2_LNA_HG_ON_OVR_MASK)
/*! @} */

/*! @name AGC_CTRL_3 - AGC Control 3 */
/*! @{ */

#define XCVR_RX_DIG_AGC_CTRL_3_AGC_UNFREEZE_TIME_MASK (0x1FFFU)
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_UNFREEZE_TIME_SHIFT (0U)
/*! AGC_UNFREEZE_TIME - AGC Unfreeze Time */
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_UNFREEZE_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_3_AGC_UNFREEZE_TIME_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_3_AGC_UNFREEZE_TIME_MASK)

#define XCVR_RX_DIG_AGC_CTRL_3_AGC_PDET_LO_DLY_MASK (0xE000U)
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_PDET_LO_DLY_SHIFT (13U)
/*! AGC_PDET_LO_DLY - AGC Peak Detect Low Delay */
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_PDET_LO_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_3_AGC_PDET_LO_DLY_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_3_AGC_PDET_LO_DLY_MASK)

#define XCVR_RX_DIG_AGC_CTRL_3_AGC_RSSI_DELT_H2S_MASK (0x7F0000U)
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_RSSI_DELT_H2S_SHIFT (16U)
/*! AGC_RSSI_DELT_H2S - AGC_RSSI_DELT_H2S */
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_RSSI_DELT_H2S(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_3_AGC_RSSI_DELT_H2S_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_3_AGC_RSSI_DELT_H2S_MASK)

#define XCVR_RX_DIG_AGC_CTRL_3_AGC_H2S_STEP_SZ_MASK (0xF800000U)
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_H2S_STEP_SZ_SHIFT (23U)
/*! AGC_H2S_STEP_SZ - AGC_H2S_STEP_SZ */
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_H2S_STEP_SZ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_3_AGC_H2S_STEP_SZ_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_3_AGC_H2S_STEP_SZ_MASK)

#define XCVR_RX_DIG_AGC_CTRL_3_AGC_UP_STEP_SZ_MASK (0xF0000000U)
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_UP_STEP_SZ_SHIFT (28U)
/*! AGC_UP_STEP_SZ - AGC Up Step Size */
#define XCVR_RX_DIG_AGC_CTRL_3_AGC_UP_STEP_SZ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_CTRL_3_AGC_UP_STEP_SZ_SHIFT)) & XCVR_RX_DIG_AGC_CTRL_3_AGC_UP_STEP_SZ_MASK)
/*! @} */

/*! @name AGC_STAT - AGC Status */
/*! @{ */

#define XCVR_RX_DIG_AGC_STAT_BBA_PDET_LO_STAT_MASK (0x1U)
#define XCVR_RX_DIG_AGC_STAT_BBA_PDET_LO_STAT_SHIFT (0U)
/*! BBA_PDET_LO_STAT - BBA Peak Detector Low Status */
#define XCVR_RX_DIG_AGC_STAT_BBA_PDET_LO_STAT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_STAT_BBA_PDET_LO_STAT_SHIFT)) & XCVR_RX_DIG_AGC_STAT_BBA_PDET_LO_STAT_MASK)

#define XCVR_RX_DIG_AGC_STAT_BBA_PDET_HI_STAT_MASK (0x2U)
#define XCVR_RX_DIG_AGC_STAT_BBA_PDET_HI_STAT_SHIFT (1U)
/*! BBA_PDET_HI_STAT - BBA Peak Detector High Status */
#define XCVR_RX_DIG_AGC_STAT_BBA_PDET_HI_STAT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_STAT_BBA_PDET_HI_STAT_SHIFT)) & XCVR_RX_DIG_AGC_STAT_BBA_PDET_HI_STAT_MASK)

#define XCVR_RX_DIG_AGC_STAT_TZA_PDET_LO_STAT_MASK (0x4U)
#define XCVR_RX_DIG_AGC_STAT_TZA_PDET_LO_STAT_SHIFT (2U)
/*! TZA_PDET_LO_STAT - TZA Peak Detector Low Status */
#define XCVR_RX_DIG_AGC_STAT_TZA_PDET_LO_STAT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_STAT_TZA_PDET_LO_STAT_SHIFT)) & XCVR_RX_DIG_AGC_STAT_TZA_PDET_LO_STAT_MASK)

#define XCVR_RX_DIG_AGC_STAT_TZA_PDET_HI_STAT_MASK (0x8U)
#define XCVR_RX_DIG_AGC_STAT_TZA_PDET_HI_STAT_SHIFT (3U)
/*! TZA_PDET_HI_STAT - TZA Peak Detector High Status */
#define XCVR_RX_DIG_AGC_STAT_TZA_PDET_HI_STAT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_STAT_TZA_PDET_HI_STAT_SHIFT)) & XCVR_RX_DIG_AGC_STAT_TZA_PDET_HI_STAT_MASK)

#define XCVR_RX_DIG_AGC_STAT_CURR_AGC_IDX_MASK   (0x1F0U)
#define XCVR_RX_DIG_AGC_STAT_CURR_AGC_IDX_SHIFT  (4U)
/*! CURR_AGC_IDX - Current AGC Gain Index */
#define XCVR_RX_DIG_AGC_STAT_CURR_AGC_IDX(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_STAT_CURR_AGC_IDX_SHIFT)) & XCVR_RX_DIG_AGC_STAT_CURR_AGC_IDX_MASK)

#define XCVR_RX_DIG_AGC_STAT_AGC_FROZEN_MASK     (0x200U)
#define XCVR_RX_DIG_AGC_STAT_AGC_FROZEN_SHIFT    (9U)
/*! AGC_FROZEN - AGC Frozen Status
 *  0b0..AGC is not frozen.
 *  0b1..AGC is frozen.
 */
#define XCVR_RX_DIG_AGC_STAT_AGC_FROZEN(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_STAT_AGC_FROZEN_SHIFT)) & XCVR_RX_DIG_AGC_STAT_AGC_FROZEN_MASK)

#define XCVR_RX_DIG_AGC_STAT_RSSI_ADC_RAW_MASK   (0xFF0000U)
#define XCVR_RX_DIG_AGC_STAT_RSSI_ADC_RAW_SHIFT  (16U)
/*! RSSI_ADC_RAW - ADC RAW RSSI Reading */
#define XCVR_RX_DIG_AGC_STAT_RSSI_ADC_RAW(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_STAT_RSSI_ADC_RAW_SHIFT)) & XCVR_RX_DIG_AGC_STAT_RSSI_ADC_RAW_MASK)
/*! @} */

/*! @name RSSI_CTRL_0 - RSSI Control 0 */
/*! @{ */

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_USE_VALS_MASK (0x1U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_USE_VALS_SHIFT (0U)
/*! RSSI_USE_VALS - RSSI Values Selection */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_USE_VALS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_USE_VALS_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_USE_VALS_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_SRC_MASK (0x6U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_SRC_SHIFT (1U)
/*! RSSI_HOLD_SRC - RSSI Hold Source Selection
 *  0b00..Access Address match
 *  0b01..Preamble Detect
 *  0b10..Reserved
 *  0b11..802.15.4 LQI done (1=freeze, 0=run AGC)
 */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_SRC(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_SRC_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_SRC_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_EN_MASK (0x8U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_EN_SHIFT (3U)
/*! RSSI_HOLD_EN - RSSI Hold Enable */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_EN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_EN_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_EN_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_CW_WEIGHT_MASK (0x60U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_CW_WEIGHT_SHIFT (5U)
/*! RSSI_IIR_CW_WEIGHT - RSSI IIR CW Weighting
 *  0b00..Bypass
 *  0b01..1/8
 *  0b10..1/16
 *  0b11..1/32
 */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_CW_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_CW_WEIGHT_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_CW_WEIGHT_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_N_WINDOW_AVG_MASK (0x300U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_N_WINDOW_AVG_SHIFT (8U)
/*! RSSI_N_WINDOW_AVG - RSSI N Window Average
 *  0b00..No averaging
 *  0b01..Averaging window length is 2 samples
 *  0b10..Averaging window length is 4 samples
 *  0b11..Averaging window length is 8 samples
 */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_N_WINDOW_AVG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_N_WINDOW_AVG_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_N_WINDOW_AVG_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_DELAY_MASK (0xFC00U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_DELAY_SHIFT (10U)
/*! RSSI_HOLD_DELAY - RSSI Hold Delay */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_DELAY_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_HOLD_DELAY_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_WEIGHT_MASK (0xF0000U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_WEIGHT_SHIFT (16U)
/*! RSSI_IIR_WEIGHT - RSSI IIR Weighting
 *  0b0000..Bypass
 *  0b0001..1/2
 *  0b0010..1/4
 *  0b0011..1/8
 *  0b0100..1/16
 *  0b0101..1/32
 */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_WEIGHT_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_IIR_WEIGHT_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_VLD_SETTLE_MASK (0x700000U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_VLD_SETTLE_SHIFT (20U)
/*! RSSI_VLD_SETTLE - RSSI Valid Settle */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_VLD_SETTLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_VLD_SETTLE_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_VLD_SETTLE_MASK)

#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_ADJ_MASK    (0xFF000000U)
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_ADJ_SHIFT   (24U)
/*! RSSI_ADJ - RSSI Adjustment */
#define XCVR_RX_DIG_RSSI_CTRL_0_RSSI_ADJ(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_0_RSSI_ADJ_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_0_RSSI_ADJ_MASK)
/*! @} */

/*! @name RSSI_CTRL_1 - RSSI Control 1 */
/*! @{ */

#define XCVR_RX_DIG_RSSI_CTRL_1_RSSI_OUT_MASK    (0xFF000000U)
#define XCVR_RX_DIG_RSSI_CTRL_1_RSSI_OUT_SHIFT   (24U)
/*! RSSI_OUT - RSSI Reading */
#define XCVR_RX_DIG_RSSI_CTRL_1_RSSI_OUT(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_CTRL_1_RSSI_OUT_SHIFT)) & XCVR_RX_DIG_RSSI_CTRL_1_RSSI_OUT_MASK)
/*! @} */

/*! @name RSSI_DFT - RSSI DFT */
/*! @{ */

#define XCVR_RX_DIG_RSSI_DFT_DFT_MAG_MASK        (0x1FFFU)
#define XCVR_RX_DIG_RSSI_DFT_DFT_MAG_SHIFT       (0U)
/*! DFT_MAG - RSSI MAG */
#define XCVR_RX_DIG_RSSI_DFT_DFT_MAG(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_DFT_DFT_MAG_SHIFT)) & XCVR_RX_DIG_RSSI_DFT_DFT_MAG_MASK)

#define XCVR_RX_DIG_RSSI_DFT_DFT_NOISE_MASK      (0x1FFF0000U)
#define XCVR_RX_DIG_RSSI_DFT_DFT_NOISE_SHIFT     (16U)
/*! DFT_NOISE - RSSI MAG */
#define XCVR_RX_DIG_RSSI_DFT_DFT_NOISE(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RSSI_DFT_DFT_NOISE_SHIFT)) & XCVR_RX_DIG_RSSI_DFT_DFT_NOISE_MASK)
/*! @} */

/*! @name DCOC_CTRL_0 - DCOC Control 0 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MIDPWR_TRK_DIS_MASK (0x1U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MIDPWR_TRK_DIS_SHIFT (0U)
/*! DCOC_MIDPWR_TRK_DIS - DCOC Mid Power Tracking Disable
 *  0b0..Tracking corrections are enabled as determined by DCOC_CORRECT_SRC and DCOC_TRK_MIN_AGC_IDX.
 *  0b1..Tracking corrections are disabled when either the TZA or BBA lo peak detector asserts.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MIDPWR_TRK_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MIDPWR_TRK_DIS_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MIDPWR_TRK_DIS_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MAN_MASK    (0x2U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MAN_SHIFT   (1U)
/*! DCOC_MAN - DCOC Manual Override */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MAN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MAN_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_MAN_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_TRK_EST_OVR_MASK (0x4U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_TRK_EST_OVR_SHIFT (2U)
/*! DCOC_TRK_EST_OVR - Override for the DCOC tracking estimator
 *  0b0..The tracking estimator is enabled only as needed by the corrector
 *  0b1..The tracking estimator remains enabled whenever the DCOC is active
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_TRK_EST_OVR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_TRK_EST_OVR_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_TRK_EST_OVR_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_SRC_MASK (0x8U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_SRC_SHIFT (3U)
/*! DCOC_CORRECT_SRC - DCOC Corrector Source
 *  0b0..If correction is enabled, the DCOC will use only the DCOC calibration table to correct the DC offset.
 *  0b1..If correction is enabled, the DCOC will use the DCOC calibration table and then the tracking estimator to correct the DC offset.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_SRC(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_SRC_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_SRC_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_EN_MASK (0x10U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_EN_SHIFT (4U)
/*! DCOC_CORRECT_EN - DCOC Correction Enable
 *  0b0..Correction disabled. The DCOC will not correct the DC offset.
 *  0b1..Correction enabled. The DCOC will use the TZA and BBA DACs, and apply digital corrections (if DCOC_CORRECT_SRC=1) to correct the DC offset.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_EN_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORRECT_EN_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_TRACK_FROM_ZERO_MASK (0x20U)
#define XCVR_RX_DIG_DCOC_CTRL_0_TRACK_FROM_ZERO_SHIFT (5U)
/*! TRACK_FROM_ZERO - Track from Zero
 *  0b0..Track from current I/Q sample.
 *  0b1..Track from zero.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_TRACK_FROM_ZERO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_TRACK_FROM_ZERO_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_TRACK_FROM_ZERO_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_BBA_CORR_POL_MASK (0x40U)
#define XCVR_RX_DIG_DCOC_CTRL_0_BBA_CORR_POL_SHIFT (6U)
/*! BBA_CORR_POL - BBA Correction Polarity
 *  0b0..Normal polarity.
 *  0b1..Negative polarity. This should be set if the ADC output is inverted, or if the BBA DACs were implemented with negative polarity.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_BBA_CORR_POL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_BBA_CORR_POL_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_BBA_CORR_POL_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_TZA_CORR_POL_MASK (0x80U)
#define XCVR_RX_DIG_DCOC_CTRL_0_TZA_CORR_POL_SHIFT (7U)
/*! TZA_CORR_POL - TZA Correction Polarity
 *  0b0..Normal polarity.
 *  0b1..Negative polarity. This should be set if the ADC output is inverted, or if the TZA DACs were implemented with negative polarity.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_TZA_CORR_POL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_TZA_CORR_POL_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_TZA_CORR_POL_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CAL_DURATION_MASK (0x1F00U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CAL_DURATION_SHIFT (8U)
/*! DCOC_CAL_DURATION - DCOC Calibration Duration
 *  0b00000..Reserved
 *  0b00001-0b11111..For a 32MHz reference clock, this is the calibration duration in microseconds; for other
 *                   reference clock frequencies, the delay is scaled accordingly.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CAL_DURATION(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CAL_DURATION_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CAL_DURATION_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_DLY_MASK (0x1F0000U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_DLY_SHIFT (16U)
/*! DCOC_CORR_DLY - DCOC Correction Delay
 *  0b00000..Reserved
 *  0b00001-0b11111..For a 32MHz reference clock, this is the wait time in microseconds; for other reference clock frequencies, the delay is scaled accordingly.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_DLY_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_DLY_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_HOLD_TIME_MASK (0x7F000000U)
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_HOLD_TIME_SHIFT (24U)
/*! DCOC_CORR_HOLD_TIME - DCOC Correction Hold Time
 *  0b0000000..Reserved
 *  0b0000001-0b1111110..For a 32MHz reference clock, this is the delay in microseconds; for other reference clock frequencies, the delay is scaled accordingly.
 *  0b1111111..The DC correction is not frozen.
 */
#define XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_HOLD_TIME(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_HOLD_TIME_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_0_DCOC_CORR_HOLD_TIME_MASK)
/*! @} */

/*! @name DCOC_CTRL_1 - DCOC Control 1 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_IDX_MASK (0x3U)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_IDX_SHIFT (0U)
/*! DCOC_SIGN_SCALE_IDX - DCOC Sign Scaling
 *  0b00..1/8
 *  0b01..1/16
 *  0b10..1/32
 *  0b11..1/64
 */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_IDX_MASK (0x1CU)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_IDX_SHIFT (2U)
/*! DCOC_ALPHAC_SCALE_IDX - DCOC Alpha-C Scaling
 *  0b000..1/2
 *  0b001..1/4
 *  0b010..1/8
 *  0b011..1/16
 *  0b100..1/32
 *  0b101..1/64
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_IDX_MASK (0xE0U)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_IDX_SHIFT (5U)
/*! DCOC_ALPHA_RADIUS_IDX - Alpha-R Scaling
 *  0b000..1
 *  0b001..1/2
 *  0b010..1/4
 *  0b011..1/8
 *  0b100..1/16
 *  0b101..1/32
 *  0b110..1/64
 *  0b111..Reserved
 */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_EST_GS_CNT_MASK (0x7000U)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_EST_GS_CNT_SHIFT (12U)
/*! DCOC_TRK_EST_GS_CNT - DCOC Tracking Estimator Gearshift Count */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_EST_GS_CNT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_EST_GS_CNT_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_EST_GS_CNT_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_GS_IDX_MASK (0x30000U)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_GS_IDX_SHIFT (16U)
/*! DCOC_SIGN_SCALE_GS_IDX - DCOC Sign Scaling for Gearshift
 *  0b00..1/8
 *  0b01..1/16
 *  0b10..1/32
 *  0b11..1/64
 */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_GS_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_GS_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_SIGN_SCALE_GS_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_GS_IDX_MASK (0x1C0000U)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_GS_IDX_SHIFT (18U)
/*! DCOC_ALPHAC_SCALE_GS_IDX - DCOC Alpha-C Scaling for Gearshift
 *  0b000..1/2
 *  0b001..1/4
 *  0b010..1/8
 *  0b011..1/16
 *  0b100..1/32
 *  0b101..1/64
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_GS_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_GS_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHAC_SCALE_GS_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_GS_IDX_MASK (0xE00000U)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_GS_IDX_SHIFT (21U)
/*! DCOC_ALPHA_RADIUS_GS_IDX - Alpha-R Scaling for Gearshift
 *  0b000..1
 *  0b001..1/2
 *  0b010..1/4
 *  0b011..1/8
 *  0b100..1/16
 *  0b101..1/32
 *  0b110..1/64
 *  0b111..Reserved
 */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_GS_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_GS_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_ALPHA_RADIUS_GS_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_MIN_AGC_IDX_MASK (0x1F000000U)
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_MIN_AGC_IDX_SHIFT (24U)
/*! DCOC_TRK_MIN_AGC_IDX - DCOC Tracking Minimum AGC Table Index */
#define XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_MIN_AGC_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_MIN_AGC_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CTRL_1_DCOC_TRK_MIN_AGC_IDX_MASK)
/*! @} */

/*! @name DCOC_DAC_INIT - DCOC DAC Initialization */
/*! @{ */

#define XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_I_MASK (0x3FU)
#define XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_I_SHIFT (0U)
/*! BBA_DCOC_INIT_I - DCOC BBA Init I */
#define XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_I_SHIFT)) & XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_I_MASK)

#define XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_Q_MASK (0x3F00U)
#define XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_Q_SHIFT (8U)
/*! BBA_DCOC_INIT_Q - DCOC BBA Init Q */
#define XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_Q_SHIFT)) & XCVR_RX_DIG_DCOC_DAC_INIT_BBA_DCOC_INIT_Q_MASK)

#define XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_I_MASK (0xFF0000U)
#define XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_I_SHIFT (16U)
/*! TZA_DCOC_INIT_I - DCOC TZA Init I */
#define XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_I_SHIFT)) & XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_I_MASK)

#define XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_Q_MASK (0xFF000000U)
#define XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_Q_SHIFT (24U)
/*! TZA_DCOC_INIT_Q - DCOC TZA Init Q */
#define XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_Q_SHIFT)) & XCVR_RX_DIG_DCOC_DAC_INIT_TZA_DCOC_INIT_Q_MASK)
/*! @} */

/*! @name DCOC_DIG_MAN - DCOC Digital Correction Manual Override */
/*! @{ */

#define XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_I_MASK (0xFFFU)
#define XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_I_SHIFT (0U)
/*! DIG_DCOC_INIT_I - DCOC DIG Init I */
#define XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_I_SHIFT)) & XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_I_MASK)

#define XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_Q_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_Q_SHIFT (16U)
/*! DIG_DCOC_INIT_Q - DCOC DIG Init Q */
#define XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_Q_SHIFT)) & XCVR_RX_DIG_DCOC_DIG_MAN_DIG_DCOC_INIT_Q_MASK)
/*! @} */

/*! @name DCOC_CAL_GAIN - DCOC Calibration Gain */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN1_MASK (0xF00U)
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN1_SHIFT (8U)
/*! DCOC_BBA_CAL_GAIN1 - DCOC BBA Calibration Gain 1 */
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN1_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN1_MASK)

#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN1_MASK (0xF000U)
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN1_SHIFT (12U)
/*! DCOC_LNA_CAL_GAIN1 - DCOC LNA Calibration Gain 1 */
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN1_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN1_MASK)

#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN2_MASK (0xF0000U)
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN2_SHIFT (16U)
/*! DCOC_BBA_CAL_GAIN2 - DCOC BBA Calibration Gain 2 */
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN2_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN2_MASK)

#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN2_MASK (0xF00000U)
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN2_SHIFT (20U)
/*! DCOC_LNA_CAL_GAIN2 - DCOC LNA Calibration Gain 2 */
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN2_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN2_MASK)

#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN3_MASK (0xF000000U)
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN3_SHIFT (24U)
/*! DCOC_BBA_CAL_GAIN3 - DCOC BBA Calibration Gain 3 */
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN3_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_BBA_CAL_GAIN3_MASK)

#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN3_MASK (0xF0000000U)
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN3_SHIFT (28U)
/*! DCOC_LNA_CAL_GAIN3 - DCOC LNA Calibration Gain 3 */
#define XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN3_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAIN_DCOC_LNA_CAL_GAIN3_MASK)
/*! @} */

/*! @name DCOC_STAT - DCOC Status */
/*! @{ */

#define XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_I_MASK    (0x3FU)
#define XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_I_SHIFT   (0U)
/*! BBA_DCOC_I - DCOC BBA DAC I */
#define XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_I(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_I_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_I_MASK)

#define XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_Q_MASK    (0x3F00U)
#define XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_Q_SHIFT   (8U)
/*! BBA_DCOC_Q - DCOC BBA DAC Q */
#define XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_Q(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_Q_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_BBA_DCOC_Q_MASK)

#define XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_I_MASK    (0xFF0000U)
#define XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_I_SHIFT   (16U)
/*! TZA_DCOC_I - DCOC TZA DAC I */
#define XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_I(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_I_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_I_MASK)

#define XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_Q_MASK    (0xFF000000U)
#define XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_Q_SHIFT   (24U)
/*! TZA_DCOC_Q - DCOC TZA DAC Q */
#define XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_Q(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_Q_SHIFT)) & XCVR_RX_DIG_DCOC_STAT_TZA_DCOC_Q_MASK)
/*! @} */

/*! @name DCOC_DC_EST - DCOC DC Estimate */
/*! @{ */

#define XCVR_RX_DIG_DCOC_DC_EST_DC_EST_I_MASK    (0xFFFU)
#define XCVR_RX_DIG_DCOC_DC_EST_DC_EST_I_SHIFT   (0U)
/*! DC_EST_I - DCOC DC Estimate I */
#define XCVR_RX_DIG_DCOC_DC_EST_DC_EST_I(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DC_EST_DC_EST_I_SHIFT)) & XCVR_RX_DIG_DCOC_DC_EST_DC_EST_I_MASK)

#define XCVR_RX_DIG_DCOC_DC_EST_DC_EST_Q_MASK    (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_DC_EST_DC_EST_Q_SHIFT   (16U)
/*! DC_EST_Q - DCOC DC Estimate Q */
#define XCVR_RX_DIG_DCOC_DC_EST_DC_EST_Q(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_DC_EST_DC_EST_Q_SHIFT)) & XCVR_RX_DIG_DCOC_DC_EST_DC_EST_Q_MASK)
/*! @} */

/*! @name DCOC_CAL_RCP - DCOC Calibration Reciprocals */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_RCP_DCOC_TMP_CALC_RECIP_MASK (0x7FFU)
#define XCVR_RX_DIG_DCOC_CAL_RCP_DCOC_TMP_CALC_RECIP_SHIFT (0U)
/*! DCOC_TMP_CALC_RECIP - DCOC Calculation Reciprocal */
#define XCVR_RX_DIG_DCOC_CAL_RCP_DCOC_TMP_CALC_RECIP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_RCP_DCOC_TMP_CALC_RECIP_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_RCP_DCOC_TMP_CALC_RECIP_MASK)

#define XCVR_RX_DIG_DCOC_CAL_RCP_ALPHA_CALC_RECIP_MASK (0x7FF0000U)
#define XCVR_RX_DIG_DCOC_CAL_RCP_ALPHA_CALC_RECIP_SHIFT (16U)
/*! ALPHA_CALC_RECIP - Alpha Calculation Reciprocal */
#define XCVR_RX_DIG_DCOC_CAL_RCP_ALPHA_CALC_RECIP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_RCP_ALPHA_CALC_RECIP_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_RCP_ALPHA_CALC_RECIP_MASK)
/*! @} */

/*! @name IQMC_CTRL - IQMC Control */
/*! @{ */

#define XCVR_RX_DIG_IQMC_CTRL_IQMC_CAL_EN_MASK   (0x1U)
#define XCVR_RX_DIG_IQMC_CTRL_IQMC_CAL_EN_SHIFT  (0U)
/*! IQMC_CAL_EN - IQ Mismatch Cal Enable */
#define XCVR_RX_DIG_IQMC_CTRL_IQMC_CAL_EN(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL_IQMC_CAL_EN_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL_IQMC_CAL_EN_MASK)

#define XCVR_RX_DIG_IQMC_CTRL_IQMC_NUM_ITER_MASK (0xFF00U)
#define XCVR_RX_DIG_IQMC_CTRL_IQMC_NUM_ITER_SHIFT (8U)
/*! IQMC_NUM_ITER - IQ Mismatch Cal Num Iter */
#define XCVR_RX_DIG_IQMC_CTRL_IQMC_NUM_ITER(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL_IQMC_NUM_ITER_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL_IQMC_NUM_ITER_MASK)

#define XCVR_RX_DIG_IQMC_CTRL_IQMC_DC_GAIN_ADJ_MASK (0x7FF0000U)
#define XCVR_RX_DIG_IQMC_CTRL_IQMC_DC_GAIN_ADJ_SHIFT (16U)
/*! IQMC_DC_GAIN_ADJ - IQ Mismatch Correction DC Gain Coeff */
#define XCVR_RX_DIG_IQMC_CTRL_IQMC_DC_GAIN_ADJ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CTRL_IQMC_DC_GAIN_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CTRL_IQMC_DC_GAIN_ADJ_MASK)
/*! @} */

/*! @name IQMC_CAL - IQMC Calibration */
/*! @{ */

#define XCVR_RX_DIG_IQMC_CAL_IQMC_GAIN_ADJ_MASK  (0x7FFU)
#define XCVR_RX_DIG_IQMC_CAL_IQMC_GAIN_ADJ_SHIFT (0U)
/*! IQMC_GAIN_ADJ - IQ Mismatch Correction Gain Coeff */
#define XCVR_RX_DIG_IQMC_CAL_IQMC_GAIN_ADJ(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CAL_IQMC_GAIN_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CAL_IQMC_GAIN_ADJ_MASK)

#define XCVR_RX_DIG_IQMC_CAL_IQMC_PHASE_ADJ_MASK (0xFFF0000U)
#define XCVR_RX_DIG_IQMC_CAL_IQMC_PHASE_ADJ_SHIFT (16U)
/*! IQMC_PHASE_ADJ - IQ Mismatch Correction Phase Coeff */
#define XCVR_RX_DIG_IQMC_CAL_IQMC_PHASE_ADJ(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_IQMC_CAL_IQMC_PHASE_ADJ_SHIFT)) & XCVR_RX_DIG_IQMC_CAL_IQMC_PHASE_ADJ_MASK)
/*! @} */

/*! @name LNA_GAIN_VAL_3_0 - LNA_GAIN Step Values 3..0 */
/*! @{ */

#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_0_MASK (0xFFU)
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_0_SHIFT (0U)
/*! LNA_GAIN_VAL_0 - LNA_GAIN step 0 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_0_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_0_MASK)

#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_1_MASK (0xFF00U)
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_1_SHIFT (8U)
/*! LNA_GAIN_VAL_1 - LNA_GAIN step 1 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_1_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_1_MASK)

#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_2_MASK (0xFF0000U)
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_2_SHIFT (16U)
/*! LNA_GAIN_VAL_2 - LNA_GAIN step 2 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_2_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_2_MASK)

#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_3_MASK (0xFF000000U)
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_3_SHIFT (24U)
/*! LNA_GAIN_VAL_3 - LNA_GAIN step 3 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_3_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_3_0_LNA_GAIN_VAL_3_MASK)
/*! @} */

/*! @name LNA_GAIN_VAL_7_4 - LNA_GAIN Step Values 7..4 */
/*! @{ */

#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_4_MASK (0xFFU)
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_4_SHIFT (0U)
/*! LNA_GAIN_VAL_4 - LNA_GAIN step 4 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_4_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_4_MASK)

#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_5_MASK (0xFF00U)
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_5_SHIFT (8U)
/*! LNA_GAIN_VAL_5 - LNA_GAIN step 5 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_5_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_5_MASK)

#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_6_MASK (0xFF0000U)
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_6_SHIFT (16U)
/*! LNA_GAIN_VAL_6 - LNA_GAIN step 6 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_6_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_6_MASK)

#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_7_MASK (0xFF000000U)
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_7_SHIFT (24U)
/*! LNA_GAIN_VAL_7 - LNA_GAIN step 7 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_7_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_7_4_LNA_GAIN_VAL_7_MASK)
/*! @} */

/*! @name LNA_GAIN_VAL_8 - LNA_GAIN Step Values 8 */
/*! @{ */

#define XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_8_MASK (0xFFU)
#define XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_8_SHIFT (0U)
/*! LNA_GAIN_VAL_8 - LNA_GAIN step 8 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_8_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_8_MASK)

#define XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_9_MASK (0xFF00U)
#define XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_9_SHIFT (8U)
/*! LNA_GAIN_VAL_9 - LNA_GAIN step 9 */
#define XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_9_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_VAL_8_LNA_GAIN_VAL_9_MASK)
/*! @} */

/*! @name BBA_RES_TUNE_VAL_7_0 - BBA Resistor Tune Values 7..0 */
/*! @{ */

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_0_MASK (0xFU)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_0_SHIFT (0U)
/*! BBA_RES_TUNE_VAL_0 - BBA Resistor Tune Step 0 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_0_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_0_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_1_MASK (0xF0U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_1_SHIFT (4U)
/*! BBA_RES_TUNE_VAL_1 - BBA Resistor Tune Step 1 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_1_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_1_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_2_MASK (0xF00U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_2_SHIFT (8U)
/*! BBA_RES_TUNE_VAL_2 - BBA Resistor Tune Step 2 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_2_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_2_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_3_MASK (0xF000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_3_SHIFT (12U)
/*! BBA_RES_TUNE_VAL_3 - BBA Resistor Tune Step 3 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_3_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_3_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_4_MASK (0xF0000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_4_SHIFT (16U)
/*! BBA_RES_TUNE_VAL_4 - BBA Resistor Tune Step 4 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_4_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_4_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_5_MASK (0xF00000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_5_SHIFT (20U)
/*! BBA_RES_TUNE_VAL_5 - BBA Resistor Tune Step 5 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_5_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_5_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_6_MASK (0xF000000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_6_SHIFT (24U)
/*! BBA_RES_TUNE_VAL_6 - BBA Resistor Tune Step 6 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_6_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_6_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_7_MASK (0xF0000000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_7_SHIFT (28U)
/*! BBA_RES_TUNE_VAL_7 - BBA Resistor Tune Step 7 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_7_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_7_0_BBA_RES_TUNE_VAL_7_MASK)
/*! @} */

/*! @name BBA_RES_TUNE_VAL_10_8 - BBA Resistor Tune Values 10..8 */
/*! @{ */

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_8_MASK (0xFU)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_8_SHIFT (0U)
/*! BBA_RES_TUNE_VAL_8 - BBA Resistor Tune Step 8 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_8_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_8_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_9_MASK (0xF0U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_9_SHIFT (4U)
/*! BBA_RES_TUNE_VAL_9 - BBA Resistor Tune Step 9 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_9_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_9_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_10_MASK (0xF00U)
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_10_SHIFT (8U)
/*! BBA_RES_TUNE_VAL_10 - BBA Resistor Tune Step 10 */
#define XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_10_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_VAL_10_8_BBA_RES_TUNE_VAL_10_MASK)
/*! @} */

/*! @name LNA_GAIN_LIN_VAL_2_0 - LNA Linear Gain Values 2..0 */
/*! @{ */

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_0_MASK (0x3FFU)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_0_SHIFT (0U)
/*! LNA_GAIN_LIN_VAL_0 - LNA Linear Gain Step 0 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_0_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_0_MASK)

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_1_MASK (0xFFC00U)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_1_SHIFT (10U)
/*! LNA_GAIN_LIN_VAL_1 - LNA Linear Gain Step 1 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_1_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_1_MASK)

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_2_MASK (0x3FF00000U)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_2_SHIFT (20U)
/*! LNA_GAIN_LIN_VAL_2 - LNA Linear Gain Step 2 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_2_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_2_0_LNA_GAIN_LIN_VAL_2_MASK)
/*! @} */

/*! @name LNA_GAIN_LIN_VAL_5_3 - LNA Linear Gain Values 5..3 */
/*! @{ */

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_3_MASK (0x3FFU)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_3_SHIFT (0U)
/*! LNA_GAIN_LIN_VAL_3 - LNA Linear Gain Step 3 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_3_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_3_MASK)

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_4_MASK (0xFFC00U)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_4_SHIFT (10U)
/*! LNA_GAIN_LIN_VAL_4 - LNA Linear Gain Step 4 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_4_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_4_MASK)

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_5_MASK (0x3FF00000U)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_5_SHIFT (20U)
/*! LNA_GAIN_LIN_VAL_5 - LNA Linear Gain Step 5 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_5_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_5_3_LNA_GAIN_LIN_VAL_5_MASK)
/*! @} */

/*! @name LNA_GAIN_LIN_VAL_8_6 - LNA Linear Gain Values 8..6 */
/*! @{ */

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_6_MASK (0x3FFU)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_6_SHIFT (0U)
/*! LNA_GAIN_LIN_VAL_6 - LNA Linear Gain Step 6 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_6_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_6_MASK)

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_7_MASK (0xFFC00U)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_7_SHIFT (10U)
/*! LNA_GAIN_LIN_VAL_7 - LNA Linear Gain Step 7 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_7_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_7_MASK)

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_8_MASK (0x3FF00000U)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_8_SHIFT (20U)
/*! LNA_GAIN_LIN_VAL_8 - LNA Linear Gain Step 8 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_8_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_8_6_LNA_GAIN_LIN_VAL_8_MASK)
/*! @} */

/*! @name LNA_GAIN_LIN_VAL_9 - LNA Linear Gain Values 9 */
/*! @{ */

#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_9_LNA_GAIN_LIN_VAL_9_MASK (0x3FFU)
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_9_LNA_GAIN_LIN_VAL_9_SHIFT (0U)
/*! LNA_GAIN_LIN_VAL_9 - LNA Linear Gain Step 9 */
#define XCVR_RX_DIG_LNA_GAIN_LIN_VAL_9_LNA_GAIN_LIN_VAL_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_LNA_GAIN_LIN_VAL_9_LNA_GAIN_LIN_VAL_9_SHIFT)) & XCVR_RX_DIG_LNA_GAIN_LIN_VAL_9_LNA_GAIN_LIN_VAL_9_MASK)
/*! @} */

/*! @name BBA_RES_TUNE_LIN_VAL_3_0 - BBA Resistor Tune Values 3..0 */
/*! @{ */

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_0_MASK (0xFFU)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_0_SHIFT (0U)
/*! BBA_RES_TUNE_LIN_VAL_0 - BBA Resistor Tune Linear Gain Step 0 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_0_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_0_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_1_MASK (0xFF00U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_1_SHIFT (8U)
/*! BBA_RES_TUNE_LIN_VAL_1 - BBA Resistor Tune Linear Gain Step 1 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_1_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_1_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_2_MASK (0xFF0000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_2_SHIFT (16U)
/*! BBA_RES_TUNE_LIN_VAL_2 - BBA Resistor Tune Linear Gain Step 2 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_2_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_2_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_3_MASK (0xFF000000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_3_SHIFT (24U)
/*! BBA_RES_TUNE_LIN_VAL_3 - BBA Resistor Tune Linear Gain Step 3 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_3_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_3_0_BBA_RES_TUNE_LIN_VAL_3_MASK)
/*! @} */

/*! @name BBA_RES_TUNE_LIN_VAL_7_4 - BBA Resistor Tune Values 7..4 */
/*! @{ */

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_4_MASK (0xFFU)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_4_SHIFT (0U)
/*! BBA_RES_TUNE_LIN_VAL_4 - BBA Resistor Tune Linear Gain Step 4 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_4_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_4_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_5_MASK (0xFF00U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_5_SHIFT (8U)
/*! BBA_RES_TUNE_LIN_VAL_5 - BBA Resistor Tune Linear Gain Step 5 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_5_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_5_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_6_MASK (0xFF0000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_6_SHIFT (16U)
/*! BBA_RES_TUNE_LIN_VAL_6 - BBA Resistor Tune Linear Gain Step 6 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_6_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_6_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_7_MASK (0xFF000000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_7_SHIFT (24U)
/*! BBA_RES_TUNE_LIN_VAL_7 - BBA Resistor Tune Linear Gain Step 7 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_7_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_7_4_BBA_RES_TUNE_LIN_VAL_7_MASK)
/*! @} */

/*! @name BBA_RES_TUNE_LIN_VAL_10_8 - BBA Resistor Tune Values 10..8 */
/*! @{ */

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_8_MASK (0x3FFU)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_8_SHIFT (0U)
/*! BBA_RES_TUNE_LIN_VAL_8 - BBA Resistor Tune Linear Gain Step 8 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_8_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_8_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_9_MASK (0xFFC00U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_9_SHIFT (10U)
/*! BBA_RES_TUNE_LIN_VAL_9 - BBA Resistor Tune Linear Gain Step 9 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_9_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_9_MASK)

#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_10_MASK (0x3FF00000U)
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_10_SHIFT (20U)
/*! BBA_RES_TUNE_LIN_VAL_10 - BBA Resistor Tune Linear Gain Step 10 */
#define XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_10_SHIFT)) & XCVR_RX_DIG_BBA_RES_TUNE_LIN_VAL_10_8_BBA_RES_TUNE_LIN_VAL_10_MASK)
/*! @} */

/*! @name AGC_GAIN_TBL_03_00 - AGC Gain Tables Step 03..00 */
/*! @{ */

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_00_MASK (0xFU)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_00_SHIFT (0U)
/*! BBA_GAIN_00 - BBA Gain 00 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_00(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_00_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_00_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_00_MASK (0xF0U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_00_SHIFT (4U)
/*! LNA_GAIN_00 - LNA Gain 00 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_00(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_00_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_00_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_01_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_01_SHIFT (8U)
/*! BBA_GAIN_01 - BBA Gain 01 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_01(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_01_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_01_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_01_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_01_SHIFT (12U)
/*! LNA_GAIN_01 - LNA Gain 01 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_01(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_01_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_01_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_02_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_02_SHIFT (16U)
/*! BBA_GAIN_02 - BBA Gain 02 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_02(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_02_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_02_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_02_MASK (0xF00000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_02_SHIFT (20U)
/*! LNA_GAIN_02 - LNA Gain 02 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_02(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_02_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_02_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_03_MASK (0xF000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_03_SHIFT (24U)
/*! BBA_GAIN_03 - BBA Gain 03 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_03(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_03_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_BBA_GAIN_03_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_03_MASK (0xF0000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_03_SHIFT (28U)
/*! LNA_GAIN_03 - LNA Gain 03 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_03(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_03_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_03_00_LNA_GAIN_03_MASK)
/*! @} */

/*! @name AGC_GAIN_TBL_07_04 - AGC Gain Tables Step 07..04 */
/*! @{ */

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_04_MASK (0xFU)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_04_SHIFT (0U)
/*! BBA_GAIN_04 - BBA Gain 04 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_04(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_04_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_04_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_04_MASK (0xF0U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_04_SHIFT (4U)
/*! LNA_GAIN_04 - LNA Gain 04 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_04(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_04_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_04_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_05_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_05_SHIFT (8U)
/*! BBA_GAIN_05 - BBA Gain 05 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_05(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_05_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_05_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_05_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_05_SHIFT (12U)
/*! LNA_GAIN_05 - LNA Gain 05 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_05(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_05_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_05_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_06_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_06_SHIFT (16U)
/*! BBA_GAIN_06 - BBA Gain 06 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_06(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_06_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_06_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_06_MASK (0xF00000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_06_SHIFT (20U)
/*! LNA_GAIN_06 - LNA Gain 06 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_06(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_06_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_06_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_07_MASK (0xF000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_07_SHIFT (24U)
/*! BBA_GAIN_07 - BBA Gain 07 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_07(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_07_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_BBA_GAIN_07_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_07_MASK (0xF0000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_07_SHIFT (28U)
/*! LNA_GAIN_07 - LNA Gain 07 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_07(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_07_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_07_04_LNA_GAIN_07_MASK)
/*! @} */

/*! @name AGC_GAIN_TBL_11_08 - AGC Gain Tables Step 11..08 */
/*! @{ */

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_08_MASK (0xFU)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_08_SHIFT (0U)
/*! BBA_GAIN_08 - BBA Gain 08 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_08(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_08_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_08_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_08_MASK (0xF0U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_08_SHIFT (4U)
/*! LNA_GAIN_08 - LNA Gain 08 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_08(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_08_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_08_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_09_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_09_SHIFT (8U)
/*! BBA_GAIN_09 - BBA Gain 09 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_09(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_09_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_09_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_09_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_09_SHIFT (12U)
/*! LNA_GAIN_09 - LNA Gain 09 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_09(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_09_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_09_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_10_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_10_SHIFT (16U)
/*! BBA_GAIN_10 - BBA Gain 10 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_10_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_10_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_10_MASK (0xF00000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_10_SHIFT (20U)
/*! LNA_GAIN_10 - LNA Gain 10 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_10_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_10_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_11_MASK (0xF000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_11_SHIFT (24U)
/*! BBA_GAIN_11 - BBA Gain 11 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_11_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_BBA_GAIN_11_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_11_MASK (0xF0000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_11_SHIFT (28U)
/*! LNA_GAIN_11 - LNA Gain 11 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_11_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_11_08_LNA_GAIN_11_MASK)
/*! @} */

/*! @name AGC_GAIN_TBL_15_12 - AGC Gain Tables Step 15..12 */
/*! @{ */

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_12_MASK (0xFU)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_12_SHIFT (0U)
/*! BBA_GAIN_12 - BBA Gain 12 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_12(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_12_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_12_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_12_MASK (0xF0U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_12_SHIFT (4U)
/*! LNA_GAIN_12 - LNA Gain 12 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_12(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_12_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_12_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_13_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_13_SHIFT (8U)
/*! BBA_GAIN_13 - BBA Gain 13 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_13(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_13_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_13_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_13_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_13_SHIFT (12U)
/*! LNA_GAIN_13 - LNA Gain 13 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_13(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_13_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_13_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_14_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_14_SHIFT (16U)
/*! BBA_GAIN_14 - BBA Gain 14 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_14(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_14_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_14_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_14_MASK (0xF00000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_14_SHIFT (20U)
/*! LNA_GAIN_14 - LNA Gain 14 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_14(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_14_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_14_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_15_MASK (0xF000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_15_SHIFT (24U)
/*! BBA_GAIN_15 - BBA Gain 15 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_15(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_15_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_BBA_GAIN_15_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_15_MASK (0xF0000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_15_SHIFT (28U)
/*! LNA_GAIN_15 - LNA Gain 15 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_15(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_15_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_15_12_LNA_GAIN_15_MASK)
/*! @} */

/*! @name AGC_GAIN_TBL_19_16 - AGC Gain Tables Step 19..16 */
/*! @{ */

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_16_MASK (0xFU)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_16_SHIFT (0U)
/*! BBA_GAIN_16 - BBA Gain 16 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_16(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_16_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_16_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_16_MASK (0xF0U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_16_SHIFT (4U)
/*! LNA_GAIN_16 - LNA Gain 16 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_16(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_16_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_16_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_17_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_17_SHIFT (8U)
/*! BBA_GAIN_17 - BBA Gain 17 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_17(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_17_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_17_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_17_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_17_SHIFT (12U)
/*! LNA_GAIN_17 - LNA Gain 17 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_17(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_17_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_17_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_18_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_18_SHIFT (16U)
/*! BBA_GAIN_18 - BBA Gain 18 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_18(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_18_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_18_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_18_MASK (0xF00000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_18_SHIFT (20U)
/*! LNA_GAIN_18 - LNA Gain 18 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_18(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_18_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_18_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_19_MASK (0xF000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_19_SHIFT (24U)
/*! BBA_GAIN_19 - BBA Gain 193 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_19(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_19_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_BBA_GAIN_19_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_19_MASK (0xF0000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_19_SHIFT (28U)
/*! LNA_GAIN_19 - LNA Gain 19 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_19(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_19_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_19_16_LNA_GAIN_19_MASK)
/*! @} */

/*! @name AGC_GAIN_TBL_23_20 - AGC Gain Tables Step 23..20 */
/*! @{ */

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_20_MASK (0xFU)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_20_SHIFT (0U)
/*! BBA_GAIN_20 - BBA Gain 20 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_20(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_20_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_20_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_20_MASK (0xF0U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_20_SHIFT (4U)
/*! LNA_GAIN_20 - LNA Gain 20 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_20(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_20_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_20_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_21_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_21_SHIFT (8U)
/*! BBA_GAIN_21 - BBA Gain 21 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_21(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_21_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_21_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_21_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_21_SHIFT (12U)
/*! LNA_GAIN_21 - LNA Gain 21 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_21(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_21_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_21_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_22_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_22_SHIFT (16U)
/*! BBA_GAIN_22 - BBA Gain 22 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_22(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_22_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_22_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_22_MASK (0xF00000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_22_SHIFT (20U)
/*! LNA_GAIN_22 - LNA Gain 22 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_22(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_22_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_22_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_23_MASK (0xF000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_23_SHIFT (24U)
/*! BBA_GAIN_23 - BBA Gain 23 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_23(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_23_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_BBA_GAIN_23_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_23_MASK (0xF0000000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_23_SHIFT (28U)
/*! LNA_GAIN_23 - LNA Gain 23 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_23(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_23_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_23_20_LNA_GAIN_23_MASK)
/*! @} */

/*! @name AGC_GAIN_TBL_26_24 - AGC Gain Tables Step 26..24 */
/*! @{ */

#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_24_MASK (0xFU)
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_24_SHIFT (0U)
/*! BBA_GAIN_24 - BBA Gain 24 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_24(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_24_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_24_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_24_MASK (0xF0U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_24_SHIFT (4U)
/*! LNA_GAIN_24 - LNA Gain 24 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_24(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_24_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_24_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_25_MASK (0xF00U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_25_SHIFT (8U)
/*! BBA_GAIN_25 - BBA Gain 25 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_25(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_25_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_25_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_25_MASK (0xF000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_25_SHIFT (12U)
/*! LNA_GAIN_25 - LNA Gain 25 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_25(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_25_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_25_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_26_MASK (0xF0000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_26_SHIFT (16U)
/*! BBA_GAIN_26 - BBA Gain 26 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_26(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_26_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_26_24_BBA_GAIN_26_MASK)

#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_26_MASK (0xF00000U)
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_26_SHIFT (20U)
/*! LNA_GAIN_26 - LNA Gain 26 */
#define XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_26(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_26_SHIFT)) & XCVR_RX_DIG_AGC_GAIN_TBL_26_24_LNA_GAIN_26_MASK)
/*! @} */

/*! @name DCOC_OFFSET - DCOC Offset */
/*! @{ */

#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_I_MASK (0x3FU)
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_I_SHIFT (0U)
/*! DCOC_BBA_OFFSET_I - DCOC BBA I-channel offset */
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_I_SHIFT)) & XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_I_MASK)

#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_Q_MASK (0x3F00U)
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_Q_SHIFT (8U)
/*! DCOC_BBA_OFFSET_Q - DCOC BBA Q-channel offset */
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_Q_SHIFT)) & XCVR_RX_DIG_DCOC_OFFSET_DCOC_BBA_OFFSET_Q_MASK)

#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_I_MASK (0xFF0000U)
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_I_SHIFT (16U)
/*! DCOC_TZA_OFFSET_I - DCOC TZA I-channel offset */
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_I_SHIFT)) & XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_I_MASK)

#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_Q_MASK (0xFF000000U)
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_Q_SHIFT (24U)
/*! DCOC_TZA_OFFSET_Q - DCOC TZA Q-channel offset */
#define XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_Q_SHIFT)) & XCVR_RX_DIG_DCOC_OFFSET_DCOC_TZA_OFFSET_Q_MASK)
/*! @} */

/*! @name DCOC_BBA_STEP - DCOC BBA DAC Step */
/*! @{ */

#define XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_RECIP_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_RECIP_SHIFT (0U)
/*! BBA_DCOC_STEP_RECIP - DCOC BBA Reciprocal of Step Size */
#define XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_RECIP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_RECIP_SHIFT)) & XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_RECIP_MASK)

#define XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_MASK (0x1FF0000U)
#define XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_SHIFT (16U)
/*! BBA_DCOC_STEP - DCOC BBA Step Size */
#define XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_SHIFT)) & XCVR_RX_DIG_DCOC_BBA_STEP_BBA_DCOC_STEP_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_0 - DCOC TZA DAC Step 0 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_RCP_0_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_RCP_0_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_0 - DCOC_TZA_STEP_RCP_0 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_RCP_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_RCP_0_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_RCP_0_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_GAIN_0_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_GAIN_0_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_0 - DCOC_TZA_STEP_GAIN_0 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_GAIN_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_GAIN_0_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_0_DCOC_TZA_STEP_GAIN_0_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_1 - DCOC TZA DAC Step 1 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_RCP_1_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_RCP_1_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_1 - DCOC_TZA_STEP_RCP_1 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_RCP_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_RCP_1_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_RCP_1_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_GAIN_1_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_GAIN_1_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_1 - DCOC_TZA_STEP_GAIN_1 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_GAIN_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_GAIN_1_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_1_DCOC_TZA_STEP_GAIN_1_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_2 - DCOC TZA DAC Step 2 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_RCP_2_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_RCP_2_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_2 - DCOC_TZA_STEP_RCP_2 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_RCP_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_RCP_2_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_RCP_2_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_GAIN_2_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_GAIN_2_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_2 - DCOC_TZA_STEP_GAIN_2 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_GAIN_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_GAIN_2_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_2_DCOC_TZA_STEP_GAIN_2_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_3 - DCOC TZA DAC Step 3 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_RCP_3_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_RCP_3_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_3 - DCOC_TZA_STEP_RCP_3 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_RCP_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_RCP_3_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_RCP_3_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_GAIN_3_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_GAIN_3_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_3 - DCOC_TZA_STEP_GAIN_3 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_GAIN_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_GAIN_3_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_3_DCOC_TZA_STEP_GAIN_3_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_4 - DCOC TZA DAC Step 4 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_RCP_4_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_RCP_4_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_4 - DCOC_TZA_STEP_RCP_4 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_RCP_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_RCP_4_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_RCP_4_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_GAIN_4_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_GAIN_4_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_4 - DCOC_TZA_STEP_GAIN_4 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_GAIN_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_GAIN_4_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_4_DCOC_TZA_STEP_GAIN_4_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_5 - DCOC TZA DAC Step 5 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_RCP_5_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_RCP_5_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_5 - DCOC_TZA_STEP_RCP_5 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_RCP_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_RCP_5_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_RCP_5_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_GAIN_5_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_GAIN_5_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_5 - DCOC_TZA_STEP_GAIN_5 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_GAIN_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_GAIN_5_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_5_DCOC_TZA_STEP_GAIN_5_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_6 - DCOC TZA DAC Step 6 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_RCP_6_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_RCP_6_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_6 - DCOC_TZA_STEP_RCP_6 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_RCP_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_RCP_6_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_RCP_6_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_GAIN_6_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_GAIN_6_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_6 - DCOC_TZA_STEP_GAIN_6 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_GAIN_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_GAIN_6_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_6_DCOC_TZA_STEP_GAIN_6_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_7 - DCOC TZA DAC Step 7 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_RCP_7_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_RCP_7_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_7 - DCOC_TZA_STEP_RCP_7 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_RCP_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_RCP_7_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_RCP_7_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_GAIN_7_MASK (0x1FFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_GAIN_7_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_7 - DCOC_TZA_STEP_GAIN_7 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_GAIN_7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_GAIN_7_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_7_DCOC_TZA_STEP_GAIN_7_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_8 - DCOC TZA DAC Step 5 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_RCP_8_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_RCP_8_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_8 - DCOC_TZA_STEP_RCP_8 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_RCP_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_RCP_8_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_RCP_8_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_GAIN_8_MASK (0x1FFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_GAIN_8_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_8 - DCOC_TZA_STEP_GAIN_8 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_GAIN_8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_GAIN_8_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_8_DCOC_TZA_STEP_GAIN_8_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_9 - DCOC TZA DAC Step 9 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_RCP_9_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_RCP_9_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_9 - DCOC_TZA_STEP_RCP_9 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_RCP_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_RCP_9_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_RCP_9_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_GAIN_9_MASK (0x3FFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_GAIN_9_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_9 - DCOC_TZA_STEP_GAIN_9 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_GAIN_9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_GAIN_9_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_9_DCOC_TZA_STEP_GAIN_9_MASK)
/*! @} */

/*! @name DCOC_TZA_STEP_10 - DCOC TZA DAC Step 10 */
/*! @{ */

#define XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_RCP_10_MASK (0x1FFFU)
#define XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_RCP_10_SHIFT (0U)
/*! DCOC_TZA_STEP_RCP_10 - DCOC_TZA_STEP_RCP_10 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_RCP_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_RCP_10_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_RCP_10_MASK)

#define XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_GAIN_10_MASK (0x3FFF0000U)
#define XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_GAIN_10_SHIFT (16U)
/*! DCOC_TZA_STEP_GAIN_10 - DCOC_TZA_STEP_GAIN_10 */
#define XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_GAIN_10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_GAIN_10_SHIFT)) & XCVR_RX_DIG_DCOC_TZA_STEP_10_DCOC_TZA_STEP_GAIN_10_MASK)
/*! @} */

/*! @name DCOC_CAL_ALPHA - DCOC Calibration Alpha */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_I_MASK (0x7FFU)
#define XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_I_SHIFT (0U)
/*! DCOC_CAL_ALPHA_I - DCOC Calibration I-channel ALPHA constant */
#define XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_I_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_I_MASK)

#define XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_Q_MASK (0x7FF0000U)
#define XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_Q_SHIFT (16U)
/*! DCOC_CAL_ALPHA_Q - DCOC_CAL_ALPHA_Q */
#define XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_Q_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_ALPHA_DCOC_CAL_ALPHA_Q_MASK)
/*! @} */

/*! @name DCOC_CAL_BETA_Q - DCOC Calibration Beta Q */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_BETA_Q_DCOC_CAL_BETA_Q_MASK (0x1FFFFU)
#define XCVR_RX_DIG_DCOC_CAL_BETA_Q_DCOC_CAL_BETA_Q_SHIFT (0U)
/*! DCOC_CAL_BETA_Q - DCOC_CAL_BETA_Q */
#define XCVR_RX_DIG_DCOC_CAL_BETA_Q_DCOC_CAL_BETA_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_BETA_Q_DCOC_CAL_BETA_Q_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_BETA_Q_DCOC_CAL_BETA_Q_MASK)
/*! @} */

/*! @name DCOC_CAL_BETA_I - DCOC Calibration Beta I */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_BETA_I_DCOC_CAL_BETA_I_MASK (0x1FFFFU)
#define XCVR_RX_DIG_DCOC_CAL_BETA_I_DCOC_CAL_BETA_I_SHIFT (0U)
/*! DCOC_CAL_BETA_I - DCOC_CAL_BETA_I */
#define XCVR_RX_DIG_DCOC_CAL_BETA_I_DCOC_CAL_BETA_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_BETA_I_DCOC_CAL_BETA_I_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_BETA_I_DCOC_CAL_BETA_I_MASK)
/*! @} */

/*! @name DCOC_CAL_GAMMA - DCOC Calibration Gamma */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_I_MASK (0xFFFFU)
#define XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_I_SHIFT (0U)
/*! DCOC_CAL_GAMMA_I - DCOC_CAL_GAMMA_I */
#define XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_I_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_I_MASK)

#define XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_Q_MASK (0xFFFF0000U)
#define XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_Q_SHIFT (16U)
/*! DCOC_CAL_GAMMA_Q - DCOC_CAL_GAMMA_Q */
#define XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_Q_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_GAMMA_DCOC_CAL_GAMMA_Q_MASK)
/*! @} */

/*! @name DCOC_CAL_IIR - DCOC Calibration IIR */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR1A_IDX_MASK (0x3U)
#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR1A_IDX_SHIFT (0U)
/*! DCOC_CAL_IIR1A_IDX - DCOC Calibration IIR 1A Index
 *  0b00..1/1
 *  0b01..1/4
 *  0b10..1/8
 *  0b11..1/16
 */
#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR1A_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR1A_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR1A_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR2A_IDX_MASK (0xCU)
#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR2A_IDX_SHIFT (2U)
/*! DCOC_CAL_IIR2A_IDX - DCOC Calibration IIR 2A Index
 *  0b00..1/1
 *  0b01..1/4
 *  0b10..1/8
 *  0b11..1/16
 */
#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR2A_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR2A_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR2A_IDX_MASK)

#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR3A_IDX_MASK (0x30U)
#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR3A_IDX_SHIFT (4U)
/*! DCOC_CAL_IIR3A_IDX - DCOC Calibration IIR 3A Index
 *  0b00..1/4
 *  0b01..1/8
 *  0b10..1/16
 *  0b11..1/32
 */
#define XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR3A_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR3A_IDX_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_IIR_DCOC_CAL_IIR3A_IDX_MASK)
/*! @} */

/*! @name DCOC_CAL - DCOC Calibration Result */
/*! @{ */

#define XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_I_MASK (0xFFFU)
#define XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_I_SHIFT (0U)
/*! DCOC_CAL_RES_I - DCOC Calibration Result - I Channel */
#define XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_I(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_I_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_I_MASK)

#define XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_Q_MASK (0xFFF0000U)
#define XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_Q_SHIFT (16U)
/*! DCOC_CAL_RES_Q - DCOC Calibration Result - Q Channel */
#define XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_Q(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_Q_SHIFT)) & XCVR_RX_DIG_DCOC_CAL_DCOC_CAL_RES_Q_MASK)
/*! @} */

/*! @name CCA_ED_LQI_CTRL_0 - RX_DIG CCA ED LQI Control Register 0 */
/*! @{ */

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CORR_THRESH_MASK (0xFFU)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CORR_THRESH_SHIFT (0U)
/*! LQI_CORR_THRESH - LQI Correlation Threshold */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CORR_THRESH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CORR_THRESH_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CORR_THRESH_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_CORR_CNTR_THRESH_MASK (0xFF00U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_CORR_CNTR_THRESH_SHIFT (8U)
/*! CORR_CNTR_THRESH - Correlation Count Threshold */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_CORR_CNTR_THRESH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_CORR_CNTR_THRESH_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_CORR_CNTR_THRESH_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CNTR_MASK (0xFF0000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CNTR_SHIFT (16U)
/*! LQI_CNTR - LQI Counter */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CNTR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CNTR_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_LQI_CNTR_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_SNR_ADJ_MASK (0x3F000000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_SNR_ADJ_SHIFT (24U)
/*! SNR_ADJ - SNR calculation adjustment */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_SNR_ADJ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_SNR_ADJ_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_0_SNR_ADJ_MASK)
/*! @} */

/*! @name CCA_ED_LQI_CTRL_1 - RX_DIG CCA ED LQI Control Register 1 */
/*! @{ */

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_DELAY_MASK (0x3FU)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_DELAY_SHIFT (0U)
/*! RSSI_NOISE_AVG_DELAY - RSSI Noise Averaging Delay */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_DELAY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_DELAY_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_DELAY_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_FACTOR_MASK (0x1C0U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_FACTOR_SHIFT (6U)
/*! RSSI_NOISE_AVG_FACTOR - RSSI Noise Averaging Factor
 *  0b000..1
 *  0b001..64
 *  0b010..70
 *  0b011..128
 *  0b100..139
 *  0b101..256
 *  0b110..277
 *  0b111..512
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_FACTOR_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_RSSI_NOISE_AVG_FACTOR_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_WEIGHT_MASK (0xE00U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_WEIGHT_SHIFT (9U)
/*! LQI_RSSI_WEIGHT - LQI RSSI Weight
 *  0b000..2.0
 *  0b001..2.125
 *  0b010..2.25
 *  0b011..2.375
 *  0b100..2.5
 *  0b101..2.625
 *  0b110..2.75
 *  0b111..2.875
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_WEIGHT_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_WEIGHT_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_SENS_MASK (0xF000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_SENS_SHIFT (12U)
/*! LQI_RSSI_SENS - LQI RSSI Sensitivity */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_SENS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_SENS_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_RSSI_SENS_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_DIS_MASK (0x10000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_DIS_SHIFT (16U)
/*! SNR_LQI_DIS - SNR LQI Disable
 *  0b0..Normal operation.
 *  0b1..The RX_DIG CCA/ED/LQI block ignores the AA match input which starts an LQI measurement.
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_DIS_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_DIS_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SEL_SNR_MODE_MASK (0x20000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SEL_SNR_MODE_SHIFT (17U)
/*! SEL_SNR_MODE - Select SNR Mode
 *  0b0..SNR estimate
 *  0b1..Mapped correlation magnitude
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SEL_SNR_MODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SEL_SNR_MODE_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SEL_SNR_MODE_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MEAS_TRANS_TO_IDLE_MASK (0x40000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MEAS_TRANS_TO_IDLE_SHIFT (18U)
/*! MEAS_TRANS_TO_IDLE - Measurement Transition to IDLE
 *  0b0..Module transitions to RSSI state
 *  0b1..Module transitions to IDLE state
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MEAS_TRANS_TO_IDLE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MEAS_TRANS_TO_IDLE_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MEAS_TRANS_TO_IDLE_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_CCA1_ED_EN_DIS_MASK (0x80000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_CCA1_ED_EN_DIS_SHIFT (19U)
/*! CCA1_ED_EN_DIS - CCA1_ED_EN Disable
 *  0b0..Normal operation
 *  0b1..CCA1_ED_EN input is disabled
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_CCA1_ED_EN_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_CCA1_ED_EN_DIS_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_CCA1_ED_EN_DIS_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_MEAS_COMPLETE_MASK (0x100000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_MEAS_COMPLETE_SHIFT (20U)
/*! MAN_MEAS_COMPLETE - Manual measurement complete
 *  0b0..Normal operation
 *  0b1..Manually asserts the measurement complete signal for the RX_DIG CCA/ED/LQI blocks. Intended to be used only for debug.
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_MEAS_COMPLETE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_MEAS_COMPLETE_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_MEAS_COMPLETE_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_AA_MATCH_MASK (0x200000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_AA_MATCH_SHIFT (21U)
/*! MAN_AA_MATCH - Manual AA Match
 *  0b0..Normal operation
 *  0b1..Manually asserts the AA match signal for the RX_DIG CCA/ED/LQI and AGC blocks. Intended to be used only for debug.
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_AA_MATCH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_AA_MATCH_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_MAN_AA_MATCH_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_WEIGHT_MASK (0xF000000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_WEIGHT_SHIFT (24U)
/*! SNR_LQI_WEIGHT - SNR LQI Weight
 *  0b0000..0.0
 *  0b0001..1.0
 *  0b0010..1.125
 *  0b0011..1.25
 *  0b0100..1.375
 *  0b0101..1.5
 *  0b0110..1.625
 *  0b0111..1.75
 *  0b1000..1.875
 *  0b1001..2.0
 *  0b1010..2.125
 *  0b1011..2.25
 *  0b1100..2.375
 *  0b1101..2.5
 *  0b1110..2.625
 *  0b1111..2.75
 */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_WEIGHT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_WEIGHT_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_SNR_LQI_WEIGHT_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_BIAS_MASK (0xF0000000U)
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_BIAS_SHIFT (28U)
/*! LQI_BIAS - LQI Bias. */
#define XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_BIAS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_BIAS_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_CTRL_1_LQI_BIAS_MASK)
/*! @} */

/*! @name CCA_ED_LQI_STAT_0 - RX_DIG CCA ED LQI Status Register 0 */
/*! @{ */

#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_LQI_OUT_MASK (0xFFU)
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_LQI_OUT_SHIFT (0U)
/*! LQI_OUT - LQI output */
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_LQI_OUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_STAT_0_LQI_OUT_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_STAT_0_LQI_OUT_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_ED_OUT_MASK (0xFF00U)
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_ED_OUT_SHIFT (8U)
/*! ED_OUT - ED output */
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_ED_OUT(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_STAT_0_ED_OUT_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_STAT_0_ED_OUT_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_SNR_OUT_MASK (0xFF0000U)
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_SNR_OUT_SHIFT (16U)
/*! SNR_OUT - SNR output */
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_SNR_OUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_STAT_0_SNR_OUT_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_STAT_0_SNR_OUT_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_CCA1_STATE_MASK (0x1000000U)
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_CCA1_STATE_SHIFT (24U)
/*! CCA1_STATE - CCA1 State */
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_CCA1_STATE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_STAT_0_CCA1_STATE_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_STAT_0_CCA1_STATE_MASK)

#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_MEAS_COMPLETE_MASK (0x2000000U)
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_MEAS_COMPLETE_SHIFT (25U)
/*! MEAS_COMPLETE - Measurement Complete */
#define XCVR_RX_DIG_CCA_ED_LQI_STAT_0_MEAS_COMPLETE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_CCA_ED_LQI_STAT_0_MEAS_COMPLETE_SHIFT)) & XCVR_RX_DIG_CCA_ED_LQI_STAT_0_MEAS_COMPLETE_MASK)
/*! @} */

/*! @name RX_CHF_COEF_0 - Receive Channel Filter Coefficient 0 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_0_RX_CH_FILT_H0_MASK (0x3FU)
#define XCVR_RX_DIG_RX_CHF_COEF_0_RX_CH_FILT_H0_SHIFT (0U)
/*! RX_CH_FILT_H0 - RX Channel Filter Coefficient 0 */
#define XCVR_RX_DIG_RX_CHF_COEF_0_RX_CH_FILT_H0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_0_RX_CH_FILT_H0_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_0_RX_CH_FILT_H0_MASK)
/*! @} */

/*! @name RX_CHF_COEF_1 - Receive Channel Filter Coefficient 1 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_1_RX_CH_FILT_H1_MASK (0x3FU)
#define XCVR_RX_DIG_RX_CHF_COEF_1_RX_CH_FILT_H1_SHIFT (0U)
/*! RX_CH_FILT_H1 - RX Channel Filter Coefficient 1 */
#define XCVR_RX_DIG_RX_CHF_COEF_1_RX_CH_FILT_H1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_1_RX_CH_FILT_H1_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_1_RX_CH_FILT_H1_MASK)
/*! @} */

/*! @name RX_CHF_COEF_2 - Receive Channel Filter Coefficient 2 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_2_RX_CH_FILT_H2_MASK (0x7FU)
#define XCVR_RX_DIG_RX_CHF_COEF_2_RX_CH_FILT_H2_SHIFT (0U)
/*! RX_CH_FILT_H2 - RX Channel Filter Coefficient 2 */
#define XCVR_RX_DIG_RX_CHF_COEF_2_RX_CH_FILT_H2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_2_RX_CH_FILT_H2_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_2_RX_CH_FILT_H2_MASK)
/*! @} */

/*! @name RX_CHF_COEF_3 - Receive Channel Filter Coefficient 3 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_3_RX_CH_FILT_H3_MASK (0x7FU)
#define XCVR_RX_DIG_RX_CHF_COEF_3_RX_CH_FILT_H3_SHIFT (0U)
/*! RX_CH_FILT_H3 - RX Channel Filter Coefficient 3 */
#define XCVR_RX_DIG_RX_CHF_COEF_3_RX_CH_FILT_H3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_3_RX_CH_FILT_H3_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_3_RX_CH_FILT_H3_MASK)
/*! @} */

/*! @name RX_CHF_COEF_4 - Receive Channel Filter Coefficient 4 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_4_RX_CH_FILT_H4_MASK (0x7FU)
#define XCVR_RX_DIG_RX_CHF_COEF_4_RX_CH_FILT_H4_SHIFT (0U)
/*! RX_CH_FILT_H4 - RX Channel Filter Coefficient 4 */
#define XCVR_RX_DIG_RX_CHF_COEF_4_RX_CH_FILT_H4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_4_RX_CH_FILT_H4_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_4_RX_CH_FILT_H4_MASK)
/*! @} */

/*! @name RX_CHF_COEF_5 - Receive Channel Filter Coefficient 5 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_5_RX_CH_FILT_H5_MASK (0x7FU)
#define XCVR_RX_DIG_RX_CHF_COEF_5_RX_CH_FILT_H5_SHIFT (0U)
/*! RX_CH_FILT_H5 - RX Channel Filter Coefficient 5 */
#define XCVR_RX_DIG_RX_CHF_COEF_5_RX_CH_FILT_H5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_5_RX_CH_FILT_H5_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_5_RX_CH_FILT_H5_MASK)
/*! @} */

/*! @name RX_CHF_COEF_6 - Receive Channel Filter Coefficient 6 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_6_RX_CH_FILT_H6_MASK (0xFFU)
#define XCVR_RX_DIG_RX_CHF_COEF_6_RX_CH_FILT_H6_SHIFT (0U)
/*! RX_CH_FILT_H6 - RX Channel Filter Coefficient 6 */
#define XCVR_RX_DIG_RX_CHF_COEF_6_RX_CH_FILT_H6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_6_RX_CH_FILT_H6_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_6_RX_CH_FILT_H6_MASK)
/*! @} */

/*! @name RX_CHF_COEF_7 - Receive Channel Filter Coefficient 7 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_7_RX_CH_FILT_H7_MASK (0xFFU)
#define XCVR_RX_DIG_RX_CHF_COEF_7_RX_CH_FILT_H7_SHIFT (0U)
/*! RX_CH_FILT_H7 - RX Channel Filter Coefficient 7 */
#define XCVR_RX_DIG_RX_CHF_COEF_7_RX_CH_FILT_H7(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_7_RX_CH_FILT_H7_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_7_RX_CH_FILT_H7_MASK)
/*! @} */

/*! @name RX_CHF_COEF_8 - Receive Channel Filter Coefficient 8 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_8_RX_CH_FILT_H8_MASK (0x1FFU)
#define XCVR_RX_DIG_RX_CHF_COEF_8_RX_CH_FILT_H8_SHIFT (0U)
/*! RX_CH_FILT_H8 - RX Channel Filter Coefficient 8 */
#define XCVR_RX_DIG_RX_CHF_COEF_8_RX_CH_FILT_H8(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_8_RX_CH_FILT_H8_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_8_RX_CH_FILT_H8_MASK)
/*! @} */

/*! @name RX_CHF_COEF_9 - Receive Channel Filter Coefficient 9 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_9_RX_CH_FILT_H9_MASK (0x1FFU)
#define XCVR_RX_DIG_RX_CHF_COEF_9_RX_CH_FILT_H9_SHIFT (0U)
/*! RX_CH_FILT_H9 - RX Channel Filter Coefficient 9 */
#define XCVR_RX_DIG_RX_CHF_COEF_9_RX_CH_FILT_H9(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_9_RX_CH_FILT_H9_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_9_RX_CH_FILT_H9_MASK)
/*! @} */

/*! @name RX_CHF_COEF_10 - Receive Channel Filter Coefficient 10 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_10_RX_CH_FILT_H10_MASK (0x3FFU)
#define XCVR_RX_DIG_RX_CHF_COEF_10_RX_CH_FILT_H10_SHIFT (0U)
/*! RX_CH_FILT_H10 - RX Channel Filter Coefficient 10 */
#define XCVR_RX_DIG_RX_CHF_COEF_10_RX_CH_FILT_H10(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_10_RX_CH_FILT_H10_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_10_RX_CH_FILT_H10_MASK)
/*! @} */

/*! @name RX_CHF_COEF_11 - Receive Channel Filter Coefficient 11 */
/*! @{ */

#define XCVR_RX_DIG_RX_CHF_COEF_11_RX_CH_FILT_H11_MASK (0x3FFU)
#define XCVR_RX_DIG_RX_CHF_COEF_11_RX_CH_FILT_H11_SHIFT (0U)
/*! RX_CH_FILT_H11 - RX Channel Filter Coefficient 11 */
#define XCVR_RX_DIG_RX_CHF_COEF_11_RX_CH_FILT_H11(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_CHF_COEF_11_RX_CH_FILT_H11_SHIFT)) & XCVR_RX_DIG_RX_CHF_COEF_11_RX_CH_FILT_H11_MASK)
/*! @} */

/*! @name AGC_MAN_AGC_IDX - AGC Manual AGC Index */
/*! @{ */

#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_MASK (0x1F0000U)
#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_SHIFT (16U)
/*! AGC_MAN_IDX - AGC Manual Index */
#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_SHIFT)) & XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_MASK)

#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_EN_MASK (0x1000000U)
#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_EN_SHIFT (24U)
/*! AGC_MAN_IDX_EN - AGC Manual Index Enable */
#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_EN_SHIFT)) & XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_MAN_IDX_EN_MASK)

#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_DCOC_START_PT_MASK (0x2000000U)
#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_DCOC_START_PT_SHIFT (25U)
/*! AGC_DCOC_START_PT - AGC DCOC Start Point */
#define XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_DCOC_START_PT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_DCOC_START_PT_SHIFT)) & XCVR_RX_DIG_AGC_MAN_AGC_IDX_AGC_DCOC_START_PT_MASK)
/*! @} */

/*! @name DC_RESID_CTRL - DC Residual Control */
/*! @{ */

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_MASK (0x7FU)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_SHIFT (0U)
/*! DC_RESID_NWIN - DC Residual NWIN */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_NWIN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_MASK (0xF00U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_SHIFT (8U)
/*! DC_RESID_ITER_FREEZE - DC Residual Iteration Freeze */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ITER_FREEZE_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_MASK (0x7000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_SHIFT (12U)
/*! DC_RESID_ALPHA - DC Residual Alpha */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_ALPHA_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_MASK (0x70000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_SHIFT (16U)
/*! DC_RESID_DLY - DC Residual Delay */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_DLY_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_MASK (0x100000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_SHIFT (20U)
/*! DC_RESID_EXT_DC_EN - DC Residual External DC Enable
 *  0b0..External DC disable. The DC Residual activates at a delay specified by DC_RESID_DLY after an AGC gain
 *       change pulse. The DC Residual is initialized with a DC offset of 0.
 *  0b1..External DC enable. The DC residual activates after the DCOC's tracking hold timer expires. The DC
 *       Residual is initialized with the DC estimate from the DCOC tracking estimator.
 */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_EXT_DC_EN_MASK)

#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_MASK (0x1F000000U)
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_SHIFT (24U)
/*! DC_RESID_MIN_AGC_IDX - DC Residual Minimum AGC Table Index */
#define XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_SHIFT)) & XCVR_RX_DIG_DC_RESID_CTRL_DC_RESID_MIN_AGC_IDX_MASK)
/*! @} */

/*! @name DC_RESID_EST - DC Residual Estimate */
/*! @{ */

#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_MASK (0x1FFFU)
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_SHIFT (0U)
/*! DC_RESID_OFFSET_I - DC Residual Offset I */
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_SHIFT)) & XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_I_MASK)

#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_MASK (0x1FFF0000U)
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_SHIFT (16U)
/*! DC_RESID_OFFSET_Q - DC Residual Offset Q */
#define XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_SHIFT)) & XCVR_RX_DIG_DC_RESID_EST_DC_RESID_OFFSET_Q_MASK)
/*! @} */

/*! @name RX_RCCAL_CTRL0 - RX RC Calibration Control0 */
/*! @{ */

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_OFFSET_MASK (0xFU)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_OFFSET_SHIFT (0U)
/*! BBA_RCCAL_OFFSET - BBA RC Calibration value offset */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_OFFSET_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_OFFSET_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_MANUAL_MASK (0x1F0U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_MANUAL_SHIFT (4U)
/*! BBA_RCCAL_MANUAL - BBA RC Calibration manual value */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_MANUAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_MANUAL_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_DIS_MASK (0x200U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_DIS_SHIFT (9U)
/*! BBA_RCCAL_DIS - BBA RC Calibration Disable
 *  0b0..BBA RC Calibration is enabled
 *  0b1..BBA RC Calibration is disabled
 */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_DIS_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_BBA_RCCAL_DIS_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_SMP_DLY_MASK (0x3000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_SMP_DLY_SHIFT (12U)
/*! RCCAL_SMP_DLY - RC Calibration Sample Delay
 *  0b00..The comp_out signal is sampled 0 clk cycle after sample signal is deasserted
 *  0b01..The comp_out signal is sampled 1 clk cycle after sample signal is deasserted
 *  0b10..The comp_out signal is sampled 2 clk cycle after sample signal is deasserted
 *  0b11..The comp_out signal is sampled 3 clk cycle after sample signal is deasserted
 */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_SMP_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_SMP_DLY_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_SMP_DLY_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_COMP_INV_MASK (0x8000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_COMP_INV_SHIFT (15U)
/*! RCCAL_COMP_INV - RC Calibration comp_out Invert
 *  0b0..The comp_out signal polarity is NOT inverted
 *  0b1..The comp_out signal polarity is inverted
 */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_COMP_INV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_COMP_INV_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_RCCAL_COMP_INV_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_OFFSET_MASK (0xF0000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_OFFSET_SHIFT (16U)
/*! TZA_RCCAL_OFFSET - TZA RC Calibration value offset */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_OFFSET_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_OFFSET_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_MANUAL_MASK (0x1F00000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_MANUAL_SHIFT (20U)
/*! TZA_RCCAL_MANUAL - TZA RC Calibration manual value */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_MANUAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_MANUAL_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_DIS_MASK (0x2000000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_DIS_SHIFT (25U)
/*! TZA_RCCAL_DIS - TZA RC Calibration Disable
 *  0b0..TZA RC Calibration is enabled
 *  0b1..TZA RC Calibration is disabled
 */
#define XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_DIS_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL0_TZA_RCCAL_DIS_MASK)
/*! @} */

/*! @name RX_RCCAL_CTRL1 - RX RC Calibration Control1 */
/*! @{ */

#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_OFFSET_MASK (0xFU)
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_OFFSET_SHIFT (0U)
/*! ADC_RCCAL_OFFSET - ADC RC Calibration value offset */
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_OFFSET_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_OFFSET_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_MANUAL_MASK (0x1F0U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_MANUAL_SHIFT (4U)
/*! ADC_RCCAL_MANUAL - ADC RC Calibration manual value */
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_MANUAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_MANUAL_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_DIS_MASK (0x200U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_DIS_SHIFT (9U)
/*! ADC_RCCAL_DIS - ADC RC Calibration Disable
 *  0b0..ADC RC Calibration is enabled
 *  0b1..ADC RC Calibration is disabled
 */
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_DIS_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL1_ADC_RCCAL_DIS_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_OFFSET_MASK (0xF0000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_OFFSET_SHIFT (16U)
/*! BBA2_RCCAL_OFFSET - BBA2 RC Calibration value offset */
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_OFFSET_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_OFFSET_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_MANUAL_MASK (0x1F00000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_MANUAL_SHIFT (20U)
/*! BBA2_RCCAL_MANUAL - BBA2 RC Calibration manual value */
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_MANUAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_MANUAL_MASK)

#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_DIS_MASK (0x2000000U)
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_DIS_SHIFT (25U)
/*! BBA2_RCCAL_DIS - BBA2 RC Calibration Disable
 *  0b0..BBA2 RC Calibration is enabled
 *  0b1..BBA2 RC Calibration is disabled
 */
#define XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_DIS_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_CTRL1_BBA2_RCCAL_DIS_MASK)
/*! @} */

/*! @name RX_RCCAL_STAT - RX RC Calibration Status */
/*! @{ */

#define XCVR_RX_DIG_RX_RCCAL_STAT_RCCAL_CODE_MASK (0x1FU)
#define XCVR_RX_DIG_RX_RCCAL_STAT_RCCAL_CODE_SHIFT (0U)
/*! RCCAL_CODE - RC Calibration code */
#define XCVR_RX_DIG_RX_RCCAL_STAT_RCCAL_CODE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_STAT_RCCAL_CODE_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_STAT_RCCAL_CODE_MASK)

#define XCVR_RX_DIG_RX_RCCAL_STAT_ADC_RCCAL_MASK (0x3E0U)
#define XCVR_RX_DIG_RX_RCCAL_STAT_ADC_RCCAL_SHIFT (5U)
/*! ADC_RCCAL - ADC RC Calibration */
#define XCVR_RX_DIG_RX_RCCAL_STAT_ADC_RCCAL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_STAT_ADC_RCCAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_STAT_ADC_RCCAL_MASK)

#define XCVR_RX_DIG_RX_RCCAL_STAT_BBA2_RCCAL_MASK (0x7C00U)
#define XCVR_RX_DIG_RX_RCCAL_STAT_BBA2_RCCAL_SHIFT (10U)
/*! BBA2_RCCAL - BBA2 RC Calibration */
#define XCVR_RX_DIG_RX_RCCAL_STAT_BBA2_RCCAL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_STAT_BBA2_RCCAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_STAT_BBA2_RCCAL_MASK)

#define XCVR_RX_DIG_RX_RCCAL_STAT_BBA_RCCAL_MASK (0x1F0000U)
#define XCVR_RX_DIG_RX_RCCAL_STAT_BBA_RCCAL_SHIFT (16U)
/*! BBA_RCCAL - BBA RC Calibration */
#define XCVR_RX_DIG_RX_RCCAL_STAT_BBA_RCCAL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_STAT_BBA_RCCAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_STAT_BBA_RCCAL_MASK)

#define XCVR_RX_DIG_RX_RCCAL_STAT_TZA_RCCAL_MASK (0x3E00000U)
#define XCVR_RX_DIG_RX_RCCAL_STAT_TZA_RCCAL_SHIFT (21U)
/*! TZA_RCCAL - TZA RC Calibration */
#define XCVR_RX_DIG_RX_RCCAL_STAT_TZA_RCCAL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RX_RCCAL_STAT_TZA_RCCAL_SHIFT)) & XCVR_RX_DIG_RX_RCCAL_STAT_TZA_RCCAL_MASK)
/*! @} */

/*! @name AUXPLL_FCAL_CTRL - Aux PLL Frequency Calibration Control */
/*! @{ */

#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_MANUAL_MASK (0x7FU)
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_MANUAL_SHIFT (0U)
/*! DAC_CAL_ADJUST_MANUAL - Aux PLL Frequency DAC Calibration Adjust Manual value */
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_MANUAL_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_MANUAL_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_AUXPLL_DAC_CAL_ADJUST_DIS_MASK (0x80U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_AUXPLL_DAC_CAL_ADJUST_DIS_SHIFT (7U)
/*! AUXPLL_DAC_CAL_ADJUST_DIS - Aux PLL Frequency Calibration Disable
 *  0b0..Calibration is enabled
 *  0b1..Calibration is disabled
 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_AUXPLL_DAC_CAL_ADJUST_DIS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CTRL_AUXPLL_DAC_CAL_ADJUST_DIS_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CTRL_AUXPLL_DAC_CAL_ADJUST_DIS_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_RUN_CNT_MASK (0x100U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_RUN_CNT_SHIFT (8U)
/*! FCAL_RUN_CNT - Aux PLL Frequency Calibration Run Count
 *  0b0..Run count is 256 clock cycles
 *  0b1..Run count is 512 clock cycles
 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_RUN_CNT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_RUN_CNT_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_RUN_CNT_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_COMP_INV_MASK (0x200U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_COMP_INV_SHIFT (9U)
/*! FCAL_COMP_INV - Aux PLL Frequency Calibration Comparison Invert
 *  0b0..(Default) The comparison associated with the count is not inverted.
 *  0b1..The comparison associated with the count is inverted
 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_COMP_INV(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_COMP_INV_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_COMP_INV_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_SMP_DLY_MASK (0xC00U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_SMP_DLY_SHIFT (10U)
/*! FCAL_SMP_DLY - Aux PLL Frequency Calibration Sample Delay
 *  0b00..The count signal is sampled 1 clk cycle after fcal_run signal is deasserted
 *  0b01..The count signal is sampled 2 clk cycle after fcal_run signal is deasserted
 *  0b10..The count signal is sampled 3 clk cycle after fcal_run signal is deasserted
 *  0b11..The count signal is sampled 4 clk cycle after fcal_run signal is deasserted
 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_SMP_DLY(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_SMP_DLY_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CTRL_FCAL_SMP_DLY_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_MASK (0x7F0000U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_SHIFT (16U)
/*! DAC_CAL_ADJUST - Aux PLL DAC Calibration Adjust value */
#define XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CTRL_DAC_CAL_ADJUST_MASK)
/*! @} */

/*! @name AUXPLL_FCAL_CNT6 - Aux PLL Frequency Calibration Count 6 */
/*! @{ */

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_COUNT_6_MASK (0x3FFU)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_COUNT_6_SHIFT (0U)
/*! FCAL_COUNT_6 - Aux PLL Frequency Calibration Count 6 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_COUNT_6(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_COUNT_6_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_COUNT_6_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_BESTDIFF_MASK (0x3FF0000U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_BESTDIFF_SHIFT (16U)
/*! FCAL_BESTDIFF - Aux PLL Frequency Calibration Best Difference */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_BESTDIFF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_BESTDIFF_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT6_FCAL_BESTDIFF_MASK)
/*! @} */

/*! @name AUXPLL_FCAL_CNT5_4 - Aux PLL Frequency Calibration Count 5 and 4 */
/*! @{ */

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_4_MASK (0x3FFU)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_4_SHIFT (0U)
/*! FCAL_COUNT_4 - Aux PLL Frequency Calibration Count 4 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_4(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_4_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_4_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_5_MASK (0x3FF0000U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_5_SHIFT (16U)
/*! FCAL_COUNT_5 - Aux PLL Frequency Calibration Count 5 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_5(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_5_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT5_4_FCAL_COUNT_5_MASK)
/*! @} */

/*! @name AUXPLL_FCAL_CNT3_2 - Aux PLL Frequency Calibration Count 3 and 2 */
/*! @{ */

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_2_MASK (0x3FFU)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_2_SHIFT (0U)
/*! FCAL_COUNT_2 - Aux PLL Frequency Calibration Count 2 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_2_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_2_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_3_MASK (0x3FF0000U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_3_SHIFT (16U)
/*! FCAL_COUNT_3 - Aux PLL Frequency Calibration Count 3 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_3(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_3_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT3_2_FCAL_COUNT_3_MASK)
/*! @} */

/*! @name AUXPLL_FCAL_CNT1_0 - Aux PLL Frequency Calibration Count 1 and 0 */
/*! @{ */

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_0_MASK (0x3FFU)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_0_SHIFT (0U)
/*! FCAL_COUNT_0 - Frequency Calibration Count 0 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_0_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_0_MASK)

#define XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_1_MASK (0x3FF0000U)
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_1_SHIFT (16U)
/*! FCAL_COUNT_1 - Frequency Calibration Count 1 */
#define XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_1_SHIFT)) & XCVR_RX_DIG_AUXPLL_FCAL_CNT1_0_FCAL_COUNT_1_MASK)
/*! @} */

/*! @name RXDIG_DFT - RXDIG DFT */
/*! @{ */

#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_FREQ_MASK (0x7U)
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_FREQ_SHIFT (0U)
/*! DFT_TONE_FREQ - DFT Tone Generator Frequency
 *  0b000..1/64 of the ref osc frequency (500kHz for 32MHz ref osc)
 *  0b001..1/128 of the ref osc frequency (250kHz for 32MHz ref osc)
 *  0b010..1/256 of the ref osc frequency (125kHz for 32MHz ref osc)
 *  0b011..1/512 of the ref osc frequency (62.5kHz for 32MHz ref osc)
 *  0b100..1/1024 of the ref osc frequency (31.25kHz for 32MHz ref osc)
 */
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_FREQ(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_FREQ_SHIFT)) & XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_FREQ_MASK)

#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_SCALE_MASK (0x8U)
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_SCALE_SHIFT (3U)
/*! DFT_TONE_SCALE - DFT Tone Generator Scale
 *  0b0..The DFT tone generator uses 3/4 of the DC offset correction DAC range.
 *  0b1..The DFT tone generator uses 1/2 of the DC offset correction DAC range.
 */
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_SCALE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_SCALE_SHIFT)) & XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_SCALE_MASK)

#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_TZA_EN_MASK (0x10U)
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_TZA_EN_SHIFT (4U)
/*! DFT_TONE_TZA_EN - DFT Tone Generator TZA Enable
 *  0b0..The DCOC controls the TZA DC offset correction DACs
 *  0b1..A tone is generated using the TZA DC offset correction DACs.
 */
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_TZA_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_TZA_EN_SHIFT)) & XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_TZA_EN_MASK)

#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_BBA_EN_MASK (0x20U)
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_BBA_EN_SHIFT (5U)
/*! DFT_TONE_BBA_EN - DFT Tone Generator BBA Enable
 *  0b0..The DCOC controls the BBA DC offset correction DACs
 *  0b1..A tone is generated using the BBA DC offset correction DACs.
 */
#define XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_BBA_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_BBA_EN_SHIFT)) & XCVR_RX_DIG_RXDIG_DFT_DFT_TONE_BBA_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_RX_DIG_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_RX_DIG_Peripheral_Access_Layer */


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


#endif  /* XCVR_RX_DIG_H_ */

