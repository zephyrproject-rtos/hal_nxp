/*
 * Copyright 2022-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLAT_DEFS_H_
#define _FWK_PLAT_DEFS_H_

#include "mflash_drv.h"                            /* TODO remove this dependency */

#define PLATFORM_EXTFLASH_START_ADDR  0x08000000UL /* FlexSPI AMBA non secure */
#define PLATFORM_EXTFLASH_SECTOR_SIZE MFLASH_SECTOR_SIZE
#define PLATFORM_EXTFLASH_PAGE_SIZE   MFLASH_PAGE_SIZE
#define PLATFORM_EXTFLASH_TOTAL_SIZE  MFLASH_BSIZE /* SPI NOR Flash is an MX25U51245G (512Mb) */

/*
 *  NV_STORAGE_START_ADDRESS is defined by linker script. Dwells in external flash  for RW61x
 */
#define NV_STORAGE_EXTFLASH_START_OFFSET ((uint32_t)NV_STORAGE_START_ADDRESS - PLATFORM_EXTFLASH_START_ADDR)

#define NV_STORAGE_START_OFFSET NV_STORAGE_EXTFLASH_START_OFFSET

/*
 * Convert offset relative to start of NV storage partition to physical address.
 */
#define NV_EXTFLASH_PHYS_ADDR(offset) ((uint32_t)NV_STORAGE_START_ADDRESS + (offset))

/*
 * Convert offset relative to start of flash device to physical address.
 */
#define EXTFLASH_PHYS_ADDR(offset) ((uint32_t)PLATFORM_EXTFLASH_START_ADDR + (offset))

#endif /* _FWK_PLAT_DEFS_H_ */
