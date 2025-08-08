/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
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
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
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

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
#define INPUTMUX_SCT0_INMUX_COUNT                 7u
#define INPUTMUX_TIMER0CAP_COUNT                  4u
#define INPUTMUX_TIMER1CAP_COUNT                  4u
#define INPUTMUX_TIMER2CAP_COUNT                  4u
#define INPUTMUX_EZHARCHB_INMUX_COUNT             8u
#define INPUTMUX_PINTSEL_COUNT                    8u
#define INPUTMUX_DMA0_ITRIG_INMUX_COUNT           32u
#define INPUTMUX_DMA0_OTRIG_INMUX_COUNT           7u
#define INPUTMUX_TIMER3CAP_COUNT                  4u
#define INPUTMUX_TIMER4CAP_COUNT                  4u
#define INPUTMUX_PINTSECSEL_COUNT                 2u
#define INPUTMUX_DMA1_ITRIG_INMUX_COUNT           16u
#define INPUTMUX_DMA1_OTRIG_INMUX_COUNT           4u
#define INPUTMUX_ADC0_TRIGN_COUNT                 4u
#define INPUTMUX_ADC1_TRIGN_COUNT                 4u
#define INPUTMUX_PWM0_EXTSYNCN_COUNT              4u
#define INPUTMUX_PWM0_EXTAN_COUNT                 4u
#define INPUTMUX_PWM0_FAULTN_COUNT                4u
#define INPUTMUX_PWM1_EXTSYNCN_COUNT              4u
#define INPUTMUX_PWM1_EXTAN_COUNT                 4u
#define INPUTMUX_PWM1_FAULTN_COUNT                4u
#define INPUTMUX_AOI0_IN_COUNT                    16u
#define INPUTMUX_AOI1_IN_COUNT                    16u
#define INPUTMUX_AOIX_EXT_TRIGN_COUNT             8u
#define INPUTMUX_DMA0_ITRIG_INMUX32_COUNT         20u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCT0_INMUX[INPUTMUX_SCT0_INMUX_COUNT]; /**< Inputmux register for SCT0 input, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t TIMER0CAP[INPUTMUX_TIMER0CAP_COUNT]; /**< Capture select register for TIMER0 inputs, array offset: 0x20, array step: 0x4 */
  __IO uint32_t TIMER0TRIG;                        /**< Trigger register for TIMER0, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TIMER1CAP[INPUTMUX_TIMER1CAP_COUNT]; /**< Capture select register for TIMER1 inputs, array offset: 0x40, array step: 0x4 */
  __IO uint32_t TIMER1TRIG;                        /**< Trigger register for TIMER1, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t TIMER2CAP[INPUTMUX_TIMER2CAP_COUNT]; /**< Capture select register for TIMER2 inputs, array offset: 0x60, array step: 0x4 */
  __IO uint32_t TIMER2TRIG;                        /**< Trigger register for TIMER2, offset: 0x70 */
       uint8_t RESERVED_3[44];
  __IO uint32_t EZHARCHB_INMUX[INPUTMUX_EZHARCHB_INMUX_COUNT]; /**< Inputmux register for EZH arch B inputs, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t PINTSEL[INPUTMUX_PINTSEL_COUNT];   /**< Pin interrupt select, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t DMA0_ITRIG_INMUX[INPUTMUX_DMA0_ITRIG_INMUX_COUNT]; /**< Trigger select for DMA0 channel, array offset: 0xE0, array step: 0x4 */
  __IO uint32_t DMA0_OTRIG_INMUX[INPUTMUX_DMA0_OTRIG_INMUX_COUNT]; /**< DMA0 output trigger selection for DMA0 input trigger, array offset: 0x160, array step: 0x4 */
       uint8_t RESERVED_4[4];
  __IO uint32_t FREQMEAS_REF;                      /**< Selection for frequency measurement reference clock, offset: 0x180 */
  __IO uint32_t FREQMEAS_TAR;                      /**< Selection for frequency measurement target clock, offset: 0x184 */
       uint8_t RESERVED_5[24];
  __IO uint32_t TIMER3CAP[INPUTMUX_TIMER3CAP_COUNT]; /**< Capture select register for TIMER3 inputs, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t TIMER3TRIG;                        /**< Trigger register for TIMER3, offset: 0x1B0 */
       uint8_t RESERVED_6[12];
  __IO uint32_t TIMER4CAP[INPUTMUX_TIMER4CAP_COUNT]; /**< Capture select register for TIMER4 inputs, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t TIMER4TRIG;                        /**< Trigger register for TIMER4, offset: 0x1D0 */
       uint8_t RESERVED_7[12];
  __IO uint32_t PINTSECSEL[INPUTMUX_PINTSECSEL_COUNT]; /**< Pin interrupt secure select, array offset: 0x1E0, array step: 0x4 */
       uint8_t RESERVED_8[24];
  __IO uint32_t DMA1_ITRIG_INMUX[INPUTMUX_DMA1_ITRIG_INMUX_COUNT]; /**< Trigger select for DMA1 channel, array offset: 0x200, array step: 0x4 */
  __IO uint32_t DMA1_OTRIG_INMUX[INPUTMUX_DMA1_OTRIG_INMUX_COUNT]; /**< DMA1 output trigger selection for DMA1 input trigger, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_9[16];
  __IO uint32_t HSCMP0_TRIG;                       /**< Input connections for HSCMP0, offset: 0x260 */
       uint8_t RESERVED_10[28];
  __IO uint32_t ADC0_TRIG[INPUTMUX_ADC0_TRIGN_COUNT]; /**< ADC0 Trigger input connections, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_11[48];
  __IO uint32_t ADC1_TRIG[INPUTMUX_ADC1_TRIGN_COUNT]; /**< ADC1 Trigger input connections, array offset: 0x2C0, array step: 0x4 */
       uint8_t RESERVED_12[48];
  __IO uint32_t DAC0_TRIG;                         /**< DAC0 Trigger Inputs, offset: 0x300 */
       uint8_t RESERVED_13[28];
  __IO uint32_t DAC1_TRIG;                         /**< DAC1 Trigger Inputs, offset: 0x320 */
       uint8_t RESERVED_14[28];
  __IO uint32_t DAC2_TRIG;                         /**< DAC2 Trigger Inputs, offset: 0x340 */
       uint8_t RESERVED_15[28];
  __IO uint32_t ENC0_TRIG;                         /**< ENC0 Trigger Input Connections, offset: 0x360 */
  __IO uint32_t ENC0_HOME;                         /**< ENC0 Input Connections, offset: 0x364 */
  __IO uint32_t ENC0_INDEX;                        /**< ENC0 Input Connections, offset: 0x368 */
  __IO uint32_t ENC0_PHASEB;                       /**< ENC0 Input Connections, offset: 0x36C */
  __IO uint32_t ENC0_PHASEA;                       /**< ENC0 Input Connections, offset: 0x370 */
       uint8_t RESERVED_16[12];
  __IO uint32_t ENC1_TRIG;                         /**< ENC1 Trigger Input Connections, offset: 0x380 */
  __IO uint32_t ENC1_HOME;                         /**< ENC1 Input Connections, offset: 0x384 */
  __IO uint32_t ENC1_INDEX;                        /**< ENC1 Input Connections, offset: 0x388 */
  __IO uint32_t ENC1_PHASEB;                       /**< ENC1 Input Connections, offset: 0x38C */
  __IO uint32_t ENC1_PHASEA;                       /**< ENC1 Input Connections, offset: 0x390 */
       uint8_t RESERVED_17[12];
  __IO uint32_t PWM0_EXTSYNC[INPUTMUX_PWM0_EXTSYNCN_COUNT]; /**< PWM0 external synchronization, array offset: 0x3A0, array step: 0x4 */
  __IO uint32_t PWM0_EXTA[INPUTMUX_PWM0_EXTAN_COUNT]; /**< PWM0 input trigger connections, array offset: 0x3B0, array step: 0x4 */
  __IO uint32_t PWM0_EXTFORCE;                     /**< PWM0 external force trigger connections, offset: 0x3C0 */
  __IO uint32_t PWM0_FAULT[INPUTMUX_PWM0_FAULTN_COUNT]; /**< PWM0 fault input trigger connections, array offset: 0x3C4, array step: 0x4 */
       uint8_t RESERVED_18[12];
  __IO uint32_t PWM1_EXTSYNC[INPUTMUX_PWM1_EXTSYNCN_COUNT]; /**< PWM1 external synchronization, array offset: 0x3E0, array step: 0x4 */
  __IO uint32_t PWM1_EXTA[INPUTMUX_PWM1_EXTAN_COUNT]; /**< PWM1 input trigger connections, array offset: 0x3F0, array step: 0x4 */
  __IO uint32_t PWM1_EXTFORCE;                     /**< PWM1 external force trigger connections, offset: 0x400 */
  __IO uint32_t PWM1_FAULT[INPUTMUX_PWM1_FAULTN_COUNT]; /**< PWM1 fault input trigger connections, array offset: 0x404, array step: 0x4 */
       uint8_t RESERVED_19[12];
  __IO uint32_t PWM0_EXTCLK;                       /**< PWM0 external clock trigger connections, offset: 0x420 */
  __IO uint32_t PWM1_EXTCLK;                       /**< PWM1 external clock trigger connections, offset: 0x424 */
       uint8_t RESERVED_20[24];
  __IO uint32_t AOI0_IN[INPUTMUX_AOI0_IN_COUNT];   /**< AOI0 trigger inputs, array offset: 0x440, array step: 0x4 */
  __IO uint32_t AOI1_IN[INPUTMUX_AOI1_IN_COUNT];   /**< AOI1 trigger inputs, array offset: 0x480, array step: 0x4 */
  __IO uint32_t AOI_EXT_TRIG[INPUTMUX_AOIX_EXT_TRIGN_COUNT]; /**< AOI External Trigger Inputs, array offset: 0x4C0, array step: 0x4 */
  __IO uint32_t HSCMP1_TRIG;                       /**< Input connections for HSCMP1, offset: 0x4E0 */
       uint8_t RESERVED_21[28];
  __IO uint32_t HSCMP2_TRIG;                       /**< Input connections for HSCMP2, offset: 0x500 */
       uint8_t RESERVED_22[28];
  __IO uint32_t DMA0_ITRIG_INMUX32[INPUTMUX_DMA0_ITRIG_INMUX32_COUNT]; /**< Trigger select for DMA0 channel, array offset: 0x520, array step: 0x4 */
       uint8_t RESERVED_23[464];
  __IO uint32_t DMA0_REQEN0;                       /**< Enable DMA0 requests, offset: 0x740 */
  __IO uint32_t DMA0_REQEN1;                       /**< Enable DMA0 requests, offset: 0x744 */
  __O  uint32_t DMA0_REQEN0_SET;                   /**< Set bits in DMA0_REQEN0 register, offset: 0x748 */
  __O  uint32_t DMA0_REQEN1_SET;                   /**< Set bits in DMA0_REQEN1 register, offset: 0x74C */
  __O  uint32_t DMA0_REQEN0_CLR;                   /**< Clear bits in DMA0_REQEN0 register, offset: 0x750 */
  __O  uint32_t DMA0_REQEN1_CLR;                   /**< Clear bits in DMA0_REQEN1 register, offset: 0x754 */
       uint8_t RESERVED_24[8];
  __IO uint32_t DMA1_REQEN;                        /**< Enable DMA1 requests, offset: 0x760 */
       uint8_t RESERVED_25[4];
  __O  uint32_t DMA1_REQEN_SET;                    /**< Set bits in DMA1_REQEN register, offset: 0x768 */
       uint8_t RESERVED_26[4];
  __O  uint32_t DMA1_REQEN_CLR;                    /**< Clear bits in DMA1_REQEN register, offset: 0x770 */
       uint8_t RESERVED_27[12];
  __IO uint32_t DMA0_ITRIGEN0;                     /**< Enable DMA0 triggers, offset: 0x780 */
  __IO uint32_t DMA0_ITRIGEN1;                     /**< Enable DMA0 triggers, offset: 0x784 */
  __O  uint32_t DMA0_ITRIGEN0_SET;                 /**< Set bits in DMA0_ITRIGEN0 register, offset: 0x788 */
  __O  uint32_t DMA0_ITRIGEN1_SET;                 /**< Set bits in DMA0_ITRIGEN1 register, offset: 0x78C */
  __O  uint32_t DMA0_ITRIGEN0_CLR;                 /**< Clear bits in DMA0_ITRIGEN0 register, offset: 0x790 */
  __O  uint32_t DMA0_ITRIGEN1_CLR;                 /**< Clear bits in DMA0_ITRIGEN1 register, offset: 0x794 */
       uint8_t RESERVED_28[8];
  __IO uint32_t DMA1_ITRIGEN;                      /**< Enable DMA1 triggers, offset: 0x7A0 */
       uint8_t RESERVED_29[4];
  __O  uint32_t DMA1_ITRIGEN_SET;                  /**< Set bits in DMA1_ITRIGEN register, offset: 0x7A8 */
       uint8_t RESERVED_30[4];
  __O  uint32_t DMA1_ITRIGEN_CLR;                  /**< Clear bits in DMA1_ITRIGEN register, offset: 0x7B0 */
} INPUTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Register_Masks INPUTMUX Register Masks
 * @{
 */

/*! @name SCT0_INMUX - Inputmux register for SCT0 input */
/*! @{ */

#define INPUTMUX_SCT0_INMUX_INP_N_MASK           (0x3FU)
#define INPUTMUX_SCT0_INMUX_INP_N_SHIFT          (0U)
/*! INP_N - Input number to SCT0 inputs 0 to 6.
 *  0b000000..SCT_GPIO_IN_A function selected from IOCON register
 *  0b000001..SCT_GPIO_IN_B function selected from IOCON register
 *  0b000010..SCT_GPIO_IN_C function selected from IOCON register
 *  0b000011..SCT_GPIO_IN_D function selected from IOCON register
 *  0b000100..SCT_GPIO_IN_E function selected from IOCON register
 *  0b000101..SCT_GPIO_IN_F function selected from IOCON register
 *  0b000110..SCT_GPIO_IN_G function selected from IOCON register
 *  0b000111..SCT_GPIO_IN_H function selected from IOCON register
 *  0b001000..T0_MAT0 ctimer 0 match[0] output
 *  0b001001..T1_MAT0 ctimer 1 match[0] output
 *  0b001010..T2_MAT0 ctimer 2 match[0] output
 *  0b001011..T3_MAT0 ctimer 3 match[0] output
 *  0b001100..T4_MAT0 ctimer 4 match[0] output
 *  0b001101..ADC0_IRQ interrupt request from ADC0
 *  0b001110..GPIOINT_BMATCH
 *  0b001111..USB0_FRAME_TOGGLE
 *  0b010000..Reserved
 *  0b010001..ACMP0_OUT from analog comparator
 *  0b010010..SHARED_I2S_SCLK0 output from I2S pin sharing
 *  0b010011..SHARED_I2S_SCLK1 output from I2S pin sharing
 *  0b010100..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b010101..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b010110..ARM_TXEV interrupt event from CPU0
 *  0b010111..DEBUG_HALTED from CPU0
 *  0b011000..ADC1_IRQ interrupt request from ADC1
 *  0b011001..ADC0_tcomp[0]
 *  0b011010..ADC0_tcomp[1]
 *  0b011011..ADC0_tcomp[2]
 *  0b011100..ADC0_tcomp[3]
 *  0b011101..ADC1_tcomp[0]
 *  0b011110..ADC1_tcomp[1]
 *  0b011111..ADC1_tcomp[2]
 *  0b100000..ADC1_tcomp[3]
 *  0b100001..HSCMP0_OUT
 *  0b100010..HSCMP1_OUT
 *  0b100011..HSCMP2_OUT
 *  0b100100..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b100101..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100110..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100111..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b101000..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b101001..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b101010..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b101011..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b101100..ENC0_CMP/POS_MATCH
 *  0b101101..ENC1_CMP/POS_MATCH
 *  0b101110..AOI0_OUT0
 *  0b101111..AOI0_OUT1
 *  0b110000..AOI0_OUT2
 *  0b110001..AOI0_OUT3
 *  0b110010..AOI1_OUT0
 *  0b110011..AOI1_OUT1
 *  0b110100..AOI1_OUT2
 *  0b110101..AOI1_OUT3
 *  0b110110..FC3_SCK
 *  0b110111..FC3_RXD_SDA_MOSI_DATA
 *  0b111000..FC3_TXD_SCL_MISO_WS
 *  0b111001..FC3_CTS_DSA_SSEL0
 *  0b111010..TMPR_OUT
 *  0b111011-0b111111..None
 */
#define INPUTMUX_SCT0_INMUX_INP_N(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_SCT0_INMUX_INP_N_SHIFT)) & INPUTMUX_SCT0_INMUX_INP_N_MASK)
/*! @} */

/*! @name TIMER0CAP - Capture select register for TIMER0 inputs */
/*! @{ */

#define INPUTMUX_TIMER0CAP_CAPTSEL_MASK          (0x3FU)
#define INPUTMUX_TIMER0CAP_CAPTSEL_SHIFT         (0U)
/*! CAPTSEL - Input number to TIMER0 capture inputs 0 to 5
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER0CAP_CAPTSEL(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER0CAP_CAPTSEL_SHIFT)) & INPUTMUX_TIMER0CAP_CAPTSEL_MASK)
/*! @} */

/*! @name TIMER0TRIG - Trigger register for TIMER0 */
/*! @{ */

#define INPUTMUX_TIMER0TRIG_TRIGIN_MASK          (0x3FU)
#define INPUTMUX_TIMER0TRIG_TRIGIN_SHIFT         (0U)
/*! TRIGIN - Input number to TIMER0 trigger inputs
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER0TRIG_TRIGIN(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER0TRIG_TRIGIN_SHIFT)) & INPUTMUX_TIMER0TRIG_TRIGIN_MASK)
/*! @} */

/*! @name TIMER1CAP - Capture select register for TIMER1 inputs */
/*! @{ */

#define INPUTMUX_TIMER1CAP_CAPTSEL_MASK          (0x3FU)
#define INPUTMUX_TIMER1CAP_CAPTSEL_SHIFT         (0U)
/*! CAPTSEL - Input number to TIMER1 capture inputs 0 to 5
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER1CAP_CAPTSEL(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER1CAP_CAPTSEL_SHIFT)) & INPUTMUX_TIMER1CAP_CAPTSEL_MASK)
/*! @} */

/*! @name TIMER1TRIG - Trigger register for TIMER1 */
/*! @{ */

#define INPUTMUX_TIMER1TRIG_TRIGIN_MASK          (0x3FU)
#define INPUTMUX_TIMER1TRIG_TRIGIN_SHIFT         (0U)
/*! TRIGIN - Input number to TIMER1 trigger inputs
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER1TRIG_TRIGIN(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER1TRIG_TRIGIN_SHIFT)) & INPUTMUX_TIMER1TRIG_TRIGIN_MASK)
/*! @} */

/*! @name TIMER2CAP - Capture select register for TIMER2 inputs */
/*! @{ */

#define INPUTMUX_TIMER2CAP_CAPTSEL_MASK          (0x3FU)
#define INPUTMUX_TIMER2CAP_CAPTSEL_SHIFT         (0U)
/*! CAPTSEL - Input number to TIMER2 capture inputs 0 to 5
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER2CAP_CAPTSEL(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER2CAP_CAPTSEL_SHIFT)) & INPUTMUX_TIMER2CAP_CAPTSEL_MASK)
/*! @} */

/*! @name TIMER2TRIG - Trigger register for TIMER2 */
/*! @{ */

#define INPUTMUX_TIMER2TRIG_TRIGIN_MASK          (0x3FU)
#define INPUTMUX_TIMER2TRIG_TRIGIN_SHIFT         (0U)
/*! TRIGIN - Input number to TIMER2 trigger inputs
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER2TRIG_TRIGIN(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER2TRIG_TRIGIN_SHIFT)) & INPUTMUX_TIMER2TRIG_TRIGIN_MASK)
/*! @} */

/*! @name EZHARCHB_INMUX - Inputmux register for EZH arch B inputs */
/*! @{ */

#define INPUTMUX_EZHARCHB_INMUX_INP_MASK         (0x7FU)
#define INPUTMUX_EZHARCHB_INMUX_INP_SHIFT        (0U)
/*! INP - Input number select to EZHARCHB input
 *  0b0000000-0b0001111..GPI00_0 to GPIO0_15 functions synced to system clock, selected from IOCON register
 *  0b0010000..SCT_OUT8 output from SCTimer, synced to system clock
 *  0b0010001..SCT_OUT9 output from SCTimer, synced to system clock
 *  0b0010010..Reserved
 *  0b0010011..Reserved
 *  0b0010100..MRT_IRQ0 Multi-rate timer interrupt request 0
 *  0b0010101..MRT_IRQ1 Multi-rate timer interrupt request 1
 *  0b0010110..T4_MAT3 ctimer 4 match[3] output
 *  0b0010111..T4_MAT2 ctimer 4 match[2] output
 *  0b0011000..T3_MAT3 ctimer 3 match[3] output
 *  0b0011001..T3_MAT2 ctimer 3 match[2] output
 *  0b0011010..T1_MAT3 ctimer 1 match[3] output
 *  0b0011011..T1_MAT2 ctimer 1 match[2] output
 *  0b0011100..UTICK0_IRQ Micro-tick timer interrupt, synced to system clock
 *  0b0011101..WDT_IRQ Watchdog Timer interrupt request, synced to system clock
 *  0b0011110..ADC0_IRQ interrupt request from ADC
 *  0b0011111..ACMP0_IRQ Combined Analog comparator interrupt request
 *  0b0100000..LSPI_HS_IRQ High speed Serial Peripheral interface interrupt request
 *  0b0100001..FLEXCOMM7_IRQ Flexcomm7 interrupt synced to system clock
 *  0b0100010..FLEXCOMM6_IRQ Flexcomm6 interrupt synced to system clock
 *  0b0100011..FLEXCOMM5_IRQ Flexcomm5 interrupt synced to system clock
 *  0b0100100..FLEXCOMM4_IRQ Flexcomm4 interrupt synced to system clock
 *  0b0100101..FLEXCOMM3_IRQ Flexcomm3 interrupt synced to system clock
 *  0b0100110..FLEXCOMM2_IRQ Flexcomm2 interrupt synced to system clock
 *  0b0100111..FLEXCOMM1_IRQ Flexcomm1 interrupt synced to system clock
 *  0b0101000..FLEXCOMM0_IRQ Flexcomm0 interrupt synced to system clock
 *  0b0101001..DMA0_IRQ DMA0 interrupt request
 *  0b0101010..DMA1_IRQ DMA1 interrupt request
 *  0b0101011..SYS_IRQ combined WDT_INT Watchdog Timer interrupt request | FLASH_IRQ Flash interrupt request | BOD_IRQ BrownOut Detection interrupt request
 *  0b0101100..RTC_COMBO_IRQ Real Time Clock Combined Alarm | Wake-up interrupt request
 *  0b0101101..ARM_TXEV interrupt event from CPU0
 *  0b0101110..GPIOINT_BMATCH GPIO_INT boolean pattern match output
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..ACMP_OUT output from analog comparator
 *  0b0110010..USB0_FRAME_TOGGLE
 *  0b0110011..Reserved
 *  0b0110100..OSTIMER_IRQ OS Timer interrupt request
 *  0b0110101..ADC1 interrupt
 *  0b0110110..HSCOMP0_IRQ/HSCOMP1_IRQ/HSCOMP2_IRQ
 *  0b0110111..DAC0 interrupt
 *  0b0111000..DAC1/2 interrupt
 *  0b0111001..FlexPWM0 interrupt
 *  0b0111010..FlexPWM1 interrupt
 *  0b0111011..ENC0 interrupt
 *  0b0111100..ENC1 interrupt
 *  0b0111101..AOI0_OUT0
 *  0b0111110..AOI1_OUT0
 *  0b0111111..TMPR_OUT
 *  0b1000000-0b1111110..Reserved
 */
#define INPUTMUX_EZHARCHB_INMUX_INP(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_EZHARCHB_INMUX_INP_SHIFT)) & INPUTMUX_EZHARCHB_INMUX_INP_MASK)
/*! @} */

/*! @name PINTSEL - Pin interrupt select */
/*! @{ */

#define INPUTMUX_PINTSEL_INTPIN_MASK             (0x7FU)
#define INPUTMUX_PINTSEL_INTPIN_SHIFT            (0U)
/*! INTPIN - Pin number select for pin interrupt or pattern match engine input. For PIOx_y: INTPIN =
 *    (x * 32) + y. PIO0_0 to PIO1_31 correspond to numbers 0 to 63.
 */
#define INPUTMUX_PINTSEL_INTPIN(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PINTSEL_INTPIN_SHIFT)) & INPUTMUX_PINTSEL_INTPIN_MASK)
/*! @} */

/*! @name DMA0_ITRIG_INMUX - Trigger select for DMA0 channel */
/*! @{ */

#define INPUTMUX_DMA0_ITRIG_INMUX_INP_MASK       (0x3FU)
#define INPUTMUX_DMA0_ITRIG_INMUX_INP_SHIFT      (0U)
/*! INP - Trigger input number (binary value) for DMA channel n (n = 0 to 31).
 *  0b000000..FlexSPI_RX
 *  0b000001..FlexSPI_TX
 *  0b000010..GPIO_INT0
 *  0b000011..GPIO_INT1
 *  0b000100..GPIO_INT2
 *  0b000101..GPIO_INT3
 *  0b000110..T0_DMAREQ_M0
 *  0b000111..T0_DMAREQ_M1
 *  0b001000..T1_DMAREQ_M0
 *  0b001001..T1_DMAREQ_M1
 *  0b001010..T2_DMAREQ_M0
 *  0b001011..T2_DMAREQ_M1
 *  0b001100..T3_DMAREQ_M0
 *  0b001101..T3_DMAREQ_M1
 *  0b001110..T4_DMAREQ_M0
 *  0b001111..T4_DMAREQ_M1
 *  0b010000..ACMP0_OUT
 *  0b010001..SDMA0_TRIGOUT_A
 *  0b010010..SDMA0_TRIGOUT_B
 *  0b010011..SDMA0_TRIGOUT_C
 *  0b010100..SDMA0_TRIGOUT_D
 *  0b010101..SCT_DMA0
 *  0b010110..SCT_DMA1
 *  0b010111..ADC0_tcomp[0]
 *  0b011000..ADC1_tcomp[0]
 *  0b011001..HSCMP0
 *  0b011010..HSCMP1
 *  0b011011..HSCMP2
 *  0b011100..AOI0_OUT0
 *  0b011101..AOI0_OUT1
 *  0b011110..AOI0_OUT2
 *  0b011111..AOI0_OUT3
 *  0b100000..AOI1_OUT0
 *  0b100001..AOI1_OUT1
 *  0b100010..AOI1_OUT2
 *  0b100011..AOI1_OUT3
 *  0b100100..FlexPWM0_req_capt0
 *  0b100101..FlexPWM0_req_capt1
 *  0b100110..FlexPWM0_req_capt2
 *  0b100111..FlexPWM0_req_capt3
 *  0b101000..FlexPWM0_req_val0
 *  0b101001..FlexPWM0_req_val1
 *  0b101010..FlexPWM0_req_val2
 *  0b101011..FlexPWM0_req_val3
 *  0b101100..FlexPWM1_req_capt0
 *  0b101101..FlexPWM1_req_capt1
 *  0b101110..FlexPWM1_req_capt2
 *  0b101111..FlexPWM1_req_capt3
 *  0b110000..FlexPWM1_req_val0
 *  0b110001..FlexPWM1_req_val1
 *  0b110010..FlexPWM1_req_val2
 *  0b110011..FlexPWM1_req_val3
 *  0b110100..TMPR_OUT
 *  0b110110-0b111111..Reserved
 */
#define INPUTMUX_DMA0_ITRIG_INMUX_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA0_ITRIG_INMUX_INP_MASK)
/*! @} */

/* The count of INPUTMUX_DMA0_ITRIG_INMUX */
#define INPUTMUX_DMA0_ITRIG_INMUX0               (32U)

/*! @name DMA0_OTRIG_INMUX - DMA0 output trigger selection for DMA0 input trigger */
/*! @{ */

#define INPUTMUX_DMA0_OTRIG_INMUX_INP_MASK       (0x3FU)
#define INPUTMUX_DMA0_OTRIG_INMUX_INP_SHIFT      (0U)
/*! INP - DMA trigger output number (binary value) for DMA channel n (n = 0 to 52). */
#define INPUTMUX_DMA0_OTRIG_INMUX_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_OTRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA0_OTRIG_INMUX_INP_MASK)
/*! @} */

/*! @name FREQMEAS_REF - Selection for frequency measurement reference clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_REF_CLKIN_MASK         (0x1FU)
#define INPUTMUX_FREQMEAS_REF_CLKIN_SHIFT        (0U)
/*! CLKIN - Clock source number (binary value) for frequency measure function target clock.
 *  0b00000..XTAL32MHz
 *  0b00001..FRO_OSC_12M
 *  0b00010..FRO_OSC_96M
 *  0b00011..WDOSC (FRO1M)
 *  0b00100..32KHZ_OSC
 *  0b00101..MAIN_SYS_CLOCK
 *  0b00110..FREQME_GPIO_CLK_A
 *  0b00111..FREQME_GPIO_CLK_B
 *  0b01000..AOI0_OUT2
 *  0b01001..AOI1_OUT2
 */
#define INPUTMUX_FREQMEAS_REF_CLKIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_REF_CLKIN_SHIFT)) & INPUTMUX_FREQMEAS_REF_CLKIN_MASK)
/*! @} */

/*! @name FREQMEAS_TAR - Selection for frequency measurement target clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_TAR_CLKIN_MASK         (0x1FU)
#define INPUTMUX_FREQMEAS_TAR_CLKIN_SHIFT        (0U)
/*! CLKIN - Clock source number (binary value) for frequency measure function target clock
 *  0b00000..XTAL32MHz
 *  0b00001..FRO_OSC_12M
 *  0b00010..FRO_OSC_96M
 *  0b00011..WDOSC (FRO1M)
 *  0b00100..32KHZ_OSC
 *  0b00101..MAIN_SYS_CLOCK
 *  0b00110..FREQME_GPIO_CLK_A
 *  0b00111..FREQME_GPIO_CLK_B
 *  0b01000..AOI0_OUT2
 *  0b01001..AOI1_OUT2
 */
#define INPUTMUX_FREQMEAS_TAR_CLKIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_TAR_CLKIN_SHIFT)) & INPUTMUX_FREQMEAS_TAR_CLKIN_MASK)
/*! @} */

/*! @name TIMER3CAP - Capture select register for TIMER3 inputs */
/*! @{ */

#define INPUTMUX_TIMER3CAP_CAPTSEL_MASK          (0x3FU)
#define INPUTMUX_TIMER3CAP_CAPTSEL_SHIFT         (0U)
/*! CAPTSEL - Input number to TIMER3 capture inputs 0 to 5
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER3CAP_CAPTSEL(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER3CAP_CAPTSEL_SHIFT)) & INPUTMUX_TIMER3CAP_CAPTSEL_MASK)
/*! @} */

/*! @name TIMER3TRIG - Trigger register for TIMER3 */
/*! @{ */

#define INPUTMUX_TIMER3TRIG_TRIGIN_MASK          (0x3FU)
#define INPUTMUX_TIMER3TRIG_TRIGIN_SHIFT         (0U)
/*! TRIGIN - Input number to TIMER3 trigger inputs
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER3TRIG_TRIGIN(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER3TRIG_TRIGIN_SHIFT)) & INPUTMUX_TIMER3TRIG_TRIGIN_MASK)
/*! @} */

/*! @name TIMER4CAP - Capture select register for TIMER4 inputs */
/*! @{ */

#define INPUTMUX_TIMER4CAP_CAPTSEL_MASK          (0x3FU)
#define INPUTMUX_TIMER4CAP_CAPTSEL_SHIFT         (0U)
/*! CAPTSEL - Input number to TIMER4 capture inputs 0 to 5
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER4CAP_CAPTSEL(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER4CAP_CAPTSEL_SHIFT)) & INPUTMUX_TIMER4CAP_CAPTSEL_MASK)
/*! @} */

/*! @name TIMER4TRIG - Trigger register for TIMER4 */
/*! @{ */

#define INPUTMUX_TIMER4TRIG_TRIGIN_MASK          (0x3FU)
#define INPUTMUX_TIMER4TRIG_TRIGIN_SHIFT         (0U)
/*! TRIGIN - Input number to TIMER4 trigger inputs
 *  0b000000..CTIMER_INP0 function selected from IOCON register
 *  0b000001..CTIMER_INP1 function selected from IOCON register
 *  0b000010..CTIMER_INP2 function selected from IOCON register
 *  0b000011..CTIMER_INP3 function selected from IOCON register
 *  0b000100..CTIMER_INP4 function selected from IOCON register
 *  0b000101..CTIMER_INP5 function selected from IOCON register
 *  0b000110..CTIMER_INP6 function selected from IOCON register
 *  0b000111..CTIMER_INP7 function selected from IOCON register
 *  0b001000..CTIMER_INP8 function selected from IOCON register
 *  0b001001..CTIMER_INP9 function selected from IOCON register
 *  0b001010..CTIMER_INP10 function selected from IOCON register
 *  0b001011..CTIMER_INP11 function selected from IOCON register
 *  0b001100..CTIMER_INP12 function selected from IOCON register
 *  0b001101..CTIMER_INP13 function selected from IOCON register
 *  0b001110..CTIMER_INP14 function selected from IOCON register
 *  0b001111..CTIMER_INP15 function selected from IOCON register
 *  0b010000..CTIMER_INP16 function selected from IOCON register
 *  0b010001..CTIMER_INP17 function selected from IOCON register
 *  0b010010..CTIMER_INP18 function selected from IOCON register
 *  0b010011..CTIMER_INP19 function selected from IOCON register
 *  0b010100..USB0_FRAME_TOGGLE
 *  0b010101..Reserved
 *  0b010110..ACMP0_OUT from analog comparator
 *  0b010111..SHARED_I2S_WS0 output from I2S pin sharing
 *  0b011000..SHARED_I2S_WS1 output from I2S pin sharing
 *  0b011001..ADC0_IRQ
 *  0b011010..ADC1_IRQ
 *  0b011011..HSCMP0_OUT
 *  0b011100..HSCMP1_OUT
 *  0b011101..HSCMP2_OUT
 *  0b011110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b011111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b100000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b100010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b100011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b100101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b100110..ENC0_CMP/POS_MATCH
 *  0b100111..ENC1_CMP/POS_MATCH
 *  0b101000..AOI0_OUT0
 *  0b101001..AOI0_OUT1
 *  0b101010..AOI0_OUT2
 *  0b101011..AOI0_OUT3
 *  0b101100..AOI1_OUT0
 *  0b101101..AOI1_OUT1
 *  0b101110..AOI1_OUT2
 *  0b101111..AOI1_OUT3
 *  0b110000..TMPR_OUT
 *  0b110001-0b111111..None
 */
#define INPUTMUX_TIMER4TRIG_TRIGIN(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER4TRIG_TRIGIN_SHIFT)) & INPUTMUX_TIMER4TRIG_TRIGIN_MASK)
/*! @} */

/*! @name PINTSECSEL - Pin interrupt secure select */
/*! @{ */

#define INPUTMUX_PINTSECSEL_INTPIN_MASK          (0x3FU)
#define INPUTMUX_PINTSECSEL_INTPIN_SHIFT         (0U)
/*! INTPIN - Pin number select for pin interrupt secure or pattern match engine input. For PIO0_x:
 *    INTPIN = x. PIO0_0 to PIO0_31 correspond to numbers 0 to 31.
 */
#define INPUTMUX_PINTSECSEL_INTPIN(x)            (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PINTSECSEL_INTPIN_SHIFT)) & INPUTMUX_PINTSECSEL_INTPIN_MASK)
/*! @} */

/*! @name DMA1_ITRIG_INMUX - Trigger select for DMA1 channel */
/*! @{ */

#define INPUTMUX_DMA1_ITRIG_INMUX_INP_MASK       (0x1FU)
#define INPUTMUX_DMA1_ITRIG_INMUX_INP_SHIFT      (0U)
/*! INP - Trigger input number (binary value) for DMA channel n (n = 0 to 14).
 *  0b00000..Pin interrupt 0 (GPIO_INT0)
 *  0b00001..Pin interrupt 1 (GPIO_INT1)
 *  0b00010..Pin interrupt 2 (GPIO_INT2)
 *  0b00011..Pin interrupt 3 (GPIO_INT3)
 *  0b00100..Timer CTIMER0 Match 0 (T0_DMAREQ_M0)
 *  0b00101..Timer CTIMER0 Match 1 (T0_DMAREQ_M1)
 *  0b00110..Timer CTIMER2 Match 0 (T2_DMAREQ_M0)
 *  0b00111..Timer CTIMER4 Match 0 (T4_DMAREQ_M0)
 *  0b01000..SDMA1_TRIGOUT_A
 *  0b01001..SDMA1_TRIGOUT_B
 *  0b01010..SDMA1_TRIGOUT_C
 *  0b01011..SDMA1_TRIGOUT_D
 *  0b01100..SCT_DMA_REQ0
 *  0b01101..SCT_DMA_REQ1
 *  0b01110..FlexSPI_RX
 *  0b01111..FlexSPI_TX
 *  0b10000..AOI0_OUT0
 *  0b10001..AOI0_OUT1
 *  0b10010..AOI0_OUT2
 *  0b10011..AOI0_OUT3
 *  0b10100..AOI1_OUT0
 *  0b10101..AOI1_OUT1
 *  0b10110..AOI1_OUT2
 *  0b10111..AOI1_OUT3
 *  0b11000..TMPR_OUT
 *  0b11001-0b11111..Reserved
 */
#define INPUTMUX_DMA1_ITRIG_INMUX_INP(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIG_INMUX_INP_SHIFT)) & INPUTMUX_DMA1_ITRIG_INMUX_INP_MASK)
/*! @} */

/*! @name DMA1_OTRIG_INMUX - DMA1 output trigger selection for DMA1 input trigger */
/*! @{ */

#define INPUTMUX_DMA1_OTRIG_INMUX_SDMA1_CH_TRIGOUT_MASK (0xFU)
#define INPUTMUX_DMA1_OTRIG_INMUX_SDMA1_CH_TRIGOUT_SHIFT (0U)
/*! SDMA1_CH_TRIGOUT - DMA trigger output number (binary value) for DMA channel n (n = 0 to 15).
 *  0b0000..SDMA1_CH0_TRIGOUT
 *  0b0001..SDMA1_CH1_TRIGOUT
 *  0b0010..SDMA1_CH2_TRIGOUT
 *  0b0011..SDMA1_CH3_TRIGOUT
 *  0b0100..SDMA1_CH4_TRIGOUT
 *  0b0101..SDMA1_CH5_TRIGOUT
 *  0b0110..SDMA1_CH6_TRIGOUT
 *  0b0111..SDMA1_CH7_TRIGOUT
 *  0b1000..SDMA1_CH8_TRIGOUT
 *  0b1001..SDMA1_CH9_TRIGOUT
 *  0b1010..SDMA1_CH10_TRIGOUT
 *  0b1011..SDMA1_CH11_TRIGOUT
 *  0b1100..SDMA1_CH12_TRIGOUT
 *  0b1101..SDMA1_CH13_TRIGOUT
 *  0b1110-0b1111..Reserved
 */
#define INPUTMUX_DMA1_OTRIG_INMUX_SDMA1_CH_TRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_OTRIG_INMUX_SDMA1_CH_TRIGOUT_SHIFT)) & INPUTMUX_DMA1_OTRIG_INMUX_SDMA1_CH_TRIGOUT_MASK)
/*! @} */

/*! @name HSCMP0_TRIG - Input connections for HSCMP0 */
/*! @{ */

#define INPUTMUX_HSCMP0_TRIG_TRIGIN_MASK         (0x3FU)
#define INPUTMUX_HSCMP0_TRIG_TRIGIN_SHIFT        (0U)
/*! TRIGIN - CMP0 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT6
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT6
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T0_MAT0
 *  0b001001..T4_MAT0
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC1_tcomp[0]
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b010010..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b010011..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b010100..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b010101..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b010110..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b010111..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b011000..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b011001..ENC0_CMP/POS_MATCH
 *  0b011010..ENC1_CMP/POS_MATCH
 *  0b011011..AOI0_OUT0
 *  0b011100..AOI0_OUT1
 *  0b011101..AOI0_OUT2
 *  0b011110..AOI0_OUT3
 *  0b011111..AOI1_OUT0
 *  0b100000..AOI1_OUT1
 *  0b100001..AOI1_OUT2
 *  0b100010..AOI1_OUT3
 *  0b100011..DMA0_TRIGOUT0
 *  0b100100..DMA0_TRIGOUT1
 *  0b100101..DMA0_TRIGOUT2
 */
#define INPUTMUX_HSCMP0_TRIG_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_HSCMP0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_HSCMP0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ADC0_TRIGN_ADC0_TRIG - ADC0 Trigger input connections */
/*! @{ */

#define INPUTMUX_ADC0_TRIGN_ADC0_TRIG_TRIGIN_MASK (0x3FU)
#define INPUTMUX_ADC0_TRIGN_ADC0_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC0 trigger inputs
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT1
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT9
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T3_MAT3
 *  0b001001..T4_MAT3
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM0_SM0_MUX_TRIG0
 *  0b011001..PWM0_SM0_MUX_TRIG1
 *  0b011010..PWM0_SM1_MUX_TRIG0
 *  0b011011..PWM0_SM1_MUX_TRIG1
 *  0b011100..PWM0_SM2_MUX_TRIG0
 *  0b011101..PWM0_SM2_MUX_TRIG1
 *  0b011110..PWM0_SM3_MUX_TRIG0
 *  0b011111..PWM0_SM3_MUX_TRIG1
 *  0b100000..PWM1_SM0_MUX_TRIG0
 *  0b100001..PWM1_SM0_MUX_TRIG1
 *  0b100010..PWM1_SM1_MUX_TRIG0
 *  0b100011..PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0
 *  0b100101..PWM1_SM2_MUX_TRIG1
 *  0b100110..PWM1_SM3_MUX_TRIG0
 *  0b100111..PWM1_SM3_MUX_TRIG1
 *  0b101000..ENC0_CMP/POS_MATCH
 *  0b101001..ENC1_CMP/POS_MATCH
 *  0b101010..AOI0_OUT0
 *  0b101011..AOI0_OUT1
 *  0b101100..AOI0_OUT2
 *  0b101101..AOI0_OUT3
 *  0b101110..AOI1_OUT0
 *  0b101111..AOI1_OUT1
 *  0b110000..AOI1_OUT2
 *  0b110001..AOI1_OUT3
 *  0b110010..DMA0_TRIGOUT0
 *  0b110011..DMA0_TRIGOUT1
 *  0b110100..DMA0_TRIGOUT2
 *  0b110101-0b111111..None
 */
#define INPUTMUX_ADC0_TRIGN_ADC0_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC0_TRIGN_ADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC0_TRIGN_ADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC0_TRIGN_ADC0_TRIG */
#define INPUTMUX_ADC0_TRIGN_ADC0_TRIG_COUNT      (4U)

/*! @name ADC1_TRIGN_ADC1_TRIG - ADC1 Trigger input connections */
/*! @{ */

#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_MASK (0x3FU)
#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC1 trigger inputs
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT2
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT3
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T3_MAT2
 *  0b001001..T4_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM0_SM0_MUX_TRIG0
 *  0b011001..PWM0_SM0_MUX_TRIG1
 *  0b011010..PWM0_SM1_MUX_TRIG0
 *  0b011011..PWM0_SM1_MUX_TRIG1
 *  0b011100..PWM0_SM2_MUX_TRIG0
 *  0b011101..PWM0_SM2_MUX_TRIG1
 *  0b011110..PWM0_SM3_MUX_TRIG0
 *  0b011111..PWM0_SM3_MUX_TRIG1
 *  0b100000..PWM1_SM0_MUX_TRIG0
 *  0b100001..PWM1_SM0_MUX_TRIG1
 *  0b100010..PWM1_SM1_MUX_TRIG0
 *  0b100011..PWM1_SM1_MUX_TRIG1
 *  0b100100..PWM1_SM2_MUX_TRIG0
 *  0b100101..PWM1_SM2_MUX_TRIG1
 *  0b100110..PWM1_SM3_MUX_TRIG0
 *  0b100111..PWM1_SM3_MUX_TRIG1
 *  0b101000..ENC0_CMP/POS_MATCH
 *  0b101001..ENC1_CMP/POS_MATCH
 *  0b101010..AOI0_OUT0
 *  0b101011..AOI0_OUT1
 *  0b101100..AOI0_OUT2
 *  0b101101..AOI0_OUT3
 *  0b101110..AOI1_OUT0
 *  0b101111..AOI1_OUT1
 *  0b110000..AOI1_OUT2
 *  0b110001..AOI1_OUT3
 *  0b110010..DMA0_TRIGOUT0
 *  0b110011..DMA0_TRIGOUT1
 *  0b110100..DMA0_TRIGOUT2
 *  0b110101-0b111111..None
 */
#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC1_TRIGN_ADC1_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC1_TRIGN_ADC1_TRIG */
#define INPUTMUX_ADC1_TRIGN_ADC1_TRIG_COUNT      (4U)

/*! @name DAC0_TRIG - DAC0 Trigger Inputs */
/*! @{ */

#define INPUTMUX_DAC0_TRIG_TRIGIN_MASK           (0x1FU)
#define INPUTMUX_DAC0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - DAC0 trigger input
 *  0b00000..PIN_INT0
 *  0b00001..PIN_INT3
 *  0b00010..SCT_OUT4
 *  0b00011..SCT_OUT5
 *  0b00100..SCT_OUT0
 *  0b00101..T0_MAT3
 *  0b00110..T1_MAT3
 *  0b00111..T2_MAT3
 *  0b01000..T2_MAT0
 *  0b01001..T3_MAT0
 *  0b01010..ACMP0_OUT
 *  0b01011..ARM_TXEV
 *  0b01100..GPIOINT_BMATCH
 *  0b01101..ADC0_tcomp[0]
 *  0b01110..ADC1_tcomp[0]
 *  0b01111..HSCMP0_OUT
 *  0b10000..HSCMP1_OUT
 *  0b10001..HSCMP2_OUT
 *  0b10010..AOI0_OUT0
 *  0b10011..AOI0_OUT1
 *  0b10100..AOI0_OUT2
 *  0b10101..AOI0_OUT3
 *  0b10110..AOI1_OUT0
 *  0b10111..AOI1_OUT1
 *  0b11000..AOI1_OUT2
 *  0b11001..AOI1_OUT3
 *  0b11010..DMA0_TRIGOUT0
 *  0b11011..DMA0_TRIGOUT1
 *  0b11100..DMA0_TRIGOUT2
 */
#define INPUTMUX_DAC0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DAC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_DAC0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name DAC1_TRIG - DAC1 Trigger Inputs */
/*! @{ */

#define INPUTMUX_DAC1_TRIG_TRIGIN_MASK           (0x1FU)
#define INPUTMUX_DAC1_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - DAC1 trigger input
 *  0b00000..PIN_INT0
 *  0b00001..PIN_INT4
 *  0b00010..SCT_OUT4
 *  0b00011..SCT_OUT5
 *  0b00100..SCT_OUT1
 *  0b00101..T0_MAT3
 *  0b00110..T1_MAT3
 *  0b00111..T2_MAT3
 *  0b01000..T2_MAT1
 *  0b01001..T3_MAT1
 *  0b01010..ACMP0_OUT
 *  0b01011..ARM_TXEV
 *  0b01100..GPIOINT_BMATCH
 *  0b01101..ADC0_tcomp[1]
 *  0b01110..ADC1_tcomp[1]
 *  0b01111..HSCMP0_OUT
 *  0b10000..HSCMP1_OUT
 *  0b10001..HSCMP2_OUT
 *  0b10010..AOI0_OUT0
 *  0b10011..AOI0_OUT1
 *  0b10100..AOI0_OUT2
 *  0b10101..AOI0_OUT3
 *  0b10110..AOI1_OUT0
 *  0b10111..AOI1_OUT1
 *  0b11000..AOI1_OUT2
 *  0b11001..AOI1_OUT3
 *  0b11010..DMA0_TRIGOUT0
 *  0b11011..DMA0_TRIGOUT1
 *  0b11100..DMA0_TRIGOUT2
 */
#define INPUTMUX_DAC1_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DAC1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_DAC1_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name DAC2_TRIG - DAC2 Trigger Inputs */
/*! @{ */

#define INPUTMUX_DAC2_TRIG_TRIGIN_MASK           (0x1FU)
#define INPUTMUX_DAC2_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - DAC2 trigger input
 *  0b00000..PIN_INT0
 *  0b00001..PIN_INT5
 *  0b00010..SCT_OUT4
 *  0b00011..SCT_OUT5
 *  0b00100..SCT_OUT2
 *  0b00101..T0_MAT3
 *  0b00110..T1_MAT3
 *  0b00111..T2_MAT3
 *  0b01000..T2_MAT2
 *  0b01001..T3_MAT2
 *  0b01010..ACMP0_OUT
 *  0b01011..ARM_TXEV
 *  0b01100..GPIOINT_BMATCH
 *  0b01101..ADC0_tcomp[2]
 *  0b01110..ADC1_tcomp[2]
 *  0b01111..HSCMP0_OUT
 *  0b10000..HSCMP1_OUT
 *  0b10001..HSCMP2_OUT
 *  0b10010..AOI0_OUT0
 *  0b10011..AOI0_OUT1
 *  0b10100..AOI0_OUT2
 *  0b10101..AOI0_OUT3
 *  0b10110..AOI1_OUT0
 *  0b10111..AOI1_OUT1
 *  0b11000..AOI1_OUT2
 *  0b11001..AOI1_OUT3
 *  0b11010..DMA0_TRIGOUT0
 *  0b11011..DMA0_TRIGOUT1
 *  0b11100..DMA0_TRIGOUT2
 */
#define INPUTMUX_DAC2_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DAC2_TRIG_TRIGIN_SHIFT)) & INPUTMUX_DAC2_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ENC0_TRIG - ENC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_ENC0_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_ENC0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - ENC0 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT4
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT1
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT0
 *  0b001001..T3_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ENC0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ENC0_HOME - ENC0 Input Connections */
/*! @{ */

#define INPUTMUX_ENC0_HOME_ENC0_HOME_MASK        (0x3FU)
#define INPUTMUX_ENC0_HOME_ENC0_HOME_SHIFT       (0U)
/*! ENC0_HOME - ENC0 Input Connections
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT4
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT1
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT0
 *  0b001001..T3_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM0_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC0_HOME_ENC0_HOME(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC0_HOME_ENC0_HOME_SHIFT)) & INPUTMUX_ENC0_HOME_ENC0_HOME_MASK)
/*! @} */

/*! @name ENC0_INDEX - ENC0 Input Connections */
/*! @{ */

#define INPUTMUX_ENC0_INDEX_ENC0_INDEX_MASK      (0x3FU)
#define INPUTMUX_ENC0_INDEX_ENC0_INDEX_SHIFT     (0U)
/*! ENC0_INDEX - ENC0 Input Connections
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT4
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT1
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT0
 *  0b001001..T3_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC0_INDEX_ENC0_INDEX(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC0_INDEX_ENC0_INDEX_SHIFT)) & INPUTMUX_ENC0_INDEX_ENC0_INDEX_MASK)
/*! @} */

/*! @name ENC0_PHASEB - ENC0 Input Connections */
/*! @{ */

#define INPUTMUX_ENC0_PHASEB_ENC0_PHASEB_MASK    (0x3FU)
#define INPUTMUX_ENC0_PHASEB_ENC0_PHASEB_SHIFT   (0U)
/*! ENC0_PHASEB - ENC0 Input Connections
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT4
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT1
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT0
 *  0b001001..T3_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC0_PHASEB_ENC0_PHASEB(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC0_PHASEB_ENC0_PHASEB_SHIFT)) & INPUTMUX_ENC0_PHASEB_ENC0_PHASEB_MASK)
/*! @} */

/*! @name ENC0_PHASEA - ENC0 Input Connections */
/*! @{ */

#define INPUTMUX_ENC0_PHASEA_ENC0_PHASEA_MASK    (0x3FU)
#define INPUTMUX_ENC0_PHASEA_ENC0_PHASEA_SHIFT   (0U)
/*! ENC0_PHASEA - ENC0 Input Connections
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT4
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT1
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT0
 *  0b001001..T3_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC0_PHASEA_ENC0_PHASEA(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC0_PHASEA_ENC0_PHASEA_SHIFT)) & INPUTMUX_ENC0_PHASEA_ENC0_PHASEA_MASK)
/*! @} */

/*! @name ENC1_TRIG - ENC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_ENC1_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_ENC1_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - ENC1 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT7
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT1
 *  0b001001..T3_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC1_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ENC1_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ENC1_HOME - ENC1 Input Connections */
/*! @{ */

#define INPUTMUX_ENC1_HOME_ENC1_HOME_MASK        (0x3FU)
#define INPUTMUX_ENC1_HOME_ENC1_HOME_SHIFT       (0U)
/*! ENC1_HOME - ENC1 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT7
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT1
 *  0b001001..T3_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC1_HOME_ENC1_HOME(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC1_HOME_ENC1_HOME_SHIFT)) & INPUTMUX_ENC1_HOME_ENC1_HOME_MASK)
/*! @} */

/*! @name ENC1_INDEX - ENC1 Input Connections */
/*! @{ */

#define INPUTMUX_ENC1_INDEX_ENC1_INDEX_MASK      (0x3FU)
#define INPUTMUX_ENC1_INDEX_ENC1_INDEX_SHIFT     (0U)
/*! ENC1_INDEX - ENC1 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT7
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT1
 *  0b001001..T3_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC1_INDEX_ENC1_INDEX(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC1_INDEX_ENC1_INDEX_SHIFT)) & INPUTMUX_ENC1_INDEX_ENC1_INDEX_MASK)
/*! @} */

/*! @name ENC1_PHASEB - ENC1 Input Connections */
/*! @{ */

#define INPUTMUX_ENC1_PHASEB_ENC1_PHASEB_MASK    (0x3FU)
#define INPUTMUX_ENC1_PHASEB_ENC1_PHASEB_SHIFT   (0U)
/*! ENC1_PHASEB - ENC1 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT7
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT1
 *  0b001001..T3_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC1_PHASEB_ENC1_PHASEB(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC1_PHASEB_ENC1_PHASEB_SHIFT)) & INPUTMUX_ENC1_PHASEB_ENC1_PHASEB_MASK)
/*! @} */

/*! @name ENC1_PHASEA - ENC1 Input Connections */
/*! @{ */

#define INPUTMUX_ENC1_PHASEA_ENC1_PHASEA_MASK    (0x3FU)
#define INPUTMUX_ENC1_PHASEA_ENC1_PHASEA_SHIFT   (0U)
/*! ENC1_PHASEA - ENC1 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT7
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T1_MAT1
 *  0b001001..T3_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_ENC1_PHASEA_ENC1_PHASEA(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ENC1_PHASEA_ENC1_PHASEA_SHIFT)) & INPUTMUX_ENC1_PHASEA_ENC1_PHASEA_MASK)
/*! @} */

/*! @name PWM0_EXTSYNCN_PWM0_EXTSYNC - PWM0 external synchronization */
/*! @{ */

#define INPUTMUX_PWM0_EXTSYNCN_PWM0_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_PWM0_EXTSYNCN_PWM0_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT2
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT0
 *  0b001001..T4_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM0_EXTSYNCN_PWM0_EXTSYNC_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXTSYNCN_PWM0_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_PWM0_EXTSYNCN_PWM0_EXTSYNC_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_PWM0_EXTSYNCN_PWM0_EXTSYNC */
#define INPUTMUX_PWM0_EXTSYNCN_PWM0_EXTSYNC_COUNT (4U)

/*! @name PWM0_EXTAN_PWM0_EXTA - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_PWM0_EXTAN_PWM0_EXTA_TRIGIN_MASK (0x3FU)
#define INPUTMUX_PWM0_EXTAN_PWM0_EXTA_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT2
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT0
 *  0b001001..T4_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM0_EXTAN_PWM0_EXTA_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXTAN_PWM0_EXTA_TRIGIN_SHIFT)) & INPUTMUX_PWM0_EXTAN_PWM0_EXTA_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_PWM0_EXTAN_PWM0_EXTA */
#define INPUTMUX_PWM0_EXTAN_PWM0_EXTA_COUNT      (4U)

/*! @name PWM0_EXTFORCE - PWM0 external force trigger connections */
/*! @{ */

#define INPUTMUX_PWM0_EXTFORCE_TRIGIN_MASK       (0x3FU)
#define INPUTMUX_PWM0_EXTFORCE_TRIGIN_SHIFT      (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT2
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT0
 *  0b001001..T4_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM0_EXTFORCE_TRIGIN(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXTFORCE_TRIGIN_SHIFT)) & INPUTMUX_PWM0_EXTFORCE_TRIGIN_MASK)
