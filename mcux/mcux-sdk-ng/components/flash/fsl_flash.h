/*
 * Copyright  2017 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_Flash_H_
#define _FSL_Flash_H_

#include "fsl_common.h"
#include "fsl_spi_adapter.h"

/*!
 * @addtogroup flash_adapter
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define NOR_FLASH_MAX_COMMAND_SZIE 4

/*! @brief Flash error code structure. */
typedef enum
{
    flash_ok,          /*!< Flash status code: OK. */
    flash_too_big,     /*!< Flash status code: Too Big. */
    flash_not_aligned, /*!< Flash status code: Not Aligned. */
    flash_busy,        /*!< Flash status code: BUSY. */
    flash_error        /*!< Flash status code: ERROR. */
} flash_err_t;

/*! @brief Flash operation code structure. */
typedef enum _flash_op_code
{
    kNorFlash_WriteEnable = 0x0, /*!< Operation code: WREN. */
    kNorFlash_Write       = 0x1, /*!< Operation code: Page Program. */
    kNorFlash_Read        = 0x2, /*!< Operation code: Read Data. */
    kNorFlash_ReadStatus  = 0x3, /*!< Operation code: Read Status Register. */
    kNorFlash_EraseSector = 0x4, /*!< Operation code: Erase sector. */
    kNorFlash_EraseChip   = 0x5, /*!< Operation code: Erase whole chip. */
} flash_op_code_t;

/*! @brief Flash config structure. */
typedef struct _flash_config
{
    uint32_t totalSize;      /*!< Total flash size. */
    uint32_t pageSize;       /*!< Page size. */
    uint32_t sectorSize;     /*!< Sector size. */
    bool needWriteEnable;    /*!< Need do write enable before write/erase operation. */
    uint8_t statusValueSize; /*!< Status value size in bytes. */
    uint32_t statusBusyMask; /*!< Status busy mask. */
    uint8_t statusBusyValue; /*!< Status busy value. */
} flash_config_t;

/*! @brief Flash transfer structure. */
typedef struct _flash_transfer
{
    flash_op_code_t opCode; /*!< Operation code. */
    uint8_t address;        /*!< Program/write address. */
    uint8_t *data;          /*!< Data buffer pointer for program buffer or store buffer. */
    uint32_t dataSize;      /*!< Data buffer size. */
} flash_transfer_t;

/*! @brief Flash handle. */
typedef struct _flash_handle
{
    flash_err_t (*executeCommand)(void *resource, flash_transfer_t *xfer); /*!< Execute command function. */
    void *resource;          /*!< Pointer for resource, resource mean the SPI adapter resource. */
    uint32_t totalSize;      /*!< Flash total size. */
    uint32_t pageSize;       /*!< Flash page size. */
    uint32_t sectorSize;     /*!< Flash sector size. */
    bool needWriteEnable;    /*!< Need do write enable before write/erase operation. */
    uint8_t statusValueSize; /*!< Status value size in bytes. */
    uint32_t statusBusyMask; /*!< Status busy mask. */
    uint8_t statusBusyValue; /*!< Status busy value. */
} flash_handle_t;
/*! @}*/
#endif
