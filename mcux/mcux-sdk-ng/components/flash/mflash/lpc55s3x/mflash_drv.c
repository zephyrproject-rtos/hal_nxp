/*
 * Copyright 2017-2020, 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <string.h>

#if (defined(MFLASH_ON_CHIP) && (MFLASH_ON_CHIP))
#include "mflash_drv.h"
#include "fsl_flash.h"
#include "fsl_flash_ffr.h"
#include "pin_mux.h"

static flash_config_t g_flash_instance = {0};

static uint32_t g_pflashBlockBase  = 0;
static uint32_t g_pflashTotalSize  = 0;
static uint32_t g_pflashSectorSize = 0;
static uint32_t g_pflashPageSize   = 0;

/* API - initialize 'mflash' */
int32_t mflash_drv_init(void)
{
    status_t result;

    result = FLASH_Init(&g_flash_instance);
    if (result != kStatus_Success)
        return result;

    result = FFR_Init(&g_flash_instance);
    if (result != kStatus_Success)
        return result;

    result = FLASH_GetProperty(&g_flash_instance, kFLASH_PropertyPflashBlockBaseAddr, &g_pflashBlockBase);
    if (result != kStatus_Success)
        return result;

    result = FLASH_GetProperty(&g_flash_instance, kFLASH_PropertyPflashSectorSize, &g_pflashSectorSize);
    if (result != kStatus_Success)
        return result;

    result = FLASH_GetProperty(&g_flash_instance, kFLASH_PropertyPflashTotalSize, &g_pflashTotalSize);
    if (result != kStatus_Success)
        return result;

    result = FLASH_GetProperty(&g_flash_instance, kFLASH_PropertyPflashPageSize, &g_pflashPageSize);

    return result;
}

/* API - Erase single sector */
int32_t mflash_drv_sector_erase(uint32_t sector_addr)
{
    if (0 == mflash_drv_is_sector_aligned(sector_addr))
        return kStatus_InvalidArgument;

    return FLASH_Erase(&g_flash_instance, sector_addr, MFLASH_SECTOR_SIZE, (uint32_t)kFLASH_ApiEraseKey);
}

/* API - Page program */
int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    if (0 == mflash_drv_is_page_aligned(page_addr))
        return kStatus_InvalidArgument;

    return FLASH_Program(&g_flash_instance, page_addr, (uint8_t *)data, MFLASH_PAGE_SIZE);
}

/* Internal - check FLASH status to avoid hardfault */
int32_t mflash_drv_is_readable(uint32_t addr)
{
#define FLASH_READMODE_ECC_MASK     (0x4U)
#define FLASH_READMODE_ECC_SHIFT    (2U)
#define FLASH_READMODE_ECC(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_READMODE_ECC_SHIFT)) & FLASH_READMODE_ECC_MASK)
#define FLASH_READMODE_MARGIN_MASK  (0xC00U)
#define FLASH_READMODE_MARGIN_SHIFT (10U)
#define FLASH_READMODE_MARGIN(x) \
    (((uint32_t)(((uint32_t)(x)) << FLASH_READMODE_MARGIN_SHIFT)) & FLASH_READMODE_MARGIN_MASK)
#define FLASH_READMODE_DMACC_MASK  (0x8000U)
#define FLASH_READMODE_DMACC_SHIFT (15U)
#define FLASH_READMODE_DMACC(x) \
    (((uint32_t)(((uint32_t)(x)) << FLASH_READMODE_DMACC_SHIFT)) & FLASH_READMODE_DMACC_MASK)

    uint32_t result = 0, result_mask = 0;

    FLASH->INTSTAT_CLR =
        FLASH_INTEN_CLR_FAIL_MASK | FLASH_INTEN_CLR_ERR_MASK | FLASH_INTEN_CLR_DONE_MASK | FLASH_INTEN_CLR_ECC_ERR_MASK;
    FLASH->STARTA   = addr >> 4;
    FLASH->DATAW[0] = FLASH_READMODE_ECC(g_flash_instance.modeConfig.readSingleWord.readWithEccOff) |
                      FLASH_READMODE_MARGIN(g_flash_instance.modeConfig.readSingleWord.readMarginLevel) |
                      FLASH_READMODE_DMACC(g_flash_instance.modeConfig.readSingleWord.readDmaccWord);
    FLASH->CMD = 3;
    while ((FLASH->INTSTAT & FLASH_INTSTAT_DONE_MASK) == 0U)
    {}
    result = FLASH->INTSTAT;

    /* Report failure in case of errors */
    result_mask = FLASH_INTSTAT_FAIL_MASK | FLASH_INTSTAT_ERR_MASK | FLASH_INTSTAT_ECC_ERR_MASK;
    if ((result_mask & result) != 0U)
        return kStatus_Fail;

    return kStatus_Success;
}

