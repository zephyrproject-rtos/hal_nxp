/*
** ###################################################################
**     Processors:          LPC864M201JBD64
**                          LPC864M201JHI33
**                          LPC864M201JHI48
**                          LPC865M201JBD64
**                          LPC865M201JHI33
**                          LPC865M201JHI48
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
**     - rev. 0.0 (2021-07-15)
**         Initial version.
**     - rev. 1.0 (2022-03-15)
**         Revesion of Rev. 1.
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

#if (defined(CPU_LPC864M201JBD64) || defined(CPU_LPC864M201JHI33) || defined(CPU_LPC864M201JHI48))
#include "LPC864_COMMON.h"
#elif (defined(CPU_LPC865M201JBD64) || defined(CPU_LPC865M201JHI33) || defined(CPU_LPC865M201JHI48))
#include "LPC865_COMMON.h"
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
#define INPUTMUX_FTM0_INMUX_COUNT                 3u
#define INPUTMUX_DMA_ITRIG_INMUX_COUNT            16u
#define INPUTMUX_FTM1_INMUX_COUNT                 3u
#define INPUTMUX_FTM0_FLT_INMUX_COUNT             4u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t DMA_INMUX_INMUX[INPUTMUX_DMA_INMUX_INMUX_COUNT]; /**< DMA output trigger selection to become DMA trigger, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t FTM0_INMUX[INPUTMUX_FTM0_INMUX_COUNT]; /**< input select register for FTM0, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[20];
  __IO uint32_t DMA_ITRIG_INMUX[INPUTMUX_DMA_ITRIG_INMUX_COUNT]; /**< Trigger select register for DMA channel, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[32];
  __IO uint32_t FTM1_INMUX[INPUTMUX_FTM1_INMUX_COUNT]; /**< input select register for FTM1 input, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[20];
  __IO uint32_t FTM0_FLT_INMUX[INPUTMUX_FTM0_FLT_INMUX_COUNT]; /**< input select register for FTM0 FAULT, array offset: 0xC0, array step: 0x4 */
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
/*! INP - DMA trigger output number (decimal value) for DMA channel n (n = 0 to 15). */
#define INPUTMUX_DMA_INMUX_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_INMUX_INMUX_INP_SHIFT)) & INPUTMUX_DMA_INMUX_INMUX_INP_MASK)
/*! @} */

/*! @name FTM0_INMUX - input select register for FTM0 */
/*! @{ */

#define INPUTMUX_FTM0_INMUX_INP_MASK             (0xFU)
#define INPUTMUX_FTM0_INMUX_INP_SHIFT            (0U)
/*! INP - Trigger input source selection (decimal value) for FTM0 input n (n = 0 to 2). 0 =
 *    FTM1_INIT_TRIG; 1 = FTM1_EXT_TRIG; 2 = ADC0_THCMP_IRQ; 3 = ACMP0_OUT; 4= GPIOINT_BMATCH; 5 = ARM_TXEV;
 *    6 = MRT_IRQ (global MRT interrupt).
 */
#define INPUTMUX_FTM0_INMUX_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FTM0_INMUX_INP_SHIFT)) & INPUTMUX_FTM0_INMUX_INP_MASK)
/*! @} */

/*! @name DMA_ITRIG_INMUX - Trigger select register for DMA channel */
/*! @{ */

#define INPUTMUX_DMA_ITRIG_INMUX_INP_MASK        (0xFU)
#define INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT       (0U)
/*! INP - Trigger input number (decimal value) for DMA channel n (n = 0 to 12). 0 = GPIO_INT4; 1 =
 *    GPIO_INT5; 2 = GPIO_INT6; 3 = GPIO_INT7; 4= ADC0_SEQA_IRQ; 5 = ADC0_SEQB_IRQ; 6 = COMP0_OUT; 7
 *    = FTM0_INIT_TRIG ORed with FTM0_EXT_TRIG; 8 = FTM1_INIT_TRIG ORed with FTM1_EXT_TRIG; 9= Ored
 *    (FTM0_CH0, FTM0_CH1,.., FTM0_CH5); 10 = Ored (FTM1_CH0, FTM1_CH1,.., FTM1_CH3); 11 = DMA
 *    trigger mux 0 (DMA_INMUX_INMUX0); 12 = DMA trigger mux 1(DMA_INMUX_INMUX1).
 */
#define INPUTMUX_DMA_ITRIG_INMUX_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA_ITRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA_ITRIG_INMUX_INP_MASK)
/*! @} */

/*! @name FTM1_INMUX - input select register for FTM1 input */
/*! @{ */

#define INPUTMUX_FTM1_INMUX_INP_MASK             (0xFU)
#define INPUTMUX_FTM1_INMUX_INP_SHIFT            (0U)
/*! INP - Trigger input source selection (decimal value) for FTM0 input n (n = 0 to 2). 0 =
 *    FTM0_INIT_TRIG; 1 = FTM0_EXT_TRIG; 2 = ADC0_THCMP_IRQ; 3 = ACMP0_OUT; 4= GPIOINT_BMATCH; 5 = ARM_TXEV;
 *    6 = MRT_IRQ (global MRT interrupt).
 */
#define INPUTMUX_FTM1_INMUX_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FTM1_INMUX_INP_SHIFT)) & INPUTMUX_FTM1_INMUX_INP_MASK)
/*! @} */

/*! @name FTM0_FLT_INMUX - input select register for FTM0 FAULT */
/*! @{ */

#define INPUTMUX_FTM0_FLT_INMUX_INP_MASK         (0xFU)
#define INPUTMUX_FTM0_FLT_INMUX_INP_SHIFT        (0U)
/*! INP - Fault inputs source selection (decimal value) for FTM0 fault input n (n = 0 to 3). 0 =
 *    FTM1_INIT_TRIG; 1 = FTM1_EXT_TRIG; 2 = ADC0_THCMP_IRQ; 3 = ACMP0_OUT; 4= GPIOINT_BMATCH; 5 =
 *    ARM_TXEV; 6 = DEBUG_HALTED; 7 = Software fault control bit in SYSCON; 8 = FTM0_FAULT n pin
 *    function (specific fault n pin for corresponding FAULT n input).
 */
#define INPUTMUX_FTM0_FLT_INMUX_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FTM0_FLT_INMUX_INP_SHIFT)) & INPUTMUX_FTM0_FLT_INMUX_INP_MASK)
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

