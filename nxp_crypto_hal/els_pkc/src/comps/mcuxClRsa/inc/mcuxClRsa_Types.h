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
#define MCUXCLRSA_STATUS_VERIFYPRIMITIVE_OK                 ((mcuxClRsa_Status_t) 0x0FF62E0Bu )  ///< RSA verify primitive operation (RSAVP1) successful
#define MCUXCLRSA_STATUS_SIGN_OK                            ((mcuxClRsa_Status_t) 0x0FF62E07u )  ///< RSA sign operation successful
#define MCUXCLRSA_STATUS_VERIFY_OK                          ((mcuxClRsa_Status_t) 0x0FF62E03u )  ///< RSA verify operation successful
#define MCUXCLRSA_STATUS_OK                                 ((mcuxClRsa_Status_t) 0x0FF62E17u )  ///< RSA operation was successful
#define MCUXCLRSA_STATUS_ERROR                              ((mcuxClRsa_Status_t) 0x0FF65330u )  ///< Error occurred during RSA operation
#define MCUXCLRSA_STATUS_INVALID_INPUT                      ((mcuxClRsa_Status_t) 0x0FF653F8u )  ///< Input data cannot be processed
#define MCUXCLRSA_STATUS_VERIFY_FAILED                      ((mcuxClRsa_Status_t) 0x0FF68930u )  ///< Signature verification failed
#define MCUXCLRSA_STATUS_FAULT_ATTACK                       ((mcuxClRsa_Status_t) 0x0FF6F0F0u )  ///< Fault attack detected
#define MCUXCLRSA_STATUS_KEYGENERATION_OK                   ((mcuxClRsa_Status_t) 0x0FF62E0Fu )  ///< RSA key generation operation executed successfully
#define MCUXCLRSA_STATUS_KEYGENERATION_ITERATIONSEXCEEDED   ((mcuxClRsa_Status_t) 0x0FF68934u )  ///< RSA key generation exceeds the limit of iterations to generate a prime
#define MCUXCLRSA_STATUS_RNG_ERROR                          ((mcuxClRsa_Status_t) 0x0FF65338u )  ///< Random number (DRBG / PRNG) error (unexpected behavior)
#define MCUXCLRSA_STATUS_ERROR_MEMORY_ALLOCATION            ((mcuxClRsa_Status_t) 0x0FF65334u )  ///< Memory allocation error during RSA operation


/** @} */


/***********************************************************
 *  MACROS RELATED TO RSA KEY
 **********************************************************/
/**
 * @defgroup MCUXCLRSA_KEY_ MCUXCLRSA_KEY_
 * @brief Key type definitions
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define  MCUXCLRSA_KEY_PUBLIC           (0xA5A5A5A5U)  ///< RSA key type public
#define  MCUXCLRSA_KEY_PRIVATEPLAIN     (0x5A5A5A5AU)  ///< RSA key type private plain
#define  MCUXCLRSA_KEY_PRIVATECRT       (0xB4B4B4B4U)  ///< RSA key type private CRT
#define  MCUXCLRSA_KEY_PRIVATECRT_DFA   (0x4B4B4B4BU)  ///< RSA key type private CRT, with which a fault-protected CRT operation is executed
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
#define MCUXCLRSA_OPTION_MESSAGE_PLAIN                 (0XA5U) ///< Option passing a plain message as input to the sign or verify operation.
#define MCUXCLRSA_OPTION_MESSAGE_DIGEST                (0X5AU) ///< Option passing a message digest as input to the sign or verify operation.
#define MCUXCLRSA_OPTION_MESSAGE_MASK                  (MCUXCLRSA_OPTION_MESSAGE_PLAIN | MCUXCLRSA_OPTION_MESSAGE_DIGEST) ///< Mask to set option MESSAGE_PLAIN or MESSAGE_DIGEST
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

/**
 * @brief Deprecated type for RSA protected status codes
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_Status_Protected_t;

/***********************************************************
 *  TYPES RELATED TO RSA KEY
 **********************************************************/
/**
 * @brief Structure type for Rsa key entries, specifying key entry length and data.
 */
typedef struct
{
  uint8_t* pKeyEntryData;    ///< Pointer to buffer containing the key entry data in big-endian byte order
  uint32_t keyEntryLength;   ///< Byte-length of the buffer pointed to by pKeyEntryData
}mcuxClRsa_KeyEntry_t;

/**
 * @brief Pointer type to Rsa key entries.
 */
// TODO CLNS-6135: replace all occurrences of "mcuxClRsa_KeyEntry" by "mcuxClRsa_KeyEntry_t *", which is more explicit for a type
typedef mcuxClRsa_KeyEntry_t * mcuxClRsa_KeyEntry;

