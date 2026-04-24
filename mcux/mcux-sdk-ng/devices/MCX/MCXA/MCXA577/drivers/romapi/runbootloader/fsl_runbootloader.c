/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_runbootloader.h"
#include "fsl_romapi_tree.h"

/*! @brief Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.runBootloader"
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

void ROMAPI_RunBootloader(void *arg)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    BOOTLOADER_API_TREE_POINTER->runBootloader(arg);
}
