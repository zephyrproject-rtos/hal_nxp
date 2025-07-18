/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SADC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SADC
 *
 * CMSIS Peripheral Access Layer for SADC
 */

#if !defined(PERI_SADC_H_)
#define PERI_SADC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SADC_Peripheral_Access_Layer SADC Peripheral Access Layer
 * @{
 */

/** SADC - Size of Registers Arrays */
#define SADC_SC1_COUNT                            1u
#define SADC_R_COUNT                              1u

/** SADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC1[SADC_SC1_COUNT];               /**< ADC Status and Control Registers 1, array offset: 0x0, array step: 0x2 */
       uint16_t RESERVED_0[2];
  __IO uint32_t CFG1;                              /**< ADC Configuration Register 1, offset: 0x4 */
  __IO uint32_t CFG2;                              /**< ADC Configuration Register 2, offset: 0x6 */
  __I  uint32_t R[SADC_R_COUNT];                   /**< ADC Data Result Register, array offset: 0x8, array step: 0x2 */
       uint16_t RESERVED_1[2];
  __IO uint32_t CV1;                               /**< Compare Value Registers, offset: 0xC */
  __IO uint32_t CV2;                               /**< Compare Value Registers, offset: 0xE */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x10 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x12 */
  __IO uint32_t OFS;                               /**< ADC Offset Correction Register, offset: 0x14 */
  __IO uint32_t PG;                                /**< ADC Plus-Side Gain Register, offset: 0x16 */
       uint16_t RESERVED_2[2];
  __IO uint32_t CLPD;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x1A */
  __IO uint32_t CLPS;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x1C */
  __IO uint32_t CLP4;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x1E */
  __IO uint32_t CLP3;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x20 */
  __IO uint32_t CLP2;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x22 */
  __IO uint32_t CLP1;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x24 */
  __IO uint32_t CLP0;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x26 */
} SADC_Type;

/* ----------------------------------------------------------------------------
   -- SADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SADC_Register_Masks SADC Register Masks
 * @{
 */

/*! @name SC1 - ADC Status and Control Registers 1 */
/*! @{ */

#define SADC_SC1_ADCH_MASK                       (0x1FUL)
#define SADC_SC1_ADCH_SHIFT                      (0UL)
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
 *  0b10000..AD16 is selected as input.
 *  0b10001..AD17 is selected as input.
 *  0b10010..AD18 is selected as input.
 *  0b10011..AD19 is selected as input.
 *  0b10100..AD20 is selected as input.
 *  0b10101..AD21 is selected as input.
 *  0b10110..AD22 is selected as input.
 *  0b10111..AD23 is selected as input.
 *  0b11000..Reserved.
 *  0b11001..Reserved.
 *  0b11010..Temp Sensor (single-ended) is selected as input.
 *  0b11011..Bandgap (single-ended) is selected as input.
 *  0b11100..Reserved.
 *  0b11101..VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b11110..VREFSL is selected as input. Voltage reference selected is determined by SC2[REFSEL].
 *  0b11111..Module is disabled.
 */
#define SADC_SC1_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC1_ADCH_SHIFT)) & SADC_SC1_ADCH_MASK)

#define SADC_SC1_AIEN_MASK                       (0x40UL)
#define SADC_SC1_AIEN_SHIFT                      (6UL)
/*! AIEN - Interrupt Enable
 *  0b0..Conversion complete interrupt is disabled.
 *  0b1..Conversion complete interrupt is enabled.
 */
#define SADC_SC1_AIEN(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC1_AIEN_SHIFT)) & SADC_SC1_AIEN_MASK)

#define SADC_SC1_COCO_MASK                       (0x80UL)
#define SADC_SC1_COCO_SHIFT                      (7UL)
/*! COCO - Conversion Complete Flag
 *  0b0..Conversion is not completed.
 *  0b1..Conversion is completed.
 */
#define SADC_SC1_COCO(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC1_COCO_SHIFT)) & SADC_SC1_COCO_MASK)
/*! @} */

/*! @name CFG1 - ADC Configuration Register 1 */
/*! @{ */

#define SADC_CFG1_ADICLK_MASK                    (0x3UL)
#define SADC_CFG1_ADICLK_SHIFT                   (0UL)
/*! ADICLK - Input Clock Select
 *  0b00..Bus clock
 *  0b01..(Bus clock)/2
 *  0b10..Alternate clock (ALTCLK)
 *  0b11..Asynchronous clock (ADACK)
 */
