/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

/** @file  mcuxClAeadModes_Els_AesGcmEngine.c
 *  @brief implementation of the AES GCM Engine functions of the mcuxClAeadModes component */

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
#include <mcuxClAes.h>
#include <internal/mcuxClBuffer_Internal.h>

/**
 * @brief AES GCM engine initialization function.
 *
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[in]       options           Options is a bitmask with one bit reserved for each of the operations
 * @param[in]       pElsOptions       Pointer to command option bit field for #mcuxClEls_Aead_Init_Async,
 *                                    #mcuxClEls_Aead_UpdateAad_Async, #mcuxClEls_Aead_UpdateData_Async
 *                                    and #mcuxClEls_Aead_Finalize_Async
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesGcmEls_Init)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesGcmEls_Init(
  mcuxClAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t options,
  mcuxClEls_AeadOption_t *pElsOptions
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesGcmEls_Init);

    mcuxClEls_KeyIndex_t keyIdx = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(pContext->key);
    uint8_t const * pKey = mcuxClKey_getLoadedKeyData(pContext->key);
    uint32_t keyLength = mcuxClKey_getSize(pContext->key);

    if((options & MCUXCLAEADMODES_ENGINE_OPTION_IV_MASK) == MCUXCLAEADMODES_ENGINE_OPTION_IV_FINAL)
    {
        /* Disable state input for one-time init */
        pElsOptions->bits.acpsie = (uint8_t)MCUXCLELS_AEAD_STATE_IN_DISABLE;

        MCUX_CSSL_FP_FUNCTION_CALL(retInit, mcuxClEls_Aead_Init_Async(*pElsOptions,
                                                                    keyIdx,
                                                                    pKey,
                                                                    keyLength,
                                                                    pIn,
                                                                    inLength,
                                                                    pContext->state));

        if (MCUXCLELS_STATUS_OK_WAIT != retInit)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Init, MCUXCLAEAD_STATUS_ERROR);
        }
        MCUX_CSSL_FP_FUNCTION_CALL(ivWaitRet, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
        MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress((uint8_t*)pContext->state, MCUXCLAEADMODES_DMA_STEP));

        if (MCUXCLELS_STATUS_OK != addressComparisonResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Init, MCUXCLAEAD_STATUS_ERROR);
        }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

        if (MCUXCLELS_STATUS_OK != ivWaitRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Init, MCUXCLAEAD_STATUS_ERROR);
        }
    }
    else
    {
        if((options & MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_START) == MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_START)
        {
            /* Disable state input for first partial init */
            pElsOptions->bits.acpsie = (uint8_t)MCUXCLELS_AEAD_STATE_IN_DISABLE;
        }

        if((options & MCUXCLAEADMODES_ENGINE_OPTION_IV_FINAL) == MCUXCLAEADMODES_ENGINE_OPTION_IV_FINAL)
        {
            /* Enable lastinit for final partial init */
            MCUX_CSSL_ANALYSIS_START_PATTERN_0U_1U_ARE_UNSIGNED()
            pElsOptions->bits.lastinit = MCUXCLELS_AEAD_LASTINIT_TRUE;
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_0U_1U_ARE_UNSIGNED()
        }

        MCUX_CSSL_FP_FUNCTION_CALL(retInitPartial, mcuxClEls_Aead_PartialInit_Async(*pElsOptions,
                                                                                    keyIdx,
                                                                                    pKey,
                                                                                    keyLength,
                                                                                    pIn,
                                                                                    inLength,
                                                                                    pContext->state));

        if(MCUXCLELS_STATUS_OK_WAIT != retInitPartial)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Init, MCUXCLAEAD_STATUS_ERROR);
        }

        MCUX_CSSL_FP_FUNCTION_CALL(ivWaitRet, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

        if (MCUXCLELS_STATUS_OK != ivWaitRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Init, MCUXCLAEAD_STATUS_ERROR);
        }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
        MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress((uint8_t*)pContext->state, MCUXCLAEADMODES_DMA_STEP));

        if (MCUXCLELS_STATUS_OK != addressComparisonResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Init, MCUXCLAEAD_STATUS_ERROR);
        }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Init, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_ENGINE_OPTION_IV_MASK) == MCUXCLAEADMODES_ENGINE_OPTION_IV_FINAL),
                                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Aead_Init_Async),
                                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
                                                                        MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN
        ),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_START) == MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_START)
                                 || ((options & MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_CONT) == MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_CONT),
                                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Aead_PartialInit_Async),
                                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
                                                                        MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN
        )
    );
}

