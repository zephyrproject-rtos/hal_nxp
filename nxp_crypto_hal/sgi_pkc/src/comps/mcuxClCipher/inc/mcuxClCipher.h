/*--------------------------------------------------------------------------*/
/* Copyright 2020-2022, 2024 NXP                                            */
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

#ifndef MCUXCLCIPHER_H_
#define MCUXCLCIPHER_H_

/** @file  mcuxClCipher.h
 *  @brief Top-level include file for the @ref mcuxClCipher component
 *
 *  This includes headers for all of the functionality provided by the @ref mcuxClCipher component.
 *
 *  @defgroup mcuxClCipher mcuxClCipher
 *  @brief Cipher component
 *
 *  The mcuxClCipher component implements the Encryption and Decryption functionality supported by CLNS.
 *  It supports Symmetric encryption algorithms.
 *
 *  An example of how to use the @ref mcuxClCipher component can be found in /mcuxClCipher/ex.
 *
 *  The @ref mcuxClCipher component supports interfaces to either encrypt/decrypt a message
 *  in one shot (mcuxClCipher_crypt) or to encrypt/decrypt it in parts (mcuxClCipher_init,
 *  mcuxClCipher_process, and mcuxClCipher_finish). In case of encrypting/decrypting a message
 *  in parts, first an initialization has to be performed (mcuxClCipher_init), followed by
 *  zero, one or multiple updates (mcuxClCipher_process), followed by a finalization
 *  (mcuxClCipher_finish). The finalization generates the encrypted/decrypted output data and
 *  destroys the context. After the finalization step, no further updates are possible.
 *
 *  The targeted encryption algorithm is selected by passing one of the offered algorithm mode
 *  descriptors, which are available in the @ref mcuxClCipherModes components.
 *
 * */

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCipher_Types.h>
#include <mcuxClCipher_Functions.h>
#include <mcuxClCipher_Constants.h>
#include <mcuxClCipher_Types.h>

#endif /* MCUXCLCIPHER_H_ */
