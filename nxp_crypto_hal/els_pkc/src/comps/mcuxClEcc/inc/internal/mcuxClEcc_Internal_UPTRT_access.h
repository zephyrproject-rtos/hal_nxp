/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2024 NXP                                       */
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
 * @file  mcuxClEcc_Internal_UPTRT_access.h
 * @brief Internal header with helper macros for UPTRT access
 */


#ifndef MCUXCLECC_INTERNAL_UPTRT_ACCESS_H_
#define MCUXCLECC_INTERNAL_UPTRT_ACCESS_H_

#include <mcuxClCore_Platform.h>

/**********************************************************/
/* Helper macros for accessing UPTRT table                */
/**********************************************************/
/** Macro for reading 2 offsets in UPTRT table.
 * [in] pOps: pointer to 16-bit offset table. This pointer must be 32-bit aligned;
 * [in] idx0, idx1: compile-time-constant indices of offsets in the table.
 * @attention not compile-time-constant indices will cause extra code size.
 * @attention if the two offsets are not in the same CPU word, this macro might cause extra code size.
 */
#define MCUXCLECC_LOAD_2OFFSETS(pOps, idx0, idx1)  \
    ( \
        ((0u == ((idx0) & (0x01u))) && ((idx1) == ((idx0) + (0x01u)))) ? \
            (((uint32_t *) (pOps))[(idx0) / 2u]) : \
            ((uint32_t) ((uint16_t *) (pOps))[idx0] | ((uint32_t) ((uint16_t *) (pOps))[idx1] << 16)) \
    )

/** Macro for writing 2 offsets to UPTRT table.
 * [in] pOps: pointer to 16-bit offset table. This pointer must be 32-bit aligned;
 * [in] idx0, idx1: compile-time-constant indices of offsets in the table.
 * @attention not compile-time-constant indices will cause extra code size.
 * @attention if the two offsets are not in the same CPU word, this macro might cause extra code size.
 */
#define MCUXCLECC_STORE_2OFFSETS(pOps, idx0, idx1, ofs1_ofs0)  \
    do{ \
        if ( (0u == ((idx0) & (0x01u))) && ((idx1) == ((idx0) + (0x01u))) )  \
        { \
          MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 - Rule 11.3 - UPTR table is 32-bit aligned in ECC component"); \
          ((uint32_t *) (pOps))[(idx0) / 2u] = (ofs1_ofs0); \
          MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING(); \
        }  \
        else  \
        { MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("MISRA Ex. 9 - Rule 11.3 - Cast to 16-bit pointer table") \
          ((uint16_t *) (pOps))[idx0] = (uint16_t) ((ofs1_ofs0) & 0xFFFFu);  \
          ((uint16_t *) (pOps))[idx1] = (uint16_t) ((ofs1_ofs0) >> 16); \
          MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES() \
        }  \
    } while(false)

/** Macro for copying 2 offsets in UPTRT table.
 * [in] pOps: pointer to 16-bit offset table. This pointer must be 32-bit aligned;
 * [in] dIdx0, dIdx1, sIdx0, sIdx1: compile-time-constant indices of offsets in the table.
 * @attention not compile-time-constant indices will cause extra code size.
 */
#define MCUXCLECC_COPY_2OFFSETS(pOps, dIdx0, dIdx1, sIdx0, sIdx1)  \
    do{  \
        if (   (0u == ((dIdx0) & (0x01u)))         \
            && ((dIdx1) == ((dIdx0) + (0x01u)))    \
            && (0u == ((sIdx0) & (0x01u)))         \
            && ((sIdx1) == ((sIdx0) + (0x01u))) )  \
        {   /* MISRA Ex. 9 - Rule 11.3 - UPTR table is 32-bit aligned in ECC component */ \
            ((uint32_t *) (pOps))[(dIdx0) / 2u] = ((uint32_t *) (pOps))[(sIdx0) / 2u]; \
        }  \
        else  \
        {   MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("MISRA Ex. 9 - Rule 11.3 - Cast to 16-bit pointer table") \
            ((uint16_t *) (pOps))[dIdx0] = ((uint16_t *) (pOps))[sIdx0];  \
            ((uint16_t *) (pOps))[dIdx1] = ((uint16_t *) (pOps))[sIdx1];  \
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES() \
        }  \
    } while (false)

#endif /* MCUXCLECC_INTERNAL_UPTRT_ACCESS_H_ */
