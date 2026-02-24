/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dwc_mipi_dphy.h"

/*
 * The MIPI CSI2 host controller implements CSI-2 protocol on host side, MIPI Rx D-PHY module implement
 * the physical layer for the MIPI D-PHY interface.
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dwc_mipi_csi2rx_1"
#endif
#define DWC_MIPI_CSI2_DATA_IDS1(vc, dt)            (((uint32_t)(0x3FU) & (dt)) << ((uint32_t)(0x8U) * (vc)))
#define DWC_MIPI_CSI2_DATA_IDS_VC1(vc)             (((uint32_t)(0xFU) & (vc)) << ((uint32_t)(0x8U) * (vc)))
#define DWC_MIPI_CSI2_INT_MSK_PHY_FATAL_MASK            (uint32_t)(0xFU)
#define DWC_MIPI_CSI2_INT_MSK_PKT_FATAL_MASK            (uint32_t)(0x3U)
#define DWC_MIPI_CSI2_INT_MSK_PHY_MASK                  (uint32_t)(0xF000FU)
#define DWC_MIPI_CSI2_INT_MSK_LINE_MASK                 (uint32_t)(0xFF00FFU)

/*******************************************************************************
 * Code
 ******************************************************************************/

void MIPI_CSI2RX_Startup(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, const csi2rx_config_t *config)
{
    if (config->phyNumber == KCSI2RX_DPHY_Primary)
    {
        /* Release DWC mipi csi2 host from reset */
        csi1->CSI2_RESETN &= ~PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
        csi1->CSI2_RESETN |= PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
    }
    else
    {
        /* Release DWC mipi csi2 host from reset */
        csi2->CSI2_RESETN &= ~SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
        csi2->CSI2_RESETN |= SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
    }

    /* Apply PHY reset*/
    DWC_DPHY_Reset(csi1, csi2, config);

    /* Set and release PHY test codes from reset */
    DWC_DPHY_TestCodeReset(csi1, csi2, config);
}

void MIPI_CSI2RX_PhyConfigure(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2,
                              uint8_t hsfreq,  uint16_t ddl_osc_freq, const csi2rx_config_t *config)
{
    uint8_t lowbyte_ddl_osc_freq = ddl_osc_freq & 0xFF;
    uint8_t highbyte_ddl_osc_freq = (ddl_osc_freq >> 8) & 0xFF;

    if (config->phyMode == KCSI2RX_DPHY_NormalMode)
    {
        if (config->phyNumber == KCSI2RX_DPHY_Primary)
        {
            /* Select testcode extension 0 and configure HS frequency range */
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_0, DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_ENABLE);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_1, hsfreq);

            /* Enable DDL oscillation frequency override */
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_5, DWC_DPHY_RX_STARTUP_OVR_5_COUNTER_BYPASS_MASK);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_4, (0x1U << 4));  /* counter_for_des_en_config_if = 1 */

            /* Configure calibration settings (undocumented registers) */
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_1);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_9, 0x43U);  /* deskew_numedges value */
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_6, 0x80U);  /* tolerance value */

            /* Configure DDL oscillation frequency */
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_2, lowbyte_ddl_osc_freq);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_3, highbyte_ddl_osc_freq);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_4, ((0x1U << 4) | DWC_DPHY_RX_STARTUP_OVR_4_DDL_OSC_FREQ_OVR_EN_MASK));
        }
        else
        {
            /* Select testcode extension 0 and configure HS frequency range */
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_0, DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_ENABLE);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_1, hsfreq);

            /* Enable DDL oscillation frequency override */
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_5, DWC_DPHY_RX_STARTUP_OVR_5_COUNTER_BYPASS_MASK);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_4, (0x1U << 4));  /* counter_for_des_en_config_if = 1 */

            /* Configure calibration settings (undocumented registers) */
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_1);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_9, 0x43U);  /* deskew_numedges value */
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_3);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_6, 0x80U);  /* tolerance value */

            /* Configure DDL oscillation frequency */
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_2, lowbyte_ddl_osc_freq);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_3, highbyte_ddl_osc_freq);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
            DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_4, ((0x1U << 4) | DWC_DPHY_RX_STARTUP_OVR_4_DDL_OSC_FREQ_OVR_EN_MASK));
        }
    }
    else
    {
        /* Aggregated mode - Configure CSI1 */
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_0, DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_ENABLE);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_SYS_1, hsfreq);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_5, DWC_DPHY_RX_STARTUP_OVR_5_COUNTER_BYPASS_MASK);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_4, (0x1U << 4));

        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_2, lowbyte_ddl_osc_freq);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_3, highbyte_ddl_osc_freq);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI1(csi1, DWC_DPHY_RX_STARTUP_OVR_4, ((0x1U << 4) | DWC_DPHY_RX_STARTUP_OVR_4_DDL_OSC_FREQ_OVR_EN_MASK));

        /* Aggregated mode - Configure CSI2 */
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_0, DWC_DPHY_RX_SYS_0_HSFREQRANGE_SEL_ENABLE);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_SYS_1, hsfreq);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_5, DWC_DPHY_RX_STARTUP_OVR_5_COUNTER_BYPASS_MASK);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_4, (0x1U << 4));

        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_2, lowbyte_ddl_osc_freq);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_3, highbyte_ddl_osc_freq);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_TESTCODE_X_REG, DWC_DPHY_TESTCODE_X_VAL_0);
        DWC_DPHY_SetTestConfigureCSI2(csi2, DWC_DPHY_RX_STARTUP_OVR_4, ((0x1U << 4) | DWC_DPHY_RX_STARTUP_OVR_4_DDL_OSC_FREQ_OVR_EN_MASK));
    }
}

