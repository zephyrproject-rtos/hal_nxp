/*
** ###################################################################
**     Processors:          MC56F81643LVLC
**                          MC56F81646LVLF
**                          MC56F81648LVLH
**                          MC56F81663LVLC
**                          MC56F81666LVLF
**                          MC56F81668LVLH
**                          MC56F81743LVLC
**                          MC56F81746LMLF
**                          MC56F81746LVLF
**                          MC56F81748LMLH
**                          MC56F81748LVLH
**                          MC56F81763LVLC
**                          MC56F81766AMLFA
**                          MC56F81766LMLF
**                          MC56F81766LVLF
**                          MC56F81768AMLHA
**                          MC56F81768LMLH
**                          MC56F81768LVLH
**                          MC56F81866AMLFA
**                          MC56F81866LVLF
**                          MC56F81868AMLHA
**                          MC56F81868LVLH
**
**     Version:             rev. 1.0, 2024-10-29
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
**     - rev. 0.1 (2019-12-10)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SIM.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(PERI_SIM_H_)
#define PERI_SIM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F81643LVLC))
#include "MC56F81643_COMMON.h"
#elif (defined(CPU_MC56F81646LVLF))
#include "MC56F81646_COMMON.h"
#elif (defined(CPU_MC56F81648LVLH))
#include "MC56F81648_COMMON.h"
#elif (defined(CPU_MC56F81663LVLC))
#include "MC56F81663_COMMON.h"
#elif (defined(CPU_MC56F81666LVLF))
#include "MC56F81666_COMMON.h"
#elif (defined(CPU_MC56F81668LVLH))
#include "MC56F81668_COMMON.h"
#elif (defined(CPU_MC56F81743LVLC))
#include "MC56F81743_COMMON.h"
#elif (defined(CPU_MC56F81746LMLF) || defined(CPU_MC56F81746LVLF))
#include "MC56F81746_COMMON.h"
#elif (defined(CPU_MC56F81748LMLH) || defined(CPU_MC56F81748LVLH))
#include "MC56F81748_COMMON.h"
#elif (defined(CPU_MC56F81763LVLC))
#include "MC56F81763_COMMON.h"
#elif (defined(CPU_MC56F81766AMLFA) || defined(CPU_MC56F81766LMLF) || defined(CPU_MC56F81766LVLF))
#include "MC56F81766_COMMON.h"
#elif (defined(CPU_MC56F81768AMLHA) || defined(CPU_MC56F81768LMLH) || defined(CPU_MC56F81768LVLH))
#include "MC56F81768_COMMON.h"
#elif (defined(CPU_MC56F81866AMLFA) || defined(CPU_MC56F81866LVLF))
#include "MC56F81866_COMMON.h"
#elif (defined(CPU_MC56F81868AMLHA) || defined(CPU_MC56F81868LVLH))
#include "MC56F81868_COMMON.h"
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
    kGPIO_Peri_A0_ANA0_and_CMPA_IN3_and_OPAMPA_IN3 = 0x0000, /**< GPIO_A0, Pin */
    kGPIO_Peri_A0_CMPC_O            = 0x0001,      /**< GPIO_A0, Pin */
    kGPIO_Peri_C2_TXD0              = 0x0220,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C2_XB_OUT11          = 0x0221,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C2_XB_IN2            = 0x0222,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C2_CLKO0             = 0x0223,      /**< GPIO_C2, Pin */
    kGPIO_Peri_C3_TA0               = 0x0230,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C3_CMPA_O            = 0x0231,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C3_RXD0              = 0x0232,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C3_CLKIN1            = 0x0233,      /**< GPIO_C3, Pin */
    kGPIO_Peri_C4_TA1               = 0x0240,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C4_CMPB_O            = 0x0241,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C4_XB_IN8            = 0x0242,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C4_OPAMPA_OUT        = 0x0243,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C6_TA2               = 0x0260,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C6_XB_IN3            = 0x0261,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C6_CMP_REF           = 0x0262,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C8_RXD0              = 0x0281,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C8_XB_IN9            = 0x0282,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C9_XB_IN4            = 0x0291,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C9_TXD0              = 0x0292,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C9_XB_OUT8           = 0x0293,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C10_XB_IN5           = 0x02A1,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C10_XB_OUT9          = 0x02A3,      /**< GPIO_C10, Pin */
    kGPIO_Peri_E0_PWMA_0B           = 0x0400,      /**< GPIO_E0, Pin */
    kGPIO_Peri_E0_XB_OUT4           = 0x0403,      /**< GPIO_E0, Pin */
    kGPIO_Peri_E1_PWMA_0A           = 0x0410,      /**< GPIO_E1, Pin */
    kGPIO_Peri_E1_XB_OUT5           = 0x0413,      /**< GPIO_E1, Pin */
    kGPIO_Peri_E2_PWMA_1B           = 0x0420,      /**< GPIO_E2, Pin */
    kGPIO_Peri_E2_XB_OUT6           = 0x0423,      /**< GPIO_E2, Pin */
    kGPIO_Peri_E3_PWMA_1A           = 0x0430,      /**< GPIO_E3, Pin */
    kGPIO_Peri_E3_XB_OUT7           = 0x0433,      /**< GPIO_E3, Pin */
    kGPIO_Peri_E4_PWMA_2B           = 0x0440,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E4_XB_IN2            = 0x0441,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E4_XB_OUT8           = 0x0443,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E5_PWMA_2A           = 0x0450,      /**< GPIO_E5, Pin */
    kGPIO_Peri_E5_XB_IN3            = 0x0451,      /**< GPIO_E5, Pin */
    kGPIO_Peri_E5_XB_OUT9           = 0x0453,      /**< GPIO_E5, Pin */
    kGPIO_Peri_F2_XB_OUT6           = 0x0521,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F2_LP_SDA0           = 0x0522,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F3_XB_OUT7           = 0x0531,      /**< GPIO_F3, Pin */
    kGPIO_Peri_F3_LP_SCL0           = 0x0532,      /**< GPIO_F3, Pin */
    kGPIO_Peri_C0_EXTAL             = 0x0200,      /**< GPIO_C0, Pin */
    kGPIO_Peri_C0_CLKIN0            = 0x0201,      /**< GPIO_C0, Pin */
    kGPIO_Peri_C5_XB_IN7            = 0x0251,      /**< GPIO_C5, Pin */
    kGPIO_Peri_C7_TXD0              = 0x0271,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C7_XB_IN8            = 0x0272,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C7_XB_OUT6           = 0x0273,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C11_LP_SCLS0         = 0x02B0,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C11_TXD1             = 0x02B2,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C11_PWMA_0X          = 0x02B3,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C12_LP_SDAS0         = 0x02C0,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C12_RXD1             = 0x02C2,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C12_PWMA_1X          = 0x02C3,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C13_TA3              = 0x02D0,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C13_XB_IN6           = 0x02D1,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C13_EWM_OUT_B        = 0x02D2,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C14_LP_SDA0          = 0x02E0,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C14_XB_OUT4          = 0x02E1,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C14_PWMA_FAULT4      = 0x02E2,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C15_LP_SCL0          = 0x02F0,      /**< GPIO_C15, Pin */
    kGPIO_Peri_C15_XB_OUT5          = 0x02F1,      /**< GPIO_C15, Pin */
    kGPIO_Peri_C15_PWMA_FAULT5      = 0x02F2,      /**< GPIO_C15, Pin */
    kGPIO_Peri_F0_XB_IN6            = 0x0500,      /**< GPIO_F0, Pin */
    kGPIO_Peri_F0_OPAMPB_OUT        = 0x0503,      /**< GPIO_F0, Pin */
    kGPIO_Peri_F1_CLKO1             = 0x0510,      /**< GPIO_F1, Pin */
    kGPIO_Peri_F1_XB_IN7            = 0x0511,      /**< GPIO_F1, Pin */
    kGPIO_Peri_F1_CMPD_O            = 0x0512,      /**< GPIO_F1, Pin */
    kGPIO_Peri_E6_PWMA_3B           = 0x0460,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E6_XB_IN4            = 0x0461,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E6_XB_OUT10          = 0x0463,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E7_PWMA_3A           = 0x0470,      /**< GPIO_E7, Pin */
    kGPIO_Peri_E7_XB_IN5            = 0x0471,      /**< GPIO_E7, Pin */
    kGPIO_Peri_E7_XB_OUT11          = 0x0473,      /**< GPIO_E7, Pin */
    kGPIO_Peri_F4_TXD1              = 0x0540,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F4_XB_OUT8           = 0x0541,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F4_PWMA_0X           = 0x0542,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F4_PWMA_FAULT6       = 0x0543,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F5_RXD1              = 0x0550,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F5_XB_OUT9           = 0x0551,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F5_PWMA_1X           = 0x0552,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F5_PWMA_FAULT7       = 0x0553,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F6_PWMA_3X           = 0x0561,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F6_XB_IN2            = 0x0563,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F7_CMPC_O            = 0x0571,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F7_XB_IN3            = 0x0573,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F8_RXD0              = 0x0580,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_XB_OUT10          = 0x0581,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_CMPD_O            = 0x0582,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_PWMA_2X           = 0x0583,      /**< GPIO_F8, Pin */
    kGPIO_Peri_C6_SS0_B             = 0x0263,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C8_MISO0             = 0x0280,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C9_SCLK0             = 0x0290,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C10_MOSI0            = 0x02A0,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C10_MISO0            = 0x02A2,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C5_DACA_O            = 0x0250,      /**< GPIO_C5, Pin */
    kGPIO_Peri_C7_SS0_B             = 0x0270,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C11_LP_SCL1          = 0x02B1,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C12_LP_SDA1          = 0x02C1,      /**< GPIO_C12, Pin */
    kGPIO_Peri_E4_LP_SCL1           = 0x0442,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E5_LP_SDA1           = 0x0452,      /**< GPIO_E5, Pin */
    kGPIO_Peri_F2_LP_SCL1           = 0x0520,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F3_LP_SDA1           = 0x0530,      /**< GPIO_F3, Pin */
    kGPIO_Peri_F6_LP_SCLS1          = 0x0562,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F7_LP_SDAS1          = 0x0572,      /**< GPIO_F7, Pin */
} gpio_peripheral_mux_t;

