/*
** ###################################################################
**     Processors:          MCXA165VLH
**                          MCXA165VLL
**                          MCXA165VLQ
**                          MCXA165VPN
**                          MCXA166VLH
**                          MCXA166VLL
**                          MCXA166VLQ
**                          MCXA166VPN
**                          MCXA175VLH
**                          MCXA175VLL
**                          MCXA175VLQ
**                          MCXA175VPN
**                          MCXA176VLH
**                          MCXA176VLL
**                          MCXA176VLQ
**                          MCXA176VPN
**                          MCXA275VLH
**                          MCXA275VLL
**                          MCXA275VLQ
**                          MCXA275VPN
**                          MCXA276VLH
**                          MCXA276VLL
**                          MCXA276VLQ
**                          MCXA276VPN
**
**     Version:             rev. 1.0, 2024-03-26
**     Build:               b241120
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
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**
** ###################################################################
*/

/*!
 * @file INPUTMUX.h
 * @version 1.0
 * @date 2024-03-26
 * @brief CMSIS Peripheral Access Layer for INPUTMUX
 *
 * CMSIS Peripheral Access Layer for INPUTMUX
 */

#if !defined(INPUTMUX_H_)
#define INPUTMUX_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA165VLH) || defined(CPU_MCXA165VLL) || defined(CPU_MCXA165VLQ) || defined(CPU_MCXA165VPN))
#include "MCXA165_COMMON.h"
#elif (defined(CPU_MCXA166VLH) || defined(CPU_MCXA166VLL) || defined(CPU_MCXA166VLQ) || defined(CPU_MCXA166VPN))
#include "MCXA166_COMMON.h"
#elif (defined(CPU_MCXA175VLH) || defined(CPU_MCXA175VLL) || defined(CPU_MCXA175VLQ) || defined(CPU_MCXA175VPN))
#include "MCXA175_COMMON.h"
#elif (defined(CPU_MCXA176VLH) || defined(CPU_MCXA176VLL) || defined(CPU_MCXA176VLQ) || defined(CPU_MCXA176VPN))
#include "MCXA176_COMMON.h"
#elif (defined(CPU_MCXA275VLH) || defined(CPU_MCXA275VLL) || defined(CPU_MCXA275VLQ) || defined(CPU_MCXA275VPN))
#include "MCXA275_COMMON.h"
#elif (defined(CPU_MCXA276VLH) || defined(CPU_MCXA276VLL) || defined(CPU_MCXA276VLQ) || defined(CPU_MCXA276VPN))
#include "MCXA276_COMMON.h"
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
#define INPUTMUX_CTIMERC_COUNT                    4u
#define INPUTMUX_SMARTDMA_TRIGGER_INPUTN_COUNT    8u
#define INPUTMUX_CTIMERD_COUNT                    4u
#define INPUTMUX_CTIMERE_COUNT                    4u
#define INPUTMUX_AOI1_INPUTM_COUNT                16u
#define INPUTMUX_ADC0_TRIGM_COUNT                 4u
#define INPUTMUX_ADC2_TRIGM_COUNT                 4u
#define INPUTMUX_ADC1_TRIGM_COUNT                 4u
#define INPUTMUX_ADC3_TRIGM_COUNT                 4u
#define INPUTMUX_FLEXPWM0_FAULT_COUNT             4u
#define INPUTMUX_FLEXPWM1_FAULT_COUNT             4u
#define INPUTMUX_AOI0_INPUTK_COUNT                16u
#define INPUTMUX_EXT_TRIGN_COUNT                  8u
#define INPUTMUX_FLEXIO_TRIGN_COUNT               4u
#define INPUTMUX_TRIGFILP_COUNT                   12u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t CTIMER0CAP[INPUTMUX_CTIMERA_COUNT]; /**< Capture select register for CTIMER inputs, array offset: 0x20, array step: 0x4 */
  __IO uint32_t TIMER0TRIG;                        /**< Trigger register for TIMER0, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CTIMER1CAP[INPUTMUX_CTIMERB_COUNT]; /**< Capture select register for CTIMER inputs, array offset: 0x40, array step: 0x4 */
  __IO uint32_t TIMER1TRIG;                        /**< Trigger register for TIMER1, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CTIMER2CAP[INPUTMUX_CTIMERC_COUNT]; /**< Capture select register for CTIMER inputs, array offset: 0x60, array step: 0x4 */
  __IO uint32_t TIMER2TRIG;                        /**< Trigger register for TIMER2 inputs, offset: 0x70 */
       uint8_t RESERVED_3[44];
  __IO uint32_t SMARTDMA_TRIG[INPUTMUX_SMARTDMA_TRIGGER_INPUTN_COUNT]; /**< SmartDMA Trigger Input Connections, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_4[192];
  __IO uint32_t FREQMEAS_REF;                      /**< Selection for frequency measurement reference clock, offset: 0x180 */
  __IO uint32_t FREQMEAS_TAR;                      /**< Selection for frequency measurement reference clock, offset: 0x184 */
       uint8_t RESERVED_5[24];
  __IO uint32_t CTIMER3CAP[INPUTMUX_CTIMERD_COUNT]; /**< Capture select register for CTIMER inputs, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t TIMER3TRIG;                        /**< Trigger register for TIMER3, offset: 0x1B0 */
       uint8_t RESERVED_6[12];
  __IO uint32_t CTIMER4CAP[INPUTMUX_CTIMERE_COUNT]; /**< Capture select register for CTIMER inputs, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t TIMER4TRIG;                        /**< Trigger register for TIMER4, offset: 0x1D0 */
       uint8_t RESERVED_7[44];
  __IO uint32_t AOI1_INPUT[INPUTMUX_AOI1_INPUTM_COUNT]; /**< AOI1 trigger input connections 0, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_8[32];
  __IO uint32_t CMP0_TRIG;                         /**< CMP0 input connections, offset: 0x260 */
       uint8_t RESERVED_9[28];
  __IO uint32_t ADC0_TRIG[INPUTMUX_ADC0_TRIGM_COUNT]; /**< ADC Trigger input connections, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_10[16];
  __IO uint32_t ADC2_TRIG[INPUTMUX_ADC2_TRIGM_COUNT]; /**< ADC Trigger input connections, array offset: 0x2A0, array step: 0x4 */
       uint8_t RESERVED_11[16];
  __IO uint32_t ADC1_TRIG[INPUTMUX_ADC1_TRIGM_COUNT]; /**< ADC Trigger input connections, array offset: 0x2C0, array step: 0x4 */
       uint8_t RESERVED_12[16];
  __IO uint32_t ADC3_TRIG[INPUTMUX_ADC3_TRIGM_COUNT]; /**< ADC Trigger input connections, array offset: 0x2E0, array step: 0x4 */
       uint8_t RESERVED_13[16];
  __IO uint32_t DAC0_TRIG;                         /**< DAC0 Trigger input connections., offset: 0x300 */
       uint8_t RESERVED_14[92];
  __IO uint32_t QDC0_TRIG;                         /**< QDC0 Trigger Input Connections, offset: 0x360 */
  __IO uint32_t QDC0_HOME;                         /**< QDC0 Trigger Input Connections, offset: 0x364 */
  __IO uint32_t QDC0_INDEX;                        /**< QDC0 Trigger Input Connections, offset: 0x368 */
  __IO uint32_t QDC0_PHASEB;                       /**< QDC0 Trigger Input Connections, offset: 0x36C */
  __IO uint32_t QDC0_PHASEA;                       /**< QDC0 Trigger Input Connections, offset: 0x370 */
  __IO uint32_t QDC0_ICAP1;                        /**< QDC0 Trigger Input Connections, offset: 0x374 */
  __IO uint32_t QDC0_ICAP2;                        /**< QDC0 Trigger Input Connections, offset: 0x378 */
  __IO uint32_t QDC0_ICAP3;                        /**< QDC0 Trigger Input Connections, offset: 0x37C */
  __IO uint32_t QDC1_TRIG;                         /**< QDC1 Trigger Input Connections, offset: 0x380 */
  __IO uint32_t QDC1_HOME;                         /**< QDC1 Trigger Input Connections, offset: 0x384 */
  __IO uint32_t QDC1_INDEX;                        /**< QDC1 Trigger Input Connections, offset: 0x388 */
  __IO uint32_t QDC1_PHASEB;                       /**< QDC1 Trigger Input Connections, offset: 0x38C */
  __IO uint32_t QDC1_PHASEA;                       /**< QDC1 Trigger Input Connections, offset: 0x390 */
  __IO uint32_t QDC1_ICAP1;                        /**< QDC1 Trigger Input Connections, offset: 0x394 */
  __IO uint32_t QDC1_ICAP2;                        /**< QDC1 Trigger Input Connections, offset: 0x398 */
  __IO uint32_t QDC1_ICAP3;                        /**< QDC1 Trigger Input Connections, offset: 0x39C */
  __IO uint32_t FLEXPWM0_SM0_EXTA0;                /**< PWM0 input trigger connections, offset: 0x3A0 */
  __IO uint32_t FLEXPWM0_SM0_EXTSYNC;              /**< PWM0 input trigger connections, offset: 0x3A4 */
  __IO uint32_t FLEXPWM0_SM1_EXTA;                 /**< PWM0 input trigger connections, offset: 0x3A8 */
  __IO uint32_t FLEXPWM0_SM1_EXTSYNC;              /**< PWM0 input trigger connections, offset: 0x3AC */
  __IO uint32_t FLEXPWM0_SM2_EXTA;                 /**< PWM0 input trigger connections, offset: 0x3B0 */
  __IO uint32_t FLEXPWM0_SM2_EXTSYNC;              /**< PWM0 input trigger connections, offset: 0x3B4 */
  __IO uint32_t FLEXPWM0_SM3_EXTA0;                /**< PWM0 input trigger connections, offset: 0x3B8 */
  __IO uint32_t FLEXPWM0_SM3_EXTSYNC;              /**< PWM0 input trigger connections, offset: 0x3BC */
  __IO uint32_t FLEXPWM0_FAULT[INPUTMUX_FLEXPWM0_FAULT_COUNT]; /**< PWM0 Fault Input Trigger Connections, array offset: 0x3C0, array step: 0x4 */
  __IO uint32_t FLEXPWM0_FORCE;                    /**< PWM0 input trigger connections, offset: 0x3D0 */
       uint8_t RESERVED_15[12];
  __IO uint32_t FLEXPWM1_SM0_EXTA0;                /**< PWM1 input trigger connections, offset: 0x3E0 */
  __IO uint32_t FLEXPWM1_SM0_EXTSYNC;              /**< PWM1 input trigger connections, offset: 0x3E4 */
  __IO uint32_t FLEXPWM1_SM1_EXTA;                 /**< PWM1 input trigger connections, offset: 0x3E8 */
  __IO uint32_t FLEXPWM1_SM1_EXTSYNC;              /**< PWM1 input trigger connections, offset: 0x3EC */
  __IO uint32_t FLEXPWM1_SM2_EXTA;                 /**< PWM1 input trigger connections, offset: 0x3F0 */
  __IO uint32_t FLEXPWM1_SM2_EXTSYNC;              /**< PWM1 input trigger connections, offset: 0x3F4 */
  __IO uint32_t FLEXPWM1_SM3_EXTA0;                /**< PWM1 input trigger connections, offset: 0x3F8 */
  __IO uint32_t FLEXPWM1_SM3_EXTSYNC;              /**< PWM1 input trigger connections, offset: 0x3FC */
  __IO uint32_t FLEXPWM1_FAULT[INPUTMUX_FLEXPWM1_FAULT_COUNT]; /**< PWM1 Fault Input Trigger Connections, array offset: 0x400, array step: 0x4 */
  __IO uint32_t FLEXPWM1_FORCE;                    /**< PWM1 input trigger connections, offset: 0x410 */
       uint8_t RESERVED_16[12];
  __IO uint32_t PWM0_EXT_CLK;                      /**< PWM0 external clock trigger, offset: 0x420 */
  __IO uint32_t PWM1_EXT_CLK;                      /**< PWM1 external clock trigger, offset: 0x424 */
       uint8_t RESERVED_17[24];
  __IO uint32_t AOI0_INPUT[INPUTMUX_AOI0_INPUTK_COUNT]; /**< AOI0 trigger input connections 0, array offset: 0x440, array step: 0x4 */
  __IO uint32_t USBFS_TRIG;                        /**< USB-FS trigger input connections, offset: 0x480 */
       uint8_t RESERVED_18[60];
  __IO uint32_t EXT_TRIG[INPUTMUX_EXT_TRIGN_COUNT]; /**< EXT trigger connections, array offset: 0x4C0, array step: 0x4 */
  __IO uint32_t CMP1_TRIG;                         /**< CMP1 input connections, offset: 0x4E0 */
       uint8_t RESERVED_19[28];
  __IO uint32_t CMP2_TRIG;                         /**< CMP2 input connections, offset: 0x500 */
       uint8_t RESERVED_20[60];
  __IO uint32_t LPI2C2_TRIG;                       /**< LPI2C2 trigger input connections, offset: 0x540 */
       uint8_t RESERVED_21[28];
  __IO uint32_t LPI2C3_TRIG;                       /**< LPI2C3 trigger input connections, offset: 0x560 */
       uint8_t RESERVED_22[60];
  __IO uint32_t LPI2C0_TRIG;                       /**< LPI2C0 trigger input connections, offset: 0x5A0 */
       uint8_t RESERVED_23[28];
  __IO uint32_t LPI2C1_TRIG;                       /**< LPI2C1 trigger input connections, offset: 0x5C0 */
       uint8_t RESERVED_24[28];
  __IO uint32_t LPSPI0_TRIG;                       /**< LPSPI0 trigger input connections, offset: 0x5E0 */
       uint8_t RESERVED_25[28];
  __IO uint32_t LPSPI1_TRIG;                       /**< LPSPI1 trigger input connections, offset: 0x600 */
       uint8_t RESERVED_26[28];
  __IO uint32_t LPUART0r;                          /**< LPUART0 trigger input connections, offset: 0x620, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART0' */
       uint8_t RESERVED_27[28];
  __IO uint32_t LPUART1r;                          /**< LPUART1 trigger input connections, offset: 0x640, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART1' */
       uint8_t RESERVED_28[28];
  __IO uint32_t LPUART2r;                          /**< LPUART2 trigger input connections, offset: 0x660, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART2' */
       uint8_t RESERVED_29[28];
  __IO uint32_t LPUART3r;                          /**< LPUART3 trigger input connections, offset: 0x680, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART3' */
       uint8_t RESERVED_30[28];
  __IO uint32_t LPUART4r;                          /**< LPUART4 trigger input connections, offset: 0x6A0, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART4' */
       uint8_t RESERVED_31[28];
  __IO uint32_t LPUART5r;                          /**< LPUART5 trigger input connections, offset: 0x6C0, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART5' */
       uint8_t RESERVED_32[28];
  __IO uint32_t FLEXIO_TRIG[INPUTMUX_FLEXIO_TRIGN_COUNT]; /**< FlexIO Trigger Input Connections, array offset: 0x6E0, array step: 0x4 */
       uint8_t RESERVED_33[784];
  __IO uint32_t TRIGFIL_PRSC;                      /**< Trigger filter prescaller, offset: 0xA00 */
  __I  uint32_t TRIGFIL_STAT0;                     /**< Trigger filter stat, offset: 0xA04 */
       uint8_t RESERVED_34[8];
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer1_MAT1 input is selected
 *  0b0100010..CTimer1_MAT2 input is selected
 *  0b0100011..CTimer1_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer3_MAT1 input is selected
 *  0b1010000..CTimer3_MAT2 input is selected
 *  0b1010001..CTimer3_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_CTIMERA_CTIMER0CAP_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMERA_CTIMER0CAP_INP_SHIFT)) & INPUTMUX_CTIMERA_CTIMER0CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMERA_CTIMER0CAP */
