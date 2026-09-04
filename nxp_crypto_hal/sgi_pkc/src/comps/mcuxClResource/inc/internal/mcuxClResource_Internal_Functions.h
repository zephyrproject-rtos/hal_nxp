/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClResource_Internal_Functions.h
 * @brief Internal functions of the mcuxClResource component
 */

#ifndef MCUXCLRESOURCE_INTERNAL_FUNCTIONS_H_
#define MCUXCLRESOURCE_INTERNAL_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClSession_Types.h>
#include <mcuxClResource_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Request hardware
 *
 * @param session                        Handle for the CL session requesting Hw.
 * @param hwId                           HW to be requested.
 * @param option                         Option for requesting HW.
 * @param pHwIrqHandler                  Function pointer handling HW interrupt.
 * @param protectionToken_pHwIrqHandler  Protection token of the HW interrupt handler.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClResource_request)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClResource_request(
    mcuxClSession_Handle_t session,
    mcuxClResource_HwId_t hwId,
    mcuxClResource_HwStatus_t option,
    mcuxClSession_HwInterruptHandler_t pHwIrqHandler,
    uint32_t protectionToken_pHwIrqHandler
);

/**
 * @brief Release hardware
 *
 * @param pResourceCtx  Global resource context.
 * @param hwId          HW to be released.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClResource_release)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClResource_release(
    mcuxClResource_Context_t * pResourceCtx,
    mcuxClResource_HwId_t hwId
);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRESOURCE_INTERNAL_FUNCTIONS_H_ */
