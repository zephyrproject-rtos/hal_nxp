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

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_Cbc_Enc, mcuxClCipherModes_EngineFunc_AesSgi_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_Cbc_Enc(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t* pIvOut,
  uint32_t* const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_Cbc_Enc);

  /* Higher level caller is responsible for bound checking */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*pOutLength, 0U, UINT32_MAX - inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inLength, 1U, UINT32_MAX - *pOutLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)

  const uint32_t numFullBlocks = inLength / MCUXCLAES_BLOCK_SIZE;

  uint32_t outOffset = 0U;
  /* Record the number of blocks plus the SGI COUNT for DI protection. */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount, mcuxClSgi_Drv_getCount());

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("value used for SC balancing which supports unsigned overflow behaviour")
  const uint32_t sgiCount = numFullBlocks + currCount;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  const uint32_t sgiCountOverflow = sgiCount & 0xFFFF0000U; // since SGI_COUNT is 16-bit register, save the possibly overflowed value and use it in DI_EXPUNGE at the end
  MCUX_CSSL_DI_RECORD(sgiCount, sgiCount);

  /* SREQI_BCIPHER_8 - Balance the block loads to SGI DATIN, i.e. the calls to mcuxClSgi_Utils_load128BitBlock */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("value used for SC balancing which supports unsigned overflow behaviour")
  uint32_t sumOfOffsets = (MCUXCLAES_BLOCK_SIZE / 2U) * (numFullBlocks - 1U) * numFullBlocks;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  // sumOfOffsets = MCUXCLAES_BLOCK_SIZE * (0 + 1 + 2 + .. + (numFullBlocks-1))
  //              = MCUXCLAES_BLOCK_SIZE * ((numFullBlocks-1) * numFullBlocks) / 2
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, sumOfOffsets);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, numFullBlocks * (uint32_t)pIn);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, numFullBlocks * (uint32_t)MCUXCLAES_BLOCK_SIZE);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, (uint32_t)(MCUXCLSGI_DRV_DATIN1_OFFSET)); // first iteration load to DATIN1
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, (numFullBlocks - 1U) * (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET)); // iterations in the loop load to DATIN0

  /* SREQI_BCIPHER_8 - Balance DI for mcuxClSgi_Utils_store128BitBlock calls */
  MCUX_CSSL_DI_RECORD(sgiStoreParam, sumOfOffsets);
  MCUX_CSSL_DI_RECORD(sgiStoreParam, numFullBlocks * (uint32_t)pOut);
  MCUX_CSSL_DI_RECORD(sgiStoreParam, numFullBlocks * (uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET));
  MCUX_CSSL_DI_RECORD(sgiStoreParam, numFullBlocks * MCUXCLAES_BLOCK_SIZE);

  MCUX_CSSL_FP_FUNCTION_CALL(retXorWrite, mcuxClSgi_Drv_enableXorWrite());
  (void)retXorWrite;

  /* load first plain block to the DATIN1 */
  /* the IV is already loaded in the DATIN1 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN1_OFFSET, pIn));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_disableXorWrite());

  // start calc
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
	  MCUXCLSGI_DRV_CTRL_NO_UP         |
	  MCUXCLSGI_DRV_CTRL_ENC           |
	  MCUXCLSGI_DRV_CTRL_INSEL_DATIN1  |
	  MCUXCLSGI_DRV_CTRL_OUTSEL_RES    |
	  pWa->sgiWa.sgiCtrlKey));

  uint32_t inOffset = MCUXCLAES_BLOCK_SIZE;

  for(uint32_t i = 1U; i < numFullBlocks; ++i)
  {
    // Copy input to SGI
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pIn + inOffset));

    // wait for finish
	  mcuxClSgi_Drv_wait();

    // start_up
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
		MCUXCLSGI_DRV_CTRL_START_UP                |
		MCUXCLSGI_DRV_CTRL_ENC                     |
		MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT |
		MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
		pWa->sgiWa.sgiCtrlKey));

    // Copy result to user
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pOut + outOffset));

    inOffset += MCUXCLAES_BLOCK_SIZE;
    outOffset += MCUXCLAES_BLOCK_SIZE;
  }

  // wait for finish
  mcuxClSgi_Drv_wait();

  /* Start SGI with TRIGGER_UP, no cryptographic operation executed */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_TRIGGER_UP));

  // wait for finish
  mcuxClSgi_Drv_wait();

  // Copy result to user
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pOut + outOffset));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("total outOffset is bounded by inLength")
  outOffset += MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  if(NULL != pIvOut)
  {
    MCUX_CSSL_DI_RECORD(sgiStore, ((uint32_t)MCUXCLSGI_DRV_DATOUT_OFFSET) + ((uint32_t)pIvOut) + 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, (uint8_t *)pIvOut));
  }

  /* outOffset is bounded by inLength */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(outOffset, 0U, inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  *pOutLength += outOffset;

  /* Expunge the current value of the SGI COUNT plus the possibly overflowed value for DI protection.
     The sum is equal to the SGI COUNT in the beginning plus the number of full blocks. */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount2, mcuxClSgi_Drv_getCount());
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Cannot overflow, since currCount2 < 2^16 and the lower 16 bits of sgiCountOverflow are 0.")
  uint32_t endCount = sgiCountOverflow + currCount2;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  MCUX_CSSL_DI_EXPUNGE(sgiCount, endCount);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_Cbc_Enc, MCUXCLCIPHER_STATUS_OK,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_disableXorWrite),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
      ( (numFullBlocks - 1U) * (
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)
        + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
        + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock))
      ),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
      MCUX_CSSL_FP_CONDITIONAL((NULL != pIvOut),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_Cbc_Dec, mcuxClCipherModes_EngineFunc_AesSgi_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_Cbc_Dec(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t* pIvOut,
  uint32_t* const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_Cbc_Dec);

  /* Higher level caller is responsible for bound checking */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*pOutLength, 0U, UINT32_MAX - inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(inLength, 1U, UINT32_MAX - *pOutLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)

  const uint32_t numFullBlocks = inLength / MCUXCLAES_BLOCK_SIZE;

  uint32_t outOffset = 0U;
  /* Record the number of blocks plus the SGI COUNT for DI protection. */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount, mcuxClSgi_Drv_getCount());
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("value used for SC balancing which supports unsigned overflow behaviour")
  const uint32_t sgiCount = numFullBlocks + currCount;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  const uint32_t sgiCountOverflow = sgiCount & 0xFFFF0000U; // since SGI_COUNT is 16-bit register, save the possibly overflowed value and use it in DI_EXPUNGE at the end
  MCUX_CSSL_DI_RECORD(sgiCount, sgiCount);

  /* SREQI_BCIPHER_8 - Balance the block loads to SGI DATIN, i.e. the calls to mcuxClSgi_Utils_load128BitBlock */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("value used for SC balancing which supports unsigned overflow behaviour")
  uint32_t sumOfOffsets = (MCUXCLAES_BLOCK_SIZE / 2U) * (numFullBlocks - 1U) * numFullBlocks;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  // sumOfOffsets = MCUXCLAES_BLOCK_SIZE * (0 + 1 + 2 + .. + (numFullBlocks-1))
  //              = MCUXCLAES_BLOCK_SIZE * ((numFullBlocks-1) * numFullBlocks) / 2
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, sumOfOffsets);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, numFullBlocks * (uint32_t)pIn);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, numFullBlocks * MCUXCLAES_BLOCK_SIZE);
  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET));

  /* SREQI_BCIPHER_8 - Balance DI for mcuxClSgi_Utils_store128BitBlock */
  MCUX_CSSL_DI_RECORD(sgiStoreParam, sumOfOffsets);
  MCUX_CSSL_DI_RECORD(sgiStoreParam, numFullBlocks * (uint32_t)pOut);
  MCUX_CSSL_DI_RECORD(sgiStoreParam, numFullBlocks * (uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET));
  MCUX_CSSL_DI_RECORD(sgiStoreParam, numFullBlocks * MCUXCLAES_BLOCK_SIZE);

  /* input cipher block 0 -> DATA0 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pIn));

  // start calc
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
      MCUXCLSGI_DRV_CTRL_NO_UP                 |
      MCUXCLSGI_DRV_CTRL_DEC                   |
      MCUXCLSGI_DRV_CTRL_INSEL_DATIN0          |
      pWa->sgiWa.sgiCtrlKey));

  uint32_t inOffset = MCUXCLAES_BLOCK_SIZE;
  static const uint32_t sgiInputOffset[3] = {MCUXCLSGI_DRV_DATIN0_OFFSET, MCUXCLSGI_DRV_DATIN2_OFFSET, MCUXCLSGI_DRV_DATIN1_OFFSET};
  static const uint32_t sgiInSel[3] = {MCUXCLSGI_DRV_CTRL_INSEL_DATIN0, MCUXCLSGI_DRV_CTRL_INSEL_DATIN2, MCUXCLSGI_DRV_CTRL_INSEL_DATIN1};
  static const uint32_t sgiOutSel[3] = {MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN2, MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN1, MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN0};

  uint32_t i = 1U;
  for(; i < numFullBlocks; ++i)
  {
    // Copy input to SGI
    MCUX_CSSL_DI_RECORD(sgiLoadBuffer, (uint32_t)(sgiInputOffset[i % 3U]));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(sgiInputOffset[i % 3U], pIn + inOffset));

    // wait for finish
    mcuxClSgi_Drv_wait();

    // start_up
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_START_UP              |
                                                      MCUXCLSGI_DRV_CTRL_DEC                   |
                                                      MCUXCLSGI_DRV_CTRL_AES_NO_KL             |
                                                      sgiInSel[i % 3U]                        |
                                                      sgiOutSel[i % 3U]                       |
                                                      pWa->sgiWa.sgiCtrlKey));

    // Copy result to user
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pOut + outOffset));

    inOffset += MCUXCLAES_BLOCK_SIZE;
    outOffset += MCUXCLAES_BLOCK_SIZE;
  }

  // wait for finish
  mcuxClSgi_Drv_wait();

  /* Start SGI with TRIGGER_UP, no cryptographic operation executed */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_TRIGGER_UP | sgiOutSel[i % 3U]));

  // wait for finish
  mcuxClSgi_Drv_wait();

  // Copy result to user
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, pOut + outOffset)); /* store P0 */

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("total outOffset is bounded by inLength")
  outOffset += MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  if(NULL != pIvOut)
  {
    MCUX_CSSL_DI_RECORD(sgiStore, ((uint32_t)(sgiInputOffset[(i - 1U) % 3U])) + ((uint32_t)pIvOut) + 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(sgiInputOffset[(i - 1U) % 3U], (uint8_t *)pIvOut));
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(outOffset, 0U, inLength, MCUXCLCIPHER_STATUS_INVALID_INPUT)
  *pOutLength += outOffset;

  /* Expunge the current value of the SGI COUNT plus the possibly overflowed value for DI protection.
     The sum is equal to the SGI COUNT in the beginning plus the number of full blocks. */
  MCUX_CSSL_FP_FUNCTION_CALL(currCount2, mcuxClSgi_Drv_getCount());
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Cannot overflow, since currCount2 < 2^16 and the lower 16 bits of sgiCountOverflow are 0.")
  uint32_t endCount = sgiCountOverflow + currCount2;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  MCUX_CSSL_DI_EXPUNGE(sgiCount, endCount);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCipherModes_Cbc_Dec, MCUXCLCIPHER_STATUS_OK,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
      ( (numFullBlocks - 1U) * (
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)
          + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)
          + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
        )
      ),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
      MCUX_CSSL_FP_CONDITIONAL((NULL != pIvOut),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_getCount)
  );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_NoPadding_Sgi =
{
  .encryptEngine                                 = mcuxClCipherModes_Cbc_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Cbc_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Dec),
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
  .addPadding                                    = mcuxClPadding_addPadding_None,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_None),
  .removePadding                                 = NULL,
  .protectionToken_removePadding                 = 0U,
  .granularityEnc                                = MCUXCLAES_BLOCK_SIZE,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};

