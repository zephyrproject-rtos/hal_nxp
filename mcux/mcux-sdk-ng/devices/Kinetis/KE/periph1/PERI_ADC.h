/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC1;                               /**< Status and Control Register 1, offset: 0x0 */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x4 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x8 */
  __IO uint32_t SC4;                               /**< Status and Control Register 4, offset: 0xC */
  __I  uint32_t R;                                 /**< Conversion Result Register, offset: 0x10 */
  __IO uint32_t CV;                                /**< Compare Value Register, offset: 0x14 */
  __IO uint32_t APCTL1;                            /**< Pin Control 1 Register, offset: 0x18 */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name SC1 - Status and Control Register 1 */
/*! @{ */

#define ADC_SC1_ADCH_MASK                        (0x1FU)
#define ADC_SC1_ADCH_SHIFT                       (0U)
/*! ADCH - Input Channel Select
 *  0b00000-0b01111..AD0-AD15
 *  0b10000-0b10011..VSS
 *  0b10100-0b10101..Reserved
 *  0b10110..Temperature Sensor
 *  0b10111..Bandgap
 *  0b11000-0b11100..Reserved
 *  0b11101..VREFH
 *  0b11110..VREFL
 *  0b11111..Module disabled Reset FIFO in FIFO mode.
 */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_ADCH_SHIFT)) & ADC_SC1_ADCH_MASK)

#define ADC_SC1_ADCO_MASK                        (0x20U)
#define ADC_SC1_ADCO_SHIFT                       (5U)
/*! ADCO - Continuous Conversion Enable
 *  0b0..One conversion following a write to the ADC_SC1 when software triggered operation is selected, or one
 *       conversion following assertion of ADHWT when hardware triggered operation is selected. When the FIFO function
 *       is enabled (AFDEP > 0), a set of conversion are triggered when ADC_SC2[ADTRG]=0.
 *  0b1..Continuous conversions are initiated following a write to ADC_SC1 when software triggered operation is
 *       selected. Continuous conversions are initiated by an ADHWT event when hardware triggered operation is
 *       selected. When the FIFO function is enabled (AFDEP > 0), a set of conversions are loop triggered.
 */
#define ADC_SC1_ADCO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_ADCO_SHIFT)) & ADC_SC1_ADCO_MASK)

#define ADC_SC1_AIEN_MASK                        (0x40U)
#define ADC_SC1_AIEN_SHIFT                       (6U)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt disabled.
 *  0b1..Conversion complete interrupt enabled.
 */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_AIEN_SHIFT)) & ADC_SC1_AIEN_MASK)

#define ADC_SC1_COCO_MASK                        (0x80U)
#define ADC_SC1_COCO_SHIFT                       (7U)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion not completed.
 *  0b1..Conversion completed.
 */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_COCO_SHIFT)) & ADC_SC1_COCO_MASK)
/*! @} */

/*! @name SC2 - Status and Control Register 2 */
/*! @{ */

#define ADC_SC2_REFSEL_MASK                      (0x3U)
#define ADC_SC2_REFSEL_SHIFT                     (0U)
/*! REFSEL - Voltage Reference Selection
 *  0b00..Default voltage reference pin pair (VREFH/VREFL).
 *  0b01..Analog supply pin pair (VDDA/VSSA).
 *  0b10..Reserved.
 *  0b11..Reserved - Selects default voltage reference (VREFH/VREFL) pin pair.
 */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC2_REFSEL_SHIFT)) & ADC_SC2_REFSEL_MASK)

#define ADC_SC2_FFULL_MASK                       (0x4U)
#define ADC_SC2_FFULL_SHIFT                      (2U)
/*! FFULL - Result FIFO full
 *  0b0..Indicates that ADC result FIFO is not full and next conversion data still can be stored into FIFO.
 *  0b1..Indicates that ADC result FIFO is full and next conversion will override old data in case of no read action.
 */
#define ADC_SC2_FFULL(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_FFULL_SHIFT)) & ADC_SC2_FFULL_MASK)

#define ADC_SC2_FEMPTY_MASK                      (0x8U)
#define ADC_SC2_FEMPTY_SHIFT                     (3U)
/*! FEMPTY - Result FIFO empty
 *  0b0..Indicates that ADC result FIFO have at least one valid new data.
 *  0b1..Indicates that ADC result FIFO have no valid new data.
 */
#define ADC_SC2_FEMPTY(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC2_FEMPTY_SHIFT)) & ADC_SC2_FEMPTY_MASK)

#define ADC_SC2_ACFGT_MASK                       (0x10U)
#define ADC_SC2_ACFGT_SHIFT                      (4U)
/*! ACFGT - Compare Function Greater Than Enable
 *  0b0..Compare triggers when input is less than compare level.
 *  0b1..Compare triggers when input is greater than or equal to compare level.
 */
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

#define ADC_SC3_ADICLK_MASK                      (0x3U)
#define ADC_SC3_ADICLK_SHIFT                     (0U)
/*! ADICLK - Input Clock Select
 *  0b00..Bus clock
 *  0b01..Bus clock divided by 2
 *  0b10..Alternate clock (ALTCLK)
 *  0b11..Asynchronous clock (ADACK)
 */
