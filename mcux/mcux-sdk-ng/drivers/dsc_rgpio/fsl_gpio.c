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
    defined(GPIO_CLOCKS)
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
static const clock_ip_name_t s_gpioClockName[] = GPIO_CLOCKS;
#endif

#if GPIO_DRIVER_HANDLE_RESET
/* Reset array */
static const reset_ip_name_t s_gpioResets[] = GPIO_RESETS_ARRAY;
#endif

static GPIO_Type * GPIO_ATTR const s_gpioBases[] = GPIO_BASE_PTRS;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the GPIO instance according to the GPIO base
 *
 * @param base    GPIO peripheral base pointer(PTA, PTB, PTC, etc.)
 * @retval GPIO instance
 */
static uint8_t GPIO_GetInstance(GPIO_Type * GPIO_ATTR base);

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint8_t GPIO_GetInstance(GPIO_Type * GPIO_ATTR base)
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
status_t GPIO_PortInit(GPIO_Type * GPIO_ATTR base)
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
        CLOCK_EnableClock(s_gpioClockName[instance]);
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
status_t GPIO_PortDeinit(GPIO_Type * GPIO_ATTR base)
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
        CLOCK_DisableClock(s_gpioClockName[instance]);
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
status_t GPIO_PinInit(GPIO_Type * GPIO_ATTR base, uint8_t pin, const gpio_pin_config_t *config)
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

/*
 * brief Enable port input.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
void GPIO_PortInputEnable(GPIO_Type * GPIO_ATTR base, uint32_t mask)
{
    base->PIDR &= ~mask;
}

/*
 * brief Disable port input.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
void GPIO_PortInputDisable(GPIO_Type * GPIO_ATTR base, uint32_t mask)
{
    base->PIDR |= mask;
}

/*
 * brief Configure the GPIO pin as Input or Output for one pin.
 *
 * Configure the GPIO pin as Input or Output for one pin.
 *
 * param base          GPIO peripheral base pointer
 * param pin           GPIO pin identifier.
 * param direction     Direction of GPIO pin. @ref gpio_pin_direction_t
 */
void GPIO_PinSetDirection(GPIO_Type * GPIO_ATTR base, uint8_t pin, gpio_pin_direction_t direction)
{
    if (direction == kGPIO_DigitalInput)
    {
        base->PDDR &= ~(1UL << pin);
    }
    else
    {
        base->PDDR |= (1UL << pin);
    }
}

/*
 * brief Sets the output level of one GPIO pin to the logic 1 or 0.
 *
 * param base    GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param pin     GPIO pin number
 * param output  GPIO pin output logic level.
 *        - 0: corresponding pin output low-logic level.
 *        - 1: corresponding pin output high-logic level.
 */
void GPIO_PinWrite(GPIO_Type * GPIO_ATTR base, uint8_t pin, uint8_t output)
{
    assert(pin < GPIO_PDR_COUNT);

    base->PDR[pin] = output;
}

/*
 * brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
void GPIO_PortSet(GPIO_Type * GPIO_ATTR base, uint32_t mask)
{
    base->PSOR = mask;
}

/*
 * brief Sets the output level of the multiple GPIO pins to the logic 0.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
void GPIO_PortClear(GPIO_Type * GPIO_ATTR base, uint32_t mask)
{
    base->PCOR = mask;
}

/*
 * brief Reverses the current output logic of the multiple GPIO pins.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
void GPIO_PortToggle(GPIO_Type * GPIO_ATTR base, uint32_t mask)
{
    base->PTOR = mask;
}

/*
 * brief Reads the current input value of the GPIO port.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 */
uint32_t GPIO_PortRead(GPIO_Type * GPIO_ATTR base)
{
    return base->PDIR;
}

/*
 * brief Reads the current input value of the GPIO pin.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param pin     GPIO pin number
 * retval GPIO port input value
 *        - 0: corresponding pin input low-logic level.
 *        - 1: corresponding pin input high-logic level.
 */
uint8_t GPIO_PinRead(GPIO_Type * GPIO_ATTR base, uint8_t pin)
{
    assert(pin < GPIO_PDR_COUNT);

    return base->PDR[pin];
}

/*
 * brief Configures the gpio pin interrupt/DMA request.
 *
 * param base    GPIO peripheral base pointer.
 * param pin     GPIO pin number.
 * param config  GPIO pin interrupt configuration.
 *        - #kGPIO_InterruptStatusFlagDisabled: Interrupt/DMA request disabled.
 *        - #kGPIO_DMARisingEdge : DMA request on rising edge(if the DMA requests exit).
 *        - #kGPIO_DMAFallingEdge: DMA request on falling edge(if the DMA requests exit).
 *        - #kGPIO_DMAEitherEdge : DMA request on either edge(if the DMA requests exit).
 *        - #kGPIO_FlagRisingEdge : Flag sets on rising edge(if the Flag states exit).
 *        - #kGPIO_FlagFallingEdge : Flag sets on falling edge(if the Flag states exit).
 *        - #kGPIO_FlagEitherEdge : Flag sets on either edge(if the Flag states exit).
 *        - #kGPIO_InterruptLogicZero  : Interrupt when logic zero.
 *        - #kGPIO_InterruptRisingEdge : Interrupt on rising edge.
 *        - #kGPIO_InterruptFallingEdge: Interrupt on falling edge.
 *        - #kGPIO_InterruptEitherEdge : Interrupt on either edge.
 *        - #kGPIO_InterruptLogicOne   : Interrupt when logic one.
 *        - #kGPIO_ActiveHighTriggerOutputEnable : Enable active high-trigger output (if the trigger states exit).
 *        - #kGPIO_ActiveLowTriggerOutputEnable  : Enable active low-trigger output (if the trigger states exit).
 */
