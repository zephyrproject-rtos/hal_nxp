/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <string.h>

#include "mflash_drv.h"
#include "fsl_flash.h"
#include "fsl_cache.h"

static flash_config_t flash_ctx;


/* API - initialize 'mflash' */
int32_t mflash_drv_init(void)
{
    status_t result;

    memset(&flash_ctx, 0, sizeof(flash_ctx));

    result = FLASH_Init(&flash_ctx);
    if (result != kStatus_Success)
    {
        return result;
    }

    return kStatus_Success;
}

/* API - Erase single sector */
int32_t mflash_drv_sector_erase(uint32_t sector_addr)
{
    status_t ret;
    uint32_t primask;
    uint32_t logaddr = MFLASH_BASE_ADDRESS + sector_addr;

    if ((sector_addr % MFLASH_SECTOR_SIZE) != 0UL)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    /* Check and unlock sector protection inside critical section */
    ret = FLASH_GetSectorProtection(&flash_ctx, logaddr);
    
    if (ret == kStatus_FLASH_SectorLocked)
    {
        ret = FLASH_SetSectorProtection(&flash_ctx, logaddr, false);
        if (ret != kStatus_FLASH_Success)
        {
            if (primask == 0UL)
            {
                __enable_irq();
            }
            return ret;
        }
    }
    else if (ret != kStatus_FLASH_Success)
    {
        /* GetSectorProtection returned an error - continue anyway,
        better handling to be implemented */
    }

    ret = FLASH_Erase(&flash_ctx, logaddr, MFLASH_SECTOR_SIZE, kFLASH_ApiEraseKey);

    /* Invalidate DCache if enabled */
    if (SCB_CCR_DC_Msk == (SCB_CCR_DC_Msk & SCB->CCR))
    {
        DCACHE_InvalidateByRange(logaddr, MFLASH_SECTOR_SIZE);
    }

    if (primask == 0UL)
    {
        __enable_irq();
    }

    __ISB();

    return ret;
}

/* API - Page program */
int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    status_t ret;
    uint32_t primask;
    uint32_t logaddr = MFLASH_BASE_ADDRESS + page_addr;

    if ((page_addr % (uint32_t)MFLASH_PAGE_SIZE) != 0UL)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    /* Check and unlock sector protection inside critical section */
    ret = FLASH_GetSectorProtection(&flash_ctx, logaddr);
    
    if (ret == kStatus_FLASH_SectorLocked)
    {
        ret = FLASH_SetSectorProtection(&flash_ctx, logaddr, false);
        if (ret != kStatus_FLASH_Success)
        {
            if (primask == 0UL)
            {
                __enable_irq();
            }
            return ret;
        }
    }
    else if (ret != kStatus_FLASH_Success)
    {
        /* GetSectorProtection returned an error - continue anyway,
        better handling to be implemented */
    }

    ret = FLASH_Program(&flash_ctx, logaddr, data, MFLASH_PAGE_SIZE);

    /* Invalidate DCache if enabled */
    if (SCB_CCR_DC_Msk == (SCB_CCR_DC_Msk & SCB->CCR))
    {
        DCACHE_InvalidateByRange(logaddr, MFLASH_PAGE_SIZE);
    }

    if (primask == 0UL)
    {
        __enable_irq();
    }

    __ISB();

    return ret;
}


/* API - Phrase program */
int32_t mflash_drv_phrase_program(uint32_t phrase_addr, uint32_t *data)
{
    status_t ret;
    uint32_t primask;
    uint32_t logaddr = MFLASH_BASE_ADDRESS + phrase_addr;

    if ((phrase_addr % (uint32_t)MFLASH_PHRASE_SIZE) != 0UL)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    /* Check and unlock sector protection inside critical section */
    ret = FLASH_GetSectorProtection(&flash_ctx, logaddr);
    
    if (ret == kStatus_FLASH_SectorLocked)
    {
        ret = FLASH_SetSectorProtection(&flash_ctx, logaddr, false);
        if (ret != kStatus_FLASH_Success)
        {
            if (primask == 0UL)
            {
                __enable_irq();
            }
            return ret;
        }
    }
    else if (ret != kStatus_FLASH_Success)
    {
        /* GetSectorProtection returned an error - continue anyway,
        better handling to be implemented */
    }

    ret = FLASH_Program(&flash_ctx, logaddr, data, MFLASH_PHRASE_SIZE);

    /* Invalidate DCache if enabled */
    if (SCB_CCR_DC_Msk == (SCB_CCR_DC_Msk & SCB->CCR))
    {
        DCACHE_InvalidateByRange(logaddr, MFLASH_PHRASE_SIZE);
    }

    if (primask == 0UL)
    {
        __enable_irq();
    }

    __ISB();

    return ret;
}

/* API - Read data */
int32_t mflash_drv_read(uint32_t addr, uint32_t *buffer, uint32_t len)
{
    (void)memcpy(buffer, (void *)(addr + MFLASH_BASE_ADDRESS), len);

    return kStatus_Success;
}

/* API - Get pointer to FLASH region */
void *mflash_drv_phys2log(uint32_t addr, uint32_t len)
{
    return (void *)(addr + MFLASH_BASE_ADDRESS);
}

/* API - Get pointer to FLASH region */
uint32_t mflash_drv_log2phys(void *ptr, uint32_t len)
{
    if ((uint32_t)ptr < MFLASH_BASE_ADDRESS)
    {
        return MFLASH_INVALID_ADDRESS;
    }

    return ((uint32_t)ptr - MFLASH_BASE_ADDRESS);
}
