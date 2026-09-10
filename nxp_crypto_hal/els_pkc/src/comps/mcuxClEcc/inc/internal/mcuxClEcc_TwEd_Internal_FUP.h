/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal_FUP.h
 * @brief defines FUP programs byte arrays for twisted Edwards curve Ed448
 */


#ifndef MCUXCLECC_TWED_INTERNAL_FUP_H_
#define MCUXCLECC_TWED_INTERNAL_FUP_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()



/**********************************************************/
/* FUPs for Ed25519 curve operations                      */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointDoubleEd25519
 */
#define mcuxClEcc_FUP_TwEd_PointDoubleEd25519_Len  16u
extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointDoubleEd25519[mcuxClEcc_FUP_TwEd_PointDoubleEd25519_Len];

/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_MixedPointAddEd25519
 */
#define mcuxClEcc_FUP_TwEd_MixedPointAddEd25519_Len  19u
extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_MixedPointAddEd25519[mcuxClEcc_FUP_TwEd_MixedPointAddEd25519_Len];


/**********************************************************/
/* FUPs for Variable Scalar Mult operation                */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep
 */
#define mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep_LEN  29u
extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep[mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep_LEN];

/**
 * FUP program declaration mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate
 */
#define mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate_LEN  15u
extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate[mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate_LEN];


/**********************************************************/
/* FUPs for miscellaneous operations on TwEd curves       */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointDouble
 */
#define mcuxClEcc_FUP_TwEd_PointDouble_LEN  16u

extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointDouble[mcuxClEcc_FUP_TwEd_PointDouble_LEN];

/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointValidation_AffineNR
 */
#define mcuxClEcc_FUP_TwEd_PointValidation_AffineNR_Len  14u

extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointValidation_AffineNR[mcuxClEcc_FUP_TwEd_PointValidation_AffineNR_Len];

/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointValidation
 */
#define mcuxClEcc_FUP_TwEd_PointValidation_HomMR_LEN  13u

extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointValidation_HomMR[mcuxClEcc_FUP_TwEd_PointValidation_HomMR_LEN];

/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointSubtraction
 */
#define mcuxClEcc_FUP_TwEd_PointSubtraction_LEN  22u

extern const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointSubtraction[mcuxClEcc_FUP_TwEd_PointSubtraction_LEN];

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_TWED_INTERNAL_FUP_H_ */
