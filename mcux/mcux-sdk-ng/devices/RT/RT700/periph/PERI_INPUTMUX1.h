/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INPUTMUX1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_INPUTMUX1.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for INPUTMUX1
 *
 * CMSIS Peripheral Access Layer for INPUTMUX1
 */

#if !defined(PERI_INPUTMUX1_H_)
#define PERI_INPUTMUX1_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- INPUTMUX1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX1_Peripheral_Access_Layer INPUTMUX1 Peripheral Access Layer
 * @{
 */

/** INPUTMUX1 - Size of Registers Arrays */
#define INPUTMUX1_PINT1_TRIG_COUNT                4u
#define INPUTMUX1_HIFI1_INTERRUPT_COUNT           27u
#define INPUTMUX1_FLEXCOMM_TRIG_COUNT             4u
#define INPUTMUX1_ADC_TRIG_COUNT                  2u
#define INPUTMUX1_CTIMER_CTIMER_CAP_COUNT         4u
#define INPUTMUX1_CTIMER_COUNT                    3u

/** INPUTMUX1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  __IO uint32_t PINT1_TRIG[INPUTMUX1_PINT1_TRIG_COUNT]; /**< PINT1 Input Connections, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[48];
  __IO uint32_t HIFI1_INTERRUPT[INPUTMUX1_HIFI1_INTERRUPT_COUNT]; /**< HiFi1 Interrupt Connections, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_2[84];
  struct {                                         /* offset: 0x200, array step: 0x20 */
    __IO uint32_t LP_FLEXCOMM_TRIG;                  /**< LP_FLEXCOMM Input Connections, array offset: 0x200, array step: 0x20 */
         uint8_t RESERVED_0[28];
  } FLEXCOMM_TRIG[INPUTMUX1_FLEXCOMM_TRIG_COUNT];
       uint8_t RESERVED_3[384];
  __IO uint32_t ADC0_TRIG[INPUTMUX1_ADC_TRIG_COUNT]; /**< ADC0 Input Connections, array offset: 0x400, array step: 0x4 */
       uint8_t RESERVED_4[504];
  struct {                                         /* offset: 0x600, array step: 0x20 */
    __IO uint32_t CAP[INPUTMUX1_CTIMER_CTIMER_CAP_COUNT];   /**< CTIMER Input Connections, array offset: 0x600, array step: index*0x20, index2*0x4 */
    __IO uint32_t TRIG;                              /**< CTIMER Input Connections, array offset: 0x610, array step: 0x20 */
         uint8_t RESERVED_0[12];
  } CTIMER[INPUTMUX1_CTIMER_COUNT];
} INPUTMUX1_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX1_Register_Masks INPUTMUX1 Register Masks
 * @{
 */

/*! @name PINT1_TRIG - PINT1 Input Connections */
/*! @{ */

#define INPUTMUX1_PINT1_TRIG_TRIGIN_MASK         (0x3FU)
#define INPUTMUX1_PINT1_TRIG_TRIGIN_SHIFT        (0U)
/*! TRIGIN - PINT1 Input Trigger
 *  0b000000..Selects PIO8_0
 *  0b000001..Selects PIO8_1
 *  0b000010..Selects PIO8_2
 *  0b000011..Selects PIO8_3
 *  0b000100..Selects PIO8_4
 *  0b000101..Selects PIO8_5
 *  0b000110..Selects PIO8_6
 *  0b000111..Selects PIO8_7
 *  0b001000..Selects PIO8_8
 *  0b001001..Selects PIO8_9
 *  0b001010..Selects PIO8_10
 *  0b001011..Selects PIO8_11
 *  0b001100..Selects PIO8_12
 *  0b001101..Selects PIO8_13
 *  0b001110..Selects PIO8_14
 *  0b001111..Selects PIO8_15
 *  0b010000..Selects PIO8_16
 *  0b010001..Selects PIO8_17
 *  0b010010..Selects PIO8_18
 *  0b010011..Selects PIO8_19
 *  0b010100..Selects PIO8_20
 *  0b010101..Selects PIO8_21
 *  0b010110..Selects PIO8_22
 *  0b010111..Selects PIO8_23
 *  0b011000..Selects PIO8_24
 *  0b011001..Selects PIO8_25
 *  0b011010..Selects PIO8_26
 *  0b011011..Selects PIO8_27
 *  0b011100..Selects PIO8_28
 *  0b011101..Selects PIO8_29
 *  0b011110..Selects PIO8_30
 *  0b011111..Selects PIO8_31
 *  0b100000..Selects PIO10_0
 *  0b100001..Selects PIO10_1
 *  0b100010..Selects PIO10_2
 *  0b100011..Selects PIO10_3
 *  0b100100..Selects PIO10_4
 *  0b100101..Selects PIO10_5
 *  0b100110..Selects PIO10_6
 *  0b100111..Selects PIO10_7
 *  0b101000..Selects PIO10_8
 *  0b101001..Selects PIO10_9
 *  0b101010..Selects PIO10_10
 *  0b101011..Selects PIO10_11
 *  0b101100..Selects PIO10_12
 *  0b101101..Selects PIO10_13
 *  0b101110..Selects PIO10_14
 *  0b101111..Selects PIO10_15
 *  0b110000..Selects PIO10_16
 *  0b110001..Selects PIO10_17
 */
#define INPUTMUX1_PINT1_TRIG_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX1_PINT1_TRIG_TRIGIN_SHIFT)) & INPUTMUX1_PINT1_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name HIFI1_INTERRUPT - HiFi1 Interrupt Connections */
/*! @{ */

#define INPUTMUX1_HIFI1_INTERRUPT_TRIGIN_MASK    (0x3FU)
#define INPUTMUX1_HIFI1_INTERRUPT_TRIGIN_SHIFT   (0U)
/*! TRIGIN - HiFi1 input interrupt
 *  0b000000..Selects LP_FLEXCOMM17 interrupt
 *  0b000001..Selects LP_FLEXCOMM18 interrupt
 *  0b000010..Selects LP_FLEXCOMM19 interrupt
 *  0b000011..Selects LP_FLEXCOMM20 interrupt
 *  0b000100..Selects PMC1 Interrupt
 *  0b000111..Selects GPIO8 channel 0 interrupt
 *  0b001000..Selects GPIO8 channel 1 interrupt
 *  0b001001..Selects GPIO9 channel 0 interrupt
 *  0b001010..Selects GPIO9 channel 1 interrupt
 *  0b001011..Selects GPIO10 channel 0 interrupt
 *  0b001100..Selects GPIO10 channel 1 interrupt
 *  0b001101..Selects WWDT2 interrupt
 *  0b001110..Selects WWDT3 interrupt
 *  0b001111..Selects MU0_MUB interrupt for HiFi1 to CPU0
 *  0b010000..Selects MU3_MUB interrupt for HiFi1 to CPU1
 *  0b010001..Selects UTICK1 interrupt
 *  0b010010..Selects MRT1 Ored interrupt
 *  0b010011..Selects OSTIMER event timer HiFi1 wakeup/interrupt
 *  0b010100..Selects CTIMER5 interrupt
 *  0b010101..Selects CTIMER6 interrupt
 *  0b010110..Selects CTIMER7 interrupt
 *  0b010111..Selects RTC1 alarm interrupt to Sense domain
 *  0b011000..Selects RTC_SS1 wakeup interrupt to Sense domain
 *  0b011001..Selects I3C2 interrupt
 *  0b011010..Selects I3C3 interrupt
 *  0b011011..Selects MICFIL interrupt for read data or error
 *  0b011100..Selects MICFIL hardware voice activity detector interrupt or error interrupt
 *  0b100010..Selects eDMA2 channel 0 interrupt
 *  0b100011..Selects eDMA2 channel 1 interrupt
 *  0b100100..Selects eDMA2 channel 2 interrupt
 *  0b100101..Selects eDMA2 channel 3 interrupt
 *  0b100110..Selects eDMA2 channel 4 interrupt
 *  0b100111..Selects eDMA2 channel 5 interrupt
 *  0b101000..Selects eDMA2 channel 6 interrupt
 *  0b101001..Selects eDMA2 channel 7 interrupt
 *  0b101010..Selects eDMA3 channel 0 interrupt
 *  0b101011..Selects eDMA3 channel 1 interrupt
 *  0b101100..Selects eDMA3 channel 2 interrupt
 *  0b101101..Selects eDMA3 channel 3 interrupt
 *  0b101110..Selects eDMA3 channel 4 interrupt
 *  0b101111..Selects eDMA3 channel 5 interrupt
 *  0b110000..Selects eDMA3 channel 6 interrupt
 *  0b110001..Selects eDMA3 channel 7 interrupt
 *  0b110010..Selects PINT1 interrupt 0
 *  0b110011..Selects PINT1 interrupt 1
 *  0b110100..Selects PINT1 interrupt 2
 *  0b110101..Selects PINT1 interrupt 3
 *  0b110110..Selects SAI3 TX/RX interrupt
 */
#define INPUTMUX1_HIFI1_INTERRUPT_TRIGIN(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX1_HIFI1_INTERRUPT_TRIGIN_SHIFT)) & INPUTMUX1_HIFI1_INTERRUPT_TRIGIN_MASK)
/*! @} */

/*! @name FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG - LP_FLEXCOMM Input Connections */
/*! @{ */

#define INPUTMUX1_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_MASK (0xFU)
#define INPUTMUX1_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - LP_FLEXCOMM Input Trigger
 *  0b0000..Selects CTIMER_S_INP0
 *  0b0001..Selects CTIMER_S_INP1
 *  0b0010..Selects CTIMER_S_INP2
 *  0b0011..Selects CTIMER_S_INP3
 *  0b0111..Selects CTIMER5_MAT3
 *  0b1000..Selects CTIMER6_MAT3
 *  0b1001..Selects CTIMER7_MAT3
 *  0b1100..Selects PINT1 boolean pattern-match output
 *  0b1101..Selects ACMP0 CMPO
 *  0b1110..Selects RTC_SS1 Interrupt
 */
#define INPUTMUX1_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX1_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_SHIFT)) & INPUTMUX1_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX1_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG */
#define INPUTMUX1_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_COUNT (4U)

/*! @name ADC_TRIG_ADC0_TRIG - ADC0 Input Connections */
/*! @{ */

#define INPUTMUX1_ADC_TRIG_ADC0_TRIG_TRIGIN_MASK (0x1FU)
#define INPUTMUX1_ADC_TRIG_ADC0_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC0 Input Trigger
 *  0b00000..Selects GPIO0 peripheral output channel 0 trigger
 *  0b00001..Selects GPIO1 peripheral output channel 0 trigger
 *  0b00010..Selects GPIO2 peripheral output channel 0 trigger
 *  0b00011..Selects GPIO3 peripheral output channel 0 trigger
 *  0b00100..Selects GPIO4 peripheral output channel 0 trigger
 *  0b00101..Selects GPIO5 peripheral output channel 0 trigger
 *  0b00110..Selects GPIO6 peripheral output channel 0 trigger
 *  0b00111..Selects GPIO7 peripheral output channel 0 trigger
 *  0b01000..Selects GPIO8 peripheral output channel 0 trigger
 *  0b01001..Selects GPIO9 peripheral output channel 0 trigger
 *  0b01010..Selects GPIO10 peripheral output channel 0 trigger
 *  0b01011..Selects SCT0_OUT4
 *  0b01100..Selects SCT0_OUT5
 *  0b01101..Selects SCT0_OUT9
 *  0b01110..Selects CTIMER0_MAT3
 *  0b01111..Selects CTIMER1_MAT3
 *  0b10000..Selects CTIMER2_MAT3
 *  0b10001..Selects CTIMER3_MAT3
 *  0b10010..Selects CTIMER4_MAT3
 *  0b10011..Selects CTIMER5_MAT3
 *  0b10100..Selects CTIMER6_MAT3
 *  0b10101..Selects CTIMER7_MAT3
 *  0b10110..Selects ACMP0 CMPO
 *  0b10111..Selects CPU0 TXEV
 *  0b11000..Selects CPU1 TXEV
 *  0b11010..Selects PINT0 boolean pattern-match output
 *  0b11011..Selects PINT1 boolean pattern-match output
 */
#define INPUTMUX1_ADC_TRIG_ADC0_TRIG_TRIGIN(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX1_ADC_TRIG_ADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX1_ADC_TRIG_ADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX1_ADC_TRIG_ADC0_TRIG */
#define INPUTMUX1_ADC_TRIG_ADC0_TRIG_COUNT       (2U)

/*! @name CTIMER_CTIMER_CAP_CAP - CTIMER Input Connections */
/*! @{ */

#define INPUTMUX1_CTIMER_CTIMER_CAP_CAP_CAPIN_MASK (0x1FU)
#define INPUTMUX1_CTIMER_CTIMER_CAP_CAP_CAPIN_SHIFT (0U)
/*! CAPIN - CTIMER Input Capture
 *  0b00000..Selects CTIMER_S_INP0
 *  0b00001..Selects CTIMER_S_INP1
 *  0b00010..Selects CTIMER_S_INP2
 *  0b00011..Selects CTIMER_S_INP3
 *  0b00100..Selects CTIMER_S_INP4
 *  0b00101..Selects CTIMER_S_INP5
 *  0b00110..Selects CTIMER_S_INP6
 *  0b00111..Selects CTIMER_S_INP7
 *  0b01000..Selects CTIMER_S_INP8
 *  0b01001..Selects CTIMER_S_INP9
 *  0b10000..Selects SAI3_TX_SYNC
 *  0b10001..Selects SAI3_RX_SYNC
 *  0b10010..Selects ACMP0 CMPO
 *  0b10011..Selects ADC0 trigger completion flag 0
 *  0b10100..Selects ADC0 trigger completion flag 1
 */
#define INPUTMUX1_CTIMER_CTIMER_CAP_CAP_CAPIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX1_CTIMER_CTIMER_CAP_CAP_CAPIN_SHIFT)) & INPUTMUX1_CTIMER_CTIMER_CAP_CAP_CAPIN_MASK)
/*! @} */

/* The count of INPUTMUX1_CTIMER_CTIMER_CAP_CAP */
#define INPUTMUX1_CTIMER_CTIMER_CAP_CAP_COUNT    (3U)

/* The count of INPUTMUX1_CTIMER_CTIMER_CAP_CAP */
#define INPUTMUX1_CTIMER_CTIMER_CAP_CAP_COUNT2   (4U)

/*! @name CTIMER_TRIG - CTIMER Input Connections */
/*! @{ */

#define INPUTMUX1_CTIMER_TRIG_TRIGIN_MASK        (0x1FU)
#define INPUTMUX1_CTIMER_TRIG_TRIGIN_SHIFT       (0U)
/*! TRIGIN - CTIMER Input Trigger
 *  0b00000..Selects CTIMER_S_INP0
 *  0b00001..Selects CTIMER_S_INP1
 *  0b00010..Selects CTIMER_S_INP2
 *  0b00011..Selects CTIMER_S_INP3
 *  0b00100..Selects CTIMER_S_INP4
 *  0b00101..Selects CTIMER_S_INP5
 *  0b00110..Selects CTIMER_S_INP6
 *  0b00111..Selects CTIMER_S_INP7
 *  0b01000..Selects CTIMER_S_INP8
 *  0b01001..Selects CTIMER_S_INP9
 *  0b10000..Selects SAI3_TX_SYNC
 *  0b10001..Selects SAI3_RX_SYNC
 *  0b10010..Selects ACMP0 CMPO
 *  0b10011..Selects ADC0 trigger completion flag 0
 *  0b10100..Selects ADC0 trigger completion flag 1
 */
#define INPUTMUX1_CTIMER_TRIG_TRIGIN(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX1_CTIMER_TRIG_TRIGIN_SHIFT)) & INPUTMUX1_CTIMER_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX1_CTIMER_TRIG */
#define INPUTMUX1_CTIMER_TRIG_COUNT              (3U)


/*!
 * @}
 */ /* end of group INPUTMUX1_Register_Masks */


/*!
 * @}
 */ /* end of group INPUTMUX1_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_INPUTMUX1_H_ */

