/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_GenerateDomainParams.c
 * @brief ECC Weierstrass custom domain parameter generation function
 */


#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_WeierECC_GenerateDomainParams)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_GenerateDomainParams(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxClEcc_Weier_BasicDomainParams_t *pEccWeierBasicDomainParams,
    uint32_t options)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClEcc_WeierECC_GenerateDomainParams, diRefValue, MCUXCLECC_STATUS_FAULT_ATTACK);

    /**********************************************************/
    /* Initialization and parameter verification              */
    /**********************************************************/

    const uint32_t byteLenP = pEccWeierBasicDomainParams->pLen;
    const uint32_t byteLenN = pEccWeierBasicDomainParams->nLen;
    const uint32_t byteLenMax = ((byteLenP > byteLenN) ? byteLenP : byteLenN);
    const uint32_t operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenMax);

    /* Initialize CPU and PKC environment */
    mcuxClEcc_CpuWa_t *pCpuWorkarea;
    uint8_t *pPkcWorkarea;
    uint16_t *pOperands;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_InitializeEnvironment(
        pSession, operandSize, ECC_GENERATEDOMAINPARAMS_NO_OF_BUFFERS,
        &pCpuWorkarea, &pPkcWorkarea, &pOperands
    ));

    /**********************************************************/
    /* Import / prepare curve parameters                      */
    /**********************************************************/

    /* Import prime p and order n. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_P, pEccWeierBasicDomainParams->pP, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_N, pEccWeierBasicDomainParams->pN, byteLenN, operandSize);

    /* Check p and n are odd (Math functions assume modulus is odd). */
    const volatile uint8_t * ptrP = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_P]);
    const volatile uint8_t * ptrN = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("PKC buffer is CPU word aligned")
    uint32_t p0 = ((const volatile uint32_t *) ptrP)[0];
    uint32_t n0 = ((const volatile uint32_t *) ptrN)[0];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    if (0x01u != (0x01u & p0 & n0))
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /* Calculate NDash of p and n, ShiftModulus of p and n, QSquared of p. */
    MCUXCLMATH_FP_NDASH(pSession, ECC_P, ECC_T0);
    MCUXCLMATH_FP_NDASH(pSession, ECC_N, ECC_T0);
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_PS, ECC_P);
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_NS, ECC_N);
    MCUXCLMATH_FP_QSQUARED(pSession, ECC_PQSQR, ECC_PS, ECC_P, ECC_T0);

    /* Import coefficients a and b, and convert a to MR. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_T0, pEccWeierBasicDomainParams->pA, byteLenP, operandSize);
    MCUXCLPKC_FP_CALC_MC1_MM(WEIER_A, ECC_T0, ECC_PQSQR, ECC_P);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(WEIER_B, pEccWeierBasicDomainParams->pB, byteLenP, operandSize);

    /* Import the base point coordinates (x,y) to buffers (ECC_S0,ECC_S1). */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_S0, pEccWeierBasicDomainParams->pG, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET_DI_BALANCED(ECC_S1, pEccWeierBasicDomainParams->pG, byteLenP, byteLenP, operandSize);

    pOperands[WEIER_VX0] = pOperands[ECC_S0];
    pOperands[WEIER_VY0] = pOperands[ECC_S1];

    /* Perform basic domain parameter checks */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Weier_DomainParamsCheck(pSession, byteLenP, byteLenN));

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *)pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Calculate R3N, and then reduce R2N < N and R2P < P. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA("2u * operandSize fits into uint16_t")
    MCUXCLMATH_FP_QDASH(pSession, ECC_T3, ECC_NS, ECC_N, ECC_T0, (uint16_t) (2u * operandSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA()
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_GenerateDomainParams_Reduce_R2N_R2P,
                        mcuxClEcc_FUP_GenerateDomainParams_Reduce_R2N_R2P_LEN);

    /**********************************************************/
    /* Optionally, generate the pre-computed point            */
    /**********************************************************/

    MCUX_CSSL_FP_BRANCH_DECL(generatePrecomputedPointBranch);
    if (MCUXCLECC_OPTION_GENERATEPRECPOINT_YES == (options & MCUXCLECC_OPTION_GENERATEPRECPOINT_MASK))
    {
        /* Convert the affine base point coordinates (x,y) stored in ECC_S0 and ECC_S1 to
         * Jacobian coordinates (X:Y:Z=1) in MR and store them in buffers (WEIER_X0,WEIER_Y0,WEIER_Z).
         * Also initialize the relative Z-coordinate Z' as 1 in MR and store it in WEIER_ZA. */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_GenerateDomainParams_Convert_G_toJacMR,
                            mcuxClEcc_FUP_GenerateDomainParams_Convert_G_toJacMR_LEN);

        /* Calculate prec point PrecG = 2^(byteLenN * 4) * G using function mcuxClEcc_RepeatPointDouble.
         * Input/output buffers of mcuxClEcc_RepeatPointDouble are set as follows:
         *
         * Input:
         *  - ECC_VX2, ECC_VY2, ECC_VZ is set to the Jacobian coordinates (X:Y:Z=1) of the base point in buffers (WEIER_X0,WEIER_Y0,WEIER_Z)
         *  - ECC_VZ2 is set to the relative Jacobian coordinate Z'=1 stored in WEIER_ZA
         * Output:
         *  - ECC_VX0, ECC_VY0, ECC_VZ0 are set to buffers (WEIER_XA,WEIER_YA,WEIER_ZA) to store the result precG in relative Jacobian coordinates
         * Temp:
         *  - ECC_VT is set to temp buffer ECC_S2
         *
         * NOTE: Since the input Z-coordinate is 1 in MR, the resulting relative Jacobian coordinate is in fact the Z-coordinate
         *       of the result. So, ECC_VX0, ECC_VY0, ECC_VZ0 will effectively contains Jacobian coordinates for precG. */
//      MCUXCLPKC_WAITFORREADY()  <== unnecessary, because VX0/VY0/VZ0/VZ/VX2/VY2/VZ2 are not used in the FUP program before.
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX0, WEIER_XA);
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VZ0, WEIER_ZA);
        MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, WEIER_VX2, WEIER_X0);
        pOperands[WEIER_VZ2] = pOperands[WEIER_ZA];
        pOperands[WEIER_VT] = pOperands[ECC_S2];

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("byteLenN * 8U cannot overflow.")
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_RepeatPointDouble((byteLenN * 8u) / 2u));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

        /* Convert precG to affine coordinates in NR and store them in (WEIER_X0,WEIER_Y0). */
        MCUXCLECC_FP_MODINV(pSession, ECC_T0, WEIER_ZA, ECC_P, ECC_T1, ECC_T3);
        /* MISRA Ex. 22, while(0) is allowed */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertJacToAffine,
                            mcuxClEcc_FUP_Weier_ConvertJacToAffine_LEN);

        MCUX_CSSL_FP_BRANCH_POSITIVE(generatePrecomputedPointBranch,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_RepeatPointDouble),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
    }
    else if (MCUXCLECC_OPTION_GENERATEPRECPOINT_NO != (options & MCUXCLECC_OPTION_GENERATEPRECPOINT_MASK))
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }


    /**********************************************************/
    /* Initialize optimized domain parameters struct at the   */
    /* start of target memory area                            */
    /**********************************************************/

    /* Interpret start of memory area pEccWeierDomainParams as struct of type mcuxClEcc_Weier_DomainParams_t */
    mcuxClEcc_Weier_DomainParams_t *pDomainParams = (mcuxClEcc_Weier_DomainParams_t *) pEccWeierDomainParams;

    /* Initialize pointers to where the domain parameters shall be stored */
    uint8_t *pDomainParamBuffers = (uint8_t *) pEccWeierDomainParams + sizeof(mcuxClEcc_Weier_DomainParams_t);
    pDomainParams->common.pFullModulusP = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_PFULL;
    pDomainParams->common.pFullModulusN = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_NFULL(byteLenP);
    pDomainParams->common.pR2P = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_R2P(byteLenP, byteLenN);
    pDomainParams->common.pR2N = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_R2N(byteLenP, byteLenN);
    pDomainParams->common.pCurveParam1 = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_CP1(byteLenP, byteLenN);
    pDomainParams->common.pCurveParam2 = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_CP2(byteLenP, byteLenN);
    pDomainParams->common.pGx = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_GX(byteLenP, byteLenN);
    pDomainParams->common.pGy = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_GY(byteLenP, byteLenN);
    pDomainParams->common.pPrecPoints = pDomainParamBuffers + MCUXCLECC_CUSTOMPARAMS_OFFSET_PP(byteLenP, byteLenN);


    /**********************************************************/
    /* Fill optimized domain parameters                       */
    /**********************************************************/

    /* Initialize lengths and function pointers in optimized domain parameter struct */
    pDomainParams->common.byteLenP = (uint16_t) byteLenP;
    pDomainParams->common.byteLenN = (uint16_t) byteLenN;
    pDomainParams->common.pScalarMultFunctions = &mcuxClEcc_Weier_ScalarMultFunctions;

    /* Export full moduli for p and n to optimized domain parameter struct. */
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pFullModulusP, ECC_PFULL, byteLenP + MCUXCLPKC_WORDSIZE);
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pFullModulusN, ECC_NFULL, byteLenN + MCUXCLPKC_WORDSIZE);

    /* Export Montgomery parameters R2P and R2N to optimized domain parameter struct. */
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pR2P, ECC_PQSQR, byteLenP);
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pR2N, ECC_NQSQR, byteLenN);

    /* Copy domain parameters a and b to optimized domain parameter struct.
     *
     * NOTE: This is done in two steps via imports to/exports from the PKC RAM
     *       because no ordinary memory copy with endianess reversal exists. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_T0, pEccWeierBasicDomainParams->pA, byteLenP, operandSize);
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pCurveParam1, ECC_T0, byteLenP);
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pCurveParam2, WEIER_B, byteLenP);

    /* Export base point coordinates to optimized domain parameter struct. */
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pGx, ECC_S0, byteLenP);
    MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pGy, ECC_S1, byteLenP);

    MCUX_CSSL_FP_BRANCH_DECL(generatePrecomputedPointSecondBranch);
    if (MCUXCLECC_OPTION_GENERATEPRECPOINT_YES == (options & MCUXCLECC_OPTION_GENERATEPRECPOINT_MASK))
    {
        /* Optionally, export prec point coordinates to optimized domain parameter struct. */
        MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pPrecPoints, WEIER_X0, byteLenP);
        MCUXCLPKC_FP_EXPORTLITTLEENDIANFROMPKC_DI_BALANCED(pDomainParams->common.pPrecPoints + byteLenP, WEIER_Y0, byteLenP);

        MCUX_CSSL_FP_BRANCH_POSITIVE(generatePrecomputedPointSecondBranch,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ExportLittleEndianFromPkc));
    }
    else if (MCUXCLECC_OPTION_GENERATEPRECPOINT_NO != (options & MCUXCLECC_OPTION_GENERATEPRECPOINT_MASK))
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    /* Import order n from input buffer and output buffer, compare to check if there are equal */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER_DI_BALANCED(ECC_T0, pEccWeierBasicDomainParams->pN, byteLenN, operandSize);
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(ECC_T1, pDomainParams->common.pFullModulusN + MCUXCLPKC_WORDSIZE, byteLenN, operandSize);

    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T0, ECC_T1);
    uint32_t zeroFlag_checkN = MCUXCLPKC_WAITFORFINISH_GETZERO();

    if (MCUXCLPKC_FLAG_ZERO == zeroFlag_checkN)
    {
        /**********************************************************/
        /* Clean up                                               */
        /**********************************************************/
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUXCLSESSION_EXIT(pSession, mcuxClEcc_WeierECC_GenerateDomainParams, diRefValue, MCUXCLECC_STATUS_OK, MCUXCLECC_STATUS_FAULT_ATTACK,
            MCUXCLECC_FP_WEIERECC_GENERATEDOMAINPARAMS_FINAL(options),
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(generatePrecomputedPointBranch, MCUXCLECC_OPTION_GENERATEPRECPOINT_YES == (options & MCUXCLECC_OPTION_GENERATEPRECPOINT_MASK)),
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(generatePrecomputedPointSecondBranch, MCUXCLECC_OPTION_GENERATEPRECPOINT_YES == (options & MCUXCLECC_OPTION_GENERATEPRECPOINT_MASK)));
    }
    MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
}
