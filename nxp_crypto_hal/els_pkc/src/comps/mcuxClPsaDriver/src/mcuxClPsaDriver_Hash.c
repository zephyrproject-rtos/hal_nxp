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


#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClPsaDriver.h>
#include <mcuxClCipherModes.h>
#include <mcuxClSession.h>
#include <mcuxClMemory_Copy.h>
#include <mcuxClMemory_Clear.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClPsaDriver_Internal.h>
#include <internal/mcuxClPsaDriver_Functions.h>
#include <internal/mcuxClPsaDriver_ExternalMacroWrappers.h>


/** Inline functions for proper type casts*/
static inline mcuxClPsaDriver_ClnsData_Hash_t* mcuxClPsaDriver_getClnsData_hashType(els_pkc_hash_operation_t *operation)
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    return (mcuxClPsaDriver_ClnsData_Hash_t *) operation->clns_data;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

static inline mcuxClPsaDriver_ClnsData_Hash_t* mcuxClPsaDriver_getClnsData_hashType_fromConstOp(const els_pkc_hash_operation_t *operation)
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST("Const is discarded for internal representation, the contents will not be modified.")
    return (mcuxClPsaDriver_ClnsData_Hash_t *) operation->clns_data;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST()
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClHash_AlgorithmDescriptor_t * mcuxClPsaDriver_psa_driver_wrapper_hash_set_algorithmDescriptor(
    psa_algorithm_t alg)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_SWITCH_STATEMENT_RETURN_TERMINATION()
    switch(alg)
    {
    /*  PSA_WANT_ALG_SHA_1 - define providing external SHA1 configurability.
        For customer usage only.
        This flag shall be enabled by build process for CL standalone builds. */
#if defined(PSA_WANT_ALG_SHA_1)
    case PSA_ALG_SHA_1:
        return mcuxClHash_Algorithm_Sha1;
#endif
    case PSA_ALG_SHA_224:
        return mcuxClHash_Algorithm_Sha224;
    case PSA_ALG_SHA_256:
        return mcuxClHash_Algorithm_Sha256;
    case PSA_ALG_SHA_384:
        return mcuxClHash_Algorithm_Sha384;
    case PSA_ALG_SHA_512:
        return mcuxClHash_Algorithm_Sha512;
    case PSA_ALG_SHA_512_224:
        return mcuxClHash_Algorithm_Sha512_224;
    case PSA_ALG_SHA_512_256:
        return mcuxClHash_Algorithm_Sha512_256;
    default:
        return NULL;
    }
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_SWITCH_STATEMENT_RETURN_TERMINATION()
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_setup(
    els_pkc_hash_operation_t *operation,
    psa_algorithm_t alg)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    /* Select algorithm descriptor */
    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = mcuxClPsaDriver_psa_driver_wrapper_hash_set_algorithmDescriptor(alg);

    if(NULL == hashAlgo)
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Initialize the hash operation */
    mcuxClPsaDriver_ClnsData_Hash_t * pClnsHashData = mcuxClPsaDriver_getClnsData_hashType(operation);

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClHash_init(
                    /* mcuxCLSession_Handle_t session: */ NULL,
                    /* mcuxClHash_Context_t context:   */ &pClnsHashData->ctx,
                    /* mcuxClHash_Algo_t  algo:        */ hashAlgo));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init) != token) || (MCUXCLHASH_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return PSA_SUCCESS;
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
 psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_update(
    els_pkc_hash_operation_t *operation,
    const uint8_t *input,
    size_t input_length )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    /* Allocate workarea space */
    uint32_t cpuWorkarea[MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_MAX / sizeof(uint32_t)];
    mcuxClPsaDriver_ClnsData_Hash_t * pClnsHashData = mcuxClPsaDriver_getClnsData_hashType(operation);

    if(pClnsHashData->ctx.algo == NULL)
    {
        return PSA_ERROR_BAD_STATE;
    }

    /* Create session */
    mcuxClSession_Descriptor_t sessionDesc;
    mcuxClSession_Handle_t session = &sessionDesc;

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(
                                                          session,
                                                          cpuWorkarea,
                                                          MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_MAX,
                                                          NULL,
                                                          0u));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Perform the hashing operation */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClHash_process(
                                                          session,
                                                          &pClnsHashData->ctx,
                                                          input,
                                                          input_length));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process) != token) || (MCUXCLHASH_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return PSA_SUCCESS;
}

