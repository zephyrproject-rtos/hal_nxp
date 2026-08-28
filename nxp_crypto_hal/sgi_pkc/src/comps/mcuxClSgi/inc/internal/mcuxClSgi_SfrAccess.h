/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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
 * @file  mcuxClSgi_SfrAccess.h
 * @brief Macros for abstracting SGI hardware SFR access
 */

#ifndef MCUXCLSGI_SFRACCESS_H_
#define MCUXCLSGI_SFRACCESS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <platform_specific_headers.h>
#include <mcuxCsslCPreProcessor.h>
#include <mcuxCsslAnalysis.h>

/** Helper macros for constructing SFR field name constants */
#define MCUXCLSGI_SFR_FIELD(prefix,sfr,field)  MCUX_CSSL_CPP_CAT4(prefix, sfr, _, field)

/** Helper macros for SGI SFR access                       */

/** Read from SGI SFR */
#define MCUXCLSGI_SFR_READ(sfr)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SGI SFR address")  \
    (SGI_SFR_BASE->SGI_SFR_NAME(sfr))                                                \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Write to SGI SFR */
#define MCUXCLSGI_SFR_WRITE(sfr, value)                                               \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SGI SFR address")  \
    do{ SGI_SFR_BASE->SGI_SFR_NAME(sfr) = (value); } while(false)                    \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Helper macros to get the mask and shift values for a specific SGI SFR field */
#define MCUXCLSGI_SFR_BITMSK(sfr, field)       MCUX_CSSL_CPP_CAT(MCUXCLSGI_SFR_FIELD(SGI_SFR_MACRO_PREFIX,sfr,field), SGI_SFR_SUFFIX_MSK)
#define MCUXCLSGI_SFR_BITPOS(sfr, field)       MCUX_CSSL_CPP_CAT(MCUXCLSGI_SFR_FIELD(SGI_SFR_MACRO_PREFIX,sfr,field), SGI_SFR_SUFFIX_POS)
#define MCUXCLSGI_SFR_BITVAL(sfr, field, val)  ((val) << MCUXCLSGI_SFR_BITPOS(sfr, field))

/** Read from SGI SFR bit field */
#define MCUXCLSGI_SFR_BITREAD(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SGI SFR address")                       \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_SIGNED_SHIFT_AMOUNT("External header outside our control")           \
    ((SGI_SFR_BASE->SGI_SFR_NAME(sfr) & MCUXCLSGI_SFR_BITMSK(sfr, bit)) >> MCUXCLSGI_SFR_BITPOS(sfr, bit))  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SIGNED_SHIFT_AMOUNT()                                                 \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Set bit field of SGI SFR (read-modify-write) */
#define MCUXCLSGI_SFR_BITSET(sfr, bit)  \
    do{  \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SGI SFR address")  \
        SGI_SFR_BASE->SGI_SFR_NAME(sfr) |= MCUXCLSGI_SFR_BITMSK(sfr, bit);                \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                    \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
    } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Clear bit field of SGI SFR (read-modify-write) */
#define MCUXCLSGI_SFR_BITCLEAR(sfr, bit)  \
    do{  \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SGI SFR address")   \
        SGI_SFR_BASE->SGI_SFR_NAME(sfr) &= (~ (uint32_t) MCUXCLSGI_SFR_BITMSK(sfr, bit));  \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                     \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
    } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Write bit field of SGI SFR with a specific value (read-modify-write) */
#define MCUXCLSGI_SFR_BITWRITE(sfr, bit, val)  \
    do{  \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SGI SFR address")  \
        SGI_SFR_BASE->SGI_SFR_NAME(sfr) = (SGI_SFR_BASE->SGI_SFR_NAME(sfr) & (~ (uint32_t) MCUXCLSGI_SFR_BITMSK(sfr, bit))) | MCUXCLSGI_SFR_BITVAL(sfr, bit, val); \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()                     \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
    } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/** Get address of SGI SFR */
#define MCUXCLSGI_SFR_ADDR(sfr)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("SGI SFR address")  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_VOLATILE("Access to a HW peripheral") \
    &(SGI_SFR_BASE->SGI_SFR_NAME(sfr)) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_VOLATILE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

#endif /* MCUXCLSGI_SFRACCESS_H_ */
