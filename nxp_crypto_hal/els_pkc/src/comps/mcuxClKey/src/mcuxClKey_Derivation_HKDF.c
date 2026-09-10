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

/** @file  mcuxClKey_Derivation_HKDF.c
 *  @brief Implementation of RFC5869 Key Derivation */

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
#include <internal/mcuxClHmac_Internal_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <mcuxClCore_FunctionIdentifiers.h> // Code flow protection
#include <mcuxCsslAnalysis.h>

#define MCUXCLKEY_DERIVATION_HKDF_MAX_OUTPUT_SIZE_FACTOR    255U  /* As defined by RFC5869 */

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_Derivation_ModeConstructor_HKDF)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_HKDF(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClKey_DerivationMode_t * pDerivationMode,
  const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
  mcuxClMac_Mode_t macMode,
  uint32_t options UNUSED_PARAM)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_Derivation_ModeConstructor_HKDF);

    pDerivationMode->derivationAlgorithm = derivationAlgorithm;
    pDerivationMode->macMode = macMode;
    pDerivationMode->options = 0U; // no options for this mode

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_Derivation_ModeConstructor_HKDF, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief  Perform input validation for RFC5869 derivation engine.
 *
 * Validation steps:
 * - Number of inputs. No input is required (at most 2 optional inputs - info and salt)
 * - Requested key size shall not be 0 or larger than the available buffer space.
 * - HMAC mode needs to be provided
 * - Requested key size shall not be larger than 255*HashLen
 *
 * @param[in]     derivationMode            Derivation mode, can be created with corresponding ModeConstructor
 * @param[in]     numberOfInputs            Number of inputs. No input is required (at most 2 optional inputs - info and salt)
 * @param[in]     derivedKey                Derived key
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_HKDF_ValidateInput)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_HKDF_ValidateInput(
    mcuxClKey_Derivation_t derivationMode,
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_HKDF_ValidateInput);

    /* No input is required , (info and salt are optional) */
    if(2U < numberOfInputs)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_ValidateInput, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be 0 or larger than the available buffer space. */
    if((derivedKey->type.size == 0U) || (derivedKey->type.size > derivedKey->container.length))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_ValidateInput, MCUXCLKEY_STATUS_ERROR);
    }

    /* HMAC mode needs to be provided */
    if((NULL == derivationMode->macMode) || (NULL == derivationMode->macMode->pCustom))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_ValidateInput, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be larger than 255*HashLen */
    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = ((mcuxClHmac_ModeDescriptor_t *) (derivationMode->macMode->pCustom))->hashAlgorithm;
    if(derivedKey->type.size > (MCUXCLKEY_DERIVATION_HKDF_MAX_OUTPUT_SIZE_FACTOR * hashAlgo->hashSize))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_ValidateInput, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_ValidateInput, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief   Key expansion step for RFC5869 derivation engine.
 *
 *  Steps performed:
 *  n = ceil(L / hashSize).
 *  T(0) = empty string.
 *  T(i) = HMAC(PRK, T(i-1) || info || i). If no info is given, consider info to be the empty string.
 *  T = T(1) || T(2) || ... || T(n).
 *  Output the derivedKey bytes
 *
 * @param[in]     pSession                  Session handle.
 * @param[in]     derivationMode            Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     prkKeyHandle              Pseudorandom key handle calculated in previous step.
 * @param[in,out] pWa                       Key derivation workarea.
 * @param[in]     inputs                    Inputs array. This function may use optional info located at inputs[0].
 * @param[out]    derivedKey                Derived key.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_HKDF_Expand)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_HKDF_Expand(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t prkKeyHandle,
    mcuxClKeyDerivation_WorkArea_t *pWa,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = info, {inputs[1] = salt}
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_HKDF_Expand);

    mcuxClMac_Context_t * const pMacContext = mcuxClMac_castToMacContext(pWa->context_Wa);
    uint8_t* pMacTempResult = pWa->macResult_Wa;
    MCUXCLBUFFER_INIT(pMacTempResultBuf, pSession, pMacTempResult, derivationMode->macMode->common.macByteSize);
    uint8_t *pMac = derivedKey->container.pData;
    MCUXCLBUFFER_INIT(pOutBuf, pSession, pMac, derivedKey->type.size);

    /*
      Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
        - The number of operations depends on the requested size of the derived output key,
        and on hashAlgo->hashSize.
        - The outputBytesLastIteration will be < hashAlgo->hashSize if the requested key's size is
        not a multiple of hashAlgo->hashSize.
    */
    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = ((mcuxClHmac_ModeDescriptor_t *) (derivationMode->macMode->pCustom))->hashAlgorithm;
    uint32_t outputBytesLastIteration = derivedKey->type.size % hashAlgo->hashSize;
    uint8_t nOfIterations = (uint8_t)((derivedKey->type.size / hashAlgo->hashSize) & 0xffU);
    if(outputBytesLastIteration != 0U)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("nOfIterations cannot be equal to UINT32_MAX, as hashAlgo->hashSize is always bigger than 1.")
        nOfIterations++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full MAC output block */
        outputBytesLastIteration = hashAlgo->hashSize;
    }

    uint32_t macOutSize = 0U;
    uint32_t offset = 0U;
    MCUX_CSSL_FP_LOOP_DECL(loop);
    for(uint8_t i = 1U; i <= nOfIterations; i++)
    {
        /* Init Mac context */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
        MCUX_CSSL_FP_FUNCTION_CALL(MacInit, mcuxClMac_init(
            pSession,
            pMacContext,
            prkKeyHandle,
            derivationMode->macMode));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if (MCUXCLMAC_STATUS_OK != MacInit)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Process T(i-1) if i > 1 */
        if (i > 1U)
        {
            MCUXCLBUFFER_INIT_RO(pInTBuf, pSession, pMac + offset - derivationMode->macMode->common.macByteSize, derivationMode->macMode->common.macByteSize);
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_TiMinusOne, mcuxClMac_process(
                pSession,
                pMacContext,
                pInTBuf,
                hashAlgo->hashSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if (MCUXCLMAC_STATUS_OK != MacProcessInput_TiMinusOne)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }
        }

        /* Process info */
        if (0U != inputs[0].size)
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_info, mcuxClMac_process(
                pSession,
                pMacContext,
                inputs[0].input,
                inputs[0].size));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if (MCUXCLMAC_STATUS_OK != MacProcessInput_info)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }
        }

        /* Process i */
        MCUXCLBUFFER_INIT_RO(pInIBuf, pSession, &i, 1U);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
        MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_i, mcuxClMac_process(
            pSession,
            pMacContext,
            pInIBuf,
            1U));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        if (MCUXCLMAC_STATUS_OK != MacProcessInput_i)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        if (i != nOfIterations)
        {
            /* Generate Mac output */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize, mcuxClMac_finish(
                pSession,
                pMacContext,
                pOutBuf,
                &macOutSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if (MCUXCLMAC_STATUS_OK != MacFinalize)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }
        }
        else
        {
            /* Handle the last iteration, which might involve a needed output smaller than the MAC output size.
               Use a workarea buffer to generate the last MAC, and copy only the needed amount of bytes to the pMac buffer. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize, mcuxClMac_finish(
                pSession,
                pMacContext,
                pMacTempResultBuf,
                &macOutSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            if (MCUXCLMAC_STATUS_OK != MacFinalize)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

            MCUX_CSSL_FP_FUNCTION_CALL(write_result, mcuxClBuffer_write(pOutBuf, 0U, (uint8_t *) MCUXCLBUFFER_GET(pMacTempResultBuf), outputBytesLastIteration));
            if(MCUXCLBUFFER_STATUS_OK != write_result)
            {
                /* clean-up the CPU work-area. */
                mcuxClSession_freeWords_cpuWa(pSession, (sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t))
                                             + (sizeof(mcuxClKey_Descriptor_t) / sizeof(uint32_t)));
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, write_result);
            }
            MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *) MCUXCLBUFFER_GET(pMacTempResultBuf), hashAlgo->hashSize);
        }

        MCUXCLBUFFER_UPDATE(pOutBuf, derivationMode->macMode->common.macByteSize);

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("offset will be increased by a total of nOfIterations * macByteSize (which is at most MCUXCLMACMODES_MAX_OUTPUT_SIZE), so this cannot wrap.")
        offset += derivationMode->macMode->common.macByteSize;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        macOutSize = 0U;

        /* Balance the security counter */
        MCUX_CSSL_FP_LOOP_ITERATION(loop,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init),
            MCUX_CSSL_FP_CONDITIONAL(i > 1U, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)),
            MCUX_CSSL_FP_CONDITIONAL(0U != inputs[0].size, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
    }
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF_Expand, MCUXCLKEY_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write),  /* In the last iteration of step 2 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear), /* In the last iteration of step 2 */
        MCUX_CSSL_FP_LOOP_ITERATIONS(loop, nOfIterations));
}