#define INPUTMUX_CTIMERA_CTIMER0CAP_COUNT        (4U)

/*! @name TIMER0TRIG - Trigger register for TIMER0 */
/*! @{ */

#define INPUTMUX_TIMER0TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER0TRIG_INP_SHIFT            (0U)
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer1_MAT1 input is selected
 *  0b0100010..CTimer1_MAT2 input is selected
 *  0b0100011..CTimer1_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer3_MAT1 input is selected
 *  0b1010000..CTimer3_MAT2 input is selected
 *  0b1010001..CTimer3_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_TIMER0TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER0TRIG_INP_SHIFT)) & INPUTMUX_TIMER0TRIG_INP_MASK)
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer3_MAT1 input is selected
 *  0b1010000..CTimer3_MAT2 input is selected
 *  0b1010001..CTimer3_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_CTIMERB_CTIMER1CAP_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMERB_CTIMER1CAP_INP_SHIFT)) & INPUTMUX_CTIMERB_CTIMER1CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMERB_CTIMER1CAP */
#define INPUTMUX_CTIMERB_CTIMER1CAP_COUNT        (4U)

/*! @name TIMER1TRIG - Trigger register for TIMER1 */
/*! @{ */

#define INPUTMUX_TIMER1TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER1TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER1
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer3_MAT1 input is selected
 *  0b1010000..CTimer3_MAT2 input is selected
 *  0b1010001..CTimer3_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_TIMER1TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER1TRIG_INP_SHIFT)) & INPUTMUX_TIMER1TRIG_INP_MASK)
/*! @} */

/*! @name CTIMERC_CTIMER2CAP - Capture select register for CTIMER inputs */
/*! @{ */

#define INPUTMUX_CTIMERC_CTIMER2CAP_INP_MASK     (0x7FU)
#define INPUTMUX_CTIMERC_CTIMER2CAP_INP_SHIFT    (0U)
/*! INP - Input number for CTIMER2
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer3_MAT1 input is selected
 *  0b1010000..CTimer3_MAT2 input is selected
 *  0b1010001..CTimer3_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_CTIMERC_CTIMER2CAP_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMERC_CTIMER2CAP_INP_SHIFT)) & INPUTMUX_CTIMERC_CTIMER2CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMERC_CTIMER2CAP */
#define INPUTMUX_CTIMERC_CTIMER2CAP_COUNT        (4U)

/*! @name TIMER2TRIG - Trigger register for TIMER2 inputs */
/*! @{ */

#define INPUTMUX_TIMER2TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER2TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER2
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer3_MAT1 input is selected
 *  0b1010000..CTimer3_MAT2 input is selected
 *  0b1010001..CTimer3_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_TIMER2TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER2TRIG_INP_SHIFT)) & INPUTMUX_TIMER2TRIG_INP_MASK)
/*! @} */

/*! @name SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG - SmartDMA Trigger Input Connections */
/*! @{ */

#define INPUTMUX_SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG_INP_MASK (0x7FU)
#define INPUTMUX_SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG_INP_SHIFT (0U)
/*! INP - Input number for SmartDMA.
 *  0b0000000..Reserved
 *  0b0000001..GPIO P0_16 input is selected
 *  0b0000010..GPIO P0_17 input is selected
 *  0b0000011..GPIO P1_8 input is selected
 *  0b0000100..GPIO P1_9 input is selected
 *  0b0000101..GPIO P1_10 input is selected
 *  0b0000110..GPIO P1_11 input is selected
 *  0b0000111..GPIO P1_12 input is selected
 *  0b0001000..GPIO P1_13 input is selected
 *  0b0001001..GPIO P2_0 input is selected
 *  0b0001010..GPIO P2_1 input is selected
 *  0b0001011..GPIO P2_2 input is selected
 *  0b0001100..GPIO P2_3 input is selected
 *  0b0001101..GPIO P2_6 input is selected
 *  0b0001110..GPIO P3_8 input is selected
 *  0b0001111..GPIO P3_9 input is selected
 *  0b0010000..GPIO P3_10 input is selected
 *  0b0010001..GPIO P3_11 input is selected
 *  0b0010010..GPIO P3_12 input is seclected
 *  0b0010011..GPIO0 Pin Event Trig input is selected
 *  0b0010100..GPIO1 Pin Event Trig input is selected
 *  0b0010101..GPIO2 Pin Event Trig input is selected
 *  0b0010110..GPIO3 Pin Event Trig input is selected
 *  0b0010111..GPIO4 Pin Event Trig input is selected
 *  0b0011000..ARM_TXEV input is selected
 *  0b0011001..AOI0_OUT0 input is selected
 *  0b0011010..AOI1_OUT1 input is selected
 *  0b0011011..DMA_IRQ input is selected
 *  0b0011100..MAU_IRQ input is selected
 *  0b0011101..WUU_IRQ input is selected
 *  0b0011110..CTimer0_MAT2 input is selected
 *  0b0011111..CTimer0_MAT3 input is selected
 *  0b0100000..CTimer1_MAT2 input is selected
 *  0b0100001..CTimer1_MAT3 input is selected
 *  0b0100010..CTimer2_MAT2 input is selected
 *  0b0100011..CTimer2_MAT3 input is selected
 *  0b0100100..CTimer3_MAT2 input is selected
 *  0b0100101..CTimer3_MAT3 input is selected
 *  0b0100110..CTimer4_MAT2 input is selected
 *  0b0100111..CTimer4_MAT3 input is selected
 *  0b0101000..OSTIMER_IRQ input is selected
 *  0b0101001..PWM0_IRQ input is selected
 *  0b0101010..PWM1_IRQ input is selected
 *  0b0101011..QDC0_IRQ input is selected
 *  0b0101100..QDC1_IRQ input is selected
 *  0b0101101..RTC_Alarm_IRQ input is selected
 *  0b0101110..RTC_1Hz_IRQ input is selected
 *  0b0101111..uTICK_IRQ input is selected
 *  0b0110000..WDT_IRQ input is selected
 *  0b0110001..Wakeup_Timer_IRQ input is selected
 *  0b0110010..CAN0_IRQ input is selected
 *  0b0110011..CAN1_IRQ input is selected
 *  0b0110100..FlexIO_IRQ input is selected
 *  0b0110101..FlexIO_Shifer0_DMA_Req input is selected
 *  0b0110110..FlexIO_Shifer1_DMA_Req input is selected
 *  0b0110111..FlexIO_Shifer2_DMA_Req input is selected
 *  0b0111000..FlexIO_Shifer3_DMA_Req input is selected
 *  0b0111001..I3C0_IRQ input is selected
 *  0b0111010..LPI2C0_IRQ input is selected
 *  0b0111011..LPI2C1_IRQ input is selected
 *  0b0111100..LPSPI0_IRQ input is selected
 *  0b0111101..LPSPI1_IRQ input is selected
 *  0b0111110..LPUART0_IRQ input is selected
 *  0b0111111..LPUART1_IRQ input is selected
 *  0b1000000..LPUART2_IRQ input is selected
 *  0b1000001..LPUART3_IRQ input is selected
 *  0b1000010..USB0_SOF input is selected
 *  0b1000011..Reserved
 *  0b1000100..ADC0_IRQ input is selected
 *  0b1000101..ADC1_IRQ input is selected
 *  0b1000110..ADC2_IRQ input is selected
 *  0b1000111..ADC3_IRQ input is selected
 *  0b1001000..CMP0_IRQ input is selected
 *  0b1001001..CMP1_IRQ input is selected
 *  0b1001010..CMP2_IRQ input is selected
 *  0b1001011..CMP0_OUT input is selected
 *  0b1001100..CMP1_OUT input is selected
 *  0b1001101..CMP2_OUT input is selected
 *  0b1001110..DAC0_IRQ input is selected
 *  0b1001111..SLCD_IRQ input is selected
 */
#define INPUTMUX_SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG_INP_SHIFT)) & INPUTMUX_SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG */
#define INPUTMUX_SMARTDMA_TRIGGER_INPUTN_SMARTDMA_TRIG_COUNT (8U)

