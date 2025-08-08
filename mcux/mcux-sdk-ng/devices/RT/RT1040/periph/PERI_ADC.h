/*
** ###################################################################
**     Processors:          MIMXRT1041DFP6B
**                          MIMXRT1041DJM6B
**                          MIMXRT1041XFP5B
**                          MIMXRT1041XJM5B
**                          MIMXRT1042DFP6B
**                          MIMXRT1042DJM6B
**                          MIMXRT1042XFP5B
**                          MIMXRT1042XJM5B
**                          MIMXRT1043DFP6B
**                          MIMXRT1043XFP5B
**                          MIMXRT1046DFQ6B
**                          MIMXRT1046XFQ5B
**
**     Version:             rev. 1.0, 2024-10-29
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
**     - rev. 0.1 (2021-07-20)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1041DFP6B) || defined(CPU_MIMXRT1041DJM6B) || defined(CPU_MIMXRT1041XFP5B) || defined(CPU_MIMXRT1041XJM5B))
#include "MIMXRT1041_COMMON.h"
#elif (defined(CPU_MIMXRT1042DFP6B) || defined(CPU_MIMXRT1042DJM6B) || defined(CPU_MIMXRT1042XFP5B) || defined(CPU_MIMXRT1042XJM5B))
#include "MIMXRT1042_COMMON.h"
#elif (defined(CPU_MIMXRT1043DFP6B) || defined(CPU_MIMXRT1043XFP5B))
#include "MIMXRT1043_COMMON.h"
#elif (defined(CPU_MIMXRT1046DFQ6B) || defined(CPU_MIMXRT1046XFQ5B))
#include "MIMXRT1046_COMMON.h"
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
#define ADC_HC_COUNT                              8u
#define ADC_R_COUNT                               8u

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t HC[ADC_HC_COUNT];                  /**< Control register for hardware triggers, array offset: 0x0, array step: 0x4 */
  __I  uint32_t HS;                                /**< Status register for HW triggers, offset: 0x20 */
  __I  uint32_t R[ADC_R_COUNT];                    /**< Data result register for HW triggers, array offset: 0x24, array step: 0x4 */
  __IO uint32_t CFG;                               /**< Configuration register, offset: 0x44 */
  __IO uint32_t GC;                                /**< General control register, offset: 0x48 */
  __IO uint32_t GS;                                /**< General status register, offset: 0x4C */
  __IO uint32_t CV;                                /**< Compare value register, offset: 0x50 */
  __IO uint32_t OFS;                               /**< Offset correction value register, offset: 0x54 */
  __IO uint32_t CAL;                               /**< Calibration value register, offset: 0x58 */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name HC - Control register for hardware triggers */
/*! @{ */

#define ADC_HC_ADCH_MASK                         (0x1FU)
#define ADC_HC_ADCH_SHIFT                        (0U)
/*! ADCH - Input Channel Select
 *  0b00000-0b01111..External channels 0 to 15 See External Signals for more information
 *  0b10000..External channel selection from ADC_ETC
 *  0b10001-0b10111..Reserved
 *  0b11000..Reserved.
 *  0b11001..VREFSH = internal channel, for ADC self-test, hard connected to VRH internally
 *  0b11010..Reserved.
 *  0b11011..Reserved.
 *  0b11100-0b11110..Reserved.
 *  0b11111..Conversion Disabled. Hardware Triggers will not initiate any conversion.
 */
#define ADC_HC_ADCH(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_HC_ADCH_SHIFT)) & ADC_HC_ADCH_MASK)

#define ADC_HC_AIEN_MASK                         (0x80U)
#define ADC_HC_AIEN_SHIFT                        (7U)
/*! AIEN - Conversion Complete Interrupt Enable/Disable Control
 *  0b0..Conversion complete interrupt disabled
 *  0b1..Conversion complete interrupt enabled
 */
#define ADC_HC_AIEN(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_HC_AIEN_SHIFT)) & ADC_HC_AIEN_MASK)
/*! @} */

/*! @name HS - Status register for HW triggers */
/*! @{ */

#define ADC_HS_COCO0_MASK                        (0x1U)
#define ADC_HS_COCO0_SHIFT                       (0U)
/*! COCO0 - Conversion Complete Flag */
#define ADC_HS_COCO0(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO0_SHIFT)) & ADC_HS_COCO0_MASK)

#define ADC_HS_COCO1_MASK                        (0x2U)
#define ADC_HS_COCO1_SHIFT                       (1U)
/*! COCO1 - Conversion Complete Flag */
#define ADC_HS_COCO1(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO1_SHIFT)) & ADC_HS_COCO1_MASK)

