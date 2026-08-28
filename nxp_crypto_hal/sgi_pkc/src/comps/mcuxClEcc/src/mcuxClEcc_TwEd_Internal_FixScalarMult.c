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
 * @file  mcuxClEcc_TwEd_Internal_FixScalarMult.c
 * @brief EdDSA internal function for (secure) scalar multiplication with the base point
 */


#include <mcuxClSession.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClSession_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>
#include <internal/mcuxClEcc_Internal_Random.h>


/**
 * This function imports the affine coordinates (xi,yi), i=0,...,7, of the pre-computed points to the PKC workarea and converts
 * them to randomized extended homogeneous coordinates (Xi:Yi:Zi:Ti) = (xi*Z:yi*Z:Z:xi*yi*Z) in MR and in range [0,p-1].
 *
 * Input:
 *  - pDomainParams  Pointer to common ECC domain parameters
 *
 * Prerequisites:
 *  - The coordinates xi and yi are stored in MR (in LE format) concatenated at pDomainParams->pPrecPoints
 *  - TWED_PP_Z contains the random Z-coordinate in MR in range [0,p-1]
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *
 * Result:
 *  - Buffers TWED_PP_Xi, TWED_PP_Yi, TWED_PP_Ti contain the coordinates Xi, Yi and Ti in MR
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_ImportAndConvertPrecPoints)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_ImportAndConvertPrecPoints(
    mcuxClEcc_CommonDomainParams_t *pDomainParams
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_ImportAndConvertPrecPoints);
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint32_t byteLenP = (uint32_t) pDomainParams->byteLenP;
    const uint8_t *pPrecPoints = pDomainParams->pPrecPoints;

    MCUX_CSSL_FP_LOOP_DECL(loop);
    for(uint32_t i = 0u; i < MCUXCLECC_TWED_FIXSCALARMULT_NOOFPRECPOINTS; i++)
    {
        /* Step 1: Copy the coordinates x and y to the buffers buf(iDst) and buf(iDst+1). */
        uint32_t iDstX = TWED_PP_X0 + ((TWED_PP_X1 - TWED_PP_X0) * i);
        uint32_t iDstY = TWED_PP_Y0 + ((TWED_PP_Y1 - TWED_PP_Y0) * i);
        uint8_t *pDstX = MCUXCLPKC_OFFSET2PTR(pOperands[iDstX]);
        uint8_t *pDstY = MCUXCLPKC_OFFSET2PTR(pOperands[iDstY]);
        const uint8_t *pSrcX = (const uint8_t *) (pPrecPoints + (2u * i * byteLenP));
        const uint8_t *pSrcY = (const uint8_t *) (pPrecPoints + (2u * i * byteLenP) + byteLenP);
        MCUX_CSSL_DI_RECORD(mcuxClEcc_TwEd_ImportAndConvertPrecPoints, (uint32_t) pDstX + (uint32_t) pSrcX + byteLenP + (uint32_t) pDstY + (uint32_t) pSrcY + byteLenP);
        MCUXCLPKC_WAITFORFINISH();
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pDstX, pSrcX, byteLenP));
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pDstY, pSrcY, byteLenP));

        /* Step 2: Let pointer table pointers corresponding to TWED_V0, TWED_V1 and TWED_V2 point to buf(iDstX), buf(iDstY) and buf(iDstT). */
        uint32_t iDstT = TWED_PP_T0 + ((TWED_PP_T1 - TWED_PP_T0) * i);
        pOperands[TWED_V0] = (uint16_t) pOperands[iDstX];
        pOperands[TWED_V1] = (uint16_t) pOperands[iDstY];
        pOperands[TWED_V2] = (uint16_t) pOperands[iDstT];

        /* Step 3: Convert affine coordinates (x,y) to extended homogeneous coordinates (X,Y,T,Z) */
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_ConvertAffineToExtHom, mcuxClEcc_FUP_TwEd_ConvertAffineToExtHom_LEN);

        MCUX_CSSL_FP_LOOP_ITERATION(loop,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup))
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_ImportAndConvertPrecPoints,
        MCUX_CSSL_FP_LOOP_ITERATIONS(loop, MCUXCLECC_TWED_FIXSCALARMULT_NOOFPRECPOINTS));
}


