/*
** ###################################################################
**     Processors:          MCXC151VFG
**                          MCXC151VFK
**                          MCXC151VFM
**                          MCXC151VFT
**                          MCXC151VLF
**                          MCXC161VFG
**                          MCXC161VFK
**                          MCXC161VFM
**                          MCXC161VFT
**                          MCXC161VLF
**                          MCXC162VFG
**                          MCXC162VFK
**                          MCXC162VFM
**                          MCXC162VFT
**                          MCXC162VLF
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b260121
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INPUTMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_INPUTMUX.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for INPUTMUX
 *
 * CMSIS Peripheral Access Layer for INPUTMUX
 */

#if !defined(PERI_INPUTMUX_H_)
#define PERI_INPUTMUX_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC151VFG) || defined(CPU_MCXC151VFK) || defined(CPU_MCXC151VFM) || defined(CPU_MCXC151VFT) || defined(CPU_MCXC151VLF))
#include "MCXC151_COMMON.h"
#elif (defined(CPU_MCXC161VFG) || defined(CPU_MCXC161VFK) || defined(CPU_MCXC161VFM) || defined(CPU_MCXC161VFT) || defined(CPU_MCXC161VLF))
#include "MCXC161_COMMON.h"
#elif (defined(CPU_MCXC162VFG) || defined(CPU_MCXC162VFK) || defined(CPU_MCXC162VFM) || defined(CPU_MCXC162VFT) || defined(CPU_MCXC162VLF))
#include "MCXC162_COMMON.h"
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
#define INPUTMUX_CTIMERA_COUNT                    4u
#define INPUTMUX_CTIMERB_COUNT                    4u
#define INPUTMUX_ADC0_TRIGM_COUNT                 4u
#define INPUTMUX_EXT_TRIGA_COUNT                  5u
#define INPUTMUX_EXT_TRIGB_COUNT                  2u
#define INPUTMUX_TRIGFILP_COUNT                   12u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t CTIMER0CAP[INPUTMUX_CTIMERA_COUNT]; /**< Capture select register for CTIMER inputs, array offset: 0x20, array step: 0x4 */
  __IO uint32_t CTIMER0TRIG;                       /**< Trigger register for CTIMER0, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CTIMER1CAP[INPUTMUX_CTIMERB_COUNT]; /**< Capture select register for CTIMER inputs, array offset: 0x40, array step: 0x4 */
  __IO uint32_t CTIMER1TRIG;                       /**< Trigger register for CTIMER1, offset: 0x50 */
       uint8_t RESERVED_2[300];
  __IO uint32_t FREQMEAS_REF;                      /**< Selection for frequency measurement reference clock, offset: 0x180 */
  __IO uint32_t FREQMEAS_TAR;                      /**< Selection for frequency measurement target clock, offset: 0x184 */
       uint8_t RESERVED_3[216];
  __IO uint32_t CMP0_TRIG;                         /**< CMP0 input connections, offset: 0x260 */
       uint8_t RESERVED_4[28];
  __IO uint32_t ADC0_TRIG[INPUTMUX_ADC0_TRIGM_COUNT]; /**< ADC Trigger input connections, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_5[272];
  __IO uint32_t FLEXPWM0_SM0_EXTA0;                /**< PWM0 input trigger connections, offset: 0x3A0 */
  __IO uint32_t FLEXPWM0_SM0_EXTSYNC;              /**< PWM0 input trigger connections, offset: 0x3A4 */
  __IO uint32_t FLEXPWM0_SM1_EXTA;                 /**< PWM0 input trigger connections, offset: 0x3A8 */
  __IO uint32_t FLEXPWM0_SM1_EXTSYNC;              /**< PWM0 input trigger connections, offset: 0x3AC */
  __IO uint32_t FLEXPWM0_SM2_EXTA;                 /**< PWM0 input trigger connections, offset: 0x3B0 */
  __IO uint32_t FLEXPWM0_SM2_EXTSYNC;              /**< PWM0 input trigger connections, offset: 0x3B4 */
       uint8_t RESERVED_6[8];
  __IO uint32_t FLEXPWM0_FAULT0;                   /**< PWM0 input trigger connections, offset: 0x3C0 */
  __IO uint32_t FLEXPWM0_FAULT1;                   /**< PWM0 input trigger connections, offset: 0x3C4 */
  __IO uint32_t FLEXPWM0_FAULT2;                   /**< PWM0 input trigger connections, offset: 0x3C8 */
  __IO uint32_t FLEXPWM0_FAULT3;                   /**< PWM0 input trigger connections, offset: 0x3CC */
  __IO uint32_t FLEXPWM0_FORCE;                    /**< PWM0 input trigger connections, offset: 0x3D0 */
       uint8_t RESERVED_7[76];
  __IO uint32_t PWM0_EXT_CLK;                      /**< PWM0 external clock trigger, offset: 0x420 */
       uint8_t RESERVED_8[156];
  __IO uint32_t EXT_TRIG[INPUTMUX_EXT_TRIGA_COUNT]; /**< EXT trigger connections 0-4, array offset: 0x4C0, array step: 0x4 */
       uint8_t RESERVED_9[4];
  __IO uint32_t EXT_TRIGB[INPUTMUX_EXT_TRIGB_COUNT]; /**< EXT trigger connections 6-7, array offset: 0x4D8, array step: 0x4 */
       uint8_t RESERVED_10[192];
  __IO uint32_t LPI2C0_TRIG;                       /**< LPI2C0 trigger input connections, offset: 0x5A0 */
       uint8_t RESERVED_11[60];
  __IO uint32_t LPSPI0_TRIG;                       /**< LPSPI0 trigger input connections, offset: 0x5E0 */
       uint8_t RESERVED_12[60];
  __IO uint32_t LPUART0r;                          /**< LPUART0 trigger input connections, offset: 0x620, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART0' */
       uint8_t RESERVED_13[28];
  __IO uint32_t LPUART1r;                          /**< LPUART1 trigger input connections, offset: 0x640, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART1' */
       uint8_t RESERVED_14[28];
  __IO uint32_t LPUART2r;                          /**< LPUART2 trigger input connections, offset: 0x660, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART2' */
       uint8_t RESERVED_15[28];
  __IO uint32_t LPUART3r;                          /**< LPUART3 trigger input connections, offset: 0x680, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART3' */
       uint8_t RESERVED_16[892];
  __IO uint32_t TRIGFIL_PRSC;                      /**< Trigger filter prescaller, offset: 0xA00 */
  __I  uint32_t TRIGFIL_STAT0;                     /**< Trigger filter stat, offset: 0xA04 */
       uint8_t RESERVED_17[8];
  __IO uint32_t TRIGFIL[INPUTMUX_TRIGFILP_COUNT];  /**< TRIGFIL control, array offset: 0xA10, array step: 0x4 */
} INPUTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Register_Masks INPUTMUX Register Masks
 * @{
 */

/*! @name CTIMERA_CTIMER0CAP - Capture select register for CTIMER inputs */
/*! @{ */

#define INPUTMUX_CTIMERA_CTIMER0CAP_INP_MASK     (0x7FU)
#define INPUTMUX_CTIMERA_CTIMER0CAP_INP_SHIFT    (0U)
/*! INP - Input number for CTIMER0
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..Reserved
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..Reserved
 *  0b0001100..Reserved
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..Reserved
 *  0b0010000..Reserved
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..Reserved
 *  0b0010111..Reserved
 *  0b0011000..Reserved
 *  0b0011001..Reserved
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTimer1_MAT1 input is selected
 *  0b0100010..CTimer1_MAT2 input is selected
 *  0b0100011..CTimer1_MAT3 input is selected
 *  0b0100100..Reserved
 *  0b0100101..Reserved
 *  0b0100110..Reserved
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..Reserved
 *  0b0110011..Reserved
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..Reserved
 *  0b1010001..Reserved
 *  0b1010010..Reserved
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMERA_CTIMER0CAP_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMERA_CTIMER0CAP_INP_SHIFT)) & INPUTMUX_CTIMERA_CTIMER0CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMERA_CTIMER0CAP */
#define INPUTMUX_CTIMERA_CTIMER0CAP_COUNT        (4U)

/*! @name CTIMER0TRIG - Trigger register for CTIMER0 */
/*! @{ */

#define INPUTMUX_CTIMER0TRIG_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER0TRIG_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER0
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..Reserved
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..Reserved
 *  0b0001100..Reserved
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..Reserved
 *  0b0010000..Reserved
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..Reserved
 *  0b0010111..Reserved
 *  0b0011000..Reserved
 *  0b0011001..Reserved
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTimer1_MAT1 input is selected
 *  0b0100010..CTimer1_MAT2 input is selected
 *  0b0100011..CTimer1_MAT3 input is selected
 *  0b0100100..Reserved
 *  0b0100101..Reserved
 *  0b0100110..Reserved
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..Reserved
 *  0b0110011..Reserved
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..Reserved
 *  0b1010001..Reserved
 *  0b1010010..Reserved
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER0TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER0TRIG_INP_SHIFT)) & INPUTMUX_CTIMER0TRIG_INP_MASK)
/*! @} */

