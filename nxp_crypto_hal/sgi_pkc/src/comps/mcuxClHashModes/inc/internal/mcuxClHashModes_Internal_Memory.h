/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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

/** @file  mcuxClHashModes_Internal_Memory.h
 *  @brief Internal memory consumption definitions of the mcuxClHashModes component
 */

#ifndef MCUXCLHASHMODES_INTERNAL_MEMORY_H_
#define MCUXCLHASHMODES_INTERNAL_MEMORY_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClHash_Types.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_MemoryComputation.h>
#include <internal/mcuxClHashModes_Internal_nonBlocking.h>


#ifdef __cplusplus
extern "C" {
#endif


/**********************************************
 * Block, State and Counter sizes
 **********************************************/

#define MCUXCLHASH_BLOCK_SIZE_SHA_1              (64U) ///< SHA-1 block size: 512 bit (64 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA_224            (64U) ///< SHA-224 block size: 512 bit (64 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA_256            (64U) ///< SHA-256 block size: 512 bit (64 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA_384           (128U) ///< SHA-384 block size: 1024 bit (128 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA_512           (128U) ///< SHA-512 block size: 1024 bit (128 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA3_224          (144U) ///< SHA3-224 block size: 1152 bit (144 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA3_256          (136U) ///< SHA3-256 block size: 1088 bit (136 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA3_384          (104U) ///< SHA3-384 block size: 832 bit (104 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA3_512           (72U) ///< SHA3-512 block size: 576 bit (72 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA3_SHAKE_128    (168U) ///< SHAKE-128 block size: 1344 bit (168 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SHA3_SHAKE_256    (136U) ///< SHAKE-256 block size: 1088 bit (136 bytes)
#define MCUXCLHASH_BLOCK_SIZE_SECSHA_1          (2U * MCUXCLHASH_BLOCK_SIZE_SHA_1) ///<SECSHA-1 block size: 2*512 bit (2*64 bytes). Includes the mask
#define MCUXCLHASH_BLOCK_SIZE_SECSHA_224        (2U * MCUXCLHASH_BLOCK_SIZE_SHA_224) ///<SECSHA-224 block size: 2*512 bit (2*64 bytes). Includes the mask
#define MCUXCLHASH_BLOCK_SIZE_SECSHA_256        (2U * MCUXCLHASH_BLOCK_SIZE_SHA_256) ///<SECSHA-256 block size: 2*512 bit (2*64 bytes). Includes the mask
#define MCUXCLHASH_BLOCK_SIZE_SECSHA_384        (2U * MCUXCLHASH_BLOCK_SIZE_SHA_384) ///<SECSHA-384 block size: 2*1024 bit (2*128 bytes). Includes the mask
#define MCUXCLHASH_BLOCK_SIZE_SECSHA_512        (2U * MCUXCLHASH_BLOCK_SIZE_SHA_512) ///<SECSHA-512 block size: 2*1024 bit (2*128 bytes). Includes the mask
#define MCUXCLHASH_BLOCK_SIZE_MAX_WITHOUT_MASK  (MCUXCLHASH_BLOCK_SIZE_SHA3_SHAKE_128) ///<Maximum block size without accounting for SecSha masks
#define MCUXCLHASH_BLOCK_SIZE_MIN               (MCUXCLHASH_BLOCK_SIZE_SHA_1)  ///< Minimum block size
#define MCUXCLHASH_BLOCK_SIZE_MAX               (MCUXCLHASH_BLOCK_SIZE_SHA3_SHAKE_128) ///< Maximum block size

#define MCUXCLHASH_STATE_SIZE_SHA_1              (20U) ///< SHA-1 state size: 160 bit (20 bytes)
#define MCUXCLHASH_STATE_SIZE_SHA_224            (32U) ///< SHA-224 state size: 256 bit (32 bytes)
#define MCUXCLHASH_STATE_SIZE_SHA_256            (32U) ///< SHA-256 state size: 256 bit (32 bytes)
#define MCUXCLHASH_STATE_SIZE_SHA_384            (64U) ///< SHA-384 state size: 512 bit (64 bytes)
#define MCUXCLHASH_STATE_SIZE_SHA_512            (64U) ///< SHA-512 state size: 512 bit (64 bytes)
#define MCUXCLHASH_STATE_SIZE_SHA3               (200U) ///< SHA3 all variants state size: 1600 bits (200 bytes)
#define MCUXCLHASH_STATE_SIZE_SECSHA_1           (2U * MCUXCLHASH_STATE_SIZE_SHA_1) ///< SECSHA-1 state size: 2*160 bit (2*20 bytes). Includes the mask
#define MCUXCLHASH_STATE_SIZE_SECSHA_224         (2U * MCUXCLHASH_STATE_SIZE_SHA_224) ///< SECSHA-224 state size: 2*256 bit (2*32 bytes). Includes the mask
#define MCUXCLHASH_STATE_SIZE_SECSHA_256         (2U * MCUXCLHASH_STATE_SIZE_SHA_256) ///< SECSHA-256 state size: 2*256 bit (2*32 bytes). Includes the mask
#define MCUXCLHASH_STATE_SIZE_SECSHA_384         (2U * MCUXCLHASH_STATE_SIZE_SHA_384) ///< SECSHA-384 state size: 2*512 bit (2*64 bytes). Includes the mask
#define MCUXCLHASH_STATE_SIZE_SECSHA_512         (2U * MCUXCLHASH_STATE_SIZE_SHA_512) ///< SECSHA-512 state size: 2*512 bit (2*64 bytes). Includes the mask
#define MCUXCLHASH_STATE_SIZE_SECSHA3            (2U * MCUXCLHASH_STATE_SIZE_SHA3) ///< SECSHA3 all variants state size: 2*1600 bits (2*200 bytes). Includes the mask

#define MCUXCLHASH_STATE_SIZE_MIN                (MCUXCLHASH_STATE_SIZE_SHA_1) ///< Minimum state size
#define MCUXCLHASH_STATE_SIZE_MAX                (MCUXCLHASH_STATE_SIZE_SHA3) ///< Maximum block size

#define MCUXCLHASH_COUNTER_SIZE_SHA_1               (8U) ///< Counter size for SHA-1 padding
#define MCUXCLHASH_COUNTER_SIZE_SHA_224             (8U) ///< Counter size for SHA-224 padding
#define MCUXCLHASH_COUNTER_SIZE_SHA_256             (8U) ///< Counter size for SHA-256 padding
#define MCUXCLHASH_COUNTER_SIZE_SHA_384            (16U) ///< Counter size for SHA-384 padding
#define MCUXCLHASH_COUNTER_SIZE_SHA_512            (16U) ///< Counter size for SHA-512 padding
#define MCUXCLHASH_COUNTER_SIZE_SHA3               (16U) ///< Counter size for SHA3 padding
#define MCUXCLHASH_COUNTER_SIZE_MAX                (16U) ///< Maximal counter size for any supported algorithm


/**********************************************
 * Checked input sizes
 **********************************************/

/**
 * @brief Check processed length mask is used to detect when the maximum input size to a hash function has been exceeded.
 * Specifically, SHA-1 and SHA-2 cannot exceed processing 2^64 and 2^128 _bits_ of input.
 * Therefore, a mask of the 3 highest bits of the highest byte of the counter is sufficient to check if this has occurred.
 * Checks are performed only in the multipart variants, in mcuxClHash_process/mcuxClHash_finish and mcuxClHash_import_state.
 */

#define MCUXCLHASH_PROCESSED_LENGTH_NO_LIMIT                        (0x0u)  ///< Mask of the highest bits in the processed counter when a hash function has no limit regarding the input size
#define MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA1                 (0xE0u) ///< Mask of the highest bits in the processed counter that should not be set for SHA-1
#define MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA2                 (0xE0u) ///< Mask of the highest bits in the processed counter that should not be set for SHA-2
#define MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA3                 (MCUXCLHASH_PROCESSED_LENGTH_NO_LIMIT) ///< Mask of the highest bits in the processed counter that should not be set for SHA-3

/**********************************************
 * Workarea sizes
 **********************************************/

/**
 * @brief WaCpu buffer is used in oneshot mode to add padding to the last message block.
 * Further it is used to store the resulting hash and in case of SHA-256 an RTF.
 * Regardless of SHA-2 variant, the size requirement is dominated by block size.
 * In streaming mode WaCpu buffer is not used at all.
 */

#define MCUXCLHASH_INTERNAL_WACPU_SIZE_SHA2_512 \
  MCUXCLCORE_MAX( \
    MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_512), \
    MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA_512) \
  )

