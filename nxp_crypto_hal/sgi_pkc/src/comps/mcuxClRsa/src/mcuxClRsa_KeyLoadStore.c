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

/** @file  mcuxClRsa_KeyLoadStore.c
 *  @brief Implementation of @ref mcuxClRsa key load and store functions
 */

#include <mcuxClCore_FunctionIdentifiers.h> // Code flow protection

#include <mcuxClKey.h>
#include <mcuxClSession.h>
#include <mcuxClToolchain.h>

#include <mcuxCsslDataIntegrity.h>

#include <mcuxClRsa_KeyTypes.h>

#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClRsa_Internal_Functions.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyLoad_PlainKey_Plain, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyLoad_PlainKey_Plain(mcuxClSession_Handle_t session,
                                                               mcuxClKey_Handle_t key,
                                                               uint8_t **ppDest,
                                                               mcuxClKey_KeyChecksum_t * pKeyChecksums UNUSED_PARAM,
                                                               mcuxClKey_Encoding_Spec_t spec)
{
  /* TODO: update Core_FunctionIdentifiers once the PR is in an advanced state and CLNS-7582 has been merged.
   * There is no point in doing that now, this will only use time for merge conflicts.
   */
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyLoad_PlainKey_Plain);

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicitly reinterpreting opaque types of workarea-like buffer objects. Key data should be word-aligned.")
  mcuxClRsa_KeyData_Plain_t * pRsaKeyData = (mcuxClRsa_KeyData_Plain_t *) mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_DI_EXPUNGE(inputParamsKey, key);

  if(MCUXCLKEY_ENCODING_SPEC_RSA_E == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
  {
    MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_E);
    MCUX_CSSL_DI_EXPUNGE(inputParamsPpDest, ppDest);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
    *ppDest = pRsaKeyData->exponent.pKeyEntryData;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
  }
  else
  {
    uint8_t const * pSrc = NULL;
    uint32_t length = 0U;
    uint8_t * pDst = *ppDest;
    MCUX_CSSL_DI_EXPUNGE(inputParamsPpDest, ppDest);

    if(MCUXCLKEY_ENCODING_SPEC_RSA_N  == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
    {
      MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_N );
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
      pSrc = pRsaKeyData->modulus.pKeyEntryData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      length = pRsaKeyData->modulus.keyEntryLength;
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(pDst, pSrc, length));
    }
    else if(MCUXCLKEY_ENCODING_SPEC_RSA_D == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
    {
      MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_D);
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
      pSrc = pRsaKeyData->exponent.pKeyEntryData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      length = pRsaKeyData->exponent.keyEntryLength;
      MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(pDst, pSrc, length);
    }
    else
    {
      MCUXCLSESSION_FAULT(session, MCUXCLRSA_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pDst);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pSrc);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, length);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_KeyLoad_PlainKey_Plain,
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_RSA_N == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK)),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int)
      ),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_RSA_D == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK)),
          MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT
      )
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyStore_PrivPlainKey_Plain, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyStore_PrivPlainKey_Plain(mcuxClSession_Handle_t session UNUSED_PARAM,
                                                                mcuxClKey_Handle_t key,
                                                                const uint8_t *pSrc,
                                                                mcuxClKey_Encoding_Spec_t spec UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyStore_PrivPlainKey_Plain);

  /* Get the source key struct from pSrc, and set up the exported key struct.
   * pSrc has been set up by the caller to contain a struct mcuxClRsa_KeyData_Plain_t. */
  uint8_t * pRsaPrivKeyData = mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicitly reinterpreting memory. Key data should be word-aligned.")
  mcuxClRsa_KeyData_Plain_t * pRsaPrivKeyDst = (mcuxClRsa_KeyData_Plain_t *) pRsaPrivKeyData;
  const mcuxClRsa_KeyData_Plain_t * pRsaPrivKeySrc = (const mcuxClRsa_KeyData_Plain_t *) pSrc;
  MCUX_CSSL_DI_EXPUNGE(inputParamsKey, key);

  /* Export n */
  pRsaPrivKeyDst->modulus.pKeyEntryData = (uint8_t *) pRsaPrivKeyData + sizeof(mcuxClRsa_KeyData_Plain_t);
  pRsaPrivKeyDst->modulus.keyEntryLength = pRsaPrivKeySrc->modulus.keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPrivKeyDst->modulus.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPrivKeySrc->modulus.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPrivKeyDst->modulus.keyEntryLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(
    pRsaPrivKeyDst->modulus.pKeyEntryData,
    pRsaPrivKeySrc->modulus.pKeyEntryData,
    pRsaPrivKeyDst->modulus.keyEntryLength
  ));


  /* Secure export d */
  pRsaPrivKeyDst->exponent.pKeyEntryData = pRsaPrivKeyDst->modulus.pKeyEntryData + pRsaPrivKeyDst->modulus.keyEntryLength;
  pRsaPrivKeyDst->exponent.keyEntryLength = pRsaPrivKeySrc->exponent.keyEntryLength;
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivKeyDst->exponent.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivKeySrc->exponent.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivKeyDst->exponent.keyEntryLength);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(
    pRsaPrivKeyDst->exponent.pKeyEntryData,
    pRsaPrivKeySrc->exponent.pKeyEntryData,
    pRsaPrivKeyDst->exponent.keyEntryLength
  );

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_KeyStore_PrivPlainKey_Plain,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int),
      MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyStore_PublicKey_Plain, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyStore_PublicKey_Plain(mcuxClSession_Handle_t session UNUSED_PARAM,
                                                                mcuxClKey_Handle_t key,
                                                                const uint8_t *pSrc,
                                                                mcuxClKey_Encoding_Spec_t spec UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyStore_PublicKey_Plain);

  /* Get the source key struct from pSrc, and set up the exported key struct.
   * pSrc has been set up by the caller to contain a struct mcuxClRsa_KeyData_Plain_t. */
  uint8_t * pRsaPubKeyData = mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicitly reinterpreting memory. Key data should be word-aligned.")
  mcuxClRsa_KeyData_Plain_t * pRsaPubKeyDst = (mcuxClRsa_KeyData_Plain_t *) pRsaPubKeyData;
  const mcuxClRsa_KeyData_Plain_t * pRsaPubKeySrc = (const mcuxClRsa_KeyData_Plain_t *) pSrc;
  MCUX_CSSL_DI_EXPUNGE(inputParamsKey, key);

  /* Export n */
  pRsaPubKeyDst->modulus.pKeyEntryData = (uint8_t *) pRsaPubKeyData + sizeof(mcuxClRsa_KeyData_Plain_t);
  pRsaPubKeyDst->modulus.keyEntryLength = pRsaPubKeySrc->modulus.keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPubKeyDst->modulus.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPubKeySrc->modulus.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPubKeyDst->modulus.keyEntryLength);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(
    pRsaPubKeyDst->modulus.pKeyEntryData,
    pRsaPubKeySrc->modulus.pKeyEntryData,
    pRsaPubKeyDst->modulus.keyEntryLength
  ));


  /* Export e */
  pRsaPubKeyDst->exponent.pKeyEntryData = pRsaPubKeyDst->modulus.pKeyEntryData + pRsaPubKeyDst->modulus.keyEntryLength;
  pRsaPubKeyDst->exponent.keyEntryLength = pRsaPubKeySrc->exponent.keyEntryLength;
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPubKeyDst->exponent.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPubKeySrc->exponent.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPubKeyDst->exponent.keyEntryLength);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(
    pRsaPubKeyDst->exponent.pKeyEntryData,
    pRsaPubKeySrc->exponent.pKeyEntryData,
    pRsaPubKeyDst->exponent.keyEntryLength
  ));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_KeyStore_PublicKey_Plain,
      2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int)
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyLoad_CrtKey_Plain, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyLoad_CrtKey_Plain(mcuxClSession_Handle_t session,
                                                               mcuxClKey_Handle_t key,
                                                               uint8_t **ppDest,
                                                               mcuxClKey_KeyChecksum_t * pKeyChecksums UNUSED_PARAM,
                                                               mcuxClKey_Encoding_Spec_t spec)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyLoad_CrtKey_Plain);

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicitly reinterpreting opaque types of workarea-like buffer objects. Key data should be word-aligned.")
  mcuxClRsa_KeyData_Crt_t * pRsaKeyData = (mcuxClRsa_KeyData_Crt_t *) mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_DI_EXPUNGE(inputParamsKey, key);

  if(MCUXCLKEY_ENCODING_SPEC_RSA_E == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
  {
    MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_E);
    MCUX_CSSL_DI_EXPUNGE(inputParamsPpDest, ppDest);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
    *ppDest = pRsaKeyData->e.pKeyEntryData;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
  }
  else
  {
    uint8_t const * pSrc = NULL;
    uint32_t length = 0U;
    uint8_t * pDst = *ppDest;
    MCUX_CSSL_DI_EXPUNGE(inputParamsPpDest, ppDest);

    if(MCUXCLKEY_ENCODING_SPEC_RSA_P == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
    {
      MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_P);
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
      pSrc = pRsaKeyData->p.pKeyEntryData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      length = pRsaKeyData->p.keyEntryLength;
    }
    else if(MCUXCLKEY_ENCODING_SPEC_RSA_Q == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
    {
      MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_Q);
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
      pSrc = pRsaKeyData->q.pKeyEntryData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      length = pRsaKeyData->q.keyEntryLength;
    }
    else if(MCUXCLKEY_ENCODING_SPEC_RSA_DP == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
    {
      MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_DP);
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
      pSrc = pRsaKeyData->dp.pKeyEntryData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      length = pRsaKeyData->dp.keyEntryLength;
    }
    else if(MCUXCLKEY_ENCODING_SPEC_RSA_DQ == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
    {
      MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_DQ);
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
      pSrc = pRsaKeyData->dq.pKeyEntryData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      length = pRsaKeyData->dq.keyEntryLength;
    }
    else if(MCUXCLKEY_ENCODING_SPEC_RSA_QINV == (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK))
    {
      MCUX_CSSL_DI_EXPUNGE(inputParamsSpec, MCUXCLKEY_ENCODING_SPEC_RSA_QINV);
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pRsaKeyData has compatible type and cast was valid")
      pSrc = pRsaKeyData->qInv.pKeyEntryData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      length = pRsaKeyData->qInv.keyEntryLength;
    }
    else
    {
      MCUXCLSESSION_FAULT(session, MCUXCLRSA_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pDst);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pSrc);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, length);
    MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(pDst, pSrc, length);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_KeyLoad_CrtKey_Plain,
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_RSA_E != (spec & MCUXCLKEY_ENCODING_SPEC_COMP_MASK)),
          MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT
      )
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyStore_PrivCrtKey_Plain, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyStore_PrivCrtKey_Plain(mcuxClSession_Handle_t session UNUSED_PARAM,
                                                                mcuxClKey_Handle_t key,
                                                                const uint8_t *pSrc,
                                                                mcuxClKey_Encoding_Spec_t spec UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyStore_PrivCrtKey_Plain);

  /* Get the source key struct from pSrc, and set up the exported key struct.
   * pSrc has been set up by the caller to contain a struct mcuxClRsa_KeyData_Crt_t. */
  uint8_t * pRsaPrivCrtKeyData = mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicitly reinterpreting memory. Key data should be word-aligned.")
  mcuxClRsa_KeyData_Crt_t * pRsaPrivCrtKeyDst = (mcuxClRsa_KeyData_Crt_t *) pRsaPrivCrtKeyData;
  const mcuxClRsa_KeyData_Crt_t * pRsaPrivCrtKeySrc = (const mcuxClRsa_KeyData_Crt_t *) pSrc;
  MCUX_CSSL_DI_EXPUNGE(inputParamsKey, key);

  /* Secure export p */
  pRsaPrivCrtKeyDst->p.pKeyEntryData = (uint8_t *) pRsaPrivCrtKeyData + sizeof(mcuxClRsa_KeyData_Crt_t);
  pRsaPrivCrtKeyDst->p.keyEntryLength = pRsaPrivCrtKeySrc->p.keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->p.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeySrc->p.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->p.keyEntryLength);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(
    pRsaPrivCrtKeyDst->p.pKeyEntryData,
    pRsaPrivCrtKeySrc->p.pKeyEntryData,
    pRsaPrivCrtKeyDst->p.keyEntryLength
  );

  /* Secure export q */
  pRsaPrivCrtKeyDst->q.pKeyEntryData = pRsaPrivCrtKeyDst->p.pKeyEntryData + pRsaPrivCrtKeyDst->p.keyEntryLength;
  pRsaPrivCrtKeyDst->q.keyEntryLength = pRsaPrivCrtKeySrc->q.keyEntryLength;
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->q.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeySrc->q.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->q.keyEntryLength);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(
    pRsaPrivCrtKeyDst->q.pKeyEntryData,
    pRsaPrivCrtKeySrc->q.pKeyEntryData,
    pRsaPrivCrtKeyDst->q.keyEntryLength
  );

  /* Secure export qInv */
  pRsaPrivCrtKeyDst->qInv.pKeyEntryData = pRsaPrivCrtKeyDst->q.pKeyEntryData + pRsaPrivCrtKeyDst->q.keyEntryLength;
  pRsaPrivCrtKeyDst->qInv.keyEntryLength = pRsaPrivCrtKeySrc->qInv.keyEntryLength;
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->qInv.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeySrc->qInv.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->qInv.keyEntryLength);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(
    pRsaPrivCrtKeyDst->qInv.pKeyEntryData,
    pRsaPrivCrtKeySrc->qInv.pKeyEntryData,
    pRsaPrivCrtKeyDst->qInv.keyEntryLength
  );

  /* Secure export dp */
  pRsaPrivCrtKeyDst->dp.pKeyEntryData = pRsaPrivCrtKeyDst->qInv.pKeyEntryData + pRsaPrivCrtKeyDst->qInv.keyEntryLength;
  pRsaPrivCrtKeyDst->dp.keyEntryLength = pRsaPrivCrtKeySrc->dp.keyEntryLength;
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->dp.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeySrc->dp.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->dp.keyEntryLength);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(
    pRsaPrivCrtKeyDst->dp.pKeyEntryData,
    pRsaPrivCrtKeySrc->dp.pKeyEntryData,
    pRsaPrivCrtKeyDst->dp.keyEntryLength
  );


  /* Secure export dq */
  pRsaPrivCrtKeyDst->dq.pKeyEntryData = pRsaPrivCrtKeyDst->dp.pKeyEntryData + pRsaPrivCrtKeyDst->dp.keyEntryLength;
  pRsaPrivCrtKeyDst->dq.keyEntryLength = pRsaPrivCrtKeySrc->dq.keyEntryLength;
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->dq.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeySrc->dq.pKeyEntryData);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pRsaPrivCrtKeyDst->dq.keyEntryLength);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(
    pRsaPrivCrtKeyDst->dq.pKeyEntryData,
    pRsaPrivCrtKeySrc->dq.pKeyEntryData,
    pRsaPrivCrtKeyDst->dq.keyEntryLength
  );


  /* Export public exponent (should be exported for MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT_DFA only). */
  mcuxClKey_AlgorithmId_t privKeyUsage = mcuxClKey_getKeyUsage(key);
  if(MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT_DFA == privKeyUsage)
  {
    pRsaPrivCrtKeyDst->e.pKeyEntryData = pRsaPrivCrtKeyDst->dq.pKeyEntryData + pRsaPrivCrtKeyDst->dq.keyEntryLength;
    pRsaPrivCrtKeyDst->e.keyEntryLength = pRsaPrivCrtKeySrc->e.keyEntryLength;
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPrivCrtKeyDst->e.pKeyEntryData);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPrivCrtKeySrc->e.pKeyEntryData);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, pRsaPrivCrtKeyDst->e.keyEntryLength);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(
      pRsaPrivCrtKeyDst->e.pKeyEntryData,
      pRsaPrivCrtKeySrc->e.pKeyEntryData,
      pRsaPrivCrtKeyDst->e.keyEntryLength
    ));
  }
  else
  {
    pRsaPrivCrtKeyDst->e.pKeyEntryData = NULL;
    pRsaPrivCrtKeyDst->e.keyEntryLength = 0U;
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_KeyStore_PrivCrtKey_Plain,
      5U * MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT,
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT_DFA == privKeyUsage),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int)
      )
  );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
