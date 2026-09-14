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

/** @file  mcuxClAeadModes_Els_AesGcm.c
 *  @brief Implementation of the AES GCM skeleton functions of the mcuxClAeadModes component */

#include <mcuxClAead.h>
#include <internal/mcuxClAeadModes_Els_Types.h>
#include <internal/mcuxClAeadModes_Els_Functions.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxCsslMemory.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEls.h>
#include <internal/mcuxClPadding_Internal.h>
#include <mcuxClAes.h>



/**
 * @brief AES GCM skeleton initialization function.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pNonce            Pointer to nonce.
 * @param[in]       nonceLength       Nonce length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesGcm_Init)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesGcm_Init(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    mcuxCl_InputBuffer_t pNonce,
    uint32_t nonceLength
    )
{
    /*
        - Common IV processing (options == oneshot / init)
            - set partialDataLength in context to zero
            - process IV with ELS and output to state in context
                - if the IV length is not 12 use using pEngine(option:iv) to process the complete blocks
                - partialData can be used to padd the IV since it is not used at this time
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesGcm_Init);
    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;

    uint32_t bytesFullIvBlocks = 0u;

    /* Number of bytes added by the padding. */
    uint32_t padOutLength = 0u;
    pContext->partialDataLength = 0u;

    if (nonceLength != 12u)
    {
        uint32_t engineOptions = MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_START;

        /* If nonce is not 12 bytes, perform a partial init. Start with the full blocks of the IV */
        bytesFullIvBlocks = (nonceLength / MCUXCLAES_BLOCK_SIZE) * MCUXCLAES_BLOCK_SIZE;
        if(0u != bytesFullIvBlocks)
        {
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(retIV, pAlgo->pEngine(session, pContext,
                                                                pNonce,
                                                                bytesFullIvBlocks,
                                                                NULL,
                                                                NULL,
                                                                engineOptions));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != retIV)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Init, MCUXCLAEAD_STATUS_ERROR);
            }

            engineOptions = MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_CONT;
        }

        MCUX_CSSL_FP_FUNCTION_CALL(padResult, mcuxClPadding_addPadding_ISO9797_1_Method1(MCUXCLELS_AEAD_IV_BLOCK_SIZE,
                                                                                        pNonce + bytesFullIvBlocks,
                                                                                        nonceLength - bytesFullIvBlocks,
                                                                                        nonceLength,
                                                                                        pContext->partialData,
                                                                                        &padOutLength));

        if (MCUXCLPADDING_STATUS_OK != padResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Init, MCUXCLAEAD_STATUS_ERROR);
        }

        if(MCUXCLELS_AEAD_IV_BLOCK_SIZE == padOutLength)
        {
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(retIV, pAlgo->pEngine(session, pContext,
                                                                pContext->partialData,
                                                                MCUXCLELS_AEAD_IV_BLOCK_SIZE,
                                                                NULL,
                                                                NULL,
                                                                engineOptions));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != retIV)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Init, MCUXCLAEAD_STATUS_ERROR);
            }

            engineOptions = MCUXCLAEADMODES_ENGINE_OPTION_IV_PARTIAL_CONT;
        }


        MCUXCLMEMORY_FP_MEMORY_SET(pContext->partialData, 0u, MCUXCLELS_AEAD_IV_BLOCK_SIZE);

        /* Set nonce length in bits. */
        pContext->partialData[15] = (uint8_t)((nonceLength <<  3u) & 0xffU);
        pContext->partialData[14] = (uint8_t)((nonceLength >>  5u) & 0xffU);
        pContext->partialData[13] = (uint8_t)((nonceLength >> 13u) & 0xffU);
        pContext->partialData[12] = (uint8_t)((nonceLength >> 21u) & 0xffU);
        pContext->partialData[11] = (uint8_t)((nonceLength >> 29u) & 0xffU);

        /* Finish the nonce initialization. */
        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(retIVFinal, pAlgo->pEngine(session, pContext,
                                                                        pContext->partialData,
                                                                        MCUXCLELS_AEAD_IV_BLOCK_SIZE,
                                                                        NULL,
                                                                        NULL,
                                                                        engineOptions | MCUXCLAEADMODES_ENGINE_OPTION_IV_FINAL));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != retIVFinal)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Init, MCUXCLAEAD_STATUS_ERROR);
        }
    }
    else
    {
        /* Nonce is 12 bytes. Pad the nonce. */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pContext->partialData,
                                                                pNonce,
                                                                12u,
                                                                MCUXCLELS_AEAD_IV_BLOCK_SIZE);

        pContext->partialData[12] = 0x00u;
        pContext->partialData[13] = 0x00u;
        pContext->partialData[14] = 0x00u;
        pContext->partialData[15] = 0x01u;

        /* Do the nonce initialization. */
        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(retIV, pAlgo->pEngine(session, pContext,
                                                                    pContext->partialData,
                                                                    MCUXCLELS_AEAD_IV_BLOCK_SIZE,
                                                                    NULL,
                                                                    NULL,
                                                                    MCUXCLAEADMODES_ENGINE_OPTION_IV_FINAL));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != retIV)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Init, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Init, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((nonceLength != 12u), MCUX_CSSL_FP_CONDITIONAL((0u != bytesFullIvBlocks), pAlgo->protection_token_engine),
                                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method1),
                                                    MCUX_CSSL_FP_CONDITIONAL((MCUXCLELS_AEAD_IV_BLOCK_SIZE == padOutLength), pAlgo->protection_token_engine),
                                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set)
        ),
        MCUX_CSSL_FP_CONDITIONAL((nonceLength == 12u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)),
        pAlgo->protection_token_engine
    );
}


