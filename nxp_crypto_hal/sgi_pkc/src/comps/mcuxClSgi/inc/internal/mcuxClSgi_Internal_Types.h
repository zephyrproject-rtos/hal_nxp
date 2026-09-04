/*--------------------------------------------------------------------------*/
/* Copyright 2024-2026 NXP                                                  */
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

#ifndef MCUXCLSGI_INTERNAL_TYPES_H_
#define MCUXCLSGI_INTERNAL_TYPES_H_

#include <mcuxCsslFlowProtection.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Function type for wrapper function to copy data out of SGI
 *
 * @param      pWa          Pointer to workarea required by this function (word-aligned)
 * @param      pOut         Output buffer to copy data from SGI to
 * @param      offset       Offset in pOut to write data to
 * @param      byteLength   Byte length to copy date from SGI to pOut
 *
 *  Data Integrity: Expunge(pOut + offset + mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET) + byteLength)
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClSgi_copyOut_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClSgi_copyOut_t)(void* pWa, mcuxCl_Buffer_t pOut, uint32_t offset, uint32_t byteLength));


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSGI_INTERNAL_TYPES_H_ */

