/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_FUP.h
 * @brief defines FUP programs byte arrays
 */


#ifndef MCUXCLECC_WEIER_INTERNAL_FUP_H_
#define MCUXCLECC_WEIER_INTERNAL_FUP_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_FeatureConfig.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()


#if defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_POINT_CONVERSION)
/**********************************************************/
/* FUPs for Weier Point Conversion operations             */
/**********************************************************/
/**
 * FUP program declaration mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine
 */
#define mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine_LEN  11u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine,
  mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_SecureConvertPoint_JacToAffine
 */
#define mcuxClEcc_FUP_Weier_SecureConvertPoint_JacToAffine_LEN  18u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_SecureConvertPoint_JacToAffine,
  mcuxClEcc_FUP_Weier_SecureConvertPoint_JacToAffine_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac
 */
#define mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac_LEN  7u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac,
  mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_ConvertJacToAffine
 */
#define mcuxClEcc_FUP_Weier_ConvertJacToAffine_LEN   10u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_ConvertJacToAffine,
  mcuxClEcc_FUP_Weier_ConvertJacToAffine_LEN
);


/*
 * FUP program declaration mcuxClEcc_FUP_Weier_ConvertAffinePoint_ToJacobian
 */
#define mcuxClEcc_FUP_Weier_ConvertAffinePoint_ToJacobian_LEN 5u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_ConvertAffinePoint_ToJacobian,
  mcuxClEcc_FUP_Weier_ConvertAffinePoint_ToJacobian_LEN
);


#endif /* defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_POINT_CONVERSION) */

/**********************************************************/
/* FUPs for Weier Miscellaneous operations                */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_UpdateJacobianCoordinates
 */
#define mcuxClEcc_FUP_UpdateJacobianCoordinates_LEN  7u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_UpdateJacobianCoordinates,
  mcuxClEcc_FUP_UpdateJacobianCoordinates_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_PointCheckAffNR
 */
#define mcuxClEcc_FUP_Weier_PointCheckAffNR_LEN  10u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_PointCheckAffNR,
  mcuxClEcc_FUP_Weier_PointCheckAffNR_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_PointCheckJacMR
 */
#define mcuxClEcc_FUP_Weier_PointCheckJacMR_LEN  15u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_PointCheckJacMR,
  mcuxClEcc_FUP_Weier_PointCheckJacMR_LEN
);



/**********************************************************/
/* FUPs for Weier Point Arithmetic Operations             */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_Weier_DoubleAdd
 */
#define mcuxClEcc_FUP_Weier_DoubleAdd_LEN1   5u
#define mcuxClEcc_FUP_Weier_DoubleAdd_LEN2  15u
#define mcuxClEcc_FUP_Weier_DoubleAdd_LEN   (mcuxClEcc_FUP_Weier_DoubleAdd_LEN1 + mcuxClEcc_FUP_Weier_DoubleAdd_LEN2)
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_DoubleAdd,
  mcuxClEcc_FUP_Weier_DoubleAdd_LEN
);


#define MCUXCLECC_FP_CALCFUP_ADD_ONLY()  \
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_VX0); \
    pOperands[WEIER_VZ2] = pOperands[WEIER_VZ0]; \
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_DoubleAdd, mcuxClEcc_FUP_Weier_DoubleAdd_LEN )
#define MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

#define MCUXCLECC_FP_CALCFUP_DOUBLE_ADD()  \
    do{  \
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_VX0); \
        pOperands[WEIER_VZ2] = pOperands[WEIER_VZ0]; \
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_DoubleAdd, mcuxClEcc_FUP_Weier_DoubleAdd_LEN );  \
        MCUXCLPKC_FP_CALCFUP_OFFSET(mcuxClEcc_FUP_Weier_DoubleAdd, mcuxClEcc_FUP_Weier_DoubleAdd_LEN1,  \
                                   mcuxClEcc_FUP_Weier_DoubleAdd_LEN2);  \
    } while (false)
#define MCUXCLECC_FP_CALLED_CALCFUP_DOUBLE_ADD  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

/**
 * FUP program declaration mcuxClEcc_FUP_Weier_RepeatDouble
 */
