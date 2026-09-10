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

/**
 * @file  mcuxClEcc_ECDSA_Internal_BlindedSecretKeyGen.c
 * @brief Internal functions for generating the ephemeral key for ECDSA in a blinded way.
 */

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClHashModes.h>
#include <mcuxClRandomModes.h>
#include <mcuxClRandom.h>
#include <mcuxClHmac.h>
#include <mcuxClMath.h>
#include <mcuxCsslMemory_Constants.h>
#include <mcuxCsslMemory_Clear.h>
#include <mcuxClMemory_Copy.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#ifdef MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC
#include <internal/mcuxClRandomModes_Internal_HmacDrbg_Functions.h>
#endif /* MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC */
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClHmac_Internal_Memory.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>
#include <internal/mcuxClPkc_Operations.h>

#include <internal/mcuxClEcc_ECDSA_Internal.h>
#include <internal/mcuxClEcc_ECDSA_Internal_FUP.h>

#include <mcuxClCore_Macros.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_RandomWithExtraBits, mcuxClEcc_ECDSA_EphemeralKeyGenFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_RandomWithExtraBits(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_Sign_Param_t * pParam,
    mcuxClEcc_ECDSA_KeyGenCtx_t *pCtx)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_RandomWithExtraBits);
    (void) pCtx;

#ifdef MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC
    /* Verify that the passed signature mode is not for deterministic ECDSA */
    if(NULL != pParam->pMode->pHmacModeDesc)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_RandomWithExtraBits, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
#endif /* MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC */

    const uint32_t byteLenN = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenN_mask) >> mcuxClEcc_DomainParam_misc_byteLenN_offset;
    MCUX_CSSL_FP_FUNCTION_CALL(ret_BlindedSecretKeyGen, mcuxClEcc_WeierECC_BlindedSecretKeyGen_RandomWithExtraBits(pSession, byteLenN));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_RandomWithExtraBits, ret_BlindedSecretKeyGen,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_BlindedSecretKeyGen_RandomWithExtraBits));
}

