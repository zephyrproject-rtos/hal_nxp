/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_GPIO_H_
#define FSL_GPIO_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_gpio
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief QN GPIO driver version 2.0.1. */
#define FSL_GPIO_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! @brief QN GPIO direction definition */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput  = 0U, /*!< Set current pin as digital input*/
    kGPIO_DigitalOutput = 1U, /*!< Set current pin as digital output*/
} gpio_pin_direction_t;

/*!
 * @brief The GPIO pin configuration structure.
 *
 * Every pin can only be configured as either output pin or input pin at a time.
 * If configured as a input pin, then leave the outputLogic unused
 */
typedef struct _gpio_pin_config
{
    gpio_pin_direction_t pinDirection; /*!< GPIO direction, input or output */
    /* Output configurations, please ignore if configured as a input one */
    uint8_t outputLogic; /*!< Set default output logic, no use in input */
} gpio_pin_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*! @name GPIO Configuration */
/*! @{ */

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
 * @param base   GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param pin    GPIO port pin number
 * @param config GPIO pin configuration pointer
 */
void GPIO_PinInit(GPIO_Type *base, uint32_t pin, const gpio_pin_config_t *config);

/*! @} */

/*! @name GPIO Output Operations */
/*! @{ */

/*!
 * @brief Sets the output level of a GPIO pin to the logic 1 or 0.
 *
 * @param base    GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param pin     GPIO pin number
 * @param output  GPIO pin output logic level.
 *        - 0: corresponding pin output low-logic level.
 *        - 1: corresponding pin output high-logic level.
 */
static inline void GPIO_PinWrite(GPIO_Type *base, uint32_t pin, uint8_t output)
{
    if (output == 0U)
    {
        base->DATAOUT = base->DATAOUT & (~(1U << pin));
    }
    else
    {
        base->DATAOUT = base->DATAOUT | (1U << pin);
    }
}

/*!
 * @brief Sets the output level of a GPIO pin to the logic 1 or 0.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PinWrite
 */
