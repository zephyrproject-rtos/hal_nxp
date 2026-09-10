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

/** @file  mcuxClOsccaSm3_Internal.h
 *  @brief Definitions and declarations of the *INTERNAL* layer of the
 *         @ref mcuxClOsccaSm3 component
 */

#ifndef MCUXCLOSCCASM3_INTERNAL_H_
#define MCUXCLOSCCASM3_INTERNAL_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClHash_Types.h>
#include <mcuxClSession.h>
#include <internal/mcuxClHash_Internal.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#ifdef MCUXCL_FEATURE_HASH_HW_SM3
#include <internal/mcuxClOsccaSm3_Internal_sm3.h>
#endif /* MCUXCL_FEATURE_HASH_HW_SM3 */

/**********************************************
 * CONSTANTS
 **********************************************/
/**
 * @defgroup mcuxClOsccaSm3_Internal mcuxClOsccaSm3_Internal
 * @brief Defines all internal of @ref mcuxClOsccaSm3 component
 * @ingroup mcuxClOsccaSm3
 * @{
 */
#define MCUXCLOSCCASM3_WACPU_SIZE_SM3       (128u)

#define MCUXCLOSCCASM3_BLOCK_SIZE_SM3       (64U) ///< SM3 block size: 512 bit (64 bytes)

#define MCUXCLOSCCASM3_STATE_SIZE_SM3       (32U) ///< SM3 state size: 256 bit (32 bytes)

#define MCUXCLOSCCASM3_COUNTER_SIZE_SM3     (8U)  ///< Counter size for SM3 padding

#define MCUXCLOSCCASM3_CONTEXT_SIZE_SM3     (sizeof(mcuxClHash_ContextDescriptor_t) + MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + MCUXCLOSCCASM3_STATE_SIZE_SM3)    ///< Context size for SM3 mulit-part


/**********************************************
 * Checked input sizes
 **********************************************/

/**
 * @brief Check processed length mask is used to detect when the maximum input size to a hash function has been exceeded.
 * Specifically.
 * Therefore, a mask of the 3 highest bits of the highest byte of the counter is sufficient to check if this has occurred.
 * Checks are performed only in the multipart variants, in mcuxClHash_process/mcuxClHash_finish and mcuxClHash_import_state.
 */

#define MCUXCLOSCCASM3_PROCESSED_LENGTH_CHECK_MASK                 (0xE0u) ///< Mask of the highest bits in the processed counter that should not be set for SM3.

/**********************************************************/
/* Internal APIs of mcuxClOsccaSm3                         */
/**********************************************************/
/**
 * @defgroup mcuxClOsccaSm3_Internal_Functions mcuxClOsccaSm3_Internal_Functions
 * @brief Defines all internal functions of @ref mcuxClOsccaSm3 component
 * @ingroup mcuxClOsccaSm3
 * @{
 */
/**@}*/

#endif /* MCUXCLOSCCASM3_INTERNAL_H_ */