/* API - Read data */
int32_t mflash_drv_read(uint32_t addr, uint32_t *buffer, uint32_t len)
{
    if (mflash_drv_is_readable(addr) != 0)
    {
        (void)memset(buffer, 0xFF, len);
    }
    else
    {
        (void)memcpy(buffer, (void *)addr, len);
    }

    return kStatus_Success;
}

/* API - Get pointer to FLASH region */
void *mflash_drv_phys2log(uint32_t addr, uint32_t len)
{
#if 0
    if (mflash_drv_is_readable(addr) != 0)
        return NULL;
#endif

    /* FLASH is directly mapped in the address space */
    return (void *)(addr);
}

/* API - Get pointer to FLASH region */
uint32_t mflash_drv_log2phys(void *ptr, uint32_t len)
{
    /* FLASH is directly mapped in the address space */
    return ((uint32_t)ptr);
}
#endif /* (defined(MFLASH_ON_CHIP) && (MFLASH_ON_CHIP)) */

#if (defined(MFLASH_OFF_CHIP) && (MFLASH_OFF_CHIP))

#include "mflash_drv.h"
#include "fsl_flash.h"
#include "fsl_flexspi_nor_flash.h"
#include "pin_mux.h"

#define FLASH_BASE_ADDR 0x08000000

static flexspi_nor_config_t flashConfig;

/* API - initialize 'mflash' */
int32_t mflash_drv_init(void)
{
    status_t result;

    serial_nor_config_option_t option;
    option.option0.U = 0xc0000001U;
    option.option1.U = 0x00000000;

    result = FLEXSPI_NorFlash_GetConfig(0, &flashConfig, &option);
    if (result != kStatus_Success)
        return result;

    result = FLEXSPI_NorFlash_Init(0, &flashConfig);
    if (result != kStatus_Success)
        return result;

    return result;
}

/* API - Erase single sector */
int32_t mflash_drv_sector_erase(uint32_t sector_addr)
{
    assert(sector_addr >= FLASH_BASE_ADDR);
    if (0 == mflash_drv_is_sector_aligned(sector_addr))
        return kStatus_InvalidArgument;

    return FLEXSPI_NorFlash_Erase(0, (flexspi_nor_config_t *)&flashConfig, (sector_addr - FLASH_BASE_ADDR),
                                  flashConfig.sectorSize);
}

/* API - Page program */
int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    assert(page_addr >= FLASH_BASE_ADDR);
    if (0 == mflash_drv_is_page_aligned(page_addr))
        return kStatus_InvalidArgument;

    return FLEXSPI_NorFlash_ProgramPage(0, &flashConfig, (page_addr - FLASH_BASE_ADDR), (uint32_t *)data);
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
#if 0
    if (mflash_drv_is_readable(addr) != 0)
        return NULL;
#endif

    /* FLASH is directly mapped in the address space */
    return (void *)(addr);
}

/* API - Get pointer to FLASH region */
uint32_t mflash_drv_log2phys(void *ptr, uint32_t len)
{
    /* FLASH is directly mapped in the address space */
    return ((uint32_t)ptr);
}
#endif /* (defined(MFLASH_OFF_CHIP) && (MFLASH_OFF_CHIP)) */