/*! @} */

/*! @name PWM0_FAULTN_PWM0_FAULT - PWM0 fault input trigger connections */
/*! @{ */

#define INPUTMUX_PWM0_FAULTN_PWM0_FAULT_TRIGIN_MASK (0x3FU)
#define INPUTMUX_PWM0_FAULTN_PWM0_FAULT_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT2
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT0
 *  0b001001..T4_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM0_FAULTN_PWM0_FAULT_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_FAULTN_PWM0_FAULT_TRIGIN_SHIFT)) & INPUTMUX_PWM0_FAULTN_PWM0_FAULT_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_PWM0_FAULTN_PWM0_FAULT */
#define INPUTMUX_PWM0_FAULTN_PWM0_FAULT_COUNT    (4U)

/*! @name PWM1_EXTSYNCN_PWM1_EXTSYNC - PWM1 external synchronization */
/*! @{ */

#define INPUTMUX_PWM1_EXTSYNCN_PWM1_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_PWM1_EXTSYNCN_PWM1_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM1
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT2
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT3
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT1
 *  0b001001..T4_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM0_SM0_MUX_TRIG0
 *  0b011001..PWM0_SM0_MUX_TRIG1
 *  0b011010..PWM0_SM1_MUX_TRIG0
 *  0b011011..PWM0_SM1_MUX_TRIG1
 *  0b011100..PWM0_SM2_MUX_TRIG0
 *  0b011101..PWM0_SM2_MUX_TRIG1
 *  0b011110..PWM0_SM3_MUX_TRIG0
 *  0b011111..PWM0_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM1_EXTSYNCN_PWM1_EXTSYNC_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM1_EXTSYNCN_PWM1_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_PWM1_EXTSYNCN_PWM1_EXTSYNC_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_PWM1_EXTSYNCN_PWM1_EXTSYNC */
