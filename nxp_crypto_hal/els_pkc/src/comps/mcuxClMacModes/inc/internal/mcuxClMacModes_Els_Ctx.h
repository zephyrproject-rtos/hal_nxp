/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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

/** @file  mcuxClMacModes_Els_Ctx.h
 *  @brief Internal header for the MAC context for modes using the ELS
 */

#ifndef MCUXCLMACMODES_ELS_CTX_H_
#define MCUXCLMACMODES_ELS_CTX_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClMac_Types.h>
#include <internal/mcuxClMac_Ctx.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClAes.h>
#include <mcuxClEls.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Mac context structure for modes using ELS HW
 *
 * This structure captures all the information that the Mac interface needs to
 * know for a particular Mac mode/algorithm to work.
 */
typedef struct mcuxClMacModes_Context
{
  mcuxClMac_Context_t common;                             ///< Common part of the context, for all modes
  mcuxClKey_Descriptor_t * key;                           ///< Key descriptor of the key to be used
  uint32_t blockBuffer[MCUXCLAES_BLOCK_SIZE_IN_WORDS];    ///< Not yet processed input data from the input stream
  uint32_t blockBufferUsed;                              ///< Used bytes in blockBuffer
  uint32_t state[MCUXCLAES_BLOCK_SIZE_IN_WORDS];          ///< state/intermediate result of the mac operation
  mcuxClEls_CmacOption_t cmac_options;                    ///< Cmac ELS options to be used
  uint32_t totalInput;                                   ///< Total input length, only needed fro
} mcuxClMacModes_Context_t;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_ELS_CTX_H_ */
