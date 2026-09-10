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

/** @file  mcuxClHashModes_MemoryConsumption.h
 *  @brief Defines the memory consumption for the mcuxClHash component */

#ifndef MCUXCLHASHMODES_MEMORYCONSUMPTION_H_
#define MCUXCLHASHMODES_MEMORYCONSUMPTION_H_

/**
 * @defgroup mcuxClHashModes_WoarkareaConsumption mcuxClHashModes_WoarkareaConsumption
 * @brief Definitions of workarea sizes for the mcuxClHashModes functions.
 * @ingroup mcuxClHash_Constants
 * @{
 */

/****************************************************************************/
/* Definitions of workarea buffer sizes for the mcuxClHashModes functions.   */
/****************************************************************************/

#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_SHA_1              (104u)                           ///< Defines the workarea size required for mcuxClHash_compute on SHA-1
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_SHA_1              (232u)                           ///< Defines the workarea size required for mcuxClHash_compare on SHA-1
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_SHA_1              (4u)                                                        ///< Defines the workarea size required for mcuxClHash_process on SHA-1
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_SHA_1               (4u)                            ///< Defines the workarea size required for mcuxClHash_finish on SHA-1
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_SHA_1               (232u)                            ///< Defines the workarea size required for mcuxClHash_verify on SHA-1
#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_SHA2_224               (96u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-224
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_SHA2_224               (224u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-224
#define MCUXCLHASH_COMPUTE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_224   (4u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-224
#define MCUXCLHASH_COMPARE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_224   (60u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-224
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_SHA2_224               (4u)                                                        ///< Defines the workarea size required for mcuxClHash_process on SHA2-224
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_SHA2_224                (96u)                        ///< Defines the workarea size required for mcuxClHash_finish on SHA2-224
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_SHA2_224                (96u)                        ///< Defines the workarea size required for mcuxClHash_verify on SHA2-224
#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_SHA2_256               (96u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-256
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_SHA2_256               (224u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-256
#define MCUXCLHASH_COMPUTE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_256   (4u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-256
#define MCUXCLHASH_COMPARE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_256   (132u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-256
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_SHA2_256               (4u)                                                        ///< Defines the workarea size required for mcuxClHash_process on SHA2-256
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_SHA2_256                (96u)                        ///< Defines the workarea size required for mcuxClHash_finish on SHA2-256
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_SHA2_256                (224u)                        ///< Defines the workarea size required for mcuxClHash_verify on SHA2-256
#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_SHA2_384               (192u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-384
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_SHA2_384               (288u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-384
#define MCUXCLHASH_COMPUTE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_384   (4u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-384
#define MCUXCLHASH_COMPARE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_384   (100u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-384
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_SHA2_384               (4u)                                                        ///< Defines the workarea size required for mcuxClHash_process on SHA2-384
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_SHA2_384                (192u)                        ///< Defines the workarea size required for mcuxClHash_finish on SHA2-384
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_SHA2_384                (288u)                        ///< Defines the workarea size required for mcuxClHash_verify on SHA2-384
#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_SHA2_512                   (192u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-512
#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_SHA2_512_224               (192u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-512/224
#define MCUXCLHASH_COMPUTE_CPU_WA_BUFFER_SIZE_SHA2_512_256               (192u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-512/256
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_SHA2_512                   (320u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-512
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_SHA2_512_224               (248u)                   ///< Defines the workarea size required for mcuxClHash_compare on SHA2-512/224
#define MCUXCLHASH_COMPARE_CPU_WA_BUFFER_SIZE_SHA2_512_256               (256u)                   ///< Defines the workarea size required for mcuxClHash_compare on SHA2-512/256
#define MCUXCLHASH_COMPUTE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_512       (4u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-512
#define MCUXCLHASH_COMPUTE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_512_224   (4u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-512/224
#define MCUXCLHASH_COMPUTE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_512_256   (4u)                       ///< Defines the workarea size required for mcuxClHash_compute on SHA2-512/256
#define MCUXCLHASH_COMPARE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_512       (132u)                       ///< Defines the workarea size required for mcuxClHash_compare on SHA2-512
#define MCUXCLHASH_COMPARE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_512_224   (60u)                   ///< Defines the workarea size required for mcuxClHash_compare on SHA2-512/224
#define MCUXCLHASH_COMPARE_NONBLOCKING_CPU_WA_BUFFER_SIZE_SHA2_512_256   (68u)                   ///< Defines the workarea size required for mcuxClHash_compare on SHA2-512/256
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_SHA2_512                   (4u)                                                        ///< Defines the workarea size required for mcuxClHash_process on SHA2-512
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_SHA2_512_224               (192u)                        ///< Defines the workarea size required for mcuxClHash_process on SHA2-512/224
#define MCUXCLHASH_PROCESS_CPU_WA_BUFFER_SIZE_SHA2_512_256               (192u)                        ///< Defines the workarea size required for mcuxClHash_process on SHA2-512/256
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_SHA2_512                    (192u)                        ///< Defines the workarea size required for mcuxClHash_finish on SHA2-512
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_SHA2_512_224                (192u)                        ///< Defines the workarea size required for mcuxClHash_finish on SHA2-512/224
#define MCUXCLHASH_FINISH_CPU_WA_BUFFER_SIZE_SHA2_512_256                (192u)                        ///< Defines the workarea size required for mcuxClHash_finish on SHA2-512/256
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_SHA2_512                    (320u)                        ///< Defines the workarea size required for mcuxClHash_verify on SHA2-512
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_SHA2_512_224                (248u)                    ///< Defines the workarea size required for mcuxClHash_verify on SHA2-512/224
#define MCUXCLHASH_VERIFY_CPU_WA_BUFFER_SIZE_SHA2_512_256                (256u)                    ///< Defines the workarea size required for mcuxClHash_verify on SHA2-512/256
/** @} */


/**
 * @defgroup mcuxClHashModes_ContextSize mcuxClHashModes_ContextSize
 * @brief Definitions of context sizes and state sizes for extraction of states of a hash operation.
 * @ingroup mcuxClHash_Constants
 * @{
 */

/**************************************************************************************************************/
/* Definitions of context sizes and state buffer sizes for mcuxClHash_export_state and mcuxClHash_import_state  */
/**************************************************************************************************************/

#define MCUXCLHASH_CONTEXT_SIZE_SHA_1_IN_WORDS                   (116u / sizeof(uint32_t))
#define MCUXCLHASH_EXPORT_IMPORT_STATE_SIZE_SHA_1                (28u)  ///< Defines the state size required for SHA-1
#define MCUXCLHASH_CONTEXT_SIZE_SHA2_224_IN_WORDS                (128u / sizeof(uint32_t))
#define MCUXCLHASH_EXPORT_IMPORT_STATE_SIZE_SHA2_224             (40u)  ///< Defines the state size required for SHA2-224
#define MCUXCLHASH_CONTEXT_SIZE_SHA2_256_IN_WORDS                (128u / sizeof(uint32_t))
#define MCUXCLHASH_EXPORT_IMPORT_STATE_SIZE_SHA2_256             (40u)  ///< Defines the state size required for SHA2-256
#define MCUXCLHASH_CONTEXT_SIZE_SHA2_384_IN_WORDS                (224u / sizeof(uint32_t))
#define MCUXCLHASH_EXPORT_IMPORT_STATE_SIZE_SHA2_384             (80u)  ///< Defines the state size required for SHA2-384
#define MCUXCLHASH_CONTEXT_SIZE_SHA2_512_IN_WORDS                (224u / sizeof(uint32_t))
#define MCUXCLHASH_EXPORT_IMPORT_STATE_SIZE_SHA2_512             (80u)  ///< Defines the state size required for SHA2-512
#define MCUXCLHASH_CONTEXT_SIZE_SHA2_512_224_IN_WORDS            (224u / sizeof(uint32_t))
#define MCUXCLHASH_EXPORT_IMPORT_STATE_SIZE_SHA2_512_224         (80u)  ///< Defines the state size required for SHA2-512/224
#define MCUXCLHASH_CONTEXT_SIZE_SHA2_512_256_IN_WORDS            (224u / sizeof(uint32_t))
#define MCUXCLHASH_EXPORT_IMPORT_STATE_SIZE_SHA2_512_256         (80u)  ///< Defines the state size required for SHA2-512/256
/** @} */


#endif /* MCUXCLHASHMODES_MEMORYCONSUMPTION_H_ */