#define INPUTMUX_PWM1_EXTSYNCN_PWM1_EXTSYNC_COUNT (4U)

/*! @name PWM1_EXTAN_PWM1_EXTA - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_PWM1_EXTAN_PWM1_EXTA_TRIGIN_MASK (0x3FU)
#define INPUTMUX_PWM1_EXTAN_PWM1_EXTA_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM1
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT2
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT3
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT1
 *  0b001001..T4_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM0_SM0_MUX_TRIG0
 *  0b011001..PWM0_SM0_MUX_TRIG1
 *  0b011010..PWM0_SM1_MUX_TRIG0
 *  0b011011..PWM0_SM1_MUX_TRIG1
 *  0b011100..PWM0_SM2_MUX_TRIG0
 *  0b011101..PWM0_SM2_MUX_TRIG1
 *  0b011110..PWM0_SM3_MUX_TRIG0
 *  0b011111..PWM0_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM1_EXTAN_PWM1_EXTA_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM1_EXTAN_PWM1_EXTA_TRIGIN_SHIFT)) & INPUTMUX_PWM1_EXTAN_PWM1_EXTA_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_PWM1_EXTAN_PWM1_EXTA */
#define INPUTMUX_PWM1_EXTAN_PWM1_EXTA_COUNT      (4U)