/*! @name CTIMERB_CTIMER1CAP - Capture select register for CTIMER inputs */
/*! @{ */

#define INPUTMUX_CTIMERB_CTIMER1CAP_INP_MASK     (0x7FU)
#define INPUTMUX_CTIMERB_CTIMER1CAP_INP_SHIFT    (0U)
/*! INP - Input number for CTIMER1
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..Reserved
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..Reserved
 *  0b0001100..Reserved
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..Reserved
 *  0b0010000..Reserved
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..Reserved
 *  0b0010111..Reserved
 *  0b0011000..Reserved
 *  0b0011001..Reserved
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..Reserved
 *  0b0100101..Reserved
 *  0b0100110..Reserved
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..Reserved
 *  0b0110011..Reserved
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..Reserved
 *  0b1010001..Reserved
 *  0b1010010..Reserved
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMERB_CTIMER1CAP_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMERB_CTIMER1CAP_INP_SHIFT)) & INPUTMUX_CTIMERB_CTIMER1CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMERB_CTIMER1CAP */
#define INPUTMUX_CTIMERB_CTIMER1CAP_COUNT        (4U)

/*! @name CTIMER1TRIG - Trigger register for CTIMER1 */
/*! @{ */

#define INPUTMUX_CTIMER1TRIG_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER1TRIG_INP_SHIFT           (0U)
/*! INP - Input number for CTIMER1
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..Reserved
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..Reserved
 *  0b0001100..Reserved
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..Reserved
 *  0b0010000..Reserved
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..Reserved
 *  0b0010111..Reserved
 *  0b0011000..Reserved
 *  0b0011001..Reserved
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..Reserved
 *  0b0100101..Reserved
 *  0b0100110..Reserved
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..Reserved
 *  0b0110011..Reserved
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..Reserved
 *  0b1010001..Reserved
 *  0b1010010..Reserved
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER1TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER1TRIG_INP_SHIFT)) & INPUTMUX_CTIMER1TRIG_INP_MASK)
/*! @} */

