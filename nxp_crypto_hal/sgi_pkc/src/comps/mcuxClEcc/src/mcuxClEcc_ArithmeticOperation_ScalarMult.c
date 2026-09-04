/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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
 * @file  mcuxClEcc_ArithOp_ScalarMult.c
 * @brief mcuxClEcc_ArithOp_ScalarMult function make mcuxClEcc_Int_PointMult
 * callable through mcuxClEcc_ArithmeticOperation
 */

#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClSession_Internal.h>


/* Arithmetic operation descriptor for scalar multiplication on Weierstrass curves */
const mcuxClEcc_ArithmeticOperationDescriptor_t mcuxClEcc_ArithOpDesc_ScalarMult =
{
  .arithOpFct = mcuxClEcc_ArithOp_ScalarMult,
  .arithOpFct_FP_FuncId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithOp_ScalarMult)
};


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ArithOp_ScalarMult, mcuxClEcc_ArithmeticOperationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_ScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ArithOp_ScalarMult);

    /**********************************************************/
    /* Check the input point and scalar lengths               */
    /**********************************************************/
    const uint32_t byteLenP = pEccWeierDomainParams->common.byteLenP;
    const uint32_t pointSize = 2u * byteLenP;
    const uint32_t scalarSizeMax = pEccWeierDomainParams->common.byteLenN;
    if ((pointSize != op2Size) || (op1Size > scalarSizeMax))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/

    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                    pEccWeierDomainParams,
                                    ECC_ARITHMETICOPERATION_SCALARMULT_NO_OF_BUFFERS));

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /**************************************************************/
    /* Import point and scalar to PKC RAM and convert them to MR  */
    /**************************************************************/

    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    /* Import scalar to S0 */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_S0, pOp1, op1Size, operandSize);
    /* expunge pOp1 after its final use. */
    MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ArithOp_ScalarMult, (uint32_t)(pOp1));
    /* Check if scalar is ZERO */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_T0, ECC_S0, 0u);
    uint32_t zeroFlag = MCUXCLPKC_WAITFORFINISH_GETZERO();
    if (MCUXCLPKC_FLAG_ZERO == zeroFlag)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        /* balance DI */
        MCUX_CSSL_DI_EXPUNGE(arithOpFct, op1Size + (uint32_t)(pOp2) + op2Size + (uint32_t)(pResult));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_ScalarMult, MCUXCLECC_STATUS_NEUTRAL_POINT,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            // Import point and scalar
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            // Cleanup
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /* Import P to (XA, YA). */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(WEIER_XA, pOp2, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET_DI_BALANCED(WEIER_YA, pOp2, byteLenP, byteLenP, operandSize);
    /* expunge pOp2 after its final use. */
    MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ArithOp_ScalarMult, (uint32_t)(pOp2));

    /* Check if P is valid. */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_XA);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_STATUS_OK != pointCheckStatus)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /* FUP program: convert point P from affine coordinates        */
    /* to Jacobian coordinates in MR                               */
    /* Input: P = (x,y) in NR in (XA, YA)                          */
    /* Output: P = (X,Y,Z) in MR in (WEIER_X0, WEIER_Y0, WEIER_Z)  */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertAffinePoint_ToJacobian,
                        mcuxClEcc_FUP_Weier_ConvertAffinePoint_ToJacobian_LEN);

    /**********************************************************/
    /* Calculate necessary precomputed Points for input Point */
    /**********************************************************/

    /* Calculate PrecP = (2^(op1Size *4)) * P.                */
    /* Input: P in (X0,Y0, ZA=1) relative-z.                  */
    /* Output: PrecP in (X3,Y3, ZA) relative-z.               */
    /* Inputs in pOperands[] and PKC workarea:                */
    /*   buffers (VX2,VY2, VZ2) contain input P, relative-z;  */
    /*   buffer VZ contains z coordinate.                     */
