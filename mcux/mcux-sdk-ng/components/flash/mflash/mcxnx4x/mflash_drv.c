/*
 * Copyright 2017-2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <string.h>

#if (defined(MFLASH_ON_CHIP) && MFLASH_ON_CHIP)

#if (defined(MFLASH_ON_CHIP_USE_FMU) && MFLASH_ON_CHIP_USE_FMU)
#include "mflash_drv.h"

#define IFLASH_CMD_RD1ALL  0x00U // Read 1s all
#define IFLASH_CMD_RD1BLK  0x01U // Read 1s block
#define IFLASH_CMD_RD1SCR  0x02U // Read 1s sector
#define IFLASH_CMD_RD1PG   0x03U // Read 1s page
#define IFLASH_CMD_RD1PHR  0x04U // Read 1s phrase
#define IFLASH_CMD_RDMISR  0x05U // Read into MISR
#define IFLASH_CMD_RD1ISCR 0x12U // Read 1s IFR sector
#define IFLASH_CMD_RD1IPG  0x13U // Read 1s IFR page
#define IFLASH_CMD_RD1IPHR 0x14U // Read 1s IFR phrase
#define IFLASH_CMD_RDIMISR 0x15U // Read IFR into MISR
#define IFLASH_CMD_PGMPG   0x23U // Program page
#define IFLASH_CMD_PGMPHR  0x24U // Program phrase
#define IFLASH_CMD_ERSALL  0x40U // Erase all
#define IFLASH_CMD_ERSSCR  0x42U // Erase sector

#define IFLASH_ERROR_STAT_FLAGS (FMU_FSTAT_ACCERR_MASK | FMU_FSTAT_PVIOL_MASK | FMU_FSTAT_CMDABT_MASK)

static void iflash_prepare(void)
{
    uint32_t fmu_fstat = FMU0->FSTAT;

    while ((fmu_fstat & FMU_FSTAT_CCIF_MASK) != FMU_FSTAT_CCIF(1))
    {
        fmu_fstat = FMU0->FSTAT;
    }

    if (fmu_fstat & IFLASH_ERROR_STAT_FLAGS)
    {
        FMU0->FSTAT = IFLASH_ERROR_STAT_FLAGS;
    }
}

static status_t iflash_launch_command(bool pe_command, uint8_t pe_type)
{
    FMU0->FSTAT = FMU_FSTAT_CCIF_MASK;

    if (pe_command)
    {
        uint32_t fmu_fstat = FMU0->FSTAT;

        while ((fmu_fstat & FMU_FSTAT_PEWEN_MASK) != FMU_FSTAT_PEWEN(pe_type))
        {
            if (fmu_fstat & FMU_FSTAT_CCIF_MASK)
            {
                return kStatus_Fail;
            }

            fmu_fstat = FMU0->FSTAT;
        }
    }

    return kStatus_Success;
}

static status_t iflash_finish_command(bool pe_command)
{
    uint32_t fmu_fstat;

    if (pe_command)
    {
        fmu_fstat = FMU0->FSTAT;

        while ((fmu_fstat & FMU_FSTAT_PERDY_MASK) != FMU_FSTAT_PERDY(1))
        {
            if (fmu_fstat & FMU_FSTAT_CCIF_MASK)
            {
                return kStatus_Fail;
            }

            fmu_fstat = FMU0->FSTAT;
        }

        FMU0->FSTAT = FMU_FSTAT_PERDY_MASK;
    }

    fmu_fstat = FMU0->FSTAT;

    while ((fmu_fstat & FMU_FSTAT_CCIF_MASK) == 0U)
    {
        fmu_fstat = FMU0->FSTAT;
    }

    return kStatus_Success;
}

int32_t mflash_drv_init(void)
{
    /* enable the Flash clock if not already set */
    CLOCK_SetupClockCtrl(SYSCON_CLOCK_CTRL_FRO12MHZ_ENA_MASK);

    return kStatus_Success;
}

