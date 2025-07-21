/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CE_BASIC_H
#define FSL_CE_BASIC_H

#include <stdint.h>

/*!
 * @ingroup ce
 * @defgroup ce_basic CE Basic Functions
 * @brief Functional API definitions for ARM drivers for CE basic functions
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Execute command in command queue
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_ExecCmd();

/*!
 * @brief Simple echo test cmd
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_NullCmd();

/*!
 * @brief Copies one memory buffer to another
 *
 * Copies one memory buffer to another. Copy is in units of words. Any data type
 * can be used.
 *
 * @param pDst Pointer to destination buffer
 * @param pSrc Pointer to source buffer
 * @param N    Number of words to copy
 *
 * @return Return 0 if succeeded, otherwise return error code.
 */
int CE_Copy(int *pDst, int *pSrc, const int N);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_BASIC_H*/
