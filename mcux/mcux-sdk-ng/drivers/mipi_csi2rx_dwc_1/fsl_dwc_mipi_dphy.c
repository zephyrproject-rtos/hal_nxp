/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dwc_mipi_dphy.h"

void DWC_DPHY_Reset(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, const csi2rx_config_t *config)
{
    if (config->phyNumber == KCSI2RX_DPHY_Primary)
    {
        /* Put DPHY into reset state */
        csi1->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi1->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
        SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

        /* Remove the DPHY from reset state */
        csi1->PHY_SHUTDOWNZ = ((csi1->PHY_SHUTDOWNZ & ~ PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK);
        SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        csi1->DPHY_RSTZ = ((csi1->DPHY_RSTZ & ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK);
    }
    else
    {
        /* Put DPHY into reset state */
        csi2->DPHY_RSTZ &= ~SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi2->PHY_SHUTDOWNZ &= ~SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
        SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

        /* Remove the DPHY from reset state */
        csi2->PHY_SHUTDOWNZ = ((csi2->PHY_SHUTDOWNZ & ~ SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK);
        SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        csi2->DPHY_RSTZ = ((csi2->DPHY_RSTZ & ~SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK);
    }
}

void DWC_DPHY_TestCodeReset(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, const csi2rx_config_t *config)
{
    if (config->phyNumber == KCSI2RX_DPHY_Primary)
    {
        /* Set PHY test codes from reset */
        csi1->PHY_TEST_CTRL0 = ((csi1->PHY_TEST_CTRL0 & ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK);

        /* release PHY test codes from reset */
        csi1->PHY_TEST_CTRL0 &= ~PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK;
    }
    else
    {
        csi2->PHY_TEST_CTRL0 = ((csi2->PHY_TEST_CTRL0 & ~SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK) | SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK);

        /* release PHY test codes from reset */
        csi2->PHY_TEST_CTRL0 &= ~SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclr_MASK;
    }
}

void DWC_DPHY_SetTestConfigureCSI1(PRIMARY_CSI2_CONTROLLER_Type *csi1, uint32_t address, uint8_t values)
{
    uint8_t phy_testclr;
    uint8_t phy_testdin;
    uint8_t phy_testen;
    uint8_t phy_testclk;

    phy_testclr   = 0;
    phy_testclk   = 1;
    phy_testdin   = address;
    phy_testen    = 1;

    csi1->PHY_TEST_CTRL1 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);

    csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

    phy_testclk   = 0;
    csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

    phy_testclk   = 0;
    phy_testen    = 0;
    phy_testdin   = values;
    csi1->PHY_TEST_CTRL1 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);
    csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

    phy_testclk   = 1;
    csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
    phy_testclk   = 0;
    csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
}

void DWC_DPHY_SetTestConfigureCSI2(SECONDARY_CSI2_CONTROLLER_Type *csi2, uint32_t address, uint8_t values)
{
    uint8_t phy_testclr;
    uint8_t phy_testdin;
    uint8_t phy_testen;
    uint8_t phy_testclk;

    phy_testclr   = 0;
    phy_testclk   = 1;
    phy_testdin   = address;
    phy_testen    = 1;

    csi2->PHY_TEST_CTRL1 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);

    csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

    phy_testclk   = 0;
    csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

    phy_testclk   = 0;
    phy_testen    = 0;
    phy_testdin   = values;
    csi2->PHY_TEST_CTRL1 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);
    csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

    phy_testclk   = 1;
    csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
    phy_testclk   = 0;
    csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
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

void DWC_DPHY_InitNormal(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    if (config->phyNumber == KCSI2RX_DPHY_Primary)
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
                                                  CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK |
                                                  CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK |
                                                  CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK);
        /* Enable PRIMARY data lane */
        phybase->PRIMARY_PHY_MODE_CONTROL = ((phybase->PRIMARY_PHY_MODE_CONTROL & ~CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK) |
                                             CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK);

        SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

        /* Set PHY_SHUTDOWNZ = 1'b1, DPHY_RSTZ = 1'b1 */
        csi1->PHY_SHUTDOWNZ = (csi1->PHY_SHUTDOWNZ & ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
        /* delay 5ns */
        SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        csi1->DPHY_RSTZ = (csi1->DPHY_RSTZ & ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi1->CSI2_RESETN |= PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;

        /* Configure the number of active lanes for CSI host controller */
        csi1->N_LANES = config->laneNum - 1U;

        /* Wait until clock lane at stop state */
        while ((csi1->PHY_STOPSTATE & PRIMARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK) != PRIMARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK)
        {
        }
    }
    else
    {
        /* configure DPHY hsfreqrange and clk, hsfreqrange operation ranging from 80 Mbps to 2.5Gbps. it can be override by DPHY PHY_TEST_CTRL1 interface*/
        phybase->SECONDARY_PHY_FREQ_CONTROL = (phybase->SECONDARY_PHY_FREQ_CONTROL & ~(CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK |
                                             CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK)) |
                                            (CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange(config->cfgclkFreqrange) |
                                             CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_hsfreqrange(config->hsFreqrange));

        phybase->SECONDARY_PHY_TEST_MODE_CONTROL = 0;
        phybase->SECONDARY_PHY_TEST_MODE_CONTROL = CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK |
                                                 CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK |
                                                 CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK;
        SDK_DelayAtLeastUs(15, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        phybase->SECONDARY_PHY_TEST_MODE_CONTROL = (phybase->SECONDARY_PHY_TEST_MODE_CONTROL & ~(CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK |
                                                  CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK)) |
                                                 (CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK |
                                                  CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK |
                                                  CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK |
                                                  CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK);
        /* Enable SECONDARY data lane */
        phybase->SECONDARY_PHY_MODE_CONTROL = ((phybase->SECONDARY_PHY_MODE_CONTROL & ~CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK) |
                                             CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK);

        SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

        /* Set PHY_SHUTDOWNZ = 1'b1, DPHY_RSTZ = 1'b1 */
        csi2->PHY_SHUTDOWNZ = (csi2->PHY_SHUTDOWNZ & ~SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
        /* delay 5ns */
        SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        csi2->DPHY_RSTZ = (csi2->DPHY_RSTZ & ~SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi2->CSI2_RESETN |= SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;

        /* Configure the number of active lanes for CSI host controller */
        csi2->N_LANES = config->laneNum - 1U;

        /* Wait until clock lane at stop state */
        while ((csi2->PHY_STOPSTATE & SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK) != SECONDARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK)
        {
        }
    }
}

void DWC_DPHY_InitAggr(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
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
                                              CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK |
                                              CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK |
                                              CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK);
    /* Enable PRIMARY data lane */
    phybase->PRIMARY_PHY_MODE_CONTROL = ((phybase->PRIMARY_PHY_MODE_CONTROL & ~CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK) |
                                         CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK);

    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    phybase->SECONDARY_PHY_TEST_MODE_CONTROL |= CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK;

    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_1);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_1);

    /* Configure RX_SYS_6 (tolerance) for testcode_x = 3 */
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_6, 0x4U);  /* tolerance = 0x4 */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_6, 0x0U);  /* tolerance = 0x0 */

    /* Configure RX_SYS_7 for testcode_x = 5 */
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_5);
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_7, (0x2U << 5));  /* tclk_miss_cnt = 2 */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_5);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_7, (0x2U << 5));  /* tclk_miss_cnt = 2 */

    /* Configure RX_SYS_7 for testcode_x = 7 */
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_7);
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_7, (0x2U << 5));  /* tclk_miss_cnt = 2 */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_7);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_7, (0x2U << 5));  /* tclk_miss_cnt = 2 */

    /* Configure RX_SYS_7 for testcode_x = 3 with different values */
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
    DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_7, 0x0U);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_7, (0x1U << 3));  /* deskew_polarity_rw = 1 */

    /* Configure RX_STARTUP_OVR_0 for testcode_x = 0 */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_0, 
                                  (DWC_DPHY_RX_STARTUP_OVR_0_CLK_EN_LNS_TESTER_MASK | 
                                   DWC_DPHY_RX_STARTUP_OVR_0_CLK_EN_LNS_BYPASS_MASK));

    /* Configure RX_STARTUP_OVR_1 for testcode_x = 0 */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_1,
                                  (DWC_DPHY_RX_STARTUP_OVR_1_DESKEW_LEGACY_OVR_EN_MASK |
                                   DWC_DPHY_RX_STARTUP_OVR_1_DESKEW_LEGACY_OVR_MASK |
                                   DWC_DPHY_RX_STARTUP_OVR_1_ENABLE_LNS_OVR_MASK |
                                   DWC_DPHY_RX_STARTUP_OVR_1_RXCLK_DDR_CLK_EN_BYPASS_MASK));

    /* Configure RX_SYS_6 for testcode_x = 3 with aggregated mode value */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_6, (0x1U << 3));  /* tolerance bit 3 set */

    /* Configure RX_SYS_3 (hsdirect) for testcode_x = 3 */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_3, DWC_DPHY_RX_SYS_3_HSDIRECT_MASK);

    /* Configure RX_SYS_4 for testcode_x = 3 */
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
    DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_4, DWC_DPHY_RX_SYS_3_HSDIRECT_MASK);  /* Same value 0x80 */

    phybase->PHY_TEST_IO_CONT |= CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_en_MASK;
    phybase->CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL |= CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_MASK;
    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    csi1->PHY_SHUTDOWNZ = (csi1->PHY_SHUTDOWNZ & ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    csi1->DPHY_RSTZ = (csi1->DPHY_RSTZ & ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    csi1->CSI2_RESETN |= PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
    csi1->N_LANES = config->laneNum - 1U;

    /* Set PHY_SHUTDOWNZ = 1'b1, DPHY_RSTZ = 1'b1 */
    csi2->PHY_SHUTDOWNZ = (csi2->PHY_SHUTDOWNZ & ~SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK) | SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    /* delay 5ns */
    SDK_DelayAtLeastUs(5, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    csi2->DPHY_RSTZ = (csi2->DPHY_RSTZ & ~SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK) | SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
    csi2->CSI2_RESETN |= SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;

    /* Wait until clock lane at stop state */
    while ((csi1->PHY_STOPSTATE & PRIMARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK) != PRIMARY_CSI2_CONTROLLER_PHY_STOPSTATE_phy_stopstateclk_MASK)
    {
    }
}
