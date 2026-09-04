/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2026 NXP                                       */
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

#include <mcuxClCore_Platform.h>
#include <mcuxClMemory_Constants.h>
#include <mcuxClMemory_Types.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClSgi_SfrAccess.h>
#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG)
#include <internal/mcuxClTrng_SfrAccess.h>
#include <internal/mcuxClTrng_Internal_SA_TRNG.h>
#endif /* MCUXCL_FEATURE_TRNG_SA_TRNG */
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_Copy_Reversed_Internal.h>
#include <internal/mcuxCsslMemory_Internal_Copy_arm_asm.h>
#include <internal/mcuxCsslMemory_Internal_Compare_arm_asm.h>
#include <internal/mcuxCsslMemory_Internal_CopyRev_arm_asm.h>
#include <internal/mcuxCsslMemory_Internal_CompareRev_arm_asm.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_copy_int)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_copy_int
(
    uint8_t * pDst,
    uint8_t const * pSrc,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_copy_int);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_Copy_arm_asm(pDst, pSrc, length));

    /* In case of source or destination addresses are one of the following:
     *     - SGI SFRs: there is no guarantee that we can read back what we wrote due to
     *                 some of them are WRITE ONLY or change its value on read or XOR read/write.
     *     - TRNG ENT registers: Always return different values
     * Hence we skip comparing.
     */
    uint32_t SGILastAddr  = (uint32_t) &((SGI_STRUCT_NAME *) SGI_SFR_BASE)->SGI_SFR_NAME(MODULE_ID);
#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG)
    uint32_t TrngEntFirstAddr = (uint32_t) &((TRNG_SFR_BASE->TRNG_SFR_NAME(ENT))[0]);
    uint32_t TrngEntLastAddr  = (uint32_t) &((TRNG_SFR_BASE->TRNG_SFR_NAME(ENT))[MCUXCLTRNG_SA_TRNG_NUMBEROFENTREGISTERS]);
#endif /* MCUXCL_FEATURE_TRNG_SA_TRNG */

    if (
        /* SGI */
          (((((uint32_t) pSrc) < (uint32_t)SGI_SFR_BASE) || (((uint32_t) pSrc) > SGILastAddr))
        && ((((uint32_t) pDst) < (uint32_t)SGI_SFR_BASE) || (((uint32_t) pDst) > SGILastAddr)))
#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG)
        /* TRNG: We never write to entropy, hence only pSrc check */
        && ((((uint32_t) pSrc) < TrngEntFirstAddr) || (((uint32_t) pSrc) > TrngEntLastAddr))
#endif /* MCUXCL_FEATURE_TRNG_SA_TRNG */

    )
    {
        /*
        * Compare copied data to ensure copy operation performed properly
        * As internal copy function doesn't have session reference to trigger early exit,
        * we will left SC unbalanced to trigger FA from upper layer
        */
        MCUX_CSSL_DI_RECORD(compareParams, (uint32_t) pDst);
        MCUX_CSSL_DI_RECORD(compareParams, (uint32_t) pSrc);
        MCUX_CSSL_DI_RECORD(compareParams, length);
        MCUX_CSSL_FP_FUNCTION_CALL(clRetval, mcuxCsslMemory_FastCompare_arm_asm(pDst, pSrc, length));
        MCUX_CSSL_DI_EXPUNGE(robustCmpStatus, clRetval);
        if(MCUXCSSLMEMORY_STATUS_EQUAL != clRetval)
        {
            MCUX_CSSL_DI_RECORD(compareParams, clRetval);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_copy_int,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_Copy_arm_asm),
        MCUX_CSSL_FP_CONDITIONAL(
                                (((((uint32_t) pSrc) < (uint32_t) SGI_SFR_BASE) || (((uint32_t) pSrc) > SGILastAddr))
                              &&  ((((uint32_t) pDst) < (uint32_t) SGI_SFR_BASE) || (((uint32_t) pDst) > SGILastAddr)))
#if defined(MCUXCL_FEATURE_TRNG_SA_TRNG)
                              &&  ((((uint32_t) pSrc) < TrngEntFirstAddr) || (((uint32_t) pSrc) > TrngEntLastAddr))
#endif /* MCUXCL_FEATURE_TRNG_SA_TRNG*/
                              ,
                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_FastCompare_arm_asm))
        );
}

#ifdef MCUXCL_FEATURE_INTERNAL_MEMORY_COPY_WITHOUT_DST_INCREMENT
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_copy_withoutDstIncrement_int)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_copy_withoutDstIncrement_int
(
    uint8_t * pDst,
    uint8_t const * pSrc,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_copy_withoutDstIncrement_int);

    // TODO CLNS-14121: Implement mcuxClMemory_copy_withoutDstIncrement_int in asm
    const uint8_t *pData = pSrc;

    /* Process byte-wise until word-size aligned buffer remains */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("pointer cast to integer for alignment check")
    while((0u < length) && (0u != (((uint32_t)pData) & (sizeof(uint32_t) - 1u))))
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()
    {
        *pDst = *pData;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
        pData++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        length--;
    }

    /* Process word-wise full words of remaining buffer */
    while(sizeof(uint32_t) <= length)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pData and pDst is 32-bit aligned")
        *((uint32_t*)pDst)  = *(const uint32_t *)pData;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
        pData += sizeof(uint32_t);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        length -= sizeof(uint32_t);
    }

    /* Process byte-wise until the end of Data */
    while(0u < length)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
        *pDst = *pData;
        pData++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        length--;
    }

    MCUX_CSSL_DI_EXPUNGE(identifier /* Not used */, (uint32_t) pData + (uint32_t) pDst);   // Balance the SC with initial pDst and incremented pData
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_copy_withoutDstIncrement_int);
}
#endif /* MCUXCL_FEATURE_INTERNAL_MEMORY_COPY_WITHOUT_DST_INCREMENT */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_copy_reversed_int)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_copy_reversed_int
(
    uint8_t * pDst,
    uint8_t const * pSrc,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_copy_reversed_int);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_CopyRev_arm_asm(pDst, pSrc, length));
    /*
     * Compare copied data to ensure copy operation performed properly
     * As internal copy function doesn't have session reference to trigger early exit,
     * we will left SC unbalanced to trigger FA from upper layer
     */
    MCUX_CSSL_DI_RECORD(compareParams, pDst);
    MCUX_CSSL_DI_RECORD(compareParams, pSrc);
    MCUX_CSSL_DI_RECORD(compareParams, length);
    MCUX_CSSL_FP_FUNCTION_CALL(clRetval, mcuxCsslMemory_FastCompareRev_arm_asm(pDst, pSrc, length));
    MCUX_CSSL_DI_EXPUNGE(robustCmpStatus, clRetval);
    if(MCUXCSSLMEMORY_STATUS_EQUAL != clRetval)
    {
        MCUX_CSSL_DI_RECORD(compareParams, clRetval);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_copy_reversed_int,
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_CopyRev_arm_asm),
                                    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_FastCompareRev_arm_asm));
}