/**
 * @brief AES GCM skeleton function for processing remaining bytes of additional authentication data
 *        which do not form a full block.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pAdata            Pointer to adata.
 * @param[in]       bytesRemainingAad Remaining adata length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesGcm_ProcessAadLastBlock)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesGcm_ProcessAadLastBlock(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    mcuxCl_InputBuffer_t pAdata,
    uint32_t bytesRemainingAad
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesGcm_ProcessAadLastBlock);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;
    if (0u != bytesRemainingAad)
    {
        /* If there is still data in the input, copy it to the partial data buffer for the next iteration. */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pContext->partialData,
            pAdata,
            bytesRemainingAad,
            MCUXCLELS_AEAD_AAD_BLOCK_SIZE);

        pContext->partialDataLength = bytesRemainingAad;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("The caller ensured that pContext->processedDataLength will not overflow by any of the performed additions to it.")
        pContext->processedDataLength += bytesRemainingAad;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }

    //Check if we done all adata and if we have some remaining data in buffer, this is for
    //the last adata block processing, add zero padding and calc
    uint32_t aadProFPFlag = 0U;
    if((pContext->processedDataLength == pContext->aadLength) && (0u != pContext->partialDataLength))
    {
        /* There is still AAD which needs to be zero-padded and processed. */
        MCUXCLMEMORY_FP_MEMORY_SET_WITH_BUFF(pContext->partialData + pContext->partialDataLength, 0u, MCUXCLELS_AEAD_AAD_BLOCK_SIZE - pContext->partialDataLength, MCUXCLELS_AEAD_AAD_BLOCK_SIZE);

        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(retPadAad, pAlgo->pEngine(session, pContext,
                                                                pContext->partialData,
                                                                MCUXCLELS_AEAD_AAD_BLOCK_SIZE,
                                                                NULL,
                                                                NULL,
                                                                MCUXCLAEADMODES_ENGINE_OPTION_AAD));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != retPadAad)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessAadLastBlock, MCUXCLAEAD_STATUS_ERROR);
        }

        aadProFPFlag = 1U;
        pContext->partialDataLength = 0u;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessAadLastBlock, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((bytesRemainingAad != 0u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)),
        MCUX_CSSL_FP_CONDITIONAL(1U == aadProFPFlag,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
            pAlgo->protection_token_engine)
    );
}


