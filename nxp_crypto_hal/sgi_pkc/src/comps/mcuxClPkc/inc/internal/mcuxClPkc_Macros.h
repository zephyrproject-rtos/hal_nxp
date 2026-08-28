/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClPkc_Macros.h
 * @brief Macros for accessing PKC hardware IP
 */


#ifndef MCUXCLPKC_MACROS_H_
#define MCUXCLPKC_MACROS_H_


#include <platform_specific_headers.h>
#include <mcuxClToolchain.h>
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_Internal_Types.h>
#include <internal/mcuxClPkc_SfrAccess.h>
#include <internal/mcuxClPkc_BasicDefs.h>

#include <internal/mcuxClPkc_Inline_Functions.h>


/**********************************************************/
/* Macros for UPTR table and offsets                      */
/**********************************************************/
/** Sets the address of UPTRT (Universal pointer FUP table). */
#define MCUXCLPKC_SETUPTRT(pUptrt)  mcuxClPkc_inline_setUptrt(pUptrt)
/** Gets the address of UPTRT (Universal pointer FUP table). */
#define MCUXCLPKC_GETUPTRT()  mcuxClPkc_inline_getUptrt()

/** Converts CPU pointer to PKC offset.
 * **CAUTION** This macro does not guarantee the returned offset is PKC-word aligned. */
#define MCUXCLPKC_PTR2OFFSET(cpuPointer)  mcuxClPkc_inline_ptr2Offset(cpuPointer)
/** Converts PKC offset to CPU pointer. */
#define MCUXCLPKC_OFFSET2PTR(pkcOffset)  mcuxClPkc_inline_offset2Ptr(pkcOffset)
/** Converts PKC offset to CPU word-aligned pointer.
 * **CAUTION** This macro assumes the offset provided is PKC-word aligned. */
#define MCUXCLPKC_OFFSET2PTRWORD(pkcOffset)  mcuxClPkc_inline_offset2PtrWord(pkcOffset)


/**********************************************************/
/* Macros for parameter set 1                             */
/**********************************************************/
/** Sets either mode of L0 operation or address of L1 microcode of parameter set 1. */
#define MCUXCLPKC_PS1_SETMODE(mode)  MCUXCLPKC_SFR_WRITE(MODE1, mode)
/** Sets packed offsets to buffers of operands Y and X of parameter set 1. */
#define MCUXCLPKC_PS1_SETXY_REG(offsetY_offsetX)  MCUXCLPKC_SFR_WRITE(XYPTR1, offsetY_offsetX)
/** Sets packed offsets to buffers of result R and operand Z of parameter set 1. */
#define MCUXCLPKC_PS1_SETZR_REG(offsetR_offsetZ)  MCUXCLPKC_SFR_WRITE(ZRPTR1, offsetR_offsetZ)
/** Sets packed MCLEN and (OP)LEN of parameter set 1. */
#define MCUXCLPKC_PS1_SETLENGTH_REG(mclen_oplen)  mcuxClPkc_inline_ps1_setLengthReg(mclen_oplen)

/** Sets two offsets to buffers of operands Y and X of parameter set 1. */
#define MCUXCLPKC_PS1_SETXY(offsetX, offsetY)  \
    MCUXCLPKC_PS1_SETXY_REG( ((uint32_t) (offsetY) << MCUXCLPKC_SFR_BITPOS(XYPTR1, YPTR)) | (uint32_t) (offsetX) )
/** Sets two offsets to buffers of result R and operand Z of parameter set 1. */
#define MCUXCLPKC_PS1_SETZR(offsetZ, offsetR)  \
    MCUXCLPKC_PS1_SETZR_REG( ((uint32_t) (offsetR) << MCUXCLPKC_SFR_BITPOS(ZRPTR1, RPTR)) | (uint32_t) (offsetZ) )
/** Sets MCLEN and (OP)LEN of parameter set 1. */
#define MCUXCLPKC_PS1_SETLENGTH(mclen, oplen)  \
    MCUXCLPKC_PS1_SETLENGTH_REG(MCUXCLPKC_PS1_PACK((mclen), (oplen)))

#define MCUXCLPKC_PS1_PACK(mclen, oplen)  \
    ( ((uint32_t) (mclen) << MCUXCLPKC_SFR_BITPOS(LEN1, MCLEN)) | (uint32_t) (oplen) )

/** Gets packed MCLEN and (OP)LEN of parameter set 1. */
#define MCUXCLPKC_PS1_GETLENGTH_REG()  mcuxClPkc_inline_ps1_getLengthReg()
/** Gets (OP)LEN of parameter set 1. */
#define MCUXCLPKC_PS1_GETOPLEN()  mcuxClPkc_inline_ps1_getOplen()
/** Gets MCLEN of parameter set 1. */
#define MCUXCLPKC_PS1_GETMCLEN()  mcuxClPkc_inline_ps1_getMclen()

