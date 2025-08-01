/*
 * Copyright 2020-2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_phytja1100.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define TJA1100_ECTRL             (17U)
#define TJA1100_ECTRL_CONFEN      ((uint16_t)(1U<<2))
#define TJA1100_ECTRL_LOOP_INT    ((uint16_t)(0U<<3))
#define TJA1100_ECTRL_LOOP_EXT    ((uint16_t)(1U<<3))
#define TJA1100_ECTRL_LOOP_EXT2   ((uint16_t)(2U<<3))
#define TJA1100_ECTRL_LOOP_REMOTE ((uint16_t)(3U<<3))

#define TJA1100_CONF1              (18U)
#define TJA1100_CONF1_MASTER       ((uint16_t)(1U<<15))
#define TJA1100_CONF1_SLAVE        ((uint16_t)(0U<<15))
#define TJA1100_CONF1_AUTOOP       ((uint16_t)(1U<<14))
#define TJA1100_CONF1_MANAGED      ((uint16_t)(0U<<14))
#define TJA1100_CONF1_TXAMP_0V5    ((uint16_t)(0U<<10))
#define TJA1100_CONF1_TXAMP_0V75   ((uint16_t)(1U<<10))
#define TJA1100_CONF1_TXAMP_1V0    ((uint16_t)(2U<<10))
#define TJA1100_CONF1_TXAMP_1V25   ((uint16_t)(3U<<10))
#define TJA1100_CONF1_MII          ((uint16_t)(0U<<8))
#define TJA1100_CONF1_RMII50RCLK   ((uint16_t)(1U<<8))
#define TJA1100_CONF1_RMII25XTAL   ((uint16_t)(2U<<8))
#define TJA1100_CONF1_REVMII       ((uint16_t)(3U<<8))
#define TJA1100_CONF1_DRV_STANDARD ((uint16_t)(0U<<7))
#define TJA1100_CONF1_DRV_REDUCED  ((uint16_t)(1U<<7))
#define TJA1100_CONF1_LED_LINKUP   ((uint16_t)(0U<<4))
#define TJA1100_CONF1_LED_RX       ((uint16_t)(1U<<4))
#define TJA1100_CONF1_LED_SERR     ((uint16_t)(2U<<4))
#define TJA1100_CONF1_LED_CRS      ((uint16_t)(3U<<4))
#define TJA1100_CONF1_LED_ENABLED  ((uint16_t)(1U<<3))
#define TJA1100_CONF1_LED_DISABLED ((uint16_t)(0U<<3))
#define TJA1100_CONF1_WAKE_RATIO   ((uint16_t)(1U<<2))
#define TJA1100_CONF1_WAKE_ABS     ((uint16_t)(0U<<2))
#define TJA1100_CONF1_AUTOPWD_EN   ((uint16_t)(1U<<0))
#define TJA1100_CONF1_AUTOPWD_DIS  ((uint16_t)(0U<<0))

#define TJA1100_CONF2                       (19U)
#define TJA1100_INT_STAT                    (21U)
#define TJA1100_INT_ENABLE                  (22U)
#define TJA1100_INT_ENABLE_LINK_STATUS_FAIL ((uint16_t)(1U << 10))
#define TJA1100_INT_ENABLE_LINK_STATUS_UP   ((uint16_t)(1U << 9))

#define PHY_READID_TIMEOUT_COUNT (1000U)
#define PHY_CONTROL_ID1          ((uint16_t)0x0180U)

/*! @brief Defines the PHY resource interface. */
#define PHY_TJA1100_WRITE(handle, regAddr, data) \
    ((phy_tja1100_resource_t *)(handle)->resource)->write((handle)->phyAddr, regAddr, data)
#define PHY_TJA1100_READ(handle, regAddr, pData) \
    ((phy_tja1100_resource_t *)(handle)->resource)->read((handle)->phyAddr, regAddr, pData)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

