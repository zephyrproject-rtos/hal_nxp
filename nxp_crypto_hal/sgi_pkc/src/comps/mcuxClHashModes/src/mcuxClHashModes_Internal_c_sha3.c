/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
#include <mcuxCsslAnalysis.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClHashModes_Core_c_sha3.h>
#include <mcuxClMemory.h>
#include <internal/mcuxClMemory_Internal.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>

/**********************************************************
 * *INTERNAL* layer functions
 **********************************************************/
/**
 * @brief Oneshot Skeleton implementation for Sha3 in SW
 *
 * Data Integrity: Expunge(pIn + inSize + outSizeRequested + pOut + pOutSizeComputed)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_oneShot_sha3_shake_core)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_oneShot_sha3_shake_core(
  mcuxClSession_Handle_t session,
  mcuxClHash_Algo_t algorithm,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  const uint32_t outSizeRequested,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSizeComputed,
  const uint8_t paddingByte)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_oneShot_sha3_shake_core);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algorithm->blockSize, 1u, 200u, MCUXCLHASH_STATUS_FAULT_ATTACK)

    /**************************************************************************************/
    /*                      Allocate buffers in workarea and initialize state             */
    /**************************************************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pState, mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLHASH_STATE_SIZE_SHA3)));

    uint8_t *pState8 = (uint8_t*)pState;

    /* Initialize state */
    MCUX_CSSL_DI_RECORD(memClearDst, pState);
    MCUX_CSSL_DI_RECORD(memClearLen, MCUXCLHASH_STATE_SIZE_SHA3);
    MCUXCLMEMORY_CLEAR_INT(pState8, MCUXCLHASH_STATE_SIZE_SHA3);

    /**************************************************************************************/
    /*                Absorb all whole blocks of input data                               */
    /**************************************************************************************/

    uint32_t offset = 0u;
    uint32_t numOfFullBlocks = inSize / algorithm->blockSize;

    /* Balance DI for call */
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, numOfFullBlocks * (uint32_t) pIn);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, numOfFullBlocks * (uint32_t) pState);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, numOfFullBlocks * (uint32_t) pState);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, numOfFullBlocks * (uint32_t) algorithm->blockSize);

    MCUX_CSSL_FP_LOOP_DECL(fullBlocksLoop);
    for(uint32_t copiedBlocks = 0u; copiedBlocks < numOfFullBlocks; copiedBlocks++)
    {
        /* Absorb data  */
        MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, offset);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_readAndXor(pIn, offset, pState8, pState8, algorithm->blockSize));

        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(offset, 0U, UINT32_MAX - algorithm->blockSize, MCUXCLHASH_STATUS_FAULT_ATTACK)
        offset += algorithm->blockSize;

        /* Perform Keccak permutations */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_core_c_keccak(pState));
        MCUX_CSSL_FP_LOOP_ITERATION(fullBlocksLoop, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_readAndXor),
                                                   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_core_c_keccak));
    }
    uint32_t sizeCopiedBytes = numOfFullBlocks * algorithm->blockSize;

    /**************************************************************************************/
    /*                          Add padding and absorb last block                         */
    /**************************************************************************************/

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inSize, sizeCopiedBytes, UINT32_MAX, MCUXCLHASH_STATUS_FAULT_ATTACK)
    uint32_t sizeRemainingBytes = inSize - sizeCopiedBytes;

    /* Absorb remaining input into the state */
    /* pIn is deliberately not recorded for sumOfBufferReadParams,
     * because mcuxClHashModes_C_oneShot_sha3 is supposed to expunge pIn.
     */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(offset, 0U, sizeCopiedBytes, MCUXCLHASH_STATUS_FAULT_ATTACK)

    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, offset);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, pState);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, pState);
    MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, sizeRemainingBytes);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_readAndXor(pIn, offset, pState8, pState8, sizeRemainingBytes));

    /* Set first byte of the padding */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(sizeRemainingBytes, 0u, algorithm->blockSize - 1u, MCUXCLHASH_STATUS_FAULT_ATTACK)
    pState8[sizeRemainingBytes] ^= paddingByte;

    /* Set the final byte of padding (could be also the first byte of padding ;) )*/
    pState8[algorithm->blockSize-1u] ^= 0x80u;

    /**************************************************************************************/
    /*                 Keep squezing to get a hash of required size                       */
    /**************************************************************************************/

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("the result does not wrap")
    const uint32_t nrSqueezingIterations = (outSizeRequested / algorithm->blockSize) + (((outSizeRequested % algorithm->blockSize) + algorithm->blockSize - 1u) / algorithm->blockSize);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, nrSqueezingIterations * (uintptr_t) pOut);
    MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, nrSqueezingIterations * (uintptr_t) pState);
    MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, outSizeRequested);

    MCUX_CSSL_FP_LOOP_DECL(squeezedBytesLoop);
    for (uint32_t squeezedBytes = 0; squeezedBytes < outSizeRequested; squeezedBytes += algorithm->blockSize)
    {
        /* Perform Keccak permutations */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_core_c_keccak(pState));

        /* Copy hash to output */
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(squeezedBytes, 0u, outSizeRequested, MCUXCLHASH_STATUS_FAULT_ATTACK)
        MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, squeezedBytes);
        uint32_t bufferWriteSize = (outSizeRequested - squeezedBytes > algorithm->blockSize) ? (algorithm->blockSize) : (outSizeRequested - squeezedBytes);

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, squeezedBytes, pState8, bufferWriteSize));

        MCUX_CSSL_FP_LOOP_ITERATION(squeezedBytesLoop, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_core_c_keccak),
                                                      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
    }

    /* Free workarea (pState and pAccumulationBuffer) */
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLHASH_STATE_SIZE_SHA3));

    *pOutSizeComputed = outSizeRequested;

    /**************************************************************************************/
    /*                          Exit                                                      */
    /**************************************************************************************/

    /* pIn is already expunged by sumOfBufferReadParams. */
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, inSize);
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, outSizeRequested);
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOut);
    MCUX_CSSL_DI_EXPUNGE(oneshotSkeletonParams, pOutSizeComputed);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_C_oneShot_sha3_shake_core,
        1U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUX_CSSL_FP_LOOP_ITERATIONS(fullBlocksLoop, numOfFullBlocks),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_readAndXor),
        MCUX_CSSL_FP_LOOP_ITERATIONS(squeezedBytesLoop, nrSqueezingIterations));
}

