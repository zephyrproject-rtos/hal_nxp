/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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

/** @file  mcuxClHash_MemoryConsumption.h
 *  @brief Defines the memory consumption for the mcuxClHash component */

#ifndef MCUXCLHASH_MEMORYCONSUMPTION_H_
#define MCUXCLHASH_MEMORYCONSUMPTION_H_

#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_MAX                (200u)                            ///< Defines the max workarea size required for mcuxClHash_compute
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_MAX                (200u)                            ///< Defines the max workarea size required for mcuxClHash_compare
#define MCUXCLHASH_INIT_CPU_WA_BUFFER_SIZE                       (4u)                                                ///< Defines the max workarea size required for mcuxClHash_init
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_MAX                (200u)                            ///< Defines the max workarea size required for mcuxClHash_process
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_MAX                 (200u)                            ///< Defines the max workarea size required for mcuxClHash_finish
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_MAX                 (200u)                            ///< Defines the max workarea size required for mcuxClHash_verify

#define MCUXCLHASH_MAX_CPU_WA_BUFFER_SIZE                        (200u)  ///< Defines the max workarea size required for this component


/****************************************************************************/
/* Definitions of context sizes for the mcuxClHash multi-part functions.     */
/****************************************************************************/

#define MCUXCLHASH_CONTEXT_SIZE                                  (400u)    ///< Defines the maximum size a context might need.
#define MCUXCLHASH_CONTEXT_SIZE_IN_WORDS                         (400u / sizeof(uint32_t))


#endif /* MCUXCLHASH_MEMORYCONSUMPTION_H_ */
