/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClMac.c
 *  @brief Implementation of mcuxClMac component public API */

#include <mcuxClSession.h>
#include <mcuxClMac.h>
#include <internal/mcuxClMac_Ctx.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClSession_Internal_EntryExit.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMac_compute)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_compute(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMac_compute, mode->common.protectionToken_compute);

  MCUX_CSSL_FP_FUNCTION_CALL(result, mode->common.compute(
                                      session,
                                      key,
                                      mode,
                                      pIn,
                                      inLength,
                                      pMac,
                                      pMacLength
  ));

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClMac_compute, result, MCUXCLMAC_STATUS_FAULT_ATTACK);
}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMac_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_init(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMac_init, mode->common.protectionToken_init);

  pContext->pMode = mode;
  MCUX_CSSL_FP_FUNCTION_CALL(result, mode->common.init(
                                      session,
                                      pContext,
                                      key
  ));

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClMac_init, result, MCUXCLMAC_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMac_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_process(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMac_process, pContext->pMode->common.protectionToken_process);

  MCUX_CSSL_FP_FUNCTION_CALL(result, pContext->pMode->common.process(
                                      session,
                                      pContext,
                                      pIn,
                                      inLength
  ));

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClMac_process, result, MCUXCLMAC_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMac_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_finish(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMac_finish, pContext->pMode->common.protectionToken_finish);

  MCUX_CSSL_FP_FUNCTION_CALL(result, pContext->pMode->common.finish(
                                      session,
                                      pContext,
                                      pMac,
                                      pMacLength
  ));

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClMac_finish, result, MCUXCLMAC_STATUS_FAULT_ATTACK);
}

