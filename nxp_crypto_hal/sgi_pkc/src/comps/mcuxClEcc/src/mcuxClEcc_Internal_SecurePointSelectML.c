/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_SecurePointSelect.c
 * @brief SecurePointSelect function
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal.h>

#include <mcuxClCore_Platform.h>

/**
 * This macro securely loads ofsP0 and ofsP1 from pOps[] table.
 * When b = "the bit at bitOffset of (scalarW0 XOR scalarW1)" = 0,
 * it returns ofsP0 = pOps_[iAccLadderCoords + 1] || pOps_[iAccLadderCoords], and
 *            ofsP1 = pOps_[iAccLadderCoords + 3] || pOps_[iAccLadderCoords + 2];
 * when b = 1,
 * it returns ofsP0 = pOps_[iAccLadderCoords + 3] || pOps_[iAccLadderCoords + 2], and
 *            ofsP1 = pOps_[iAccLadderCoords + 1] || pOps_[iAccLadderCoords].
 */
#if defined(__RISCV32)

#define CREATE_ROR_TEMP  \
    uint32_t temp3
#define ALLOCATE_ROR_TEMP  \
    , [tmp3] "=&r" (temp3)
#define ROTATE_RIGHT(dest, src, bitsToRotate, tmp) \
    "neg   "#tmp", "#bitsToRotate"\n"\
    "sll   "#tmp", "#src", "#tmp"\n"\
    "srl   "#dest", "#src", "#bitsToRotate"\n"\
    "or    "#dest", "#dest", "#tmp"\n"

