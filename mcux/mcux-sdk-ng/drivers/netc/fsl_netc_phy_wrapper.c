/*
 * Copyright 2023, 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_netc_phy_wrapper.h"

status_t NETC_PHYRead(netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t *val)
{
    uint8_t portAddr = pcs ? 0x0U : 0x10U;

    return NETC_MDIOC45Read(handle, portAddr, devAddr, (regAddr >> 1U), val);
}

status_t NETC_PHYWrite(netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t val)
{
    uint8_t portAddr = pcs ? 0x0U : 0x10U;

    return NETC_MDIOC45Write(handle, portAddr, devAddr, (regAddr >> 1U), val);
}

status_t NETC_PHYWriteBits(
    netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t mask, uint16_t val)
{
    uint8_t portAddr = pcs ? 0x0U : 0x10U;
    uint16_t regValue;
    status_t status;

    status = NETC_MDIOC45Read(handle, portAddr, devAddr, (regAddr >> 1U), &regValue);
    if (status != kStatus_Success)
    {
        return status;
    }

    regValue &= ~mask;
    val &= mask;
    if (val != 0U)
    {
        regValue |= val;
    }

    return NETC_MDIOC45Write(handle, portAddr, devAddr, (regAddr >> 1U), regValue);
}

status_t NETC_PHYPollBit(
    netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t mask, uint16_t is_set)
{
    uint16_t regValue;
    status_t status;

    do
    {
        status = NETC_PHYRead(handle, pcs, devAddr, regAddr, &regValue);
        if (status != kStatus_Success)
        {
            return status;
        }
        regValue &= mask;
    } while (regValue != (is_set == 1U ? mask : 0U));

    return kStatus_Success;
}

status_t NETC_PHYWriteRegBits(netc_mdio_handle_t *handle, bool pcs, volatile uint16_t *reg, uint16_t mask, uint16_t val)
{
    uint8_t portAddr = pcs ? 0x0U : 0x10U;
    uint8_t devAddr  = getPhyDev(reg);
    uint16_t regAddr = getPhyReg(reg);
    uint16_t regValue;
    status_t status;

    status = NETC_MDIOC45Read(handle, portAddr, devAddr, regAddr, &regValue);
    if (status != kStatus_Success)
    {
        return status;
    }

    regValue &= ~mask;
    if (val != 0U)
    {
        regValue |= val;
    }

    return NETC_MDIOC45Write(handle, portAddr, devAddr, regAddr, regValue);
}

status_t NETC_PHYReadReg(netc_mdio_handle_t *handle, bool pcs, const volatile uint16_t *reg, uint16_t *val)
{
    uint8_t portAddr = pcs ? 0x0U : 0x10U;
    uint8_t devAddr  = getPhyDev(reg);
    uint16_t regAddr = getPhyReg(reg);

    return NETC_MDIOC45Read(handle, portAddr, devAddr, regAddr, val);
}
