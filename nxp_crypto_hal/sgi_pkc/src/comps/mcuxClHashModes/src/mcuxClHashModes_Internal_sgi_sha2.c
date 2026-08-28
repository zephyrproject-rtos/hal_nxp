/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClHashModes_Internal_Resource_Common.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClHashModes_Internal_sgi_sha2_common.h>

/**********************************************************
 * Helper functions
 **********************************************************/

/**********************************************************
 * *INTERNAL* layer functions
 **********************************************************/

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_oneShot_Sha2, mcuxClHash_AlgoSkeleton_OneShot_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Sgi_oneShot_Sha2(
  mcuxClSession_Handle_t session,
  mcuxClHash_Algo_t algorithm,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_oneShot_Sha2);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->hashSize, MCUXCLHASH_OUTPUT_SIZE_SHA_224, MCUXCLHASH_OUTPUT_SIZE_SHA_512, MCUXCLHASH_STATUS_INVALID_PARAMS)
    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, pOut);
    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, algorithm->hashSize);

    /**************************************************************************************
     * Step 1: Initialize SGI to perform Hash operation of dedicated algorithm
     **************************************************************************************/

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) algorithm->pAlgorithmDetails;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    /* Error handled inside HwRequest */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRequest(session, NULL, 0U, MCUXCLHASHMODES_REQ_SGI));

    /* Don't check the return value since it always return OK */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));

    /* Configure respective SHA-2 in auto mode using standard IV */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(algorithmDetails->sgiUtilsInitHash(session, NULL, MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV));

    /* Enable counter, to count number of blocks processed by SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_enableHashCounter(0u));

    /**************************************************************************************
     * Step 2: Process full blocks of input data
     **************************************************************************************/

    /* All blocks can be processed in bulk directly from in */
    uint32_t offset = 0u;
    const size_t algoBlockSize = algorithm->blockSize;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algoBlockSize, MCUXCLHASH_BLOCK_SIZE_SHA_224, MCUXCLHASH_BLOCK_SIZE_SHA_512, MCUXCLHASH_STATUS_INVALID_PARAMS)
    uint32_t numberOfFullBlocks = inSize / algoBlockSize;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(numberOfFullBlocks, 0u, UINT32_MAX / MCUXCLHASH_BLOCK_SIZE_SHA_224, MCUXCLHASH_STATUS_INVALID_PARAMS)

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("numberOfFullBlocks is less than MAX of uint32_t even increased by 1")
    uint32_t expectedSgiCounter = numberOfFullBlocks + 1U;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    uint32_t fullBlocksLength = numberOfFullBlocks * algoBlockSize;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(fullBlocksLength, 0u, inSize, MCUXCLHASH_STATUS_INVALID_PARAMS)

    /* Wait until SGI is ready to take input */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Start SGI SHA2 processing */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

    /*
     * Buffer in CPU WA to be used to store the last block of data in the finalization phase
     */
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, shaBlock, mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algoBlockSize)));
    uint8_t *shaBlockBytes = (uint8_t *)shaBlock;

    if (0U < numberOfFullBlocks)
    {
        /* Load all full blocks of input data to SGI SHA FIFO SFR */
        MCUX_CSSL_DI_RECORD(inputParam, fullBlocksLength);
        MCUX_CSSL_DI_RECORD(inputParam, pIn);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo_buffer(pIn, fullBlocksLength));

        offset += fullBlocksLength;
    }

    /**************************************************************************************
     * Step 3: Pad the input data and process last block
     **************************************************************************************/

    size_t sizeRemainingBlock = (size_t)(inSize - fullBlocksLength);
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(sizeRemainingBlock, 0U, MCUXCLHASH_BLOCK_SIZE_SHA_512 - 1U, MCUXCLHASH_STATUS_INVALID_PARAMS)

    /* pIn is deliberately not recorded for sumOfBufferReadParams,
     * because mcuxClHashModes_Sgi_oneShot_Sha2 is supposed to expunge pIn.
     */
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, offset);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, shaBlock);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, sizeRemainingBlock);
    /* Copy the data to the buffer in the workspace. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, offset, shaBlockBytes, sizeRemainingBlock));

    /* add first byte of the padding: (remaining) < (block length) so there is space in the buffer */
    shaBlockBytes[sizeRemainingBlock] = 0x80u;
    sizeRemainingBlock += 1u;
    uint32_t numberOfZeroBytes = algoBlockSize - sizeRemainingBlock;

    /* Process partial padded block if needed */
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t numZeroBytes = numberOfZeroBytes);
    if (algorithm->counterSize > numberOfZeroBytes) // need room for 64 bit counter and one additional byte
    {
        /* Record input data for mcuxClMemory_set_int() */
        MCUX_CSSL_DI_RECORD(setShablock1, &shaBlockBytes[sizeRemainingBlock]);
        MCUX_CSSL_DI_RECORD(setShablock1, numberOfZeroBytes);

        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, shaBlock);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, algoBlockSize);

        MCUXCLMEMORY_SET_INT(&shaBlockBytes[sizeRemainingBlock], 0x00u, numberOfZeroBytes);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(shaBlockBytes, algoBlockSize));

        sizeRemainingBlock = 0u;
        numberOfZeroBytes = algoBlockSize;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("expectedSgiCounter is less than MAX of uint32_t even increased by 1")
        expectedSgiCounter += 1u;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    /* Perform padding by adding data counter */
    /* Record input data for mcuxClMemory_set_int() */
    MCUX_CSSL_DI_RECORD(setShablock2, &shaBlockBytes[sizeRemainingBlock]);
    MCUX_CSSL_DI_RECORD(setShablock2, numberOfZeroBytes);

    /* Record input data for mcuxClSgi_Utils_loadFifo() */
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, shaBlock);
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, algoBlockSize);

    MCUXCLMEMORY_SET_INT(&shaBlockBytes[sizeRemainingBlock], 0x00u, numberOfZeroBytes);

    sizeRemainingBlock = algoBlockSize;
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize <<  3u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >>  5u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >> 13u) & 0xFFu);
    shaBlockBytes[--sizeRemainingBlock] = (uint8_t)((inSize >> 21u) & 0xFFu);
    shaBlockBytes[sizeRemainingBlock - 1u] = (uint8_t)(inSize >> 29u);

    /* Load input data to SHA FIFO */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(shaBlockBytes, algoBlockSize));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

    /**************************************************************************************
     * Step 4: Copy result to output buffers
     **************************************************************************************/

    /* Wait until SGI has finished check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Check whether number of processed blocks is correct */
    expectedSgiCounter = expectedSgiCounter % ((uint32_t)MCUXCLHASHMODES_INTERNAL_SGI_COUNT_MAX_VALUE + 1u);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, expectedSgiCounter));

    /* Copy hash digest to output buffer */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storeHashResult(session, pOut, algorithm->hashSize));

    *pOutSize = algorithm->hashSize;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

    /* Free workarea (shaBlock) */
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(algoBlockSize));

    /* pIn already expunged by sumOfBufferReadParams. */
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, inSize);
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOut);
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOutSize);

    /* Release and exit */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRelease(session, MCUXCLHASHMODES_REQ_SGI));

    /* Set expectations and exit */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Sgi_oneShot_Sha2, MCUXCLHASH_STATUS_OK,
        /* Step 1 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        algorithmDetails->protectionToken_sgiUtilsInitHash,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
        /* Step 2 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_CONDITIONAL((0U < numberOfFullBlocks),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo_buffer)
        ),
        /* Step 3 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
        MCUX_CSSL_FP_CONDITIONAL((algorithm->counterSize > numZeroBytes),
            MCUXCLMEMORY_SET_INT_FP_EXPECT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
        ),
        MCUXCLMEMORY_SET_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        /* Step 4 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_checkHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storeHashResult),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRelease)
    );
}


/**
 * @brief Balance the flow protection for the SHA-2 process function.
 *
 * @param[in]  processedAlreadyOneBlock  Flag indicating if at least one block was already processed
 * @param[in]  unProcessedLenBefore      Length of unprocessed data before processing
 * @param[in]  unProcessedLenAfter       Length of unprocessed data after processing
 * @param[in]  remSize                   Remaining size of data to process
 * @param[in]  dataToCopyLen             Length of data to copy to unprocessed buffer
 * @param[in]  unProcessedLenLast        Last unprocessed length value
 * @param[in]  numFullBlocks             Number of full blocks to process
 * @param[in]  toProcessAtLeastOneBlock  Flag indicating if at least one block should be processed
 * @param[in]  remainingSize             Remaining size after processing full blocks
 * @param[in]  algoBlockSize             Block size of the algorithm
 *
 * @return void
 *
 */
