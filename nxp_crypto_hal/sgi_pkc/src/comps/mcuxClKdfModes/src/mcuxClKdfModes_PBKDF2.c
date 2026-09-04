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

/** @file  mcuxClKdfModes_PBKDF2.c
 *  @brief Implementation of PBKDF2 Key Derivation */

#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClBuffer.h>
#include <mcuxClHmac.h>
#include <mcuxClKey.h>
#include <mcuxClKdfModes.h>
#include <mcuxClMac.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClHmac_Internal_Types.h>
#include <internal/mcuxClKdfModes_Internal_Algorithms.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMac_Internal_Constants.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClMemory_ClearSecure_Internal.h>
#include <internal/mcuxClMacModes_Common_Functions.h>

/**
 * @brief Computes a HMAC digest using the mcuxClMac API
 *
 * @param[in]   pSession
 * @param[in]   hmacMode    Mac mode to be used, must be an Hmac mode
 * @param[in]   hmacKey     Key to be used for the Hmac computation
 * @param[in]   salt        The salt will form the first part of the input for the Hmac computation
 * @param[in]   pIndex      pIndex will form the second part of the input for the Hmac computation. Must be 4 Byte in size.
 * @param[out]  pOutput     Output buffer to store the computed digest. Must be large enough to hold a digest according to hmacMode.
 *
 * @details
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivation_pbkdf2_computeHmac)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivation_pbkdf2_computeHmac(
    mcuxClSession_Handle_t       pSession,
    mcuxClMac_Mode_t             hmacMode,
    mcuxClKey_Handle_t           hmacKey,
    mcuxClKey_DerivationInput_t  salt,
    uint8_t *                   pIndex,
    uint8_t *                   pOutput
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivation_pbkdf2_computeHmac);

    /* Allocate space for the MAC context. */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClMac_Context_t*, hmacContext, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLHMAC_MAX_CONTEXT_SIZE_IN_WORDS));

    mcuxClMac_Status_t init_result = mcuxClMac_init(pSession, hmacContext, hmacKey, hmacMode);
    if(MCUXCLMAC_STATUS_OK != init_result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivation_pbkdf2_computeHmac, init_result);
    }

    /* Process the salt. */
    mcuxClMac_Status_t process_result1 = mcuxClMac_process(pSession, hmacContext, salt.input, salt.size);
    if(MCUXCLMAC_STATUS_OK != process_result1)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivation_pbkdf2_computeHmac, process_result1);
    }

    /* Process the input */
    MCUXCLBUFFER_INIT_RO(pIndexBuf, pSession, pIndex, sizeof(uint32_t));
    mcuxClMac_Status_t process_result2 = mcuxClMac_process(pSession, hmacContext, pIndexBuf, sizeof(uint32_t));
    if(MCUXCLMAC_STATUS_OK != process_result2)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivation_pbkdf2_computeHmac, process_result2);
    }

    uint32_t outSize = 0u;

    /* Create the digest. */
    MCUXCLBUFFER_INIT(pOutputBuf, pSession, pOutput, sizeof(uint32_t));
    mcuxClMac_Status_t finish_result = mcuxClMac_finish(pSession, hmacContext, pOutputBuf, &outSize);
    if(MCUXCLMAC_STATUS_OK != finish_result)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivation_pbkdf2_computeHmac, finish_result);
    }

    /* clean-up the CPU work-area: hmacContext */
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLHMAC_MAX_CONTEXT_SIZE_IN_WORDS);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivation_pbkdf2_computeHmac, MCUXCLKEY_STATUS_OK);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_Derivation_ModeConstructor_PBKDF2)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_PBKDF2(
    mcuxClKey_DerivationMode_t * pDerivationMode,
    const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
    mcuxClMac_Mode_t macMode,
    uint32_t iterationCount)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_Derivation_ModeConstructor_PBKDF2);

    pDerivationMode->derivationAlgorithm = derivationAlgorithm;
    pDerivationMode->macMode = macMode;
    pDerivationMode->options = iterationCount;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_Derivation_ModeConstructor_PBKDF2, MCUXCLKEY_STATUS_OK);
}


