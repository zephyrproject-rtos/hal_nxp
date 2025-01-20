/*
 * Copyright 2018, 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _LPC_GPIO_H_
#define _LPC_GPIO_H_

#include "fsl_common.h"

/*!
 * @addtogroup lpc_gpio
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief LPC GPIO driver version. */
#define FSL_GPIO_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! @brief LPC GPIO direction definition */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput  = 0U, /*!< Set current pin as digital input*/
    kGPIO_DigitalOutput = 1U, /*!< Set current pin as digital output*/
} gpio_pin_direction_t;

/*! @brief GPIO interrupt mode definition. */
typedef enum _gpio_interrupt_mode
{
    kGPIO_IntDisabled            = 0U, /*!< Set current pin general IO functionality.*/
    kGPIO_IntLowLevel            = 1U, /*!< Set current pin interrupt is low-level sensitive.*/
    kGPIO_IntHighLevel           = 2U, /*!< Set current pin interrupt is high-level sensitive.*/
    kGPIO_IntRisingEdge          = 3U, /*!< Set current pin interrupt is rising-edge sensitive.*/
    kGPIO_IntFallingEdge         = 4U, /*!< Set current pin interrupt is falling-edge sensitive.*/
    kGPIO_IntRisingOrFallingEdge = 5U, /*!< Enable the edge select bit to override the ICR register's configuration.*/
} gpio_interrupt_mode_t;

/*!
 * @brief The GPIO pin configuration structure.
 *
 * Every pin can only be configured as either output pin or input pin at a time.
 * If configured as a input pin, then leave the outputConfig unused.
 */

typedef struct _gpio_pin_config
{
    gpio_pin_direction_t direction; /*!< Specifies the pin direction. */
    uint8_t outputLogic;            /*!< Set a default output logic, which has no use in input */
} gpio_pin_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes a GPIO pin used by the board.
 *
 * To initialize the GPIO, define a pin configuration, either input or output, in the user file.
 * Then, call the GPIO_PinInit() function.
 *
 * This is an example to define an input pin or output pin configuration:
 * @code
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
 * @endcode
 *
 * @param base   GPIO peripheral base pointer(Typically GPIO)
 * @param pin    GPIO pin number
 * @param Config GPIO pin configuration pointer
 */
void GPIO_PinInit(GPIO_Type *base, uint32_t pin, const gpio_pin_config_t *Config);

/*!
 * @brief Initializes the GPIO peripheral.
 *
 * This function ungates the GPIO clock.
 *
 * @param base   GPIO peripheral base pointer.
 * @param port   GPIO port number.
 */
void GPIO_PortInit(GPIO_Type *base, uint32_t port);

/*!
 * @brief Initializes the GPIO peripheral.
 *
 * This function ungates the GPIO clock.
 *
 * @param base   GPIO peripheral base pointer.
 * @param pin	  GPIO pin number
 * @param pinInterruptMode  GPIO interrupt mode
 */
void GPIO_PinSetInterruptConfig(GPIO_Type *base, uint32_t pin, gpio_interrupt_mode_t pinInterruptMode);

/*! @} */
/*! @name GPIO Output Operations */
/*! @{ */

/*!
 * @brief Sets the output level of the one GPIO pin to the logic 1 or 0.
 *
 * @param base    GPIO peripheral base pointer(Typically GPIO)
 * @param pin     GPIO pin number
 * @param output  GPIO pin output logic level.
 *        - 0: corresponding pin output low-logic level.
 *        - 1: corresponding pin output high-logic level.
 */
static inline void GPIO_PinWrite(GPIO_Type *base, uint32_t pin, uint8_t output)
{
    base->GPIODATA[1 << pin] = (output << pin);
}

/*! @} */
/*! @name GPIO Input Operations */
/*! @{ */

/**
 * @brief	Get a GPIO pin state via the GPIODATA register
 *
 * @param	base	GPIO peripheral base pointer(Typically GPIO)
 * @param	pin		GPIO pin number
 * @retval GPIO Pin input value
 *        - 0: corresponding pin input low-logic level.
 *        - 1: corresponding pin input high-logic level.
 */
static inline bool GPIO_PinRead(GPIO_Type *base, uint8_t pin)
{
    return (base->GPIODATA[1 << pin] != 0);
}

/*! @} */
/*! @name GPIO Port Operations */
/*! @{ */

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * @param base    GPIO peripheral base pointer(Typically GPIO)
 * @param pinmask GPIO pin number macro
 */
static inline void GPIO_PortSet(GPIO_Type *base, uint32_t pinmask)
{
    base->GPIODATA[pinmask] = pinmask;
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 0.
 *
 * @param base    GPIO peripheral base pointer(Typically GPIO)
 * @param pinmask GPIO pin number macro
 */
static inline void GPIO_PortClear(GPIO_Type *base, uint32_t pinmask)
{
    base->GPIODATA[pinmask] = 0;
}

/*!
 * @brief Reverses current output logic of the multiple GPIO pins.
 *
 * @param base    GPIO peripheral base pointer(Typically GPIO)
 * @param pinmask GPIO pin number macro
 */
static inline void GPIO_PortToggle(GPIO_Type *base, uint32_t pinmask)
{
    base->GPIODATA[pinmask] ^= (pinmask);
}

/*!
 * @brief Reads the current input value of the whole GPIO port.
 *
 * @param base    GPIO peripheral base pointer(Typically GPIO)
 */
static inline uint32_t GPIO_PortRead(GPIO_Type *base)
{
    return (uint32_t)base->GPIODATA[4095];
}

/*! @} */
/*! @name GPIO Interrupts Operations */
/*! @{ */

/**
 * @brief	Enables interrupts for selected pins on a port
 *
 * @param	base	 GPIO peripheral base pointer(Typically GPIO)
 * @param	pinmask	 GPIO pin number macro
 */
static inline void GPIO_PortEnableInterrupts(GPIO_Type *base, uint32_t pinmask)
{
    base->IMSC |= pinmask;
}

/**
 * @brief	Disables interrupts for selected pins on a port
 *
 * @param	base	 GPIO peripheral base pointer(Typically GPIO)
 * @param	pinmask	 GPIO pin number macro
 */
static inline void GPIO_PortDisableInterrupts(GPIO_Type *base, uint32_t pinmask)
{
    base->IMSC &= ~pinmask;
}

/**
 * @brief	Returns raw interrupt pending status for pin interrupts for a port
 *
 * @param	base	GPIO peripheral base pointer(Typically GPIO)
 * @retval	A bifield containing the raw pending interrupt states for each pin (0..11) on the port
 */
static inline uint32_t GPIO_PortGetInterruptsFlags(GPIO_Type *base)
{
    return base->RIS;
}

/**
 * @brief	Returns masked interrupt pending status for pin interrupts for a port
 *
 * @param	base	GPIO peripheral base pointer(Typically GPIO)
 * @retval	A bifield containing the masked pending interrupt states for each pin (0..11) on the port
 */
static inline uint32_t GPIO_PortReadMaskedInterrupts(GPIO_Type *base)
{
    return base->MIS;
}

/**
 * @brief	Clears pending interrupts for selected pins for a port
 *
 * @param	base	GPIO peripheral base pointer(Typically GPIO)
 * @param	pinmask	GPIO pin number macro
 */
static inline void GPIO_PortClearInterruptFlags(GPIO_Type *base, uint32_t pinmask)
{
    base->IC = pinmask;
    /* Two NOPs should be added after the clear of
        the interrupt edge detection logic*/
    __NOP();
    __NOP();
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* _LPC_GPIO_H_*/
