/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2019, 2024-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpio.h"

/*
 * $Coverage Justification Reference$
 *
 * $Justification gpio_c_ref_1$
 * The peripheral base address is always valid and checked by assert.
 *
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.gpio"
#endif

#if defined(GPIO_RSTS)
#define GPIO_RESETS_ARRAY GPIO_RSTS
#endif

#if defined(GPIO_CLOCKS)
#define GPIO_CLOCKS_ARRAY GPIO_CLOCKS
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if !(defined(FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && \
    defined(FSL_FEATURE_SOC_PORT_COUNT)
static PORT_Type *const s_portBases[] = PORT_BASE_PTRS;
#endif
static GPIO_Type *const s_gpioBases[] = GPIO_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && \
    defined(GPIO_CLOCKS_ARRAY)
/*! @brief Array to map FGPIO instance number to clock name. */
static const clock_ip_name_t s_gpioClockName[] = GPIO_CLOCKS_ARRAY;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(FSL_FEATURE_SOC_FGPIO_COUNT) && FSL_FEATURE_SOC_FGPIO_COUNT

#if defined(FSL_FEATURE_PCC_HAS_FGPIO_CLOCK_GATE_CONTROL) && FSL_FEATURE_PCC_HAS_FGPIO_CLOCK_GATE_CONTROL

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map FGPIO instance number to clock name. */
static const clock_ip_name_t s_fgpioClockName[] = FGPIO_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#endif /* FSL_FEATURE_PCC_HAS_FGPIO_CLOCK_GATE_CONTROL */

#endif /* FSL_FEATURE_SOC_FGPIO_COUNT */

#if defined(GPIO_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_gpioResets[] = GPIO_RESETS_ARRAY;
#endif

#if GPIO_PIN_CALLBACK_COUNT
/*!
 * @brief Pointers to the handle registered for each GPIO instance, indexed by instance.
 *
 * Driver keeps an instance-indexed table of the caller-owned handles registered through
 * GPIO_CreateHandle(). The shared dispatcher GPIO_DriverIRQHandler(instance) looks the handle up
 * by instance, so a board/device vector ISR only needs the controller instance -- no per-use-case
 * ISR body and no hand-passed handle at interrupt time.
 */
static gpio_handle_t *s_gpioHandles[ARRAY_SIZE(s_gpioBases)];
#endif /* GPIO_PIN_CALLBACK_COUNT */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Enable/disable GPIO port clock.
 *
 * @param base   GPIO peripheral base pointer.
 * @param enable True means enable GPIO port clock, false means disable.
 */
static void GPIO_PortClockEnable(GPIO_Type *base, bool enable);

/*******************************************************************************
 * Code
 ******************************************************************************/
uint32_t GPIO_GetInstance(GPIO_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    /*
     * $Branch Coverage Justification$
     * (instance >= ARRAY_SIZE(s_gpioBases)) not covered.
     * $ref gpio_c_ref_1$.
     */
    for (instance = 0; instance < ARRAY_SIZE(s_gpioBases); instance++) /* GCOVR_EXCL_BR_LINE */
    {
        if (MSDK_REG_NONSECURE_ADDR(s_gpioBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_gpioBases));

    return instance;
}

static void GPIO_PortClockEnable(GPIO_Type *base, bool enable)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)&& \
    defined(GPIO_CLOCKS_ARRAY)
    uint32_t instance = GPIO_GetInstance(base);

    /* Ensure the instance index is within bounds of the s_gpioClockName array */
    assert(instance < ARRAY_SIZE(s_gpioClockName));

    if (enable)
    {
        CLOCK_EnableClock(s_gpioClockName[instance]);
    }
    else
    {
        CLOCK_DisableClock(s_gpioClockName[instance]);
    }
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Initializes the GPIO peripheral.
 *
 * This function ungates the GPIO clock.
 *
 * param base   GPIO peripheral base pointer.
 */
void GPIO_PortInit(GPIO_Type *base)
{
    GPIO_PortClockEnable(base, true);

#if defined(GPIO_RESETS_ARRAY)
    /* Reset the GPIO module */
    RESET_ReleasePeripheralReset(s_gpioResets[GPIO_GetInstance(base)]);
#endif
}


/*!
 * brief Deinitializes the GPIO peripheral.
 *
 * param base   GPIO peripheral base pointer.
 */
