/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mipi_csi2rx.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.mipi_csi"
#endif

#if defined(MIPI_CSI_RSTS)
#define MIPI_CSI_RESETS_ARRAY MIPI_CSI_RSTS
#elif defined(MIPI_CSI_RSTS_N)
#define MIPI_CSI_RESETS_ARRAY MIPI_CSI_RSTS_N
#endif

#if defined(MIPI_CSI_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_mipiCsiResets[] = MIPI_CSI_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef CSI2RX_PHY_INIT_TIMEOUT_COUNT
#define CSI2RX_PHY_INIT_TIMEOUT_COUNT (1000000U)
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Gets the default configuration for MIPI CSI-2 RX controller.
 *
 * param config Pointer to the configuration structure. Must not be NULL.
 */
void CSI2RX_GetDefaultConfig(csi2rx_config_t *config)
{
    assert(config != NULL);

    (void)memset(config, 0, sizeof(*config));

    config->laneNum           = 2U;
    config->enableVCX         = false;
    config->enableScramble    = false;
    config->enablePacketIface = false;
    config->flushCount        = 7U;
    config->enableWatchdog    = false;
    config->watchdogCount     = 0U;
    config->tHsSettle_EscClk  = 9U;
    config->tClkSettle_EscClk = 16U;
    config->enableHighSpeed   = false;
    config->enableDeskew      = false;
}

/*!
 * brief Initializes the MIPI CSI-2 RX controller and D-PHY.
 *
 * param base   MIPI_CSI2RX peripheral base address.
 * param config Pointer to the configuration structure.
 *
 * retval kStatus_Success  Initialization succeeded.
 * retval kStatus_Timeout  D-PHY PHY_INIT_DONE not asserted within timeout.
 */
status_t CSI2RX_Init(MIPI_CSI2RX_Type *base, const csi2rx_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);
    assert((config->laneNum >= 1U) && (config->laneNum <= 2U));

    uint32_t reg;
    uint32_t timeout;

#if defined(MIPI_CSI_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_mipiCsiResets[0]);
#endif

    reg = 0U;
    reg |= MIPI_CSI2RX_CFG_REG0_CFG_UC_PRG_RXHS_SETTLE(config->tClkSettle_EscClk);
    reg |= MIPI_CSI2RX_CFG_REG0_CFG_U_PRG_RXHS_SETTLE(config->tHsSettle_EscClk);
    reg |= MIPI_CSI2RX_CFG_REG0_CFG_LANE1_SEL(1U);
    reg |= MIPI_CSI2RX_CFG_REG0_CFG_LANE0_SEL(0U);
    reg |= MIPI_CSI2RX_CFG_REG0_CFG_DPHY_CLK_FHS_MODE(1U);
    if (config->enableHighSpeed)
    {
        reg |= MIPI_CSI2RX_CFG_REG0_CFG_RX_HSEL(1U);
    }
    if (config->enableDeskew)
    {
        reg |= MIPI_CSI2RX_CFG_REG0_CFG_DPHY_DESKEW_EN(1U);
    }
    reg |= MIPI_CSI2RX_CFG_REG0_CFG_TST_CLKDSKW(1U);
    base->CFG_REG0 = reg;

    /* Poll CFG_REG1[25] PHY_INIT_DONE. */
    timeout = CSI2RX_PHY_INIT_TIMEOUT_COUNT;
    while (0U == (base->CFG_REG1 & MIPI_CSI2RX_CFG_REG1_CFG_PHY_INIT_DONE_MASK))
    {
        if (0U == --timeout)
        {
            return kStatus_Timeout;
        }
    }

    /* Configure non-lane registers. */
    base->CFG_FLUSH_COUNT = MIPI_CSI2RX_CFG_FLUSH_COUNT_CFG_FLUSH_COUNT(config->flushCount);

    base->CFG_WATCHDOG_COUNT = config->enableWatchdog ?
        (MIPI_CSI2RX_CFG_WATCHDOG_COUNT_CFG_WATCHDOG_EN_MASK |
         MIPI_CSI2RX_CFG_WATCHDOG_COUNT_CFG_WATCHDOG_COUNT(config->watchdogCount)) :
        0U;

    /* Enable clock lane and data lanes FIRST (before cfg_num_lanes). */
    base->CLOCK_LANE = MIPI_CSI2RX_CLOCK_LANE_CFG_CLK_LANE_EN_MASK;

    base->LANE_0 = MIPI_CSI2RX_LANE_0_CFG_DATA_LANE_EN_LN0_MASK |
                   MIPI_CSI2RX_LANE_0_CFG_RX_LANE0_SEL(0U);

    if (config->laneNum >= 2U)
    {
        base->LANE_1 = MIPI_CSI2RX_LANE_1_CFG_DATA_LANE_EN_LN1_MASK |
                       MIPI_CSI2RX_LANE_1_CFG_RX_LANE1_SEL(1U);
    }

    /* Set cfg_num_lanes as the FINAL step. */
    reg = 0U;
    reg = MIPI_CSI2RX_CFG_MODE_CFG_NUM_LANES(config->laneNum);

    if (config->enableVCX)
    {
        reg |= MIPI_CSI2RX_CFG_MODE_CFG_VCX_EN_MASK;
    }
    if (config->enablePacketIface)
    {
        reg |= MIPI_CSI2RX_CFG_MODE_CFG_PACKET_INTERFACE_EN_MASK;
    }
    if (config->enableScramble)
    {
        reg |= MIPI_CSI2RX_CFG_MODE_CFG_SCRAMBLE_EN_MASK;
    }
    base->CFG_MODE = reg;

    /* Clear all pending IRQ status flags (W1C). */
    base->IRQ_STATUS = (MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_0_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_1_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_2_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_3_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_4_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_5_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_6_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_7_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_8_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_9_MASK  |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_10_MASK |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_11_MASK |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_12_MASK |
                        MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_17_MASK);

    return kStatus_Success;
}

/*!
 * brief Deinitializes the MIPI CSI RX controller.
 *
 * param base MIPI_CSI2RX peripheral base address.
 */
void CSI2RX_Deinit(MIPI_CSI2RX_Type *base)
{
    assert(base != NULL);

    /* Disable clock lane and data lanes. */
    base->CLOCK_LANE = 0U;
    base->LANE_0     = 0U;
    base->LANE_1     = 0U;

    /* Set lane count to 0 (controller off). */
    base->CFG_MODE = 0U;

    /* Disable all interrupts. */
    base->IRQ_ENABLE = 0U;

    /* Power down D-PHY: set cfg_pd_phy = 1. */
    base->CFG_REG0 |= MIPI_CSI2RX_CFG_REG0_CFG_PD_PHY_MASK;
}
