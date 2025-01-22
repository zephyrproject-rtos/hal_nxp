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
#define MFLASH_SECTOR_SIZE (4096U)
#endif

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE (256U)
#endif

/* Platform specific definitions */
#define EXAMPLE_QSPI      QuadSPI0
#define QSPI_CLOCK_SOURCE kCLOCK_McgPll0Clk
#define QSPI_CLK_FREQ     CLOCK_GetFreq(kCLOCK_McgPll0Clk)
#define FLASH_SIZE        0x00400000U

#endif
