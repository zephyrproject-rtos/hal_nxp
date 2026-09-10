/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal_PrecPointImportAndValidate.c
 * @brief Function to import, convert and validate the coordinates of a pre-computed point
 */

#include <mcuxClToolchain.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>


/**
 * This function imports the affine coordinates (x,y) of a pre-computed point to the PKC workarea,
 * converts them to extended affine coordinates (x:y:1:t) in MR and in range [0,p-1] and verifies
 * that the point lies on the curve.
 *
 * Input:
 *  - pSession  Handle for the current CL session
 *  - iDst      Pointer table index of buffer to which the x-coordinate shall be copied
 *  - pSrc      Pointer to the pre-computed point x-coordinate
 *
 * Prerequisites:
 *  - The coordinates x and y are stored in MR (in LE format) concatenated at address pSrc
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers ECC_CP0 and ECC_CP1 contain the curve parameters a and d in MR
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - Buffers buf(iDst), buf(iDst+1) and buf(iDst+2) contain the coordinates x, y and t in MR
 *
 * Return values:
 *  - MCUXCLECC_STATUS_OK            if the function executed successfully
 *  - MCUXCLECC_STATUS_FAULT_ATTACK  if the point validation failed
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_PrecPointImportAndValidate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_TwEd_PrecPointImportAndValidate(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    uint8_t iDst,
    uint8_t *pSrc,
    uint16_t byteLenP
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_PrecPointImportAndValidate);

    /* Step 1: Copy the coordinates x and y to the buffers buf(iDst) and buf(iDst+1). */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUXCLPKC_WAITFORFINISH();
    MCUXCLMEMORY_FP_MEMORY_COPY(MCUXCLPKC_OFFSET2PTR(pOperands[iDst]), pSrc, byteLenP);
    MCUXCLMEMORY_FP_MEMORY_COPY(MCUXCLPKC_OFFSET2PTR(pOperands[iDst+1u]), pSrc+byteLenP, byteLenP);

    /* Step 2: Let pointer table pointers corresponding to TWED_V0, TWED_V1 and TWED_V2 point to buf(iDst), buf(iDst+1) and buf(iDst+2). */
    pOperands[TWED_V0] = (uint16_t) pOperands[iDst];
    pOperands[TWED_V1] = (uint16_t) pOperands[iDst+1u];
    pOperands[TWED_V2] = (uint16_t) pOperands[iDst+2u];

    /* Step 3: Validate the coordinates by checking the curve equation a*x2 + y2 = 1 + d*x2*y2: */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_PointValidation_AffineNR, mcuxClEcc_FUP_TwEd_PointValidation_AffineNR_Len);

    /* Step 4: If the ZERO flag of the PKC is not set, return #MCUXCLECC_STATUS_FAULT_ATTACK. Otherwise, return #MCUXCLECC_STATUS_OK. */
    if (MCUXCLPKC_FLAG_ZERO != MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_TwEd_PrecPointImportAndValidate, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_TwEd_PrecPointImportAndValidate, MCUXCLECC_STATUS_OK,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup)
        );
    }
}