/*! @name FREQMEAS_REF - Selection for frequency measurement reference clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_REF_INP_MASK           (0x7FU)
#define INPUTMUX_FREQMEAS_REF_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function target clock.
 *  0b0000000..Reserved
 *  0b0000001..clk_in input is selected
 *  0b0000010..FRO_OSC_12M input is selected
 *  0b0000011..fro_hf_div input is selected
 *  0b0000100..Reserved
 *  0b0000101..clk_16k[1] input is selected
 *  0b0000110..SLOW_CLK input is selected
 *  0b0000111..FREQME_CLK_IN0 input is selected
 *  0b0001000..FREQME_CLK_IN1 input is selected input is selected
 *  0b0001001..AOI0_OUT0 input is selected
 *  0b0001010..AOI0_OUT1
 *  0b0001011..PWM0_SM0_MUX_TRIG0
 *  0b0001100..PWM0_SM0_MUX_TRIG1
 *  0b0001101..PWM0_SM1_MUX_TRIG0
 *  0b0001110..PWM0_SM1_MUX_TRIG1
 *  0b0001111..PWM0_SM2_MUX_TRIG0
 *  0b0010000..PWM0_SM2_MUX_TRIG1
 *  0b0010001..PWM0_SM3_MUX_TRIG0
 *  0b0010010..PWM0_SM3_MUX_TRIG1
 *  0b0010011..Reserved
 *  0b0010100..Reserved
 *  0b0010101..Reserved
 *  0b0010110..Reserved
 *  0b0010111..Reserved
 *  0b0011000..Reserved
 *  0b0011001..Reserved
 *  0b0011010..Reserved
 *  0b0011011..Reserved
 *  0b0011100..Reserved
 *  0b0011101..Reserved
 *  0b0011110..Reserved
 *  0b0011111..Reserved
 *  0b0100000..AOI1_OUT0 input is selected
 *  0b0100001..AOI1_OUT1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b0100011..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b0100101..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100110..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b0100111..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0101000..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b0101001..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FREQMEAS_REF_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_REF_INP_SHIFT)) & INPUTMUX_FREQMEAS_REF_INP_MASK)
/*! @} */

/*! @name FREQMEAS_TAR - Selection for frequency measurement reference clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_TAR_INP_MASK           (0x7FU)
#define INPUTMUX_FREQMEAS_TAR_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function target clock.
 *  0b0000000..Reserved
 *  0b0000001..clk_in input is selected
 *  0b0000010..FRO_OSC_12M input is selected
 *  0b0000011..fro_hf_div input is selected
 *  0b0000100..Reserved
 *  0b0000101..clk_16k[1] input is selected
 *  0b0000110..SLOW_CLK input is selected
 *  0b0000111..FREQME_CLK_IN0 input is selected
 *  0b0001000..FREQME_CLK_IN1 input is selected input is selected
 *  0b0001001..AOI0_OUT0 input is selected
 *  0b0001010..AOI0_OUT1
 *  0b0001011..PWM0_SM0_MUX_TRIG0
 *  0b0001100..PWM0_SM0_MUX_TRIG1
 *  0b0001101..PWM0_SM1_MUX_TRIG0
 *  0b0001110..PWM0_SM1_MUX_TRIG1
 *  0b0001111..PWM0_SM2_MUX_TRIG0
 *  0b0010000..PWM0_SM2_MUX_TRIG1
 *  0b0010001..PWM0_SM3_MUX_TRIG0
 *  0b0010010..PWM0_SM3_MUX_TRIG1
 *  0b0010011..Reserved
 *  0b0010100..Reserved
 *  0b0010101..Reserved
 *  0b0010110..Reserved
 *  0b0010111..Reserved
 *  0b0011000..Reserved
 *  0b0011001..Reserved
 *  0b0011010..Reserved
 *  0b0011011..Reserved
 *  0b0011100..Reserved
 *  0b0011101..Reserved
 *  0b0011110..Reserved
 *  0b0011111..Reserved
 *  0b0100000..AOI1_OUT0 input is selected
 *  0b0100001..AOI1_OUT1 input is selected
 *  0b0100010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b0100011..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b0100100..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b0100101..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b0100110..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b0100111..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b0101000..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b0101001..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FREQMEAS_TAR_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_TAR_INP_SHIFT)) & INPUTMUX_FREQMEAS_TAR_INP_MASK)
/*! @} */

/*! @name CTIMERD_CTIMER3CAP - Capture select register for CTIMER inputs */
/*! @{ */

#define INPUTMUX_CTIMERD_CTIMER3CAP_INP_MASK     (0x7FU)
#define INPUTMUX_CTIMERD_CTIMER3CAP_INP_SHIFT    (0U)
/*! INP - Input number for CTIMER3
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer2_MAT1 input is selected
 *  0b1010000..CTimer2_MAT2 input is selected
 *  0b1010001..CTimer2_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 *  0b1110001..TRIG_IN0 input is selected
 *  0b1110010..TRIG_IN1 input is selected
 *  0b1110011..TRIG_IN2 input is selected
 *  0b1110100..TRIG_IN3 input is selected
 *  0b1110101..TRIG_IN4 input is selected
 *  0b1110110..TRIG_IN5 input is selected
 *  0b1110111..TRIG_IN6 input is selected
 *  0b1111000..TRIG_IN7 input is selected
 *  0b1111001..TRIG_IN8 input is selected
 *  0b1111010..TRIG_IN9 input is selected
 *  0b1111011..TRIG_IN10 input is selected
 *  0b1111100..TRIG_IN11 input is selected
 */
#define INPUTMUX_CTIMERD_CTIMER3CAP_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMERD_CTIMER3CAP_INP_SHIFT)) & INPUTMUX_CTIMERD_CTIMER3CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMERD_CTIMER3CAP */
#define INPUTMUX_CTIMERD_CTIMER3CAP_COUNT        (4U)

/*! @name TIMER3TRIG - Trigger register for TIMER3 */
/*! @{ */

#define INPUTMUX_TIMER3TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER3TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER3
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer2_MAT1 input is selected
 *  0b1010000..CTimer2_MAT2 input is selected
 *  0b1010001..CTimer2_MAT3 input is selected
 *  0b1010010..CTimer4_MAT1 input is selected
 *  0b1010011..CTimer4_MAT2 input is selected
 *  0b1010100..CTimer4_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 *  0b1110001..TRIG_IN0 input is selected
 *  0b1110010..TRIG_IN1 input is selected
 *  0b1110011..TRIG_IN2 input is selected
 *  0b1110100..TRIG_IN3 input is selected
 *  0b1110101..TRIG_IN4 input is selected
 *  0b1110110..TRIG_IN5 input is selected
 *  0b1110111..TRIG_IN6 input is selected
 *  0b1111000..TRIG_IN7 input is selected
 *  0b1111001..TRIG_IN8 input is selected
 *  0b1111010..TRIG_IN9 input is selected
 *  0b1111011..TRIG_IN10 input is selected
 *  0b1111100..TRIG_IN11 input is selected
 */
#define INPUTMUX_TIMER3TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER3TRIG_INP_SHIFT)) & INPUTMUX_TIMER3TRIG_INP_MASK)
/*! @} */

/*! @name CTIMERE_CTIMER4CAP - Capture select register for CTIMER inputs */
/*! @{ */

#define INPUTMUX_CTIMERE_CTIMER4CAP_INP_MASK     (0x7FU)
#define INPUTMUX_CTIMERE_CTIMER4CAP_INP_SHIFT    (0U)
/*! INP - Input number for CTIMER4
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer2_MAT1 input is selected
 *  0b1010000..CTimer2_MAT2 input is selected
 *  0b1010001..CTimer2_MAT3 input is selected
 *  0b1010010..CTimer3_MAT1 input is selected
 *  0b1010011..CTimer3_MAT2 input is selected
 *  0b1010100..CTimer3_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 *  0b1110001..TRIG_IN0 input is selected
 *  0b1110010..TRIG_IN1 input is selected
 *  0b1110011..TRIG_IN2 input is selected
 *  0b1110100..TRIG_IN3 input is selected
 *  0b1110101..TRIG_IN4 input is selected
 *  0b1110110..TRIG_IN5 input is selected
 *  0b1110111..TRIG_IN6 input is selected
 *  0b1111000..TRIG_IN7 input is selected
 *  0b1111001..TRIG_IN8 input is selected
 *  0b1111010..TRIG_IN9 input is selected
 *  0b1111011..TRIG_IN10 input is selected
 *  0b1111100..TRIG_IN11 input is selected
 */
#define INPUTMUX_CTIMERE_CTIMER4CAP_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMERE_CTIMER4CAP_INP_SHIFT)) & INPUTMUX_CTIMERE_CTIMER4CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMERE_CTIMER4CAP */
#define INPUTMUX_CTIMERE_CTIMER4CAP_COUNT        (4U)

/*! @name TIMER4TRIG - Trigger register for TIMER4 */
/*! @{ */

#define INPUTMUX_TIMER4TRIG_INP_MASK             (0x7FU)
#define INPUTMUX_TIMER4TRIG_INP_SHIFT            (0U)
/*! INP - Input number for CTIMER4
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
 *  0b0010101..USB0 usb0 start of frame input is selected
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0]
 *  0b0011011..ADC0_tcomp[1]
 *  0b0011100..ADC0_tcomp[2]
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT is selected
 *  0b0011111..CMP1_OUT is selected
 *  0b0100000..CMP2_OUT is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..QDC0_CMP_FLAG0 is selected
 *  0b0101000..QDC0_CMP_FLAG1 input is selected
 *  0b0101001..QDC0_CMP_FLAG2 input is selected
 *  0b0101010..QDC0_CMP_FLAG3 input is selected
 *  0b0101011..QDC0_POS_MATCH0 input is selected
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
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
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..LPUART3 Received Data Word input is selected
 *  0b1000010..LPUART3 Transmitted Data Word input is selected
 *  0b1000011..LPUART3 Receive Line Idle input is selected
 *  0b1000100..LPUART4 Received Data Word input is selected
 *  0b1000101..LPUART4 Transmitted Data Word input is selected
 *  0b1000110..LPUART4 Receive Line Idle input is selected
 *  0b1000111..AOI1_OUT0 input is selected
 *  0b1001000..AOI1_OUT1 input is selected
 *  0b1001001..AOI1_OUT2 input is selected
 *  0b1001010..AOI1_OUT3 input is selected
 *  0b1001011..ADC1_tcomp[0] input is selected
 *  0b1001100..ADC1_tcomp[1] input is selected
 *  0b1001101..ADC1_tcomp[2] input is selected
 *  0b1001110..ADC1_tcomp[3] input is selected
 *  0b1001111..CTimer2_MAT1 input is selected
 *  0b1010000..CTimer2_MAT2 input is selected
 *  0b1010001..CTimer2_MAT3 input is selected
 *  0b1010010..CTimer3_MAT1 input is selected
 *  0b1010011..CTimer3_MAT2 input is selected
 *  0b1010100..CTimer3_MAT3 input is selected
 *  0b1010101..QDC1_CMP_FLAG0 input is selected
 *  0b1010110..QDC1_CMP_FLAG1 input is selected
 *  0b1010111..QDC1_CMP_FLAG2 input is selected
 *  0b1011000..QDC1_CMP_FLAG3 input is selected
 *  0b1011001..QDC1_POS_MATCH0 input is selected
 *  0b1011010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1011011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1011100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1011110..LPI2C2 Master End of Packet input is selected
 *  0b1011111..LPI2C2 Slave End of Packet input is selected
 *  0b1100000..LPI2C3 Master End of Packet input is selected
 *  0b1100001..LPI2C3 Slave End of Packet input is selected
 *  0b1100010..LPUART5 Received Data Word input is selected
 *  0b1100011..LPUART5 Transmitted Data Word input is selected
 *  0b1100100..LPUART5 Receive Line Idle input is selected
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..ADC2_tcomp[0] input is selected
 *  0b1101010..ADC2_tcomp[1] input is selected
 *  0b1101011..ADC2_tcomp[2] input is selected
 *  0b1101100..ADC2_tcomp[3] input is selected
 *  0b1101101..ADC3_tcomp[0] input is selected
 *  0b1101110..ADC3_tcomp[1] input is selected
 *  0b1101111..ADC3_tcomp[2] input is selected
 *  0b1110000..ADC3_tcomp[3] input is selected
 *  0b1110001..TRIG_IN0 input is selected
 *  0b1110010..TRIG_IN1 input is selected
 *  0b1110011..TRIG_IN2 input is selected
 *  0b1110100..TRIG_IN3 input is selected
 *  0b1110101..TRIG_IN4 input is selected
 *  0b1110110..TRIG_IN5 input is selected
 *  0b1110111..TRIG_IN6 input is selected
 *  0b1111000..TRIG_IN7 input is selected
 *  0b1111001..TRIG_IN8 input is selected
 *  0b1111010..TRIG_IN9 input is selected
 *  0b1111011..TRIG_IN10 input is selected
 *  0b1111100..TRIG_IN11 input is selected
 */
