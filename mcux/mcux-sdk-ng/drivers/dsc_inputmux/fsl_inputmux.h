/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_INPUTMUX_H_
#define FSL_INPUTMUX_H_

#include "fsl_inputmux_connections.h"
#include "fsl_common.h"

/*!
 * @addtogroup inputmux_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Group interrupt driver version for SDK */
#define FSL_INPUTMUX_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Initialize INPUTMUX peripheral.
 *
 * This function enables the INPUTMUX clock.
 *
 * @param instance INPUTMUX instance number.
 */
void INPUTMUX_Init(inputmux_instance_t instance);

/*!
 * @brief Deinitialize INPUTMUX peripheral.
 *
 * This function disables the INPUTMUX clock.
 *
 * @param instance INPUTMUX instance number.
 */
void INPUTMUX_Deinit(inputmux_instance_t instance);

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
void INPUTMUX_AttachSignal(uint16_t index, inputmux_connection_t connection);

#ifdef __cplusplus
}
#endif

/*! @} */

#endif /* FSL_INPUTMUX_H_ */
