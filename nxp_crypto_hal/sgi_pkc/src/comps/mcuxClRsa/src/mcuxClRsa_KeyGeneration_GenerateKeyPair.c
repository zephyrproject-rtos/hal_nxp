/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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

/** @file  mcuxClRsa_KeyGeneration_GenerateKeyPair.c
 *  @brief mcuxClRsa: implementation of RSA key generation function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>

#include <internal/mcuxClSession_Internal.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyGeneration_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyGeneration_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyGeneration_GenerateKeyPair);


  /*********************************************************/
  /* Verify key sizes in bits                              */
  /*********************************************************/

  const uint32_t publicKeySize = mcuxClKey_getSize(pubKey);
  const uint32_t privateKeySize = mcuxClKey_getSize(privKey);
  if(((MCUXCLKEY_SIZE_1024 != publicKeySize)
    && (MCUXCLKEY_SIZE_2048 != publicKeySize)
    && (MCUXCLKEY_SIZE_3072 != publicKeySize)
    && (MCUXCLKEY_SIZE_4096 != publicKeySize)
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
    && (MCUXCLKEY_SIZE_6144 != publicKeySize)
    && (MCUXCLKEY_SIZE_8192 != publicKeySize)
#endif
    ) || (publicKeySize != privateKeySize))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
  }

  /****************************************************************/
  /* Execute key generation function                              */
  /****************************************************************/
  mcuxClKey_AlgorithmId_t privKeyUsage = mcuxClKey_getKeyUsage(privKey);
  if((MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT == privKeyUsage) || (MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT_DFA == privKeyUsage))
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClRsa_Util_KeyGeneration_Crt(pSession,
        generation,
        privKey,
        pubKey
        ));
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClRsa_Util_KeyGeneration_Plain(pSession,
        generation,
        privKey,
        pubKey
        ));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_KeyGeneration_GenerateKeyPair,
    (((MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT == privKeyUsage) || (MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT_DFA == privKeyUsage)) ?
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_KeyGeneration_Crt) :
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_KeyGeneration_Plain))
    );
}
