/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

/** @file  mcuxClCipherModes_Els_Aes.c
 *  @brief implementation of the Skeleton functions of the mcuxClCipher component */

#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <internal/mcuxClPadding_Internal.h>
#include <mcuxClAes.h>
#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>


/**
 * @brief Function performs cipher init operation and OutLength buffer validation
 *
 * @param[in/out]   pCtx
 * @param[in]       pKey
 * @param[in]       pMode
 * @param[in]       pIv
 * @param[in]       ivLength
 * @param[in]       inLength
 * @param[in]       pOutLength   pointer to output length buffer, shall not be modified only validated
 * @param[in]       steps        bitmask with one bit reserved for init/update/finalize steps
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_InitAndValidate)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_InitAndValidate(
    mcuxClCipherModes_Context_Aes_Els_t * pCtx,
    mcuxClKey_Handle_t pKey,
    mcuxClCipher_Mode_t pMode,
    mcuxCl_InputBuffer_t pIv,
    uint32_t ivLength,
    uint32_t inLength,
    uint32_t * const pOutLength,
    uint32_t steps)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_InitAndValidate);
    if (MCUXCLCIPHER_OPTION_INIT == (steps & MCUXCLCIPHER_OPTION_INIT)) /* Init or oneshot */
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pCtx is of type mcuxClCipherModes_Context_Aes_Els_t *")
        MCUX_CSSL_FP_FUNCTION_CALL(initResult, mcuxClCipherModes_SkeletonAes_Init(pCtx, pKey, pMode, pIv, ivLength));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
        if(MCUXCLCIPHER_STATUS_OK != initResult)
        {
           MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_InitAndValidate, initResult, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes_Init));
        }
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pCtx is of type mcuxClCipherModes_Context_Aes_Els_t *")
    if((MCUXCLCIPHER_OPTION_INIT != steps) && ((*pOutLength > (UINT32_MAX - inLength)) || ((*pOutLength + inLength) > (UINT32_MAX - pCtx->common.blockBufferUsed))))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_InitAndValidate, MCUXCLCIPHER_STATUS_INVALID_INPUT);
    }
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_InitAndValidate, MCUXCLCIPHER_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL(MCUXCLCIPHER_OPTION_INIT == (steps & MCUXCLCIPHER_OPTION_INIT), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes_Init)));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_SkeletonAes)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_SkeletonAes(
    mcuxClSession_Handle_t session,
    mcuxClCipher_Context_t * const pContext,
    mcuxClKey_Handle_t pKey,
    mcuxClCipher_Mode_t pMode,
    mcuxCl_InputBuffer_t pIv,
    uint32_t ivLength,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength,
    uint32_t steps //!< steps is a bitmask with one bit reserved for each of the steps below
    )
{
    /* [Design]
        ATTN: pOutLength will be incremented by the number of bytes of encrypted data that have been
              written to the @p pOut buffer. Except otherwise mentioned processing steps output data
              to pOut and update pOutLength

        - Oneshot Initialization (steps == oneshot)
            - check if inLength is a multiple of granularity (in the mode), if not exit with ERROR

        - Init processing (steps == oneshot / init)
            - if mode requires IV: copy pIv to ivState in context and check IV length == blocklength otherwise error
            - set blockBufferUsed in context to zero

        - Update processing (steps == oneshot / update)
            - if blockBufferUsed != 0 (this will never be the case for oneshot)
                - set elsOptions
                - add the new data from the input to blockBuffer and process if possible
                - adapt blockBufferUsed
            - set elsOptions
            - process remaining complete blocks from the input
            - add remaining data to blockBuffer, adapt blockBufferUsed (this can happen for oneshot)

        - Finish processing (steps == oneshot / finish)
            - dataToCopy = blockBufferUsed rounded up to the next multiple of granularity from the context
            - Check if the padding function does not point to NULL, if it does exit with ERROR
            - Apply the padding function on blockBuffer from context
            - If the output of the padding function is longer than zero, set elsOptions and process the blockBuffer,
              store the result in blockBuffer
            - copy dataToCopy bytes from blockBuffer to the output and update pOutLength accordingly
            - clean up context

    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_SkeletonAes);
    /* Keep track of where we are in output */
    uint8_t * pOutput = (uint8_t *) pOut;

    /* Correct Context type for Aes ELS Skeleton */
    mcuxClCipherModes_Context_Aes_Els_t * pCtx = NULL;
    uint32_t cpuWaSizeInWords = 0;

    if(NULL == session)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_SkeletonAes, MCUXCLCIPHER_STATUS_ERROR);
    }

    if(MCUXCLCIPHER_OPTION_ONESHOT == steps)
    {
        /* Create context for Oneshot, needed by ELS */
        cpuWaSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClCipherModes_Context_Aes_Els_t));
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        pCtx = (mcuxClCipherModes_Context_Aes_Els_t *) mcuxClSession_allocateWords_cpuWa(session, cpuWaSizeInWords);
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
        if(NULL == pCtx)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_SkeletonAes, MCUXCLCIPHER_STATUS_FAILURE);
        }

        /* inLength needs to be a multiple of the granularity, if this is not the case, return an error.
           The granularity is set in the mode as such:
           - for CTR it is set to 1
           - for paddingNone it is set to blocksize
           - for other padding modes it is set to 1
        */
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        if (0u != (inLength % ((mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t *)pMode->pAlgorithm)->granularity))
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_SkeletonAes, MCUXCLCIPHER_STATUS_ERROR);
        }
    }
    else
    {
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        pCtx = (mcuxClCipherModes_Context_Aes_Els_t *) pContext;
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
    }

    MCUX_CSSL_FP_FUNCTION_CALL(initResult, mcuxClCipherModes_InitAndValidate(
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
                        pCtx,
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
                        pKey,
                        pMode,
                        pIv,
                        ivLength,
                        inLength,
                        pOutLength,
                        steps));
    if(MCUXCLCIPHER_STATUS_OK != initResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_SkeletonAes, initResult, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_InitAndValidate));
    }

    if (MCUXCLCIPHER_OPTION_PROCESS == (steps & MCUXCLCIPHER_OPTION_PROCESS)) /* process or oneshot */
    {
        uint32_t outLen = 0u;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pCtx is of type mcuxClCipherModes_Context_Aes_Els_t *")
        MCUX_CSSL_FP_FUNCTION_CALL(processResult, mcuxClCipherModes_SkeletonAes_Process(session, pCtx, pIn, inLength, pOut, &outLen));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
        if (MCUXCLCIPHER_STATUS_OK != processResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_SkeletonAes, processResult,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes_Process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_InitAndValidate));
        }
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("False Positive, *pOutLength will not overflow As it was checked above")
        *pOutLength += outLen;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        pOutput += outLen;
    }

    if (MCUXCLCIPHER_OPTION_FINISH == (steps & MCUXCLCIPHER_OPTION_FINISH)) /* finish or oneshot */
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pCtx is of type mcuxClCipherModes_Context_Aes_Els_t *")
        MCUX_CSSL_FP_FUNCTION_CALL(finishResult, mcuxClCipherModes_SkeletonAes_Finish(session, pCtx, (mcuxCl_Buffer_t)pOutput, pOutLength));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
        if(MCUXCLCIPHER_STATUS_OK != finishResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_SkeletonAes, finishResult,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_InitAndValidate),
                MCUX_CSSL_FP_CONDITIONAL((MCUXCLCIPHER_OPTION_PROCESS == (steps & MCUXCLCIPHER_OPTION_PROCESS)),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes_Process)),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes_Finish));
        }
    }

    if(MCUXCLCIPHER_OPTION_ONESHOT == steps)
    {
        /* Free context in Session */
        mcuxClSession_freeWords_cpuWa(session, cpuWaSizeInWords);
    }

    /* Exit and balance the flow protection. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_SkeletonAes, MCUXCLCIPHER_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_InitAndValidate),
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLCIPHER_OPTION_PROCESS == (steps & MCUXCLCIPHER_OPTION_PROCESS)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes_Process)),
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLCIPHER_OPTION_FINISH == (steps & MCUXCLCIPHER_OPTION_FINISH)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_SkeletonAes_Finish)));
}
