/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClMath_Internal_Functions.h
 * @brief Internal APIs of mcuxClMath component
 */


#ifndef MCUXCLMATH_INTERNAL_FUNCTIONS_H_
#define MCUXCLMATH_INTERNAL_FUNCTIONS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>

#include <mcuxClSession.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClMath_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClMath_Internal_Functions mcuxClMath_Internal_Functions
 * @brief Defines all functions of @ref mcuxClMath
 * @ingroup mcuxClMath
 * @{
 */


/**
 * @brief Initializes and uses the new UPTRT and returns the address of original UPTRT.
 *
 * This function copies up to 8 offsets of PKC operands from current UPTRT to the new UPTRT,
 * sets PKC to use the new UPTRT, and returns the address of original UPTRT.
 *
 * @param[in]     i3_i2_i1_i0    the first 4 indices of offsets to be copied
 * @param[in]     i7_i6_i5_i4    the second 4 indices of offsets to be copied
 * @param[in,out] localPtrUptrt  address of the new UPTRT to be filled
 * @param         noOfIndices    number of offsets to be copied from original UPTRT to new UPTRT
 * @param[out]    oldPtrUptrt    pointer to where receives the original UPTRT address
 *
 * @pre
 *  - This function will retrieve the original UPTRT address and return it to caller via @p oldPtrUptrt.
 *    This function will overwrite this address by @p localPtrUptrt.
 *  - @p localPtrUptrt shall be 2-byte aligned.
 *    Caller shall allocate at least @p noOfIndices 2-byte entries in this table.
 *  - This function shall not be called during a running FUP program (i.e., GOANY bit is set).
 *    Caller shall call #MCUXCLPKC_WAITFORREADY before calling this function, if a FUP program has been called.
 *
 * @post
 *  - @p i0 (bits 0~7):   originalUptrt[i0] will be copied to @p localPtrUptrt[0], if @p noOfIndices >= 1.
 *  - @p i1 (bits 8~15):  originalUptrt[i1] will be copied to @p localPtrUptrt[1], if @p noOfIndices >= 2.
 *  - @p i2 (bits 16~23): originalUptrt[i2] will be copied to @p localPtrUptrt[2], if @p noOfIndices >= 3.
 *  - @p i3 (bits 24~31): originalUptrt[i3] will be copied to @p localPtrUptrt[3], if @p noOfIndices >= 4.
 *  - @p i4 (bits 0~7):   originalUptrt[i4] will be copied to @p localPtrUptrt[4], if @p noOfIndices >= 5.
 *  - @p i5 (bits 8~15):  originalUptrt[i5] will be copied to @p localPtrUptrt[5], if @p noOfIndices >= 6.
 *  - @p i6 (bits 16~23): originalUptrt[i6] will be copied to @p localPtrUptrt[6], if @p noOfIndices >= 7.
 *  - @p i7 (bits 24~31): originalUptrt[i7] will be copied to @p localPtrUptrt[7], if @p noOfIndices >= 8.
 *  - This function will overwrite the UPTRT address with @p localPtrUptrt.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_InitLocalUptrt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_InitLocalUptrt(
    uint32_t i3_i2_i1_i0,
    uint32_t i7_i6_i5_i4,
    uint16_t *localPtrUptrt,
    uint8_t noOfIndices,
    const uint16_t **oldPtrUptrt
    );


/**
 * @brief Counts number of leading zero bits of a PKC operand.
 *
 * This function counts the number of leading zero bits of a PKC operand
 * at offset UPTRT[iX] and of size PS1 OPLEN.
 *
 * @param[in]  iX              index of PKC operand
 *
 * @pre
 *  - @p iX is the index of X (PKC operand), size = operandSize.
 *    The offset (UPTRT[iX]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *  - This function will not use PKC, and assumes PKC will not modify the operand iX simultaneously.
 *  - PKC PS1 OPLEN defines operandSize and shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval numLeadingZeroes    Number of leading zeroes
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_LeadingZeros)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClMath_LeadingZeros(
    uint8_t iX
    );


/**
 * @brief Counts number of trailing zero bits of a PKC operand.
 *
 * This function counts the number of trailing zero bits of a PKC operand
 * at offset UPTRT[iX] and of size PS1 OPLEN.
 *
 * @param[in]  iX               index of PKC operand
 *
 * @pre
 * - @p iX is the index of X (PKC operand), size = operandSize.
 *   The offset (UPTRT[iX]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 * - This function will not use PKC, and assumes PKC will not modify the operand iX simultaneously.
 * - PKC PS1 OPLEN defines operandSize and shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval numTrailingZeroes    Number of trailing zeroes
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_TrailingZeros)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClMath_TrailingZeros(
    uint8_t iX
    );


/**
 * @brief Prepares shifted modulus
 *
 * This function left shifts modulus (PKC operand iN) until there is no leading zero
 * and stores the result in PKC operand iNShifted.
 *
 * @param[out,in] iNShifted_iN  indices of PKC operands
 *
 * @pre
 *  - @p iN        (bits 0~7): index of modulus (PKC operand), size = operandSize.
 *                 The modulus shall be non-zero.
 *                 The offset (UPTRT[iN]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *  - @p iNShifted (bits 8~15): index of shifted modulus (PKC operand), size = operandSize.
 *                 This function supports in-place operation, i.e., iNShifted = iN.
 *  - PKC PS1 OPLEN defines operandSize and shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 * @post
 *  - PKC PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ShiftModulus)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ShiftModulus(
    uint16_t iNShifted_iN
    );
/** Helper macro for #mcuxClMath_ShiftModulus. */
#define MCUXCLMATH_SHIFTMODULUS(iNShifted, iN)  \
    mcuxClMath_ShiftModulus(MCUXCLPKC_PACKARGS2(iNShifted, iN))
/** Helper macro for #mcuxClMath_ShiftModulus with flow protection. */
#define MCUXCLMATH_FP_SHIFTMODULUS(iNShifted, iN)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_SHIFTMODULUS(iNShifted, iN))


/**
 * @brief Prepares modulus (calculates NDash) for PKC modular multiplication.
 *
 * This function calculates NDash = (-modulus)^(-1) mod 256^(MCUXCLPKC_WORDSIZE)
 * and stores NDash in the PKC word in front of the PKC operand of modulus (iN).
 *
 * @param[in]     pSession  handle for the current CL session
 * @param[in,tmp] iN_iT     indices of PKC operands
 *
 * @pre
 *  - @p iT (bits 0~7): index of temp (PKC operand).
 *          The size of temp shall be at least (2 * MCUXCLPKC_WORDSIZE).
 *  - @p iN (bits 8~15): index of modulus (PKC operand).
 *          The modulus shall be an odd number.
 *          The result NDash will be stored in the PKC word before modulus,
 *            i.e., at the offset, (UPTRT[iN] - MCUXCLPKC_WORDSIZE).
 *
 * @post
 *  - PKC PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_NDash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_NDash(
    mcuxClSession_Handle_t pSession,
    uint16_t iN_iT
    );
/** Helper macro for #mcuxClMath_NDash. */
#define MCUXCLMATH_NDASH(pSession, iN, iT)  \
    mcuxClMath_NDash(pSession, MCUXCLPKC_PACKARGS2(iN, iT))
/** Helper macro for #mcuxClMath_NDash with flow protection. */
#define MCUXCLMATH_FP_NDASH(pSession, iN, iT)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_NDASH(pSession, iN, iT))


/**
 * @brief Calculates QDash = Q * Q' mod n, where Q = 256^(operandSize) mod n, and Q' = 256^length mod n.
 *
 * This function computes QDash which can be used to convert a PKC operand
 * (of the size @p length) to its Montgomery representation (of the size operandSize).
 *
 * @param[in]            pSession                handle for the current CL session
 * @param[out,in,in,tmp] iQDash_iNShifted_iN_iT  indices of PKC operands
 * @param                length                  specify Q' = 256^length mod n
 *
 * @pre
 * - @p iT        (bits 0~7): index of temp (PKC operand).
 *                The size of temp shall be at least (operandSize + MCUXCLPKC_WORDSIZE).
 * - @p iN        (bits 8~15): index of modulus (PKC operand), size = operandSize.
 *                NDash of modulus shall be stored in the PKC word before modulus.
 * - @p iNShifted (bits 16~23): index of shifted modulus (PKC operand), size = operandSize.
 *                If there is no leading zero in the PKC operand modulus, it can be iN.
 * - @p iQDash    (bits 24~31): index of result QDash (PKC operand), size = operandSize.
 *                QDash might be greater than modulus.
 * - @p length shall be nonzero. A zero length will cause undefined behavior.
 * - PKC PS1 OPLEN = MCLEN defines operandSize.
 *
 * @post
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_QDash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_QDash(
    mcuxClSession_Handle_t pSession,
    uint32_t iQDash_iNShifted_iN_iT,
    uint16_t length
    );
/** Helper macro for #mcuxClMath_QDash. */
#define MCUXCLMATH_QDASH(pSession, iQDash, iNShifted, iN, iT, len)  \
    mcuxClMath_QDash(pSession, MCUXCLPKC_PACKARGS4(iQDash, iNShifted, iN, iT), len)
/** Helper macro for #mcuxClMath_QDash with flow protection. */
#define MCUXCLMATH_FP_QDASH(pSession, iQDash, iNShifted, iN, iT, len)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_QDASH(pSession, iQDash, iNShifted, iN, iT, len))


/**
 * @brief Calculates QSquared = Q^2 mod n, where Q = 256^(operandSize) mod n.
 *
 * This function computes QSquared which can be used to convert a PKC operand
 * to its Montgomery representation (both are of the size operandSize).
 *
 * @param[in]            pSession               handle for the current CL session
 * @param[out,in,in,tmp] iQSqr_iNShifted_iN_iT  indices of PKC operands
 *
 * @pre
 *  - @p iT        (bits 0~7): index of temp (PKC operand).
 *                 The size of temp shall be at least (operandSize + MCUXCLPKC_WORDSIZE).
 *  - @p iN        (bits 8~15): index of modulus (PKC operand), size = operandSize.
 *                 NDash of modulus shall be stored in the PKC word before modulus.
 *  - @p iNShifted (bits 16~23): index of shifted modulus (PKC operand), size = operandSize.
 *                 If there is no leading zero in the PKC operand modulus, it can be iN.
 *  - @p iQSqr     (bits 24~31): index of result QSquared (PKC operand), size = operandSize.
 *                 QSquared might be greater than modulus.
 *  - PKC PS1 OPLEN = MCLEN defines operandSize and shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @post
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_QSquared)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_QSquared(
    mcuxClSession_Handle_t pSession,
    uint32_t iQSqr_iNShifted_iN_iT
    );
/** Helper macro for #mcuxClMath_QSquared. */
#define MCUXCLMATH_QSQUARED(pSession, iQSqr, iNShifted, iN, iT)  \
    mcuxClMath_QSquared(pSession, MCUXCLPKC_PACKARGS4(iQSqr, iNShifted, iN, iT))
/** Helper macro for #mcuxClMath_QSquared with flow protection. */
#define MCUXCLMATH_FP_QSQUARED(pSession, iQSqr, iNShifted, iN, iT)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_QSQUARED(pSession, iQSqr, iNShifted, iN, iT))


/**
 * @brief Calculates modular inversion, with odd modulus
 *
 * This function calculates modular inversion, result = X^(-1) mod n.
 *
 * @param[in]            pSession     handle for the current CL session
 * @param[out,in,in,tmp] iR_iX_iN_iT  indices of PKC operands
 * @param[in]            flagCoprime  coprime flag
 *
 * @pre
 *  - @p iT (bits 0~7): index of temp (PKC operand).
 *          Its size shall be at least (operandSize + MCUXCLPKC_WORDSIZE).
 *          The offset (UPTRT[iT]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *  - @p iN (bits 8~15): index of modulus (PKC operand), size = operandSize.
 *          NDash of modulus shall be stored in the PKC word before modulus.
 *  - @p iX (bits 16~23): index of X (PKC operand), size = operandSize.
 *          If X and N are coprime size = operandSize, otherwise size = (operandSize + MCUXCLPKC_WORDSIZE).
 *          X will be destroyed by this function.
 *  - @p iR (bits 24~31): index of result (PKC operand).
 *          Its size shall be at least (operandSize + MCUXCLPKC_WORDSIZE).
 *          The offset (UPTRT[iR]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *          The result fits in operandSize, but might be greater than modulus.
 *  - @p flagCoprime indicates if X and N are coprime: MCUXCLMATH_XN_COPRIME if that is the case, otherwise MCUXCLMATH_XN_NOT_COPRIME.
 *  - PKC PS1 OPLEN = MCLEN defines operandSize.
 *
 * @post
 *  - PKC PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ModInv)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ModInv(
    mcuxClSession_Handle_t pSession, uint32_t iR_iX_iN_iT, uint32_t flagCoprime
    );
/** Helper macro for #mcuxClMath_ModInv. X and N should be coprime. */
#define MCUXCLMATH_MODINV(pSession, iR, iX, iN, iT)  \
    mcuxClMath_ModInv(pSession, MCUXCLPKC_PACKARGS4(iR, iX, iN, iT), MCUXCLMATH_XN_COPRIME)
/** Helper macro for #mcuxClMath_ModInv with flow protection. X and N should be coprime. */
#define MCUXCLMATH_FP_MODINV(pSession, iR, iX, iN, iT)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_MODINV(pSession, iR, iX, iN, iT))


/**
 * @brief Calculates modular reduction with even modulus
 *
 * This function calculates modular reduction result = X mod n, where the modulus n is even.
 *
 * @param[in]              pSession      handle for the current CL session
 * @param[out,in,in,tmp]   iR_iX_iN_iT0  indices of PKC operands
 * @param[tmp,tmp,tmp,tmp] iT1_iT2_iT3   indices of PKC operands
 *
 * @pre
 *  - @p iT0 (bits 0~7 of iR_iX_iN_iT0): index of temp0 (PKC operand).
 *           Its size shall be at least (lenN + MCUXCLPKC_WORDSIZE).
 *           The operand of modulus can be used as temp0 (i.e., iT0 = iN), but the modulus will be destroyed.
 *  - @p iN  (bits 8~15 of iR_iX_iN_iT0): index of modulus (PKC operand), size = lenN.
 *           The offset (UPTRT[iN]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *  - @p iX  (bits 16~23 of iR_iX_iN_iT0): index of X (PKC operand). Its size shall be at least (lenX + MCUXCLPKC_WORDSIZE).
 *  - @p iR  (bits 24~31 of iR_iX_iN_iT0): index of result (PKC operand). Its size shall be at least (lenN + MCUXCLPKC_WORDSIZE).
 *  - @p iT3 (bits 0~7 of iT1_iT2_iT3): index of temp3 (PKC operand). Its size shall be at least (lenN + MCUXCLPKC_WORDSIZE).
 *  - @p iT2 (bits 8~15 of iT1_iT2_iT3): index of temp2 (PKC operand). Its size shall be at least lenN.
 *  - @p iT1 (bits 16~23 of iT1_iT2_iT3): index of temp1 (PKC operand). Its size shall be at least lenN.
 *           The operand iR of result can be used as temp1 (i.e., iT1 = iR).
 *  - PKC PS1 OPLEN defines lenN (length of modulus n), and MCLEN defines lenX (length of X).
 *    lenX (PS1 MCLEN) >= lenN (PS1 OPLEN). Both OPLEN and MCLEN shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @post
 *  - PKC PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ReduceModEven)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ReduceModEven(
    mcuxClSession_Handle_t pSession,
    uint32_t iR_iX_iN_iT0,
    uint32_t iT1_iT2_iT3
    );
/** Helper macro for #mcuxClMath_ReduceModEven. */
#define MCUXCLMATH_REDUCEMODEVEN(pSession, iR, iX, iN, iT0, iT1, iT2, iT3)  \
    mcuxClMath_ReduceModEven(pSession, MCUXCLPKC_PACKARGS4(iR, iX, iN, iT0), MCUXCLPKC_PACKARGS4(0u, iT1, iT2, iT3))
/** Helper macro for #mcuxClMath_ReduceModEven with flow protection. */
#define MCUXCLMATH_FP_REDUCEMODEVEN(pSession, iR, iX, iN, iT0, iT1, iT2, iT3)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_REDUCEMODEVEN(pSession, iR, iX, iN, iT0, iT1, iT2, iT3))


/**
 * @brief Calculates modular exponentiation.
 *
 * This function calculates modular exponentiation with left-to-right binary
 * square-and-multiply algorithm.
 *
 * @param[in]            pExp           pointer to exponent
 * @param                expByteLength  byte length of exponent
 * @param[out,in,in,tmp] iR_iX_iN_iT    indices of PKC operands
 *
 * @pre
 *  - @p pExp the exponent is a big-endian octet string and shall be non-zero.
 *  - @p iT (bits 0~7): index of temp operand (PKC operand). Its size shall be at least (lenN + MCUXCLPKC_WORDSIZE).
 *  - @p iN (bits 8~15): index of modulus (PKC operand), size = operandSize.
 *          NDash of modulus shall be stored in the PKC word before modulus.
 *  - @p iX (bits 16~23): index of base number (PKC operand), size = operandSize.
 *  - @p iR (bits 24~31): index of result (PKC operand). Its size shall be at least (lenN + MCUXCLPKC_WORDSIZE).
 *  - PKC PS1 OPLEN = MCLEN defines operandSize.
 *
 * @post
 *  - Data Integrity: Expunge(expByteLength + pExp)
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ModExp_SqrMultL2R)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ModExp_SqrMultL2R(
    const uint8_t *pExp,
    uint32_t expByteLength,
    uint32_t iR_iX_iN_iT
    );
/** Helper macro for #mcuxClMath_ModExp_SqrMultL2R. */
#define MCUXCLMATH_MODEXP_SQRMULTL2R(pExp, byteLenExp, iR, iX, iN, iT)  \
    mcuxClMath_ModExp_SqrMultL2R(pExp, byteLenExp, MCUXCLPKC_PACKARGS4(iR, iX, iN, iT))
/** Helper macro for #mcuxClMath_ModExp_SqrMultL2R with flow protection. */
#define MCUXCLMATH_FP_MODEXP_SQRMULTL2R(pExp, byteLenExp, iR, iX, iN, iT)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_MODEXP_SQRMULTL2R(pExp, byteLenExp, iR, iX, iN, iT))


/**
 * @brief Securely calculates modular exponentiation.
 *
 * This function calculates modular exponentiation in a secure manner.
 * It randomizes the computation by Euclidean splitting: exponent = b * q + r,
 * where b is a 64-bit odd random number (with both MSbit and LSbit set), and
 * r = exponent % b. The exponentiation is calculated by two steps:
 * (1) m0 = m^q mod n; and (2) result = m0^b * m^r mod n.
 * In addition, base operands are re-randomized, by adding random multiples of the
 * modulus to them before performing modular multiplications.
 *
 * @param[in]                pSession        handle for the current CL session.
 * @param[in]                pExpTemp        pointer to temporary buffer
 * @param                    expByteLength   byte length of exponent
 * @param[tmp,in,tmp,tmp]    iT3_iX_iT2_iT1  indices of PKC operands
 * @param[in,tmp,tmp,in/out] iN_iTE_iT0_iR   indices of PKC operands
 *
 * @pre
 *  - This function uses PRNG which has to be initialized prior to calling the function.
 *  - @p session: The session pointed to by pSession has to be initialized prior to a call to this function.
 *  - @p pExpTemp: the temporary buffer can be in either CPU or PKC workarea:
 *    - If it is in CPU workarea: It shall be CPU word aligned, and its length shall be a multiple of CPU word
 *      and greater than @p expByteLength.
 *    - If it is in PKC workarea: It shall be PKC word aligned, and its length shall be
 *      MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(expByteLength + 1u)
 *  - @p iT1 (bits 0~7 of iT3_iX_iT2_iT1): index of temp1 (PKC operand). Its size shall be
 *           at least max(MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(@p expByteLength + 1), lenN + MCUXCLPKC_WORDSIZE, 2 * MCUXCLPKC_WORDSIZE).
 *  - @p iT2 (bits 8~15 of iT3_iX_iT2_iT1): index of temp2 (PKC operand). Its size shall be
 *           at least max(lenN + MCUXCLPKC_WORDSIZE, 2 * MCUXCLPKC_WORDSIZE).
 *  - @p iX  (bits 16~23 of iT3_iX_iT2_iT1): index of base number (PKC operand). Its size shall be
 *           at least operandSize + MCUXCLPKC_WORDSIZE (= lenN + MCUXCLPKC_WORDSIZE).
 *           It will be overwritten.
 *  - @p iT3 (bits 24~31 of iT3_iX_iT2_iT1): index of temp3 (PKC operand). Its size shall be
 *           at least max(lenN + MCUXCLPKC_WORDSIZE, 2 * MCUXCLPKC_WORDSIZE).
 *  - @p iR  (bits 0~7 of iN_iTE_iT0_iR): index of result, and of the secret exponent in PKC RAM (PKC operand).
 *           The size shall be at least max(MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(@p expByteLength + 1), lenN + MCUXCLPKC_WORDSIZE).
 *           This PKC buffer shall already contain the exponent in little Endian. The exponent shall be non-zero.
 *  - @p iT0 (bits 8~15 of iN_iTE_iT0_iR): index of temp0 (PKC operand). The size shall be
 *           at least max(MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(@p expByteLength + 1), lenN + MCUXCLPKC_WORDSIZE).
 *  - @p iTE (bits 16~23 of iN_iTE_iT0_iR): index of temp4 (PKC operand).
 *           The size shall be at least (6 * MCUXCLPKC_WORDSIZE).
 *  - @p iN  (bits 24~31 of iN_iTE_iT0_iR): index of modulus (PKC operand), size = operandSize (= lenN).
 *           The upper 32 bits of N shall be null, which can be obtained for instance by applying 32-bit modulus blinding,
 *           or by artificially increasing PS1 lengths and all buffer sizes by 1 PKC word.
 *           NDash of modulus shall be stored in the PKC word before modulus.
 *  - PKC PS1 OPLEN = MCLEN defines operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(lenN), where lenN
 *      is the length of modulus n. As the upper 32 bits of N should be null, operandSize >= lenN + 4 bytes.
 *
 * @post
 *  - Data Integrity: Expunge(expByteLength)
 *  - PKC PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_SecModExp)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_SecModExp(
    mcuxClSession_Handle_t session,
    uint32_t *pExpTemp,
    uint32_t expByteLength,
    uint32_t iT3_iX_iT2_iT1,
    uint32_t iN_iTE_iT0_iR
    );
/** Helper macro for #mcuxClMath_SecModExp. */
#define MCUXCLMATH_SECMODEXP(session, pExpTemp, byteLenExp, iR, iX, iN, iTE, iT0, iT1, iT2, iT3)  \
    mcuxClMath_SecModExp(session, pExpTemp, byteLenExp, MCUXCLPKC_PACKARGS4(iT3, iX, iT2, iT1), MCUXCLPKC_PACKARGS4(iN, iTE, iT0, iR))


/**
 * @brief Calculates exact division with odd divisor.
 *
 * This function calculates exact division R = X/Y, where divisor Y is odd and
 * dividend X shall be exactly a multiple of Y. If X is not a multiple of Y,
 * result will be incorrect.
 *
 * @param[in]            pSession        handle for the current CL session
 * @param[out,in,in,tmp] iR_iX_iY_iT     indices of PKC operands
 * @param                xPkcByteLength  length of X
 * @param                yPkcByteLength  length of Y
 *
 * @pre
 *  - @p iT (bits 0~7): index of temp (PKC operand).
 *          Its size shall be at least (3 * MCUXCLPKC_WORDSIZE).
 *          The offset (UPTRT[iT]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *  - @p iY (bits 8~15): index of divisor Y (PKC operand), size = yPkcByteLength.
 *          The most significant PKC word of Y shall be nonzero.
 *  - @p iX (bits 16~23): index of dividend X (PKC operand), size = xPkcByteLength.
 *          X will be destroyed by this function.
 *          CAUTION: if xPkcByteLength = MCUXCLPKC_WORDSIZE,
 *            this function will access to (read) one extra PKC word of X, i.e.,
 *            X[MCUXCLPKC_WORDSIZE ~ 2*MCUXCLPKC_WORDSIZE - 1]. The value of this
 *            PKC word will not affect correctness of the result, but caller shall
 *            ensure that this PKC word is accessible by PKC.
 *  - @p iR (bits 24~31): index of result R (PKC operand),
 *          size = (xPkcByteLength - yPkcByteLength + MCUXCLPKC_WORDSIZE).
 *  - @p xPkcByteLength shall be a multiple of MCUXCLPKC_WORDSIZE, and >= @p yPkcByteLength.
 *  - @p yPkcByteLength shall be a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @post
 *  - PKC PS1 lengths unused (modified and restored in the function).
 *  - PKC PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ExactDivideOdd)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ExactDivideOdd(mcuxClSession_Handle_t pSession, uint32_t iR_iX_iY_iT, uint32_t xPkcByteLength, uint32_t yPkcByteLength);
/** Helper macro for #mcuxClMath_ExactDivideOdd. */
#define MCUXCLMATH_EXACTDIVIDEODD(pSession, iR, iX, iY, iT, xPkcByteLen, yPkcByteLen)  \
    mcuxClMath_ExactDivideOdd(pSession, MCUXCLPKC_PACKARGS4(iR, iX, iY, iT), xPkcByteLen, yPkcByteLen)
/** Helper macro for #mcuxClMath_ExactDivideOdd with flow protection. */
#define MCUXCLMATH_FP_EXACTDIVIDEODD(pSession, iR, iX, iY, iT, xPkcByteLen, yPkcByteLen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_EXACTDIVIDEODD(pSession, iR, iX, iY, iT, xPkcByteLen, yPkcByteLen))


/**
 * @brief Calculates exact division (supporting even divisor).
 *
 * This function calculates exact division R = X/Y, where dividend X shall be
 * exactly a multiple of divisor Y. If X is not a multiple of Y, result will be
 * incorrect.
 * This function trims trailing zero bits of Y and gets Y' = Y >> trailingZeros(Y),
 * and X' = X >> ((trailingZeros(Y) / 8*MCUXCLPKC_WORDSIZE) * 8*MCUXCLPKC_WORDSIZE).
 * It relies on mcuxClMath_ExactDivideOdd to calculate R' = X'/Y', and then calculates
 * R = R' >> (trailingZeros(Y) % (8*MCUXCLPKC_WORDSIZE)).
 *
 * @param[in]            pSession        handle for the current CL session
 * @param[out,in,in,tmp] iR_iX_iY_iT     Pointer table indices of parameters
 * @param                xPkcByteLength  length of X
 * @param                yPkcByteLength  length of Y
 *
 * @pre
 *  - @p iT (bits 0~7): index of temp (PKC operand).
 *          Its size shall be at least (3 * MCUXCLPKC_WORDSIZE).
 *  - @p iY (bits 8~15): index of divisor Y (PKC operand), size = yPkcByteLength.
 *          The most significant PKC word of Y shall be nonzero.
 *          The offset (UPTRT[iY]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *  - @p iX (bits 16~23): index of dividend X (PKC operand), size = xPkcByteLength.
 *          X will be destroyed by this function.
 *          CAUTION: if the length of trimmed X' is MCUXCLPKC_WORDSIZE,
 *            this function will access to (read) one extra PKC word of X, i.e.,
 *            X[xPkcByteLength ~ xPkcByteLength + MCUXCLPKC_WORDSIZE - 1].
 *            The value of this PKC word will not affect correctness of the result,
 *            but caller shall ensure that this PKC word is accessible by PKC.
 *            If caller cannot guarantee the length of trimmed X' greater than
 *            MCUXCLPKC_WORDSIZE, X shall be stored in buffer of the size,
 *            xPkcByteLength + MCUXCLPKC_WORDSIZE.
 *  - @p iR (bits 24~31): index of result R (PKC operand).
 *          Its buffer size shall be at least (xPkcByteLength - yPkcByteLength + 2*MCUXCLPKC_WORDSIZE).
 *          The result fits in size = (xPkcByteLength - yPkcByteLength + MCUXCLPKC_WORDSIZE).
 *  - @p xPkcByteLength shall be a multiple of MCUXCLPKC_WORDSIZE.
 *  - @p yPkcByteLength shall be a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @post
 *  - PKC PS1 lengths unused (modified and restored in the function).
 *  - PKC PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *  - PKC in ready state but might not be in finished state. Call #MCUXCLPKC_WAITFORFINISH
 *      before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ExactDivide)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ExactDivide(mcuxClSession_Handle_t pSession, uint32_t iR_iX_iY_iT, uint32_t xPkcByteLength, uint32_t yPkcByteLength);
/** Helper macro for #mcuxClMath_ExactDivide. */
#define MCUXCLMATH_EXACTDIVIDE(pSession, iR, iX, iY, iT, xPkcByteLen, yPkcByteLen)  \
    mcuxClMath_ExactDivide(pSession, MCUXCLPKC_PACKARGS4(iR, iX, iY, iT), xPkcByteLen, yPkcByteLen)

/** Helper macro for #mcuxClMath_ExactDivide with flow protection. */
#define MCUXCLMATH_FP_EXACTDIVIDE(pSession, iR, iX, iY, iT, xPkcByteLen, yPkcByteLen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_EXACTDIVIDE(pSession, iR, iX, iY, iT, xPkcByteLen, yPkcByteLen))


/**
 * @brief Calculates a square root modulo a prime number p.
 *
 * This function calculates a square root beta of alpha modulo a prime number p
 * by using the Tonelli-Shanks algorithm. If alpha is not a square modulo p then
 * the result will be irrelevant. This function should be preferred for prime
 * numbers which satisfy p = 1 (mod 4). For primes with p = 3 (mod 4) there is
 * a faster method to compute square roots.
 *
 * @param[in]              pSession          handle for the current CL session
 * @param[out,in,in,in]    iR_iA_iP_iQ       Pointer table indices of parameters
 * @param[tmp,tmp,tmp,tmp] iT0_iT1_iT2_iT3   Pointer table indices of temp variables
 * @param                  byteLengthP       length of the prime p
 *
 * @pre
 *  - @p iQ(bits 0~7)   : Pointer table index to Montgomery parameter R^2 (mod p)
 *  - @p iP(bits 8~15)  : Pointer table index to prime number p
 *  - @p iA(bits 16~23) : Pointer table index to input value whose square root is requested
 *  - @p iR(bits 24~31) : Pointer table index to the result R.
 *  - PS1 OPLEN defines operandSize and shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @post
 *  - PS2 OPLEN and MCLEN will be modified, and original values will not be restored.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ModSquareRoot_TonelliShanks)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ModSquareRoot_TonelliShanks(
    mcuxClSession_Handle_t pSession,
    uint32_t iR_iA_iP_iQ,
    uint32_t iT0_iT1_iT2_iT3,
    uint32_t byteLengthP);

/** Helper macro for #mcuxClMath_ModSquareRoot_TonelliShanks. */
#define MCUXCLMATH_MODSQUAREROOT_TONELLISHANKS(pSession, iR, iA, iP, iQ, iT0, iT1, iT2, iT3, byteLen)  \
    mcuxClMath_ModSquareRoot_TonelliShanks(pSession, MCUXCLPKC_PACKARGS4(iR, iA, iP, iQ), MCUXCLPKC_PACKARGS4(iT0, iT1, iT2, iT3), byteLen)

/** Helper macro for #mcuxClMath_ModSquareRoot_TonelliShanks with flow protection. */
#define MCUXCLMATH_FP_MODSQUAREROOT_TONELLISHANKS(pSession, iR, iA, iP, iQ, iT0, iT1, iT2, iT3, byteLen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_MODSQUAREROOT_TONELLISHANKS(pSession, iR, iA, iP, iQ, iT0, iT1, iT2, iT3, byteLen))

/**
 * @brief Calculates a square root modulo a prime number p.
 *
 * This function outputs a square root beta of alpha modulo a prime number p.
 * The function serves as a higher level API to the square root extraction algorithms.
 * Based on the value p (mod 4) it selects the appropriate square root extraction
 * algorithm for the given prime number p.
 * If p = 1 (mod 4) then the Tonelli-Shanks algorithm is used.
 * If p = 3 (mod 4) then computing a square root modulo p reduces to a
 * single exponentiation.
 *
 * @param[out,in,in,in]    iR_iA_iP_iQ       Pointer table indices of parameters
 * @param[tmp,tmp,tmp,tmp] iT0_iT1_iT2_iT3   Pointer table indices of temp variables
 * @param                  byteLengthP       length of the prime p
 *
 * @pre
 *  - @p iQ(bits 0~7)   : Pointer table index to Montgomery parameter R^2 (mod p)
 *  - @p iP(bits 8~15)  : Pointer table index to prime number p
 *  - @p iA(bits 16~23) : Pointer table index to input value whose square root is requested
 *  - @p iR(bits 24~31) : Pointer table index to the result R
 *  - PS1 OPLEN defines operandSize and shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @return void
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEFINED_MORE_THAN_ONCE("It declared only once.")
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_ModSquareRoot)
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMath_ModSquareRoot(
    mcuxClSession_Handle_t pSession,
    uint32_t iR_iA_iP_iQ,
    uint32_t iT0_iT1_iT2_iT3,
    uint32_t byteLengthP);

/** Helper macro for #mcuxClMath_ModSquareRoot. */
#define MCUXCLMATH_MODSQUAREROOT(pSession, iR, iA, iP, iQ, iT0, iT1, iT2, iT3, byteLen)  \
    mcuxClMath_ModSquareRoot(pSession, MCUXCLPKC_PACKARGS4(iR, iA, iP, iQ), MCUXCLPKC_PACKARGS4(iT0, iT1, iT2, iT3), byteLen)

/** Helper macro for #mcuxClMath_ModSquareRoot with flow protection. */
#define MCUXCLMATH_FP_MODSQUAREROOT(pSession, iR, iA, iP, iQ, iT0, iT1, iT2, iT3, byteLen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_MODSQUAREROOT(pSession, iR, iA, iP, iQ, iT0, iT1, iT2, iT3, byteLen))


/**
 * @brief Calculates the Legendre symbol (alpha/p).
 *
 * This function calculates the Legendre symbol for alpha modulo a prime number p.
 * The Legendre symbol (alpha/p) is a quantity which identifies if alpha is a square
 * modulo p. By its definition:
 * (alpha/p) =  0    if alpha is divisible by p
 * (alpha/p) =  1    if alpha is a square modulo p
 * (alpha/p) = -1    if alpha is not a square modulo p
 * This implementation makes use of the quadratic reciprocity law in order to allow
 * the computation of (alpha/p) in the style of the Euclidean algorithm.
 * This implies that the computation of the Legendre symbol is actually done via its
 * generalization, the Jacobi symbol.
 *
 * @param[in] pSession          Handle for the current CL session
 * @param[in] iA                Pointer table index to alpha, whose symbol (alpha/p) is requested
 * @param[tmp] iT1_iT2_iT3      Pointer table indices of temp variables
 *                              The size of iT2 shall be (operandSize + MCUXCLPKC_WORDSIZE).
 * @param[in] iP                Pointer table index to prime number p
 *
 * @pre
 *  - PS1 OPLEN defines operandSize and shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval The value of the Legendre symbol (alpha/p)
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEFINED_MORE_THAN_ONCE("It declared only once.")
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMath_LegendreSymbol)
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClMath_LegendreSymbol(
    mcuxClSession_Handle_t pSession,
    uint8_t iA,
    uint32_t iT1_iT2_iT3_iP);

/** Helper macro for #mcuxClMath_LegendreSymbol. */
#define MCUXCLMATH_LEGENDRESYMBOL(pSession, iA, iT1, iT2, iT3, iP)  \
    mcuxClMath_LegendreSymbol(pSession, iA, MCUXCLPKC_PACKARGS4(iT1, iT2, iT3, iP))

/**
 * @}
 */ /* mcuxClMath_Internal_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMATH_INTERNAL_FUNCTIONS_H_ */
