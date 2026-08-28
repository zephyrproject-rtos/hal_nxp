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

#ifndef MCUXCLSIGNATURE_CONSTANTS_H_
#define MCUXCLSIGNATURE_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

/* New Error codes */
#define MCUXCLSIGNATURE_STATUS_OK                      (0x0FF72E03u)
#define MCUXCLSIGNATURE_STATUS_FAULT_ATTACK            (0x0FF7F0F0u)

// Old Error Codes
#define MCUXCLSIGNATURE_STATUS_FAILURE                               (0x0FF75330u)
#define MCUXCLSIGNATURE_FAILURE                                      MCUXCLSIGNATURE_STATUS_FAILURE ///< @deprecated Please use #MCUXCLSIGNATURE_STATUS_FAILURE instead
#define MCUXCLSIGNATURE_OK                                           MCUXCLSIGNATURE_STATUS_OK ///< @deprecated Please use #MCUXCLSIGNATURE_STATUS_OK instead
#define MCUXCLSIGNATURE_STATUS_NOT_OK                                (0x0FF78930u)
#define MCUXCLSIGNATURE_NOT_OK                                       MCUXCLSIGNATURE_STATUS_NOT_OK ///< @deprecated Please use #MCUXCLSIGNATURE_STATUS_NOT_OK instead
#define MCUXCLSIGNATURE_STATUS_INVALID_PARAMS                        (0x0FF753F8u)
#define MCUXCLSIGNATURE_INVALID_PARAMS                               MCUXCLSIGNATURE_STATUS_INVALID_PARAMS ///< @deprecated Please use #MCUXCLSIGNATURE_STATUS_INVALID_PARAMS instead
#define MCUXCLSIGNATURE_STATUS_NOT_SUPPORTED                         (0x0FF75370u)
#define MCUXCLSIGNATURE_NOT_SUPPORTED                                MCUXCLSIGNATURE_STATUS_NOT_SUPPORTED  ///< @deprecated Please use #MCUXCLSIGNATURE_STATUS_NOT_SUPPORTED instead

#define MCUXCLSIGNATURE_TRANSLATE_VERIFY_RETURN_CODE(code) \
  (((((code) & 0x0000FFFFu) == 0x00002E03u) || (((code) & 0x0000FFFFu) == 0x00008930u)) \
       ? ((MCUXCLSIGNATURE_STATUS_NOT_OK & 0xFFFF0000u) | ((code) & 0x0000FFFFu)) \
       : (MCUXCLSIGNATURE_STATUS_FAILURE))

#endif /* MCUXCLSIGNATURE_CONSTANTS_H_ */
