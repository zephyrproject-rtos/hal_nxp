/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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

/** @file  mcuxClKey_MemoryConsumption.h
 *  @brief Defines the memory consumption for the mcuxClKey component
 *         All work area sizes in bytes are a multiple of CPU wordsize.
 */

#ifndef MCUXCLKEY_MEMORYCONSUMPTION_H_
#define MCUXCLKEY_MEMORYCONSUMPTION_H_

/**
 * @defgroup mcuxClKey_MemoryConsumption mcuxClKey_MemoryConsumption
 * @brief Defines the memory consumption for the mcuxClKey component
 * @ingroup mcuxClKey
 * @{
 */

#define MCUXCLKEY_DESCRIPTOR_SIZE          (56u)
#define MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS (MCUXCLKEY_DESCRIPTOR_SIZE / sizeof(uint32_t))

#define MCUXCLKEY_TYPEDESCRIPTOR_SIZE          (12u)
#define MCUXCLKEY_TYPEDESCRIPTOR_SIZE_IN_WORDS (MCUXCLKEY_TYPEDESCRIPTOR_SIZE / sizeof(uint32_t))

#define MCUXCLKEY_CUSTOMTYPEDESCRIPTOR_SIZE          (12u)
#define MCUXCLKEY_CUSTOMTYPEDESCRIPTOR_SIZE_IN_WORDS (MCUXCLKEY_CUSTOMTYPEDESCRIPTOR_SIZE / sizeof(uint32_t))

#ifdef MCUXCL_FEATURE_KEY_DERIVATION
#define MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE          (16u)
#define MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS (MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE / sizeof(uint32_t))

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_108
#define MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE             1116u
#define MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE_IN_WORDS    (MCUXCLKEY_DERIVATION_CPU_WA_SIZE / sizeof(uint32_t))
#define MCUXCLKEY_DERIVATION_CM_CPU_WA_SIZE                         MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE /* deprecated, use MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE instead */
#define MCUXCLKEY_DERIVATION_CM_CPU_WA_SIZE_IN_WORDS                MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE_IN_WORDS /* deprecated, use MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE_IN_WORDS instead */
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_108 */

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_56C
#define MCUXCLKEY_DERIVATION_NIST_SP800_56C_CPU_WA_SIZE             1772u
#define MCUXCLKEY_DERIVATION_NIST_SP800_56C_CPU_WA_SIZE_IN_WORDS    (MCUXCLKEY_DERIVATION_NIST_SP800_56C_CPU_WA_SIZE / sizeof(uint32_t))
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_56C */




#ifdef MCUXCL_FEATURE_KEY_DERIVATION_HKDF
#define MCUXCLKEY_DERIVATION_HKDF_CPU_WA_SIZE                       1172u
#define MCUXCLKEY_DERIVATION_HKDF_CPU_WA_SIZE_IN_WORDS              (MCUXCLKEY_DERIVATION_HKDF_CPU_WA_SIZE / sizeof(uint32_t))
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_HKDF */

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_PBKDF2
#define MCUXCLKEY_DERIVATION_PBKDF2_CPU_WA_SIZE                     1280u
#define MCUXCLKEY_DERIVATION_PBKDF2_CPU_WA_SIZE_IN_WORDS            (MCUXCLKEY_DERIVATION_PBKDF2_CPU_WA_SIZE / sizeof(uint32_t))
#endif /* MCUXCL_FEATURE_KEY_DERIVATION_PBKDF2 */


#define MCUXCLKEY_DERIVATION_CPU_WA_SIZE                            1772u
#define MCUXCLKEY_DERIVATION_CPU_WA_SIZE_IN_WORDS                   (MCUXCLKEY_DERIVATION_CPU_WA_SIZE / sizeof(uint32_t))
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */

/**
 * @}
 */ /* mcuxClKey_MemoryConsumption */

#endif /* MCUXCLKEY_MEMORYCONSUMPTION_H_ */
