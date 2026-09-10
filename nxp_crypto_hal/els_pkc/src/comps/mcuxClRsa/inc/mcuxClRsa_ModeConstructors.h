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

#ifndef MCUXCLRSA_MODECONSTRUCTORS_H_
#define MCUXCLRSA_MODECONSTRUCTORS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>


#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#include <mcuxClCipher_Types.h>
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

#include <mcuxClKey_Types.h>
#include <mcuxClHash_Types.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Descriptors of mcuxClRsa APIs                           */
/**********************************************************/
/**
 * @defgroup mcuxClRsa_Descriptors mcuxClRsa_Descriptors
 * @brief Defines descriptors of @ref mcuxClRsa
 * @ingroup mcuxClRsa
 * @{
 */

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
/**
 * \defgroup clRsaCipherModes Cipher RSA mode definitions
 * \brief Modes used by the Cipher operations with RSA.
 * \ingroup clRsaCipherModes
 * @{
 */

#ifdef MCUXCL_FEATURE_RSA_RSAES_OAEP
/**
 * \brief Mode constructor for RSAES-OAEP-ENCRYPT operation
 *        Before calling this function, sufficient space should be allocated for the cipher mode and RSA-specific content,
 *        using the macro MCUXCLRSA_CIPHER_MODE_SIZE
 *
 * \param pCipherMode         Pointer to a mode descriptor that will be updated by this function.
 * \param hashAlgorithm       Hash algorithm that should be used.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Encrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Encrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode,
  mcuxClHash_Algo_t hashAlgorithm
);

/**
 * \brief Mode constructor for RSAES-OAEP-DECRYPT operation
 *        Before calling this function, sufficient space should be allocated for the cipher mode and RSA-specific content,
 *        using the macro MCUXCLRSA_CIPHER_MODE_SIZE
 *
 * \param pCipherMode         Pointer to a mode descriptor that will be updated by this function.
 * \param hashAlgorithm       Hash algorithm that should be used.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Decrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_OAEP_Decrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode,
  mcuxClHash_Algo_t hashAlgorithm
);

#endif /* MCUXCL_FEATURE_RSA_RSAES_OAEP */

#ifdef MCUXCL_FEATURE_RSA_RSAES_PKCS1v15
/**
 * \brief Mode constructor for RSAES-PKCS1-V1_5-ENCRYPT operation
 *        Before calling this function, sufficient space should be allocated for the cipher mode and RSA-specific content,
 *        using the macro MCUXCLRSA_CIPHER_MODE_SIZE
 *
 * \param pCipherMode         Pointer to a mode descriptor that will be updated by this function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Encrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Encrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode
);

/**
 * \brief Mode constructor for RSAES-PKCS1-V1_5-DECRYPT operation
 *        Before calling this function, sufficient space should be allocated for the cipher mode and RSA-specific content,
 *        using the macro MCUXCLRSA_CIPHER_MODE_SIZE
 *
 * \param pCipherMode         Pointer to a mode descriptor that will be updated by this function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Decrypt)
void mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5_Decrypt(
  mcuxClCipher_ModeDescriptor_t * pCipherMode
);

#endif /* MCUXCL_FEATURE_RSA_RSAES_PKCS1v15 */

/** @} */
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

/** @} */

/**
 * \brief Mode constructor for RSA public key type
 *
 * \param [out] pKeyType         Pointer to a key type descriptor that will be initialized.
 * \param [in]  keySize          The key size for the key type in bytes.
 *
 * @return A code-flow protected error code (see @ref MCUXCLRSA_STATUS_)
 * @retval #MCUXCLRSA_STATUS_OK            mode descriptor has been initialized successfully
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT invalid key size
 * @retval #MCUXCLRSA_STATUS_FAULT_ATTACK  fault attack (unexpected behavior) is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_Public_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_Public_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
);
/** @} */

/**
 * \brief Mode constructor for RSA private plain key type
 *
 * \param [out] pKeyType         Pointer to a key type descriptor that will be initialized.
 * \param [in]  keySize          The key size for the key type in bytes.
 *
 * @return A code-flow protected error code (see @ref MCUXCLRSA_STATUS_)
 * @retval #MCUXCLRSA_STATUS_OK            mode descriptor has been initialized successfully
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT invalid key size
 * @retval #MCUXCLRSA_STATUS_FAULT_ATTACK  fault attack (unexpected behavior) is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_PrivatePlain_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_PrivatePlain_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
);
/** @} */

/**
 * \brief Mode constructor for RSA private CRT key type
 *
 * \param [out] pKeyType         Pointer to a key type descriptor that will be initialized.
 * \param [in]  keySize          The key size for the key type in bytes.
 *
 * @return A code-flow protected error code (see @ref MCUXCLRSA_STATUS_)
 * @retval #MCUXCLRSA_STATUS_OK            mode descriptor has been initialized successfully
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT invalid key size
 * @retval #MCUXCLRSA_STATUS_FAULT_ATTACK  fault attack (unexpected behavior) is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_PrivateCRT_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_PrivateCRT_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
);
/** @} */

/**
 * \brief Mode constructor for RSA private CRT_DFA key type
 *
 * \param [out] pKeyType         Pointer to a key type descriptor that will be initialized.
 * \param [in]  keySize          The key size for the key type in bytes.
 *
 * @return A code-flow protected error code (see @ref MCUXCLRSA_STATUS_)
 * @retval #MCUXCLRSA_STATUS_OK            mode descriptor has been initialized successfully
 * @retval #MCUXCLRSA_STATUS_INVALID_INPUT invalid key size
 * @retval #MCUXCLRSA_STATUS_FAULT_ATTACK  fault attack (unexpected behavior) is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_PrivateCRT_DFA_KeyType_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_PrivateCRT_DFA_KeyType_ModeConstructor(
  mcuxClKey_TypeDescriptor_t * pKeyType,
  mcuxClKey_Size_t keySize
);
/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_MODECONSTRUCTORS_H_ */
