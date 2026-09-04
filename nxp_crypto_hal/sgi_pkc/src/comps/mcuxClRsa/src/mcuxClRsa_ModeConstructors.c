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

/** @file  mcuxClRsa_ModeConstructors.c
 *  @brief mcuxClRsa: implementation of RSA mode constructors for Signature and Cipher components
 */

#include <mcuxClSignature.h>
#include <internal/mcuxClSignature_Internal.h>

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#include <mcuxClCipher.h>
#include <internal/mcuxClCipher_Internal.h>
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

#include <internal/mcuxClPkc_Internal_Functions.h>

#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>

#include <mcuxClRsa.h>
#include <mcuxClRsa_ModeConstructors.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

/**
 * @brief Initialize PKC hardware
 *
 * @param[in]   pIn      session handle for the current CL session.
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_PkcInitialize, mcuxClRsa_PkcInitializeEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_PkcInitialize(mcuxClSession_Handle_t session)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_PkcInitialize);
  MCUXCLPKC_FP_INITIALIZE(session);
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_PkcInitialize, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_Initialize));
}

/**
 * @brief Deinitialize PKC hardware
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_PkcDeinitialize, mcuxClRsa_PkcDeInitializeEngine_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_PkcDeinitialize(void)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_PkcDeinitialize);
  MCUXCLPKC_FP_DEINITIALIZE();
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_PkcDeinitialize, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_Deinitialize));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_SignatureModeConstructor_RSASSA_PSS)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_SignatureModeConstructor_RSASSA_PSS(
  mcuxClSignature_ModeDescriptor_t * pSignatureMode,
  mcuxClRsa_SignatureProtocolDescriptor_t * pProtocolDescriptor,
  mcuxClHash_Algo_t hashAlgorithm,
  uint32_t saltLength,
  uint32_t options)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_SignatureModeConstructor_RSASSA_PSS);

  /* Fill signature protocol parameters for RSA with PSS encoding */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the protocol parameters.")
  pProtocolDescriptor->pHashAlgo = (mcuxClHash_AlgorithmDescriptor_t *)hashAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  pProtocolDescriptor->pSignMode = mcuxClRsa_pssEncode;
  pProtocolDescriptor->sign_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssEncode);
  pProtocolDescriptor->pVerifyMode = mcuxClRsa_pssVerify;
  pProtocolDescriptor->verify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pssVerify);
  pProtocolDescriptor->saltLength = saltLength;
  pProtocolDescriptor->options = options;

  {
    pProtocolDescriptor->pPkcInitFun = mcuxClRsa_PkcInitialize;
    pProtocolDescriptor->pPkcDeInitFun = mcuxClRsa_PkcDeinitialize;
    pProtocolDescriptor->pkcInit_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_PkcInitialize);
    pProtocolDescriptor->pkcDeInit_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_PkcDeinitialize);
    pProtocolDescriptor->pRsaPublicExpFun = mcuxClRsa_public;
    pProtocolDescriptor->rsaPublicExp_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_public);
  }

  /* Fill signature mode parameters for RSA */
  pSignatureMode->pSignFct = mcuxClRsa_Util_sign;
  pSignatureMode->protection_token_sign = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_sign);
  pSignatureMode->pVerifyFct = mcuxClRsa_Util_verify;
  pSignatureMode->protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_verify);
  pSignatureMode->pProtocolDescriptor = pProtocolDescriptor;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_SignatureModeConstructor_RSASSA_PSS);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_SignatureModeConstructor_RSASSA_PKCS1_v1_5)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_SignatureModeConstructor_RSASSA_PKCS1_v1_5(
  mcuxClSignature_ModeDescriptor_t * pSignatureMode,
  mcuxClRsa_SignatureProtocolDescriptor_t * pProtocolDescriptor,
  mcuxClHash_Algo_t hashAlgorithm,
  uint32_t options)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_SignatureModeConstructor_RSASSA_PKCS1_v1_5);

  /* Fill signature protocol parameters for RSA with PKCS#1 v1.5 encoding */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the protocol parameters")
  pProtocolDescriptor->pHashAlgo = (mcuxClHash_AlgorithmDescriptor_t *)hashAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  pProtocolDescriptor->pSignMode = mcuxClRsa_pkcs1v15Encode_sign;
  pProtocolDescriptor->sign_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_sign);
  pProtocolDescriptor->pVerifyMode = mcuxClRsa_pkcs1v15Verify;
  pProtocolDescriptor->verify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Verify);
  pProtocolDescriptor->saltLength = 0U; /* there is no salt for PKCS#1 */
  pProtocolDescriptor->options = options;

  {
    pProtocolDescriptor->pPkcInitFun = mcuxClRsa_PkcInitialize;
    pProtocolDescriptor->pPkcDeInitFun = mcuxClRsa_PkcDeinitialize;
    pProtocolDescriptor->pkcInit_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_PkcInitialize);
    pProtocolDescriptor->pkcDeInit_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_PkcDeinitialize);
    pProtocolDescriptor->pRsaPublicExpFun = mcuxClRsa_public;
    pProtocolDescriptor->rsaPublicExp_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_public);
  }

  /* Fill signature mode parameters for RSA */
  pSignatureMode->pSignFct = mcuxClRsa_Util_sign;
  pSignatureMode->protection_token_sign = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_sign);
  pSignatureMode->pVerifyFct = mcuxClRsa_Util_verify;
  pSignatureMode->protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_verify);
  pSignatureMode->pProtocolDescriptor = pProtocolDescriptor;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_SignatureModeConstructor_RSASSA_PKCS1_v1_5);
}


