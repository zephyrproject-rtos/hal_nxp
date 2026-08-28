/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClDma_SfrAccess.h
 * @brief Macros for abstracting the DMA3 hardware SFR access
 */

#ifndef MCUXCLDMA_SFRACCESS_H_
#define MCUXCLDMA_SFRACCESS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <platform_specific_headers.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************/
/********************* DMA Hardware Abstraction Layer  *************************/
/*******************************************************************************/

/* Note:                                                                       */
/*   DMA SFRs consist of MP (Management Page) SFRs, and channel-specific SFRs, */
/*   including TCD (Transfer Control Descriptor) SFRs. All these SFR "types"   */
/*   will be abstracted in the following.                                      */


/** General helper macros for constructing field name constants */
#define MCUXCLDMA_PASTE(a,b)        a ## b
#define MCUXCLDMA_CONCAT(a,b)       MCUXCLDMA_PASTE(a,b)
#define MCUXCLDMA_CONCAT3(a,b,c)    MCUXCLDMA_CONCAT(MCUXCLDMA_CONCAT(a,b),c)
#define MCUXCLDMA_CONCAT4(a,b,c,d)  MCUXCLDMA_CONCAT(MCUXCLDMA_CONCAT3(a,b,c),d)


/*************************************************/
/* Definitions to access DMA SFRs and SFR fields */
/*************************************************/

/**
 * Different DMA hardware definition headers might be supported.
 * Only one of them should be used/included.
 */
#ifndef MCUXCL_FEATURE_DMA_CRR_HEADER /* Legacy approach */

#ifdef eDMA_TCD_TCD_CH_CSR_ERQ_MASK
  /** Base of the DMA MP SFR structure */
  #define DMA_MP_SFR_BASE                                                                \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("DMA3_MP hardware base address")  \
    (DMA3_MP)                                                                            \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

  /** Base of the DMA Channel SFR structure */
  #define DMA_CH_SFR_BASE                                                                \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("DMA3_TCD hardware base address") \
    (DMA3_TCD)                                                                           \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

  /** Base of the DMA TCD SFR structure */
  #define DMA_TCD_SFR_BASE                                                                \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("DMA3_TCD hardware base address") \
    (DMA3_TCD)                                                                           \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()

  /**
   * Definitions for accessing DMA MP SFRs via, e.g., DMA_MP_SFR_BASE->MP_CSR, or DMA_MP_SFR_BASE->CH_GRPRI[0]
   * and for constructing the mask and shift values for a corresponding SFR field, e.g., eDMA_MP_MP_CSR_EDBG_MASK
   */
  #define DMA_MP_SFR_NAME(sfr)         sfr        ///< DMA MP SFR full name
  #define DMA_MP_CH_SFR_NAME(ch,sfr)   sfr[(ch)]  ///< DMA MP SFR full name (for a channel-specific SFR)
  #define DMA_MP_SFR_PREFIX            eDMA_MP_   ///< DMA MP SFR field name prefix

  /**
   * Definitions for accessing DMA channel-specific SFRs, e.g., DMA_CH_SFR_BASE->TCD[0].CH_CSR,
   * and for constructing the mask and shift values for a corresponding SFR field, e.g., eDMA_TCD_TCD_CH_CSR_ERQ_MASK
   */
  #define DMA_CH_SFR_NAME(ch,sfr)      TCD[(ch)].sfr  ///< DMA channel-specific SFR full name for a given channel
  #define DMA_CH_SFR_PREFIX            eDMA_TCD_TCD_  ///< DMA channel-specific SFR field name prefix

/**
   * Definitions for accessing DMA TCD-specific SFRs, e.g., DMA_TCD_SFR_BASE->TCD[0].CSR,
   * and for constructing the mask and shift values for a corresponding SFR field, e.g., eDMA_TCD_CSR_ERQ_MASK
   */
  #define DMA_TCD_SFR_NAME(ch,sfr)      TCD[(ch)].sfr  ///< DMA channel-specific SFR full name for a given channel
  #define DMA_TCD_SFR_PREFIX            eDMA_TCD_TCD_  ///< DMA channel-specific SFR field name prefix

  /**
   * Helper macro for constructing SFR field name constants
   */
  #define DMA_SFR_FIELD(prefix,sfr,field)  MCUXCLDMA_CONCAT(prefix,sfr ## _ ## field) ///< DMA SFR field name
  #define DMA_SFR_SUFFIX_MSK  _MASK   ///< DMA SFR field name suffix for mask
  #define DMA_SFR_SUFFIX_POS  _SHIFT  ///< DMA SFR field name suffix for bit position