/*! @name FREQMEAS_REF - Selection for frequency measurement reference clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_REF_INP_MASK           (0x3FU)
#define INPUTMUX_FREQMEAS_REF_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function target clock.
 *  0b000000..Reserved
 *  0b000001..clk_in input is selected
 *  0b000010..FRO_OSC_12M input is selected
 *  0b000011..fro_hf_div input is selected
 *  0b000100..Osc32k[1] input is selected
 *  0b000101..clk_16k[1] input is selected
 *  0b000110..SLOW_CLK input is selected
 *  0b000111..FREQME_CLK_IN0 input is selected
 *  0b001000..FREQME_CLK_IN1 input is selected
 *  0b001001..Reserved
 *  0b001010..Reserved
 *  0b001011..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b001100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b001101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b001110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b001111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b010000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..CLK__iomux__IPP__scg__ipp_do_scg_clkout input is selected
 *  0b010100..Reserved
 *  0b010101..spc_pmc_bg_refresh_1p8v input is selected
 *  0b010110..reserverd input is selected
 *  0b010111..spc_pmc_timer_clk_1p8v input is selected
 *  0b011000..spc_pmc_tst_obs_bit_sfa_1p8v input is selected
 *  0b011001..spc_pmc_tst_obs_bit_sfa_1p8v[1] ^ spc_pmc_coreldo_tstctrl_testdelayin_sf input is selected
 *  0b011010..Reserved
 *  0b011011..reserverd(USB PLL 480M clock - div by 20 input is selected
 *  0b011100..VBAT OSC32K test trigger input is selected
 *  0b011101..VBAT OSC32K test clock input is selected
 *  0b011110..reserverd input is selected
 *  0b011111..reserverd input is selected
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..Reserved
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 */
#define INPUTMUX_FREQMEAS_REF_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_REF_INP_SHIFT)) & INPUTMUX_FREQMEAS_REF_INP_MASK)
/*! @} */

