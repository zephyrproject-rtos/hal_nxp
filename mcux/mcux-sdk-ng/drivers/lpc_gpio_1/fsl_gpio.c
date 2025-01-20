/*
 * Copyright 2018, 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpio.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpc_gpio_1"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map FGPIO instance number to clock name. */
static const clock_ip_name_t s_gpioClockName[] = GPIO_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Prototypes
 ************ ******************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Initializes the GPIO peripheral.
 *
 * This function ungates the GPIO clock.
 *
 * param base   GPIO peripheral base pointer.
 * param port   GPIO port number.
 */
void GPIO_PortInit(GPIO_Type *base, uint32_t port)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    assert(port < ARRAY_SIZE(s_gpioClockName));

    /* Upgate the GPIO clock */
    CLOCK_EnableClock(s_gpioClockName[port]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Initializes the GPIO peripheral.
 *
 * This function ungates the GPIO clock.
 *
 * param base   GPIO peripheral base pointer.
 * param pin	  GPIO pin number
 * param pinInterruptMode  GPIO interrupt mode
 */
void GPIO_PinSetInterruptConfig(GPIO_Type *base, uint32_t pin, gpio_interrupt_mode_t pinInterruptMode)
{
    uint32_t pinmask = 0;
    /* Register reset to default value */
    base->IMSC &= ~(1U << pin);
    pinmask = (0xFFFU & (1U << pin));
    /* Register reset to default value */
    switch (pinInterruptMode)
    {
        case (kGPIO_IntLowLevel):
            base->IS |= pinmask;
            base->IEV &= ~pinmask;
            break;
        case (kGPIO_IntHighLevel):
            base->IS |= pinmask;
            base->IEV |= pinmask;
            break;
        case (kGPIO_IntRisingEdge):
            base->IS &= ~pinmask;
            base->IEV |= pinmask;
            break;
        case (kGPIO_IntFallingEdge):
            base->IS &= ~pinmask;
            base->IEV &= ~pinmask;
            break;
        case (kGPIO_IntRisingOrFallingEdge):
            base->IBE |= pinmask;
            break;
        case (kGPIO_IntDisabled):
        default:
            break;
    }
}

/*!
 * brief Initializes a GPIO pin used by the board.
 *
 * To initialize the GPIO, define a pin configuration, either input or output, in the user file.
 * Then, call the GPIO_PinInit() function.
 *
 * This is an example to define an input pin or output pin configuration:
 * code
 * // Define a digital input pin configuration,
 * gpio_pin_config_t config =
 * {
 *   kGPIO_DigitalInput,
 *   0,
 * }
 * //Define a digital output pin configuration,
 * gpio_pin_config_t config =
 * {
 *   kGPIO_DigitalOutput,
 *   0,
 * }
 * endcode
 *
 * param base   GPIO peripheral base pointer(Typically GPIO)
 * param pin    GPIO pin number
 * param config GPIO pin configuration pointer
 */
void GPIO_PinInit(GPIO_Type *base, uint32_t pin, const gpio_pin_config_t *Config)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint8_t port;
    for (port = 0; port < ARRAY_SIZE(s_gpioClockName); port++)
    {
        /* Upgate the GPIO clock */
        CLOCK_EnableClock(s_gpioClockName[port]);
    }
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Configure GPIO pin direction */
    if (Config->direction == kGPIO_DigitalInput)
    {
        base->DIR &= ~(1U << pin);
    }
    else
    {
        /* Set default output value */
        if (Config->outputLogic == 0U)
        {
            GPIO_PinWrite(base, pin, Config->outputLogic);
        }
        else
        {
            GPIO_PinWrite(base, pin, !Config->outputLogic);
        }
        /* Set pin direction */
        base->DIR |= 1U << pin;
    }
}
