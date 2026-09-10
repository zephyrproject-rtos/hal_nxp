/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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

/** @file  mcuxClKey_Derivation_NIST_SP800_56C.c
 *  @brief Implementation of SP800-56C Key Derivation */

#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClKey_Derivation_Helper.h>

#include <mcuxClMac.h>
#include <mcuxClMacModes.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClHmac.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMac_Internal_Constants.h>
#include <internal/mcuxClMac_Internal_Functions.h>
#include <internal/mcuxClHash_Internal.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <mcuxClCore_FunctionIdentifiers.h> // Code flow protection
#include <mcuxCsslAnalysis.h>
#include <mcuxClKey_DerivationAlgorithms_NIST_SP800_56C.h>
#include <internal/mcuxClKey_DerivationAlgorithms_NIST_SP800_108_Internal.h>
#include <mcuxClKey_DerivationAlgorithms_NIST_SP800_108.h>
#include <mcuxClEls.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClKey_DerivationMode_t * pDerivationMode,
  const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
  mcuxClMac_Mode_t macMode,
  mcuxClHash_Algo_t hashFunction,
  uint32_t options UNUSED_PARAM)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C);

    pDerivationMode->derivationAlgorithm = derivationAlgorithm;
    pDerivationMode->macMode = macMode;
    pDerivationMode->hashFunction = hashFunction;
    pDerivationMode->options = 0U; // no options for this mode

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_56C, MCUXCLKEY_STATUS_OK);
}

#define COUNTER_BYTE_LEN       (sizeof(uint32_t))


