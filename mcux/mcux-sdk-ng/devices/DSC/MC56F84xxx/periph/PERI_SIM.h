/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SIM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(PERI_SIM_H_)
#define PERI_SIM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(GPIO_PERIPHERAL_MUX_T_)
#define GPIO_PERIPHERAL_MUX_T_
/*!
 * @addtogroup Pin_Mux
 * @{
 */

/*!
 * @brief Structure for the pin mux table
 *
 * The pin mux table is soc specificed.
 * Enumeration member bitfield:
 *   BIT0~BIT1: peripheral function selector.
 *   BIT4~BIT7: pin index.
 *   BIT8~BIT11: port index.
 *   Other BITs: 0, reserved.
 */
typedef enum _gpio_peripheral_mux
{
    kGPIO_Peri_A0_ANA0_and_CMPA_IN3 = 0x0000,      /**< GPIO_A0, Pin */
    kGPIO_Peri_A0_CMPC_O            = 0x0001,      /**< GPIO_A0, Pin */
    kGPIO_Peri_C0_EXTAL             = 0x0200,      /**< GPIO_C0, Pin */
    kGPIO_Peri_C0_CLKIN0            = 0x0201,      /**< GPIO_C0, Pin */
    kGPIO_Peri_C2_TXD0              = 0x0220,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C2_TB0               = 0x0221,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C2_XB_IN2            = 0x0222,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C2_CLKO0             = 0x0223,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C3_TA0               = 0x0230,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C3_CMPA_O            = 0x0231,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C3_RXD0              = 0x0232,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C3_CLKIN1            = 0x0233,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C4_TA1               = 0x0240,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C4_CMPB_O            = 0x0241,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C4_XB_IN8            = 0x0242,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C4_EWM_OUT_B         = 0x0243,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C5_XB_IN7            = 0x0251,      /**< GPIO_C5, Pin */
    kGPIO_Peri_C6_TA2               = 0x0260,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C6_XB_IN3            = 0x0261,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C6_CMP_REF           = 0x0262,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C7_SS0_B             = 0x0270,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C7_TXD0              = 0x0271,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C8_MISO0             = 0x0280,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C8_RXD0              = 0x0281,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C8_XB_IN9            = 0x0282,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C9_SCLK0             = 0x0290,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C9_XB_IN4            = 0x0291,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C10_MOSI0            = 0x02A0,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C10_XB_IN5           = 0x02A1,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C10_MISO0            = 0x02A2,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C11_SCL1             = 0x02B1,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C11_TXD1             = 0x02B2,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C12_SDA1             = 0x02C1,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C12_RXD1             = 0x02C2,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C13_TA3              = 0x02D0,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C13_XB_IN6           = 0x02D1,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C13_EWM_OUT_B        = 0x02D2,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C14_SDA0             = 0x02E0,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C14_XB_OUT4          = 0x02E1,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C15_SCL0             = 0x02F0,      /**< GPIO_C15, Pin */
    kGPIO_Peri_C15_XB_OUT5          = 0x02F1,      /**< GPIO_C15, Pin */
    kGPIO_Peri_E4_PWMA_2B           = 0x0440,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E4_XB_IN2            = 0x0441,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E5_PWMA_2A           = 0x0450,      /**< GPIO_E5, Pin */
    kGPIO_Peri_E5_XB_IN3            = 0x0451,      /**< GPIO_E5, Pin */
    kGPIO_Peri_F0_XB_IN6            = 0x0500,      /**< GPIO_F0, Pin */
    kGPIO_Peri_F0_TB2               = 0x0501,      /**< GPIO_F0, Pin */
    kGPIO_Peri_F1_CLKO1             = 0x0510,      /**< GPIO_F1, Pin */
    kGPIO_Peri_F1_XB_IN7            = 0x0511,      /**< GPIO_F1, Pin */
    kGPIO_Peri_E6_PWMA_3B           = 0x0460,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E6_XB_IN4            = 0x0461,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E7_PWMA_3A           = 0x0470,      /**< GPIO_E7, Pin */
    kGPIO_Peri_E7_XB_IN5            = 0x0471,      /**< GPIO_E7, Pin */
    kGPIO_Peri_F1_CMPD_O            = 0x0512,      /**< GPIO_F1, Pin */
    kGPIO_Peri_F2_SCL1              = 0x0520,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F2_XB_OUT6           = 0x0521,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F3_SDA1              = 0x0530,      /**< GPIO_F3, Pin */
    kGPIO_Peri_F3_XB_OUT7           = 0x0531,      /**< GPIO_F3, Pin */
    kGPIO_Peri_F4_TXD1              = 0x0540,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F4_XB_OUT8           = 0x0541,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F5_RXD1              = 0x0550,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F5_XB_OUT9           = 0x0551,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F6_TB2               = 0x0560,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F6_PWMA_3X           = 0x0561,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F6_XB_IN2            = 0x0563,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F7_TB3               = 0x0570,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F7_CMPC_O            = 0x0571,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F7_XB_IN3            = 0x0573,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F8_RXD0              = 0x0580,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_TB1               = 0x0581,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_CMPD_O            = 0x0582,      /**< GPIO_F8, Pin */
    kGPIO_Peri_C11_CANTX            = 0x02B0,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C12_CANRX            = 0x02C0,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C5_DACO              = 0x0250,      /**< GPIO_C5, Pin */
    kGPIO_Peri_D5_RXD2              = 0x0350,      /**< GPIO_D5, Pin */
    kGPIO_Peri_D5_XB_IN5            = 0x0351,      /**< GPIO_D5, Pin */
    kGPIO_Peri_D5_XB_OUT9           = 0x0352,      /**< GPIO_D5, Pin */
    kGPIO_Peri_D6_TXD2              = 0x0360,      /**< GPIO_D6, Pin */
    kGPIO_Peri_D6_XB_IN4            = 0x0361,      /**< GPIO_D6, Pin */
    kGPIO_Peri_D6_XB_OUT8           = 0x0362,      /**< GPIO_D6, Pin */
    kGPIO_Peri_D7_XB_OUT11          = 0x0370,      /**< GPIO_D7, Pin */
    kGPIO_Peri_D7_XB_IN7            = 0x0371,      /**< GPIO_D7, Pin */
    kGPIO_Peri_D7_MISO1             = 0x0372,      /**< GPIO_D7, Pin */
    kGPIO_Peri_E6_PWMB_2B           = 0x0462,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E7_PWMB_2A           = 0x0472,      /**< GPIO_E7, Pin */
    kGPIO_Peri_F0_SCLK1             = 0x0502,      /**< GPIO_F0, Pin */
    kGPIO_Peri_F6_PWMB_3X           = 0x0562,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F7_SS1_B             = 0x0572,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F9_RXD2              = 0x0590,      /**< GPIO_F9, Pin */
    kGPIO_Peri_F9_PWMA_FAULT7       = 0x0591,      /**< GPIO_F9, Pin */
    kGPIO_Peri_F9_PWMB_FAULT7       = 0x0592,      /**< GPIO_F9, Pin */
    kGPIO_Peri_F9_XB_OUT11          = 0x0593,      /**< GPIO_F9, Pin */
    kGPIO_Peri_F10_TXD2             = 0x05A0,      /**< GPIO_F10, Pin */
    kGPIO_Peri_F10_PWMA_FAULT6      = 0x05A1,      /**< GPIO_F10, Pin */
    kGPIO_Peri_F10_PWMB_FAULT6      = 0x05A2,      /**< GPIO_F10, Pin */
    kGPIO_Peri_F10_XB_OUT10         = 0x05A3,      /**< GPIO_F10, Pin */
    kGPIO_Peri_G0_PWMB_1B           = 0x0600,      /**< GPIO_G0, Pin */
    kGPIO_Peri_G0_XB_OUT6           = 0x0601,      /**< GPIO_G0, Pin */
    kGPIO_Peri_G1_PWMB_1A           = 0x0610,      /**< GPIO_G1, Pin */
    kGPIO_Peri_G1_XB_OUT7           = 0x0611,      /**< GPIO_G1, Pin */
    kGPIO_Peri_G2_PWMB_0B           = 0x0620,      /**< GPIO_G2, Pin */
    kGPIO_Peri_G2_XB_OUT4           = 0x0621,      /**< GPIO_G2, Pin */
    kGPIO_Peri_G3_PWMB_0A           = 0x0630,      /**< GPIO_G3, Pin */
    kGPIO_Peri_G3_XB_OUT5           = 0x0631,      /**< GPIO_G3, Pin */
    kGPIO_Peri_G6_PWMA_FAULT4       = 0x0660,      /**< GPIO_G6, Pin */
    kGPIO_Peri_G6_PWMB_FAULT4       = 0x0661,      /**< GPIO_G6, Pin */
    kGPIO_Peri_G6_TB2               = 0x0662,      /**< GPIO_G6, Pin */
    kGPIO_Peri_G6_XB_OUT8           = 0x0663,      /**< GPIO_G6, Pin */
    kGPIO_Peri_G7_PWMA_FAULT5       = 0x0670,      /**< GPIO_G7, Pin */
    kGPIO_Peri_G7_PWMB_FAULT5       = 0x0671,      /**< GPIO_G7, Pin */
    kGPIO_Peri_G7_XB_OUT9           = 0x0672,      /**< GPIO_G7, Pin */
    kGPIO_Peri_G11_TB3              = 0x06B0,      /**< GPIO_G11, Pin */
    kGPIO_Peri_G11_CLKO0            = 0x06B1,      /**< GPIO_G11, Pin */
    kGPIO_Peri_G11_MOSI1            = 0x06B2,      /**< GPIO_G11, Pin */
    kGPIO_Peri_B9_ANC21             = 0x0190,      /**< GPIO_B9, Pin */
    kGPIO_Peri_B9_XB_IN9            = 0x0191,      /**< GPIO_B9, Pin */
    kGPIO_Peri_B9_MISO2             = 0x0192,      /**< GPIO_B9, Pin */
    kGPIO_Peri_B10_ANC22            = 0x01A0,      /**< GPIO_B10, Pin */
    kGPIO_Peri_B10_XB_IN8           = 0x01A1,      /**< GPIO_B10, Pin */
    kGPIO_Peri_B10_MOSI2            = 0x01A2,      /**< GPIO_B10, Pin */
    kGPIO_Peri_B11_ANC23            = 0x01B0,      /**< GPIO_B11, Pin */
    kGPIO_Peri_B11_XB_IN7           = 0x01B1,      /**< GPIO_B11, Pin */
    kGPIO_Peri_B11_SCLK2            = 0x01B2,      /**< GPIO_B11, Pin */
    kGPIO_Peri_E8_PWMB_2B           = 0x0480,      /**< GPIO_E8, Pin */
    kGPIO_Peri_E8_PWMA_FAULT0       = 0x0481,      /**< GPIO_E8, Pin */
    kGPIO_Peri_E9_PWMB_2A           = 0x0490,      /**< GPIO_E9, Pin */
    kGPIO_Peri_E9_PWMA_FAULT1       = 0x0491,      /**< GPIO_E9, Pin */
    kGPIO_Peri_F11_TXD0             = 0x05B0,      /**< GPIO_F11, Pin */
    kGPIO_Peri_F11_XB_IN11          = 0x05B1,      /**< GPIO_F11, Pin */
    kGPIO_Peri_F12_MISO1            = 0x05C0,      /**< GPIO_F12, Pin */
    kGPIO_Peri_F12_PWMB_FAULT2      = 0x05C1,      /**< GPIO_F12, Pin */
    kGPIO_Peri_F13_MOSI1            = 0x05D0,      /**< GPIO_F13, Pin */
    kGPIO_Peri_F13_PWMB_FAULT1      = 0x05D1,      /**< GPIO_F13, Pin */
    kGPIO_Peri_F14_SCLK1            = 0x05E0,      /**< GPIO_F14, Pin */
    kGPIO_Peri_F14_PWMB_FAULT0      = 0x05E1,      /**< GPIO_F14, Pin */
    kGPIO_Peri_F15_RXD0             = 0x05F0,      /**< GPIO_F15, Pin */
    kGPIO_Peri_F15_XB_IN10          = 0x05F1,      /**< GPIO_F15, Pin */
    kGPIO_Peri_G4_PWMB_3B           = 0x0640,      /**< GPIO_G4, Pin */
    kGPIO_Peri_G4_PWMA_FAULT2       = 0x0641,      /**< GPIO_G4, Pin */
    kGPIO_Peri_G5_PWMB_3A           = 0x0650,      /**< GPIO_G5, Pin */
    kGPIO_Peri_G5_PWMA_FAULT3       = 0x0651,      /**< GPIO_G5, Pin */
    kGPIO_Peri_G8_PWMB_0X           = 0x0680,      /**< GPIO_G8, Pin */
    kGPIO_Peri_G8_PWMA_0X           = 0x0681,      /**< GPIO_G8, Pin */
    kGPIO_Peri_G8_TA2               = 0x0682,      /**< GPIO_G8, Pin */
    kGPIO_Peri_G8_XB_OUT10          = 0x0683,      /**< GPIO_G8, Pin */
    kGPIO_Peri_G9_PWMB_1X           = 0x0690,      /**< GPIO_G9, Pin */
    kGPIO_Peri_G9_PWMA_1X           = 0x0691,      /**< GPIO_G9, Pin */
    kGPIO_Peri_G9_TA3               = 0x0692,      /**< GPIO_G9, Pin */
    kGPIO_Peri_G9_XB_OUT11          = 0x0693,      /**< GPIO_G9, Pin */
    kGPIO_Peri_G10_PWMB_2X          = 0x06A0,      /**< GPIO_G10, Pin */
    kGPIO_Peri_G10_PWMA_2X          = 0x06A1,      /**< GPIO_G10, Pin */
    kGPIO_Peri_G10_XB_IN8           = 0x06A2,      /**< GPIO_G10, Pin */
    kGPIO_Peri_G10_SS2_B            = 0x06A3,      /**< GPIO_G10, Pin */
} gpio_peripheral_mux_t;

/* @} */
#endif /* GPIO_PERIPHERAL_MUX_T_ */

