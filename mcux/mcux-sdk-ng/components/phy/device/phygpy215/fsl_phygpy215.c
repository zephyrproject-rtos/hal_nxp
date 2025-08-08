/*
 * Copyright 2020-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_phygpy215.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Defines the PHY GPY215 vendor defined registers. */
#define PHY_MIISTAT_REG (0x18U) /*!< The PHY media-independent interface status register (0.24). */
#define PHY_IMASK_REG   (0x19U) /*!< The PHY interrupt mask register (0.25). */
#define PHY_ISTAT_REG   (0x1AU) /*!< The PHY interrupt status register (0.26). */

/*! @brief Defines the PHY GPY215 PMA/PMD registers. */
#define PMA_CTRL1_REG (0x0U) /*!< The PMA/PMD control 1 register (1.0). */
#define PMA_CTRL2_REG (0x7U) /*!< The PMA/PMD control 2 register (1.7). */

/*! @brief Defines the PHY GPY215 auto-negotiation registers. */
#define ANEG_CTRL_REG        (0x00U) /*!< The auto-negotiation control register (7.0). */
#define ANEG_EEE_AN_ADV1_REG (0x3CU) /*!< The EEE advertisement 1 register (7.60). */
#define ANEG_EEE_AN_ADV2_REG (0x3EU) /*!< The EEE advertisement 2 register (7.62). */

/*! @brief Defines the mask flags in STD_CTRL register (0.0). */
#define STD_CTRL_DPLX_MASK ((uint16_t)0x0100U) /*!< The forced duplex mode mask. */
#define STD_CTRL_ANRS_MASK ((uint16_t)0x0200U) /*!< The restart auto-negotiation mask. */
#define STD_CTRL_LB_MASK   ((uint16_t)0x4000U) /*!< The loop-back on GMII mask. */
#define STD_CTRL_RST_MASK  ((uint16_t)0x8000U) /*!< The reset mask. */

/*! @brief Defines the mask flags in MIISTAT register (0.24). */
#define PHY_MIISTAT_SPEED_MASK  ((uint16_t)0x0007U) /*!< The GPY Ethernet PHY speed mask. */
#define PHY_MIISTAT_SPEED_TEN   ((uint16_t)0x0000U) /*!< The 10 Mb/s mask. */
#define PHY_MIISTAT_SPEED_FAST  ((uint16_t)0x0001U) /*!< The 100 Mbit/s mask. */
#define PHY_MIISTAT_SPEED_GIGA  ((uint16_t)0x0002U) /*!< The 1000 Mbit/s mask. */
#define PHY_MIISTAT_SPEED_ANEG  ((uint16_t)0x0003U) /*!< The autonegotiation mode mask. */
#define PHY_MIISTAT_SPEED_BZ2G5 ((uint16_t)0x0004U) /*!< The 2.5GBit/s mask. */
#define PHY_MIISTAT_DPX_MASK    ((uint16_t)0x0008U) /*!< The GPY Ethernet PHY duplex mode mask. */

/*! @brief Defines the mask flags in IMASK register (0.25). */
#define PHY_IMASK_ANC_MASK  ((uint16_t)0x0400U) /*!< The auto-negotiation complete mask. */
#define PHY_IMASK_ADSC_MASK ((uint16_t)0x0020U) /*!< The link speed auto-downspeed detect mask. */
#define PHY_IMASK_DXMC_MASK ((uint16_t)0x0004U) /*!< The duplex mode change mask. */
#define PHY_IMASK_LSPC_MASK ((uint16_t)0x0002U) /*!< The link speed change mask. */
#define PHY_IMASK_LSTC_MASK ((uint16_t)0x0001U) /*!< The link state change mask. */