/**
 * @brief Input validation for NIST SP800-56C Counter Mode function
 *
 * @param[in]     derivationMode    Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     inputs            The first entry points to the fixedInfo parameter; the second to the optional salt, if given.
 * @param[in]     numberOfInputs    Should be 2 if salt is passed, 1 if fixedInfo is passed but not salt, and 0 if neither is passed.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput(
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput);
    /* Both inputs are optional, but must at least be given as NULL pointer with size 0 */
    if(2U != numberOfInputs)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    if(((inputs[0].size != 0U) && MCUXCLBUFFER_IS_NULL(inputs[0].input)) ||
       ((inputs[1].size != 0U) && MCUXCLBUFFER_IS_NULL(inputs[1].input)))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be 0 or larger than the available buffer space. */
    if((0U == derivedKey->type.size) || (derivedKey->type.size > derivedKey->container.length))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput, MCUXCLKEY_STATUS_ERROR);
    }

    /* Either macMode or hashFunction shall be given, not both, not none. */
    if(((NULL == derivationMode->macMode) && (NULL == derivationMode->hashFunction)) ||
       ((NULL != derivationMode->macMode) && (NULL != derivationMode->hashFunction)))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput, MCUXCLKEY_STATUS_INVALID_INPUT);
    }
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief Key derivation function for NIST SP800-56C OneStep Counter Mode engine with hash derivation mode.
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Hash derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     inputs            The first entry points to the fixedInfo parameter; the second to the optional salt, if given.
 * @param[in]     numberOfInputs    Should be 2 if salt is passed, 1 if fixedInfo is passed but not salt, and 0 if neither is passed.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash);
    /* Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
        - The number of operations depends on the requested size of the derived output key,
        and on the output size of the chosen hash function.
        - The outputBytesLastIteration will be < hashSize if the requested key's size is
        not a multiple of the hash function output size (1 <= outputBytesLastIteration <= hashSize).
    */

    /* As derivedKey->type.size is an uint32_t, nOfIterations cannot overflow. This also guarantees "n <= 2^32-1" as required by the specification. */
    uint32_t nOfIterations = derivedKey->type.size / derivationMode->hashFunction->hashSize;
    uint32_t outputBytesLastIteration = derivedKey->type.size % derivationMode->hashFunction->hashSize;
    MCUX_CSSL_FP_LOOP_DECL(loop);

    if(outputBytesLastIteration != 0U)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("nOfIterations cannot be equal to UINT32_MAX, as derivationMode->hashFunction->hashSize is always bigger than 1.")
        nOfIterations++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full hash output size */
        outputBytesLastIteration = derivationMode->hashFunction->hashSize;
    }

    /* Allocate space for the hash context. */
    mcuxClHash_ContextDescriptor_t * const pContext = mcuxClHash_castToHashContextDescriptor(
                                                       mcuxClSession_allocateWords_cpuWa(pSession, mcuxClHash_getContextWordSize(derivationMode->hashFunction))
                                                     );
    if(NULL == pContext)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_ERROR);
    }

    /* Allocate space for the hash digest. */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    uint8_t *pTempOut= (uint8_t *)mcuxClSession_allocateWords_cpuWa(pSession, derivationMode->hashFunction->hashSize / sizeof(uint32_t));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
    if(NULL == pTempOut)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_ERROR);
    }
    MCUXCLBUFFER_INIT(pTempOutBuf, pSession, pTempOut, derivationMode->hashFunction->hashSize);

    uint32_t outSize = 0U;
    uint8_t *pOutputKey = derivedKey->container.pData;
    MCUXCLBUFFER_INIT(pOutputKeyBuf, pSession, pOutputKey, derivedKey->type.size);

    for(uint32_t counter = 1U; counter <= nOfIterations; counter++)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(init_result, mcuxClHash_init(
                pSession,
                pContext,
                derivationMode->hashFunction
        ));

        if(MCUXCLHASH_STATUS_OK != init_result)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Initialize auxiliary space for it's big-endian representation. */
        uint32_t counterBigEndian = 0x0U;
        uint8_t * pCounterBigEndian = (uint8_t *)&counterBigEndian;

        /* Convert the counter to big-endian. */
        mcuxClMemory_StoreBigEndian32(pCounterBigEndian, counter);

        /* Process the counter. */
        MCUXCLBUFFER_INIT_RO(pCounterBigEndianBuf, pSession, pCounterBigEndian, COUNTER_BYTE_LEN);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called between any mcuxClHash_finish and mcuxClHash_process calls, so the integrity of pContext is ensured.")
        MCUX_CSSL_FP_FUNCTION_CALL(process_result1, mcuxClHash_process(
                pSession,
                pContext,
                pCounterBigEndianBuf,
                COUNTER_BYTE_LEN
        ));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if(MCUXCLHASH_STATUS_OK != process_result1)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Process the message Z. */
        uint8_t* pMessageZ = derivationKey->container.pData;
        MCUXCLBUFFER_INIT_RO(pMessageZBuf, pSession, pMessageZ, derivationKey->type.size);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called between any mcuxClHash_finish and mcuxClHash_process calls, so the integrity of pContext is ensured.")
        MCUX_CSSL_FP_FUNCTION_CALL(process_result2, mcuxClHash_process(
                pSession,
                pContext,
                pMessageZBuf,
                derivationKey->type.size
        ));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if(MCUXCLHASH_STATUS_OK != process_result2)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Process the fixedInfo. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called between any mcuxClHash_finish and mcuxClHash_process calls, so the integrity of pContext is ensured.")
        MCUX_CSSL_FP_FUNCTION_CALL(process_result3, mcuxClHash_process(
                pSession,
                pContext,
                inputs[0].input,
                inputs[0].size
        ));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if(MCUXCLHASH_STATUS_OK != process_result3)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        if (counter != nOfIterations)
        {
            /* Create the digest. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called before and between any mcuxClHash_finish calls, so the integrity of pContext is ensured.")
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClHash_finish(
                    pSession,
                    pContext,
                    pOutputKeyBuf,
                    &outSize
            ));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if(MCUXCLHASH_STATUS_OK != finish_result)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

            /* Balance the security counter */
            MCUX_CSSL_FP_LOOP_ITERATION(loop,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish));
        }
        else
        {
            /* Create the digest. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("mcuxClHash_init is called before and between any mcuxClHash_finish calls, so the integrity of pContext is ensured.")
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClHash_finish(
                    pSession,
                    pContext,
                    pTempOutBuf,
                    &outSize
            ));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if(MCUXCLHASH_STATUS_OK != finish_result)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

            MCUX_CSSL_FP_FUNCTION_CALL(write_result, mcuxClBuffer_write(pOutputKeyBuf, 0U, (uint8_t *) MCUXCLBUFFER_GET(pTempOutBuf), outputBytesLastIteration));
            if(MCUXCLBUFFER_STATUS_OK != write_result)
            {
                /* clean-up the CPU work-area: pTempOut and pContext */
                MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot overflow.")
                mcuxClSession_freeWords_cpuWa(pSession, (derivationMode->hashFunction->hashSize / sizeof(uint32_t)) + mcuxClHash_getContextWordSize(derivationMode->hashFunction));
                MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, write_result);
            }
            MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *) MCUXCLBUFFER_GET(pTempOutBuf), derivationMode->hashFunction->hashSize);

            /* Balance the security counter */
            MCUX_CSSL_FP_LOOP_ITERATION(loop,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
        }

        MCUXCLBUFFER_UPDATE(pOutputKeyBuf, derivationMode->hashFunction->hashSize);
        outSize = 0U;
    }

    /* clean-up the CPU work-area: pTempOut and pContext */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context and workarea size calculations cannot overflow.")
    mcuxClSession_freeWords_cpuWa(pSession, (derivationMode->hashFunction->hashSize / sizeof(uint32_t)) + mcuxClHash_getContextWordSize(derivationMode->hashFunction));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash, MCUXCLKEY_STATUS_OK,
       MCUX_CSSL_FP_LOOP_ITERATIONS(loop, nOfIterations));
}


