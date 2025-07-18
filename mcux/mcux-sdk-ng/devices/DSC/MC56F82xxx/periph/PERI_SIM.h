/*
** ###################################################################
**     Processors:          MC56F82313VLC
**                          MC56F82316VLF
**                          MC56F82323VFM
**                          MC56F82623VLC
**                          MC56F82643VLC
**                          MC56F82646VLF
**                          MC56F82723VFM
**                          MC56F82723VLC
**                          MC56F82726VLF
**                          MC56F82728VLH
**                          MC56F82733MFM
**                          MC56F82733VFM
**                          MC56F82733VLC
**                          MC56F82736VLF
**                          MC56F82738VLH
**                          MC56F82743VFM
**                          MC56F82743VLC
**                          MC56F82746MLF
**                          MC56F82746VLF
**                          MC56F82748MLH
**                          MC56F82748VLH
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
**     - rev. 0.1 (2020-12-11)
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

#if (defined(CPU_MC56F82313VLC))
#include "MC56F82313_COMMON.h"
#elif (defined(CPU_MC56F82316VLF))
#include "MC56F82316_COMMON.h"
#elif (defined(CPU_MC56F82323VFM))
#include "MC56F82323_COMMON.h"
#elif (defined(CPU_MC56F82623VLC))
#include "MC56F82623_COMMON.h"
#elif (defined(CPU_MC56F82643VLC))
#include "MC56F82643_COMMON.h"
#elif (defined(CPU_MC56F82646VLF))
#include "MC56F82646_COMMON.h"
#elif (defined(CPU_MC56F82723VFM) || defined(CPU_MC56F82723VLC))
#include "MC56F82723_COMMON.h"
#elif (defined(CPU_MC56F82726VLF))
#include "MC56F82726_COMMON.h"
#elif (defined(CPU_MC56F82728VLH))
#include "MC56F82728_COMMON.h"
#elif (defined(CPU_MC56F82733MFM) || defined(CPU_MC56F82733VFM) || defined(CPU_MC56F82733VLC))
#include "MC56F82733_COMMON.h"
#elif (defined(CPU_MC56F82736VLF))
#include "MC56F82736_COMMON.h"
#elif (defined(CPU_MC56F82738VLH))
#include "MC56F82738_COMMON.h"
#elif (defined(CPU_MC56F82743VFM) || defined(CPU_MC56F82743VLC))
#include "MC56F82743_COMMON.h"
#elif (defined(CPU_MC56F82746MLF) || defined(CPU_MC56F82746VLF))
#include "MC56F82746_COMMON.h"
#elif (defined(CPU_MC56F82748MLH) || defined(CPU_MC56F82748VLH))
#include "MC56F82748_COMMON.h"
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
    kGPIO_Peri_C4_XB_IN6            = 0x0242,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C4_EWM_OUT_B         = 0x0243,      /**< GPIO_C4, Pin */
    kGPIO_Peri_C6_TA2               = 0x0260,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C6_XB_IN3            = 0x0261,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C6_CMP_REF           = 0x0262,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C6_SS0_B             = 0x0263,      /**< GPIO_C6, Pin */
    kGPIO_Peri_C8_MISO0             = 0x0280,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C8_RXD0              = 0x0281,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C8_XB_IN9            = 0x0282,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C8_XB_OUT6           = 0x0283,      /**< GPIO_C8, Pin */
    kGPIO_Peri_C9_SCLK0             = 0x0290,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C9_XB_IN4            = 0x0291,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C9_TXD0              = 0x0292,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C9_XB_OUT8           = 0x0293,      /**< GPIO_C9, Pin */
    kGPIO_Peri_C10_MOSI0            = 0x02A0,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C10_XB_IN5           = 0x02A1,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C10_MISO0            = 0x02A2,      /**< GPIO_C10, Pin */
    kGPIO_Peri_C10_XB_OUT9          = 0x02A3,      /**< GPIO_C10, Pin */
    kGPIO_Peri_E4_PWM_2B            = 0x0440,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E4_XB_IN2            = 0x0441,      /**< GPIO_E4, Pin */
    kGPIO_Peri_E5_PWM_2A            = 0x0450,      /**< GPIO_E5, Pin */
    kGPIO_Peri_E5_XB_IN3            = 0x0451,      /**< GPIO_E5, Pin */
    kGPIO_Peri_F2_SCL0              = 0x0520,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F2_XB_OUT6           = 0x0521,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F3_SDA0              = 0x0530,      /**< GPIO_F3, Pin */
    kGPIO_Peri_F3_XB_OUT7           = 0x0531,      /**< GPIO_F3, Pin */
    kGPIO_Peri_A0_ANA0_and_CMPA_IN3 = 0x0000,      /**< GPIO_A0, Pin */
    kGPIO_Peri_A0_CMPC_O            = 0x0001,      /**< GPIO_A0, Pin */
    kGPIO_Peri_B1_ANB1_and_CMPB_IN0 = 0x0110,      /**< GPIO_B1, Pin */
    kGPIO_Peri_B1_DACB_O            = 0x0111,      /**< GPIO_B1, Pin */
    kGPIO_Peri_C0_EXTAL             = 0x0200,      /**< GPIO_C0, Pin */
    kGPIO_Peri_C0_CLKIN0            = 0x0201,      /**< GPIO_C0, Pin */
    kGPIO_Peri_C5_DACA_O            = 0x0250,      /**< GPIO_C5, Pin */
    kGPIO_Peri_C5_XB_IN7            = 0x0251,      /**< GPIO_C5, Pin */
    kGPIO_Peri_C7_SS0_B             = 0x0270,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C7_TXD0              = 0x0271,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C7_XB_IN8            = 0x0272,      /**< GPIO_C7, Pin */
    kGPIO_Peri_C11_SCL0             = 0x02B1,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C11_TXD1             = 0x02B2,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C12_SDA0             = 0x02C1,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C12_RXD1             = 0x02C2,      /**< GPIO_C12, Pin */
    kGPIO_Peri_C13_TA3              = 0x02D0,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C13_XB_IN6           = 0x02D1,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C13_EWM_OUT_B        = 0x02D2,      /**< GPIO_C13, Pin */
    kGPIO_Peri_C14_SDA0             = 0x02E0,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C14_XB_OUT4          = 0x02E1,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C14_PWM_FAULT4       = 0x02E2,      /**< GPIO_C14, Pin */
    kGPIO_Peri_C15_SCL0             = 0x02F0,      /**< GPIO_C15, Pin */
    kGPIO_Peri_C15_XB_OUT5          = 0x02F1,      /**< GPIO_C15, Pin */
    kGPIO_Peri_C15_PWM_FAULT5       = 0x02F2,      /**< GPIO_C15, Pin */
    kGPIO_Peri_F1_CLKO1             = 0x0510,      /**< GPIO_F1, Pin */
    kGPIO_Peri_F1_XB_IN7            = 0x0511,      /**< GPIO_F1, Pin */
    kGPIO_Peri_F1_CMPD_O            = 0x0512,      /**< GPIO_F1, Pin */
    kGPIO_Peri_C11_CANTX            = 0x02B0,      /**< GPIO_C11, Pin */
    kGPIO_Peri_C12_CANRX            = 0x02C0,      /**< GPIO_C12, Pin */
    kGPIO_Peri_E6_PWM_3B            = 0x0460,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E6_XB_IN4            = 0x0461,      /**< GPIO_E6, Pin */
    kGPIO_Peri_E7_PWM_3A            = 0x0470,      /**< GPIO_E7, Pin */
    kGPIO_Peri_E7_XB_IN5            = 0x0471,      /**< GPIO_E7, Pin */
    kGPIO_Peri_F0_XB_IN6            = 0x0500,      /**< GPIO_F0, Pin */
    kGPIO_Peri_F0_SCLK1             = 0x0502,      /**< GPIO_F0, Pin */
    kGPIO_Peri_F2_MISO1             = 0x0522,      /**< GPIO_F2, Pin */
    kGPIO_Peri_F3_MOSI1             = 0x0532,      /**< GPIO_F3, Pin */
    kGPIO_Peri_F4_TXD1              = 0x0540,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F4_XB_OUT8           = 0x0541,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F4_PWM_0X            = 0x0542,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F4_PWM_FAULT6        = 0x0543,      /**< GPIO_F4, Pin */
    kGPIO_Peri_F5_RXD1              = 0x0550,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F5_XB_OUT9           = 0x0551,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F5_PWM_1X            = 0x0552,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F5_PWM_FAULT7        = 0x0553,      /**< GPIO_F5, Pin */
    kGPIO_Peri_F6_PWM_3X            = 0x0561,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F6_XB_IN2            = 0x0563,      /**< GPIO_F6, Pin */
    kGPIO_Peri_F7_CMPC_O            = 0x0571,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F7_SS1_B             = 0x0572,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F7_XB_IN3            = 0x0573,      /**< GPIO_F7, Pin */
    kGPIO_Peri_F8_RXD0              = 0x0580,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_XB_OUT10          = 0x0581,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_CMPD_O            = 0x0582,      /**< GPIO_F8, Pin */
    kGPIO_Peri_F8_PWM_2X            = 0x0583,      /**< GPIO_F8, Pin */
} gpio_peripheral_mux_t;