/**
 * This function prepares the accumulated point and the pre-computed points for the upcoming scalar multiplication loop:
 *  - It initializes the accumulated point coordinates (X:Y:T:Z) stored in buffers TWED_X, TWED_Y, TWED_T, TWED_Z with
 *    (0:Z:Z:0) in MR, where
 *     - if MCUXCLECC_SCALARMULT_OPTION_SECURE is chosen, Z is a random in range [1,p-1]
 *     - if MCUXCLECC_SCALARMULT_OPTION_PLAIN is chosen, Z = 1
 *  - If MCUXCLECC_SCALARMULT_OPTION_SECURE is chosen, it shuffles the pre-computed point buffers in memory
 *  - It imports the affine coordinates (xi,yi), i=0,...,7, of the pre-computed points to the PKC workarea and converts
 *    them to randomized extended homogeneous coordinates (Xi:Yi:Zi:Ti) = (xi*Z:yi*Z:Z:xi*yi*Z) in MR and in range [0,p-1].
 *
 * Input:
 *  - pSession      Handle for the current CL session
 *  - pDomainParams Pointer to common ECC domain parameters
 *  - options       Options parameter
 *
 * Prerequisites:
 *  - The coordinates xi and yi are stored in MR (in LE format) concatenated at pDomainParams->pPrecPoints
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *
 * Result:
 *  - Buffers TWED_X, TWED_Y, TWED_T, TWED_Z contain the randomized coordinates (X:Y:T:Z) of the accumulated point in MR
 *  - Buffers TWED_PP_Xi, TWED_PP_Yi, TWED_PP_Ti contain the coordinates Xi, Yi and Ti in MR
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_InitAccumulatorAndPrecPoints)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_InitAccumulatorAndPrecPoints(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_CommonDomainParams_t *pDomainParams,
    uint32_t options
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_InitAccumulatorAndPrecPoints);

    /*
     * Step 1: Initialize the accumulated point P in buffers TWED_X, TWED_Y, TWED_Z and TWED_T with
     *         the coordinates of the neutral point given in extended homogeneous coordinates (0:Z:Z:0).
     *         If option
     *          - MCUXCLECC_SCALARMULT_OPTION_SECURE is chosen, Z is random value (!==) 0 modp (in MR).
     *          - MCUXCLECC_SCALARMULT_OPTION_PLAIN is chosen, Z = 1 (in MR).
     *         Initilize the common pre-computed point coordinate TWED_PP_Z with TWED_Z and,
     *         if MCUXCLECC_SCALARMULT_OPTION_SECURE is chosen, shuffle the pre-computed point buffers
     *         before their initialization.
     */
    MCUX_CSSL_FP_BRANCH_DECL(scalarMult1Branch);
    MCUX_CSSL_FP_BRANCH_DECL(scalarMult2Branch);
    if(MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options))
    {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_GenerateRandomModModulus(pSession, ECC_P, TWED_Z));
        uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_RandomizeUPTRT(&pOperands[TWED_PP_X0], (TWED_PP_T7 - TWED_PP_X0 + 1u)));

        MCUX_CSSL_FP_BRANCH_POSITIVE(scalarMult1Branch,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateRandomModModulus),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_RandomizeUPTRT));
    }
    else if (MCUXCLECC_SCALARMULT_OPTION_PLAIN == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options))
    {
        MCUXCLPKC_FP_CALC_OP1_NEG(TWED_Z, ECC_P);

        MCUX_CSSL_FP_BRANCH_POSITIVE(scalarMult2Branch, MCUXCLPKC_FP_CALLED_CALC_OP1_NEG);
    }
    else
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUXCLPKC_FP_CALC_OP1_CONST(TWED_X, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(TWED_Y, TWED_Z, 0u);
    MCUXCLPKC_FP_CALC_OP1_CONST(TWED_T, 0u);
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(TWED_PP_Z, TWED_Z, 0u);

    /*
     * Step 2: For each of the 8 pre-computed points Pi, i = 0,...,7:
     *          - import its x- and y-coordinates
     *          - convert them to extended homogeneous coordinates with random Z in MR and in range [0,p-1]
     *          - and store them in buffers TWED_PP_Xi TWED_PP_Yi and TWED_PP_Ti.
     */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_ImportAndConvertPrecPoints(pDomainParams));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_InitAccumulatorAndPrecPoints,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarMult1Branch,
            MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options)),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarMult2Branch,
            MCUXCLECC_SCALARMULT_OPTION_PLAIN == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options)),
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
        MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_ImportAndConvertPrecPoints));
}


