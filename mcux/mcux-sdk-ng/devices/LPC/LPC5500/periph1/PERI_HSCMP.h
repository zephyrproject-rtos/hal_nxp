/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for HSCMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_HSCMP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HSCMP
 *
 * CMSIS Peripheral Access Layer for HSCMP
 */

#if !defined(PERI_HSCMP_H_)
#define PERI_HSCMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- HSCMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSCMP_Peripheral_Access_Layer HSCMP Peripheral Access Layer
 * @{
 */

/** HSCMP - Register Layout Typedef */
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
  __IO uint32_t RRCR0;                             /**< Round Robin Control Register 0, offset: 0x24 */
  __IO uint32_t RRCR1;                             /**< Round Robin Control Register 1, offset: 0x28 */
  __IO uint32_t RRCSR;                             /**< Round Robin Control and Status Register, offset: 0x2C */
  __IO uint32_t RRSR;                              /**< Round Robin Status Register, offset: 0x30 */
       uint8_t RESERVED_1[4];
  __IO uint32_t RRCR2;                             /**< Round Robin Control Register 2, offset: 0x38 */
} HSCMP_Type;

/* ----------------------------------------------------------------------------
   -- HSCMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSCMP_Register_Masks HSCMP Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define HSCMP_VERID_FEATURE_MASK                 (0xFFFFU)
#define HSCMP_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000001..Round robin feature
 */
#define HSCMP_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_VERID_FEATURE_SHIFT)) & HSCMP_VERID_FEATURE_MASK)

#define HSCMP_VERID_MINOR_MASK                   (0xFF0000U)
#define HSCMP_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define HSCMP_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_VERID_MINOR_SHIFT)) & HSCMP_VERID_MINOR_MASK)

#define HSCMP_VERID_MAJOR_MASK                   (0xFF000000U)
#define HSCMP_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define HSCMP_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_VERID_MAJOR_SHIFT)) & HSCMP_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define HSCMP_PARAM_DAC_RES_MASK                 (0xFU)
#define HSCMP_PARAM_DAC_RES_SHIFT                (0U)
/*! DAC_RES - DAC Resolution
 *  0b0000..4 bit DAC
 *  0b0001..6 bit DAC
 *  0b0010..8 bit DAC
 *  0b0011..10 bit DAC
 *  0b0100..12 bit DAC
 *  0b0101..14 bit DAC
 *  0b0110..16 bit DAC
 */
#define HSCMP_PARAM_DAC_RES(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_PARAM_DAC_RES_SHIFT)) & HSCMP_PARAM_DAC_RES_MASK)
/*! @} */

/*! @name CCR0 - Comparator Control Register 0 */
/*! @{ */

#define HSCMP_CCR0_CMP_EN_MASK                   (0x1U)
#define HSCMP_CCR0_CMP_EN_SHIFT                  (0U)
/*! CMP_EN - Comparator Enable
 *  0b0..Disable (The analog logic remains off and consumes no power.)
 *  0b1..Enable
 */
#define HSCMP_CCR0_CMP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR0_CMP_EN_SHIFT)) & HSCMP_CCR0_CMP_EN_MASK)

#define HSCMP_CCR0_CMP_STOP_EN_MASK              (0x2U)
#define HSCMP_CCR0_CMP_STOP_EN_SHIFT             (1U)
/*! CMP_STOP_EN - Comparator STOP Mode Enable
 *  0b0..Disable the analog comparator regardless of CMP_EN.
 *  0b1..Allow the analog comparator to be enabled by CMP_EN.
 */
#define HSCMP_CCR0_CMP_STOP_EN(x)                (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR0_CMP_STOP_EN_SHIFT)) & HSCMP_CCR0_CMP_STOP_EN_MASK)

#define HSCMP_CCR0_LINKEN_MASK                   (0x4U)
#define HSCMP_CCR0_LINKEN_SHIFT                  (2U)
/*! LINKEN - CMP-to-DAC Link Enable
 *  0b0..Disable the CMP-to-DAC link: enabling or disabling the DAC is independent from enabling or disabling the CMP.
 *  0b1..Enable the CMP-to-DAC link: the DAC enable/disable is controlled by the CMP_EN bit instead of DCR[DAC_EN].
 */
