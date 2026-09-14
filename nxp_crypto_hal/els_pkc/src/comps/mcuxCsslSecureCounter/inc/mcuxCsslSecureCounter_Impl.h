/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
 * \file  mcuxCsslSecureCounter_Impl.h
 * \brief Selection of the implementation for the secure counter mechanism.
 */

#ifndef MCUXCSSLSECURECOUNTER_IMPL_H_
#define MCUXCSSLSECURECOUNTER_IMPL_H_

/* Include the configuration for the secure counter mechanism. */
#include <mcuxCsslSecureCounter_Cfg.h>

/* Include the selected implementation of the secure counter mechanism. */
#if defined(MCUX_CSSL_SC_USE_HW_CDOG) && (1 == MCUX_CSSL_SC_USE_HW_CDOG)
  #include <mcuxCsslSecureCounter_HardwareAddresses.h>
  #include <mcuxCsslSecureCounter_HW_CDOG.h>
#elif defined(MCUX_CSSL_SC_USE_HYBRID_LOCAL_CDOG) && (1 == MCUX_CSSL_SC_USE_HYBRID_LOCAL_CDOG)
  #include <mcuxCsslSecureCounter_HardwareAddresses.h>
  #include <mcuxCsslSecureCounter_Hybrid_LocalCDOG.h>
#elif defined(MCUX_CSSL_SC_USE_HW_S3SCM) && (1 == MCUX_CSSL_SC_USE_HW_S3SCM)
  #include <mcuxCsslSecureCounter_HardwareAddresses.h>
  #include <mcuxCsslSecureCounter_HW_S3SCM.h>
#elif defined(MCUX_CSSL_SC_USE_HW_SCM) && (1 == MCUX_CSSL_SC_USE_HW_SCM)
  #include <mcuxCsslSecureCounter_HardwareAddresses.h>
  #include <mcuxCsslSecureCounter_HW_SCM.h>
#elif defined(MCUX_CSSL_SC_USE_SW_LOCAL) && (1 == MCUX_CSSL_SC_USE_SW_LOCAL)
  #include <mcuxCsslSecureCounter_SW_Local.h>
#elif defined(MCUX_CSSL_SC_USE_SW_CONTEXT) && (1 == MCUX_CSSL_SC_USE_SW_CONTEXT)
  #include <mcuxCsslSecureCounter_SW_Context.h>
#elif defined(MCUX_CSSL_SC_USE_SW_CALLBACK) && (1 == MCUX_CSSL_SC_USE_SW_CALLBACK)
  #include <mcuxCsslSecureCounter_SW_Callback.h>
#elif defined(MCUX_CSSL_SC_USE_SW_GLOBAL) && (1 == MCUX_CSSL_SC_USE_SW_GLOBAL)
  #include <mcuxCsslSecureCounter_SW_Global.h>
#elif defined(MCUX_CSSL_SC_USE_NONE) && (1 == MCUX_CSSL_SC_USE_NONE)
  #include <mcuxCsslSecureCounter_None.h>
#else
  #error "No secure counter implementation found/configured."
#endif

#endif /* MCUXCSSLSECURECOUNTER_IMPL_H_ */
