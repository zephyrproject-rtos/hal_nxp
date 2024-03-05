/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __FSL_LPSPI_NOR_FLASH_H__
#define __FSL_LPSPI_NOR_FLASH_H__

#include "fsl_common.h"
#include "fsl_lpspi.h"
#include "fsl_nor_flash.h"

/*!
 * @addtogroup lpspi_nor_flash
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Erase 4K block.
 *
 * @param handle    The NOR Flash handler.
 * @param address   The start address to be erased.
 * @retval execution status
 */
status_t Nor_Flash_Erase_Block_4K(nor_handle_t *handle, uint32_t address);

/*!
 * @brief Erase 32K block.
 *
 * @param handle    The NOR Flash handler.
 * @param address   The start address to be erased.
 * @retval execution status
 */
status_t Nor_Flash_Erase_Block_32K(nor_handle_t *handle, uint32_t address);

/*!
 * @brief Erase 64K block.
 *
 * @param handle    The NOR Flash handler.
 * @param address   The start address to be erased.
 * @retval execution status
 */
status_t Nor_Flash_Erase_Block_64K(nor_handle_t *handle, uint32_t address);

/*!
 * @brief Prepare the NOR flash for low power entry
 *
 * @param handle The NOR Flash handler.
 * @retval status_t execution status
 */
status_t Nor_Flash_Enter_Lowpower(nor_handle_t *handle);

/*!
 * @brief Prepare the NOR flash for low power exit
 *
 * @param handle The NOR Flash handler.
 * @retval status_t execution status
 */
status_t Nor_Flash_Exit_Lowpower(nor_handle_t *handle);

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif /* __FSL_LPSPI_NOR_FLASH_H__ */
