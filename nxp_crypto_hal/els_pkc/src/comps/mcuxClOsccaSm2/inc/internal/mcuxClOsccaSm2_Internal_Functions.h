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

/**
 * @file  mcuxClOsccaSm2_Internal_Functions.h
 * @brief Internal APIs of mcuxClOsccaSm2 component
 */


#ifndef MCUXCLOSCCASM2_INTERNAL_FUNCTIONS_H_
#define MCUXCLOSCCASM2_INTERNAL_FUNCTIONS_H_


#include <stdint.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <mcuxClOsccaSm2_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
#include <mcuxClSignature_Types.h>
#endif
#include <internal/mcuxClOsccaSm2_Internal_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**********************************************************/
/* Internal APIs of mcuxClOsccaSm2                         */
/**********************************************************/
#ifdef MCUXCL_FEATURE_SM2_INTERNAL
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Signature_Internal_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Signature_Internal_Init(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint16_t phase
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Signature_Internal_Finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Signature_Internal_Finish(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint16_t phase,
  mcuxCl_InputBuffer_t pIn,
  uint8_t * const pPrivateKeyInverse,
  mcuxCl_Buffer_t pSignature,
  uint32_t * const pSignatureSize
);

/**
 * @brief This function implements the OSCCA SM2 signature generation.
 *
 * @param[in]  session                   Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key
 * @param[in]  mode                      Signature mode descriptor
 * @param[in]  pIn                       Pointer to buffer, which contains the input to the sign operation
 * @param[in]  inSize                    input date length, no used
 * @param[out] pSignature                Pointer to memory area in which signature R and S will be exported if signature is generated successfully.
 *                                         - They will be stored as Big-endian octet strings of the exact length curveParam.byteLenN.
                                           - The string of R is followed by the string of S.
 * @param[out]  pSignatureSize           Pointer to output date length, no used
 * @returns Status of the operation
 * @retval #MCUXCLOSCCASM2_STATUS_OK                   if signature is generated successfully;
 * @retval #MCUXCLOSCCASM2_STATUS_INVALID_PARAMS       if parameters are invalid;
 * @retval #MCUXCLOSCCASM2_STATUS_RNG_ERROR            if random number (DRBG / PRNG) error (unexpected behavior);
 * @retval #MCUXCLOSCCASM2_STATUS_FAULT_ATTACK         if fault attack (unexpected behavior) is detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Sign, mcuxClSignature_SignFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Sign(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    mcuxClSignature_Mode_t mode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_Buffer_t pSignature,
    uint32_t * const pSignatureSize
);

/**
 * @brief This function implements the OSCCA SM2 signature verification.
 *
 * @param[in]  session                   Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key
 * @param[in]  mode                      Signature mode descriptor
 * @param[in]  pIn                       Pointer to buffer, which contains the input to the verify operation
 * @param[in]  inSize                    input date length, no used
 * @param[in]  pSignature                Pointer to buffer, which contains the signature
 * @param[in]  pSignatureSize            pointer to output date length, no used
 * @returns Status of the operation
 *
 * @retval #MCUXCLOSCCASM2_STATUS_OK                     if SM2 Signature is valid;
 * @retval #MCUXCLOSCCASM2_STATUS_INVALID_SIGNATURE      if SM2 Signature is invalid;
 * @retval #MCUXCLOSCCASM2_STATUS_INVALID_PARAMS         if parameters are invalid;
 * @retval #MCUXCLOSCCASM2_STATUS_FAULT_ATTACK           if fault attack (unexpected behavior) is detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Verify, mcuxClSignature_VerifyFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Verify(
    mcuxClSession_Handle_t             session,
    mcuxClKey_Handle_t                 key,
    mcuxClSignature_Mode_t             mode,
    mcuxCl_InputBuffer_t               pIn,
    uint32_t                          inSize,
    mcuxCl_InputBuffer_t               pSignature,
    uint32_t                          signatureSize
);


#ifdef MCUXCL_FEATURE_SIGNATURE_SELFTEST
/**
 * @brief This function tests the OSCCA SM2 verification API.
 *
 * @param[in]  session                   Pointer to #mcuxClSession_Descriptor
 * @param[in]  mode                      Signature mode descriptor
 *
 * @returns Status of the operation
 *
 * @retval #MCUXCLSIGNATURE_STATUS_OK                     if SM2 Signature selftest is valid;
 * @retval #MCUXCLSIGNATURE_STATUS_FAILURE                if fault attack (unexpected behavior) is detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Signature_OnlyVerify_SelfTest, mcuxClSignature_SelfTestFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClOsccaSm2_Signature_OnlyVerify_SelfTest(
    mcuxClSession_Handle_t session,
    mcuxClSignature_Mode_t mode
);

/**
 * @brief This function tests the OSCCA SM2 signature and verification APIs.
 *
 * @param[in]  session                   Pointer to #mcuxClSession_Descriptor
 * @param[in]  mode                      Signature mode descriptor
 *
 * @returns Status of the operation
 *
 * @retval #MCUXCLSIGNATURE_STATUS_OK                     if SM2 Signature selftest is valid;
 * @retval #MCUXCLSIGNATURE_STATUS_FAILURE                if fault attack (unexpected behavior) is detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Signature_SignVerify_SelfTest, mcuxClSignature_SelfTestFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClOsccaSm2_Signature_SignVerify_SelfTest(
    mcuxClSession_Handle_t session,
    mcuxClSignature_Mode_t mode
);
#endif /* MCUXCL_FEATURE_SIGNATURE_SELFTEST */
#endif /* MCUXCL_FEATURE_SM2_SIGNATURE */
#endif /* MCUXCL_FEATURE_SM2_INTERNAL */

/**
 * @brief This function computes (1+d)^-1 for private key d.
 *
 * @returns Status of the operation
 *
 * @retval ::MCUXCLOSCCASM2_STATUS_INVERT_PRIVATE_KEY_OK   Inverting private key is successful
 * @retval ::MCUXCLOSCCASM2_STATUS_FAULT_ATTACK            Fault attack is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_InvertPrivateKey)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_InvertPrivateKey(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_InvertPrivateKey_Param_t *pParams    /**< @brief Pointer to parameter struct */
);

