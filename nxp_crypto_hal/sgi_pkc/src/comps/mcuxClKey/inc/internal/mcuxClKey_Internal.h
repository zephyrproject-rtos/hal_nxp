/*--------------------------------------------------------------------------*/
/* Copyright 2022, 2024-2026 NXP                                            */
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

#ifndef MCUXCLKEY_INTERNAL_H_
#define MCUXCLKEY_INTERNAL_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClKey_Internal_EncodingMechanisms.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Constants_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Define encoding IDs */
/**
 * @defgroup mcuxClKey_KeyTypes mcuxClKey_KeyTypes
 * @brief Defines all encoding types of @ref mcuxClKey
 * @ingroup mcuxClKey_Macros
 * @{
 */

/* Specification bit field:
 * bits:     31 .. 16 | 15 .. 8 |   7    | 6 .. 4 | 3 .. 0
 * fields:   offset   |  size   | chunk  | action |  part
 *
 * Part:     Indicates the part for multi-part keys (0x0 means the key is a single part)
 * Action:   Indicates how the load/store should function (normale/secure/pointer copy)
 * Chunk:    Indicates a partial load/store (specify offset and size as well)
 * Size:     Size of the partial load/store (only to be unused in conjunction with "chunk")
 * Offset:   Offset of the partial load/store (only to be unused in conjunction with "chunk")
 */

// Part identifier:
#define MCUXCLKEY_ENCODING_SPEC_PART_MASK                    0x0000000Fu
#define MCUXCLKEY_ENCODING_SPEC_PART_ALL                     0x00000000u

// Spec for generic single-part keys:
#define MCUXCLKEY_ENCODING_SPEC_SINGLE_PART                  0x00000000u

// Spec for multi-part keys:
#define MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_PRIVKEY            0x00000001u
#define MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_SUBPRIVKEY         0x00000002u
#define MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_PRIVKEYHALFHASH    0x00000003u
#define MCUXCLKEY_ENCODING_SPEC_RSA_N                        0x00000004u
#define MCUXCLKEY_ENCODING_SPEC_RSA_E                        0x00000005u
#define MCUXCLKEY_ENCODING_SPEC_RSA_D                        0x00000006u
#define MCUXCLKEY_ENCODING_SPEC_RSA_P                        0x00000007u
#define MCUXCLKEY_ENCODING_SPEC_RSA_Q                        0x00000008u
#define MCUXCLKEY_ENCODING_SPEC_RSA_DP                       0x00000009u
#define MCUXCLKEY_ENCODING_SPEC_RSA_DQ                       0x0000000Au
#define MCUXCLKEY_ENCODING_SPEC_RSA_QINV                     0x0000000Bu

#define MCUXCLKEY_ENCODING_SPEC_MLKEM_PK_RHO                 0x00000001u
#define MCUXCLKEY_ENCODING_SPEC_MLKEM_PK_T                   0x00000002u
#define MCUXCLKEY_ENCODING_SPEC_MLKEM_SK_S                   0x00000003u
#define MCUXCLKEY_ENCODING_SPEC_MLKEM_SK_PK                  0x00000004u
#define MCUXCLKEY_ENCODING_SPEC_MLKEM_SK_H_PK                0x00000005u
#define MCUXCLKEY_ENCODING_SPEC_MLKEM_SK_Z                   0x00000006u

#define MCUXCLKEY_ENCODING_SPEC_MLDSA_PK_RHO                 0x00000001u
#define MCUXCLKEY_ENCODING_SPEC_MLDSA_PK_T                   0x00000002u
#define MCUXCLKEY_ENCODING_SPEC_MLDSA_SK_RHO                 0x00000003u
#define MCUXCLKEY_ENCODING_SPEC_MLDSA_SK_K                   0x00000004u
#define MCUXCLKEY_ENCODING_SPEC_MLDSA_SK_H_PK                0x00000005u
#define MCUXCLKEY_ENCODING_SPEC_MLDSA_SK_S1                  0x00000006u
#define MCUXCLKEY_ENCODING_SPEC_MLDSA_SK_S2                  0x00000007u
#define MCUXCLKEY_ENCODING_SPEC_MLDSA_SK_T0                  0x00000008u

// Destination action:
#define MCUXCLKEY_ENCODING_SPEC_ACTION_MASK                  0x00000070u
#define MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL                0x00000000u ///< Store/Load to/from key data to the destination location with a normal copy
#define MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE                0x00000010u ///< Store/Load to/from key data to the destination location with a secure copy
#define MCUXCLKEY_ENCODING_SPEC_ACTION_PTR                   0x00000020u ///< Update the destination pointer to point to the raw key data (if no decoding required, TBD in case of decoding required: allocate cache location using Session, or use the user provided pointer)
#define MCUXCLKEY_ENCODING_SPEC_ACTION_STORE_FROM_PLAIN      0x00000030u ///< Store normal (plain) key data to the destination
#define MCUXCLKEY_ENCODING_SPEC_ACTION_STORE_FROM_PROTECTED  0x00000040u ///< Store protected (SFR masked) key data to the destination

// Component specs:
#define MCUXCLKEY_ENCODING_SPEC_COMP_MASK                    0x000000FFu

// For big key parts, processing them in chunks might be required [FUTURE USE]
#define MCUXCLKEY_ENCODING_SPEC_CHUNK_MASK                   0x00000080u
#define MCUXCLKEY_ENCODING_SPEC_CHUNK_PROCESSING_ENABLED     0x00000080u
#define MCUXCLKEY_ENCODING_SPEC_CHUNK_PROCESSING_DISABLED    0x00000000u

#define MCUXCLKEY_ENCODING_SPEC_CHUNK_SIZE_MASK              0x0000FF00u ///< Size (in words) in the key part (0x00 == 256 words)
#define MCUXCLKEY_ENCODING_SPEC_CHUNK_SIZE_POS               8u
#define MCUXCLKEY_ENCODING_SPEC_CHUNK_SIZE(len)              (((len) << MCUXCLKEY_ENCODING_SPEC_CHUNK_SIZE_POS) & MCUXCLKEY_ENCODING_SPEC_CHUNK_SIZE_MASK)

#define MCUXCLKEY_ENCODING_SPEC_CHUNK_OFFSET_MASK            0xFFFF0000u ///< Offset (in words) in the key part
#define MCUXCLKEY_ENCODING_SPEC_CHUNK_OFFSET_POS             16u
#define MCUXCLKEY_ENCODING_SPEC_CHUNK_OFFSET(off)            (((off) << MCUXCLKEY_ENCODING_SPEC_CHUNK_OFFSET_POS) & MCUXCLKEY_ENCODING_SPEC_CHUNK_OFFSET_MASK)
/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLKEY_INTERNAL_H_ */