#define INPUTMUX_TIMER4TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TIMER4TRIG_INP_SHIFT)) & INPUTMUX_TIMER4TRIG_INP_MASK)
/*! @} */

/*! @name AOI1_INPUTM_AOI1_INPUT - AOI1 trigger input connections 0 */
/*! @{ */

#define INPUTMUX_AOI1_INPUTM_AOI1_INPUT_INP_MASK (0x7FU)
#define INPUTMUX_AOI1_INPUTM_AOI1_INPUT_INP_SHIFT (0U)
/*! INP - AOI0 trigger input connections
 *  0b0000000..Reserved
 *  0b0000001..ADC0_tcomp[0] input is selected
 *  0b0000010..ADC0_tcomp[1] input is selected
 *  0b0000011..ADC0_tcomp[2] input is selected
 *  0b0000100..ADC0_tcomp[3] input is selected
 *  0b0000101..CMP0_OUT input is selected
 *  0b0000110..CMP1_OUT input is selected
 *  0b0000111..CMP2_OUT input is selected
 *  0b0001000..CTimer0_MAT0 input is selected
 *  0b0001001..CTimer0_MAT1 input is selected
 *  0b0001010..CTimer0_MAT2 input is selected
 *  0b0001011..CTimer0_MAT3 input is selected
 *  0b0001100..CTimer1_MAT0
 *  0b0001101..CTimer1_MAT1 input is selected
 *  0b0001110..CTimer1_MAT2 input is selected
 *  0b0001111..CTimer1_MAT3 input is selected
 *  0b0010000..CTimer2_MAT0 input is selected
 *  0b0010001..CTimer2_MAT1 input is selected
 *  0b0010010..CTimer2_MAT2 input is selected
 *  0b0010011..CTimer2_MAT3 input is selected
 *  0b0010100..LPTMR0 input is selected
 *  0b0010101..Reserved
 *  0b0010110..QDC0_CMP_FLAG0 input is selected
 *  0b0010111..QDC0_CMP_FLAG1 input is selected
 *  0b0011000..QDC0_CMP_FLAG2 input is selected
 *  0b0011001..QDC0_CMP_FLAG3 input is selected
 *  0b0011010..QDC0_POS_MATCH0 input is selected
 *  0b0011011..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0011100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0011110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0100010..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100011..TRIG_IN0 input is selected
 *  0b0100100..TRIG_IN1 input is selected
 *  0b0100101..TRIG_IN2 input is selected
 *  0b0100110..TRIG_IN3 input is selected
 *  0b0100111..TRIG_IN4 input is selected
 *  0b0101000..TRIG_IN5 input is selected
 *  0b0101001..TRIG_IN6 input is selected
 *  0b0101010..TRIG_IN7 input is selected
 *  0b0101011..TRIG_IN8 input is selected
 *  0b0101100..TRIG_IN9 input is selected
 *  0b0101101..TRIG_IN10 input is selected
 *  0b0101110..TRIG_IN11 input is selected
 *  0b0101111..GPIO0 Pin Event Trig 0 input is selected
 *  0b0110000..GPIO1 Pin Event Trig 0 input is selected
 *  0b0110001..GPIO2 Pin Event Trig 0 input is selected
 *  0b0110010..GPIO3 Pin Event Trig 0 input is selected
 *  0b0110011..GPIO4 Pin Event Trig 0 input is selected
 *  0b0110100..ADC1_tcomp[0] input is selected
 *  0b0110101..ADC1_tcomp[1] input is selected
 *  0b0110110..ADC1_tcomp[2] input is selected
 *  0b0110111..ADC1_tcomp[3] input is selected
 *  0b0111000..CTimer3_MAT0 input is selected
 *  0b0111001..CTimer3_MAT1 input is selected
 *  0b0111010..CTimer3_MAT2 input is selected
 *  0b0111011..CTimer3_MAT3 input is selected
 *  0b0111100..CTimer4_MAT0 input is selected
 *  0b0111101..CTimer4_MAT1 input is selected
 *  0b0111110..CTimer4_MAT2 input is selected
 *  0b0111111..CTimer4_MAT3 input is selected
 *  0b1000000..FlexIO CH0 input is selected
 *  0b1000001..FlexIO CH1 input is selected
 *  0b1000010..FlexIO CH2 input is selected
 *  0b1000011..FlexIO CH3 input is selected
 *  0b1000100..QDC1_CMP_FLAG0 input is selected
 *  0b1000101..QDC1_CMP_FLAG1 input is selected
 *  0b1000110..QDC1_CMP_FLAG2 input is selected
 *  0b1000111..QDC1_CMP_FLAG3 input is selected
 *  0b1001000..QDC1_POS_MATCH0 input is selected
 *  0b1001001..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1001010..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b1001011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1001100..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b1001101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1001110..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b1001111..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1010000..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b1010001..PWM0_SM0_A_Output
 *  0b1010010..PWM0_SM0_B_Output
 *  0b1010011..PWM0_SM1_A_Output
 *  0b1010100..PWM0_SM1_B_Output
 *  0b1010101..PWM0_SM2_A_Output
 *  0b1010110..PWM0_SM2_B_Output
 *  0b1010111..PWM0_SM3_A_Output
 *  0b1011000..PWM0_SM3_B_Output
 *  0b1011001..ADC2_tcomp[0] input is selected
 *  0b1011010..ADC2_tcomp[1] input is selected
 *  0b1011011..ADC2_tcomp[2] input is selected
 *  0b1011100..ADC2_tcomp[3] input is selected
 *  0b1011101..ADC3_tcomp[0] input is selected
 *  0b1011110..ADC3_tcomp[1] input is selected
 *  0b1011111..ADC3_tcomp[2] input is selected
 *  0b1100000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_AOI1_INPUTM_AOI1_INPUT_INP(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AOI1_INPUTM_AOI1_INPUT_INP_SHIFT)) & INPUTMUX_AOI1_INPUTM_AOI1_INPUT_INP_MASK)
/*! @} */

/* The count of INPUTMUX_AOI1_INPUTM_AOI1_INPUT */
#define INPUTMUX_AOI1_INPUTM_AOI1_INPUT_COUNT    (16U)

/*! @name CMP0_TRIG - CMP0 input connections */
/*! @{ */

#define INPUTMUX_CMP0_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_CMP0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - CMP0 input trigger
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP1_OUT input is selected
 *  0b000111..CMP2_OUT input is selected
 *  0b001000..CTimer0_MAT0 input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer1_MAT0
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer2_MAT0 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..LPTMR0 input is selected
 *  0b001111..Reserved
 *  0b010000..QDC0_POS_MATCH0
 *  0b010001..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b010010..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b010011..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b010100..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b010101..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b010110..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011000..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..CTimer3_MAT0
 *  0b101000..CTimer3_MAT1
 *  0b101001..CTimer4_MAT0 input is selected
 *  0b101010..CTimer4_MAT1 input is selected
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..QDC1_POS_MATCH0 input is selected
 *  0b110000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b110110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM2_MUX_TRIG1 input is selected
 */
#define INPUTMUX_CMP0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CMP0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_CMP0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ADC0_TRIGM_ADC0_TRIG - ADC Trigger input connections */
/*! @{ */

#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_MASK (0x3FU)
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC0 trigger inputs
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..QDC0_POS_MATCH0 input is selected
 *  0b010010..PWM0_SM0_OUT_TRIG0 input is selected
 *  0b010011..PWM0_SM0_OUT_TRIG1 input is selected
 *  0b010100..PWM0_SM1_OUT_TRIG0 input is selected
 *  0b010101..PWM0_SM1_OUT_TRIG1 input is selected
 *  0b010110..PWM0_SM2_OUT_TRIG0 input is selected
 *  0b010111..PWM0_SM2_OUT_TRIG1 input is selected
 *  0b011000..PWM0_SM3_OUT_TRIG0 input is selected
 *  0b011001..PWM0_SM3_OUT_TRIG1 input is selected
 *  0b011010..GPIO0 Pin Event Trig 0 input is selected
 *  0b011011..GPIO1 Pin Event Trig 0 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO3 Pin Event Trig 0 input is selected
 *  0b011110..GPIO4 Pin Event Trig 0 input is selected
 *  0b011111..WUU
 *  0b100000..Reserved
 *  0b100001..AOI1_OUT0 input is selected
 *  0b100010..AOI1_OUT1 input is selected
 *  0b100011..AOI1_OUT2 input is selected
 *  0b100100..AOI1_OUT3 input is selected
 *  0b100101..ADC1_tcomp[0] input is selected
 *  0b100110..ADC1_tcomp[1] input is selected
 *  0b100111..ADC1_tcomp[2] input is selected
 *  0b101000..ADC1_tcomp[3] input is selected
 *  0b101001..CTimer3_MAT0 input is selected
 *  0b101010..CTimer3_MAT1 input is selected
 *  0b101011..CTimer4_MAT0 input is selected
 *  0b101100..CTimer4_MAT1 input is selected
 *  0b101101..FlexIO CH0 input is selected
 *  0b101110..FlexIO CH1 input is selected
 *  0b101111..FlexIO CH2 input is selected
 *  0b110000..FlexIO CH3 input is selected
 *  0b110001..QDC1_POS_MATCH0 input is selected
 *  0b110010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110110..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC0_TRIGM_ADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC0_TRIGM_ADC0_TRIG */
#define INPUTMUX_ADC0_TRIGM_ADC0_TRIG_COUNT      (4U)

/*! @name ADC2_TRIGM_ADC2_TRIG - ADC Trigger input connections */
/*! @{ */

#define INPUTMUX_ADC2_TRIGM_ADC2_TRIG_TRIGIN_MASK (0x3FU)
#define INPUTMUX_ADC2_TRIGM_ADC2_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC2 trigger inputs
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..QDC0_POS_MATCH0 input is selected
 *  0b010010..PWM0_SM0_OUT_TRIG0 input is selected
 *  0b010011..PWM0_SM0_OUT_TRIG1 input is selected
 *  0b010100..PWM0_SM1_OUT_TRIG0 input is selected
 *  0b010101..PWM0_SM1_OUT_TRIG1 input is selected
 *  0b010110..PWM0_SM2_OUT_TRIG0 input is selected
 *  0b010111..PWM0_SM2_OUT_TRIG1 input is selected
 *  0b011000..PWM0_SM3_OUT_TRIG0 input is selected
 *  0b011001..PWM0_SM3_OUT_TRIG1 input is selected
 *  0b011010..GPIO0 Pin Event Trig 0 input is selected
 *  0b011011..GPIO1 Pin Event Trig 0 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO3 Pin Event Trig 0 input is selected
 *  0b011110..GPIO4 Pin Event Trig 0 input is selected
 *  0b011111..WUU
 *  0b100000..Reserved
 *  0b100001..AOI1_OUT0 input is selected
 *  0b100010..AOI1_OUT1 input is selected
 *  0b100011..AOI1_OUT2 input is selected
 *  0b100100..AOI1_OUT3 input is selected
 *  0b100101..ADC3_tcomp[0] input is selected
 *  0b100110..ADC3_tcomp[1] input is selected
 *  0b100111..ADC3_tcomp[2] input is selected
 *  0b101000..ADC3_tcomp[3] input is selected
 *  0b101001..CTimer3_MAT0 input is selected
 *  0b101010..CTimer3_MAT1 input is selected
 *  0b101011..CTimer4_MAT0 input is selected
 *  0b101100..CTimer4_MAT1 input is selected
 *  0b101101..FlexIO CH0 input is selected
 *  0b101110..FlexIO CH1 input is selected
 *  0b101111..FlexIO CH2 input is selected
 *  0b110000..FlexIO CH3 input is selected
 *  0b110001..QDC1_POS_MATCH0 input is selected
 *  0b110010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110110..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_ADC2_TRIGM_ADC2_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC2_TRIGM_ADC2_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC2_TRIGM_ADC2_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC2_TRIGM_ADC2_TRIG */
#define INPUTMUX_ADC2_TRIGM_ADC2_TRIG_COUNT      (4U)

/*! @name ADC1_TRIGM_ADC1_TRIG - ADC Trigger input connections */
/*! @{ */

