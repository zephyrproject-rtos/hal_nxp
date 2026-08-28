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
#include <mcuxClSession_Types.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClRandomModes_MemoryConsumption.h>
#include <mcuxClRandomModes_Functions_TestMode.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>
#include <internal/mcuxClRandomModes_Private_NormalMode.h>
#include <internal/mcuxClTrng_Internal.h>
#include <internal/mcuxClRandomModes_Private_ExitGates.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRandom_OperationModeDescriptor_t mcuxClRandomModes_OperationModeDescriptor_NormalMode_PrDisabled = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .initFunction                    = mcuxClRandomModes_NormalMode_initFunction,
    .reseedFunction                  = mcuxClRandomModes_NormalMode_reseedFunction,
    .generateFunction                = mcuxClRandomModes_NormalMode_generateFunction_PrDisabled,
    .selftestFunction                = mcuxClRandomModes_NormalMode_selftestFunction,
    .protectionTokenInitFunction     = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_NormalMode_initFunction,
    .protectionTokenReseedFunction   = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_NormalMode_reseedFunction,
    .protectionTokenGenerateFunction = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_NormalMode_generateFunction_PrDisabled,
    .protectionTokenSelftestFunction = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_NormalMode_selftestFunction,
    .operationMode                   = MCUXCLRANDOMMODES_NORMALMODE,
};


/**
 * \brief This function instantiates a DRBG in NORMAL_MODE following the lines of the function Instantiate_function specified in NIST SP800-90A
 *
 * This function instantiates a DRBG in NORMAL_MODE following the lines of the function Instantiate_function specified in NIST SP800-90A.
 * The function obtains entropy input for the DRBG seed from the TRNG.
 *
 * \param  pSession[in]          Handle for the current CL session
 * \param  mode[in]              Handle for the current Random Mode
 * \param  context[in]           Handle for the current Random Context
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_NormalMode_initFunction, mcuxClRandom_initFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_NormalMode_initFunction(
                    mcuxClSession_Handle_t pSession,
                    mcuxClRandom_Mode_t mode,
                    mcuxClRandom_Context_t context
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_NormalMode_initFunction);

    const mcuxClRandomModes_DrbgModeDescriptor_t *pDrbgMode = mcuxClRandomModes_castToDrbgModeDescriptor(mode->pDrbgMode);

    /* Record entropyInputLength for mcuxClTrng_getEntropyInput() */
    MCUX_CSSL_DI_RECORD(trngOutputSize, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(pDrbgMode->pDrbgVariant->initSeedSize));

    /* Request and init HW */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_CtrDrbg_requestHW(pSession));

    mcuxClRandomModes_Context_Generic_t *pRngCtxGeneric = mcuxClRandomModes_castToContext_Generic(context);

    /* Initialize buffer in CPU workarea for the entropy input and nonce to derive the DRBG seed */
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pEntropyInputAndNonce, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(pDrbgMode->pDrbgVariant->initSeedSize)));

    /* Call TRNG initialization function to ensure it's properly configured for upcoming TRNG accesses */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClTrng_Init(pSession));

    /* Generate entropy input using the TRNG */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
      mcuxClTrng_getEntropyInput(pSession, pEntropyInputAndNonce, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(pDrbgMode->pDrbgVariant->initSeedSize))
      );

    /* Initialize the reseedSeedOffset field of the context */
    pRngCtxGeneric->reseedSeedOffset = 0u;

    /* Derive the initial DRBG state from the generated entropy input and nonce. Return value is not checked, but instead forwarded to API. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pDrbgMode->pDrbgAlgorithms->instantiateAlgorithm(
                pSession,
                mode,
                context,
                (uint8_t *) pEntropyInputAndNonce));

    /* Free workarea (pEntropyInputAndNonce) */
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(pDrbgMode->pDrbgVariant->initSeedSize));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_cleanupOnExit(pSession));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_NormalMode_initFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_CtrDrbg_requestHW),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_Init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_getEntropyInput),
        pDrbgMode->pDrbgAlgorithms->protectionTokenInstantiateAlgorithm,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_cleanupOnExit));
}


