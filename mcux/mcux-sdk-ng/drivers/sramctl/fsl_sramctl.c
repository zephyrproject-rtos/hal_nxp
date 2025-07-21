/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sramctl.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.sramctl"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map SRAMCTL instance number to base pointer. */
static SRAMCTL_Type *const s_SramctlBase[] = SRAMCTL_BASE_PTRS;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initialize memory
 *
 * param instance_idx instance index
 * param start_addr
 * param end_addr
 */
void SRAMCTL_InitMem(uint32_t instance_idx, uint32_t start_addr, uint32_t end_addr)
{
    SRAMCTL_Type *sramctl = s_SramctlBase[instance_idx];
    sramctl->RAMIAS = start_addr;
    sramctl->RAMIAE = end_addr;
    sramctl->RAMCR = SRAMCTL_RAMCR_INIT(1U);

    while ((sramctl->RAMSR & SRAMCTL_RAMSR_IDONE(1U)) == 0U)
    {
    }
}
