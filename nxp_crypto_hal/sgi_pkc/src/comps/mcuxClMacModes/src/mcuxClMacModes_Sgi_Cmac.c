/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClKey.h>
#include <mcuxClKey_Types.h>
#include <mcuxClMac.h>
#include <mcuxClMacModes_MemoryConsumption.h>
#include <mcuxClPadding.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMacModes_Common_Memory.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Algorithms.h>
#include <internal/mcuxClMacModes_Sgi_Cleanup.h>
#include <internal/mcuxClMacModes_Sgi_Cmac.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>

/* CMAC */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClMacModes_AlgorithmDescriptor_t mcuxClMacModes_AlgorithmDescriptor_CMAC =
{
  .compute = mcuxClMacModes_computeCMAC,
  .protectionToken_compute = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_computeCMAC),
  .handleLastBlock_oneshot = NULL,
  .init = NULL, /* no init needed */
  .update = mcuxClMacModes_updateCMAC,
  .protectionToken_update = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_updateCMAC),
  .finalize = mcuxClMacModes_finalizeCMAC,
  .protectionToken_finalize = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_finalizeCMAC),
  .copyOut = mcuxClMacModes_CopyOutNormal,
  .protectionToken_copyOut = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CopyOutNormal),
  .addPadding = mcuxClPadding_addPadding_MAC_ISO9797_1_Method2,
  .protectionToken_addPadding = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2),
};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/* Helper functions */

#ifndef MCUXCL_FEATURE_MACMODES_SGI_CMAC_SUB_KEYS
/**
 * @brief Internal function, which shifts the buffer pointed to by pSrc by one bit to the left, conditionally
 * XORs MCUXCLMACMODES_AES_CMAC_RB_CONST and stores the result in a buffer pointed to by pDst.
 *
 * @param[in]  pDst       Pointer to destination buffer.
 * @param[in]  pSrc       Pointer to source buffer.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_ShiftLeftXorRb)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_ShiftLeftXorRb(uint32_t* pDst, const uint32_t* pSrc)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_ShiftLeftXorRb);
  /* multiplication GF(2) */
  /* Dst = Src << 1  */

  uint8_t constRB = 0U;

  /* Test MSB of L := AES-128(K, const_zero); if it is one, XOR with MCUXCLMACMODES_AES_CMAC_RB_CONST  */
  if(MCUXCLMACMODES_AES_CMAC_MSB_MASK == (pSrc[0] & MCUXCLMACMODES_AES_CMAC_MSB_MASK))
  {
    constRB = MCUXCLMACMODES_AES_CMAC_RB_CONST;
  }

  MCUX_CSSL_FP_LOOP_DECL(loopShiftLeftXorRb);
  for(uint32_t i = 0U; i < 3U ; ++i)
  {
    pDst[i] = (pSrc[i] << 1U) | (pSrc[i + 1U] >> ((sizeof(uint32_t) * 8U) - 1U));
    MCUX_CSSL_FP_LOOP_ITERATION(loopShiftLeftXorRb);
  }

  pDst[3] = (pSrc[3]  << 1U) ^ constRB;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_ShiftLeftXorRb,
    MCUX_CSSL_FP_LOOP_ITERATIONS(loopShiftLeftXorRb, 3U)
  );
}
#endif

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_CmacGenerateSubKeys)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_CmacGenerateSubKeys(mcuxClSession_Handle_t session, mcuxClMacModes_WorkArea_t* pWa, uint32_t option)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_CmacGenerateSubKeys);

   /* subkeys are in big-endian, so we need to switch the SGI to BE (for the copy only) */
  MCUX_CSSL_FP_FUNCTION_CALL(retSetByteOrder, mcuxClSgi_Drv_setByteOrder((uint32_t)MCUXCLSGI_DRV_BYTE_ORDER_BE));
  (void)retSetByteOrder;

  /* Load zeroes to SGI input */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN1_OFFSET + 0U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN1_OFFSET + 4U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN1_OFFSET + 8U, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(MCUXCLSGI_DRV_DATIN1_OFFSET + 12U, 0U));

  /* start calc */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
    MCUXCLSGI_DRV_CTRL_END_UP                  |
    MCUXCLSGI_DRV_CTRL_ENC                     |
    MCUXCLSGI_DRV_CTRL_INSEL_DATIN1            |
    MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
    pWa->sgiWa.sgiCtrlKey));

  /* wait for finish */
  mcuxClSgi_Drv_wait();

