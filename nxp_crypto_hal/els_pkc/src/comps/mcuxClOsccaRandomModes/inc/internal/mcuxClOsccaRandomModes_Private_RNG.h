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
 * @file  mcuxClOsccaRandomModes_Private_RNG.h
 * @brief Internal TRNG definitions of mcuxClOsccaRandomModes component
 */

#ifndef MCUXCLOSCCARANDOMMODES_PRIVATE_RNG_H_
#define MCUXCLOSCCARANDOMMODES_PRIVATE_RNG_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <platform_specific_headers.h>
#include <mcuxClRandom_Types.h>
#include <internal/mcuxClOsccaRandomModes_SfrAccess.h>
#include <mcuxClOscca_PlatformTypes.h>

#define MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN 128U

typedef struct
{
    mcuxClRandom_Context_t common;
    uint32_t readOff;
    uint32_t writeOff;
    uint32_t entIdx;
    uint32_t bufferEmpty;
    uint32_t entropyBuf[MCUXCLOSCCARANDOMMODES_ENTROPY_BUFFER_LEN / sizeof(uint32_t)];
} mcuxClOsccaRandomModes_Context_RNG_t;

#define MCUXCLOSCCARANDOMMODES_FAIL_LIMIT_FOR_256BITS      ( 4459U )
#define MCUXCLOSCCARANDOMMODES_FAIL_LIMIT_FOR_10000BITS    ( 6264181U )

#define MCUXCLOSCCARANDOMMODES_SELFTEST_DELIVERY_LEN                      ( 32U )
#define MCUXCLOSCCARANDOMMODES_SELFTEST_POWERON_LEN                       ( 1250U )
#define MCUXCLOSCCARANDOMMODES_SELFTEST_CYCLICAL_LEN                      ( 1250U )
#define MCUXCLOSCCARANDOMMODES_SELFTEST_SIMPLE_LEN                        ( 32U )

#ifdef MCUXCL_FEATURE_OSCCA_RNG_256
#define MCUXCLOSCCARANDOMMODES_RNG_NUMBEROFENTREGISTERS           (8u)
#else
#error "Build configuration issue: OSCCA_RandomModes component included but neither OSCCA_RNG_256 nor OSCCA_RNG_512 are defined"
#endif

#define MCUXCLOSCCARANDOMMODES_RNG_INDEXOFLASTENTREGISTER         (MCUXCLOSCCARANDOMMODES_RNG_NUMBEROFENTREGISTERS - 1u)


#define MCUXCLOSCCARANDOMMODES_INIT_TRNG()                                    \
     do {                                                                    \
     /* init the TRNG */                                                     \
     /* set into programing mode */                                          \
     MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITSET(MCTL, PRGM);                     \
     /* set retry times to 3 before error happen */                          \
     MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITVALSET(SCMISC, RTY_CT, 3UL);         \
     /* mask 3 interrupts */                                                 \
     MCUXCLOSCCARANDOMMODES_TRNG0_SFR_WRITE(INT_MASK, 0u);                    \
     /* set into normal run mode */                                          \
     MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITCLEAR(MCTL, PRGM);                   \
     } while (false)

#define MCUXCLOSCCARANDOMMODES_CHECKSTATUS_TRNG()                             \
        (MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITREAD(MCTL, ENT_VAL) == 1U)

#define MCUXCLOSCCARANDOMMODES_AVAILABLE_TRNG()                               \
    do {                                                                     \
        if (MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITREAD(MCTL, ENT_VAL) == 1U)    \
        {                                                                    \
            break;                                                           \
        }                                                                    \
        if (MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITREAD(MCTL, ERR) == 1U)        \
        {                                                                    \
            /* set into programing mode */                                   \
            MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITSET(MCTL, PRGM);              \
            /* clear the error */                                            \
            MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITSET(MCTL, ERR);               \
            /* restart generating */                                         \
            MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITCLEAR(MCTL, PRGM);            \
        }                                                                    \
    } while (true)

#define MCUXCLOSCCARANDOMMODES_GETWORD_TRNG(offset)                           \
    MCUXCLOSCCARANDOMMODES_TRNG0_SFR_READ(ENT)[offset]

#endif /* MCUXCLOSCCARANDOMMODES_PRIVATE_RNG_H_ */
