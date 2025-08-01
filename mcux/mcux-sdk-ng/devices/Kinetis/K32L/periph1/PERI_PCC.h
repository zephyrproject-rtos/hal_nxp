/*
** ###################################################################
**     Processors:          K32L2A31VLH1A
**                          K32L2A31VLL1A
**                          K32L2A41VLH1A
**                          K32L2A41VLL1A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PCC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-30)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PCC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC
 *
 * CMSIS Peripheral Access Layer for PCC
 */

#if !defined(PERI_PCC_H_)
#define PERI_PCC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L2A31VLH1A) || defined(CPU_K32L2A31VLL1A))
#include "K32L2A31A_COMMON.h"
#elif (defined(CPU_K32L2A41VLH1A) || defined(CPU_K32L2A41VLL1A))
#include "K32L2A41A_COMMON.h"
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
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */

/** PCC - Size of Registers Arrays */
#define PCC_CLKCFG_COUNT                          121u

/** PCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CLKCFG[PCC_CLKCFG_COUNT];          /**< PCC CLKCFG Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} PCC_Type;

/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Register_Masks PCC Register Masks
 * @{
 */

/*! @name CLKCFG - PCC CLKCFG Register */
/*! @{ */

#define PCC_CLKCFG_PCD_MASK                      (0x7U)
#define PCC_CLKCFG_PCD_SHIFT                     (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1 (pass-through, no clock divide).
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC_CLKCFG_PCD(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PCD_SHIFT)) & PCC_CLKCFG_PCD_MASK)

#define PCC_CLKCFG_FRAC_MASK                     (0x8U)
#define PCC_CLKCFG_FRAC_SHIFT                    (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC_CLKCFG_FRAC(x)                       (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_FRAC_SHIFT)) & PCC_CLKCFG_FRAC_MASK)

#define PCC_CLKCFG_PCS_MASK                      (0x7000000U)
#define PCC_CLKCFG_PCS_SHIFT                     (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled) An external clock can be enabled for this peripheral.
 *  0b001..OSCCLK - System Oscillator Platform Clock(scg_sosc_plat_clk).
 *  0b010..SCGIRCLK - Slow IRC Clock(scg_sirc_plat_clk), (maximum is 8MHz).
 *  0b011..SCGFIRCLK - Fast IRC Clock(scg_firc_plat_clk), (maximum is 48MHz).
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..SCGPCLK System PLL clock (scg_spll_plat_clk).
 *  0b111..Reserved.
 */
#define PCC_CLKCFG_PCS(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PCS_SHIFT)) & PCC_CLKCFG_PCS_MASK)

#define PCC_CLKCFG_INUSE_MASK                    (0x20000000U)
#define PCC_CLKCFG_INUSE_SHIFT                   (29U)
/*! INUSE - Clock Gate Control
 *  0b0..Another core is not using this peripheral.
 *  0b1..Another core is using this peripheral. Software cannot modify the existing clocking configuration.
 */
#define PCC_CLKCFG_INUSE(x)                      (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_INUSE_SHIFT)) & PCC_CLKCFG_INUSE_MASK)

#define PCC_CLKCFG_CGC_MASK                      (0x40000000U)
#define PCC_CLKCFG_CGC_SHIFT                     (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define PCC_CLKCFG_CGC(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_CGC_SHIFT)) & PCC_CLKCFG_CGC_MASK)

#define PCC_CLKCFG_PR_MASK                       (0x80000000U)
#define PCC_CLKCFG_PR_SHIFT                      (31U)
/*! PR - Enable
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC_CLKCFG_PR(x)                         (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PR_SHIFT)) & PCC_CLKCFG_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC_Register_Masks */

#define PCC_INSTANCE_MASK      0xF
#define PCC_INSTANCE_SHIFT     12
#define PCC_PERIPHERAL_MASK    0xFFF
#define PCC_PERIPHERAL_SHIFT   0
#define PCC_INSTANCE_0    0
#define PCC_INSTANCE_1    1

