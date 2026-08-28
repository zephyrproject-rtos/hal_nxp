/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxClRandomModes_MemoryConsumption.h
 * @brief Defines the memory consumption for the mcuxClRandom component
 */

#ifndef MCUXCLRANDOMMODES_MEMORYCONSUMPTION_H_
#define MCUXCLRANDOMMODES_MEMORYCONSUMPTION_H_

/**
 * @defgroup mcuxClRandomModes_MemoryConsumption mcuxClRandomModes_MemoryConsumption
 * @brief Defines the memory consumption for the @ref mcuxClRandom component
 * @ingroup mcuxClRandomModes
 * @{
 */

#define MCUXCLRANDOMMODES_PATCHMODE_DESCRIPTOR_SIZE     (20u)

#define MCUXCLRANDOMMODES_TESTMODE_DESCRIPTOR_SIZE     (20u)

#define MCUXCLRANDOMMODES_MAX_CPU_WA_BUFFER_SIZE                      (316u)

#define MCUXCLRANDOMMODES_INIT_WACPU_SIZE                             (288u)
#define MCUXCLRANDOMMODES_RESEED_WACPU_SIZE                           (256u)
#define MCUXCLRANDOMMODES_GENERATE_WACPU_SIZE                         (256u)
#define MCUXCLRANDOMMODES_SELFTEST_WACPU_SIZE                         (316u)
#define MCUXCLRANDOMMODES_UNINIT_WACPU_SIZE                           (0u)
#define MCUXCLRANDOMMODES_CHECKSECURITYSTRENGTH_WACPU_SIZE            (0u)
#define MCUXCLRANDOMMODES_CREATEPATCHMODE_WACPU_SIZE                  (0u)
#define MCUXCLRANDOMMODES_CREATETESTMODEFROMNORMALMODE_WACPU_SIZE     (0u)


#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
#define MCUXCLRANDOMMODES_CTR_DRBG_AES128_CONTEXT_SIZE ($(mcuxClRandomModes_Context_Aes128)u)
#define MCUXCLRANDOMMODES_CTR_DRBG_AES128_CONTEXT_SIZE_IN_WORDS ((MCUXCLRANDOMMODES_CTR_DRBG_AES128_CONTEXT_SIZE + sizeof(uint32_t) - 1u) / sizeof(uint32_t))
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
#define MCUXCLRANDOMMODES_CTR_DRBG_AES192_CONTEXT_SIZE ($(mcuxClRandomModes_Context_Aes192)u)
#define MCUXCLRANDOMMODES_CTR_DRBG_AES192_CONTEXT_SIZE_IN_WORDS ((MCUXCLRANDOMMODES_CTR_DRBG_AES192_CONTEXT_SIZE + sizeof(uint32_t) - 1u) / sizeof(uint32_t))
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
#define MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE (72u)
#define MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE_IN_WORDS ((MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE + sizeof(uint32_t) - 1u) / sizeof(uint32_t))
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
#define MCUXCLRANDOMMODES_TESTMODE_CTR_DRBG_AES128_INIT_ENTROPY_SIZE     ($(mcuxClRandomModes_TestMode_CtrDrbg_Aes128_Entropy_Input_Init_size)u)
#define MCUXCLRANDOMMODES_TESTMODE_CTR_DRBG_AES128_RESEED_ENTROPY_SIZE   ($(mcuxClRandomModes_TestMode_CtrDrbg_Aes128_Entropy_Input_Reseed_size)u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
#define MCUXCLRANDOMMODES_TESTMODE_CTR_DRBG_AES192_INIT_ENTROPY_SIZE     ($(mcuxClRandomModes_TestMode_CtrDrbg_Aes192_Entropy_Input_Init_size)u)
#define MCUXCLRANDOMMODES_TESTMODE_CTR_DRBG_AES192_RESEED_ENTROPY_SIZE   ($(mcuxClRandomModes_TestMode_CtrDrbg_Aes192_Entropy_Input_Reseed_size)u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
#define MCUXCLRANDOMMODES_TESTMODE_CTR_DRBG_AES256_INIT_ENTROPY_SIZE     (64u)
#define MCUXCLRANDOMMODES_TESTMODE_CTR_DRBG_AES256_RESEED_ENTROPY_SIZE   (48u)
#endif // MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256


#define MCUXCLRANDOMMODES_PATCHMODE_CONTEXT_SIZE        (4u)
#define MCUXCLRANDOMMODES_PATCHMODE_CONTEXT_SIZE_IN_WORDS ((MCUXCLRANDOMMODES_PATCHMODE_CONTEXT_SIZE + sizeof(uint32_t) - 1u) / sizeof(uint32_t))

/**
 * @}
 */ /* mcuxClRandomModes_MemoryConsumption */

#endif /* MCUXCLRANDOMMODES_MEMORYCONSUMPTION_H_ */
