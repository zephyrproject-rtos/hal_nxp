/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClMath.h>
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
#include <internal/mcuxClSession_Internal.h>


#define MCUXCLECC_FP_ECC_POINTSUB_BRANCH  (MCUX_CSSL_FP_CONDITIONAL((mcuxClEcc_ArithOp_PointSub == caller), MCUXCLPKC_FP_CALLED_CALC_OP1_SUB ))

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_CpuWa_t * const pCpuWorkarea,
    mcuxCl_InputBuffer_t pOp1,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t* pOperands32,
    uint32_t byteLenP
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate);

    /* Import P1 from pOp1 to (WEIER_X1,WEIER_Y1) and P2 from pOp2 to (WEIER_X2,WEIER_Y2) */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, WEIER_X1, pOp1, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, WEIER_Y1, pOp1, byteLenP, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, WEIER_X2, pOp2, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, WEIER_Y2, pOp2, byteLenP, byteLenP);

    /* Check if P1 is valid. */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, ECC_V0, ECC_V1, WEIER_X1, WEIER_Y1);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_STATUS_OK != pointCheckStatus)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, MCUXCLECC_STATUS_INVALID_PARAMS,
            /* Import P1 and P2 and validate P1 */
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            /* Clean up and exit */
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /* Check if P2 is valid. */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, ECC_V0, ECC_V1, WEIER_X2, WEIER_Y2);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus2, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_STATUS_OK != pointCheckStatus2)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, MCUXCLECC_STATUS_INVALID_PARAMS,
            /* Import and validate P1 and P2 */
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            /* Clean up and exit */
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate, MCUXCLECC_STATUS_OK,
            /* Import and validate P1 and P2 */
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));
}

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
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/
    mcuxClEcc_CpuWa_t * const pCpuWorkarea = mcuxClEcc_castToEccCpuWorkarea(mcuxClSession_getCpuWaBuffer(pSession));

    MCUX_CSSL_FP_FUNCTION_CALL(ret_SetupEnvironment,
        mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                           pEccWeierDomainParams,
                                           ECC_ARITHMETICOPERATION_POINTADD_NO_OF_BUFFERS) );
    if (MCUXCLECC_STATUS_OK != ret_SetupEnvironment)
    {
        MCUXCLECC_HANDLE_HW_UNAVAILABLE(ret_SetupEnvironment, mcuxClEcc_ArithOp_PointAddSub);

        /* Session has been cleaned, PKC has been deinitialized in SetupEnvironment. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub, MCUXCLECC_STATUS_INVALID_PARAMS,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment) );
    }

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /**********************************************************/
    /* Import points to PKC and convert them to MR            */
    /**********************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL(ret_importAndValidate, mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate(pSession, pCpuWorkarea,
                                                                                                    pOp1, pOp2, pOperands32, byteLenP));
    if (MCUXCLECC_STATUS_OK != ret_importAndValidate)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub, ret_importAndValidate,
            /* Setup environment */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            /* Import and validate P1 and P2 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate));
    }

    if (mcuxClEcc_ArithOp_PointSub == caller)
    {
        /* Calculate negative point (-P2) */
        MCUXCLPKC_FP_CALC_OP1_SUB(WEIER_Y2, ECC_P, WEIER_Y2);
    } else
    if (mcuxClEcc_ArithOp_PointAdd != caller)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub, MCUXCLECC_STATUS_INVALID_PARAMS);
    }
    else
    {
        // Intentionally empty
    }

    /* Convert P1 and P2 to Jacobian coordinates in MR */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac,
                        mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac_LEN);

    /**********************************************************/
    /* Calcualte P1 + P2                                      */
    /**********************************************************/

    /* Point virtual buffers to the points P1 and P2 for mcuxClEcc_PointFullAdd */
    MCUXCLECC_COPY_2OFFSETS(pOperands32, ECC_V0, ECC_V1, WEIER_XA, WEIER_YA);  // input: P1; is also output P1 + P2
    MCUXCLECC_COPY_2OFFSETS(pOperands32, ECC_V2, ECC_V3, WEIER_ZA, WEIER_Z);   // input: z' and z; is also output z'
    MCUXCLECC_COPY_2OFFSETS(pOperands32, ECC_V4, ECC_V5, WEIER_X0, WEIER_Y0);  // input: P2

    pOperands[WEIER_VT] = pOperands[ECC_S2]; /* Use S2 as 5th temp. */
    pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];

    /* Calculate P1 + P2 */
    MCUX_CSSL_FP_FUNCTION_CALL(statusPointFullAdd, mcuxClEcc_PointFullAdd());

    if (MCUXCLECC_STATUS_NEUTRAL_POINT == statusPointFullAdd)
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_ArithOp_PointAddSub, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub, MCUXCLECC_STATUS_NEUTRAL_POINT,
            /* Setup environment */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            /* Import and validate P1 and P2 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate),
            /* MCUXCLPKC_FP_CALC_OP1_SUB is called in case of subtraction */
            MCUXCLECC_FP_ECC_POINTSUB_BRANCH,
            /* Convert P1 and P2 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
            /* Calculate P1 + P2 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd),
            /* Clean up and exit */
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }


    /**********************************************************/
    /* Convert the result to affine coordinates in NR         */
    /**********************************************************/

    MCUXCLMATH_FP_MODINV(ECC_T0, WEIER_ZA, ECC_P, ECC_T2);            // T0 = z'^(-1) * 256^(-LEN), use T2 as temp
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertJacToAffine,
                        mcuxClEcc_FUP_Weier_ConvertJacToAffine_LEN);

    /* Export the result from PKC into pResult */
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER(mcuxClEcc_ArithOp_PointAddSub, pResult, WEIER_X0, byteLenP);
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET(mcuxClEcc_ArithOp_PointAddSub, pResult, WEIER_Y0, byteLenP, byteLenP);

    /* Set the result size */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*pResultSize, 0u, UINT32_MAX - (2u * byteLenP), MCUXCLECC_STATUS_FAULT_ATTACK);
    *pResultSize += 2u * byteLenP;


    /**********************************************************/
    /* Clean up and exit                                      */
    /**********************************************************/

    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
        mcuxClEcc_ArithOp_PointAddSub, MCUXCLECC_STATUS_FAULT_ATTACK);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAddSub, MCUXCLECC_STATUS_OK,
        /* Setup environment */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
        /* Import and validate P1 and P2 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithOp_PointAddSub_ImportAndValidate),
        /* MCUXCLPKC_FP_CALC_OP1_SUB is called in case of subtraction */
        MCUXCLECC_FP_ECC_POINTSUB_BRANCH,
        /* Convert P1 and P2 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        /* Calculate P1 + P2 */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointFullAdd),
        /* Convert result to affine coordinates */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        /* Export result */
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET,
        /* Clean up and exit */
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}