#ifdef MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, mcuxClEcc_ECDSA_EphemeralKeyGenFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_Sign_Param_t * pParam,
    mcuxClEcc_ECDSA_KeyGenCtx_t *pCtx)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic);

    /* Verify that the passed signature mode is properly set up for deterministic ECDSA */
    if(NULL == pParam->pMode->pHmacModeDesc)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();

    const uint32_t byteLenN = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenN_mask) >> mcuxClEcc_DomainParam_misc_byteLenN_offset;
    const uint32_t byteLenHash = (pParam->optLen & mcuxClEcc_Sign_Param_optLen_byteLenHash_mask) >> mcuxClEcc_Sign_Param_optLen_byteLenHash_offset;
    const uint32_t byteLenHashImport = MCUXCLCORE_MIN(byteLenHash, byteLenN);

    /* Space for Random mode descriptors and context must be reserved by the caller:
     *  - one for an HMAC_DRBG in normal mode associated to the given HMAC mode
     *  - one for an associated HMAC_DRBG in test mode which allows to initialize the HMAC_DRBG with a given seed as required by the deterministic ECDSA ephemeral key construction.
     *  - random context */
    /* Context pointer must be validated by the caller hence no additional checks here */
    mcuxClEcc_ECDSA_Deterministic_KeyGenCtx_t *pDeterministicCtx = mcuxClEcc_castToECDSADeterministicKeyGenCtx(pCtx);
    mcuxClRandom_ModeDescriptor_t *pTestModeDesc = mcuxClRandom_castToModeDescriptor(pDeterministicCtx->testModeDescriptor);
    mcuxClRandom_ModeDescriptor_t *pHmacDrbgMode = mcuxClRandom_castToModeDescriptor(pDeterministicCtx->hmacDrbgModeDescriptor);
    mcuxClRandom_Context_t pRandomCtx = mcuxClRandom_castToContext(pDeterministicCtx->randomCtx);

    // TODO-CLNS-10703: Can there be some of the init stuff shared with higher level functions e.g. sign?
    if(MCUXCLECC_INT_ECDSADETERMINISTIC_CTX_INITIALIZED != pDeterministicCtx->initFlag)
    {
        /*********************************************************************************************/
        /* Create HMAC_DRBG associated to the given HMAC mode.                                       */
        /*                                                                                           */
        /* NOTE: The seed sizes passed to the function are chosen in a way that that the HMAC_DRBG   */
        /*       can later (in test mode) be seeded upon initialization                              */
        /*        - with the properly encoded private key as entropy input and                       */
        /*        - with the properly encoded message digest as nonce                                */
        /*       as specified in NIST SP800-90A.                                                     */
        /*********************************************************************************************/
        mcuxClMac_Mode_t hmacMode = pParam->pMode->pHmacModeDesc;
        uint32_t initSeedSize = 2u * byteLenN;
        uint32_t reseedSeedSize = byteLenN;
        MCUX_CSSL_FP_FUNCTION_CALL(retCreateNormalMode, mcuxClRandomModes_createCustomHmacDrbgMode(
            pHmacDrbgMode,
            hmacMode,
            initSeedSize,
            reseedSeedSize
        ));
        if (MCUXCLRANDOM_STATUS_OK != retCreateNormalMode)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
        }


        /*********************************************************************************************/
        /* Prepare the seed material (entropy_input || nonce) to be used during instantiation of the */
        /* HMAC_DRBG below:                                                                          */
        /*   - Prepare the entropy input, i.e. the private key encoded using primitive int2octets as */
        /*     specified in rfc6979, at the start of buffer ECC_S0                                   */
        /*   - Prepare the nonce, i.e. the message digest encoded using primitive bits2octets as     */
        /*     specified in rfc6979, directly behind the entropy input                               */
        /*                                                                                           */
        /*         |            ECC_S0               ||              ECC_T0            |             */
        /*         ---------------------------------------------------------------------             */
        /*         | int2octets(private key) | bits2octets(digest) | ***************** |             */
        /*                                                                                           */
        /*********************************************************************************************/
        uint32_t *pEntropyInput = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S0]);
        uint8_t *pNonce = (uint8_t *) pEntropyInput + byteLenN;

        /* Import digest (up to byteLenN bytes are enough) to ECC_T1.
        *
        * NOTES: - Copying the digest without endianess reversal ensures that its endianess is already in line with the bits2octets encoding
        *        - The digest is imported to ECC_T1 instead of to its (potentially not PKC aligned) final destination to facilitate PKC operations
        *          needed for its proper encoding.
        *        - During the import, the digest is already padded with zeros or truncated to byte length depending on the relation between its byte length
        *          and the byte length of n
        *        - If the hash byte length is larger than the one of n, further bit level truncation is taken care of after the import. In such case
        *          endianess has to be reversed to facilitate PKC operations. */
        MCUXCLPKC_FP_CALC_OP1_CONST(ECC_T1, 0u);
        uint8_t *pDigestImportDst = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T1]) + byteLenN - byteLenHashImport;
        MCUXCLPKC_WAITFORFINISH();
        MCUXCLMEMORY_FP_MEMORY_COPY(pDigestImportDst, pParam->pHash, byteLenHashImport);

        /* Truncate message hash if its bit length is longer than that of n. */
        if (byteLenHash >= byteLenN)
        {
            /* Count leading zeros in MSByte of n. */
            const volatile uint8_t * ptrN = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
            uint8_t nMSByte = ptrN[byteLenN - 1u];
            uint32_t nMSByte_LeadZeros = (uint32_t) mcuxClMath_CountLeadingZerosWord((uint32_t) nMSByte) - (8u * ((sizeof(uint32_t)) - 1u));
            /* Only keep the first bitLenN bits of hash. */
            MCUXCLMEMORY_FP_MEMORY_COPY_REVERSED(pDigestImportDst, pDigestImportDst, byteLenHashImport);
            MCUXCLPKC_FP_CALC_OP1_SHR(ECC_T1, ECC_T1, (uint8_t) (nMSByte_LeadZeros & 0xFFu));
            /* Reduce the value modulo n */
            MCUXCLPKC_FP_CALC_MC1_MS(ECC_T1, ECC_T1, ECC_N, ECC_N);
            MCUXCLPKC_WAITFORFINISH();
            MCUXCLMEMORY_FP_MEMORY_COPY_REVERSED(pDigestImportDst, pDigestImportDst, byteLenHashImport);
        }

        /* Shift the nonce to its destination address. Take into account destination address may be not aligned to PKC word boundary. */
        uint32_t noncePkcBufferOffset = byteLenN % MCUXCLPKC_WORDSIZE;
        uint32_t nonceByteLenPlusPkcBufferOffset = noncePkcBufferOffset + byteLenN;
        uint32_t noncePkcBufferSize = MCUXCLCORE_ALIGN_TO_WORDSIZE(MCUXCLPKC_WORDSIZE, nonceByteLenPlusPkcBufferOffset);
        uint8_t *pNoncePkcAligned = pNonce - (byteLenN % MCUXCLPKC_WORDSIZE);
        MCUXCLPKC_WAITFORREADY();
        pOperands[ECC_V0] = MCUXCLPKC_PTR2OFFSET(pNoncePkcAligned);
        MCUXCLPKC_PS2_SETLENGTH(0u, noncePkcBufferSize);
        MCUXCLPKC_FP_CALC_OP2_SHL(ECC_V0, ECC_T1, (uint8_t) 8u * (byteLenN % MCUXCLPKC_WORDSIZE));
        MCUXCLPKC_WAITFORFINISH();

        /* Prefill private key buffer with LQRNG. */
        {
            MCUXCLBUFFER_INIT(pBuffEntropyInput, NULL, (uint8_t *) pEntropyInput, byteLenN);
            MCUX_CSSL_FP_FUNCTION_CALL(retNcGenerate_prefillPrivateKeyBuffer, mcuxClRandom_ncGenerate(pSession, pBuffEntropyInput, byteLenN));
            if (MCUXCLRANDOM_STATUS_OK != retNcGenerate_prefillPrivateKeyBuffer)
            {
                if (MCUXCLRANDOM_STATUS_ERROR == retNcGenerate_prefillPrivateKeyBuffer)
                {
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_RNG_ERROR,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
                        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                        MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
                        MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate) );
                }

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
            }
        }  /* scope of pBuffEntropyInput */

        /* Securely copy the private key to its (PKC word aligned) destination address pEntropyInput before the nonce.
        * Due to the copy without endianess reversal, the private key is already correctly encoded afterwards (using int2octets) */
        MCUXCLMEMORY_FP_MEMORY_COPY((uint8_t *) pEntropyInput, pParam->pPrivateKey, byteLenN);

        /*********************************************************************************************/
        /* Create an HMAC_DRBG test mode which shall use the seed material prepared above for        */
        /* seeding during below instantiation and instantiate it.                                    */
        /*                                                                                           */
        /* NOTE: Since mcuxClRandomModes_createTestFromNormalMode requires the custom seed input      */
        /*       pointer to be aligned, we first shift the seed material again to an aligned         */
        /*       address. Use ECC_S1 || ECC_T1 as temp buffers here.                                 */
        /*********************************************************************************************/

        /* Create test mode utilizing the seed prepared above. */
        MCUX_CSSL_FP_FUNCTION_CALL(retCreateTestMode, mcuxClRandomModes_createTestFromNormalMode(
            pTestModeDesc,
            pHmacDrbgMode,
            pEntropyInput
        ));
        if (MCUXCLRANDOM_STATUS_OK != retCreateTestMode)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
        }

    #ifdef MCUXCL_FEATURE_ECC_STRENGTH_CHECK
        /* Derive the security strength required for the RNG from bitLenN/2 and check whether it can be provided.
        *
        * NOTE: The function mcuxClRandom_checkSecurityStrength can't be used for this because it reads the security strength from the Random config stored in the session. */
        if (MCUXCLCORE_MIN((byteLenN * 8u) / 2u, 256u) > pTestModeDesc->securityStrength)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_RNG_ERROR,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
                MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                    MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                    MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode) );
        }
    #endif

        /* Instantiate HMAC_DRBG */
        if (NULL == pRandomCtx)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
        MCUX_CSSL_FP_FUNCTION_CALL(retTestModeInit, pTestModeDesc->pOperationMode->initFunction(pSession, pTestModeDesc, pRandomCtx));
        if (MCUXCLRANDOM_STATUS_OK != retTestModeInit)
        {
            if (MCUXCLRANDOM_STATUS_ERROR == retTestModeInit)
            {
                /* Clear CPU workarea before returning. */
                uint32_t clearSize = (sizeof(uint32_t)) * MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE_IN_WORDS;
                MCUX_CSSL_FP_FUNCTION_CALL(retMemoryClear_RandomCtx, mcuxCsslMemory_Clear(
                    mcuxCsslParamIntegrity_Protect(3u, pRandomCtx, clearSize, clearSize),
                    (uint8_t *) pRandomCtx,
                    clearSize,
                    clearSize));
                if (MCUXCSSLMEMORY_STATUS_OK != retMemoryClear_RandomCtx)
                {
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
                }

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_RNG_ERROR,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
                    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                    MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                    MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                        MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode),
                    pTestModeDesc->pOperationMode->protectionTokenInitFunction,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear) );
            }

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
        }
    }
    /*********************************************************************************************/
    /* Generate an ephemeral key k using the HMAC_DBRG in test mode in a loop as specified in    */
    /* rfc6979. If the generated value is not in range [1,n-1], repeat.                          */
    /*********************************************************************************************/

    uint32_t fails_k  = 0u;
    uint32_t fails_k1 = 0u;
    MCUX_CSSL_FP_LOOP_DECL(MainLoop_K);   /* inner loop */
    MCUX_CSSL_FP_LOOP_DECL(MainLoop_K1);  /* outer loop */

    do
    {
        do
        {
            /*********************************************************************************************/
            /* Generate a candidate ephemeral key k using the HMAC_DBRG in test mode                     */
            /*********************************************************************************************/

            /* Initialize PS2 to perform plain additions and subtractions for the computation of (k + r) - (n + r). */
            const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
            const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;
            MCUXCLPKC_PS2_SETLENGTH(0u, bufferSize);
            uint32_t* pK = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S2]);

            /* Clear upper part of ephemeral key buffer. */

            uint8_t * pUpper = &((uint8_t *)pK)[byteLenN];
            MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(byteLenN, 0, bufferSize, MCUXCLECC_STATUS_FAULT_ATTACK)
            uint32_t upperSize = bufferSize - byteLenN;
            MCUX_CSSL_FP_FUNCTION_CALL(retMemoryClear_K, mcuxCsslMemory_Clear(
                mcuxCsslParamIntegrity_Protect(3u, pUpper, upperSize, upperSize),
                pUpper,
                upperSize,
                upperSize));
            if (MCUXCSSLMEMORY_STATUS_OK != retMemoryClear_K)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
            }

            /* Prefill ephemeral key buffer with LQRNG. */
            MCUXCLBUFFER_INIT(pKBuff, NULL, (uint8_t *) pK, byteLenN);
            MCUX_CSSL_FP_FUNCTION_CALL(retNcGenerate_prefillEphemeralKeyBuffer, mcuxClRandom_ncGenerate(pSession, pKBuff, byteLenN));
            if (MCUXCLRANDOM_STATUS_OK != retNcGenerate_prefillEphemeralKeyBuffer)
            {
                if (MCUXCLRANDOM_STATUS_ERROR == retNcGenerate_prefillEphemeralKeyBuffer)
                {
                    /* Clear CPU workarea before returning. */
                    uint32_t clearSize = (sizeof(uint32_t)) * MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE_IN_WORDS;
                    MCUX_CSSL_FP_FUNCTION_CALL(retMemoryClear_RandomCtx, mcuxCsslMemory_Clear(
                        mcuxCsslParamIntegrity_Protect(3u, pRandomCtx, clearSize, clearSize),
                        (uint8_t *) pRandomCtx,
                        clearSize,
                        clearSize));
                    if (MCUXCSSLMEMORY_STATUS_OK != retMemoryClear_RandomCtx)
                    {
                        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
                    }

                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_RNG_ERROR,
                        /* Balancing function calls before the loop */
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
                        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                        MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                        MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode),
                        pTestModeDesc->pOperationMode->protectionTokenInitFunction,
                        MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K, fails_k + fails_k1),
                        MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K1, fails_k1),
                        /* Balancing function inside the loop until this point */
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear) );
                }
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
            }

            /* Generate ephemeral key k using the HMAC_DRBG */
            MCUX_CSSL_FP_FUNCTION_CALL(retTestModeGenerate, pTestModeDesc->pOperationMode->generateFunction(pSession, pTestModeDesc, pRandomCtx, pKBuff, byteLenN));
            if (MCUXCLRANDOM_STATUS_OK != retTestModeGenerate)
            {
                if (MCUXCLRANDOM_STATUS_ERROR == retTestModeGenerate)
                {
                    /* Clear CPU workarea before returning. */
                    uint32_t clearSize = (sizeof(uint32_t)) * MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE_IN_WORDS;
                    MCUX_CSSL_FP_FUNCTION_CALL(retMemoryClear_RandomCtx, mcuxCsslMemory_Clear(
                        mcuxCsslParamIntegrity_Protect(3u, pRandomCtx, clearSize, clearSize),
                        (uint8_t *) pRandomCtx,
                        clearSize,
                        clearSize));
                    if (MCUXCSSLMEMORY_STATUS_OK != retMemoryClear_RandomCtx)
                    {
                        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
                    }

                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_RNG_ERROR,
                        /* Balancing function calls before the loop */
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
                        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                        MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                        MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode),
                        pTestModeDesc->pOperationMode->protectionTokenInitFunction,
                        MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K, fails_k + fails_k1),
                        MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K1, fails_k1),
                        /* Balancing function inside the loop until this point */
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                        pTestModeDesc->pOperationMode->protectionTokenGenerateFunction,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear) );
                }

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
            }

            /* Generate (bufferSize - 1) bytes LQRNG in operand T2, for:             */
            /* (1) first operandSize bytes: mask ephemeral key to switch endianness; */
            /* (2) whole (bufferSize - 1) bytes: blind k to compare k < n;           */
            /* (3) first operandSize bytes: blind k to compute (k0)^(-1) * k mod n.  */
            uint32_t* pT2 = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_T2]);
            ((uint8_t *) pT2)[bufferSize - 1u] = 0u;
            {
                MCUXCLBUFFER_INIT(pBuffT2, NULL, (uint8_t *) pT2, bufferSize - 1u);
                MCUX_CSSL_FP_FUNCTION_CALL(retNcGenerate_T2, mcuxClRandom_ncGenerate(pSession, pBuffT2, bufferSize - 1u));
                if (MCUXCLRANDOM_STATUS_OK != retNcGenerate_T2)
                {
                    /* Clear CPU workarea before returning. */
                    uint32_t clearSize = (sizeof(uint32_t)) * MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE_IN_WORDS;
                    MCUX_CSSL_FP_FUNCTION_CALL(retMemoryClear_RandomCtx, mcuxCsslMemory_Clear(
                        mcuxCsslParamIntegrity_Protect(3u, pRandomCtx, clearSize, clearSize),
                        (uint8_t *) pRandomCtx,
                        clearSize,
                        clearSize));
                    if (MCUXCSSLMEMORY_STATUS_OK != retMemoryClear_RandomCtx)
                    {
                        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
                    }

                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_RNG_ERROR,
                        /* Balancing function calls before the loop */
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
                        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                        MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                        MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                            MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                            MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode),
                        pTestModeDesc->pOperationMode->protectionTokenInitFunction,
                        MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K, fails_k + fails_k1),
                        MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K1, fails_k1),
                        /* Balancing function inside the loop until this point */
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                        pTestModeDesc->pOperationMode->protectionTokenGenerateFunction,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear) );
                }
            }  /* scope of pBuffT2 */
            MCUXCLPKC_FP_CALC_OP1_XOR(ECC_S2, ECC_S2, ECC_T2);
            MCUXCLPKC_WAITFORFINISH();

            /* Revert the endianess of the generated k so that in can be considered an integer by the PKC. */
            MCUXCLPKC_FP_SWITCHENDIANNESS(pK, byteLenN);
            MCUXCLPKC_FP_SWITCHENDIANNESS(pT2, byteLenN);
            MCUXCLPKC_FP_CALC_OP1_XOR(ECC_S2, ECC_S2, ECC_T2);
            MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();

            /* Encode k using the bits2int procedure as specified in rfc6979, i.e. truncate it to the bit length of n. */
            const volatile uint8_t * ptrN = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
            uint8_t nMSByte = ptrN[byteLenN - 1u];
            uint32_t nMSByte_LeadZeros = (uint32_t) mcuxClMath_CountLeadingZerosWord((uint32_t) nMSByte) - (8u * ((sizeof(uint32_t)) - 1u));
            MCUXCLPKC_FP_CALC_OP1_SHR(ECC_S2, ECC_S2, (uint8_t)(nMSByte_LeadZeros & 0xFFU));


            /*********************************************************************************************/
            /* Check if k is smaller than n in an additively blinded way. If not, repeat.                */
            /*********************************************************************************************/

            /* Reuse T2 = rnd, length = (bufferSize - 1u) > operandSize >= byteLenN. */
            /* Compute (k+rnd) - (n+rnd) in a FUP program. If the PKC CARRY flag is not set,
             * k is not smaller than n and a new candidate needs to be generated. */
            MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_CheckNSmallerK,
                                mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_CheckNSmallerK_LEN);

            /* Balance FP for the loop so far. */
            MCUX_CSSL_FP_LOOP_ITERATION(MainLoop_K,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                pTestModeDesc->pOperationMode->protectionTokenGenerateFunction,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                MCUXCLPKC_FP_CALLED_CALC_OP1_XOR,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SwitchEndianness),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SwitchEndianness),
                MCUXCLPKC_FP_CALLED_CALC_OP1_XOR,
                MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
            );

            /* Check PKC CARRY Flag, and if it is not set, repeat */
            fails_k += (1u ^ (MCUXCLPKC_FLAG_NOCARRY ^ MCUXCLPKC_WAITFORFINISH_GETCARRY()));
        } while(MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_GETCARRY());


        /*********************************************************************************************/
        /* Blind the ephemeral key k multiplicatively with a 64 bit blinding k0 (with MSBit set to 1)*/
        /* to obtain k1 = k0^(-1) * k mod n. In blinded form check if it is zero. If so, repeat.     */
        /*********************************************************************************************/

        /* Generate a 64 bit random multiplicative blinding value k0 */
        uint8_t* pK0 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S0]);
        MCUXCLPKC_FP_CALC_OP1_CONST(ECC_S0, 0u);
        MCUXCLBUFFER_INIT(pK0Buff, NULL, pK0, 8u); // TODO-CLNS-10703: Add define for 8u
        MCUXCLPKC_WAITFORFINISH();
        MCUX_CSSL_FP_FUNCTION_CALL(retNcGenerate_2, mcuxClRandom_ncGenerate(pSession, pK0Buff, 8u));
        if (MCUXCLRANDOM_STATUS_OK != retNcGenerate_2)
        {
            if (MCUXCLRANDOM_STATUS_ERROR == retNcGenerate_2)
            {
                /* Clear CPU workarea before returning. */
                uint32_t clearSize = (sizeof(uint32_t)) * MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE_IN_WORDS;
                MCUX_CSSL_FP_FUNCTION_CALL(retMemoryClear_RandomCtx, mcuxCsslMemory_Clear(
                    mcuxCsslParamIntegrity_Protect(3u, pRandomCtx, clearSize, clearSize),
                    (uint8_t *) pRandomCtx,
                    clearSize,
                    clearSize));
                if (MCUXCSSLMEMORY_STATUS_OK != retMemoryClear_RandomCtx)
                {
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
                }

                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_RNG_ERROR,
                    /* Balancing function calls before the loop */
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
                    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                    MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                    MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                        MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                        MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode),
                    pTestModeDesc->pOperationMode->protectionTokenInitFunction,
                    MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K, fails_k + fails_k1 + 1u),
                    MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K1, fails_k1),
                    /* Balancing function inside the if-block until this point */
                    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear) );
            }

            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
        }

        /* Set MSBit of k0 (to ensure k0 != 0) using the PKC.
         *
         * NOTES:
         *  - PKC PS1 can be used, because operandSize >= 64.
         *  - Clear operand S3 and set bit 64 to 1 */
        MCUXCLPKC_FP_CALC_OP1_CONST(ECC_S3, 0u);
        uint32_t *ptr32S3 = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S3]);
        MCUXCLPKC_WAITFORFINISH();
        ptr32S3[1] = 0x80000000u;
        MCUXCLPKC_FP_CALC_OP1_OR(ECC_S0, ECC_S0, ECC_S3);

        /* Compute modular inverse of k0 mod n and store it in buffer T0. */
        /* ZA = k0, duplicate because ModInv(k0) will destroy input k0. */
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_ZA, ECC_S0, 0u);
        /* T0 = k0^(-1) = ModInv(k0), with temp S1. */
        MCUXCLMATH_FP_MODINV(ECC_T0, WEIER_ZA, ECC_N, ECC_S1);

        /* Compute k1 in a blinded way and in blinded form check if k is zero
         * T2 = rnd (operandSize) will be reused.
         * S2 = k will be overwritten firstly by (k+rnd mod n) in the FUP.
         * NOTE: After the FUP program, the PKC ZERO flag is set iff k is zero */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_BlindK_CheckZeroK,
                            mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_BlindK_CheckZeroK_LEN);

        /* Balance the FP for the final part of the loop. */
        MCUX_CSSL_FP_LOOP_ITERATION(MainLoop_K1,
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
        );

        /* Check if k1 is zero, and if so, repeat */
        fails_k1 += (1u ^ (MCUXCLPKC_FLAG_ZERO ^ MCUXCLPKC_WAITFORFINISH_GETZERO()));
    } while(MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_GETZERO());

    /* Clear CPU workarea before returning. */
    uint32_t clearSize = (sizeof(uint32_t)) * MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE_IN_WORDS;
    MCUX_CSSL_FP_FUNCTION_CALL(retMemoryClear_RandomCtx, mcuxCsslMemory_Clear(
        mcuxCsslParamIntegrity_Protect(3u, pRandomCtx, clearSize, clearSize),
        (uint8_t *) pRandomCtx,
        clearSize,
        clearSize));
    if (MCUXCSSLMEMORY_STATUS_OK != retMemoryClear_RandomCtx)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    if(MCUXCLECC_INT_ECDSADETERMINISTIC_CTX_INITIALIZED == pDeterministicCtx->initFlag)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_OK,
            MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K, fails_k + fails_k1 + 1u),
            MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K1, fails_k1 + 1u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear) );
    }
    else
    {
        pDeterministicCtx->initFlag = MCUXCLECC_INT_ECDSADETERMINISTIC_CTX_INITIALIZED;

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic, MCUXCLECC_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createCustomHmacDrbgMode),
            MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            MCUXCLPKC_FP_CALLED_CALC_OP2_SHL,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed),
                MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,
                MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode),
            pTestModeDesc->pOperationMode->protectionTokenInitFunction,
            MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K, fails_k + fails_k1 + 1u),
            MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_K1, fails_k1 + 1u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Clear) );
    }

}
#endif /* MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC */
