/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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

/** @file  mcuxClRsa_KeyGeneration_Helper.c
 *  @brief mcuxClRsa: implementation of RSA key generation helper function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClRandom.h>
#include <mcuxClPkc.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>
#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>


#ifdef MCUXCL_FEATURE_RSA_STRENGTH_CHECK
#define MCUXCLRSA_KEYGEN_FP_SECSTRENGTH  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_checkSecurityStrength)
#else
#define MCUXCLRSA_KEYGEN_FP_SECSTRENGTH  (0u)
#endif

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyGeneration_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_KeyGeneration_Init(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Type_t type,
  uint32_t *byteLenE)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyGeneration_Init);

  /*
   * 1. Check the key type, i.e.:
   * - algorithm IDs
   * - key sizes (it should be 1024, 2048, 3072, 4096, 6144 or 8192).
   *
   * If did not pass verification, function returns MCUXCLRSA_STATUS_INVALID_INPUT error.
   *
   */
  const uint32_t bitLenKey = type->size;
  if(((MCUXCLKEY_ALGO_ID_RSA | MCUXCLKEY_ALGO_ID_KEY_PAIR) != type->algoId)
       || ((MCUXCLKEY_SIZE_2048 != bitLenKey)
            && (MCUXCLKEY_SIZE_3072 != bitLenKey)
            && (MCUXCLKEY_SIZE_4096 != bitLenKey)
            ))
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Init, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

#ifdef MCUXCL_FEATURE_RSA_STRENGTH_CHECK
  /*
   * 2. Check entropy provided by RNG
   *    If the RNG does not provide an appropriate level of entropy (security strength)
   *    for the given key size, this function returns MCUXCLRSA_STATUS_RNG_ERROR error.
   */
  uint32_t securityStrength = MCUXCLRSA_GET_MINIMUM_SECURITY_STRENGTH(bitLenKey);
  MCUX_CSSL_FP_FUNCTION_CALL(ret_checkSecurityStrength, mcuxClRandom_checkSecurityStrength(pSession, securityStrength));
  if(MCUXCLRANDOM_STATUS_OK != ret_checkSecurityStrength)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Init, MCUXCLRSA_STATUS_RNG_ERROR,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_checkSecurityStrength));
  }
