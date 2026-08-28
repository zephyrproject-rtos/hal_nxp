/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClMac.h>
#include <internal/mcuxClMacModes_Common_Constants.h>
#include <internal/mcuxClMacModes_Sgi_Functions.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <internal/mcuxClMacModes_Sgi_Cleanup.h>

#include <mcuxClAes.h>
#include <internal/mcuxClSgi_Drv.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Drv.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Utils.h>
#include <internal/mcuxClDma_Resource.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClKey_Functions_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_cleanupOnExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_cleanupOnExit(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_Context_t *pContext,
  mcuxClKey_Handle_t key,
  uint32_t cpuWaSizeInWords)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_cleanupOnExit);

  /* Note for SREQI_MAC_17:
   * It is not necessary to explicitly clear the GMAC counter0/J0 in contexts and workareas
   * in case of abnormal errors, as the GMAC init phases for multipart and oneshot properly
   * clear/overwrite the counter0/J0 using DI-protected memory functions. */

  /* Free CPU WA in Session */
  mcuxClSession_freeWords_cpuWa(session, cpuWaSizeInWords);

  /* Flush the given key, if status is not KEEPLOADED */
  if(NULL != key)
  {
    if(MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (mcuxClKey_getLoadStatus(key) & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))
    {
      /* Flush the key in use if it is not preloaded.
       * Note that we purposefully don't flush the whole SGI or the whole Key bank to not overwrite other keys. */
      MCUXCLKEY_FLUSH_FP(session, key, 0U /* spec */);
    }
  }
  else if(NULL != pContext)
  {
    /* Flush the key(s) in the context, if needed */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushKeyInSgi(session, &(pContext->keyContext)));
    /* For GMAC, flush H-key in context. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushSubKeyInSgi(session, &(pContext->HkeyContext)));
  }
  else
  {
    /* intentionally empty */
  }


  /* Uninitialize (and release) the SGI hardware */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_Uninit(session));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_cleanupOnExit,
    MCUX_CSSL_FP_CONDITIONAL(((NULL != key)
        && (MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (mcuxClKey_getLoadStatus(key) & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))),
      MCUXCLKEY_FLUSH_FP_CALLED_CHECK_NULL(key)
    ), /* NULL != key */
    MCUX_CSSL_FP_CONDITIONAL(((NULL == key) && (NULL != pContext)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushSubKeyInSgi),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushKeyInSgi)
    ), /* NULL != pContext */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_Uninit)
  );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_cleanupOnExit_dmaDriven)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_cleanupOnExit_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_Context_t *pContext,
  mcuxClKey_Handle_t key,
  uint32_t cpuWaSizeInWords)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_cleanupOnExit_dmaDriven);

  /* Free CPU WA in Session */
  mcuxClSession_freeWords_cpuWa(session, cpuWaSizeInWords);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_release(session, mcuxClSession_getDmaInputChannel(session)));

  /* Flush the given key, if needed */
  if((NULL != key)
      && (MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (mcuxClKey_getLoadStatus(key) & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))
    )
  {
    uint32_t numKeyWords = mcuxClKey_getSize(key) / sizeof(uint32_t);
    uint32_t keySlot = mcuxClKey_getLoadedKeySlot(key);
    /* Record input data for mcuxClSgi_Drv_flushRegisterBanks() */
    MCUX_CSSL_DI_RECORD(sgiFlush,mcuxClSgi_Drv_keySlotToOffset(keySlot));
    MCUX_CSSL_DI_RECORD(sgiFlush,mcuxClKey_getSize(key));
    /* Flush the key in use if it is not preloaded.
      * Note that we purposefully don't flush the whole SGI or the whole Key bank to not overwrite other keys. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_flushRegisterBanks(mcuxClSgi_Drv_keySlotToOffset(keySlot), numKeyWords));

    /* Restore the initial state of the key object */
    mcuxClKey_setLoadStatus(key, MCUXCLKEY_LOADSTATUS_NOTLOADED);
    mcuxClKey_setLoadedKeySlot(key, MCUXCLKEY_LOADOPTION_SLOT_INVALID);
  }
  else if(NULL != pContext)
  {
    /* Flush the key(s) in the context, if needed */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushKeyInSgi(session, &(pContext->keyContext)));
    /* for GMAC, flush H-key in context */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushSubKeyInSgi(session, &(pContext->HkeyContext)));
  }
  else
  {
    /* intentionally empty */
  }


  /* Uninitialize (and release) the SGI hardware */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_Uninit(session));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMacModes_cleanupOnExit_dmaDriven,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_release),
            MCUX_CSSL_FP_CONDITIONAL( ((NULL != key) &&
                         (MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (mcuxClKey_getLoadStatus(key) & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_flushRegisterBanks)),
            MCUX_CSSL_FP_CONDITIONAL( (NULL != pContext),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushSubKeyInSgi),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushKeyInSgi)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_Uninit)
            );
}

