/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPCMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LPCMP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPCMP
 *
 * CMSIS Peripheral Access Layer for LPCMP
 */

#if !defined(PERI_LPCMP_H_)
#define PERI_LPCMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- LPCMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPCMP_Peripheral_Access_Layer LPCMP Peripheral Access Layer
 * @{
 */

/** LPCMP - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t CCR0;                              /**< Comparator Control Register 0, offset: 0x8 */
  __IO uint32_t CCR1;                              /**< Comparator Control Register 1, offset: 0xC */
  __IO uint32_t CCR2;                              /**< Comparator Control Register 2, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DCR;                               /**< DAC Control Register, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x1C */
  __IO uint32_t CSR;                               /**< Comparator Status Register, offset: 0x20 */
} LPCMP_Type;

/* ----------------------------------------------------------------------------
   -- LPCMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPCMP_Register_Masks LPCMP Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define LPCMP_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPCMP_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000001..Round robin feature
 */
#define LPCMP_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_FEATURE_SHIFT)) & LPCMP_VERID_FEATURE_MASK)

#define LPCMP_VERID_MINOR_MASK                   (0xFF0000U)
#define LPCMP_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number. This read only field returns the minor version number for the module specification. */
#define LPCMP_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MINOR_SHIFT)) & LPCMP_VERID_MINOR_MASK)

#define LPCMP_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPCMP_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number. This read only field returns the major version number for the module specification. */
#define LPCMP_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MAJOR_SHIFT)) & LPCMP_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define LPCMP_PARAM_DAC_RES_MASK                 (0xFU)
#define LPCMP_PARAM_DAC_RES_SHIFT                (0U)
/*! DAC_RES - DAC resolution
 *  0b0000..4 bit DAC
 *  0b0001..6 bit DAC
 *  0b0010..8 bit DAC
 *  0b0011..10 bit DAC
 *  0b0100..12 bit DAC
 *  0b0101..14 bit DAC
 *  0b0110..16 bit DAC
 */
#define LPCMP_PARAM_DAC_RES(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_PARAM_DAC_RES_SHIFT)) & LPCMP_PARAM_DAC_RES_MASK)
/*! @} */

/*! @name CCR0 - Comparator Control Register 0 */
/*! @{ */

#define LPCMP_CCR0_CMP_EN_MASK                   (0x1U)
#define LPCMP_CCR0_CMP_EN_SHIFT                  (0U)
/*! CMP_EN - Comparator Module Enable
 *  0b0..Analog Comparator is disabled.
 *  0b1..Analog Comparator is enabled.
 */
#define LPCMP_CCR0_CMP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_EN_SHIFT)) & LPCMP_CCR0_CMP_EN_MASK)

#define LPCMP_CCR0_CMP_STOP_EN_MASK              (0x2U)
#define LPCMP_CCR0_CMP_STOP_EN_SHIFT             (1U)
/*! CMP_STOP_EN - Comparator Module STOP Mode Enable
 *  0b0..Comparator is disabled in STOP modes regardless of CMP_EN.
 *  0b1..Comparator is enabled in STOP mode if CMP_EN is active
 */
#define LPCMP_CCR0_CMP_STOP_EN(x)                (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_STOP_EN_SHIFT)) & LPCMP_CCR0_CMP_STOP_EN_MASK)
/*! @} */

/*! @name CCR1 - Comparator Control Register 1 */
/*! @{ */

#define LPCMP_CCR1_WINDOW_EN_MASK                (0x1U)
#define LPCMP_CCR1_WINDOW_EN_SHIFT               (0U)
/*! WINDOW_EN - Windowing Enable
 *  0b0..Windowing mode is not selected.
 *  0b1..Windowing mode is selected.
 */
#define LPCMP_CCR1_WINDOW_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_WINDOW_EN_SHIFT)) & LPCMP_CCR1_WINDOW_EN_MASK)

#define LPCMP_CCR1_SAMPLE_EN_MASK                (0x2U)
#define LPCMP_CCR1_SAMPLE_EN_SHIFT               (1U)
/*! SAMPLE_EN - Sample Enable
 *  0b0..Sampling mode is not selected.
 *  0b1..Sampling mode is selected.
 */
#define LPCMP_CCR1_SAMPLE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_SAMPLE_EN_SHIFT)) & LPCMP_CCR1_SAMPLE_EN_MASK)

#define LPCMP_CCR1_DMA_EN_MASK                   (0x4U)
#define LPCMP_CCR1_DMA_EN_SHIFT                  (2U)
/*! DMA_EN - DMA Enable
 *  0b0..DMA is disabled.
 *  0b1..DMA is enabled.
 */
#define LPCMP_CCR1_DMA_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_DMA_EN_SHIFT)) & LPCMP_CCR1_DMA_EN_MASK)

#define LPCMP_CCR1_COUT_INV_MASK                 (0x8U)
#define LPCMP_CCR1_COUT_INV_SHIFT                (3U)
/*! COUT_INV - Comparator invert
 *  0b0..Does not invert the comparator output.
 *  0b1..Inverts the comparator output.
 */
