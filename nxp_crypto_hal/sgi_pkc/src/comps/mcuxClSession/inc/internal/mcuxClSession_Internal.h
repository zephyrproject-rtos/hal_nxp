/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
 * @file  mcuxClSession_Internal.h
 * @brief Internal definitions of the mcuxClSession component
 */

#ifndef MCUXCLSESSION_INERNAL_H_
#define MCUXCLSESSION_INERNAL_H_

#include <stddef.h>
#include <mcuxClToolchain.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief Function to allocate CPU buffer.
 *
 * This function allocates a buffer in CPU workarea specified in @p pSession.
 *
 * @param[in] pSession         Session handle.
 * @param[in] wordsToAllocate  The size of buffer to be allocated, in number of CPU words (uint32_t).
 *
 * @return pointer to the buffer if it is allocated successfully.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_allocateWords_cpuWa)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t*) mcuxClSession_allocateWords_cpuWa(mcuxClSession_Handle_t pSession, uint32_t wordsToAllocate);

/**
 * @brief Function to allocate PKC buffer.
 *
 * This function allocates a buffer in PKC workarea specified in @p pSession.
 *
 * The PKC workarea is assumed to be initialized to be PKC-word aligned.
 * However, size of each buffer (allocated from PKC workarea) is in number of CPU words,
 * and address of each buffer is CPU-word aligned, but might be not PKC-word aligned.
 * Callers need to take care if a buffer is PKC-word aligned, if it is used as a PKC operand.
 * For example, the total size of buffer(s) allocated before a PKC operand buffer shall
 * be a multiple of PKC wordsize.
 *
 * @param[in] pSession         Session handle.
 * @param[in] wordsToAllocate  The size of buffer to be allocated, in number of CPU words (uint32_t).
 *
 * @return pointer to the buffer if it is allocated successfully.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_allocateWords_pkcWa)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t*) mcuxClSession_allocateWords_pkcWa(mcuxClSession_Handle_t pSession, uint32_t wordsToAllocate);

/**
 * @brief Function to allocate UPTRT buffer in PKC/CPU WA.
 *
 * This function allocates a UPTRT table buffer in PKC or CPU WA (depending on feature flag MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM)
 * workarea specified in @p pSession. The allocated buffer is wordsToAllocate words.
 *
 * @param[in] pSession         Session handle.
 * @param[in] wordsToAllocate  The size of buffer to be allocated, in number of CPU words (uint32_t).
 *
 * @return pointer to the buffer if it is allocated successfully.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_allocateWords_uptrt)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t*) mcuxClSession_allocateWords_uptrt(mcuxClSession_Handle_t pSession, uint32_t wordsToAllocate);

/**
 * @brief Function to free CPU workarea.
 *
 * This function frees specified words from the tail of used CPU workarea.
 * The space is freed but **not** erased (zeroed).
 *
 * @param[in] pSession     Session handle.
 * @param[in] wordsToFree  The size of CPU workarea to be freed, in number of CPU words (uint32_t)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_freeWords_cpuWa)
void mcuxClSession_freeWords_cpuWa(
    mcuxClSession_Handle_t pSession,
    uint32_t wordsToFree
);

/**
 * @brief Function to free PKC workarea.
 *
 * This function frees specified words from the tail of used PKC workarea.
 * The space is freed but **not** erased (zeroed).
 *
 * @param[in] pSession     Session handle.
 * @param[in] wordsToFree  The size of PKC workarea to be freed, in number of CPU words (uint32_t)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_freeWords_pkcWa)
void mcuxClSession_freeWords_pkcWa(
    mcuxClSession_Handle_t pSession,
    uint32_t wordsToFree
);

/**
 * @brief Function to free UPTRT table in CPU/PKC workarea.
 *
 * This function frees UPTRT in PKC or CPU WA (depending on feature flag MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM)
 * wordsToFree words from the tail of used PKC/CPU workarea. The space is freed but **not** erased (zeroed).
 *
 * @param[in] pSession     Session handle.
 * @param[in] wordsToFree  The size of PKC/CPU (depending on feature flag MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM)
 *                         workarea to be freed, in number of CPU words (uint32_t)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_freeWords_uptrt)
void mcuxClSession_freeWords_uptrt(
    mcuxClSession_Handle_t pSession,
    uint32_t wordsToFree
);

/**
 * @brief Set the Security options in a Crypto Library session.
 *
 * @param  session          Handle for the current CL session.
 * @param  securityOptions  Security options that will be set
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_setSecurityOptions_Internal)
static inline void mcuxClSession_setSecurityOptions_Internal(
  mcuxClSession_Handle_t session,
  mcuxClSession_SecurityOptions_t securityOptions
)
{
/* Unused params*/
    (void) session;
    (void) securityOptions;
}

/**
 * @brief Get the Security options from a Crypto Library session.
 *
 * @param  session          Handle for the current CL session.
 *
 * @return securityOptions  Security options that will be returned
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_getSecurityOptions_Internal)
static inline mcuxClSession_SecurityOptions_t mcuxClSession_getSecurityOptions_Internal(
  mcuxClSession_Handle_t session
)
{
/* Unused param*/
    (void) session;
    return 0u;
}

/**
 * @brief Get the pointer to end of currently used buffer from a Crypto Library session.
 *
 * @param  session          Handle for the current CL session.
 *
 * @return pointer to the end of used buffer, it will be also a start of next allocated buffer.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_getEndOfUsedBuffer_Internal)
static inline uint32_t* mcuxClSession_getEndOfUsedBuffer_Internal(
  mcuxClSession_Handle_t session
)
{
    return (& session->cpuWa.buffer[session->cpuWa.used]);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSESSION_INERNAL_H_ */
