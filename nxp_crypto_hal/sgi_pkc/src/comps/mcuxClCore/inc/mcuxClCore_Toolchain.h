/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023, 2026 NXP                                            */
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

#ifndef MCUXCLCORE_TOOLCHAIN_H_
#define MCUXCLCORE_TOOLCHAIN_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCl_Core_Swap64)
static inline uint64_t mcuxCl_Core_Swap64(uint64_t value)
{
#if defined(__GNUC__) || defined(__clang__)
    return __builtin_bswap64(value);
#else
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Offset calculations cannot overflow.")
    return ((value >> 56) & 0x00000000000000FFULL) |
           ((value >> 40) & 0x000000000000FF00ULL) |
           ((value >> 24) & 0x0000000000FF0000ULL) |
           ((value >>  8) & 0x00000000FF000000ULL) |
           ((value <<  8) & 0x000000FF00000000ULL) |
           ((value << 24) & 0x0000FF0000000000ULL) |
           ((value << 40) & 0x00FF000000000000ULL) |
           ((value << 56) & 0xFF00000000000000ULL);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
#endif
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCl_Core_Swap32)
static inline uint32_t mcuxCl_Core_Swap32(uint32_t value)
{
#if defined(__GNUC__) || defined(__clang__)
    return __builtin_bswap32(value);
#else
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Offset calculations cannot overflow.")
    return ((value >> 24) & 0x000000FFUL) |
           ((value << 24) & 0xFF000000UL) |
           ((value >>  8) & 0x0000FF00UL) |
           ((value <<  8) & 0x00FF0000UL);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
#endif
}


#endif /* MCUXCLCORE_TOOLCHAIN_H_ */
