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

#ifndef MCUXCLCIPHERMODES_SGI_CLEANUP_H_
#define MCUXCLCIPHERMODES_SGI_CLEANUP_H_

#include <mcuxClSession_Types.h>
#include <mcuxClSgi_Types.h>

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClKey.h>
#include <mcuxClMemory_Copy.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClCipherModes_Sgi_Functions.h>

/* Defines to control HW cleanup in cleanupOnExit functions. */
#define MCUXCLCIPHERMODES_CLEANUP_HW_ALL     0x00000F0FU
#define MCUXCLCIPHERMODES_CLEANUP_HW_SGI     0x0000000FU
#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
#define MCUXCLCIPHERMODES_CLEANUP_HW_DMA     0x00000F00U
#endif /* defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING) */
#define MCUXCLCIPHERMODES_CLEANUP_HW_NONE    0xFFFF0000U

/**
 * @brief Function to handle normal exit
 *
 * Use this function to leave functions in this file in normal exit cases.
 * It frees CPU workarea and uninitializes the SGI.
 *
 * @param      session          Handle for the current CL session.
 * @param      pContext         Pointer to multipart context (word-aligned)
 * @param      key              Handle for the key (word-aligned).
 *                              If the key is in the context, this param shall be NULL.
 * @param[in]  cpuWaSizeInWords Number of cpu wa words to free
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_cleanupOnExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_cleanupOnExit(
    mcuxClSession_Handle_t session,
    mcuxClCipherModes_Context_Aes_Sgi_t *pContext,
    mcuxClKey_Handle_t key,
    uint32_t cpuWaSizeInWords
);

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @brief Function to handle normal exit
 *
 * Use this function to leave functions in this file in normal exit cases.
 * It frees CPU workarea, releases the DMA and uninitializes the SGI.
 *
 * @param      session          Handle for the current CL session.
 * @param      pContext         Pointer to multipart context (word-aligned)
 * @param      key              Handle for the used key (word-aligned)
 * @param[in]  cpuWaSizeInWords Number of cpu wa words to free
 * @param[in]  cleanupDmaSgi    Instructions on whether to clean DMA, SGI,
 *                               can be either of these values:
 *                                 #MCUXCLCIPHERMODES_CLEANUP_HW_ALL
 *                                 #MCUXCLCIPHERMODES_CLEANUP_HW_SGI
 *                                 #MCUXCLCIPHERMODES_CLEANUP_HW_DMA
 *                                 #MCUXCLCIPHERMODES_CLEANUP_HW_NONE
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_cleanupOnExit_dmaDriven)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_cleanupOnExit_dmaDriven(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_Context_Aes_Sgi_t *pContext,
  mcuxClKey_Handle_t key,
  uint32_t cpuWaSizeInWords,
  uint32_t cleanupDmaSgi
);

#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

#endif /* MCUXCLCIPHERMODES_SGI_CLEANUP_H_ */