/**
 * @brief Top-level function of the implementation of PBKDF2 Key Derivation
 *
 * @param[in]   pSession
 * @param[in]   derivationMode      Mode that specifies algorithm details
 * @param[in]   derivationKey       Key handle holding the source key
 * @param[in]   inputs              Array holding information about the salt to be used
 * @param[in]   numberOfInputs      Number of inputs, expected to be 1
 * @param[out]  derivedKey          Key handle to receive resulting key
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_PBKDF2, mcuxClKey_DerivationEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_derivationEngine_PBKDF2(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], /* inputs[0] = salt */
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_PBKDF2);

    uint32_t derivedKeySize = mcuxClKey_getSize(derivedKey);

    // Use pointer from mcuxClKey_getKeyData as temporary buffer for the plain key data
    uint8_t *pOutputKey = mcuxClKey_getKeyData(derivedKey);

    /* DI unbalancing to protect input parameters, balanced individually after last usage. */
    MCUX_CSSL_DI_RECORD(kdfParameters, derivedKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, derivationKey);
    MCUX_CSSL_DI_RECORD(kdfParameters, pOutputKey);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].input);

    /* Salt is required */
    if(1u != numberOfInputs)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Requested key size shall not be 0 or larger than the available buffer space. */
    if((0u == derivedKeySize) || (derivedKeySize > derivedKey->container.length))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }

    /* HMAC mode needs to be provided */
    if((NULL == derivationMode->macMode) || (NULL == derivationMode->macMode->pCustom))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Salt shall to be at least 8 Bytes. Not enforced */
    /* Iteration count shall be at least 1000. Not enforced */

    /* DESIGN:
     * Follow the algorithm described in section 5.2 of RFC 2898:
     * Step 1: Compute l = ceil(dkLen / hLen) [The number of blocks]
     * Step 2: Compute r = dkLen - (l - 1) * hLen [The number of Bytes needed from the output of the last block]
     * Step 3: Compute T_1, ..., T_l [The block outputs], where
     *      T_i := F(password [aka. derivationKey], salt, c, i);
     *      F(password, salt, c, i) := U_1 xor U_2 xor ... xor U_c;
     *      U_1 := HMAC(Password [used as key], salt || BE32(i));
     *      U_{j+1} := HMAC(Password, U_j);
     *      BE32(i) := [The 32-Bit Big-Endian representation of the counter value i]
     * Step 4: T = T_1 || T_2 || ... || T_l.
     * Output the first dkLen Bytes of T [i.e. only use r Bytes from T_l].
     */

    uint32_t macByteSize = derivationMode->macMode->common.macByteSize;
    uint32_t numberOfBlocks = derivedKeySize / macByteSize;
    uint32_t outputBytesLastBlock = derivedKeySize % macByteSize;

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKeySize);

    if(outputBytesLastBlock != 0u)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        numberOfBlocks++;
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full MAC output block */
        outputBytesLastBlock = macByteSize;
    }

    /* Allocate space for intermediate Hmac results */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pMacOutput, mcuxClSession_allocateWords_cpuWa(pSession, macByteSize / sizeof(uint32_t)));

    /* SREQI_KDF_1 - DI records for clearing of pMacOutput */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pMacOutput);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, macByteSize);

    /* Allocate space for big endian counter value */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pBigEndianI, mcuxClSession_allocateWords_cpuWa(pSession, 1u));

    /* Allocate space for outputKey (used as T_i buffer) */
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pT_i_buffer, mcuxClSession_allocateWords_cpuWa(pSession, macByteSize / sizeof(uint32_t)));

    /* SREQI_KDF_1 - DI records for clearing of pT_i_buffer */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pT_i_buffer);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, macByteSize);

    /* Compute T_i blocks */
    for(size_t i = 1u; i <= numberOfBlocks; i++)
    {
        MCUX_CSSL_DI_RECORD(loop, 1u);
        /* Compute U_1 */
        mcuxClMemory_StoreBigEndian32(pBigEndianI, i);
        mcuxClKey_Status_t u1_result = mcuxClKey_derivation_pbkdf2_computeHmac(pSession,
                                                                             derivationMode->macMode,
                                                                             derivationKey,
                                                                             inputs[0],
                                                                             pBigEndianI,
                                                                             pMacOutput);
        if(MCUXCLKEY_STATUS_OK != u1_result)
        {
            MCUXCLSESSION_ERROR(pSession, u1_result);
        }

        /* Copy U_1 to T_i buffer */
        MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, pT_i_buffer);
        MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, pMacOutput);
        MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, macByteSize);
        MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pT_i_buffer, pMacOutput, macByteSize));

        /* Compute U_2 ... U_c */
        for(size_t j = 1u; j < derivationMode->options; j++)
        {
            uint32_t outSize = 0;
            MCUXCLBUFFER_INIT_RO(pMacInBuf, pSession, pMacOutput, macByteSize);
            MCUXCLBUFFER_INIT(pTempMacOutBuf, pSession, pMacOutput, macByteSize);
            mcuxClMac_Status_t compute_result = mcuxClMac_compute(pSession,
                                                                derivationKey,
                                                                derivationMode->macMode,
                                                                pMacInBuf,
                                                                macByteSize,
                                                                pTempMacOutBuf,
                                                                &outSize);

            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, compute_result);

            MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, pT_i_buffer);
            MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, pT_i_buffer);
            MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, MCUXCLBUFFER_GET(pTempMacOutBuf));
            MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, macByteSize);
            MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_XOR_INT_FP_EXPECT);
            MCUXCLMEMORY_XOR_INT(pT_i_buffer, pT_i_buffer, (uint8_t*)MCUXCLBUFFER_GET(pTempMacOutBuf), macByteSize);
        }

        if(i != numberOfBlocks)
        {
            MCUXCLBUFFER_INIT(pOutputKeyBuf, pSession, pOutputKey, macByteSize);
            /* If not last iteration: Copy T_i buffer to derivedKey */
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pOutputKeyBuf);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, (i - 1u) * macByteSize);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pT_i_buffer);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, macByteSize);
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(
                pOutputKeyBuf,
                (i - 1u) * macByteSize,
                pT_i_buffer,
                macByteSize));
        }
        else
        {
            MCUXCLBUFFER_INIT(pOutputKeyBuf, pSession, pOutputKey, outputBytesLastBlock);
            /* If last iteration: Copy first outputBytesLastBlock bytes of T_i buffer to derivedKey */
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pOutputKeyBuf);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, (i - 1u) * macByteSize);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pT_i_buffer);
            MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, outputBytesLastBlock);
            MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(
                pOutputKeyBuf,
                (i - 1u) * macByteSize,
                pT_i_buffer,
                outputBytesLastBlock));

            /* SREQI_KDF_1 - Clear pMacOutput after usage */
            MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
            MCUXCLMEMORY_CLEAR_SECURE_INT(pMacOutput, macByteSize);

            /* SREQI_KDF_1 - Clear pT_i_buffer after usage */
            MCUX_CSSL_FP_EXPECT(MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
            MCUXCLMEMORY_CLEAR_SECURE_INT(pT_i_buffer, macByteSize);
        }
    }

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivationKey);
    MCUX_CSSL_DI_EXPUNGE(loop, numberOfBlocks);

    /* Apply the requested encoding to the generated key data. This will overwrite the plain key data with the encoded key data */
    MCUX_CSSL_FP_EXPECT(MCUXCLKEY_STORE_FP_CALLED(derivedKey));
    MCUXCLKEY_STORE_FP(pSession, derivedKey, pOutputKey, MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);

    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pOutputKey);

    /* clean-up the CPU work-area: pBigEndianI, pMacOutput, pT_i_buffer */
    mcuxClSession_freeWords_cpuWa(pSession, 1u + 2u * (macByteSize / sizeof(uint32_t)));

    /* FP balancing and exit */
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_derivationEngine_PBKDF2);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_PBKDF2 = {
    .pDerivationEngine = mcuxClKey_derivationEngine_PBKDF2,
    .protectionTokenDerivationEngine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_PBKDF2)
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