int32_t mflash_drv_sector_erase(uint32_t sector_addr)
{
    status_t ret;
    uint32_t primask;

    if ((sector_addr % MFLASH_SECTOR_SIZE) != 0)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    iflash_prepare();

    FMU0->FCCOB[0] = IFLASH_CMD_ERSSCR;
    FMU0->FCCOB[1] = 0x00U;

    ret = iflash_launch_command(true, 1);

    if (ret != kStatus_Success)
    {
        goto cleanup;
    }

    *(uint32_t *)(sector_addr)        = 0UL;
    *(uint32_t *)(sector_addr + 0x04) = 0UL;
    *(uint32_t *)(sector_addr + 0x08) = 0UL;
    *(uint32_t *)(sector_addr + 0x0C) = 0UL;

    ret = iflash_finish_command(true);

cleanup:

    if (primask == 0)
    {
        __enable_irq();
    }

    /* Flush pipeline to allow pending interrupts take place
     * before starting next loop */
    __ISB();

    return ret;
}

int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    status_t ret;
    uint32_t primask;

    if ((page_addr % MFLASH_PAGE_SIZE) != 0)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    iflash_prepare();

    FMU0->FCCOB[0] = IFLASH_CMD_PGMPG;
    FMU0->FCCOB[1] = 0x00U;

    ret = iflash_launch_command(true, 2);
    if (ret != kStatus_Success)
    {
        goto cleanup;
    }

    for (uint32_t i = 0; i < MFLASH_PAGE_SIZE; i += 4)
    {
        *(uint32_t *)(page_addr + i) = ((uint32_t *)data)[i / 4];
    }

    ret = iflash_finish_command(true);

cleanup:

    if (primask == 0)
    {
        __enable_irq();
    }

    /* Flush pipeline to allow pending interrupts take place
     * before starting next loop */
    __ISB();

    return ret;
}

int32_t mflash_drv_phrase_program(uint32_t phrase_addr, uint32_t *data)
{
    status_t ret;
    uint32_t primask;

    if ((phrase_addr % MFLASH_PHRASE_SIZE) != 0)
    {
        return kStatus_InvalidArgument;
    }

    primask = __get_PRIMASK();
    __disable_irq();

    iflash_prepare();

    FMU0->FCCOB[0] = IFLASH_CMD_PGMPHR;
    FMU0->FCCOB[1] = 0x00U;

    ret = iflash_launch_command(true, 1);
    if (ret != kStatus_Success)
    {
        goto cleanup;
    }

    for (uint32_t i = 0; i < MFLASH_PHRASE_SIZE; i += 4)
    {
        *(uint32_t *)(phrase_addr + i) = ((uint32_t *)data)[i / 4];
    }

    ret = iflash_finish_command(true);

cleanup:

    if (primask == 0)
    {
        __enable_irq();
    }

    /* Flush pipeline to allow pending interrupts take place
     * before starting next loop */
    __ISB();

    return ret;
}

int32_t mflash_drv_read(uint32_t addr, uint32_t *buffer, uint32_t len)
{
    (void)memcpy(buffer, (void *)addr, len);
    return kStatus_Success;
}

void *mflash_drv_phys2log(uint32_t addr, uint32_t len)
{
    /* FLASH is directly mapped in the address space */
    return (void *)(addr);
}

uint32_t mflash_drv_log2phys(void *ptr, uint32_t len)
{
    /* FLASH is directly mapped in the address space */
    return (uint32_t)ptr;
}

#else
#include "mflash_drv.h"
#include "fsl_flash.h"
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

    return FLASH_Erase(&g_flash_instance, sector_addr, MFLASH_SECTOR_SIZE, kFLASH_ApiEraseKey);
}

/* API - Page program */
int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    if (0 == mflash_drv_is_page_aligned(page_addr))
        return kStatus_InvalidArgument;

    return FLASH_Program(&g_flash_instance, page_addr, (uint8_t *)data, MFLASH_PAGE_SIZE);
}

