/*
 * Copyright 2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_netc_soc.h"
#include "fsl_netc_phy_wrapper.h"

#define NETC_PHY_WRITE_BITS(h, p, r, m, v)            \
    {                                                 \
        status = NETC_PHYWriteRegBits(h, p, r, m, v); \
        if (status != kStatus_Success)                \
        {                                             \
            return status;                            \
        }                                             \
    }

#define NETC_PHY_READ(h, p, r, v)             \
    {                                         \
        status = NETC_PHYReadReg(h, p, r, v); \
        if (status != kStatus_Success)        \
        {                                     \
            return status;                    \
        }                                     \
    }

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
        hw->func.vf   = s_netcVfBases[siIdx - 3U];
        hw->msixTable = (netc_msix_entry_t *)((uintptr_t)hw->si + 0x60000U);
    }
}

uint32_t NETC_SocGetFuncInstance(netc_hw_eth_port_idx_t port)
{
    uint32_t instance = (uint32_t)port + 1U;

    return instance;
}

status_t NETC_PHYInit(netc_mdio_handle_t *handle, phy_mode_t mode)
{
#if !(defined(FSL_FEATURE_NETC_HAS_NO_XGMII) && FSL_FEATURE_NETC_HAS_NO_XGMII)
    uint16_t regValue;
    status_t status;

    if ((mode == kNETC_XGMII10G) || (mode == kNETC_XGMII10GAuto))
    {
        NETC_PHY_WRITE_BITS(handle, false, &ENET_PHY_MAC_ADAPTER->MAC_ADAPTER_LOCK_PHY,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_MASK,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK(0x1U));
        NETC_PHY_WRITE_BITS(handle, false, &ENET_PHY_MAC_ADAPTER->MAC_ADAPTER_LOCK_MPLLA,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_MASK,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK(0x1U));
        NETC_PHY_WRITE_BITS(handle, false, &ENET_PHY_MAC_ADAPTER->MAC_ADAPTER_LOCK_MPLLB,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_MASK,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK(0x1U));
        NETC_PHY_WRITE_BITS(handle, false, &ENET_PHY_MAC_ADAPTER->MAC_ADAPTER_LOCK_RAM,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_MASK,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK(0x1U));
        NETC_PHY_WRITE_BITS(handle, false, &ENET_PHY_MAC_ADAPTER->MAC_ADAPTER_LOCK_ROM,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_MASK,
                            ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_SRAM, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_INIT_DN_MASK;
        } while (regValue == 0x0U);
        NETC_PHY_WRITE_BITS(handle, false, &ENET_PHY_CTRL_EX->GLOBAL_CTRL_EX_0,
                            ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_MASK,
                            ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_XS_PCS_MMD->SR_XS_PCS_CTRL1, &regValue);
            regValue &= ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_MASK;
        } while (regValue != 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->SR_MII_CTRL,
                            ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK,
                            ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_GENCTRL1,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0(0x1U));
        SDK_DelayAtLeastUs(1, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_GENCTRL1,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_TX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK;
        } while (regValue != 0x0U);
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK;
        } while (regValue != 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE(0x6U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT(0x5U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_EN(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL5,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL4,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL5,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_SPD_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_SPD_EN(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_FRACN_CTRL(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER(0x21U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL(0x5U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL3,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH(0xA016U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL(0x11U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_MISC_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_SUP_MISC_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_SUP_MISC(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0(0x29U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0(0x549U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0_RX0_CDR_PPM_MAX_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0_RX0_CDR_PPM_MAX(0x12U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0_TX0_MISC_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0_TX0_MISC(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST(0xFU));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST(0x20U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN(0x20U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_POLE_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_POLE_0(0x2U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0(0x10U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL3,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0(0x7U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_RX_CDR_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_RX_CDR_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC(0x12U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_GENCTRL1,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL3,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_GENCTRL4,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA1_GAIN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA1_GAIN_0(0x5U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA2_GAIN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA2_GAIN_0(0x5U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_RX_CDR_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_GENCTRL1,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_SEL_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_SEL_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->SR_XS_PCS_CTRL2,
                            ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_MASK,
                            ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DIG_CTRL1,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_MASK,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_KR_CTRL,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_MODE_MASK,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_MODE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->SR_XS_PCS_CTRL2,
                            ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_MASK,
                            ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER(0x21U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_MPLLA_CTRL3,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH(0xA016U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0(0x549U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0(0x29U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0(0x10U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_RX_CDR_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_RX_CDR_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC(0x12U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_GENCTRL4,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_RX_CDR_CTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE(0x3U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DIG_CTRL1,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_MASK,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_SRAM, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_INIT_DN_MASK;
        } while (regValue == 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_SRAM,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_EXT_LD_DN_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_EXT_LD_DN(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DIG_CTRL1, &regValue);
            regValue &= ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_MASK;
        } while (regValue != 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_GENCTRL1,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK;
        } while (regValue != 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DEBUG_CTRL,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_MASK,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DEBUG_CTRL,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_MASK,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_RX_LSTS, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_0_MASK;
        } while (regValue == 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_MISC_STS, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_MASK;
        } while (regValue == 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ(0x0U));

        if (mode == kNETC_XGMII10GAuto)
        {
            NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->VR_MII_AN_CTRL,
                                ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK,
                                ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN(0x1U));
        }

        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->VR_MII_AN_CTRL,
                            ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_MASK,
                            ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG(0x0U));

        if (mode == kNETC_XGMII10GAuto)
        {
            NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->VR_MII_LINK_TIMER_CTRL,
                                ENET_PHY_VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK,
                                ENET_PHY_VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME(0x1U));
            NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->VR_MII_DIG_CTRL1,
                                ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_MASK,
                                ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE(0x1U));
        }

        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->SR_MII_CTRL, ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS6_MASK,
                            ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS6(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->SR_MII_CTRL, ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS13_MASK,
                            ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS13(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->SR_MII_CTRL, ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS5_MASK,
                            ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS5(0x0U));

        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DEBUG_CTRL,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_MASK,
                            ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_TX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE(0x2U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK;
        } while (regValue != 0x0U);
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK;
        } while (regValue != 0x0U);
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_TX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_TX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_GENCTRL1,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->MP_12G_16G_25G_RX_POWER_STATE_CTRL,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK,
                            ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE(0x0U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0(0x1U));
        NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK,
                            ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0(0x1U));
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_TX_GENCTRL2, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK;
        } while (regValue != 0x0U);
        do
        {
            NETC_PHY_READ(handle, true, &ENET_PHY_PMA_MMD->VR_XS_PMA_MP_12G_16G_RX_GENCTRL2, &regValue);
            regValue &= ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK;
        } while (regValue != 0x0U);

        if (mode == kNETC_XGMII10GAuto)
        {
            NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->SR_MII_CTRL,
                                ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK,
                                ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE(0x1U));
            do
            {
                NETC_PHY_READ(handle, true, &ENET_PHY_VS_MII_MMD->VR_MII_AN_INTR_STS, &regValue);
                regValue &= ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK;
            } while (regValue == 0x0U);
            do
            {
                NETC_PHY_READ(handle, true, &ENET_PHY_VS_MII_MMD->VR_MII_AN_INTR_STS, &regValue);
                regValue &= ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_MASK;
            } while (regValue != ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS(0x2FU));

            NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_VS_MII_MMD->VR_MII_AN_INTR_STS,
                                ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK,
                                ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR(0x0U));

            NETC_PHY_WRITE_BITS(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DIG_CTRL1,
                                ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_MASK,
                                ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST(0x1U));
            do
            {
                NETC_PHY_READ(handle, true, &ENET_PHY_XS_PCS_MMD->VR_XS_PCS_DIG_CTRL1, &regValue);
                regValue &= ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_MASK;
            } while (regValue != 0U);
        }
    }
    else
    {
        return kStatus_NETC_Unsupported;
    }

#endif
    return kStatus_Success;
}
