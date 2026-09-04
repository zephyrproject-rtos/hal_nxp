/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/**
 * @file  mcuxClRsa_Internal_Types.h
 * @brief Internal type definitions for the mcuxClRsa component
 */

#ifndef MCUXCLRSA_INTERNAL_TYPES_H_
#define MCUXCLRSA_INTERNAL_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClRsa_Types.h>
#include <mcuxClHash_Types.h>
#include <mcuxClBuffer.h>

#include <mcuxClRsa_ModeConstructors.h>

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#include <internal/mcuxClCipher_Internal_Types.h>
#endif /* MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT || MCUXCL_FEATURE_CIPHER_RSA_DECRYPT */

#ifdef __cplusplus
extern "C" {
#endif

 /**
 * @defgroup mcuxClRsa_Internal_Macros mcuxClRsa_Internal_Macros
 * @brief Defines all internal macros of the @ref mcuxClRsa component
 * @ingroup mcuxClRsa
 * @{
 */

/**
 * @defgroup MCUXCLRSA_STATUS_INTERNAL_ MCUXCLRSA_STATUS_INTERNAL_
 * @brief Internal return code definitions
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_STATUS_INTERNAL_KEYOP_OK                 ((mcuxClRsa_Status_t) 0xB2B25A5AU )  ///< RSA key operation successful
#define MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK                ((mcuxClRsa_Status_t) 0xB2B29A9AU )  ///< RSA encoding operation successful
#define MCUXCLRSA_STATUS_INTERNAL_MGF_OK                   ((mcuxClRsa_Status_t) 0xB2B2AAAAU )  ///< RSA mask generation function operation successful
#define MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_CMP_FAILED     ((mcuxClRsa_Status_t) 0xB2B2ABABU )  ///< RSA key generation test failed at comparison stage
#define MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_GCDA0_FAILED   ((mcuxClRsa_Status_t) 0xB2B2ADADU )  ///< RSA key generation test failed at the stage of GCD with A0
#define MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_GCDE_FAILED    ((mcuxClRsa_Status_t) 0xB2B2AEAEU )  ///< RSA key generation test failed at the stage of GCD with E
#define MCUXCLRSA_STATUS_INTERNAL_TESTPRIME_MRT_FAILED     ((mcuxClRsa_Status_t) 0xB2B2AFAFU )  ///< RSA key generation test failed at the stage of Miller Rabin Test
#define MCUXCLRSA_STATUS_INTERNAL_PRIVEXP_INVALID          ((mcuxClRsa_Status_t) 0xB2B2ACACU )  ///< The private exponent d does not meet the FIPS 186-5 (A.1.1, step 3) requirements

/** @} */

/**
 * @}
 */

/***********************************************************
 *  TYPES RELATED TO PADDING FUNCTIONALITY
 **********************************************************/

 /**
 * @brief Function type for padding engine
 *
 * Generic function pointer to padding function declarations
 *
 * @param[in]  pSession                Pointer to session.
 * @param[in]  pInput                  Buffer that contains the input data.
 * @param[in]  inputLength             Length of input in bytes.
 * @param[in]  pVerificationInput      Pointer to encoded message that is verified.
 * @param[in]  pHashAlgo               Pointer to hash algorithm used in padding function.
 * @param[in]  pLabel                  Buffer that contains the label in case of OAEP padding.
 * @param[in]  saltlabelLength         Length of salt in case of PSS padding, or label in case of OAEP padding.
 * @param[in]  keyBitLength            Bitlength of public modulus n.
 * @param[in]  options                 Options.
 * @param[out] pOutput                 Buffer that contains the output of the padding function.
 * @param[out] pOutLength              Length of output in bytes.
 *
 * @return Status of the padding operation
 *
 * @attention  Data Integrity (only when used for signature verification operation):
 *             Expunge(pInput + pVerificationInput)
 *             Record(returnCode)
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRsa_PadVerModeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) (* mcuxClRsa_PadVerModeEngine_t)(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength));

/**
 * @brief RSA-specific key types
 */
#define MCUXCLRSA_KEYTYPE_INTERNAL_PUBLIC         (MCUXCLKEY_ALGO_ID_RSA | MCUXCLKEY_ALGO_ID_PUBLIC_KEY)
#define MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN   (MCUXCLKEY_ALGO_ID_RSA | MCUXCLKEY_ALGO_ID_PRIVATE_KEY)
#define MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT     (MCUXCLKEY_ALGO_ID_RSA | MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT)
#define MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA  (MCUXCLKEY_ALGO_ID_RSA | MCUXCLKEY_ALGO_ID_PRIVATE_KEY_CRT_DFA)

/**
* @brief Function type for RSA public exponentiation engine
*
* Generic function pointer to RSA public exponentiation function.
* See mcuxClRsa_NoHwAcc_Public and mcuxClRsa_public for more details.
*
*/
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRsa_PublicExpEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRsa_PublicExpEngine_t)(
    mcuxClSession_Handle_t      pSession,
    mcuxClKey_Handle_t          key,
    mcuxCl_InputBuffer_t        pInput,
    uint8_t *                  pOutput));