/**
 * @brief   Key derivation engine according to RFC5869 derivation algorithm.
 *
 * @param[in]     pSession                  Session handle
 * @param[in]     derivationMode            Derivation mode, can be created with corresponding ModeConstructor
 * @param[in]     derivationKey             Derivation key
 * @param[in]     inputs                    Inputs array. No input is required (at most 2 optional inputs - info and salt)
 * @param[in]     numberOfInputs            Number of inputs.
 * @param[out]    derivedKey                Derived key
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_HKDF, mcuxClKey_DerivationEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_HKDF(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = info, {inputs[1] = salt}
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_HKDF);

    MCUX_CSSL_FP_FUNCTION_CALL(ret_validateInput, mcuxClKey_derivationEngine_HKDF_ValidateInput(
        derivationMode,
        numberOfInputs,
        derivedKey));

    if(MCUXCLKEY_STATUS_OK != ret_validateInput)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, ret_validateInput,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_HKDF_ValidateInput));
    }

    mcuxClKeyDerivation_WorkArea_t *pWa = mcuxClKey_castToKeyDerivationWorkarea(
                                            mcuxClSession_allocateWords_cpuWa(pSession, sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t))
                                          );
    if(NULL == pWa)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, MCUXCLKEY_STATUS_ERROR);
    }

    MCUXCLMEMORY_FP_MEMORY_CLEAR(pWa->context_Wa, MCUXCLMAC_MAX_CONTEXT_SIZE_HMAC);
    mcuxClMac_Context_t * const pMacContext = mcuxClMac_castToMacContext(pWa->context_Wa);
    uint8_t* pMacResult = pWa->macResult_Wa;
    MCUXCLBUFFER_INIT(pMacResultBuf, pSession, pMacResult, derivationMode->macMode->common.macByteSize);
    uint32_t macOutSize = 0U;

    /* Allocate space for the Hmac key handle */
    mcuxClKey_Handle_t hmacKeyHandle = mcuxClKey_castToKeyHandle(
                                        mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS)
                                      );
    if(NULL == hmacKeyHandle)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, MCUXCLKEY_STATUS_ERROR);
    }

     /* Step 1: Extract
      * Use the salt as key and derivationKey as message for HMAC to obtain PRK.
      * If no salt is given, create a zero-string of size hashSize as default-salt.
      */
    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = ((mcuxClHmac_ModeDescriptor_t *) (derivationMode->macMode->pCustom))->hashAlgorithm;
    if (0U != inputs[1].size)
    {
        hmacKeyHandle->type.size = inputs[1].size;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to create a mock key")
        hmacKeyHandle->location.pData = (uint8_t*)MCUXCLBUFFER_GET(inputs[1].input);
        hmacKeyHandle->container.pData = (uint8_t*)MCUXCLBUFFER_GET(inputs[1].input);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
    }
    else
    {
        /* Use pWa->macResult_Wa to store a zero-string of size hashSize */
        MCUXCLMEMORY_FP_MEMORY_CLEAR(pWa->macResult_Wa, hashAlgo->hashSize);
        hmacKeyHandle->type.size = hashAlgo->hashSize;
        hmacKeyHandle->location.pData = pWa->macResult_Wa;
        hmacKeyHandle->container.pData = pWa->macResult_Wa;
    }

    /* Init Mac context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
    MCUX_CSSL_FP_FUNCTION_CALL(MacInitPRK, mcuxClMac_init(
        pSession,
        pMacContext,
        hmacKeyHandle,
        derivationMode->macMode));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

    if (MCUXCLMAC_STATUS_OK != MacInitPRK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    /* Process IKM */
    uint8_t * pDerivationKey = mcuxClKey_getLoadedKeyData(derivationKey);
    uint32_t derivationKeySize = mcuxClKey_getSize(derivationKey);
    MCUXCLBUFFER_INIT_RO(pDerivationKeyBuf, pSession, pDerivationKey, derivationKeySize);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_IKM, mcuxClMac_process(
        pSession,
        pMacContext,
        pDerivationKeyBuf,
        derivationKeySize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

    if (MCUXCLMAC_STATUS_OK != MacProcessInput_IKM)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
    MCUX_CSSL_FP_FUNCTION_CALL(MacFinalizePRK, mcuxClMac_finish(
        pSession,
        pMacContext,
        pMacResultBuf,
        &macOutSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

    if (MCUXCLMAC_STATUS_OK != MacFinalizePRK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    /* Step 2: Expand
     * Use generated PRF and optional info (context) to derive key of desired size
     */

    /* Prepare PRK key handle */
    hmacKeyHandle->location.pData = (uint8_t*) MCUXCLBUFFER_GET(pMacResultBuf);
    hmacKeyHandle->container.pData = (uint8_t*) MCUXCLBUFFER_GET(pMacResultBuf);
    hmacKeyHandle->type.size = hashAlgo->hashSize;

    MCUX_CSSL_FP_FUNCTION_CALL(ret_hkdfExpand, mcuxClKey_derivationEngine_HKDF_Expand(
        pSession,
        derivationMode,
        hmacKeyHandle,
        pWa,
        inputs,
        derivedKey));

    if (MCUXCLKEY_STATUS_OK != ret_hkdfExpand)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, ret_hkdfExpand);
    }

    /* clean-up the CPU work-area. */
    mcuxClSession_freeWords_cpuWa(pSession, (sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t))
                                         + (MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_HKDF, MCUXCLKEY_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_HKDF_ValidateInput),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear), /* Clear pWa->context_Wa */
        MCUX_CSSL_FP_CONDITIONAL(0U == inputs[1].size, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)), /* Clear pWa->macResult_Wa */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init),     /* In the step 1 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),  /* In the step 1 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish),   /* In the step 1 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_HKDF_Expand));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_HKDF = {
    .pDerivationEngine = mcuxClKey_derivationEngine_HKDF,
    .protectionTokenDerivationEngine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_HKDF)
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
