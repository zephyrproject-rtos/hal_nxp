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
 *
 * @file:   mcuxClRandomModes_Internal_SizeDefinitions.h
 * @brief:  This file contains size definitions to share them with other components
 *
 */

#ifndef MCUXCLRANDOMMODES_INTERNAL_SIZEDEFINITIONS_H_
#define MCUXCLRANDOMMODES_INTERNAL_SIZEDEFINITIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClAes.h>
#include <stdint.h>
#include <stdbool.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>
#include <mcuxClRandom_Types.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>
#include <mcuxClCore_Macros.h>

/**************************************************************************************************/
/*                                                                                                */
/* Definition of max workarea sizes allocated by internal DRBG algorithm related helper functions */
/*                                                                                                */
/**************************************************************************************************/
/*
 * Description of how much cpuWa mcuxClRandomModes_CtrDrbg_bcc uses
 */
#define MCUXCLRANDOMMODES_CTRDRBG_BCC_CPUWA_SIZE     MCUXCLAES_BLOCK_SIZE

/*
 * Description of how much cpuWa mcuxClRandomModes_CtrDrbg_df uses at most, i.e. for the AES-256 CTR_DRBG case
 *
 * cpuWa          | IV | L | N | Seed | 0x80 | Padding over (L,N,Seed,0x80) | K            | X  | additionBlock  |
 * size in byte   | 16 | 4 | 4 | 64   | 1    |         0-7 => max=7         | 256 \ 8 = 32 | 16 |       16       |
 *
 */
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_IV                MCUXCLAES_BLOCK_SIZE
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_L                 (4)
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_N                 (4)
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_SEED              MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES256
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_0X80              (1)
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_MAXPADDING        (7)
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_K_MAXSIZE         MCUXCLAES_AES256_KEY_SIZE
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_X                 MCUXCLAES_BLOCK_SIZE

#define MCUXCLRANDOMMODES_CTRDRBG_DERIVATIONFUNCTION_CPUWA_MAXSIZE     (\
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_IV + \
                                                                        MCUXCLCORE_NUM_OF_CPUWORDS_CEIL( \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_L + \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_N + \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_SEED + \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_0X80 + \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_MAXPADDING) * sizeof(uint32_t) + \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_K_MAXSIZE + \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_AES256_DF_X + \
                                                                        MCUXCLRANDOMMODES_CTRDRBG_BCC_CPUWA_SIZE \
                                                                      )

/*
 * Description of how much cpuWa mcuxClRandomModes_CtrDrbg_UpdateState uses at most, i.e. for the AES-256 CTR_DRBG case
 *
 * cpuWa          | Seed                                             |
 * size in byte   | entropy_input size for AES-256 for the init case |
 *
 */
#define MCUXCLRANDOMMODES_CTRDRBG_UPDATESTATE_CPUWA_MAXSIZE     (MCUXCLRANDOMMODES_ALIGN_TO_AES_BLOCKSIZE(MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES256))


/*********************************************************************************************/
/*                                                                                           */
/* Definition of max workarea sizes allocated by function pointer functions                  */
/*     - instantiateAlgorithm                                                                */
/*     - reseedAlgorithm                                                                     */
/*     - generateAlgorithm                                                                   */
/*     - selftestAlgorithm                                                                   */
/*                                                                                           */
/*********************************************************************************************/
#define MCUXCLRANDOMMODES_CTRDRBG_AES256_INIT_SEEDMATERIAL_SIZE  (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLCORE_MAX(MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES256, MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES256)))
/*
 * Description of how much cpuWa mcuxClRandomModes_CtrDrbg_instantiateAlgorithm uses at most
 *
 * cpuWa          | Seed                                   | cpuWa used by called functions |
 * size in byte   | entropy_input size for the init case   | Max(cpuWaDF, cpuWaUpdateState) |
 *
 */
#define MCUXCLRANDOMMODES_CTRDRBG_INSTANTIATEALGO_CPUWA_MAXSIZE (       \
        MCUXCLRANDOMMODES_CTRDRBG_AES256_INIT_SEEDMATERIAL_SIZE + \
        MCUXCLCORE_MAX( \
            MCUXCLRANDOMMODES_CTRDRBG_DERIVATIONFUNCTION_CPUWA_MAXSIZE, \
            MCUXCLRANDOMMODES_CTRDRBG_UPDATESTATE_CPUWA_MAXSIZE         \
        ) \
    )