/**
 * This function checks if a re-randomization is needed i.e. it checks if the number of remaining scalar multiplication iterations
 * is a (positive) multiple of 16. If this is the case, the function generates a random value in range [1,p-1] and uses it to re-randomize
 * the coordinates of the accumulated point (X:Y:T:Z) and the pre-computed points (PP_Xi:PP_Yi:PP_Ti:PP_Z). Also, it shuffles the
 * pre-computed point buffers in memory and updates the PPTable according to this.
 *
 * Data Integrity: If a re-randomization takes place, the function EXPUNGEs by 1.
 *
 * Input:
 *  - pSession              Handle for the current CL session
 *  - pCpuWa                Pointer to the CPU workarea specific to the TwE_FixScalarMult function which
 *                          amongst others contains a pointer to the pre-computed point table (PPTable)
 *  - currentDigitBitIndex  Current bit index of the scalar digit to be processed by the scalar multiplication loop
 *
 * Prerequisites:
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffers TWED_X, TWED_Y, TWED_T, TWED_Z contain the extended twisted Edwards coordinates
 *    (X:Y:T:Z) of the accumulated point in MR to be re-randomized by a fresh random value
 *  - Buffers TWED_PP_Xi, TWED_PP_Yi, TWED_PP_Ti, i = 0,...,7, and TWED_PP_Z contain the affine
 *    extended twisted Edwards coordinates (PP_Xi:PP_Yi:PP_Ti:PP_Z) of the pre-computed points
 *    in MR to be re-randomized by a fresh random value and to be re-shuffled
 *
 * Result: If a re-randomization is triggered,
 *  - Buffers TWED_X, TWED_Y, TWED_T and TWED_Z contain (X*Z':Y*Z':T*Z':Z*Z') in MR and buffers
 *    TWED_PP_Xi, TWED_PP_Yi, TWED_PP_Ti, i = 0,...,7, and TWED_PP_Z contain the coordinates
 *    (Z'*PP_Xi:Z'*PP_Yi:Z'*PP_Ti:Z'*PP_Z) in MR for a random value Z' in [1,p-1].
 *  - Buffers TWED_PP_Xi, TWED_PP_Yi, TWED_PP_Ti, i = 0,...,7 have been shuffled in memory
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_FixScalarMult_ReRandomizeIfNeeded)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_FixScalarMult_ReRandomizeIfNeeded(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t *pCpuWa,
    uint32_t currentDigitBitIndex)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_FixScalarMult_ReRandomizeIfNeeded);

    MCUX_CSSL_FP_BRANCH_DECL(currentDigitBranch);
    if ( (0u < currentDigitBitIndex) &&
         (0u == (currentDigitBitIndex & (MCUXCLECC_TWED_FIXSCALARMULT_POINT_RANDOMIZE_PER_BITS - 1u))))
    {
        uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
        uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_GenerateRandomModModulus(pSession, ECC_P, ECC_T0));

        /* Re-randomize the accumulated point's coordinates */
        MCUXCLPKC_WAITFORREADY();
        pOperands[TWED_V0] = pOperands[TWED_X];
        pOperands[TWED_V1] = pOperands[TWED_Y];
        pOperands[TWED_V2] = pOperands[TWED_T];
        pOperands[TWED_V3] = pOperands[TWED_Z];
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_UpdateExtHomCoords, mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_LEN);

        /* Re-randomize the pre-computed points' coordinates */
        MCUX_CSSL_FP_LOOP_DECL(loop);
        for (uint32_t i = 0u; i < MCUXCLECC_TWED_FIXSCALARMULT_NOOFPRECPOINTS; i++)
        {
            MCUXCLPKC_WAITFORREADY();
            pOperands[TWED_V0] = pOperands[TWED_PP_X0 + i * 3u];
            pOperands[TWED_V1] = pOperands[TWED_PP_Y0 + i * 3u];
            pOperands[TWED_V2] = pOperands[TWED_PP_T0 + i * 3u];
            pOperands[TWED_V3] = pOperands[TWED_PP_Z];
            MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_UpdateExtHomCoords, mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_XYT_LEN);

            MCUX_CSSL_FP_LOOP_ITERATION(loop,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
        }

        /* Only update Z */
        MCUXCLPKC_FP_CALCFUP_OFFSET(mcuxClEcc_FUP_TwEd_UpdateExtHomCoords, mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_XYT_LEN, mcuxClEcc_FUP_TwEd_UpdateExtHomCoords_Z_LEN);

        /* Shuffle the pre-computed points' buffers */
        MCUXCLPKC_WAITFORFINISH();
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_ReRandomizeUPTRT(&pOperands[TWED_PP_X0],
                                                            (uint16_t)operandSize,
                                                            (TWED_PP_T7 - TWED_PP_X0 + 1u)));

        /* Update the PPTable after UPTRT re-randomization.
            *
            * NOTE: The temp buffers ECC_T0,...,ECC_T3 were not shuffled, and don't need to be taken into account for the update */
        uint64_t *pPrecPointTable = pCpuWa->precPointTable;
        uint32_t ppIdx = TWED_PP_X7;
        for (uint32_t i = 0u; i < MCUXCLECC_TWED_PPTABLE_ENTRY_NUMS; i += 2u)
        {
            pPrecPointTable[i] = MCUXCLECC_TWED_PPTABLE_ENTRY_UPDATE(pPrecPointTable[i], pOperands, (uint64_t)ppIdx, (uint64_t)ppIdx + 1u, (uint64_t)ppIdx + 2u);
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("ppIdx start value is selected such way it will not overflow.")
            ppIdx -= 3u;
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        }
        ppIdx = TWED_PP_X0;
        for (uint32_t i = 1u; i < MCUXCLECC_TWED_PPTABLE_ENTRY_NUMS; i += 2u)
        {
            pPrecPointTable[i] = MCUXCLECC_TWED_PPTABLE_ENTRY_UPDATE(pPrecPointTable[i], pOperands, (uint64_t)ppIdx, (uint64_t)ppIdx + 1u, (uint64_t)ppIdx + 2u);
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("ppIdx start value is selected such way it will not overflow.")
            ppIdx += 3u;
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        }

        MCUX_CSSL_DI_EXPUNGE(SecureFixScalarMult_Loop_Shuffle, 1u);

        MCUX_CSSL_FP_BRANCH_POSITIVE(currentDigitBranch,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_GenerateRandomModModulus),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
            MCUX_CSSL_FP_LOOP_ITERATIONS(loop, MCUXCLECC_TWED_FIXSCALARMULT_NOOFPRECPOINTS),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ReRandomizeUPTRT));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_FixScalarMult_ReRandomizeIfNeeded,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(currentDigitBranch,
            (0u < currentDigitBitIndex) && (0u == (currentDigitBitIndex & (MCUXCLECC_TWED_FIXSCALARMULT_POINT_RANDOMIZE_PER_BITS - 1u)))));
}

