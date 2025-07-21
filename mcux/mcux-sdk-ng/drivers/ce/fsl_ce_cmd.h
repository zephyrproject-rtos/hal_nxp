/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CE_CMD_H
#define FSL_CE_CMD_H

#include "fsl_ce_if.h"

#define DSP0_MU_BASE_ADDR MUA_BASE

/*!
 * @ingroup ce
 * @defgroup ce_cmd CE Command Functions
 * @brief Functional API definitions for command to communicate with CE.
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Initalizes the ARM-CE command buffer
 *
 * Initalizes the ARM-CE command buffer. Needs to called on power-up or reset
 * or if the command mode needs to be changed.
 * @param[in] psCmdBuffer  Pointer to the command buffer structure, application shall
 * allocate it, and it shall be in CE memory.
 * @param[in] cmdbuffer    The command buffer memory. Size of the buffer should be 256.
 * @param[in] statusbuffer The status buffer memory. Size of the buffer should be 134.
 * @param[in] cmdmode Whether one command or multi command queue, and, blocking or non-blocking
 * call
 *
 * @return Currently only return 0.
 */
int CE_CmdInitBuffer(ce_cmdbuffer_t *psCmdBuffer,
                     volatile uint32_t cmdbuffer[],
                     volatile uint32_t statusbuffer[],
                     ce_cmd_mode_t cmdmode);

/*!
 * @brief Resets the command queue
 *
 * Any pending commands in the queue will be flushed.
 *
 * @return Currently only return 0.
 */
int CE_CmdReset();

/*!
 * @brief Adds a command to the command queue
 *
 * @param cmd Specifies the command name
 * @param cmdargs Defines all arguments for the command
 * @retval 0  Command added successfully
 * @retval -1 Command not added since command queue is at maximum limit
 */
int CE_CmdAdd(ce_cmd_t cmd, ce_cmdstruct_t *cmdargs);

/*!
 * @brief Launches the command queue for execution on CE
 *
 * @param force_launch Specifies the mode
 *    - 1: executes the queue regardless of the command mode
 *    - 0: executes the queue only if in ONE cmd mode. Otherwise, does nothing
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_CmdLaunch(int force_launch);

/*!
 * @brief Launches the current command queue and returns upon completion of the queue on CE
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_CmdLaunchBlocking();

/*!
 * @brief Launches the current command queue and returns without waiting for completion on CE
 *
 * CE Will send an interrupt via MUA->GCR to ARM upon completion of task. User can also poll to check for completion.
 * User has to call CE_CmdReset() in the IRQ handler. IRQ::DSP_IRQn needs to be enabled.
 *
 * @return Currently only return 0.
 */
int CE_CmdLaunchNonBlocking();

/*!
 * @brief Checks the command queue execution status on CE
 *
 * @retval 0 Task completed and CE is ready for next command(s)
 * @retval 1 Task still running; CE is busy
 */
int CE_CmdCheckStatus();

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_CMD_H*/