/* @} */
#endif /* GPIO_PERIPHERAL_MUX_T_ */

#if !defined(SIM_SWRESET_PERI_INDEX_T_)
#define SIM_SWRESET_PERI_INDEX_T_
typedef enum _sim_swReset_peri_index
{
    kSIM_SWResetGPIO                = 6U,          /**< GPIO Software Reset. */
    kSIM_SWResetTMRA                = 15U,         /**< TMRA Software Reset. */
    kSIM_SWResetIIC0                = 22U,         /**< IIC0 Software Reset. */
    kSIM_SWResetQSPI0               = 25U,         /**< QSPI0 Software Reset. */
    kSIM_SWResetSCI1                = 27U,         /**< SCI1 Software Reset. */
    kSIM_SWResetSCI0                = 28U,         /**< SCI0 Software Reset. */
    kSIM_SWResetDACA                = 29U,         /**< DACA Software Reset. */
    kSIM_SWResetDACB                = 30U,         /**< DACB Software Reset. */
    kSIM_SWResetPIT1                = 34U,         /**< PIT1 Software Reset. */
    kSIM_SWResetPIT0                = 35U,         /**< PIT0 Software Reset. */
    kSIM_SWResetCRC                 = 37U,         /**< CRC Software Reset. */
    kSIM_SWResetCADC                = 39U,         /**< Cyclic ADC Software Reset. */
    kSIM_SWResetCMP                 = 44U,         /**< CMP Software Reset. */
    kSIM_SWResetEWM                 = 47U,         /**< EWM Software Reset. */
    kSIM_SWResetPWMA                = 55U,         /**< PWMA Software Reset. */
    kSIM_SWResetMSCAN               = 16U,         /**< MSCAN Software Reset. */
    kSIM_SWResetQSPI1               = 24U,         /**< QSPI1 Software Reset. */
} sim_swReset_peri_index_t;
#endif /* SIM_SWRESET_PERI_INDEX_T_ */