/*! @name PWM1_EXTFORCE - PWM1 external force trigger connections */
/*! @{ */

#define INPUTMUX_PWM1_EXTFORCE_TRIGIN_MASK       (0x3FU)
#define INPUTMUX_PWM1_EXTFORCE_TRIGIN_SHIFT      (0U)
/*! TRIGIN - Trigger input connections for PWM1
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT2
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT3
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT1
 *  0b001001..T4_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM0_SM0_MUX_TRIG0
 *  0b011001..PWM0_SM0_MUX_TRIG1
 *  0b011010..PWM0_SM1_MUX_TRIG0
 *  0b011011..PWM0_SM1_MUX_TRIG1
 *  0b011100..PWM0_SM2_MUX_TRIG0
 *  0b011101..PWM0_SM2_MUX_TRIG1
 *  0b011110..PWM0_SM3_MUX_TRIG0
 *  0b011111..PWM0_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM1_EXTFORCE_TRIGIN(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM1_EXTFORCE_TRIGIN_SHIFT)) & INPUTMUX_PWM1_EXTFORCE_TRIGIN_MASK)
/*! @} */

/*! @name PWM1_FAULTN_PWM1_FAULT - PWM1 fault input trigger connections */
/*! @{ */

#define INPUTMUX_PWM1_FAULTN_PWM1_FAULT_TRIGIN_MASK (0x3FU)
#define INPUTMUX_PWM1_FAULTN_PWM1_FAULT_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for PWM1
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT2
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT3
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT1
 *  0b001001..T4_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM0_SM0_MUX_TRIG0
 *  0b011001..PWM0_SM0_MUX_TRIG1
 *  0b011010..PWM0_SM1_MUX_TRIG0
 *  0b011011..PWM0_SM1_MUX_TRIG1
 *  0b011100..PWM0_SM2_MUX_TRIG0
 *  0b011101..PWM0_SM2_MUX_TRIG1
 *  0b011110..PWM0_SM3_MUX_TRIG0
 *  0b011111..PWM0_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM1_FAULTN_PWM1_FAULT_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM1_FAULTN_PWM1_FAULT_TRIGIN_SHIFT)) & INPUTMUX_PWM1_FAULTN_PWM1_FAULT_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_PWM1_FAULTN_PWM1_FAULT */
#define INPUTMUX_PWM1_FAULTN_PWM1_FAULT_COUNT    (4U)

/*! @name PWM0_EXTCLK - PWM0 external clock trigger connections */
/*! @{ */

#define INPUTMUX_PWM0_EXTCLK_TRIGIN_MASK         (0x3FU)
#define INPUTMUX_PWM0_EXTCLK_TRIGIN_SHIFT        (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT5
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT2
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT0
 *  0b001001..T4_MAT0
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM1_SM0_MUX_TRIG0
 *  0b011001..PWM1_SM0_MUX_TRIG1
 *  0b011010..PWM1_SM1_MUX_TRIG0
 *  0b011011..PWM1_SM1_MUX_TRIG1
 *  0b011100..PWM1_SM2_MUX_TRIG0
 *  0b011101..PWM1_SM2_MUX_TRIG1
 *  0b011110..PWM1_SM3_MUX_TRIG0
 *  0b011111..PWM1_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM0_EXTCLK_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXTCLK_TRIGIN_SHIFT)) & INPUTMUX_PWM0_EXTCLK_TRIGIN_MASK)
/*! @} */

/*! @name PWM1_EXTCLK - PWM1 external clock trigger connections */
/*! @{ */

#define INPUTMUX_PWM1_EXTCLK_TRIGIN_MASK         (0x3FU)
#define INPUTMUX_PWM1_EXTCLK_TRIGIN_SHIFT        (0U)
/*! TRIGIN - Trigger input connections for PWM1
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT2
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT3
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T2_MAT1
 *  0b001001..T4_MAT1
 *  0b001010..ACMP0_OUT
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[0]
 *  0b001110..ADC0_tcomp[1]
 *  0b001111..ADC0_tcomp[2]
 *  0b010000..ADC0_tcomp[3]
 *  0b010001..ADC1_tcomp[0]
 *  0b010010..ADC1_tcomp[1]
 *  0b010011..ADC1_tcomp[2]
 *  0b010100..ADC1_tcomp[3]
 *  0b010101..HSCMP0_OUT
 *  0b010110..HSCMP1_OUT
 *  0b010111..HSCMP2_OUT
 *  0b011000..PWM0_SM0_MUX_TRIG0
 *  0b011001..PWM0_SM0_MUX_TRIG1
 *  0b011010..PWM0_SM1_MUX_TRIG0
 *  0b011011..PWM0_SM1_MUX_TRIG1
 *  0b011100..PWM0_SM2_MUX_TRIG0
 *  0b011101..PWM0_SM2_MUX_TRIG1
 *  0b011110..PWM0_SM3_MUX_TRIG0
 *  0b011111..PWM0_SM3_MUX_TRIG1
 *  0b100000..ENC0_CMP/POS_MATCH
 *  0b100001..ENC1_CMP/POS_MATCH
 *  0b100010..AOI0_OUT0
 *  0b100011..AOI0_OUT1
 *  0b100100..AOI0_OUT2
 *  0b100101..AOI0_OUT3
 *  0b100110..AOI1_OUT0
 *  0b100111..AOI1_OUT1
 *  0b101000..AOI1_OUT2
 *  0b101001..AOI1_OUT3
 *  0b101010..EXTTRIG_IN0
 *  0b101011..EXTTRIG_IN1
 *  0b101100..EXTTRIG_IN2
 *  0b101101..EXTTRIG_IN3
 *  0b101110..EXTTRIG_IN4
 *  0b101111..EXTTRIG_IN5
 *  0b110000..EXTTRIG_IN6
 *  0b110001..EXTTRIG_IN7
 *  0b110010..EXTTRIG_IN8
 *  0b110011..EXTTRIG_IN9
 *  0b110100..DMA0_TRIGOUT0
 *  0b110101..DMA0_TRIGOUT1
 *  0b110110..DMA0_TRIGOUT2
 */
#define INPUTMUX_PWM1_EXTCLK_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM1_EXTCLK_TRIGIN_SHIFT)) & INPUTMUX_PWM1_EXTCLK_TRIGIN_MASK)
/*! @} */

/*! @name AOI0_IN - AOI0 trigger inputs */
/*! @{ */

#define INPUTMUX_AOI0_IN_IN_MASK                 (0x3FU)
#define INPUTMUX_AOI0_IN_IN_SHIFT                (0U)
/*! IN - Input trigger assignments
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT1
 *  0b000010..SCT_OUT0
 *  0b000011..SCT_OUT1
 *  0b000100..SCT_OUT2
 *  0b000101..SCT_OUT3
 *  0b000110..T0_MAT3
 *  0b000111..T1_MAT3
 *  0b001000..T2_MAT3
 *  0b001001..T2_MAT2
 *  0b001010..T3_MAT2
 *  0b001011..T4_MAT2
 *  0b001100..ACMP0_OUT
 *  0b001101..GPIOINT_BMATCH
 *  0b001110..ADC0_IRQ
 *  0b001111..ADC1_IRQ
 *  0b010000..ADC0_tcomp[0]
 *  0b010001..ADC0_tcomp[1]
 *  0b010010..ADC0_tcomp[2]
 *  0b010011..ADC0_tcomp[3]
 *  0b010100..ADC1_tcomp[0]
 *  0b010101..ADC1_tcomp[1]
 *  0b010110..ADC1_tcomp[2]
 *  0b010111..ADC1_tcomp[3]
 *  0b011000..HSCMP0_OUT
 *  0b011001..HSCMP1_OUT
 *  0b011010..HSCMP2_OUT
 *  0b011011..PWM0_SM0_MUX_TRIG0
 *  0b011100..PWM0_SM0_MUX_TRIG1
 *  0b011101..PWM0_SM1_MUX_TRIG0
 *  0b011110..PWM0_SM1_MUX_TRIG1
 *  0b011111..PWM0_SM2_MUX_TRIG0
 *  0b100000..PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0
 *  0b100010..PWM0_SM3_MUX_TRIG1
 *  0b100011..PWM1_SM0_MUX_TRIG0
 *  0b100100..PWM1_SM0_MUX_TRIG1
 *  0b100101..PWM1_SM1_MUX_TRIG0
 *  0b100110..PWM1_SM1_MUX_TRIG1
 *  0b100111..PWM1_SM2_MUX_TRIG0
 *  0b101000..PWM1_SM2_MUX_TRIG1
 *  0b101001..PWM1_SM3_MUX_TRIG0
 *  0b101010..PWM1_SM3_MUX_TRIG1
 *  0b101011..ENC0_CMP/POS_MATCH
 *  0b101100..ENC1_CMP/POS_MATCH
 *  0b101101..EXTTRIG_IN0
 *  0b101110..EXTTRIG_IN1
 *  0b101111..EXTTRIG_IN2
 *  0b110000..EXTTRIG_IN3
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..DMA0_TRIGOUT0
 *  0b110100..DMA0_TRIGOUT1
 *  0b110101..DMA0_TRIGOUT2
 *  0b110110..DMA0_TRIGOUT3
 *  0b110111..DMA0_TRIGOUT4
 *  0b111000..DMA0_TRIGOUT5
 *  0b111001..DMA0_TRIGOUT6
 *  0b111010..DMA1_TRIGOUT0
 *  0b111011..DMA1_TRIGOUT1
 *  0b111100..DMA1_TRIGOUT2
 */
#define INPUTMUX_AOI0_IN_IN(x)                   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AOI0_IN_IN_SHIFT)) & INPUTMUX_AOI0_IN_IN_MASK)
/*! @} */

/* The count of INPUTMUX_AOI0_IN */
#define INPUTMUX_AOI0_INPUTTRIGGER0              (16U)

/*! @name AOI1_IN - AOI1 trigger inputs */
/*! @{ */

