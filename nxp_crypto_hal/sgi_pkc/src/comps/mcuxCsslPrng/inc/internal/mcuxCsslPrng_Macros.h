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

/**
 * @file  mcuxCsslPrng_Macros.h
 */


#ifndef MCUXCSSLPRNG_MACROS_H
#define MCUXCSSLPRNG_MACROS_H

#include <stddef.h>
#include <platform_specific_headers.h>

#include <mcuxClConfig.h> // Exported features flags header

#include <internal/mcuxClSgi_Drv.h>

#if defined(MCUXCL_FEATURE_PRNG_SGI_SFRSEED)
#include <internal/mcuxClPrng_Internal.h>
#endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */

/**
 * Macro returning one word (32-bit) of PRNG
 */
#define MCUXCSSLPRNG_GENERATE_WORD()  mcuxCsslPrng_inline_generateWord()

static inline uint32_t mcuxCsslPrng_inline_generateWord(void)
{
#if defined(SCM)      /* S5xy */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SCM SFR address")
    return SCM->SCM_PRNG_OUT;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()
#elif defined(S3SCM)  /* S401 */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SCM SFR address")
    return S3SCM->S3SCM_PRNG_OUT.reg;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()
#elif defined(MCUXCL_FEATURE_PRNG_SGI)
    return MCUX_CSSL_FP_RESULT(mcuxClSgi_Drv_getPrngWord());
#elif defined(MCUXCL_FEATURE_PRNG_SGI_SFRSEED)
    return MCUX_CSSL_FP_RESULT(mcuxClPrng_generate_word());
#else
#error Unsupported platform
    return (uint32_t) 0xDEADBEEFu;
#endif
}


#endif /* MCUXCSSLPRNG_MACROS_H */
