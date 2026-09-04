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
 * @file  mcuxClEcc_ArithmeticOperation_PointAdd.c
 * @brief implementation of mcuxClEcc_ArithOp_PointAdd function
 */


#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal.h>


/* Arithmetic operation descriptor for point addition on Weierstrass curves */
const mcuxClEcc_ArithmeticOperationDescriptor_t mcuxClEcc_ArithOpDesc_PointAdd =
{
  .arithOpFct = mcuxClEcc_ArithOp_PointAdd,
  .arithOpFct_FP_FuncId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithOp_PointAdd)
};


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ArithOp_PointAdd, mcuxClEcc_ArithmeticOperationFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ArithOp_PointAdd(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_Weier_DomainParams_t *pEccWeierDomainParams,
    mcuxCl_InputBuffer_t pOp1,
    uint32_t op1Size,
    mcuxCl_InputBuffer_t pOp2,
    uint32_t op2Size,
    mcuxCl_Buffer_t pResult,
    uint32_t * const pResultSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ArithOp_PointAdd);

    MCUX_CSSL_FP_FUNCTION_CALL(ret_PointAddSubFct,
       mcuxClEcc_ArithOp_PointAddSub(pSession,
                                    pEccWeierDomainParams,
                                    pOp1,
                                    op1Size,
                                    pOp2,
                                    op2Size,
                                    pResult,
                                    pResultSize,
                                    mcuxClEcc_ArithOp_PointAdd));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_ArithOp_PointAdd, ret_PointAddSubFct,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ArithOp_PointAddSub));
}

