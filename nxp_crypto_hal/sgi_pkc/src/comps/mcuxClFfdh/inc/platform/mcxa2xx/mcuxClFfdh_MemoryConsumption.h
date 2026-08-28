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
 * @file  mcuxClFfdh_MemoryConsumption.h
 * @brief Defines the memory consumption for the mcuxClFfdh component
 */

#ifndef MCUXCLFFDH_MEMORYCONSUMPTION_H_
#define MCUXCLFFDH_MEMORYCONSUMPTION_H_

#include <mcuxClCore_Macros.h>

/**
 * @defgroup mcuxClFfdh_MemoryConsumption mcuxClFfdh_MemoryConsumption
 * @brief Defines the memory consumption for the @ref mcuxClFfdh component
 * @ingroup mcuxClFfdh
 * @{
 */

/**
 * @addtogroup MCUXCLFFDH_WACPU
 * @brief Define the CPU workarea size required by mcuxClFfdh APIs.
 * @{
 */

#define MCUXCLKEY_AGREEMENT_FFDH_WACPU_SIZE_2048 (420u )  ///< CPU workarea size (in bytes) for ffdhe2048 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WACPU_SIZE_3072 (420u )  ///< CPU workarea size (in bytes) for ffdhe3072 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WACPU_SIZE_4096 (420u )  ///< CPU workarea size (in bytes) for ffdhe4096 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WACPU_SIZE_6144 (420u )  ///< CPU workarea size (in bytes) for ffdhe6144 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WACPU_SIZE_8192 (1448u )  ///< CPU workarea size (in bytes) for ffdhe8192 #mcuxClKey_agreement.

/**
 * @}
 */  /* MCUXCLFFDH_WACPU */


/**
 * @addtogroup MCUXCLFFDH_WAPKC
 * @brief Define the PKC workarea size required by mcuxClFfdh APIs.
 * @{
 */

/**
 * @brief PKC wordsize in FFDH component.
 */
#define MCUXCLFFDH_PKC_WORDSIZE  8u

/**
 * PKC workarea size (in bytes) for #mcuxClFfdh_FFDH_KeyAgreement for arbitrary lengths of p.
 */
#define MCUXCLKEY_AGREEMENT_FFDH_WAPKC_SIZE_2048 (2448u )  ///< PKC workarea size (in bytes) for ffdhe2048 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WAPKC_SIZE_3072 (3600u )  ///< PKC workarea size (in bytes) for ffdhe3072 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WAPKC_SIZE_4096 (4752u )  ///< PKC workarea size (in bytes) for ffdhe4096 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WAPKC_SIZE_6144 (7056u )  ///< PKC workarea size (in bytes) for ffdhe6144 #mcuxClKey_agreement.
#define MCUXCLKEY_AGREEMENT_FFDH_WAPKC_SIZE_8192 (7328u )  ///< PKC workarea size (in bytes) for ffdhe8192 #mcuxClKey_agreement.


/**
 * @}
 */  /* MCUXCLFFDH_WAPKC */


/**
 * @}
 */  /* mcuxClFfdh_MemoryConsumption */

#endif /* MCUXCLFFDH_MEMORYCONSUMPTION_H_ */
