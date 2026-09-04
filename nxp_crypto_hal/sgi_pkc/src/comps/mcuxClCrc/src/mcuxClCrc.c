/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Platform.h>

#include <mcuxClCrc.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClCrc_Internal_Constants.h>
#include <internal/mcuxClCrc_Internal_Functions.h>

#include <internal/mcuxClCrc_Drv.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_computeCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_computeCRC16(const uint8_t *pBytes, uint32_t length)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_computeCRC16);
  MCUX_CSSL_DI_RECORD(mcuxClCrc_Internal_updateCRC16_pBytes, (uint32_t)pBytes + length);

  /* Configure CRC to perform 16-bit CRC computation with a given seed
   * and the platform-specified 16-bit CRC polynomial.
   * Also configure the writes to be byte-wise transposed */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC16(
    MCUXCLCRC_DEFAULT_POLY_16,
    MCUXCLCRC_DEFAULT_SEED_16,
    MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS | MCUXCLCRC_DRV_BIT_COMPLEMENT_RESULT));

  MCUX_CSSL_FP_FUNCTION_CALL(uint16_t, crcResult, mcuxClCrc_Drv_updateCRC16(pBytes, length));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_computeCRC16, crcResult,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC16),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_updateCRC16));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_computeCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_computeCRC32(const uint8_t *pBytes, uint32_t length)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_computeCRC32);
  MCUX_CSSL_DI_RECORD(mcuxClCrc_Internal_updateCRC32_pBytes, (uint32_t)pBytes + length);

  /* Configure CRC to perform 32-bit CRC computation with a given seed
   * and the platform-specified 32-bit CRC polynomial.
   * Also configure both reads and writes to be byte-wise transposed */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC32(
    MCUXCLCRC_DEFAULT_POLY_32,
    MCUXCLCRC_DEFAULT_SEED_32,
    MCUXCLCRC_DRV_READ_TRANSPOSE_BYTES_NO_BITS | MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS | MCUXCLCRC_DRV_BIT_COMPLEMENT_RESULT));

  MCUX_CSSL_FP_FUNCTION_CALL(crcResult, mcuxClCrc_Drv_updateCRC32(pBytes, length));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_computeCRC32, crcResult,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC32),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_updateCRC32));
}
