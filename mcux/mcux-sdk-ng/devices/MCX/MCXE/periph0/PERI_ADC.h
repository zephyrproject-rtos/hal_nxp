/*
** ###################################################################
**     Processors:          MCXE247VLL
**                          MCXE247VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250417
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE247VLL) || defined(CPU_MCXE247VLQ))
#include "MCXE247_COMMON.h"
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
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Size of Registers Arrays */
#define ADC_SC1_COUNT                             32u
#define ADC_R_COUNT                               32u

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC1A;                              /**< ADC Status and Control Register 1, offset: 0x0 */
  __IO uint32_t SC1B;                              /**< ADC Status and Control Register 1, offset: 0x4 */
  __IO uint32_t SC1C;                              /**< ADC Status and Control Register 1, offset: 0x8 */
  __IO uint32_t SC1D;                              /**< ADC Status and Control Register 1, offset: 0xC */
  __IO uint32_t SC1E;                              /**< ADC Status and Control Register 1, offset: 0x10 */
  __IO uint32_t SC1F;                              /**< ADC Status and Control Register 1, offset: 0x14 */
  __IO uint32_t SC1G;                              /**< ADC Status and Control Register 1, offset: 0x18 */
  __IO uint32_t SC1H;                              /**< ADC Status and Control Register 1, offset: 0x1C */
  __IO uint32_t SC1I;                              /**< ADC Status and Control Register 1, offset: 0x20 */
  __IO uint32_t SC1J;                              /**< ADC Status and Control Register 1, offset: 0x24 */
  __IO uint32_t SC1K;                              /**< ADC Status and Control Register 1, offset: 0x28 */
  __IO uint32_t SC1L;                              /**< ADC Status and Control Register 1, offset: 0x2C */
  __IO uint32_t SC1M;                              /**< ADC Status and Control Register 1, offset: 0x30 */
  __IO uint32_t SC1N;                              /**< ADC Status and Control Register 1, offset: 0x34 */
  __IO uint32_t SC1O;                              /**< ADC Status and Control Register 1, offset: 0x38 */
  __IO uint32_t SC1P;                              /**< ADC Status and Control Register 1, offset: 0x3C */
  __IO uint32_t CFG1;                              /**< ADC Configuration Register 1, offset: 0x40 */
  __IO uint32_t CFG2;                              /**< ADC Configuration Register 2, offset: 0x44 */
  __I  uint32_t RA;                                /**< ADC Data Result Registers, offset: 0x48 */
  __I  uint32_t RB;                                /**< ADC Data Result Registers, offset: 0x4C */
  __I  uint32_t RC;                                /**< ADC Data Result Registers, offset: 0x50 */
  __I  uint32_t RD;                                /**< ADC Data Result Registers, offset: 0x54 */
  __I  uint32_t RE;                                /**< ADC Data Result Registers, offset: 0x58 */
  __I  uint32_t RF;                                /**< ADC Data Result Registers, offset: 0x5C */
  __I  uint32_t RG;                                /**< ADC Data Result Registers, offset: 0x60 */
  __I  uint32_t RH;                                /**< ADC Data Result Registers, offset: 0x64 */
  __I  uint32_t RI;                                /**< ADC Data Result Registers, offset: 0x68 */
  __I  uint32_t RJ;                                /**< ADC Data Result Registers, offset: 0x6C */
  __I  uint32_t RK;                                /**< ADC Data Result Registers, offset: 0x70 */
  __I  uint32_t RL;                                /**< ADC Data Result Registers, offset: 0x74 */
  __I  uint32_t RM;                                /**< ADC Data Result Registers, offset: 0x78 */
  __I  uint32_t RN;                                /**< ADC Data Result Registers, offset: 0x7C */
  __I  uint32_t RO;                                /**< ADC Data Result Registers, offset: 0x80 */
  __I  uint32_t RP;                                /**< ADC Data Result Registers, offset: 0x84 */
  __IO uint32_t CV1;                               /**< Compare Value Registers, offset: 0x88 */
  __IO uint32_t CV2;                               /**< Compare Value Registers, offset: 0x8C */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x90 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x94 */
  __IO uint32_t BASE_OFS;                          /**< BASE Offset Register, offset: 0x98 */
  __IO uint32_t OFS;                               /**< ADC Offset Correction Register, offset: 0x9C */
  __IO uint32_t USR_OFS;                           /**< USER Offset Correction Register, offset: 0xA0 */
  __IO uint32_t XOFS;                              /**< ADC X Offset Correction Register, offset: 0xA4 */
  __IO uint32_t YOFS;                              /**< ADC Y Offset Correction Register, offset: 0xA8 */
  __IO uint32_t GAIN;                              /**< ADC Gain Register, offset: 0xAC */
  __IO uint32_t UG;                                /**< ADC User Gain Register, offset: 0xB0 */
  __IO uint32_t CLPS;                              /**< ADC General Calibration Value Register S, offset: 0xB4 */
  __IO uint32_t CLP3;                              /**< ADC Plus-Side General Calibration Value Register 3, offset: 0xB8 */
  __IO uint32_t CLP2;                              /**< ADC Plus-Side General Calibration Value Register 2, offset: 0xBC */
  __IO uint32_t CLP1;                              /**< ADC Plus-Side General Calibration Value Register 1, offset: 0xC0 */
  __IO uint32_t CLP0;                              /**< ADC Plus-Side General Calibration Value Register 0, offset: 0xC4 */
  __IO uint32_t CLPX;                              /**< ADC Plus-Side General Calibration Value Register X, offset: 0xC8 */
  __IO uint32_t CLP9;                              /**< ADC Plus-Side General Calibration Value Register 9, offset: 0xCC */
  __IO uint32_t CLPS_OFS;                          /**< ADC General Calibration Offset Value Register S, offset: 0xD0 */
  __IO uint32_t CLP3_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 3, offset: 0xD4 */
  __IO uint32_t CLP2_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 2, offset: 0xD8 */
  __IO uint32_t CLP1_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 1, offset: 0xDC */
  __IO uint32_t CLP0_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 0, offset: 0xE0 */
  __IO uint32_t CLPX_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register X, offset: 0xE4 */
  __IO uint32_t CLP9_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 9, offset: 0xE8 */
       uint8_t RESERVED_0[28];
  __IO uint32_t SC1[ADC_SC1_COUNT];                /**< ADC Status and Control Register 1, array offset: 0x108, array step: 0x4 */
  __I  uint32_t R[ADC_R_COUNT];                    /**< ADC Data Result Registers, array offset: 0x188, array step: 0x4 */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name SC1A - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1A_ADCH_MASK                       (0x3FU)
