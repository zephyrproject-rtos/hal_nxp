/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BOOT_HEADER_H_
#define BOOT_HEADER_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @brief BOOT_HEADER driver version 1.0.0. */
#define FSL_BOOT_HEADER_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

typedef uint32_t boot_lc_config_t;
extern const boot_lc_config_t LC_Config;

#endif /* BOOT_HEADER_H_ */
