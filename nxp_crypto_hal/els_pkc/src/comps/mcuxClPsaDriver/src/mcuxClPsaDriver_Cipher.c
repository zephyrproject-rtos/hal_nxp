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


#include <mcuxClMemory_Clear.h>
#include <mcuxClPsaDriver.h>
#include <mcuxClAes.h>
#include <mcuxClCipher.h>
#include <mcuxClCipherModes.h>
#include <mcuxClSession.h>
#include <mcuxClRandom.h>
#include <mcuxClRandomModes.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClCipherModes_Els_Types.h>
#include <internal/mcuxClPsaDriver_Functions.h>
#include <internal/mcuxClPsaDriver_Internal.h>
#include <internal/mcuxClPsaDriver_ExternalMacroWrappers.h>

#if MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE >= MCUXCLRANDOMMODES_NCINIT_WACPU_SIZE
    #define MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE
#else
    #define MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE MCUXCLRANDOMMODES_NCINIT_WACPU_SIZE
#endif

/** Inline function for proper type casts*/
static inline mcuxClPsaDriver_ClnsData_Cipher_t* mcuxClPsaDriver_getClnsData_cipherType(els_pkc_cipher_operation_t *operation)
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    return (mcuxClPsaDriver_ClnsData_Cipher_t *) operation->clns_data;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_abort(
    els_pkc_cipher_operation_t  *operation )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    mcuxClPsaDriver_ClnsData_Cipher_t * pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);
    if(PSA_SUCCESS !=  mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusUnload(&pClnsCipherData->keydesc))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Clear cipher ctx */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(token, mcuxClMemory_clear ((uint8_t*)pClnsCipherData,
                                                                       MCUXCLPSADRIVER_CLNSDATA_CIPHER_SIZE,
                                                                       MCUXCLPSADRIVER_CLNSDATA_CIPHER_SIZE));

    operation->default_iv_length = 0;
    operation->iv_required = 0;
    //operation->iv_set = 0;

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != token)
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    return PSA_SUCCESS;
}

static psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt_internal(
    mcuxClKey_Descriptor_t *pKey,
    psa_algorithm_t alg,
    const uint8_t *input, /* Buffer containing the message to decrypt. This consists of the IV followed by the ciphertext. */
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length )
{
    psa_key_attributes_t *attributes = mcuxClPsaDriver_castAuxDataToKeyAttributes(pKey);
    /* For algorithms supported by CLNS, add implementation. */
    if (mcuxClPsaDriver_psa_driver_wrapper_cipher_isAlgSupported(attributes))
    {

        if (!mcuxClPsaDriver_psa_driver_wrapper_cipher_doesKeyPolicySupportAlg(attributes, alg))
        {
            return PSA_ERROR_NOT_PERMITTED;
        }

        /* Variable for the AES mode. Set this according to the key policy. */
        const mcuxClCipher_ModeDescriptor_t *mode = NULL;
        uint32_t iv_required = mcuxClPsaDriver_psa_driver_wrapper_cipher_modeSelectDec(alg, &mode);
        if (NULL == mode)
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }

        /* check for invalid input based upon following rule
           inLength needs to be a multiple of the granularity, if this is not the case, return an error. */
        const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t *pAlgo = mode->pAlgorithm;
        if((input_length % pAlgo->granularity) != 0u)
        {
            return (PSA_ERROR_INVALID_ARGUMENT);
        }

        size_t expected_output_size;
        expected_output_size = output_size == 0u ? output_size : input_length;

        /* Check for small output buffer size*/
        if( output_size < expected_output_size )
        {
            return( PSA_ERROR_BUFFER_TOO_SMALL );
        }

        /* Key buffer for the CPU workarea in memory. */
        uint32_t cpuWorkarea[MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE/sizeof(uint32_t)];

        /* Create session */
        mcuxClSession_Descriptor_t session;

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(&session, cpuWorkarea, MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE, NULL, 0u));

        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Initialize the PRNG */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(&session));
        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        // If there is no need for IV iv_length will be set to 0 and ciphertext will point to beginning of input buffer
        // In other case first 16B of input buffer will be used as IV and ciphertext will point to input buffer + iv_length
        uint32_t iv_length = (1u == iv_required) ? MCUXCLAES_BLOCK_SIZE : 0u;
        /* Initializing the output length with zero */
        uint32_t output_length_tmp = 0u;

        /* Do the decryption */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClCipher_crypt(
            &session, pKey, mode,
            /* input := IV || ciphertext */
            input, iv_length,
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Per PSA standard for cipher_decrypt the input_length must contain the iv_length, this cannot wrap.")
            input + iv_length, input_length - iv_length,
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
            output, &output_length_tmp));

        *output_length = (size_t)output_length_tmp;
        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_crypt) != token) || (MCUXCLCIPHER_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
        /* Destroy the session */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(&session));

        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Return with success */
        return PSA_SUCCESS;
    }
    else{
        return PSA_ERROR_NOT_SUPPORTED;
    }
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt(
    const psa_key_attributes_t * attributes,
    const uint8_t * key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    // The driver handles multiple storage locations, call it first then default to builtin driver
    /* Create the key */
    mcuxClKey_Descriptor_t key = {0};
    psa_status_t keyStatus = mcuxClPsaDriver_psa_driver_wrapper_createClKey(attributes, key_buffer, key_buffer_size, &key);
    if(PSA_SUCCESS != keyStatus)
    {
        return keyStatus;
    }
    status = mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt_internal(&key,
                                                                       alg,
                                                                       input,
                                                                       input_length,
                                                                       output,
                                                                       output_size,
                                                                       output_length);

    keyStatus = mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusUnload(&key);
    if(PSA_SUCCESS !=  keyStatus)
    {
        return keyStatus;
    }

    return status;
}

static psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt_setup_internal(
    els_pkc_cipher_operation_t  *operation,
    mcuxClKey_Descriptor_t *keyDesc,
    psa_algorithm_t alg)
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    psa_key_attributes_t *attributes =(psa_key_attributes_t *)mcuxClKey_getAuxData(keyDesc);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* For algorithms supported by CLNS, add implementation. */
    if (mcuxClPsaDriver_psa_driver_wrapper_cipher_isAlgSupported(attributes))
    {
        if (!mcuxClPsaDriver_psa_driver_wrapper_cipher_doesKeyPolicySupportAlg(attributes, alg))
        {
            return PSA_ERROR_NOT_PERMITTED;
        }

        /* Variable for the AES mode. Set this according to the key policy. */
        const mcuxClCipher_ModeDescriptor_t *mode = NULL;
        operation->iv_required = mcuxClPsaDriver_psa_driver_wrapper_cipher_modeSelectDec(alg, &mode);
        if (NULL == mode)
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }

        //operation->iv_set = 0u;
        operation->default_iv_length = (1u == operation->iv_required) ? MCUXCLAES_BLOCK_SIZE : 0u;

        /* Key buffer for the CPU workarea in memory. */
        uint32_t cpuWorkarea[MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE_IN_WORDS];

        /* Create session */
        mcuxClSession_Descriptor_t session;

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(&session, cpuWorkarea, MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE, NULL, 0u));

        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        uint8_t tempIV[16] = {0u};

        /* Do the encryption */
        mcuxClPsaDriver_ClnsData_Cipher_t * pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClCipher_init(&session, (mcuxClCipher_Context_t *) &pClnsCipherData->ctx, keyDesc, mode, tempIV, operation->default_iv_length));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_init) != token) || (MCUXCLCIPHER_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
        /* Destroy the session */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(&session));

        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Return with success */
        return PSA_SUCCESS;
    }
    else
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt_setup(
    els_pkc_cipher_operation_t  *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size, psa_algorithm_t alg)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{

    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    // The driver handles multiple storage locations, call it first then default to builtin driver
    /* Create the key */
    mcuxClPsaDriver_ClnsData_Cipher_t * pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);
    mcuxClKey_Descriptor_t *keyDesc = &pClnsCipherData->keydesc;
    psa_status_t keyStatus = mcuxClPsaDriver_psa_driver_wrapper_createClKey(attributes, key_buffer, key_buffer_size, keyDesc);
    if(PSA_SUCCESS != keyStatus)
    {
        return keyStatus;
    }
    status = mcuxClPsaDriver_psa_driver_wrapper_cipher_decrypt_setup_internal(operation,
                                                         keyDesc,
                                                         alg);

    keyStatus = mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusSuspend(keyDesc);
    if(PSA_SUCCESS !=  keyStatus)
    {
        return keyStatus;
    }

    return status;
}

static psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt_internal(
    mcuxClKey_Descriptor_t *pKey,
    psa_algorithm_t alg,
    const uint8_t *iv_data,
    size_t iv_length,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length)
{
    psa_key_attributes_t *attributes = mcuxClPsaDriver_castAuxDataToKeyAttributes(pKey);
    /* For algorithms supported by CLNS, add implementation. */
    if (mcuxClPsaDriver_psa_driver_wrapper_cipher_isAlgSupported(attributes))
    {
        if (!mcuxClPsaDriver_psa_driver_wrapper_cipher_doesKeyPolicySupportAlg(attributes, alg))
        {
            return PSA_ERROR_NOT_PERMITTED;
        }

        /* Variable for the AES mode. Set this according to the key policy. */
        const mcuxClCipher_ModeDescriptor_t *mode = NULL;
        (void)mcuxClPsaDriver_psa_driver_wrapper_cipher_modeSelectEnc(alg, &mode);
        if (NULL == mode)
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }

        /* check for invalid input based upon following rule
           inLength needs to be a multiple of the granularity, if this is not the case, return an error. */
        const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t *pAlgo = mode->pAlgorithm;
        if((input_length % pAlgo->granularity) != 0u)
        {
            return (PSA_ERROR_INVALID_ARGUMENT);
        }
        /* Key buffer for the CPU workarea in memory. */
        uint32_t cpuWorkarea[MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE/sizeof(uint32_t)];
        /* Initializing the output length with zero */
        uint32_t output_length_tmp = 0u;

        /* Create session */
        mcuxClSession_Descriptor_t session;

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(&session, cpuWorkarea, MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE, NULL, 0u));

        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Initialize the PRNG */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(&session));
        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Do the encryption */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClCipher_crypt(&session, pKey, mode, iv_data, iv_length, input, input_length, output, &output_length_tmp));
        *output_length = (size_t)output_length_tmp;
        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_crypt) != token) || (MCUXCLCIPHER_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Destroy the session */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(&session));

        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
        /* Return with success */
        return PSA_SUCCESS;
    }
    else{
        return PSA_ERROR_NOT_SUPPORTED;
    }
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *iv_data,
    size_t iv_length,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    // The driver handles multiple storage locations, call it first then default to builtin driver
    /* Create the key */
    mcuxClKey_Descriptor_t key = {0};
    psa_status_t keyStatus = mcuxClPsaDriver_psa_driver_wrapper_createClKey(attributes, key_buffer, key_buffer_size, &key);
    if(PSA_SUCCESS != keyStatus)
    {
        return keyStatus;
    }
    status = mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt_internal( &key,
					                                                    alg,
					                                                    iv_data,
					                                                    iv_length,
					                                                    input,
					                                                    input_length,
					                                                    output,
					                                                    output_size,
					                                                    output_length);

    keyStatus = mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusUnload(&key);
    if(PSA_SUCCESS !=  keyStatus)
    {
        return keyStatus;
    }

    return status;
}

static psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt_setup_internal(
    els_pkc_cipher_operation_t  *operation,
    mcuxClKey_Descriptor_t *keyDesc,
    psa_algorithm_t alg)
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    psa_key_attributes_t *attributes =(psa_key_attributes_t *)mcuxClKey_getAuxData(keyDesc);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
    /* For algorithms supported by CLNS, add implementation. */
    if (mcuxClPsaDriver_psa_driver_wrapper_cipher_isAlgSupported(attributes))
    {

        if (!mcuxClPsaDriver_psa_driver_wrapper_cipher_doesKeyPolicySupportAlg(attributes, alg))
        {
            return PSA_ERROR_NOT_PERMITTED;
        }

        /* Variable for the AES mode. Set this according to the key policy. */
        const mcuxClCipher_ModeDescriptor_t *mode = NULL;
        operation->iv_required = mcuxClPsaDriver_psa_driver_wrapper_cipher_modeSelectEnc(alg, &mode);
        if (NULL == mode)
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }

        uint8_t tempIV[16] = {0u};
        operation->default_iv_length = (1u == operation->iv_required) ? MCUXCLAES_BLOCK_SIZE : 0u;
        //operation->iv_set = 0u;

        /* Key buffer for the CPU workarea in memory. */
        uint32_t cpuWorkarea[MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE_IN_WORDS];

        /* Create session */
        mcuxClSession_Descriptor_t session;

        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(&session, cpuWorkarea, MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE, NULL, 0u));

        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Do the encryption */
        mcuxClPsaDriver_ClnsData_Cipher_t * pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClCipher_init(&session, (mcuxClCipher_Context_t *) &pClnsCipherData->ctx, keyDesc, mode, tempIV, operation->default_iv_length));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_init) != token) || (MCUXCLCIPHER_STATUS_OK != result))
        {
            return PSA_ERROR_GENERIC_ERROR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Destroy the session */
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(&session));

        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
        {
            return PSA_ERROR_CORRUPTION_DETECTED;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();

        /* Return with success */
        return PSA_SUCCESS;
    }
    else{
        return PSA_ERROR_NOT_SUPPORTED;
    }
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt_setup(
    els_pkc_cipher_operation_t  *operation,
    const psa_key_attributes_t * attributes,
    const uint8_t * key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    // The driver handles multiple storage locations, call it first then default to builtin driver
    /* Create the key */
    mcuxClPsaDriver_ClnsData_Cipher_t * pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);
    mcuxClKey_Descriptor_t *keyDesc = &pClnsCipherData->keydesc;
    psa_status_t keyStatus = mcuxClPsaDriver_psa_driver_wrapper_createClKey(attributes, key_buffer, key_buffer_size, keyDesc);
    if(PSA_SUCCESS != keyStatus)
    {
        return keyStatus;
    }
    status = mcuxClPsaDriver_psa_driver_wrapper_cipher_encrypt_setup_internal(operation,
					                                                         keyDesc,
					                                                         alg);

    keyStatus = mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusSuspend(keyDesc);
    if(PSA_SUCCESS !=  keyStatus)
    {
        return keyStatus;
    }

    return status;
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_finish(
    els_pkc_cipher_operation_t  *operation,
    uint8_t *output,
    size_t output_size,
    size_t *output_length)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    /* check for invalid input based upon following rule
       inLength needs to be a multiple of the granularity, if this is not the case, return an error. */
    mcuxClPsaDriver_ClnsData_Cipher_t * pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);
    mcuxClCipherModes_Context_Aes_Els_t  *const pContext = &pClnsCipherData->ctx;
    const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t *pAlgo = pContext->common.pMode->pAlgorithm;
    if((pContext->common.blockBufferUsed % pAlgo->granularity) != 0u)
    {
        return (PSA_ERROR_INVALID_ARGUMENT);
    }

    /* Key buffer for the CPU workarea in memory. */
    uint32_t cpuWorkarea[MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE/sizeof(uint32_t)];

    /* Create session */
    mcuxClSession_Descriptor_t session;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(&session, cpuWorkarea, MCUXCLPSA_MAX_CIPHER_CPUWA_SIZE, NULL, 0u));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Initialize the PRNG */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(&session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /*not used*/
    (void)output_size;

    mcuxClKey_Descriptor_t *keyDesc = &pClnsCipherData->keydesc;
    if(PSA_SUCCESS !=  mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusResume(keyDesc))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    uint32_t output_length_tmp = 0u;

    /* Do the encryption */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClCipher_finish(&session, (mcuxClCipher_Context_t *) &pClnsCipherData->ctx, output, &output_length_tmp));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
    *output_length = (size_t)output_length_tmp;
    if(PSA_SUCCESS !=  mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusUnload(keyDesc))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_finish) != token) || (MCUXCLCIPHER_STATUS_OK != result))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(&session));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();
    /* Return with success */
    return PSA_SUCCESS;
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_set_iv(
    els_pkc_cipher_operation_t  *operation,
    const uint8_t *iv_data,
    size_t iv_length )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    //operation->iv_set = 1u;

    /* check if input iv_length is less than default iv length, then the argument is invalid */
    if (operation->default_iv_length > iv_length)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    mcuxClPsaDriver_ClnsData_Cipher_t * pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);
    uint8_t *pIvState = (uint8_t *) pClnsCipherData->ctx.ivState;
    for (uint32_t i = 0u; i < iv_length; ++i)
    {
        pIvState[i] = iv_data[i];
    }

    return PSA_SUCCESS;
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_cipher_update(
    els_pkc_cipher_operation_t  *operation,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    size_t expected_output_size;

    expected_output_size = output_size == 0u ? output_size : input_length;

    /* Potential check for small output buffer size*/
    if( output_size < expected_output_size )
    {
        return( PSA_ERROR_BUFFER_TOO_SMALL );
    }

    mcuxClPsaDriver_ClnsData_Cipher_t *pClnsCipherData = mcuxClPsaDriver_getClnsData_cipherType(operation);

    size_t total_length = input_length + pClnsCipherData->ctx.common.blockBufferUsed;

    /* Adding check if output buffer is big enough to hold all data from input + intermediate data in context to prevent buffer overflow. */
    if (total_length >= MCUXCLAES_BLOCK_SIZE)
    {
        if (output_size / MCUXCLAES_BLOCK_SIZE < total_length / MCUXCLAES_BLOCK_SIZE)
        {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
    }
    
    /* Key buffer for the CPU workarea in memory. */
    uint32_t cpuWorkarea[MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE_IN_WORDS];

    /* Create session */
    mcuxClSession_Descriptor_t session;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(&session, cpuWorkarea, MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE, NULL, 0u));

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* not used */
    (void)output_size;

    mcuxClKey_Descriptor_t *keyDesc = &pClnsCipherData->keydesc;
    if(PSA_SUCCESS !=  mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusResume(keyDesc))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    uint32_t output_length_tmp = 0u;

    /* Do the encryption */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClCipher_process(&session, (mcuxClCipher_Context_t *) &pClnsCipherData->ctx, input, input_length, output, &output_length_tmp));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    *output_length = (size_t)output_length_tmp;

    if(PSA_SUCCESS !=  mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusSuspend(keyDesc))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }

    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipher_process) != token) || (MCUXCLCIPHER_STATUS_OK != result))
    {
        return PSA_ERROR_GENERIC_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(&session));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();
    /* Return with success */
    return PSA_SUCCESS;
}
