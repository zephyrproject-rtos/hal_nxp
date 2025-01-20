/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flash.h"
#include "fsl_clock.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_flash"
#endif

#define FLASH_256K (256 * 1024)
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Check the FLASH controller is busy or not.
 *
 * @param base FLASH peripheral base address.
 * @return 0 is not busy.
 */

static inline uint32_t FLASH_BusyStatusCheck(void);
/*!
 * @brief Check the FLASH controller in error status or not.
 *
 * @param base FLASH peripheral base address.
 * @return status_t.
 */
static inline status_t FLASH_StatusCheck(void);
/*******************************************************************************
 * Code
 ******************************************************************************/
static inline uint32_t FLASH_BusyStatusCheck(void)
{
    return (FLASH_GetBusyStatusFlags() &
            (kFLASH_EraseBusyL | kFLASH_WriteBusyL | kFLASH_EraseBusyH | kFLASH_WriteBusyH));
}

static inline status_t FLASH_StatusCheck(void)
{
    uint32_t status = FLASH_GetStatusFlags();
    if (!(status & ~(FLASH_INT_STAT_ERASEL_INT_MASK | FLASH_INT_STAT_WRITEL_INT_MASK | FLASH_INT_STAT_ERASEH_INT_MASK |
                     FLASH_INT_STAT_WRITEH_INT_MASK | FLASH_INT_STAT_WRBUFL_INT_MASK | FLASH_INT_STAT_WRBUFH_INT_MASK)))
    {
        return kStatus_FLASH_Success;
    }
    else if (status & (FLASH_INT_STAT_LOCKL_INT_MASK | FLASH_INT_STAT_LOCKH_INT_MASK))
    {
        return kStatus_FLASH_ProtectionViolation;
    }
    else if (status & (FLASH_INT_STAT_AHBL_INT_MASK | FLASH_INT_STAT_AHBH_INT_MASK))
    {
        return kStatus_FLASH_AHBError;
    }
    else if (status & (FLASH_INT_STAT_WRITE_FAIL_L_INT_MASK | FLASH_INT_STAT_WRITE_FAIL_H_INT_MASK))
    {
        return kStatus_FLASH_WriteError;
    }
    else if (status & (FLASH_INT_STAT_ERASE_FAIL_L_INT_MASK | FLASH_INT_STAT_ERASE_FAIL_H_INT_MASK))
    {
        return kStatus_FLASH_EraseError;
    }
    else
    {
        return kStatus_FLASH_Fail;
    }
}

/*
 * brief Initializes the FLASH with configuration.
 *
 * This function configures the FLASH module with the user-defined settings.
 * param config pointer to configuration structure
 * return none
 */
status_t FLASH_Init(flash_config_t *config)
{
    if (config == NULL)
    {
        return kStatus_FLASH_InvalidArgument;
    }

    FLASH->SMART_CTRL |=
        (FLASH_SMART_CTRL_SMART_ERASEH_EN_MASK | FLASH_SMART_CTRL_SMART_ERASEL_EN_MASK |
         FLASH_SMART_CTRL_MAX_ERASE(config->smartMaxEraseTime) | FLASH_SMART_CTRL_MAX_WRITE(config->smartMaxWriteTime));

    FLASH->TIME_CTRL = FLASH_TIME_CTRL_TIME_BASE(config->timeBase) | FLASH_TIME_CTRL_PRGM_CYCLE(config->programCycle);

    FLASH->ERASE_TIME = FLASH_ERASE_TIME_ERASE_TIME_BASE(config->eraseTimeBase);

    /*load lock bit and protection bit, load redundancy page info*/
    FLASH->INI_RD_EN = FLASH_INI_RD_EN_INI_RD_EN_MASK;
    while ((FLASH_GetBusyStatusFlags() & (FLASH_STATUS1_FSH_STA_MASK | FLASH_STATUS1_INI_RD_DONE_MASK)) !=
           FLASH_STATUS1_INI_RD_DONE_MASK)
    {
    }
    return kStatus_FLASH_Success;
}

