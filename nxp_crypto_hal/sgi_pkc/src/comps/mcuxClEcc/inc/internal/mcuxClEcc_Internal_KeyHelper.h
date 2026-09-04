/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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

#ifndef MCUXCLECC_INTERNAL_KEYHELPER_H_
#define MCUXCLECC_INTERNAL_KEYHELPER_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClKey_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Define encoding specs for ECC key loads. Generic types/macro are located in mcuxClKey_Internal.h */

/* ECC combined key specs (see @ref MCUXCLKEY_ENCODING_SPEC_COMP_MASK): */
#define MCUXCLECC_ENCODING_SPEC_EDDSA_SUBPRIVKEY_LOAD_SECURE        (MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_SUBPRIVKEY | MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE)
#define MCUXCLECC_ENCODING_SPEC_EDDSA_PRIVKEYHALFHASH_PTR           (MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_PRIVKEYHALFHASH | MCUXCLKEY_ENCODING_SPEC_ACTION_PTR)
#define MCUXCLECC_ENCODING_SPEC_EDDSA_PRIVKEY_STORE_SECURE          (MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_PRIVKEY | MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE)
#define MCUXCLECC_ENCODING_SPEC_EDDSA_SUBPRIVKEY_STORE_SECURE       (MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_SUBPRIVKEY | MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE)
#define MCUXCLECC_ENCODING_SPEC_EDDSA_PRIVKEYHALFHASH_STORE_SECURE  (MCUXCLKEY_ENCODING_SPEC_ECC_EDDSA_PRIVKEYHALFHASH | MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE)



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_INTERNAL_KEYHELPER_H_ */
