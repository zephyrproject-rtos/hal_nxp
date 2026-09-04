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

/** @file  mcuxClKdfModes_NIST_SP800_56C.c
 *  @brief Implementation of SP800-56C Key Derivation */

#include <mcuxClCore_FunctionIdentifiers.h> // Code flow protection

#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClHmac.h>
#include <mcuxClKey.h>
#include <mcuxClKdfModes.h>
#include <mcuxClMac.h>
#include <mcuxClMacModes.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClKdfModes_Internal_Algorithms.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMac_Internal_Constants.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClMemory_ClearSecure_Internal.h>
#include<internal/mcuxClHashModes_Internal.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C(
  mcuxClKey_DerivationMode_t * pDerivationMode,
  const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
  mcuxClMac_Mode_t macMode,
  mcuxClHash_Algo_t hashFunction,
  uint32_t options UNUSED_PARAM)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C);

    pDerivationMode->derivationAlgorithm = derivationAlgorithm;
    pDerivationMode->macMode = macMode;
    pDerivationMode->hashFunction = hashFunction;
    pDerivationMode->options = 0u; // no options for this mode

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C, MCUXCLKEY_STATUS_OK);
}

#define COUNTER_BYTE_LEN       (sizeof(uint32_t))

/**
 * @brief NIST SP800-56C OneStep implementation using a Hash algorithm.
 *
 * Data Integrity: Expunge(inputs[1].size, inputs[1].input, inputs[0].size, inputs[0].input, derivedKeySize, derivationKeySize, pMessageZ)
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    mcuxClKey_Derivation_t derivationMode,
    uint8_t *pMessageZ,
    uint8_t *pOutputKey,
    uint32_t derivedKeySize,
    uint32_t derivationKeySize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash);

    /* Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
        - The number of operations depends on the requested size of the derived output key,
        and on the output size of the chosen hash function.
        - The outputBytesLastIteration will be < hashSize if the requested key's size is
        not a multiple of the hash function output size (1 <= outputBytesLastIteration <= hashSize).
    */
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].input);

    MCUXCLBUFFER_INIT(pOutputKeyBuf, pSession, pOutputKey, derivedKeySize);

    /* As derivedKeySize is an uint32_t, nOfIterations cannot overflow. This also guarantees "n <= 2^32-1" as required by the specification. */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(derivationMode->hashFunction->hashSize, MCUXCLHASH_OUTPUT_SIZE_SHA_1, MCUXCLHASH_MAX_OUTPUT_SIZE, MCUXCLKEY_STATUS_INVALID_INPUT)
    uint32_t nOfIterations = derivedKeySize / derivationMode->hashFunction->hashSize;
    uint32_t outputBytesLastIteration = derivedKeySize % derivationMode->hashFunction->hashSize;

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKeySize);

    if(outputBytesLastIteration != 0u)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("As hashSize is greater than 1, this cannot overflow.")
        nOfIterations++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full hash output size */
        outputBytesLastIteration = derivationMode->hashFunction->hashSize;
    }

    /* Allocate space for the hash context. */
    uint32_t hashContextWordSize = mcuxClHash_getContextWordSize(derivationMode->hashFunction);
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hashContextWordSize, sizeof(mcuxClHash_ContextDescriptor_t),
        sizeof(mcuxClHash_ContextDescriptor_t) + MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + MCUXCLHASH_STATE_SIZE_MAX + MCUXCLHASH_BLOCK_SIZE_MAX,
        MCUXCLKEY_STATUS_INVALID_INPUT)
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClHash_Context_t, pContext, mcuxClSession_allocateWords_cpuWa(pSession, hashContextWordSize));

    /* Allocate space for the hash digest. */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pTempOut, mcuxClSession_allocateWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t)));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* SREQI_KDF_1 - DI records for clearing of pTempOut */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pTempOut);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, derivationMode->hashFunction->hashSize);
    MCUXCLBUFFER_INIT(pTempOutBuf, pSession, pTempOut, derivationMode->hashFunction->hashSize);

    uint32_t outSize = 0u;
    for(uint32_t counter = 1u; counter <= nOfIterations; counter++)
    {
        MCUX_CSSL_DI_RECORD(loop, 1u);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("pContext has the correct type.")
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init));
        MCUX_CSSL_FP_FUNCTION_CALL(init_result, mcuxClHash_init(pSession, pContext, derivationMode->hashFunction));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
        if(MCUXCLHASH_STATUS_OK != init_result)
        {
            /* clean-up the CPU work-area: pTempOut and pContext */
            mcuxClSession_freeWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t) + hashContextWordSize);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, init_result);
        }

        /* Initialize auxiliary space for it's big-endian representation. */
        uint32_t counterBigEndian = 0x0u;
        uint8_t * pCounterBigEndian = (uint8_t *)&counterBigEndian;

        /* Convert the counter to big-endian. */
        mcuxClMemory_StoreBigEndian32(pCounterBigEndian, counter);

        /* Process the counter. */
        MCUXCLBUFFER_INIT_RO(pCounterBigEndianBuf, pSession, pCounterBigEndian, COUNTER_BYTE_LEN);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called between any mcuxClHash_finish and mcuxClHash_process calls, so the integrity of pContext is ensured.")
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process));
        MCUX_CSSL_FP_FUNCTION_CALL(process_result1, mcuxClHash_process(pSession,
                                                                pContext,
                                                                pCounterBigEndianBuf,
                                                                COUNTER_BYTE_LEN));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if(MCUXCLHASH_STATUS_OK != process_result1)
        {
            /* clean-up the CPU work-area: pTempOut and pContext */
            mcuxClSession_freeWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t) + hashContextWordSize);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, process_result1);
        }

        /* Process the message Z. */
        MCUXCLBUFFER_INIT_RO(pMessageZBuf, pSession, pMessageZ, derivationKeySize);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called between any mcuxClHash_finish and mcuxClHash_process calls, so the integrity of pContext is ensured.")
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process));
        MCUX_CSSL_FP_FUNCTION_CALL(process_result2, mcuxClHash_process(pSession,
                                                                pContext,
                                                                pMessageZBuf,
                                                                derivationKeySize));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if(MCUXCLHASH_STATUS_OK != process_result2)
        {
            /* clean-up the CPU work-area: pTempOut and pContext */
            mcuxClSession_freeWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t) + hashContextWordSize);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, process_result2);
        }

        /* Process the fixedInfo. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called between any mcuxClHash_finish and mcuxClHash_process calls, so the integrity of pContext is ensured.")
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process));
        MCUX_CSSL_FP_FUNCTION_CALL(process_result3, mcuxClHash_process(pSession, pContext, inputs[0].input, inputs[0].size));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if(MCUXCLHASH_STATUS_OK != process_result3)
        {
            /* clean-up the CPU work-area: pTempOut and pContext */
            mcuxClSession_freeWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t) + hashContextWordSize);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, process_result3);
        }

        if (counter != nOfIterations)
        {
            /* Create the digest. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called before and between any mcuxClHash_finish calls, so the integrity of pContext is ensured.")
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish));
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClHash_finish(pSession, pContext, pOutputKeyBuf, &outSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if(MCUXCLHASH_STATUS_OK != finish_result)
            {
                /* clean-up the CPU work-area: pTempOut and pContext */
                mcuxClSession_freeWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t) + hashContextWordSize);

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, finish_result);
            }
        }
        else
        {
            /* Create the digest. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called before and between any mcuxClHash_finish calls, so the integrity of pContext is ensured.")
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish));
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClHash_finish(pSession, pContext, pTempOutBuf, &outSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if(MCUXCLHASH_STATUS_OK != finish_result)
            {
                /* clean-up the CPU work-area: pTempOut and pContext */
                mcuxClSession_freeWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t) + hashContextWordSize);

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, finish_result);
            }

            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pOutputKeyBuf);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, MCUXCLBUFFER_GET(pTempOutBuf));
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, outputBytesLastIteration);
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(
                pOutputKeyBuf,
                0u,
                (uint8_t *)MCUXCLBUFFER_GET(pTempOutBuf),
                outputBytesLastIteration));
            /* SREQI_KDF_1 - Clear temp out buffer after usage */
            MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
            MCUXCLMEMORY_CLEAR_SECURE_INT(pTempOut, derivationMode->hashFunction->hashSize);
        }

        MCUXCLBUFFER_UPDATE(pOutputKeyBuf, derivationMode->hashFunction->hashSize);
        outSize = 0u;
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivationKeySize);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pMessageZ);
    MCUX_CSSL_DI_EXPUNGE(loop, nOfIterations);

    /* clean-up the CPU work-area: pTempOut and pContext */
    mcuxClSession_freeWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t) + hashContextWordSize);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief NIST SP800-56C OneStep implementation using a Mac algorithm.
 *
 * Data Integrity: Expunge(inputs[1].size, inputs[1].input, inputs[0].size, inputs[0].input, derivedKeySize, derivationKeySize, pMessageZ)
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    mcuxClKey_Derivation_t derivationMode,
    uint8_t *pMessageZ,
    uint8_t *pOutputKey,
    uint32_t derivedKeySize,
    uint32_t derivationKeySize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac);

    /* Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
        - The number of operations depends on the requested size of the derived output key,
        and on the output size of the chosen MAC function.
        - The outputBytesLastIteration will be < macByteSize if the requested key's size is
        not a multiple of the MAC function output size (1 <= outputBytesLastIteration <= macByteSize).
    */
    MCUXCLBUFFER_INIT(pOutputKeyBuf, pSession, pOutputKey, derivedKeySize);

    /* As derivedKeySize is an uint32_t, nOfIterations cannot overflow. This also guarantees "n <= 2^32-1" as required by the specification. */
    uint32_t nOfIterations = derivedKeySize / derivationMode->macMode->common.macByteSize;
    uint32_t outputBytesLastIteration = derivedKeySize % derivationMode->macMode->common.macByteSize;

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKeySize);

    if(outputBytesLastIteration != 0u)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("As macByteSize is greater than 1, this cannot overflow.")
        nOfIterations++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full MAC output block */
        outputBytesLastIteration = derivationMode->macMode->common.macByteSize;
    }

    /* Allocate space for the MAC context. */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKdfModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(pSession, sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* Allocate space for the Hmac key handle */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_Handle_t, hmacKeyHandle, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* Initialize hmacKey.
        * Use the salt as HMAC key. If there is no salt given (inputs[1].size = 0),
        * HMAC will create a zero key of block length, as required by SP800-56C.
        */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, intermediateArray, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS));

    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, inputs[1].input);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, intermediateArray);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, inputs[1].size);
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(inputs[1].input, 0u, intermediateArray, inputs[1].size));

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].input);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("hmacKeyHandle has the correct type.")
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init));
    MCUX_CSSL_FP_FUNCTION_CALL(resultKeyInit, mcuxClKey_init(
    /* mcuxClSession_Handle_t session         */ pSession,
    /* mcuxClKey_Handle_t key                 */ hmacKeyHandle,
    /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Hmac_variableLength,
    /* uint8_t * pKeyData                    */ (const uint8_t *)intermediateArray,
    /* uint32_t keyDataLength                */ inputs[1].size));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    if (MCUXCLKEY_STATUS_OK != resultKeyInit)
    {
        /* free hmacKeyHandle, pWa and the intermediate array for salt. */
        mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].size);

    uint32_t outSize = 0u;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("pWa has the correct type.")
    uint8_t *pMacResult = pWa->macResult_Wa;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    MCUXCLBUFFER_INIT(pTempMacResultBuf, pSession, pMacResult, derivationMode->macMode->common.macByteSize);
    /* SREQI_KDF_1 - DI records for clearing of pMacResult */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pMacResult);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, derivationMode->macMode->common.macByteSize);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Allowed memory reinterpretation, 32Bit alignment of context_Wa is guranteed")
    mcuxClMac_Context_t * const pContext = (mcuxClMac_Context_t *) &pWa->context_Wa;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    for(uint32_t counter = 1u; counter <= nOfIterations; counter++)
    {
        MCUX_CSSL_DI_RECORD(loop, 1u);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("pContext has the correct type.")
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init));
        MCUX_CSSL_FP_FUNCTION_CALL(init_result, mcuxClMac_init(pSession, pContext, hmacKeyHandle, derivationMode->macMode));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if(MCUXCLMAC_STATUS_OK != init_result)
        {
            /* free hmacKeyHandle, pWa and the intermediate array for salt. */
            mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, init_result);
        }

        /* Initialize auxiliary space for it's big-endian representation. */
        uint32_t counterBigEndian = 0x0u;
        uint8_t * pCounterBigEndian = (uint8_t *)&counterBigEndian;

        /* Convert the counter to big-endian. */
        mcuxClMemory_StoreBigEndian32(pCounterBigEndian, counter);

        /* Process the counter. */
        MCUXCLBUFFER_INIT_RO(pCounterBigEndianBuf, pSession, pCounterBigEndian, COUNTER_BYTE_LEN);
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
        MCUX_CSSL_FP_FUNCTION_CALL(process_result1, mcuxClMac_process(pSession,
                                                                pContext,
                                                                pCounterBigEndianBuf,
                                                                COUNTER_BYTE_LEN));

        if(MCUXCLMAC_STATUS_OK != process_result1)
        {
            /* free hmacKeyHandle, pWa and the intermediate array for salt. */
            mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, process_result1);
        }

        /* Process the message Z. */
        MCUXCLBUFFER_INIT_RO(pMessageZBuf, pSession, pMessageZ, derivationKeySize);
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
        MCUX_CSSL_FP_FUNCTION_CALL(process_result2, mcuxClMac_process(pSession,
                                                                pContext,
                                                                pMessageZBuf,
                                                                derivationKeySize));

        if(MCUXCLMAC_STATUS_OK != process_result2)
        {
            /* free hmacKeyHandle, pWa and the intermediate array for salt. */
            mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, process_result2);
        }

        /* Process the fixedInfo. */
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
        MCUX_CSSL_FP_FUNCTION_CALL(process_result3, mcuxClMac_process(pSession, pContext, inputs[0].input, inputs[0].size));

        if(MCUXCLMAC_STATUS_OK != process_result3)
        {
            /* free hmacKeyHandle, pWa and the intermediate array for salt. */
            mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, process_result3);
        }

        if (counter != nOfIterations)
        {
            /* Create the digest. */
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClMac_finish(pSession, pContext, pOutputKeyBuf, &outSize));

            if(MCUXCLMAC_STATUS_OK != finish_result)
            {
                /* free hmacKeyHandle, pWa and the intermediate array for salt. */
                mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, finish_result);
            }
        }
        else
        {
            /* Create the digest. */
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClMac_finish(pSession, pContext, pTempMacResultBuf, &outSize));

            if(MCUXCLMAC_STATUS_OK != finish_result)
            {
                /* free hmacKeyHandle, pWa and the intermediate array for salt. */
                mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, finish_result);
            }

            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pOutputKeyBuf);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, MCUXCLBUFFER_GET(pTempMacResultBuf));
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, outputBytesLastIteration);
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(
                pOutputKeyBuf,
                0u,
                (uint8_t *)MCUXCLBUFFER_GET(pTempMacResultBuf),
                outputBytesLastIteration));
            MCUX_CSSL_ANALYSIS_START_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()
            /* SREQI_KDF_1 - Clear temp buffer after usage */
            MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
            MCUXCLMEMORY_CLEAR_SECURE_INT(pMacResult, derivationMode->macMode->common.macByteSize);
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()
        }

        MCUXCLBUFFER_UPDATE(pOutputKeyBuf, derivationMode->macMode->common.macByteSize);
        outSize = 0u;
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivationKeySize);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pMessageZ);
    MCUX_CSSL_DI_EXPUNGE(loop, nOfIterations);

    /* free hmacKeyHandle, pWa and the intermediate array for salt. */
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)) + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief Key derivation engine function for NIST SP800-56C Counter Mode.
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     inputs            The first entry points to the fixedInfo parameter; the second to the optional salt, if given.
 * @param[in]     numberOfInputs    Should be 2 if salt is passed, 1 if fixedInfo is passed but not salt, and 0 if neither is passed.
 * @param[out]    derivedKey        Output key handle.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep, mcuxClKey_DerivationEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep);

    uint32_t derivedKeySize = mcuxClKey_getSize(derivedKey);
    uint32_t derivationKeySize = mcuxClKey_getSize(derivationKey);

    uint8_t *pMessageZ = NULL;
    MCUX_CSSL_FP_EXPECT(MCUXCLKEY_LOAD_FP_CALLED(derivationKey));
    MCUXCLKEY_LOAD_FP(pSession, derivationKey, &pMessageZ, NULL, MCUXCLKEY_ENCODING_SPEC_ACTION_PTR);

    // Use pointer from mcuxClKey_getKeyData as temporary buffer for the plain key data
    uint8_t *pOutputKey = mcuxClKey_getKeyData(derivedKey);

    /* DI unbalancing to protect input parameters, balanced individually after last usage. */
    MCUX_CSSL_DI_RECORD(kdfParameters, derivedKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, pMessageZ);
    MCUX_CSSL_DI_RECORD(kdfParameters, derivationKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, pOutputKey);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[1].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[1].input);

    /* Input validation */

    /* Both inputs are optional, but must at least be given as NULL pointer with size 0 */
    if(2u != numberOfInputs)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    if(((inputs[0].size != 0u) && MCUXCLBUFFER_IS_NULL(inputs[0].input)) ||
       ((inputs[1].size != 0u) && MCUXCLBUFFER_IS_NULL(inputs[1].input)))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be 0 or larger than the available buffer space. */
    if((0u == derivedKeySize) || (derivedKeySize > derivedKey->container.length))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    /* Either macMode or hashFunction shall be given, not both, not none. */
    if(((NULL == derivationMode->macMode) && (NULL == derivationMode->hashFunction)) ||
       ((NULL != derivationMode->macMode) && (NULL != derivationMode->hashFunction)))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }
    /* hashFunction case */
    if(NULL != derivationMode->hashFunction)
    {
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash));
        MCUX_CSSL_FP_FUNCTION_CALL(oneStepHashResult, mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash(
            pSession,
            inputs,
            derivationMode,
            pMessageZ,
            pOutputKey,
            derivedKeySize,
            derivationKeySize));
        if(MCUXCLKEY_STATUS_OK != oneStepHashResult)
        {
            MCUXCLSESSION_ERROR(pSession, oneStepHashResult);
        }
    }
    /* macMode case */
    else /* (NULL != derivationMode->macMode) */
    {
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac));
        MCUX_CSSL_FP_FUNCTION_CALL(oneStepMacResult, mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac(
            pSession,
            inputs,
            derivationMode,
            pMessageZ,
            pOutputKey,
            derivedKeySize,
            derivationKeySize));
        if(MCUXCLKEY_STATUS_OK != oneStepMacResult)
        {
            MCUXCLSESSION_ERROR(pSession, oneStepMacResult);
        }
    }

    /* Apply the requested encoding to the generated key data. This will overwrite the plain key data with the encoded key data */
    MCUX_CSSL_FP_EXPECT(MCUXCLKEY_STORE_FP_CALLED(derivedKey));
    MCUXCLKEY_STORE_FP(pSession, derivedKey, pOutputKey, MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pOutputKey);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep);
}