/**
 * @brief Key derivation function for NIST SP800-56C OneStep Counter Mode engine with mac derivation mode.
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Mac derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     inputs            The first entry points to the fixedInfo parameter; the second to the optional salt, if given.
 * @param[in]     numberOfInputs    Should be 2 if salt is passed, 1 if fixedInfo is passed but not salt, and 0 if neither is passed.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac);
    /* Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
        - The number of operations depends on the requested size of the derived output key,
        and on the output size of the chosen MAC function.
        - The outputBytesLastIteration will be < macByteSize if the requested key's size is
        not a multiple of the MAC function output size (1 <= outputBytesLastIteration <= macByteSize).
    */

    /* As derivedKey->type.size is an uint32_t, nOfIterations cannot overflow. This also guarantees "n <= 2^32-1" as required by the specification. */
    uint32_t nOfIterations = derivedKey->type.size / derivationMode->macMode->common.macByteSize;
    uint32_t outputBytesLastIteration = derivedKey->type.size % derivationMode->macMode->common.macByteSize;
    MCUX_CSSL_FP_LOOP_DECL(loop);

    if(outputBytesLastIteration != 0U)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("nOfIterations cannot be equal to UINT32_MAX, as derivationMode->macMode->common.macByteSize is always bigger than 1.")
        nOfIterations++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full MAC output block */
        outputBytesLastIteration = derivationMode->macMode->common.macByteSize;
    }

    /* Allocate space for the MAC context. */
    mcuxClKeyDerivation_WorkArea_t *pWa = mcuxClKey_castToKeyDerivationWorkarea(
                                        mcuxClSession_allocateWords_cpuWa(pSession, sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t))
                                      );
    if(NULL == pWa)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_ERROR);
    }

    /* Allocate space for the Hmac key handle */
    mcuxClKey_Handle_t hmacKeyHandle = mcuxClKey_castToKeyHandle(
                                        mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS)
                                      );
    if(NULL == hmacKeyHandle)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_ERROR);
    }

    /* Initialize mock hmacKey. Only initialize fields that are needed by SW-HMAC.
        * Use the salt as HMAC key. If there is no salt given (inputs[1].size = 0),
        * HMAC will create a zero key of block length, as required by SP800-56C.
        */
    hmacKeyHandle->type.size = inputs[1].size;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to create a mock key")
    hmacKeyHandle->location.pData = (uint8_t *)MCUXCLBUFFER_GET(inputs[1].input);
    hmacKeyHandle->container.pData = (uint8_t *)MCUXCLBUFFER_GET(inputs[1].input);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()

    uint32_t outSize = 0U;
    uint8_t *pOutputKey = derivedKey->container.pData;
    MCUXCLBUFFER_INIT(pOutputKeyBuf, pSession, pOutputKey, derivedKey->type.size);
    uint8_t *pMacResult = pWa->macResult_Wa;
    MCUXCLBUFFER_INIT(pMacResultBuf, pSession, pMacResult, derivationMode->macMode->common.macByteSize);
    mcuxClMac_Context_t * const pContext = mcuxClMac_castToMacContext(pWa->context_Wa);
    for(uint32_t counter = 1U; counter <= nOfIterations; counter++)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pContext is initialized by mcuxClMac_init")
        MCUX_CSSL_FP_FUNCTION_CALL(init_result, mcuxClMac_init(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
            pSession,
            pContext,
            hmacKeyHandle,
            derivationMode->macMode));

        if(MCUXCLMAC_STATUS_OK != init_result)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Initialize auxiliary space for it's big-endian representation. */
        uint32_t counterBigEndian = 0x0U;
        uint8_t * pCounterBigEndian = (uint8_t *)&counterBigEndian;

        /* Convert the counter to big-endian. */
        mcuxClMemory_StoreBigEndian32(pCounterBigEndian, counter);

        /* Process the counter. */
        MCUXCLBUFFER_INIT_RO(pCounterBigEndianBuf, pSession, pCounterBigEndian, COUNTER_BYTE_LEN);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(process_result1, mcuxClMac_process(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
                pSession,
                pContext,
                pCounterBigEndianBuf,
                COUNTER_BYTE_LEN
        ));

        if(MCUXCLMAC_STATUS_OK != process_result1)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Process the message Z. */
        uint8_t* pMessageZ = derivationKey->container.pData;
        MCUXCLBUFFER_INIT_RO(pMessageZBuf, pSession, pMessageZ, derivationKey->type.size);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(process_result2, mcuxClMac_process(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
                pSession,
                pContext,
                pMessageZBuf,
                derivationKey->type.size
        ));

        if(MCUXCLMAC_STATUS_OK != process_result2)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Process the fixedInfo. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(process_result3, mcuxClMac_process(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
                pSession,
                pContext,
                inputs[0].input,
                inputs[0].size
        ));

        if(MCUXCLMAC_STATUS_OK != process_result3)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        if (counter != nOfIterations)
        {
            /* Create the digest. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClMac_finish(
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
                    pSession,
                    pContext,
                    pOutputKeyBuf,
                    &outSize
            ));

            if(MCUXCLMAC_STATUS_OK != finish_result)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

            /* Balance the security counter */
            MCUX_CSSL_FP_LOOP_ITERATION(loop,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
        }
        else
        {
            /* Create the digest. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
            MCUX_CSSL_FP_FUNCTION_CALL(finish_result, mcuxClMac_finish(
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
                    pSession,
                    pContext,
                    pMacResultBuf,
                    &outSize
            ));

            if(MCUXCLMAC_STATUS_OK != finish_result)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

            MCUX_CSSL_FP_FUNCTION_CALL(write_result, mcuxClBuffer_write(pOutputKeyBuf, 0U, (uint8_t *) MCUXCLBUFFER_GET(pMacResultBuf), outputBytesLastIteration));
            if(MCUXCLBUFFER_STATUS_OK != write_result)
            {
                /* free hmacKeyHandle and pWa */
                mcuxClSession_freeWords_cpuWa(pSession, (sizeof(mcuxClKey_Descriptor_t) / sizeof(uint32_t)) + (sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t)));
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, write_result);
            }
            MCUX_CSSL_ANALYSIS_START_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()
            MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *) MCUXCLBUFFER_GET(pMacResultBuf), MCUXCLMAC_MAX_OUTPUT_SIZE);
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()

            /* Balance the security counter */
            MCUX_CSSL_FP_LOOP_ITERATION(loop,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
        }

        MCUXCLBUFFER_UPDATE(pOutputKeyBuf, derivationMode->macMode->common.macByteSize);
        outSize = 0U;
    }

    /* free hmacKeyHandle and pWa */
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS + sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac, MCUXCLKEY_STATUS_OK,
       MCUX_CSSL_FP_LOOP_ITERATIONS(loop, nOfIterations));
}