#define ADC_SC1A_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1A_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1A_ADCH_SHIFT)) & ADC_SC1A_ADCH_MASK)

#define ADC_SC1A_AIEN_MASK                       (0x40U)
#define ADC_SC1A_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1A_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1A_AIEN_SHIFT)) & ADC_SC1A_AIEN_MASK)

#define ADC_SC1A_COCO_MASK                       (0x80U)
#define ADC_SC1A_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1A_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1A_COCO_SHIFT)) & ADC_SC1A_COCO_MASK)
/*! @} */

/*! @name SC1B - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1B_ADCH_MASK                       (0x3FU)
#define ADC_SC1B_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1B_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1B_ADCH_SHIFT)) & ADC_SC1B_ADCH_MASK)

#define ADC_SC1B_AIEN_MASK                       (0x40U)
#define ADC_SC1B_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1B_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1B_AIEN_SHIFT)) & ADC_SC1B_AIEN_MASK)

#define ADC_SC1B_COCO_MASK                       (0x80U)
#define ADC_SC1B_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1B_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1B_COCO_SHIFT)) & ADC_SC1B_COCO_MASK)
/*! @} */

/*! @name SC1C - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1C_ADCH_MASK                       (0x3FU)
#define ADC_SC1C_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1C_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1C_ADCH_SHIFT)) & ADC_SC1C_ADCH_MASK)

#define ADC_SC1C_AIEN_MASK                       (0x40U)
#define ADC_SC1C_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1C_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1C_AIEN_SHIFT)) & ADC_SC1C_AIEN_MASK)

#define ADC_SC1C_COCO_MASK                       (0x80U)
#define ADC_SC1C_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1C_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1C_COCO_SHIFT)) & ADC_SC1C_COCO_MASK)
/*! @} */

/*! @name SC1D - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1D_ADCH_MASK                       (0x3FU)
#define ADC_SC1D_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1D_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1D_ADCH_SHIFT)) & ADC_SC1D_ADCH_MASK)

#define ADC_SC1D_AIEN_MASK                       (0x40U)
#define ADC_SC1D_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1D_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1D_AIEN_SHIFT)) & ADC_SC1D_AIEN_MASK)

#define ADC_SC1D_COCO_MASK                       (0x80U)
#define ADC_SC1D_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1D_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1D_COCO_SHIFT)) & ADC_SC1D_COCO_MASK)
/*! @} */

/*! @name SC1E - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1E_ADCH_MASK                       (0x3FU)
#define ADC_SC1E_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1E_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1E_ADCH_SHIFT)) & ADC_SC1E_ADCH_MASK)

#define ADC_SC1E_AIEN_MASK                       (0x40U)
#define ADC_SC1E_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1E_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1E_AIEN_SHIFT)) & ADC_SC1E_AIEN_MASK)

#define ADC_SC1E_COCO_MASK                       (0x80U)
#define ADC_SC1E_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1E_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1E_COCO_SHIFT)) & ADC_SC1E_COCO_MASK)
/*! @} */

/*! @name SC1F - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1F_ADCH_MASK                       (0x3FU)
#define ADC_SC1F_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1F_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1F_ADCH_SHIFT)) & ADC_SC1F_ADCH_MASK)

#define ADC_SC1F_AIEN_MASK                       (0x40U)
#define ADC_SC1F_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1F_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1F_AIEN_SHIFT)) & ADC_SC1F_AIEN_MASK)

#define ADC_SC1F_COCO_MASK                       (0x80U)
#define ADC_SC1F_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1F_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1F_COCO_SHIFT)) & ADC_SC1F_COCO_MASK)
/*! @} */

/*! @name SC1G - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1G_ADCH_MASK                       (0x3FU)
#define ADC_SC1G_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1G_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1G_ADCH_SHIFT)) & ADC_SC1G_ADCH_MASK)

#define ADC_SC1G_AIEN_MASK                       (0x40U)
#define ADC_SC1G_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1G_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1G_AIEN_SHIFT)) & ADC_SC1G_AIEN_MASK)

#define ADC_SC1G_COCO_MASK                       (0x80U)
#define ADC_SC1G_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1G_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1G_COCO_SHIFT)) & ADC_SC1G_COCO_MASK)
/*! @} */

