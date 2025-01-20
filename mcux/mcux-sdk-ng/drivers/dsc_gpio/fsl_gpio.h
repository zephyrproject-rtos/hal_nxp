/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_GPIO_H_
#define FSL_GPIO_H_

#include "fsl_common.h"

/*!
 * @defgroup gpio GPIO: General-Purpose Input/Output Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief GPIO driver version. */
#define FSL_GPIO_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * GPIO peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup gpio_driver_log The Driver Change Log
 * @ingroup gpio
 * @{
 * The current GPIO driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *    - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup gpio_intro GPIO Peripheral and Driver Overview
 * @ingroup gpio
 * @brief Content including 1) peripheral features; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features
 * ==================================================
 *
 *  Features
 *  ---------
 *  + A GPIO pin can be configured in different operation modes
 *      - As GPIO input with or without pull resistor
 *      - As GPIO output with push-pull mode or open-drain mode
 *      - As a peripheral pin when multiplexed with another module
 *
 *  + GPIO pins are placed on SoC in groups of one to 16 bits, called ports and designated as A, B, C and so on.
 *	  For available pins and port, it is different from SoC to SoC, please refer to SoC's data sheet for the specific
 *    definition of each GPIO port on the chip.
 *
 *  + Pin functionality muxing
 *      - GPIO pin can be muxed as GPIO mode or peripheral mode. Usually GPIO peripheral set whether pin
 *        is configured as Peripheral or GPIO and SIM peripheral do with specific peripheral configuration.
 *      - Peripheral mode: The peripheral module controls the pin. However, if the pin is not configured as an analog
 *        input/output, drive strength, edge slew rate control, push-pull or open-drain output and pull resistor enable
 *        and type select remain controlled by GPIO registers.
 *      - GPIO mode: The GPIO module controls the pin. Any data output and input an be written to or read from GPIO data
 *        registers. Pull resistor enables and type select are controlled by a GPIO register. GPIO pins can generated
 *        the edge interrupt and insert the software interrupt.
 *
 *  + GPIO pin configuration
 *      - Individual pull resistor enable/disable and type configuration for either GPIO mode or Peripheral mode.
 *      - Individual selection of output push-pull mode or open-drain mode.
 *      - Individual output drive strength control for each pin.
 *      - Individual output edge slew rate control for each pin to reduce switch noise.
 *      - Ability to monitor each pins' logic when pin is in either GPIO mode or peripheral mode by using raw
 *        data(RDATA) register.
 *
 *  + Pin Interrupt
 *      - Each pin has the ability to generate an interrupt with programmable rising or falling edge detection.
 *      - Each pin can generate an interrupt from software interrupt which usually set by user
 *
 *  + 5V tolerance.
 *
 * How this driver is designed to make this peripheral work
 * ===========================================================
 * This driver provide multiple definitions/functions to tell the configuration operation for each GPIO Pin/Port. Here
 * are several important definition and parameters usage to note
 *
 * + Most of API are requiring user provide parameter for the base address of GPIO port and pin. User provide the GPIOA
 *   like base address pointer to specify which GPIO PORT to operate with and provide the @ref gpio_pin_t to tell which
 *   Pin to operate. However, as mentioned in features section, though each PORT can get 16 pin groups but it is not
 *   necessary all these 16 pins are available in the SoC user is using. User need be quite careful to configure only
 *   the available pin. Driver is able to be created with enumeration to get only exited pin listed but it may reduce
 *   performance thus this way is not adopted.
 *
 * + 2 kinds of API sets are provided in this driver. One is for a single pin and another is for whole PORT. PORT API
 *   can operate whole port with synchronization satisfied. All Pin APIs are actually implemented by invoking PORT API
 *   cause these pin stuff are actually provided in PORT level from aspect of register arrangement and layout. Pin API
 *   require single pin specified by @ref gpio_pin_t and PORT API require multiple pins information that user can OR
 *   several pins and provide it as parameter. E.g. kGPIO_Pin0 | kGPIO_Pin1 means operation upon Pin 0 and Pin 1 in the
 *   specified PORT.
 *
 *  + Initialization and De-initialization Interfaces
 *      - Configure the GPIO to certain state with all feature covered.
 *      - Only Pin API is provided
 *
 *  + Pin MUX Interfaces
 *      - Configure the GPIO pin as GPIO or peripheral MUX functionalities. Note that GPIO driver will access the
 *      SIM registers to do all necessary PIN MUX configuration to offer better user experience.
 *      - Only Pin API is provided
 *
 *  + GPIO Pin Configuration Interfaces
 *      - Functions to configure the pin or port attribute.
 *      - Only Pin API is provided
 *
 *  + GPIO Write/Read/Toggle Interfaces
 *      - Functions to Write/Read/Clear/Set Toggle GPIO.
 *      - Note that Toggle is not atomic operation and it is implemented by read the value back and revert the output.
 *      - Pin/Port API are all provided
 *
 *  + GPIO Interrupt Interfaces
 *      - Interrupt Enable/Disable function
 *      - Check whether Interrupt is enabled
 *      - Assert/De-assert software interrupt which can generate interrupt by user.
 *      - Configure the interrupt detect condition as rising edge or falling edge.
 *      - Pin/Port API are all provided
 *
 *  + GPIO Status flags Interface
 *      - Get/Clear status flags
 *      - Separate APIs are provided by different status flags to achieve best performance.
 *      - Pin/Port API are all provided
 *
 *  How to use this driver
 *  =======================
 *  + Steps shall be done outside GPIO driver
 *      - SoC level interrupt controller configuration shall be configured/enabled in application codes if PIN is
 *        expected to generate interrupt on raising/falling edge or software interrupt.
 *      - Interrupt entry function shall be added in the application codes and interrupt handler function shall be
 *        placed in the entry function to make sure the implemented interrupt handling codes will be invoked on a
 *        generation of interrupt.
 *
 *  + Initialize the pin with expected features configured by calling GPIO_PinInit or alternatively user can call
 sperate
 *    functional API to initialize different pad attributes or peripheral mux seperately. This is oftenly used when user
 *    switch the GPIO configuration runtime for non-reset state.
 *
 *  + If GPIO is used as Interrupt Mode
 *      - Implement the interrupt handling function by calling GPIO_PortGetInterruptPendingStatusFlag and
 *        GPIO_PortGetEdgeDetectedStatusFlag to know which pin trigger the interrupt and clear that interrupt status to
 *        avoid next triggering with actually no new interrupt trigger condition happen.
 *
 *  Typical Use Case
 *  ================
 *  + GPIO Initialization:
 *    @code
           gpio_config_t sConfig = {
             .eDirection     = kGPIO_DigitalOutput;
             .eMode          = kGPIO_ModeGpio;
             .ePeripheralMux = 0U;  //When GPIO mode configuration is GPIO, this field is unused.
             .eOutMode       = kGPIO_OutputOpenDrain;
             .eSlewRate      = kGPIO_SlewRateFast;
             .eOutLevel      = kGPIO_OutputLow;
             .eDriveStrength = kGPIO_DriveStrengthLow;
             .ePull          = kGPIO_PullDisable;
             .eInterruptMode = kGPIO_InterruptDisable;
         }
          GPIO_PinInit(GPIOA, kGPIO_Pin1, &sConfig);
      @endcode
 *
 *  + Configure the multiplexing of GPIO pins to different peripheral:
 *    @code
            GPIO_PinSetPeripheralMode(GPIOD, kGPIO_Pin5, kGPIO_ModePeripheral);
            GPIO_PinSetPeripheralMux(kGPIO_Peri_D5_RXD2);
      @endcode
 *
 *  + Configure the GPIO pin as Input/Output for one pin:
 *    @code
            //Configure the GPIOA pin0 as Input.
            GPIO_PinSetDirection(GPIOA, kGPIO_Pin0, kGPIO_DigitalInput);
            //Configure the GPIOA pin0 as Output.
            GPIO_PinSetDirection(GPIOA, kGPIO_Pin0, kGPIO_DigitalOutput);
      @endcode
 *
 *  +  Toggle the GPIO output voltage level when configured as Output.
 *     @code
             GPIO_PinSetDirection(GPIOA, kGPIO_Pin0, kGPIO_DigitalOutput);
             GPIO_PinToggle((GPIOA, kGPIO_Pin0);
      @endcode
 *
 *  + Set GPIO Pin as High voltage level on Output.
 *    @code
        GPIO_PinWrite(GPIOA, kGPIO_Pin0, kGPIO_OutputHigh);
      @endcode
 *
 *  + Read High/Low voltage level for one GPIO pin from the pin or the data bus.
 *    @code
            if(GPIO_PinRead(GPIOA, kGPIO_Pin0)
     {
                //GPIOA Pin 0 is High
     }
      else
     {
      //GPIOA Pin 0 is Low
     }
      @endcode
 *
 *  + Enable interrupt detection for one pin.
 *    @code
           GPIO_PinEnableInterrupt(GPIOA, kGPIO_Pin0);
      @endcode
 *
 *  + Get interrupt pending status flags for one pin.
 *    @code
           if(GPIO_PinGetInterruptPendingStatusFlags(GPIOA,kGPIO_Pin0))
       {
              //Interrupt occurred on GPIOA Pin 0.
        }
           else
           {
              //No interrupt on GPIOA Pin 0.
           }
      @endcode
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Helper MACRO function to extract Port Index. (GPIOA, GPIOB, GPIOC, and so on.)
 *  The fields located in bit 8 - bit 11.*/
#define GPIO_MUX_ENUM_TO_PORT_INDEX(emux) (((uint16_t)(emux)&0xF00U) >> 0x08U)

/*! @brief Helper MACRO function to extract Pin Index. The fields located in bit 4 - bit 7. */
#define GPIO_MUX_ENUM_TO_PIN_INDEX(emux) (((uint16_t)(emux)&0xF0U) >> 0x04U)

/*! @brief Helper MACRO function to extract Pin mux config register value. The fields located in bit 0 - bit 1. */
#define GPIO_MUX_ENUM_TO_REG_VALUE(emux) ((uint16_t)(emux)&0x3U)

/*! @brief Helper MACRO function to extract Pin mux config mask. */
#define GPIO_MUX_ENUM_TO_PIN_MASK(emux)                                                                    \
    ((GPIO_MUX_ENUM_TO_PIN_INDEX(emux) < 8U) ? ((uint16_t)3U << (GPIO_MUX_ENUM_TO_PIN_INDEX(emux) * 2U)) : \
                                               ((uint16_t)3U << ((GPIO_MUX_ENUM_TO_PIN_INDEX(emux) - 8U) * 2U)))

/*! @brief Helper MACRO function to extract Pin mux config register value on a GPIO Pin. */
#define GPIO_MUX_ENUM_TO_PIN_VALUE(emux)                                                 \
    ((GPIO_MUX_ENUM_TO_PIN_INDEX(emux) < 8U) ?                                           \
         (GPIO_MUX_ENUM_TO_REG_VALUE(emux) << (GPIO_MUX_ENUM_TO_PIN_INDEX(emux) * 2U)) : \
         (GPIO_MUX_ENUM_TO_REG_VALUE(emux) << ((GPIO_MUX_ENUM_TO_PIN_INDEX(emux) - 8U) * 2U)))

/*! @brief GPIO Pin identifier with each pin get a unique bit thus they can be ORed. */
typedef enum _gpio_pin
{
    kGPIO_Pin0  = (0x1U << 0U),  /*!< GPIO PORT Pin  0. */
    kGPIO_Pin1  = (0x1U << 1U),  /*!< GPIO PORT Pin  1. */
    kGPIO_Pin2  = (0x1U << 2U),  /*!< GPIO PORT Pin  2. */
    kGPIO_Pin3  = (0x1U << 3U),  /*!< GPIO PORT Pin  3. */
    kGPIO_Pin4  = (0x1U << 4U),  /*!< GPIO PORT Pin  4. */
    kGPIO_Pin5  = (0x1U << 5U),  /*!< GPIO PORT Pin  5. */
    kGPIO_Pin6  = (0x1U << 6U),  /*!< GPIO PORT Pin  6. */
    kGPIO_Pin7  = (0x1U << 7U),  /*!< GPIO PORT Pin  7. */
    kGPIO_Pin8  = (0x1U << 8U),  /*!< GPIO PORT Pin  8. */
    kGPIO_Pin9  = (0x1U << 9U),  /*!< GPIO PORT Pin  9. */
    kGPIO_Pin10 = (0x1U << 10U), /*!< GPIO PORT Pin 10. */
    kGPIO_Pin11 = (0x1U << 11U), /*!< GPIO PORT Pin 11. */
    kGPIO_Pin12 = (0x1U << 12U), /*!< GPIO PORT Pin 12. */
    kGPIO_Pin13 = (0x1U << 13U), /*!< GPIO PORT Pin 13. */
    kGPIO_Pin14 = (0x1U << 14U), /*!< GPIO PORT Pin 14. */
    kGPIO_Pin15 = (0x1U << 15U), /*!< GPIO PORT Pin 15. */
} gpio_pin_t;

/*! @brief GPIO Pin peripheral/gpio mode option. */
typedef enum _gpio_peripheral_mode
{
    kGPIO_ModeGpio       = 0U, /*!< Set GPIO pin as GPIO Mode. */
    kGPIO_ModePeripheral = 1U, /*!< Set GPIO pin as Peripheral Mode. */
} gpio_peripheral_mode_t;

/*! @brief GPIO Pin input/output direction option. */
typedef enum _gpio_direction
{
    kGPIO_DigitalInput  = 0U, /*!< Set GPIO pin as digital input. */
    kGPIO_DigitalOutput = 1U, /*!< Set GPIO pin as digital output. */
} gpio_direction_t;

/*! @brief GPIO Pin pull resistor mode option. */
typedef enum _gpio_pull_mode
{
    kGPIO_PullDown    = 0U, /*!< Internal pull-down resistor is enabled. */
    kGPIO_PullUp      = 1U, /*!< Internal pull-up resistor is enabled. */
    kGPIO_PullDisable = 2U, /*!< Internal pull-up/down resistor is disabled. */
} gpio_pull_mode_t;

/*! @brief GPIO Pin output mode option. */
typedef enum _gpio_output_mode
{
    kGPIO_OutputOpenDrain = 0U, /*!< Open drain output mode. */
    kGPIO_OutputPushPull  = 1U, /*!< Push pull output mode. */
} gpio_output_mode_t;

/*! @brief GPIO Pin output High/Low level option. */
typedef enum _gpio_output_level
{
    kGPIO_OutputLow  = 0U, /*!< Set GPIO pin output low voltage level. */
    kGPIO_OutputHigh = 1U, /*!< Set GPIO pin output high voltage level. */
} gpio_output_level_t;

/*! @brief GPIO Pin output Fast/Slow slew rate option. */
typedef enum _gpio_output_slew_rate
{
    kGPIO_SlewRateFast = 0U, /*!< Set GPIO pin output Fast slew rate. */
    kGPIO_SlewRateSlow = 1U, /*!< Set GPIO pin output Slow slew rate. */
} gpio_output_slew_rate_t;

/*! @brief GPIO Pin output High/Low drive strength option. */
typedef enum _gpio_output_drive_strength
{
    kGPIO_DriveStrengthLow  = 0U, /*!< Set GPIO pin output Low-drive strength. */
    kGPIO_DriveStrengthHigh = 1U, /*!< Set GPIO pin output High-drive strength. */
} gpio_output_drive_strength_t;

/*! @brief GPIO Pin interrupt detect option. */
typedef enum _gpio_interrupt_mode
{
    kGPIO_InterruptRisingEdge  = 0x0U, /*!< Interrupt on rising edge. */
    kGPIO_InterruptFallingEdge = 0x1U, /*!< Interrupt on falling edge. */
    kGPIO_InterruptDisable     = 0x2U, /*!< Interrupt is disabled. */
} gpio_interrupt_mode_t;

/*! @brief GPIO Pin configuration covering all configurable fields when GPIO is configured in GPIO mode. */
typedef struct _gpio_config
{
    /* GPIO Pin General configuration. */
    gpio_direction_t eDirection; /*!< GPIO direction, input or output */

    /* GPIO Mode configuration */
    gpio_peripheral_mode_t eMode; /*!< GPIO mode as peripheral or GPIO */
    gpio_peripheral_mux_t eMux;   /*!< Set the peripheral type if GPIO is configured as peripheral */

    /* GPIO pin configuration */
    gpio_output_mode_t eOutMode;                 /*!< GPIO Open-Drain/Push-Pull output mode. */
    gpio_output_slew_rate_t eSlewRate;           /*!< GPIO Fast/Slow slew rate output mode. */
    gpio_output_level_t eOutLevel;               /*!< GPIO Output High/Low level. */
    gpio_output_drive_strength_t eDriveStrength; /*!< GPIO output Drive strength High/Low. */
    gpio_pull_mode_t ePull;                      /*!< GPIO Pull resistor mode configuration. */
    gpio_interrupt_mode_t eInterruptMode;        /*!< GPIO interrupt detection condition configuration. */
} gpio_config_t;

#if defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!
 * @name Initialization and De-initialization Interfaces
 * @{
 */

/*!
 * @brief Initializes a GPIO pin with provided structure @ref gpio_config_t covering all configuration fields.
 *
 * To initialize the GPIO, define a pin configuration, as either input or output, in the user file.
 * Then, call the GPIO_PinInit() function.
 *
 * @note If GPIO glitch is critical for your application, do not use this API instead using the API in GPIO
 * pin configuration interfaces to do with the glitch during GPIO mode transition in accordance to your
 * board design.
 *
 * This is function to configure all GPIO Pin configurable fields.
 * @code
        gpio_config_t sConfig = {
            .eDirection     = kGPIO_DigitalOutput,
            .eMode          = kGPIO_ModeGpio,
            .eOutMode       = kGPIO_OutputOpenDrain,
            .eSlewRate      = kGPIO_SlewRateFast,
            .eOutLevel      = kGPIO_OutputLow,
            .eDriveStrength = kGPIO_DriveStrengthLow,
            .ePull          = kGPIO_PullDisable,
            .eInterruptMode = kGPIO_InterruptDisable,
       }
        GPIO_PinInit(GPIOA, kGPIO_Pin1, &psConfig);
   @endcode
 *
 * @param base      GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @param psConfig  GPIO pin configuration pointer
 */
void GPIO_PinInit(GPIO_Type *base, gpio_pin_t ePin, const gpio_config_t *psConfig);

/*! @} */

/*!
 * @name GPIO Peripheral Mode Interfaces
 * @{
 */

/*!
 * @brief Configure the GPIO Pin as Peripheral mode or GPIO mode for one pin.
 *
 * Configure GPIO can be configured as Peripheral mode or GPIO mode for one pin.
 *
 * @param base  GPIO peripheral base pointer
 * @param ePin  GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *              in SoC and user need to check the data sheet.
 * @param eMode Peripheral mode or GPIO mode for this pin. See @ref gpio_peripheral_mode_t
 */
static inline void GPIO_PinSetPeripheralMode(GPIO_Type *base, gpio_pin_t ePin, gpio_peripheral_mode_t eMode)
{
    if (eMode == kGPIO_ModeGpio)
    {
        base->PER &= ~(uint16_t)ePin;
    }
    else
    {
        base->PER |= (uint16_t)ePin;
    }
}

/*!
 * @brief Configure the multiplexing of GPIO pins to different peripheral.
 *
 * Configure the MUX of GPIO pins to different peripheral functionality.
 * @note User still need to call the GPIO_PinSetPeripheralMode.
 *
 * @param eMux  GPIO peripheral MUX when configured as peripheral mode.
 */
#pragma bfsc force
static inline void GPIO_PinSetPeripheralMux(gpio_peripheral_mux_t eMux)
{
    if (GPIO_MUX_ENUM_TO_PORT_INDEX(eMux) == 0U)
    {
        if (GPIO_MUX_ENUM_TO_PIN_INDEX(eMux) < 8U)
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSAL) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSAL > 0U))
            PeriphWriteBitGroup(SIM->GPSAL, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
        else
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSAH) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSAH > 0U))
            PeriphWriteBitGroup(SIM->GPSAH, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
    }
    else if (GPIO_MUX_ENUM_TO_PORT_INDEX(eMux) == 1U)
    {
        if (GPIO_MUX_ENUM_TO_PIN_INDEX(eMux) < 8U)
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSBL) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSBL > 0U))
            PeriphWriteBitGroup(SIM->GPSBL, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
        else
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSBH) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSBH > 0U))
            PeriphWriteBitGroup(SIM->GPSBH, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
    }
    else if (GPIO_MUX_ENUM_TO_PORT_INDEX(eMux) == 2U)
    {
        if (GPIO_MUX_ENUM_TO_PIN_INDEX(eMux) < 8U)
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSCL) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSCL > 0U))
            PeriphWriteBitGroup(SIM->GPSCL, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
        else
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSCH) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSCH > 0U))
            PeriphWriteBitGroup(SIM->GPSCH, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
    }
    else if (GPIO_MUX_ENUM_TO_PORT_INDEX(eMux) == 3U)
    {
        if (GPIO_MUX_ENUM_TO_PIN_INDEX(eMux) < 8U)
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSDL) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSDL > 0U))
            PeriphWriteBitGroup(SIM->GPSDL, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
        else
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSDH) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSDH > 0U))
            PeriphWriteBitGroup(SIM->GPSDH, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
    }
    else if (GPIO_MUX_ENUM_TO_PORT_INDEX(eMux) == 4U)
    {
        if (GPIO_MUX_ENUM_TO_PIN_INDEX(eMux) < 8U)
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSEL) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSEL > 0U))
            PeriphWriteBitGroup(SIM->GPSEL, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
        else
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSEH) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSEH > 0U))
            PeriphWriteBitGroup(SIM->GPSEH, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
    }
    else if (GPIO_MUX_ENUM_TO_PORT_INDEX(eMux) == 5U)
    {
        if (GPIO_MUX_ENUM_TO_PIN_INDEX(eMux) < 8U)
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSFL) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSFL > 0U))
            PeriphWriteBitGroup(SIM->GPSFL, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
        else
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSFH) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSFH > 0U))
            PeriphWriteBitGroup(SIM->GPSFH, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
    }
    else if (GPIO_MUX_ENUM_TO_PORT_INDEX(eMux) == 6U)
    {
        if (GPIO_MUX_ENUM_TO_PIN_INDEX(eMux) < 8U)
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSGL) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSGL > 0U))
            PeriphWriteBitGroup(SIM->GPSGL, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
        else
        {
#if (defined(FSL_FEATURE_SIM_PINMUX_HAS_GPSGH) && (FSL_FEATURE_SIM_PINMUX_HAS_GPSGH > 0U))
            PeriphWriteBitGroup(SIM->GPSGH, GPIO_MUX_ENUM_TO_PIN_MASK(eMux), GPIO_MUX_ENUM_TO_PIN_VALUE(eMux));
#endif
        }
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}
#pragma bfsc on