#define MCUXCLPKC_PS1_UNPACK_OPLEN(lenRegValue)  \
    ( ((lenRegValue) & MCUXCLPKC_SFR_BITMSK(LEN1, LEN)) >> MCUXCLPKC_SFR_BITPOS(LEN1, LEN) )
#define MCUXCLPKC_PS1_UNPACK_MCLEN(lenRegValue)  \
    ( ((lenRegValue) & MCUXCLPKC_SFR_BITMSK(LEN1, MCLEN)) >> MCUXCLPKC_SFR_BITPOS(LEN1, MCLEN) )

/** Macro to start PKC L0 operation with parameter set 1. */
#define MCUXCLPKC_PS1_START_L0()  \
    do{ MCUXCLPKC_SFR_BITSET(CTRL, GOD1); MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND(); } while(false)
/** Macro to start PKC L1 microcode with parameter set 1. */
#define MCUXCLPKC_PS1_START_L1()  \
    do{ MCUXCLPKC_SFR_BITSET(CTRL, GOM1); MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND(); } while(false)


/**********************************************************/
/* Macros for parameter set 2                             */
/**********************************************************/
/** Sets either mode of L0 operation or address of L1 microcode of parameter set 2. */
#define MCUXCLPKC_PS2_SETMODE(mode)  MCUXCLPKC_SFR_WRITE(MODE2, mode)
/** Sets packed offsets to buffers of operands Y and X of parameter set 2. */
#define MCUXCLPKC_PS2_SETXY_REG(offsetY_offsetX)  MCUXCLPKC_SFR_WRITE(XYPTR2, offsetY_offsetX)
/** Sets packed offsets to buffers of result R and operand Z of parameter set 2. */
#define MCUXCLPKC_PS2_SETZR_REG(offsetR_offsetZ)  MCUXCLPKC_SFR_WRITE(ZRPTR2, offsetR_offsetZ)
/** Sets packed MCLEN and (OP)LEN of parameter set 2. */
#define MCUXCLPKC_PS2_SETLENGTH_REG(mclen_oplen)  mcuxClPkc_inline_ps2_setLengthReg(mclen_oplen)

/** Sets two offsets to buffers of operands Y and X of parameter set 2. */
#define MCUXCLPKC_PS2_SETXY(offsetX, offsetY)  \
    MCUXCLPKC_PS2_SETXY_REG( ((uint32_t) (offsetY) << MCUXCLPKC_SFR_BITPOS(XYPTR2, YPTR)) | (uint32_t) (offsetX) )
/** Sets two offsets to buffers of result R and operand Z of parameter set 2. */
#define MCUXCLPKC_PS2_SETZR(offsetZ, offsetR)  \
    MCUXCLPKC_PS2_SETZR_REG( ((uint32_t) (offsetR) << MCUXCLPKC_SFR_BITPOS(ZRPTR2, RPTR)) | (uint32_t) (offsetZ) )
/** Sets MCLEN and (OP)LEN of parameter set 2. */
#define MCUXCLPKC_PS2_SETLENGTH(mclen, oplen)  \
    MCUXCLPKC_PS2_SETLENGTH_REG(MCUXCLPKC_PS2_PACK((mclen), (oplen)))

#define MCUXCLPKC_PS2_PACK(mclen, oplen)  \
    ( ((uint32_t) (mclen) << MCUXCLPKC_SFR_BITPOS(LEN2, MCLEN)) | (uint32_t) (oplen) )

/** Gets packed MCLEN and (OP)LEN of parameter set 2. */
#define MCUXCLPKC_PS2_GETLENGTH_REG()  mcuxClPkc_inline_ps2_getLengthReg()
/** Gets (OP)LEN of parameter set 2. */
#define MCUXCLPKC_PS2_GETOPLEN()  MCUXCLPKC_SFR_BITREAD(LEN2, LEN)
/** Gets MCLEN of parameter set 2. */
#define MCUXCLPKC_PS2_GETMCLEN()  MCUXCLPKC_SFR_BITREAD(LEN2, MCLEN)

/** Macro to start PKC L0 operation with parameter set 2. */
#define MCUXCLPKC_PS2_START_L0()  \
    do{ MCUXCLPKC_SFR_BITSET(CTRL, GOD2); MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND(); } while(false)
/** Macro to start PKC L1 microcode with parameter set 2. */
#define MCUXCLPKC_PS2_START_L1()  \
    do{ MCUXCLPKC_SFR_BITSET(CTRL, GOM2); MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND(); } while(false)



/**********************************************************/
/* Macros for PKC SFRs: CTRL and CFG                      */
/**********************************************************/
/** Macro to clear CTRL STOP bit and return the latest CTRL (after clearing STOP bit). */
#define MCUXCLPKC_CLEARSTOP()  mcuxClPkc_inline_clearStop()