/**
 * @brief AES GCM engine additional authentication data processing function.
 *
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[in]       pElsOptions       Pointer to command option bit field for #mcuxClEls_Aead_Init_Async,
 *                                    #mcuxClEls_Aead_UpdateAad_Async, #mcuxClEls_Aead_UpdateData_Async
 *                                    and #mcuxClEls_Aead_Finalize_Async
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesGcmEls_Aad)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesGcmEls_Aad(
  mcuxClAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxClEls_AeadOption_t *pElsOptions
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesGcmEls_Aad);

    mcuxClEls_KeyIndex_t keyIdx = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(pContext->key);
    uint8_t const * pKey = mcuxClKey_getLoadedKeyData(pContext->key);
    uint32_t keyLength = mcuxClKey_getSize(pContext->key);

    MCUX_CSSL_FP_FUNCTION_CALL(ret_updateAad, mcuxClEls_Aead_UpdateAad_Async(*pElsOptions,
                                                                            keyIdx,
                                                                            pKey,
                                                                            keyLength,
                                                                            pIn,
                                                                            inLength,
                                                                            pContext->state));

    if (ret_updateAad != MCUXCLELS_STATUS_OK_WAIT)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Aad, MCUXCLAEAD_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(aadWait, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (aadWait != MCUXCLELS_STATUS_OK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Aad, MCUXCLAEAD_STATUS_ERROR);
    }


#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress((uint8_t*)pContext->state  , MCUXCLAEADMODES_DMA_STEP));

    if (MCUXCLELS_STATUS_OK != addressComparisonResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Aad, MCUXCLAEAD_STATUS_ERROR);
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Aad, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Aead_UpdateAad_Async),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
        MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN);
}


/**
 * @brief AES GCM engine data processing function.
 *
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[out]      pOut              Pointer to output.
 * @param[in]       options           Options is a bitmask with one bit reserved for each of the operations
 * @param[in]       pElsOptions       Pointer to command option bit field for #mcuxClEls_Aead_Init_Async,
 *                                    #mcuxClEls_Aead_UpdateAad_Async, #mcuxClEls_Aead_UpdateData_Async
 *                                    and #mcuxClEls_Aead_Finalize_Async
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesGcmEls_Data)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesGcmEls_Data(
  mcuxClAeadModes_Context_t *pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t options,
  mcuxClEls_AeadOption_t *pElsOptions)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesGcmEls_Data);

    mcuxClEls_KeyIndex_t keyIdx = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(pContext->key);
    uint8_t const * pKey = mcuxClKey_getLoadedKeyData(pContext->key);
    uint32_t keyLength = mcuxClKey_getSize(pContext->key);

    if(((options & MCUXCLAEADMODES_ENGINE_OPTION_DATA_FINAL) == MCUXCLAEADMODES_ENGINE_OPTION_DATA_FINAL)
        && (MCUXCLAES_BLOCK_SIZE != pContext->partialDataLength))
    {
        /* Enable special processing for final, partial block */
        pElsOptions->bits.msgendw = (uint8_t)pContext->partialDataLength;
    }

    MCUX_CSSL_FP_FUNCTION_CALL(ret_updateData, mcuxClEls_Aead_UpdateData_Async(*pElsOptions,
                                                                                keyIdx,
                                                                                pKey,
                                                                                keyLength,
                                                                                pIn,
                                                                                inLength,
                                                                                pOut,
                                                                                pContext->state));

    if (ret_updateData != MCUXCLELS_STATUS_OK_WAIT)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Data, MCUXCLAEAD_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(waitData, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (waitData != MCUXCLELS_STATUS_OK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Data, MCUXCLAEAD_STATUS_ERROR);
    }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress((uint8_t*)pContext->state  , MCUXCLAEADMODES_DMA_STEP));

    if (MCUXCLELS_STATUS_OK != addressComparisonResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Data, MCUXCLAEAD_STATUS_ERROR);
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Data, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Aead_UpdateData_Async),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
        MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN);
}