/*! @} */

/*!
 * @name GPIO Pin Configuration Interfaces
 * @{
 */

/*!
 * @brief Configure the GPIO pin as Input or Output for one pin.
 *
 * Configure the GPIO pin as Input or Output for one pin.
 *
 * @param base          GPIO peripheral base pointer
 * @param ePin          GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                      in SoC and user need to check the data sheet.
 * @param eDirection    Direction of GPIO pin. @ref gpio_direction_t
 */
static inline void GPIO_PinSetDirection(GPIO_Type *base, gpio_pin_t ePin, gpio_direction_t eDirection)
{
    if (eDirection == kGPIO_DigitalInput)
    {
        base->DDR &= ~(uint16_t)ePin;
    }
    else
    {
        base->DDR |= (uint16_t)ePin;
    }
}

/*!
 * @brief Configure GPIO pin output as Push-Pull or Open-Drain for one pin
 *
 * Configure GPIO pin output as Push-Pull or Open-Drain. This function applies while pin
 * is configured as output. See @ref gpio_direction_t and API GPIO_PinSetDirection.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @param eOutMode  Push-Pull/Open-Drain output mode. See @ref gpio_output_mode_t.
 */
static inline void GPIO_PinSetOutputMode(GPIO_Type *base, gpio_pin_t ePin, gpio_output_mode_t eOutMode)
{
    if (eOutMode == kGPIO_OutputOpenDrain)
    {
        base->PPMODE &= ~(uint16_t)ePin;
    }
    else
    {
        base->PPMODE |= (uint16_t)ePin;
    }
}

