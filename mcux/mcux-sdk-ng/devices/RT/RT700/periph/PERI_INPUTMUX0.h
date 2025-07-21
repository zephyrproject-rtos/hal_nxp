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
**         CMSIS Peripheral Access Layer for INPUTMUX0
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
 * @file PERI_INPUTMUX0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for INPUTMUX0
 *
 * CMSIS Peripheral Access Layer for INPUTMUX0
 */

#if !defined(PERI_INPUTMUX0_H_)
#define PERI_INPUTMUX0_H_                        /**< Symbol preventing repeated inclusion */

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
   -- INPUTMUX0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX0_Peripheral_Access_Layer INPUTMUX0 Peripheral Access Layer
 * @{
 */

/** INPUTMUX0 - Size of Registers Arrays */
#define INPUTMUX0_SCT0_TRIG_COUNT                 7u
#define INPUTMUX0_PINT0_TRIG_COUNT                8u
#define INPUTMUX0_HIFI4_INTERRUPT_COUNT           27u
#define INPUTMUX0_FLEXCOMM_TRIG_COUNT             14u
#define INPUTMUX0_CTIMER_CTIMER_CAP_COUNT         4u
#define INPUTMUX0_CTIMER_COUNT                    5u
#define INPUTMUX0_FREQ_MEASURE_COUNT              2u
#define INPUTMUX0_EZH_TRIG_COUNT                  8u
#define INPUTMUX0_FLEXIO_TRIG_COUNT               4u

/** INPUTMUX0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCT0_TRIG[INPUTMUX0_SCT0_TRIG_COUNT]; /**< SCT0 Input Connections, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[228];
  __IO uint32_t PINT0_TRIG[INPUTMUX0_PINT0_TRIG_COUNT]; /**< PINT0 Input Connections, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[32];
  __IO uint32_t HIFI4_INTERRUPT[INPUTMUX0_HIFI4_INTERRUPT_COUNT]; /**< HiFi4 Interrupt Connections, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_2[84];
  struct {                                         /* offset: 0x200, array step: 0x20 */
    __IO uint32_t LP_FLEXCOMM_TRIG;                  /**< LP_FLEXCOMM Input Connections, array offset: 0x200, array step: 0x20 */
         uint8_t RESERVED_0[28];
  } FLEXCOMM_TRIG[INPUTMUX0_FLEXCOMM_TRIG_COUNT];
       uint8_t RESERVED_3[576];
  struct {                                         /* offset: 0x600, array step: 0x20 */
    __IO uint32_t CAP[INPUTMUX0_CTIMER_CTIMER_CAP_COUNT];   /**< CTIMER Input Connections, array offset: 0x600, array step: index*0x20, index2*0x4 */
    __IO uint32_t TRIG;                              /**< CTIMER Input Connections, array offset: 0x610, array step: 0x20 */
         uint8_t RESERVED_0[12];
  } CTIMER[INPUTMUX0_CTIMER_COUNT];
       uint8_t RESERVED_4[96];
  __IO uint32_t FREQME_TRIG[INPUTMUX0_FREQ_MEASURE_COUNT]; /**< FREQME Clock Selection, array offset: 0x700, array step: 0x4 */
       uint8_t RESERVED_5[24];
  __IO uint32_t EZHV_TRIG[INPUTMUX0_EZH_TRIG_COUNT]; /**< EZH-V Input Connections, array offset: 0x720, array step: 0x4 */
       uint8_t RESERVED_6[32];
  __IO uint32_t FLEXIO_TRIG[INPUTMUX0_FLEXIO_TRIG_COUNT]; /**< FLEXIO Input Connections, array offset: 0x760, array step: 0x4 */
} INPUTMUX0_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX0_Register_Masks INPUTMUX0 Register Masks
 * @{
 */

/*! @name SCT0_TRIG - SCT0 Input Connections */
/*! @{ */

#define INPUTMUX0_SCT0_TRIG_TRIGIN_MASK          (0x1FU)
#define INPUTMUX0_SCT0_TRIG_TRIGIN_SHIFT         (0U)
/*! TRIGIN - SCT0 Input Trigger
 *  0b00000..Selects SCT0_GPIN0
 *  0b00001..Selects SCT0_GPIN1
 *  0b00010..Selects SCT0_GPIN2
 *  0b00011..Selects SCT0_GPIN3
 *  0b00100..Selects SCT0_GPIN4
 *  0b00101..Selects SCT0_GPIN5
 *  0b00110..Selects SCT0_GPIN6
 *  0b00111..Selects SCT0_GPIN7
 *  0b01000..Selects CTIMER0_MAT0
 *  0b01001..Selects CTIMER1_MAT0
 *  0b01010..Selects CTIMER2_MAT0
 *  0b01011..Selects CTIMER3_MAT0
 *  0b01100..Selects CTIMER4_MAT0
 *  0b01101..Selects USB1 start of frame
 *  0b01110..Selects PINT0 boolean pattern-match output
 *  0b01111..Selects USB0 start of frame
 *  0b10000..Selects ACMP0 CMPO
 *  0b10001..Selects SAI0_TX_BCLK
 *  0b10010..Selects SAI0_RX_BCLK
 *  0b10011..Selects SAI1_TX_BCLK
 *  0b10100..Selects SAI1_RX_BCLK
 *  0b10101..Selects SAI2_TX_BCLK
 *  0b10110..Selects SAI2_RX_BCLK
 *  0b10111..Selects MCLK
 *  0b11000..Selects CPU0 TXEV
 *  0b11001..Selects CPU0 Halted
 *  0b11010..Selects ADC0 trigger completion flag 0
 *  0b11011..Selects ADC0 trigger completion flag 1
 */
#define INPUTMUX0_SCT0_TRIG_TRIGIN(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_SCT0_TRIG_TRIGIN_SHIFT)) & INPUTMUX0_SCT0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name PINT0_TRIG - PINT0 Input Connections */
/*! @{ */

#define INPUTMUX0_PINT0_TRIG_TRIGIN_MASK         (0x3FU)
#define INPUTMUX0_PINT0_TRIG_TRIGIN_SHIFT        (0U)
/*! TRIGIN - PINT0 Input Trigger
 *  0b000000..Selects PIO0_0
 *  0b000001..Selects PIO0_1
 *  0b000010..Selects PIO0_2
 *  0b000011..Selects PIO0_3
 *  0b000100..Selects PIO0_4
 *  0b000101..Selects PIO0_5
 *  0b000110..Selects PIO0_6
 *  0b000111..Selects PIO0_7
 *  0b001000..Selects PIO0_8
 *  0b001001..Selects PIO0_9
 *  0b001010..Selects PIO0_10
 *  0b001011..Selects PIO0_11
 *  0b001100..Selects PIO0_12
 *  0b001101..Selects PIO0_13
 *  0b001110..Selects PIO0_14
 *  0b001111..Selects PIO0_15
 *  0b010000..Selects PIO0_16
 *  0b010001..Selects PIO0_17
 *  0b010010..Selects PIO0_18
 *  0b010011..Selects PIO0_19
 *  0b010100..Selects PIO0_20
 *  0b010101..Selects PIO0_21
 *  0b010110..Selects PIO0_22
 *  0b010111..Selects PIO0_23
 *  0b011000..Selects PIO0_24
 *  0b011001..Selects PIO0_25
 *  0b011010..Selects PIO0_26
 *  0b011011..Selects PIO0_27
 *  0b011100..Selects PIO0_28
 *  0b011101..Selects PIO0_29
 *  0b011110..Selects PIO0_30
 *  0b011111..Selects PIO0_31
 *  0b100000..Selects PIO1_0
 *  0b100001..Selects PIO1_1
 *  0b100010..Selects PIO1_2
 *  0b100011..Selects PIO1_3
 *  0b100100..Selects PIO1_4
 *  0b100101..Selects PIO1_5
 *  0b100110..Selects PIO1_6
 *  0b100111..Selects PIO1_7
 *  0b101000..Selects PIO1_8
 *  0b101001..Selects PIO1_9
 *  0b101010..Selects PIO1_10
 *  0b101011..Selects PIO1_11
 *  0b101100..Selects PIO1_12
 *  0b101101..Selects PIO1_13
 *  0b101110..Selects PIO1_14
 *  0b101111..Selects PIO1_15
 *  0b110000..Selects PIO1_16
 *  0b110001..Selects PIO1_17
 *  0b110010..Selects PIO1_18
 *  0b110011..Selects PIO1_19
 */
#define INPUTMUX0_PINT0_TRIG_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_PINT0_TRIG_TRIGIN_SHIFT)) & INPUTMUX0_PINT0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name HIFI4_INTERRUPT - HiFi4 Interrupt Connections */
/*! @{ */

#define INPUTMUX0_HIFI4_INTERRUPT_TRIGIN_MASK    (0x7FU)
#define INPUTMUX0_HIFI4_INTERRUPT_TRIGIN_SHIFT   (0U)
/*! TRIGIN - HiFi4 Input Interrupt
 *  0b0000000..Selects LP_FLEXCOMM0 interrupt
 *  0b0000001..Selects LP_FLEXCOMM1 interrupt
 *  0b0000010..Selects LP_FLEXCOMM2 interrupt
 *  0b0000011..Selects LP_FLEXCOMM3 interrupt
 *  0b0000100..Selects LP_FLEXCOMM4 interrupt
 *  0b0000101..Selects LP_FLEXCOMM5 interrupt
 *  0b0000110..Selects LP_FLEXCOMM6 interrupt
 *  0b0000111..Selects LP_FLEXCOMM7 interrupt
 *  0b0001000..Selects LP_FLEXCOMM8 interrupt
 *  0b0001001..Selects LP_FLEXCOMM9 interrupt
 *  0b0001010..Selects LP_FLEXCOMM10 interrupt
 *  0b0001011..Selects LP_FLEXCOMM11 interrupt
 *  0b0001100..Selects LP_FLEXCOMM12 interrupt
 *  0b0001101..Selects LP_FLEXCOMM13 interrupt
 *  0b0001110..Selects MU2_MUA interrupt for HiFi4 to CPU1
 *  0b0001111..Selects MU4_MUB interrupt for HiFi4 to CPU0
 *  0b0010000..Selects WWDT0 interrupt
 *  0b0010001..Selects WWDT1 interrupt
 *  0b0010010..Selects UTICK0 interrupt
 *  0b0010011..Selects LPSPI14 interrupt
 *  0b0010100..Selects MRT0 Ored interrupt
 *  0b0010101..Selects OSTIMER event timer for HiFi4 wakeup/interrupt
 *  0b0010110..Selects CTIMER0 interrupt
 *  0b0010111..Selects CTIMER1 interrupt
 *  0b0011000..Selects CTIMER2 interrupt
 *  0b0011001..Selects CTIMER3 interrupt
 *  0b0011010..Selects CTIMER4 interrupt
 *  0b0011011..Selects RTC0 alarm interrupt to computer domain
 *  0b0011100..Selects RTC_SS0 wakeup interrupt to compute domain
 *  0b0011101..Selects I3C0 interrupt
 *  0b0011110..Selects I3C1 interrupt
 *  0b0011111..Selects MICFIL interrupt for read data or error
 *  0b0100000..Selects MICFIL hardware voice activity detector interrupt or error interrupt
 *  0b0100001..Selects LCDIF interrupt
 *  0b0100010..Selects VGPU interrupt from graphics core (domain HCLK)
 *  0b0100011..Selects EZH-V interrupt
 *  0b0100100..Selects FLEXIO interrupt
 *  0b0100101..Selects LPSPI16 interrupt
 *  0b0100110..Selects eDMA0 channel 0 interrupt
 *  0b0100111..Selects eDMA0 channel 1 interrupt
 *  0b0101000..Selects eDMA0 channel 2 interrupt
 *  0b0101001..Selects eDMA0 channel 3 interrupt
 *  0b0101010..Selects eDMA0 channel 4 interrupt
 *  0b0101011..Selects eDMA0 channel 5 interrupt
 *  0b0101100..Selects eDMA0 channel 6 interrupt
 *  0b0101101..Selects eDMA0 channel 7 interrupt
 *  0b0101110..Selects eDMA0 channel 8 interrupt
 *  0b0101111..Selects eDMA0 channel 9 interrupt
 *  0b0110000..Selects eDMA0 channel 10 interrupt
 *  0b0110001..Selects eDMA0 channel 11 interrupt
 *  0b0110010..Selects eDMA0 channel 12 interrupt
 *  0b0110011..Selects eDMA0 channel 13 interrupt
 *  0b0110100..Selects eDMA0 channel 14 interrupt
 *  0b0110101..Selects eDMA0 channel 15 interrupt
 *  0b0110110..Selects eDMA1 channel 0 interrupt
 *  0b0110111..Selects eDMA1 channel 1 interrupt
 *  0b0111000..Selects eDMA1 channel 2 interrupt
 *  0b0111001..Selects eDMA1 channel 3 interrupt
 *  0b0111010..Selects eDMA1 channel 4 interrupt
 *  0b0111011..Selects eDMA1 channel 5 interrupt
 *  0b0111100..Selects eDMA1 channel 6 interrupt
 *  0b0111101..Selects eDMA1 channel 7 interrupt
 *  0b0111110..Selects eDMA1 channel 8 interrupt
 *  0b0111111..Selects eDMA1 channel 9 interrupt
 *  0b1000000..Selects eDMA1 channel 10 interrupt
 *  0b1000001..Selects eDMA1 channel 11 interrupt
 *  0b1000010..Selects eDMA1 channel 12 interrupt
 *  0b1000011..Selects eDMA1 channel 13 interrupt
 *  0b1000100..Selects eDMA1 channel 14 interrupt
 *  0b1000101..Selects eDMA1 channel 15 interrupt
 *  0b1000110..Selects GPIO0 channel 0 interrupt
 *  0b1000111..Selects GPIO0 channel 1 interrupt
 *  0b1001000..Selects GPIO1 channel 0 interrupt
 *  0b1001001..Selects GPIO1 channel 1 interrupt
 *  0b1001010..Selects GPIO2 channel 0 interrupt
 *  0b1001011..Selects GPIO2 channel 1 interrupt
 *  0b1001100..Selects GPIO3 channel 0 interrupt
 *  0b1001101..Selects GPIO3 channel 1 interrupt
 *  0b1001110..Selects GPIO4 channel 0 interrupt
 *  0b1001111..Selects GPIO4 channel 1 interrupt
 *  0b1010000..Selects GPIO5 channel 0 interrupt
 *  0b1010001..Selects GPIO5 channel 1 interrupt
 *  0b1010010..Selects GPIO6 channel 0 interrupt
 *  0b1010011..Selects GPIO6 channel 1 interrupt
 *  0b1010100..Selects GPIO7 channel 0 interrupt
 *  0b1010101..Selects GPIO7 channel 1 interrupt
 *  0b1010110..Selects PINT0 interrupt 0
 *  0b1010111..Selects PINT0 interrupt 1
 *  0b1011000..Selects PINT0 interrupt 2
 *  0b1011001..Selects PINT0 interrupt 3
 *  0b1011010..Selects PINT0 interrupt 4
 *  0b1011011..Selects PINT0 interrupt 5
 *  0b1011100..Selects PINT0 interrupt 6
 *  0b1011101..Selects PINT0 interrupt 7
 *  0b1011110..Selects SAI0 TX/RX interrupt
 *  0b1011111..Selects SAI1 TX/RX interrupt
 *  0b1100000..Selects SAI2 TX/RX interrupt
 *  0b1100010..Selects XSPI0 Ored interrupt and flash error interrupt.
 *  0b1100011..Selects XSPI1 Ored interrupt and flash error interrupt.
 *  0b1100100..Selects XSPI2 Ored interrupt and flash error interrupt.
 *  0b1100101..Selects JPGDECWRP Ored context 0-3 interrupt
 *  0b1100110..Selects PNGDEC interrupt
 *  0b1100111..Selects NPU interrupt
 *  0b1101000..Selects PMC0 interrupt
 */
#define INPUTMUX0_HIFI4_INTERRUPT_TRIGIN(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_HIFI4_INTERRUPT_TRIGIN_SHIFT)) & INPUTMUX0_HIFI4_INTERRUPT_TRIGIN_MASK)
/*! @} */

/*! @name FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG - LP_FLEXCOMM Input Connections */
/*! @{ */

#define INPUTMUX0_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_MASK (0xFU)
#define INPUTMUX0_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - LP_FLEXCOMM Input Trigger
 *  0b0000..Selects CTIMER_C_INP0
 *  0b0001..Selects CTIMER_C_INP1
 *  0b0010..Selects CTIMER_C_INP2
 *  0b0011..Selects CTIMER_C_INP3
 *  0b0100..Selects SCT0_OUT3
 *  0b0101..Selects SCT0_OUT6
 *  0b0110..Selects SCT0_OUT9
 *  0b0111..Selects CTIMER0_MAT3
 *  0b1000..Selects CTIMER1_MAT3
 *  0b1001..Selects CTIMER2_MAT3
 *  0b1010..Selects CTIMER3_MAT3
 *  0b1011..Selects CTIMER4_MAT3
 *  0b1100..Selects PINT0 boolean pattern-match output
 *  0b1101..Selects ACMP0 CMPO
 *  0b1110..Selects RTC_SS0 interrupt
 */
#define INPUTMUX0_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_SHIFT)) & INPUTMUX0_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX0_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG */
#define INPUTMUX0_FLEXCOMM_TRIG_LP_FLEXCOMM_TRIG_COUNT (14U)

/*! @name CTIMER_CTIMER_CAP_CAP - CTIMER Input Connections */
/*! @{ */

#define INPUTMUX0_CTIMER_CTIMER_CAP_CAP_CAPIN_MASK (0x1FU)
#define INPUTMUX0_CTIMER_CTIMER_CAP_CAP_CAPIN_SHIFT (0U)
/*! CAPIN - CTIMER input capture
 *  0b00000..Selects CTIMER_C_INP0
 *  0b00001..Selects CTIMER_C_INP1
 *  0b00010..Selects CTIMER_C_INP2
 *  0b00011..Selects CTIMER_C_INP3
 *  0b00100..Selects CTIMER_C_INP4
 *  0b00101..Selects CTIMER_C_INP5
 *  0b00110..Selects CTIMER_C_INP6
 *  0b00111..Selects CTIMER_C_INP7
 *  0b01000..Selects CTIMER_C_INP8
 *  0b01001..Selects CTIMER_C_INP9
 *  0b01010..Selects CTIMER_C_INP10
 *  0b01011..Selects CTIMER_C_INP11
 *  0b01100..Selects CTIMER_C_INP12
 *  0b01101..Selects CTIMER_C_INP13
 *  0b01110..Selects CTIMER_C_INP14
 *  0b01111..Selects CTIMER_C_INP15
 *  0b10000..Selects SAI0_TX_SYNC
 *  0b10001..Selects SAI0_RX_SYNC
 *  0b10010..Selects SAI1_TX_SYNC
 *  0b10011..Selects SAI1_RX_SYNC
 *  0b10100..Selects SAI2_TX_SYNC
 *  0b10101..Selects SAI2_RX_SYNC
 *  0b10110..Selects USB0 start of frame
 *  0b10111..Selects USB1 start of frame
 *  0b11000..Selects ACMP0 CMPO
 *  0b11001..Selects ADC0 trigger completion flag 0
 *  0b11010..Selects ADC0 trigger completion flag 1
 *  0b11011..Selects ITRC TMPR_OUT[0]
 *  0b11100..Selects ITRC TMPR_OUT[1]
 */
#define INPUTMUX0_CTIMER_CTIMER_CAP_CAP_CAPIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_CTIMER_CTIMER_CAP_CAP_CAPIN_SHIFT)) & INPUTMUX0_CTIMER_CTIMER_CAP_CAP_CAPIN_MASK)
/*! @} */

/* The count of INPUTMUX0_CTIMER_CTIMER_CAP_CAP */
#define INPUTMUX0_CTIMER_CTIMER_CAP_CAP_COUNT    (5U)

/* The count of INPUTMUX0_CTIMER_CTIMER_CAP_CAP */
#define INPUTMUX0_CTIMER_CTIMER_CAP_CAP_COUNT2   (4U)

/*! @name CTIMER_TRIG - CTIMER Input Connections */
/*! @{ */

#define INPUTMUX0_CTIMER_TRIG_TRIGIN_MASK        (0x1FU)
#define INPUTMUX0_CTIMER_TRIG_TRIGIN_SHIFT       (0U)
/*! TRIGIN - CTIMER Input Trigger
 *  0b00000..Selects CTIMER_C_INP0
 *  0b00001..Selects CTIMER_C_INP1
 *  0b00010..Selects CTIMER_C_INP2
 *  0b00011..Selects CTIMER_C_INP3
 *  0b00100..Selects CTIMER_C_INP4
 *  0b00101..Selects CTIMER_C_INP5
 *  0b00110..Selects CTIMER_C_INP6
 *  0b00111..Selects CTIMER_C_INP7
 *  0b01000..Selects CTIMER_C_INP8
 *  0b01001..Selects CTIMER_C_INP9
 *  0b01010..Selects CTIMER_C_INP10
 *  0b01011..Selects CTIMER_C_INP11
 *  0b01100..Selects CTIMER_C_INP12
 *  0b01101..Selects CTIMER_C_INP13
 *  0b01110..Selects CTIMER_C_INP14
 *  0b01111..Selects CTIMER_C_INP15
 *  0b10000..Selects SAI0_TX_SYNC
 *  0b10001..Selects SAI0_RX_SYNC
 *  0b10010..Selects SAI1_TX_SYNC
 *  0b10011..Selects SAI1_RX_SYNC
 *  0b10100..Selects SAI2_TX_SYNC
 *  0b10101..Selects SAI2_RX_SYNC
 *  0b10110..Selects USB0 start of frame
 *  0b10111..Selects USB1 start of frame
 *  0b11000..Selects ACMP0 CMPO
 *  0b11001..Selects ADC0 trigger completion flag 0
 *  0b11010..Selects ADC0 trigger completion flag 1
 *  0b11011..Selects ITRC TMPR_OUT[0]
 *  0b11100..Selects ITRC TMPR_OUT[1]
 */
#define INPUTMUX0_CTIMER_TRIG_TRIGIN(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_CTIMER_TRIG_TRIGIN_SHIFT)) & INPUTMUX0_CTIMER_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX0_CTIMER_TRIG */
#define INPUTMUX0_CTIMER_TRIG_COUNT              (5U)

/*! @name FREQ_MEASURE_FREQME_TRIG - FREQME Clock Selection */
/*! @{ */

#define INPUTMUX0_FREQ_MEASURE_FREQME_TRIG_TRIGIN_MASK (0x1FU)
#define INPUTMUX0_FREQ_MEASURE_FREQME_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - FREQME Input Clock
 *  0b00000..Selects main crystal oscillator
 *  0b00001..Selects FRO1_DIV8
 *  0b00010..Selects FRO1
 *  0b00011..Selects LPOSC
 *  0b00100..Selects OSC32KNP osc32k_out
 *  0b00110..Selects FRO0
 *  0b00111..Selects FRO2
 *  0b01000..Selects FREQME_GPIO_A_CLK
 *  0b01001..Selects FREQME_GPIO_B_CLK
 */
#define INPUTMUX0_FREQ_MEASURE_FREQME_TRIG_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_FREQ_MEASURE_FREQME_TRIG_TRIGIN_SHIFT)) & INPUTMUX0_FREQ_MEASURE_FREQME_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX0_FREQ_MEASURE_FREQME_TRIG */
#define INPUTMUX0_FREQ_MEASURE_FREQME_TRIG_COUNT (2U)

/*! @name EZH_TRIG_EZHV_TRIG - EZH-V Input Connections */
/*! @{ */

#define INPUTMUX0_EZH_TRIG_EZHV_TRIG_TRIGIN_MASK (0x7FU)
#define INPUTMUX0_EZH_TRIG_EZHV_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - EZH-V Input Trigger
 *  0b0000000..Selects GPIO0 peripheral output channel 0 trigger
 *  0b0000001..Selects GPIO0 peripheral output channel 1 trigger
 *  0b0000010..Selects GPIO1 peripheral output channel 0 trigger
 *  0b0000011..Selects GPIO1 peripheral output channel 1 trigger
 *  0b0000100..Selects GPIO2 peripheral output channel 0 trigger
 *  0b0000101..Selects GPIO2 peripheral output channel 1 trigger
 *  0b0000110..Selects GPIO3 peripheral output channel 0 trigger
 *  0b0000111..Selects GPIO3 peripheral output channel 1 trigger
 *  0b0001000..Selects GPIO4 peripheral output channel 0 trigger
 *  0b0001001..Selects GPIO4 peripheral output channel 1 trigger
 *  0b0001010..Selects GPIO5 peripheral output channel 0 trigger
 *  0b0001011..Selects GPIO5 peripheral output channel 1 trigger
 *  0b0001100..Selects GPIO6 peripheral output channel 0 trigger
 *  0b0001101..Selects GPIO6 peripheral output channel 1 trigger
 *  0b0001110..Selects GPIO7 peripheral output channel 0 trigger
 *  0b0001111..Selects GPIO7 peripheral output channel 1 trigger
 *  0b0010000..Selects LP_FLEXCOMM0 interrupt
 *  0b0010001..Selects LP_FLEXCOMM1 interrupt
 *  0b0010010..Selects LP_FLEXCOMM2 interrupt
 *  0b0010011..Selects LP_FLEXCOMM3 interrupt
 *  0b0010100..Selects LP_FLEXCOMM4 interrupt
 *  0b0010101..Selects LP_FLEXCOMM5 interrupt
 *  0b0010110..Selects LP_FLEXCOMM6 interrupt
 *  0b0010111..Selects LP_FLEXCOMM7 interrupt
 *  0b0011000..Selects LPSPI14 interrupt
 *  0b0011001..Selects LPSPI16 interrupt
 *  0b0011010..Selects I3C0 interrupt
 *  0b0011011..Selects I3C1 interrupt
 *  0b0011100..Selects I3C2 interrupt
 *  0b0011101..Selects I3C3 interrupt
 *  0b0011110..Selects FLEXIO interrupt
 *  0b0011111..Selects GPIO0 interrupt
 *  0b0100000..Selects GPIO1 interrupt
 *  0b0100001..Selects GPIO2 interrupt
 *  0b0100010..Selects GPIO3 interrupt
 *  0b0100011..Selects GPIO4 interrupt
 *  0b0100100..Selects GPIO5 interrupt
 *  0b0100101..Selects GPIO6 interrupt
 *  0b0100110..Selects GPIO7 interrupt
 *  0b0100111..Selects GPIO8 interrupt
 *  0b0101000..Selects GPIO9 interrupt
 *  0b0101001..Selects GPIO10 interrupt
 *  0b0101010..Selects SCT0 interrupt
 *  0b0101011..Selects CTIMER0 interrupt
 *  0b0101100..Selects CTIMER1 interrupt
 *  0b0101101..Selects CTIMER2 interrupt
 *  0b0101110..Selects CTIMER3 interrupt
 *  0b0101111..Selects CTIMER4 interrupt
 *  0b0110000..Selects CTIMER5 interrupt
 *  0b0110001..Selects CTIMER6 interrupt
 *  0b0110010..Selects CTIMER7 interrupt
 *  0b0110011..Selects UTICK0 interrupt
 *  0b0110100..Selects MRT0 interrupt
 *  0b0110101..Selects RTC0 interrupt
 *  0b0110110..Selects OSTIMER event timer CPU0 wakeup/interrupt
 *  0b0110111..Selects WWDT0 interrupt
 *  0b0111000..Selects WWDT1 interrupt
 *  0b0111001..Selects ADC0 interrupt
 *  0b0111010..Selects ACMP0 interrupt
 *  0b0111011..Selects MICFIL interrupt
 *  0b0111100..Selects MICFIL HWVAD
 *  0b0111101..Selects uSDHC0 interrupt
 *  0b0111110..Selects uSDHC1 interrupt
 *  0b0111111..Selects USB0 interrupt
 *  0b1000000..Selects USB1 interrupt
 *  0b1000001..Selects LCDIF interrupt
 *  0b1000010..Selects VGPU interrupt
 *  0b1000011..Selects eDMA0 channel 0 interrupt
 *  0b1000100..Selects eDMA0 channel 1 interrupt
 *  0b1000101..Selects eDMA0 channel 2 interrupt
 *  0b1000110..Selects eDMA0 channel 3 interrupt
 *  0b1000111..Selects eDMA1 channel 0 interrupt
 *  0b1001000..Selects eDMA1 channel 1 interrupt
 *  0b1001001..Selects eDMA1 channel 2 interrupt
 *  0b1001010..Selects eDMA1 channel 3 interrupt
 *  0b1001011..Selects eDMA2 channel 0 interrupt
 *  0b1001100..Selects eDMA2 channel 1 interrupt
 *  0b1001101..Selects eDMA2 channel 2 interrupt
 *  0b1001110..Selects eDMA2 channel 3 interrupt
 *  0b1001111..Selects eDMA3 channel 0 interrupt
 *  0b1010000..Selects eDMA3 channel 1 interrupt
 *  0b1010001..Selects eDMA3 channel 2 interrupt
 *  0b1010010..Selects eDMA3 channel 3 interrupt
 *  0b1010011..Selects HiFi1 TIE_EXPSTATE_1
 *  0b1010100..Selects HiFi4 TIE_EXPSTATE_1
 *  0b1010101..Selects SCT0_OUT8
 *  0b1010110..Selects SCT0_OUT9
 *  0b1010111..Selects CTIMER4_MAT3
 *  0b1011000..Selects CTIMER4_MAT2
 *  0b1011001..Selects CTIMER3_MAT3
 *  0b1011010..Selects CTIMER3_MAT2
 *  0b1011011..Selects CPU0 TXEV
 *  0b1011100..Selects PINT0 boolean pattern-match output
 *  0b1011101..Selects MIPI_DSI_HOST interrupt
 *  0b1011110..Selects USB0 start of frame
 *  0b1011111..Selects USB1 start of frame
 *  0b1100000..Selects ITRC TMPR_OUT[0]
 *  0b1100001..Selects ITRC TMPR_OUT[1]
 */
#define INPUTMUX0_EZH_TRIG_EZHV_TRIG_TRIGIN(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_EZH_TRIG_EZHV_TRIG_TRIGIN_SHIFT)) & INPUTMUX0_EZH_TRIG_EZHV_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX0_EZH_TRIG_EZHV_TRIG */
#define INPUTMUX0_EZH_TRIG_EZHV_TRIG_COUNT       (8U)

/*! @name FLEXIO_TRIG - FLEXIO Input Connections */
/*! @{ */

#define INPUTMUX0_FLEXIO_TRIG_TRIGIN_MASK        (0x3FU)
#define INPUTMUX0_FLEXIO_TRIG_TRIGIN_SHIFT       (0U)
/*! TRIGIN - FLEXIO Input Trigger
 *  0b000000..Selects CTIMER_C_INP0
 *  0b000001..Selects CTIMER_C_INP1
 *  0b000010..Selects CTIMER_C_INP2
 *  0b000011..Selects CTIMER_C_INP3
 *  0b000100..Selects SCT0_OUT6
 *  0b000101..Selects SCT0_OUT7
 *  0b000110..Selects SCT0_OUT8
 *  0b000111..Selects CTIMER0_MAT3
 *  0b001000..Selects CTIMER1_MAT3
 *  0b001001..Selects CTIMER2_MAT3
 *  0b001010..Selects CTIMER3_MAT3
 *  0b001011..Selects CTIMER4_MAT3
 *  0b001100..Selects PINT0 boolean pattern-match output
 *  0b001101..Selects ACMP0 CMPO
 *  0b001111..Selects RTC_SS0 interrupt
 *  0b010000..Selects GPIO0 peripheral output channel 0 trigger
 *  0b010001..Selects GPIO0 peripheral output channel 1 trigger
 *  0b010010..Selects GPIO1 peripheral output channel 0 trigger
 *  0b010011..Selects GPIO1 peripheral output channel 1 trigger
 *  0b010100..Selects GPIO2 peripheral output channel 0 trigger
 *  0b010101..Selects GPIO2 peripheral output channel 1 trigger
 *  0b010110..Selects GPIO3 peripheral output channel 0 trigger
 *  0b010111..Selects GPIO3 peripheral output channel 1 trigger
 *  0b011000..Selects GPIO4 peripheral output channel 0 trigger
 *  0b011001..Selects GPIO4 peripheral output channel 1 trigger
 *  0b011010..Selects GPIO5 peripheral output channel 0 trigger
 *  0b011011..Selects GPIO5 peripheral output channel 1 trigger
 *  0b011100..Selects GPIO6 peripheral output channel 0 trigger
 *  0b011101..Selects GPIO6 peripheral output channel 1 trigger
 *  0b011110..Selects GPIO7 peripheral output channel 0 trigger
 *  0b011111..Selects GPIO7 peripheral output channel 1 trigger
 *  0b100000..Selects GPIO8 peripheral output channel 0 trigger
 *  0b100001..Selects GPIO8 peripheral output channel 1 trigger
 *  0b100010..Selects GPIO9 peripheral output channel 0 trigger
 *  0b100011..Selects GPIO9 peripheral output channel 1 trigger
 *  0b100100..Selects GPIO10 peripheral output channel 0 trigger
 *  0b100101..Selects GPIO10 peripheral output channel 1 trigger
 *  0b100110..Selects ITRC TMPR_OUT[0]
 *  0b100111..Selects ITRC TMPR_OUT[1]
 */
#define INPUTMUX0_FLEXIO_TRIG_TRIGIN(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX0_FLEXIO_TRIG_TRIGIN_SHIFT)) & INPUTMUX0_FLEXIO_TRIG_TRIGIN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INPUTMUX0_Register_Masks */


/*!
 * @}
 */ /* end of group INPUTMUX0_Peripheral_Access_Layer */


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


#endif  /* PERI_INPUTMUX0_H_ */

