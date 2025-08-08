/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MFLASH_DRV_H__
#define __MFLASH_DRV_H__

#include "mflash_common.h"

/* Flash constants */
#ifndef MFLASH_SECTOR_SIZE
#define MFLASH_SECTOR_SIZE (4096U)
#endif

#ifndef MFLASH_PHRASE_SIZE
#define MFLASH_PHRASE_SIZE (8U)
#endif


/* there is no concept of flash page on MCX E2x, only section programming
 * which requires use of FlexRAM which may be used by EEPROM emulation
 * so its availability is not guaranteed. To ensure compatibility with components
 * that expect a use page programming let's set this to 128. */

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE (128)
#endif

#ifndef MFLASH_BASE_ADDRESS
#define MFLASH_BASE_ADDRESS (0U)
#endif

int32_t mflash_drv_phrase_program(uint32_t phrase_addr, uint32_t *data);

#endif
