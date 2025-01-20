/*
 * The Clear BSD License
 * Copyright 2014, NXP
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FSL_IOCON_H_
#define FSL_IOCON_H_

#include "fsl_common.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.jn_iocon"
#endif

/*!
 * @addtogroup jn_iocon
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief IOCON driver version 2.0.0. */
#define LPC_IOCON_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/**
 * @brief Array of IOCON pin definitions passed to IOCON_SetPinMuxing() must be in this format
 */
typedef struct _iocon_group
{
    uint32_t port : 8;      /* Pin port */
    uint32_t pin : 8;       /* Pin number */
    uint32_t modefunc : 16; /* Function and mode */
} iocon_group_t;

/**
 * @brief IOCON function and mode selection definitions
 * @note See the User Manual for specific modes and functions supported by the various pins.
 */
#define IOCON_FUNC0 IOCON_PIO_FUNC(0) /*!< Selects pin function 0 */
#define IOCON_FUNC1 IOCON_PIO_FUNC(1) /*!< Selects pin function 1 */
#define IOCON_FUNC2 IOCON_PIO_FUNC(2) /*!< Selects pin function 2 */
#define IOCON_FUNC3 IOCON_PIO_FUNC(3) /*!< Selects pin function 3 */
#define IOCON_FUNC4 IOCON_PIO_FUNC(4) /*!< Selects pin function 4 */
#define IOCON_FUNC5 IOCON_PIO_FUNC(5) /*!< Selects pin function 5 */
#define IOCON_FUNC6 IOCON_PIO_FUNC(6) /*!< Selects pin function 6 */
#define IOCON_FUNC7 IOCON_PIO_FUNC(7) /*!< Selects pin function 7 */

#define IOCON_MODE_PULLUP   IOCON_PIO_MODE(0) /*!< Selects pull-up function */
#define IOCON_MODE_REPEATER IOCON_PIO_MODE(1) /*!< Selects pin repeater function */
#define IOCON_MODE_INACT    IOCON_PIO_MODE(2) /*!< No addition pin function */
#define IOCON_MODE_PULLDOWN IOCON_PIO_MODE(3) /*!< Selects pull-down function */

#define IOCON_HYS_EN    (0x1 << 5)         /*!< Enables hysteresis ??*/
#define IOCON_GPIO_MODE IOCON_PIO_SLEW0(1) /*!< GPIO Mode */
#define IOCON_I2C_SLEW  IOCON_PIO_SLEW0(1) /*!< I2C Slew Rate Control */

#define IOCON_INV_EN IOCON_PIO_INVERT(1) /*!< Enables invert function on input */

#define IOCON_ANALOG_EN  IOCON_PIO_DIGIMODE(0) /*!< Enables analog function by setting 0 to bit 7 */
#define IOCON_DIGITAL_EN IOCON_PIO_DIGIMODE(1) /*!< Enables digital function by setting 1 to bit 7(default) */

#define IOCON_STDI2C_EN IOCON_PIO_FILTEROFF(1) /*!< I2C standard mode/fast-mode */

#define IOCON_INPFILT_OFF IOCON_PIO_FILTEROFF(1) /*!< Input filter Off for GPIO pins */
#define IOCON_INPFILT_ON  IOCON_PIO_FILTEROFF(0) /*!< Input filter On for GPIO pins */

#define IOCON_SLEW1_OFF IOCON_PIO_SLEW1(0) /*!< Driver Slew Rate Control */
#define IOCON_SLEW1_ON  IOCON_PIO_SLEW1(1) /*!< Driver Slew Rate Control */

#define IOCON_FASTI2C_EN (IOCON_INPFILT_ON | IOCON_SLEW1_ON) /*!< I2C Fast-mode Plus and high-speed slave */

#define IOCON_OPENDRAIN_EN IOCON_PIO_OD(1) /*!< Enables open-drain function */

#define IOCON_S_MODE_0CLK IOCON_PIO_SSEL(0) /*!< Bypass input filter */
#define IOCON_S_MODE_1CLK IOCON_PIO_SSEL(1) /*!< Input pulses shorter than 1 filter clock are rejected */
#define IOCON_S_MODE_2CLK IOCON_PIO_SSEL(2) /*!< Input pulses shorter than 2 filter clock2 are rejected */
#define IOCON_S_MODE_3CLK IOCON_PIO_SSEL(3) /*!< Input pulses shorter than 3 filter clock2 are rejected */

/* Set IO clamping to the DIO : freeze the IO state.
 * Requires SYSCON->RETENTIONCTRL.IOCLAMPING=1 . Automatically set in powerdown */
#define IOCON_IO_CLAMPING_NORMAL_MFIO    (1 << 11)
#define IOCON_IO_CLAMPING_COMBO_MFIO_I2C (1 << 12) /* Use this flag for PIO11 and PIO12 only */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @brief   Sets I/O Control pin mux
 * @param   base        : The base of IOCON peripheral on the chip
 * @param   port        : GPIO port to mux
 * @param   pin         : GPIO pin to mux
 * @param   modefunc    : OR'ed values of type IOCON_*
 * @return  Nothing
 */
__STATIC_INLINE void IOCON_PinMuxSet(IOCON_Type *base, uint8_t port, uint8_t pin, uint32_t modefunc)
{
    base->PIO[port][pin] = modefunc;
}

/**
 * @brief   Set all I/O Control pin muxing
 * @param   base        : The base of IOCON peripheral on the chip
 * @param   pinArray    : Pointer to array of pin mux selections
 * @param   arrayLength : Number of entries in pinArray
 * @return  Nothing
 */
__STATIC_INLINE void IOCON_SetPinMuxing(IOCON_Type *base, const iocon_group_t *pinArray, uint32_t arrayLength)
{
    uint32_t i;

    for (i = 0; i < arrayLength; i++)
    {
        IOCON_PinMuxSet(base, pinArray[i].port, pinArray[i].pin, pinArray[i].modefunc);
    }
}

/**
 * @brief   Sets I/O Control pin mux pull select
 * @param   base        : The base of IOCON peripheral on the chip
 * @param   port        : GPIO port to mux
 * @param   pin         : GPIO pin to mux
 * @param   pull_select : OR'ed values of type IOCON_*
 * @return  Nothing
 */
__STATIC_INLINE void IOCON_PullSet(IOCON_Type *base, uint8_t port, uint8_t pin, uint8_t pull_select)
{
    uint32_t reg = base->PIO[port][pin];
    reg &= ~IOCON_PIO_MODE_MASK;
    reg |= IOCON_PIO_MODE(pull_select);
    base->PIO[port][pin] = reg;
}

/**
 * @brief   Sets I/O Control pin mux pull select
 * @param   base        : The base of IOCON peripheral on the chip
 * @param   port        : GPIO port to mux
 * @param   pin         : GPIO pin to mux
 * @param   func        : Pinmux function
 * @return  Nothing
 */
__STATIC_INLINE void IOCON_FuncSet(IOCON_Type *base, uint8_t port, uint8_t pin, uint8_t func)
{
    uint32_t reg = base->PIO[port][pin];
    reg &= ~IOCON_PIO_FUNC_MASK;
    reg |= IOCON_PIO_FUNC(func);
    base->PIO[port][pin] = reg;
}
/*! @} */

#if defined(__cplusplus)
}
#endif

#endif /* FSL_IOCON_H_ */