/*!
 * @brief Configure High/Low drive strength when Pin is configured as output for one pin.
 *
 * Configure High/Low drive strength when Pin is configured as output. See
 * @ref gpio_direction_t and API GPIO_PinSetDirection.
 *
 * @param base              GPIO peripheral base pointer
 * @param ePin              GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins
 * existed in SoC and user need to check the data sheet.
 * @param eDriveStrength    High/Low driver strength. See @ref gpio_output_drive_strength_t
 */
static inline void GPIO_PinSetDriveStrength(GPIO_Type *base,
                                            gpio_pin_t ePin,
                                            gpio_output_drive_strength_t eDriveStrength)
{
    if (eDriveStrength == kGPIO_DriveStrengthLow)
    {
        base->DRIVE &= ~(uint16_t)ePin;
    }
    else
    {
        base->DRIVE |= (uint16_t)ePin;
    }
}

/*!
 * @brief Configure GPIO pin Fast/Slow slew rate when pin is configured as output.
 *
 * Configure GPIO pin Fast/Slow slew rate when pin is configured as output. See
 * @ref gpio_direction_t and API GPIO_PinSetDirection.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @param eSlewRate Fast/Slow slewrate. See @ref gpio_output_slew_rate_t
 */
static inline void GPIO_PinSetSlewRate(GPIO_Type *base, gpio_pin_t ePin, gpio_output_slew_rate_t eSlewRate)
{
    if (eSlewRate == kGPIO_SlewRateFast)
    {
        base->SRE &= ~(uint16_t)ePin;
    }
    else
    {
        base->SRE |= (uint16_t)ePin;
    }
}

