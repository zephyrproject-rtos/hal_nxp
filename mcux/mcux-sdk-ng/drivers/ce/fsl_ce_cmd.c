/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for Low level drivers for CM33-CE Driver
==========================================================================*/

#include "fsl_common.h"
#include "fsl_ce_cmd.h"
#include "fsl_mu.h"

#define CE_MU           MUA
#define CE_COMPUTE_DONE 0xD09EU

static ce_cmdbuffer_t *s_ce_cmdbuffer;

#define NOP1  __asm("NOP");
#define NOP4  NOP1 NOP1 NOP1 NOP1
#define NOP16 NOP4 NOP4 NOP4 NOP4
#define NOP32 NOP16 NOP16

/*!
 * brief Inserts a small delay using a NOP instruction.
 */
static inline void CE_CmdDelay(void)
{
    NOP32
}

/*!
 * brief Initializes the CM33-ZV2117 command buffer.
 * details This function must to be called once after power-up or reset,
 * or when the command queue mode needs to be changed. Once configured,
 * the command mode remains unchanged till reset or re-initialization.
 * 
 * param [out] psCmdBuffer  Pointer to the command buffer structure.
 * Must be allocated in ARM memory (not ZV2117).
 * param [in]  cmdbuffer    Command buffer. Must be 256 words in ZV2117 data memory.
 * param [in]  statusbuffer Status buffer. Must be 134 words in ZV2117 data memory.
 * param [in]  cmdmode      Command mode. One of:
 * - ref kCE_CmdModeOneNonBlocking
 * - ref kCE_CmdModeMultipleNonBlocking
 * - ref kCE_CmdModeOneBlocking
 * - ref kCE_CmdModeMultipleBlocking
 *
 * retval 0 Initialization is successful.
 */
int32_t CE_CmdInitBuffer(ce_cmdbuffer_t *psCmdBuffer,
                     volatile uint32_t cmdbuffer[],
                     volatile int32_t statusbuffer[],
                     ce_cmd_mode_t cmdmode)
{
    s_ce_cmdbuffer = psCmdBuffer;

    s_ce_cmdbuffer->cmdmode           = cmdmode;
    s_ce_cmdbuffer->buffer_base_ptr   = cmdbuffer;
    s_ce_cmdbuffer->status_buffer_ptr = statusbuffer;
    (void)CE_CmdReset();

    return 0;
}

/*!
 * brief Resets the CM33-ZV2117 command queue.
 *
 * details Any pending commands in the queue will be flushed.
 * 
 * retval 0 Reset is successful.
 */
int32_t CE_CmdReset(void)
{
    volatile uint32_t *cmd_base     = s_ce_cmdbuffer->buffer_base_ptr;

    *cmd_base                       = 0xCCCC;
    s_ce_cmdbuffer->next_buffer_ptr = cmd_base + 1;
    s_ce_cmdbuffer->n_cmd           = 0;

    return 0;
}

/*!
 * brief Adds a command to the command queue.
 *
 * param [in] cmd     Command name. Choose from the enum description
 * in ref fsl_ce_if.h. Not all of the cmd are implemented
 * in the current release.
 * param [in] cmdargs Arguments structure detailing the arguments
 * for the function/command.
 * 
 * retval 0  Command added successfully.
 * retval -1 Command not added (queue is full).
 */
int32_t CE_CmdAdd(ce_cmd_t cmd, ce_cmdstruct_t *cmdargs)
{
    int32_t addstatus;
    volatile uint16_t *nargsbase;
    uint16_t i;
    uint32_t size;
    volatile uint32_t *cmdbase;
    void **ptrargbase;
    int32_t *ptrparambase;

    if (s_ce_cmdbuffer->n_cmd < CE_CMD_MAX_CMDS_ZVQ)
    {
        size    = sizeof(void *) * cmdargs->n_ptr_args + sizeof(int32_t) * ((uint32_t)cmdargs->n_param_args + 1U) + sizeof(int16_t) * 2U;
        cmdbase = s_ce_cmdbuffer->next_buffer_ptr;

        *cmdbase = (uint32_t)cmd;

        nargsbase  = (volatile uint16_t *)(cmdbase + 1U);
        *nargsbase = cmdargs->n_ptr_args;
        nargsbase += 1;
        *nargsbase = cmdargs->n_param_args;
        nargsbase += 1;

        ptrargbase = (void **)nargsbase;
        for (i = 0; i < cmdargs->n_ptr_args; i++)
        {
            *ptrargbase = cmdargs->arg_ptr_array[i];
            ptrargbase += 1;
        }

        ptrparambase = (int32_t *)ptrargbase;
        for (i = 0; i < cmdargs->n_param_args; i++)
        {
            *ptrparambase = cmdargs->arg_param_array[i];
            ptrparambase += 1;
        }

        s_ce_cmdbuffer->n_cmd++;

        cmdbase += (size / sizeof(int32_t));
        s_ce_cmdbuffer->next_buffer_ptr = cmdbase;

        addstatus = 0;
    }
    else
    {
        addstatus = -1;
    }

    return addstatus;
}