#define INPUTMUX_AOI1_IN_IN_MASK                 (0x3FU)
#define INPUTMUX_AOI1_IN_IN_SHIFT                (0U)
/*! IN - Input trigger assignments
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT1
 *  0b000010..SCT_OUT0
 *  0b000011..SCT_OUT1
 *  0b000100..SCT_OUT2
 *  0b000101..SCT_OUT3
 *  0b000110..T0_MAT3
 *  0b000111..T1_MAT3
 *  0b001000..T2_MAT3
 *  0b001001..T2_MAT2
 *  0b001010..T3_MAT2
 *  0b001011..T4_MAT2
 *  0b001100..ACMP0_OUT
 *  0b001101..GPIOINT_BMATCH
 *  0b001110..ADC0_IRQ
 *  0b001111..ADC1_IRQ
 *  0b010000..ADC0_tcomp[0]
 *  0b010001..ADC0_tcomp[1]
 *  0b010010..ADC0_tcomp[2]
 *  0b010011..ADC0_tcomp[3]
 *  0b010100..ADC1_tcomp[0]
 *  0b010101..ADC1_tcomp[1]
 *  0b010110..ADC1_tcomp[2]
 *  0b010111..ADC1_tcomp[3]
 *  0b011000..HSCMP0_OUT
 *  0b011001..HSCMP1_OUT
 *  0b011010..HSCMP2_OUT
 *  0b011011..PWM0_SM0_MUX_TRIG0
 *  0b011100..PWM0_SM0_MUX_TRIG1
 *  0b011101..PWM0_SM1_MUX_TRIG0
 *  0b011110..PWM0_SM1_MUX_TRIG1
 *  0b011111..PWM0_SM2_MUX_TRIG0
 *  0b100000..PWM0_SM2_MUX_TRIG1
 *  0b100001..PWM0_SM3_MUX_TRIG0
 *  0b100010..PWM0_SM3_MUX_TRIG1
 *  0b100011..PWM1_SM0_MUX_TRIG0
 *  0b100100..PWM1_SM0_MUX_TRIG1
 *  0b100101..PWM1_SM1_MUX_TRIG0
 *  0b100110..PWM1_SM1_MUX_TRIG1
 *  0b100111..PWM1_SM2_MUX_TRIG0
 *  0b101000..PWM1_SM2_MUX_TRIG1
 *  0b101001..PWM1_SM3_MUX_TRIG0
 *  0b101010..PWM1_SM3_MUX_TRIG1
 *  0b101011..ENC0_CMP/POS_MATCH
 *  0b101100..ENC1_CMP/POS_MATCH
 *  0b101101..EXTTRIG_IN0
 *  0b101110..EXTTRIG_IN1
 *  0b101111..EXTTRIG_IN2
 *  0b110000..EXTTRIG_IN3
 *  0b110001..Reserved
 *  0b110010..Reserved
 *  0b110011..DMA0_TRIGOUT0
 *  0b110100..DMA0_TRIGOUT1
 *  0b110101..DMA0_TRIGOUT2
 *  0b110110..DMA0_TRIGOUT3
 *  0b110111..DMA0_TRIGOUT4
 *  0b111000..DMA0_TRIGOUT5
 *  0b111001..DMA0_TRIGOUT6
 *  0b111010..DMA1_TRIGOUT0
 *  0b111011..DMA1_TRIGOUT1
 *  0b111100..DMA1_TRIGOUT2
 */
#define INPUTMUX_AOI1_IN_IN(x)                   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AOI1_IN_IN_SHIFT)) & INPUTMUX_AOI1_IN_IN_MASK)
/*! @} */

/* The count of INPUTMUX_AOI1_IN */
#define INPUTMUX_AOI1_INPUTTRIGGER0              (16U)

/*! @name AOIX_EXT_TRIGN_AOI_EXT_TRIG - AOI External Trigger Inputs */
/*! @{ */

#define INPUTMUX_AOIX_EXT_TRIGN_AOI_EXT_TRIG_TRIGIN_MASK (0x1FU)
#define INPUTMUX_AOIX_EXT_TRIGN_AOI_EXT_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - AOI external trigger inputs from 0 to 4.
 *  0b00000..PIN_INT0
 *  0b00001..PIN_INT1
 *  0b00010..ADC0_IRQ
 *  0b00011..ADC1_IRQ
 *  0b00100..ADC0_tcomp[0]
 *  0b00101..ADC1_tcomp[0]
 *  0b00110..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b00111..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b01000..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b01001..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b01010..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b01011..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b01100..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b01101..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b01110..ENC0_CMP/POS_MATCH
 *  0b01111..ENC1_CMP/POS_MATCH
 *  0b10000..AOI0_OUT0
 *  0b10001..AOI0_OUT1
 *  0b10010..AOI0_OUT2
 *  0b10011..AOI0_OUT3
 *  0b10100..AOI1_OUT0
 *  0b10101..AOI1_OUT1
 *  0b10110..AOI1_OUT2
 *  0b10111..AOI1_OUT3
 *  0b11000..TMPR_OUT
 *  0b11001-0b11111..None
 */
#define INPUTMUX_AOIX_EXT_TRIGN_AOI_EXT_TRIG_TRIGIN(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AOIX_EXT_TRIGN_AOI_EXT_TRIG_TRIGIN_SHIFT)) & INPUTMUX_AOIX_EXT_TRIGN_AOI_EXT_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_AOIX_EXT_TRIGN_AOI_EXT_TRIG */
#define INPUTMUX_AOIX_EXT_TRIGN_AOI_EXT_TRIG_COUNT (8U)

/*! @name HSCMP1_TRIG - Input connections for HSCMP1 */
/*! @{ */

#define INPUTMUX_HSCMP1_TRIG_TRIGIN_MASK         (0x3FU)
#define INPUTMUX_HSCMP1_TRIG_TRIGIN_SHIFT        (0U)
/*! TRIGIN - CMP1 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT7
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT7
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T0_MAT1
 *  0b001001..T4_MAT1
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[1]
 *  0b001110..ADC1_tcomp[1]
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b010010..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b010011..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b010100..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b010101..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b010110..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b010111..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b011000..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b011001..ENC0_CMP/POS_MATCH
 *  0b011010..ENC1_CMP/POS_MATCH
 *  0b011011..AOI0_OUT0
 *  0b011100..AOI0_OUT1
 *  0b011101..AOI0_OUT2
 *  0b011110..AOI0_OUT3
 *  0b011111..AOI1_OUT0
 *  0b100000..AOI1_OUT1
 *  0b100001..AOI1_OUT2
 *  0b100010..AOI1_OUT3
 *  0b100011..DMA0_TRIGOUT0
 *  0b100100..DMA0_TRIGOUT1
 *  0b100101..DMA0_TRIGOUT2
 */
#define INPUTMUX_HSCMP1_TRIG_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_HSCMP1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_HSCMP1_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name HSCMP2_TRIG - Input connections for HSCMP2 */
/*! @{ */

#define INPUTMUX_HSCMP2_TRIG_TRIGIN_MASK         (0x3FU)
#define INPUTMUX_HSCMP2_TRIG_TRIGIN_SHIFT        (0U)
/*! TRIGIN - CMP2 input trigger
 *  0b000000..PIN_INT0
 *  0b000001..PIN_INT4
 *  0b000010..SCT_OUT4
 *  0b000011..SCT_OUT5
 *  0b000100..SCT_OUT8
 *  0b000101..T0_MAT3
 *  0b000110..T1_MAT3
 *  0b000111..T2_MAT3
 *  0b001000..T0_MAT2
 *  0b001001..T4_MAT2
 *  0b001010..Reserved
 *  0b001011..ARM_TXEV
 *  0b001100..GPIOINT_BMATCH
 *  0b001101..ADC0_tcomp[2]
 *  0b001110..ADC1_tcomp[2]
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..PWM0_SM0_MUX_TRIG0 | PWM0_SM0_MUX_TRIG1
 *  0b010010..PWM0_SM1_MUX_TRIG0 | PWM0_SM1_MUX_TRIG1
 *  0b010011..PWM0_SM2_MUX_TRIG0 | PWM0_SM2_MUX_TRIG1
 *  0b010100..PWM0_SM3_MUX_TRIG0 | PWM0_SM3_MUX_TRIG1
 *  0b010101..PWM1_SM0_MUX_TRIG0 | PWM1_SM0_MUX_TRIG1
 *  0b010110..PWM1_SM1_MUX_TRIG0 | PWM1_SM1_MUX_TRIG1
 *  0b010111..PWM1_SM2_MUX_TRIG0 | PWM1_SM2_MUX_TRIG1
 *  0b011000..PWM1_SM3_MUX_TRIG0 | PWM1_SM3_MUX_TRIG1
 *  0b011001..ENC0_CMP/POS_MATCH
 *  0b011010..ENC1_CMP/POS_MATCH
 *  0b011011..AOI0_OUT0
 *  0b011100..AOI0_OUT1
 *  0b011101..AOI0_OUT2
 *  0b011110..AOI0_OUT3
 *  0b011111..AOI1_OUT0
 *  0b100000..AOI1_OUT1
 *  0b100001..AOI1_OUT2
 *  0b100010..AOI1_OUT3
 *  0b100011..DMA0_TRIGOUT0
 *  0b100100..DMA0_TRIGOUT1
 *  0b100101..DMA0_TRIGOUT2
 */
#define INPUTMUX_HSCMP2_TRIG_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_HSCMP2_TRIG_TRIGIN_SHIFT)) & INPUTMUX_HSCMP2_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name DMA0_ITRIG_INMUX32 - Trigger select for DMA0 channel */
/*! @{ */

#define INPUTMUX_DMA0_ITRIG_INMUX32_INP_MASK     (0x3FU)
#define INPUTMUX_DMA0_ITRIG_INMUX32_INP_SHIFT    (0U)
/*! INP - Trigger input number (binary value) for DMA channel n (n = 32 to 51).
 *  0b000000..FlexSPI_RX
 *  0b000001..FlexSPI_TX
 *  0b000010..GPIO_INT0
 *  0b000011..GPIO_INT1
 *  0b000100..GPIO_INT2
 *  0b000101..GPIO_INT3
 *  0b000110..T0_DMAREQ_M0
 *  0b000111..T0_DMAREQ_M1
 *  0b001000..T1_DMAREQ_M0
 *  0b001001..T1_DMAREQ_M1
 *  0b001010..T2_DMAREQ_M0
 *  0b001011..T2_DMAREQ_M1
 *  0b001100..T3_DMAREQ_M0
 *  0b001101..T3_DMAREQ_M1
 *  0b001110..T4_DMAREQ_M0
 *  0b001111..T4_DMAREQ_M1
 *  0b010000..ACMP0_OUT
 *  0b010001..SDMA0_TRIGOUT_A
 *  0b010010..SDMA0_TRIGOUT_B
 *  0b010011..SDMA0_TRIGOUT_C
 *  0b010100..SDMA0_TRIGOUT_D
 *  0b010101..SCT_DMA0
 *  0b010110..SCT_DMA1
 *  0b010111..ADC0_tcomp[0]
 *  0b011000..ADC1_tcomp[0]
 *  0b011001..HSCMP0
 *  0b011010..HSCMP1
 *  0b011011..HSCMP2
 *  0b011100..AOI0_OUT0
 *  0b011101..AOI0_OUT1
 *  0b011110..AOI0_OUT2
 *  0b011111..AOI0_OUT3
 *  0b100000..AOI1_OUT0
 *  0b100001..AOI1_OUT1
 *  0b100010..AOI1_OUT2
 *  0b100011..AOI1_OUT3
 *  0b100100..FlexPWM0_req_capt0
 *  0b100101..FlexPWM0_req_capt1
 *  0b100110..FlexPWM0_req_capt2
 *  0b100111..FlexPWM0_req_capt3
 *  0b101000..FlexPWM0_req_val0
 *  0b101001..FlexPWM0_req_val1
 *  0b101010..FlexPWM0_req_val2
 *  0b101011..FlexPWM0_req_val3
 *  0b101100..FlexPWM1_req_capt0
 *  0b101101..FlexPWM1_req_capt1
 *  0b101110..FlexPWM1_req_capt2
 *  0b101111..FlexPWM1_req_capt3
 *  0b110000..FlexPWM1_req_val0
 *  0b110001..FlexPWM1_req_val1
 *  0b110010..FlexPWM1_req_val2
 *  0b110011..FlexPWM1_req_val3
 *  0b110100..TMPR_OUT
 *  0b110110-0b111111..Reserved
 */
#define INPUTMUX_DMA0_ITRIG_INMUX32_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIG_INMUX32_INP_SHIFT)) & INPUTMUX_DMA0_ITRIG_INMUX32_INP_MASK)
/*! @} */

/*! @name DMA0_REQEN0 - Enable DMA0 requests */
/*! @{ */

#define INPUTMUX_DMA0_REQEN0_REQ_ENA0_MASK       (0x1U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA0_SHIFT      (0U)
/*! REQ_ENA0 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA0(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA0_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA0_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA1_MASK       (0x2U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA1_SHIFT      (1U)
/*! REQ_ENA1 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA1(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA1_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA1_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA2_MASK       (0x4U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA2_SHIFT      (2U)
/*! REQ_ENA2 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA2(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA2_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA2_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA3_MASK       (0x8U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA3_SHIFT      (3U)
/*! REQ_ENA3 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA3(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA3_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA3_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA4_MASK       (0x10U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA4_SHIFT      (4U)
/*! REQ_ENA4 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA4(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA4_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA4_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA5_MASK       (0x20U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA5_SHIFT      (5U)
/*! REQ_ENA5 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA5(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA5_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA5_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA6_MASK       (0x40U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA6_SHIFT      (6U)
/*! REQ_ENA6 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA6(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA6_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA6_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA7_MASK       (0x80U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA7_SHIFT      (7U)
/*! REQ_ENA7 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA7(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA7_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA7_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA8_MASK       (0x100U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA8_SHIFT      (8U)
/*! REQ_ENA8 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA8(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA8_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA8_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA9_MASK       (0x200U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA9_SHIFT      (9U)
/*! REQ_ENA9 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA9(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA9_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA9_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA10_MASK      (0x400U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA10_SHIFT     (10U)
/*! REQ_ENA10 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA10(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA10_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA10_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA11_MASK      (0x800U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA11_SHIFT     (11U)
/*! REQ_ENA11 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA11(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA11_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA11_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA12_MASK      (0x1000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA12_SHIFT     (12U)
/*! REQ_ENA12 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA12(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA12_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA12_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA13_MASK      (0x2000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA13_SHIFT     (13U)
/*! REQ_ENA13 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA13(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA13_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA13_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA14_MASK      (0x4000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA14_SHIFT     (14U)
/*! REQ_ENA14 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA14(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA14_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA14_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA15_MASK      (0x8000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA15_SHIFT     (15U)
/*! REQ_ENA15 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA15(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA15_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA15_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA16_MASK      (0x10000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA16_SHIFT     (16U)
/*! REQ_ENA16 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA16(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA16_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA16_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA17_MASK      (0x20000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA17_SHIFT     (17U)
/*! REQ_ENA17 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA17(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA17_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA17_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA18_MASK      (0x40000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA18_SHIFT     (18U)
/*! REQ_ENA18 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA18(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA18_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA18_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA19_MASK      (0x80000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA19_SHIFT     (19U)
/*! REQ_ENA19 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA19(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA19_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA19_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA20_MASK      (0x100000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA20_SHIFT     (20U)
/*! REQ_ENA20 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA20(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA20_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA20_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA21_MASK      (0x200000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA21_SHIFT     (21U)
/*! REQ_ENA21 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA21(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA21_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA21_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA22_MASK      (0x400000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA22_SHIFT     (22U)
/*! REQ_ENA22 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA22(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA22_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA22_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA23_MASK      (0x800000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA23_SHIFT     (23U)
/*! REQ_ENA23 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA23(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA23_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA23_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA24_MASK      (0x1000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA24_SHIFT     (24U)
/*! REQ_ENA24 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA24(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA24_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA24_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA25_MASK      (0x2000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA25_SHIFT     (25U)
/*! REQ_ENA25 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA25(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA25_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA25_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA26_MASK      (0x4000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA26_SHIFT     (26U)
/*! REQ_ENA26 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA26(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA26_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA26_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA27_MASK      (0x8000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA27_SHIFT     (27U)
/*! REQ_ENA27 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA27(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA27_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA27_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA28_MASK      (0x10000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA28_SHIFT     (28U)
/*! REQ_ENA28 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA28(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA28_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA28_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA29_MASK      (0x20000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA29_SHIFT     (29U)
/*! REQ_ENA29 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA29(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA29_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA29_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA30_MASK      (0x40000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA30_SHIFT     (30U)
/*! REQ_ENA30 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA30(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA30_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA30_MASK)

#define INPUTMUX_DMA0_REQEN0_REQ_ENA31_MASK      (0x80000000U)
#define INPUTMUX_DMA0_REQEN0_REQ_ENA31_SHIFT     (31U)
/*! REQ_ENA31 - Controls the first 32 request inputs of DMA0. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA0_REQEN0_REQ_ENA31(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_REQ_ENA31_SHIFT)) & INPUTMUX_DMA0_REQEN0_REQ_ENA31_MASK)
/*! @} */

/*! @name DMA0_REQEN1 - Enable DMA0 requests */
/*! @{ */

#define INPUTMUX_DMA0_REQEN1_REQ_ENA0_MASK       (0x1U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA0_SHIFT      (0U)
/*! REQ_ENA0 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA0(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA0_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA0_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA1_MASK       (0x2U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA1_SHIFT      (1U)
/*! REQ_ENA1 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA1(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA1_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA1_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA2_MASK       (0x4U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA2_SHIFT      (2U)
/*! REQ_ENA2 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA2(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA2_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA2_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA3_MASK       (0x8U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA3_SHIFT      (3U)
/*! REQ_ENA3 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA3(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA3_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA3_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA4_MASK       (0x10U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA4_SHIFT      (4U)
/*! REQ_ENA4 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA4(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA4_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA4_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA5_MASK       (0x20U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA5_SHIFT      (5U)
/*! REQ_ENA5 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA5(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA5_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA5_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA6_MASK       (0x40U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA6_SHIFT      (6U)
/*! REQ_ENA6 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA6(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA6_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA6_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA7_MASK       (0x80U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA7_SHIFT      (7U)
/*! REQ_ENA7 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA7(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA7_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA7_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA8_MASK       (0x100U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA8_SHIFT      (8U)
/*! REQ_ENA8 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA8(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA8_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA8_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA9_MASK       (0x200U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA9_SHIFT      (9U)
/*! REQ_ENA9 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA9(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA9_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA9_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA10_MASK      (0x400U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA10_SHIFT     (10U)
/*! REQ_ENA10 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA10(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA10_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA10_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA11_MASK      (0x800U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA11_SHIFT     (11U)
/*! REQ_ENA11 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA11(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA11_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA11_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA12_MASK      (0x1000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA12_SHIFT     (12U)
/*! REQ_ENA12 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA12(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA12_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA12_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA13_MASK      (0x2000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA13_SHIFT     (13U)
/*! REQ_ENA13 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA13(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA13_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA13_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA14_MASK      (0x4000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA14_SHIFT     (14U)
/*! REQ_ENA14 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA14(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA14_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA14_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA15_MASK      (0x8000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA15_SHIFT     (15U)
/*! REQ_ENA15 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA15(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA15_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA15_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA16_MASK      (0x10000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA16_SHIFT     (16U)
/*! REQ_ENA16 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA16(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA16_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA16_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA17_MASK      (0x20000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA17_SHIFT     (17U)
/*! REQ_ENA17 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA17(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA17_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA17_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA18_MASK      (0x40000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA18_SHIFT     (18U)
/*! REQ_ENA18 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA18(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA18_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA18_MASK)

#define INPUTMUX_DMA0_REQEN1_REQ_ENA19_MASK      (0x80000U)
#define INPUTMUX_DMA0_REQEN1_REQ_ENA19_SHIFT     (19U)
/*! REQ_ENA19 - Controls the remaining 20 request inputs of DMA0. If bit i is '1' the DMA request input #(i+32) is enabled. */
#define INPUTMUX_DMA0_REQEN1_REQ_ENA19(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_REQ_ENA19_SHIFT)) & INPUTMUX_DMA0_REQEN1_REQ_ENA19_MASK)
/*! @} */

