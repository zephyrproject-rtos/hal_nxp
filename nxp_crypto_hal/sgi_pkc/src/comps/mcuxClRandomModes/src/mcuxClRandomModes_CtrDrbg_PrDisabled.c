/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024, 2026 NXP                                            */
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

#include <mcuxClRandomModes.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClRandomModes_MemoryConsumption.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>
#include <internal/mcuxClRandomModes_Private_NormalMode.h>
#include <internal/mcuxClRandomModes_Private_TestMode.h>
#include <internal/mcuxClRandomModes_Private_PrDisabled.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRandomModes_DrbgAlgorithmsDescriptor_t mcuxClRandomModes_DrbgAlgorithmsDescriptor_CtrDrbg_PrDisabled =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .instantiateAlgorithm = mcuxClRandomModes_CtrDrbg_instantiateAlgorithm,
    .reseedAlgorithm = mcuxClRandomModes_CtrDrbg_reseedAlgorithm,
    .generateAlgorithm = mcuxClRandomModes_CtrDrbg_generateAlgorithm,
    .selftestAlgorithm = mcuxClRandomModes_PrDisabled_selftestAlgorithm,
    .protectionTokenInstantiateAlgorithm = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_CtrDrbg_instantiateAlgorithm,
    .protectionTokenReseedAlgorithm = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_CtrDrbg_reseedAlgorithm,
    .protectionTokenGenerateAlgorithm = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_CtrDrbg_generateAlgorithm,
    .protectionTokenSelftestAlgorithm = MCUX_CSSL_FP_FUNCID_mcuxClRandomModes_PrDisabled_selftestAlgorithm
};

