/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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

/** @file  mcuxClPrng_SCM.c
 *  @brief Implementation of the non-cryptographic PRNG functions using SCM. */

#include <mcuxClBuffer.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>

#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG)
#include <internal/mcuxClTrng_Internal.h>
#endif /* MCUXCL_FEATURE_TRNG_SA_TRNG */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPrng_reseed)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPrng_reseed(mcuxClSession_Handle_t pSession)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPrng_reseed);

    #if defined(MCUXCL_FEATURE_TRNG_SA_TRNG)
        /* Generate entropy using the TRNG */

        /* Allocate memory for the seed */
        uint32_t prngSeed[1] = {0U};

        /* Record DI for mcuxClTrng_getEntropyInput */
        MCUX_CSSL_DI_RECORD(trngOutputSize, sizeof(uint32_t));

        /* Call TRNG initialization function to ensure it's properly configured for upcoming TRNG accesses */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClTrng_Init(pSession));

        /* Generate entropy input using the TRNG */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(
            mcuxClTrng_getEntropyInput(pSession, prngSeed, sizeof(uint32_t))
        );

        #if defined(MCUXCL_FEATURE_PRNG_SGI_SFRSEED)
            /* Set the Sfr seed */
            mcuxClSgi_Sfr_writeSfrSeed(prngSeed[0]);
        #elif defined(MCUXCL_FEATURE_PRNG_SGI)
            /* Reseed the PRNG SW Seed */
            mcuxClSgi_Sfr_writePrngSwSeed(prngSeed[0]);
        #endif /* MCUXCL_FEATURE_PRNG_SGI_SFRSEED */
    #else
        // Put pragmas for compiler if needed to prevent conversion of warning to error
        #pragma message("PRNG cannot be reseeded. Entropy input for seeding the PRNG is not enabled in the platform.")
    #endif /* MCUXCL_FEATURE_TRNG_SA_TRNG */

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPrng_reseed
    #if defined(MCUXCL_FEATURE_TRNG_SA_TRNG)
        ,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_Init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_getEntropyInput)
    #endif /* MCUXCL_FEATURE_TRNG_SA_TRNG */
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPrng_generate_word)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClPrng_generate_word(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPrng_generate_word);

    MCUXCLPRNG_INIT()

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PRNG SFR address")
    MCUXCLPRNG_GET_WORD(randomWord);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

    MCUXCLPRNG_RESTORE()

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPrng_generate_word, randomWord);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPrng_generate_Internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPrng_generate_Internal(
    uint8_t*              pOut,
    uint32_t              outLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPrng_generate_Internal);

    MCUX_CSSL_DI_RECORD(sumOfPassedInputParams, (uint32_t)pOut);
    MCUX_CSSL_DI_RECORD(sumOfPassedInputParams, outLength);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("casting pointer to integer to check alignment.");
    const uint32_t dstAddress = (uint32_t) pOut;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER();

    uint32_t unalignedBytes = sizeof(uint32_t) - (dstAddress % sizeof(uint32_t));
    uint32_t leadingBytes = (unalignedBytes < outLength) ? unalignedBytes : outLength;
    uint32_t outLengthFullWords = (outLength - leadingBytes) / sizeof(uint32_t);
    uint32_t remainingBytes = (outLength - leadingBytes) % sizeof(uint32_t);

    MCUXCLPRNG_INIT()

    while (0u != leadingBytes) /* destination address is not aligned. */
    {
        MCUX_CSSL_DI_DONOTOPTIMIZE(pOut);
        MCUXCLPRNG_GET_WORD(randomWord);
        uint8_t randomByte = (uint8_t)(randomWord & 0xFFu);
        /* Write random byte to pOut */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pOut of outLength.");
        *(pOut++)= randomByte;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        leadingBytes--;
    }

    for(uint32_t i = 0u; i < outLengthFullWords; i++)
    {
        MCUX_CSSL_DI_DONOTOPTIMIZE(pOut);
        MCUXCLPRNG_GET_WORD(drawnRandom);
        /* Write random word to pOut */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pOut of outLength.");
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pOut is 32-bit aligned")
        *((uint32_t*)pOut) = drawnRandom;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        pOut = pOut + sizeof(uint32_t);
    }

    while(0u != remainingBytes)
    {
        MCUX_CSSL_DI_DONOTOPTIMIZE(pOut);
        MCUXCLPRNG_GET_WORD(randomWord);
        uint8_t randomByte = (uint8_t)(randomWord & 0xFFu);
        /* Write random byte to pOut */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pOut of outLength.");
        *(pOut++)= randomByte;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        remainingBytes--;
    }

    MCUXCLPRNG_RESTORE()

    MCUX_CSSL_DI_EXPUNGE(incrementedOutputPointer, (uint32_t)pOut);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPrng_generate_Internal);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPrng_generate)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPrng_generate(
    mcuxClSession_Handle_t pSession,
    mcuxCl_Buffer_t        pOut,
    uint32_t              outLength
)
{
    //TODO CLNS-10974 improve this function
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPrng_generate);

    uint32_t outLengthFullWords = (outLength / sizeof(uint32_t));
    MCUX_CSSL_DI_RECORD(sumOfBufferWrite1Params, outLengthFullWords * (uint32_t)pOut);
    MCUX_CSSL_DI_RECORD(sumOfBufferWrite1Params, outLengthFullWords * sizeof(uint32_t));

    MCUXCLPRNG_INIT()

    for(uint32_t i = 0u; i < outLengthFullWords; i++)
    {
        MCUXCLPRNG_GET_WORD(drawnRandom);

        /* Write to pOut */
        MCUX_CSSL_DI_RECORD(sumOfBufferWrite1Params, i * sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_ESCAPING_LOCAL_ADDRESS("Address drawnRandom is for internal use only and does not escape")
        MCUX_CSSL_DI_RECORD(sumOfBufferWrite1Params, (uint32_t) &drawnRandom);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_ESCAPING_LOCAL_ADDRESS()
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, i * sizeof(uint32_t), (const uint8_t*)(&drawnRandom), sizeof(uint32_t)));
    }

    uint32_t remainingBytes = (outLength % sizeof(uint32_t));
    if(0u != remainingBytes)
    {
        MCUXCLPRNG_GET_WORD(drawnRandomRemainingBytes);
        MCUX_CSSL_DI_RECORD(sumOfBufferWrite2Params, (uint32_t)pOut);
        MCUX_CSSL_DI_RECORD(sumOfBufferWrite2Params, outLengthFullWords * sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_ESCAPING_LOCAL_ADDRESS("Address drawnRandomRemainingBytes is for internal use only and does not escape")
        MCUX_CSSL_DI_RECORD(sumOfBufferWrite2Params, (uint32_t) &drawnRandomRemainingBytes);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_ESCAPING_LOCAL_ADDRESS()
        MCUX_CSSL_DI_RECORD(sumOfBufferWrite2Params, remainingBytes);

        /* Write to pOut */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, outLengthFullWords * sizeof(uint32_t), (const uint8_t*)(&drawnRandomRemainingBytes), remainingBytes));
    }

    MCUXCLPRNG_RESTORE()

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPrng_generate,
        (outLengthFullWords * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write)),
        MCUX_CSSL_FP_CONDITIONAL((0U != remainingBytes),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write)));
}
