/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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
 * @file  mcuxClFfdh_KeyEncodingMechanisms.h
 * @brief Definition of internal key types in mcuxClFfdh component
 */

#ifndef MCUXCLFFDH_KEYENCODINGMECHANISMS_H
#define MCUXCLFFDH_KEYENCODINGMECHANISMS_H

#include <mcuxClKey_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Key encoding types are provided as external API for the user/customer, and never used internally.")

/**********************************************************/
/* FFDH key encoding                                      */
/**********************************************************/

/**
 * @brief Key encoding descriptor for a FFDH private key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClFfdh_EncodingDescriptor_PrivateKey_Plain;
/**
 * @brief Key encoding for a FFDH private key.
 */
#define mcuxClFfdh_Encoding_PrivateKey_Plain &mcuxClFfdh_EncodingDescriptor_PrivateKey_Plain

/**
 * @brief Key encoding descriptor for a FFDH public key.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClFfdh_EncodingDescriptor_PublicKey_Plain;
/**
 * @brief Key encoding for a FFDH public key.
 */
#define mcuxClFfdh_Encoding_PublicKey_Plain &mcuxClFfdh_EncodingDescriptor_PublicKey_Plain

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLFFDH_KEYENCODINGMECHANISMS_H */