/* @} */
#endif /* GPIO_PERIPHERAL_MUX_T_ */

#if !defined(SIM_XBAR_INPUT_ADC_TMR_INDEX_T_)
#define SIM_XBAR_INPUT_ADC_TMR_INDEX_T_
typedef enum _sim_xbar_input_adc_tmr_index
{
    kSIM_XBARIN36Index              = 0U,          /**< xbar input 36. */
    kSIM_XBARIN37Index              = 1U,          /**< xbar input 37. */
    kSIM_XBARIN38Index              = 2U,          /**< xbar input 38. */
    kSIM_XBARIN39Index              = 3U,          /**< xbar input 39. */
} sim_xbar_input_adc_tmr_index_t;
#endif /* SIM_XBAR_INPUT_ADC_TMR_INDEX_T_ */

#if !defined(SIM_XBAR_INPUT_ADC_TMR_SELECTION_T_)
#define SIM_XBAR_INPUT_ADC_TMR_SELECTION_T_
typedef enum _sim_xbar_input_adc_tmr_selection
{
    kSIM_XBARIN36TMRA0              = 0U,          /**< xbar input 36, TMRA0. */
    kSIM_XBARIN36ADCAN0limit        = 1U,          /**< xbar input 36, ADC AN0 limit. */
    kSIM_XBARIN37TMRA1              = 0U,          /**< xbar input 37, TMRA1. */
    kSIM_XBARIN37ADCAN1limit        = 1U,          /**< xbar input 37, ADC AN1 limit. */
    kSIM_XBARIN38TMRA2              = 0U,          /**< xbar input 38, TMRA2. */
    kSIM_XBARIN38ADCAN2limit        = 1U,          /**< xbar input 38, ADC AN2 limit. */
    kSIM_XBARIN39TMRA3              = 0U,          /**< xbar input 39, TMRA3. */
    kSIM_XBARIN39ADCAN3limit        = 1U,          /**< xbar input 39, ADC AN3 limit. */
} sim_xbar_input_adc_tmr_selection_t;
#endif /* SIM_XBAR_INPUT_ADC_TMR_SELECTION_T_ */

#if !defined(SIM_SWRESET_PERI_INDEX_T_)
#define SIM_SWRESET_PERI_INDEX_T_
typedef enum _sim_swReset_peri_index
{
    kSIM_SWResetGPIO                = 6U,          /**< GPIO Software Reset. */
    kSIM_SWResetTMRA                = 15U,         /**< TMRA Software Reset. */
    kSIM_SWResetLPI2C0              = 21U,         /**< LPI2C0 Software Reset. */
    kSIM_SWResetLPI2C1              = 22U,         /**< LPI2C1 Software Reset. */
    kSIM_SWResetQSPI0               = 25U,         /**< QSPI0 Software Reset. */
    kSIM_SWResetSCI1                = 27U,         /**< SCI1 Software Reset. */
    kSIM_SWResetSCI0                = 28U,         /**< SCI0 Software Reset. */
    kSIM_SWResetDAC                 = 29U,         /**< DAC Software Reset. */
    kSIM_SWResetPIT1                = 34U,         /**< PIT1 Software Reset. */
    kSIM_SWResetPIT0                = 35U,         /**< PIT0 Software Reset. */
    kSIM_SWResetQDC                 = 36U,         /**< QDC Software Reset. */
    kSIM_SWResetCRC                 = 37U,         /**< CRC Software Reset. */
    kSIM_SWResetCADC                = 39U,         /**< Cyclic ADC Software Reset. */
    kSIM_SWResetCMP                 = 44U,         /**< CMP Software Reset. */
    kSIM_SWResetEWM                 = 47U,         /**< EWM Software Reset. */
    kSIM_SWResetPWMA                = 55U,         /**< PWMA Software Reset. */
    kSIM_SWResetDMAMUX              = 57U,         /**< DMA_MUX Software Reset. */
    kSIM_SWResetOPAMPB              = 58U,         /**< OPAMPB Software Reset. */
    kSIM_SWResetOPAMPA              = 59U,         /**< OPAMPA Software Reset. */
} sim_swReset_peri_index_t;
#endif /* SIM_SWRESET_PERI_INDEX_T_ */

#if !defined(SIM_INTERNAL_PERI_INDEX_T_)
#define SIM_INTERNAL_PERI_INDEX_T_
typedef enum _sim_internal_peri_index
{
    kSIM_SCI0_RXDInputIndex         = 0U,          /**< Select SCI0_RXD Input. */
    kSIM_SCI1_RXDInputIndex         = 1U,          /**< Select SCI1_RXD Input. */
    kSIM_TMRAInput0Index            = 8U,          /**< Select TMRA Input 0. */
    kSIM_TMRAInput1Index            = 9U,          /**< Select TMRA Input 1. */
    kSIM_TMRAInput2Index            = 10U,         /**< Select TMRA Input 2. */
    kSIM_TMRAInput3Index            = 11U,         /**< Select TMRA Input 3. */
} sim_internal_peri_index_t;
#endif /* SIM_INTERNAL_PERI_INDEX_T_ */

