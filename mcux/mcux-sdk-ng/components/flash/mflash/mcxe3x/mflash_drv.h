/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MFLASH_DRV_H__
#define __MFLASH_DRV_H__

#include "mflash_common.h"

/* Flash constants */

#define MFLASH_SECTOR_SIZE (8192)

#define MFLASH_SUPER_SECTOR_SIZE (65536)

#define MFLASH_PAGE_SIZE (128)

#define MFLASH_PHRASE_SIZE (8)

#define MFLASH_BASE_ADDRESS (0)

int32_t mflash_drv_phrase_program(uint32_t phrase_addr, uint32_t *data);

#endif
