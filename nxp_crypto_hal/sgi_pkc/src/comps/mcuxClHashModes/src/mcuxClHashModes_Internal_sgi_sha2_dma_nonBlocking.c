/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

#include <mcuxClToolchain.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClResource_Internal_Types.h>
#include <internal/mcuxClResource_Internal_Functions.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClAes.h>
#include <internal/mcuxClDma_Drv.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Resource.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClHashModes_Internal_Resource_Common.h>
#include <mcuxClCore_Macros.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClHashModes_Internal_sgi_sha2_common.h>

/**********************************************************
 * Helper functions
 **********************************************************/
/**
 * @brief Sha2 nonBlocking interrupt service routine cleanup and exit
 *
 * This routine is intended to be executed as last step of interrupt callback.
 * Session workare reserved memory space is freed, SGI flushed and released,
 * DMA released and user callback triggered
 *
 * @param session Current session handle
 * @param waWordSize Work area size in words to be freed
 * @param userCallbackStatus Return value to be forwared in user callback
 * @param releaseOption Option from MCUXCLHASHMODES_REQ_* define set indicating which
 *        hardware resource shall be released
 *
 * @pre
 *  - session job workarea must point to initialized interrupt context
 * (mcuxClSession_job_setClWorkarea with initialized structure with Internal IsrCtx type)
 *  - required hardware should be requested before routine execution:
 *    - Input Dma
 *    - SGI
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback(
  mcuxClSession_Handle_t session,
  uint32_t waWordSize,
  mcuxClHash_Status_t userCallbackStatus,
  uint32_t releaseOption
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback);
    mcuxClSession_freeWords_cpuWa(session, waWordSize);

    /* flush whole SGI */
    // TODO CLNS-16291: FLUSH_KEY for SGI is not usable anymore with preloaded keys
    // mcuxClSgi_Drv_enableFlush(MCUXCLSGI_DRV_FLUSH_ALL);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRelease(session, releaseOption));

    MCUX_CSSL_FP_FUNCTION_CALL(ucStatus, mcuxClSession_triggerUserCallback(session, userCallbackStatus));
    if(MCUXCLSESSION_STATUS_OK != ucStatus)
    {
        MCUXCLSESSION_ERROR(session, ucStatus);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRelease),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_triggerUserCallback)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_castToSha2OneshotInternalIsrCtx)
static mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t* mcuxClHashModes_castToSha2OneshotInternalIsrCtx(uint32_t* pContext)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t*) pContext;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_castToSha2MultipartInternalIsrCtx)
static mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t* mcuxClHashModes_castToSha2MultipartInternalIsrCtx(uint32_t* pContext)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t*) pContext;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

/**********************************************************
 * *INTERNAL* layer functions
 **********************************************************/