#if !defined(SIM_INTERNAL_PERI_INPUT_T_)
#define SIM_INTERNAL_PERI_INPUT_T_
typedef enum _sim_internal_peri_input
{
    kSIM_SCI0_RXDInput_GPIOC3_GPIOC8_GPIOF8 = 0U,  /**< Select SCI0_RXD Input, GPIOC3 or GPIOC8 or GPIOF8. */
    kSIM_SCI0_RXDInput_XB_OUT36     = 1U,          /**< Select SCI0_RXD Input, XB_OUT36. */
    kSIM_SCI1_RXDInput_GPIOC12_GPIOF5 = 0U,        /**< Select SCI1_RXD Input, GPIOC12 or GPIOF5. */
    kSIM_SCI1_RXDInput_XB_OUT37     = 1U,          /**< Select SCI1_RXD Input, XB_OUT37. */
    kSIM_TMRAInput0_GPIOC3          = 0U,          /**< Select TMRA Input 0, GPIOC3. */
    kSIM_TMRAInput0_XB_OUT38        = 1U,          /**< Select TMRA Input 0, XB_OUT38. */
    kSIM_TMRAInput1_GPIOC4          = 0U,          /**< Select TMRA Input 1, GPIOC4. */
    kSIM_TMRAInput1_XB_OUT39        = 1U,          /**< Select TMRA Input 1, XB_OUT39. */
    kSIM_TMRAInput2_GPIOC6          = 0U,          /**< Select TMRA Input 2, GPIOC6 . */
    kSIM_TMRAInput2_XB_OUT40        = 1U,          /**< Select TMRA Input 2, XB_OUT40. */
    kSIM_TMRAInput3_GPIOC13         = 0U,          /**< Select TMRA Input 3, GPIOC13 . */
    kSIM_TMRAInput3_XB_OUT41        = 1U,          /**< Select TMRA Input 3, XB_OUT41. */
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
    kSIM_SCR4                       = 4U,          /**< SCR4. */
    kSIM_SCR5                       = 5U,          /**< SCR5. */
    kSIM_SCR6                       = 6U,          /**< SCR6. */
} sim_software_contrl_register_index_t;
#endif /* SIM_SOFTWARE_CONTRL_REGISTER_INDEX_T_ */

#if !defined(SIM_BOOT_OVERRIDE_MODE_T_)
#define SIM_BOOT_OVERRIDE_MODE_T_
/*!
 * @brief The enumeration of boot over ride mode, FOPT[7:6] | boot_override_mode determines the boot option,
 * the result 11b boots from ROM, while any other values boot from flash.
 */
typedef enum _sim_boot_override_mode
{
    kSIM_BootFromRomOrFlash         = 0U,          /**< Boot from ROM or Flash depending on FOPT[7:6] at next non-POR reset. */
    kSIM_BootFromRom                = 3U,          /**< Boot from ROM at next non-POR reset. */
} sim_boot_override_mode_t;
#endif /* SIM_BOOT_OVERRIDE_MODE_T_ */


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
       uint16_t RESERVED_0[4];
       uint16_t MSHID;                             /**< Most Significant Half of JTAG ID, offset: 0x6 */
       uint16_t LSHID;                             /**< Least Significant Half of JTAG ID, offset: 0x7 */
  __IO uint16_t PWR;                               /**< Power Control Register, offset: 0x8 */
       uint16_t RESERVED_1[1];
  __IO uint16_t CLKOUT;                            /**< Clock Output Select Register, offset: 0xA */
  __IO uint16_t PCR;                               /**< Peripheral Clock Rate Register, offset: 0xB */
  __IO uint16_t PCE0;                              /**< Peripheral Clock Enable Register 0, offset: 0xC */
  __IO uint16_t PCE1;                              /**< Peripheral Clock Enable Register 1, offset: 0xD */
  __IO uint16_t PCE2;                              /**< Peripheral Clock Enable Register 2, offset: 0xE */
  __IO uint16_t PCE3;                              /**< Peripheral Clock Enable Register 3, offset: 0xF */
  __IO uint16_t SD0;                               /**< Peripheral Clock STOP Disable Register 0, offset: 0x10 */
  __IO uint16_t SD1;                               /**< Peripheral Clock STOP Disable Register 1, offset: 0x11 */
  __IO uint16_t SD2;                               /**< Peripheral Clock STOP Disable Register 2, offset: 0x12 */
  __IO uint16_t SD3;                               /**< Peripheral Clock STOP Disable Register 3, offset: 0x13 */
  __IO uint16_t IOSAHI;                            /**< I/O Short Address Location Register, offset: 0x14 */
  __IO uint16_t IOSALO;                            /**< I/O Short Address Location Register, offset: 0x15 */
  __IO uint16_t PROT;                              /**< Protection Register, offset: 0x16 */
  __IO uint16_t GPSAL;                             /**< GPIOA LSBs Peripheral Select Register, offset: 0x17 */
       uint16_t GPSBL;                             /**< GPIOB LSBs Peripheral Select Register, offset: 0x18 */
  __IO uint16_t GPSCL;                             /**< GPIOC LSBs Peripheral Select Register, offset: 0x19 */
  __IO uint16_t GPSCH;                             /**< GPIOC MSBs Peripheral Select Register, offset: 0x1A */
       uint16_t RESERVED_2[1];
  __IO uint16_t GPSEL;                             /**< GPIOE LSBs Peripheral Select Register, offset: 0x1C */
       uint16_t RESERVED_3[1];
  __IO uint16_t GPSFL;                             /**< GPIOF LSBs Peripheral Select Register, offset: 0x1E */
  __IO uint16_t GPSFH;                             /**< GPIOF MSBs Peripheral Select Register, offset: 0x1F */
       uint16_t RESERVED_4[2];
  __IO uint16_t IPS0;                              /**< Internal Peripheral Select Register 0, offset: 0x22 */
  __IO uint16_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x23 */
  __IO uint16_t PSWR0;                             /**< Peripheral Software Reset Register 0, offset: 0x24 */
  __IO uint16_t PSWR1;                             /**< Peripheral Software Reset Register 1, offset: 0x25 */
  __IO uint16_t PSWR2;                             /**< Peripheral Software Reset Register 2, offset: 0x26 */
  __IO uint16_t PSWR3;                             /**< Peripheral Software Reset Register 3, offset: 0x27 */
  __IO uint16_t PWRMODE;                           /**< Power Mode Register, offset: 0x28 */
       uint16_t RESERVED_5[28];
  __IO uint16_t SCR0;                              /**< Software Control Register, offset: 0x45 */
  __IO uint16_t SCR1;                              /**< Software Control Register, offset: 0x46 */
  __IO uint16_t SCR2;                              /**< Software Control Register, offset: 0x47 */
  __IO uint16_t SCR3;                              /**< Software Control Register, offset: 0x48 */
  __IO uint16_t SCR4;                              /**< Software Control Register, offset: 0x49 */
  __IO uint16_t SCR5;                              /**< Software Control Register, offset: 0x4A */
  __IO uint16_t SCR6;                              /**< Software Control Register, offset: 0x4B */
       uint16_t RESERVED_6[1];
  __IO uint16_t ADC_TMR_SEL;                       /**< ADC and TMR Select Register, offset: 0x4D */
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
 *  0b100..DMA module is disabled and the DMAEBL field is write protected until the next reset.
 *  0b101..DMA module is enabled in run mode only and the DMAEBL field is write protected until the next reset.
 *  0b110..DMA module is enabled in run and wait modes only and the DMAEBL field is write protected until the next reset.
 *  0b111..DMA module is enabled in all low power modes and the DMAEBL field is write protected until the next reset.
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

#define SIM_RSTAT_COP_WIN_MASK                   (0x100U)
#define SIM_RSTAT_COP_WIN_SHIFT                  (8U)
/*! COP_WIN - COP Window Time-out Reset */
#define SIM_RSTAT_COP_WIN(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_COP_WIN_SHIFT)) & SIM_RSTAT_COP_WIN_MASK)

#define SIM_RSTAT_BOOT_MODE_STATUS_MASK          (0x600U)
#define SIM_RSTAT_BOOT_MODE_STATUS_SHIFT         (9U)
/*! BOOT_MODE_STATUS - Boot mode. */
#define SIM_RSTAT_BOOT_MODE_STATUS(x)            (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_BOOT_MODE_STATUS_SHIFT)) & SIM_RSTAT_BOOT_MODE_STATUS_MASK)
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
 *  0b000..Function = SYS_CLK continuous after reset
 *  0b001..Function = MSTR_2X_CLK continuous after reset
 *  0b010..Function = DIV2_BUS_CLK (BUS_CLK/2, used for flash memory module) continuous after reset
 *  0b011..Function = MSTR_OSC (master clock) continuous after reset
 *  0b100..Function = FIRC8M (8 MHz / 2 MHz internal reference clock )
 *  0b101..Function = Frosc200K (200 kHz relaxation oscillator clock )
 *  0b110..Reserved. For normal operation, do not write 11x.
 *  0b111..Reserved. For normal operation, do not write 11x.
 */
#define SIM_CLKOUT_CLKOSEL0(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKOSEL0_SHIFT)) & SIM_CLKOUT_CLKOSEL0_MASK)

