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

/** @file  mcuxClAeadModes_Els_AesCcm.c
 *  @brief Implementation of the AES CCM skeleton functions of the mcuxClAeadModes component */

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
 * @brief AES CCM skeleton initialization function.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pNonce            Pointer to nonce.
 * @param[in]       nonceLength,      Nonce length.
 * @param[in]       inLength          Input length.
 * @param[in]       adataLength       Adata length.
 * @param[in]       tagLength         Tag length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesCcm_Init)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesCcm_Init(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t* pContext,
    mcuxCl_InputBuffer_t pNonce,
    uint32_t nonceLength,
    uint32_t inLength,
    uint32_t adataLength,
    uint32_t tagLength)
{
    /*
        - Common IV processing (options == oneshot / init)
            - set partialDataLength in context to zero
            - construct the first block using the nonce from the input and the dataLength, aadLength and tagLength from the
            context. partialData can be used for this as it is not in use yet.
            - process the first block using pEngine(option: auth+init) with zero IV (the engine will update the state in context)
            - construct the counter for CTR mode encryption and output to state in context, let it start at 'one'
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesCcm_Init);

    /* Init tag. For CCM, the state store the tag value */
    MCUXCLMEMORY_FP_MEMORY_SET(pContext->state, 0U, MCUXCLAES_BLOCK_SIZE);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;
    pContext->partialDataLength = 0U;

    /* Generate the plain tag -> CBC-MAC with zero IV */
    // Clear first blocks to guarantee zero padding
    MCUXCLMEMORY_FP_MEMORY_SET(pContext->partialData, 0U, MCUXCLAES_BLOCK_SIZE);

    /* Check that tagLength and nonceLength are in range:
     *  tagLength shall be in {4,6,8,10,12,14,16}
     *  nonceLength shall be in {7,8,9,10,11,12,13} */
    if((tagLength < 4U) || (tagLength > 16U) || (nonceLength < 7U) || (nonceLength > 13U))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Init, MCUXCLAEAD_STATUS_ERROR);
    }

    // Get length of auth field from parameter
    uint8_t t = (uint8_t)(((tagLength - 2U) / 2U) & 0xffU);
    // Get q-1 from parameter
    uint8_t q = (uint8_t)(MCUXCLAES_BLOCK_SIZE - 1U - nonceLength);
    // Assemble the flags byte for B0
    // --------------------------------------------
    // |     7    |   6   |    5..3     |   2..0  |
    // | Reserved | Adata | [(t-2)/2]_3 | [q-1]_3 |
    // --------------------------------------------
    uint8_t isheaderLen = (uint8_t)(adataLength > 0U);  /* isheaderLen is a single bit */
    pContext->partialData[0U] = ((uint8_t)((isheaderLen << 6U) & 0xffU))
                                | ((uint8_t)((t << 3U) & 0xffU))
                                | (q - 1U);

    // Create B0
    // ----------------------------------
    // |   0   | 1 .. 15-q | 16-q .. 15 |
    // | Flags |     N     |      Q     |
    // ----------------------------------

    // Copy nonce N
    MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->partialData[1U], pNonce, nonceLength);

    // Create Q
    uint32_t inMask = 0x000000ffU;
    for(int8_t it = 15; it >= (16 - ((int8_t)q)); --it)
    {
        pContext->partialData[it] = (uint8_t)(((inLength & inMask) >> (((15U - (uint8_t)it) * 8U) & 0x0fU)) & 0xffU);
        inMask = inMask << 8;
    }

    //Calculate tag over B0
    //process the first block using pEngine(option: auth) with zero IV and output to state in context
    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL(authRet, pAlgo->pEngine(session, pContext,
                                                                pContext->partialData,
                                                                MCUXCLAES_BLOCK_SIZE,
                                                                NULL,
                                                                NULL,
                                                                MCUXCLAEADMODES_ENGINE_OPTION_AUTH | MCUXCLAEADMODES_ENGINE_OPTION_INIT));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if(MCUXCLAEAD_STATUS_OK != authRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Init, MCUXCLAEAD_STATUS_ERROR);
    }

    // Formatting of the associated data
    // Encode a and concatenate with associated data
    // Check if AAD has to be processed
    if(0U == adataLength)
    {
        pContext->partialDataLength = 0U;
    }
    // If 0 < a < 2^{16}-2^{8}, then a is encoded as [a]_16, i.e., two octets.
    else if(adataLength < ((1UL << 16U) - (1UL << 8U)))
    {
        // a < 2^{16}-2^{8}
        pContext->partialData[0] = (uint8_t)((adataLength & 0x0000FF00U) >> 8U);
        pContext->partialData[1] = (uint8_t)((adataLength & 0x000000FFU) >> 0U);

        pContext->partialDataLength = 2U;
    }
    // If 2^{16}-2^{8} <= a < 2^{32}, then a is encoded as 0xff || 0xfe || [a]_32, i.e., six octets.
    else
    {
        // a >= 2^{16}-2^{8}
        pContext->partialData[0] = (uint8_t)0xFFU;
        pContext->partialData[1] = (uint8_t)0xFEU;
        pContext->partialData[2] = (uint8_t)((adataLength & 0xFF000000U) >> 24U);
        pContext->partialData[3] = (uint8_t)((adataLength & 0x00FF0000U) >> 16U);
        pContext->partialData[4] = (uint8_t)((adataLength & 0x0000FF00U) >> 8U);
        pContext->partialData[5] = (uint8_t)((adataLength & 0x000000FFU) >> 0U);

        pContext->partialDataLength = 6U;
    }

    // If 2^{32} <= a < 2^{64}, then a is encoded as 0xff || 0xff || [a]_64, i.e., ten octets.
    // This case is not supported in CL and hence does not occur since inLength is uint32_t

    /*  Generate the counter for CTR mode encryption */
    // &pContext->state[32] won't be used in CCM mode, so write it to store the counter0Data.
    // Use &pContext->state[48] to store the counterData
    // Set counter to zero first
    MCUXCLMEMORY_FP_MEMORY_SET(&pContext->state[32], 0U, MCUXCLAES_BLOCK_SIZE);


    // Assemble the flags byte
    // ------------------------------------------
    // |     7    |     6    |  5..3  |   2..0  |
    // | Reserved | Reserved |   000  | [q-1]_3 |
    // ------------------------------------------
    pContext->state[32] = q - 1U;

    // Create CTR0
    // ----------------------------------
    // |   0   | 1 .. 15-q | 16-q .. 15 |
    // | Flags |     N     |      0     |
    // ----------------------------------

    // Copy nonce into counter block
    MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->state[33], pNonce, nonceLength);

    MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->state[48], &pContext->state[32], MCUXCLAES_BLOCK_SIZE);
    // Last X bytes of counterData are always equal zero, set last byte to one for the next computation
    pContext->state[63] = 0x1U;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Init, MCUXCLAEAD_STATUS_OK,
        3u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
        3u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
        pAlgo->protection_token_engine
    );
}

