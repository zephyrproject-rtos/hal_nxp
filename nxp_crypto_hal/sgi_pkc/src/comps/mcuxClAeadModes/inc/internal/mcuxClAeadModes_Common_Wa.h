/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

/** @file  mcuxClAeadModes_Common_Wa.h
 *  @brief Internal structure of the work space for the mcuxClAeadModes component
 */

#ifndef MCUXCLAEADMODES_COMMON_WA_H_
#define MCUXCLAEADMODES_COMMON_WA_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClAes_Constants.h>

#include <internal/mcuxClAeadModes_Common_Constants.h>
#include <internal/mcuxClAes_Wa.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMacModes_Common_Types.h>

#include <internal/mcuxClCipherModes_Common_Wa.h>

typedef union mcuxClAeadModes_CpuWorkArea
{
    uint8_t CCM_B0[MCUXCLAEADMODES_CCM_B0_SIZE];
    uint8_t tagBuffer[2U * MCUXCLAEADMODES_TAGLEN_MAX];
    uint8_t lastBlockBuffer[MCUXCLAES_BLOCK_SIZE - 1U];
} mcuxClAeadModes_CpuWorkArea_t;


typedef struct mcuxClAeadModes_WorkArea
{
  mcuxClAes_Workarea_Sgi_t sgiWa;
  mcuxClAeadModes_CpuWorkArea_t cpuWa;
  uint32_t gmacModeDescBuf[MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClMac_ModeDescriptor_t))
                           + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClMacModes_GmacModeDescriptor_t))];
} mcuxClAeadModes_WorkArea_t;

#endif /* MCUXCLAEADMODES_COMMON_WA_H_ */
