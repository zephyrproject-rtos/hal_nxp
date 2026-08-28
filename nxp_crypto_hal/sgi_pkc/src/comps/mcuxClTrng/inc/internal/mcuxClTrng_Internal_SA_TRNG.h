/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClTrng_Internal_SA_TRNG.h
 *  @brief Provide macros for mcuxClTrng internal use.
 * This header declares internal macros to deduplicate code and support for internal use only. 
 */

#ifndef MCUXCLTRNG_INTERNAL_SA_TRNG_H_
#define MCUXCLTRNG_INTERNAL_SA_TRNG_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <platform_specific_headers.h>
#include <internal/mcuxClTrng_SfrAccess.h>
#include <internal/mcuxClTrng_Internal_Constants.h>

#define MCUXCLTRNG_ERROR_LIMIT                          (3u)
#define MCUXCLTRNG_SA_TRNG_HW_DUAL_OSCILLATOR_MODE      (1u)

#ifdef MCUXCL_FEATURE_TRNG_SA_TRNG_256
#define MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS         (8u)
#elif defined(MCUXCL_FEATURE_TRNG_SA_TRNG_512)
#define MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS        (16u)
#else
#error "Build configuration issue: SA_TRNG component included but neither SA_TRNG_256 nor SA_TRNG_512 are defined"
#endif

#endif /* MCUXCLTRNG_INTERNAL_SA_TRNG_H_ */
