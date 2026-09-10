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

/**
 * @file  mcuxClOsccaSm3_MemoryConsumption.h
 * @brief Defines the memory consumption for the mcuxClOsccaSm3 component
 */

#ifndef MCUXCLOSCCASM3_MEMORYCONSUMPTION_H_
#define MCUXCLOSCCASM3_MEMORYCONSUMPTION_H_

/**
 * @defgroup MCUXCLOSCCASM3_WA MCUXCLOSCCASM3_WA
 * @brief Definitions of workarea sizes for the mcuxClOsccaSm3 functions.
 * @ingroup mcuxClOsccaSm3_Constants
 * @{
 */

/****************************************************************************/
/* Definitions of workarea buffer sizes for the mcuxClOsccaSm3 functions.    */
/****************************************************************************/
#define MCUXCLOSCCASM3_COMPUTE_CPU_WA_BUFFER_SIZE_SM3          (192u)   ///< Defines the workarea size required for mcuxClOsccaSm3_compute on SM3
#define MCUXCLOSCCASM3_COMPUTE_CPU_WA_BUFFER_SIZE_MAX          (192u)  ///< Defines the max workarea size required for mcuxClOsccaSm3_compute


#define MCUXCLOSCCASM3_INIT_CPU_WA_BUFFER_SIZE                 (0u)  ///< Defines the max workarea size required for mcuxClOsccaSm3_init

#define MCUXCLOSCCASM3_PROCESS_CPU_WA_BUFFER_SIZE_SM3          (32u)  ///< Defines the workarea size required for mcuxClOsccaSm3_process on SM3
#define MCUXCLOSCCASM3_PROCESS_CPU_WA_BUFFER_SIZE_MAX          (32u)  ///< Defines the max workarea size required for mcuxClOsccaSm3_process

#define MCUXCLOSCCASM3_FINISH_CPU_WA_BUFFER_SIZE_SM3          (64u)  ///< Defines the workarea size required for mcuxClOsccaSm3_finish on SM3
#define MCUXCLOSCCASM3_FINISH_CPU_WA_BUFFER_SIZE_MAX          (64u)  ///< Defines the max workarea size required for mcuxClOsccaSm3_finish

#define MCUXCLOSCCASM3_MAX_CPU_WA_BUFFER_SIZE                 (192u)  ///< Defines the max workarea size required this component

/** @} */

/**
 * @defgroup MCUXCLOSCCASM3_CONTEXT MCUXCLOSCCASM3_CONTEXT
 * @brief Definitions of context sizes for the mcuxClOsccaSm3 multi-part functions.
 * @ingroup mcuxClOsccaSm3_Constants
 * @{
 */

/****************************************************************************/
/* Definitions of context sizes for the mcuxClOsccaSm3 multi-part functions. */
/****************************************************************************/

#define MCUXCLOSCCASM3_CONTEXT_SIZE (128u)
#define MCUXCLOSCCASM3_CONTEXT_SIZE_IN_WORDS (128u / sizeof(uint32_t)) ///< Defines the context size for streaming hashing interfaces

/********************************************************************************************/
/* Definitions of state buffer sizes for mcuxClHash_export_state and mcuxClHash_import_state  */
/********************************************************************************************/

#define MCUXCLOSCCASM3_EXPORT_IMPORT_CPU_WA_BUFFER_SIZE                  (40u)      ///< Defines the state size required for SM3

/**
 * @}
 */ /* mcuxClOsccaSm3_MemoryConsumption */

#endif /* MCUXCLOSCCASM3_MEMORYCONSUMPTION_H_ */