#define ADC_SC3_ADICLK(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC3_ADICLK_SHIFT)) & ADC_SC3_ADICLK_MASK)

#define ADC_SC3_MODE_MASK                        (0xCU)
#define ADC_SC3_MODE_SHIFT                       (2U)
/*! MODE - Conversion Mode Selection
 *  0b00..8-bit conversion (N = 8)
 *  0b01..10-bit conversion (N = 10)
 *  0b10..12-bit conversion (N = 12)
 *  0b11..Reserved
 */
#define ADC_SC3_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_MODE_SHIFT)) & ADC_SC3_MODE_MASK)

#define ADC_SC3_ADLSMP_MASK                      (0x10U)
#define ADC_SC3_ADLSMP_SHIFT                     (4U)
/*! ADLSMP - Long Sample Time Configuration
 *  0b0..Short sample time.
 *  0b1..Long sample time.
 */
#define ADC_SC3_ADLSMP(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC3_ADLSMP_SHIFT)) & ADC_SC3_ADLSMP_MASK)

#define ADC_SC3_ADIV_MASK                        (0x60U)
#define ADC_SC3_ADIV_SHIFT                       (5U)
/*! ADIV - Clock Divide Select
 *  0b00..Divide ration = 1, and clock rate = Input clock.
 *  0b01..Divide ration = 2, and clock rate = Input clock / 2.
 *  0b10..Divide ration = 3, and clock rate = Input clock / 4.
 *  0b11..Divide ration = 4, and clock rate = Input clock / 8.
 */
#define ADC_SC3_ADIV(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_ADIV_SHIFT)) & ADC_SC3_ADIV_MASK)

#define ADC_SC3_ADLPC_MASK                       (0x80U)
#define ADC_SC3_ADLPC_SHIFT                      (7U)
/*! ADLPC - Low-Power Configuration
 *  0b0..High speed configuration.
 *  0b1..Low power configuration:The power is reduced at the expense of maximum clock speed.
 */
#define ADC_SC3_ADLPC(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC3_ADLPC_SHIFT)) & ADC_SC3_ADLPC_MASK)
/*! @} */

/*! @name SC4 - Status and Control Register 4 */
/*! @{ */

#define ADC_SC4_AFDEP_MASK                       (0x7U)
#define ADC_SC4_AFDEP_SHIFT                      (0U)
/*! AFDEP - FIFO Depth
 *  0b000..FIFO is disabled.
 *  0b001..2-level FIFO is enabled.
 *  0b010..3-level FIFO is enabled..
 *  0b011..4-level FIFO is enabled.
 *  0b100..5-level FIFO is enabled.
 *  0b101..6-level FIFO is enabled.
 *  0b110..7-level FIFO is enabled.
 *  0b111..8-level FIFO is enabled.
 */
#define ADC_SC4_AFDEP(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC4_AFDEP_SHIFT)) & ADC_SC4_AFDEP_MASK)

#define ADC_SC4_ACFSEL_MASK                      (0x20U)
#define ADC_SC4_ACFSEL_SHIFT                     (5U)
/*! ACFSEL - Compare Function Selection
 *  0b0..OR all of compare trigger.
 *  0b1..AND all of compare trigger.
 */
#define ADC_SC4_ACFSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC4_ACFSEL_SHIFT)) & ADC_SC4_ACFSEL_MASK)

#define ADC_SC4_ASCANE_MASK                      (0x40U)
#define ADC_SC4_ASCANE_SHIFT                     (6U)
/*! ASCANE - FIFO Scan Mode Enable
 *  0b0..FIFO scan mode disabled.
 *  0b1..FIFO scan mode enabled.
 */
#define ADC_SC4_ASCANE(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC4_ASCANE_SHIFT)) & ADC_SC4_ASCANE_MASK)
/*! @} */

/*! @name R - Conversion Result Register */
/*! @{ */

#define ADC_R_ADR_MASK                           (0xFFFU)
#define ADC_R_ADR_SHIFT                          (0U)
/*! ADR - Conversion Result */
#define ADC_R_ADR(x)                             (((uint32_t)(((uint32_t)(x)) << ADC_R_ADR_SHIFT)) & ADC_R_ADR_MASK)
/*! @} */

/*! @name CV - Compare Value Register */
/*! @{ */

#define ADC_CV_CV_MASK                           (0xFFFU)
#define ADC_CV_CV_SHIFT                          (0U)
/*! CV - Conversion Result[11:0] */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x)) << ADC_CV_CV_SHIFT)) & ADC_CV_CV_MASK)
/*! @} */

/*! @name APCTL1 - Pin Control 1 Register */
/*! @{ */

#define ADC_APCTL1_ADPC_MASK                     (0xFFFFU)
#define ADC_APCTL1_ADPC_SHIFT                    (0U)
/*! ADPC - ADC Pin Control
 *  0b0000000000000000..ADx pin I/O control enabled.
 *  0b0000000000000001..ADx pin I/O control disabled.
 */
#define ADC_APCTL1_ADPC(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_APCTL1_ADPC_SHIFT)) & ADC_APCTL1_ADPC_MASK)
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

