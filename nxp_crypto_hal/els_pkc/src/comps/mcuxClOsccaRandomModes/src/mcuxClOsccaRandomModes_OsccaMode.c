/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClOsccaRandomModes_OsccaMode.c
 *  @brief Implementation of the Trng component which provides APIs for
 *  handling of Oscca Trng random number. This file implements the functions
 *  declared in mcuxClOsccaRandomModes_Functions.h. */

#include <mcuxClToolchain.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClSession.h>
#include <mcuxClRandom.h>
#include <mcuxClMemory.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClSession_Internal.h>
#include <mcuxClOsccaRandomModes.h>
#include <internal/mcuxClOsccaRandomModes_Private_RNG.h>
#include <internal/mcuxClOsccaRandomModes_Private_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaRandomModes_ROtrng_init, mcuxClRandom_initFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_init(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaRandomModes_ROtrng_reseed, mcuxClRandom_reseedFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_reseed(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode,
    mcuxClRandom_Context_t context
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaRandomModes_ROtrng_selftest, mcuxClRandom_selftestFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_selftest(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaRandomModes_ROtrng_generate, mcuxClRandom_generateFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_generate(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t    mode,
    mcuxClRandom_Context_t context,
    uint8_t *             pOut,
    uint32_t              outLength
);

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_init, mcuxClRandom_initFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_init(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    mcuxClRandom_Mode_t mode UNUSED_PARAM,
    mcuxClRandom_Context_t context
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_init);

    MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_ALIGNED_TYPE()
    mcuxClOsccaRandomModes_Context_RNG_t* pRngCtx = (mcuxClOsccaRandomModes_Context_RNG_t*) context;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_ALIGNED_TYPE()

    /* Clear whole ctx buffer */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("pRngCtx is a pointer with right type.")
    pRngCtx->readOff = 0u;
    pRngCtx->writeOff = 0u;
    pRngCtx->entIdx = 0u;
    pRngCtx->bufferEmpty = 1u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t*)&(pRngCtx->entropyBuf),MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN);
    /* init the TRNG */
    MCUXCLOSCCARANDOMMODES_INIT_TRNG();

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_init, MCUXCLRANDOM_STATUS_OK,
                           MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));

}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_reseed, mcuxClRandom_reseedFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_reseed(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    mcuxClRandom_Mode_t    mode UNUSED_PARAM,
    mcuxClRandom_Context_t context UNUSED_PARAM
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_reseed);

	MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_reseed, MCUXCLRANDOM_STATUS_OK);
}