#define LPCMP_CCR1_COUT_INV(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_INV_SHIFT)) & LPCMP_CCR1_COUT_INV_MASK)

#define LPCMP_CCR1_COUT_SEL_MASK                 (0x10U)
#define LPCMP_CCR1_COUT_SEL_SHIFT                (4U)
/*! COUT_SEL - Comparator Output Select
 *  0b0..Set CMPO to equal COUT (filtered comparator output).
 *  0b1..Set CMPO to equal COUTA (unfiltered comparator output).
 */
#define LPCMP_CCR1_COUT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_SEL_SHIFT)) & LPCMP_CCR1_COUT_SEL_MASK)

#define LPCMP_CCR1_COUT_PEN_MASK                 (0x20U)
#define LPCMP_CCR1_COUT_PEN_SHIFT                (5U)
/*! COUT_PEN - Comparator Output Pin Enable
 *  0b0..When COUT_PEN is 0, the comparator output (after window/filter settings dependent on software
 *       configuration) is not available to a packaged pin.
 *  0b1..When COUT_PEN is 1, and if the software has configured the comparator to own a packaged pin, the
 *       comparator output is available in a packaged pin.
 */
#define LPCMP_CCR1_COUT_PEN(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_PEN_SHIFT)) & LPCMP_CCR1_COUT_PEN_MASK)

#define LPCMP_CCR1_FILT_CNT_MASK                 (0x70000U)
#define LPCMP_CCR1_FILT_CNT_SHIFT                (16U)
/*! FILT_CNT - Filter Sample Count
 *  0b000..Filter is disabled. If SAMPLE_EN = 1, then COUT is a logic zero (this is not a legal state in , and is
 *         not recommended). If SAMPLE_EN = 0, COUT = COUTA.
 *  0b001..1 consecutive sample must agree (comparator output is simply sampled).
 *  0b010..2 consecutive samples must agree.
 *  0b011..3 consecutive samples must agree.
 *  0b100..4 consecutive samples must agree.
 *  0b101..5 consecutive samples must agree.
 *  0b110..6 consecutive samples must agree.
 *  0b111..7 consecutive samples must agree.
 */
#define LPCMP_CCR1_FILT_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_FILT_CNT_SHIFT)) & LPCMP_CCR1_FILT_CNT_MASK)

#define LPCMP_CCR1_FILT_PER_MASK                 (0xFF000000U)
#define LPCMP_CCR1_FILT_PER_SHIFT                (24U)
/*! FILT_PER - Filter Sample Period */
#define LPCMP_CCR1_FILT_PER(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_FILT_PER_SHIFT)) & LPCMP_CCR1_FILT_PER_MASK)
/*! @} */

/*! @name CCR2 - Comparator Control Register 2 */
/*! @{ */

#define LPCMP_CCR2_CMP_HPMD_MASK                 (0x1U)
#define LPCMP_CCR2_CMP_HPMD_SHIFT                (0U)
/*! CMP_HPMD - CMP High Power Mode Select
 *  0b0..Low speed comparison mode is selected.(when CMP_NPMD is 0)
 *  0b1..High speed comparison mode is selected.(when CMP_NPMD is 0)
 */
#define LPCMP_CCR2_CMP_HPMD(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_CMP_HPMD_SHIFT)) & LPCMP_CCR2_CMP_HPMD_MASK)

#define LPCMP_CCR2_CMP_NPMD_MASK                 (0x2U)
#define LPCMP_CCR2_CMP_NPMD_SHIFT                (1U)
/*! CMP_NPMD - CMP Nano Power Mode Select
 *  0b0..Nano Power Comparator is not enabled (mode is determined by CMP_HPMD)
 *  0b1..Nano Power Comparator is enabled
 */
#define LPCMP_CCR2_CMP_NPMD(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_CMP_NPMD_SHIFT)) & LPCMP_CCR2_CMP_NPMD_MASK)

#define LPCMP_CCR2_HYSTCTR_MASK                  (0x30U)
#define LPCMP_CCR2_HYSTCTR_SHIFT                 (4U)
/*! HYSTCTR - Comparator hard block hysteresis control. See chip data sheet to get the actual hystersis value with each level
 *  0b00..The hard block output has level 0 hysteresis internally.
 *  0b01..The hard block output has level 1 hysteresis internally.
 *  0b10..The hard block output has level 2 hysteresis internally.
 *  0b11..The hard block output has level 3 hysteresis internally.
 */
#define LPCMP_CCR2_HYSTCTR(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_HYSTCTR_SHIFT)) & LPCMP_CCR2_HYSTCTR_MASK)

#define LPCMP_CCR2_PSEL_MASK                     (0x70000U)
#define LPCMP_CCR2_PSEL_SHIFT                    (16U)
/*! PSEL - Plus Input MUX Control
 *  0b000..Input 0
 *  0b001..Input 1
 *  0b010..Input 2
 *  0b011..Input 3
 *  0b100..Input 4
 *  0b101..Input 5
 *  0b110..Input 6
 *  0b111..Internal DAC output
 */
