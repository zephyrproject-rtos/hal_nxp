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

#include <mcuxClCore_Platform.h>
#include <mcuxClCrc.h>
#include <internal/mcuxClCrc_Internal_Functions.h>
#include <internal/mcuxClCrc_Internal_Constants.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Internal_updateCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Internal_updateCRC16(const uint8_t *pBytes, uint32_t length, uint16_t seed16)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Internal_updateCRC16);
    uint16_t crc = seed16;

    for (uint32_t byteIndex = 0U; byteIndex < length; byteIndex++)
    {
        crc ^= ((uint16_t) pBytes[byteIndex] << 8u);
        for (uint32_t bitIndex = 0u; bitIndex < 8u; bitIndex++)
        {
            if (0u != (crc & 0x8000u))
            {
                crc = (uint16_t) ((((uint32_t) crc << 1u) ^ MCUXCLCRC_DEFAULT_POLY_16) & (uint32_t) 0xFFFFu);
            }
            else
            {
                crc <<= 1u;
            }
        }
    }

    /* Do FA protection, only for compatibility with HW-based implementation */
    MCUX_CSSL_DI_RECORD(identifier, (uint32_t)pBytes + length);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Internal_updateCRC16, crc);
}

#ifdef MCUXCL_FEATURE_CRC_CRC32
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Internal_updateCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Internal_updateCRC32(const uint8_t *pBytes, uint32_t length, uint32_t seed32)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Internal_updateCRC32);

    uint32_t crc = seed32;

    for (uint32_t byteIndex = 0u; byteIndex < length; byteIndex++)
    {
        crc ^= ((uint32_t) pBytes[byteIndex] << 24u);
        for (uint32_t bitIndex = 0u; bitIndex < 8u; bitIndex++)
        {
            if (0u != (crc & 0x80000000u))
            {
                crc = (crc << 1u) ^ MCUXCLCRC_DEFAULT_POLY_32;
            }
            else
            {
                crc <<= 1u;
            }
        }
    }
          
    /* Do FA protection, only for compatibility with HW-based implementation */
    MCUX_CSSL_DI_RECORD(identifier, (uint32_t)pBytes + length);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Internal_updateCRC32, crc);
}
#endif /* MCUXCL_FEATURE_CRC_CRC32 */
