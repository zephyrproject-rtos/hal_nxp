/*
** ###################################################################
**     Processors:          MKE14Z128VLH7
**                          MKE14Z128VLL7
**                          MKE14Z256VLH7
**                          MKE14Z256VLL7
**                          MKE15Z128VLH7
**                          MKE15Z128VLL7
**                          MKE15Z256VLH7
**                          MKE15Z256VLL7
**
**     Version:             rev. 7.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2015-08-19)
**         Initial version.
**     - rev. 2.0 (2015-09-22)
**         Based on rev0final RDP, add PCC/TRGMUX.
**     - rev. 3.0 (2015-12-29)
**         Align LPFLL register names.
**     - rev. 4.0 (2016-02-19)
**         Based on rev1final RDP.
**     - rev. 5.0 (2016-08-02)
**         Based on rev1.x RDP.
**     - rev. 6.0 (2016-09-20)
**         Based on rev2 RDP.
**     - rev. 7.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 7.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z128VLH7) || defined(CPU_MKE14Z128VLL7) || defined(CPU_MKE14Z256VLH7) || defined(CPU_MKE14Z256VLL7))
#include "MKE14Z7_COMMON.h"
#elif (defined(CPU_MKE15Z128VLH7) || defined(CPU_MKE15Z128VLL7) || defined(CPU_MKE15Z256VLH7) || defined(CPU_MKE15Z256VLL7))
#include "MKE15Z7_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
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
#define ADC_SC1_COUNT                             2u
#define ADC_R_COUNT                               2u

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC1[ADC_SC1_COUNT];                /**< ADC Status and Control Register 1, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[56];
  __IO uint32_t CFG1;                              /**< ADC Configuration Register 1, offset: 0x40 */
  __IO uint32_t CFG2;                              /**< ADC Configuration Register 2, offset: 0x44 */
  __I  uint32_t R[ADC_R_COUNT];                    /**< ADC Data Result Registers, array offset: 0x48, array step: 0x4 */
       uint8_t RESERVED_1[56];
  __IO uint32_t CV1;                               /**< Compare Value Registers, offset: 0x88 */
  __IO uint32_t CV2;                               /**< Compare Value Registers, offset: 0x8C */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x90 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x94 */
  __IO uint32_t BASE_OFS;                          /**< BASE Offset Register, offset: 0x98 */
  __IO uint32_t OFS;                               /**< ADC Offset Correction Register, offset: 0x9C */
  __IO uint32_t USR_OFS;                           /**< USER Offset Correction Register, offset: 0xA0 */
  __IO uint32_t XOFS;                              /**< ADC X Offset Correction Register, offset: 0xA4 */
  __IO uint32_t YOFS;                              /**< ADC Y Offset Correction Register, offset: 0xA8 */
  __IO uint32_t G;                                 /**< ADC Gain Register, offset: 0xAC */
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
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name SC1 - ADC Status and Control Register 1 */
/*! @{ */

#define ADC_SC1_ADCH_MASK                        (0x1FU)
#define ADC_SC1_ADCH_SHIFT                       (0U)
/*! ADCH - Input channel select
 *  0b00000..AD0 is selected as input.
 *  0b00001..AD1 is selected as input.
 *  0b00010..AD2 is selected as input.
 *  0b00011..AD3 is selected as input.
 *  0b00100..AD4 is selected as input.
 *  0b00101..AD5 is selected as input.
 *  0b00110..AD6 is selected as input.
 *  0b00111..AD7 is selected as input.
 *  0b01000..AD8 is selected as input.
 *  0b01001..AD9 is selected as input.
 *  0b01010..AD10 is selected as input.
 *  0b01011..AD11 is selected as input.
 *  0b01100..AD12 is selected as input.
 *  0b01101..AD13 is selected as input.
 *  0b01110..AD14 is selected as input.
 *  0b01111..AD15 is selected as input.
 *  0b10000..Reserved.
 *  0b10001..Reserved.
 *  0b10010..AD18 is selected as input.
 *  0b10011..AD19 is selected as input.
 *  0b10100..Reserved.
 *  0b10101..AD21 is selected as input.
 *  0b10110..AD22 is selected as input.
 *  0b10111..AD23 is selected as input.
 *  0b11000..Reserved
 *  0b11001..Reserved
 *  0b11010..Temp Sensor
 *  0b11011..Band Gap
 *  0b11100..AD28 is selected as input.
 *  0b11101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b11110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b11111..Module is disabled
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

/*! @name CFG1 - ADC Configuration Register 1 */
/*! @{ */