/*! @name SC1H - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1H_ADCH_MASK                       (0x3FU)
#define ADC_SC1H_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1H_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1H_ADCH_SHIFT)) & ADC_SC1H_ADCH_MASK)

#define ADC_SC1H_AIEN_MASK                       (0x40U)
#define ADC_SC1H_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1H_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1H_AIEN_SHIFT)) & ADC_SC1H_AIEN_MASK)

#define ADC_SC1H_COCO_MASK                       (0x80U)
#define ADC_SC1H_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1H_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1H_COCO_SHIFT)) & ADC_SC1H_COCO_MASK)
/*! @} */

/*! @name SC1I - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1I_ADCH_MASK                       (0x3FU)
#define ADC_SC1I_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1I_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1I_ADCH_SHIFT)) & ADC_SC1I_ADCH_MASK)

#define ADC_SC1I_AIEN_MASK                       (0x40U)
#define ADC_SC1I_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1I_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1I_AIEN_SHIFT)) & ADC_SC1I_AIEN_MASK)

#define ADC_SC1I_COCO_MASK                       (0x80U)
#define ADC_SC1I_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1I_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1I_COCO_SHIFT)) & ADC_SC1I_COCO_MASK)
/*! @} */

/*! @name SC1J - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1J_ADCH_MASK                       (0x3FU)
#define ADC_SC1J_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1J_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1J_ADCH_SHIFT)) & ADC_SC1J_ADCH_MASK)

#define ADC_SC1J_AIEN_MASK                       (0x40U)
#define ADC_SC1J_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1J_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1J_AIEN_SHIFT)) & ADC_SC1J_AIEN_MASK)

#define ADC_SC1J_COCO_MASK                       (0x80U)
#define ADC_SC1J_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1J_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1J_COCO_SHIFT)) & ADC_SC1J_COCO_MASK)
/*! @} */

/*! @name SC1K - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1K_ADCH_MASK                       (0x3FU)
#define ADC_SC1K_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1K_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1K_ADCH_SHIFT)) & ADC_SC1K_ADCH_MASK)

#define ADC_SC1K_AIEN_MASK                       (0x40U)
#define ADC_SC1K_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1K_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1K_AIEN_SHIFT)) & ADC_SC1K_AIEN_MASK)

#define ADC_SC1K_COCO_MASK                       (0x80U)
#define ADC_SC1K_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1K_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1K_COCO_SHIFT)) & ADC_SC1K_COCO_MASK)
/*! @} */

/*! @name SC1L - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1L_ADCH_MASK                       (0x3FU)
#define ADC_SC1L_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1L_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1L_ADCH_SHIFT)) & ADC_SC1L_ADCH_MASK)

#define ADC_SC1L_AIEN_MASK                       (0x40U)
#define ADC_SC1L_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1L_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1L_AIEN_SHIFT)) & ADC_SC1L_AIEN_MASK)

#define ADC_SC1L_COCO_MASK                       (0x80U)
#define ADC_SC1L_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1L_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1L_COCO_SHIFT)) & ADC_SC1L_COCO_MASK)
/*! @} */

/*! @name SC1M - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1M_ADCH_MASK                       (0x3FU)
#define ADC_SC1M_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1M_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1M_ADCH_SHIFT)) & ADC_SC1M_ADCH_MASK)

#define ADC_SC1M_AIEN_MASK                       (0x40U)
#define ADC_SC1M_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1M_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1M_AIEN_SHIFT)) & ADC_SC1M_AIEN_MASK)

#define ADC_SC1M_COCO_MASK                       (0x80U)
#define ADC_SC1M_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1M_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1M_COCO_SHIFT)) & ADC_SC1M_COCO_MASK)
/*! @} */

/*! @name SC1N - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1N_ADCH_MASK                       (0x3FU)
#define ADC_SC1N_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1N_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1N_ADCH_SHIFT)) & ADC_SC1N_ADCH_MASK)

#define ADC_SC1N_AIEN_MASK                       (0x40U)
#define ADC_SC1N_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1N_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1N_AIEN_SHIFT)) & ADC_SC1N_AIEN_MASK)

#define ADC_SC1N_COCO_MASK                       (0x80U)
#define ADC_SC1N_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1N_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1N_COCO_SHIFT)) & ADC_SC1N_COCO_MASK)
/*! @} */

/*! @name SC1O - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1O_ADCH_MASK                       (0x3FU)
#define ADC_SC1O_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1O_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1O_ADCH_SHIFT)) & ADC_SC1O_ADCH_MASK)

#define ADC_SC1O_AIEN_MASK                       (0x40U)
#define ADC_SC1O_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1O_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1O_AIEN_SHIFT)) & ADC_SC1O_AIEN_MASK)

#define ADC_SC1O_COCO_MASK                       (0x80U)
#define ADC_SC1O_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1O_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1O_COCO_SHIFT)) & ADC_SC1O_COCO_MASK)
/*! @} */

/*! @name SC1P - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1P_ADCH_MASK                       (0x3FU)
#define ADC_SC1P_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1P_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1P_ADCH_SHIFT)) & ADC_SC1P_ADCH_MASK)

#define ADC_SC1P_AIEN_MASK                       (0x40U)
#define ADC_SC1P_AIEN_SHIFT                      (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1P_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1P_AIEN_SHIFT)) & ADC_SC1P_AIEN_MASK)

#define ADC_SC1P_COCO_MASK                       (0x80U)
#define ADC_SC1P_COCO_SHIFT                      (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1P_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC1P_COCO_SHIFT)) & ADC_SC1P_COCO_MASK)
/*! @} */

/*! @name CFG1 - ADC Configuration Register 1 */
/*! @{ */

#define ADC_CFG1_ADICLK_MASK                     (0x3U)
#define ADC_CFG1_ADICLK_SHIFT                    (0U)
/*! ADICLK - Input Clock Select
 *  0b00..Alternate clock 1 (ALTCLK1)
 *  0b01..Alternate clock 2 (ALTCLK2)
 *  0b10..Alternate clock 3 (ALTCLK3)
 *  0b11..Alternate clock 4 (ALTCLK4)
 */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_ADICLK_SHIFT)) & ADC_CFG1_ADICLK_MASK)

#define ADC_CFG1_MODE_MASK                       (0xCU)
#define ADC_CFG1_MODE_SHIFT                      (2U)
/*! MODE - Conversion mode selection
 *  0b00..8-bit conversion.
 *  0b01..12-bit conversion.
 *  0b10..10-bit conversion.
 *  0b11..Reserved
 */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_MODE_SHIFT)) & ADC_CFG1_MODE_MASK)

#define ADC_CFG1_ADIV_MASK                       (0x60U)
#define ADC_CFG1_ADIV_SHIFT                      (5U)
/*! ADIV - Clock Divide Select
 *  0b00..The divide ratio is 1 and the clock rate is input clock.
 *  0b01..The divide ratio is 2 and the clock rate is (input clock)/2.
 *  0b10..The divide ratio is 4 and the clock rate is (input clock)/4.
 *  0b11..The divide ratio is 8 and the clock rate is (input clock)/8.
 */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_ADIV_SHIFT)) & ADC_CFG1_ADIV_MASK)

#define ADC_CFG1_CLRLTRG_MASK                    (0x100U)
#define ADC_CFG1_CLRLTRG_SHIFT                   (8U)
/*! CLRLTRG - Clear Latch Trigger in Trigger Handler Block */
#define ADC_CFG1_CLRLTRG(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_CLRLTRG_SHIFT)) & ADC_CFG1_CLRLTRG_MASK)
/*! @} */

/*! @name CFG2 - ADC Configuration Register 2 */
/*! @{ */

#define ADC_CFG2_SMPLTS_MASK                     (0xFFU)
#define ADC_CFG2_SMPLTS_SHIFT                    (0U)
/*! SMPLTS - Sample Time Select */
#define ADC_CFG2_SMPLTS(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG2_SMPLTS_SHIFT)) & ADC_CFG2_SMPLTS_MASK)
/*! @} */

/*! @name RA - ADC Data Result Registers */
/*! @{ */

#define ADC_RA_D_MASK                            (0xFFFU)
#define ADC_RA_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RA_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RA_D_SHIFT)) & ADC_RA_D_MASK)
/*! @} */

/*! @name RB - ADC Data Result Registers */
/*! @{ */

#define ADC_RB_D_MASK                            (0xFFFU)
#define ADC_RB_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RB_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RB_D_SHIFT)) & ADC_RB_D_MASK)
/*! @} */

/*! @name RC - ADC Data Result Registers */
/*! @{ */

#define ADC_RC_D_MASK                            (0xFFFU)
#define ADC_RC_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RC_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RC_D_SHIFT)) & ADC_RC_D_MASK)
/*! @} */

/*! @name RD - ADC Data Result Registers */
/*! @{ */

#define ADC_RD_D_MASK                            (0xFFFU)
#define ADC_RD_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RD_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RD_D_SHIFT)) & ADC_RD_D_MASK)
/*! @} */

/*! @name RE - ADC Data Result Registers */
/*! @{ */

#define ADC_RE_D_MASK                            (0xFFFU)
#define ADC_RE_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RE_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RE_D_SHIFT)) & ADC_RE_D_MASK)
/*! @} */

/*! @name RF - ADC Data Result Registers */
/*! @{ */

#define ADC_RF_D_MASK                            (0xFFFU)
#define ADC_RF_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RF_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RF_D_SHIFT)) & ADC_RF_D_MASK)
/*! @} */

/*! @name RG - ADC Data Result Registers */
/*! @{ */

#define ADC_RG_D_MASK                            (0xFFFU)
#define ADC_RG_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RG_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RG_D_SHIFT)) & ADC_RG_D_MASK)
/*! @} */

/*! @name RH - ADC Data Result Registers */
/*! @{ */

#define ADC_RH_D_MASK                            (0xFFFU)
#define ADC_RH_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RH_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RH_D_SHIFT)) & ADC_RH_D_MASK)
/*! @} */

/*! @name RI - ADC Data Result Registers */
/*! @{ */

#define ADC_RI_D_MASK                            (0xFFFU)
#define ADC_RI_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RI_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RI_D_SHIFT)) & ADC_RI_D_MASK)
/*! @} */

