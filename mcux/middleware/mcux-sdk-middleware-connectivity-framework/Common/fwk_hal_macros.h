/*! *********************************************************************************
 * Copyright 2022-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */
#ifndef _HAL_MACROS_H_
#define _HAL_MACROS_H_

#include <stdint.h>
#include <assert.h>

/* Required for __REV definition */
#include "cmsis_compiler.h"

/*============================================================================
                         USEFUL MACROS
=============================================================================*/

/*!
 ****************************************************************************************
 * @brief
 * HAL_CLZ implementation : count leading zeroes from MSB
 * HAL_CTZ implementation : count trailing zeroes from LSB
 * HAL_RBIT implementation : bit mirror 32-bit operation:bit n moves to bit (31-n)
 *
 *****************************************************************************************/
#if defined(__GNUC__)

#define HAL_CLZ(x) ((uint8_t)(__builtin_clz(x) & 0x3fUL))
#define HAL_CTZ(x) ((uint8_t)(__builtin_ctz(x) & 0x3fUL))
static inline uint32_t __hal_revb(uint32_t x)
{
    unsigned int res;
    __asm volatile("rbit    %0, %1  \n\t" : "=r"(res) : "r"(x));
    return res;
}
#define HAL_RBIT(x) __hal_revb(x)

#elif defined(__IAR_SYSTEMS_ICC__)

#define HAL_CLZ(x)  ((uint8_t)(__iar_builtin_CLZ(x) & 0x3fUL))
#define HAL_RBIT(x) ((uint32_t)(__iar_builtin_RBIT(x)))

static inline uint8_t __hal_ctz(uint32_t x)
{
    uint8_t res;
    x   = HAL_RBIT((unsigned int)x);
    res = HAL_CLZ((unsigned int)x);
    return res;
}

#define HAL_CTZ(x) __hal_ctz(x)

#else
#define HAL_CLZ(x) HAL_CLZ_UNDEFINED(x)
#define HAL_CTZ(x) HAL_CTZ_UNDEFINED(x)
#endif

/*!
 ****************************************************************************************
 * @brief
 * HAL_BSR Bit Scan Reverse ( find MSB bit set in a bit field )
 * HAL_BSF Bit Scan Forward ( find LSB bit set in a bit field )
 * HAL_FFS Find First Bit Set Find LSB bit position + 1 per standard ffs definition
 *
 ****************************************************************************************
 */
#define HAL_BSR(x) (((x) != 0UL) ? (uint8_t)(31U - (HAL_CLZ(x) & 0x1fU)) : 0xffU)
#define HAL_BSF(x) HAL_CTZ(x)
#define HAL_FFS(x) (HAL_CTZ(x) + 1U)

/*!
 ****************************************************************************************
 * @brief
 * HAL_REV16 swap bytes in a 16 bit word : useful for htons/ntohs and all endianness conversions
 * HAL_REV32 swap bytes in a 32 bit word : useful for htonl/ntohl and all endianness conversions
 ****************************************************************************************
 */
#if defined(__GNUC__)
#define HAL_REV16(x) ((uint32_t)__builtin_bswap16(x))
#define HAL_REV32(x) ((uint32_t)__builtin_bswap32(x))

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__CC_ARM)

#define HAL_REV16(x) ((uint32_t)__REV16(x))
#define HAL_REV32(x) ((uint32_t)__REV(x))

#endif

#define HAL_HTONS(_x_) HAL_REV16((_x_))
#define HAL_NTOHS(_x_) HAL_REV16((_x_))

#define HAL_HTONL(_x_) HAL_REV32((_x_))
#define HAL_NTOHL(_x_) HAL_REV32((_x_))

#define HAL_BSWAP16(_x_) HAL_REV16((_x_))
#define HAL_BSWAP32(_x_) HAL_REV32((_x_))

/*!
 ****************************************************************************************
 * @brief
 * KB used to define memory sizes expressed in kilobytes
 * MB used to define memory sizes expressed in megabytes
 ****************************************************************************************
 */
#ifndef KB
#define KB(x) (((uint32_t)x) << 10U)
#endif
#ifndef MB
#define MB(x) (((uint32_t)x) << 20U)
#endif

/*!
 ****************************************************************************************
 * @brief
 * KHz used to define frequencies in kHz
 * MHz used to define frequencies in MHz
 ****************************************************************************************
 */
#define KHz(x) (((uint32_t)x) * 1000U)
#define MHz(x) (((uint32_t)x) * 1000000U)

#define SET_BIT(bitmap, i) bitmap[((i) >> 5U)] |= (1U << ((i)&0x1fU))
#define CLR_BIT(bitmap, i) bitmap[((i) >> 5U)] &= ~(1U << ((i)&0x1fU))
#define GET_BIT(bitmap, i) (((bitmap[(i) >> 5U] & (1U << ((i)&0x1fU))) >> ((i)&0x1f)) != 0U)