#define HSCMP_CCR0_LINKEN(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR0_LINKEN_SHIFT)) & HSCMP_CCR0_LINKEN_MASK)
/*! @} */

/*! @name CCR1 - Comparator Control Register 1 */
/*! @{ */

#define HSCMP_CCR1_WINDOW_EN_MASK                (0x1U)
#define HSCMP_CCR1_WINDOW_EN_SHIFT               (0U)
/*! WINDOW_EN - Windowing Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_CCR1_WINDOW_EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_WINDOW_EN_SHIFT)) & HSCMP_CCR1_WINDOW_EN_MASK)

#define HSCMP_CCR1_SAMPLE_EN_MASK                (0x2U)
#define HSCMP_CCR1_SAMPLE_EN_SHIFT               (1U)
/*! SAMPLE_EN - Sampling Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_CCR1_SAMPLE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_SAMPLE_EN_SHIFT)) & HSCMP_CCR1_SAMPLE_EN_MASK)

#define HSCMP_CCR1_DMA_EN_MASK                   (0x4U)
#define HSCMP_CCR1_DMA_EN_SHIFT                  (2U)
/*! DMA_EN - DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_CCR1_DMA_EN(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_DMA_EN_SHIFT)) & HSCMP_CCR1_DMA_EN_MASK)

#define HSCMP_CCR1_COUT_INV_MASK                 (0x8U)
#define HSCMP_CCR1_COUT_INV_SHIFT                (3U)
/*! COUT_INV - Comparator Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define HSCMP_CCR1_COUT_INV(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_COUT_INV_SHIFT)) & HSCMP_CCR1_COUT_INV_MASK)

#define HSCMP_CCR1_COUT_SEL_MASK                 (0x10U)
#define HSCMP_CCR1_COUT_SEL_SHIFT                (4U)
/*! COUT_SEL - Comparator Output Select
 *  0b0..Use COUT (filtered)
 *  0b1..Use COUTA (unfiltered)
 */
#define HSCMP_CCR1_COUT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_COUT_SEL_SHIFT)) & HSCMP_CCR1_COUT_SEL_MASK)

#define HSCMP_CCR1_COUT_PEN_MASK                 (0x20U)
#define HSCMP_CCR1_COUT_PEN_SHIFT                (5U)
/*! COUT_PEN - Comparator Output Pin Enable
 *  0b0..Not available
 *  0b1..Available
 */
#define HSCMP_CCR1_COUT_PEN(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_COUT_PEN_SHIFT)) & HSCMP_CCR1_COUT_PEN_MASK)

#define HSCMP_CCR1_COUTA_OWEN_MASK               (0x40U)
#define HSCMP_CCR1_COUTA_OWEN_SHIFT              (6U)
/*! COUTA_OWEN - COUTA_OW Enable
 *  0b0..COUTA holds the last sampled value
 *  0b1..COUTA is defined by the COUTA_OW bit
 */
#define HSCMP_CCR1_COUTA_OWEN(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_COUTA_OWEN_SHIFT)) & HSCMP_CCR1_COUTA_OWEN_MASK)

#define HSCMP_CCR1_COUTA_OW_MASK                 (0x80U)
#define HSCMP_CCR1_COUTA_OW_SHIFT                (7U)
/*! COUTA_OW - COUTA Output Level for Closed Window
 *  0b0..COUTA is 0
 *  0b1..COUTA is 1
 */
#define HSCMP_CCR1_COUTA_OW(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_COUTA_OW_SHIFT)) & HSCMP_CCR1_COUTA_OW_MASK)

