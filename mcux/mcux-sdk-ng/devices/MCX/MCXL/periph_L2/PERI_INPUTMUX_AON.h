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
**         CMSIS Peripheral Access Layer for INPUTMUX_AON
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
 * @file PERI_INPUTMUX_AON.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for INPUTMUX_AON
 *
 * CMSIS Peripheral Access Layer for INPUTMUX_AON
 */

#if !defined(PERI_INPUTMUX_AON_H_)
#define PERI_INPUTMUX_AON_H_                     /**< Symbol preventing repeated inclusion */

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
   -- INPUTMUX_AON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_AON_Peripheral_Access_Layer INPUTMUX_AON Peripheral Access Layer
 * @{
 */

/** INPUTMUX_AON - Size of Registers Arrays */
#define INPUTMUX_AON_QTMRA_COUNT                  4u
#define INPUTMUX_AON_SOC_GLUE_XOR0_INA_COUNT      2u
#define INPUTMUX_AON_QTMRB_COUNT                  4u
#define INPUTMUX_AON_ACMP0_TRIGM_COUNT            4u
#define INPUTMUX_AON_LPADC0_TRIGM_COUNT           4u
#define INPUTMUX_AON_AON_TRIG_OUTN_COUNT          2u

/** INPUTMUX_AON - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[416];
  __IO uint32_t QTMR0_TMR[INPUTMUX_AON_QTMRA_COUNT]; /**< QTMR0 Input Connections, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t SOC_GLUE_XOR0_IN[INPUTMUX_AON_SOC_GLUE_XOR0_INA_COUNT]; /**< SOC_GLUE_XOR0 trigger input connections, array offset: 0x1B0, array step: 0x4 */
  __IO uint32_t SOC_GLUE_CMPPADS_PCTRL_XOR_IN0;    /**< SOC_GLUE_CMPPADS_PCTRL_XOR_IN0 trigger input connections, offset: 0x1B8 */
  __IO uint32_t SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0;   /**< SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0 trigger input connections, offset: 0x1BC */
  __IO uint32_t QTMR1_TMR[INPUTMUX_AON_QTMRB_COUNT]; /**< QTMR1 Input Connections, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t LC_ROT_SOC_LOGIC_IN;               /**< LC_ROT_SOC_LOGIC_IN trigger input connections, offset: 0x1D0 */
  __IO uint32_t LCSENSE_SEQ_PTRIG_GLUE_IN;         /**< LCSENSE_SEQ_PTRIG_GLUE_IN trigger input connections, offset: 0x1D4 */
  __IO uint32_t LCSENSE_SEQ_TICKS_GLUE_IN;         /**< LCSENSE_SEQ_TICKS_GLUE_IN trigger input connections, offset: 0x1D8 */
       uint8_t RESERVED_1[132];
  __IO uint32_t ACMP0_TRIG[INPUTMUX_AON_ACMP0_TRIGM_COUNT]; /**< ACMP0 Input Connections, array offset: 0x260, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __IO uint32_t LPADC0_TRIG[INPUTMUX_AON_LPADC0_TRIGM_COUNT]; /**< LPADC trigger input connections, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_3[560];
  __IO uint32_t AON_TRIG_OUT[INPUTMUX_AON_AON_TRIG_OUTN_COUNT]; /**< AON Trigger Output Connections, array offset: 0x4C0, array step: 0x4 */
       uint8_t RESERVED_4[24];
  __IO uint32_t CMP0_SAMPLE;                       /**< ACMP0 SAMPLE trigger input connections, offset: 0x4E0 */
  __IO uint32_t CMP0_RR_TRIG;                      /**< ACMP0 RR trigger input connections, offset: 0x4E4 */
       uint8_t RESERVED_5[184];
  __IO uint32_t LPI2C0_TRIG;                       /**< LPI2C0 trigger input connections, offset: 0x5A0 */
       uint8_t RESERVED_6[124];
  __IO uint32_t LPUART0r;                          /**< LPUART0 trigger input connections, offset: 0x620, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART0' */
} INPUTMUX_AON_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX_AON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_AON_Register_Masks INPUTMUX_AON Register Masks
 * @{
 */

/*! @name QTMR0_TMR - QTMR0 Input Connections */
/*! @{ */

#define INPUTMUX_AON_QTMR0_TMR_INP_MASK          (0x3FU)
#define INPUTMUX_AON_QTMR0_TMR_INP_SHIFT         (0U)
/*! INP - Input number for AON QTMR0
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_QTMR0_TMR_INP(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_QTMR0_TMR_INP_SHIFT)) & INPUTMUX_AON_QTMR0_TMR_INP_MASK)
/*! @} */

/* The count of INPUTMUX_AON_QTMR0_TMR */
#define INPUTMUX_AON_QTMR0_TMR_COUNT             (4U)

/*! @name SOC_GLUE_XOR0_IN - SOC_GLUE_XOR0 trigger input connections */
/*! @{ */

#define INPUTMUX_AON_SOC_GLUE_XOR0_IN_INP_MASK   (0x3FU)
#define INPUTMUX_AON_SOC_GLUE_XOR0_IN_INP_SHIFT  (0U)
/*! INP - Input number for SOC_GLUE_XOR0
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_SOC_GLUE_XOR0_IN_INP(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_SOC_GLUE_XOR0_IN_INP_SHIFT)) & INPUTMUX_AON_SOC_GLUE_XOR0_IN_INP_MASK)
/*! @} */

/* The count of INPUTMUX_AON_SOC_GLUE_XOR0_IN */
#define INPUTMUX_AON_SOC_GLUE_XOR0_IN_COUNT      (2U)

/*! @name SOC_GLUE_CMPPADS_PCTRL_XOR_IN0 - SOC_GLUE_CMPPADS_PCTRL_XOR_IN0 trigger input connections */
/*! @{ */

#define INPUTMUX_AON_SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_INP_MASK (0x3FU)
#define INPUTMUX_AON_SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_INP_SHIFT (0U)
/*! INP - Input number for SOC_GLUE_CMPPADS_PCTRL_XOR_IN0
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_INP_SHIFT)) & INPUTMUX_AON_SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_INP_MASK)
/*! @} */

/*! @name SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0 - SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0 trigger input connections */
/*! @{ */

#define INPUTMUX_AON_SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_INP_MASK (0x3FU)
#define INPUTMUX_AON_SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_INP_SHIFT (0U)
/*! INP - Input number for SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_INP_SHIFT)) & INPUTMUX_AON_SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_INP_MASK)
/*! @} */

/*! @name QTMR1_TMR - QTMR1 Input Connections */
/*! @{ */

#define INPUTMUX_AON_QTMR1_TMR_INP_MASK          (0x3FU)
#define INPUTMUX_AON_QTMR1_TMR_INP_SHIFT         (0U)
/*! INP - Input number for AON QTMR0
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_QTMR1_TMR_INP(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_QTMR1_TMR_INP_SHIFT)) & INPUTMUX_AON_QTMR1_TMR_INP_MASK)
/*! @} */

/* The count of INPUTMUX_AON_QTMR1_TMR */
#define INPUTMUX_AON_QTMR1_TMR_COUNT             (4U)

/*! @name LC_ROT_SOC_LOGIC_IN - LC_ROT_SOC_LOGIC_IN trigger input connections */
/*! @{ */

#define INPUTMUX_AON_LC_ROT_SOC_LOGIC_IN_INP_MASK (0x3FU)
#define INPUTMUX_AON_LC_ROT_SOC_LOGIC_IN_INP_SHIFT (0U)
/*! INP - Input number for LC_ROT_SOC_LOGIC_IN
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_LC_ROT_SOC_LOGIC_IN_INP(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_LC_ROT_SOC_LOGIC_IN_INP_SHIFT)) & INPUTMUX_AON_LC_ROT_SOC_LOGIC_IN_INP_MASK)
/*! @} */

/*! @name LCSENSE_SEQ_PTRIG_GLUE_IN - LCSENSE_SEQ_PTRIG_GLUE_IN trigger input connections */
/*! @{ */

#define INPUTMUX_AON_LCSENSE_SEQ_PTRIG_GLUE_IN_INP_MASK (0x3FU)
#define INPUTMUX_AON_LCSENSE_SEQ_PTRIG_GLUE_IN_INP_SHIFT (0U)
/*! INP - Input number for LCSENSE_SEQ_PTRIG_GLUE_IN
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_LCSENSE_SEQ_PTRIG_GLUE_IN_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_LCSENSE_SEQ_PTRIG_GLUE_IN_INP_SHIFT)) & INPUTMUX_AON_LCSENSE_SEQ_PTRIG_GLUE_IN_INP_MASK)
/*! @} */

/*! @name LCSENSE_SEQ_TICKS_GLUE_IN - LCSENSE_SEQ_TICKS_GLUE_IN trigger input connections */
/*! @{ */

#define INPUTMUX_AON_LCSENSE_SEQ_TICKS_GLUE_IN_INP_MASK (0x3FU)
#define INPUTMUX_AON_LCSENSE_SEQ_TICKS_GLUE_IN_INP_SHIFT (0U)
/*! INP - Input number for LCSENSE_SEQ_TICKS_GLUE_IN
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..QTMR1_tmr0_output is selected
 *  0b001011..QTMR1_tmr1_output is selected
 *  0b001100..QTMR1_tmr2_output is selected
 *  0b001101..QTMR1_tmr3_output is selected
 *  0b001110..CMP0_OUT is selected
 *  0b001111..Reserved
 *  0b010000..LPI2C0 Controller End of Packet is selected
 *  0b010001..LPI2C0 Target End of Packet is selected
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..LPUART0 Received Data Word is selected
 *  0b010101..LPUART0 Transmitted Data Word is selected
 *  0b010110..LPUART0 Receive Line Idle is selected
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..LPTMR0 output is selected
 *  0b011111..Reserved
 *  0b100000..LC_ROT_SOC_LOGIC_OUT1 is selected
 *  0b100001..LC_ROT_SOC_LOGIC_OUT2 is selected
 *  0b100010..LC_ROT_SOC_LOGIC_OUT3 is selected
 *  0b100011..LC_ROT_SOC_LOGIC_OUT4 is selected
 *  0b100100..QTMR0_tmr0_dir is selected
 *  0b100101..QTMR0_tmr1_dir is selected
 *  0b100110..QTMR0_tmr2_dir is selected
 *  0b100111..QTMR0_tmr3_dir is selected
 *  0b101000..QTMR1_tmr0_dir is selected
 *  0b101001..QTMR1_tmr1_dir is selected
 *  0b101010..QTMR1_tmr2_dir is selected
 *  0b101011..QTMR1_tmr3_dir is selected
 *  0b101100..ACMP0 raw analog comparator output is selected
 *  0b101101..ACMP0_AON_cout is selected
 *  0b101110..logic_0 is selected
 *  0b101111..logic_1 is selected
 *  0b110000..WUU output is selected
 *  0b110001..GPIO (AON) Pin Event Trig 0 input is selected
 *  0b110010..Reserved
 *  0b110011..soc_glue_XOR0_out is selected
 *  0b110100..Reserved
 *  0b110101..QTMR0_tmr0_output is selected
 *  0b110110..QTMR0_tmr1_output is selected
 *  0b110111..QTMR0_tmr2_output is selected
 *  0b111000..QTMR0_tmr3_output is selected
 *  0b111001..LCSense_Sequencer_Primary_Trigger_glue_out is selected
 */
#define INPUTMUX_AON_LCSENSE_SEQ_TICKS_GLUE_IN_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_LCSENSE_SEQ_TICKS_GLUE_IN_INP_SHIFT)) & INPUTMUX_AON_LCSENSE_SEQ_TICKS_GLUE_IN_INP_MASK)
/*! @} */

/*! @name ACMP0_TRIG - ACMP0 Input Connections */
/*! @{ */

#define INPUTMUX_AON_ACMP0_TRIG_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_AON_ACMP0_TRIG_TRIGIN_SHIFT     (0U)
/*! TRIGIN - CMP0 input trigger
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..Reserved
 *  0b001011..Reserved
 *  0b001100..QTMR0_tmr0_output is selected
 *  0b001101..QTMR0_tmr1_output is selected
 *  0b001110..QTMR0_tmr2_output is selected
 *  0b001111..QTMR0_tmr3_output is selected
 *  0b010000..LPTMR0 output is selected
 *  0b010001..Reserved
 *  0b010010..QTMR1_tmr0_output is selected
 *  0b010011..QTMR1_tmr1_output is selected
 *  0b010100..QTMR1_tmr2_output is selected
 *  0b010101..QTMR1_tmr3_output is selected
 *  0b010110..Reserved
 *  0b010111..WUU is selected
 *  0b011000..GPIO (AON) Pin Event Trig 0 is selected
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..ACMP0 raw analog comparator output is selected
 *  0b011111..ACMP0_AON_cout is selected
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..SoC_glue_XOR0_out is selected
 *  0b100011..Reserved
 */
#define INPUTMUX_AON_ACMP0_TRIG_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_ACMP0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_AON_ACMP0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_AON_ACMP0_TRIG */
#define INPUTMUX_AON_ACMP0_TRIG_COUNT            (4U)

/*! @name LPADC0_TRIG - LPADC trigger input connections */
/*! @{ */

#define INPUTMUX_AON_LPADC0_TRIG_TRIGIN_MASK     (0x1FU)
#define INPUTMUX_AON_LPADC0_TRIG_TRIGIN_SHIFT    (0U)
/*! TRIGIN - ADC0 trigger inputs
 *  0b00000..Reserved
 *  0b00001..AON_TRIG_IN0 is selected
 *  0b00010..AON_TRIG_IN1 is selected
 *  0b00011..AON_TRIG_IN2 is selected
 *  0b00100..AON_TRIG_IN03 is selected
 *  0b00101..AON_TRIG_IN04 is selected
 *  0b00110..AON_TRIG_IN5 is selected
 *  0b00111..AON_TRIG_IN6 is selected
 *  0b01000..AON_TRIG_IN7 is selected
 *  0b01001..CM33 transmit event is selected
 *  0b01010..LPCMP_OUT is selected
 *  0b01011..Reserved
 *  0b01100..QTMR0_tmr0_output is selected
 *  0b01101..QTMR0_tmr1_output is selected
 *  0b01110..QTMR0_tmr2_output is selected
 *  0b01111..QTMR0_tmr3_output is selected
 *  0b10000..LPTMR0 output is selected
 *  0b10001..Reserved
 *  0b10010..QTMR1_tmr0_output is selected
 *  0b10011..QTMR1_tmr1_output is selected
 *  0b10100..QTMR1_tmr2_output is selected
 *  0b10101..QTMR1_tmr3_output is selected
 *  0b10110..Reserved
 *  0b10111..WUU is selected
 *  0b11000..GPIO (AON) Pin Event Trig 0 is selected
 *  0b11001..ACMP0 raw analog comparator output is selected
 *  0b11010..ACMP0_AON_cout is selected
 *  0b11011..Reserved
 *  0b11100..Reserved
 *  0b11101..soc_glue_XOR0_out is selected
 *  0b11110..Reserved
 */
#define INPUTMUX_AON_LPADC0_TRIG_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_LPADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_AON_LPADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_AON_LPADC0_TRIG */
#define INPUTMUX_AON_LPADC0_TRIG_COUNT           (4U)

/*! @name AON_TRIG_OUT - AON Trigger Output Connections */
/*! @{ */

#define INPUTMUX_AON_AON_TRIG_OUT_INP_MASK       (0x1FU)
#define INPUTMUX_AON_AON_TRIG_OUT_INP_SHIFT      (0U)
/*! INP - EXT trigger input connections
 *  0b00000..Reserved
 *  0b00001..CM33 transmit event is selected
 *  0b00010..AON_LPUART0 (ipp_do_lpuart_txd) is selected
 *  0b00011..Reserved
 *  0b00100..Reserved
 *  0b00101..Reserved
 *  0b00110..Reserved
 *  0b00111..Reserved
 *  0b01000..LPADC_trigger_out[0] is selected
 *  0b01001..LPADC_trigger_out[1] is selected
 *  0b01010..LPADC_trigger_out[2] is selected
 *  0b01011..parked_out_intverted is selected
 *  0b01100..AON_LPTMR0 output is selected
 *  0b01101..Reserved
 *  0b01110..LPCOMP0_out is selected
 *  0b01111..Reserved
 *  0b10000..ACMP0 raw analog comparator output is selected
 *  0b10001..ACMP0_AON_cout is selected
 *  0b10010..Reserved
 *  0b10011..Reserved
 *  0b10100..QTMR0_tmr0_output is selected
 *  0b10101..QTMR0_tmr1_output is selected
 *  0b10110..QTMR0_tmr2_output is selected
 *  0b10111..QTMR0_tmr3_output is selected
 *  0b11000..QTMR1_tmr0_output is selected
 *  0b11001..QTMR1_tmr1_output is selected
 *  0b11010..QTMR1_tmr2_output is selected
 *  0b11011..QTMR1_tmr3_output is selected
 */
#define INPUTMUX_AON_AON_TRIG_OUT_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_AON_TRIG_OUT_INP_SHIFT)) & INPUTMUX_AON_AON_TRIG_OUT_INP_MASK)
/*! @} */

/* The count of INPUTMUX_AON_AON_TRIG_OUT */
#define INPUTMUX_AON_AON_TRIG_OUT_COUNT          (2U)

/*! @name CMP0_SAMPLE - ACMP0 SAMPLE trigger input connections */
/*! @{ */

#define INPUTMUX_AON_CMP0_SAMPLE_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_AON_CMP0_SAMPLE_TRIGIN_SHIFT    (0U)
/*! TRIGIN - ACMP0 input trigger
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..LPCMP_OUT is selected
 *  0b001011..Reserved
 *  0b001100..QTMR0_tmr0_output is selected
 *  0b001101..QTMR0_tmr1_output is selected
 *  0b001110..QTMR0_tmr2_output is selected
 *  0b001111..QTMR0_tmr3_output is selected
 *  0b010000..LPTMR0 output is selected
 *  0b010001..Reserved
 *  0b010010..QTMR1_tmr0_output is selected
 *  0b010011..QTMR1_tmr1_output is selected
 *  0b010100..QTMR1_tmr2_output is selected
 *  0b010101..QTMR1_tmr3_output is selected
 *  0b010110..Reserved
 *  0b010111..WUU is selected
 *  0b011000..GPIO (AON) Pin Event Trig 0 is selected
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..Reserved
 *  0b011111..Reserved
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..SoC_glue_XOR0_out is selected
 *  0b100011..Reserved
 */
#define INPUTMUX_AON_CMP0_SAMPLE_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_CMP0_SAMPLE_TRIGIN_SHIFT)) & INPUTMUX_AON_CMP0_SAMPLE_TRIGIN_MASK)
/*! @} */

/*! @name CMP0_RR_TRIG - ACMP0 RR trigger input connections */
/*! @{ */

#define INPUTMUX_AON_CMP0_RR_TRIG_TRIGIN_MASK    (0x3FU)
#define INPUTMUX_AON_CMP0_RR_TRIG_TRIGIN_SHIFT   (0U)
/*! TRIGIN - ACMP0 input trigger
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..LPCMP_OUT is selected
 *  0b001011..Reserved
 *  0b001100..QTMR0_tmr0_output is selected
 *  0b001101..QTMR0_tmr1_output is selected
 *  0b001110..QTMR0_tmr2_output is selected
 *  0b001111..QTMR0_tmr3_output is selected
 *  0b010000..LPTMR0 output is selected
 *  0b010001..Reserved
 *  0b010010..QTMR1_tmr0_output is selected
 *  0b010011..QTMR1_tmr1_output is selected
 *  0b010100..QTMR1_tmr2_output is selected
 *  0b010101..QTMR1_tmr3_output is selected
 *  0b010110..Reserved
 *  0b010111..WUU is selected
 *  0b011000..GPIO (AON) Pin Event Trig 0 is selected
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..Reserved
 *  0b011111..Reserved
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..SoC_glue_XOR0_out is selected
 *  0b100011..Reserved
 */
#define INPUTMUX_AON_CMP0_RR_TRIG_TRIGIN(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_CMP0_RR_TRIG_TRIGIN_SHIFT)) & INPUTMUX_AON_CMP0_RR_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name LPI2C0_TRIG - LPI2C0 trigger input connections */
/*! @{ */

#define INPUTMUX_AON_LPI2C0_TRIG_INP_MASK        (0x3FU)
#define INPUTMUX_AON_LPI2C0_TRIG_INP_SHIFT       (0U)
/*! INP - LPI2C0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..LPCMP_OUT is selected
 *  0b001011..Reserved
 *  0b001100..QTMR0_tmr0_output is selected
 *  0b001101..QTMR0_tmr1_output is selected
 *  0b001110..QTMR0_tmr2_output is selected
 *  0b001111..QTMR0_tmr3_output is selected
 *  0b010000..LPTMR0 output is selected
 *  0b010001..Reserved
 *  0b010010..QTMR1_tmr0_output is selected
 *  0b010011..QTMR1_tmr1_output is selected
 *  0b010100..QTMR1_tmr2_output is selected
 *  0b010101..QTMR1_tmr3_output is selected
 *  0b010110..Reserved
 *  0b010111..WUU is selected
 *  0b011000..GPIO (AON) Pin Event Trig 0 is selected
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..ACMP0 raw analog comparator output is selected
 *  0b011111..ACMP0_AON_cout is selected
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..SoC_glue_XOR0_out is selected
 *  0b100011..Reserved
 */
#define INPUTMUX_AON_LPI2C0_TRIG_INP(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_LPI2C0_TRIG_INP_SHIFT)) & INPUTMUX_AON_LPI2C0_TRIG_INP_MASK)
/*! @} */

/*! @name LPUART0 - LPUART0 trigger input connections */
/*! @{ */

#define INPUTMUX_AON_LPUART0_INP_MASK            (0x3FU)
#define INPUTMUX_AON_LPUART0_INP_SHIFT           (0U)
/*! INP - LPI2C0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..AON_TRIG_IN0 input is selected
 *  0b000010..AON_TRIG_IN1 input is selected
 *  0b000011..AON_TRIG_IN2 input is selected
 *  0b000100..AON_TRIG_IN3 input is selected
 *  0b000101..AON_TRIG_IN4 input is selected
 *  0b000110..AON_TRIG_IN5 input is selected
 *  0b000111..AON_TRIG_IN6 input is selected
 *  0b001000..AON_TRIG_IN7 input is selected
 *  0b001001..CM33 transmit event is selected
 *  0b001010..LPCMP_OUT is selected
 *  0b001011..Reserved
 *  0b001100..QTMR0_tmr0_output is selected
 *  0b001101..QTMR0_tmr1_output is selected
 *  0b001110..QTMR0_tmr2_output is selected
 *  0b001111..QTMR0_tmr3_output is selected
 *  0b010000..LPTMR0 output is selected
 *  0b010001..Reserved
 *  0b010010..QTMR1_tmr0_output is selected
 *  0b010011..QTMR1_tmr1_output is selected
 *  0b010100..QTMR1_tmr2_output is selected
 *  0b010101..QTMR1_tmr3_output is selected
 *  0b010110..Reserved
 *  0b010111..WUU is selected
 *  0b011000..GPIO (AON) Pin Event Trig 0 is selected
 *  0b011001..Reserved
 *  0b011010..LPADC_trigger_out[0] is selected
 *  0b011011..LPADC_trigger_out[1] is selected
 *  0b011100..LPADC_trigger_out[2] is selected
 *  0b011101..LPADC_trigger_out[3] is selected
 *  0b011110..ACMP0 raw analog comparator output is selected
 *  0b011111..ACMP0_AON_cout is selected
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..SoC_glue_XOR0_out is selected
 *  0b100011..Reserved
 */
#define INPUTMUX_AON_LPUART0_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AON_LPUART0_INP_SHIFT)) & INPUTMUX_AON_LPUART0_INP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INPUTMUX_AON_Register_Masks */


/*!
 * @}
 */ /* end of group INPUTMUX_AON_Peripheral_Access_Layer */


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


#endif  /* PERI_INPUTMUX_AON_H_ */

