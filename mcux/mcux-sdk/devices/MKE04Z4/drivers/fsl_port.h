/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_PORT_H_
#define _FSL_PORT_H_

#include "fsl_common.h"

/*!
 * @addtogroup port
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! Version 2.0.2. */
#define FSL_PORT_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*@}*/

#define FSL_PORT_FILTER_SELECT_BITMASK (0x3U) /*!< The IOFLT Filter selection bit mask . */
#define PORT_PINNUMS_EACHPORT 8U              /* PORT pin numbers in each PTA/PTB etc. */

/*! @brief Module or peripheral for port pin selection */
typedef enum _port_module_t
{
    kPORT_NMI = SIM_SOPT_NMIE_MASK,              /*!< NMI port pin select. */
    kPORT_RESET = SIM_SOPT_RSTPE_MASK,           /*!< RESET pin select. */
    kPORT_SWDE = SIM_SOPT_SWDE_MASK,             /*!< Single wire debug port pin. */
    kPORT_I2C0 = SIM_PINSEL_I2C0PS_MASK,         /*!< I2C0 Port pin select. */
    kPORT_SPI0 = SIM_PINSEL_SPI0PS_MASK,         /*!< SPI0 port pin select. */
    kPORT_UART0 = SIM_PINSEL_UART0PS_MASK,       /*!< UART0 port pin select. */
    kPORT_FTM0CH0 = SIM_PINSEL_FTM0PS0_MASK,     /*!< FTM0_CH0 port pin select. */
    kPORT_FTM0CH1 = SIM_PINSEL_FTM0PS1_MASK,     /*!< FTM0_CH1 port pin select. */
    kPORT_FTM2CH2 = SIM_PINSEL_FTM2PS2_MASK,     /*!< FTM2_CH2 port pin select. */
    kPORT_FTM2CH3 = SIM_PINSEL_FTM2PS3_MASK,     /*!< FTM2_CH3 port pin select. */
    kPORT_FTM0CLK = SIM_PINSEL_FTM0CLKPS_MASK,   /*!< FTM0 clock pin select. */
    kPORT_FTM2CLK = SIM_PINSEL_FTM2CLKPS_MASK,   /*!< FTM2 clock pin select. */
    kPORT_PWTCLK = (int)SIM_PINSEL_PWTCLKPS_MASK /*!< PWT clock pin select. */
} port_module_t;

/*! @brief Port type */
typedef enum _port_type_t
{
    kPORT_PTA = 0U, /*!< PORT PTA. */
    kPORT_PTB = 1U, /*!< PORT PTB. */
    kPORT_PTC = 2U  /*!< PORT PTC. */
} port_type_t;

/*! @brief Pin number, Notice this index enum has been deprecated and it will be removed in the next release. */
typedef enum _port_pin_index_t
{
    kPORT_PinIdx0 = 0U, /*!< PORT PIN index 0. */
    kPORT_PinIdx1 = 1U, /*!< PORT PIN index 1. */
    kPORT_PinIdx2 = 2U, /*!< PORT PIN index 2. */
    kPORT_PinIdx3 = 3U, /*!< PORT PIN index 3. */
    kPORT_PinIdx4 = 4U, /*!< PORT PIN index 4. */
    kPORT_PinIdx5 = 5U, /*!< PORT PIN index 5. */
    kPORT_PinIdx6 = 6U, /*!< PORT PIN index 6. */
    kPORT_PinIdx7 = 7U  /*!< PORT PIN index 7. */
} port_pin_index_t;

