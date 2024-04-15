/*
 * Copyright 2022-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_CONFIG_H_
#define _FWK_CONFIG_H_

#include "fwk_platform_definitions.h"

#ifndef gPlatformUseHwParameter_d
#define gPlatformUseHwParameter_d 0
#endif

#ifndef gPlatformDisableBleLowPower_d
#define gPlatformDisableBleLowPower_d 0
#endif

#ifndef gPlatformDisableSetBtCalData_d
#define gPlatformDisableSetBtCalData_d 0
#endif

#ifndef gPlatformDisableSetBtCalDataAnnex100_d
#define gPlatformDisableSetBtCalDataAnnex100_d 1
#endif

#ifndef gPlatformDisableVendorSpecificInit
#define gPlatformDisableVendorSpecificInit 0
#endif

#ifndef gPlatformEnableTxPowerChangeWithCountry_d
#define gPlatformEnableTxPowerChangeWithCountry_d 0
#endif

/*
 * gPlatformSetAntDiversity_d
 * value is 0, enable ant1(share antenna with annex100),or enable ant2 with external FEM(ble only case)
 * value is 1, enable ant3(diversity with annex100)
 * value is 2, enable ant4(diversity with annex100)
 */
#ifndef gPlatformSetAntDiversity_d
#define gPlatformSetAntDiversity_d 0
#endif

/*
 * gBoardUseFro32k_d diversity
 * value is 0, enable external XTAL32K
 * value is 1, enable internal FRO32K
 */
#ifndef gBoardUseFro32k_d
#define gBoardUseFro32k_d 0
#endif

/*********************************************************************
 * gPlatNvsSectorSize_c NVS Sector size is necessarily a multiple of
 * physical flash sector size.
 *
 * Defaults to 2 flash sectors because 8kB slabs is already pretty large.
 * Cannot exceed 16 sectors.
 *
 *********************************************************************/
#ifndef gPlatNvsSectorSize_c
#define gPlatNvsSectorSize_c (PLATFORM_EXTFLASH_SECTOR_SIZE * 2u)
#endif

#endif /* _FWK_CONFIG_H_ */
