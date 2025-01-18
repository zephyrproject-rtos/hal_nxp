/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpio.h"
#include "fsl_port.h"

struct dbg_io {
    uint32_t pin;
    void* gpio;
    void* port;
};

struct dbg_io dbg_ios[] = {
    {1, GPIOB, PORTB},      /* J12 - 5 */
    {2, GPIOB, PORTB},      /* J12 - 4 */
    {3, GPIOB, PORTB},      /* J12 - 6 */
    {4, GPIOB, PORTB},      /* J12 - 3 */
    {2, GPIOD, PORTD},      /* J4  - 2 */
    {3, GPIOD, PORTD},      /* J4  - 3 */
};

const uint32_t n_dbg_ios = sizeof(dbg_ios) / sizeof(dbg_ios[0]);

void Dbg_IO_Init(void)
{
    gpio_pin_config_t config;
    config.pinDirection = kGPIO_DigitalOutput;
    config.outputLogic = 0;

    for (uint32_t i = 0U; i < n_dbg_ios; i++) {
        PORT_SetPinMux(dbg_ios[i].port, dbg_ios[i].pin, kPORT_MuxAsGpio);
        GPIO_PinInit(dbg_ios[i].gpio, dbg_ios[i].pin, &config);

        /* Test toggle */
        GPIO_PinWrite(dbg_ios[i].gpio, dbg_ios[i].pin, 0U);
        GPIO_PinWrite(dbg_ios[i].gpio, dbg_ios[i].pin, 1U);
        GPIO_PinWrite(dbg_ios[i].gpio, dbg_ios[i].pin, 0U);
        GPIO_PinWrite(dbg_ios[i].gpio, dbg_ios[i].pin, 1U);
        GPIO_PinWrite(dbg_ios[i].gpio, dbg_ios[i].pin, 0U);
        GPIO_PinWrite(dbg_ios[i].gpio, dbg_ios[i].pin, 1U);
        GPIO_PinWrite(dbg_ios[i].gpio, dbg_ios[i].pin, 0U);
    }
}

void Dbg_IO_Set(unsigned long io, unsigned short level)
{
    if (io < n_dbg_ios)
        GPIO_PinWrite(dbg_ios[io].gpio, dbg_ios[io].pin, level);
}