#define SIM_CLKOUT_CLKDIS0_MASK                  (0x20U)
#define SIM_CLKOUT_CLKDIS0_SHIFT                 (5U)
/*! CLKDIS0 - Disable for CLKOUT0
 *  0b0..CLKOUT0 output is enabled and outputs the signal indicated by CLKOSEL0
 *  0b1..CLKOUT0 is disabled
 */
#define SIM_CLKOUT_CLKDIS0(x)                    (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKDIS0_SHIFT)) & SIM_CLKOUT_CLKDIS0_MASK)

#define SIM_CLKOUT_CLKOSEL1_MASK                 (0x380U)
#define SIM_CLKOUT_CLKOSEL1_SHIFT                (7U)
/*! CLKOSEL1 - CLKOUT1 Select
 *  0b000..Function = SYS_CLK continuous after reset
 *  0b001..Function = MSTR_2X_CLK continuous after reset
 *  0b010..Function = DIV2_BUS_CLK (BUS_CLK/2, used for flash memory module) continuous after reset
 *  0b011..Function = MSTR_OSC (master clock) continuous after reset
 *  0b100..Function = FIRC8M (8 MHz / 2 MHz internal reference clock )
 *  0b101..Function = Frosc200K (200 kHz relaxation oscillator clock )
 *  0b110..Reserved. For normal operation, do not write 11x.
 *  0b111..Reserved. For normal operation, do not write 11x.
 */
#define SIM_CLKOUT_CLKOSEL1(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_CLKOUT_CLKOSEL1_SHIFT)) & SIM_CLKOUT_CLKOSEL1_MASK)

#define SIM_CLKOUT_CLKDIS1_MASK                  (0x1000U)
#define SIM_CLKOUT_CLKDIS1_SHIFT                 (12U)
/*! CLKDIS1 - Disable for CLKOUT1
 *  0b0..CLKOUT1 output is enabled and outputs the signal indicated by CLKOSEL1
 *  0b1..CLKOUT1 is disabled
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

#define SIM_PCR_QDC_CR_MASK                      (0x80U)
#define SIM_PCR_QDC_CR_SHIFT                     (7U)
/*! QDC_CR - QDC Clock Rate
 *  0b0..QDC clock rate equals bus clock rate (default)
 *  0b1..QDC clock rate equals 2X bus clock rate
 */
#define SIM_PCR_QDC_CR(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCR_QDC_CR_SHIFT)) & SIM_PCR_QDC_CR_MASK)

#define SIM_PCR_LPI2C0_CR_MASK                   (0x100U)
#define SIM_PCR_LPI2C0_CR_SHIFT                  (8U)
/*! LPI2C0_CR - LPI2C0 Clock Rate
 *  0b0..LPI2C0 clock rate equals bus clock rate (default)
 *  0b1..LPI2C0 clock rate equals 2X bus clock rate
 */
#define SIM_PCR_LPI2C0_CR(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PCR_LPI2C0_CR_SHIFT)) & SIM_PCR_LPI2C0_CR_MASK)

#define SIM_PCR_LPI2C1_CR_MASK                   (0x200U)
#define SIM_PCR_LPI2C1_CR_SHIFT                  (9U)
/*! LPI2C1_CR - LPI2C1 Clock Rate
 *  0b0..LPI2C1 clock rate equals bus clock rate (default)
 *  0b1..LPI2C1 clock rate equals 2X bus clock rate
 */
#define SIM_PCR_LPI2C1_CR(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PCR_LPI2C1_CR_SHIFT)) & SIM_PCR_LPI2C1_CR_MASK)

#define SIM_PCR_PWM_CR_MASK                      (0x400U)
#define SIM_PCR_PWM_CR_SHIFT                     (10U)
/*! PWM_CR - PWM Clock Rate
 *  0b0..PWM clock rate equals bus clock rate
 *  0b1..PWM clock rate equals 2X bus clock rate (default)
 */
#define SIM_PCR_PWM_CR(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCR_PWM_CR_SHIFT)) & SIM_PCR_PWM_CR_MASK)

#define SIM_PCR_TMR_CR_MASK                      (0x800U)
#define SIM_PCR_TMR_CR_SHIFT                     (11U)
/*! TMR_CR - TMR Clock Rate
 *  0b0..TMR clock rate equals bus clock rate (default)
 *  0b1..TMR clock rate equals 2X bus clock rate
 */
#define SIM_PCR_TMR_CR(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCR_TMR_CR_SHIFT)) & SIM_PCR_TMR_CR_MASK)

#define SIM_PCR_SCI1_CR_MASK                     (0x1000U)
#define SIM_PCR_SCI1_CR_SHIFT                    (12U)
/*! SCI1_CR - SCI1 Clock Rate
 *  0b0..SCI1 clock rate equals bus clock rate (default)
 *  0b1..SCI1 clock rate equals 2X bus clock rate
 */
#define SIM_PCR_SCI1_CR(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCR_SCI1_CR_SHIFT)) & SIM_PCR_SCI1_CR_MASK)

#define SIM_PCR_SCI0_CR_MASK                     (0x2000U)
#define SIM_PCR_SCI0_CR_SHIFT                    (13U)
/*! SCI0_CR - SCI0 Clock Rate
 *  0b0..SCI0 clock rate equals bus clock rate (default)
 *  0b1..SCI0 clock rate equals 2X bus clock rate
 */
#define SIM_PCR_SCI0_CR(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCR_SCI0_CR_SHIFT)) & SIM_PCR_SCI0_CR_MASK)
/*! @} */

/*! @name PCE0 - Peripheral Clock Enable Register 0 */
/*! @{ */

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

#define SIM_PCE1_LPI2C0_MASK                     (0x20U)
#define SIM_PCE1_LPI2C0_SHIFT                    (5U)
/*! LPI2C0 - LPI2C0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_LPI2C0(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_LPI2C0_SHIFT)) & SIM_PCE1_LPI2C0_MASK)

#define SIM_PCE1_LPI2C1_MASK                     (0x40U)
#define SIM_PCE1_LPI2C1_SHIFT                    (6U)
/*! LPI2C1 - LPI2C1 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_LPI2C1(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_LPI2C1_SHIFT)) & SIM_PCE1_LPI2C1_MASK)

#define SIM_PCE1_QSPI0_MASK                      (0x200U)
#define SIM_PCE1_QSPI0_SHIFT                     (9U)
/*! QSPI0 - QSPI0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_QSPI0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_QSPI0_SHIFT)) & SIM_PCE1_QSPI0_MASK)

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
/*! QDC - QDC IPBus Clock Enable
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

#define SIM_PCE2_CMPD_MASK                       (0x200U)
#define SIM_PCE2_CMPD_SHIFT                      (9U)
/*! CMPD - CMPD IPBus Clock Enable (enables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPD(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPD_SHIFT)) & SIM_PCE2_CMPD_MASK)

#define SIM_PCE2_CMPC_MASK                       (0x400U)
#define SIM_PCE2_CMPC_SHIFT                      (10U)
/*! CMPC - CMPC IPBus Clock Enable (enables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPC(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPC_SHIFT)) & SIM_PCE2_CMPC_MASK)

#define SIM_PCE2_CMPB_MASK                       (0x800U)
#define SIM_PCE2_CMPB_SHIFT                      (11U)
/*! CMPB - CMPB IPBus Clock Enable (enables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPB(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPB_SHIFT)) & SIM_PCE2_CMPB_MASK)

#define SIM_PCE2_CMPA_MASK                       (0x1000U)
#define SIM_PCE2_CMPA_SHIFT                      (12U)
/*! CMPA - CMPA IPBus Clock Enable (enables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE2_CMPA(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE2_CMPA_SHIFT)) & SIM_PCE2_CMPA_MASK)
/*! @} */

/*! @name PCE3 - Peripheral Clock Enable Register 3 */
/*! @{ */

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

