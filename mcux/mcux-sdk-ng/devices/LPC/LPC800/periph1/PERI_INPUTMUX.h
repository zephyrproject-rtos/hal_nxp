/*
** ###################################################################
**     Processors:          LPC822M101JDH20
**                          LPC822M101JHI33
**                          LPC824M201JDH20
**                          LPC824M201JHI33
**                          LPC832M101FDH20
**                          LPC834M101FHI33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INPUTMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-02-09)
**         Initial version.
**     - rev. 1.1 (2018-02-25)
**         Update some registers according to UM rev 1.2
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_INPUTMUX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for INPUTMUX
 *
 * CMSIS Peripheral Access Layer for INPUTMUX
 */

#if !defined(PERI_INPUTMUX_H_)
#define PERI_INPUTMUX_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC822M101JDH20) || defined(CPU_LPC822M101JHI33))
#include "LPC822_COMMON.h"
#elif (defined(CPU_LPC824M201JDH20) || defined(CPU_LPC824M201JHI33))
#include "LPC824_COMMON.h"
#elif (defined(CPU_LPC832M101FDH20))
#include "LPC832_COMMON.h"
#elif (defined(CPU_LPC834M101FHI33))
#include "LPC834_COMMON.h"
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
   -- INPUTMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Peripheral_Access_Layer INPUTMUX Peripheral Access Layer
 * @{
 */

/** INPUTMUX - Size of Registers Arrays */
#define INPUTMUX_DMA_ITRIG_INMUX_COUNT            18u
#define INPUTMUX_DMA_INMUX_INMUX_COUNT            2u
#define INPUTMUX_SCT0_INMUX_COUNT                 4u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t DMA_ITRIG_INMUX[INPUTMUX_DMA_ITRIG_INMUX_COUNT]; /**< Trigger select register for DMA channel, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[16312];
  __IO uint32_t DMA_INMUX_INMUX[INPUTMUX_DMA_INMUX_INMUX_COUNT]; /**< DMA output trigger selection to become DMA trigger 7 and DMA trigger 8, array offset: 0x4000, array step: 0x4 */
       uint8_t RESERVED_1[24];
  __IO uint32_t SCT0_INMUX[INPUTMUX_SCT0_INMUX_COUNT]; /**< input select register for SCT, array offset: 0x4020, array step: 0x4 */
} INPUTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Register_Masks INPUTMUX Register Masks
 * @{
 */

/*! @name DMA_ITRIG_INMUX - Trigger select register for DMA channel */
/*! @{ */

#define INPUTMUX_DMA_ITRIG_INMUX_INP_MASK        (0xFU)
#define INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT       (0U)
/*! INP - Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from
 *    ADC, SCT, ACMP, pin interrupts, and DMA requests.
 *  0b0000..ADC_SEQA_IRQ
 *  0b0001..ADC_SEQB_IRQ
 *  0b0010..SCT_DMA0
 *  0b0011..SCT_DMA1
 *  0b0100..ACMP_O
 *  0b0101..PININT0
 *  0b0110..PININT1
 *  0b0111..DMA trigger mux 0
 *  0b1000..DMA trigger mux 1
 *  0b1001-0b1111..None
 */
#define INPUTMUX_DMA_ITRIG_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA_ITRIG_INMUX_INP_MASK)
/*! @} */

/*! @name DMA_INMUX_INMUX - DMA output trigger selection to become DMA trigger 7 and DMA trigger 8 */
/*! @{ */

#define INPUTMUX_DMA_INMUX_INMUX_INP_MASK        (0x1FU)
#define INPUTMUX_DMA_INMUX_INMUX_INP_SHIFT       (0U)
/*! INP - DMA trigger output number (decimal value) for DMA channel n (n = 0 to 17). */
#define INPUTMUX_DMA_INMUX_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_INMUX_INMUX_INP_SHIFT)) & INPUTMUX_DMA_INMUX_INMUX_INP_MASK)
/*! @} */

/*! @name SCT0_INMUX - input select register for SCT */
/*! @{ */

#define INPUTMUX_SCT0_INMUX_INP_N_MASK           (0xFU)
#define INPUTMUX_SCT0_INMUX_INP_N_SHIFT          (0U)
/*! INP_N - Input mux register for SCT input n (n = 0 to 3). 0 = sct input 0 1=sct input 1 2= sct
 *    input 2 3= sct input 3 4= adc_thcmp_irq 5 = comparator out 6=arm_txev 7=debug_halted
 *  0b0000..SCT_PIN0
 *  0b0001..SCT_PIN1
 *  0b0010..SCT_PIN2
 *  0b0011..SCT_PIN3
 *  0b0100..ADC_THCMP_IRQ
 *  0b0101..ACMP_O
 *  0b0110..ARM_TXEV
 *  0b0111..DEBUG_HALTED
 *  0b1000-0b1111..None
 */
#define INPUTMUX_SCT0_INMUX_INP_N(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_SCT0_INMUX_INP_N_SHIFT)) & INPUTMUX_SCT0_INMUX_INP_N_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INPUTMUX_Register_Masks */


/*!
 * @}
 */ /* end of group INPUTMUX_Peripheral_Access_Layer */


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


#endif  /* PERI_INPUTMUX_H_ */