/*!
 * @brief Configure Pull resistor for GPIO pin to Disable/Pull-Up/Pull-Down.
 *
 * Configure Pull resistor for GPIO pin to Disable/Pull-Up/Pull-Down.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @param ePullMode Pull Mode as Disable/Pull-Up/Pull-Down. See @ref gpio_pull_mode_t
 */
static inline void GPIO_PinSetPullResistorMode(GPIO_Type *base, gpio_pin_t ePin, gpio_pull_mode_t ePullMode)
{
    if (ePullMode != kGPIO_PullDisable)
    {
        /* Configure the Pull Up/Down*/
        if (ePullMode == kGPIO_PullDown)
        {
            base->PUS &= ~(uint16_t)ePin;
        }
        else
        {
            base->PUS |= (uint16_t)ePin;
        }
        /* Enable the pull resistor. */
        base->PUR |= (uint16_t)ePin;
    }
    else
    {
        /* Disable the pull resistor. */
        base->PUR &= ~(uint16_t)ePin;
    }
}

/*! @} */

/*!
 * @name GPIO PIN/PORT Write/Read/Toggle Interfaces
 * @{
 */

/*!
 * @brief Set GPIO Pin as High/Low voltage level on Output.
 *
 * Set GPIO Pin as High/Low voltage level on Output.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @param eOutput   Output as High level or Low Level. See @ref gpio_output_level_t.
 */