#if !defined(SIM_SWRESET_PERI_INDEX_T_)
#define SIM_SWRESET_PERI_INDEX_T_
typedef enum _sim_swReset_peri_index
{
    kSIM_SWResetGPIO                = 6U,          /**< GPIO Software Reset. */
    kSIM_SWResetTMRB                = 11U,         /**< TMRB Software Reset. */
    kSIM_SWResetTMRA                = 15U,         /**< TMRA Software Reset. */
    kSIM_SWResetFLEXCAN             = 16U,         /**< FlexCAN Software Reset. */
    kSIM_SWResetIIC1                = 21U,         /**< IIC1 Software Reset. */
    kSIM_SWResetIIC0                = 22U,         /**< IIC0 Software Reset. */
    kSIM_SWResetQSPI1               = 24U,         /**< QSPI1 Software Reset. */
    kSIM_SWResetQSPI0               = 25U,         /**< QSPI0 Software Reset. */
    kSIM_SWResetSCI1                = 27U,         /**< SCI1 Software Reset. */
    kSIM_SWResetSCI0                = 28U,         /**< SCI0 Software Reset. */
    kSIM_SWResetDAC                 = 29U,         /**< DAC Software Reset. */
    kSIM_SWResetPDB1                = 32U,         /**< Programmable Delay Block Software Reset. */
    kSIM_SWResetPDB0                = 33U,         /**< Programmable Delay Block Software Reset. */
    kSIM_SWResetPIT1                = 34U,         /**< PIT1 Software Reset. */
    kSIM_SWResetPIT0                = 35U,         /**< PIT0 Software Reset. */
    kSIM_SWResetQDC                 = 36U,         /**< Quadrature Decoder Software Reset. */
    kSIM_SWResetCRC                 = 37U,         /**< CRC Software Reset. */
    kSIM_SWResetCADC                = 39U,         /**< Cyclic ADC Software Reset. */
    kSIM_SWResetSARADC              = 40U,         /**< SAR ADC Software Reset. */
    kSIM_SWResetCMP                 = 44U,         /**< CMP Software Reset. */
    kSIM_SWResetEWM                 = 47U,         /**< EWM Software Reset. */
    kSIM_SWResetPWMA                = 55U,         /**< PWMA Software Reset. */
    kSIM_SWResetQSPI2               = 23U,         /**< QSPI2 Software Reset. */
    kSIM_SWResetSCI2                = 26U,         /**< SCI2 Software Reset. */
    kSIM_SWResetPWMB                = 51U,         /**< PWMB Software Reset. */
} sim_swReset_peri_index_t;
#endif /* SIM_SWRESET_PERI_INDEX_T_ */

#if !defined(SIM_INTERNAL_PERI_INDEX_T_)
#define SIM_INTERNAL_PERI_INDEX_T_
typedef enum _sim_internal_peri_index
{
    kSIM_PWMAFault0InputIndex       = 0U,          /**< Select PWMA Fault 0 Input. */
    kSIM_PWMAFault1InputIndex       = 1U,          /**< Select PWMA Fault 1 Input. */
    kSIM_PWMAFault2InputIndex       = 2U,          /**< Select PWMA Fault 2 Input. */
    kSIM_PWMAFault3InputIndex       = 3U,          /**< Select PWMA Fault 3 Input. */
    kSIM_TMRA0InputIndex            = 8U,          /**< Select TMRA0 Input. */
    kSIM_TMRA1InputIndex            = 9U,          /**< Select TMRA1 Input. */
    kSIM_TMRA2InputIndex            = 10U,         /**< Select TMRA2 Input. */
    kSIM_TMRA3InputIndex            = 11U,         /**< Select TMRA3 Input. */
    kSIM_TMRB0InputIndex            = 12U,         /**< Select TMRB0 Input. */
    kSIM_TMRB1InputIndex            = 13U,         /**< Select TMRB1 Input. */
    kSIM_TMRB2InputIndex            = 14U,         /**< Select TMRB2 Input. */
    kSIM_TMRB3InputIndex            = 15U,         /**< Select TMRB3 Input. */
    kSIM_PWMBFault0InputIndex       = 4U,          /**< Select PWMB Fault 0 Input. */
    kSIM_PWMBFault1InputIndex       = 5U,          /**< Select PWMB Fault 1 Input. */
    kSIM_PWMBFault2InputIndex       = 6U,          /**< Select PWMB Fault 2 Input. */
} sim_internal_peri_index_t;
#endif /* SIM_INTERNAL_PERI_INDEX_T_ */

#if !defined(SIM_INTERNAL_PERI_INPUT_T_)
#define SIM_INTERNAL_PERI_INPUT_T_
typedef enum _sim_internal_peri_input
{
    kSIM_PWMAFault0Input_GPIOE8     = 0U,          /**< Select PWMA Fault 0 Input, GPIOE8. */
    kSIM_PWMAFault0Input_XB_OUT29   = 1U,          /**< Select PWMA Fault 0 Input, XB_OUT29. */
    kSIM_PWMAFault1Input_GPIOE9     = 0U,          /**< Select PWMA Fault 1 Input, GPIOE9. */
    kSIM_PWMAFault1Input_XB_OUT30   = 1U,          /**< Select PWMA Fault 1 Input, XB_OUT30. */
    kSIM_PWMAFault2Input_GPIOG4     = 0U,          /**< Select PWMA Fault 2 Input, GPIOG4. */
    kSIM_PWMAFault2Input_XB_OUT31   = 1U,          /**< Select PWMA Fault 2 Input, XB_OUT31. */
    kSIM_PWMAFault3Input_GPIOG5     = 0U,          /**< Select PWMA Fault 3 Input, GPIOG5. */
    kSIM_PWMAFault3Input_XB_OUT32   = 1U,          /**< Select PWMA Fault 3 Input, XB_OUT32. */
    kSIM_TMRA0Input_GPIOC3          = 0U,          /**< Select TMRA0 Input, GPIOC3. */
    kSIM_TMRA0Input_XB_OUT49        = 1U,          /**< Select TMRA0 Input, XB_OUT49. */
    kSIM_TMRA1Input_GPIOC4          = 0U,          /**< Select TMRA1 Input, GPIOC4. */
    kSIM_TMRA1Input_XB_OUT50        = 1U,          /**< Select TMRA1 Input, XB_OUT50. */
    kSIM_TMRA2Input_GPIOC6_GPIOG8   = 0U,          /**< Select TMRA2 Input, GPIOC6 or GPIOG8. */
    kSIM_TMRA2Input_XB_OUT51        = 1U,          /**< Select TMRA2 Input, XB_OUT51. */
    kSIM_TMRA3Input_GPIOC13_GPIOG9  = 0U,          /**< Select TMRA3 Input, GPIOC13 or GPIOG9. */
    kSIM_TMRA3Input_XB_OUT52        = 1U,          /**< Select TMRA3 Input, XB_OUT52. */
    kSIM_TMRB0Input_GPIOC2          = 0U,          /**< Select TMRB0 Input, GPIOC2. */
    kSIM_TMRB0Input_XB_OUT34        = 1U,          /**< Select TMRB0 Input, XB_OUT34. */
    kSIM_TMRB1Input_GPIOF8          = 0U,          /**< Select TMRB1 Input, GPIOF8. */
    kSIM_TMRB1Input_XB_OUT35        = 1U,          /**< Select TMRB1 Input, XB_OUT35. */
    kSIM_TMRB2Input_GPIOF6_GPIOF0_GPIOG6 = 0U,     /**< Select TMRB2 Input, GPIOF6, GPIOF0, or GPIOG6. */
    kSIM_TMRB2Input_XB_OUT36        = 1U,          /**< Select TMRB2 Input, XB_OUT36. */
    kSIM_TMRB3Input_GPIOF7_GPIOG11  = 0U,          /**< Select TMRB3 Input, GPIOF7 or GPIOG11. */
    kSIM_TMRB3Input_XB_OUT37        = 1U,          /**< Select TMRB3 Input, XB_OUT37. */
    kSIM_PWMBFault0Input_GPIOF14    = 0U,          /**< Select PWMB Fault 0 Input, GPIOF14. */
    kSIM_PWMBFault0Input_XB_OUT29   = 1U,          /**< Select PWMB Fault 0 Input, XB_OUT29. */
    kSIM_PWMBFault1Input_GPIOF13    = 0U,          /**< Select PWMB Fault 1 Input, GPIOF13. */
    kSIM_PWMBFault1Input_XB_OUT30   = 1U,          /**< Select PWMB Fault 1 Input, XB_OUT30. */
    kSIM_PWMBFault2Input_GPIOF12    = 0U,          /**< Select PWMB Fault 2 Input, GPIOF12. */
    kSIM_PWMBFault2Input_XB_OUT31   = 1U,          /**< Select PWMB Fault 2 Input, XB_OUT31. */
} sim_internal_peri_input_t;
#endif /* SIM_INTERNAL_PERI_INPUT_T_ */

#if !defined(SIM_SOFTWARE_CONTRL_REGISTER_INDEX_T_)
#define SIM_SOFTWARE_CONTRL_REGISTER_INDEX_T_
typedef enum _sim_software_contrl_register_index
{
    kSIM_SCR0                       = 0U,          /**< SCR0. */
    kSIM_SCR1                       = 1U,          /**< SCR1. */
    kSIM_SCR2                       = 2U,          /**< SCR2. */
    kSIM_SCR3                       = 3U,          /**< SCR3. */
} sim_software_contrl_register_index_t;
#endif /* SIM_SOFTWARE_CONTRL_REGISTER_INDEX_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< Control Register, offset: 0x0 */
  __I  uint16_t RSTAT;                             /**< Reset Status Register, offset: 0x1 */
  __IO uint16_t SCR0;                              /**< Software Control Register, offset: 0x2 */
  __IO uint16_t SCR1;                              /**< Software Control Register, offset: 0x3 */
  __IO uint16_t SCR2;                              /**< Software Control Register, offset: 0x4 */
  __IO uint16_t SCR3;                              /**< Software Control Register, offset: 0x5 */
       uint16_t MSHID;                             /**< Most Significant Half of JTAG ID, offset: 0x6 */
       uint16_t LSHID;                             /**< Least Significant Half of JTAG ID, offset: 0x7 */
  __IO uint16_t PWR;                               /**< Power Control Register, offset: 0x8 */
       uint16_t RESERVED_0[1];
  __IO uint16_t CLKOUT;                            /**< Clock Output Select Register, offset: 0xA */
  __IO uint16_t PCR;                               /**< Peripheral Clock Rate Register, offset: 0xB */
  __IO uint16_t PCE0;                              /**< Peripheral Clock Enable Register 0, offset: 0xC */
  __IO uint16_t PCE1;                              /**< Peripheral Clock Enable Register 1, offset: 0xD */
  __IO uint16_t PCE2;                              /**< Peripheral Clock Enable Register 2, offset: 0xE */
  __IO uint16_t PCE3;                              /**< Peripheral Clock Enable Register 3, offset: 0xF */
  __IO uint16_t SD0;                               /**< STOP Disable Register 0, offset: 0x10 */
  __IO uint16_t SD1;                               /**< Peripheral Clock STOP Disable Register 1, offset: 0x11 */
  __IO uint16_t SD2;                               /**< Peripheral Clock STOP Disable Register 2, offset: 0x12 */
  __IO uint16_t SD3;                               /**< Peripheral Clock STOP Disable Register 3, offset: 0x13 */
  __IO uint16_t IOSAHI;                            /**< I/O Short Address Location Register, offset: 0x14 */
  __IO uint16_t IOSALO;                            /**< I/O Short Address Location Register, offset: 0x15 */
  __IO uint16_t PROT;                              /**< Protection Register, offset: 0x16 */
  __IO uint16_t GPSAL;                             /**< GPIOA LSBs Peripheral Select Register, offset: 0x17 */
  __IO uint16_t GPSBH;                             /**< GPIOB MSBs Peripheral Select Register, offset: 0x18 */
  __IO uint16_t GPSCL;                             /**< GPIOC LSBs Peripheral Select Register, offset: 0x19 */
  __IO uint16_t GPSCH;                             /**< GPIOC MSBs Peripheral Select Register, offset: 0x1A */
  __IO uint16_t GPSDL;                             /**< GPIOD LSBs Peripheral Select Register, offset: 0x1B */
  __IO uint16_t GPSEL;                             /**< GPIOE LSBs Peripheral Select Register, offset: 0x1C */
  __IO uint16_t GPSEH;                             /**< GPIOE MSBs Peripheral Select Register, offset: 0x1D */
  __IO uint16_t GPSFL;                             /**< GPIOF LSBs Peripheral Select Register, offset: 0x1E */
  __IO uint16_t GPSFH;                             /**< GPIOF MSBs Peripheral Select Register, offset: 0x1F */
  __IO uint16_t GPSGL;                             /**< GPIOG LSBs Peripheral Select Register, offset: 0x20 */
  __IO uint16_t GPSGH;                             /**< GPIOG MSBs Peripheral Select Register, offset: 0x21 */
  __IO uint16_t IPS0;                              /**< Internal Peripheral Select Register 0, offset: 0x22 */
  __IO uint16_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x23 */
  __IO uint16_t PSWR0;                             /**< Peripheral Software Reset Register 0, offset: 0x24 */
  __IO uint16_t PSWR1;                             /**< Peripheral Software Reset Register 1, offset: 0x25 */
  __IO uint16_t PSWR2;                             /**< Peripheral Software Reset Register 2, offset: 0x26 */
  __IO uint16_t PSWR3;                             /**< Peripheral Software Reset Register 3, offset: 0x27 */
  __IO uint16_t PWRMODE;                           /**< Power Mode Register, offset: 0x28 */
       uint16_t RESERVED_1[3];
  __I  uint16_t NVMOPT2H;                          /**< Non-Volatile Memory Option Register 2 (High), offset: 0x2C */
  __I  uint16_t NVMOPT2L;                          /**< Non-Volatile Memory Option Register 2 (Low), offset: 0x2D */
  __I  uint16_t NVMOPT3H;                          /**< Non-Volatile Memory Option Register 3 (High), offset: 0x2E */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define SIM_CTRL_WAIT_DISABLE_MASK               (0x3U)
#define SIM_CTRL_WAIT_DISABLE_SHIFT              (0U)
/*! WAIT_DISABLE - WAIT Disable
 *  0b00..Wait mode is entered when the DSC core executes a WAIT instruction.
 *  0b01..The DSC core WAIT instruction does not cause entry into wait mode.
 *  0b10..Wait mode is entered when the DSC core executes a WAIT instruction, and the WAIT_disable field is write protected until the next reset.
 *  0b11..The DSC core WAIT instruction does not cause entry into wait mode, and the WAIT_disable field is write protected until the next reset.
 */
#define SIM_CTRL_WAIT_DISABLE(x)                 (((uint16_t)(((uint16_t)(x)) << SIM_CTRL_WAIT_DISABLE_SHIFT)) & SIM_CTRL_WAIT_DISABLE_MASK)

#define SIM_CTRL_STOP_DISABLE_MASK               (0xCU)
#define SIM_CTRL_STOP_DISABLE_SHIFT              (2U)
/*! STOP_DISABLE - STOP Disable
 *  0b00..Stop mode is entered when the DSC core executes a STOP instruction.
 *  0b01..The DSC core STOP instruction does not cause entry into stop mode.
 *  0b10..Stop mode is entered when the DSC core executes a STOP instruction, and the STOP_disable field is write protected until the next reset.
 *  0b11..The DSC core STOP instruction does not cause entry into stop mode, and the STOP_disable field is write protected until the next reset.
 */
#define SIM_CTRL_STOP_DISABLE(x)                 (((uint16_t)(((uint16_t)(x)) << SIM_CTRL_STOP_DISABLE_SHIFT)) & SIM_CTRL_STOP_DISABLE_MASK)

#define SIM_CTRL_SWRST_MASK                      (0x10U)
#define SIM_CTRL_SWRST_SHIFT                     (4U)
/*! SWRST - SOFTWARE RESET */
#define SIM_CTRL_SWRST(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_CTRL_SWRST_SHIFT)) & SIM_CTRL_SWRST_MASK)