#define MCUXCLRANDOMMODES_CTRDRBG_AES256_RESEED_SEEDMATERIAL_SIZE  (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLCORE_MAX(MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES256, MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES256)))
/*
 * Description of how much cpuWa mcuxClRandomModes_CtrDrbg_reseedAlgorithm uses at most
 *
 * cpuWa          | Seed                                     | cpuWa used by called functions |
 * size in byte   | entropy_input size for the reseed case   | Max(cpuWaDF, cpuWaUpdateState) |
 *
 */
#define MCUXCLRANDOMMODES_CTRDRBG_RESEEDALGO_CPUWA_MAXSIZE (       \
        MCUXCLRANDOMMODES_CTRDRBG_AES256_RESEED_SEEDMATERIAL_SIZE + \
        MCUXCLCORE_MAX( \
            MCUXCLRANDOMMODES_CTRDRBG_DERIVATIONFUNCTION_CPUWA_MAXSIZE, \
            MCUXCLRANDOMMODES_CTRDRBG_UPDATESTATE_CPUWA_MAXSIZE         \
        ) \
    )

#define MCUXCLRANDOMMODES_CTRDRBG_AES256_GENERATE_ADDITIONALINPUT_SIZE  (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_SEEDLEN_CTR_DRBG_AES256))
/*
 * Description of how much cpuWa mcuxClRandomModes_CtrDrbg_generateAlgorithm uses at most
 *
 * cpuWa          | additional input | cpuWa used by called functions |
 * size in byte   |     seedlen      |        cpuWaUpdateState        |
 *
 */
#define MCUXCLRANDOMMODES_CTRDRBG_GENERATEALGO_CPUWA_MAXSIZE (       \
        MCUXCLRANDOMMODES_CTRDRBG_AES256_GENERATE_ADDITIONALINPUT_SIZE + \
        MCUXCLRANDOMMODES_CTRDRBG_UPDATESTATE_CPUWA_MAXSIZE \
    )


/*********************************************************************************************/
/*                                                                                           */
/* Definition of max workarea sizes allocated by function pointer functions in test mode     */
/*     - initFunction                                                                        */
/*     - reseedFunction                                                                      */
/*     - generateFunction                                                                    */
/*                                                                                           */
/*********************************************************************************************/

/*
 * Description of how much cpuWa mcuxClRandomModes_TestMode_initFunction uses at most
 *
 * cpuWa          | Call to instantiateAlgo |
 * size in byte   | cpuWaInstantiateAlgo   |
 *
 */
#define MCUXCLRANDOMMODES_TESTMODE_INIT_CPUWA_MAXSIZE ( MCUXCLRANDOMMODES_CTRDRBG_INSTANTIATEALGO_CPUWA_MAXSIZE )

/*
 * Description of how much cpuWa mcuxClRandomModes_TestMode_reseedFunction uses at most
 *
 * cpuWa          | Call to reseedAlgo |
 * size in byte   |  cpuWaReseedAlgo   |
 *
 */
#define MCUXCLRANDOMMODES_TESTMODE_RESEED_CPUWA_MAXSIZE ( MCUXCLRANDOMMODES_CTRDRBG_RESEEDALGO_CPUWA_MAXSIZE )

/*
 * Description of how much cpuWa mcuxClRandomModes_generateFunction_PrDisabled/PTG3 uses at most
 *
 * cpuWa          | Call(s) to reseedFunc | Call(s) to generateAlgo |
 * size in byte   |    cpuWaReseedFunc    |    cpuWaGenerateAlgo    |
 *
 */
#define MCUXCLRANDOMMODES_TESTMODE_GENERATE_CPUWA_MAXSIZE ( \
            MCUXCLCORE_MAX( \
                MCUXCLRANDOMMODES_TESTMODE_RESEED_CPUWA_MAXSIZE, \
                MCUXCLRANDOMMODES_CTRDRBG_GENERATEALGO_CPUWA_MAXSIZE) \
        )

/*
 * Description of how much cpuWa mcuxClRandomModes_TestMode_selftestFunction uses at most
 */
#define MCUXCLRANDOMMODES_TESTMODE_SELFTEST_CPUWA_MAXSIZE 4u

