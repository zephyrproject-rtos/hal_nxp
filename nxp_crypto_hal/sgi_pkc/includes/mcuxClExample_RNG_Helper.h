/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023, 2025 NXP                                            */
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

#ifndef MCUXCLEXAMPLE_RNG_HELPER_H_
#define MCUXCLEXAMPLE_RNG_HELPER_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClRandom.h>
#include <mcuxClRandomModes.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

// always allocate a minimum size buffer to avoid issues
// The size is given in bytes and allocated in words
#define MCUXCLEXAMPLE_ALLOCATE_RNG_CTXT(rngCtxLength) (rngCtxLength?((rngCtxLength + sizeof(uint32_t) - 1u) / sizeof(uint32_t)):1u)  

/**
 * Random data generator and Non-cryptographic PRNG initialization function via mcuxClRandom_init and mcuxClRandom_ncInit.
 * [in]     pSession        Handle for the current CL session.
 * [in]     rngCtxLength    Size (in bytes) of the RNG context need to be allocated based on the mode.
 * [in]     mode            Mode of operation for random data generator.
 **/

#define MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_RNG(pSession, rngCtxLength, mode)                                               \
    uint32_t context[MCUXCLEXAMPLE_ALLOCATE_RNG_CTXT(rngCtxLength)] = {0};                                                    \
    mcuxClRandom_Context_t pRng_ctx = (mcuxClRandom_Context_t)context;                                                         \
                                                                                                                             \
    /* Initialize the RNG context */                                                                                         \
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(randomInit_result, randomInit_token, mcuxClRandom_init(pSession,                          \
                                                                                          pRng_ctx,                          \
                                                                                          mode));                            \
    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init) != randomInit_token) || (MCUXCLRANDOM_STATUS_OK != randomInit_result))  \
    {                                                                                                                        \
        return MCUXCLEXAMPLE_STATUS_ERROR;                                                                                    \
    }                                                                                                                        \
    MCUX_CSSL_FP_FUNCTION_CALL_END();                                                                                         \
                                                                                                                             \
    MCUXCLEXAMPLE_INITIALIZE_PRNG(pSession);


#define MCUXCLEXAMPLE_INITIALIZE_PRNG(session)                                                                               \
    /* Initialize the PRNG */                                                                                               \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("session->apiCall is not NULL")                               \
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(session));                          \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()                                                              \
    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) || (MCUXCLRANDOM_STATUS_OK != prngInit_result))   \
    {                                                                                                                       \
        return MCUXCLEXAMPLE_STATUS_ERROR;                                                                                   \
    }                                                                                                                       \
    MCUX_CSSL_FP_FUNCTION_CALL_END()

#endif /* MCUXCLEXAMPLE_RNG_HELPER_H_ */
