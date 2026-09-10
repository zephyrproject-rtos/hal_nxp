/*--------------------------------------------------------------------------*/
/* Copyright 2018-2024 NXP                                                  */
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

/** @file  mcuxClOsccaSm2_Encrypt.c
 *  @brief mcuxClOsccaSm2: implementation of SM2 Encrypt function
 */

#include <mcuxClMemory.h>
#include <mcuxClHash.h>
#include <mcuxClSession.h>
#include <mcuxClOsccaSm2.h>
#include <mcuxClOsccaSm3.h>
#include <mcuxClOsccaPkc.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaSm2_Internal.h>
#include <internal/mcuxClOsccaSm2_Internal_Hash.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClOsccaPkc_Macros.h>
#include <internal/mcuxClOsccaPkc_Operations.h>
#include <internal/mcuxClOsccaPkc_FupMacros.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm2_Encrypt, mcuxClOsccaSm2_EncEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Encrypt(mcuxClSession_Handle_t session, mcuxClOsccaSm2_Encrypt_Param_t *pParams)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm2_Encrypt);

    MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_ALIGNED_TYPE()
    mcuxClOsccaSm2_Internal_EncDecCtx_t* pCtx = (mcuxClOsccaSm2_Internal_EncDecCtx_t*)pParams->pEncDecCtx;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_ALIGNED_TYPE()

    /*Check the correctness of the state option: Options 0 and "INIT | FINALIZE" are not supported.*/
    uint16_t stateOption = (pParams->options & MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_MASK);
    if ((0u == stateOption)  || ((MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_INIT | MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_FINALIZE) == stateOption))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_Encrypt,MCUXCLOSCCASM2_STATUS_FAULT_ATTACK);
    }

    MCUXCLOSCCASM2_FP_REQUEST_PKC(session, mcuxClOsccaSm2_Encrypt);

    if (MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_INIT == (pParams->options & MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_INIT))
    {
        MCUX_CSSL_FP_FUNCTION_CALL(encInitRet,  mcuxClOsccaSm2_Encrypt_Internal_Init(session, pParams));
        if (MCUXCLOSCCASM2_STATUS_ENCRYPT_OK != encInitRet)
        {
            MCUXCLOSCCASM2_FP_RELEASE_PKC(session, mcuxClOsccaSm2_Encrypt);
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_Encrypt, encInitRet,
                                       MCUXCLOSCCASM2_FP_CALLED_REQUEST_PKC,
                                       MCUXCLOSCCASM2_FP_CALLED_RELEASE_PKC,
                                       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm2_Encrypt_Internal_Init));
        }
    }
    else
    {
        /*Crc check over the EncDecCtx has to be done after each call excluding INIT*/
        MCUX_CSSL_FP_FUNCTION_CALL(SM2EncryptRet2, mcuxClOsccaSm2_ValidateEncDecCtx(
                MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("Reinterpret the external parameter to internal context structure.")
                pCtx,
                MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
                (uint32_t)pParams->domainParameters.p.wNumBytes));
        if (MCUXCLOSCCASM2_STATUS_VALIDATE_ENCDEC_CTX_OK != SM2EncryptRet2)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_Encrypt, MCUXCLOSCCASM2_STATUS_FAULT_ATTACK);
        }
    }

    if (MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_UPDATE == (pParams->options & MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_UPDATE))
    {
        /*Perform whole Update phase - functionality extracted as similiarity between encrypt and decrypt functions exist*/
        MCUX_CSSL_FP_FUNCTION_CALL(SM2EncryptRet3, mcuxClOsccaSm2_EncDec_UpdatePhase(
            session,
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("reinterpret the API strcture type to internal structure type.")
            (mcuxClOsccaSm2_EncDec_Common_Param_t *)pParams,
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
            MCUXCLOSCCASM2_ENCRYPT));
        if (MCUXCLOSCCASM2_STATUS_ENCDEC_PHASE_OK != SM2EncryptRet3)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_Encrypt, MCUXCLOSCCASM2_STATUS_FAULT_ATTACK);
        }
    }

    MCUX_CSSL_FP_FUNCTION_CALL(encfinalRet,  mcuxClOsccaSm2_Encrypt_Internal_Final(session, pParams));

    MCUXCLOSCCASM2_FP_RELEASE_PKC(session, mcuxClOsccaSm2_Encrypt);

    /* Balance security counter */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_Encrypt, encfinalRet,
                                                      MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_INIT == (pParams->options & MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_INIT) ?
                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm2_Encrypt_Internal_Init) : MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm2_ValidateEncDecCtx),
                                                      MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_UPDATE == (pParams->options & MCUXCLOSCCASM2_OPT_ENC_DEC_STATE_UPDATE) ?
                    MCUXCLOSCCASM2_SECURITYCOUNTER_VAL_ENCDEC_BALANCE_UPDATE_PART : 0u,
                                                      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm2_Encrypt_Internal_Final),
                                                      MCUXCLOSCCASM2_FP_CALLED_REQUEST_PKC,
                                                      MCUXCLOSCCASM2_FP_CALLED_RELEASE_PKC);
}
