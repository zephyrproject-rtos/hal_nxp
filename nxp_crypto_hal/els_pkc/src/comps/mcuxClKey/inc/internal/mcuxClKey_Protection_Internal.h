/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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

/** @file  mcuxClKey_Protection_Internal.h
 *  @brief Internal header of mcuxClKey_Protection
 */

#ifndef MCUXCLKEY_PROTECTION_INTERNAL_H_
#define MCUXCLKEY_PROTECTION_INTERNAL_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClKey_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * INTERNAL FUNCTIONS
 **********************************************/
/*! @brief Internal functions for the key component  */

/**
 * @brief no key protection function
 *
 * @param[in]  key              The key of type mcuxClKey_Handle_t
 *
 * @return status
 * @retval MCUXCLKEY_STATUS_ERROR   On error
 * @retval MCUXCLKEY_STATUS_OK      On success
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_protect_fct_none, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_protect_fct_none(
  mcuxClKey_Handle_t key
  );

/**
 * @brief ckdf key protection function
 *
 * @param[in]  key                 The key of type mcuxClKey_Handle_t
 *
 * The key properties must be set before calling this function
 * by calling @ref mcuxClKey_setKeyproperties
 *
 * @return status
 * @retval MCUXCLKEY_STATUS_ERROR   On error
 * @retval MCUXCLKEY_STATUS_OK      On success
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_protect_fct_ckdf, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_protect_fct_ckdf(
  mcuxClKey_Handle_t key
  );


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLKEY_PROTECTION_INTERNAL_H_ */
