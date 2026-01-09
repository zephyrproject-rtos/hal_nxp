/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLAT_DEFS_H_
#define _FWK_PLAT_DEFS_H_

#include "fsl_device_registers.h"
#include "fwk_hal_macros.h"

#define FWK_MCXW23_FAMILIES 1

/*
 * External Flash geometry characteristics.
 */
#define PLATFORM_EXTFLASH_SECTOR_SIZE KB(4U)
#define PLATFORM_EXTFLASH_PAGE_SIZE   256U
#define PLATFORM_EXTFLASH_TOTAL_SIZE  MB(8U)

#endif /* _FWK_PLAT_DEFS_H_ */