#endif

  /*
   * 3. Check if E is FIPS compliant, i.e., is odd values in the range 2^16 < e < 2^256,
   *    determine the length without leading zeros.
   *    If did not pass verification, function returns MCUXCLRSA_STATUS_INVALID_INPUT error.
   */
  mcuxClRsa_KeyEntry_t * pPublicExponent = (mcuxClRsa_KeyEntry_t *) type->info;
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_VerifyE, mcuxClRsa_VerifyE(pPublicExponent, byteLenE));
  if(MCUXCLRSA_STATUS_KEYGENERATION_OK != retVal_VerifyE)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Init, MCUXCLRSA_STATUS_INVALID_INPUT,
        MCUXCLRSA_KEYGEN_FP_SECSTRENGTH,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_VerifyE));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Init, MCUXCLRSA_STATUS_OK,
      MCUXCLRSA_KEYGEN_FP_SECSTRENGTH,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_VerifyE));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyGeneration_StorePrivateCRT)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_KeyGeneration_StorePrivateCRT(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t pSession,
  uint8_t * pPrivData,
  uint32_t * const pPrivDataLength,
  uint32_t byteLenPrime)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyGeneration_StorePrivateCRT);
  /*
   * 15. Write RSA CRT key (p, q, qInv, dp, dq) to the buffer pointed by pPrivData.
   *     This buffer contains RSA key (mcuxClRsa_Key data type, i.e.: key type and key entries)
   *     followed by the key data, i.e.: p, q, qInv, dp, dq.
   *     Key entries stored in big-endian byte order (copy with reverse order).
   *
   * Used functions: mcuxClPkc_SecureExportBigEndianFromPkc
   */

  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting to internal type")
  mcuxClRsa_Key *pRsaPrivCrtKey = (mcuxClRsa_Key *) pPrivData;

  pRsaPrivCrtKey->keytype = MCUXCLRSA_KEY_PRIVATECRT;
  *pPrivDataLength = sizeof(mcuxClRsa_Key);


  pRsaPrivCrtKey->pMod1 = (mcuxClRsa_KeyEntry_t *) (pPrivData + *pPrivDataLength);
  *pPrivDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPrivCrtKey->pMod2 = (mcuxClRsa_KeyEntry_t *) (pPrivData + *pPrivDataLength);
  *pPrivDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPrivCrtKey->pQInv = (mcuxClRsa_KeyEntry_t *) (pPrivData + *pPrivDataLength);
  *pPrivDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPrivCrtKey->pExp1 = (mcuxClRsa_KeyEntry_t *) (pPrivData + *pPrivDataLength);
  *pPrivDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPrivCrtKey->pExp2 = (mcuxClRsa_KeyEntry_t *) (pPrivData + *pPrivDataLength);
  *pPrivDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPrivCrtKey->pExp3 = NULL;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type.")
  pRsaPrivCrtKey->pMod1->pKeyEntryData = pPrivData + *pPrivDataLength;
  pRsaPrivCrtKey->pMod1->keyEntryLength = byteLenPrime;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_FP_FUNCTION_CALL(ret_SecExportP,
      mcuxClPkc_SecureExportBigEndianFromPkc(pSession,
                                            pRsaPrivCrtKey->pMod1->pKeyEntryData,
                                            MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1),
                                            pRsaPrivCrtKey->pMod1->keyEntryLength));
  if (MCUXCLPKC_STATUS_OK != ret_SecExportP)
  {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_StorePrivateCRT, MCUXCLRSA_STATUS_ERROR);
  }
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The sum of Key length cannot wrap.")
  *pPrivDataLength += pRsaPrivCrtKey->pMod1->keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pRsaPrivCrtKey->pMod2->pKeyEntryData = pPrivData + *pPrivDataLength;
  pRsaPrivCrtKey->pMod2->keyEntryLength = byteLenPrime;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_FP_FUNCTION_CALL(ret_SecExportQ,
      mcuxClPkc_SecureExportBigEndianFromPkc(pSession,
                                            pRsaPrivCrtKey->pMod2->pKeyEntryData,
                                            MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1),
                                            pRsaPrivCrtKey->pMod2->keyEntryLength));
  if (MCUXCLPKC_STATUS_OK != ret_SecExportQ)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_StorePrivateCRT, MCUXCLRSA_STATUS_ERROR);
  }
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The sum of key length cannot wrap.")
  *pPrivDataLength += pRsaPrivCrtKey->pMod2->keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pRsaPrivCrtKey->pQInv->pKeyEntryData = pPrivData + *pPrivDataLength;
  pRsaPrivCrtKey->pQInv->keyEntryLength = byteLenPrime;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_FP_FUNCTION_CALL(ret_SecExportQinv,
      mcuxClPkc_SecureExportBigEndianFromPkc(pSession,
                                            pRsaPrivCrtKey->pQInv->pKeyEntryData,
                                            MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_QINV,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1),
                                            pRsaPrivCrtKey->pQInv->keyEntryLength));
  if (MCUXCLPKC_STATUS_OK != ret_SecExportQinv)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_StorePrivateCRT, MCUXCLRSA_STATUS_ERROR);
  }
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The sum of key length cannot wrap.")
  *pPrivDataLength += pRsaPrivCrtKey->pQInv->keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pRsaPrivCrtKey->pExp1->pKeyEntryData = pPrivData + *pPrivDataLength;
  pRsaPrivCrtKey->pExp1->keyEntryLength = byteLenPrime;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_FP_FUNCTION_CALL(ret_SecExportDp,
      mcuxClPkc_SecureExportBigEndianFromPkc(pSession,
                                            pRsaPrivCrtKey->pExp1->pKeyEntryData,
                                            MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DP,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1),
                                            pRsaPrivCrtKey->pExp1->keyEntryLength));
  if (MCUXCLPKC_STATUS_OK != ret_SecExportDp)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_StorePrivateCRT, MCUXCLRSA_STATUS_ERROR);
  }
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The sum of key length cannot wrap.")
  *pPrivDataLength += pRsaPrivCrtKey->pExp1->keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pRsaPrivCrtKey->pExp2->pKeyEntryData = pPrivData + *pPrivDataLength;
  pRsaPrivCrtKey->pExp2->keyEntryLength = byteLenPrime;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_FP_FUNCTION_CALL(ret_SecExportDq,
      mcuxClPkc_SecureExportBigEndianFromPkc(pSession,
                                            pRsaPrivCrtKey->pExp2->pKeyEntryData,
                                            MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DQ,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1),
                                            pRsaPrivCrtKey->pExp2->keyEntryLength));
  if (MCUXCLPKC_STATUS_OK != ret_SecExportDq)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_StorePrivateCRT, MCUXCLRSA_STATUS_ERROR);
  }
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The sum of key length cannot wrap.")
  *pPrivDataLength += pRsaPrivCrtKey->pExp2->keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_StorePrivateCRT, MCUXCLRSA_STATUS_OK,
    5u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureExportBigEndianFromPkc));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyGeneration_StorePrivatePlain)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_KeyGeneration_StorePrivatePlain(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t pSession,
  uint8_t * pPrivData,
  uint32_t * const pPrivDataLength,
  uint8_t * pPubData,
  uint32_t dLen)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyGeneration_StorePrivatePlain);
  /*
   * 13. Write RSA plain key (d, n) to the buffer pointed by pPrivData.
   *     This buffer contains RSA key (mcuxClRsa_Key data type, i.e.: key type and key entries)
   *     followed by the key data, i.e.: n, d.
   *     Key entries stored in big-endian byte order (copy with reverse order).
   *
   * Used functions: mcuxClPkc_ExportBigEndianFromPkc (to export n);
   *                 mcuxClPkc_SecureExportBigEndianFromPkc (to export d).
   */
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting to internal type")
  mcuxClRsa_Key *pRsaPrivatePlainKey = (mcuxClRsa_Key *) pPrivData;
  mcuxClRsa_Key *pRsaPubKey = (mcuxClRsa_Key *) pPubData;
  pRsaPrivatePlainKey->keytype = MCUXCLRSA_KEY_PRIVATEPLAIN;
  *pPrivDataLength = sizeof(mcuxClRsa_Key);

  pRsaPrivatePlainKey->pMod1 = (mcuxClRsa_KeyEntry_t *) (pPrivData + *pPrivDataLength);
  *pPrivDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPrivatePlainKey->pMod2 = NULL;
  pRsaPrivatePlainKey->pQInv = NULL;

  pRsaPrivatePlainKey->pExp1 = (mcuxClRsa_KeyEntry_t *) (pPrivData + *pPrivDataLength);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

  *pPrivDataLength += sizeof(mcuxClRsa_KeyEntry_t);
  pRsaPrivatePlainKey->pExp2 = NULL;
  pRsaPrivatePlainKey->pExp3 = NULL;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  uint32_t byteLenKey = pRsaPubKey->pMod1->keyEntryLength;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(pRsaPubKey->pMod1->keyEntryLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  pRsaPrivatePlainKey->pMod1->pKeyEntryData = pPrivData + *pPrivDataLength;
  pRsaPrivatePlainKey->pMod1->keyEntryLength = byteLenKey;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUXCLMEMORY_FP_MEMORY_COPY(
      pRsaPrivatePlainKey->pMod1->pKeyEntryData,
      pRsaPubKey->pMod1->pKeyEntryData,
      pRsaPrivatePlainKey->pMod1->keyEntryLength);

  *pPrivDataLength += pRsaPrivatePlainKey->pMod1->keyEntryLength;

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pRsaPrivatePlainKey->pExp1->pKeyEntryData = pPrivData + *pPrivDataLength;
  pRsaPrivatePlainKey->pExp1->keyEntryLength = dLen;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  const uint32_t pkcByteLenKey = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(byteLenKey);
  MCUXCLPKC_PS1_SETLENGTH(0u, pkcByteLenKey); /* set operand len for mcuxClPkc_SecureExportBigEndianFromPkc */
  MCUX_CSSL_FP_FUNCTION_CALL(ret_SecExportD,
      mcuxClPkc_SecureExportBigEndianFromPkc(pSession,
                                            pRsaPrivatePlainKey->pExp1->pKeyEntryData,
                                            MCUXCLPKC_PACKARGS2(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_D,
                                                               MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_N /* used as a temp */),
                                            pRsaPrivatePlainKey->pExp1->keyEntryLength));
  if (MCUXCLPKC_STATUS_OK != ret_SecExportD)
  {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_Plain, MCUXCLRSA_STATUS_ERROR);
  }
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The sum of key length cannot wrap.")
  *pPrivDataLength += pRsaPrivatePlainKey->pExp1->keyEntryLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_KeyGeneration_StorePrivatePlain, MCUXCLRSA_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureExportBigEndianFromPkc));
}