/**
 * \brief This function reseeds a DRBG in NORMAL_MODE following the lines of the function Reseed_function specified in NIST SP800-90A
 *
 * This function reseed a DRBG in NORMAL_MODE following the lines of the function Reseed_function specified in NIST SP800-90A.
 * The function obtains entropy input for the DRBG seed from the TRNG.
 *
 * \param  pSession[in]          Handle for the current CL session
 * \param  mode[in]              Handle for the current Random Mode
 * \param  context[in]           Handle for the current Random Context
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_NormalMode_reseedFunction, mcuxClRandom_reseedFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_NormalMode_reseedFunction(
                    mcuxClSession_Handle_t pSession,
                    mcuxClRandom_Mode_t mode,
                    mcuxClRandom_Context_t context
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_NormalMode_reseedFunction);

    const mcuxClRandomModes_DrbgModeDescriptor_t *pDrbgMode = mcuxClRandomModes_castToDrbgModeDescriptor(mode->pDrbgMode);

    /* Record entropyInputLength for mcuxClTrng_getEntropyInput() */
    MCUX_CSSL_DI_RECORD(trngOutputSize, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(pDrbgMode->pDrbgVariant->reseedSeedSize));

    /* Request and init HW */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_CtrDrbg_requestHW(pSession));

    /* Initialize buffer in CPU workarea for the entropy input to derive the DRBG seed */
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pEntropyInput, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(pDrbgMode->pDrbgVariant->reseedSeedSize)));

    /* Generate entropy input using the TRNG */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(
        mcuxClTrng_getEntropyInput(pSession, pEntropyInput, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(pDrbgMode->pDrbgVariant->reseedSeedSize))
        );

    /* Derive the initial DRBG state from the generated entropy input. Return value is not checked, but instead forwarded to API. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pDrbgMode->pDrbgAlgorithms->reseedAlgorithm(
                pSession,
                mode,
                context,
                (uint8_t *) pEntropyInput));

    /* Free workarea (pEntropyInputAndNonce) */
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(pDrbgMode->pDrbgVariant->reseedSeedSize));
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_cleanupOnExit(pSession));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_NormalMode_reseedFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_CtrDrbg_requestHW),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_getEntropyInput),
        pDrbgMode->pDrbgAlgorithms->protectionTokenReseedAlgorithm,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_cleanupOnExit));
}