/**
 * @brief Sha2 Oneshot (Init/Update/Finalize) Interrupt Service Routine (ISR).
 *
 * This routine is intended to be executed as an interrupt callback after SGI
 * has finished processing. It will check if the Sha2 operation has finished
 * without any errors, process last block, copy out the result and trigger
 * user callback on exit. In case of one-shot compare, this function will
 * compare the result against the reference before triggering the user callback.
 *
 * @param session Current session handle
 *
 * @pre
 *  - session job workarea must point to initialized interrupt context
 * (mcuxClSession_job_setWa with initialized structure of mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t)
 *  - required hardware must be requested before routine execution:
 *    - Input Dma (input gathering)
 *    - SGI (sha2 calculation)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sha2Sgi_ISR_Oneshot, mcuxClSession_HwInterruptHandler_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sha2Sgi_ISR_Oneshot(mcuxClSession_Handle_t session)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sha2Sgi_ISR_Oneshot);

    mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t *isrCtx = mcuxClHashModes_castToSha2OneshotInternalIsrCtx(mcuxClSession_job_getClWorkarea(session));
    mcuxClSession_Channel_t inChannel = mcuxClSession_getDmaInputChannel(session);
    mcuxCl_InputBuffer_t inputBuf = isrCtx->inputBuf;

    uint32_t workareaSizeToFree = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t));
    mcuxClHash_AlgorithmDescriptor_t *algorithm = isrCtx->algorithm;

    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, isrCtx->pOut);
    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, algorithm->hashSize);

    /* Wait for data copy to finish and check for errors */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inChannel));

    mcuxClDma_Drv_disableChannelDoneInterrupts(inChannel);
    mcuxClDma_Drv_disableErrorInterrupts(inChannel);

    /**************************************************************************************
     * Step 3: Pad the input data and process last block
     **************************************************************************************/
    uint32_t numberOfFullBlocks = isrCtx->numberOfFullBlocks;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Cannot wrap as algorithm->blockSize is limited to MCUXCLHASH_BLOCK_SIZE_MAX")
    uint32_t offset = numberOfFullBlocks * algorithm->blockSize;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    size_t inSize = isrCtx->inSize;

    /* Buffer in CPU WA to store the last block of data in the finalization phase */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Cannot wrap as algorithm->blockSize is limited to MCUXCLHASH_BLOCK_SIZE_MAX")
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, shaBlock, mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize)));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    uint8_t *shaBlockBytes = (uint8_t *)shaBlock;

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Cannot wrap as algorithm->blockSize is limited to MCUXCLHASH_BLOCK_SIZE_MAX")
    workareaSizeToFree += MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("algorithm->blockSize is greater than 1 regarding to macro definition")
    size_t sizeRemainingBlock = inSize & (algorithm->blockSize - 1u);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    /* Balance DI impact of mcuxClBuffer_read. */
    MCUX_CSSL_DI_RECORD(bufferReadBalancing, inputBuf);
    MCUX_CSSL_DI_RECORD(bufferReadBalancing, offset);
    MCUX_CSSL_DI_RECORD(bufferReadBalancing, shaBlock);
    MCUX_CSSL_DI_RECORD(bufferReadBalancing, sizeRemainingBlock);
    /* Copy the data to the buffer in the workspace. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Offset computation does not overflow")
    // TODO CLNS-16738: Investigate whether we want Function call here? Needed to be reverted for FP build.
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(inputBuf, offset, shaBlockBytes, sizeRemainingBlock));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* add first byte of the padding: (remaining) < (block length) so there is space in the buffer */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("sizeRemainingBlock did not wrap, sizeRemainingBlock increased by 1 is less than MAX of uint32_t regarding to the initialization above")
    shaBlockBytes[sizeRemainingBlock] = 0x80u;
    sizeRemainingBlock += 1u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    uint32_t numberOfZeroBytes = algorithm->blockSize - sizeRemainingBlock;

    /* Process partial padded block if needed */
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t numZeroBytes = numberOfZeroBytes);
    if (algorithm->counterSize > numberOfZeroBytes) // need room for 64 bit counter and one additional byte
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("shaBlockBytes + sizeRemainingBlock does not overflow");
        /* Record input data for mcuxClMemory_set_int() */
        MCUX_CSSL_DI_RECORD(setShablock1, &shaBlockBytes[sizeRemainingBlock]);
        MCUX_CSSL_DI_RECORD(setShablock1, numberOfZeroBytes);
        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, shaBlock);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, algorithm->blockSize);

        MCUXCLMEMORY_SET_INT(&shaBlockBytes[sizeRemainingBlock], 0x00u, numberOfZeroBytes);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        /* Load input data to SHA FIFO */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(shaBlockBytes, algorithm->blockSize));
        sizeRemainingBlock = 0u;
        numberOfZeroBytes = algorithm->blockSize;
    }

    /* Perform padding by adding data counter */
    /* Record input data for mcuxClMemory_set_int() */
    MCUX_CSSL_DI_RECORD(setShablock2, &shaBlockBytes[sizeRemainingBlock]);
    MCUX_CSSL_DI_RECORD(setShablock2, numberOfZeroBytes);
    /* Record input data for mcuxClSgi_Utils_loadFifo() */
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, shaBlock);
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, algorithm->blockSize);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("shaBlockBytes + sizeRemainingBlock does not overflow")
    MCUXCLMEMORY_SET_INT(&shaBlockBytes[sizeRemainingBlock], 0x00u, numberOfZeroBytes);

    sizeRemainingBlock = algorithm->blockSize;
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize <<  3u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >>  5u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >> 13u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >> 21u) & 0xFFu);
    shaBlockBytes[sizeRemainingBlock - 1u] = (uint8_t)(inSize >> 29u);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* Load input data to SHA FIFO */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(shaBlockBytes, algorithm->blockSize));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

    uint32_t expectedSgiCounter = ((numberOfZeroBytes == algorithm->blockSize) ? 1u : 0u);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("expectedSgiCounter is less than MAX of uint32_t")
    expectedSgiCounter += numberOfFullBlocks + 1u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Wait until SGI has finished and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Check whether number of processed blocks is correct */
    expectedSgiCounter = expectedSgiCounter % (MCUXCLHASHMODES_INTERNAL_SGI_COUNT_MAX_VALUE + 1u);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, expectedSgiCounter));

    mcuxClHash_Status_t userCallbackStatus = MCUXCLHASH_STATUS_FAULT_ATTACK;

    /**************************************************************************************
    * Step 4: Copy result to output buffers
    **************************************************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storeHashResult(session, isrCtx->pOut, algorithm->hashSize));

    *isrCtx->pOutSize = algorithm->hashSize;
    userCallbackStatus = MCUXCLHASH_STATUS_JOB_COMPLETED;

    /* Clean-up */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback(
        session,
        workareaSizeToFree,
        userCallbackStatus,
        MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_INPUT | MCUXCLHASHMODES_REQ_DMA_OUTPUT
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sha2Sgi_ISR_Oneshot,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
        MCUX_CSSL_FP_CONDITIONAL((algorithm->counterSize > numZeroBytes),
            MCUXCLMEMORY_SET_INT_FP_EXPECT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
        ),
        MCUXCLMEMORY_SET_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_checkHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storeHashResult),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback)
    );
}

