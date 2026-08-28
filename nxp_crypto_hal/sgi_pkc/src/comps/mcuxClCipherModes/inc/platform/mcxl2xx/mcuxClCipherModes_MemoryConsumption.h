/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

/** @file  mcuxClCipher_MemoryConsumption.h
 *  @brief Memory consumption of the mcuxClCipher component
 *         All work area sizes in bytes are a multiple of CPU wordsize.
 */

#ifndef MCUXCLCIPHER_MEMORYCONSUMPTION_H_
#define MCUXCLCIPHER_MEMORYCONSUMPTION_H_

/**
 * @defgroup mcuxClCipherModes_MemoryConsumption mcuxClCipherModes_MemoryConsumption
 * @brief Memory consumption of the Cipher operations.
 * @ingroup mcuxClCipherModes
 * @{
 */

#include <mcuxClCore_Macros.h>

/* Workarea sizes */
#define MCUXCLCIPHER_AES_ENCRYPT_CPU_WA_BUFFER_SIZE               (80U)
#define MCUXCLCIPHER_AES_DECRYPT_CPU_WA_BUFFER_SIZE               (80U)
#define MCUXCLCIPHER_AES_ENCRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS      MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLCIPHER_AES_ENCRYPT_CPU_WA_BUFFER_SIZE)
#define MCUXCLCIPHER_AES_DECRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS      MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLCIPHER_AES_DECRYPT_CPU_WA_BUFFER_SIZE)


#define MCUXCLCIPHER_AES_INIT_ENCRYPT_CPU_WA_BUFFER_SIZE          (80U)
#define MCUXCLCIPHER_AES_INIT_DECRYPT_CPU_WA_BUFFER_SIZE          (80U)
#define MCUXCLCIPHER_AES_PROCESS_CPU_WA_BUFFER_SIZE               (80U)
#define MCUXCLCIPHER_AES_FINISH_CPU_WA_BUFFER_SIZE                (80U)
#define MCUXCLCIPHER_AES_INIT_ENCRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLCIPHER_AES_INIT_ENCRYPT_CPU_WA_BUFFER_SIZE)
#define MCUXCLCIPHER_AES_INIT_DECRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLCIPHER_AES_INIT_DECRYPT_CPU_WA_BUFFER_SIZE)
#define MCUXCLCIPHER_AES_PROCESS_CPU_WA_BUFFER_SIZE_IN_WORDS      MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLCIPHER_AES_PROCESS_CPU_WA_BUFFER_SIZE)
#define MCUXCLCIPHER_AES_FINISH_CPU_WA_BUFFER_SIZE_IN_WORDS       MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLCIPHER_AES_FINISH_CPU_WA_BUFFER_SIZE)


#define MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE                   (MCUXCLCIPHER_AES_ENCRYPT_CPU_WA_BUFFER_SIZE)
#define MCUXCLCIPHER_MAX_AES_CPU_WA_BUFFER_SIZE_IN_WORDS          (MCUXCLCIPHER_AES_ENCRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS)


/* Context sizes */
#define MCUXCLCIPHER_AES_CONTEXT_SIZE                             (108U)
#define MCUXCLCIPHER_AES_CONTEXT_SIZE_IN_WORDS                    MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLCIPHER_AES_CONTEXT_SIZE)


/** @} */

#endif /* MCUXCLCIPHER_MEMORYCONSUMPTION_H_ */