void GPIO_PortDenit(GPIO_Type *base)
{
    GPIO_PortClockEnable(base, false);
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
void GPIO_PinInit(GPIO_Type *base, uint32_t pin, const gpio_pin_config_t *config)
{
    assert(NULL != config);

    GPIO_PortClockEnable(base, true);

#if defined(GPIO_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_gpioResets[GPIO_GetInstance(base)]);
#endif

    if (config->pinDirection == kGPIO_DigitalInput)
    {
        base->PDDR &= GPIO_FIT_REG(~(1UL << pin));
    }
    else
    {
        GPIO_PinWrite(base, pin, config->outputLogic);
        base->PDDR |= GPIO_FIT_REG((1UL << pin));
    }
}

#if defined(FSL_FEATURE_GPIO_HAS_VERSION_INFO_REGISTER) && FSL_FEATURE_GPIO_HAS_VERSION_INFO_REGISTER
void GPIO_GetVersionInfo(GPIO_Type *base, gpio_version_info_t *verInfo)
{
    uint32_t verid = base->VERID;
    verInfo->feature  = (uint16_t)((verid & GPIO_VERID_FEATURE_MASK) >> GPIO_VERID_FEATURE_SHIFT);
    verInfo->minor    = (uint8_t)((verid & GPIO_VERID_MINOR_MASK) >> GPIO_VERID_MINOR_SHIFT);
    verInfo->major    = (uint8_t)((verid & GPIO_VERID_MAJOR_MASK) >> GPIO_VERID_MAJOR_SHIFT);
}
#endif /* FSL_FEATURE_GPIO_HAS_VERSION_INFO_REGISTER */

#if !(defined(FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && \
    defined(FSL_FEATURE_SOC_PORT_COUNT)
/*!
 * brief Reads the GPIO port interrupt status flag.
 *
 * If a pin is configured to generate the DMA request, the corresponding flag
 * is cleared automatically at the completion of the requested DMA transfer.
 * Otherwise, the flag remains set until a logic one is written to that flag.
 * If configured for a level sensitive interrupt that remains asserted, the flag
 * is set again immediately.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * retval The current GPIO port interrupt status flag, for example, 0x00010001 means the
 *         pin 0 and 17 have the interrupt.
 */
uint32_t GPIO_PortGetInterruptFlags(GPIO_Type *base)
{
    uint8_t instance;
    PORT_Type *portBase;
    instance = (uint8_t)GPIO_GetInstance(base);
    portBase = s_portBases[instance];
    return portBase->ISFR;
}
#else
/*!
 * brief Read the GPIO interrupt status flags.
 *
 * param base GPIO peripheral base pointer. (GPIOA, GPIOB, GPIOC, and so on.)
 * return The current GPIO's interrupt status flag.
 *         '1' means the related pin's flag is set, '0' means the related pin's flag not set.
 *          For example, the return value 0x00010001 means the pin 0 and 17 have the interrupt pending.
 */
uint32_t GPIO_GpioGetInterruptFlags(GPIO_Type *base)
{
    return base->ISFR[0];
}
#if (defined(FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT) && FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT)
/*!
 * brief Read the GPIO interrupt status flags based on selected interrupt channel(IRQS).
 * param base GPIO peripheral base pointer. (GPIOA, GPIOB, GPIOC, and so on.)
 * param channel '0' means selete interrupt channel 0, '1' means selete interrupt channel 1.
 *
 * return The current GPIO's interrupt status flag based on the selected interrupt channel.
 *         '1' means the related pin's flag is set, '0' means the related pin's flag not set.
 *          For example, the return value 0x00010001 means the pin 0 and 17 have the interrupt pending.
 */
uint32_t GPIO_GpioGetInterruptChannelFlags(GPIO_Type *base, uint32_t channel)
{
    assert(channel < 2U);
    return base->ISFR[channel];
}
#endif /* FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT */
/*!
 * brief Read individual pin's interrupt status flag.
 *
 * param base GPIO peripheral base pointer. (GPIOA, GPIOB, GPIOC, and so on)
 * param pin GPIO specific pin number.
 * return The current selected pin's interrupt status flag.
 */
uint8_t GPIO_PinGetInterruptFlag(GPIO_Type *base, uint32_t pin)
{
    return (uint8_t)((base->ICR[pin] & GPIO_ICR_ISF_MASK) >> GPIO_ICR_ISF_SHIFT);
}
#endif /* FSL_FEATURE_PORT_HAS_NO_INTERRUPT */

#if !(defined(FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && \
    defined(FSL_FEATURE_SOC_PORT_COUNT)
/*!
 * brief Clears multiple GPIO pin interrupt status flags.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pin number macro
 */
void GPIO_PortClearInterruptFlags(GPIO_Type *base, uint32_t mask)
{
    uint8_t instance;
    PORT_Type *portBase;
    instance       = (uint8_t)GPIO_GetInstance(base);
    portBase       = s_portBases[instance];
    portBase->ISFR = mask;
}
#else
/*!
 * brief Clears GPIO pin interrupt status flags.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pin number macro
 */
void GPIO_GpioClearInterruptFlags(GPIO_Type *base, uint32_t mask)
{
    /* Perform a dummy read before writing to ensure the write succeeds.*/
    base->ISFR[0] &= GPIO_FIT_REG(mask);
}
#if (defined(FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT) && FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT)
/*!
 * brief Clears GPIO pin interrupt status flags based on selected interrupt channel(IRQS).
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param mask GPIO pin number macro
 * param channel '0' means selete interrupt channel 0, '1' means selete interrupt channel 1.
 */
void GPIO_GpioClearInterruptChannelFlags(GPIO_Type *base, uint32_t mask, uint32_t channel)
{
    assert(channel < 2U);
    base->ISFR[channel] = GPIO_FIT_REG(mask);
}
#endif /* FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT */
/*!
 * brief Clear GPIO individual pin's interrupt status flag.
 *
 * param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on).
 * param pin GPIO specific pin number.
 */
void GPIO_PinClearInterruptFlag(GPIO_Type *base, uint32_t pin)
{
    base->ICR[pin] |= GPIO_FIT_REG(GPIO_ICR_ISF(1U));
}

#endif /* FSL_FEATURE_PORT_HAS_NO_INTERRUPT */

#if defined(FSL_FEATURE_GPIO_HAS_ATTRIBUTE_CHECKER) && FSL_FEATURE_GPIO_HAS_ATTRIBUTE_CHECKER
/*!
 * brief The GPIO module supports a device-specific number of data ports, organized as 32-bit
 * words/8-bit Bytes. Each 32-bit/8-bit data port includes a GACR register, which defines the byte-level
 * attributes required for a successful access to the GPIO programming model. If the GPIO module's GACR register
 * organized as 32-bit words, the attribute controls for the 4 data bytes in the GACR follow a standard little
 * endian data convention.
 *
 * param base      GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * param attribute GPIO checker attribute
 */
void GPIO_CheckAttributeBytes(GPIO_Type *base, gpio_checker_attribute_t attribute)
{
#if defined(FSL_FEATURE_GPIO_REGISTERS_WIDTH) && (FSL_FEATURE_GPIO_REGISTERS_WIDTH == 8U)
    base->GACR = ((uint8_t)attribute << GPIO_GACR_ACB_SHIFT);
#else
    base->GACR = ((uint32_t)attribute << GPIO_GACR_ACB0_SHIFT) | ((uint32_t)attribute << GPIO_GACR_ACB1_SHIFT) |
                 ((uint32_t)attribute << GPIO_GACR_ACB2_SHIFT) | ((uint32_t)attribute << GPIO_GACR_ACB3_SHIFT);
#endif /* FSL_FEATURE_GPIO_REGISTERS_WIDTH */
}
#endif

#if GPIO_PIN_CALLBACK_COUNT
/*!
 * brief Initializes a GPIO interrupt handle and registers it for the controller.
 *
 * Clears the handle's per-pin callback table and stores the handle in the driver's
 * instance-indexed table so the shared dispatcher GPIO_DriverIRQHandler(instance) can find it from
 * the controller instance alone. Call once before registering any pin callback.
 *
 * param base   GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on).
 * param handle Pointer to the caller-owned GPIO interrupt handle.
 */
void GPIO_CreateHandle(GPIO_Type *base, gpio_handle_t *handle)
{
    uint32_t i;

    assert(NULL != handle);

    for (i = 0U; i < GPIO_PIN_CALLBACK_COUNT; i++)
    {
        handle->entries[i].pinMask  = 0U;
        handle->entries[i].callback = NULL;
        handle->entries[i].userData = NULL;
    }

    /* Register the handle for this instance so the shared dispatcher can look it up. */
    s_gpioHandles[GPIO_GetInstance(base)] = handle;
}

/*!
 * brief Registers a pin-mask interrupt callback in the handle.
 *
 * note Matching is by exact pinMask, not by overlap. Registering masks that share a pin (for
 * example 0x3 then 0x1) creates two separate entries, and both callbacks run when the shared pin
 * fires.
 *
 * param handle   Pointer to the GPIO interrupt handle.
 * param pinMask  Bitmask of pins to register the callback for (bit n == pin n).
 * param callback Callback to invoke for the watched pins. Passing NULL removes the matching entry.
 * param userData User data pointer passed back to the callback.
 * retval kStatus_Success         Callback stored (or removed when callback is NULL).
 * retval kStatus_InvalidArgument pinMask is 0.
 * retval kStatus_OutOfRange      No free entry is available to store a new callback.
 */
status_t GPIO_SetPinCallback(gpio_handle_t *handle, uint32_t pinMask, gpio_pin_callback_t callback, void *userData)
{
    uint32_t i;
    uint32_t freeSlot = GPIO_PIN_CALLBACK_COUNT;

    assert(NULL != handle);

    if (0U == pinMask)
    {
        return kStatus_InvalidArgument;
    }

    /* Passing a NULL callback is a removal request. */
    if (NULL == callback)
    {
        return GPIO_ClearPinCallback(handle, pinMask);
    }

    /* Replace an entry watching exactly this mask, else remember the first free slot. */
    for (i = 0U; i < GPIO_PIN_CALLBACK_COUNT; i++)
    {
        if (handle->entries[i].pinMask == pinMask)
        {
            handle->entries[i].callback = callback;
            handle->entries[i].userData = userData;
            return kStatus_Success;
        }
        if ((0U == handle->entries[i].pinMask) && (freeSlot == GPIO_PIN_CALLBACK_COUNT))
        {
            freeSlot = i;
        }
    }

    if (freeSlot == GPIO_PIN_CALLBACK_COUNT)
    {
        return kStatus_OutOfRange;
    }

    handle->entries[freeSlot].pinMask  = pinMask;
    handle->entries[freeSlot].callback = callback;
    handle->entries[freeSlot].userData = userData;

    return kStatus_Success;
}

/*!
 * brief Clears a pin-mask interrupt callback in the handle.
 *
 * param handle  Pointer to the GPIO interrupt handle.
 * param pinMask Bitmask of pins whose callback entry is removed (bit n == pin n).
 * retval kStatus_Success         Callback cleared.
 * retval kStatus_InvalidArgument pinMask is 0.
 * retval kStatus_OutOfRange      No entry watches exactly pinMask.
 */
status_t GPIO_ClearPinCallback(gpio_handle_t *handle, uint32_t pinMask)
{
    uint32_t i;

    assert(NULL != handle);

    if (0U == pinMask)
    {
        return kStatus_InvalidArgument;
    }

    for (i = 0U; i < GPIO_PIN_CALLBACK_COUNT; i++)
    {
        if (handle->entries[i].pinMask == pinMask)
        {
            handle->entries[i].pinMask  = 0U;
            handle->entries[i].callback = NULL;
            handle->entries[i].userData = NULL;
            return kStatus_Success;
        }
    }

    return kStatus_OutOfRange;
}
#endif /* GPIO_PIN_CALLBACK_COUNT */

/*!
 * brief Unified GPIO interrupt dispatcher.
 *
 * Looks up the handle registered for instance via GPIO_CreateHandle(), reads the controller's
 * pending interrupt flags, and for each callback entry whose watched pins intersect the pending
 * flags: clears those flags first, then invokes the callback once with the pending subset as a
 * pin bitmask. After the entries are serviced, any pending flags not claimed by a registered entry
 * are cleared as well, so an interrupt that is enabled in hardware but has no callback cannot keep
 * re-firing (interrupt storm). Following the SDK convention where the vector handler recovers its
 * handle from a driver-static table (compare PDM_EventHandleIRQ(instance)), a board/device vector
 * ISR forwards to this function with only the controller instance, so no per-use-case ISR body is
 * needed.
 *
 * param instance GPIO peripheral instance number.
 */
#if !(defined(FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && \
    defined(FSL_FEATURE_SOC_PORT_COUNT)
/* Interrupt is route to PORT. */
void GPIO_DriverIRQHandler(uint32_t instance)
{
    PORT_Type *base;
    uint32_t flags;

    if (instance >= ARRAY_SIZE(s_portBases))
    {
        SDK_ISR_EXIT_BARRIER;
        return;
    }

    base   = s_portBases[instance];

#if GPIO_PIN_CALLBACK_COUNT
    uint32_t handled = 0U;
    uint32_t unhandled;
    uint32_t i;

    gpio_handle_t *handle = s_gpioHandles[instance];

    /* No handle registered for this controller: nothing to dispatch. */
    if (NULL == handle)
    {
        SDK_ISR_EXIT_BARRIER;
        return;
    }

    flags = base->ISFR;

    for (i = 0U; i < GPIO_PIN_CALLBACK_COUNT; i++)
    {
        uint32_t pending = flags & handle->entries[i].pinMask;

        if ((0U != pending) && (NULL != handle->entries[i].callback))
        {
            /* Clear the pending flags before invoking the callback so a level re-assert during
             * the callback is observed on the next interrupt. */
            base->ISFR = pending;
            handled |= pending;
            handle->entries[i].callback(s_gpioBases[instance], handle, pending, handle->entries[i].userData);
        }
    }

    /* Clear any pending flags not claimed by a registered entry. Without this, a pin whose
     * interrupt is enabled in hardware but has no matching callback would never have its flag
     * cleared and would keep re-entering this handler (interrupt storm). */
    unhandled = flags & ~handled;
    if (0U != unhandled)
    {
        base->ISFR = unhandled;
    }
#else
    flags = base->ISFR;
    base->ISFR = flags;
#endif /* GPIO_PIN_CALLBACK_COUNT */

    SDK_ISR_EXIT_BARRIER;
}
#else /* Interrupt handle by GPIO */
void GPIO_DriverIRQHandler(uint32_t instance)
{
    GPIO_Type *base;
    uint32_t flags;

    if (instance >= ARRAY_SIZE(s_gpioBases))
    {
        SDK_ISR_EXIT_BARRIER;
        return;
    }

    base   = s_gpioBases[instance];

#if GPIO_PIN_CALLBACK_COUNT
    uint32_t handled = 0U;
    uint32_t unhandled;
    uint32_t i;

    gpio_handle_t *handle = s_gpioHandles[instance];

    /* No handle registered for this controller: nothing to dispatch. */
    if (NULL == handle)
    {
        SDK_ISR_EXIT_BARRIER;
        return;
    }

    flags = GPIO_GpioGetInterruptFlags(base);

    for (i = 0U; i < GPIO_PIN_CALLBACK_COUNT; i++)
    {
        uint32_t pending = flags & handle->entries[i].pinMask;

        if ((0U != pending) && (NULL != handle->entries[i].callback))
        {
            /* Clear the pending flags before invoking the callback so a level re-assert during
             * the callback is observed on the next interrupt. */
            GPIO_GpioClearInterruptFlags(base, pending);
            handled |= pending;
            handle->entries[i].callback(base, handle, pending, handle->entries[i].userData);
        }
    }

    /* Clear any pending flags not claimed by a registered entry. Without this, a pin whose
     * interrupt is enabled in hardware but has no matching callback would never have its flag
     * cleared and would keep re-entering this handler (interrupt storm). */
    unhandled = flags & ~handled;
    if (0U != unhandled)
    {
        GPIO_GpioClearInterruptFlags(base, unhandled);
    }
#else
    flags = GPIO_GpioGetInterruptFlags(base);
    GPIO_GpioClearInterruptFlags(base, flags);
#endif /* GPIO_PIN_CALLBACK_COUNT */

    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(FSL_FEATURE_SOC_FGPIO_COUNT) && FSL_FEATURE_SOC_FGPIO_COUNT

/*******************************************************************************
 * Variables
 ******************************************************************************/
static FGPIO_Type *const s_fgpioBases[] = FGPIO_BASE_PTRS;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
uint32_t FGPIO_GetInstance(FGPIO_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_fgpioBases); instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_fgpioBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_fgpioBases));

    return instance;
}