#define LPCMP_CCR2_PSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_PSEL_SHIFT)) & LPCMP_CCR2_PSEL_MASK)

#define LPCMP_CCR2_MSEL_MASK                     (0x700000U)
#define LPCMP_CCR2_MSEL_SHIFT                    (20U)
/*! MSEL - Minus Input MUX Control
 *  0b000..Input 0
 *  0b001..Input 1
 *  0b010..Input 2
 *  0b011..Input 3
 *  0b100..Input 4
 *  0b101..Input 5
 *  0b110..Input 6
 *  0b111..Internal DAC output
 */
#define LPCMP_CCR2_MSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_MSEL_SHIFT)) & LPCMP_CCR2_MSEL_MASK)
/*! @} */

/*! @name DCR - DAC Control Register */
/*! @{ */

#define LPCMP_DCR_DAC_EN_MASK                    (0x1U)
#define LPCMP_DCR_DAC_EN_SHIFT                   (0U)
/*! DAC_EN - DAC Enable
 *  0b0..DAC is disabled.
 *  0b1..DAC is enabled.
 */
#define LPCMP_DCR_DAC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_EN_SHIFT)) & LPCMP_DCR_DAC_EN_MASK)

#define LPCMP_DCR_DAC_HPMD_MASK                  (0x2U)
#define LPCMP_DCR_DAC_HPMD_SHIFT                 (1U)
/*! DAC_HPMD - DAC High Power Mode Select
 *  0b0..DAC high power mode is not enabled.
 *  0b1..DAC high power mode is enabled.
 */
#define LPCMP_DCR_DAC_HPMD(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_HPMD_SHIFT)) & LPCMP_DCR_DAC_HPMD_MASK)

#define LPCMP_DCR_VRSEL_MASK                     (0x100U)
#define LPCMP_DCR_VRSEL_SHIFT                    (8U)
/*! VRSEL - Supply Voltage Reference Source Select
 *  0b0..vrefh_int is selected as resistor ladder network supply reference Vin.
 *  0b1..vrefh_ext is selected as resistor ladder network supply reference Vin.
 */
#define LPCMP_DCR_VRSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_VRSEL_SHIFT)) & LPCMP_DCR_VRSEL_MASK)

#define LPCMP_DCR_DAC_DATA_MASK                  (0x3F0000U)
#define LPCMP_DCR_DAC_DATA_SHIFT                 (16U)
/*! DAC_DATA - DAC Output Voltage Select */
#define LPCMP_DCR_DAC_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_DATA_SHIFT)) & LPCMP_DCR_DAC_DATA_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define LPCMP_IER_CFR_IE_MASK                    (0x1U)
#define LPCMP_IER_CFR_IE_SHIFT                   (0U)
/*! CFR_IE - Comparator Flag Rising Interrupt Enable
 *  0b0..CFR interrupt is disabled.
 *  0b1..CFR interrupt is enabled.
 */
#define LPCMP_IER_CFR_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFR_IE_SHIFT)) & LPCMP_IER_CFR_IE_MASK)

#define LPCMP_IER_CFF_IE_MASK                    (0x2U)
#define LPCMP_IER_CFF_IE_SHIFT                   (1U)
/*! CFF_IE - Comparator Flag Falling Interrupt Enable
 *  0b0..CFF interrupt is disabled.
 *  0b1..CFF interrupt is enabled.
 */
#define LPCMP_IER_CFF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFF_IE_SHIFT)) & LPCMP_IER_CFF_IE_MASK)
/*! @} */

/*! @name CSR - Comparator Status Register */
/*! @{ */

#define LPCMP_CSR_CFR_MASK                       (0x1U)
#define LPCMP_CSR_CFR_SHIFT                      (0U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..A rising edge has not been detected on COUT.
 *  0b1..A rising edge on COUT has occurred.
 */
#define LPCMP_CSR_CFR(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFR_SHIFT)) & LPCMP_CSR_CFR_MASK)

#define LPCMP_CSR_CFF_MASK                       (0x2U)
#define LPCMP_CSR_CFF_SHIFT                      (1U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..A falling edge has not been detected on COUT.
 *  0b1..A falling edge on COUT has occurred.
 */
#define LPCMP_CSR_CFF(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFF_SHIFT)) & LPCMP_CSR_CFF_MASK)

#define LPCMP_CSR_COUT_MASK                      (0x100U)
#define LPCMP_CSR_COUT_SHIFT                     (8U)
/*! COUT - Analog Comparator Output */
#define LPCMP_CSR_COUT(x)                        (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_COUT_SHIFT)) & LPCMP_CSR_COUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPCMP_Register_Masks */


/*!
 * @}
 */ /* end of group LPCMP_Peripheral_Access_Layer */


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


#endif  /* PERI_LPCMP_H_ */

