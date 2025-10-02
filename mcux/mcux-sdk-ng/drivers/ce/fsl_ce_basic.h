/*
 * Copyright 2024-2025 NXP
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
 * @brief Executes commands in the command queue.
 * 
 * @return Command execution status.
 */
int32_t CE_ExecCmd(void);

/*!
 * @brief Sends a basic command to verify that ZV2117 is operational
 * and that the command interface is functioning properly.
 *
 * @details This function passes through the command processing interface
 * and returns a success status.
 * 
 * @return Command execution status.
 */
int32_t CE_NullCmd(void);

/*!
 * @brief Copies data between buffers in the ZV2117 memory section.
 *
 * @details Copies a specified number of 32-bit words from the source
 * to the destination buffer. Both buffers must reside in the ZV2117
 * data memory section.
 *
 * @param [out] pDst Pointer to destination buffer
 * @param [in]  pSrc Pointer to source buffer
 * @param [in]  N    Number of 32-bit words to copy
 *
 * @return Command execution status.
 */
int32_t CE_Copy(int32_t *pDst, int32_t *pSrc, const int32_t N);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*FSL_CE_BASIC_H*/
