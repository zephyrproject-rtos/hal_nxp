/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_PlainFixScalarMult.c
 * @brief Plain scalar multiplication with (fixed) base point for Weierstrass curves
 */


#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClPkc_ImportExport.h>

#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

#include <internal/mcuxClSession_Internal.h>

/**
 * This function implements a scalar multiplication lambda*G for a given secret scalar lambda in {1,...,n-1}
 * and the base point G on Weierstrass curves. The result will be returned in homogeneous coordinates (Xres:Yres:Zres).
 * The scalar multiplication is implemented using a non-regular comb method processing 2 bits at a time. The required pre-computed
 * point PrecG is passed via the domain parameters and will be imported by this function internally.
 *
 * Input:
 *  - pSession              Handle for the current CL session
 *  - pDomainParams         Pointer to ECC common domain parameters structure
 *  - iScalar Pointer       table index of secret scalar lambda
 *  - scalarBitLength       Bit length of the scalar
 *  - options               Parameter to pass options
 *
 * Prerequisites:
 *  - Buffer buf(iScalar) contains the secret scalar lambda of bit length scalarBitLength
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers WEIER_A and WEIER_B contain the curve parameters a in Montgomery representation and b in normal representation
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - Buffers WEIER_XA, WEIER_YA and WEIER_Z contain Xres, Yres and Zres in MR
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_PlainFixScalarMult, mcuxClEcc_ScalarMultFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_PlainFixScalarMult(
    mcuxClSession_Handle_t pSession,                 ///<  [in]  pSession            Handle for the current CL session
    mcuxClEcc_CommonDomainParams_t *pDomainParams,   ///<  [in]  pDomainParams       Pointer to ECC common domain parameters structure
    uint8_t iScalar,                                ///<  [in]  iScalar             Pointer table index of secret scalar lambda
    uint32_t scalarBitLength,                       ///<  [in]  scalarBitLength     Bit length of the scalar
    uint32_t options UNUSED_PARAM                   ///<  [in]  options             Parameter to pass options
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_PlainFixScalarMult);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    const uint32_t byteLenP = pDomainParams->byteLenP;

    /* Import G to (X1,Y1). */
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(WEIER_X1, pDomainParams->pGx, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(WEIER_Y1, pDomainParams->pGy, byteLenP, operandSize);

    /* Import PrecG to (X2, Y2). */
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(WEIER_X2, pDomainParams->pPrecPoints, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(WEIER_Y2, pDomainParams->pPrecPoints + byteLenP, byteLenP, operandSize);

    /* Check G in (X1,Y1) affine NR. */
//      MCUXCLPKC_WAITFORREADY();  <== there is WaitForFinish in import function.
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X1);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckBasePointStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_STATUS_OK != pointCheckBasePointStatus)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Check PrecG in (X2,Y2) affine NR. */
//      MCUXCLPKC_WAITFORREADY();  <== there is WaitForFinish in _PointCheckAffineNR.
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X2);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckPrecPointStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_STATUS_OK != pointCheckPrecPointStatus)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Convert coordinates of G and PrecG to MR.   */
    /* G:     (X1,Y1) affine NR -> (XA,YA, 1) Jacobian;     */
    /* PrecG: (X2,X2) affine NR -> (X3,Y3, Z=1) relative-z. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR,
                        mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR_LEN);

    /* Prepare 3 pre-computed points for G, with the same z coordinate. */
    /* The relative z-coordinate, z' is stored in Z, instead of ZA.     */
    /* Input: G     in (XA,YA, 1) Jacobian;                      */
    /*        PrecG in (X3,Y3, Z=1) relative-z.  (ps, not in ZA) */
    /* Output: Prec1 = G (unchanged)   in (XA,YA, 1) Jacobian;   */
    /*         Prec2 = PrecG (updated) in (X2,Y2, Z) relative-z; */
    /*         Prec3 = G + PrecG       in (X3,Y3, Z) relative-z. */
//      MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VT2/VT3/VX0/VY0/VZ0/VX1/VY1 are not used in the FUP program before.
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VT2, WEIER_X2);  /* output: Prec2 */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X3);  /* input: PrecG; output: Prec3 */
    pOperands[WEIER_VZ0] = pOperands[WEIER_Z];                              /* input: z';    output: z' */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, WEIER_XA);  /* input: G */
    MCUXCLECC_FP_CALCFUP_ADD_ONLY();
    /* Hint: since z' (@ Z) = 1, the initial part of double-add FUP program (4 mul) can be skipped, */
    /*       by manually copying G in (XA,YA) to (X2,Y2), which needs extra code size.              */

    /* Update z = z * z' = z' (skipped because z=1, and z' has been stored in Z). */
    /* Update Prec1: (XA,YA, 1) -> (X1,Y1, Z) Jacobian. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_Fup_Verify_Update_G_to_Prec1,
                        mcuxClEcc_Fup_Verify_Update_G_to_Prec1_LEN);

    /* Calculate P1 = u1 * G. */
    /* Input: 3 Prec_i, in (Xi,Yi, Z) Jacobian.        */
    /* Output: P1 in (XA,YA, ZA) relative-z, w.r.t. Z. */
//      MCUXCLPKC_WAITFORREADY();  <==unnecessary, because VT is not used in the FUP program before.
    pOperands[WEIER_VT] = pOperands[ECC_S2];  /* Use S2 as 5th temp. */

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Int_PointMult(iScalar, scalarBitLength));

    /* Update z = z * z', so P1: (XA,YA, ZA) relative-z -> (XA,YA, Z) Jacobian. */
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_T0, WEIER_Z, WEIER_ZA, ECC_P);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_Z, ECC_T0, 0u);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_Weier_PlainFixScalarMult,
        MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER, \
        MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER, \
        MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER, \
        MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
        MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY, \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup), \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_PointMult), \
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM, \
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST);
}