/*! @brief Defines the mask flags in PMA_CTRL1 register (1.0). */
#define PMA_CTRL1_SPEED_MASK  ((uint16_t)0x207CU) /*!< The SSL, SSM and SPEED_SEL fields mask. */
#define PMA_CTRL1_SPEED_10M   ((uint16_t)0x0000U) /*!< The 10 Mb/s mask. */
#define PMA_CTRL1_SPEED_100M  ((uint16_t)0x2000U) /*!< The 100 Mb/s mask. */
#define PMA_CTRL1_SPEED_1000M ((uint16_t)0x0040U) /*!< The 1000 Mb/s mask. */
#define PMA_CTRL1_SPEED_2500M ((uint16_t)0x2058U) /*!< The 2.5 Gb/s mask. */

/*! @brief Defines the mask flags in PMA_CTRL2 register (1.7). */
#define PMA_CTRL2_TYPE_SEL_MASK        ((uint16_t)0x003FU) /*!< The PMA/PMD type selection mask. */
#define PMA_CTRL2_TYPE_SEL_MASK_1000BT ((uint16_t)0x000CU) /*!< The 1000BASE-T type mask. */
#define PMA_CTRL2_TYPE_SEL_100BTX      ((uint16_t)0x000EU) /*!< The 100BASE-TX type mask. */
#define PMA_CTRL2_TYPE_SEL_10BT        ((uint16_t)0x000FU) /*!< The 10BASE-T type mask. */
#define PMA_CTRL2_TYPE_SEL_2_5GBT      ((uint16_t)0x0030U) /*!< The 2.5GBASE-T type mask. */

/*! @brief Defines the mask flags in ANEG_CTRL register (7.0). */
#define ANEG_CTRL_ANEG_ENAB_MASK    ((uint16_t)0x1000U) /*!< The auto-negotiation enable mask. */
#define ANEG_CTRL_ANEG_RESTART_MASK ((uint16_t)0x0200U) /*!< The restart auto-negotiation mask. */
   
/*! @brief Defines the mask flags in ANEG_EEE_AN_ADV1 register (7.60). */
#define ANEG_EEE_AN_ADV1_100BTX_MASK ((uint16_t)0x0002U) /*!< The support of 100BASE-TX EEE mask. */
#define ANEG_EEE_AN_ADV1_1000BT_MASK ((uint16_t)0x0004U) /*!< The support of 1000BASE-T EEE mask. */

/*! @brief Defines the mask flags in ANEG_EEE_AN_ADV2 register (7.62). */
#define ANEG_EEE_AN_ADV2_EEE2G5_MASK ((uint16_t)0x0001U) /*!< The advertise 2G5BT EEE capability mask. */

/*! @brief Defines the PHY GPY215 expected value of the STD_PHYID1 register (0.2). */
#define PHY_CONTROL_ID1 (0x67C9U) /*!< The PHY ID1. */

/*! @brief Defines the timeout macro. */
#define PHY_READID_TIMEOUT_COUNT (1000U)

/*! @brief Defines the PHY resource interface. */
#define PHY_GPY215_WRITE(handle, regAddr, data) \
    (((phy_gpy215_resource_t *)(handle)->resource)->write((handle)->phyAddr, regAddr, data))
#define PHY_GPY215_READ(handle, regAddr, pData) \
    (((phy_gpy215_resource_t *)(handle)->resource)->read((handle)->phyAddr, regAddr, pData))
#define PHY_GPY215_WRITE_EXT(handle, devAddr, regAddr, data) \
    ((phy_gpy215_resource_t *)(handle)->resource)->writeExt((handle)->phyAddr, devAddr, regAddr, data)
#define PHY_GPY215_READ_EXT(handle, devAddr, regAddr, pData) \
    ((phy_gpy215_resource_t *)(handle)->resource)->readExt((handle)->phyAddr, devAddr, regAddr, pData)
#define PHY_GPY215_HAS_C45(handle)                                      \
    (((phy_gpy215_resource_t *)(handle)->resource)->readExt != NULL) && \
    (((phy_gpy215_resource_t *)(handle)->resource)->writeExt != NULL)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static status_t PHY_GPY215_SetLinkSpeed(phy_handle_t *handle, phy_speed_t speed);
static status_t PHY_GPY215_MMD_SetDevice(phy_handle_t *handle,
                                         uint8_t device,
                                         uint16_t addr,
                                         phy_mmd_access_mode_t mode);
