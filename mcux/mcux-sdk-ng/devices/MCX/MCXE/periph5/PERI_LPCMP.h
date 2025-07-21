/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
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
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_LPCMP.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for LPCMP
 *
 * CMSIS Peripheral Access Layer for LPCMP
 */

#if !defined(PERI_LPCMP_H_)
#define PERI_LPCMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t CCR0;                              /**< Comparator Control Register 0, offset: 0x8 */
  __IO uint32_t CCR1;                              /**< Comparator Control Register 1, offset: 0xC */
  __IO uint32_t CCR2;                              /**< Comparator Control Register 2, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DCR;                               /**< DAC Control, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t CSR;                               /**< Comparator Status, offset: 0x20 */
  __IO uint32_t RRCR0;                             /**< Round Robin Control Register 0, offset: 0x24 */
  __IO uint32_t RRCR1;                             /**< Round Robin Control Register 1, offset: 0x28 */
  __IO uint32_t RRCSR;                             /**< Round Robin Control and Status, offset: 0x2C */
  __IO uint32_t RRSR;                              /**< Round Robin Status, offset: 0x30 */
} LPCMP_Type;

/* ----------------------------------------------------------------------------
   -- LPCMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPCMP_Register_Masks LPCMP Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define LPCMP_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPCMP_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000001..Round robin feature
 */
#define LPCMP_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_FEATURE_SHIFT)) & LPCMP_VERID_FEATURE_MASK)

#define LPCMP_VERID_MINOR_MASK                   (0xFF0000U)
#define LPCMP_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define LPCMP_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MINOR_SHIFT)) & LPCMP_VERID_MINOR_MASK)

#define LPCMP_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPCMP_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define LPCMP_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MAJOR_SHIFT)) & LPCMP_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPCMP_PARAM_DAC_RES_MASK                 (0xFU)
#define LPCMP_PARAM_DAC_RES_SHIFT                (0U)
/*! DAC_RES - DAC Resolution
 *  0b0000..4-bit DAC
 *  0b0001..6-bit DAC
 *  0b0010..8-bit DAC
 *  0b0011..10-bit DAC
 *  0b0100..12-bit DAC
 *  0b0101..14-bit DAC
 *  0b0110..16-bit DAC
 */
#define LPCMP_PARAM_DAC_RES(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_PARAM_DAC_RES_SHIFT)) & LPCMP_PARAM_DAC_RES_MASK)
/*! @} */

/*! @name CCR0 - Comparator Control Register 0 */
/*! @{ */

#define LPCMP_CCR0_CMP_EN_MASK                   (0x1U)
#define LPCMP_CCR0_CMP_EN_SHIFT                  (0U)
/*! CMP_EN - Comparator Enable
 *  0b0..Disables (The analog logic remains off and consumes no power.)
 *  0b1..Enables
 */
#define LPCMP_CCR0_CMP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_EN_SHIFT)) & LPCMP_CCR0_CMP_EN_MASK)

#define LPCMP_CCR0_CMP_STOP_EN_MASK              (0x2U)
#define LPCMP_CCR0_CMP_STOP_EN_SHIFT             (1U)
/*! CMP_STOP_EN - Comparator STANDBY Mode Enable
 *  0b0..Disable the analog comparator regardless of CMP_EN.
 *  0b1..Allows CMP_EN to enable the analog comparator.
 */
#define LPCMP_CCR0_CMP_STOP_EN(x)                (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_STOP_EN_SHIFT)) & LPCMP_CCR0_CMP_STOP_EN_MASK)

#define LPCMP_CCR0_LINKEN_MASK                   (0x4U)
#define LPCMP_CCR0_LINKEN_SHIFT                  (2U)
/*! LINKEN - CMP-to-DAC Link Enable
 *  0b0..Disable the CMP-to-DAC link: enabling or disabling the DAC is independent from enabling or disabling the CMP.
 *  0b1..Enable the CMP-to-DAC link: the DAC enable/disable is controlled by the CMP_EN bit instead of
 *       DCR[DAC_EN]. Also, when the CMP is auto-disabled because software selects the same signal for both the plus and minus
 *       comparator inputs, the DAC is disabled too.
 */