#endif
#endif /* MCUXCL_FEATURE_DMA_CRR_HEADER */


/*************************************************/
/* Helper macros for DMA SFR access              */
/*************************************************/

/** Helper macros to get the mask and shift values for a DMA MP SFR field */
#define MCUXCLDMA_MP_SFR_BITMSK(sfr,field)   MCUXCLDMA_CONCAT(DMA_SFR_FIELD(DMA_MP_SFR_PREFIX,sfr,field), DMA_SFR_SUFFIX_MSK)
#define MCUXCLDMA_MP_SFR_BITPOS(sfr,field)   MCUXCLDMA_CONCAT(DMA_SFR_FIELD(DMA_MP_SFR_PREFIX,sfr,field), DMA_SFR_SUFFIX_POS)

/** Helper macros to get the mask and shift values for a channel-specific DMA SFR field */
#define MCUXCLDMA_CH_SFR_BITMSK(sfr,field)   MCUXCLDMA_CONCAT(DMA_SFR_FIELD(DMA_CH_SFR_PREFIX,sfr,field), DMA_SFR_SUFFIX_MSK)
#define MCUXCLDMA_CH_SFR_BITPOS(sfr,field)   MCUXCLDMA_CONCAT(DMA_SFR_FIELD(DMA_CH_SFR_PREFIX,sfr,field), DMA_SFR_SUFFIX_POS)

/** Helper macros to get the mask and shift values for a TCD-specific DMA SFR field */
#define MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)   MCUXCLDMA_CONCAT(DMA_SFR_FIELD(DMA_TCD_SFR_PREFIX,sfr,field), DMA_SFR_SUFFIX_MSK)
#define MCUXCLDMA_TCD_SFR_BITPOS(sfr,field)   MCUXCLDMA_CONCAT(DMA_SFR_FIELD(DMA_TCD_SFR_PREFIX,sfr,field), DMA_SFR_SUFFIX_POS)

/** Helper macros to shift and mask a value for a DMA MP SFR field */
#define MCUXCLDMA_MP_VALUE32_TO_FIELD(value,sfr,field)  (((uint32_t)(value) << MCUXCLDMA_MP_SFR_BITPOS(sfr,field)) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field))
#define MCUXCLDMA_MP_VALUE16_TO_FIELD(value,sfr,field)  (((uint16_t)(value) << MCUXCLDMA_MP_SFR_BITPOS(sfr,field)) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field))

/** Helper macro to mask and shift a DMA MP SFR field value, to get the field's value */
#define MCUXCLDMA_MP_FIELD_TO_VALUE32(valueSfr,sfr,field)  (((uint32_t)(valueSfr) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_MP_SFR_BITPOS(sfr,field))
#define MCUXCLDMA_MP_FIELD_TO_VALUE16(valueSfr,sfr,field)  (((uint16_t)(valueSfr) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_MP_SFR_BITPOS(sfr,field))

/** Helper macros to shift and mask a value for a channel-specific DMA SFR field */
#define MCUXCLDMA_CH_VALUE32_TO_FIELD(value,sfr,field)  (((uint32_t)(value) << MCUXCLDMA_CH_SFR_BITPOS(sfr,field)) & MCUXCLDMA_CH_SFR_BITMSK(sfr,field))
#define MCUXCLDMA_CH_VALUE16_TO_FIELD(value,sfr,field)  (((uint16_t)(value) << MCUXCLDMA_CH_SFR_BITPOS(sfr,field)) & MCUXCLDMA_CH_SFR_BITMSK(sfr,field))

/** Helper macro to mask and shift a DMA MP SFR field value, to get the field's value */
#define MCUXCLDMA_CH_FIELD_TO_VALUE32(valueSfr,sfr,field)  (((uint32_t)(valueSfr) & MCUXCLDMA_CH_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_CH_SFR_BITPOS(sfr,field))
#define MCUXCLDMA_CH_FIELD_TO_VALUE16(valueSfr,sfr,field)  (((uint16_t)(valueSfr) & MCUXCLDMA_CH_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_CH_SFR_BITPOS(sfr,field))