#define MCUXCLECC_SECUREPOINTSELECT(ofsP0_, ofsP1_, pOps_, iAccLadderCoords, scalarW0_, scalarW1_, randomWord_, bitOffset_)  \
    do{  \
        uint32_t temp0;  \
        uint32_t temp1 = (bitOffset_);  \
        uint32_t temp2 = (randomWord_);  \
        uint32_t offsetX0 = ((iAccLadderCoords) * 2u);  \
        CREATE_ROR_TEMP;  \
        __asm volatile (  \
            "addi  %[tmp1], %[tmp1], -2\n"\
            ROTATE_RIGHT(%[tmp0], %[s0], %[tmp1], %[tmp3])  /* t0 = ( s0 .... ) ||  b0 || .. */\
            "andi  %[tmp2], %[tmp2], -5\n"                  /* t2 = ( rand .. ) ||   0 || .. */\
            "xor   %[tmp0], %[tmp0], %[tmp2]\n"             /* t0 = ( s0^rand ) ||  b0 || .. */\
            ROTATE_RIGHT(%[tmp1], %[s1], %[tmp1], %[tmp3])  /* t1 = ( s1 .... ) ||  b1 || .. */\
            "xor   %[tmp0], %[tmp0], %[tmp1]\n"             /* t0 = ( s^rand  ) ||   b || .. */\
            "or    %[tmp0], %[tmp0], %[tmp2]\n"             /* t0 = ( s|rand  ) ||   b || .. */\
            "sub   %[tmp1], %[pOps], %[tmp2]\n"\
            "addi  %[tmp2], %[tmp2], 4\n"                   /* t2 = ( rand .. ) ||   1 || .. */\
            "and   %[tmp2], %[tmp2], %[tmp0]\n"             /* t2 = ( rand .. ) ||   b || .. */\
            "add   %[tmp1], %[tmp1], %[ofsX0]\n"\
            "add   %[tmp0], %[tmp1], %[tmp2]\n"             /* update address offset */\
            "lw    %[tmp0], 0(%[tmp0])\n"\
            "xori  %[tmp2], %[tmp2], 4\n"                   /* t2 = ( rand .. ) || 1-b || .. */\
            "add   %[tmp1], %[tmp1], %[tmp2]\n"             /* update address offset */\
            "lw    %[tmp1], 0(%[tmp1])\n"\
            : [tmp0] "=&r" (temp0),  \
              [tmp1] "+&r" (temp1),  \
              [tmp2] "+&r" (temp2)  \
              ALLOCATE_ROR_TEMP  \
            : [pOps]  "r" (pOps_),  \
              [s0]    "r" (scalarW0_),  \
              [s1]    "r" (scalarW1_),  \
              [ofsX0] "r" (offsetX0)  \
        );  \
        (ofsP0_) = temp0;  \
        (ofsP1_) = temp1;  \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#elif defined(ICCARM_ARMCC_GNUC)

#define MCUXCLECC_SECUREPOINTSELECT(ofsP0_, ofsP1_, pOps_, iAccLadderCoords, scalarW0_, scalarW1_, randomWord_, bitOffset_)  \
    do{  \
        uint32_t temp0;  \
        uint32_t temp1 = (bitOffset_);  \
        uint32_t temp2 = (randomWord_);  \
        uint32_t offsetX0 = ((iAccLadderCoords) * 2u);  \
        __asm volatile (  \
            "SUBS  %[tmp1], %[tmp1], #2\n"\
            "ROR   %[tmp0], %[s0], %[tmp1]\n"    /* t0 = ( s0 .... ) ||  b0 || .. */\
            "BIC   %[tmp2], %[tmp2], #4\n"       /* t2 = ( rand .. ) ||   0 || .. */\
            "EORS  %[tmp0], %[tmp0], %[tmp2]\n"  /* t0 = ( s0^rand ) ||  b0 || .. */\
            "ROR   %[tmp1], %[s1], %[tmp1]\n"    /* t1 = ( s1 .... ) ||  b1 || .. */\
            "EORS  %[tmp0], %[tmp0], %[tmp1]\n"  /* t0 = ( s^rand  ) ||   b || .. */\
            "ORRS  %[tmp0], %[tmp0], %[tmp2]\n"  /* t0 = ( s|rand ) ||   b || .. */\
            "SUBS  %[tmp1], %[pOps], %[tmp2]\n"\
            "ADDS  %[tmp2], %[tmp2], #4\n"       /* t2 = ( rand .. ) ||   1 || .. */\
            "ADDS  %[tmp1], %[tmp1], %[ofsX0]\n"\
            "ANDS  %[tmp2], %[tmp2], %[tmp0]\n"  /* t2 = ( rand .. ) ||   b || .. */\
            "LDR   %[tmp0], [%[tmp1], %[tmp2]]\n"\
            "EOR   %[tmp2], %[tmp2], #4\n"       /* t2 = ( rand .. ) || 1-b || .. */\
            "LDR   %[tmp1], [%[tmp1], %[tmp2]]\n"\
            : [tmp0] "=&r" (temp0),  \
              [tmp1] "+&r" (temp1),  \
              [tmp2] "+&r" (temp2)  \
            : [pOps]  "r" (pOps_),  \
              [s0]    "r" (scalarW0_),  \
              [s1]    "r" (scalarW1_),  \
              [ofsX0] "r" (offsetX0)  \
            : "cc"  \
        );  \
        (ofsP0_) = temp0;  \
        (ofsP1_) = temp1;  \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#else
    #error Unsupported compiler. The above section must be manually adapted to support the inline assembly syntax.
#endif

 /**
 * Function for selecting points for montgomery ladder.
 *
 * Input:
 *  - maskedCurrentScalarWord    Currently processed scalar word (masked)
 *  - currentScalarWordMask      Currently processed scalar word mask
 *  - currentScalarBitInWord     Position of currently processed bit
 *  - iAccLadderCoords           Pointer table index of accumulated ladder coordinates
 *  - iVirtualCoords             Pointer table index of virtual points, which will point to coordinates of accumulated ladder point
 *
 * Result:
 * When b = "the bit at currentScalarBitInWord of (maskedCurrentScalarWord XOR currentScalarWordMask)" = 0,
 * it sets virtual pointers:
 *      pOperands[iVirtualCoords]   = pOperands[iAccLadderCoords],
 *      pOperands[iVirtualCoords+1] = pOperands[iAccLadderCoords+1],
 *      pOperands[iVirtualCoords+2] = pOperands[iAccLadderCoords+2],
 *      pOperands[iVirtualCoords+3] = pOperands[iAccLadderCoords+3],
 * when b = 1,
 * it sets virtual pointers
 *      pOperands[iVirtualCoords]   = pOperands[iAccLadderCoords+2],
 *      pOperands[iVirtualCoords+1] = pOperands[iAccLadderCoords+3],
 *      pOperands[iVirtualCoords+2] = pOperands[iAccLadderCoords],
 *      pOperands[iVirtualCoords+3] = pOperands[iAccLadderCoords+1],
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_SecurePointSelectML)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_SecurePointSelectML(uint32_t maskedCurrentScalarWord,
                                                              uint32_t currentScalarWordMask, uint32_t currentScalarBitInWord,
                                                              uint8_t iAccLadderCoords, uint8_t iVirtualCoords)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_SecurePointSelectML);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    MCUX_CSSL_FP_FUNCTION_CALL(randomMask, mcuxClPrng_generate_word());

    uint32_t offsetsP0;
    uint32_t offsetsP1;

    MCUXCLECC_SECUREPOINTSELECT(offsetsP0, offsetsP1, pOperands, (uint32_t) iAccLadderCoords,
                                maskedCurrentScalarWord, currentScalarWordMask, randomMask, currentScalarBitInWord);

    /* Write offsetsP0 and offsetsP1 to pOperands[iVirtualCoords] || pOperands[iVirtualCoords] and pOperands[iVirtualCoords+2] || pOperands[iVirtualCoords+3] */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, iVirtualCoords, offsetsP0);
    MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, (uint32_t) iVirtualCoords + 2u, offsetsP1);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_SecurePointSelectML, 
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word));
}
