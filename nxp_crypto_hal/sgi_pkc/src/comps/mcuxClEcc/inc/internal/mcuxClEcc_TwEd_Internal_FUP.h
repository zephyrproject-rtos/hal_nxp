/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024, 2026 NXP                                            */
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
#define mcuxClEcc_FUP_TwEd_PointDoubleEd25519_LEN  16u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_PointDoubleEd25519,
  mcuxClEcc_FUP_TwEd_PointDoubleEd25519_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_MixedPointAddEd25519
 */
#define mcuxClEcc_FUP_TwEd_MixedPointAddEd25519_LEN  19u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_MixedPointAddEd25519,
  mcuxClEcc_FUP_TwEd_MixedPointAddEd25519_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointAddEd25519
 */
#define mcuxClEcc_FUP_TwEd_PointAddEd25519_LEN  20u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_PointAddEd25519,
  mcuxClEcc_FUP_TwEd_PointAddEd25519_LEN
);



/**********************************************************/
/* FUPs for Variable Scalar Mult operation                */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep
 */
#define mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep_LEN  29u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep,
  mcuxClEcc_FUP_VarScalarMult_YZMontLadder_LadderStep_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate
 */
#define mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate_LEN  15u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate,
  mcuxClEcc_FUP_VarScalarMult_Recover_X_Coordinate_LEN
);



/**********************************************************/
/* FUPs for miscellaneous operations on TwEd curves       */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointDouble
 */
#define mcuxClEcc_FUP_TwEd_PointDouble_LEN  16u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_PointDouble,
  mcuxClEcc_FUP_TwEd_PointDouble_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointValidation_AffineNR
 */
#define mcuxClEcc_FUP_TwEd_PointValidation_AffineNR_LEN  14u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_PointValidation_AffineNR,
  mcuxClEcc_FUP_TwEd_PointValidation_AffineNR_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointValidation
 */
#define mcuxClEcc_FUP_TwEd_PointValidation_HomMR_LEN  13u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_PointValidation_HomMR,
  mcuxClEcc_FUP_TwEd_PointValidation_HomMR_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_PointSubtraction
 */
#define mcuxClEcc_FUP_TwEd_PointSubtraction_LEN  22u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_PointSubtraction,
  mcuxClEcc_FUP_TwEd_PointSubtraction_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_TwEd_UpdateExtHomCoords
 */
#define mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_XT_LEN  5u
#define mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_Y_LEN  3u
#define mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_XYT_LEN  (mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_XT_LEN + mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_Y_LEN )
#define mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_Z_LEN  3u
#define mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_YZ_LEN  (mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_Y_LEN + mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_Z_LEN )
#define mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_LEN  (mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_XYT_LEN + mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_Z_LEN )

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_UpdateExtHomCoords,
  mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_LEN
);


/*
 * FUP program declaration mcuxClEcc_FUP_TwEd_ConvertAffineToExtHom
 */
#define mcuxClEcc_FUP_TwEd_ConvertAffineToExtHom_LEN  8u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_TwEd_ConvertAffineToExtHom,
  mcuxClEcc_FUP_TwEd_ConvertAffineToExtHom_LEN
);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_TWED_INTERNAL_FUP_H_ */