#define SADC_CFG1_ADICLK(x)                      (((uint32_t)(((uint32_t)(x)) << SADC_CFG1_ADICLK_SHIFT)) & SADC_CFG1_ADICLK_MASK)

#define SADC_CFG1_MODE_MASK                      (0xCUL)
#define SADC_CFG1_MODE_SHIFT                     (2UL)
/*! MODE - Conversion mode selection
 *  0b00..It is single-ended 8-bit conversion.
 *  0b01..It is single-ended 12-bit conversion .
 *  0b10..It is single-ended 10-bit conversion .
 *  0b11..It is single-ended 16-bit conversion.
 */
#define SADC_CFG1_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CFG1_MODE_SHIFT)) & SADC_CFG1_MODE_MASK)

#define SADC_CFG1_ADLSMP_MASK                    (0x10UL)
#define SADC_CFG1_ADLSMP_SHIFT                   (4UL)
/*! ADLSMP - Sample time configuration
 *  0b0..Short sample time.
 *  0b1..Long sample time.
 */
#define SADC_CFG1_ADLSMP(x)                      (((uint32_t)(((uint32_t)(x)) << SADC_CFG1_ADLSMP_SHIFT)) & SADC_CFG1_ADLSMP_MASK)

#define SADC_CFG1_ADIV_MASK                      (0x60UL)
#define SADC_CFG1_ADIV_SHIFT                     (5UL)
/*! ADIV - Clock Divide Select
 *  0b00..The divide ratio is 1 and the clock rate is input clock.
 *  0b01..The divide ratio is 2 and the clock rate is (input clock)/2.
 *  0b10..The divide ratio is 4 and the clock rate is (input clock)/4.
 *  0b11..The divide ratio is 8 and the clock rate is (input clock)/8.
 */
#define SADC_CFG1_ADIV(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CFG1_ADIV_SHIFT)) & SADC_CFG1_ADIV_MASK)

#define SADC_CFG1_ADLPC_MASK                     (0x80UL)
#define SADC_CFG1_ADLPC_SHIFT                    (7UL)
/*! ADLPC - Low-Power Configuration
 *  0b0..Normal power configuration.
 *  0b1..Low-power configuration. The power is reduced at the expense of maximum clock speed.
 */
#define SADC_CFG1_ADLPC(x)                       (((uint32_t)(((uint32_t)(x)) << SADC_CFG1_ADLPC_SHIFT)) & SADC_CFG1_ADLPC_MASK)
/*! @} */

/*! @name CFG2 - ADC Configuration Register 2 */
/*! @{ */

#define SADC_CFG2_ADLSTS_MASK                    (0x3UL)
#define SADC_CFG2_ADLSTS_SHIFT                   (0UL)
/*! ADLSTS - Long Sample Time Select
 *  0b00..Default longest sample time; 20 extra ADCK cycles; 24 ADCK cycles total.
 *  0b01..12 extra ADCK cycles; 16 ADCK cycles total sample time.
 *  0b10..6 extra ADCK cycles; 10 ADCK cycles total sample time.
 *  0b11..2 extra ADCK cycles; 6 ADCK cycles total sample time.
 */
#define SADC_CFG2_ADLSTS(x)                      (((uint32_t)(((uint32_t)(x)) << SADC_CFG2_ADLSTS_SHIFT)) & SADC_CFG2_ADLSTS_MASK)

#define SADC_CFG2_ADHSC_MASK                     (0x4UL)
#define SADC_CFG2_ADHSC_SHIFT                    (2UL)
/*! ADHSC - High-Speed Configuration
 *  0b0..Normal conversion sequence selected.
 *  0b1..High-speed conversion sequence selected with 2 additional ADCK cycles to total conversion time.
 */
#define SADC_CFG2_ADHSC(x)                       (((uint32_t)(((uint32_t)(x)) << SADC_CFG2_ADHSC_SHIFT)) & SADC_CFG2_ADHSC_MASK)

#define SADC_CFG2_ADACKEN_MASK                   (0x8UL)
#define SADC_CFG2_ADACKEN_SHIFT                  (3UL)
/*! ADACKEN - Asynchronous Clock Output Enable
 *  0b0..Asynchronous clock output disabled; Asynchronous clock is enabled only if selected by ADICLK and a conversion is active.
 *  0b1..Asynchronous clock and clock output is enabled regardless of the state of the ADC.
 */
