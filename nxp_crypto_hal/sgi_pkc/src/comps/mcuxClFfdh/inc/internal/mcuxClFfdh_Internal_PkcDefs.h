/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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
 * @file  mcuxClFfdh_Internal_PkcDefs.h
 * @brief Internal definitions of the mcuxClFfdh component
 */

#ifndef MCUXCLFFDH_INTERNAL_PKCDEFS_H_
#define MCUXCLFFDH_INTERNAL_PKCDEFS_H_

#include <mcuxClFfdh_Types.h>

#ifdef __cplusplus
extern "C" {
#endif


/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for the mcuxClFfdh     */
/****************************************************************************/
#define FFDH_UPTRTINDEX_P               (0U) ///< UPTR virtual table index for buffer P
#define FFDH_UPTRTINDEX_PFULL           (1U) ///< UPTR table index for P'|P buffer
#define FFDH_UPTRTINDEX_BASE            (2U) ///< UPTR table index for base buffer
#define FFDH_UPTRTINDEX_EXP             (3U) ///< UPTR table index for exponent buffer
#define FFDH_UPTRTINDEX_T1              (4U) ///< UPTR table index for temp 1 buffer
#define FFDH_UPTRTINDEX_T2              (5U) ///< UPTR table index for temp 2 buffer
#define FFDH_UPTRTINDEX_T3              (6U) ///< UPTR table index for temp 3 buffer
#define FFDH_UPTRTINDEX_T4              (7U) ///< UPTR table index for temp 4 buffer
#define FFDH_UPTRTINDEX_T5              (8U) ///< UPTR table index for temp 5 buffer
#define FFDH_UPTRTINDEX_T6              (9U) ///< UPTR table index for temp 6 buffer
#define FFDH_UPTRT_COUNT                (10U) ///< UPTR table size of function mcuxClFfdh key agreement

#define FFDH_NO_OF_VIRTUALS   (FFDH_UPTRTINDEX_PFULL) ///< UPTR table size of function mcuxClFfdh key agreement
#define FFDH_NO_OF_BUFFERS    (FFDH_UPTRT_COUNT - FFDH_NO_OF_VIRTUALS) ///< UPTR table size of function mcuxClFfdh key agreement


/*******************************************************************************/
/* Defines to control placement of temporary exponentiation buffer (pExpTemp)  */
/*******************************************************************************/
#ifdef MCUXCL_FEATURE_PKC_RAM_8KB
/*  Define which informs if all secure exponentiation buffers can fit into the PKC RAM for given prime length.
    Size is hardcoded since particular group may be unavailable due to feature flag choice. */
#define FFDH_EXPTMP_FAME_RAM_ONLY_MAX_LENGTH (6144U / 8U)
#elif defined(MCUXCL_FEATURE_PKC_RAM_4KB)
/*  Define which informs if all secure exponentiation buffers can fit into the PKC RAM for given prime length.
    Size is hardcoded since particular group may be unavailable due to feature flag choice. */
#define FFDH_EXPTMP_FAME_RAM_ONLY_MAX_LENGTH (3072U / 8U)
#else
    #error "Unsupported PKC RAM size configuration."
#endif


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLFFDH_INTERNAL_PKCDEFS_H_ */


