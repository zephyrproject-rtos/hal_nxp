/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2026 NXP                                       */
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
 * @file  mcuxClMath_Internal.h
 * @brief Internal header of mcuxClMath component
 *
 * @defgroup mcuxClMath_Internal mcuxClMath_Internal
 * @brief component of mathematics functions
 */

#ifndef MCUXCLMATH_INTERNAL_H_
#define MCUXCLMATH_INTERNAL_H_

#include <mcuxClCore_Platform.h>

#include <internal/mcuxClMath_Internal_Functions.h>
#include <internal/mcuxClMath_Internal_Types.h>

/* The maximum number of pointers in the UPTRT for calls to mcuxClMath_InitLocalUptrt */
#define MATH_NO_OF_MAX_VIRTUALS 32U

#define MCUXCLMATH_SIZEOF_MATH_UPTRT MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(sizeof(uint16_t) * (MATH_NO_OF_MAX_VIRTUALS))

#endif /* MCUXCLMATH_INTERNAL_H_ */
