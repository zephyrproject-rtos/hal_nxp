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

/** @file  mcuxClKdfModes_HKDF.c
 *  @brief Implementation of RFC5869 Key Derivation */

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
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClHmac_Internal_Types.h>
#include <internal/mcuxClKdfModes_Internal_Algorithms.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKdfModes_Internal_Functions.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMac_Internal_Constants.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_ClearSecure_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

#define MCUXCLKEY_DERIVATION_HKDF_MAX_OUTPUT_SIZE_FACTOR    255u  /* As defined by RFC5869 */

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
    pDerivationMode->options = 0u; // no options for this mode

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_Derivation_ModeConstructor_HKDF, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief HKDF input validation.
 *
 * @param[in]     pSession           Session handle
 * @param[in]     derivationMode    Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     numberOfInputs    Shall be 1, if sharedInfo is given, otherwise 0.
 * @param[in]     pDerivedKey       Output key handle.
 *
 * @return Status code indicating whether the inputs are valid.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_HKDF_Check_Inputs)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKdfModes_Engine_HKDF_Check_Inputs(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t pDerivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_Engine_HKDF_Check_Inputs);

    /* No input is required, (info and salt are optional) */
    if(2u < numberOfInputs)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be 0 or larger than the available buffer space. */
    if((mcuxClKey_getSize(pDerivedKey) == 0u) || (mcuxClKey_getSize(pDerivedKey) > pDerivedKey->container.length))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* HMAC mode needs to be provided */
    if((NULL == derivationMode->macMode) || (NULL == derivationMode->macMode->pCustom))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be larger than 255*HashLen */
    const mcuxClHash_AlgorithmDescriptor_t *pHashAlgo = ((mcuxClHmac_ModeDescriptor_t *)(derivationMode->macMode->pCustom))->hashAlgorithm;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pHashAlgo->hashSize, 0u, MCUXCLHASH_MAX_OUTPUT_SIZE, MCUXCLKEY_STATUS_INVALID_INPUT);
    if(mcuxClKey_getSize(pDerivedKey) > (MCUXCLKEY_DERIVATION_HKDF_MAX_OUTPUT_SIZE_FACTOR * pHashAlgo->hashSize))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKdfModes_Engine_HKDF_Check_Inputs, MCUXCLKEY_STATUS_OK);
}

