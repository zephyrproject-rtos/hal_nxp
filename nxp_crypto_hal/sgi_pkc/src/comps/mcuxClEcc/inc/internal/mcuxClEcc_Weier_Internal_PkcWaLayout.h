/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_PkcWaLayout.h
 * @brief internal header for short Weierstrass curves
 */


#ifndef MCUXCLECC_WEIER_INTERNAL_PKCWALAYOUT_H_
#define MCUXCLECC_WEIER_INTERNAL_PKCWALAYOUT_H_

#include <mcuxClCore_Platform.h>
#include <internal/mcuxClEcc_Internal_PkcWaLayout.h>

#ifdef __cplusplus
extern "C" {
#endif


/**********************************************************/
/** PKC workarea memory layout for Weierstrass functions. */
/**********************************************************/
#define WEIER_VX0  ECC_V0
#define WEIER_VY0  ECC_V1
#define WEIER_VX1  ECC_V2
#define WEIER_VY1  ECC_V3

#define WEIER_VZ0  ECC_V4
#define WEIER_VZ   ECC_V5
#define WEIER_VT2  ECC_V6
#define WEIER_VT3  ECC_V7

#define WEIER_VX2  ECC_V8
#define WEIER_VY2  ECC_V9
#define WEIER_VZ2  ECC_VA
#define WEIER_VT   ECC_VB

#define WEIER_A    ECC_CP0
#define WEIER_B    ECC_CP1

#define WEIER_XA  ECC_COORD00
#define WEIER_YA  ECC_COORD01
#define WEIER_ZA  ECC_COORD02
#define WEIER_Z   ECC_COORD03
#define WEIER_X0  ECC_COORD04 /* Make sure the pointer entry for WEIER_X0 to be at a 64-bit aligned address */
#define WEIER_Y0  ECC_COORD05
#define WEIER_X1  ECC_COORD06
#define WEIER_Y1  ECC_COORD07
#define WEIER_X2  ECC_COORD08
#define WEIER_Y2  ECC_COORD09
#define WEIER_X3  ECC_COORD10
#define WEIER_Y3  ECC_COORD11

#define WEIER_PP_X0   ECC_COORD12
#define WEIER_PP_Y0   ECC_COORD13
#define WEIER_PP_X1   ECC_COORD14
#define WEIER_PP_Y1   ECC_COORD15
#define WEIER_PP_X2   ECC_COORD16
#define WEIER_PP_Y2   ECC_COORD17
#define WEIER_PP_X3   ECC_COORD18
#define WEIER_PP_Y3   ECC_COORD19
#define WEIER_PP_X4   ECC_COORD20
#define WEIER_PP_Y4   ECC_COORD21
#define WEIER_PP_X5   ECC_COORD22
#define WEIER_PP_Y5   ECC_COORD23
#define WEIER_PP_X6   ECC_COORD24
#define WEIER_PP_Y6   ECC_COORD25
#define WEIER_PP_X7   ECC_COORD26
#define WEIER_PP_Y7   ECC_COORD27


#define ECC_GENERATEKEYPAIR_NO_OF_VIRTUALS     ECC_NO_OF_VIRTUALS
#define ECC_GENERATEKEYPAIR_NO_OF_BUFFERS      (WEIER_Y1 + 1u - ECC_GENERATEKEYPAIR_NO_OF_VIRTUALS)

#define ECC_GENERATESIGNATURE_NO_OF_VIRTUALS       ECC_NO_OF_VIRTUALS
#define ECC_GENERATESIGNATURE_NO_OF_BUFFERS        (WEIER_Y1 + 1u - ECC_GENERATESIGNATURE_NO_OF_VIRTUALS)

#define ECC_VERIFYSIGNATURE_NO_OF_VIRTUALS     ECC_NO_OF_VIRTUALS
#define ECC_VERIFYSIGNATURE_NO_OF_BUFFERS      (WEIER_Y3 + 1u - ECC_VERIFYSIGNATURE_NO_OF_VIRTUALS)

#define ECC_KEYAGREEMENT_NO_OF_VIRTUALS     ECC_NO_OF_VIRTUALS
#define ECC_KEYAGREEMENT_NO_OF_BUFFERS      (WEIER_Y1 + 1u - ECC_KEYAGREEMENT_NO_OF_VIRTUALS)

#define ECC_GENERATEDOMAINPARAMS_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_GENERATEDOMAINPARAMS_NO_OF_BUFFERS   (WEIER_Y0 + 1u - ECC_GENERATEDOMAINPARAMS_NO_OF_VIRTUALS)

#define ECC_DECODEPOINT_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_DECODEPOINT_NO_OF_BUFFERS   (WEIER_YA + 1u - ECC_DECODEPOINT_NO_OF_VIRTUALS)

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION
#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SCALARMULT
#define ECC_ARITHMETICOPERATION_SCALARMULT_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_ARITHMETICOPERATION_SCALARMULT_NO_OF_BUFFERS   (WEIER_Y3 + 1u - ECC_ARITHMETICOPERATION_SCALARMULT_NO_OF_VIRTUALS)
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SCALARMULT */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SECURESCALARMULT
#define ECC_ARITHMETICOPERATION_SECURESCALARMULT_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_ARITHMETICOPERATION_SECURESCALARMULT_NO_OF_BUFFERS   (WEIER_Y1 + 1u - ECC_ARITHMETICOPERATION_SCALARMULT_NO_OF_VIRTUALS)
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SECURESCALARMULT */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTADD
#define ECC_ARITHMETICOPERATION_POINTADD_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_ARITHMETICOPERATION_POINTADD_NO_OF_BUFFERS   (WEIER_Y2 + 1u - ECC_ARITHMETICOPERATION_POINTADD_NO_OF_VIRTUALS)
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTADD */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB
#define ECC_ARITHMETICOPERATION_POINTSUB_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_ARITHMETICOPERATION_POINTSUB_NO_OF_BUFFERS   (WEIER_Y2 + 1u - ECC_ARITHMETICOPERATION_POINTSUB_NO_OF_VIRTUALS)
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB */
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION */

#define ECC_WEIERECC_PRIVATEKEYVALIDATION_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_WEIERECC_PRIVATEKEYVALIDATION_NO_OF_BUFFERS   (ECC_T0 + 1u - ECC_WEIERECC_PRIVATEKEYVALIDATION_NO_OF_VIRTUALS)
#define ECC_WEIERECC_PUBLICKEYVALIDATION_NO_OF_VIRTUALS   ECC_NO_OF_VIRTUALS
#define ECC_WEIERECC_PUBLICKEYVALIDATION_NO_OF_BUFFERS    (ECC_T2 + 1u - ECC_WEIERECC_PUBLICKEYVALIDATION_NO_OF_VIRTUALS)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_WEIER_INTERNAL_PKCWALAYOUT_H_ */