/**
 * \brief This function generates random numbers from a DRBG in NORMAL_MODE following the lines of the function Generate_function specified in NIST SP800-90A
 * and reseeds according to the DRG.3 security level.
 *
 * This function generates random numbers from a DRBG in NORMAL_MODE following the lines of the function Generate_function specified in NIST SP800-90A.
 * If reseedCounter overflowed, the DRBG will be reseeded before the randomness generation.
 * If so, the function obtains entropy input for the DRBG seed from the TRNG.
 *
 * \param  pSession[in]         Handle for the current CL session
 * \param  mode[in]             Handle for the current Random Mode
 * \param  context[in]          Handle for the current Random Context
 * \param  pOut[out]            Output buffer to which the generated randomness will be written
 * \param  outLength[in]        Number of requested random bytes
 * \param  pXorMask[in]         Pointer to Boolean masking used for masking DRBG output (in CtrDrbg mode only)
 *
 * Data Integrity: Expunge(pSession + pOut + outLength + pXorMask)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_NormalMode_generateFunction_PrDisabled, mcuxClRandom_generateFunction_t)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_NormalMode_generateFunction_PrDisabled(
                    mcuxClSession_Handle_t pSession,
                    mcuxClRandom_Mode_t mode,
                    mcuxClRandom_Context_t context,
                    mcuxCl_Buffer_t pOut,
                    uint32_t outLength,
                    const uint32_t *pXorMask
)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_NormalMode_generateFunction_PrDisabled);

    mcuxClRandomModes_Context_Generic_t *pRngCtxGeneric = mcuxClRandomModes_castToContext_Generic(context);

    const mcuxClRandomModes_DrbgModeDescriptor_t *pDrbgMode = mcuxClRandomModes_castToDrbgModeDescriptor(mode->pDrbgMode);

    /* Bring the DI out of balance, to be balanced by caller. This is done before any potential exit. */
    MCUX_CSSL_DI_EXPUNGE(sumOfRandomGenerateParams, pSession);
    MCUX_CSSL_DI_EXPUNGE(sumOfRandomGenerateParams, pOut);
    MCUX_CSSL_DI_EXPUNGE(sumOfRandomGenerateParams, outLength);
    MCUX_CSSL_DI_EXPUNGE(sumOfRandomGenerateParams, pXorMask);

    /* NIST SP800-90A requests outLength to be limited by 2^19 bits, i.e. 2^16 Bytes. */
    if(MCUXCLRANDOMMODES_DRBG_OUTPUT_MAX < outLength)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLRANDOM_STATUS_INVALID_PARAM);
    }

    /* Reseed the DRBG state if the reseed counter overflowed */
    MCUX_CSSL_FP_COUNTER_STMT(uint64_t reseedCounterIfStmt = pRngCtxGeneric->reseedCounter);
    if (pRngCtxGeneric->reseedCounter >= pDrbgMode->pDrbgVariant->reseedInterval)
    {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mode->pOperationMode->reseedFunction(pSession, mode, context));
    }

    /* Request and init HW */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_CtrDrbg_requestHW(pSession));


    /* Generate random bytes. Return value is not checked, but instead forwarded to API. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pDrbgMode->pDrbgAlgorithms->generateAlgorithm(
                pSession,
                mode,
                context,
                pOut,
                outLength,
                pXorMask));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_cleanupOnExit(pSession));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_NormalMode_generateFunction_PrDisabled,
        MCUX_CSSL_FP_CONDITIONAL(reseedCounterIfStmt >= pDrbgMode->pDrbgVariant->reseedInterval,
            mode->pOperationMode->protectionTokenReseedFunction),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_CtrDrbg_requestHW),
        pDrbgMode->pDrbgAlgorithms->protectionTokenGenerateAlgorithm,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_cleanupOnExit));
}



/**
 * \brief This function performs a selftest of a DRBG in NORMAL_MODE
 *
 * The specific test pattern depends on the drbgMode.
 *
 * @param  pSession[in]    Handle for the current CL session
 * @param  mode[in]        Mode of operation for random data generator.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_NormalMode_selftestFunction, mcuxClRandom_selftestFunction_t)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_NormalMode_selftestFunction(mcuxClSession_Handle_t pSession, mcuxClRandom_Mode_t mode)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_NormalMode_selftestFunction);
    /* Back up Random configuration of current session */
    mcuxClRandom_Mode_t modeBackup = pSession->randomCfg.mode;
    mcuxClRandom_Context_t ctxBackup = pSession->randomCfg.ctx;

    /* Allocate space for new testMode */
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClRandom_ModeDescriptor_t*, pTestModeDesc, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRANDOMMODES_TESTMODE_DESCRIPTOR_SIZE)));

    /* Derive testMode from passed mode */
    MCUX_CSSL_FP_FUNCTION_CALL(result_create, mcuxClRandomModes_createTestFromNormalMode(pTestModeDesc, mode, NULL));
    if(result_create != MCUXCLRANDOM_STATUS_OK)
    {
        MCUXCLSESSION_FAULT(pSession, result_create);
    }

    /* Allocate space for pTestCtx according to the contextSize */
    /* pTestModeDesc->contextSize max value is MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE = 64 */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pTestModeDesc->contextSize, 0u, 64u, MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClRandom_Context_t, pTestCtx, mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(pTestModeDesc->contextSize)));

    const mcuxClRandomModes_DrbgModeDescriptor_t *pDrbgMode = mcuxClRandomModes_castToDrbgModeDescriptor(mode->pDrbgMode);

    /* Call function executing the DRBG mode specific selftest algorithm */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pDrbgMode has compatible type and cast was valid")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pDrbgMode->pDrbgAlgorithms->selftestAlgorithm(pSession, pTestCtx, pTestModeDesc));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

    /* Restore Random configuration of session */
    pSession->randomCfg.mode = modeBackup;
    pSession->randomCfg.ctx = ctxBackup;

    /* Free workarea (pTestModeDesc and pTestCtx) */
    /* pTestModeDesc->contextSize max value is MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE = 64 */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(pTestModeDesc->contextSize, 0u, 64u, MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRANDOMMODES_TESTMODE_DESCRIPTOR_SIZE) + MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(pTestModeDesc->contextSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_NormalMode_selftestFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_createTestFromNormalMode),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        pDrbgMode->pDrbgAlgorithms->protectionTokenSelftestAlgorithm);
}


/**
 * @brief This function performs a comparison of two arrays
 *
 * @param  wordLength[in]   Length of arrays to compare in word size
 * @param  expected[in]     Input buffer with expected value
 * @param  actual[in]       Input buffer with actual value, to be compared with expected value
 *
 * @note Function uses an early-exit mechanism with following return codes:
 *   - MCUXCLRANDOM_STATUS_FAULT_ATTACK    if the arrays are not equal
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_selftest_VerifyArrays)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_selftest_VerifyArrays(mcuxClSession_Handle_t pSession, uint32_t wordLength, const uint32_t * const expected, uint32_t *actual)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_selftest_VerifyArrays);

    MCUX_CSSL_FP_LOOP_DECL(forLoopVerify);
    for (uint32_t i = 0u; i < wordLength; i++)
    {
        if (expected[i] != actual[i])
        {
            MCUXCLSESSION_FAULT(pSession, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
        }
        MCUX_CSSL_FP_LOOP_ITERATION(forLoopVerify);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_selftest_VerifyArrays,
        MCUX_CSSL_FP_LOOP_ITERATIONS(forLoopVerify, wordLength));
}