/**
 * This function performs the scalar multiplication loop (Step 5 of the fixed scalar multiplication algorithm).
 * For i from (roundedScalarBitLength - 4) down to 0:
 *  - Call point doubling routine defined by pointDoubleFct to compute P = 2*P
 *  - Get digit (i3 i2 i1 i0)_2 at offset i in buf(iScalar), and set PP = P_((i3 i2 i1)_2 ^ (i0 i0 i0)_2 ^ (1 1 1)_2)
 *  - Call pointer selection routine specified by ptrSelectFct to set TWED_PP_VX0 to the buffer storing the X-coordinate of PP and
 *             - if i0 = 1, set TWED_PP_VY0 and TWED_PP_VT0 to the buffers storing the Y- and T-coordinates of PP.
 *             - if i0 = 0, set TWED_PP_VY0 and TWED_PP_VT0 to buffers ECC_T2 and ECC_T3 and store the negative Y- and T-coordinates of PP in buffers ECC_T2 and ECC_T3.
 *  - Call point addition routine defined by pointAddFct to compute P = P + PP
 *  - Periodically re-randomize if MCUXCLECC_SCALARMULT_OPTION_SECURE is chosen
 *
 * Input:
 *  - pSession              Handle for the current CL session
 *  - pCpuWa                Pointer to the CPU workarea (used in secure mode)
 *  - iScalar               Table index of secret scalar lambda
 *  - roundedScalarBitLength Scalar bit length rounded up to multiple of 4
 *  - scalarBitLength       Original bit length of the scalar
 *  - pointAddFct           Curve dependent function to perform point addition
 *  - pointDoubleFct        Curve dependent function to perform point doubling
 *  - options               MCUXCLECC_SCALARMULT_OPTION_SECURE or MCUXCLECC_SCALARMULT_OPTION_PLAIN
 *
 * Prerequisites:
 *  - Buffer buf(iScalar) contains the recoded and reordered scalar
 *  - Accumulated point initialized in TWED_X, TWED_Y, TWED_T, TWED_Z
 *  - Pre-computed points initialized in TWED_PP_Xi, TWED_PP_Yi, TWED_PP_Ti
 *
 * Result:
 *  - Buffers TWED_X, TWED_Y, TWED_T, TWED_Z contain the result of scalar multiplication
 *  - Data Integrity: Expunge((MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options) * scalarBitLength)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_FixScalarMult_Loop)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_FixScalarMult_Loop(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t *pCpuWa,
    const uint8_t iScalar,
    const uint32_t roundedScalarBitLength,
    const uint32_t scalarBitLength,
    mcuxClEcc_TwEd_PointAddFunction_t pointAddFct,
    mcuxClEcc_TwEd_PointDoubleFunction_t pointDoubleFct,
    const uint32_t options
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_FixScalarMult_Loop);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint32_t *pScalar = MCUXCLPKC_OFFSET2PTRWORD(pOperands[iScalar]);

    uint32_t currentDigitBitIndex = roundedScalarBitLength; /* roundedScalarBitLength is multiple of MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE, so index can be unsigned. */

    /* Record bit length to protect the loop. roundedScalarBitLength is for the while-loop (EXPUNGE(fixScalarMult)) and RECORD(-scalarBitLength) will EXPUNGE(scalarBitLength) */
    MCUX_CSSL_DI_RECORD(SecureFixScalarMult_Loop_BitLength, (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options) * (roundedScalarBitLength - scalarBitLength));

    /* If OPTION_SECURE is chosen: Record shuffle times to protect the loop
     *
     * NOTE: This RECORD will be expunged by the calls to mcuxClEcc_TwEd_FixScalarMult_ReRandomizeIfNeeded */
    if(MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options))
    {
        MCUX_CSSL_DI_RECORD(SecureFixScalarMult_Loop_Shuffle, (roundedScalarBitLength - 1u) / MCUXCLECC_TWED_FIXSCALARMULT_POINT_RANDOMIZE_PER_BITS);
    }

    uint32_t currentScalarWordMask = MCUXCLECC_RANDOM_WORD;
    uint32_t currentScalarWord = 0u;
    uint32_t maskedCurrentScalarWord = 0u;
    MCUX_CSSL_FP_LOOP_DECL(whileLoop);
    while(currentDigitBitIndex > 0u)
    {
        /* Update loop counter, deviation from the design to let iterate over unsigned value */
        currentDigitBitIndex -= MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE;

        /* Read next scalar word if needed. */
        uint32_t currentDigitInWordIndex  = currentDigitBitIndex % 32u;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The result does not wrap. The roundedScalarBitLength must coincide with the bit length of n rounded up to a multiple of 4.")

        MCUX_CSSL_FP_BRANCH_DECL(currentDigitBranch);
        if(((uint32_t)currentDigitBitIndex == (roundedScalarBitLength - 4u)) || (currentDigitInWordIndex  == (32u - MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE)))
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        {
            MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
            uint32_t currentScalarWordIndex = currentDigitBitIndex / 32u;
            currentScalarWord = pScalar[currentScalarWordIndex];
            MCUX_CSSL_FP_FUNCTION_CALL(prngGenerateWordRet, mcuxClPrng_generate_word());
            currentScalarWordMask = prngGenerateWordRet;
            maskedCurrentScalarWord = currentScalarWord ^ currentScalarWordMask;

            MCUX_CSSL_FP_BRANCH_POSITIVE(currentDigitBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word));
        }

        /* Call point doubling routine defined by pointDoubleFct to compute P = 2*P */
        (void)pointDoubleFct();

        /* Call pointer selection routine to set TWED_PP_VX0, TWED_PP_VY0 and TWED_PP_VT0
         * to the buffers storing the X-, Y- and T-coordinates of PP. */
        MCUX_CSSL_FP_BRANCH_DECL(scalarMult2Branch);
        MCUX_CSSL_FP_BRANCH_DECL(scalarMult3Branch);
        if (MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options))
        {
            /* SecureFixScalarMult_Loop_BitLength was recorded at function entry */
            MCUX_CSSL_DI_EXPUNGE(fixScalarMult, MCUXCLECC_SCALARMULT_OPTION_SECURE * MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE);
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_SecurePtrSelectComb(pCpuWa, maskedCurrentScalarWord, currentScalarWordMask, currentDigitInWordIndex));

            MCUX_CSSL_FP_BRANCH_POSITIVE(scalarMult2Branch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_SecurePtrSelectComb));
        }
        else if (MCUXCLECC_SCALARMULT_OPTION_PLAIN == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options))
        {
            /* SecureFixScalarMult_Loop_BitLength was recorded at function entry */
            MCUX_CSSL_DI_EXPUNGE(fixScalarMult, MCUXCLECC_SCALARMULT_OPTION_PLAIN * MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE);
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_PlainPtrSelectComb(pSession, currentScalarWord, (uint8_t)currentDigitInWordIndex));

            MCUX_CSSL_FP_BRANCH_POSITIVE(scalarMult3Branch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_PlainPtrSelectComb));
        }
        else
        {
            /* Do nothing */
        }

        /* Call point addition routine defined by pointAddFct to compute P = P + PP. */
        (void)pointAddFct();

        /*
         * Check if MCUXCLECC_SCALARMULT_OPTION_SECURE and if the number of remaining iterations is a (positive) multiple of 16.
         * If this is the case, shuffle the pre-computed points' buffers and re-randomize coordinates of accumulated and
         * pre-computed points.
         *
         * NOTE: If a re-randomization took place, the function EXPUNGEs by the increment 1. */
        MCUX_CSSL_FP_BRANCH_DECL(scalarMult4Branch);
        if ((MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options)))
        {
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_FixScalarMult_ReRandomizeIfNeeded(pSession, pCpuWa, currentDigitBitIndex));

            MCUX_CSSL_FP_BRANCH_POSITIVE(scalarMult4Branch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_FixScalarMult_ReRandomizeIfNeeded));
        }

        MCUX_CSSL_FP_LOOP_ITERATION(whileLoop,
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(currentDigitBranch,
                ((uint32_t)currentDigitBitIndex == (roundedScalarBitLength - 4u)) ||
                (currentDigitInWordIndex  == (32u - MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE))),
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarMult2Branch, MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options)),
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarMult3Branch, MCUXCLECC_SCALARMULT_OPTION_PLAIN == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options)),
            MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarMult4Branch, MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options)));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_FixScalarMult_Loop,
        MCUX_CSSL_FP_LOOP_ITERATIONS(whileLoop, roundedScalarBitLength / MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * This function implements a (secure) scalar multiplication lambda*G for a given (secret) scalar lambda in {0,...,n-1}
 * and the base point G on a twisted Edwards curves. The result will be returned in homogeneous coordinates (Xres:Yres:Zres).
 * The scalar multiplication is implemented using a regular comb method processing 4 bits at a time.
 * To achieve regularity, the scalar is recoded into a non-zero BSD representation and the comb
 * method is implemented by doing a double-and-add-or-subtract loop using pre-computed points
 *
 *      P_(i3 i2 i1)_2 = G_0 + (-1)^(1 - i1) * G1 + (-1)^(1-i2) * G2 + (-1)^(1-i3) * G3,
 *
 * where Gi = 2^(i*scalarBitLength/4), which are provided by the EdDSA Domain Parameters.
 * When called with MCUXCLECC_SCALARMULT_OPTION_SECURE option further side-channel attacks protection is added in
 * addition to MCUXCLECC_SCALARMULT_OPTION_PLAIN case.
 *
 * For the point arithmetic executed during the scalar multiplication iterations, extended homogeneous coordinates are used
 * as described in https://eprint.iacr.org/2008/522.pdf which represent a point (x,y) by (X:Y:Z:T) with x=X/Z, y=Y/Z and x*y=T/Z.
 * Due to the fact that with the chosen regular scalar multiplication algorithm we don't have consecutive doublings, there's no point
 * in mixing extended homogeneous with homogeneous coordinates as suggested in Section 4.3 of https://eprint.iacr.org/2008/522.pdf.
 *
 * The function also outputs the correct result, namely the neutral point, in case the input scalar is zero.
 *
 * Input:
 *  - pSession              Handle for the current CL session
 *  - pDomainParams         Pointer to ECC common domain parameters structure
 *  - iScalar               table index of secret scalar lambda
 *  - scalarBitLength       Bit length of the scalar; must coincide with the bit length of n
 *  - pointAddFct           Curve dependent function to perform point addition on twisted Edwards curve
 *  - pointDoubleFct        Curve dependent function to perform point doubling on twisted Edwards curve
 *  - options               Parameter to pass options. Possible options are MCUXCLECC_SCALARMULT_OPTION_SECURE and MCUXCLECC_SCALARMULT_OPTION_PLAIN.
 *
 * Prerequisites:
 *  - Buffer buf(iScalar) contains the secret scalar lambda of bit length scalarBitLength
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers ECC_CP0 and ECC_CP1 contain the curve parameters a and d in MR
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - Buffers TWED_X, TWED_Y and TWED_Z contain Xres, Yres and Zres in MR
 *
 * @attention The PKC calculation might be still on-going, call #mcuxClPkc_WaitForFinish before CPU accesses to the result.
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_FixScalarMult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_FixScalarMult(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_CommonDomainParams_t *pDomainParams,
    uint8_t iScalar,
    uint32_t scalarBitLength,
    mcuxClEcc_TwEd_PointAddFunction_t pointAddFct,
    mcuxClEcc_TwEd_PointDoubleFunction_t pointDoubleFct,
    uint32_t options
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_FixScalarMult);

    /* Determine pointer table pointer */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();

    /*
     * Step 1: Ensure that the scalar used subsequently is odd by negating it modulo n
     *
     * NOTE: As a prerequisite of this function, the passed scalarBitLength equals the bit length of n.
     *       Hence, scalarBitLength is also an appropriate scalar length for the negative scalar.
     */
    uint32_t *pScalar = MCUXCLPKC_OFFSET2PTRWORD(pOperands[iScalar]);
    MCUXCLPKC_WAITFORFINISH();
    const uint32_t scalarLsb = pScalar[0u] & 0x1u;

    MCUX_CSSL_FP_BRANCH_DECL(scalarLsbBranch);
    if(0u == scalarLsb)
    {
        MCUXCLPKC_FP_CALC_OP1_SUB(iScalar, ECC_N, iScalar);
        MCUX_CSSL_FP_BRANCH_POSITIVE(scalarLsbBranch, MCUXCLPKC_FP_CALLED_CALC_OP1_SUB);
    }

    /*
     * Step 2: Call function mcuxClEcc_RecodeAndReorderScalar to obtain the recoded
     *         and reordered secret scalar lambda' in buffer buf(iScalar).
     */

    /* Round scalar length up to the next multiple of f as this is required by the reordering and comb method. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(scalarBitLength, 0u, MCUXCLECC_WEIERECC_MAX_SIZE_BASEPOINTORDER*8u)
    uint32_t roundedScalarBitLength = MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE * ((scalarBitLength + (MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE - 1u)) / MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE);

    /* Recode and reorder scalar. */
     MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_RecodeAndReorderScalar(pSession, iScalar, MCUXCLECC_TWED_FIXSCALARMULT_DIGITSIZE, roundedScalarBitLength));

    /*
     * Step 3: Prepare the accumulated point and the pre-computed points for the upcoming scalar multiplication loop:
     *          - Initialize the accumulated point coordinates (X:Y:T:Z) in buffers TWED_X, TWED_Y, TWED_T, TWED_Z with (0:Z:Z:0) in MR, where
     *            - if MCUXCLECC_SCALARMULT_OPTION_SECURE is chosen, Z is a random in range [1,p-1]
     *            - if MCUXCLECC_SCALARMULT_OPTION_PLAIN is chosen, Z = 1
     *          - If MCUXCLECC_SCALARMULT_OPTION_SECURE is chosen, shuffle the pre-computed point buffers in memory (before their initialization)
     *          - Import the affine coordinates (xi,yi), i=0,...,7, of the pre-computed points to the PKC workarea and convert them to randomized
     *            extended homogeneous coordinates (Xi:Yi:Zi:Ti) = (xi*Z:yi*Z:Z:xi*yi*Z) in buffers TWED_PP_Xi, TWED_PP_Yi, TWED_PP_Ti and TWED_PP_Z
     *            in MR and in range [0,p-1].
     */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_InitAccumulatorAndPrecPoints(pSession, pDomainParams, options));

    /*
     * Step 4: If OPTION_SECURE is chosen:
     *         Create PPTable (Pre-computed Points Table) for secure point selection
     */
    mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t *pCpuWa = NULL;
    MCUX_CSSL_FP_BRANCH_DECL(scalarMultBranch);
    if (MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options))
    {
      MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pCpuWa64BitUnaligned, mcuxClSession_allocateWords_cpuWa(pSession, (uint32_t)((sizeof(mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t) + sizeof(uint32_t)) / sizeof(uint32_t))));

      uint32_t alignmentOffset = (((uint32_t)pCpuWa64BitUnaligned) % sizeof(uint64_t)) >> 2u;
      uint32_t* pCpuWa64BitAligned = &pCpuWa64BitUnaligned[alignmentOffset];
      pCpuWa = mcuxClEcc_TwEd_inline_PointerToCpuWa(pCpuWa64BitAligned);
      uint64_t* pPrecPointTable = pCpuWa->precPointTable;
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_CreatePPTable(pPrecPointTable));

      MCUX_CSSL_FP_BRANCH_POSITIVE(scalarMultBranch,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_CreatePPTable),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa));
    }

    /*
     * Step 5: Execute the scalar multiplication loop
     */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_TwEd_FixScalarMult_Loop(pSession, pCpuWa, iScalar, roundedScalarBitLength, scalarBitLength, pointAddFct, pointDoubleFct, options));

    /*
     * Step 6: Restore the original scalar and negate the resulting point if needed.
     */
    MCUX_CSSL_FP_BRANCH_DECL(scalarLsb2Branch);
    if(0u == scalarLsb)
    {
        MCUXCLPKC_FP_CALC_OP1_SUB(iScalar, ECC_N, iScalar);
        MCUXCLPKC_FP_CALC_MC1_MS(TWED_X, ECC_P, TWED_X, ECC_PS);

        MCUX_CSSL_FP_BRANCH_POSITIVE(scalarLsb2Branch,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB,
            MCUXCLPKC_FP_CALLED_CALC_MC1_MS);
    }

    /* If OPTION_SECURE is chosen: Free allocated workarea */
    if(MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options))
    {
        mcuxClSession_freeWords_cpuWa(pSession, (uint32_t) (sizeof(mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t) + sizeof(uint32_t)) / sizeof(uint32_t));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_FixScalarMult,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarLsbBranch, 0u == scalarLsb),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_RecodeAndReorderScalar),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_InitAccumulatorAndPrecPoints),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarMultBranch, MCUXCLECC_SCALARMULT_OPTION_SECURE == (MCUXCLECC_SCALARMULT_OPTION_SECURE_MASK & options)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_TwEd_FixScalarMult_Loop),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(scalarLsb2Branch, 0u == scalarLsb));
}