#if defined(MCUXCL_FEATURE_HASH_C_SHA3)
/*
 * Data Integrity: Expunge(pIn + inSize + pOut + pOutSize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_oneShot_sha3, mcuxClHash_AlgoSkeleton_OneShot_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_C_oneShot_sha3(
  mcuxClSession_Handle_t session,
  mcuxClHash_Algo_t algorithm,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_oneShot_sha3);

    MCUX_CSSL_DI_RECORD(oneshotSkeletonParams, algorithm->hashSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_oneShot_sha3_shake_core(session,
                                                                            algorithm,
                                                                            pIn,
                                                                            inSize,
                                                                            algorithm->hashSize,
                                                                            pOut,
                                                                            pOutSize,
                                                                            0x06u   /* padding SHA3 */
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_C_oneShot_sha3, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_oneShot_sha3_shake_core)
    );
}
#endif /* if defined(MCUXCL_FEATURE_HASH_C_SHA3) */

/**
 * @brief Oneshot Skeleton implementation for Shake in SW
 *
 * @post
 *  - Data Integrity: Expunge(pIn + inSize + pOut + pOutSize)
 *
 * @param[in]       session    Handle for the current CL session.
 * @param[in]       algorithm  Hash algorithm that should be used during the computation.
 * @param[in]       pIn        Pointer to the input buffer that contains the data
 *                             that needs to be hashed.
 * @param[in]       inSize     Number of bytes of data in the pIn buffer.
 * @param[in,out]   pOut       Pointer to the output buffer where the computed hash
 *                             value is written.
 * @param[in,out]   pOutSize   Pointer to the number of bytes, which shall be computed.
 *                             After the function call, it contains the number of bytes written to the pOut buffer.
 *
 * @retval #MCUXCLHASH_STATUS_ERROR_MEMORY_ALLOCATION   workarea allocation fails
 * @retval #MCUXCLHASH_STATUS_OK                        operation is successful
 * @return Error code (see @ref mcuxClHashModes, @ref mcuxClBuffer) in case of other failures.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_oneShot_hash_shake, mcuxClHash_AlgoSkeleton_OneShot_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_C_oneShot_hash_shake(
  mcuxClSession_Handle_t session,
  mcuxClHash_Algo_t algorithm,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_oneShot_hash_shake);

    uint32_t outSize = *pOutSize;
    if(0U == outSize)
    {
        outSize = algorithm->hashSize;
    }
    else
    {
        *pOutSize = 0U;
    }
    MCUX_CSSL_DI_RECORD(oneshotSkeletonParams, outSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_oneShot_sha3_shake_core(session,
                                                                            algorithm,
                                                                            pIn,
                                                                            inSize,
                                                                            outSize,
                                                                            pOut,
                                                                            pOutSize,
                                                                            0x1FU   /* padding SHA3_SHAKE */
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_C_oneShot_hash_shake, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_oneShot_sha3_shake_core)
    );
}

