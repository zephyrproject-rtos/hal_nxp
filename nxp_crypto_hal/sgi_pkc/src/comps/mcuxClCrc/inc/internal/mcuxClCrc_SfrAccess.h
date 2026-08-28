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
 * @file  mcuxClCrc_SfrAccess.h
 * @brief Macros for abstracting CRC hardware SFR access
 */


#ifndef MCUXCLCRC_SFRACCESS_H_
#define MCUXCLCRC_SFRACCESS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <platform_specific_headers.h>

/****                                 ****/
/**** CRC Hardware Abstraction Layer ****/
/****                                 ****/

/**
 * 2 different CRC hardware definition headers are supported.
 * Only one of them should be used/included.
 */
#ifndef MCUXCL_FEATURE_CRC_CRR_HEADER /* Legacy approach */
/**
 * Definitions for accessing CRC SFRs via, e.g., CRC->STATUS.
 */

#ifdef CRC_CTRL_TCRC_SHIFT
  #define CRC_SFR_BASE           CRC0        ///< base of CRC SFRs
  #define CRC_SFR_NAME1(sfr)     sfr         ///< full name of SFR
  #define CRC_SFR_NAME(sfr)      CRC_SFR_NAME1(sfr)     ///< full name of SFR
  #define CRC_SFR_PREFIX         CRC_        ///< sfr field name prefix
  #define CRC_SFR_SUFFIX_MSK     _MASK       ///< sfr field name suffix for mask
  #define CRC_SFR_SUFFIX_POS     _SHIFT      ///< sfr field name suffix for bit position
#else
  #define CRC_SFR_BASE           CRC0        ///< base of CRC SFRs
  #define CRC_SFR_NAME1(sfr)     sfr         ///< full name of SFR
  #define CRC_SFR_NAME(sfr)      CRC_SFR_NAME1(sfr).reg     ///< full name of SFR
  #define CRC_SFR_PREFIX         CRC0_       ///< sfr field name prefix
  #define CRC_SFR_SUFFIX_MSK     _Msk        ///< sfr field name suffix for mask
  #define CRC_SFR_SUFFIX_POS     _Pos        ///< sfr field name suffix for bit position
#endif

#endif /* MCUXCL_FEATURE_CRC_CRR_HEADER */


/**
 * Definitions for accessing CRC SFRs via, e.g., IP_CRC->STATUS.
 */

/** Helper macros for constructing SFR field name constants */
#define MCUXCLCRC_PASTE(a,b)  a ## b
#define MCUXCLCRC_CONCAT(a,b) MCUXCLCRC_PASTE(a,b)
#define MCUXCLCRC_SFR_FIELD(prefix,sfr,field)  MCUXCLCRC_CONCAT(prefix, sfr ## _ ## field)

/** Helper macros to get the mask and shift values for a specific CRC SFR field */
#define MCUXCLCRC_SFR_BITMSK(sfr, field)       MCUXCLCRC_CONCAT(MCUXCLCRC_SFR_FIELD(CRC_SFR_PREFIX,sfr,field), CRC_SFR_SUFFIX_MSK)
#define MCUXCLCRC_SFR_BITPOS(sfr, field)       MCUXCLCRC_CONCAT(MCUXCLCRC_SFR_FIELD(CRC_SFR_PREFIX,sfr,field), CRC_SFR_SUFFIX_POS)


/**********************************************************/
/* Helper macros for CRC SFR access                       */
/**********************************************************/

/** Read from CRC SFR */
#define MCUXCLCRC_SFR_READ(sfr)                                                      \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address") \
    (CRC_SFR_BASE->CRC_SFR_NAME(sfr))                                               \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Write to CRC SFR */
#define MCUXCLCRC_SFR_WRITE(sfr, value)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address") \
    do{ CRC_SFR_BASE->CRC_SFR_NAME(sfr) = (value); } while(false)                   \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

#define MCUXCLCRC_SFR_WRITE8(sfr, value)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")      \
    do{ *(volatile uint8_t *) &CRC_SFR_BASE->CRC_SFR_NAME(sfr) = (value); } while(false) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

#define MCUXCLCRC_SFR_WRITE16(sfr, value)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")        \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Hardware access method")             \
    do{ *(volatile uint16_t *) &CRC_SFR_BASE->CRC_SFR_NAME(sfr) = (value); } while(false)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()                                      \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Read from CRC SFR bit field */
#define MCUXCLCRC_SFR_BITREAD(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")                      \
    ((CRC_SFR_BASE->CRC_SFR_NAME(sfr) & MCUXCLCRC_SFR_BITMSK(sfr, bit)) >> MCUXCLCRC_SFR_BITPOS(sfr, bit)) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Set bit field of CRC SFR (read-modify-write) */
#define MCUXCLCRC_SFR_BITSET(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")      \
    do{ CRC_SFR_BASE->CRC_SFR_NAME(sfr) |= MCUXCLCRC_SFR_BITMSK(sfr, bit); } while(false) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Clear bit field of CRC SFR (read-modify-write) */
#define MCUXCLCRC_SFR_BITCLEAR(sfr, bit)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")                     \
    do{ CRC_SFR_BASE->CRC_SFR_NAME(sfr) &= (~ (uint32_t) MCUXCLCRC_SFR_BITMSK(sfr, bit)); } while(false) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/** Set value of multi-bit field of CRC SFR (read-modify-write) */
#define MCUXCLCRC_SFR_BITVALSET(sfr, bit, val)  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")                                        \
    do{ uint32_t temp = CRC_SFR_BASE->CRC_SFR_NAME(sfr) & (~ (uint32_t) MCUXCLCRC_SFR_BITMSK(sfr, bit));                    \
        CRC_SFR_BASE->CRC_SFR_NAME(sfr) = ((val) << MCUXCLCRC_SFR_BITPOS(sfr, bit)) & MCUXCLCRC_SFR_BITMSK(sfr, bit) | temp; \
    } while(false)                                                                                                         \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

/**** ------------------------------ ****/

#endif /* MCUXCLCRC_SFRACCESS_H_ */