status_t MIPI_CSI2RX_InitInterface(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2,
                                   CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    assert(NULL != config);
    status_t result = kStatus_Success;

    uint8_t phy_testclr;
    uint8_t phy_testdin;
    uint8_t phy_testen;
    uint8_t phy_testclk;

    /* Select CSI and phy according into config */
    if (config->phyMode == KCSI2RX_DPHY_NormalMode)
    {
        if (config->phyNumber == KCSI2RX_DPHY_Primary)
        {
            /* Put Synopsys DPHY to reset status */
            csi1->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
            csi1->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;

            phy_testclr = 1;
            phy_testdin = 0;
            phy_testen = 0;
            phy_testclk = 0;

            csi1->PHY_TEST_CTRL1 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);
            csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
            SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
            phy_testclr = 0;
            csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

            MIPI_CSI2RX_PhyConfigure(csi1, csi2, config->hsFreqrange, config->ddl_osc_freq, config);
            DWC_DPHY_InitNormal(csi1, csi2, phybase, config);
            phybase->PRIMARY_PHY_TEST_MODE_CONTROL &= 0xfffffcff; /* Clear bits [9:8] */

            /* The dwc csi host interface supports up to 8 virtual channels, configure vitrual channel datatype */
            if (config->vcNum <= (uint32_t)3)
            {
                csi1->DATA_IDS_1 =  ((csi1->DATA_IDS_1 & ~DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType))
                                     | DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType));
                csi1->DATA_IDS_VC_1 &= DWC_MIPI_CSI2_DATA_IDS_VC1(config->vcNum);
            }
            else if (config->vcNum > 3 && config->vcNum <= 7)
            {
                csi1->DATA_IDS_2 = ((csi1->DATA_IDS_2 & ~DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType)) | DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType));
                csi1->DATA_IDS_VC_2 &= DWC_MIPI_CSI2_DATA_IDS_VC1(config->vcNum);
            }
        }
        else
        {
            /* Put Synopsys DPHY to reset status */
            csi2->DPHY_RSTZ &= ~SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
            csi2->PHY_SHUTDOWNZ &= ~SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;

            phy_testclr = 1;
            phy_testdin = 0;
            phy_testen = 0;
            phy_testclk = 0;

            csi2->PHY_TEST_CTRL1 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);
            csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
            SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
            phy_testclr = 0;
            csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

            MIPI_CSI2RX_PhyConfigure(csi1, csi2, config->hsFreqrange, config->ddl_osc_freq, config);
            DWC_DPHY_InitNormal(csi1, csi2, phybase, config);
            phybase->SECONDARY_PHY_TEST_MODE_CONTROL &= 0xfffffcff; /* Clear bits [9:8] */

            /* The dwc csi host interface supports up to 8 virtual channels, configure vitrual channel datatype */
            if (config->vcNum <= (uint32_t)3)
            {
                csi2->DATA_IDS_1 =  ((csi2->DATA_IDS_1 & ~DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType))
                                     | DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType));
                csi2->DATA_IDS_VC_1 &= DWC_MIPI_CSI2_DATA_IDS_VC1(config->vcNum);
            }
            else if (config->vcNum > 3 && config->vcNum <= 7)
            {
                csi2->DATA_IDS_2 = ((csi2->DATA_IDS_2 & ~DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType)) | DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType));
                csi2->DATA_IDS_VC_2 &= DWC_MIPI_CSI2_DATA_IDS_VC1(config->vcNum);
            }
        }
    }
    else
    {
        /* Put Synopsys DPHY to reset status */
        csi1->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi1->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
        phy_testclr = 1;
        phy_testdin = 0;
        phy_testen = 0;
        phy_testclk = 0;
        csi1->PHY_TEST_CTRL1 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);
        csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
        SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        phy_testclr = 0;
        csi1->PHY_TEST_CTRL0 = (PRIMARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

        /* Put Synopsys DPHY to reset status */
        csi2->DPHY_RSTZ &= ~SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi2->PHY_SHUTDOWNZ &= ~SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;

        phy_testclr = 1;
        phy_testdin = 0;
        phy_testen = 0;
        phy_testclk = 0;

        csi2->PHY_TEST_CTRL1 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL1_phy_testen(phy_testen) | phy_testdin);
        csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);
        SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        phy_testclr = 0;
        csi2->PHY_TEST_CTRL0 = (SECONDARY_CSI2_CONTROLLER_PHY_TEST_CTRL0_phy_testclk(phy_testclk) | phy_testclr);

        MIPI_CSI2RX_PhyConfigure(csi1, csi2, config->hsFreqrange, config->ddl_osc_freq, config);

        DWC_DPHY_InitAggr(csi1, csi2, phybase, config);
        phybase->PRIMARY_PHY_TEST_MODE_CONTROL &= 0xfffffcff; /* Clear bits [9:8] */
        phybase->SECONDARY_PHY_TEST_MODE_CONTROL &= 0xfffffcff; /* Clear bits [9:8] */
    }

    return result;
}