/*! @name FREQMEAS_TAR - Selection for frequency measurement target clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_TAR_INP_MASK           (0x3FU)
#define INPUTMUX_FREQMEAS_TAR_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function target clock.
 *  0b000000..Reserved
 *  0b000001..clk_in input is selected
 *  0b000010..FRO_OSC_12M input is selected
 *  0b000011..fro_hf_div input is selected
 *  0b000100..Osc32k[1] input is selected
 *  0b000101..clk_16k[1] input is selected
 *  0b000110..SLOW_CLK input is selected
 *  0b000111..FREQME_CLK_IN0 input is selected
 *  0b001000..FREQME_CLK_IN1 input is selected
 *  0b001001..Reserved
 *  0b001010..Reserved
 *  0b001011..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b001100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b001101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b001110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b001111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b010000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..CLK__iomux__IPP__scg__ipp_do_scg_clkout input is selected
 *  0b010100..Reserved
 *  0b010101..spc_pmc_bg_refresh_1p8v input is selected
 *  0b010110..reserverd input is selected
 *  0b010111..spc_pmc_timer_clk_1p8v input is selected
 *  0b011000..spc_pmc_tst_obs_bit_sfa_1p8v input is selected
 *  0b011001..spc_pmc_tst_obs_bit_sfa_1p8v[1] ^ spc_pmc_coreldo_tstctrl_testdelayin_sf input is selected
 *  0b011010..Reserved
 *  0b011011..reserverd(USB PLL 480M clock - div by 20 input is selected
 *  0b011100..VBAT OSC32K test trigger input is selected
 *  0b011101..VBAT OSC32K test clock input is selected
 *  0b011110..reserverd input is selected
 *  0b011111..reserverd input is selected
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..Reserved
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 */
#define INPUTMUX_FREQMEAS_TAR_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_TAR_INP_SHIFT)) & INPUTMUX_FREQMEAS_TAR_INP_MASK)
/*! @} */

/*! @name CMP0_TRIG - CMP0 input connections */
/*! @{ */

#define INPUTMUX_CMP0_TRIG_TRIGIN_MASK           (0x1FU)
#define INPUTMUX_CMP0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - CMP0 input trigger
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..Reserved
 *  0b00011..Reserved
 *  0b00100..Reserved
 *  0b00101..Reserved
 *  0b00110..Reserved
 *  0b00111..Reserved
 *  0b01000..CTimer0_MAT0 input is selected
 *  0b01001..CTimer0_MAT2 input is selected
 *  0b01010..CTimer1_MAT0 input is selected
 *  0b01011..CTimer1_MAT2 input is selected
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..LPTMR0 input is selected
 *  0b01111..Reserved
 *  0b10000..Reserved
 *  0b10001..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b10010..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b10011..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b10100..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b10101..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b10110..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b10111..Reserved
 *  0b11000..Reserved
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_CMP0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CMP0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_CMP0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ADC0_TRIGM_ADC0_TRIG - ADC Trigger input connections */
/*! @{ */

#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_MASK (0x1FU)
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC0 trigger inputs
 *  0b00000..Reserved
 *  0b00001..ARM_TXEV input is selected
 *  0b00010..Reserved
 *  0b00011..Reserved
 *  0b00100..Reserved
 *  0b00101..Reserved
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT0 input is selected
 *  0b01010..CTimer0_MAT1 input is selected
 *  0b01011..CTimer1_MAT0 input is selected
 *  0b01100..CTimer1_MAT1 input is selected
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..Reserved
 *  0b10010..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b10011..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b10100..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b10101..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b10110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b10111..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b11000..Reserved
 *  0b11001..Reserved
 *  0b11010..GPIO0 Pin Event Trig 0 input is selected
 *  0b11011..GPIO1 Pin Event Trig 0 input is selected
 *  0b11100..GPIO2 Pin Event Trig 0 input is selected
 *  0b11101..GPIO3 Pin Event Trig 0 input is selected
 *  0b11110..Reserved
 *  0b11111..WUU input is selected
 */
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC0_TRIGM_ADC0_TRIG */
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_COUNT      (4U)

