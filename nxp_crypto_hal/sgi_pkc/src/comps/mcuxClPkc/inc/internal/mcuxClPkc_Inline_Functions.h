/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClPkc_Inline_Functions.h
 * @brief Inline functions for accessing PKC hardware IP
 */


#ifndef MCUXCLPKC_INLINE_FUNCTIONS_H_
#define MCUXCLPKC_INLINE_FUNCTIONS_H_


#include <platform_specific_headers.h>

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClPkc_Internal_Types.h>
#include <internal/mcuxClPkc_SfrAccess.h>
#include <internal/mcuxClPkc_BasicDefs.h>


/**********************************************************/
/* Inline functions for UPTR table and offsets            */
/**********************************************************/
/** Inline function to set the address of UPTRT (Universal pointer FUP table). */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_setUptrt)
static inline void mcuxClPkc_inline_setUptrt(const uint16_t * pUptrt)
{
    MCUX_CSSL_ANALYSIS_COVERITY_START_DEVIATE(MISRA_C_2012_Rule_11_4, "Convert pointer to address.")
    uint32_t uptrtAddr = (uint32_t) pUptrt;
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_DEVIATE(MISRA_C_2012_Rule_11_4)

    MCUXCLPKC_SFR_WRITE(UPTRT, uptrtAddr);
}

/** Inline function to get the address of UPTRT (Universal pointer FUP table). */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_getUptrt)
static inline uint16_t * mcuxClPkc_inline_getUptrt(void)
{
    uint32_t uptrtAddr = MCUXCLPKC_SFR_READ(UPTRT);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("Convert UPTRT address to pointer.")
    return (uint16_t *) uptrtAddr;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()
}

/** Inline function to convert CPU pointer to PKC offset. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_ptr2Offset)
static inline uint16_t mcuxClPkc_inline_ptr2Offset(const uint8_t * cpuPointer)
{
    MCUX_CSSL_ANALYSIS_COVERITY_START_DEVIATE(MISRA_C_2012_Rule_11_4, "calculate PKC operand offset.")
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(CERT_STR30_C, "it's a pointer to PKC operand, but not string literal.")

    uint32_t maskedAddress = (uint32_t) cpuPointer & MCUXCLPKC_RAM_OFFSET_MASK;

    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(CERT_STR30_C)
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_DEVIATE(MISRA_C_2012_Rule_11_4)

    return (uint16_t) maskedAddress;
}

/** Inline function to convert PKC offset to CPU pointer. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_offset2Ptr)
static inline uint8_t * mcuxClPkc_inline_offset2Ptr(uint16_t pkcOffset)
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("convert PKC operand offset to pointer.")

    uint32_t ptrAddress = (uint32_t) pkcOffset | (uint32_t) MCUXCLPKC_RAM_START_ADDRESS;
    uint8_t * ptr = (uint8_t *) ptrAddress;

    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

    return ptr;
}

/** Inline function to convert PKC offset to CPU word-aligned pointer. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_offset2PtrWord)
static inline uint32_t * mcuxClPkc_inline_offset2PtrWord(uint16_t pkcOffset)
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("convert PKC operand offset (PKC-word aligned) to pointer.")

    uint32_t ptrAddress = (uint32_t) pkcOffset | (uint32_t) MCUXCLPKC_RAM_START_ADDRESS;
    uint32_t * ptrWord = (uint32_t *) ptrAddress;

    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

    return ptrWord;
}


/**********************************************************/
/* Inline functions for parameter set 1 and 2             */
/**********************************************************/
/** Inline function to set packed MCLEN and (OP)LEN of parameter set 1. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_ps1_setLengthReg)
static inline void mcuxClPkc_inline_ps1_setLengthReg(uint32_t mclen_oplen)
{
    MCUXCLPKC_SFR_WRITE(LEN1, mclen_oplen);
}

/** Inline function to set packed MCLEN and (OP)LEN of parameter set 2. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_ps2_setLengthReg)
static inline void mcuxClPkc_inline_ps2_setLengthReg(uint32_t mclen_oplen)
{
    MCUXCLPKC_SFR_WRITE(LEN2, mclen_oplen);
}

/** Inline function to get packed MCLEN and (OP)LEN of parameter set 1. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_ps1_getLengthReg)
static inline uint32_t mcuxClPkc_inline_ps1_getLengthReg(void)
{
    uint32_t lengths = MCUXCLPKC_SFR_READ(LEN1);
    return lengths;
}

/** Inline function to get packed MCLEN and (OP)LEN of parameter set 2. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_ps2_getLengthReg)
static inline uint32_t mcuxClPkc_inline_ps2_getLengthReg(void)
{
    uint32_t lengths = MCUXCLPKC_SFR_READ(LEN2);
    return lengths;
}

/** Inline function to get (OP)LEN of parameter set 1. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_ps1_getOplen)
static inline uint16_t mcuxClPkc_inline_ps1_getOplen(void)
{
    uint32_t opLen =  MCUXCLPKC_SFR_BITREAD(LEN1, LEN);
    return (uint16_t) opLen;
}

/** Inline function to get MCLEN of parameter set 1. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_ps1_getMclen)
static inline uint16_t mcuxClPkc_inline_ps1_getMclen(void)
{
    uint32_t mcLen = MCUXCLPKC_SFR_BITREAD(LEN1, MCLEN);
    return (uint16_t) mcLen;
}


/**********************************************************/
/* Inline functions to wait PKC computations              */
/**********************************************************/
/** Inline function to wait until PKC finishes both on-going and pending calculations (if there is any). */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_waitForFinish)
static inline void mcuxClPkc_inline_waitForFinish(void)
{
    do{} while(0u != MCUXCLPKC_SFR_BITREAD(STATUS, ACTIV));
}

