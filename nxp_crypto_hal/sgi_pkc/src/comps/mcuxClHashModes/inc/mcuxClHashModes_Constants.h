/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

/** @file  mcuxClHashModes_Constants.h
 *  @brief Constants for use with the mcuxClHashModes component */

#ifndef MCUXCLHASHMODES_CONSTANTS_H_
#define MCUXCLHASHMODES_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

/**
 * @defgroup mcuxClHashModes_Constants mcuxClHashModes_Constants
 * @brief Constants of @ref mcuxClHashModes component
 * @ingroup mcuxClHashModes
 * @{
 */

/**
 * @defgroup MCUXCLHASH_OUTPUT_SIZE_ MCUXCLHASH_OUTPUT_SIZE_
 * @brief Defines for digest sizes
 * @ingroup mcuxClHash_Constants
 * @{
 */

#define MCUXCLHASH_OUTPUT_SIZE_SHA_1                 (20U) ///< SHA-1 output size: 160 bit (20 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA_224               (28U) ///< SHA-224 output size: 224 bit (28 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA_256               (32U) ///< SHA-256 output size: 256 bit (32 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA_384               (48U) ///< SHA-384 output size: 384 bit (48 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA_512               (64U) ///< SHA-512 output size: 512 bit (64 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA_512_224           (28U) ///< SHA-512/224 output size: 224 bit (28 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA_512_256           (32U) ///< SHA-512/256 output size: 256 bit (32 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_224              (28U)  ///< SHA3-224        output size:  224 bit (28 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_256              (32U)  ///< SHA3-256        output size:  256 bit (32 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_384              (48U)  ///< SHA3-384        output size:  384 bit (48 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_512              (64U)  ///< SHA3-512        output size:  512 bit (64 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_SHAKE_128        (168uL) ///< SHA3-SHAKE 128  output size: 1344 bit (168 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_SHAKE_256        (136uL) ///< SHA3-SHAKE 256  output size: 1088 bit (136 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_CSHAKE_128       (168uL) ///< SHA3-CSHAKE 128 output size: 1344 bit (168 bytes)
#define MCUXCLHASH_OUTPUT_SIZE_SHA3_CSHAKE_256       (136uL) ///< SHA3-CSHAKE 256 output size: 1088 bit (136 bytes)
#define MCUXCLHASH_MAX_OUTPUT_SIZE                   (MCUXCLHASH_OUTPUT_SIZE_SHA3_SHAKE_128) ///< Maximum output size
/**@}*/


/**@}*/

#endif /* MCUXCLHASHMODES_CONSTANTS_H_ */