static status_t PHY_GPY215_MMD_Read(phy_handle_t *handle, uint8_t device, uint16_t addr, uint16_t *data);
static status_t PHY_GPY215_MMD_Write(phy_handle_t *handle, uint8_t device, uint16_t addr, uint16_t data);

/*******************************************************************************
 * Variables
 ******************************************************************************/
const phy_operations_t phygpy215_ops = {.phyInit             = PHY_GPY215_Init,
                                        .phyWrite            = PHY_GPY215_Write,
                                        .phyRead             = PHY_GPY215_Read,
                                        .phyWriteC45         = PHY_GPY215_WriteC45,
                                        .phyReadC45          = PHY_GPY215_ReadC45,
                                        .getAutoNegoStatus   = PHY_GPY215_GetAutoNegotiationStatus,
                                        .getLinkStatus       = PHY_GPY215_GetLinkStatus,
                                        .getLinkSpeedDuplex  = PHY_GPY215_GetLinkSpeedDuplex,
                                        .setLinkSpeedDuplex  = PHY_GPY215_SetLinkSpeedDuplex,
                                        .enableLoopback      = PHY_GPY215_EnableLoopback,
                                        .enableLinkInterrupt = PHY_GPY215_EnableLinkInterrupt,
                                        .clearInterrupt      = PHY_GPY215_ClearInterrupt};

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t PHY_GPY215_Init(phy_handle_t *handle, const phy_config_t *config)
{
    uint32_t counter  = PHY_READID_TIMEOUT_COUNT;
    status_t result   = kStatus_Success;
    phy_gpy215_resource_t *resource;
    uint16_t regValue = 0;

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

    resource = (phy_gpy215_resource_t *)config->resource;
    assert((resource->read != NULL) && (resource->write != NULL));
    if ((resource->read == NULL) || (resource->write == NULL))
    {
        return kStatus_Fail;
    }

    /* Assign PHY address and operation resource. */
    handle->phyAddr  = config->phyAddr;
    handle->resource = config->resource;

    /* Check PHY ID. */
    do
    {
        result = PHY_GPY215_READ(handle, PHY_ID1_REG, &regValue);
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
    result = PHY_GPY215_WRITE(handle, PHY_BASICCONTROL_REG, STD_CTRL_RST_MASK);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Wait for reset to complete. */
    do
    {
        result = PHY_GPY215_READ(handle, PHY_BASICCONTROL_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }
    } while ((regValue & STD_CTRL_RST_MASK) != 0U);

    if (config->autoNeg)
    {
        /* Configure just EEE, GPY215 is already set to advertise relevant modes after reset. */
        result = PHY_GPY215_MMD_Read(handle, PHY_MMD_AN, ANEG_EEE_AN_ADV1_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        if (config->enableEEE)
        {
            regValue |= (ANEG_EEE_AN_ADV1_100BTX_MASK | ANEG_EEE_AN_ADV1_1000BT_MASK);
        }
        else
        {
            regValue &= (uint16_t)(~(ANEG_EEE_AN_ADV1_100BTX_MASK | ANEG_EEE_AN_ADV1_1000BT_MASK));
        }
        result = PHY_GPY215_MMD_Write(handle, PHY_MMD_AN, ANEG_EEE_AN_ADV1_REG, regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        result = PHY_GPY215_MMD_Read(handle, PHY_MMD_AN, ANEG_EEE_AN_ADV2_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        if (config->enableEEE)
        {
            regValue |= ANEG_EEE_AN_ADV2_EEE2G5_MASK;
        }
        else
        {
            regValue &= (uint16_t)(~ANEG_EEE_AN_ADV2_EEE2G5_MASK);
        }
        result = PHY_GPY215_MMD_Write(handle, PHY_MMD_AN, ANEG_EEE_AN_ADV2_REG, regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        /* Enable auto-negotiation. */
        result = PHY_GPY215_MMD_Read(handle, PHY_MMD_AN, ANEG_CTRL_REG, &regValue);
        if (result != kStatus_Success)
        {
            return result;
        }

        regValue |= (ANEG_CTRL_ANEG_ENAB_MASK | ANEG_CTRL_ANEG_RESTART_MASK);
        result = PHY_GPY215_MMD_Write(handle, PHY_MMD_AN, ANEG_CTRL_REG, regValue);
    }
    else
    {
        /* Disable the auto-negotiation and set user-defined speed/duplex configuration. */
        result = PHY_GPY215_SetLinkSpeedDuplex(handle, config->speed, config->duplex);
    }

    if (result != kStatus_Success)
    {
        return result;
    }

    /* Set PHY link status management interrupt. */
    result = PHY_GPY215_EnableLinkInterrupt(handle, config->intrType);

    return result;
}

status_t PHY_GPY215_Write(phy_handle_t *handle, uint8_t phyReg, uint16_t data)
{
    return PHY_GPY215_WRITE(handle, phyReg, data);
}

status_t PHY_GPY215_Read(phy_handle_t *handle, uint8_t phyReg, uint16_t *pData)
{
    return PHY_GPY215_READ(handle, phyReg, pData);
}

status_t PHY_GPY215_WriteC45(phy_handle_t *handle, uint8_t devAddr, uint16_t regAddr, uint16_t data)
{
    return PHY_GPY215_WRITE_EXT(handle, devAddr, regAddr, data);
}

status_t PHY_GPY215_ReadC45(phy_handle_t *handle, uint8_t devAddr, uint16_t regAddr, uint16_t *pData)
{
    return PHY_GPY215_READ_EXT(handle, devAddr, regAddr, pData);
}

status_t PHY_GPY215_GetAutoNegotiationStatus(phy_handle_t *handle, bool *status)
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
    result = PHY_GPY215_READ(handle, PHY_BASICSTATUS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if ((regValue & PHY_BSTATUS_AUTONEGCOMP_MASK) != 0U)
        {
            *status = true;
        }
    }
    return result;
}

status_t PHY_GPY215_GetLinkStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    status_t result;
    uint16_t regValue;

    if (status == NULL)
    {
        return kStatus_Fail;
    }

    /* Read the basic status register. */
    result = PHY_GPY215_READ(handle, PHY_BASICSTATUS_REG, &regValue);
    if (result == kStatus_Success)
    {
        if ((regValue & PHY_BSTATUS_LINKSTATUS_MASK) != 0U)
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

status_t PHY_GPY215_GetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t *speed, phy_duplex_t *duplex)
{
    assert(!((speed == NULL) && (duplex == NULL)));

    status_t result;
    uint16_t regValue;

    /* Read the media-independent interface status register. */
    result = PHY_GPY215_READ(handle, PHY_MIISTAT_REG, &regValue);
    if (result != kStatus_Success)
    {
        return result;
    }

    if ((regValue & PHY_MIISTAT_SPEED_MASK) == PHY_MIISTAT_SPEED_ANEG)
    {
        return kStatus_Timeout;
    }

    if (speed != NULL)
    {
        switch (regValue & PHY_MIISTAT_SPEED_MASK)
        {
            case PHY_MIISTAT_SPEED_TEN:
                *speed = kPHY_Speed10M;
                break;
            case PHY_MIISTAT_SPEED_FAST:
                *speed = kPHY_Speed100M;
                break;
            case PHY_MIISTAT_SPEED_GIGA:
                *speed = kPHY_Speed1000M;
                break;
            case PHY_MIISTAT_SPEED_BZ2G5:
                *speed = kPHY_Speed2500M;
                break;
            default:
                return kStatus_Fail;
        }
    }

    if (duplex != NULL)
    {
        if ((regValue & PHY_MIISTAT_DPX_MASK) != 0U)
        {
            *duplex = kPHY_FullDuplex;
        }
        else
        {
            *duplex = kPHY_HalfDuplex;
        }
    }

    return result;
}

status_t PHY_GPY215_SetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t speed, phy_duplex_t duplex)
{
    status_t result;
    uint16_t regValue;

    assert((duplex == kPHY_FullDuplex) || (speed <= kPHY_Speed100M));
    if ((duplex == kPHY_HalfDuplex) && (speed > kPHY_Speed100M))
    {
        return kStatus_Fail;
    }

    /* Set speed */
    result = PHY_GPY215_SetLinkSpeed(handle, speed);

    /* Set duplex mode. */
    result = PHY_GPY215_READ(handle, PHY_BASICCONTROL_REG, &regValue);
    if (result != kStatus_Success)
    {
        return result;
    }

    if (duplex == kPHY_FullDuplex)
    {
        regValue |= STD_CTRL_DPLX_MASK;
    }
    else
    {
        regValue &= ~STD_CTRL_DPLX_MASK;
    }

    /* Disable Autonegotiation */
    result = PHY_GPY215_MMD_Read(handle, PHY_MMD_AN, ANEG_CTRL_REG, &regValue);
    if (result != kStatus_Success)
    {
        return result;
    }

    regValue &= (uint16_t)(~(ANEG_CTRL_ANEG_ENAB_MASK | ANEG_CTRL_ANEG_RESTART_MASK));

    result = PHY_GPY215_MMD_Write(handle, PHY_MMD_AN, ANEG_CTRL_REG, regValue);

    return result;
}

status_t PHY_GPY215_EnableLoopback(phy_handle_t *handle, phy_loop_t mode, phy_speed_t speed, bool enable)
{
    /* This PHY only supports local loopback. */
    assert(mode == kPHY_LocalLoop);

    status_t result;
    uint16_t regValue;

    if (mode != kPHY_LocalLoop)
    {
        return kStatus_Fail;
    }

    if (enable)
    {
        /* Set speed first before reading basic control register. */
        result = PHY_GPY215_SetLinkSpeed(handle, speed);
        if (result != kStatus_Success)
        {
            return result;
        }
    }

    result = PHY_GPY215_READ(handle, PHY_BASICCONTROL_REG, &regValue);
    if (result != kStatus_Success)
    {
        return result;
    }

    if (enable)
    {
        /* Enable loopback. */
        regValue |= STD_CTRL_LB_MASK;
        return PHY_GPY215_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
    }
    else
    {
        /* Disable loopback and restart autonegotiation if enabled. */
        regValue &= ~STD_CTRL_LB_MASK;
        regValue |= STD_CTRL_ANRS_MASK;
        return PHY_GPY215_WRITE(handle, PHY_BASICCONTROL_REG, regValue);
    }
}

status_t PHY_GPY215_EnableLinkInterrupt(phy_handle_t *handle, phy_interrupt_type_t type)
{
    status_t result;
    uint16_t regValue;

    /* Clear pending interrupt first. */
    result = PHY_GPY215_ClearInterrupt(handle);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Enable/disable link interrupts. */
    if (type == kPHY_IntrDisable)
    {
        regValue = (uint16_t)0x0000U;
    }
    else
    {
        /*
         * MDINT polarity is determined by pin strapping, so setting the type parameter
         * to kPHY_IntrActiveLow or kPHY_IntrActiveHigh does not make a difference.
         */
        regValue = (PHY_IMASK_LSTC_MASK |
                    PHY_IMASK_LSPC_MASK |
                    PHY_IMASK_DXMC_MASK |
                    PHY_IMASK_ADSC_MASK |
                    PHY_IMASK_ANC_MASK);
    }

    return PHY_GPY215_WRITE(handle, PHY_IMASK_REG, regValue);
}

status_t PHY_GPY215_ClearInterrupt(phy_handle_t *handle)
{
    uint16_t regValue;

    return PHY_GPY215_READ(handle, PHY_ISTAT_REG, &regValue);    
}

static status_t PHY_GPY215_SetLinkSpeed(phy_handle_t *handle, phy_speed_t speed)
{
    status_t result;
    uint16_t regValue1;
    uint16_t regValue2;

    assert(speed <= kPHY_Speed2500M);
    if (speed > kPHY_Speed2500M)
    {
        return kStatus_Fail;
    }

    result = PHY_GPY215_MMD_Read(handle, PHY_MMD_PMAPMD, PMA_CTRL1_REG, &regValue1);
    if (result != kStatus_Success)
    {
        return result;
    }

    result = PHY_GPY215_MMD_Read(handle, PHY_MMD_PMAPMD, PMA_CTRL2_REG, &regValue2);
    if (result != kStatus_Success)
    {
        return result;
    }

    regValue1 &= ~(uint16_t)PMA_CTRL1_SPEED_MASK;
    regValue2 &= ~(uint16_t)PMA_CTRL2_TYPE_SEL_MASK;

    switch (speed)
    {
        case kPHY_Speed10M:
            regValue1 |= PMA_CTRL1_SPEED_10M;
            regValue2 |= PMA_CTRL2_TYPE_SEL_10BT;
            break;
        case kPHY_Speed100M:
            regValue1 |= PMA_CTRL1_SPEED_100M;
            regValue2 |= PMA_CTRL2_TYPE_SEL_100BTX;
            break;
        case kPHY_Speed1000M:
            regValue1 |= PMA_CTRL1_SPEED_1000M;
            regValue2 |= PMA_CTRL2_TYPE_SEL_MASK_1000BT;
            break;
        case kPHY_Speed2500M:
            regValue1 |= PMA_CTRL1_SPEED_2500M;
            regValue2 |= PMA_CTRL2_TYPE_SEL_2_5GBT;
            break;
        default:
            return kStatus_Fail;
    }

    result = PHY_GPY215_MMD_Write(handle, PHY_MMD_PMAPMD, PMA_CTRL1_REG, regValue1);
    if (result != kStatus_Success)
    {
        return result;
    }

    result = PHY_GPY215_MMD_Write(handle, PHY_MMD_PMAPMD, PMA_CTRL2_REG, regValue2);
    if (result != kStatus_Success)
    {
        return result;
    }

    return result;
}

static status_t PHY_GPY215_MMD_SetDevice(phy_handle_t *handle,
                                         uint8_t device,
                                         uint16_t addr,
                                         phy_mmd_access_mode_t mode)
{
    status_t result;

    /* Set Function mode of address access(b00) and device address. */
    result = PHY_GPY215_WRITE(handle, PHY_MMD_ACCESS_CONTROL_REG, device);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Set register address. */
    result = PHY_GPY215_WRITE(handle, PHY_MMD_ACCESS_DATA_REG, addr);
    if (result != kStatus_Success)
    {
        return result;
    }

    /* Set Function mode of data access(b01~11) and device address. */
    return PHY_GPY215_WRITE(handle, PHY_MMD_ACCESS_CONTROL_REG, (uint16_t)mode | (uint16_t)device);
}

static status_t PHY_GPY215_MMD_Read(phy_handle_t *handle, uint8_t device, uint16_t addr, uint16_t *data)
{
    status_t result;
    
    if (PHY_GPY215_HAS_C45(handle))
    {
        result = PHY_GPY215_READ_EXT(handle, device, addr, data);
    }
    else
    {
        result = PHY_GPY215_MMD_SetDevice(handle, device, addr, kPHY_MMDAccessNoPostIncrement);
        if (result == kStatus_Success)
        {
            result = PHY_GPY215_READ(handle, PHY_MMD_ACCESS_DATA_REG, data);
        }
    }

    return result;
}

static status_t PHY_GPY215_MMD_Write(phy_handle_t *handle, uint8_t device, uint16_t addr, uint16_t data)
{
    status_t result;

    if (PHY_GPY215_HAS_C45(handle))
    {
        result = PHY_GPY215_WRITE_EXT(handle, device, addr, data);
    }
    else
    {
        result = PHY_GPY215_MMD_SetDevice(handle, device, addr, kPHY_MMDAccessNoPostIncrement);
        if (result == kStatus_Success)
        {
            result = PHY_GPY215_WRITE(handle, PHY_MMD_ACCESS_DATA_REG, data);
        }
    }

    return result;
}
