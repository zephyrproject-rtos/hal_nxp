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

#include <mcuxClHash.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Core_c_sha3.h>

/**********************************************************
 * Defines and Macros
 **********************************************************/
#define MCUXCLHASHMODES_KECCAK_ROUND_COUNT     ( 24u )   /* Number of rounds of the Keccak permutation. */

/* 64-bit rotate left expression */
#define MCUXCLHASHMODES_KECCACK_ROTL64(X, Y) ((0u == (Y)) ? (X) : (((X) << (Y)) | ((X) >> (64u - (Y)))))

#define MCUXCLHASHMODES_KECCAK_INPLACEXOR(X,Y) ((X) ^= (Y))

#define Aba (pState64[ 0])
#define Abe (pState64[ 1])
#define Abi (pState64[ 2])
#define Abo (pState64[ 3])
#define Abu (pState64[ 4])
#define Aga (pState64[ 5])
#define Age (pState64[ 6])
#define Agi (pState64[ 7])
#define Ago (pState64[ 8])
#define Agu (pState64[ 9])
#define Aka (pState64[10])
#define Ake (pState64[11])
#define Aki (pState64[12])
#define Ako (pState64[13])
#define Aku (pState64[14])
#define Ama (pState64[15])
#define Ame (pState64[16])
#define Ami (pState64[17])
#define Amo (pState64[18])
#define Amu (pState64[19])
#define Asa (pState64[20])
#define Ase (pState64[21])
#define Asi (pState64[22])
#define Aso (pState64[23])
#define Asu (pState64[24])

/***********************************************************
 * Constants                                               *
 **********************************************************/
/* Global constants for SHA3 */
static const uint64_t mcuxClHashModes_Sha3_KeccakRoundConstant64[MCUXCLHASHMODES_KECCAK_ROUND_COUNT] = {
    0x0000000000000001UL,
    0x0000000000008082UL,
    0x800000000000808AUL,
    0x8000000080008000UL,
    0x000000000000808BUL,
    0x0000000080000001UL,
    0x8000000080008081UL,
    0x8000000000008009UL,
    0x000000000000008AUL,
    0x0000000000000088UL,
    0x0000000080008009UL,
    0x000000008000000AUL,
    0x000000008000808BUL,
    0x800000000000008BUL,
    0x8000000000008089UL,
    0x8000000000008003UL,
    0x8000000000008002UL,
    0x8000000000000080UL,
    0x000000000000800AUL,
    0x800000008000000AUL,
    0x8000000080008081UL,
    0x8000000000008080UL,
    0x0000000080000001UL,
    0x8000000080008008UL
};

/***********************************************************
 * Inlined Functions Definition                            *
 **********************************************************/
static inline uint64_t mcuxClHashModes_keccak_chi(uint64_t x, uint64_t y, uint64_t z)
{
  return (x ^ ((~y) & z));
}

static inline uint64_t mcuxClHashModes_keccak_computeParity(uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e)
{
  return a^ b ^ c ^ d ^ e;
}

static inline uint64_t mcuxClHashModes_keccak_combineParity(uint64_t x, uint64_t y)
{
  return x ^ MCUXCLHASHMODES_KECCACK_ROTL64(y, 1u);
}

static inline uint64_t mcuxClHashModes_keccak_iota(uint64_t x, uint64_t y)
{
  return x ^ y;
}

static inline uint64_t mcuxClHashModes_keccak_lambda(uint64_t x, uint64_t y)
{
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(y, 0u, 64u, MCUXCLHASH_STATUS_FAULT_ATTACK)
  return MCUXCLHASHMODES_KECCACK_ROTL64((x), (y));
}

/***********************************************************
 * Public Functions Definition                             *
 **********************************************************/