#if defined(FSL_FEATURE_PCC_HAS_FGPIO_CLOCK_GATE_CONTROL) && FSL_FEATURE_PCC_HAS_FGPIO_CLOCK_GATE_CONTROL
/*!
 * brief Initializes the FGPIO peripheral.
 *
 * This function ungates the FGPIO clock.
 *
 * param base   FGPIO peripheral base pointer (FGPIOA, FGPIOB, FGPIOC, and so on.)
 */
void FGPIO_PortInit(FGPIO_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate FGPIO periphral clock */
    CLOCK_EnableClock(s_fgpioClockName[FGPIO_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
#endif /* FSL_FEATURE_PCC_HAS_FGPIO_CLOCK_GATE_CONTROL */

/*!
 * brief Initializes a FGPIO pin used by the board.
 *
 * To initialize the FGPIO driver, define a pin configuration, as either input or output, in the user file.
 * Then, call the FGPIO_PinInit() function.
 *
 * This is an example to define an input pin or an output pin configuration:
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
 * param base   FGPIO peripheral base pointer (FGPIOA, FGPIOB, FGPIOC, and so on.)
 * param pin    FGPIO port pin number
 * param config FGPIO pin configuration pointer
 */
void FGPIO_PinInit(FGPIO_Type *base, uint32_t pin, const gpio_pin_config_t *config)
{
    assert(NULL != config);

    if (config->pinDirection == kGPIO_DigitalInput)
    {
        base->PDDR &= ~(1UL << pin);
    }
    else
    {
        FGPIO_PinWrite(base, pin, config->outputLogic);
        base->PDDR |= (1UL << pin);
    }
}
#if !(defined(FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && FSL_FEATURE_PORT_HAS_NO_INTERRUPT) && \
    defined(FSL_FEATURE_SOC_PORT_COUNT)
/*!
 * brief Reads the FGPIO port interrupt status flag.
 *
 * If a pin is configured to generate the DMA request, the corresponding flag
 * is cleared automatically at the completion of the requested DMA transfer.
 * Otherwise, the flag remains set until a logic one is written to that flag.
 * If configured for a level-sensitive interrupt that remains asserted, the flag
 * is set again immediately.
 *
 * param base FGPIO peripheral base pointer (FGPIOA, FGPIOB, FGPIOC, and so on.)
 * retval The current FGPIO port interrupt status flags, for example, 0x00010001 means the
 *         pin 0 and 17 have the interrupt.
 */
uint32_t FGPIO_PortGetInterruptFlags(FGPIO_Type *base)
{
    uint8_t instance;
    instance = (uint8_t)FGPIO_GetInstance(base);
    PORT_Type *portBase;
    portBase = s_portBases[instance];
    return portBase->ISFR;
}

/*!
 * brief Clears the multiple FGPIO pin interrupt status flag.
 *
 * param base FGPIO peripheral base pointer (FGPIOA, FGPIOB, FGPIOC, and so on.)
 * param mask FGPIO pin number macro
 */
void FGPIO_PortClearInterruptFlags(FGPIO_Type *base, uint32_t mask)
{
    uint8_t instance;
    instance = (uint8_t)FGPIO_GetInstance(base);
    PORT_Type *portBase;
    portBase       = s_portBases[instance];
    portBase->ISFR = mask;
}
#endif
#if defined(FSL_FEATURE_FGPIO_HAS_ATTRIBUTE_CHECKER) && FSL_FEATURE_FGPIO_HAS_ATTRIBUTE_CHECKER
/*!
 * brief The FGPIO module supports a device-specific number of data ports, organized as 32-bit
 * words. Each 32-bit data port includes a GACR register, which defines the byte-level
 * attributes required for a successful access to the GPIO programming model. The attribute controls for the 4 data
 * bytes in the GACR follow a standard little endian
 * data convention.
 *
 * param base      FGPIO peripheral base pointer (FGPIOA, FGPIOB, FGPIOC, and so on.)
 * param attribute FGPIO checker attribute
 */
void FGPIO_CheckAttributeBytes(FGPIO_Type *base, gpio_checker_attribute_t attribute)
{
    base->GACR = ((uint32_t)attribute << FGPIO_GACR_ACB0_SHIFT) | ((uint32_t)attribute << FGPIO_GACR_ACB1_SHIFT) |
                 ((uint32_t)attribute << FGPIO_GACR_ACB2_SHIFT) | ((uint32_t)attribute << FGPIO_GACR_ACB3_SHIFT);
}
#endif

#endif /* FSL_FEATURE_SOC_FGPIO_COUNT */