/*!
 * brief  Sets the FLASH configuration structure to default values.
 *
 * This function initializes the UART configuration structure to a default value.
 * code
 *   config->blockBase = FSL_FEATURE_FLASH_BASE_ADDR;
 *   config->totalSize = FSL_FEATURE_FLASH_SIZE_BYTES;
 *   config->pageSize = FSL_FEATURE_FLASH_PAGE_SIZE_BYTES;
 *   config->eraseTimeBase = FLASH_ERASE_TIME_BASE;
 *   config->timeBase = FLASH_TIME_BASE(ahb_clk);
 *   config->programCycle = FLASH_PROG_CYCLE;
 *   config->smartMaxEraseTime = FLASH_SMART_MAX_ERASE_TIME;
 *   config->smartMaxWriteTime = FLASH_SMART_MAX_WRITE_TIME;
 *   config->smartWriteEnable = false;
 * endcode
 * param config pointer to flash config structure
 * return none
 */
void FLASH_GetDefaultConfig(flash_config_t *config)
{
    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    uint32_t ahb_freq = CLOCK_GetFreq(kCLOCK_BusClk);

    config->blockBase         = FSL_FEATURE_FLASH_BASE_ADDR;
    config->totalSize         = FSL_FEATURE_FLASH_SIZE_BYTES;
    config->pageSize          = FSL_FEATURE_FLASH_PAGE_SIZE_BYTES;
    config->eraseTimeBase     = FLASH_ERASE_TIME_BASE;
    config->timeBase          = FLASH_TIME_BASE(ahb_freq);
    config->programCycle      = FLASH_PROG_CYCLE;
    config->smartMaxEraseTime = FLASH_SMART_MAX_ERASE_TIME;
    config->smartMaxWriteTime = FLASH_SMART_MAX_WRITE_TIME;
    config->smartWriteEnable  = false;
}
/*!
 * brief Erases flash pages encompassed by parameters passed into function
 *
 * This function erases the appropriate number of flash pages based on the
 * desired start address and length.
 *
 * param config pointer to configuration structure
 * param start  Specifies the start address of the FLASH to be erased, the address should be aligned with 4 bytes
 * param lengthInBytes The length, given in bytes (not words or long-words)
 *                      to be erased. Must be word aligned.
 */
status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    uint32_t status;
    uint32_t mask      = config->totalSize - 1;
    uint8_t page_idx_s = (start & mask) >> 11U;
    uint8_t page_idx_e = ((start + lengthInBytes - 1U) & mask) >> 11U;

    for (int idx = page_idx_s; idx <= page_idx_e; idx++)
    {
        status = FLASH_PageErase(config, idx);
        if (status)
        {
            break;
        }
    }
    return status;
}

/**
 * brief Erases a specified FLASH page
 *
 * This function erases a page based on page_index.
 * param config pointer to configuration structure
 * param  pageIdx       The page index to be erased
 * return status
 */
status_t FLASH_PageErase(flash_config_t *config, uint8_t pageIdx)
{
    if ((config == NULL) || ((pageIdx > 127U) && (config->totalSize == FLASH_256K)))
    {
        return kStatus_FLASH_InvalidArgument;
    }

    if ((pageIdx < 128U) && (config->totalSize != FLASH_256K))
    {
        FLASH->ERASE_CTRL = (FLASH_ERASE_CTRL_PAGE_ERASEL_EN_MASK | FLASH_ERASE_CTRL_PAGE_IDXL(pageIdx));
    }
    else
    {
        FLASH->ERASE_CTRL = (FLASH_ERASE_CTRL_PAGE_ERASEH_EN_MASK | FLASH_ERASE_CTRL_PAGE_IDXH(pageIdx));
    }

    /*Wait the last operation is over.*/
    while (FLASH_BusyStatusCheck())
    {
    }
    return FLASH_StatusCheck();
}

/**
 * brief Erases a specified FLASH block
 *
 * This function erases a block based on block.
 * param config pointer to configuration structure
 * param  block Specifies the block to be erased
 * return status
 */