/**
 * @brief AES GCM skeleton function for processing additional authentication data.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pAdata            Pointer to adata.
 * @param[in]       adataLength       Adata length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesGcm_ProcessAad)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesGcm_ProcessAad(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    mcuxCl_InputBuffer_t pAdata,
    uint32_t adataLength
    )
{
    /*
        - AAD processing (options == oneshot / update aad)
            - if partialDataLength != 0 add the new data from the input to partialData and process using pEngine(option:aad)
            if possible,adapt partialDataLength and processedDataLength (this will never be the case for oneshot)
            - process remaining complete blocks using pEngine(option:aad) from the input, adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength (this can happen
            for oneshot)
            - [Assertion] aadLength <= processedDataLength
            - if aadLength == processedDataLength padd partialData with zeros and process using pEngine(option:aad), set
            partialDataLength to zero
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesGcm_ProcessAad);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;

    //below variable definitions are used for flow protection of plaintext data process

    uint32_t aadProFPFlag1 = 0u;
    uint32_t aadProFPFlag2 = 0u;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->partialDataLength, 0u, MCUXCLAES_BLOCK_SIZE, MCUXCLAEAD_STATUS_ERROR)

    if ((adataLength > (UINT32_MAX - pContext->partialDataLength))
        || (adataLength > (UINT32_MAX - pContext->processedDataLength)))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessAad, MCUXCLAEAD_STATUS_ERROR);
    }

    /* Number of bytes to possibly copy into the partial data buffer, which is min(free buffer space, new data). */
    uint32_t bytesCopied = 0u;
    uint32_t bytesToCopy = (((MCUXCLELS_AEAD_AAD_BLOCK_SIZE - pContext->partialDataLength) < (adataLength)) ?
                            (MCUXCLELS_AEAD_AAD_BLOCK_SIZE - pContext->partialDataLength) : (adataLength));

    if (pContext->partialDataLength != 0u)
    {
        aadProFPFlag1 = 1u;
        /* Add new data into the partial data buffer and process, if possible. */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pContext->partialData + pContext->partialDataLength,
                                                                pAdata,
                                                                bytesToCopy,
                                                                MCUXCLELS_AEAD_AAD_BLOCK_SIZE);

        /* Update the number of bytes in the partial data buffer. */
        pContext->partialDataLength += bytesToCopy;

        if (MCUXCLELS_AEAD_AAD_BLOCK_SIZE == pContext->partialDataLength)
        {
            aadProFPFlag2 = 1u;
            /* partialData now contains a full block, so process it. */
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(retAad, pAlgo->pEngine(session, pContext,
                                                                pContext->partialData,
                                                                MCUXCLELS_AEAD_AAD_BLOCK_SIZE,
                                                                NULL,
                                                                NULL,
                                                                MCUXCLAEADMODES_ENGINE_OPTION_AAD));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != retAad)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessAad, MCUXCLAEAD_STATUS_ERROR);
            }

            /* The partial data buffer is now empty. */
            pContext->partialDataLength = 0u;

        }

        /* The bytes copied already should not be taken into account further. */
        bytesCopied += bytesToCopy;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("bytesToCopy can't be bigger than adataLength")
        adataLength -= bytesToCopy;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("adataLength > (UINT32_MAX - pContext->processedDataLength) was checked")
        pContext->processedDataLength += bytesToCopy;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    uint32_t bytesRemainingAad = (adataLength / MCUXCLELS_AEAD_AAD_BLOCK_SIZE) * MCUXCLELS_AEAD_AAD_BLOCK_SIZE;
    if(0u != bytesRemainingAad)
    {
        /* Process as many remaining full blocks as possible. */
        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(retBlkAad, pAlgo->pEngine(session, pContext,
                                                                        pAdata + bytesCopied,
                                                                        bytesRemainingAad,
                                                                        NULL,
                                                                        NULL,
                                                                        MCUXCLAEADMODES_ENGINE_OPTION_AAD));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != retBlkAad)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessAad, MCUXCLAEAD_STATUS_ERROR);
        }

        /* The bytes copied already should not be taken into account further. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("bytesCopied will be increased by a maximum of inLength, this cannot wrap.")
        bytesCopied += bytesRemainingAad;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("The caller ensured that pContext->processedDataLength will not overflow by any of the performed additions to it.")
        pContext->processedDataLength += bytesRemainingAad;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }

    bytesRemainingAad = adataLength & (MCUXCLAES_BLOCK_SIZE - 1u);
    MCUX_CSSL_FP_FUNCTION_CALL(retAadLastBlock, mcuxClAeadModes_SkeletonAesGcm_ProcessAadLastBlock(
        session,
        pContext,
        pAdata + bytesCopied,
        bytesRemainingAad)
    );

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessAad, retAadLastBlock,
        MCUX_CSSL_FP_CONDITIONAL((aadProFPFlag1 == 1u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            MCUX_CSSL_FP_CONDITIONAL((aadProFPFlag2 == 1u), pAlgo->protection_token_engine)),
        MCUX_CSSL_FP_CONDITIONAL((0u != ((adataLength / MCUXCLELS_AEAD_AAD_BLOCK_SIZE) * MCUXCLELS_AEAD_AAD_BLOCK_SIZE)), pAlgo->protection_token_engine),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm_ProcessAadLastBlock)
    );
}


/**
 * @brief AES GCM skeleton function for processing last bytes of data which do not form a full block,
 *        stored in context and input.
 *
 *
 * @param[in]       session                 Session handle.
 * @param[in]       pIn                     Pointer to input.
 * @param[in,out]   pContext                Pointer to context.
 * @param[in]       inputBytesRemaining     Input length. Must be smaller than block size.
 * @param[out]      pOutput                 Pointer to output.
 * @param[out]      pOutLength              Pointer to output length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesGcm_ProcessLastBlock)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesGcm_ProcessLastBlock(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    const uint8_t *pIn,
    uint32_t inputBytesRemaining,
    uint8_t *pOutput,
    uint32_t * const pOutLength
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesGcm_ProcessLastBlock);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;
    uint32_t dataProFPFlag = 0u;
    if (0u != inputBytesRemaining)
    {
        /* If there is still data in the input, copy it to the partial data buffer for the next iteration. */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pContext->partialData,
                                                            pIn,
                                                            inputBytesRemaining,
                                                            MCUXCLAES_BLOCK_SIZE);
        pContext->partialDataLength = inputBytesRemaining;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("The caller ensured that pContext->processedDataLength will not overflow by any of the performed additions to it.")
        pContext->processedDataLength += inputBytesRemaining;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }

    //Check if we done all input data and if we have some remaining data in buffer, this is for
    //the last input data block processing, add zero padding and calc
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->aadLength, 0u, UINT32_MAX - pContext->dataLength, MCUXCLAEAD_STATUS_ERROR)
    if((pContext->processedDataLength == pContext->dataLength + pContext->aadLength) && (0u != pContext->partialDataLength))
    {
        dataProFPFlag = 1u;
        /* There is still data which needs to be zero-padded and processed. */
        MCUXCLMEMORY_FP_MEMORY_SET_WITH_BUFF(pContext->partialData + pContext->partialDataLength, 0u, MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength, MCUXCLAES_BLOCK_SIZE);

        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(redFinalData, pAlgo->pEngine(session, pContext,
                                                                    pContext->partialData,
                                                                    MCUXCLAES_BLOCK_SIZE,
                                                                    pContext->partialData,
                                                                    NULL,
                                                                    MCUXCLAEADMODES_ENGINE_OPTION_DATA_FINAL));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != redFinalData)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessLastBlock, MCUXCLAEAD_STATUS_ERROR);
        }

        /* Write to pOutLength how many bytes have been processed. */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pOutput, pContext->partialData, pContext->partialDataLength, MCUXCLAES_BLOCK_SIZE);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("The caller ensured that *pOutLength will not overflow by any of the performed additions to it.")
        *pOutLength += pContext->partialDataLength;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        /* The partial data buffer is now empty. */
        pContext->partialDataLength = 0u;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_ProcessLastBlock, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((inputBytesRemaining != 0u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)),
        MCUX_CSSL_FP_CONDITIONAL((dataProFPFlag != 0u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
                                                        pAlgo->protection_token_engine)
    );
}


