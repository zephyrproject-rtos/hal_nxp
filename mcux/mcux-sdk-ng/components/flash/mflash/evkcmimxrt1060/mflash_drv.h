/*
 * Copyright 2018-2021,2024 NXP
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
#define MFLASH_FLEXSPI (FLEXSPI)
#endif

#ifndef MFLASH_BASE_ADDRESS
#define MFLASH_BASE_ADDRESS (FlexSPI_AMBA_BASE)
#endif

#define MFLASH_BSIZE 0x1000000UL /* Flash size expressed in bytes 16MB */

#define MFLASH_REMAP_OFFSET() (IOMUXC_GPR->GPR32 & 0xFFFFF000UL)
#define MFLASH_REMAP_START()  (IOMUXC_GPR->GPR30 & 0xFFFFF000UL)
#define MFLASH_REMAP_END()    (IOMUXC_GPR->GPR31 & 0xFFFFF000UL)

#define MFLASH_REMAP_ACTIVE() (MFLASH_REMAP_OFFSET() != 0UL)

#endif