#define SADC_CFG2_ADACKEN(x)                     (((uint32_t)(((uint32_t)(x)) << SADC_CFG2_ADACKEN_SHIFT)) & SADC_CFG2_ADACKEN_MASK)
/*! @} */

/*! @name R - ADC Data Result Register */
/*! @{ */

#define SADC_R_D_MASK                            (0xFFFFUL)
#define SADC_R_D_SHIFT                           (0UL)
/*! D - Data result */
#define SADC_R_D(x)                              (((uint32_t)(((uint32_t)(x)) << SADC_R_D_SHIFT)) & SADC_R_D_MASK)
/*! @} */

/*! @name CV1 - Compare Value Registers */
/*! @{ */

#define SADC_CV1_CV_MASK                         (0xFFFFUL)
#define SADC_CV1_CV_SHIFT                        (0UL)
/*! CV - Compare Value. */
#define SADC_CV1_CV(x)                           (((uint32_t)(((uint32_t)(x)) << SADC_CV1_CV_SHIFT)) & SADC_CV1_CV_MASK)
/*! @} */

/*! @name CV2 - Compare Value Registers */
/*! @{ */

#define SADC_CV2_CV_MASK                         (0xFFFFUL)
#define SADC_CV2_CV_SHIFT                        (0UL)
/*! CV - Compare Value. */
#define SADC_CV2_CV(x)                           (((uint32_t)(((uint32_t)(x)) << SADC_CV2_CV_SHIFT)) & SADC_CV2_CV_MASK)
/*! @} */

/*! @name SC2 - Status and Control Register 2 */
/*! @{ */

#define SADC_SC2_REFSEL_MASK                     (0x3UL)
#define SADC_SC2_REFSEL_SHIFT                    (0UL)
/*! REFSEL - Voltage Reference Selection
 *  0b00..Default voltage reference pin pair, that is, external pins VREFH and VREFL
 *  0b01..Alternate reference pair, that is, VALTH and VALTL . This pair may be additional external pins or
 *        internal sources depending on the MCU configuration. See the chip configuration information for details
 *        specific to this MCU
 *  0b10..Internal bandgap reference and associated ground reference (V BGH and V BGL ). Consult the Chip
 *        Configuration information for details specific to this MCU.
 *  0b11..Reserved
 */
#define SADC_SC2_REFSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SADC_SC2_REFSEL_SHIFT)) & SADC_SC2_REFSEL_MASK)

#define SADC_SC2_DMAEN_MASK                      (0x4UL)
#define SADC_SC2_DMAEN_SHIFT                     (2UL)
/*! DMAEN - DMA Enable
 *  0b0..DMA is disabled.
 *  0b1..DMA is enabled and will assert the ADC DMA request during an ADC conversion complete event noted when any
 *       of the SC1n[COCO] flags is asserted.
 */
#define SADC_SC2_DMAEN(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_SC2_DMAEN_SHIFT)) & SADC_SC2_DMAEN_MASK)

#define SADC_SC2_ACREN_MASK                      (0x8UL)
#define SADC_SC2_ACREN_SHIFT                     (3UL)
/*! ACREN - Compare Function Range Enable
 *  0b0..Range function disabled. Only CV1 is compared.
 *  0b1..Range function enabled. Both CV1 and CV2 are compared.
 */
#define SADC_SC2_ACREN(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_SC2_ACREN_SHIFT)) & SADC_SC2_ACREN_MASK)

#define SADC_SC2_ACFGT_MASK                      (0x10UL)
#define SADC_SC2_ACFGT_SHIFT                     (4UL)
/*! ACFGT - Compare Function Greater Than Enable
 *  0b0..Configures less than threshold, outside range not inclusive and inside range not inclusive; functionality
 *       based on the values placed in CV1 and CV2.
 *  0b1..Configures greater than or equal to threshold, outside and inside ranges inclusive; functionality based on the values placed in CV1 and CV2.
 */
#define SADC_SC2_ACFGT(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_SC2_ACFGT_SHIFT)) & SADC_SC2_ACFGT_MASK)

