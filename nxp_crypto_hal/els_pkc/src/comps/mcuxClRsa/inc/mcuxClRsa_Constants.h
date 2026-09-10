/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
 * @file  mcuxClRsa_Constants.h
 * @brief Constant definitions for the mcuxClRsa component
 */

#ifndef MCUXCLRSA_CONSTANTS_H_
#define MCUXCLRSA_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

#ifdef __cplusplus
extern "C" {
#endif

/* TODO:
 * Using defines for SGI Hashes is a workaround to enable testing of internal padding functions. This should not be in the CL, as mode constructors are used for S5xy.
 * CL artifact to remove this workaround: CLNS-6116
 * TT artifact to adapt the tests: CLNS-6117
 */

/**
 * @defgroup mcuxClRsa_Constants mcuxClRsa_Constants
 * @brief Constants of @ref mcuxClRsa component
 * @ingroup mcuxClRsa
 * @{
 */

/**
* @defgroup mcuxClRsa_Sign_Modes mcuxClRsa_Sign_Modes
* @brief Signing modes of the @ref mcuxClRsa component
* @ingroup mcuxClRsa_Constants
* @{
*/

/**
 * @brief Mode definition for RSASP1
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_NoEncode;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-SIGN using SHA-2/224
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_224;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-SIGN using SHA-2/256
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_256;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-SIGN using SHA-2/384
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_384;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-SIGN using SHA-2/512
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_512;

/**
 * @brief Mode definition for RSASSA-PSS-SIGN using SHA-2/224
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_Pss_Sha2_224;

/**
 * @brief Mode definition for RSASSA-PSS-SIGN using SHA-2/256
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_Pss_Sha2_256;

/**
 * @brief Mode definition for RSASSA-PSS-SIGN using SHA-2/384
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_Pss_Sha2_384;

/**
 * @brief Mode definition for RSASSA-PSS-SIGN using SHA-2/512
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Sign_Pss_Sha2_512;

/**
 * @}
 */

/**
* @defgroup mcuxClRsa_Verify_Modes mcuxClRsa_Verify_Modes
* @brief Verify modes of the @ref mcuxClRsa component
* @ingroup mcuxClRsa_Constants
* @{
*/

/**
 * @brief Mode definition for RSAVP1
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_NoVerify;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-VERIFY using SHA-2/224
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_224;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-VERIFY using SHA-2/256
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_256;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-VERIFY using SHA-2/384
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_384;

/**
 * @brief Mode definition for RSASSA-PKCS1-v1_5-VERIFY using SHA-2/512
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_512;

/**
 * @brief Mode definition for RSASSA-PSS-VERIFY using SHA-2/224
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_224;

/**
 * @brief Mode definition for RSASSA-PSS-VERIFY using SHA-2/256
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_256;

/**
 * @brief Mode definition for RSASSA-PSS-VERIFY using SHA-2/384
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_384;

/**
 * @brief Mode definition for RSASSA-PSS-VERIFY using SHA-2/512
 */
extern const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_Pss_Sha2_512;

/**
 * @}
 * @}
 */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_CONSTANTS_H_ */
