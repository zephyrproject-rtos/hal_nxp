/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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
#include <mcuxCsslAnalysis.h>

#include <mcuxClRandomModes_Functions_TestMode.h>

#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>
#include <internal/mcuxClRandomModes_Private_PrDisabled.h>
#include <internal/mcuxClRandomModes_Private_NormalMode.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_HYPERLINK_IN_COMMENTS()
/**
 * \brief This function performs a selftest of a DRBG if prediction resistance is disabled
 *
 * This function performs a selftest of a DRBG if prediction resistance is disabled. More precisely, it implements a CAVP like known answer test as specified in
 *
 *   https://csrc.nist.gov/CSRC/media/Projects/Cryptographic-Algorithm-Validation-Program/documents/drbg/DRBGVS.pdf
 *
 * i.e. known answer tests for the following flow are executed
 *
 *    (initialize entropy input)
 *    init
 *    (update entropy input)
 *    reseed
 *    generate
 *    generate
 *    uninit
 *
 * @param [in]     pSession   Handle for the current CL session.
 * @param [in]     testCtx    Pointer to a Random data context buffer large enough
 *                            to hold the context for the selected @p pTestMode
 * @param [in]     pTestMode   Mode of operation for random data generator.
 *
 * \return
 *   - MCUXCLRANDOM_STATUS_OK              if the selftest finished successfully
 *   - MCUXCLRANDOM_STATUS_FAULT_ATTACK    if the selftest failed
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_HYPERLINK_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_PrDisabled_selftestAlgorithm, mcuxClRandomModes_selftestAlgorithm_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_PrDisabled_selftestAlgorithm(mcuxClSession_Handle_t pSession, mcuxClRandom_Context_t pTestCtx, mcuxClRandom_ModeDescriptor_t *pTestMode)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_PrDisabled_selftestAlgorithm);

    /* Set entropy input pointer in pTestMode */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    const mcuxClRandomModes_DrbgModeDescriptor_t *pDrbgMode = (const mcuxClRandomModes_DrbgModeDescriptor_t *) pTestMode->pDrbgMode;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    const uint32_t *const * testVectors = pDrbgMode->pDrbgTestVectors;
    MCUX_CSSL_FP_FUNCTION_CALL(ret_updateIn, mcuxClRandomModes_updateEntropyInput(pTestMode,
                testVectors[MCUXCLRANDOMMODES_TESTVECTORS_INDEX_ENTROPY_PRDISABLED]));
    (void)ret_updateIn;

    /***********************************************
    * Initialize DRBG with known entropy using     *
    * mcuxClRandom_init function                    *
    ************************************************/

    /* Call Random_init */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_init, mcuxClRandom_init(pSession, (mcuxClRandom_Context_t)pTestCtx, pTestMode));
    if(MCUXCLRANDOM_STATUS_OK != ret_init)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }


    /***********************************************
    * Reseed with known entropy using              *
    * mcuxClRandom_reseed function                  *
    ************************************************/

    /* Input new entropy to be used for reseeding by updating pTestMode */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_updateIn2, mcuxClRandomModes_updateEntropyInput(pTestMode,
                testVectors[MCUXCLRANDOMMODES_TESTVECTORS_INDEX_ENTROPY_RESEED_PRDISABLED]));
    (void)ret_updateIn2;

    MCUX_CSSL_FP_FUNCTION_CALL(ret_reseed, mcuxClRandom_reseed(pSession));
    /* Call Random_reseed */
    if(MCUXCLRANDOM_STATUS_OK != ret_reseed)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }


    /***********************************************
     * Generate first value using                  *
     * mcuxClRandom_generate function               *
     ***********************************************/

    uint32_t randomBytes[MCUXCLRANDOMMODES_SELFTEST_RANDOMDATALENGTH/sizeof(uint32_t)];
    MCUXCLBUFFER_INIT(pBufRandomBytes, NULL, (uint8_t*)randomBytes, MCUXCLRANDOMMODES_SELFTEST_RANDOMDATALENGTH);
    MCUX_CSSL_ANALYSIS_START_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
    MCUX_CSSL_FP_FUNCTION_CALL(ret_generate,
            mcuxClRandom_generate(pSession, pBufRandomBytes, MCUXCLRANDOMMODES_SELFTEST_RANDOMDATALENGTH));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
    if(MCUXCLRANDOM_STATUS_OK != ret_generate)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }


    /***********************************************
     * Generate second value using                 *
     * mcuxClRandom_generate function               *
     ***********************************************/
    MCUX_CSSL_ANALYSIS_START_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
    MCUX_CSSL_FP_FUNCTION_CALL(ret_generate2,
            mcuxClRandom_generate(pSession, pBufRandomBytes, MCUXCLRANDOMMODES_SELFTEST_RANDOMDATALENGTH));
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_ADDRESS_IN_SFR_IS_NOT_REUSED_OUTSIDE()
    if(MCUXCLRANDOM_STATUS_OK != ret_generate2)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    /* Verify generated random bytes */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_verifyOutput, mcuxClRandomModes_selftest_VerifyArrays(MCUXCLRANDOMMODES_SELFTEST_RANDOMDATALENGTH/(sizeof(uint32_t)),
                                                                  testVectors[MCUXCLRANDOMMODES_TESTVECTORS_INDEX_RANDOMDATA_PRDISABLED],
                                                                  randomBytes));
    if(MCUXCLRANDOM_STATUS_OK != ret_verifyOutput)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    /***********************************************
     * Clean up using mcuxClRandom_uninit function  *
     ***********************************************/

    uint32_t contextSizeInWords = pTestMode->contextSize / sizeof(uint32_t);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_uninit, mcuxClRandom_uninit(pSession));
    if(MCUXCLRANDOM_STATUS_OK != ret_uninit)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    /* Verify whether context is clear */
    for (uint32_t i = 0u; i < contextSizeInWords; i++)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("pTestCtx contains an integer array of size contextSizeInWords")
        if(((uint32_t *) pTestCtx)[i] != 0u)
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandomModes_PrDisabled_selftestAlgorithm, MCUXCLRANDOM_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_updateEntropyInput),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_updateEntropyInput),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_reseed),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_selftest_VerifyArrays),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_uninit) );
}
