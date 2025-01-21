/*
** ###################################################################
**     Processors:          LPC54101J256BD64
**                          LPC54101J256UK49
**                          LPC54101J512BD64
**                          LPC54101J512UK49
**                          LPC54102J256BD64_cm0plus
**                          LPC54102J256BD64_cm4
**                          LPC54102J256UK49_cm0plus
**                          LPC54102J256UK49_cm4
**                          LPC54102J512BD64_cm0plus
**                          LPC54102J512BD64_cm4
**                          LPC54102J512UK49_cm0plus
**                          LPC54102J512UK49_cm4
**
**     Version:             rev. 1.0, 2016-04-29
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INPUTMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-29)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file INPUTMUX.h
 * @version 1.0
 * @date 2016-04-29
 * @brief CMSIS Peripheral Access Layer for INPUTMUX
 *
 * CMSIS Peripheral Access Layer for INPUTMUX
 */

#if !defined(INPUTMUX_H_)
#define INPUTMUX_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54101J256BD64) || defined(CPU_LPC54101J256UK49) || defined(CPU_LPC54101J512BD64) || defined(CPU_LPC54101J512UK49))
#include "LPC54101_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm0plus) || defined(CPU_LPC54102J256UK49_cm0plus) || defined(CPU_LPC54102J512BD64_cm0plus) || defined(CPU_LPC54102J512UK49_cm0plus))
#include "LPC54102_cm0plus_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm4) || defined(CPU_LPC54102J256UK49_cm4) || defined(CPU_LPC54102J512BD64_cm4) || defined(CPU_LPC54102J512UK49_cm4))
#include "LPC54102_cm4_COMMON.h"
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
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
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
#define INPUTMUX_PINTSEL_COUNT                    8u
#define INPUTMUX_DMA_ITRIG_INMUX_COUNT            22u
#define INPUTMUX_DMA_OTRIG_INMUX_COUNT            4u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[192];
  __IO uint32_t PINTSEL[INPUTMUX_PINTSEL_COUNT];   /**< Pin interrupt select register, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t DMA_ITRIG_INMUX[INPUTMUX_DMA_ITRIG_INMUX_COUNT]; /**< Trigger select register for DMA channel, array offset: 0xE0, array step: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DMA_OTRIG_INMUX[INPUTMUX_DMA_OTRIG_INMUX_COUNT]; /**< DMA output trigger selection to become DMA trigger, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __IO uint32_t FREQMEAS_REF;                      /**< Selection for frequency measurement reference clock, offset: 0x160 */
  __IO uint32_t FREQMEAS_TARGET;                   /**< Selection for frequency measurement target clock, offset: 0x164 */
} INPUTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Register_Masks INPUTMUX Register Masks
 * @{
 */

/*! @name PINTSEL - Pin interrupt select register */
/*! @{ */

#define INPUTMUX_PINTSEL_INTPIN_MASK             (0xFFU)
#define INPUTMUX_PINTSEL_INTPIN_SHIFT            (0U)
/*! INTPIN - Pin number select for pin interrupt or pattern match engine input. (PIO0_0 to PIO1_31 correspond to numbers 0 to 63). */
#define INPUTMUX_PINTSEL_INTPIN(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PINTSEL_INTPIN_SHIFT)) & INPUTMUX_PINTSEL_INTPIN_MASK)
/*! @} */

/*! @name DMA_ITRIG_INMUX - Trigger select register for DMA channel */
/*! @{ */

#define INPUTMUX_DMA_ITRIG_INMUX_INP_MASK        (0x1FU)
#define INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT       (0U)
/*! INP - Trigger input number (decimal value) for DMA channel n (n = 0 to 21). 0 = ADC0 Sequence A
 *    interrupt 1 = ADC0 Sequence B interrupt 2 = SCT0 DMA request 0 3 = SCT0 DMA request 1 4 =
 *    Timer CTIMER0 Match 0 5 = Timer CTIMER0 Match 1 6 = Timer CTIMER1 Match 0 7 = Timer CTIMER2 Match
 *    0 8 = Timer CTIMER2 Match 1 9 = Timer CTIMER3 Match 0 10 = Timer CTIMER4 Match 0 11 = Timer
 *    CTIMER4 Match 1 12 = Pin interrupt 0 13 = Pin interrupt 1 14 = Pin interrupt 2 15 = Pin
 *    interrupt 3 16 = DMA output trigger mux 0 17 = DMA output trigger mux 1 18 = DMA output trigger mux 2
 *    19 = DMA output trigger mux 3
 */
#define INPUTMUX_DMA_ITRIG_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA_ITRIG_INMUX_INP_MASK)
/*! @} */

/*! @name DMA_OTRIG_INMUX - DMA output trigger selection to become DMA trigger */
/*! @{ */

#define INPUTMUX_DMA_OTRIG_INMUX_INP_MASK        (0x1FU)
#define INPUTMUX_DMA_OTRIG_INMUX_INP_SHIFT       (0U)
/*! INP - DMA trigger output number (decimal value) for DMA channel n (n = 0 to 19). */
#define INPUTMUX_DMA_OTRIG_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_OTRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA_OTRIG_INMUX_INP_MASK)
/*! @} */

/*! @name FREQMEAS_REF - Selection for frequency measurement reference clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_REF_CLKIN_MASK         (0x1FU)
#define INPUTMUX_FREQMEAS_REF_CLKIN_SHIFT        (0U)
/*! CLKIN - Clock source number (decimal value) for frequency measure function target clock: 0 =
 *    CLK_IN 1 = FRO 12 MHz oscillator 2 = Watchdog oscillator 3 = 32 kHz RTC oscillator 4 = Main clock
 *    (see Section 4.5.23) 5 = PIO0_4 6 = PIO0_20 7 = PIO0_24 8 = PIO1_4
 */
#define INPUTMUX_FREQMEAS_REF_CLKIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_REF_CLKIN_SHIFT)) & INPUTMUX_FREQMEAS_REF_CLKIN_MASK)
/*! @} */

/*! @name FREQMEAS_TARGET - Selection for frequency measurement target clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_TARGET_CLKIN_MASK      (0x1FU)
#define INPUTMUX_FREQMEAS_TARGET_CLKIN_SHIFT     (0U)
/*! CLKIN - Clock source number (decimal value) for frequency measure function target clock: 0 =
 *    CLK_IN 1 = FRO 12 MHz oscillator 2 = Watchdog oscillator 3 = 32 kHz RTC oscillator 4 = Main clock
 *    (see Section 4.5.23) 5 = PIO0_4 6 = PIO0_20 7 = PIO0_24 8 = PIO1_4
 */
#define INPUTMUX_FREQMEAS_TARGET_CLKIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_TARGET_CLKIN_SHIFT)) & INPUTMUX_FREQMEAS_TARGET_CLKIN_MASK)
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
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* INPUTMUX_H_ */