/**
 * @brief Sha2 Multipart Process (Update) Interrupt Service Routine (ISR).
 *
 * This routine is intended to be executed as an interrupt callback after SGI
 * has finished processing. It will check if the Sha2 operation has finished
 * without any errors, copy out the context and trigger
 * user callback on exit.
 *
 * @param session Current session handle
 *
 * @pre
 *  - session job workarea must point to initialized interrupt context
 * (mcuxClSession_job_setWa with initialized structure of mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t)
 *  - required hardware must be requested before routine execution:
 *    - Input Dma (input gathering)
 *    - SGI (sha2 calculation)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sha2Sgi_ISR_Multipart, mcuxClSession_HwInterruptHandler_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sha2Sgi_ISR_Multipart(mcuxClSession_Handle_t session)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sha2Sgi_ISR_Multipart);

    mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t *isrCtx = mcuxClHashModes_castToSha2MultipartInternalIsrCtx(mcuxClSession_job_getClWorkarea(session));
    mcuxClHash_ContextDescriptor_t *context = isrCtx->ctx;
    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;

    mcuxClSession_Channel_t inChannel = mcuxClSession_getDmaInputChannel(session);
    /* Wait for data copy to finish and check for errors */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inChannel));
    mcuxClDma_Drv_disableChannelDoneInterrupts(inChannel);
    mcuxClDma_Drv_disableErrorInterrupts(inChannel);

    uint32_t numberOfFullBlocks = isrCtx->numberOfFullBlocks;
    size_t inSize = isrCtx->inSize;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("the result is less than MAX of uint32_t as algorithm->blockSize is limited to PH_NCCLHASH_BLOCK_SIZE_MAX")
    size_t sizeRemainingBlock = inSize & (algorithm->blockSize - 1u);
    uint32_t offset = numberOfFullBlocks * algorithm->blockSize + isrCtx->inputOffset;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

    /* Wait until SGI has finished and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* We have isrCtx->inputOffset > 0 if and only if there was one block (the unprocessed buffer) processed before. */
    uint32_t expectedSgiCounter = numberOfFullBlocks + ((isrCtx->inputOffset > 0u)? 1u : 0u);
    /* Check whether number of processed blocks is correct */
    expectedSgiCounter = expectedSgiCounter % (MCUXCLHASHMODES_INTERNAL_SGI_COUNT_MAX_VALUE + 1u);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, expectedSgiCounter));

    /* Reach here mean more than 1 block processed correctly with DMA, then need store the state for next process */
    /* Extract state from SGI and put it into context */
    uint32_t *pState = mcuxClHash_getStatePtr(context);
    MCUX_CSSL_DI_RECORD(sgiStorePartialHash, pState);
    MCUX_CSSL_DI_RECORD(sgiStorePartialHash, algorithm->stateSize);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storePartialHash(pState, algorithm->stateSize));

    /* Copy the remaining data to the buffer in the workspace. */
    if (0u < sizeRemainingBlock)
    {
        mcuxCl_InputBuffer_t inputBuf = isrCtx->inputBuf;
        uint8_t *pUnprocessed = (uint8_t *)mcuxClHash_getUnprocessedPtr(context);
        /* Balance DI impact of mcuxClBuffer_read. */
        MCUX_CSSL_DI_RECORD(bufferReadBalancing, inputBuf);
        MCUX_CSSL_DI_RECORD(bufferReadBalancing, offset);
        MCUX_CSSL_DI_RECORD(bufferReadBalancing, pUnprocessed);
        MCUX_CSSL_DI_RECORD(bufferReadBalancing, sizeRemainingBlock);

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Offset computation does not overflow")
        // TODO CLNS-16738: Investigate whether we want Function call here? Needed to be reverted for FP build.
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(inputBuf, offset, pUnprocessed, sizeRemainingBlock));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        context->unprocessedLength = sizeRemainingBlock;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback(
        session,
        MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t)),
        MCUXCLHASH_STATUS_JOB_COMPLETED,
        MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_INPUT
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sha2Sgi_ISR_Multipart,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_checkHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storePartialHash),
        MCUX_CSSL_FP_CONDITIONAL((0u < sizeRemainingBlock),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback)
    );
}

