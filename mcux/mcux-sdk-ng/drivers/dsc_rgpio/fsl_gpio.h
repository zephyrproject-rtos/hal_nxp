/*
 * Copyright 2025 NXP
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
#define FSL_GPIO_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief GPIO direction definition */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput  = 0U, /*!< Set current pin as digital input*/
    kGPIO_DigitalOutput = 1U, /*!< Set current pin as digital output*/
} gpio_pin_direction_t;

/*! @brief Configures the interrupt generation condition. */
typedef enum _gpio_interrupt_config
{
    kGPIO_InterruptStatusFlagDisabled   = 0x0U,  /*!< Interrupt status flag is disabled. */
    kGPIO_DMARisingEdge                 = 0x1U,  /*!< ISF flag and DMA request on rising edge. */
    kGPIO_DMAFallingEdge                = 0x2U,  /*!< ISF flag and DMA request on falling edge. */
    kGPIO_DMAEitherEdge                 = 0x3U,  /*!< ISF flag and DMA request on either edge. */
    kGPIO_FlagRisingEdge                = 0x5U,  /*!< Flag sets on rising edge. */
    kGPIO_FlagFallingEdge               = 0x6U,  /*!< Flag sets on falling edge. */
    kGPIO_FlagEitherEdge                = 0x7U,  /*!< Flag sets on either edge. */
    kGPIO_InterruptLogicZero            = 0x8U,  /*!< Interrupt when logic zero. */
    kGPIO_InterruptRisingEdge           = 0x9U,  /*!< Interrupt on rising edge. */
    kGPIO_InterruptFallingEdge          = 0xAU,  /*!< Interrupt on falling edge. */
    kGPIO_InterruptEitherEdge           = 0xBU,  /*!< Interrupt on either edge. */
    kGPIO_InterruptLogicOne             = 0xCU,  /*!< Interrupt when logic one. */
    kGPIO_ActiveHighTriggerOutputEnable = 0xDU,  /*!< Enable active high-trigger output. */
    kGPIO_ActiveLowTriggerOutputEnable  = 0xEU,  /*!< Enable active low-trigger output. */
} gpio_interrupt_config_t;

/*! @brief Configures the selection of interrupt/DMA request/trigger output. */
typedef enum _gpio_interrupt_selection
{
    kGPIO_InterruptOutput0 = 0x0U, /*!< Interrupt/DMA request/trigger output 0. */
    kGPIO_InterruptOutput1 = 0x1U, /*!< Interrupt/DMA request/trigger output 1. */
} gpio_interrupt_selection_t;

/*! @brief GPIO pin and interrupt control. */
typedef enum
{
    kGPIO_PinControlNonSecure          = 0x01U, /*!< Pin Control Non-Secure access. */
    kGPIO_InterruptControlNonSecure    = 0x02U, /*!< Interrupt Control Non-Secure access. */
    kGPIO_PinControlNonPrivilege       = 0x04U, /*!< Pin Control Non-Privilege access. */
    kGPIO_InterruptControlNonPrivilege = 0x08U, /*!< Interrupt Control Non-Privilege access. */
} gpio_pin_interrupt_control_t;

/*!
 * @brief The GPIO pin configuration structure.
 *
 * Each pin can only be configured as either an output pin or an input pin at a time.
 * If configured as an input pin, leave the outputLogic unused.
 */
typedef struct _gpio_pin_config
{
    gpio_pin_direction_t pinDirection; /*!< GPIO direction, input or output */
    uint8_t outputLogic;               /*!< Output level, not used if configured as input. */
} gpio_pin_config_t;

