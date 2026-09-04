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
 * @file  mcuxClEcc_Weier_Internal_KeyGen.c
 * @brief Weierstrass curve internal key generation
 */

#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>
#include <mcuxClEcc.h>
#include <mcuxClRandom.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Utils.h>
#include <internal/mcuxClMath_Internal_Functions.h>
#include <internal/mcuxClEcc_Internal_Random.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClPrng_Internal_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

#define MCUXCLECC_FP_WEIER_KEYGEN_SECSTRENGTH  MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_checkSecurityStrength)

/**
 * This function implements secure ECDSA private key / ephemeral key generation,
 * according to FIPS 186-4. It outputs multiplicative split d0 and d1 as well as d,
 * satisfying d0*d1 mod n = d = (c mod (n-1)) + 1, in which d is the private key
 * derived from a (bitLen(n)+64)-bit true (DRBG) random number c and d0 is a 64-bit
 * random number (with bit 63 set).
 *
 * Inputs:
 *   nByteLength: byte length of n (base point order).
 *
 * Inputs in pOperands[] and PKC workarea: N/A.
 *
 * Prerequisites:
 *   ps1Len = (operandSize, operandSize);
 *   curve order n in N, NDash of n in NFULL;
 *   no on-going calculation;
 *   buffers S0, S1, S2 and S3 are with doubled-size (2*operandSize).
 *
 * Result in PKC workarea:
 *   buffers S0 and S1 contain multiplicative split private key d0 and d1 (operandSize);
 *   buffer S3 contains a random value usable for blinding operations of size opLen.
 *
 * Other modifications:
 *   buffers T0, T3, XA, YA, ZA and Z are modified (as temp, buffer size);
 *   buffers S0, S1, S2 and S3 are modified (as temp, double buffer size);
 *   offsets pOperands[VT] is modified.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Int_CoreKeyGen)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Int_CoreKeyGen(mcuxClSession_Handle_t pSession, uint32_t nByteLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Int_CoreKeyGen);
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(nByteLength, MCUXCLECC_WEIERECC_MIN_SIZE_BASEPOINTORDER, MCUXCLECC_WEIERECC_MAX_SIZE_BASEPOINTORDER)
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    /* Count leading zeros in most significant word of n. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 to Rule 11.3 - PKC word is CPU word aligned.")
    const uint32_t *ptr32N = (const uint32_t *) MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    const uint32_t wordNumN = (nByteLength + (sizeof(uint32_t)) - 1u) / (sizeof(uint32_t));
    uint32_t nMSWord = ptr32N[wordNumN - 1u];
    uint32_t nMSWord_LeadZeros = mcuxClMath_CountLeadingZerosWord(nMSWord);
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(nMSWord_LeadZeros, 0u, 31u)
    uint32_t bitLenN65 = (wordNumN * (sizeof(uint32_t)) * 8u) - nMSWord_LeadZeros + 65u;
    uint32_t pkcByteLenN65 = (bitLenN65 + (MCUXCLPKC_WORDSIZE * 8u) - 1u) / (MCUXCLPKC_WORDSIZE * 8u) * MCUXCLPKC_WORDSIZE;
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_pkcByteLenN65, pkcByteLenN65);
    const uint32_t mcLen_opLen = MCUXCLPKC_PS1_GETLENGTH_REG();
    const uint32_t opLen = MCUXCLPKC_PS1_UNPACK_OPLEN(mcLen_opLen);
    /* Record the used PS1 and PS2 lengths for the called FUP programs */
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_FUPReduceModEven_PS1, MCUXCLPKC_PS1_PACK(pkcByteLenN65, opLen));
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_FUPCoreKeyGenSteps567_PS1, mcLen_opLen);
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_FUPCoreKeyGenSteps56_PS2, MCUXCLPKC_PS2_PACK(0u, opLen * 2u));
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_FUPCoreKeyGenSteps7_PS2, MCUXCLPKC_PS2_PACK(opLen * 2u, opLen));

    /************************************************************************************/
    /* Step 1: Generate key seed c with the DRBG in Boolean masked form c_b = c ^ r.    */
    /* a. generate Boolean mask r.                                                      */
    /* b. generate Boolean masked key seed c_b                                          */
    /* NOTE: c_b and r is in a buffers of size, pkcSize(bitLenN+65)                     */
    /************************************************************************************/
    /* Generate mask r in buffer S0 and clear garbage bytes */
    uint8_t *ptrS0 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S0]);
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_PKCWA_S0, (uint32_t) ptrS0);
    const uint32_t keySeedLength = (wordNumN * (sizeof(uint32_t))) + 8u;
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(keySeedLength, MCUXCLECC_WEIERECC_MIN_SIZE_PRIVATEKEY, pkcByteLenN65)
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_keySeedLength, keySeedLength);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, &ptrS0[keySeedLength]);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, pkcByteLenN65 - keySeedLength);
    MCUXCLMEMORY_CLEAR_INT(&ptrS0[keySeedLength], pkcByteLenN65 - keySeedLength);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_ncGenerate_Internal(pSession, ptrS0, keySeedLength));
    /* Prepare buffer S2 for masked key seed c_b: Initialize it with PRNG data and clear garbage bytes */
    uint8_t *ptrS2 = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]);
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_PKCWA_S2, (uint32_t) ptrS2);
    MCUX_CSSL_DI_RECORD(sumOfMemClearParams, (uint32_t)&ptrS2[keySeedLength] + pkcByteLenN65 - keySeedLength);
    MCUXCLMEMORY_CLEAR_INT(&ptrS2[keySeedLength], pkcByteLenN65 - keySeedLength);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(ptrS2, keySeedLength));
    /* Derive the security strength required for the RNG from bitLenN / 2 and check whether it can be provided. */
    MCUX_CSSL_FP_FUNCTION_CALL(ret_checkSecurityStrength, mcuxClRandom_checkSecurityStrength(pSession, MCUXCLCORE_MIN((nByteLength * 8u) / 2u, 256u)));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret_checkSecurityStrength);
    /* Generate key seed c with the DRBG in Boolean masked form c_b = c ^ r, where c_b is stored in ECC_S2 and the XOR-mask r has been generated above in buffer ECC_S0. */
    /* c_b is loaded into ECC_S2, second share (r) is generated in previous step in ECC_S0 buffer */
    uint32_t *ptr32S0 = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S0]);
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_PKCWA_S0, (uint32_t) ptr32S0);
    MCUXCLECC_FP_RANDOM_HQRNG(mcuxClEcc_Int_CoreKeyGen, pSession, ptrS2, keySeedLength, ptr32S0);
    /*******************************************************************************/
    /* Step 2:                                                                     */
    /* a. Truncate c_b and r to nBitLen+64 bits.                                   */
    /* b. Set bit at the top of c_b to avoid overflowing (c_b += 2^(nBitLen+64))   */
    /* in the upcoming boolean to arithmetic masking conversion.                   */
    /* NOTE: This does not have an impact on the key seed value!                   */
    /* NOTE: The bit above c_b (now at bit position nBitLen+64) is still set to 1  */
    /* c. Convert from boolean masking (c + 2^(nBitLen+64) = c_b ^ r) to           */
    /*    arithmetic masking           (c + 2^(nBitLen+64) = c' + r)               */
    /* d. Calculate r' = 2^(nBitLen+64) - r    (c = c' - r')                       */
    /* OPLEN = pkcSize(bitLenN+65 bit).                                            */
    /*******************************************************************************/
    /* Step 2a: Set bit at the top of c_b of the generated random key seed */
    /* Step 2b: Truncate c_b and r. */
    pOperands[WEIER_VT] = (uint16_t) nMSWord_LeadZeros;
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_PKCWA_VT, nMSWord_LeadZeros);
    uint32_t *ptr32S1 = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S1]);
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_PKCWA_S1, (uint32_t) ptr32S1);
    /* Set PS2 OPLEN = pkcByteLenN65. */
    MCUXCLPKC_PS2_SETLENGTH(0u, pkcByteLenN65);
    MCUXCLPKC_FP_CALC_OP2_CONST(ECC_S1, 0u);
    MCUXCLPKC_WAITFORFINISH();
    ptr32S1[(bitLenN65 - 1u) / 32u] = (uint32_t) 1u << ((bitLenN65 - 1u) & 31u);
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_CoreKeyGen_Steps2ab,
                        mcuxClEcc_FUP_Weier_CoreKeyGen_Steps2ab_LEN);
    /* Expunge nMSWord_LeadZeros stored in PKC buffer VT after used in CoreKeyGen_Steps2ab */
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_PKCWA_VT, (uint32_t) pOperands[WEIER_VT]);
    /* Step 2c: Convert boolean masking to arithmetic masking by modyfying masked value            */
    /*         c' + r = c_b ^ r = c + 2^(nBitLen+64)                                               */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_Weier_BooleanToArithmeticMasking());
    /* Step 2d: Calculate r' = 2^(nBitLen+64) - r.*/
    /* S1 = 2^(nBitLen+64) */
    MCUXCLPKC_FP_CALC_OP2_CONST(ECC_S1, 0u);
    MCUXCLPKC_WAITFORFINISH();
    ptr32S1[(bitLenN65 - 1u) / 32u] = (uint32_t) 1u << ((bitLenN65 - 1u) & 31u);
    /* S0 = r' = 2^(nBitLen+64) - r*/
    MCUXCLPKC_FP_CALC_OP2_SUB(ECC_S0, ECC_S1, ECC_S3);
    /*******************************************************************/
    /* Step 3: use ReduceModEven to compute:                           */
    /*         s = r' mod (n-1);                                       */
    /*         c" = c' mod (n-1) = (c+s) mod (n-1).                    */
    /*******************************************************************/
    /* Z = n - 1*/
    MCUXCLPKC_FP_CALC_OP1_SUB_CONST(WEIER_Z, ECC_N, 1u);
    MCUXCLPKC_WAITFORREADY();
    /* S1 = c" = ReduceModEven(c', n-1). */
    MCUXCLPKC_PS1_SETLENGTH(pkcByteLenN65, opLen);
    MCUXCLMATH_FP_REDUCEMODEVEN(pSession, ECC_S1, ECC_S2, WEIER_Z, WEIER_XA, ECC_S1, WEIER_YA, WEIER_ZA);
    /* S2 = s = ReduceModEven(r', n-1). */
    MCUXCLMATH_FP_REDUCEMODEVEN(pSession, ECC_S2, ECC_S0, WEIER_Z, WEIER_XA, ECC_S2, WEIER_YA, WEIER_ZA);

    /* Expunge the PS1 lengths after used by ReduceModEven */
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_FUPReduceModEven_PS1, MCUXCLPKC_PS1_GETLENGTH_REG());
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS1_SETLENGTH_REG(mcLen_opLen);  /* MCLEN = OPLEN = opLen. */

    /**********************************************************/
    /* Step 4: generate 64-bit random d0, (MSb set);          */
    /*         compute v = ModInv(d0) = d0^(-1) mod n.        */
    /**********************************************************/
    /* Clear buffers S0 and S3, with OPLEN = operandSize. */
    MCUXCLPKC_FP_CALC_OP1_CONST(ECC_S0, 0u);
    MCUXCLPKC_FP_CALC_OP1_CONST(ECC_S3, 0u);
    /* Generate S0 = 64-bit random d0, with PRNG. */
    MCUX_CSSL_DI_RECORD(EccIntCoreKeyGen_PKCWA_S0, ptrS0);
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_ncGenerate_Internal(pSession, ptrS0, 8u));
    /* Set MSBit of d0 (to ensure d0 != 0) using the PKC.
     *
     * NOTES:
     *   - PKC PS1 can be used, because operandSize >= 64.
     *   - The LSWord of S3 has already been cleared above */
    uint32_t *ptr32S3 = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S3]);
    ptr32S3[1] = 0x80000000u;
    MCUXCLPKC_FP_CALC_OP1_OR(ECC_S0, ECC_S0, ECC_S3);
    /* ZA = d0, duplicate because ModInv(d0) will destroy input d0. */
    MCUXCLPKC_FP_CALC_OP1_OR_CONST(WEIER_ZA, ECC_S0, 0u);
    /* T0 = v = ModInv(d0), with temp S3. */
    MCUXCLECC_FP_MODINV(pSession, ECC_T0, WEIER_ZA, ECC_N, ECC_S3, ECC_T3);
    /* Now, S0 = d0 (opLen), T0 = v (opLen), Z = n-1 (opLen), */
    /*      S1 = c" (opLen), S2 = s (opLen).  */
    /**********************************************************/
    /* Step 5: compute d' = (v*c") - (v*s) mod (v*(n-1)),     */
    /*                    = v * (c mod (n-1)).                */
    /* a. 3 plain multiplications (PM):                       */
    /*    MCLEN = OPLEN = opLen, RLEN = 2 * opLen;            */
    /* b. modular addition (MS): OPLEN = 2 * opLen.           */
    /**********************************************************/
    /**********************************************************/
    /* Step 6: compute d" = d' + v,                           */
    /*                    = v * ((c mod (n-1)) + 1) = v * d.  */
    /* a. plain addition (ADD): OPLEN = 2 * opLen;            */
    /* b. v shall be prepared in buffer of size, 2*opLen.     */
    /**********************************************************/
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS2_SETLENGTH(0u, opLen * 2u);
    /* Step 5: S2 = d' = (v*c") + (v*s) mod (v*(n-1)); */
    /*         S3 = v * s, as another random number.   */
    /* Step 6: S2 = d" = d' + v.                       */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_CoreKeyGen_Steps56,
                        mcuxClEcc_FUP_Weier_CoreKeyGen_Steps56_LEN);
    /* Expunge the PS2 length after used by CoreKeyGen_Steps56 */
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_FUPCoreKeyGenSteps56_PS2, MCUXCLPKC_PS2_GETLENGTH_REG());
    /**********************************************************/
    /* Step 7: compute d1 = d" mod n < n.                     */
    /* a. length of d" is (2 * opLen).                        */
    /**********************************************************/
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS2_SETLENGTH(opLen * 2u, opLen);
    /* Step 7: S1 = d1 = (d" mod n) < n. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_CoreKeyGen_Step7,
                        mcuxClEcc_FUP_Weier_CoreKeyGen_Step7_LEN);
    /* Expunge the PS1 length after used by CoreKeyGen_Steps56 and CoreKeyGen_Step7 */
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_FUPCoreKeyGenSteps567_PS1, MCUXCLPKC_PS1_GETLENGTH_REG());
    /* Expunge the PS2 lengths after used by CoreKeyGen_Step7 */
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_FUPCoreKeyGenSteps7_PS2, MCUXCLPKC_PS2_GETLENGTH_REG());
    /**
     * Re-compute pkcByteLenN65 and keySeedLength then Expunge them
     * Consequently, the invariants ptr32N, wordNumN, bitLenN65, pkcByteLenN65, and keySeedLength are protected.
    */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 to Rule 11.3 - PKC word is CPU word aligned.")
    const uint32_t *ptr32N_2 = (const uint32_t *) MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    /* another way to calculate WordNumN to avoid compiler storing the value on stack */
    const uint32_t wordNumN_2 = nByteLength / sizeof(uint32_t) + (nByteLength % sizeof(uint32_t)==0u?0u:1u);
    MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND();  // avoid CPU accessing to PKC workarea when PKC is busy
    const uint32_t nMSWord_LeadZeros_2 = mcuxClMath_CountLeadingZerosWord(ptr32N_2[wordNumN_2 - 1u]);
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(nMSWord_LeadZeros_2, 0u, 31u)
    const uint32_t bitLenN65_2 = (wordNumN_2 * (sizeof(uint32_t)) * 8u) - nMSWord_LeadZeros_2 + 65u;
    const uint32_t pkcByteLenN65_2 = (bitLenN65_2 + (MCUXCLPKC_WORDSIZE * 8u) - 1u) / (MCUXCLPKC_WORDSIZE * 8u) * MCUXCLPKC_WORDSIZE;
    const uint32_t keySeedLength_2 = (wordNumN_2 * (sizeof(uint32_t))) + 8u;
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_pkcByteLenN65, pkcByteLenN65_2);
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_keySeedLength, keySeedLength_2);
    /**
     * Expunge pointers to S0, S1, and S2.
     * Consequently, the pointers ptrS0, ptr32S0, ptr32S1, ptrS2 are protected.
     */
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_PKCWA_S0, (uint32_t) MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_S0]) * 3u);
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_PKCWA_S1, (uint32_t) MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S1]));
    MCUX_CSSL_DI_EXPUNGE(EccIntCoreKeyGen_PKCWA_S2, (uint32_t) MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S2]));
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_Int_CoreKeyGen,
        MCUXCLECC_FP_INT_COREKEYGEN_FINAL);
}
