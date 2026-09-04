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
 * @file  mcuxClCrc_Internal_Constants.h
 * @brief Internal constants of the mcuxClCrc component
 */

#ifndef MCUXCLCRC_INTERNAL_CONSTANTS_H_
#define MCUXCLCRC_INTERNAL_CONSTANTS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClCrc_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClCrc_Internal_Constants mcuxClCrc_Internal_Constants
 * @brief Internal constants of the @ref mcuxClCrc component
 * @ingroup mcuxClCrc
 * @{
 */

/**
 * @defgroup mcuxClCrc_Internal_Constants_Defines mcuxClCrc_Internal_Constants_Defines
 * @brief Defines the CRC constants of component @ref mcuxClCrc
 * @ingroup mcuxClCrc_Internal_Constants
 * @{
 */


#define MCUXCLCRC_DEFAULT_SEED_16 (0xFFFFu)       ///< The initial seed of the default 16-bit CRC algorithm
#define MCUXCLCRC_DEFAULT_SEED_32 (0xFFFFFFFFu)   ///< The initial seed of the default 32-bit CRC algorithm

#define MCUXCLCRC_DEFAULT_POLY_16 (0x00001021u)   ///< The polynomial of the default 16-bit CRC algorithm
#define MCUXCLCRC_DEFAULT_POLY_32 (0x04C11DB7u)   ///< The polynomial of the default 32-bit CRC algorithm

#define MCUXCLCRC_DEFAULT_CRC_OUT_MASK_16 ((uint16_t)0xFFFFu)       ///< The output mask of the default 16-bit CRC algorithm
#define MCUXCLCRC_DEFAULT_CRC_OUT_MASK_32 ((uint32_t)0xFFFFFFFFu)   ///< The output mask of the default 32-bit CRC algorithm

#define MCUXCLCRC_STATUS_FAULT_ATTACK      ((mcuxClCrc_Status_t) 0x0234F0F0u)   ///< Crc function detected a fault attack

/**
 * @}
 */ /* mcuxClCrc_Internal_Constants_Defines */

/**
 * @}
 */ /* mcuxClCrc_Internal_Constants */
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCRC_INTERNAL_CONSTANTS_H_ */