/*! @name FLEXPWM0_SM0_EXTA0 - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_MASK  (0x3FU)
#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM0_EXTSYNC - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM1_EXTA - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM1_EXTSYNC - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM2_EXTA - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM2_EXTSYNC - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT0 - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_FAULT0_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT1 - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_FAULT1_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT2 - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_FAULT2_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT3 - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_FAULT3_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FORCE - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN_SHIFT     (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FORCE_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FORCE_TRIGIN_MASK)
/*! @} */

/*! @name PWM0_EXT_CLK - PWM0 external clock trigger */
/*! @{ */

#define INPUTMUX_PWM0_EXT_CLK_INP_MASK           (0x7U)
#define INPUTMUX_PWM0_EXT_CLK_INP_SHIFT          (0U)
/*! INP - Trigger input connections for PWM
 *  0b000..Reserved
 *  0b001..clk_16k[1] input is selected
 *  0b010..clk_in input is selected
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..TRIG_IN0 input is selected
 *  0b110..TRIG_IN7 input is selected
 *  0b111..Reserved
 */
#define INPUTMUX_PWM0_EXT_CLK_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXT_CLK_INP_SHIFT)) & INPUTMUX_PWM0_EXT_CLK_INP_MASK)
/*! @} */

/*! @name EXT_TRIGA_EXT_TRIG - EXT trigger connections 0-4 */
/*! @{ */

#define INPUTMUX_EXT_TRIGA_EXT_TRIG_INP_MASK     (0x1FU)
#define INPUTMUX_EXT_TRIGA_EXT_TRIG_INP_SHIFT    (0U)
/*! INP - EXT trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..Reserved
 *  0b00011..Reserved
 *  0b00100..Reserved
 *  0b00101..Reserved
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..LPUART0 ipp_do_lpuart_txd input is selected
 *  0b01010..LPUART1 ipp_do_lpuart_txd input is selected
 *  0b01011..LPUART2 ipp_do_lpuart_txd input is selected
 *  0b01100..LPUART3 ipp_do_lpuart_txd input is selected
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b10000..Reserved
 *  0b10001..Reserved
 *  0b10010..Reserved
 *  0b10011..RTC_1Hz_CLK input is selected
 */
#define INPUTMUX_EXT_TRIGA_EXT_TRIG_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_EXT_TRIGA_EXT_TRIG_INP_SHIFT)) & INPUTMUX_EXT_TRIGA_EXT_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_EXT_TRIGA_EXT_TRIG */
#define INPUTMUX_EXT_TRIGA_EXT_TRIG_COUNT        (5U)

/*! @name EXT_TRIGB - EXT trigger connections 6-7 */
/*! @{ */

#define INPUTMUX_EXT_TRIGB_INP_MASK              (0x1FU)
#define INPUTMUX_EXT_TRIGB_INP_SHIFT             (0U)
/*! INP - EXT trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..Reserved
 *  0b00011..Reserved
 *  0b00100..Reserved
 *  0b00101..Reserved
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..LPUART0 ipp_do_lpuart_txd input is selected
 *  0b01010..LPUART1 ipp_do_lpuart_txd input is selected
 *  0b01011..LPUART2 ipp_do_lpuart_txd input is selected
 *  0b01100..LPUART3 ipp_do_lpuart_txd input is selected
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b10000..Reserved
 *  0b10001..Reserved
 *  0b10010..Reserved
 *  0b10011..RTC_1Hz_CLK input is selected
 */
#define INPUTMUX_EXT_TRIGB_INP(x)                (((uint32_t)(((uint32_t)(x)) << INPUTMUX_EXT_TRIGB_INP_SHIFT)) & INPUTMUX_EXT_TRIGB_INP_MASK)
/*! @} */