#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
/* Cipher encrypt/decrypt mode functions for RSA encrypt and decrypt operations */
static const mcuxClRsa_Cipher_ModeFunctions_t mcuxClRsa_Cipher_ModeFunctions_Rsa = {
  .encrypt = mcuxClRsa_Util_encrypt,
  .decrypt = mcuxClRsa_Util_decrypt,
  .protection_token_encrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_encrypt),
  .protection_token_decrypt = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_Util_decrypt)
};

#ifdef MCUXCL_FEATURE_RSA_RSAES_OAEP
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_CipherModeConstructor_RSAES_OAEP)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_CipherModeConstructor_RSAES_OAEP(
  mcuxClCipher_ModeDescriptor_t * pCipherMode,
  mcuxClHash_Algo_t hashAlgorithm
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_CipherModeConstructor_RSAES_OAEP);

  /* Create RSA algorithm descriptor after the cipher mode.
   * It is assumed that sufficient space was allocated by users, with the macro MCUXCLRSA_CIPHER_MODE_SIZE */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicit cast to reinterpret memory, to initialize pAlgorithmDescriptor at word-aligned location after pCipherMode")
  mcuxClRsa_Cipher_AlgorithmDescriptor_t *pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) ((uint8_t*)pCipherMode + sizeof(mcuxClCipher_ModeDescriptor_t));

  /* Fill cipher algorithm parameters for RSA with OAEP encoding */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the cipher algorithm parameters.")
  pAlgorithmDescriptor->pHashAlgo = (mcuxClHash_AlgorithmDescriptor_t *)hashAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  pAlgorithmDescriptor->pEncryptMode = mcuxClRsa_oaepEncode;
  pAlgorithmDescriptor->pDecryptMode = mcuxClRsa_oaepDecode;
  pAlgorithmDescriptor->encrypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_oaepEncode);
  pAlgorithmDescriptor->decrypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_oaepDecode);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

  /* Fill cipher mode parameters for RSA */
  pCipherMode->pModeFunctions = (const void *) &mcuxClRsa_Cipher_ModeFunctions_Rsa;
  pCipherMode->pAlgorithm = pAlgorithmDescriptor;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_CipherModeConstructor_RSAES_OAEP);
}
#endif /* MCUXCL_FEATURE_RSA_RSAES_OAEP */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5(
  mcuxClCipher_ModeDescriptor_t * pCipherMode
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5);

  /* Create RSA algorithm descriptor after the cipher mode.
   * It is assumed that sufficient space was allocated by users, with the macro MCUXCLRSA_CIPHER_MODE_SIZE */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicit cast to reinterpret memory, to initialize pAlgorithmDescriptor at word-aligned location after pCipherMode")
  mcuxClRsa_Cipher_AlgorithmDescriptor_t *pAlgorithmDescriptor = (mcuxClRsa_Cipher_AlgorithmDescriptor_t *) ((uint8_t*)pCipherMode + sizeof(mcuxClCipher_ModeDescriptor_t));

  /* Fill cipher algorithm parameters for RSA with PKCS#1 v1.5 encoding */
  pAlgorithmDescriptor->pHashAlgo = NULL; /* No hash algorithm is used for RSAES-PKCS1-v1_5 */
  pAlgorithmDescriptor->pEncryptMode = mcuxClRsa_pkcs1v15Encode_encrypt;
  pAlgorithmDescriptor->pDecryptMode = mcuxClRsa_pkcs1v15Decode_decrypt;
  pAlgorithmDescriptor->encrypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_encrypt);
  pAlgorithmDescriptor->decrypt_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Decode_decrypt);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

  /* Fill cipher mode parameters for RSA */
  pCipherMode->pModeFunctions = (const void *) &mcuxClRsa_Cipher_ModeFunctions_Rsa;
  pCipherMode->pAlgorithm = pAlgorithmDescriptor;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5);
}


#endif /* MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT || MCUXCL_FEATURE_CIPHER_RSA_DECRYPT */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_KeyGeneration_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyGeneration_ModeConstructor(
  mcuxClKey_GenerationDescriptor_t * pKeyGenMode,
  const uint8_t * pE,
  uint32_t eLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_KeyGeneration_ModeConstructor);

  /* Create RSA descriptor after the key mode.
   * It is assumed that sufficient space was allocated by users, with the macro MCUXCLRSA_KEYGEN_MODE_SIZE */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Explicit cast to reinterpret memory, to initialize pProtocolDescriptor at word-aligned location after pKeyGenMode")
  mcuxClRsa_KeyGeneration_ProtocolDescriptor_t *pProtocolDescriptor = (mcuxClRsa_KeyGeneration_ProtocolDescriptor_t *) ((uint8_t*)pKeyGenMode + sizeof(mcuxClKey_GenerationDescriptor_t));

  /* Fill key protocol parameters for RSA key generation */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the key protocol parameters")
  pProtocolDescriptor->pubExp.pKeyEntryData = (uint8_t *)pE;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  pProtocolDescriptor->pubExp.keyEntryLength = eLength;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

  /* Fill cipher mode parameters for RSA */
  pKeyGenMode->pKeyGenFct = mcuxClRsa_KeyGeneration_GenerateKeyPair;
  pKeyGenMode->protectionTokenKeyGenFct = MCUX_CSSL_FP_FUNCID_mcuxClRsa_KeyGeneration_GenerateKeyPair;
  pKeyGenMode->pProtocolDescriptor = (void *) pProtocolDescriptor;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRsa_KeyGeneration_ModeConstructor);
}

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
