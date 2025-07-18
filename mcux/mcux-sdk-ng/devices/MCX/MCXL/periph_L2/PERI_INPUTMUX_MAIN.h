/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INPUTMUX_MAIN
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_INPUTMUX_MAIN.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for INPUTMUX_MAIN
 *
 * CMSIS Peripheral Access Layer for INPUTMUX_MAIN
 */

#if !defined(PERI_INPUTMUX_MAIN_H_)
#define PERI_INPUTMUX_MAIN_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- INPUTMUX_MAIN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_MAIN_Peripheral_Access_Layer INPUTMUX_MAIN Peripheral Access Layer
 * @{
 */

/** INPUTMUX_MAIN - Size of Registers Arrays */
#define INPUTMUX_MAIN_CTIMERA_COUNT               4u
#define INPUTMUX_MAIN_CTIMERB_COUNT               4u
#define INPUTMUX_MAIN_CTIMERC_COUNT               4u
#define INPUTMUX_MAIN_ADC0_TRIGM_COUNT            4u
#define INPUTMUX_MAIN_AOI0_MUXK_COUNT             16u
#define INPUTMUX_MAIN_EXT_TRIGN_COUNT             8u

/** INPUTMUX_MAIN - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t CTIMER0CAP[INPUTMUX_MAIN_CTIMERA_COUNT]; /**< Capture select register for CTIMER0 inputs, array offset: 0x20, array step: 0x4 */
  __IO uint32_t CTIMER0TRIG;                       /**< Trigger register for CTIMER0, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CTIMER1CAP[INPUTMUX_MAIN_CTIMERB_COUNT]; /**< Capture select register for CTIMER1 inputs, array offset: 0x40, array step: 0x4 */
  __IO uint32_t CTIMER1TRIG;                       /**< Trigger register for CTIMER1, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CTIMER2CAP[INPUTMUX_MAIN_CTIMERC_COUNT]; /**< Capture select register for CTIMER2 inputs, array offset: 0x60, array step: 0x4 */
  __IO uint32_t TIMER2TRIG;                        /**< Trigger register for CTIMER2 inputs, offset: 0x70 */
       uint8_t RESERVED_3[492];
  __IO uint32_t CMP0_TRIG;                         /**< CMP0 Input Connections, offset: 0x260 */
       uint8_t RESERVED_4[28];
  __IO uint32_t ADC0_TRIG[INPUTMUX_MAIN_ADC0_TRIGM_COUNT]; /**< ADC Trigger Input Connections, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_5[432];
  __IO uint32_t AOI0_MUX[INPUTMUX_MAIN_AOI0_MUXK_COUNT]; /**< AOI0 Trigger Input Connections, array offset: 0x440, array step: 0x4 */
       uint8_t RESERVED_6[64];
  __IO uint32_t EXT_TRIG[INPUTMUX_MAIN_EXT_TRIGN_COUNT]; /**< EXT Trigger Connections, array offset: 0x4C0, array step: 0x4 */
       uint8_t RESERVED_7[192];
  __IO uint32_t LPI2C0_TRIG;                       /**< LPI2C0 Trigger Input Connections, offset: 0x5A0 */
       uint8_t RESERVED_8[28];
  __IO uint32_t LPI2C1_TRIG;                       /**< LPI2C1 Trigger Input Connections, offset: 0x5C0 */
       uint8_t RESERVED_9[28];
  __IO uint32_t LPSPI0_TRIG;                       /**< LPSPI0 Trigger Input Connections, offset: 0x5E0 */
       uint8_t RESERVED_10[28];
  __IO uint32_t LPSPI1_TRIG;                       /**< LPSPI1 Trigger Input Connections, offset: 0x600 */
       uint8_t RESERVED_11[28];
  __IO uint32_t LPUART0r;                          /**< LPUART0 Trigger Input Connections, offset: 0x620, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART0' */
       uint8_t RESERVED_12[28];
  __IO uint32_t LPUART1r;                          /**< LPUART1 Trigger Input Connections, offset: 0x640, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART1' */
} INPUTMUX_MAIN_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX_MAIN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_MAIN_Register_Masks INPUTMUX_MAIN Register Masks
 * @{
 */

/*! @name CTIMER0CAP - Capture select register for CTIMER0 inputs */
/*! @{ */

#define INPUTMUX_MAIN_CTIMER0CAP_INP_MASK        (0x7FU)
#define INPUTMUX_MAIN_CTIMER0CAP_INP_SHIFT       (0U)
/*! INP - Input number for CTIMER0
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTIMER1_MAT1 input is selected
 *  0b0100010..CTIMER1_MAT2 input is selected
 *  0b0100011..CTIMER1_MAT3 input is selected
 *  0b0100100..CTIMER2_MAT1 input is selected
 *  0b0100101..CTIMER2_MAT2 input is selected
 *  0b0100110..CTIMER2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..Reserved
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Controller End of Packet input is selected
 *  0b0110001..LPI2C0 Target End of Packet input is selected
 *  0b0110010..LPI2C1 Controller End of Packet input is selected
 *  0b0110011..LPI2C1 Target End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..Reserved
 *  0b0111111..Reserved
 *  0b1000000..Reserved
 */
#define INPUTMUX_MAIN_CTIMER0CAP_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_CTIMER0CAP_INP_SHIFT)) & INPUTMUX_MAIN_CTIMER0CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_MAIN_CTIMER0CAP */
#define INPUTMUX_MAIN_CTIMER0CAP_COUNT           (4U)

/*! @name CTIMER0TRIG - Trigger register for CTIMER0 */
/*! @{ */

#define INPUTMUX_MAIN_CTIMER0TRIG_INP_MASK       (0x7FU)
#define INPUTMUX_MAIN_CTIMER0TRIG_INP_SHIFT      (0U)
/*! INP - Input number for CTIMER0
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTIMER1_MAT1 input is selected
 *  0b0100010..CTIMER1_MAT2 input is selected
 *  0b0100011..CTIMER1_MAT3 input is selected
 *  0b0100100..CTIMER2_MAT1 input is selected
 *  0b0100101..CTIMER2_MAT2 input is selected
 *  0b0100110..CTIMER2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..Reserved
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Controller End of Packet input is selected
 *  0b0110001..LPI2C0 Target End of Packet input is selected
 *  0b0110010..LPI2C1 Controller End of Packet input is selected
 *  0b0110011..LPI2C1 Target End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..Reserved
 *  0b0111111..Reserved
 *  0b1000000..Reserved
 */
#define INPUTMUX_MAIN_CTIMER0TRIG_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_CTIMER0TRIG_INP_SHIFT)) & INPUTMUX_MAIN_CTIMER0TRIG_INP_MASK)
/*! @} */

/*! @name CTIMER1CAP - Capture select register for CTIMER1 inputs */
/*! @{ */

#define INPUTMUX_MAIN_CTIMER1CAP_INP_MASK        (0x7FU)
#define INPUTMUX_MAIN_CTIMER1CAP_INP_SHIFT       (0U)
/*! INP - Input number for CTIMER1
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..Reserved
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTIMER0_MAT1 input is selected
 *  0b0100010..CTIMER0_MAT2 input is selected
 *  0b0100011..CTIMER0_MAT3 input is selected
 *  0b0100100..CTIMER2_MAT1 input is selected
 *  0b0100101..CTIMER2_MAT2 input is selected
 *  0b0100110..CTIMER2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..Reserved
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Controller End of Packet input is selected
 *  0b0110001..LPI2C0 Target End of Packet input is selected
 *  0b0110010..LPI2C1 Controller End of Packet input is selected
 *  0b0110011..LPI2C1 Target End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..Reserved
 *  0b0111111..Reserved
 *  0b1000000..Reserved
 */
#define INPUTMUX_MAIN_CTIMER1CAP_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_CTIMER1CAP_INP_SHIFT)) & INPUTMUX_MAIN_CTIMER1CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_MAIN_CTIMER1CAP */
#define INPUTMUX_MAIN_CTIMER1CAP_COUNT           (4U)

/*! @name CTIMER1TRIG - Trigger register for CTIMER1 */
/*! @{ */

#define INPUTMUX_MAIN_CTIMER1TRIG_INP_MASK       (0x7FU)
#define INPUTMUX_MAIN_CTIMER1TRIG_INP_SHIFT      (0U)
/*! INP - Input number for CTIMER1
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..Reserved
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTIMER0_MAT1 input is selected
 *  0b0100010..CTIMER0_MAT2 input is selected
 *  0b0100011..CTIMER0_MAT3 input is selected
 *  0b0100100..CTIMER2_MAT1 input is selected
 *  0b0100101..CTIMER2_MAT2 input is selected
 *  0b0100110..CTIMER2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..Reserved
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Controller End of Packet input is selected
 *  0b0110001..LPI2C0 Target End of Packet input is selected
 *  0b0110010..LPI2C1 Controller End of Packet input is selected
 *  0b0110011..LPI2C1 Target End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..Reserved
 *  0b0111111..Reserved
 *  0b1000000..Reserved
 */
#define INPUTMUX_MAIN_CTIMER1TRIG_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_CTIMER1TRIG_INP_SHIFT)) & INPUTMUX_MAIN_CTIMER1TRIG_INP_MASK)
/*! @} */

/*! @name CTIMER2CAP - Capture select register for CTIMER2 inputs */
/*! @{ */

#define INPUTMUX_MAIN_CTIMER2CAP_INP_MASK        (0x7FU)
#define INPUTMUX_MAIN_CTIMER2CAP_INP_SHIFT       (0U)
/*! INP - Input number for CTIMER2
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..Reserved
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTIMER0_MAT1 input is selected
 *  0b0100010..CTIMER0_MAT2 input is selected
 *  0b0100011..CTIMER0_MAT3 input is selected
 *  0b0100100..CTIMER1_MAT1 input is selected
 *  0b0100101..CTIMER1_MAT2 input is selected
 *  0b0100110..CTIMER1_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..Reserved
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Controller End of Packet input is selected
 *  0b0110001..LPI2C0 Target End of Packet input is selected
 *  0b0110010..LPI2C1 Controller End of Packet input is selected
 *  0b0110011..LPI2C1 Target End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..Reserved
 *  0b0111111..Reserved
 *  0b1000000..Reserved
 */
#define INPUTMUX_MAIN_CTIMER2CAP_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_CTIMER2CAP_INP_SHIFT)) & INPUTMUX_MAIN_CTIMER2CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_MAIN_CTIMER2CAP */
#define INPUTMUX_MAIN_CTIMER2CAP_COUNT           (4U)

/*! @name TIMER2TRIG - Trigger register for CTIMER2 inputs */
/*! @{ */

#define INPUTMUX_MAIN_TIMER2TRIG_INP_MASK        (0x7FU)
#define INPUTMUX_MAIN_TIMER2TRIG_INP_SHIFT       (0U)
/*! INP - Input number for CTIMER2
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..Reserved
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..Reserved
 *  0b0100000..Reserved
 *  0b0100001..CTIMER0_MAT1 input is selected
 *  0b0100010..CTIMER0_MAT2 input is selected
 *  0b0100011..CTIMER0_MAT3 input is selected
 *  0b0100100..CTIMER1_MAT1 input is selected
 *  0b0100101..CTIMER1_MAT2 input is selected
 *  0b0100110..CTIMER1_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..Reserved
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..LPI2C0 Controller End of Packet input is selected
 *  0b0110001..LPI2C0 Target End of Packet input is selected
 *  0b0110010..LPI2C1 Controller End of Packet input is selected
 *  0b0110011..LPI2C1 Target End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..Reserved
 *  0b0111111..Reserved
 *  0b1000000..Reserved
 */
#define INPUTMUX_MAIN_TIMER2TRIG_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_TIMER2TRIG_INP_SHIFT)) & INPUTMUX_MAIN_TIMER2TRIG_INP_MASK)
/*! @} */

/*! @name CMP0_TRIG - CMP0 Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_CMP0_TRIG_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_MAIN_CMP0_TRIG_TRIGIN_SHIFT     (0U)
/*! TRIGIN - CMP0 input trigger
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..Reserved
 *  0b000111..Reserved
 *  0b001000..CTIMER0_MAT0 input is selected
 *  0b001001..CTIMER0_MAT2 input is selected
 *  0b001010..CTIMER1_MAT0
 *  0b001011..CTIMER1_MAT2 input is selected
 *  0b001100..CTIMER2_MAT0 input is selected
 *  0b001101..CTIMER2_MAT2 input is selected
 *  0b001110..Reserved
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Reserved
 *  0b010110..Reserved
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..Reserved
 *  0b011110..WUU input is selected
 */
#define INPUTMUX_MAIN_CMP0_TRIG_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_CMP0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_MAIN_CMP0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ADC0_TRIG - ADC Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_ADC0_TRIG_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_MAIN_ADC0_TRIG_TRIGIN_SHIFT     (0U)
/*! TRIGIN - ADC0 trigger inputs
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTIMER0_MAT0 input is selected
 *  0b001010..CTIMER0_MAT1 input is selected
 *  0b001011..CTIMER1_MAT0 input is selected
 *  0b001100..CTIMER1_MAT1 input is selected
 *  0b001101..CTIMER2_MAT0 input is selected
 *  0b001110..CTIMER2_MAT1 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..Reserved
 *  0b010101..Reserved
 *  0b010110..Reserved
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..GPIO1 Pin Event Trig 0 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO3 Pin Event Trig 0 input is selected
 *  0b011110..Reserved
 *  0b011111..WUU
 */
#define INPUTMUX_MAIN_ADC0_TRIG_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_ADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_MAIN_ADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_MAIN_ADC0_TRIG */
#define INPUTMUX_MAIN_ADC0_TRIG_COUNT            (4U)

/*! @name AOI0_MUX - AOI0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_AOI0_MUX_INP_MASK          (0x3FU)
#define INPUTMUX_MAIN_AOI0_MUX_INP_SHIFT         (0U)
/*! INP - AOI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ADC0_tcomp[0] input is selected
 *  0b000010..ADC0_tcomp[1] input is selected
 *  0b000011..ADC0_tcomp[2] input is selected
 *  0b000100..ADC0_tcomp[3] input is selected
 *  0b000101..CMP0_OUT input is selected
 *  0b000110..Reserved
 *  0b000111..Reserved
 *  0b001000..CTIMER0_MAT0 input is selected
 *  0b001001..CTIMER0_MAT1 input is selected
 *  0b001010..CTIMER0_MAT2 input is selected
 *  0b001011..CTIMER0_MAT3 input is selected
 *  0b001100..CTIMER1_MAT0 input is selected
 *  0b001101..CTIMER1_MAT1 input is selected
 *  0b001110..CTIMER1_MAT2 input is selected
 *  0b001111..CTIMER1_MAT3 input is selected
 *  0b010000..CTIMER2_MAT0 input is selected
 *  0b010001..CTIMER2_MAT1 input is selected
 *  0b010010..CTIMER2_MAT2 input is selected
 *  0b010011..CTIMER2_MAT3 input is selected
 *  0b010100..Reserved
 *  0b010101..Reserved
 *  0b010110..Reserved
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..Reserved
 *  0b011100..Reserved
 *  0b011101..Reserved
 *  0b011110..Reserved
 *  0b011111..Reserved
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..Reserved
 *  0b100011..TRIG_IN0 input is selected
 *  0b100100..TRIG_IN1 input is selected
 *  0b100101..TRIG_IN2 input is selected
 *  0b100110..TRIG_IN3 input is selected
 *  0b100111..TRIG_IN4 input is selected
 *  0b101000..TRIG_IN5 input is selected
 *  0b101001..TRIG_IN6 input is selected
 *  0b101010..TRIG_IN7 input is selected
 *  0b101011..TRIG_IN8 input is selected
 *  0b101100..TRIG_IN9 input is selected
 *  0b101101..TRIG_IN10 input is selected
 *  0b101110..TRIG_IN11 input is selected
 *  0b101111..Reserved
 *  0b110000..GPIO1 Pin Event Trig 0 input is selected
 *  0b110001..GPIO2 Pin Event Trig 0 input is selected
 *  0b110010..GPIO3 Pin Event Trig 0 input is selected
 */
#define INPUTMUX_MAIN_AOI0_MUX_INP(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_AOI0_MUX_INP_SHIFT)) & INPUTMUX_MAIN_AOI0_MUX_INP_MASK)
/*! @} */

/* The count of INPUTMUX_MAIN_AOI0_MUX */
#define INPUTMUX_MAIN_AOI0_MUX_COUNT             (16U)

/*! @name EXT_TRIG - EXT Trigger Connections */
/*! @{ */

#define INPUTMUX_MAIN_EXT_TRIG_INP_MASK          (0x1FU)
#define INPUTMUX_MAIN_EXT_TRIG_INP_SHIFT         (0U)
/*! INP - EXT trigger input connections
 *  0b00000..Reserved
 *  0b00001..ARM_TXEV input is selected
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..LPUART0 input is selected
 *  0b01010..LPUART1 input is selected
 *  0b01011..Reserved
 */
#define INPUTMUX_MAIN_EXT_TRIG_INP(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_EXT_TRIG_INP_SHIFT)) & INPUTMUX_MAIN_EXT_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_MAIN_EXT_TRIG */
#define INPUTMUX_MAIN_EXT_TRIG_COUNT             (8U)

/*! @name LPI2C0_TRIG - LPI2C0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_LPI2C0_TRIG_INP_MASK       (0x3FU)
#define INPUTMUX_MAIN_LPI2C0_TRIG_INP_SHIFT      (0U)
/*! INP - LPI2C0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTIMER0_MAT0 input is selected
 *  0b001010..CTIMER0_MAT1 input is selected
 *  0b001011..CTIMER1_MAT0 input is selected
 *  0b001100..CTIMER1_MAT1 input is selected
 *  0b001101..CTIMER2_MAT0 input is selected
 *  0b001110..CTIMER2_MAT1 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..Reserved
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO1 Pin Event Trig 0 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..Reserved
 *  0b011110..WUU input is selected
 */
#define INPUTMUX_MAIN_LPI2C0_TRIG_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_LPI2C0_TRIG_INP_SHIFT)) & INPUTMUX_MAIN_LPI2C0_TRIG_INP_MASK)
/*! @} */

/*! @name LPI2C1_TRIG - LPI2C1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_LPI2C1_TRIG_INP_MASK       (0x3FU)
#define INPUTMUX_MAIN_LPI2C1_TRIG_INP_SHIFT      (0U)
/*! INP - LPI2C1 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTIMER0_MAT0 input is selected
 *  0b001010..CTIMER0_MAT1 input is selected
 *  0b001011..CTIMER1_MAT0 input is selected
 *  0b001100..CTIMER1_MAT1 input is selected
 *  0b001101..CTIMER2_MAT0 input is selected
 *  0b001110..CTIMER2_MAT1 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..Reserved
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..Reserved
 *  0b011110..WUU input is selected
 */
#define INPUTMUX_MAIN_LPI2C1_TRIG_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_LPI2C1_TRIG_INP_SHIFT)) & INPUTMUX_MAIN_LPI2C1_TRIG_INP_MASK)
/*! @} */

/*! @name LPSPI0_TRIG - LPSPI0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_LPSPI0_TRIG_INP_MASK       (0x3FU)
#define INPUTMUX_MAIN_LPSPI0_TRIG_INP_SHIFT      (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTIMER0_MAT1 input is selected
 *  0b001010..CTIMER0_MAT2 input is selected
 *  0b001011..CTIMER1_MAT1 input is selected
 *  0b001100..CTIMER1_MAT2 input is selected
 *  0b001101..CTIMER2_MAT1 input is selected
 *  0b001110..CTIMER2_MAT2 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..Reserved
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..Reserved
 *  0b011110..WUU input is selected
 */
#define INPUTMUX_MAIN_LPSPI0_TRIG_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_LPSPI0_TRIG_INP_SHIFT)) & INPUTMUX_MAIN_LPSPI0_TRIG_INP_MASK)
/*! @} */

/*! @name LPSPI1_TRIG - LPSPI1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_LPSPI1_TRIG_INP_MASK       (0x3FU)
#define INPUTMUX_MAIN_LPSPI1_TRIG_INP_SHIFT      (0U)
/*! INP - LPSPI1 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTIMER0_MAT1 input is selected
 *  0b001010..CTIMER0_MAT2 input is selected
 *  0b001011..CTIMER1_MAT1 input is selected
 *  0b001100..CTIMER1_MAT2 input is selected
 *  0b001101..CTIMER2_MAT1 input is selected
 *  0b001110..CTIMER2_MAT2 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..Reserved
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..Reserved
 *  0b011110..WUU input is selected
 */
#define INPUTMUX_MAIN_LPSPI1_TRIG_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_LPSPI1_TRIG_INP_SHIFT)) & INPUTMUX_MAIN_LPSPI1_TRIG_INP_MASK)
/*! @} */

/*! @name LPUART0 - LPUART0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_LPUART0_INP_MASK           (0x3FU)
#define INPUTMUX_MAIN_LPUART0_INP_SHIFT          (0U)
/*! INP - LPUART0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTIMER0_MAT2 input is selected
 *  0b001010..CTIMER0_MAT3 input is selected
 *  0b001011..CTIMER1_MAT2 input is selected
 *  0b001100..CTIMER1_MAT3 input is selected
 *  0b001101..CTIMER2_MAT2 input is selected
 *  0b001110..CTIMER2_MAT3 input is selected
 *  0b001111..Reserved
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
 *  0b011101..Reserved
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU selected
 */
#define INPUTMUX_MAIN_LPUART0_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_LPUART0_INP_SHIFT)) & INPUTMUX_MAIN_LPUART0_INP_MASK)
/*! @} */

/*! @name LPUART1 - LPUART1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_MAIN_LPUART1_INP_MASK           (0x3FU)
#define INPUTMUX_MAIN_LPUART1_INP_SHIFT          (0U)
/*! INP - LPUART1 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTIMER0_MAT2 input is selected
 *  0b001010..CTIMER0_MAT3 input is selected
 *  0b001011..CTIMER1_MAT2 input is selected
 *  0b001100..CTIMER1_MAT3 input is selected
 *  0b001101..CTIMER2_MAT2 input is selected
 *  0b001110..CTIMER2_MAT3 input is selected
 *  0b001111..Reserved
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
 *  0b011101..Reserved
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU selected
 */
#define INPUTMUX_MAIN_LPUART1_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_MAIN_LPUART1_INP_SHIFT)) & INPUTMUX_MAIN_LPUART1_INP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INPUTMUX_MAIN_Register_Masks */


/*!
 * @}
 */ /* end of group INPUTMUX_MAIN_Peripheral_Access_Layer */


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


#endif  /* PERI_INPUTMUX_MAIN_H_ */

