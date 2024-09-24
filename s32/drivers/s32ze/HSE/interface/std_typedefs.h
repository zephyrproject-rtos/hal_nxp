/*
 * Copyright 2019-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STD_TYPEDEFS_H
#define STD_TYPEDEFS_H

#ifdef __cplusplus
extern "C"{
#endif

#if defined(CUSTOM_STDINT_H)
    /* Define at compile time the header file containing the definition for custom types from stdint */
    #include CUSTOM_STDINT_H
#else
    #if !defined(NO_STDINT_H)
    /* Default - include stdint.h */
        #include <stdint.h>
        #include <stdbool.h>
    #endif /* !defined(NO_STDINT_H) */
#endif

/* Standard typedefs used by header files, based on ISO C standard */
typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef volatile int64_t vint64_t;
typedef volatile uint64_t vuint64_t;

typedef uint8_t bool_t;

#ifndef TRUE
    /**
    * @brief Boolean true value
    */
    #define TRUE true
#endif
#ifndef FALSE
    /**
    * @brief Boolean false value
    */
    #define FALSE false
#endif

#ifndef NULL
    #define NULL ((void *)0)
#endif

#ifdef __cplusplus
}
#endif

#endif /*  STD_TYPEDEFS_H */

/** @} */