/* LOG_1, LOG_2, LOG_4, LOG_8: used by LOG macro */
#define LOG_1(n) (((n) >= (1u << 1U)) ? 1U : 0U)
#define LOG_2(n) (((n) >= (1u << 2U)) ? (2U + LOG_1((n) >> 2U)) : LOG_1(n))
#define LOG_4(n) (((n) >= (1u << 4U)) ? (4U + LOG_2((n) >> 4U)) : LOG_2(n))
#define LOG_8(n) (((n) >= (1u << 8U)) ? (8U + LOG_4((n) >> 8U)) : LOG_4(n))
/*
 * Macro to compute log2 (logarithm) of a constant at compile time.
 * Does not make sense for runtime log2 calculation.
 * Computation should be based on __builtin_clz.
 * For in
 *
 */
#define LOG(n) (((n) >= (1U << 16U)) ? (16U + LOG_8((n) >> 16U)) : LOG_8(n))

#if !defined(__IAR_SYSTEMS_ICC__)
#undef BUILD_ASSERT /* clear out common version */
/* C++11 has static_assert built in */
#if defined(__cplusplus) && (__cplusplus >= 201103L)
#define BUILD_ASSERT(EXPR, MSG...) static_assert(EXPR, "" MSG)

/*
 * GCC 4.6 and higher have the C11 _Static_assert built in and its
 * output is easier to understand than the common BUILD_ASSERT macros.
 * Don't use this in C++98 mode though (which we can hit, as
 * static_assert() is not available)
 */
#elif !defined(__cplusplus) && \
    ((__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)) || (__STDC_VERSION__) >= 201100)
#define BUILD_ASSERT(EXPR, MSG...) _Static_assert(EXPR, "" MSG)
#else
#define BUILD_ASSERT(EXPR, MSG...)
#endif

/**
 * @brief Validate if two entities have a compatible type
 *
 * @param a the first entity to be compared
 * @param b the second entity to be compared
 * @return 1 if the two elements are compatible, 0 if they are not
 */
#define SAME_TYPE(a, b) __builtin_types_compatible_p(__typeof__(a), __typeof__(b))

/**
 * @brief Validate CONTAINER_OF parameters, only applies to C mode.
 */
#ifndef __cplusplus
#define CONTAINER_OF_VALIDATE(ptr, type, field)                                    \
    BUILD_ASSERT(SAME_TYPE(*(ptr), ((type *)0)->field) || SAME_TYPE(*(ptr), void), \
                 "pointer type mismatch in CONTAINER_OF");
#else  /* __cplusplus */
#define CONTAINER_OF_VALIDATE(ptr, type, field)
#endif /* __cplusplus */
#else  /* __IAR_SYSTEMS_ICC__ */
/* No CONTAINER_OF_VALIDATE macros for IAR */
#define CONTAINER_OF_VALIDATE(ptr, type, field)
/* Neither BUILD_ASSERT nor  SAME_TYPE defined for IAR */
#endif /* __IAR_SYSTEMS_ICC__ */

#define _DO_CONCAT(x, y) x##y
#define _CONCAT(x, y)    _DO_CONCAT(x, y)

#define DECL_ALIGN(type) __aligned(__alignof(type)) type

/**
 * @brief Get a pointer to a structure containing the element
 *
 * Example:
 *
 *	struct foo {
 *		int bar;
 *	};
 *
 *	struct foo my_foo;
 *	int *ptr = &my_foo.bar;
 *
 *	struct foo *container = CONTAINER_OF(ptr, struct foo, bar);
 *
 * Above, @p container points at @p my_foo.
 *
 * @param ptr pointer to a structure element
 * @param type name of the type that @p ptr is an element of
 * @param field the name of the field within the struct @p ptr points to
 * @return a pointer to the structure that contains @p ptr
 */
#define CONTAINER_OF(_PTR_, _TYPE_, _FIELD_)                                 \
    ({                                                                       \
        CONTAINER_OF_VALIDATE(_PTR_, _TYPE_, _FIELD_)                        \
        ((_TYPE_ *)(void *)(((char *)(_PTR_)) - offsetof(_TYPE_, _FIELD_))); \
    })

static inline uint32_t HAL_GetPowerOfTwoShift(uint32_t x)
{
    uint32_t ret;
    uint32_t clz_result;
    uint32_t shift_nbr;

    if (x <= 1U)
    {
        ret = 0U;
    }
    else
    {
        assert(x <= ((0xFFFFFFFFU >> 1) + 1U));

        /* Use Count Leading Zeros to round x to the smallest power of two greater than or equal to x */
        clz_result = (uint32_t)HAL_CLZ(x - 1U);
        shift_nbr  = (uint32_t)32U - clz_result;

        x = (uint32_t)1U << shift_nbr;

        /* Use Count Trailing Zeros to get the shift */
        ret = HAL_CTZ(x);
    }

    return ret;
}

/**
 * @brief Computes the shift count needed to represent a number as a power of two.
 *
 * This function calculates the number of right shifts required to reduce a power-of-two
 * number equal to or greater than the input value `x` down to 1.
 *
 * @param x Input value.
 * @return uint32_t Number of shifts.
 */

#define HAL_GETPOWEROF2SHIFT(x) HAL_GetPowerOfTwoShift(x)

#endif