/*********************************************************************************************/
/*                                                                                           */
/* Definition of max workarea sizes allocated by function pointer functions in normal mode   */
/*     - initFunction                                                                        */
/*     - reseedFunction                                                                      */
/*     - generateFunction                                                                    */
/*     - selftestFunction                                                                    */
/*                                                                                           */
/*********************************************************************************************/

/*
 * Description of how much cpuWa mcuxClRandomModes_NormalMode_initFunction uses at most
 *
 * cpuWa          | Seed                                   | Call to instantiateAlgo |
 * size in byte   | entropy_input size for the init case   |  cpuWaInstantiateAlgo   |
 *
 */
#define MCUXCLRANDOMMODES_NORMALMODE_INIT_CPUWA_MAXSIZE ( \
            MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES256) + \
            MCUXCLRANDOMMODES_CTRDRBG_INSTANTIATEALGO_CPUWA_MAXSIZE \
        )

/*
 * Description of how much cpuWa mcuxClRandomModes_NormalMode_reseedFunction uses at most
 *
 * cpuWa          | Seed                                     | Call to reseedAlgo |
 * size in byte   | entropy_input size for the reseed case   |  cpuWaReseedAlgo   |
 *
 */
#define MCUXCLRANDOMMODES_NORMALMODE_RESEED_CPUWA_MAXSIZE ( \
            MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES256) + \
            MCUXCLRANDOMMODES_CTRDRBG_RESEEDALGO_CPUWA_MAXSIZE \
        )

/*
 * Description of how much cpuWa mcuxClRandomModes_generateFunction_PrDisabled/PTG3 uses at most
 *
 * cpuWa          | Call(s) to reseedFunc | Call(s) to generateAlgo |
 * size in byte   |    cpuWaReseedFunc    |    cpuWaGenerateAlgo    |
 *
 */
#define MCUXCLRANDOMMODES_NORMALMODE_GENERATE_CPUWA_MAXSIZE ( \
            MCUXCLCORE_MAX( \
                MCUXCLRANDOMMODES_NORMALMODE_RESEED_CPUWA_MAXSIZE, \
                MCUXCLRANDOMMODES_CTRDRBG_GENERATEALGO_CPUWA_MAXSIZE) \
        )

/*
 * Description of how much cpuWa mcuxClRandomModes_NormalMode_selftestFunction uses at most
 *
 * cpuWa          | Call(s) to initFunc | Call(s) to reseedFunc | Call(s) to generateFunc |
 * size in byte   |    cpuWaInitFunc    |    cpuWaReseedFunc    |    cpuWaGenerateFunc    |
 */
/*
 * A union is used here to determine the maximum size of the cpu wa. This type is NOT intended to be used in the code.
 * Usage of nested MAX is not possible here as the evaluated lines getting too long for the build system.
 */