/**
* @brief Function type for PKC initialization engine
*
* Generic function pointer to PKC initialization function
*
* @param[in]   session  session handle for the current CL session.
*/
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRsa_PkcInitializeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRsa_PkcInitializeEngine_t)(mcuxClSession_Handle_t session));

/**
* @brief Function type for PKC deinitialization engine
*
* Generic function pointer to PKC deinitialization function
*
*/
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRsa_PkcDeInitializeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRsa_PkcDeInitializeEngine_t)(void));

/**
 * @brief RSA-specific protocol descriptor structure for signature generation/verification with @ref mcuxClSignature
 */
struct mcuxClRsa_Signature_ProtocolDescriptor
{
  mcuxClHash_AlgorithmDescriptor_t *  pHashAlgo;     ///< Pointer to hashing functionality.
  mcuxClRsa_PadVerModeEngine_t   pSignMode;          ///< Pointer to padding functionality for the signature generation.
  mcuxClRsa_PadVerModeEngine_t   pVerifyMode;        ///< Pointer to padding functionality for the signature verification.
  uint32_t                      sign_FunId;         ///< Flow protection function identifier of padding function.
  uint32_t                      verify_FunId;       ///< Flow protection function identifier of padding verification function.
  mcuxClRsa_PkcInitializeEngine_t pPkcInitFun;       ///< Pointer to PKC initialization functionality for the signature verification.
  uint32_t                      pkcInit_FunId;      ///< Flow protection function identifier of PKC initialization function.
  mcuxClRsa_PkcDeInitializeEngine_t pPkcDeInitFun;   ///< Pointer to PKC deinitialization functionality for the signature verification.
  uint32_t                      pkcDeInit_FunId;    ///< Flow protection function identifier of PKC deinitialization function.
  mcuxClRsa_PublicExpEngine_t    pRsaPublicExpFun;   ///< Pointer to public exponentiation functionality for the signature verification.
  uint32_t                      rsaPublicExp_FunId; ///< Flow protection function identifier of public exponentiation function.
  uint32_t                      saltLength;         ///< Number of bytes of the salt, only used for PSS padding.
  uint32_t                      options;            ///< Options.
};

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
/**
 * @brief RSA-specific algorithm descriptor structure for encryption/decryption with @ref mcuxClCipher
 */
typedef struct
{
  mcuxClHash_AlgorithmDescriptor_t *  pHashAlgo;   ///< Pointer to hashing functionality.
  mcuxClRsa_PadVerModeEngine_t   pEncryptMode;     ///< Pointer to padding functionality for the encryption.
  mcuxClRsa_PadVerModeEngine_t   pDecryptMode;     ///< Pointer to padding functionality for the decryption.
  uint32_t                      encrypt_FunId;    ///< Flow protection function identifier of encoding function.
  uint32_t                      decrypt_FunId;    ///< Flow protection function identifier of decoding function.
} mcuxClRsa_Cipher_AlgorithmDescriptor_t;

/**
 * @brief This structure captures all the information related to the functions
 * of the Cipher interfaces.
 */
typedef struct mcuxClRsa_Cipher_ModeFunctions
{
  MCUXCLCIPHER_ENCRYPT_DECRYPT_ONESHOT_MODEFUNCTIONS
} mcuxClRsa_Cipher_ModeFunctions_t;
#endif /* MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT || MCUXCL_FEATURE_CIPHER_RSA_DECRYPT */

/**
 * @brief RSA-specific protocol descriptor structure for key generation with @ref mcuxClKey
 *
 * TODO CLNS-7015: An extra entry in the protocol descriptor should be used to specify whether to perform key verification.
 */
typedef struct
{
  mcuxClRsa_KeyEntry_t pubExp;   ///< Public exponent.
} mcuxClRsa_KeyGeneration_ProtocolDescriptor_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_INTERNAL_TYPES_H_ */
