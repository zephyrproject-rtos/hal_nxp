/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for CE wrapper/driver FFT functions on ARM
==========================================================================*/

#include "fsl_ce_transform.h"
#include "fsl_ce_cmd.h"

int CE_TransformCFFT_F16(float *pY, float *pX, float *pScratch, int log2N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_CFFT_F16, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_TransformCFFT_F32(float *pY, float *pX, float *pScratch, int log2N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_CFFT_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_TransformIFFT_F16(float *pY, float *pX, float *pScratch, int log2N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_IFFT_F16, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_TransformIFFT_F32(float *pY, float *pX, float *pScratch, int log2N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pX;
    cmdstruct.arg_ptr_array[1]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[2]   = (void *)pY;
    cmdstruct.arg_param_array[0] = log2N;

    status = CE_CmdAdd(kCE_Cmd_IFFT_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}