#define SIM_CTRL_ONCEEBL_MASK                    (0x20U)
#define SIM_CTRL_ONCEEBL_SHIFT                   (5U)
/*! ONCEEBL - OnCE Enable
 *  0b0..The OnCE clock to the DSC core is enabled when the core TAP is enabled.
 *  0b1..The OnCE clock to the DSC core is always enabled.
 */
#define SIM_CTRL_ONCEEBL(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_CTRL_ONCEEBL_SHIFT)) & SIM_CTRL_ONCEEBL_MASK)

#define SIM_CTRL_DMAEBL_MASK                     (0x1C0U)
#define SIM_CTRL_DMAEBL_SHIFT                    (6U)
/*! DMAEBL - DMA Enable
 *  0b000..DMA module is disabled.
 *  0b001..DMA module is enabled in run mode only.
 *  0b010..DMA module is enabled in run and wait modes only.
 *  0b011..DMA module is enabled in all power modes.
 *  0b100..DMA module is disabled and the DMAEbl field is write protected until the next reset.
 *  0b101..DMA module is enabled in run mode only and the DMAEbl field is write protected until the next reset.
 *  0b110..DMA module is enabled in run and wait modes only and the DMAEbl field is write protected until the next reset.
 *  0b111..DMA module is enabled in all low power modes and the DMAEbl field is write protected until the next reset.
 */
#define SIM_CTRL_DMAEBL(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_CTRL_DMAEBL_SHIFT)) & SIM_CTRL_DMAEBL_MASK)

#define SIM_CTRL_RST_FILT_MASK                   (0x400U)
#define SIM_CTRL_RST_FILT_SHIFT                  (10U)
/*! RST_FILT - External Reset Padcell Input Filter Enable
 *  0b0..Input filter on external reset disabled
 *  0b1..Input filter on external reset enabled
 */
#define SIM_CTRL_RST_FILT(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_CTRL_RST_FILT_SHIFT)) & SIM_CTRL_RST_FILT_MASK)
/*! @} */

/*! @name RSTAT - Reset Status Register */
/*! @{ */

#define SIM_RSTAT_POR_MASK                       (0x4U)
#define SIM_RSTAT_POR_SHIFT                      (2U)
/*! POR - Power-on Reset */
#define SIM_RSTAT_POR(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_POR_SHIFT)) & SIM_RSTAT_POR_MASK)

#define SIM_RSTAT_EXTR_MASK                      (0x8U)
#define SIM_RSTAT_EXTR_SHIFT                     (3U)
/*! EXTR - External Reset */
#define SIM_RSTAT_EXTR(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_EXTR_SHIFT)) & SIM_RSTAT_EXTR_MASK)

#define SIM_RSTAT_COP_LOR_MASK                   (0x10U)
#define SIM_RSTAT_COP_LOR_SHIFT                  (4U)
/*! COP_LOR - COP Loss of Reference Reset */
#define SIM_RSTAT_COP_LOR(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_COP_LOR_SHIFT)) & SIM_RSTAT_COP_LOR_MASK)

#define SIM_RSTAT_COP_CPU_MASK                   (0x20U)
#define SIM_RSTAT_COP_CPU_SHIFT                  (5U)
/*! COP_CPU - COP CPU Time-out Reset */
#define SIM_RSTAT_COP_CPU(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_COP_CPU_SHIFT)) & SIM_RSTAT_COP_CPU_MASK)

#define SIM_RSTAT_SWR_MASK                       (0x40U)
#define SIM_RSTAT_SWR_SHIFT                      (6U)
/*! SWR - Software Reset */
#define SIM_RSTAT_SWR(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_SWR_SHIFT)) & SIM_RSTAT_SWR_MASK)

#define SIM_RSTAT_EZPR_MASK                      (0x80U)
#define SIM_RSTAT_EZPR_SHIFT                     (7U)
/*! EZPR - EzPort Reset Request */
#define SIM_RSTAT_EZPR(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_EZPR_SHIFT)) & SIM_RSTAT_EZPR_MASK)
/*! @} */

/*! @name SCR0 - Software Control Register */
/*! @{ */

#define SIM_SCR0_SCR0_MASK                       (0xFFFFU)
#define SIM_SCR0_SCR0_SHIFT                      (0U)
/*! SCR0 - Software Control Data */
#define SIM_SCR0_SCR0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR0_SCR0_SHIFT)) & SIM_SCR0_SCR0_MASK)
/*! @} */

/*! @name SCR1 - Software Control Register */
/*! @{ */

#define SIM_SCR1_SCR1_MASK                       (0xFFFFU)
#define SIM_SCR1_SCR1_SHIFT                      (0U)
/*! SCR1 - Software Control Data */
#define SIM_SCR1_SCR1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR1_SCR1_SHIFT)) & SIM_SCR1_SCR1_MASK)
/*! @} */

/*! @name SCR2 - Software Control Register */
/*! @{ */

#define SIM_SCR2_SCR2_MASK                       (0xFFFFU)
#define SIM_SCR2_SCR2_SHIFT                      (0U)
/*! SCR2 - Software Control Data */
#define SIM_SCR2_SCR2(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR2_SCR2_SHIFT)) & SIM_SCR2_SCR2_MASK)
/*! @} */

/*! @name SCR3 - Software Control Register */
/*! @{ */

#define SIM_SCR3_SCR3_MASK                       (0xFFFFU)
#define SIM_SCR3_SCR3_SHIFT                      (0U)
/*! SCR3 - Software Control Data */
#define SIM_SCR3_SCR3(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR3_SCR3_SHIFT)) & SIM_SCR3_SCR3_MASK)
/*! @} */

/*! @name PWR - Power Control Register */
/*! @{ */

#define SIM_PWR_LRSTDBY_MASK                     (0x3U)
#define SIM_PWR_LRSTDBY_SHIFT                    (0U)
/*! LRSTDBY - Large Regulator Standby Control
 *  0b00..Large regulator placed in normal mode (default).
 *  0b01..Large regulator placed in standby mode.
 *  0b10..Large regulator placed in normal mode and LRSTDBY is write protected until device reset.
 *  0b11..Large regulator placed in standby mode and LRSTDBY is write protected until device reset.
 */
#define SIM_PWR_LRSTDBY(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PWR_LRSTDBY_SHIFT)) & SIM_PWR_LRSTDBY_MASK)

#define SIM_PWR_SR27STDBY_MASK                   (0xCU)
#define SIM_PWR_SR27STDBY_SHIFT                  (2U)
/*! SR27STDBY - Small Regulator 2.7 V Supply Standby Control
 *  0b00..Small regulator 2.7 V supply placed in normal mode (default).
 *  0b01..Small regulator 2.7 V supply placed in standby mode.
 *  0b10..Small regulator 2.7 V supply placed in normal mode and SR27STDBY is write protected until chip reset.
 *  0b11..Small regulator 2.7 V supply placed in standby mode and SR27STDBY is write protected until chip reset.
 */
#define SIM_PWR_SR27STDBY(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PWR_SR27STDBY_SHIFT)) & SIM_PWR_SR27STDBY_MASK)

#define SIM_PWR_SR27PDN_MASK                     (0x30U)
#define SIM_PWR_SR27PDN_SHIFT                    (4U)
/*! SR27PDN - Small Regulator 2.7 V Supply Powerdown Control
 *  0b00..Small regulator placed in normal mode (default).
 *  0b01..Small regulator placed in powerdown mode.
 *  0b10..Small regulator placed in normal mode and SR27PDN is write protected until chip reset.
 *  0b11..Small regulator placed in powerdown mode and SR27PDN is write protected until chip reset.
 */
#define SIM_PWR_SR27PDN(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PWR_SR27PDN_SHIFT)) & SIM_PWR_SR27PDN_MASK)

#define SIM_PWR_SR12STDBY_MASK                   (0xC0U)
#define SIM_PWR_SR12STDBY_SHIFT                  (6U)
/*! SR12STDBY - Small Regulator 1.2 V Supply Standby Control
 *  0b00..Small regulator 1.2 V supply placed in normal mode (default).
 *  0b01..Small regulator 1.2 V supply placed in standby mode.
 *  0b10..Small regulator 1.2 V supply placed in normal mode and SR12STDBY is write protected until chip reset.
 *  0b11..Small regulator 1.2 V supply placed in standby mode and SR12STDBY is write protected until chip reset.
 */
#define SIM_PWR_SR12STDBY(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PWR_SR12STDBY_SHIFT)) & SIM_PWR_SR12STDBY_MASK)
/*! @} */

/*! @name CLKOUT - Clock Output Select Register */
/*! @{ */

#define SIM_CLKOUT_CLKOSEL0_MASK                 (0x7U)
#define SIM_CLKOUT_CLKOSEL0_SHIFT                (0U)
/*! CLKOSEL0 - CLKOUT0 Select
 *  0b000..Function = Continuous System Clock; Signal Name = iclk_sys_cont System clock continuous after reset (100 MHz max)
 *  0b001..Function = 2x continuous clock; Signal Name = iclk_per_cont_2x 2x system frequency continuous after reset (200 MHz max)
 *  0b010..Function = div4 system clock; Signal Name = iclk_sys_div4_cont div4 system clock used for flash (25 MHz max)
 *  0b011..Function = Master Clock; Signal Name = mstr_osc Master clock source before PLL (ROSC, OSC, or external clock) continuous
 *  0b100..Function = 8 MHz / 400 kHz int. oscillator clock; Signal Name = rosc_8m_clk
 *  0b101..Function = 32 kHz int. oscillator clock; Signal Name = rosc_32k_clk
 *  0b110..Reserved. For normal operation, do not write 11x.
 *  0b111..Reserved. For normal operation, do not write 11x.
 */
#define SIM_CLKOUT_CLKOSEL0(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKOSEL0_SHIFT)) & SIM_CLKOUT_CLKOSEL0_MASK)

#define SIM_CLKOUT_CLKDIS0_MASK                  (0x20U)
#define SIM_CLKOUT_CLKDIS0_SHIFT                 (5U)
/*! CLKDIS0 - Disable for CLKOUT0
 *  0b0..CLKOUT0 output is enabled and outputs the signal indicated by CLKOSEL0
 *  0b1..CLKOUT0 is 0
 */
#define SIM_CLKOUT_CLKDIS0(x)                    (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKDIS0_SHIFT)) & SIM_CLKOUT_CLKDIS0_MASK)

#define SIM_CLKOUT_CLKOSEL1_MASK                 (0x380U)
#define SIM_CLKOUT_CLKOSEL1_SHIFT                (7U)
/*! CLKOSEL1 - CLKOUT1 Select
 *  0b000..Function = Continuous System Clock; Signal Name = iclk_sys_cont System clock continuous after reset (100 MHz max)
 *  0b001..Function = 2x continuous clock; Signal Name = iclk_per_cont_2x 2x system frequency continuous after reset (200 MHz max)
 *  0b010..Function = div4 system clock; Signal Name = iclk_sys_div4_cont div4 system clock used for flash (25 MHz max)
 *  0b011..Function = Master Clock; Signal Name = mstr_osc Master clock source before PLL (ROSC, OSC, or external clock) continuous
 *  0b100..Function = 8 MHz / 400 kHz int. oscillator clock; Signal Name = rosc_8m_clk
 *  0b101..Function = 32 kHz int. oscillator clock; Signal Name = rosc_32k_clk
 *  0b110..Reserved. For normal operation, do not write 11x.
 *  0b111..Reserved. For normal operation, do not write 11x.
 */
#define SIM_CLKOUT_CLKOSEL1(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKOSEL1_SHIFT)) & SIM_CLKOUT_CLKOSEL1_MASK)

#define SIM_CLKOUT_CLKDIS1_MASK                  (0x1000U)
#define SIM_CLKOUT_CLKDIS1_SHIFT                 (12U)
/*! CLKDIS1 - Disable for CLKOUT1
 *  0b0..CLKOUT1 output is enabled and outputs the signal indicated by CLKOSEL1
 *  0b1..CLKOUT1 is 0
 */
#define SIM_CLKOUT_CLKDIS1(x)                    (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKDIS1_SHIFT)) & SIM_CLKOUT_CLKDIS1_MASK)

#define SIM_CLKOUT_CLKODIV_MASK                  (0xE000U)
#define SIM_CLKOUT_CLKODIV_SHIFT                 (13U)
/*! CLKODIV - CLKOUT divide factor
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 4
 *  0b011..Divide by 8
 *  0b100..Divide by 16
 *  0b101..Divide by 32
 *  0b110..Divide by 64
 *  0b111..Divide by 128
 */
#define SIM_CLKOUT_CLKODIV(x)                    (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKODIV_SHIFT)) & SIM_CLKOUT_CLKODIV_MASK)
/*! @} */

/*! @name PCR - Peripheral Clock Rate Register */
/*! @{ */

#define SIM_PCR_SCI2_CR_MASK                     (0x800U)
#define SIM_PCR_SCI2_CR_SHIFT                    (11U)
/*! SCI2_CR - SCI2 Clock Rate
 *  0b0..SCI2 clock rate equals core clock rate; maximum 100 MHz (default)
 *  0b1..SCI2 clock rate equals 2X core clock rate
 */
#define SIM_PCR_SCI2_CR(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCR_SCI2_CR_SHIFT)) & SIM_PCR_SCI2_CR_MASK)

#define SIM_PCR_SCI1_CR_MASK                     (0x1000U)
#define SIM_PCR_SCI1_CR_SHIFT                    (12U)
/*! SCI1_CR - SCI1 Clock Rate
 *  0b0..SCI1 clock rate equals core clock rate; maximum 100 MHz (default)
 *  0b1..SCI1 clock rate equals 2X core clock rate
 */
#define SIM_PCR_SCI1_CR(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCR_SCI1_CR_SHIFT)) & SIM_PCR_SCI1_CR_MASK)

#define SIM_PCR_SCI0_CR_MASK                     (0x2000U)
#define SIM_PCR_SCI0_CR_SHIFT                    (13U)
/*! SCI0_CR - SCI0 Clock Rate
 *  0b0..SCI0 clock rate equals core clock rate; maximum 100 MHz (default)
 *  0b1..SCI0 clock rate equals 2X core clock rate
 */
#define SIM_PCR_SCI0_CR(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCR_SCI0_CR_SHIFT)) & SIM_PCR_SCI0_CR_MASK)
/*! @} */

/*! @name PCE0 - Peripheral Clock Enable Register 0 */
/*! @{ */