/**
 * @brief Key derivation engine function for NIST SP800-56C OneStep Counter Mode.
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     inputs            The first entry points to the fixedInfo parameter; the second to the optional salt, if given.
 * @param[in]     numberOfInputs    Should be 2 if salt is passed, 1 if fixedInfo is passed but not salt, and 0 if neither is passed.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep, mcuxClKey_DerivationEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = fixedInfo, inputs[1] = salt
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep);

    /* Input validation */
    MCUX_CSSL_FP_FUNCTION_CALL(oneStepValidateInput_result, mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput(
        derivationMode,
        inputs, // inputs[0] = fixedInfo, inputs[1] = salt
        numberOfInputs,
        derivedKey));

    if(MCUXCLKEY_STATUS_OK != oneStepValidateInput_result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep, oneStepValidateInput_result,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput));
    }

    /* hashFunction case */
    if(NULL != derivationMode->hashFunction)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(oneStepHash_result, mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash(
            pSession,
            derivationMode,
            derivationKey,
            inputs, // inputs[0] = fixedInfo, inputs[1] = salt
            numberOfInputs,
            derivedKey));

        if(MCUXCLKEY_STATUS_OK != oneStepHash_result)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep, oneStepHash_result);
        }
    }
    /* macMode case */
    else /* (NULL != derivationMode->macMode) */
    {
        MCUX_CSSL_FP_FUNCTION_CALL(oneStepMac_result, mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac(
            pSession,
            derivationMode,
            derivationKey,
            inputs, // inputs[0] = fixedInfo, inputs[1] = salt
            numberOfInputs,
            derivedKey));

        if(MCUXCLKEY_STATUS_OK != oneStepMac_result)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep, oneStepMac_result);
        }
    }

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep, MCUXCLKEY_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_ValidateInput),
        MCUX_CSSL_FP_CONDITIONAL(NULL != derivationMode->hashFunction, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Hash)),
        MCUX_CSSL_FP_CONDITIONAL(NULL != derivationMode->macMode, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_OneStep_Mac))
    );
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
}