/*
 * Data Integrity: Expunge(pIn + inSize + pOut + *pOutSize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_oneShot_xof_shake, mcuxClHash_AlgoSkeleton_OneShot_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_C_oneShot_xof_shake(
  mcuxClSession_Handle_t session,
  mcuxClHash_Algo_t algorithm,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_oneShot_xof_shake);

    const uint32_t outSize = *pOutSize;
    *pOutSize = 0U;

    MCUX_CSSL_DI_RECORD(oneshotSkeletonParams, pOutSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_oneShot_sha3_shake_core(session,
                                                                            algorithm,
                                                                            pIn,
                                                                            inSize,
                                                                            outSize,
                                                                            pOut,
                                                                            pOutSize,
                                                                            0x1FU   /* padding SHA3_SHAKE */
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_C_oneShot_xof_shake, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_oneShot_sha3_shake_core)
    );
}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_process_sha3_shake, mcuxClHash_AlgoSkeleton_Process_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_C_process_sha3_shake(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_process_sha3_shake);

    const mcuxClHash_AlgorithmDescriptor_t * algo = pContext->algo;
    uint32_t offset = 0U;
    uint32_t *pState = mcuxClHash_getStatePtr(pContext);
    uint8_t *pState8 = (uint8_t*)pState;

    MCUX_CSSL_FP_FUNCTION_CALL(int32_t, squeezeAlreadyCalled, mcuxClHash_processedLength_cmp(pContext->processedLength, MCUXCLHASHMODES_SHAKE_PHASE_SQUEEZE));
    if (0 == squeezeAlreadyCalled)
    {
        /* Invalid call sequence */
        MCUXCLSESSION_ERROR(session, MCUXCLHASH_STATUS_FAILURE);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(int32_t, firstBlockAbsorbed, mcuxClHash_processedLength_cmp(pContext->processedLength, MCUXCLHASHMODES_SHAKE_PHASE_INIT));
    if (0 == firstBlockAbsorbed)
    {
        /* Initialize state */
        MCUX_CSSL_DI_RECORD(memClearDst, pState);
        MCUX_CSSL_DI_RECORD(memClearLen, MCUXCLHASH_STATE_SIZE_SHA3);
        MCUXCLMEMORY_CLEAR_INT(pState8, MCUXCLHASH_STATE_SIZE_SHA3);
        /* The state has been cleared. Advance the phase indicator, such that
         * the state is not cleared any more in a future call to this function */
        pContext->processedLength[0] = MCUXCLHASHMODES_SHAKE_PHASE_ABSORB;
    }

    /**************************************************************************************/
    /*                Absorb all whole blocks of input data                               */
    /**************************************************************************************/
    uint32_t remainingBytes = inSize;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algo->blockSize, MCUXCLHASH_BLOCK_SIZE_SHA_1, MCUXCLHASH_BLOCK_SIZE_MAX, MCUXCLHASH_STATUS_FAULT_ATTACK)

    uint32_t nrLoopIterations = 0u;
    if (0u < remainingBytes)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("the result does not wrap")
        nrLoopIterations = (remainingBytes / algo->blockSize) + ((remainingBytes % algo->blockSize) + pContext->unprocessedLength + algo->blockSize - 1u) / algo->blockSize;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, nrLoopIterations * (uintptr_t) pIn);
        MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, nrLoopIterations * (uintptr_t) pState + pContext->unprocessedLength);
        MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, nrLoopIterations * (uintptr_t) pState + pContext->unprocessedLength);
        MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, remainingBytes);
    }

    MCUX_CSSL_FP_LOOP_DECL(RemainBytesLoop);
    while (0u < remainingBytes)
    {
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->unprocessedLength, 0U, algo->blockSize - 1U, MCUXCLHASH_STATUS_FAULT_ATTACK)
        /* Take into account something might be already in unprocessed buffer */
        uint32_t dataToCopyLength = (remainingBytes < (algo->blockSize - pContext->unprocessedLength)) ? remainingBytes : (algo->blockSize - pContext->unprocessedLength);

        /* Absorb data into state */
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(offset, 0u, UINT32_MAX, MCUXCLHASH_STATUS_FAULT_ATTACK)
        MCUX_CSSL_DI_RECORD(sumOfBufferReadParams, offset);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_readAndXor(pIn, offset, pState8 + pContext->unprocessedLength, pState8 + pContext->unprocessedLength, dataToCopyLength));

        /* Update counter / pContext data / input pointer */
        remainingBytes -= dataToCopyLength;
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(dataToCopyLength, 0u, UINT32_MAX, MCUXCLHASH_STATUS_FAULT_ATTACK)
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(offset, 0u, UINT32_MAX - dataToCopyLength, MCUXCLHASH_STATUS_FAULT_ATTACK)
        offset += dataToCopyLength;
        pContext->unprocessedLength += dataToCopyLength;

        /* When whole unprocessed buffer filled, process block and update pContext data*/
        MCUX_CSSL_FP_BRANCH_DECL(remainFullBlockBranch);
        if (pContext->unprocessedLength == algo->blockSize)
        {
            /* Perform Keccak permutations */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_core_c_keccak(pState));

            /* Data processed, nothing in the buffer, state buffer updated*/
            pContext->unprocessedLength = 0u;

            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Flow protections checks the result modulo 2^32 so that a potential overflow does not change the result")
            //MCUX_CSSL_FP_COUNTER_STMT(blocksProcessedCounter += 1u;)
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
            MCUX_CSSL_FP_BRANCH_POSITIVE(remainFullBlockBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_core_c_keccak));
        }
        MCUX_CSSL_FP_LOOP_ITERATION(RemainBytesLoop, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_readAndXor),
                                                    MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(remainFullBlockBranch, pContext->unprocessedLength == 0u));
    }

    /**************************************************************************************/
    /*                          Exit                                                      */
    /**************************************************************************************/
    MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, pContext);
    MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, pIn);
    MCUX_CSSL_DI_EXPUNGE(processSkeletonParams, inSize);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_C_process_sha3_shake, MCUXCLHASH_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_CONDITIONAL((0 == firstBlockAbsorbed), MCUXCLMEMORY_CLEAR_INT_FP_EXPECT),
        MCUX_CSSL_FP_LOOP_ITERATIONS(RemainBytesLoop, nrLoopIterations)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_Sha3_shake_finishAbsorb_core(
  mcuxClHash_Context_t pContext,
  const uint8_t paddingByte)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core);

    const mcuxClHash_AlgorithmDescriptor_t * algo = pContext->algo;
    uint8_t *pState = (uint8_t *)mcuxClHash_getStatePtr(pContext);

    MCUX_CSSL_FP_FUNCTION_CALL(int32_t, firstBlockAbsorbed, mcuxClHash_processedLength_cmp(pContext->processedLength, MCUXCLHASHMODES_SHAKE_PHASE_INIT));
    /* Initialize state. Needed if process has never been called */
    if (0 == firstBlockAbsorbed)
    {
        /* Initialize state */
        MCUX_CSSL_DI_RECORD(memClearDst, pState);
        MCUX_CSSL_DI_RECORD(memClearLen, MCUXCLHASH_STATE_SIZE_SHA3);
        MCUXCLMEMORY_CLEAR_INT((uint8_t *)pState, MCUXCLHASH_STATE_SIZE_SHA3);
        /* The state has been cleared. Phase indicator is not advanced,
         * since it is not needed for padding and the context is cleared at the end of this function. */
    }

    /* Switch from Absorb to Squeeze phase (such that state initialization and padding is only done once) */
    pContext->processedLength[0] = MCUXCLHASHMODES_SHAKE_PHASE_SQUEEZE;


    /**************************************************************************************/
    /*             Add padding  and absorb remaining input to the state                   */
    /**************************************************************************************/

    /* Set first byte of the padding */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(algo->blockSize, 1u, 200u, /*no return*/)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->unprocessedLength, 0u, algo->blockSize - 1u, /*no return*/)
    pState[pContext->unprocessedLength] ^= paddingByte;

    /* Set the final byte of padding (could be also the first byte of padding ;) )*/
    pState[algo->blockSize-1u] ^= 0x80u;

    /* Reset unprocessedLength to prepare for repurposing as squeezeed bytes counter */
    pContext->unprocessedLength = 0u;

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_CONDITIONAL((0 == firstBlockAbsorbed), MCUXCLMEMORY_CLEAR_INT_FP_EXPECT)
    );
}


