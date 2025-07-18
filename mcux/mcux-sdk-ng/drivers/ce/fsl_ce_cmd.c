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

static inline void CE_CmdDelay(void)
{
    NOP32
}

int CE_CmdInitBuffer(ce_cmdbuffer_t *psCmdBuffer,
                     volatile uint32_t cmdbuffer[],
                     volatile uint32_t statusbuffer[],
                     ce_cmd_mode_t cmdmode)
{
    s_ce_cmdbuffer = psCmdBuffer;

    s_ce_cmdbuffer->cmdmode           = cmdmode;
    s_ce_cmdbuffer->buffer_base_ptr   = (unsigned int *)cmdbuffer;
    s_ce_cmdbuffer->status_buffer_ptr = (int *)statusbuffer;
    CE_CmdReset();

    return 0;
}

int CE_CmdReset()
{
    unsigned int *cmd_base          = s_ce_cmdbuffer->buffer_base_ptr;
    *cmd_base                       = 0xCCCC;
    s_ce_cmdbuffer->next_buffer_ptr = cmd_base + 1;
    s_ce_cmdbuffer->n_cmd           = 0;

    return 0;
}

int CE_CmdAdd(ce_cmd_t cmd, ce_cmdstruct_t *cmdargs)
{
    int i, size, addstatus;
    unsigned short *nargsbase;
    unsigned int *cmdbase;
    void **ptrargbase;
    int *ptrparambase;

    if (s_ce_cmdbuffer->n_cmd < CE_CMD_MAX_CMDS_ZVQ)
    {
        size    = sizeof(void *) * cmdargs->n_ptr_args + sizeof(int) * (cmdargs->n_param_args + 1) + sizeof(short) * 2;
        cmdbase = s_ce_cmdbuffer->next_buffer_ptr;

        *cmdbase = (unsigned int)cmd;

        nargsbase  = (unsigned short *)(cmdbase + 1);
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

        ptrparambase = (int *)ptrargbase;
        for (i = 0; i < cmdargs->n_param_args; i++)
        {
            *ptrparambase = cmdargs->arg_param_array[i];
            ptrparambase += 1;
        }

        s_ce_cmdbuffer->n_cmd++;

        cmdbase += (size / sizeof(int));
        s_ce_cmdbuffer->next_buffer_ptr = cmdbase;

        addstatus = 0;
    }
    else
    {
        addstatus = -1;
    }

    return addstatus;
}

int CE_CmdLaunch(int force_launch)
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

int CE_CmdLaunchBlocking()
{
    unsigned int n_cmd;

    if (s_ce_cmdbuffer->n_cmd == 0)
    {
        return -2; /* no commands to send */
    }

    /* write number of commands via TX2 reg */
    MU_SendMsg((MU_Type *)DSP0_MU_BASE_ADDR, 2U, s_ce_cmdbuffer->n_cmd);
    CE_CmdDelay();
    /* launch CE by sending MU interrupt */
    status_t status = MU_TriggerInterrupts((MU_Type *)DSP0_MU_BASE_ADDR, kMU_GenInt0InterruptTrigger);

    if (kStatus_Success != status)
    {
        assert(false);
    }

    /* blocking: so poll till completion */
    /* completion is signaled when ZV2117 writes "D09E"to top of cmd buffer */
    n_cmd = *(s_ce_cmdbuffer->buffer_base_ptr);
    while (n_cmd != CE_COMPUTE_DONE)
    {
        CE_CmdDelay();
        n_cmd = *(s_ce_cmdbuffer->buffer_base_ptr);
    }

    CE_CmdReset();

    /* read the status register */
    return *(s_ce_cmdbuffer->status_buffer_ptr + 1);
}

int CE_CmdLaunchNonBlocking()
{
    /* Launches non-blocking */
    if (s_ce_cmdbuffer->n_cmd == 0)
    {
        return -2; /* no commands to send */
    }
    /* Write number of commands via TX2 reg,
     * set MSb to indicate non-blocking mode to ZENV: ZENV will send interrupt back in this case. */
    MU_SendMsg((MU_Type *)DSP0_MU_BASE_ADDR, 2U, 0x80000000 | s_ce_cmdbuffer->n_cmd);
    CE_CmdDelay();

    /* launch CE by sending MU interrupt */
    status_t status = MU_TriggerInterrupts((MU_Type *)DSP0_MU_BASE_ADDR, kMU_GenInt0InterruptTrigger);
    if (kStatus_Success != status)
    {
        assert(false);
    }

    /* non-blocking: so return and the ARM core can resume other tasks */
    return 0;
}

int CE_CmdCheckStatus()
{
    int status         = -1;
    unsigned int n_cmd = *(s_ce_cmdbuffer->buffer_base_ptr);

    if (n_cmd != CE_COMPUTE_DONE)
    {
        status = CE_STATUS_BUSY; /* still running */
    }
    else
    {
        status = CE_STATUS_IDLE; /* completed */
        CE_CmdReset();
    }

    return status;
}
