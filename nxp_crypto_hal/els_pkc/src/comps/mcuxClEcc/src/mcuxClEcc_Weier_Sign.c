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
 * @file  mcuxClEcc_Weier_Sign.c
 * @brief Weierstrass curve ECDSA signature generation API
 */


#include <stdint.h>
#include <stddef.h>

#include <mcuxClPkc.h>
#include <mcuxClMath.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClBuffer.h>
#include <mcuxClEcc.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClEcc_Internal_Random.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_ECDSA_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_BlindedFixScalarMult)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Weier_BlindedFixScalarMult(
        mcuxClSession_Handle_t pSession,
        const mcuxClEcc_Sign_Param_t * pParam,
        uint32_t *pK1NoOfTrailingZeros,
        mcuxClEcc_ECDSA_KeyGenCtx_t *pKeyGenCtx)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_BlindedFixScalarMult);

    uint32_t *pOperands32 = MCUXCLPKC_GETUPTRT32();

    const uint32_t byteLenP = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenP_mask) >> mcuxClEcc_DomainParam_misc_byteLenP_offset;
    const uint32_t byteLenN = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenN_mask) >> mcuxClEcc_DomainParam_misc_byteLenN_offset;
    /**********************************************************/
    /* Import and check base point G                          */
    /**********************************************************/
    /* Import G to (X1,Y1). */  /* TODO: create a function to import and check point. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Weier_BlindedFixScalarMult, WEIER_X1, pParam->curveParam.pG, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFEROFFSET(mcuxClEcc_Weier_BlindedFixScalarMult, WEIER_Y1, pParam->curveParam.pG, byteLenP, byteLenP);

    /* Check G in (X1,Y1) affine NR. */
