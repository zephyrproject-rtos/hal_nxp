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

#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClAes.h>

#include <mcuxClCipherModes_MemoryConsumption.h>

#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClCipherModes_Sgi_Cleanup.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
#include <internal/mcuxClDma_Resource.h>
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

#include <internal/mcuxClCrc_Internal_Functions.h>


/**
 * @brief Function to handle normal exit
 *
 * Use this function to leave functions in this file in normal exit cases.
 * It frees CPU workarea and uninitializes the SGI.
 *
 * @param      session          Handle for the current CL session.
 * @param      pContext         Pointer to multipart context
 * @param      key              Handle for the key.
 *                              If the key is in the context, this param shall be NULL.
 * @param[in]  cpuWaSizeInWords Number of cpu wa words to free
 */
 MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_cleanupOnExit)
 MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_cleanupOnExit(
   mcuxClSession_Handle_t session,
   mcuxClCipherModes_Context_Aes_Sgi_t *pContext,
   mcuxClKey_Handle_t key,
   uint32_t cpuWaSizeInWords
 )
 {
   MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_cleanupOnExit);

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
     /* Flush the key in the context, if needed */
     MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushKeyInSgi(session, &(pContext->keyContext)));
   }
   else
   {
     /* intentionally empty */
   }


   /* Uninitialize (and release) the SGI hardware */
   MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_Uninit(session));

   MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_cleanupOnExit,
     MCUX_CSSL_FP_CONDITIONAL(((NULL != key)
         && (MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (mcuxClKey_getLoadStatus(key) & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))),
       MCUXCLKEY_FLUSH_FP_CALLED_CHECK_NULL(key)
     ), /* NULL != key */
     MCUX_CSSL_FP_CONDITIONAL(((NULL == key)
         && (NULL != pContext)),
       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushKeyInSgi)
     ), /* NULL != pContext */
     MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_Uninit)
   );
}

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_cleanupOnExit_dmaDriven)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_cleanupOnExit_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_Context_Aes_Sgi_t *pContext,
  mcuxClKey_Handle_t key,
  uint32_t cpuWaSizeInWords,
  uint32_t cleanupDmaSgi)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_cleanupOnExit_dmaDriven);

  /* Free CPU WA in Session */
  mcuxClSession_freeWords_cpuWa(session, cpuWaSizeInWords);

  if(0U != (cleanupDmaSgi & MCUXCLCIPHERMODES_CLEANUP_HW_DMA))
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_releaseInputAndOutput(session));
  }

#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
  /* The SGI AUTO-mode might still be running if no input was processed so far
   * (can be the case, e.g., for CTR-NonBlocking mode, as it is started during the
   * pAlgo->setupIV step for this mode). We need to stop AUTO-mode here to bring the
   * SGI in non-busy state because the KEY_FLUSH (PRNG) uses the SGI.
   * If AUTO-mode is not running anymore, stopping it will do no harm. */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopAndDisableAutoMode());
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */

  MCUX_CSSL_FP_COUNTER_STMT(uint32_t flush_FP_tag = 0U);

  if(0U != (cleanupDmaSgi & MCUXCLCIPHERMODES_CLEANUP_HW_SGI))
  {
    /* Flush the given key, if needed */
    if((NULL != key)
        && (MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (mcuxClKey_getLoadStatus(key) & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))
      )
    {
      /* Flush the key in use if it is not preloaded.
      * Note that we purposefully don't flush the whole SGI or the whole Key bank to not overwrite other keys. */
      MCUX_CSSL_FP_COUNTER_STMT(flush_FP_tag = MCUXCLKEY_FLUSH_FP_CALLED(key));
      MCUXCLKEY_FLUSH_FP(session, key, 0U /* spec */);
    }
    else if(NULL != pContext)
    {
      /* Flush the key in the context, if needed */
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_flushKeyInSgi(session, &(pContext->keyContext)));
    }
    else
    {
      /* intentionally empty */
    }


    /* Uninitialize (and release) the SGI hardware */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_Uninit(session));
  }

  if (NULL != pContext)
  {
    /* Update context CRC */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(&pContext->common, MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_cleanupOnExit_dmaDriven,
                                MCUX_CSSL_FP_CONDITIONAL( (0U != (cleanupDmaSgi & MCUXCLCIPHERMODES_CLEANUP_HW_DMA)),
                                                       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_releaseInputAndOutput)),
#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopAndDisableAutoMode),
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */
                                MCUX_CSSL_FP_CONDITIONAL( (NULL != pContext),
                                                       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc)),
                                MCUX_CSSL_FP_CONDITIONAL( (0U != (cleanupDmaSgi & MCUXCLCIPHERMODES_CLEANUP_HW_SGI)),
                                                       MCUX_CSSL_FP_CONDITIONAL(((NULL != key)
                               && (MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED != (mcuxClKey_getLoadStatus(key) & MCUXCLKEY_LOADSTATUS_OPTIONS_KEEPLOADED))),
                                                       flush_FP_tag),
                                                       MCUX_CSSL_FP_CONDITIONAL((NULL != pContext),
                                                                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_flushKeyInSgi)),
                                                       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_Uninit))
                                );
}
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */
