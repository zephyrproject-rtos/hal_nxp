/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_netc_soc.h"
#include "fsl_netc_phy_wrapper.h"

/*! @brief Pointers to enetc si bases for each instance. */
static ENETC_SI_Type *const s_enetcSiBases[] = ENETC_SI_BASE_PTRS;

/*! @brief Pointers to netc bases for each instance. */
static ENETC_PCI_TYPE0_Type *const s_netcBases[] = ENETC_PCI_TYPE0_BASE_PTRS;

/*! @brief Pointers to netc vf bases for each instance. */
static ENETC_VF_PCI_TYPE0_Type *const s_netcVfBases[] = ENETC_VF_PCI_TYPE0_BASE_PTRS;

/*! @brief Pointers to enetc bases for each instance. */
static NETC_ENETC_Type *const s_netcEnetcBases[] = NETC_ENETC_BASE_PTRS;

void NETC_SocGetBaseResource(netc_enetc_hw_t *hw, netc_hw_si_idx_t si)
{
    uint8_t instance = getSiInstance(si);
    uint8_t siNum    = getSiNum(si);
    uint8_t siIdx    = getSiIdx(si);

    hw->si             = s_enetcSiBases[siIdx];
    hw->base           = s_netcEnetcBases[instance];
    hw->common         = (NETC_SW_ENETC_Type *)((uintptr_t)hw->base + 0x1000U);
    hw->portGroup.port = (NETC_PORT_Type *)((uintptr_t)hw->base + 0x4000U);
    hw->portGroup.eth  = (NETC_ETH_LINK_Type *)((uintptr_t)hw->base + 0x5000U);
    hw->global         = (ENETC_GLOBAL_Type *)((uintptr_t)hw->base + 0x10000U);
    if (siNum == 0U)
    {
        hw->func.pf   = s_netcBases[1U + siIdx];
        hw->msixTable = (netc_msix_entry_t *)((uintptr_t)hw->si + 0x30000U);
    }
    else
    {
        hw->func.vf   = s_netcVfBases[siIdx - 2U];
        hw->msixTable = (netc_msix_entry_t *)((uintptr_t)hw->si + 0x60000U);
    }
}

uint32_t NETC_SocGetFuncInstance(netc_hw_eth_port_idx_t port)
{
    uint32_t instance = (uint32_t)port + 1U;

    return instance;
}

status_t NETC_SocPreInitVsi(netc_enetc_hw_t *hw, netc_hw_si_idx_t si)
{
    return kStatus_Success;
}

