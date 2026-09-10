/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
 * @file  mcuxClEls_Internal_Common.h
 * @brief ELS header for common internal functionality.
 */

#ifndef MCUXCLELS_INTERNAL_COMMON_H_
#define MCUXCLELS_INTERNAL_COMMON_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClEls_Common.h> // Common types
#include <platform_specific_headers.h>

#ifdef __cplusplus
extern "C" {
#endif


/**********************************************
 * CONSTANTS
 **********************************************/

/**
 * @def MCUXCLELS_HW_VERSION
 * @ingroup mcuxClEls_Common
 * @brief Compatible ELS hardware IP version for the CLNS release that this header is part of.
 */
#ifndef MCUXCL_FEATURE_ELS_GET_FW_VERSION
#define MCUXCLELS_HW_VERSION ((mcuxClEls_HwVersion_t) { \
        .bits = { \
            .revision = (uint32_t) ELS_HW_VERSION_REVISION, \
            .minor = (uint32_t) ELS_HW_VERSION_MINOR, \
            .major = (uint32_t) ELS_HW_VERSION_MAJOR, \
            .level = (uint32_t) ELS_HW_VERSION_LEVEL \
        } \
    })
#else /* MCUXCL_FEATURE_ELS_GET_FW_VERSION */
#define MCUXCLELS_HW_VERSION ((mcuxClEls_HwVersion_t) { \
        .bits = { \
            .revision = (uint32_t) ELS_HW_VERSION_REVISION, \
            .minor = (uint32_t) ELS_HW_VERSION_MINOR, \
            .major = (uint32_t) ELS_HW_VERSION_MAJOR, \
            .fw_revision = (uint32_t) ELS_HW_VERSION_FW_REVISION, \
            .fw_minor = (uint32_t) ELS_HW_VERSION_FW_MINOR, \
            .fw_major = (uint32_t) ELS_HW_VERSION_FW_MAJOR \
        } \
    })
#endif /* MCUXCL_FEATURE_ELS_GET_FW_VERSION */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLELS_INTERNAL_COMMON_H_ */

