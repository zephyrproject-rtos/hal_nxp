/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * @file  mcuxClMath_Internal_Utils.h
 * @brief platform independent abstraction over math related builtin functions
 */

#ifndef MCUXCLMATH_INTERNAL_UTILS_H_
#define MCUXCLMATH_INTERNAL_UTILS_H_

#include <mcuxClCore_Platform.h>
#include <platform_specific_headers.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Count leading zeros of non-zero value.
 * If the value is 0, the result is undefined.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_CountLeadingZerosWord)
static inline uint32_t mcuxClMath_CountLeadingZerosWord(uint32_t value)
{
#ifdef __CLZ
    return __CLZ(value);
#else
    return (uint32_t)__builtin_clz(value);
#endif
}

/*
 * Count trailing zeros of non-zero value.
 * In case the value is 0,
 * the result might be undefined if using compiler built-in function;
 * or 32 if using the software implementation.
 */
/**
 * [DESIGN]
 * The software implementation counts the trailing 1 in inverse of input,
 * by checking the LSBit and right-shifting the inverse in a loop, until
 * any 0 bit is right-shifted to LSBit. Since the right-shifting will set
 * MSBit 0, the loop will execute not more than 32 iterations.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_CountTrailingZeroesWord)
static inline uint32_t mcuxClMath_CountTrailingZeroesWord(uint32_t value)
{
#if defined(__CLZ) && defined(__RBIT)
    return  __CLZ(__RBIT(value));
#else
    uint32_t zeroes = 0u;
    uint32_t inverseValue = ~value;

    while (1u == (1u & inverseValue))
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("This loop executes up to 32 iterations, \
                because MSBit is cleared when right-shifting unsigned inverseValue.")
        zeroes++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        inverseValue >>= 1u;
    }

    return zeroes;
#endif
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*MCUXCLMATH_INTERNAL_UTILS_H_ */
