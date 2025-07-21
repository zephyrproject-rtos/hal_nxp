/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_phyyt8521.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Defines the YT8521 PHY vendor defined registers. */
#define PHY_SPECIFIC_STATUS_REG (0x11U) /*!< The PHY specific status register. */

/*! @brief Defines the YT8521 interrupt registers. */
#define PHY_INER_REG 0x12U /*!< Interrupt Enable Register */
#define PHY_INSR_REG 0x13U /*!< Interrupt Status Register */

/*! @brief Defines the YT8521 PHY ID number. */
#define PHY_CONTROL_ID1 (0x001CU) /*!< The PHY ID1 . */

/*! @brief Defines the mask flag in interrupt enable register. */
#define PHY_INER_LINKSTATUS_SUCCESS_MASK ((uint16_t)0x0400U) /*!< bit 10, The PHY link status success interrupt mask. */
#define PHY_INER_LINKSTATUS_FAILURE_MASK ((uint16_t)0x0800U) /*!< bit 11, The PHY link status failure interrupt mask. */

/*! @brief Defines the mask flag in specific status register. */
#define PHY_SSTATUS_LINKSTATUS_MASK ((uint16_t)0x0400U) /*!< The PHY link status mask. */
#define PHY_SSTATUS_LINKSPEED_MASK  ((uint16_t)0xC000U) /*!< bit 15:14 The PHY link speed mask. */
#define PHY_SSTATUS_LINKDUPLEX_MASK ((uint16_t)0x2000U) /*!< bit 13 The PHY link duplex mask. */
#define PHY_SSTATUS_LINKSPEED_SHIFT (14U)               /*!< The link speed shift */

/*! @brief Defines the timeout macro. */
#define PHY_READID_TIMEOUT_COUNT 1000U

/*! @brief Defines the PHY resource interface. */
#define PHY_YT8521_WRITE(handle, regAddr, data) \
    ((phy_yt8521_resource_t *)((handle)->resource))->write((handle)->phyAddr, regAddr, data)
#define PHY_YT8521_READ(handle, regAddr, pData) \
    ((phy_yt8521_resource_t *)((handle)->resource))->read((handle)->phyAddr, regAddr, pData)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

const phy_operations_t phyyt8521_ops = {.phyInit             = PHY_YT8521_Init,
                                        .phyWrite            = PHY_YT8521_Write,
                                        .phyRead             = PHY_YT8521_Read,
                                        .getAutoNegoStatus   = PHY_YT8521_GetAutoNegotiationStatus,
                                        .getLinkStatus       = PHY_YT8521_GetLinkStatus,
                                        .getLinkSpeedDuplex  = PHY_YT8521_GetLinkSpeedDuplex,
                                        .setLinkSpeedDuplex  = PHY_YT8521_SetLinkSpeedDuplex,
                                        .enableLoopback      = PHY_YT8521_EnableLoopback,
                                        .enableLinkInterrupt = PHY_YT8521_EnableLinkInterrupt,
                                        .clearInterrupt      = PHY_YT8521_ClearInterrupt};

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t PHY_YT8521_Init(phy_handle_t *handle, const phy_config_t *config)
{
    uint32_t counter  = PHY_READID_TIMEOUT_COUNT;
    uint16_t regValue = 0U;
    status_t result;

    /* Assign PHY address and operation resource. */
    handle->phyAddr  = config->phyAddr;
    handle->resource = config->resource;

    /* Check PHY ID. */
    do
    {
        result = PHY_YT8521_READ(handle, PHY_ID1_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }
        counter--;
    } while ((regValue != PHY_CONTROL_ID1) && (counter != 0U));

    if (counter == 0U)
    {
        return kStatus_Fail;
    }

    /* Reset PHY. */
    result = PHY_YT8521_WRITE(handle, PHY_BASICCONTROL_REG, PHY_BCTL_RESET_MASK);
    if (result != kStatus_Success)
    {
        return result;
    }

    do
    {
        result = PHY_YT8521_READ(handle, PHY_BASICCONTROL_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }
    } while ((regValue & PHY_BCTL_RESET_MASK) != 0U);

    if (config->autoNeg)
    {
        /* Set the auto-negotiation. */
        result = PHY_YT8521_WRITE(handle, PHY_AUTONEG_ADVERTISE_REG,
                                  PHY_100BASETX_FULLDUPLEX_MASK | PHY_100BASETX_HALFDUPLEX_MASK |
                                      PHY_10BASETX_FULLDUPLEX_MASK | PHY_10BASETX_HALFDUPLEX_MASK |
                                      PHY_IEEE802_3_SELECTOR_MASK);
        if (result == kStatus_Success)
        {
            result = PHY_YT8521_WRITE(handle, PHY_1000BASET_CONTROL_REG, PHY_1000BASET_FULLDUPLEX_MASK);
            if (result == kStatus_Success)
            {
                result = PHY_YT8521_READ(handle, PHY_BASICCONTROL_REG, &regValue);
                if (result == kStatus_Success)
                {
                    result = PHY_YT8521_WRITE(handle, PHY_BASICCONTROL_REG,
                                              (regValue | PHY_BCTL_AUTONEG_MASK | PHY_BCTL_RESTART_AUTONEG_MASK));
                }
            }
        }
    }
    else
    {
        /* Disable isolate mode */
        result = PHY_YT8521_READ(handle, PHY_BASICCONTROL_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }
        regValue &= ~PHY_BCTL_ISOLATE_MASK;
        result = PHY_YT8521_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        /* Disable the auto-negotiation and set user-defined speed/duplex configuration. */
        result = PHY_YT8521_SetLinkSpeedDuplex(handle, config->speed, config->duplex);
    }
    if (result != kStatus_Success)
    {
        return result;
    }

    result = PHY_YT8521_EnableLinkInterrupt(handle, config->intrType);
    return result;
}

