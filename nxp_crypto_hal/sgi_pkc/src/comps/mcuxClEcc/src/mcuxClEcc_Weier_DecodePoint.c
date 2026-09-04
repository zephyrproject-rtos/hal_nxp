/*--------------------------------------------------------------------------*/
/* Copyright 2022, 2024-2025 NXP                                            */
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
 * @file  mcuxClEcc_Weier_DecodePoint.c
 * @brief ECC Weierstrass point decoding function
 */


#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>

#include <internal/mcuxClSession_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_WeierECC_DecodePoint)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_WeierECC_DecodePoint(
    mcuxClSession_Handle_t pSession,
    mcuxCl_InputBuffer_t pEncodedPoint,
    mcuxCl_Buffer_t pDecodedPoint,
    mcuxClEcc_WeierECC_PointEncType_t pointEncType,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClEcc_WeierECC_DecodePoint, diRefValue, MCUXCLECC_STATUS_FAULT_ATTACK);

    /* Call point decoding function specified by the point encoding type descriptor. */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_PointDecFct,
        pointEncType->pointDecFct(pSession,
                                  pEncodedPoint,
                                  pDecodedPoint,
                                  pointEncType,
                                  pEccWeierDomainParams));

    MCUXCLSESSION_EXIT(pSession, mcuxClEcc_WeierECC_DecodePoint, diRefValue, ret_PointDecFct, MCUXCLECC_STATUS_FAULT_ATTACK,
        pointEncType->pointDecFctFPId);
}
