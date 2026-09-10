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
 * \file  mcuxCsslSecureCounter_Cfg.h
 * \brief Configuration of the implementation for the secure counter mechanism.
 */

#ifndef MCUXCSSLSECURECOUNTER_CFG_H_
#define MCUXCSSLSECURECOUNTER_CFG_H_

/**
 * \addtogroup mcuxCsslCFG MCUX CSSL -- Configurations
 *
 * \defgroup mcuxCsslSecureCounter_CFG Secure Counter Configuration
 * \brief Configuration options for the secure counter mechanism.
 * \ingroup mcuxCsslCFG
 */

/**
 * \def MCUX_CSSL_SC_USE_HYBRID_LOCAL_CDOG
 * \brief If set to 1, use the hybrid secure counter mechanism implementation based on
 *        a SW counter stored in a local variable and the code watchdog (CDOG) HW IP block.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_HYBRID_LOCAL_CDOG      0

/**
 * \def MCUX_CSSL_SC_USE_HW_CDOG
 * \brief If set to 1, use the secure counter mechanism implementation based on
 *        the code watchdog (CDOG) HW IP block.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_HW_CDOG      0

/**
 * \def MCUX_CSSL_SC_USE_HW_SCM
 * \brief If set to 1, use the secure counter mechanism implementation based on
 *        the subsystem control module (SCM) HW IP block.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_HW_SCM      0

/**
 * \def MCUX_CSSL_SC_USE_HW_S3SCM
 * \brief If set to 1, use the secure counter mechanism implementation based on
 *        the subsystem control module (S3SCM) HW IP block.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_HW_S3SCM      0

/**
 * \def MCUX_CSSL_SC_USE_SW_LOCAL
 * \brief If set to 1, use the secure counter mechanism implementation based on
 *        a SW counter stored in a local variable.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_SW_LOCAL    1

/**
 * \def MCUX_CSSL_SC_USE_SW_CONTEXT
 * \brief If set to 1, use the secure counter mechanism implementation based on
 *        a SW counter stored in a context structure.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_SW_CONTEXT    0

/**
 * \def MCUX_CSSL_SC_USE_SW_CALLBACK
 * \brief If set to 1, use the secure counter mechanism implementation based on
 *        a SW counter pointed to through a callback function.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_SW_CALLBACK    0

/**
 * \def MCUX_CSSL_SC_USE_SW_GLOBAL
 * \brief If set to 1, use the secure counter mechanism implementation based on
 *        a SW counter stored in a global variable.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_SW_GLOBAL    0

/**
 * \def MCUX_CSSL_SC_USE_NONE
 * \brief If set to 1, do not use the secure counter mechanism.
 * \ingroup mcuxCsslSecureCounter_CFG
 */
    #define MCUX_CSSL_SC_USE_NONE    0

/* Basic configuration sanity check */

#endif /* MCUXCSSLSECURECOUNTER_CFG_H_ */
