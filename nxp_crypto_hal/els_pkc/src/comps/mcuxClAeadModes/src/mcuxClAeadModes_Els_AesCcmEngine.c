/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClAeadModes_Els_AesCcmEngine.c
 *  @brief implementation of the AES CCM Engine functions of the mcuxClAeadModes component */

#include <mcuxClToolchain.h>
#include <mcuxClAead.h>
#include <internal/mcuxClAeadModes_Common.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>
#include <mcuxCsslMemory.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEls.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>


/**
 * @brief AES CCM authentication engine function.
 *
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[out]      pOut              Pointer to output.
 * @param[in]       options           Options is a bitmask with one bit reserved for each of the operations
 * @param[in]       pCmacOpt          Pointer to command option bit field for #mcuxClEls_Cmac_Async
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesCcmEls_Auth)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesCcmEls_Auth(
  mcuxClAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t options,
  mcuxClEls_CmacOption_t *pCmacOpt)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesCcmEls_Auth);

    mcuxClEls_KeyIndex_t keyIdx = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(pContext->key);
    uint8_t const * pKey = mcuxClKey_getLoadedKeyData(pContext->key);
    uint32_t keyLength = mcuxClKey_getSize(pContext->key);
    const uint32_t direction = pContext->common.mode->algorithm->direction;

    if((options == MCUXCLAEADMODES_ENGINE_OPTION_AEAD) && (MCUXCLELS_AEAD_DECRYPT == direction))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(cmacResult, mcuxClEls_Cmac_Async(*pCmacOpt,
                                                                    keyIdx,
                                                                    pKey,
                                                                    keyLength,
                                                                    pOut,
                                                                    inLength,
                                                                    pContext->state));

        if( MCUXCLELS_STATUS_OK_WAIT != cmacResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Auth, MCUXCLAEAD_STATUS_ERROR);
        }
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_CALL(cmacResult, mcuxClEls_Cmac_Async(*pCmacOpt,
                                                                    keyIdx,
                                                                    pKey,
                                                                    keyLength,
                                                                    pIn,
                                                                    inLength,
                                                                    pContext->state));
        if( MCUXCLELS_STATUS_OK_WAIT != cmacResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Auth, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    MCUX_CSSL_FP_FUNCTION_CALL(cmacWaitResult, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (MCUXCLELS_STATUS_OK != cmacWaitResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Auth, MCUXCLAEAD_STATUS_ERROR);
    }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress((uint8_t*)pContext->state, MCUXCLELS_CMAC_OUT_SIZE));

    if (MCUXCLELS_STATUS_OK != addressComparisonResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Auth, MCUXCLAEAD_STATUS_ERROR);
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Auth, MCUXCLAEAD_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cmac_Async),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
            MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN);
}


/**
 * @brief AES CCM decryption engine function.
 *
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[out]      pOut              Pointer to output.
 * @param[in]       pCipherElsOpt     Pointer to command option bit field for #mcuxClEls_Cipher_Async
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesCcmEls_Dec)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesCcmEls_Dec(
  mcuxClAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  mcuxClEls_CipherOption_t *pCipherElsOpt)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesCcmEls_Dec);

    mcuxClEls_KeyIndex_t keyIdx = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(pContext->key);
    uint8_t const * pKey = mcuxClKey_getLoadedKeyData(pContext->key);
    uint32_t keyLength = mcuxClKey_getSize(pContext->key);

    MCUX_CSSL_FP_FUNCTION_CALL(ctrRet, mcuxClEls_Cipher_Async(*pCipherElsOpt,
                                                            keyIdx,
                                                            pKey,
                                                            keyLength,
                                                            pIn,
                                                            inLength,
                                                            &pContext->state[48],
                                                            pOut));

    if(MCUXCLELS_STATUS_OK_WAIT != ctrRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Dec, MCUXCLAEAD_STATUS_ERROR,
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cipher_Async));
    }

    MCUX_CSSL_FP_FUNCTION_CALL(ctrWaitRet, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (MCUXCLELS_STATUS_OK != ctrWaitRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Dec, MCUXCLAEAD_STATUS_ERROR,
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cipher_Async),
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation));
    }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK

    MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress(&pContext->state[48], MCUXCLELS_CMAC_OUT_SIZE));

    if (MCUXCLELS_STATUS_OK != addressComparisonResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Dec, MCUXCLAEAD_STATUS_ERROR);
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Dec, MCUXCLAEAD_STATUS_OK,
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cipher_Async),
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
                                        MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN);
}


/**
 * @brief AES CCM encryption engine function.
 *
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[out]      pOut              Pointer to output.
 * @param[in]       pCipherElsOpt     Pointer to command option bit field for #mcuxClEls_Cipher_Async
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesCcmEls_Enc)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesCcmEls_Enc(
  mcuxClAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  mcuxClEls_CipherOption_t *pCipherElsOpt)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesCcmEls_Enc);

    mcuxClEls_KeyIndex_t keyIdx = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(pContext->key);
    uint8_t const * pKey = mcuxClKey_getLoadedKeyData(pContext->key);
    uint32_t keyLength = mcuxClKey_getSize(pContext->key);

    MCUX_CSSL_FP_FUNCTION_CALL(ctrRet, mcuxClEls_Cipher_Async(*pCipherElsOpt,
                                                            keyIdx,
                                                            pKey,
                                                            keyLength,
                                                            pIn,
                                                            inLength,
                                                            &pContext->state[48],
                                                            pOut));

    if(MCUXCLELS_STATUS_OK_WAIT != ctrRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Enc, MCUXCLAEAD_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(ctrWaitRet, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (MCUXCLELS_STATUS_OK != ctrWaitRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Enc, MCUXCLAEAD_STATUS_ERROR);
    }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress(&pContext->state[48], MCUXCLELS_CMAC_OUT_SIZE));

    if (MCUXCLELS_STATUS_OK != addressComparisonResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Enc, MCUXCLAEAD_STATUS_ERROR);
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls_Enc, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Cipher_Async),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
        MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN);
}

/**
 * @brief AES CCM engine function.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[out]      pOut              Pointer to output.
 * @param[out]      pOutLength        Pointer to output length.
 * @param[in]       options           Options is a bitmask with one bit reserved for each of the operations
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesCcmEls)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesCcmEls(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  uint32_t options
  )
{
    /* [Design]

        - Note:
            - options is a bitmask:  1: auth, 2: enc, 3: aead, 4: init, 8: finish
            - processing is done in this particular order such that in-place encryption/decryption is supported

        - Preconditions
            - mode in context has been initialized
            - inLength is a multiple of the block size (16 bytes)

        - Initialization
            - set pData equal to pIn

        - Decryption  (options == enc / aead AND direction = decryption)
            - set pData equal to pOut
            - use ELS in CTR mode to decrypt the data pIn and store the output at pOut

        - Authentication (options == auth / aead)
            - use ELS in CBC-MAC mode to update the state in the context with the contents of pData

        - Encryption  (options == enc / aead AND direction = encryption)
            - use ELS in CTR mode to encrypt the data pIn and store the output at pOut

        - exit
    */

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesCcmEls);
    const uint32_t direction = pContext->common.mode->algorithm->direction;

    /* Initialize ELS CMAC options. */
    mcuxClEls_CmacOption_t cmacOpt;
    cmacOpt.bits.initialize = MCUXCLELS_CMAC_INITIALIZE_DISABLE;
    cmacOpt.bits.finalize = MCUXCLELS_CMAC_FINALIZE_DISABLE;

    /* Initialize ELS Cipher options. */
    mcuxClEls_CipherOption_t cipherElsOpt;
    cipherElsOpt.word.value = 0u;
    cipherElsOpt.bits.dcrpt  = MCUXCLELS_CIPHER_ENCRYPT;
    cipherElsOpt.bits.cphmde = MCUXCLELS_CIPHERPARAM_ALGORITHM_AES_CTR;
    cipherElsOpt.bits.cphsoe = MCUXCLELS_CIPHER_STATE_OUT_ENABLE;
    #ifndef MCUXCL_FEATURE_ELS_NO_INTERNAL_STATE_FLAGS
    cipherElsOpt.bits.cphsie = MCUXCLELS_CIPHER_STATE_IN_ENABLE;
    #endif /* MCUXCL_FEATURE_ELS_NO_INTERNAL_STATE_FLAGS */

    // Get key location
    if(MCUXCLKEY_LOADSTATUS_MEMORY == mcuxClKey_getLoadStatus(pContext->key))
    {
        cmacOpt.bits.extkey = MCUXCLELS_CMAC_EXTERNAL_KEY_ENABLE;
        cipherElsOpt.bits.extkey = MCUXCLELS_CIPHER_EXTERNAL_KEY;
    }
    else if(MCUXCLKEY_LOADSTATUS_COPRO == mcuxClKey_getLoadStatus(pContext->key))
    {
        cmacOpt.bits.extkey = MCUXCLELS_CMAC_EXTERNAL_KEY_DISABLE;
        cipherElsOpt.bits.extkey = MCUXCLELS_CIPHER_INTERNAL_KEY;
    }
    else
    {
        // Error: no key loaded
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls, MCUXCLAEAD_STATUS_ERROR);
    }

    if(((options & MCUXCLAEADMODES_ENGINE_OPTION_ENC) == MCUXCLAEADMODES_ENGINE_OPTION_ENC)
        && (MCUXCLELS_AEAD_DECRYPT == direction))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(decRet, mcuxClAeadModes_EngineAesCcmEls_Dec(
            pContext,
            pIn,
            inLength,
            pOut,
            &cipherElsOpt));

        if (MCUXCLAEAD_STATUS_OK != decRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    if((options & MCUXCLAEADMODES_ENGINE_OPTION_AUTH) == MCUXCLAEADMODES_ENGINE_OPTION_AUTH)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(authRet, mcuxClAeadModes_EngineAesCcmEls_Auth(
            pContext,
            pIn,
            inLength,
            pOut,
            options,
            &cmacOpt));

        if(MCUXCLAEAD_STATUS_OK != authRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    if(((options & MCUXCLAEADMODES_ENGINE_OPTION_ENC) == MCUXCLAEADMODES_ENGINE_OPTION_ENC)
      && (MCUXCLELS_AEAD_ENCRYPT == direction))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(encRet, mcuxClAeadModes_EngineAesCcmEls_Enc(
            pContext,
            pIn,
            inLength,
            pOut,
            &cipherElsOpt));

        if (MCUXCLAEAD_STATUS_OK != encRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    /* Exit and balance the flow protection. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesCcmEls, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_ENGINE_OPTION_ENC) == MCUXCLAEADMODES_ENGINE_OPTION_ENC),
            MCUX_CSSL_FP_CONDITIONAL(MCUXCLELS_AEAD_DECRYPT == direction, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesCcmEls_Dec)),
            MCUX_CSSL_FP_CONDITIONAL(MCUXCLELS_AEAD_ENCRYPT == direction, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesCcmEls_Enc))
        ),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_ENGINE_OPTION_AUTH) == MCUXCLAEADMODES_ENGINE_OPTION_AUTH),
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesCcmEls_Auth)
        )
    );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClAeadModes_AlgorithmDescriptor_t mcuxClAeadModes_AlgorithmDescriptor_Aes_Ccm_enc = {
    .pSkeleton = mcuxClAeadModes_SkeletonAesCcm,
    .pEngine = mcuxClAeadModes_EngineAesCcmEls,
    .protection_token_skeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm),
    .protection_token_engine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesCcmEls),
    .direction = MCUXCLELS_AEAD_ENCRYPT
};

const mcuxClAeadModes_AlgorithmDescriptor_t mcuxClAeadModes_AlgorithmDescriptor_Aes_Ccm_dec = {
    .pSkeleton = mcuxClAeadModes_SkeletonAesCcm,
    .pEngine = mcuxClAeadModes_EngineAesCcmEls,
    .protection_token_skeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm),
    .protection_token_engine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesCcmEls),
    .direction = MCUXCLELS_AEAD_DECRYPT
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