/* poker test, with the parameter run length 2, ref to GMT0005-2012 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_PokerTest)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_PokerTest(uint8_t *pWaCPU, uint32_t length, uint32_t limit)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_PokerTest);
    mcuxClRandom_Status_t ret = MCUXCLRANDOM_STATUS_ERROR;
    uint32_t freCount[4] = {0U, 0U, 0U, 0U};
    uint32_t freCountSum = 0U;

    for (uint32_t i = 0U; i < length; i++)
    {
        for (uint32_t j = 0U; j < 4U; j++) /* 4 2-bit in one byte*/
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_FALSE_POSITIVE_INTEGER_CONVERSION_MISINTERPRETS_DATA("No data is lost, none of the involved operations can overflow the unsigned 8-bit range.")
            uint8_t ni = (uint8_t)((pWaCPU[i] >> (j << 1)) & 0x03U); /* get every 2 bits in workArea[i] */
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_FALSE_POSITIVE_INTEGER_CONVERSION_MISINTERPRETS_DATA()
            MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(freCount[ni], 0U, MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN * 4u, MCUXCLRANDOM_STATUS_FAULT_ATTACK)
            freCount[ni]++;
        }
    }

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(freCountSum, 0U, (MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN * 4u) * (MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN * 4u) * 4u, MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    for (uint32_t i = 0U; i < 4U; i++)
    {
        freCountSum += freCount[i] * freCount[i];
    }


    if (freCountSum < limit) {
        ret = MCUXCLRANDOM_STATUS_OK;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_PokerTest, ret);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_DeliverySimpleTest)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_DeliverySimpleTest(
    mcuxClSession_Handle_t pSession
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_DeliverySimpleTest);
    uint8_t pWaCPU[MCUXCLOSCCARANDOMMODES_SELFTEST_DELIVERY_LEN];
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pWaCPU, MCUXCLOSCCARANDOMMODES_SELFTEST_DELIVERY_LEN);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_ESCAPING_LOCAL_ADDRESS("Address of pWaCPU is not reused outside of mcuxClRandom_generate function")
    MCUX_CSSL_FP_FUNCTION_CALL(genRngRet, mcuxClRandom_generate(pSession, pWaCPU, MCUXCLOSCCARANDOMMODES_SELFTEST_DELIVERY_LEN));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_ESCAPING_LOCAL_ADDRESS()
    if (MCUXCLRANDOM_STATUS_OK != genRngRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_DeliverySimpleTest, MCUXCLRANDOM_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(RngSelfPokerRet, mcuxClOsccaRandomModes_ROtrng_PokerTest(pWaCPU, MCUXCLOSCCARANDOMMODES_SELFTEST_DELIVERY_LEN, MCUXCLOSCCARANDOMMODES_FAIL_LIMIT_FOR_256BITS));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_DeliverySimpleTest, RngSelfPokerRet,
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate),
                               MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_PokerTest));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_PowerOnTest)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_PowerOnTest(
    mcuxClSession_Handle_t pSession,
    uint32_t              loopCnt,
    uint32_t              failLoopCnt)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_PowerOnTest);
    mcuxClRandom_Status_t ret = MCUXCLRANDOM_STATUS_ERROR;
    uint32_t failCnt = 0u;
    uint8_t pWaCPU[MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN];
    MCUXCLMEMORY_FP_MEMORY_CLEAR(pWaCPU, MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN);
    /* acquire loopCnt*10000 bits of random numbers and divide them into loopCnt groups */
    for (uint32_t i = 0; i < loopCnt; i++)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_ESCAPING_LOCAL_ADDRESS("Address of pWaCPU is not reused outside of mcuxClRandom_generate function")
        MCUX_CSSL_FP_FUNCTION_CALL(genRngRet, mcuxClRandom_generate(pSession, pWaCPU, MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_ESCAPING_LOCAL_ADDRESS()
        if (MCUXCLRANDOM_STATUS_OK != genRngRet)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_PowerOnTest, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
        }

        MCUX_CSSL_FP_FUNCTION_CALL(RngSelfPokerRet, mcuxClOsccaRandomModes_ROtrng_PokerTest(pWaCPU, MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN, MCUXCLOSCCARANDOMMODES_FAIL_LIMIT_FOR_10000BITS));
        if (MCUXCLRANDOM_STATUS_OK != RngSelfPokerRet)
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("False positive; failCnt is initialized to zero, and loopCnt and failCnt have the same data size.")
            failCnt++;
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        }
    }

    /* if 2 or more groups of test sequence do not satisfy the test criteria,
     * give an alarm that the test is unacceptable.
     */
    if (failCnt >= failLoopCnt)
    {
        ret = MCUXCLRANDOM_STATUS_ERROR;
    }
    else
    {
        ret = MCUXCLRANDOM_STATUS_OK;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_PowerOnTest, ret,
                     MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
                     loopCnt * ( MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate)
                               + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_PokerTest)));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_selftest, mcuxClRandom_selftestFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_selftest(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t mode UNUSED_PARAM
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_selftest);

    /* Back up Random configuration of current session */
    mcuxClRandom_Mode_t modeBackup = pSession->randomCfg.mode;
    mcuxClRandom_Context_t ctxBackup = pSession->randomCfg.ctx;

    mcuxClRandom_Context_t pCtx;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Cast to correct pointer type")
    pCtx = (mcuxClRandom_Context_t)mcuxClSession_allocateWords_cpuWa(pSession, MCUXCLOSCCARANDOMMODES_OSCCARNG_SELFTEST_CPU_SIZE /sizeof(uint32_t));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    if(NULL == pCtx)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_selftest, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    /* Initialize the Random session with OSCCA TRNG mode. */
    MCUX_CSSL_FP_FUNCTION_CALL(RngInitRet, mcuxClRandom_init(
                                                  pSession,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("change pCtx type to mcuxClRandom_Context_t")
                                                  pCtx,
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
                                                  mcuxClOsccaRandomModes_Mode_TRNG));
    if (MCUXCLRANDOM_STATUS_OK != RngInitRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_selftest, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(RngSimTeRet, mcuxClOsccaRandomModes_ROtrng_DeliverySimpleTest(pSession));
    if (MCUXCLRANDOM_STATUS_FAULT_ATTACK == RngSimTeRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_selftest, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(RngPowerOnTeRet1, mcuxClOsccaRandomModes_ROtrng_PowerOnTest(pSession, 20u, 2u)); /* 20 loops, 2 times fail */
    if (MCUXCLRANDOM_STATUS_FAULT_ATTACK == RngPowerOnTeRet1)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_selftest, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(RngPowerOnTeRet2, mcuxClOsccaRandomModes_ROtrng_PowerOnTest(pSession, 5u, 1u)); /* 5 loops, 1 time fail */
    if (MCUXCLRANDOM_STATUS_FAULT_ATTACK == RngPowerOnTeRet2)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_selftest, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(uninitRet, mcuxClRandom_uninit(pSession));
    if (MCUXCLRANDOM_STATUS_OK != uninitRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_selftest, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    mcuxClSession_freeWords_cpuWa(pSession, MCUXCLOSCCARANDOMMODES_OSCCARNG_SELFTEST_CPU_SIZE /sizeof(uint32_t));

    /* Restore Random configuration of current session */
    pSession->randomCfg.mode = modeBackup;
    pSession->randomCfg.ctx = ctxBackup;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_selftest, MCUXCLRANDOM_STATUS_OK,
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_DeliverySimpleTest),
                    2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_PowerOnTest),
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_uninit));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_generate_head)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_generate_head(
    mcuxClOsccaRandomModes_Context_RNG_t* pRngCtx,
    uint8_t *             pOut,
    uint32_t*             outLength,
    uint32_t*             genRandomBytes,
    uint32_t*             unalignHeadBytes)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_generate_head);

    uint32_t singleEntWord;
    uint32_t outLen = *outLength;
    uint32_t genBytes = *genRandomBytes;
    /* process by bytes now */
    uint32_t rdOffset = pRngCtx->readOff;
    uint32_t wtOffset = pRngCtx->writeOff;
    uint32_t entIdx   = pRngCtx->entIdx;
    uint32_t unalignHeadBys = *unalignHeadBytes;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(rdOffset, 0u, (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U), MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(*outLength, 0u, UINT32_MAX, MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(entIdx, 0u, MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER, MCUXCLRANDOM_STATUS_FAULT_ATTACK)

    unalignHeadBys = sizeof(uint32_t) - ((uint32_t)pOut & (sizeof(uint32_t) - 1U));
    unalignHeadBys &= (sizeof(uint32_t) - 1U);
    if (unalignHeadBys > outLen)
    {
        /* avoid the wrong case when outLen < 4*/
        unalignHeadBys = outLen;
    }

    /* process the unalign bytes */
    if (0U != unalignHeadBys)
    {
        /* if there are remained entropy in buffer */
        if ((rdOffset != wtOffset) || (0U == pRngCtx->bufferEmpty))
        {
            singleEntWord = pRngCtx->entropyBuf[rdOffset++];
            rdOffset &= (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U);
            if (rdOffset == wtOffset)
            {
                pRngCtx->bufferEmpty = 1U;
            }
        }
        else
        {
            MCUXCLOSCCARANDOMMODES_AVAILABLE_TRNG();
            singleEntWord = MCUXCLOSCCARANDOMMODES_GETWORD_TRNG(entIdx);
            entIdx++;
            entIdx &= MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER;
        }

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("genBytes must be in the range of [0, 4u]")
        for (uint32_t i = unalignHeadBys; i > 0U ;i--)
        {
            pOut[genBytes] =
                (uint8_t) ((singleEntWord >> (i * 8U)) & 0xffU);
            genBytes++;

        }
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        *outLength = (*outLength) - unalignHeadBys;
    }

    *unalignHeadBytes = unalignHeadBys;
    *genRandomBytes = genBytes;
    pRngCtx->readOff = rdOffset;
    pRngCtx->writeOff = wtOffset;
    pRngCtx->entIdx = entIdx & MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate_head, MCUXCLRANDOM_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_generate_words)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_generate_words(
    mcuxClOsccaRandomModes_Context_RNG_t* pRngCtx,
    uint32_t*             pDestWords,
    uint32_t              outLength,
    uint32_t*             genRandomBytes)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_generate_words);

    uint32_t genRandomWords = 0u;
    uint32_t singleEntWord;
    uint32_t genBytes = *genRandomBytes;
    uint32_t rdOffset = pRngCtx->readOff;
    uint32_t wtOffset = pRngCtx->writeOff;
    uint32_t entIdx   = pRngCtx->entIdx;
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(rdOffset, 0u, (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U), MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(wtOffset, 0u, (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U), MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(genRandomWords, 0u, UINT32_MAX, MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(genBytes, 0u, UINT32_MAX, MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(entIdx, 0u, MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER, MCUXCLRANDOM_STATUS_FAULT_ATTACK)

    /* process by words now */
    if (0u == pRngCtx->bufferEmpty)
    {
        while ((rdOffset != wtOffset) && (outLength > 0U))
        {
            pDestWords[genRandomWords] = pRngCtx->entropyBuf[rdOffset++];
            /* wrap round the index if need */
            rdOffset &= (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U);
            outLength -= sizeof(uint32_t);
            genRandomWords += 1U;
            genBytes += sizeof(uint32_t);
        }
        if (rdOffset == wtOffset)
        {
            pRngCtx->bufferEmpty = 1U;
        }
    }

    /* still need more entropy */
    while (outLength > 0U)
    {
        MCUXCLOSCCARANDOMMODES_AVAILABLE_TRNG();
        singleEntWord = MCUXCLOSCCARANDOMMODES_GETWORD_TRNG(entIdx);
        pDestWords[genRandomWords] = singleEntWord;

        entIdx++;
        entIdx &= MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER;

        outLength -= sizeof(uint32_t);
        genRandomWords += 1U;
        genBytes += sizeof(uint32_t);
    }

    *genRandomBytes = genBytes;
    pRngCtx->readOff = rdOffset;
    pRngCtx->writeOff = wtOffset;
    pRngCtx->entIdx = entIdx & MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate_words, MCUXCLRANDOM_STATUS_OK);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_generate_tail)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_generate_tail(
    mcuxClOsccaRandomModes_Context_RNG_t* pRngCtx,
    uint8_t *             pOut,
    uint32_t*             genRandomBytes,
    uint32_t              unalignTailBytes)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_generate_tail);

    uint32_t singleEntWord;
    uint32_t genBytes = *genRandomBytes;
    uint32_t rdOffset = pRngCtx->readOff;
    uint32_t wtOffset = pRngCtx->writeOff;
    uint32_t entIdx   = pRngCtx->entIdx;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(rdOffset, 0u, (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U), MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(wtOffset, 0u, (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U), MCUXCLRANDOM_STATUS_FAULT_ATTACK)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(entIdx, 0u, MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER, MCUXCLRANDOM_STATUS_FAULT_ATTACK)

    /* process the remain unalign bytes */
    if (0U < unalignTailBytes)
    {
        /* if there are remained entropy in buffer */
        if ((rdOffset != wtOffset) || (0U == pRngCtx->bufferEmpty))
        {
            singleEntWord = pRngCtx->entropyBuf[rdOffset++];
            rdOffset &= (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U);
            if (rdOffset == wtOffset)
            {
                pRngCtx->bufferEmpty = 1U;
            }
        }
        else
        {
            MCUXCLOSCCARANDOMMODES_AVAILABLE_TRNG();
            singleEntWord = MCUXCLOSCCARANDOMMODES_GETWORD_TRNG(entIdx);
            entIdx++;
            entIdx &= MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER;
        }

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("genBytes must be in the range of [0, UINT32_MAX]")
        for (uint32_t i = 0U; i < unalignTailBytes; i++)
        {
            pOut[genBytes] = (uint8_t) ((singleEntWord >> (i * 8U)) & 0xffU);
            genBytes++;

        }
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }

    /* still have extra entropy in hardware, read out and regenerating */
    while (entIdx != 0U)
    {
        pRngCtx->entropyBuf[wtOffset] = MCUXCLOSCCARANDOMMODES_GETWORD_TRNG(entIdx);
        entIdx++;
        wtOffset++;
        entIdx &= MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER;
        wtOffset &= (MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN/sizeof(uint32_t) - 1U);
        pRngCtx->bufferEmpty = 0U;
    }

    *genRandomBytes = genBytes;
    pRngCtx->readOff = rdOffset;
    pRngCtx->writeOff = wtOffset;
    pRngCtx->entIdx = entIdx & MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate_tail, MCUXCLRANDOM_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaRandomModes_ROtrng_generate, mcuxClRandom_generateFunction_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClOsccaRandomModes_ROtrng_generate(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t    mode UNUSED_PARAM,
    mcuxClRandom_Context_t context,
    uint8_t *             pOut,
    uint32_t              outLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaRandomModes_ROtrng_generate);
    MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_ALIGNED_TYPE()
    mcuxClOsccaRandomModes_Context_RNG_t* pRngCtx = (mcuxClOsccaRandomModes_Context_RNG_t*) context;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_ALIGNED_TYPE()
    uint32_t genRandomBytes = 0u;
    uint32_t outLenExpected = outLength;
    uint32_t unalignHeadBytes = 0u;

    if (NULL == pOut)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate, MCUXCLRANDOM_STATUS_ERROR);
    }

    /* Initializ the output buffer with random data */
    MCUX_CSSL_FP_FUNCTION_CALL(randomGenRet, mcuxClRandom_ncGenerate(pSession, pOut, outLength));
    if (MCUXCLRANDOM_STATUS_OK != randomGenRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate, MCUXCLRANDOM_STATUS_ERROR);
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("all parameters are with right type.")
    MCUX_CSSL_FP_FUNCTION_CALL(headGenRet, mcuxClOsccaRandomModes_ROtrng_generate_head(pRngCtx, pOut, &outLength, &genRandomBytes, &unalignHeadBytes));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    if (MCUXCLRANDOM_STATUS_OK != headGenRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    /* process by words now */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Cast to correct pointer type")
    uint32_t *pDestWords = (uint32_t *)&pOut[unalignHeadBytes];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    uint32_t unalignTailBytes = outLength & (sizeof(uint32_t) - 1U);
    outLength &= ~(sizeof(uint32_t) - 1U);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("all parameters are with right type.")
    MCUX_CSSL_FP_FUNCTION_CALL(wordGenRet, mcuxClOsccaRandomModes_ROtrng_generate_words(pRngCtx, pDestWords, outLength, &genRandomBytes));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    if (MCUXCLRANDOM_STATUS_OK != wordGenRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("all parameters are with right type.")
    MCUX_CSSL_FP_FUNCTION_CALL(tailGenRet, mcuxClOsccaRandomModes_ROtrng_generate_tail(pRngCtx, pOut, &genRandomBytes, unalignTailBytes));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    if (MCUXCLRANDOM_STATUS_OK != tailGenRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    if (genRandomBytes == outLenExpected)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate, MCUXCLRANDOM_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_generate_head),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_generate_words),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_generate_tail));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaRandomModes_ROtrng_generate, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
}