#ifdef MCUXCL_FEATURE_MACMODES_SGI_CMAC_SUB_KEYS
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
    MCUXCLSGI_DRV_CTRL_END_UP                  |
    MCUXCLSGI_DRV_CTRL_ENC                     |
    MCUXCLSGI_DRV_CTRL_INSEL_DATOUT            |
    MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
    MCUXCLSGI_DRV_CTRL_CMAC));

  /* wait for finish */
  mcuxClSgi_Drv_wait();

  if(MCUXCLMACMODES_AES_CMAC_K1_AND_K2 == option)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
      MCUXCLSGI_DRV_CTRL_END_UP                |
      MCUXCLSGI_DRV_CTRL_ENC                   |
      MCUXCLSGI_DRV_CTRL_INSEL_DATOUT          |
      MCUXCLSGI_DRV_CTRL_OUTSEL_RES            |
      MCUXCLSGI_DRV_CTRL_CMAC));

    /* wait for finish */
    mcuxClSgi_Drv_wait();
  }
#else /* MCUXCL_FEATURE_MACMODES_SGI_CMAC_SUB_KEYS */
  uint32_t *subKey = (uint32_t *)pWa->algoWa.subKey; /* temporary buffer for shift subkey*/

  MCUX_CSSL_DI_RECORD(sgiStore, 2U * ((uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET) + (uint32_t)(subKey) + 16U) );

  /* Store result of encryption to temp buffer */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, (uint8_t *)(subKey)));

  /* Shift left result of encryption to generate subKey 1 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_ShiftLeftXorRb(subKey, subKey));        /* enc(0) -> multiplication GF(2) = subKey 1 */

  if(MCUXCLMACMODES_AES_CMAC_K1_AND_K2 == option)
  {
    /* Shift left subKey 1 to generate subKey 2 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_ShiftLeftXorRb(subKey, subKey));     /*   key1 -> multipMCUX_CSSL_FP_FUNCTION_CALLED_VOID(multiplication GF(2)) = subKey 2 */
  }

  /* Store subkey back to DATOUT */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, (uint8_t *)(subKey)));
#endif // MCUXCL_FEATURE_MACMODES_SGI_CMAC_SUB_KEYS

  MCUX_CSSL_FP_FUNCTION_CALL(retSetByteOrder2, mcuxClSgi_Drv_setByteOrder(MCUXCLSGI_DRV_BYTE_ORDER_LE));
  (void)retSetByteOrder2;


  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_CmacGenerateSubKeys,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_setByteOrder),
    (4U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_loadWord)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
#ifdef MCUXCL_FEATURE_MACMODES_SGI_CMAC_SUB_KEYS
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLMACMODES_AES_CMAC_K1_AND_K2 == option),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)),
#else
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_ShiftLeftXorRb),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLMACMODES_AES_CMAC_K1_AND_K2 == option),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_ShiftLeftXorRb)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock),
#endif // MCUXCL_FEATURE_MACMODES_SGI_CMAC_SUB_KEYS
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_setByteOrder)
  );
}