/**
 * @brief HKDF salt preparation.
 *
 * Data Integrity: Expunge(inputs[1].size, inputs[1].input)
 *
 * @param[in]     pSession          Current CL session
 * @param[in]     inputs[]          Additional KDF Inputs
 * @param[in]     hashAlgo          Hash algorithm to be used by KDF
 * @param[in]     pWa               CPU Workarea
 * @param[out]    hmacKeyHandle     Key handle for the output key
 *
 * @return Status code forwarded from mcuxClMemory, mcuxClHash, mcuxClKey subfunctions.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_HKDF_Salt_Preparation)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_HKDF_Salt_Preparation(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = info, {inputs[1] = salt}
    const mcuxClHash_AlgorithmDescriptor_t *pHashAlgo,
    mcuxClKdfModes_WorkArea_t *pWa,
    mcuxClKey_Handle_t hmacKeyHandle)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_HKDF_Salt_Preparation);

    uint32_t hmacKeySize;

    const uint32_t hashBlockSize = pHashAlgo->blockSize;

    if(0u == inputs[1].size)
    {
        MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pWa->macResult_Wa);
        MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pHashAlgo->hashSize);
        MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].size);
        MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].input);
        /* Use pWa->macResult_Wa to store a zero-string of size hashSize */
        MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_INT_FP_EXPECT);
        MCUXCLMEMORY_CLEAR_INT(pWa->macResult_Wa, pHashAlgo->hashSize);
        hmacKeySize = pHashAlgo->hashSize;
    }
    else if(inputs[1].size <= hashBlockSize)
    {
        /* if the salt fits in a block, just copy */
        MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, 0u);
        MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_params, pWa->macResult_Wa);
        /* Buffer_read expunges inputs[1].size and inputs[1].input. This is intentionally kept unbalanced here. */
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(inputs[1].input, 0u, pWa->macResult_Wa, inputs[1].size));
        hmacKeySize = inputs[1].size;
    }
    else
    {
        /* if the salt is bigger than the block size, hash it to hash size */
        MCUX_CSSL_DI_RECORD(oneshotSkeletonParams, inputs[1].input);
        MCUX_CSSL_DI_RECORD(oneshotSkeletonParams, inputs[1].size);
        uint32_t preHashOutSize = 0u;
        MCUX_CSSL_DI_RECORD(oneshotSkeletonParams, &preHashOutSize);
        MCUXCLBUFFER_INIT(outBuf, NULL, pWa->macResult_Wa, pHashAlgo->hashSize);
        MCUX_CSSL_DI_RECORD(oneshotSkeletonParams, outBuf);
        MCUX_CSSL_FP_FUNCTION_CALL(
          prehash_Status,
          pHashAlgo->oneShotSkeleton(pSession, pHashAlgo, inputs[1].input, inputs[1].size, outBuf, &preHashOutSize)
        );
        if(MCUXCLHASH_STATUS_OK != prehash_Status)
        {
          MCUX_CSSL_FP_FUNCTION_EXIT(
            mcuxClKey_derivationEngine_HKDF_Salt_Preparation,
            prehash_Status,
            pHashAlgo->protection_token_oneShotSkeleton
          );
        }
        hmacKeySize = preHashOutSize;
        MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].size);
        MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].input);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(
      keyInit_Status,
      mcuxClKey_init(
        /* mcuxClSession_Handle_t session         */ pSession,
        /* mcuxClKey_Handle_t key                 */ hmacKeyHandle,
        /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Hmac_variableLength,
        /* uint8_t * pKeyData                    */ (const uint8_t*)pWa->macResult_Wa,
        /* uint32_t keyDataLength                */ hmacKeySize
      )
    );
    if (MCUXCLKEY_STATUS_OK != keyInit_Status)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(
        mcuxClKey_derivationEngine_HKDF_Salt_Preparation,
        keyInit_Status,
        MCUX_CSSL_FP_CONDITIONAL((0u != inputs[1].size) && (inputs[1].size > hashBlockSize),
            pHashAlgo->protection_token_oneShotSkeleton
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init)
      );
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(
      mcuxClKey_derivationEngine_HKDF_Salt_Preparation,
      MCUXCLKEY_STATUS_OK,
      MCUX_CSSL_FP_CONDITIONAL((0u != inputs[1].size) && (inputs[1].size > hashBlockSize),
          pHashAlgo->protection_token_oneShotSkeleton
      ),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_HKDF, mcuxClKey_DerivationEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_derivationEngine_HKDF(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = info, {inputs[1] = salt}
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_HKDF);

    uint32_t derivedKeySize = mcuxClKey_getSize(derivedKey);
    uint8_t *pDerivationKeyData = NULL;
    MCUX_CSSL_FP_EXPECT(MCUXCLKEY_LOAD_FP_CALLED(derivationKey));
    MCUXCLKEY_LOAD_FP(
            pSession,
            derivationKey,
            &pDerivationKeyData,
            NULL,
            MCUXCLKEY_ENCODING_SPEC_ACTION_PTR
    );

    uint32_t derivationKeySize = mcuxClKey_getSize(derivationKey);
    // Use pointer from mcuxClKey_getKeyData as temporary buffer for the plain key data
    uint8_t *pMac = mcuxClKey_getKeyData(derivedKey);
    MCUXCLBUFFER_INIT(pOutBuf, pSession, pMac, derivedKeySize);

    /* DI unbalancing to protect input parameters, balanced individually after last usage. */
    MCUX_CSSL_DI_RECORD(kdfParameters, derivedKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, pDerivationKeyData);
    MCUX_CSSL_DI_RECORD(kdfParameters, derivationKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, pMac);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[1].size);  /* Balanced in mcuxClKey_derivationEngine_HKDF_Salt_Preparation */
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[1].input); /* Balanced in mcuxClKey_derivationEngine_HKDF_Salt_Preparation */

    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKdfModes_Engine_HKDF_Check_Inputs));
    MCUX_CSSL_FP_FUNCTION_CALL(checkInputs_Status, mcuxClKdfModes_Engine_HKDF_Check_Inputs(
        pSession,
        derivationMode,
        numberOfInputs,
        derivedKey));
    if(MCUXCLKEY_STATUS_OK != checkInputs_Status)
    {
        MCUXCLSESSION_ERROR(pSession, checkInputs_Status);
    }

    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = ((mcuxClHmac_ModeDescriptor_t *)(derivationMode->macMode->pCustom))->hashAlgorithm;

    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKdfModes_WorkArea_t*, pWa, mcuxClSession_allocateWords_cpuWa(pSession, sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)));

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("The pointer pWa has compatible type and cast was valid")
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pWa->context_Wa);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, MCUXCLMAC_MAX_CONTEXT_SIZE_HMAC);
    MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_INT_FP_EXPECT);
    MCUXCLMEMORY_CLEAR_INT((uint8_t*)pWa->context_Wa, MCUXCLMAC_MAX_CONTEXT_SIZE_HMAC);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Reinterpret structure for pMacContext type, and the pointer pWa->context_Wa is CPU word aligned because of mcuxClSession_allocateWords_cpuWa.")
    mcuxClMac_Context_t * const pMacContext = (mcuxClMac_Context_t *)pWa->context_Wa;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    uint8_t* pMacResult = pWa->macResult_Wa;
    /* SREQI_KDF_1 - DI records for clearing of pMacResult */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pWa->macResult_Wa);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, derivationMode->macMode->common.macByteSize);
    MCUXCLBUFFER_INIT(pTempMacResultBuf, pSession, pMacResult, derivationMode->macMode->common.macByteSize);
    uint32_t macOutSize = 0u;

    /* Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
         - The number of operations depends on the requested size of the derived output key,
           and on hashAlgo->hashSize.
         - The outputBytesLastIteration will be < hashAlgo->hashSize if the requested key's size is
           not a multiple of hashAlgo->hashSize.
    */

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA("derivedKeySize has been checked, so it safe to do the casting");
    uint8_t nOfIterations = (uint8_t)(derivedKeySize / hashAlgo->hashSize);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA();
    uint32_t outputBytesLastIteration = derivedKeySize % hashAlgo->hashSize;

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKeySize);

    if(outputBytesLastIteration != 0u)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("If we enter this if, nOfIterations is at most 254, so the increment does not wrap.")
        nOfIterations++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full MAC output block */
        outputBytesLastIteration = hashAlgo->hashSize;
    }

    /* Allocate space for the Hmac key handle */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClKey_Handle_t, hmacKeyHandle, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    /* Step 1: Use the salt as key and derivationKey as message for HMAC to obtain PRK.
    * If no salt is given, create a zero-string of size hashSize as default-salt.
    */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("The pointer hmacKeyHandle has compatible type and cast was valid")
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_HKDF_Salt_Preparation));
    MCUX_CSSL_FP_FUNCTION_CALL(prepareSalt_Status, mcuxClKey_derivationEngine_HKDF_Salt_Preparation(
      pSession,
      inputs,
      hashAlgo,
      pWa,
      hmacKeyHandle));
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
      if(MCUXCLKEY_STATUS_OK != prepareSalt_Status)
    {
        MCUXCLSESSION_ERROR(pSession, prepareSalt_Status);
    }

    /* Init Mac context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("hmacKeyHandle has the correct type.")
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pMacContext and hmacKeyHandle have compatible type and casts were valid")
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init));
    MCUX_CSSL_FP_FUNCTION_CALL(macInitPRK_Status, mcuxClMac_init(
        pSession,
        pMacContext,
        hmacKeyHandle,
        derivationMode->macMode));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()

    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macInitPRK_Status);

    /* Process IKM */
    MCUXCLBUFFER_INIT_RO(pDerivationKeyBuf, pSession, pDerivationKeyData, derivationKeySize);

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pDerivationKeyData);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
    MCUX_CSSL_FP_FUNCTION_CALL(macProcessInput_IKM_Status, mcuxClMac_process(
        pSession,
        pMacContext,
        pDerivationKeyBuf,
        derivationKeySize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macProcessInput_IKM_Status);

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivationKeySize);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
    MCUX_CSSL_FP_FUNCTION_CALL(macFinalizePRK_Status, mcuxClMac_finish(
        pSession,
        pMacContext,
        pTempMacResultBuf,
        &macOutSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macFinalizePRK_Status);

    /* Step 2:
     * n = ceil(L / hashSize).
     * T(0)= empty string.
     * T(i) = HMAC(PRK, T(i-1) || info || i).
     * T = T(1) || T(2) || ... || T(n).
     * Output the first L Bytes of T.
     * If no info is given, consider info to be the empty string.
     */

    /* Set PRK as the HMAC key */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init));
    MCUX_CSSL_FP_FUNCTION_CALL(keyInit2_Status, mcuxClKey_init(
    /* mcuxClSession_Handle_t session         */ pSession,
    /* mcuxClKey_Handle_t key                 */ hmacKeyHandle,
    /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Hmac_variableLength,
    /* uint8_t * pKeyData                    */ (uint8_t*)MCUXCLBUFFER_GET(pTempMacResultBuf),
    /* uint32_t keyDataLength                */ hashAlgo->hashSize
    ));

    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, keyInit2_Status);

    macOutSize = 0u;

    uint32_t offset = 0U;
    for(uint8_t i = 1u; i <= nOfIterations; i++)
    {
        MCUX_CSSL_DI_RECORD(loop, 1u);
        /* Init Mac context */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init));
        MCUX_CSSL_FP_FUNCTION_CALL(macInit_Status, mcuxClMac_init(
            pSession,
            pMacContext,
            hmacKeyHandle,
            derivationMode->macMode));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macInit_Status);

        /* Process T(i-1) if i > 1 */
        if (i > 1u)
        {
            MCUXCLBUFFER_INIT_RO(pInTBuf, pSession, pMac + offset - derivationMode->macMode->common.macByteSize, derivationMode->macMode->common.macByteSize);
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
            MCUX_CSSL_FP_FUNCTION_CALL(macProcessInput_TiMinusOne_Status, mcuxClMac_process(
                pSession,
                pMacContext,
                pInTBuf,
                hashAlgo->hashSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macProcessInput_TiMinusOne_Status);

        }

        /* Process info */
        if (0u != inputs[0].size)
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
            MCUX_CSSL_FP_FUNCTION_CALL(macProcessInput_info_Status, mcuxClMac_process(
                pSession,
                pMacContext,
                inputs[0].input,
                inputs[0].size));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macProcessInput_info_Status);
        }

        /* Process i */
        MCUXCLBUFFER_INIT_RO(pInIBuf, pSession, &i, 1u);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
        MCUX_CSSL_FP_FUNCTION_CALL(macProcessInput_i_Status, mcuxClMac_process(
            pSession,
            pMacContext,
            pInIBuf,
            1u));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macProcessInput_i_Status);

        if (i != nOfIterations)
        {
            /* Generate Mac output */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
            MCUX_CSSL_FP_FUNCTION_CALL(macFinalize_Status, mcuxClMac_finish(
                pSession,
                pMacContext,
                pOutBuf,
                &macOutSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macFinalize_Status);
        }
        else
        {
            /* Handle the last iteration, which might involve a needed output smaller than the MAC output size.
               Use a workarea buffer to generate the last MAC, and copy only the needed amount of bytes to the pMac buffer. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
            MCUX_CSSL_FP_FUNCTION_CALL(macFinalize_Status, mcuxClMac_finish(
                pSession,
                pMacContext,
                pTempMacResultBuf,
                &macOutSize));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, macFinalize_Status);

            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pOutBuf);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, MCUXCLBUFFER_GET(pTempMacResultBuf));
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, outputBytesLastIteration);
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOutBuf, 0u, (uint8_t *) MCUXCLBUFFER_GET(pTempMacResultBuf), outputBytesLastIteration));
            /* SREQI_KDF_1 - Clear temp out buffer after usage */
            MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
            MCUXCLMEMORY_CLEAR_SECURE_INT((uint8_t*)pWa->macResult_Wa, derivationMode->macMode->common.macByteSize);
        }

        MCUXCLBUFFER_UPDATE(pOutBuf, derivationMode->macMode->common.macByteSize);
        offset += derivationMode->macMode->common.macByteSize;
        macOutSize = 0u;
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_EXPUNGE(loop, nOfIterations);

    /* Apply the requested encoding to the generated key data. This will overwrite the plain key data with the encoded key data */
    MCUX_CSSL_FP_EXPECT(MCUXCLKEY_STORE_FP_CALLED(derivedKey));
    MCUXCLKEY_STORE_FP(pSession, derivedKey, pMac, MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);

    /* clean-up the CPU work-area. */
    mcuxClSession_freeWords_cpuWa(pSession, (sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t))
                                         + (MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS));

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pMac);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_derivationEngine_HKDF);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_HKDF = {
    .pDerivationEngine = mcuxClKey_derivationEngine_HKDF,
    .protectionTokenDerivationEngine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_HKDF)
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
