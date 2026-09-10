/*--------------------------------------------------------------------------*/
/* Copyright 2016, 2021, 2023 NXP                                           */
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
 *
 * @file:  mcuxClOscca_PlatformTypes.h
 * @brief: Platform type definitions
 *
 */
#ifndef MCUXCLOSCCA_PLATFORMTYPES_H_
#define MCUXCLOSCCA_PLATFORMTYPES_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint32_t mcuxClOscca_Size_t;
typedef uint32_t mcuxClOscca_Uint_t;
typedef int32_t mcuxClOscca_Int_t;

/**
 * global scratch pad structure definition
 */
typedef struct
{
  volatile uint16_t securityCounter;
  volatile uint16_t stackPointerBackup;
  uint32_t generalPurposeValue;
} mcuxClOscca_ScratchPad_t;

#define MCUX_CLOSCCA_SCRATCHPAD_SECTION __attribute__((section(".data.gmcuxClOscca_ScratchPad")))

/**
 * global scratch pad object
 */
extern mcuxClOscca_ScratchPad_t MCUX_CLOSCCA_SCRATCHPAD_SECTION gmcuxClOscca_ScratchPad;

#endif /* MCUXCLOSCCA_PLATFORMTYPES_H_ */