#define LPCMP_CCR0_LINKEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_LINKEN_SHIFT)) & LPCMP_CCR0_LINKEN_MASK)
/*! @} */

/*! @name CCR1 - Comparator Control Register 1 */
/*! @{ */

#define LPCMP_CCR1_WINDOW_EN_MASK                (0x1U)
#define LPCMP_CCR1_WINDOW_EN_SHIFT               (0U)
/*! WINDOW_EN - Windowing Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_CCR1_WINDOW_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_WINDOW_EN_SHIFT)) & LPCMP_CCR1_WINDOW_EN_MASK)

#define LPCMP_CCR1_SAMPLE_EN_MASK                (0x2U)
#define LPCMP_CCR1_SAMPLE_EN_SHIFT               (1U)
/*! SAMPLE_EN - Sampling Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_CCR1_SAMPLE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_SAMPLE_EN_SHIFT)) & LPCMP_CCR1_SAMPLE_EN_MASK)

#define LPCMP_CCR1_DMA_EN_MASK                   (0x4U)
#define LPCMP_CCR1_DMA_EN_SHIFT                  (2U)
/*! DMA_EN - DMA Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_CCR1_DMA_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_DMA_EN_SHIFT)) & LPCMP_CCR1_DMA_EN_MASK)

#define LPCMP_CCR1_COUT_INV_MASK                 (0x8U)
#define LPCMP_CCR1_COUT_INV_SHIFT                (3U)
/*! COUT_INV - Comparator Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define LPCMP_CCR1_COUT_INV(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_INV_SHIFT)) & LPCMP_CCR1_COUT_INV_MASK)

#define LPCMP_CCR1_COUT_SEL_MASK                 (0x10U)
#define LPCMP_CCR1_COUT_SEL_SHIFT                (4U)
/*! COUT_SEL - Comparator Output Select
 *  0b0..Use COUT (filtered)
 *  0b1..Use COUTA (unfiltered)
 */
#define LPCMP_CCR1_COUT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_SEL_SHIFT)) & LPCMP_CCR1_COUT_SEL_MASK)

#define LPCMP_CCR1_COUT_PEN_MASK                 (0x20U)
#define LPCMP_CCR1_COUT_PEN_SHIFT                (5U)
/*! COUT_PEN - Comparator Output Pin Enable
 *  0b0..Not available
 *  0b1..Available
 */
#define LPCMP_CCR1_COUT_PEN(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUT_PEN_SHIFT)) & LPCMP_CCR1_COUT_PEN_MASK)

#define LPCMP_CCR1_COUTA_OWEN_MASK               (0x40U)
#define LPCMP_CCR1_COUTA_OWEN_SHIFT              (6U)
/*! COUTA_OWEN - COUTA_OW Enable
 *  0b0..COUTA holds the last sampled value.
 *  0b1..Enables the COUTA signal value to be defined by COUTA_OW.
 */
#define LPCMP_CCR1_COUTA_OWEN(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUTA_OWEN_SHIFT)) & LPCMP_CCR1_COUTA_OWEN_MASK)

#define LPCMP_CCR1_COUTA_OW_MASK                 (0x80U)
#define LPCMP_CCR1_COUTA_OW_SHIFT                (7U)
/*! COUTA_OW - COUTA Output Level for Closed Window
 *  0b0..COUTA is 0
 *  0b1..COUTA is 1
 */
#define LPCMP_CCR1_COUTA_OW(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_COUTA_OW_SHIFT)) & LPCMP_CCR1_COUTA_OW_MASK)

#define LPCMP_CCR1_WINDOW_INV_MASK               (0x100U)
#define LPCMP_CCR1_WINDOW_INV_SHIFT              (8U)
/*! WINDOW_INV - WINDOW/SAMPLE Signal Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define LPCMP_CCR1_WINDOW_INV(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_WINDOW_INV_SHIFT)) & LPCMP_CCR1_WINDOW_INV_MASK)

#define LPCMP_CCR1_WINDOW_CLS_MASK               (0x200U)
#define LPCMP_CCR1_WINDOW_CLS_SHIFT              (9U)
/*! WINDOW_CLS - CMPO Event Window Close
 *  0b0..CMPO event cannot close the window
 *  0b1..CMPO event can close the window
 */
