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

/** @file  mcuxClRandom_DRBG.c
 *  @brief Implementation of the Random component which provides APIs for
 *  handling of DRBG random number generators. This file implements the functions
 *  declared in mcuxClRandom.h. */

#include <mcuxClToolchain.h>

#include <mcuxClBuffer.h>
#include <mcuxClRandom.h>
#include <mcuxClSession.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClCrc_Internal_Functions.h>
#include <internal/mcuxClMemory_ClearSecure_Internal.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>


/**
 * @brief This function verifies a Random mode
 *
 * @param  mode[in]       Random mode to be verified
 * @param  pSession[in]   Session handle
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - #MCUXCLRANDOM_STATUS_FAULT_ATTACK  if the Random mode is uninitialized
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_verifyMode)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandom_verifyMode(mcuxClSession_Handle_t pSession, mcuxClRandom_Mode_t mode)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandom_verifyMode);

    // TODO CLNS-7923: Need to be discussed whether INVALID_PARAM or FAULT_ATTACK should be returned
    if(mode == NULL)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    }
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandom_verifyMode);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_generate_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandom_generate_internal(
    mcuxClSession_Handle_t pSession,
    mcuxCl_Buffer_t        pOut,
    uint32_t              outLength,
    const uint32_t        *pXorMask
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandom_generate_internal);

    mcuxClRandom_Context_t pRngCtx = pSession->randomCfg.ctx;
    mcuxClRandom_Mode_t sessionMode = pSession->randomCfg.mode;

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(pSession, pRngCtx, sessionMode->contextSize));

    /* Call generate function from randommodes
     * Data Integrity: Expunge(pSession + pOut + outLength + pXorMask) */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(sessionMode->pOperationMode->generateFunction(pSession, sessionMode, pRngCtx, pOut, outLength, pXorMask));

    /* Update the context CRC */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pRngCtx, sessionMode->contextSize));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandom_generate_internal,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
        sessionMode->pOperationMode->protectionTokenGenerateFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_init(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Context_t pContext,
    mcuxClRandom_Mode_t    mode
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_init, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    MCUX_CSSL_DI_RECORD(randomInitParamPsession, pSession);
    MCUX_CSSL_DI_RECORD(randomInitParamPctx, pContext);
    MCUX_CSSL_DI_RECORD(randomInitParamMode, mode);

    /* Verify passed mode parameter */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_verifyMode(pSession, mode));

    /* Store context in session. */
    pSession->randomCfg.ctx = pContext;

    /* Store mode in session. */
    pSession->randomCfg.mode = mode;

    /* Call internal init function */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mode->pOperationMode->initFunction(pSession, mode, pContext));

    /* Initialize the context CRC */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pContext, mode->contextSize));

    MCUX_CSSL_DI_EXPUNGE(randomInitParamPsession, pSession);
    MCUX_CSSL_DI_EXPUNGE(randomInitParamPctx, pContext);
    MCUX_CSSL_DI_EXPUNGE(randomInitParamMode, mode);
    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_init, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_verifyMode),
        mode->pOperationMode->protectionTokenInitFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_reseed)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_reseed(
    mcuxClSession_Handle_t pSession
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_reseed, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    MCUX_CSSL_DI_RECORD(sumOfRandomReseedParams, pSession);

    /* Verify context integrity */
    mcuxClRandom_Context_t pRngCtx = pSession->randomCfg.ctx;
    mcuxClRandom_Mode_t sessionMode = pSession->randomCfg.mode;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(pSession, pRngCtx, sessionMode->contextSize));

    /* Call internal reseed function */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(sessionMode->pOperationMode->reseedFunction(pSession, sessionMode, pRngCtx));

    /* Update the context CRC */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_computeContextCrc(pRngCtx, sessionMode->contextSize));

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomReseedParams, pSession);
    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_reseed, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
        sessionMode->pOperationMode->protectionTokenReseedFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_computeContextCrc));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_generate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_generate(
    mcuxClSession_Handle_t pSession,
    mcuxCl_Buffer_t        pOut,
    uint32_t              outLength
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_generate, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, pSession);
    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, pOut);
    MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, outLength);

    /* Call internal generate function
     * Data Integrity: Expunge(pSession + pOut + outLength) */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_generate_internal(pSession, pOut, outLength, NULL));

    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_generate, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_uninit)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_uninit(
  mcuxClSession_Handle_t pSession
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_uninit, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    MCUX_CSSL_DI_RECORD(sumOfRandomUninitParams, pSession);

    /* Verify context integrity */
    mcuxClRandom_Mode_t sessionMode = pSession->randomCfg.mode;
    mcuxClRandom_Context_t pRngCtx = pSession->randomCfg.ctx;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_verifyContextCrc(pSession, pRngCtx, sessionMode->contextSize));

    /* Clear the context. ContextSize will never be 0. An error here is considered a fault attack, so no DI or FP balancing is needed. */
    MCUX_CSSL_DI_RECORD(clearSecureDI, pSession->randomCfg.ctx);
    MCUX_CSSL_DI_RECORD(clearSecureDI, sessionMode->contextSize);
    MCUXCLMEMORY_CLEAR_SECURE_INT((uint8_t *) pSession->randomCfg.ctx, sessionMode->contextSize);

    /* Clear pointers stored in the session. */
    pSession->randomCfg.ctx = NULL;
    pSession->randomCfg.mode = NULL;

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomUninitParams, pSession);
    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_uninit, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_verifyContextCrc),
        MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_selftest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_selftest(
    mcuxClSession_Handle_t pSession,
    mcuxClRandom_Mode_t    mode
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_selftest, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    MCUX_CSSL_DI_RECORD(sumOfRandomSelftestParams, pSession);
    MCUX_CSSL_DI_RECORD(sumOfRandomSelftestParams, mode);

    /* Verify passed mode parameter */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_verifyMode(pSession, mode));

    /* Call internal selftest function. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mode->pOperationMode->selftestFunction(pSession, mode));

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomSelftestParams, pSession);
    MCUX_CSSL_DI_EXPUNGE(sumOfRandomSelftestParams, mode);
    MCUXCLSESSION_EXIT(pSession, mcuxClRandom_selftest, diRefValue, MCUXCLRANDOM_STATUS_OK, MCUXCLRANDOM_STATUS_FAULT_ATTACK,
        mode->pOperationMode->protectionTokenSelftestFunction,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_verifyMode));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandom_checkSecurityStrength)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandom_checkSecurityStrength(
    mcuxClSession_Handle_t pSession,
    uint32_t              securityStrength
)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClRandom_checkSecurityStrength, diRefValue, MCUXCLRANDOM_STATUS_FAULT_ATTACK);
    MCUX_CSSL_DI_RECORD(sumOfRandomCheckSecurityStrengthParams, pSession);
    MCUX_CSSL_DI_RECORD(sumOfRandomCheckSecurityStrengthParams, securityStrength);

    mcuxClRandom_Mode_t sessionMode = pSession->randomCfg.mode;

    MCUX_CSSL_DI_EXPUNGE(sumOfRandomCheckSecurityStrengthParams, pSession);
    MCUX_CSSL_DI_EXPUNGE(sumOfRandomCheckSecurityStrengthParams, securityStrength);

    if(securityStrength > sessionMode->securityStrength)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLRANDOM_STATUS_LOW_SECURITY_STRENGTH);
    }

    MCUXCLSESSION_EXIT(pSession,
                      mcuxClRandom_checkSecurityStrength,
                      diRefValue,
                      MCUXCLRANDOM_STATUS_OK,
                      MCUXCLRANDOM_STATUS_FAULT_ATTACK);
}