static inline void GPIO_WritePinOutput(GPIO_Type *base, uint32_t pin, uint8_t output)
{
    GPIO_PinWrite(base, pin, output);
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */
static inline void GPIO_PortSet(GPIO_Type *base, uint32_t mask)
{
    base->DATAOUT = base->DATAOUT | mask;
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortSet.
 */
static inline void GPIO_SetPinsOutput(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortSet(base, mask);
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 0.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */
static inline void GPIO_PortClear(GPIO_Type *base, uint32_t mask)
{
    base->DATAOUT = base->DATAOUT & (~mask);
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 0.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortClear.
 */
static inline void GPIO_ClearPinsOutput(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortClear(base, mask);
}

/*!
 * @brief Reverses current output logic of the multiple GPIO pins.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */
static inline void GPIO_PortToggle(GPIO_Type *base, uint32_t mask)
{
    base->DATAOUT = base->DATAOUT ^ mask;
}

/*!
 * @brief Reverses current output logic of the multiple GPIO pins.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortToggle.
 */
static inline void GPIO_TogglePinsOutput(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortToggle(base, mask);
}
/*! @} */

/*! @name GPIO Input Operations */
/*! @{ */

/*!
 * @brief Reads the current input value of the whole GPIO port.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param pin  GPIO pin number
 * @retval GPIO port input value
 *        - 0: corresponding pin input low-logic level.
 *        - 1: corresponding pin input high-logic level.
 */
static inline uint32_t GPIO_PinRead(GPIO_Type *base, uint32_t pin)
{
    return (((base->DATA) >> pin) & 0x01U);
}

/*!
 * @brief Reads the current input value of the whole GPIO port.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PinRead
 */
static inline uint32_t GPIO_ReadPinInput(GPIO_Type *base, uint32_t pin)
{
    return GPIO_PinRead(base, pin);
}
/*! @} */

/*! @name GPIO Interrupt */
/*! @{ */

/*!
 * @brief Reads whole GPIO port interrupt status flag.
 *
 * The flag remains set until a logic one is written to that flag.
 * If configured for a level sensitive interrupt that remains asserted, the flag
 * is set again immediately.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @retval Current GPIO port interrupt status flag, for example, 0x00010001 means the
 *         pin 0 and 17 have the interrupt.
 */
static inline uint32_t GPIO_PortGetInterruptFlags(GPIO_Type *base)
{
    return base->INTSTATUS;
}

/*!
 * @brief Reads whole GPIO port interrupt status flag.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortGetInterruptFlags
 */
static inline uint32_t GPIO_GetPinsInterruptFlags(GPIO_Type *base)
{
    return GPIO_PortGetInterruptFlags(base);
}

/*!
 * @brief Clears multiple GPIO pin interrupt status flag.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */
static inline void GPIO_PortClearInterruptFlags(GPIO_Type *base, uint32_t mask)
{
    base->INTSTATUS = mask;
}

/*!
 * @brief Clears multiple GPIO pin interrupt status flag.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortClearInterruptFlags.
 */
static inline void GPIO_ClearPinsInterruptFlags(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortClearInterruptFlags(base, mask);
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a high level interrupt.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */

static inline void GPIO_PortSetHighLevelInterrupt(GPIO_Type *base, uint32_t mask)
{
    base->INTTYPECLR = mask; /* Clear INT TYPE bit */
    base->INTPOLSET  = mask; /* Set INT POLarity bit */
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a high level interrupt.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortSetHighLevelInterrupt.
 */

static inline void GPIO_SetHighLevelInterrupt(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortSetHighLevelInterrupt(base, mask);
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a rising edge interrupt.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */

static inline void GPIO_PortSetRisingEdgeInterrupt(GPIO_Type *base, uint32_t mask)
{
    base->INTTYPESET = mask; /* Set INT TYPE bit */
    base->INTPOLSET  = mask; /* Set INT POLarity bit */
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a rising edge interrupt.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortSetRisingEdgeInterrupt.
 */

static inline void GPIO_SetRisingEdgeInterrupt(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortSetRisingEdgeInterrupt(base, mask);
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a low level interrupt.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */

static inline void GPIO_PortSetLowLevelInterrupt(GPIO_Type *base, uint32_t mask)
{
    base->INTTYPECLR = mask; /* Clear INT TYPE bit */
    base->INTPOLCLR  = mask; /* Clear INT POLarity bit */
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a low level interrupt.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortSetLowLevelInterrupt.
 */
static inline void GPIO_SetLowLevelInterrupt(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortSetLowLevelInterrupt(base, mask);
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a falling edge interrupt.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */
static inline void GPIO_PortSetFallingEdgeInterrupt(GPIO_Type *base, uint32_t mask)
{
    base->INTTYPESET = mask; /* Set INT TYPE bit */
    base->INTPOLCLR  = mask; /* Clear INT POLarity bit */
}

/*!
 * @brief  Changes the interrupt type for the specified pin to a falling edge interrupt.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortSetFallingEdgeInterrupt.
 */
static inline void GPIO_SetFallingEdgeInterrupt(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortSetFallingEdgeInterrupt(base, mask);
}

/*!
 * @brief Enable GPIO pin interrupt.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */
static inline void GPIO_PortEnableInterrupt(GPIO_Type *base, uint32_t mask)
{
    base->INTENSET = mask;
}

/*!
 * @brief Enable GPIO pin interrupt.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortEnableInterrupt.
 */
static inline void GPIO_EnableInterrupt(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortEnableInterrupt(base, mask);
}

/*!
 * @brief Disable GPIO pin interrupt.
 *
 * @param base GPIO peripheral base pointer(GPIOA, GPIOB.)
 * @param mask GPIO pin number macro
 */
static inline void GPIO_PortDisableInterrupt(GPIO_Type *base, uint32_t mask)
{
    base->INTENCLR = mask;
}

/*!
 * @brief Disable GPIO pin interrupt.
 * @deprecated Do not use this function.  It has been superseded by @ref GPIO_PortDisableInterrupt
 */
static inline void GPIO_DisableInterrupt(GPIO_Type *base, uint32_t mask)
{
    GPIO_PortDisableInterrupt(base, mask);
}
/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_GPIO_H_*/
