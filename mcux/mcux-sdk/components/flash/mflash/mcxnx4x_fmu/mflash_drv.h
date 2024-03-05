/*
 * Copyright 2017-2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MFLASH_DRV_H__
#define __MFLASH_DRV_H__

#include "mflash_common.h"

/* Flash constants */
#ifndef MFLASH_SECTOR_SIZE
#define MFLASH_SECTOR_SIZE (8192)
#endif

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE (128)
#endif

#ifndef MFLASH_PHRASE_SIZE
#define MFLASH_PHRASE_SIZE (16)
#endif

#ifndef MFLASH_BASE_ADDRESS
#define MFLASH_BASE_ADDRESS (0)
#endif

#define MFLASH_PAGE_INTEGRITY_CHECKS (1)

static inline int32_t mflash_drv_is_readable(uint32_t addr)
{
    return kStatus_Success;
}

int32_t mflash_drv_phrase_program(uint32_t phrase_addr, uint32_t *data);

#endif