#define SIM_PCE3_ROM_MASK                        (0x200U)
#define SIM_PCE3_ROM_SHIFT                       (9U)
/*! ROM - ROM IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_ROM(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_ROM_SHIFT)) & SIM_PCE3_ROM_MASK)

#define SIM_PCE3_OPAMPB_MASK                     (0x400U)
#define SIM_PCE3_OPAMPB_SHIFT                    (10U)
/*! OPAMPB - OPAMPB IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_OPAMPB(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_OPAMPB_SHIFT)) & SIM_PCE3_OPAMPB_MASK)

#define SIM_PCE3_OPAMPA_MASK                     (0x800U)
#define SIM_PCE3_OPAMPA_SHIFT                    (11U)
/*! OPAMPA - OPAMPA IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE3_OPAMPA(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCE3_OPAMPA_SHIFT)) & SIM_PCE3_OPAMPA_MASK)
/*! @} */

/*! @name SD0 - Peripheral Clock STOP Disable Register 0 */
/*! @{ */

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

#define SIM_SD1_LPI2C0_MASK                      (0x20U)
#define SIM_SD1_LPI2C0_SHIFT                     (5U)
/*! LPI2C0 - LPI2C0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode, but the LPI2C0 module will not enter stop mode.
 */
#define SIM_SD1_LPI2C0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_SD1_LPI2C0_SHIFT)) & SIM_SD1_LPI2C0_MASK)

#define SIM_SD1_LPI2C1_MASK                      (0x40U)
#define SIM_SD1_LPI2C1_SHIFT                     (6U)
/*! LPI2C1 - LPI2C1 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode, but the LPI2C1 module will not enter stop mode.
 */
#define SIM_SD1_LPI2C1(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_SD1_LPI2C1_SHIFT)) & SIM_SD1_LPI2C1_MASK)

#define SIM_SD1_QSPI0_MASK                       (0x200U)
#define SIM_SD1_QSPI0_SHIFT                      (9U)
/*! QSPI0 - QSPI0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_QSPI0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD1_QSPI0_SHIFT)) & SIM_SD1_QSPI0_MASK)

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
/*! QDC - QDC IPBus STOP Disable
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

#define SIM_SD2_CMPD_MASK                        (0x200U)
#define SIM_SD2_CMPD_SHIFT                       (9U)
/*! CMPD - CMPD IPBus STOP Disable (disables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPD(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPD_SHIFT)) & SIM_SD2_CMPD_MASK)

#define SIM_SD2_CMPC_MASK                        (0x400U)
#define SIM_SD2_CMPC_SHIFT                       (10U)
/*! CMPC - CMPC IPBus STOP Disable (disables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPC(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPC_SHIFT)) & SIM_SD2_CMPC_MASK)

#define SIM_SD2_CMPB_MASK                        (0x800U)
#define SIM_SD2_CMPB_SHIFT                       (11U)
/*! CMPB - CMPB IPBus STOP Disable (disables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPB(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPB_SHIFT)) & SIM_SD2_CMPB_MASK)

#define SIM_SD2_CMPA_MASK                        (0x1000U)
#define SIM_SD2_CMPA_SHIFT                       (12U)
/*! CMPA - CMPA IPBus STOP Disable (disables both CMP and 8-bit reference DAC)
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD2_CMPA(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD2_CMPA_SHIFT)) & SIM_SD2_CMPA_MASK)
/*! @} */

/*! @name SD3 - Peripheral Clock STOP Disable Register 3 */
/*! @{ */

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

#define SIM_SD3_ROM_MASK                         (0x200U)
#define SIM_SD3_ROM_SHIFT                        (9U)
/*! ROM - ROM IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_ROM(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_SD3_ROM_SHIFT)) & SIM_SD3_ROM_MASK)

#define SIM_SD3_OPAMPB_MASK                      (0x400U)
#define SIM_SD3_OPAMPB_SHIFT                     (10U)
/*! OPAMPB - OPAMPB IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_OPAMPB(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_SD3_OPAMPB_SHIFT)) & SIM_SD3_OPAMPB_MASK)

#define SIM_SD3_OPAMPA_MASK                      (0x800U)
#define SIM_SD3_OPAMPA_SHIFT                     (11U)
/*! OPAMPA - OPAMPA IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD3_OPAMPA(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_SD3_OPAMPA_SHIFT)) & SIM_SD3_OPAMPA_MASK)
/*! @} */

/*! @name IOSAHI - I/O Short Address Location Register */
/*! @{ */

#define SIM_IOSAHI_ISAL23_22_MASK                (0x3U)
#define SIM_IOSAHI_ISAL23_22_SHIFT               (0U)
/*! ISAL23_22 - Bits 23:22 of the address */
#define SIM_IOSAHI_ISAL23_22(x)                  (((uint16_t)(((uint16_t)(x)) << SIM_IOSAHI_ISAL23_22_SHIFT)) & SIM_IOSAHI_ISAL23_22_MASK)
/*! @} */

/*! @name IOSALO - I/O Short Address Location Register */
/*! @{ */

#define SIM_IOSALO_ISAL21_6_MASK                 (0xFFFFU)
#define SIM_IOSALO_ISAL21_6_SHIFT                (0U)
/*! ISAL21_6 - Bits 21:6 of the address */
#define SIM_IOSALO_ISAL21_6(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_IOSALO_ISAL21_6_SHIFT)) & SIM_IOSALO_ISAL21_6_MASK)
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
 *  0b0..Function = ANA0/CMPA_IN3/OPAMPA_IN3; Peripheral = ADC/CMPA/OPAMPA; Direction = IN
 *  0b1..Function = CMPC_O; Peripheral = CMPC; Direction = OUT
 */
#define SIM_GPSAL_A0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSAL_A0_SHIFT)) & SIM_GPSAL_A0_MASK)
/*! @} */

/*! @name GPSCL - GPIOC LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSCL_C0_MASK                        (0x1U)
#define SIM_GPSCL_C0_SHIFT                       (0U)
/*! C0 - Configure GPIO C0
 *  0b0..Function = EXTAL; Peripheral = OSC; Direction = IN
 *  0b1..Function = CLKIN0; Peripheral = OCCS; Direction = IN
 */
#define SIM_GPSCL_C0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C0_SHIFT)) & SIM_GPSCL_C0_MASK)

#define SIM_GPSCL_C2_MASK                        (0x30U)
#define SIM_GPSCL_C2_SHIFT                       (4U)
/*! C2 - Configure GPIO C2
 *  0b00..Function = TXD0; Peripheral = SCI0; Direction = IO
 *  0b01..Function = XB_OUT11; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = XB_IN2; Peripheral = XBAR; Direction = IN
 *  0b11..Function = CLKOUT0; Peripheral = OCCS; Direction = OUT
 */
#define SIM_GPSCL_C2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C2_SHIFT)) & SIM_GPSCL_C2_MASK)

#define SIM_GPSCL_C3_MASK                        (0xC0U)
#define SIM_GPSCL_C3_SHIFT                       (6U)
/*! C3
 *  0b00..Function = TA0; Peripheral = TMRA; Direction = IO
 *  0b01..Function = CMPA_O; Peripheral = CMPA; Direction = OUT
 *  0b10..Function = RXD0; Peripheral = SCI0; Direction = IN
 *  0b11..Function = CLKIN1; Peripheral = OCCS; Direction = IN
 */
#define SIM_GPSCL_C3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C3_SHIFT)) & SIM_GPSCL_C3_MASK)

#define SIM_GPSCL_C4_MASK                        (0x300U)
#define SIM_GPSCL_C4_SHIFT                       (8U)
/*! C4 - Configure GPIO C4
 *  0b00..Function = TA1; Peripheral = TMRA; Direction = IO
 *  0b01..Function = CMPB_O; Peripheral = CMPB; Direction = OUT
 *  0b10..Function = XB_IN8; Peripheral = XBAR; Direction = IN
 *  0b11..Function = OPAMPA_OUT; Peripheral = OPAMPA; Direction = OUT
 */
#define SIM_GPSCL_C4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C4_SHIFT)) & SIM_GPSCL_C4_MASK)