/**
 * @brief Oneshot Skeleton implementation for DMA non-blocking Sha2 with SGI support
 *
 * Data Integrity: Expunge(pIn + inSize + pOut + pOutSize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_oneShot_Sha2_DmaNonBlocking, mcuxClHash_AlgoSkeleton_OneShot_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Sgi_oneShot_Sha2_DmaNonBlocking(
  mcuxClSession_Handle_t session,
  mcuxClHash_Algo_t algorithm,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_oneShot_Sha2_DmaNonBlocking);

    /**************************************************************************************
     * Step 1: Initialize SGI to perform Hash operation of dedicated algorithm
     **************************************************************************************/
    mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;

    /* Error handled inside HwRequest */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRequest(
      session,
      mcuxClHashModes_Sha2Sgi_ISR_Oneshot,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sha2Sgi_ISR_Oneshot),
      MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_INPUT | MCUXCLHASHMODES_REQ_DMA_OUTPUT));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));

    /* Configure respective SHA-2 in auto mode using standard IV */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(algorithmDetails->sgiUtilsInitHash(session, NULL, MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV));

    /* Enable counter, to count number of blocks processed by SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_enableHashCounter(0u));

    /**************************************************************************************
     * Step 2: Process full blocks of input data
     **************************************************************************************/

    /* All blocks can be processed in bulk directly from in */
    uint32_t numberOfFullBlocks = inSize / algorithm->blockSize;

    /* Wait until SGI is ready to take input and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Start SGI SHA2 processing */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

    if (0u < numberOfFullBlocks)
    {
        /* Load input data to FIFO register banks */
        /* Configure the DMA channels */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("numberOfFullBlocks * algorithm->blockSize cannot overflow")
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiSha2InputChannel(
          session,
          MCUXCLBUFFER_GET(pIn),
          numberOfFullBlocks * algorithm->blockSize));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        /* Enable interrupts for the completion of the input channel and for errors */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableChannelDoneInterrupts(inputChannel));
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableErrorInterrupts(inputChannel));

        MCUX_CSSL_FP_FUNCTION_CALL(mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t*, isrCtx, mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t))));

        isrCtx->inSize = inSize;
        isrCtx->inputBuf = pIn;
        isrCtx->numberOfFullBlocks = numberOfFullBlocks;
        isrCtx->pOut = pOut;
        isrCtx->pOutSize = pOutSize;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST("Algorithm field cannot be const to be able to set it")
        isrCtx->algorithm = (mcuxClHash_AlgorithmDescriptor_t *)algorithm;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST()
        mcuxClSession_job_setClWorkarea(session, isrCtx);

        /* Enable the DMA */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_startChannel(inputChannel));

        MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pIn);
        MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, inSize);
        MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOut);
        MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOutSize);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Sgi_oneShot_Sha2_DmaNonBlocking, MCUXCLHASH_STATUS_JOB_STARTED,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
            algorithmDetails->protectionToken_sgiUtilsInitHash,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
            MCUX_CSSL_FP_CONDITIONAL((0u < numberOfFullBlocks),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiSha2InputChannel),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableChannelDoneInterrupts),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableErrorInterrupts),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_startChannel)
            )
        );
    }

    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, pOut);
    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, algorithm->hashSize);


    /**************************************************************************************
     * Step 3: Pad the input data and process last block
     **************************************************************************************/
    /* Buffer in CPU WA to store the last block of data in the finalization phase */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize) cannot wrap")
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, shaBlock, mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize)));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    uint8_t *shaBlockBytes = (uint8_t *)shaBlock;

    /* Balance DI impact of mcuxClBuffer_read. */

    /* pIn and inSize are deliberately not recorded for bufferReadBalancing,
     * because mcuxClHashModes_Sgi_oneShot_Sha2_DmaNonBlocking is supposed to expunge pIn and inSize.
     */
    MCUX_CSSL_DI_RECORD(bufferReadBalancing, shaBlock);

    /* Copy the data to the buffer in the workspace. */
    /* Copy input to accumulation buffer */
    /* Error handled inside buffer_read*/
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, 0u, shaBlockBytes, inSize));

    /* add first byte of the padding: (remaining) < (block length) so there is space in the buffer */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("the result does not wrap since inSize is less then a block")
    shaBlockBytes[inSize] = 0x80u;
    uint32_t sizeRemainingBlock = inSize + 1u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    uint32_t numberOfZeroBytes = algorithm->blockSize - sizeRemainingBlock;

    /* Process partial padded block if needed */
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t numZeroBytes = numberOfZeroBytes);
    if (algorithm->counterSize > numberOfZeroBytes) // need room for 64 bit counter and one additional byte
    {
        /* Record input data for mcuxClMemory_set_int() */
        MCUX_CSSL_DI_RECORD(setShablock1, &shaBlockBytes[sizeRemainingBlock]);
        MCUX_CSSL_DI_RECORD(setShablock1, numberOfZeroBytes);
        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, shaBlock);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, algorithm->blockSize);

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("shaBlockBytes + sizeRemainingBlock does not overflow")
        MCUXCLMEMORY_SET_INT(&shaBlockBytes[sizeRemainingBlock], 0x00u, numberOfZeroBytes);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        /* Load input data to SHA FIFO */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(shaBlockBytes, algorithm->blockSize));
        sizeRemainingBlock = 0u;
        numberOfZeroBytes = algorithm->blockSize;
    }

    /* Perform padding by adding data counter */
    /* Record input data for mcuxClMemory_set_int() */
    MCUX_CSSL_DI_RECORD(setShablock2, &shaBlockBytes[sizeRemainingBlock]);
    MCUX_CSSL_DI_RECORD(setShablock2, numberOfZeroBytes);
    /* Record input data for mcuxClSgi_Utils_loadFifo() */
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, shaBlock);
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, algorithm->blockSize);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("shaBlockBytes + sizeRemainingBlock does not overflow")
    MCUXCLMEMORY_SET_INT(&shaBlockBytes[sizeRemainingBlock], 0x00u, numberOfZeroBytes);

    sizeRemainingBlock = algorithm->blockSize;
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize <<  3u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >>  5u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >> 13u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >> 21u) & 0xFFu);
    shaBlockBytes[sizeRemainingBlock - 1u] = (uint8_t)(inSize >> 29u);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* Load input data to SHA FIFO */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(shaBlockBytes, algorithm->blockSize));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algorithm->blockSize));
    /**************************************************************************************
     * Step 4: Copy result to output buffers
     **************************************************************************************/
    uint32_t expectedSgiCounter = ((numberOfZeroBytes == algorithm->blockSize) ? 1u : 0u);
    expectedSgiCounter += numberOfFullBlocks + 1u;


    /* pIn and inSize already expunged by bufferReadBalancing. */
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOut);
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOutSize);

    /* Complete all operations */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_Sgi_Sha2End(
      session,
      algorithm,
      expectedSgiCounter,
      pOut,
      pOutSize,
      MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_INPUT | MCUXCLHASHMODES_REQ_DMA_OUTPUT
    ));

    /* Set expectations and exit */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Sgi_oneShot_Sha2_DmaNonBlocking, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        algorithmDetails->protectionToken_sgiUtilsInitHash,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
        MCUX_CSSL_FP_CONDITIONAL((algorithm->counterSize > numZeroBytes),
            MCUXCLMEMORY_SET_INT_FP_EXPECT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
        ),
        MCUXCLMEMORY_SET_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sgi_Sha2End)
    );
}


