/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

/** @file  mcuxClKey_Encoding.c
 *  @brief Implementation of the Key encoding functions that are supported
 *  by component. */

#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClKey.h>
#include <mcuxClMemory.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClKey_FeatureConfig.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_CopySecure_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClAes_KeyEncodingMechanisms_Sgi.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_KeyLoad_Plain, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_KeyLoad_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint8_t **ppDest,
  mcuxClKey_KeyChecksum_t * pKeyChecksums,
  mcuxClKey_Encoding_Spec_t spec)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_KeyLoad_Plain);

  /* If spec specifies to set the key pointer to ppDest */
  if ((MCUXCLKEY_ENCODING_SPEC_ACTION_PTR == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK)))
  {
    *ppDest = mcuxClKey_getKeyData(key);
  }
  else if (MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
    /* Record input data for mcuxClMemory_copy_secure_int() */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int, *ppDest);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int, mcuxClKey_getKeyData(key));
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int, mcuxClKey_getSize(key));
    MCUXCLMEMORY_COPY_SECURE_INT((uint8_t*)(*ppDest), mcuxClKey_getKeyData(key), mcuxClKey_getSize(key));
  }
  else if (MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL== (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
    /* Record input data for mcuxClMemory_copy_int() */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, *ppDest);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, mcuxClKey_getKeyData(key));
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, mcuxClKey_getSize(key));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClMemory_copy_int((uint8_t*)(*ppDest), mcuxClKey_getKeyData(key), mcuxClKey_getSize(key))
    );
  }
  else
  {
    /* spec is not valid */
    MCUXCLSESSION_FAULT(session, MCUXCLKEY_STATUS_FAULT_ATTACK);
  }
  if(pKeyChecksums != NULL)
  {
    pKeyChecksums->VerifyFunc = key->encoding->handleKeyChecksumsFunc;
    pKeyChecksums->protectionToken_VerifyFunc = key->encoding->protectionToken_handleKeyChecksumsFunc;
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_KeyLoad_Plain,
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK)),
      MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT
    ),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)
    )
  );
}

#ifdef MCUXCLKEY_FEATURE_INTERNAL_STOREPLAIN_FUNC
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_KeyStore_Plain, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_KeyStore_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t *pSrc,
  mcuxClKey_Encoding_Spec_t spec)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_KeyStore_Plain);

  /* If spec specifies to set the key pointer to pSrc */
  if (MCUXCLKEY_ENCODING_SPEC_ACTION_PTR == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("pKeyData can not made const inside of key component as it is possible that the data changes after init due to generation/agreement/derivation of keys.");
    mcuxClKey_setKeyData(key, (uint8_t *) pSrc);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  }
  else if (MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
    uint8_t *pData = mcuxClKey_getKeyData(key);
    if(pData == pSrc)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_KeyStore_Plain);
    }
    /* Record input data for mcuxClMemory_copy_secure_int() */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int, pSrc);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int, mcuxClKey_getKeyData(key));
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int, mcuxClKey_getSize(key));
    MCUXCLMEMORY_COPY_SECURE_INT(pData, pSrc, mcuxClKey_getSize(key));
  }
  else if (MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL== (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
    uint8_t *pData = mcuxClKey_getKeyData(key);
    if(pData == pSrc)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_KeyStore_Plain);
    }
    /* Record input data for mcuxClMemory_copy_int() */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, pSrc);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, mcuxClKey_getKeyData(key));
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int, mcuxClKey_getSize(key));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pData, pSrc, mcuxClKey_getSize(key)));
  }
  else
  {
    /* spec is not valid */
    MCUXCLSESSION_FAULT(session, MCUXCLKEY_STATUS_FAULT_ATTACK);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_KeyStore_Plain,
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK)),
      MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT
    ),
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)
    )
  );
}
#endif /* MCUXCLKEY_FEATURE_INTERNAL_STOREPLAIN_FUNC */

#ifdef MCUXCLKEY_FEATURE_INTERNAL_FLUSH_FUNC
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_KeyFlush_Plain, mcuxClKey_FlushFuncPtr_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_KeyFlush_Plain(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClKey_Encoding_Spec_t spec)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_KeyFlush_Plain);

  /* Flush the key from the loaded-to copro, based on the key type */
  if(MCUXCLKEY_ALGO_ID_AES == (mcuxClKey_getAlgoId(key) & MCUXCLKEY_ALGO_ID_ALGO_MASK))
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_keyFlush(session, key, spec));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_KeyFlush_Plain,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_keyFlush));
  }
  else
  {
    /* spec is not valid/supported yet */
    MCUXCLSESSION_FAULT(session, MCUXCLKEY_STATUS_FAULT_ATTACK);
  }
}
#endif /* MCUXCLKEY_FEATURE_INTERNAL_FLUSH_FUNC */

#ifdef MCUXCLKEY_FEATURE_INTERNAL_HANDLECHECKSUMNONE_FUNC
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_handleKeyChecksums_none, mcuxClKey_HandleKeyChecksums_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_handleKeyChecksums_none(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClKey_KeyChecksum_t * pKeyChecksums UNUSED_PARAM,
  uint8_t* pKey UNUSED_PARAM
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_handleKeyChecksums_none);

  // Nothing to do

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_handleKeyChecksums_none);
}
#endif /* MCUXCLKEY_FEATURE_INTERNAL_HANDLECHECKSUMNONE_FUNC */

/**
 * @brief Key encoding descriptor for loading a plain key by setting the pointer in *ppDest.
 */
const mcuxClKey_EncodingDescriptor_t mcuxClKey_EncodingDescriptor_Plain = {
  .loadFunc = &mcuxClKey_KeyLoad_Plain,
  .protectionToken_loadFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_KeyLoad_Plain),
#ifdef MCUXCLKEY_FEATURE_INTERNAL_STOREPLAIN_FUNC
  .storeFunc = &mcuxClKey_KeyStore_Plain,
  .protectionToken_storeFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_KeyStore_Plain),
#else
  .storeFunc = NULL,
  .protectionToken_storeFunc = 0U,
#endif /* MCUXCLKEY_FEATURE_INTERNAL_STOREPLAIN_FUNC */
#ifdef MCUXCLKEY_FEATURE_INTERNAL_FLUSH_FUNC
  .flushFunc = &mcuxClKey_KeyFlush_Plain,
  .protectionToken_flushFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_KeyFlush_Plain),
#else
  .flushFunc = NULL,
  .protectionToken_flushFunc = 0U,
#endif /* MCUXCLKEY_FEATURE_INTERNAL_FLUSH_FUNC */
#ifdef MCUXCLKEY_FEATURE_INTERNAL_HANDLECHECKSUMNONE_FUNC
  .handleKeyChecksumsFunc = &mcuxClKey_handleKeyChecksums_none,
  .protectionToken_handleKeyChecksumsFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_handleKeyChecksums_none)
#else
  .handleKeyChecksumsFunc = NULL,
  .protectionToken_handleKeyChecksumsFunc = 0U
#endif /* MCUXCLKEY_FEATURE_INTERNAL_HANDLECHECKSUMNONE_FUNC */
};

