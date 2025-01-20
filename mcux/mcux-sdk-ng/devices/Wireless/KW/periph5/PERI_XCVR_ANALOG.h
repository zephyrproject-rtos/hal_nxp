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
**         CMSIS Peripheral Access Layer for XCVR_ANALOG
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
 * @file XCVR_ANALOG.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_ANALOG
 *
 * CMSIS Peripheral Access Layer for XCVR_ANALOG
 */

#if !defined(XCVR_ANALOG_H_)
#define XCVR_ANALOG_H_                           /**< Symbol preventing repeated inclusion */

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
   -- XCVR_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ANALOG_Peripheral_Access_Layer XCVR_ANALOG Peripheral Access Layer
 * @{
 */

/** XCVR_ANALOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t BB_LDO_1;                          /**< RF Analog Baseband LDO Control 1, offset: 0x0 */
  __IO uint32_t BB_LDO_2;                          /**< RF Analog Baseband LDO Control 2, offset: 0x4 */
  __IO uint32_t RX_ADC;                            /**< RF Analog ADC Control, offset: 0x8 */
  __IO uint32_t RX_BBA;                            /**< RF Analog BBA Control, offset: 0xC */
  __IO uint32_t RX_LNA;                            /**< RF Analog LNA Control, offset: 0x10 */
  __IO uint32_t RX_TZA;                            /**< RF Analog TZA Control, offset: 0x14 */
  __IO uint32_t RX_AUXPLL;                         /**< RF Analog Aux PLL Control, offset: 0x18 */
  __IO uint32_t SY_CTRL_1;                         /**< RF Analog Synthesizer Control 1, offset: 0x1C */
  __IO uint32_t SY_CTRL_2;                         /**< RF Analog Synthesizer Control 2, offset: 0x20 */
  __IO uint32_t TX_DAC_PA;                         /**< RF Analog TX HPM DAC and PA Control, offset: 0x24 */
  __IO uint32_t BALUN_TX;                          /**< RF Analog Balun TX Mode Control, offset: 0x28 */
  __IO uint32_t BALUN_RX;                          /**< RF Analog Balun RX Mode Control, offset: 0x2C */
  __I  uint32_t DFT_OBSV_1;                        /**< RF Analog DFT Observation Register 1, offset: 0x30 */
  __IO uint32_t DFT_OBSV_2;                        /**< RF Analog DFT Observation Register 2, offset: 0x34 */
} XCVR_ANALOG_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_ANALOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ANALOG_Register_Masks XCVR_ANALOG Register Masks
 * @{
 */

/*! @name BB_LDO_1 - RF Analog Baseband LDO Control 1 */
/*! @{ */

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_BYP_MASK (0x1U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_BYP_SHIFT (0U)
/*! BB_LDO_ADCDAC_BYP - rmap_bb_ldo_adcdac_byp
 *  0b0..Bypass disabled.
 *  0b1..Bypass enabled
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_BYP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_BYP_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_BYP_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_DIAGSEL_MASK (0x2U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_DIAGSEL_SHIFT (1U)
/*! BB_LDO_ADCDAC_DIAGSEL - rmap_bb_ldo_adcdac_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_DIAGSEL_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_DIAGSEL_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_SPARE_MASK (0xCU)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_SPARE_SHIFT (2U)
/*! BB_LDO_ADCDAC_SPARE - rmap_bb_ldo_adcdac_spare[1:0] */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_SPARE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_SPARE_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_SPARE_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_TRIM_MASK (0x70U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_TRIM_SHIFT (4U)
/*! BB_LDO_ADCDAC_TRIM - rmap_bb_ldo_adcdac_trim[2:0]
 *  0b000..1.20 V ( Default )
 *  0b001..1.25 V
 *  0b010..1.28 V
 *  0b011..1.33 V
 *  0b100..1.40 V
 *  0b101..1.44 V
 *  0b110..1.50 V
 *  0b111..1.66 V
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_TRIM(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_TRIM_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_ADCDAC_TRIM_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_BYP_MASK (0x100U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_BYP_SHIFT (8U)
/*! BB_LDO_BBA_BYP - rmap_bb_ldo_bba_byp
 *  0b0..Bypass disabled.
 *  0b1..Bypass enabled
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_BYP(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_BYP_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_BYP_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_DIAGSEL_MASK (0x200U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_DIAGSEL_SHIFT (9U)
/*! BB_LDO_BBA_DIAGSEL - rmap_bb_ldo_bba_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_DIAGSEL_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_DIAGSEL_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_SPARE_MASK (0xC00U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_SPARE_SHIFT (10U)
/*! BB_LDO_BBA_SPARE - rmap_bb_ldo_bba_spare[1:0] */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_SPARE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_SPARE_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_SPARE_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_TRIM_MASK (0x7000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_TRIM_SHIFT (12U)
/*! BB_LDO_BBA_TRIM - rmap_bb_ldo_bba_trim[2:0]
 *  0b000..1.20 V ( Default )
 *  0b001..1.25 V
 *  0b010..1.28 V
 *  0b011..1.33 V
 *  0b100..1.40 V
 *  0b101..1.44 V
 *  0b110..1.50 V
 *  0b111..1.66 V
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_TRIM(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_TRIM_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_BBA_TRIM_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_BYP_MASK (0x10000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_BYP_SHIFT (16U)
/*! BB_LDO_FDBK_BYP - rmap_bb_ldo_fdbk_byp
 *  0b0..Bypass disabled.
 *  0b1..Bypass enabled
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_BYP(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_BYP_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_BYP_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_DIAGSEL_MASK (0x20000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_DIAGSEL_SHIFT (17U)
/*! BB_LDO_FDBK_DIAGSEL - rmap_bb_ldo_fdbk_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_DIAGSEL_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_DIAGSEL_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_SPARE_MASK (0xC0000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_SPARE_SHIFT (18U)
/*! BB_LDO_FDBK_SPARE - rmap_bb_ldo_fdbk_spare[1:0] */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_SPARE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_SPARE_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_SPARE_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_TRIM_MASK (0x700000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_TRIM_SHIFT (20U)
/*! BB_LDO_FDBK_TRIM - rmap_bb_ldo_fdbk_trim[2:0]
 *  0b000..1.2/1.176 V ( Default )
 *  0b001..1.138/1.115 V
 *  0b010..1.085/1.066 V
 *  0b011..1.04/1.025 V
 *  0b100..1.28/1.25 V
 *  0b101..1.4/1.35 V
 *  0b110..1.55/1.4 V
 *  0b111..1.78/1.4 V
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_TRIM(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_TRIM_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_FDBK_TRIM_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_BYP_MASK  (0x1000000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_BYP_SHIFT (24U)
/*! BB_LDO_HF_BYP - rmap_bb_ldo_hf_byp
 *  0b0..Bypass disabled.
 *  0b1..Bypass enabled
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_BYP(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_BYP_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_BYP_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_DIAGSEL_MASK (0x2000000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_DIAGSEL_SHIFT (25U)
/*! BB_LDO_HF_DIAGSEL - rmap_bb_ldo_hf_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_DIAGSEL_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_DIAGSEL_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_SPARE_MASK (0xC000000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_SPARE_SHIFT (26U)
/*! BB_LDO_HF_SPARE - rmap_bb_ldo_hf_spare[1:0] */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_SPARE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_SPARE_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_SPARE_MASK)

#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_TRIM_MASK (0x70000000U)
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_TRIM_SHIFT (28U)
/*! BB_LDO_HF_TRIM - rmap_bb_ldo_hf_trim[2:0]
 *  0b000..1.20 V ( Default )
 *  0b001..1.25 V
 *  0b010..1.28 V
 *  0b011..1.33 V
 *  0b100..1.40 V
 *  0b101..1.44 V
 *  0b110..1.50 V
 *  0b111..1.66 V
 */
#define XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_TRIM(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_TRIM_SHIFT)) & XCVR_ANALOG_BB_LDO_1_BB_LDO_HF_TRIM_MASK)
/*! @} */

/*! @name BB_LDO_2 - RF Analog Baseband LDO Control 2 */
/*! @{ */

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_BYP_MASK  (0x1U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_BYP_SHIFT (0U)
/*! BB_LDO_PD_BYP - rmap_bb_ldo_pd_byp
 *  0b0..Bypass disabled.
 *  0b1..Bypass enabled
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_BYP(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_BYP_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_BYP_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_DIAGSEL_MASK (0x2U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_DIAGSEL_SHIFT (1U)
/*! BB_LDO_PD_DIAGSEL - rmap_bb_ldo_pd_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_DIAGSEL_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_DIAGSEL_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_SPARE_MASK (0xCU)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_SPARE_SHIFT (2U)
/*! BB_LDO_PD_SPARE - rmap_bb_ldo_pd_spare[1:0] */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_SPARE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_SPARE_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_SPARE_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_TRIM_MASK (0x70U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_TRIM_SHIFT (4U)
/*! BB_LDO_PD_TRIM - rmap_bb_ldo_pd_trim[2:0]
 *  0b000..1.20 V ( Default )
 *  0b001..1.25 V
 *  0b010..1.28 V
 *  0b011..1.33 V
 *  0b100..1.40 V
 *  0b101..1.44 V
 *  0b110..1.50 V
 *  0b111..1.66 V
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_TRIM(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_TRIM_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_PD_TRIM_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCO_SPARE_MASK (0x300U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCO_SPARE_SHIFT (8U)
/*! BB_LDO_VCO_SPARE - rmap_bb_ldo_vco_spare[1:0] */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCO_SPARE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_VCO_SPARE_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_VCO_SPARE_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_BYP_MASK (0x400U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_BYP_SHIFT (10U)
/*! BB_LDO_VCOLO_BYP - rmap_bb_ldo_vcolo_byp
 *  0b0..Bypass disabled.
 *  0b1..Bypass enabled
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_BYP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_BYP_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_BYP_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_DIAGSEL_MASK (0x800U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_DIAGSEL_SHIFT (11U)
/*! BB_LDO_VCOLO_DIAGSEL - rmap_bb_ldo_vcolo_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_DIAGSEL_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_DIAGSEL_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_TRIM_MASK (0x7000U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_TRIM_SHIFT (12U)
/*! BB_LDO_VCOLO_TRIM - rmap_bb_ldo_vcolo_trim[2:0]
 *  0b000..1.138/1.117 V ( Default )
 *  0b001..1.076/1.058 V
 *  0b010..1.027/1.012 V
 *  0b011..0.98/0.97 V
 *  0b100..1.22/1.19 V
 *  0b101..1.33/1.3 V
 *  0b110..1.5/1.4 V
 *  0b111..1.82/1.4 V
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_TRIM(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_TRIM_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_VCOLO_TRIM_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_DIAGSEL_MASK (0x10000U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_DIAGSEL_SHIFT (16U)
/*! BB_LDO_VTREF_DIAGSEL - rmap_bb_ldo_vtref_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_DIAGSEL_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_DIAGSEL_MASK)

#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_TC_MASK (0x60000U)
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_TC_SHIFT (17U)
/*! BB_LDO_VTREF_TC - rmap_bb_ldo_vtref_tc[1:0]
 *  0b00..1.117/1.176 V
 *  0b01..1.134/1.188 V
 *  0b10..1.10/1.162 V
 *  0b11..1.09/1.152 V
 */
#define XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_TC(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_TC_SHIFT)) & XCVR_ANALOG_BB_LDO_2_BB_LDO_VTREF_TC_MASK)
/*! @} */

/*! @name RX_ADC - RF Analog ADC Control */
/*! @{ */

#define XCVR_ANALOG_RX_ADC_RX_ADC_BUMP_MASK      (0xFFU)
#define XCVR_ANALOG_RX_ADC_RX_ADC_BUMP_SHIFT     (0U)
/*! RX_ADC_BUMP - rmap_rx_adc_bump[7:0] */
#define XCVR_ANALOG_RX_ADC_RX_ADC_BUMP(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_ADC_RX_ADC_BUMP_SHIFT)) & XCVR_ANALOG_RX_ADC_RX_ADC_BUMP_MASK)

#define XCVR_ANALOG_RX_ADC_RX_ADC_FS_SEL_MASK    (0x300U)
#define XCVR_ANALOG_RX_ADC_RX_ADC_FS_SEL_SHIFT   (8U)
/*! RX_ADC_FS_SEL - rmap_rx_adc_fs_sel[1:0]
 *  0b00..52MHz (2x26MHz)
 *  0b01..64MHz (2x32MHz)
 *  0b10..+13% of 64MHz
 *  0b11..- 11% of 64MHz
 */
#define XCVR_ANALOG_RX_ADC_RX_ADC_FS_SEL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_ADC_RX_ADC_FS_SEL_SHIFT)) & XCVR_ANALOG_RX_ADC_RX_ADC_FS_SEL_MASK)

#define XCVR_ANALOG_RX_ADC_RX_ADC_I_DIAGSEL_MASK (0x400U)
#define XCVR_ANALOG_RX_ADC_RX_ADC_I_DIAGSEL_SHIFT (10U)
/*! RX_ADC_I_DIAGSEL - rmap_rx_adc_i_diagsel */
#define XCVR_ANALOG_RX_ADC_RX_ADC_I_DIAGSEL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_ADC_RX_ADC_I_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_ADC_RX_ADC_I_DIAGSEL_MASK)

#define XCVR_ANALOG_RX_ADC_RX_ADC_Q_DIAGSEL_MASK (0x800U)
#define XCVR_ANALOG_RX_ADC_RX_ADC_Q_DIAGSEL_SHIFT (11U)
/*! RX_ADC_Q_DIAGSEL - rmap_rx_adc_q_diagsel */
#define XCVR_ANALOG_RX_ADC_RX_ADC_Q_DIAGSEL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_ADC_RX_ADC_Q_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_ADC_RX_ADC_Q_DIAGSEL_MASK)

#define XCVR_ANALOG_RX_ADC_RX_ADC_SPARE_MASK     (0xF000U)
#define XCVR_ANALOG_RX_ADC_RX_ADC_SPARE_SHIFT    (12U)
/*! RX_ADC_SPARE - rmap_rx_adc_spare[3:0] */
#define XCVR_ANALOG_RX_ADC_RX_ADC_SPARE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_ADC_RX_ADC_SPARE_SHIFT)) & XCVR_ANALOG_RX_ADC_RX_ADC_SPARE_MASK)
/*! @} */

/*! @name RX_BBA - RF Analog BBA Control */
/*! @{ */

#define XCVR_ANALOG_RX_BBA_RX_BBA_BW_SEL_MASK    (0x7U)
#define XCVR_ANALOG_RX_BBA_RX_BBA_BW_SEL_SHIFT   (0U)
/*! RX_BBA_BW_SEL - rmap_rx_bba_bw_sel[2:0]
 *  0b000..1000K
 *  0b001..900K
 *  0b010..800K
 *  0b011..700K Default
 *  0b100..600K
 *  0b101..500K
 */
#define XCVR_ANALOG_RX_BBA_RX_BBA_BW_SEL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA_BW_SEL_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA_BW_SEL_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA_CUR_BUMP_MASK  (0x8U)
#define XCVR_ANALOG_RX_BBA_RX_BBA_CUR_BUMP_SHIFT (3U)
/*! RX_BBA_CUR_BUMP - rmap_rx_bba_cur_bump */
#define XCVR_ANALOG_RX_BBA_RX_BBA_CUR_BUMP(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA_CUR_BUMP_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA_CUR_BUMP_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL1_MASK  (0x10U)
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL1_SHIFT (4U)
/*! RX_BBA_DIAGSEL1 - rmap_rx_bba_diagsel1
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL1(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL1_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL1_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL2_MASK  (0x20U)
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL2_SHIFT (5U)
/*! RX_BBA_DIAGSEL2 - rmap_rx_bba_diagsel2
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL2(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL2_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL2_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL3_MASK  (0x40U)
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL3_SHIFT (6U)
/*! RX_BBA_DIAGSEL3 - rmap_rx_bba_diagsel3
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL3(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL3_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL3_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL4_MASK  (0x80U)
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL4_SHIFT (7U)
/*! RX_BBA_DIAGSEL4 - rmap_rx_bba_diagsel4
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL4(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL4_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA_DIAGSEL4_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA_SPARE_MASK     (0x3F0000U)
#define XCVR_ANALOG_RX_BBA_RX_BBA_SPARE_SHIFT    (16U)
/*! RX_BBA_SPARE - rmap_rx_bba_spare[5:0]
 *  0b000000..600mV (Default)
 *  0b000001..675mV
 *  0b000010..450mV
 *  0b000011..525mV
 */
#define XCVR_ANALOG_RX_BBA_RX_BBA_SPARE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA_SPARE_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA_SPARE_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA2_BW_SEL_MASK   (0x7000000U)
#define XCVR_ANALOG_RX_BBA_RX_BBA2_BW_SEL_SHIFT  (24U)
/*! RX_BBA2_BW_SEL - rmap_bba2_bw_sel[2:0]
 *  0b000..1000K
 *  0b001..900K
 *  0b010..800K
 *  0b011..700K Default
 *  0b100..600K
 *  0b101..500K
 */
#define XCVR_ANALOG_RX_BBA_RX_BBA2_BW_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA2_BW_SEL_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA2_BW_SEL_MASK)

#define XCVR_ANALOG_RX_BBA_RX_BBA2_SPARE_MASK    (0x70000000U)
#define XCVR_ANALOG_RX_BBA_RX_BBA2_SPARE_SHIFT   (28U)
/*! RX_BBA2_SPARE - rmap_rx_bba2_spare[2:0] */
#define XCVR_ANALOG_RX_BBA_RX_BBA2_SPARE(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_BBA_RX_BBA2_SPARE_SHIFT)) & XCVR_ANALOG_RX_BBA_RX_BBA2_SPARE_MASK)
/*! @} */

/*! @name RX_LNA - RF Analog LNA Control */
/*! @{ */

#define XCVR_ANALOG_RX_LNA_RX_LNA_BUMP_MASK      (0xFU)
#define XCVR_ANALOG_RX_LNA_RX_LNA_BUMP_SHIFT     (0U)
/*! RX_LNA_BUMP - rmap_rx_lna_bump[3:0]
 *  0b0000..Default
 *  0b0001..-25%
 *  0b0010..+50%
 *  0b0011..+25%
 *  0b0100..CM 480mV
 *  0b1000..CM 600mV
 *  0b1100..CM 660mV
 */
#define XCVR_ANALOG_RX_LNA_RX_LNA_BUMP(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_LNA_RX_LNA_BUMP_SHIFT)) & XCVR_ANALOG_RX_LNA_RX_LNA_BUMP_MASK)

#define XCVR_ANALOG_RX_LNA_RX_LNA_HG_DIAGSEL_MASK (0x10U)
#define XCVR_ANALOG_RX_LNA_RX_LNA_HG_DIAGSEL_SHIFT (4U)
/*! RX_LNA_HG_DIAGSEL - rmap_rx_lna_hg_diagsel */
#define XCVR_ANALOG_RX_LNA_RX_LNA_HG_DIAGSEL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_LNA_RX_LNA_HG_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_LNA_RX_LNA_HG_DIAGSEL_MASK)

#define XCVR_ANALOG_RX_LNA_RX_LNA_HIZ_ENABLE_MASK (0x20U)
#define XCVR_ANALOG_RX_LNA_RX_LNA_HIZ_ENABLE_SHIFT (5U)
/*! RX_LNA_HIZ_ENABLE - rmap_rx_lna_hiZ_enable */
#define XCVR_ANALOG_RX_LNA_RX_LNA_HIZ_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_LNA_RX_LNA_HIZ_ENABLE_SHIFT)) & XCVR_ANALOG_RX_LNA_RX_LNA_HIZ_ENABLE_MASK)

#define XCVR_ANALOG_RX_LNA_RX_LNA_LG_DIAGSEL_MASK (0x40U)
#define XCVR_ANALOG_RX_LNA_RX_LNA_LG_DIAGSEL_SHIFT (6U)
/*! RX_LNA_LG_DIAGSEL - rmap_rx_lna_lg_diagsel */
#define XCVR_ANALOG_RX_LNA_RX_LNA_LG_DIAGSEL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_LNA_RX_LNA_LG_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_LNA_RX_LNA_LG_DIAGSEL_MASK)

#define XCVR_ANALOG_RX_LNA_RX_LNA_SPARE_MASK     (0x300U)
#define XCVR_ANALOG_RX_LNA_RX_LNA_SPARE_SHIFT    (8U)
/*! RX_LNA_SPARE - rmap_rx_lna_spare[1:0] */
#define XCVR_ANALOG_RX_LNA_RX_LNA_SPARE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_LNA_RX_LNA_SPARE_SHIFT)) & XCVR_ANALOG_RX_LNA_RX_LNA_SPARE_MASK)

#define XCVR_ANALOG_RX_LNA_RX_MIXER_BUMP_MASK    (0xF0000U)
#define XCVR_ANALOG_RX_LNA_RX_MIXER_BUMP_SHIFT   (16U)
/*! RX_MIXER_BUMP - rmap_rx_mixer_bump[3:0]
 *  0b0000..825mV (Default)
 *  0b0001..750mV
 *  0b0010..900mV
 *  0b0011..975mV
 */
#define XCVR_ANALOG_RX_LNA_RX_MIXER_BUMP(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_LNA_RX_MIXER_BUMP_SHIFT)) & XCVR_ANALOG_RX_LNA_RX_MIXER_BUMP_MASK)

#define XCVR_ANALOG_RX_LNA_RX_MIXER_SPARE_MASK   (0x100000U)
#define XCVR_ANALOG_RX_LNA_RX_MIXER_SPARE_SHIFT  (20U)
/*! RX_MIXER_SPARE - rmap_rx_mixer_spare */
#define XCVR_ANALOG_RX_LNA_RX_MIXER_SPARE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_LNA_RX_MIXER_SPARE_SHIFT)) & XCVR_ANALOG_RX_LNA_RX_MIXER_SPARE_MASK)
/*! @} */

/*! @name RX_TZA - RF Analog TZA Control */
/*! @{ */

#define XCVR_ANALOG_RX_TZA_RX_TZA_BW_SEL_MASK    (0x7U)
#define XCVR_ANALOG_RX_TZA_RX_TZA_BW_SEL_SHIFT   (0U)
/*! RX_TZA_BW_SEL - rmap_rx_tza_bw_sel[2:0]
 *  0b000..1000K
 *  0b001..900K
 *  0b010..800K
 *  0b011..700K Default
 *  0b100..600K
 *  0b101..500K
 */
#define XCVR_ANALOG_RX_TZA_RX_TZA_BW_SEL(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA_BW_SEL_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA_BW_SEL_MASK)

#define XCVR_ANALOG_RX_TZA_RX_TZA_CUR_BUMP_MASK  (0x8U)
#define XCVR_ANALOG_RX_TZA_RX_TZA_CUR_BUMP_SHIFT (3U)
/*! RX_TZA_CUR_BUMP - rmap_rx_tza_cur_bump */
#define XCVR_ANALOG_RX_TZA_RX_TZA_CUR_BUMP(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA_CUR_BUMP_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA_CUR_BUMP_MASK)

#define XCVR_ANALOG_RX_TZA_RX_TZA_GAIN_BUMP_MASK (0x10U)
#define XCVR_ANALOG_RX_TZA_RX_TZA_GAIN_BUMP_SHIFT (4U)
/*! RX_TZA_GAIN_BUMP - rmap_rx_tza_gain_bump */
#define XCVR_ANALOG_RX_TZA_RX_TZA_GAIN_BUMP(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA_GAIN_BUMP_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA_GAIN_BUMP_MASK)

#define XCVR_ANALOG_RX_TZA_RX_TZA_SPARE_MASK     (0x3F0000U)
#define XCVR_ANALOG_RX_TZA_RX_TZA_SPARE_SHIFT    (16U)
/*! RX_TZA_SPARE - rmap_rx_tza_spare[5:0]
 *  0b000000..600mV (Default)
 *  0b000001..675mV
 *  0b000010..450mV
 *  0b000011..525mV
 */
#define XCVR_ANALOG_RX_TZA_RX_TZA_SPARE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA_SPARE_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA_SPARE_MASK)

#define XCVR_ANALOG_RX_TZA_RX_TZA1_DIAGSEL_MASK  (0x1000000U)
#define XCVR_ANALOG_RX_TZA_RX_TZA1_DIAGSEL_SHIFT (24U)
/*! RX_TZA1_DIAGSEL - rmap_rx_tza1_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_TZA_RX_TZA1_DIAGSEL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA1_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA1_DIAGSEL_MASK)

#define XCVR_ANALOG_RX_TZA_RX_TZA2_DIAGSEL_MASK  (0x2000000U)
#define XCVR_ANALOG_RX_TZA_RX_TZA2_DIAGSEL_SHIFT (25U)
/*! RX_TZA2_DIAGSEL - rmap_rx_tza2_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_TZA_RX_TZA2_DIAGSEL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA2_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA2_DIAGSEL_MASK)

#define XCVR_ANALOG_RX_TZA_RX_TZA3_DIAGSEL_MASK  (0x4000000U)
#define XCVR_ANALOG_RX_TZA_RX_TZA3_DIAGSEL_SHIFT (26U)
/*! RX_TZA3_DIAGSEL - rmap_rx_tza3_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_TZA_RX_TZA3_DIAGSEL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA3_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA3_DIAGSEL_MASK)

#define XCVR_ANALOG_RX_TZA_RX_TZA4_DIAGSEL_MASK  (0x8000000U)
#define XCVR_ANALOG_RX_TZA_RX_TZA4_DIAGSEL_SHIFT (27U)
/*! RX_TZA4_DIAGSEL - rmap_rx_tza4_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_RX_TZA_RX_TZA4_DIAGSEL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_TZA_RX_TZA4_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_TZA_RX_TZA4_DIAGSEL_MASK)
/*! @} */

/*! @name RX_AUXPLL - RF Analog Aux PLL Control */
/*! @{ */

#define XCVR_ANALOG_RX_AUXPLL_BIAS_TRIM_MASK     (0x7U)
#define XCVR_ANALOG_RX_AUXPLL_BIAS_TRIM_SHIFT    (0U)
/*! BIAS_TRIM - rmap_rxtx_auxpll_bias_trim[2:0] */
#define XCVR_ANALOG_RX_AUXPLL_BIAS_TRIM(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_BIAS_TRIM_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_BIAS_TRIM_MASK)

#define XCVR_ANALOG_RX_AUXPLL_DIAGSEL1_MASK      (0x8U)
#define XCVR_ANALOG_RX_AUXPLL_DIAGSEL1_SHIFT     (3U)
/*! DIAGSEL1 - rmap_rxtx_auxpll_diagsel1 */
#define XCVR_ANALOG_RX_AUXPLL_DIAGSEL1(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_DIAGSEL1_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_DIAGSEL1_MASK)

#define XCVR_ANALOG_RX_AUXPLL_DIAGSEL2_MASK      (0x10U)
#define XCVR_ANALOG_RX_AUXPLL_DIAGSEL2_SHIFT     (4U)
/*! DIAGSEL2 - rmap_rxtx_auxpll_diagsel2 */
#define XCVR_ANALOG_RX_AUXPLL_DIAGSEL2(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_DIAGSEL2_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_DIAGSEL2_MASK)

#define XCVR_ANALOG_RX_AUXPLL_LF_CNTL_MASK       (0xE0U)
#define XCVR_ANALOG_RX_AUXPLL_LF_CNTL_SHIFT      (5U)
/*! LF_CNTL - rmap_rxtx_auxpll_lf_cntl[2:0] */
#define XCVR_ANALOG_RX_AUXPLL_LF_CNTL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_LF_CNTL_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_LF_CNTL_MASK)

#define XCVR_ANALOG_RX_AUXPLL_SPARE_MASK         (0xF00U)
#define XCVR_ANALOG_RX_AUXPLL_SPARE_SHIFT        (8U)
/*! SPARE - rmap_rxtx_auxpll_spare[3:0] */
#define XCVR_ANALOG_RX_AUXPLL_SPARE(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_SPARE_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_SPARE_MASK)

#define XCVR_ANALOG_RX_AUXPLL_VCO_DAC_REF_ADJUST_MASK (0xF000U)
#define XCVR_ANALOG_RX_AUXPLL_VCO_DAC_REF_ADJUST_SHIFT (12U)
/*! VCO_DAC_REF_ADJUST - rmap_rxtx_auxpll_vco_dac_ref_adjust[3:0] */
#define XCVR_ANALOG_RX_AUXPLL_VCO_DAC_REF_ADJUST(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_VCO_DAC_REF_ADJUST_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_VCO_DAC_REF_ADJUST_MASK)

#define XCVR_ANALOG_RX_AUXPLL_VTUNE_TESTMODE_MASK (0x10000U)
#define XCVR_ANALOG_RX_AUXPLL_VTUNE_TESTMODE_SHIFT (16U)
/*! VTUNE_TESTMODE - rmap_rxtx_auxpll_vtune_testmode */
#define XCVR_ANALOG_RX_AUXPLL_VTUNE_TESTMODE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_VTUNE_TESTMODE_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_VTUNE_TESTMODE_MASK)

#define XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_BIAST_MASK (0x300000U)
#define XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_BIAST_SHIFT (20U)
/*! RXTX_BAL_BIAST - rmap_rxtx_bal_biast[1:0]
 *  0b00..0.6
 *  0b01..0.4
 *  0b10..0.9
 *  0b11..1.2
 */
#define XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_BIAST(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_BIAST_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_BIAST_MASK)

#define XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_SPARE_MASK (0x7000000U)
#define XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_SPARE_SHIFT (24U)
/*! RXTX_BAL_SPARE - rmap_rxtx_bal_spare[2:0] */
#define XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_SPARE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_SPARE_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_RXTX_BAL_SPARE_MASK)

#define XCVR_ANALOG_RX_AUXPLL_RXTX_RCCAL_DIAGSEL_MASK (0x10000000U)
#define XCVR_ANALOG_RX_AUXPLL_RXTX_RCCAL_DIAGSEL_SHIFT (28U)
/*! RXTX_RCCAL_DIAGSEL - rmap_rxtx_rccal_diagsel */
#define XCVR_ANALOG_RX_AUXPLL_RXTX_RCCAL_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_RX_AUXPLL_RXTX_RCCAL_DIAGSEL_SHIFT)) & XCVR_ANALOG_RX_AUXPLL_RXTX_RCCAL_DIAGSEL_MASK)
/*! @} */

/*! @name SY_CTRL_1 - RF Analog Synthesizer Control 1 */
/*! @{ */

#define XCVR_ANALOG_SY_CTRL_1_SY_DIVN_SPARE_MASK (0x1U)
#define XCVR_ANALOG_SY_CTRL_1_SY_DIVN_SPARE_SHIFT (0U)
/*! SY_DIVN_SPARE - rmap_sy_divn_spare */
#define XCVR_ANALOG_SY_CTRL_1_SY_DIVN_SPARE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_DIVN_SPARE_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_DIVN_SPARE_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_FCAL_SPARE_MASK (0x2U)
#define XCVR_ANALOG_SY_CTRL_1_SY_FCAL_SPARE_SHIFT (1U)
/*! SY_FCAL_SPARE - rmap_sy_fcal_spare */
#define XCVR_ANALOG_SY_CTRL_1_SY_FCAL_SPARE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_FCAL_SPARE_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_FCAL_SPARE_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_FDBK_MASK (0x30U)
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_FDBK_SHIFT (4U)
/*! SY_LO_BUMP_RTLO_FDBK - rmap_sy_lo_bump_rtlo_fdbk[1:0]
 *  0b00..1.045 V
 *  0b01..1.084 V
 *  0b10..1.097 V
 *  0b11..1.10 V
 */
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_FDBK(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_FDBK_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_FDBK_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_RX_MASK (0xC0U)
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_RX_SHIFT (6U)
/*! SY_LO_BUMP_RTLO_RX - rmap_sy_lo_bump_rtlo_rx[1:0]
 *  0b00..1.051/1.037 V
 *  0b01..1.082/1.075 V
 *  0b10..1.092/1.088 V
 *  0b11..1.098/1.094 V
 */
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_RX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_RX_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_RX_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_TX_MASK (0x300U)
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_TX_SHIFT (8U)
/*! SY_LO_BUMP_RTLO_TX - rmap_sy_lo_bump_rtlo_tx[1:0]
 *  0b00..1.071/1.065 V
 *  0b01..1.092/1.090 V
 *  0b10..1.099/1.098 V
 *  0b11..1.10/1.1 V
 */
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_TX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_TX_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_LO_BUMP_RTLO_TX_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_LO_DIAGSEL_MASK (0x400U)
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_DIAGSEL_SHIFT (10U)
/*! SY_LO_DIAGSEL - rmap_sy_lo_diagsel
 *  0b0..Diag disable
 *  0b1..Diag enable
 */
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_DIAGSEL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_LO_DIAGSEL_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_LO_DIAGSEL_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_LO_SPARE_MASK   (0x7000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_SPARE_SHIFT  (12U)
/*! SY_LO_SPARE - rmap_sy_lo_spare[2:0] */
#define XCVR_ANALOG_SY_CTRL_1_SY_LO_SPARE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_LO_SPARE_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_LO_SPARE_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_LPF_FILT_CTRL_MASK (0x70000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_LPF_FILT_CTRL_SHIFT (16U)
/*! SY_LPF_FILT_CTRL - rmap_sy_lpf_filt_ctrl[2:0] */
#define XCVR_ANALOG_SY_CTRL_1_SY_LPF_FILT_CTRL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_LPF_FILT_CTRL_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_LPF_FILT_CTRL_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_LPF_SPARE_MASK  (0x80000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_LPF_SPARE_SHIFT (19U)
/*! SY_LPF_SPARE - rmap_sy_lpf_spare */
#define XCVR_ANALOG_SY_CTRL_1_SY_LPF_SPARE(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_LPF_SPARE_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_LPF_SPARE_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_PD_DIAGSEL_MASK (0x100000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_DIAGSEL_SHIFT (20U)
/*! SY_PD_DIAGSEL - rmap_sy_pd_diagsel */
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_DIAGSEL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_PD_DIAGSEL_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_PD_DIAGSEL_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_TUNE_MASK (0x600000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_TUNE_SHIFT (21U)
/*! SY_PD_PCH_TUNE - rmap_sy_pd_pch_tune[1:0] */
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_TUNE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_TUNE_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_TUNE_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_SEL_MASK (0x800000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_SEL_SHIFT (23U)
/*! SY_PD_PCH_SEL - rmap_sy_pd_pch_sel
 *  0b0..inverter based precharge
 *  0b1..resistor divider based precharge
 */
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_SEL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_SEL_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_PD_PCH_SEL_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_PD_SPARE_MASK   (0x3000000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_SPARE_SHIFT  (24U)
/*! SY_PD_SPARE - rmap_sy_pd_spare[1:0]
 *  0b00..Default ;
 *  0b01..PD output is pulled down.
 */
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_SPARE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_PD_SPARE_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_PD_SPARE_MASK)

#define XCVR_ANALOG_SY_CTRL_1_SY_PD_VTUNE_OVERRIDE_TEST_MODE_MASK (0x10000000U)
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_VTUNE_OVERRIDE_TEST_MODE_SHIFT (28U)
/*! SY_PD_VTUNE_OVERRIDE_TEST_MODE - rmap_sy_pd_vtune_override_test_mode */
#define XCVR_ANALOG_SY_CTRL_1_SY_PD_VTUNE_OVERRIDE_TEST_MODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_1_SY_PD_VTUNE_OVERRIDE_TEST_MODE_SHIFT)) & XCVR_ANALOG_SY_CTRL_1_SY_PD_VTUNE_OVERRIDE_TEST_MODE_MASK)
/*! @} */

/*! @name SY_CTRL_2 - RF Analog Synthesizer Control 2 */
/*! @{ */

#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_BIAS_MASK   (0x7U)
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_BIAS_SHIFT  (0U)
/*! SY_VCO_BIAS - rmap_sy_vco_bias[2:0]
 *  0b000..0.97V
 *  0b001..1.033V
 *  0b010..1.06V
 *  0b011..1.07V
 *  0b100..1.08V
 *  0b101..1.085V
 *  0b110..1.090V
 *  0b111..1.095V
 */
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_BIAS(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_2_SY_VCO_BIAS_SHIFT)) & XCVR_ANALOG_SY_CTRL_2_SY_VCO_BIAS_MASK)

#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_DIAGSEL_MASK (0x8U)
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_DIAGSEL_SHIFT (3U)
/*! SY_VCO_DIAGSEL - rmap_sy_vco_diagsel
 *  0b1..Diag enable
 *  0b0..Diag disable
 */
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_DIAGSEL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_2_SY_VCO_DIAGSEL_SHIFT)) & XCVR_ANALOG_SY_CTRL_2_SY_VCO_DIAGSEL_MASK)

#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_KV_MASK     (0x70U)
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_KV_SHIFT    (4U)
/*! SY_VCO_KV - rmap_sy_vco_kv[2:0]
 *  0b000..50MHz/V
 *  0b001..60MHz/V
 *  0b010..70MHz/V
 *  0b011..80MHz/V
 *  0b100..80MHz/V
 *  0b101..80MHz/V
 *  0b110..80MHz/V
 *  0b111..80MHz/V
 */
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_KV(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_2_SY_VCO_KV_SHIFT)) & XCVR_ANALOG_SY_CTRL_2_SY_VCO_KV_MASK)

#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_KVM_MASK    (0x700U)
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_KVM_SHIFT   (8U)
/*! SY_VCO_KVM - rmap_sy_vco_kvm[2:0]
 *  0b000..10MHz/V
 *  0b001..20MHz/V
 *  0b010..30MHz/V
 *  0b011..40MHz/V
 *  0b100..40MHz/V
 *  0b101..40MHz/V
 *  0b110..40MHz/V
 *  0b111..40MHz/V
 */
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_KVM(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_2_SY_VCO_KVM_SHIFT)) & XCVR_ANALOG_SY_CTRL_2_SY_VCO_KVM_MASK)

#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_PK_DET_ON_MASK (0x1000U)
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_PK_DET_ON_SHIFT (12U)
/*! SY_VCO_PK_DET_ON - rmap_sy_vco_pk_det_on
 *  0b1..Enable
 *  0b0..Disable
 */
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_PK_DET_ON(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_2_SY_VCO_PK_DET_ON_SHIFT)) & XCVR_ANALOG_SY_CTRL_2_SY_VCO_PK_DET_ON_MASK)

