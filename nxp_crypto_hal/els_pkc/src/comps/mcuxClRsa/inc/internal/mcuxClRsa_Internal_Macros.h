/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2024 NXP                                            */
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
 * @file  mcuxClRsa_Internal_Macros.h
 * @brief Internal macros of the mcuxClRsa component
 */

#ifndef MCUXCLRSA_INTERNAL_MACROS_H_
#define MCUXCLRSA_INTERNAL_MACROS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <stdint.h>
#include <mcuxClCore_Macros.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup MCUXCLRSA_INTERNAL_DEFINES_ MCUXCLRSA_INTERNAL_DEFINES_
 * @brief Internal macros of the mcuxClRsa component.
 * @ingroup mcuxClRsa_Internal_Defines
 * @{
 */
#define MCUXCLRSA_PSS_PADDING1_LEN (8u)
    ///< Define for the PSS padding1 length.

#define MCUXCLRSA_HASH_MAX_SIZE (64u)
    ///< Defines the maximum sizes of the hash algorithms

#define MCUXCLRSA_MAX_MODLEN (512u)
/** @} */


/**
 * @defgroup MCUXCLRSA_INTERNAL_MACROS_ MCUXCLRSA_INTERNAL_MACROS_
 * @brief Internal macro of the mcuxClRsa component.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_GET_MINIMUM_SECURITY_STRENGTH(keyBitLength) \
        (((keyBitLength) <= 2048u) ? 112u : \
        (((keyBitLength) <= 3072u) ? 128u : \
                                     152u))   ///< Macro to determine the minimal security strength that
                                              ///< needs to be provided by the RNG for RSA keys with
                                              ///< lengths from 2048 bits to 4096 bits.
                                              ///< Numbers taken from NIST SP 800-56B REV. 2, Table 2

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_INTERNAL_MACROS_H_ */

