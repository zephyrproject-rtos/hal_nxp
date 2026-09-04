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

/** @file  mcuxClSignature_Internal.h
 *  @brief Internal header for Signature types
 */

#ifndef MCUXCLSIGNATURE_INTERNAL_H_
#define MCUXCLSIGNATURE_INTERNAL_H_

#include <mcuxClSignature_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession_Types.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Mode/Skeleton function types
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClSignature_SignFct_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) (*mcuxClSignature_SignFct_t) (
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClSignature_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pSignature,
  uint32_t * const pSignatureSize
));

/**
* Data Integrity: Record(returnCode)
*/
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClSignature_VerifyFct_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) (*mcuxClSignature_VerifyFct_t) (
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClSignature_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_InputBuffer_t pSignature,
  uint32_t signatureSize
));


/**
 * \brief Signature mode descriptor structure
 * \ingroup clSignatureModes
 *
 * This structure captures all the information that the Signature interfaces need
 * to know about a particular Signature mode.
 */
struct mcuxClSignature_ModeDescriptor
{
  mcuxClSignature_SignFct_t   pSignFct;
  uint32_t protection_token_sign;
  mcuxClSignature_VerifyFct_t pVerifyFct;
  uint32_t protection_token_verify;
  const void * pProtocolDescriptor;  // TODO TBD shall this be pAlgorithmDescriptor, to be more consistent with the naming in Cipher components?
};

/**
 * @brief Signature context structure
 *
 * This structure is used in the multi-part interfaces to store the
 * information about the current operation and the relevant internal state.
 * This is the common part of the context needed by signature modes.
 */
struct mcuxClSignature_Context
{
  const mcuxClSignature_ModeDescriptor_t * pMode;
};

#ifdef MCUXCL_FEATURE_SIGNATURE_SELFTEST
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClSignature_SelfTestFct_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) (*mcuxClSignature_SelfTestFct_t) (
  mcuxClSession_Handle_t session,
  mcuxClSignature_Mode_t mode
));

/**
 * \brief Signature selftest mode descriptor structure
 * \ingroup clSignatureModes
 *
 * This structure captures all the information that the Signature selftest interfaces need
 * to know about a particular Signature selftest mode.
 */
struct mcuxClSignature_TestDescriptor
{
  mcuxClSignature_SelfTestFct_t pSelfTestFct;
  uint32_t                     protection_token_selftest;
};
#endif /* MCUXCL_FEATURE_SIGNATURE_SELFTEST */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSIGNATURE_INTERNAL_H_ */