/* Work area size for the C implementation of SHA-3 and Shake */
/*
 * A union is used here to determine the maximum size of the cpu wa. This type is NOT intended to be used in the code.
 * Usage of nested MAX is not possible here as the evaluated lines getting too long for the build system.
 */
typedef union
{
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_224)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_256)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_384)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_512)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_128)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_256)];
} mcuxClHashModes_Internal_MaxUnion_Sha3Shake_Oneshot_CpuWa_t;

/** @brief Maximum WA size over all active SHA3 / SHAKE modes for oneshot */
#define MCUXCLHASH_INTERNAL_WACPU_SIZE_SHA3_ONESHOT (sizeof(mcuxClHashModes_Internal_MaxUnion_Sha3Shake_Oneshot_CpuWa_t))


typedef union
{
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_224)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_256)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_384)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_512)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_128)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_256)];
} mcuxClHashModes_Internal_MaxUnion_Sha3Shake_Process_CpuWa_t;

/** @brief Maximum WA size over all active SHA3 / SHAKE modes for process */
#define MCUXCLHASH_INTERNAL_WACPU_SIZE_SHA3_PROCESS (sizeof(mcuxClHashModes_Internal_MaxUnion_Sha3Shake_Process_CpuWa_t))


typedef union
{
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_224)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_256)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_384)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_512)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_128)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_256)];
} mcuxClHashModes_Internal_MaxUnion_Sha3Shake_Finish_CpuWa_t;

