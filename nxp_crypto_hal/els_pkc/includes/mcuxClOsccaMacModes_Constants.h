/*--------------------------------------------------------------------------*/
/* Copyright 2022 NXP                                                       */
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

/** @file  mcuxClOsccaMacModes_Constants.h
 *  @brief Supported constants for the mcuxClOsccaMacModes component
 */

#ifndef MCUXCLOSCCAMACMODES_CONSTANTS_H_
#define MCUXCLOSCCAMACMODES_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

#if defined(MCUXCL_FEATURE_MACMODES_CMAC_SM4) || defined(MCUXCL_FEATURE_MACMODES_CBCMAC_SM4)
/**
 * @defgroup mcuxClOsccaMacModes_Constants mcuxClOsccaMacModes_Constants
 * @brief Constants used by the OSCCA Mac operations.
 * @ingroup mcuxClOsccaMacModes
 * @{
 */
#endif /* defined(MCUXCL_FEATURE_MACMODES_CMAC_SM4) || defined(MCUXCL_FEATURE_MACMODES_CBCMAC_SM4) */

/**********************************************
 * CONSTANTS
 **********************************************/
/* Output sizes */
#ifdef MCUXCL_FEATURE_MACMODES_CMAC_SM4
#define MCUXCLOSCCASM4_CMAC_OUTPUT_SIZE    16u
#endif /* MCUXCL_FEATURE_MACMODES_CMAC_SM4 */

#ifdef MCUXCL_FEATURE_MACMODES_CBCMAC_SM4
#define MCUXCLOSCCASM4_CBCMAC_OUTPUT_SIZE  16u
#endif /* MCUXCL_FEATURE_MACMODES_CBCMAC_SM4 */

#if defined(MCUXCL_FEATURE_MACMODES_CMAC_SM4) || defined(MCUXCL_FEATURE_MACMODES_CBCMAC_SM4)
/** @} */
#endif /* defined(MCUXCL_FEATURE_MACMODES_CMAC_SM4) || defined(MCUXCL_FEATURE_MACMODES_CBCMAC_SM4) */
#endif /* MCUXCLOSCCAMACMODES_CONSTANTS_H_ */
