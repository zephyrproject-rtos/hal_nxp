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
 * @file  mcuxClKey_Functions.h
 * @brief Top-level API of the mcuxClKey component. It is capable to load and flush
 *        keys into memory locations or coprocessors.
 */

#ifndef MCUXCLKEY_FUNCTIONS_H_
#define MCUXCLKEY_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession.h>
#include <mcuxClSession_Types.h>

#include <mcuxClKey_Types.h>
#ifdef MCUXCL_FEATURE_KEY_DERIVATION
#include <mcuxClMac_Types.h>
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @defgroup mcuxClKey_Functions mcuxClKey_Functions
 * @brief Defines all functions of @ref mcuxClKey
 * @ingroup mcuxClKey
 * @{
 */

/**
 * @brief Initializes a key handle.
 *
 * Initializes a key handle with default encoding values.
 *
 * @param       session          Session handle to provide session dependent information
 * @param       key              Key handle that will be initialized (word-aligned)
 * @param       type             Define which key type shall be initialized
 * @param[in]   pKeyData         Pointer to the source data of the key. This can be a pointer to a plain key, any
 *                               supported encoded key, a share or a key blob. The encoding mechanism defines the
 *                               purpose of this parameter.
 * @param       keyDataLength    Length of the provided key data @p pKeyData
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @endif
 *
 * @retval #MCUXCLKEY_STATUS_FAILURE  Key initialization failed
 * @retval #MCUXCLKEY_STATUS_OK       on successful operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_init(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    mcuxClKey_Type_t type,
    const uint8_t * pKeyData,
    uint32_t keyDataLength
);


/**
 * @brief Establishes a key pair link between a private and public key handle.
 *
 * @param   session     Session handle to provide session dependent information
 * @param   privKey     Key handle of private key (word-aligned)
 * @param   pubKey      Key handle of public key (word-aligned)
 *
 * @retval void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_linkKeyPair)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_linkKeyPair(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey
);

/**
 * @brief Configures the encoding mechanism for the given key handle.
 *
 * This function shall be used when the key material of a key handle is already
 * encoded. @ref mcuxClKey_init must be called to initialize the key handle first.
 *
 * @param       session         Session handle to provide session dependent information
 * @param       key             Key handle that will be configured (word-aligned)
 * @param       encoding        Define the encoding and flush mechanism that shall be used with this @p key
 * @param[in]   pAuxData        Auxiliary data needed for the given key @p encoding.
 * @param       auxDataLength   Number of bytes available in the @p pAuxData buffer.
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @endif
 *
 * @retval #MCUXCLKEY_STATUS_ERROR  on unsuccessful operation
 * @retval #MCUXCLKEY_STATUS_OK     on successful operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_setEncoding)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_setEncoding(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    mcuxClKey_Encoding_t encoding,
    const uint8_t * pAuxData,
    uint32_t auxDataLength
);

/**
 * @brief Load key into destination key slot of a coprocessor
 *
 * @param  session        Session handle to provide session dependent information
 * @param  key            Key handle that provides of the key to be loaded (word-aligned)
 * @param  loadOptions    Provide the destination key slot in the hardware and associated options.
 *                        The key slot must be available in the coprocessor that fits the key type.
 *                          The slot shall be a provided constant in @ref MCUXCLKEY_LOADOPTION_SLOT_.
 *                          Additional options in @ref  MCUXCLKEY_LOADOPTION_ can be provided.
 */
/** To delete a key again from the key slot, call @ref mcuxClKey_flush.
 */
/** @attention In case the key is already loaded to a key slot that differs from the @p slot,
 * the previous slot will be flushed before loading the key to the given new slot.
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @endif
 *
 * @retval #MCUXCLKEY_STATUS_OK             on successful operation
 * @retval #MCUXCLKEY_STATUS_INVALID_INPUT  if the given loadOptions do not fit the key type
 * @retval #MCUXCLKEY_STATUS_FAULT_ATTACK   if a fault attack was detected
 */
/**
 * @retval #MCUXCLSGI_STATUS_UNWRAP_ERROR    Error during RFC3394 Key Unwrap detected. An SGI reset or FULL_FLUSH needs to be performed.
 *
 * @attention If the given key handle contains an RFC3394 wrapped key, this operation will unwrap the key material.
 * This can potentially lead to a #MCUXCLSGI_STATUS_UNWRAP_ERROR.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_loadCopro)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_loadCopro(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    uint32_t loadOptions
);

/**
 * @brief Flush key from destination which can be a key slot of coprocessor or memory buffer
 *
 * @param   session    Session handle to provide session dependent information
 * @param   key        Key handle that provides information to flush the key from its location (word-aligned)
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @endif
 *
 * @retval #MCUXCLKEY_STATUS_OK             on successful operation
 * @retval #MCUXCLKEY_STATUS_FAULT_ATTACK   if a fault is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_flush)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_flush(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key
);

#ifdef MCUXCL_FEATURE_KEY_DERIVATION

/**
 * @brief Execute a key derivation function (KDF) to derive a cryptographic key from several inputs,
 * or a public key from a private key for asymmetric cryptographic algorithms.
 *
 * @param      session                Handle for the current CL session.
 * @param      derivationMode         Structure which contains information on which algorithm(s) to be used (Hash, HMac-hash, CMac-mode, RSA, ECC)
 * @param      derivationKey          Key handle to a key derivation key (word-aligned)
 * @param[in]  inputs[]               Array of multiple inputs to the key derivation function, such as IV, label, context, salt, seed
 * @param      numberOfInputs         Number of different inputs given in inputs
 * @param      derivedKey             Key handle for the derived output key (word-aligned)
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLKEY_STATUS_, see individual documentation for more information
 * @endif
 *
 * @retval #MCUXCLKEY_STATUS_ERROR  on unsuccessful operation
 * @retval #MCUXCLKEY_STATUS_OK     on successful operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_derivation)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivation(
    mcuxClSession_Handle_t session,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[],
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey
);
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */

/**
 * @brief Key-pair generation function.
 * @api
 *
 * This function can be used to perform a key-pair generation operation.
 * The generated keys are linked with each other using mcuxClKey_linkKeyPair.
 *
 * Note: the key handles @p privKey and @p pubKey must already be initialized
 * and contain a proper key type (matching to the @p generation algorithm),
 * encoding mechanism and enough space for key data buffers.
 *
 * @param[in]     session      Handle for the current CL session.
 * @param[in]     generation   Key generation algorithm that determines the key
 *                             data stored in @p privKey and @p pubKey.
 * @param         privKey      Key handle for the private key (word-aligned).
 * @param         pubKey       Key handle for the public key (word-aligned).
 *
 * @return Status of the mcuxClKey_generate_keypair operation.
 * @retval #MCUXCLKEY_STATUS_OK                 Key generation operation executed successfully.
 * @retval #MCUXCLKEY_STATUS_INVALID_INPUT      The input parameters are not valid.
 * @retval #MCUXCLKEY_STATUS_ERROR              An error occurred during the execution.
 * @retval #MCUXCLKEY_STATUS_FAILURE            The key generation failed.
 *                                             RSA-specific: this occurs in case the key generation exceeds the limit of iterations to generate a prime.
 * @retval #MCUXCLKEY_STATUS_FAULT_ATTACK       An error occurred during the execution.
 *
 * @attention This function uses DRBG and PRNG which have to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_generate_keypair)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_generate_keypair(
    mcuxClSession_Handle_t session,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey
); /* generate a fresh new key (pair) */

/**
 * @brief Key agreement function.
 * @api
 *
 * This function can be used to perform a Diffie-Hellman-like key agreement operation.
 *
 * @param      session            Handle for the current CL session.
 * @param      agreement          Key agreement algorithm that determines the value of
 *                                @p pOut.
 * @param      key                First key to be used for the agreement operation (word-aligned).
 * @param      otherKey           Other key to be used for the agreement operation (word-aligned).
 * @param      additionalInputs   Additional input needed for the agreement operation.
 * @param      numberOfInputs     Number of the additional inputs needed for the agreement operation.
 * @param[out] pOut               Pointer to a memory location to store the agreed key.
 * @param[out] pOutLength         Will be incremented by the number of bytes written to @p pOut.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_agreement)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_agreement(
    mcuxClSession_Handle_t session,
    mcuxClKey_Agreement_t agreement,
    mcuxClKey_Handle_t key,
    mcuxClKey_Handle_t otherKey,
    mcuxClKey_Agreement_AdditionalInput_t additionalInputs[],
    uint32_t numberOfInputs,
    uint8_t * pOut,
    uint32_t * const pOutLength
); /* determine a shared key on based on public and private inputs */

#ifdef MCUXCL_FEATURE_KEY_SELFTEST
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_agreement_selftest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_agreement_selftest(
    mcuxClSession_Handle_t session,
    mcuxClKey_Agreement_t agreement,
    mcuxClKey_Test_t test
);
#endif /* MCUXCL_FEATURE_KEY_SELFTEST */

/**
 * @brief Key descriptor initialization function including applying a
 * encoding mechanism.
 * @api
 *
 * This function performs the initialization of a Key descriptor. In addition
 * the given @p encoding mechanism gets applied to the given raw key data.
 *
 * @param      session                 Handle for the current CL session.
 * @param      encoding                Encoding mechanism to be applied to the given
 *                                     @p pPlainKeyData.
 * @param      encodedKey              Key to be initialized and encoded (word-aligned).
 * @param      type                    Type of the key.
 * @param[in]  pPlainKeyData           Plain raw key data.
 * @param      plainKeyDataLength      Number of bytes available in the @p pPlainKeyData.
 * @param[in]  pAuxData                Auxiliary data needed for the given key @p encoding.
 * @param      auxDataLength           Number of bytes available in the @p pAuxData buffer.
 * @param[out] pEncodedKeyData         Encoded raw key data (after applying @p encoding to
 *                                     the @p pPlainKeyData)
 * @param[out] pEncodedKeyDataLength   Incremented with the number of bytes
 *                                     written at @p pEncodedKeyData.
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_encode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_encode(
    mcuxClSession_Handle_t session,
    mcuxClKey_Encoding_t encoding,
    mcuxClKey_Handle_t encodedKey,
    mcuxClKey_Type_t type,
    const uint8_t * pPlainKeyData,
    uint32_t plainKeyDataLength,
    const uint8_t * pAuxData,
    uint32_t auxDataLength,
    uint8_t * pEncodedKeyData,
    uint32_t * const pEncodedKeyDataLength
);

/**
 * @brief Key recoding (re-encoding) function to apply a new encoding to key material.
 * @api
 *
 * This function performs the initialization of the key descriptor @p recodedKey.
 * In addition, it decodes the key material of the given @p encodedKey and recodes
 * (re-encoded) the plain material with the given @p encoding to finalize the init
 * of the @p recodedKey.
 *
 * In-place recoding is not supported.
 *
 * @param      session                 Handle for the current CL session.
 * @param[in]  encodedKey              Input key associated with the material to be recoded.
 *                                     This key object is used as const input (word-aligned).
 * @param      encoding                Encoding mechanism to be applied to the plain key
 *                                     material of the given @p encodedKey.
 * @param      recodedKey              Output key handle containing the recoded key. Must point to an
 *                                     uninitialized key handle, in-place recoding is not supported (word-aligned).
 * @param[in]  pAuxData                Auxiliary data needed for the given key @p encoding.
 * @param      auxDataLength           Number of bytes available in the @p pAuxData buffer.
 * @param[out] pEncodedKeyData         Recoded key data (after applying @p encoding to the
 *                                     decoded key data associated with @p encodedKey).
 * @param[out] pEncodedKeyDataLength   Incremented with the number of bytes written to @p pEncodedKeyData.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_recode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_recode(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t encodedKey,
    mcuxClKey_Encoding_t encoding,
    mcuxClKey_Handle_t recodedKey,
    const uint8_t * pAuxData,
    uint32_t auxDataLength,
    uint8_t * pEncodedKeyData,
    uint32_t * const pEncodedKeyDataLength
);

/**
 * @brief Key validation function
 * @api
 *
 * This function validates a key.
 *
 * @param[in]    session       Handle for the current CL session.
 * @param[in]    validation    Key validation type.
 * @param[in]    key           Key handle for the key to be validated (word-aligned).
 *
 * @retval #MCUXCLKEY_STATUS_VALIDATION_PASSED      Key validation successful
 * @retval #MCUXCLKEY_STATUS_VALIDATION_FAILED      Key validation failed
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_validate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_validate(
    mcuxClSession_Handle_t session,
    mcuxClKey_Validation_t validation,
    mcuxClKey_Handle_t key
);



/**
 * @}
 */ /* mcuxClKey_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLKEY_FUNCTIONS_H_ */