#define HSCMP_CCR1_WINDOW_INV_MASK               (0x100U)
#define HSCMP_CCR1_WINDOW_INV_SHIFT              (8U)
/*! WINDOW_INV - WINDOW/SAMPLE Signal Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define HSCMP_CCR1_WINDOW_INV(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_WINDOW_INV_SHIFT)) & HSCMP_CCR1_WINDOW_INV_MASK)

#define HSCMP_CCR1_WINDOW_CLS_MASK               (0x200U)
#define HSCMP_CCR1_WINDOW_CLS_SHIFT              (9U)
/*! WINDOW_CLS - COUT Event Window Close
 *  0b0..COUT event cannot close the window
 *  0b1..COUT event can close the window
 */
#define HSCMP_CCR1_WINDOW_CLS(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_WINDOW_CLS_SHIFT)) & HSCMP_CCR1_WINDOW_CLS_MASK)

#define HSCMP_CCR1_EVT_SEL_MASK                  (0xC00U)
#define HSCMP_CCR1_EVT_SEL_SHIFT                 (10U)
/*! EVT_SEL - COUT Event Select
 *  0b00..Rising edge
 *  0b01..Falling edge
 *  0b1x..Both edges
 */
#define HSCMP_CCR1_EVT_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_EVT_SEL_SHIFT)) & HSCMP_CCR1_EVT_SEL_MASK)

#define HSCMP_CCR1_FILT_CNT_MASK                 (0x70000U)
#define HSCMP_CCR1_FILT_CNT_SHIFT                (16U)
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
#define HSCMP_CCR1_FILT_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_FILT_CNT_SHIFT)) & HSCMP_CCR1_FILT_CNT_MASK)

#define HSCMP_CCR1_FILT_PER_MASK                 (0xFF000000U)
#define HSCMP_CCR1_FILT_PER_SHIFT                (24U)
/*! FILT_PER - Filter Sample Period */
#define HSCMP_CCR1_FILT_PER(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR1_FILT_PER_SHIFT)) & HSCMP_CCR1_FILT_PER_MASK)
/*! @} */

/*! @name CCR2 - Comparator Control Register 2 */
/*! @{ */

#define HSCMP_CCR2_CMP_HPMD_MASK                 (0x1U)
#define HSCMP_CCR2_CMP_HPMD_SHIFT                (0U)
/*! CMP_HPMD - CMP High Power Mode Select
 *  0b0..Low power(speed) comparison mode
 *  0b1..High power(speed) comparison mode
 */
#define HSCMP_CCR2_CMP_HPMD(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_CMP_HPMD_SHIFT)) & HSCMP_CCR2_CMP_HPMD_MASK)

#define HSCMP_CCR2_CMP_NPMD_MASK                 (0x2U)
#define HSCMP_CCR2_CMP_NPMD_SHIFT                (1U)
/*! CMP_NPMD - CMP Nano Power Mode Select
 *  0b0..Disable (Mode is determined by CMP_HPMD.)
 *  0b1..Enable
 */
#define HSCMP_CCR2_CMP_NPMD(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_CMP_NPMD_SHIFT)) & HSCMP_CCR2_CMP_NPMD_MASK)

#define HSCMP_CCR2_OFFSET_MASK                   (0x4U)
#define HSCMP_CCR2_OFFSET_SHIFT                  (2U)
/*! OFFSET - Comparator Offset Control
 *  0b0..Level 0: The hysteresis selected by HYSTCTR is valid for both directions (rising and falling).
 *  0b1..Level 1: Hysteresis does not apply when INP (input-plus) crosses INM (input-minus) in the rising
 *       direction or when INM crosses INP in the falling direction. Hysteresis still applies for INP crossing INM in the
 *       falling direction.
 */
#define HSCMP_CCR2_OFFSET(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_OFFSET_SHIFT)) & HSCMP_CCR2_OFFSET_MASK)

