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
 *
 * @file:    mcuxClOsccaSm2_ModeConstants.h
 * @brief:   Platform related mode definitions for the OSCCA SM2 component
 *
 */

#ifndef MCUXCLOSCCASM2_MODECONSTANTS_H_
#define MCUXCLOSCCASM2_MODECONSTANTS_H_

#include <mcuxCsslAnalysis.h>
#include <mcuxClOsccaSm2_Types.h>
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
#include <mcuxClSignature_Types.h>
#endif /* MCUXCL_FEATURE_SM2_SIGNATURE */
#ifdef MCUXCL_FEATURE_KEY_GENERATION
#include <mcuxClKey_Types.h>
#endif /* MCUXCL_FEATURE_KEY_GENERATION */
#ifdef MCUXCL_FEATURE_SM2_CIPHER
#include <mcuxClCipher_Types.h>
#endif /* MCUXCL_FEATURE_SM2_CIPHER */

#ifdef __cplusplus
extern "C"
{
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()

#ifdef MCUXCL_FEATURE_SM2_INTERNAL

/* The parameters for SM2 256-bit standard elliptic curves in the prime field */
extern const mcuxClOsccaSm2_DomainParam_t mcuxClOsccaSm2_DomainParams_SM2P256_Std;

/* The parameters for SM2 256-bit extend elliptic curves in the prime field */
extern const mcuxClOsccaSm2_DomainParam_t mcuxClOsccaSm2_DomainParams_SM2P256_Ext;

#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
/**
 * @brief SM2 Signature Mode descriptor
 */
extern const mcuxClSignature_ModeDescriptor_t mcuxClSignature_ModeDescriptor_SM2;

/**
 * @brief SM2 Signature Mode
 */
static mcuxClSignature_Mode_t mcuxClSignature_Mode_SM2 =
  &mcuxClSignature_ModeDescriptor_SM2;


#ifdef MCUXCL_FEATURE_SIGNATURE_SELFTEST
/**
 * @brief SM2 Signature selftest Mode descriptor which only execute SM2 verify
 */
extern const mcuxClSignature_TestDescriptor_t mcuxClSignature_TestDescriptor_SM2_VerifyOnly;

/**
 * @brief SM2 Signature selftest Mode for only SM2 verify
 */
static mcuxClSignature_Test_t mcuxClSignature_Test_SM2_VerifyOnly =
  &mcuxClSignature_TestDescriptor_SM2_VerifyOnly;

/**
 * @brief SM2 Signature selftest Mode descriptor which execute SM2 sign/verify
 */
extern const mcuxClSignature_TestDescriptor_t mcuxClSignature_TestDescriptor_SM2_SignVerify;

/**
 * @brief SM2 Signature selftest Mode for SM2 sign/verify
 */
static mcuxClSignature_Test_t mcuxClSignature_Test_SM2_SignVerify =
  &mcuxClSignature_TestDescriptor_SM2_SignVerify;

#endif /* MCUXCL_FEATURE_SIGNATURE_SELFTEST */

#endif /* MCUXCL_FEATURE_SM2_SIGNATURE */

#ifdef MCUXCL_FEATURE_KEY_GENERATION
#ifdef MCUXCL_FEATURE_SM2_KEYGEN
/**
 * @brief SM2 Key generation algorithm descriptor
 */
extern const mcuxClKey_GenerationDescriptor_t mcuxClKey_GenerationDescriptor_SM2;

/**
 * @brief SM2 Key generation algorithm
 */
static mcuxClKey_Generation_t mcuxClKey_Generation_SM2 =
  &mcuxClKey_GenerationDescriptor_SM2;
#endif /* MCUXCL_FEATURE_SM2_KEYGEN */
#endif /* MCUXCL_FEATURE_KEY_GENERATION */

#ifdef MCUXCL_FEATURE_SM2_CIPHER

extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM2_ENC;
static mcuxClCipher_Mode_t mcuxClCipher_Mode_SM2_ENC =
  &mcuxClOscca_Cipher_ModeDesc_SM2_ENC;

extern const mcuxClCipher_ModeDescriptor_t mcuxClOscca_Cipher_ModeDesc_SM2_DEC;
static mcuxClCipher_Mode_t mcuxClCipher_Mode_SM2_DEC =
  &mcuxClOscca_Cipher_ModeDesc_SM2_DEC;


#endif /* MCUXCL_FEATURE_SM2_CIPHER */

#ifdef MCUXCL_FEATURE_SM2_KEYAGREEMENT
extern const mcuxClKey_AgreementDescriptor_t mcuxClOsccaSm2_AgreementDesc_Initiator;
static mcuxClKey_Agreement_t mcuxClOsccaSm2_Agreement_Initiator =
  &mcuxClOsccaSm2_AgreementDesc_Initiator;

extern const mcuxClKey_AgreementDescriptor_t mcuxClOsccaSm2_AgreementDesc_Responder;
static mcuxClKey_Agreement_t mcuxClOsccaSm2_Agreement_Responder =
  &mcuxClOsccaSm2_AgreementDesc_Responder;

extern const mcuxClKey_TestDescriptor_t mcuxClKey_TestDescriptor_SM2_Agreement;
static mcuxClKey_Test_t mcuxClKey_Test_SM2_Agreement =
  &mcuxClKey_TestDescriptor_SM2_Agreement;
#endif /* MCUXCL_FEATURE_SM2_KEYAGREEMENT */
#endif /* MCUXCL_FEATURE_SM2_INTERNAL */

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASM2_MODECONSTANTS_H_ */
