/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <string.h>

#include "mflash_drv.h"
#include "pin_mux.h"
#include "fsl_iap.h"

static flash_config_t s_flashDriver = {0};

static uint32_t pflashBlock0Base = 0;
static uint32_t pflashBlock0Size = 0;
static uint32_t pflashSectorSize = 0;
static uint32_t pflashBlockCount = 0;
static uint32_t pflashTotalSize  = 0;

/* API - initialize 'mflash' */
int32_t mflash_drv_init(void)
{
    status_t result;

    (void)memset(&s_flashDriver, 0, sizeof(flash_config_t));

    result = FLASH_Init(&s_flashDriver);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Flash cache cleared to make sure no content is left in from other applications */
    FLASH_CacheClear();

    result = FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyPflashBlockBaseAddr, &pflashBlock0Base);
    if (result != kStatus_Success)
    {
        return result;
    }

    result = FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyPflashBlockSize, &pflashBlock0Size);
    if (result != kStatus_Success)
    {
        return result;
    }

    result = FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyPflashSectorSize, &pflashSectorSize);
    if (result != kStatus_Success)
    {
        return result;
    }

    result = FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyPflashBlockCount, &pflashBlockCount);
    if (result != kStatus_Success)
    {
        return result;
    }

    result = FLASH_GetProperty(&s_flashDriver, kFLASH_PropertyPflashTotalSize, &pflashTotalSize);

    return result;
}

/* API - Erase single sector */
int32_t mflash_drv_sector_erase(uint32_t sector_addr)
{
    uint32_t primask = 0;
    int32_t ret      = kStatus_Fail;

    primask = DisableGlobalIRQ();

    /* Enable speculative loading of the cache, to reduce the amount of traffic. */
    FLASH_CacheSpeculationControl(true);

    ret = FLASH_Erase(&s_flashDriver, sector_addr, MFLASH_SECTOR_SIZE, (uint32_t)kFLASH_ApiEraseKey);

    FLASH_CacheSpeculationControl(false);

    EnableGlobalIRQ(primask);

    return ret;
}

/* API - Page program */
int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    uint32_t primask = 0;
    int32_t ret      = kStatus_Fail;

    primask = DisableGlobalIRQ();

    FLASH_CacheSpeculationControl(true);

    ret = FLASH_Program(&s_flashDriver,  page_addr, (uint8_t *)data, MFLASH_PAGE_SIZE);

    /* Clear code bus cache */
    FLASH_CacheClear();
    FLASH_CacheSpeculationControl(false);

    EnableGlobalIRQ(primask);

    return ret;
}

/* API - Read data */
int32_t mflash_drv_read(uint32_t addr, uint32_t *buffer, uint32_t len)
{
    (void)memcpy((void *)buffer, (void *)(uint32_t *)addr, len);

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
