/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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
 * @file  mcuxClHmac_Constants.h
 * @brief Constants for the mcuxClHmac component
 */

#ifndef MCUXCLHMAC_CONSTANTS_H_
#define MCUXCLHMAC_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClHashModes_Constants.h>

/**
 * @defgroup mcuxClHmac_Constants mcuxClHmac Constants
 * @brief Constants of @ref mcuxClHmac component
 * @ingroup mcuxClHmac
 * @{
 */

/* Output sizes */

#define MCUXCLHMAC_ELS_OUTPUT_SIZE               (32u)  /* Size of HMAC SHA-256 output in bytes: 256 bits (32 bytes) */
#define MCUXCLHMAC_ELS_OUTPUT_SIZE_IN_WORDS      (MCUXCLHMAC_ELS_OUTPUT_SIZE / sizeof(uint32_t))

#define MCUXCLHMAC_MAX_OUTPUT_SIZE               (MCUXCLHASH_MAX_OUTPUT_SIZE)
#define MCUXCLHMAC_MAX_OUTPUT_SIZE_IN_WORDS      (MCUXCLHMAC_MAX_OUTPUT_SIZE / sizeof(uint32_t))

/* Helper macros and constants for HMAC buffer sizes, assuming HMAC on ELS with SHA-256 is used */
#define MCUXCLHMAC_ELS_BLOCK_SIZE                (64u)
#define MCUXCLHMAC_ELS_SIZE_OF_LENGTH_FIELD      (8u)
#define MCUXCLHMAC_ELS_MIN_PADDING_LENGTH        (MCUXCLHMAC_ELS_SIZE_OF_LENGTH_FIELD + 1u) ///< Size of minimum HMAC padding length
#define MCUXCLHMAC_ELS_INPUTBUFFER_LENGTH(dataLength) \
  ((((dataLength) + MCUXCLHMAC_ELS_MIN_PADDING_LENGTH) + (MCUXCLHMAC_ELS_BLOCK_SIZE) - 1u) / (MCUXCLHMAC_ELS_BLOCK_SIZE)) * MCUXCLHMAC_ELS_BLOCK_SIZE ///< Formula to calculate input buffer size for HMAC with SHA-256

/** @}*/

#endif /* MCUXCLHMAC_CONSTANTS_H_ */