#define INPUTMUX_ADC1_TRIGM_ADC1_TRIG_TRIGIN_MASK (0x3FU)
#define INPUTMUX_ADC1_TRIGM_ADC1_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC1 trigger inputs
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..QDC0_POS_MATCH0 input is selected
 *  0b010010..PWM0_SM0_OUT_TRIG0 input is selected
 *  0b010011..PWM0_SM0_OUT_TRIG1 input is selected
 *  0b010100..PWM0_SM1_OUT_TRIG0 input is selected
 *  0b010101..PWM0_SM1_OUT_TRIG1 input is selected
 *  0b010110..PWM0_SM2_OUT_TRIG0 input is selected
 *  0b010111..PWM0_SM2_OUT_TRIG1 input is selected
 *  0b011000..PWM0_SM3_OUT_TRIG0 input is selected
 *  0b011001..PWM0_SM3_OUT_TRIG1 input is selected
 *  0b011010..GPIO0 Pin Event Trig 0 input is selected
 *  0b011011..GPIO1 Pin Event Trig 0 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO3 Pin Event Trig 0 input is selected
 *  0b011110..GPIO4 Pin Event Trig 0 input is selected
 *  0b011111..WUU
 *  0b100000..Reserved
 *  0b100001..AOI1_OUT0 input is selected
 *  0b100010..AOI1_OUT1 input is selected
 *  0b100011..AOI1_OUT2 input is selected
 *  0b100100..AOI1_OUT3 input is selected
 *  0b100101..ADC0_tcomp[0] input is selected
 *  0b100110..ADC0_tcomp[1] input is selected
 *  0b100111..ADC0_tcomp[2] input is selected
 *  0b101000..ADC0_tcomp[3] input is selected
 *  0b101001..CTimer3_MAT0 input is selected
 *  0b101010..CTimer3_MAT1 input is selected
 *  0b101011..CTimer4_MAT0 input is selected
 *  0b101100..CTimer4_MAT1 input is selected
 *  0b101101..FlexIO CH0 input is selected
 *  0b101110..FlexIO CH1 input is selected
 *  0b101111..FlexIO CH2 input is selected
 *  0b110000..FlexIO CH3 input is selected
 *  0b110001..QDC1_POS_MATCH0 input is selected
 *  0b110010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110110..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_ADC1_TRIGM_ADC1_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC1_TRIGM_ADC1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC1_TRIGM_ADC1_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC1_TRIGM_ADC1_TRIG */
#define INPUTMUX_ADC1_TRIGM_ADC1_TRIG_COUNT      (4U)

/*! @name ADC3_TRIGM_ADC3_TRIG - ADC Trigger input connections */
/*! @{ */

#define INPUTMUX_ADC3_TRIGM_ADC3_TRIG_TRIGIN_MASK (0x3FU)
#define INPUTMUX_ADC3_TRIGM_ADC3_TRIG_TRIGIN_SHIFT (0U)
/*! TRIGIN - ADC3 trigger inputs
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..QDC0_POS_MATCH0 input is selected
 *  0b010010..PWM0_SM0_OUT_TRIG0 input is selected
 *  0b010011..PWM0_SM0_OUT_TRIG1 input is selected
 *  0b010100..PWM0_SM1_OUT_TRIG0 input is selected
 *  0b010101..PWM0_SM1_OUT_TRIG1 input is selected
 *  0b010110..PWM0_SM2_OUT_TRIG0 input is selected
 *  0b010111..PWM0_SM2_OUT_TRIG1 input is selected
 *  0b011000..PWM0_SM3_OUT_TRIG0 input is selected
 *  0b011001..PWM0_SM3_OUT_TRIG1 input is selected
 *  0b011010..GPIO0 Pin Event Trig 0 input is selected
 *  0b011011..GPIO1 Pin Event Trig 0 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO3 Pin Event Trig 0 input is selected
 *  0b011110..GPIO4 Pin Event Trig 0 input is selected
 *  0b011111..WUU
 *  0b100000..Reserved
 *  0b100001..AOI1_OUT0 input is selected
 *  0b100010..AOI1_OUT1 input is selected
 *  0b100011..AOI1_OUT2 input is selected
 *  0b100100..AOI1_OUT3 input is selected
 *  0b100101..ADC2_tcomp[0] input is selected
 *  0b100110..ADC2_tcomp[1] input is selected
 *  0b100111..ADC2_tcomp[2] input is selected
 *  0b101000..ADC2_tcomp[3] input is selected
 *  0b101001..CTimer3_MAT0 input is selected
 *  0b101010..CTimer3_MAT1 input is selected
 *  0b101011..CTimer4_MAT0 input is selected
 *  0b101100..CTimer4_MAT1 input is selected
 *  0b101101..FlexIO CH0 input is selected
 *  0b101110..FlexIO CH1 input is selected
 *  0b101111..FlexIO CH2 input is selected
 *  0b110000..FlexIO CH3 input is selected
 *  0b110001..QDC1_POS_MATCH0 input is selected
 *  0b110010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110110..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_ADC3_TRIGM_ADC3_TRIG_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC3_TRIGM_ADC3_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC3_TRIGM_ADC3_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC3_TRIGM_ADC3_TRIG */
#define INPUTMUX_ADC3_TRIGM_ADC3_TRIG_COUNT      (4U)

/*! @name DAC0_TRIG - DAC0 Trigger input connections. */
/*! @{ */

#define INPUTMUX_DAC0_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_DAC0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - DAC0 trigger input
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b010011..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b010100..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b010101..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b010110..Reserved
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..GPIO0 Pin Event Trig 0 input is selected
 *  0b011011..GPIO1 Pin Event Trig 0 input is selected
 *  0b011100..GPIO2 Pin Event Trig 0 input is selected
 *  0b011101..GPIO3 Pin Event Trig 0 input is selected
 *  0b011110..GPIO4 Pin Event Trig 0 input is selected
 *  0b011111..WUU input is selected
 *  0b100000..Reserved
 *  0b100001..AOI1_OUT0 input is selected
 *  0b100010..AOI1_OUT1 input is selected
 *  0b100011..AOI1_OUT2 input is selected
 *  0b100100..AOI1_OUT3 input is selected
 *  0b100101..ADC0_tcomp[0] input is selected
 *  0b100110..ADC0_tcomp[1] input is selected
 *  0b100111..ADC1_tcomp[0] input is selected
 *  0b101000..ADC1_tcomp[1] input is selected
 *  0b101001..CTimer3_MAT0 input is selected
 *  0b101010..CTimer3_MAT1 input is selected
 *  0b101011..CTimer4_MAT0 input is selected
 *  0b101100..CTimer4_MAT1 input is selected
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 *  0b110000..Reserved
 *  0b110001..Reserved
 *  0b110010..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110110..Reserved
 *  0b110111..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..ADC2_tcomp[0] input is selected
 *  0b111011..ADC2_tcomp[1] input is selected
 *  0b111100..ADC3_tcomp[0] input is selected
 *  0b111101..ADC3_tcomp[1] input is selected
 */
#define INPUTMUX_DAC0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_DAC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_DAC0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name QDC0_TRIG - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_TRIG_INP_MASK              (0x7FU)
#define INPUTMUX_QDC0_TRIG_INP_SHIFT             (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_TRIG_INP(x)                (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_TRIG_INP_SHIFT)) & INPUTMUX_QDC0_TRIG_INP_MASK)
/*! @} */

/*! @name QDC0_HOME - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_HOME_INP_MASK              (0x7FU)
#define INPUTMUX_QDC0_HOME_INP_SHIFT             (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_HOME_INP(x)                (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_HOME_INP_SHIFT)) & INPUTMUX_QDC0_HOME_INP_MASK)
/*! @} */

/*! @name QDC0_INDEX - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_INDEX_INP_MASK             (0x7FU)
#define INPUTMUX_QDC0_INDEX_INP_SHIFT            (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_INDEX_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_INDEX_INP_SHIFT)) & INPUTMUX_QDC0_INDEX_INP_MASK)
/*! @} */

/*! @name QDC0_PHASEB - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_PHASEB_INP_MASK            (0x7FU)
#define INPUTMUX_QDC0_PHASEB_INP_SHIFT           (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_PHASEB_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_PHASEB_INP_SHIFT)) & INPUTMUX_QDC0_PHASEB_INP_MASK)
/*! @} */

/*! @name QDC0_PHASEA - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_PHASEA_INP_MASK            (0x7FU)
#define INPUTMUX_QDC0_PHASEA_INP_SHIFT           (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..Reserved
 *  0b0010111..Reserved
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_PHASEA_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_PHASEA_INP_SHIFT)) & INPUTMUX_QDC0_PHASEA_INP_MASK)
/*! @} */

/*! @name QDC0_ICAP1 - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_ICAP1_INP_MASK             (0x7FU)
#define INPUTMUX_QDC0_ICAP1_INP_SHIFT            (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_ICAP1_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_ICAP1_INP_SHIFT)) & INPUTMUX_QDC0_ICAP1_INP_MASK)
/*! @} */

/*! @name QDC0_ICAP2 - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_ICAP2_INP_MASK             (0x7FU)
#define INPUTMUX_QDC0_ICAP2_INP_SHIFT            (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_ICAP2_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_ICAP2_INP_SHIFT)) & INPUTMUX_QDC0_ICAP2_INP_MASK)
/*! @} */

/*! @name QDC0_ICAP3 - QDC0 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC0_ICAP3_INP_MASK             (0x7FU)
#define INPUTMUX_QDC0_ICAP3_INP_SHIFT            (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC0_ICAP3_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC0_ICAP3_INP_SHIFT)) & INPUTMUX_QDC0_ICAP3_INP_MASK)
/*! @} */

/*! @name QDC1_TRIG - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_TRIG_INP_MASK              (0x7FU)
#define INPUTMUX_QDC1_TRIG_INP_SHIFT             (0U)
/*! INP - QDC1 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC1_TRIG_INP(x)                (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_TRIG_INP_SHIFT)) & INPUTMUX_QDC1_TRIG_INP_MASK)
/*! @} */

/*! @name QDC1_HOME - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_HOME_INP_MASK              (0x7FU)
#define INPUTMUX_QDC1_HOME_INP_SHIFT             (0U)
/*! INP - QDC1 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC1_HOME_INP(x)                (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_HOME_INP_SHIFT)) & INPUTMUX_QDC1_HOME_INP_MASK)
/*! @} */

/*! @name QDC1_INDEX - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_INDEX_INP_MASK             (0x7FU)
#define INPUTMUX_QDC1_INDEX_INP_SHIFT            (0U)
/*! INP - QDC1 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..>CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC1_INDEX_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_INDEX_INP_SHIFT)) & INPUTMUX_QDC1_INDEX_INP_MASK)
/*! @} */

/*! @name QDC1_PHASEB - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_PHASEB_INP_MASK            (0x7FU)
#define INPUTMUX_QDC1_PHASEB_INP_SHIFT           (0U)
/*! INP - QDC1 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 inout is selected
 */
#define INPUTMUX_QDC1_PHASEB_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_PHASEB_INP_SHIFT)) & INPUTMUX_QDC1_PHASEB_INP_MASK)
/*! @} */

/*! @name QDC1_PHASEA - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_PHASEA_INP_MASK            (0x7FU)
#define INPUTMUX_QDC1_PHASEA_INP_SHIFT           (0U)
/*! INP - QDC0 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC1_PHASEA_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_PHASEA_INP_SHIFT)) & INPUTMUX_QDC1_PHASEA_INP_MASK)
/*! @} */

/*! @name QDC1_ICAP1 - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_ICAP1_INP_MASK             (0x7FU)
#define INPUTMUX_QDC1_ICAP1_INP_SHIFT            (0U)
/*! INP - QDC1 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC1_ICAP1_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_ICAP1_INP_SHIFT)) & INPUTMUX_QDC1_ICAP1_INP_MASK)
/*! @} */

/*! @name QDC1_ICAP2 - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_ICAP2_INP_MASK             (0x7FU)
#define INPUTMUX_QDC1_ICAP2_INP_SHIFT            (0U)
/*! INP - QDC1 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC1_ICAP2_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_ICAP2_INP_SHIFT)) & INPUTMUX_QDC1_ICAP2_INP_MASK)
/*! @} */

/*! @name QDC1_ICAP3 - QDC1 Trigger Input Connections */
/*! @{ */

