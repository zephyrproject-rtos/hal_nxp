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
 * @file  mcuxClSession_Internal_Functions.h
 * @brief Internal functions of the mcuxClSession component
 */

#ifndef MCUXCLSESSION_INTERNAL_FUNCTIONS_H_
#define MCUXCLSESSION_INTERNAL_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCrc.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_FeatureConfig.h>


#include <mcuxClSession.h>
#include <mcuxClResource_Types.h>
#include <internal/mcuxClResource_Internal_Functions.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Trigger user callback function
 *
 * @param session  Handle for the current CL session.
 * @param status   parameter to pass to user callback function
 *
 * @return status
 * @retval #MCUXCLSESSION_STATUS_OK     Session operation successful
 * @retval #MCUXCLSESSION_STATUS_ERROR  Error occurred during Session operation
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_triggerUserCallback)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_triggerUserCallback(
    mcuxClSession_Handle_t session,
    uint32_t status
);

/**
 * @brief (inline) function to get the DMA input channel.
 *
 * @param[in] session  Session handle.
 *
 * @return the DMA input channel.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_getDmaInputChannel)
static inline mcuxClSession_Channel_t mcuxClSession_getDmaInputChannel(
    mcuxClSession_Handle_t session
    )
{
    return session->jobContext.dmaChannels.input;
}

/**
 * @brief (inline) function to get the DMA output channel.
 *
 * @param[in] session  Session handle.
 *
 * @return the DMA output channel.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_getDmaOutputChannel)
static inline mcuxClSession_Channel_t mcuxClSession_getDmaOutputChannel(
    mcuxClSession_Handle_t session
    )
{
    return session->jobContext.dmaChannels.output;
}

/**
 * @brief Set workarea pointer to exchange information with the interrupt
 *
 * @param session        Handle for the current CL session.
 * @param pClWorkarea    Pointer to CL data which can be used by the interrupt
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_job_setClWorkarea)
static inline void mcuxClSession_job_setClWorkarea(
    mcuxClSession_Handle_t session,
    void * pClWorkarea
    )
{
    session->jobContext.pClWorkarea = pClWorkarea;
}

/**
 * @brief Get clWorkarea pointer
 *
 * @param session        Handle for the current CL session.
 *
 * @return Void pointer to the current clWorkarea in the session jobcontext
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_job_getClWorkarea)
static inline void* mcuxClSession_job_getClWorkarea(
    mcuxClSession_Handle_t session
    )
{
    return session->jobContext.pClWorkarea;
}


/**
 * @brief This function computes a CRC value for some input data and saves it in the session.
 *        The CRC value is used for external verification in the session.
 *
 * @param session           Handle for the current CL session.
 * @param dataToVerify      The input data for which the CRC is computed.
 * @param dataLength        The length of the input data.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_computeAndSetCrcForExternalVerification)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSession_computeAndSetCrcForExternalVerification(
    mcuxClSession_Handle_t session,
    uint8_t *dataToVerify,
    uint32_t dataLength
    )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSession_computeAndSetCrcForExternalVerification);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSession_computeAndSetCrcForExternalVerification);
}

#ifdef MCUXCLSESSION_FEATURE_INTERNAL_CLEANUP_FREED_WA
/**
 * @brief Clean up a Crypto Library session.
 *
 * This function will (securely) cleanup the currently unused dirty memory in the session.
 *
 * @param  pSession Session to be cleaned.
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_cleanup_freedWorkareas)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSession_cleanup_freedWorkareas(
  mcuxClSession_Handle_t pSession
);
#endif /* MCUXCLSESSION_FEATURE_INTERNAL_CLEANUP_FREED_WA */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSESSION_INTERNAL_FUNCTIONS_H_ */
