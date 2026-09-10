/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

/** @file  mcuxClHMac_Sw.c
 *  @brief Implementation of SW engine functions for the HMAC component */

#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClMac.h>
#include <mcuxClSession.h>
#include <mcuxClMemory.h>
#include <mcuxClKey.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHmac_Internal_Functions.h>
#include <internal/mcuxClHmac_Internal_Types.h>
#include <internal/mcuxClHmac_Core_Functions_Sw.h>

#define MCUXCLMAC_HMAC_IPAD_BYTE (0x36u)
#define MCUXCLMAC_HMAC_OPAD_BYTE (0x5cu)

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_Engine_Init_Sw, mcuxClHmac_InitEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_Engine_Init_Sw(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Generic_t * const pContext)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_Engine_Init_Sw);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC context types")
    mcuxClHmac_Context_Sw_t * const pCtxSw = (mcuxClHmac_Context_Sw_t *) pContext;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pCtxSw is of the right type (mcuxClHmac_Context_Sw_t * const)")
    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = ((mcuxClHmac_ModeDescriptor_t *) (pCtxSw->common.pMode->pCustom))->hashAlgorithm;
    mcuxClKey_Descriptor_t * key = pCtxSw->key;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    const uint32_t hashBlockSize = hashAlgo->blockSize;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hashBlockSize, 0u, MCUXCLHASH_BLOCK_SIZE_MAX, MCUXCLMAC_STATUS_FAULT_ATTACK)

    uint32_t keySize = mcuxClKey_getSize(key);
    uint8_t *pKeyData = mcuxClKey_getKeyData(key);
    size_t alreadyFilledKeyDataSize = 0u;
    uint32_t *pPreparedHmacKey = mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashBlockSize));
    if(NULL == pPreparedHmacKey)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Init_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /*********************************************************************************************************/
    /* Prepare a block-sized key from the key given in the Hmac context (pContext) and store it in work area */
    /*********************************************************************************************************/
    if(keySize > hashBlockSize) /* key is too long */
    {
        MCUXCLBUFFER_INIT_RO(pKeyDataBuf, session, pKeyData, keySize);
        MCUXCLBUFFER_INIT_RW(pPreparedHmacKeyBuf, session, (uint8_t *)pPreparedHmacKey, hashBlockSize);
        uint32_t hashOutputSize = 0u;
        /* Given key must be hashed and then zero-padded up to hashBlockSize */
        MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_compute, mcuxClHash_compute(session,
                                                                hashAlgo,
                                                                pKeyDataBuf,
                                                                keySize,
                                                                pPreparedHmacKeyBuf,
                                                                &hashOutputSize));

        if(MCUXCLHASH_STATUS_OK != result_Hash_compute)
        {
            /* Free workarea (pPreparedHmacKey) */
            mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashBlockSize));
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Init_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
        }
        alreadyFilledKeyDataSize = hashAlgo->hashSize;
    }
    else /* key is not too long */
    {
        /* Given key must be zero-padded up to hashBlockSize */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pPreparedHmacKey,
                                                               pKeyData,
                                                               keySize,
                                                               hashBlockSize);
        alreadyFilledKeyDataSize = keySize;
    }

    /* Zero-pad the key */
    MCUXCLMEMORY_FP_MEMORY_SET((uint8_t *)pPreparedHmacKey + alreadyFilledKeyDataSize, 0u, hashBlockSize - alreadyFilledKeyDataSize);

    /***************************************************************************************************************/
    /* Store the prepared block-sized key in the Hmac context for later use in the outer hash during finalization  */
    /***************************************************************************************************************/

    MCUXCLMEMORY_FP_MEMORY_COPY(pCtxSw->preparedHmacKey, pPreparedHmacKey, hashBlockSize);

    /********************************************************************/
    /* Initialize a Hash context for multipart within the Hmac context  */
    /********************************************************************/
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    pCtxSw->hashCtx = (mcuxClHash_Context_t) &(pCtxSw->hashContextBuffer); /* The content of the hash context is stored in the Hmac context */
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_init, mcuxClHash_init(
    /* mcuxCLSession_Handle_t session: */ session,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer is of the right type (mcuxClHash_Context_t *)")
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    /* mcuxClHash_Algo_t  algorithm:   */ hashAlgo
    ));
    if(MCUXCLHASH_STATUS_OK != result_Hash_init)
    {
        /* Free workarea (pPreparedHmacKey) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashBlockSize));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Init_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /*****************************************************************************************************************/
    /* XOR the ipad to the block-sized key in the work area and Hash-process it (the first block of the inner hash)  */
    /*****************************************************************************************************************/
    for(size_t i = 0u; i < hashBlockSize; i++ )
    {
        ((uint8_t *)pPreparedHmacKey)[i] ^= MCUXCLMAC_HMAC_IPAD_BYTE;
    }

    MCUXCLBUFFER_INIT_RO(pPreparedHmacKeyInBuf, session, pPreparedHmacKey, hashBlockSize);
    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_process, mcuxClHash_process(
    /* mcuxCLSession_Handle_t session: */ session,
MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("hashCTX is initialized by internal trusted function")
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
    /* mcuxCl_InputBuffer_t in:        */ pPreparedHmacKeyInBuf,
    /* uint32_t inSize:               */ hashBlockSize
    ));
    if(MCUXCLHASH_STATUS_OK != result_Hash_process)
    {
        /* Free workarea (pPreparedHmacKey) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashBlockSize));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Init_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /* Free workarea (pPreparedHmacKey) */
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashBlockSize));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Init_Sw, MCUXCLMAC_STATUS_OK,
          MCUX_CSSL_FP_CONDITIONAL((keySize <= hashBlockSize),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
          ),
          MCUX_CSSL_FP_CONDITIONAL((keySize > hashBlockSize),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute)
          ),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_Engine_Update_Sw, mcuxClHmac_UpdateEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_Engine_Update_Sw(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Generic_t * const pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_Engine_Update_Sw);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC context types")
    mcuxClHmac_Context_Sw_t * const pCtxSw = (mcuxClHmac_Context_Sw_t *) pContext;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()

    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_process, mcuxClHash_process(
    /* mcuxCLSession_Handle_t session: */ session,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("hashCTX is initialized by internal trusted function")
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pCtxSw is of the right type (mcuxClHmac_Context_Sw_t * const)")
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
    /* mcuxCl_InputBuffer_t in:        */ pIn,
    /* uint32_t inSize:               */ inLength
    ));
    if(MCUXCLHASH_STATUS_OK != result_Hash_process)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Update_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Update_Sw, MCUXCLMAC_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_Engine_Finalize_Sw, mcuxClHmac_FinalizeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_Engine_Finalize_Sw(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Generic_t * const pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_Engine_Finalize_Sw);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC context types")
    mcuxClHmac_Context_Sw_t * const pCtxSw = (mcuxClHmac_Context_Sw_t *) pContext;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pCtxSw is of the right type (mcuxClHmac_Context_Sw_t * const)")
    const mcuxClHash_AlgorithmDescriptor_t *hashAlgo = ((mcuxClHmac_ModeDescriptor_t *) (pCtxSw->common.pMode->pCustom))->hashAlgorithm;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    const uint32_t hashSize = hashAlgo->hashSize;
    const uint32_t hashBlockSize = hashAlgo->blockSize;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hashSize, 0u, MCUXCLHASH_MAX_OUTPUT_SIZE, MCUXCLMAC_STATUS_FAULT_ATTACK)

    /****************************************************************************************************************************************/
    /* Finalize the inner hash by calling Hash-finalize with the Hash context stored in the Hmac context and write the digest to work area  */
    /****************************************************************************************************************************************/

    uint32_t *pInnerHash = mcuxClSession_allocateWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashSize));
    if(NULL == pInnerHash)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Finalize_Sw, MCUXCLMAC_STATUS_ERROR);
    }

    uint32_t hashOutputSize = 0u;

    MCUXCLBUFFER_INIT_RW(pInnerHashOutBuf, session, (uint8_t *)pInnerHash, hashSize);
    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_finish_1, mcuxClHash_finish(
    /* mcuxCLSession_Handle_t session: */ session,
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
    /* mcuxCl_Buffer_t pOut            */ pInnerHashOutBuf,
    /* uint32_t *const pOutSize,      */ &hashOutputSize
    ));
    if((hashOutputSize != hashSize) || (MCUXCLHASH_STATUS_OK != result_Hash_finish_1))
    {
        /* Free workarea (pInnerHash) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashSize));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Finalize_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /**********************************************************************/
    /* Initialize a new Hash context (re-using the old context's memory)  */
    /**********************************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_init, mcuxClHash_init(
    /* mcuxCLSession_Handle_t session: */ session,
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
    /* mcuxClHash_Algo_t  algorithm:   */ hashAlgo
    ));
    if(MCUXCLHASH_STATUS_OK != result_Hash_init)
    {
        /* Free workarea (pInnerHash) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashSize));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Finalize_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /***********************************************************************************************************************************/
    /* XOR the opad to the block-sized key that is stored in the Hmac context and Hash-process it (the first block of the outer hash)  */
    /***********************************************************************************************************************************/

    uint8_t *pKeyData = (uint8_t *) pCtxSw->preparedHmacKey;

    for(size_t i = 0u; i < hashBlockSize; i++ )
    {
        pKeyData[i] ^= MCUXCLMAC_HMAC_OPAD_BYTE;
    }

    MCUXCLBUFFER_INIT_RO(pKeyDataBuf, session, pKeyData, hashBlockSize);
    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_process_1, mcuxClHash_process(
    /* mcuxCLSession_Handle_t session: */ session,
MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("hashCTX is initialized by internal trusted function")
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
    /* mcuxCl_InputBuffer_t in:        */ pKeyDataBuf,
    /* uint32_t inSize:               */ hashBlockSize
    ));
    if(MCUXCLHASH_STATUS_OK != result_Hash_process_1)
    {
        /* Free workarea (pInnerHash) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashSize));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Finalize_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /********************************************************************************/
    /* Hash-process the digest from before, residing in work area (the inner hash)  */
    /********************************************************************************/

    MCUXCLBUFFER_INIT_RO(pInnerHashInBuf, session, pInnerHash, hashSize);
    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_process_2, mcuxClHash_process(
    /* mcuxCLSession_Handle_t session: */ session,
MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("hashCTX is initialized by internal trusted function")
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
    /* mcuxCl_InputBuffer_t in:        */ pInnerHashInBuf,
    /* uint32_t inSize:               */ hashSize
    ));
    if(MCUXCLHASH_STATUS_OK != result_Hash_process_2)
    {
        /* Free workarea (pInnerHash) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashSize));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Finalize_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /**********************************************************************************************************************/
    /* Finalize the outer hash by calling Hash-finalize, write the resulting digest to pOut and its length to pOutLength  */
    /**********************************************************************************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL(result_Hash_finish_2, mcuxClHash_finish(
    /* mcuxCLSession_Handle_t session: */ session,
MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("hashCTX is initialized by internal trusted function")
    /* mcuxClHash_Context_t context:   */ pCtxSw->hashCtx,
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
    /* mcuxCl_Buffer_t pOut            */ pOut,
    /* uint32_t *const pOutSize,      */ pOutLength
    ));
    if((*pOutLength != hashSize) || (MCUXCLHASH_STATUS_OK != result_Hash_finish_2))
    {
        /* Free workarea (pInnerHash) */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashSize));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Finalize_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    /* Free workarea (pInnerHash) */
    mcuxClSession_freeWords_cpuWa(session, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(hashSize));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Finalize_Sw, MCUXCLMAC_STATUS_OK,
            2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),
            2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_Engine_Oneshot_Sw, mcuxClHmac_ComputeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_Engine_Oneshot_Sw(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Generic_t * const pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutLength)
{
    /* [Design]
    - TODO: In my opinion, we cannot save much when doing Hmac_Oneshot except for the storing of the block-sized key in context.
            We could oneshot the outer hash instead of multipart (with just two parts), but we have a hash context from the
            inner hash anyway, so we can just as well re-use that.
            So it's probably easiest to just call Hmac_Init, Hmac_Update, Hmac_Finalize here.
            Otherwise, here's the slightly optimized design, leaving out the key-storing:

    - Prepare a block-sized key from the key given in the Hmac context (pContext) and store it in work area
      - If keySize > blockSize
        - Hash the key in OneShot
        - Append the digest with (blockSize - digestSize) zero bytes such that it fills one hash block
      - Else just append the key with (blockSize - keySize) zero bytes such that it fills one hash block
    - Initialize a Hash context for multipart
    - XOR the ipad to the block-sized key in the work area and Hash-process it (the first block of the inner hash)
    - Hash-process the input pIn with length inLength using the Hash context
    - Finalize the inner hash by calling Hash-finalize with the Hash context and write the digest to work area
    - Initialize a new Hash context (re-using the old context's memory)
    - XOR ipad^opad (to remove the ipad from before) to the block-sized key in the work area and Hash-process it (the first block of the outer hash)
    - Hash-process the digest from before (the inner hash)
    - Finalize the outer hash by calling Hash-finalize, write the resulting digest to pOut and its length to pOutLength
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_Engine_Oneshot_Sw);

    MCUX_CSSL_FP_FUNCTION_CALL(result_HMAC_init, mcuxClHmac_Engine_Init_Sw(
            session,
            pContext
    ));
    if(MCUXCLMAC_STATUS_OK != result_HMAC_init)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Oneshot_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(result_HMAC_update, mcuxClHmac_Engine_Update_Sw(
            session,
            pContext,
            pIn,
            inLength
    ));
    if(MCUXCLMAC_STATUS_OK != result_HMAC_update)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Oneshot_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(result_HMAC_finalize, mcuxClHmac_Engine_Finalize_Sw(
            session,
            pContext,
            pOut,
            pOutLength
    ));
    if(MCUXCLMAC_STATUS_OK != result_HMAC_finalize)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Oneshot_Sw, MCUXCLMAC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_Engine_Oneshot_Sw, MCUXCLMAC_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_Engine_Init_Sw),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_Engine_Update_Sw),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_Engine_Finalize_Sw));
}

const mcuxClHmac_AlgorithmDescriptor_t mcuxClHmac_AlgorithmDescriptor_Sw = {
    .engineInit = mcuxClHmac_Engine_Init_Sw,
    .protectionToken_engineInit = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_Engine_Init_Sw),
    .engineUpdate = mcuxClHmac_Engine_Update_Sw,
    .protectionToken_engineUpdate = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_Engine_Update_Sw),
    .engineFinalize = mcuxClHmac_Engine_Finalize_Sw,
    .protectionToken_engineFinalize = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_Engine_Finalize_Sw),
    .engineOneshot = mcuxClHmac_Engine_Oneshot_Sw,
    .protectionToken_engineOneshot = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHmac_Engine_Oneshot_Sw),
    .addPadding = NULL,
};
