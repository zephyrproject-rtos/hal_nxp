/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023, 2025 NXP                                            */
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

#ifndef MCUXCLRANDOMMODES_PRIVATE_PRDISABLED_H_
#define MCUXCLRANDOMMODES_PRIVATE_PRDISABLED_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClRandom_Types.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MCUXCLRANDOMMODES_TESTVECTORS_INDEX_ENTROPY_PRDISABLED        ( 0u)
#define MCUXCLRANDOMMODES_TESTVECTORS_INDEX_ENTROPY_RESEED_PRDISABLED ( 1u)
#define MCUXCLRANDOMMODES_TESTVECTORS_INDEX_RANDOMDATA_PRDISABLED     ( 2u)
#define MCUXCLRANDOMMODES_NO_OF_TESTVECTORS_PRDISABLED (MCUXCLRANDOMMODES_TESTVECTORS_INDEX_RANDOMDATA_PRDISABLED + 1u)

extern const mcuxClRandomModes_DrbgAlgorithmsDescriptor_t mcuxClRandomModes_DrbgAlgorithmsDescriptor_CtrDrbg_PrDisabled;

/* Internal function prototypes */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_PrDisabled_selftestAlgorithm, mcuxClRandomModes_selftestAlgorithm_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_PrDisabled_selftestAlgorithm(mcuxClSession_Handle_t pSession, mcuxClRandom_Context_t pTestCtx, mcuxClRandom_ModeDescriptor_t *pTestMode);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_PRIVATE_PRDISABLED_H_ */
