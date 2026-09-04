/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023, 2025-2026 NXP                                       */
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
 * @file  mcuxClResource_Internal_Types.h
 * @brief Internal type definitions for the mcuxClResource component
 */


#ifndef MCUXCLRESOURCE_INTERNAL_TYPES_H_
#define MCUXCLRESOURCE_INTERNAL_TYPES_H_

#include <platform_specific_headers.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClSession_Types.h>
#include <mcuxClResource_Types.h>


/**********************************************************/
/* IRQ number definitions                                 */
/**********************************************************/
#define MCUXCLRESOURCE_IRQ_DMA00    ((mcuxClResource_Interrupt_t) DMA_CH0_IRQ_NUMBER)
#define MCUXCLRESOURCE_IRQ_SGI      ((mcuxClResource_Interrupt_t) SGI_IRQ_NUMBER)
#define MCUXCLRESOURCE_IRQ_PKC      ((mcuxClResource_Interrupt_t) PKC_IRQ_NUMBER)
#ifdef MCUXCL_FEATURE_HW_LTC
#define MCUXCLRESOURCE_IRQ_LTC      ((mcuxClResource_Interrupt_t) LTC_IRQ_NUMBER)
#else
#define MCUXCLRESOURCE_IRQ_LTC      MCUXCLRESOURCE_IRQ_INVALID
#endif

#define MCUXCLRESOURCE_IRQ_CRC      MCUXCLRESOURCE_IRQ_INVALID
#define MCUXCLRESOURCE_IRQ_SC0      MCUXCLRESOURCE_IRQ_INVALID
#define MCUXCLRESOURCE_IRQ_TRNG0    ((mcuxClResource_Interrupt_t) 18u)
#define MCUXCLRESOURCE_IRQ_TRNG1    ((mcuxClResource_Interrupt_t) 19u)
#define MCUXCLRESOURCE_IRQ_DMA(ch)  mcuxClResource_inline_irq_dma(ch)
#define MCUXCLRESOURCE_IRQ_INVALID  ((mcuxClResource_Interrupt_t) 0xFFu)

/**
 * Inline function to get IRQ number of a DMA channel.
 *   IRQ_INVALID will be returned if DMA channel does not exist.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClResource_inline_irq_dma)
static inline mcuxClResource_Interrupt_t mcuxClResource_inline_irq_dma(mcuxClSession_Channel_t ch)
{
    mcuxClResource_Interrupt_t irq = MCUXCLRESOURCE_IRQ_INVALID;
#if DMA_CH_TOTAL > 0
    if ((uint32_t) DMA_CH_TOTAL > (uint32_t)ch)
    {
        uint32_t irq2 = GET_DMA_CHX_IRQ_NUMBER(((uint32_t) ch));
        irq = (mcuxClResource_Interrupt_t) irq2;
    }
#endif
    return irq;
}

/**********************************************************/
/* Hardware ID definitions                                */
/**********************************************************/
/**
 * Macro to get HW ID of a DMA channel.
 *   DMA channels 0 ~ (DMA_CH_TOTAL -1) is mapped to Hardware ID 0 ~ (DMA_CH_TOTAL -1);
 *   HWID_INVALID will be returned if DMA channel does not exist.
 */
#if DMA_CH_TOTAL > 0
#define MCUXCLRESOURCE_HWID_DMA(ch_)   \
    (  ((uint32_t) (ch_) < (uint32_t) DMA_CH_TOTAL)  \
     ? (mcuxClResource_HwId_t) (ch_) : MCUXCLRESOURCE_HWID_INVALID )
#else
#define MCUXCLRESOURCE_HWID_DMA(ch_)   \
    MCUXCLRESOURCE_HWID_INVALID
#endif

/**
 * Macro to get DMA channel of a HW ID.
 *   DMA channels 0 ~ (DMA_CH_TOTAL -1) is mapped to Hardware ID 0 ~ (DMA_CH_TOTAL -1);
 */
#define MCUXCLRESOURCE_DMACH(id_)  ((mcuxClSession_Channel_t)(id_))