/*! @name LPI2C0_TRIG - LPI2C0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C0_TRIG_INP_MASK            (0x1FU)
#define INPUTMUX_LPI2C0_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C0 trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..Reserved
 *  0b00011..Reserved
 *  0b00100..Reserved
 *  0b00101..Reserved
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT0 input is selected
 *  0b01010..CTimer0_MAT1 input is selected
 *  0b01011..CTimer1_MAT0 input is selected
 *  0b01100..CTimer1_MAT1 input is selected
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..TRIG_IN0 input is selected
 *  0b10010..TRIG_IN1 input is selected
 *  0b10011..TRIG_IN2 input is selected
 *  0b10100..TRIG_IN3 input is selected
 *  0b10101..TRIG_IN4 input is selected
 *  0b10110..TRIG_IN5 input is selected
 *  0b10111..TRIG_IN6 input is selected
 *  0b11000..TRIG_IN7 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPI2C0_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C0_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C0_TRIG_INP_MASK)
/*! @} */

/*! @name LPSPI0_TRIG - LPSPI0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPSPI0_TRIG_INP_MASK            (0x1FU)
#define INPUTMUX_LPSPI0_TRIG_INP_SHIFT           (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..Reserved
 *  0b00011..Reserved
 *  0b00100..Reserved
 *  0b00101..Reserved
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT1 input is selected
 *  0b01010..CTimer0_MAT2 input is selected
 *  0b01011..CTimer1_MAT1 input is selected
 *  0b01100..CTimer1_MAT2 input is selected
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..TRIG_IN0 input is selected
 *  0b10010..TRIG_IN1 input is selected
 *  0b10011..TRIG_IN2 input is selected
 *  0b10100..TRIG_IN3 input is selected
 *  0b10101..TRIG_IN4 input is selected
 *  0b10110..TRIG_IN5 input is selected
 *  0b10111..TRIG_IN6 input is selected
 *  0b11000..TRIG_IN7 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPSPI0_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPSPI0_TRIG_INP_SHIFT)) & INPUTMUX_LPSPI0_TRIG_INP_MASK)
/*! @} */

/*! @name LPUART0 - LPUART0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART0_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART0_INP_SHIFT               (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART0_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART0_INP_SHIFT)) & INPUTMUX_LPUART0_INP_MASK)
/*! @} */

/*! @name LPUART1 - LPUART1 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART1_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART1_INP_SHIFT               (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART1_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART1_INP_SHIFT)) & INPUTMUX_LPUART1_INP_MASK)
/*! @} */

/*! @name LPUART2 - LPUART2 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART2_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART2_INP_SHIFT               (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART2_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART2_INP_SHIFT)) & INPUTMUX_LPUART2_INP_MASK)
/*! @} */

/*! @name LPUART3 - LPUART3 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART3_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART3_INP_SHIFT               (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..Reserved
 *  0b000011..Reserved
 *  0b000100..Reserved
 *  0b000101..Reserved
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..Reserved
 *  0b001110..Reserved
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART3_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART3_INP_SHIFT)) & INPUTMUX_LPUART3_INP_MASK)
/*! @} */

/*! @name TRIGFIL_PRSC - Trigger filter prescaller */
/*! @{ */

#define INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_VAL_MASK (0x3U)
#define INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_VAL_SHIFT (0U)
/*! FILT_SCALE_VAL - Filter Prescaller Value
 *  0b00..Bypass the clock
 *  0b01..Divide 2
 *  0b10..Divide 4
 *  0b11..Divide 8
 */
#define INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_VAL(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_VAL_SHIFT)) & INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_VAL_MASK)

#define INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_EN_MASK (0x80000000U)
#define INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_EN_SHIFT (31U)
/*! FILT_SCALE_EN - Enable trigger filter prescaller
 *  0b0..Disable prescaller
 *  0b1..Enabled prescaller
 */
#define INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_EN(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_EN_SHIFT)) & INPUTMUX_TRIGFIL_PRSC_FILT_SCALE_EN_MASK)
/*! @} */

