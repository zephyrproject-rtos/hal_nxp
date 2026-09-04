/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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

#ifndef MCUXCL_HASHMODES_MEMORYCOMPUTATION_H
#define MCUXCL_HASHMODES_MEMORYCOMPUTATION_H

#include <mcuxClCore_Macros.h>
#include <internal/mcuxClHashModes_ModesConstants.h>
#include <internal/mcuxClHashModes_ModesMemoryMacros.h>
#include <mcuxCsslCPreProcessor.h>

/**
 * Please define memory computation macros for a family of modes here.
 */


/** @brief Context size computation for all modes.
 *
 * State and unprocessed buffers are stored behind context struct.
 * Start of state is potentially shifted to ensure 64 Bit alignment. Maximum shift: MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET.
 * Subsequent buffers are not shifted as state and block sizes guarantee 64 Bit alignment for all algorithms that need it,
 * and 32 Bit alignment for all algorithms.
 * SecSha1 and SecSha2 use additional buffers for stateMask and unprocessedMask which is reflected in the doubled state and
 * block size compared to normal SHA-1 and SHA-2.
 * SecSha3 does not use an unprocessed mask buffer, therfore only the state size of the SecSha3 descriptors is doubled.
 * The resulting size is aligned to 32 Bit to allow easy conversion to word size in public memory header.
 */
#define MCUXCLHASHMODES_COMPUTE_CONTEXT_SIZE(DESCRIPTOR) \
    (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE( sizeof(mcuxClHash_ContextDescriptor_t) + \
                                      MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + \
                                      MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR) + \
                                      MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR) ) )

/*
 * C_SHA-1 mode
 */

/** @brief Memory consumption of C_SHA-1 oneshot */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_SHA1_ONESHOT(DESCRIPTOR) \
    ( ( MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR)) \
    + MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR)) ) * sizeof(uint32_t) )

/** @brief Memory consumption of C_SHA-1 process */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_SHA1_PROCESS(DESCRIPTOR)    4U

/** @brief Memory consumption of C_SHA-1 finish */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_SHA1_FINISH(DESCRIPTOR)     4U

/*
 * SecSha-1, SecSha-2 modes
 */

/** @brief Memory consumption of SecSha-1 and SecSha-2 oneshot */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SECSHA_1_2_ONESHOT(DESCRIPTOR) \
    (( (sizeof(uint32_t) + MCUXCLCORE_ALIGN_TO_WORDSIZE(sizeof(uint64_t), MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR) / 2U)) + \
       (sizeof(uint32_t) + MCUXCLCORE_ALIGN_TO_WORDSIZE(sizeof(uint64_t), MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR) / 2U)) ) * 2U)

/** @brief Memory consumption of SecSha-1 and SecSha-2 process */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SECSHA_1_2_PROCESS(DESCRIPTOR)    4U

/** @brief Memory consumption of SecSha-1 and SecSha-2 finish */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SECSHA_1_2_FINISH(DESCRIPTOR)     4U


/*
 * C_SHA-2 Modes
 */

/** @brief Memory consumption of C_SHA-2 oneshot */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_SHA2_ONESHOT(DESCRIPTOR) \
    ( ( ( (sizeof(uint32_t) + MCUXCLCORE_ALIGN_TO_WORDSIZE(sizeof(uint64_t), MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR)) ) / sizeof(uint32_t) ) \
    + ( (sizeof(uint32_t) + MCUXCLCORE_ALIGN_TO_WORDSIZE(sizeof(uint64_t), MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR))) / sizeof(uint32_t) ) ) * sizeof(uint32_t))

/** @brief Memory consumption of C_SHA-2 process */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_SHA2_PROCESS(DESCRIPTOR)    4U

/** @brief Memory consumption of C_SHA-2 finish */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_SHA2_FINISH(DESCRIPTOR)     4U

/*
 * SHA-2 SGI Blocking Modes
 */

/** @brief Memory consumption of SGI SHA-2 oneshot */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SGI_SHA2_ONESHOT(DESCRIPTOR) \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR)) * sizeof(uint32_t))

/** @brief Memory consumption of SGI SHA-2 process */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SGI_SHA2_PROCESS(DESCRIPTOR)      4U

/** @brief Memory consumption of SGI SHA-2 finish */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SGI_SHA2_FINISH(DESCRIPTOR)       4U

/*
 * SHA-2 SGI Non-Blocking Modes
 */

/** @brief Memory consumption of SGI SHA-2 non-blocking oneshot */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_NONBLOCKING_SHA2_ONESHOT(DESCRIPTOR) \
    ( ( MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t)) \
    + MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR)) ) * sizeof(uint32_t))

/** @brief Memory consumption of SGI SHA-2 non-blocking process */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_NONBLOCKING_SHA2_PROCESS(DESCRIPTOR) \
    ( MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t)) * sizeof(uint32_t) )

/** @brief Memory consumption of SGI SHA-2 non-blocking finish */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_NONBLOCKING_SHA2_FINISH(DESCRIPTOR)       4U

/*
 * Keccak C Modes (SHA-3 and SHAKE)
 */

/** @brief Memory consumption of C Keccak oneshot */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_KECCAK_ONESHOT(DESCRIPTOR) \
    ( ( MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR))) * sizeof(uint32_t) )


/** @brief Memory consumption of C Keccak process */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_KECCAK_PROCESS(DESCRIPTOR)      4U

/** @brief Memory consumption of C Keccak finish */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_C_KECCAK_FINISH(DESCRIPTOR)       4U

/*
 * SecKeccak Modes (SecSha-3 and SecShake)
 */

/** @brief Memory consumption of SecKeccak oneshot */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SECKECCAK_ONESHOT(DESCRIPTOR) \
    ( ( (sizeof(uint32_t) + MCUXCLCORE_ALIGN_TO_WORDSIZE(sizeof(uint64_t), MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR) / 2U) ) * 2U ) + \
        MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR) )

/** @brief Memory consumption of SecKeccak process */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SECKECCAK_PROCESS(DESCRIPTOR)      4U

/** @brief Memory consumption of SecKeccak finish */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_SECKECCAK_FINISH(DESCRIPTOR)       4U


#endif /* MCUXCL_HASHMODES_MEMORYCOMPUTATION_H */
