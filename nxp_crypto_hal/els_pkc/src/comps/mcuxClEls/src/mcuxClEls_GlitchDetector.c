/*--------------------------------------------------------------------------*/
/* Copyright 2020-2022, 2024 NXP                                            */
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

/** @file  mcuxClEls_GlitchDetector.c
 *  @brief ELS implementation for key management.
 * This file implements the functions declared in mcuxClEls_GlitchDetector.h. */

#include <mcuxClEls_GlitchDetector.h>
#include <stdbool.h>
#include <mcuxClEls.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClEls_Internal.h>

#ifdef MCUXCL_FEATURE_ELS_GLITCHDETECTOR

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_GlitchDetector_LoadConfig_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_LoadConfig_Async(
    uint8_t const * pInput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_GlitchDetector_LoadConfig_Async);

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_GlitchDetector_LoadConfig_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }

    mcuxClEls_setInput0_fixedSize(pInput);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_GDET_CFG_LOAD, 0U, ELS_CMD_BIG_ENDIAN);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_GlitchDetector_LoadConfig_Async, MCUXCLELS_STATUS_OK_WAIT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_GlitchDetector_Trim_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_Trim_Async(
    uint8_t * pOutput)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_GlitchDetector_Trim_Async);

    /* ELS SFRs are not cached => Tell SW to wait for ELS to come back from BUSY state before modifying the SFRs */
    if (mcuxClEls_isBusy())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_GlitchDetector_Trim_Async, MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT);
    }

    mcuxClEls_setOutput_fixedSize(pOutput);
    mcuxClEls_startCommand(ID_CFG_ELS_CMD_GDET_TRIM, 0U, ELS_CMD_BIG_ENDIAN);


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_GlitchDetector_Trim_Async, MCUXCLELS_STATUS_OK_WAIT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_GlitchDetector_GetEventCounter)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_GetEventCounter(
    uint8_t * pCount)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_GlitchDetector_GetEventCounter);

    // Decode from Gray coding
    uint8_t count8 = (uint8_t) (MCUXCLELS_GET_GDET_EVTCNT_FIELD(MCUXCLELS_SFR_GDET_EVTCNT_GDET_EVTCNT) & 0xffU);
    count8 ^= count8 >> 4u;
    count8 ^= count8 >> 2u;
    count8 ^= count8 >> 1u;

    // Assign to the result variable
    *pCount = count8;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_GlitchDetector_GetEventCounter, MCUXCLELS_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEls_GlitchDetector_ResetEventCounter)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_ResetEventCounter(
    void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEls_GlitchDetector_ResetEventCounter);

    // Start GDET Event Counter reset
    MCUXCLELS_SFR_WRITE(ELS_GDET_EVTCNT_CLR, 1u);

    // The actual reset occurs in a different clock domain from the ELS core clock, so we have to wait for synchroni-
    // zation. The spec states that this takes on the order of 2 cycles of the ELS core clock plus 2 cycles of the
    // Glitch Detector reference clock.
    while(1u != MCUXCLELS_GET_GDET_EVTCNT_FIELD(MCUXCLELS_SFR_GDET_EVTCNT_GDET_EVTCNT_CLR_DONE))
    {
        // Do nothing
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEls_GlitchDetector_ResetEventCounter, MCUXCLELS_STATUS_OK);
}

#endif /* MCUXCL_FEATURE_ELS_GLITCHDETECTOR */
