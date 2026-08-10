/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Includes */
#include <stdio.h>
#include "fsl_device_registers.h"
#include "fsl_power.h"

int32_t POWER_SetState(pwr_s_t *pwr_st)
{
    uint32_t channel = SCMI_A2P;
    uint32_t flag = 0;
    uint32_t domainId = pwr_st->did;
    uint32_t state = pwr_st->st;

    return SCMI_PowerStateSet(channel, domainId, flag, state);
}

uint32_t POWER_GetState(pwr_s_t *pwr_st)
{
    uint32_t channel = SCMI_A2P;
    uint32_t domainId = pwr_st->did;
    uint32_t state = SCMI_POWER_DOMAIN_STATE_OFF;

    SCMI_PowerStateGet(channel, domainId, &state);

    return state;
}
