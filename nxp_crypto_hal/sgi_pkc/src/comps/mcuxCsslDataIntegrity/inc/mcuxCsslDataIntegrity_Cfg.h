/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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
 * \file  mcuxCsslDataIntegrity_Cfg.h
 * \brief Configuration of the implementation for the data integrity mechanism.
 */

#ifndef MCUXCSSLDATAINTEGRITY_CFG_H_
#define MCUXCSSLDATAINTEGRITY_CFG_H_

/**
 * \addtogroup mcuxCsslCFG MCUX CSSL -- Configurations
 *
 * \defgroup mcuxCsslDataIntegrity_CFG Data Integrity Configuration
 * \brief Configuration options for the data integrity mechanism.
 * \ingroup mcuxCsslCFG
 */

/**
 * \def MCUX_CSSL_DI_USE_SECURE_COUNTER
 * \brief If set to 1, use the data integrity mechanism implementation based on
 *        the CSSL secure counter mechanism.
 * \ingroup mcuxCsslDataIntegrity_CFG
 */
    #define MCUX_CSSL_DI_USE_SECURE_COUNTER      1

/**
 * \def MCUX_CSSL_DI_USE_NONE
 * \brief If set to 1, do not use the data integrity mechanism.
 * \ingroup mcuxCsslDataIntegrity_CFG
 */
    #define MCUX_CSSL_DI_USE_NONE    0

/* Basic configuration sanity check */

#endif /* MCUXCSSLDATAINTEGRITY_CFG_H_ */