static inline void GPIO_PinWrite(GPIO_Type *base, gpio_pin_t ePin, gpio_output_level_t eOutput)
{
    if (eOutput == kGPIO_OutputLow)
    {
        base->DR &= ~(uint16_t)ePin;
    }
    else
    {
        base->DR |= (uint16_t)ePin;
    }
}

/*!
 * @brief Set GPIO multiple pins output High voltage level without impact
 * pins.
 *
 * Set GPIO multiple pins output High voltage level without impact other pins. Multiple
 * pins are configured by OR enumerator from @ref gpio_pin_t
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortSet(GPIO_Type *base, uint16_t u16Pins)
{
    base->DR |= u16Pins;
}

/*!
 * @brief Output High voltage level for GPIO Pin when configured as Output.
 *
 * Output High voltage level for GPIO Pin when configured as Output.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 */
static inline void GPIO_PinSet(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortSet(base, (uint16_t)ePin);
}

/*!
 * @brief Set GPIO multiple pins belong to same PORT output Low voltage level when these pins
 * are configured as output.
 *
 * Set GPIO multiple pins belong to same PORT output Low voltage level when these pins are configured
 * as output. Multiple pins are configured by ORing enumerators from @ref gpio_pin_t
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortClear(GPIO_Type *base, uint16_t u16Pins)
{
    base->DR &= ~u16Pins;
}

/*!
 * @brief Output Low voltage level for GPIO Pin when configured as Output.
 *
 * Output Low voltage level for GPIO Pin when configured as Output.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 */
