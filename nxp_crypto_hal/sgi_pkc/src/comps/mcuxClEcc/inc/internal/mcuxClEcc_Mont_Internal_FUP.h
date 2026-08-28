/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2024, 2026 NXP                                      */
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
 * @file  mcuxClEcc_Mont_Internal_FUP.h
 * @brief defines FUP programs byte arrays
 */


#ifndef MCUXCLECC_MONT_INTERNAL_FUP_H_
#define MCUXCLECC_MONT_INTERNAL_FUP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>


/**********************************************************/
/* FUPs for Montgomery DH functionalities                 */
/**********************************************************/

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
/**
 * FUP program declaration mcuxClEcc_FUP_MontDhDecodeScalar
 */
#define mcuxClEcc_FUP_MontDhDecodeScalar_LEN  10u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_MontDhDecodeScalar,
  mcuxClEcc_FUP_MontDhDecodeScalar_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_MontDhX_CalcAffineX
 */
#define mcuxClEcc_FUP_MontDhX_CalcAffineX_LEN  8u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_MontDhX_CalcAffineX,
  mcuxClEcc_FUP_MontDhX_CalcAffineX_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_MontDhX_DecodeAndRandomizeX
 */
#define mcuxClEcc_FUP_MontDhX_DecodeAndRandomizeX_LEN  6u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_MontDhX_DecodeAndRandomizeX,
  mcuxClEcc_FUP_MontDhX_DecodeAndRandomizeX_LEN
);



/**********************************************************/
/* FUPs for SecureScalarMult operation                    */
/**********************************************************/
/**
 * FUP program declaration mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords
 */
#define mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords_LEN  9u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords,
  mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep
 */
#define mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep_Affine_LEN  19u
#define mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep_Projective_LEN  22u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep,
  mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep_Projective_LEN
);


MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_MONT_INTERNAL_FUP_H_ */