#define TWOSTEP_INPUT_LABEL_INDEX      (0) // inputs[0]
#define TWOSTEP_INPUT_CONTEXT_INDEX    (1) // inputs[1]
#define TWOSTEP_INPUT_SALT_INDEX       (2) // inputs[2]


/**
 * @brief Key derivation CMAC core function for for SP800 56C TwoStep CMAC key derivation mode function.
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Cmac derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     cmacKey           Cmac key.
 * @param[in]     inputs            The first entry points to the Label parameter, second to the Context,
 *                                  third to salt, fourth to optional IV.
 * @param[in]     numberOfInputs    Number of inputs. Should be 4 if IV is provided, 3 with no IV.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_Handle_t cmacKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core);
    /***************************/
    /*  Prepare Kdk key handle */
    /***************************/
    uint32_t *kdkKeyBuffer = mcuxClSession_allocateWords_cpuWa(pSession,  MCUXCLAES_AES128_KEY_SIZE_IN_WORDS);
    if(NULL == kdkKeyBuffer)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    mcuxClKey_Handle_t kdkKey = mcuxClKey_castToKeyHandle(
                                mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS)
                              );
    if(NULL == kdkKey)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(resultKeyInit2, mcuxClKey_init(
    /* mcuxClSession_Handle_t session         */ pSession,
    /* mcuxClKey_Handle_t key                 */ kdkKey,
    /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Aes128,
    /* uint8_t * pKeyData                    */ (uint8_t *) kdkKeyBuffer,
    /* uint32_t keyDataLength                */ MCUXCLAES_AES128_KEY_SIZE
    ));

    if(MCUXCLKEY_STATUS_OK != resultKeyInit2)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    /**********************************/
    /*         MAC Computation        */
    /**********************************/
    uint32_t macSize = 0U;
    uint8_t* pData = derivationKey->container.pData;
    MCUXCLBUFFER_INIT_RO(pDataBuf, pSession, pData, derivationKey->type.size);
    MCUXCLBUFFER_INIT(pOutBuf, pSession, (uint8_t*)kdkKeyBuffer, MCUXCLAES_AES128_KEY_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL(mc_status, mcuxClMac_compute(
        /* mcuxClSession_Handle_t session:  */ pSession,
        /* const mcuxClKey_Handle_t key:    */ cmacKey,
        /* const mcuxClMac_Mode_t mode:     */ mcuxClMac_Mode_CMAC,
        /* mcuxCl_InputBuffer_t pIn:        */ pDataBuf,
        /* uint32_t inLength:              */ derivationKey->type.size,
        /* mcuxCl_Buffer_t pMac:            */ pOutBuf,
        /* uint32_t * const pMacLength:    */ &macSize)
    );

    if((MCUXCLMAC_STATUS_OK != mc_status) || (MCUXCLAES_AES128_KEY_SIZE != macSize))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    uint32_t *kdkKeyBuffer2 = mcuxClSession_allocateWords_cpuWa(pSession,  MCUXCLAES_AES128_KEY_SIZE_IN_WORDS);
    if(NULL == kdkKeyBuffer2)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    /* load key into destination memory buffer */
    MCUX_CSSL_FP_FUNCTION_CALL(resultLoadMem2, mcuxClKey_loadMemory(
                                /* mcuxClSession_Handle_t pSession:   */ pSession,
                                /* mcuxClKey_Handle_t key:            */ kdkKey,
                                /* uint32_t * dstData:               */ kdkKeyBuffer2));
    if(MCUXCLKEY_STATUS_OK != resultLoadMem2)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    /***************************/
    /*  SP800-108 calculation  */
    /***************************/
    mcuxClKey_DerivationMode_t * pDerivationMode = mcuxClKey_castToKeyDerivationMode(
                                                    mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS)
                                                  );
    if(NULL == pDerivationMode)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(constructKeyDerivationModeStatus, mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108(
    /* mcuxClKey_DerivationMode_t *                      */ pDerivationMode,
    /* const mcuxClKey_DerivationAlgorithmDescriptor_t * */ mcuxClKey_DerivationAlgorithm_NIST_SP800_108,
    /* mcuxClMac_Mode_t                                  */ mcuxClMac_Mode_CMAC,
    /* uint32_t                                         */ MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_32
                                                            | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_ENABLED
                                                            | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER
    ));

    if (MCUXCLKEY_STATUS_OK != constructKeyDerivationModeStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

    mcuxClKey_DerivationInput_t sp800108inputs[2] = {inputs[TWOSTEP_INPUT_LABEL_INDEX], inputs[TWOSTEP_INPUT_CONTEXT_INDEX]};

    /* Call key derivation engine directly to avoid Misra 17.2 violation. */
    MCUX_CSSL_FP_FUNCTION_CALL(resultDeriv, mcuxClKey_derivationEngine_NIST_SP800_108(
    /* mcuxClSession_Handle_t pSession         */ pSession,
    /* mcuxClKey_Derivation_t derivationMode   */ pDerivationMode,
    /* mcuxClKey_Handle_t derivationKey        */ kdkKey,
    /* mcuxClKey_DerivationInput_t inputs[]    */ sp800108inputs,
    /* uint32_t numberOfInputs                */ 2U,
    /* mcuxClKey_Handle_t derivedKey           */ derivedKey
    ));

    if(MCUXCLKEY_STATUS_OK != resultDeriv)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_ERROR);
    }

        /* free variables */
    mcuxClSession_freeWords_cpuWa(pSession,  MCUXCLAES_AES128_KEY_SIZE_IN_WORDS                  /* kdkKeyBuffer  */
                                            + MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS                 /* kdkKey  */

                                            + MCUXCLAES_AES128_KEY_SIZE_IN_WORDS                  /* kdkKeyBuffer2 */
                                            + MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS); /* SP800-108 WA */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core, MCUXCLKEY_STATUS_OK,
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init),
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute),
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_loadMemory),
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108),
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108));
}