#define SADC_SC2_ACFE_MASK                       (0x20UL)
#define SADC_SC2_ACFE_SHIFT                      (5UL)
/*! ACFE - Compare Function Enable
 *  0b0..Compare function disabled.
 *  0b1..Compare function enabled.
 */
#define SADC_SC2_ACFE(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC2_ACFE_SHIFT)) & SADC_SC2_ACFE_MASK)

#define SADC_SC2_ADTRG_MASK                      (0x40UL)
#define SADC_SC2_ADTRG_SHIFT                     (6UL)
/*! ADTRG - Conversion Trigger Select
 *  0b0..Software trigger selected.
 *  0b1..Hardware trigger selected.
 */
#define SADC_SC2_ADTRG(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_SC2_ADTRG_SHIFT)) & SADC_SC2_ADTRG_MASK)

#define SADC_SC2_ADACT_MASK                      (0x80UL)
#define SADC_SC2_ADACT_SHIFT                     (7UL)
/*! ADACT - Conversion Active
 *  0b0..Conversion not in progress.
 *  0b1..Conversion in progress.
 */
#define SADC_SC2_ADACT(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_SC2_ADACT_SHIFT)) & SADC_SC2_ADACT_MASK)
/*! @} */

/*! @name SC3 - Status and Control Register 3 */
/*! @{ */

#define SADC_SC3_AVGS_MASK                       (0x3UL)
#define SADC_SC3_AVGS_SHIFT                      (0UL)
/*! AVGS - Hardware Average Select
 *  0b00..4 samples averaged.
 *  0b01..8 samples averaged.
 *  0b10..16 samples averaged.
 *  0b11..32 samples averaged.
 */
#define SADC_SC3_AVGS(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC3_AVGS_SHIFT)) & SADC_SC3_AVGS_MASK)

#define SADC_SC3_AVGE_MASK                       (0x4UL)
#define SADC_SC3_AVGE_SHIFT                      (2UL)
/*! AVGE - Hardware Average Enable
 *  0b0..Hardware average function disabled.
 *  0b1..Hardware average function enabled.
 */
#define SADC_SC3_AVGE(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC3_AVGE_SHIFT)) & SADC_SC3_AVGE_MASK)

#define SADC_SC3_ADCO_MASK                       (0x8UL)
#define SADC_SC3_ADCO_SHIFT                      (3UL)
/*! ADCO - Continuous Conversion Enable
 *  0b0..One conversion or one set of conversions if the hardware average function is enabled, that is, AVGE=1, after initiating a conversion.
 *  0b1..Continuous conversions or sets of conversions if the hardware average function is enabled, that is, AVGE=1, after initiating a conversion.
 */
#define SADC_SC3_ADCO(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC3_ADCO_SHIFT)) & SADC_SC3_ADCO_MASK)

#define SADC_SC3_ASSITRGEN_MASK                  (0x10UL)
#define SADC_SC3_ASSITRGEN_SHIFT                 (4UL)
/*! ASSITRGEN - Assist Trigger Enable
 *  0b0..Writes to ADCSC1 COCO bit don't have an affect on ADTRG.
 *  0b1..Writes to ADCSC1 COCO bit will be reflected into ADTRG register. Note: When ASSITRGEN is set, writes to
 *       ADCSC1 are delayed by 1/2 bus cycle to allow ADCSC1 COCO write to be updated in ADTRG register so
 *       conversion type can be correctly generated (software if coco write is 0 causing ADTRG to clear or hardware type if
 *       coco write is 1.). Note: User must ensure no hardware trigger is generated between the time ADCSC1 COCO
 *       bit is written if value of ADTRG will change to guarantee correct conversion type is generated.
 */
#define SADC_SC3_ASSITRGEN(x)                    (((uint32_t)(((uint32_t)(x)) << SADC_SC3_ASSITRGEN_SHIFT)) & SADC_SC3_ASSITRGEN_MASK)

#define SADC_SC3_CALF_MASK                       (0x40UL)
#define SADC_SC3_CALF_SHIFT                      (6UL)
/*! CALF - Calibration Failed Flag
 *  0b0..Calibration completed normally.
 *  0b1..Calibration failed. ADC accuracy specifications are not guaranteed.
 */
#define SADC_SC3_CALF(x)                         (((uint32_t)(((uint32_t)(x)) << SADC_SC3_CALF_SHIFT)) & SADC_SC3_CALF_MASK)

