/*
 * Copyright 2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_phytja1120.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Defines the PHY TJA1120 registers */

/* MMD1 - IEEE registers for PMA/PMD */
#define MDIO_PMA_PMD_CONTROL1                   (0x0000U)
#define MDIO_PMA_PMD_CONTROL1_REMOTE_LOOPBACK   (1U << 1)
#define MDIO_PMA_PMD_CONTROL1_LOCAL_LOOPBACK    (1U << 0)

/* MMD3 - IEEE registers for PCS */
#define MDIO_PCS_CONTROL1                       (0x0000U)
#define MDIO_PCS_CONTROL1_LOOPBACK              (1U << 14)

/* MMD30 - Device version register */
#define TJA1120_DEVICE_IDENTIFIER3              (0x0004U)
#define TJA1120_DEVICE_IDENTIFIER3_SIL_VER_MASK (0xF000U)
#define TJA1120_DEVICE_IDENTIFIER3_SIL_VER_A0   (0x1000U)

/* MMD30 - Device status register */
#define TJA1120_DEVICE_CONTROL                  (0x0040U)
#define TJA1120_DEVICE_CONTROL_RESET            (1U << 15)
#define TJA1120_DEVICE_CONTROL_GLOBAL_CFG_EN    (1U << 14)
#define TJA1120_DEVICE_CONTROL_SUPER_CFG_EN     (1U << 13)

/* MMD30 - Device status register */
#define TJA1120_XMII_ABILITIES                  (0xAFC4U)
#define TJA1120_XMII_ABILITIES_SGMII_ABILITY    (1U << 0)

/* MMD30 - SGMII control register */
#define TJA1120_SGMII_BASIC_CONTROL             (0xB000U)
#define TJA1120_SGMII_BASIC_CONTROL_LPM         (1U << 11)

/* Shared - Port function enables register */
#define TJA1120_PORT_FUNC_ENABLES               (0x8048U)
#define TJA1120_PORT_FUNC_ENABLES_TEST_EN       (1U << 0)

/* Shared - PHY control register */
#define TJA1120_PHY_CONTROL                     (0x8100U)
#define TJA1120_PHY_CONTROL_START_OP            (1U << 0)
#define TJA1120_PHY_CONTROL_GOTO_STANDBY        (1U << 1)

/* Shared - PHY status register */
#define TJA1120_PHY_STATUS                      (0x8102U)
#define TJA1120_PHY_STATUS_LINK_STAT            (1U << 2)

/* Shared - PHY config register */
#define TJA1120_PHY_CONFIG                      (0x8108U)
#define TJA1120_PHY_CONFIG_TEST_ENABLE          (1U << 1)
#define TJA1120_PHY_CONFIG_AUTO_OP              (1U << 0)

/* Shared - PHY functional IRQ masked status register */
#define TJA1120_PHY_FUNC_IRQ_STATUS             (0x80A2U)
#define TJA1120_PHY_FUNC_IRQ_LINK_EVENT         (1U << 1)
#define TJA1120_PHY_FUNC_IRQ_LINK_AVAIL         (1U << 2)

/* Shared - PHY functional IRQ source & enable registers */
#define TJA1120_PHY_FUNC_IRQ_ACK                (0x80A0U)
#define TJA1120_PHY_FUNC_IRQ_EN                 (0x80A1U)
#define TJA1120_PHY_FUNC_IRQ_LINK_EVENT_EN      (1U << 1)
#define TJA1120_PHY_FUNC_IRQ_LINK_AVAIL_EN      (1U << 2)

/* IEEE registers for PMA/PMD */
#define MDIO_PMA_PMD_BT1_CTRL                   (0x0834U)
#define MDIO_PMA_PMD_BT1_CTRL_CFG_LEADER        (1U << 14)

/*! @brief TJA1120 PHY identifier 1 */
#define TJA1120_ID_1 (0x1BU)

/*! @brief TJA1120 PHY identifier 2 */
#define TJA1120_ID_2 (0xB030U)

/*! @brief TJA1120 PHY identifier 2 mask */
#define TJA1120_ID_2_MASK (0xFFF0U)