#define HSCMP_CCR2_HYSTCTR_MASK                  (0x30U)
#define HSCMP_CCR2_HYSTCTR_SHIFT                 (4U)
/*! HYSTCTR - Comparator Hysteresis Control
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define HSCMP_CCR2_HYSTCTR(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_HYSTCTR_SHIFT)) & HSCMP_CCR2_HYSTCTR_MASK)

#define HSCMP_CCR2_PSEL_MASK                     (0x70000U)
#define HSCMP_CCR2_PSEL_SHIFT                    (16U)
/*! PSEL - Plus Input MUX Select
 *  0b000..Input 0p
 *  0b001..Input 1p
 *  0b010..Input 2p
 *  0b011..Input 3p
 *  0b100..Input 4p
 *  0b101..Input 5p
 *  0b110..Reserved
 *  0b111..Internal DAC output
 */
#define HSCMP_CCR2_PSEL(x)                       (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_PSEL_SHIFT)) & HSCMP_CCR2_PSEL_MASK)

#define HSCMP_CCR2_MSEL_MASK                     (0x700000U)
#define HSCMP_CCR2_MSEL_SHIFT                    (20U)
/*! MSEL - Minus Input MUX Select
 *  0b000..Input 0m
 *  0b001..Input 1m
 *  0b010..Input 2m
 *  0b011..Input 3m
 *  0b100..Input 4m
 *  0b101..Input 5m
 *  0b110..Reserved
 *  0b111..Internal DAC output
 */
#define HSCMP_CCR2_MSEL(x)                       (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_MSEL_SHIFT)) & HSCMP_CCR2_MSEL_MASK)

#define HSCMP_CCR2_INPSEL_MASK                   (0x3000000U)
#define HSCMP_CCR2_INPSEL_SHIFT                  (24U)
/*! INPSEL - Input Plus Select
 *  0b00..IN0: from the 8-bit DAC output
 *  0b01..IN1: from the analog 8-1 mux
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define HSCMP_CCR2_INPSEL(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_INPSEL_SHIFT)) & HSCMP_CCR2_INPSEL_MASK)

#define HSCMP_CCR2_INMSEL_MASK                   (0x30000000U)
#define HSCMP_CCR2_INMSEL_SHIFT                  (28U)
/*! INMSEL - Input Minus Select
 *  0b00..IN0: from the 8-bit DAC output
 *  0b01..IN1: from the analog 8-1 mux
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define HSCMP_CCR2_INMSEL(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_CCR2_INMSEL_SHIFT)) & HSCMP_CCR2_INMSEL_MASK)
/*! @} */

/*! @name DCR - DAC Control Register */
/*! @{ */

#define HSCMP_DCR_DAC_EN_MASK                    (0x1U)
#define HSCMP_DCR_DAC_EN_SHIFT                   (0U)
/*! DAC_EN - DAC Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_DCR_DAC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << HSCMP_DCR_DAC_EN_SHIFT)) & HSCMP_DCR_DAC_EN_MASK)

#define HSCMP_DCR_DAC_HPMD_MASK                  (0x2U)
#define HSCMP_DCR_DAC_HPMD_SHIFT                 (1U)
/*! DAC_HPMD - DAC High Power Mode Select
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_DCR_DAC_HPMD(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_DCR_DAC_HPMD_SHIFT)) & HSCMP_DCR_DAC_HPMD_MASK)

#define HSCMP_DCR_VRSEL_MASK                     (0x100U)
#define HSCMP_DCR_VRSEL_SHIFT                    (8U)
/*! VRSEL - DAC Reference High Voltage Source Select
 *  0b0..vrefh0
 *  0b1..vrefh1
 */
#define HSCMP_DCR_VRSEL(x)                       (((uint32_t)(((uint32_t)(x)) << HSCMP_DCR_VRSEL_SHIFT)) & HSCMP_DCR_VRSEL_MASK)

