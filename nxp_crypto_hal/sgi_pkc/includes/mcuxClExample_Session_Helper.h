/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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

#ifndef MCUXCLEXAMPLE_SESSION_HELPER_H_
#define MCUXCLEXAMPLE_SESSION_HELPER_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Examples.h>
#include <mcuxClSession.h>
#include <mcuxClResource.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <platform_specific_headers.h>

/**
 * Initialize Session via mcuxClSession_init.
 * [in]  pSession     : Pointer to the session handle.
 * [in]  cpuWaLength  : Size (in bytes) of the workarea for CPU operations. The size shall be a multiple of CPU wordsize.
 * [in]  pkcWaLength  : Size (in bytes) of the workarea for PKC operations. The size shall be a multiple of CPU wordsize.
 */

/* Macros to make sure some memory is always allocated to avoid issues */
#define MCUXCLEXAMPLE_ALLOCATE_CPUWA(cpuWaLength) \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT("Constant values are allowed as an argument to macro function") \
        ((((sizeof(uint32_t)) <= (cpuWaLength))?(cpuWaLength):sizeof(uint32_t)) / (sizeof(uint32_t))) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT()
#define MCUXCLEXAMPLE_ALLOCATE_PKCWA(pkcWaLength) \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT("Constant values are allowed as an argument to macro function") \
        ((((sizeof(uint32_t)) <= (pkcWaLength))?(pkcWaLength):sizeof(uint32_t)) / (sizeof(uint32_t))) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT()

#define MCUXCLEXAMPLE_MAX_WA(a, b) \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT("Constant values are allowed as an argument to macro function") \
        (((a) > (b)) ? (a) : (b)) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT()

#include <mcuxClResource.h>

/**
 * If SESSION_JOBS feature is supported by platform, the resource context will be allocated on the stack and initialized.
 * This is for illustration purpose of the flow and to have the example self-contained, and for production use there should
 * be a single instance and initialized only once.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClExample_Session_InitAndSetResourceCtx)
static inline bool mcuxClExample_Session_InitAndSetResourceCtx(
                        mcuxClSession_Handle_t pSession,
                        mcuxClResource_Context_t * pResourceCtx)
{
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ri_status, ri_token, mcuxClResource_init(
        /* mcuxClResource_Context_t * pResourceCtx:              */ pResourceCtx,
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
        /* mcuxClResource_MutexAcquire_Callback_t pMutexAcquire: */ NULL,
        /* mcuxClResource_MutexRelease_Callback_t pMutexRelease: */ NULL
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
    ));
    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_init) != ri_token) || (MCUXCLRESOURCE_STATUS_OK != ri_status))
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(ssr_status, ssr_token, mcuxClSession_setResource(
        /* mcuxClSession_Handle_t session:           */ pSession,
        /* mcuxClResource_Context_t * pResourceCtx:  */ pResourceCtx));
    if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_setResource) != ssr_token) || (MCUXCLSESSION_STATUS_OK != ssr_status))
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return MCUXCLEXAMPLE_STATUS_OK;
}

#define MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(pSession, cpuWaLength, pkcWaLength)                              \
        uint32_t cpuWaBuffer[MCUXCLEXAMPLE_ALLOCATE_CPUWA(cpuWaLength)];                                               \
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(si_status, token, mcuxClSession_init(                                          \
            /* mcuxClSession_Handle_t session:      */ pSession,                                                       \
            /* uint32_t * const cpuWaBuffer:       */ cpuWaBuffer,                                                    \
            /* uint32_t cpuWaSize:                 */ cpuWaLength,                                                    \
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER()                                                \
            /* uint32_t * const pkcWaBuffer:       */ (uint32_t *) PKC_RAM_ADDR,                                      \
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()                                                 \
            /* uint32_t pkcWaSize:                 */ pkcWaLength                                                     \
            ));                                                                                                       \
        /* mcuxClSession_init is a flow-protected function: Check the protection token and the return value */         \
        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != si_status))        \
        {                                                                                                             \
            return MCUXCLEXAMPLE_STATUS_ERROR;                                                                         \
        }                                                                                                             \
        MCUX_CSSL_FP_FUNCTION_CALL_END();                                                                              \
        uint32_t resCtx[MCUXCLRESOURCE_CONTEXT_SIZE/sizeof(uint32_t)];                                                 \
        MCUX_CSSL_ANALYSIS_COVERITY_START_DEVIATE(MISRA_C_2012_Rule_10_3, "Implicit cast between int and bool in examples is allowed for readability purposes")\
        if (!mcuxClExample_Session_InitAndSetResourceCtx(pSession, (mcuxClResource_Context_t *)resCtx))                 \
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_DEVIATE(MISRA_C_2012_Rule_10_3)                                               \
        {                                                                                                             \
            return MCUXCLEXAMPLE_STATUS_ERROR;                                                                         \
        }

/* For non-blocking, resource context needs to be global to be used for interrupt/callback handlers,
   until such handling is incorporated for all examples. */
#define MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION_NONBLOCKING(pSession, cpuWaLength, pkcWaLength)                  \
        uint32_t cpuWaBuffer[MCUXCLEXAMPLE_ALLOCATE_CPUWA(cpuWaLength)];                                               \
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(si_status, token, mcuxClSession_init(                                          \
            /* mcuxClSession_Handle_t session:      */ pSession,                                                       \
            /* uint32_t * const cpuWaBuffer:       */ cpuWaBuffer,                                                    \
            /* uint32_t cpuWaSize:                 */ cpuWaLength,                                                    \
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER()                                                \
            /* uint32_t * const pkcWaBuffer:       */ (uint32_t *) PKC_RAM_ADDR,                                      \
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()                                                 \
            /* uint32_t pkcWaSize:                 */ pkcWaLength                                                     \
            ));                                                                                                       \
        /* mcuxClSession_init is a flow-protected function: Check the protection token and the return value */         \
        if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != token) || (MCUXCLSESSION_STATUS_OK != si_status))        \
        {                                                                                                             \
            return MCUXCLEXAMPLE_STATUS_ERROR;                                                                         \
        }                                                                                                             \
        MCUX_CSSL_FP_FUNCTION_CALL_END();

/**
 * Cleanup Session via mcuxClSession_cleanup
 * [in]  pSession: Pointer to the session handle.
 **/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClExample_Session_Clean)
static inline bool mcuxClExample_Session_Clean(mcuxClSession_Handle_t pSession)
{
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cleanup_result, cleanup_token, mcuxClSession_cleanup(pSession));

    if(MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != cleanup_token || MCUXCLSESSION_STATUS_OK != cleanup_result)
    {
        return MCUXCLEXAMPLE_STATUS_ERROR;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_END();

    return MCUXCLEXAMPLE_STATUS_OK;
}

#endif /* MCUXCLEXAMPLE_SESSION_HELPER_H_ */