/*! @brief Defines the timeout macro */
#define PHY_READID_TIMEOUT_COUNT (1000U)

/*! @brief Converts clause 22 register address to clause 45 address */
#define CL22_TO_CL45(register) ((register) + 0x8000U)

/*!
 * @brief Execute an operation and return immediately if it fails
 *
 * This macro executes the given operation and checks its status.
 * If the operation returns anything other than kStatus_Success,
 * it returns that error code from the current function.
 *
 * @param x The operation to execute
 */
#define RETURN_ON_ERROR(x) \
    do { \
        status_t _result = (x); \
        if (_result != kStatus_Success) \
        { \
          return _result; \
        } \
    } while(0)

/*! @brief Defines the PHY resource interface */
#define PHY_TJA1120_WRITE(handle, devAddr, regAddr, data) \
    ((phy_tja1120_resource_t *)(handle)->resource)->write((handle)->phyAddr, devAddr, regAddr, data)
#define PHY_TJA1120_READ(handle, devAddr, regAddr, pData) \
    ((phy_tja1120_resource_t *)(handle)->resource)->read((handle)->phyAddr, devAddr, regAddr, pData)

/*******************************************************************************
 * Variables
 ******************************************************************************/

const phy_operations_t phytja1120_ops = {.phyInit             = PHY_TJA1120_Init,
                                         .phyWrite            = NULL,
                                         .phyRead             = NULL,
                                         .phyWriteC45         = PHY_TJA1120_Write,
                                         .phyReadC45          = PHY_TJA1120_Read,
                                         .getAutoNegoStatus   = PHY_TJA1120_GetAutoNegotiationStatus,
                                         .getLinkStatus       = PHY_TJA1120_GetLinkStatus,
                                         .getLinkSpeedDuplex  = PHY_TJA1120_GetLinkSpeedDuplex,
                                         .setLinkSpeedDuplex  = PHY_TJA1120_SetLinkSpeedDuplex,
                                         .enableLoopback      = PHY_TJA1120_EnableLoopback,
                                         .enableLinkInterrupt = PHY_TJA1120_EnableInterrupt,
                                         .clearInterrupt      = PHY_TJA1120_ClearInterrupt};

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Verifies the TJA1120 PHY ID
 *
 * This function reads the PHY identifier registers and verifies they match
 * the expected values for a TJA1120 PHY.
 *
 * @param handle The PHY device handle.
 * @retval kStatus_Success if the PHY ID is valid
 * @retval kStatus_Fail if timeout occurs
 * @retval kStatus_Timeout PHY MDIO visit time out
 */
static status_t PHY_TJA1120_VerifyPhyId(phy_handle_t *handle)
{
    uint32_t counter = PHY_READID_TIMEOUT_COUNT;
    uint16_t reg1;
    uint16_t reg2;

    do
    {
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PMAPMD, CL22_TO_CL45(PHY_ID1_REG), &reg1));
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PMAPMD, CL22_TO_CL45(PHY_ID2_REG), &reg2));
        counter--;
    } while (((reg1 != TJA1120_ID_1) || ((reg2 & TJA1120_ID_2_MASK) != TJA1120_ID_2)) && (counter != 0U));

    if (counter == 0U)
    {
        return kStatus_Fail;
    }

    return kStatus_Success;
}

 /*!
 * @brief Performs a soft reset of the TJA1120 PHY device
 *
 * @param handle The PHY device handle.
 * @retval kStatus_Success if reset was successful
 * @retval kStatus_Timeout  PHY MDIO visit time out
 */
static status_t PHY_TJA1120_SoftReset(phy_handle_t *handle)
{
    uint16_t reg;

    /* Write reset bit to device control register */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_DEVICE_CONTROL,
                                      TJA1120_DEVICE_CONTROL_RESET));

    /* Poll until reset bit is cleared */
    do
    {
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_DEVICE_CONTROL, &reg));
    } while (reg & TJA1120_DEVICE_CONTROL_RESET);

    return kStatus_Success;
}

