/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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

/** @file  mcuxClAeadModes_Sgi_Cleanup.h
 *  @brief Internal cleanup function declaration for the mcuxClAeadModes component */

#ifndef MCUXCLAEADMODES_SGI_CLEANUP_H_
#define MCUXCLAEADMODES_SGI_CLEANUP_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <internal/mcuxClAeadModes_Common_Wa.h>
#include <internal/mcuxClAeadModes_Sgi_Ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Function to handle the normal exit for AEAD multipart.
 *
 * Use this function to leave highest-level mode functions in normal exit cases.
 * It flushes the SGI Key in context if not preloaded, frees CPU workarea and uninitializes the SGI.
 *
 * @param      session          Handle for the current CL session.
 * @param      pContext         Pointer to multipart context (word-aligned)
 * @param[in]  cpuWaSizeInWords Number of cpu wa words to free
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_cleanupOnMultipartExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_cleanupOnMultipartExit(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *pContext,
  uint32_t cpuWaSizeInWords);

/**
 * @brief Function to handle the normal exit for AEAD oneshot.
 *
 * Use this function to leave highest-level mode functions in normal exit cases.
 * It flushes the SGI Key if not preloaded, frees CPU workarea and uninitializes the SGI.
 *
 * @param      session          Handle for the current CL session.
 * @param      key              Handle for the key (word-aligned).
 * @param[in]  cpuWaSizeInWords Number of cpu wa words to free
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_cleanupOnOneshotExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_cleanupOnOneshotExit(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint32_t cpuWaSizeInWords);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*MCUXCLAEADMODES_SGI_CLEANUP_H_*/
