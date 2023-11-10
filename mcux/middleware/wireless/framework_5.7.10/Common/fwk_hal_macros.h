/*! *********************************************************************************
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * \file
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */
#ifndef _HAL_MACROS_H_
#define _HAL_MACROS_H_

/* Required for __REV definition */
#if defined (__IAR_SYSTEMS_ICC__)
#include "cmsis_iccarm.h"
#endif



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

#if defined (__GNUC__)

#define HAL_CLZ(x) __builtin_clz(x)
#define HAL_CTZ(x) __builtin_ctz(x)
static inline uint32_t __hal_revb(uint32_t x)
{
    unsigned int res;
    __asm volatile ("rbit    %0, %1  \n\t"
                    : "=r" (res)
                    : "r" (x));
    return res;
}
#define HAL_RBIT(x) __hal_revb(x)

#elif defined (__IAR_SYSTEMS_ICC__)

#define HAL_CLZ(x) __iar_builtin_CLZ(x)
#define HAL_RBIT(x) __iar_builtin_RBIT(x)

static inline uint32_t __hal_ctz(uint32_t x)
{
    uint32_t res;
    x = (uint32_t)HAL_RBIT((unsigned int)x);
    res = (uint32_t)HAL_CLZ((unsigned int)x);
    return res;
}

#define HAL_CTZ(x) __hal_ctz(x)


#else
static inline uint32_t count_leading_zeroes(uint32_t x)
{
    uint32_t i = 32u;
    if (x != 0u)
    {
        for (i = 0; i < 32; i++)
        {
            if (x & (1<<(31-i)))
                break;
        }
    }
    return i;
}

static inline uint32_t count_trailing_zeroes(uint32_t x)
{
    uint32_t i = 32u;
    if (x != 0u)
    {
        for (i = 0; i < 32; i++)
        {
            if (x & (1<<i))
                break;
        }
    }
    return i;
}

#define HAL_CLZ(x) count_leading_zeroes(x)
#define HAL_CTZ(x) count_trailing_zeroes(x)
#endif



/*!
 ****************************************************************************************
 * @brief
 * HAL_BSR Bit Scan Reverse ( find MSB bit set in a bit field )
 * HAL_BSF Bit Scan Forward ( find LSB bit set in a bit field )
 * HAL_FFS Find LSB bit position + 1 per standard ffs definition
 *
 ****************************************************************************************
 */
#define HAL_BSR(x) (31 - HAL_CLZ(x))
#define HAL_BSF(x) HAL_CTZ(x)
#define HAL_FFS(x) (HAL_CTZ(x) + 1)


/*!
 ****************************************************************************************
 * @brief
 * HAL_REV16 swap bytes in a 16 bit word : useful for htons/ntohs and all enddianness conversions
 * HAL_REV32 swap bytes in a 32 bit word : useful for htonl/ntohl and all enddianness conversions
 ****************************************************************************************
 */
#if defined (__GNUC__)
#define HAL_REV16(x) __builtin_bswap16(x)
#define HAL_REV32(x)  __builtin_bswap32(x)

#elif defined (__IAR_SYSTEMS_ICC__)

#define HAL_REV16(x) __REV16(x)
#define HAL_REV32(x) __REV(x)

#endif


#define HAL_HTONS(_x_)  HAL_REV16((_x_))
#define HAL_NTOHS(_x_)  HAL_REV16((_x_))

#define HAL_HTONL(_x_)  HAL_REV32((_x_))
#define HAL_NTOHL(_x_)  HAL_REV32((_x_))

#define HAL_BSWAP16(_x_) HAL_REV16((_x_))
#define HAL_BSWAP32(_x_) HAL_REV32((_x_))

#endif
