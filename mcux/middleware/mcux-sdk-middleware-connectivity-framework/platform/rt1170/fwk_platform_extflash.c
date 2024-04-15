/*
 * Copyright 2018-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* RT1170 MFLASH driver imposes that all accesses be multiple of 32 bits */
#define PLATFORM_ACCESS_ALIGNMENT_CONSTRAINT_LOG 2u

#include "../Common/fwk_platform_mflash.ch"
