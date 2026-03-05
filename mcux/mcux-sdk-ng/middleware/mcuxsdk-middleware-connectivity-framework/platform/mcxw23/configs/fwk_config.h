/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_CONFIG_H_
#define _FWK_CONFIG_H_

#include "fwk_platform_definitions.h"

#define gPlatformRamStartAddress_c   (0x20004000U)
#define gPlatformRamEndAddress_c     (0x2001FFFF)
#define gPlatformFlashStartAddress_c (0)
#define gPlatformFlashEndAddress_c   (FSL_FEATURE_SYSCON_FLASH_SIZE_BYTES - 1)

/*********************************************************************
 *        General
 *********************************************************************/

/*
 * MCXW23 CM33 core has the DSP extension (__DSP_PRESENT), which allows the use of the NXP UltraFast EC P256
 * library. The flags may be set to 0 if this library is not required. It mainly makes sense for BLE point validation.
 */
#ifndef gSecLibUseDspExtension_d
#define gSecLibUseDspExtension_d 1
#endif

/*********************************************************************
 *        PLATFORM
 *********************************************************************/
/* Enable TimerManager support */
#ifndef gPlatformUseTimerManager_d
#define gPlatformUseTimerManager_d 1
#endif

#endif /* _FWK_CONFIG_H_ */
