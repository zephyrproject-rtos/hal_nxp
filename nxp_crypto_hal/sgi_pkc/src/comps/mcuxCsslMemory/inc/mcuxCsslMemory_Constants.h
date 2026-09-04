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

/**
 * @file  mcuxCsslMemory_Constants.h
 * @brief Constants definitions for the mcuxCsslMemory component
 */

#ifndef MCUXCSSLMEMORY_CONSTANTS_H
#define MCUXCSSLMEMORY_CONSTANTS_H

#include <stdint.h>
#include <mcuxCsslMemory_Types.h>

/**
 * @defgroup mcuxCsslMemory_Constants mcuxCsslMemory_Constants
 * @brief Defines valid function return codes of @ref mcuxCsslMemory
 * @ingroup mcuxCsslMemory
 * @{
 */

/**********************************************
 * CONSTANTS
 **********************************************/

/**
 * @brief CSSL Memory Component mask value.
 */
#define MCUXCSSLMEMORY_COMPONENT_MASK              0x04240000u ///< Component mask value

/**
 * @defgroup MCUXCSSLMEMORY_STATUS_ MCUXCSSLMEMORY_STATUS_
 * @brief Defines valid @ref mcuxCsslMemory function return codes
 * @ingroup mcuxCsslMemory_Constants
 * @{
 */

#define MCUXCSSLMEMORY_STATUS_OK                 ((mcuxCsslMemory_Status_t) 0x04242E03u) ///< The operation was successful
#define MCUXCSSLMEMORY_STATUS_EQUAL              ((mcuxCsslMemory_Status_t) 0x04242E47u) ///< The two contents of the Memory Compare are equal
#define MCUXCSSLMEMORY_STATUS_ZERO_LENGTH        ((mcuxCsslMemory_Status_t) 0x04242E8Bu) ///< The length passed to Memory Compare is zero
#define MCUXCSSLMEMORY_STATUS_NOT_EQUAL          ((mcuxCsslMemory_Status_t) 0x042489B8u) ///< The two contents of the Memory Compare are not equal
#define MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER  ((mcuxCsslMemory_Status_t) 0x0424533Cu) ///< A parameter was invalid
#define MCUXCSSLMEMORY_STATUS_FAULT              ((mcuxCsslMemory_Status_t) 0x0424F0F0u) ///< A fault occurred in the execution

#define MCUXCSSLMEMORY_KEEP_ORDER     ((uint32_t) 0x042439A5u)  ///< Data storing in destination buffer in original order.
#define MCUXCSSLMEMORY_REVERSE_ORDER  ((uint32_t) 0x0424395Au)  ///< Data storing in destination buffer with reversed order.
/**
 * @}
 */

#endif /* MCUXCSSLMEMORY_CONSTANTS_H */