#define SADC_SC3_CAL_MASK                        (0x80UL)
#define SADC_SC3_CAL_SHIFT                       (7UL)
/*! CAL - Calibration */
#define SADC_SC3_CAL(x)                          (((uint32_t)(((uint32_t)(x)) << SADC_SC3_CAL_SHIFT)) & SADC_SC3_CAL_MASK)
/*! @} */

/*! @name OFS - ADC Offset Correction Register */
/*! @{ */

#define SADC_OFS_OFS_MASK                        (0xFFFFUL)
#define SADC_OFS_OFS_SHIFT                       (0UL)
/*! OFS - Offset Error Correction Value */
#define SADC_OFS_OFS(x)                          (((uint32_t)(((uint32_t)(x)) << SADC_OFS_OFS_SHIFT)) & SADC_OFS_OFS_MASK)
/*! @} */

/*! @name PG - ADC Plus-Side Gain Register */
/*! @{ */

#define SADC_PG_PG_MASK                          (0xFFFFUL)
#define SADC_PG_PG_SHIFT                         (0UL)
/*! PG - Plus-Side Gain */
#define SADC_PG_PG(x)                            (((uint32_t)(((uint32_t)(x)) << SADC_PG_PG_SHIFT)) & SADC_PG_PG_MASK)
/*! @} */

/*! @name CLPD - ADC Plus-Side General Calibration Value Register */
/*! @{ */

#define SADC_CLPD_CLPD_MASK                      (0x3FUL)
#define SADC_CLPD_CLPD_SHIFT                     (0UL)
#define SADC_CLPD_CLPD(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CLPD_CLPD_SHIFT)) & SADC_CLPD_CLPD_MASK)
/*! @} */

/*! @name CLPS - ADC Plus-Side General Calibration Value Register */
/*! @{ */

#define SADC_CLPS_CLPS_MASK                      (0x3FUL)
#define SADC_CLPS_CLPS_SHIFT                     (0UL)
#define SADC_CLPS_CLPS(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CLPS_CLPS_SHIFT)) & SADC_CLPS_CLPS_MASK)
/*! @} */

/*! @name CLP4 - ADC Plus-Side General Calibration Value Register */
/*! @{ */

#define SADC_CLP4_CLP4_MASK                      (0x3FFUL)
#define SADC_CLP4_CLP4_SHIFT                     (0UL)
#define SADC_CLP4_CLP4(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CLP4_CLP4_SHIFT)) & SADC_CLP4_CLP4_MASK)
/*! @} */

/*! @name CLP3 - ADC Plus-Side General Calibration Value Register */
/*! @{ */

#define SADC_CLP3_CLP3_MASK                      (0x1FFUL)
#define SADC_CLP3_CLP3_SHIFT                     (0UL)
#define SADC_CLP3_CLP3(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CLP3_CLP3_SHIFT)) & SADC_CLP3_CLP3_MASK)
/*! @} */

/*! @name CLP2 - ADC Plus-Side General Calibration Value Register */
/*! @{ */

#define SADC_CLP2_CLP2_MASK                      (0xFFUL)
#define SADC_CLP2_CLP2_SHIFT                     (0UL)
#define SADC_CLP2_CLP2(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CLP2_CLP2_SHIFT)) & SADC_CLP2_CLP2_MASK)
/*! @} */

/*! @name CLP1 - ADC Plus-Side General Calibration Value Register */
/*! @{ */

#define SADC_CLP1_CLP1_MASK                      (0x7FUL)
#define SADC_CLP1_CLP1_SHIFT                     (0UL)
#define SADC_CLP1_CLP1(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CLP1_CLP1_SHIFT)) & SADC_CLP1_CLP1_MASK)
/*! @} */

/*! @name CLP0 - ADC Plus-Side General Calibration Value Register */
/*! @{ */

#define SADC_CLP0_CLP0_MASK                      (0x3FUL)
#define SADC_CLP0_CLP0_SHIFT                     (0UL)
#define SADC_CLP0_CLP0(x)                        (((uint32_t)(((uint32_t)(x)) << SADC_CLP0_CLP0_SHIFT)) & SADC_CLP0_CLP0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SADC_Register_Masks */


/*!
 * @}
 */ /* end of group SADC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SADC_H_ */