/**
 * @brief Plain encoding descriptor for RSA private plain keys.
 */
const mcuxClKey_EncodingDescriptor_t mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain = {&mcuxClRsa_KeyLoad_PlainKey_Plain,
                                                                         &mcuxClRsa_KeyStore_PrivPlainKey_Plain,
                                                                         NULL,
                                                                         NULL,
                                                                         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyLoad_PlainKey_Plain),
                                                                         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyStore_PrivPlainKey_Plain),
                                                                         0U,
                                                                         0U};

/**
 * @brief Plain encoding descriptor for RSA public keys.
 */
const mcuxClKey_EncodingDescriptor_t mcuxClRsa_EncodingDescriptor_PublicKey_Plain = {&mcuxClRsa_KeyLoad_PlainKey_Plain,
                                                                         &mcuxClRsa_KeyStore_PublicKey_Plain,
                                                                         NULL,
                                                                         NULL,
                                                                         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyLoad_PlainKey_Plain),
                                                                         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyStore_PublicKey_Plain),
                                                                         0U,
                                                                         0U};
/**
 * @brief Plain encoding descriptor for RSA private CRT keys.
 */
const mcuxClKey_EncodingDescriptor_t mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain = {&mcuxClRsa_KeyLoad_CrtKey_Plain,
                                                                         &mcuxClRsa_KeyStore_PrivCrtKey_Plain,
                                                                         NULL,
                                                                         NULL,
                                                                         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyLoad_CrtKey_Plain),
                                                                         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_KeyStore_PrivCrtKey_Plain),
                                                                         0U,
                                                                         0U};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
