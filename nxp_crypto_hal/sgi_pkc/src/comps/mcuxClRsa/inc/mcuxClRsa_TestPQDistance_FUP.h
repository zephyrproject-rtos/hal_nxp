/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2024 NXP                                            */
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

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClRsa_TestPQDistance_FUP.h>

MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_TestPQDistance_FUP,
    FUP_CRC_PLACEHOLDER,
    /* 1. Xor 128 MSbits of p with rand */
    FUP_OP1_XOR(MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T1,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_P128MSB,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_RAND),
    /* 2. Xor 128 MSbits of q with rand */
    FUP_OP1_XOR(MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T2,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_Q128MSB,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_RAND),
    /* 3. Copy 100 MSbits of masked p into buffer in PKC RAM */
    FUP_OP1_SHR(MCUXCLRSA_INTERNAL_TESTPQDISTANCE_RAND,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T1,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_CONSTANT28),
    /* 4. Copy 100 MS bits of masked q into buffer in PKC RAM */
    FUP_OP1_SHR(MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T1,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T2,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_CONSTANT28),
    /*
    * 5. Compare 100 MSbits of p and q in a masked way
    *    If they are equal, then function returns MCUXCLRSA_STATUS_INVALID_INPUT error code
    *    (primes do not meet the FIPS requirements).
    */
    FUP_OP1_CMP(MCUXCLRSA_INTERNAL_TESTPQDISTANCE_RAND,
        MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T1),
);