const phy_operations_t phytja1100_ops = {.phyInit             = PHY_TJA1100_Init,
                                         .phyWrite            = PHY_TJA1100_Write,
                                         .phyRead             = PHY_TJA1100_Read,
                                         .getAutoNegoStatus   = PHY_TJA1100_GetAutoNegotiationStatus,
                                         .getLinkStatus       = PHY_TJA1100_GetLinkStatus,
                                         .getLinkSpeedDuplex  = PHY_TJA1100_GetLinkSpeedDuplex,
                                         .setLinkSpeedDuplex  = PHY_TJA1100_SetLinkSpeedDuplex,
                                         .enableLoopback      = PHY_TJA1100_EnableLoopback,
                                         .enableLinkInterrupt = PHY_TJA1100_EnableLinkInterrupt,
                                         .clearInterrupt      = PHY_TJA1100_ClearInterrupt};

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t PHY_TJA1100_Init(phy_handle_t *handle, const phy_config_t *config)
{
    assert(config != NULL);
    assert(config->speed == kPHY_Speed100M);
    assert(config->duplex == kPHY_FullDuplex);
    assert(config->autoNeg == false);
    assert(config->enableEEE == false);
    assert((config->intrType == kPHY_IntrDisable) || (config->intrType == kPHY_IntrActiveLow));

    uint32_t counter = PHY_READID_TIMEOUT_COUNT;
    status_t result;
    uint16_t reg;

    if ((config == NULL) ||
        (config->speed != kPHY_Speed100M) ||
        (config->duplex != kPHY_FullDuplex) ||
        (config->autoNeg != false) ||
        (config->enableEEE != false) ||
        ((config->intrType != kPHY_IntrDisable) &&
         (config->intrType != kPHY_IntrActiveLow)))
    {
        return kStatus_InvalidArgument;
    }

    /* Assign PHY address and operation resource. */
    handle->phyAddr  = config->phyAddr;
    handle->resource = config->resource;

    /* Check PHY ID. */
    do
    {
        result = PHY_TJA1100_READ(handle, PHY_ID1_REG, &reg);
        if (result != kStatus_Success)
        {
            return result;
        }
        counter--;
    } while ((reg != PHY_CONTROL_ID1) && (counter != 0U));

    if (counter == 0U)
    {
        return kStatus_Fail;
    }

    /* Allow configuration changes. */
    result = PHY_TJA1100_READ(handle, TJA1100_ECTRL, &reg);
    if (result != kStatus_Success)
    {
        return result;
    }

    reg |= TJA1100_ECTRL_CONFEN;

    result = PHY_TJA1100_WRITE(handle, TJA1100_ECTRL, reg);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Soft-reset + power-down. */
    result = PHY_TJA1100_WRITE(handle, PHY_BASICCONTROL_REG, PHY_BCTL_RESET_MASK | PHY_BCTL_POWER_DOWN_MASK);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Wait for soft-reset to finish. */
    do
    {
        result = PHY_TJA1100_READ(handle, PHY_BASICCONTROL_REG, &reg);
        if (result != kStatus_Success)
        {
            return result;
        }
    } while (reg & PHY_BCTL_RESET_MASK);

    /* Apply configuration. */
    reg = TJA1100_CONF1_AUTOOP |
          TJA1100_CONF1_TXAMP_1V0 |
          TJA1100_CONF1_RMII50RCLK |
          TJA1100_CONF1_LED_LINKUP |
          TJA1100_CONF1_LED_ENABLED;

    if (config->master)
    {
        reg |= TJA1100_CONF1_MASTER;
    }

    result = PHY_TJA1100_WRITE(handle, TJA1100_CONF1, reg);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Power-up. */
    result = PHY_TJA1100_READ(handle, PHY_BASICCONTROL_REG, &reg);
    if (result != kStatus_Success)
    {
        return result;
    }

    reg &= ~PHY_BCTL_POWER_DOWN_MASK;
    result = PHY_TJA1100_WRITE(handle, PHY_BASICCONTROL_REG, reg);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Enable/disable link status interrupt if needed. */
    return PHY_TJA1100_EnableLinkInterrupt(handle, config->intrType);
}

status_t PHY_TJA1100_Write(phy_handle_t *handle, uint8_t phyReg, uint16_t data)
{
    return PHY_TJA1100_WRITE(handle, phyReg, data);
}

status_t PHY_TJA1100_Read(phy_handle_t *handle, uint8_t phyReg, uint16_t *pData)
{
    return PHY_TJA1100_READ(handle, phyReg, pData);
}

status_t PHY_TJA1100_GetAutoNegotiationStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    if (status == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /*
     * Auto-negotiation is not supported in 100BASE-T1, but the AUTONEG_COMPLETE
     * bit of status register defaults to 1, so treat it as "complete".
     */
    *status = true;

    return kStatus_Success;
}

