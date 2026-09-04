/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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

#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClToolchain.h>

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClMemory.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Aes_Iv.h>
#include <internal/mcuxClCipherModes_Sgi_Cleanup.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Sfr_Ctrl.h>
#include <internal/mcuxClSgi_Utils.h>


#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Utils.h>
#include <internal/mcuxClDma_Drv.h>
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_No_IV, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_No_IV(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_No_IV);

  pWa->pIV = NULL;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_No_IV);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_IV, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_IV);

  MCUX_CSSL_DI_RECORD(sgiLoadBuffer, ((uint32_t)pIv) + (uint32_t)(MCUXCLSGI_DRV_DATIN1_OFFSET) + 16U);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(MCUXCLSGI_DRV_DATIN1_OFFSET, pIv));  /* load the IV in DATIN1 */

  /* Store the needed register of the IV s.t. intermediate IVs can be re-loaded after crypt operations */
  pWa->pIV = mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATIN1_OFFSET);
  pWa->ctrSize = MCUXCLAES_BLOCK_SIZE;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_IV,
                                 MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock));
}

#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_IV_AutoMode_Cbc_Dec, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV_AutoMode_Cbc_Dec(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_IV_AutoMode_Cbc_Dec);

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  /* Copy IV to SGI DATIN2 with DMA, as needed by SGI AUTO mode.
     Note that this is not according to SGI spec. In spec it states to first enable
     SGI AUTO mode with cmd=CBC and direction=decrypt before loading IV to DATIN0.
     As we know SGI AUTO mode propagates the IV internally to DATIN2 (from DATIN0),
     we just write it to DATIN2 directly.
     This mitigates some issues when disabling SGI AUTO mode for the single-block case,
     where the IV in DATIN0 is overwritten once AUTO mode is disabled. In DATIN2 the IV
     is kept, hence it allows us for a more consistent SW behaviour for multi-block and
     single-block handling.
  */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputChannel(session, MCUXCLSGI_DRV_DATIN2_OFFSET, MCUXCLBUFFER_GET(pIv)));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(inputChannel));

  /* Store the needed register of the IV s.t. intermediate IVs can be re-loaded after crypt operations */
  pWa->pIV = mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATIN2_OFFSET);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_IV_AutoMode_Cbc_Dec,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputChannel),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_IV_to_DATOUT_DMA, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV_to_DATOUT_DMA(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_IV_to_DATOUT_DMA);

  /* Copy IV to SGI DATOUT with DMA */
  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputChannel(session, MCUXCLSGI_DRV_DATOUT_OFFSET, MCUXCLBUFFER_GET(pIv)));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(inputChannel));

  /* Store the needed register of the IV s.t. intermediate IVs can be re-loaded after crypt operations */
  pWa->pIV = mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_IV_to_DATOUT_DMA,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputChannel),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_IV_AutoMode_Ctr, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV_AutoMode_Ctr(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_IV_AutoMode_Ctr);

  mcuxClSession_Channel_t inputChannel = mcuxClSession_getDmaInputChannel(session);

  /* Known limitation: Configure and start the SGI to AUTO mode CTR *before* loading the IV to DATIN0 */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureAutoMode(MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CTR_128));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(pWa->sgiWa.sgiCtrlKey | MCUXCLSGI_DRV_CTRL_NO_UP));

  /* Copy IV to SGI DATIN0 with DMA */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_configureSgiInputChannel(session, MCUXCLSGI_DRV_DATIN0_OFFSET, MCUXCLBUFFER_GET(pIv)));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Utils_startTransferOneBlock(inputChannel));

  /* Use DATA register that is used to store the current IV. */
  pWa->pIV = mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATIN2_OFFSET);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_Drv_waitForChannelDone(session, inputChannel));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_IV_AutoMode_Ctr,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureAutoMode),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_configureSgiInputChannel),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Utils_startTransferOneBlock),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_Drv_waitForChannelDone));
}
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_checkIvLen_noIv, mcuxClCipherModes_CheckIvLength_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_checkIvLen_noIv(
  mcuxClSession_Handle_t session,
  uint32_t ivLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_checkIvLen_noIv);

  if(0U == ivLength)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_checkIvLen_noIv);
  }

  MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_checkIvLen, mcuxClCipherModes_CheckIvLength_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_checkIvLen(
  mcuxClSession_Handle_t session,
  uint32_t ivLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_checkIvLen);

  if(MCUXCLAES_BLOCK_SIZE == ivLength)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_checkIvLen);
  }

  MCUXCLSESSION_ERROR(session, MCUXCLCIPHER_STATUS_INVALID_INPUT);
}
