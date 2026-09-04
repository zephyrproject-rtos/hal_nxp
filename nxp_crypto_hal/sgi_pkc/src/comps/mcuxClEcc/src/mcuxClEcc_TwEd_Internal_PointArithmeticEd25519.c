/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal_PointArithmeticEd25519.c
 * @brief Edwards curve internal point arithmetic for curve Ed25519
 */


#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>


MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * This function implements a point doubling on Ed25519 in extended homogeneous coordinates.
 * More precisely, given a point P = (X:Y:Z:T) in extended homogeneous coordinates it calculates
 * 2*P = (Xres:Yres:Zres:Tres) according to the algorithm specified in Section 3.3 of
 * https://eprint.iacr.org/2008/522.pdf with a = -1.
 *
 * Prerequisites:
 *  - Buffers TWED_X, TWED_Y, TWED_Z and TWED_T contain the homogeneous coordinates (X:Y:Z:T) of P in MR
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - The resulting coordinates (Xres:Yres:Zres:Tres) are stored in buffers TWED_X, TWED_Y, TWED_Z and TWED_T in MR.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_PointDoubleEd25519, mcuxClEcc_TwEd_PointDoubleFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PointDoubleEd25519(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_PointDoubleEd25519);

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_PointDoubleEd25519, mcuxClEcc_FUP_TwEd_PointDoubleEd25519_LEN);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_PointDoubleEd25519,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
        );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * This function implements a unified and complete mixed extended point addition on Ed25519.
 * More precisely, given a point P1 = (X1:Y1:Z1:T1) in extended homogeneous
 * coordinates and a point P2 = (X2:Y2:1:T2) in extended affine coordinates,
 * it calculates the sum P1 + P2 in extended homogeneous coordinates
 * P1 = (Xres:Yres:Zres:Tres), even if either an input or the resulting point is the neutral point.
 * To this end the a = -1 specific algorithm specified
 * in Section 3.1 of https://eprint.iacr.org/2008/522.pdf is used with Z2 = 1.
 *
 * Prerequisites:
 *  - Buffers TWED_X, TWED_Y, TWED_Z and TWED_T contain the homogeneous coordinates (X1:Y1:Z1:T1) of P1 in MR
 *  - Pointers TWED_PP_VX0, TWED_PP_VY0 and TWED_PP_VT0 point to the coordinates X2, Y2 and T2 in MR.
 *  - Depending on currentDigitBitIndex in mcuxClEcc_TwEd_FixScalarMult() it may be that
 *      TWED_PP_VY0 points to ECC_T2 and TWED_PP_VT0 to ECC_T3
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - The resulting coordinates (Xres:Yres:Zres:Tres) are stored in buffers TWED_X, TWED_Y, TWED_Z and TWED_T in MR.
 *
 * @attention The PKC calculation might be still on-going, call #mcuxClPkc_WaitForFinish before CPU accesses to the result.
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_MixedPointAddEd25519, mcuxClEcc_TwEd_PointAddFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_MixedPointAddEd25519(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_MixedPointAddEd25519);

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_MixedPointAddEd25519, mcuxClEcc_FUP_TwEd_MixedPointAddEd25519_LEN);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_MixedPointAddEd25519,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
        );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * This function implements a unified and complete extended point addition on Ed25519.
 * More precisely, given a point P1 = (X1:Y1:Z1:T1) in extended homogeneous
 * coordinates and a point P2 = (X2:Y2:Z2:T2) in extended affine coordinates,
 * it calculates the sum P1 + P2 in extended homogeneous coordinates
 * P1 = (Xres:Yres:Zres:Tres), even if either an input or the resulting point is the neutral point.
 * To this end the a = -1 specific algorithm specified in Section 3.1 of https://eprint.iacr.org/2008/522.pdf is used.
 *
 * Prerequisites:
 *  - Buffers TWED_X, TWED_Y, TWED_Z and TWED_T contain the homogeneous coordinates (X1:Y1:Z1:T1) of P1 in MR
 *  - Pointers TWED_PP_VX0, TWED_PP_VY0, TWED_PP_VT0 point to the coordinates X2, Y2, T2 in MR.
 *  - Buffer TWED_PP_Z contain Z2 in MR
 *  - Depending on currentDigitBitIndex in mcuxClEcc_TwEd_SecureFixScalarMult() it may be that
 *      TWED_PP_VY0 points to ECC_T2 and TWED_PP_VT0 to ECC_T3
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - The resulting coordinates (Xres:Yres:Zres:Tres) are stored in buffers TWED_X, TWED_Y, TWED_Z and TWED_T in MR.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_PointAddEd25519, mcuxClEcc_TwEd_PointAddFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PointAddEd25519(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_PointAddEd25519);

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_PointAddEd25519, mcuxClEcc_FUP_TwEd_PointAddEd25519_LEN);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_PointAddEd25519,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
        );
}
