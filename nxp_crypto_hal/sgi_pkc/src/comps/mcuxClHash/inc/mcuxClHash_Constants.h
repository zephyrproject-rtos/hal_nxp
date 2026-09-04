/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023, 2025 NXP                                            */
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

/** @file  mcuxClHash_Constants.h
 *  @brief Constants for use with the mcuxClHash component */

#ifndef MCUXCLHASH_CONSTANTS_H_
#define MCUXCLHASH_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

/**
 * @defgroup mcuxClHash_Constants mcuxClHash_Constants
 * @brief Constants of @ref mcuxClHash component
 * @ingroup mcuxClHash
 * @{
 */

/**
 * @defgroup MCUXCLHASH_STATUS_ MCUXCLHASH_STATUS_
 * @brief Return code definitions
 * @ingroup mcuxClHash_Constants
 * @{
 */
#define MCUXCLHASH_STATUS_OK                                  ((mcuxClHash_Status_t) 0x06662E03u)                   ///< Hash operation successful
#define MCUXCLHASH_STATUS_COMPARE_EQUAL                       ((mcuxClHash_Status_t) 0x06662E07u)                   ///< Hash operation and comparison of result successful
#define MCUXCLHASH_COMPARE_EQUAL                              MCUXCLHASH_STATUS_COMPARE_EQUAL                       ///< \deprecated Replaced by MCUXCLHASH_STATUS_COMPARE_EQUAL
#define MCUXCLHASH_STATUS_FAILURE                             ((mcuxClHash_Status_t) 0x06665330u)                   ///< Hash operation failed
#define MCUXCLHASH_FAILURE                                    MCUXCLHASH_STATUS_FAILURE                             ///< \deprecated Replaced by MCUXCLHASH_STATUS_FAILURE
#define MCUXCLHASH_STATUS_INVALID_PARAMS                      ((mcuxClHash_Status_t) 0x066653F8u)                   ///< Hash function called with invalid parameters
#define MCUXCLHASH_STATUS_COMPARE_NOT_EQUAL                   ((mcuxClHash_Status_t) 0x06668930u)                   ///< Hash operation succeeded, but comparison of result failed
#define MCUXCLHASH_COMPARE_NOT_EQUAL                          ((mcuxClHash_Status_t) 0x06668930u)                   ///< \deprecated Replaced by MCUXCLHASH_STATUS_COMPARE_NOT_EQUAL
#define MCUXCLHASH_STATUS_FULL                                ((mcuxClHash_Status_t) 0x0666538Eu)                   ///< Hash operation failed because the total input size exceeds the upper limit
#define MCUXCLHASH_STATUS_FAULT_ATTACK                        ((mcuxClHash_Status_t) 0x0666F0F0u)                   ///< Fault attack (unexpected behavior) detected
#define MCUXCLHASH_STATUS_JOB_STARTED                         ((mcuxClHash_Status_t) 0x06662E47u)                   ///< There is ongoing job in coprocessor which will trigger user callback on exit
#define MCUXCLHASH_STATUS_JOB_COMPLETED                       ((mcuxClHash_Status_t) 0x06662E8Bu)                   ///< Job started in coprocessor has completed successfully
#define MCUXCLHASH_STATUS_JOB_COMPLETED_COMPARE_NOT_EQUAL     ((mcuxClHash_Status_t) 0x06668903u)                   ///< Job started in coprocessor has completed, but comparison of result failed
#define MCUXCLHASH_STATUS_JOB_UNAVAILABLE                     ((mcuxClHash_Status_t) 0x066689BCu)                   ///< Job started in coprocessor is not available

/**@}*/

/**@}*/

#endif /* MCUXCLHASH_CONSTANTS_H_ */