/**
 * @brief Hash modes Sha2 non-blocking ending and cleanup operations. This function stores remaing part of data which
 *        is not sufficient to fill complete block. It needs to be run as a step of
 *        Sha2 SGI non-blocking processing stage as it expects full blocks to be handled already.
 *
 *
 * This function performs following Sha2 operations
 *  - store state in context when full block was processed during prevoius stages
 *  - copy input to accumulation buffer
 *  - mcuxClSgi_Drv_close
 *  - release SGI and DMA input
 *
 * @param[in]       session             Handle for the current CL session
 * @param[in]       context             Hash algorithm that should be used during the operations
 * @param[in]       pIn                 Pointer to input buffer object
 * @param[in]       inSize              Input size, where algoBlockSize > inSize
 * @param[out]      inOffset            Offset in buffer object
 * @param[out]      dataToCopyLength    Size indicating if data had to be transferred to unprocessed buffer
 *                                      during previous processing stages
 *
 * @return void
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FAILURE - if the number of processed blocks is incorrect.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_process_StoreRemainingData_Sha2_DmaNonBlocking)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_process_StoreRemainingData_Sha2_DmaNonBlocking(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t context,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  uint32_t inOffset,
  uint32_t dataToCopyLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_process_StoreRemainingData_Sha2_DmaNonBlocking);

    /* If just 1 block processed, update state in context */
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t unprocessedLen = context->unprocessedLength);
    if (((0u < dataToCopyLength) && (0u == context->unprocessedLength)))
    {
        uint32_t *pState = mcuxClHash_getStatePtr(context);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

        /* Wait until SGI has finished and check for SGI SHA error */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

        /* Extract state from SGI and put it into context */
        MCUX_CSSL_DI_RECORD(sgiStorePartialHash, pState);
        MCUX_CSSL_DI_RECORD(sgiStorePartialHash, context->algo->stateSize);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storePartialHash(pState, context->algo->stateSize));

        /* Check whether number of processed blocks is correct */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, 1u));
    }
    /* 0 < inSize < blockSize*/
    if (0u < inSize)
    {
        uint8_t *pUnprocessed = (uint8_t *)mcuxClHash_getUnprocessedPtr(context);
        /* Balance DI impact of mcuxClBuffer_read. */
        MCUX_CSSL_DI_RECORD(bufferRead2Balancing, pIn);
        MCUX_CSSL_DI_RECORD(bufferRead2Balancing, inOffset);
        MCUX_CSSL_DI_RECORD(bufferRead2Balancing, pUnprocessed);
        MCUX_CSSL_DI_RECORD(bufferRead2Balancing, inSize);

        /* Copy input to accumulation buffer */
        /* Error handled inside mcuxClBuffer_read */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, inOffset, pUnprocessed, inSize));

        /* Update context data / input pointer */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("the result does not wrap ")
        context->unprocessedLength += inSize;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRelease(session, MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_INPUT));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_process_StoreRemainingData_Sha2_DmaNonBlocking,
        MCUX_CSSL_FP_CONDITIONAL(((0u < dataToCopyLength) && (0u == unprocessedLen)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storePartialHash),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_checkHashCounter)
        ),
        MCUX_CSSL_FP_CONDITIONAL((0u < inSize),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRelease)
    );
}