/*! @name RJ - ADC Data Result Registers */
/*! @{ */

#define ADC_RJ_D_MASK                            (0xFFFU)
#define ADC_RJ_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RJ_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RJ_D_SHIFT)) & ADC_RJ_D_MASK)
/*! @} */

/*! @name RK - ADC Data Result Registers */
/*! @{ */

#define ADC_RK_D_MASK                            (0xFFFU)
#define ADC_RK_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RK_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RK_D_SHIFT)) & ADC_RK_D_MASK)
/*! @} */

/*! @name RL - ADC Data Result Registers */
/*! @{ */

#define ADC_RL_D_MASK                            (0xFFFU)
#define ADC_RL_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RL_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RL_D_SHIFT)) & ADC_RL_D_MASK)
/*! @} */

/*! @name RM - ADC Data Result Registers */
/*! @{ */

#define ADC_RM_D_MASK                            (0xFFFU)
#define ADC_RM_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RM_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RM_D_SHIFT)) & ADC_RM_D_MASK)
/*! @} */

/*! @name RN - ADC Data Result Registers */
/*! @{ */

#define ADC_RN_D_MASK                            (0xFFFU)
#define ADC_RN_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RN_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RN_D_SHIFT)) & ADC_RN_D_MASK)
/*! @} */

/*! @name RO - ADC Data Result Registers */
/*! @{ */

#define ADC_RO_D_MASK                            (0xFFFU)
#define ADC_RO_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RO_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RO_D_SHIFT)) & ADC_RO_D_MASK)
/*! @} */

/*! @name RP - ADC Data Result Registers */
/*! @{ */

#define ADC_RP_D_MASK                            (0xFFFU)
#define ADC_RP_D_SHIFT                           (0U)
/*! D - Data result */
#define ADC_RP_D(x)                              (((uint32_t)(((uint32_t)(x)) << ADC_RP_D_SHIFT)) & ADC_RP_D_MASK)
/*! @} */

/*! @name CV1 - Compare Value Registers */
/*! @{ */

#define ADC_CV1_CV_MASK                          (0xFFFFU)
#define ADC_CV1_CV_SHIFT                         (0U)
/*! CV - Compare Value. */
#define ADC_CV1_CV(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV1_CV_SHIFT)) & ADC_CV1_CV_MASK)
/*! @} */

/*! @name CV2 - Compare Value Registers */
/*! @{ */

#define ADC_CV2_CV_MASK                          (0xFFFFU)
#define ADC_CV2_CV_SHIFT                         (0U)
/*! CV - Compare Value. */
#define ADC_CV2_CV(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV2_CV_SHIFT)) & ADC_CV2_CV_MASK)
/*! @} */

/*! @name SC2 - Status and Control Register 2 */
/*! @{ */

#define ADC_SC2_REFSEL_MASK                      (0x3U)
#define ADC_SC2_REFSEL_SHIFT                     (0U)
/*! REFSEL - Voltage Reference Selection
 *  0b00..Default voltage reference pin pair, that is, external pins VREFH and VREFL
 *  0b01..Alternate reference voltage, that is, VALTH. This voltage may be additional external pin or internal
 *        source depending on the MCU configuration. See the chip configuration information for details specific to
 *        this MCU.
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC2_REFSEL_SHIFT)) & ADC_SC2_REFSEL_MASK)

#define ADC_SC2_DMAEN_MASK                       (0x4U)
#define ADC_SC2_DMAEN_SHIFT                      (2U)
/*! DMAEN - DMA Enable
 *  0b0..DMA is disabled.
 *  0b1..DMA is enabled and will assert the ADC DMA request during an ADC conversion complete event , which is
 *       indicated when any SC1n[COCO] flag is asserted.
 */
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_DMAEN_SHIFT)) & ADC_SC2_DMAEN_MASK)

#define ADC_SC2_ACREN_MASK                       (0x8U)
#define ADC_SC2_ACREN_SHIFT                      (3U)
/*! ACREN - Compare Function Range Enable */
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ACREN_SHIFT)) & ADC_SC2_ACREN_MASK)

#define ADC_SC2_ACFGT_MASK                       (0x10U)
#define ADC_SC2_ACFGT_SHIFT                      (4U)
/*! ACFGT - Compare Function Greater Than Enable */
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ACFGT_SHIFT)) & ADC_SC2_ACFGT_MASK)

#define ADC_SC2_ACFE_MASK                        (0x20U)
#define ADC_SC2_ACFE_SHIFT                       (5U)
/*! ACFE - Compare Function Enable
 *  0b0..Compare function disabled.
 *  0b1..Compare function enabled.
 */
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ACFE_SHIFT)) & ADC_SC2_ACFE_MASK)

#define ADC_SC2_ADTRG_MASK                       (0x40U)
#define ADC_SC2_ADTRG_SHIFT                      (6U)
/*! ADTRG - Conversion Trigger Select
 *  0b0..Software trigger selected.
 *  0b1..Hardware trigger selected.
 */
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ADTRG_SHIFT)) & ADC_SC2_ADTRG_MASK)

#define ADC_SC2_ADACT_MASK                       (0x80U)
#define ADC_SC2_ADACT_SHIFT                      (7U)
/*! ADACT - Conversion Active
 *  0b0..Conversion not in progress.
 *  0b1..Conversion in progress.
 */
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ADACT_SHIFT)) & ADC_SC2_ADACT_MASK)