status_t FLASH_BlockErase(flash_config_t *config, uint32_t block)
{
    if ((config == NULL) || ((block & kFLASH_Block1) && (config->totalSize == FLASH_256K)))
    {
        return kStatus_FLASH_InvalidArgument;
    }
    if (config->totalSize != FLASH_256K)
    {
        FLASH->ERASE_CTRL = ((block << FLASH_ERASE_CTRL_HALF_ERASEL_EN_SHIFT) &
                             (FLASH_ERASE_CTRL_HALF_ERASEL_EN_MASK | FLASH_ERASE_CTRL_HALF_ERASEH_EN_MASK));
    }
    else
    {
        FLASH->ERASE_CTRL = FLASH_ERASE_CTRL_HALF_ERASEH_EN_MASK;
    }

    /*Wait the last operation is over.*/
    while (FLASH_BusyStatusCheck())
    {
    }
    return FLASH_StatusCheck();
}

/**
 * brief Writes n word data to a specified start address of the FLASH using a polling method
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the addr and n_word.
 * param base FLASH peripheral base address.
 * param config pointer to configuration structure
 * param start  Specifies the start address of the FLASH to be written, the address should be aligned with 4 bytes
 * param  src  Pointer of the write data buffer
 * param  lengthInBytes  The size of data to be written
 * return status
 */
status_t FLASH_Program(flash_config_t *config, uint32_t start, uint32_t *src, uint32_t lengthInBytes)
{
    if ((config == NULL) || (src == NULL))
    {
        return kStatus_FLASH_InvalidArgument;
    }

    uint32_t data   = 0U;
    uint32_t offset = 0U;
    uint32_t len    = 0U;
    uint32_t i      = 0U;
    uint32_t j      = config->smartMaxWriteTime;
    uint32_t m      = 0U;
    uint32_t n      = 0U;

    if ((start < config->blockBase) || ((start + lengthInBytes) > (config->blockBase + config->totalSize)))
    {
        return kStatus_FLASH_AddressError;
    }

    if (config->totalSize != FLASH_256K)
    {
        FLASH->SMART_CTRL = ((config->smartWriteEnable ?
                                  (FLASH_SMART_CTRL_SMART_WRITEH_EN_MASK | FLASH_SMART_CTRL_SMART_WRITEL_EN_MASK) :
                                  0U) |
                             FLASH_SMART_CTRL_PRGMH_EN_MASK | FLASH_SMART_CTRL_PRGML_EN_MASK);
    }
    else
    {
        FLASH->SMART_CTRL = ((config->smartWriteEnable ? (FLASH_SMART_CTRL_SMART_WRITEH_EN_MASK) : 0U) |
                             FLASH_SMART_CTRL_PRGMH_EN_MASK);
    }

    while (j--) /*Retry config->smartMaxWriteTime times*/
    {
        uint8_t *tmp_buf  = (uint8_t *)src;
        uint32_t tmp_addr = start;
        /*1- address unaligned with 4 bytes */
        offset = tmp_addr & 0x03U;
        if (offset)
        {
            len  = 4U - offset;
            data = *((volatile uint32_t *)(tmp_addr & (~0x03U)));
            len  = (len < lengthInBytes) ? len : lengthInBytes;
            for (i = 0U; i < len; i++)
            {
                *((uint8_t *)(&data) + offset + i) = *tmp_buf++;
            }
            *((volatile uint32_t *)(tmp_addr & (~0x03U))) = data;
            tmp_addr += len;
        }

        /*2- word copy*/
        m = ((lengthInBytes - len) & 0x7FFFFU) >> 2U;
        n = (lengthInBytes - len) & 0x03U;
        if ((uint32_t)tmp_buf & 0x03U)
        {
            while (m--)
            {
                /*Using byte copy insure the write is ok, while the p_buf is not 4 byte ailgn*/

                union
                {
                    uint32_t word;
                    uint8_t byte[4];
                } tmp;
                tmp.byte[0]                        = *tmp_buf++;
                tmp.byte[1]                        = *tmp_buf++;
                tmp.byte[2]                        = *tmp_buf++;
                tmp.byte[3]                        = *tmp_buf++;
                *((volatile uint32_t *)(tmp_addr)) = tmp.word;
                tmp_addr += 4U;
            }
        }
        else
        {
            while (m--)
            {
                *((volatile uint32_t *)(tmp_addr)) = *((volatile uint32_t *)tmp_buf);
                tmp_addr += 4U;
                tmp_buf += 4U;
            }
        }

        /*3 rest of data*/
        if (n)
        {
            uint32_t last_word = *((volatile uint32_t *)(tmp_addr));
            for (i = 0U; i < n; i++)
            {
                ((uint8_t *)&last_word)[i] = *tmp_buf++;
            }
            *((volatile uint32_t *)(tmp_addr)) = last_word;
        }
        /*wait write over*/
        while (FLASH_BusyStatusCheck())
        {
        }
        if (config->smartWriteEnable)
        {
            return FLASH_StatusCheck();
        }
        else
        {
            uint32_t raddr  = FSL_FEATURE_FLASH_READ_BASE_ADDR | (start & 0x7FFFFU);
            uint8_t *p_buf  = (uint8_t *)src;
            uint32_t n_byte = lengthInBytes;
            while (n_byte && (*p_buf++ == *((volatile uint8_t *)(raddr++))))
            {
                if (n_byte)
                {
                    n_byte--;
                }
            }
            if (!n_byte)
            {
                return kStatus_FLASH_Success;
            }
        }
    }
    return kStatus_FLASH_Fail;
}

