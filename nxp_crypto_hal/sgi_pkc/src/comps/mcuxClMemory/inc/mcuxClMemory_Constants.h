/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2025 NXP                                                 */
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

/** @file  mcuxClMemory_Constants.h
 *  @brief Memory constant header.
 * This header exposes constants used by the @ref mcuxClMemory functions. */

/**
 * @defgroup mcuxClMemory_Constants mcuxClMemory_Constants
 * @brief Defines all constants used by the @ref mcuxClMemory functions.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_CONSTANTS_H
#define MCUXCLMEMORY_CONSTANTS_H

/**********************************************
 * CONSTANTS
 **********************************************/

#define MCUXCLMEMORY_COMPONENT_MASK              0x09990000u ///< Component mask value

/**
 * @defgroup MCUXCLMEMORY_STATUS_ MCUXCLMEMORY_STATUS_
 * @brief Defines valid mcuxClMemory function return codes
 * @ingroup mcuxClMemory_Types_Macros
 * @{
 */
#define MCUXCLMEMORY_STATUS_EQUAL                ((mcuxClMemory_Status_t) 0x09992E47u) ///< The two contents of the Memory Compare are equal
#define MCUXCLMEMORY_STATUS_NOT_EQUAL            ((mcuxClMemory_Status_t) 0x099989B8u) ///< The two contents of the Memory Compare are not equal
#define MCUXCLMEMORY_STATUS_FAULT                ((mcuxClMemory_Status_t) 0x0999F0F0u) ///< A fault occurred in the execution

/**
 * @}
 */

#endif  /* MCUXCLMEMORY_CONSTANTS_H */

/**
 * @}
 */