#define ADC_SC2_TRGPRNUM_MASK                    (0x6000U)
#define ADC_SC2_TRGPRNUM_SHIFT                   (13U)
/*! TRGPRNUM - Trigger Process Number */
#define ADC_SC2_TRGPRNUM(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SC2_TRGPRNUM_SHIFT)) & ADC_SC2_TRGPRNUM_MASK)

#define ADC_SC2_TRGSTLAT_MASK                    (0xF0000U)
#define ADC_SC2_TRGSTLAT_SHIFT                   (16U)
/*! TRGSTLAT - Trigger Status
 *  0b0000..No trigger request has been latched
 *  0b0001..A trigger request has been latched
 */
#define ADC_SC2_TRGSTLAT(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SC2_TRGSTLAT_SHIFT)) & ADC_SC2_TRGSTLAT_MASK)

#define ADC_SC2_TRGSTERR_MASK                    (0xF000000U)
#define ADC_SC2_TRGSTERR_SHIFT                   (24U)
/*! TRGSTERR - Error in Multiplexed Trigger Request
 *  0b0000..No error has occurred
 *  0b0001..An error has occurred
 */
#define ADC_SC2_TRGSTERR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SC2_TRGSTERR_SHIFT)) & ADC_SC2_TRGSTERR_MASK)
/*! @} */

/*! @name SC3 - Status and Control Register 3 */
/*! @{ */

#define ADC_SC3_AVGS_MASK                        (0x3U)
#define ADC_SC3_AVGS_SHIFT                       (0U)
/*! AVGS - Hardware Average Select
 *  0b00..4 samples averaged.
 *  0b01..8 samples averaged.
 *  0b10..16 samples averaged.
 *  0b11..32 samples averaged.
 */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_AVGS_SHIFT)) & ADC_SC3_AVGS_MASK)

#define ADC_SC3_AVGE_MASK                        (0x4U)
#define ADC_SC3_AVGE_SHIFT                       (2U)
/*! AVGE - Hardware Average Enable
 *  0b0..Hardware average function disabled.
 *  0b1..Hardware average function enabled.
 */
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_AVGE_SHIFT)) & ADC_SC3_AVGE_MASK)

#define ADC_SC3_ADCO_MASK                        (0x8U)
#define ADC_SC3_ADCO_SHIFT                       (3U)
/*! ADCO - Continuous Conversion Enable
 *  0b0..One conversion will be performed (or one set of conversions, if AVGE is set) after a conversion is initiated.
 *  0b1..Continuous conversions will be performed (or continuous sets of conversions, if AVGE is set) after a conversion is initiated.
 */
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_ADCO_SHIFT)) & ADC_SC3_ADCO_MASK)

#define ADC_SC3_CAL_MASK                         (0x80U)
#define ADC_SC3_CAL_SHIFT                        (7U)
/*! CAL - Calibration */
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_SC3_CAL_SHIFT)) & ADC_SC3_CAL_MASK)
/*! @} */

/*! @name BASE_OFS - BASE Offset Register */
/*! @{ */

#define ADC_BASE_OFS_BA_OFS_MASK                 (0xFFU)
#define ADC_BASE_OFS_BA_OFS_SHIFT                (0U)
/*! BA_OFS - Base Offset Error Correction Value */
#define ADC_BASE_OFS_BA_OFS(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_BASE_OFS_BA_OFS_SHIFT)) & ADC_BASE_OFS_BA_OFS_MASK)
/*! @} */

/*! @name OFS - ADC Offset Correction Register */
/*! @{ */

#define ADC_OFS_OFS_MASK                         (0xFFFFU)
#define ADC_OFS_OFS_SHIFT                        (0U)
/*! OFS - Offset Error Correction Value */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_OFS_OFS_SHIFT)) & ADC_OFS_OFS_MASK)
/*! @} */

/*! @name USR_OFS - USER Offset Correction Register */
/*! @{ */

#define ADC_USR_OFS_USR_OFS_MASK                 (0xFFU)
#define ADC_USR_OFS_USR_OFS_SHIFT                (0U)
/*! USR_OFS - USER Offset Error Correction Value */
#define ADC_USR_OFS_USR_OFS(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_USR_OFS_USR_OFS_SHIFT)) & ADC_USR_OFS_USR_OFS_MASK)
/*! @} */

/*! @name XOFS - ADC X Offset Correction Register */
/*! @{ */

#define ADC_XOFS_XOFS_MASK                       (0x3FU)
#define ADC_XOFS_XOFS_SHIFT                      (0U)
/*! XOFS - X offset error correction value */
#define ADC_XOFS_XOFS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_XOFS_XOFS_SHIFT)) & ADC_XOFS_XOFS_MASK)
/*! @} */

/*! @name YOFS - ADC Y Offset Correction Register */
/*! @{ */

#define ADC_YOFS_YOFS_MASK                       (0xFFU)
#define ADC_YOFS_YOFS_SHIFT                      (0U)
/*! YOFS - Y offset error correction value */
#define ADC_YOFS_YOFS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_YOFS_YOFS_SHIFT)) & ADC_YOFS_YOFS_MASK)
/*! @} */