/**
 * @brief AES GCM engine finalization function.
 *
 * @param[in,out]   pContext          Pointer to context.
 * @param[out]      pOut              Pointer to output.
 * @param[in]       pElsOptions       Pointer to command option bit field for #mcuxClEls_Aead_Init_Async,
 *                                    #mcuxClEls_Aead_UpdateAad_Async, #mcuxClEls_Aead_UpdateData_Async
 *                                    and #mcuxClEls_Aead_Finalize_Async
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesGcmEls_Finalize)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesGcmEls_Finalize(
  mcuxClAeadModes_Context_t* pContext,
  mcuxCl_Buffer_t pOut,
  mcuxClEls_AeadOption_t* pElsOptions)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesGcmEls_Finalize);

    mcuxClEls_KeyIndex_t keyIdx = (mcuxClEls_KeyIndex_t) mcuxClKey_getLoadedKeySlot(pContext->key);
    uint8_t const * pKey = mcuxClKey_getLoadedKeyData(pContext->key);
    uint32_t keyLength = mcuxClKey_getSize(pContext->key);

    MCUX_CSSL_FP_FUNCTION_CALL(ret_finish, mcuxClEls_Aead_Finalize_Async(*pElsOptions,
                                                                    keyIdx,
                                                                    pKey,
                                                                    keyLength,
                                                                    pContext->aadLength,
                                                                    pContext->dataLength,
                                                                    pOut,
                                                                    pContext->state));

    if (ret_finish != MCUXCLELS_STATUS_OK_WAIT)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Finalize, MCUXCLAEAD_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(waitFinish, mcuxClEls_WaitForOperation(MCUXCLELS_ERROR_FLAGS_CLEAR));

    if (waitFinish != MCUXCLELS_STATUS_OK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Finalize, MCUXCLAEAD_STATUS_ERROR);
    }

#ifdef MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK
    MCUX_CSSL_FP_FUNCTION_CALL(addressComparisonResult, mcuxClEls_CompareDmaFinalOutputAddress((uint8_t*)pOut  , MCUXCLELS_AEAD_TAG_SIZE));

    if (MCUXCLELS_STATUS_OK != addressComparisonResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Finalize, MCUXCLAEAD_STATUS_ERROR);
    }
#endif /* MCUXCL_FEATURE_ELS_DMA_FINAL_ADDRESS_READBACK */

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls_Finalize, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Aead_Finalize_Async),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_WaitForOperation),
        MCUXCLELS_DMA_READBACK_PROTECTION_TOKEN);
}