#define SIM_PCE0_GPIOG_MASK                      (0x1U)
#define SIM_PCE0_GPIOG_SHIFT                     (0U)
/*! GPIOG - GPIOG IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_GPIOG(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_GPIOG_SHIFT)) & SIM_PCE0_GPIOG_MASK)

#define SIM_PCE0_GPIOF_MASK                      (0x2U)
#define SIM_PCE0_GPIOF_SHIFT                     (1U)
/*! GPIOF - GPIOF IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_GPIOF(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_GPIOF_SHIFT)) & SIM_PCE0_GPIOF_MASK)

#define SIM_PCE0_GPIOE_MASK                      (0x4U)
#define SIM_PCE0_GPIOE_SHIFT                     (2U)
/*! GPIOE - GPIOE IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_GPIOE(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_GPIOE_SHIFT)) & SIM_PCE0_GPIOE_MASK)

#define SIM_PCE0_GPIOD_MASK                      (0x8U)
#define SIM_PCE0_GPIOD_SHIFT                     (3U)
/*! GPIOD - GPIOD IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_GPIOD(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_GPIOD_SHIFT)) & SIM_PCE0_GPIOD_MASK)

#define SIM_PCE0_GPIOC_MASK                      (0x10U)
#define SIM_PCE0_GPIOC_SHIFT                     (4U)
/*! GPIOC - GPIOC IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_GPIOC(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_GPIOC_SHIFT)) & SIM_PCE0_GPIOC_MASK)

#define SIM_PCE0_GPIOB_MASK                      (0x20U)
#define SIM_PCE0_GPIOB_SHIFT                     (5U)
/*! GPIOB - GPIOB IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_GPIOB(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_GPIOB_SHIFT)) & SIM_PCE0_GPIOB_MASK)

#define SIM_PCE0_GPIOA_MASK                      (0x40U)
#define SIM_PCE0_GPIOA_SHIFT                     (6U)
/*! GPIOA - GPIOA IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_GPIOA(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_GPIOA_SHIFT)) & SIM_PCE0_GPIOA_MASK)

#define SIM_PCE0_TB3_MASK                        (0x100U)
#define SIM_PCE0_TB3_SHIFT                       (8U)
/*! TB3 - TMRB3 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TB3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TB3_SHIFT)) & SIM_PCE0_TB3_MASK)

#define SIM_PCE0_TB2_MASK                        (0x200U)
#define SIM_PCE0_TB2_SHIFT                       (9U)
/*! TB2 - TMRB2 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TB2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TB2_SHIFT)) & SIM_PCE0_TB2_MASK)

#define SIM_PCE0_TB1_MASK                        (0x400U)
#define SIM_PCE0_TB1_SHIFT                       (10U)
/*! TB1 - TMRB1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TB1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TB1_SHIFT)) & SIM_PCE0_TB1_MASK)

#define SIM_PCE0_TB0_MASK                        (0x800U)
#define SIM_PCE0_TB0_SHIFT                       (11U)
/*! TB0 - TMRB0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TB0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TB0_SHIFT)) & SIM_PCE0_TB0_MASK)

#define SIM_PCE0_TA3_MASK                        (0x1000U)
#define SIM_PCE0_TA3_SHIFT                       (12U)
/*! TA3 - TMRA3 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TA3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TA3_SHIFT)) & SIM_PCE0_TA3_MASK)

#define SIM_PCE0_TA2_MASK                        (0x2000U)
#define SIM_PCE0_TA2_SHIFT                       (13U)
/*! TA2 - TMRA2 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TA2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TA2_SHIFT)) & SIM_PCE0_TA2_MASK)

#define SIM_PCE0_TA1_MASK                        (0x4000U)
#define SIM_PCE0_TA1_SHIFT                       (14U)
/*! TA1 - TMRA1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TA1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TA1_SHIFT)) & SIM_PCE0_TA1_MASK)

#define SIM_PCE0_TA0_MASK                        (0x8000U)
#define SIM_PCE0_TA0_SHIFT                       (15U)
/*! TA0 - TMRA0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE0_TA0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE0_TA0_SHIFT)) & SIM_PCE0_TA0_MASK)
/*! @} */

/*! @name PCE1 - Peripheral Clock Enable Register 1 */
/*! @{ */

#define SIM_PCE1_FLEXCAN_MASK                    (0x1U)
#define SIM_PCE1_FLEXCAN_SHIFT                   (0U)
/*! FLEXCAN - FlexCAN IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_FLEXCAN(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_FLEXCAN_SHIFT)) & SIM_PCE1_FLEXCAN_MASK)

#define SIM_PCE1_IIC1_MASK                       (0x20U)
#define SIM_PCE1_IIC1_SHIFT                      (5U)
/*! IIC1 - IIC1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_IIC1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_IIC1_SHIFT)) & SIM_PCE1_IIC1_MASK)

#define SIM_PCE1_IIC0_MASK                       (0x40U)
#define SIM_PCE1_IIC0_SHIFT                      (6U)
/*! IIC0 - IIC0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_IIC0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_IIC0_SHIFT)) & SIM_PCE1_IIC0_MASK)

#define SIM_PCE1_QSPI2_MASK                      (0x80U)
#define SIM_PCE1_QSPI2_SHIFT                     (7U)
/*! QSPI2 - QSPI2 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_QSPI2(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_QSPI2_SHIFT)) & SIM_PCE1_QSPI2_MASK)

#define SIM_PCE1_QSPI1_MASK                      (0x100U)
#define SIM_PCE1_QSPI1_SHIFT                     (8U)
/*! QSPI1 - QSPI1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_QSPI1(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_QSPI1_SHIFT)) & SIM_PCE1_QSPI1_MASK)

#define SIM_PCE1_QSPI0_MASK                      (0x200U)
#define SIM_PCE1_QSPI0_SHIFT                     (9U)
/*! QSPI0 - QSPI0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_QSPI0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_QSPI0_SHIFT)) & SIM_PCE1_QSPI0_MASK)

#define SIM_PCE1_SCI2_MASK                       (0x400U)
#define SIM_PCE1_SCI2_SHIFT                      (10U)
/*! SCI2 - SCI2 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_SCI2(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_SCI2_SHIFT)) & SIM_PCE1_SCI2_MASK)

#define SIM_PCE1_SCI1_MASK                       (0x800U)
#define SIM_PCE1_SCI1_SHIFT                      (11U)
/*! SCI1 - SCI1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_SCI1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_SCI1_SHIFT)) & SIM_PCE1_SCI1_MASK)

#define SIM_PCE1_SCI0_MASK                       (0x1000U)
#define SIM_PCE1_SCI0_SHIFT                      (12U)
/*! SCI0 - SCI0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_SCI0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_SCI0_SHIFT)) & SIM_PCE1_SCI0_MASK)

#define SIM_PCE1_DAC_MASK                        (0x2000U)
#define SIM_PCE1_DAC_SHIFT                       (13U)
/*! DAC - DAC IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_DAC(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_DAC_SHIFT)) & SIM_PCE1_DAC_MASK)
/*! @} */

/*! @name PCE2 - Peripheral Clock Enable Register 2 */
/*! @{ */

#define SIM_PCE2_PDB1_MASK                       (0x1U)
#define SIM_PCE2_PDB1_SHIFT                      (0U)
/*! PDB1 - Programmable Delay Block IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_PDB1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_PDB1_SHIFT)) & SIM_PCE2_PDB1_MASK)

#define SIM_PCE2_PDB0_MASK                       (0x2U)
#define SIM_PCE2_PDB0_SHIFT                      (1U)
/*! PDB0 - Programmable Delay Block IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_PDB0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_PDB0_SHIFT)) & SIM_PCE2_PDB0_MASK)

#define SIM_PCE2_PIT1_MASK                       (0x4U)
#define SIM_PCE2_PIT1_SHIFT                      (2U)
/*! PIT1 - Programmable Interval Timer IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_PIT1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_PIT1_SHIFT)) & SIM_PCE2_PIT1_MASK)

#define SIM_PCE2_PIT0_MASK                       (0x8U)
#define SIM_PCE2_PIT0_SHIFT                      (3U)
/*! PIT0 - Programmable Interval Timer IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_PIT0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_PIT0_SHIFT)) & SIM_PCE2_PIT0_MASK)

#define SIM_PCE2_QDC_MASK                        (0x10U)
#define SIM_PCE2_QDC_SHIFT                       (4U)
/*! QDC - Quadrature Decoder IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_QDC(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_QDC_SHIFT)) & SIM_PCE2_QDC_MASK)

#define SIM_PCE2_CRC_MASK                        (0x20U)
#define SIM_PCE2_CRC_SHIFT                       (5U)
/*! CRC - CRC IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CRC(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CRC_SHIFT)) & SIM_PCE2_CRC_MASK)

#define SIM_PCE2_CYCADC_MASK                     (0x80U)
#define SIM_PCE2_CYCADC_SHIFT                    (7U)
/*! CYCADC - Cyclic ADC IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CYCADC(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CYCADC_SHIFT)) & SIM_PCE2_CYCADC_MASK)

#define SIM_PCE2_SARADC_MASK                     (0x100U)
#define SIM_PCE2_SARADC_SHIFT                    (8U)
/*! SARADC - SAR ADC IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_SARADC(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_SARADC_SHIFT)) & SIM_PCE2_SARADC_MASK)

#define SIM_PCE2_CMPD_MASK                       (0x200U)
#define SIM_PCE2_CMPD_SHIFT                      (9U)
/*! CMPD - CMPD IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPD(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPD_SHIFT)) & SIM_PCE2_CMPD_MASK)

#define SIM_PCE2_CMPC_MASK                       (0x400U)
#define SIM_PCE2_CMPC_SHIFT                      (10U)
/*! CMPC - CMPC IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPC(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPC_SHIFT)) & SIM_PCE2_CMPC_MASK)

#define SIM_PCE2_CMPB_MASK                       (0x800U)
#define SIM_PCE2_CMPB_SHIFT                      (11U)
/*! CMPB - CMPB IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPB(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPB_SHIFT)) & SIM_PCE2_CMPB_MASK)

#define SIM_PCE2_CMPA_MASK                       (0x1000U)
#define SIM_PCE2_CMPA_SHIFT                      (12U)
/*! CMPA - CMPA IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPA(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPA_SHIFT)) & SIM_PCE2_CMPA_MASK)
/*! @} */

/*! @name PCE3 - Peripheral Clock Enable Register 3 */
/*! @{ */

#define SIM_PCE3_PWMBCH3_MASK                    (0x1U)
#define SIM_PCE3_PWMBCH3_SHIFT                   (0U)
/*! PWMBCH3 - PWMB Channel 3 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMBCH3(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMBCH3_SHIFT)) & SIM_PCE3_PWMBCH3_MASK)

#define SIM_PCE3_PWMBCH2_MASK                    (0x2U)
#define SIM_PCE3_PWMBCH2_SHIFT                   (1U)
/*! PWMBCH2 - PWMB Channel 2 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMBCH2(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMBCH2_SHIFT)) & SIM_PCE3_PWMBCH2_MASK)

#define SIM_PCE3_PWMBCH1_MASK                    (0x4U)
#define SIM_PCE3_PWMBCH1_SHIFT                   (2U)
/*! PWMBCH1 - PWMB Channel 1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMBCH1(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMBCH1_SHIFT)) & SIM_PCE3_PWMBCH1_MASK)

#define SIM_PCE3_PWMBCH0_MASK                    (0x8U)
#define SIM_PCE3_PWMBCH0_SHIFT                   (3U)
/*! PWMBCH0 - PWMB Channel 0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMBCH0(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMBCH0_SHIFT)) & SIM_PCE3_PWMBCH0_MASK)

#define SIM_PCE3_PWMACH3_MASK                    (0x10U)
#define SIM_PCE3_PWMACH3_SHIFT                   (4U)
/*! PWMACH3 - PWMA Channel 3 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMACH3(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMACH3_SHIFT)) & SIM_PCE3_PWMACH3_MASK)

#define SIM_PCE3_PWMACH2_MASK                    (0x20U)
#define SIM_PCE3_PWMACH2_SHIFT                   (5U)
/*! PWMACH2 - PWMA Channel 2 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMACH2(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMACH2_SHIFT)) & SIM_PCE3_PWMACH2_MASK)

#define SIM_PCE3_PWMACH1_MASK                    (0x40U)
#define SIM_PCE3_PWMACH1_SHIFT                   (6U)
/*! PWMACH1 - PWMA Channel 1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMACH1(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMACH1_SHIFT)) & SIM_PCE3_PWMACH1_MASK)

#define SIM_PCE3_PWMACH0_MASK                    (0x80U)
#define SIM_PCE3_PWMACH0_SHIFT                   (7U)
/*! PWMACH0 - PWMA Channel 0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_PWMACH0(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_PWMACH0_SHIFT)) & SIM_PCE3_PWMACH0_MASK)
/*! @} */

/*! @name SD0 - STOP Disable Register 0 */
/*! @{ */

#define SIM_SD0_GPIOG_MASK                       (0x1U)
#define SIM_SD0_GPIOG_SHIFT                      (0U)
/*! GPIOG - GPIOG IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_GPIOG(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD0_GPIOG_SHIFT)) & SIM_SD0_GPIOG_MASK)

#define SIM_SD0_GPIOF_MASK                       (0x2U)
#define SIM_SD0_GPIOF_SHIFT                      (1U)
/*! GPIOF - GPIOF IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_GPIOF(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD0_GPIOF_SHIFT)) & SIM_SD0_GPIOF_MASK)

#define SIM_SD0_GPIOE_MASK                       (0x4U)
#define SIM_SD0_GPIOE_SHIFT                      (2U)
/*! GPIOE - GPIOE IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_GPIOE(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD0_GPIOE_SHIFT)) & SIM_SD0_GPIOE_MASK)

#define SIM_SD0_GPIOD_MASK                       (0x8U)
#define SIM_SD0_GPIOD_SHIFT                      (3U)
/*! GPIOD - GPIOD IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_GPIOD(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD0_GPIOD_SHIFT)) & SIM_SD0_GPIOD_MASK)

#define SIM_SD0_GPIOC_MASK                       (0x10U)
#define SIM_SD0_GPIOC_SHIFT                      (4U)
/*! GPIOC - GPIOC IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_GPIOC(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD0_GPIOC_SHIFT)) & SIM_SD0_GPIOC_MASK)

#define SIM_SD0_GPIOB_MASK                       (0x20U)
#define SIM_SD0_GPIOB_SHIFT                      (5U)
/*! GPIOB - GPIOB IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_GPIOB(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD0_GPIOB_SHIFT)) & SIM_SD0_GPIOB_MASK)

#define SIM_SD0_GPIOA_MASK                       (0x40U)
#define SIM_SD0_GPIOA_SHIFT                      (6U)
/*! GPIOA - GPIOA IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_GPIOA(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD0_GPIOA_SHIFT)) & SIM_SD0_GPIOA_MASK)

#define SIM_SD0_TB3_MASK                         (0x100U)
#define SIM_SD0_TB3_SHIFT                        (8U)
/*! TB3 - TMRB3 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TB3(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TB3_SHIFT)) & SIM_SD0_TB3_MASK)

#define SIM_SD0_TB2_MASK                         (0x200U)
#define SIM_SD0_TB2_SHIFT                        (9U)
/*! TB2 - TMRB2 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TB2(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TB2_SHIFT)) & SIM_SD0_TB2_MASK)

#define SIM_SD0_TB1_MASK                         (0x400U)
#define SIM_SD0_TB1_SHIFT                        (10U)
/*! TB1 - TMRB1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TB1(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TB1_SHIFT)) & SIM_SD0_TB1_MASK)

#define SIM_SD0_TB0_MASK                         (0x800U)
#define SIM_SD0_TB0_SHIFT                        (11U)
/*! TB0 - TMRB0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TB0(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TB0_SHIFT)) & SIM_SD0_TB0_MASK)

#define SIM_SD0_TA3_MASK                         (0x1000U)
#define SIM_SD0_TA3_SHIFT                        (12U)
/*! TA3 - TMRA3 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TA3(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TA3_SHIFT)) & SIM_SD0_TA3_MASK)

#define SIM_SD0_TA2_MASK                         (0x2000U)
#define SIM_SD0_TA2_SHIFT                        (13U)
/*! TA2 - TMRA2 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TA2(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TA2_SHIFT)) & SIM_SD0_TA2_MASK)

#define SIM_SD0_TA1_MASK                         (0x4000U)
#define SIM_SD0_TA1_SHIFT                        (14U)
/*! TA1 - TMRA1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TA1(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TA1_SHIFT)) & SIM_SD0_TA1_MASK)

#define SIM_SD0_TA0_MASK                         (0x8000U)
#define SIM_SD0_TA0_SHIFT                        (15U)
/*! TA0 - TMRA0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD0_TA0(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD0_TA0_SHIFT)) & SIM_SD0_TA0_MASK)
/*! @} */

