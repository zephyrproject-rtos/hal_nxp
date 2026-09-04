/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

#include <mcuxClToolchain.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClAes.h>

#include <mcuxClSession.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClCipherModes_Sgi_Aes_Iv.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_Ctr, mcuxClCipherModes_EngineFunc_AesSgi_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_Ctr(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t* pIvOut,
  uint32_t* const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_Ctr);

  /* Higher level caller is responsible for bound checking */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*pOutLength, 0U, UINT32_MAX - inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inLength, 1U, UINT32_MAX - *pOutLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)

  uint32_t outOffset = 0U;
  uint32_t inOffset = MCUXCLAES_BLOCK_SIZE;

  /* number of full blocks */
  uint32_t numFullBlocks  = inLength / MCUXCLAES_BLOCK_SIZE;
  /* length of the last block, will be 0 < lastBlockLength <= MCUXCLAES_BLOCK_SIZE (for an inLength > 0) */
  uint32_t lastBlockLength = (0U == numFullBlocks ) ? (inLength % MCUXCLAES_BLOCK_SIZE) : MCUXCLAES_BLOCK_SIZE;
  /* number of SGI operations, including process of the last block if not full */
  const uint32_t numOperations = (MCUXCLAES_BLOCK_SIZE == lastBlockLength) ? numFullBlocks  : MCUXCLCORE_NUM_OF_WORDS_CEIL(MCUXCLAES_BLOCK_SIZE, lastBlockLength);
  /* numOperations cannot be 0U */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(numOperations, 1U, UINT32_MAX, MCUXCLCIPHER_STATUS_INVALID_INPUT)

  /* Record the number of operations plus the SGI COUNT for DI protection. */
  MCUX_CSSL_ANALYSIS_START_PATTERN_SC_INTEGER_OVERFLOW()
  MCUX_CSSL_FP_FUNCTION_CALL(currCount, mcuxClSgi_Drv_getCount());
  const uint32_t sgiCount = numOperations + currCount;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SC_INTEGER_OVERFLOW()

  const uint32_t sgiCountOverflow = sgiCount & 0xFFFF0000U; /* since SGI_COUNT is 16-bit register, save the possibly overflowed value and use it in DI_EXPUNGE at the end */
  MCUX_CSSL_DI_RECORD(sgiCount, sgiCount);

  /* SREQI_BCIPHER_8 - Balance the block loads to SGI DATIN, i.e. the calls to mcuxClSgi_Utils_load128BitBlock */
  MCUX_CSSL_ANALYSIS_START_PATTERN_SC_INTEGER_OVERFLOW()
  uint32_t sumOfOffsets = (MCUXCLAES_BLOCK_SIZE / 2U) * (numOperations - 1U) * numOperations;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_SC_INTEGER_OVERFLOW()
  /* sumOfOffsets = MCUXCLAES_BLOCK_SIZE * (0 + 1 + 2 + .. + (numOperations-1))    */
  /*              = MCUXCLAES_BLOCK_SIZE * ((numOperations-1) * numOperations) / 2 */
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, sumOfOffsets);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, numOperations * (uint32_t)pIn);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, numOperations * MCUXCLAES_BLOCK_SIZE);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, numOperations * (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET));

  /* SREQI_BCIPHER_8 - Balance DI for copyOutFunction and mcuxClSgi_Utils_store128BitBlock calls */
  MCUX_CSSL_DI_RECORD(copyOutOrSgiStoreParams, sumOfOffsets);
  MCUX_CSSL_DI_RECORD(copyOutOrSgiStoreParams, numOperations * (uint32_t)pOut);
  MCUX_CSSL_DI_RECORD(copyOutOrSgiStoreParams, numOperations * (uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET));
  MCUX_CSSL_DI_RECORD(copyOutOrSgiStoreParams, (numOperations - 1U) * MCUXCLAES_BLOCK_SIZE);
  MCUX_CSSL_DI_RECORD(copyOutOrSgiStoreParams, lastBlockLength);

  /* Balance DI for mcuxClSgi_Drv_incrementData calls */
  MCUX_CSSL_DI_RECORD(inputParam, (MCUXCLSGI_DRV_DATIN1_OFFSET + (MCUXCLAES_BLOCK_SIZE - pWa->ctrSize)) * numOperations);
  MCUX_CSSL_DI_RECORD(incLength, pWa->ctrSize * numOperations);

  /* start_up first block crypto operation without an update of DATOUT */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_NO_UP                 |
                                                    MCUXCLSGI_DRV_CTRL_ENC                   |
                                                    MCUXCLSGI_DRV_CTRL_INSEL_DATIN1          |  /* Counter is loaded into DATIN1 */
                                                    pWa->sgiWa.sgiCtrlKey));

  /* Process the first block, which may be smaller than MCUXCLAES_BLOCK_SIZE */
  /* Copy input to SGI */
  if(inLength < MCUXCLAES_BLOCK_SIZE)
  {
      MCUX_CSSL_DI_RECORD(sgiLoadBuffer, inLength - MCUXCLAES_BLOCK_SIZE + pWa->sgiWa.paddingBuff); /* balancing already recorded parametes */
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load_notFull128Block_buffer(MCUXCLSGI_DRV_DATIN0_OFFSET, pIn, inLength, pWa->sgiWa.paddingBuff));
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pIn));
  }


  for(uint32_t i = 1U; i < numFullBlocks ; ++i)
  {
    /* Increase counter value */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pWa->ctrSize, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLCIPHER_STATUS_INVALID_INPUT)
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_incrementData(MCUXCLSGI_DRV_DATIN1_OFFSET + (MCUXCLAES_BLOCK_SIZE - pWa->ctrSize), pWa->ctrSize));

    /* wait for finish */
    mcuxClSgi_Drv_wait();
    /* Start up SGI, update DATOUT at the start of the operation. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_START_UP              |
                                                      MCUXCLSGI_DRV_CTRL_ENC                   |
                                                      MCUXCLSGI_DRV_CTRL_INSEL_DATIN1          |
                                                      MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN0 |
                                                      pWa->sgiWa.sgiCtrlKey));

    // Copy result to user
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pOut + outOffset)); /* Copy result to user */

    /* Copy input to SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pIn + inOffset));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("total outOffset / inOffset is bounded by inLength")
    inOffset += MCUXCLAES_BLOCK_SIZE;
    outOffset += MCUXCLAES_BLOCK_SIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  }

  mcuxClSgi_Drv_wait();

  /* Start SGI with TRIGGER_UP, no cryptographic operation executed */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_TRIGGER_UP            |
                                                    MCUXCLSGI_DRV_CTRL_ENC                   |
                                                    MCUXCLSGI_DRV_CTRL_INSEL_DATIN1          |
                                                    MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN0 |
                                                    pWa->sgiWa.sgiCtrlKey));

  // Increase counter value
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pWa->ctrSize, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_incrementData(MCUXCLSGI_DRV_DATIN1_OFFSET + (MCUXCLAES_BLOCK_SIZE - pWa->ctrSize), pWa->ctrSize));

  /* wait for finish */
  mcuxClSgi_Drv_wait();

  // Copy result to user - might not be a full block
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pWa->sgiWa.copyOutFunction(pWa, pOut, outOffset, lastBlockLength));
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("total outOffset is bounded by inLength")
  outOffset += lastBlockLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  if(NULL != pIvOut)
  {
    MCUX_CSSL_DI_RECORD(sgiStore, ((uint32_t)(MCUXCLSGI_DRV_DATIN1_OFFSET)) + ((uint32_t)pIvOut) + 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATIN1_OFFSET, (uint8_t *)pIvOut));
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(outOffset, 0U, inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  *pOutLength += outOffset;

  /* Expunge the current value of the SGI COUNT plus the possibly overflowed value for DI protection.
     The sum is equal to the SGI COUNT in the beginning plus the number of operations. */

  MCUX_CSSL_FP_FUNCTION_CALL(currCount2, mcuxClSgi_Drv_getCount());
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Cannot overflow, since currCount2 < 2^16 and the lower 16 bits of sgiCountOverflow are 0.")
  uint32_t endCount = sgiCountOverflow + currCount2;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  MCUX_CSSL_DI_EXPUNGE(sgiCount, endCount);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_Ctr, MCUXCLCIPHER_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    MCUX_CSSL_FP_CONDITIONAL( (inLength < MCUXCLAES_BLOCK_SIZE),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load_notFull128Block_buffer)),
    MCUX_CSSL_FP_CONDITIONAL( (inLength >= MCUXCLAES_BLOCK_SIZE),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)),
    MCUX_CSSL_FP_CONDITIONAL((numFullBlocks > 1U),
    (numFullBlocks - 1U) * ( MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)
                            + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)
                            + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
                            + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_incrementData))),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_incrementData),
    pWa->sgiWa.protectionToken_copyOutFunction,
    MCUX_CSSL_FP_CONDITIONAL( (NULL != pIvOut),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount)
  );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CTR_Sgi =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  .encryptEngine                                 = mcuxClCipherModes_Ctr,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ctr),
  .decryptEngine                                 = mcuxClCipherModes_Ctr,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Ctr),
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
  .completeAutoModeEngine                        = NULL,
  .protectionToken_completeAutoModeEngine        = 0U,
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */
  .setupIVEncrypt                                = mcuxClCipherModes_IV,
  .protectionToken_setupIVEncrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_IV),
  .setupIVDecrypt                                = mcuxClCipherModes_IV,
  .protectionToken_setupIVDecrypt                = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_IV),
  .checkIvLength                                 = mcuxClCipherModes_checkIvLen,
  .protectionToken_checkIvLength                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_checkIvLen),
  .addPadding                                    = mcuxClPadding_addPadding_Stream,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_Stream),
  .removePadding                                 = mcuxClPadding_removePadding_Stream,
  .protectionToken_removePadding                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Stream),
  .granularityEnc                                = 1U,
  .granularityDec                                = 1U
};
