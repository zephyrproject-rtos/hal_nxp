/*
 * Copyright 2022-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLAT_DEFS_H_
#define _FWK_PLAT_DEFS_H_

#include "fsl_device_registers.h"

#ifndef KB
#define KB(x) (((uint32_t)x) << 10u)
#endif
#ifndef MB
#define MB(x) (((uint32_t)x) << 20u)
#endif

#define gPlatformRamStartAddress_c (0x20000000U)
#define gPlatformRamEndAddress_c   (0x2001BFFFU)

#define gPlatformFlashStartAddress_c (FSL_FEATURE_FLASH_PFLASH_START_ADDRESS)
#define gPlatformFlashEndAddress_c   (FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE)

/*
 * External Flash geometry characteristics. SPI NOR Flash Part is AT25XE161D (16Mb)
 */
#define PLATFORM_EXTFLASH_SECTOR_SIZE KB(4U)
#define PLATFORM_EXTFLASH_PAGE_SIZE   256U
#define PLATFORM_EXTFLASH_TOTAL_SIZE  MB(2U)

#define PLATFORM_INTFLASH_SECTOR_SIZE FSL_FEATURE_FLASH_PFLASH_SECTOR_SIZE

/* IFR has 4 sectors */
#define IFR_SECT_ROMCFG  0u /* ROM Bootload configurations */
#define IFR_SECT_USER    1u /* Reserved for customer usage */
#define IFR_SECT_CMAC    2u /* Reserved CMAC */
#define IFR_SECT_OTA_CFG 3u /* OTACFG */
#ifndef FSL_FEATURE_IFR0_START_ADDRESS
#define FSL_FEATURE_IFR0_START_ADDRESS (0x02000000U)
#endif

#define IFR_SECTOR_SIZE FSL_FEATURE_FLASH_PFLASH_SECTOR_SIZE

#define IFR0_BASE FSL_FEATURE_IFR0_START_ADDRESS
//#define IFR1_BASE                     FSL_FEATURE_FLASH_BLOCK0_IFR1_START

#define IFR_SECTOR_OFFSET(n) ((n)*IFR_SECTOR_SIZE)

/* OTA CFG is in sector 3 of IFR */
#define IFR_OTA_CFG_ADDR (IFR0_BASE + IFR_SECTOR_OFFSET(IFR_SECT_OTA_CFG))
#define IFR_USER_ADDR    (IFR0_BASE + IFR_SECTOR_OFFSET(IFR_SECT_USER))
#define IFR_W_ONCE_DATA  (IFR0_BASE + IFR_SECTOR_OFFSET(IFR_SECT_ROMCFG) + 0x1000)

#define APP_FACTORY_DATA_MAX_LEN 0x800U
#define PROD_DATA_LEN            0x80U

#define PROD_DATA_OFFSET        0U
#define APP_FACTORY_DATA_OFFSET (PROD_DATA_OFFSET + PROD_DATA_LEN)

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern uint32_t Image$$PROD_DATA_REGION$$Base;
#define PROD_DATA_BASE_ADDR &Image$$PROD_DATA_REGION$$Base
#else
extern uint32_t PROD_DATA_BASE_ADDR[];
#endif /* defined(__CC_ARM) */

#define MAIN_FLASH_PROD_DATA_ADDR ((uint32_t)PROD_DATA_BASE_ADDR)

/* Connected MCU uses NOR Flash driver not mflash. NV storage is by default placed in internal flash */
/* If one means to place NVS instance in external flash, need to define NV_STORAGE_EXTFLASH_START_OFFSET at the right
 * offset in
 * external flash. It could be done using NV_STORAGE_START_ADDRESS provided that it is defined accordingly in linker
 * script */
#ifdef NV_STORAGE_EXTFLASH_START_OFFSET
#define NV_EXTFLASH_OFFSET(offset) (NV_EXTFLASH_PHYS_ADDR(offset) - NV_STORAGE_EXTFLASH_START_OFFSET)
#define NV_STORAGE_START_OFFSET    NV_STORAGE_EXTFLASH_START_OFFSET
#else
/*
 *  NV_STORAGE_START_ADDRESS is defined by linker script. Dwells in external flash  for RW61x
 */
#define NV_STORAGE_INTFLASH_START_OFFSET ((uint32_t)NV_STORAGE_START_ADDRESS - gPlatformFlashStartAddress_c)
#define NV_STORAGE_START_OFFSET          NV_STORAGE_INTFLASH_START_OFFSET
#endif

#endif /* _FWK_PLAT_DEFS_H_ */