/**
 * @brief Squeeze process implementation for Shake in SW
 *
 * @param[in]       session    Handle for the current CL session, it is UNUSED.
 * @param[in,out]   pContext   Handle for the current context.
 * @param[in,out]   pOut       Pointer to the input buffer that contains the data
 *                             that needs to be hashed.
 * @param[in]       outSize    Number of bytes of data in the pIn buffer.
 *
 * @post Data Integrity: Expunge(pContext + pOut + outSize)
 *
 * @retval #MCUXCLHASH_STATUS_OK                        operation is successful
 * @return Error code (see @ref mcuxClHashModes, @ref mcuxClBuffer) in case of other failures.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_shake_squeeze)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_shake_squeeze(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClHash_Context_t pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t outSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_shake_squeeze);

    const mcuxClHash_AlgorithmDescriptor_t * algo = pContext->algo;
    uint32_t *pState = mcuxClHash_getStatePtr(pContext);
    uint8_t *pState8 = (uint8_t*)pState;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->unprocessedLength, 0u, algo->blockSize, MCUXCLHASH_STATUS_FAULT_ATTACK)
    MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, pOut);
    MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, (uintptr_t)pState + (algo->blockSize - pContext->unprocessedLength));

    MCUX_CSSL_FP_BRANCH_DECL(squeezeBranch);
    MCUX_CSSL_FP_COUNTER_STMT(const uint32_t unProDataSize = pContext->unprocessedLength);
    /* Squeeze block-wise from the state. Output data from the state and only permute when a whole block has been output.
    This allows to have keccak permutations at the right time across multiple squeeze calls. */
    if(outSize <= pContext->unprocessedLength) /* Not more data than available is requested -> Take from the state */
    {
        /* No squeeze needed, take from the state, skipping previously used data */
        MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, outSize);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, 0u, pState8 + (algo->blockSize - pContext->unprocessedLength), outSize));

        pContext->unprocessedLength -= outSize;
        MCUX_CSSL_FP_BRANCH_POSITIVE(squeezeBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
    }
    else /* More data than available is requested -> Take all remaining data from the state, repeat: (call keccak permutation, take more data from the state) */
    {
        uint32_t outputGenerated = 0u;
        /* Take all data from the state, skipping previously used data */
        MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, pContext->unprocessedLength);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, 0u, pState8 + (algo->blockSize - pContext->unprocessedLength), pContext->unprocessedLength));

        outputGenerated += pContext->unprocessedLength;
        pContext->unprocessedLength = 0u;

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("the result does not wrap")
        const uint32_t nrLoopIterations = (outSize - outputGenerated) / algo->blockSize + ((outSize - outputGenerated) % algo->blockSize + algo->blockSize - 1u) / algo->blockSize;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, nrLoopIterations * (uintptr_t) pOut);
        MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, nrLoopIterations * (uintptr_t) pState);
        MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, outSize - outputGenerated);

        MCUX_CSSL_FP_LOOP_DECL(Loop_OutSizeBlocks);
        while(outSize != outputGenerated)
        {
            /* Call Keccak permutation to generate new data */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_core_c_keccak(pState));

            /* Take what is needed from the state */
            MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(outputGenerated, 0u, outSize, MCUXCLHASH_STATUS_FAULT_ATTACK)
            uint32_t currentOutSize = ((outSize - outputGenerated > algo->blockSize) ? algo->blockSize : (outSize - outputGenerated));
            MCUX_CSSL_DI_RECORD(sumOfBufferWriteParams, outputGenerated);
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, outputGenerated, pState8, currentOutSize));

            pContext->unprocessedLength = algo->blockSize - currentOutSize;
            outputGenerated += currentOutSize;
            MCUX_CSSL_FP_LOOP_ITERATION(Loop_OutSizeBlocks, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_core_c_keccak),
                                                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
        }
        MCUX_CSSL_FP_BRANCH_NEGATIVE(squeezeBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write),
                                                   MCUX_CSSL_FP_LOOP_ITERATIONS(Loop_OutSizeBlocks, nrLoopIterations));
    }

    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pContext);
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pOut);
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, outSize);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_C_shake_squeeze, MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(squeezeBranch, outSize <= unProDataSize),
                                                                   MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(squeezeBranch, outSize > unProDataSize));
}

