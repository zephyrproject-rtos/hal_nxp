/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file gpio_driver.h
 * @brief The gpio_driver.h file containes the Generic Irq implmentation for the i.MXRT1050 gpio.
*/

#ifndef __DRIVER_GPIO_H__
#define __DRIVER_GPIO_H__

#include "Driver_Common.h"
#include "Driver_GPIO.h"
#include "fsl_common.h"
#include "fsl_gpio.h"

#define PIN_SET 1U
#define PIN_CLR 0U

/**
\brief GPIO PORT NAMES.
*/
typedef enum port_number
{
    GPIO1_NUM = 0,
    GPIO2_NUM = 1,
    GPIO3_NUM = 2,
    GPIO4_NUM = 3,
    GPIO5_NUM = 4,
    TOTAL_NUMBER_PORT
} port_number_t;

/*!
 * @brief The GPIO Pin Configuration i.MX SDK.
 */
typedef struct gpioConfigiMXSDK
{
    gpio_pin_config_t pinConfig;          /*!< General pin charactertics.*/
    gpio_interrupt_mode_t interruptMode;  /*!< Interrupt mode for a pin.*/
} gpioConfigiMXSDK_t;

/*!
 * @brief The GPIO pin handle for i.MX SDK.
 */
typedef struct gpioHandleiMXSDK
{
    GPIO_Type *base;           /*!< Base address of the GPIO Port.*/
    uint32_t pinNumber;        /*!< pin number start from 0 -31.*/
    uint32_t mask;             /*!< mask value for a pin.*/
    IRQn_Type irq;             /*!< IRQ Number for the port.*/
    port_number_t portNumber;  /*!< Port Number for the port.*/
    uint8_t pinStatus;         /*!< pin status.*/
} gpioHandleiMXSDK_t;

/*!
 * @brief The gpio isr object.
 */
typedef struct gpioIsrObj
{
    void *pUserData;              /*!< Pointer to a UserData.*/
    gpio_isr_handler_t isrHandle; /*!< pointer to isrHandle.*/
} gpioIsrObj_t;

/*!
 * @brief Macro to create a Gpio handle
 */
#define MAKE_GPIO_HANDLE(Base, PinNumber, Irq) \
    static gpioHandleKSDK_t PortName##PinNumber = {.base = Base,                          \
                                                   .pinNumber = PinNumber,                \
                                                   .irq = Irq};
extern GENERIC_DRIVER_GPIO Driver_GPIO_KSDK;

#endif // __DRIVER_GPIO_H__