/**
 * brief Get FLASH page lock bit
 *
 * This function get the flash page lock bit.
 * param base  FLASH peripheral base address.
 * param config pointer to configuration structure
 * param lockBit  Pointer of the lock bit configuration structure(0: lock; 1: unlock)
 * return status
 */
status_t FLASH_GetLockBit(flash_config_t *config, flash_lock_bit_t *lockBit)
{
    if ((config == NULL) || (lockBit == NULL))
    {
        return kStatus_FLASH_InvalidArgument;
    }

    uint32_t *pLockBit = (uint32_t *)lockBit;

    *pLockBit++ = FLASH->LOCK_STAT0;
    *pLockBit++ = FLASH->LOCK_STAT1;
    *pLockBit++ = FLASH->LOCK_STAT2;
    *pLockBit++ = FLASH->LOCK_STAT3;
    *pLockBit++ = FLASH->LOCK_STAT4;
    *pLockBit++ = FLASH->LOCK_STAT5;
    *pLockBit++ = FLASH->LOCK_STAT6;
    *pLockBit++ = FLASH->LOCK_STAT7;
    *pLockBit   = FLASH->LOCK_STAT8;

    return kStatus_FLASH_Success;
}

/**
 * brief Set FLASH page lock bit
 *
 * This function set the flash page lock bit base based on lockBit.
 * param base  FLASH peripheral base address.
 * param config pointer to configuration structure
 * param lockBit  Pointer of the lock bit configuration structure(0: lock; 1: unlock)
 * return status
 */
status_t FLASH_SetLockBit(flash_config_t *config, flash_lock_bit_t *lockBit)
{
    uint32_t result = kStatus_Success;

    if ((config == NULL) || (lockBit == NULL))
    {
        return kStatus_FLASH_InvalidArgument;
    }

    /*If last page is lock,unlock it*/
    if (!(FLASH->LOCK_STAT7 & 0x80000000U))
    {
        FLASH->ERASE_PASSWORD = 0x5B6C013AU;

        FLASH_PageErase(config, (uint8_t)FLASH_ADDR_TO_PAGE(FSL_FEATURE_FLASH_LOCK_BIT_STORE_ADDR));
        while (FLASH_BusyStatusCheck())
        {
        }
        /*Enable controller read lock information*/
        FLASH->INI_RD_EN = FLASH_INI_RD_EN_INI_RD_EN_MASK;
        while ((FLASH_GetBusyStatusFlags() & (FLASH_STATUS1_FSH_STA_MASK | FLASH_STATUS1_INI_RD_DONE_MASK)) !=
               FLASH_STATUS1_INI_RD_DONE_MASK)
        {
        }
    }
    result = FLASH_Program(config, FSL_FEATURE_FLASH_LOCK_BIT_STORE_ADDR, (uint32_t *)lockBit, 9 * 4);

    /*Enable lock bit setting*/
    FLASH->INI_RD_EN = FLASH_INI_RD_EN_INI_RD_EN_MASK;
    while ((FLASH_GetBusyStatusFlags() & (FLASH_STATUS1_FSH_STA_MASK | FLASH_STATUS1_INI_RD_DONE_MASK)) !=
           FLASH_STATUS1_INI_RD_DONE_MASK)
    {
    }
    return result;
}