MCUX_CSSL_FP_COUNTER_STMT(
/* balancing the FP for non-blocking CMAC update engine */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_computeCMAC_balancingFP)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_computeCMAC_balancingFP(const uint32_t noOfBytesToProcess,
                                                                              const uint32_t inLengthInBlocks,
                                                                              const mcuxClMacModes_Algorithm_t pAlgo)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_computeCMAC_balancingFP);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_computeCMAC_balancingFP,

    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
    MCUX_CSSL_FP_CONDITIONAL((1U < inLengthInBlocks),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_loadZeroIV),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_engine),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)),
    MCUX_CSSL_FP_CONDITIONAL(((0U != noOfBytesToProcess) && (0U == (noOfBytesToProcess % MCUXCLAES_BLOCK_SIZE))),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CmacGenerateSubKeys),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLAES_BLOCK_SIZE != noOfBytesToProcess),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)),

    MCUX_CSSL_FP_CONDITIONAL(((0U == noOfBytesToProcess) || (0U != (noOfBytesToProcess % MCUXCLAES_BLOCK_SIZE))),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CmacGenerateSubKeys),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLAES_BLOCK_SIZE < noOfBytesToProcess),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite)),
      pAlgo->protectionToken_addPadding,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)),

    MCUX_CSSL_FP_CONDITIONAL((MCUXCLAES_BLOCK_SIZE < noOfBytesToProcess),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_disableXorWrite)),

    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_engine));
})


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_computeCMAC, mcuxClMacModes_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_computeCMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * workArea,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes UNUSED_PARAM
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_computeCMAC);

  mcuxClMacModes_Algorithm_t pAlgo = mcuxClMacModes_castToMacModesAlgorithm(mode->common.pAlgorithm);
  if(inLength > (UINT32_MAX - MCUXCLAES_BLOCK_SIZE))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLMAC_STATUS_INVALID_PARAM);
  }

  uint32_t operation = MCUXCLSGI_DRV_CTRL_END_UP                  |
                       MCUXCLSGI_DRV_CTRL_INSEL_DATIN0            |
                       MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
                       MCUXCLSGI_DRV_CTRL_ENC                     |
                       workArea->sgiWa.sgiCtrlKey;

  uint32_t inputOffset = 0U;
  uint32_t noOfBytesToProcess = inLength;
  uint32_t inLengthInBlocks = (inLength + (MCUXCLAES_BLOCK_SIZE - 1U)) / MCUXCLAES_BLOCK_SIZE;
  MCUX_CSSL_FP_FUNCTION_CALL(sfrSeed, mcuxClPrng_generate_word());

  /* processing full blocks without last block*/
  if(1U < inLengthInBlocks)
  {
    MCUX_CSSL_DI_RECORD(sgiLoad, (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET));
    MCUX_CSSL_DI_RECORD(sgiLoad, (uint32_t)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET));
    MCUX_CSSL_DI_RECORD(sgiLoad, 16U);

    uint32_t lenInBlocksLocal = (inLengthInBlocks-1U);
    /* Load all-zero IV to DATOUT */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_loadZeroIV());

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_engine(
      session,
      workArea,
      NULL,
      pIn,
      inputOffset,
      lenInBlocksLocal * MCUXCLAES_BLOCK_SIZE,
      sfrSeed,
      operation,
      mcuxClMacModes_updateEngine,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_updateEngine)));

    inputOffset += lenInBlocksLocal * MCUXCLAES_BLOCK_SIZE;

   /* Copy result to DATIN0, to save it while subkeys are generated. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, (const uint8_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET)));
  }

  /*
   * Handle last block.
   * 1) Store current output in DATIN0. In case there is only one block, current output will be 0.
   * 2) Using DATIN1, compute subkey k1 or k2, depending on whether block is full, and store in DATOUT.
   * 3) Xor (potentially padded) last input block onto DATIN0 using SGI XorWrite.
   * 4) Start SGI operation, xoring subkey from DATOUT onto DATIN0 using INSEL_DATIN0_XOR_DATOUT.
   */
  if((0U != noOfBytesToProcess) && (0U == (noOfBytesToProcess % MCUXCLAES_BLOCK_SIZE))) /* Remaining data is a single AES block. No padding needed. */
  {
    /* Record load input */
    MCUX_CSSL_DI_RECORD(sgiLoad, MCUXCLSGI_DRV_DATIN0_OFFSET);
    MCUX_CSSL_DI_RECORD(sgiLoad, (pIn + inputOffset));
    MCUX_CSSL_DI_RECORD(sgiLoad, 16U);
    /* Generate subkey */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_CmacGenerateSubKeys(session, workArea, MCUXCLMACMODES_AES_CMAC_K1_ONLY));

    /* for one block, the input can be loaded directly because it is equivalent to the input block ^ (IV = 0) */
    if(MCUXCLAES_BLOCK_SIZE != noOfBytesToProcess)
    {
       /* Enable XOR-on-write to XOR the saved previous output with the last input block */
       MCUX_CSSL_FP_FUNCTION_CALL(retXorWrite, mcuxClSgi_Drv_enableXorWrite());
       (void)retXorWrite;
    }

    /* Copy input to SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pIn + inputOffset));
  }
  else /* Add padding before loading data to SGI. */
  {
    /* Record load input */
    MCUX_CSSL_DI_RECORD(sgiLoad, (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET));
    MCUX_CSSL_DI_RECORD(sgiLoad, workArea->sgiWa.paddingBuff);
    MCUX_CSSL_DI_RECORD(sgiLoad, 16U);
    /* Generate subkeys */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_CmacGenerateSubKeys(session,workArea, MCUXCLMACMODES_AES_CMAC_K1_AND_K2));

    if(MCUXCLAES_BLOCK_SIZE < noOfBytesToProcess)
    {
       /* Enable XOR-on-write to XOR the saved previous output with the last input block */
       MCUX_CSSL_FP_FUNCTION_CALL(retXorWrite, mcuxClSgi_Drv_enableXorWrite());
       (void)retXorWrite;
    }

    /* DATIN0 now contains m_n xor enc(m_n-1). DATOUT contains the subkey.
    * mcuxClMacModes_finalizeEngine uses INSEL_DATIN0_XOR_DATOUT to complete
    * the final input computation.
    */

    uint32_t pOutLen = 0U;
    uint32_t remainingBytes = (uint32_t)(noOfBytesToProcess & (MCUXCLAES_BLOCK_SIZE - 1U));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->addPadding(session,
                                                     MCUXCLAES_BLOCK_SIZE,
                                                     pIn,
                                                     inputOffset,
                                                     remainingBytes,
                                                     inLength,
                                                     (uint8_t *)workArea->sgiWa.paddingBuff,
                                                     &pOutLen));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, workArea->sgiWa.paddingBuff));
  }

  /* disable XOR for input length greater than the block */
  if(MCUXCLAES_BLOCK_SIZE < noOfBytesToProcess)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_disableXorWrite());
  }

  /* DATIN0 now contains m_n xor enc(m_n-1). DATOUT contains the subkey.
  * mcuxClMacModes_finalizeEngine uses INSEL_DATIN0_XOR_DATOUT to complete
  * the final input computation.
  */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("this null pointer is unused in this function ")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_engine(
      session,
      workArea,
      NULL,
      NULL,
      0,
      0,
      sfrSeed,
      operation,
      mcuxClMacModes_finalizeEngine,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_finalizeEngine)));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  MCUX_CSSL_FP_COUNTER_STMT(MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_computeCMAC_balancingFP(noOfBytesToProcess, inLengthInBlocks, pAlgo)));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_computeCMAC, MCUXCLMAC_STATUS_OK,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_computeCMAC_balancingFP));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_updateCMAC, mcuxClMacModes_UpdateFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_updateCMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes UNUSED_PARAM
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_updateCMAC);

  /* The `inputLen` variable is only used for FP balancing. To suppress compiler issues where FP is
  *  disabled it is used in the `inLengthFullBlocks` compuation instead of `inLength`. */
  uint32_t inputLen = inLength;

  /* Determine input size (including data accumulated in context). */
  uint32_t blockBufferUsed = pContext->blockBufferUsed;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(inputLen, 0U, UINT32_MAX - blockBufferUsed, MCUXCLMAC_STATUS_INVALID_PARAM)
  uint32_t inLengthFullBlocks = (inputLen + blockBufferUsed) / MCUXCLAES_BLOCK_SIZE;
  uint32_t inLengthRemainder = (inputLen + blockBufferUsed) & (MCUXCLAES_BLOCK_SIZE - 1U);

  if (0U < inLength)
  {
    if(pContext->totalInput > (UINT32_MAX - inLength))
    {
      MCUXCLSESSION_ERROR(session, MCUXCLMAC_STATUS_INVALID_PARAM);
    }
    pContext->totalInput += inLength;

    uint32_t inputOffset = 0U;
    /*
     * The last block has to be XORed with subkey.
     * Thus do not process a full last block but put it to accumulation buffer to be processed in finalize step.
     */
    if (0U == inLengthRemainder)
    {
      inLengthFullBlocks = (inLengthFullBlocks - 1U);
      inLengthRemainder = MCUXCLAES_BLOCK_SIZE;
      if ((0U < inLengthFullBlocks) && (MCUXCLAES_BLOCK_SIZE <= inLength))
      {
        inLength -= MCUXCLAES_BLOCK_SIZE;
      }
    }
    /* Prepare operation parameters */
    uint32_t operation = MCUXCLSGI_DRV_CTRL_END_UP                  |
                         MCUXCLSGI_DRV_CTRL_INSEL_DATIN0            |
                         MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
                         MCUXCLSGI_DRV_CTRL_ENC                     |
                         pContext->keyContext.sgiCtrlKey;

    if (0U < inLengthFullBlocks)
    {
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_process_preTag_calculation(
        session,
        workArea,
        pContext,
        pIn,
        inLength,
        operation));

      inputOffset += inLength;
    }

    /* Save the last full block to context buffer */
    if ((MCUXCLAES_BLOCK_SIZE == inLengthRemainder) || (0U == inLengthFullBlocks))
    {
      MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(pContext->blockBufferUsed, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLMAC_STATUS_INVALID_PARAM)
      MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(inLengthRemainder - pContext->blockBufferUsed, 0U, MCUXCLAES_BLOCK_SIZE, MCUXCLMAC_STATUS_INVALID_PARAM)
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, pIn);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, inputOffset);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, &((uint8_t *)pContext->blockBuffer)[pContext->blockBufferUsed]);
      MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, inLengthRemainder - pContext->blockBufferUsed);
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_secure(
        pIn,
        inputOffset,
        &((uint8_t *)pContext->blockBuffer)[pContext->blockBufferUsed],
        inLengthRemainder - pContext->blockBufferUsed));

      pContext->blockBufferUsed = inLengthRemainder;
    }
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_updateCMAC, MCUXCLMAC_STATUS_OK,
    MCUX_CSSL_FP_CONDITIONAL(
      ((0U < inputLen) && (0U < inLengthFullBlocks)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_process_preTag_calculation)
    ),
    MCUX_CSSL_FP_CONDITIONAL(
      ((0U < inputLen) && ((MCUXCLAES_BLOCK_SIZE == inLengthRemainder) || (0U == inLengthFullBlocks))),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_secure)
    )
  );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_finalizeCMAC, mcuxClMacModes_FinalizeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_finalizeCMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * workArea,
  mcuxClMacModes_Context_t * const pContext)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_finalizeCMAC);
  MCUX_CSSL_DI_RECORD(sgiLoad, (uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET) + MCUXCLAES_BLOCK_SIZE);
  mcuxClMacModes_Algorithm_t pAlgo = (mcuxClMacModes_Algorithm_t) pContext->common.pMode->common.pAlgorithm;

  /*
   * Handle last block.
   * 1) Store pretag from context in DATIN0.
   * 2) Using DATIN1, compute subkey k1 or k2, depending on whether block is full, and store in DATOUT.
   * 3) Xor (potentially padded) last input block onto DATIN0 using SGI XorWrite.
   * 4) Start SGI operation, xoring subkey from DATOUT onto DATIN0 using INSEL_DATIN0_XOR_DATOUT.
   */
  /* Load (masked) preTag to DATOUT */
  uint32_t *pDst_sgiDatin0 = (uint32_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATIN0_OFFSET);
  const uint32_t *pSrc_maskedPreTag = (const uint32_t *)pContext->maskedPreTag;
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, pDst_sgiDatin0);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, (uint32_t)pSrc_maskedPreTag);
  MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copyBlockSfrMasked, MCUXCLAES_BLOCK_SIZE);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copyBlockSfrMasked(
    pDst_sgiDatin0,
    pSrc_maskedPreTag,
    pContext->keyContext.sfrSeed));

  if(MCUXCLAES_BLOCK_SIZE == pContext->blockBufferUsed)
  {
    MCUX_CSSL_DI_RECORD(sgiLoad, pContext->blockBuffer);

    /* Generate subkey */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_CmacGenerateSubKeys(session, workArea, MCUXCLMACMODES_AES_CMAC_K1_ONLY));

    /* Enable XOR-on-write to XOR the saved previous output with the last input block */
    MCUX_CSSL_FP_FUNCTION_CALL(retXorWrite, mcuxClSgi_Drv_enableXorWrite());
    (void)retXorWrite;

    /* Copy input to SGI */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT("The object backend implementation might fail, the pointer backend implementation does not.")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, (uint8_t *)pContext->blockBuffer));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT()
  }
  else /* Add padding before loading data to SGI. */
  {

    MCUXCLBUFFER_INIT_RO(paddingInBuffer, NULL, (uint8_t *)pContext->blockBuffer, pContext->blockBufferUsed);

    /* Record load input */
    MCUX_CSSL_DI_RECORD(sgiLoad, workArea->sgiWa.paddingBuff);

    uint32_t pOutLen = 0U;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->addPadding(session,
                                                     MCUXCLAES_BLOCK_SIZE,
                                                     paddingInBuffer,
                                                     0,
                                                     pContext->blockBufferUsed,
                                                     pContext->blockBufferUsed,
                                                     (uint8_t *)workArea->sgiWa.paddingBuff,
                                                     &pOutLen));
    /* Generate subkeys */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_CmacGenerateSubKeys(session, workArea, MCUXCLMACMODES_AES_CMAC_K1_AND_K2));

    /* Enable XOR-on-write to XOR the saved previous output with the last input block */
    MCUX_CSSL_FP_FUNCTION_CALL(retXorWrite, mcuxClSgi_Drv_enableXorWrite());
    (void)retXorWrite;

    /* Copy input to SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, workArea->sgiWa.paddingBuff));
  }

  /* Perform encryption of the last block */
  uint32_t operation =  MCUXCLSGI_DRV_CTRL_ENC                     |
                        MCUXCLSGI_DRV_CTRL_END_UP                  |
                        MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT |
                        MCUXCLSGI_DRV_CTRL_OUTSEL_RES              |
                        pContext->keyContext.sgiCtrlKey;


  /* Perform encryption of the last block */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_disableXorWrite());
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("this null pointer is unused in this function ")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_engine(
    session,
    workArea,
    pContext,
    NULL,
    0,
    0,
    pContext->keyContext.sfrSeed,
    operation,
    mcuxClMacModes_finalizeEngine,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_finalizeEngine)));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_finalizeCMAC,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copyBlockSfrMasked),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLAES_BLOCK_SIZE == pContext->blockBufferUsed),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CmacGenerateSubKeys),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLAES_BLOCK_SIZE != pContext->blockBufferUsed),
      pAlgo->protectionToken_addPadding,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CmacGenerateSubKeys),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_disableXorWrite),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_engine)
  );
}