/**
 * @brief AES GCM skeleton function for processing input data.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[out]      pOut              Pointer to output.
 * @param[out]      pOutLength        Pointer to output length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesGcm_Process)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesGcm_Process(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength
    )
{
    /*
        - Data processing (options == oneshot / update data)
            - if partialDataLength != 0 add the new data from the input to partialData and process using pEngine(option:data)
            if possible,adapt partialDataLength and processedDataLength (this will never be the case for oneshot)
            - process remaining complete blocks using pEngine(option:data)from the input, adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength (this can happen
            for oneshot)
            - [Assertion] aadLength + dataLength  <= processedDataLength
            - if aadLength + dataLength == processedDataLength padd partialData with zeros
            and process using pEngine(option:data), set partialDataLength to zero
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesGcm_Process);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->partialDataLength, 0u, MCUXCLAES_BLOCK_SIZE, MCUXCLAEAD_STATUS_ERROR)

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;
    uint32_t dataProFPFlag1 = 0u;
    uint32_t dataProFPFlag2 = 0u;
    uint8_t *pOutput = pOut;

    if ((inLength > (UINT32_MAX - pContext->partialDataLength))
        || (inLength > (UINT32_MAX - pContext->processedDataLength))
        || (*pOutLength > (UINT32_MAX - pContext->partialDataLength - inLength)))

    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Process, MCUXCLAEAD_STATUS_ERROR);
    }

    /* Number of bytes to possibly copy into the partial data buffer. */
    uint32_t bytesCopied = 0u;
    uint32_t bytesToCopy = (((MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength) < (inLength)) ?
                    (MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength) : (inLength));

    if (pContext->partialDataLength != 0u)
    {
        dataProFPFlag1 = 1u;
        /* Process input data. */
        /* Add new data into the partial data buffer and process, if possible. */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pContext->partialData + pContext->partialDataLength,
                                                                pIn,
                                                                bytesToCopy,
                                                                MCUXCLAES_BLOCK_SIZE);

        /* Update the number of bytes in the partial data buffer. */
        pContext->partialDataLength += bytesToCopy;

        if (MCUXCLAES_BLOCK_SIZE == pContext->partialDataLength)
        {
            dataProFPFlag2 = 1u;
            /* partialData now contains a full block, so process it. */
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(retData, pAlgo->pEngine(session, pContext,
                                                                            pContext->partialData,
                                                                            MCUXCLAES_BLOCK_SIZE,
                                                                            pOutput,
                                                                            NULL,
                                                                            MCUXCLAEADMODES_ENGINE_OPTION_DATA));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != retData)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Process, MCUXCLAEAD_STATUS_ERROR);
            }

            /* The partial data buffer is now empty. */
            pContext->partialDataLength = 0u;

            /* Write to pOutLength how many bytes have been written, and update the output buffer */
            *pOutLength += MCUXCLAES_BLOCK_SIZE;
            pOutput += MCUXCLAES_BLOCK_SIZE;
        }

        /* The bytes copied already should not be taken into account further. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("inLength > (UINT32_MAX - pContext->processedDataLength) was checked")
        pContext->processedDataLength += bytesToCopy;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        bytesCopied += bytesToCopy;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("bytesToCopy can't be bigger than inLength")
        inLength -= bytesToCopy;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    uint32_t bytesRemainingData = (inLength / MCUXCLAES_BLOCK_SIZE) * MCUXCLAES_BLOCK_SIZE;
    if(0u != bytesRemainingData)
    {
        /* Process as many remaining full blocks as possible. */
        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(retBlkData, pAlgo->pEngine(session, pContext,
                                                                    pIn + bytesCopied,
                                                                    bytesRemainingData,
                                                                    pOutput,
                                                                    NULL,
                                                                    MCUXCLAEADMODES_ENGINE_OPTION_DATA));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != retBlkData)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Process, MCUXCLAEAD_STATUS_ERROR);
        }

        pContext->processedDataLength += bytesRemainingData;
        /* The bytes copied already should not be taken into account further. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("bytesCopied will be increased by a maximum of inLength, this cannot wrap.")
        bytesCopied += bytesRemainingData;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        /* Write to pOutLength how many bytes have been written. */
        *pOutLength += bytesRemainingData;
        pOutput += bytesRemainingData;
    }

    bytesRemainingData = inLength & (MCUXCLAES_BLOCK_SIZE - 1u);

    MCUX_CSSL_FP_FUNCTION_CALL(retProcessLastBlock, mcuxClAeadModes_SkeletonAesGcm_ProcessLastBlock(
        session,
        pContext,
        pIn + bytesCopied,
        bytesRemainingData,
        pOutput,
        pOutLength)
    );

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Process, retProcessLastBlock,
        MCUX_CSSL_FP_CONDITIONAL((dataProFPFlag1 == 1u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            MCUX_CSSL_FP_CONDITIONAL((dataProFPFlag2 == 1u), pAlgo->protection_token_engine)
        ),
        MCUX_CSSL_FP_CONDITIONAL((0u != ((inLength / MCUXCLAES_BLOCK_SIZE) * MCUXCLAES_BLOCK_SIZE)), pAlgo->protection_token_engine),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm_ProcessLastBlock)
    );
}