static inline void GPIO_PinClear(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortClear(base, (uint16_t)ePin);
}

/*!
 * @brief Toggle GPIO multiple pins belong to same PORT when these pins are configured as output.
 *
 * Toggle GPIO multiple pins belong to same PORT when these pins are configured as output.
 * Multiple pins are configured by ORing enumerators from @ref gpio_pin_t
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortToggle(GPIO_Type *base, uint16_t u16Pins)
{
    base->DR ^= u16Pins;
}

/*!
 * @brief Toggle the GPIO output voltage level when configured as Output.
 *
 * Toggle the GPIO output voltage level when configured as Output.
 *
 * @note  GPIO peripheral register do not get register to toggle directly. It is
 * implemented by read back the GPIO output level and write to the register with
 * reverted level.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 */

static inline void GPIO_PinToggle(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortToggle(base, (uint16_t)ePin);
}

/*!
 * @brief Read High/Low voltage level for multiple GPIO pins from the pin or the data bus.
 *
 * Read High/Low voltage level for multiple GPIO pins from the pin if the pin is configured
 * as input or the data bus.
 * When the device comes out of reset, GPIO pins are configured as inputs with internal
 * pull disabled. As a result, the reset value of this pin is undefined.
 * For different PORT,  the available pins number is different. User need use the return value
 * to OR with the @ref gpio_pin_t to decide whether that pin is logic high or low.
 * @code
 *      if (GPIO_PortRead(GPIOA) & (uint16_t)kGPIO_Pin0)
 *      {
 *          //GPIOA Pin 0 is High
 *      }
 *      else
 *      {
 *          //GPIOA Pin 0 is Low
 *      }
 * @endcode
 *
 * @param  base      GPIO peripheral base pointer
 * @return Voltage level for multiple GPIO pins from the pin or the data bus.
 */
static inline uint16_t GPIO_PortRead(GPIO_Type *base)
{
    return base->DR;
}

/*!
 * @brief Read High/Low voltage level for one GPIO pin from the pin or the data bus.
 *
 * Read High/Low voltage level from the pin if the pin is configured as input
 * or the data bus.
 * @note When the device comes out of reset, GPIO pins are configured as inputs with internal
 * pull disabled. As a result, the reset value of this pin is undefined.
 *
 * @param  base     GPIO peripheral base pointer
 * @param  ePin     GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @retval 1        Voltage level for one GPIO pin from the pin or the data bus is high.
 * @retval 0        Voltage level for one GPIO pin from the pin or the data bus is low.
 */