typedef union
{
    uint8_t mcuxClRandomModes_Testmode_Init_CpuWa_Maxsize[MCUXCLRANDOMMODES_TESTMODE_INIT_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Testmode_Reseed_CpuWa_Maxsize[MCUXCLRANDOMMODES_TESTMODE_RESEED_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Testmode_Generate_CpuWa_Maxsize[MCUXCLRANDOMMODES_TESTMODE_GENERATE_CPUWA_MAXSIZE];
} mcuxClRandomModes_Internal_MaxUnion_Selftest_WaCpu_t;
#define MCUXCLRANDOMMODES_NORMALMODE_SELFTEST_CPUWA_MAXSIZE ( \
            sizeof(mcuxClRandom_ModeDescriptor_t) + \
            sizeof(mcuxClRandomModes_Context_CtrDrbg_Aes256_t) + \
            sizeof(mcuxClRandomModes_Internal_MaxUnion_Selftest_WaCpu_t) \
        )


/*********************************************************************************************/
/*                                                                                           */
/* Definition of workarea sizes for API functions                                            */
/*     - init                                                                                */
/*     - reseed                                                                              */
/*     - generate                                                                            */
/*     - selftest                                                                            */
/*                                                                                           */
/*********************************************************************************************/

/*
 * Maximum cpuWa size for init
 *
 * A union is used here to determine the maximum size of the cpu wa. This type is NOT intended to be used in the code.
 * Usage of nested MAX is not possible here as the evaluated lines getting too long for the build system.
 */
typedef union
{
    uint8_t mcuxClRandomModes_Normalmode_Init_CpuWa_Maxsize[MCUXCLRANDOMMODES_NORMALMODE_INIT_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Testmode_Init_CpuWa_Maxsize[MCUXCLRANDOMMODES_TESTMODE_INIT_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Init_CpuWa_Size_Min[4u];
} mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Init_t;
#define MCUXCLRANDOMMODES_INIT_WACPU_SIZE_MAX (sizeof(mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Init_t))


/*
 * Maximum cpuWa size for reseed
 *
 * A union is used here to determine the maximum size of the cpu wa. This type is NOT intended to be used in the code.
 * Usage of nested MAX is not possible here as the evaluated lines getting too long for the build system.
 */
typedef union
{
    uint8_t mcuxClRandomModes_Normalmode_Reseed_CpuWa_Maxsize[MCUXCLRANDOMMODES_NORMALMODE_RESEED_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Testmode_Reseed_CpuWa_Maxsize[MCUXCLRANDOMMODES_TESTMODE_RESEED_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Reseed_CpuWa_Size_Min[4u];
} mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Reseed_t;
#define MCUXCLRANDOMMODES_RESEED_WACPU_SIZE_MAX (sizeof(mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Reseed_t))


/*
 * Maximum cpuWa size for generate
 *
 * A union is used here to determine the maximum size of the cpu wa. This type is NOT intended to be used in the code.
 * Usage of nested MAX is not possible here as the evaluated lines getting too long for the build system.
 */
typedef union
{
    uint8_t mcuxClRandomModes_Normalmode_Generate_CpuWa_Maxsize[MCUXCLRANDOMMODES_NORMALMODE_GENERATE_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Testmode_Generate_CpuWa_Maxsize[MCUXCLRANDOMMODES_TESTMODE_GENERATE_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Generate_WaCpu_Size_Min[4u];
} mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Generate_t;
#define MCUXCLRANDOMMODES_GENERATE_WACPU_SIZE_MAX (sizeof(mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Generate_t))

/*
 * Maximum cpuWa size for selftest
 *
 * A union is used here to determine the maximum size of the cpu wa. This type is NOT intended to be used in the code.
 * Usage of nested MAX is not possible here as the evaluated lines getting too long for the build system.
 */
typedef union
{
    uint8_t mcuxClRandomModes_Normalmode_Selftest_CpuWa_Maxsize[MCUXCLRANDOMMODES_NORMALMODE_SELFTEST_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Testmode_Selftest_CpuWa_Maxsize[MCUXCLRANDOMMODES_TESTMODE_SELFTEST_CPUWA_MAXSIZE];
    uint8_t mcuxClRandomModes_Selftest_WaCpu_Min_Size[4u];
} mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Selftest_t;
#define MCUXCLRANDOMMODES_SELFTEST_WACPU_SIZE_MAX (sizeof(mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_Selftest_t))

/*
 * Maximum cpuWa size over all API functions
 *
 * A union is used here to determine the maximum size of the cpu wa. This type is NOT intended to be used in the code.
 * Usage of nested MAX is not possible here as the evaluated lines getting too long for the build system.
 */
typedef union
{
    uint8_t mcuxClRandomModes_Init_WaCpu_Size_Max[MCUXCLRANDOMMODES_INIT_WACPU_SIZE_MAX];
    uint8_t mcuxClRandomModes_Reseed_WaCpu_Size_Max[MCUXCLRANDOMMODES_RESEED_WACPU_SIZE_MAX];
    uint8_t mcuxClRandomModes_Generate_WaCpu_Size_Max[MCUXCLRANDOMMODES_GENERATE_WACPU_SIZE_MAX];
    uint8_t mcuxClRandomModes_Selftest_WaCpu_Size_Max[MCUXCLRANDOMMODES_SELFTEST_WACPU_SIZE_MAX];
} mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_t;
#define MCUXCLRANDOMMODES_CPUWA_MAXSIZE (sizeof(mcuxClRandomModes_Internal_MaxUnion_WaCpu_MaxSize_t))

#endif /* MCUXCLRANDOMMODES_INTERNAL_SIZEDEFINITIONS_H_ */
