/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_gpio"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to GPIO bases for each instance. */
static GPIO_Type *const s_gpioBases[] = GPIO_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to GPIO clocks for each instance. */
static const clock_ip_name_t s_gpioClocks[] = GPIO_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * API
 ******************************************************************************/
static uint32_t GPIO_GetInstance(GPIO_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_gpioBases); instance++)
    {
        if (s_gpioBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_gpioBases));

    return instance;
}

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
void GPIO_PinInit(GPIO_Type *base, gpio_pin_t ePin, const gpio_config_t *psConfig)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the module clock */
    CLOCK_EnableClock(s_gpioClocks[GPIO_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Set GPIO as Input mode at the beginning to avoid glitch . */
    GPIO_PinSetDirection(base, ePin, kGPIO_DigitalInput);

    /* Always configure GPIO to GPIO mode. */
    GPIO_PinSetPeripheralMode(base, ePin, psConfig->eMode);

    /* Set the peripheral mux if GPIO is configured as peripheral mode */
    if (psConfig->eMode == kGPIO_ModePeripheral)
    {
        GPIO_PinSetPeripheralMux(psConfig->eMux);
    }

    /* Configure GPIO Pin interrupt detection condition. */
    GPIO_PinSetInterruptConfig(base, ePin, psConfig->eInterruptMode);

    /* Configure Pull resistor for GPIO pin to Disable/Pull-Up/Pull-Down. */
    GPIO_PinSetPullResistorMode(base, ePin, psConfig->ePull);

    /* Configure the GPIO pin output mode as Push-Pull or Open-Drain. */
    GPIO_PinSetOutputMode(base, ePin, psConfig->eOutMode);

    /* Configure GPIO pin Fast/Slow slew rate when pin is configured as output. */
    GPIO_PinSetSlewRate(base, ePin, psConfig->eSlewRate);

    /* Configure High/Low drive strength when Pin is configured as output.*/
    GPIO_PinSetDriveStrength(base, ePin, psConfig->eDriveStrength);

    /* Set GPIO Pin as High/Low voltage level on Output.*/
    GPIO_PinWrite(base, ePin, psConfig->eOutLevel);

    /* Configure the GPIO pin as Output. */
    GPIO_PinSetDirection(base, ePin, psConfig->eDirection);
}