#define LPCMP_CCR1_WINDOW_CLS(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_WINDOW_CLS_SHIFT)) & LPCMP_CCR1_WINDOW_CLS_MASK)

#define LPCMP_CCR1_EVT_SEL_MASK                  (0xC00U)
#define LPCMP_CCR1_EVT_SEL_SHIFT                 (10U)
/*! EVT_SEL - CMPO Event Select
 *  0b00..Rising edge
 *  0b01..Falling edge
 *  0b1x..Both edges
 */
#define LPCMP_CCR1_EVT_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_EVT_SEL_SHIFT)) & LPCMP_CCR1_EVT_SEL_MASK)

#define LPCMP_CCR1_FILT_CNT_MASK                 (0x70000U)
#define LPCMP_CCR1_FILT_CNT_SHIFT                (16U)
/*! FILT_CNT - Filter Sample Count
 *  0b000..Filter is bypassed: COUT = COUTA
 *  0b001..1 consecutive sample (Comparator output is simply sampled.)
 *  0b010..2 consecutive samples
 *  0b011..3 consecutive samples
 *  0b100..4 consecutive samples
 *  0b101..5 consecutive samples
 *  0b110..6 consecutive samples
 *  0b111..7 consecutive samples
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
 *  0b0..Low power (speed) comparison mode
 *  0b1..High power (speed) comparison mode
 */
#define LPCMP_CCR2_CMP_HPMD(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_CMP_HPMD_SHIFT)) & LPCMP_CCR2_CMP_HPMD_MASK)

#define LPCMP_CCR2_OFFSET_MASK                   (0x4U)
#define LPCMP_CCR2_OFFSET_SHIFT                  (2U)
/*! OFFSET - Comparator Offset Control
 *  0b0..Level 0: The hysteresis selected by HYSTCTR is valid for both directions (rising and falling).
 *  0b1..Level 1: Hysteresis does not apply when INP (input-plus) crosses INM (input-minus) in the rising
 *       direction or when INM crosses INP in the falling direction. Hysteresis still applies for INP crossing INM in the
 *       falling direction.
 */
#define LPCMP_CCR2_OFFSET(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_OFFSET_SHIFT)) & LPCMP_CCR2_OFFSET_MASK)

#define LPCMP_CCR2_HYSTCTR_MASK                  (0x30U)
#define LPCMP_CCR2_HYSTCTR_SHIFT                 (4U)
/*! HYSTCTR - Comparator Hysteresis Control
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define LPCMP_CCR2_HYSTCTR(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_HYSTCTR_SHIFT)) & LPCMP_CCR2_HYSTCTR_MASK)

#define LPCMP_CCR2_PSEL_MASK                     (0x70000U)
#define LPCMP_CCR2_PSEL_SHIFT                    (16U)
/*! PSEL - Plus Input MUX Select
 *  0b000..Input channel 0
 *  0b001..Input channel 1
 *  0b010..Input channel 2
 *  0b011..Input channel 3
 *  0b100..Input channel 4
 *  0b101..Input channel 5
 *  0b110..Input channel 6
 *  0b111..Input channel 7
 */
#define LPCMP_CCR2_PSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_PSEL_SHIFT)) & LPCMP_CCR2_PSEL_MASK)

#define LPCMP_CCR2_MSEL_MASK                     (0x700000U)
#define LPCMP_CCR2_MSEL_SHIFT                    (20U)
/*! MSEL - Minus Input MUX Select
 *  0b000..Input channel 0
 *  0b001..Input channel 1
 *  0b010..Input channel 2
 *  0b011..Input channel 3
 *  0b100..Input channel 4
 *  0b101..Input channel 5
 *  0b110..Input channel 6
 *  0b111..Input channel 7
 */
#define LPCMP_CCR2_MSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_MSEL_SHIFT)) & LPCMP_CCR2_MSEL_MASK)

