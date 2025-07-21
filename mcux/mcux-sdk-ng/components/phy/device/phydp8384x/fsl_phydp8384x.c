/*
 * Copyright 2020-2021,2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_phydp8384x.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Defines the PHY DP8384X vendor defined registers. */
#define PHYSTS_REG (0x10) /*!< The PHY status register. */
#define MICR_REG   (0x11) /*!< The MII interrupt control register. */
#define MISR_REG   (0x12) /*!< The MII interrupt status register. */

/*! @brief Defines the mask flag in PHYSTS register. */
#define PHYSTS_SPEED_MASK  ((uint16_t)0x0002U) /*!< The PHY speed mask. */
#define PHYSTS_DUPLEX_MASK ((uint16_t)0x0004U) /*!< The PHY duplex mask. */

/*! @brief Defines the mask flag in MII interrupt control register. */
#define MICR_INT_OE_MASK ((uint16_t)0x0001U) /*!< The interrupt output enable mask. */
#define MICR_INTEN_MASK  ((uint16_t)0x0002U) /*!< The interrupt enable mask. */

/*! @brief Defines the mask flag in MII interrupt status and event control register. */
#define MISR_ANC_INT_EN_MASK  ((uint16_t)0x0004U) /*!< The enable interrupt on auto-negotiation complete event mask. */
#define MISR_DUP_INT_EN_MASK  ((uint16_t)0x0008U) /*!< The enable interrupt on change of duplex status mask. */
#define MISR_SPD_INT_EN_MASK  ((uint16_t)0x0010U) /*!< The enable interrupt on change of speed status mask. */
#define MISR_LINK_INT_EN_MASK ((uint16_t)0x0020U) /*!< The enable interrupt on change of link status mask. */

/*! @brief Defines the PHY DP8384X ID number. */
#define PHY_CONTROL_ID1 (0x2000U) /*!< The PHY ID1. */

/*! @brief Defines the timeout macro. */
#define PHY_READID_TIMEOUT_COUNT (1000U)

/*! @brief Defines the PHY resource interface. */
#define PHY_DP8384X_WRITE(handle, regAddr, data) \
    (((phy_dp8384x_resource_t *)(handle)->resource)->write((handle)->phyAddr, regAddr, data))
