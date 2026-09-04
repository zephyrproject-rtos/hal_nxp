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

/** Macro for writing a 32-bit PKC offset pair to two consecutive PKC offset entries of the PKC offset table which must be at a CPU word aligned address.
 * [in] pOps: pointer to 16-bit offset table. This pointer must be 32-bit aligned;
 * [in] iDst: compile-time-constant PKC offset table index of first destination table entry; must be even;
 * [in] ofsPair: compile-time-constant PKC offset pair;
 * @attention not compile-time-constant indices will cause extra code size.
 */
#define MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOps, iDst, ofsPair)  \
    do{ \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("MISRA Ex. 9 - Rule 11.3 - UPTR table is 32-bit aligned in ECC component"); \
        ((uint32_t *) (pOps))[(iDst) / 2u] = (ofsPair); \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING(); \
    } while(false)

/** Macro for copying two consecutive PKC offset entries of the PKC offset table to two other consecutive entries. Both entry pairs must be at a CPU word aligned address.
 * [in] pOperands32: pointer to PKC offset table considered as uint32_t pointer. This pointer must be 32-bit aligned;
 * [in] iDst, iSrc: compile-time-constant PKC offset table indices of first destination and source offsets; each index must be even;
 * @attention not compile-time-constant indices will cause extra code size.
 */
#define MCUXCLECC_COPY_PKCOFFSETPAIR_ALIGNED(pOperands32, iDst, iSrc)  \
    do{  \
        (pOperands32)[(iDst) / 2u] = (pOperands32)[(iSrc) / 2u]; \
    } while (false)

#endif /* MCUXCLECC_INTERNAL_UPTRT_ACCESS_H_ */
