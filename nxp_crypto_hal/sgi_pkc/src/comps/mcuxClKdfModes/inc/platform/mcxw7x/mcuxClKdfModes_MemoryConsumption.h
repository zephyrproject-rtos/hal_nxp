/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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

/** @file  mcuxClKdfModes_MemoryConsumption.h
 *  @brief Defines the memory consumption for the mcuxClKdfModes component
 *         All work area sizes in bytes are a multiple of CPU wordsize.
 */

#ifndef MCUXCLKDFMODES_MEMORYCONSUMPTION_H_
#define MCUXCLKDFMODES_MEMORYCONSUMPTION_H_

/**
 * @defgroup mcuxClKdfModes_MemoryConsumption mcuxClKdfModes_MemoryConsumption
 * @brief Defines the memory consumption for the mcuxClKdfModes component
 * @ingroup mcuxClKdfModes
 * @{
 */

#define MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE                  (16u)
#define MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE_IN_WORDS         (MCUXCLKEY_DERIVATION_MODE_DESCRIPTOR_SIZE / sizeof(uint32_t))

#define MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE             2048u
#define MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE_IN_WORDS    (MCUXCLKEY_DERIVATION_CPU_WA_SIZE / sizeof(uint32_t))
#define MCUXCLKEY_DERIVATION_CM_CPU_WA_SIZE                         MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE /* deprecated, use MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE instead */
#define MCUXCLKEY_DERIVATION_CM_CPU_WA_SIZE_IN_WORDS                MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE_IN_WORDS /* deprecated, use MCUXCLKEY_DERIVATION_NIST_SP800_108_CPU_WA_SIZE_IN_WORDS instead */

#define MCUXCLKEY_DERIVATION_NIST_SP800_56C_CPU_WA_SIZE             3816u
#define MCUXCLKEY_DERIVATION_NIST_SP800_56C_CPU_WA_SIZE_IN_WORDS    (MCUXCLKEY_DERIVATION_NIST_SP800_56C_CPU_WA_SIZE / sizeof(uint32_t))




#define MCUXCLKEY_DERIVATION_HKDF_CPU_WA_SIZE                       2112u
#define MCUXCLKEY_DERIVATION_HKDF_CPU_WA_SIZE_IN_WORDS              (MCUXCLKEY_DERIVATION_HKDF_CPU_WA_SIZE / sizeof(uint32_t))

#define MCUXCLKEY_DERIVATION_PBKDF2_CPU_WA_SIZE                     2212u
#define MCUXCLKEY_DERIVATION_PBKDF2_CPU_WA_SIZE_IN_WORDS            (MCUXCLKEY_DERIVATION_PBKDF2_CPU_WA_SIZE / sizeof(uint32_t))


#define MCUXCLKEY_DERIVATION_CPU_WA_SIZE                            3816u
#define MCUXCLKEY_DERIVATION_CPU_WA_SIZE_IN_WORDS                   (MCUXCLKEY_DERIVATION_CPU_WA_SIZE / sizeof(uint32_t))

/**
 * @}
 */ /* mcuxClKdfModes_MemoryConsumption */

#endif /* MCUXCLKDFMODES_MEMORYCONSUMPTION_H_ */
