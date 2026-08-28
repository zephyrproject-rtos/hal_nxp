/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024, 2026 NXP                                            */
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

/** @file  mcuxClAeadModes_MemoryConsumption.h
 *  @brief Defines the memory consumption for the mcuxClAeadModes component */

#ifndef MCUXCLAEADMODES_MEMORYCONSUMPTION_H_
#define MCUXCLAEADMODES_MEMORYCONSUMPTION_H_

#include <mcuxClCore_Macros.h>

/**
 * @defgroup mcuxClAeadModes_MemoryConsumption mcuxClAeadModes_MemoryConsumption
 * @brief Defines the memory consumption for the mcuxClAead component
 *        All work area sizes in bytes are a multiple of CPU wordsize.
 * @ingroup mcuxClAeadModes
 * @{
 */

#define MCUXCLAEAD_ENCRYPT_CPU_WA_BUFFER_SIZE          (576U)
#define MCUXCLAEAD_ENCRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_ENCRYPT_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_DECRYPT_CPU_WA_BUFFER_SIZE          (576U)
#define MCUXCLAEAD_DECRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS  MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_DECRYPT_CPU_WA_BUFFER_SIZE )

#define MCUXCLAEAD_INIT_ENCRYPT_CPU_WA_BUFFER_SIZE          (272U)
#define MCUXCLAEAD_INIT_ENCRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_INIT_ENCRYPT_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_INIT_DECRYPT_CPU_WA_BUFFER_SIZE          (272U)
#define MCUXCLAEAD_INIT_DECRYPT_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_INIT_DECRYPT_CPU_WA_BUFFER_SIZE )



#define MCUXCLAEAD_INIT_CPU_WA_BUFFER_SIZE                   (272U)
#define MCUXCLAEAD_INIT_CPU_WA_BUFFER_SIZE_IN_WORDS          MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_INIT_CPU_WA_BUFFER_SIZE)
#define MCUXCLAEAD_PROCESS_CPU_WA_BUFFER_SIZE                (272U)
#define MCUXCLAEAD_PROCESS_CPU_WA_BUFFER_SIZE_IN_WORDS       MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_PROCESS_CPU_WA_BUFFER_SIZE)
#define MCUXCLAEAD_PROCESS_ADATA_CPU_WA_BUFFER_SIZE          (272U)
#define MCUXCLAEAD_PROCESS_ADATA_CPU_WA_BUFFER_SIZE_IN_WORDS MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_PROCESS_ADATA_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_FINISH_CPU_WA_BUFFER_SIZE                 (272U)
#define MCUXCLAEAD_FINISH_CPU_WA_BUFFER_SIZE_IN_WORDS        MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_FINISH_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_VERIFY_CPU_WA_BUFFER_SIZE                 (272U)
#define MCUXCLAEAD_VERIFY_CPU_WA_BUFFER_SIZE_IN_WORDS        MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_VERIFY_CPU_WA_BUFFER_SIZE )
#define MCUXCLAEAD_MAX_CPU_WA_BUFFER_SIZE                    (576U)
#define MCUXCLAEAD_MAX_CPU_WA_BUFFER_SIZE_IN_WORDS           MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_MAX_CPU_WA_BUFFER_SIZE )

#define MCUXCLAEAD_CONTEXT_SIZE (304U)


#define MCUXCLAEAD_WA_SIZE_MAX (576U)
#define MCUXCLAEAD_WA_SIZE_IN_WORDS_MAX     MCUXCLCORE_NUM_OF_CPUWORDS_FLOOR(MCUXCLAEAD_WA_SIZE_MAX )

/**
 * @}
 */ /* mcuxClAead_MemoryConsumption */

#endif /* MCUXCLAEADMODES_MEMORYCONSUMPTION_H_ */