#define ADC_CFG1_ADICLK_MASK                     (0x3U)
#define ADC_CFG1_ADICLK_SHIFT                    (0U)
/*! ADICLK - Input Clock Select
 *  0b00..Alternate clock 1 (ADC_ALTCLK1)
 *  0b01..Alternate clock 2 (ADC_ALTCLK2)
 *  0b10..Alternate clock 3 (ADC_ALTCLK3)
 *  0b11..Alternate clock 4 (ADC_ALTCLK4)
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
/*! @} */

/*! @name CFG2 - ADC Configuration Register 2 */
/*! @{ */

#define ADC_CFG2_SMPLTS_MASK                     (0xFFU)
#define ADC_CFG2_SMPLTS_SHIFT                    (0U)
/*! SMPLTS - Sample Time Select */
#define ADC_CFG2_SMPLTS(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG2_SMPLTS_SHIFT)) & ADC_CFG2_SMPLTS_MASK)
/*! @} */

/*! @name R - ADC Data Result Registers */
/*! @{ */

#define ADC_R_D_MASK                             (0xFFFU)
#define ADC_R_D_SHIFT                            (0U)
/*! D - Data result */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x)) << ADC_R_D_SHIFT)) & ADC_R_D_MASK)
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

/*! @name G - ADC Gain Register */
/*! @{ */

#define ADC_G_G_MASK                             (0x7FFU)
#define ADC_G_G_SHIFT                            (0U)
#define ADC_G_G(x)                               (((uint32_t)(((uint32_t)(x)) << ADC_G_G_SHIFT)) & ADC_G_G_MASK)
/*! @} */

/*! @name UG - ADC User Gain Register */
/*! @{ */

#define ADC_UG_UG_MASK                           (0x3FFU)
#define ADC_UG_UG_SHIFT                          (0U)
#define ADC_UG_UG(x)                             (((uint32_t)(((uint32_t)(x)) << ADC_UG_UG_SHIFT)) & ADC_UG_UG_MASK)
/*! @} */

/*! @name CLPS - ADC General Calibration Value Register S */
/*! @{ */

#define ADC_CLPS_CLPS_MASK                       (0x7FU)
#define ADC_CLPS_CLPS_SHIFT                      (0U)
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLPS_CLPS_SHIFT)) & ADC_CLPS_CLPS_MASK)
/*! @} */

/*! @name CLP3 - ADC Plus-Side General Calibration Value Register 3 */
/*! @{ */

#define ADC_CLP3_CLP3_MASK                       (0x3FFU)
#define ADC_CLP3_CLP3_SHIFT                      (0U)
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP3_CLP3_SHIFT)) & ADC_CLP3_CLP3_MASK)
/*! @} */

/*! @name CLP2 - ADC Plus-Side General Calibration Value Register 2 */
/*! @{ */

#define ADC_CLP2_CLP2_MASK                       (0x3FFU)
#define ADC_CLP2_CLP2_SHIFT                      (0U)
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP2_CLP2_SHIFT)) & ADC_CLP2_CLP2_MASK)
/*! @} */

/*! @name CLP1 - ADC Plus-Side General Calibration Value Register 1 */
/*! @{ */

#define ADC_CLP1_CLP1_MASK                       (0x1FFU)
#define ADC_CLP1_CLP1_SHIFT                      (0U)
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP1_CLP1_SHIFT)) & ADC_CLP1_CLP1_MASK)
/*! @} */

/*! @name CLP0 - ADC Plus-Side General Calibration Value Register 0 */
/*! @{ */

#define ADC_CLP0_CLP0_MASK                       (0xFFU)
#define ADC_CLP0_CLP0_SHIFT                      (0U)
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP0_CLP0_SHIFT)) & ADC_CLP0_CLP0_MASK)
/*! @} */

/*! @name CLPX - ADC Plus-Side General Calibration Value Register X */
/*! @{ */

#define ADC_CLPX_CLPX_MASK                       (0x7FU)
#define ADC_CLPX_CLPX_SHIFT                      (0U)
#define ADC_CLPX_CLPX(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLPX_CLPX_SHIFT)) & ADC_CLPX_CLPX_MASK)
/*! @} */

/*! @name CLP9 - ADC Plus-Side General Calibration Value Register 9 */
/*! @{ */

#define ADC_CLP9_CLP9_MASK                       (0x7FU)
#define ADC_CLP9_CLP9_SHIFT                      (0U)
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
#elif defined(__CWCC__)
  #pragma pop
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

