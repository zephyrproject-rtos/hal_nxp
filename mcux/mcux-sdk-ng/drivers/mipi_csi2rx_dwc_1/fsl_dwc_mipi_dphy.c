/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dwc_mipi_dphy.h"

void DWC_DPHY_PowerOff(PRIMARY_CSI2_CONTROLLER_Type *base)
{
    /* Poweroff DWC RX DPHY module */
    base->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;

    base->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
}

void DWC_DPHY_Reset(PRIMARY_CSI2_CONTROLLER_Type *base)
{
    /* Put DPHY into reset state */
    base->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
    base->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    /* Remove the DPHY from reset state */
    base->PHY_SHUTDOWNZ = ((base->PHY_SHUTDOWNZ & ~ PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK);
    SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    base->DPHY_RSTZ = ((base->DPHY_RSTZ & ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK);
}

void DWC_DPHY_TestCodeReset(PRIMARY_CSI2_CONTROLLER_Type *base)
{
    /* Set PHY test codes from reset */
    base->PHY_TEST_CTRL0 = ((base->PHY_TEST_CTRL0 & ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK);

    /* release PHY test codes from reset */
    base->PHY_TEST_CTRL0 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK;
}

void DWC_DPHY_SetTestConfigure(PRIMARY_CSI2_CONTROLLER_Type *base, uint32_t address, uint8_t values)
{
    /* enable address writing operation and set dphy offset address */
    base->PHY_TEST_CTRL1 = ((base->PHY_TEST_CTRL1 & ~(PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK |
                                                      PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin(address))) |
                                                     (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK |
                                                      PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin(address)));

    /* Set then clear phy_testclk */
    base->PHY_TEST_CTRL0 = ((base->PHY_TEST_CTRL0 & ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK);
    base->PHY_TEST_CTRL0 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK;

    /* disable address writing operation and configure dphy register values */
    base->PHY_TEST_CTRL1 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK;
    base->PHY_TEST_CTRL1 = ((base->PHY_TEST_CTRL1 & ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin(values)) | PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin(values));

    /* Set then clear phy_testclk */
    base->PHY_TEST_CTRL0 = ((base->PHY_TEST_CTRL0 & ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK);
    base->PHY_TEST_CTRL0 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK;
}

uint32_t DWC_DPHY_ReadTestConfigure(PRIMARY_CSI2_CONTROLLER_Type *base, uint8_t address)
{
    uint32_t values = 0;

    /* enable address writing operation and set dphy offset address */
    base->PHY_TEST_CTRL1 = ((base->PHY_TEST_CTRL1 & ~(PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK |
                                                      PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin(address))) |
                                                     (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK |
                                                      PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdin(address)));

    /* Set then clear phy_testclk */
    base->PHY_TEST_CTRL0 = ((base->PHY_TEST_CTRL0 & ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK);
    base->PHY_TEST_CTRL0 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk_MASK;

    /* Read dphy test address values */
    values = base->PHY_TEST_CTRL1;
    values = (uint32_t)(PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testdout(values));

    /* disable address writing operation and configure dphy register values */
    base->PHY_TEST_CTRL1 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen_MASK;

    return values;
}

static void DWC_DHYPrimayInT(CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    /* configure DPHY hsfreqrange and clk, hsfreqrange operation ranging from 80 Mbps to 2.5Gbps. it can be override by DPHY PHY_TEST_CTRL1 interface*/
    phybase->PRIMARY_PHY_FREQ_CONTROL = (phybase->PRIMARY_PHY_FREQ_CONTROL & ~(CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK |
                                         CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK)) |
                                        (CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange(config->cfgclkFreqrange) |
                                         CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_hsfreqrange(config->hsFreqrange));

    phybase->PRIMARY_PHY_TEST_MODE_CONTROL = 0;
    phybase->PRIMARY_PHY_TEST_MODE_CONTROL = CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK |
                                             CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK |
                                             CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK;
    SDK_DelayAtLeastUs(15, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    phybase->PRIMARY_PHY_TEST_MODE_CONTROL = (phybase->PRIMARY_PHY_TEST_MODE_CONTROL & ~(CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK |
                                              CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK)) |
                                             (CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK |
                                              CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK);
    /* Enable PRIMARY data lane */
    phybase->PRIMARY_PHY_MODE_CONTROL = ((phybase->PRIMARY_PHY_MODE_CONTROL & ~CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK) |
                                         CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK);

    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

static void DWC_DHYSecondryInT(CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    uint32_t tmp;

    phybase->SECONDARY_PHY_MODE_CONTROL = 0;

    tmp = phybase->SECONDARY_PHY_TEST_MODE_CONTROL & ~(CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK |
                                                       CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK |
                                                       CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK);
    tmp |= CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK | CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK |
          CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK;
    phybase->SECONDARY_PHY_TEST_MODE_CONTROL = tmp;
    SDK_DelayAtLeastUs(15, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    tmp = (phybase->SECONDARY_PHY_TEST_MODE_CONTROL) & ~(CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK |
                                                         CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK);
    tmp |= CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK | CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK;
    phybase->SECONDARY_PHY_TEST_MODE_CONTROL = tmp;

    /* Enable secondry data lane */
    phybase->SECONDARY_PHY_MODE_CONTROL = ((phybase->SECONDARY_PHY_MODE_CONTROL & ~CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK) |
                                           CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK);
}

status_t DWC_DPHY_Init(PRIMARY_CSI2_CONTROLLER_Type *csibase, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    status_t result = kStatus_Success;

    assert(NULL != config);

    /* Configure the number of active lanes for CSI host controller */
    csibase->N_LANES = config->laneNum - 1U;

    csibase->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
    csibase->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    csibase->CSI2_RESETN &= ~PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;

    csibase->PHY_TEST_CTRL0 = (csibase->PHY_TEST_CTRL0 & ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK;

    SDK_DelayAtLeastUs(15, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    csibase->PHY_TEST_CTRL0 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK;

    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    if (config->phyMode == KCSI2RX_DPHY_AggregatedMode)
    {
        DWC_DHYPrimayInT(phybase, config);
        DWC_DHYSecondryInT(phybase, config);
        phybase->CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL = (phybase->CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL & ~CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_MASK) |
                                                                                                          CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_MASK;
    }
    else if (config->phyNumber == KCSI2RX_DPHY_Primary)
    {
        DWC_DHYPrimayInT(phybase, config);
        phybase->CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL &= (~CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_MASK);
    }
    else if(config->phyNumber == KCSI2RX_DPHY_Secondary)
    {
        DWC_DHYSecondryInT(phybase, config);
        phybase->CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL &= (~CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_MASK);
    }
    else
    {
        /* error mode, return directly */
        return kStatus_Fail;
    }

    /* Set PHY_SHUTDOWNZ = 1'b1, DPHY_RSTZ = 1'b1 */
    csibase->PHY_SHUTDOWNZ = (csibase->PHY_SHUTDOWNZ & ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    /* delay 5ns */
    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    csibase->DPHY_RSTZ = (csibase->DPHY_RSTZ & ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;

    /* Wait until clock lane at stop state */
    while ((csibase->PHY_STOPSTATE & PRIMARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK) != PRIMARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK)
    {
    }
    return result;
}