static status_t NETC_PHYSelectMPLL(netc_mdio_handle_t *handle, bool is_2p5g)
{
    uint16_t val;
    status_t ret;

    NETC_PHYWriteBits(handle, false, PHY_DEV_GLOBAL, REG_GLOBAL_CTRL_EX_4, REG_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE,
                      REG_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE);
    NETC_PHYWriteBits(handle, false, PHY_DEV_GLOBAL, REG_GLOBAL_CTRL_EX_4, REG_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE,
                      REG_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE);

    NETC_PHYRead(handle, false, PHY_DEV_GLOBAL, REG_GLOBAL_CTRL_EX_0, &val);
    val = is_2p5g ? (val | REG_GLOBAL_CTRL_EX_0_MPLLB_SEL) : (val & ~REG_GLOBAL_CTRL_EX_0_MPLLB_SEL);
    NETC_PHYWrite(handle, false, PHY_DEV_GLOBAL, REG_GLOBAL_CTRL_EX_0, val);

    SDK_DelayAtLeastUs(1000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    ret = NETC_PHYPollBit(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_SRAM, REG_PMA_SRAM_INIT_DN, 1);
    if (ret != kStatus_Success)
    {
        return ret;
    }

    SDK_DelayAtLeastUs(1000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    NETC_PHYWriteBits(handle, false, PHY_DEV_GLOBAL, REG_GLOBAL_CTRL_EX_0, REG_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS,
                      REG_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS);

    return NETC_PHYPollBit(handle, true, PHY_PCS_DEV_VEND2, REG_PCS_CTRL1, REG_PCS_CTRL1_RESET, 0);
}

static status_t NETC_PHYInit2P5G(netc_mdio_handle_t *handle)
{
    status_t ret;

    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_MII_DIG_CTRL1, REG_MII_DIG_CTRL1_EN_2_5G_MODE,
                      REG_MII_DIG_CTRL1_EN_2_5G_MODE);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_MII_CTRL, REG_MII_CTRL_SS13, 0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_MII_CTRL, REG_MII_CTRL_SS6, REG_MII_CTRL_SS6);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_MII_CTRL, REG_MII_CTRL_AN_ENABLE, 0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL,
                      REG_PMA_MPLL_CMN_CTRL_MPLLB_SEL_0, REG_PMA_MPLL_CMN_CTRL_MPLLB_SEL_0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_REF_CLK_CTRL,
                      REG_PMA_REF_CLK_CTRL_REF_RANGE_MASK, REG_PMA_REF_CLK_CTRL_REF_RANGE(2));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_REF_CLK_CTRL,
                      REG_PMA_REF_CLK_CTRL_REF_CLK_DIV2, REG_PMA_REF_CLK_CTRL_REF_CLK_DIV2);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_REF_CLK_CTRL,
                      REG_PMA_REF_CLK_CTRL_REF_MPLLB_DIV2, REG_PMA_REF_CLK_CTRL_REF_MPLLB_DIV2);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_MPLLB_CTRL0,
                      REG_PMA_MPLLB_CTRL0_MPLLB_MULTIPLIER_MASK,
                      REG_PMA_MPLLB_CTRL0_MPLLB_MULTIPLIER(0x7D)); // DEC 125
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_MPLLB_CTRL0,
                      REG_PMA_MPLLB_CTRL0_MPLLB_CAL_DISABLE, 0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_MPLLB_CTRL1,
                      REG_PMA_MPLLB_CTRL1_MPLLB_FRACN_CTRL_MASK, REG_PMA_MPLLB_CTRL1_MPLLB_FRACN_CTRL(0x0));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_MPLLB_CTRL2,
                      REG_PMA_MPLLB_CTRL2_V2_MPLLB_TX_CLK_DIV_MASK, REG_PMA_MPLLB_CTRL2_V2_MPLLB_TX_CLK_DIV(0x5));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_MPLLB_CTRL2,
                      REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV10_CLK_EN, REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV10_CLK_EN);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_MPLLB_CTRL2,
                      REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV8_CLK_EN, 0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_MPLLB_CTRL2,
                      REG_PMA_MPLLB_CTRL2_V2_MPLLB_WRD_DIV2_EN, 0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_16G_MPLLB_CTRL3,
                      REG_PMA_MPLL_CTRL3_MPLLB_BANDWIDTH_MASK,
                      REG_PMA_MPLL_CTRL3_MPLLB_BANDWIDTH(0x3f)); // DEC 63
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_VCO_CAL_LD0,
                      REG_PMA_VCO_CAL_LD0_VCO_LD_VAL_0_MASK,
                      REG_PMA_VCO_CAL_LD0_VCO_LD_VAL_0(0x546)); // DEC 1350
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_16G_25G_VCO_CAL_REF0,
                      REG_PMA_VCO_CAL_REF0_V2_VCO_REF_LD_0_MASK,
                      REG_PMA_VCO_CAL_REF0_V2_VCO_REF_LD_0(0x1b)); // DEC 27
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_RX_GENCTRL1,
                      REG_PMA_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0, 0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_TX_RATE_CTRL,
                      REG_PMA_TX_RATE_CTRL_TX0_RATE_MASK, REG_PMA_TX_RATE_CTRL_TX0_RATE(0x0));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_RX_RATE_CTRL,
                      REG_PMA_RX_RATE_CTRL_RX0_RATE_MASK, REG_PMA_RX_RATE_CTRL_RX0_RATE(0x1));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_TX_GENCTRL2,
                      REG_PMA_TX_GENCTRL2_TX0_WIDTH_MASK, REG_PMA_TX_GENCTRL2_TX0_WIDTH(0x1));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_RX_GENCTRL2,
                      REG_PMA_RX_GENCTRL2_RX0_WIDTH_MASK, REG_PMA_RX_GENCTRL2_RX0_WIDTH(0x1));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_AFE_DFE_EN_CTRL, REG_PMA_AFE_DFE_EN_CTRL_AFE_EN_0,
                      0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_AFE_DFE_EN_CTRL, REG_PMA_AFE_DFE_EN_CTRL_DFE_EN_0,
                      0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_16G_25G_RX_EQ_CTRL0,
                      REG_PMA_RX_EQ_CTRL0_CTLE_BOOST_0_MASK, REG_PMA_RX_EQ_CTRL0_CTLE_BOOST_0(0x7));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0,
                      REG_PMA_DFE_TAP_CTRL0_DFE_TAP1_0_MASK, REG_PMA_DFE_TAP_CTRL0_DFE_TAP1_0(0x0));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_RX_CDR_CTRL,
                      REG_PMA_RX_CDR_CTRL_VCO_LOW_FREQ_0, REG_PMA_RX_CDR_CTRL_VCO_LOW_FREQ_0);
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_MII_DIG_CTRL1, REG_MII_DIG_CTRL1_VR_RST,
                      REG_MII_DIG_CTRL1_VR_RST);

    ret = NETC_PHYPollBit(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_SRAM, REG_PMA_SRAM_INIT_DN, 1);
    if (ret != kStatus_Success)
    {
        return ret;
    }

    SDK_DelayAtLeastUs(1000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    NETC_PHYWriteBits(handle, false, PHY_DEV_GLOBAL, REG_GLOBAL_CTRL_EX_0, REG_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS,
                      REG_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS);

    ret = NETC_PHYPollBit(handle, true, PHY_PCS_DEV_VEND2, REG_MII_DIG_CTRL1, REG_MII_DIG_CTRL1_VR_RST, 0);
    if (ret != kStatus_Success)
    {
        return ret;
    }

    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_TX_EQ_CTRL0,
                      REG_PMA_TX_EQ_CTRL0_TX_EQ_PRE_MASK, REG_PMA_TX_EQ_CTRL0_TX_EQ_PRE(0x0));
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_TX_EQ_CTRL0,
                      REG_PMA_TX_EQ_CTRL0_TX_EQ_MAIN_MASK,
                      REG_PMA_TX_EQ_CTRL0_TX_EQ_MAIN(0x18)); // DEC 24
    NETC_PHYWriteBits(handle, true, PHY_PCS_DEV_VEND2, REG_PMA_MP_12G_16G_25G_TX_EQ_CTRL1,
                      REG_PMA_TX_EQ_CTRL1_TX_EQ_POST_MASK, REG_PMA_TX_EQ_CTRL1_TX_EQ_POST(0x0));
    return kStatus_Success;
}

status_t NETC_PHYInit(netc_mdio_handle_t *handle, phy_mode_t mode)
{
    status_t ret;

    if (mode != kNETC_SGMII2G5)
    {
        return kStatus_InvalidArgument;
    }

    ret = NETC_PHYSelectMPLL(handle, true);
    if (ret != kStatus_Success)
    {
        return ret;
    }

    ret = NETC_PHYInit2P5G(handle);
    if (ret != kStatus_Success)
    {
        return ret;
    }

    return kStatus_Success;
}
