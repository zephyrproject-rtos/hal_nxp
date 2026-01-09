/*
 * Copyright 2025 NXP
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

/*! *********************************************************************************
 *   RNG Module Configuration
 ********************************************************************************** */
/*! Set priority of TRNG interrupt (must be lower than link layer interrupts).
 *   See system_MCXW23*.* files for more details on the system requirements regarding interrupt priorities. */
#define gRngIsrPrio_c ((NVIC_DEFAULT_PRIORITY) << (8U - (uint8_t)__NVIC_PRIO_BITS))

#endif /* _FWK_CONFIG_H_ */
