/*
 * Copyright 2025 NXP
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

    if ((sector_addr % MFLASH_SECTOR_SIZE) != 0UL)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    ret = FLASH_Erase(&flash_ctx, sector_addr, MFLASH_SECTOR_SIZE, kFTFx_ApiEraseKey);

    L1CACHE_CleanCodeCacheByRange(sector_addr, MFLASH_SECTOR_SIZE);

    if (primask == 0UL)
    {
        __enable_irq();
    }

    __ISB();

    return ret;
}

/* there is no concept of flash page on MCX E2x, only section programming
 * which requires use of FlexRAM which may be used by EEPROM emulation
 * so its availability is not guaranteed */

/* API - Emulated page program */

int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    status_t ret;
    uint32_t primask;

    if ((page_addr % (uint32_t)MFLASH_PAGE_SIZE) != 0UL)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    ret = FLASH_Program(&flash_ctx, page_addr, (uint8_t *)data, MFLASH_PAGE_SIZE);

    L1CACHE_CleanCodeCacheByRange(page_addr, MFLASH_PAGE_SIZE);

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

    if ((phrase_addr % (uint32_t)MFLASH_PHRASE_SIZE) != 0UL)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    ret = FLASH_Program(&flash_ctx, phrase_addr, (uint8_t *)data, MFLASH_PHRASE_SIZE);

    L1CACHE_CleanCodeCacheByRange(phrase_addr, MFLASH_PHRASE_SIZE);

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
    (void)memcpy(buffer, (void *)addr, len);
    return kStatus_Success;
}

/* API - Get pointer to FLASH region */
void *mflash_drv_phys2log(uint32_t addr, uint32_t len)
{
    /* FLASH is directly mapped in the address space */
    return (void *)(addr);
}

/* API - Get pointer to FLASH region */
uint32_t mflash_drv_log2phys(void *ptr, uint32_t len)
{
    /* FLASH is directly mapped in the address space */
    return ((uint32_t)ptr);
}
