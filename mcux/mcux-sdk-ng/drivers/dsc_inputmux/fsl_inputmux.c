/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_inputmux.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_inputmux"
#endif

#if defined(INPUTMUX_RSTS)
#define INPUTMUX_RESETS_ARRAY INPUTMUX_RSTS
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Pointers to INPUTMUX bases for each instance. */
static void *const s_inputmuxBases[] = INPUTMUX_BASE_PTRS;

#if defined(INPUTMUX_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_inputmuxResets[] = INPUTMUX_RESETS_ARRAY;
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map INPUTMUX instance number to clock name. */
static const clock_ip_name_t s_inputmuxClockName[] = INPUTMUX_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Initialize INPUTMUX peripheral.
 *
 * This function enables the INPUTMUX clock.
 *
 * @param instance INPUTMUX instance number.
 */
void INPUTMUX_Init(inputmux_instance_t instance)
{
    assert(instance < ARRAY_SIZE(s_inputmuxBases));

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_inputmuxClockName[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(INPUTMUX_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_inputmuxResets[instance]);
#endif
}

/*!
 * @brief Deinitialize INPUTMUX peripheral.
 *
 * This function disables the INPUTMUX clock.
 *
 * @param instance INPUTMUX instance number.
 */
void INPUTMUX_Deinit(inputmux_instance_t instance)
{
    assert(instance < ARRAY_SIZE(s_inputmuxBases));

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_inputmuxClockName[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * @brief Attaches a signal
 *
 * This function attaches multiplexed signals from INPUTMUX to target signals.
 * For example, to attach frequency measurement reference clock:
 * @code
 *      INPUTMUX_AttachSignal(kINPUTMUX_FreqMeas, 0U, kINPUTMUX_MainClkToFreqmeasRef);
 * @endcode
 *
 * @param index The serial number of destination register in the group of INPUTMUX registers with same name.
 * @param connection Applies signal from source signals collection to target signal.
 */
void INPUTMUX_AttachSignal(uint16_t index, inputmux_connection_t connection)
{
    uint32_t instance;
    uint32_t pmuxReg;
    uint32_t output;
    uint32_t connection_id;
    uint32_t base;

    connection_id = (uint32_t)connection;

    /* extract instance from connection */
    instance = PMUX_INSTANCE(connection_id);

    assert(instance < ARRAY_SIZE(s_inputmuxBases));

    base = (uint32_t)s_inputmuxBases[instance];

    /* extract pmux to be used */
    pmuxReg = PMUX_REG(connection_id);
    /* extract function number */
    output = PMUX_OUTPUT(connection_id);
    /* program signal */
    *(volatile uint32_t *)(base + pmuxReg + (index * 2U)) = output;
}
