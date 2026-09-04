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
 * @file  mcuxClEcc_TwEd_Internal_SecurePtrSelectComb.c
 * @brief Implementation of secure pointer selection for comb method on Twisted Edwards curves
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>

#include <mcuxClCore_Platform.h>

/*
 *         Create PPTable (Pre-computed Points Table) for secure point selection. This table contains uint64_t bit entries which hold
 *         the following PKC offsets in a packed form for later secure point selection:
 *
 *         Index | Entry
 *         -------------------------------------------------------
 *         0     | packOps64(PP_X7, PP_Y7, PP_T7, ECC_T3, ECC_T0)
 *         1     | packOps64(PP_X0, PP_Y0, PP_T0, ECC_T0, ECC_T3)
 *         2     | packOps64(PP_X6, PP_Y6, PP_T6, ECC_T3, ECC_T0)
 *         3     | packOps64(PP_X1, PP_Y1, PP_T1, ECC_T0, ECC_T3)
 *         4     | packOps64(PP_X5, PP_Y5, PP_T5, ECC_T3, ECC_T0)
 *         5     | packOps64(PP_X2, PP_Y2, PP_T2, ECC_T0, ECC_T3)
 *         6     | packOps64(PP_X4, PP_Y4, PP_T4, ECC_T3, ECC_T0)
 *         7     | packOps64(PP_X3, PP_Y3, PP_T3, ECC_T0, ECC_T3)
 *         8     | packOps64(PP_X3, PP_Y3, PP_T3, ECC_T3, ECC_T0)
 *         9     | packOps64(PP_X4, PP_Y4, PP_T4, ECC_T0, ECC_T3)
 *         10    | packOps64(PP_X2, PP_Y2, PP_T2, ECC_T3, ECC_T0)
 *         11    | packOps64(PP_X5, PP_Y5, PP_T5, ECC_T0, ECC_T3)
 *         12    | packOps64(PP_X1, PP_Y1, PP_T1, ECC_T3, ECC_T0)
 *         13    | packOps64(PP_X6, PP_Y6, PP_T6, ECC_T0, ECC_T3)
 *         14    | packOps64(PP_X0, PP_Y0, PP_T0, ECC_T3, ECC_T0)
 *         15    | packOps64(PP_X7, PP_Y7, PP_T7, ECC_T0, ECC_T3)
 *
 *         Here, packOps64(iX, iY, iT, iXNeg, iTNeg) is defined as follows
 *
 *              packOps64(iX, iY, iT, iXNeg, iTNeg) = (PKC_OFFSET(iX)    >> 3)       |
 *                                                    (PKC_OFFSET(iY)    >> 3) << 12 |
 *                                                    (PKC_OFFSET(iT)    >> 3) << 24 |
 *                                                    (PKC_OFFSET(iXNeg) >> 3) << 36 |
 *                                                    (PKC_OFFSET(iTNeg) >> 3) << 48
 *
 *         and PKC_OFFSET(idx) is the PKC offset of the PKC buffer corresponding to pointer table entry index idx.
 *
 * NOTE: For the sake of code saving, this packing assumes that the PKC word size is at least 64 bits, and the MSBit of
 *       PKC buffer offsets contained in the pointer table is zero.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_CreatePPTable)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_CreatePPTable(uint64_t *pPrecPointTable)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_CreatePPTable);

    uint32_t ppIdx = TWED_PP_X7;
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();

    for (uint32_t i = 0u; i < MCUXCLECC_TWED_PPTABLE_ENTRY_NUMS; i += 2u)
    {
        pPrecPointTable[i] = MCUXCLECC_TWED_PPTABLE_PACK_ENTRY(pOperands, (uint64_t)ppIdx, (uint64_t)ppIdx + 1u, (uint64_t)ppIdx + 2u, (uint64_t)ECC_T0, (uint64_t)ECC_T3);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("ppIdx start value is selected such way it will not overflow.")
        ppIdx -= 3u;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }
    ppIdx = TWED_PP_X0;
    for (uint32_t i = 1u; i < MCUXCLECC_TWED_PPTABLE_ENTRY_NUMS; i += 2u)
    {
        pPrecPointTable[i] = MCUXCLECC_TWED_PPTABLE_PACK_ENTRY(pOperands, (uint64_t)ppIdx, (uint64_t)ppIdx + 1u, (uint64_t)ppIdx + 2u, (uint64_t)ECC_T3, (uint64_t)ECC_T0);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("ppIdx start value is selected such way it will not overflow.")
        ppIdx += 3u;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_CreatePPTable);
}

#define MCUXCLECC_WRITEPKCOFFSET(ofsY_ofsX,maskVal) \
do { \
    /* UNUSED */ (void) (maskVal); \
    MCUXCLPKC_PS1_SETXY_REG(ofsY_ofsX); \
} while (false)


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_SecurePtrSelectComb)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_SecurePtrSelectComb(
    mcuxClEcc_TwEd_SecureFixScalarMult_CpuWa_t *pCpuWa,
    uint32_t scalarWord0,
    uint32_t scalarWord1,
    uint32_t scalarDigitOffset
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_SecurePtrSelectComb);

    /**
     *  Step 1: In a secure way, determine the masked PKC offsets of the pre-computed points
     *          which shall be used for the next double-and-add step.
     */

    /* No PKC SFR masking available. The prec point table mask can be set to zero. */
    pCpuWa->precPointTableMask = 0u;

    /* Determine the XOR-masked prec point table entry corresponding to the current scalar digit. */
    uint64_t maskedTableEntry = 0u;
    uint64_t *pPrecPointTableMask = &(pCpuWa->precPointTableMask);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_SecurePtrTableEntrySelect((uint8_t *) pCpuWa->precPointTable, scalarWord0, scalarWord1, scalarDigitOffset,
                MCUXCLECC_TWED_PPTABLE_ENTRY_SIZE_LOG2,
                MCUXCLECC_TWED_PPTABLE_INDEX_BITSIZE,
                (uint8_t *) pCpuWa->shuffleBuffer1, (uint8_t *) pCpuWa->shuffleBuffer2, (uint8_t *)&maskedTableEntry, (uint8_t *) pPrecPointTableMask));

    /* Unpack the masked prec point table entry to derive the XOR-masked
     *  - PKC offsets of prec point coordinates X,Y,T to be used in the upcoming double-and-add step
     *  - PKC offsets of the temp buffers which will be used to hold the negative values of X and T */
    uint16_t offsetMaskedX, offsetMaskedY, offsetMaskedT, offsetMaskedMinusX, offsetMaskedMinusT;
    MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY(maskedTableEntry, offsetMaskedX, offsetMaskedY, offsetMaskedT,
                            offsetMaskedMinusX, offsetMaskedMinusT);
    /* If no PKC SFR masking is available, no XOR-masking has actually been applied to the PKC offsets. */

    /* Determine PKC offsets of temp buffers ECC_T0,...,ECC_T3 for upcoming PKC operations. */
    uint16_t *pOperands   = MCUXCLPKC_GETUPTRT();
    uint16_t offsetT0     = pOperands[ECC_T0];
    uint16_t offsetT1     = pOperands[ECC_T1];
    uint16_t offsetT2     = pOperands[ECC_T2];
    uint16_t offsetT3     = pOperands[ECC_T3];

    /* Unpack the prec point table mask to obtain the XOR-masks corresponding to the masked PKC offsets derived above. */
    uint16_t offsetXMask, offsetYMask, offsetTMask, offsetMinusXMask, offsetMinusTMask;
    MCUXCLECC_TWED_PPTABLE_UNPACK_ENTRY(*pPrecPointTableMask, offsetXMask, offsetYMask, offsetTMask, offsetMinusXMask, offsetMinusTMask);
    /* If no PKC SFR masking is available, all masks are zero. */


    /**
     *  Step 2: In a secure way, use the above computed masked PKC offsets (and masks) to store
     *            - the X-coordinate of the pre-computed point to be used for the next double-and-add step in buffer ECC_T1
     *            - the T-coordinate of the pre-computed point to be used for the next double-and-add step in buffer ECC_T2
     *          shall be used for the next double-and-add step.
     */

    /* ECC_T3 = PKC_BUF(offsetMaskedX ^ offsetXMask) = X */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_WRITEPKCOFFSET(((uint32_t) offsetMaskedX << 16u), ((uint32_t) offsetXMask << 16u));
    MCUXCLPKC_PS1_SETZR(0u, offsetT3);
    MCUXCLPKC_PS1_SETMODE(MCUXCLPKC_OP_OR_CONST);
    MCUXCLPKC_PS1_START_L0();

    /* ECC_T0 = -X mod p */
    MCUXCLPKC_FP_CALC_OP1_SUB(ECC_T0, ECC_P, ECC_T3);

    /* ECC_T1 = PKC_BUF(offsetMaskedMinusX ^ offsetMinusXMask)
     *        = X or -X mod p (depending on whether the "positive" or "negative" prec point shall be used during double-and-add step. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_WRITEPKCOFFSET(((uint32_t) offsetMaskedMinusX << 16u), ((uint32_t) offsetMinusXMask << 16u));
    MCUXCLPKC_PS1_SETZR(0u, offsetT1);
    MCUXCLPKC_PS1_SETMODE(MCUXCLPKC_OP_OR_CONST);
    MCUXCLPKC_PS1_START_L0();

    /* ECC_T0 = PKC_BUF(offsetMaskedT ^ offsetTMask) = T */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_WRITEPKCOFFSET((uint32_t) offsetMaskedT | ((uint32_t) offsetMaskedT << 16u), (uint32_t) offsetTMask | ((uint32_t) offsetTMask << 16u));
    MCUXCLPKC_PS1_SETZR(0u, offsetT0);
    MCUXCLPKC_PS1_START_L0();

    /* ECC_T3 = -T mod p */
    MCUXCLPKC_FP_CALC_OP1_SUB(ECC_T3, ECC_P, ECC_T0);

    /* ECC_T2 = PKC_BUF(offsetMaskedMinusT ^ offsetMinusTMask)
     *        = T or -T mod p (depending on whether the "positive" or "negative" prec point shall be used during double-and-add step. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_WRITEPKCOFFSET((uint32_t) offsetMaskedMinusT | ((uint32_t) offsetMaskedMinusT << 16u), (uint32_t) offsetMinusTMask | ((uint32_t) offsetMinusTMask << 16u));
    MCUXCLPKC_PS1_SETZR(0u, offsetT2);
    MCUXCLPKC_PS1_SETMODE(MCUXCLPKC_OP_OR_CONST);
    MCUXCLPKC_PS1_START_L0();

    /* Set virtual pointers TWED_PP_VX0, TWED_PP_VY0 and TWED_PP_VT0 */
    MCUXCLPKC_WAITFORREADY();
    pOperands[TWED_PP_VX0] = pOperands[ECC_T1];
    pOperands[TWED_PP_VT0] = pOperands[ECC_T2];
    pOperands[TWED_PP_VY0] = offsetMaskedY ^ offsetYMask;

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_SecurePtrSelectComb,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SecurePtrTableEntrySelect),
        MCUXCLPKC_FP_CALLED_CALC_OP1_SUB,
        MCUXCLPKC_FP_CALLED_CALC_OP1_SUB);
}
