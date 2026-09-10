/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_FP.h
 * @brief flow protection definitions
 */


#ifndef MCUXCLECC_WEIER_INTERNAL_FP_H_
#define MCUXCLECC_WEIER_INTERNAL_FP_H_

#include <mcuxClCore_Platform.h>


/**********************************************************/
/* mcuxClEcc_KeyGen                                        */
/**********************************************************/

/* Initialization */
#define MCUXCLECC_FP_KEYGEN_INIT  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SetupEnvironment),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared)

/* Import/check base point */
#define MCUXCLECC_FP_KEYGEN_BASE_POINT  \
    MCUXCLECC_FP_KEYGEN_INIT,  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

/* Generate private key */
#define MCUXCLECC_FP_KEYGEN_GENERATE_PRIKEY  \
    MCUXCLECC_FP_KEYGEN_BASE_POINT,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_BlindedSecretKeyGen_RandomWithExtraBits)

/* Calculate public key */
#define MCUXCLECC_FP_KEYGEN_CALC_PUBKEY  \
    MCUXCLECC_FP_KEYGEN_GENERATE_PRIKEY,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_LSB0s,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult)

/* Convert/check public key */
#define MCUXCLECC_FP_KEYGEN_CONVERT_PUBKEY  \
    MCUXCLECC_FP_KEYGEN_CALC_PUBKEY,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

/* Check n/p and export */
#define MCUXCLECC_FP_KEYGEN_FINAL  \
    MCUXCLECC_FP_KEYGEN_CONVERT_PUBKEY,  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureExportBigEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportBigEndianFromPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportBigEndianFromPkc),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,  \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE


/**********************************************************/
/* mcuxClEcc_Sign                                          */
/**********************************************************/

/* Initialization */
#define MCUXCLECC_FP_SIGN_INIT  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SetupEnvironment)

#define MCUXCLECC_FP_SIGN_BEFORE_LOOP  \
    MCUXCLECC_FP_SIGN_INIT, \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)

/* Main loop - first part, until checking r */
#define MCUXCLECC_FP_SIGN_LOOP_R  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_BlindedFixScalarMult),  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MS

/* Mail loop - second part, checking s */
#define MCUXCLECC_FP_SIGN_LOOP_S  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureImportBigEndianToPkc),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    /* optional SHR will be balanced separately */ \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MM,  \
    MCUXCLPKC_FP_CALLED_CALC_MC1_MS

#define MCUXCLECC_FP_SIGN_FINAL  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,  \
    MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,  \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE


/**********************************************************/
/* mcuxClEcc_PointMult                                     */
/**********************************************************/

/* Initialization */
#define MCUXCLECC_FP_POINTMULT_INIT  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SetupEnvironment),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QDash)

/* Import/check base point */
#define MCUXCLECC_FP_POINTMULT_BASE_POINT  \
    MCUXCLECC_FP_POINTMULT_INIT,  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

/* Import scalar */
// TODO (CLNS-979) Avoid multiplication with 2 if CLNS-979 is reseolved
#define MCUXCLECC_FP_POINTMULT_SCALAR  \
    MCUXCLECC_FP_POINTMULT_BASE_POINT,  \
    (2u * MCUXCLPKC_FP_CALLED_CALC_OP1_CONST),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),  \
    MCUXCLPKC_FP_CALLED_SECUREIMPORTBIGENDIANTOPKC_BUFFER,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_SHR,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_ADD,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

/* Calculate scalar multiplication */
#define MCUXCLECC_FP_POINTMULT_SCALAR_MULTIPLICATION  \
    MCUXCLECC_FP_POINTMULT_SCALAR,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult),  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_LSB0s,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult)

/* Convert/check result of scalar multiplication */
#define MCUXCLECC_FP_POINTMULT_CONVERT_POINT  \
    MCUXCLECC_FP_POINTMULT_SCALAR_MULTIPLICATION,  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR)

/* Check n/p and export */
// TODO (CLNS-979) Avoid multiplication with 2 if CLNS-979 is reseolved
#define MCUXCLECC_FP_POINTMULT_FINAL  \
    MCUXCLECC_FP_POINTMULT_CONVERT_POINT,  \
    (2u * MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER),  \
    (2u * MCUXCLPKC_FP_CALLED_CALC_OP1_CMP),  \
    MCUXCLPKC_FP_CALLED_SECUREEXPORTBIGENDIANFROMPKC_BUFFER,  \
    MCUXCLPKC_FP_CALLED_SECUREEXPORTBIGENDIANFROMPKC_BUFFEROFFSET,  \
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,  \
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE


/**********************************************************/
/* mcuxClEcc_Verify                                        */
/**********************************************************/

#define MCUXCLECC_FP_VERIFY_INIT  \
        (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SetupEnvironment)+ \
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER+ \
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET)

#define MCUXCLECC_FP_VERIFY_PREPARE_AND_CHECK \
        (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SignatureRangeCheck)+ \
         MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Verify_PrepareMessageDigest))

#define MCUXCLECC_FP_VERIFY_CALC_P1 \
       (MCUXCLPKC_FP_CALLED_CALC_MC1_MS+ \
        MCUXCLPKC_FP_CALLED_CALC_MC1_MR+ \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv)+ \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)+ \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_InterleaveTwoScalars)+ \
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLPKC_FLAG_ZERO != checkHashZero), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_PlainFixScalarMult)))




#endif /* MCUXCLECC_WEIER_INTERNAL_FP_H_ */