/**
 * @brief Key derivation function for for SP800 56C TwoStep derivation engine with Cmac derivation mode
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Cmac derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     inputs            The first entry points to the Label parameter, second to the Context,
 *                                  third to salt, fourth to optional IV.
 * @param[in]     numberOfInputs    Number of inputs. Should be 4 if IV is provided, 3 with no IV.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac);
    /***************************/
    /* Prepare CMAC key handle */
    /***************************/
    uint32_t cmacKeyLength = inputs[TWOSTEP_INPUT_SALT_INDEX].size;
    mcuxClKey_Type_t cmacKeyType = NULL;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKey_GetAesKeyType(cmacKeyLength, &cmacKeyType));
    if(NULL == cmacKeyType)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    const uint8_t *pCmacKey = (const uint8_t*)MCUXCLBUFFER_GET(inputs[TWOSTEP_INPUT_SALT_INDEX].input);
    bool saltPointerReceived = (NULL != pCmacKey);
    if(!saltPointerReceived)
    {
        /* Salt is strictly needed. If null-pointer is given, locate on cpuWa. */
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        uint8_t *pCmacKeyDefault = (uint8_t *)mcuxClSession_allocateWords_cpuWa(pSession,  cmacKeyLength / sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
        if(NULL == pCmacKeyDefault)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_ERROR);
        }
        MCUXCLMEMORY_FP_MEMORY_CLEAR(pCmacKeyDefault, cmacKeyLength);
        pCmacKey = pCmacKeyDefault;
    }

    mcuxClKey_Handle_t cmacKey = mcuxClKey_castToKeyHandle(
                                  mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS)
                                );
    if(NULL == cmacKey)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(resultKeyInit1, mcuxClKey_init(
    /* mcuxClSession_Handle_t session         */ pSession,
    /* mcuxClKey_Handle_t key                 */ cmacKey,
    /* mcuxClKey_Type_t type                  */ cmacKeyType,
    /* uint8_t * pKeyData                    */ pCmacKey,
    /* uint32_t keyDataLength                */ cmacKeyLength
    ));

    if(MCUXCLKEY_STATUS_OK != resultKeyInit1)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_ERROR);
    }

        /* Key buffer for the key in memory. */
    uint32_t *key_buffer = mcuxClSession_allocateWords_cpuWa(pSession, cmacKeyLength / sizeof(uint32_t));
    if(NULL == key_buffer)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_ERROR);
    }

    /* load key into destination memory buffer */
    MCUX_CSSL_FP_FUNCTION_CALL(resultLoadMem, mcuxClKey_loadMemory(
                                /* mcuxClSession_Handle_t pSession:   */ pSession,
                                /* mcuxClKey_Handle_t key:            */ cmacKey,
                                /* uint32_t * dstData:               */ key_buffer));
    if(MCUXCLKEY_STATUS_OK != resultLoadMem)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(resultCmacCore, mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core(
        pSession,
        derivationMode,
        derivationKey,
        cmacKey,
        inputs, // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
        numberOfInputs,
        derivedKey));

    if(MCUXCLKEY_STATUS_OK != resultCmacCore)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, resultCmacCore);
    }


    /*************/
    /*  Cleanup  */
    /*************/
    /* free CMAC key buffer */
    if(!saltPointerReceived)
    {
        mcuxClSession_freeWords_cpuWa(pSession,  cmacKeyLength / sizeof(uint32_t));
    }

    /* free variables */
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                            + cmacKeyLength / sizeof(uint32_t)                   /* key_buffer */
    );

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac, MCUXCLKEY_STATUS_OK,
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_GetAesKeyType),
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init),
                                        MCUX_CSSL_FP_CONDITIONAL(!saltPointerReceived,
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)),
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_loadMemory),
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac_Core));
}