/** Helper macros to shift and mask a value for a TCD-specific DMA SFR field */
#define MCUXCLDMA_TCD_VALUE32_TO_FIELD(value,sfr,field)  (((uint32_t)(value) << MCUXCLDMA_TCD_SFR_BITPOS(sfr,field)) & MCUXCLDMA_TCD_SFR_BITMSK(sfr,field))
#define MCUXCLDMA_TCD_VALUE16_TO_FIELD(value,sfr,field)  (((uint16_t)(value) << MCUXCLDMA_TCD_SFR_BITPOS(sfr,field)) & MCUXCLDMA_TCD_SFR_BITMSK(sfr,field))

/** Helper macro to mask and shift a DMA TCD SFR field value, to get the field's value */
#define MCUXCLDMA_TCD_FIELD_TO_VALUE32(valueSfr,sfr,field)  (((uint32_t)(valueSfr) & MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_TCD_SFR_BITPOS(sfr,field))
#define MCUXCLDMA_TCD_FIELD_TO_VALUE16(valueSfr,sfr,field)  (((uint16_t)(valueSfr) & MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_TCD_SFR_BITPOS(sfr,field))


/** Read from DMA SFR */
#define MCUXCLDMA_MP_SFR_READ(sfr)        (DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr))
#define MCUXCLDMA_MP_CH_SFR_READ(ch,sfr)  (DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr))
#define MCUXCLDMA_CH_SFR_READ(ch,sfr)     (DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr))
#define MCUXCLDMA_TCD_SFR_READ(ch,sfr)    (DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr))

/** Write to DMA SFR */
#define MCUXCLDMA_MP_SFR_WRITE(sfr,value)   \
  do{ DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) = (value); } while(false)

#define MCUXCLDMA_MP_CH_SFR_WRITE(ch,sfr,value)   \
  do{ DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) = (value); } while(false)

#define MCUXCLDMA_CH_SFR_WRITE(ch,sfr,value)  \
  do{ DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) = (value); } while(false)

#define MCUXCLDMA_TCD_SFR_WRITE(ch,sfr,value)  \
  do{ DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) = (value); } while(false)


/** Set single-bit DMA SFR bit field (read-modify-write) */
#define MCUXCLDMA_MP_SFR_BITFIELD_SET(sfr,field)  \
  do{ DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) |= MCUXCLDMA_MP_SFR_BITMSK(sfr,field); } while(false)

#define MCUXCLDMA_MP_CH_SFR_BITFIELD_SET(ch,sfr,field)  \
  do{ DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) |= MCUXCLDMA_MP_SFR_BITMSK(sfr,field); } while(false)

#define MCUXCLDMA_CH_SFR_BITFIELD_SET(ch,sfr,field)  \
  do{ DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) |= MCUXCLDMA_CH_SFR_BITMSK(sfr,field); } while(false)

#define MCUXCLDMA_TCD_SFR_BITFIELD_SET(ch,sfr,field)  \
  do{ DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) |= MCUXCLDMA_TCD_SFR_BITMSK(sfr,field); } while(false)


/** Clear single-bit DMA SFR field (read-modify-write) */
#define MCUXCLDMA_MP_SFR_BITFIELD_CLEAR(sfr,field)  \
  do{ DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) &= (~ MCUXCLDMA_MP_SFR_BITMSK(sfr,field)); } while(false)

#define MCUXCLDMA_MP_CH_SFR_BITFIELD_CLEAR(ch,sfr,field)  \
  do{ DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) &= (~ MCUXCLDMA_MP_SFR_BITMSK(sfr,field)); } while(false)

#define MCUXCLDMA_CH_SFR_BITFIELD_CLEAR(ch,sfr,field)  \
  do{ DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) &= (~ MCUXCLDMA_CH_SFR_BITMSK(sfr,field)); } while(false)

#define MCUXCLDMA_CH_SFR16_BITFIELD_CLEAR(ch,sfr,field)  \
  do{ DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) &= (~ (uint16_t)MCUXCLDMA_CH_SFR_BITMSK(sfr,field)); } while(false)

#define MCUXCLDMA_TCD_SFR_BITFIELD_CLEAR(ch,sfr,field)  \
  do{ DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) &= (~ MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)); } while(false)

#define MCUXCLDMA_TCD_SFR16_BITFIELD_CLEAR(ch,sfr,field)  \
  do{ DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) &= (~ (uint16_t)MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)); } while(false)


