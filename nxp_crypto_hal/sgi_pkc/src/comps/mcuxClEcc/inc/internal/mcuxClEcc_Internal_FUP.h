/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_FUP.h
 * @brief defines FUP programs byte arrays
 */

#ifndef MCUXCLECC_INTERNAL_FUP_H_
#define MCUXCLECC_INTERNAL_FUP_H_

#include <mcuxClCore_Platform.h>

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClEcc_FeatureConfig.h>
#include <internal/mcuxClPkc_FupMacros.h>


#ifdef __cplusplus
extern "C" {
#endif

/*
 * FUP program declaration mcuxClEcc_FUP_ConvertHomToAffine
 */
#define mcuxClEcc_FUP_ConvertHomToAffine_LEN 7u

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_ConvertHomToAffine,
  mcuxClEcc_FUP_ConvertHomToAffine_LEN
);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

/*
 * FUP program declaration mcuxClEcc_FUP_Interleave
 */
#define mcuxClEcc_FUP_Interleave_LEN 7u

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Interleave,
  mcuxClEcc_FUP_Interleave_LEN
);
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#if defined(MCUXCL_FEATURE_ECC_EDDSA) || defined(MCUXCL_FEATURE_ECC_MONTDH)
/*
 * FUP program declaration mcuxClEcc_FUP_ReduceRandomModModulus
 */
#define mcuxClEcc_FUP_ReduceRandomModModulus_LEN 4u

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_ReduceRandomModModulus,
  mcuxClEcc_FUP_ReduceRandomModModulus_LEN
);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()
#endif /* MCUXCL_FEATURE_ECC_EDDSA MCUXCL_FEATURE_ECC_MONTDH */

#ifdef MCUXCL_FEATURE_ECC_EDDSA
/**
 * FUP program declaration mcuxClEcc_FUP_PointComparisonHom
 */
#define mcuxClEcc_FUP_PointComparisonHom_LEN 16u

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_PointComparisonHom,
  mcuxClEcc_FUP_PointComparisonHom_LEN
);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()
#endif /* MCUXCL_FEATURE_ECC_EDDSA */


/**
 * FUP program declaration mcuxClEcc_FUP_SetupEnvironment_ClearBuffers
 */
#define mcuxClEcc_FUP_SetupEnvironment_ClearBuffers_LEN 5u

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_SetupEnvironment_ClearBuffers,
  mcuxClEcc_FUP_SetupEnvironment_ClearBuffers_LEN
);
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#if defined(MCUXCLECC_FEATURE_INTERNAL_GENMULTBLINDING)

/**
 * FUP program declaration mcuxClEcc_FUP_SetupEnvironment_ClearBuffers
 */
#define mcuxClEcc_FUP_GenerateMultiplicativeBlinding_LEN 7u

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_GenerateMultiplicativeBlinding,
  mcuxClEcc_FUP_GenerateMultiplicativeBlinding_LEN
);
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()
#endif /* defined(MCUXCLECC_FEATURE_INTERNAL_GENMULTBLINDING) */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_INTERNAL_FUP_H_ */
