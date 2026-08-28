/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*!
 * \file This file provides static inline utility functions for checking signed
 *       overflow or unsigned wrapping for various types and operations.
 */

#ifndef MCUX_PSA_UTIL_WRAPCHECK_STATIC_INLINE_H
#define MCUX_PSA_UTIL_WRAPCHECK_STATIC_INLINE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


/******************************************************************************/
/*                                  uint32_t                                  */
/******************************************************************************/

/*!
 * \brief Check if addition of two 32-bit unsigned integers would wrap.
 *
 * \param[in] a 32-bit unsinged integer operand 'a'
 * \param[in] b 32-bit unsinged integer operand 'b'
 *
 * \retval true if addition wrap would occur, false if no wrap occurs
 */
static inline bool mcux_psa_add_uint32_t_wrapcheck(uint32_t a, uint32_t b)
{
    if ((UINT32_MAX - a) < b)
    {
        return true;
    }
    return false;
}

/*!
 * \brief Check if subtraction of two 32-bit unsigned integers would wrap.
 *
 * \param[in] a 32-bit unsinged integer operand 'a'
 * \param[in] b 32-bit unsinged integer operand 'b'
 *
 * \retval true if subtraction wrap would occur, false if no wrap occurs
 */
static inline bool mcux_psa_sub_uint32_t_wrapcheck(uint32_t a, uint32_t b)
{
    if (a < b)
    {
        return true;
    }
    return false;
}

/******************************************************************************/
/*                                   size_t                                   */
/******************************************************************************/

/*!
 * \brief Check if addition of two size_t integers would wrap.
 *
 * \param[in] a size_t integer operand 'a'
 * \param[in] b size_t integer operand 'b'
 *
 * \retval true if addition wrap would occur, false if no wrap occurs
 */
static inline bool mcux_psa_add_size_t_wrapcheck(size_t a, size_t b)
{
    if ((SIZE_MAX - a) < b)
    {
        return true;
    }
    return false;
}

/*!
 * \brief Check if subtraction of two size_t integers would wrap.
 *
 * \param[in] a size_t integer operand 'a'
 * \param[in] b size_t integer operand 'b'
 *
 * \retval true if subtraction wrap would occur, false if no wrap occurs
 */
static inline bool mcux_psa_sub_size_t_wrapcheck(size_t a, size_t b)
{
    if (a < b)
    {
        return true;
    }
    return false;
}

/*!
 * \brief Check if multiplication of two size_t integers would wrap.
 *
 * \param[in] a size_t integer operand 'a'
 * \param[in] b size_t integer operand 'b'
 *
 * \retval true if multiplication wrap would occur, false if no wrap occurs
 */
static inline bool mcux_psa_mul_size_t_wrapcheck(size_t a, size_t b)
{
    if ((0u != b) && (a > (SIZE_MAX / b)))
    {
        return true;
    }
    return false;
}

#endif /* MCUX_PSA_UTIL_WRAPCHECK_STATIC_INLINE_H */