#define SIM_GPSCL_C5_MASK                        (0x400U)
#define SIM_GPSCL_C5_SHIFT                       (10U)
/*! C5 - Configure GPIO C5
 *  0b0..Function = DACA_O; Peripheral = DAC; Direction = OUT
 *  0b1..Function = XB_IN7; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSCL_C5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C5_SHIFT)) & SIM_GPSCL_C5_MASK)

#define SIM_GPSCL_C6_MASK                        (0x3000U)
#define SIM_GPSCL_C6_SHIFT                       (12U)
/*! C6 - Configure GPIO C6
 *  0b00..Function = TA2; Peripheral = TMRA; Direction = IO
 *  0b01..Function = XB_IN3; Peripheral = XBAR; Direction = IN
 *  0b10..Function = CMP_REF; Peripheral = CMPx; Direction = IN
 *  0b11..Function = SS0_B; Peripheral = SPI0; Direction = IO
 */
#define SIM_GPSCL_C6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C6_SHIFT)) & SIM_GPSCL_C6_MASK)

#define SIM_GPSCL_C7_MASK                        (0xC000U)
#define SIM_GPSCL_C7_SHIFT                       (14U)
/*! C7 - Configure GPIO C7
 *  0b00..Function = SS0_B; Peripheral = SPI0; Direction = IO
 *  0b01..Function = TXD0; Peripheral = SCI0; Direction = OUT
 *  0b10..Function = XB_IN8; Peripheral = XBAR; Direction = IN
 *  0b11..Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
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

#define SIM_GPSCH_C9_MASK                        (0xCU)
#define SIM_GPSCH_C9_SHIFT                       (2U)
/*! C9 - Configure GPIO C9
 *  0b00..Function = SCLK0; Peripheral = SPI0; Direction = IO
 *  0b01..Function = XB_IN4; Peripheral = XBAR; Direction = IN
 *  0b10..Function = TXD0; Peripheral = SCI0; Direction = OUT
 *  0b11..Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSCH_C9(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C9_SHIFT)) & SIM_GPSCH_C9_MASK)

#define SIM_GPSCH_C10_MASK                       (0x30U)
#define SIM_GPSCH_C10_SHIFT                      (4U)
/*! C10 - Configure GPIO C10
 *  0b00..Function = MOSI0; Peripheral = SPI0; Direction = IO
 *  0b01..Function = XB_IN5; Peripheral = XBAR; Direction = IN
 *  0b10..Function = MISO0; Peripheral = SPI0; Direction = IO
 *  0b11..Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSCH_C10(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C10_SHIFT)) & SIM_GPSCH_C10_MASK)

#define SIM_GPSCH_C11_MASK                       (0xC0U)
#define SIM_GPSCH_C11_SHIFT                      (6U)
/*! C11 - Configure GPIO C11
 *  0b00..Function = SCLS0; Peripheral = LPI2C0; Direction = IO
 *  0b01..Function = SCL1; Peripheral = LPI2C1; Direction = IO
 *  0b10..Function = TXD1; Peripheral = SCI1; Direction = IO
 *  0b11..Function = PWMA_0X; Peripheral = PWMA; Direction = IO
 */
#define SIM_GPSCH_C11(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C11_SHIFT)) & SIM_GPSCH_C11_MASK)

#define SIM_GPSCH_C12_MASK                       (0x300U)
#define SIM_GPSCH_C12_SHIFT                      (8U)
/*! C12 - Configure GPIO C12
 *  0b00..Function = SDAS0; Peripheral = LPI2C0; Direction = IO
 *  0b01..Function = SDA1; Peripheral = LPI2C1; Direction = IO
 *  0b10..Function = RXD1; Peripheral = SCI1; Direction = IN
 *  0b11..Function = PWMA_1X; Peripheral = PWMA; Direction = IO
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

#define SIM_GPSCH_C14_MASK                       (0x3000U)
#define SIM_GPSCH_C14_SHIFT                      (12U)
/*! C14 - Configure GPIO C14
 *  0b00..Function = SDA0; Peripheral = LPI2C0; Direction = IO
 *  0b01..Function = XB_OUT4; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWMA_FAULT4; Peripheral = PWMA; Direction = IN
 *  0b11..reserved
 */
#define SIM_GPSCH_C14(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C14_SHIFT)) & SIM_GPSCH_C14_MASK)

#define SIM_GPSCH_C15_MASK                       (0xC000U)
#define SIM_GPSCH_C15_SHIFT                      (14U)
/*! C15 - Configure GPIO C15
 *  0b00..Function = SCL0; Peripheral = LPI2C0; Direction = IO
 *  0b01..Function = XB_OUT5; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWMA_FAULT5; Peripheral = PWMA; Direction = IN
 *  0b11..reserved
 */
#define SIM_GPSCH_C15(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C15_SHIFT)) & SIM_GPSCH_C15_MASK)
/*! @} */

/*! @name GPSEL - GPIOE LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSEL_E0_MASK                        (0x3U)
#define SIM_GPSEL_E0_SHIFT                       (0U)
/*! E0 - Configure GPIO E0
 *  0b00..Function = PWMA_0B; Peripheral = PWMA; Direction = IO
 *  0b01..reserved
 *  0b10..reserved
 *  0b11..Function = XB_OUT4; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E0_SHIFT)) & SIM_GPSEL_E0_MASK)

#define SIM_GPSEL_E1_MASK                        (0xCU)
#define SIM_GPSEL_E1_SHIFT                       (2U)
/*! E1 - Configure GPIO E1
 *  0b00..Function = PWMA_0A; Peripheral = PWMA; Direction = IO
 *  0b01..reserved
 *  0b10..reserved
 *  0b11..Function = XB_OUT5; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E1_SHIFT)) & SIM_GPSEL_E1_MASK)

#define SIM_GPSEL_E2_MASK                        (0x30U)
#define SIM_GPSEL_E2_SHIFT                       (4U)
/*! E2 - Configure GPIO E2
 *  0b00..Function = PWMA_1B; Peripheral = PWMA; Direction = IO
 *  0b01..reserved
 *  0b10..reserved
 *  0b11..Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E2_SHIFT)) & SIM_GPSEL_E2_MASK)

#define SIM_GPSEL_E3_MASK                        (0xC0U)
#define SIM_GPSEL_E3_SHIFT                       (6U)
/*! E3 - Configure GPIO E3
 *  0b00..Function = PWMA_1A; Peripheral = PWMA; Direction = IO
 *  0b01..reserved
 *  0b10..reserved
 *  0b11..Function = XB_OUT7; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E3_SHIFT)) & SIM_GPSEL_E3_MASK)

#define SIM_GPSEL_E4_MASK                        (0x300U)
#define SIM_GPSEL_E4_SHIFT                       (8U)
/*! E4 - Configure GPIO E4
 *  0b00..Function = PWMA_2B; Peripheral = PWMA; Direction = IO
 *  0b01..Function = XB_IN2; Peripheral = XBAR; Direction = IN
 *  0b10..Function = SCL1; Peripheral = LPI2C1; Direction = IO
 *  0b11..Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E4_SHIFT)) & SIM_GPSEL_E4_MASK)

#define SIM_GPSEL_E5_MASK                        (0xC00U)
#define SIM_GPSEL_E5_SHIFT                       (10U)
/*! E5 - Configure GPIO E5
 *  0b00..Function = PWMA_2A; Peripheral = PWMA; Direction = IO
 *  0b01..Function = XB_IN3; Peripheral = XBAR; Direction = IN
 *  0b10..Function = SDA1; Peripheral = LPI2C1; Direction = IO
 *  0b11..Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E5_SHIFT)) & SIM_GPSEL_E5_MASK)

#define SIM_GPSEL_E6_MASK                        (0x3000U)
#define SIM_GPSEL_E6_SHIFT                       (12U)
/*! E6 - Configure GPIO E6
 *  0b00..Function = PWMA_3B; Peripheral = PWMA; Direction = IO
 *  0b01..Function = XB_IN4; Peripheral = XBAR; Direction = IN
 *  0b10..Reserved
 *  0b11..Function = XB_OUT10; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E6_SHIFT)) & SIM_GPSEL_E6_MASK)

#define SIM_GPSEL_E7_MASK                        (0xC000U)
#define SIM_GPSEL_E7_SHIFT                       (14U)
/*! E7 - Configure GPIO E7
 *  0b00..Function = PWMA_3A; Peripheral = PWMA; Direction = IO
 *  0b01..Function = XB_IN5; Peripheral = XBAR; Direction = IN
 *  0b10..Reserved
 *  0b11..Function = XB_OUT11; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSEL_E7(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E7_SHIFT)) & SIM_GPSEL_E7_MASK)
/*! @} */

