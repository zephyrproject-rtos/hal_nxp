/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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
 * @file  mcuxClSession_Functions.h
 * @brief Top-level API of the mcuxClSession component
 */

#ifndef MCUXCLSESSION_FUNCTIONS_H_
#define MCUXCLSESSION_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClSession_Types.h>
#include <mcuxClResource_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/
/**
 * @defgroup mcuxClSession_Functions mcuxClSession_Functions
 * @brief Defines all functions of @ref mcuxClSession
 * @ingroup mcuxClSession
 * @{
 */

/**
 * @brief Initialize a Crypto Library session.
 *
 * @param  pSession     Session to be initialized.
 * @param  pCpuWaBuffer Pointer to buffer to be used as workarea for CPU operations.
 *                      This pointer shall be CPU-word aligned.
 * @param  cpuWaLength  Size (in bytes) of the workarea for CPU operations.
 *                      The size shall be a multiple of CPU wordsize.
 * @param  pPkcWaBuffer Pointer to buffer to be used as workarea for PKC operations.
 *                      This pointer shall be PKC-word aligned.
 * @param  pkcWaLength  Size (in bytes) of the workarea for PKC operations.
 *                      The size shall be a multiple of **CPU** wordsize.
 *
 * @return status
 * @retval #MCUXCLSESSION_STATUS_OK     Session has been initialized successfully
 * @retval #MCUXCLSESSION_STATUS_ERROR  Error occurred during session initializing.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_init(
  mcuxClSession_Handle_t pSession,
  uint32_t * const pCpuWaBuffer,
  uint32_t cpuWaLength,
  uint32_t * const pPkcWaBuffer,
  uint32_t pkcWaLength
  /* TBD: sclRandom_Context_t * const rngCtx */
);

/**
 * @brief Set the resource context in a Crypto Library session
 *
 * @param session       Session to be initialized.
 * @param pResourceCtx  Pointer to the global resource context.
 *
 * @return status
 * @retval #MCUXCLSESSION_STATUS_OK  Session operation successful
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_setResource)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_setResource(
  mcuxClSession_Handle_t session,
  mcuxClResource_Context_t * pResourceCtx
);

/**
 * @brief Configure the parameters for non-blocking operations (jobs) in this session.
 *
 * @param session        Handle for the current CL session.
 * @param dmaChannels    DMA channels to be used for non-blocking operations.
 * @param pUserCallback  Callback triggered on CL status changes.
 * @param pUserData      Data passed back to the callback function.
 *
 * @return status
 * @retval #MCUXCLSESSION_STATUS_OK  Session operation successful
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_configure_job)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_configure_job(
  mcuxClSession_Handle_t session,
  mcuxClSession_Channels_t dmaChannels,
  mcuxClSession_Callback_t pUserCallback,
  void * pUserData
);






/**
 * @brief Clean up a Crypto Library session.
 *
 * This function will (securely) cleanup the session, which will still be usable afterwards.
 *
 * @param  pSession Session to be cleaned.
 *
 * @return status
 * @retval #MCUXCLSESSION_STATUS_OK     Session operation successful
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_cleanup)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_cleanup(
  mcuxClSession_Handle_t pSession
);

/**
 * @brief Destroy a Crypto Library session.
 *
 * This function will (securely) cleanup the session, including uninitialization etc.
 * The session will no longer be usable afterwards.
 *
 * @param  pSession Session to be destroyed.
 *
 * @return status
 * @retval #MCUXCLSESSION_STATUS_OK     Session operation successful
 * @retval #MCUXCLSESSION_STATUS_ERROR  Error occurred during Session operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_destroy)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_destroy(
  mcuxClSession_Handle_t pSession
);

/**
 * @brief Function to switch to another random configuration.
 *
 * @param  session     Session to set the new random configuration.
 * @param  randomMode  Random data generation mode/algorithm. It should be the same mode used to initialize randomCtx.
 * @param  randomCtx   Random context.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_setRandom)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_setRandom(
    mcuxClSession_Handle_t session,
    mcuxClRandom_Mode_t randomMode,
    mcuxClRandom_Context_t randomCtx
);




/**
 * @brief Clean up HW Resources after error case. (Early Exit scenario)
 *
 * This function will reset all used HW Resources after an error (Early Exit scenario).
 * Additionally it will clear the CPU workspace and PKC workspace if applicable.
 * Random context associated with the session will not be cleared and must be reinitialized
 * before further usage.
 *
 * @attention This function must not be used in case of Fault Attack error case
 *            but instead Power-On-Reset or System Reset must be performed.
 *
 * @param pSession Session which is used when the error occurred.
 *
 * @return status
 * @retval #MCUXCLSESSION_STATUS_OK     The HW Resources cleaned up successfully
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_cleanupOnError)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_cleanupOnError(
  mcuxClSession_Handle_t pSession
);



/**
 * @}
 */ /* mcuxClSession_Functions */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSESSION_FUNCTIONS_H_ */