void GPIO_SetPinInterruptConfig(GPIO_Type * GPIO_ATTR base, uint8_t pin, gpio_interrupt_config_t config)
{
    base->ICR[pin] = (base->ICR[pin] & ~GPIO_ICR_IRQC_MASK) | GPIO_ICR_IRQC(config);
}

/*
 * brief Configures the gpio pin interrupt/DMA request/trigger output channel selection.
 *
 * param base    GPIO peripheral base pointer.
 * param pin     GPIO pin number.
 * param selection  GPIO pin interrupt output selection.
 *        - #kGPIO_InterruptOutput0: Interrupt/DMA request/trigger output 0.
 *        - #kGPIO_InterruptOutput1 : Interrupt/DMA request/trigger output 1.
 */
void GPIO_SetPinInterruptChannel(GPIO_Type * GPIO_ATTR base, uint8_t pin, gpio_interrupt_selection_t selection)
{
    base->ICR[pin] = (base->ICR[pin] & ~GPIO_ICR_IRQS_MASK) | GPIO_ICR_IRQS(selection);
}

/*
 * brief Read the GPIO interrupt status flags based on selected interrupt channel(IRQS).
 *
 * param base GPIO peripheral base pointer. (GPIOA, GPIOB, GPIOC, and so on.)
 * param channel '0' means select interrupt channel 0, '1' means select interrupt channel 1.
 * return The current GPIO's interrupt status flag based on the selected interrupt channel.
 *         '1' means the related pin's flag is set, '0' means the related pin's flag not set.
 *          For example, the return value 0x00010001 means the pin 0 and 17 have the interrupt pending.
 */
uint32_t GPIO_GpioGetInterruptChannelFlags(GPIO_Type * GPIO_ATTR base, uint8_t channel)
{
    assert(channel < GPIO_ISFR_COUNT);

    return base->ISFR[channel];
}

/*
 * brief Read individual pin's interrupt status flag.
 *
 * param base GPIO peripheral base pointer. (GPIOA, GPIOB, GPIOC, and so on)
 * param pin GPIO specific pin number.
 * return 1 means flag asserted, 0 means not.
 */
uint8_t GPIO_PinGetInterruptFlag(GPIO_Type * GPIO_ATTR base, uint8_t pin)
{
    return (uint8_t)((base->ICR[pin] & GPIO_ICR_ISF_MASK) >> GPIO_ICR_ISF_SHIFT);
}

/*
 * brief Clear GPIO individual pin's interrupt status flag.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on).
 * param pin GPIO specific pin number.
 */
void GPIO_PinClearInterruptFlag(GPIO_Type * GPIO_ATTR base, uint8_t pin)
{
    base->ICR[pin] |= GPIO_ICR_ISF_MASK;
}

/*
 * brief Clears GPIO pin interrupt status flags based on selected interrupt channel(IRQS).
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 * param channel '0' means select interrupt channel 0, '1' means select interrupt channel 1.
 */
void GPIO_GpioClearInterruptChannelFlags(GPIO_Type * GPIO_ATTR base, uint32_t mask, uint8_t channel)
{
    assert(channel < GPIO_ISFR_COUNT);
    base->ISFR[channel] = mask;
}

/*
 * brief Sets the GPIO interrupt configuration in PCR register for multiple pins.
 *
 * param base   GPIO peripheral base pointer.
 * param mask   GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 * param config  GPIO pin interrupt configuration.
 *        - #kGPIO_InterruptStatusFlagDisabled: Interrupt disabled.
 *        - #kGPIO_DMARisingEdge : DMA request on rising edge(if the DMA requests exit).
 *        - #kGPIO_DMAFallingEdge: DMA request on falling edge(if the DMA requests exit).
 *        - #kGPIO_DMAEitherEdge : DMA request on either edge(if the DMA requests exit).
 *        - #kGPIO_FlagRisingEdge : Flag sets on rising edge(if the Flag states exit).
 *        - #kGPIO_FlagFallingEdge : Flag sets on falling edge(if the Flag states exit).
 *        - #kGPIO_FlagEitherEdge : Flag sets on either edge(if the Flag states exit).
 *        - #kGPIO_InterruptLogicZero  : Interrupt when logic zero.
 *        - #kGPIO_InterruptRisingEdge : Interrupt on rising edge.
 *        - #kGPIO_InterruptFallingEdge: Interrupt on falling edge.
 *        - #kGPIO_InterruptEitherEdge : Interrupt on either edge.
 *        - #kGPIO_InterruptLogicOne   : Interrupt when logic one.
 *        - #kGPIO_ActiveHighTriggerOutputEnable : Enable active high-trigger output (if the trigger states exit).
 *        - #kGPIO_ActiveLowTriggerOutputEnable  : Enable active low-trigger output (if the trigger states exit)..
 */
void GPIO_SetMultipleInterruptPinsConfig(GPIO_Type * GPIO_ATTR base, uint32_t mask, gpio_interrupt_config_t config)
{
    if (0UL != (mask & 0xffffUL))
    {
        base->GICLR = (GPIO_ICR_IRQC(config) | (mask & 0xffffU));
    }

    mask = mask >> 16U;
    if (mask != 0UL)
    {
        base->GICHR = (GPIO_ICR_IRQC(config) | (mask & 0xffffU));
    }
}