/*!
 * @brief Performs VDD_CORE work-around sequence as stated in the TJA1120
 * application note (AN13663) and ES_TJA1120 errata
 *
 * @param handle          PHY TJA1120 handle.
 * @param verifyWrites    Whether to verify write operations.
 * @retval kStatus_Success  PHY register sequence completed successfully
 * @retval kStatus_Fail     PHY register verification failed
 * @retval kStatus_Timeout  PHY register access timeout
 */
static status_t PHY_TJA1120_VddCoreWorkaround(phy_handle_t *handle, bool verifyWrites)
{
    uint16_t reg;

    /* 1st step of enabling write */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, 0x01F8, 0x4B95));

    /* 2nd step of enabling write */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, 0x01F9, 0xF3CD));

    /* Modify the internal LDO settings */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, 0x0476, 0x58A0));

    /* Modify the ADC latch configuration */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_PMAPMD, 0x8921, 0x0A3A));

    /* Modify SQI averaging */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_PMAPMD, 0x89F1, 0x16C1));

    /* OPTIONAL: Verify write operations */
    if (verifyWrites)
    {
        /* Verify LDO settings */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, 0x0476, &reg));

        /* Ignore status bits (bit 2 and bit 9) */
        reg &= 0xFDFB;

        if (reg != 0x58A0)
        {
            return kStatus_Fail;
        }

        /* Verify ADC latch configuration */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PMAPMD, 0x8921, &reg));

        if (reg != 0x0A3A)
        {
            return kStatus_Fail;
        }

        /* Verify SQI averaging */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PMAPMD, 0x89F1, &reg));

        if (reg != 0x16C1)
        {
            return kStatus_Fail;
        }
    }

    /* 1st step of disabling write */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, 0x01F8, 0x0000));

    /* 2nd step of disabling write */
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, 0x01F9, 0x0000));

    return kStatus_Success;
}

/*!
 * @brief Puts SGMII PCS into power down mode and restarts it
 *
 * This is required by ES_TJA1120 errata for a stable operation of SGMII after
 * a startup event (restart of the device, wake up from sleep, SGMII block reset).
 *
 * @param handle The PHY handle.
 * @retval kStatus_Success Operation was successful.
 * @retval kStatus_Fail An error occurred.
 */
static status_t PHY_TJA1120_SgmiiPcsRestart(phy_handle_t *handle)
{
    uint16_t reg;

    /* Check if SGMII is supported by reading XMII_ABILITIES register */
    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_XMII_ABILITIES, &reg));

    /* If SGMII ability bit is set */
    if (reg & TJA1120_XMII_ABILITIES_SGMII_ABILITY)
    {
        /* Read SGMII basic control register */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_SGMII_BASIC_CONTROL, &reg));

        /* Set PCS to the power down mode briefly */
        reg |= TJA1120_SGMII_BASIC_CONTROL_LPM;
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_SGMII_BASIC_CONTROL, reg));

        /* Resume the normal operation */
        reg &= ~TJA1120_SGMII_BASIC_CONTROL_LPM;
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_SGMII_BASIC_CONTROL, reg));
    }

    return kStatus_Success;
}

/*!
 * @brief Enables or disables configuration registers in the TJA1120 PHY
 *
 * @param handle Pointer to the PHY device handle.
 * @param enable true to enable configuration register access, false to disable it.
 * @retval kStatus_Success if successful
 * @retval kStatus_Fail or other error code otherwise.
 */
static status_t PHY_TJA1120_EnableConfigRegisters(phy_handle_t *handle, bool enable)
{
    uint16_t reg;

    if (enable)
    {
        /* Enable config registers */
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_DEVICE_CONTROL,
                                            TJA1120_DEVICE_CONTROL_GLOBAL_CFG_EN |
                                            TJA1120_DEVICE_CONTROL_SUPER_CFG_EN));
    }
    else
    {
        /* Clear configuration enable bits */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_DEVICE_CONTROL, &reg));
        reg &= ~(TJA1120_DEVICE_CONTROL_GLOBAL_CFG_EN | TJA1120_DEVICE_CONTROL_SUPER_CFG_EN);
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_DEVICE_CONTROL, reg));
    }

    return kStatus_Success;
}

