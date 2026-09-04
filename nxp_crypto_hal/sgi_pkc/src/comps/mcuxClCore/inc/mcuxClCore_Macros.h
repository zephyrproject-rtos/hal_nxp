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

/**
 * @file  mcuxClCore_Macros.h
 * @brief Definition of macros.
 *
 */

#ifndef MCUXCLCORE_MACROS_H_
#define MCUXCLCORE_MACROS_H_

/* Macro to calculate the rounded down number of words that fit into the specified size */
#define MCUXCLCORE_NUM_OF_WORDS_FLOOR(wordsize, size)  \
  ((size) / (wordsize))

/* Macro to calculate the rounded up number of words needed to fit an object of the specified size */
#define MCUXCLCORE_NUM_OF_WORDS_CEIL(wordsize, size)  \
  (((size) + (wordsize) - 1u) / (wordsize))

/* Macro to calculate the rounded down number of CPU words that fit into the specified size */
#define MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(size)  \
  MCUXCLCORE_NUM_OF_WORDS_FLOOR(sizeof(uint32_t), size)

/* Macro to calculate the rounded up number of CPU words needed to fit an object of the specified size */
#define MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(size)  \
  MCUXCLCORE_NUM_OF_WORDS_CEIL(sizeof(uint32_t), size)

/* Macro to round up a given size to the nearest multiple of a specified word size */
#define MCUXCLCORE_ALIGN_TO_WORDSIZE(wordsize, size)  \
  (MCUXCLCORE_NUM_OF_WORDS_CEIL(wordsize, size) * (wordsize))

/* Macro to round up a given size to the nearest multiple of the CPU word size */
#define MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(size)  \
  MCUXCLCORE_ALIGN_TO_WORDSIZE(sizeof(uint32_t), size)

/* Macro to calculate the maximum of two values */
#define MCUXCLCORE_MAX(a, b)  \
  (((a) > (b)) ? (a) : (b))

/* Macro to calculate the minimum of two values */
#define MCUXCLCORE_MIN(a, b)  \
  (((a) < (b)) ? (a) : (b))

/* Macros to get the status code class of a 32-bit return code */
#define MCUXCLCORE_CLS_MASK           (0x0000FF00u)
#define MCUXCLCORE_CLS_NORMAL         (0x00002E00u)
#define MCUXCLCORE_CLS_NORMALMISMATCH (0x00008900u)
#define MCUXCLCORE_CLS_ABNORMAL       (0x00005300U)
#define MCUXCLCORE_CLS_ATTACK         (0x0000F000U)
#define MCUXCLCORE_GET_CLS(returnCode)  \
  ((returnCode) & MCUXCLCORE_CLS_MASK)

/**
 * @def MCUXCLCORE_DONOTOPTIMIZE
 * @brief Prevent compiler from moving the variable @p value.
 * @api
 * @param value Variable that shall not be moved around.
 */
#if !defined ( __m56800E__ )
 #define MCUXCLCORE_DONOTOPTIMIZE(val) \
  __asm volatile("" : "+r" (val))
#else
 #define MCUXCLCORE_DONOTOPTIMIZE(val)
#endif /* !defined ( __m56800E__ ) */
#endif /* MCUXCLCORE_MACROS_H_ */