#define ADC_HS_COCO2_MASK                        (0x4U)
#define ADC_HS_COCO2_SHIFT                       (2U)
#define ADC_HS_COCO2(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO2_SHIFT)) & ADC_HS_COCO2_MASK)

#define ADC_HS_COCO3_MASK                        (0x8U)
#define ADC_HS_COCO3_SHIFT                       (3U)
#define ADC_HS_COCO3(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO3_SHIFT)) & ADC_HS_COCO3_MASK)

#define ADC_HS_COCO4_MASK                        (0x10U)
#define ADC_HS_COCO4_SHIFT                       (4U)
#define ADC_HS_COCO4(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO4_SHIFT)) & ADC_HS_COCO4_MASK)

#define ADC_HS_COCO5_MASK                        (0x20U)
#define ADC_HS_COCO5_SHIFT                       (5U)
#define ADC_HS_COCO5(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO5_SHIFT)) & ADC_HS_COCO5_MASK)

#define ADC_HS_COCO6_MASK                        (0x40U)
#define ADC_HS_COCO6_SHIFT                       (6U)
#define ADC_HS_COCO6(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO6_SHIFT)) & ADC_HS_COCO6_MASK)

#define ADC_HS_COCO7_MASK                        (0x80U)
#define ADC_HS_COCO7_SHIFT                       (7U)
#define ADC_HS_COCO7(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_HS_COCO7_SHIFT)) & ADC_HS_COCO7_MASK)
/*! @} */

/*! @name R - Data result register for HW triggers */
/*! @{ */

#define ADC_R_CDATA_MASK                         (0xFFFU)
#define ADC_R_CDATA_SHIFT                        (0U)
/*! CDATA - Data (result of an ADC conversion) */
#define ADC_R_CDATA(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_R_CDATA_SHIFT)) & ADC_R_CDATA_MASK)
/*! @} */

/*! @name CFG - Configuration register */
/*! @{ */

#define ADC_CFG_ADICLK_MASK                      (0x3U)
#define ADC_CFG_ADICLK_SHIFT                     (0U)
/*! ADICLK - Input Clock Select
 *  0b00..IPG clock
 *  0b01..IPG clock divided by 2
 *  0b10..Reserved
 *  0b11..Asynchronous clock (ADACK)
 */
#define ADC_CFG_ADICLK(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADICLK_SHIFT)) & ADC_CFG_ADICLK_MASK)

#define ADC_CFG_MODE_MASK                        (0xCU)
#define ADC_CFG_MODE_SHIFT                       (2U)
/*! MODE - Conversion Mode Selection
 *  0b00..8-bit conversion
 *  0b01..10-bit conversion
 *  0b10..12-bit conversion
 *  0b11..Reserved
 */
#define ADC_CFG_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CFG_MODE_SHIFT)) & ADC_CFG_MODE_MASK)

#define ADC_CFG_ADLSMP_MASK                      (0x10U)
#define ADC_CFG_ADLSMP_SHIFT                     (4U)
/*! ADLSMP - Long Sample Time Configuration
 *  0b0..Short sample mode.
 *  0b1..Long sample mode.
 */
#define ADC_CFG_ADLSMP(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADLSMP_SHIFT)) & ADC_CFG_ADLSMP_MASK)

#define ADC_CFG_ADIV_MASK                        (0x60U)
#define ADC_CFG_ADIV_SHIFT                       (5U)
/*! ADIV - Clock Divide Select
 *  0b00..Input clock
 *  0b01..Input clock / 2
 *  0b10..Input clock / 4
 *  0b11..Input clock / 8
 */
#define ADC_CFG_ADIV(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADIV_SHIFT)) & ADC_CFG_ADIV_MASK)

#define ADC_CFG_ADLPC_MASK                       (0x80U)
#define ADC_CFG_ADLPC_SHIFT                      (7U)
/*! ADLPC - Low-Power Configuration
 *  0b0..ADC hard block not in low power mode.
 *  0b1..ADC hard block in low power mode.
 */
#define ADC_CFG_ADLPC(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADLPC_SHIFT)) & ADC_CFG_ADLPC_MASK)

#define ADC_CFG_ADSTS_MASK                       (0x300U)
#define ADC_CFG_ADSTS_SHIFT                      (8U)
/*! ADSTS
 *  0b00..Sample period (ADC clocks) = 3 if ADLSMP=0b Sample period (ADC clocks) = 13 if ADLSMP=1b
 *  0b01..Sample period (ADC clocks) = 5 if ADLSMP=0b Sample period (ADC clocks) = 17 if ADLSMP=1b
 *  0b10..Sample period (ADC clocks) = 7 if ADLSMP=0b Sample period (ADC clocks) = 21 if ADLSMP=1b
 *  0b11..Sample period (ADC clocks) = 9 if ADLSMP=0b Sample period (ADC clocks) = 25 if ADLSMP=1b
 */