/**
 * @brief AES CCM skeleton function for processing remaining bytes stored in context of additional
 *        authentication data.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesCcm_AadLastBlock)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesCcm_AadLastBlock(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesCcm_AadLastBlock);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;

    //Check if we done all adata and if we have some remaining data in buffer, this is for
    //the last adata block processing, add zero padding and calc pretag
    uint32_t aadFpFlag = 0U;
    if((pContext->processedDataLength == pContext->aadLength) && (0u != pContext->partialDataLength))
    {
         /* Apply the padding function specified in the mode on the partial data. */
        MCUXCLMEMORY_FP_MEMORY_SET(&pContext->partialData[pContext->partialDataLength], 0x00u, MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);

        //Process remaining adata and create pretag
        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(aadPadAuthRet, pAlgo->pEngine(session, pContext,
                                                                pContext->partialData,
                                                                MCUXCLAES_BLOCK_SIZE,
                                                                NULL,
                                                                NULL,
                                                                MCUXCLAEADMODES_ENGINE_OPTION_AUTH));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != aadPadAuthRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_AadLastBlock, MCUXCLAEAD_STATUS_ERROR);
        }
        aadFpFlag = 1U;
        pContext->partialDataLength = 0U;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_AadLastBlock, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL(1U == aadFpFlag,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
            pAlgo->protection_token_engine
        )
    );
}


