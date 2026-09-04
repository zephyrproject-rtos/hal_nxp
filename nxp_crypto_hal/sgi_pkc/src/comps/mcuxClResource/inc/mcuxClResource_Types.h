/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023, 2025 NXP                                            */
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
 * @file  mcuxClResource_Types.h
 * @brief Type definitions for the mcuxClResource component
 */


#ifndef MCUXCLRESOURCE_TYPES_H_
#define MCUXCLRESOURCE_TYPES_H_

#include <mcuxClCore_Platform.h>


/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @defgroup mcuxClResource_Types mcuxClResource_Types
 * @brief Defines all types of @ref mcuxClResource
 * @ingroup mcuxClResource
 * @{
 */

/**
 * @brief Type for mcuxClResource status codes
 *
 * This type provides information about the status of the Resource operation
 * that has been performed.
 */
typedef uint32_t mcuxClResource_Status_t;

/**
 * @brief Resource context type
 */
typedef struct mcuxClResource_Context mcuxClResource_Context_t;

/**
 * @brief Callback type for acquiring a mutex
 */
typedef uint32_t (*mcuxClResource_MutexAcquire_Callback_t)(uint32_t value);

/**
 * @brief Callback type for releasing a mutex
 */
typedef uint32_t (*mcuxClResource_MutexRelease_Callback_t)(uint32_t value);

typedef uint32_t mcuxClResource_HwId_t;
typedef uint32_t mcuxClResource_HwStatus_t;
typedef uint32_t mcuxClResource_Interrupt_t;

/**
 * @}
 */ /* mcuxClResource_Types */


/**********************************************
 * CONSTANTS
 **********************************************/
/**
 * @defgroup mcuxClResource_Constants mcuxClResource_Constants
 * @brief Defines all constants of @ref mcuxClResource
 * @ingroup mcuxClResource
 * @{
 */

/**
 * @defgroup MCUXCLRESOURCE_STATUS_  mcuxClResource return code definitions
 * @{
 */
#define MCUXCLRESOURCE_STATUS_OK           ((mcuxClResource_Status_t) 0x0CCC2E03u)  ///< Resource operation successful
#define MCUXCLRESOURCE_STATUS_UNAVAILABLE  ((mcuxClResource_Status_t) 0x0CCC5334u)  ///< Resource request failed
#define MCUXCLRESOURCE_STATUS_ERROR        ((mcuxClResource_Status_t) 0x0CCC5330u)  ///< Error occurred during Resource operation
#define MCUXCLRESOURCE_STATUS_FAULT_ATTACK ((mcuxClResource_Status_t) 0x0CCCF0F0u)  ///< Fault attack detected

/**@}*/

/**
 * @defgroup MCUXCLRESOURCE_HWSTATUS_ mcuxClResource status of HW resource and option to request HW resource
 * @brief Defines of hardware request options
 * @{
 */
#define MCUXCLRESOURCE_HWSTATUS_SIZE_IN_BITS        (2u)  ///< bit length of HW request option
#define MCUXCLRESOURCE_HWSTATUS_INTERRUPTABLE       ((mcuxClResource_HwStatus_t) 0x01u)  ///< option to request HW as interruptible
#define MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE   ((mcuxClResource_HwStatus_t) 0x02u)  ///< option to request HW as non-interruptible


/**@}*/

/**
 * @}
 */ /* mcuxClResource_Constants */


#endif /* MCUXCLRESOURCE_TYPES_H_ */
