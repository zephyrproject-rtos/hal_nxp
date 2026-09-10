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

/** @file  mcuxClPsaDriver.h
 *  @brief Additional macros for the ARM PSA driver
 */

#ifndef MCUXCLPSADRIVER_H_
#define MCUXCLPSADRIVER_H_


#include <mbedtls/build_info.h>
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "tf_psa_crypto_common.h"
#else
#include <common.h>
#endif
#include <psa/crypto.h>
#include <psa_crypto_driver_wrappers.h>
#include <mcuxClConfig.h> // Exported features flags header

/* Include TF-M builtin key driver added from TFM v1.8 updates */
#if defined(PSA_CRYPTO_DRIVER_TFM_BUILTIN_KEY_LOADER)
#include "tfm_builtin_key_loader.h"
#endif /* PSA_CRYPTO_DRIVER_TFM_BUILTIN_KEY_LOADER */

/* If TF-M builtin key driver is enabled (only aplicable for tfm examples) */
#if defined(PSA_CRYPTO_DRIVER_TFM_BUILTIN_KEY_LOADER)
#define MCUXCLPSADRIVER_IS_LOCAL_STORAGE(location) ((location) == PSA_KEY_LOCATION_LOCAL_STORAGE || (location) == TFM_BUILTIN_KEY_LOADER_KEY_LOCATION)
#else
#define MCUXCLPSADRIVER_IS_LOCAL_STORAGE(location) ((location) == PSA_KEY_LOCATION_LOCAL_STORAGE)
#endif

#define PSA_KEY_LOCATION_EXTERNAL_STORAGE ((psa_key_location_t)(PSA_KEY_LOCATION_VENDOR_FLAG | 0x00U))

#endif /* MCUXCLPSADRIVER_H_ */