/**
 * @brief AES CCM skeleton function for processing additional authentication data.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in]       pAdata            Pointer to adata.
 * @param[in]       adataLength       Adata length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesCcm_Aad)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesCcm_Aad(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    mcuxCl_InputBuffer_t pAdata,
    uint32_t adataLength)
{
    /*
        - AAD processing (options == oneshot / update aad)
            - if adataLength != 0 add the new data from the input to partialData[partialDataLength] and process using
            pEngine(option: auth) if possible, adapt partialDataLength and processedDataLength
            - process remaining complete blocks from the input using pEngine(option: auth), adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength
            - [Assertion] aadLength <= processedDataLength
            - if aadLength == processedDataLength padd partialData with zeros and process using pEngine(option: auth), set
            partialDataLength to zero
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesCcm_Aad);

    if ((adataLength > (UINT32_MAX - pContext->partialDataLength))
    || (adataLength > (UINT32_MAX - pContext->processedDataLength)))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Aad, MCUXCLAEAD_STATUS_ERROR);
    }

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;
    uint32_t mainAadFpFlag = 0U;
    uint32_t secondAadFpFlag = 0U;
    uint32_t thirdAadFpFlag = 0U;
    uint32_t forthAadFpFlag = 0U;

    uint32_t lenToCopy = adataLength;
    // adataLength is the length of AAD for this AAD process call
    if(0u != lenToCopy)
    {
        if((pContext->partialDataLength + lenToCopy) >= MCUXCLAES_BLOCK_SIZE)
        {
            secondAadFpFlag = 1u;
            uint8_t const* pAad = (uint8_t const*)pAdata;
            MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->partialData[pContext->partialDataLength],pAad,MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);
            pAad += MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength;

            lenToCopy -= (MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);
            pContext->partialDataLength = 0u;

            //Calculate tag over adata
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(aadAuthRet, pAlgo->pEngine(session, pContext,
                                                                        pContext->partialData,
                                                                        MCUXCLAES_BLOCK_SIZE,
                                                                        NULL,
                                                                        NULL,
                                                                        MCUXCLAEADMODES_ENGINE_OPTION_AUTH));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != aadAuthRet)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Aad, MCUXCLAEAD_STATUS_ERROR);
            }

            if(lenToCopy >= MCUXCLAES_BLOCK_SIZE)
            {
                thirdAadFpFlag = 1u;
                uint32_t adataBlocks = lenToCopy / MCUXCLAES_BLOCK_SIZE;
                MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
                MCUX_CSSL_FP_FUNCTION_CALL(aadBlkAuthRet, pAlgo->pEngine(session, pContext,
                                                                        pAad,
                                                                        adataBlocks * MCUXCLAES_BLOCK_SIZE,
                                                                        NULL,
                                                                        NULL,
                                                                        MCUXCLAEADMODES_ENGINE_OPTION_AUTH));
                MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

                if(MCUXCLAEAD_STATUS_OK != aadBlkAuthRet)
                {
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Aad, MCUXCLAEAD_STATUS_ERROR);
                }
                pAad += adataBlocks * MCUXCLAES_BLOCK_SIZE;

                // Remaining lenToCopy is equal to lenToCopy & (MCUXCLAES_BLOCK_SIZE - 1u)
                lenToCopy &= (MCUXCLAES_BLOCK_SIZE - 1u);
            }

            if(0u != lenToCopy)
            {
                forthAadFpFlag = 1u;
                //copy remaining data into partialData
                MCUXCLMEMORY_FP_MEMORY_COPY(pContext->partialData,pAad,lenToCopy);
                pContext->partialDataLength = lenToCopy;
            }
        }
        else
        {
            mainAadFpFlag = 1u;
            //bytes in buffer and new adata is less then blockSize - save data into partialData
            MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->partialData[pContext->partialDataLength],pAdata,lenToCopy);
            pContext->partialDataLength += lenToCopy;
        }
    }

    //update adata size to processedDataLength in ctx
    pContext->processedDataLength += adataLength;//The processedDataLength add the length of each processing

    MCUX_CSSL_FP_FUNCTION_CALL(aadLastBlockRet, mcuxClAeadModes_SkeletonAesCcm_AadLastBlock(
        session,
        pContext)
    );

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Aad, aadLastBlockRet,
        MCUX_CSSL_FP_CONDITIONAL((secondAadFpFlag == 1u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            pAlgo->protection_token_engine,
            MCUX_CSSL_FP_CONDITIONAL((thirdAadFpFlag == 1u), pAlgo->protection_token_engine),
            MCUX_CSSL_FP_CONDITIONAL((forthAadFpFlag == 1u), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy))
        ),
        MCUX_CSSL_FP_CONDITIONAL((mainAadFpFlag == 1u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm_AadLastBlock)
    );
}

/**
 * @brief AES CCM skeleton function for processing last bytes of input data stored in context.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[out]      pOutput           Pointer to output.
 * @param[out]      pOutLength        Pointer to output length.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock(
    mcuxClSession_Handle_t session,
    mcuxClAeadModes_Context_t * const pContext,
    uint8_t *pOutput,
    uint32_t * const pOutLength
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock);
    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;
    //below variable definitions are used for flow protection of final one block process
    uint32_t mainFinFpFlag = 0u;
    //Check if we done all input data and if we have some remaining data in buffer, this is for
    //the last input data block processing, add zero padding and calc final tag

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->aadLength, 0u, UINT32_MAX - pContext->dataLength, MCUXCLAEAD_STATUS_ERROR)
    if((pContext->processedDataLength == pContext->dataLength + pContext->aadLength) && (0u != pContext->partialDataLength))
    {
        if(pContext->partialDataLength < MCUXCLAES_BLOCK_SIZE)
        {
            mainFinFpFlag = 1u;
            MCUXCLMEMORY_FP_MEMORY_SET(&pContext->partialData[pContext->partialDataLength], 0x00u, MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);
        }
        else
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock, MCUXCLAEAD_STATUS_ERROR);
        }
        //This last block length less then MCUXCLAES_BLOCK_SIZE, so can't directly write result to pOut
        //&pContext->state[16] have not been used, so can re-write it to store the CTR result
        MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
        MCUX_CSSL_FP_FUNCTION_CALL(inPaddEncRet, pAlgo->pEngine(session, pContext,
                                                                            pContext->partialData,
                                                                            MCUXCLAES_BLOCK_SIZE,
                                                                            &pContext->state[16],
                                                                            NULL,
                                                                            MCUXCLAEADMODES_ENGINE_OPTION_ENC));
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

        if(MCUXCLAEAD_STATUS_OK != inPaddEncRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock, MCUXCLAEAD_STATUS_ERROR);
        }

        /* Copy the padding to the output and update pOutLength accordingly. */
        MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pOutput, &pContext->state[16], pContext->partialDataLength, MCUXCLAES_BLOCK_SIZE);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("The caller ensured that *pOutLength will not overflow by any of the performed additions to it.")
        *pOutLength += pContext->partialDataLength;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        if(MCUXCLELS_AEAD_ENCRYPT == pAlgo->direction)
        {
            //Process remaining data and create pretag
            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(inPaddAuthRet, pAlgo->pEngine(session, pContext,
                                                                            pContext->partialData,
                                                                            MCUXCLAES_BLOCK_SIZE,
                                                                            NULL,
                                                                            NULL,
                                                                            MCUXCLAEADMODES_ENGINE_OPTION_AUTH));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != inPaddAuthRet)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock, MCUXCLAEAD_STATUS_ERROR);
            }
        }
        else
        {
            //Process remaining data and create pretag
            MCUXCLMEMORY_FP_MEMORY_SET(&pContext->state[16u + pContext->partialDataLength], 0x00u, MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);

            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(inPaddAuthRet, pAlgo->pEngine(session, pContext,
                                                                            &pContext->state[16],
                                                                            MCUXCLAES_BLOCK_SIZE,
                                                                            NULL,
                                                                            NULL,
                                                                            MCUXCLAEADMODES_ENGINE_OPTION_AUTH));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != inPaddAuthRet)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock, MCUXCLAEAD_STATUS_ERROR);
            }
        }
        pContext->partialDataLength = 0u;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock, MCUXCLAEAD_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((mainFinFpFlag == 1u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
            pAlgo->protection_token_engine,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            pAlgo->protection_token_engine,
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLELS_AEAD_DECRYPT == pAlgo->direction), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set))
        )
    );
}