#define LPCMP_CCR2_INPSEL_MASK                   (0x3000000U)
#define LPCMP_CCR2_INPSEL_SHIFT                  (24U)
/*! INPSEL - Input Plus Select
 *  0b00..IN0: from the 8-bit DAC output
 *  0b01..IN1: from the analog 8-1 mux
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define LPCMP_CCR2_INPSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_INPSEL_SHIFT)) & LPCMP_CCR2_INPSEL_MASK)

#define LPCMP_CCR2_INMSEL_MASK                   (0x30000000U)
#define LPCMP_CCR2_INMSEL_SHIFT                  (28U)
/*! INMSEL - Input Minus Select
 *  0b00..IN0: from the 8-bit DAC output
 *  0b01..IN1: from the analog 8-1 mux
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define LPCMP_CCR2_INMSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR2_INMSEL_SHIFT)) & LPCMP_CCR2_INMSEL_MASK)
/*! @} */

/*! @name DCR - DAC Control */
/*! @{ */

#define LPCMP_DCR_DAC_EN_MASK                    (0x1U)
#define LPCMP_DCR_DAC_EN_SHIFT                   (0U)
/*! DAC_EN - DAC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_DCR_DAC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_EN_SHIFT)) & LPCMP_DCR_DAC_EN_MASK)

#define LPCMP_DCR_VRSEL_MASK                     (0x100U)
#define LPCMP_DCR_VRSEL_SHIFT                    (8U)
/*! VRSEL - DAC Reference High Voltage Source Select
 *  0b0..vrefh0
 *  0b1..vrefh1
 */
#define LPCMP_DCR_VRSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_VRSEL_SHIFT)) & LPCMP_DCR_VRSEL_MASK)

#define LPCMP_DCR_DAC_DATA_MASK                  (0xFF0000U)
#define LPCMP_DCR_DAC_DATA_SHIFT                 (16U)
/*! DAC_DATA - DAC Output Voltage Select */
#define LPCMP_DCR_DAC_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_DATA_SHIFT)) & LPCMP_DCR_DAC_DATA_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define LPCMP_IER_CFR_IE_MASK                    (0x1U)
#define LPCMP_IER_CFR_IE_SHIFT                   (0U)
/*! CFR_IE - Comparator Flag Rising Interrupt Enable
 *  0b0..Disables the comparator flag rising interrupt.
 *  0b1..Enables the comparator flag rising interrupt when CFR is set.
 */
#define LPCMP_IER_CFR_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFR_IE_SHIFT)) & LPCMP_IER_CFR_IE_MASK)

#define LPCMP_IER_CFF_IE_MASK                    (0x2U)
#define LPCMP_IER_CFF_IE_SHIFT                   (1U)
/*! CFF_IE - Comparator Flag Falling Interrupt Enable
 *  0b0..Disables the comparator flag falling interrupt.
 *  0b1..Enables the comparator flag falling interrupt when CFF is set.
 */
#define LPCMP_IER_CFF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFF_IE_SHIFT)) & LPCMP_IER_CFF_IE_MASK)

#define LPCMP_IER_RRF_IE_MASK                    (0x4U)
#define LPCMP_IER_RRF_IE_SHIFT                   (2U)
/*! RRF_IE - Round-Robin Flag Interrupt Enable
 *  0b0..Disables the round-robin flag interrupt.
 *  0b1..Enables the round-robin flag interrupt when the comparison result changes for a given channel.
 */
#define LPCMP_IER_RRF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_RRF_IE_SHIFT)) & LPCMP_IER_RRF_IE_MASK)
/*! @} */

/*! @name CSR - Comparator Status */
/*! @{ */

#define LPCMP_CSR_CFR_MASK                       (0x1U)
#define LPCMP_CSR_CFR_SHIFT                      (0U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..Not detected
 *  0b1..Detected
 */
#define LPCMP_CSR_CFR(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFR_SHIFT)) & LPCMP_CSR_CFR_MASK)

#define LPCMP_CSR_CFF_MASK                       (0x2U)
#define LPCMP_CSR_CFF_SHIFT                      (1U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..Not detected
 *  0b1..Detected
 */