#define MCUXCLRESOURCE_HWID_SGI      ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 0u)
#define MCUXCLRESOURCE_HWID_PKC      ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 1u)
#define MCUXCLRESOURCE_HWID_LTC      ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 2u)
#define MCUXCLRESOURCE_HWID_CRC      ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 3u)
#define MCUXCLRESOURCE_HWID_SC0      ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 4u)
#define MCUXCLRESOURCE_HWID_TRNG0    ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 5u)
#define MCUXCLRESOURCE_HWID_TRNG1    ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 6u)
#define MCUXCLRESOURCE_HWID_TOTAL    ((mcuxClResource_HwId_t) DMA_CH_TOTAL + 7u)  ///< total number of HW resource
#define MCUXCLRESOURCE_HWID_INVALID  ((mcuxClResource_HwId_t) 0xFFu)

/* Auxiliary definitions. */
#define MCUXCLRESOURCE_HWID_COPRO_0     MCUXCLRESOURCE_HWID_SGI    ///< the first co-processor (non-DMA) HW ID
#define MCUXCLRESOURCE_HWID_COPRO_LAST  MCUXCLRESOURCE_HWID_TRNG1  ///< the last co-processor (non-DMA) HW ID

/**
 * Macro and inline function to get HW ID corresponding to an IRQ.
 *   HWID_INVALID will be returned if IRQ does not exist.
 */
#define MCUXCLRESOURCE_HWID_IRQ(i)   mcuxClResource_inline_hwId_irq(i)
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClResource_inline_hwId_irq)
static inline mcuxClResource_HwId_t mcuxClResource_inline_hwId_irq(mcuxClResource_Interrupt_t interrupt)
{
    mcuxClResource_HwId_t hwId = MCUXCLRESOURCE_HWID_INVALID;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("(interrupt - MCUXCLRESOURCE_IRQ_DMA00) can't be negative when (MCUXCLRESOURCE_IRQ_DMA00 <= interrupt)")
    if (MCUXCLRESOURCE_IRQ_DMA00 <= interrupt)
    {
        hwId = MCUXCLRESOURCE_HWID_DMA(interrupt - MCUXCLRESOURCE_IRQ_DMA00);
    }
    return hwId;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
}

/* Macro and inline function to check if a hardware ID maps to a DMA channel. */
#define MCUXCLRESOURCE_HWID_IS_DMA(hwId)  mcuxClResource_inline_hwId_is_dma(hwId)
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClResource_inline_hwId_is_dma)
static inline bool mcuxClResource_inline_hwId_is_dma(mcuxClResource_HwId_t hwId)
{
#if DMA_CH_TOTAL > 0
    return ((mcuxClResource_HwId_t) DMA_CH_TOTAL > hwId);
#else
    return false;
#endif
}


/* Table element to record HW allocation. */
typedef struct
{
    mcuxClResource_HwStatus_t status;     ///< HW allocation status.
                                         ///  In case of multi-request by the same session, all request options are concatenated as status.
                                         ///  The last request option is stored in LSBits.
    mcuxClSession_Descriptor_t *session;  ///< The current session owning the HW.
                                         ///  When HW is available (not occupied), it is NULL.
} mcuxClResource_hwAllocation_t;

struct mcuxClResource_Context
{
    mcuxClResource_hwAllocation_t hwTable[MCUXCLRESOURCE_HWID_TOTAL];
};


/* HW is availabe if all request options are not set. */
#define MCUXCLRESOURCE_HWSTATUS_AVAILABLE  ((mcuxClResource_HwStatus_t) 0u)

/* Mask of all non-interruptible (HW request option) bits in status word. */
#define MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE_ALL_MASK  0xAAAAAAAAu

/* Macro to check if a HW is interruptible, i.e.,  */
/* none of request option(s) is non-interruptible. */
#define MCUXCLRESOURCE_HWSTATUS_CHECK_INTERRUPTABLE(status)  \
    (0u == ((status) & MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE_ALL_MASK))


#endif /* MCUXCLRESOURCE_INTERNAL_TYPES_H_ */
