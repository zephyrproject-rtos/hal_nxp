/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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
 * @file  mcuxClEcc_ArithOp_SecureScalarMult.c
 * @brief Implementation of secure scalar multiplication
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
#include <internal/mcuxClSession_Internal_EntryExit.h>


/* Arithmetic operation descriptor for secure scalar multiplication on Weierstrass curves */
const mcuxClEcc_ArithmeticOperationDescriptor_t mcuxClEcc_ArithOpDesc_SecureScalarMult =
{
  .arithOpFct = mcuxClEcc_ArithOp_SecureScalarMult,
  .arithOpFct_FP_FuncId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithOp_SecureScalarMult)
};


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ArithOp_SecureScalarMult, mcuxClEcc_ArithmeticOperationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_SecureScalarMult(
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
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ArithOp_SecureScalarMult);

    /**********************************************************/
    /* Step 1: Check the input point and scalar lengths       */
    /**********************************************************/
    const uint32_t byteLenP = pEccWeierDomainParams->common.byteLenP;
    const uint32_t pointSize = 2u * byteLenP;
    const uint32_t scalarSizeMax = pEccWeierDomainParams->common.byteLenN;
    if ((pointSize != op2Size) || (op1Size > scalarSizeMax))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }
    MCUX_CSSL_DI_EXPUNGE(arithOpFct, op2Size);

    /**********************************************************/
    /* Step 2: Initialization                                 */
    /**********************************************************/

    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_WeierECC_SetupEnvironment(pSession,
                                    pEccWeierDomainParams,
                                    ECC_ARITHMETICOPERATION_SECURESCALARMULT_NO_OF_BUFFERS));

    /* Randomize coordinate buffers used within secure scalar multiplication (X0/Y0/X1/Y1). */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_RandomizeUPTRT(&pOperands[WEIER_XA],
                                                        (WEIER_Y1 - WEIER_XA + 1u)) );

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

    /**************************************************************/
    /* Step 3: Import point and scalar to PKC RAM                 */
    /**************************************************************/

    /* Import scalar to S2 */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_S2, pOp1, op1Size, operandSize);
    /* expunge pOp1 and op1Size after its final use. */
    MCUX_CSSL_DI_EXPUNGE(arithOpFct, (uint32_t)(pOp1));
    MCUX_CSSL_DI_EXPUNGE(arithOpFct, op1Size);

    /* Import P to (XA, YA). */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(WEIER_XA, pOp2, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET_DI_BALANCED(WEIER_YA, pOp2, byteLenP, byteLenP, operandSize);
    /* expunge pOp2 after its final use. */
    MCUX_CSSL_DI_EXPUNGE(arithOpFct, (uint32_t)(pOp2));

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

    /**********************************************************/
    /* Step 4: Perform a secure scalar multiplication Q = d*P */
    /*         using a multiplicative splitting for d.        */
    /**********************************************************/

    /* Call the BlindedScalarMult function.
     * If the function returns OK, WEIER_X0, WEIER_Y0, WEIER_Z contain the Jacobian coordinates of Q. */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_BlindedVarScalarMult, mcuxClEcc_BlindedVarScalarMult(pSession,
                                                                                      (mcuxClEcc_CommonDomainParams_t *) &pEccWeierDomainParams->common) );
    if (MCUXCLECC_INTSTATUS_SCALAR_ZERO == ret_BlindedVarScalarMult)
    {
        /* Clear PKC workarea. */
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        /* balance DI */
        MCUX_CSSL_DI_EXPUNGE(arithOpFct, pResult);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_SecureScalarMult, MCUXCLECC_STATUS_NEUTRAL_POINT,
            /* Step 2 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),
            /* Step 3 */
            2u * MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
            /* Step 4 */
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_BlindedVarScalarMult),
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }
    else if (MCUXCLECC_STATUS_OK != ret_BlindedVarScalarMult)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Intentionally left empty */
    }

    /* Check the confidential point Q in randomized Jacobian coordinates before the conversion to affine coordinates. */
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckQStatusJacMR, mcuxClEcc_Weier_PointCheckJacMR(pSession, WEIER_X0, WEIER_Y0, WEIER_Z));
    if (MCUXCLECC_STATUS_OK != pointCheckQStatusJacMR)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }


    /**********************************************************/
    /* Step 5: Securely convert resulting point to affine     */
    /*         coordinates                                     */
    /**********************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Weier_SecureConvertPoint_JacToAffine(pSession));

    /**********************************************************/
    /* Step 6: Export the resulting point.                    */
    /**********************************************************/

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        mcuxClEcc_IntegrityCheckPN(pSession, (mcuxClEcc_CommonDomainParams_t *) &pEccWeierDomainParams->common));

    /* Export the result from PKC into pResult */
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER_DI_BALANCED(pResult, WEIER_XA, byteLenP);
    MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET_DI_BALANCED(pResult, WEIER_YA, byteLenP, byteLenP);

    /* Expunge pResult after its final use. */
    MCUX_CSSL_DI_EXPUNGE(arithOpFct, pResult);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("caller-controlled variable. user must handle overflows.")
    *pResultSize += (2u * byteLenP);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    /* Clear PKC workarea. */
    mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
    MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

    mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_SecureScalarMult, MCUXCLECC_STATUS_OK,
        /* Step 2: Initialization */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_WeierECC_SetupEnvironment),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT),
        /* Step 3: Import point and scalar to PKC RAM */
        2u * MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
        /* Step 4: Perform secure scalar multiplication */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_BlindedVarScalarMult),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_PointCheckJacMR),
        /* Step 5: Convert resulting point to affine coordinates */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SecureConvertPoint_JacToAffine),
        /* Step 6: Export the resulting point */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_IntegrityCheckPN),
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET,
        MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
}