/*! @brief Pin selection */
typedef enum _port_pin_select_t
{
    kPORT_NMI_OTHERS = 0U,           /*!< PTB4/FTM2_CH4 etc function as PTB4/FTM2_CH4 etc */
    kPORT_NMI_NMIE = 1U,             /*!< PTB4/FTM2_CH4 etc function as NMI. */
    kPORT_RST_OTHERS = 0U,           /*!< PTA5/IRQ etc function as PTA5/IRQ etc. */
    kPORT_RST_RSTPE = 1U,            /*!< PTA5/IRQ etc function as REST. */
    kPORT_SWDE_OTHERS = 0U,          /*!< PTA4/ACMP0 etc function as PTA4/ACMP0 etc. */
    kPORT_SWDE_SWDE = 1U,            /*!< PTA4/ACMP0 etc function as SWD. */
    kPORT_I2C0_SCLPTA3_SDAPTA2 = 0U, /*!< I2C0_SCL and I2C0_SDA are mapped on PTA3 and PTA2, respectively. */
    kPORT_I2C0_SCLPTB7_SDAPTB6 = 1U, /*!< I2C0_SCL and I2C0_SDA are mapped on PTB7 and PTB6, respectively. */
    kPORT_SPI0_SCKPTB2_MOSIPTB3_MISOPTB4_PCSPTB5 = 0U, /*!< SPI0_SCK/MOSI/MISO/PCS0 are mapped on PTB2/PTB3/PTB4/PTB5.*/
    kPORT_SPI0_SCKPTA6_MOSIPTA7_MISOPTB1_PCSPTB0 =
        1U,                         /*!< SPI0_SCK/MOSI/MISO/PCS0 are mapped on PTA6/PTA7/PTB1/PTB0. */
    kPORT_UART0_RXPTB0_TXPTB1 = 0U, /*!< UART0_RX and UART0_TX are mapped on PTB0 and PTB1. */
    kPORT_UART0_RXPTA2_TXPTA3 = 1U, /*!< UART0_RX and UART0_TX are mapped on PTA2 and PTA3. */
    kPORT_FTM0_CH0_PTA0 = 0U,       /*!< FTM0_CH0 channels are mapped on PTA0. */
    kPORT_FTM0_CH0_PTB2 = 1U,       /*!< FTM0_CH0 channels are mapped on PTB2. */
    kPORT_FTM0_CH1_PTA1 = 0U,       /*!< FTM0_CH1 channels are mapped on PTA1. */
    kPORT_FTM0_CH1_PTB3 = 1U,       /*!< FTM0_CH1 channels are mapped on PTB3. */
    kPORT_FTM2_CH2_PTC2 = 0U,       /*!< FTM2_CH2 channels are mapped on PTC2. */
    kPORT_FTM2_CH2_PTC4 = 1U,       /*!< FTM2_CH2 channels are mapped on PTD2. */
    kPORT_FTM2_CH3_PTC3 = 0U,       /*!< FTM2_CH3 channels are mapped on PTC3. */
    kPORT_FTM2_CH3_PTC5 = 1U,       /*!< FTM2_CH3 channels are mapped on PTC5. */
    kPORT_FTM0CLK_TCLK1 = 0U,       /*!< FTM0 CLK using the TCLK1 pin. */
    kPORT_FTM0CLK_TCLK2 = 1U,       /*!< FTM0 CLK using the TCLK2 pin. */
    kPORT_FTM2CLK_TCLK1 = 0U,       /*!< FTM2 CLK using the TCLK1 pin. */
    kPORT_FTM2CLK_TCLK2 = 1U,       /*!< FTM2 CLK using the TCLK2 pin. */
    kPORT_PWTCLK_TCLK1 = 0U,        /*!< PWT CLK using the TCLK1 pin. */
    kPORT_PWTCLK_TCLK2 = 1U,        /*!< PWT CLK using the TCLK2 pin. */
} port_pin_select_t;

/*! @brief The PORT pins for input glitch filter configure */
typedef enum _port_filter_pin_t
{
    kPORT_FilterPTA = PORT_IOFLT_FLTA_SHIFT,     /*!< Filter for input from PTA. */
    kPORT_FilterPTB = PORT_IOFLT_FLTB_SHIFT,     /*!< Filter for input from PTB. */
    kPORT_FilterPTC = PORT_IOFLT_FLTC_SHIFT,     /*!< Filter for input from PTC. */
    kPORT_FilterIIC = PORT_IOFLT_FLTIIC_SHIFT,   /*!< Filter for input from I2C. */
    kPORT_FilterFTM0 = PORT_IOFLT_FLTFTM0_SHIFT, /*!< Filter for input from FTM0. */
    kPORT_FilterPWT = PORT_IOFLT_FLTPWT_SHIFT,   /*!< Filter for input from PWT. */
    kPORT_FilterRST = PORT_IOFLT_FLTRST_SHIFT,   /*!< Filter for input from RESET/IRQ. */
    kPORT_FilterKBI0 = PORT_IOFLT_FLTKBI0_SHIFT, /*!< Filter for input from KBI0. */
    kPORT_FilterKBI1 = PORT_IOFLT_FLTKBI1_SHIFT, /*!< Filter for input from KBI1. */
    kPORT_FilterNMI = PORT_IOFLT_FLTNMI_SHIFT,   /*!< Filter for input from NMI. */
} port_filter_pin_t;

