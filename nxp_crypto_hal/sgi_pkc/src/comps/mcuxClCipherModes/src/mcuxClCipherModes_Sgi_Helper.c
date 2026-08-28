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
#include <internal/mcuxClSgi_Sfr_Ctrl.h>

#include <internal/mcuxClCipher_Internal.h>
#include <mcuxClAes.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Cleanup.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <mcuxClMemory.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
#include <internal/mcuxClDma_Resource.h>
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */
#include <internal/mcuxClAes_Internal_Functions.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_copyOut_toPtr, mcuxClSgi_copyOut_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_copyOut_toPtr(
  void* pWa,
  mcuxCl_Buffer_t outBuf,
  uint32_t offset,
  uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_copyOut_toPtr);
  mcuxClCipherModes_WorkArea_t* pWaCipher = mcuxClCipherModes_castToCipherModesWorkArea(pWa);

  if(MCUXCLAES_BLOCK_SIZE != byteLength)
  {
    /* If length is not full block size, copy from SGI into a temporary buffer to avoid byte-wise access to SGI. */
    uint8_t* outData = pWaCipher->sgiWa.paddingBuff;
    MCUX_CSSL_DI_RECORD(store128BitBlockDI /* Not used */, (uint32_t)outData + MCUXCLAES_BLOCK_SIZE);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, outData));
    MCUX_CSSL_DI_RECORD(bufferWriteDI, (uint32_t)outData);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(outBuf, offset, outData, byteLength));
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET, outBuf + offset));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_copyOut_toPtr,
                                MCUX_CSSL_FP_CONDITIONAL(MCUXCLAES_BLOCK_SIZE != byteLength,
                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write) ),
                                MCUX_CSSL_FP_CONDITIONAL(MCUXCLAES_BLOCK_SIZE == byteLength,
                                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock) )
                                );
}




MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_loadKeyAndIvtoSgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_loadKeyAndIvtoSgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx,
  mcuxClCipherModes_WorkArea_t * pWa,
  uint32_t inLength,
  mcuxClKey_KeyChecksum_t** pKeyChecksum
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_loadKeyAndIvtoSgi);

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("pCtx->common.blockBufferUsed can't be larger than MCUXCLAES_BLOCK_SIZE")
  if((MCUXCLAES_BLOCK_SIZE - pCtx->common.blockBufferUsed) <= inLength)
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_loadKeyFromCtx_Sgi(session, &(pCtx->keyContext), &pWa->sgiWa));
    if(pKeyChecksum != NULL)
    {
      *pKeyChecksum = &pCtx->keyContext.keyChecksums;
    }
    MCUXCLBUFFER_INIT_RO(ivBuff, session, pCtx->ivState, MCUXCLAES_BLOCK_SIZE_IN_WORDS);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pCtx->setupIV(session, pWa, ivBuff));
  }
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_loadKeyAndIvtoSgi,
    MCUX_CSSL_FP_CONDITIONAL(((MCUXCLAES_BLOCK_SIZE - pCtx->common.blockBufferUsed) <= inLength),
                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_loadKeyFromCtx_Sgi),
                        pCtx->protectionToken_setupIV));
}

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClSession_HwInterruptHandler_t callbackFunction,
  uint32_t protectionToken_callbackFunction
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_request(
    session,
    mcuxClSession_getDmaOutputChannel(session),
    callbackFunction,
    protectionToken_callbackFunction
  ));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_request(
    session,
    mcuxClSession_getDmaInputChannel(session),
    callbackFunction,
    protectionToken_callbackFunction
  ));

  mcuxClSession_job_setClWorkarea(session, (void*) pWa);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext,
    2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_request)
  );
}
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