/*! @name GAIN - ADC Gain Register */
/*! @{ */

#define ADC_GAIN_GAIN_MASK                       (0x7FFU)
#define ADC_GAIN_GAIN_SHIFT                      (0U)
/*! GAIN - GAIN */
#define ADC_GAIN_GAIN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_GAIN_GAIN_SHIFT)) & ADC_GAIN_GAIN_MASK)
/*! @} */

/*! @name UG - ADC User Gain Register */
/*! @{ */

#define ADC_UG_UG_MASK                           (0x3FFU)
#define ADC_UG_UG_SHIFT                          (0U)
/*! UG - UG */
#define ADC_UG_UG(x)                             (((uint32_t)(((uint32_t)(x)) << ADC_UG_UG_SHIFT)) & ADC_UG_UG_MASK)
/*! @} */

/*! @name CLPS - ADC General Calibration Value Register S */
/*! @{ */

#define ADC_CLPS_CLPS_MASK                       (0x7FU)
#define ADC_CLPS_CLPS_SHIFT                      (0U)
/*! CLPS - CLPS */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLPS_CLPS_SHIFT)) & ADC_CLPS_CLPS_MASK)
/*! @} */

/*! @name CLP3 - ADC Plus-Side General Calibration Value Register 3 */
/*! @{ */

#define ADC_CLP3_CLP3_MASK                       (0x3FFU)
#define ADC_CLP3_CLP3_SHIFT                      (0U)
/*! CLP3 - CLP3 */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP3_CLP3_SHIFT)) & ADC_CLP3_CLP3_MASK)
/*! @} */

/*! @name CLP2 - ADC Plus-Side General Calibration Value Register 2 */
/*! @{ */

#define ADC_CLP2_CLP2_MASK                       (0x3FFU)
#define ADC_CLP2_CLP2_SHIFT                      (0U)
/*! CLP2 - CLP2 */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP2_CLP2_SHIFT)) & ADC_CLP2_CLP2_MASK)
/*! @} */

/*! @name CLP1 - ADC Plus-Side General Calibration Value Register 1 */
/*! @{ */

#define ADC_CLP1_CLP1_MASK                       (0x1FFU)
#define ADC_CLP1_CLP1_SHIFT                      (0U)
/*! CLP1 - CLP1 */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP1_CLP1_SHIFT)) & ADC_CLP1_CLP1_MASK)
/*! @} */

/*! @name CLP0 - ADC Plus-Side General Calibration Value Register 0 */
/*! @{ */

#define ADC_CLP0_CLP0_MASK                       (0xFFU)
#define ADC_CLP0_CLP0_SHIFT                      (0U)
/*! CLP0 - CLP0 */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP0_CLP0_SHIFT)) & ADC_CLP0_CLP0_MASK)
/*! @} */

/*! @name CLPX - ADC Plus-Side General Calibration Value Register X */
/*! @{ */

#define ADC_CLPX_CLPX_MASK                       (0x7FU)
#define ADC_CLPX_CLPX_SHIFT                      (0U)
/*! CLPX - CLPX */
#define ADC_CLPX_CLPX(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLPX_CLPX_SHIFT)) & ADC_CLPX_CLPX_MASK)
/*! @} */

/*! @name CLP9 - ADC Plus-Side General Calibration Value Register 9 */
/*! @{ */

#define ADC_CLP9_CLP9_MASK                       (0x7FU)
#define ADC_CLP9_CLP9_SHIFT                      (0U)
/*! CLP9 - CLP9 */
#define ADC_CLP9_CLP9(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP9_CLP9_SHIFT)) & ADC_CLP9_CLP9_MASK)
/*! @} */

/*! @name CLPS_OFS - ADC General Calibration Offset Value Register S */
/*! @{ */

#define ADC_CLPS_OFS_CLPS_OFS_MASK               (0xFU)
#define ADC_CLPS_OFS_CLPS_OFS_SHIFT              (0U)
/*! CLPS_OFS - CLPS Offset */
#define ADC_CLPS_OFS_CLPS_OFS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CLPS_OFS_CLPS_OFS_SHIFT)) & ADC_CLPS_OFS_CLPS_OFS_MASK)
/*! @} */

/*! @name CLP3_OFS - ADC Plus-Side General Calibration Offset Value Register 3 */
/*! @{ */

#define ADC_CLP3_OFS_CLP3_OFS_MASK               (0xFU)
#define ADC_CLP3_OFS_CLP3_OFS_SHIFT              (0U)
/*! CLP3_OFS - CLP3 Offset */
#define ADC_CLP3_OFS_CLP3_OFS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CLP3_OFS_CLP3_OFS_SHIFT)) & ADC_CLP3_OFS_CLP3_OFS_MASK)
/*! @} */

/*! @name CLP2_OFS - ADC Plus-Side General Calibration Offset Value Register 2 */
/*! @{ */

#define ADC_CLP2_OFS_CLP2_OFS_MASK               (0xFU)
#define ADC_CLP2_OFS_CLP2_OFS_SHIFT              (0U)
/*! CLP2_OFS - CLP2 Offset */
#define ADC_CLP2_OFS_CLP2_OFS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CLP2_OFS_CLP2_OFS_SHIFT)) & ADC_CLP2_OFS_CLP2_OFS_MASK)
/*! @} */

