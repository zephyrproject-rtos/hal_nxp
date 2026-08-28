/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClMath_ModInv.c
 * @brief mcuxClMath: modular inversion implementation
 */


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClMath_Internal_ModInv.h>
#include <internal/mcuxClMath_ModInv_FUP.h>
#include <internal/mcuxClMath_Internal_Types.h>
#include <internal/mcuxClMath_Internal_Functions.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_ModInv)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ModInv(mcuxClSession_Handle_t pSession, uint32_t iR_iX_iN_iT, uint32_t flagCoprime)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_ModInv);

    const uint32_t backupPs1LenReg = MCUXCLPKC_PS1_GETLENGTH_REG();
    uint32_t operandSize = MCUXCLPKC_PS1_UNPACK_OPLEN(backupPs1LenReg);
    operandSize &= ~((uint32_t) MCUXCLPKC_WORDSIZE - 1u);  /* round down to a multiple of MCUXCLPKC_WORDSIZE, to calculate exponent correctly. */

    /* ASSERT: operandSize (PS1 LEN) is valid, and operands (of length = operandSize + MCUXCLPKC_WORDSIZE) are within PKC workarea. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(operandSize, MCUXCLPKC_WORDSIZE, MCUXCLPKC_RAM_SIZE - MCUXCLPKC_WORDSIZE)

    /* Prepare local UPTRT. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting 32-bit pointer to 16-bit pointer is 16-bit aligned")
    uint16_t * const pOperands = (uint16_t*)pSession->pMathUptrt;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    const uint16_t *pBackupPtrUptrt;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMath_InitLocalUptrt(iR_iX_iN_iT, 0u, pOperands, 4u, &pBackupPtrUptrt));

    const uint16_t offsetT = pOperands[MODINV_T];
    /* ASSERT: operand T (length >= operandSize + MCUXCLPKC_WORDSIZE) is within PKC workarea. */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(offsetT, MCUXCLPKC_RAM_OFFSET_MIN, MCUXCLPKC_RAM_OFFSET_MAX - (2u * MCUXCLPKC_WORDSIZE))

    /* WAITFORREADY in mcuxClMath_InitLocalUptrt(...). */
    pOperands[MODINV_T1] = (uint16_t) (offsetT + MCUXCLPKC_WORDSIZE);
    pOperands[MODINV_CONST1] = 0x0001u;
    pOperands[MODINV_CONST0] = 0x0000u;

    /* WAITFORREADY in mcuxClMath_InitLocalUptrt(...). */
    MCUXCLPKC_PS1_SETLENGTH((uint32_t)31u * (uint32_t)MCUXCLPKC_WORDSIZE, operandSize);  /* Loop counter = 31 for MCUXCLPKC_MC_MI. */
    MCUXCLPKC_PS2_SETLENGTH_REG(operandSize + MCUXCLPKC_WORDSIZE);   /* MCLEN on higher 16 bits is not used. */

    if (MCUXCLMATH_XN_COPRIME == flagCoprime)
    {
        /* X and N are coprime */
        MCUXCLPKC_FP_CALCFUP(mcuxClMath_ModInv_Fup1, mcuxClMath_ModInv_Fup1_LEN);
    }
    else
    {
        /* X and N are not coprime */
        MCUXCLPKC_FP_CALCFUP(mcuxClMath_ModInv_Fup2a, mcuxClMath_ModInv_Fup2a_LEN);

        MCUXCLPKC_WAITFORREADY();
        MCUXCLPKC_PS2_SETLENGTH(operandSize, operandSize);
        MCUXCLPKC_FP_CALCFUP(mcuxClMath_ModInv_Fup2b, mcuxClMath_ModInv_Fup2b_LEN);
    }

    const volatile uint32_t *pExp = (volatile uint32_t *) MCUXCLPKC_OFFSET2PTRWORD(offsetT);
    volatile uint32_t *pR = (volatile uint32_t *) MCUXCLPKC_OFFSET2PTRWORD(pOperands[MODINV_R]);

    MCUXCLPKC_WAITFORFINISH();
    MCUXCLPKC_PS1_SETLENGTH_REG(backupPs1LenReg);
    uint32_t exponent = *pExp;
    uint32_t operandBitLen = operandSize << 3;
    const mcuxClPkc_FUPEntry_t* mcuxClMath_ModInv_Fup3;

    MCUX_CSSL_FP_BRANCH_DECL(fup3Branch);
    if (exponent <= operandBitLen)
    {
        exponent = operandBitLen - exponent;
        mcuxClMath_ModInv_Fup3 = mcuxClMath_ModInv_Fup3a;
        MCUX_CSSL_FP_BRANCH_POSITIVE(fup3Branch);
    }
    else
    {
        exponent = (operandBitLen * 2u) - exponent;
        mcuxClMath_ModInv_Fup3 = mcuxClMath_ModInv_Fup3b;
        MCUX_CSSL_FP_BRANCH_NEGATIVE(fup3Branch);
    }

    /* Set R = 2^(operandBitLEn - exponent) or 2^(2*operandBitLEn - exponent). */
    pR[exponent >> 5] = (uint32_t) 1u << (exponent & 0x0000001Fu);
    MCUX_CSSL_FP_COUNTER_STMT(uint32_t exponentBitLen = *pExp);

    /* Convert AlmostMontgomeryInverse to modular inverse. */
    MCUXCLPKC_FP_CALCFUP(mcuxClMath_ModInv_Fup3, mcuxClMath_ModInv_Fup3_LEN);

    /* Restore pUptrt. */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_SETUPTRT(pBackupPtrUptrt);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMath_ModInv,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),   /* Fup1 or Fup2a */
        MCUX_CSSL_FP_CONDITIONAL(MCUXCLMATH_XN_COPRIME != flagCoprime, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)), /* Fup2b */
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(fup3Branch, exponentBitLen <= operandBitLen),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(fup3Branch, exponentBitLen > operandBitLen),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));  /* Fup3a or Fup3b */
}
