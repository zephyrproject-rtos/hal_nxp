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


#include <mcuxClEcc.h>
#include <mcuxClKey.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <mcuxClBuffer.h>
#include <mcuxClMemory_Copy.h>
#include <mcuxClPkc_Types.h>
#include <internal/mcuxClPkc_Macros.h>
#include <mcuxClPsaDriver.h>
#include <mcuxClRandom.h>
#include <mcuxClRandomModes.h>
#include <mcuxClSession.h>

#include <internal/mcuxClPsaDriver_Functions.h>
#include <internal/mcuxClPsaDriver_Internal.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_generate_ecp_key(
    const psa_key_attributes_t *attributes,
    uint8_t *key_buffer,
    size_t key_buffer_size,
    size_t *key_buffer_length)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_OF_COMPOSITE_EXPRESSION("PSA_KEY_TYPE_ECC_GET_FAMILY macro comes from external library outside our control")
    psa_ecc_family_t curve = MCUXCLPSADRIVER_PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_OF_COMPOSITE_EXPRESSION()
    size_t bytes = MCUXCLPSADRIVER_BITS_TO_BYTES(psa_get_key_bits(attributes));

    if(key_buffer_size < bytes)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    //For Montgomery curves
    if(curve == PSA_ECC_FAMILY_MONTGOMERY)
    {
        /* Setup one session to be used by all functions called */
        mcuxClSession_Descriptor_t session;
        //Byte length of a Curve448
        if(bytes == MCUXCLECC_MONTDH_CURVE448_SIZE_PRIVATEKEY)
        {
            uint32_t pCpuWa[MCUXCLECC_MONTDH_GENERATEKEYPAIR_CURVE448_WACPU_SIZE / (sizeof(uint32_t))];
            /* Initialize session with pkcWA on the beginning of PKC RAM */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(si_status, si_token, mcuxClSession_init(&session, pCpuWa, MCUXCLECC_MONTDH_GENERATEKEYPAIR_CURVE448_WACPU_SIZE,
                                     mcuxClPkc_inline_getPointerToPkcRamStart(), MCUXCLECC_MONTDH_GENERATEKEYPAIR_CURVE448_WAPKC_SIZE));


            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != si_token) || (MCUXCLSESSION_STATUS_OK != si_status))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            mcuxClRandom_Context_t pRng_ctx;
            mcuxClRandom_Mode_t    randomMode;

#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256)
            uint32_t context[MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE_IN_WORDS] = {0u};
            MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
            pRng_ctx = (mcuxClRandom_Context_t)context;
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
            randomMode = mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3;
#else
            pRng_ctx = NULL;
            randomMode = mcuxClRandomModes_Mode_ELS_Drbg;