/*!
 * @brief Starts PHY operation
 *
 * @param handle Pointer to the PHY device handle.
 * @retval kStatus_Success if successful
 * @retval kStatus_Fail or other error code otherwise.
 */
static status_t PHY_TJA1120_StartPhyOperation(phy_handle_t *handle)
{
    uint16_t reg;

    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PHY_CONTROL, &reg));
    reg &= ~TJA1120_PHY_CONTROL_GOTO_STANDBY;
    reg |= TJA1120_PHY_CONTROL_START_OP;
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_CONTROL, reg));

    return kStatus_Success;
}

/*!
 * @brief Goes to standy mode for reconfiguration
 *
 * @param handle Pointer to the PHY device handle.
 * @retval kStatus_Success if successful
 * @retval kStatus_Fail or other error code otherwise.
 */
static status_t PHY_TJA1120_GoToStandby(phy_handle_t *handle)
{
    uint16_t reg;

    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PHY_CONTROL, &reg));
    reg &= ~TJA1120_PHY_CONTROL_START_OP;
    reg |= TJA1120_PHY_CONTROL_GOTO_STANDBY;
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_CONTROL, reg));

    return kStatus_Success;
}

status_t PHY_TJA1120_Init(phy_handle_t *handle, const phy_config_t *config)
{
    assert(config != NULL);
    assert(config->speed == kPHY_Speed1000M);
    assert(config->duplex == kPHY_FullDuplex);
    assert(config->autoNeg == false);
    assert(config->enableEEE == false);
    assert((config->intrType == kPHY_IntrDisable) || (config->intrType == kPHY_IntrActiveLow));

    uint16_t reg;

    if ((config == NULL) ||
        (config->speed != kPHY_Speed1000M) ||
        (config->duplex != kPHY_FullDuplex) ||
        (config->autoNeg != false) ||
        (config->enableEEE != false) ||
        ((config->intrType != kPHY_IntrDisable) &&
         (config->intrType != kPHY_IntrActiveLow)))
    {
        return kStatus_InvalidArgument;
    }

    /* Assign PHY address and operation resource */
    handle->phyAddr  = config->phyAddr;
    handle->resource = config->resource;

    /* Check PHY ID */
    RETURN_ON_ERROR(PHY_TJA1120_VerifyPhyId(handle));

    /* Perform PHY soft reset */
    RETURN_ON_ERROR(PHY_TJA1120_SoftReset(handle));

    /* Perform VDD_CORE workaround if needed */
    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_DEVICE_IDENTIFIER3, &reg));
    if ((reg & TJA1120_DEVICE_IDENTIFIER3_SIL_VER_MASK) != TJA1120_DEVICE_IDENTIFIER3_SIL_VER_A0)
    {
        RETURN_ON_ERROR(PHY_TJA1120_VddCoreWorkaround(handle, true));
    }

    /* Ensure a stable operation of SGMII after a startup event */
    RETURN_ON_ERROR(PHY_TJA1120_SgmiiPcsRestart(handle));

    /* Enable configuration registers */
    RETURN_ON_ERROR(PHY_TJA1120_EnableConfigRegisters(handle, true));

    /* Enable PHY autonomous operation */
    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PHY_CONFIG, &reg));
    reg |= TJA1120_PHY_CONFIG_AUTO_OP;
    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_CONFIG, reg));

    /* Configure leader/follower mode */
    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PMAPMD, MDIO_PMA_PMD_BT1_CTRL, &reg));

    if (config->master)
    {
        reg |= MDIO_PMA_PMD_BT1_CTRL_CFG_LEADER;
    }
    else
    {
        reg &= ~MDIO_PMA_PMD_BT1_CTRL_CFG_LEADER;
    }

    RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_PMAPMD, MDIO_PMA_PMD_BT1_CTRL, reg));

    /* Enable interrupts if needed */
    RETURN_ON_ERROR(PHY_TJA1120_EnableInterrupt(handle, config->intrType));

    /* Start PHY operation */
    RETURN_ON_ERROR(PHY_TJA1120_StartPhyOperation(handle));

    return kStatus_Success;
}

status_t PHY_TJA1120_Write(phy_handle_t *handle, uint8_t devAddr, uint16_t phyReg, uint16_t data)
{
    return PHY_TJA1120_WRITE(handle, devAddr, phyReg, data);
}

status_t PHY_TJA1120_Read(phy_handle_t *handle, uint8_t devAddr, uint16_t phyReg, uint16_t *pData)
{
    return PHY_TJA1120_READ(handle, devAddr, phyReg, pData);
}

status_t PHY_TJA1120_GetAutoNegotiationStatus(phy_handle_t *handle, bool *status)
{
    /* For TJA1120, the link being up means auto-negotiation is complete
     * since it's a 1000BASE-T1 PHY with fixed speed/duplex settings */
    return PHY_TJA1120_GetLinkStatus(handle, status);
}

status_t PHY_TJA1120_GetLinkStatus(phy_handle_t *handle, bool *status)
{
    assert(status);

    uint16_t reg;

    if (status == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /* Check if internal (PCS) loopback is enabled */
    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PCS, MDIO_PCS_CONTROL1, &reg));
    if ((reg & MDIO_PCS_CONTROL1_LOOPBACK) == MDIO_PCS_CONTROL1_LOOPBACK)
    {
        /* Link available not set when activated */
        *status = true;
        return kStatus_Success;
    }

    /* Read PHY status register */
    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PHY_STATUS, &reg));

    *status = (reg & TJA1120_PHY_STATUS_LINK_STAT) != 0;
    return kStatus_Success;
}

status_t PHY_TJA1120_GetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t *speed, phy_duplex_t *duplex)
{
    assert(!((speed == NULL) && (duplex == NULL)));

    if ((speed == NULL) && (duplex == NULL))
    {
        return kStatus_InvalidArgument;
    }

    /* No need to read settings, speed and duplex is fixed on this PHY */

    if (speed != NULL)
    {
        *speed = kPHY_Speed1000M;
    }

    if (duplex != NULL)
    {
        *duplex = kPHY_FullDuplex;
    }

    return kStatus_Success;
}

status_t PHY_TJA1120_SetLinkSpeedDuplex(phy_handle_t *handle, phy_speed_t speed, phy_duplex_t duplex)
{
    assert(speed == kPHY_Speed1000M);
    assert(duplex == kPHY_FullDuplex);

    if ((speed != kPHY_Speed1000M) || (duplex != kPHY_FullDuplex))
    {
        return kStatus_InvalidArgument;
    }

    /* No need to write settings, speed and duplex is fixed on this PHY */
    return kStatus_Success;
}

status_t PHY_TJA1120_EnableLoopback(phy_handle_t *handle, phy_loop_t mode, phy_speed_t speed, bool enable)
{
    assert(speed == kPHY_Speed1000M);

    uint16_t reg;

    /* The TJA1120 only supports 1000 Mbps speed */
    if (speed != kPHY_Speed1000M)
    {
        return kStatus_InvalidArgument;
    }

    /* Go to standby for reconfiguration */
    RETURN_ON_ERROR(PHY_TJA1120_GoToStandby(handle));

    if (enable)
    {
        /* Set TEST_ENABLE bit before enabling loopback */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PHY_CONFIG, &reg));
        reg |= TJA1120_PHY_CONFIG_TEST_ENABLE;
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_CONFIG, reg));
    }

    switch (mode)
    {
        case kPHY_LocalLoop:
            /* Internal PCS loopback - Set LOOPBACK bit in PCS Control Register 1 */
            RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PCS, MDIO_PCS_CONTROL1, &reg));

            if (enable)
            {
                /* Enable PCS loopback */
                reg |= MDIO_PCS_CONTROL1_LOOPBACK;
            }
            else
            {
                /* Disable PCS loopback */
                reg &= ~MDIO_PCS_CONTROL1_LOOPBACK;
            }

            RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_PCS, MDIO_PCS_CONTROL1, reg));
            break;

        case kPHY_RemoteLoop:
            /* Remote PMA loopback - Set REMOTE_LOOPBACK bit in PMA/PMD Control Register 1 */
            RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PMAPMD, MDIO_PMA_PMD_CONTROL1, &reg));

            if (enable)
            {
                /* Enable PMA remote loopback */
                reg |= MDIO_PMA_PMD_CONTROL1_REMOTE_LOOPBACK;
            }
            else
            {
                /* Disable PMA remote loopback */
                reg &= ~MDIO_PMA_PMD_CONTROL1_REMOTE_LOOPBACK;
            }

            RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_PMAPMD, MDIO_PMA_PMD_CONTROL1, reg));
            break;

        case kPHY_ExternalLoop:
            /* External PMA loopback - Set LOCAL_LOOPBACK bit in PMA/PMD Control Register 1 */
            RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_PMAPMD, MDIO_PMA_PMD_CONTROL1, &reg));

            if (enable)
            {
                /* Enable PMA local loopback */
                reg |= MDIO_PMA_PMD_CONTROL1_LOCAL_LOOPBACK;
            }
            else
            {
                /* Disable PMA local loopback */
                reg &= ~MDIO_PMA_PMD_CONTROL1_LOCAL_LOOPBACK;
            }

            RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_PMAPMD, MDIO_PMA_PMD_CONTROL1, reg));
            break;

        default:
            return kStatus_InvalidArgument;
    }

    if (enable)
    {
        /* Enable test mode usage for port */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PORT_FUNC_ENABLES, &reg));
        reg |= TJA1120_PORT_FUNC_ENABLES_TEST_EN;
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PORT_FUNC_ENABLES, reg));
    }
    else
    {
        /* Clear TEST_ENABLE bit after disabling loopback */
        RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PHY_CONFIG, &reg));
        reg &= ~TJA1120_PHY_CONFIG_TEST_ENABLE;
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_CONFIG, reg));
    }

    /* Start PHY operation */
    RETURN_ON_ERROR(PHY_TJA1120_StartPhyOperation(handle));

    return kStatus_Success;
}

status_t PHY_TJA1120_EnableInterrupt(phy_handle_t *handle, phy_interrupt_type_t type)
{
    assert((type == kPHY_IntrDisable) || (type == kPHY_IntrActiveLow));

    if (type == kPHY_IntrDisable)
    {
        /* Disable all interrupts in PHY interrupt enable register */
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_FUNC_IRQ_EN, 0U));
    }
    else if (type == kPHY_IntrActiveLow)
    {
        /* Clear any pending interrupts */
        RETURN_ON_ERROR(PHY_TJA1120_ClearInterrupt(handle));

        /* Enable link status change interrupts */
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_FUNC_IRQ_EN,
                                          TJA1120_PHY_FUNC_IRQ_LINK_EVENT_EN |
                                          TJA1120_PHY_FUNC_IRQ_LINK_AVAIL_EN));
    }
    else
    {
        /* Interrupt type not supported */
        return kStatus_InvalidArgument;
    }
    
    return kStatus_Success;
}

status_t PHY_TJA1120_ClearInterrupt(phy_handle_t *handle)
{
    uint16_t reg;

    /* Read interrupt status register */
    RETURN_ON_ERROR(PHY_TJA1120_READ(handle, PHY_MMD_VEND1, TJA1120_PHY_FUNC_IRQ_STATUS, &reg));

    /* If there are active interrupts, acknowledge/clear them */
    if (reg & (TJA1120_PHY_FUNC_IRQ_LINK_EVENT | TJA1120_PHY_FUNC_IRQ_LINK_AVAIL))
    {
        /* Write the read value to the acknowledge register to clear the interrupts */
        RETURN_ON_ERROR(PHY_TJA1120_WRITE(handle, PHY_MMD_VEND1, TJA1120_PHY_FUNC_IRQ_ACK,
            (reg & (TJA1120_PHY_FUNC_IRQ_LINK_EVENT | TJA1120_PHY_FUNC_IRQ_LINK_AVAIL))));
    }

    return kStatus_Success;
}
