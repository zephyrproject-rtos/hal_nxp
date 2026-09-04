/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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
#include <mcuxClCore_Macros.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClRandomModes_Internal_SizeDefinitions.h>

#include <mcuxClFfdh_Types.h>
#include <internal/mcuxClPkc_Internal_Types.h>
#include <internal/mcuxClFfdh_Internal.h>
#include <internal/mcuxClFfdh_Internal_PkcDefs.h>
#include <internal/mcuxClMath_Internal.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()

#define MCUXCLFFDH_SIZEOF_UPTRT_CPUWA MCUXCLMATH_SIZEOF_MATH_UPTRT
/* Size of UPTRT in CPU workarea when UPTRT is stored in CPU RAM */
#define MCUXCLFFDH_SIZEOF_UPTRT_PKCWA 0U
/* Size of UPTRT in PKC workarea when UPTRT is stored in CPU RAM */

volatile uint8_t mcuxClKey_Agreement_FFDH_WaCPU_Size_2048[MCUXCLFFDH_SIZEOF_UPTRT_CPUWA + SIZEOF_FFDHCPUWA_T + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(uint16_t) * (FFDH_UPTRT_COUNT)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_CPUWA_MAXSIZE)];
volatile uint8_t mcuxClKey_Agreement_FFDH_WaCPU_Size_3072[MCUXCLFFDH_SIZEOF_UPTRT_CPUWA + SIZEOF_FFDHCPUWA_T + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(uint16_t) * (FFDH_UPTRT_COUNT)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_CPUWA_MAXSIZE)];
#ifdef MCUXCL_FEATURE_PKC_RAM_8KB
volatile uint8_t mcuxClKey_Agreement_FFDH_WaCPU_Size_4096[MCUXCLFFDH_SIZEOF_UPTRT_CPUWA + SIZEOF_FFDHCPUWA_T + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(uint16_t) * (FFDH_UPTRT_COUNT)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_CPUWA_MAXSIZE)];
#elif defined(MCUXCL_FEATURE_PKC_RAM_4KB)
#define FDDH_TEMP_BUFFER_SIZE4096 MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(4096U / 8U + 1U)
volatile uint8_t mcuxClKey_Agreement_FFDH_WaCPU_Size_4096[MCUXCLFFDH_SIZEOF_UPTRT_CPUWA + SIZEOF_FFDHCPUWA_T + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(uint16_t) * (FFDH_UPTRT_COUNT)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_CPUWA_MAXSIZE) + FDDH_TEMP_BUFFER_SIZE4096];
#endif
volatile uint8_t mcuxClKey_Agreement_FFDH_WaCPU_Size_6144[MCUXCLFFDH_SIZEOF_UPTRT_CPUWA + SIZEOF_FFDHCPUWA_T + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(uint16_t) * (FFDH_UPTRT_COUNT)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_CPUWA_MAXSIZE)];

#define FDDH_TEMP_BUFFER_SIZE8192 MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(8192U / 8U + 1U)
volatile uint8_t mcuxClKey_Agreement_FFDH_WaCPU_Size_8192[MCUXCLFFDH_SIZEOF_UPTRT_CPUWA + SIZEOF_FFDHCPUWA_T + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(uint16_t) * (FFDH_UPTRT_COUNT)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_CPUWA_MAXSIZE) + FDDH_TEMP_BUFFER_SIZE8192];

volatile uint8_t mcuxClFfdh_PKC_wordsize[MCUXCLPKC_WORDSIZE];

volatile uint8_t mcuxClFfdh_KeyAgreement_WaPKC_NoOfBuffers[FFDH_NO_OF_BUFFERS];

/* Sizes of buffers in PKC RAM are extended by 1FW due to MCUXCLMATH_SECMODEXP requirements.
   For large field elements certain optimizations are in place:
   - last buffer in PKC memory is smaller with size equal to 6 * MCUXCLPKC_WORDSIZE due to MCUXCLMATH_SECMODEXP properties.
   - one of the buffers for MCUXCLMATH_SECMODEXP shall be placed in CPU RAM. */
volatile uint8_t mcuxClKey_Agreement_FFDH_WaPKC_Size_2048 [MCUXCLFFDH_SIZEOF_UPTRT_PKCWA + FFDH_NO_OF_BUFFERS * (MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(2048U / 8U + 1U) + MCUXCLPKC_WORDSIZE)];

volatile uint8_t mcuxClKey_Agreement_FFDH_WaPKC_Size_3072 [MCUXCLFFDH_SIZEOF_UPTRT_PKCWA + FFDH_NO_OF_BUFFERS * (MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(3072U / 8U + 1U) + MCUXCLPKC_WORDSIZE)];

#ifdef MCUXCL_FEATURE_PKC_RAM_8KB
volatile uint8_t mcuxClKey_Agreement_FFDH_WaPKC_Size_4096 [MCUXCLFFDH_SIZEOF_UPTRT_PKCWA + FFDH_NO_OF_BUFFERS * (MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(4096U / 8U + 1U) + MCUXCLPKC_WORDSIZE)];
#elif defined(MCUXCL_FEATURE_PKC_RAM_4KB)
/* Formulas reflect aformentioned optimizations */
volatile uint8_t mcuxClKey_Agreement_FFDH_WaPKC_Size_4096 [MCUXCLFFDH_SIZEOF_UPTRT_PKCWA + (FFDH_NO_OF_BUFFERS - 2U) * (MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(4096U / 8U + 1U) + MCUXCLPKC_WORDSIZE) + 6U * MCUXCLPKC_WORDSIZE];
#endif /* MCUXCL_FEATURE_PKC_RAM_4KB */

volatile uint8_t mcuxClKey_Agreement_FFDH_WaPKC_Size_6144 [MCUXCLFFDH_SIZEOF_UPTRT_PKCWA + FFDH_NO_OF_BUFFERS * (MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(6144U / 8U + 1U) + MCUXCLPKC_WORDSIZE)];

/* Formulas reflect aformentioned optimizations */
volatile uint8_t mcuxClKey_Agreement_FFDH_WaPKC_Size_8192 [MCUXCLFFDH_SIZEOF_UPTRT_PKCWA + (FFDH_NO_OF_BUFFERS - 2U) * (MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(8192U / 8U + 1U) + MCUXCLPKC_WORDSIZE) + 6U * MCUXCLPKC_WORDSIZE];


MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