#define HSCMP_DCR_DACOE_MASK                     (0x8000U)
#define HSCMP_DCR_DACOE_SHIFT                    (15U)
/*! DACOE - DAC Output Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_DCR_DACOE(x)                       (((uint32_t)(((uint32_t)(x)) << HSCMP_DCR_DACOE_SHIFT)) & HSCMP_DCR_DACOE_MASK)

#define HSCMP_DCR_DAC_DATA_MASK                  (0xFF0000U)
#define HSCMP_DCR_DAC_DATA_SHIFT                 (16U)
/*! DAC_DATA - DAC Output Voltage Select */
#define HSCMP_DCR_DAC_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_DCR_DAC_DATA_SHIFT)) & HSCMP_DCR_DAC_DATA_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define HSCMP_IER_CFR_IE_MASK                    (0x1U)
#define HSCMP_IER_CFR_IE_SHIFT                   (0U)
/*! CFR_IE - Comparator Flag Rising Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable: Assert an interrupt when CFR is set.
 */
#define HSCMP_IER_CFR_IE(x)                      (((uint32_t)(((uint32_t)(x)) << HSCMP_IER_CFR_IE_SHIFT)) & HSCMP_IER_CFR_IE_MASK)

#define HSCMP_IER_CFF_IE_MASK                    (0x2U)
#define HSCMP_IER_CFF_IE_SHIFT                   (1U)
/*! CFF_IE - Comparator Flag Falling Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable: Assert an interrupt when CFF is set.
 */
#define HSCMP_IER_CFF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << HSCMP_IER_CFF_IE_SHIFT)) & HSCMP_IER_CFF_IE_MASK)

#define HSCMP_IER_RRF_IE_MASK                    (0x4U)
#define HSCMP_IER_RRF_IE_SHIFT                   (2U)
/*! RRF_IE - Round-Robin Flag Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable: Assert an interrupt when the comparison result changes for a given channel.
 */
#define HSCMP_IER_RRF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << HSCMP_IER_RRF_IE_SHIFT)) & HSCMP_IER_RRF_IE_MASK)
/*! @} */

/*! @name CSR - Comparator Status Register */
/*! @{ */

#define HSCMP_CSR_CFR_MASK                       (0x1U)
#define HSCMP_CSR_CFR_SHIFT                      (0U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..Not detected
 *  0b1..Detected
 */
#define HSCMP_CSR_CFR(x)                         (((uint32_t)(((uint32_t)(x)) << HSCMP_CSR_CFR_SHIFT)) & HSCMP_CSR_CFR_MASK)

#define HSCMP_CSR_CFF_MASK                       (0x2U)
#define HSCMP_CSR_CFF_SHIFT                      (1U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..Not detected
 *  0b1..Detected
 */
#define HSCMP_CSR_CFF(x)                         (((uint32_t)(((uint32_t)(x)) << HSCMP_CSR_CFF_SHIFT)) & HSCMP_CSR_CFF_MASK)

#define HSCMP_CSR_RRF_MASK                       (0x4U)
#define HSCMP_CSR_RRF_SHIFT                      (2U)
/*! RRF - Round-Robin Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define HSCMP_CSR_RRF(x)                         (((uint32_t)(((uint32_t)(x)) << HSCMP_CSR_RRF_SHIFT)) & HSCMP_CSR_RRF_MASK)

#define HSCMP_CSR_COUT_MASK                      (0x100U)
#define HSCMP_CSR_COUT_SHIFT                     (8U)
/*! COUT - Analog Comparator Output */
#define HSCMP_CSR_COUT(x)                        (((uint32_t)(((uint32_t)(x)) << HSCMP_CSR_COUT_SHIFT)) & HSCMP_CSR_COUT_MASK)
/*! @} */

/*! @name RRCR0 - Round Robin Control Register 0 */
/*! @{ */

#define HSCMP_RRCR0_RR_EN_MASK                   (0x1U)
#define HSCMP_RRCR0_RR_EN_SHIFT                  (0U)
/*! RR_EN - Round-Robin Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR0_RR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR0_RR_EN_SHIFT)) & HSCMP_RRCR0_RR_EN_MASK)

#define HSCMP_RRCR0_RR_NSAM_MASK                 (0x300U)
#define HSCMP_RRCR0_RR_NSAM_SHIFT                (8U)
/*! RR_NSAM - Number of Sample Clocks
 *  0b00..0 clocks
 *  0b01..1 clocks
 *  0b10..2 clocks
 *  0b11..3 clocks
 */