static inline uint8_t GPIO_PinRead(GPIO_Type *base, gpio_pin_t ePin)
{
    return (0U != (GPIO_PortRead(base) & (uint16_t)ePin)) ? 1U : 0U;
}

/*!
 * @brief Read Raw voltage high/low level data from the pins or peripheral bus for multiple
 * pins belong to same PORT.
 *
 * Read Raw voltage high/low level data from the pins or peripheral bus. Values are
 * not clocked and are subject to change at any time. Read several times to ensure
 * a stable value. The reset value of this register depends on the default PIN state.
 * User need use the return value to OR with the @ref gpio_pin_t to decide whether that
 * pin is logic high or low.
 * @code
 *      if (GPIO_PortReadRawData(GPIOA) & (uint16_t)kGPIO_Pin0)
 *      {
 *          //GPIOA Pin 0 is High
 *      }
 *      else
 *      {
 *          //GPIOA Pin 0 is Low
 *      }
 * @endcode
 *
 * @param  base      GPIO peripheral base pointer
 * @return Voltage high/low level data from the pins or peripheral bus for multiple
 *         pins belong to same PORT.
 */
static inline uint16_t GPIO_PortReadRawData(GPIO_Type *base)
{
    return base->RAWDATA;
}

/*!
 * @brief Read Raw logic level data from the pins or peripheral bus for one pin.
 *
 * Read Raw voltage high/low level data from the pins or peripheral bus. Values are
 * not clocked and are subject to change at any time. Read several times to ensure
 * a stable value. The reset value of this register depends on the default PIN state.
 *
 * @param  base     GPIO peripheral base pointer
 * @param  ePin     GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @retval 1        Raw voltage level data from the pins or peripheral bus is high.
 * @retval 0        Raw voltage level data from the pins or peripheral bus is low.
 */
static inline uint8_t GPIO_PinReadRawData(GPIO_Type *base, gpio_pin_t ePin)
{
    return (0U != (GPIO_PortReadRawData(base) & (uint16_t)ePin)) ? 1U : 0U;
}

/*! @} */

/*!
 * @name GPIO Interrupt Interfaces
 * @{
 */

/*!
 * @brief Configure GPIO Pin interrupt detection condition.
 *
 * Configure GPIO Pin interrupt detection condition
 *
 * @param base          GPIO peripheral base pointer
 * @param ePin          GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                      in SoC and user need to check the data sheet.
 * @param eIntConfig    Interrupt detection condition for rising edge/down edge or no detection. See
 *                      @ref gpio_interrupt_mode_t
 */
static inline void GPIO_PinSetInterruptConfig(GPIO_Type *base, gpio_pin_t ePin, gpio_interrupt_mode_t eIntConfig)
{
    if (eIntConfig != kGPIO_InterruptDisable)
    {
        /* Configure the Interrupt detection edge. */
        if (eIntConfig == kGPIO_InterruptRisingEdge)
        {
            base->IPOLR &= ~(uint16_t)ePin;
        }
        else
        {
            base->IPOLR |= (uint16_t)ePin;
        }
        /* Enable the Pin Interrupt*/
        base->IENR |= (uint16_t)ePin;
    }
    else
    {
        /* Disable the Pin Interrupt*/
        base->IENR &= (~(uint16_t)ePin);
    }
}

/*!
 * @brief Assert software interrupt for multiple pins belong to same port which will generate interrupt.
 *
 * This API is only for software testing of a software interrupt
 * capability. When the software interrupt is asserted, an interrupt is
 * generated. The interrupt is generated continually until this software
 * interrupt is de-asserted.
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortAssertSWInterrupts(GPIO_Type *base, uint16_t u16Pins)
{
    base->IAR |= u16Pins;
}

/*!
 * @brief De-Assert software interrupt for multiple pins belong to same port which will stop generating interrupt.
 *
 * This API is only for software testing of a software interrupt
 * capability.
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortDeassertSWInterrupts(GPIO_Type *base, uint16_t u16Pins)
{
    base->IAR &= ~u16Pins;
}

/*!
 * @brief Assert software interrupt for one pin which will generate interrupt.
 *
 * This API is only for software testing of a software interrupt
 * capability. When the software interrupt is asserted, an interrupt is
 * generated. The interrupt is generated continually until this software
 * interrupt is de-asserted.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 */
static inline void GPIO_PinAssertSWInterrupt(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortAssertSWInterrupts(base, (uint16_t)ePin);
}

/*!
 * @brief De-Assert software interrupt for one pin which will stop generating interrupt.
 *
 * This API is only for software testing of a software interrupt
 * capability.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 */
static inline void GPIO_PinDeassertSWInterrupt(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortDeassertSWInterrupts(base, (uint16_t)ePin);
}

/*!
 * @brief Enable interrupt detection for multiple pins belong to same port
 *
 * This API is to enable interrupt detection on rising edge or falling edge.
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortEnableInterrupts(GPIO_Type *base, uint16_t u16Pins)
{
    base->IENR |= u16Pins;
}

/*!
 * @brief Disable interrupt detection for multiple pins belong to same port.
 *
 * This API is to disable interrupt detection on rising edge or falling edge.
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortDisableInterrupts(GPIO_Type *base, uint16_t u16Pins)
{
    base->IENR &= ~u16Pins;
}

/*!
 * @brief Enable interrupt detection for one pin.
 *
 * This API is to enable interrupt detection on rising edge or falling edge.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 */
