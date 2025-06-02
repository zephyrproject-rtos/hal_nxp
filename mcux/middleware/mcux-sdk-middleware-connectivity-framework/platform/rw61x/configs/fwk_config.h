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

/*********************************************************************
 * gPlatformDisableLEPCTimer_d LEPC(LE power control) is a generic
 * BLE feature introduced from Core5.2, LE power control timer is the
 * timer initiated by controller periodically to monitor RSSI of peer
 * device, and trigger power control procedure if needed, disable this
 * timer can save some power consumption for BLE controller.
 *
 * LEPC feature will not work after disable LEPC timer since the supported
 * feature bits in controller will also be cleaned.
 * Defaults to 0 means not disable LEPC timer, 1 to disable LEPC timer.
 *
 *********************************************************************/
#ifndef gPlatformDisableLEPCTimer_d
#define gPlatformDisableLEPCTimer_d 0
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

/*********************************************************************
 * gPlatformMcuBootUseRemap_d If MCU boot uses remapping, image trailers
 * are expected at a different offset than when it uses swap mode.
 *
 * Defaults to 1. If changed to 0, MCU boot must be changed too.
 *
 *********************************************************************/
#ifndef gPlatformMcuBootUseRemap_d
#define gPlatformMcuBootUseRemap_d 1
#endif

#endif /* _FWK_CONFIG_H_ */
