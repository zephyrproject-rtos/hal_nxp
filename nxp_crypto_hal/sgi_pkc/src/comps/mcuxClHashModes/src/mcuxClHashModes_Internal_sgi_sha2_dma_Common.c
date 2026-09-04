/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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

#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClAes.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Utils.h>
#include <internal/mcuxClDma_Resource.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClHashModes_Internal_Resource_Common.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

/**********************************************************
 * Helper functions
 **********************************************************/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_Sha2End)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_Sha2End (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Algo_t algorithm,
                        uint32_t expectedSgiCounter,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize,
                        uint32_t releaseOption
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_Sha2End);

    /* Wait until SGI has finished and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Check whether number of processed blocks is correct */
    expectedSgiCounter = expectedSgiCounter % (MCUXCLHASHMODES_INTERNAL_SGI_COUNT_MAX_VALUE + 1u);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, expectedSgiCounter));

    /* Copy hash digest to output buffer */
    /* pOut is NULL only in DMA blocking modes which is not supported on MCU */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storeHashResult(session, pOut, algorithm->hashSize));
    *pOutSize = algorithm->hashSize;

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRelease(session, releaseOption));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_Sha2End,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_checkHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storeHashResult),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRelease)
    );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_finish_Sha2_DmaBlocking, mcuxClHash_AlgoSkeleton_Finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_finish_Sha2_DmaBlocking (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_finish_Sha2_DmaBlocking);
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(context->algo->blockSize, MCUXCLHASH_BLOCK_SIZE_MIN, MCUXCLHASH_BLOCK_SIZE_MAX, MCUXCLHASH_STATUS_INVALID_PARAMS);
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(context->algo->stateSize, MCUXCLHASH_STATE_SIZE_MIN, MCUXCLHASH_STATE_SIZE_MAX, MCUXCLHASH_STATUS_INVALID_PARAMS);

    /* context is deliberately not recorded for clearContext,
     * because mcuxClHashModes_Sgi_finish_Sha2_DmaBlocking is supposed to expunge context.
     */
    MCUX_CSSL_DI_RECORD(clearContext, sizeof(mcuxClHash_ContextDescriptor_t) + context->algo->blockSize + context->algo->stateSize);

    uint32_t *pUnprocessed = mcuxClHash_getUnprocessedPtr(context);
    uint8_t *pUnprocessedBytes = (uint8_t *)pUnprocessed;
    uint32_t *pState = mcuxClHash_getStatePtr(context);

    const size_t algoBlockSize = context->algo->blockSize;
    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) context->algo->pAlgorithmDetails;

    /* error handled inside HwRequest */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRequest(session, NULL, 0U, MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_OUTPUT));

    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, pOut);
    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, algorithm->hashSize);

    /* Don't check the return value since it always return OK */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));

    MCUX_CSSL_FP_FUNCTION_CALL(int, processedAlreadyOneBlock, mcuxClHash_processedLength_cmp(context->processedLength, algoBlockSize));

    MCUX_CSSL_FP_BRANCH_DECL(initStateWithIvBranch);
    if (0 > processedAlreadyOneBlock)
    {
        /* Configure respective SHA-2 in auto mode using standard IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(algorithmDetails->sgiUtilsInitHash(session, NULL, MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV));
        MCUX_CSSL_FP_BRANCH_POSITIVE(initStateWithIvBranch, algorithmDetails->protectionToken_sgiUtilsInitHash);
    }
    else
    {
        /* Configure respective SHA-2 in auto mode using pState as IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(algorithmDetails->sgiUtilsInitHash(session, pState, MCUXCLSGI_UTILS_AUTO_MODE_LOAD_IV));
        MCUX_CSSL_FP_BRANCH_NEGATIVE(initStateWithIvBranch, algorithmDetails->protectionToken_sgiUtilsInitHash);
    }

    /* Enable counter, to count number of blocks processed by SGI in this call*/
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_enableHashCounter(0u));

    /* No further input to be added, processedLength can be updated now. Will be used for final length value attached inside padding */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHash_processedLength_add(context->processedLength, (uint64_t)context->unprocessedLength));

    /* Verify that the processed length will not exceed the algorithm's maximum allowed length. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("algorithm->counterSize decreased by 1 is greater than ZERO regarding to the Macro definition")
    uint8_t counterHighestByte = ((uint8_t *) context->processedLength)[algorithm->counterSize - 1u];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    if(0u != (counterHighestByte & algorithm->processedLengthCheckMask))
    {
        MCUXCLSESSION_ERROR(session, MCUXCLHASH_STATUS_FULL);
    }

    /* Check whether context->unprocessedLength would wrap */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("the result of context->unprocessedLength is checked to avoid wrapping ")
    if(0u == context->unprocessedLength + 1u)
    {
        MCUXCLSESSION_FAULT(session, MCUXCLHASH_STATUS_FAULT_ATTACK);
    }

    pUnprocessedBytes[context->unprocessedLength++] = 0x80u; //set first bit of padding
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    uint32_t remainingBlockLength = algoBlockSize - (context->unprocessedLength);

    /* Wait until SGI is ready to take input and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Start SGI SHA2 processing */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t counterLen = context->algo->counterSize);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t remainingBlockLen = remainingBlockLength);
    if(context->algo->counterSize > remainingBlockLength) // need room for 64 bit counter
    {
        /* Set remaining bytes in accumulation buffer to zero */
        /* Record input data for mcuxClMemory_set_int() */
        MCUX_CSSL_DI_RECORD(setUnprocessed1, pUnprocessedBytes + context->unprocessedLength);
        MCUX_CSSL_DI_RECORD(setUnprocessed1, remainingBlockLength);

        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, pUnprocessed);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, algorithm->blockSize);

        MCUXCLMEMORY_SET_INT(pUnprocessedBytes + context->unprocessedLength, 0x00u, remainingBlockLength);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(pUnprocessedBytes, algorithm->blockSize));
        remainingBlockLength = algoBlockSize;
        context->unprocessedLength = 0u;
    }

    /* Set remaining bytes in accumulation buffer to zero */
    /* Record input data for mcuxClMemory_set_int() */
    MCUX_CSSL_DI_RECORD(setUnprocessed2, pUnprocessedBytes + context->unprocessedLength);
    MCUX_CSSL_DI_RECORD(setUnprocessed2, remainingBlockLength);

    /* Record input data for mcuxClSgi_Utils_loadFifo() */
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, pUnprocessed);
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, algorithm->blockSize);

    MCUXCLMEMORY_SET_INT(pUnprocessedBytes + context->unprocessedLength, 0x00u, remainingBlockLength);

    /* Perform padding by adding data counter - length is added from end of the array; byte-length is converted to bit-length */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHash_processedLength_toBits(context->processedLength));

    MCUX_CSSL_FP_LOOP_DECL(loopPadding);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t algoCounterSize = algorithm->counterSize);
    for(uint32_t i = 0u; i < algorithm->counterSize; ++i)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("blockSize is always large enough so that the index computation does not wrap. ")
        pUnprocessedBytes[algorithm->blockSize - i - 1u] = ((uint8_t*)context->processedLength)[i];
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_FP_LOOP_ITERATION(loopPadding);
    }

    /* Load input data to SHA FIFO */
    uint32_t expectedSgiCounter = ((remainingBlockLength == algoBlockSize) ? 2u : 1u);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(pUnprocessedBytes, algorithm->blockSize));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

    /* Wait until SGI is ready to take input and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Check whether number of processed blocks is correct */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, expectedSgiCounter));

    /* Copy hash digest to output buffer */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storeHashResult(session, pOut, context->algo->hashSize));

    *pOutSize = context->algo->hashSize;

    /* Clear context */
    MCUXCLMEMORY_CLEAR_INT((uint8_t*) context, sizeof(mcuxClHash_ContextDescriptor_t) + context->algo->blockSize + context->algo->stateSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

    /* Release HW and exit */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRelease(session, MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_OUTPUT));

    /* context already expunged by clearContext. */
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pOut);
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pOutSize);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_finish_Sha2_DmaBlocking,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(initStateWithIvBranch, (0 > processedAlreadyOneBlock)),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(initStateWithIvBranch, (0 <= processedAlreadyOneBlock)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_add),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_CONDITIONAL((counterLen > remainingBlockLen),
            MCUXCLMEMORY_SET_INT_FP_EXPECT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
        ),
        MCUXCLMEMORY_SET_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_toBits),
        MCUX_CSSL_FP_LOOP_ITERATIONS(loopPadding, algoCounterSize),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_checkHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storeHashResult),
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRelease)
    );
}

