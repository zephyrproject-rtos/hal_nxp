/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for CE wrapper/driver functions on ARM
==========================================================================*/

#include "fsl_ce_matrix.h"
#include "fsl_ce_cmd.h"

/*!
 * brief Calculates the sum of two real 16-bit integer (Q15) matrices.
 *
 * details Computes C = A + B, where A, B, and C are an M × N real int16_t matrices.
 * All matrices are assumed to have the same format and dimensions.
 *
 * param [out] pDst Pointer to the output matrix C (size M × N).
 * param [in]  pA   Pointer to the input matrix A (size M × N).
 * param [in]  pB   Pointer to the input matrix B (size M × N).
 * param [in]  M    Number of rows of matrices A, B, and C.
 * param [in]  N    Number of columns of matrices A, B, and C.
 *
 * return Command execution status.
 */
int32_t CE_MatrixAdd_Q15(int16_t *pDst, int16_t *pA, int16_t *pB, int32_t M, int32_t N)
{
    int32_t status;

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

/*!
 * brief Calculates the sum of two real 32-bit integer (Q31) matrices.
 *
 * details Computes C = A + B, where A, B, and C are an M × N real int32_t matrices.
 * All matrices are assumed to have the same format and dimensions.
 *
 * param [out] pDst Pointer to the output matrix C (size M × N).
 * param [in]  pA   Pointer to the input matrix A (size M × N).
 * param [in]  pB   Pointer to the input matrix B (size M × N).
 * param [in]  M    Number of rows of matrices A, B, and C.
 * param [in]  N    Number of columns of matrices A, B, and C.
 *
 * return Command execution status.
 */
int32_t CE_MatrixAdd_Q31(int32_t *pDst, int32_t *pA, int32_t *pB, int32_t M, int32_t N)
{
    int32_t status;

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

/*!
 * brief Calculates the sum of two real 32-bit floating-point matrices.
 *
 * details Computes C = A + B, where A, B, and C are an M × N real float32 matrices.
 * All matrices are assumed to have the same format and dimensions.
 *
 * param [out] pDst Pointer to the output matrix C (size M × N).
 * param [in]  pA   Pointer to the input matrix A (size M × N).
 * param [in]  pB   Pointer to the input matrix B (size M × N).
 * param [in]  M    Number of rows of matrices A, B, and C.
 * param [in]  N    Number of columns of matrices A, B, and C.
 *
 * return Command execution status.
 */
int32_t CE_MatrixAdd_F32(float *pDst, float *pA, float *pB, int32_t M, int32_t N)
{
    int32_t status;

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

/*!
 * brief Calculates the element-wise product of two real 32-bit floating-point matrices.
 *
 * details Computes C = A .× B, where A, B, and C are an M × N real float32 matrices.
 * All matrices are assumed to have the same format and dimensions.
 *
 * param [out] pDst Pointer to the output matrix C (size M × N).
 * param [in]  pA   Pointer to the input matrix A (size M × N).
 * param [in]  pB   Pointer to the input matrix B (size M × N).
 * param [in]  M    Number of rows of matrices A, B, and C.
 * param [in]  N    Number of columns of matrices A, B, and C.
 *
 * return Command execution status.
 */
int32_t CE_MatrixElemMul_F32(float *pDst, float *pA, float *pB, int32_t M, int32_t N)
{
    int32_t status;

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

/*!
 * brief Calculates the matrix product of two real 32-bit floating-point matrices.
 *
 * details Computes C = A × B, where:
 * - A is an M × N real float32 matrix,
 * - B is an N × P real float32 matrix,
 * - C is the resulting M × P real float32 matrix.
 *
 * All matrices are assumed to be in row-major format.
 *
 * param [out] pDst Pointer to the output matrix C (size M × P)
 * param [in]  pA   Pointer to the input matrix A (size M × N).
 * param [in]  pB   Pointer to the input matrix B (size N × P).
 * param [in]  M    Number of rows of matrix A.
 * param [in]  N    Number of columns in matrix A (and rows in matrix B).
 * param [in]  P    Number of columns of matrix B.
 *
 * return Command execution status.
 *
 * note Data precision and format is as defined by the argument type.
 * Limits on max value of N:
 * - For F32: N < 128;
 * - For CF32: N < 64.
 */
int32_t CE_MatrixMul_F32(float *pDst, float *pA, float *pB, int32_t M, int32_t N, int32_t P)
{
    int32_t status;

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

/*!
 * brief Calculates the matrix product of two complex 32-bit floating point matrices.
 *
 * details Computes C = A × B, where:
 * - A is an M × N complex float32 matrix,
 * - B is an N × P complex float32 matrix,
 * - C is the resulting M × P complex float32 matrix.
 *
 * All matrices are assumed to be in row-major format.
 *
 * param [out] pDst Pointer to the output matrix C (size M × P).
 * param [in]  pA   Pointer to the input matrix A (size M × N).
 * param [in]  pB   Pointer to the input matrix B (size N × P).
 * param [in]  M    Number of rows of matrix A.
 * param [in]  N    Number of columns in matrix A (and rows in matrix B).
 * param [in]  P    Number of columns of matrix B.
 *
 * return Command execution status.
 */
int32_t CE_MatrixMul_CF32(float *pDst, float *pA, float *pB, int32_t M, int32_t N, int32_t P)
{
    int32_t status;

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

/*!
 * brief Calculates the inverse or Cholesky inverse of a complex Hermitian matrix
 * (in float32 precision).
 *
 * details Computes one of the following:
 * - Ainv = inv(A)
 * - Ainv = inv(chol(A))
 *
 * where chol(A) is the lower triangular Cholesky decomposition of matrix A.
 *
 * The input matrix must be in row-major format and can be either:
 * - A full M × M matrix, or
 * - A packed upper triangular matrix (containing only the upper triangle).
 *
 * The output matrix is written in row-major format, and only
 * the lower triangle is stored. The total number of output elements is:
 * - Mc = (M + 1) × M / 2
 *
 * param[out] pAinv            Pointer to the output matrix inverse.
 * Mc elements are written (complex float32).
 * param[in]  pA               Pointer to the input matrix A (complex float32, size M × M).
 * param[in]  pScratch         Pointer to scratch buffer (minimum size Mc × 3 × 8 bytes).
 * param[in]  M                Number of rows/columns in matrix A.
 * param[in]  flag_packedInput Format of input matrix:
 * - 0: full matrix
 * - 1: packed upper triangular matrix
 * param[in]  flag_cholInv Type of inverse to compute:
 * - 0: inv(A)
 * - 1: inv(chol(A))
 *
 * return Command execution status.
 *
 * note The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_MatrixInvHerm_CF32(
    float *pAinv, float *pA, float *pScratch, int32_t M, uint8_t flag_packedInput, uint8_t flag_cholInv)
{
    int32_t status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 3;
    cmdstruct.arg_ptr_array[0]   = (void *)pAinv;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pScratch;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = (int32_t)flag_packedInput;
    cmdstruct.arg_param_array[2] = (int32_t)flag_cholInv;

    status = CE_CmdAdd(kCE_Cmd_MAT_INV_HERM_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

/*!
 * brief Calculates the Eigenvalue Decomposition (EVD) of a complex Hermitian matrix
 * (float32 precision).
 *
 * details Performs EVD on an M×M complex Hermitian matrix A:
 * - [U, T] = eig(A)
 *
 * The input matrix must be in column-major format and can be either:
 * - A full M × M matrix, or
 * - A packed upper triangular matrix.
 *
 * The decomposition uses an iterative QR algorithm to compute:
 * - U: matrix of eigenvectors (M × M, column-major)
 * - T: vector of eigenvalues (M × 1)
 *
 * Maximum supported matrix size: M ≤ 40.
 *
 * param [out] pLambdaOut Pointer to the output vector of eigenvalues
 * (size M × 1, complex float32).
 * param [out] pUout      Pointer to the output matrix of eigenvectors
 * (size M × M, column-major, complex float32).
 * param [in]  pUin       Pointer to the input matrix A
 * (size M × M, column-major, complex float32).
 * param [in]  pScratch   Pointer to scratch buffer
 * (minimum size: (M × M × 4 + 360) × 4 bytes).
 * param [in]  M          Number of rows/columns in matrix A.
 * param [in]  tol        Tolerance value for QR convergence.
 * Smaller values yield better accuracy but require more iterations.
 * param [in]  max_iter   Maximum number of QR iterations.
 * If exceeded, the function terminates regardless of convergence.
 * param [in] flag_packedInput Format of input matrix:
 * - 0: full matrix
 * - 1: packed upper triangular part only
 *
 * return Command execution status.
 * The number of QR iterations is returned in status[3] register.
 *
 * note If input and output buffers overlap,
 * the output U matrix will overwrite the input matrix A.
 */
int32_t CE_MatrixEvdHerm_CF32(float *pLambdaOut,
                              float *pUout,
                              float *pUin,
                              float *pScratch,
                              int32_t M,
                              float tol,
                              int32_t max_iter,
                              uint8_t flag_packedInput)
{
    int32_t status;
    int32_t *ptemp = (int32_t *)&tol;

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
    cmdstruct.arg_param_array[3] = (int32_t)flag_packedInput;

    status = CE_CmdAdd(kCE_Cmd_MAT_EVD_HERM_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}

/*!
 * brief Calculates the Cholesky Decomposition of a complex Hermitian matrix
 * (float32 precision).
 *
 * details Calculates L = chol(A), where A is a complex Hermitian M × M matrix and
 * L is a lower triangular matrix such that A = L × L ^ H.
 *
 * The input matrix must be in row-major format and can be either:
 * - A full M × M matrix, or
 * - A packed format containing only the upper triangular elements.
 *
 * The output matrix is also in row-major format,
 * and only the lower triangular part is written.
 * The total number of output elements is Mc, where:
 * - Mc = (M + 1) × M / 2
 *
 * param [out] pL               Pointer to the output lower triangular matrix L.
 * Only Mc elements are written (complex-valued float32 data in row-major format).
 * param [in]  pA               Pointer to the input matrix A (full or packed format).
 * Must be complex-valued float32 data in row-major format.
 * param [in]  pScratch         Pointer to a scratch buffer (at least Mc × 8 bytes).
 * param [in]  M                Number of rows/columns of matrix A.
 * param [in]  flag_packedInput Format flag for input matrix:
 * - 0: full matrix
 * - 1: packed upper triangular matrix
 *
 * return Command execution status.
 *
 * note The input, output and scratch buffers must be separately allocated and non-overlapping.
 */
int32_t CE_MatrixChol_CF32(float *pL, float *pA, float *pScratch, int32_t M, uint8_t flag_packedInput)
{
    int32_t status;

    ce_cmdstruct_t cmdstruct;
    cmdstruct.n_ptr_args         = 3;
    cmdstruct.n_param_args       = 2;
    cmdstruct.arg_ptr_array[0]   = (void *)pL;
    cmdstruct.arg_ptr_array[1]   = (void *)pA;
    cmdstruct.arg_ptr_array[2]   = (void *)pScratch;
    cmdstruct.arg_param_array[0] = M;
    cmdstruct.arg_param_array[1] = (int32_t)flag_packedInput;

    status = CE_CmdAdd(kCE_Cmd_MAT_CHOL_CF32, &cmdstruct);

    if (status == 0)
    {
        status = CE_CmdLaunch(0);
    }

    return status;
}