/*! @brief The Filter selection for input pins */
typedef enum _port_filter_select_t
{
    kPORT_BUSCLK_OR_NOFILTER =
        0U,                /*!< Filter section BUSCLK for PTA~PTC, No filter for REST/KBI0/KBI1/NMI/PWT/FTM0/I2C. */
    kPORT_FILTERDIV1 = 1U, /*!< Filter Division Set 1. */
    kPORT_FILTERDIV2 = 2U, /*!< Filter Division Set 2. */
    kPORT_FILTERDIV3_OR_BUSCLK = 3U /*!< Filter Division Set 3. */
} port_filter_select_t;

/*! @brief Port pin for high driver enable/disable control. */
typedef enum _port_highdrive_pin_t
{
    kPORT_HighDrive_PTB5 = PORT_HDRVE_PTB5_MASK, /*!< PTB5. */
    kPORT_HighDrive_PTC1 = PORT_HDRVE_PTC1_MASK, /*!< PTC1. */
    kPORT_HighDrive_PTC5 = PORT_HDRVE_PTC5_MASK  /*!< PTC5. */
} port_highdrive_pin_t;

/*******************************************************************************
* API
******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*! @name Configuration */
/*@{*/

/*!
 * @brief Selects pin for modules.
 *
 * This API is used to select the port pin for the module with multiple port pin
 * selection. For example the FTM Channel 0 can be mapped to ether PTA0 or PTB2.
 * Select FTM channel 0 map to PTA0 port pin as:
 * @code
 * PORT_SetPinSelect(kPORT_FTM0CH0, kPORT_FTM0_CH0_PTA0);
 * @endcode
 *
 * @note： This API doesn't support to select specified ALT for a given port pin.
 * The ALT feature is automatically selected by hardware according to the
 * ALT priority:
 *     Low -----> high:
 *     Alt1, Alt2, …
 * when peripheral modules has been enabled.
 *
 * If you want to select a specified ALT for a given port pin, please add two more
 * steps after calling PORT_SetPinSelect:
 * 1. Enable module or the port control in the module for the ALT you want to select.
 *   For I2C ALT feature:all port enable is controlled by the module enable, so
 *   set IICEN in I2CX_C1 to enable the port pins for I2C feature.
 *   For KBI ALT feature:each port pin is controlled independently by each bit in KBIx_PE.
 *   set related bit in this register to enable the KBI feature in the port pin.
 * 2. Make sure there is no module enabled with higher priority than the ALT module feature
 *  you want to select.
 *
 * @param module   Modules for pin selection.
 *        For NMI/RST module are write-once attribute after reset.
 * @param pin   Port pin selection for modules.
 *
 */
void PORT_SetPinSelect(port_module_t module, port_pin_select_t pin);

/*!
 * @brief Selects the glitch filter for input pins.
 *
 * @param base   PORT peripheral base pointer.
 * @param port   PORT pin, see "port_filter_pin_t".
 * @param filter  Filter select, see "port_filter_select_t".
 */
static inline void PORT_SetFilterSelect(PORT_Type *base, port_filter_pin_t port, port_filter_select_t filter)
{
    uint32_t fltReg;

    /* Clear the filed to zero. */
    fltReg = base->IOFLT & ~((uint32_t)FSL_PORT_FILTER_SELECT_BITMASK << (uint32_t)port);
    /* Set the filter selection. */
    base->IOFLT = ((uint32_t)filter << (uint32_t)port) | fltReg;
}

