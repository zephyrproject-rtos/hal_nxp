/*--------------------------------------------------------------------------*/
/* Copyright 2018-2022 NXP                                                  */
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
 * @file  mcuxClOsccaPkc_FupMacros.h
 * @brief Macros for PKC FUP program composing
 */

#ifndef MCUXCLOSCCAPKC_FUPMACROS_H_
#define MCUXCLOSCCAPKC_FUPMACROS_H_


#include <internal/mcuxClOsccaPkc_Operations.h>
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

/**********************************************************/
/* Macros to create FUP program                           */
/**********************************************************/
/**
 * @brief FUP programs data structure
 */
typedef struct mcuxClOsccaPkc_FUPEntry
{
    uint8_t a;
    uint8_t b;
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t r;
}mcuxClOsccaPkc_FUPEntry_t;

/**
 * Macro to create FUP program, e.g., a FUP program with 2 entries:
 * MCUXCLPKC_FUP_EXT_ROM(FupProgram1, FUP_MC1_MMUL(0,1,1), FUP_MC1_MMUL(1,0,0));
 */
#define MCUXCLOSCCAPKC_FUP_EXT_ROM(name, ...)  \
    MCUX_CSSL_ANALYSIS_START_PATTERN_FUP() \
    const mcuxClOsccaPkc_FUPEntry_t name[] __attribute__((aligned(4),section("PH_CL_FUP_PROGRAMS_MAGIC_AREA"))) = { __VA_ARGS__ } \
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP()

#define MCUXCLOSCCAPKC_FUP_LEN(pFupProgram)  ((uint8_t) ((sizeof(pFupProgram)) / sizeof(mcuxClOsccaPkc_FUPEntry_t)))

/**********************************************************/
/* Macros for FUP CRC entry                               */
/**********************************************************/
/**
 * Macro to reserve space for a CRC entry in FUP program.
 * The CRC32 value is temporarily set to 0x00000000, and will be updated (filled) by build system.
 */
#define MCUXCLOSCCAPKC_FUP_DATA                       (0x0U)
#define MCUXCLOSCCAPKC_FUP_CRC                        (0x10U)
#define MCUXCLOSCCAPKC_CRC_ENTRY                      {MCUXCLOSCCAPKC_FUP_CRC, 0, 0, 0, 0, 0}

/** Helper macro to pack CRC entry. */
#define MCUXCLOSCCAPKC_FUP_CRC_ENTRY(crc32)           {MCUXCLOSCCAPKC_FUP_CRC, 0, (crc32) & 0xFFu, ((crc32) >> 8) & 0xFFu, ((crc32) >> 16) & 0xFFu, ((crc32) >> 24) & 0xFFu}

/**********************************************************/
/* Helper macros for FUP program composing                */
/**********************************************************/
MCUX_CSSL_ANALYSIS_COVERITY_START_DEVIATE(MISRA_C_2012_Rule_2_5, "FUP operations are defined.")
/* L0 operation (OP) with parameter set 1, without repeating. */
#define FUP_OP1_AND(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_AND, Y /* unused */, Y, Z, R}
#define FUP_OP1_OR(R, Y, Z)                                 {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_OR, Y /* unused */, Y, Z, R}
#define FUP_OP1_XOR(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_XOR, Y /* unused */, Y, Z, R}
#define FUP_OP1_SUB(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_SUB, Y /* unused */, Y, Z, R}
#define FUP_OP1_SBX0(R, Z)                                  {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_SBX0, Z /* unused */, Z /* unused */, Z, R}
#define FUP_OP1_ROTL(R, Y, Z)                               {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_ROTL, Y /* unused */, Y, Z, R}
#define FUP_OP1_SHL(R, Y, C)                                {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_SHL, Y /* unused */, Y, C, R}
#define FUP_OP1_ADD(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_ADD, Y /* unused */, Y, Z, R}
#define FUP_OP1_ADD_CONST(R, Y, C)                          {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_ADD_YC, Y /* unused */, Y, C, R}
#define FUP_OP1_NEG(R, Z)                                   {MCUXCLOSCCAPKC_FUP_OP1, MCUXCLOSCCAPKC_FOP_NEG, Z /* unused */, Z /* unused */, Z, R}

/* L1 microcode (MC) with parameter set 1, without repeating. */
#define FUP_MC1_MMUL(R, X, Y, Z)                            {MCUXCLOSCCAPKC_FUP_MC1, MCUXCLOSCCAPKC_FMC_MMUL, X, Y, Z, R}
#define FUP_MC1_MADD(R, Y, Z, X)                            {MCUXCLOSCCAPKC_FUP_MC1, MCUXCLOSCCAPKC_FMC_MADD, X, Y, Z, R}
#define FUP_MC1_MSUB(R, Y, Z, X)                            {MCUXCLOSCCAPKC_FUP_MC1, MCUXCLOSCCAPKC_FMC_MSUB, X, Y, Z, R}
#define FUP_MC1_MRED(R, X, Z)                               {MCUXCLOSCCAPKC_FUP_MC1, MCUXCLOSCCAPKC_FMC_MRED, X, X /* unused */, Z, R}

/* L0 operation (OP) with parameter set 2, without repeating. */
#define FUP_OP2_AND(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_AND, Y /* unused */, Y, Z, R}
#define FUP_OP2_OR(R, Y, Z)                                 {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_OR, Y /* unused */, Y, Z, R}
#define FUP_OP2_XOR(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_XOR, Y /* unused */, Y, Z, R}
#define FUP_OP2_SUB(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_SUB, Y /* unused */, Y, Z, R}
#define FUP_OP2_SBX0(R, Z)                                  {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_SBX0, Z /* unused */, Z /* unused */, Z, R}
#define FUP_OP2_ROTL(R, Y, Z)                               {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_ROTL, Y /* unused */, Y, Z, R}
#define FUP_OP2_SHL(R, Y, C)                                {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_SHL, Y /* unused */, Y, C, R}
#define FUP_OP2_ADD(R, Y, Z)                                {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_ADD, Y /* unused */, Y, Z, R}
#define FUP_OP2_ADD_CONST(R, Y, C)                          {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_ADD_YC, Y /* unused */, Y, C, R}
#define FUP_OP2_NEG(R, Z)                                   {MCUXCLOSCCAPKC_FUP_OP2, MCUXCLOSCCAPKC_FOP_NEG, Z /* unused */, Z /* unused */, Z, R}

/* L1 microcode (MC) with parameter set 2, without repeating. */
#define FUP_MC2_MMUL(R, X, Y, Z)                            {MCUXCLOSCCAPKC_FUP_MC2, MCUXCLOSCCAPKC_FMC_MMUL, X, Y, Z, R}
#define FUP_MC2_MADD(R, Y, Z, X)                            {MCUXCLOSCCAPKC_FUP_MC2, MCUXCLOSCCAPKC_FMC_MADD, X, Y, Z, R}
#define FUP_MC2_MSUB(R, Y, Z, X)                            {MCUXCLOSCCAPKC_FUP_MC2, MCUXCLOSCCAPKC_FMC_MSUB, X, Y, Z, R}
#define FUP_MC2_MRED(R, X, Z)                               {MCUXCLOSCCAPKC_FUP_MC2, MCUXCLOSCCAPKC_FMC_MRED, X, X /* unused */, Z, R}
MCUX_CSSL_ANALYSIS_COVERITY_STOP_DEVIATE(MISRA_C_2012_Rule_2_5)

#endif /*MCUXCLOSCCAPKC_FUPMACROS_H_*/
