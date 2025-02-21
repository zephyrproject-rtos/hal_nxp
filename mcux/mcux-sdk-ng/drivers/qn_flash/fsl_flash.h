/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_FLASH_H_
#define FSL_FLASH_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_flash
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief FLASH driver version 2.0.0. */
#define FSL_FLASH_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

#define FLASH_TIME_BASE(clk) \
    (2 * (clk) /             \
     1000000) /*!<Time base of FLASH timing, 2us: 64 cycles in 32 MHz/32 cycles in 16 MHz/16 cycles in 8 MHz*/
#define FLASH_ERASE_TIME_BASE 16000 /*!<Time base of FLASH timing, 2ms: 16000 cycles in 8 MHz(internal fixed clock)*/
#define FLASH_PROG_CYCLE      30    /*!<Program times in normal write mode*/

#define FLASH_SMART_MAX_ERASE_TIME 3 /*When smart erase is used, this is the maximum number of erase operation.*/
#define FLASH_SMART_MAX_WRITE_TIME 3 /*When smart program is used, this is the maximum number of write operation.*/

#define FLASH_ADDR_TO_PAGE(addr) ((uint8_t)((addr) >> 11)) /*!<FLASH address convert to page*/

typedef enum _flash_busy
{
    kFLASH_EraseBusyL = FLASH_STATUS1_FSH_ERA_BUSY_L_MASK,
    kFLASH_WriteBusyL = FLASH_STATUS1_FSH_WR_BUSY_L_MASK,
    kFLASH_EraseBusyH = FLASH_STATUS1_FSH_ERA_BUSY_H_MASK,
    kFLASH_WriteBusyH = FLASH_STATUS1_FSH_WR_BUSY_H_MASK
} flash_busy_t;

typedef enum _flash_status
{
    kStatus_FLASH_Success             = MAKE_STATUS(kStatusGroup_Generic, 0), /*!< flash operation is successful*/
    kStatus_FLASH_Fail                = MAKE_STATUS(kStatusGroup_Generic, 1), /*!< flash operation is not successful*/
    kStatus_FLASH_InvalidArgument     = MAKE_STATUS(kStatusGroup_Generic, 4), /*!< Invalid argument*/
    kStatus_FLASH_AddressError        = MAKE_STATUS(kStatusGroup_FLASH, 0),   /*!< Address is out of range */
    kStatus_FLASH_EraseError          = MAKE_STATUS(kStatusGroup_FLASH, 1),   /*!< The erase operation is error */
    kStatus_FLASH_WriteError          = MAKE_STATUS(kStatusGroup_FLASH, 2),   /*!< The erase operation is error */
    kStatus_FLASH_ProtectionViolation = MAKE_STATUS(
        kStatusGroup_FLASH, 3), /*!< The program/erase operation is requested to execute on protected areas */
    kStatus_FLASH_AHBError     = MAKE_STATUS(kStatusGroup_FLASH, 4), /*!< The AHB operation is error */
    kStatus_FLASH_Busy         = MAKE_STATUS(kStatusGroup_FLASH, 5), /*!< Flash is busy */
    kStatus_FLASH_WriteDmaIdle = MAKE_STATUS(kStatusGroup_FLASH, 6), /*!< Flash write finish */
    kStatus_FLASH_ReadDmaIdle  = MAKE_STATUS(kStatusGroup_FLASH, 7), /*!< Flash read finish */
} flash_status_t;

typedef enum _flash_block
{
    kFLASH_Block0 = 1U, /*!< The block 0 of Flash */
    kFLASH_Block1 = 2U  /*!< The block 1 of Flash */
} flash_block_t;

/**
 * @brief Flash configuration structure
 */
typedef struct _flash_config
{
    uint32_t blockBase;        /*!< A base address of the first block */
    uint32_t totalSize;        /*!< The total size of Flash. */
    uint32_t pageSize;         /*!< The size in bytes of a page of Flash. */
    uint8_t smartMaxEraseTime; /*!< The maximum number of erase attempts for one Smart Erase operation. */
    uint8_t smartMaxWriteTime; /*!< The maximum number of write attempts for one Smart Write operation. */
    uint16_t programCycle;     /*!< The maximum number of write operations in one flash page program. */
    uint32_t timeBase;         /*!< The amount of AHB clock cycles equal to 2 microseconds.*/
    uint32_t eraseTimeBase;    /*!< The amount of internal 8 MHz clock cycles to use for the erase time*/
    bool smartWriteEnable;     /*!< The smart write configuration*/
} flash_config_t;

/**
 * @brief  Flash lock bit Structure definition
 */
typedef struct _flash_lock_bit
{
    uint32_t lockCtrl0; /*!< Flash page lock register0, . */
    uint32_t lockCtrl1; /*!< Flash page lock register1. */
    uint32_t lockCtrl2; /*!< Flash page lock register2. */
    uint32_t lockCtrl3; /*!< Flash page lock register3. */
    uint32_t lockCtrl4; /*!< Flash page lock register4, . */
    uint32_t lockCtrl5; /*!< Flash page lock register5. */
    uint32_t lockCtrl6; /*!< Flash page lock register6. */
    uint32_t lockCtrl7; /*!< Flash page lock register7. */
    uint32_t lockCtrl8; /*!< Flash page lock register8. */
} flash_lock_bit_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*
 * @brief Initializes the FLASH with configuration.
 *
 * This function configures the FLASH module with the user-defined settings.
 * @param config pointer to configuration structure
 * @return none
 */