/*! @name SD1 - Peripheral Clock STOP Disable Register 1 */
/*! @{ */

#define SIM_SD1_FLEXCAN_MASK                     (0x1U)
#define SIM_SD1_FLEXCAN_SHIFT                    (0U)
/*! FLEXCAN - FlexCAN IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_FLEXCAN(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD1_FLEXCAN_SHIFT)) & SIM_SD1_FLEXCAN_MASK)

#define SIM_SD1_IIC1_MASK                        (0x20U)
#define SIM_SD1_IIC1_SHIFT                       (5U)
/*! IIC1 - IIC1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode, but the IIC1 module will not enter stop mode.
 */
#define SIM_SD1_IIC1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_IIC1_SHIFT)) & SIM_SD1_IIC1_MASK)

#define SIM_SD1_IIC0_MASK                        (0x40U)
#define SIM_SD1_IIC0_SHIFT                       (6U)
/*! IIC0 - IIC0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode, but the IIC0 module will not enter stop mode.
 */
#define SIM_SD1_IIC0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_IIC0_SHIFT)) & SIM_SD1_IIC0_MASK)

#define SIM_SD1_QSPI2_MASK                       (0x80U)
#define SIM_SD1_QSPI2_SHIFT                      (7U)
/*! QSPI2 - QSPI2 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_QSPI2(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD1_QSPI2_SHIFT)) & SIM_SD1_QSPI2_MASK)

#define SIM_SD1_QSPI1_MASK                       (0x100U)
#define SIM_SD1_QSPI1_SHIFT                      (8U)
/*! QSPI1 - QSPI1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_QSPI1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD1_QSPI1_SHIFT)) & SIM_SD1_QSPI1_MASK)

#define SIM_SD1_QSPI0_MASK                       (0x200U)
#define SIM_SD1_QSPI0_SHIFT                      (9U)
/*! QSPI0 - QSPI0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_QSPI0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD1_QSPI0_SHIFT)) & SIM_SD1_QSPI0_MASK)

#define SIM_SD1_SCI2_MASK                        (0x400U)
#define SIM_SD1_SCI2_SHIFT                       (10U)
/*! SCI2 - SCI2 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_SCI2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_SCI2_SHIFT)) & SIM_SD1_SCI2_MASK)

#define SIM_SD1_SCI1_MASK                        (0x800U)
#define SIM_SD1_SCI1_SHIFT                       (11U)
/*! SCI1 - SCI1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_SCI1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_SCI1_SHIFT)) & SIM_SD1_SCI1_MASK)

#define SIM_SD1_SCI0_MASK                        (0x1000U)
#define SIM_SD1_SCI0_SHIFT                       (12U)
/*! SCI0 - SCI0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_SCI0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_SCI0_SHIFT)) & SIM_SD1_SCI0_MASK)

#define SIM_SD1_DAC_MASK                         (0x2000U)
#define SIM_SD1_DAC_SHIFT                        (13U)
/*! DAC - DAC IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_DAC(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD1_DAC_SHIFT)) & SIM_SD1_DAC_MASK)
/*! @} */

/*! @name SD2 - Peripheral Clock STOP Disable Register 2 */
/*! @{ */

#define SIM_SD2_PDB1_MASK                        (0x1U)
#define SIM_SD2_PDB1_SHIFT                       (0U)
/*! PDB1 - Programmable Delay Block IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_PDB1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_PDB1_SHIFT)) & SIM_SD2_PDB1_MASK)

#define SIM_SD2_PDB0_MASK                        (0x2U)
#define SIM_SD2_PDB0_SHIFT                       (1U)
/*! PDB0 - Programmable Delay Block IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_PDB0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_PDB0_SHIFT)) & SIM_SD2_PDB0_MASK)

#define SIM_SD2_PIT1_MASK                        (0x4U)
#define SIM_SD2_PIT1_SHIFT                       (2U)
/*! PIT1 - Programmable Interval Timer IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_PIT1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_PIT1_SHIFT)) & SIM_SD2_PIT1_MASK)

#define SIM_SD2_PIT0_MASK                        (0x8U)
#define SIM_SD2_PIT0_SHIFT                       (3U)
/*! PIT0 - Programmable Interval Timer IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_PIT0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_PIT0_SHIFT)) & SIM_SD2_PIT0_MASK)

#define SIM_SD2_QDC_MASK                         (0x10U)
#define SIM_SD2_QDC_SHIFT                        (4U)
/*! QDC - Quadrature Decoder IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_QDC(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD2_QDC_SHIFT)) & SIM_SD2_QDC_MASK)

#define SIM_SD2_CRC_MASK                         (0x20U)
#define SIM_SD2_CRC_SHIFT                        (5U)
/*! CRC - CRC IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CRC(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CRC_SHIFT)) & SIM_SD2_CRC_MASK)

#define SIM_SD2_CYCADC_MASK                      (0x80U)
#define SIM_SD2_CYCADC_SHIFT                     (7U)
/*! CYCADC - Cyclic ADC IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CYCADC(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CYCADC_SHIFT)) & SIM_SD2_CYCADC_MASK)

#define SIM_SD2_SARADC_MASK                      (0x100U)
#define SIM_SD2_SARADC_SHIFT                     (8U)
/*! SARADC - SAR ADC IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_SARADC(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_SD2_SARADC_SHIFT)) & SIM_SD2_SARADC_MASK)

#define SIM_SD2_CMPD_MASK                        (0x200U)
#define SIM_SD2_CMPD_SHIFT                       (9U)
/*! CMPD - CMPD IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPD(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPD_SHIFT)) & SIM_SD2_CMPD_MASK)

#define SIM_SD2_CMPC_MASK                        (0x400U)
#define SIM_SD2_CMPC_SHIFT                       (10U)
/*! CMPC - CMPC IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPC(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPC_SHIFT)) & SIM_SD2_CMPC_MASK)

#define SIM_SD2_CMPB_MASK                        (0x800U)
#define SIM_SD2_CMPB_SHIFT                       (11U)
/*! CMPB - CMPB IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPB(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPB_SHIFT)) & SIM_SD2_CMPB_MASK)

#define SIM_SD2_CMPA_MASK                        (0x1000U)
#define SIM_SD2_CMPA_SHIFT                       (12U)
/*! CMPA - CMPA IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPA(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPA_SHIFT)) & SIM_SD2_CMPA_MASK)
/*! @} */

/*! @name SD3 - Peripheral Clock STOP Disable Register 3 */
/*! @{ */

#define SIM_SD3_PWMBCH3_MASK                     (0x1U)
#define SIM_SD3_PWMBCH3_SHIFT                    (0U)
/*! PWMBCH3 - PWMB Channel 3 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMBCH3(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMBCH3_SHIFT)) & SIM_SD3_PWMBCH3_MASK)

#define SIM_SD3_PWMBCH2_MASK                     (0x2U)
#define SIM_SD3_PWMBCH2_SHIFT                    (1U)
/*! PWMBCH2 - PWMB Channel 2 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMBCH2(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMBCH2_SHIFT)) & SIM_SD3_PWMBCH2_MASK)

#define SIM_SD3_PWMBCH1_MASK                     (0x4U)
#define SIM_SD3_PWMBCH1_SHIFT                    (2U)
/*! PWMBCH1 - PWMB Channel 1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMBCH1(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMBCH1_SHIFT)) & SIM_SD3_PWMBCH1_MASK)

#define SIM_SD3_PWMBCH0_MASK                     (0x8U)
#define SIM_SD3_PWMBCH0_SHIFT                    (3U)
/*! PWMBCH0 - PWMB Channel 0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMBCH0(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMBCH0_SHIFT)) & SIM_SD3_PWMBCH0_MASK)

#define SIM_SD3_PWMACH3_MASK                     (0x10U)
#define SIM_SD3_PWMACH3_SHIFT                    (4U)
/*! PWMACH3 - PWMA Channel 3 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMACH3(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMACH3_SHIFT)) & SIM_SD3_PWMACH3_MASK)

#define SIM_SD3_PWMACH2_MASK                     (0x20U)
#define SIM_SD3_PWMACH2_SHIFT                    (5U)
/*! PWMACH2 - PWMA Channel 2 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMACH2(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMACH2_SHIFT)) & SIM_SD3_PWMACH2_MASK)

#define SIM_SD3_PWMACH1_MASK                     (0x40U)
#define SIM_SD3_PWMACH1_SHIFT                    (6U)
/*! PWMACH1 - PWMA Channel 1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMACH1(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMACH1_SHIFT)) & SIM_SD3_PWMACH1_MASK)

#define SIM_SD3_PWMACH0_MASK                     (0x80U)
#define SIM_SD3_PWMACH0_SHIFT                    (7U)
/*! PWMACH0 - PWMA Channel 0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_PWMACH0(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_SD3_PWMACH0_SHIFT)) & SIM_SD3_PWMACH0_MASK)
/*! @} */

/*! @name IOSAHI - I/O Short Address Location Register */
/*! @{ */

#define SIM_IOSAHI_ISAL_MASK                     (0x3U)
#define SIM_IOSAHI_ISAL_SHIFT                    (0U)
/*! ISAL - Bits 23:22 of the address */
#define SIM_IOSAHI_ISAL(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IOSAHI_ISAL_SHIFT)) & SIM_IOSAHI_ISAL_MASK)
/*! @} */

/*! @name IOSALO - I/O Short Address Location Register */
/*! @{ */

#define SIM_IOSALO_ISAL_MASK                     (0xFFFFU)
#define SIM_IOSALO_ISAL_SHIFT                    (0U)
/*! ISAL - Bits 21:6 of the address */
#define SIM_IOSALO_ISAL(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IOSALO_ISAL_SHIFT)) & SIM_IOSALO_ISAL_MASK)
/*! @} */

/*! @name PROT - Protection Register */
/*! @{ */

#define SIM_PROT_GIPSP_MASK                      (0x3U)
#define SIM_PROT_GIPSP_SHIFT                     (0U)
/*! GIPSP - GPIO and Internal Peripheral Select Protection
 *  0b00..Write protection off (default).
 *  0b01..Write protection on.
 *  0b10..Write protection off and locked until chip reset.
 *  0b11..Write protection on and locked until chip reset.
 */
#define SIM_PROT_GIPSP(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PROT_GIPSP_SHIFT)) & SIM_PROT_GIPSP_MASK)

#define SIM_PROT_PCEP_MASK                       (0xCU)
#define SIM_PROT_PCEP_SHIFT                      (2U)
/*! PCEP - Peripheral Clock Enable Protection
 *  0b00..Write protection off (default).
 *  0b01..Write protection on.
 *  0b10..Write protection off and locked until chip reset.
 *  0b11..Write protection on and locked until chip reset.
 */
#define SIM_PROT_PCEP(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PROT_PCEP_SHIFT)) & SIM_PROT_PCEP_MASK)

#define SIM_PROT_GDP_MASK                        (0x30U)
#define SIM_PROT_GDP_SHIFT                       (4U)
/*! GDP - GPIO Port D Protection
 *  0b00..Write protection off (default).
 *  0b01..Write protection on.
 *  0b10..Write protection off and locked until chip reset.
 *  0b11..Write protection on and locked until chip reset.
 */
#define SIM_PROT_GDP(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PROT_GDP_SHIFT)) & SIM_PROT_GDP_MASK)

#define SIM_PROT_PMODE_MASK                      (0xC0U)
#define SIM_PROT_PMODE_SHIFT                     (6U)
/*! PMODE - Power Mode Control Write Protection
 *  0b00..Write protection off (default).
 *  0b01..Write protection on.
 *  0b10..Write protection off and locked until chip reset.
 *  0b11..Write protection on and locked until chip reset.
 */
#define SIM_PROT_PMODE(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PROT_PMODE_SHIFT)) & SIM_PROT_PMODE_MASK)
/*! @} */

/*! @name GPSAL - GPIOA LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSAL_A0_MASK                        (0x1U)
#define SIM_GPSAL_A0_SHIFT                       (0U)
/*! A0 - Configure GPIO A0
 *  0b0..Function = ANA0/CMPA3; Peripheral = ADC/CMPA; Direction = AN_IN
 *  0b1..Function = CMPC_O; Peripheral = CMPC; Direction = OUT
 */
#define SIM_GPSAL_A0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSAL_A0_SHIFT)) & SIM_GPSAL_A0_MASK)
/*! @} */

/*! @name GPSBH - GPIOB MSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSBH_B9_MASK                        (0xCU)
#define SIM_GPSBH_B9_SHIFT                       (2U)
/*! B9 - Configure GPIO B9
 *  0b00..Function = ANC13; Peripheral = ADC; Direction = AN_IN
 *  0b01..Function = XB_IN9; Peripheral = XBAR; Direction = IN
 *  0b10..Function = MISOK2; Peripheral = SPI2; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSBH_B9(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSBH_B9_SHIFT)) & SIM_GPSBH_B9_MASK)

#define SIM_GPSBH_B10_MASK                       (0x30U)
#define SIM_GPSBH_B10_SHIFT                      (4U)
/*! B10 - Configure GPIO B10
 *  0b00..Function = ANC14; Peripheral = ADC; Direction = AN_IN
 *  0b01..Function = XB_IN8; Peripheral = XBAR; Direction = IN
 *  0b10..Function = MOSI2; Peripheral = SPI2; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSBH_B10(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSBH_B10_SHIFT)) & SIM_GPSBH_B10_MASK)

#define SIM_GPSBH_B11_MASK                       (0xC0U)
#define SIM_GPSBH_B11_SHIFT                      (6U)
/*! B11 - Configure GPIO B11
 *  0b00..Function = ANC15; Peripheral = ADC; Direction = AN_IN
 *  0b01..Function = XB_IN7; Peripheral = XBAR; Direction = IN
 *  0b10..Function = SCK2; Peripheral = SPI2; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSBH_B11(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSBH_B11_SHIFT)) & SIM_GPSBH_B11_MASK)
/*! @} */

/*! @name GPSCL - GPIOC LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSCL_C0_MASK                        (0x1U)
#define SIM_GPSCL_C0_SHIFT                       (0U)
/*! C0 - Configure GPIO C0
 *  0b0..Function = EXTAL; Peripheral = OSC; Direction = AN_IN
 *  0b1..Function = CLKIN; Peripheral = OCCS; Direction = IN
 */
#define SIM_GPSCL_C0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C0_SHIFT)) & SIM_GPSCL_C0_MASK)

