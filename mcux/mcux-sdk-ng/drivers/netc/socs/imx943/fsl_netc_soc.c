/*
 * Copyright 2024-2025 NXP
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
        hw->func.pf   = s_netcBases[1 + siIdx];
        hw->msixTable = (netc_msix_entry_t *)((uintptr_t)hw->si + 0x30000U);
    }
    else
    {
        hw->func.vf   = s_netcVfBases[siIdx - 3];
        hw->msixTable = (netc_msix_entry_t *)((uintptr_t)hw->si + 0x60000U);
    }
}

uint32_t NETC_SocGetFuncInstance(netc_hw_eth_port_idx_t port)
{
    if (port >= kNETC_SWITCH0EthPort0)
    {
        return 5U;
    }

    return ((uint32_t)port + 1U);
}

static uint32_t NETC_PHYRead(netc_mdio_handle_t *handle, uint8_t portAddr, uint8_t devAddr, uint16_t regAddr)
{
    uint16_t val = 0U;
    status_t status;

    status = NETC_MDIOC45Read(handle, portAddr, devAddr, regAddr, &val);
    if (status != kStatus_Success)
    {
        assert(false);
    }

    return val;
}

static void NETC_PHYWrite(netc_mdio_handle_t *handle, uint8_t portAddr, uint8_t devAddr, uint16_t regAddr, uint16_t val)
{
    status_t status;

    status = NETC_MDIOC45Write(handle, portAddr, devAddr, regAddr, val);
    if (status != kStatus_Success)
    {
        assert(false);
    }
}

status_t NETC_PHYInit(netc_mdio_handle_t *handle, phy_mode_t mode)
{
    static int already_done      = 0;
    static uint32_t ref_clk_init = 0;
    uint32_t value;
    uint32_t sel_mplla = 0;
    uint32_t sel_mpllb = 0;
    int portId = 0;

    if (handle->mdio.port == kNETC_SWITCH0EthPort0)
    {
        portId = 0;
        BLK_CTRL_NETCMIX->MISC_SOC_CONTROL &= 0xFFFFFFFD;
    }

    if (handle->mdio.port == kNETC_SWITCH0EthPort1)
    {
        portId = 1;
        BLK_CTRL_NETCMIX->MISC_SOC_CONTROL |= 0x2;
    }

    NETC_PHYWrite(handle, 0x10, 0x1f, 0x200 >> 1, 0x80);
    NETC_PHYWrite(handle, 0x10, 0x1f, 0x204 >> 1, 0x80);
    NETC_PHYWrite(handle, 0x10, 0x1f, 0x208 >> 1, 0x80);
    NETC_PHYWrite(handle, 0x10, 0x1f, 0x20c >> 1, 0x80);

    if (already_done == 0)
    {
        value = NETC_PHYRead(handle, 0x10, 0x01, 0x0056);
        value = ((value & 0xF0FF) | (portId << 8));
        NETC_PHYWrite(handle, 0x10, 0x01, 0x0056, value);
    }

    value = NETC_PHYRead(handle, 0x10, 0x0, 0x124 >> 1);
    value = (value | 0x0100 | 0x4000);
    NETC_PHYWrite(handle, 0x10, 0x0, 0x124 >> 1, value);

    SDK_DelayAtLeastUs(4000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    value = NETC_PHYRead(handle, 0x0, 0x1F, 0x809B);
    while ((value & 0x00000001) == 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x1F, 0x809B);
    }
    if (already_done == 0)
    {
        NETC_PHYWrite(handle, 0x10, 0x0, 0x114 >> 1, (0x101 | sel_mpllb << 7 | sel_mplla << 6));
    }

    value = NETC_PHYRead(handle, 0x0, 0x5E, 0x0);
    while ((value & 0x00008000) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x0);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x0);
    value = ((value & 0xEFFF) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x0, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8030);
    value = (value | 0x0100);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8030, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8051);
    value = (value | 0x0010);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8051, value);

    SDK_DelayAtLeastUs(1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8030);
    value = (value & 0xFEFF);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8030, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8051);
    value = (value & 0xFFEF);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8051, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8040);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8040);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8035);
    value = ((value & 0xFFFC) | 0x0003);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8035, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8070);
    value = ((value & 0xFFFE));
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8070, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8030);
    value = (value & 0xEFFF);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8030, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8060);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8060);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8050);
    value = ((value & 0xFEFF));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8050, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8055);
    value = ((value & 0xFFFC) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8055, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8055);
    value = ((value & 0xFFFC) | 0x0003);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8055, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    value = ((value & 0xFFFE) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8032, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    value = ((value & 0xFFFE) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8052, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    }

    SDK_DelayAtLeastUs(1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    value = ((value & 0xFFFE));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8032, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    value = ((value & 0xFFFE));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8052, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8040);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8040);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8060);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8060);
    }

    if (already_done == 0)
    {
        if (ref_clk_init == 0)
        {
            value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8091);
            value = ((value & 0xFF03) | 0x00F0);
            NETC_PHYWrite(handle, 0x0, 0x1F, 0x8091, value);
            ref_clk_init++;
        }

        SDK_DelayAtLeastUs(6000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8073);
        value = ((value & 0xE000) | 0x028A);
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x8073, value);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8072);
        value = ((value & 0x0));
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x8072, value);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x807A);
        value = ((value & 0x0));
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x807A, value);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8079);
        value = ((value & 0x0));
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x8079, value);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x807A);
        value = ((value & 0x0));
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x807A, value);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8072);
        value = ((value & 0x0));
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x8072, value);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8071);
        value = ((value & 0xFF00) | 0x0028);
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x8071, value);

        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8077);
        NETC_PHYWrite(handle, 0x0, 0x5F, 0x8077, 0xA017);
    }
    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8090);
    value = ((value & 0xE0FF) | 0x1100);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8090, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x809C);
    value = ((value & 0xFF00) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x809C, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8096);
    value = ((value & 0xFF80) | 0x0022);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8096, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8092);
    value = ((value & 0xE000) | 0x0550);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8092, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8065);
    value = ((value & 0xFFE0) | 0x0012);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8065, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8070);
    value = ((value & 0xFFEF));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8070, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x803E);
    value = ((value & 0xFF00) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x803E, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8034);
    value = ((value & 0xFFF8) | 0x0002);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8034, value);

    SDK_DelayAtLeastUs(1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8034);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    value = ((value & 0xFCFF) | 0x0100);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8032, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8031);
    value = ((value & 0xF8FF) | 0x0700);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8031, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8031);
    value = ((value & 0xFFEF) | 0x0010);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8031, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8033);
    value = ((value & 0xFFF0) | 0x000F);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8033, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8036);
    value = ((value & 0xFFC0));
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8036, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8037);
    value = ((value & 0xFFC0) | 0x0020);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8037, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8036);
    value = ((value & 0xC0FF) | 0x2000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8036, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8054);
    value = ((value & 0xFFFC) | 0x0002);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8054, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8058);
    value = ((value & 0xFF80) | 0x0010);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8058, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8053);
    value = ((value & 0xFFF8) | 0x0002);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8053, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8064);
    value = ((value & 0xFFEE) | 0x0010);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8064, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8069);
    value = ((value & 0xFF00) | 0x0017);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8069, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    value = ((value & 0xFCFF) | 0x0100);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8052, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8051);
    value = ((value & 0xEFFF));
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8051, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8056);
    value = ((value & 0xFFEF) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8056, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8053);
    value = ((value & 0xEFFF) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8053, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8068);
    value = ((value & 0xFEFF) | 0x0100);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8068, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8057);
    value = ((value & 0xFFF8) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8057, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8058);
    value = ((value & 0x88FF) | 0x4400);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8058, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x805E);
    value = ((value & 0xFF00) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x805E, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8064);
    value = ((value & 0xFCFF) | 0x0200);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8064, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8051);
    value = ((value & 0xFEFF) | 0x0100);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8051, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x806B);
    value = ((value & 0xF0FF) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x806B, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x805D);
    value = ((value & 0xFFCE) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x805D, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8000);
    value = ((value & 0xFFFB) | 0x0004);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8000, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x805C);
    value = ((value & 0xFFFE) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x805C, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8000);
    value = ((value & 0x7FFF) | 0x8000);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8000, value);

    value = NETC_PHYRead(handle, 0x0, 0x1F, 0x809B);
    while ((value & 0x00000001) == 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x1F, 0x809B);
    }

    SDK_DelayAtLeastUs(1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    if (already_done == 0)
    {
        NETC_PHYWrite(handle, 0x10, 0x0, 0x114 >> 1, (0x101 | sel_mpllb << 7 | sel_mplla << 6));
    }
    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8000);
    while ((value & 0x00008000) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8000);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8031);
    value = ((value & 0xEFFF) | 0x1000);
    NETC_PHYWrite(handle, 0x0, 0x1F, 0x8031, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8005);
    value = ((value & 0xFFAF));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8005, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8005);
    value = ((value & 0xFEFF) | 0x0100);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8005, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8035);
    value = ((value & 0xFFFC) | 0x0002);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8035, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8070);
    value = ((value & 0xFFFE) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8070, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    value = ((value & 0xFFFE) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8032, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    value = ((value & 0xFFFE) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8052, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    }

    SDK_DelayAtLeastUs(1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8035);
    value = ((value & 0xFFFC) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8035, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8035);
    value = ((value & 0xFEFF));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8035, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8055);
    value = ((value & 0xFEFC) | 0x0000);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8055, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8030);
    value = ((value & 0xEFFF) | 0x1000);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8030, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8050);
    value = ((value & 0xFEFF) | 0x0100);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8050, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    value = ((value & 0xFFFE) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8032, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    value = ((value & 0xFFFE) | 0x0001);
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8052, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    }

    SDK_DelayAtLeastUs(1000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8032);
    value = ((value & 0xFFFE));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8032, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8052);
    value = ((value & 0xFFFE));
    NETC_PHYWrite(handle, 0x0, 0x5F, 0x8052, value);

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8040);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8040);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8060);
    while ((value & 0x00000001) != 0)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x8060);
    }

    value = NETC_PHYRead(handle, 0x0, 0x5F, 0x1);
    while ((value & 0x00000004) != 4)
    {
        value = NETC_PHYRead(handle, 0x0, 0x5F, 0x1);
    }

    already_done = 1;

    return kStatus_Success;
}
