/*
** ###################################################################
**     Processors:          MKE14Z32VFP4
**                          MKE14Z32VLD4
**                          MKE14Z32VLF4
**                          MKE14Z64VFP4
**                          MKE14Z64VLD4
**                          MKE14Z64VLF4
**                          MKE15Z32VFP4
**                          MKE15Z32VLD4
**                          MKE15Z32VLF4
**                          MKE15Z64VFP4
**                          MKE15Z64VLD4
**                          MKE15Z64VLF4
**                          MKE16Z32VLD4
**                          MKE16Z32VLF4
**                          MKE16Z64VLD4
**                          MKE16Z64VLF4
**
**     Version:             rev. 4.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PWT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-05-09)
**         Initial version.
**     - rev. 2.0 (2018-09-17)
**         Based on rev1 RM.
**     - rev. 3.0 (2020-01-22)
**         Add 40 pins part numbers.
**     - rev. 4.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PWT.h
 * @version 4.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PWT
 *
 * CMSIS Peripheral Access Layer for PWT
 */

#if !defined(PERI_PWT_H_)
#define PERI_PWT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z32VFP4) || defined(CPU_MKE14Z32VLD4) || defined(CPU_MKE14Z32VLF4) || defined(CPU_MKE14Z64VFP4) || defined(CPU_MKE14Z64VLD4) || defined(CPU_MKE14Z64VLF4))
#include "MKE14Z4_COMMON.h"
#elif (defined(CPU_MKE15Z32VFP4) || defined(CPU_MKE15Z32VLD4) || defined(CPU_MKE15Z32VLF4) || defined(CPU_MKE15Z64VFP4) || defined(CPU_MKE15Z64VLD4) || defined(CPU_MKE15Z64VLF4))
#include "MKE15Z4_COMMON.h"
#elif (defined(CPU_MKE16Z32VLD4) || defined(CPU_MKE16Z32VLF4) || defined(CPU_MKE16Z64VLD4) || defined(CPU_MKE16Z64VLF4))
#include "MKE16Z4_COMMON.h"
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
   -- PWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWT_Peripheral_Access_Layer PWT Peripheral Access Layer
 * @{
 */

/** PWT - Register Layout Typedef */
typedef struct {
  __IO uint8_t CS;                                 /**< Pulse Width Timer Control and Status Register, offset: 0x0 */
  __IO uint8_t CR;                                 /**< Pulse Width Timer Control Register, offset: 0x1 */
  __I  uint8_t PPH;                                /**< Pulse Width Timer Positive Pulse Width Register: High, offset: 0x2 */
  __I  uint8_t PPL;                                /**< Pulse Width Timer Positive Pulse Width Register: Loq, offset: 0x3 */
  __I  uint8_t NPH;                                /**< Pulse Width Timer Negative Pulse Width Register: High, offset: 0x4 */
  __I  uint8_t NPL;                                /**< Pulse Width Timer Negative Pulse Width Register: Low, offset: 0x5 */
  __I  uint8_t CNTH;                               /**< Pulse Width Timer Counter Register: High, offset: 0x6 */
  __I  uint8_t CNTL;                               /**< Pulse Width Timer Counter Register: Low, offset: 0x7 */
} PWT_Type;

/* ----------------------------------------------------------------------------
   -- PWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWT_Register_Masks PWT Register Masks
 * @{
 */

/*! @name CS - Pulse Width Timer Control and Status Register */
/*! @{ */

#define PWT_CS_PWTOV_MASK                        (0x1U)
#define PWT_CS_PWTOV_SHIFT                       (0U)
/*! PWTOV - PWT Counter Overflow
 *  0b0..PWT counter no overflow.
 *  0b1..PWT counter runs from 0xFFFF to 0x0000.
 */
#define PWT_CS_PWTOV(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_CS_PWTOV_SHIFT)) & PWT_CS_PWTOV_MASK)

#define PWT_CS_PWTRDY_MASK                       (0x2U)
#define PWT_CS_PWTRDY_SHIFT                      (1U)
/*! PWTRDY - PWT Pulse Width Valid
 *  0b0..PWT pulse width register(s) is not up-to-date.
 *  0b1..PWT pulse width register(s) has been updated.
 */
#define PWT_CS_PWTRDY(x)                         (((uint8_t)(((uint8_t)(x)) << PWT_CS_PWTRDY_SHIFT)) & PWT_CS_PWTRDY_MASK)

#define PWT_CS_FCTLE_MASK                        (0x4U)
#define PWT_CS_FCTLE_SHIFT                       (2U)
/*! FCTLE - First counter load enable after enable
 *  0b0..Do not load the first counter values to corresponding registers
 *  0b1..Load the first coutner value to corresponding registers depended by the PWTIN level
 */
#define PWT_CS_FCTLE(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_CS_FCTLE_SHIFT)) & PWT_CS_FCTLE_MASK)

#define PWT_CS_PWTSR_MASK                        (0x8U)
#define PWT_CS_PWTSR_SHIFT                       (3U)
/*! PWTSR - PWT Soft Reset
 *  0b0..No action taken.
 *  0b1..Writing 1 to this field will perform soft reset to PWT.
 */
#define PWT_CS_PWTSR(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_CS_PWTSR_SHIFT)) & PWT_CS_PWTSR_MASK)

#define PWT_CS_POVIE_MASK                        (0x10U)
#define PWT_CS_POVIE_SHIFT                       (4U)
/*! POVIE - PWT Counter Overflow Interrupt Enable
 *  0b0..Disable PWT to generate interrupt when PWTOV is set.
 *  0b1..Enable PWT to generate interrupt when PWTOV is set.
 */
#define PWT_CS_POVIE(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_CS_POVIE_SHIFT)) & PWT_CS_POVIE_MASK)

#define PWT_CS_PRDYIE_MASK                       (0x20U)
#define PWT_CS_PRDYIE_SHIFT                      (5U)
/*! PRDYIE - PWT Pulse Width Data Ready Interrupt Enable
 *  0b0..Disable PWT to generate interrupt when PWTRDY is set.
 *  0b1..Enable PWT to generate interrupt when PWTRDY is set.
 */
#define PWT_CS_PRDYIE(x)                         (((uint8_t)(((uint8_t)(x)) << PWT_CS_PRDYIE_SHIFT)) & PWT_CS_PRDYIE_MASK)

#define PWT_CS_PWTIE_MASK                        (0x40U)
#define PWT_CS_PWTIE_SHIFT                       (6U)
/*! PWTIE - PWT Module Interrupt Enable
 *  0b0..Disables the PWT to generate interrupt.
 *  0b1..Enables the PWT to generate interrupt.
 */
#define PWT_CS_PWTIE(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_CS_PWTIE_SHIFT)) & PWT_CS_PWTIE_MASK)

#define PWT_CS_PWTEN_MASK                        (0x80U)
#define PWT_CS_PWTEN_SHIFT                       (7U)
/*! PWTEN - PWT Module Enable
 *  0b0..The PWT is disabled.
 *  0b1..The PWT is enabled.
 */
#define PWT_CS_PWTEN(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_CS_PWTEN_SHIFT)) & PWT_CS_PWTEN_MASK)
/*! @} */

/*! @name CR - Pulse Width Timer Control Register */
/*! @{ */

#define PWT_CR_PRE_MASK                          (0x7U)
#define PWT_CR_PRE_SHIFT                         (0U)
/*! PRE - PWT Clock Prescaler (CLKPRE) Setting
 *  0b000..Clock divided by 1.
 *  0b001..Clock divided by 2.
 *  0b010..Clock divided by 4.
 *  0b011..Clock divided by 8.
 *  0b100..Clock divided by 16.
 *  0b101..Clock divided by 32.
 *  0b110..Clock divided by 64.
 *  0b111..Clock divided by 128.
 */
#define PWT_CR_PRE(x)                            (((uint8_t)(((uint8_t)(x)) << PWT_CR_PRE_SHIFT)) & PWT_CR_PRE_MASK)

#define PWT_CR_LVL_MASK                          (0x8U)
#define PWT_CR_LVL_SHIFT                         (3U)
/*! LVL - PWTIN Level when Overflows */
#define PWT_CR_LVL(x)                            (((uint8_t)(((uint8_t)(x)) << PWT_CR_LVL_SHIFT)) & PWT_CR_LVL_MASK)

#define PWT_CR_TGL_MASK                          (0x10U)
#define PWT_CR_TGL_SHIFT                         (4U)
/*! TGL - PWTIN states Toggled from last state
 *  0b0..The selected PWTIN hasn't changed its original states from last time.
 *  0b1..The selected PWTIN has toggled its states.
 */
#define PWT_CR_TGL(x)                            (((uint8_t)(((uint8_t)(x)) << PWT_CR_TGL_SHIFT)) & PWT_CR_TGL_MASK)

#define PWT_CR_PINSEL_MASK                       (0x60U)
#define PWT_CR_PINSEL_SHIFT                      (5U)
/*! PINSEL - PWT Pulse Inputs Selection
 *  0b00..PWTIN[0] is enabled.
 *  0b01..PWTIN[1] is enabled.
 *  0b10..PWTIN[2] enabled.
 *  0b11..PWTIN[3] enabled.
 */
#define PWT_CR_PINSEL(x)                         (((uint8_t)(((uint8_t)(x)) << PWT_CR_PINSEL_SHIFT)) & PWT_CR_PINSEL_MASK)

#define PWT_CR_PCLKS_MASK                        (0x80U)
#define PWT_CR_PCLKS_SHIFT                       (7U)
/*! PCLKS - PWT Clock Source Selection
 *  0b0..BUS_CLK is selected as the clock source of PWT counter.
 *  0b1..Alternative clock is selected as the clock source of PWT counter.
 */
#define PWT_CR_PCLKS(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_CR_PCLKS_SHIFT)) & PWT_CR_PCLKS_MASK)
/*! @} */

/*! @name PPH - Pulse Width Timer Positive Pulse Width Register: High */
/*! @{ */

#define PWT_PPH_PPWH_MASK                        (0xFFU)
#define PWT_PPH_PPWH_SHIFT                       (0U)
/*! PPWH - Positive Pulse Width[15:8] */
#define PWT_PPH_PPWH(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_PPH_PPWH_SHIFT)) & PWT_PPH_PPWH_MASK)
/*! @} */

/*! @name PPL - Pulse Width Timer Positive Pulse Width Register: Loq */
/*! @{ */

#define PWT_PPL_PPWL_MASK                        (0xFFU)
#define PWT_PPL_PPWL_SHIFT                       (0U)
/*! PPWL - Positive Pulse Width[7:0] */
#define PWT_PPL_PPWL(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_PPL_PPWL_SHIFT)) & PWT_PPL_PPWL_MASK)
/*! @} */

/*! @name NPH - Pulse Width Timer Negative Pulse Width Register: High */
/*! @{ */

#define PWT_NPH_NPWH_MASK                        (0xFFU)
#define PWT_NPH_NPWH_SHIFT                       (0U)
/*! NPWH - Negative Pulse Width[15:8] */
#define PWT_NPH_NPWH(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_NPH_NPWH_SHIFT)) & PWT_NPH_NPWH_MASK)
/*! @} */

/*! @name NPL - Pulse Width Timer Negative Pulse Width Register: Low */
/*! @{ */

#define PWT_NPL_NPWL_MASK                        (0xFFU)
#define PWT_NPL_NPWL_SHIFT                       (0U)
/*! NPWL - Negative Pulse Width[7:0] */
#define PWT_NPL_NPWL(x)                          (((uint8_t)(((uint8_t)(x)) << PWT_NPL_NPWL_SHIFT)) & PWT_NPL_NPWL_MASK)
/*! @} */

/*! @name CNTH - Pulse Width Timer Counter Register: High */
/*! @{ */

#define PWT_CNTH_PWTH_MASK                       (0xFFU)
#define PWT_CNTH_PWTH_SHIFT                      (0U)
/*! PWTH - PWT counter[15:8] */
#define PWT_CNTH_PWTH(x)                         (((uint8_t)(((uint8_t)(x)) << PWT_CNTH_PWTH_SHIFT)) & PWT_CNTH_PWTH_MASK)
/*! @} */

/*! @name CNTL - Pulse Width Timer Counter Register: Low */
/*! @{ */

#define PWT_CNTL_PWTL_MASK                       (0xFFU)
#define PWT_CNTL_PWTL_SHIFT                      (0U)
/*! PWTL - PWT counter[7:0] */
#define PWT_CNTL_PWTL(x)                         (((uint8_t)(((uint8_t)(x)) << PWT_CNTL_PWTL_SHIFT)) & PWT_CNTL_PWTL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PWT_Register_Masks */


/*!
 * @}
 */ /* end of group PWT_Peripheral_Access_Layer */


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


#endif  /* PERI_PWT_H_ */