#define SIM_GPSCL_C2_MASK                        (0x30U)
#define SIM_GPSCL_C2_SHIFT                       (4U)
/*! C2 - Configure GPIO C2
 *  0b00..Function = TXD0; Peripheral = SCI0; Direction = IO
 *  0b01..Function = TB0; Peripheral = TMRB; Direction = IO
 *  0b10..Function = XB_IN2; Peripheral = XBAR; Direction = IN
 *  0b11..Function = CLKOUT0; Peripheral = SIM; Direction = OUT
 */
#define SIM_GPSCL_C2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C2_SHIFT)) & SIM_GPSCL_C2_MASK)

#define SIM_GPSCL_C3_MASK                        (0xC0U)
#define SIM_GPSCL_C3_SHIFT                       (6U)
/*! C3
 *  0b00..Function = TA0; Peripheral = TMRA; Direction = IO
 *  0b01..Function = CMPA_O; Peripheral = CMPA; Direction = OUT
 *  0b10..Function = RXD0; Peripheral = SCI0; Direction = IN
 *  0b11..Function = CLKIN1; Peripheral = SIM; Direction = IN
 */
#define SIM_GPSCL_C3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C3_SHIFT)) & SIM_GPSCL_C3_MASK)

#define SIM_GPSCL_C4_MASK                        (0x300U)
#define SIM_GPSCL_C4_SHIFT                       (8U)
/*! C4 - Configure GPIO C4
 *  0b00..Function = TA1; Peripheral = TMRA; Direction = IO
 *  0b01..Function = CMPB_O; Peripheral = CMPB; Direction = OUT
 *  0b10..Function = XB_IN8; Peripheral = XBAR; Direction = IN
 *  0b11..Function = EWM_OUT_B; Peripheral = EWM; Direction = OUT
 */
#define SIM_GPSCL_C4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C4_SHIFT)) & SIM_GPSCL_C4_MASK)

#define SIM_GPSCL_C5_MASK                        (0x400U)
#define SIM_GPSCL_C5_SHIFT                       (10U)
/*! C5 - Configure GPIO C5
 *  0b0..Function = DACO; Peripheral = DAC; Direction = AN_OUT
 *  0b1..Function = XB_IN7; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSCL_C5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C5_SHIFT)) & SIM_GPSCL_C5_MASK)

#define SIM_GPSCL_C6_MASK                        (0x3000U)
#define SIM_GPSCL_C6_SHIFT                       (12U)
/*! C6 - Configure GPIO C6
 *  0b00..Function = TA2; Peripheral = TMRA; Direction = IO
 *  0b01..Function = XB_IN3; Peripheral = XBAR; Direction = IN
 *  0b10..Function = CMPREF; Peripheral = HSCMP A/B/C/D; Direction = AN_IN
 *  0b11..Reserved
 */
#define SIM_GPSCL_C6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C6_SHIFT)) & SIM_GPSCL_C6_MASK)

#define SIM_GPSCL_C7_MASK                        (0x4000U)
#define SIM_GPSCL_C7_SHIFT                       (14U)
/*! C7 - Configure GPIO C7
 *  0b0..Function = SS0_B; Peripheral = SPI0; Direction = IO
 *  0b1..Function = TXD0; Peripheral = SCI0; Direction = IO
 */
#define SIM_GPSCL_C7(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C7_SHIFT)) & SIM_GPSCL_C7_MASK)
/*! @} */

/*! @name GPSCH - GPIOC MSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSCH_C8_MASK                        (0x3U)
#define SIM_GPSCH_C8_SHIFT                       (0U)
/*! C8 - Configure GPIO C8
 *  0b00..Function = MISO0; Peripheral = SPI0; Direction = IO
 *  0b01..Function = RXD0; Peripheral = SCI0; Direction = IN
 *  0b10..Function = XB_IN9; Peripheral = XBAR; Direction = IN
 *  0b11..Reserved
 */
#define SIM_GPSCH_C8(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C8_SHIFT)) & SIM_GPSCH_C8_MASK)

#define SIM_GPSCH_C9_MASK                        (0x4U)
#define SIM_GPSCH_C9_SHIFT                       (2U)
/*! C9 - Configure GPIO C9
 *  0b0..Function = SCLK0; Peripheral = SPI0; Direction = IO
 *  0b1..Function = XB_IN4; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSCH_C9(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C9_SHIFT)) & SIM_GPSCH_C9_MASK)

#define SIM_GPSCH_C10_MASK                       (0x30U)
#define SIM_GPSCH_C10_SHIFT                      (4U)
/*! C10 - Configure GPIO C10
 *  0b00..Function = MOSI0; Peripheral = SPI0; Direction = IO
 *  0b01..Function = XB_IN5; Peripheral = XBAR; Direction = IN
 *  0b10..Function = MISO0; Peripheral = SPI0; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSCH_C10(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C10_SHIFT)) & SIM_GPSCH_C10_MASK)

#define SIM_GPSCH_C11_MASK                       (0xC0U)
#define SIM_GPSCH_C11_SHIFT                      (6U)
/*! C11 - Configure GPIO C11
 *  0b00..Function = CANTX; Peripheral = FlexCAN; Direction = OD_OUT
 *  0b01..Function = SCL1; Peripheral = IIC1; Direction = OD_IO
 *  0b10..Function = TXD1; Peripheral = SCI1; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSCH_C11(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C11_SHIFT)) & SIM_GPSCH_C11_MASK)

#define SIM_GPSCH_C12_MASK                       (0x300U)
#define SIM_GPSCH_C12_SHIFT                      (8U)
/*! C12 - Configure GPIO C12
 *  0b00..Function = CANRX; Peripheral = FlexCAN; Direction = IN
 *  0b01..Function = SDA1; Peripheral = IIC1; Direction = OD_IO
 *  0b10..Function = RXD1; Peripheral = SCI1; Direction = IN
 *  0b11..Reserved
 */
#define SIM_GPSCH_C12(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C12_SHIFT)) & SIM_GPSCH_C12_MASK)

#define SIM_GPSCH_C13_MASK                       (0xC00U)
#define SIM_GPSCH_C13_SHIFT                      (10U)
/*! C13 - Configure GPIO C13
 *  0b00..Function = TA3; Peripheral = TMRA; Direction = IO
 *  0b01..Function = XB_IN6; Peripheral = XBAR; Direction = IN
 *  0b10..Function = EWM_OUT_B; Peripheral = EWM; Direction = OUT
 *  0b11..Reserved
 */
#define SIM_GPSCH_C13(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C13_SHIFT)) & SIM_GPSCH_C13_MASK)

#define SIM_GPSCH_C14_MASK                       (0x1000U)
#define SIM_GPSCH_C14_SHIFT                      (12U)
/*! C14 - Configure GPIO C14
 *  0b0..Function = SDA0; Peripheral = IIC0; Direction = OD_IO
 *  0b1..Function = XB_OUT4; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSCH_C14(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C14_SHIFT)) & SIM_GPSCH_C14_MASK)

#define SIM_GPSCH_C15_MASK                       (0x4000U)
#define SIM_GPSCH_C15_SHIFT                      (14U)
/*! C15 - Configure GPIO C15
 *  0b0..Function = SCL0; Peripheral = IIC0; Direction = OD_IO
 *  0b1..Function = XB_OUT5; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSCH_C15(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C15_SHIFT)) & SIM_GPSCH_C15_MASK)
/*! @} */

/*! @name GPSDL - GPIOD LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSDL_D5_MASK                        (0xC00U)
#define SIM_GPSDL_D5_SHIFT                       (10U)
/*! D5 - Configure GPIO D5
 *  0b00..Function = RXD2; Peripheral = SCI2; Direction = IN
 *  0b01..Function = XB_IN5; Peripheral = XBAR; Direction = IN
 *  0b10..Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
 *  0b11..Reserved
 */
#define SIM_GPSDL_D5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSDL_D5_SHIFT)) & SIM_GPSDL_D5_MASK)

#define SIM_GPSDL_D6_MASK                        (0x3000U)
#define SIM_GPSDL_D6_SHIFT                       (12U)
/*! D6 - Configure GPIO D6
 *  0b00..Function = TXD2; Peripheral = SCI1; Direction = IO
 *  0b01..Function = XB_IN4; Peripheral = XBAR; Direction = IN
 *  0b10..Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
 *  0b11..Reserved
 */
#define SIM_GPSDL_D6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSDL_D6_SHIFT)) & SIM_GPSDL_D6_MASK)

#define SIM_GPSDL_D7_MASK                        (0xC000U)
#define SIM_GPSDL_D7_SHIFT                       (14U)
/*! D7 - Configure GPIO D7
 *  0b00..Function = XB_OUT11; Peripheral = XBAR; Direction = OUT
 *  0b01..Function = XB_IN7; Peripheral = XBAR; Direction = IN
 *  0b10..Function = MISO1; Peripheral = SPI1; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSDL_D7(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSDL_D7_SHIFT)) & SIM_GPSDL_D7_MASK)
/*! @} */

/*! @name GPSEL - GPIOE LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSEL_E4_MASK                        (0x100U)
#define SIM_GPSEL_E4_SHIFT                       (8U)
/*! E4 - Configure GPIO E4
 *  0b0..Function = PWMA_2B; Peripheral = PWMA; Direction = IO
 *  0b1..Function = XB_IN2; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSEL_E4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E4_SHIFT)) & SIM_GPSEL_E4_MASK)

#define SIM_GPSEL_E5_MASK                        (0x400U)
#define SIM_GPSEL_E5_SHIFT                       (10U)
/*! E5 - Configure GPIO E5
 *  0b0..Function = PWMA_2A; Peripheral = PWMA; Direction = IO
 *  0b1..Function = XB_IN3; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSEL_E5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E5_SHIFT)) & SIM_GPSEL_E5_MASK)

#define SIM_GPSEL_E6_MASK                        (0x3000U)
#define SIM_GPSEL_E6_SHIFT                       (12U)
/*! E6 - Configure GPIO E6
 *  0b00..Function = PWMA_3B; Peripheral = PWMA; Direction = IO
 *  0b01..Function = XB_IN4; Peripheral = XBAR; Direction = IN
 *  0b10..Function = PWMB_2B; Peripheral = PWMB; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSEL_E6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E6_SHIFT)) & SIM_GPSEL_E6_MASK)

#define SIM_GPSEL_E7_MASK                        (0xC000U)
#define SIM_GPSEL_E7_SHIFT                       (14U)
/*! E7 - Configure GPIO E7
 *  0b00..Function = PWMA_3A; Peripheral = PWMA; Direction = IO
 *  0b01..Function = XB_IN5; Peripheral = XBAR; Direction = IN
 *  0b10..Function = PWMB_2A; Peripheral = PWMB; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSEL_E7(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E7_SHIFT)) & SIM_GPSEL_E7_MASK)
/*! @} */

/*! @name GPSEH - GPIOE MSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSEH_E8_MASK                        (0x1U)
#define SIM_GPSEH_E8_SHIFT                       (0U)
/*! E8 - Configure GPIO E8
 *  0b0..Function = PWMB_2B; Peripheral = PWMB; Direction = IO
 *  0b1..Function = PWMA_FAULT0; Peripheral = PWMA; Direction = IN
 */
#define SIM_GPSEH_E8(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEH_E8_SHIFT)) & SIM_GPSEH_E8_MASK)

#define SIM_GPSEH_E9_MASK                        (0x4U)
#define SIM_GPSEH_E9_SHIFT                       (2U)
/*! E9 - Configure GPIO E9
 *  0b0..Function = PWMB_2A; Peripheral = PWMB; Direction = IO
 *  0b1..Function = PWMA_FAULT1; Peripheral = PWMA; Direction = IN
 */
#define SIM_GPSEH_E9(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEH_E9_SHIFT)) & SIM_GPSEH_E9_MASK)
/*! @} */

/*! @name GPSFL - GPIOF LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSFL_F0_MASK                        (0x3U)
#define SIM_GPSFL_F0_SHIFT                       (0U)
/*! F0 - Configure GPIO F0
 *  0b00..Function = XB_IN6; Peripheral = XBAR; Direction = IN
 *  0b01..Function = TB2; Peripheral = TMRB; Direction = IO
 *  0b10..Function = SCLK1; Peripheral = SPI1; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSFL_F0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F0_SHIFT)) & SIM_GPSFL_F0_MASK)

#define SIM_GPSFL_F1_MASK                        (0xCU)
#define SIM_GPSFL_F1_SHIFT                       (2U)
/*! F1 - Configure GPIO F1
 *  0b00..Function = CLKOUT1; Peripheral = SIM; Direction = OUT
 *  0b01..Function = XB_IN7; Peripheral = XBAR; Direction = IN
 *  0b10..Function = CMPD_O; Peripheral = HSCMPD; Direction = OUT
 *  0b11..Reserved
 */
#define SIM_GPSFL_F1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F1_SHIFT)) & SIM_GPSFL_F1_MASK)

#define SIM_GPSFL_F2_MASK                        (0x10U)
#define SIM_GPSFL_F2_SHIFT                       (4U)
/*! F2 - Configure GPIO F2
 *  0b0..Function = SCL1; Peripheral = IIC1; Direction = OD_OUT
 *  0b1..Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSFL_F2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F2_SHIFT)) & SIM_GPSFL_F2_MASK)

#define SIM_GPSFL_F3_MASK                        (0x40U)
#define SIM_GPSFL_F3_SHIFT                       (6U)
/*! F3 - Configure GPIO F3
 *  0b0..Function = SDA1; Peripheral = IIC1; Direction = OD_IO
 *  0b1..Function = XB_OUT7; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSFL_F3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F3_SHIFT)) & SIM_GPSFL_F3_MASK)

#define SIM_GPSFL_F4_MASK                        (0x100U)
#define SIM_GPSFL_F4_SHIFT                       (8U)
/*! F4 - Configure GPIO F4
 *  0b0..Function = TXD1; Peripheral = SCI1; Direction = IO
 *  0b1..Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSFL_F4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F4_SHIFT)) & SIM_GPSFL_F4_MASK)

#define SIM_GPSFL_F5_MASK                        (0x400U)
#define SIM_GPSFL_F5_SHIFT                       (10U)
/*! F5 - Configure GPIO F5
 *  0b0..Function = RXD1; Peripheral = SCI1; Direction = IN
 *  0b1..Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSFL_F5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F5_SHIFT)) & SIM_GPSFL_F5_MASK)

#define SIM_GPSFL_F6_MASK                        (0x3000U)
#define SIM_GPSFL_F6_SHIFT                       (12U)
/*! F6 - Configure GPIO F6
 *  0b00..Function = TB2; Peripheral = TMRB; Direction = IO
 *  0b01..Function = PWMA_3X; Peripheral = PWMA; Direction = IO
 *  0b10..Function = PWMB_3X; Peripheral = PWMB; Direction = IO
 *  0b11..Function = XB_IN2; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSFL_F6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F6_SHIFT)) & SIM_GPSFL_F6_MASK)

#define SIM_GPSFL_F7_MASK                        (0xC000U)
#define SIM_GPSFL_F7_SHIFT                       (14U)
/*! F7 - Configure GPIO F7
 *  0b00..Function = TB3; Peripheral = TMRB; Direction = IO
 *  0b01..Function = CMPC_O; Peripheral = HSCMPC; Direction = OUT
 *  0b10..Function = SS1_B; Peripheral = SPI1; Direction = IO
 *  0b11..Function = XB_IN3; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSFL_F7(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F7_SHIFT)) & SIM_GPSFL_F7_MASK)
/*! @} */