/**
 * @brief Key derivation function for for SP800 56C TwoStep derivation engine with Hmac derivation mode
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Hmac derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     inputs            The first entry points to the Label parameter, second to the Context,
 *                                  third to salt, fourth to optional IV.
 * @param[in]     numberOfInputs    Number of inputs. Should be 4 if IV is provided, 3 with no IV.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
        MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac);

        if((NULL == derivationMode->macMode) || (NULL == derivationMode->macMode->pCustom))
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_INVALID_INPUT);
        }
        /***************************/
        /* Prepare HMAC key handle */
        /***************************/
        const uint32_t hashSize = ((mcuxClHmac_ModeDescriptor_t *) (derivationMode->macMode->pCustom))->hashAlgorithm->hashSize;

        mcuxClKey_Handle_t hmacKey = mcuxClKey_castToKeyHandle(
                                            mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS)
                                          );
        if(NULL == hmacKey)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_ERROR);
        }

        /* Initialize mockHmac key for step 1.  Only initialize fields that are needed by SW-HMAC.
         * If there is no salt given (inputs[TWOSTEP_INPUT_SALT_INDEX].size = 0), HMAC will create a zero key of block length, as required by SP800-56C.
         */
        hmacKey->type.size = inputs[TWOSTEP_INPUT_SALT_INDEX].size;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to create a mock key")
        hmacKey->location.pData = (uint8_t *) inputs[TWOSTEP_INPUT_SALT_INDEX].input;
        hmacKey->container.pData = (uint8_t *) inputs[TWOSTEP_INPUT_SALT_INDEX].input;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()

        /***************************/
        /*  Prepare Kdk key handle */
        /***************************/
        uint32_t *kdkKeyBuffer = mcuxClSession_allocateWords_cpuWa(pSession, hashSize / sizeof(uint32_t));
        if(NULL == kdkKeyBuffer)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_ERROR);
        }

        /**********************************/
        /*         MAC Computation        */
        /**********************************/
        uint32_t macSize = 0U;
        uint8_t* pData = derivationKey->container.pData;
        MCUXCLBUFFER_INIT_RO(pDataBuf, pSession, pData, derivationKey->type.size);
        MCUXCLBUFFER_INIT(pOutBuf, pSession, (uint8_t*)kdkKeyBuffer, hashSize);
        MCUX_CSSL_FP_FUNCTION_CALL(mc_status, mcuxClMac_compute(
            /* mcuxClSession_Handle_t session:  */ pSession,
            /* const mcuxClKey_Handle_t key:    */ hmacKey,
            /* const mcuxClMac_Mode_t mode:     */ derivationMode->macMode,
            /* mcuxCl_InputBuffer_t pIn:        */ pDataBuf,
            /* uint32_t inLength:              */ derivationKey->type.size,
            /* mcuxCl_Buffer_t pMac:            */ pOutBuf,
            /* uint32_t * const pMacLength:    */ &macSize)
        );

        if((MCUXCLMAC_STATUS_OK != mc_status) || (hashSize != macSize))
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_ERROR);
        }

        /***************************/
        /*  SP800-108 calculation  */
        /***************************/
        mcuxClKey_Handle_t kdkKey = mcuxClKey_castToKeyHandle(
                                     mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS)
                                   );
        if(NULL == kdkKey)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_ERROR);
        }

        /* Initialize mock hmacKey for step 2. Only initialize fields that are needed by SW-HMAC. */
        kdkKey->type.size = hashSize;
        kdkKey->location.pData = (uint8_t *) MCUXCLBUFFER_GET(pOutBuf);
        kdkKey->container.pData = (uint8_t *) MCUXCLBUFFER_GET(pOutBuf);

        mcuxClKey_DerivationMode_t * pDerivationMode = mcuxClKey_castToKeyDerivationMode(
                                                        mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS)
                                                      );
        if(NULL == pDerivationMode)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_ERROR);
        }

        MCUX_CSSL_FP_FUNCTION_CALL(constructKeyDerivationModeStatus, mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108(
        /* mcuxClKey_DerivationMode_t *                      */ pDerivationMode,
        /* const mcuxClKey_DerivationAlgorithmDescriptor_t * */ mcuxClKey_DerivationAlgorithm_NIST_SP800_108,
        /* mcuxClMac_Mode_t                                  */ derivationMode->macMode,
        /* uint32_t                                         */ MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_32
                                                               | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_ENABLED
                                                               | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER
        ));

        if (MCUXCLKEY_STATUS_OK != constructKeyDerivationModeStatus)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_ERROR);
        }

        mcuxClKey_DerivationInput_t sp800108inputs[2] = {inputs[TWOSTEP_INPUT_LABEL_INDEX], inputs[TWOSTEP_INPUT_CONTEXT_INDEX]};
        /* Call key derivation engine directly to avoid Misra 17.2 violation. */
        MCUX_CSSL_FP_FUNCTION_CALL(resultDeriv, mcuxClKey_derivationEngine_NIST_SP800_108(
        /* mcuxClSession_Handle_t pSession         */ pSession,
        /* mcuxClKey_Derivation_t derivationMode   */ pDerivationMode,
        /* mcuxClKey_Handle_t derivationKey        */ kdkKey,
        /* mcuxClKey_DerivationInput_t inputs[]    */ sp800108inputs,
        /* uint32_t numberOfInputs                */ 2U,
        /* mcuxClKey_Handle_t derivedKey           */ derivedKey
        ));

        if(MCUXCLKEY_STATUS_OK != resultDeriv)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_ERROR);
        }

        /*************/
        /*  Cleanup  */
        /*************/

        /* free HMAC key, kdkKeyBuffer, kdkKey and mode descriptor */
        mcuxClSession_freeWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                               + hashSize / sizeof(uint32_t)
                                               + MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS
                                               + MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac, MCUXCLKEY_STATUS_OK,
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_compute),
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108),
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108));
}


