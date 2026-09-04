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
 * @file  mcuxClEcc_ArithmeticOperation_PointAddSub.c
 * @brief implementation of mcuxClEcc_ArithOp_PointAdd and/or mcuxClEcc_ArithOp_PointSub function
 */


#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>

#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClSession_Internal.h>


#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB
#define MCUXCLECC_FP_ECC_POINTSUB_BRANCH  (MCUX_CSSL_FP_CONDITIONAL((mcuxClEcc_ArithOp_PointSub == caller), MCUXCLPKC_FP_CALLED_CALC_OP1_SUB ))
#else
#define MCUXCLECC_FP_ECC_POINTSUB_BRANCH  (0u)
#endif



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ArithOp_PointAddSub)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_PointAddSub(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize,
    mcuxClEcc_ArithmeticOperationFunction_t caller
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ArithOp_PointAddSub);

    /**********************************************************/
    /* Check the input point lengths                          */
    /**********************************************************/

    const uint32_t byteLenP = pEccWeierDomainParams->common.byteLenP;
    const uint32_t pointSize = 2u * byteLenP;

    /* P1 and P2 sizes should be 2u*byteLenP */
    if ((pointSize != op1Size) || (pointSize != op2Size))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/

    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                    pEccWeierDomainParams,
                                    ECC_ARITHMETICOPERATION_POINTADD_NO_OF_BUFFERS));

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /**********************************************************/
    /* Import points to PKC and convert them to MR            */
    /**********************************************************/

    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    /* Import P1 from pOp1 to (WEIER_X1,WEIER_Y1) and P2 from pOp2 to (WEIER_X2,WEIER_Y2) */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(WEIER_X1, pOp1, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET_DI_BALANCED(WEIER_Y1, pOp1, byteLenP, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(WEIER_X2, pOp2, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET_DI_BALANCED(WEIER_Y2, pOp2, byteLenP, byteLenP, operandSize);

    /* expunge pOp1 and pOp2 after its final use. */
    MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ArithOp_ScalarMult, (uint32_t)(pOp1) + (uint32_t)(pOp2));

    /* Check if P1 is valid. */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, ECC_V0, WEIER_X1);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_STATUS_OK != pointCheckStatus)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /* Check if P2 is valid. */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, ECC_V0, WEIER_X2);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus2, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_STATUS_OK != pointCheckStatus2)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB
    if (mcuxClEcc_ArithOp_PointSub == caller)
    {
        /* Calculate negative point (-P2) */
        MCUXCLPKC_FP_CALC_OP1_SUB(WEIER_Y2, ECC_P, WEIER_Y2);
    } else
#endif
    if (mcuxClEcc_ArithOp_PointAdd != caller)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }
    else
    {
        // Intentionally empty
    }

    /* Convert P1 and P2 to Jacobian coordinates in MR */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac,
                        mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac_LEN);

    /**********************************************************/
    /* Calculate P1 + P2                                      */
    /**********************************************************/

    /* Point virtual buffers to the points P1 and P2 for mcuxClEcc_PointFullAdd */
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_XA);  // input: P1
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VZ0, WEIER_ZA);  // input: z' and z
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX1, WEIER_X0);  // input: P2
    MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_XA);  // output P1 + P2
    pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];                             // output: z'

    pOperands[WEIER_VT] = pOperands[ECC_S2]; /* Use S2 as 5th temp. */
    pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];

    /* Calculate P1 + P2 */
    MCUX_CSSL_FP_FUNCTION_CALL(statusPointFullAdd, mcuxClEcc_PointFullAdd());

    if (MCUXCLECC_STATUS_NEUTRAL_POINT == statusPointFullAdd)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        /* balance DI */
        MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ArithOp_PointAddSub, (4u * byteLenP) + (uint32_t)(pResult));

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub,
                                  MCUXCLECC_STATUS_NEUTRAL_POINT,
                                  /* Setup environment */
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
                                  /* Import and convert P1 and P2 */
                                  MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
                                  MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
                                  MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
                                  MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
                                  MCUXCLECC_FP_ECC_POINTSUB_BRANCH,
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
                                  /* Calculate P1 + P2 */
                                  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd),
                                  /* Clean up and exit */
                                  MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /**********************************************************/
    /* Convert the result to affine coordinates in NR         */
    /**********************************************************/

    MCUXCLECC_FP_MODINV(pSession, ECC_T0, WEIER_ZA, ECC_P, ECC_T2, ECC_T3);            // T0 = z'^(-1) * 256^(-LEN), use T2, T3 as temp
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertJacToAffine,
                        mcuxClEcc_FUP_Weier_ConvertJacToAffine_LEN);

    /* Export the result from PKC into pResult */
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER_DI_BALANCED(pResult, WEIER_X0, byteLenP);
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET_DI_BALANCED(pResult, WEIER_Y0, byteLenP, byteLenP);

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

    /* balance DI */
    MCUX_CSSL_DI_EXPUNGE(mcuxClEcc_ArithOp_PointAddSub, (4u * byteLenP) + (uint32_t)(pResult));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub,
                              MCUXCLECC_STATUS_OK,
                              /* Setup environment */
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
                              /* Import and convert P1 and P2 */
                              MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
                              MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
                              MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
                              MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
                              MCUXCLECC_FP_ECC_POINTSUB_BRANCH,
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
                              /* Calculate P1 + P2 */
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd),
                              /* Convert result to affine coordinates */
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),
                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
                              /* Export result */
                              MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER,
                              MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET,
                              /* Clean up and exit */
                              MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}