/**
 * @brief AES GCM skeleton finalization function. Performs the finish or finish+verify step,
 *        depending on the options bits.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in,out]   pTag              Pointer to tag.
 * @param[in]       tagLength         Tag length.
 * @param[in]       options           Options is a bitmask with one bit reserved for each
 *                                    of the operations
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesGcm_Finalize)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesGcm_Finalize(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    mcuxCl_Buffer_t pTag,
    uint32_t tagLength,
    uint32_t options
    )
{
    /*
        - Finalization processing (options == oneshot / finish / verify)
            - if partialDataLength != 0 exit with ERROR
            - perform the finalize processing using pEngine(option:finish),
            - store tag in partialData
            - copy calculated tag to pTag when MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT option is used
            - compare calculated tag with pTag when MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT option is used
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesGcm_Finalize);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;

    if (pContext->partialDataLength != 0u)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Finalize, MCUXCLAEAD_STATUS_ERROR);
    }

    /* Call the finalize function. */
    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL(retFinal, pAlgo->pEngine(session, pContext,
                                                            NULL,
                                                            0u,
                                                            pContext->partialData,
                                                            NULL,
                                                            MCUXCLAEADMODES_ENGINE_OPTION_FINISH));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if(MCUXCLAEAD_STATUS_OK != retFinal)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Finalize, MCUXCLAEAD_STATUS_ERROR);
    }

    /*
        - Finalization / verification processing
    */
    mcuxClAead_Status_t status = MCUXCLAEAD_STATUS_ERROR;

    if ((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT)
    {
        MCUXCLMEMORY_FP_MEMORY_COPY(pTag, pContext->partialData, tagLength);
        status = MCUXCLAEAD_STATUS_OK;
    }

    if ((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(compare_result, mcuxCsslMemory_Compare(mcuxCsslParamIntegrity_Protect(3u, pTag, pContext->partialData, tagLength),
                                                                      pTag,
                                                                      pContext->partialData,
                                                                      tagLength));

        if(MCUXCSSLMEMORY_STATUS_EQUAL == compare_result)
        {
            status = MCUXCLAEAD_STATUS_OK;
        }
        else if(MCUXCSSLMEMORY_STATUS_NOT_EQUAL == compare_result)
        {
            status = MCUXCLAEAD_STATUS_INVALID_TAG;
        }
        else
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Finalize, MCUXCLAEAD_STATUS_FAULT_ATTACK);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm_Finalize, status,
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT),
            pAlgo->protection_token_engine, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
        ),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT),
            pAlgo->protection_token_engine, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare)
        )
    );
}


