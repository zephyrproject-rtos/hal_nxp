/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClRsa_ModeConstructors.c
 *  @brief mcuxClRsa: implementation of RSA mode constructors for Signature and Cipher components
 */


#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#include <mcuxClCipher.h>
#include <internal/mcuxClCipher_Internal.h>
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

#include <mcuxClPkc_Functions.h>

#include <internal/mcuxClRsa_Internal_Macros.h>


#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>

#include <mcuxClRsa.h>
#include <mcuxClRsa_ModeConstructors.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
/* Cipher crypt mode function for RSA encrypt operation */
static const mcuxClRsa_Cipher_ModeFunctions_t mcuxClRsa_Cipher_ModeFunctions_Rsa_encrypt = {
  .crypt = mcuxClRsa_Util_encrypt,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_encrypt)
};

/* Cipher crypt mode function for RSA decrypt operation */
static const mcuxClRsa_Cipher_ModeFunctions_t mcuxClRsa_Cipher_ModeFunctions_Rsa_decrypt  = {
  .crypt = mcuxClRsa_Util_decrypt,
  .protection_token_crypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_decrypt)
};

#ifdef MCUXCL_FEATURE_RSA_RSAES_OAEP
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Encrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Encrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode,
  mcuxClHash_Algo_t hashAlgorithm
)
{
  /* Create RSA algorithm descriptor after the cipher mode.
   * It is assumed that sufficient space was allocated by users, with the macro MCUXCLRSA_CIPHER_MODE_SIZE */
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting to internal type")
  mcuxClRsa_Cipher_AlgorithmDescriptor_t *pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) ((uint8_t*)pCipherMode + sizeof(mcuxClCipher_ModeDescriptor_t));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

  /* Fill cipher algorithm parameters for RSA with OAEP encoding */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the cipher algorithm parameters.")
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pAlgorithmDescriptor->pHashAlgo = (mcuxClHash_AlgorithmDescriptor_t *)hashAlgorithm;
  pAlgorithmDescriptor->pCryptMode = mcuxClRsa_oaepEncode;
  pAlgorithmDescriptor->crypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_oaepEncode);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()

  /* Fill cipher mode parameters for RSA */
  pCipherMode->pModeFunctions = (const void *) &mcuxClRsa_Cipher_ModeFunctions_Rsa_encrypt;
  pCipherMode->pAlgorithm = pAlgorithmDescriptor;
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Decrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Decrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode,
  mcuxClHash_Algo_t hashAlgorithm
)
{
  /* Create RSA algorithm descriptor after the cipher mode.
   * It is assumed that sufficient space was allocated by users, with the macro MCUXCLRSA_CIPHER_MODE_SIZE */
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting to internal type")
  mcuxClRsa_Cipher_AlgorithmDescriptor_t *pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) ((uint8_t*)pCipherMode + sizeof(mcuxClCipher_ModeDescriptor_t));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

  /* Fill cipher algorithm parameters for RSA with OAEP decoding */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the cipher algorithm parameters.")
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type")
  pAlgorithmDescriptor->pHashAlgo = (mcuxClHash_AlgorithmDescriptor_t *)hashAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  pAlgorithmDescriptor->pCryptMode = mcuxClRsa_oaepDecode;
  pAlgorithmDescriptor->crypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_oaepDecode);

  /* Fill cipher mode parameters for RSA */
  pCipherMode->pModeFunctions = (const void *) &mcuxClRsa_Cipher_ModeFunctions_Rsa_decrypt;
  pCipherMode->pAlgorithm = pAlgorithmDescriptor;
}
#endif /* MCUXCL_FEATURE_RSA_RSAES_OAEP */