/* Constants for RNG health testing
 * This data does NOT originate from NIST DRBG test vectors (NIST SP 800-90A DRBGVS). It is provided by the RNG steering team. */
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG_512)
/* EntropyInput||Nonce = db6a6c4d5f17710eb1a65e7f82b390ffaf8f2c43f43eef29e4ffc350a2f475339c7b2d12259c9d */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_Entropy_Init_Aes128_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0x4d6c6adbu, 0x0e71175fu, 0x7f5ea6b1u, 0xff90b382u, 0x432c8fafu, 0x29ef3ef4u, 0x50c3ffe4u, 0x3375f4a2u,
    0x122d7b9cu, 0x009d9c25u
};
#elif MCUXCL_FEATURE_TRNG_SA_TRNG_256
/* EntropyInput||Nonce = db6a6c4d5f17710eb1a65e7f82b390ffaf8f2c43f43eef29e4ffc350a2f47533 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_Entropy_Init_Aes128_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  0x4d6c6adbu, 0x0e71175fu, 0x7f5ea6b1u, 0xff90b382u, 0x432c8fafu, 0x29ef3ef4u, 0x50c3ffe4u, 0x3375f4a2u
};
#endif /* (defined(MCUXCL_FEATURE_TRNG_SA_TRNG_512) || defined(MCUXCL_FEATURE_TRNG_DIGI_TRNG)) elif MCUXCL_FEATURE_TRNG_SA_TRNG_256 */
#endif /* MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128 */
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
/* EntropyInput||Nonce = 6c0764088dd3d30d93ed2cbbe6a8ac115098e458e74d34527ecd4183df2bb34a07c934a8793cc5c76a2a94cb7aa1fe2cd1b615d566b204 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_Entropy_Init_Aes192_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0x0864076cu, 0x0dd3d38du, 0xbb2ced93u, 0x11aca8e6u, 0x58e49850u, 0x52344de7u, 0x8341cd7eu, 0x4ab32bdfu,
    0xa834c907u, 0xc7c53c79u, 0xcb942a6au, 0x2cfea17au, 0xd515b6d1u, 0x0004b266u
};
#endif
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
/* EntropyInput||Nonce = 1f4d063d959fd773aa0d0f446ef8f5ed02dd4c1d5166efe2974ff6a1c81bb50f2d282d3814b1fa5dfee09592244d5e2235063b24361857ab7c25f4ec48ede801 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_Entropy_Init_Aes256_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0x3d064d1fu, 0x73d79f95u, 0x440f0daau, 0xedf5f86eu, 0x1d4cdd02u, 0xe2ef6651u, 0xa1f64f97u, 0x0fb51bc8u,
    0x382d282du, 0x5dfab114u, 0x9295e0feu, 0x225e4d24u, 0x243b0635u, 0xab571836u, 0xecf4257cu, 0x01e8ed48u
};
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
/* EntropyInputReseed = 3e3a397ad3edbd5d2505814805f51f20f356d541cb40f9 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_Entropy_Reseed_Aes128_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0x7a393a3eu, 0x5dbdedd3u, 0x48810525u, 0x201ff505u, 0x41d556f3u, 0x00f940cbu
};
#endif
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
/* EntropyInputReseed = 58c7b1da4f8b13a2acb8648ab51e36131ed31289c0924f2e6739e1b41c74039714d28c913573e5 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_Entropy_Reseed_Aes192_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0xdab1c758u, 0xa2138b4fu, 0x8a64b8acu, 0x13361eb5u, 0x8912d31eu, 0x2e4f92c0u, 0xb4e13967u, 0x9703741cu,
    0x918cd214u, 0x00e57335u
};
#endif
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
/* EntropyInputReseed = 685576d7db675fb95e23a646a935aa8e57ff1645cabdd851e3ee1f71d15cbe4af0d43973a5de33c5c873daf10bb4b4c8 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_Entropy_Reseed_Aes256_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0xd7765568u, 0xb95f67dbu, 0x46a6235eu, 0x8eaa35a9u, 0x4516ff57u, 0x51d8bdcau, 0x711feee3u, 0x4abe5cd1u,
    0x7339d4f0u, 0xc533dea5u, 0xf1da73c8u, 0xc8b4b40bu
};
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG_512)
/* ReturnedBits = 7a766353d1b809fd97d89219972debbce3f53d1be1b3dbddf1e4c2e15954e1338d0ff1f411326348f1e85a29b5feeb93554eb54a98c3b0e691f244dad72fd80b */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_RandomData_Aes128_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0x5363767au, 0xfd09b8d1u, 0x1992d897u, 0xbceb2d97u, 0x1b3df5e3u, 0xdddbb3e1u, 0xe1c2e4f1u, 0x33e15459u,
    0xf4f10f8du, 0x48633211u, 0x295ae8f1u, 0x93ebfeb5u, 0x4ab54e55u, 0xe6b0c398u, 0xda44f291u, 0x0bd82fd7u
};
#elif MCUXCL_FEATURE_TRNG_SA_TRNG_256
/* ReturnedBits = 3f790c4ffb8ac6d4293005eea51a153f532a9ba38cb545493186c7ed1ee5157dfc40409d8dc3596738d44df5423fa016e60bdc1f101cb40ba7f0db9007963f2c */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_RandomData_Aes128_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0x4f0c793fu, 0xd4c68afbu, 0xee053029u, 0x3f151aa5u, 0xa39b2a53u, 0x4945b58cu, 0xedc78631u, 0x7d15e51eu,
    0x9d4040fcu, 0x6759c38du, 0xf54dd438u, 0x16a03f42u, 0x1fdc0be6u, 0x0bb41c10u, 0x90dbf0a7u, 0x2c3f9607u
};
#endif /* (defined(MCUXCL_FEATURE_TRNG_SA_TRNG_512) || defined(MCUXCL_FEATURE_TRNG_DIGI_TRNG)) elif MCUXCL_FEATURE_TRNG_SA_TRNG_256 */
#endif /* MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128 */
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
/* ReturnedBits = 35f96c8d58335a75b537d3c794d6a363619bf76f1f28fe6595c9630e9e5e2770093c20bedffd17778105d52654cd27cd20ad46b8fba58926b2401344c8a493bc */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_RandomData_Aes192_PrDisabled[] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    0x8d6cf935u, 0x755a3358u, 0xc7d337b5u, 0x63a3d694u, 0x6ff79b61u, 0x65fe281fu, 0x0e63c995u, 0x70275e9eu,
    0xbe203c09u, 0x7717fddfu, 0x26d50581u, 0xcd27cd54u, 0xb846ad20u, 0x2689a5fbu, 0x441340b2u, 0xbc93a4c8u
};
#endif
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
/* ReturnedBits = e7a7e570c1f356561878fde178279f82e547de6388731b0ee479641e1153ccec2610d9576b76df106df94b434fd3424de080fe23395865fd3d7dfffc4cd2ccad */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t mcuxClRandomModes_TestVectors_RandomData_Aes256_PrDisabled[] = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    0x70e5a7e7u, 0x5656f3c1u, 0xe1fd7818u, 0x829f2778u, 0x63de47e5u, 0x0e1b7388u, 0x1e6479e4u, 0xeccc5311u,
    0x57d91026u, 0x10df766bu, 0x434bf96du, 0x4d42d34fu, 0x23fe80e0u, 0xfd655839u, 0xfcff7d3du, 0xadccd24cu
};
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t * const mcuxClRandomModes_TestVectors_Aes128_PrDisabled[MCUXCLRANDOMMODES_NO_OF_TESTVECTORS_PRDISABLED] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    mcuxClRandomModes_TestVectors_Entropy_Init_Aes128_PrDisabled,
    mcuxClRandomModes_TestVectors_Entropy_Reseed_Aes128_PrDisabled,
    mcuxClRandomModes_TestVectors_RandomData_Aes128_PrDisabled
};
#endif
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t * const mcuxClRandomModes_TestVectors_Aes192_PrDisabled[MCUXCLRANDOMMODES_NO_OF_TESTVECTORS_PRDISABLED] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    mcuxClRandomModes_TestVectors_Entropy_Init_Aes192_PrDisabled,
    mcuxClRandomModes_TestVectors_Entropy_Reseed_Aes192_PrDisabled,
    mcuxClRandomModes_TestVectors_RandomData_Aes192_PrDisabled
};
#endif
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const uint32_t * const mcuxClRandomModes_TestVectors_Aes256_PrDisabled[MCUXCLRANDOMMODES_NO_OF_TESTVECTORS_PRDISABLED] =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    mcuxClRandomModes_TestVectors_Entropy_Init_Aes256_PrDisabled,
    mcuxClRandomModes_TestVectors_Entropy_Reseed_Aes256_PrDisabled,
    mcuxClRandomModes_TestVectors_RandomData_Aes256_PrDisabled
};
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const mcuxClRandomModes_DrbgModeDescriptor_t mcuxClRandomModes_DrbgModeDescriptor_CtrDrbg_AES128_PrDisabled =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .pDrbgAlgorithms = &mcuxClRandomModes_DrbgAlgorithmsDescriptor_CtrDrbg_PrDisabled,
    .pDrbgVariant = &mcuxClRandomModes_DrbgVariantDescriptor_CtrDrbg_AES128,
    .pDrbgTestVectors = mcuxClRandomModes_TestVectors_Aes128_PrDisabled,
    .continuousReseedInterval = 0u
};
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const mcuxClRandomModes_DrbgModeDescriptor_t mcuxClRandomModes_DrbgModeDescriptor_CtrDrbg_AES192_PrDisabled =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .pDrbgAlgorithms = &mcuxClRandomModes_DrbgAlgorithmsDescriptor_CtrDrbg_PrDisabled,
    .pDrbgVariant = &mcuxClRandomModes_DrbgVariantDescriptor_CtrDrbg_AES192,
    .pDrbgTestVectors = mcuxClRandomModes_TestVectors_Aes192_PrDisabled,
    .continuousReseedInterval = 0u
};
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
static const mcuxClRandomModes_DrbgModeDescriptor_t mcuxClRandomModes_DrbgModeDescriptor_CtrDrbg_AES256_PrDisabled =
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    .pDrbgAlgorithms = &mcuxClRandomModes_DrbgAlgorithmsDescriptor_CtrDrbg_PrDisabled,
    .pDrbgVariant = &mcuxClRandomModes_DrbgVariantDescriptor_CtrDrbg_AES256,
    .pDrbgTestVectors = mcuxClRandomModes_TestVectors_Aes256_PrDisabled,
    .continuousReseedInterval = 0u
};
#endif