#define HSCMP_RRCR0_RR_NSAM(x)                   (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR0_RR_NSAM_SHIFT)) & HSCMP_RRCR0_RR_NSAM_MASK)

#define HSCMP_RRCR0_RR_INITMOD_MASK              (0x3F0000U)
#define HSCMP_RRCR0_RR_INITMOD_SHIFT             (16U)
/*! RR_INITMOD - Initialization Delay Modulus
 *  0b000000..63 cycles (same as 111111b)
 *  0b000001-0b111111..1 to 63 cycles
 */
#define HSCMP_RRCR0_RR_INITMOD(x)                (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR0_RR_INITMOD_SHIFT)) & HSCMP_RRCR0_RR_INITMOD_MASK)
/*! @} */

/*! @name RRCR1 - Round Robin Control Register 1 */
/*! @{ */

#define HSCMP_RRCR1_RR_CH0EN_MASK                (0x1U)
#define HSCMP_RRCR1_RR_CH0EN_SHIFT               (0U)
/*! RR_CH0EN - Channel 0 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH0EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH0EN_SHIFT)) & HSCMP_RRCR1_RR_CH0EN_MASK)

#define HSCMP_RRCR1_RR_CH1EN_MASK                (0x2U)
#define HSCMP_RRCR1_RR_CH1EN_SHIFT               (1U)
/*! RR_CH1EN - Channel 1 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH1EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH1EN_SHIFT)) & HSCMP_RRCR1_RR_CH1EN_MASK)

#define HSCMP_RRCR1_RR_CH2EN_MASK                (0x4U)
#define HSCMP_RRCR1_RR_CH2EN_SHIFT               (2U)
/*! RR_CH2EN - Channel 2 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH2EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH2EN_SHIFT)) & HSCMP_RRCR1_RR_CH2EN_MASK)

#define HSCMP_RRCR1_RR_CH3EN_MASK                (0x8U)
#define HSCMP_RRCR1_RR_CH3EN_SHIFT               (3U)
/*! RR_CH3EN - Channel 3 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH3EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH3EN_SHIFT)) & HSCMP_RRCR1_RR_CH3EN_MASK)

#define HSCMP_RRCR1_RR_CH4EN_MASK                (0x10U)
#define HSCMP_RRCR1_RR_CH4EN_SHIFT               (4U)
/*! RR_CH4EN - Channel 4 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH4EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH4EN_SHIFT)) & HSCMP_RRCR1_RR_CH4EN_MASK)

#define HSCMP_RRCR1_RR_CH5EN_MASK                (0x20U)
#define HSCMP_RRCR1_RR_CH5EN_SHIFT               (5U)
/*! RR_CH5EN - Channel 5 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH5EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH5EN_SHIFT)) & HSCMP_RRCR1_RR_CH5EN_MASK)

#define HSCMP_RRCR1_RR_CH6EN_MASK                (0x40U)
#define HSCMP_RRCR1_RR_CH6EN_SHIFT               (6U)
/*! RR_CH6EN - Channel 6 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH6EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH6EN_SHIFT)) & HSCMP_RRCR1_RR_CH6EN_MASK)

#define HSCMP_RRCR1_RR_CH7EN_MASK                (0x80U)
#define HSCMP_RRCR1_RR_CH7EN_SHIFT               (7U)
/*! RR_CH7EN - Channel 7 Input Enable in Trigger Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSCMP_RRCR1_RR_CH7EN(x)                  (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_RR_CH7EN_SHIFT)) & HSCMP_RRCR1_RR_CH7EN_MASK)

#define HSCMP_RRCR1_FIXP_MASK                    (0x10000U)
#define HSCMP_RRCR1_FIXP_SHIFT                   (16U)
/*! FIXP - Fixed Port
 *  0b0..Fix the Plus port. Sweep only the inputs to the Minus port.
 *  0b1..Fix the Minus port. Sweep only the inputs to the Plus port.
 */
