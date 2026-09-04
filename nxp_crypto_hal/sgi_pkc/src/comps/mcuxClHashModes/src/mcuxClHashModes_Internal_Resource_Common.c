/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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

#include <mcuxClToolchain.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <internal/mcuxClDma_Utils_Sgi.h>
#include <internal/mcuxClDma_Drv.h>
#include <mcuxClDma_Types.h>
#include <internal/mcuxClDma_Resource.h>
#include <internal/mcuxClResource_Internal_Types.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClHashModes_Internal_Resource_Common.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

/**********************************************************
 * Helper functions
 **********************************************************/

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_HwRequest)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_HwRequest(
    mcuxClSession_Handle_t session,
    mcuxClSession_HwInterruptHandler_t pHwIrqHandler,
    uint32_t protectionToken_pHwIrqHandler,
    uint32_t requestOption
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_HwRequest);

    /* Request SGI hardware */
    /* The `requestOption` check for SGI hardware has been removed, as SGI is the only hardware in mcu_dci for Hash */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(
        session, MCUXCLRESOURCE_HWID_SGI,
        MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE,
        NULL, 0U)
    );


    const uint32_t sgiOption = MCUXCLHASHMODES_REQ_SGI & requestOption;
    const uint32_t dmaInputOption   = MCUXCLHASHMODES_REQ_DMA_INPUT & requestOption;
    const uint32_t dmaOutputOption  = MCUXCLHASHMODES_REQ_DMA_OUTPUT & requestOption;

    mcuxClSession_HwInterruptHandler_t dmaIsr = NULL;
    uint32_t protectionToken_dmaIsr = 0U;
    if((NULL != pHwIrqHandler) && (MCUXCLHASHMODES_REQ_SGI == sgiOption))
    {
        dmaIsr = pHwIrqHandler;
        protectionToken_dmaIsr = protectionToken_pHwIrqHandler;
    }

    MCUX_CSSL_FP_BRANCH_DECL(hashDmaOption);
    if ((MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption) && (MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption))
    {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_requestInputAndOutput(session, dmaIsr, protectionToken_dmaIsr));
        MCUX_CSSL_FP_BRANCH_POSITIVE(hashDmaOption, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_requestInputAndOutput));
    }
    else
    {
        if(MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption)
        {
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_request(
                session,
                mcuxClSession_getDmaInputChannel(session),
                dmaIsr,
                protectionToken_dmaIsr));
        }

        if(MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption)
        {
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_request(
                session,
                mcuxClSession_getDmaOutputChannel(session),
                dmaIsr,
                protectionToken_dmaIsr));
        }

        MCUX_CSSL_FP_BRANCH_NEGATIVE(hashDmaOption,
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_request)
            ),
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_request)
            )
        );
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_HwRequest,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(hashDmaOption, ((MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption) && (MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption))),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(hashDmaOption, ((MCUXCLHASHMODES_REQ_DMA_INPUT != dmaInputOption) || (MCUXCLHASHMODES_REQ_DMA_OUTPUT != dmaOutputOption))),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_HwRelease)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_HwRelease(
    mcuxClSession_Handle_t session,
    uint32_t releaseOption
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_HwRelease);

    /* Release the SGI hardware */
    /* The `releaseOption` check for SGI hardware has been removed, as SGI is the only hardware in mcu_dci for Hash */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_release(session->pResourceCtx, MCUXCLRESOURCE_HWID_SGI));

    const uint32_t dmaInputOption = MCUXCLHASHMODES_REQ_DMA_INPUT & releaseOption;
    const uint32_t dmaOutputOption = MCUXCLHASHMODES_REQ_DMA_OUTPUT & releaseOption;

    MCUX_CSSL_FP_BRANCH_DECL(hashDmaOption);
    if((MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption) && (MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption))
    {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_releaseInputAndOutput(session));
        MCUX_CSSL_FP_BRANCH_POSITIVE(hashDmaOption, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_releaseInputAndOutput));
    }
    else
    {
        if(MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption)
        {
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_release(session, mcuxClSession_getDmaInputChannel(session)));
        }
        if(MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption)
        {
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_release(session, mcuxClSession_getDmaOutputChannel(session)));
        }

        MCUX_CSSL_FP_BRANCH_NEGATIVE(hashDmaOption,
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_release)
            ),
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_release)
            )
        );
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHashModes_HwRelease,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(hashDmaOption, ((MCUXCLHASHMODES_REQ_DMA_INPUT == dmaInputOption) && (MCUXCLHASHMODES_REQ_DMA_OUTPUT == dmaOutputOption))),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(hashDmaOption, ((MCUXCLHASHMODES_REQ_DMA_INPUT != dmaInputOption) || (MCUXCLHASHMODES_REQ_DMA_OUTPUT != dmaOutputOption))),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_release)
    );
}
