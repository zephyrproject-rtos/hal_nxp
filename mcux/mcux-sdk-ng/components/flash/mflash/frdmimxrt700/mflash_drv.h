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

/* FRDM-IMXRT700 quad NOR flash is connected to XSPI0 */
#define MFLASH_BASE_ADDRESS (XSPI0_AMBA_BASE)

/* W25Q25PW: 256 Mb = 32 MB */
#define MFLASH_FLASH_SIZE (32UL * 1024UL * 1024UL)

#endif /* __MFLASH_DRV_H__ */
