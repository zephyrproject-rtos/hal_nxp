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

/** @file  mcuxClOsccaCipherModes_MemoryConsumption.h
 *  @brief Memory consumption of the mcuxClOsccaCipherModes component */
 
#ifndef MCUXCLOSCCACIPHERMODES_MEMORYCONSUMPTION_H_
#define MCUXCLOSCCACIPHERMODES_MEMORYCONSUMPTION_H_

/* Workarea sizes */
#ifdef MCUXCL_FEATURE_CIPHERMODES_SM4

#define MCUXCLOSCCACIPHER_SM4_CRYPT_CPU_WA_BUFFER_SIZE            (584u)
#define MCUXCLOSCCACIPHER_SM4_CRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS   (MCUXCLOSCCACIPHER_SM4_CRYPT_CPU_WA_BUFFER_SIZE / sizeof(uint32_t))

#define MCUXCLOSCCACIPHER_MAX_SM4_CPU_WA_BUFFER_SIZE              (MCUXCLOSCCACIPHER_SM4_CRYPT_CPU_WA_BUFFER_SIZE)
#define MCUXCLOSCCACIPHER_MAX_SM4_CPU_WA_BUFFER_SIZE_IN_WORDS     (MCUXCLOSCCACIPHER_SM4_CRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS)



#define MCUXCLOSCCACIPHER_SM4_INIT_CPU_WA_BUFFER_SIZE             (4u)
#define MCUXCLOSCCACIPHER_SM4_PROCESS_CPU_WA_BUFFER_SIZE          (4u)
#define MCUXCLOSCCACIPHER_SM4_FINISH_CPU_WA_BUFFER_SIZE           (4u)
#define MCUXCLOSCCACIPHER_SM4_INIT_CPU_WA_BUFFER_SIZE_IN_WORDS    (MCUXCLOSCCACIPHER_SM4_INIT_CPU_WA_BUFFER_SIZE / sizeof(uint32_t))
#define MCUXCLOSCCACIPHER_SM4_PROCESS_CPU_WA_BUFFER_SIZE_IN_WORDS (MCUXCLOSCCACIPHER_SM4_PROCESS_CPU_WA_BUFFER_SIZE / sizeof(uint32_t))
#define MCUXCLOSCCACIPHER_SM4_FINISH_CPU_WA_BUFFER_SIZE_IN_WORDS  (MCUXCLOSCCACIPHER_SM4_FINISH_CPU_WA_BUFFER_SIZE / sizeof(uint32_t))

/* Context sizes */
#define MCUXCLOSCCACIPHER_SM4_CONTEXT_SIZE                        (584u)
#define MCUXCLOSCCACIPHER_SM4_CONTEXT_SIZE_IN_WORDS               (MCUXCLOSCCACIPHER_SM4_CONTEXT_SIZE / sizeof(uint32_t))
#endif /* MCUXCL_FEATURE_CIPHERMODES_SM4 */

#endif /* MCUXCLOSCCACIPHERMODES_MEMORYCONSUMPTION_H_ */
