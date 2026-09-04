/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023, 2025-2026 NXP                                      */
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

/** @file  mcuxClAead_Constants.h
 *  @brief Constants for use with the mcuxClAead component */

#ifndef MCUXCLAEAD_CONSTANTS_H_
#define MCUXCLAEAD_CONSTANTS_H_

/**
 * @defgroup mcuxClAead_Constants mcuxClAead_Constants
 * @brief Constants of @ref mcuxClAead component
 * @ingroup mcuxClAead
 * @{
 */

#include <mcuxClConfig.h> // Exported features flags header

/* Error codes */
#define MCUXCLAEAD_STATUS_ERROR                        ((mcuxClAead_Status_t) 0x01115330U)  ///< Error occured during Aead operation
#define MCUXCLAEAD_STATUS_FAULT_ATTACK                 ((mcuxClAead_Status_t) 0x0111F0F0U)  ///< Aead function returned fault attack
#define MCUXCLAEAD_STATUS_OK                           ((mcuxClAead_Status_t) 0x01112E03U)  ///< Aead function returned successfully
#define MCUXCLAEAD_STATUS_INVALID_PARAM                ((mcuxClAead_Status_t) 0x011153F8U)  ///< Aead function parameter invalid
#define MCUXCLAEAD_STATUS_INVALID_TAG                  ((mcuxClAead_Status_t) 0x011189F8U)  ///< Aead function tag invalid

/**@}*/

#endif /* MCUXCLAEAD_CONSTANTS_H_ */