/**
 * @brief AES CCM skeleton function for processing input data.
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
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesCcm_Process)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesCcm_Process(
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
            - if inLength != 0 add the new data from the input to partialData and process using pEngine(option: aead) if possible,
            adapt partialDataLength and processedDataLength (this will never be the case for oneshot)
            - process remaining complete blocks from the input using pEngine(option: aead), adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength
            - [Assertion] aadLength + dataLength  <= processedDataLength
            - if aadLength + dataLength == processedDataLength padd partialData with zeros
            and process using pEngine(option: auth+enc), set partialDataLength to zero
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesCcm_Process);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;
    //below variable definitions are used for flow protection of plaintext data process
    uint32_t mainProFpFlag = 0u;
    uint32_t secondProFpFlag = 0u;
    uint32_t thirdProFpFlag = 0u;
    uint32_t forthProFpFlag = 0u;
    uint8_t *pOutput = pOut;


    if ((inLength > (UINT32_MAX - pContext->partialDataLength))
        || (inLength > (UINT32_MAX - pContext->processedDataLength))
        || (*pOutLength > (UINT32_MAX - pContext->partialDataLength - inLength)))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Process, MCUXCLAEAD_STATUS_ERROR);
    }

    if(0u != inLength)
    {
        uint8_t const* pInput = (uint8_t const*)pIn;
        if((pContext->partialDataLength + inLength) >= MCUXCLAES_BLOCK_SIZE)
        {
            mainProFpFlag = 1u;
            MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->partialData[pContext->partialDataLength],pInput,MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);
            pInput += MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength;
            inLength -= (MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);
            //update processed input data length to processedDataLength
            pContext->processedDataLength += (MCUXCLAES_BLOCK_SIZE - pContext->partialDataLength);
            pContext->partialDataLength = 0u;

            MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
            MCUX_CSSL_FP_FUNCTION_CALL(inAeadRet, pAlgo->pEngine(session, pContext,
                                                                        pContext->partialData,
                                                                        MCUXCLAES_BLOCK_SIZE,
                                                                        pOutput,
                                                                        NULL,
                                                                        MCUXCLAEADMODES_ENGINE_OPTION_AEAD));
            MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

            if(MCUXCLAEAD_STATUS_OK != inAeadRet)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Process, MCUXCLAEAD_STATUS_ERROR);
            }

            pOutput +=  MCUXCLAES_BLOCK_SIZE;
            *pOutLength += MCUXCLAES_BLOCK_SIZE;

            if(inLength >= MCUXCLAES_BLOCK_SIZE)
            {
                secondProFpFlag = 1u;
                uint32_t inputBlocks = inLength / MCUXCLAES_BLOCK_SIZE;

                MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
                MCUX_CSSL_FP_FUNCTION_CALL(inBlkAeadRet, pAlgo->pEngine(session, pContext,
                                                                        pInput,
                                                                        inputBlocks * MCUXCLAES_BLOCK_SIZE,
                                                                        pOutput,
                                                                        NULL,
                                                                        MCUXCLAEADMODES_ENGINE_OPTION_AEAD));
                MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

                if(MCUXCLAEAD_STATUS_OK != inBlkAeadRet)
                {
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Process, MCUXCLAEAD_STATUS_ERROR);
                }

                pInput += inputBlocks * MCUXCLAES_BLOCK_SIZE;
                // Remaining inLength is equal to inLength  & (MCUXCLAES_BLOCK_SIZE - 1u)
                inLength &= (MCUXCLAES_BLOCK_SIZE - 1u);
                //update processed input data length to processedDataLength

                MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("inLength > (UINT32_MAX - pContext->processedDataLength) was checked")
                pContext->processedDataLength += inputBlocks * MCUXCLAES_BLOCK_SIZE;
                MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
                pOutput += inputBlocks * MCUXCLAES_BLOCK_SIZE;
                MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("(*pOutLength > (UINT32_MAX - pContext->partialDataLength - inLength)) was checked")
                *pOutLength += inputBlocks * MCUXCLAES_BLOCK_SIZE;
                MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
            }

            if(0u != inLength)
            {
                thirdProFpFlag = 1u;
                //copy remaining data into blockBuffer
                MCUXCLMEMORY_FP_MEMORY_COPY(pContext->partialData,pInput,inLength);
                pContext->partialDataLength = inLength;
                //update processed input data length to processedDataLength
                pContext->processedDataLength += inLength;
            }
        }
        else
        {
            forthProFpFlag = 1u;
            //bytes in buffer and new adata is less then blockSize - save data into partialData
            MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->partialData[pContext->partialDataLength],pIn,inLength);
            pContext->partialDataLength += inLength;
            //update processed input data length to processedDataLength
            pContext->processedDataLength += inLength;
        }
    }

    MCUX_CSSL_FP_FUNCTION_CALL(processLastBlock_Ret, mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock(
        session,
        pContext,
        pOutput,
        pOutLength));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Process, processLastBlock_Ret,
        MCUX_CSSL_FP_CONDITIONAL((mainProFpFlag == 1u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            pAlgo->protection_token_engine,
            MCUX_CSSL_FP_CONDITIONAL((secondProFpFlag == 1u),pAlgo->protection_token_engine),
            MCUX_CSSL_FP_CONDITIONAL((thirdProFpFlag == 1u),MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy))
        ),
        MCUX_CSSL_FP_CONDITIONAL((forthProFpFlag == 1u),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
        ),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm_ProcessLastBlock)
    );
}


/**
 * @brief AES CCM skeleton finalize function. Performs the finish or finish+verify step,
 *        depending on the options bits.
 *
 * @param[in]       session           Session handle.
 * @param[in,out]   pContext          Pointer to context.
 * @param[in,out]   pTag              Pointer to tag.
 * @param[in]       tagLength         Tag length.
 * @param[in]       options           Options is a bitmask with one bit reserved for each
 *                                    of the operations.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesCcm_Finalize)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesCcm_Finalize(
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
            - reset counter value to 'zero' (leaving the other fields intact)
            - process the CBC-MAC state with pEngine(option: enc), and store the result in partialData
    */
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesCcm_Finalize);

    const mcuxClAeadModes_AlgorithmDescriptor_t* const pAlgo = pContext->common.mode->algorithm;

    if (0u != pContext->partialDataLength)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Finalize, MCUXCLAEAD_STATUS_ERROR);
    }

    //reset counter value to 'zero' (leaving the other fields intact)
    MCUXCLMEMORY_FP_MEMORY_COPY(&pContext->state[48],&pContext->state[32],MCUXCLAES_BLOCK_SIZE);

    //Encrypt pretag with counter0 to get final tag
    MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
    MCUX_CSSL_FP_FUNCTION_CALL(finalTagEncRet, pAlgo->pEngine(session, pContext,
                                                                        pContext->state,
                                                                        MCUXCLAES_BLOCK_SIZE,
                                                                        pContext->partialData,
                                                                        NULL,
                                                                        MCUXCLAEADMODES_ENGINE_OPTION_ENC));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

    if(MCUXCLAEAD_STATUS_OK != finalTagEncRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Finalize, MCUXCLAEAD_STATUS_ERROR);
    }

    /*
        - Finalization processing (options == oneshot / finish)
            - copy tagLength bytes from partialData to the tag in case of encryption
            - compare tagLength bytes from partialData to the tag in case of decryption
    */
    mcuxClAead_Status_t status = MCUXCLAEAD_STATUS_ERROR;

    if ((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT)
    {
        MCUXCLMEMORY_FP_MEMORY_COPY(pTag, pContext->partialData, pContext->tagLength);
        status = MCUXCLAEAD_STATUS_OK;
    }

    if ((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(compare_result, mcuxCsslMemory_Compare(mcuxCsslParamIntegrity_Protect(3u, pTag, pContext->partialData, pContext->tagLength),
                                                                      pTag,
                                                                      pContext->partialData,
                                                                      pContext->tagLength));

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
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Finalize, MCUXCLAEAD_STATUS_FAULT_ATTACK);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm_Finalize, status,
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            pAlgo->protection_token_engine,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
        ),
        MCUX_CSSL_FP_CONDITIONAL((((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            pAlgo->protection_token_engine,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare)
        )
    );
}

/**
 * @brief AES CCM skeleton function.
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
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_SkeletonAesCcm)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_SkeletonAesCcm(
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

        Note:
            - options is a bitmask: 1: init, 2: aad, 4: process, 8: finish, 15: oneshot, 16: verify

        - Preconditions
            - aadLength in context has been initialized
            - dataLength in context has been initialized
            - tagLength in context has been initialized
            - key in context has been initialized
            - mode in context has been initialized
            - processedDataLength in context has been initialized and maintained

        - Context usage:
            - the state contains both the CTR counter and the partial CBC-MAC

        - Common IV processing (options == oneshot / init)
            - set partialDataLength in context to zero
            - construct the first block using the nonce from the input and the dataLength, aadLength and tagLength from the
              context. partialData can be used for this as it is not in use yet.
            - process the first block using pEngine(option: auth+init) with zero IV (the engine will update the state in context)
            - construct the counter for CTR mode encryption and output to state in context, let it start at 'one'

        - AAD processing (options == oneshot / update aad)
            - if adataLength != 0 add the new data from the input to partialData[partialDataLength] and process using
              pEngine(option: auth) if possible, adapt partialDataLength and processedDataLength
            - process remaining complete blocks from the input using pEngine(option: auth), adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength
            - [Assertion] aadLength <= processedDataLength
            - if aadLength == processedDataLength padd partialData with zeros and process using pEngine(option: auth), set
              partialDataLength to zero

        - Data processing (options == oneshot / update data)
            - if inLength != 0 add the new data from the input to partialData and process using pEngine(option: auth+enc) if possible,
              adapt partialDataLength and processedDataLength (this will never be the case for oneshot)
            - process remaining complete blocks from the input using pEngine(option: auth+enc), adapt processedDataLength
            - add remaining data to partialData, adapt partialDataLength and processedDataLength
            - [Assertion] aadLength + dataLength  <= processedDataLength
            - if aadLength + dataLength == processedDataLength padd partialData with zeros
              and process using pEngine(option: auth+enc), set partialDataLength to zero

        - Finalization processing (options == oneshot / finish / verify)
            - if partialDataLength != 0 exit with ERROR
            - reset counter value to 'zero' (leaving the other fields intact)
            - process the CBC-MAC state with pEngine(option: enc), and store the result in partialData

        - Finalization processing (options == oneshot / finish)
            - copy tagLength bytes from partialData to the tag
            - clean up context

        - Finalization processing (options == verify)
            - compare tagLength bytes from partialData to the tag
            - clean up context

        - exit
    */

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_SkeletonAesCcm);

    if ((options & MCUXCLAEADMODES_OPTION_INIT) == MCUXCLAEADMODES_OPTION_INIT)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(initRet, mcuxClAeadModes_SkeletonAesCcm_Init(
            session,
            pContext,
            pNonce,
            nonceLength,
            inLength,
            adataLength,
            tagLength));

        if(MCUXCLAEAD_STATUS_OK != initRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm, initRet);
        }
    }

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pContext->partialDataLength, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLAEAD_STATUS_ERROR)

    if ((options & MCUXCLAEADMODES_OPTION_PROCESS_AAD) == MCUXCLAEADMODES_OPTION_PROCESS_AAD)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(processAadRet, mcuxClAeadModes_SkeletonAesCcm_Aad(
            session,
            pContext,
            pAdata,
            adataLength));

        if(MCUXCLAEAD_STATUS_OK != processAadRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm, MCUXCLAEAD_STATUS_ERROR);
        }
    }

    if ((options & MCUXCLAEADMODES_OPTION_PROCESS) == MCUXCLAEADMODES_OPTION_PROCESS)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(procesRet, mcuxClAeadModes_SkeletonAesCcm_Process(
            session,
            pContext,
            pIn,
            inLength,
            pOut,
            pOutLength));

        if(MCUXCLAEAD_STATUS_OK != procesRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm, procesRet);
        }
    }

    mcuxClAead_Status_t ccmStatus = MCUXCLAEAD_STATUS_OK;

    if(((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT)
            || ((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(finalizeRet, mcuxClAeadModes_SkeletonAesCcm_Finalize(
            session,
            pContext,
            pTag,
            tagLength,
            options)
        );

        ccmStatus = finalizeRet;
    }

    /* Exit and balance the flow protection. */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_SkeletonAesCcm, ccmStatus,
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_OPTION_INIT) == MCUXCLAEADMODES_OPTION_INIT),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm_Init)
        ),
        MCUX_CSSL_FP_CONDITIONAL((((options & MCUXCLAEADMODES_OPTION_PROCESS_AAD) == MCUXCLAEADMODES_OPTION_PROCESS_AAD)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm_Aad)
        ),
        MCUX_CSSL_FP_CONDITIONAL((((options & MCUXCLAEADMODES_OPTION_PROCESS) == MCUXCLAEADMODES_OPTION_PROCESS)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm_Process)
        ),
        MCUX_CSSL_FP_CONDITIONAL(((options & MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT) == MCUXCLAEADMODES_OPTION_FINISH_ENCRYPT)
            || ((options & MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT) == MCUXCLAEADMODES_OPTION_VERIFY_DECRYPT),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAeadModes_SkeletonAesCcm_Finalize)
        )
    );
}