#define LPCMP_CSR_CFF(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFF_SHIFT)) & LPCMP_CSR_CFF_MASK)

#define LPCMP_CSR_RRF_MASK                       (0x4U)
#define LPCMP_CSR_RRF_SHIFT                      (2U)
/*! RRF - Round-Robin Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define LPCMP_CSR_RRF(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_RRF_SHIFT)) & LPCMP_CSR_RRF_MASK)

#define LPCMP_CSR_COUT_MASK                      (0x100U)
#define LPCMP_CSR_COUT_SHIFT                     (8U)
/*! COUT - Analog Comparator Output */
#define LPCMP_CSR_COUT(x)                        (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_COUT_SHIFT)) & LPCMP_CSR_COUT_MASK)
/*! @} */

/*! @name RRCR0 - Round Robin Control Register 0 */
/*! @{ */

#define LPCMP_RRCR0_RR_EN_MASK                   (0x1U)
#define LPCMP_RRCR0_RR_EN_SHIFT                  (0U)
/*! RR_EN - Round-Robin Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR0_RR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_RR_EN_SHIFT)) & LPCMP_RRCR0_RR_EN_MASK)

#define LPCMP_RRCR0_RR_NSAM_MASK                 (0x300U)
#define LPCMP_RRCR0_RR_NSAM_SHIFT                (8U)
/*! RR_NSAM - Number of Sample Clocks
 *  0b00..0 clock
 *  0b01..1 clock
 *  0b10..2 clocks
 *  0b11..3 clocks
 */
#define LPCMP_RRCR0_RR_NSAM(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_RR_NSAM_SHIFT)) & LPCMP_RRCR0_RR_NSAM_MASK)

#define LPCMP_RRCR0_RR_INITMOD_MASK              (0x3F0000U)
#define LPCMP_RRCR0_RR_INITMOD_SHIFT             (16U)
/*! RR_INITMOD - Initialization Delay Modulus
 *  0b000000..63 cycles (same as 111111b)
 *  0b000001-0b111111..1 to 63 cycles
 */
#define LPCMP_RRCR0_RR_INITMOD(x)                (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_RR_INITMOD_SHIFT)) & LPCMP_RRCR0_RR_INITMOD_MASK)
/*! @} */

/*! @name RRCR1 - Round Robin Control Register 1 */
/*! @{ */

#define LPCMP_RRCR1_RR_CH0EN_MASK                (0x1U)
#define LPCMP_RRCR1_RR_CH0EN_SHIFT               (0U)
/*! RR_CH0EN - Channel 0 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH0EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH0EN_SHIFT)) & LPCMP_RRCR1_RR_CH0EN_MASK)

#define LPCMP_RRCR1_RR_CH1EN_MASK                (0x2U)
#define LPCMP_RRCR1_RR_CH1EN_SHIFT               (1U)
/*! RR_CH1EN - Channel 1 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH1EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH1EN_SHIFT)) & LPCMP_RRCR1_RR_CH1EN_MASK)

#define LPCMP_RRCR1_RR_CH2EN_MASK                (0x4U)
#define LPCMP_RRCR1_RR_CH2EN_SHIFT               (2U)
/*! RR_CH2EN - Channel 2 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH2EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH2EN_SHIFT)) & LPCMP_RRCR1_RR_CH2EN_MASK)

#define LPCMP_RRCR1_RR_CH3EN_MASK                (0x8U)
#define LPCMP_RRCR1_RR_CH3EN_SHIFT               (3U)
/*! RR_CH3EN - Channel 3 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH3EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH3EN_SHIFT)) & LPCMP_RRCR1_RR_CH3EN_MASK)

#define LPCMP_RRCR1_RR_CH4EN_MASK                (0x10U)
#define LPCMP_RRCR1_RR_CH4EN_SHIFT               (4U)
/*! RR_CH4EN - Channel 4 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH4EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH4EN_SHIFT)) & LPCMP_RRCR1_RR_CH4EN_MASK)

#define LPCMP_RRCR1_RR_CH5EN_MASK                (0x20U)
#define LPCMP_RRCR1_RR_CH5EN_SHIFT               (5U)
/*! RR_CH5EN - Channel 5 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH5EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH5EN_SHIFT)) & LPCMP_RRCR1_RR_CH5EN_MASK)

#define LPCMP_RRCR1_RR_CH6EN_MASK                (0x40U)
#define LPCMP_RRCR1_RR_CH6EN_SHIFT               (6U)
/*! RR_CH6EN - Channel 6 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH6EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH6EN_SHIFT)) & LPCMP_RRCR1_RR_CH6EN_MASK)

#define LPCMP_RRCR1_RR_CH7EN_MASK                (0x80U)
#define LPCMP_RRCR1_RR_CH7EN_SHIFT               (7U)
/*! RR_CH7EN - Channel 7 Input Enable in Trigger Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPCMP_RRCR1_RR_CH7EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_RR_CH7EN_SHIFT)) & LPCMP_RRCR1_RR_CH7EN_MASK)

#define LPCMP_RRCR1_FIXP_MASK                    (0x10000U)
#define LPCMP_RRCR1_FIXP_SHIFT                   (16U)
/*! FIXP - Fixed Port
 *  0b0..Fix the plus port. Sweep only the inputs to the minus port.
 *  0b1..Fix the minus port. Sweep only the inputs to the plus port.
 */