/*! @name GPSFL - GPIOF LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSFL_F0_MASK                        (0x3U)
#define SIM_GPSFL_F0_SHIFT                       (0U)
/*! F0 - Configure GPIO F0
 *  0b00..Function = XB_IN6; Peripheral = XBAR; Direction = IN
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Function = OPAMPB_OUT; Peripheral = OPAMP B; Direction = OUT
 */
#define SIM_GPSFL_F0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F0_SHIFT)) & SIM_GPSFL_F0_MASK)

#define SIM_GPSFL_F1_MASK                        (0xCU)
#define SIM_GPSFL_F1_SHIFT                       (2U)
/*! F1 - Configure GPIO F1
 *  0b00..Function = CLKOUT1; Peripheral = OCCS; Direction = OUT
 *  0b01..Function = XB_IN7; Peripheral = XBAR; Direction = IN
 *  0b10..Function = CMPD_O; Peripheral = CMP D; Direction = OUT
 *  0b11..Reserved
 */
#define SIM_GPSFL_F1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F1_SHIFT)) & SIM_GPSFL_F1_MASK)

#define SIM_GPSFL_F2_MASK                        (0x30U)
#define SIM_GPSFL_F2_SHIFT                       (4U)
/*! F2 - Configure GPIO F2
 *  0b00..Function = SCL1; Peripheral = LPI2C1; Direction = IO
 *  0b01..Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = SDA0; Peripheral = LPI2C0; Direction = IO
 *  0b11..reserved
 */
#define SIM_GPSFL_F2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F2_SHIFT)) & SIM_GPSFL_F2_MASK)

#define SIM_GPSFL_F3_MASK                        (0xC0U)
#define SIM_GPSFL_F3_SHIFT                       (6U)
/*! F3 - Configure GPIO F3
 *  0b00..Function = SDA1; Peripheral = LPI2C1; Direction = IO
 *  0b01..Function = XB_OUT7; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = SCL0; Peripheral = LPI2C0; Direction = IO
 *  0b11..reserved
 */
#define SIM_GPSFL_F3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F3_SHIFT)) & SIM_GPSFL_F3_MASK)

#define SIM_GPSFL_F4_MASK                        (0x300U)
#define SIM_GPSFL_F4_SHIFT                       (8U)
/*! F4 - Configure GPIO F4
 *  0b00..Function = TXD1; Peripheral = SCI1; Direction = IO
 *  0b01..Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWMA_0X; Peripheral = PWMA; Direction = IO
 *  0b11..Function = PWMA_FAULT6; Peripheral = PWMA; Direction = IN
 */
#define SIM_GPSFL_F4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F4_SHIFT)) & SIM_GPSFL_F4_MASK)

#define SIM_GPSFL_F5_MASK                        (0xC00U)
#define SIM_GPSFL_F5_SHIFT                       (10U)
/*! F5 - Configure GPIO F5
 *  0b00..Function = RXD1; Peripheral = SCI1; Direction = IN
 *  0b01..Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWMA_1X; Peripheral = PWMA; Direction = IO
 *  0b11..Function = PWMA_FAULT7; Peripheral = PWMA; Direction = IN
 */
#define SIM_GPSFL_F5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F5_SHIFT)) & SIM_GPSFL_F5_MASK)

#define SIM_GPSFL_F6_MASK                        (0x3000U)
#define SIM_GPSFL_F6_SHIFT                       (12U)
/*! F6 - Configure GPIO F6
 *  0b00..Reserved
 *  0b01..Function = PWMA_3X; Peripheral = PWMA; Direction = IO
 *  0b10..Function = SCLS1; Peripheral = LPI2C1; Direction = IO
 *  0b11..Function = XB_IN2; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSFL_F6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F6_SHIFT)) & SIM_GPSFL_F6_MASK)

#define SIM_GPSFL_F7_MASK                        (0xC000U)
#define SIM_GPSFL_F7_SHIFT                       (14U)
/*! F7 - Configure GPIO F7
 *  0b00..Reserved
 *  0b01..Function = CMPC_O; Peripheral = CMP C; Direction = OUT
 *  0b10..Function = SDAS1; Peripheral = LPI2C1; Direction = IO
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
 *  0b01..Function =XB_OUT10; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = CMPD_O; Peripheral = CMP D; Direction = OUT
 *  0b11..Function = PWMA_2X; Peripheral = PWMA; Direction = IO
 */
#define SIM_GPSFH_F8(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F8_SHIFT)) & SIM_GPSFH_F8_MASK)
/*! @} */

/*! @name IPS0 - Internal Peripheral Select Register 0 */
/*! @{ */

#define SIM_IPS0_SCI0_MASK                       (0x1U)
#define SIM_IPS0_SCI0_SHIFT                      (0U)
/*! SCI0 - Select SCI0_RXD Input
 *  0b0..Function = GPIOC3 or GPIOC8 or GPIOF8; Peripheral = GPIO; Direction = IN
 *  0b1..Function = XB_OUT36; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_SCI0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_SCI0_SHIFT)) & SIM_IPS0_SCI0_MASK)

#define SIM_IPS0_SCI1_MASK                       (0x2U)
#define SIM_IPS0_SCI1_SHIFT                      (1U)
/*! SCI1 - Select SCI1_RXD Input
 *  0b0..Function = GPIOC12 or GPIOF5; Peripheral = GPIO; Direction = IN
 *  0b1..Function = XB_OUT37; Peripheral = XBARA; Direction = IN
 */
#define SIM_IPS0_SCI1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_SCI1_SHIFT)) & SIM_IPS0_SCI1_MASK)

#define SIM_IPS0_TA0_MASK                        (0x100U)
#define SIM_IPS0_TA0_SHIFT                       (8U)
/*! TA0 - Select TMRA Input 0
 *  0b0..Function = GPIOC3; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT38; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA0_SHIFT)) & SIM_IPS0_TA0_MASK)

#define SIM_IPS0_TA1_MASK                        (0x200U)
#define SIM_IPS0_TA1_SHIFT                       (9U)
/*! TA1 - Select TMRA Input 1
 *  0b0..Function = GPIOC4; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT39; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA1_SHIFT)) & SIM_IPS0_TA1_MASK)

#define SIM_IPS0_TA2_MASK                        (0x400U)
#define SIM_IPS0_TA2_SHIFT                       (10U)
/*! TA2 - Select TMRA Input 2
 *  0b0..Function = GPIOC6 ; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT40; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA2_SHIFT)) & SIM_IPS0_TA2_MASK)

#define SIM_IPS0_TA3_MASK                        (0x800U)
#define SIM_IPS0_TA3_SHIFT                       (11U)
/*! TA3 - Select TMRA Input 3
 *  0b0..Function = GPIOC13 ; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT41; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPS0_TA3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPS0_TA3_SHIFT)) & SIM_IPS0_TA3_MASK)
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

#define SIM_MISC0_FAST_MODE_MASK                 (0x4U)
#define SIM_MISC0_FAST_MODE_SHIFT                (2U)
/*! FAST_MODE
 *  0b0..Normal operating mode (core: bus frequency as 1:1)
 *  0b1..Device boots in fast mode (core:bus frequency as 2:1) after software reset
 */
#define SIM_MISC0_FAST_MODE(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_FAST_MODE_SHIFT)) & SIM_MISC0_FAST_MODE_MASK)

#define SIM_MISC0_SCTRL_REORDER_MASK             (0x8U)
#define SIM_MISC0_SCTRL_REORDER_SHIFT            (3U)
/*! SCTRL_REORDER
 *  0b0..Normal order
 *  0b1..Enable the re-ordering of ADC scan control bits
 */
#define SIM_MISC0_SCTRL_REORDER(x)               (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_SCTRL_REORDER_SHIFT)) & SIM_MISC0_SCTRL_REORDER_MASK)

#define SIM_MISC0_MODE_STAT_MASK                 (0x100U)
#define SIM_MISC0_MODE_STAT_SHIFT                (8U)
/*! MODE_STAT - Mode Status bit
 *  0b0..Device in normal operating mode (core: bus frequency as 1:1)
 *  0b1..Device in fast mode (core: bus frequency as 2:1)
 */