const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method1_Sgi =
{
  .encryptEngine                                 = mcuxClCipherModes_Cbc_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Cbc_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Dec),
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
  .addPadding                                    = mcuxClPadding_addPadding_ISO9797_1_Method1,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method1),
  .removePadding                                 = mcuxClPadding_removePadding_ISO9797_1_Method1,
  .protectionToken_removePadding                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_ISO9797_1_Method1),
  .granularityEnc                                = 1U,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};

const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingISO9797_1_Method2_Sgi =
{
  .encryptEngine                                 = mcuxClCipherModes_Cbc_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Cbc_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Dec),
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
  .addPadding                                    = mcuxClPadding_addPadding_ISO9797_1_Method2,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2),
  .removePadding                                 = mcuxClPadding_removePadding_ISO9797_1_Method2,
  .protectionToken_removePadding                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_ISO9797_1_Method2),
  .granularityEnc                                = 1U,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};

const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t mcuxClCipherModes_AlgorithmDescriptor_CBC_PaddingPKCS7_Sgi =
{
  .encryptEngine                                 = mcuxClCipherModes_Cbc_Enc,
  .protectionToken_encryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Enc),
  .decryptEngine                                 = mcuxClCipherModes_Cbc_Dec,
  .protectionToken_decryptEngine                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_Cbc_Dec),
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
  .addPadding                                    = mcuxClPadding_addPadding_PKCS7,
  .protectionToken_addPadding                    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_PKCS7),
  .removePadding                                 = mcuxClPadding_removePadding_PKCS7,
  .protectionToken_removePadding                 = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_PKCS7),
  .granularityEnc                                = 1U,
  .granularityDec                                = MCUXCLAES_BLOCK_SIZE
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