#define PCC_DMA0_INDEX      ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 8)
#define PCC_FLASH_INDEX     ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 32)
#define PCC_DMAMUX0_INDEX   ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 33)
#define PCC_INTMUX0_INDEX   ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 36)
#define PCC_TPM2_INDEX      ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 46)
#define PCC_LPIT0_INDEX     ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 48)
#define PCC_LPTMR0_INDEX    ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 52)
#define PCC_RTC_INDEX       ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 56)
#define PCC_LPSPI2_INDEX    ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 62)
#define PCC_LPI2C2_INDEX    ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 66)
#define PCC_LPUART2_INDEX   ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 70)
#define PCC_EMVSIM0_INDEX   ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 78)
#define PCC_USB0FS_INDEX    ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 85)
#define PCC_PORTA_INDEX     ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 90)
#define PCC_PORTB_INDEX     ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 91)
#define PCC_PORTC_INDEX     ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 92)
#define PCC_PORTD_INDEX     ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 93)
#define PCC_PORTE_INDEX     ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 94)
#define PCC_TSI0_INDEX      ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 98)
#define PCC_ADC0_INDEX      ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 102)
#define PCC_DAC0_INDEX      ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 106)
#define PCC_CMP0_INDEX      ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 110)
#define PCC_VREF_INDEX      ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 114)
#define PCC_CRC_INDEX       ((uint16_t)((PCC_INSTANCE_0 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 120)
#define PCC_DMA0            (PCC0->CLKCFG[8])
#define PCC_FLASH           (PCC0->CLKCFG[32])
#define PCC_DMAMUX0         (PCC0->CLKCFG[33])
#define PCC_INTMUX0         (PCC0->CLKCFG[36])
#define PCC_TPM2            (PCC0->CLKCFG[46])
#define PCC_LPIT0           (PCC0->CLKCFG[48])
#define PCC_LPTMR0          (PCC0->CLKCFG[52])
#define PCC_RTC             (PCC0->CLKCFG[56])
#define PCC_LPSPI2          (PCC0->CLKCFG[62])
#define PCC_LPI2C2          (PCC0->CLKCFG[66])
#define PCC_LPUART2         (PCC0->CLKCFG[70])
#define PCC_EMVSIM0         (PCC0->CLKCFG[78])
#define PCC_USB0FS          (PCC0->CLKCFG[85])
#define PCC_PORTA           (PCC0->CLKCFG[90])
#define PCC_PORTB           (PCC0->CLKCFG[91])
#define PCC_PORTC           (PCC0->CLKCFG[92])
#define PCC_PORTD           (PCC0->CLKCFG[93])
#define PCC_PORTE           (PCC0->CLKCFG[94])
#define PCC_TSI0            (PCC0->CLKCFG[98])
#define PCC_ADC0            (PCC0->CLKCFG[102])
#define PCC_DAC0            (PCC0->CLKCFG[106])
#define PCC_CMP0            (PCC0->CLKCFG[110])
#define PCC_VREF            (PCC0->CLKCFG[114])
#define PCC_CRC             (PCC0->CLKCFG[120])

#define PCC_TRNG_INDEX      ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 37)
#define PCC_TPM0_INDEX      ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 44)
#define PCC_TPM1_INDEX      ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 45)
#define PCC_LPTMR1_INDEX    ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 53)
#define PCC_LPSPI0_INDEX    ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 60)
#define PCC_LPSPI1_INDEX    ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 61)
#define PCC_LPI2C0_INDEX    ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 64)
#define PCC_LPI2C1_INDEX    ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 65)
#define PCC_LPUART0_INDEX   ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 68)
#define PCC_LPUART1_INDEX   ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 69)
#define PCC_FLEXIO0_INDEX   ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 74)
#define PCC_PORTM_INDEX     ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 96)
#define PCC_CMP1_INDEX      ((uint16_t)((PCC_INSTANCE_1 & PCC_INSTANCE_MASK) << PCC_INSTANCE_SHIFT) | 111)
#define PCC_TRNG            (PCC1->CLKCFG[37])
#define PCC_TPM0            (PCC1->CLKCFG[44])
#define PCC_TPM1            (PCC1->CLKCFG[45])
#define PCC_LPTMR1          (PCC1->CLKCFG[53])
#define PCC_LPSPI0          (PCC1->CLKCFG[60])
#define PCC_LPSPI1          (PCC1->CLKCFG[61])
#define PCC_LPI2C0          (PCC1->CLKCFG[64])
#define PCC_LPI2C1          (PCC1->CLKCFG[65])
#define PCC_LPUART0         (PCC1->CLKCFG[68])
#define PCC_LPUART1         (PCC1->CLKCFG[69])
#define PCC_FLEXIO0         (PCC1->CLKCFG[74])
#define PCC_CMP1            (PCC1->CLKCFG[111])


/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC_H_ */