#define LPCMP_RRCR1_FIXP(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_FIXP_SHIFT)) & LPCMP_RRCR1_FIXP_MASK)

#define LPCMP_RRCR1_FIXCH_MASK                   (0x700000U)
#define LPCMP_RRCR1_FIXCH_SHIFT                  (20U)
/*! FIXCH - Fixed Channel Select
 *  0b000..Channel 0
 *  0b001..Channel 1
 *  0b010..Channel 2
 *  0b011..Channel 3
 *  0b100..Channel 4
 *  0b101..Channel 5
 *  0b110..Channel 6
 *  0b111..Channel 7
 */
#define LPCMP_RRCR1_FIXCH(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR1_FIXCH_SHIFT)) & LPCMP_RRCR1_FIXCH_MASK)
/*! @} */

/*! @name RRCSR - Round Robin Control and Status */
/*! @{ */

#define LPCMP_RRCSR_RR_CH0OUT_MASK               (0x1U)
#define LPCMP_RRCSR_RR_CH0OUT_SHIFT              (0U)
/*! RR_CH0OUT - Comparison Result for Channel 0 */
#define LPCMP_RRCSR_RR_CH0OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH0OUT_SHIFT)) & LPCMP_RRCSR_RR_CH0OUT_MASK)

#define LPCMP_RRCSR_RR_CH1OUT_MASK               (0x2U)
#define LPCMP_RRCSR_RR_CH1OUT_SHIFT              (1U)
/*! RR_CH1OUT - Comparison Result for Channel 1 */
#define LPCMP_RRCSR_RR_CH1OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH1OUT_SHIFT)) & LPCMP_RRCSR_RR_CH1OUT_MASK)

#define LPCMP_RRCSR_RR_CH2OUT_MASK               (0x4U)
#define LPCMP_RRCSR_RR_CH2OUT_SHIFT              (2U)
/*! RR_CH2OUT - Comparison Result for Channel 2 */
#define LPCMP_RRCSR_RR_CH2OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH2OUT_SHIFT)) & LPCMP_RRCSR_RR_CH2OUT_MASK)

#define LPCMP_RRCSR_RR_CH3OUT_MASK               (0x8U)
#define LPCMP_RRCSR_RR_CH3OUT_SHIFT              (3U)
/*! RR_CH3OUT - Comparison Result for Channel 3 */
#define LPCMP_RRCSR_RR_CH3OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH3OUT_SHIFT)) & LPCMP_RRCSR_RR_CH3OUT_MASK)

