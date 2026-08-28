/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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
 * @file  mcuxCsslDataIntegrity_AssemblyMacros.h
 * @brief Assembly macros for the data integrity mechanism
 */

#ifndef MCUXCSSLDATAINTEGRITY_ASSEMBLYMACROS_H_
#define MCUXCSSLDATAINTEGRITY_ASSEMBLYMACROS_H_

#include <mcuxCsslSecureCounter_AssemblyMacros.h>

/**
 * \addtogroup mcuxCsslIMPL MCUX CSSL -- Implementations
 *
 * \defgroup mcuxCsslDataIntegrity_Asm Data Integrity: Assembly implementation
 * \brief Assembly implementation of the data integrity mechanism.
 * \ingroup mcuxCsslIMPL
 */

/**
 * \def MCUX_CSSL_DI_ASM_BASE
 * \brief DI SFR base address for SCM hardware
 * \ingroup mcuxCsslDataIntegrity_Asm
 */
#define MCUX_CSSL_DI_ASM_BASE  MCUX_CSSL_SC_SCM_ASM_BASE

/**
 * \def MCUX_CSSL_DI_ASM_INIT_BASE
 * \brief Assembly macro: Initialize the base address for the data integrity.
 *        This should be performed before calling other assembly macros MCUX_CSSL_DI_ASM_RECORD and MCUX_CSSL_DI_ASM_EXPUNGE.
 *        Usage in assembly: "MCUX_CSSL_DI_ASM_INIT_BASE baseReg"
 * \ingroup mcuxCsslDataIntegrity_Asm
 *
 * \param baseReg    Register that will be assigned the base address.
 */
#define MCUX_CSSL_DI_ASM_INIT_BASE  MCUX_CSSL_SC_ASM_INIT_BASE

/**
 * \def MCUX_CSSL_DI_ASM_INIT_BASE_COND
 * \brief Assembly macro: conditionally initialize the base address for the data integrity.
 *        This macro assumes the register (baseReg) contains the base address of the other HW SFR,
 *        %hi(addressOtherHw). If the base addresses (DI and the other hardware) are different,
 *        this macro will initialize the base address for DI; otherwise, this macro does nothing.
 *        Using this macro can avoid initializing register with the same base address.
 *        Usage in assembly: "MCUX_CSSL_DI_ASM_INIT_BASE_COND baseReg, addressOtherHw"
 * \ingroup mcuxCsslDataIntegrity_Asm
 *
 * \param baseReg    Register that will be assigned the base address.
 * \param addressOtherHw  a constant, which is an address of another hardware SFR
 */
#define MCUX_CSSL_DI_ASM_INIT_BASE_COND  MCUX_CSSL_SC_ASM_INIT_BASE_COND

/**
 * \def MCUX_CSSL_DI_ASM_VALUE
 * \brief Assembly macro: Retrieves the current data integrity value.
 *        Usage in assembly: "MCUX_CSSL_DI_ASM_VALUE baseReg, valueReg"
 * \ingroup mcuxCsslDataIntegrity_Asm
 *
 * \param baseReg    Register that contains the base address for DI, previously initialized with MCUX_CSSL_DI_ASM_INIT_BASE.
 * \param valueReg   Register to store the DI value.
 */
#define MCUX_CSSL_DI_ASM_VALUE     MCUX_CSSL_SC_ASM_VALUE

/**
 * \def MCUX_CSSL_DI_ASM_REF_VALUE
 * \brief Assembly macro: Retrieves the current data integrity reference value.
 *        Usage in assembly: "MCUX_CSSL_DI_ASM_REF_VALUE baseReg, valueReg"
 * \ingroup mcuxCsslDataIntegrity_Asm
 *
 * \param baseReg    Register that contains the base address for DI, previously initialized with MCUX_CSSL_DI_ASM_INIT_BASE.
 * \param valueReg   Register to store the reference DI value.
 */
#define MCUX_CSSL_DI_ASM_REF_VALUE     MCUX_CSSL_SC_ASM_REF_VALUE

/**
 * \def MCUX_CSSL_DI_ASM_WRITE_REF
 * \brief Assembly macro: Writes the data integrity reference value.
 *        Usage in assembly: "MCUX_CSSL_DI_ASM_WRITE_REF baseReg, valueReg"
 * \ingroup mcuxCsslDataIntegrity_Asm
 *
 * \param baseReg    Register that contains the base address for DI, previously initialized with MCUX_CSSL_DI_ASM_INIT_BASE.
 * \param valueReg   Register that contains the reference DI value.
 */
#define MCUX_CSSL_DI_ASM_WRITE_REF     MCUX_CSSL_SC_ASM_WRITE_REF

/**
 * \def MCUX_CSSL_DI_ASM_RECORD
 * \brief Assembly macro: Record the value for data integrity checking.
 *        Usage in assembly: "MCUX_CSSL_DI_ASM_RECORD baseReg, valueReg"
 * \ingroup mcuxCsslDataIntegrity_Asm
 *
 * \param baseReg    Register that contains the base address for DI, previously initialized with MCUX_CSSL_DI_ASM_INIT_BASE.
 * \param valueReg   Register that contains the value which needs to be recorded.
 */
#define MCUX_CSSL_DI_ASM_RECORD     MCUX_CSSL_SC_ASM_ADD

/**
 * \def MCUX_CSSL_DI_RECORD_IMPL
 * \brief Assembly macro: Expunge the record for value.
 *        Usage in assembly: "MCUX_CSSL_DI_ASM_EXPUNGE baseReg, valueReg"
 * \ingroup mcuxCsslDataIntegrity_Asm
 *
 * \param baseReg    Register that contains the base address for DI, previously initialized with MCUX_CSSL_DI_ASM_INIT_BASE.
 * \param valueReg   Register that contains the expected value that was recorded.
 */
#define MCUX_CSSL_DI_ASM_EXPUNGE    MCUX_CSSL_SC_ASM_SUB

#endif /* MCUXCSSLDATAINTEGRITY_ASSEMBLYMACROS_H_ */
