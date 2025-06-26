/*
 * Copyright 2018-2020,2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MFLASH_DRV_H__
#define __MFLASH_DRV_H__

#include "mflash_common.h"

/* Flash constants */
#ifndef MFLASH_SECTOR_SIZE
#define MFLASH_SECTOR_SIZE (0x1000U)
#endif

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE (256U)
#endif

#ifndef MFLASH_FLEXSPI
#define MFLASH_FLEXSPI (FLEXSPI2)
#endif

#ifndef MFLASH_BASE_ADDRESS
#define MFLASH_BASE_ADDRESS (FlexSPI2_AMBA_BASE)
#endif

/* Allow incremental writes without erase (enabled by default).
 * This method cannot be used in certain cases, e.g. when page checksums are used
 */
#ifndef MFLASH_INC_WRITE
#define MFLASH_INC_WRITE 1
#endif

/* Flash Size expressed in bytes : 8MB - 64Mb QSPI */
#define MFLASH_BSIZE 0x800000UL

#define MFLASH_REMAP_OFFSET() (IOMUXC_GPR->GPR32 & 0xFFFFF000UL)
#define MFLASH_REMAP_START()  (IOMUXC_GPR->GPR30 & 0xFFFFF000UL)
#define MFLASH_REMAP_END()    (IOMUXC_GPR->GPR31 & 0xFFFFF000UL)

#define MFLASH_REMAP_ACTIVE() (MFLASH_REMAP_OFFSET() != 0UL)

#endif
