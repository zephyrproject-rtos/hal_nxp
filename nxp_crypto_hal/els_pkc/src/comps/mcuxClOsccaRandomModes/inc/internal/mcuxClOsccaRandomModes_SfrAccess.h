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
 * @file  mcuxClOsccaRandomModes_SfrAccess.h
 * @brief Macros for abstracting TRNG hardware SFR access
 */


#ifndef MCUXCLOSCCARANDOMMODES_SFRACCESS_H_
#define MCUXCLOSCCARANDOMMODES_SFRACCESS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <platform_specific_headers.h>

/****                                 ****/
/**** TRNG Hardware Abstraction Layer ****/
/****                                 ****/

/**
 * 2 different TRNG hardware definition headers are supported.
 * Only one of them should be used/included.
 */


/**
 * Definitions for accessing TRNG SFRs via, e.g., IP_TRNG->STATUS.
 */

/** Helper macros for constructing SFR field name constants */
#define MCUXCLOSCCARANDOMMODES_PASTE(a,b)  a ## b
#define MCUXCLOSCCARANDOMMODES_CONCAT(a,b) MCUXCLOSCCARANDOMMODES_PASTE(a,b)
#define MCUXCLOSCCARANDOMMODES_SFR_FIELD(prefix,sfr,field)  MCUXCLOSCCARANDOMMODES_CONCAT(prefix, sfr ## _ ## field)

/** Helper macros to get the mask and shift values for a specific TRNG SFR field */
#define MCUXCLOSCCARANDOMMODES_SFR_BITMSK(sfr, field)       MCUXCLOSCCARANDOMMODES_CONCAT(MCUXCLOSCCARANDOMMODES_SFR_FIELD(TRNG_SFR_PREFIX,sfr,field), TRNG_SFR_SUFFIX_MSK)
#define MCUXCLOSCCARANDOMMODES_SFR_BITPOS(sfr, field)       MCUXCLOSCCARANDOMMODES_CONCAT(MCUXCLOSCCARANDOMMODES_SFR_FIELD(TRNG_SFR_PREFIX,sfr,field), TRNG_SFR_SUFFIX_POS)

/**********************************************************/
/* Helper macros for TRNG SFR access                       */
/**********************************************************/

/** Read from TRNG0 SFR */
#define MCUXCLOSCCARANDOMMODES_TRNG0_SFR_READ(sfr) \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("TRNG base and SFR addresses will always be 32-bit aligned.") \
    (TRNG_SFR_BASE->TRNG_SFR_NAME(sfr)) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Write to TRNG0 SFR */
#define MCUXCLOSCCARANDOMMODES_TRNG0_SFR_WRITE(sfr, value)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("TRNG base and SFR addresses will always be 32-bit aligned.") \
    do{ TRNG_SFR_BASE->TRNG_SFR_NAME(sfr) = (value); } while(false) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Read from TRNG0 SFR bit field */
#define MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITREAD(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("TRNG base and SFR addresses will always be 32-bit aligned.") \
    ((TRNG_SFR_BASE->TRNG_SFR_NAME(sfr) & MCUXCLOSCCARANDOMMODES_SFR_BITMSK(sfr, bit)) >> MCUXCLOSCCARANDOMMODES_SFR_BITPOS(sfr, bit)) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Set bit field of TRNG0 SFR (read-modify-write) */
#define MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITSET(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("TRNG base and SFR addresses will always be 32-bit aligned.") \
    do{ TRNG_SFR_BASE->TRNG_SFR_NAME(sfr) |= MCUXCLOSCCARANDOMMODES_SFR_BITMSK(sfr, bit); } while(false) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Clear bit field of TRNG0 SFR (read-modify-write) */
#define MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITCLEAR(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("TRNG base and SFR addresses will always be 32-bit aligned.") \
    do{ TRNG_SFR_BASE->TRNG_SFR_NAME(sfr) &= (~ (uint32_t) MCUXCLOSCCARANDOMMODES_SFR_BITMSK(sfr, bit)); } while(false) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Set value of multi-bit field of TRNG0 SFR (read-modify-write) */
#define MCUXCLOSCCARANDOMMODES_TRNG0_SFR_BITVALSET(sfr, bit, val)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("TRNG base and SFR addresses will always be 32-bit aligned.") \
    do{ uint32_t temp = TRNG_SFR_BASE->TRNG_SFR_NAME(sfr) & (~ (uint32_t) MCUXCLOSCCARANDOMMODES_SFR_BITMSK(sfr, bit)); \
        TRNG_SFR_BASE->TRNG_SFR_NAME(sfr) = (((val) << MCUXCLOSCCARANDOMMODES_SFR_BITPOS(sfr, bit)) & MCUXCLOSCCARANDOMMODES_SFR_BITMSK(sfr, bit)) | temp; \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER() \
    } while(false)


/**** ------------------------------ ****/

#endif /* MCUXCLOSCCARANDOMMODES_SFRACCESS_H_ */