/*! @name GPSFH - GPIOF MSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSFH_F8_MASK                        (0x3U)
#define SIM_GPSFH_F8_SHIFT                       (0U)
/*! F8 - Configure GPIO F8
 *  0b00..Function = RXD0; Peripheral = SCI0; Direction = IN
 *  0b01..Function =TB1; Peripheral = TMRB; Direction = IO
 *  0b10..Function = CMPD_O; Peripheral = HSCMPD; Direction = OUT
 *  0b11..Reserved
 */
#define SIM_GPSFH_F8(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F8_SHIFT)) & SIM_GPSFH_F8_MASK)

#define SIM_GPSFH_F9_MASK                        (0xCU)
#define SIM_GPSFH_F9_SHIFT                       (2U)
/*! F9 - Configure GPIO F9
 *  0b00..Function = RXD2; Peripheral = SCI2; Direction = IN
 *  0b01..Function = PWMA_FAULT7; Peripheral = PWMA; Direction = IN
 *  0b10..Function = PWMB_FAULT7; Peripheral = PWMB; Direction = IN
 *  0b11..Function = XB_OUT11; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSFH_F9(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F9_SHIFT)) & SIM_GPSFH_F9_MASK)

#define SIM_GPSFH_F10_MASK                       (0x30U)
#define SIM_GPSFH_F10_SHIFT                      (4U)
/*! F10 - Configure GPIO F10
 *  0b00..Function = TXD2; Peripheral = SCI2; Direction = IO
 *  0b01..Function = PWMA_FAULT6; Peripheral = PWMA; Direction = IN
 *  0b10..Function = PWMB_FAULT6; Peripheral = PWMB; Direction = IN
 *  0b11..Function = XB_OUT10; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSFH_F10(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F10_SHIFT)) & SIM_GPSFH_F10_MASK)

#define SIM_GPSFH_F11_MASK                       (0x40U)
#define SIM_GPSFH_F11_SHIFT                      (6U)
/*! F11 - Configure GPIO F11
 *  0b0..Function = TXD0; Peripheral = SCI0; Direction = IO
 *  0b1..Function = XB_IN11; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSFH_F11(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F11_SHIFT)) & SIM_GPSFH_F11_MASK)

#define SIM_GPSFH_F12_MASK                       (0x100U)
#define SIM_GPSFH_F12_SHIFT                      (8U)
/*! F12 - Configure GPIO F12
 *  0b0..Function = MISO1; Peripheral = SPI1; Direction = IO
 *  0b1..Function = PWMB_FAULT2; Peripheral = PWMB; Direction = IN
 */
#define SIM_GPSFH_F12(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F12_SHIFT)) & SIM_GPSFH_F12_MASK)

#define SIM_GPSFH_F13_MASK                       (0x400U)
#define SIM_GPSFH_F13_SHIFT                      (10U)
/*! F13 - Configure GPIO F13
 *  0b0..Function = MOSI1; Peripheral = SPI1; Direction = IO
 *  0b1..Function = PWMB_FAULT1; Peripheral = PWMB; Direction = IN
 */
#define SIM_GPSFH_F13(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F13_SHIFT)) & SIM_GPSFH_F13_MASK)

#define SIM_GPSFH_F14_MASK                       (0x1000U)
#define SIM_GPSFH_F14_SHIFT                      (12U)
/*! F14 - Configure GPIO F14
 *  0b0..Function = SCLK1; Peripheral = SPI1; Direction = IO
 *  0b1..Function = PWMB_FAULT0; Peripheral = PWMB; Direction = IN
 */
#define SIM_GPSFH_F14(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F14_SHIFT)) & SIM_GPSFH_F14_MASK)

#define SIM_GPSFH_F15_MASK                       (0x4000U)
#define SIM_GPSFH_F15_SHIFT                      (14U)
/*! F15 - Configure GPIO F15
 *  0b0..Function = RXD0; Peripheral = SCI0; Direction = IN
 *  0b1..Function = XB_IN10; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSFH_F15(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F15_SHIFT)) & SIM_GPSFH_F15_MASK)
/*! @} */

/*! @name GPSGL - GPIOG LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSGL_G0_MASK                        (0x1U)
#define SIM_GPSGL_G0_SHIFT                       (0U)
/*! G0 - Configure GPIO G0
 *  0b0..Function = PWMB_1B; Peripheral = PWMB; Direction = IO
 *  0b1..Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSGL_G0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G0_SHIFT)) & SIM_GPSGL_G0_MASK)

#define SIM_GPSGL_G1_MASK                        (0x4U)
#define SIM_GPSGL_G1_SHIFT                       (2U)
/*! G1 - Configure GPIO G1
 *  0b0..Function = PWMB_1A; Peripheral = PWMB; Direction = IO
 *  0b1..Function = XB_OUT7; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSGL_G1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G1_SHIFT)) & SIM_GPSGL_G1_MASK)

#define SIM_GPSGL_G2_MASK                        (0x10U)
#define SIM_GPSGL_G2_SHIFT                       (4U)
/*! G2 - Configure GPIO G2
 *  0b0..Function = PWMB_0B; Peripheral = PWMB; Direction = IO
 *  0b1..Function = XB_OUT4; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSGL_G2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G2_SHIFT)) & SIM_GPSGL_G2_MASK)

#define SIM_GPSGL_G3_MASK                        (0x40U)
#define SIM_GPSGL_G3_SHIFT                       (6U)
/*! G3 - Configure GPIO G3
 *  0b0..Function = PWMB_0A; Peripheral = PWMB; Direction = IO
 *  0b1..Function = XB_OUT5; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSGL_G3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G3_SHIFT)) & SIM_GPSGL_G3_MASK)

#define SIM_GPSGL_G4_MASK                        (0x100U)
#define SIM_GPSGL_G4_SHIFT                       (8U)
/*! G4 - Configure GPIO G4
 *  0b0..Function = PWMB_3B; Peripheral = PWMB; Direction = IO
 *  0b1..Function = PWMA_FAULT2; Peripheral = PWMA; Direction = IN
 */
#define SIM_GPSGL_G4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G4_SHIFT)) & SIM_GPSGL_G4_MASK)

#define SIM_GPSGL_G5_MASK                        (0x400U)
#define SIM_GPSGL_G5_SHIFT                       (10U)
/*! G5 - Configure GPIO G5
 *  0b0..Function = PWMB_3A; Peripheral = PWMB; Direction = IO
 *  0b1..Function = PWMA_FAULT3; Peripheral = PWMA; Direction = IN
 */
#define SIM_GPSGL_G5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G5_SHIFT)) & SIM_GPSGL_G5_MASK)

#define SIM_GPSGL_G6_MASK                        (0x3000U)
#define SIM_GPSGL_G6_SHIFT                       (12U)
/*! G6 - Configure GPIO G6
 *  0b00..Function = PWMA_FAULT4; Peripheral = PWMA; Direction = IN
 *  0b01..Function = PWMB_FAULT4; Peripheral = PWMB; Direction = IN
 *  0b10..Function = TB2; Peripheral = TMRB; Direction = IO
 *  0b11..Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSGL_G6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G6_SHIFT)) & SIM_GPSGL_G6_MASK)

#define SIM_GPSGL_G7_MASK                        (0xC000U)
#define SIM_GPSGL_G7_SHIFT                       (14U)
/*! G7 - Configure GPIO G7
 *  0b00..Function = PWMA_FAULT5; Peripheral = PWMA; Direction = IN
 *  0b01..Function = PWMB_FAULT5; Peripheral = PWMB; Direction = IN
 *  0b10..Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
 *  0b11..Reserved
 */
#define SIM_GPSGL_G7(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGL_G7_SHIFT)) & SIM_GPSGL_G7_MASK)
/*! @} */

/*! @name GPSGH - GPIOG MSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSGH_G8_MASK                        (0x3U)
#define SIM_GPSGH_G8_SHIFT                       (0U)
/*! G8 - Configure GPIO G8
 *  0b00..Function = PWMB_0X; Peripheral = PWMB; Direction = IO
 *  0b01..Function = PWMA_0X; Peripheral = PWMA; Direction = IO
 *  0b10..Function = TA2; Peripheral = TMRA; Direction = IO
 *  0b11..Function = XB_OUT10; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSGH_G8(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGH_G8_SHIFT)) & SIM_GPSGH_G8_MASK)

#define SIM_GPSGH_G9_MASK                        (0xCU)
#define SIM_GPSGH_G9_SHIFT                       (2U)
/*! G9 - Configure GPIO G9
 *  0b00..Function = PWMB_1X; Peripheral = PWMB; Direction = IO
 *  0b01..Function = PWMA_1X; Peripheral = PWMA; Direction = IO
 *  0b10..Function = TA3; Peripheral = TMRA; Direction = IO
 *  0b11..Function = XB_OUT11; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSGH_G9(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSGH_G9_SHIFT)) & SIM_GPSGH_G9_MASK)

#define SIM_GPSGH_G10_MASK                       (0x30U)
#define SIM_GPSGH_G10_SHIFT                      (4U)
/*! G10 - Configure GPIO G10
 *  0b00..Function = PWMB_2X; Peripheral = PWMB; Direction = IO
 *  0b01..Function = PWMA_2X; Peripheral = PWMA; Direction = IO
 *  0b10..Function = XB_IN8; Peripheral = XBAR; Direction = IN
 *  0b11..Function = SS2_B; Peripheral = SPI2; Direction = IO
 */
#define SIM_GPSGH_G10(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSGH_G10_SHIFT)) & SIM_GPSGH_G10_MASK)

#define SIM_GPSGH_G11_MASK                       (0xC0U)
#define SIM_GPSGH_G11_SHIFT                      (6U)
/*! G11 - Configure GPIO G11
 *  0b00..Function = TB3; Peripheral = TMRB; Direction = IO
 *  0b01..Function = CLKOUT0; Peripheral = SIM; Direction = OUT
 *  0b10..Function = MOSI1; Peripheral = SPI1; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSGH_G11(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSGH_G11_SHIFT)) & SIM_GPSGH_G11_MASK)
/*! @} */

/*! @name IPS0 - Internal Peripheral Select Register 0 */
/*! @{ */

#define SIM_IPS0_PWMAF0_MASK                     (0x1U)
#define SIM_IPS0_PWMAF0_SHIFT                    (0U)
/*! PWMAF0 - Select PWMA Fault 0 Input
 *  0b0..Function = GPIOE8; Peripheral = GPIOE; Direction = IN
 *  0b1..Function = XB_OUT29; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_PWMAF0(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_PWMAF0_SHIFT)) & SIM_IPS0_PWMAF0_MASK)

#define SIM_IPS0_PWMAF1_MASK                     (0x2U)
#define SIM_IPS0_PWMAF1_SHIFT                    (1U)
/*! PWMAF1 - Select PWMA Fault 1 Input
 *  0b0..Function = GPIOE9; Peripheral = GPIOE; Direction = IN
 *  0b1..Function = XB_OUT30; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_PWMAF1(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_PWMAF1_SHIFT)) & SIM_IPS0_PWMAF1_MASK)

#define SIM_IPS0_PWMAF2_MASK                     (0x4U)
#define SIM_IPS0_PWMAF2_SHIFT                    (2U)
/*! PWMAF2 - Select PWMA Fault 2 Input
 *  0b0..Function = GPIOG4; Peripheral = GPIOG; Direction = IN
 *  0b1..Function = XB_OUT31; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_PWMAF2(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_PWMAF2_SHIFT)) & SIM_IPS0_PWMAF2_MASK)

#define SIM_IPS0_PWMAF3_MASK                     (0x8U)
#define SIM_IPS0_PWMAF3_SHIFT                    (3U)
/*! PWMAF3 - Select PWMA Fault 3 Input
 *  0b0..Function = GPIOG5; Peripheral = GPIOG; Direction = IN
 *  0b1..Function = XB_OUT32; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_PWMAF3(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_PWMAF3_SHIFT)) & SIM_IPS0_PWMAF3_MASK)

#define SIM_IPS0_PWMBF0_MASK                     (0x10U)
#define SIM_IPS0_PWMBF0_SHIFT                    (4U)
/*! PWMBF0 - Select PWMB Fault 0 Input
 *  0b0..Function = GPIOF14; Peripheral = GPIOF; Direction = IN
 *  0b1..Function = XB_OUT29; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_PWMBF0(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_PWMBF0_SHIFT)) & SIM_IPS0_PWMBF0_MASK)

#define SIM_IPS0_PWMBF1_MASK                     (0x20U)
#define SIM_IPS0_PWMBF1_SHIFT                    (5U)
/*! PWMBF1 - Select PWMB Fault 1 Input
 *  0b0..Function = GPIOF13; Peripheral = GPIOF; Direction = IN
 *  0b1..Function = XB_OUT30; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_PWMBF1(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_PWMBF1_SHIFT)) & SIM_IPS0_PWMBF1_MASK)

#define SIM_IPS0_PWMBF2_MASK                     (0x40U)
#define SIM_IPS0_PWMBF2_SHIFT                    (6U)
/*! PWMBF2 - Select PWMB Fault 2 Input
 *  0b0..Function = GPIOF12; Peripheral = GPIOF; Direction = IN
 *  0b1..Function = XB_OUT31; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_PWMBF2(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_PWMBF2_SHIFT)) & SIM_IPS0_PWMBF2_MASK)

#define SIM_IPS0_TA0_MASK                        (0x100U)
#define SIM_IPS0_TA0_SHIFT                       (8U)
/*! TA0 - Select TMRA0 Input
 *  0b0..Function = GPIOC3; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT49; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA0_SHIFT)) & SIM_IPS0_TA0_MASK)

#define SIM_IPS0_TA1_MASK                        (0x200U)
#define SIM_IPS0_TA1_SHIFT                       (9U)
/*! TA1 - Select TMRA1 Input
 *  0b0..Function = GPIOC4; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT50; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA1_SHIFT)) & SIM_IPS0_TA1_MASK)

#define SIM_IPS0_TA2_MASK                        (0x400U)
#define SIM_IPS0_TA2_SHIFT                       (10U)
/*! TA2 - Select TMRA2 Input
 *  0b0..Function = GPIOC6 or GPIOG8; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT51; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA2_SHIFT)) & SIM_IPS0_TA2_MASK)

#define SIM_IPS0_TA3_MASK                        (0x800U)
#define SIM_IPS0_TA3_SHIFT                       (11U)
/*! TA3 - Select TMRA3 Input
 *  0b0..Function = GPIOC13 or GPIOG9; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT52; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA3_SHIFT)) & SIM_IPS0_TA3_MASK)

#define SIM_IPS0_TB0_MASK                        (0x1000U)
#define SIM_IPS0_TB0_SHIFT                       (12U)
/*! TB0 - Select TMRB0 Input
 *  0b0..Function = GPIOC2; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT34; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TB0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TB0_SHIFT)) & SIM_IPS0_TB0_MASK)

#define SIM_IPS0_TB1_MASK                        (0x2000U)
#define SIM_IPS0_TB1_SHIFT                       (13U)
/*! TB1 - Select TMRB1 Input
 *  0b0..Function = GPIOF8; Peripheral = GPIOF; Direction = IN
 *  0b1..Function = XB_OUT35; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TB1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TB1_SHIFT)) & SIM_IPS0_TB1_MASK)

#define SIM_IPS0_TB2_MASK                        (0x4000U)
#define SIM_IPS0_TB2_SHIFT                       (14U)
/*! TB2 - Select TMRB2 Input
 *  0b0..Function = GPIOF6, GPIOF0, or GPIOG6; Peripheral = GPIOF; Direction = IN
 *  0b1..Function = XB_OUT36; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TB2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TB2_SHIFT)) & SIM_IPS0_TB2_MASK)

#define SIM_IPS0_TB3_MASK                        (0x8000U)
#define SIM_IPS0_TB3_SHIFT                       (15U)
/*! TB3 - Select TMRB3 Input
 *  0b0..Function = GPIOF7 or GPIOG11; Peripheral = GPIOF; Direction = IN
 *  0b1..Function = XB_OUT37; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TB3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TB3_SHIFT)) & SIM_IPS0_TB3_MASK)
/*! @} */