/** Read from multi-bit DMA SFR bit field */
#define MCUXCLDMA_MP_SFR_BITFIELD_READ(sfr,field)  \
  ((DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_MP_SFR_BITPOS(sfr,field))

#define MCUXCLDMA_MP_CH_SFR_BITFIELD_READ(ch,sfr,field)  \
  ((DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_MP_SFR_BITPOS(sfr,field))

#define MCUXCLDMA_CH_SFR_BITFIELD_READ(ch,sfr,field)  \
  ((DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) & MCUXCLDMA_CH_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_CH_SFR_BITPOS(sfr,field))

#define MCUXCLDMA_TCD_SFR_BITFIELD_READ(ch,sfr,field)  \
  ((DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) & MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)) >> MCUXCLDMA_TCD_SFR_BITPOS(sfr,field))


/** Write value of multi-bit field of 32-bit DMA SFR (read-modify-write) */
#define MCUXCLDMA_MP_SFR32_BITFIELD_WRITE(sfr,field,value)  \
  do{ uint32_t temp = DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) & (~ (uint32_t)MCUXCLDMA_MP_SFR_BITMSK(sfr,field));  \
      DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) = (((uint32_t)(value) << MCUXCLDMA_MP_SFR_BITPOS(sfr,field)) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)

#define MCUXCLDMA_MP_CH_SFR32_BITFIELD_WRITE(ch,sfr,field,value)  \
  do{ uint32_t temp = DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) & (~ (uint32_t)MCUXCLDMA_MP_SFR_BITMSK(sfr,field));  \
      DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) = (((uint32_t)(value) << MCUXCLDMA_MP_SFR_BITPOS(sfr,field)) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)

#define MCUXCLDMA_CH_SFR32_BITFIELD_WRITE(ch,sfr,field,value)  \
  do{ uint32_t temp = DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) & (~ (uint32_t)MCUXCLDMA_CH_SFR_BITMSK(sfr,field));  \
      DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) = (((uint32_t)(value) << MCUXCLDMA_CH_SFR_BITPOS(sfr,field)) & MCUXCLDMA_CH_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)

#define MCUXCLDMA_TCD_SFR32_BITFIELD_WRITE(ch,sfr,field,value)  \
  do{ uint32_t temp = DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) & (~ (uint32_t)MCUXCLDMA_TCD_SFR_BITMSK(sfr,field));  \
      DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) = (((uint32_t)(value) << MCUXCLDMA_TCD_SFR_BITPOS(sfr,field)) & MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)


/** Write value of multi-bit field of 16-bit DMA SFR (read-modify-write) */
#define MCUXCLDMA_MP_SFR16_BITFIELD_WRITE(sfr,field,value)  \
  do{ uint16_t temp = DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) & (~ (uint16_t)MCUXCLDMA_MP_SFR_BITMSK(sfr,field));  \
      DMA_MP_SFR_BASE->DMA_MP_SFR_NAME(sfr) = (((uint16_t)(value) << MCUXCLDMA_MP_SFR_BITPOS(sfr,field)) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)

#define MCUXCLDMA_MP_CH_SFR16_BITFIELD_WRITE(ch,sfr,field,value)  \
  do{ uint16_t temp = DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) & (~ (uint16_t)MCUXCLDMA_MP_SFR_BITMSK(sfr,field));  \
      DMA_MP_SFR_BASE->DMA_MP_CH_SFR_NAME(ch,sfr) = (((uint16_t)(value) << MCUXCLDMA_MP_SFR_BITPOS(sfr,field)) & MCUXCLDMA_MP_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)

#define MCUXCLDMA_CH_SFR16_BITFIELD_WRITE(ch,sfr,field,value)  \
  do{ uint16_t temp = DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) & (~ (uint16_t)MCUXCLDMA_CH_SFR_BITMSK(sfr,field));  \
      DMA_CH_SFR_BASE->DMA_CH_SFR_NAME(ch,sfr) = (((uint16_t)(value) << MCUXCLDMA_CH_SFR_BITPOS(sfr,field)) & MCUXCLDMA_CH_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)

#define MCUXCLDMA_TCD_SFR16_BITFIELD_WRITE(ch,sfr,field,value)  \
  do{ uint16_t temp = DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) & (~ (uint16_t)MCUXCLDMA_TCD_SFR_BITMSK(sfr,field));  \
      DMA_TCD_SFR_BASE->DMA_TCD_SFR_NAME(ch,sfr) = (((uint16_t)(value) << MCUXCLDMA_TCD_SFR_BITPOS(sfr,field)) & MCUXCLDMA_TCD_SFR_BITMSK(sfr,field)) | temp;  \
  } while(false)


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLDMA_SFRACCESS_H_ */
