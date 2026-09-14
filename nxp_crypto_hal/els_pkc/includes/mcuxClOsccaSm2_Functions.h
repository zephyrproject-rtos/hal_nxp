/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * @file  mcuxClOsccaSm2_Functions.h
 * @brief Top level APIs of mcuxClOsccaSm2 component
 */


#ifndef MCUXCLOSCCASM2_FUNCTIONS_H_
#define MCUXCLOSCCASM2_FUNCTIONS_H_


#include <stdint.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession.h>
#include <mcuxClOsccaSm2_Types.h>
#include <mcuxClKey_Types.h>
#ifdef MCUXCL_FEATURE_SM2_CIPHER
#include <mcuxClCipher_Types.h>
#endif /* MCUXCL_FEATURE_SM2_CIPHER */
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup mcuxClOsccaSm2_Functions mcuxClOsccaSm2_Functions
 * @brief Defines all functions to perform OSCCA SM2 operations.
 * @ingroup mcuxClOsccaSm2
 * @{
 */
/**********************************************************/
/* Public APIs of mcuxClOsccaSm2                           */
/**********************************************************/
#ifdef MCUXCL_FEATURE_SM2_INTERNAL

#ifdef MCUXCL_FEATURE_SM2_KEYGEN

/**
 * @brief sm2 key pair generation.
 * @api
 *
 * This function generates an SM2 key pair for usage.
 *
 * @param      session              Handle for the current CL session.
 * @param[in]  generation           Key generation algorithm specifier.
 * @param[out] privKey              Key handle for the generated private key.
 * @param[out] pubKey               Key handle for the generated public key.
 *
 * @return status
 * @retval #MCUX_CL_KEY_STATUS_OK                   if private key and public key are generated successfully;
 * @retval #MCUX_CL_KEY_STATUS_FAILURE              if failure during execution;
 * @retval #MCUX_CL_KEY_STATUS_FAULT_ATTACK         if fault attack (unexpected behavior) is detected.
 * @attention This function uses TRNG and PRNG. Caller needs to check if TRNG and PRNG are ready.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClOsccaSm2_GenerateKeyPair(
    mcuxClSession_Handle_t session,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey
);

#endif /* MCUXCL_FEATURE_SM2_KEYGEN */

#ifdef MCUXCL_FEATURE_SM2_CIPHER

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Cipher_SkeletonSM2, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClOsccaSm2_Cipher_SkeletonSM2(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t pKey,
  mcuxClCipher_Mode_t pMode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  uint32_t steps //!< steps is a bitmask with one bit reserved for each of the steps below
);

#endif /* MCUXCL_FEATURE_SM2_CIPHER */

#ifdef MCUXCL_FEATURE_SM2_KEYAGREEMENT
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_key_agreement, mcuxClKey_AgreementFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClOsccaSm2_key_agreement(
    mcuxClSession_Handle_t session,
    mcuxClKey_Agreement_t agreement,
    mcuxClKey_Handle_t key,
    mcuxClKey_Handle_t otherKey,
    mcuxClKey_Agreement_AdditionalInput_t additionalInputs[],
    uint32_t numberOfInputs,
    uint8_t * pOut,
    uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_KeyAgreement_SelfTest, mcuxClKey_Agreement_SelfTestFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClOsccaSm2_KeyAgreement_SelfTest(
    mcuxClSession_Handle_t session,
    mcuxClKey_Agreement_t agreement
);
#endif /* MCUXCL_FEATURE_SM2_KEYAGREEMENT */
#endif /* MCUXCL_FEATURE_SM2_INTERNAL */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Signature_PreHash)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Signature_PreHash(
    mcuxClSession_Handle_t             session,
    mcuxClKey_Handle_t                 key,
    mcuxCl_InputBuffer_t               pIdentifier,
    uint16_t                          identifierSize,
    mcuxCl_Buffer_t                    pPrehash,
    uint32_t * const                  prehashSize
);

/**
 * @}
 */ /* mcuxClOsccaSm2_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASM2_FUNCTIONS_H_ */