/**
 * @brief AES GCM engine function.
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
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_EngineAesGcmEls)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_EngineAesGcmEls (
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
            - options is a bitmask:  1: aad, 2: iv, 4: data, 8: finish

        - Preconditions
            - mode in context has been initialized
            - inLength is a multiple of the block size (16 bytes)

        - IV (options == iv)
            - if(options == finish), the IV final process
            - or use ELS in auth cipher mode initialize stage to create the partial starting counter state J0

        - AAD (options == aad)
            - use ELS in auth cipher mode AAD stage to create the starting tag

        - DATA (options == data)
            - use ELS in auth cipher mode Process message stage to output the processed text to pOut and update the tag to state of Context

        - FINAL  (options == finish)
            - use ELS in auth cipher mode Final stage to create the final tag to pOut

        - exit
    */

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_EngineAesGcmEls);

    /* Initialize ELS options. */
    mcuxClEls_AeadOption_t elsOptions;
    elsOptions.word.value = 0u;
    elsOptions.bits.dcrpt  = (uint8_t)(pContext->common.mode->algorithm->direction & 0xffU);
    elsOptions.bits.acpsie = (uint8_t)MCUXCLELS_AEAD_STATE_IN_ENABLE;
    MCUX_CSSL_ANALYSIS_START_PATTERN_0U_1U_ARE_UNSIGNED()
    elsOptions.bits.lastinit = MCUXCLELS_AEAD_LASTINIT_FALSE;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_0U_1U_ARE_UNSIGNED()

    if (MCUXCLKEY_LOADSTATUS_MEMORY == mcuxClKey_getLoadStatus(pContext->key))
    {
        elsOptions.bits.extkey = MCUXCLELS_CIPHER_EXTERNAL_KEY;
    }
    else if (MCUXCLKEY_LOADSTATUS_COPRO == mcuxClKey_getLoadStatus(pContext->key))
    {
        elsOptions.bits.extkey = MCUXCLELS_CIPHER_INTERNAL_KEY;
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls, MCUXCLAEAD_STATUS_ERROR);
    }

    if(0U != (options & MCUXCLAEADMODES_ENGINE_OPTION_IV_MASK))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(ivRet, mcuxClAeadModes_EngineAesGcmEls_Init(
            pContext,
            pIn,
            inLength,
            options,
            &elsOptions));

        if (MCUXCLAEAD_STATUS_OK != ivRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    if((options & MCUXCLAEADMODES_ENGINE_OPTION_AAD) == MCUXCLAEADMODES_ENGINE_OPTION_AAD)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(aadRet, mcuxClAeadModes_EngineAesGcmEls_Aad(
            pContext,
            pIn,
            inLength,
            &elsOptions));

        if (MCUXCLAEAD_STATUS_OK != aadRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    if(0U != (options & MCUXCLAEADMODES_ENGINE_OPTION_DATA_MASK))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(dataRet, mcuxClAeadModes_EngineAesGcmEls_Data(
            pContext,
            pIn,
            inLength,
            pOut,
            options,
            &elsOptions));

        if (MCUXCLAEAD_STATUS_OK != dataRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    if((options & MCUXCLAEADMODES_ENGINE_OPTION_FINISH) == MCUXCLAEADMODES_ENGINE_OPTION_FINISH)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(dataRet, mcuxClAeadModes_EngineAesGcmEls_Finalize(
            pContext,
            pOut,
            &elsOptions));

        if (MCUXCLAEAD_STATUS_OK != dataRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    /* Exit and balance the flow protection. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_EngineAesGcmEls, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_ENGINE_OPTION_IV_MASK) != 0U),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesGcmEls_Init)),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_ENGINE_OPTION_AAD) == MCUXCLAEADMODES_ENGINE_OPTION_AAD),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesGcmEls_Aad)),
        MCUX_CSSL_FP_CONDITIONAL((0u != (options & MCUXCLAEADMODES_ENGINE_OPTION_DATA_MASK)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesGcmEls_Data)),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_ENGINE_OPTION_FINISH) == MCUXCLAEADMODES_ENGINE_OPTION_FINISH),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesGcmEls_Finalize))
    );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClAeadModes_AlgorithmDescriptor_t mcuxClAeadModes_AlgorithmDescriptor_Aes_Gcm_enc = {
    .pSkeleton = mcuxClAeadModes_SkeletonAesGcm,
    .pEngine = mcuxClAeadModes_EngineAesGcmEls,
    .protection_token_skeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm),
    .protection_token_engine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesGcmEls),
    .direction = MCUXCLELS_AEAD_ENCRYPT
};

const mcuxClAeadModes_AlgorithmDescriptor_t mcuxClAeadModes_AlgorithmDescriptor_Aes_Gcm_dec = {
    .pSkeleton = mcuxClAeadModes_SkeletonAesGcm,
    .pEngine = mcuxClAeadModes_EngineAesGcmEls,
    .protection_token_skeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm),
    .protection_token_engine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_EngineAesGcmEls),
    .direction = MCUXCLELS_AEAD_DECRYPT
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
