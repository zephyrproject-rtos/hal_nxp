/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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
#include <mcuxCsslAnalysis.h>

#include <mcuxClCore_Macros.h>
#include <mcuxClMac.h>
#include <mcuxClMacModes_MemoryConsumption.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Sgi_Cmac.h>
#include <internal/mcuxClMacModes_Sgi_Algorithms.h>

#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClAes.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Utils.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClDma_Resource.h>
#include <mcuxClBuffer.h>



/* Shared CMAC DMA-driven helper */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_handleLastBlock_cmac_oneshot, mcuxClMacModes_handleLastBlock_oneshot_t)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_handleLastBlock_cmac_oneshot(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * pWa,
  mcuxClMacModes_Algorithm_t pAlgo,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t totalInputLength,
  uint32_t remainingBytes
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_handleLastBlock_cmac_oneshot);

  MCUX_CSSL_DI_RECORD(outputCopy, (uint32_t)MCUXCLSGI_DRV_DATIN0_OFFSET + (uint32_t)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET) + (uint32_t)MCUXCLAES_BLOCK_SIZE);

  /* Apply padding to the last block if needed, while SGI is busy */
  uint32_t padOutLen = 0U;

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pAlgo->addPadding(
    session,
    MCUXCLAES_BLOCK_SIZE,
    pIn,
    inOffset,
    remainingBytes,
    totalInputLength,
    pWa->sgiWa.paddingBuff,
    &padOutLen));

  /* AUTO mode limitation: SGI will only de-assert the busy flag once the (CBC-)MAC output is read.
     Access the DATOUT once to trigger SGI finish. Otherwise, SGI will be stuck and the last block
     cannot be handled. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 4U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 8U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 12U));

  /* Known bug in SGI AUTO mode: if AUTO_MODE.CMD is not reset to 0 here, subsequent SGI operations will not work.
     Workaround: wait for SGI and reset AUTO_MODE to 0. To be removed in CLNS-7392 once fixed in HW. */
  mcuxClSgi_Drv_wait(); /* Known limitation: wait for SGI busy flag to be de-asserted before overwriting AUTO mode CMD */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_resetAutoMode());

  /* Copy result to DATIN0, to save it while subkeys are generated. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, (uint8_t*)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET)));
  /* Load the last block to DATIN0 */
  if(MCUXCLAES_BLOCK_SIZE == padOutLen)
  {
    /* Generate subkeys, Use subKey2 because padding was added */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_CmacGenerateSubKeys(session, pWa, MCUXCLMACMODES_AES_CMAC_K1_AND_K2));

    /* Enable XOR-on-write to XOR the saved previous output with the last input block. */
    MCUX_CSSL_FP_FUNCTION_CALL(retXorWrite, mcuxClSgi_Drv_enableXorWrite());
    (void)retXorWrite;

    /* Padding was added - Copy padded input to SGI */
    MCUX_CSSL_DI_RECORD(sgiLoad, ((uint32_t)(MCUXCLSGI_DRV_DATIN0_OFFSET)) + ((uint32_t)pWa->sgiWa.paddingBuff) + 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN0_OFFSET, pWa->sgiWa.paddingBuff));
  }
  else
  {
     /* Generate subkey */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMacModes_CmacGenerateSubKeys(session, pWa, MCUXCLMACMODES_AES_CMAC_K1_ONLY));

    /* Enable XOR-on-write to XOR the saved previous output with the last input block. */
    MCUX_CSSL_FP_FUNCTION_CALL(retXorWrite, mcuxClSgi_Drv_enableXorWrite());
    (void)retXorWrite;

    mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
    MCUXCLBUFFER_DERIVE_RO(pInWithOffset, pIn, inOffset);

    /* No padding needed - Copy last input block to SGI */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputChannel(session, MCUXCLSGI_DRV_DATIN0_OFFSET, MCUXCLBUFFER_GET(pInWithOffset)));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(inputChannel));

    /* Wait for data copy to finish and check for errors */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));
  }

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_disableXorWrite());

  /* DATIN0 now contains m_n xor enc(m_n-1). DATOUT contains the subkey.
   * Use INSEL_DATIN0_XOR_DATOUT to complete the final input computation.
   */

  /* Perform encryption of the last block */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
    pWa->sgiWa.sgiCtrlKey                     |
    MCUXCLSGI_DRV_CTRL_ENC                     |
    MCUXCLSGI_DRV_CTRL_END_UP                  |
    MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT | /* IV stored in DATOUT, IV ^ lastblock ^ subkey */
    MCUXCLSGI_DRV_CTRL_OUTSEL_RES));
  mcuxClSgi_Drv_wait();

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_handleLastBlock_cmac_oneshot,
          pAlgo->protectionToken_addPadding,
          4U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_storeWord),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_resetAutoMode),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock),
          MCUX_CSSL_FP_CONDITIONAL( (MCUXCLAES_BLOCK_SIZE == padOutLen),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CmacGenerateSubKeys),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock)),
          MCUX_CSSL_FP_CONDITIONAL( (MCUXCLAES_BLOCK_SIZE != padOutLen),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMacModes_CmacGenerateSubKeys),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputChannel),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone)),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_disableXorWrite),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
  );
}