#define HSCMP_RRCR1_FIXP(x)                      (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_FIXP_SHIFT)) & HSCMP_RRCR1_FIXP_MASK)

#define HSCMP_RRCR1_FIXCH_MASK                   (0x700000U)
#define HSCMP_RRCR1_FIXCH_SHIFT                  (20U)
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
#define HSCMP_RRCR1_FIXCH(x)                     (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR1_FIXCH_SHIFT)) & HSCMP_RRCR1_FIXCH_MASK)
/*! @} */

/*! @name RRCSR - Round Robin Control and Status Register */
/*! @{ */

#define HSCMP_RRCSR_RR_CH0OUT_MASK               (0x1U)
#define HSCMP_RRCSR_RR_CH0OUT_SHIFT              (0U)
/*! RR_CH0OUT - Comparison Result for Channel 0 */
#define HSCMP_RRCSR_RR_CH0OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH0OUT_SHIFT)) & HSCMP_RRCSR_RR_CH0OUT_MASK)

#define HSCMP_RRCSR_RR_CH1OUT_MASK               (0x2U)
#define HSCMP_RRCSR_RR_CH1OUT_SHIFT              (1U)
/*! RR_CH1OUT - Comparison Result for Channel 1 */
#define HSCMP_RRCSR_RR_CH1OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH1OUT_SHIFT)) & HSCMP_RRCSR_RR_CH1OUT_MASK)

#define HSCMP_RRCSR_RR_CH2OUT_MASK               (0x4U)
#define HSCMP_RRCSR_RR_CH2OUT_SHIFT              (2U)
/*! RR_CH2OUT - Comparison Result for Channel 2 */
#define HSCMP_RRCSR_RR_CH2OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH2OUT_SHIFT)) & HSCMP_RRCSR_RR_CH2OUT_MASK)

#define HSCMP_RRCSR_RR_CH3OUT_MASK               (0x8U)
#define HSCMP_RRCSR_RR_CH3OUT_SHIFT              (3U)
/*! RR_CH3OUT - Comparison Result for Channel 3 */
#define HSCMP_RRCSR_RR_CH3OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH3OUT_SHIFT)) & HSCMP_RRCSR_RR_CH3OUT_MASK)

#define HSCMP_RRCSR_RR_CH4OUT_MASK               (0x10U)
#define HSCMP_RRCSR_RR_CH4OUT_SHIFT              (4U)
/*! RR_CH4OUT - Comparison Result for Channel 4 */
#define HSCMP_RRCSR_RR_CH4OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH4OUT_SHIFT)) & HSCMP_RRCSR_RR_CH4OUT_MASK)

#define HSCMP_RRCSR_RR_CH5OUT_MASK               (0x20U)
#define HSCMP_RRCSR_RR_CH5OUT_SHIFT              (5U)
/*! RR_CH5OUT - Comparison Result for Channel 5 */
#define HSCMP_RRCSR_RR_CH5OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH5OUT_SHIFT)) & HSCMP_RRCSR_RR_CH5OUT_MASK)

#define HSCMP_RRCSR_RR_CH6OUT_MASK               (0x40U)
#define HSCMP_RRCSR_RR_CH6OUT_SHIFT              (6U)
/*! RR_CH6OUT - Comparison Result for Channel 6 */
#define HSCMP_RRCSR_RR_CH6OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH6OUT_SHIFT)) & HSCMP_RRCSR_RR_CH6OUT_MASK)

#define HSCMP_RRCSR_RR_CH7OUT_MASK               (0x80U)
#define HSCMP_RRCSR_RR_CH7OUT_SHIFT              (7U)
/*! RR_CH7OUT - Comparison Result for Channel 7 */
#define HSCMP_RRCSR_RR_CH7OUT(x)                 (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCSR_RR_CH7OUT_SHIFT)) & HSCMP_RRCSR_RR_CH7OUT_MASK)
/*! @} */

/*! @name RRSR - Round Robin Status Register */
/*! @{ */