/*! @name DMA0_REQEN0_SET - Set bits in DMA0_REQEN0 register */
/*! @{ */

#define INPUTMUX_DMA0_REQEN0_SET_SET0_MASK       (0x1U)
#define INPUTMUX_DMA0_REQEN0_SET_SET0_SHIFT      (0U)
/*! SET0 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET0(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET0_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET0_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET1_MASK       (0x2U)
#define INPUTMUX_DMA0_REQEN0_SET_SET1_SHIFT      (1U)
/*! SET1 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET1(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET1_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET1_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET2_MASK       (0x4U)
#define INPUTMUX_DMA0_REQEN0_SET_SET2_SHIFT      (2U)
/*! SET2 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET2(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET2_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET2_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET3_MASK       (0x8U)
#define INPUTMUX_DMA0_REQEN0_SET_SET3_SHIFT      (3U)
/*! SET3 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET3(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET3_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET3_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET4_MASK       (0x10U)
#define INPUTMUX_DMA0_REQEN0_SET_SET4_SHIFT      (4U)
/*! SET4 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET4(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET4_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET4_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET5_MASK       (0x20U)
#define INPUTMUX_DMA0_REQEN0_SET_SET5_SHIFT      (5U)
/*! SET5 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET5(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET5_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET5_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET6_MASK       (0x40U)
#define INPUTMUX_DMA0_REQEN0_SET_SET6_SHIFT      (6U)
/*! SET6 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET6(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET6_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET6_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET7_MASK       (0x80U)
#define INPUTMUX_DMA0_REQEN0_SET_SET7_SHIFT      (7U)
/*! SET7 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET7(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET7_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET7_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET8_MASK       (0x100U)
#define INPUTMUX_DMA0_REQEN0_SET_SET8_SHIFT      (8U)
/*! SET8 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET8(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET8_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET8_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET9_MASK       (0x200U)
#define INPUTMUX_DMA0_REQEN0_SET_SET9_SHIFT      (9U)
/*! SET9 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET9(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET9_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET9_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET10_MASK      (0x400U)
#define INPUTMUX_DMA0_REQEN0_SET_SET10_SHIFT     (10U)
/*! SET10 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET10(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET10_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET10_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET11_MASK      (0x800U)
#define INPUTMUX_DMA0_REQEN0_SET_SET11_SHIFT     (11U)
/*! SET11 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET11(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET11_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET11_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET12_MASK      (0x1000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET12_SHIFT     (12U)
/*! SET12 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET12(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET12_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET12_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET13_MASK      (0x2000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET13_SHIFT     (13U)
/*! SET13 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET13(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET13_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET13_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET14_MASK      (0x4000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET14_SHIFT     (14U)
/*! SET14 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET14(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET14_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET14_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET15_MASK      (0x8000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET15_SHIFT     (15U)
/*! SET15 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET15(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET15_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET15_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET16_MASK      (0x10000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET16_SHIFT     (16U)
/*! SET16 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET16(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET16_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET16_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET17_MASK      (0x20000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET17_SHIFT     (17U)
/*! SET17 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET17(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET17_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET17_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET18_MASK      (0x40000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET18_SHIFT     (18U)
/*! SET18 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET18(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET18_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET18_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET19_MASK      (0x80000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET19_SHIFT     (19U)
/*! SET19 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET19(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET19_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET19_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET20_MASK      (0x100000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET20_SHIFT     (20U)
/*! SET20 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET20(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET20_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET20_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET21_MASK      (0x200000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET21_SHIFT     (21U)
/*! SET21 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET21(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET21_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET21_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET22_MASK      (0x400000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET22_SHIFT     (22U)
/*! SET22 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET22(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET22_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET22_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET23_MASK      (0x800000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET23_SHIFT     (23U)
/*! SET23 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET23(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET23_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET23_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET24_MASK      (0x1000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET24_SHIFT     (24U)
/*! SET24 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET24(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET24_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET24_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET25_MASK      (0x2000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET25_SHIFT     (25U)
/*! SET25 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET25(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET25_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET25_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET26_MASK      (0x4000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET26_SHIFT     (26U)
/*! SET26 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET26(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET26_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET26_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET27_MASK      (0x8000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET27_SHIFT     (27U)
/*! SET27 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET27(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET27_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET27_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET28_MASK      (0x10000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET28_SHIFT     (28U)
/*! SET28 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET28(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET28_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET28_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET29_MASK      (0x20000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET29_SHIFT     (29U)
/*! SET29 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET29(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET29_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET29_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET30_MASK      (0x40000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET30_SHIFT     (30U)
/*! SET30 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET30(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET30_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET30_MASK)

#define INPUTMUX_DMA0_REQEN0_SET_SET31_MASK      (0x80000000U)
#define INPUTMUX_DMA0_REQEN0_SET_SET31_SHIFT     (31U)
/*! SET31 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is set to 1; if bit #i = 0, no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_SET_SET31(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_SET_SET31_SHIFT)) & INPUTMUX_DMA0_REQEN0_SET_SET31_MASK)
/*! @} */