#if defined(MCUXCL_FEATURE_HASH_C_SHA3)
/**
 * @brief Finish Skeleton implementation for Shake in SW
 *
 * Data Integrity: Expunge(pContext + pOut + pOutSize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_finish_sha3, mcuxClHash_AlgoSkeleton_Finish_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_finish_sha3(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_finish_sha3);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core(pContext, 0x06u));

    /**************************************************************************************/
    /*                               Squeeze a single block                               */
    /**************************************************************************************/

    /* Record output size for mcuxClHashModes_C_shake_squeeze */
    MCUX_CSSL_DI_RECORD(finishSkeletonParams, pContext->algo->hashSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_shake_squeeze(session, pContext, pOut, pContext->algo->hashSize));

    /* Output the number of bytes squeezed */
    *pOutSize = pContext->algo->hashSize;

    /* Balance record of pOutSize from Hash API level */
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pOutSize);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_C_finish_sha3,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_shake_squeeze)
    );
}
#endif /* if defined(MCUXCL_FEATURE_HASH_C_SHA3) */


#if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE)
/**
 * @brief Finish Skeleton implementation for Shake in SW via the Hash API.
 *        If *pOutSize is 0, we take algorithm->hashSize as the output length, otherwise we take *pOutSize.
 *
 * @param[in]       session    Handle for the current CL session, it is UNUSED.
 * @param[in,out]   pContext   Handle for the current context.
 * @param[in,out]   pOut       Pointer to the output buffer.
 * @param[in]       pOutSize   Pointer to the number of bytes, which shall be computed.
 *                             After the function call, it contains the number of bytes written to the pOut buffer.
 *
 * @post Data Integrity: Expunge(context + pOut + pOutSize)
 *
 * @retval #MCUXCLHASH_STATUS_OK                        operation is successful
 * @return Error code (see @ref mcuxClHashModes, @ref mcuxClBuffer) in case of other failures.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_finish_hash_shake, mcuxClHash_AlgoSkeleton_Finish_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_finish_hash_shake(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_finish_hash_shake);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core(pContext, 0x1fu));

    /**************************************************************************************/
    /*                            Squeeze a single block                                  */
    /**************************************************************************************/
    uint32_t outSize = *pOutSize;
    if(0U == outSize)
    {
        outSize = pContext->algo->hashSize;
    }
    else
    {
        *pOutSize = 0U;
    }

    /* Record output size for mcuxClHashModes_C_shake_squeeze */
    MCUX_CSSL_DI_RECORD(finishSkeletonParams, outSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_shake_squeeze(session, pContext, pOut, outSize));

    /* Output the number of bytes squeezed */
    *pOutSize = outSize;

    /* Balance record of pOutSize from Hash API level */
    MCUX_CSSL_DI_EXPUNGE(finishSkeletonParams, pOutSize);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_C_finish_hash_shake,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_shake_squeeze)
    );
}
#endif /* if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) */