#define INPUTMUX_QDC1_ICAP3_INP_MASK             (0x7FU)
#define INPUTMUX_QDC1_ICAP3_INP_SHIFT            (0U)
/*! INP - QDC1 input connections
 *  0b0000000..Reserved
 *  0b0000001..ARM_TXEV input is selected
 *  0b0000010..AOI0_OUT0 input is selected
 *  0b0000011..AOI0_OUT1 input is selected
 *  0b0000100..AOI0_OUT2 input is selected
 *  0b0000101..AOI0_OUT3 input is selected
 *  0b0000110..CMP0_OUT input is selected
 *  0b0000111..CMP1_OUT input is selected
 *  0b0001000..CMP2_OUT input is selected
 *  0b0001001..CTimer0_MAT2 input is selected
 *  0b0001010..CTimer0_MAT3
 *  0b0001011..CTimer1_MAT2 input is selected
 *  0b0001100..CTimer1_MAT3 input is selected
 *  0b0001101..CTimer2_MAT2 input is selected
 *  0b0001110..CTimer2_MAT3 input is selected
 *  0b0001111..Reserved
 *  0b0010000..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010001..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0010010..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010011..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0010100..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0010110..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..TRIG_IN8 input is selected
 *  0b0100001..TRIG_IN9 input is selected
 *  0b0100010..TRIG_IN10 input is selected
 *  0b0100011..TRIG_IN11 input is selected
 *  0b0100100..GPIO0 Pin Event Trig 0 is selected
 *  0b0100101..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100110..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100111..GPIO3 Pin Event Trig 0 input is selected
 *  0b0101000..GPIO4 Pin Event Trig 0 input is selected
 *  0b0101001..AOI1_OUT0 input is selected
 *  0b0101010..AOI1_OUT1 input is selected
 *  0b0101011..AOI1_OUT2 input is selected
 *  0b0101100..AOI1_OUT3 input is selected
 *  0b0101101..Reserved
 *  0b0101110..Reserved
 *  0b0101111..Reserved
 *  0b0110000..Reserved
 *  0b0110001..CTimer3_MAT2 input is selected
 *  0b0110010..CTimer3_MAT3 input is selected
 *  0b0110011..CTimer4_MAT2 input is selected
 *  0b0110100..CTimer4_MAT3 input is selected
 *  0b0110101..Reserved
 *  0b0110110..Reserved
 *  0b0110111..Reserved
 *  0b0111000..Reserved
 *  0b0111001..Reserved
 *  0b0111010..Reserved
 *  0b0111011..Reserved
 *  0b0111100..Reserved
 *  0b0111101..Reserved
 *  0b0111110..PWM1_SM0_OUT_TRIG0 input is selected
 *  0b0111111..PWM1_SM0_OUT_TRIG1 input is selected
 *  0b1000000..PWM1_SM1_OUT_TRIG0 input is selected
 *  0b1000001..PWM1_SM1_OUT_TRIG1 input is selected
 *  0b1000010..PWM1_SM2_OUT_TRIG0 input is selected
 *  0b1000011..PWM1_SM2_OUT_TRIG1 input is selected
 *  0b1000100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1000101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_QDC1_ICAP3_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_QDC1_ICAP3_INP_SHIFT)) & INPUTMUX_QDC1_ICAP3_INP_MASK)
/*! @} */

/*! @name FLEXPWM0_SM0_EXTA0 - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_MASK  (0x3FU)
#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM0_EXTSYNC - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM1_EXTA - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM1_EXTSYNC - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM2_EXTA - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM2_EXTSYNC - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM3_EXTA0 - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM3_EXTA0_TRIGIN_MASK  (0x3FU)
#define INPUTMUX_FLEXPWM0_SM3_EXTA0_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM3_EXTA0_TRIGIN(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM3_EXTA0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM3_EXTA0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM3_EXTSYNC - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT - PWM0 Fault Input Trigger Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT_TRIGIN_SHIFT     (0U)
/*! TRIGIN - FAULT input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_FAULT_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FORCE - PWM0 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN_SHIFT     (0U)
/*! TRIGIN - Trigger input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM1_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FORCE_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FORCE_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM0_EXTA0 - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM0_EXTA0_TRIGIN_MASK  (0x3FU)
#define INPUTMUX_FLEXPWM1_SM0_EXTA0_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM0_EXTA0_TRIGIN(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM0_EXTA0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM0_EXTA0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM0_EXTSYNC - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM0_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM1_SM0_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM0_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM0_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM0_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM1_EXTA - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM1_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM1_SM1_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM1_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM1_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM1_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM1_EXTSYNC - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM1_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM1_SM1_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM1_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM1_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM1_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM2_EXTA - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM2_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM1_SM2_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM2_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM2_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM2_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM2_EXTSYNC - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM2_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM1_SM2_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM2_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM2_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM2_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM3_EXTA0 - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM3_EXTA0_TRIGIN_MASK  (0x3FU)
#define INPUTMUX_FLEXPWM1_SM3_EXTA0_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTA input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM3_EXTA0_TRIGIN(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM3_EXTA0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM3_EXTA0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_SM3_EXTSYNC - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_SM3_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM1_SM3_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - EXTSYNC input connections for PWM0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_SM3_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_SM3_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_SM3_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_FAULT - PWM1 Fault Input Trigger Connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_FAULT_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_FLEXPWM1_FAULT_TRIGIN_SHIFT     (0U)
/*! TRIGIN - FAULT input connections for PWM1
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_FAULT_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_FAULT_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_FAULT_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM1_FORCE - PWM1 input trigger connections */
/*! @{ */

#define INPUTMUX_FLEXPWM1_FORCE_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_FLEXPWM1_FORCE_TRIGIN_SHIFT     (0U)
/*! TRIGIN - Trigger input connections for PWM1
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..QDC0_CMP_FLAG0 input is selected
 *  0b010000..QDC0_CMP_FLAG1 input is selected
 *  0b010001..QDC0_CMP_FLAG2 input is selected
 *  0b010010..QDC0_CMP_FLAG3 input is selected
 *  0b010011..QDC0_POS_MATCH0 input is selected
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
 *  0b100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b100101..AOI1_OUT0 input is selected
 *  0b100110..AOI1_OUT1 input is selected
 *  0b100111..AOI1_OUT2 input is selected
 *  0b101000..AOI1_OUT3 input is selected
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..CTimer3_MAT2 input is selected
 *  0b101110..CTimer3_MAT3 input is selected
 *  0b101111..CTimer4_MAT2 input is selected
 *  0b110000..CTimer4_MAT3 input is selected
 *  0b110001..QDC1_CMP_FLAG0 input is selected
 *  0b110010..QDC1_CMP_FLAG1 input is selected
 *  0b110011..QDC1_CMP_FLAG2 input is selected
 *  0b110100..QDC1_CMP_FLAG3 input is selected
 *  0b110101..QDC1_POS_MATCH0 input is selected
 *  0b110110..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b110111..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b111000..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b111001..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b111010..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b111011..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b111100..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b111101..PWM0_SM3_MUX_TRIG1 input is selected
 */
#define INPUTMUX_FLEXPWM1_FORCE_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM1_FORCE_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM1_FORCE_TRIGIN_MASK)
/*! @} */

/*! @name PWM0_EXT_CLK - PWM0 external clock trigger */
/*! @{ */

#define INPUTMUX_PWM0_EXT_CLK_TRIGIN_MASK        (0xFU)
#define INPUTMUX_PWM0_EXT_CLK_TRIGIN_SHIFT       (0U)
/*! TRIGIN - Trigger input connections for PWM
 *  0b0000..Reserved
 *  0b0001..clk_16k[1] input is selected
 *  0b0010..clk_in input is selected
 *  0b0011..AOI0_OUT0 input is selected
 *  0b0100..AOI0_OUT1 input is selected
 *  0b0101..EXTTRIG_IN0 input is selected
 *  0b0110..EXTTRIG_IN7 input is selected
 *  0b0111..AOI1_OUT0 input is selected
 *  0b1000..AOI1_OUT1 input is selected
 */
#define INPUTMUX_PWM0_EXT_CLK_TRIGIN(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXT_CLK_TRIGIN_SHIFT)) & INPUTMUX_PWM0_EXT_CLK_TRIGIN_MASK)
/*! @} */

/*! @name PWM1_EXT_CLK - PWM1 external clock trigger */
/*! @{ */

#define INPUTMUX_PWM1_EXT_CLK_TRIGIN_MASK        (0xFU)
#define INPUTMUX_PWM1_EXT_CLK_TRIGIN_SHIFT       (0U)
/*! TRIGIN - Trigger input connections for PWM
 *  0b0000..Reserved
 *  0b0001..clk_16k[1] input is selected
 *  0b0010..clk_in input is selected
 *  0b0011..AOI0_OUT0 input is selected
 *  0b0100..AOI0_OUT1 input is selected
 *  0b0101..EXTTRIG_IN0 input is selected
 *  0b0110..EXTTRIG_IN7 input is selected
 *  0b0111..AOI1_OUT0 input is selected
 *  0b1000..AOI1_OUT1 input is selected
 */
#define INPUTMUX_PWM1_EXT_CLK_TRIGIN(x)          (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM1_EXT_CLK_TRIGIN_SHIFT)) & INPUTMUX_PWM1_EXT_CLK_TRIGIN_MASK)
/*! @} */

/*! @name AOI0_INPUTK_AOI0_INPUT - AOI0 trigger input connections 0 */
/*! @{ */

#define INPUTMUX_AOI0_INPUTK_AOI0_INPUT_INP_MASK (0x7FU)
#define INPUTMUX_AOI0_INPUTK_AOI0_INPUT_INP_SHIFT (0U)
/*! INP - AOI0 trigger input connections
 *  0b0000000..Reserved
 *  0b0000001..ADC0_tcomp[0] input is selected
 *  0b0000010..ADC0_tcomp[1] input is selected
 *  0b0000011..ADC0_tcomp[2] input is selected
 *  0b0000100..ADC0_tcomp[3] input is selected
 *  0b0000101..CMP0_OUT input is selected
 *  0b0000110..CMP1_OUT input is selected
 *  0b0000111..CMP2_OUT input is selected
 *  0b0001000..CTimer0_MAT0 input is selected
 *  0b0001001..CTimer0_MAT1 input is selected
 *  0b0001010..CTimer0_MAT2 input is selected
 *  0b0001011..CTimer0_MAT3 input is selected
 *  0b0001100..CTimer1_MAT0 input is selected
 *  0b0001101..CTimer1_MAT1 input is selected
 *  0b0001110..CTimer1_MAT2 input is selected
 *  0b0001111..CTimer1_MAT3 input is selected
 *  0b0010000..CTimer2_MAT0 input is selected
 *  0b0010001..CTimer2_MAT1 input is selected
 *  0b0010010..CTimer2_MAT2 input is selected
 *  0b0010011..CTimer2_MAT3 input is selected
 *  0b0010100..LPTMR0 input is selected
 *  0b0010101..Reserved
 *  0b0010110..QDC0_CMP_FLAG0 input is selected
 *  0b0010111..QDC0_CMP_FLAG1 input is selected
 *  0b0011000..QDC0_CMP_FLAG2 input is selected
 *  0b0011001..QDC0_CMP_FLAG3 input is selected
 *  0b0011010..QDC0_POS_MATCH0 input is selected
 *  0b0011011..PWM0_SM0_MUX_TRIG0 0 input is selected
 *  0b0011100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b0011101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0011110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b0011111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0100000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b0100001..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0100010..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b0100011..TRIG_IN0 input is selected
 *  0b0100100..TRIG_IN1 input is selected
 *  0b0100101..TRIG_IN2 input is selected
 *  0b0100110..TRIG_IN3 input is selected
 *  0b0100111..TRIG_IN4 input is selected
 *  0b0101000..TRIG_IN5 input is selected
 *  0b0101001..TRIG_IN6 input is selected
 *  0b0101010..TRIG_IN7 input is selected
 *  0b0101011..TRIG_IN8 input is selected
 *  0b0101100..TRIG_IN9 input is selected
 *  0b0101101..TRIG_IN10 input is selected
 *  0b0101110..TRIG_IN11 input is selected
 *  0b0101111..GPIO0 Pin Event Trig 0 input is selected
 *  0b0110000..GPIO1 Pin Event Trig 0 input is selected
 *  0b0110001..GPIO2 Pin Event Trig 0 input is selected
 *  0b0110010..GPIO3 Pin Event Trig 0 input is selected
 *  0b0110011..GPIO4 Pin Event Trig 0 input is selected
 *  0b0110100..ADC1_tcomp[0] input is selected
 *  0b0110101..ADC1_tcomp[1] input is selected
 *  0b0110110..ADC1_tcomp[2] input is selected
 *  0b0110111..ADC1_tcomp[3] input is selected
 *  0b0111000..CTimer3_MAT0 input is selected
 *  0b0111001..CTimer3_MAT1 input is selected
 *  0b0111010..CTimer3_MAT2 input is selected
 *  0b0111011..CTimer3_MAT3 input is selected
 *  0b0111100..CTimer4_MAT0 input is selected
 *  0b0111101..CTimer4_MAT1 input is selected
 *  0b0111110..CTimer4_MAT2 input is selected
 *  0b0111111..CTimer4_MAT3 input is selected
 *  0b1000000..FlexIO CH0 input is selected
 *  0b1000001..FlexIO CH1 input is selected
 *  0b1000010..FlexIO CH2 input is selected
 *  0b1000011..FlexIO CH3 input is selected
 *  0b1000100..QDC1_CMP_FLAG0 input is selected
 *  0b1000101..QDC1_CMP_FLAG1 input is selected
 *  0b1000110..QDC1_CMP_FLAG2 input is selected
 *  0b1000111..QDC1_CMP_FLAG3 input is selected
 *  0b1001000..QDC1_POS_MATCH0 input is selected
 *  0b1001001..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1001010..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b1001011..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1001100..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b1001101..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1001110..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b1001111..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1010000..PWM1_SM3_MUX_TRIG1 input is selected
 *  0b1010001..PWM0_SM0_A_Output
 *  0b1010010..PWM0_SM0_B_Output
 *  0b1010011..PWM0_SM1_A_Output
 *  0b1010100..PWM0_SM1_B_Output
 *  0b1010101..PWM0_SM2_A_Output
 *  0b1010110..PWM0_SM2_B_Output
 *  0b1010111..PWM0_SM3_A_Output
 *  0b1011000..PWM0_SM3_B_Output
 *  0b1011001..ADC2_tcomp[0] input is selected
 *  0b1011010..ADC2_tcomp[1] input is selected
 *  0b1011011..ADC2_tcomp[2] input is selected
 *  0b1011100..ADC2_tcomp[3] input is selected
 *  0b1011101..ADC3_tcomp[0] input is selected
 *  0b1011110..ADC3_tcomp[1] input is selected
 *  0b1011111..ADC3_tcomp[2] input is selected
 *  0b1100000..ADC3_tcomp[3] input is selected
 */