status_t PHY_TJA1100_GetLinkStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    status_t result;
    uint16_t reg;

    if (status == NULL)
    {
        return kStatus_InvalidArgument;
    }

    result = PHY_TJA1100_READ(handle, PHY_BASICSTATUS_REG, &reg);
    if (result != kStatus_Success)
    {
        return result;
    }

    if (reg & PHY_BSTATUS_LINKSTATUS_MASK)
    {
        *status = true;
    }
    else
    {
        *status = false;
    }

    return result;
}

status_t PHY_TJA1100_GetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t *speed, phy_duplex_t *duplex)
{
    assert(!((speed == NULL) && (duplex == NULL)));

    if ((speed == NULL) && (duplex == NULL))
    {
        return kStatus_InvalidArgument;
    }

    /* No need to read settings, speed and duplex is fixed on this PHY. */

    if (speed != NULL)
    {
        *speed = kPHY_Speed100M;
    }

    if (duplex != NULL)
    {
        *duplex = kPHY_FullDuplex;
    }

    return kStatus_Success;
}

status_t PHY_TJA1100_SetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t speed, phy_duplex_t duplex)
{
    assert(speed == kPHY_Speed100M);
    assert(duplex == kPHY_FullDuplex);

    if ((speed != kPHY_Speed100M) || (duplex != kPHY_FullDuplex))
    {
        return kStatus_InvalidArgument;
    }

    /* No need to write settings, speed and duplex is fixed on this PHY. */

    return kStatus_Success;
}

status_t PHY_TJA1100_EnableLoopback(phy_handle_t *handle, phy_loop_t mode, phy_speed_t speed, bool enable)
{
    status_t result;
    uint16_t bctrl;
    uint16_t ectrl;

    result = PHY_TJA1100_READ(handle, PHY_BASICCONTROL_REG, &bctrl);
    if (result != kStatus_Success)
    {
        return result;
    }

    result = PHY_TJA1100_READ(handle, TJA1100_ECTRL, &ectrl);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Disable loopback. */
    ectrl &= ~TJA1100_ECTRL_LOOP_REMOTE;
    bctrl &= ~PHY_BCTL_LOOP_MASK;

    if (enable)
    {
        bctrl |= PHY_BCTL_LOOP_MASK;

        switch (mode)
        {
        case kPHY_LocalLoop:
            ectrl |= TJA1100_ECTRL_LOOP_INT;
            break;
        case kPHY_ExternalLoop:
            ectrl |= TJA1100_ECTRL_LOOP_EXT;
            break;
        case kPHY_RemoteLoop:
            ectrl |= TJA1100_ECTRL_LOOP_REMOTE;
            break;
        default:
            return kStatus_InvalidArgument;
        }
    }

    result = PHY_TJA1100_WRITE(handle, TJA1100_ECTRL, ectrl);
    if (result != kStatus_Success)
    {
        return result;
    }

    return PHY_TJA1100_WRITE(handle, PHY_BASICCONTROL_REG, bctrl);
}

status_t PHY_TJA1100_EnableLinkInterrupt(phy_handle_t *handle, phy_interrupt_type_t type)
{
    assert((type == kPHY_IntrDisable) || (type == kPHY_IntrActiveLow));

    status_t result;
    uint16_t reg;

    /* Clear interrupt status. */
    result = PHY_TJA1100_READ(handle, TJA1100_INT_STAT, &reg);
    if (result != kStatus_Success)
    {
        return result;
    }

    if (type == kPHY_IntrDisable)
    {
        reg = 0U;
    }
    else if (type == kPHY_IntrActiveLow)
    {
        reg = TJA1100_INT_ENABLE_LINK_STATUS_FAIL | TJA1100_INT_ENABLE_LINK_STATUS_UP;
    }
    else
    {
        return kStatus_InvalidArgument;
    }

    /* Enable/disable link status interrupts. */
    return PHY_TJA1100_WRITE(handle, TJA1100_INT_ENABLE, reg);
}

status_t PHY_TJA1100_ClearInterrupt(phy_handle_t *handle)
{
    uint16_t reg;

    return PHY_TJA1100_READ(handle, TJA1100_INT_STAT, &reg);
}