#if defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256)
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_C_generate_shake, mcuxClHash_AlgoSkeleton_Finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_generate_shake(
  mcuxClSession_Handle_t session,
  mcuxClHash_Context_t pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutSize)

{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_C_generate_shake);

    MCUX_CSSL_FP_FUNCTION_CALL(int32_t, squeezeAlreadyCalled, mcuxClHash_processedLength_cmp(pContext->processedLength,MCUXCLHASHMODES_SHAKE_PHASE_SQUEEZE));

    MCUX_CSSL_FP_BRANCH_DECL(squeezeAlreadyCalledBranch);
    MCUX_CSSL_FP_COUNTER_STMT(const int32_t ifSqueezeAlreadyCalled = squeezeAlreadyCalled);
    if(-1 == squeezeAlreadyCalled)
    {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core(pContext, 0x1fu));
        MCUX_CSSL_FP_BRANCH_POSITIVE(squeezeAlreadyCalledBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core));
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_shake_squeeze(session, pContext, pOut, *pOutSize));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_C_generate_shake,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_processedLength_cmp),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(squeezeAlreadyCalledBranch, -1 == ifSqueezeAlreadyCalled),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_shake_squeeze)
    );
}
#endif /*#if defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256) */


/**********************************************************
 * Algorithm descriptor implementations
 **********************************************************/
#define MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3        NULL
#define MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3_SHAKE  NULL

#if defined(MCUXCL_FEATURE_HASH_C_SHA3)
MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_224, MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_256, MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_384, MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_512, MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3);
#endif /* defined(MCUXCL_FEATURE_HASH_C_SHA3) */

#if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE)
MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_128, MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3_SHAKE);

MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_256, MCUXCLHASHMODES_INTERNAL_ALGODESCRIPTOR_C_SHA3_SHAKE);
#endif /* defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) */
