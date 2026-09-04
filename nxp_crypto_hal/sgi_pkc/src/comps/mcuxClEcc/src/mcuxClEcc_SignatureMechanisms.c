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
 * @file  mcuxClEcc_SignatureMechanisms.c
 * @brief mcuxClEcc: implementation of ECC related signature mode descriptors
 */

#include <mcuxClSignature.h>
#include <internal/mcuxClSignature_Internal.h>
#include <mcuxClMac.h>

#include <mcuxClEcc.h>
#include <mcuxCsslAnalysis.h>

#ifdef MCUXCL_FEATURE_ECC_EDDSA
#include <internal/mcuxClEcc_EdDSA_Internal.h>
#endif /* MCUXCL_FEATURE_ECC_EDDSA */

#include <internal/mcuxClEcc_ECDSA_Internal.h>


const mcuxClSignature_ModeDescriptor_t mcuxClSignature_ModeDescriptor_ECDSA =
{
  .pSignFct = mcuxClEcc_ECDSA_GenerateSignature,
  .protection_token_sign = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_GenerateSignature),
  .pVerifyFct = mcuxClEcc_ECDSA_VerifySignature,
  .protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_VerifySignature),
  .pProtocolDescriptor = (const void *) &mcuxClEcc_ECDSA_ProtocolDescriptor

};


/* Signature mode structure for Ed25519 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClSignature_ModeDescriptor_t mcuxClSignature_ModeDescriptor_Ed25519 =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  .pSignFct = mcuxClEcc_EdDSA_GenerateSignature,
  .protection_token_sign = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateSignature),
  .pVerifyFct = mcuxClEcc_EdDSA_VerifySignature,
  .protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature),
  .pProtocolDescriptor = (const void *) &mcuxClEcc_EdDsa_Ed25519ProtocolDescriptor
};

