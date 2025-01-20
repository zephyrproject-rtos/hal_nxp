/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for CE wrapper/driver functions on ARM
==========================================================================*/

#include "fsl_ce_matrix.h"
#include "fsl_ce_cmd.h"

int CE_MatrixAdd_Q15(int16_t *pDst, int16_t *pA, int16_t *pB, int M, int N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 2;
    cmdstruct.arg_ptr_array[0]   = (void *)pDst;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pB;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = N;

    status = CE_CmdAdd(kCE_Cmd_MAT_ADD_Q15, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixAdd_Q31(int32_t *pDst, int32_t *pA, int32_t *pB, int M, int N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 2;
    cmdstruct.arg_ptr_array[0]   = (void *)pDst;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pB;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = N;

    status = CE_CmdAdd(kCE_Cmd_MAT_ADD_Q31, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixAdd_F32(float *pDst, float *pA, float *pB, int M, int N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 2;
    cmdstruct.arg_ptr_array[0]   = (void *)pDst;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pB;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = N;

    status = CE_CmdAdd(kCE_Cmd_MAT_ADD_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixElemMul_F32(float *pDst, float *pA, float *pB, int M, int N)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 2;
    cmdstruct.arg_ptr_array[0]   = (void *)pDst;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pB;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = N;

    status = CE_CmdAdd(kCE_Cmd_MAT_HADAMARDMULT_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixMul_F32(float *pDst, float *pA, float *pB, int M, int N, int P)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 3;
    cmdstruct.arg_ptr_array[0]   = (void *)pDst;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pB;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = N;
    cmdstruct.arg_param_array[2] = P;

    status = CE_CmdAdd(kCE_Cmd_MAT_MULT_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixMul_CF32(float *pDst, float *pA, float *pB, int M, int N, int P)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 3;
    cmdstruct.arg_ptr_array[0]   = (void *)pDst;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pB;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = N;
    cmdstruct.arg_param_array[2] = P;

    status = CE_CmdAdd(kCE_Cmd_MAT_MULT_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixInv_F32(float *pAinv, float *pA, int M)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 2;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pAinv;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_param_array[0] = M;

    status = CE_CmdAdd(kCE_Cmd_MAT_INV_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixInvSymm_F32(float *pAinv, float *pA, int M)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 2;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pAinv;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_param_array[0] = M;

    status = CE_CmdAdd(kCE_Cmd_MAT_INV_SYMM_F32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixInv_CF32(float *pAinv, float *pA, int M)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 2;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pAinv;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_param_array[0] = M;

    status = CE_CmdAdd(kCE_Cmd_MAT_INV_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixInvHerm_CF32(
    float *pAinv, float *pA, float *pScratch, int M, uint8_t flag_packedInput, uint8_t flag_cholInv)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 3;
    cmdstruct.arg_ptr_array[0]   = (void *)pAinv;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pScratch;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = flag_packedInput;
    cmdstruct.arg_param_array[2] = flag_cholInv;

    status = CE_CmdAdd(kCE_Cmd_MAT_INV_HERM_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixChol_CF32(float *pL, float *pA, int M)
{
    int status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 2;
    cmdstruct.n_param_args       = 1;
    cmdstruct.arg_ptr_array[0]   = (void *)pL;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_param_array[0] = M;

    status = CE_CmdAdd(kCE_Cmd_MAT_CHOL_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

int CE_MatrixEvdHerm_CF32(float *pLambdaOut,
                          float *pUout,
                          float *pUin,
                          float *pScratch,
                          int M,
                          float tol,
                          int max_iter,
                          uint8_t flag_packedInput)
{
    int status;
    int *ptemp = (int *)&tol;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 4;
    cmdstruct.n_param_args       = 4;
    cmdstruct.arg_ptr_array[0]   = (void *)pLambdaOut;
    cmdstruct.arg_ptr_array[1]   = (void *)pUout;
    cmdstruct.arg_ptr_array[2]   = (void *)pScratch;
    cmdstruct.arg_ptr_array[3]   = (void *)pUin;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = *ptemp;
    cmdstruct.arg_param_array[2] = max_iter;
    cmdstruct.arg_param_array[3] = flag_packedInput;

    status = CE_CmdAdd(kCE_Cmd_MAT_EVD_HERM_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}