/*!
 * @brief Sets the width threshold for glitch filter division set 1.
 *`
 * @param base   PORT peripheral base pointer.
 * @param threshold PORT glitch filter width threshold, take refer to reference manual for detail information.
 *        0  -   LPOCLK
 *        1  -   LPOCLK/2
 *        2  -   LPOCLK/4
 *        3  -   LPOCLK/8
 *        4  -   LPOCLK/16
 *        5  -   LPOCLK/32
 *        6  -   LPOCLK/64
 *        7  -   LPOCLK/128
 */
static inline void PORT_SetFilterDIV1WidthThreshold(PORT_Type *base, uint8_t threshold)
{
    uint32_t fltReg;

    fltReg = base->IOFLT & ~PORT_IOFLT_FLTDIV1_MASK;
    base->IOFLT = fltReg | PORT_IOFLT_FLTDIV1(threshold);
}

/*!
 * @brief Sets the width threshold for glitch filter division set 2.
 *`
 * @param base   PORT peripheral base pointer.
 * @param threshold PORT glitch filter width threshold, take refer to reference manual for detail information.
 *        0  -   BUSCLK/32
 *        1  -   BUSCLK/64
 *        2  -   BUSCLK/128
 *        3  -   BUSCLK/256
 *        4  -   BUSCLK/512
 *        5  -   BUSCLK/1024
 *        6  -   BUSCLK/2048
 *        7  -   BUSCLK/4096
 */
static inline void PORT_SetFilterDIV2WidthThreshold(PORT_Type *base, uint8_t threshold)
{
    uint32_t fltReg;

    fltReg = base->IOFLT & ~PORT_IOFLT_FLTDIV2_MASK;
    base->IOFLT = fltReg | PORT_IOFLT_FLTDIV2(threshold);
}

/*!
 * @brief Sets the width threshold for glitch filter division set 3.
 *`
 * @param base   PORT peripheral base pointer.
 * @param threshold PORT glitch filter width threshold, take refer to reference manual for detail information.
 *        0  -   BUSCLK/2
 *        1  -   BUSCLK/4
 *        2  -   BUSCLK/8
 *        3  -   BUSCLK/16
 */
static inline void PORT_SetFilterDIV3WidthThreshold(PORT_Type *base, uint8_t threshold)
{
    uint32_t fltReg;

    fltReg = base->IOFLT & ~PORT_IOFLT_FLTDIV3_MASK;
    base->IOFLT = fltReg | PORT_IOFLT_FLTDIV3(threshold);
}

/*!
 * @brief Enables or disables the port pull up.
 *
 * @param base   PORT peripheral base pointer.
 * @param port   PORT type, such as PTA/PTB/PTC etc, see "port_type_t".
 * @param num    PORT pin number, such as 0, 1, 2....
 *               For PTC, there are only six pins from 0 ~ 5, the PTC6, PTC7 are not exists in this device.
 *               so when set PTC please don't set the 6 and 7, take refer to the reference manual.
 * @param enable  Enable or disable the pull up feature switch.
 */
static inline void PORT_SetPinPullUpEnable(PORT_Type *base, port_type_t port, uint8_t num, bool enable)
{
    if (enable)
    {
        /* Enable the pull up */
        base->PUEL |= (1UL << (PORT_PINNUMS_EACHPORT * (uint32_t)port + (uint32_t)num));
    }
    else
    {
        /* Disable the pull up */
        base->PUEL &= ~(1UL << (PORT_PINNUMS_EACHPORT * (uint32_t)port + (uint32_t)num));
    }
}

/*!
 * @brief Set High drive for port pins.
 *
 * @param base PORT peripheral base pointer.
 * @param pin PORT pin support high drive.
 * @param enable Enable or disable the high driver feature switch.
 */
static inline void PORT_SetHighDriveEnable(PORT_Type *base, port_highdrive_pin_t pin, bool enable)
{
    if (enable)
    {
        base->HDRVE |= (uint32_t)pin;
    }
    else
    {
        base->HDRVE &= ~(uint32_t)pin;
    }
}

/*@}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* _FSL_PORT_H_ */