/**
 * @brief Balance the flow protection for the SHA-2 DMA non-blocking process function when processing more than block size.
 *
 * @param[in]  unProcessedLenBefore  Length of unprocessed data before processing
 * @param[in]  unProcessedLenAfter   Length of unprocessed data after processing
 * @param[in]  dataToCopyLength      Length of data to copy to unprocessed buffer
 * @param[in]  unprocessedLength     Current unprocessed length value
 * @param[in]  algoBlockSize         Block size of the algorithm
 *
 * @return void
 *
 */
MCUX_CSSL_FP_COUNTER_STMT(
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_moreThanBlockSize)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_moreThanBlockSize(
  const uint32_t unProcessedLenBefore,
  const uint32_t unProcessedLenAfter,
  const uint32_t dataToCopyLength,
  const uint32_t unprocessedLength,
  const size_t algoBlockSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_moreThanBlockSize);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_moreThanBlockSize,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_add),
        MCUX_CSSL_FP_CONDITIONAL( (unProcessedLenBefore > 0u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
            MCUX_CSSL_FP_CONDITIONAL( (unProcessedLenAfter == algoBlockSize),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
            )
        ),
        MCUX_CSSL_FP_CONDITIONAL((!((0u < dataToCopyLength) && (0u == unprocessedLength))),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiSha2InputChannel),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableChannelDoneInterrupts),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_enableErrorInterrupts),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_startChannel));
}
)   /* end of MCUX_CSSL_FP_COUNTER_STMT */

/**
 * @brief Balance the flow protection for the SHA-2 DMA non-blocking process function when processing less than one block.
 *
 * @param[in]  unProcessedLenBefore  Length of unprocessed data before processing
 * @param[in]  unProcessedLenAfter   Length of unprocessed data after processing
 * @param[in]  algoBlockSize         Block size of the algorithm
 *
 * @return void
 *
 */
MCUX_CSSL_FP_COUNTER_STMT(
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_lessThanBlockSize)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_lessThanBlockSize(
  const uint32_t unProcessedLenBefore,
  const uint32_t unProcessedLenAfter,
  const size_t algoBlockSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_lessThanBlockSize);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_lessThanBlockSize,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_add),
        MCUX_CSSL_FP_CONDITIONAL( (unProcessedLenBefore > 0u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
            MCUX_CSSL_FP_CONDITIONAL( (unProcessedLenAfter == algoBlockSize),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
            )
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sgi_process_StoreRemainingData_Sha2_DmaNonBlocking));
}
)   /* end of MCUX_CSSL_FP_COUNTER_STMT */


