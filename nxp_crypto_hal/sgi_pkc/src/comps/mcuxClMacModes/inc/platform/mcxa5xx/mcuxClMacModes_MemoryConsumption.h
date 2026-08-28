/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/** @file  mcuxClMacModes_MemoryConsumption.h
 *  @brief Defines the memory consumption for the mcuxClMacModes component
 *         All work area sizes in bytes are a multiple of CPU wordsize.
 */

#ifndef MCUXCLMACMODES_MEMORYCONSUMPTION_H_
#define MCUXCLMACMODES_MEMORYCONSUMPTION_H_

#include <mcuxClCore_Macros.h>
#include <mcuxClCipherModes_MemoryConsumption.h>

/**
 * @defgroup mcuxClMacModes_MemoryConsumption mcuxClMacModes_MemoryConsumption
 * @brief Defines the memory consumption for the mcuxClMacModes component
 * @ingroup mcuxClMacModes
 * @{
 */

/* Workarea sizes */
#define MCUXCLMAC_MAX_CPU_WA_BUFFER_SIZE               (84U)
#define MCUXCLMAC_MAX_CPU_WA_BUFFER_SIZE_IN_WORDS      MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLMAC_MAX_CPU_WA_BUFFER_SIZE)

#define MCUXCLMAC_COMPUTE_CPU_WA_BUFFER_SIZE           (84U)
#define MCUXCLMAC_COMPUTE_CPU_WA_BUFFER_SIZE_IN_WORDS  MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLMAC_COMPUTE_CPU_WA_BUFFER_SIZE)
#define MCUXCLMAC_INIT_CPU_WA_BUFFER_SIZE              (84U)
#define MCUXCLMAC_INIT_CPU_WA_BUFFER_SIZE_IN_WORDS     MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLMAC_INIT_CPU_WA_BUFFER_SIZE)
#define MCUXCLMAC_PROCESS_CPU_WA_BUFFER_SIZE           (84U)
#define MCUXCLMAC_PROCESS_CPU_WA_BUFFER_SIZE_IN_WORDS  MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLMAC_PROCESS_CPU_WA_BUFFER_SIZE)
#define MCUXCLMAC_PROCESS_NONBLOCKING_CPU_WA_BUFFER_SIZE           (84U)
#define MCUXCLMAC_PROCESS_NONBLOCKING_CPU_WA_BUFFER_SIZE_IN_WORDS  MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLMAC_PROCESS_NONBLOCKING_CPU_WA_BUFFER_SIZE)
#define MCUXCLMAC_FINISH_CPU_WA_BUFFER_SIZE            (84U)
#define MCUXCLMAC_FINISH_CPU_WA_BUFFER_SIZE_IN_WORDS   MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLMAC_FINISH_CPU_WA_BUFFER_SIZE)

/* Context sizes */
#define MCUXCLMAC_CONTEXT_SIZE                         (144U)
#define MCUXCLMAC_CONTEXT_SIZE_IN_WORDS                MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLMAC_CONTEXT_SIZE)

/* Mode descriptor sizes */

/**
 * @}
 */ /* mcuxClMac_MemoryConsumption */

#endif /* MCUXCLMACMODES_MEMORYCONSUMPTION_H_ */
