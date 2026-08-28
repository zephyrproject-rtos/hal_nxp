/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2026 NXP                                                 */
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

#include <mcuxClCore_Platform.h>
#include <platform_specific_headers.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()

#if defined(SCM)      /* S5xy */
  #define MCUXCSSLPRNG_SCM_PRNG_ADDR  ((uint32_t) SCM_BASE + offsetof(SCM_Type, SCM_PRNG_OUT))
#elif defined(S3SCM)  /* S401 */
  #define MCUXCSSLPRNG_SCM_PRNG_ADDR  ((uint32_t) S3SCM_BASE + offsetof(S3SCM_Type, S3SCM_PRNG_OUT))
#elif defined(MCUXCL_FEATURE_PRNG_SGI)
  #include <internal/mcuxClSgi_SfrAccess.h>
  #define MCUXCSSLPRNG_SGI_PRNG_ADDR ((uint32_t) SGI_SFR_BASE + offsetof(SGI_Type, SGI_PRNG_SW_READ))
#elif defined(MCUXCL_FEATURE_PRNG_SGI_SFRSEED)
/* Avoid below error if stub is used. */
#else
  #error Unsupported platform
#endif

#if defined(MCUXCL_FEATURE_PRNG_SGI)
#if !defined(__m56800E__)
MCUX_CSSL_ANALYSIS_CLANG_START_SUPPRESS_WARNING(-Wgnu-folding-constant, " Usage of the offsetof within specification of array size triggers warning in armclang. Disable it temporarily");
#endif
/* we bias the array size by + 1 so it's never 0 when (MCUXCSSLPRNG_SGI_PRNG_ADDR >> 16) == 0 */
/* enum forces compile-time evaluation of the array sizes,
 * which solves an issue with certain compilers when using offsetof in array dimension declarations */
enum { MCUXCSSLPRNG_SGI_PRNG_ADDR_HI16 = ((MCUXCSSLPRNG_SGI_PRNG_ADDR >> 16u) + 1u) };
enum { MCUXCSSLPRNG_SGI_PRNG_ADDR_LO16 = (MCUXCSSLPRNG_SGI_PRNG_ADDR & 0xFFFFu) };
volatile uint8_t mcuxCsslPrng_prngSfrAddr_hi16[MCUXCSSLPRNG_SGI_PRNG_ADDR_HI16];
volatile uint8_t mcuxCsslPrng_prngSfrAddr_lo16[MCUXCSSLPRNG_SGI_PRNG_ADDR_LO16];
#if !defined(__m56800E__)
MCUX_CSSL_ANALYSIS_CLANG_STOP_SUPPRESS_WARNING(-Wgnu-folding-constant);
#endif
#elif defined(MCUXCL_FEATURE_PRNG_SGI_SFRSEED)
volatile uint8_t mcuxCsslPrng_prngSfrAddr_hi16[1u];
volatile uint8_t mcuxCsslPrng_prngSfrAddr_lo16[1u];
#else
/* we bias the array size by + 1 so it's never 0 when (MCUXCSSLPRNG_SCM_PRNG_ADDR >> 16) == 0 */
/* enum forces compile-time evaluation of the array sizes,
 * which solves an issue with certain compilers when using offsetof in array dimension declarations */
enum { MCUXCSSLPRNG_SCM_PRNG_ADDR_HI16 = ((MCUXCSSLPRNG_SCM_PRNG_ADDR >> 16u) + 1u) };
enum { MCUXCSSLPRNG_SCM_PRNG_ADDR_LO16 = (MCUXCSSLPRNG_SCM_PRNG_ADDR & 0xFFFFu) };
volatile uint8_t mcuxCsslPrng_prngSfrAddr_hi16[MCUXCSSLPRNG_SCM_PRNG_ADDR_HI16];
volatile uint8_t mcuxCsslPrng_prngSfrAddr_lo16[MCUXCSSLPRNG_SCM_PRNG_ADDR_LO16];
#endif

MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