#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
/* Mode descriptors for NIST SP800-90A CTR_DRBGs with DRG.3 security level */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the generic structure member.")
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRandom_ModeDescriptor_t mcuxClRandomModes_mdCtrDrbg_AES128_DRG3 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .pOperationMode   = &mcuxClRandomModes_OperationModeDescriptor_NormalMode_PrDisabled,
    .pDrbgMode        = (void *) &mcuxClRandomModes_DrbgModeDescriptor_CtrDrbg_AES128_PrDisabled,
    .contextSize      = MCUXCLRANDOMMODES_CTR_DRBG_AES128_CONTEXT_SIZE,
    .auxParam         = (uint32_t *) &mcuxClRandomModes_OperationModeDescriptor_TestMode_PrDisabled,
    .securityStrength = MCUXCLRANDOMMODES_SECURITYSTRENGTH_CTR_DRBG_AES128
};
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the generic structure member.")
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRandom_ModeDescriptor_t mcuxClRandomModes_mdCtrDrbg_AES192_DRG3 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .pOperationMode   = &mcuxClRandomModes_OperationModeDescriptor_NormalMode_PrDisabled,
    .pDrbgMode        = (void *) &mcuxClRandomModes_DrbgModeDescriptor_CtrDrbg_AES192_PrDisabled,
    .contextSize      = MCUXCLRANDOMMODES_CTR_DRBG_AES192_CONTEXT_SIZE,
    .auxParam         = (uint32_t *) &mcuxClRandomModes_OperationModeDescriptor_TestMode_PrDisabled,
    .securityStrength = MCUXCLRANDOMMODES_SECURITYSTRENGTH_CTR_DRBG_AES192
};
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the generic structure member.")
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRandom_ModeDescriptor_t mcuxClRandomModes_mdCtrDrbg_AES256_DRG3 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .pOperationMode   = &mcuxClRandomModes_OperationModeDescriptor_NormalMode_PrDisabled,
    .pDrbgMode        = (void *) &mcuxClRandomModes_DrbgModeDescriptor_CtrDrbg_AES256_PrDisabled,
    .contextSize      = MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE,
    .auxParam         = (uint32_t *) &mcuxClRandomModes_OperationModeDescriptor_TestMode_PrDisabled,
    .securityStrength = MCUXCLRANDOMMODES_SECURITYSTRENGTH_CTR_DRBG_AES256
};
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
#endif

