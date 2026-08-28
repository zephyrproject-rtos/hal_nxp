/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClRsa_Types.h
 * @brief Type definitions for the mcuxClRsa component
 */

#ifndef MCUXCLRSA_TYPES_H_
#define MCUXCLRSA_TYPES_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

/***********************************************************
 *  MACROS
 **********************************************************/

/**
 * @defgroup mcuxClRsa_Macros mcuxClRsa_Macros
 * @brief Defines all macros of @ref mcuxClRsa
 * @ingroup mcuxClRsa
 * @{
 */

/***********************************************************
 *  MACROS RELATED TO FUNCTION STATUS
 **********************************************************/

/**
 * @defgroup MCUXCLRSA_STATUS_ MCUXCLRSA_STATUS_
 * @brief Return code definitions
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_STATUS_SIGN_OK                            ((mcuxClRsa_Status_t) 0x0FF62E07U )  ///< RSA sign operation successful
#define MCUXCLRSA_STATUS_VERIFY_OK                          ((mcuxClRsa_Status_t) 0x0FF62E03U )  ///< RSA verify operation successful
#define MCUXCLRSA_STATUS_OK                                 ((mcuxClRsa_Status_t) 0x0FF62E17U )  ///< RSA operation was successful
#define MCUXCLRSA_STATUS_ERROR                              ((mcuxClRsa_Status_t) 0x0FF65330U )  ///< Error occurred during RSA operation
#define MCUXCLRSA_STATUS_INVALID_INPUT                      ((mcuxClRsa_Status_t) 0x0FF653F8U )  ///< Input data cannot be processed
#define MCUXCLRSA_STATUS_VERIFY_FAILED                      ((mcuxClRsa_Status_t) 0x0FF68930U )  ///< Signature verification failed
#define MCUXCLRSA_STATUS_FAULT_ATTACK                       ((mcuxClRsa_Status_t) 0x0FF6F0F0U )  ///< Fault attack detected
#define MCUXCLRSA_STATUS_KEYGENERATION_OK                   ((mcuxClRsa_Status_t) 0x0FF62E0FU )  ///< RSA key generation operation executed successfully

/** @} */


/***********************************************************
 *  MACROS RELATED TO PUBLIC FUNCTIONS' OPTIONS
 **********************************************************/
/**
 * @defgroup MCUXCLRSA_OPTION_ MCUXCLRSA_OPTION_
 * @brief Function options definitions
 * @ingroup mcuxClRsa_Macros
 * @{
 */
/**
 * @}
 * @}
 */

/**********************************************
 * TYPEDEFS
 **********************************************/
 /**
 * @defgroup mcuxClRsa_Types mcuxClRsa_Types
 * @brief Defines all types of the @ref mcuxClRsa component
 * @ingroup mcuxClRsa
 * @{
 */

/***********************************************************
 *  TYPES RELATED TO FUNCTION STATUS
 **********************************************************/

/**
 * @brief Type for RSA status codes
 */
typedef uint32_t mcuxClRsa_Status_t;

/***********************************************************
 *  TYPES RELATED TO RSA KEY
 **********************************************************/
/**
 * @brief Structure type for Rsa key entries, specifying key entry length and data.
 */
/* Struct is packed to prevent compiler optimizations (e.g., LDR.D) on unaligned data. */
typedef struct
{
  uint8_t* pKeyEntryData;    ///< Pointer to buffer containing the key entry data in big-endian byte order
  uint32_t keyEntryLength;   ///< Byte-length of the buffer pointed to by pKeyEntryData
} __attribute__ ((packed)) mcuxClRsa_KeyEntry_t;

/**
 * @}
 */


#endif /* MCUXCLRSA_TYPES_H_ */

