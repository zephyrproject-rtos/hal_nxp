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

/** @file  mcuxClAeadModes_Sgi_Cleanup.c
 *  @brief implementation of the cleanup functions of the mcuxClAeadModes component */


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClAead_Constants.h>
#include <mcuxClAes.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <mcuxClSession.h>
#include <mcuxCsslDataIntegrity.h>

#include <internal/mcuxClAeadModes_Common.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClAeadModes_Common_Functions.h>
#include <internal/mcuxClAeadModes_Sgi_Cleanup.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClSgi_Utils.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClKey_Functions_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_cleanupOnMultipartExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void)
mcuxClAeadModes_cleanupOnMultipartExit(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *pContext,
  uint32_t cpuWaSizeInWords)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_cleanupOnMultipartExit);

  /* Note on SREQI_AEAD_8 for abnormal errors:
     It is not necessary to zero counter0 in contexts in case of abnormal errors,
     as the init phases of all current AEADs (GCM/CCM) properly clear/overwrite counter0 using DI-protected memory functions. */

  /* Clear the key in the context */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushKeyInSgi(session, &(pContext->cipherCtx.keyContext)));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushSubKeyInSgi(session, &(pContext->macCtx.HkeyContext)));

  /* Uninitialize (and release) the SGI hardware */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_Uninit(session));

  /* Free CPU WA in Session */
  mcuxClSession_freeWords_cpuWa(session, cpuWaSizeInWords);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_cleanupOnMultipartExit,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushSubKeyInSgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushKeyInSgi),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_Uninit)
  );

}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_cleanupOnOneshotExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void)
mcuxClAeadModes_cleanupOnOneshotExit(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint32_t cpuWaSizeInWords)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_cleanupOnOneshotExit);

  /* Note on SREQI_AEAD_8 for abnormal errors:
     It is not necessary to zero counter0 in contexts in case of abnormal errors,
     as the init phases of all current AEADs (GCM/CCM) properly clear/overwrite counter0 using DI-protected memory functions. */

  /* Flush the given key, if needed */
  const uint16_t keyLoadStatus = mcuxClKey_getLoadStatus(key);
  MCUX_CSSL_FP_COUNTER_STMT(const volatile uint16_t keyLoadStatusRef = keyLoadStatus);
  if(MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (keyLoadStatus & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))
  {
    /* Flush the key in use if it is not preloaded.
    * Note that we purposefully don't flush the whole SGI or the whole Key bank to not overwrite other keys. */
    MCUXCLKEY_FLUSH_FP(session, key, 0U /* spec */);
  }


  /* Uninitialize (and release) the SGI hardware */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_Uninit(session));

  /* Free CPU WA in Session */
  mcuxClSession_freeWords_cpuWa(session, cpuWaSizeInWords);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAeadModes_cleanupOnOneshotExit,
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (keyLoadStatusRef & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED)),
      MCUXCLKEY_FLUSH_FP_CALLED(key)
    ),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_Uninit)
  );

}
