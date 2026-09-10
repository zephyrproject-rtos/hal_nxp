/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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
 * @file  mcuxClOsccaSm2_Internal_Hash.h
 * @brief internal header for abstracting hash calls in mcuxClOsccaSm2
 */


#ifndef MCUXCLOSCCASM2_INTERNAL_HASH_H_
#define MCUXCLOSCCASM2_INTERNAL_HASH_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClHash_Types.h>
#include <mcuxClHash_Functions.h>
#include <mcuxClHash_Constants.h>
#include <internal/mcuxClHash_Internal.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClSession_Internal.h>


/******************************************************************************/
/* Macros to wrapper the init and partial compute the hash                    */
/******************************************************************************/
#define MCUXCLOSCCASM2_FP_CALC_HASHINITPRO(pSession, pCtx, algoHash, pIn, inSize, hashRet) \
    do{                                                                     \
        /* Initialize the hash context */                                   \
        MCUX_CSSL_FP_FUNCTION_CALL(retInitHash,                              \
            mcuxClHash_init(pSession,                                        \
                            MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES() \
                           (mcuxClHash_Context_t)(pCtx),                     \
                            MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY() \
                           algoHash) );                                     \
        if (MCUXCLHASH_STATUS_OK != retInitHash)                             \
        {                                                                   \
            hashRet = retInitHash;                                          \
            break;                                                          \
        }                                                                   \
                                                                            \
        /* Update hash context with partial input */                        \
        MCUX_CSSL_FP_FUNCTION_CALL(retProcessHash,                           \
            mcuxClHash_process(pSession,                                     \
                              (mcuxClHash_Context_t)(pCtx),                  \
                              (pIn),                                        \
                              inSize) );                                    \
        if (MCUXCLHASH_STATUS_OK != retProcessHash)                          \
        {                                                                   \
            hashRet = retProcessHash;                                       \
            break;                                                          \
        }                                                                   \
        hashRet = MCUXCLHASH_STATUS_OK;                                      \
    } while(false)

#define MCUXCLOSCCASM2_FP_CALLED_CALC_HASHINITPRO                            \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_init),                            \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process)

/******************************************************************************/
/* Macros to wrapper partial hash compute                                     */
/******************************************************************************/
#define MCUXCLOSCCASM2_FP_CALC_HASHPROCESS(pSession, pCtx, pIn, inSize, hashRet) \
    do{                                                                     \
        /* Update hash context with partial input */                        \
        MCUX_CSSL_FP_FUNCTION_CALL(retProcessHash,                           \
            mcuxClHash_process(pSession,                                     \
                              MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES() \
                              (mcuxClHash_Context_t)(pCtx),                  \
                              MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY() \
                              (pIn),                                        \
                              inSize) );                                    \
        if (MCUXCLHASH_STATUS_OK != retProcessHash)                          \
        {                                                                   \
            hashRet = retProcessHash;                                       \
            break;                                                          \
        }                                                                   \
        hashRet = MCUXCLHASH_STATUS_OK;                                      \
    } while(false)

#define MCUXCLOSCCASM2_FP_CALLED_CALC_HASHPROCESS                            \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process)

/******************************************************************************/
/* Macros to wrapper partial hash compute and final hash process              */
/******************************************************************************/
#define MCUXCLOSCCASM2_FP_CALC_HASHFINALPRO(pSession, pCtx, pIn, inSize, pOutput, hashRet) \
    do{                                                                     \
        uint32_t outLength = 0u;                                            \
        /* Update hash context with partial input */                        \
        MCUX_CSSL_FP_FUNCTION_CALL(retProHash,                               \
            mcuxClHash_process(pSession,                                     \
                              MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES() \
                              (mcuxClHash_Context_t)(pCtx),                  \
                              MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY() \
                              (mcuxCl_InputBuffer_t) (pIn),                  \
                              inSize) );                                    \
        if (MCUXCLHASH_STATUS_OK != retProHash)                              \
        {                                                                   \
            hashRet = retProHash;                                           \
            break;                                                          \
        }                                                                   \
                                                                            \
        /* Finalize hash computation */                                     \
        MCUX_CSSL_FP_FUNCTION_CALL(retFinalHash,                             \
            mcuxClHash_finish(pSession,                                      \
                              (mcuxClHash_Context_t)(pCtx),                  \
                              (pOutput),                                    \
                              &outLength) );                                \
        if (MCUXCLHASH_STATUS_OK != retFinalHash)                            \
        {                                                                   \
            hashRet = retFinalHash;                                         \
            break;                                                          \
        }                                                                   \
        hashRet = MCUXCLHASH_STATUS_OK;                                      \
    } while(false)

#define MCUXCLOSCCASM2_FP_CALLED_CALC_HASHFINALPRO                           \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process),                         \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_finish)

/******************************************************************************/
/* Macros to wrapper the SM3 hash context copy                                */
/******************************************************************************/
#define MCUXCLOSCCASM2_FP_CONTEXT_HASHCOPY(pCtxDst, pCtxOri)                              \
    do{                                                                                  \
        MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES() \
        ((mcuxClHash_Context_t)pCtxDst)->unprocessedLength = ((mcuxClHash_Context_t)pCtxOri)->unprocessedLength;    \
        ((mcuxClHash_Context_t)pCtxDst)->processedLength[0U] = ((mcuxClHash_Context_t)pCtxOri)->processedLength[0U];\
        ((mcuxClHash_Context_t)pCtxDst)->processedLength[1U] = ((mcuxClHash_Context_t)pCtxOri)->processedLength[1U];\
        ((mcuxClHash_Context_t)pCtxDst)->processedLength[2U] = ((mcuxClHash_Context_t)pCtxOri)->processedLength[2U];\
        ((mcuxClHash_Context_t)pCtxDst)->processedLength[3U] = ((mcuxClHash_Context_t)pCtxOri)->processedLength[3U];\
        ((mcuxClHash_Context_t)pCtxDst)->algo = ((mcuxClHash_Context_t)pCtxOri)->algo;                                        \
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy((uint8_t *)mcuxClHash_getUnprocessedPtr((mcuxClHash_Context_t)pCtxDst),                 \
                                                        (uint8_t *)mcuxClHash_getUnprocessedPtr((mcuxClHash_Context_t)pCtxOri),                 \
                                                        MCUXCLOSCCASM3_BLOCK_SIZE_SM3,                                           \
                                                        MCUXCLOSCCASM3_BLOCK_SIZE_SM3));                                         \
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy((uint8_t *)mcuxClHash_getStatePtr((mcuxClHash_Context_t)pCtxDst),                       \
                                                        (uint8_t *)mcuxClHash_getStatePtr((mcuxClHash_Context_t)pCtxOri),                       \
                                                        MCUXCLOSCCASM3_STATE_SIZE_SM3,                                           \
                                                        MCUXCLOSCCASM3_STATE_SIZE_SM3));                                         \
        MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY() \
    } while(false)

#endif /* MCUXCLOSCCASM2_INTERNAL_HASH_H_ */