#define LPCMP_RRCSR_RR_CH4OUT_MASK               (0x10U)
#define LPCMP_RRCSR_RR_CH4OUT_SHIFT              (4U)
/*! RR_CH4OUT - Comparison Result for Channel 4 */
#define LPCMP_RRCSR_RR_CH4OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH4OUT_SHIFT)) & LPCMP_RRCSR_RR_CH4OUT_MASK)

#define LPCMP_RRCSR_RR_CH5OUT_MASK               (0x20U)
#define LPCMP_RRCSR_RR_CH5OUT_SHIFT              (5U)
/*! RR_CH5OUT - Comparison Result for Channel 5 */
#define LPCMP_RRCSR_RR_CH5OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH5OUT_SHIFT)) & LPCMP_RRCSR_RR_CH5OUT_MASK)

#define LPCMP_RRCSR_RR_CH6OUT_MASK               (0x40U)
#define LPCMP_RRCSR_RR_CH6OUT_SHIFT              (6U)
/*! RR_CH6OUT - Comparison Result for Channel 6 */
#define LPCMP_RRCSR_RR_CH6OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH6OUT_SHIFT)) & LPCMP_RRCSR_RR_CH6OUT_MASK)

#define LPCMP_RRCSR_RR_CH7OUT_MASK               (0x80U)
#define LPCMP_RRCSR_RR_CH7OUT_SHIFT              (7U)
/*! RR_CH7OUT - Comparison Result for Channel 7 */
#define LPCMP_RRCSR_RR_CH7OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH7OUT_SHIFT)) & LPCMP_RRCSR_RR_CH7OUT_MASK)
/*! @} */

/*! @name RRSR - Round Robin Status */
/*! @{ */

#define LPCMP_RRSR_RR_CH0F_MASK                  (0x1U)
#define LPCMP_RRSR_RR_CH0F_SHIFT                 (0U)
/*! RR_CH0F - Channel 0 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH0F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH0F_SHIFT)) & LPCMP_RRSR_RR_CH0F_MASK)

#define LPCMP_RRSR_RR_CH1F_MASK                  (0x2U)
#define LPCMP_RRSR_RR_CH1F_SHIFT                 (1U)
/*! RR_CH1F - Channel 1 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH1F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH1F_SHIFT)) & LPCMP_RRSR_RR_CH1F_MASK)

#define LPCMP_RRSR_RR_CH2F_MASK                  (0x4U)
#define LPCMP_RRSR_RR_CH2F_SHIFT                 (2U)
/*! RR_CH2F - Channel 2 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH2F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH2F_SHIFT)) & LPCMP_RRSR_RR_CH2F_MASK)

#define LPCMP_RRSR_RR_CH3F_MASK                  (0x8U)
#define LPCMP_RRSR_RR_CH3F_SHIFT                 (3U)
/*! RR_CH3F - Channel 3 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH3F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH3F_SHIFT)) & LPCMP_RRSR_RR_CH3F_MASK)

#define LPCMP_RRSR_RR_CH4F_MASK                  (0x10U)
#define LPCMP_RRSR_RR_CH4F_SHIFT                 (4U)
/*! RR_CH4F - Channel 4 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH4F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH4F_SHIFT)) & LPCMP_RRSR_RR_CH4F_MASK)

#define LPCMP_RRSR_RR_CH5F_MASK                  (0x20U)
#define LPCMP_RRSR_RR_CH5F_SHIFT                 (5U)
/*! RR_CH5F - Channel 5 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH5F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH5F_SHIFT)) & LPCMP_RRSR_RR_CH5F_MASK)

#define LPCMP_RRSR_RR_CH6F_MASK                  (0x40U)
#define LPCMP_RRSR_RR_CH6F_SHIFT                 (6U)
/*! RR_CH6F - Channel 6 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH6F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH6F_SHIFT)) & LPCMP_RRSR_RR_CH6F_MASK)

#define LPCMP_RRSR_RR_CH7F_MASK                  (0x80U)
#define LPCMP_RRSR_RR_CH7F_SHIFT                 (7U)
/*! RR_CH7F - Channel 7 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define LPCMP_RRSR_RR_CH7F(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_RRSR_RR_CH7F_SHIFT)) & LPCMP_RRSR_RR_CH7F_MASK)
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

