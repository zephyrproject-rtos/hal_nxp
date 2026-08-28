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
 * @file  mcuxClResource_Functions.h
 * @brief Top-level API of the mcuxClResource component
 */


#ifndef MCUXCLRESOURCE_FUNCTIONS_H_
#define MCUXCLRESOURCE_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClResource_Types.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClResource_Functions mcuxClResource_Functions
 * @brief Defines all functions of @ref mcuxClResource
 * @ingroup mcuxClResource
 * @{
 */

/**
 * @brief Resource context initialization function.
 *
 * This function performs the initialization of the resource context.
 * There should generally only be one (global) resource context.
 *
 * @param pResourceCtx   Pointer to the global resource context
 * @param pMutexAcquire  Callback to be used for acquiring a mutex.
 * @param pMutexRelease  Callback to be used for releasing a mutex.
 *
 * @return status
 * @retval #MCUXCLRESOURCE_STATUS_OK     Resource context has been initialized successfully
 * @retval #MCUXCLRESOURCE_STATUS_ERROR  Error occurred during resource initializing
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClResource_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClResource_Status_t) mcuxClResource_init(
    mcuxClResource_Context_t * pResourceCtx,
    mcuxClResource_MutexAcquire_Callback_t pMutexAcquire,
    mcuxClResource_MutexRelease_Callback_t pMutexRelease
);

/**
 * @brief Resource interrupt handler.
 *
 * This function performs the interrupt handling for the given resource to wrap-up
 * an operation after the interrupt of the resource was triggered.
 * The user callback, which is installed in the session that performed the non-blocking
 * operation, will be triggered by this function if the crypto operation finished successfully.
 *
 * @attention This function shall not be called directly in interrupt service routines
 *   (ISR) of the resources, but rather after the ISR has been triggered.
 *   Do not clear any error bits in the respective resources before calling this function,
 *   as the error status bits are read and handled/translated by Clib to wrap-up the operation.
 * @attention In case of any detected error or fault, the installed user callback
 *   is not triggered.
 *
 * @param  pResourceCtx  Pointer to the global resource context
 * @param  interrupt     The interrupt to be handled.
 *
 * @return status
 * @retval #MCUXCLRESOURCE_STATUS_OK     Resource operation successful
 * @retval #MCUXCLRESOURCE_STATUS_ERROR  Error occurred during Resource operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClResource_handle_interrupt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClResource_Status_t) mcuxClResource_handle_interrupt(
    const mcuxClResource_Context_t *pResourceCtx,
    mcuxClResource_Interrupt_t interrupt
);

/**
 * @}
 */ /* mcuxClResource_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRESOURCE_FUNCTIONS_H_ */
