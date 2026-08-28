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

/**
 * @file  mcuxClSession_jobHandling.c
 * @brief mcuxClSession functions for job handling
 */

#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClSession_Internal_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_configure_job)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_configure_job(
  mcuxClSession_Handle_t session,
  mcuxClSession_Channels_t dmaChannels,
  mcuxClSession_Callback_t pUserCallback,
  void* pUserData
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSession_configure_job);

    session->jobContext.dmaChannels = dmaChannels;
    session->jobContext.pUserCallback = pUserCallback;
    session->jobContext.pUserData = pUserData;

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClSession_configure_job, MCUXCLSESSION_STATUS_OK, MCUXCLSESSION_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_triggerUserCallback)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_triggerUserCallback(
  mcuxClSession_Handle_t session,
  uint32_t status
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSession_triggerUserCallback);

    mcuxClSession_Callback_t pUserCallback = session->jobContext.pUserCallback;

    if(NULL == pUserCallback)
    {
        MCUXCLSESSION_ERROR(session, MCUXCLSESSION_STATUS_ERROR);
    }

    pUserCallback(status, session->jobContext.pUserData);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClSession_triggerUserCallback, MCUXCLSESSION_STATUS_OK);
}