/* API - Read data */
int32_t mflash_drv_read(uint32_t addr, uint32_t *buffer, uint32_t len)
{
    memcpy(buffer, (void *)addr, len);
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

#endif /* (defined(MFLASH_ON_CHIP_USE_FMU) && MFLASH_ON_CHIP_USE_FMU) */
#endif /* (defined(MFLASH_ON_CHIP) && MFLASH_ON_CHIP) */

#if (defined(MFLASH_OFF_CHIP) && MFLASH_OFF_CHIP)

#include "mflash_drv.h"
#include "fsl_flash.h"
#include "fsl_cache.h"
#include "fsl_flexspi_nor_flash.h"
#include "pin_mux.h"

#define FLASH_BASE_ADDR 0x80000000UL

#if FLASH_USE_CUSTOM_FCB
/* fcb for w45q64 */
const uint8_t CUSTOM_FCB[] = {
    0x46, 0x43, 0x46, 0x42, 0x00, 0x04, 0x01, 0x56, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x01, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x04, 0x18, 0x0a, 0x06,
    0x32, 0x04, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x04, 0x04, 0x24, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x04, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0x04, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x18, 0x08, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x60, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#endif

static flexspi_nor_config_t flashConfig;

/* API - initialize 'mflash' */
int32_t mflash_drv_init(void)
{
    status_t result;

#if FLASH_USE_CUSTOM_FCB
    memcpy(&flashConfig, CUSTOM_FCB, sizeof(flexspi_nor_config_t));
#else
    serial_nor_config_option_t option;
    option.option0.U = 0xc0000001U;
    option.option1.U = 0x00000000;

    result = FLEXSPI_NorFlash_GetConfig(0, &flashConfig, &option);
    if (result != kStatus_Success)
    {
        return result;
    }
#endif

    result = FLEXSPI_NorFlash_Init(0, &flashConfig);
    if (result != kStatus_Success)
    {
        return result;
    }

    return result;
}

/* API - Erase single sector */
int32_t mflash_drv_sector_erase(uint32_t sector_addr)
{
    status_t status;
    uint32_t primask = __get_PRIMASK();
            
    if (0 == mflash_drv_is_sector_aligned(sector_addr))
        return kStatus_InvalidArgument;

    __disable_irq();
    
    status = FLEXSPI_NorFlash_Erase(0, (flexspi_nor_config_t *)&flashConfig, sector_addr,
                                  flashConfig.sectorSize);
    
    DCACHE_InvalidateByRange(MFLASH_BASE_ADDRESS + sector_addr, MFLASH_SECTOR_SIZE);

    
    if (primask == 0)
    {
        __enable_irq();
    }

    /* Flush pipeline to allow pending interrupts take place
     * before starting next loop */
    __ISB();

    return status;
}

/* API - Page program */
int32_t mflash_drv_page_program(uint32_t page_addr, uint32_t *data)
{
    status_t status;
    uint32_t primask = __get_PRIMASK();
    
    if (0 == mflash_drv_is_page_aligned(page_addr))
        return kStatus_InvalidArgument;

    __disable_irq();

    status = FLEXSPI_NorFlash_ProgramPage(0, &flashConfig, page_addr, (uint32_t *)data);
    
    DCACHE_InvalidateByRange(MFLASH_BASE_ADDRESS + page_addr, MFLASH_PAGE_SIZE);

            
    if (primask == 0)
    {
        __enable_irq();
    }

    /* Flush pipeline to allow pending interrupts take place
     * before starting next loop */
    __ISB();

    return status;
}

/* API - Read data */
int32_t mflash_drv_read(uint32_t addr, uint32_t *buffer, uint32_t len)
{
    memcpy(buffer, (void *)(addr + MFLASH_BASE_ADDRESS), len);

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
        return kStatus_InvalidArgument;

    return ((uint32_t)ptr - MFLASH_BASE_ADDRESS);
}


#endif /* (defined(MFLASH_OFF_CHIP) && MFLASH_OFF_CHIP) */
