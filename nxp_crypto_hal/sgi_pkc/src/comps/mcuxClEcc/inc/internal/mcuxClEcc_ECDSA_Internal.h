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
 * @file  mcuxClEcc_ECDSA_Internal.h
 * @brief internal header for ECDSA
 */


#ifndef MCUXCLECC_ECDSA_INTERNAL_H_
#define MCUXCLECC_ECDSA_INTERNAL_H_


#include <mcuxClCore_Platform.h>
#include <mcuxClSignature_Types.h>
#include <mcuxClEcc_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>
#include <mcuxClMac.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Function implementing ECDSA signature generation
 *
 * @param[in]  pSession                  Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key (word-aligned)
 * @param[in]  mode                      Signature mode descriptor
 * @param[in]  pIn                       Pointer to buffer, which contains the message digest to be signed
 * @param[in]  inSize                    Size of the message digest to be signed
 * @param[out] pSignature                Pointer to buffer, which contains the result (signature)
 * @param[out] pSignatureSize            Will be set to the number of bytes of data that have been written to the pSignature buffer
 *
 * @return A code-flow protected error code (see @ref MCUXCLSIGNATURE_STATUS_)
 * @retval #MCUXCLSIGNATURE_STATUS_OK     if signature is generated successfully;
 *
 * @attention This function uses DRBG and PRNG. Caller needs to check if DRBG and PRNG are ready.
 */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ECDSA_GenerateSignature, mcuxClSignature_SignFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClEcc_ECDSA_GenerateSignature(
    mcuxClSession_Handle_t   pSession,
    mcuxClKey_Handle_t       key,
    mcuxClSignature_Mode_t   mode,
    mcuxCl_InputBuffer_t     pIn,
    uint32_t                inSize,
    mcuxCl_Buffer_t          pSignature,
    uint32_t * const        pSignatureSize
    );

/**
 * @brief Function implementing ECDSA signature verification.
 *
 * When the MCUXCLSESSION_SECURITYOPTIONS_SAVE_CRC_FOR_EXTERNAL_VERIFICATION_ENABLE security option is active,
 * the function saves the CRC32 of the R value of the computed signature in the session.
 * The CRC on user side can be computed with the function mcuxClCrc_computeCRC32 and with the function
 * mcuxClSession_getCrcForExternalVerification, the user can obtain the reference CRC for the verification.
 *
 * Data Integrity: Record(returnCode)
 * returnCode is not recorded in case of fault attack or error
 *
 * @param[in]  pSession                  Pointer to #mcuxClSession_Descriptor
 * @param[in]  key                       Key handle for the input key (word-aligned)
 * @param[in]  mode                      Signature mode descriptor
 * @param[in]  pIn                       Pointer to buffer, which contains the message digest
 * @param[in]  inSize                    Size of the message digest
 * @param[in]  pSignature                Pointer to buffer, which contains the signature
 * @param[out] signatureSize             Number of bytes of data in the pSignature buffer
 *
 *
 * @return A code-flow protected error code (see @ref MCUXCLSIGNATURE_STATUS_)
 * @retval #MCUXCLSIGNATURE_STATUS_OK          if ECDSA Signature is valid;
 * @retval #MCUXCLSIGNATURE_STATUS_NOT_OK      if ECDSA Signature is invalid;
 */

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ECDSA_VerifySignature, mcuxClSignature_VerifyFct_t )
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClEcc_ECDSA_VerifySignature(
    mcuxClSession_Handle_t   pSession,
    mcuxClKey_Handle_t       key,
    mcuxClSignature_Mode_t   mode,
    mcuxCl_InputBuffer_t     pIn,
    uint32_t                inSize,
    mcuxCl_InputBuffer_t     pSignature,
    uint32_t                signatureSize
    );

/**********************************************************/
/* Internal ECDSA types                                   */
/**********************************************************/

/**
 * Options for ECDSA signature generation descriptors
 */
#define MCUXCLECC_ECDSA_SIGNATURE_GENERATE_RANDOMIZED     0x5A5A5A5Au  ///< option for randomized ECDSA (according to FIPS 186-5)

/**
 *  ECDSA SignatureProtocol variant structure.
 */
struct mcuxClEcc_ECDSA_SignatureProtocolDescriptor
{
    uint32_t generateOption;                        ///< option of signature generation
    uint32_t verifyOption;                          ///< option of signature verification
    const mcuxClMac_ModeDescriptor_t *pHmacModeDesc; ///< HMAC mode
};

/**********************************************************/
/* Internal ECDSA descriptors                             */
/**********************************************************/

/* ECDSA protocol descriptor */
extern const mcuxClEcc_ECDSA_SignatureProtocolDescriptor_t mcuxClEcc_ECDSA_ProtocolDescriptor;

/**********************************************************/
/* Internal ECDSA functions                               */
/**********************************************************/

/**
 * Declaration of function to import and pad or truncate the ECDSA message digest
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_ECDSA_PrepareMessageDigest)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_ECDSA_PrepareMessageDigest(
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    uint32_t byteLenN
    );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_ECDSA_INTERNAL_H_ */