#define ADC_CFG_ADSTS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADSTS_SHIFT)) & ADC_CFG_ADSTS_MASK)

#define ADC_CFG_ADHSC_MASK                       (0x400U)
#define ADC_CFG_ADHSC_SHIFT                      (10U)
/*! ADHSC - High Speed Configuration
 *  0b0..Normal conversion selected.
 *  0b1..High speed conversion selected.
 */
#define ADC_CFG_ADHSC(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADHSC_SHIFT)) & ADC_CFG_ADHSC_MASK)

#define ADC_CFG_REFSEL_MASK                      (0x1800U)
#define ADC_CFG_REFSEL_SHIFT                     (11U)
/*! REFSEL - Voltage Reference Selection
 *  0b00..Selects VREFH/VREFL as reference voltage.
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define ADC_CFG_REFSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_REFSEL_SHIFT)) & ADC_CFG_REFSEL_MASK)

#define ADC_CFG_ADTRG_MASK                       (0x2000U)
#define ADC_CFG_ADTRG_SHIFT                      (13U)
/*! ADTRG - Conversion Trigger Select
 *  0b0..Software trigger selected
 *  0b1..Hardware trigger selected
 */
#define ADC_CFG_ADTRG(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADTRG_SHIFT)) & ADC_CFG_ADTRG_MASK)

#define ADC_CFG_AVGS_MASK                        (0xC000U)
#define ADC_CFG_AVGS_SHIFT                       (14U)
/*! AVGS - Hardware Average select
 *  0b00..4 samples averaged
 *  0b01..8 samples averaged
 *  0b10..16 samples averaged
 *  0b11..32 samples averaged
 */
#define ADC_CFG_AVGS(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CFG_AVGS_SHIFT)) & ADC_CFG_AVGS_MASK)

#define ADC_CFG_OVWREN_MASK                      (0x10000U)
#define ADC_CFG_OVWREN_SHIFT                     (16U)
/*! OVWREN - Data Overwrite Enable
 *  0b0..Disable the overwriting. Existing Data in Data result register will not be overwritten by subsequent converted data.
 *  0b1..Enable the overwriting.
 */
#define ADC_CFG_OVWREN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_OVWREN_SHIFT)) & ADC_CFG_OVWREN_MASK)
/*! @} */

/*! @name GC - General control register */
/*! @{ */

#define ADC_GC_ADACKEN_MASK                      (0x1U)
#define ADC_GC_ADACKEN_SHIFT                     (0U)
/*! ADACKEN - Asynchronous clock output enable
 *  0b0..Asynchronous clock output disabled; Asynchronous clock only enabled if selected by ADICLK and a conversion is active.
 *  0b1..Asynchronous clock and clock output enabled regardless of the state of the ADC
 */
#define ADC_GC_ADACKEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_GC_ADACKEN_SHIFT)) & ADC_GC_ADACKEN_MASK)

#define ADC_GC_DMAEN_MASK                        (0x2U)
#define ADC_GC_DMAEN_SHIFT                       (1U)
/*! DMAEN - DMA Enable
 *  0b0..DMA disabled (default)
 *  0b1..DMA enabled
 */
#define ADC_GC_DMAEN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_GC_DMAEN_SHIFT)) & ADC_GC_DMAEN_MASK)

#define ADC_GC_ACREN_MASK                        (0x4U)
#define ADC_GC_ACREN_SHIFT                       (2U)
/*! ACREN - Compare Function Range Enable
 *  0b0..Range function disabled. Only the compare value 1 of ADC_CV register (CV1) is compared.
 *  0b1..Range function enabled. Both compare values of ADC_CV registers (CV1 and CV2) are compared.
 */
#define ADC_GC_ACREN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_GC_ACREN_SHIFT)) & ADC_GC_ACREN_MASK)

#define ADC_GC_ACFGT_MASK                        (0x8U)
#define ADC_GC_ACFGT_SHIFT                       (3U)
/*! ACFGT - Compare Function Greater Than Enable
 *  0b0..Configures "Less Than Threshold, Outside Range Not Inclusive and Inside Range Not Inclusive"
 *       functionality based on the values placed in the ADC_CV register.
 *  0b1..Configures "Greater Than Or Equal To Threshold, Outside Range Inclusive and Inside Range Inclusive"
 *       functionality based on the values placed in the ADC_CV registers.
 */
#define ADC_GC_ACFGT(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_GC_ACFGT_SHIFT)) & ADC_GC_ACFGT_MASK)