#if !defined(SIM_INTERNAL_PERI_INDEX_T_)
#define SIM_INTERNAL_PERI_INDEX_T_
typedef enum _sim_internal_peri_index
{
    kSIM_SCI0_RXDsourceIndex        = 0U,          /**< Select SCI0_RXD source. */
    kSIM_SCI1_RXDInputIndex         = 1U,          /**< Select SCI1_RXD Input. */
    kSIM_TMRA0InputIndex            = 8U,          /**< Select TMRA0 Input. */
    kSIM_TMRA1InputIndex            = 9U,          /**< Select TMRA1 Input. */
    kSIM_TMRA2InputIndex            = 10U,         /**< Select TMRA2 Input. */
    kSIM_TMRA3InputIndex            = 11U,         /**< Select TMRA3 Input. */
} sim_internal_peri_index_t;
#endif /* SIM_INTERNAL_PERI_INDEX_T_ */

#if !defined(SIM_INTERNAL_PERI_INPUT_T_)
#define SIM_INTERNAL_PERI_INPUT_T_
typedef enum _sim_internal_peri_input
{
    kSIM_SCI0_RXDsource_GPIOC3_GPIOC8_GPIOF8 = 0U, /**< Select SCI0_RXD source, GPIOC3 or GPIOC8 or GPIOF8. */
    kSIM_SCI0_RXDsource_XB_OUT38    = 1U,          /**< Select SCI0_RXD source, XB_OUT38. */
    kSIM_SCI1_RXDInput_GPIOC12_GPIOF5 = 0U,        /**< Select SCI1_RXD Input, GPIOC12 or GPIOF5. */
    kSIM_SCI1_RXDInput_XB_OUT39     = 1U,          /**< Select SCI1_RXD Input, XB_OUT39. */
    kSIM_TMRA0Input_GPIOC3          = 0U,          /**< Select TMRA0 Input, GPIOC3. */
    kSIM_TMRA0Input_XB_OUT34        = 1U,          /**< Select TMRA0 Input, XB_OUT34. */
    kSIM_TMRA1Input_GPIOC4          = 0U,          /**< Select TMRA1 Input, GPIOC4. */
    kSIM_TMRA1Input_XB_OUT35        = 1U,          /**< Select TMRA1 Input, XB_OUT35. */
    kSIM_TMRA2Input_GPIOC6          = 0U,          /**< Select TMRA2 Input, GPIOC6. */
    kSIM_TMRA2Input_XB_OUT36        = 1U,          /**< Select TMRA2 Input, XB_OUT36. */
    kSIM_TMRA3Input_GPIOC13         = 0U,          /**< Select TMRA3 Input, GPIOC13. */
    kSIM_TMRA3Input_XB_OUT37        = 1U,          /**< Select TMRA3 Input, XB_OUT37. */
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
    kSIM_SCR7                       = 7U,          /**< SCR7. */
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
  __IO uint16_t SD0;                               /**< STOP Disable Register 0, offset: 0x10 */
  __IO uint16_t SD1;                               /**< Peripheral Clock STOP Disable Register 1, offset: 0x11 */
  __IO uint16_t SD2;                               /**< Peripheral Clock STOP Disable Register 2, offset: 0x12 */
  __IO uint16_t SD3;                               /**< Peripheral Clock STOP Disable Register 3, offset: 0x13 */
  __IO uint16_t IOSAHI;                            /**< I/O Short Address Location Register, offset: 0x14 */
  __IO uint16_t IOSALO;                            /**< I/O Short Address Location Register, offset: 0x15 */
  __IO uint16_t PROT;                              /**< Protection Register, offset: 0x16 */
  __IO uint16_t GPSAL;                             /**< GPIOA LSBs Peripheral Select Register, offset: 0x17 */
  __IO uint16_t GPSBL;                             /**< GPIOB LSBs Peripheral Select Register, offset: 0x18 */
  __IO uint16_t GPSCL;                             /**< GPIOC LSBs Peripheral Select Register, offset: 0x19 */
  __IO uint16_t GPSCH;                             /**< GPIOC MSBs Peripheral Select Register, offset: 0x1A */
       uint16_t RESERVED_2[1];
  __IO uint16_t GPSEL;                             /**< GPIOE LSBs Peripheral Select Register, offset: 0x1C */
       uint16_t RESERVED_3[1];
  __IO uint16_t GPSFL;                             /**< GPIOF LSBs Peripheral Select Register, offset: 0x1E */
  __IO uint16_t GPSFH;                             /**< GPIOF MSBs Peripheral Select Register, offset: 0x1F */
       uint16_t RESERVED_4[2];
  __IO uint16_t IPSN;                              /**< Internal Peripheral Select Register, offset: 0x22 */
  __IO uint16_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x23 */
  __IO uint16_t PSWR0;                             /**< Peripheral Software Reset Register 0, offset: 0x24 */
  __IO uint16_t PSWR1;                             /**< Peripheral Software Reset Register 1, offset: 0x25 */
  __IO uint16_t PSWR2;                             /**< Peripheral Software Reset Register 2, offset: 0x26 */
  __IO uint16_t PSWR3;                             /**< Peripheral Software Reset Register 3, offset: 0x27 */
  __IO uint16_t PWRMODE;                           /**< Power Mode Register, offset: 0x28 */
       uint16_t RESERVED_5[3];
  __I  uint16_t NVMOPT2H;                          /**< Non-Volatile Memory Option Register 2 (High), offset: 0x2C */
  __I  uint16_t NVMOPT2L;                          /**< Non-Volatile Memory Option Register 2 (Low), offset: 0x2D */
       uint16_t RESERVED_6[23];
  __IO uint16_t SCR0;                              /**< Software Control Register, offset: 0x45 */
  __IO uint16_t SCR1;                              /**< Software Control Register 1, offset: 0x46 */
  __IO uint16_t SCR2;                              /**< Software Control Register 2, offset: 0x47 */
  __IO uint16_t SCR3;                              /**< Software Control Register 3, offset: 0x48 */
  __IO uint16_t SCR4;                              /**< Software Control Register 4, offset: 0x49 */
  __IO uint16_t SCR5;                              /**< Software Control Register, offset: 0x4A */
  __IO uint16_t SCR6;                              /**< Software Control Register 5, offset: 0x4B */
  __IO uint16_t SCR7;                              /**< Software Control Register 6, offset: 0x4C */
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

#define SIM_RSTAT_COP_WNDOW_MASK                 (0x40U)
#define SIM_RSTAT_COP_WNDOW_SHIFT                (6U)
/*! COP_WNDOW - COP Window Time-out Reset */
#define SIM_RSTAT_COP_WNDOW(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_COP_WNDOW_SHIFT)) & SIM_RSTAT_COP_WNDOW_MASK)

#define SIM_RSTAT_SWR_MASK                       (0x80U)
#define SIM_RSTAT_SWR_SHIFT                      (7U)
/*! SWR - Software Reset Request */
#define SIM_RSTAT_SWR(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_RSTAT_SWR_SHIFT)) & SIM_RSTAT_SWR_MASK)
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
 *  0b001..Function = MSTR_2X continuous after reset
 *  0b010..Function = DIV2_BUS_CLK continuous after reset
 *  0b011..Function = MSTR_OSC (master clock) continuous after reset
 *  0b100..Function = ROSC_8M (8 MHz / 400 kHz relaxation oscillator clock )
 *  0b101..Function = ROSC_200K (200 kHz relaxation oscillator clock )
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
 *  0b001..Function = MSTR_2X continuous after reset
 *  0b010..Function = DIV2_BUS_CLK continuous after reset
 *  0b011..Function = MSTR_OSC (master clock) continuous after reset
 *  0b100..Function = ROSC_8M (8 MHz / 400 kHz relaxation oscillator clock )
 *  0b101..Function = ROSC_200K (200 kHz relaxation oscillator clock )
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

#define SIM_PCR_IIC_FILT_MASK                    (0x200U)
#define SIM_PCR_IIC_FILT_SHIFT                   (9U)
/*! IIC_FILT - IIC_FILT Clock Rate
 *  0b0..IIC FILTER clock rate equals bus clock rate (default).
 *  0b1..IIC FILTER clock rate equals 2X bus clock rate that is, 100MHz
 */
#define SIM_PCR_IIC_FILT(x)                      (((uint16_t)(((uint16_t)(x)) << SIM_PCR_IIC_FILT_SHIFT)) & SIM_PCR_IIC_FILT_MASK)

#define SIM_PCR_PWM_MASK                         (0x400U)
#define SIM_PCR_PWM_SHIFT                        (10U)
/*! PWM - PWM Clock Rate
 *  0b0..PWM clock rate equals bus clock rate (default).
 *  0b1..PWM clock rate equals 2X bus clock rat,ie 100MHz
 */
#define SIM_PCR_PWM(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_PCR_PWM_SHIFT)) & SIM_PCR_PWM_MASK)

#define SIM_PCR_TMR_MASK                         (0x800U)
#define SIM_PCR_TMR_SHIFT                        (11U)
/*! TMR - TMR Clock Rate
 *  0b0..TMR clock rate equals bus clock rate (default).
 *  0b1..TMR clock rate equals 2X bus clock rate that is, 100MHz.
 */
#define SIM_PCR_TMR(x)                           (((uint16_t)(((uint16_t)(x)) << SIM_PCR_TMR_SHIFT)) & SIM_PCR_TMR_MASK)

#define SIM_PCR_SCI1_CR_MASK                     (0x1000U)
#define SIM_PCR_SCI1_CR_SHIFT                    (12U)
/*! SCI1_CR - SCI1 Clock Rate
 *  0b0..SCI1 clock rate equals bus clock rate (default)
 *  0b1..SCI1 clock rate equals 2X bus clock rate that is, 100 MHz
 */
#define SIM_PCR_SCI1_CR(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PCR_SCI1_CR_SHIFT)) & SIM_PCR_SCI1_CR_MASK)

#define SIM_PCR_SCI0_CR_MASK                     (0x2000U)
#define SIM_PCR_SCI0_CR_SHIFT                    (13U)
/*! SCI0_CR - SCI0 Clock Rate
 *  0b0..SCI0 clock rate equals bus clock rate (default)
 *  0b1..SCI0 clock rate equals 2X bus clock rate that is, 100MHz
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

#define SIM_PCE1_MSCAN_MASK                      (0x1U)
#define SIM_PCE1_MSCAN_SHIFT                     (0U)
/*! MSCAN - MSCAN IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_MSCAN(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_MSCAN_SHIFT)) & SIM_PCE1_MSCAN_MASK)

#define SIM_PCE1_IIC0_MASK                       (0x40U)
#define SIM_PCE1_IIC0_SHIFT                      (6U)
/*! IIC0 - IIC0 IPBus Clock Enable
 *  0b0..The peripheral is not clocked.
 *  0b1..The peripheral is clocked.
 */
#define SIM_PCE1_IIC0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_IIC0_SHIFT)) & SIM_PCE1_IIC0_MASK)

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

#define SIM_PCE1_DACA_MASK                       (0x2000U)
#define SIM_PCE1_DACA_SHIFT                      (13U)
/*! DACA - 12bit DACA IPBus Clock Enable
 *  0b0..12bit DACA is not clocked.
 *  0b1..12bit DACA is clocked.
 */
#define SIM_PCE1_DACA(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_DACA_SHIFT)) & SIM_PCE1_DACA_MASK)

#define SIM_PCE1_DACB_MASK                       (0x4000U)
#define SIM_PCE1_DACB_SHIFT                      (14U)
/*! DACB - 12bit DACB IPBus Clock Enable
 *  0b0..12bit DACB is not clocked.
 *  0b1..12bit DACB is clocked.
 */
#define SIM_PCE1_DACB(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_PCE1_DACB_SHIFT)) & SIM_PCE1_DACB_MASK)
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

#define SIM_SD1_MSCAN_MASK                       (0x1U)
#define SIM_SD1_MSCAN_SHIFT                      (0U)
/*! MSCAN - MSCAN IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_MSCAN(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SD1_MSCAN_SHIFT)) & SIM_SD1_MSCAN_MASK)

#define SIM_SD1_IIC0_MASK                        (0x40U)
#define SIM_SD1_IIC0_SHIFT                       (6U)
/*! IIC0 - IIC0 IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode, but the IIC0 module will not enter stop mode.
 */
#define SIM_SD1_IIC0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_IIC0_SHIFT)) & SIM_SD1_IIC0_MASK)

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

#define SIM_SD1_DACA_MASK                        (0x2000U)
#define SIM_SD1_DACA_SHIFT                       (13U)
/*! DACA - DACA IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_DACA(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_DACA_SHIFT)) & SIM_SD1_DACA_MASK)

#define SIM_SD1_DACB_MASK                        (0x4000U)
#define SIM_SD1_DACB_SHIFT                       (14U)
/*! DACB - DACB IPBus STOP Disable
 *  0b0..The peripheral is not clocked in stop mode.
 *  0b1..The peripheral is clocked in stop mode.
 */
#define SIM_SD1_DACB(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_SD1_DACB_SHIFT)) & SIM_SD1_DACB_MASK)
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
 *  0b0..Function = ANA0/CMPA3; Peripheral = ADC/CMPA; Direction = AN_IN
 *  0b1..Function = CMPC_O; Peripheral = CMPC; Direction = OUT
 */
#define SIM_GPSAL_A0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSAL_A0_SHIFT)) & SIM_GPSAL_A0_MASK)
/*! @} */

/*! @name GPSBL - GPIOB LSBs Peripheral Select Register */
/*! @{ */

#define SIM_GPSBL_B1_MASK                        (0x4U)
#define SIM_GPSBL_B1_SHIFT                       (2U)
/*! B1
 *  0b0..Function = ANB1/CMPB_IN0; Peripheral = ADC/CMPB; Direction = AN_IN
 *  0b1..Function = DACB; Peripheral = DAC; Direction = OUT
 */
#define SIM_GPSBL_B1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSBL_B1_SHIFT)) & SIM_GPSBL_B1_MASK)
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
 *  0b01..Function = XBOUT_11; Peripheral = XBARA; Direction = OUT
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
 *  0b10..Function = XB_IN6; Peripheral = XBAR; Direction = IN
 *  0b11..Function = EWM_OUT_B; Peripheral = EWM; Direction = OUT
 */
#define SIM_GPSCL_C4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C4_SHIFT)) & SIM_GPSCL_C4_MASK)

#define SIM_GPSCL_C5_MASK                        (0x400U)
#define SIM_GPSCL_C5_SHIFT                       (10U)
/*! C5 - Configure GPIO C5
 *  0b0..Function = DACA; Peripheral = DAC; Direction = AN_OUT
 *  0b1..Function = XB_IN7; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSCL_C5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C5_SHIFT)) & SIM_GPSCL_C5_MASK)

#define SIM_GPSCL_C6_MASK                        (0x3000U)
#define SIM_GPSCL_C6_SHIFT                       (12U)
/*! C6 - Configure GPIO C6
 *  0b00..Function = TA2; Peripheral = TMRA; Direction = IO
 *  0b01..Function = XB_IN3; Peripheral = XBAR; Direction = IN
 *  0b10..Function = CMPREF; Peripheral = HSCMP A/B/C /D ; Direction = AN_IN
 *  0b11..Function: SS0_B; Periphal: SPI0; Direction: IO
 */
#define SIM_GPSCL_C6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCL_C6_SHIFT)) & SIM_GPSCL_C6_MASK)

#define SIM_GPSCL_C7_MASK                        (0xC000U)
#define SIM_GPSCL_C7_SHIFT                       (14U)
/*! C7 - Configure GPIO C7
 *  0b00..Function = SS0_B; Peripheral = SPI0; Direction = IO
 *  0b01..Function = TXD0; Peripheral = SCI0; Direction = IO
 *  0b10..Function = XBIN_8; Peripheral = XBARA; Direction = IO
 *  0b11..Reserved
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
 *  0b11..Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
 */
#define SIM_GPSCH_C8(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C8_SHIFT)) & SIM_GPSCH_C8_MASK)

#define SIM_GPSCH_C9_MASK                        (0xCU)
#define SIM_GPSCH_C9_SHIFT                       (2U)
/*! C9 - Configure GPIO C9
 *  0b00..Function = SCLK0; Peripheral = SPI0; Direction = IO
 *  0b01..Function = XB_IN4; Peripheral = XBAR; Direction = IN
 *  0b10..Function = TXD0; Peripheral = SCI0; Direction = IO
 *  0b11..Function = XB_OUT8; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSCH_C9(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C9_SHIFT)) & SIM_GPSCH_C9_MASK)

#define SIM_GPSCH_C10_MASK                       (0x30U)
#define SIM_GPSCH_C10_SHIFT                      (4U)
/*! C10 - Configure GPIO C10
 *  0b00..Function = MOSI0; Peripheral = SPI0; Direction = IO
 *  0b01..Function = XB_IN5; Peripheral = XBAR; Direction = IN
 *  0b10..Function = MISO0; Peripheral = SPI0; Direction = IO
 *  0b11..Function = XB_OUT9; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSCH_C10(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C10_SHIFT)) & SIM_GPSCH_C10_MASK)

#define SIM_GPSCH_C11_MASK                       (0xC0U)
#define SIM_GPSCH_C11_SHIFT                      (6U)
/*! C11 - Configure GPIO C11
 *  0b00..Function = CANTX; Peripheral = MSCAN; Direction = OD_OUT
 *  0b01..Function = SCL0; Peripheral = IIC0; Direction = OD_IO
 *  0b10..Function = TXD1; Peripheral = SCI1; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSCH_C11(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C11_SHIFT)) & SIM_GPSCH_C11_MASK)

#define SIM_GPSCH_C12_MASK                       (0x300U)
#define SIM_GPSCH_C12_SHIFT                      (8U)
/*! C12 - Configure GPIO C12
 *  0b00..Function = CANRX; Peripheral = MSCAN; Direction = IN
 *  0b01..Function = SDA0; Peripheral = IIC0; Direction = OD_IO
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

#define SIM_GPSCH_C14_MASK                       (0x3000U)
#define SIM_GPSCH_C14_SHIFT                      (12U)
/*! C14 - Configure GPIO C14
 *  0b00..Function = SDA0; Peripheral = IIC0; Direction = OD_IO
 *  0b01..Function = XB_OUT4; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWM_FAULT4; Peripheral = PWM; Direction = OD_IO
 *  0b11..Reserved
 */
#define SIM_GPSCH_C14(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C14_SHIFT)) & SIM_GPSCH_C14_MASK)

#define SIM_GPSCH_C15_MASK                       (0xC000U)
#define SIM_GPSCH_C15_SHIFT                      (14U)
/*! C15 - Configure GPIO C15
 *  0b00..Function = SCL0; Peripheral = IIC0; Direction = OD_IO
 *  0b01..Function = XB_OUT5; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWM_FAULT5; Peripheral = PWM; Direction = IN
 *  0b11..Reserved
 */
#define SIM_GPSCH_C15(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_GPSCH_C15_SHIFT)) & SIM_GPSCH_C15_MASK)
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

#define SIM_GPSEL_E6_MASK                        (0x1000U)
#define SIM_GPSEL_E6_SHIFT                       (12U)
/*! E6 - Configure GPIO E6
 *  0b0..Function = PWMA_3B; Peripheral = PWMA; Direction = IO
 *  0b1..Function = XB_IN4; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSEL_E6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSEL_E6_SHIFT)) & SIM_GPSEL_E6_MASK)

#define SIM_GPSEL_E7_MASK                        (0x4000U)
#define SIM_GPSEL_E7_SHIFT                       (14U)
/*! E7 - Configure GPIO E7
 *  0b0..Function = PWMA_3A; Peripheral = PWMA; Direction = IO
 *  0b1..Function = XB_IN5; Peripheral = XBAR; Direction = IN
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

#define SIM_GPSFL_F2_MASK                        (0x30U)
#define SIM_GPSFL_F2_SHIFT                       (4U)
/*! F2 - Configure GPIO F2
 *  0b00..Function = SCL0; Peripheral = IIC0; Direction = OD_IO
 *  0b01..Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = MISO1; Peripheral = SPI1; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSFL_F2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F2_SHIFT)) & SIM_GPSFL_F2_MASK)

#define SIM_GPSFL_F3_MASK                        (0xC0U)
#define SIM_GPSFL_F3_SHIFT                       (6U)
/*! F3 - Configure GPIO F3
 *  0b00..Function = SDA0; Peripheral = IIC0; Direction = OD_IO
 *  0b01..Function = XB_OUT7; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = MOSI1; Peripheral = SPI1; Direction = IO
 *  0b11..Reserved
 */
#define SIM_GPSFL_F3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F3_SHIFT)) & SIM_GPSFL_F3_MASK)

#define SIM_GPSFL_F4_MASK                        (0x300U)
#define SIM_GPSFL_F4_SHIFT                       (8U)
/*! F4 - Configure GPIO F4
 *  0b00..Function = TXD1; Peripheral = SCI1; Direction = IO
 *  0b01..Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWMA_0X; Peripheral = PWMA; Direction = IO
 *  0b11..Function = PWMA_FAULT6; Peripheral = PWMA; Direction = OUT
 */
#define SIM_GPSFL_F4(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F4_SHIFT)) & SIM_GPSFL_F4_MASK)

#define SIM_GPSFL_F5_MASK                        (0xC00U)
#define SIM_GPSFL_F5_SHIFT                       (10U)
/*! F5 - Configure GPIO F5
 *  0b00..Function = RXD1; Peripheral = SCI1; Direction = IN
 *  0b01..Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
 *  0b10..Function = PWMA_1x; Peripheral = PWMA; Direction = IN
 *  0b11..Function = PWMA_FAULT7; Peripheral = PWMA; Direction = OUT
 */
#define SIM_GPSFL_F5(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F5_SHIFT)) & SIM_GPSFL_F5_MASK)

#define SIM_GPSFL_F6_MASK                        (0x3000U)
#define SIM_GPSFL_F6_SHIFT                       (12U)
/*! F6 - Configure GPIO F6
 *  0b00..Reserved
 *  0b01..Function = PWMA_3X; Peripheral = PWMA; Direction = IO
 *  0b10..Reserved
 *  0b11..Function = XB_IN2; Peripheral = XBAR; Direction = IN
 */
#define SIM_GPSFL_F6(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFL_F6_SHIFT)) & SIM_GPSFL_F6_MASK)

#define SIM_GPSFL_F7_MASK                        (0xC000U)
#define SIM_GPSFL_F7_SHIFT                       (14U)
/*! F7 - Configure GPIO F7
 *  0b00..Reserved
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
 *  0b01..Function =XB_OUT10; Peripheral = XBARA; Direction = IO
 *  0b10..Function = CMPD_O; Peripheral = HSCMPD; Direction = OUT
 *  0b11..Function = PWMA_2x; Peripheral = PWMA; Direction = IO
 */
#define SIM_GPSFH_F8(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_GPSFH_F8_SHIFT)) & SIM_GPSFH_F8_MASK)
/*! @} */

/*! @name IPSN - Internal Peripheral Select Register */
/*! @{ */

#define SIM_IPSN_SCI0_MASK                       (0x1U)
#define SIM_IPSN_SCI0_SHIFT                      (0U)
/*! SCI0 - Select SCI0_RXD source
 *  0b0..Function = GPIOC3 or GPIOC8 or GPIOF8; Peripheral = GPIO; Direction = IN
 *  0b1..Function = XB_OUT38; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPSN_SCI0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_IPSN_SCI0_SHIFT)) & SIM_IPSN_SCI0_MASK)

#define SIM_IPSN_SCI1_MASK                       (0x2U)
#define SIM_IPSN_SCI1_SHIFT                      (1U)
/*! SCI1 - Select SCI1_RXD Input
 *  0b0..Function = GPIOC12 or GPIOF5; Peripheral = GPIO; Direction = IN
 *  0b1..Function = XB_OUT39; Peripheral = XBARA; Direction = IN
 */
#define SIM_IPSN_SCI1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_IPSN_SCI1_SHIFT)) & SIM_IPSN_SCI1_MASK)

#define SIM_IPSN_TA0_MASK                        (0x100U)
#define SIM_IPSN_TA0_SHIFT                       (8U)
/*! TA0 - Select TMRA0 Input
 *  0b0..Function = GPIOC3; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT34; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPSN_TA0(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPSN_TA0_SHIFT)) & SIM_IPSN_TA0_MASK)

#define SIM_IPSN_TA1_MASK                        (0x200U)
#define SIM_IPSN_TA1_SHIFT                       (9U)
/*! TA1 - Select TMRA1 Input
 *  0b0..Function = GPIOC4; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT35; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPSN_TA1(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPSN_TA1_SHIFT)) & SIM_IPSN_TA1_MASK)

#define SIM_IPSN_TA2_MASK                        (0x400U)
#define SIM_IPSN_TA2_SHIFT                       (10U)
/*! TA2 - Select TMRA2 Input
 *  0b0..Function = GPIOC6; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT36; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPSN_TA2(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPSN_TA2_SHIFT)) & SIM_IPSN_TA2_MASK)

#define SIM_IPSN_TA3_MASK                        (0x800U)
#define SIM_IPSN_TA3_SHIFT                       (11U)
/*! TA3 - Select TMRA3 Input
 *  0b0..Function = GPIOC13; Peripheral = GPIOC; Direction = IN
 *  0b1..Function = XB_OUT37; Peripheral = XBAR; Direction = IN
 */
#define SIM_IPSN_TA3(x)                          (((uint16_t)(((uint16_t)(x)) << SIM_IPSN_TA3_SHIFT)) & SIM_IPSN_TA3_MASK)
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
 *  0b0..Normal operating mode
 *  0b1..Device boots in fast mode (core:bus :: 2:1) after software reset.
 */
#define SIM_MISC0_FAST_MODE(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_FAST_MODE_SHIFT)) & SIM_MISC0_FAST_MODE_MASK)

#define SIM_MISC0_ADC_SCTRL_MASK                 (0x8U)
#define SIM_MISC0_ADC_SCTRL_SHIFT                (3U)
/*! ADC_SCTRL
 *  0b0..Normal order
 *  0b1..Enable the re-ordering of ADC scan control bits
 */
#define SIM_MISC0_ADC_SCTRL(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_ADC_SCTRL_SHIFT)) & SIM_MISC0_ADC_SCTRL_MASK)

#define SIM_MISC0_MODE_STAT_MASK                 (0x100U)
#define SIM_MISC0_MODE_STAT_SHIFT                (8U)
/*! MODE_STAT
 *  0b0..Device in normal operating mode with core. Bus frequency is 1:1
 *  0b1..Device in fast mode
 */
#define SIM_MISC0_MODE_STAT(x)                   (((uint16_t)(((uint16_t)(x)) << SIM_MISC0_MODE_STAT_SHIFT)) & SIM_MISC0_MODE_STAT_MASK)
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

#define SIM_PSWR1_MSCAN_MASK                     (0x1U)
#define SIM_PSWR1_MSCAN_SHIFT                    (0U)
/*! MSCAN - MSCAN Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_MSCAN(x)                       (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_MSCAN_SHIFT)) & SIM_PSWR1_MSCAN_MASK)

#define SIM_PSWR1_IIC0_MASK                      (0x40U)
#define SIM_PSWR1_IIC0_SHIFT                     (6U)
/*! IIC0 - IIC0 Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_IIC0(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_IIC0_SHIFT)) & SIM_PSWR1_IIC0_MASK)

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

#define SIM_PSWR1_DACA_MASK                      (0x2000U)
#define SIM_PSWR1_DACA_SHIFT                     (13U)
/*! DACA - DACA Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_DACA(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_DACA_SHIFT)) & SIM_PSWR1_DACA_MASK)

#define SIM_PSWR1_DACB_MASK                      (0x4000U)
#define SIM_PSWR1_DACB_SHIFT                     (14U)
/*! DACB - DACB Software Reset
 *  0b0..The corresponding peripheral is not reset.
 *  0b1..The corresponding peripheral is reset.
 */
#define SIM_PSWR1_DACB(x)                        (((uint16_t)(((uint16_t)(x)) << SIM_PSWR1_DACB_SHIFT)) & SIM_PSWR1_DACB_MASK)
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

#define SIM_NVMOPT2L_ROSC_200K_FTRIM_MASK        (0x1FFU)
#define SIM_NVMOPT2L_ROSC_200K_FTRIM_SHIFT       (0U)
/*! ROSC_200K_FTRIM - 200 kHz Relaxation Oscillator Frequency Trim */
#define SIM_NVMOPT2L_ROSC_200K_FTRIM(x)          (((uint16_t)(((uint16_t)(x)) << SIM_NVMOPT2L_ROSC_200K_FTRIM_SHIFT)) & SIM_NVMOPT2L_ROSC_200K_FTRIM_MASK)

#define SIM_NVMOPT2L_PMC_BGTRIM_MASK             (0xF000U)
#define SIM_NVMOPT2L_PMC_BGTRIM_SHIFT            (12U)
/*! PMC_BGTRIM - PMC Bandgap Trim */
#define SIM_NVMOPT2L_PMC_BGTRIM(x)               (((uint16_t)(((uint16_t)(x)) << SIM_NVMOPT2L_PMC_BGTRIM_SHIFT)) & SIM_NVMOPT2L_PMC_BGTRIM_MASK)
/*! @} */

/*! @name SCR0 - Software Control Register */
/*! @{ */

#define SIM_SCR0_SCR0_MASK                       (0xFFFFU)
#define SIM_SCR0_SCR0_SHIFT                      (0U)
/*! SCR0 - Software Control Data */
#define SIM_SCR0_SCR0(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR0_SCR0_SHIFT)) & SIM_SCR0_SCR0_MASK)
/*! @} */

/*! @name SCR1 - Software Control Register 1 */
/*! @{ */

#define SIM_SCR1_SCR1_MASK                       (0xFFFFU)
#define SIM_SCR1_SCR1_SHIFT                      (0U)
/*! SCR1 - Software Control Data */
#define SIM_SCR1_SCR1(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR1_SCR1_SHIFT)) & SIM_SCR1_SCR1_MASK)
/*! @} */

/*! @name SCR2 - Software Control Register 2 */
/*! @{ */

#define SIM_SCR2_SCR2_MASK                       (0xFFFFU)
#define SIM_SCR2_SCR2_SHIFT                      (0U)
/*! SCR2 - Software Control Data */
#define SIM_SCR2_SCR2(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR2_SCR2_SHIFT)) & SIM_SCR2_SCR2_MASK)
/*! @} */

/*! @name SCR3 - Software Control Register 3 */
/*! @{ */

#define SIM_SCR3_SCR3_MASK                       (0xFFFFU)
#define SIM_SCR3_SCR3_SHIFT                      (0U)
/*! SCR3 - Software Control Data */
#define SIM_SCR3_SCR3(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR3_SCR3_SHIFT)) & SIM_SCR3_SCR3_MASK)
/*! @} */

/*! @name SCR4 - Software Control Register 4 */
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

/*! @name SCR6 - Software Control Register 5 */
/*! @{ */

#define SIM_SCR6_SCR6_MASK                       (0xFFFFU)
#define SIM_SCR6_SCR6_SHIFT                      (0U)
/*! SCR6 - Software Control Data */
#define SIM_SCR6_SCR6(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR6_SCR6_SHIFT)) & SIM_SCR6_SCR6_MASK)
/*! @} */

/*! @name SCR7 - Software Control Register 6 */
/*! @{ */

#define SIM_SCR7_SCR7_MASK                       (0xFFFFU)
#define SIM_SCR7_SCR7_SHIFT                      (0U)
/*! SCR7 - Software Control Data */
#define SIM_SCR7_SCR7(x)                         (((uint16_t)(((uint16_t)(x)) << SIM_SCR7_SCR7_SHIFT)) & SIM_SCR7_SCR7_MASK)
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

