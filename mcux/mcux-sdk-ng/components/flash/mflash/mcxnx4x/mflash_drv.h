/*
 * Copyright 2017-2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MFLASH_DRV_H__
#define __MFLASH_DRV_H__

#include "mflash_common.h"

/* Flash constants */

#if (defined(MFLASH_ON_CHIP) && MFLASH_ON_CHIP)
#ifndef MFLASH_SECTOR_SIZE
#define MFLASH_SECTOR_SIZE (8192U)
#endif

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE (128U)
#endif

#ifndef MFLASH_BASE_ADDRESS
#define MFLASH_BASE_ADDRESS (0U)
#endif

#define MFLASH_PAGE_INTEGRITY_CHECKS (1)

static inline int32_t mflash_drv_is_readable(uint32_t addr)
{
    return kStatus_Success;
}
#endif /* (defined(MFLASH_ON_CHIP) && MFLASH_ON_CHIP) */

#if (defined(MFLASH_OFF_CHIP) && MFLASH_OFF_CHIP)
#ifndef MFLASH_SECTOR_SIZE
#define MFLASH_SECTOR_SIZE (4096U)
#endif

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE (256U)
#endif

#ifndef FLASH_USE_CUSTOM_FCB
#define FLASH_USE_CUSTOM_FCB (0)
#endif

#ifndef MFLASH_BASE_ADDRESS
#define MFLASH_BASE_ADDRESS (0x80000000U)
#endif
#endif /* (defined(MFLASH_OFF_CHIP) && MFLASH_OFF_CHIP) */

#endif