status_t MIPI_CSI2RX_Init(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    status_t result = kStatus_Success;

    assert(NULL != config);

    /* Start up MIPI CSI-2 host control */
    MIPI_CSI2RX_Startup(csi1, csi2, config);

    /* Initialize the MIPI CSI-2 host controller */
    result = MIPI_CSI2RX_InitInterface(csi1, csi2, phybase, config);

    /* Define errors mask, enable CSI interrupt. */
    csi1->INT_MSK_PHY_FATAL &= ~DWC_MIPI_CSI2_INT_MSK_PHY_FATAL_MASK;
    csi1->INT_MSK_PKT_FATAL &= ~DWC_MIPI_CSI2_INT_MSK_PKT_FATAL_MASK;
    csi1->INT_MSK_PHY &= ~DWC_MIPI_CSI2_INT_MSK_PHY_MASK;
    csi1->INT_MSK_LINE &= ~DWC_MIPI_CSI2_INT_MSK_LINE_MASK;
    csi2->INT_MSK_PHY_FATAL &= ~DWC_MIPI_CSI2_INT_MSK_PHY_FATAL_MASK;
    csi2->INT_MSK_PKT_FATAL &= ~DWC_MIPI_CSI2_INT_MSK_PKT_FATAL_MASK;
    csi2->INT_MSK_PHY &= ~DWC_MIPI_CSI2_INT_MSK_PHY_MASK;
    csi2->INT_MSK_LINE &= ~DWC_MIPI_CSI2_INT_MSK_LINE_MASK;

    return result;
}

void MIPI_CSI2RX_Deinit(PRIMARY_CSI2_CONTROLLER_Type *csi1, SECONDARY_CSI2_CONTROLLER_Type *csi2, uint8_t instance)
{
    if (instance == KCSI2RX_DPHY_Primary)
    {
        csi1->CSI2_RESETN &= ~PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
        /* Poweroff DWC RX DPHY module */
        csi1->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi1->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    }
    else
    {
        csi2->CSI2_RESETN &= ~SECONDARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
        /* Poweroff DWC RX DPHY module */
        csi2->DPHY_RSTZ &= ~SECONDARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
        csi2->PHY_SHUTDOWNZ &= ~SECONDARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    }
}