MCUX_CSSL_FP_COUNTER_STMT(
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_process_Sha2_balanceFP)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_process_Sha2_balanceFP(
  const int processedAlreadyOneBlock,
  const uint32_t unProcessedLenBefore,
  const uint32_t unProcessedLenAfter,
  const uint32_t remSize,
  const uint32_t dataToCopyLen,
  const uint32_t unProcessedLenLast,
  const uint32_t numFullBlocks,
  const uint8_t toProcessAtLeastOneBlock,
  const uint32_t remainingSize,
  const size_t algoBlockSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_process_Sha2_balanceFP);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_process_Sha2_balanceFP,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_add),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sgi_process_Sha2_verifyProcessedLength),
        MCUX_CSSL_FP_CONDITIONAL( (unProcessedLenBefore > 0u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
            MCUX_CSSL_FP_CONDITIONAL( (unProcessedLenAfter == algoBlockSize),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
            )
        ),
        MCUX_CSSL_FP_CONDITIONAL( (algoBlockSize <= remSize),
            MCUX_CSSL_FP_CONDITIONAL((!((0U < dataToCopyLen) && (0U == unProcessedLenLast))),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
            ),
            MCUX_CSSL_FP_CONDITIONAL((0U < numFullBlocks),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo_buffer)
            )
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_CONDITIONAL((toProcessAtLeastOneBlock > 0u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_storePartialHash)
        ),
        MCUX_CSSL_FP_CONDITIONAL((0u < remainingSize),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_checkHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRelease));
}
)   /* end of MCUX_CSSL_FP_COUNTER_STMT */

