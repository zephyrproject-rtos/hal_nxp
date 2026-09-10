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

/**
 * @file  mcuxClEcc_Internal_Random.h
 * @brief internal header for abstracting random access in mcuxClEcc
 */


#ifndef MCUXCLECC_INTERNAL_RANDOM_H_
#define MCUXCLECC_INTERNAL_RANDOM_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClRandom.h>
#include <internal/mcuxClRandom_Internal_Functions.h>


/******************************************************************************/
/* Macro to generate high-quality random number in PKC workarea.              */
/******************************************************************************/
#if defined(MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND)
#include <internal/mcuxClSession_Internal.h>

#define MCUXCLECC_FP_RANDOM_HQRNG_PKCWA(callerID, pSession, pOutPKCWA, length, result)                        \
    do{                                                                                                      \
        /* Generate random number in CPU workarea. */                                                        \
        const uint32_t tempSizeWord = ((length) + (sizeof(uint32_t)) - 1u) / (sizeof(uint32_t));             \
        uint8_t * pTemp = (uint8_t*) mcuxClSession_allocateWords_cpuWa(pSession, tempSizeWord);               \
        if (NULL == pTemp)                                                                                   \
        {                                                                                                    \
            MCUX_CSSL_FP_FUNCTION_EXIT(callerID, MCUXCLECC_STATUS_FAULT_ATTACK);                               \
        }                                                                                                    \
        MCUXCLBUFFER_INIT(buffTemp, NULL, pTemp, length);                                                     \
        MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, (uint32_t)(pSession) + (uint32_t)buffTemp + (length)); \
        MCUX_CSSL_FP_FUNCTION_CALL(ret_random, mcuxClRandom_generate_internal(pSession, buffTemp, length));    \
        if (MCUXCLRANDOM_STATUS_OK != ret_random)                                                             \
        {                                                                                                    \
            result = MCUXCLECC_STATUS_RNG_ERROR;                                                              \
            break;                                                                                           \
        }                                                                                                    \
        /* Copy generated random numbers to PKC workarea. */                                                 \
        MCUXCLMEMORY_FP_MEMORY_COPY(pOutPKCWA, pTemp, length);                                                \
        /* Release temporary buffer. */                                                                      \
        mcuxClSession_freeWords_cpuWa(pSession, tempSizeWord);                                                \
        result = MCUXCLECC_STATUS_OK;                                                                         \
    } while(false)

#define MCUXCLECC_FP_CALLED_RANDOM_HQRNG_PKCWA \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal), \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)
#else
#define MCUXCLECC_FP_RANDOM_HQRNG_PKCWA(callerID, pSession, pOutPKCWA, length, result)                            \
    do{                                                                                                          \
        MCUXCLBUFFER_INIT(buffOutPKCWA, NULL, pOutPKCWA, length);                                                 \
        MCUX_CSSL_DI_RECORD(sumOfRandomGenerateParams, (uint32_t)(pSession) + (uint32_t)buffOutPKCWA + (length)); \
        MCUX_CSSL_FP_FUNCTION_CALL(ret_random, mcuxClRandom_generate_internal(pSession, buffOutPKCWA, length));    \
        if (MCUXCLRANDOM_STATUS_OK != ret_random)                                                                 \
        {                                                                                                        \
            result = MCUXCLECC_STATUS_RNG_ERROR;                                                                  \
        }                                                                                                        \
        else                                                                                                     \
        {                                                                                                        \
            result = MCUXCLECC_STATUS_OK;                                                                         \
        }                                                                                                        \
    } while(false)

#define MCUXCLECC_FP_CALLED_RANDOM_HQRNG_PKCWA  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal)
#endif /* MCUXCL_FEATURE_ELS_ACCESS_PKCRAM_WORKAROUND */


#endif /* MCUXCLECC_INTERNAL_RANDOM_H_ */
