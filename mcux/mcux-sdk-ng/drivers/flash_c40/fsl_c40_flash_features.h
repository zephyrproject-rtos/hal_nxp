/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef FSL_C40_FLASH_FEATURES_H_
#define FSL_C40_FLASH_FEATURES_H_

#include "fsl_common.h"

/* Differences in flash array for different S32K3 variants can be added in elif conditions */
#if defined(CPU_S32K344)

/* Code flash: 4 MiB total => 4 blocks × 1 MiB each */
#define FSL_FEATURE_FLASH_C40_BLOCK_SIZE_CODE    (1024 * 1024)
#define FSL_FEATURE_FLASH_C40_BLOCK_COUNT_CODE   (4)
/* Data flash: 256 KiB */
#define FSL_FEATURE_FLASH_C40_BLOCK_SIZE_DATA    (256 * 1024)
#else
#error "C40 feature macros not defined for this SoC."

#endif

#endif /* FSL_C40_FLASH_FEATURES_H_ */
