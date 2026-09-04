/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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

/** @file  mcuxClMacModes_Common.c
 *  @brief Implementation of mcuxClMacModes component public API
 */

#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClMacModes_Constants.h>
#include <mcuxClMacModes_Functions.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCipher_Constants.h>

#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMacModes_Common_Constants.h>
#include <internal/mcuxClMacModes_Common_Types.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMacModes_Sgi_Algorithms.h>

#include <internal/mcuxClMacModes_Sgi_Gmac.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_createGmacMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_createGmacMode(
  mcuxClMac_CustomMode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_createGmacMode);

  /* copy the common GMAC mode descriptor into the mode */
  MCUX_CSSL_DI_RECORD(mode_cpy, (uint32_t)&mode->common);
  MCUX_CSSL_DI_RECORD(mode_cpy, (uint32_t)&mcuxClMac_CommonModeDescriptor_GMAC);
  MCUX_CSSL_DI_RECORD(mode_cpy, sizeof(mcuxClMac_CommonModeDescriptor_GMAC));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(
    (uint8_t *)&mode->common,
    (const uint8_t *)&mcuxClMac_CommonModeDescriptor_GMAC,
    sizeof(mcuxClMac_CommonModeDescriptor_GMAC)));

  /* pCustom points to the end of the mode descriptor in memory,
     assumes user allocated sufficient memory with MCUXCLMAC_GMAC_MODE_DESCRIPTOR_SIZE */
  uintptr_t pCustomLocation = (uintptr_t)mode + sizeof(mcuxClMac_ModeDescriptor_t);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("integer cast to pointer void *")
  mode->pCustom = (void *) pCustomLocation;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

  mcuxClMacModes_GmacModeDescriptor_t * gmacModeDescriptor = (mcuxClMacModes_GmacModeDescriptor_t *) mode->pCustom;
  gmacModeDescriptor->pIv = pIv;
  gmacModeDescriptor->ivLength = ivLength;

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_createGmacMode, MCUXCLMAC_STATUS_OK,
             MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
}


