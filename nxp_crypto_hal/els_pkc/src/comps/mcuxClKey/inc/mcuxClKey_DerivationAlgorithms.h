/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * @file  mcuxClKey_DerivationAlgorithms.h
 * @brief Supported algorithms for key derivation
 */

#ifndef MCUXCLKEY_DERIVATIONALGORITHMS_H_
#define MCUXCLKEY_DERIVATIONALGORITHMS_H_

#include <mcuxClConfig.h> // Exported features flags header

#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_108
#include <mcuxClKey_DerivationAlgorithms_NIST_SP800_108.h>
#endif
#ifdef MCUXCL_FEATURE_KEY_DERIVATION_NIST_SP800_56C
#include <mcuxClKey_DerivationAlgorithms_NIST_SP800_56C.h>
#endif
#ifdef MCUXCL_FEATURE_KEY_DERIVATION_HKDF
#include <mcuxClKey_DerivationAlgorithms_HKDF.h>
#endif
#ifdef MCUXCL_FEATURE_KEY_DERIVATION_PBKDF2
#include <mcuxClKey_DerivationAlgorithms_PBKDF2.h>
#endif

#endif /* MCUXCLKEY_DERIVATIONALGORITHMS_H_ */
