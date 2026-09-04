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

/** @file  mcuxClCipher_Constants.h
 *  @brief Constants for use with the mcuxClCipher component
 */

#ifndef MCUXCLCIPHER_CONSTANTS_H_
#define MCUXCLCIPHER_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

/**
 * @defgroup mcuxClCipher_Constants mcuxClCipher_Constants
 * @brief Constants of @ref mcuxClCipher component
 * @ingroup mcuxClCipher
 * @{
 */

/* Status codes */
#define MCUXCLCIPHER_STATUS_ERROR                        ((mcuxClCipher_Status_t) 0x02225330U) ///< Functional error detected in cipher operation
#define MCUXCLCIPHER_STATUS_FAILURE                      ((mcuxClCipher_Status_t) 0x02225334U) ///< Functional failure detected
#define MCUXCLCIPHER_STATUS_INVALID_INPUT                ((mcuxClCipher_Status_t) 0x022253F8U) ///< Invalid input provided
#define MCUXCLCIPHER_STATUS_FAULT_ATTACK                 ((mcuxClCipher_Status_t) 0x0222F0F0U) ///< Fault attack detected
#define MCUXCLCIPHER_STATUS_OK                           ((mcuxClCipher_Status_t) 0x02222E03U) ///< Blocking operation finished successfully
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
#define MCUXCLCIPHER_STATUS_JOB_STARTED                  ((mcuxClCipher_Status_t) 0x02222E47U) ///< Non-blocking operation started successfully
#define MCUXCLCIPHER_STATUS_JOB_COMPLETED                ((mcuxClCipher_Status_t) 0x02222E8BU) ///< Non-blocking operation finished successfully
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/** @}*/
#endif /* MCUXCLCIPHER_CONSTANTS_H_ */