#ifdef MCUXCL_FEATURE_RSA_RSAES_PKCS1v15
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Encrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Encrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode
)
{
  /* Create RSA algorithm descriptor after the cipher mode.
   * It is assumed that sufficient space was allocated by users, with the macro MCUXCLRSA_CIPHER_MODE_SIZE */
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting to internal type")
  mcuxClRsa_Cipher_AlgorithmDescriptor_t *pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) ((uint8_t*)pCipherMode + sizeof(mcuxClCipher_ModeDescriptor_t));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

  /* Fill cipher algorithm parameters for RSA with PKCS#1 v1.5 encoding */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type.")
  pAlgorithmDescriptor->pHashAlgo = (mcuxClHash_AlgorithmDescriptor_t *)NULL; /* No hash algorithm is used for RSAES-PKCS1-v1_5 */
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  pAlgorithmDescriptor->pCryptMode = mcuxClRsa_pkcs1v15Encode_encrypt;
  pAlgorithmDescriptor->crypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_encrypt);

  /* Fill cipher mode parameters for RSA */
  pCipherMode->pModeFunctions = (const void *) &mcuxClRsa_Cipher_ModeFunctions_Rsa_encrypt;
  pCipherMode->pAlgorithm = pAlgorithmDescriptor;
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Decrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Decrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode
)
{
  /* Create RSA algorithm descriptor after the cipher mode.
   * It is assumed that sufficient space was allocated by users, with the macro MCUXCLRSA_CIPHER_MODE_SIZE */
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting to internal type")
  mcuxClRsa_Cipher_AlgorithmDescriptor_t *pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) ((uint8_t*)pCipherMode + sizeof(mcuxClCipher_ModeDescriptor_t));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

  /* Fill cipher algorithm parameters for RSA with PKCS#1 v1.5 encoding */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("False positve, correct type.")
  pAlgorithmDescriptor->pHashAlgo = (mcuxClHash_AlgorithmDescriptor_t *)NULL; /* No hash algorithm is used for RSAES-PKCS1-v1_5 */
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  pAlgorithmDescriptor->pCryptMode = mcuxClRsa_pkcs1v15Decode_decrypt;
  pAlgorithmDescriptor->crypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Decode_decrypt);

  /* Fill cipher mode parameters for RSA */
  pCipherMode->pModeFunctions = (const void *) &mcuxClRsa_Cipher_ModeFunctions_Rsa_decrypt;
  pCipherMode->pAlgorithm = pAlgorithmDescriptor;
}
#endif /* MCUXCL_FEATURE_RSA_RSAES_PKCS1v15 */

#endif /* MCUXCL_FEATURE_CIPHER_CRYPT */




MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_Public_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_Public_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_Public_KeyType_ModeConstructor);
  mcuxClRsa_Status_t ret = MCUXCLRSA_STATUS_INVALID_INPUT;
  //The supported bit-size of the key range from 512 to max (4096 or 8192) in multiples of 8
  if((keySize >= 512u/8u) && (keySize <= MCUXCLRSA_MAX_MODLEN))
  {
    pKeyType->algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC;
    pKeyType->size = keySize * 8u; //For RSA the size needs to be in bits
    pKeyType->info = NULL;
    ret = MCUXCLRSA_STATUS_OK;
  }
  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRsa_Public_KeyType_ModeConstructor, ret, MCUXCLRSA_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_PrivatePlain_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_PrivatePlain_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_PrivatePlain_KeyType_ModeConstructor);
  mcuxClRsa_Status_t ret = MCUXCLRSA_STATUS_INVALID_INPUT;
  //The supported bit-size of the key range from 512 to max (4096 or 8192) in multiples of 8
  if((keySize >= 512u/8u) && (keySize <= MCUXCLRSA_MAX_MODLEN))
  {
    pKeyType->algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN;
    pKeyType->size = keySize * 8u; //For RSA the size needs to be in bits
    pKeyType->info = NULL;
    ret = MCUXCLRSA_STATUS_OK;
  }
  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRsa_PrivatePlain_KeyType_ModeConstructor, ret, MCUXCLRSA_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_PrivateCRT_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_PrivateCRT_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_PrivateCRT_KeyType_ModeConstructor);
  mcuxClRsa_Status_t ret = MCUXCLRSA_STATUS_INVALID_INPUT;
  //The supported bit-size of the key range from 512 to max (4096 or 8192) in multiples of 8
  if((keySize >= 512u/8u) && (keySize <= MCUXCLRSA_MAX_MODLEN))
  {
    pKeyType->algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT;
    pKeyType->size = keySize * 8u; //For RSA the size needs to be in bits
    pKeyType->info = NULL;
    ret = MCUXCLRSA_STATUS_OK;
  }
  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRsa_PrivateCRT_KeyType_ModeConstructor, ret, MCUXCLRSA_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_PrivateCRT_DFA_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_PrivateCRT_DFA_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_PrivateCRT_DFA_KeyType_ModeConstructor);
  mcuxClRsa_Status_t ret = MCUXCLRSA_STATUS_INVALID_INPUT;
  //The supported bit-size of the key range from 512 to max (4096 or 8192) in multiples of 8
  if((keySize >= 512u/8u) && (keySize <= MCUXCLRSA_MAX_MODLEN))
  {
    pKeyType->algoId = MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA;
    pKeyType->size = keySize * 8u; //For RSA the size needs to be in bits
    pKeyType->info = NULL;
    ret = MCUXCLRSA_STATUS_OK;
  }
  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRsa_PrivateCRT_DFA_KeyType_ModeConstructor, ret, MCUXCLRSA_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