static const mcuxClRandom_OperationModeDescriptor_t mcuxClOsccaRandomModes_OperationModeDescriptor_ROTRNG_Trng = {
    .initFunction                    = mcuxClOsccaRandomModes_ROtrng_init,
    .reseedFunction                  = mcuxClOsccaRandomModes_ROtrng_reseed,
    .generateFunction                = mcuxClOsccaRandomModes_ROtrng_generate,
    .selftestFunction                = mcuxClOsccaRandomModes_ROtrng_selftest,
    .protectionTokenInitFunction     = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_init),
    .protectionTokenReseedFunction   = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_reseed),
    .protectionTokenGenerateFunction = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_generate),
    .protectionTokenSelftestFunction = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaRandomModes_ROtrng_selftest),
    .operationMode                   = MCUXCLOSCCARANDOMMODES_OSCCA_MODE
};

const mcuxClRandom_ModeDescriptor_t mcuxClOsccaRandomModes_mdROTRNG_Trng = {
    .pOperationMode   = &mcuxClOsccaRandomModes_OperationModeDescriptor_ROTRNG_Trng,
    .pDrbgMode        = NULL,
    .contextSize      = sizeof(mcuxClOsccaRandomModes_Context_RNG_t),
    .auxParam         = NULL,
    .securityStrength = 0u
};