/*! @name CLP1_OFS - ADC Plus-Side General Calibration Offset Value Register 1 */
/*! @{ */

#define ADC_CLP1_OFS_CLP1_OFS_MASK               (0xFU)
#define ADC_CLP1_OFS_CLP1_OFS_SHIFT              (0U)
/*! CLP1_OFS - CLP1 Offset */
#define ADC_CLP1_OFS_CLP1_OFS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CLP1_OFS_CLP1_OFS_SHIFT)) & ADC_CLP1_OFS_CLP1_OFS_MASK)
/*! @} */

/*! @name CLP0_OFS - ADC Plus-Side General Calibration Offset Value Register 0 */
/*! @{ */

#define ADC_CLP0_OFS_CLP0_OFS_MASK               (0xFU)
#define ADC_CLP0_OFS_CLP0_OFS_SHIFT              (0U)
/*! CLP0_OFS - CLP0 Offset */
#define ADC_CLP0_OFS_CLP0_OFS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CLP0_OFS_CLP0_OFS_SHIFT)) & ADC_CLP0_OFS_CLP0_OFS_MASK)
/*! @} */

/*! @name CLPX_OFS - ADC Plus-Side General Calibration Offset Value Register X */
/*! @{ */

#define ADC_CLPX_OFS_CLPX_OFS_MASK               (0xFFFU)
#define ADC_CLPX_OFS_CLPX_OFS_SHIFT              (0U)
/*! CLPX_OFS - CLPX Offset */
#define ADC_CLPX_OFS_CLPX_OFS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CLPX_OFS_CLPX_OFS_SHIFT)) & ADC_CLPX_OFS_CLPX_OFS_MASK)
/*! @} */

/*! @name CLP9_OFS - ADC Plus-Side General Calibration Offset Value Register 9 */
/*! @{ */

#define ADC_CLP9_OFS_CLP9_OFS_MASK               (0xFFFU)
#define ADC_CLP9_OFS_CLP9_OFS_SHIFT              (0U)
/*! CLP9_OFS - CLP9 Offset */
#define ADC_CLP9_OFS_CLP9_OFS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CLP9_OFS_CLP9_OFS_SHIFT)) & ADC_CLP9_OFS_CLP9_OFS_MASK)
/*! @} */

/*! @name SC1 - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1_ADCH_MASK                        (0x3FU)
#define ADC_SC1_ADCH_SHIFT                       (0U)
/*! ADCH - Input channel select
 *  0b000000..External channel 0 is selected as input.
 *  0b000001..External channel 1 is selected as input.
 *  0b000010..External channel 2 is selected as input.
 *  0b000011..External channel 3 is selected as input.
 *  0b000100..External channel 4 is selected as input.
 *  0b000101..External channel 5 is selected as input.
 *  0b000110..External channel 6 is selected as input.
 *  0b000111..External channel 7 is selected as input.
 *  0b001000..External channel 8 is selected as input.
 *  0b001001..External channel 9 is selected as input.
 *  0b001010..External channel 10 is selected as input.
 *  0b001011..External channel 11 is selected as input.
 *  0b001100..External channel 12 is selected as input.
 *  0b001101..External channel 13 is selected as input.
 *  0b001110..External channel 14 is selected as input.
 *  0b001111..External channel 15 is selected as input.
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Internal channel 0 is selected as input.
 *  0b010110..Internal channel 1 is selected as input.
 *  0b010111..Internal channel 2 is selected as input.
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Band Gap
 *  0b011100..Internal channel 3 is selected as input.
 *  0b011101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b011111..Reserved
 *  0b100000..External channel 16 is selected as input.
 *  0b100001..External channel 17 is selected as input.
 *  0b100010..External channel 18 is selected as input.
 *  0b100011..External channel 19 is selected as input.
 *  0b100100..External channel 20 is selected as input.
 *  0b100101..External channel 21 is selected as input.
 *  0b100110..External channel 22 is selected as input.
 *  0b100111..External channel 23 is selected as input.
 *  0b101000..External channel 24 is selected as input.
 *  0b101001..External channel 25 is selected as input.
 *  0b101010..External channel 26 is selected as input.
 *  0b101011..External channel 27 is selected as input.
 *  0b101100..External channel 28 is selected as input.
 *  0b101101..External channel 29 is selected as input.
 *  0b101110..External channel 30 is selected as input.
 *  0b101111..External channel 31 is selected as input.
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 *  0b111110..Reserved
 *  0b111111..Reserved
 */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_ADCH_SHIFT)) & ADC_SC1_ADCH_MASK)

#define ADC_SC1_AIEN_MASK                        (0x40U)
#define ADC_SC1_AIEN_SHIFT                       (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_AIEN_SHIFT)) & ADC_SC1_AIEN_MASK)

#define ADC_SC1_COCO_MASK                        (0x80U)
#define ADC_SC1_COCO_SHIFT                       (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_COCO_SHIFT)) & ADC_SC1_COCO_MASK)
/*! @} */

/*! @name R - ADC Data Result Registers */
/*! @{ */

#define ADC_R_D_MASK                             (0xFFFU)
#define ADC_R_D_SHIFT                            (0U)
/*! D - Data result */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x)) << ADC_R_D_SHIFT)) & ADC_R_D_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


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


#endif  /* PERI_ADC_H_ */

