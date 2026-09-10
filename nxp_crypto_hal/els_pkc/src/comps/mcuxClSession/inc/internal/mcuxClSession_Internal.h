/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#if defined(__COVERITY__)
#include <internal/mcuxClPkc_Macros.h>
#endif /* defined(__COVERITY__) */

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief (inline) function to allocate CPU buffer.
 *
 * This function allocates a buffer in CPU workarea specified in @p pSession.
 *
 * @param[in] pSession         Session handle.
 * @param[in] wordsToAllocate  The size of buffer to be allocated, in number of CPU words (uint32_t).
 *
 * @return pointer to the buffer if it is allocated successfully;
 *         NULL if the buffer cannot be allocated.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_allocateWords_cpuWa)
static inline uint32_t* mcuxClSession_allocateWords_cpuWa(
    mcuxClSession_Handle_t pSession,
    uint32_t wordsToAllocate)
{
    uint32_t * pCpuBuffer = NULL;
    const uint32_t usedWords = pSession->cpuWa.used;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(usedWords, 0u, (UINT32_MAX >> 2u), NULL)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(wordsToAllocate, 0u, (UINT32_MAX >> 2u) - usedWords, NULL)
    const uint32_t expectedUsed = usedWords + wordsToAllocate;

    if (expectedUsed <= pSession->cpuWa.size)
    {
        pCpuBuffer = & (pSession->cpuWa.buffer[usedWords]);
        pSession->cpuWa.used = expectedUsed;

        if (expectedUsed > pSession->cpuWa.dirty)
        {
            pSession->cpuWa.dirty = expectedUsed;
        }
    }

    return pCpuBuffer;
}

/**
 * @brief Get workarea buffer
 *
 * @param session   Handle for the current CL session.
 *
 * @return Pointer to first unused place in current work area
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_getCpuWaBuffer)
static inline uint32_t* mcuxClSession_getCpuWaBuffer(mcuxClSession_Handle_t pSession)
{
    return &(pSession->cpuWa.buffer[pSession->cpuWa.used]);
}

/**
 * @brief (inline) function to allocate PKC buffer.
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
 * @return pointer to the buffer if it is allocated successfully;
 *         NULL if the buffer cannot be allocated.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_allocateWords_pkcWa)
static inline uint32_t* mcuxClSession_allocateWords_pkcWa(
    mcuxClSession_Handle_t pSession,
    uint32_t wordsToAllocate)
{
    uint32_t * pPkcBuffer = NULL;
    const uint32_t usedWords = pSession->pkcWa.used;

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(usedWords, 0u, MCUXCLPKC_RAM_SIZE, NULL)
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(wordsToAllocate, 0u, MCUXCLPKC_RAM_SIZE - usedWords, NULL)
    const uint32_t expectedUsed = usedWords + wordsToAllocate;

    if (expectedUsed <= pSession->pkcWa.size)
    {
        pPkcBuffer = & (pSession->pkcWa.buffer[usedWords]);
        pSession->pkcWa.used = expectedUsed;

        if (expectedUsed > pSession->pkcWa.dirty)
        {
            pSession->pkcWa.dirty = expectedUsed;
        }
    }

    return pPkcBuffer;
}

/**
 * @brief (inline) function to free CPU workarea.
 *
 * This function frees specified words from the tail of used CPU workarea.
 * The space is freed but **not** erased (zeroed).
 *
 * @param[in] pSession     Session handle.
 * @param[in] wordsToFree  The size of CPU workarea to be freed, in number of CPU words (uint32_t)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_freeWords_cpuWa)
static inline void mcuxClSession_freeWords_cpuWa(
    mcuxClSession_Handle_t pSession,
    uint32_t wordsToFree)
{
    if(wordsToFree > pSession->cpuWa.used)
    {
        pSession->cpuWa.used = 0u;
    }
    else
    {
        pSession->cpuWa.used -= wordsToFree;
    }
}

/**
 * @brief (inline) function to free PKC workarea.
 *
 * This function frees specified words from the tail of used PKC workarea.
 * The space is freed but **not** erased (zeroed).
 *
 * @param[in] pSession     Session handle.
 * @param[in] wordsToFree  The size of PKC workarea to be freed, in number of CPU words (uint32_t)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSession_freeWords_pkcWa)
static inline void mcuxClSession_freeWords_pkcWa(
    mcuxClSession_Handle_t pSession,
    uint32_t wordsToFree)
{
    if(wordsToFree > pSession->pkcWa.used)
    {
        pSession->pkcWa.used = 0u;
    }
    else
    {
        pSession->pkcWa.used -= wordsToFree;
    }
}

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


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSESSION_INERNAL_H_ */
