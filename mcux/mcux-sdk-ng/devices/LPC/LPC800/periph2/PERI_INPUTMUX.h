/*
** ###################################################################
**     Processors:          LPC844M201JBD48
**                          LPC844M201JBD64
**                          LPC844M201JHI33
**                          LPC844M201JHI48
**                          LPC845M301JBD48
**                          LPC845M301JBD64
**                          LPC845M301JHI33
**                          LPC845M301JHI48
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
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
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

#if (defined(CPU_LPC844M201JBD48) || defined(CPU_LPC844M201JBD64) || defined(CPU_LPC844M201JHI33) || defined(CPU_LPC844M201JHI48))
#include "LPC844_COMMON.h"
#elif (defined(CPU_LPC845M301JBD48) || defined(CPU_LPC845M301JBD64) || defined(CPU_LPC845M301JHI33) || defined(CPU_LPC845M301JHI48))
#include "LPC845_COMMON.h"
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
#define INPUTMUX_DMA_INMUX_INMUX_COUNT            2u
#define INPUTMUX_SCT_INMUX_COUNT                  4u
#define INPUTMUX_DMA_ITRIG_INMUX_COUNT            25u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t DMA_INMUX_INMUX[INPUTMUX_DMA_INMUX_INMUX_COUNT]; /**< DMA output trigger selection to become DMA trigger, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t SCT_INMUX[INPUTMUX_SCT_INMUX_COUNT]; /**< input select register for SCT, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t DMA_ITRIG_INMUX[INPUTMUX_DMA_ITRIG_INMUX_COUNT]; /**< Trigger select register for DMA channel, array offset: 0x40, array step: 0x4 */
} INPUTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Register_Masks INPUTMUX Register Masks
 * @{
 */

/*! @name DMA_INMUX_INMUX - DMA output trigger selection to become DMA trigger */
/*! @{ */

#define INPUTMUX_DMA_INMUX_INMUX_INP_MASK        (0x1FU)
#define INPUTMUX_DMA_INMUX_INMUX_INP_SHIFT       (0U)
/*! INP - DMA trigger output number (decimal value) for DMA channel n (n = 0 to 24). */
#define INPUTMUX_DMA_INMUX_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_INMUX_INMUX_INP_SHIFT)) & INPUTMUX_DMA_INMUX_INMUX_INP_MASK)
/*! @} */

/*! @name SCT_INMUX - input select register for SCT */
/*! @{ */

#define INPUTMUX_SCT_INMUX_INP_N_MASK            (0xFU)
#define INPUTMUX_SCT_INMUX_INP_N_SHIFT           (0U)
/*! INP_N - Input mux register for SCT input n (n = 0 to 3). 0 = sct input 0 1=sct input 1 2= sct
 *    input 2 3= sct gpio input 3 4= adc_thcmp_irq 5 = comparator out 6 = timer ct32b0 match2
 *    7=gpio_int_bmatch 8=arm_txev 9=debug_halted
 */
#define INPUTMUX_SCT_INMUX_INP_N(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_SCT_INMUX_INP_N_SHIFT)) & INPUTMUX_SCT_INMUX_INP_N_MASK)
/*! @} */

/*! @name DMA_ITRIG_INMUX - Trigger select register for DMA channel */
/*! @{ */

#define INPUTMUX_DMA_ITRIG_INMUX_INP_MASK        (0xFU)
#define INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT       (0U)
/*! INP - Trigger input number (decimal value) for DMA channel n (n = 0 to 12). 0 = ADC0 Sequence A
 *    interrupt 1 = ADC0 Sequence B interrupt 2 = SCT0 DMA request 0 3 = SCT0 DMA request 1 4=
 *    Comparator out 5 = Pin interrupt 4 6 = Pin interrupt 5 7 = Pin interrupt 6 8 = Pin interrupt 7 9=
 *    Timer CTIMER0 Match 0 dma request 10 = Timer CTIMER0 Match 1 dma request 11 = DMA output
 *    trigger mux 0 12 = DMA output trigger mux 1
 */
#define INPUTMUX_DMA_ITRIG_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA_ITRIG_INMUX_INP_MASK)
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

