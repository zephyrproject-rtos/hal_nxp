/*--------------------------------------------------------------------------*/
/* Copyright 2020-2022, 2025 NXP                                            */
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
 * @file  mcuxCsslFlowProtection_Impl.h
 * @brief Selection of the implementation for the flow protection mechanism.
 */

#ifndef MCUX_CSSL_FLOW_PROTECTION_IMPL_H_
#define MCUX_CSSL_FLOW_PROTECTION_IMPL_H_

/* Include the configuration for the flow protection mechanism. */
#include <mcuxCsslFlowProtection_Cfg.h>

/* Include the selected implementation of the flow protection mechanism. */
#if defined(MCUX_CSSL_FP_USE_CODE_SIGNATURE) && (1 == MCUX_CSSL_FP_USE_CODE_SIGNATURE)
#  include <mcuxCsslFlowProtection_CodeSignature.h>
#elif defined(MCUX_CSSL_FP_USE_SECURE_COUNTER) \
      && (1 == MCUX_CSSL_FP_USE_SECURE_COUNTER)
#  include <mcuxCsslSecureCounter_Cfg.h>
#  include <mcuxCsslFlowProtection_SecureCounter_Common.h>
#  if defined(MCUX_CSSL_SC_USE_SW_LOCAL) && (1 == MCUX_CSSL_SC_USE_SW_LOCAL)
#    include <mcuxCsslFlowProtection_SecureCounter_Local.h>
#  else
#    include <mcuxCsslFlowProtection_SecureCounter_Global.h>
#  endif
#elif defined(MCUX_CSSL_FP_USE_NONE) && (1 == MCUX_CSSL_FP_USE_NONE)
#  include <mcuxCsslFlowProtection_None.h>
#else
  #error "No flow protection implementation found/configured."
#endif

#endif /* MCUX_CSSL_FLOW_PROTECTION_IMPL_H_ */
