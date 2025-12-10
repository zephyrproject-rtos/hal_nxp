/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566.h
 * @version 2.0
 * @date 2025-04-14
 * @brief Peripheral Access Layer for S32K566
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(S32K566_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K566_COMMON_H_

#include "OsIf_ArchCfg.h"

#ifdef MCAL_PLATFORM_ARM
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
        #include "S32K566_R52_COMMON.h"
    #elif (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)
        #if defined(MCAL_PLATFORM_ARM_M7)
            #include "S32K566_M7_COMMON.h"
        #elif defined(MCAL_PLATFORM_ARM_M4)
            #include "S32K566_M4_COMMON.h"
        #endif
    #else
        #error Unknown CPU
    #endif
#else
    #ifdef MCAL_PLATFORM_ZENV
        #include "S32K566_DSPV_COMMON.h"
    #else
        #error Unknown CPU
    #endif
#endif /* MCAL_PLATFORM_ARM*/

#endif  /* #if !defined(S32K566_COMMON_H_) */

