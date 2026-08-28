/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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

#ifndef MCUX_CSSL_ASSEMBLY_H_
#define MCUX_CSSL_ASSEMBLY_H_

#include <mcuxCsslCPreProcessor.h>

/* for armclang */
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#define MCUX_CSSL_ASM_LABEL(name) \
  name:

#define MCUX_CSSL_ASM_FILE_START() \
  .syntax unified

#define MCUX_CSSL_ASM_FILE_END()

#define MCUX_CSSL_ASM_FUNC_ALIGNMENT() \
  .align 2

#define MCUX_CSSL_ASM_FUNC_SECTION(name) \
  .section MCUX_CSSL_CPP_CAT(.text.,name)

#define MCUX_CSSL_ASM_FUNC_SYMBOL_GLOBAL(name) \
  .global name

#define MCUX_CSSL_ASM_FUNC_SYMBOL(name) \
  .type name,"function"

#define MCUX_CSSL_ASM_FUNC_START(name) \
  MCUX_CSSL_ASM_LABEL(name)

#define MCUX_CSSL_ASM_FUNC_END(name)


/* for llvm */
#elif defined ( __clang__ )
#define MCUX_CSSL_ASM_LABEL(name) \
  name:

#define MCUX_CSSL_ASM_FILE_START() \
  .syntax unified

#define MCUX_CSSL_ASM_FILE_END()

#define MCUX_CSSL_ASM_FUNC_ALIGNMENT() \
  .align 2

#define MCUX_CSSL_ASM_FUNC_SECTION(name) \
  .section MCUX_CSSL_CPP_CAT(.text.,name)

#define MCUX_CSSL_ASM_FUNC_SYMBOL_GLOBAL(name) \
  .global name

#define MCUX_CSSL_ASM_FUNC_SYMBOL(name) \
  .type name,"function"

#define MCUX_CSSL_ASM_FUNC_START(name) \
  MCUX_CSSL_ASM_LABEL(name)

#define MCUX_CSSL_ASM_FUNC_END(name)

/* using the gcc toolchain file for both gcc and armgcc */
#elif defined ( __GNUC__ )
#define MCUX_CSSL_ASM_LABEL(name) \
  name:

#define MCUX_CSSL_ASM_FILE_START() \
  .syntax unified

#define MCUX_CSSL_ASM_FILE_END()

#define MCUX_CSSL_ASM_FUNC_ALIGNMENT() \
  .align 2

#define MCUX_CSSL_ASM_FUNC_SECTION(name) \
  .section MCUX_CSSL_CPP_CAT(.text.,name)

#define MCUX_CSSL_ASM_FUNC_SYMBOL_GLOBAL(name) \
  .global name

#define MCUX_CSSL_ASM_FUNC_SYMBOL(name) \
  .type name,"function"

#define MCUX_CSSL_ASM_FUNC_START(name) \
  MCUX_CSSL_ASM_LABEL(name)

#define MCUX_CSSL_ASM_FUNC_END(name)

/* for armcc compiler */
#elif defined ( __CC_ARM )
#define MCUX_CSSL_ASM_FILE_START()

#define MCUX_CSSL_ASM_FILE_END() \
  MCUX_CSSL_CPP_EMPTY()    END

#define MCUX_CSSL_ASM_LABEL(name) \
  name

#define MCUX_CSSL_ASM_FUNC_SECTION(name) \
  MCUX_CSSL_CPP_EMPTY()    AREA MCUX_CSSL_CPP_CAT3(|i.,name,|), CODE, ALIGN=4

#define MCUX_CSSL_ASM_FUNC_ALIGNMENT() \
  MCUX_CSSL_CPP_EMPTY()    ALIGN

#define MCUX_CSSL_ASM_FUNC_SYMBOL(name) \
  MCUX_CSSL_CPP_EMPTY()    EXPORT name

#define MCUX_CSSL_ASM_FUNC_START(name) \
  MCUX_CSSL_ASM_LABEL(name) FUNCTION

#define MCUX_CSSL_ASM_FUNC_END(name) \
  MCUX_CSSL_CPP_EMPTY()    ENDFUNC

/* for ghs compiler */
#elif defined ( __ghs__ )
#define MCUX_CSSL_ASM_LABEL(name) \
  name:

#define MCUX_CSSL_ASM_FILE_START()

#define MCUX_CSSL_ASM_FILE_END()

#define MCUX_CSSL_ASM_FUNC_ALIGNMENT() \
  .align 2

#define MCUX_CSSL_ASM_FUNC_SECTION(name) \
  .section MCUX_CSSL_CPP_CAT(.text.,name), "ax"

#define MCUX_CSSL_ASM_FUNC_SYMBOL_GLOBAL(name) \
  .global name

#define MCUX_CSSL_ASM_FUNC_SYMBOL(name) \
  .type name, $function

#define MCUX_CSSL_ASM_FUNC_START(name) \
  name::

#define MCUX_CSSL_ASM_FUNC_END(name)

/* for iar compiler */
#elif defined ( __ICCARM__ ) || defined ( __IASMARM__ )
#define MCUX_CSSL_ASM_LABEL(name) \
  name:

#define MCUX_CSSL_ASM_FILE_START() \


#define MCUX_CSSL_ASM_FILE_END() \
  MCUX_CSSL_CPP_EMPTY()    END

#define MCUX_CSSL_ASM_FUNC_ALIGNMENT() \
  MCUX_CSSL_CPP_EMPTY()    THUMB

#define MCUX_CSSL_ASM_FUNC_SECTION(name) \
  MCUX_CSSL_CPP_EMPTY()    SECTION .text:CODE(2)

#define MCUX_CSSL_ASM_FUNC_SYMBOL(name) \
  MCUX_CSSL_CPP_EMPTY()    PUBLIC name

#define MCUX_CSSL_ASM_FUNC_START(name) \
  MCUX_CSSL_ASM_LABEL(name)

#define MCUX_CSSL_ASM_FUNC_END(name)

#define MCUX_CSSL_ASM_FUNC_SYMBOL_GLOBAL(name)

#else
#error Unsupported assembler
#endif

#endif /* MCUX_CSSL_ASSEMBLY_H_ */
