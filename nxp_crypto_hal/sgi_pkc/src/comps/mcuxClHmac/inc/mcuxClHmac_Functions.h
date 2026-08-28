/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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
 * @file  mcuxClHmac_Functions.h
 * @brief Functions for the mcuxClHmac component
 */

#ifndef MCUXCLHMAC_FUNCTIONS_H_
#define MCUXCLHMAC_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClSession_Types.h>
#include <mcuxClMac_Types.h>
#include <mcuxClHash_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClHmac_Functions mcuxClHmac_Functions
 * @brief Defines all functions of @ref mcuxClHmac
 * @ingroup mcuxClHmac
 * @{
*/

/**
 * @defgroup mcuxClHmac_Constructors APIs to construct HMAC modes
 * @brief Interfaces to construct HMAC modes of operation.
 * @ingroup mcuxClHmac_Functions
 * @{
 */

/**
 * @brief This function creates a HMAC mode descriptor for software implementations of HMAC.
 *
 * The SW-HMAC modes of operation require additional input, hence a
 * mode descriptor has to be constructed with this function.
 * The resulting descriptor will be written to @p mode.
 *
 * This function must be called before any SW-HMAC operation is performed.
 *
 * @param mode[out]             Pointer to HMAC custom mode to be initialized.
 * @param mcuxClHash_Algo_t[in]  Pointer to the Hash algorithm descriptor to be used.
 *
 * @return status
 * 
 * \implements{REQ_788238,REQ_788239}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_createHmacMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_createHmacMode(
    mcuxClMac_CustomMode_t mode,
    mcuxClHash_Algo_t hashAlgorithm
);

/**
 * @}
 */ /* mcuxClHmac_Constructors */

/**
 * @}
 */ /* mcuxClHmac_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHMAC_FUNCTIONS_H_ */