//      MCUXCLPKC_WAITFORREADY();  <== there is WaitForFinish in import function.
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_X1, WEIER_Y1);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_BlindedFixScalarMult, MCUXCLECC_STATUS_INVALID_PARAMS,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));

    }
    else if (MCUXCLECC_STATUS_OK != pointCheckStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_BlindedFixScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    /**********************************************************/
    /* Generate multiplicative split ephemeral key k0 and k1, */
    /* k = k0 * k1 mod n, where k0 is a 64-bit odd number     */
    /**********************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL(ret_BlindedSecretKeyGen, pParam->pMode->pBlindedEphemeralKeyGenFct(pSession, pParam, pKeyGenCtx));
    if (MCUXCLECC_STATUS_OK != ret_BlindedSecretKeyGen)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_BlindedFixScalarMult, ret_BlindedSecretKeyGen);
    }

    /**********************************************************/
    /* Calculate Q = k1 * (k0 * G)                            */
    /**********************************************************/

    /* Convert coordinates of G to Montgomery representation. */
    MCUXCLPKC_FP_CALC_MC1_MM(WEIER_X0, WEIER_X1, ECC_PQSQR, ECC_P);
    MCUXCLPKC_FP_CALC_MC1_MM(WEIER_Y0, WEIER_Y1, ECC_PQSQR, ECC_P);
    MCUXCLPKC_FP_CALC_OP1_NEG(WEIER_Z, ECC_P);  /* 1 in MR */
    /* G will be randomized (projective coordinate randomization) in SecurePointMult. */

    /* Calculate Q0 = k0 * G. */
    MCUX_CSSL_FP_FUNCTION_CALL(securePointMultStatusFirst, mcuxClEcc_SecurePointMult(pSession, ECC_S0, 64u));
   if(MCUXCLECC_STATUS_RNG_ERROR == securePointMultStatusFirst)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_RNG_ERROR);
    }
    else if(MCUXCLECC_STATUS_OK != securePointMultStatusFirst)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    /* In case k1 is even, perform scalar multiplication k1 * Q0 by computing (n - k1) * (-Q0)
     * as this avoids the exceptional case k1 = n-1. scalar modification will need to be reverted later on
     */
    MCUX_CSSL_FP_BRANCH_DECL(scalarEvenBranch);
    MCUXCLPKC_FP_CALC_OP1_LSB0s(ECC_S1);
    *pK1NoOfTrailingZeros = MCUXCLPKC_WAITFORFINISH_GETZERO();
    if(MCUXCLPKC_FLAG_NONZERO == *pK1NoOfTrailingZeros)
    {
        MCUXCLPKC_FP_CALC_OP1_SUB(ECC_S1, ECC_N, ECC_S1);
        MCUXCLPKC_FP_CALC_MC1_MS(WEIER_Y0, ECC_PS, WEIER_Y0, ECC_PS);

        MCUX_CSSL_FP_BRANCH_POSITIVE(scalarEvenBranch,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);
    }

    /* Calculate Q = k1 * Q0. */
    MCUX_CSSL_FP_FUNCTION_CALL(securePointMultStatusSecond, mcuxClEcc_SecurePointMult(pSession, ECC_S1, byteLenN * 8u));
    if(MCUXCLECC_STATUS_RNG_ERROR == securePointMultStatusSecond)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_RNG_ERROR);
    }
    else if(MCUXCLECC_STATUS_OK != securePointMultStatusSecond)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }
    MCUX_CSSL_FP_EXPECT(MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarEvenBranch, MCUXCLPKC_FLAG_NONZERO == *pK1NoOfTrailingZeros));

    /**********************************************************/
    /* Convert Q to affine coordinates and check              */
    /**********************************************************/

    /* T0 = ModInv(Z), where Z = (z * 256^LEN) \equiv z in MR. */
    MCUXCLMATH_FP_MODINV(ECC_T0, WEIER_Z, ECC_P, ECC_T1);
    /* T0 = z^(-1) * 256^(-LEN) \equiv z^(-1) * 256^(-2LEN) in MR. */

    /* Convert Q to affine coordinates. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine,
                        mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine_LEN);

    /* Check Q in (XA,YA) affine NR. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_COPY_2OFFSETS(pOperands32, WEIER_VX0, WEIER_VY0, WEIER_XA, WEIER_YA);
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckQStatus, mcuxClEcc_PointCheckAffineNR());
    if (MCUXCLECC_STATUS_OK != pointCheckQStatus)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_BlindedFixScalarMult, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_BlindedFixScalarMult, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFEROFFSET,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR),
        pParam->pMode->pBlindedEphemeralKeyGenFct_FP_FuncId,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUXCLPKC_FP_CALLED_CALC_OP1_NEG,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult),
        MCUXCLPKC_FP_CALLED_CALC_OP1_LSB0s,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePointMult),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ModInv),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_PointCheckAffineNR));
}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Sign)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Sign(
        mcuxClSession_Handle_t pSession,
        const mcuxClEcc_Sign_Param_t * pParam)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Sign);

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/

    /* mcuxClEcc_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
    mcuxClEcc_CpuWa_t * const pCpuWorkarea = mcuxClEcc_castToEccCpuWorkarea(mcuxClSession_getCpuWaBuffer(pSession));

    uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, 0u);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_SetupEnvironment,
        mcuxClEcc_Weier_SetupEnvironment(pSession,
                                        & pParam->curveParam,
                                        ECC_SIGN_NO_OF_BUFFERS) );
    if (MCUXCLECC_STATUS_OK != ret_SetupEnvironment)
    {
        if (MCUXCLECC_STATUS_INVALID_PARAMS == ret_SetupEnvironment)
        {
            /* Session has been cleaned, PKC has been deinitialized in SetupEnvironment. */
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_INVALID_PARAMS,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_SetupEnvironment) );
        }

        MCUXCLECC_HANDLE_HW_UNAVAILABLE(ret_SetupEnvironment, mcuxClEcc_Sign);
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Randomize buffers XA/YA/ZA/Z/X0/Y0/X1/Y1. */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_FP_FUNCTION_CALL(retRandomUptrt,
                              mcuxClPkc_RandomizeUPTRT(pSession,
                                                      &pOperands[WEIER_XA],
                                                      (WEIER_Y1 - WEIER_XA + 1u)) );
    if (MCUXCLPKC_STATUS_OK != retRandomUptrt)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_RNG_ERROR);
    }

    MCUXCLMATH_FP_QSQUARED(ECC_NQSQR, ECC_NS, ECC_N, ECC_T0);

    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;

    const uint32_t byteLenP = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenP_mask) >> mcuxClEcc_DomainParam_misc_byteLenP_offset;
    const uint32_t byteLenN = (pParam->curveParam.misc & mcuxClEcc_DomainParam_misc_byteLenN_mask) >> mcuxClEcc_DomainParam_misc_byteLenN_offset;

    mcuxClEcc_ECDSA_KeyGenCtx_t *pKeyGenCtx = mcuxClEcc_castToECDSAKeyGenCtx(mcuxClSession_allocateWords_cpuWa(pSession, pParam->pMode->keyGenCtxSizeInWords));
    if(NULL == pKeyGenCtx)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pKeyGenCtx, pParam->pMode->keyGenCtxSizeInWords); /* make sure state is cleared */

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("There is enough space in the cpu workarea to hold the key context, it cannot be wrapped.")
    pCpuWorkarea->wordNumCpuWa += pParam->pMode->keyGenCtxSizeInWords;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Main loop of signature generation until both r and s are nonzero. */
    uint32_t fail_r = 0u;
    uint32_t fail_s = 0u;
    MCUX_CSSL_FP_LOOP_DECL(MainLoop_R);
    MCUX_CSSL_FP_LOOP_DECL(MainLoop_S);
    do
    {
        uint32_t k1NoOfTrailingZeros = 0u;
        MCUX_CSSL_FP_FUNCTION_CALL(ret_publicPointCalc, mcuxClEcc_Weier_BlindedFixScalarMult(pSession, pParam, &k1NoOfTrailingZeros, pKeyGenCtx));

        if(MCUXCLECC_STATUS_OK != ret_publicPointCalc)
        {
            /* Cleanup / SC balacning in error scenarios (excluding FAULT_ATTACK) is done to simplify error checking. */
            if((0u == fail_r) && (0u == fail_s) && (MCUXCLECC_STATUS_FAULT_ATTACK != ret_publicPointCalc))
            {
                mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
                MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
                    mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);

                mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, ret_publicPointCalc,
                    MCUXCLECC_FP_SIGN_BEFORE_LOOP,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_Weier_BlindedFixScalarMult),
                    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
            }
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);
        }

        /**********************************************************/
        /* Calculate r = Q.x mod n, and check if r is zero        */
        /**********************************************************/
        MCUX_CSSL_FP_LOOP_ITERATION(MainLoop_R, MCUXCLECC_FP_SIGN_LOOP_R);
        MCUXCLPKC_FP_CALC_MC1_MS(WEIER_XA, WEIER_XA, ECC_N, ECC_N);  /* Hasse's theorem: Abs(n - (p+1)) <= 2 * sqrt(p). */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Numer of fail is used to balanced FP, it cannot be wrapped.")
        fail_r += MCUXCLPKC_WAITFORFINISH_GETZERO();
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_GETZERO())
        {
            continue;
        }

        /**********************************************************/
        /* Securely import private key                            */
        /**********************************************************/

        MCUX_CSSL_FP_FUNCTION_CALL(ret_SecImport,
            mcuxClPkc_SecureImportBigEndianToPkc(pSession, MCUXCLPKC_PACKARGS2(WEIER_ZA, ECC_T0),
                                                pParam->pPrivateKey, byteLenN) );
        if (MCUXCLPKC_STATUS_OK != ret_SecImport)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);
        }

        /* Generate random number d1 (to blind the private key). */
        {
            uint8_t * const ptrZ = MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_Z]);
            MCUXCLBUFFER_INIT(buffZ, NULL, ptrZ, operandSize);
            MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
            MCUX_CSSL_FP_FUNCTION_CALL(ret_PRNG_GetRandom, mcuxClRandom_ncGenerate(pSession, buffZ, operandSize));
            if (MCUXCLRANDOM_STATUS_OK != ret_PRNG_GetRandom)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_RNG_ERROR);
            }
        }  /* buffZ scope */


        /**********************************************************/
        /* Import message hash, and truncate if longer than n     */
        /**********************************************************/

        /* Import message hash (up to byteLenN bytes). */
        uint32_t byteLenHash = (pParam->optLen & mcuxClEcc_Sign_Param_optLen_byteLenHash_mask) >> mcuxClEcc_Sign_Param_optLen_byteLenHash_offset;
        uint32_t byteLenHashImport = MCUXCLCORE_MIN(byteLenHash, byteLenN);
        MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Sign, ECC_S2, pParam->pHash, byteLenHashImport);

        /* Truncate message hash if its bit length is longer than that of n. */
        if (byteLenHash >= byteLenN)
        {
            /* Count leading zeros in MSByte of n. */
            const volatile uint8_t * ptrN = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
            uint8_t nMSByte = ptrN[byteLenN - 1u];
            uint32_t nMSByte_LeadZeros = (uint32_t) mcuxClMath_CountLeadingZerosWord((uint32_t) nMSByte) - (8u * ((sizeof(uint32_t)) - 1u));

            /* Only keep the first bitLenN bits of hash. */
            MCUXCLPKC_FP_CALC_OP1_SHR(ECC_S2, ECC_S2, (uint8_t)(nMSByte_LeadZeros & 0xFFU));
        }

        MCUX_CSSL_FP_LOOP_ITERATION(MainLoop_S,
            MCUX_CSSL_FP_CONDITIONAL((byteLenHash >= byteLenN),
                MCUXCLPKC_FP_CALLED_CALC_OP1_SHR ),
            MCUXCLECC_FP_SIGN_LOOP_S );


        /**********************************************************/
        /* Securely calculate signature s, and check if s is zero */
        /**********************************************************/
        /* Revert scalar modification by computing n-k1 in place again before calculating signature s */
        if(MCUXCLPKC_FLAG_NONZERO == k1NoOfTrailingZeros)
        {
            MCUXCLPKC_FP_CALC_OP1_SUB(ECC_S1, ECC_N, ECC_S1);
            MCUX_CSSL_FP_EXPECT(MCUXCLPKC_FP_CALLED_CALC_OP1_SUB);
        }
        /* Now, XA = r,  S2 = z (hash of message);   */
        /*      S0 = k0, S1 = k1, k = k0 * k1 mod n; */
        /*      ZA = d,  Z  = d1.                    */
        /* s = k^(-1) * (z + r * d) = (k0*k1)^(-1) * (z + r * (d0-d1)) mod n. */

        /* T1 = s'  = k1*(z+r*d) * R^(-2) mod n <= n; */
        /* T2 = k0' = (k*k1) * R^(-3) mod n.          */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_Sign_CalculateS,
                            mcuxClEcc_FUP_Weier_Sign_CalculateS_LEN);

        /* T0 = h0 = ModInv(k0') = (k*k1)^(-1) * R^3 mod n. */
        MCUXCLMATH_FP_MODINV(ECC_T0, ECC_T2, ECC_N, ECC_T3);

        /* YA = s = h0 * s' - n mod n < n. */
        /* MM(h0, s') < 2n because s' <= n. */
        MCUXCLPKC_FP_CALC_MC1_MM(WEIER_YA, ECC_T0, ECC_T1, ECC_N);
        MCUXCLPKC_FP_CALC_MC1_MS(WEIER_YA, WEIER_YA, ECC_N, ECC_N);

        fail_s += MCUXCLPKC_WAITFORFINISH_GETZERO();

    } while(MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_GETZERO());


    /**********************************************************/
    /* Check n and p and export signature r and s             */
    /**********************************************************/

    /* Import prime p and order n again, and check (compare with) existing one. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Sign, ECC_T0, pParam->curveParam.pP, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Sign, ECC_T1, pParam->curveParam.pN, byteLenN);

    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T0, ECC_P);
    uint32_t zeroFlag_checkP = MCUXCLPKC_WAITFORFINISH_GETZERO();

    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T1, ECC_N);
    uint32_t zeroFlag_checkN = MCUXCLPKC_WAITFORFINISH_GETZERO();

    if (   (zeroFlag_checkP == MCUXCLPKC_FLAG_ZERO)
        && (zeroFlag_checkN == MCUXCLPKC_FLAG_ZERO) )
    {
        MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFER(mcuxClEcc_Sign, pParam->pSignature, WEIER_XA, byteLenN);
        MCUXCLPKC_FP_EXPORTBIGENDIANFROMPKC_BUFFEROFFSET(mcuxClEcc_Sign, pParam->pSignature, WEIER_YA, byteLenN, byteLenN);

        /* Clear PKC workarea. */
        MCUXCLPKC_PS1_SETLENGTH(0u, bufferSize * ECC_SIGN_NO_OF_BUFFERS);
        pOperands[ECC_P] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea);
        MCUXCLPKC_FP_CALC_OP1_CONST(ECC_P, 0u);

        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClEcc_Sign, MCUXCLECC_STATUS_OK, MCUXCLECC_STATUS_FAULT_ATTACK,
            MCUXCLECC_FP_SIGN_BEFORE_LOOP,
            MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_R, fail_r + fail_s + 1u),
            MCUX_CSSL_FP_LOOP_ITERATIONS(MainLoop_S, fail_s + 1u),
            MCUXCLECC_FP_SIGN_FINAL);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Sign, MCUXCLECC_STATUS_FAULT_ATTACK);
}


