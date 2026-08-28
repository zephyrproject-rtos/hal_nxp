/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/** @file  mcuxClMac_Internal_Constants.h
 *  @brief Internal header for MAC constants
 */

#ifndef MCUXCLMAC_INTERNAL_CONSTANTS_H_
#define MCUXCLMAC_INTERNAL_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClMacModes_Constants.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>

#include <mcuxClHmac_Constants.h>
#include <internal/mcuxClHmac_Internal_Memory.h>


#ifdef __cplusplus
extern "C" {
#endif

/* Define maximum output size for mcuxClHmac modes */
#define MCUXCLMAC_MAX_OUTPUT_SIZE_HMAC                       (MCUXCLHMAC_MAX_OUTPUT_SIZE)

/* Define maximum output size for mcuxClMacModes modes */
#define MCUXCLMAC_MAX_OUTPUT_SIZE_MACMODES                   (MCUXCLMACMODES_MAX_OUTPUT_SIZE)

#define MCUXCLMAC_MAX_OUTPUT_SIZE    \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT("Constant values are allowed as an argument to macro function") \
    ((MCUXCLMAC_MAX_OUTPUT_SIZE_HMAC > MCUXCLMAC_MAX_OUTPUT_SIZE_MACMODES) ? MCUXCLMAC_MAX_OUTPUT_SIZE_HMAC : MCUXCLMAC_MAX_OUTPUT_SIZE_MACMODES) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT()
#define MCUXCLMAC_MAX_OUTPUT_SIZE_IN_WORDS                   (MCUXCLMAC_MAX_OUTPUT_SIZE / sizeof(uint32_t))


/* Define maximum context size for mcuxClHmac modes */
#define MCUXCLMAC_MAX_CONTEXT_SIZE_HMAC                       (MCUXCLHMAC_INTERNAL_CONTEXT_SIZE)

/* Define maximum context size for mcuxClMacModes modes */
#define MCUXCLMAC_MAX_CONTEXT_SIZE_MACMODES                   (sizeof(mcuxClMacModes_Context_t))

#define MCUXCLMAC_MAX_CONTEXT_SIZE    \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT("Constant values are allowed as an argument to macro function") \
    ((MCUXCLMAC_MAX_CONTEXT_SIZE_HMAC > MCUXCLMAC_MAX_CONTEXT_SIZE_MACMODES) ? MCUXCLMAC_MAX_CONTEXT_SIZE_HMAC : MCUXCLMAC_MAX_CONTEXT_SIZE_MACMODES) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT()
#define MCUXCLMAC_MAX_CONTEXT_SIZE_IN_WORDS                   (MCUXCLMAC_MAX_CONTEXT_SIZE / sizeof(uint32_t))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMAC_INTERNAL_CONSTANTS_H_ */