#define PHY_DP8384X_READ(handle, regAddr, pData) \
    (((phy_dp8384x_resource_t *)(handle)->resource)->read((handle)->phyAddr, regAddr, pData))

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
const phy_operations_t phydp8384x_ops = {.phyInit             = PHY_DP8384X_Init,
                                         .phyWrite            = PHY_DP8384X_Write,
                                         .phyRead             = PHY_DP8384X_Read,
                                         .phyWriteC45         = NULL,
                                         .phyReadC45          = NULL,
                                         .getAutoNegoStatus   = PHY_DP8384X_GetAutoNegotiationStatus,
                                         .getLinkStatus       = PHY_DP8384X_GetLinkStatus,
                                         .getLinkSpeedDuplex  = PHY_DP8384X_GetLinkSpeedDuplex,
                                         .setLinkSpeedDuplex  = PHY_DP8384X_SetLinkSpeedDuplex,
                                         .enableLoopback      = PHY_DP8384X_EnableLoopback,
                                         .enableLinkInterrupt = PHY_DP8384X_EnableLinkInterrupt,
                                         .clearInterrupt      = PHY_DP8384X_ClearInterrupt};

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t PHY_DP8384X_Init(phy_handle_t *handle, const phy_config_t *config)
{
    uint32_t counter = PHY_READID_TIMEOUT_COUNT;
    status_t result  = kStatus_Success;
    phy_dp8384x_resource_t *resource;
    uint16_t regValue;

    assert(handle != NULL);
    assert(config != NULL);
    assert(config->resource != NULL);
    assert(config->ops != NULL);

    if ((handle == NULL) ||
        (config == NULL) ||
        (config->resource == NULL) ||
        (config->ops == NULL))
    {
        return kStatus_Fail;
    }

    resource = (phy_dp8384x_resource_t *)config->resource;
    assert((resource->read != NULL) && (resource->write != NULL));
    if ((resource->read == NULL) || (resource->write == NULL))
    {
        return kStatus_Fail;
    }

    /* Assign PHY address and operation resource. */
    handle->phyAddr = config->phyAddr;
    handle->resource = config->resource;

    /* Check PHY ID. */
    do
    {
        result = PHY_DP8384X_READ(handle, PHY_ID1_REG, &regValue);
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
    result = PHY_DP8384X_WRITE(handle, PHY_BASICCONTROL_REG, PHY_BCTL_RESET_MASK);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Wait for reset to complete. */
    do
    {
        result = PHY_DP8384X_READ(handle, PHY_BASICCONTROL_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }
    } while ((regValue & PHY_BCTL_RESET_MASK) != 0U);

    if (config->autoNeg)
    {
        /* Set the negotiation. */
        result = PHY_DP8384X_WRITE(handle, PHY_AUTONEG_ADVERTISE_REG,
                       (PHY_100BASETX_FULLDUPLEX_MASK | PHY_100BASETX_HALFDUPLEX_MASK |
                        PHY_10BASETX_FULLDUPLEX_MASK | PHY_10BASETX_HALFDUPLEX_MASK | PHY_IEEE802_3_SELECTOR_MASK));
        if (result == kStatus_Success)
        {
            result = PHY_DP8384X_WRITE(handle, PHY_BASICCONTROL_REG,
                                (PHY_BCTL_AUTONEG_MASK | PHY_BCTL_RESTART_AUTONEG_MASK));
        }
    }
    else
    {
        /* This PHY only supports 10/100M speed. */
        assert(config->speed <= kPHY_Speed100M);
        if (config->speed > kPHY_Speed100M)
        {
            return kStatus_Fail;
        }

        /* Disable isolate mode */
        result = PHY_DP8384X_READ(handle, PHY_BASICCONTROL_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }
        regValue &= ~PHY_BCTL_ISOLATE_MASK;
        result = PHY_DP8384X_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        /* Disable the auto-negotiation and set user-defined speed/duplex configuration. */
        result = PHY_DP8384X_SetLinkSpeedDuplex(handle, config->speed, config->duplex);
    }

    /* Set PHY link status management interrupt. */
    result = PHY_DP8384X_EnableLinkInterrupt(handle, config->intrType);

    return result;
}

status_t PHY_DP8384X_Write(phy_handle_t *handle, uint8_t phyReg, uint16_t data)
{
    return PHY_DP8384X_WRITE(handle, phyReg, data);
}

status_t PHY_DP8384X_Read(phy_handle_t *handle, uint8_t phyReg, uint16_t *pData)
{
    return PHY_DP8384X_READ(handle, phyReg, pData);
}

status_t PHY_DP8384X_GetAutoNegotiationStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    status_t result;
    uint16_t regValue;

    if (status == NULL)
    {
        return kStatus_Fail;
    }

    *status = false;

    /* Check auto negotiation complete. */
    result = PHY_DP8384X_READ(handle, PHY_BASICSTATUS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if ((regValue & PHY_BSTATUS_AUTONEGCOMP_MASK) != 0U)
        {
            *status = true;
        }
    }
    return result;
}