/** @brief Maximum WA size over all active SHA3 / SHAKE modes for finish */
#define MCUXCLHASH_INTERNAL_WACPU_SIZE_SHA3_FINISH (sizeof(mcuxClHashModes_Internal_MaxUnion_Sha3Shake_Finish_CpuWa_t))


/* Work area size for the implementation of SecSha-3/SecShake */

typedef union
{
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_224)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_256)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_384)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_512)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_128)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_256)];
} mcuxClHashModes_Internal_MaxUnion_SecSha3Shake_Oneshot_CpuWa_t;

/** @brief Maximum WA size over all active SecSha-3 / SecShake modes for oneshot */
#define MCUXCLHASH_INTERNAL_WACPU_SIZE_SECSHA3SHAKE_ONESHOT (sizeof(mcuxClHashModes_Internal_MaxUnion_SecSha3Shake_Oneshot_CpuWa_t))

typedef union
{
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_224)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_256)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_384)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_512)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_128)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_256)];
} mcuxClHashModes_Internal_MaxUnion_SecSha3Shake_Process_CpuWa_t;

/** @brief Maximum WA size over all active SecSha-3 / SecShake modes for process */
#define MCUXCLHASH_INTERNAL_WACPU_SIZE_SECSHA3SHAKE_PROCESS (sizeof(mcuxClHashModes_Internal_MaxUnion_SecSha3Shake_Process_CpuWa_t))

typedef union
{
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_224)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_256)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_384)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_512)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_128)];
  uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_256)];
} mcuxClHashModes_Internal_MaxUnion_SecSha3Shake_Finish_CpuWa_t;

/** @brief Maximum WA size over all active SecSha-3 / SecShake modes for finish */
#define MCUXCLHASH_INTERNAL_WACPU_SIZE_SECSHA3SHAKE_FINISH (sizeof(mcuxClHashModes_Internal_MaxUnion_SecSha3Shake_Finish_CpuWa_t))


typedef union
{
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sha1[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA1)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha1[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA1)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sgi_Sha2_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sgi_Sha2_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sgi_Sha2_384[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_384)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sgi_Sha2_512[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_512)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sgi_Sha2_512_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_512_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sgi_Sha2_512_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_512_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha2_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha2_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha2_384[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA_384)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha2_512[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA_512)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha2_512_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA_512_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha2_512_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA_512_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha2_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha2_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha2_384[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA_384)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha2_512[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA_512)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha2_512_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA_512_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha2_512_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA_512_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sha2_224_Nonblocking[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sha2_256_Nonblocking[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sha2_384_Nonblocking[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_384)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sha2_512_Nonblocking[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_512)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sha2_512_224_Nonblocking[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_512_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_Sha2_512_256_Nonblocking[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_NONBLOCKING_SHA_512_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_384)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_512)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_128)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_C_Sha3_Shake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_224[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_224)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_256)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_384[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_384)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecSha3_512[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHA3_512)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_128[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_128)];
    uint8_t mcuxClHash_Internal_WaCpu_Size_SecShake_256[MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(MCUXCLHASHMODES_DESCRIPTOR_SECSHAKE_256)];
} mcuxClHashModes_Internal_MaxUnion_WaCpu_t;
#define MCUXCLHASHMODES_INTERNAL_WACPU_MAX (sizeof(mcuxClHashModes_Internal_MaxUnion_WaCpu_t))

/* For SecSha-1/2/3 MCUXCLHASH_STATE_SIZE_MAX accounts both for state and state mask buffers.
 *
 * For SecSha-1/2 MCUXCLHASH_BLOCK_SIZE_MAX accounts for block and block mask buffers.
 * For SecSha-3 MCUXCLHASH_BLOCK_SIZE_MAX only accounts for the block buffer, as the block mask buffer is unused.
 */
#define MCUXCLHASHMODES_CONTEXT_MAX_SIZE_INTERNAL \
  (MCUXCLCORE_ALIGN_TO_WORDSIZE(sizeof(uint32_t), \
                               sizeof(mcuxClHash_ContextDescriptor_t) + MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET \
                                   + MCUXCLHASH_BLOCK_SIZE_MAX + MCUXCLHASH_STATE_SIZE_MAX))

#define MCUXCLHASHMODES_SHAKE128_CONTEXT_SIZE_INTERNAL       MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_128)
#define MCUXCLHASHMODES_SHAKE256_CONTEXT_SIZE_INTERNAL       MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT(MCUXCLHASHMODES_DESCRIPTOR_C_SHA3_SHAKE_256)

#define MCUXCLHASHMODES_SHA256_CONTEXT_SIZE_INTERNAL         MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT(MCUXCLHASHMODES_DESCRIPTOR_SGI_SHA_256, MCUXCLHASHMODES_DESCRIPTOR_C_SHA_256)



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_INTERNAL_MEMORY_H_ */
