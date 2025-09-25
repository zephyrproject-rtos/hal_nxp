/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for CE wrapper/driver functions on ARM
==========================================================================*/

#include "fsl_ce_basic.h"
#include "fsl_ce_cmd.h"

/*!
 * brief Executes commands in the command queue.
 * 
 * return Command execution status.
 */
int32_t CE_ExecCmd(void)
{
    int32_t status = CE_CmdLaunch(1);

    return status;
}

/*!
 * brief Sends a basic command to verify that ZV2117 is operational
 * and that the command interface is functioning properly.
 *
 * details This function passes through the command processing interface
 * and returns a success status.
 * 
 * return Command execution status.
 */
int32_t CE_NullCmd(void)
{
    int32_t status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args   = 0;
    cmdstruct.n_param_args = 0;

    status = CE_CmdAdd(kCE_Cmd_NULLCMD, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

/*!
 * brief Copies data between buffers in the ZV2117 memory section.
 *
 * details Copies a specified number of 32-bit words from the source
 * to the destination buffer. Both buffers must reside in the ZV2117
 * data memory section.
 *
 * param [out] pDst Pointer to destination buffer
 * param [in]  pSrc Pointer to source buffer
 * param [in]  N    Number of 32-bit words to copy
 *
 * return Command execution status.
 */
int32_t CE_Copy(int32_t *pDst, int32_t *pSrc, const int32_t N)
{
    int32_t status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 2;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pDst;
    cmdstruct.arg_ptr_array[1]   = (void *)pSrc;
    cmdstruct.arg_param_array[0] = N;

    status = CE_CmdAdd(kCE_Cmd_ZVCOPY, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}