status_t PHY_DP8384X_GetLinkStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    status_t result;
    uint16_t regValue;

    if (status == NULL)
    {
        return kStatus_Fail;
    }

    /* Read the basic status register. */
    result = PHY_DP8384X_READ(handle, PHY_BASICSTATUS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if ((PHY_BSTATUS_LINKSTATUS_MASK & regValue) != 0U)
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

status_t PHY_DP8384X_GetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t *speed, phy_duplex_t *duplex)
{
    assert(!((speed == NULL) && (duplex == NULL)));

    status_t result;
    uint16_t regValue;

    /* Read the status register. */
    result = PHY_DP8384X_READ(handle, PHYSTS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if (speed != NULL)
        {
            if ((regValue & PHYSTS_SPEED_MASK) != 0U)
            {
                *speed = kPHY_Speed10M;
            }
            else
            {
                *speed = kPHY_Speed100M;
            }
        }

        if (duplex != NULL)
        {
            if ((regValue & PHYSTS_DUPLEX_MASK) != 0U)
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

status_t PHY_DP8384X_SetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t speed, phy_duplex_t duplex)
{
    /* This PHY only supports 10/100M speed. */
    assert(speed <= kPHY_Speed100M);

    status_t result;
    uint16_t regValue;

    if (speed > kPHY_Speed100M)
    {
        return kStatus_Fail;
    }

    result = PHY_DP8384X_READ(handle, PHY_BASICCONTROL_REG, &regValue);
    if (result == kStatus_Success)
    {
        /* Disable the auto-negotiation and set according to user-defined configuration. */
        regValue &= ~PHY_BCTL_AUTONEG_MASK;
        if (speed == kPHY_Speed100M)
        {
            regValue |= PHY_BCTL_SPEED0_MASK;
        }
        else
        {
            regValue &= ~PHY_BCTL_SPEED0_MASK;
        }
        if (duplex == kPHY_FullDuplex)
        {
            regValue |= PHY_BCTL_DUPLEX_MASK;
        }
        else
        {
            regValue &= ~PHY_BCTL_DUPLEX_MASK;
        }
        result = PHY_DP8384X_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
    }
    return result;
}

status_t PHY_DP8384X_EnableLoopback(phy_handle_t *handle, phy_loop_t mode, phy_speed_t speed, bool enable)
{
    /* This PHY only supports local loopback and 10/100M speed. */
    assert(mode == kPHY_LocalLoop);
    assert(speed <= kPHY_Speed100M);

    status_t result;
    uint16_t regValue;

    if (mode != kPHY_LocalLoop)
    {
        return kStatus_Fail;
    }

    if (enable)
    {
        /* Set the loop mode. */
        if (speed == kPHY_Speed100M)
        {
            regValue = PHY_BCTL_SPEED0_MASK | PHY_BCTL_DUPLEX_MASK | PHY_BCTL_LOOP_MASK;
        }
        else
        {
            regValue = PHY_BCTL_DUPLEX_MASK | PHY_BCTL_LOOP_MASK;
        }
        result = PHY_DP8384X_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        /* Wait for loop link status. */
        do
        {
            result = PHY_DP8384X_READ(handle, PHY_BASICSTATUS_REG, &regValue);
            if (result != kStatus_Success)
            {
                return result;
            }
        } while ((regValue & PHY_BSTATUS_LINKSTATUS_MASK) == 0U);
    }
    else
    {
        /* Disable the loop mode. */
        result = PHY_DP8384X_READ(handle, PHY_BASICCONTROL_REG, &regValue);
        if (result == kStatus_Success)
        {
            regValue &= ~PHY_BCTL_LOOP_MASK;
            result = PHY_DP8384X_WRITE(handle, PHY_BASICCONTROL_REG,
                                (regValue | PHY_BCTL_RESTART_AUTONEG_MASK));
        }
    }
    return result;
}

status_t PHY_DP8384X_EnableLinkInterrupt(phy_handle_t *handle, phy_interrupt_type_t type)
{
    assert((type == kPHY_IntrDisable) || (type == kPHY_IntrActiveLow));

    status_t result;
    uint16_t regValue;

    if ((type != kPHY_IntrDisable) && (type != kPHY_IntrActiveLow))
    {
        return kStatus_Fail;
    }

    result = PHY_DP8384X_READ(handle, MICR_REG, &regValue);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Enable/disable link interrupts. */
    if (type == kPHY_IntrDisable)
    {
        regValue &= ~MICR_INTEN_MASK;

        result = PHY_DP8384X_WRITE(handle, MICR_REG, regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        result = PHY_DP8384X_ClearInterrupt(handle);
    }
    else
    {
        result = PHY_DP8384X_ClearInterrupt(handle);
        if (result != kStatus_Success)
        {
            return result;
        }

        result = PHY_DP8384X_WRITE(handle, MISR_REG, MISR_ANC_INT_EN_MASK |
                                                     MISR_DUP_INT_EN_MASK |
                                                     MISR_SPD_INT_EN_MASK |
                                                     MISR_LINK_INT_EN_MASK);

        regValue |= (MICR_INT_OE_MASK | MICR_INTEN_MASK);

        result = PHY_DP8384X_WRITE(handle, MICR_REG, regValue);
    }

    return result;
}

status_t PHY_DP8384X_ClearInterrupt(phy_handle_t *handle)
{
    uint16_t regValue;

    return PHY_DP8384X_READ(handle, MISR_REG, &regValue);
}
