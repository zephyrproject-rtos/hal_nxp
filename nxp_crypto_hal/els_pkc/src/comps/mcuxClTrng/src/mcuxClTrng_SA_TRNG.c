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

/** @file  mcuxClTrng_SA_TRNG.c
 *  @brief Implementation of the Trng component which provides APIs for
 *  handling of Trng random number. This file implements the functions
 *  declared in mcuxClTrng_Internal_Functions.h. */

#include <mcuxClToolchain.h>
#include <mcuxClSession.h>
#include <mcuxClMemory.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClTrng_SfrAccess.h>
#include <internal/mcuxClTrng_Internal.h>
#include <internal/mcuxClTrng_Internal_SA_TRNG.h>

/**
 *  @brief Initialization function for the SA_TRNG
 *
 *  This function performs all required steps to be done before SA_TRNG data can be requested via the function
 *  mcuxClTrng_getEntropyInput.
 *
 *  NOTES:
 *   - Enabling and configuration of the SA_TRNG shall be done before calling the Crypto Library.
 *     The Crypto Library requires the TRNG to be configured in dual oscillator mode. Therefore,
 *     this function simply verifies that the TRNG is configured in dual oscillator mode.
 *   - For performance it is recommended to put the TRNG in running mode immediately after configuration.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClTrng_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClTrng_Status_t) mcuxClTrng_Init(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClTrng_Init);

    MCUX_CSSL_FP_FUNCTION_CALL(retVal_checkConfig, mcuxClTrng_checkConfig());

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_Init, retVal_checkConfig,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_checkConfig));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClTrng_checkConfig)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClTrng_Status_t) mcuxClTrng_checkConfig(void)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClTrng_checkConfig);


    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_checkConfig, MCUXCLTRNG_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClTrng_getEntropyInput)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClTrng_Status_t) mcuxClTrng_getEntropyInput(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    uint32_t *pEntropyInput,
    uint32_t entropyInputLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClTrng_getEntropyInput);

    /* Call check configuration function to ensure the TRNG is properly configured for upcoming TRNG accesses */
    MCUX_CSSL_FP_FUNCTION_CALL(result_trngCheckConfig, mcuxClTrng_checkConfig());
    if(MCUXCLTRNG_STATUS_OK != result_trngCheckConfig)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, result_trngCheckConfig,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_checkConfig));
    }

    if ((NULL == pEntropyInput) || ((entropyInputLength % sizeof(uint32_t)) != 0u))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_ERROR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_checkConfig));
    }

    /* Write 1 to clear ERR flag. */
    MCUXCLTRNG_SFR_BITSET(MCTL, ERR);

    /* Put TRNG in running mode (clear PRGM bit) in case it has not been done before. */
    MCUXCLTRNG_SFR_BITCLEAR(MCTL, PRGM);

    /* Count the observed number of TRNG errors */
    uint32_t noOfTrngErrors = 0u;

    /*****************************************************************************/
    /* Entropy generation process has finished successfully (ENT_VAL bit == 1).  */
    /* Copy out as much entropy as requested                                     */
    /*****************************************************************************/

    /* Copy full words of entropy.
     * NOTE: Memory_copy is not used since it copies byte-wise from SFR while only word-wise SFR access is allowed.
     */
    uint32_t entropyInputWordLength = (entropyInputLength >> 2u);
    uint32_t *pDest = pEntropyInput;

    /* The subsequent loop to draw TRNG words is started with an offset to ensure that the last TRNG word drawn within the loop
    *  is the last word in the TRNG entropy register. This will trigger another TRNG entropy generation and reduces the time to wait
    *  for the TRNG to be ready when this function is called the next time.
    */
    uint32_t offset = MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS - (entropyInputWordLength % MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS);

    /* Wait until TRNG entropy generation is ready.
     * If TRNG hardware error detected return with MCUXCLTRNG_STATUS_FAULT_ATTACK.
     */
    MCUXCLTRNG_SA_TRNG_WAITFORREADY(noOfTrngErrors);

    for(uint32_t i = offset; i < (entropyInputWordLength + offset); i++)
    {
        /* When i is a multiple of the TRNG output buffer size (MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS) wait until new entropy words have been generated. */
        if((i % MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS) == 0u)
        {
            /* Wait until TRNG entropy generation is ready, If TRNG hardware error detected return with MCUXCLTRNG_STATUS_FAULT_ATTACK. */
            MCUXCLTRNG_SA_TRNG_WAITFORREADY(noOfTrngErrors);
        }
        /* Copy word of entropy into destination buffer. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pDest can't be larger than max(uint32_t)")
        *pDest = MCUXCLTRNG_SFR_READ(ENT)[i % MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS];
        /* Increment pDest to point to the next word. */
        pDest++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }

    MCUX_CSSL_DI_RECORD(trngOutputSize, entropyInputLength);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClTrng_getEntropyInput, MCUXCLTRNG_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClTrng_checkConfig));
}

