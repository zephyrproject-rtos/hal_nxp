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
 * @file  mcuxClPkc_Calculate.c
 * @brief PKC L0(OP)/L1(MC)/L2(FUP) calculation functions
 */


#include <platform_specific_headers.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClPkc_Internal_Types.h>
#include <internal/mcuxClPkc_Internal_Functions.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_Calc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_Calc(uint16_t param_mode, uint32_t iR_iX_iY_iZ)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_Calc);

    const volatile uint16_t * pUPTRT = MCUXCLPKC_GETUPTRT();

    uint32_t iZ = 0xFFu & iR_iX_iY_iZ;
    uint32_t iY = 0xFFu & (iR_iX_iY_iZ >> 8);
    uint32_t iX = 0xFFu & (iR_iX_iY_iZ >> 16);
    uint32_t iR = 0xFFu & (iR_iX_iY_iZ >> 24);

    uint16_t offsetZ = pUPTRT[iZ];
    uint16_t offsetY = pUPTRT[iY];
    uint16_t offsetX = pUPTRT[iX];
    uint16_t offsetR = pUPTRT[iR];

    /* Pre-calculate pkc_ctrl according to:                  */
    /* L0-PS1: param_mode = 0x00xy => PKC_CTRL_GOD1_Pos = 2; */
    /* L0-PS2: param_mode = 0x40xy => PKC_CTRL_GOD2_Pos = 3; */
    /* L1-PS1: param_mode = 0x80xy => PKC_CTRL_GOM1_Pos = 4; */
    /* L1-PS2: param_mode = 0xC0xy => PKC_CTRL_GOM2_Pos = 5. */
#if (  (MCUXCLPKC_SFR_BITPOS(CTRL, GOD1) != 2) | (MCUXCLPKC_SFR_BITPOS(CTRL, GOD2) != 3) \
     | (MCUXCLPKC_SFR_BITPOS(CTRL, GOM1) != 4) | (MCUXCLPKC_SFR_BITPOS(CTRL, GOM2) != 5) )
#error update implementation according to the PKC spec
#endif
    uint32_t pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL) | ((uint32_t) MCUXCLPKC_SFR_BITMSK(CTRL, GOD1) << (((uint32_t) param_mode >> 14u) & 0x3u));

    MCUXCLPKC_WAITFORREADY();
    MCUX_CSSL_FP_BRANCH_DECL(ps1ps2Branch);
    if (0U == ((uint32_t) param_mode & ((uint32_t) MCUXCLPKC_PARAM_PS2 << 8)))
    {
        MCUXCLPKC_PS1_SETMODE(param_mode);  /* Only mode in least significant 8 bits */
        MCUXCLPKC_PS1_SETXY(offsetX, offsetY);
        MCUXCLPKC_PS1_SETZR(offsetZ, offsetR);
        MCUX_CSSL_FP_BRANCH_POSITIVE(ps1ps2Branch);
    }
    else
    {
        MCUXCLPKC_PS2_SETMODE(param_mode);  /* Only mode in least significant 8 bits */
        MCUXCLPKC_PS2_SETXY(offsetX, offsetY);
        MCUXCLPKC_PS2_SETZR(offsetZ, offsetR);
        MCUX_CSSL_FP_BRANCH_NEGATIVE(ps1ps2Branch);
    }

    MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl);
    MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND();

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_Calc,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(ps1ps2Branch, 0U == ((uint32_t) param_mode & ((uint32_t) MCUXCLPKC_PARAM_PS2 << 8U))),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(ps1ps2Branch, 0U != ((uint32_t) param_mode & ((uint32_t) MCUXCLPKC_PARAM_PS2 << 8U))));
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_CalcConst)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_CalcConst(uint16_t param_mode, uint32_t iR_iX_iY_C)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_CalcConst);

    const volatile uint16_t * pUPTRT = MCUXCLPKC_GETUPTRT();

    uint32_t C  = 0xFFu & iR_iX_iY_C;
    uint32_t iY = 0xFFu & (iR_iX_iY_C >> 8);
    uint32_t iX = 0xFFu & (iR_iX_iY_C >> 16);
    uint32_t iR = 0xFFu & (iR_iX_iY_C >> 24);

    uint16_t offsetY = pUPTRT[iY];
    uint16_t offsetX = pUPTRT[iX];
    uint16_t offsetR = pUPTRT[iR];

    uint32_t pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);

    MCUXCLPKC_WAITFORREADY();
    MCUX_CSSL_FP_BRANCH_DECL(ps1ps2Branch);
    if (0U == ((uint32_t) param_mode & ((uint32_t) MCUXCLPKC_PARAM_PS2 << 8U)))
    {
        pkc_ctrl |= MCUXCLPKC_SFR_BITMSK(CTRL, GOD1);
        MCUXCLPKC_PS1_SETMODE(param_mode);  /* Only mode in least significant 8 bits */
        MCUXCLPKC_PS1_SETXY(offsetX, offsetY);
        MCUXCLPKC_PS1_SETZR(C, offsetR);
        MCUX_CSSL_FP_BRANCH_POSITIVE(ps1ps2Branch);
    }
    else
    {
        pkc_ctrl |= MCUXCLPKC_SFR_BITMSK(CTRL, GOD2);
        MCUXCLPKC_PS2_SETMODE(param_mode);  /* Only mode in least significant 8 bits */
        MCUXCLPKC_PS2_SETXY(offsetX, offsetY);
        MCUXCLPKC_PS2_SETZR(C, offsetR);
        MCUX_CSSL_FP_BRANCH_NEGATIVE(ps1ps2Branch);
    }

    MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl);
    MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND();

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_CalcConst,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(ps1ps2Branch, 0U == ((uint32_t) param_mode & ((uint32_t) MCUXCLPKC_PARAM_PS2 << 8U))),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(ps1ps2Branch, 0U != ((uint32_t) param_mode & ((uint32_t) MCUXCLPKC_PARAM_PS2 << 8U))));
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_CalcFup)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_CalcFup(mcuxClPkc_PtrFUPEntry_t pUPTR, uint8_t uLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_CalcFup);

    uint32_t pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL) | MCUXCLPKC_SFR_BITMSK(CTRL, GOU) | MCUXCLPKC_SFR_BITMSK(CTRL, CLRCACHE);
    MCUXCLPKC_WAITFORREADY();

    MCUXCLPKC_SFR_WRITE(UPTR, (uint32_t) pUPTR);
    MCUXCLPKC_SFR_WRITE(ULEN, (uint32_t) uLength);

    /* Clear PKC UPTRT cache and start calculation of the FUP program. */
    MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl);
    MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND();

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_CalcFup);
}