#define mcuxClEcc_FUP_Weier_RepeatDouble_LEN1  5u
#define mcuxClEcc_FUP_Weier_RepeatDouble_LEN2  16u
#define mcuxClEcc_FUP_Weier_RepeatDouble_LEN3  3u
#define mcuxClEcc_FUP_Weier_RepeatDouble_LEN   (mcuxClEcc_FUP_Weier_RepeatDouble_LEN1 + mcuxClEcc_FUP_Weier_RepeatDouble_LEN2 + mcuxClEcc_FUP_Weier_RepeatDouble_LEN3)
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_RepeatDouble,
  mcuxClEcc_FUP_Weier_RepeatDouble_LEN
);


#define MCUXCLECC_FP_CALCFUP_ONE_DOUBLE()  \
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_RepeatDouble,  \
                        mcuxClEcc_FUP_Weier_RepeatDouble_LEN1 + mcuxClEcc_FUP_Weier_RepeatDouble_LEN2)
#define MCUXCLECC_FP_CALLED_CALCFUP_ONE_DOUBLE  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)

#if defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_SECUREPOINTMULT)

/**
 * FUP program declaration mcuxClEcc_FUP_Weier_CoZPointAddSub
 */
#define mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN1   7u
#define mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN2   18u
#define mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN3   3u
#define mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN  \
    (mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN1 + mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN2 + mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN3)
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_CoZPointAddSub,
  mcuxClEcc_FUP_Weier_CoZPointAddSub_LEN
);



/**
 * FUP program declaration mcuxClEcc_FUP_Weier_SecurePointMult_Reduce_X1_Y1_ZA_ModP
 */
#define mcuxClEcc_FUP_Weier_SecurePointMult_Reduce_X1_Y1_ZA_ModP_LEN  8
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_SecurePointMult_Reduce_X1_Y1_ZA_ModP,
  mcuxClEcc_FUP_Weier_SecurePointMult_Reduce_X1_Y1_ZA_ModP_LEN
);



/**
 * FUP program declaration mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1
 */
#define mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN1  4u
#define mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN2  11u
#define mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN3  5u
#define mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN  \
    (  mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN1  \
     + mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN2  \
     + mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN3 )
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1,
  mcuxClEcc_FUP_Weier_SecurePointMult_PrepareZA_UpdateZ_P0_P1_LEN
);


#endif /* defined(MCUXCLECC_FEATURE_INTERNAL_WEIER_SECUREPOINTMULT) */



/**********************************************************/
/* FUPs for Weier KeyGeneration                           */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_Weier_KeyGen_DerivePlainPrivKey
 */
#define mcuxClEcc_FUP_Weier_KeyGen_DerivePlainPrivKey_LEN  7u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_KeyGen_DerivePlainPrivKey,
  mcuxClEcc_FUP_Weier_KeyGen_DerivePlainPrivKey_LEN
);




/**
 * FUP program declaration mcuxClEcc_FUP_Weier_BooleanToArithmeticMasking
 */
#define mcuxClEcc_FUP_Weier_BooleanToArithmeticMasking_LEN  8u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_BooleanToArithmeticMasking,
  mcuxClEcc_FUP_Weier_BooleanToArithmeticMasking_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_CoreKeyGen_Steps2ab
 */
#define mcuxClEcc_FUP_Weier_CoreKeyGen_Steps2ab_LEN  4u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_CoreKeyGen_Steps2ab,
  mcuxClEcc_FUP_Weier_CoreKeyGen_Steps2ab_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_CoreKeyGen_Steps56
 */
#define mcuxClEcc_FUP_Weier_CoreKeyGen_Steps56_LEN  8u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_CoreKeyGen_Steps56,
  mcuxClEcc_FUP_Weier_CoreKeyGen_Steps56_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_CoreKeyGen_Step7
 */
#define mcuxClEcc_FUP_Weier_CoreKeyGen_Step7_LEN  5u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_CoreKeyGen_Step7,
  mcuxClEcc_FUP_Weier_CoreKeyGen_Step7_LEN
);



/***************************************************************/
/* FUPs for ECDH PointMult (KeyAgreement) and SecureScalarMult */
/***************************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_Weier_PointMult_SplitScalar_ConvertPoint2MR
 */