/** Inline function to wait until PKC is ready to accept next calculation (i.e., no pending calculation). */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_waitForReady)
static inline void mcuxClPkc_inline_waitForReady(void)
{
    do{} while(0u != MCUXCLPKC_SFR_BITREAD(STATUS, GOANY));
}

/** Inline function to wait PKC calculation and then get PKC status. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_waitForFinishGetStatus)
static inline uint32_t mcuxClPkc_inline_waitForFinishGetStatus(void)
{
    uint32_t pkc_status;
    do {
        pkc_status = MCUXCLPKC_SFR_READ(STATUS);
    } while (0u != (pkc_status & MCUXCLPKC_SFR_BITMSK(STATUS, ACTIV)));

    return pkc_status;
}


/**********************************************************/
/* Inline functions to manipulate CTRL RESET/STOP bits    */
/**********************************************************/
/**
 * Inline function to clear CTRL STOP bit and return CTRL (STOP bit cleared).
 * @return  the latest PKC CTRL (of which STOP bit is cleared).
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_clearStop)
static inline uint32_t mcuxClPkc_inline_clearStop(void)
{
    /* Clear STOP bit if it has been set. */
    uint32_t pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);
    if (0u != (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, STOP)))
    {
        MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl & (~ MCUXCLPKC_SFR_BITMSK(CTRL, STOP)));

        /* Poll until STOP bit is cleared. */
        do
        {
            pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);
        } while(0u != (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, STOP)));
    }

    return pkc_ctrl;
}

/**
 * Inline function to clear CTRL STOP bit and then set CTRL RESET bit.
 * @return the latest PKC CTRL (after clearing STOP and setting RESET bit)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_clearStop_setReset)
static inline uint32_t mcuxClPkc_inline_clearStop_setReset(void)
{
    uint32_t pkc_ctrl = mcuxClPkc_inline_clearStop();

    /* If RESET bit is not set, wait any on-going calculation and then set RESET bit. */
    if (0u == (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, RESET)))
    {
        pkc_ctrl |= MCUXCLPKC_SFR_BITMSK(CTRL, RESET);

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEAD_CODE("this function polls PKC SFR.")
        mcuxClPkc_inline_waitForFinish();
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEAD_CODE()

        /* Set RESET bit (also update other CTRL bits). */
        MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl);

        /* Poll until RESET bit is set. */
        do
        {
            pkc_ctrl = MCUXCLPKC_SFR_READ(CTRL);
        } while(0u == (pkc_ctrl & MCUXCLPKC_SFR_BITMSK(CTRL, RESET)));
    }

    return pkc_ctrl;
}

/**
 * Inline function to clear CTRL RESET bit and update other CTRL bits according to the given pkcCtrl.
 * @param[in] pkcCtrl  the current/desired CTRL value.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_clearReset)
static inline void mcuxClPkc_inline_clearReset(uint32_t pkcCtrl)
{
    const uint32_t pkc_ctrl = pkcCtrl & (~ MCUXCLPKC_SFR_BITMSK(CTRL, RESET));
    MCUXCLPKC_SFR_WRITE(CTRL, pkc_ctrl);

    /* Poll until RESET bit is cleared. */
    while (0u != (MCUXCLPKC_SFR_BITREAD(CTRL, RESET)))
    {}
}

/**
 * Inline function to set CFG.
 * According to PKC specification, this function will clear STOP and set RESET before updating CFG.
 * It will clear RESET before returning to caller.
 *
 * @param[in] pkcCfg  the desired CFG value.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_inline_setCfg)
static inline void mcuxClPkc_inline_setCfg(uint32_t pkcCfg)
{
    uint32_t pkcCtrl = mcuxClPkc_inline_clearStop_setReset();

    MCUXCLPKC_SFR_WRITE(CFG, pkcCfg);

    mcuxClPkc_inline_clearReset(pkcCtrl);
}


#endif /* MCUXCLPKC_INLINE_FUNCTIONS_H_ */
