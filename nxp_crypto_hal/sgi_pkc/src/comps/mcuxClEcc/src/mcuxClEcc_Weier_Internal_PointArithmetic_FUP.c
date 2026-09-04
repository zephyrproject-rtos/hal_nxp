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
 * @file  mcuxClEcc_Weier_Internal_PointArithmetic_FUP.c
 * @brief FUP programs for Weierstrass curve internal point arithmetic
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_DoubleAdd[20] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x33u,0x58u,0xc2u,0x21u},{0x80u,0x00u,0x0eu,0x0eu,0x00u,0x19u},{0x80u,0x00u,0x19u,0x0eu,0x00u,0x1bu},{0x80u,0x00u,0x06u,0x19u,0x00u,0x0au},{0x80u,0x00u,0x07u,0x1bu,0x00u,0x0bu},{0x10u,0x00u,0x37u,0xafu,0x0du,0xd7u},{0x80u,0x2au,0x10u,0x0du,0x0bu,0x1bu},{0x80u,0x2au,0x10u,0x0cu,0x0au,0x0bu},{0x80u,0x00u,0x0eu,0x0bu,0x00u,0x19u},{0x00u,0x1eu,0x19u,0x19u,0x03u,0x08u},{0x80u,0x00u,0x0bu,0x0bu,0x00u,0x19u},{0x80u,0x00u,0x0cu,0x19u,0x00u,0x0au},{0x80u,0x00u,0x19u,0x0bu,0x00u,0x04u},{0x80u,0x00u,0x0du,0x04u,0x00u,0x0bu},{0x80u,0x00u,0x1bu,0x1bu,0x00u,0x19u},{0x81u,0x2au,0x10u,0x04u,0x0au,0x04u},{0x80u,0x21u,0x10u,0x04u,0x19u,0x04u},{0x80u,0x2au,0x10u,0x0au,0x04u,0x05u},{0x80u,0x00u,0x05u,0x1bu,0x00u,0x19u},{0x80u,0x2au,0x10u,0x19u,0x0bu,0x05u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_RepeatDouble[24] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x95u,0xa1u,0x06u,0xeau},{0x80u,0x00u,0x0eu,0x09u,0x00u,0x19u},{0x80u,0x00u,0x19u,0x19u,0x00u,0x0fu},{0x80u,0x00u,0x0fu,0x0fu,0x00u,0x19u},{0x80u,0x00u,0x12u,0x19u,0x00u,0x0fu},{0x10u,0x00u,0x73u,0xe1u,0x11u,0xd2u},{0x80u,0x00u,0x0cu,0x0cu,0x00u,0x1bu},{0x80u,0x21u,0x10u,0x0fu,0x1bu,0x19u},{0x81u,0x21u,0x10u,0x19u,0x1bu,0x19u},{0x80u,0x21u,0x10u,0x0du,0x0du,0x1bu},{0x80u,0x00u,0x1bu,0x0eu,0x00u,0x1du},{0x00u,0x1eu,0x1du,0x1du,0x03u,0x08u},{0x80u,0x00u,0x1bu,0x0du,0x00u,0x1du},{0x80u,0x21u,0x10u,0x1du,0x1du,0x1bu},{0x80u,0x00u,0x0cu,0x1bu,0x00u,0x1fu},{0x80u,0x00u,0x19u,0x19u,0x00u,0x04u},{0x81u,0x2au,0x10u,0x04u,0x1fu,0x04u},{0x80u,0x2au,0x10u,0x1fu,0x04u,0x1fu},{0x80u,0x00u,0x19u,0x1fu,0x00u,0x05u},{0x80u,0x00u,0x1bu,0x1du,0x00u,0x19u},{0x80u,0x2au,0x10u,0x05u,0x19u,0x05u},{0x10u,0x00u,0x7eu,0x91u,0x25u,0x10u},{0x80u,0x21u,0x10u,0x0fu,0x0fu,0x1bu},{0x80u,0x00u,0x19u,0x1bu,0x00u,0x0fu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/* FUP program: repeated point doubling.                        */
/* Prerequisites: **CAUTION** the 5th temp VT is assigned;      */
/*                coefficient a (in MR) is stored in buffer A.  */
/* Input: P = (x,y, z') in (VX2,VY2, VZ2), relative-z;          */
/*        zRef is stored in buffer VZ.                          */
/* Output: P_Dbl = 2P in (VX0,VY0, VZ0), relative-z,            */
/*         supporting result in-place.                          */



/* FUP program: point doubling-addition with mix-coordinates.                  */
/* Input:                                                                      */
/*   P0 = (x0,y0, z') in (VX2,VY2, VZ2), relative-z;                           */
/*   P1 = (x1,y1, z)  in (VX1,VY1, unused), Jacobian.                          */
/* Output:                                                                     */
/* (1 iteration)                                                               */
/*   P'0 := P1 + P0   in relative-z, and                                       */
/*   P0 will be updated (according to new z') and stored in (VT2,VT3).         */
/* (2 iterations, skip the first 4 operations in the 2nd iteration)            */
/*   P"0 := P1 + 2*P0 in relative-z.                                           */
/* P'0 / P"0 will be stored in (VX0,VY0, VZ0).                                 */
/* Attention:                                                                  */
/*   1. P0 != +/- P1, avoid doubling and O (point at infinity);                */
/*   2. VT2 and VT3 are different buffers from VX0/VY0/VZ0/VX1/VY1/VX2/VY2.    */
/*   3. For multiple iterations, VX2/VY2/VZ2 needs to be equal to VX0/VY0/VZ0. */