#define INPUTMUX_AOI0_INPUTK_AOI0_INPUT_INP(x)   (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AOI0_INPUTK_AOI0_INPUT_INP_SHIFT)) & INPUTMUX_AOI0_INPUTK_AOI0_INPUT_INP_MASK)
/*! @} */

/* The count of INPUTMUX_AOI0_INPUTK_AOI0_INPUT */
#define INPUTMUX_AOI0_INPUTK_AOI0_INPUT_COUNT    (16U)

/*! @name USBFS_TRIG - USB-FS trigger input connections */
/*! @{ */

#define INPUTMUX_USBFS_TRIG_INP_MASK             (0xFU)
#define INPUTMUX_USBFS_TRIG_INP_SHIFT            (0U)
/*! INP - USB-FS trigger input connections.
 *  0b0000..Reserved
 *  0b0001..LPUART0 lpuart_trg_txdata input is selected
 *  0b0010..LPUART1 lpuart_trg_txdata input is selected
 *  0b0011..LPUART2 lpuart_trg_txdata input is selected
 *  0b0100..LPUART3 lpuart_trg_txdata input is selected
 *  0b0101..LPUART4 lpuart_trg_txdata input is selected
 *  0b0110..LPUART5 lpuart_trg_txdata input is selected
 */
#define INPUTMUX_USBFS_TRIG_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_USBFS_TRIG_INP_SHIFT)) & INPUTMUX_USBFS_TRIG_INP_MASK)
/*! @} */

/*! @name EXT_TRIGN_EXT_TRIG - EXT trigger connections */
/*! @{ */

#define INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_MASK     (0x1FU)
#define INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_SHIFT    (0U)
/*! INP - EXT trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..CMP1_OUT input is selected
 *  0b01000..CMP2_OUT input is selected
 *  0b01001..LPUART0 ipp_do_lpuart_txd input is selected
 *  0b01010..LPUART1 ipp_do_lpuart_txd input is selected
 *  0b01011..LPUART2 ipp_do_lpuart_txd input is selected
 *  0b01100..LPUART3 ipp_do_lpuart_txd input is selected
 *  0b01101..LPUART4 ipp_do_lpuart_txd input is selected
 *  0b01110..AOI1_OUT0 input is selected
 *  0b01111..AOI1_OUT1 input is selected
 *  0b10000..AOI1_OUT2 input is selected
 *  0b10001..RTC_1Hz_CLK input is selected
 *  0b10010..LPUART5 ipp_do_lpuart_txd input is selected
 */
#define INPUTMUX_EXT_TRIGN_EXT_TRIG_INP(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_SHIFT)) & INPUTMUX_EXT_TRIGN_EXT_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_EXT_TRIGN_EXT_TRIG */
#define INPUTMUX_EXT_TRIGN_EXT_TRIG_COUNT        (8U)

/*! @name CMP1_TRIG - CMP1 input connections */
/*! @{ */

#define INPUTMUX_CMP1_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_CMP1_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - CMP1 input trigger
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP2_OUT input is selected
 *  0b001000..CTimer0_MAT0 input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer1_MAT0
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer2_MAT0 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..LPTMR0 input is selected
 *  0b001111..Reserved
 *  0b010000..QDC0_POS_MATCH0
 *  0b010001..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b010010..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b010011..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b010100..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b010101..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b010110..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011000..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..CTimer3_MAT0
 *  0b101000..CTimer3_MAT1
 *  0b101001..CTimer4_MAT0 input is selected
 *  0b101010..CTimer4_MAT1 input is selected
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..QDC1_POS_MATCH0 input is selected
 *  0b110000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b110110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM2_MUX_TRIG1 input is selected
 */
#define INPUTMUX_CMP1_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CMP1_TRIG_TRIGIN_SHIFT)) & INPUTMUX_CMP1_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name CMP2_TRIG - CMP2 input connections */
/*! @{ */

#define INPUTMUX_CMP2_TRIG_TRIGIN_MASK           (0x3FU)
#define INPUTMUX_CMP2_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - CMP2 input trigger
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CTimer0_MAT0 input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer1_MAT0
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer2_MAT0 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..LPTMR0 input is selected
 *  0b001111..Reserved
 *  0b010000..QDC0_POS_MATCH0 input is selected
 *  0b010001..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b010010..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b010011..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b010100..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b010101..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b010110..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b011000..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..CTimer3_MAT0
 *  0b101000..CTimer3_MAT1
 *  0b101001..CTimer4_MAT0 input is selected
 *  0b101010..CTimer4_MAT1 input is selected
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..QDC1_POS_MATCH0 input is selected
 *  0b110000..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b110001..PWM1_SM0_MUX_TRIG1 input is selected
 *  0b110010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b110011..PWM1_SM1_MUX_TRIG1 input is selected
 *  0b110100..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b110101..PWM1_SM2_MUX_TRIG1 input is selected
 *  0b110110..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b110111..PWM1_SM2_MUX_TRIG1 input is selected
 */
#define INPUTMUX_CMP2_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CMP2_TRIG_TRIGIN_SHIFT)) & INPUTMUX_CMP2_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name LPI2C2_TRIG - LPI2C2 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C2_TRIG_INP_MASK            (0x3FU)
#define INPUTMUX_LPI2C2_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C2 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
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
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..CTimer3_MAT2 input is selected
 *  0b100100..CTimer3_MAT3 input is selected
 *  0b100101..CTimer4_MAT2 input is selected
 *  0b100110..CTimer4_MAT3 input is selected
 *  0b100111..FlexIO CH0 input is selected
 *  0b101000..FlexIO CH1 input is selected
 *  0b101001..FlexIO CH2 input is selected
 *  0b101010..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPI2C2_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C2_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C2_TRIG_INP_MASK)
/*! @} */

/*! @name LPI2C3_TRIG - LPI2C3 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C3_TRIG_INP_MASK            (0x3FU)
#define INPUTMUX_LPI2C3_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C3 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
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
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..CTimer3_MAT2 input is selected
 *  0b100100..CTimer3_MAT3 input is selected
 *  0b100101..CTimer4_MAT2 input is selected
 *  0b100110..CTimer4_MAT3 input is selected
 *  0b100111..FlexIO CH0 input is selected
 *  0b101000..FlexIO CH1 input is selected
 *  0b101001..FlexIO CH2 input is selected
 *  0b101010..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPI2C3_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C3_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C3_TRIG_INP_MASK)
/*! @} */

/*! @name LPI2C0_TRIG - LPI2C0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C0_TRIG_INP_MASK            (0x3FU)
#define INPUTMUX_LPI2C0_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
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
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..CTimer3_MAT2 input is selected
 *  0b100100..CTimer3_MAT3 input is selected
 *  0b100101..CTimer4_MAT2 input is selected
 *  0b100110..CTimer4_MAT3 input is selected
 *  0b100111..FlexIO CH0 input is selected
 *  0b101000..FlexIO CH1 input is selected
 *  0b101001..FlexIO CH2 input is selected
 *  0b101010..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPI2C0_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C0_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C0_TRIG_INP_MASK)
/*! @} */

/*! @name LPI2C1_TRIG - LPI2C1 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C1_TRIG_INP_MASK            (0x3FU)
#define INPUTMUX_LPI2C1_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C1 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT0 input is selected
 *  0b001010..CTimer0_MAT1 input is selected
 *  0b001011..CTimer1_MAT0 input is selected
 *  0b001100..CTimer1_MAT1 input is selected
 *  0b001101..CTimer2_MAT0 input is selected
 *  0b001110..CTimer2_MAT1 input is selected
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
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..CTimer3_MAT2 input is selected
 *  0b100100..CTimer3_MAT3 input is selected
 *  0b100101..CTimer4_MAT2 input is selected
 *  0b100110..CTimer4_MAT3 input is selected
 *  0b100111..FlexIO CH0 input is selected
 *  0b101000..FlexIO CH1 input is selected
 *  0b101001..FlexIO CH2 input is selected
 *  0b101010..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPI2C1_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C1_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C1_TRIG_INP_MASK)
/*! @} */

/*! @name LPSPI0_TRIG - LPSPI0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPSPI0_TRIG_INP_MASK            (0x3FU)
#define INPUTMUX_LPSPI0_TRIG_INP_SHIFT           (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT1 input is selected
 *  0b001010..CTimer0_MAT2 input is selected
 *  0b001011..CTimer1_MAT1 input is selected
 *  0b001100..CTimer1_MAT2 input is selected
 *  0b001101..CTimer2_MAT1 input is selected
 *  0b001110..CTimer2_MAT2 input is selected
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
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..CTimer3_MAT2 input is selected
 *  0b100100..CTimer3_MAT3 input is selected
 *  0b100101..CTimer4_MAT2 input is selected
 *  0b100110..CTimer4_MAT3 input is selected
 *  0b100111..FlexIO CH0 input is selected
 *  0b101000..FlexIO CH1 input is selected
 *  0b101001..FlexIO CH2 input is selected
 *  0b101010..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPSPI0_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPSPI0_TRIG_INP_SHIFT)) & INPUTMUX_LPSPI0_TRIG_INP_MASK)
/*! @} */

/*! @name LPSPI1_TRIG - LPSPI1 trigger input connections */
/*! @{ */

