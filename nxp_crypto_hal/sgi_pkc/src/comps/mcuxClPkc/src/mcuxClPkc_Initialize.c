/*--------------------------------------------------------------------------*/
/* Copyright 2014-2026 NXP                                                  */
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
 * @file  mcuxClPkc_Initialize.c
 * @brief PKC initialize and deinitialize functions
 */


#include <platform_specific_headers.h>
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClSession_Types.h>

#include <internal/mcuxClPkc_Internal_Types.h>
#include <internal/mcuxClPkc_Internal_Functions.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>



/**
 * @brief Get PKC CFG value
 *
 * This function returns the CFG value of PKC.
 *
 * @param[in] session Handle for the current CL session.
 *
 * @return pkcCfg  PKC CFG that will be returned
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_getCFGSettings)
static MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClPkc_getCFGSettings(mcuxClSession_Handle_t session)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_getCFGSettings);
    /* Configure PKC CFG with default when there is no session->securityOptions. */
    const uint32_t pkcCfg =   MCUXCLPKC_SFR_BITMSK(CFG, IDLEOP)
                            | MCUXCLPKC_SFR_BITMSK(CFG, CLKRND)
                            | MCUXCLPKC_SFR_CFG_RNDDLY_NODLY;
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPkc_getCFGSettings, pkcCfg);
}


/**
 * [Design]
 * This function initializes PKC hardware in the following steps:
 * (0) clear SFR Mask on supported platforms;
 * (1) if PKC is in STOP, clear STOP bit according to PKC specification;
 * (2) if PKC is not in RESET, wait any on-going calculation;
 * (3) initialize and set PKC according to PKC specification.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_Initialize, mcuxClPkc_PkcInitializeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_Initialize(mcuxClSession_Handle_t session)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_Initialize);

    /* Clear SFR Mask, on supported platforms. */
    MCUXCLPKC_CLEARSFRMASK();

    /* Clear STOP bit if it has been set. */
    uint32_t pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);
    if (0u != (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, STOP)))
    {
        MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl & (~ MCUXCLPKC_SFR_BITMSK(CTRL, STOP)));

        /* Poll the STOP bit until it is cleared. */
        do
        {
            pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);
        } while(0u != (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, STOP)));
    }

    /* Wait any on-going calculation and then set RESET bit, if RESET bit is not set. */
    if (0u == (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, RESET)))
    {
        MCUXCLPKC_WAITFORFINISH();

        /* Set PKC RESET bit. */
        MCUXCLPKC_SFR_WRITE(CTRL, MCUXCLPKC_SFR_BITMSK(CTRL, RESET));

        /* Poll the RESET bit until it is set. */
        while (0u == (MCUXCLPKC_SFR_BITREAD(CTRL, RESET)))
        {}
    }

    /* Configure PKC. */
    MCUX_CSSL_FP_FUNCTION_CALL(pkcCfg, mcuxClPkc_getCFGSettings(session));
    MCUXCLPKC_SFR_WRITE(CFG, pkcCfg);


    /* Configure PKC and clear RESET bit. */
    const uint32_t pkcCtrl = MCUXCLPKC_SFR_BITMSK(CTRL, CLRCACHE)
                             | MCUXCLPKC_SFR_BITMSK(CTRL, CACHE_EN)
                             | MCUXCLPKC_SFR_CTRL_REDMUL_FULLSZ;
    MCUXCLPKC_SFR_WRITE(CTRL, pkcCtrl);

    /* Poll the RESET bit until it is cleared. */
    while (0u != (MCUXCLPKC_SFR_BITREAD(CTRL, RESET)))
    {}

    /* Poll the PW_READY bit until it is set, on supported platforms. */
    MCUXCLPKC_PKC_WAIT_PW_READY();

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_Initialize,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_getCFGSettings));
}


/**
 * [Design]
 * This function deinitializes PKC hardware in the following steps:
 * (0) clear SFR Mask on supported platforms;
 * (1) if PKC is in STOP, clear STOP bit according to PKC specification;
 * (2) if PKC is not in RESET, wait any on-going calculation, and then set PKC RESET bit;
 * (3) clear PKC SFRs;
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_Deinitialize, mcuxClPkc_PkcDeInitializeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_Deinitialize(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_Deinitialize);

    /* Clear SFR Mask, on supported platforms. */
    MCUXCLPKC_CLEARSFRMASK();

    /* Clear STOP bit if it has been set. */
    uint32_t pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);
    if (0u != (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, STOP)))
    {
        MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl & (~ MCUXCLPKC_SFR_BITMSK(CTRL, STOP)));

        /* Poll the STOP bit until it is cleared. */
        do
        {
            pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);
        } while(0u != (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, STOP)));
    }

    /* Wait any on-going calculation and then set RESET bit, if RESET bit is not set. */
    if (0u == (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, RESET)))
    {
        MCUXCLPKC_WAITFORFINISH();

        /* Set PKC RESET bit. */
        MCUXCLPKC_SFR_WRITE(CTRL, MCUXCLPKC_SFR_BITMSK(CTRL, RESET));

        /* Poll the RESET bit until it is set. */
        while (0u == (MCUXCLPKC_SFR_BITREAD(CTRL, RESET)))
        {}
    }

    /* Clear SFRs. */
    MCUXCLPKC_SFR_WRITE(MODE1,  0u);
    MCUXCLPKC_SFR_WRITE(XYPTR1, 0u);
    MCUXCLPKC_SFR_WRITE(ZRPTR1, 0u);
    MCUXCLPKC_SFR_WRITE(LEN1,   0u);
    MCUXCLPKC_SFR_WRITE(MODE2,  0u);
    MCUXCLPKC_SFR_WRITE(XYPTR2, 0u);
    MCUXCLPKC_SFR_WRITE(ZRPTR2, 0u);
    MCUXCLPKC_SFR_WRITE(LEN2,   0u);
    MCUXCLPKC_SFR_WRITE(UPTR,   0u);
    MCUXCLPKC_SFR_WRITE(UPTRT,  0u);
    MCUXCLPKC_SFR_WRITE(ULEN,   0u);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_Deinitialize);
}