#define TWOSTEP_INPUT_LABEL_INDEX      (0) // inputs[0]
#define TWOSTEP_INPUT_CONTEXT_INDEX    (1) // inputs[1]
#define TWOSTEP_INPUT_SALT_INDEX       (2) // inputs[2]

/**
 * @brief NIST SP800-56C TwoStep implementation using a CMAC algorithm.
 *
 * Data Integrity: Expunge(inputs[0].size, inputs[0].input, inputs[1].size, inputs[1].input, inputs[2].size, inputs[2].input, derivationKeySize, pData)
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    uint8_t *pData,
    uint32_t derivationKeySize,
    mcuxClKey_Handle_t derivedKey
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac);

    /***************************/
    /* Prepare CMAC key handle */
    /***************************/
    uint32_t cmacKeyLength = inputs[TWOSTEP_INPUT_SALT_INDEX].size;
    mcuxClKey_Type_t cmacKeyType = NULL;
    switch(cmacKeyLength)
    {
        case MCUXCLAES_AES128_KEY_SIZE:
        {
            cmacKeyType = mcuxClKey_Type_Aes128;
            break;
        }
#ifdef MCUXCL_FEATURE_AES192
        case MCUXCLAES_AES192_KEY_SIZE:
        {
            cmacKeyType = mcuxClKey_Type_Aes192;
            break;
        }
#endif /* MCUXCL_FEATURE_AES192 */
        case MCUXCLAES_AES256_KEY_SIZE:
        {
            cmacKeyType = mcuxClKey_Type_Aes256;
            break;
        }
        default:
        {
            cmacKeyType = NULL;
            break;
        }
    }
    if(NULL == cmacKeyType)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    const uint8_t *pCmacKeyData;
    uint32_t usedCpuWaWords = 0u;
    if(NULL == MCUXCLBUFFER_GET(inputs[TWOSTEP_INPUT_SALT_INDEX].input))
    {
        /* Salt is strictly needed. If null-pointer is given, locate on cpuWa. */
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
        MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pCmacKeyDefault, mcuxClSession_allocateWords_cpuWa(pSession, cmacKeyLength / sizeof(uint32_t)));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

        usedCpuWaWords += cmacKeyLength / sizeof(uint32_t);

        MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pCmacKeyDefault);
        MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, cmacKeyLength);
        MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_INT_FP_EXPECT);
        MCUXCLMEMORY_CLEAR_INT(pCmacKeyDefault, cmacKeyLength);
        pCmacKeyData = pCmacKeyDefault;
    }
    else
    {
      MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
      MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, intermediateArray, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS));

      usedCpuWaWords += MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS;

      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, inputs[TWOSTEP_INPUT_SALT_INDEX].input);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, intermediateArray);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, inputs[TWOSTEP_INPUT_SALT_INDEX].size);
      MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(inputs[TWOSTEP_INPUT_SALT_INDEX].input, 0u, intermediateArray, inputs[TWOSTEP_INPUT_SALT_INDEX].size));
      pCmacKeyData = (const uint8_t*)intermediateArray;
    }

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_Handle_t, cmacKey, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    usedCpuWaWords += MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS;

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("cmacKey has the correct type.")
    mcuxClKey_Status_t resultKeyInit1 = mcuxClKey_init(
        /* mcuxClSession_Handle_t session         */ pSession,
        /* mcuxClKey_Handle_t key                 */ cmacKey,
        /* mcuxClKey_Type_t type                  */ cmacKeyType,
        /* uint8_t * pKeyData                    */ pCmacKeyData,
        /* uint32_t keyDataLength                */ cmacKeyLength);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    if(MCUXCLKEY_STATUS_OK != resultKeyInit1)
    {
        mcuxClSession_freeWords_cpuWa(pSession, usedCpuWaWords);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    /***************************/
    /*  Prepare Kdk key handle */
    /***************************/
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, kdkKeyBuffer, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLAES_AES128_KEY_SIZE_IN_WORDS));

    usedCpuWaWords += MCUXCLAES_AES128_KEY_SIZE_IN_WORDS;

    /* SREQI_KDF_1 - DI records for clearing of kdkKeyBuffer */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, kdkKeyBuffer);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, MCUXCLAES_AES128_KEY_SIZE_IN_WORDS);

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_Handle_t, kdkKey, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    usedCpuWaWords += MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS;

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("kdkKey has the correct type.")
    mcuxClKey_Status_t resultKeyInit2 = mcuxClKey_init(
        /* mcuxClSession_Handle_t session         */ pSession,
        /* mcuxClKey_Handle_t key                 */ kdkKey,
        /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Aes128,
        /* uint8_t * pKeyData                    */ (uint8_t *)kdkKeyBuffer,
        /* uint32_t keyDataLength                */ MCUXCLAES_AES128_KEY_SIZE);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()

    if(MCUXCLKEY_STATUS_OK != resultKeyInit2)
    {
        mcuxClSession_freeWords_cpuWa(pSession, usedCpuWaWords);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    /**********************************/
    /*         MAC Computation        */
    /**********************************/
    uint32_t macSize = 0u;
    MCUXCLBUFFER_INIT_RO(pDataBuf, pSession, pData, derivationKeySize);

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pData);

    MCUXCLBUFFER_INIT(pTempKdkKeyBuf, pSession, (uint8_t*)kdkKeyBuffer, MCUXCLAES_AES128_KEY_SIZE);
    mcuxClMac_Status_t mc_status = mcuxClMac_compute(
        /* mcuxClSession_Handle_t session:  */ pSession,
        /* const mcuxClKey_Handle_t key:    */ cmacKey,
        /* const mcuxClMac_Mode_t mode:     */ mcuxClMac_Mode_CMAC,
        /* mcuxCl_InputBuffer_t pIn:        */ pDataBuf,
        /* uint32_t inLength:              */ derivationKeySize,
        /* mcuxCl_Buffer_t pMac:            */ pTempKdkKeyBuf,
        /* uint32_t * const pMacLength:    */ &macSize);

    if(MCUXCLMAC_STATUS_OK != mc_status)
    {
        mcuxClSession_freeWords_cpuWa(pSession, usedCpuWaWords);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, mc_status);
    }

    if(MCUXCLAES_AES128_KEY_SIZE != macSize)
    {
        mcuxClSession_freeWords_cpuWa(pSession, usedCpuWaWords);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivationKeySize);

    /***************************/
    /*  SP800-108 calculation  */
    /***************************/
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_DerivationMode_t*, pDerivationMode, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    usedCpuWaWords += MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS;

    mcuxClKey_Status_t constructKeyDerivationModeStatus = mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108(
        /* mcuxClKey_DerivationMode_t *                      */ pDerivationMode,
        /* const mcuxClKey_DerivationAlgorithmDescriptor_t * */ mcuxClKey_DerivationAlgorithm_NIST_SP800_108,
        /* mcuxClMac_Mode_t                                  */ mcuxClMac_Mode_CMAC,
        /* uint32_t                                         */
        MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_32
        | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER);

    if (MCUXCLKEY_STATUS_OK != constructKeyDerivationModeStatus)
    {
        mcuxClSession_freeWords_cpuWa(pSession, usedCpuWaWords);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    struct mcuxClKey_DerivationInput emptyInput = {.input=NULL, .size= 0u};
    mcuxClKey_DerivationInput_t sp800108inputs[3] = {inputs[TWOSTEP_INPUT_LABEL_INDEX], inputs[TWOSTEP_INPUT_CONTEXT_INDEX], emptyInput};

    /* Call key derivation engine directly to avoid Misra 17.2 violation. */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_derivationEngine_NIST_SP800_108(
        /* mcuxClSession_Handle_t pSession         */ pSession,
        /* mcuxClKey_Derivation_t derivationMode   */ pDerivationMode,
        /* mcuxClKey_Handle_t derivationKey        */ kdkKey,
        /* mcuxClKey_DerivationInput_t inputs[]    */ sp800108inputs,
        /* uint32_t numberOfInputs                */ 2u,
        /* mcuxClKey_Handle_t derivedKey           */ derivedKey));

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_LABEL_INDEX].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_LABEL_INDEX].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_CONTEXT_INDEX].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_CONTEXT_INDEX].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKey);

    /*************/
    /*  Cleanup  */
    /*************/

    /* SREQI_KDF_1 - Clear kdkKeyBuffer after usage */
    MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
    MCUXCLMEMORY_CLEAR_SECURE_INT((uint8_t*)kdkKeyBuffer, MCUXCLAES_AES128_KEY_SIZE_IN_WORDS);

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_SALT_INDEX].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_SALT_INDEX].input);

    /* free CPU WA */
    mcuxClSession_freeWords_cpuWa(pSession, usedCpuWaWords);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief NIST SP800-56C TwoStep implementation using an HMAC algorithm.
 *
 * Data Integrity: Expunge(inputs[0].size, inputs[0].input, inputs[1].size, inputs[1].input, inputs[2].size, inputs[2].input, derivationKeySize, pData)
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    uint8_t *pData,
    uint32_t derivationKeySize,
    mcuxClKey_Handle_t derivedKey,
    mcuxClKey_Derivation_t derivationMode
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac);

    if((NULL == derivationMode->macMode) || (NULL == derivationMode->macMode->pCustom))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }
    /***************************/
    /* Prepare HMAC key handle */
    /***************************/

    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = ((mcuxClHmac_ModeDescriptor_t *) (derivationMode->macMode->pCustom))->hashAlgorithm;
    const uint32_t hashSize = hashAlgo->hashSize;

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_Handle_t, hmacKey, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* Initialize Hmac key for step 1.
        * If there is no salt given (inputs[TWOSTEP_INPUT_SALT_INDEX].size = 0), HMAC will create a zero key of block length, as required by SP800-56C.
        */

    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, intermediateArray, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS));

    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, inputs[TWOSTEP_INPUT_SALT_INDEX].input);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, intermediateArray);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, inputs[TWOSTEP_INPUT_SALT_INDEX].size);
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(
    inputs[TWOSTEP_INPUT_SALT_INDEX].input, 0u, intermediateArray, inputs[TWOSTEP_INPUT_SALT_INDEX].size));

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("hmacKey has the correct type.")
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init));
    MCUX_CSSL_FP_FUNCTION_CALL(resultKeyInit1, mcuxClKey_init(
    /* mcuxClSession_Handle_t session         */ pSession,
    /* mcuxClKey_Handle_t key                 */ hmacKey,
    /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Hmac_variableLength,
    /* uint8_t * pKeyData                    */ (const uint8_t *)intermediateArray,
    /* uint32_t keyDataLength                */ inputs[TWOSTEP_INPUT_SALT_INDEX].size));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    if (MCUXCLKEY_STATUS_OK != resultKeyInit1)
    {
        /* free HMAC key */
        mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                                + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_SALT_INDEX].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_SALT_INDEX].input);

    /***************************/
    /*  Prepare Kdk key handle */
    /***************************/
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, kdkKeyBuffer, mcuxClSession_allocateWords_cpuWa(pSession, hashSize / sizeof(uint32_t)));

    /* SREQI_KDF_1 - DI records for clearing of kdkKeyBuffer */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, kdkKeyBuffer);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, hashSize);

    /**********************************/
    /*         MAC Computation        */
    /**********************************/
    uint32_t macSize = 0u;
    MCUXCLBUFFER_INIT_RO(pDataBuf, pSession, pData, derivationKeySize);

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pData);

    MCUXCLBUFFER_INIT(pTempKdkKeyBuf, pSession, (uint8_t*)kdkKeyBuffer, hashSize);
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute));
    MCUX_CSSL_FP_FUNCTION_CALL(mc_status, mcuxClMac_compute(
        /* mcuxClSession_Handle_t session:  */ pSession,
        /* const mcuxClKey_Handle_t key:    */ hmacKey,
        /* const mcuxClMac_Mode_t mode:     */ derivationMode->macMode,
        /* mcuxCl_InputBuffer_t pIn:        */ pDataBuf,
        /* uint32_t inLength:              */ derivationKeySize,
        /* mcuxCl_Buffer_t pMac:            */ pTempKdkKeyBuf,
        /* uint32_t * const pMacLength:    */ &macSize));

    if(MCUXCLMAC_STATUS_OK != mc_status)
    {
        /* free HMAC key, kdkKeyBuffer */
        mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                                + hashSize / sizeof(uint32_t)
                                                + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, mc_status);
    }

    if(hashSize != macSize)
    {
        /* free HMAC key, kdkKeyBuffer */
        mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                                + hashSize / sizeof(uint32_t)
                                                + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivationKeySize);

    /***************************/
    /*  SP800-108 calculation  */
    /***************************/
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_Handle_t, kdkKey, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* Initialize kdkKey for step 2. */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init));
    MCUX_CSSL_FP_FUNCTION_CALL(resultKeyInit2, mcuxClKey_init(
    /* mcuxClSession_Handle_t session         */ pSession,
    /* mcuxClKey_Handle_t key                 */ kdkKey,
    /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Hmac_variableLength,
    /* uint8_t * pKeyData                    */ (const uint8_t *)MCUXCLBUFFER_GET(pTempKdkKeyBuf),
    /* uint32_t keyDataLength                */ hashSize));
    if (MCUXCLKEY_STATUS_OK != resultKeyInit2)
    {
        /* free HMAC key, kdkKeyBuffer, kdkKey */
        mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                                + hashSize / sizeof(uint32_t)
                                                + MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                                + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_DerivationMode_t*, pDerivationMode, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108));
    MCUX_CSSL_FP_FUNCTION_CALL(constructKeyDerivationModeStatus, mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108(
        /* mcuxClKey_DerivationMode_t *                      */ pDerivationMode,
        /* const mcuxClKey_DerivationAlgorithmDescriptor_t * */ mcuxClKey_DerivationAlgorithm_NIST_SP800_108,
        /* mcuxClMac_Mode_t                                  */ derivationMode->macMode,
        /* uint32_t                                         */
        MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_32
        | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER));

    if (MCUXCLKEY_STATUS_OK != constructKeyDerivationModeStatus)
    {
        /* free HMAC key, kdkKeyBuffer, kdkKey and mode descriptor */
        mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                                + hashSize / sizeof(uint32_t)
                                                + MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                                + MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS
                                                + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    struct mcuxClKey_DerivationInput emptyInput = {.input=NULL, .size= 0u};
    mcuxClKey_DerivationInput_t sp800108inputs[3] = {inputs[TWOSTEP_INPUT_LABEL_INDEX], inputs[TWOSTEP_INPUT_CONTEXT_INDEX], emptyInput};
    /* Call key derivation engine directly to avoid Misra 17.2 violation. */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_derivationEngine_NIST_SP800_108(
        /* mcuxClSession_Handle_t pSession         */ pSession,
        /* mcuxClKey_Derivation_t derivationMode   */ pDerivationMode,
        /* mcuxClKey_Handle_t derivationKey        */ kdkKey,
        /* mcuxClKey_DerivationInput_t inputs[]    */ sp800108inputs,
        /* uint32_t numberOfInputs                */ 2u,
        /* mcuxClKey_Handle_t derivedKey           */ derivedKey));

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_LABEL_INDEX].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_LABEL_INDEX].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_CONTEXT_INDEX].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[TWOSTEP_INPUT_CONTEXT_INDEX].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKey);

    /*************/
    /*  Cleanup  */
    /*************/

    /* SREQI_KDF_1 - Clear kdkKeyBuffer after usage */
    MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
    MCUXCLMEMORY_CLEAR_SECURE_INT((uint8_t*)kdkKeyBuffer, hashSize);

    /* free HMAC key, kdkKeyBuffer, kdkKey and mode descriptor */
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                            + hashSize / sizeof(uint32_t)
                                            + MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                            + MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS
                                            + MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep, mcuxClKey_DerivationEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep);

    uint32_t derivedKeySize = mcuxClKey_getSize(derivedKey);
    uint32_t derivationKeySize = mcuxClKey_getSize(derivationKey);

    uint8_t *pData = NULL;
    MCUXCLKEY_LOAD_FP(pSession, derivationKey, &pData, NULL, MCUXCLKEY_ENCODING_SPEC_ACTION_PTR);

    /* DI unbalancing to protect input parameters, balanced individually after last usage. */
    MCUX_CSSL_DI_RECORD(kdfParameters, derivedKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, pData);
    MCUX_CSSL_DI_RECORD(kdfParameters, derivationKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, derivedKey);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[TWOSTEP_INPUT_LABEL_INDEX].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[TWOSTEP_INPUT_LABEL_INDEX].input);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[TWOSTEP_INPUT_CONTEXT_INDEX].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[TWOSTEP_INPUT_CONTEXT_INDEX].input);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[TWOSTEP_INPUT_SALT_INDEX].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[TWOSTEP_INPUT_SALT_INDEX].input);

    /* 3 inputs are required (even if salt is zero to indicate its lenght), (IV is optional) */
    if((3u != numberOfInputs) && (4u != numberOfInputs))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be 0 or larger than the available buffer space. */
    if((0u == derivedKeySize) || (derivedKeySize > derivedKey->container.length))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKeySize);

    /* MAC mode OR hash function is provided */
    if((NULL == derivationMode->macMode) == (NULL == derivationMode->hashFunction))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    if(mcuxClMac_Mode_CMAC == derivationMode->macMode)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(twoStepCmacRes, mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac(
        pSession,
        inputs,
        pData,
        derivationKeySize,
        derivedKey));
        if(MCUXCLKEY_STATUS_OK != twoStepCmacRes)
        {
            MCUXCLSESSION_ERROR(pSession, twoStepCmacRes);
        }
    }
    else /* HMAC case */
    {
        MCUX_CSSL_FP_FUNCTION_CALL(twoStepHmacRes, mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac(
        pSession,
        inputs,
        pData,
        derivationKeySize,
        derivedKey,
        derivationMode));
        if(MCUXCLKEY_STATUS_OK != twoStepHmacRes)
        {
            MCUXCLSESSION_ERROR(pSession, twoStepHmacRes);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(
      mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep,
      MCUXCLKEY_LOAD_FP_CALLED(derivationKey),
      MCUX_CSSL_FP_CONDITIONAL(
        (mcuxClMac_Mode_CMAC == derivationMode->macMode),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac)
      ),
      MCUX_CSSL_FP_CONDITIONAL(
        (mcuxClMac_Mode_CMAC != derivationMode->macMode),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac)
      )
    );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_NIST_SP800_56C_OneStep = {
    .pDerivationEngine = mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep,
    .protectionTokenDerivationEngine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep)
};

const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_NIST_SP800_56C_TwoStep = {
    .pDerivationEngine = mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep,
    .protectionTokenDerivationEngine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep)
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
