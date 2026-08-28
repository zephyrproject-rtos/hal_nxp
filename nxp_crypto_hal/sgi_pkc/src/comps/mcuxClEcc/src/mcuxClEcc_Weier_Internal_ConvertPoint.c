/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_ConvertPoint.c
 * @brief Weierstrass curve internal point conversion
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClPrng_Internal_Functions.h>

/**
 * This function securely converts a point from Jacobian to affine coordinates.
 *
 * Inputs in PKC workarea:
 *   buffers (X0,Y0,Z) contain the point, Jacobian, Montgomery representation.
 *
 * Result in PKC workarea:
 *   buffer (XA,YA), contain the point, affine, normal representation.
 *
 * Modifications in PKC workarea:
 *   buffers ECC_T1, ECC_T3 are used as temporary storage during ModInv operation.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_SecureConvertPoint_JacToAffine)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_SecureConvertPoint_JacToAffine(mcuxClSession_Handle_t pSession)

{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_SecureConvertPoint_JacToAffine);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();

    /* T0 = ModInv(Z), where Z = (z * 256^LEN) \equiv z in MR. */
    MCUXCLECC_FP_MODINV(pSession, ECC_T0, WEIER_Z, ECC_P, ECC_T1, ECC_T3);
    /* T0 = z^(-1) * 256^(-LEN) \equiv z^(-1) * 256^(-2LEN) in MR. */

    uint8_t * const ptrRnd = MCUXCLPKC_OFFSET2PTR(pOperands[WEIER_YA]);
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(ptrRnd, operandSize));

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_SecureConvertPoint_JacToAffine,
                        mcuxClEcc_FUP_Weier_SecureConvertPoint_JacToAffine_LEN);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_Weier_SecureConvertPoint_JacToAffine,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ModInv),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
}