/**
 * Macro to clear CTRL STOP bit and then set CTRL RESET bit.
 * STOP bit must be cleared before setting RESET, according to PKC specification.
 * This macro will return the latest CTRL (after clearing STOP and setting RESET).
 */
#define MCUXCLPKC_CLEARSTOP_SETRESET()  mcuxClPkc_inline_clearStop_setReset()

/**
 * Macro to clear CTRL RESET bit.
 * Caller shall ensure CTRL STOP bit cleared before calling this macro.
 * Caller shall provide the latest or desired CTRL (for other bits in CTRL).
 */
#define MCUXCLPKC_CLEARRESET(ctrl)  mcuxClPkc_inline_clearReset(ctrl)

/**
 * Macro to set CFG.
 * This macro will also clear CTRL RESET and STOP bits.
 */
#define MCUXCLPKC_SETCFG(cfg)  mcuxClPkc_inline_setCfg(cfg)


/**********************************************************/
/* Other macros                                           */
/**********************************************************/
/** Waits until PKC finishes both on-going and pending calculations (if there is any). */
#define MCUXCLPKC_WAITFORFINISH()  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEAD_CODE("this function polls PKC SFR.")  \
    mcuxClPkc_inline_waitForFinish()  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEAD_CODE()

/** Waits until PKC is ready to accept next calculation (i.e., no pending calculation). */
#define MCUXCLPKC_WAITFORREADY()  \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEAD_CODE("this function polls PKC SFR.")  \
    mcuxClPkc_inline_waitForReady()  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEAD_CODE()

/** Waits PKC calculation and then gets PKC status. */
#define MCUXCLPKC_WAITFORFINISH_GETSTATUS()  \
    MCUX_CSSL_ANALYSIS_COVERITY_START_DEVIATE(MISRA_C_2012_Rule_13_5, "this function read and checks PKC SFR.")  \
    mcuxClPkc_inline_waitForFinishGetStatus() \
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_DEVIATE(MISRA_C_2012_Rule_13_5)

/* Macros to enable and disable GF2 calculation mode. */
#define MCUXCLPKC_ENABLEGF2()   MCUXCLPKC_SFR_BITSET(CTRL, GF2CONV)    ///< Enable GF2 calculation mode.
#define MCUXCLPKC_DISABLEGF2()  MCUXCLPKC_SFR_BITCLEAR(CTRL, GF2CONV)  ///< Disable GF2 calculation mode.

/* Macros to get PKC carry and zero flags. */
#define MCUXCLPKC_GETCARRY()  MCUXCLPKC_SFR_BITREAD(STATUS, CARRY)  ///< Get PKC carry flag.
#define MCUXCLPKC_GETZERO()   MCUXCLPKC_SFR_BITREAD(STATUS, ZERO)   ///< Get PKC zero flag.
#define MCUXCLPKC_FLAG_ZERO     1u  ///< PKC zero flag: result is zero
#define MCUXCLPKC_FLAG_NONZERO  0u  ///< PKC zero flag: result is nonzero
#define MCUXCLPKC_FLAG_CARRY    1u  ///< PKC carry flag: carry occurred
#define MCUXCLPKC_FLAG_NOCARRY  0u  ///< PKC carry flag: carry not occurred

/** Macro to wait PKC calculation and then get carry flag. */
#define MCUXCLPKC_WAITFORFINISH_GETCARRY()  \
    ((MCUXCLPKC_WAITFORFINISH_GETSTATUS() & MCUXCLPKC_SFR_BITMSK(STATUS, CARRY)) >> MCUXCLPKC_SFR_BITPOS(STATUS, CARRY))

/** Macro to wait PKC calculation and then get zero flag. */
#define MCUXCLPKC_WAITFORFINISH_GETZERO()  \
    ((MCUXCLPKC_WAITFORFINISH_GETSTATUS() & MCUXCLPKC_SFR_BITMSK(STATUS, ZERO)) >> MCUXCLPKC_SFR_BITPOS(STATUS, ZERO))


/**********************************************************/
/* Platform-dependent macros                              */
/**********************************************************/
/** PW_READY check is not required. */
#define MCUXCLPKC_PKC_WAIT_PW_READY()  do{} while(false)

/** SFR Mask is not supported. */
#define MCUXCLPKC_CLEARSFRMASK()  do{} while(false)

/** Workaround disabled. */
#define MCUXCLPKC_PKC_CPU_ARBITRATION_WORKAROUND()  do{} while(false)

/** Workaround disabled. */
#define MCUXCLPKC_PKC_BLOCK_CPU_WORKAROUND()  do{} while(false)


#endif /* MCUXCLPKC_MACROS_H_ */