/*! @name MISC0 - Miscellaneous Register 0 */
/*! @{ */

#define SIM_MISC0_PIT_MSTR_MASK                  (0x1U)
#define SIM_MISC0_PIT_MSTR_SHIFT                 (0U)
/*! PIT_MSTR - Select Master Programmable Interval Timer (PIT)
 *  0b0..PIT0 is master PIT and PIT1 is slave PIT
 *  0b1..PIT1 is master PIT and PIT0 is slave PIT
 */
#define SIM_MISC0_PIT_MSTR(x)                    (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_PIT_MSTR_SHIFT)) & SIM_MISC0_PIT_MSTR_MASK)

#define SIM_MISC0_CLKINSEL_MASK                  (0x2U)
#define SIM_MISC0_CLKINSEL_SHIFT                 (1U)
/*! CLKINSEL - CLKIN Select
 *  0b0..CLKIN0 (GPIOC0 alt1) is selected as CLKIN
 *  0b1..CLKIN1 (GPIOC3 alt3) is selected as CLKIN
 */
#define SIM_MISC0_CLKINSEL(x)                    (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_CLKINSEL_SHIFT)) & SIM_MISC0_CLKINSEL_MASK)
/*! @} */

/*! @name PSWR0 - Peripheral Software Reset Register 0 */
/*! @{ */

#define SIM_PSWR0_GPIO_MASK                      (0x40U)
#define SIM_PSWR0_GPIO_SHIFT                     (6U)
/*! GPIO - GPIO Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR0_GPIO(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR0_GPIO_SHIFT)) & SIM_PSWR0_GPIO_MASK)

#define SIM_PSWR0_TB_MASK                        (0x800U)
#define SIM_PSWR0_TB_SHIFT                       (11U)
/*! TB - TMRB Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR0_TB(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PSWR0_TB_SHIFT)) & SIM_PSWR0_TB_MASK)

#define SIM_PSWR0_TA_MASK                        (0x8000U)
#define SIM_PSWR0_TA_SHIFT                       (15U)
/*! TA - TMRA Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR0_TA(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PSWR0_TA_SHIFT)) & SIM_PSWR0_TA_MASK)
/*! @} */

/*! @name PSWR1 - Peripheral Software Reset Register 1 */
/*! @{ */

#define SIM_PSWR1_FLEXCAN_MASK                   (0x1U)
#define SIM_PSWR1_FLEXCAN_SHIFT                  (0U)
/*! FLEXCAN - FlexCAN Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_FLEXCAN(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_FLEXCAN_SHIFT)) & SIM_PSWR1_FLEXCAN_MASK)

#define SIM_PSWR1_IIC1_MASK                      (0x20U)
#define SIM_PSWR1_IIC1_SHIFT                     (5U)
/*! IIC1 - IIC1 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_IIC1(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_IIC1_SHIFT)) & SIM_PSWR1_IIC1_MASK)

#define SIM_PSWR1_IIC0_MASK                      (0x40U)
#define SIM_PSWR1_IIC0_SHIFT                     (6U)
/*! IIC0 - IIC0 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_IIC0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_IIC0_SHIFT)) & SIM_PSWR1_IIC0_MASK)

#define SIM_PSWR1_QSPI2_MASK                     (0x80U)
#define SIM_PSWR1_QSPI2_SHIFT                    (7U)
/*! QSPI2 - QSPI2 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_QSPI2(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_QSPI2_SHIFT)) & SIM_PSWR1_QSPI2_MASK)

#define SIM_PSWR1_QSPI1_MASK                     (0x100U)
#define SIM_PSWR1_QSPI1_SHIFT                    (8U)
/*! QSPI1 - QSPI1 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_QSPI1(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_QSPI1_SHIFT)) & SIM_PSWR1_QSPI1_MASK)

#define SIM_PSWR1_QSPI0_MASK                     (0x200U)
#define SIM_PSWR1_QSPI0_SHIFT                    (9U)
/*! QSPI0 - QSPI0 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_QSPI0(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_QSPI0_SHIFT)) & SIM_PSWR1_QSPI0_MASK)

#define SIM_PSWR1_SCI2_MASK                      (0x400U)
#define SIM_PSWR1_SCI2_SHIFT                     (10U)
/*! SCI2 - SCI2 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_SCI2(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_SCI2_SHIFT)) & SIM_PSWR1_SCI2_MASK)

#define SIM_PSWR1_SCI1_MASK                      (0x800U)
#define SIM_PSWR1_SCI1_SHIFT                     (11U)
/*! SCI1 - SCI1 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_SCI1(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_SCI1_SHIFT)) & SIM_PSWR1_SCI1_MASK)

#define SIM_PSWR1_SCI0_MASK                      (0x1000U)
#define SIM_PSWR1_SCI0_SHIFT                     (12U)
/*! SCI0 - SCI0 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_SCI0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_SCI0_SHIFT)) & SIM_PSWR1_SCI0_MASK)

#define SIM_PSWR1_DAC_MASK                       (0x2000U)
#define SIM_PSWR1_DAC_SHIFT                      (13U)
/*! DAC - DAC Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_DAC(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_DAC_SHIFT)) & SIM_PSWR1_DAC_MASK)
/*! @} */

/*! @name PSWR2 - Peripheral Software Reset Register 2 */
/*! @{ */

#define SIM_PSWR2_PDB1_MASK                      (0x1U)
#define SIM_PSWR2_PDB1_SHIFT                     (0U)
/*! PDB1 - Programmable Delay Block Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_PDB1(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_PDB1_SHIFT)) & SIM_PSWR2_PDB1_MASK)

#define SIM_PSWR2_PDB0_MASK                      (0x2U)
#define SIM_PSWR2_PDB0_SHIFT                     (1U)
/*! PDB0 - Programmable Delay Block Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_PDB0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_PDB0_SHIFT)) & SIM_PSWR2_PDB0_MASK)

#define SIM_PSWR2_PIT1_MASK                      (0x4U)
#define SIM_PSWR2_PIT1_SHIFT                     (2U)
/*! PIT1 - Programmable Interval Timer Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_PIT1(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_PIT1_SHIFT)) & SIM_PSWR2_PIT1_MASK)

#define SIM_PSWR2_PIT0_MASK                      (0x8U)
#define SIM_PSWR2_PIT0_SHIFT                     (3U)
/*! PIT0 - Programmable Interval Timer Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_PIT0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_PIT0_SHIFT)) & SIM_PSWR2_PIT0_MASK)

#define SIM_PSWR2_QDC_MASK                       (0x10U)
#define SIM_PSWR2_QDC_SHIFT                      (4U)
/*! QDC - Quadrature Decoder Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_QDC(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_QDC_SHIFT)) & SIM_PSWR2_QDC_MASK)

#define SIM_PSWR2_CRC_MASK                       (0x20U)
#define SIM_PSWR2_CRC_SHIFT                      (5U)
/*! CRC - CRC Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_CRC(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_CRC_SHIFT)) & SIM_PSWR2_CRC_MASK)

#define SIM_PSWR2_CYCADC_MASK                    (0x80U)
#define SIM_PSWR2_CYCADC_SHIFT                   (7U)
/*! CYCADC - Cyclic ADC Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_CYCADC(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_CYCADC_SHIFT)) & SIM_PSWR2_CYCADC_MASK)

#define SIM_PSWR2_SARADC_MASK                    (0x100U)
#define SIM_PSWR2_SARADC_SHIFT                   (8U)
/*! SARADC - SAR ADC Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_SARADC(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_SARADC_SHIFT)) & SIM_PSWR2_SARADC_MASK)

#define SIM_PSWR2_CMP_MASK                       (0x1000U)
#define SIM_PSWR2_CMP_SHIFT                      (12U)
/*! CMP - CMP Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_CMP(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_CMP_SHIFT)) & SIM_PSWR2_CMP_MASK)

#define SIM_PSWR2_EWM_MASK                       (0x8000U)
#define SIM_PSWR2_EWM_SHIFT                      (15U)
/*! EWM - EWM Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR2_EWM(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PSWR2_EWM_SHIFT)) & SIM_PSWR2_EWM_MASK)
/*! @} */

/*! @name PSWR3 - Peripheral Software Reset Register 3 */
/*! @{ */

#define SIM_PSWR3_PWMB_MASK                      (0x8U)
#define SIM_PSWR3_PWMB_SHIFT                     (3U)
/*! PWMB - PWMB Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR3_PWMB(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR3_PWMB_SHIFT)) & SIM_PSWR3_PWMB_MASK)

#define SIM_PSWR3_PWMA_MASK                      (0x80U)
#define SIM_PSWR3_PWMA_SHIFT                     (7U)
/*! PWMA - PWMA Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR3_PWMA(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR3_PWMA_SHIFT)) & SIM_PSWR3_PWMA_MASK)
/*! @} */

/*! @name PWRMODE - Power Mode Register */
/*! @{ */

#define SIM_PWRMODE_VLPMODE_MASK                 (0x1U)
#define SIM_PWRMODE_VLPMODE_SHIFT                (0U)
/*! VLPMODE - VLPMODE Entry/Exit
 *  0b0..Start exit from VLPMODE
 *  0b1..Start entry to VLPMODE
 */
#define SIM_PWRMODE_VLPMODE(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_PWRMODE_VLPMODE_SHIFT)) & SIM_PWRMODE_VLPMODE_MASK)

#define SIM_PWRMODE_LPMODE_MASK                  (0x2U)
#define SIM_PWRMODE_LPMODE_SHIFT                 (1U)
/*! LPMODE - LPMODE Entry/Exit
 *  0b0..Start exit from LPMODE
 *  0b1..Start entry to LPMODE
 */
#define SIM_PWRMODE_LPMODE(x)                    (((uint16_t)(((uint16_t)(x)) << SIM_PWRMODE_LPMODE_SHIFT)) & SIM_PWRMODE_LPMODE_MASK)

#define SIM_PWRMODE_VLPMS_MASK                   (0x100U)
#define SIM_PWRMODE_VLPMS_SHIFT                  (8U)
/*! VLPMS - VLPMODE Status Indicator
 *  0b0..Not in VLPMODE
 *  0b1..In VLPMODE
 */
#define SIM_PWRMODE_VLPMS(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PWRMODE_VLPMS_SHIFT)) & SIM_PWRMODE_VLPMS_MASK)

#define SIM_PWRMODE_LPMS_MASK                    (0x200U)
#define SIM_PWRMODE_LPMS_SHIFT                   (9U)
/*! LPMS - LPMODE Status Indicator
 *  0b0..Not in LPMODE
 *  0b1..In LPMODE
 */
#define SIM_PWRMODE_LPMS(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PWRMODE_LPMS_SHIFT)) & SIM_PWRMODE_LPMS_MASK)
/*! @} */

/*! @name NVMOPT2H - Non-Volatile Memory Option Register 2 (High) */
/*! @{ */

#define SIM_NVMOPT2H_ROSC_8M_FTRIM_MASK          (0x3FFU)
#define SIM_NVMOPT2H_ROSC_8M_FTRIM_SHIFT         (0U)
/*! ROSC_8M_FTRIM - 8 MHz Relaxation Oscillator Frequency Trim */
#define SIM_NVMOPT2H_ROSC_8M_FTRIM(x)            (((uint16_t)(((uint16_t)(x)) << SIM_NVMOPT2H_ROSC_8M_FTRIM_SHIFT)) & SIM_NVMOPT2H_ROSC_8M_FTRIM_MASK)

#define SIM_NVMOPT2H_ROSC_8M_TTRIM_MASK          (0x3C00U)
#define SIM_NVMOPT2H_ROSC_8M_TTRIM_SHIFT         (10U)
/*! ROSC_8M_TTRIM - 8 MHz Relaxation Oscillator Temperature Trim */
#define SIM_NVMOPT2H_ROSC_8M_TTRIM(x)            (((uint16_t)(((uint16_t)(x)) << SIM_NVMOPT2H_ROSC_8M_TTRIM_SHIFT)) & SIM_NVMOPT2H_ROSC_8M_TTRIM_MASK)
/*! @} */

/*! @name NVMOPT2L - Non-Volatile Memory Option Register 2 (Low) */
/*! @{ */

#define SIM_NVMOPT2L_ROSC_32K_FTRIM_MASK         (0x1FFU)
#define SIM_NVMOPT2L_ROSC_32K_FTRIM_SHIFT        (0U)
/*! ROSC_32K_FTRIM - 32 kHz Relaxation Oscillator Frequency Trim */
#define SIM_NVMOPT2L_ROSC_32K_FTRIM(x)           (((uint16_t)(((uint16_t)(x)) << SIM_NVMOPT2L_ROSC_32K_FTRIM_SHIFT)) & SIM_NVMOPT2L_ROSC_32K_FTRIM_MASK)

#define SIM_NVMOPT2L_PMC_BGTRIM_MASK             (0xF000U)
#define SIM_NVMOPT2L_PMC_BGTRIM_SHIFT            (12U)
/*! PMC_BGTRIM - PMC Bandgap Trim */
#define SIM_NVMOPT2L_PMC_BGTRIM(x)               (((uint16_t)(((uint16_t)(x)) << SIM_NVMOPT2L_PMC_BGTRIM_SHIFT)) & SIM_NVMOPT2L_PMC_BGTRIM_MASK)
/*! @} */

/*! @name NVMOPT3H - Non-Volatile Memory Option Register 3 (High) */
/*! @{ */

#define SIM_NVMOPT3H_SAR_VREFBG_TRIM_MASK        (0xFFFFU)
#define SIM_NVMOPT3H_SAR_VREFBG_TRIM_SHIFT       (0U)
/*! SAR_VREFBG_TRIM - SAR ADC Bandgap Reference Capture */
#define SIM_NVMOPT3H_SAR_VREFBG_TRIM(x)          (((uint16_t)(((uint16_t)(x)) << SIM_NVMOPT3H_SAR_VREFBG_TRIM_SHIFT)) & SIM_NVMOPT3H_SAR_VREFBG_TRIM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SIM_H_ */

