/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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
 * @file  mcuxCsslMemory.h
 * @brief Top-level include file for the CSSL memory functions
 */

#ifndef MCUXCSSLMEMORY_H
#define MCUXCSSLMEMORY_H

/**
 * @defgroup mcuxCsslMemory mcuxCsslMemory
 * @brief Control Flow Protected Memory Functions
 *
 * @ingroup mcuxCsslAPI
 */
#include <mcuxCsslMemory_Constants.h>
#include <mcuxCsslMemory_Types.h>

#include <mcuxClConfig.h> // Exported features flags header


#include <mcuxCsslMemory_Compare.h>

#include <mcuxCsslMemory_Clear.h>

#include <mcuxCsslMemory_Copy.h>

#include <mcuxCsslMemory_Set.h>

#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COPY
#include <mcuxCsslMemory_SecureCopy.h>
#endif

#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_XOR
#include <mcuxCsslMemory_SecureXOR.h>
#endif

#include <mcuxCsslMemory_SecureSet.h>


#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COMPARE
#include <mcuxCsslMemory_SecureCompare.h>
#endif

#endif /* MCUXCSSLMEMORY_H */
