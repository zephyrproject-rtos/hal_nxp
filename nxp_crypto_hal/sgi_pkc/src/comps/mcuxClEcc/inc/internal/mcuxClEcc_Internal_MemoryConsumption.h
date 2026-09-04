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

/** @file  mcuxClEcc_Internal_MemoryConsumption.h
 *  @brief Internal memory consumption definitions of the mcuxClEcc component */

#ifndef MCUXCLECC_INTERNAL_MEMORY_CONSUMPTION_H_
#define MCUXCLECC_INTERNAL_MEMORY_CONSUMPTION_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClCore_Macros.h>

/* mcuxClMath_Internal.h provides MCUXCLMATH_SIZEOF_MATH_UPTRT which is used in PKC operations */
#include <internal/mcuxClMath_Internal.h>


#ifdef __cplusplus
extern "C" {
#endif


/****************************************************************************/
/* Macros for workarea sizes for mcuxClEcc_InitializeEnvironment.            */
/****************************************************************************/
#define SIZEOF_ECC_UPTRT_WA(NO_BUFFERS, NO_VIRTUALS)    (MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(sizeof(uint16_t) * ((NO_BUFFERS) + (NO_VIRTUALS))))
/* Size of ECC UPTRT workarea for specified number of buffers and virtual pointers */
#define SIZEOF_TOTAL_UPTRT_WA(NO_BUFFERS, NO_VIRTUALS)  (MCUXCLMATH_SIZEOF_MATH_UPTRT + SIZEOF_ECC_UPTRT_WA(NO_BUFFERS, NO_VIRTUALS))
/* Total size of UPTRT workarea including Math and ECC components */

#define SIZEOF_ECCCPUWA_T                           (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClEcc_CpuWa_t)) + sizeof(uint32_t)) /* Reserve 1 word for making UPTR table start from 64-bit aligned address */
/* Size of ECC CPU workarea structure with extra word for 64-bit alignment */
#define MCUXCLECC_SIZEOF_UPTRT_CPUWA(NO_BUFFERS, NO_VIRTUALS) SIZEOF_TOTAL_UPTRT_WA(NO_BUFFERS, NO_VIRTUALS)
/* Size of UPTRT in CPU workarea when UPTRT is stored in CPU RAM */
#define MCUXCLECC_SIZEOF_UPTRT_PKCWA(NO_BUFFERS, NO_VIRTUALS) 0U
/* Size of UPTRT in PKC workarea when UPTRT is stored in CPU RAM */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_INTERNAL_MEMORY_CONSUMPTION_H_ */