/*!
 * brief Launches the ZV2117 with the current command queue.
 *
 * param [in] force_launch
 * - 1: Launches the queue regardless of the command mode.
 * - 0: Launches only if in single-command mode. Otherwise, does nothing.
 *
 * retval 0 Launch is successful.
 */
int32_t CE_CmdLaunch(int32_t force_launch)
{
    if (force_launch == 1)
    {
        if (s_ce_cmdbuffer->cmdmode > kCE_CmdModeMultipleNonBlocking)
        {
            return CE_CmdLaunchBlocking();
        }
        else
        {
            return CE_CmdLaunchNonBlocking();
        }
    }

    if (s_ce_cmdbuffer->cmdmode == kCE_CmdModeOneNonBlocking)
    {
        return CE_CmdLaunchNonBlocking();
    }

    if (s_ce_cmdbuffer->cmdmode == kCE_CmdModeOneBlocking)
    {
        return CE_CmdLaunchBlocking();
    }

    return 0;
}

/*!
 * brief Launches the current command queue and waits for completion.
 * 
 * retval 0 Launch is successful.
 */
int32_t CE_CmdLaunchBlocking(void)
{
    uint32_t n_cmd;
    status_t status = kStatus_Fail;

#if CE_COMPUTE_TIMEOUT
    uint32_t timeout = CE_COMPUTE_TIMEOUT;
#endif

    if (s_ce_cmdbuffer->n_cmd == 0U)
    {
        return -2; /* no commands to send */
    }

    /* write number of commands via TX2 reg */
    status = MU_SendMsg((MU_Type *)DSP0_MU_BASE_ADDR, 2U, s_ce_cmdbuffer->n_cmd);
    if (kStatus_Success != status)
    {
        assert(false);
    }

    CE_CmdDelay();
    /* launch CE by sending MU interrupt */
    status = MU_TriggerInterrupts((MU_Type *)DSP0_MU_BASE_ADDR, (uint32_t)kMU_GenInt0InterruptTrigger);
    if (kStatus_Success != status)
    {
        assert(false);
    }

    /* blocking: so poll till completion */
    /* completion is signaled when ZV2117 writes "D09E"to top of cmd buffer */
    n_cmd = *(s_ce_cmdbuffer->buffer_base_ptr);

    while (n_cmd != CE_COMPUTE_DONE)
    {
#if CE_COMPUTE_TIMEOUT
        if (--timeout == 0U)
        {
            return kStatus_Timeout;
        }
#endif
        CE_CmdDelay();
        n_cmd = *(s_ce_cmdbuffer->buffer_base_ptr);
    }

    (void)CE_CmdReset();

    /* read the status register */
    return *(s_ce_cmdbuffer->status_buffer_ptr + 1U);
}

/*!
 * brief Launches the current command queue and returns immediately.
 * 
 * details ZV2117 will send an interrupt via MUA->GCR to ARM upon task completion.
 * Alternatively, the user can poll for completion. 
 * 
 * If using interrupt, the user must call CE_CmdReset() in the IRQ handler.
 * IRQ::DSP_IRQn must be enabled.
 * 
 * The user can optionally also poll to figure out the command queue execution status.
 * 
 * retval 0 Launch is successful.
 */
int32_t CE_CmdLaunchNonBlocking(void)
{
    status_t status = kStatus_Fail;

    /* Launches non-blocking */
    if (s_ce_cmdbuffer->n_cmd == 0U)
    {
        return -2; /* no commands to send */
    }
    /* Write number of commands via TX2 reg,
     * set MSb to indicate non-blocking mode to ZENV: ZENV will send interrupt back in this case. */
    status = MU_SendMsg((MU_Type *)DSP0_MU_BASE_ADDR, 2U, 0x80000000U | s_ce_cmdbuffer->n_cmd);
    if (kStatus_Success != status)
    {
        assert(false);
    }

    CE_CmdDelay();

    /* launch CE by sending MU interrupt */
    status = MU_TriggerInterrupts((MU_Type *)DSP0_MU_BASE_ADDR, (uint32_t)kMU_GenInt0InterruptTrigger);
    if (kStatus_Success != status)
    {
        assert(false);
    }

    /* non-blocking: so return and the ARM core can resume other tasks */
    return 0;
}

/*!
 * brief Checks the execution status of the current command queue.
 * Only applicable in non-blocking mode.
 * 
 * return
 * - ref CE_STATUS_BUSY ZV2117 is still executing.
 * - ref CE_STATUS_IDLE Execution completed; ZV2117 is ready for new commands.
 */
int32_t CE_CmdCheckStatus(void)
{
    int32_t status         = -1;
    uint32_t n_cmd = *(s_ce_cmdbuffer->buffer_base_ptr);

    if (n_cmd != CE_COMPUTE_DONE)
    {
        status = CE_STATUS_BUSY; /* still running */
    }
    else
    {
        status = CE_STATUS_IDLE; /* completed */
        (void)CE_CmdReset();
    }

    return status;
}
