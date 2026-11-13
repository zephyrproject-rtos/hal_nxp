/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MFLASH_DRV_H__
#define __MFLASH_DRV_H__

#include "mflash_common.h"

/* Sector size: 4 KB */
#define MFLASH_SECTOR_SIZE (4096U)

/* Page size: 256 B */
#define MFLASH_PAGE_SIZE (256U)

/* MIMXRT2660-EVK quad NOR flash is connected to MAIN__XSPI_0 (AMBA at 0x60000000 non-secure) */
#define MFLASH_BASE_ADDRESS (XSPI0_AMBA_BASE)

/* W25H512NWEAM: 512 Mb = 64 MB */
#define MFLASH_FLASH_SIZE (64UL * 1024UL * 1024UL)

#endif /* __MFLASH_DRV_H__ */