/**
 * @brief This function computes the Za pre-hash value (see SM2 specification).
 *
 * @returns Status of the operation
 *
 * @retval ::MCUXCLOSCCASM2_STATUS_COMPUTE_PREHASH_OK      Computing pre-hash is successful
 * @retval ::MCUXCLOSCCASM2_STATUS_FAULT_ATTACK            Fault attack is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_ComputePrehash)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_ComputePrehash(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_ComputePrehash_Param_t *pParams    /**< @brief Pointer to parameter struct */
);


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Encrypt_Internal_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Encrypt_Internal_Init(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Encrypt_Param_t *pParams
);


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Encrypt_Internal_Final)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Encrypt_Internal_Final(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Encrypt_Param_t *pParams
);


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Decrypt_Internal_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Decrypt_Internal_Init(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Decrypt_Param_t *pParams
);


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Decrypt_Internal_Final)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Decrypt_Internal_Final(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Decrypt_Param_t *pParams
);
/**
 * @brief This function implements the OSCCA SM2 encryption algorithm.
 *
 * @returns Status of the operation
 *
 * @retval ::MCUXCLOSCCASM2_STATUS_ENCRYPT_OK               Encryption is successful
 * @retval ::MCUXCLOSCCASM2_STATUS_ENCRYPT_INVALID_PARAMS   Input parameters are invalid
 * @retval ::MCUXCLOSCCASM2_STATUS_FAULT_ATTACK             Fault attack is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Encrypt, mcuxClOsccaSm2_EncEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Encrypt(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Encrypt_Param_t *pParams    /**< @brief Pointer to parameter struct */
);

/**
 * @brief This function implements the OSCCA SM2 decryption algorithm.
 *
 * @returns Status of the operation
 *
 * @retval ::MCUXCLOSCCASM2_STATUS_DECRYPT_OK               Decryption is successful
 * @retval ::MCUXCLOSCCASM2_STATUS_DECRYPT_NOK              Decryption is failed due to bad inputs
 * @retval ::MCUXCLOSCCASM2_STATUS_FAULT_ATTACK             Fault attack is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Decrypt, mcuxClOsccaSm2_DecEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Decrypt(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Decrypt_Param_t *pParams    /**< @brief Pointer to parameter struct */
);

/**
 * @brief This function implements part of OSCCA SM2 key exchange algorithm.
 *        Complete functionality of SM2 key exchanged shall be realized by
 *        using this function, mcuxClOsccaSm2_ComputePrehash for hashing identification
 *        and mcuxClOsccaSm2_GenerateKeyPair for ephemeral key generation.
 *        Note that, if key confirmation is used, it is only computed here and shall
 *        be verified or sent to other party outside of this function.
 *
 * @returns Status of the operation
 *
 * @retval ::MCUXCLOSCCASM2_STATUS_KEYEXCHANGE_OK              Operation is successful, i.e., common secret is correctly computed
 * @retval ::MCUXCLOSCCASM2_STATUS_KEYEXCHANGE_NOK             Operation is failed
 * @retval ::MCUXCLOSCCASM2_STATUS_KEYEXCHANGE_INVALID_PARAMS  Input parameters are invalid
 * @retval ::MCUXCLOSCCASM2_STATUS_FAULT_ATTACK                Fault attack is detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_KeyExchange)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_KeyExchange(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_KeyExchange_Param_t *pParams
);
/**
 * @}
 */ /* mcuxClOsccaSm2_Internal_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASM2_INTERNAL_FUNCTIONS_H_ */
