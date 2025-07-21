/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CE_MATRIX_H
#define FSL_CE_MATRIX_H

#include <stdint.h>

/*!
 * @ingroup ce
 * @defgroup ce_matrix CE Matrix Functions
 * @brief Functional API definitions for CE Matrix functions.
 * @{
 */

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
 * @brief Adds two MxN matrices with data in specified format
 *
 * Adds two MxN matrices; matrices can be in either of row or columns major
 * formats.
 * Data precision and format is as defined by the argument type
 *
 * @param pDst Pointer to buffer for output matrix
 * @param pA Pointer to buffer for input matrix A
 * @param pB Pointer to buffer for input matrix B
 * @param M  Number of rows for each input matrix
 * @param N  Number of columns for each input matrix
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixAdd_Q15(int16_t *pDst, int16_t *pA, int16_t *pB, int M, int N);

/*!
 * @copydoc CE_MatrixAdd_Q15
 */
int CE_MatrixAdd_Q31(int32_t *pDst, int32_t *pA, int32_t *pB, int M, int N);

/*!
 * @copydoc CE_MatrixAdd_Q15
 */
int CE_MatrixAdd_F32(float *pDst, float *pA, float *pB, int M, int N);

/*!
 * @brief Element wise multiply between two MxN matrices
 *
 * Elementwise multiplies two MxN matrices; matrices can be in either of row or
 * columns major formats.
 *
 * Data precision and format is as defined by the argument type
 *
 * @param pDst Pointer to buffer for output matrix
 * @param pA   Pointer to buffer for input matrix A
 * @param pB   Pointer to buffer for input matrix B
 * @param M    Number of rows for each input matrix
 * @param N    Number of columns for each input matrix
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixElemMul_F32(float *pDst, float *pA, float *pB, int M, int N);

/*!
 * @brief Matrix multiply between two MxN matrices
 *
 * Matrix multiply C[MxP] = A[MxN] x B[NxP] matrices with data in specified
 * format.
 * Multiply between MxN and NxP matrices; matrices must be in row major format
 *
 * @param pDst Pointer to buffer for output matrix [MxP]
 * @param pA   Pointer to buffer for input matrix A [MxN]
 * @param pB   Pointer to buffer for input matrix B [NxP]
 * @param M    Number of rows for input matrix A
 * @param N    Number of columns for input matrix A, or, Number of rows for input matrix B
 * @param P    Number of columns for input matrix B
 *
 * Data precision and format is as defined by the argument type
 * @note Limits on max value of N: For F32: N < 128; For CF32: N < 64
 */
int CE_MatrixMul_F32(float *pDst, float *pA, float *pB, int M, int N, int P);

/*!
 * @copydoc CE_MatrixMul_F32
 */
int CE_MatrixMul_CF32(float *pDst, float *pA, float *pB, int M, int N, int P);

/*
 * @brief Matrix Inversion
 *
 * Calculates inv(A) where A is a MxM real matrix
 *
 * @param pAinv Pointer to buffer for output inverse matrix
 * @param pA    Pointer to buffer for input matrix A
 * @param M     Number of rows or columns of A
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixInv_F32(float *pAinv, float *pA, int M);

/*
 * @brief Matrix Inversion
 *
 * Calculates inv(A) where A is a MxM symmetric real matrix
 *
 * @param pAinv Pointer to buffer for output inverse matrix
 * @param pA    Pointer to buffer for input matrix A
 * @param M     Number of rows or columns of A
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixInvSymm_F32(float *pAinv, float *pA, int M);

/*
 * @brief Matrix Inversion
 *
 * Calculates inv(A) where A is a MxM complex matrix
 *
 * @param pAinv Pointer to buffer for output inverse matrix
 * @param pA    Pointer to buffer for input matrix A
 * @param M     Number of rows or columns of A
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixInv_CF32(float *pAinv, float *pA, int M);

/*!
 * @brief Matrix Inversion
 *
 * Based on an user specified flag, calculates either
 *   \li Ainv = inv(A), or,
 *   \li Linv = inv(chol(A)),
 *
 * where chol() is the lower triangular Cholesky Decomposition of A.
 * A is a MxM complex Hermitian matrix.
 * A is expected to be in row major format and can either be packed (only
 * upper traingular elements) or full
 *
 * @param[out] pAinv Pointer to buffer for output inverse matrix.
 * Only the upper triangular elements of the output matrix are written out. The
 * output is written in row major order. Output size is Mc*8 bytes.
 * Mc = *((1+M)*M)/2.
 * @param[in] pA Pointer to buffer for input matrix A. If flag_packedInput=0,
 * MxM matrix expected in row major format. If flag_packedInput=1, Only
 * upper triangular part of A is expected in row major format (Mc CF32 elements).
 * @param[in] pScratch Scratch memory of size (Mc*3)*8 bytes.
 * @param M   Number of rows or columns of A
 * @param flag_packedInput Flag indicating input matrix format.
 *   - 0: full matrix
 *   - 1: upper triangular part only
 * @param flag_cholInv Flag indicating inverse type.
 *   - 0: Out = inv(A)
 *   - 1: Out = inv(chol(A))
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixInvHerm_CF32(
    float *pAinv, float *pA, float *pScratch, int M, uint8_t flag_packedInput, uint8_t flag_cholInv);

/*!
 * @brief Eigen Value Decompositions
 *
 * Calculates Eigen Value Decompositions of a MxM matrix.
 * Calculates [U, T] = evd(A) where A is a MxM complex Hermitian matrix, U is
 * the output matrix of eigen vectors, and T is the diagonal matrix of eigen
 * values.
 *
 * @param pLambdaOut Pointer to buffer for output Eigen Vectors (MxM)
 * @param pUout      Pointer to buffer with output Eigen Values (Mx1)
 * @param pUin       Pointer to buffer for input matrix A
 * @param M          Number of rows or columns of A
 * @param pScratch   Scratch memory, the minimum scratch size required is (40 x 40 x 4 + 360) x 4 bytes.
 * @param tol        Tolerance specifying exit condition for the iterative computation
 * @param max_iter   Upper bound on number of iterations for convergence of each Eigen value
 * @param flag_packedInput Flag indicating input matrix format.
 *   - 0: full matrix
 *   - 1: upper triangular part only
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixEvdHerm_CF32(float *pLambdaOut,
                          float *pUout,
                          float *pUin,
                          float *pScratch,
                          int M,
                          float tol,
                          int max_iter,
                          uint8_t flag_packedInput);

/*!
 * @brief Cholesky Decomposition
 *
 * Calculates L = chol(A) where A is a MxM complex Hermitian matrix
 * This Cholesky Decomposition returns a lower triangular matrix L,
 * such that A = L*L^H, A and L are expected to be in column major format
 *
 * @param pL Pointer to buffer for output triangular matrix L
 * @param pA Pointer to buffer for input matrix A
 * @param M  Number of rows or columns of A
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_MatrixChol_CF32(float *pL, float *pA, int M);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_MATRIX_H*/