/**
 * @brief Process Skeleton implementation for DMA non-blocking Sha2 with SGI support
 *
 * Data Integrity: Expunge(context + pIn + inSize)
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FULL - when the total input size exceeds the upper limit.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking, mcuxClHash_AlgoSkeleton_Process_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking (
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t context,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking);

    /******************************************************************************************************
     * Step 1: Initialize SGI to perform Hash operation of dedicated algorithm if no data processed yet.
     * Initialize Hash counter in SGI and local variables
     ******************************************************************************************************/
    uint32_t *pState = mcuxClHash_getStatePtr(context);
    const mcuxClHash_AlgorithmDescriptor_t *algorithm = context->algo;
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    const size_t algoBlockSize = algorithm->blockSize;
    // TODO CLNS-16738: please check
    //MCUX_CSSL_FP_COUNTER_STMT(const uint32_t expectedNumberOfCopyOperations = ((context->unprocessedLength + inSize % algoBlockSize) > 0u ? 1u : 0u) + (context->unprocessedLength > 0u ? 1u : 0u));

    /* Request resources */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRequest(
      session,
      mcuxClHashModes_Sha2Sgi_ISR_Multipart,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sha2Sgi_ISR_Multipart),
      MCUXCLHASHMODES_REQ_SGI | MCUXCLHASHMODES_REQ_DMA_INPUT
    ));

    /* Don't check the return value since it always return OK */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));

    /* Initialize state with IV */
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

    /* Enable counter, to count number of blocks processed by SGI in this call */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_enableHashCounter(0u));

    /* Compute counter increase, considering the amount of unprocessed data now and at the end of this function. */
    uint64_t counterIncrease = (uint64_t)inSize + context->unprocessedLength;

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Cannot wrap as counterIncrease >= (counterIncrease mod algoBlockSize)")
    counterIncrease -= MCUXCLHASH_MOD_BLOCK_SIZE(counterIncrease, (uint64_t)algoBlockSize);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHash_processedLength_add(context->processedLength, counterIncrease));

    /* Verify that the processed length will not exceed the algorithm's maximum allowed length. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("This index computation cannot wrap")
    uint8_t counterHighestByte = ((uint8_t *) context->processedLength)[algorithm->counterSize - 1u];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    if(0u != (counterHighestByte & algorithm->processedLengthCheckMask))
    {
        MCUXCLSESSION_ERROR(session, MCUXCLHASH_STATUS_FULL);
    }

    /**************************************************************************************
     * Step 2: Process input data
     **************************************************************************************/

    /* All blocks can be processed in bulk directly from pIn */
    /* If anything in pUnprocessed, first it needs to be filled up to blockSize and processed. Only then input can be passed into the SGI register */
    uint32_t dataToCopyLength = 0u;
    uint32_t inOffset = 0u;
    const uint32_t fullSize = inSize;
    uint32_t *pUnprocessed = mcuxClHash_getUnprocessedPtr(context);
    uint8_t *pUnprocessedBytes = (uint8_t *)pUnprocessed;

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t unProcessedLenBefore = context->unprocessedLength);
    if(context->unprocessedLength > 0u)
    {
        /* Take into account something might be already in unprocessed buffer */
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(context->unprocessedLength, 0u, algoBlockSize, MCUXCLHASH_STATUS_FAULT_ATTACK);
        dataToCopyLength = (inSize < (algoBlockSize - context->unprocessedLength)) ? inSize : (algoBlockSize - context->unprocessedLength);

        /* Balance DI impact of mcuxClBuffer_read. */
        MCUX_CSSL_DI_RECORD(bufferRead1Balancing, pIn);
        MCUX_CSSL_DI_RECORD(bufferRead1Balancing, inOffset);
        MCUX_CSSL_DI_RECORD(bufferRead1Balancing, pUnprocessedBytes + context->unprocessedLength);
        MCUX_CSSL_DI_RECORD(bufferRead1Balancing, dataToCopyLength);

        /* Copy input to accumulation buffer */
        /* Error handled inside mcuxClBuffer_read */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, inOffset, pUnprocessedBytes + context->unprocessedLength, dataToCopyLength));

        /* Update counter / context data / input pointer */
        inSize -= dataToCopyLength;
        inOffset += dataToCopyLength;
        context->unprocessedLength += dataToCopyLength;

        /* If whole unprocessed buffer filled, process block and update context data*/
        //MCUX_CSSL_FP_COUNTER_STMT(uint32_t unprocessedLen = context->unprocessedLength);
        if(context->unprocessedLength == algoBlockSize)
        {
            /* Record input data for mcuxClSgi_Utils_loadFifo() */
            MCUX_CSSL_DI_RECORD(sgiLoadFifo, pUnprocessed);
            MCUX_CSSL_DI_RECORD(sgiLoadFifo, algoBlockSize);

            /* Wait until SGI is ready to take input and check for SGI SHA error */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

            /* Start SGI SHA2 processing */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(pUnprocessedBytes, algoBlockSize));
            /* Update necessary context data, prepare for block processing */
            context->unprocessedLength = 0u;
        }
    }

    MCUX_CSSL_FP_COUNTER_STMT(
        /* During FP balancing the `unProcessedLenAfter` is checked to determine if the execution entered the if(context->unprocessedLength == algoBlockSize) branch. */
        uint32_t unProcessedLenAfter = (context->unprocessedLength == 0u) ?algoBlockSize :context->unprocessedLength;
    );

    /* Process whole blocks */
    uint32_t numberOfFullBlocks = inSize / algoBlockSize;
    if (algoBlockSize <= inSize)
    {
        mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);

        /* check if SGI has already started because it can't wait more than once after it start */
        if (!((0u < dataToCopyLength) && (0u == context->unprocessedLength)))
        {
            /* Wait until SGI is ready to take input and check for SGI SHA error */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

            /* Start SGI SHA2 processing */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));
        }


        /* Load input data to FIFO register banks */
        /* Configure the DMA channels */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("inOffset within valid pIn buffer")
        MCUXCLBUFFER_DERIVE_RO(pInWithOffset, pIn, inOffset);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("numberOfFullBlocks * algoBlockSize is less than MAX of uint32_t regarding to initialization above")

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiSha2InputChannel(
          session,
          MCUXCLBUFFER_GET(pInWithOffset),
          numberOfFullBlocks * algoBlockSize));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        /* Enable interrupts for the completion of the input channel and for errors */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableChannelDoneInterrupts(inputChannel));

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_enableErrorInterrupts(inputChannel));

        MCUX_CSSL_FP_FUNCTION_CALL(mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t*, isrCtx, mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t))));

        isrCtx->inSize = inSize;
        isrCtx->inputBuf = pIn;
        isrCtx->inputOffset = inOffset;
        isrCtx->numberOfFullBlocks = numberOfFullBlocks;
        isrCtx->ctx = context;
        mcuxClSession_job_setClWorkarea(session, isrCtx);

        /* Enable the DMA */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_startChannel(inputChannel));

        MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, context);
        MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, pIn);
        MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, fullSize);

        /* FP balancing */
        MCUX_CSSL_FP_COUNTER_STMT(MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_moreThanBlockSize(
                                                                    unProcessedLenBefore,
                                                                    unProcessedLenAfter,
                                                                    dataToCopyLength,
                                                                    context->unprocessedLength,
                                                                    algoBlockSize)));

        /* Early exit for non-blocking mode */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking, MCUXCLHASH_STATUS_JOB_STARTED,
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(initStateWithIvBranch, (0 > processedAlreadyOneBlock)),
            MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(initStateWithIvBranch, (0 <= processedAlreadyOneBlock)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_moreThanBlockSize)
        );
    }
    else
    {
        MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, context);
        MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, pIn);
        MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, fullSize);

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_OVERFLOWED_TRUNCATED_STATUS_CODE()

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_Sgi_process_StoreRemainingData_Sha2_DmaNonBlocking(
          session,
          context,
          pIn,
          inSize,
          inOffset,
          dataToCopyLength
        ));

        MCUX_CSSL_FP_COUNTER_STMT(
          MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_lessThanBlockSize(
            unProcessedLenBefore,
            unProcessedLenAfter,
            algoBlockSize
          ))
        );

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking, MCUXCLHASH_STATUS_OK,
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(initStateWithIvBranch, (0 > processedAlreadyOneBlock)),
            MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(initStateWithIvBranch, (0 <= processedAlreadyOneBlock)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sgi_process_Sha2_DmaNonBlocking_balanceFP_lessThanBlockSize)
        );
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OVERFLOWED_TRUNCATED_STATUS_CODE()
    }
}


/**********************************************************
 * Algorithm descriptor implementations
 **********************************************************/
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_224, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha224);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_256, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha256);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_384, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha384);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_512, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha512);


MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
