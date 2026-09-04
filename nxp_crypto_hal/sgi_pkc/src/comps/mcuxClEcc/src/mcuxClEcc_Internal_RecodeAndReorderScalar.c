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

/**
 * @file  mcuxClEcc_Internal_RecodeAndReorderScalar.c
 * @brief mcuxClEcc: implementation of mcuxClEcc_RecodeAndReorderScalar
 */

#include <mcuxClToolchain.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_UPTRT_access.h>
#include <internal/mcuxClEcc_Internal_FUP.h>


/**
 * This function recodes an odd, potentially secret, scalar lambda = (lambda_{f*K-1},...,lambda_0)_2 of (not necessarily exact) bit length f*K,
 * into non-zero BSD representation by rotating it right by one bit to obtain
 *
 *      lambda~ = (lambda~_{f*K-1},...,lambda~_0)_2 = (lambda_{f*K-1},...,lambda_0)_2.
 *
 * Further, it reorders the bits of lambda~ for usage within the comb method by splitting it into f parts and interleaving them to obtain
 *
 *      lambda' = (lambda~_{f*K-1}, lambda~_{(f-1)*K-1},...,lambda~_{K-1},...,lambda~_{(f-1)*K},lambda~_{(f-2)*K},...,lambda~_0)_2
 *
 * Input:
 *   - pSession         Handle for the current CL session
 *   - scalarIndex      Table index of buffer storing the scalar lambda to be blinded
 *   - f                Number of parts into which the scalar will be divided; must be a power of two
 *   - scalarBitLength  scalar length in bits, must be a multiple of f.
 *
 * Prerequisites:
 *   - ps1Len = (operandSize, operandSize)
 *
 * Result:
 *   - The recoded and reordered scalar lambda' is contained in the buffer with table index scalarIndex.
 *
 * Other modifications:
 *   - Buffers ECC_T0 and ECC_T1 are modified (as temp).
 *   - Offsets pOperands[ECC_V0/ECC_V1/ECC_V3] are modified.
 *   - ps2 LEN and MCLEN are modified.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_RecodeAndReorderScalar)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_RecodeAndReorderScalar(mcuxClSession_Handle_t pSession UNUSED_PARAM,
                                                                        uint8_t scalarIndex,
                                                                        uint8_t f,
                                                                        uint32_t scalarBitLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_RecodeAndReorderScalar);

    /* Step 1:
     * Set the pointer in ECC_V0 to the buffer corresponding to scalarIndex.
     */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUXCLPKC_WAITFORREADY();
    pOperands[ECC_V0] = pOperands[scalarIndex];

    /* Step 2:
     * Use PKC to rotate the buffer ECC_V0 to the right by one bit.
     */
    MCUXCLPKC_FP_CALC_OP1_ROTR(ECC_V0, ECC_V0, 1u);

    /* Step 3:
     * Use the PKC to move the MSBit of the buffer to bit position f*K-1 of the buffer ECC_V0. The buffer now contains lambda~.
     */
    // TODO: Moving the MSBit still to be done (but not necessary for Ed25519 and Ed448 with f = 4) -> CLNS-6486

    /* Step 4:
     * Successively ( log_2(f) times ) do the following:
     *   - Shift upper half of the f*K bit value in ECC_V0 to the next PKC word boundary
     *   - Use PKC to square lower and upper half of the value in ECC_V0 and store the results in ECC_T0 and ECC_T1, respectively
     *   - Left shift ECC_T1 by one bit
     *   - Set ECC_V0 = ECC_T0 | ECC_T1
     *
     * This is all done by mcuxClEcc_InterleaveScalar.
     */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("the result does not wrap, because the return vaule of mcuxClMath_CountLeadingZerosWord is in the range [0,31].")
    uint32_t fLog = 32u - mcuxClMath_CountLeadingZerosWord((uint32_t) f) - 1u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_InterleaveScalar(scalarIndex, scalarBitLength, fLog));

    /* Step 5:
     * Complete pkc operations
     */
    MCUXCLPKC_WAITFORREADY();

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_RecodeAndReorderScalar,
        MCUXCLPKC_FP_CALLED_CALC_OP1_ROTR,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_InterleaveScalar));
}
