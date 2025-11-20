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

#define DWC_MIPI_CSI2_DATA_IDS1(vc, dt)            (uint32_t)(0x3FU)&(dt) << (uint32_t)(0x8U)*(vc)
#define DWC_MIPI_CSI2_DATA_IDS_VC1(vc)             (uint32_t)(0xFU)&(vc) << (uint32_t)(0x8U)*(vc)

#define DWC_MIPI_CSI2_INT_MSK_PHY_FATAL_MASK            (uint32_t)(0xFU)
#define DWC_MIPI_CSI2_INT_MSK_PKT_FATAL_MASK            (uint32_t)(0x3U)
#define DWC_MIPI_CSI2_INT_MSK_PHY_MASK                  (uint32_t)(0xF000FU)
#define DWC_MIPI_CSI2_INT_MSK_LINE_MASK                 (uint32_t)(0xFF00FFU)

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map MIPI CSI2RX instance number to base address. */
static const uint32_t s_csi2rxBaseAddrs[] = PRIMARY_CSI2_CONTROLLER_BASE_ADDRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to MPI CSI2RX clocks for each instance. */
static const clock_ip_name_t s_csi2rxClocks[] = CSI_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/

uint32_t MIPI_CSI2RX_GetInstance(PRIMARY_CSI2_CONTROLLER_Type *base)
{
    uint32_t i;

    for (i = 0U; i < ARRAY_SIZE(s_csi2rxBaseAddrs); i++)
    {
        if (MSDK_REG_SECURE_ADDR((uint32_t)base) == MSDK_REG_SECURE_ADDR(s_csi2rxBaseAddrs[i]))
        {
            return i;
        }
    }

    assert(false);

    return 0;
}

void MIPI_CSI2RX_Startup(PRIMARY_CSI2_CONTROLLER_Type *base)
{
    /* Release DWC mipi csi2 host from reset */
    base->CSI2_RESETN &= ~PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
    base->CSI2_RESETN |= PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;

    /* Apply PHY reset*/
    DWC_DPHY_Reset(base);

    /* Set and release PHY test codes from reset */
    DWC_DPHY_TestCodeReset(base);
}

status_t MIPI_CSI2RX_InitInterface(PRIMARY_CSI2_CONTROLLER_Type *base, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    assert(NULL != config);
    status_t result = kStatus_Success;

    /* Put Synopsys DPHY to reset status */
    base->DPHY_RSTZ &= ~PRIMARY_CSI2_CONTROLLER_DPHY_RSTZ_dphy_rstz_MASK;
    base->PHY_SHUTDOWNZ &= ~PRIMARY_CSI2_CONTROLLER_PHY_SHUTDOWNZ_phy_shutdownz_MASK;
    base->CSI2_RESETN &= ~PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;

    /* Init CSI PHY interface */
    result = DWC_DPHY_Init(base, phybase, config);

    base->CSI2_RESETN = ((base->CSI2_RESETN & ~PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK) | PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK);

    /* The dwc csi host interface supports up to 8 virtual channels, configure vitrual channel datatype */
    if (config->vcNum <= (uint32_t)3)
    {
        base->DATA_IDS_1 =  ((base->DATA_IDS_1 & ~DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType)) | DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType));
        base->DATA_IDS_VC_1 &= DWC_MIPI_CSI2_DATA_IDS_VC1(config->vcNum);
    }
    else if (config->vcNum > 3 && config->vcNum <= 7)
    {
        base->DATA_IDS_2 = ((base->DATA_IDS_2 & ~DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType)) | DWC_MIPI_CSI2_DATA_IDS1(config->vcNum, config->dataType));
        base->DATA_IDS_VC_2 &= DWC_MIPI_CSI2_DATA_IDS_VC1(config->vcNum);
    }

    return result;
}

status_t MIPI_CSI2RX_Init(PRIMARY_CSI2_CONTROLLER_Type *pribase, SECONDARY_CSI2_CONTROLLER_Type *secbase, CAMERA_PHY_CSR_Type *phybase, const csi2rx_config_t *config)
{
    status_t result = kStatus_Success;
    PRIMARY_CSI2_CONTROLLER_Type *base;

    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* un-gate clock */
    (void)CLOCK_EnableClock(s_csi2rxClocks[CSI2RX_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /*
     * Check the required number of data lanes for the CSI interface.
     * When the D-PHY operates in normal mode, each CSI interface supports up to 2 data lanes.
     * In aggregation mode, 4 data lanes can be implemented on the first interface.
     */
    if (config->phyMode == KCSI2RX_DPHY_NormalMode)
    {
        assert (config->laneNum <= 2);
        if (config->phyNumber == KCSI2RX_DPHY_Primary)
        {
            base = pribase;
        }
        else
        {
            base = (PRIMARY_CSI2_CONTROLLER_Type *)secbase;
        }
    }
    else if ((config->phyMode == KCSI2RX_DPHY_AggregatedMode) && (config->phyNumber == KCSI2RX_DPHY_Primary))
    {
        assert (config->laneNum <= 4);
        base = (PRIMARY_CSI2_CONTROLLER_Type *)pribase;
    }

    /* Start up MIPI CSI-2 host control */
    MIPI_CSI2RX_Startup(base);

    /* Initialize the MIPI CSI-2 host controller */
    result = MIPI_CSI2RX_InitInterface(base, phybase, config);

    /* Define errors mask, enable CSI interrupt. */
    base->INT_MSK_PHY_FATAL &= ~DWC_MIPI_CSI2_INT_MSK_PHY_FATAL_MASK;
    base->INT_MSK_PKT_FATAL &= ~DWC_MIPI_CSI2_INT_MSK_PKT_FATAL_MASK;
    base->INT_MSK_PHY &= ~DWC_MIPI_CSI2_INT_MSK_PHY_MASK;
    base->INT_MSK_LINE &= ~DWC_MIPI_CSI2_INT_MSK_LINE_MASK;

    return result;
}

void MIPI_CSI2RX_Deinit(PRIMARY_CSI2_CONTROLLER_Type *base)
{
    base->CSI2_RESETN &= ~PRIMARY_CSI2_CONTROLLER_CSI2_RESETN_csi2_resetn_MASK;
    DWC_DPHY_PowerOff(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* gate clock */
    (void)CLOCK_DisableClock(s_csi2rxClocks[CSI2RX_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