/*! @} */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @addtogroup gpio
 * @{
 */

/*! @name GPIO Configuration */
/*! @{ */

/*!
 * @brief Initializes the GPIO peripheral.
 *
 * This function ungates the GPIO clock.
 *
 * @param base   GPIO peripheral base pointer.
 * @return kStatus_Success if success; otherwise returns an error code.
 */
status_t GPIO_PortInit(GPIO_Type *base);

/*!
 * @brief Denitializes the GPIO peripheral.
 *
 * @param base   GPIO peripheral base pointer.
 * @return kStatus_Success if success; otherwise returns an error code.
 */
status_t GPIO_PortDeinit(GPIO_Type *base);

/*!
 * @brief Initializes a GPIO pin used by the board.
 *
 * To initialize the GPIO, define a pin configuration, as either input or output, in the user file.
 * Then, call the GPIO_PinInit() function.
 *
 * This is an example to define an input pin or an output pin configuration.
 * @code
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
 * @endcode
 *
 * @param base   GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param pin    GPIO port pin number
 * @param config GPIO pin configuration pointer
 * @return kStatus_Success if success; otherwise returns an error code.
 */
status_t GPIO_PinInit(GPIO_Type *base, uint8_t pin, const gpio_pin_config_t *config);

/*!
 * @brief Enable port input.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
static inline void GPIO_PortInputEnable(GPIO_Type *base, uint32_t mask)
{
    base->PIDR &= ~mask;
}

/*!
 * @brief Disable port input.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
static inline void GPIO_PortInputDisable(GPIO_Type *base, uint32_t mask)
{
    base->PIDR |= mask;
}

/*!
 * @brief Configure the GPIO pin as Input or Output for one pin.
 *
 * Configure the GPIO pin as Input or Output for one pin.
 *
 * @param base          GPIO peripheral base pointer
 * @param pin           GPIO pin identifier.
 * @param direction     Direction of GPIO pin. @ref gpio_pin_direction_t
 */
static inline void GPIO_PinSetDirection(GPIO_Type *base, uint8_t pin, gpio_pin_direction_t direction)
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

/*! @} */

/*! @name GPIO Output Operations */
/*! @{ */

/*!
 * @brief Sets the output level of one GPIO pin to the logic 1 or 0.
 *
 * @param base    GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param pin     GPIO pin number
 * @param output  GPIO pin output logic level.
 *        - 0: corresponding pin output low-logic level.
 *        - 1: corresponding pin output high-logic level.
 */
static inline void GPIO_PinWrite(GPIO_Type *base, uint8_t pin, uint8_t output)
{
    assert(pin < GPIO_PDR_COUNT);

    base->PDR[pin] = output;
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
static inline void GPIO_PortSet(GPIO_Type *base, uint32_t mask)
{
    base->PSOR = mask;
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 0.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
static inline void GPIO_PortClear(GPIO_Type *base, uint32_t mask)
{
    base->PCOR = mask;
}

/*!
 * @brief Reverses the current output logic of the multiple GPIO pins.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
static inline void GPIO_PortToggle(GPIO_Type *base, uint32_t mask)
{
    base->PTOR = mask;
}

/*! @} */

/*! @name GPIO Input Operations */
/*! @{ */

/*!
 * @brief Reads the current input value of the GPIO port.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 */
static inline uint32_t GPIO_PortRead(GPIO_Type *base)
{
    return base->PDIR;
}

/*!
 * @brief Reads the current input value of the GPIO pin.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param pin     GPIO pin number
 * @retval GPIO port input value
 *        - 0: corresponding pin input low-logic level.
 *        - 1: corresponding pin input high-logic level.
 */
static inline uint8_t GPIO_PinRead(GPIO_Type *base, uint8_t pin)
{
    assert(pin < GPIO_PDR_COUNT);

    return base->PDR[pin];
}

/*! @} */

/*! @name GPIO Interrupt */
/*! @{ */
/*!
 * @brief Configures the gpio pin interrupt/DMA request.
 *
 * @param base    GPIO peripheral base pointer.
 * @param pin     GPIO pin number.
 * @param config  GPIO pin interrupt configuration.
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
static inline void GPIO_SetPinInterruptConfig(GPIO_Type *base, uint8_t pin, gpio_interrupt_config_t config)
{
    base->ICR[pin] = (base->ICR[pin] & ~GPIO_ICR_IRQC_MASK) | GPIO_ICR_IRQC(config);
}

/*!
 * @brief Configures the gpio pin interrupt/DMA request/trigger output channel selection.
 *
 * @param base    GPIO peripheral base pointer.
 * @param pin     GPIO pin number.
 * @param selection  GPIO pin interrupt output selection.
 *        - #kGPIO_InterruptOutput0: Interrupt/DMA request/trigger output 0.
 *        - #kGPIO_InterruptOutput1 : Interrupt/DMA request/trigger output 1.
 */
static inline void GPIO_SetPinInterruptChannel(GPIO_Type *base, uint8_t pin, gpio_interrupt_selection_t selection)
{
    base->ICR[pin] = (base->ICR[pin] & ~GPIO_ICR_IRQS_MASK) | GPIO_ICR_IRQS(selection);
}

/*!
 * @brief Read the GPIO interrupt status flags based on selected interrupt channel(IRQS).
 *
 * @param base GPIO peripheral base pointer. (GPIOA, GPIOB, GPIOC, and so on.)
 * @param channel '0' means select interrupt channel 0, '1' means select interrupt channel 1.
 * @return The current GPIO's interrupt status flag based on the selected interrupt channel.
 *         '1' means the related pin's flag is set, '0' means the related pin's flag not set.
 *          For example, the return value 0x00010001 means the pin 0 and 17 have the interrupt pending.
 */
static inline uint32_t GPIO_GpioGetInterruptChannelFlags(GPIO_Type *base, uint8_t channel)
{
    assert(channel < GPIO_ISFR_COUNT);

    return base->ISFR[channel];
}

/*!
 * @brief Read individual pin's interrupt status flag.
 *
 * @param base GPIO peripheral base pointer. (GPIOA, GPIOB, GPIOC, and so on)
 * @param pin GPIO specific pin number.
 * @return 1 means flag asserted, 0 means not.
 */
static inline uint8_t GPIO_PinGetInterruptFlag(GPIO_Type *base, uint8_t pin)
{
    return (uint8_t)((base->ICR[pin] & GPIO_ICR_ISF_MASK) >> GPIO_ICR_ISF_SHIFT);
}

/*!
 * @brief Clear GPIO individual pin's interrupt status flag.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on).
 * @param pin GPIO specific pin number.
 */
static inline void GPIO_PinClearInterruptFlag(GPIO_Type *base, uint8_t pin)
{
    base->ICR[pin] |= GPIO_ICR_ISF_MASK;
}

/*!
 * @brief Clears GPIO pin interrupt status flags based on selected interrupt channel(IRQS).
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 * @param channel '0' means select interrupt channel 0, '1' means select interrupt channel 1.
 */
static inline void GPIO_GpioClearInterruptChannelFlags(GPIO_Type *base, uint32_t mask, uint8_t channel)
{
    assert(channel < GPIO_ISFR_COUNT);
    base->ISFR[channel] = mask;
}

/*!
 * @brief Sets the GPIO interrupt configuration in PCR register for multiple pins.
 *
 * @param base   GPIO peripheral base pointer.
 * @param mask   GPIO pins. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 * @param config  GPIO pin interrupt configuration.
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
static inline void GPIO_SetMultipleInterruptPinsConfig(GPIO_Type *base, uint32_t mask, gpio_interrupt_config_t config)
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

/*! @} */
/*! @} */

#if defined(__cplusplus)
}
#endif

#endif /* FSL_GPIO_H_ */