/*! @name TRIGFIL_STAT0 - Trigger filter stat */
/*! @{ */

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN0_VAL_MASK (0x1U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN0_VAL_SHIFT (0U)
/*! TRIG_IN0_VAL - TRIG_IN value
 *  0b0..TRIG_IN0 is 0
 *  0b1..TRIG_IN0 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN0_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN0_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN0_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN1_VAL_MASK (0x2U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN1_VAL_SHIFT (1U)
/*! TRIG_IN1_VAL - TRIG_IN value
 *  0b0..TRIG_IN1 is 0
 *  0b1..TRIG_IN1 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN1_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN1_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN1_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN2_VAL_MASK (0x4U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN2_VAL_SHIFT (2U)
/*! TRIG_IN2_VAL - TRIG_IN value
 *  0b0..TRIG_IN2 is 0
 *  0b1..TRIG_IN2 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN2_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN2_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN2_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN3_VAL_MASK (0x8U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN3_VAL_SHIFT (3U)
/*! TRIG_IN3_VAL - TRIG_IN value
 *  0b0..TRIG_IN3 is 0
 *  0b1..TRIG_IN3 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN3_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN3_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN3_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN4_VAL_MASK (0x10U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN4_VAL_SHIFT (4U)
/*! TRIG_IN4_VAL - TRIG_IN value
 *  0b0..TRIG_IN4 is 0
 *  0b1..TRIG_IN4 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN4_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN4_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN4_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN5_VAL_MASK (0x20U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN5_VAL_SHIFT (5U)
/*! TRIG_IN5_VAL - TRIG_IN value
 *  0b0..TRIG_IN5 is 0
 *  0b1..TRIG_IN5 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN5_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN5_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN5_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN6_VAL_MASK (0x40U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN6_VAL_SHIFT (6U)
/*! TRIG_IN6_VAL - TRIG_IN value
 *  0b0..TRIG_IN6 is 0
 *  0b1..TRIG_IN6 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN6_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN6_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN6_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN7_VAL_MASK (0x80U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN7_VAL_SHIFT (7U)
/*! TRIG_IN7_VAL - TRIG_IN value
 *  0b0..TRIG_IN7 is 0
 *  0b1..TRIG_IN7 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN7_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN7_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN7_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN8_VAL_MASK (0x100U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN8_VAL_SHIFT (8U)
/*! TRIG_IN8_VAL - TRIG_IN value
 *  0b0..TRIG_IN8 is 0
 *  0b1..TRIG_IN8 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN8_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN8_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN8_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN9_VAL_MASK (0x200U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN9_VAL_SHIFT (9U)
/*! TRIG_IN9_VAL - TRIG_IN value
 *  0b0..TRIG_IN9 is 0
 *  0b1..TRIG_IN9 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN9_VAL(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN9_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN9_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN10_VAL_MASK (0x400U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN10_VAL_SHIFT (10U)
/*! TRIG_IN10_VAL - TRIG_IN value
 *  0b0..TRIG_IN10 is 0
 *  0b1..TRIG_IN10 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN10_VAL(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN10_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN10_VAL_MASK)

#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN11_VAL_MASK (0x800U)
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN11_VAL_SHIFT (11U)
/*! TRIG_IN11_VAL - TRIG_IN value
 *  0b0..TRIG_IN11 is 0
 *  0b1..TRIG_IN11 is 1
 */
#define INPUTMUX_TRIGFIL_STAT0_TRIG_IN11_VAL(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFIL_STAT0_TRIG_IN11_VAL_SHIFT)) & INPUTMUX_TRIGFIL_STAT0_TRIG_IN11_VAL_MASK)
/*! @} */

/*! @name TRIGFILP_TRIGFIL - TRIGFIL control */
/*! @{ */

#define INPUTMUX_TRIGFILP_TRIGFIL_FILT_PER_MASK  (0xFFU)
#define INPUTMUX_TRIGFILP_TRIGFIL_FILT_PER_SHIFT (0U)
/*! FILT_PER - Input Filter Sample Period */
#define INPUTMUX_TRIGFILP_TRIGFIL_FILT_PER(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFILP_TRIGFIL_FILT_PER_SHIFT)) & INPUTMUX_TRIGFILP_TRIGFIL_FILT_PER_MASK)

#define INPUTMUX_TRIGFILP_TRIGFIL_FILT_CNT_MASK  (0x700U)
#define INPUTMUX_TRIGFILP_TRIGFIL_FILT_CNT_SHIFT (8U)
/*! FILT_CNT - Input Filter Sample Count */
#define INPUTMUX_TRIGFILP_TRIGFIL_FILT_CNT(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TRIGFILP_TRIGFIL_FILT_CNT_SHIFT)) & INPUTMUX_TRIGFILP_TRIGFIL_FILT_CNT_MASK)
/*! @} */

/* The count of INPUTMUX_TRIGFILP_TRIGFIL */
#define INPUTMUX_TRIGFILP_TRIGFIL_COUNT          (12U)


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

