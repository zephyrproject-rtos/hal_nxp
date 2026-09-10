/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

/**
 * @file  mcuxClMath_SecModMultOdd.c
 * @brief mcuxClMath: secure modular multiplication
 */


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClBuffer.h>
#include <mcuxClRandom.h>
#include <mcuxClSession.h>
#include <mcuxClMath.h>
#include <mcuxClMemory.h>


#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMath_Internal_SecModMult.h>
#include <internal/mcuxClMath_SecModMult_FUP.h>
#include <internal/mcuxClMath_Internal_Functions.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClPrng_Internal.h>


/**
 * [DESIGN]
 * Public secure modular multiplication function.
 *
 * CAUTION: N should be odd.
 *
 * Data Integrity: Expunge(pX, lenX, pY, lenY, pN, lenN)
 *
 * @param[in] pSession  handle for the current CL session.
 * @param[in] pX  pointer to X
 * @param[in] lenX  length of X in bytes
 * @param[in] pY  pointer to Y
 * @param[in] lenY  length of Y in bytes
 * @param[in] pN  pointer to N
 * @param[in] lenN  length of N in bytes
 * @param[out] pR  pointer to R
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #MCUXCLMATH_STATUS_OK                 function executed successfully
 * @retval #MCUXCLMATH_STATUS_ERROR              error occurred during operation
 * @retval #MCUXCLMATH_STATUS_FAULT_ATTACK       fault attack occurred during operation
 * @retval #MCUXCLMATH_STATUS_INVALID_PARAMS     function called with invalid parameters
 * @retval #MCUXCLRESOURCE_STATUS_UNAVAILABLE    PKC Resource request failed
 * @retval #MCUXCLRESOURCE_STATUS_ERROR          Error occurred during PKC Resource operation
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_SecModMultOdd)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMath_Status_t) mcuxClMath_SecModMultOdd(
    mcuxClSession_Handle_t pSession,
    mcuxCl_InputBuffer_t pX,
    uint32_t lenX,
    mcuxCl_InputBuffer_t pY,
    uint32_t lenY,
    mcuxCl_InputBuffer_t pN,
    uint32_t lenN,
    mcuxCl_Buffer_t pR
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_SecModMultOdd);

    const uint32_t byteLenMax = ((lenX > lenN) ? lenX : lenN);
    const uint32_t operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenMax);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The result does not wrap. The bufferSize can't be larger than UINT32_MAX.")
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    /* Setup CPU workarea and PKC buffer. */
    const uint32_t byteLenOperandsTable = (sizeof(uint16_t)) * (uint32_t) MCUXCLMATH_MODMULT_NO_OF_BUFFERS;
    const uint32_t alignedByteLenCpuWa = MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(byteLenOperandsTable);
    const uint32_t wordNumCpuWa = alignedByteLenCpuWa / (sizeof(uint32_t));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pCpuWorkarea are 16-bit aligned as Operands Table ")
    uint16_t *pCpuWorkarea = (uint16_t *) mcuxClSession_allocateWords_cpuWa(pSession, wordNumCpuWa);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    /* Initialize PKC */
    uint32_t pkcStateBackupSize = MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClPkc_State_t)) / sizeof(uint32_t);
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    mcuxClPkc_State_t * pkcStateBackup = (mcuxClPkc_State_t *) mcuxClSession_allocateWords_cpuWa(pSession, pkcStateBackupSize);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
    if (NULL == pkcStateBackup)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_sign, MCUXCLMATH_STATUS_FAULT_ATTACK);
    }

    MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, pkcStateBackup, mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The result does not wrap. The bufferSize*5 can't be larger than UINT32_MAX.")
    const uint32_t wordNumPkcWa = (bufferSize * (uint32_t) MCUXCLMATH_MODMULT_NO_OF_BUFFERS) / (sizeof(uint32_t));  /* PKC bufferSize is a multiple of CPU word size. */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordNumPkcWa);
    if ((NULL == pCpuWorkarea) || (NULL == pPkcWorkarea))
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }

    MCUXCLPKC_WAITFORREADY();
    /* Generate and randomize PKC UPTRT */
    MCUXCLPKC_FP_GENERATEUPTRT(pCpuWorkarea,
                              pPkcWorkarea,
                              (uint16_t) bufferSize,
                              (uint8_t)MCUXCLMATH_MODMULT_NO_OF_BUFFERS);
    MCUXCLPKC_SETUPTRT(pCpuWorkarea);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_RandomizeUPTRT(pSession, pCpuWorkarea, (uint8_t)MCUXCLMATH_MODMULT_NO_OF_BUFFERS));

    uint16_t *pOperands = pCpuWorkarea;
    uint16_t offsetX = pOperands[MCUXCLMATH_MODMULT_X];
    uint8_t *pBufferX = MCUXCLPKC_OFFSET2PTR(offsetX);
    uint16_t offsetY = pOperands[MCUXCLMATH_MODMULT_Y];
    uint8_t *pBufferY = MCUXCLPKC_OFFSET2PTR(offsetY);
    /* clean up buffer for X and Y before importing */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW(" bufferSize is never less than lenX or lenY ")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_clear((uint8_t *) (pBufferX + lenX), bufferSize - lenX, bufferSize));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_clear((uint8_t *) (pBufferY + lenY), bufferSize - lenY, bufferSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    /* Set PS1 MCLEN and LEN. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);
    /* Import X and Y with secure buffer read with reverse endianness */
    MCUXCLPKC_FP_SECUREIMPORTBIGENDIANTOPKC(statusBufferImportX, pSession, MCUXCLMATH_MODMULT_X, MCUXCLMATH_MODMULT_T1, pX, lenX);
    if(MCUXCLPKC_STATUS_OK != statusBufferImportX)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }

    MCUXCLPKC_FP_SECUREIMPORTBIGENDIANTOPKC(statusBufferImportY, pSession, MCUXCLMATH_MODMULT_Y, MCUXCLMATH_MODMULT_T1, pY, lenY);
    if(MCUXCLPKC_STATUS_OK != statusBufferImportY)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }

    uint16_t offsetN = pOperands[MCUXCLMATH_MODMULT_N];
    uint8_t *pBufferN = MCUXCLPKC_OFFSET2PTR(offsetN);
    /* reserve 1 MCUXCLPKC_WORDSIZE for NDash result, size of BufferN reduced to operandSize */
    pBufferN += MCUXCLPKC_WORDSIZE;
    offsetN = MCUXCLPKC_PTR2OFFSET(pBufferN);
    pOperands[MCUXCLMATH_MODMULT_N] = offsetN;
    /* clean up buffer for N before importing */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW(" operandSize is never less than lenN ")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_clear((uint8_t *) (pBufferN + lenN), operandSize - lenN, bufferSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    /* import N with normal buffer read with reverse endianness */
    MCUXCLPKC_FP_SECUREIMPORTBIGENDIANTOPKC(statusBufferImportN, pSession, MCUXCLMATH_MODMULT_N, MCUXCLMATH_MODMULT_T1, pN, lenN);
    if(MCUXCLPKC_STATUS_OK != statusBufferImportN)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }

    MCUXCLPKC_WAITFORFINISH();

    /* Check that the modulus is odd, otherwise return INVALID_PARAMS */
    uint8_t lsbN = pBufferN[0] & 0x01U;
    if (lsbN != 1u)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_INVALID_PARAMS);
    }

    /* Compute NDash */
    MCUXCLMATH_FP_NDASH(MCUXCLMATH_MODMULT_N, MCUXCLMATH_MODMULT_T1);
    MCUXCLPKC_WAITFORFINISH();
    /* R = X*Y*Q^(-1) mod N */
    /* ASSERT: operandSize is nonzero, and less than MCUXCLPKC_RAM_SIZE/MCUXCLMATH_MODMULT_NO_OF_BUFFERS. */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(operandSize, 1u, (MCUXCLPKC_RAM_SIZE / MCUXCLMATH_MODMULT_NO_OF_BUFFERS), MCUXCLMATH_STATUS_ERROR)
    MCUX_CSSL_FP_FUNCTION_CALL(statusSecModMult1, MCUXCLMATH_SECMODMULT(pSession, MCUXCLMATH_MODMULT_R, MCUXCLMATH_MODMULT_N, MCUXCLMATH_MODMULT_Y, MCUXCLMATH_MODMULT_X, MCUXCLMATH_MODMULT_X, MCUXCLMATH_MODMULT_T1, (uint16_t)operandSize));
    if (MCUXCLMATH_STATUS_OK != statusSecModMult1)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }

    /* Y=Q^2, T1 * X used as temp */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);
    MCUXCLMATH_FP_SHIFTMODULUS(MCUXCLMATH_MODMULT_T1, MCUXCLMATH_MODMULT_N);
    MCUXCLMATH_FP_QSQUARED(MCUXCLMATH_MODMULT_Y, MCUXCLMATH_MODMULT_T1, MCUXCLMATH_MODMULT_N, MCUXCLMATH_MODMULT_X);
    MCUXCLPKC_WAITFORFINISH();

    /* multiply R with Q^2, input T2 re-uses the buffer R, result is written to the buffer X */
    /* ASSERT: operandSize is nonzero, and less than MCUXCLPKC_RAM_SIZE/MCUXCLMATH_MODMULT_NO_OF_BUFFERS. */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(operandSize, 1u, (MCUXCLPKC_RAM_SIZE / MCUXCLMATH_MODMULT_NO_OF_BUFFERS), MCUXCLMATH_STATUS_ERROR)
    MCUX_CSSL_FP_FUNCTION_CALL(statusSecModMult2, MCUXCLMATH_SECMODMULT(pSession, MCUXCLMATH_MODMULT_X, MCUXCLMATH_MODMULT_N, MCUXCLMATH_MODMULT_Y, MCUXCLMATH_MODMULT_R, MCUXCLMATH_MODMULT_R, MCUXCLMATH_MODMULT_T1, (uint16_t)operandSize));
    if (MCUXCLMATH_STATUS_OK != statusSecModMult2)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }
    /* Export the result with secure buffer write with reverse endianness */
    MCUXCLPKC_FP_SECUREEXPORTBIGENDIANFROMPKC(statusBufferExport, pSession, pR, MCUXCLMATH_MODMULT_X, MCUXCLMATH_MODMULT_T1, lenN);
    if(MCUXCLPKC_STATUS_OK != statusBufferExport)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }

    /* clear the data in the PKC buffer (X) that contains the result by overwriting it with random data */
    /* ASSERT: bufferSize is nonzero, and less than MCUXCLPKC_RAM_SIZE/MCUXCLMATH_MODMULT_NO_OF_BUFFERS. */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(bufferSize, 1u, (MCUXCLPKC_RAM_SIZE / MCUXCLMATH_MODMULT_NO_OF_BUFFERS), MCUXCLMATH_STATUS_ERROR)
    MCUX_CSSL_FP_FUNCTION_CALL(ret_Random_ncGenerate, mcuxClRandom_ncGenerate(pSession, pBufferX, bufferSize));
    if (MCUXCLRANDOM_STATUS_OK != ret_Random_ncGenerate)
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_ERROR);
    }
    else
    {
        mcuxClSession_freeWords_pkcWa(pSession, wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, pkcStateBackup,
            mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, (wordNumCpuWa + pkcStateBackupSize));
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMultOdd, MCUXCLMATH_STATUS_OK,
            MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_GenerateUPTRT),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureImportBigEndianToPkc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureImportBigEndianToPkc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureImportBigEndianToPkc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_SecModMult),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_SecModMult),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureExportBigEndianFromPkc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
}