#endif
            /* Initialize the RNG context */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("Pointer pRng_ctx points to an object of the right type, the cast was valid.")
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(rngInit_result, rngInit_token, mcuxClRandom_init(&session, pRng_ctx, randomMode));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init) != rngInit_token) || (MCUXCLRANDOM_STATUS_OK != rngInit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }

            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /* Initialize the PRNG */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /* Prepare input for key generation */
            uint32_t privKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
            mcuxClKey_Handle_t privKeyHandler = mcuxClKey_castToKeyHandle(privKeyDesc);
            uint32_t pubKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
            mcuxClKey_Handle_t pubKeyHandler = mcuxClKey_castToKeyHandle(pubKeyDesc);
            uint8_t pubKeyBuffer[MCUXCLECC_MONTDH_CURVE448_SIZE_PUBLICKEY]={0};

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(privkeyinit_result, privkeyinit_token, mcuxClKey_init(
            /* mcuxClSession_Handle_t session         */ &session,
            /* mcuxClKey_Handle_t key                 */ privKeyHandler,
            /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Ecc_MontDH_Curve448_PrivateKey,
            /* mcuxCl_Buffer_t pKeyData               */ (mcuxCl_Buffer_t) key_buffer,
            /* uint32_t keyDataLength                */ MCUXCLECC_MONTDH_CURVE448_SIZE_PRIVATEKEY));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != privkeyinit_token) || (MCUXCLKEY_STATUS_OK != privkeyinit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(pubkeyinit_result, pubkeyinit_token, mcuxClKey_init(
            /* mcuxClSession_Handle_t session         */ &session,
            /* mcuxClKey_Handle_t key                 */ pubKeyHandler,
            /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Ecc_MontDH_Curve448_PublicKey,
            /* mcuxCl_Buffer_t pKeyData               */ (mcuxCl_Buffer_t) pubKeyBuffer,
            /* uint32_t keyDataLength                */ MCUXCLECC_MONTDH_CURVE448_SIZE_PUBLICKEY));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != pubkeyinit_token) || (MCUXCLKEY_STATUS_OK != pubkeyinit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /* Call Dh KeyGeneration for keys generation and check FP and return code */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(keygeneration_result, keygeneration_token, mcuxClEcc_MontDH_GenerateKeyPair(&session,
                                                                  privKeyHandler,
                                                                  pubKeyHandler));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_GenerateKeyPair) != keygeneration_token) || (MCUXCLECC_STATUS_OK != keygeneration_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            *key_buffer_length = (size_t) MCUXCLECC_MONTDH_CURVE448_SIZE_PRIVATEKEY;

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cleanup_result, cleanup_token, mcuxClSession_cleanup(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != cleanup_token) || (MCUXCLSESSION_STATUS_OK != cleanup_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(destroy_result, destroy_token, mcuxClSession_destroy(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != destroy_token) || (MCUXCLSESSION_STATUS_OK != destroy_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            return PSA_SUCCESS;
        }

        //Byte length of a Curve25519
        else if(bytes == MCUXCLECC_MONTDH_CURVE25519_SIZE_PRIVATEKEY)
        {
            uint32_t pCpuWa[MCUXCLECC_MONTDH_GENERATEKEYPAIR_CURVE25519_WACPU_SIZE / (sizeof(uint32_t))];
            /* Initialize session with pkcWA on the beginning of PKC RAM */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(si_status, si_token, mcuxClSession_init(&session, pCpuWa, MCUXCLECC_MONTDH_GENERATEKEYPAIR_CURVE25519_WACPU_SIZE,
                                     mcuxClPkc_inline_getPointerToPkcRamStart(), MCUXCLECC_MONTDH_GENERATEKEYPAIR_CURVE25519_WAPKC_SIZE));


            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != si_token) || (MCUXCLSESSION_STATUS_OK != si_status))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /* Initialize the RNG */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(randomInit_result, randomInit_token, mcuxClRandom_init(
                &session,
                MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("NULL argument (context) is not dereferenced with mode mcuxClRandomModes_Mode_ELS_Drbg")
                NULL,
                MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()
                mcuxClRandomModes_Mode_ELS_Drbg));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init) != randomInit_token) || (MCUXCLRANDOM_STATUS_OK != randomInit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /* Initialize the PRNG */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /* Prepare input for key generation */
            uint32_t privKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
            mcuxClKey_Handle_t privKeyHandler = mcuxClKey_castToKeyHandle(privKeyDesc);
            uint32_t pubKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
            mcuxClKey_Handle_t pubKeyHandler = mcuxClKey_castToKeyHandle(pubKeyDesc);
            uint8_t pubKeyBuffer[MCUXCLECC_MONTDH_CURVE25519_SIZE_PUBLICKEY]={0};

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(privkeyinit_result, privkeyinit_token, mcuxClKey_init(
            /* mcuxClSession_Handle_t session         */ &session,
            /* mcuxClKey_Handle_t key                 */ privKeyHandler,
            /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Ecc_MontDH_Curve25519_PrivateKey,
            /* mcuxCl_Buffer_t pKeyData               */ (mcuxCl_Buffer_t) key_buffer,
            /* uint32_t keyDataLength                */ MCUXCLECC_MONTDH_CURVE25519_SIZE_PRIVATEKEY));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != privkeyinit_token) || (MCUXCLKEY_STATUS_OK != privkeyinit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(pubkeyinit_result, pubkeyinit_token, mcuxClKey_init(
            /* mcuxClSession_Handle_t session         */ &session,
            /* mcuxClKey_Handle_t key                 */ pubKeyHandler,
            /* mcuxClKey_Type_t type                  */ mcuxClKey_Type_Ecc_MontDH_Curve25519_PublicKey,
            /* mcuxCl_Buffer_t pKeyData               */ (mcuxCl_Buffer_t) pubKeyBuffer,
            /* uint32_t keyDataLength                */ MCUXCLECC_MONTDH_CURVE25519_SIZE_PUBLICKEY));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != pubkeyinit_token) || (MCUXCLKEY_STATUS_OK != pubkeyinit_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /* Call Dh KeyGeneration for keys generation and check FP and return code */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(keygeneration_result, keygeneration_token, mcuxClEcc_MontDH_GenerateKeyPair(&session,
                                                                  privKeyHandler,
                                                                  pubKeyHandler));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_MontDH_GenerateKeyPair) != keygeneration_token) || (MCUXCLECC_STATUS_OK != keygeneration_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            *key_buffer_length = (size_t) MCUXCLECC_MONTDH_CURVE25519_SIZE_PRIVATEKEY;

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cleanup_result, cleanup_token, mcuxClSession_cleanup(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != cleanup_token) || (MCUXCLSESSION_STATUS_OK != cleanup_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(destroy_result, destroy_token, mcuxClSession_destroy(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != destroy_token) || (MCUXCLSESSION_STATUS_OK != destroy_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            return PSA_SUCCESS;
        }
        else
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }
    //For Weierstrass curves, curve_parameters have defined in mcuxClEcc_Types.c
    else if((curve == PSA_ECC_FAMILY_SECP_R1) || (curve == PSA_ECC_FAMILY_SECP_K1) || (curve == PSA_ECC_FAMILY_BRAINPOOL_P_R1))
    {

        const mcuxClEcc_Weier_DomainParams_t* curveParamData = mcuxClPsaDriver_psa_driver_wrapper_getEccDomainParams(attributes);
        if(NULL == curveParamData)
        {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        /* Initialize buffers on the stack for domain parameters endianess swap (LE -> BE) */
        const uint32_t byteLenP = curveParamData->common.byteLenP;
        const uint32_t byteLenN = curveParamData->common.byteLenN;

        /* Setup one session to be used by all functions called */
        mcuxClSession_Descriptor_t session;

        uint32_t pCpuWa[MCUXCLECC_KEYGEN_WACPU_SIZE / (sizeof(uint32_t))];
        /* Initialize session with pkcWA on the beginning of PKC RAM */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(si_status, si_token, mcuxClSession_init(&session, pCpuWa, sizeof(pCpuWa),
                                 mcuxClPkc_inline_getPointerToPkcRamStart(), MCUXCLECC_KEYGEN_WAPKC_SIZE(byteLenP,byteLenN)));


        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != si_token) || (MCUXCLSESSION_STATUS_OK != si_status))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        mcuxClRandom_Context_t pRng_ctx;
        mcuxClRandom_Mode_t    randomMode;
#if defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256)
        /* Initialize the RNG context, with maximum size */
        uint32_t context[MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE_IN_WORDS] = {0u};
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        pRng_ctx = (mcuxClRandom_Context_t)context;
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        if(byteLenN <= 32u)  /* 128-bit security strength */
        {
          randomMode = mcuxClRandomModes_Mode_ELS_Drbg;
        }
        else  /* 256-bit security strength */
        {
          randomMode = mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3;
        }
#else
        pRng_ctx = NULL;
        randomMode = mcuxClRandomModes_Mode_ELS_Drbg;
#endif

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("Pointer pRng_ctx points to an object of the right type, the cast was valid.")
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(rngInit_result, rngInit_token, mcuxClRandom_init(&session, pRng_ctx, randomMode));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init) != rngInit_token) || (MCUXCLRANDOM_STATUS_OK != rngInit_result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }

        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Initialize the PRNG */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(&session));
        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        uint8_t pubKeyBuffer[2u*MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP];

        /* Reverse endianess of domain parameters as current ECC component expects domain parameters in big endian */
        uint8_t pG[2u*MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP];
        uint8_t pA[MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP];
        uint8_t pB[MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP];
        uint8_t pP[MCUXCLECC_WEIERECC_MAX_SIZE_PRIMEP];
        uint8_t pN[MCUXCLECC_WEIERECC_MAX_SIZE_BASEPOINTORDER];
        for(uint32_t i = 0; i < byteLenP; i++)
        {
            pA[i] = curveParamData->common.pCurveParam1[byteLenP - i - 1u];
            pB[i] = curveParamData->common.pCurveParam2[byteLenP - i - 1u];
            pP[i] = curveParamData->common.pFullModulusP[byteLenP + MCUXCLPKC_WORDSIZE - i - 1u];
            pG[i] = curveParamData->common.pGx[byteLenP - i - 1u];
            pG[byteLenP + i] = curveParamData->common.pGy[byteLenP - i - 1u];
        }
        for(uint32_t i = 0; i < byteLenN; i++)
        {
            pN[i] = curveParamData->common.pFullModulusN[byteLenN + MCUXCLPKC_WORDSIZE - i - 1u];
        }

        MCUXCLBUFFER_INIT_RO(buffA, NULL, pA, byteLenP);
        MCUXCLBUFFER_INIT_RO(buffB, NULL, pB, byteLenP);
        MCUXCLBUFFER_INIT_RO(buffP, NULL, pP, byteLenP);
        MCUXCLBUFFER_INIT_RO(buffG, NULL, pG, byteLenP * 2u);
        MCUXCLBUFFER_INIT_RO(buffN, NULL, pN, byteLenN);

        mcuxClEcc_KeyGen_Param_t paramKeyGen =
        {
            .curveParam = (mcuxClEcc_DomainParam_t)
            {
                .pA = buffA,
                .pB = buffB,
                .pP = buffP,
                .pG = buffG,
                .pN = buffN,
                .misc = mcuxClEcc_DomainParam_misc_Pack(byteLenN, byteLenP)
            },
            .pPrivateKey = key_buffer,
            .pPublicKey = pubKeyBuffer,
            .optLen = 0u
        };

        /* Call KeyGeneration for keys generation and check FP and return code */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(keygeneration_result, keygeneration_token, mcuxClEcc_KeyGen(&session, &paramKeyGen));
        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_KeyGen) != keygeneration_token) || (MCUXCLECC_STATUS_OK != keygeneration_result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        *key_buffer_length = byteLenN;
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cleanup_result, cleanup_token, mcuxClSession_cleanup(&session));
        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != cleanup_token) || (MCUXCLSESSION_STATUS_OK != cleanup_result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(destroy_result, destroy_token, mcuxClSession_destroy(&session));
        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != destroy_token) || (MCUXCLSESSION_STATUS_OK != destroy_result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        return PSA_SUCCESS;
    }
    // Like the twisted Edwards curves Ed25519 and Ed448.
    else
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }
}
