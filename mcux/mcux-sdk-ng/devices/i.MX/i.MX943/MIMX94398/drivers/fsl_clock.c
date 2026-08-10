/*
 * Copyright 2024,2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_clock.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif

volatile uint64_t g_clockSourceFreq[CLOCK_NUM_SRC];

status_t CLOCK_EnableClock(clock_ip_name_t clkId)
{
    uint32_t channel = SCMI_A2P;
    uint32_t clockId = (uint32_t)clkId;
    uint32_t attributes = SCMI_CLOCK_CONFIG_SET_ENABLE(SCMI_CLOCK_STATE_ENABLE);
    uint32_t oemConfigVal = 0U;
    int32_t result = SCMI_ERR_SUCCESS;
    status_t status = kStatus_Success;

    if (clkId == kCLOCK_IpInvalid)
    {
        return kStatus_InvalidArgument;
    }
    result = SCMI_ClockConfigSet(channel, clockId, attributes, oemConfigVal);
    if (result != SCMI_ERR_SUCCESS)
    {
        status = kStatus_Fail;
    }

    return status;
}

status_t CLOCK_DisableClock(clock_ip_name_t clkId)
{
    uint32_t channel = SCMI_A2P;
    uint32_t clockId = (uint32_t)clkId;
    uint32_t attributes = SCMI_CLOCK_CONFIG_SET_ENABLE(SCMI_CLOCK_STATE_DISABLE);
    uint32_t oemConfigVal = 0U;
    int32_t result = SCMI_ERR_SUCCESS;
    status_t status = kStatus_Success;

    if (clkId == kCLOCK_IpInvalid)
    {
        return kStatus_InvalidArgument;
    }
    result = SCMI_ClockConfigSet(channel, clockId, attributes, oemConfigVal);
    if (result != SCMI_ERR_SUCCESS)
    {
        status = kStatus_Fail;
    }

    return status;
}

status_t CLOCK_SetRate(clk_t *clk)
{
    uint32_t channel = SCMI_A2P;
    uint32_t clockId = (uint32_t)clk->clkId;
    uint32_t flags = SCMI_CLOCK_RATE_FLAGS_ROUND(clk->clkRoundOpt);
    scmi_clock_rate_t rate = {0, 0};
    int32_t result = SCMI_ERR_SUCCESS;
    status_t status = kStatus_Success;

    if (clk->clkId == kCLOCK_IpInvalid)
    {
        return kStatus_InvalidArgument;
    }
    rate.lower = clk->rate & 0xFFFFFFFF;
    rate.upper = (clk->rate >> 32U) & 0xFFFFFFFF;

    result = SCMI_ClockRateSet(channel, clockId, flags, rate);
    if (result != SCMI_ERR_SUCCESS)
    {
        status = kStatus_Fail;
    }

    return status;
}

uint64_t CLOCK_GetRate(clock_ip_name_t clkId)
{
    scmi_clock_rate_t rate = {0, 0};
    uint32_t channel = SCMI_A2P;
    uint32_t clockId = (uint32_t)clkId;
    int32_t result = SCMI_ERR_SUCCESS;

    if (clkId == kCLOCK_IpInvalid)
    {
        return 0ULL;
    }

    result = SCMI_ClockRateGet(channel, clockId, &rate);
    if (result != SCMI_ERR_SUCCESS)
    {
        return 0ULL;
    }

    return rate.lower | ((uint64_t)(rate.upper) << 32U);
}

status_t CLOCK_SetParent(clk_t *clk)
{
    uint32_t channel = SCMI_A2P;
    uint32_t clockId = (uint32_t)clk->clkId;
    uint32_t parentId = (uint32_t)clk->pclkId;
    int32_t result = SCMI_ERR_SUCCESS;
    status_t status = kStatus_Success;

    if (clk->clkId == kCLOCK_IpInvalid || clk->pclkId == kCLOCK_IpInvalid)
    {
        return kStatus_InvalidArgument;
    }

    result = SCMI_ClockParentSet(channel, clockId, parentId);
    if (result != SCMI_ERR_SUCCESS)
    {
        status = kStatus_Fail;
    }

    return status;
}

