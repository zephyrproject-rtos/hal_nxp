/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/**
 * @file  mcuxClPkc_Resource.h
 * @brief Macros for requesting/releasing PKC
 */


#ifndef MCUXCLPKC_RESOURCE_H_
#define MCUXCLPKC_RESOURCE_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClSession.h>
#include <internal/mcuxClPkc_Internal_Types.h>
#include <internal/mcuxClPkc_Internal_Functions.h>

#include <mcuxClResource_Types.h>
#include <internal/mcuxClResource_Internal_Types.h>
#include <internal/mcuxClSession_Internal_Functions.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Macro to request PKC resource and initialize PKC. */
#define MCUXCLPKC_FP_REQUEST_INITIALIZE(session, callerName) \
    do {  \
        MCUX_CSSL_FP_FUNCTION_CALL_VOID( \
            mcuxClResource_request(session, MCUXCLRESOURCE_HWID_PKC, MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE, NULL, 0U) \
        ); \
        MCUXCLPKC_FP_INITIALIZE(session); \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Macro to deinitialize PKC and release PKC resource */
#define MCUXCLPKC_FP_DEINITIALIZE_RELEASE(session) \
    do {  \
        MCUXCLPKC_FP_DEINITIALIZE();\
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_release((session)->pResourceCtx, MCUXCLRESOURCE_HWID_PKC)); \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_Initialize)


#define MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE  \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_Deinitialize),\
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_release)


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPKC_RESOURCE_H_ */
