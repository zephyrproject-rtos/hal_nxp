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

/**
 * @file  mcuxClPkc_BasicDefs.h
 * @brief Primitive defines for PKC
 */

#ifndef MCUXCLPKC_BASICDEFS_H_
#define MCUXCLPKC_BASICDEFS_H_

#include <platform_specific_headers.h>

#include <mcuxClCore_Platform.h>
#include <mcuxClToolchain.h>

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_SfrAccess.h>

/**********************************************************/
/* Internal PKC definitions                               */
/**********************************************************/
#if defined(MCUXCL_FEATURE_PKC_RAM_4KB)
#define MCUXCLPKC_RAM_SIZE        0x00001000u         ///< PKC workarea size = 4 KByte
#define MCUXCLPKC_RAM_OFFSET_MASK 0x00000FFFu         ///< Mask to extract PKC offset from CPU pointer
#elif defined(MCUXCL_FEATURE_PKC_RAM_8KB)
#define MCUXCLPKC_RAM_SIZE        0x00002000u         ///< PKC workarea size = 8 KByte
#define MCUXCLPKC_RAM_OFFSET_MASK 0x00001FFFu         ///< Mask to extract PKC offset from CPU pointer
#else
#error PKC_RAM size feature not properly defined
#endif                                               /* MCUXCL_FEATURE_PKC_RAM_8KB */
#define MCUXCLPKC_LOG2_WORDSIZE     3u                ///< log2(PKC wordsize in byte)

#define MCUXCLPKC_RAM_OFFSET_MIN    0u                ///< Minimum (included) of PKC operand offset
#define MCUXCLPKC_RAM_OFFSET_MAX    MCUXCLPKC_RAM_SIZE ///< Maximum (not included) of PKC operand offset
#define MCUXCLPKC_RAM_START_ADDRESS PKC_RAM_ADDR      ///< PKC workarea address

/** Check if an address is in the PKC RAM */
#define MCUXCLPKC_IS_PKC_RAM(address) \
  (((uint32_t)(address) >= (uint32_t)MCUXCLPKC_RAM_START_ADDRESS) && \
   ((uint32_t)(address) < (uint32_t)MCUXCLPKC_RAM_START_ADDRESS + MCUXCLPKC_RAM_SIZE))

#endif /* MCUXCLPKC_BASICDEFS_H_ */
