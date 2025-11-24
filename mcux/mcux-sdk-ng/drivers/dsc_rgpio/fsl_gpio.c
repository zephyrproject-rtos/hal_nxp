/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_rgpio"
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && \
    defined(GPIO_CLOCKS_ARRAY)
#define GPIO_DRIVER_HANDLE_CLOCK 1
#else
#define GPIO_DRIVER_HANDLE_CLOCK 0
#endif

#if defined(GPIO_RESETS_ARRAY)
#define GPIO_DRIVER_HANDLE_RESET 1
#else
#define GPIO_DRIVER_HANDLE_RESET 0
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if GPIO_DRIVER_HANDLE_CLOCK
/*! @brief Array to map FGPIO instance number to clock name. */
static const clock_ip_name_t s_gpioClockName[] = GPIO_CLOCKS_ARRAY;
#endif

#if GPIO_DRIVER_HANDLE_RESET
/* Reset array */
static const reset_ip_name_t s_gpioResets[] = GPIO_RESETS_ARRAY;
#endif

static GPIO_Type *const s_gpioBases[] = GPIO_BASE_PTRS;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the GPIO instance according to the GPIO base
 *
 * @param base    GPIO peripheral base pointer(PTA, PTB, PTC, etc.)
 * @retval GPIO instance
 */
static uint8_t GPIO_GetInstance(GPIO_Type *base);

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint8_t GPIO_GetInstance(GPIO_Type *base)
{
    uint8_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_gpioBases); instance++)
    {
        if (s_gpioBases[instance] == base)
        {
            break;
        }
    }

    return instance;
}

/*!
 * brief Initializes the GPIO peripheral.
 *
 * This function ungates the GPIO clock.
 *
 * param base   GPIO peripheral base pointer.
 */
status_t GPIO_PortInit(GPIO_Type *base)
{
    status_t status;

    uint8_t instance = GPIO_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_gpioBases))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
#if GPIO_DRIVER_HANDLE_CLOCK
        CLOCK_EnableGlock(s_gpioClockName[instance]);
#endif

#if defined(GPIO_RESETS_ARRAY)
        RESET_ReleasePeripheralReset(s_gpioResets[instance]);
#endif

        status = kStatus_Success;
    }

    return status;

}


/*!
 * brief Deinitializes the GPIO peripheral.
 *
 * param base   GPIO peripheral base pointer.
 */
status_t GPIO_PortDeinit(GPIO_Type *base)
{
    status_t status;

    uint8_t instance = GPIO_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_gpioBases))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
#if GPIO_DRIVER_HANDLE_CLOCK
        CLOCK_EnableGlock(s_gpioClockName[instance]);
#endif
        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Initializes a GPIO pin used by the board.
 *
 * To initialize the GPIO, define a pin configuration, as either input or output, in the user file.
 * Then, call the GPIO_PinInit() function.
 *
 * This is an example to define an input pin or an output pin configuration.
 * code
 * Define a digital input pin configuration,
 * gpio_pin_config_t config =
 * {
 *   kGPIO_DigitalInput,
 *   0,
 * }
 * Define a digital output pin configuration,
 * gpio_pin_config_t config =
 * {
 *   kGPIO_DigitalOutput,
 *   0,
 * }
 * endcode
 *
 * param base   GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param pin    GPIO port pin number
 * param config GPIO pin configuration pointer
 */
status_t GPIO_PinInit(GPIO_Type *base, uint8_t pin, const gpio_pin_config_t *config)
{
    assert(NULL != config);

    status_t status;

    status = GPIO_PortInit(base);

    if (kStatus_Success == status)
    {
        GPIO_PinWrite(base, pin, config->outputLogic);
        GPIO_PinSetDirection(base, pin, config->pinDirection);
    }

    return status;
}
