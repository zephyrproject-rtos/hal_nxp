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

/** @file  mcuxClRandom_PRNG.c
 *  @brief Implementation of the non-cryptographic PRNG functions. */

#include <mcuxClToolchain.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>
#include <mcuxClRandom.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncPatch)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_ncPatch(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_CustomNcGenerateAlgorithm_t prngPatchFunction,
    void *pCustomPrngState
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandom_ncPatch);

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomNcPatchParams, (uint32_t)pSession + (uint32_t) pCustomPrngState);

    /* Set the PRNG patch function to patch the PRNG */
    pSession->randomCfg.prngPatchFunction = prngPatchFunction;
    pSession->randomCfg.pCustomPrngState = pCustomPrngState;

    MCUX_CSSL_DI_RECORD(sumOfRandomNcPatchParams, (uint32_t)pSession + (uint32_t) pCustomPrngState);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRandom_ncPatch, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncInit)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_ncInit(
    mcuxClSession_Handle_t pSession
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandom_ncInit);

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomNcInitParams, (uint32_t)pSession);

    /* Reset the PRNG patch function to un-patch the PRNG */
    pSession->randomCfg.prngPatchFunction = NULL;
    pSession->randomCfg.pCustomPrngState = NULL;

    MCUX_CSSL_FP_FUNCTION_CALL(ret_Prng_Init, mcuxClPrng_init());

    MCUX_CSSL_DI_RECORD(sumOfRandomNcInitParams, (uint32_t)pSession);

    if(MCUXCLPRNG_STATUS_ERROR == ret_Prng_Init)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandom_ncInit, MCUXCLRANDOM_STATUS_ERROR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_init));
    }
    else if(MCUXCLPRNG_STATUS_OK != ret_Prng_Init)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandom_ncInit, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRandom_ncInit, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_init));
    }
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncGenerate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_ncGenerate(
    mcuxClSession_Handle_t pSession,
    mcuxCl_Buffer_t        pOut,
    uint32_t              outLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandom_ncGenerate);

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomNcGenerateParams, (uint32_t)pSession + (uint32_t)pOut + outLength);

    if(NULL != pSession->randomCfg.prngPatchFunction)
    {
        mcuxClRandom_Status_t result_customAlg = pSession->randomCfg.prngPatchFunction(
                    pSession->randomCfg.pCustomPrngState,
                    pOut,
                    outLength);

        MCUX_CSSL_DI_RECORD(sumOfRandomNcGenerateParams, (uint32_t)pSession + (uint32_t)pOut + outLength);

        MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRandom_ncGenerate, result_customAlg, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }
    /* Assume normal mode going forward. */

    MCUX_CSSL_FP_FUNCTION_CALL(ret_Prng_GetRandom, mcuxClPrng_generate(pOut, outLength));

    MCUX_CSSL_DI_RECORD(sumOfRandomNcGenerateParams, (uint32_t)pSession + (uint32_t)pOut + outLength);

    if(MCUXCLPRNG_STATUS_ERROR == ret_Prng_GetRandom)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandom_ncGenerate, MCUXCLRANDOM_STATUS_ERROR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate));
    }
    else if(MCUXCLPRNG_STATUS_OK != ret_Prng_GetRandom)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRandom_ncGenerate, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClRandom_ncGenerate, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate));
    }
}