#define SIM_MISC0_MODE_STAT(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_MODE_STAT_SHIFT)) & SIM_MISC0_MODE_STAT_MASK)

#define SIM_MISC0_LPI2C0_TRIG_SEL_MASK           (0x200U)
#define SIM_MISC0_LPI2C0_TRIG_SEL_SHIFT          (9U)
/*! LPI2C0_TRIG_SEL - LPI2C0 master/slave trigger select
 *  0b0..Selects slave trigger
 *  0b1..Selects master trigger
 */
#define SIM_MISC0_LPI2C0_TRIG_SEL(x)             (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_LPI2C0_TRIG_SEL_SHIFT)) & SIM_MISC0_LPI2C0_TRIG_SEL_MASK)

#define SIM_MISC0_LPI2C1_TRIG_SEL_MASK           (0x400U)
#define SIM_MISC0_LPI2C1_TRIG_SEL_SHIFT          (10U)
/*! LPI2C1_TRIG_SEL - LPI2C1 master/slave trigger select
 *  0b0..Selects slave trigger
 *  0b1..Selects master trigger.
 */
#define SIM_MISC0_LPI2C1_TRIG_SEL(x)             (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_LPI2C1_TRIG_SEL_SHIFT)) & SIM_MISC0_LPI2C1_TRIG_SEL_MASK)
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

#define SIM_PSWR1_LPI2C0_MASK                    (0x20U)
#define SIM_PSWR1_LPI2C0_SHIFT                   (5U)
/*! LPI2C0 - LPI2C0 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_LPI2C0(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_LPI2C0_SHIFT)) & SIM_PSWR1_LPI2C0_MASK)

#define SIM_PSWR1_LPI2C1_MASK                    (0x40U)
#define SIM_PSWR1_LPI2C1_SHIFT                   (6U)
/*! LPI2C1 - LPI2C1 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_LPI2C1(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_LPI2C1_SHIFT)) & SIM_PSWR1_LPI2C1_MASK)

#define SIM_PSWR1_QSPI0_MASK                     (0x200U)
#define SIM_PSWR1_QSPI0_SHIFT                    (9U)
/*! QSPI0 - QSPI0 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_QSPI0(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_QSPI0_SHIFT)) & SIM_PSWR1_QSPI0_MASK)

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
/*! QDC - QDC Software Reset
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

#define SIM_PSWR3_PWMA_MASK                      (0x80U)
#define SIM_PSWR3_PWMA_SHIFT                     (7U)
/*! PWMA - PWMA Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR3_PWMA(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR3_PWMA_SHIFT)) & SIM_PSWR3_PWMA_MASK)

#define SIM_PSWR3_DMA_MUX_MASK                   (0x200U)
#define SIM_PSWR3_DMA_MUX_SHIFT                  (9U)
/*! DMA_MUX - DMA_MUX Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR3_DMA_MUX(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PSWR3_DMA_MUX_SHIFT)) & SIM_PSWR3_DMA_MUX_MASK)

#define SIM_PSWR3_OPAMPB_MASK                    (0x400U)
#define SIM_PSWR3_OPAMPB_SHIFT                   (10U)
/*! OPAMPB - OPAMPB Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR3_OPAMPB(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PSWR3_OPAMPB_SHIFT)) & SIM_PSWR3_OPAMPB_MASK)

#define SIM_PSWR3_OPAMPA_MASK                    (0x800U)
#define SIM_PSWR3_OPAMPA_SHIFT                   (11U)
/*! OPAMPA - OPAMPA Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR3_OPAMPA(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PSWR3_OPAMPA_SHIFT)) & SIM_PSWR3_OPAMPA_MASK)
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
/*! VLPMS - VLPMODE Status indicator
 *  0b0..Not in VLPMODE
 *  0b1..In VLPMODE
 */
#define SIM_PWRMODE_VLPMS(x)                     (((uint16_t)(((uint16_t)(x)) << SIM_PWRMODE_VLPMS_SHIFT)) & SIM_PWRMODE_VLPMS_MASK)

#define SIM_PWRMODE_LPMS_MASK                    (0x200U)
#define SIM_PWRMODE_LPMS_SHIFT                   (9U)
/*! LPMS - LPMODE Status indicator
 *  0b0..Not in LPMODE
 *  0b1..In LPMODE
 */
#define SIM_PWRMODE_LPMS(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PWRMODE_LPMS_SHIFT)) & SIM_PWRMODE_LPMS_MASK)
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

/*! @name SCR4 - Software Control Register */
/*! @{ */

#define SIM_SCR4_SCR4_MASK                       (0xFFFFU)
#define SIM_SCR4_SCR4_SHIFT                      (0U)
/*! SCR4 - Software Control Data */
#define SIM_SCR4_SCR4(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR4_SCR4_SHIFT)) & SIM_SCR4_SCR4_MASK)
/*! @} */

/*! @name SCR5 - Software Control Register */
/*! @{ */

#define SIM_SCR5_SCR5_MASK                       (0xFFFFU)
#define SIM_SCR5_SCR5_SHIFT                      (0U)
/*! SCR5 - Software Control Data */
#define SIM_SCR5_SCR5(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR5_SCR5_SHIFT)) & SIM_SCR5_SCR5_MASK)
/*! @} */

/*! @name SCR6 - Software Control Register */
/*! @{ */

#define SIM_SCR6_SCR6_MASK                       (0xFFFFU)
#define SIM_SCR6_SCR6_SHIFT                      (0U)
/*! SCR6 - Software Control Data */
#define SIM_SCR6_SCR6(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR6_SCR6_SHIFT)) & SIM_SCR6_SCR6_MASK)
/*! @} */

/*! @name ADC_TMR_SEL - ADC and TMR Select Register */
/*! @{ */

#define SIM_ADC_TMR_SEL_XBAR_IN36_MASK           (0x1U)
#define SIM_ADC_TMR_SEL_XBAR_IN36_SHIFT          (0U)
/*! XBAR_IN36
 *  0b0..TMRA0
 *  0b1..ADC AN0 limit
 */
#define SIM_ADC_TMR_SEL_XBAR_IN36(x)             (((uint16_t)(((uint16_t)(x)) << SIM_ADC_TMR_SEL_XBAR_IN36_SHIFT)) & SIM_ADC_TMR_SEL_XBAR_IN36_MASK)

#define SIM_ADC_TMR_SEL_XBAR_IN37_MASK           (0x2U)
#define SIM_ADC_TMR_SEL_XBAR_IN37_SHIFT          (1U)
/*! XBAR_IN37
 *  0b0..TMRA1
 *  0b1..ADC AN1 limit
 */
#define SIM_ADC_TMR_SEL_XBAR_IN37(x)             (((uint16_t)(((uint16_t)(x)) << SIM_ADC_TMR_SEL_XBAR_IN37_SHIFT)) & SIM_ADC_TMR_SEL_XBAR_IN37_MASK)

#define SIM_ADC_TMR_SEL_XBAR_IN38_MASK           (0x4U)
#define SIM_ADC_TMR_SEL_XBAR_IN38_SHIFT          (2U)
/*! XBAR_IN38
 *  0b0..TMRA2
 *  0b1..ADC AN2 limit
 */
#define SIM_ADC_TMR_SEL_XBAR_IN38(x)             (((uint16_t)(((uint16_t)(x)) << SIM_ADC_TMR_SEL_XBAR_IN38_SHIFT)) & SIM_ADC_TMR_SEL_XBAR_IN38_MASK)

#define SIM_ADC_TMR_SEL_XBAR_IN39_MASK           (0x8U)
#define SIM_ADC_TMR_SEL_XBAR_IN39_SHIFT          (3U)
/*! XBAR_IN39
 *  0b0..TMRA3
 *  0b1..ADC AN3 limit
 */
#define SIM_ADC_TMR_SEL_XBAR_IN39(x)             (((uint16_t)(((uint16_t)(x)) << SIM_ADC_TMR_SEL_XBAR_IN39_SHIFT)) & SIM_ADC_TMR_SEL_XBAR_IN39_MASK)
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