static inline void GPIO_PinEnableInterrupt(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortEnableInterrupts(base, (uint16_t)ePin);
}

/*!
 * @brief Disable interrupt detection for one pin.
 *
 * This API is to disable interrupt detection on rising edge or falling edge.
 *
 * @param base      GPIO peripheral base pointer
 * @param ePin      GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 */
static inline void GPIO_PinDisableInterrupt(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortDisableInterrupts(base, (uint16_t)ePin);
}

/*! @} */

/*!
 * @name GPIO Status Get/Clear Interfaces
 * @{
 */

/*!
 * @brief Get interrupt pending status flags all pins belong to same port.
 *
 * Get interrupt pending status flags for all pins belong to same port. User need to use
 * the @ref gpio_pin_t to OR with the return value, if the result is not 0, this flag is set.
 * otherwise, this flag is not set.
 *
 * @note this flags can only be cleared by calling GPIO_PortClearEdgeDetectedStatusFlag
 * if it is caused by edge detected or by calling GPIO_PortEnableSWInterrupt if it is caused
 * by SW interrupt.
 * @code
 *      if (GPIO_PortGetInterruptPendingStatusFlags(GPIOA) & (uint16_t)kGPIO_Pin0)
 *      {
 *          //Interrupt occurred on GPIOA Pin 0.
 *      }
 *      else
 *      {
 *          //No Interrupt on GPIOA Pin 0.
 *      }
 * @endcode
 *
 * @param  base      GPIO peripheral base pointer
 * @return Interrupt pending status flags all pins belong to same port.
 */
static inline uint16_t GPIO_PortGetInterruptPendingStatusFlags(GPIO_Type *base)
{
    return base->IPR;
}

/*!
 * @brief Get interrupt pending status flags for one pin.
 *
 * Get interrupt pending status flags for one pin.
 * @note this flags can only be cleared by calling GPIO_PortClearEdgeDetectedStatusFlag
 * if it is caused by edge detected or by calling GPIO_PortEnableSWInterrupt if it is caused
 * by SW interrupt.
 *
 * @param  base     GPIO peripheral base pointer
 * @param  ePin     GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @retval 1        Interrupt occurred.
 * @retval 0        No Interrupt.
 */
static inline uint16_t GPIO_PinGetInterruptPendingStatusFlags(GPIO_Type *base, gpio_pin_t ePin)
{
    return (0U != (GPIO_PortGetInterruptPendingStatusFlags(base) & (uint16_t)ePin)) ? 1U : 0U;
}

/*!
 * @brief Get Edge detected status flags for all pins belong to same port.
 *
 * Get edge detected status flags for all pins in the PORT. This status flag can only be detected
 * when interrupt detection is enabled by GPIO_PortEnableInterrupt or GPIO_PinEnableInterrupt.
 * @code
 *      if (GPIO_PortGetEdgeDetectedStatusFlags(GPIOA) & (uint16_t)kGPIO_Pin0)
 *      {
 *          //An edge detected on GPIOA Pin 0.
 *      }
 *      else
 *      {
 *          //No edge detected on GPIOA Pin 0.
 *      }
 * @endcode
 *
 * @param  base      GPIO peripheral base pointer
 * @return Detected edge status flags for all pins belong to same port.
 */
static inline uint16_t GPIO_PortGetEdgeDetectedStatusFlags(GPIO_Type *base)
{
    return base->IESR;
}

/*!
 * @brief Get Edge detected status flags for one pin.
 *
 * Get edge detected status flags for one pin. This status flag can only be detected when
 * interrupt detection is enabled by GPIO_PortEnableInterrupt or GPIO_PinEnableInterrupt.
 *
 * @param  base     GPIO peripheral base pointer
 * @param  ePin     GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *                  in SoC and user need to check the data sheet.
 * @retval 1        An edge detected.
 * @retval 0        No edge detected.
 */
static inline uint8_t GPIO_PinGetEdgeDetectedStatusFlag(GPIO_Type *base, gpio_pin_t ePin)
{
    return (0U != (GPIO_PortGetEdgeDetectedStatusFlags(base) & (uint16_t)ePin)) ? 1U : 0U;
}

/*!
 * @brief Clear Edge detected status flags for multiple pins belong to same port.
 *
 * Clear Edge Detected status flags for multiple pins belong to same port.
 *
 * @param base      GPIO peripheral base pointer
 * @param u16Pins   GPIO pins which is ORed by @ref gpio_pin_t. # kGPIO_Pin0 | kGPIO_Pin3
 *                  means Pin 0 and Pin 3.
 */
static inline void GPIO_PortClearEdgeDetectedStatusFlags(GPIO_Type *base, uint16_t u16Pins)
{
    base->IESR = u16Pins;
}

/*!
 * @brief Clear Edge detected status flags for one pin.
 *
 * Clear Edge Detected status flags for one pin.
 *
 * @param base  GPIO peripheral base pointer
 * @param ePin  GPIO pin identifier. User enumerator provided by @ref gpio_pin_t. Note that not all Pins existed
 *              in SoC and user need to check the data sheet.
 */
static inline void GPIO_PinClearEdgeDetectedStatusFlags(GPIO_Type *base, gpio_pin_t ePin)
{
    GPIO_PortClearEdgeDetectedStatusFlags(base, (uint16_t)ePin);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_GPIO_H_*/
