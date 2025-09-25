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
/*!
 * @brief Maximum loop wait time for CE computation.
 *
 * When CE is computing, driver will wait for the computation to complete.
 * This parameter defines how many loops to check completion before return timeout.
 * If defined as 0, driver will wait forever until completion.
 */
#ifndef CE_COMPUTE_TIMEOUT
    #ifdef CONFIG_CE_COMPUTE_TIMEOUT
        #define CE_COMPUTE_TIMEOUT CONFIG_CE_COMPUTE_TIMEOUT
    #else
        #define CE_COMPUTE_TIMEOUT 0U
    #endif
#endif

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
 * @brief Initializes the CM33-ZV2117 command buffer.
 * @details This function must to be called once after power-up or reset,
 * or when the command queue mode needs to be changed. Once configured,
 * the command mode remains unchanged till reset or re-initialization.
 * 
 * @param [out] psCmdBuffer  Pointer to the command buffer structure.
 * Must be allocated in ARM memory (not ZV2117).
 * @param [in]  cmdbuffer    Command buffer. Must be 256 words in ZV2117 data memory.
 * @param [in]  statusbuffer Status buffer. Must be 134 words in ZV2117 data memory.
 * @param [in]  cmdmode      Command mode. One of:
 * - @ref kCE_CmdModeOneNonBlocking
 * - @ref kCE_CmdModeMultipleNonBlocking
 * - @ref kCE_CmdModeOneBlocking
 * - @ref kCE_CmdModeMultipleBlocking
 *
 * @retval 0 Initialization is successful.
 */
int32_t CE_CmdInitBuffer(ce_cmdbuffer_t *psCmdBuffer,
                     volatile uint32_t cmdbuffer[],
                     volatile int32_t statusbuffer[],
                     ce_cmd_mode_t cmdmode);

/*!
 * @brief Resets the CM33-ZV2117 command queue.
 *
 * @details Any pending commands in the queue will be flushed.
 * 
 * @retval 0 Reset is successful.
 */
int32_t CE_CmdReset(void);

/*!
 * @brief Adds a command to the command queue.
 *
 * @param [in] cmd     Command name. Choose from the enum description
 * in @ref fsl_ce_if.h. Not all of the cmd are implemented
 * in the current release.
 * @param [in] cmdargs Arguments structure detailing the arguments
 * for the function/command.
 * 
 * @retval 0  Command added successfully.
 * @retval -1 Command not added (queue is full).
 */
int32_t CE_CmdAdd(ce_cmd_t cmd, ce_cmdstruct_t *cmdargs);

/*!
 * @brief Launches the ZV2117 with the current command queue.
 *
 * @param [in] force_launch
 * - 1: Launches the queue regardless of the command mode.
 * - 0: Launches only if in single-command mode. Otherwise, does nothing.
 *
 * @retval 0 Launch is successful.
 */
int32_t CE_CmdLaunch(int32_t force_launch);

/*!
 * @brief Launches the current command queue and waits for completion.
 * 
 * @retval 0 Launch is successful.
 */
int32_t CE_CmdLaunchBlocking(void);

/*!
 * @brief Launches the current command queue and returns immediately.
 * 
 * @details ZV2117 will send an interrupt via MUA->GCR to ARM upon task completion.
 * Alternatively, the user can poll for completion. 
 * 
 * If using interrupt, the user must call CE_CmdReset() in the IRQ handler.
 * IRQ::DSP_IRQn must be enabled.
 * 
 * The user can optionally also poll to figure out the command queue execution status.
 * 
 * @retval 0 Launch is successful.
 */
int32_t CE_CmdLaunchNonBlocking(void);

/*!
 * @brief Checks the execution status of the current command queue.
 * Only applicable in non-blocking mode.
 * 
 * @return
 * - @ref CE_STATUS_BUSY ZV2117 is still executing.
 * - @ref CE_STATUS_IDLE Execution completed; ZV2117 is ready for new commands.
 */
int32_t CE_CmdCheckStatus(void);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_CMD_H*/