/**
 * @brief AES GCM skeleton function.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pNonce            Pointer to nonce.
 * @param[in]       nonceLength,      Nonce length.
 * @param[in]       pIn               Pointer to input.
 * @param[in]       inLength          Input length.
 * @param[in]       pAdata            Pointer to adata.
 * @param[in]       adataLength       Adata length.
 * @param[out]      pOut              Pointer to output.
 * @param[out]      pOutLength        Pointer to output length.
 * @param[in,out]   pTag              Pointer to tag.
 * @param[in]       tagLength         Tag length.
 * @param[in]       options           Options is a bitmask with one bit reserved for each of the operations
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesGcm)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesGcm(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    mcuxCl_InputBuffer_t pNonce,
    uint32_t nonceLength,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_InputBuffer_t pAdata,
    uint32_t adataLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength,
    mcuxCl_Buffer_t pTag,
    uint32_t tagLength,
    uint32_t options
    )
{
    /* [Design]
        ATTN: pOutLength will be _incremented_ by the number of bytes of encrypted data that have been
              written to the @p pOut buffer. Except otherwise mentioned processing steps _output_ data
              to pOut and update pOutLength

        - Preconditions
            - aadLength in context has been initialized
            - dataLength in context has been initialized
            - tagLength in context has been initialized
            - key in context has been initialized
            - mode in context has been initialized
            - processedDataLength in context has been initialized and maintained

        - Context usage:
            - the state contains both the counter and the partial MAC

        - Common IV processing (options == oneshot / init)
            - set partialDataLength in context to zero
            - process IV with ELS and output to state in context
                - if the IV length is not 12 use using pEngine(option:iv) to process the complete blocks
                - partialData can be used to padd the IV since it is not used at this time

        - AAD processing (options == oneshot / update aad)
            - if partialDataLength != 0 add the new data from the input to partialData and process using pEngine(option:aad)
              if possible,adapt partialDataLength and processedDataLength (this will never be the case for oneshot)
            - process remaining complete blocks using pEngine(option:aad) from the input, adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength (this can happen
              for oneshot)
            - [Assertion] aadLength <= processedDataLength
            - if aadLength == processedDataLength padd partialData with zeros and process using pEngine(option:aad), set
              partialDataLength to zero

        - Data processing (options == oneshot / update data)
            - if partialDataLength != 0 add the new data from the input to partialData and process using pEngine(option:data)
              if possible,adapt partialDataLength and processedDataLength (this will never be the case for oneshot)
            - process remaining complete blocks using pEngine(option:data)from the input, adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength (this can happen
              for oneshot)
            - [Assertion] aadLength + dataLength  <= processedDataLength
            - if aadLength + dataLength == processedDataLength padd partialData with zeros
              and process using pEngine(option:data), set partialDataLength to zero

        - Finalization processing (options == oneshot / finish / verify)
            - if partialDataLength != 0 exit with ERROR
            - perform the finalize processing using pEngine(option:finish), store tag in partialData in context

        - Finalization processing (options == oneshot / finish)
            - copy tagLength bytes from partialData to the tag
            - clean up context

        - Finalization processing (options == verify)
            - compare tagLength bytes from partialData to the tag
            - clean up context

        - exit
    */

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesGcm);

    if ((options & MCUXCLAEADMODES_OPTION_INIT) == MCUXCLAEADMODES_OPTION_INIT)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(initRet, mcuxClAeadModes_SkeletonAesGcm_Init(
            session,
            pContext,
            pNonce,
            nonceLength)
        );

        if(MCUXCLAEAD_STATUS_OK != initRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm, initRet);
        }
    }

    if ((options & MCUXCLAEADMODES_OPTION_PROCESS_AAD) == MCUXCLAEADMODES_OPTION_PROCESS_AAD)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(processAadRet, mcuxClAeadModes_SkeletonAesGcm_ProcessAad(
            session,
            pContext,
            pAdata,
            adataLength)
        );

        if(MCUXCLAEAD_STATUS_OK != processAadRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm, processAadRet);
        }
    }

    if ((options & MCUXCLAEADMODES_OPTION_PROCESS) == MCUXCLAEADMODES_OPTION_PROCESS)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(processRet, mcuxClAeadModes_SkeletonAesGcm_Process(
            session,
            pContext,
            pIn,
            inLength,
            pOut,
            pOutLength)
        );

        if(MCUXCLAEAD_STATUS_OK != processRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm, processRet);
        }
    }

    mcuxClAead_Status_t gcmRet = MCUXCLAEAD_STATUS_OK;

    if (((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT)
        || ((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(finalizeRet, mcuxClAeadModes_SkeletonAesGcm_Finalize(
            session,
            pContext,
            pTag,
            tagLength,
            options)
        );

        gcmRet = finalizeRet;
    }

    /* Exit and balance the flow protection. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesGcm, gcmRet,
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_OPTION_INIT) == MCUXCLAEADMODES_OPTION_INIT),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm_Init)
        ),
        MCUX_CSSL_FP_CONDITIONAL((((options & MCUXCLAEADMODES_OPTION_PROCESS_AAD) == MCUXCLAEADMODES_OPTION_PROCESS_AAD)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm_ProcessAad)
        ),
        MCUX_CSSL_FP_CONDITIONAL((((options & MCUXCLAEADMODES_OPTION_PROCESS) == MCUXCLAEADMODES_OPTION_PROCESS)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm_Process)
        ),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT)
            || ((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesGcm_Finalize)
        )
    );
}
