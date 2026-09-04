/*--------------------------------------------------------------------------*/
/* Copyright 2020 NXP                                                       */
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

/** @file  mcuxCl_clns.h
 *  @brief CLNS header for component-independent functionality */

#ifndef MCUXCL_CLNS_H_
#define MCUXCL_CLNS_H_

#include <mcuxClConfig.h> // Exported features flags header

/**********************************************
 * CONSTANTS
 **********************************************/

#define MCUXCL_VERSION_MAX_SIZE ((size_t) 32U) ///< Maximum size of the CLNS version string, in bytes (including zero-terminator)

/**
 * \implements{REQ_788368}
 */
#define MCUXCL_VERSION "DCI_SDK_V4.3.0" ///< String literal for the version string of CLNS release that this header is part of

/**********************************************
 * FUNCTIONS
 **********************************************/

/** Gets the CLNS version string that uniquely identifies this release of the CLNS. */
/** @attention This header was delivered as part of a CLNS release with the version string: DCI_SDK_V4.3.0.
 *             A string literal is defined by the macro #MCUXCL_VERSION. */
/**
 * @return Zero-terminated ASCII string that identifies this release of the CLNS.
 *         Maximum size in bytes (including zero-terminator) is #MCUXCL_VERSION_MAX_SIZE. */
static inline char const* mcuxCl_GetVersion(void)
{
    return MCUXCL_VERSION;
}

#endif /* MCUXCL_CLNS_H_ */
