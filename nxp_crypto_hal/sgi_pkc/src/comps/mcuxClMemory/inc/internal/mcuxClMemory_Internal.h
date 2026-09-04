/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2024 NXP                                       */
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
 * @file  mcuxClMemory_Internal.h
 * @brief Top-level include file for the internal memory operations.
 */

#ifndef MCUXCLMEMORY_INTERNAL_H
#define MCUXCLMEMORY_INTERNAL_H

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClMemory_Constants.h>
#include <mcuxClMemory_Types.h>

#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_Compare_Internal.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_Set_Internal.h>
#include <internal/mcuxClMemory_Copy_Reversed_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClMemory_XOR_Internal.h>

#include <internal/mcuxClMemory_ClearSecure_Internal.h>
#include <internal/mcuxClMemory_CompareDPASecure_Internal.h>
#include <internal/mcuxClMemory_CompareSecure_Internal.h>
#include <internal/mcuxClMemory_CopySecure_Internal.h>
#include <internal/mcuxClMemory_SetSecure_Internal.h>
#include <internal/mcuxClMemory_CopySecure_Reversed_Internal.h>
#include <internal/mcuxClMemory_XORSecure_Internal.h>
#include <internal/mcuxClMemory_XORSecureWithConst_Internal.h>

#endif /* MCUXCLMEMORY_INTERNAL_H */
