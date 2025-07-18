/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for CE wrapper/driver functions on ARM
==========================================================================*/

#include "fsl_ce_basic.h"
#include "fsl_ce_cmd.h"

int CE_ExecCmd()
{
    int status = CE_CmdLaunch(1);
    return status;
}

int CE_NullCmd()
{
    int status;
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

int CE_Copy(int *pDst, int *pSrc, const int N)
{
    int status;

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