#define INPUTMUX_LPSPI1_TRIG_INP_MASK            (0x3FU)
#define INPUTMUX_LPSPI1_TRIG_INP_SHIFT           (0U)
/*! INP - LPSPI1 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT1 input is selected
 *  0b001010..CTimer0_MAT2 input is selected
 *  0b001011..CTimer1_MAT1 input is selected
 *  0b001100..CTimer1_MAT2 input is selected
 *  0b001101..CTimer2_MAT1 input is selected
 *  0b001110..CTimer2_MAT2 input is selected
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
 *  0b011001..GPIO0 Pin Event Trig 0 input is selected
 *  0b011010..GPIO1 Pin Event Trig 0 input is selected
 *  0b011011..GPIO2 Pin Event Trig 0 input is selected
 *  0b011100..GPIO3 Pin Event Trig 0 input is selected
 *  0b011101..GPIO4 Pin Event Trig 0 input is selected
 *  0b011110..WUU input is selected
 *  0b011111..AOI1_OUT0 input is selected
 *  0b100000..AOI1_OUT1 input is selected
 *  0b100001..AOI1_OUT2 input is selected
 *  0b100010..AOI1_OUT3 input is selected
 *  0b100011..CTimer3_MAT2 input is selected
 *  0b100100..CTimer3_MAT3 input is selected
 *  0b100101..CTimer4_MAT2 input is selected
 *  0b100110..CTimer4_MAT3 input is selected
 *  0b100111..FlexIO CH0 input is selected
 *  0b101000..FlexIO CH1 input is selected
 *  0b101001..FlexIO CH2 input is selected
 *  0b101010..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPSPI1_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPSPI1_TRIG_INP_SHIFT)) & INPUTMUX_LPSPI1_TRIG_INP_MASK)
/*! @} */

/*! @name LPUART0 - LPUART0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART0_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART0_INP_SHIFT               (0U)
/*! INP - LPUART0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
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
 *  0b100001..GPIO4 Pin Event Trig 0 input is selected
 *  0b100010..WUU selected
 *  0b100011..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100100..AOI1_OUT0 input is selected
 *  0b100101..AOI1_OUT1 input is selected
 *  0b100110..AOI1_OUT2 input is selected
 *  0b100111..AOI1_OUT3 input is selected
 *  0b101000..CTimer3_MAT2 input is selected
 *  0b101001..CTimer3_MAT3 input is selected
 *  0b101010..CTimer4_MAT2 input is selected
 *  0b101011..CTimer4_MAT3 input is selected
 *  0b101100..FlexIO CH0 input is selected
 *  0b101101..FlexIO CH1 input is selected
 *  0b101110..FlexIO CH2 input is selected
 *  0b101111..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPUART0_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART0_INP_SHIFT)) & INPUTMUX_LPUART0_INP_MASK)
/*! @} */

/*! @name LPUART1 - LPUART1 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART1_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART1_INP_SHIFT               (0U)
/*! INP - LPUART1 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
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
 *  0b100001..GPIO4 Pin Event Trig 0 input is selected
 *  0b100010..WUU selected
 *  0b100011..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100100..AOI1_OUT0 input is selected
 *  0b100101..AOI1_OUT1 input is selected
 *  0b100110..AOI1_OUT2 input is selected
 *  0b100111..AOI1_OUT3 input is selected
 *  0b101000..CTimer3_MAT2 input is selected
 *  0b101001..CTimer3_MAT3 input is selected
 *  0b101010..CTimer4_MAT2 input is selected
 *  0b101011..CTimer4_MAT3 input is selected
 *  0b101100..FlexIO CH0 input is selected
 *  0b101101..FlexIO CH1 input is selected
 *  0b101110..FlexIO CH2 input is selected
 *  0b101111..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPUART1_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART1_INP_SHIFT)) & INPUTMUX_LPUART1_INP_MASK)
/*! @} */

/*! @name LPUART2 - LPUART2 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART2_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART2_INP_SHIFT               (0U)
/*! INP - LPUART2 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
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
 *  0b100001..GPIO4 Pin Event Trig 0 input is selected
 *  0b100010..WUU selected
 *  0b100011..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100100..AOI1_OUT0 input is selected
 *  0b100101..AOI1_OUT1 input is selected
 *  0b100110..AOI1_OUT2 input is selected
 *  0b100111..AOI1_OUT3 input is selected
 *  0b101000..CTimer3_MAT2 input is selected
 *  0b101001..CTimer3_MAT3 input is selected
 *  0b101010..CTimer4_MAT2 input is selected
 *  0b101011..CTimer4_MAT3 input is selected
 *  0b101100..FlexIO CH0 input is selected
 *  0b101101..FlexIO CH1 input is selected
 *  0b101110..FlexIO CH2 input is selected
 *  0b101111..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPUART2_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART2_INP_SHIFT)) & INPUTMUX_LPUART2_INP_MASK)
/*! @} */

/*! @name LPUART3 - LPUART3 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART3_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART3_INP_SHIFT               (0U)
/*! INP - LPUART3 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
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
 *  0b100001..GPIO4 Pin Event Trig 0 input is selected
 *  0b100010..WUU selected
 *  0b100011..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100100..AOI1_OUT0 input is selected
 *  0b100101..AOI1_OUT1 input is selected
 *  0b100110..AOI1_OUT2 input is selected
 *  0b100111..AOI1_OUT3 input is selected
 *  0b101000..CTimer3_MAT2 input is selected
 *  0b101001..CTimer3_MAT3 input is selected
 *  0b101010..CTimer4_MAT2 input is selected
 *  0b101011..CTimer4_MAT3 input is selected
 *  0b101100..FlexIO CH0 input is selected
 *  0b101101..FlexIO CH1 input is selected
 *  0b101110..FlexIO CH2 input is selected
 *  0b101111..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPUART3_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART3_INP_SHIFT)) & INPUTMUX_LPUART3_INP_MASK)
/*! @} */

/*! @name LPUART4 - LPUART4 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART4_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART4_INP_SHIFT               (0U)
/*! INP - LPUART4 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
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
 *  0b100001..GPIO4 Pin Event Trig 0 input is selected
 *  0b100010..WUU selected
 *  0b100011..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100100..AOI1_OUT0 input is selected
 *  0b100101..AOI1_OUT1 input is selected
 *  0b100110..AOI1_OUT2 input is selected
 *  0b100111..AOI1_OUT3 input is selected
 *  0b101000..CTimer3_MAT2 input is selected
 *  0b101001..CTimer3_MAT3 input is selected
 *  0b101010..CTimer4_MAT2 input is selected
 *  0b101011..CTimer4_MAT3 input is selected
 *  0b101100..FlexIO CH0 input is selected
 *  0b101101..FlexIO CH1 input is selected
 *  0b101110..FlexIO CH2 input is selected
 *  0b101111..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPUART4_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART4_INP_SHIFT)) & INPUTMUX_LPUART4_INP_MASK)
/*! @} */

/*! @name LPUART5 - LPUART5 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART5_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART5_INP_SHIFT               (0U)
/*! INP - LPUART5 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..CMP1_OUT input is selected
 *  0b001000..CMP2_OUT input is selected
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
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
 *  0b100001..GPIO4 Pin Event Trig 0 input is selected
 *  0b100010..WUU selected
 *  0b100011..USB0 ipp_ind_uart_rxd_usbmux input is selected
 *  0b100100..AOI1_OUT0 input is selected
 *  0b100101..AOI1_OUT1 input is selected
 *  0b100110..AOI1_OUT2 input is selected
 *  0b100111..AOI1_OUT3 input is selected
 *  0b101000..CTimer3_MAT2 input is selected
 *  0b101001..CTimer3_MAT3 input is selected
 *  0b101010..CTimer4_MAT2 input is selected
 *  0b101011..CTimer4_MAT3 input is selected
 *  0b101100..FlexIO CH0 input is selected
 *  0b101101..FlexIO CH1 input is selected
 *  0b101110..FlexIO CH2 input is selected
 *  0b101111..FlexIO CH3 input is selected
 */
#define INPUTMUX_LPUART5_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART5_INP_SHIFT)) & INPUTMUX_LPUART5_INP_MASK)
/*! @} */

/*! @name FLEXIO_TRIGN_FLEXIO_TRIG - FlexIO Trigger Input Connections */
/*! @{ */

#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_MASK (0x7FU)
#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_SHIFT (0U)
/*! INP - Input number for FlexIO0.
 *  0b0000000..Reserved
 *  0b0000001..AOI0_OUT0 input is selected
 *  0b0000010..AOI0_OUT1 input is selected
 *  0b0000011..AOI0_OUT2 input is selected
 *  0b0000100..AOI0_OUT3 input is selected
 *  0b0000101..ADC0_tcomp[0] input is selected
 *  0b0000110..ADC0_tcomp[1] input is selected
 *  0b0000111..ADC0_tcomp[2] input is selected
 *  0b0001000..ADC0_tcomp[3] input is selected
 *  0b0001001..CMP0_OUT input is selected
 *  0b0001010..CMP1_OUT input is selected
 *  0b0001011..CMP2_OUT input is selected
 *  0b0001100..CTimer0_MAT1 input is selected
 *  0b0001101..CTimer0_MAT2 input is selected
 *  0b0001110..CTimer1_MAT1 input is selected
 *  0b0001111..CTimer1_MAT2 input is selected
 *  0b0010000..CTimer2_MAT1 input is selected
 *  0b0010001..CTimer2_MAT2 input is selected
 *  0b0010010..LPTMR0 input is selected
 *  0b0010011..Reserved
 *  0b0010100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0010101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0010110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0010111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0011000..TRIG_IN0 input is selected
 *  0b0011001..TRIG_IN1 input is selected
 *  0b0011010..TRIG_IN2 input is selected
 *  0b0011011..TRIG_IN3 input is selected
 *  0b0011100..TRIG_IN4 input is selected
 *  0b0011101..TRIG_IN5 input is selected
 *  0b0011110..TRIG_IN6 input is selected
 *  0b0011111..TRIG_IN7 input is selected
 *  0b0100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b0100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b0100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b0100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b0100100..GPIO4 Pin Event Trig 0 input is selected
 *  0b0100101..WUU input is selected
 *  0b0100110..LPI2C0 Master End of Packet
 *  0b0100111..LPI2C0 Slave End of Packet
 *  0b0101000..LPI2C1 Master End of Packet
 *  0b0101001..LPI2C1 Slave End of Packet
 *  0b0101010..LPSPI0 End of Frame
 *  0b0101011..LPSPI0 Received Data Word
 *  0b0101100..LPSPI1 End of Frame
 *  0b0101101..LPSPI1 Received Data Word
 *  0b0101110..LPUART0 Received Data Word
 *  0b0101111..LPUART0 Transmitted Data Word
 *  0b0110000..LPUART0 Receive Line Idle
 *  0b0110001..LPUART1 Received Data Word
 *  0b0110010..LPUART1 Transmitted Data Word
 *  0b0110011..LPUART1 Receive Line Idle
 *  0b0110100..LPUART2 Received Data Word
 *  0b0110101..LPUART2 Transmitted Data Word
 *  0b0110110..LPUART2 Receive Line Idle
 *  0b0110111..LPUART3 Received Data Word
 *  0b0111000..LPUART3 Transmitted Data Word
 *  0b0111001..LPUART3 Receive Line Idle
 *  0b0111010..LPUART4 Received Data Word
 *  0b0111011..LPUART4 Transmitted Data Word
 *  0b0111100..LPUART4 Receive Line Idle
 *  0b0111101..AOI1_OUT0 input is selected
 *  0b0111110..AOI1_OUT1 input is selected
 *  0b0111111..AOI1_OUT2 input is selected
 *  0b1000000..AOI1_OUT3 input is selected
 *  0b1000001..ADC1_tcomp[0] input is selected
 *  0b1000010..ADC1_tcomp[1] input is selected
 *  0b1000011..ADC1_tcomp[2] input is selected
 *  0b1000100..ADC1_tcomp[3] input is selected
 *  0b1000101..CTimer3_MAT2 input is selected
 *  0b1000110..CTimer3_MAT3 input is selected
 *  0b1000111..CTimer4_MAT2 input is selected
 *  0b1001000..CTimer4_MAT3 input is selected
 *  0b1001001..PWM1_SM0_MUX_TRIG0 input is selected
 *  0b1001010..PWM1_SM1_MUX_TRIG0 input is selected
 *  0b1001011..PWM1_SM2_MUX_TRIG0 input is selected
 *  0b1001100..PWM1_SM3_MUX_TRIG0 input is selected
 *  0b1001101..LPI2C2 Master End of Packet
 *  0b1001110..LPI2C2 Slave End of Packet
 *  0b1001111..LPI2C3 Master End of Packet
 *  0b1010000..LPI2C3 Slave End of Packet
 */
#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP(x) (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_SHIFT)) & INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG */
#define INPUTMUX_FLEXIO_TRIGN_FLEXIO_TRIG_COUNT  (4U)

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


#endif  /* INPUTMUX_H_ */

