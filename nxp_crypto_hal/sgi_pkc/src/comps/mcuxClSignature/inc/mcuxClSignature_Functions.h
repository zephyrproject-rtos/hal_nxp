/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023, 2025-2026 NXP                                       */
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

#ifndef MCUXCLSIGNATURE_FUNCTIONS_H_
#define MCUXCLSIGNATURE_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>

#include <mcuxClSession_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSignature_Types.h>

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mcuxClSignature_Functions mcuxClSignature_Functions
 * \brief Interfaces to perform Signature operations in one shot.
 * \ingroup mcuxClSignature
 * @{
 */

/**
 * \brief One-shot signing function
 * \api
 *
 * This function performs a signing operation in one shot. The algorithm to be
 * used will be determined based on the key and mode that are provided.
 *
 * For example, to perform an ECDSA signing operation over pre-hashed data
 * with a 256-bit private key, the following needs to be provided:
 *  - ECC256 private key
 *  - ECDSA mode, pre-hashed data
 *  - Input data, hash of the data to be signed
 *  - Output data buffer
 *
 * \param      session        Handle for the current CL session.
 * \param      key            Key to be used to sign the data (word-aligned).
 * \param      mode           Signature mode that should be used during the
 *                            signing operation.
 * \param[in]  pIn            Pointer to the input buffer that contains the
 *                            data that needs to be signed.
 * \param      inSize         Number of bytes of data in the \p pIn buffer.
 * \param[out] pSignature     Pointer to the output buffer where the generated
 *                            signature needs to be written.
 * \param[out] pSignatureSize Will be set to the number of bytes of data
 *                            that have been written to the \p pSignature
 *                            buffer.
 * \return status
 *
 * @attention When used with RSA modes, the function uses PRNG, which has to be initialized prior to calling the function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSignature_sign)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClSignature_sign(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClSignature_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pSignature,
  uint32_t * const pSignatureSize
); /* oneshot sign */

/**
 * \brief Record signature verification parameters for protection.
 *
 * Records signature mode, input data pIn and inSize parameters for additional protection.
 * This function must be called immediately before the mcuxClSignature_verify function
 * call when ECDSA mode is requested. Failure to do so will result
 * in a protection token mismatch during the signature verification.
 *
 * @note This function will use the first word of CPU WA (without allocating it)
 *       to store the calculated parameter protection value. This will then be used
 *       by the mcuxClSignature_verify function to validate parameters.
 *
 * \param      pSession      Handle for the current CL session.
 * \param      mode          Signature mode that should be used during the
 *                           verification operation.
 * \param[in]  pIn           Pointer to the input buffer that contains the
 *                           data that has been signed.
 * \param      inSize        Number of bytes of data in the \p pIn buffer.
 *
 * \return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSignature_verify_recordParam)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClSignature_verify_recordParam(
  mcuxClSession_Handle_t pSession,
  mcuxClSignature_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize
);

/**
 * \brief One-shot verification function
 * \api
 *
 * This function performs a signature verification operation in one shot. The
 * algorithm to be used will be determined based on the key and mode that are
 * provided.
 *
 * For example, to perform an ECDSA signature verification operation with
 * pre-hashed data and a 256-bit public key, the following needs to be provided:
 *  - ECC256 public key
 *  - ECDSA mode, pre-hashed data
 *  - Input data, hash of the data to be verified
 *  - Signature
 *
 * \param      session       Handle for the current CL session.
 * \param      key           Key to be used to verify the \p pSignature (word-aligned).
 * \param      mode          Signature mode that should be used during the
 *                           verification operation.
 * \param[in]  pIn           Pointer to the input buffer that contains the
 *                           data that has been signed.
 * \param      inSize        Number of bytes of data in the \p pIn buffer.
 * \param[in]  pSignature    Pointer to the buffer that contains the signature
 *                           that needs to be verified.
 * \param      signatureSize Number of bytes of data in the \p pSignature
 *                           buffer.
 */
 /** \note                   When performing ECDSA signature verification: mode, pIn and inSize parameters
 *                           require additional protection using mcuxClSignature_verify_recordParam().
 *                           This will initialize first word of CPU WA with integrity value required by
 *                           mcuxClSignature_verify() to validate parameters.
 */
 /**
 * \return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSignature_verify)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClSignature_verify(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClSignature_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_InputBuffer_t pSignature,
  uint32_t signatureSize
); /* oneshot verification */
/** @} */

#ifdef MCUXCL_FEATURE_SIGNATURE_SELFTEST
/**
 * \brief Signature selftest function
 * \api
 *
 * This function performs a signature selftest operation.
 * The algorithm to be used will be determined based on the mode and test types that are provided.
 *
 * For example, to perform an SM2 selftest operation with only verify, the following needs to be provided:
 *  - SM2 mode
 *  - mcuxClOsccaSm2_Test_VerifyOnly for test descriptor
 *
 * \param      session       Handle for the current CL session.
 * \param      mode          Signature mode that should be used during the
 *                           selftest operation.
 * \param      test          Signature selftest type that should be used during the selftest operation.
 * \return status
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSignature_selftest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClSignature_selftest(
  mcuxClSession_Handle_t session,
  mcuxClSignature_Mode_t mode,
  mcuxClSignature_Test_t test
); /* selftest */
#endif /* MCUXCL_FEATURE_SIGNATURE_SELFTEST */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSIGNATURE_FUNCTIONS_H_ */
