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

/** @file  mcuxClHmac_Internal_Memory.h
 *  @brief Internal definitions of memory sizes for the HMAC component
 */

#ifndef MCUXCLHMAC_INTERNAL_MEMORY_H_
#define MCUXCLHMAC_INTERNAL_MEMORY_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClHashModes_Constants.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHash_Internal_Memory.h>
#include <internal/mcuxClHashModes_Internal_Memory.h>
#include <mcuxClCore_Macros.h>
#include <internal/mcuxClHmac_Internal_Types.h>
#include <mcuxClHmac_Constants.h>

#define MCUXCLHMAC_INTERNAL_CONTEXT_SIZE     (sizeof(mcuxClHmac_Context_Sw_t))

#define MCUXCLHMAC_INTERNAL_WACPU_INIT      MCUXCLHASH_BLOCK_SIZE_MAX_WITHOUT_MASK + MCUXCLHASH_INTERNAL_WACPU_MAX
#define MCUXCLHMAC_INTERNAL_WACPU_FINISH    MCUXCLHASH_MAX_OUTPUT_SIZE
#define MCUXCLHMAC_INTERNAL_WACPU_COMPUTE   MCUXCLHMAC_INTERNAL_CONTEXT_SIZE + \
                                            MCUXCLCORE_MAX(MCUXCLHMAC_INTERNAL_WACPU_INIT, MCUXCLHMAC_INTERNAL_WACPU_FINISH)
#define MCUXCLHMAC_INTERNAL_WACPU_COMPARE   MCUXCLHMAC_INTERNAL_WACPU_COMPUTE + 2u * MCUXCLHMAC_MAX_OUTPUT_SIZE
#define MCUXCLHMAC_INTERNAL_WACPU_VERIFY    MCUXCLHMAC_INTERNAL_WACPU_FINISH + 2u * MCUXCLHASH_MAX_OUTPUT_SIZE

#define MCUXCLHMAC_INTERNAL_MAX_WACPU       MCUXCLCORE_MAX(MCUXCLHMAC_INTERNAL_WACPU_COMPARE, MCUXCLHMAC_INTERNAL_WACPU_VERIFY)

#endif /* MCUXCLHMAC_INTERNAL_MEMORY_H_ */