/**
 * @brief Key derivation engine for SP800 56C TwoStep derivation algorithm type
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Mac derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Input derivation key.
 * @param[in]     inputs            The first entry points to the Label parameter, second to the Context,
 *                                  third to salt, fourth to optional IV.
 * @param[in]     numberOfInputs    Number of inputs. Should be 4 if IV is provided, 3 with no IV.
 * @param[out]    derivedKey        Output key handle.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep, mcuxClKey_DerivationEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep);

    /* 3 inputs are required (even if salt is zero to indicate its lenght), (IV is optional) */
    if((3U != numberOfInputs) && (4U != numberOfInputs))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be 0 or larger than the available buffer space. */
    if((derivedKey->type.size == 0U) || (derivedKey->type.size > derivedKey->container.length))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep, MCUXCLKEY_STATUS_ERROR);
    }

    /* MAC mode OR hash function is provided */
    if((NULL == derivationMode->macMode) == (NULL == derivationMode->hashFunction))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    if(mcuxClMac_Mode_CMAC == derivationMode->macMode)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(resultTwoStepCmac, mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac(
            pSession,
            derivationMode,
            derivationKey,
            inputs, // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
            numberOfInputs,
            derivedKey));

        if(MCUXCLKEY_STATUS_OK != resultTwoStepCmac)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep, resultTwoStepCmac);
        }
    }
    else /* HMAC case */
    {
        MCUX_CSSL_FP_FUNCTION_CALL(resultTwoStepHmac, mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac(
            pSession,
            derivationMode,
            derivationKey,
            inputs, // inputs[0] = Label, inputs[1] = Context, inputs[2] = salt, {inputs[3] = IV}
            numberOfInputs,
            derivedKey));

        if(MCUXCLKEY_STATUS_OK != resultTwoStepHmac)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep, resultTwoStepHmac);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep,
                                            MCUXCLKEY_STATUS_OK,
                                            MCUX_CSSL_FP_CONDITIONAL((mcuxClMac_Mode_CMAC == derivationMode->macMode),
                                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Cmac)),
                                            MCUX_CSSL_FP_CONDITIONAL((mcuxClMac_Mode_CMAC != derivationMode->macMode),
                                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_56C_TwoStep_Hmac)));
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
