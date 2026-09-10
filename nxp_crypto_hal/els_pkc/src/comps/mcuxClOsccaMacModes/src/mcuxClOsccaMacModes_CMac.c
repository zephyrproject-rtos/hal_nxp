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

/** @file  mcuxClOsccaMacModes_CMAC.c
 *  @brief implementation of the SM4 CMAC part of mcuxClOsccaMacModes component */

#include <mcuxClToolchain.h>
#include <mcuxClMac.h>
#include <mcuxClMemory.h>
#include <mcuxClOscca_Memory.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <internal/mcuxClOsccaSm4_Internal_Constants.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClOsccaMacModes_Internal_Functions.h>
#include <internal/mcuxClOsccaMacModes_Types.h>
#include <internal/mcuxClOsccaMacModes_Ctx.h>
#include <internal/mcuxClOsccaMacModes_SM4_CMAC.h>
#include <internal/mcuxClOsccaMacModes_Algorithms.h>

#ifdef MCUXCL_FEATURE_MACMODES_CMAC_SM4
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClOsccaMacModes_AlgorithmDescriptor_t mcuxClOsccaMacModes_AlgorithmDescriptor_CMAC_SM4 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  .engineInit = mcuxClOsccaMacModes_Engine_CMAC_Init,
  .protectionToken_engineInit =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_Engine_CMAC_Init),
  .engineUpdate =  mcuxClOsccaMacModes_Engine_CMAC_Update,
  .protectionToken_engineUpdate =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_Engine_CMAC_Update),
  .engineFinalize =  mcuxClOsccaMacModes_Engine_CMAC_Finalize,
  .protectionToken_engineFinalize =  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_Engine_CMAC_Finalize),
  .engineOneshot = mcuxClOsccaMacModes_Engine_CMAC_Oneshot,
  .protectionToken_engineOneshot = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_Engine_CMAC_Oneshot),
  .addPadding = mcuxClPadding_addPadding_ISO9797_1_Method2,
  .protectionToken_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2),
};
#endif /* MCUXCL_FEATURE_MACMODES_CMAC_SM4 */

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_Engine_CMAC_Init, mcuxClOsccaMac_InitEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Init(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClOsccaMacModes_Context_t * const pContext
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_Engine_CMAC_Init);
    mcuxClOsccaMacModes_Context_t* pCtx = (mcuxClOsccaMacModes_Context_t *)pContext;
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pCtx->stateIv,MCUXCLOSCCASM4_BLOCK_SIZE);

    /* No partial data after init. */
    pCtx->nrOfUnprocessedBytes = 0u;
    pCtx->dataProcessed = 0u;
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Init, MCUXCLMAC_STATUS_OK,
           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_Engine_CMAC_Update, mcuxClOsccaMac_UpdateEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Update(
  mcuxClSession_Handle_t session,
  mcuxClOsccaMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    mcuxClOsccaMacModes_Context_t* pCtx = (mcuxClOsccaMacModes_Context_t *)pContext;
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_Engine_CMAC_Update);

    uint32_t lastBlockRemainingBytes = 0u;
    uint32_t fullBlocksRemainingBytes = 0u;
    uint32_t inLenOri = inLength;
    uint32_t inOffset = 0u;

    if(0u == inLength)
    {
        /* Nothing to process */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Update, MCUXCLMAC_STATUS_OK);
    }

    MCUX_CSSL_FP_EXPECT(
        MCUX_CSSL_FP_CONDITIONAL((inLength <= (MCUXCLOSCCASM4_BLOCK_SIZE - pCtx->nrOfUnprocessedBytes)), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)),
        MCUX_CSSL_FP_CONDITIONAL((inLength > (MCUXCLOSCCASM4_BLOCK_SIZE - pCtx->nrOfUnprocessedBytes)),
                                       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_ScheduleSM4Key),
                                       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
                                       MCUX_CSSL_FP_CONDITIONAL((0u != pCtx->nrOfUnprocessedBytes),
                                            MCUX_CSSL_FP_CONDITIONAL((MCUXCLOSCCASM4_BLOCK_SIZE > pCtx->nrOfUnprocessedBytes),MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)),
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor),
                                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine)))
                                            );

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pCtx->nrOfUnprocessedBytes, 0u, MCUXCLOSCCASM4_BLOCK_SIZE, MCUXCLMAC_STATUS_FAILURE)
    if(inLength <= (MCUXCLOSCCASM4_BLOCK_SIZE - pCtx->nrOfUnprocessedBytes)) /* "lazy" processing */
    {
        /* Store bytes in context */
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferRead, mcuxClBuffer_read(pIn, inOffset, pCtx->stateIn + pCtx->nrOfUnprocessedBytes, inLength));
        (void)statusBufferRead; // No need to check it because the function only returns OK.

        pCtx->nrOfUnprocessedBytes += inLength;
        pCtx->dataProcessed += inLength;
    }
    else /* At least one block of data to process */
    {
        uint32_t* pRoundKeys = (uint32_t*)mcuxClSession_allocateWords_cpuWa(session,  MCUXCLOSCCASM4_RK_WORDS);
        if(NULL == pRoundKeys)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Update, MCUXCLMAC_STATUS_FAILURE);
        }

        MCUX_CSSL_FP_FUNCTION_CALL(setupResult, mcuxClOsccaSm4_ScheduleSM4Key(pRoundKeys, pCtx->pKey->container.pData, MCUXCLOSCCASM4_ENCRYPT));
        if(MCUXCLOSCCASM4_STATUS_LOADKEY_OK != setupResult)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Update, MCUXCLMAC_STATUS_FAILURE);
        }

        if(0u != pCtx->nrOfUnprocessedBytes)  /* Process 1 block from context */
        {
            if(MCUXCLOSCCASM4_BLOCK_SIZE > pCtx->nrOfUnprocessedBytes)
            {
                uint32_t emptyBytes = MCUXCLOSCCASM4_BLOCK_SIZE - pCtx->nrOfUnprocessedBytes;
                /* Add new data into the partial data buffer and process */
                MCUX_CSSL_FP_FUNCTION_CALL(statusBufferRead, mcuxClBuffer_read(pIn, inOffset, pCtx->stateIn + pCtx->nrOfUnprocessedBytes, emptyBytes));
                (void)statusBufferRead; // No need to check it because the function only returns OK.

                /* The bytes copied already should not be taken into account further. */
                MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("inLenOri must be larger than emptyBytes and pCtx->dataProcessed, inOffset += emptyBytes can't be larger than max(uint32_t)")
                inLenOri -= emptyBytes;
                pCtx->dataProcessed += emptyBytes;
                inOffset += emptyBytes;
                MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
            }

            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pCtx->stateIn, pCtx->stateIn, pCtx->stateIv, MCUXCLOSCCASM4_BLOCK_SIZE));
            MCUX_CSSL_FP_FUNCTION_CALL(engineRet, mcuxClOsccaSm4_Engine(pRoundKeys, pCtx->stateIn, pCtx->stateIv, MCUXCLOSCCASM4_ENCRYPT));
            if(engineRet != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Update, MCUXCLMAC_STATUS_FAILURE);
            }

            /* The partial data buffer is now empty. */
            pCtx->nrOfUnprocessedBytes = 0u;
        }

        /* Process remaining full blocks (excluding last block!) from input buffer */
        if(inLenOri < 1u)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Update, MCUXCLMAC_STATUS_FAILURE);
        }

        lastBlockRemainingBytes = (inLenOri - 1u) % MCUXCLOSCCASM4_BLOCK_SIZE + 1u; /* "lazy" processing */
        fullBlocksRemainingBytes = inLenOri - lastBlockRemainingBytes;
        while((fullBlocksRemainingBytes / MCUXCLOSCCASM4_BLOCK_SIZE) > 0U)
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pIn[inOffset] can't exceed the pIn buffer")
            MCUX_CSSL_FP_FUNCTION_CALL(statusBufferRead, mcuxClBuffer_read(pIn, inOffset, pCtx->stateIn, MCUXCLOSCCASM4_BLOCK_SIZE));
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
            (void)statusBufferRead; // No need to check it because the function only returns OK.

            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pCtx->stateIn, pCtx->stateIn, pCtx->stateIv, MCUXCLOSCCASM4_BLOCK_SIZE));
            MCUX_CSSL_FP_FUNCTION_CALL(engineRet2, mcuxClOsccaSm4_Engine(pRoundKeys, pCtx->stateIn, pCtx->stateIv, MCUXCLOSCCASM4_ENCRYPT));
            if(engineRet2 != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Update, MCUXCLMAC_STATUS_FAILURE);
            }

            /* The bytes copied already should not be taken into account further. */
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("inOffset += MCUXCLOSCCASM4_BLOCK_SIZE can't be larger than max(uint32_t)")
            inOffset += MCUXCLOSCCASM4_BLOCK_SIZE;
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
            fullBlocksRemainingBytes -= MCUXCLOSCCASM4_BLOCK_SIZE;
            inLenOri -= MCUXCLOSCCASM4_BLOCK_SIZE;
            pCtx->dataProcessed += MCUXCLOSCCASM4_BLOCK_SIZE;
        }

        /* Add last data into the data buffer*/
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pIn[inOffset] can't exceed the pIn buffer")
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferRead, mcuxClBuffer_read(pIn, inOffset, pCtx->stateIn, lastBlockRemainingBytes));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        (void)statusBufferRead; // No need to check it because the function only returns OK.
        pCtx->nrOfUnprocessedBytes = lastBlockRemainingBytes;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("lastBlockRemainingBytes is less than MCUXCLOSCCASM4_BLOCK_SIZE and pCtx->dataProcessed can't be larger than max(uint32_t)")
        pCtx->dataProcessed += lastBlockRemainingBytes;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        /* Free CPU WA */
        mcuxClSession_freeWords_cpuWa(session, MCUXCLOSCCASM4_RK_WORDS);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Update, MCUXCLMAC_STATUS_OK,
        MCUX_CSSL_FP_CONDITIONAL((inLength != inLenOri),
            ((inLength - lastBlockRemainingBytes) / MCUXCLOSCCASM4_BLOCK_SIZE) * (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
                                                                               + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor)
                                                                               + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine))));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_Engine_CMAC_Finalize, mcuxClOsccaMac_FinishEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Finalize(
  mcuxClSession_Handle_t session,
  mcuxClOsccaMacModes_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutLength
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_Engine_CMAC_Finalize);
    mcuxClOsccaMacModes_Context_t* pCtx = (mcuxClOsccaMacModes_Context_t *)pContext;

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Cast to correct pointer type")
    uint32_t* pCmacFinalBuf = (uint32_t*)mcuxClSession_allocateWords_cpuWa(session,  MCUXCLOSCCASM4_BLOCK_SIZE_WORDS * 2u + MCUXCLOSCCASM4_RK_WORDS);
    if(NULL == pCmacFinalBuf)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Finalize, MCUXCLMAC_STATUS_FAILURE);
    }
    uint32_t* pRoundKeys = pCmacFinalBuf;
    uint8_t* pK1K2 = (uint8_t*)(pRoundKeys + MCUXCLOSCCASM4_RK_WORDS); //temporary buffer for the K1 or K2 store of CMAC mode
    uint8_t* pStateOut = pK1K2 + MCUXCLOSCCASM4_BLOCK_SIZE;  ///< intermediate result of the mac operation
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    MCUX_CSSL_FP_FUNCTION_CALL(setupResult, mcuxClOsccaSm4_ScheduleSM4Key(pRoundKeys, pCtx->pKey->container.pData, MCUXCLOSCCASM4_ENCRYPT));
    if(MCUXCLOSCCASM4_STATUS_LOADKEY_OK != setupResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Finalize, MCUXCLMAC_STATUS_FAILURE);
    }

    //use pK1K2 to store the K1
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pStateOut,MCUXCLOSCCASM4_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL(engineRet, mcuxClOsccaSm4_Engine(pRoundKeys, pStateOut, pStateOut, MCUXCLOSCCASM4_ENCRYPT));
    if(engineRet != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Finalize, MCUXCLMAC_STATUS_FAILURE);
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOsccaMacModes_SM4_Gen_K1K2(pK1K2, pStateOut));

    if(pCtx->nrOfUnprocessedBytes == MCUXCLOSCCASM4_BLOCK_SIZE)//for this situation, use K1 to get the last block input data
    {
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pCtx->stateIn, pCtx->stateIn, pK1K2, MCUXCLOSCCASM4_BLOCK_SIZE));
    }
    else /* input was not a multiple of the blocksize or inputLen = 0 - add padding and use K2 to get the last block input data */
    {
      /* Number of bytes added by the padding. */
      uint32_t padOutLength = 0u;
      /* Apply the padding function, for CMAC, it's only mcuxClPadding_addPadding_ISO9797_1_Method2 mode*/
      MCUX_CSSL_FP_FUNCTION_CALL(padResult, mcuxClPadding_addPadding_ISO9797_1_Method2(MCUXCLOSCCASM4_BLOCK_SIZE, pCtx->stateIn, pCtx->nrOfUnprocessedBytes,
                                         pCtx->dataProcessed, pCtx->stateIn, &padOutLength));
      if (padResult != MCUXCLPADDING_STATUS_OK)
      {
          MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Finalize, MCUXCLMAC_STATUS_FAILURE);
      }
      // Cal K2 to store in pStateOut
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOsccaMacModes_SM4_Gen_K1K2(pStateOut, pK1K2));
      // K2^pCtx->stateIn to get the last block input data for cmacMode
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pCtx->stateIn, pCtx->stateIn, pStateOut, MCUXCLOSCCASM4_BLOCK_SIZE));
    }

    /* Process the last block input data */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pCtx->stateIn, pCtx->stateIn, pCtx->stateIv, MCUXCLOSCCASM4_BLOCK_SIZE));
    MCUX_CSSL_FP_FUNCTION_CALL(engineRet2, mcuxClOsccaSm4_Engine(pRoundKeys, pCtx->stateIn, pStateOut, MCUXCLOSCCASM4_ENCRYPT));
    if(engineRet2 != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Finalize, MCUXCLMAC_STATUS_FAILURE);
    }

    /* Copy the last result to the output and update pOutLength accordingly. */
    MCUX_CSSL_FP_FUNCTION_CALL(statusBufferWrite, mcuxClBuffer_write(pOut, 0u, pStateOut, MCUXCLOSCCASM4_BLOCK_SIZE));
    (void)statusBufferWrite; // No need to check it because the function only returns OK.

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Caller should set *pOutLength properly to make sure not to wrap")
    *pOutLength += MCUXCLOSCCASM4_BLOCK_SIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Free CPU WA */
    MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)pCmacFinalBuf, sizeof(uint32_t) * MCUXCLOSCCASM4_BLOCK_SIZE_WORDS * 2u + MCUXCLOSCCASM4_RK_WORDS);
    mcuxClSession_freeWords_cpuWa(session, MCUXCLOSCCASM4_BLOCK_SIZE_WORDS * 2u + MCUXCLOSCCASM4_RK_WORDS);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Finalize, MCUXCLMAC_STATUS_OK,
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_ScheduleSM4Key),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_SM4_Gen_K1K2),
              MCUX_CSSL_FP_CONDITIONAL((pCtx->nrOfUnprocessedBytes == MCUXCLOSCCASM4_BLOCK_SIZE),
                                                                          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor)),
              MCUX_CSSL_FP_CONDITIONAL((pCtx->nrOfUnprocessedBytes != MCUXCLOSCCASM4_BLOCK_SIZE),
                                                                          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2),
                                                                          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor),
                                                                          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_SM4_Gen_K1K2)),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)
              );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, mcuxClOsccaMac_ComputeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_Engine_CMAC_Oneshot(
    mcuxClSession_Handle_t session,
    mcuxClMac_Mode_t mode UNUSED_PARAM,
    mcuxClKey_Handle_t key,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutLength
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_ScheduleSM4Key),
                                                                   3u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
                                                                   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine),
                                                                   MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_SM4_Gen_K1K2));
    uint32_t* pCmacOneshotBuf = (uint32_t*)mcuxClSession_allocateWords_cpuWa(session,  MCUXCLOSCCASM4_BLOCK_SIZE_WORDS * 4u + MCUXCLOSCCASM4_RK_WORDS);
    if(NULL == pCmacOneshotBuf)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUXCLMAC_STATUS_FAILURE);
    }

    uint32_t* pRoundKeys = pCmacOneshotBuf;
    uint8_t* pK1K2 = (uint8_t*)(pRoundKeys + MCUXCLOSCCASM4_RK_WORDS);
    uint8_t *pStateIn = pK1K2 + MCUXCLOSCCASM4_BLOCK_SIZE;
    uint8_t *pStateIv = pStateIn + MCUXCLOSCCASM4_BLOCK_SIZE;
    uint8_t *pStateOut = pStateIv + MCUXCLOSCCASM4_BLOCK_SIZE;

    MCUX_CSSL_FP_FUNCTION_CALL(setupResult, mcuxClOsccaSm4_ScheduleSM4Key(pRoundKeys, key->container.pData, MCUXCLOSCCASM4_ENCRYPT));
    if(MCUXCLOSCCASM4_STATUS_LOADKEY_OK != setupResult)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUXCLMAC_STATUS_FAILURE);
    }

    MCUXCLMEMORY_FP_MEMORY_CLEAR(pStateIv,MCUXCLOSCCASM4_BLOCK_SIZE);
    //use pK1K2 to store the K1
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pStateOut,MCUXCLOSCCASM4_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL(engineRet, mcuxClOsccaSm4_Engine(pRoundKeys, pStateOut, pStateOut, MCUXCLOSCCASM4_ENCRYPT));
    if(engineRet != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUXCLMAC_STATUS_FAILURE);
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOsccaMacModes_SM4_Gen_K1K2(pK1K2, pStateOut));

    uint32_t inLenOri = inLength;
    uint32_t inOffset = 0u;
    while(inLenOri >= MCUXCLOSCCASM4_BLOCK_SIZE)
    {
        /* Add data into the pState buffer and process */
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferRead, mcuxClBuffer_read(pIn, inOffset, pStateIn, MCUXCLOSCCASM4_BLOCK_SIZE));
        (void)statusBufferRead; // No need to check it because the function only returns OK.

        //for this situation, use K1 to get the last block input data
        if(inLenOri == MCUXCLOSCCASM4_BLOCK_SIZE)
        {
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pStateIn, pStateIn, pK1K2, MCUXCLOSCCASM4_BLOCK_SIZE));
        }

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pStateIn, pStateIn, pStateIv, MCUXCLOSCCASM4_BLOCK_SIZE));
        MCUX_CSSL_FP_FUNCTION_CALL(engineRet2, mcuxClOsccaSm4_Engine(pRoundKeys, pStateIn, pStateIv, MCUXCLOSCCASM4_ENCRYPT));
        if(engineRet2 != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUXCLMAC_STATUS_FAILURE);
        }

        /* The bytes copied already should not be taken into account further. */
        inLenOri -= MCUXCLOSCCASM4_BLOCK_SIZE;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("inOffset += MCUXCLOSCCASM4_BLOCK_SIZE can't be larger than max(uint32_t)")
        inOffset += MCUXCLOSCCASM4_BLOCK_SIZE;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    if((inLenOri > 0u) || (inLength == 0u))
    {
        /* Number of bytes added by the padding. */
        uint32_t padOutLength = 0u;
        // Get input data for last block
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferRead, mcuxClBuffer_read(pIn, inOffset, pStateIn, inLenOri));
        (void)statusBufferRead; // No need to check it because the function only returns OK.

        /* Apply the padding function, for CMAC, it's only mcuxClPadding_addPadding_ISO9797_1_Method2 mode*/
        MCUX_CSSL_FP_FUNCTION_CALL(padResult, mcuxClPadding_addPadding_ISO9797_1_Method2(MCUXCLOSCCASM4_BLOCK_SIZE, pStateIn, inLenOri,
                                         inLength, pStateIn, &padOutLength));
        if (padResult != MCUXCLPADDING_STATUS_OK)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUXCLMAC_STATUS_FAILURE);
        }
        // Cal K2 to store in pStateOut
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOsccaMacModes_SM4_Gen_K1K2(pStateOut, pK1K2));
        // K2^blocks[in].data to get the last block input data for cmacMode
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pStateIn, pStateIn, pStateOut, MCUXCLOSCCASM4_BLOCK_SIZE));
        /* If padding was added, process the data in the pStateIn buffer. */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_FastSecureXor(pStateIn, pStateIn, pStateIv, MCUXCLOSCCASM4_BLOCK_SIZE));
        MCUX_CSSL_FP_FUNCTION_CALL(engineRet3, mcuxClOsccaSm4_Engine(pRoundKeys, pStateIn, pStateOut, MCUXCLOSCCASM4_ENCRYPT));
        if(engineRet3 != MCUXCLOSCCASM4_STATUS_CRYPT_OK)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUXCLMAC_STATUS_FAILURE);
        }
        /* Copy the padding to the output and update pOutLength accordingly. */
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferWrite, mcuxClBuffer_write(pOut, 0u, pStateOut, padOutLength));
        (void)statusBufferWrite; // No need to check it because the function only returns OK.

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Caller should set *pOutLength properly to make sure not to wrap")
        *pOutLength += padOutLength;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }
    else
    {
        /* Copy the padding to the output and update pOutLength accordingly. */
        MCUX_CSSL_FP_FUNCTION_CALL(statusBufferWrite, mcuxClBuffer_write(pOut, 0u, pStateIv, MCUXCLOSCCASM4_BLOCK_SIZE));
        (void)statusBufferWrite; // No need to check it because the function only returns OK.

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Caller should set *pOutLength properly to make sure not to wrap")
        *pOutLength += MCUXCLOSCCASM4_BLOCK_SIZE;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    /* Free CPU WA */
    MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)pCmacOneshotBuf, sizeof(uint32_t) * (MCUXCLOSCCASM4_BLOCK_SIZE_WORDS * 4u + MCUXCLOSCCASM4_RK_WORDS));
    mcuxClSession_freeWords_cpuWa(session, MCUXCLOSCCASM4_BLOCK_SIZE_WORDS * 4u + MCUXCLOSCCASM4_RK_WORDS);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_Engine_CMAC_Oneshot, MCUXCLMAC_STATUS_OK,
           (inLength / MCUXCLOSCCASM4_BLOCK_SIZE) * (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
                                                    + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor)
                                                    + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine)),
           MCUX_CSSL_FP_CONDITIONAL(((inLenOri == 0u) && (inLength != 0u)), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor)),
           MCUX_CSSL_FP_CONDITIONAL(((inLenOri > 0u) || (inLength == 0u)), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
                                                                          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2),
                                                                          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaMacModes_SM4_Gen_K1K2),
                                                                          2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_FastSecureXor),
                                                                          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Engine)
                                  ),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write)
          );
}