#define ADC_GC_ACFE_MASK                         (0x10U)
#define ADC_GC_ACFE_SHIFT                        (4U)
/*! ACFE - Compare Function Enable
 *  0b0..Compare function disabled
 *  0b1..Compare function enabled
 */
#define ADC_GC_ACFE(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_GC_ACFE_SHIFT)) & ADC_GC_ACFE_MASK)

#define ADC_GC_AVGE_MASK                         (0x20U)
#define ADC_GC_AVGE_SHIFT                        (5U)
/*! AVGE - Hardware average enable
 *  0b0..Hardware average function disabled
 *  0b1..Hardware average function enabled
 */
#define ADC_GC_AVGE(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_GC_AVGE_SHIFT)) & ADC_GC_AVGE_MASK)

#define ADC_GC_ADCO_MASK                         (0x40U)
#define ADC_GC_ADCO_SHIFT                        (6U)
/*! ADCO - Continuous Conversion Enable
 *  0b0..One conversion or one set of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.
 *  0b1..Continuous conversions or sets of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.
 */
#define ADC_GC_ADCO(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_GC_ADCO_SHIFT)) & ADC_GC_ADCO_MASK)

#define ADC_GC_CAL_MASK                          (0x80U)
#define ADC_GC_CAL_SHIFT                         (7U)
/*! CAL - Calibration */
#define ADC_GC_CAL(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_GC_CAL_SHIFT)) & ADC_GC_CAL_MASK)
/*! @} */

/*! @name GS - General status register */
/*! @{ */

#define ADC_GS_ADACT_MASK                        (0x1U)
#define ADC_GS_ADACT_SHIFT                       (0U)
/*! ADACT - Conversion Active
 *  0b0..Conversion not in progress.
 *  0b1..Conversion in progress.
 */
#define ADC_GS_ADACT(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_GS_ADACT_SHIFT)) & ADC_GS_ADACT_MASK)

#define ADC_GS_CALF_MASK                         (0x2U)
#define ADC_GS_CALF_SHIFT                        (1U)
/*! CALF - Calibration Failed Flag
 *  0b0..Calibration completed normally.
 *  0b1..Calibration failed. ADC accuracy specifications are not guaranteed.
 */
#define ADC_GS_CALF(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_GS_CALF_SHIFT)) & ADC_GS_CALF_MASK)

#define ADC_GS_AWKST_MASK                        (0x4U)
#define ADC_GS_AWKST_SHIFT                       (2U)
/*! AWKST - Asynchronous wakeup interrupt status
 *  0b0..No asynchronous interrupt.
 *  0b1..Asynchronous wake up interrupt occurred in stop mode.
 */
#define ADC_GS_AWKST(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_GS_AWKST_SHIFT)) & ADC_GS_AWKST_MASK)
/*! @} */

/*! @name CV - Compare value register */
/*! @{ */

#define ADC_CV_CV1_MASK                          (0xFFFU)
#define ADC_CV_CV1_SHIFT                         (0U)
/*! CV1 - Compare Value 1 */
#define ADC_CV_CV1(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV_CV1_SHIFT)) & ADC_CV_CV1_MASK)

#define ADC_CV_CV2_MASK                          (0xFFF0000U)
#define ADC_CV_CV2_SHIFT                         (16U)
/*! CV2 - Compare Value 2 */
#define ADC_CV_CV2(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV_CV2_SHIFT)) & ADC_CV_CV2_MASK)
/*! @} */

/*! @name OFS - Offset correction value register */
/*! @{ */

#define ADC_OFS_OFS_MASK                         (0xFFFU)
#define ADC_OFS_OFS_SHIFT                        (0U)
/*! OFS - Offset value */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_OFS_OFS_SHIFT)) & ADC_OFS_OFS_MASK)

#define ADC_OFS_SIGN_MASK                        (0x1000U)
#define ADC_OFS_SIGN_SHIFT                       (12U)
/*! SIGN - Sign bit
 *  0b0..The offset value is added with the raw result
 *  0b1..The offset value is subtracted from the raw converted value
 */
#define ADC_OFS_SIGN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_OFS_SIGN_SHIFT)) & ADC_OFS_SIGN_MASK)
/*! @} */

/*! @name CAL - Calibration value register */
/*! @{ */

#define ADC_CAL_CAL_CODE_MASK                    (0xFU)
#define ADC_CAL_CAL_CODE_SHIFT                   (0U)
/*! CAL_CODE - Calibration Result Value */
#define ADC_CAL_CAL_CODE(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CAL_CAL_CODE_SHIFT)) & ADC_CAL_CAL_CODE_MASK)
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

