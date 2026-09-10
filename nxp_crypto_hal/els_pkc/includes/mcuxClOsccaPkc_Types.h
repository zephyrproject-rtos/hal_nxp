/*--------------------------------------------------------------------------*/
/* Copyright 2018-2023 NXP                                                  */
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
 * @file  mcuxClOsccaPkc_Types.h
 * @brief Type definitions of mcuxClOsccaPkc component
 */


#ifndef MCUXCLOSCCAPKC_TYPES_H
#define MCUXCLOSCCAPKC_TYPES_H


#include <stdint.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

/**
 * @defgroup mcuxClOsccaPkc_Types mcuxClOsccaPkc_Types
 * @brief Defines all Types of @ref mcuxClOsccaPkc
 * @ingroup mcuxClOsccaPkc
 * @{
 */

/**********************************************************/
/* Helper macros                                          */
/**********************************************************/
/** @brief Macros for packing 2 8-bit parameters. */
#define MCUXCLOSCCAPKC_PKCPACKARGS2(hi8, lo8)  \
    ( ((uint16_t) (hi8) << 8u) | ((uint16_t) (lo8)) )


/**********************************************************/
/* PKC information                                        */
/**********************************************************/
#define MCUXCLOSCCAPKC_RAM_SIZE           0x00001000u  ///< PKC workarea size = 4 KByte

/**
 * @}
 */ /* mcuxClOsccaPkc_Types */

#endif /* #MCUXCLOSCCAPKC_TYPES_H */
