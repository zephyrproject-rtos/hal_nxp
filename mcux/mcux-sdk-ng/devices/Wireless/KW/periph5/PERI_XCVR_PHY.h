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
**         CMSIS Peripheral Access Layer for XCVR_PHY
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
 * @file XCVR_PHY.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_PHY
 *
 * CMSIS Peripheral Access Layer for XCVR_PHY
 */

#if !defined(XCVR_PHY_H_)
#define XCVR_PHY_H_                              /**< Symbol preventing repeated inclusion */

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
   -- XCVR_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PHY_Peripheral_Access_Layer XCVR_PHY Peripheral Access Layer
 * @{
 */

/** XCVR_PHY - Register Layout Typedef */
typedef struct {
  __IO uint32_t PHY_PRE_REF0;                      /**< PREAMBLE REFERENCE WAVEFORM 0, offset: 0x0 */
  __IO uint32_t PRE_REF1;                          /**< PREAMBLE REFERENCE WAVEFORM 1, offset: 0x4 */
  __IO uint32_t PRE_REF2;                          /**< PREAMBLE REFERENCE WAVEFORM 2, offset: 0x8 */
       uint8_t RESERVED_0[20];
  __IO uint32_t CFG1;                              /**< PHY CONFIGURATION REGISTER 1, offset: 0x20 */
  __IO uint32_t CFG2;                              /**< PHY CONFIGURATION REGISTER 2, offset: 0x24 */
  __IO uint32_t EL_CFG;                            /**< PHY EARLY/LATE CONFIGURATION REGISTER, offset: 0x28 */
  __IO uint32_t NTW_ADR_BSM;                       /**< PHY NETWORK ADDRESS FOR BSM, offset: 0x2C */
  __I  uint32_t STATUS;                            /**< PHY STATUS REGISTER, offset: 0x30 */
} XCVR_PHY_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PHY_Register_Masks XCVR_PHY Register Masks
 * @{
 */

/*! @name PHY_PRE_REF0 - PREAMBLE REFERENCE WAVEFORM 0 */
/*! @{ */

#define XCVR_PHY_PHY_PRE_REF0_FSK_PREAMBLE_REF0_MASK (0xFFFFFFFFU)
#define XCVR_PHY_PHY_PRE_REF0_FSK_PREAMBLE_REF0_SHIFT (0U)
#define XCVR_PHY_PHY_PRE_REF0_FSK_PREAMBLE_REF0(x) (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_PHY_PRE_REF0_FSK_PREAMBLE_REF0_SHIFT)) & XCVR_PHY_PHY_PRE_REF0_FSK_PREAMBLE_REF0_MASK)
/*! @} */

/*! @name PRE_REF1 - PREAMBLE REFERENCE WAVEFORM 1 */
/*! @{ */

#define XCVR_PHY_PRE_REF1_FSK_PREAMBLE_REF1_MASK (0xFFFFFFFFU)
#define XCVR_PHY_PRE_REF1_FSK_PREAMBLE_REF1_SHIFT (0U)
#define XCVR_PHY_PRE_REF1_FSK_PREAMBLE_REF1(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_PRE_REF1_FSK_PREAMBLE_REF1_SHIFT)) & XCVR_PHY_PRE_REF1_FSK_PREAMBLE_REF1_MASK)
/*! @} */

/*! @name PRE_REF2 - PREAMBLE REFERENCE WAVEFORM 2 */
/*! @{ */

#define XCVR_PHY_PRE_REF2_FSK_PREAMBLE_REF2_MASK (0xFFFFU)
#define XCVR_PHY_PRE_REF2_FSK_PREAMBLE_REF2_SHIFT (0U)
#define XCVR_PHY_PRE_REF2_FSK_PREAMBLE_REF2(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_PRE_REF2_FSK_PREAMBLE_REF2_SHIFT)) & XCVR_PHY_PRE_REF2_FSK_PREAMBLE_REF2_MASK)
/*! @} */

/*! @name CFG1 - PHY CONFIGURATION REGISTER 1 */
/*! @{ */

#define XCVR_PHY_CFG1_AA_PLAYBACK_MASK           (0x2U)
#define XCVR_PHY_CFG1_AA_PLAYBACK_SHIFT          (1U)
/*! AA_PLAYBACK - Access Address Playback */
#define XCVR_PHY_CFG1_AA_PLAYBACK(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_AA_PLAYBACK_SHIFT)) & XCVR_PHY_CFG1_AA_PLAYBACK_MASK)

#define XCVR_PHY_CFG1_AA_OUTPUT_SEL_MASK         (0x4U)
#define XCVR_PHY_CFG1_AA_OUTPUT_SEL_SHIFT        (2U)
/*! AA_OUTPUT_SEL - Access Address Output Select
 *  0b0..demodulated
 *  0b1..matched
 */
#define XCVR_PHY_CFG1_AA_OUTPUT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_AA_OUTPUT_SEL_SHIFT)) & XCVR_PHY_CFG1_AA_OUTPUT_SEL_MASK)

#define XCVR_PHY_CFG1_FSK_BIT_INVERT_MASK        (0x8U)
#define XCVR_PHY_CFG1_FSK_BIT_INVERT_SHIFT       (3U)
/*! FSK_BIT_INVERT - FSK Bit Invert */
#define XCVR_PHY_CFG1_FSK_BIT_INVERT(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_FSK_BIT_INVERT_SHIFT)) & XCVR_PHY_CFG1_FSK_BIT_INVERT_MASK)

#define XCVR_PHY_CFG1_RFU00_MASK                 (0x10U)
#define XCVR_PHY_CFG1_RFU00_SHIFT                (4U)
/*! RFU00 - Reserved for future use. */
#define XCVR_PHY_CFG1_RFU00(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_RFU00_SHIFT)) & XCVR_PHY_CFG1_RFU00_MASK)

#define XCVR_PHY_CFG1_BSM_EN_BLE_MASK            (0x20U)
#define XCVR_PHY_CFG1_BSM_EN_BLE_SHIFT           (5U)
/*! BSM_EN_BLE - BLE Bit Streaming Mode Enable bit
 *  0b0..BSM for BLE disabled
 *  0b1..BSM for BLE enabled
 */
#define XCVR_PHY_CFG1_BSM_EN_BLE(x)              (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_BSM_EN_BLE_SHIFT)) & XCVR_PHY_CFG1_BSM_EN_BLE_MASK)

#define XCVR_PHY_CFG1_DEMOD_CLK_MODE_MASK        (0xC0U)
#define XCVR_PHY_CFG1_DEMOD_CLK_MODE_SHIFT       (6U)
/*! DEMOD_CLK_MODE - Demodulator Clock Mode
 *  0b00..Normal
 *  0b01..Demodulate all samples
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define XCVR_PHY_CFG1_DEMOD_CLK_MODE(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_DEMOD_CLK_MODE_SHIFT)) & XCVR_PHY_CFG1_DEMOD_CLK_MODE_MASK)

#define XCVR_PHY_CFG1_CTS_THRESH_MASK            (0xFF00U)
#define XCVR_PHY_CFG1_CTS_THRESH_SHIFT           (8U)
/*! CTS_THRESH - CTS (Coarse Timing Search) Correlation Threshold */
#define XCVR_PHY_CFG1_CTS_THRESH(x)              (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_CTS_THRESH_SHIFT)) & XCVR_PHY_CFG1_CTS_THRESH_MASK)

#define XCVR_PHY_CFG1_FSK_FTS_TIMEOUT_MASK       (0x700000U)
#define XCVR_PHY_CFG1_FSK_FTS_TIMEOUT_SHIFT      (20U)
/*! FSK_FTS_TIMEOUT - FSK FTS Timeout
 *  0b000..4 symbols
 *  0b001..5 symbols
 *  0b010..6 symbols
 *  0b011..7 symbols
 *  0b100..8 symbols
 *  0b101..9 symbols
 *  0b110..10 symbols
 *  0b111..11 symbols
 */
#define XCVR_PHY_CFG1_FSK_FTS_TIMEOUT(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_FSK_FTS_TIMEOUT_SHIFT)) & XCVR_PHY_CFG1_FSK_FTS_TIMEOUT_MASK)

#define XCVR_PHY_CFG1_RFU01_MASK                 (0x1000000U)
#define XCVR_PHY_CFG1_RFU01_SHIFT                (24U)
/*! RFU01 - Reserved for future use. */
#define XCVR_PHY_CFG1_RFU01(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_RFU01_SHIFT)) & XCVR_PHY_CFG1_RFU01_MASK)

#define XCVR_PHY_CFG1_RFU02_MASK                 (0x2000000U)
#define XCVR_PHY_CFG1_RFU02_SHIFT                (25U)
/*! RFU02 - Reserved for future use. */
#define XCVR_PHY_CFG1_RFU02(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_RFU02_SHIFT)) & XCVR_PHY_CFG1_RFU02_MASK)

#define XCVR_PHY_CFG1_BLE_NTW_ADR_THR_MASK       (0x70000000U)
#define XCVR_PHY_CFG1_BLE_NTW_ADR_THR_SHIFT      (28U)
/*! BLE_NTW_ADR_THR - BLE Network Address Match Bit Error Threshold */
#define XCVR_PHY_CFG1_BLE_NTW_ADR_THR(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG1_BLE_NTW_ADR_THR_SHIFT)) & XCVR_PHY_CFG1_BLE_NTW_ADR_THR_MASK)
/*! @} */

/*! @name CFG2 - PHY CONFIGURATION REGISTER 2 */
/*! @{ */

#define XCVR_PHY_CFG2_PHY_FIFO_PRECHG_MASK       (0xFU)
#define XCVR_PHY_CFG2_PHY_FIFO_PRECHG_SHIFT      (0U)
/*! PHY_FIFO_PRECHG - PHY FIFO Precharge Level */
#define XCVR_PHY_CFG2_PHY_FIFO_PRECHG(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_PHY_FIFO_PRECHG_SHIFT)) & XCVR_PHY_CFG2_PHY_FIFO_PRECHG_MASK)

#define XCVR_PHY_CFG2_RFU03_MASK                 (0x10U)
#define XCVR_PHY_CFG2_RFU03_SHIFT                (4U)
/*! RFU03 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU03(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU03_SHIFT)) & XCVR_PHY_CFG2_RFU03_MASK)

#define XCVR_PHY_CFG2_RFU04_MASK                 (0x20U)
#define XCVR_PHY_CFG2_RFU04_SHIFT                (5U)
/*! RFU04 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU04(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU04_SHIFT)) & XCVR_PHY_CFG2_RFU04_MASK)

#define XCVR_PHY_CFG2_RFU05_MASK                 (0x40U)
#define XCVR_PHY_CFG2_RFU05_SHIFT                (6U)
/*! RFU05 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU05(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU05_SHIFT)) & XCVR_PHY_CFG2_RFU05_MASK)

#define XCVR_PHY_CFG2_RFU06_MASK                 (0x80U)
#define XCVR_PHY_CFG2_RFU06_SHIFT                (7U)
/*! RFU06 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU06(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU06_SHIFT)) & XCVR_PHY_CFG2_RFU06_MASK)

#define XCVR_PHY_CFG2_X2_DEMOD_GAIN_MASK         (0xF00U)
#define XCVR_PHY_CFG2_X2_DEMOD_GAIN_SHIFT        (8U)
/*! X2_DEMOD_GAIN - X2_DEMOD_GAIN */
#define XCVR_PHY_CFG2_X2_DEMOD_GAIN(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_X2_DEMOD_GAIN_SHIFT)) & XCVR_PHY_CFG2_X2_DEMOD_GAIN_MASK)

#define XCVR_PHY_CFG2_RFU07_MASK                 (0x10000U)
#define XCVR_PHY_CFG2_RFU07_SHIFT                (16U)
/*! RFU07 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU07(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU07_SHIFT)) & XCVR_PHY_CFG2_RFU07_MASK)

#define XCVR_PHY_CFG2_RFU08_MASK                 (0x20000U)
#define XCVR_PHY_CFG2_RFU08_SHIFT                (17U)
/*! RFU08 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU08(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU08_SHIFT)) & XCVR_PHY_CFG2_RFU08_MASK)

#define XCVR_PHY_CFG2_RFU09_MASK                 (0x40000U)
#define XCVR_PHY_CFG2_RFU09_SHIFT                (18U)
/*! RFU09 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU09(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU09_SHIFT)) & XCVR_PHY_CFG2_RFU09_MASK)

#define XCVR_PHY_CFG2_RFU10_MASK                 (0x80000U)
#define XCVR_PHY_CFG2_RFU10_SHIFT                (19U)
/*! RFU10 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU10(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU10_SHIFT)) & XCVR_PHY_CFG2_RFU10_MASK)

#define XCVR_PHY_CFG2_RFU11_MASK                 (0x100000U)
#define XCVR_PHY_CFG2_RFU11_SHIFT                (20U)
/*! RFU11 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU11(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU11_SHIFT)) & XCVR_PHY_CFG2_RFU11_MASK)

#define XCVR_PHY_CFG2_RFU12_MASK                 (0x200000U)
#define XCVR_PHY_CFG2_RFU12_SHIFT                (21U)
/*! RFU12 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU12(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU12_SHIFT)) & XCVR_PHY_CFG2_RFU12_MASK)

#define XCVR_PHY_CFG2_RFU13_MASK                 (0x400000U)
#define XCVR_PHY_CFG2_RFU13_SHIFT                (22U)
/*! RFU13 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU13(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU13_SHIFT)) & XCVR_PHY_CFG2_RFU13_MASK)

#define XCVR_PHY_CFG2_RFU14_MASK                 (0x800000U)
#define XCVR_PHY_CFG2_RFU14_SHIFT                (23U)
/*! RFU14 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU14(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU14_SHIFT)) & XCVR_PHY_CFG2_RFU14_MASK)

#define XCVR_PHY_CFG2_RFU15_MASK                 (0x1000000U)
#define XCVR_PHY_CFG2_RFU15_SHIFT                (24U)
/*! RFU15 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU15(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU15_SHIFT)) & XCVR_PHY_CFG2_RFU15_MASK)

#define XCVR_PHY_CFG2_RFU16_MASK                 (0x2000000U)
#define XCVR_PHY_CFG2_RFU16_SHIFT                (25U)
/*! RFU16 - Reserved for future use. */
#define XCVR_PHY_CFG2_RFU16(x)                   (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_RFU16_SHIFT)) & XCVR_PHY_CFG2_RFU16_MASK)

#define XCVR_PHY_CFG2_PHY_CLK_ON_MASK            (0x80000000U)
#define XCVR_PHY_CFG2_PHY_CLK_ON_SHIFT           (31U)
/*! PHY_CLK_ON - Force PHY Clock On (testmode)
 *  0b0..PHY clock is enabled by TSM output: rx_phy_en
 *  0b1..PHY clock is forced on at all times
 */
#define XCVR_PHY_CFG2_PHY_CLK_ON(x)              (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_CFG2_PHY_CLK_ON_SHIFT)) & XCVR_PHY_CFG2_PHY_CLK_ON_MASK)
/*! @} */

/*! @name EL_CFG - PHY EARLY/LATE CONFIGURATION REGISTER */
/*! @{ */

#define XCVR_PHY_EL_CFG_EL_ENABLE_MASK           (0x1U)
#define XCVR_PHY_EL_CFG_EL_ENABLE_SHIFT          (0U)
/*! EL_ENABLE - EL_ENABLE
 *  0b0..Disable Early/Late
 *  0b1..Enable Early/Late
 */
#define XCVR_PHY_EL_CFG_EL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_EL_CFG_EL_ENABLE_SHIFT)) & XCVR_PHY_EL_CFG_EL_ENABLE_MASK)

#define XCVR_PHY_EL_CFG_EL_ZB_ENABLE_MASK        (0x2U)
#define XCVR_PHY_EL_CFG_EL_ZB_ENABLE_SHIFT       (1U)
/*! EL_ZB_ENABLE - EL_ZB_ENABLE
 *  0b0..Disable Early/Late
 *  0b1..Enable Early/Late
 */
#define XCVR_PHY_EL_CFG_EL_ZB_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_EL_CFG_EL_ZB_ENABLE_SHIFT)) & XCVR_PHY_EL_CFG_EL_ZB_ENABLE_MASK)

#define XCVR_PHY_EL_CFG_EL_ZB_WIN_SIZE_MASK      (0x4U)
#define XCVR_PHY_EL_CFG_EL_ZB_WIN_SIZE_SHIFT     (2U)
/*! EL_ZB_WIN_SIZE - EL_ZB_WIN_SIZE
 *  0b0..2 symbols
 *  0b1..3 symbols
 */
#define XCVR_PHY_EL_CFG_EL_ZB_WIN_SIZE(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_EL_CFG_EL_ZB_WIN_SIZE_SHIFT)) & XCVR_PHY_EL_CFG_EL_ZB_WIN_SIZE_MASK)

#define XCVR_PHY_EL_CFG_EL_WIN_SIZE_MASK         (0xF00U)
#define XCVR_PHY_EL_CFG_EL_WIN_SIZE_SHIFT        (8U)
/*! EL_WIN_SIZE - EL_WIN_SIZE */
#define XCVR_PHY_EL_CFG_EL_WIN_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_EL_CFG_EL_WIN_SIZE_SHIFT)) & XCVR_PHY_EL_CFG_EL_WIN_SIZE_MASK)

#define XCVR_PHY_EL_CFG_EL_INTERVAL_MASK         (0x3F0000U)
#define XCVR_PHY_EL_CFG_EL_INTERVAL_SHIFT        (16U)
/*! EL_INTERVAL - EL_INTERVAL */
#define XCVR_PHY_EL_CFG_EL_INTERVAL(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_EL_CFG_EL_INTERVAL_SHIFT)) & XCVR_PHY_EL_CFG_EL_INTERVAL_MASK)
/*! @} */

/*! @name NTW_ADR_BSM - PHY NETWORK ADDRESS FOR BSM */
/*! @{ */

#define XCVR_PHY_NTW_ADR_BSM_NTW_ADR_BSM_MASK    (0xFFFFFFFFU)
#define XCVR_PHY_NTW_ADR_BSM_NTW_ADR_BSM_SHIFT   (0U)
/*! NTW_ADR_BSM - NTW_ADR_BSM */
#define XCVR_PHY_NTW_ADR_BSM_NTW_ADR_BSM(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_NTW_ADR_BSM_NTW_ADR_BSM_SHIFT)) & XCVR_PHY_NTW_ADR_BSM_NTW_ADR_BSM_MASK)
/*! @} */

/*! @name STATUS - PHY STATUS REGISTER */
/*! @{ */

#define XCVR_PHY_STATUS_PREAMBLE_FOUND_MASK      (0x1U)
#define XCVR_PHY_STATUS_PREAMBLE_FOUND_SHIFT     (0U)
/*! PREAMBLE_FOUND - Preamble Found */
#define XCVR_PHY_STATUS_PREAMBLE_FOUND(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_STATUS_PREAMBLE_FOUND_SHIFT)) & XCVR_PHY_STATUS_PREAMBLE_FOUND_MASK)

#define XCVR_PHY_STATUS_AA_SFD_MATCHED_MASK      (0x2U)
#define XCVR_PHY_STATUS_AA_SFD_MATCHED_SHIFT     (1U)
/*! AA_SFD_MATCHED - Access Address or SFD Found */
#define XCVR_PHY_STATUS_AA_SFD_MATCHED(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_STATUS_AA_SFD_MATCHED_SHIFT)) & XCVR_PHY_STATUS_AA_SFD_MATCHED_MASK)

#define XCVR_PHY_STATUS_AA_MATCHED_MASK          (0xF0U)
#define XCVR_PHY_STATUS_AA_MATCHED_SHIFT         (4U)
/*! AA_MATCHED - Access Address Matched
 *  0b0000..No Network Address has matched
 *  0b0001..Network Address 0 has matched
 *  0b0010..Network Address 1 has matched
 *  0b0100..Network Address 2 has matched
 *  0b1000..Network Address 3 has matched
 */
#define XCVR_PHY_STATUS_AA_MATCHED(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_STATUS_AA_MATCHED_SHIFT)) & XCVR_PHY_STATUS_AA_MATCHED_MASK)

#define XCVR_PHY_STATUS_HAMMING_DISTANCE_MASK    (0x700U)
#define XCVR_PHY_STATUS_HAMMING_DISTANCE_SHIFT   (8U)
/*! HAMMING_DISTANCE - HAMMING DISTANCE */
#define XCVR_PHY_STATUS_HAMMING_DISTANCE(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_STATUS_HAMMING_DISTANCE_SHIFT)) & XCVR_PHY_STATUS_HAMMING_DISTANCE_MASK)

#define XCVR_PHY_STATUS_DATA_FIFO_DEPTH_MASK     (0xF000U)
#define XCVR_PHY_STATUS_DATA_FIFO_DEPTH_SHIFT    (12U)
/*! DATA_FIFO_DEPTH - DATA FIFO DEPTH */
#define XCVR_PHY_STATUS_DATA_FIFO_DEPTH(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_STATUS_DATA_FIFO_DEPTH_SHIFT)) & XCVR_PHY_STATUS_DATA_FIFO_DEPTH_MASK)

#define XCVR_PHY_STATUS_CFO_ESTIMATE_MASK        (0xFF0000U)
#define XCVR_PHY_STATUS_CFO_ESTIMATE_SHIFT       (16U)
/*! CFO_ESTIMATE - Carrier Frequency Offset Estimate */
#define XCVR_PHY_STATUS_CFO_ESTIMATE(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_PHY_STATUS_CFO_ESTIMATE_SHIFT)) & XCVR_PHY_STATUS_CFO_ESTIMATE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_PHY_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_PHY_Peripheral_Access_Layer */


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


#endif  /* XCVR_PHY_H_ */

