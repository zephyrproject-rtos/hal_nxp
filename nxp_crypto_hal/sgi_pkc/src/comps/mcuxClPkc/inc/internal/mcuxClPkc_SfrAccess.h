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
 * @file  mcuxClPkc_SfrAccess.h
 * @brief Macros for abstracting PKC hardware SFR access
 */


#ifndef MCUXCLPKC_SFRACCESS_H_
#define MCUXCLPKC_SFRACCESS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClSession_Types.h>
#include <platform_specific_headers.h>


/****                                ****/
/**** PKC Hardware Abstraction Layer ****/
/****                                ****/

/**
 * 2 different PKC hardware definition headers are supported.
 * Only one of them should be used/included.
 */


/** Special definitions of multi-bit bit field. */
#define MCUXCLPKC_SFR_CFG_RNDDLY_NODLY   (((uint32_t)(((uint32_t)(0u))   << MCUXCLPKC_SFR_BITPOS(CFG,RNDDLY))) & MCUXCLPKC_SFR_BITMSK(CFG,RNDDLY))
#define MCUXCLPKC_SFR_CFG_RNDDLY(val)    (((uint32_t)(((uint32_t)(val))  << MCUXCLPKC_SFR_BITPOS(CFG,RNDDLY))) & MCUXCLPKC_SFR_BITMSK(CFG,RNDDLY))
#define MCUXCLPKC_SFR_CTRL_REDMUL_FULLSZ (((uint32_t)(((uint32_t)(0u))   << MCUXCLPKC_SFR_BITPOS(CTRL,REDMUL))) & MCUXCLPKC_SFR_BITMSK(CTRL,REDMUL))


/**
 * Definitions for accessing PKC SFRs via, e.g., IP_PKC->STATUS.
 */

/** Helper macros for constructing SFR field name constants */
#define MCUXCLPKC_PASTE(a,b)  a ## b
#define MCUXCLPKC_CONCAT(a,b) MCUXCLPKC_PASTE(a,b)
#define MCUXCLPKC_SFR_FIELD(prefix,sfr,field)        MCUXCLPKC_CONCAT(prefix, sfr ## _ ## field)

/** Helper macros to get the mask and shift values for a specific PKC SFR field */
#define MCUXCLPKC_SFR_BITMSK(sfr, field)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_SIGNED_SHIFT_AMOUNT("External header outside our control")  \
    MCUXCLPKC_CONCAT(MCUXCLPKC_SFR_FIELD(PKC_SFR_PREFIX,sfr,field), PKC_SFR_SUFFIX_MSK)            \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SIGNED_SHIFT_AMOUNT()
#define MCUXCLPKC_SFR_BITPOS(sfr, field)        MCUXCLPKC_CONCAT(MCUXCLPKC_SFR_FIELD(PKC_SFR_PREFIX,sfr,field), PKC_SFR_SUFFIX_POS)
#define MCUXCLPKC_SFR_BITFMT(sfr, field, val)  (MCUXCLPKC_SFR_FIELD(PKC_SFR_PREFIX,sfr,field) (val))
#define MCUXCLPKC_SFR_BITVAL(sfr, field, val)  ((val) << MCUXCLPKC_SFR_BITPOS(sfr, field))

/**********************************************************/
/* Helper macros for PKC SFR access                       */
/**********************************************************/

/** Read from PKC SFR */
#define MCUXCLPKC_SFR_READ(sfr)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")  \
    (PKC_SFR_BASE->PKC_SFR_NAME(sfr))                                                \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Write to PKC SFR */
#define MCUXCLPKC_SFR_WRITE(sfr, value)  \
    do{  \
        uint32_t tmp_ = (value);                                                         \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")  \
        PKC_SFR_BASE->PKC_SFR_NAME(sfr) = tmp_;                                          \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                    \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
    } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Read from PKC SFR bit field */
#define MCUXCLPKC_SFR_BITREAD(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")                       \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_SIGNED_SHIFT_AMOUNT("External header outside our control")           \
    ((PKC_SFR_BASE->PKC_SFR_NAME(sfr) & MCUXCLPKC_SFR_BITMSK(sfr, bit)) >> MCUXCLPKC_SFR_BITPOS(sfr, bit))  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SIGNED_SHIFT_AMOUNT()                                                 \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Set bit field of PKC SFR (read-modify-write) */
#define MCUXCLPKC_SFR_BITSET(sfr, bit)  \
    do{  \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")  \
        PKC_SFR_BASE->PKC_SFR_NAME(sfr) |= MCUXCLPKC_SFR_BITMSK(sfr, bit);                \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                    \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
    } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Clear bit field of PKC SFR (read-modify-write) */
#define MCUXCLPKC_SFR_BITCLEAR(sfr, bit)  \
    do{  \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")   \
        PKC_SFR_BASE->PKC_SFR_NAME(sfr) &= (~ (uint32_t) MCUXCLPKC_SFR_BITMSK(sfr, bit));  \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                     \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
    } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Set value of multi-bit field of PKC SFR (read-modify-write) */
#define MCUXCLPKC_SFR_BITVALSET(sfr, bit, val)  \
    do{  \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")                  \
        uint32_t tmp_ = PKC_SFR_BASE->PKC_SFR_NAME(sfr) & (~ (uint32_t) MCUXCLPKC_SFR_BITMSK(sfr, bit));  \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                                    \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_SIGNED_SHIFT_AMOUNT("External header outside our control")  \
        tmp_ |= (((val) << MCUXCLPKC_SFR_BITPOS(sfr, bit)) & MCUXCLPKC_SFR_BITMSK(sfr, bit));          \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SIGNED_SHIFT_AMOUNT()                                        \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")  \
        PKC_SFR_BASE->PKC_SFR_NAME(sfr) =  tmp_;                                         \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                    \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
    } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Get address of PKC SFR */
#define MCUXCLPKC_SFR_ADDR(sfr)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("PKC SFR address")  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_VOLATILE("Access to a HW peripheral") \
    &(PKC_SFR_BASE->PKC_SFR_NAME(sfr)) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_VOLATILE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Get offset of PKC SFR */
#define MCUXCLPKC_SFR_OFFSET(sfr)  \
    (uint32_t)(offsetof(PKC_STRUCT_NAME, PKC_SFR_NAME(sfr)))

/**** ------------------------------ ****/

#endif /* MCUXCLPKC_SFRACCESS_H_ */
