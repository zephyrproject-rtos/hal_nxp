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
**         CMSIS Peripheral Access Layer for XCVR_TX_DIG
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
 * @file XCVR_TX_DIG.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_TX_DIG
 *
 * CMSIS Peripheral Access Layer for XCVR_TX_DIG
 */

#if !defined(XCVR_TX_DIG_H_)
#define XCVR_TX_DIG_H_                           /**< Symbol preventing repeated inclusion */

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
   -- XCVR_TX_DIG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_TX_DIG_Peripheral_Access_Layer XCVR_TX_DIG Peripheral Access Layer
 * @{
 */

/** XCVR_TX_DIG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< TX Digital Control, offset: 0x0 */
  __IO uint32_t DATA_PADDING;                      /**< TX Data Padding, offset: 0x4 */
  __IO uint32_t GFSK_CTRL;                         /**< TX GFSK Modulator Control, offset: 0x8 */
  __IO uint32_t GFSK_COEFF2;                       /**< TX GFSK Filter Coefficients 2, offset: 0xC */
  __IO uint32_t GFSK_COEFF1;                       /**< TX GFSK Filter Coefficients 1, offset: 0x10 */
  __IO uint32_t FSK_SCALE;                         /**< TX FSK Modulation Levels, offset: 0x14 */
  __IO uint32_t DFT_PATTERN;                       /**< TX DFT Modulation Pattern, offset: 0x18 */
  __IO uint32_t RF_DFT_BIST_1;                     /**< TX DFT Control 1, offset: 0x1C */
  __IO uint32_t RF_DFT_BIST_2;                     /**< TX DFT Control 2, offset: 0x20 */
} XCVR_TX_DIG_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_TX_DIG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_TX_DIG_Register_Masks XCVR_TX_DIG Register Masks
 * @{
 */

/*! @name CTRL - TX Digital Control */
/*! @{ */

#define XCVR_TX_DIG_CTRL_RADIO_DFT_MODE_MASK     (0xFU)
#define XCVR_TX_DIG_CTRL_RADIO_DFT_MODE_SHIFT    (0U)
/*! RADIO_DFT_MODE - Radio DFT Modes
 *  0b0000..Normal Radio Operation, DFT not engaged.
 *  0b0001..Carrier Frequency Only
 *  0b0010..Pattern Register GFSK
 *  0b0011..LFSR GFSK
 *  0b0100..Pattern Register FSK
 *  0b0101..LFSR FSK
 *  0b0110..Pattern Register O-QPSK
 *  0b0111..LFSR O-QPSK
 *  0b1000..LFSR 802.15.4 Symbols
 *  0b1001..PLL Modulation from RAM
 *  0b1010..PLL Coarse Tune BIST
 *  0b1011..PLL Frequency Synthesizer BIST
 *  0b1100..High Port DAC BIST
 *  0b1101..VCO Frequency Meter
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define XCVR_TX_DIG_CTRL_RADIO_DFT_MODE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_RADIO_DFT_MODE_SHIFT)) & XCVR_TX_DIG_CTRL_RADIO_DFT_MODE_MASK)

#define XCVR_TX_DIG_CTRL_LFSR_LENGTH_MASK        (0x70U)
#define XCVR_TX_DIG_CTRL_LFSR_LENGTH_SHIFT       (4U)
/*! LFSR_LENGTH - LFSR Length
 *  0b000..LFSR 9, tap mask 100010000
 *  0b001..LFSR 10, tap mask 1001000000
 *  0b010..LFSR 11, tap mask 11101000000
 *  0b011..LFSR 13, tap mask 1101100000000
 *  0b100..LFSR 15, tap mask 111010000000000
 *  0b101..LFSR 17, tap mask 11110000000000000
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define XCVR_TX_DIG_CTRL_LFSR_LENGTH(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_LFSR_LENGTH_SHIFT)) & XCVR_TX_DIG_CTRL_LFSR_LENGTH_MASK)

#define XCVR_TX_DIG_CTRL_LFSR_EN_MASK            (0x80U)
#define XCVR_TX_DIG_CTRL_LFSR_EN_SHIFT           (7U)
/*! LFSR_EN - LFSR Enable */
#define XCVR_TX_DIG_CTRL_LFSR_EN(x)              (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_LFSR_EN_SHIFT)) & XCVR_TX_DIG_CTRL_LFSR_EN_MASK)

#define XCVR_TX_DIG_CTRL_DFT_CLK_SEL_MASK        (0x700U)
#define XCVR_TX_DIG_CTRL_DFT_CLK_SEL_SHIFT       (8U)
/*! DFT_CLK_SEL - DFT Clock Selection
 *  0b000..62.5 kHz
 *  0b001..125 kHz
 *  0b010..250 kHz
 *  0b011..500 kHz
 *  0b100..1 MHz
 *  0b101..2 MHz
 *  0b110..4 MHz
 *  0b111..RF OSC Clock
 */
#define XCVR_TX_DIG_CTRL_DFT_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_DFT_CLK_SEL_SHIFT)) & XCVR_TX_DIG_CTRL_DFT_CLK_SEL_MASK)

#define XCVR_TX_DIG_CTRL_TX_DFT_EN_MASK          (0x800U)
#define XCVR_TX_DIG_CTRL_TX_DFT_EN_SHIFT         (11U)
/*! TX_DFT_EN - DFT Modulation Enable */
#define XCVR_TX_DIG_CTRL_TX_DFT_EN(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_TX_DFT_EN_SHIFT)) & XCVR_TX_DIG_CTRL_TX_DFT_EN_MASK)

#define XCVR_TX_DIG_CTRL_SOC_TEST_SEL_MASK       (0x3000U)
#define XCVR_TX_DIG_CTRL_SOC_TEST_SEL_SHIFT      (12U)
/*! SOC_TEST_SEL - Radio Clock Selector for SoC RF Clock Tests
 *  0b00..No Clock Selected
 *  0b01..PLL Sigma Delta Clock, divided by 2
 *  0b10..Auxiliary PLL Clock, divided by 2
 *  0b11..RF Ref Osc clock, divided by 2
 */
#define XCVR_TX_DIG_CTRL_SOC_TEST_SEL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_SOC_TEST_SEL_SHIFT)) & XCVR_TX_DIG_CTRL_SOC_TEST_SEL_MASK)

#define XCVR_TX_DIG_CTRL_TX_CAPTURE_POL_MASK     (0x10000U)
#define XCVR_TX_DIG_CTRL_TX_CAPTURE_POL_SHIFT    (16U)
/*! TX_CAPTURE_POL - Polarity of the Input Data for the Transmitter */
#define XCVR_TX_DIG_CTRL_TX_CAPTURE_POL(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_TX_CAPTURE_POL_SHIFT)) & XCVR_TX_DIG_CTRL_TX_CAPTURE_POL_MASK)

#define XCVR_TX_DIG_CTRL_FREQ_WORD_ADJ_MASK      (0xFFC00000U)
#define XCVR_TX_DIG_CTRL_FREQ_WORD_ADJ_SHIFT     (22U)
/*! FREQ_WORD_ADJ - Frequency Word Adjustment */
#define XCVR_TX_DIG_CTRL_FREQ_WORD_ADJ(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_CTRL_FREQ_WORD_ADJ_SHIFT)) & XCVR_TX_DIG_CTRL_FREQ_WORD_ADJ_MASK)
/*! @} */

/*! @name DATA_PADDING - TX Data Padding */
/*! @{ */

#define XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_0_MASK (0xFFU)
#define XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_0_SHIFT (0U)
/*! DATA_PADDING_PAT_0 - Data Padding Pattern 0 */
#define XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_0_SHIFT)) & XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_0_MASK)

#define XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_1_MASK (0xFF00U)
#define XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_1_SHIFT (8U)
/*! DATA_PADDING_PAT_1 - Data Padding Pattern 1 */
#define XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_1_SHIFT)) & XCVR_TX_DIG_DATA_PADDING_DATA_PADDING_PAT_1_MASK)

#define XCVR_TX_DIG_DATA_PADDING_DFT_LFSR_OUT_MASK (0x7FFF0000U)
#define XCVR_TX_DIG_DATA_PADDING_DFT_LFSR_OUT_SHIFT (16U)
/*! DFT_LFSR_OUT - LFSR Output */
#define XCVR_TX_DIG_DATA_PADDING_DFT_LFSR_OUT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_DATA_PADDING_DFT_LFSR_OUT_SHIFT)) & XCVR_TX_DIG_DATA_PADDING_DFT_LFSR_OUT_MASK)

#define XCVR_TX_DIG_DATA_PADDING_LRM_MASK        (0x80000000U)
#define XCVR_TX_DIG_DATA_PADDING_LRM_SHIFT       (31U)
/*! LRM - LFSR Reset Mask */
#define XCVR_TX_DIG_DATA_PADDING_LRM(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_DATA_PADDING_LRM_SHIFT)) & XCVR_TX_DIG_DATA_PADDING_LRM_MASK)
/*! @} */

/*! @name GFSK_CTRL - TX GFSK Modulator Control */
/*! @{ */

#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MULTIPLY_TABLE_MANUAL_MASK (0xFFFFU)
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MULTIPLY_TABLE_MANUAL_SHIFT (0U)
/*! GFSK_MULTIPLY_TABLE_MANUAL - Manual GFSK Multiply Lookup Table Value */
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MULTIPLY_TABLE_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_GFSK_MULTIPLY_TABLE_MANUAL_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_GFSK_MULTIPLY_TABLE_MANUAL_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MI_MASK       (0x30000U)
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MI_SHIFT      (16U)
/*! GFSK_MI - GFSK Modulation Index
 *  0b00..0.32
 *  0b01..0.50
 *  0b10..0.70
 *  0b11..1.00
 */
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MI(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_GFSK_MI_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_GFSK_MI_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MLD_MASK      (0x100000U)
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MLD_SHIFT     (20U)
/*! GFSK_MLD - Disable GFSK Multiply Lookup Table */
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MLD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_GFSK_MLD_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_GFSK_MLD_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_GFSK_FLD_MASK      (0x200000U)
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_FLD_SHIFT     (21U)
/*! GFSK_FLD - Disable GFSK Filter Lookup Table */
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_FLD(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_GFSK_FLD_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_GFSK_FLD_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MOD_INDEX_SCALING_MASK (0x7000000U)
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MOD_INDEX_SCALING_SHIFT (24U)
/*! GFSK_MOD_INDEX_SCALING - GFSK Modulation Index Scaling Factor
 *  0b000..1
 *  0b001..1 + 1/32
 *  0b010..1 + 1/16
 *  0b011..1 + 1/8
 *  0b100..1 - 1/32
 *  0b101..1 - 1/16
 *  0b110..1 - 1/8
 *  0b111..Reserved
 */
#define XCVR_TX_DIG_GFSK_CTRL_GFSK_MOD_INDEX_SCALING(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_GFSK_MOD_INDEX_SCALING_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_GFSK_MOD_INDEX_SCALING_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_OVRD_EN_MASK (0x10000000U)
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_OVRD_EN_SHIFT (28U)
/*! TX_IMAGE_FILTER_OVRD_EN - TX Image Filter Override Enable */
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_OVRD_EN_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_OVRD_EN_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_0_OVRD_MASK (0x20000000U)
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_0_OVRD_SHIFT (29U)
/*! TX_IMAGE_FILTER_0_OVRD - TX Image Filter 0 Override Control */
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_0_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_0_OVRD_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_0_OVRD_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_1_OVRD_MASK (0x40000000U)
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_1_OVRD_SHIFT (30U)
/*! TX_IMAGE_FILTER_1_OVRD - TX Image Filter 1 Override Control */
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_1_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_1_OVRD_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_1_OVRD_MASK)

#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_2_OVRD_MASK (0x80000000U)
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_2_OVRD_SHIFT (31U)
/*! TX_IMAGE_FILTER_2_OVRD - TX Image Filter 2 Override Control */
#define XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_2_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_2_OVRD_SHIFT)) & XCVR_TX_DIG_GFSK_CTRL_TX_IMAGE_FILTER_2_OVRD_MASK)
/*! @} */

/*! @name GFSK_COEFF2 - TX GFSK Filter Coefficients 2 */
/*! @{ */

#define XCVR_TX_DIG_GFSK_COEFF2_GFSK_FILTER_COEFF_MANUAL2_MASK (0xFFFFFFFFU)
#define XCVR_TX_DIG_GFSK_COEFF2_GFSK_FILTER_COEFF_MANUAL2_SHIFT (0U)
/*! GFSK_FILTER_COEFF_MANUAL2 - GFSK Manual Filter Coefficients[63:32] */
#define XCVR_TX_DIG_GFSK_COEFF2_GFSK_FILTER_COEFF_MANUAL2(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_COEFF2_GFSK_FILTER_COEFF_MANUAL2_SHIFT)) & XCVR_TX_DIG_GFSK_COEFF2_GFSK_FILTER_COEFF_MANUAL2_MASK)
/*! @} */

/*! @name GFSK_COEFF1 - TX GFSK Filter Coefficients 1 */
/*! @{ */

#define XCVR_TX_DIG_GFSK_COEFF1_GFSK_FILTER_COEFF_MANUAL1_MASK (0xFFFFFFFFU)
#define XCVR_TX_DIG_GFSK_COEFF1_GFSK_FILTER_COEFF_MANUAL1_SHIFT (0U)
/*! GFSK_FILTER_COEFF_MANUAL1 - GFSK Manual Filter Coefficient [31:0] */
#define XCVR_TX_DIG_GFSK_COEFF1_GFSK_FILTER_COEFF_MANUAL1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_GFSK_COEFF1_GFSK_FILTER_COEFF_MANUAL1_SHIFT)) & XCVR_TX_DIG_GFSK_COEFF1_GFSK_FILTER_COEFF_MANUAL1_MASK)
/*! @} */

/*! @name FSK_SCALE - TX FSK Modulation Levels */
/*! @{ */

#define XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_0_MASK (0x1FFFU)
#define XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_0_SHIFT (0U)
/*! FSK_MODULATION_SCALE_0 - FSK Modulation Scale for a data 0 */
#define XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_0_SHIFT)) & XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_0_MASK)

#define XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_1_MASK (0x1FFF0000U)
#define XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_1_SHIFT (16U)
/*! FSK_MODULATION_SCALE_1 - FSK Modulation Scale for a data 1 */
#define XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_1(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_1_SHIFT)) & XCVR_TX_DIG_FSK_SCALE_FSK_MODULATION_SCALE_1_MASK)
/*! @} */

/*! @name DFT_PATTERN - TX DFT Modulation Pattern */
/*! @{ */

#define XCVR_TX_DIG_DFT_PATTERN_DFT_MOD_PATTERN_MASK (0xFFFFFFFFU)
#define XCVR_TX_DIG_DFT_PATTERN_DFT_MOD_PATTERN_SHIFT (0U)
/*! DFT_MOD_PATTERN - DFT Modulation Pattern */
#define XCVR_TX_DIG_DFT_PATTERN_DFT_MOD_PATTERN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_DFT_PATTERN_DFT_MOD_PATTERN_SHIFT)) & XCVR_TX_DIG_DFT_PATTERN_DFT_MOD_PATTERN_MASK)
/*! @} */

/*! @name RF_DFT_BIST_1 - TX DFT Control 1 */
/*! @{ */

#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_GO_MASK (0x1U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_GO_SHIFT (0U)
/*! CTUNE_BIST_GO - Start the Coarse Tune BIST */
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_GO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_GO_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_GO_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_FINISHED_MASK (0x2U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_FINISHED_SHIFT (1U)
/*! CTUNE_BIST_FINISHED - Coarse Tune BIST has finished Tuning all Channels */
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_FINISHED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_FINISHED_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_FINISHED_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_RESULT_MASK (0x4U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_RESULT_SHIFT (2U)
/*! CTUNE_BIST_RESULT - Coarse Tune BIST Result */
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_RESULT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_RESULT_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_RESULT_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_THRSHLD_MASK (0xF0U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_THRSHLD_SHIFT (4U)
/*! CTUNE_BIST_THRSHLD - Maximum Difference Threshold for Coarse Tune BIST */
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_THRSHLD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_THRSHLD_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_BIST_THRSHLD_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_MASK (0xFF00U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_SHIFT (8U)
/*! CTUNE_MAX_DIFF - Maximum Frequency Count Difference found by the Coarse Tune BIST */
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_CH_MASK (0x7F0000U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_CH_SHIFT (16U)
/*! CTUNE_MAX_DIFF_CH - Maximum Frequency Count Difference Radio Channel */
#define XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_CH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_CH_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_CTUNE_MAX_DIFF_CH_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_FREQ_MASK (0x7000000U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_FREQ_SHIFT (24U)
/*! PA_AM_MOD_FREQ - RF Power Amplifier Amplitude Modulation Frequency
 *  0b000..4 MHz
 *  0b001..2 MHz
 *  0b010..1 MHz
 *  0b011..500 kHz
 *  0b100..250 kHz
 *  0b101..125 kHz
 *  0b110..62.5 kHz
 *  0b111..Reserved
 */
#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_FREQ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_FREQ_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_FREQ_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_ENTRIES_MASK (0x70000000U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_ENTRIES_SHIFT (28U)
/*! PA_AM_MOD_ENTRIES - RF Power Amplifier Amplitude Modulation Table Entries
 *  0b000..Reserved
 *  0b001..2 entries
 *  0b010..3 entries
 *  0b011..4 entries
 *  0b100..5 entries
 *  0b101..6 entries
 *  0b110..7 entries
 *  0b111..8 entries
 */
#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_ENTRIES(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_ENTRIES_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_ENTRIES_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_EN_MASK (0x80000000U)
#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_EN_SHIFT (31U)
/*! PA_AM_MOD_EN - RF Power Amplifier Amplitude Modulation Enable */
#define XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_EN_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_1_PA_AM_MOD_EN_MASK)
/*! @} */

/*! @name RF_DFT_BIST_2 - TX DFT Control 2 */
/*! @{ */

#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_GO_MASK (0x1U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_GO_SHIFT (0U)
/*! SYN_BIST_GO - Start the PLL Frequency Synthesizer BIST */
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_GO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_GO_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_GO_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_FINISHED_MASK (0x2U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_FINISHED_SHIFT (1U)
/*! SYN_BIST_FINISHED - PLL Frequency Synthesizer BIST has finished trying to lock to Radio Channels */
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_FINISHED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_FINISHED_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_FINISHED_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_RESULT_MASK (0x4U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_RESULT_SHIFT (2U)
/*! SYN_BIST_RESULT - PLL Frequency Synthesizer BIST Result */
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_RESULT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_RESULT_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_RESULT_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_ALL_CHANNELS_MASK (0x8U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_ALL_CHANNELS_SHIFT (3U)
/*! SYN_BIST_ALL_CHANNELS - PLL Frequency Synthesizer BIST All Channels */
#define XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_ALL_CHANNELS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_ALL_CHANNELS_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_SYN_BIST_ALL_CHANNELS_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_FREQ_COUNT_THRESHOLD_MASK (0xFF0U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_FREQ_COUNT_THRESHOLD_SHIFT (4U)
/*! FREQ_COUNT_THRESHOLD - Frequency Meter Count Difference Threshold */
#define XCVR_TX_DIG_RF_DFT_BIST_2_FREQ_COUNT_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_FREQ_COUNT_THRESHOLD_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_FREQ_COUNT_THRESHOLD_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_GO_MASK (0x1000U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_GO_SHIFT (12U)
/*! HPM_INL_BIST_GO - Start the High Port Modulator DAC INL BIST */
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_GO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_GO_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_GO_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_FINISHED_MASK (0x2000U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_FINISHED_SHIFT (13U)
/*! HPM_INL_BIST_FINISHED - High Port Modulator DAC INL BIST has finished measuring the INL of the HPM DAC */
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_FINISHED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_FINISHED_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_FINISHED_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_RESULT_MASK (0x4000U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_RESULT_SHIFT (14U)
/*! HPM_INL_BIST_RESULT - High Port Modulator DAC INL BIST Result */
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_RESULT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_RESULT_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_HPM_INL_BIST_RESULT_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_GO_MASK (0x10000U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_GO_SHIFT (16U)
/*! HPM_DNL_BIST_GO - Start the High Port Modulator DAC DNL BIST */
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_GO(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_GO_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_GO_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_FINISHED_MASK (0x20000U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_FINISHED_SHIFT (17U)
/*! HPM_DNL_BIST_FINISHED - High Port Modulator DAC DNL BIST has finished measuring the DNL of the HPM DAC */
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_FINISHED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_FINISHED_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_FINISHED_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_RESULT_MASK (0x40000U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_RESULT_SHIFT (18U)
/*! HPM_DNL_BIST_RESULT - High Port Modulator DAC DNL BIST Result */
#define XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_RESULT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_RESULT_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_HPM_DNL_BIST_RESULT_MASK)

#define XCVR_TX_DIG_RF_DFT_BIST_2_DFT_MAX_RAM_SIZE_MASK (0x1FF00000U)
#define XCVR_TX_DIG_RF_DFT_BIST_2_DFT_MAX_RAM_SIZE_SHIFT (20U)
/*! DFT_MAX_RAM_SIZE - Maximum RAM Address to use as Modulation */
#define XCVR_TX_DIG_RF_DFT_BIST_2_DFT_MAX_RAM_SIZE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_TX_DIG_RF_DFT_BIST_2_DFT_MAX_RAM_SIZE_SHIFT)) & XCVR_TX_DIG_RF_DFT_BIST_2_DFT_MAX_RAM_SIZE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_TX_DIG_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_TX_DIG_Peripheral_Access_Layer */


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


#endif  /* XCVR_TX_DIG_H_ */