#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_SPARE_MASK  (0x1C000U)
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_SPARE_SHIFT (14U)
/*! SY_VCO_SPARE - rmap_sy_vco_spare[2:0] */
#define XCVR_ANALOG_SY_CTRL_2_SY_VCO_SPARE(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_SY_CTRL_2_SY_VCO_SPARE_SHIFT)) & XCVR_ANALOG_SY_CTRL_2_SY_VCO_SPARE_MASK)
/*! @} */

/*! @name TX_DAC_PA - RF Analog TX HPM DAC and PA Control */
/*! @{ */

#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_CAP_MASK (0x3U)
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_CAP_SHIFT (0U)
/*! TX_DAC_BUMP_CAP - rmap_tx_dac_bump_cap[1:0]
 *  0b00..1pF(default)
 *  0b01..1.5pF
 *  0b10..1.5pF
 *  0b11..2pF
 */
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_CAP(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_CAP_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_CAP_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_IDAC_MASK (0x18U)
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_IDAC_SHIFT (3U)
/*! TX_DAC_BUMP_IDAC - rmap_tx_dac_bump_idac[1:0]
 *  0b00..250nA(default)
 *  0b01..207nA
 *  0b10..312nA
 *  0b11..415nA
 */
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_IDAC(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_IDAC_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_IDAC_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_RLOAD_MASK (0xC0U)
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_RLOAD_SHIFT (6U)
/*! TX_DAC_BUMP_RLOAD - rmap_tx_dac_bump_rload[1:0]
 *  0b00..3.12 kohms(default)
 *  0b01..2.34 kohms
 *  0b10..3.9 kohms
 *  0b11..4.6 kohms
 */
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_RLOAD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_RLOAD_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_DAC_BUMP_RLOAD_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_DIAGSEL_MASK (0x200U)
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_DIAGSEL_SHIFT (9U)
/*! TX_DAC_DIAGSEL - rmap_tx_dac_diagsel
 *  0b0..Disable Diag
 *  0b1..Enable Diag
 */
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_DIAGSEL(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_DAC_DIAGSEL_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_DAC_DIAGSEL_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_INVERT_CLK_MASK (0x400U)
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_INVERT_CLK_SHIFT (10U)
/*! TX_DAC_INVERT_CLK - rmap_tx_dac_invert_clk */
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_INVERT_CLK(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_DAC_INVERT_CLK_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_DAC_INVERT_CLK_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_OPAMP_DIAGSEL_MASK (0x800U)
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_OPAMP_DIAGSEL_SHIFT (11U)
/*! TX_DAC_OPAMP_DIAGSEL - rmap_tx_dac_opamp_diagsel
 *  0b0..Disable Diag
 *  0b1..Enable Diag
 */
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_OPAMP_DIAGSEL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_DAC_OPAMP_DIAGSEL_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_DAC_OPAMP_DIAGSEL_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_SPARE_MASK  (0xE000U)
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_SPARE_SHIFT (13U)
/*! TX_DAC_SPARE - rmap_tx_dac_spare[2:0] */
#define XCVR_ANALOG_TX_DAC_PA_TX_DAC_SPARE(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_DAC_SPARE_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_DAC_SPARE_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_PA_BUMP_VBIAS_MASK (0xE0000U)
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_BUMP_VBIAS_SHIFT (17U)
/*! TX_PA_BUMP_VBIAS - rmap_tx_pa_bump_vbias[2:0]
 *  0b000..0.557
 *  0b001..0.651
 *  0b010..0.741
 *  0b011..0.822
 *  0b100..0.590
 *  0b101..0.683
 *  0b110..0.771
 *  0b111..0.850
 */
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_BUMP_VBIAS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_PA_BUMP_VBIAS_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_PA_BUMP_VBIAS_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_PA_DIAGSEL_MASK (0x200000U)
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_DIAGSEL_SHIFT (21U)
/*! TX_PA_DIAGSEL - rmap_tx_pa_diagsel */
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_DIAGSEL(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_PA_DIAGSEL_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_PA_DIAGSEL_MASK)

#define XCVR_ANALOG_TX_DAC_PA_TX_PA_SPARE_MASK   (0x3800000U)
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_SPARE_SHIFT  (23U)
/*! TX_PA_SPARE - rmap_tx_pa_spare[2:0] */
#define XCVR_ANALOG_TX_DAC_PA_TX_PA_SPARE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_TX_DAC_PA_TX_PA_SPARE_SHIFT)) & XCVR_ANALOG_TX_DAC_PA_TX_PA_SPARE_MASK)
/*! @} */

/*! @name BALUN_TX - RF Analog Balun TX Mode Control */
/*! @{ */

#define XCVR_ANALOG_BALUN_TX_RXTX_BAL_TX_CODE_MASK (0xFFFFFFU)
#define XCVR_ANALOG_BALUN_TX_RXTX_BAL_TX_CODE_SHIFT (0U)
/*! RXTX_BAL_TX_CODE - Balun Tuning Cap Settings in Transmit Mode */
#define XCVR_ANALOG_BALUN_TX_RXTX_BAL_TX_CODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BALUN_TX_RXTX_BAL_TX_CODE_SHIFT)) & XCVR_ANALOG_BALUN_TX_RXTX_BAL_TX_CODE_MASK)
/*! @} */

/*! @name BALUN_RX - RF Analog Balun RX Mode Control */
/*! @{ */

#define XCVR_ANALOG_BALUN_RX_RXTX_BAL_RX_CODE_MASK (0xFFFFFFU)
#define XCVR_ANALOG_BALUN_RX_RXTX_BAL_RX_CODE_SHIFT (0U)
/*! RXTX_BAL_RX_CODE - Balun Tuning Cap Settings in Receive Mode */
#define XCVR_ANALOG_BALUN_RX_RXTX_BAL_RX_CODE(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_BALUN_RX_RXTX_BAL_RX_CODE_SHIFT)) & XCVR_ANALOG_BALUN_RX_RXTX_BAL_RX_CODE_MASK)
/*! @} */

/*! @name DFT_OBSV_1 - RF Analog DFT Observation Register 1 */
/*! @{ */

#define XCVR_ANALOG_DFT_OBSV_1_DFT_FREQ_COUNTER_MASK (0x7FFFFU)
#define XCVR_ANALOG_DFT_OBSV_1_DFT_FREQ_COUNTER_SHIFT (0U)
/*! DFT_FREQ_COUNTER - VCO Frequency Counter Value */
#define XCVR_ANALOG_DFT_OBSV_1_DFT_FREQ_COUNTER(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DFT_OBSV_1_DFT_FREQ_COUNTER_SHIFT)) & XCVR_ANALOG_DFT_OBSV_1_DFT_FREQ_COUNTER_MASK)

#define XCVR_ANALOG_DFT_OBSV_1_CTUNE_MAX_DIFF_MASK (0xFF00000U)
#define XCVR_ANALOG_DFT_OBSV_1_CTUNE_MAX_DIFF_SHIFT (20U)
/*! CTUNE_MAX_DIFF - Maximum Frequency Count Difference found by the Coarse Tune BIST */
#define XCVR_ANALOG_DFT_OBSV_1_CTUNE_MAX_DIFF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DFT_OBSV_1_CTUNE_MAX_DIFF_SHIFT)) & XCVR_ANALOG_DFT_OBSV_1_CTUNE_MAX_DIFF_MASK)
/*! @} */

/*! @name DFT_OBSV_2 - RF Analog DFT Observation Register 2 */
/*! @{ */

#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_MASK (0x1FFFFU)
#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_SHIFT (0U)
/*! SYN_BIST_MAX_DIFF - PLL Frequency Synthesizer BIST Worst Frequency Count */
#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_SHIFT)) & XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_MASK)

#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_CH_MASK (0x7F000000U)
#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_CH_SHIFT (24U)
/*! SYN_BIST_MAX_DIFF_CH - PLL Frequency Synthesizer BIST Worst Channel */
#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_CH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_CH_SHIFT)) & XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_MAX_DIFF_CH_MASK)

#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_IGNORE_FAILS_MASK (0x80000000U)
#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_IGNORE_FAILS_SHIFT (31U)
/*! SYN_BIST_IGNORE_FAILS - PLL Frequency Synthesizer BIST Ignore Fails */
#define XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_IGNORE_FAILS(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_IGNORE_FAILS_SHIFT)) & XCVR_ANALOG_DFT_OBSV_2_SYN_BIST_IGNORE_FAILS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_ANALOG_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_ANALOG_Peripheral_Access_Layer */


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


#endif  /* XCVR_ANALOG_H_ */