status_t FLASH_Init(flash_config_t *config);

/*!
 * @brief Get FLASH status flags.
 *
 * This function get all FLASH status flags.
 * @return FLASH status flags.
 */
static inline uint32_t FLASH_GetStatusFlags(void)
{
    return FLASH->INT_STAT;
}

/*!
 * @brief Clears status flags with the provided mask.
 *
 * This function clears FLASH status flags with a provided mask.
 * @param mask The status flags to be cleared
 */
static inline void FLASH_ClearStatusFlags(uint32_t mask)
{
    FLASH->INTCLR = mask;
}

/*!
 * @brief Enables the FLASH interrupt.
 *
 * This function enables the FLASH interrupt.
 *
 * @param mask interrupt source.
 */
static inline void FLASH_EnableInterrupts(uint32_t mask)
{
    FLASH->INTEN |= mask;
}
/*!
 * @brief Disables the FLASH interrupt.
 *
 * This function disables the FLASH interrupt.
 *
 * @param mask interrupt source.
 */
static inline void FLASH_DisableInterrupts(uint32_t mask)
{
    FLASH->INTEN &= ~mask;
}

/*!
 * @brief Get FLASH busy status flags.
 *
 * This function get all FLASH busy status flags.
 * @return FLASH busy status flags.
 */

static inline uint32_t FLASH_GetBusyStatusFlags(void)
{
    return FLASH->STATUS1;
}

/*!
 * @brief  Sets the FLASH configuration structure to default values.
 *
 * This function initializes the UART configuration structure to a default value.
 * @code
 *   config->blockBase = FSL_FEATURE_FLASH_BASE_ADDR;
 *   config->totalSize = FSL_FEATURE_FLASH_SIZE_BYTES;
 *   config->pageSize = FSL_FEATURE_FLASH_PAGE_SIZE_BYTES;
 *   config->eraseTimeBase = FLASH_ERASE_TIME_BASE;
 *   config->timeBase = FLASH_TIME_BASE(ahb_clk);
 *   config->programCycle = FLASH_PROG_CYCLE;
 *   config->smartMaxEraseTime = FLASH_SMART_MAX_ERASE_TIME;
 *   config->smartMaxWriteTime = FLASH_SMART_MAX_WRITE_TIME;
 *   config->smartWriteEnable = false;
 * @endcode
 * @param config pointer to flash config structure
 * @return none
 */
void FLASH_GetDefaultConfig(flash_config_t *config);

/*!
 * @brief Erases flash pages encompassed by parameters passed into function
 *
 * This function erases the appropriate number of flash pages based on the
 * desired start address and length.
 *
 * @param config pointer to configuration structure
 * @param start  Specifies the start address of the FLASH to be erased, the address should be aligned with 4 bytes
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *                      to be erased. Must be word aligned.
 */
status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);

/**
 * @brief Erases a specified FLASH page
 *
 * This function erases a page based on page_index.
 * @param config pointer to configuration structure
 * @param  pageIdx       The page index to be erased
 * @return status
 */
status_t FLASH_PageErase(flash_config_t *config, uint8_t pageIdx);

/**
 * @brief Erases a specified FLASH block
 *
 * This function erases a block based on block.
 * @param config pointer to configuration structure
 * @param  block Specifies the block to be erased
 * @return status
 */
status_t FLASH_BlockErase(flash_config_t *config, uint32_t block);

/**
 * @brief Writes n word data to a specified start address of the FLASH using a polling method
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the addr and n_word.
 * @param base FLASH peripheral base address.
 * @param config pointer to configuration structure
 * @param start  Specifies the start address of the FLASH to be written, the address should be aligned with 4 bytes
 * @param  src  Pointer of the write data buffer
 * @param  lengthInBytes  The size of data to be written
 * @return status
 */
status_t FLASH_Program(flash_config_t *config, uint32_t start, uint32_t *src, uint32_t lengthInBytes);

/**
 * @brief Get FLASH page lock bit
 *
 * This function get the flash page lock bit.
 * @param base  FLASH peripheral base address.
 * @param config pointer to configuration structure
 * @param lockBit  Pointer of the lock bit configuration structure(0: lock; 1: unlock)
 * @return status
 */
status_t FLASH_GetLockBit(flash_config_t *config, flash_lock_bit_t *lockBit);

/**
 * @brief Set FLASH page lock bit
 *
 * This function set the flash page lock bit base based on lockBit.
 * @param base  FLASH peripheral base address.
 * @param config pointer to configuration structure
 * @param lockBit  Pointer of the lock bit configuration structure(0: lock; 1: unlock)
 * @return status
 */
status_t FLASH_SetLockBit(flash_config_t *config, flash_lock_bit_t *lockBit);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* FSL_FLASH_H_*/
