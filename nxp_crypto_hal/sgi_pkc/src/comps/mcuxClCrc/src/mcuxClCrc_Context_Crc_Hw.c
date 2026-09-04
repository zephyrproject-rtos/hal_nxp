/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCrc.h>

#include <internal/mcuxClCrc_Drv.h>
#include <internal/mcuxClCrc_Internal_Functions.h>
#include <internal/mcuxClCrc_Internal_Constants.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_computeContextCrc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_computeContextCrc(void* pCtx, uint32_t contextSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_computeContextCrc);

    /* Assert context at least contains the crc value */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(contextSize, 4u, UINT32_MAX);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    uint32_t *pContext = (uint32_t *)pCtx;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC32(MCUXCLCRC_DEFAULT_POLY_32,
                                                                MCUXCLCRC_DEFAULT_SEED_32,
                                                                MCUXCLCRC_DRV_READ_TRANSPOSE_BYTES_NO_BITS  |
                                                                MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS |
                                                                MCUXCLCRC_DRV_BIT_COMPLEMENT_RESULT));

    uint32_t * pContextEnd = pContext + (contextSize / sizeof(uint32_t));
    MCUX_CSSL_DI_RECORD(crcLoop, pContextEnd);

    pContext++; /* skip place for the CRC */
    while( pContext < pContextEnd)
    {
        mcuxClCrc_Drv_writeData32bit(*pContext++);
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    *((uint32_t*) pCtx) = mcuxClCrc_Sfr_readData();
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_DI_EXPUNGE(crcLoop, pContext);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCrc_computeContextCrc,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC32));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_verifyContextCrc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_verifyContextCrc(mcuxClSession_Handle_t session, void* pCtx, uint32_t contextSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_verifyContextCrc);

    /* Assert context at least contains the crc value */
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(contextSize, 4u, UINT32_MAX);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    uint32_t *pContext = (uint32_t *)pCtx;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC32(MCUXCLCRC_DEFAULT_POLY_32,
                                                                MCUXCLCRC_DEFAULT_SEED_32,
                                                                MCUXCLCRC_DRV_READ_TRANSPOSE_BYTES_NO_BITS  |
                                                                MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS |
                                                                MCUXCLCRC_DRV_BIT_COMPLEMENT_RESULT));

    uint32_t * pContextEnd = pContext + (contextSize / sizeof(uint32_t));
    MCUX_CSSL_DI_RECORD( crcLoop, pContextEnd);

    pContext++; /* skip place for the CRC */
    while( pContext < pContextEnd)
    {
        mcuxClCrc_Drv_writeData32bit(*pContext++);
    }

    if( *(uint32_t *)pCtx != mcuxClCrc_Sfr_readData())
    {
        MCUXCLSESSION_FAULT(session, MCUXCLCRC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_DI_EXPUNGE(crcLoop, pContext);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCrc_verifyContextCrc,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC32));
}