/*! @name DMA0_REQEN1_SET - Set bits in DMA0_REQEN1 register */
/*! @{ */

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA0_MASK   (0x1U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA0_SHIFT  (0U)
/*! REQ_ENA0 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA0(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA0_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA0_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA1_MASK   (0x2U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA1_SHIFT  (1U)
/*! REQ_ENA1 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA1(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA1_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA1_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA2_MASK   (0x4U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA2_SHIFT  (2U)
/*! REQ_ENA2 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA2(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA2_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA2_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA3_MASK   (0x8U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA3_SHIFT  (3U)
/*! REQ_ENA3 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA3(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA3_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA3_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA4_MASK   (0x10U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA4_SHIFT  (4U)
/*! REQ_ENA4 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA4(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA4_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA4_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA5_MASK   (0x20U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA5_SHIFT  (5U)
/*! REQ_ENA5 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA5(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA5_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA5_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA6_MASK   (0x40U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA6_SHIFT  (6U)
/*! REQ_ENA6 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA6(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA6_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA6_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA7_MASK   (0x80U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA7_SHIFT  (7U)
/*! REQ_ENA7 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA7(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA7_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA7_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA8_MASK   (0x100U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA8_SHIFT  (8U)
/*! REQ_ENA8 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA8(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA8_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA8_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA9_MASK   (0x200U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA9_SHIFT  (9U)
/*! REQ_ENA9 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA9(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA9_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA9_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA10_MASK  (0x400U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA10_SHIFT (10U)
/*! REQ_ENA10 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA10(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA10_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA10_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA11_MASK  (0x800U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA11_SHIFT (11U)
/*! REQ_ENA11 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA11(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA11_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA11_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA12_MASK  (0x1000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA12_SHIFT (12U)
/*! REQ_ENA12 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA12(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA12_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA12_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA13_MASK  (0x2000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA13_SHIFT (13U)
/*! REQ_ENA13 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA13(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA13_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA13_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA14_MASK  (0x4000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA14_SHIFT (14U)
/*! REQ_ENA14 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA14(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA14_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA14_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA15_MASK  (0x8000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA15_SHIFT (15U)
/*! REQ_ENA15 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA15(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA15_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA15_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA16_MASK  (0x10000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA16_SHIFT (16U)
/*! REQ_ENA16 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA16(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA16_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA16_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA17_MASK  (0x20000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA17_SHIFT (17U)
/*! REQ_ENA17 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA17(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA17_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA17_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA18_MASK  (0x40000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA18_SHIFT (18U)
/*! REQ_ENA18 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA18(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA18_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA18_MASK)

#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA19_MASK  (0x80000U)
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA19_SHIFT (19U)
/*! REQ_ENA19 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is set to 1; if bit #i = 0, no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_SET_REQ_ENA19(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_SET_REQ_ENA19_SHIFT)) & INPUTMUX_DMA0_REQEN1_SET_REQ_ENA19_MASK)
/*! @} */

/*! @name DMA0_REQEN0_CLR - Clear bits in DMA0_REQEN0 register */
/*! @{ */

#define INPUTMUX_DMA0_REQEN0_CLR_CLR0_MASK       (0x1U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR0_SHIFT      (0U)
/*! CLR0 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR0(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR0_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR0_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR1_MASK       (0x2U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR1_SHIFT      (1U)
/*! CLR1 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR1(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR1_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR1_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR2_MASK       (0x4U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR2_SHIFT      (2U)
/*! CLR2 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR2(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR2_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR2_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR3_MASK       (0x8U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR3_SHIFT      (3U)
/*! CLR3 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR3(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR3_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR3_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR4_MASK       (0x10U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR4_SHIFT      (4U)
/*! CLR4 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR4(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR4_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR4_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR5_MASK       (0x20U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR5_SHIFT      (5U)
/*! CLR5 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR5(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR5_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR5_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR6_MASK       (0x40U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR6_SHIFT      (6U)
/*! CLR6 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR6(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR6_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR6_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR7_MASK       (0x80U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR7_SHIFT      (7U)
/*! CLR7 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR7(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR7_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR7_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR8_MASK       (0x100U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR8_SHIFT      (8U)
/*! CLR8 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR8(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR8_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR8_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR9_MASK       (0x200U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR9_SHIFT      (9U)
/*! CLR9 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR9(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR9_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR9_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR10_MASK      (0x400U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR10_SHIFT     (10U)
/*! CLR10 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR10(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR10_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR10_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR11_MASK      (0x800U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR11_SHIFT     (11U)
/*! CLR11 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR11(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR11_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR11_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR12_MASK      (0x1000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR12_SHIFT     (12U)
/*! CLR12 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR12(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR12_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR12_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR13_MASK      (0x2000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR13_SHIFT     (13U)
/*! CLR13 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR13(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR13_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR13_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR14_MASK      (0x4000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR14_SHIFT     (14U)
/*! CLR14 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR14(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR14_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR14_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR15_MASK      (0x8000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR15_SHIFT     (15U)
/*! CLR15 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR15(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR15_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR15_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR16_MASK      (0x10000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR16_SHIFT     (16U)
/*! CLR16 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR16(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR16_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR16_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR17_MASK      (0x20000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR17_SHIFT     (17U)
/*! CLR17 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR17(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR17_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR17_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR18_MASK      (0x40000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR18_SHIFT     (18U)
/*! CLR18 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR18(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR18_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR18_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR19_MASK      (0x80000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR19_SHIFT     (19U)
/*! CLR19 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR19(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR19_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR19_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR20_MASK      (0x100000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR20_SHIFT     (20U)
/*! CLR20 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR20(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR20_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR20_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR21_MASK      (0x200000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR21_SHIFT     (21U)
/*! CLR21 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR21(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR21_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR21_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR22_MASK      (0x400000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR22_SHIFT     (22U)
/*! CLR22 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR22(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR22_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR22_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR23_MASK      (0x800000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR23_SHIFT     (23U)
/*! CLR23 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR23(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR23_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR23_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR24_MASK      (0x1000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR24_SHIFT     (24U)
/*! CLR24 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR24(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR24_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR24_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR25_MASK      (0x2000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR25_SHIFT     (25U)
/*! CLR25 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR25(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR25_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR25_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR26_MASK      (0x4000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR26_SHIFT     (26U)
/*! CLR26 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR26(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR26_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR26_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR27_MASK      (0x8000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR27_SHIFT     (27U)
/*! CLR27 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR27(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR27_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR27_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR28_MASK      (0x10000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR28_SHIFT     (28U)
/*! CLR28 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR28(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR28_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR28_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR29_MASK      (0x20000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR29_SHIFT     (29U)
/*! CLR29 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR29(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR29_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR29_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR30_MASK      (0x40000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR30_SHIFT     (30U)
/*! CLR30 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR30(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR30_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR30_MASK)

#define INPUTMUX_DMA0_REQEN0_CLR_CLR31_MASK      (0x80000000U)
#define INPUTMUX_DMA0_REQEN0_CLR_CLR31_SHIFT     (31U)
/*! CLR31 - Write : If bit #i = 1, bit #i in DMA0_REQEN0 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN0 register. */
#define INPUTMUX_DMA0_REQEN0_CLR_CLR31(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN0_CLR_CLR31_SHIFT)) & INPUTMUX_DMA0_REQEN0_CLR_CLR31_MASK)
/*! @} */

/*! @name DMA0_REQEN1_CLR - Clear bits in DMA0_REQEN1 register */
/*! @{ */

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA0_MASK   (0x1U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA0_SHIFT  (0U)
/*! REQ_ENA0 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA0(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA0_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA0_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA1_MASK   (0x2U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA1_SHIFT  (1U)
/*! REQ_ENA1 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA1(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA1_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA1_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA2_MASK   (0x4U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA2_SHIFT  (2U)
/*! REQ_ENA2 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA2(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA2_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA2_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA3_MASK   (0x8U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA3_SHIFT  (3U)
/*! REQ_ENA3 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA3(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA3_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA3_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA4_MASK   (0x10U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA4_SHIFT  (4U)
/*! REQ_ENA4 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA4(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA4_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA4_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA5_MASK   (0x20U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA5_SHIFT  (5U)
/*! REQ_ENA5 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA5(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA5_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA5_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA6_MASK   (0x40U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA6_SHIFT  (6U)
/*! REQ_ENA6 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA6(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA6_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA6_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA7_MASK   (0x80U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA7_SHIFT  (7U)
/*! REQ_ENA7 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA7(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA7_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA7_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA8_MASK   (0x100U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA8_SHIFT  (8U)
/*! REQ_ENA8 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA8(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA8_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA8_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA9_MASK   (0x200U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA9_SHIFT  (9U)
/*! REQ_ENA9 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA9(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA9_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA9_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA10_MASK  (0x400U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA10_SHIFT (10U)
/*! REQ_ENA10 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA10(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA10_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA10_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA11_MASK  (0x800U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA11_SHIFT (11U)
/*! REQ_ENA11 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA11(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA11_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA11_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA12_MASK  (0x1000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA12_SHIFT (12U)
/*! REQ_ENA12 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA12(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA12_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA12_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA13_MASK  (0x2000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA13_SHIFT (13U)
/*! REQ_ENA13 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA13(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA13_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA13_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA14_MASK  (0x4000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA14_SHIFT (14U)
/*! REQ_ENA14 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA14(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA14_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA14_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA15_MASK  (0x8000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA15_SHIFT (15U)
/*! REQ_ENA15 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA15(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA15_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA15_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA16_MASK  (0x10000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA16_SHIFT (16U)
/*! REQ_ENA16 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA16(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA16_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA16_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA17_MASK  (0x20000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA17_SHIFT (17U)
/*! REQ_ENA17 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA17(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA17_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA17_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA18_MASK  (0x40000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA18_SHIFT (18U)
/*! REQ_ENA18 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA18(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA18_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA18_MASK)

#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA19_MASK  (0x80000U)
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA19_SHIFT (19U)
/*! REQ_ENA19 - Write : If bit #i = 1, bit #i in DMA0_REQEN1 register is reset to 0; if bit #i = 0 , no change in DMA0_REQEN1 register. */
#define INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA19(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA19_SHIFT)) & INPUTMUX_DMA0_REQEN1_CLR_REQ_ENA19_MASK)
/*! @} */

/*! @name DMA1_REQEN - Enable DMA1 requests */
/*! @{ */

#define INPUTMUX_DMA1_REQEN_REQ_ENA0_MASK        (0x1U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA0_SHIFT       (0U)
/*! REQ_ENA0 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA0(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA0_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA0_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA1_MASK        (0x2U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA1_SHIFT       (1U)
/*! REQ_ENA1 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA1(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA1_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA1_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA2_MASK        (0x4U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA2_SHIFT       (2U)
/*! REQ_ENA2 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA2(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA2_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA2_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA3_MASK        (0x8U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA3_SHIFT       (3U)
/*! REQ_ENA3 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA3(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA3_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA3_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA4_MASK        (0x10U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA4_SHIFT       (4U)
/*! REQ_ENA4 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA4(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA4_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA4_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA5_MASK        (0x20U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA5_SHIFT       (5U)
/*! REQ_ENA5 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA5(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA5_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA5_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA6_MASK        (0x40U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA6_SHIFT       (6U)
/*! REQ_ENA6 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA6(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA6_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA6_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA7_MASK        (0x80U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA7_SHIFT       (7U)
/*! REQ_ENA7 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA7(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA7_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA7_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA8_MASK        (0x100U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA8_SHIFT       (8U)
/*! REQ_ENA8 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA8(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA8_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA8_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA9_MASK        (0x200U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA9_SHIFT       (9U)
/*! REQ_ENA9 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA9(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA9_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA9_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA10_MASK       (0x400U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA10_SHIFT      (10U)
/*! REQ_ENA10 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA10(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA10_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA10_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA11_MASK       (0x800U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA11_SHIFT      (11U)
/*! REQ_ENA11 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA11(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA11_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA11_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA12_MASK       (0x1000U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA12_SHIFT      (12U)
/*! REQ_ENA12 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA12(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA12_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA12_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA13_MASK       (0x2000U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA13_SHIFT      (13U)
/*! REQ_ENA13 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA13(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA13_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA13_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA14_MASK       (0x4000U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA14_SHIFT      (14U)
/*! REQ_ENA14 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA14(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA14_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA14_MASK)

#define INPUTMUX_DMA1_REQEN_REQ_ENA15_MASK       (0x8000U)
#define INPUTMUX_DMA1_REQEN_REQ_ENA15_SHIFT      (15U)
/*! REQ_ENA15 - Controls the 16 request inputs of DMA1. If bit i is '1' the DMA request input #i is enabled. */
#define INPUTMUX_DMA1_REQEN_REQ_ENA15(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_REQ_ENA15_SHIFT)) & INPUTMUX_DMA1_REQEN_REQ_ENA15_MASK)
/*! @} */

/*! @name DMA1_REQEN_SET - Set bits in DMA1_REQEN register */
/*! @{ */

#define INPUTMUX_DMA1_REQEN_SET_SET0_MASK        (0x1U)
#define INPUTMUX_DMA1_REQEN_SET_SET0_SHIFT       (0U)
/*! SET0 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET0(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET0_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET0_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET1_MASK        (0x2U)
#define INPUTMUX_DMA1_REQEN_SET_SET1_SHIFT       (1U)
/*! SET1 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET1(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET1_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET1_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET2_MASK        (0x4U)
#define INPUTMUX_DMA1_REQEN_SET_SET2_SHIFT       (2U)
/*! SET2 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET2(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET2_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET2_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET3_MASK        (0x8U)
#define INPUTMUX_DMA1_REQEN_SET_SET3_SHIFT       (3U)
/*! SET3 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET3(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET3_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET3_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET4_MASK        (0x10U)
#define INPUTMUX_DMA1_REQEN_SET_SET4_SHIFT       (4U)
/*! SET4 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET4(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET4_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET4_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET5_MASK        (0x20U)
#define INPUTMUX_DMA1_REQEN_SET_SET5_SHIFT       (5U)
/*! SET5 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET5(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET5_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET5_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET6_MASK        (0x40U)
#define INPUTMUX_DMA1_REQEN_SET_SET6_SHIFT       (6U)
/*! SET6 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET6(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET6_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET6_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET7_MASK        (0x80U)
#define INPUTMUX_DMA1_REQEN_SET_SET7_SHIFT       (7U)
/*! SET7 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET7(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET7_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET7_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET8_MASK        (0x100U)
#define INPUTMUX_DMA1_REQEN_SET_SET8_SHIFT       (8U)
/*! SET8 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET8(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET8_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET8_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET9_MASK        (0x200U)
#define INPUTMUX_DMA1_REQEN_SET_SET9_SHIFT       (9U)
/*! SET9 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET9(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET9_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET9_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET10_MASK       (0x400U)
#define INPUTMUX_DMA1_REQEN_SET_SET10_SHIFT      (10U)
/*! SET10 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET10(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET10_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET10_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET11_MASK       (0x800U)
#define INPUTMUX_DMA1_REQEN_SET_SET11_SHIFT      (11U)
/*! SET11 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET11(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET11_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET11_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET12_MASK       (0x1000U)
#define INPUTMUX_DMA1_REQEN_SET_SET12_SHIFT      (12U)
/*! SET12 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET12(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET12_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET12_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET13_MASK       (0x2000U)
#define INPUTMUX_DMA1_REQEN_SET_SET13_SHIFT      (13U)
/*! SET13 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET13(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET13_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET13_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET14_MASK       (0x4000U)
#define INPUTMUX_DMA1_REQEN_SET_SET14_SHIFT      (14U)
/*! SET14 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET14(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET14_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET14_MASK)

#define INPUTMUX_DMA1_REQEN_SET_SET15_MASK       (0x8000U)
#define INPUTMUX_DMA1_REQEN_SET_SET15_SHIFT      (15U)
/*! SET15 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is set to 1; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_SET_SET15(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_SET_SET15_SHIFT)) & INPUTMUX_DMA1_REQEN_SET_SET15_MASK)
/*! @} */

/*! @name DMA1_REQEN_CLR - Clear bits in DMA1_REQEN register */
/*! @{ */

#define INPUTMUX_DMA1_REQEN_CLR_CLR0_MASK        (0x1U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR0_SHIFT       (0U)
/*! CLR0 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR0(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR0_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR0_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR1_MASK        (0x2U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR1_SHIFT       (1U)
/*! CLR1 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR1(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR1_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR1_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR2_MASK        (0x4U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR2_SHIFT       (2U)
/*! CLR2 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR2(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR2_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR2_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR3_MASK        (0x8U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR3_SHIFT       (3U)
/*! CLR3 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR3(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR3_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR3_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR4_MASK        (0x10U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR4_SHIFT       (4U)
/*! CLR4 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR4(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR4_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR4_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR5_MASK        (0x20U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR5_SHIFT       (5U)
/*! CLR5 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR5(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR5_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR5_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR6_MASK        (0x40U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR6_SHIFT       (6U)
/*! CLR6 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR6(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR6_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR6_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR7_MASK        (0x80U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR7_SHIFT       (7U)
/*! CLR7 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR7(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR7_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR7_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR8_MASK        (0x100U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR8_SHIFT       (8U)
/*! CLR8 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR8(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR8_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR8_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR9_MASK        (0x200U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR9_SHIFT       (9U)
/*! CLR9 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR9(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR9_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR9_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR10_MASK       (0x400U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR10_SHIFT      (10U)
/*! CLR10 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR10(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR10_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR10_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR11_MASK       (0x800U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR11_SHIFT      (11U)
/*! CLR11 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR11(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR11_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR11_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR12_MASK       (0x1000U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR12_SHIFT      (12U)
/*! CLR12 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR12(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR12_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR12_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR13_MASK       (0x2000U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR13_SHIFT      (13U)
/*! CLR13 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR13(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR13_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR13_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR14_MASK       (0x4000U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR14_SHIFT      (14U)
/*! CLR14 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR14(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR14_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR14_MASK)

#define INPUTMUX_DMA1_REQEN_CLR_CLR15_MASK       (0x8000U)
#define INPUTMUX_DMA1_REQEN_CLR_CLR15_SHIFT      (15U)
/*! CLR15 - Write : If bit #i = 1, bit #i in DMA1_REQEN register is reset to 0; if bit #i = 0 , no change in DMA1_REQEN register */
#define INPUTMUX_DMA1_REQEN_CLR_CLR15(x)         (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_REQEN_CLR_CLR15_SHIFT)) & INPUTMUX_DMA1_REQEN_CLR_CLR15_MASK)
/*! @} */

/*! @name DMA0_ITRIGEN0 - Enable DMA0 triggers */
/*! @{ */

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN0_MASK     (0x1U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN0_SHIFT    (0U)
/*! ITRIGEN0 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN0(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN0_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN0_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN1_MASK     (0x2U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN1_SHIFT    (1U)
/*! ITRIGEN1 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN1(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN1_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN1_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN2_MASK     (0x4U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN2_SHIFT    (2U)
/*! ITRIGEN2 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN2(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN2_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN2_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN3_MASK     (0x8U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN3_SHIFT    (3U)
/*! ITRIGEN3 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN3(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN3_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN3_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN4_MASK     (0x10U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN4_SHIFT    (4U)
/*! ITRIGEN4 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN4(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN4_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN4_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN5_MASK     (0x20U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN5_SHIFT    (5U)
/*! ITRIGEN5 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN5(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN5_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN5_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN6_MASK     (0x40U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN6_SHIFT    (6U)
/*! ITRIGEN6 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN6(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN6_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN6_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN7_MASK     (0x80U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN7_SHIFT    (7U)
/*! ITRIGEN7 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN7(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN7_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN7_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN8_MASK     (0x100U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN8_SHIFT    (8U)
/*! ITRIGEN8 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN8(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN8_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN8_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN9_MASK     (0x200U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN9_SHIFT    (9U)
/*! ITRIGEN9 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN9(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN9_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN9_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN10_MASK    (0x400U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN10_SHIFT   (10U)
/*! ITRIGEN10 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN10(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN10_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN10_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN11_MASK    (0x800U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN11_SHIFT   (11U)
/*! ITRIGEN11 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN11(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN11_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN11_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN12_MASK    (0x1000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN12_SHIFT   (12U)
/*! ITRIGEN12 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN12(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN12_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN12_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN13_MASK    (0x2000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN13_SHIFT   (13U)
/*! ITRIGEN13 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN13(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN13_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN13_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN14_MASK    (0x4000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN14_SHIFT   (14U)
/*! ITRIGEN14 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN14(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN14_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN14_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN15_MASK    (0x8000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN15_SHIFT   (15U)
/*! ITRIGEN15 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN15(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN15_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN15_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN16_MASK    (0x10000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN16_SHIFT   (16U)
/*! ITRIGEN16 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN16(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN16_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN16_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN17_MASK    (0x20000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN17_SHIFT   (17U)
/*! ITRIGEN17 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN17(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN17_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN17_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN18_MASK    (0x40000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN18_SHIFT   (18U)
/*! ITRIGEN18 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN18(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN18_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN18_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN19_MASK    (0x80000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN19_SHIFT   (19U)
/*! ITRIGEN19 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN19(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN19_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN19_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN20_MASK    (0x100000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN20_SHIFT   (20U)
/*! ITRIGEN20 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN20(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN20_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN20_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN21_MASK    (0x200000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN21_SHIFT   (21U)
/*! ITRIGEN21 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN21(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN21_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN21_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN22_MASK    (0x400000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN22_SHIFT   (22U)
/*! ITRIGEN22 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN22(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN22_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN22_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN23_MASK    (0x800000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN23_SHIFT   (23U)
/*! ITRIGEN23 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN23(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN23_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN23_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN24_MASK    (0x1000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN24_SHIFT   (24U)
/*! ITRIGEN24 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN24(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN24_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN24_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN25_MASK    (0x2000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN25_SHIFT   (25U)
/*! ITRIGEN25 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN25(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN25_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN25_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN26_MASK    (0x4000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN26_SHIFT   (26U)
/*! ITRIGEN26 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN26(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN26_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN26_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN27_MASK    (0x8000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN27_SHIFT   (27U)
/*! ITRIGEN27 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN27(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN27_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN27_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN28_MASK    (0x10000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN28_SHIFT   (28U)
/*! ITRIGEN28 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN28(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN28_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN28_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN29_MASK    (0x20000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN29_SHIFT   (29U)
/*! ITRIGEN29 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN29(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN29_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN29_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN30_MASK    (0x40000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN30_SHIFT   (30U)
/*! ITRIGEN30 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN30(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN30_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN30_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN31_MASK    (0x80000000U)
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN31_SHIFT   (31U)
/*! ITRIGEN31 - Controls the 32 trigger inputs of DMA0. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA0_ITRIGEN0_ITRIGEN31(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_ITRIGEN31_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_ITRIGEN31_MASK)
/*! @} */

/*! @name DMA0_ITRIGEN1 - Enable DMA0 triggers */
/*! @{ */

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN0_MASK     (0x1U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN0_SHIFT    (0U)
/*! ITRIGEN0 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN0(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN0_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN0_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN1_MASK     (0x2U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN1_SHIFT    (1U)
/*! ITRIGEN1 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN1(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN1_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN1_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN2_MASK     (0x4U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN2_SHIFT    (2U)
/*! ITRIGEN2 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN2(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN2_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN2_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN3_MASK     (0x8U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN3_SHIFT    (3U)
/*! ITRIGEN3 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN3(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN3_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN3_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN4_MASK     (0x10U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN4_SHIFT    (4U)
/*! ITRIGEN4 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN4(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN4_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN4_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN5_MASK     (0x20U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN5_SHIFT    (5U)
/*! ITRIGEN5 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN5(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN5_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN5_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN6_MASK     (0x40U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN6_SHIFT    (6U)
/*! ITRIGEN6 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN6(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN6_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN6_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN7_MASK     (0x80U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN7_SHIFT    (7U)
/*! ITRIGEN7 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN7(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN7_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN7_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN8_MASK     (0x100U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN8_SHIFT    (8U)
/*! ITRIGEN8 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN8(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN8_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN8_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN9_MASK     (0x200U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN9_SHIFT    (9U)
/*! ITRIGEN9 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN9(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN9_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN9_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN10_MASK    (0x400U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN10_SHIFT   (10U)
/*! ITRIGEN10 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN10(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN10_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN10_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN11_MASK    (0x800U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN11_SHIFT   (11U)
/*! ITRIGEN11 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN11(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN11_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN11_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN12_MASK    (0x1000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN12_SHIFT   (12U)
/*! ITRIGEN12 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN12(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN12_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN12_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN13_MASK    (0x2000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN13_SHIFT   (13U)
/*! ITRIGEN13 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN13(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN13_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN13_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN14_MASK    (0x4000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN14_SHIFT   (14U)
/*! ITRIGEN14 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN14(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN14_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN14_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN15_MASK    (0x8000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN15_SHIFT   (15U)
/*! ITRIGEN15 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN15(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN15_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN15_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN16_MASK    (0x10000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN16_SHIFT   (16U)
/*! ITRIGEN16 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN16(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN16_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN16_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN17_MASK    (0x20000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN17_SHIFT   (17U)
/*! ITRIGEN17 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN17(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN17_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN17_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN18_MASK    (0x40000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN18_SHIFT   (18U)
/*! ITRIGEN18 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN18(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN18_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN18_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN19_MASK    (0x80000U)
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN19_SHIFT   (19U)
/*! ITRIGEN19 - Controls the remaining 20 trigger inputs of DMA0. If bit n is '1' the DMA trigger input #(n+32) is enabled. */
#define INPUTMUX_DMA0_ITRIGEN1_ITRIGEN19(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_ITRIGEN19_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_ITRIGEN19_MASK)
/*! @} */

/*! @name DMA0_ITRIGEN0_SET - Set bits in DMA0_ITRIGEN0 register */
/*! @{ */

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET0_MASK     (0x1U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET0_SHIFT    (0U)
/*! SET0 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET0(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET0_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET0_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET1_MASK     (0x2U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET1_SHIFT    (1U)
/*! SET1 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET1(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET1_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET1_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET2_MASK     (0x4U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET2_SHIFT    (2U)
/*! SET2 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET2(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET2_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET2_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET3_MASK     (0x8U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET3_SHIFT    (3U)
/*! SET3 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET3(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET3_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET3_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET4_MASK     (0x10U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET4_SHIFT    (4U)
/*! SET4 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET4(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET4_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET4_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET5_MASK     (0x20U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET5_SHIFT    (5U)
/*! SET5 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET5(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET5_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET5_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET6_MASK     (0x40U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET6_SHIFT    (6U)
/*! SET6 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET6(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET6_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET6_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET7_MASK     (0x80U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET7_SHIFT    (7U)
/*! SET7 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET7(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET7_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET7_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET8_MASK     (0x100U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET8_SHIFT    (8U)
/*! SET8 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET8(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET8_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET8_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET9_MASK     (0x200U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET9_SHIFT    (9U)
/*! SET9 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET9(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET9_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET9_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET10_MASK    (0x400U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET10_SHIFT   (10U)
/*! SET10 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET10(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET10_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET10_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET11_MASK    (0x800U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET11_SHIFT   (11U)
/*! SET11 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET11(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET11_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET11_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET12_MASK    (0x1000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET12_SHIFT   (12U)
/*! SET12 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET12(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET12_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET12_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET13_MASK    (0x2000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET13_SHIFT   (13U)
/*! SET13 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET13(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET13_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET13_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET14_MASK    (0x4000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET14_SHIFT   (14U)
/*! SET14 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET14(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET14_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET14_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET15_MASK    (0x8000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET15_SHIFT   (15U)
/*! SET15 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET15(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET15_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET15_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET16_MASK    (0x10000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET16_SHIFT   (16U)
/*! SET16 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET16(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET16_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET16_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET17_MASK    (0x20000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET17_SHIFT   (17U)
/*! SET17 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET17(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET17_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET17_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET18_MASK    (0x40000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET18_SHIFT   (18U)
/*! SET18 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET18(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET18_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET18_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET19_MASK    (0x80000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET19_SHIFT   (19U)
/*! SET19 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET19(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET19_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET19_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET20_MASK    (0x100000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET20_SHIFT   (20U)
/*! SET20 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET20(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET20_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET20_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET21_MASK    (0x200000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET21_SHIFT   (21U)
/*! SET21 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET21(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET21_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET21_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET22_MASK    (0x400000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET22_SHIFT   (22U)
/*! SET22 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET22(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET22_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET22_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET23_MASK    (0x800000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET23_SHIFT   (23U)
/*! SET23 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET23(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET23_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET23_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET24_MASK    (0x1000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET24_SHIFT   (24U)
/*! SET24 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET24(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET24_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET24_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET25_MASK    (0x2000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET25_SHIFT   (25U)
/*! SET25 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET25(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET25_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET25_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET26_MASK    (0x4000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET26_SHIFT   (26U)
/*! SET26 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET26(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET26_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET26_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET27_MASK    (0x8000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET27_SHIFT   (27U)
/*! SET27 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET27(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET27_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET27_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET28_MASK    (0x10000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET28_SHIFT   (28U)
/*! SET28 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET28(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET28_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET28_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET29_MASK    (0x20000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET29_SHIFT   (29U)
/*! SET29 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET29(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET29_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET29_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET30_MASK    (0x40000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET30_SHIFT   (30U)
/*! SET30 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET30(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET30_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET30_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_SET_SET31_MASK    (0x80000000U)
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET31_SHIFT   (31U)
/*! SET31 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_SET_SET31(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_SET_SET31_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_SET_SET31_MASK)
/*! @} */

/*! @name DMA0_ITRIGEN1_SET - Set bits in DMA0_ITRIGEN1 register */
/*! @{ */

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET0_MASK     (0x1U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET0_SHIFT    (0U)
/*! SET0 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET0(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET0_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET0_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET1_MASK     (0x2U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET1_SHIFT    (1U)
/*! SET1 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET1(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET1_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET1_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET2_MASK     (0x4U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET2_SHIFT    (2U)
/*! SET2 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET2(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET2_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET2_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET3_MASK     (0x8U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET3_SHIFT    (3U)
/*! SET3 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET3(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET3_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET3_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET4_MASK     (0x10U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET4_SHIFT    (4U)
/*! SET4 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET4(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET4_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET4_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET5_MASK     (0x20U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET5_SHIFT    (5U)
/*! SET5 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET5(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET5_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET5_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET6_MASK     (0x40U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET6_SHIFT    (6U)
/*! SET6 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET6(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET6_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET6_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET7_MASK     (0x80U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET7_SHIFT    (7U)
/*! SET7 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET7(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET7_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET7_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET8_MASK     (0x100U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET8_SHIFT    (8U)
/*! SET8 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET8(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET8_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET8_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET9_MASK     (0x200U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET9_SHIFT    (9U)
/*! SET9 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET9(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET9_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET9_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET10_MASK    (0x400U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET10_SHIFT   (10U)
/*! SET10 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET10(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET10_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET10_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET11_MASK    (0x800U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET11_SHIFT   (11U)
/*! SET11 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET11(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET11_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET11_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET12_MASK    (0x1000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET12_SHIFT   (12U)
/*! SET12 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET12(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET12_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET12_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET13_MASK    (0x2000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET13_SHIFT   (13U)
/*! SET13 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET13(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET13_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET13_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET14_MASK    (0x4000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET14_SHIFT   (14U)
/*! SET14 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET14(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET14_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET14_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET15_MASK    (0x8000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET15_SHIFT   (15U)
/*! SET15 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET15(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET15_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET15_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET16_MASK    (0x10000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET16_SHIFT   (16U)
/*! SET16 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET16(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET16_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET16_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET17_MASK    (0x20000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET17_SHIFT   (17U)
/*! SET17 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET17(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET17_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET17_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET18_MASK    (0x40000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET18_SHIFT   (18U)
/*! SET18 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET18(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET18_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET18_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_SET_SET19_MASK    (0x80000U)
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET19_SHIFT   (19U)
/*! SET19 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is set to 1; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_SET_SET19(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_SET_SET19_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_SET_SET19_MASK)
/*! @} */

/*! @name DMA0_ITRIGEN0_CLR - Clear bits in DMA0_ITRIGEN0 register */
/*! @{ */

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR0_MASK     (0x1U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR0_SHIFT    (0U)
/*! CLR0 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR0(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR0_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR0_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR1_MASK     (0x2U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR1_SHIFT    (1U)
/*! CLR1 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR1(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR1_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR1_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR2_MASK     (0x4U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR2_SHIFT    (2U)
/*! CLR2 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR2(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR2_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR2_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR3_MASK     (0x8U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR3_SHIFT    (3U)
/*! CLR3 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR3(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR3_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR3_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR4_MASK     (0x10U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR4_SHIFT    (4U)
/*! CLR4 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR4(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR4_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR4_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR5_MASK     (0x20U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR5_SHIFT    (5U)
/*! CLR5 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR5(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR5_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR5_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR6_MASK     (0x40U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR6_SHIFT    (6U)
/*! CLR6 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR6(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR6_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR6_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR7_MASK     (0x80U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR7_SHIFT    (7U)
/*! CLR7 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR7(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR7_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR7_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR8_MASK     (0x100U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR8_SHIFT    (8U)
/*! CLR8 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR8(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR8_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR8_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR9_MASK     (0x200U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR9_SHIFT    (9U)
/*! CLR9 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR9(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR9_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR9_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR10_MASK    (0x400U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR10_SHIFT   (10U)
/*! CLR10 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR10(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR10_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR10_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR11_MASK    (0x800U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR11_SHIFT   (11U)
/*! CLR11 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR11(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR11_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR11_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR12_MASK    (0x1000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR12_SHIFT   (12U)
/*! CLR12 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR12(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR12_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR12_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR13_MASK    (0x2000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR13_SHIFT   (13U)
/*! CLR13 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR13(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR13_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR13_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR14_MASK    (0x4000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR14_SHIFT   (14U)
/*! CLR14 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR14(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR14_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR14_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR15_MASK    (0x8000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR15_SHIFT   (15U)
/*! CLR15 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR15(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR15_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR15_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR16_MASK    (0x10000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR16_SHIFT   (16U)
/*! CLR16 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR16(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR16_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR16_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR17_MASK    (0x20000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR17_SHIFT   (17U)
/*! CLR17 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR17(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR17_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR17_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR18_MASK    (0x40000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR18_SHIFT   (18U)
/*! CLR18 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR18(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR18_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR18_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR19_MASK    (0x80000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR19_SHIFT   (19U)
/*! CLR19 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR19(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR19_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR19_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR20_MASK    (0x100000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR20_SHIFT   (20U)
/*! CLR20 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR20(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR20_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR20_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR21_MASK    (0x200000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR21_SHIFT   (21U)
/*! CLR21 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR21(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR21_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR21_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR22_MASK    (0x400000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR22_SHIFT   (22U)
/*! CLR22 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR22(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR22_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR22_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR23_MASK    (0x800000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR23_SHIFT   (23U)
/*! CLR23 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR23(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR23_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR23_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR24_MASK    (0x1000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR24_SHIFT   (24U)
/*! CLR24 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR24(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR24_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR24_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR25_MASK    (0x2000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR25_SHIFT   (25U)
/*! CLR25 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR25(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR25_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR25_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR26_MASK    (0x4000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR26_SHIFT   (26U)
/*! CLR26 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR26(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR26_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR26_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR27_MASK    (0x8000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR27_SHIFT   (27U)
/*! CLR27 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR27(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR27_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR27_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR28_MASK    (0x10000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR28_SHIFT   (28U)
/*! CLR28 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR28(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR28_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR28_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR29_MASK    (0x20000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR29_SHIFT   (29U)
/*! CLR29 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR29(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR29_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR29_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR30_MASK    (0x40000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR30_SHIFT   (30U)
/*! CLR30 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR30(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR30_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR30_MASK)

#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR31_MASK    (0x80000000U)
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR31_SHIFT   (31U)
/*! CLR31 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN0 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN0 register.
 */
#define INPUTMUX_DMA0_ITRIGEN0_CLR_CLR31(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN0_CLR_CLR31_SHIFT)) & INPUTMUX_DMA0_ITRIGEN0_CLR_CLR31_MASK)
/*! @} */

/*! @name DMA0_ITRIGEN1_CLR - Clear bits in DMA0_ITRIGEN1 register */
/*! @{ */

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR0_MASK     (0x1U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR0_SHIFT    (0U)
/*! CLR0 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR0(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR0_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR0_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR1_MASK     (0x2U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR1_SHIFT    (1U)
/*! CLR1 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR1(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR1_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR1_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR2_MASK     (0x4U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR2_SHIFT    (2U)
/*! CLR2 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR2(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR2_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR2_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR3_MASK     (0x8U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR3_SHIFT    (3U)
/*! CLR3 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR3(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR3_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR3_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR4_MASK     (0x10U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR4_SHIFT    (4U)
/*! CLR4 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR4(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR4_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR4_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR5_MASK     (0x20U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR5_SHIFT    (5U)
/*! CLR5 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR5(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR5_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR5_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR6_MASK     (0x40U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR6_SHIFT    (6U)
/*! CLR6 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR6(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR6_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR6_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR7_MASK     (0x80U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR7_SHIFT    (7U)
/*! CLR7 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR7(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR7_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR7_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR8_MASK     (0x100U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR8_SHIFT    (8U)
/*! CLR8 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR8(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR8_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR8_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR9_MASK     (0x200U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR9_SHIFT    (9U)
/*! CLR9 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 , no
 *    change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR9(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR9_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR9_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR10_MASK    (0x400U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR10_SHIFT   (10U)
/*! CLR10 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR10(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR10_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR10_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR11_MASK    (0x800U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR11_SHIFT   (11U)
/*! CLR11 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR11(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR11_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR11_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR12_MASK    (0x1000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR12_SHIFT   (12U)
/*! CLR12 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR12(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR12_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR12_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR13_MASK    (0x2000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR13_SHIFT   (13U)
/*! CLR13 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR13(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR13_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR13_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR14_MASK    (0x4000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR14_SHIFT   (14U)
/*! CLR14 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR14(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR14_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR14_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR15_MASK    (0x8000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR15_SHIFT   (15U)
/*! CLR15 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR15(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR15_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR15_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR16_MASK    (0x10000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR16_SHIFT   (16U)
/*! CLR16 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR16(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR16_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR16_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR17_MASK    (0x20000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR17_SHIFT   (17U)
/*! CLR17 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR17(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR17_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR17_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR18_MASK    (0x40000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR18_SHIFT   (18U)
/*! CLR18 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR18(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR18_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR18_MASK)

#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR19_MASK    (0x80000U)
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR19_SHIFT   (19U)
/*! CLR19 - Write : If bit #i = 1, bit #i in DMA0_ITRIGEN1 register is reset to 0; if bit #i = 0 ,
 *    no change in DMA0_ITRIGEN1 register.
 */
#define INPUTMUX_DMA0_ITRIGEN1_CLR_CLR19(x)      (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA0_ITRIGEN1_CLR_CLR19_SHIFT)) & INPUTMUX_DMA0_ITRIGEN1_CLR_CLR19_MASK)
/*! @} */

/*! @name DMA1_ITRIGEN - Enable DMA1 triggers */
/*! @{ */

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN0_MASK      (0x1U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN0_SHIFT     (0U)
/*! ITRIGEN0 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN0(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN0_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN0_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN1_MASK      (0x2U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN1_SHIFT     (1U)
/*! ITRIGEN1 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN1(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN1_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN1_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN2_MASK      (0x4U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN2_SHIFT     (2U)
/*! ITRIGEN2 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN2(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN2_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN2_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN3_MASK      (0x8U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN3_SHIFT     (3U)
/*! ITRIGEN3 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN3(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN3_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN3_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN4_MASK      (0x10U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN4_SHIFT     (4U)
/*! ITRIGEN4 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN4(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN4_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN4_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN5_MASK      (0x20U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN5_SHIFT     (5U)
/*! ITRIGEN5 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN5(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN5_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN5_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN6_MASK      (0x40U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN6_SHIFT     (6U)
/*! ITRIGEN6 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN6(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN6_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN6_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN7_MASK      (0x80U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN7_SHIFT     (7U)
/*! ITRIGEN7 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN7(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN7_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN7_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN8_MASK      (0x100U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN8_SHIFT     (8U)
/*! ITRIGEN8 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN8(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN8_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN8_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN9_MASK      (0x200U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN9_SHIFT     (9U)
/*! ITRIGEN9 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN9(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN9_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN9_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN10_MASK     (0x400U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN10_SHIFT    (10U)
/*! ITRIGEN10 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN10(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN10_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN10_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN11_MASK     (0x800U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN11_SHIFT    (11U)
/*! ITRIGEN11 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN11(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN11_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN11_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN12_MASK     (0x1000U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN12_SHIFT    (12U)
/*! ITRIGEN12 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN12(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN12_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN12_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN13_MASK     (0x2000U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN13_SHIFT    (13U)
/*! ITRIGEN13 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN13(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN13_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN13_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN14_MASK     (0x4000U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN14_SHIFT    (14U)
/*! ITRIGEN14 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN14(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN14_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN14_MASK)

#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN15_MASK     (0x8000U)
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN15_SHIFT    (15U)
/*! ITRIGEN15 - Controls the 16 trigger inputs of DMA1. If bit i is '1' the DMA trigger input #i is enabled. */
#define INPUTMUX_DMA1_ITRIGEN_ITRIGEN15(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_ITRIGEN15_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_ITRIGEN15_MASK)
/*! @} */

/*! @name DMA1_ITRIGEN_SET - Set bits in DMA1_ITRIGEN register */
/*! @{ */

#define INPUTMUX_DMA1_ITRIGEN_SET_SET0_MASK      (0x1U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET0_SHIFT     (0U)
/*! SET0 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET0(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET0_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET0_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET1_MASK      (0x2U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET1_SHIFT     (1U)
/*! SET1 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET1(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET1_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET1_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET2_MASK      (0x4U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET2_SHIFT     (2U)
/*! SET2 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET2(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET2_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET2_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET3_MASK      (0x8U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET3_SHIFT     (3U)
/*! SET3 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET3(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET3_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET3_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET4_MASK      (0x10U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET4_SHIFT     (4U)
/*! SET4 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET4(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET4_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET4_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET5_MASK      (0x20U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET5_SHIFT     (5U)
/*! SET5 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET5(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET5_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET5_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET6_MASK      (0x40U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET6_SHIFT     (6U)
/*! SET6 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET6(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET6_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET6_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET7_MASK      (0x80U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET7_SHIFT     (7U)
/*! SET7 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET7(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET7_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET7_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET8_MASK      (0x100U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET8_SHIFT     (8U)
/*! SET8 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET8(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET8_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET8_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET9_MASK      (0x200U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET9_SHIFT     (9U)
/*! SET9 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET9(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET9_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET9_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET10_MASK     (0x400U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET10_SHIFT    (10U)
/*! SET10 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET10(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET10_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET10_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET11_MASK     (0x800U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET11_SHIFT    (11U)
/*! SET11 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET11(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET11_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET11_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET12_MASK     (0x1000U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET12_SHIFT    (12U)
/*! SET12 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET12(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET12_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET12_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET13_MASK     (0x2000U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET13_SHIFT    (13U)
/*! SET13 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET13(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET13_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET13_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET14_MASK     (0x4000U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET14_SHIFT    (14U)
/*! SET14 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET14(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET14_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET14_MASK)

#define INPUTMUX_DMA1_ITRIGEN_SET_SET15_MASK     (0x8000U)
#define INPUTMUX_DMA1_ITRIGEN_SET_SET15_SHIFT    (15U)
/*! SET15 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is set to 1; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_SET_SET15(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_SET_SET15_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_SET_SET15_MASK)
/*! @} */

/*! @name DMA1_ITRIGEN_CLR - Clear bits in DMA1_ITRIGEN register */
/*! @{ */

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR0_MASK      (0x1U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR0_SHIFT     (0U)
/*! CLR0 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR0(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR0_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR0_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR1_MASK      (0x2U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR1_SHIFT     (1U)
/*! CLR1 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR1(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR1_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR1_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR2_MASK      (0x4U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR2_SHIFT     (2U)
/*! CLR2 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR2(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR2_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR2_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR3_MASK      (0x8U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR3_SHIFT     (3U)
/*! CLR3 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR3(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR3_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR3_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR4_MASK      (0x10U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR4_SHIFT     (4U)
/*! CLR4 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR4(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR4_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR4_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR5_MASK      (0x20U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR5_SHIFT     (5U)
/*! CLR5 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR5(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR5_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR5_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR6_MASK      (0x40U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR6_SHIFT     (6U)
/*! CLR6 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR6(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR6_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR6_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR7_MASK      (0x80U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR7_SHIFT     (7U)
/*! CLR7 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR7(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR7_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR7_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR8_MASK      (0x100U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR8_SHIFT     (8U)
/*! CLR8 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR8(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR8_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR8_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR9_MASK      (0x200U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR9_SHIFT     (9U)
/*! CLR9 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR9(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR9_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR9_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR10_MASK     (0x400U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR10_SHIFT    (10U)
/*! CLR10 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR10(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR10_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR10_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR11_MASK     (0x800U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR11_SHIFT    (11U)
/*! CLR11 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR11(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR11_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR11_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR12_MASK     (0x1000U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR12_SHIFT    (12U)
/*! CLR12 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR12(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR12_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR12_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR13_MASK     (0x2000U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR13_SHIFT    (13U)
/*! CLR13 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR13(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR13_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR13_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR14_MASK     (0x4000U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR14_SHIFT    (14U)
/*! CLR14 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR14(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR14_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR14_MASK)

#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR15_MASK     (0x8000U)
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR15_SHIFT    (15U)
/*! CLR15 - Write : If bit #i = 1, bit #i in DMA1_ITRIGEN register is reset to 0; if bit #i = 0 , no change in DMA1_ITRIGEN register */
#define INPUTMUX_DMA1_ITRIGEN_CLR_CLR15(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DMA1_ITRIGEN_CLR_CLR15_SHIFT)) & INPUTMUX_DMA1_ITRIGEN_CLR_CLR15_MASK)
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