status_t PHY_YT8521_Write(phy_handle_t *handle, uint8_t phyReg, uint16_t data)
{
    return PHY_YT8521_WRITE(handle, phyReg, data);
}

status_t PHY_YT8521_Read(phy_handle_t *handle, uint8_t phyReg, uint16_t *pData)
{
    return PHY_YT8521_READ(handle, phyReg, pData);
}

status_t PHY_YT8521_GetAutoNegotiationStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    status_t result;
    uint16_t regValue;

    *status = false;

    /* Check auto negotiation complete. */
    result = PHY_YT8521_READ(handle, PHY_BASICSTATUS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if ((regValue & PHY_BSTATUS_AUTONEGCOMP_MASK) != 0U)
        {
            *status = true;
        }
    }
    return result;
}

status_t PHY_YT8521_GetLinkStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    status_t result;
    uint16_t regValue;

    /* Read the basic status register. */
    result = PHY_YT8521_READ(handle, PHY_SPECIFIC_STATUS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if ((PHY_SSTATUS_LINKSTATUS_MASK & regValue) != 0U)
        {
            /* Link up. */
            *status = true;
        }
        else
        {
            /* Link down. */
            *status = false;
        }
    }
    return result;
}

status_t PHY_YT8521_GetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t *speed, phy_duplex_t *duplex)
{
    assert(!((speed == NULL) && (duplex == NULL)));

    status_t result;
    uint16_t regValue;

    /* Read the status register. */
    result = PHY_YT8521_READ(handle, PHY_SPECIFIC_STATUS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if (speed != NULL)
        {
            switch ((regValue & PHY_SSTATUS_LINKSPEED_MASK) >> PHY_SSTATUS_LINKSPEED_SHIFT)
            {
                case (uint16_t)kPHY_Speed10M:
                    *speed = kPHY_Speed10M;
                    break;
                case (uint16_t)kPHY_Speed100M:
                    *speed = kPHY_Speed100M;
                    break;
                case (uint16_t)kPHY_Speed1000M:
                    *speed = kPHY_Speed1000M;
                    break;
                default:
                    *speed = kPHY_Speed10M;
                    break;
            }
        }

        if (duplex != NULL)
        {
            if ((regValue & PHY_SSTATUS_LINKDUPLEX_MASK) != 0U)
            {
                *duplex = kPHY_FullDuplex;
            }
            else
            {
                *duplex = kPHY_HalfDuplex;
            }
        }
    }
    return result;
}

