/*--------------------------------------------------------------------------*/
/* Copyright 2022 NXP                                                       */
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
 * @file  mcuxClOsccaSm2_Internal_FUP.h
 * @brief defines FUP programs byte arrays
 */

#ifndef MCUXCLOSCCASM2_INTERNAL_FUP_H_
#define MCUXCLOSCCASM2_INTERNAL_FUP_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClOsccaPkc_FupMacros.h>

#define mcuxClOsccaSm2_FUP_InvertPrivateKey_LEN  9u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_InvertPrivateKey[mcuxClOsccaSm2_FUP_InvertPrivateKey_LEN];

#define mcuxClOsccaSm2_FUP_PointDouble_LEN  23u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_PointDouble[mcuxClOsccaSm2_FUP_PointDouble_LEN];

#define mcuxClOsccaSm2_FUP_PointAdd_LEN  20u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_PointAdd[mcuxClOsccaSm2_FUP_PointAdd_LEN];

#define mcuxClOsccaSm2_FUP_PointCheckCoordinateX_LEN  6u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_PointCheckCoordinateX[mcuxClOsccaSm2_FUP_PointCheckCoordinateX_LEN];

#define mcuxClOsccaSm2_FUP_PointCheckCoordinateY_LEN  6u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_PointCheckCoordinateY[mcuxClOsccaSm2_FUP_PointCheckCoordinateY_LEN];

#define mcuxClOsccaSm2_FUP_PointCheckCoordinateNegY_LEN  4u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_PointCheckCoordinateNegY[mcuxClOsccaSm2_FUP_PointCheckCoordinateNegY_LEN];

#define mcuxClOsccaSm2_FUP_EccTransAffinePoint2Jac_LEN  8u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_EccTransAffinePoint2Jac[mcuxClOsccaSm2_FUP_EccTransAffinePoint2Jac_LEN];

#define mcuxClOsccaSm2_FUP_JacPointCheck_LEN  16u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_JacPointCheck[mcuxClOsccaSm2_FUP_JacPointCheck_LEN];

#define mcuxClOsccaSm2_FUP_CheckRPlusS_LEN  5u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_CheckRPlusS[mcuxClOsccaSm2_FUP_CheckRPlusS_LEN];

#define mcuxClOsccaSm2_FUP_CheckSignature_LEN  5u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_CheckSignature[mcuxClOsccaSm2_FUP_CheckSignature_LEN];

#define mcuxClOsccaSm2_FUP_Sign_Prepare_KD_LEN  6u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_Sign_Prepare_KD[mcuxClOsccaSm2_FUP_Sign_Prepare_KD_LEN];

#define mcuxClOsccaSm2_FUP_Sign_RPlusK_LEN  7u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_Sign_RPlusK[mcuxClOsccaSm2_FUP_Sign_RPlusK_LEN];

#define mcuxClOsccaSm2_FUP_Sign_Check_r_LEN  5u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_Sign_Check_r[mcuxClOsccaSm2_FUP_Sign_Check_r_LEN];

#define mcuxClOsccaSm2_FUP_Sign_Double_Check_r_LEN  6u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_Sign_Double_Check_r[mcuxClOsccaSm2_FUP_Sign_Double_Check_r_LEN];

#define mcuxClOsccaSm2_FUP_Sign_Compute_s_LEN  22u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_Sign_Compute_s[mcuxClOsccaSm2_FUP_Sign_Compute_s_LEN];

#define mcuxClOsccaSm2_FUP_UpdateZ_LEN  6u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_UpdateZ[mcuxClOsccaSm2_FUP_UpdateZ_LEN];

#define mcuxClOsccaSm2_FUP_EccPointMultMontgomery_InitPoints_LEN  7u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_EccPointMultMontgomery_InitPoints[mcuxClOsccaSm2_FUP_EccPointMultMontgomery_InitPoints_LEN];

#define mcuxClOsccaSm2_FUP_EccPointMultMontgomery_CopyP1P0_LEN  4u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_EccPointMultMontgomery_CopyP1P0[mcuxClOsccaSm2_FUP_EccPointMultMontgomery_CopyP1P0_LEN];

#define mcuxClOsccaSm2_FUP_EccPointMultMontgomery_CopyP0P1_LEN  4u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_EccPointMultMontgomery_CopyP0P1[mcuxClOsccaSm2_FUP_EccPointMultMontgomery_CopyP0P1_LEN];

#define mcuxClOsccaSm2_FUP_EccPointConvert2Affine_prepareZ3_LEN  5u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_EccPointConvert2Affine_PrepareZ3[mcuxClOsccaSm2_FUP_EccPointConvert2Affine_prepareZ3_LEN];

#define mcuxClOsccaSm2_FUP_EccImportInputPointWithInit_PrepareZ23_LEN  4u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_EccImportInputPointInputPointWithInit_PrepareZ23[mcuxClOsccaSm2_FUP_EccImportInputPointWithInit_PrepareZ23_LEN];

#define mcuxClOsccaSm2_FUP_KeyExchgCalcTa_LEN  11u
extern const mcuxClOsccaPkc_FUPEntry_t mcuxClOsccaSm2_FUP_KeyExchgCalcTa[mcuxClOsccaSm2_FUP_KeyExchgCalcTa_LEN];

#endif /* MCUXCLOSCCASM2_INTERNAL_FUP_H_ */