/*
 * Hashing functions
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_compute(
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *hash_,
    size_t hash_size,
    size_t *hash_length)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    /* Select algorithm descriptor */
    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = mcuxClPsaDriver_psa_driver_wrapper_hash_set_algorithmDescriptor(alg);

    if(NULL == hashAlgo)
    {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Allocate workarea space */
    uint32_t cpuWorkarea[MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_MAX / sizeof(uint32_t)];

    /* Create session */
    mcuxClSession_Descriptor_t sessionDesc;
    mcuxClSession_Handle_t session = &sessionDesc;

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(
                                                          session,
                                                          cpuWorkarea,
                                                          MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_MAX,
                                                          NULL,
                                                          0u));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Check if output buffer has a valid size, otherwise return */
    if(hashAlgo->hashSize > hash_size)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Perform the hashing operation */
    uint32_t hashOutputSize = 0u;
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClHash_compute(
                                                          session,
                                                          hashAlgo,
                                                          input,
                                                          input_length,
                                                          hash_,
                                                          &hashOutputSize));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute) != token) || (MCUXCLHASH_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Update the hash length */
    if(hash_length != NULL) {
        *hash_length = hashAlgo->hashSize;
    }

    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return PSA_SUCCESS;
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_finish(
    els_pkc_hash_operation_t *operation,
    uint8_t *hash_,
    size_t hash_size,
    size_t *hash_length )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    /* Allocate workarea space */
    uint32_t cpuWorkarea[MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_MAX / sizeof(uint32_t)];

    /* Create session */
    mcuxClSession_Descriptor_t sessionDesc;
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Set hash_length and check consistency with Algo->hashSize */
    *hash_length = hash_size;

    /* Set hash_length correctly and check consistency with hash_size */
    mcuxClPsaDriver_ClnsData_Hash_t * pClnsHashData = mcuxClPsaDriver_getClnsData_hashType(operation);

    if(pClnsHashData->ctx.algo->hashSize > hash_size)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Update the actual hashsize from algorithum*/
    *hash_length = pClnsHashData->ctx.algo->hashSize;

    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_init(
                                                      session,
                                                      cpuWorkarea,
                                                      MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_MAX,
                                                      NULL,
                                                      0u));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Perform the hashing operation */
    uint32_t hashOutputSize = 0;
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClHash_finish(
                                                       session,
                                                       &pClnsHashData->ctx,
                                                       hash_,
                                                       &hashOutputSize));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish) != token) || (MCUXCLHASH_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Destroy the session */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(result, token, mcuxClSession_destroy(session));

    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != token) || (MCUXCLSESSION_STATUS_OK != result))
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return PSA_SUCCESS;
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_clone(
    const els_pkc_hash_operation_t *source_operation,
    els_pkc_hash_operation_t *target_operation )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{

    /* Copy content from mcuxClHash_Context_t */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("copy only reads from source")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(tokenCopy1, mcuxClMemory_copy (
                                                    (uint8_t*)target_operation->clns_data,
                                                    (uint8_t*)source_operation->clns_data,
                                                    sizeof(mcuxClHash_ContextDescriptor_t),
                                                    sizeof(mcuxClHash_ContextDescriptor_t)));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy) != tokenCopy1)
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    /* Compute new position and length of buffers
     * Note: This is not compatible with SecSha. */
    mcuxClPsaDriver_ClnsData_Hash_t * pClnsHashDataTarget = mcuxClPsaDriver_getClnsData_hashType(target_operation);
    mcuxClPsaDriver_ClnsData_Hash_t * pClnsHashDataSource = mcuxClPsaDriver_getClnsData_hashType_fromConstOp(source_operation);
    uint32_t *pStateTarget = mcuxClHash_getStatePtr(&pClnsHashDataTarget->ctx);
    uint32_t *pStateSource = mcuxClHash_getStatePtr(&pClnsHashDataSource->ctx);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("stateSize is at most MCUXCLHASH_STATE_SIZE_MAX, blockSize is at most MCUXCLHASH_BLOCK_SIZE_MAX, this cannot wrap.")
    size_t bufferSizes = pClnsHashDataSource->ctx.algo->stateSize + pClnsHashDataSource->ctx.algo->blockSize;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Copy state and unprocessed buffer to target hash operation handle. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(tokenCopy2, mcuxClMemory_copy (
                                                      (uint8_t *) pStateTarget,
                                                      (uint8_t *) pStateSource,
                                                      bufferSizes,
                                                      bufferSizes));
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy) != tokenCopy2)
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    /* Remaining Bytes in source and target behind pUnprocessed are not accessed by hash algorithms, so we do not copy them. */

    return PSA_SUCCESS;
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_hash_abort(
    els_pkc_hash_operation_t *operation )
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    /* Clear hash clns data (context) */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(token, mcuxClMemory_clear (
                                                        (uint8_t*)operation->clns_data,
                                                        MCUXCLPSADRIVER_CLNSDATA_HASH_SIZE,
                                                        MCUXCLPSADRIVER_CLNSDATA_HASH_SIZE));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear) != token)
    {
        return PSA_ERROR_CORRUPTION_DETECTED;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();

    return PSA_SUCCESS;

}


