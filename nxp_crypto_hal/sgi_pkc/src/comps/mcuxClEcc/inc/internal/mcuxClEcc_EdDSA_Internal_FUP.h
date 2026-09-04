/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024, 2026 NXP                                            */
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
 * @file  mcuxClEcc_EdDSA_Internal_FUP.h
 * @brief defines FUP programs byte arrays
 */

#ifndef MCUXCLECC_EDDSA_INTERNAL_FUP_H_
#define MCUXCLECC_EDDSA_INTERNAL_FUP_H_

#include <mcuxClCore_Platform.h>

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()

/**********************************************************/
/* FUPs for GenerateKeyPair functionality                 */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_EdDSA_GenerateKeyPair_Prepare_S
 */
#define mcuxClEcc_FUP_EdDSA_GenerateKeyPair_Prepare_S_LEN 12u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_EdDSA_GenerateKeyPair_Prepare_S,
  mcuxClEcc_FUP_EdDSA_GenerateKeyPair_Prepare_S_LEN
);

/**********************************************************/
/* FUPs for GenerateSignature functionality               */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S
 */
#define mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S_LEN 13u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S,
  mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S_LEN
);

/**********************************************************/
/* FUPs for CalcHashModN functionality                    */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_EdDSA_Internal_CalcHashModN_ModN
 */
#define mcuxClEcc_FUP_EdDSA_Internal_CalcHashModN_ModN_LEN 7u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_EdDSA_Internal_CalcHashModN_ModN,
  mcuxClEcc_FUP_EdDSA_Internal_CalcHashModN_ModN_LEN
);

/**********************************************************/
/* FUPs for DecodePoint functionality                     */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Common
 */
#define mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Common_LEN 7u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Common,
  mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Common_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Ed25519
 */
#define mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Ed25519_LEN 7u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Ed25519,
  mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_PrepareExp_Ed25519_LEN
);

/**
 * FUP program declaration mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_ComputeXCandidate_Ed25519
 */
#define mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_ComputeXCandidate_Ed25519_LEN 7u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_ComputeXCandidate_Ed25519,
  mcuxClEcc_FUP_EdDSA_Internal_DecodePoint_ComputeXCandidate_Ed25519_LEN
);


MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

#endif /* MCUXCLECC_EDDSA_INTERNAL_FUP_H_ */