#define mcuxClEcc_FUP_Weier_PointMult_SplitScalar_ConvertPoint2MR_LEN  10u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_PointMult_SplitScalar_ConvertPoint2MR,
  mcuxClEcc_FUP_Weier_PointMult_SplitScalar_ConvertPoint2MR_LEN
);



/**********************************************************/
/* FUPs for ECDSA Sign                                    */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_Weier_Sign_CalculateS
 */
#define mcuxClEcc_FUP_Weier_Sign_CalculateS_LEN  13u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_Sign_CalculateS,
  mcuxClEcc_FUP_Weier_Sign_CalculateS_LEN
);



/**********************************************************/
/* FUPs for ECDSA Verify                                  */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR
 */
#define mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR_LEN  5u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR,
  mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR_LEN
);


/**
 * FUP program declaration mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR
 */
#define mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR_LEN  10u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR,
  mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR_LEN
);


/**
 * FUP program declaration mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR
 */
#define mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR_LEN  6u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR,
  mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR_LEN
);


/**
 * FUP program declaration mcuxClEcc_Fup_Verify_InitZ_CalcU1U2
 */
#define mcuxClEcc_Fup_Verify_InitZ_CalcU1U2_LEN  6u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_Fup_Verify_InitZ_CalcU1U2,
  mcuxClEcc_Fup_Verify_InitZ_CalcU1U2_LEN
);


/**
 * FUP program declaration mcuxClEcc_Fup_Verify_Update_G_to_Prec1
 */
#define mcuxClEcc_Fup_Verify_Update_G_to_Prec1_LEN  5u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_Fup_Verify_Update_G_to_Prec1,
  mcuxClEcc_Fup_Verify_Update_G_to_Prec1_LEN
);


/**
 * FUP program declaration mcuxClEcc_Fup_Verify_Update_pubkeyQ_P1_z
 */
#define mcuxClEcc_Fup_Verify_Update_pubkeyQ_P1_z_LEN  9u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_Fup_Verify_Update_pubkeyQ_P1_z,
  mcuxClEcc_Fup_Verify_Update_pubkeyQ_P1_z_LEN
);



/**********************************************************/
/* FUPs for ECC DecodePoint functionality                 */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_DecodePoint_SEC_CalcAlpha
 */
#define mcuxClEcc_FUP_DecodePoint_SEC_CalcAlpha_LEN  7u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_DecodePoint_SEC_CalcAlpha,
  mcuxClEcc_FUP_DecodePoint_SEC_CalcAlpha_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_DecodePoint_SEC_VerifyBeta
 */
#define mcuxClEcc_FUP_DecodePoint_SEC_VerifyBeta_LEN 7u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_DecodePoint_SEC_VerifyBeta,
  mcuxClEcc_FUP_DecodePoint_SEC_VerifyBeta_LEN
);



/**********************************************************/
/* FUPs for ECC GenerateDomainParams functionality        */
/**********************************************************/

/**
 * FUP program declaration mcuxClEcc_FUP_GenerateDomainParams_Reduce_R2N_R2P
 */
#define mcuxClEcc_FUP_GenerateDomainParams_Reduce_R2N_R2P_LEN   4u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_GenerateDomainParams_Reduce_R2N_R2P,
  mcuxClEcc_FUP_GenerateDomainParams_Reduce_R2N_R2P_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_GenerateDomainParams_Convert_G_toJacMR
 */
#define mcuxClEcc_FUP_GenerateDomainParams_Convert_G_toJacMR_LEN   5u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_GenerateDomainParams_Convert_G_toJacMR,
  mcuxClEcc_FUP_GenerateDomainParams_Convert_G_toJacMR_LEN
);


/**
 * FUP program declaration mcuxClEcc_FUP_Weier_DiscriminantCalculate
 */
#define mcuxClEcc_FUP_Weier_DiscriminantCalculate_LEN  13u
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClEcc_FUP_Weier_DiscriminantCalculate,
  mcuxClEcc_FUP_Weier_DiscriminantCalculate_LEN
);



MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_WEIER_INTERNAL_FUP_H_ */