status_t PHY_YT8521_SetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t speed, phy_duplex_t duplex)
{
    status_t result;
    uint16_t regValue;

    result = PHY_YT8521_READ(handle, PHY_BASICCONTROL_REG, &regValue);
    if (result == kStatus_Success)
    {
        /* Disable the auto-negotiation and set according to user-defined configuration. */
        regValue &= ~PHY_BCTL_AUTONEG_MASK;
        if (speed == kPHY_Speed1000M)
        {
            regValue &= PHY_BCTL_SPEED0_MASK;
            regValue |= PHY_BCTL_SPEED1_MASK;
        }
        else if (speed == kPHY_Speed100M)
        {
            regValue |= PHY_BCTL_SPEED0_MASK;
            regValue &= ~PHY_BCTL_SPEED1_MASK;
        }
        else
        {
            regValue &= ~PHY_BCTL_SPEED0_MASK;
            regValue &= ~PHY_BCTL_SPEED1_MASK;
        }
        if (duplex == kPHY_FullDuplex)
        {
            regValue |= PHY_BCTL_DUPLEX_MASK;
        }
        else
        {
            regValue &= ~PHY_BCTL_DUPLEX_MASK;
        }
        result = PHY_YT8521_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
    }
    return result;
}

status_t PHY_YT8521_EnableLoopback(phy_handle_t *handle, phy_loop_t mode, phy_speed_t speed, bool enable)
{
    /* This PHY only supports local loopback. */
    assert(mode == kPHY_LocalLoop);

    status_t result;
    uint16_t regValue;

    /* Set the loop mode. */
    if (enable)
    {
        if (speed == kPHY_Speed1000M)
        {
            regValue = PHY_BCTL_SPEED1_MASK | PHY_BCTL_DUPLEX_MASK | PHY_BCTL_LOOP_MASK;
        }
        else if (speed == kPHY_Speed100M)
        {
            regValue = PHY_BCTL_SPEED0_MASK | PHY_BCTL_DUPLEX_MASK | PHY_BCTL_LOOP_MASK;
        }
        else
        {
            regValue = PHY_BCTL_DUPLEX_MASK | PHY_BCTL_LOOP_MASK;
        }
        result = PHY_YT8521_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
    }
    else
    {
        /* First read the current status in control register. */
        result = PHY_YT8521_READ(handle, PHY_BASICCONTROL_REG, &regValue);
        if (result == kStatus_Success)
        {
            regValue &= ~PHY_BCTL_LOOP_MASK;
            result = PHY_YT8521_WRITE(handle, PHY_BASICCONTROL_REG, (regValue | PHY_BCTL_RESTART_AUTONEG_MASK));
        }
    }
    return result;
}

status_t PHY_YT8521_EnableLinkInterrupt(phy_handle_t *handle, phy_interrupt_type_t type)
{
    assert(type != kPHY_IntrActiveHigh);

    status_t result;
    uint16_t regValue;

    /* Read operation will clear pending interrupt before enable interrupt. */
    result = PHY_YT8521_READ(handle, PHY_INER_REG, &regValue);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Enable/Disable link up+down interrupt. */
    if (type == kPHY_IntrActiveLow)
    {
        regValue |= PHY_INER_LINKSTATUS_SUCCESS_MASK | PHY_INER_LINKSTATUS_FAILURE_MASK;
    }
    else if (type == kPHY_IntrActiveHigh)
    {
        return kStatus_InvalidArgument;
    }
    else
    {
        regValue &= ~(PHY_INER_LINKSTATUS_SUCCESS_MASK | PHY_INER_LINKSTATUS_FAILURE_MASK);
    }
    result = PHY_YT8521_WRITE(handle, PHY_INER_REG, regValue);

    return result;
}

status_t PHY_YT8521_ClearInterrupt(phy_handle_t *handle)
{
    uint16_t regValue;
    /* Just Read Interrupt Status Register(0x13) to clear interrupt status. */
    return PHY_YT8521_READ(handle, PHY_INSR_REG, &regValue);
}
