/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
 * \file  mcuxClBuffer.c
 * \brief Provides the internal implementation for the plain C pointer buffer types.
 */


#include <mcuxClToolchain.h>
#include <mcuxClCore_Platform.h>

#include <mcuxClBuffer.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClBuffer_FeatureConfig.h>
#include <internal/mcuxClMemory_Copy_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_export)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClBuffer_Status_t) mcuxClBuffer_export(mcuxCl_Buffer_t bufDst, uint32_t offset, const uint8_t *pSrc, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_export);

  // Balance the SC for buffer / memory copy params
  MCUX_CSSL_DI_RECORD(copyParamsSrc /* Not used */, pSrc);
  MCUX_CSSL_DI_RECORD(copyParamsDst /* Not used */, bufDst);
  MCUX_CSSL_DI_RECORD(copyParamsDst /* Not used */, offset);
  MCUX_CSSL_DI_RECORD(copyParamsLength /* Not used */, byteLength);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(bufDst, offset, pSrc, byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClBuffer_export, MCUXCLBUFFER_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_import)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClBuffer_Status_t) mcuxClBuffer_import(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_import);

  // Balance the SC for buffer / memory copy params
  MCUX_CSSL_DI_RECORD(copyParamsDst /* Not used */, pDst);
  MCUX_CSSL_DI_RECORD(copyParamsSrc /* Not used */, bufSrc);
  MCUX_CSSL_DI_RECORD(copyParamsSrc /* Not used */, offset);
  MCUX_CSSL_DI_RECORD(copyParamsLength /* Not used */, byteLength);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(bufSrc, offset, pDst, byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClBuffer_import, MCUXCLBUFFER_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}

#if defined(MCUXCLBUFFER_FEATURE_INTERNAL_READ_NO_DEST_INC)
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_read_withoutDestIncrement)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_read_withoutDestIncrement(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_read_withoutDestIncrement);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_withoutDstIncrement_int(pDst, &bufSrc[offset], byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_read_withoutDestIncrement,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_withoutDstIncrement_int)
  );
}
#endif /* MCUXCLBUFFER_FEATURE_INTERNAL_READ_NO_DEST_INC && MCUXCL_FEATURE_BUFFER_USE_POINTER */

