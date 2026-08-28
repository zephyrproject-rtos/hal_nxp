/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023, 2025 NXP                                            */
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

#ifndef COMPILER_TOOLCHAIN_H_
#define COMPILER_TOOLCHAIN_H_

/* for armclang */
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #define MCUX_FUP_ATTRIBUTE __attribute__((aligned(4))) __attribute__((section("MCUX_OBFUSCATED_FUP_SEGMENT")))
    #define UNUSED_PARAM __attribute__((unused))
    /*
        Use of UNALIGNED on ARMCLANG

        The __unaligned keyword is a type qualifier that tells the compiler to treat the pointer or variable as an unaligned pointer or variable.
        www.keil.com/support/man/docs/armclang_ref/armclang_ref_pfl1493130433688.htm

        The use of __attribute__((packed)) is incorrect on ARMCLANG

        The packed type attribute specifies that a type must have the smallest possible alignment. This attribute only applies to struct and union types.
        www.keil.com/support/man/docs/armclang_ref/armclang_ref_chr1393328521340.htm

        -munaligned-access is the default for architectures that support unaligned accesses to data. This default applies to all architectures supported by Arm Compiler for Embedded 6, except Armv6-M, and Armv8-M without the Main Extension.
    */
    #define UNALIGNED __unaligned
    #define MCUX_CSSL_UNUSED(p) ((void) (p))
    /* Macro for alligning buffers to cpu word */
    #define ALIGNED __attribute__((aligned(4)))
    #define ALIGNED_N(x) __attribute__((aligned(x)))
    #define NORETURN __attribute__((__noreturn__))
    #define ALWAYS_INLINE __attribute__((always_inline))

/* using the gcc toolchain file for both gcc and armgcc */
#elif defined ( __GNUC__ )
    #define MCUX_FUP_ATTRIBUTE __attribute__((aligned(4)))
    #define UNUSED_PARAM __attribute__((unused))
    #ifndef __x86_64
    #define UNALIGNED
    #endif
    /* Macro for alligning buffers to cpu word */
    #define ALIGNED __attribute__((aligned(4)))
    #define ALIGNED_N(x) __attribute__((aligned(x)))
    #define NORETURN __attribute__((__noreturn__))
    #if !defined(ALWAYS_INLINE) /* Zephyr defines this as well */
    #define ALWAYS_INLINE __attribute__((always_inline))
    #endif

/* for armcc compiler */
#elif defined ( __CC_ARM )
    #define MCUX_FUP_ATTRIBUTE __attribute__((aligned(4))) __attribute__((section("MCUX_OBFUSCATED_FUP_SEGMENT")))
    #define UNUSED_PARAM __attribute__((unused))
    #define UNALIGNED __packed
    /* Macro for alligning buffers to cpu word */
    #define ALIGNED __attribute__((aligned(4)))
    #define ALIGNED_N(x) __attribute__((aligned(x)))
    #define NORETURN __attribute__((__noreturn__))
    #define ALWAYS_INLINE __attribute__((always_inline))

/* for ghs compiler */
#elif defined ( __ghs__ )
    #define MCUX_FUP_ATTRIBUTE __attribute__((aligned(4)))
    #define UNUSED_PARAM __attribute__((unused))
    #define UNALIGNED
    /* Macro for alligning buffers to cpu word */
    #define ALIGNED __attribute__((aligned(4)))
    #define ALIGNED_N(x) __attribute__((aligned(x)))
    #define NORETURN __attribute__((__noreturn__))
    #define ALWAYS_INLINE __attribute__((always_inline))

/* for iar compiler */
#elif defined ( __ICCARM__ )
    #define MCUX_FUP_ATTRIBUTE __attribute__((aligned(4))) __attribute__((section(".mcux_obfuscated_fup_segment")))
    #define UNUSED_PARAM __attribute__((unused))
    #define UNALIGNED __packed
    /* Macro for alligning buffers to cpu word */
    #define ALIGNED __attribute__((aligned(4)))
    #define ALIGNED_N(x) __attribute__((aligned(x)))
    #define NORETURN __attribute__((__noreturn__))
    #define ALWAYS_INLINE __attribute__((always_inline))

/* for llvm */
#elif defined ( __clang__ )
    #define MCUX_FUP_ATTRIBUTE __attribute__((aligned(4)))
    #define UNUSED_PARAM __attribute__((unused))
    #define UNALIGNED
    /* Macro for alligning buffers to cpu word */
    #define ALIGNED __attribute__((aligned(4)))
    #define ALIGNED_N(x) __attribute__((aligned(x)))
    #define NORETURN __attribute__((__noreturn__))
    #define ALWAYS_INLINE __attribute__((always_inline))

/* for dsp56800x */
#elif defined ( __m56800E__ )
    #define MCUX_FUP_ATTRIBUTE __attribute__((aligned(4)))
    #define UNUSED_PARAM __attribute__((unused))
    #define UNALIGNED
    /* Macro for alligning buffers to cpu word */
    #define ALIGNED __attribute__((aligned(4)))
    #define ALIGNED_N(x) __attribute__((aligned(x)))
    #define NORETURN __attribute__((__noreturn__))
    #define ALWAYS_INLINE __attribute__((always_inline))
#endif


#if defined(__ghs__) || defined( __ICCARM__ ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)) || defined(__GNUC__)
    #define GHS_ICCARM_ARMCC_GT_10_5_GNUC
#endif

#if defined(__ghs__) || defined(__gcc__) || defined(__ICCARM__) || defined(__GNUC__)
    #define GHS_GCC_ICCARM_GNUC
#endif

#if defined(__ghs__) || defined(__gcc__) || defined(__ICCARM__)
    #define GHS_GCC_ICCARM
#endif

#if defined(__ICCARM__) || defined(__ARMCC_VERSION) || defined(__CC_ARM) || defined(__GNUC__)
    #define ICCARM_ARMCC_GNUC
#endif

#if defined(__ICCARM__) || defined(__ARMCC_VERSION) || defined(__GNUC__)
    #define ICCARM_ARMCLANG_GNUC
#endif

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION < 6010050)
    #define ARMCC_LT_10_5 //6.01 build 0050
#endif


#if defined ( __CC_ARM )
/* Arm Compiler 4/5 */
#define MCUX_CL_COMPILER_ARMCC
#define MCUX_CL_COMPILER_ARM_COMPILER

#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) && (__ARMCC_VERSION < 6100100)
/* Arm Compiler 6.6 LTM (armclang) */
#define MCUX_CL_COMPILER_ARMCLANG_LTM
#define MCUX_CL_COMPILER_ARM_COMPILER

#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6100100)
/* Arm Compiler above 6.10.1 (armclang) */
#define MCUX_CL_COMPILER_ARMCLANG
#define MCUX_CL_COMPILER_ARM_COMPILER

#elif defined (_clang_)
#define MCUX_CL_COMPILER_ARM_COMPILER /* i.e. Version 6.01 build 0019  */
#endif


#if ( defined(__ARMCC_VERSION) || defined(_MSC_VER) ) && !defined(inline) && !defined(__cplusplus)
    #define ARMCC_MSC_VER_NOT_INLINE_NOT_CPP
#endif

#endif /* COMPILER_TOOLCHAIN_H_ */
