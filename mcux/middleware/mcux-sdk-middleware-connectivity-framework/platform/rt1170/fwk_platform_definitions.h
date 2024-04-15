/*
 * Copyright 2022-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLAT_DEFS_H_
#define _FWK_PLAT_DEFS_H_

#ifndef KB
#define KB(x) (((uint32_t)x) << 10u)
#endif
#ifndef MB
#define MB(x) (((uint32_t)x) << 20u)
#endif

/* SPI NOR Flash is an 16MBytes on RT1170 evk */
#define FLASH_SIZE MB(16U)

#ifndef MFLASH_SECTOR_SIZE
#define MFLASH_SECTOR_SIZE KB(4U)
#endif

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE 256u
#endif

#define PLATFORM_EXTFLASH_SECTOR_SIZE MFLASH_SECTOR_SIZE
#define PLATFORM_EXTFLASH_PAGE_SIZE   MFLASH_PAGE_SIZE
#define PLATFORM_EXTFLASH_TOTAL_SIZE  FLASH_SIZE

#endif /* _FWK_PLAT_DEFS_H_ */