/**
 * @brief Verify that the processed length does not exceed the algorithm's maximum allowed length.
 *
 * @param[in]  session          Handle for the current CL session
 * @param[in]  context          Hash context
 * @param[in]  algoCounterSize  Size of the algorithm's counter in bytes
 *
 * @return void
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FULL - if the processed length exceeds the maximum allowed length.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_process_Sha2_verifyProcessedLength)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_process_Sha2_verifyProcessedLength(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t context,
  const size_t algoCounterSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_process_Sha2_verifyProcessedLength);

    /* Verify that the processed length will not exceed the algorithm's maximum allowed length. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("algoCounterSize is greater than 1")
    uint8_t counterHighestByte = ((uint8_t *) context->processedLength)[algoCounterSize - 1u];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    if(0u != (counterHighestByte & context->algo->processedLengthCheckMask))
    {
        MCUXCLSESSION_ERROR(session, MCUXCLHASH_STATUS_FULL);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_process_Sha2_verifyProcessedLength);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_process_Sha2, mcuxClHash_AlgoSkeleton_Process_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Sgi_process_Sha2(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t context,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_process_Sha2);

    const uint32_t fullSize = inSize;

    /******************************************************************************************************
     * Step 1: Initialize SGI to perform Hash operation of dedicated algorithm if no data processed yet.
     * Initialize Hash counter in SGI and local variables
     ******************************************************************************************************/
    uint32_t offset = 0u;
    uint32_t *pUnprocessed = mcuxClHash_getUnprocessedPtr(context);
    uint8_t *pUnprocessedBytes = (uint8_t *)pUnprocessed;
    uint32_t *pState = mcuxClHash_getStatePtr(context);
    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) context->algo->pAlgorithmDetails;
    const size_t algoBlockSize = context->algo->blockSize;
    const size_t algoCounterSize = context->algo->counterSize;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algoBlockSize, MCUXCLHASH_BLOCK_SIZE_MIN, MCUXCLHASH_BLOCK_SIZE_MAX, MCUXCLHASH_STATUS_INVALID_PARAMS);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("numberOfFullBlocks cannot overflow for any combination of inSize and algorithm. ")
    uint32_t numberOfFullBlocks = (inSize / algoBlockSize) + ((inSize % algoBlockSize) + (context->unprocessedLength % algoBlockSize)) / algoBlockSize;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    uint32_t expectedSgiCounter = numberOfFullBlocks;
    uint8_t toProcessAtLeastOneBlock = (numberOfFullBlocks > 0u) ? 1u : 0u;

    /* Error handled inside HwRequest */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRequest(session, NULL, 0U, MCUXCLHASHMODES_REQ_SGI));

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

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Cannot wrap as counterIncrease >= (counterIncrease mod blockSize)")
    counterIncrease -= MCUXCLHASH_MOD_BLOCK_SIZE(counterIncrease, (uint64_t)algoBlockSize);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Add the counter increase to the processedLength */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHash_processedLength_add(context->processedLength, counterIncrease));

    /* assert algoCounterSize is between min (8U for sha2-224) and max (16U for sha2-512) */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(algoCounterSize, 8U, 16U)

    /* Verify that the processed length will not exceed the algorithm's maximum allowed length. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClHashModes_Sgi_process_Sha2_verifyProcessedLength(session, context, algoCounterSize)
    );

    /**************************************************************************************
     * Step 2: Process input data
     **************************************************************************************/

    /* All blocks can be processed in bulk directly from pIn */
    /* If anything in pUnprocessed, first it needs to be filled up to blockSize and processed. Only then input can be passed into the SGI register */
    uint32_t dataToCopyLength = 0u;
    uint32_t remainingSize = inSize;
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t unProcessedLenBefore = context->unprocessedLength);
    if(context->unprocessedLength > 0u)
    {
        /* Take into account something might be already in unprocessed buffer */
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(context->unprocessedLength, 0u, algoBlockSize, MCUXCLHASH_STATUS_FAULT_ATTACK);
        dataToCopyLength = (remainingSize < (algoBlockSize - context->unprocessedLength)) ? remainingSize : (algoBlockSize - context->unprocessedLength);
        MCUX_CSSL_DI_RECORD(sumOfBufferRead1Params, pIn);
        MCUX_CSSL_DI_RECORD(sumOfBufferRead1Params, offset);
        MCUX_CSSL_DI_RECORD(sumOfBufferRead1Params, (pUnprocessedBytes + context->unprocessedLength));
        MCUX_CSSL_DI_RECORD(sumOfBufferRead1Params, dataToCopyLength);
        /* Copy input to accumulation buffer */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn,
                                                        offset,
                                                        pUnprocessedBytes + context->unprocessedLength,
                                                        dataToCopyLength));

        /* Update counter / context data / input pointer */
        remainingSize -= dataToCopyLength;
        offset += dataToCopyLength;
        context->unprocessedLength += dataToCopyLength;

        /* If whole unprocessed buffer filled, process block and update context data*/
        if(context->unprocessedLength == algoBlockSize)
        {
            /* Record input data for mcuxClSgi_Utils_loadFifo() */
            MCUX_CSSL_DI_RECORD(sgiLoadFifo, pUnprocessedBytes);
            MCUX_CSSL_DI_RECORD(sgiLoadFifo, algoBlockSize);

            /* Wait until SGI is ready to take input and check for SGI SHA error */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

            /* Start SGI SHA2 processing */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(pUnprocessedBytes, algoBlockSize));

            context->unprocessedLength = 0u;
        }
    }

    MCUX_CSSL_FP_COUNTER_STMT(
        /* During FP balancing the `unProcessedLenAfter` is checked to determine if the execution entered the if(context->unprocessedLength == algoBlockSize) branch. */
        uint32_t unProcessedLenAfter = (context->unprocessedLength == 0u) ?algoBlockSize :context->unprocessedLength;
    );

    numberOfFullBlocks = remainingSize / algoBlockSize;

    MCUX_CSSL_FP_COUNTER_STMT(
        uint32_t remSize = remainingSize;
        uint32_t dataToCopyLen = dataToCopyLength;
        uint32_t unProcessedLenLast = context->unprocessedLength;
        uint32_t numFullBlocks = numberOfFullBlocks;
    )

    if (algoBlockSize <= remainingSize)
    {
        ++toProcessAtLeastOneBlock;
        /* check if SGI has already started because it can't wait more than once after a start */
        if (!((0U < dataToCopyLength) && (0U == context->unprocessedLength)))
        {
            /* Wait until SGI is ready to take input */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

            /* Start SGI SHA2 processing */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));
        }

        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(numberOfFullBlocks, 0U, (UINT32_MAX - offset)/ algoBlockSize, MCUXCLHASH_STATUS_FAULT_ATTACK);
        const uint32_t fullBlocksByteLength = numberOfFullBlocks * algoBlockSize;

        /* Load input data to FIFO register banks */
        if (0U < numberOfFullBlocks)
        {
            /* Load all full blocks of input data to SGI SHA FIFO SFR */
            /* Record data for mcuxClSgi_Utils_loadFifo_buffer() */
            MCUX_CSSL_DI_RECORD(inputParam, fullBlocksByteLength);
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("offset within valid pIn buffer")
            MCUXCLBUFFER_DERIVE_RO(pInWithOffset, pIn, offset);
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
            /* Record length for mcuxClSgi_Utils_loadFifo_buffer() */
            MCUX_CSSL_DI_RECORD(inputParam, MCUXCLBUFFER_GET(pInWithOffset));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo_buffer(pInWithOffset, fullBlocksByteLength));

            offset += fullBlocksByteLength;
        }

        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(remainingSize, fullBlocksByteLength, UINT32_MAX, MCUXCLHASH_STATUS_FAULT_ATTACK);
        remainingSize -= fullBlocksByteLength;
        context->unprocessedLength = 0U;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

    /* If at least 1 block processed, update state in context */
    if (toProcessAtLeastOneBlock > 0u)
    {
        /* Wait until SGI has finished and check for SGI SHA error */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

        /* Extract state from SGI and put it into context */
        MCUX_CSSL_DI_RECORD(sgiStorePartialHash, pState);
        MCUX_CSSL_DI_RECORD(sgiStorePartialHash, context->algo->stateSize);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storePartialHash(pState, context->algo->stateSize));
    }

    /* 0 < remainingSize < blockSize*/
    if(0u < remainingSize)
    {
        MCUX_CSSL_DI_RECORD(sumOfBufferRead2Params, pIn);
        MCUX_CSSL_DI_RECORD(sumOfBufferRead2Params, offset);
        MCUX_CSSL_DI_RECORD(sumOfBufferRead2Params, (pUnprocessedBytes + context->unprocessedLength));
        MCUX_CSSL_DI_RECORD(sumOfBufferRead2Params, remainingSize);
        /* Copy input to accumulation buffer */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Offset cannot overflow")
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn,
                                                        offset,
                                                        pUnprocessedBytes + context->unprocessedLength,
                                                        remainingSize));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        /* Update context data / input pointer */
        context->unprocessedLength += remainingSize;
    }

    /* Wait until SGI has finished and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Check whether number of processed blocks is correct */
    expectedSgiCounter = expectedSgiCounter % ((uint32_t)MCUXCLHASHMODES_INTERNAL_SGI_COUNT_MAX_VALUE + 1u);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, expectedSgiCounter));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

    MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, context);
    MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, pIn);
    MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, fullSize);

    /* Release and exit */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRelease(session, MCUXCLHASHMODES_REQ_SGI));

    /* FP is balanced in a seperate function for CCM */
    MCUX_CSSL_FP_COUNTER_STMT(MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_Sgi_process_Sha2_balanceFP(
                                                                processedAlreadyOneBlock,
                                                                unProcessedLenBefore,
                                                                unProcessedLenAfter,
                                                                remSize,
                                                                dataToCopyLen,
                                                                unProcessedLenLast,
                                                                numFullBlocks,
                                                                toProcessAtLeastOneBlock,
                                                                remainingSize,
                                                                algoBlockSize)));

    /* Set expectations, balancing FP and exit */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_Sgi_process_Sha2, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(initStateWithIvBranch, (0 > processedAlreadyOneBlock)),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(initStateWithIvBranch, (0 <= processedAlreadyOneBlock)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_Sgi_process_Sha2_balanceFP)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_Sgi_finish_Sha2, mcuxClHash_AlgoSkeleton_Finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_finish_Sha2(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t context,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_Sgi_finish_Sha2);

    const size_t algoBlockSize = context->algo->blockSize;
    const size_t algoCounterSize = context->algo->counterSize;
    const size_t algoStateSize = context->algo->stateSize;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algoStateSize, MCUXCLHASH_STATE_SIZE_MIN, MCUXCLHASH_STATE_SIZE_MAX, MCUXCLHASH_STATUS_INVALID_PARAMS);
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algoBlockSize, MCUXCLHASH_BLOCK_SIZE_MIN, MCUXCLHASH_BLOCK_SIZE_MAX, MCUXCLHASH_STATUS_INVALID_PARAMS);

    /* context is deliberately not recorded for clearContext,
     * because mcuxClHashModes_Sgi_finish_Sha2 is supposed to expunge context.
     */
    MCUX_CSSL_DI_RECORD(clearContext, sizeof(mcuxClHash_ContextDescriptor_t) + algoBlockSize + algoStateSize);

    uint32_t *pUnprocessed = mcuxClHash_getUnprocessedPtr(context);
    uint8_t *pUnprocessedBytes = (uint8_t *)pUnprocessed;
    uint32_t *pState = mcuxClHash_getStatePtr(context);

    const mcuxClHashModes_Internal_AlgorithmDescriptor_t *algorithmDetails = (const mcuxClHashModes_Internal_AlgorithmDescriptor_t *) context->algo->pAlgorithmDetails;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(context->algo->hashSize, MCUXCLHASH_OUTPUT_SIZE_SHA_224, MCUXCLHASH_OUTPUT_SIZE_SHA_512, MCUXCLHASH_STATUS_INVALID_PARAMS)
    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, pOut);
    MCUX_CSSL_DI_RECORD(storeHashResultBalancing, context->algo->hashSize);

    /* Error hanlded inside HwRequest */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRequest(session, NULL, 0U, MCUXCLHASHMODES_REQ_SGI));

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
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("index computation does not wrap. ")
    uint8_t counterHighestByte = ((uint8_t *) context->processedLength)[algoCounterSize - 1u];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    if(0u != (counterHighestByte & context->algo->processedLengthCheckMask))
    {
        MCUXCLSESSION_ERROR(session, MCUXCLHASH_STATUS_FULL);
    }

    /* Check whether context->unprocessedLength would wrap */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(context->unprocessedLength, 0u, algoBlockSize - 1u, MCUXCLHASH_STATUS_INVALID_PARAMS);
    pUnprocessedBytes[context->unprocessedLength++] = 0x80u; //set first bit of padding

    uint32_t remainingBlockLength = algoBlockSize - (context->unprocessedLength);

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t remBlockLen = remainingBlockLength);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t counterLen = algoCounterSize);

    MCUX_CSSL_FP_BRANCH_DECL(processRemBlock);
    if(algoCounterSize > remainingBlockLength) // need room for 64 bit counter
    {
        /* Set remaining bytes in accumulation buffer to zero */
        /* Record input data for mcuxClMemory_set_int() */
        MCUX_CSSL_DI_RECORD(setUnprocessed1, pUnprocessedBytes + context->unprocessedLength);
        MCUX_CSSL_DI_RECORD(setUnprocessed1, remainingBlockLength);

        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, pUnprocessed);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, algoBlockSize);

        MCUXCLMEMORY_SET_INT(pUnprocessedBytes + context->unprocessedLength, 0x00u, remainingBlockLength);

        /* Wait until SGI is ready to take input and check for SGI SHA error */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

        /* Start SGI SHA2 processing */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

        /* Load input data to SHA FIFO */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(pUnprocessedBytes, algoBlockSize));

        MCUX_CSSL_FP_BRANCH_POSITIVE(processRemBlock,
            MCUXCLMEMORY_SET_INT_FP_EXPECT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo)
        );

        remainingBlockLength = algoBlockSize;
        context->unprocessedLength = 0u;
    }
    else
    {
      /* Start SGI SHA2 processing */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));
        MCUX_CSSL_FP_BRANCH_NEGATIVE(processRemBlock, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start));
    }

    /* Set remaining bytes in accumulation buffer to zero */
    /* Record input data for mcuxClMemory_set_int() */
    MCUX_CSSL_DI_RECORD(setUnprocessed2, pUnprocessedBytes + context->unprocessedLength);
    MCUX_CSSL_DI_RECORD(setUnprocessed2, remainingBlockLength);

    /* Record input data for mcuxClSgi_Utils_loadFifo() */
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, pUnprocessed);
    MCUX_CSSL_DI_RECORD(sgiLoadFifo, algoBlockSize);

    MCUXCLMEMORY_SET_INT(pUnprocessedBytes + context->unprocessedLength, 0x00u, remainingBlockLength);

    /* Perform padding by adding data counter - length is added from end of the array; byte-length is converted to bit-length */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHash_processedLength_toBits(context->processedLength));

    MCUX_CSSL_FP_LOOP_DECL(loopPadding);
    for(uint32_t i = 0u; i < algoCounterSize; ++i)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("blockSize is always large enough so that the index computation does not wrap. ")
        pUnprocessedBytes[algoBlockSize - i - 1u] = ((uint8_t*)context->processedLength)[i];
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_FP_LOOP_ITERATION(loopPadding);
    }

    uint32_t expectedSgiCounter = ((remainingBlockLength == algoBlockSize) ? 2u : 1u);

    /* Load input data to FIFO register banks */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(pUnprocessedBytes, algoBlockSize));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

    *pOutSize = context->algo->hashSize;

    /* Wait until SGI has finished and check for SGI SHA error */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

    /* Check whether number of processed blocks is correct */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_checkHashCounter(session, expectedSgiCounter));

    /* Copy hash digest to output buffer */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_storeHashResult(session, pOut, context->algo->hashSize));

    /* Clear context */
    MCUXCLMEMORY_CLEAR_INT((uint8_t*) context, sizeof(mcuxClHash_ContextDescriptor_t) + algoBlockSize + algoStateSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

    /* context already expunged by clearContext. */
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pOut);
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pOutSize);

    /* Release and exit */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_HwRelease(session, MCUXCLHASHMODES_REQ_SGI));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_Sgi_finish_Sha2,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_HwRequest),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(initStateWithIvBranch, (0 > processedAlreadyOneBlock)),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(initStateWithIvBranch, (0 <= processedAlreadyOneBlock)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableHashCounter),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_add),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(processRemBlock, (counterLen > remBlockLen)),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(processRemBlock, (counterLen <= remBlockLen)),
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

/**********************************************************
 * Algorithm descriptor implementations
 **********************************************************/
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_224, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha224);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_256, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha256);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_384, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha384);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_512, &mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha512);



MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