//  MCUXCLPKC_WAITFORREADY();  <== unnecessary, because VX0/VY0/VZ0/VZ/VX2/VY2/VZ2 are not used in the FUP program before.
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X3);  /* output: PrecP */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VZ0, WEIER_ZA);  /* input: z, z'; output z' */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_X0);  /* input: P */
    pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];
    pOperands[WEIER_VT] = pOperands[ECC_S2];  /* Use S2 as 5th temp. */

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_RepeatPointDouble((op1Size * 8u) / 2u));

    /* Prepare 3 pre-computed points for P, with the same z coordinate. */
    /* Input: P     in (X0, Y0, Z) Jacobian;                       */
    /*        PrecP in (X3, Y3, ZA) relative-z.                    */
    /* Output: Prec1 = P (unchanged)   in (X0, Y0, Z) Jacobian;    */
    /*         Prec2 = PrecP (updated) in (X2, Y2, ZA) relative-z; */
    /*         Prec3 = P + PrecP       in (X3, Y3, ZA) relative-z. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VT2, WEIER_X2);  /* output: Prec2 */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_X3);  /* input: PrecP; output: Prec3 */
    pOperands[WEIER_VZ0] = pOperands[WEIER_ZA];                        /* input/output: z' */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, WEIER_X0);  /* input: P */
    MCUXCLECC_FP_CALCFUP_ADD_ONLY();

    /* Update P:  (X0,Y0, old Z) -> (X1,Y1, new Z) Jacobian; */
    /* Update z = z * z'. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_UpdateJacobianCoordinates,
                        mcuxClEcc_FUP_UpdateJacobianCoordinates_LEN);

    /**********************************************************/
    /* Calcualte scalar * P                                   */
    /**********************************************************/

    /* Calculate P2 = u2 * P. */
    /* Inputs in pOperands[] and PKC workarea:          */
    /*   Prec1 = P,         in (X1,Y1, Z) Jacobian;     */
    /*   Prec2 = PrecP,     in (X2,Y2, Z) Jacobian;     */
    /*   Prec3 = P + PrecP, in (X3,Y3, Z) Jacobian.     */
    /* Output: P2 in (XA,YA, ZA) relative-z, w.r.t. Z.  */
//  pOperands[WEIER_VT] = pOperands[ECC_S2];  <== the 5th temp WEIER_VT has been set before calling _RepeatPointDouble.

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Int_PointMult(ECC_S0, op1Size * 8u));

    /* Update z = z * z', so P1: (XA,YA, ZA) relative-z -> (XA,YA, Z) Jacobian. */
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_T1, WEIER_Z, WEIER_ZA, ECC_P);

    /**********************************************************/
    /* Convert the result to affine coordinates in NR         */
    /**********************************************************/
    MCUXCLECC_FP_MODINV(pSession, ECC_T0, ECC_T1, ECC_P, ECC_T2, ECC_T3);            // T0 = z'^(-1) * 256^(-LEN), use T2, T3 as temp
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertJacToAffine,
                        mcuxClEcc_FUP_Weier_ConvertJacToAffine_LEN);

    /* Export the result from PKC into pResult */
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER_DI_BALANCED(pResult, ECC_COORD04, byteLenP);
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET_DI_BALANCED(pResult, ECC_COORD05, byteLenP, byteLenP);

    /* Set the result size */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("caller-controlled variable. user must handle overflows.")
    *pResultSize += (2u * byteLenP);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /**********************************************************/
    /* Clean up and exit                                      */
    /**********************************************************/

    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    /* Expunge op1Size, op2Size and pResult after its final use. */
    MCUX_CSSL_DI_EXPUNGE(arithOpFct, op1Size + op2Size + (uint32_t)(pResult));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_ScalarMult, MCUXCLECC_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
        // Import point and scalar
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        // Calculate precomputed Points
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_RepeatPointDouble),
        MCUXCLECC_FP_CALLED_CALCFUP_ADD_ONLY,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        // Calculate scalar * P
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Int_PointMult),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        // Convert the result
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET,
        // Cleanup
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}

