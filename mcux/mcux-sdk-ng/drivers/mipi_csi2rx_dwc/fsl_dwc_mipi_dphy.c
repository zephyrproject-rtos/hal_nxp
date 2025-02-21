/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
 
#include "fsl_dwc_mipi_dphy.h"

void DWC_DPHY_PowerOff(CAMERA_MIPI_CSI2_Type *base)
{
    /* Poweroff DWC RX DPHY module */
    base->DPHY_RSTZ &= ~CAMERA_MIPI_CSI2_DPHY_RSTZ_dphy_rstz_MASK;

    base->PHY_SHUTDOWNZ &= ~CAMERA_MIPI_CSI2_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
}

void DWC_DPHY_Reset(CAMERA_MIPI_CSI2_Type *base)
{
    /* Put DPHY into reset state */
    base->DPHY_RSTZ &= ~CAMERA_MIPI_CSI2_DPHY_RSTZ_dphy_rstz_MASK;
    base->PHY_SHUTDOWNZ &= ~CAMERA_MIPI_CSI2_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    /* Remove the DPHY from reset state */
    base->PHY_SHUTDOWNZ |= CAMERA_MIPI_CSI2_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    base->DPHY_RSTZ |= CAMERA_MIPI_CSI2_DPHY_RSTZ_dphy_rstz_MASK;
}

void DWC_DPHY_TestCodeReset(CAMERA_MIPI_CSI2_Type *base)
{
    /* Set PHY test codes from reset */
    base->PHY_TEST_CTRL0 |= CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclr_MASK;

    /* release PHY test codes from reset */
    base->PHY_TEST_CTRL0 &= ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclr_MASK;
}

void DWC_DPHY_SetTestConfigure(CAMERA_MIPI_CSI2_Type *base, uint32_t address, uint8_t values)
{
    /* enable address writing operation and set dphy offset address */
    base->PHY_TEST_CTRL1 |= (CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testen_MASK | CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testdin(address));

    /* Set then clear phy_testclk */
    base->PHY_TEST_CTRL0 |= CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclk_MASK;
    base->PHY_TEST_CTRL0 &= ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclk_MASK;

    /* disable address writing operation and configure dphy register values */
    base->PHY_TEST_CTRL1 &= ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testen_MASK;
    base->PHY_TEST_CTRL1 |= CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testdin(values);

    /* Set then clear phy_testclk */
    base->PHY_TEST_CTRL0 |= CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclk_MASK;
    base->PHY_TEST_CTRL0 &= ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclk_MASK;
}

uint32_t DWC_DPHY_ReadTestConfigure(CAMERA_MIPI_CSI2_Type *base, uint8_t address)
{
    uint32_t values = 0;

    /* enable address writing operation and set dphy offset address */
    base->PHY_TEST_CTRL1 |= (CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testen_MASK | CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testdin(address));

    /* Set then clear phy_testclk */
    base->PHY_TEST_CTRL0 |= CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclk_MASK;
    base->PHY_TEST_CTRL0 &= ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclk_MASK;

    /* Read dphy test address values */
    values = base->PHY_TEST_CTRL1;
    values = (uint32_t)(CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testdout(values));

    /* disable address writing operation and configure dphy register values */
    base->PHY_TEST_CTRL1 &= ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL1_phy_testen_MASK;

    return values;
}

status_t DWC_DPHY_Init(CAMERA_MIPI_CSI2_Type *csibase, CAMERA_DSI_OR_CSI_PHY_CSR_Type *phybase, csi2rx_config_t *config)
{
    status_t result = kStatus_Success;

    assert(NULL != config);

    csibase->DPHY_RSTZ &= ~CAMERA_MIPI_CSI2_DPHY_RSTZ_dphy_rstz_MASK;
    csibase->PHY_SHUTDOWNZ &= ~CAMERA_MIPI_CSI2_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    csibase->CSI2_RESETN &= ~CAMERA_MIPI_CSI2_CSI2_RESETN_csi2_resetn_MASK;

    csibase->PHY_TEST_CTRL0 |= CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclr_MASK;

    SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    csibase->PHY_TEST_CTRL0 = ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclr_MASK;

    /*
     * The DWC MIPI CSI2 HOST support four data lane, but different sensors have different lane capacities.
     * Such as ov5640 supprot 1/2 data lanes, OS08A20 support up to 4 lanes.
     * So set this value according to the user's application.
     */
    if (config->laneNum == 2U)
    {
        /* Enable lane control, default enable four data lanes */
        phybase->STANDALONE_PHY_MODE_CONTROL |= CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT(DWC_DPHY_DATALANE1) | 
                                                CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT(DWC_DPHY_DATALANE2);
    }
    else if(config->laneNum == 4U)
    {
        phybase->STANDALONE_PHY_MODE_CONTROL = CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK;
    }
    else
    {
        /* Fix misra c-2012 issue */
    }

    phybase->STANDALONE_PHY_TEST_MODE_CONTROL = 0;
    phybase->STANDALONE_PHY_TEST_MODE_CONTROL |= CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_basedir_0_MASK | 
                                                 CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK | 
                                                 CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK;

    /* Configure the number of active lanes for CSI host controller */
    csibase->N_LANES = config->laneNum - 1U;

    /* configure DPHY hsfreqrange and clk, hsfreqrange operation ranging from 80 Mbps to 2.5Gbps. it can be override by DPHY PHY_TEST_CTRL1 interface*/
    phybase->STANDALONE_PHY_FREQ_CONTROL |= CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange(config->cfgclkfreqrange) |
                                            CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_hsfreqrange(config->hsfreqrange);

    /* Set PHY_SHUTDOWNZ = 1'b1, DPHY_RSTZ = 1'b1 */
    csibase->PHY_SHUTDOWNZ |= CAMERA_MIPI_CSI2_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    /* delay 5ns */
    SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    csibase->DPHY_RSTZ |= CAMERA_MIPI_CSI2_DPHY_RSTZ_dphy_rstz_MASK;

    csibase->PHY_TEST_CTRL0 &= ~CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclk_MASK;
    csibase->PHY_TEST_CTRL0 |= CAMERA_MIPI_CSI2_PHY_TEST_CTRL0_phy_testclr_MASK;
    /* Wait until clock lane at stop state */
    while ((csibase->PHY_STOPSTATE & CAMERA_MIPI_CSI2_PHY_STOPSTATE_phy_stopstateclk_MASK) != CAMERA_MIPI_CSI2_PHY_STOPSTATE_phy_stopstateclk_MASK)
    {
    }
    return result;
}