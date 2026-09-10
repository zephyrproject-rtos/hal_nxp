/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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
 * @file  mcuxClEcc_ECDSA_Internal_FUP.h
 * @brief defines FUP programs byte arrays
 */


#ifndef MCUXCLECC_ECDSA_INTERNAL_FUP_H_
#define MCUXCLECC_ECDSA_INTERNAL_FUP_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()

#ifdef MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC
/**
 * FUP program declaration mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_CheckNSmallerK
 */
#define mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_CheckNSmallerK_LEN  6u
extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_CheckNSmallerK[mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_CheckNSmallerK_LEN];

/**
 * FUP program declaration mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_BlindK_CheckZeroK
 */
#define mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_BlindK_CheckZeroK_LEN  10u
extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_BlindK_CheckZeroK[mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_BlindK_CheckZeroK_LEN];
#endif /* MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC */

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_ECDSA_INTERNAL_FUP_H_ */