/**
 * @brief Structure type for Rsa key, specifying key type and key entries.
 */
typedef struct mcuxClRsa_Key
{
  uint32_t              keytype;  ///< Key type specifier:
                                     ///< In case of an RSA public key this shall be set to @ref MCUXCLRSA_KEY_PUBLIC.
                                     ///< In case of an RSA private plain key this shall be set to @ref MCUXCLRSA_KEY_PRIVATEPLAIN.
                                     ///< In case of an RSA private CRT key this shall be set to @ref MCUXCLRSA_KEY_PRIVATECRT.
                                     ///< In case of an RSA private CRT key, with which a fault-protected CRT operation is executed, this shall be set to @ref MCUXCLRSA_KEY_PRIVATECRT_DFA
  mcuxClRsa_KeyEntry_t * pMod1;    ///< Pointer to first key entry:
                                     ///< In case of @ref MCUXCLRSA_KEY_PUBLIC and @ref MCUXCLRSA_KEY_PRIVATEPLAIN the first key entry points to the public parameter modulus N.
                                     ///< In case of @ref MCUXCLRSA_KEY_PRIVATECRT and @ref MCUXCLRSA_KEY_PRIVATECRT_DFA the first key entry points to the private parameter prime factor P.
  mcuxClRsa_KeyEntry_t * pMod2;    ///< Pointer to second key entry:
                                     ///< In case of @ref MCUXCLRSA_KEY_PUBLIC and @ref MCUXCLRSA_KEY_PRIVATEPLAIN this pointer shall be set to NULL.
                                     ///< In case of @ref MCUXCLRSA_KEY_PRIVATECRT and @ref MCUXCLRSA_KEY_PRIVATECRT_DFA the second key entry points to the private parameter prime factor Q.
  mcuxClRsa_KeyEntry_t * pQInv;    ///< Pointer to third key entry:
                                     ///< In case of @ref MCUXCLRSA_KEY_PUBLIC and @ref MCUXCLRSA_KEY_PRIVATEPLAIN this pointer shall be set to NULL.
                                     ///< In case of @ref MCUXCLRSA_KEY_PRIVATECRT and @ref MCUXCLRSA_KEY_PRIVATECRT_DFA the third key entry points to the private parameter QInv = (1 / (Q % P)).
  mcuxClRsa_KeyEntry_t * pExp1;    ///< Pointer to fourth key entry:
                                     ///< In case of @ref MCUXCLRSA_KEY_PUBLIC the first exponent entry points to the public parameter exponent E.
                                     ///< In case of @ref MCUXCLRSA_KEY_PRIVATEPLAIN the first exponent entry points to the private parameter exponent D.
                                     ///< In case of @ref MCUXCLRSA_KEY_PRIVATECRT and @ref MCUXCLRSA_KEY_PRIVATECRT_DFA the first exponent entry points to the private parameter DP = D % (P-1).
  mcuxClRsa_KeyEntry_t * pExp2;    ///< Pointer to fifth key entry:
                                     ///< In case of @ref MCUXCLRSA_KEY_PUBLIC and @ref MCUXCLRSA_KEY_PRIVATEPLAIN this pointer shall be set to NULL.
                                     ///< In case of @ref MCUXCLRSA_KEY_PRIVATECRT and @ref MCUXCLRSA_KEY_PRIVATECRT_DFA the second exponent entry points to the private parameter DQ = D % (Q-1).
  mcuxClRsa_KeyEntry_t * pExp3;    ///< Pointer to sixth key entry:
                                     ///< In case of @ref MCUXCLRSA_KEY_PUBLIC, @ref MCUXCLRSA_KEY_PRIVATEPLAIN, and @ref MCUXCLRSA_KEY_PRIVATECRT this pointer shall be set to NULL.
                                     ///< In case of @ref MCUXCLRSA_KEY_PRIVATECRT_DFA the third exponent entry points to the public parameter exponent E.
} mcuxClRsa_Key;


/***********************************************************
 *  TYPES RELATED TO SIGN / VERIFY FUNCTIONALITY
 **********************************************************/

/**
 * @brief Forward declaration of Sign/Verify mode struct.
 */
typedef struct mcuxClRsa_SignVerifyMode_t mcuxClRsa_SignVerifyMode_t;

/**
 * @brief Pointer type to Sign/Verify mode.
 */
typedef mcuxClRsa_SignVerifyMode_t * mcuxClRsa_SignVerifyMode;

/**
 * @}
 */


#endif /* MCUXCLRSA_TYPES_H_ */

