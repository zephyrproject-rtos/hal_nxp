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
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClCrc_Internal_Functions.h>



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncPatch)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_ncPatch(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_CustomNcGenerateAlgorithm_t prngPatchFunction,
    void *pCustomPrngState
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_ncPatch, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);

    MCUX_CSSL_DI_RECORD(sumOfRandomNcPatchParams, (uint32_t)pSession + (uint32_t) pCustomPrngState);

    /* Set the PRNG patch function to patch the PRNG */
    pSession->randomCfg.prngPatchFunction = prngPatchFunction;
    pSession->randomCfg.pCustomPrngState = pCustomPrngState;

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomNcPatchParams, (uint32_t)pSession + (uint32_t) pCustomPrngState);

    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_ncPatch, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncInit)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_ncInit(
    mcuxClSession_Handle_t pSession
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_ncInit, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);

    MCUX_CSSL_DI_RECORD(sumOfRandomNcInitParams, pSession);

    /* Reset the PRNG patch function to un-patch the PRNG */
    pSession->randomCfg.prngPatchFunction = NULL;
    pSession->randomCfg.pCustomPrngState = NULL;

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomNcInitParams, pSession);

    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_ncInit, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncReseed)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_ncReseed(
    mcuxClSession_Handle_t pSession
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_ncReseed, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);

    /* Call internal reseed function */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_reseed(pSession));

    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_ncReseed, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_reseed));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncGenerate_Internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandom_ncGenerate_Internal(
    mcuxClSession_Handle_t pSession,
    uint8_t*              pOut,
    uint32_t              outLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandom_ncGenerate_Internal);

    if(NULL != pSession->randomCfg.prngPatchFunction)
    {
        MCUXCLBUFFER_INIT(pBufOut, NULL, pOut, outLength);
        mcuxClRandom_Status_t result_customAlg = pSession->randomCfg.prngPatchFunction(
                    pSession->randomCfg.pCustomPrngState,
                    pBufOut,
                    outLength);

        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, result_customAlg);
        MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandom_ncGenerate_Internal);
    }

    /* Assume normal mode going forward. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pOut, outLength));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandom_ncGenerate_Internal, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncGenerateWord_Internal)
uint32_t mcuxClRandom_ncGenerateWord_Internal(mcuxClSession_Handle_t pSession)
{

    if(NULL != pSession->randomCfg.prngPatchFunction)
    {
        uint32_t rngWord = 0x0u;
        MCUXCLBUFFER_INIT(pBufRandom, NULL, (uint8_t *) &rngWord, 4u);
        (void) pSession->randomCfg.prngPatchFunction(
                pSession->randomCfg.pCustomPrngState,
                pBufRandom,
                sizeof(uint32_t));
        return rngWord;
    }

    return MCUX_CSSL_FP_RESULT(mcuxClPrng_generate_word());
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_ncGenerate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_ncGenerate(
    mcuxClSession_Handle_t pSession,
    mcuxCl_Buffer_t        pOut,
    uint32_t              outLength
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_ncGenerate, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);

    MCUX_CSSL_DI_RECORD(sumOfRandomNcGenerateParams, (uint32_t)pSession + (uint32_t)pOut + outLength);

    if(NULL != pSession->randomCfg.prngPatchFunction)
    {
        mcuxClRandom_Status_t result_customAlg = pSession->randomCfg.prngPatchFunction(
                    pSession->randomCfg.pCustomPrngState,
                    pOut,
                    outLength);

        MCUX_CSSL_DI_EXPUNGE(sumOfRandomNcGenerateParams, (uint32_t)pSession + (uint32_t)pOut + outLength);

        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, result_customAlg);
        MCUXCLSESSION_EXIT(pSession, mcuxClRandom_ncGenerate, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }

    /* Assume normal mode going forward. */

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate(pSession, pOut, outLength));

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomNcGenerateParams, (uint32_t)pSession + (uint32_t)pOut + outLength);

    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_ncGenerate, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate));
}
