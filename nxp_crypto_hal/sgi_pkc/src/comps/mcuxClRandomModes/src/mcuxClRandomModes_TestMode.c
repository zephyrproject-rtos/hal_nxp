/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

#include <mcuxClToolchain.h>
#include <mcuxClRandom.h>
#include <mcuxClRandomModes.h>
#include <mcuxClSession.h>
#include <mcuxClMemory.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClRandomModes_Functions_TestMode.h>

#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>
#include <internal/mcuxClRandomModes_Private_TestMode.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClRandomModes_Private_ExitGates.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRandom_OperationModeDescriptor_t mcuxClRandomModes_OperationModeDescriptor_TestMode_PrDisabled =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .initFunction                    = mcuxClRandomModes_TestMode_initFunction,
    .reseedFunction                  = mcuxClRandomModes_TestMode_reseedFunction,
    .generateFunction                = mcuxClRandomModes_NormalMode_generateFunction_PrDisabled,
    .selftestFunction                = mcuxClRandomModes_TestMode_selftestFunction,
    .protectionTokenInitFunction     = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_TestMode_initFunction,
    .protectionTokenReseedFunction   = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_TestMode_reseedFunction,
    .protectionTokenGenerateFunction = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_NormalMode_generateFunction_PrDisabled,
    .protectionTokenSelftestFunction = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_TestMode_selftestFunction,
    .operationMode                   = MCUXCLRANDOMMODES_TESTMODE,
};



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_createTestFromNormalMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_createTestFromNormalMode(mcuxClRandom_ModeDescriptor_t *pTestMode, mcuxClRandom_Mode_t normalMode, const uint32_t * const pCustomSeed)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_createTestFromNormalMode);

    MCUX_CSSL_ANALYSIS_START_CAST_TO_MORE_SPECIFIC_TYPE() /*For a normal mode, auxParam contains a pointer to mcuxClRandom_OperationModeDescriptor_t */
    pTestMode->pOperationMode   = (mcuxClRandom_OperationModeDescriptor_t *) normalMode->auxParam;
    MCUX_CSSL_ANALYSIS_STOP_CAST_TO_MORE_SPECIFIC_TYPE()
    pTestMode->pDrbgMode        = normalMode->pDrbgMode;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded because TestMode needs to update the custom seed hold in auxParam.")
    pTestMode->auxParam         = (uint32_t *) pCustomSeed;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
    pTestMode->contextSize      = normalMode->contextSize;
    pTestMode->securityStrength = normalMode->securityStrength;

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(
      mcuxClRandomModes_createTestFromNormalMode,
      MCUXCLRANDOM_STATUS_OK,
      MCUXCLRANDOM_STATUS_FAULT_ATTACK
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_updateEntropyInput)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_updateEntropyInput(mcuxClRandom_ModeDescriptor_t *pTestMode, const uint32_t * const pCustomSeed)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_updateEntropyInput);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded because TestMode needs to update the custom seed hold in auxParam.")
    pTestMode->auxParam         = (uint32_t *) pCustomSeed;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRandomModes_updateEntropyInput, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
}


/**
 * \brief This function instantiates a DRBG in TEST_MODE following the lines of the function Instantiate_function specified in NIST SP800-90A
 *
 * This function instantiates a DRBG in TEST_MODE following the lines of the function Instantiate_function specified in NIST SP800-90A.
 * The function reads entropy input and nonce for the DRBG seed from a buffer provided by the user of the CL.
 *
 * \param  session[in]          Handle for the current CL session
 * \param  mode[in]             Handle for the current Random Mode
 * \param  context[in]          Handle for the current Random Context
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_TestMode_initFunction, mcuxClRandom_initFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_TestMode_initFunction(
                    mcuxClSession_Handle_t pSession,
                    mcuxClRandom_Mode_t mode,
                    mcuxClRandom_Context_t context
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_TestMode_initFunction);

    mcuxClRandomModes_Context_Generic_t *pRngCtxGeneric = mcuxClRandomModes_castToContext_Generic(context);

    const mcuxClRandomModes_DrbgModeDescriptor_t *pDrbgMode = mcuxClRandomModes_castToDrbgModeDescriptor(mode->pDrbgMode);

    /* Initialize the reseedSeedOffset field of the context */
    pRngCtxGeneric->reseedSeedOffset = 0u;

    /* Request and init HW */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_CtrDrbg_requestHW(pSession));

    /* Derive the initial DRBG state from the user-defined entropy input and nonce. Return value is not checked, but instead forwarded to API. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pDrbgMode->pDrbgAlgorithms->instantiateAlgorithm(
                pSession,
                mode,
                context,
                (uint8_t *) mode->auxParam));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_cleanupOnExit(pSession));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_TestMode_initFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_CtrDrbg_requestHW),
        pDrbgMode->pDrbgAlgorithms->protectionTokenInstantiateAlgorithm,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_cleanupOnExit));
}


/**
 * \brief This function reseeds a DRBG in TEST_MODE following the lines of the function Reseed_function specified in NIST SP800-90A
 *
 * This function reseeds a DRBG in TEST_MODE following the lines of the function Reseed_function specified in NIST SP800-90A.
 * The function reads entropy input for the DRBG seed from a buffer provided by the user of the CL.
 *
 * \param  session[in]          Handle for the current CL session
 * \param  mode[in]             Handle for the current Random Mode
 * \param  context[in]          Handle for the current Random Context
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_TestMode_reseedFunction, mcuxClRandom_reseedFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_TestMode_reseedFunction(
                    mcuxClSession_Handle_t pSession,
                    mcuxClRandom_Mode_t mode,
                    mcuxClRandom_Context_t context
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_TestMode_reseedFunction);

    mcuxClRandomModes_Context_Generic_t *pRngCtxGeneric = mcuxClRandomModes_castToContext_Generic(context);

    const mcuxClRandomModes_DrbgModeDescriptor_t *pDrbgMode = mcuxClRandomModes_castToDrbgModeDescriptor(mode->pDrbgMode);

    /* Request and init HW */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_CtrDrbg_requestHW(pSession));


    /* Derive the initial DRBG state from the user-defined entropy input. Return value is not checked, but instead forwarded to API. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pDrbgMode->pDrbgAlgorithms->reseedAlgorithm(
                pSession,
                mode,
                context,
                (((uint8_t *) mode->auxParam) + pRngCtxGeneric->reseedSeedOffset)));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_cleanupOnExit(pSession));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_TestMode_reseedFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_CtrDrbg_requestHW),
        pDrbgMode->pDrbgAlgorithms->protectionTokenReseedAlgorithm,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_cleanupOnExit));

}

/**
 * \brief Empty function called during mcuxClRandom_selftest when TEST_MODE is activated
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_TestMode_selftestFunction, mcuxClRandom_selftestFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_TestMode_selftestFunction(mcuxClSession_Handle_t pSession UNUSED_PARAM, mcuxClRandom_Mode_t mode UNUSED_PARAM)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_TestMode_selftestFunction);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_TestMode_selftestFunction);
}