#define HSCMP_RRSR_RR_CH0F_MASK                  (0x1U)
#define HSCMP_RRSR_RR_CH0F_SHIFT                 (0U)
/*! RR_CH0F - Channel 0 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH0F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH0F_SHIFT)) & HSCMP_RRSR_RR_CH0F_MASK)

#define HSCMP_RRSR_RR_CH1F_MASK                  (0x2U)
#define HSCMP_RRSR_RR_CH1F_SHIFT                 (1U)
/*! RR_CH1F - Channel 1 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH1F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH1F_SHIFT)) & HSCMP_RRSR_RR_CH1F_MASK)

#define HSCMP_RRSR_RR_CH2F_MASK                  (0x4U)
#define HSCMP_RRSR_RR_CH2F_SHIFT                 (2U)
/*! RR_CH2F - Channel 2 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH2F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH2F_SHIFT)) & HSCMP_RRSR_RR_CH2F_MASK)

#define HSCMP_RRSR_RR_CH3F_MASK                  (0x8U)
#define HSCMP_RRSR_RR_CH3F_SHIFT                 (3U)
/*! RR_CH3F - Channel 3 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH3F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH3F_SHIFT)) & HSCMP_RRSR_RR_CH3F_MASK)

#define HSCMP_RRSR_RR_CH4F_MASK                  (0x10U)
#define HSCMP_RRSR_RR_CH4F_SHIFT                 (4U)
/*! RR_CH4F - Channel 4 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH4F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH4F_SHIFT)) & HSCMP_RRSR_RR_CH4F_MASK)

#define HSCMP_RRSR_RR_CH5F_MASK                  (0x20U)
#define HSCMP_RRSR_RR_CH5F_SHIFT                 (5U)
/*! RR_CH5F - Channel 5 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH5F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH5F_SHIFT)) & HSCMP_RRSR_RR_CH5F_MASK)

#define HSCMP_RRSR_RR_CH6F_MASK                  (0x40U)
#define HSCMP_RRSR_RR_CH6F_SHIFT                 (6U)
/*! RR_CH6F - Channel 6 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH6F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH6F_SHIFT)) & HSCMP_RRSR_RR_CH6F_MASK)

#define HSCMP_RRSR_RR_CH7F_MASK                  (0x80U)
#define HSCMP_RRSR_RR_CH7F_SHIFT                 (7U)
/*! RR_CH7F - Channel 7 Input Changed Flag
 *  0b0..Not different
 *  0b1..Different
 */
#define HSCMP_RRSR_RR_CH7F(x)                    (((uint32_t)(((uint32_t)(x)) << HSCMP_RRSR_RR_CH7F_SHIFT)) & HSCMP_RRSR_RR_CH7F_MASK)
/*! @} */

/*! @name RRCR2 - Round Robin Control Register 2 */
/*! @{ */

#define HSCMP_RRCR2_RR_TIMER_RELOAD_MASK         (0xFFFFFFFU)
#define HSCMP_RRCR2_RR_TIMER_RELOAD_SHIFT        (0U)
/*! RR_TIMER_RELOAD - Number of sample clocks */
#define HSCMP_RRCR2_RR_TIMER_RELOAD(x)           (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR2_RR_TIMER_RELOAD_SHIFT)) & HSCMP_RRCR2_RR_TIMER_RELOAD_MASK)

#define HSCMP_RRCR2_RR_TIMER_EN_MASK             (0x80000000U)
#define HSCMP_RRCR2_RR_TIMER_EN_SHIFT            (31U)
/*! RR_TIMER_EN - Round-Robin internal timer enable.
 *  0b0..Round-Robin internal timer is disabled.
 *  0b1..Round-Robin internal timer is enabled.
 */
#define HSCMP_RRCR2_RR_TIMER_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSCMP_RRCR2_RR_TIMER_EN_SHIFT)) & HSCMP_RRCR2_RR_TIMER_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HSCMP_Register_Masks */


/*!
 * @}
 */ /* end of group HSCMP_Peripheral_Access_Layer */


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


#endif  /* PERI_HSCMP_H_ */