/**
 * @brief Keccak Core function
 *
 * This function performs Keccak permutation on the state
 *
 * @param[in,out] pState	Pointer to the 200 byte (5*5*64 = 1600 bits) state
 *
 * @return void
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_core_c_keccak)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_core_c_keccak(uint32_t *pState)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_core_c_keccak);

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("This pointer is aligned to 64 bit boundary")
  uint64_t *pState64 = (uint64_t *)pState;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

  MCUX_CSSL_FP_LOOP_DECL(loopKeccakRound);
  for (uint8_t i = 0u; i < MCUXCLHASHMODES_KECCAK_ROUND_COUNT; ++i)
  {
    /* Prepare Theta */
    uint64_t Ca = mcuxClHashModes_keccak_computeParity(Aba, Aga, Aka, Ama, Asa);
    uint64_t Ce = mcuxClHashModes_keccak_computeParity(Abe, Age, Ake, Ame, Ase);
    uint64_t Ci = mcuxClHashModes_keccak_computeParity(Abi, Agi, Aki, Ami, Asi);
    uint64_t Co = mcuxClHashModes_keccak_computeParity(Abo, Ago, Ako, Amo, Aso);
    uint64_t Cu = mcuxClHashModes_keccak_computeParity(Abu, Agu, Aku, Amu, Asu);

    uint64_t Da = mcuxClHashModes_keccak_combineParity(Cu, Ce);
    uint64_t De = mcuxClHashModes_keccak_combineParity(Ca, Ci);
    uint64_t Di = mcuxClHashModes_keccak_combineParity(Ce, Co);
    uint64_t Do = mcuxClHashModes_keccak_combineParity(Ci, Cu);
    uint64_t Du = mcuxClHashModes_keccak_combineParity(Co, Ca);

    /* Lambda = Theta + Rho + Pi */
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Aba, Da);
    uint64_t Bba = mcuxClHashModes_keccak_lambda(Aba, 0u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Age, De);
    uint64_t Bbe = mcuxClHashModes_keccak_lambda(Age, 44u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Aki, Di);
    uint64_t Bbi = mcuxClHashModes_keccak_lambda(Aki, 43u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Amo, Do);
    uint64_t Bbo = mcuxClHashModes_keccak_lambda(Amo, 21u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Asu, Du);
    uint64_t Bbu = mcuxClHashModes_keccak_lambda(Asu, 14u);

    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Abo, Do);
    uint64_t Bga = mcuxClHashModes_keccak_lambda(Abo, 28u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Agu, Du);
    uint64_t Bge = mcuxClHashModes_keccak_lambda(Agu, 20u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Aka, Da);
    uint64_t Bgi = mcuxClHashModes_keccak_lambda(Aka, 3u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Ame, De);
    uint64_t Bgo = mcuxClHashModes_keccak_lambda(Ame, 45u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Asi, Di);
    uint64_t Bgu = mcuxClHashModes_keccak_lambda(Asi, 61u);

    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Abe, De);
    uint64_t Bka = mcuxClHashModes_keccak_lambda(Abe, 1u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Agi, Di);
    uint64_t Bke = mcuxClHashModes_keccak_lambda(Agi, 6u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Ako, Do);
    uint64_t Bki = mcuxClHashModes_keccak_lambda(Ako, 25u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Amu, Du);
    uint64_t Bko = mcuxClHashModes_keccak_lambda(Amu, 8u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Asa, Da);
    uint64_t Bku = mcuxClHashModes_keccak_lambda(Asa, 18u);

    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Abu, Du);
    uint64_t Bma = mcuxClHashModes_keccak_lambda(Abu, 27u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Aga, Da);
    uint64_t Bme = mcuxClHashModes_keccak_lambda(Aga, 36u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Ake, De);
    uint64_t Bmi = mcuxClHashModes_keccak_lambda(Ake, 10u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Ami, Di);
    uint64_t Bmo = mcuxClHashModes_keccak_lambda(Ami, 15u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Aso, Do);
    uint64_t Bmu = mcuxClHashModes_keccak_lambda(Aso, 56u);

    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Abi, Di);
    uint64_t Bsa = mcuxClHashModes_keccak_lambda(Abi, 62u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Ago, Do);
    uint64_t Bse = mcuxClHashModes_keccak_lambda(Ago, 55u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Aku, Du);
    uint64_t Bsi = mcuxClHashModes_keccak_lambda(Aku, 39u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Ama, Da);
    uint64_t Bso = mcuxClHashModes_keccak_lambda(Ama, 41u);
    MCUXCLHASHMODES_KECCAK_INPLACEXOR(Ase, De);
    uint64_t Bsu = mcuxClHashModes_keccak_lambda(Ase, 2u);

    /* Chi and Iota */
    Aba = mcuxClHashModes_keccak_chi(Bba, Bbe, Bbi);
    Aba = mcuxClHashModes_keccak_iota(Aba, mcuxClHashModes_Sha3_KeccakRoundConstant64[i]);
    Abe = mcuxClHashModes_keccak_chi(Bbe, Bbi, Bbo);
    Abi = mcuxClHashModes_keccak_chi(Bbi, Bbo, Bbu);
    Abo = mcuxClHashModes_keccak_chi(Bbo, Bbu, Bba);
    Abu = mcuxClHashModes_keccak_chi(Bbu, Bba, Bbe);

    Aga = mcuxClHashModes_keccak_chi(Bga, Bge, Bgi);
    Age = mcuxClHashModes_keccak_chi(Bge, Bgi, Bgo);
    Agi = mcuxClHashModes_keccak_chi(Bgi, Bgo, Bgu);
    Ago = mcuxClHashModes_keccak_chi(Bgo, Bgu, Bga);
    Agu = mcuxClHashModes_keccak_chi(Bgu, Bga, Bge);

    Aka = mcuxClHashModes_keccak_chi(Bka, Bke, Bki);
    Ake = mcuxClHashModes_keccak_chi(Bke, Bki, Bko);
    Aki = mcuxClHashModes_keccak_chi(Bki, Bko, Bku);
    Ako = mcuxClHashModes_keccak_chi(Bko, Bku, Bka);
    Aku = mcuxClHashModes_keccak_chi(Bku, Bka, Bke);

    Ama = mcuxClHashModes_keccak_chi(Bma, Bme, Bmi);
    Ame = mcuxClHashModes_keccak_chi(Bme, Bmi, Bmo);
    Ami = mcuxClHashModes_keccak_chi(Bmi, Bmo, Bmu);
    Amo = mcuxClHashModes_keccak_chi(Bmo, Bmu, Bma);
    Amu = mcuxClHashModes_keccak_chi(Bmu, Bma, Bme);

    Asa = mcuxClHashModes_keccak_chi(Bsa, Bse, Bsi);
    Ase = mcuxClHashModes_keccak_chi(Bse, Bsi, Bso);
    Asi = mcuxClHashModes_keccak_chi(Bsi, Bso, Bsu);
    Aso = mcuxClHashModes_keccak_chi(Bso, Bsu, Bsa);
    Asu = mcuxClHashModes_keccak_chi(Bsu, Bsa, Bse);

    MCUX_CSSL_FP_LOOP_ITERATION(loopKeccakRound);
  }

	/*return E_OK*/
	MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_core_c_keccak,
    MCUX_CSSL_FP_LOOP_ITERATIONS(loopKeccakRound, MCUXCLHASHMODES_KECCAK_ROUND_COUNT)
  );
}
