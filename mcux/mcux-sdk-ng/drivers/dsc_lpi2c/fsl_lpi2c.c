/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpi2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_lpi2c"
#endif

/* ! @brief LPI2C master fifo commands. */
enum
{
    kTxDataCmd = LPI2C_MTDR_CMD(0x0U), /*!< Transmit DATA[7:0] */
    kRxDataCmd = LPI2C_MTDR_CMD(0X1U), /*!< Receive (DATA[7:0] + 1) bytes */
    kStopCmd   = LPI2C_MTDR_CMD(0x2U), /*!< Generate STOP condition */
    kStartCmd  = LPI2C_MTDR_CMD(0x4U), /*!< Generate(repeated) START and transmit address in DATA[[7:0] */
};

/*!
 * @brief Default watermark values.
 *
 * The default watermarks are set to zero.
 */
enum
{
    kDefaultTxWatermark = 0,
    kDefaultRxWatermark = 0,
};

/*! @brief States for the state machine used by transactional APIs. */
enum
{
    kIdleState = 0,
    kSendCommandState,
    kIssueReadCommandState,
    kTransferDataState,
    kStopState,
    kWaitForCompletionState,
#if I2C_SMBUS_ENABLE
    kSendPecState,
    kCheckPecAckState,
    kReceivePecState,
    kCheckReceivedPecState,
#endif
};

/*! @brief Typedef for master interrupt handler. */
typedef void (*lpi2c_master_isr_t)(lpi2c_master_transfer_handle_t *psHandle);

/*! @brief Typedef for slave interrupt handler. */
typedef void (*lpi2c_slave_isr_t)(lpi2c_slave_transfer_handle_t *psHandle);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* Not static so it can be used from fsl_lpi2c_edma.c. */
uint32_t LPI2C_GetInstance(LPI2C_Type *base);

static uint16_t LPI2C_GetCyclesForWidth(uint32_t u32SrcClockHz,
                                        uint32_t u32WidthNs,
                                        uint32_t u32MaxCycles,
                                        uint16_t u16Prescaler);

static status_t LPI2C_MasterWaitForTxReady(LPI2C_Type *base);

static status_t LPI2C_MasterTransferRunStateMachine(lpi2c_master_transfer_handle_t *psHandle, bool *bIsDone);

static void LPI2C_TransferInitStateMachine(lpi2c_master_transfer_handle_t *psHandle);

static status_t LPI2C_SlaveCheckAndClearError(LPI2C_Type *base, uint16_t u16Flags);

static void LPI2C_CommonIRQHandler(uint32_t u32Instance);

#if I2C_SMBUS_ENABLE
void LPI2C_UpdateCrc8(uint8_t *pu8CrcValue, uint8_t *pu8Data, uint16_t u16ByteCount);
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map LPI2C instance number to base pointer. */
static LPI2C_Type *const s_eLpi2cBases[] = LPI2C_BASE_PTRS;

/*! @brief Array to map LPI2C instance number to IRQ number. */
static IRQn_Type const s_eLpi2cIrqs[] = LPI2C_IRQS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map LPI2C instance number to clock gate enum. */
static clock_ip_name_t const s_eLpi2cClocks[] = LPI2C_CLOCKS;

#if defined(LPI2C_PERIPH_CLOCKS)
/*! @brief Array to map LPI2C instance number to pheripheral clock gate enum. */
static const clock_ip_name_t s_eLpi2cPeriphClocks[] = LPI2C_PERIPH_CLOCKS;
#endif

#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Pointer to master IRQ handler. */
static lpi2c_master_isr_t s_pfLpi2cMasterIsr;

/*! @brief Pointers to master handles for each instance. */
static lpi2c_master_transfer_handle_t *s_psLpi2cMasterHandle[ARRAY_SIZE(s_eLpi2cBases)];

/*! @brief Pointer to slave IRQ handler. */
static lpi2c_slave_isr_t s_pfLpi2cSlaveIsr;

/*! @brief Pointers to slave handles for each instance. */
static lpi2c_slave_transfer_handle_t *s_psLpi2cSlaveHandle[ARRAY_SIZE(s_eLpi2cBases)];

#if I2C_SMBUS_ENABLE
static uint8_t s_u8MasterCrcValue = 0U;
static uint8_t s_u8SlaveCrcValue  = 0U;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Returns an instance number given a base address.
 *
 * If an invalid base address is passed, debug builds will assert. Release builds will just return
 * instance number 0.
 *
 * @param base The LPI2C peripheral base address.
 * @return LPI2C instance number starting from 0.
 */
uint32_t LPI2C_GetInstance(LPI2C_Type *base)
{
    uint32_t u32Instance;
    for (u32Instance = 0U; u32Instance < ARRAY_SIZE(s_eLpi2cBases); ++u32Instance)
    {
        if (s_eLpi2cBases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_eLpi2cBases));
    return u32Instance;
}

/*!
 * @brief Computes a cycle count for a given time in nanoseconds.
 * @param u32SrcClockHz LPI2C functional clock frequency in Hertz.
 * @param u32WidthNs Desired with in nanoseconds.
 * @param u32MaxCycles Maximum cycle count, determined by the number of bits wide the cycle count field is.
 * @param u16Prescaler LPI2C prescaler setting. Pass 1 if the prescaler should not be used, as for slave glitch widths.
 */
static uint16_t LPI2C_GetCyclesForWidth(uint32_t u32SrcClockHz,
                                        uint32_t u32WidthNs,
                                        uint32_t u32MaxCycles,
                                        uint16_t u16Prescaler)
{
    assert(u32SrcClockHz > 0U);
    assert(u16Prescaler > 0U);

    uint32_t u32BusCycleNs = 1000000UL / (u32SrcClockHz / u16Prescaler / 1000U);
    uint16_t u16Cycles     = 0U;

    /* Search for the cycle count just below the desired glitch width. */
    while (((u16Cycles * u32BusCycleNs) < u32WidthNs) && (u16Cycles < u32MaxCycles))
    {
        ++u16Cycles;
    }
    /* Use this same logic code flow rather than 'u16Cycles+1' in while loop to pass compiler issue */
    if (u16Cycles > 0U)
    {
        u16Cycles--;
    }

    /* If we end up with zero cycles, then set the filter to a single cycle unless the */
    /* bus clock is greater than 10x the desired glitch width. */
    if ((u16Cycles == 0U) && (u32BusCycleNs <= (u32WidthNs * 10U)))
    {
        u16Cycles = 1U;
    }

    return u16Cycles;
}

/*!
 * @brief Wait until there is room in the tx fifo.
 * @param base The LPI2C peripheral base address.
 * @retval #kStatus_Success
 * @retval #kStatus_LPI2C_PinLowTimeout
 * @retval #kStatus_LPI2C_ArbitrationLost
 * @retval #kStatus_LPI2C_Nak
 * @retval #kStatus_LPI2C_FifoError
 */
static status_t LPI2C_MasterWaitForTxReady(LPI2C_Type *base)
{
    uint16_t u16Status;
    uint16_t u16TxCount;
    uint16_t txFifoSize = (uint16_t)FSL_FEATURE_LPI2C_FIFO_SIZEn(base);

#if I2C_RETRY_TIMES
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
#endif
    do
    {
        status_t result;

        /* Get the number of words in the tx fifo and compute empty slots. */
        LPI2C_MasterGetFifoCounts(base, NULL, &u16TxCount);
        u16TxCount = txFifoSize - u16TxCount;

        /* Check for error flags. */
        u16Status = LPI2C_MasterGetStatusFlags(base);
        result    = LPI2C_MasterCheckAndClearError(base, u16Status);
        if (kStatus_Success != result)
        {
            return result;
        }
#if I2C_RETRY_TIMES
    } while ((0U == u16TxCount) && (0U != --u32WaitTimes));

    if (0U == u32WaitTimes)
    {
        return kStatus_LPI2C_Timeout;
    }
#else
    } while (0U == u16TxCount);
#endif

    return kStatus_Success;
}

/* ------------------------------------ Module Init/Deinit Sub-group ------------------------------------ */
/*!
 * brief Provides a default configuration for the LPI2C peripheral, including master and slave.
 *
 * This is an example:
 * code
 *   lpi2c_config_t config;
 *   LPI2C_GetDefaultConfig(&config, 12000000U);
 *   config.u32BaudRateBps = 100000U;
 *   LPI2C_Init(LPI2C1, &config);
 * endcode
 *
 * After calling this function, you can override any settings in order to customize the configuration,
 * prior to initializing the driver with LPI2C_Init().
 *
 * param psConfig User provided configuration structure for default values. Refer to #lpi2c_config_t.
 * param u16SlaveAddress Slave address raw value, driver will shift it.
 * param u32SrcClockHz Frequency in Hertz of the LPI2C functional clock. Used to calculate the baud rate divisors,
 *      filter widths, and timeout periods.
 */
void LPI2C_GetDefaultConfig(lpi2c_config_t *psConfig, uint16_t u16SlaveAddress, uint32_t u32SrcClockHz)
{
    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    /* Store LPI2C peripheral clock for driver use. */
    psConfig->u32SrcClockHz = u32SrcClockHz;

    /* Initializes the master configure structure. */

    /* Default enable the master interface */
    psConfig->bEnableMaster       = true;
    psConfig->bEnableDoze         = true;
    psConfig->bDebugEnable        = false;
    psConfig->bMasterIgnoreAck    = false;
    psConfig->ePinConfig          = (uint16_t)kLPI2C_2PinOpenDrain;
    psConfig->u32BaudRateBps      = 100000UL;
    psConfig->u32BusIdleTimeoutNs = 0U;
#if I2C_SMBUS_ENABLE
    /* Set Pin Low Timeout to 35ms as default according to SMBus specification. */
    psConfig->u32PinLowTimeoutNs = 35000UL;
#endif
    psConfig->u32MasterSdaGlitchFilterWidthNs = 200U;
    psConfig->u32MasterSclGlitchFilterWidthNs = 200U;
    psConfig->hostRequest.bEnable             = false;
    psConfig->hostRequest.eSource             = (uint16_t)kLPI2C_HostRequestExternalPin;
    psConfig->hostRequest.ePolarity           = (uint16_t)kLPI2C_HostRequestPinActiveHigh;

    /* Initializes the slave configure structure. */

    /* Default enable the slave interface */
    psConfig->bEnableSlave                   = true;
    psConfig->u16Address0                    = u16SlaveAddress;
    psConfig->u16Address1                    = 0U;
    psConfig->eAddressMatchMode              = (uint16_t)kLPI2C_Match7BitAddress0;
    psConfig->bFilterDozeEnable              = true;
    psConfig->bFilterEnable                  = true;
    psConfig->bEnableGeneralCall             = false;
    psConfig->bEnableSmbusAlert              = false;
    psConfig->sSclStall.bEnableAck           = false;
    psConfig->sSclStall.bEnableTx            = true;
    psConfig->sSclStall.bEnableRx            = true;
    psConfig->sSclStall.bEnableAddress       = false;
    psConfig->bSlaveIgnoreAck                = false;
    psConfig->bEnableReceivedAddressRead     = false;
    psConfig->u32SlaveSdaGlitchFilterWidthNs = 200U;
    psConfig->u32SlaveSclGlitchFilterWidthNs = 200U;
    psConfig->u32DataValidDelayNs            = 0U;
    psConfig->u32ClockHoldTimeNs             = 0U;
}

/*!
 * brief Initializes the LPI2C peripheral, including master and slave.
 *
 * This function enables the peripheral clock and initializes the LPI2C peripheral as described by the user
 * provided configuration. A software reset is performed prior to configuration. This function can enable master
 * and slave together. If only want to use one of them, please call LPI2C_MasterInit or LPI2C_SlaveInit.
 *
 * note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enabled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the
 * API.
 *
 * param base The LPI2C peripheral base address.
 * param psConfig User provided peripheral configuration. Use LPI2C_GetDefaultConfig() to get a set of
 * defaults that you can override.
 */
void LPI2C_Init(LPI2C_Type *base, const lpi2c_config_t *psConfig)
{
    uint16_t u16Prescaler;
    uint16_t u16Cycles;
    uint16_t u16Cfgr2;
    uint16_t u16Cfgr3;
    uint16_t u16Value;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)

    uint32_t u32Instance = LPI2C_GetInstance(base);

    /* Ungate the clock. */
    CLOCK_EnableClock(s_eLpi2cClocks[u32Instance]);
#if defined(LPI2C_PERIPH_CLOCKS)
    /* Ungate the functional clock in initialize function. */
    CLOCK_EnableClock(s_eLpi2cPeriphClocks[instance]);
#endif

#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /** Master Interface Init. */

    /* Reset peripheral before configuring it. */
    LPI2C_MasterReset(base);

    /* Doze bit: 0 is enable, 1 is disable */
    base->MCR = LPI2C_MCR_DBGEN(psConfig->bDebugEnable) | LPI2C_MCR_DOZEN(!(psConfig->bEnableDoze));

    /* host request */
    u16Value = base->MCFGR0;
    u16Value &= (~(LPI2C_MCFGR0_HREN_MASK | LPI2C_MCFGR0_HRPOL_MASK | LPI2C_MCFGR0_HRSEL_MASK));
    u16Value |= LPI2C_MCFGR0_HREN(psConfig->hostRequest.bEnable) | LPI2C_MCFGR0_HRPOL(psConfig->hostRequest.ePolarity) |
                LPI2C_MCFGR0_HRSEL(psConfig->hostRequest.eSource);
    base->MCFGR0 = u16Value;

    /* pin config and ignore ack */
    u16Value = base->MCFGR1;
    u16Value &= ~(LPI2C_MCFGR1_PINCFG_MASK | LPI2C_MCFGR1_IGNACK_MASK);
    u16Value |= LPI2C_MCFGR1_PINCFG(psConfig->ePinConfig);
    u16Value |= LPI2C_MCFGR1_IGNACK(psConfig->bMasterIgnoreAck);
    base->MCFGR1 = u16Value;

    LPI2C_MasterSetWatermarks(base, (uint16_t)kDefaultTxWatermark, (uint16_t)kDefaultRxWatermark);

    /* Configure glitch filters and bus idle and pin low timeouts. */
    u16Prescaler = (base->MCFGR1 & LPI2C_MCFGR1_PRESCALE_MASK) >> LPI2C_MCFGR1_PRESCALE_SHIFT;
    if (0U != (psConfig->u32BusIdleTimeoutNs))
    {
        u16Cfgr2  = base->MCFGR2;
        u16Cycles = LPI2C_GetCyclesForWidth(psConfig->u32SrcClockHz, psConfig->u32BusIdleTimeoutNs,
                                            (LPI2C_MCFGR2_BUSIDLE_MASK >> LPI2C_MCFGR2_BUSIDLE_SHIFT), u16Prescaler);
        u16Cfgr2 &= ~LPI2C_MCFGR2_BUSIDLE_MASK;
        u16Cfgr2 |= LPI2C_MCFGR2_BUSIDLE(u16Cycles);
        base->MCFGR2 = u16Cfgr2;
    }
    u16Cfgr3 = base->MCFGR3;
    if (0U != (psConfig->u32MasterSdaGlitchFilterWidthNs))
    {
        u16Cycles = LPI2C_GetCyclesForWidth(psConfig->u32SrcClockHz, psConfig->u32MasterSdaGlitchFilterWidthNs,
                                            (LPI2C_MCFGR3_FILTSDA_MASK >> LPI2C_MCFGR3_FILTSDA_SHIFT), 1U);
        u16Cfgr3 &= ~LPI2C_MCFGR3_FILTSDA_MASK;
        u16Cfgr3 |= LPI2C_MCFGR3_FILTSDA(u16Cycles);
    }
    if (0U != psConfig->u32MasterSclGlitchFilterWidthNs)
    {
        u16Cycles = LPI2C_GetCyclesForWidth(psConfig->u32SrcClockHz, psConfig->u32MasterSclGlitchFilterWidthNs,
                                            (LPI2C_MCFGR3_FILTSCL_MASK >> LPI2C_MCFGR3_FILTSCL_SHIFT), 1U);
        u16Cfgr3 &= ~LPI2C_MCFGR3_FILTSCL_MASK;
        u16Cfgr3 |= LPI2C_MCFGR3_FILTSCL(u16Cycles);
    }
    base->MCFGR3 = u16Cfgr3;
    if (0U != psConfig->u32PinLowTimeoutNs)
    {
        u16Cycles    = LPI2C_GetCyclesForWidth(psConfig->u32SrcClockHz, psConfig->u32PinLowTimeoutNs / 256U,
                                            (LPI2C_MCFGR2_BUSIDLE_MASK >> LPI2C_MCFGR2_BUSIDLE_SHIFT), u16Prescaler);
        base->MCFGR4 = (base->MCFGR4 & ~LPI2C_MCFGR4_PINLOW_MASK) | LPI2C_MCFGR4_PINLOW(u16Cycles);
    }

    LPI2C_MasterSetBaudRate(base, psConfig->u32SrcClockHz, psConfig->u32BaudRateBps);
    LPI2C_MasterEnable(base, psConfig->bEnableMaster);

    /** Slave Interface Init. */

    /* Restore to reset conditions. */
    LPI2C_SlaveReset(base);

    /* Configure peripheral. */
    base->SAMR0 = LPI2C_SAMR0_ADDR0(psConfig->u16Address0);
    base->SAMR1 = LPI2C_SAMR1_ADDR1(psConfig->u16Address1);

    base->SCFGR0 =
        LPI2C_SCFGR0_SAEN(psConfig->bEnableSmbusAlert) | LPI2C_SCFGR0_IGNACK(psConfig->bSlaveIgnoreAck) |
        LPI2C_SCFGR0_RXCFG(psConfig->bEnableReceivedAddressRead) | LPI2C_SCFGR0_GCEN(psConfig->bEnableGeneralCall) |
        LPI2C_SCFGR0_ACKSTALL(psConfig->sSclStall.bEnableAck) | LPI2C_SCFGR0_TXDSTALL(psConfig->sSclStall.bEnableTx) |
        LPI2C_SCFGR0_RXSTALL(psConfig->sSclStall.bEnableRx) | LPI2C_SCFGR0_ADRSTALL(psConfig->sSclStall.bEnableAddress);

    base->SCFGR1 = LPI2C_SCFGR1_ADDRCFG(psConfig->eAddressMatchMode);

    u16Cycles =
        LPI2C_SCFGR2_DATAVD(LPI2C_GetCyclesForWidth(psConfig->u32SrcClockHz, psConfig->u32DataValidDelayNs,
                                                    (LPI2C_SCFGR2_DATAVD_MASK >> LPI2C_SCFGR2_DATAVD_SHIFT), 1U));

    base->SCFGR2 = u16Cycles | LPI2C_SCFGR2_CLKHOLD(LPI2C_GetCyclesForWidth(
                                   psConfig->u32SrcClockHz, psConfig->u32ClockHoldTimeNs,
                                   (LPI2C_SCFGR2_CLKHOLD_MASK >> LPI2C_SCFGR2_CLKHOLD_SHIFT), 1U));

    u16Cycles =
        LPI2C_SCFGR3_FILTSDA(LPI2C_GetCyclesForWidth(psConfig->u32SrcClockHz, psConfig->u32SlaveSdaGlitchFilterWidthNs,
                                                     (LPI2C_SCFGR3_FILTSDA_MASK >> LPI2C_SCFGR3_FILTSDA_SHIFT), 1U));
    u16Cycles |=
        LPI2C_SCFGR3_FILTSCL(LPI2C_GetCyclesForWidth(psConfig->u32SrcClockHz, psConfig->u32SlaveSclGlitchFilterWidthNs,
                                                     (LPI2C_SCFGR3_FILTSCL_MASK >> LPI2C_SCFGR3_FILTSCL_SHIFT), 1U));

    base->SCFGR3 = u16Cycles;

    /* Save SCR to last so we don't enable slave until it is configured */
    base->SCR = LPI2C_SCR_FILTDZ(psConfig->bFilterDozeEnable) | LPI2C_SCR_FILTEN(psConfig->bFilterEnable) |
                LPI2C_SCR_SEN(psConfig->bEnableSlave);
}

/*!
 * brief Deinitializes the LPI2C peripheral, including master and slave.
 *
 * This function disables the LPI2C peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * param base The LPI2C peripheral base address.
 */
void LPI2C_Deinit(LPI2C_Type *base)
{
    /* Restore to reset state. */
    LPI2C_MasterReset(base);
    LPI2C_SlaveReset(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)

    uint32_t instance = LPI2C_GetInstance(base);

    /* Gate clock. */
    CLOCK_DisableClock(s_eLpi2cClocks[instance]);
#if defined(LPI2C_PERIPH_CLOCKS)
    /* Gate the functional clock. */
    CLOCK_DisableClock(s_eLpi2cPeriphClocks[instance]);
#endif

#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Provides a default configuration for the LPI2C master peripheral.
 *
 * This is an example:
 * code
 *   lpi2c_master_config_t sConfig;
 *   LPI2C_MasterGetDefaultConfig(&sConfig, 12000000U);
 *   sConfig.u32BaudRateBps = 100000U;
 *   I2C_MasterInit(LPI2C1, &sConfig);
 * endcode
 *
 * After calling this function, you can override any settings in order to customize the configuration,
 * prior to initializing the master driver with LPI2C_MasterInit().
 *
 * param psMasterConfig User provided configuration structure for default values. Refer to #lpi2c_master_config_t.
 * param u32SrcClockHz Frequency in Hertz of the LPI2C functional clock. Used to calculate the baud rate divisors,
 *       filter widths, and timeout periods.
 */
void LPI2C_MasterGetDefaultConfig(lpi2c_master_config_t *psMasterConfig, uint32_t u32SrcClockHz)
{
    /* Initializes the configure structure to zero. */
    (void)memset(psMasterConfig, 0, sizeof(*psMasterConfig));

    /* Default enable the master interface */
    psMasterConfig->bEnableMaster       = true;
    psMasterConfig->bEnableDoze         = true;
    psMasterConfig->bDebugEnable        = false;
    psMasterConfig->bIgnoreAck          = false;
    psMasterConfig->ePinConfig          = (uint16_t)kLPI2C_2PinOpenDrain;
    psMasterConfig->u32SrcClockHz       = u32SrcClockHz;
    psMasterConfig->u32BaudRateBps      = 100000UL;
    psMasterConfig->u32BusIdleTimeoutNs = 0U;
#if I2C_SMBUS_ENABLE
    /* Set Pin Low Timeout to 35ms as default according to SMBus specification. */
    psMasterConfig->u32PinLowTimeoutNs = 35000UL;
#endif
    psMasterConfig->u32SdaGlitchFilterWidthNs = 200U;
    psMasterConfig->u32SclGlitchFilterWidthNs = 200U;
    psMasterConfig->hostRequest.bEnable       = false;
    psMasterConfig->hostRequest.eSource       = (uint16_t)kLPI2C_HostRequestExternalPin;
    psMasterConfig->hostRequest.ePolarity     = (uint16_t)kLPI2C_HostRequestPinActiveHigh;
}

/*!
 * brief Initializes the LPI2C master peripheral.
 *
 * This function enables the peripheral clock and initializes the LPI2C master peripheral as described by the user
 * provided configuration. A software reset is performed prior to configuration. User just needs to call this function
 * to enable LPI2C master if only use I2C master operation.
 *
 * note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enabled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the
 * API.
 *
 * param base The LPI2C peripheral base address.
 * param psMasterConfig User provided peripheral configuration. Use LPI2C_MasterGetDefaultConfig() to get a set of
 *       defaults that you can override.
 */
void LPI2C_MasterInit(LPI2C_Type *base, const lpi2c_master_config_t *psMasterConfig)
{
    uint16_t u16Prescaler;
    uint16_t u16Cycles;
    uint16_t u16Cfgr2;
    uint16_t u16Cfgr3;
    uint16_t u16Value;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)

    uint32_t instance = LPI2C_GetInstance(base);

    /* Ungate the clock. */
    CLOCK_EnableClock(s_eLpi2cClocks[instance]);
#if defined(LPI2C_PERIPH_CLOCKS)
    /* Ungate the functional clock in initialize function. */
    CLOCK_EnableClock(s_eLpi2cPeriphClocks[instance]);
#endif

#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Reset peripheral before configuring it. */
    LPI2C_MasterReset(base);

    /* Doze bit: 0 is enable, 1 is disable */
    base->MCR = LPI2C_MCR_DBGEN(psMasterConfig->bDebugEnable) | LPI2C_MCR_DOZEN(!(psMasterConfig->bEnableDoze));

    /* host request */
    u16Value = base->MCFGR0;
    u16Value &= (~(LPI2C_MCFGR0_HREN_MASK | LPI2C_MCFGR0_HRPOL_MASK | LPI2C_MCFGR0_HRSEL_MASK));
    u16Value |= LPI2C_MCFGR0_HREN(psMasterConfig->hostRequest.bEnable) |
                LPI2C_MCFGR0_HRPOL(psMasterConfig->hostRequest.ePolarity) |
                LPI2C_MCFGR0_HRSEL(psMasterConfig->hostRequest.eSource);
    base->MCFGR0 = u16Value;

    /* pin config and ignore ack */
    u16Value = base->MCFGR1;
    u16Value &= ~(LPI2C_MCFGR1_PINCFG_MASK | LPI2C_MCFGR1_IGNACK_MASK);
    u16Value |= LPI2C_MCFGR1_PINCFG(psMasterConfig->ePinConfig);
    u16Value |= LPI2C_MCFGR1_IGNACK(psMasterConfig->bIgnoreAck);
    base->MCFGR1 = u16Value;

    LPI2C_MasterSetWatermarks(base, (uint16_t)kDefaultTxWatermark, (uint16_t)kDefaultRxWatermark);

    /* Configure glitch filters and bus idle and pin low timeouts. */
    u16Prescaler = (base->MCFGR1 & LPI2C_MCFGR1_PRESCALE_MASK) >> LPI2C_MCFGR1_PRESCALE_SHIFT;
    if (0U != (psMasterConfig->u32BusIdleTimeoutNs))
    {
        u16Cfgr2  = base->MCFGR2;
        u16Cycles = LPI2C_GetCyclesForWidth(psMasterConfig->u32SrcClockHz, psMasterConfig->u32BusIdleTimeoutNs,
                                            (LPI2C_MCFGR2_BUSIDLE_MASK >> LPI2C_MCFGR2_BUSIDLE_SHIFT), u16Prescaler);
        u16Cfgr2 &= ~LPI2C_MCFGR2_BUSIDLE_MASK;
        u16Cfgr2 |= LPI2C_MCFGR2_BUSIDLE(u16Cycles);
        base->MCFGR2 = u16Cfgr2;
    }
    u16Cfgr3 = base->MCFGR3;
    if (0U != (psMasterConfig->u32SdaGlitchFilterWidthNs))
    {
        u16Cycles = LPI2C_GetCyclesForWidth(psMasterConfig->u32SrcClockHz, psMasterConfig->u32SdaGlitchFilterWidthNs,
                                            (LPI2C_MCFGR3_FILTSDA_MASK >> LPI2C_MCFGR3_FILTSDA_SHIFT), 1U);
        u16Cfgr3 &= ~LPI2C_MCFGR3_FILTSDA_MASK;
        u16Cfgr3 |= LPI2C_MCFGR3_FILTSDA(u16Cycles);
    }
    if (0U != psMasterConfig->u32SclGlitchFilterWidthNs)
    {
        u16Cycles = LPI2C_GetCyclesForWidth(psMasterConfig->u32SrcClockHz, psMasterConfig->u32SclGlitchFilterWidthNs,
                                            (LPI2C_MCFGR3_FILTSCL_MASK >> LPI2C_MCFGR3_FILTSCL_SHIFT), 1U);
        u16Cfgr3 &= ~LPI2C_MCFGR3_FILTSCL_MASK;
        u16Cfgr3 |= LPI2C_MCFGR3_FILTSCL(u16Cycles);
    }
    base->MCFGR3 = u16Cfgr3;
    if (0U != psMasterConfig->u32PinLowTimeoutNs)
    {
        u16Cycles    = LPI2C_GetCyclesForWidth(psMasterConfig->u32SrcClockHz, psMasterConfig->u32PinLowTimeoutNs / 256U,
                                            (LPI2C_MCFGR2_BUSIDLE_MASK >> LPI2C_MCFGR2_BUSIDLE_SHIFT), u16Prescaler);
        base->MCFGR4 = (base->MCFGR4 & ~LPI2C_MCFGR4_PINLOW_MASK) | LPI2C_MCFGR4_PINLOW(u16Cycles);
    }

    LPI2C_MasterSetBaudRate(base, psMasterConfig->u32SrcClockHz, psMasterConfig->u32BaudRateBps);
    LPI2C_MasterEnable(base, psMasterConfig->bEnableMaster);
}

/*!
 * brief Deinitializes the LPI2C master peripheral.
 *
 * This function disables the LPI2C master peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * param base The LPI2C peripheral base address.
 */
void LPI2C_MasterDeinit(LPI2C_Type *base)
{
    /* Restore to reset state. */
    LPI2C_MasterReset(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)

    uint32_t instance = LPI2C_GetInstance(base);

    /* Gate clock. */
    CLOCK_DisableClock(s_eLpi2cClocks[instance]);
#if defined(LPI2C_PERIPH_CLOCKS)
    /* Gate the functional clock. */
    CLOCK_DisableClock(s_eLpi2cPeriphClocks[instance]);
#endif

#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Provides a default configuration for the LPI2C slave peripheral.
 *
 * This is an example:
 * code
 *   lpi2c_slave_config_t sConfig;
 *   LPI2C_SlaveGetDefaultConfig(&sConfig, u16SlaveAddress, u32SrcClockHz);
 *   LPI2C_SlaveInit(LPI2C1, &sConfig);
 * endcode
 *
 * After calling this function, override any settings  to customize the configuration,
 * prior to initializing the master driver with LPI2C_SlaveInit(). Be sure to override at least the
 * u8Address0 member of the configuration structure with the desired slave address.
 *
 * param psSlaveConfig User provided configuration structure that is set to default values. Refer to
 *      #lpi2c_slave_config_t.
 * param u16SlaveAddress Slave address raw value, driver will shift it.
 * param u32SrcClockHz Frequency in Hertz of the LPI2C functional clock. Used to calculate the filter widths,
 *      data valid delay, and clock hold time.
 */
void LPI2C_SlaveGetDefaultConfig(lpi2c_slave_config_t *psSlaveConfig, uint16_t u16SlaveAddress, uint32_t u32SrcClockHz)
{
    /* Initializes the configure structure to zero. */
    (void)memset(psSlaveConfig, 0, sizeof(*psSlaveConfig));

    psSlaveConfig->bEnableSlave               = true;
    psSlaveConfig->u16Address0                = u16SlaveAddress;
    psSlaveConfig->u16Address1                = 0U;
    psSlaveConfig->eAddressMatchMode          = (uint16_t)kLPI2C_Match7BitAddress0;
    psSlaveConfig->bFilterDozeEnable          = true;
    psSlaveConfig->bFilterEnable              = true;
    psSlaveConfig->bEnableGeneralCall         = false;
    psSlaveConfig->bEnableSmbusAlert          = false;
    psSlaveConfig->sSclStall.bEnableAck       = false;
    psSlaveConfig->sSclStall.bEnableTx        = true;
    psSlaveConfig->sSclStall.bEnableRx        = true;
    psSlaveConfig->sSclStall.bEnableAddress   = false;
    psSlaveConfig->bIgnoreAck                 = false;
    psSlaveConfig->bEnableReceivedAddressRead = false;
    psSlaveConfig->u32SdaGlitchFilterWidthNs  = 200U;
    psSlaveConfig->u32SclGlitchFilterWidthNs  = 200U;
    psSlaveConfig->u32DataValidDelayNs        = 0U;
    psSlaveConfig->u32ClockHoldTimeNs         = 0U;
    psSlaveConfig->u32SrcClockHz              = u32SrcClockHz;
}

/*!
 * brief Initializes the LPI2C slave peripheral.
 *
 * This function enables the peripheral clock and initializes the LPI2C slave peripheral as described by the user
 * provided configuration. User just needs to call this function to enable LPI2C slave if only use I2C slave operation.
 *
 * note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enabled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the
 * API.
 *
 * param base The LPI2C peripheral base address.
 * param psSlaveConfig User provided peripheral configuration. Use LPI2C_SlaveGetDefaultConfig() to get a set of
 * defaults that you can override.
 */
void LPI2C_SlaveInit(LPI2C_Type *base, const lpi2c_slave_config_t *psSlaveConfig)
{
    uint16_t u16TmpCycle;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)

    uint32_t u32Instance = LPI2C_GetInstance(base);

    /* Ungate the clock. */
    CLOCK_EnableClock(s_eLpi2cClocks[u32Instance]);
#if defined(LPI2C_PERIPH_CLOCKS)
    /* Ungate the functional clock in initialize function. */
    CLOCK_EnableClock(s_eLpi2cPeriphClocks[u32Instance]);
#endif

#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Restore to reset conditions. */
    LPI2C_SlaveReset(base);

    /* Configure peripheral. */
    base->SAMR0 = LPI2C_SAMR0_ADDR0(psSlaveConfig->u16Address0);
    base->SAMR1 = LPI2C_SAMR1_ADDR1(psSlaveConfig->u16Address1);

    base->SCFGR0 = LPI2C_SCFGR0_SAEN(psSlaveConfig->bEnableSmbusAlert) |
                   LPI2C_SCFGR0_IGNACK(psSlaveConfig->bIgnoreAck) |
                   LPI2C_SCFGR0_RXCFG(psSlaveConfig->bEnableReceivedAddressRead) |
                   LPI2C_SCFGR0_GCEN(psSlaveConfig->bEnableGeneralCall) |
                   LPI2C_SCFGR0_ACKSTALL(psSlaveConfig->sSclStall.bEnableAck) |
                   LPI2C_SCFGR0_TXDSTALL(psSlaveConfig->sSclStall.bEnableTx) |
                   LPI2C_SCFGR0_RXSTALL(psSlaveConfig->sSclStall.bEnableRx) |
                   LPI2C_SCFGR0_ADRSTALL(psSlaveConfig->sSclStall.bEnableAddress);

    base->SCFGR1 = LPI2C_SCFGR1_ADDRCFG(psSlaveConfig->eAddressMatchMode);

    u16TmpCycle =
        LPI2C_SCFGR2_DATAVD(LPI2C_GetCyclesForWidth(psSlaveConfig->u32SrcClockHz, psSlaveConfig->u32DataValidDelayNs,
                                                    (LPI2C_SCFGR2_DATAVD_MASK >> LPI2C_SCFGR2_DATAVD_SHIFT), 1U));

    base->SCFGR2 = u16TmpCycle | LPI2C_SCFGR2_CLKHOLD(LPI2C_GetCyclesForWidth(
                                     psSlaveConfig->u32SrcClockHz, psSlaveConfig->u32ClockHoldTimeNs,
                                     (LPI2C_SCFGR2_CLKHOLD_MASK >> LPI2C_SCFGR2_CLKHOLD_SHIFT), 1U));

    u16TmpCycle = LPI2C_SCFGR3_FILTSDA(
        LPI2C_GetCyclesForWidth(psSlaveConfig->u32SrcClockHz, psSlaveConfig->u32SdaGlitchFilterWidthNs,
                                (LPI2C_SCFGR3_FILTSDA_MASK >> LPI2C_SCFGR3_FILTSDA_SHIFT), 1U));
    u16TmpCycle |= LPI2C_SCFGR3_FILTSCL(
        LPI2C_GetCyclesForWidth(psSlaveConfig->u32SrcClockHz, psSlaveConfig->u32SclGlitchFilterWidthNs,
                                (LPI2C_SCFGR3_FILTSCL_MASK >> LPI2C_SCFGR3_FILTSCL_SHIFT), 1U));

    base->SCFGR3 = u16TmpCycle;

    /* Save SCR to last so we don't enable slave until it is configured */
    base->SCR = LPI2C_SCR_FILTDZ(psSlaveConfig->bFilterDozeEnable) | LPI2C_SCR_FILTEN(psSlaveConfig->bFilterEnable) |
                LPI2C_SCR_SEN(psSlaveConfig->bEnableSlave);
}

/*!
 * brief Deinitializes the LPI2C slave peripheral.
 *
 * This function disables the LPI2C slave peripheral and gates the clock. It also performs a software
 * reset to restore the peripheral to reset conditions.
 *
 * param base The LPI2C peripheral base address.
 */
void LPI2C_SlaveDeinit(LPI2C_Type *base)
{
    LPI2C_SlaveReset(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)

    uint32_t u32Instance = LPI2C_GetInstance(base);

    /* Gate the clock. */
    CLOCK_DisableClock(s_eLpi2cClocks[u32Instance]);

#if defined(LPI2C_PERIPH_CLOCKS)
    /* Gate the functional clock. */
    CLOCK_DisableClock(s_eLpi2cPeriphClocks[u32Instance]);
#endif

#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
/* --------------------------------------- End of Module Init/Deinit Sub-group -------------------------------------- */

/* ------------------------------------ Master Peripheral Configuration Sub-group ----------------------------------- */
/*!
 * brief Sets the I2C bus frequency for master transactions.
 *
 * The LPI2C master is automatically disabled and re-enabled as necessary to configure the baud
 * rate. Do not call this function during a transfer, or the transfer is aborted.
 *
 * note Please note that the second parameter is the clock frequency of LPI2C module, the third
 * parameter means user configured bus baudrate, this implementation is different from other I2C drivers
 * which use baudrate configuration as second parameter and source clock frequency as third parameter.
 *
 * param base The LPI2C peripheral base address.
 * param u32SrcClockHz LPI2C functional clock frequency in Hertz.
 * param u32BaudRateBps Requested bus frequency in Hertz.
 */
void LPI2C_MasterSetBaudRate(LPI2C_Type *base, uint32_t u32SrcClockHz, uint32_t u32BaudRateBps)
{
    bool bWasEnabled;
    uint8_t u8FiltScl;
    uint8_t u8Divider     = 1U;
    uint8_t u8BestDivider = 1U;
    uint8_t u8Prescale    = 0U;
    uint8_t u8BestPre     = 0U;
    uint8_t u8ClkCycle;
    uint8_t u8BestClkCycle = 0U;
    uint32_t u32AbsBps     = 0U;
    uint32_t u32BestBps    = 0xffffffffUL;
    uint32_t u32ComputedRate;
    uint16_t u16TmpReg = 0U;

    /* Disable master mode. */
    bWasEnabled = (0U != ((base->MCR & LPI2C_MCR_MEN_MASK) >> LPI2C_MCR_MEN_SHIFT));
    LPI2C_MasterEnable(base, false);

    u8FiltScl = (uint8_t)((base->MCFGR3 & LPI2C_MCFGR3_FILTSCL_MASK) >> LPI2C_MCFGR3_FILTSCL_SHIFT);

    /* Baud rate = (sourceClock_Hz / 2 ^ prescale) / (CLKLO + 1 + CLKHI + 1 + SCL_LATENCY)
     * SCL_LATENCY = ROUNDDOWN((2 + FILTSCL) / (2 ^ prescale))
     */
    for (u8Prescale = 0U; u8Prescale <= 7U; u8Prescale++)
    {
        /* Calculate the clkCycle, clkCycle = CLKLO + CLKHI, divider = 2 ^ prescale */
        u8ClkCycle = (uint8_t)((10U * u32SrcClockHz / u8Divider / u32BaudRateBps + 5U) / 10U -
                               (2U + u8FiltScl) / u8Divider - 2U);
        /* The max value for CLKLO + CLKHI is 63 + 63 = 126 */
        if (u8ClkCycle > 126U)
        {
            u8Divider *= 2U;
            continue;
        }
        /* Calculate the computed baudrate and compare it with the desired baudrate */
        u32ComputedRate = (u32SrcClockHz / (uint32_t)u8Divider) /
                          ((uint32_t)u8ClkCycle + 2U + (2U + (uint32_t)u8FiltScl) / (uint32_t)u8Divider);
        u32AbsBps =
            u32BaudRateBps > u32ComputedRate ? u32BaudRateBps - u32ComputedRate : u32ComputedRate - u32BaudRateBps;
        if (u32AbsBps < u32BestBps)
        {
            u8BestPre      = u8Prescale;
            u8BestDivider  = u8Divider;
            u8BestClkCycle = u8ClkCycle;
            u32BestBps     = u32AbsBps;

            /* If the error is 0, then we can stop searching because we won't find a better match. */
            if (u32AbsBps == 0U)
            {
                break;
            }
        }
        u8Divider *= 2U;
    }

    /* SCL low time tLO should be larger than or equal to SCL high time tHI,
       tLO = (CLKLO + 1) x (2 ^ PRESCALE), tHI = (CLKHI + 1 + SCL_LATENCY) x (2 ^ PRESCALE), in this case
       CLKLO should be larger than CLKHI + (2U + filtScl) / bestDivider */
    uint8_t u8TmpHigh = (u8ClkCycle - (2U + u8FiltScl) / u8BestDivider - 1U) / 2U;

    /* Calculate DATAVD and SETHOLD.
       To meet the timing requirement of I2C spec for standard mode, fast mode and fast mode plus,
       the min tHD:STA should be at least 0.4 times of the SCL clock cycle, use 0.5 to be safe,
       the max tVD:DAT/tVD:ACK/tHD:DAT should be at most 0.345 times of the SCL clock cycle, use 0.25 to be safe. */
    /* tHD:STA = (SETHOLD + 1) x (2 ^ PRESCALE) x LPI2C clock source cycles. */
    uint8_t u8TmpHold = (uint8_t)(u32SrcClockHz / u32BaudRateBps / u8BestDivider / 2U) - 1U;
    /* tVD:DAT/tVD:ACK/tHD:DAT = (DATAVD + 1) x (2 ^ PRESCALE) x LPI2C clock source cycles. */
    uint8_t u8TmpDataVd = (uint8_t)(u32SrcClockHz / u32BaudRateBps / u8BestDivider / 4U) - 1U;

    /* Set CLKHI, CLKLO, SETHOLD, DATAVD value. */
    u16TmpReg   = LPI2C_MCCR0_CLKHI(u8TmpHigh) | LPI2C_MCCR0_CLKLO((uint16_t)u8BestClkCycle - (uint16_t)u8TmpHigh);
    base->MCCR0 = u16TmpReg;
    u16TmpReg   = LPI2C_MCCR1_SETHOLD(u8TmpHold) | LPI2C_MCCR1_DATAVD(u8TmpDataVd);
    base->MCCR1 = u16TmpReg;

    /* Set PRESCALE value. */
    base->MCFGR1 = (base->MCFGR1 & ~LPI2C_MCFGR1_PRESCALE_MASK) | LPI2C_MCFGR1_PRESCALE(u8BestPre);

    /* Restore master mode. */
    if (bWasEnabled)
    {
        LPI2C_MasterEnable(base, true);
    }
}

/*!
 * brief Sets the LPI2C master glitch filter width.
 *
 * After the LPI2C module is initialized as master, user can call this function to change the glitch filter width.
 *
 * param base The LPI2C peripheral base address.
 * param u32SdaFilterWidthNs The SDA glitch filter length in nano seconds.
 * param u32SclFilterWidthNs The SCL glitch filter length in nano seconds.
 * param u32SrcClockHz LPI2C peripheral clock frequency in Hz
 */
void LPI2C_MasterSetGlitchFilter(LPI2C_Type *base,
                                 uint32_t u32SdaFilterWidthNs,
                                 uint32_t u32SclFilterWidthNs,
                                 uint32_t u32SrcClockHz)
{
    uint16_t u16Cycles;
    uint16_t u16Cfgr3;

    /* Disable master mode. */
    bool bWasEnabled = (0U != ((base->MCR & LPI2C_MCR_MEN_MASK) >> LPI2C_MCR_MEN_SHIFT));
    LPI2C_MasterEnable(base, false);

    u16Cfgr3 = base->MCFGR3;
    u16Cfgr3 &= ~LPI2C_MCFGR3_FILTSDA_MASK;
    u16Cfgr3 &= ~LPI2C_MCFGR3_FILTSCL_MASK;
    u16Cycles = LPI2C_GetCyclesForWidth(u32SrcClockHz, u32SdaFilterWidthNs,
                                        (LPI2C_MCFGR3_FILTSDA_MASK >> LPI2C_MCFGR3_FILTSDA_SHIFT), 1U);
    u16Cfgr3 |= LPI2C_MCFGR3_FILTSDA(u16Cycles);
    u16Cycles = LPI2C_GetCyclesForWidth(u32SrcClockHz, u32SclFilterWidthNs,
                                        (LPI2C_MCFGR3_FILTSCL_MASK >> LPI2C_MCFGR3_FILTSCL_SHIFT), 1U);
    u16Cfgr3 |= LPI2C_MCFGR3_FILTSCL(u16Cycles);
    base->MCFGR3 = u16Cfgr3;

    /* Restore master mode. */
    if (bWasEnabled)
    {
        LPI2C_MasterEnable(base, true);
    }
}

/*!
 * brief Configures LPI2C master data match feature.
 *
 * param base The LPI2C peripheral base address.
 * param psConfig Settings for the data match feature.
 */
void LPI2C_MasterSetDataMatch(LPI2C_Type *base, const lpi2c_data_match_config_t *psConfig)
{
    /* Disable master mode. */
    bool bWasEnabled = (0U != ((base->MCR & LPI2C_MCR_MEN_MASK) >> LPI2C_MCR_MEN_SHIFT));
    LPI2C_MasterEnable(base, false);

    base->MCFGR1 = (base->MCFGR1 & ~LPI2C_MCFGR1_MATCFG_MASK) | LPI2C_MCFGR1_MATCFG(psConfig->eMatchMode);
    base->MCFGR0 = (base->MCFGR0 & ~LPI2C_MCFGR0_RDMO_MASK) | LPI2C_MCFGR0_RDMO(psConfig->bRxDataMatchOnly);
    base->MDMR   = LPI2C_MDMR_MATCH0(psConfig->u8Match0) | LPI2C_MDMR_MATCH1(psConfig->u8Match1);

    /* Restore master mode. */
    if (bWasEnabled)
    {
        LPI2C_MasterEnable(base, true);
    }
}
/* -------------------------------- End of Master Peripheral Configuration Sub-group ------------------------------ */

/* ------------------------------------ Slave Peripheral Configuration Sub-group ---------------------------------- */
/*!
 * brief Sets the LPI2C slave glitch filter width.
 *
 * After the LPI2C module is initialized as slave, user can call this function to change the glitch filter width.
 *
 * param base The LPI2C peripheral base address.
 * param u32SdaFilterWidthNs The SDA glitch filter length in nano seconds.
 * param u32SclFilterWidthNs The SCL glitch filter length in nano seconds.
 * param u32SrcClockHz LPI2C peripheral clock frequency in Hz
 */
void LPI2C_SlaveSetGlitchFilter(LPI2C_Type *base,
                                uint32_t u32SdaFilterWidthNs,
                                uint32_t u32SclFilterWidthNs,
                                uint32_t u32SrcClockHz)
{
    uint16_t u16Cycles;
    uint16_t u16Cfgr3;

    /* Disable slave mode. */
    bool bWasEnabled = (0U != ((base->SCR & LPI2C_SCR_SEN_MASK) >> LPI2C_SCR_SEN_SHIFT));
    LPI2C_SlaveEnable(base, false);

    u16Cfgr3 = base->SCFGR3;
    u16Cfgr3 &= ~LPI2C_SCFGR3_FILTSDA_MASK;
    u16Cfgr3 &= ~LPI2C_SCFGR3_FILTSCL_MASK;
    u16Cycles = LPI2C_GetCyclesForWidth(u32SrcClockHz, u32SdaFilterWidthNs,
                                        (LPI2C_SCFGR3_FILTSDA_MASK >> LPI2C_SCFGR3_FILTSDA_SHIFT), 1U);
    u16Cfgr3 |= LPI2C_SCFGR3_FILTSDA(u16Cycles);
    u16Cycles = LPI2C_GetCyclesForWidth(u32SrcClockHz, u32SclFilterWidthNs,
                                        (LPI2C_SCFGR3_FILTSCL_MASK >> LPI2C_SCFGR3_FILTSCL_SHIFT), 1U);
    u16Cfgr3 |= LPI2C_SCFGR3_FILTSCL(u16Cycles);
    base->SCFGR3 = u16Cfgr3;

    /* Restore slave mode. */
    if (bWasEnabled)
    {
        LPI2C_SlaveEnable(base, true);
    }
}

/*!
 * brief Configure the slave addressing mode.
 *
 * After the LPI2C module is initialized as slave, user can call this function to change the configuration of slave
 * addressing mode.
 *
 * param base The LPI2C peripheral base address.
 * param eAddressMatchMode The slave addressing match mode.
 * param u16Address0 LPI2C slave address 0. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * param u16Address1 LPI2C slave address 1. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 */
void LPI2C_SlaveSetAddressingMode(LPI2C_Type *base,
                                  lpi2c_slave_address_match_t eAddressMatchMode,
                                  uint16_t u16Address0,
                                  uint16_t u16Address1)
{
    /* Disable slave mode. */
    bool bWasEnabled = (0U != ((base->SCR & LPI2C_SCR_SEN_MASK) >> LPI2C_SCR_SEN_SHIFT));
    LPI2C_SlaveEnable(base, false);

    base->SCFGR1 = LPI2C_SCFGR1_ADDRCFG(eAddressMatchMode);
    base->SAMR0  = LPI2C_SAMR0_ADDR0(u16Address0);
    base->SAMR1  = LPI2C_SAMR1_ADDR1(u16Address1);

    /* Restore slave mode. */
    if (bWasEnabled)
    {
        LPI2C_SlaveEnable(base, true);
    }
}
/* ------------------------------ End of Slave Peripheral Configuration Sub-group ----------------------------- */

/* ------------------------------------- Master Bus operations Sub-Group -------------------------------------- */
/*!
 * @brief Convert provided flags to status code, and clear any errors if present.
 * @param base The LPI2C peripheral base address.
 * @param u16Status Current status flags value that will be checked.
 * @retval #kStatus_Success
 * @retval #kStatus_LPI2C_PinLowTimeout
 * @retval #kStatus_LPI2C_ArbitrationLost
 * @retval #kStatus_LPI2C_Nak
 * @retval #kStatus_LPI2C_FifoError
 */
/* Not static so it can be used from fsl_lpi2c_edma.c. */
status_t LPI2C_MasterCheckAndClearError(LPI2C_Type *base, uint16_t u16Status)
{
    status_t result = kStatus_Success;

    /* Check for error. These errors cause a stop to automatically be sent. We must */
    /* clear the errors before a new transfer can start. */
    u16Status &= (uint16_t)kLPI2C_MasterErrorInterruptFlags;
    if (0U != u16Status)
    {
        /* Select the correct error code. Ordered by severity, with bus issues first. */
        if (0U != (u16Status & (uint16_t)kLPI2C_MasterPinLowTimeoutInterruptFlag))
        {
            result = kStatus_LPI2C_PinLowTimeout;
        }
        else if (0U != (u16Status & (uint16_t)kLPI2C_MasterArbitrationLostInterruptFlag))
        {
            result = kStatus_LPI2C_ArbitrationLost;
        }
        else if (0U != (u16Status & (uint16_t)kLPI2C_MasterNackDetectInterruptFlag))
        {
            result = kStatus_LPI2C_Nak;
        }
        else if (0U != (u16Status & (uint16_t)kLPI2C_MasterFifoErrInterruptFlag))
        {
            result = kStatus_LPI2C_FifoError;
        }
        else
        {
            ; /* Intentional empty */
        }

        /* Clear the flags. */
        LPI2C_MasterClearStatusFlags(base, u16Status);

        /* Reset fifos. These flags clear automatically. */
        base->MCR |= LPI2C_MCR_RRF_MASK | LPI2C_MCR_RTF_MASK;
    }
    else
    {
        ; /* Intentional empty */
    }

    return result;
}

/*!
 * @brief Make sure the bus isn't already busy.
 *
 * A busy bus is allowed if we are the one driving it.
 *
 * @param base The LPI2C peripheral base address.
 * @retval #kStatus_Success
 * @retval #kStatus_LPI2C_Busy
 */
/* Not static so it can be used from fsl_lpi2c_edma.c. */
status_t LPI2C_MasterCheckForBusyBus(LPI2C_Type *base)
{
    status_t ret = kStatus_Success;

    uint16_t u16Status = LPI2C_MasterGetStatusFlags(base);
    if ((0U != (u16Status & (uint16_t)kLPI2C_MasterBusBusyFlag)) &&
        (0U == (u16Status & (uint16_t)kLPI2C_MasterBusyFlag)))
    {
        ret = kStatus_LPI2C_Busy;
    }

    return ret;
}

/*!
 * brief Sends a START signal and slave address on the I2C bus.
 *
 * This function is used to initiate a new master mode transfer. First, the bus state is checked to ensure
 * that another master is not occupying the bus. Then a START signal is transmitted, followed by the
 * 7-bit address specified in the a address parameter. Note that this function does not actually wait
 * until the START and address are successfully sent on the bus before returning.
 *
 * param base The LPI2C peripheral base address.
 * param u8Address 7-bit slave device address, in bits [6:0].
 * param eDir Master transfer direction, either #kLPI2C_Read or #kLPI2C_Write. This parameter is used to set
 *      the R/w bit (bit 0) in the transmitted slave address.
 * param bIsRepeatedStart The bool logic for repeated START or START, repeated START won't reset PEC value.
 * retval #kStatus_Success START signal and address were successfully enqueued in the transmit FIFO.
 * retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 */
status_t LPI2C_MasterStartInternal(LPI2C_Type *base,
                                   uint8_t u8Address,
                                   lpi2c_data_direction_t eDir,
                                   bool bIsRepeatedStart)
{
    status_t result;
    uint8_t startByte;

    /* Return an error if the bus is already in use not by us. */
    result = LPI2C_MasterCheckForBusyBus(base);
    if (kStatus_Success != result)
    {
        return result;
    }

    /* Clear all flags. */
    LPI2C_MasterClearStatusFlags(base, (uint16_t)kLPI2C_MasterClearInterruptFlags);

    /* Turn off auto-stop option. */
    base->MCFGR1 &= ~LPI2C_MCFGR1_AUTOSTOP_MASK;

    /* Wait until there is room in the fifo. */
    result = LPI2C_MasterWaitForTxReady(base);
    if (kStatus_Success != result)
    {
        return result;
    }

    /* Issue start command. */
    startByte  = (uint8_t)(((uint16_t)u8Address << 1U) | (uint16_t)eDir);
    base->MTDR = (uint16_t)kStartCmd | (uint16_t)startByte;

#if I2C_SMBUS_ENABLE
    /* PEC is caculated from the first START. */
    if (!bIsRepeatedStart)
    {
        s_u8MasterCrcValue = 0U;
    }
    LPI2C_UpdateCrc8(&s_u8MasterCrcValue, &startByte, 1U);
#endif

    return kStatus_Success;
}

/*!
 * brief Sends a STOP signal on the I2C bus.
 *
 * This function does not return until the STOP signal is seen on the bus, or an error occurs.
 *
 * param base The LPI2C peripheral base address.
 * retval #kStatus_Success The STOP signal was successfully sent on the bus and the transaction terminated.
 * retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * retval #kStatus_LPI2C_FifoError FIFO under run or overrun.
 * retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterStop(LPI2C_Type *base)
{
    /* Wait until there is room in the fifo. */
    status_t result = LPI2C_MasterWaitForTxReady(base);
    if (kStatus_Success != result)
    {
        return result;
    }

#if I2C_SMBUS_ENABLE
    /* Reset the PEC value. */
    s_u8MasterCrcValue = 0U;
#endif

    /* Send the STOP signal */
    base->MTDR = (uint16_t)kStopCmd;

/* Wait for the stop detected flag to set, indicating the transfer has completed on the bus. */
/* Also check for errors while waiting. */
#if I2C_RETRY_TIMES
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
#endif

#if I2C_RETRY_TIMES
    while ((result == kStatus_Success) && (0U != --u32WaitTimes))
#else
    while (result == kStatus_Success)
#endif
    {
        uint16_t u16Status = LPI2C_MasterGetStatusFlags(base);

        /* Check for error flags. */
        result = LPI2C_MasterCheckAndClearError(base, u16Status);

        /* Check if the stop was sent successfully. */
        if ((0U != (u16Status & (uint16_t)kLPI2C_MasterStopDetectInterruptFlag)) &&
            (0U != (u16Status & (uint16_t)kLPI2C_MasterTxReadyInterruptFlag)))
        {
            LPI2C_MasterClearStatusFlags(base, (uint16_t)kLPI2C_MasterStopDetectInterruptFlag);
            break;
        }
    }

#if I2C_RETRY_TIMES
    if (0U == u32WaitTimes)
    {
        return kStatus_LPI2C_Timeout;
    }
#endif

    return result;
}

/*!
 * brief Performs a polling send transfer on the I2C bus.
 *
 * Sends up to a txSize number of bytes to the previously addressed slave device. The slave may
 * reply with a NAK to any byte in order to terminate the transfer early. If this happens, this
 * function returns #kStatus_LPI2C_Nak.
 *
 * param base  The LPI2C peripheral base address.
 * param pTxBuff The pointer to the data to be transferred.
 * param u16TxSize The length in bytes of the data to be transferred.
 * param bPecEnable It decides whether one byte PEC is needed to send.
 *
 * retval #kStatus_Success Data was sent successfully.
 * retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * retval #kStatus_LPI2C_FifoError FIFO under run or over run.
 * retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterSend(LPI2C_Type *base, void *pTxBuff, uint16_t u16TxSize, bool bPecEnable)
{
    uint8_t *pu8Buf = (uint8_t *)pTxBuff;

    assert(NULL != pTxBuff);

    status_t result = kStatus_Success;

    /* Send data buffer */
    while (0U != (u16TxSize--))
    {
        /* Wait until there is room in the fifo. This also checks for errors. */
        result = LPI2C_MasterWaitForTxReady(base);
        if (kStatus_Success != result)
        {
            return result;
        }

        /* Write byte into LPI2C master data register. */
        base->MTDR = *pu8Buf++;
    }
#if I2C_SMBUS_ENABLE
    uint16_t u16TxCount;

    if (bPecEnable)
    {
        LPI2C_UpdateCrc8(&s_u8MasterCrcValue, pTxBuff, u16TxSize);

        result = LPI2C_MasterWaitForTxReady(base);
        if (kStatus_Success != result)
        {
            return result;
        }

        /* Add the PEC data after all vaild data. */
        base->MTDR = s_u8MasterCrcValue;
        /* Check whether last byte gets Nack indicated PEC mismatch. */
        while (1)
        {
            LPI2C_MasterGetFifoCounts(base, NULL, &u16TxCount);
            result = LPI2C_MasterWaitForTxReady(base);
            if ((kStatus_Success != result) || (0U == u16TxCount))
            {
                /* Check fifo counts again to ensure the result is last sent out byte's. */
                LPI2C_MasterGetFifoCounts(base, NULL, &u16TxCount);
                if ((0U == u16TxCount) && (kStatus_LPI2C_Nak == result))
                {
                    result = kStatus_LPI2C_Pec_Error;
                }
                break;
            }
        }
    }
#endif

    return result;
}

/*!
 * brief Performs a polling receive transfer on the I2C bus.
 *
 * param base  The LPI2C peripheral base address.
 * param pRxBuff The pointer to the data to be transferred.
 * param u16RxSize The length in bytes of the data to be transferred.
 * param bPecEnable It decides whether one byte PEC is needed to receive.
 *
 * retval #kStatus_Success Data was received successfully.
 * retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * retval #kStatus_LPI2C_FifoError FIFO under run or overrun.
 * retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterReceive(LPI2C_Type *base, void *pRxBuff, uint16_t u16RxSize, bool bPecEnable)
{
    status_t result;
    uint8_t *pu8Buf;
#if I2C_RETRY_TIMES
    uint32_t u32WaitTimes;
#endif

    assert(NULL != pRxBuff);

    /* Handle empty read. */
    if (u16RxSize == 0U)
    {
        return kStatus_Success;
    }

    /* Wait until there is room in the command fifo. */
    result = LPI2C_MasterWaitForTxReady(base);
    if (kStatus_Success != result)
    {
        return result;
    }

#if I2C_SMBUS_ENABLE
    if (bPecEnable)
    {
        assert(u16RxSize < UINT16_MAX);
        /* Receive one more byte for PEC */
        u16RxSize++;
    }
#endif

    /* Issue command to receive data. */
    base->MTDR = ((uint16_t)kRxDataCmd) | LPI2C_MTDR_DATA(u16RxSize - 1U);

    /* Receive data */
    pu8Buf = (uint8_t *)pRxBuff;
    while (0U != (u16RxSize--))
    {
#if I2C_RETRY_TIMES
        u32WaitTimes = I2C_RETRY_TIMES;
#endif
        /* Read LPI2C receive fifo register. The register includes a flag to indicate whether */
        /* the FIFO is empty, so we can both get the data and check if we need to keep reading */
        /* using a single register read. */
        uint16_t value;
        do
        {
            /* Check for errors. */
            result = LPI2C_MasterCheckAndClearError(base, LPI2C_MasterGetStatusFlags(base));
            if (kStatus_Success != result)
            {
                return result;
            }

            value = base->MRDR;
#if I2C_RETRY_TIMES
        } while ((0U != (value & LPI2C_MRDR_RXEMPTY_MASK)) && (0U != --u32WaitTimes));
        if (0U == u32WaitTimes)
        {
            return kStatus_LPI2C_Timeout;
        }
#else
        } while (0U != (value & LPI2C_MRDR_RXEMPTY_MASK));
#endif

#if I2C_SMBUS_ENABLE
        if (bPecEnable && (u16RxSize == 0U))
        {
            /* Updated the PEC value and compare with the received one. */
            LPI2C_UpdateCrc8(&s_u8MasterCrcValue, (uint8_t *)pRxBuff, u16RxSize);
            if (s_u8MasterCrcValue != (uint8_t)(value & LPI2C_MRDR_DATA_MASK))
            {
                return kStatus_LPI2C_Pec_Error;
            }
            else
            {
                break;
            }
        }
#endif

        *pu8Buf++ = (uint8_t)(value & LPI2C_MRDR_DATA_MASK);
    }

    return kStatus_Success;
}
/* ------------------------------ End of Master Peripheral Configuration Sub-group ----------------------------- */

/* --------------------------------------- Slave Bus operations Sub-Group -------------------------------------- */
/*!
 * brief Performs a polling send transfer on the I2C bus.
 *
 * param base  The LPI2C peripheral base address.
 * param pTxBuff The pointer to the data to be transferred.
 * param u16TxSize The length in bytes of the data to be transferred.
 * param pu16ActualTxSize
 * return Error or success status returned by API.
 */
status_t LPI2C_SlaveSend(LPI2C_Type *base, void *pTxBuff, uint16_t u16TxSize, uint16_t *pu16ActualTxSize)
{
    uint8_t *pu8Buf       = (uint8_t *)pTxBuff;
    uint16_t u16Remaining = u16TxSize;

    assert(NULL != pTxBuff);

#if I2C_RETRY_TIMES
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
#endif

    /* Clear stop flag. */
    LPI2C_SlaveClearStatusFlags(
        base, (uint16_t)kLPI2C_SlaveStopDetectInterruptFlag | (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag);

    while (0U != u16Remaining)
    {
        uint16_t flags;
        status_t result;

        /* Wait until we can transmit. */
        do
        {
            /* Check for errors */
            flags  = LPI2C_SlaveGetStatusFlags(base);
            result = LPI2C_SlaveCheckAndClearError(base, flags);
            if (kStatus_Success != result)
            {
                if (NULL != pu16ActualTxSize)
                {
                    *pu16ActualTxSize = u16TxSize - u16Remaining;
                }
                return result;
            }
#if I2C_RETRY_TIMES
        } while ((0U == (flags & ((uint16_t)kLPI2C_SlaveTxReadyFlag | (uint16_t)kLPI2C_SlaveStopDetectFlag |
                                  (uint16_t)kLPI2C_SlaveRepeatedStartDetectFlag))) &&
                 (0U != --u32WaitTimes));
        if (0U == u32WaitTimes)
        {
            return kStatus_LPI2C_Timeout;
        }
#else
        } while (0U ==
                 (flags & ((uint16_t)kLPI2C_SlaveTxReadyInterruptFlag | (uint16_t)kLPI2C_SlaveStopDetectInterruptFlag |
                           (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag)));
#endif

        /* Send a byte. */
        if (0U != (flags & (uint16_t)kLPI2C_SlaveTxReadyInterruptFlag))
        {
            base->STDR = *pu8Buf++;
            --u16Remaining;
        }

        /* Exit loop if we see a stop or restart in transfer*/
        if ((0U != (flags & ((uint16_t)kLPI2C_SlaveStopDetectInterruptFlag |
                             (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag))) &&
            (u16Remaining != 0U))
        {
            LPI2C_SlaveClearStatusFlags(base, (uint16_t)kLPI2C_SlaveStopDetectInterruptFlag |
                                                  (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag);
            break;
        }
    }

    if (NULL != pu16ActualTxSize)
    {
        *pu16ActualTxSize = u16TxSize - u16Remaining;
    }

    return kStatus_Success;
}

/*!
 * brief Performs a polling receive transfer on the I2C bus.
 *
 * param base  The LPI2C peripheral base address.
 * param pRxBuff The pointer to the data to be transferred.
 * param u16RxSize The length in bytes of the data to be transferred.
 * param pu16ActualRxSize
 * return Error or success status returned by API.
 */
status_t LPI2C_SlaveReceive(LPI2C_Type *base, void *pRxBuff, uint16_t u16RxSize, uint16_t *pu16ActualRxSize)
{
    uint8_t *pu8Buf       = (uint8_t *)pRxBuff;
    uint16_t u16Remaining = u16RxSize;

    assert(NULL != pRxBuff);

#if I2C_RETRY_TIMES
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
#endif

    /* Clear stop flag. */
    LPI2C_SlaveClearStatusFlags(
        base, (uint16_t)kLPI2C_SlaveStopDetectInterruptFlag | (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag);

    while (0U != u16Remaining)
    {
        uint16_t flags;
        status_t result;

        /* Wait until we can receive. */
        do
        {
            /* Check for errors */
            flags  = LPI2C_SlaveGetStatusFlags(base);
            result = LPI2C_SlaveCheckAndClearError(base, flags);
            if (kStatus_Success != result)
            {
                if (NULL != pu16ActualRxSize)
                {
                    *pu16ActualRxSize = u16RxSize - u16Remaining;
                }
                return result;
            }
#if I2C_RETRY_TIMES
        } while ((0U == (flags & ((uint16_t)kLPI2C_SlaveRxReadyFlag | (uint16_t)kLPI2C_SlaveStopDetectFlag |
                                  (uint16_t)kLPI2C_SlaveRepeatedStartDetectFlag))) &&
                 (0U != --u32WaitTimes));
        if (0U == u32WaitTimes)
        {
            return kStatus_LPI2C_Timeout;
        }
#else
        } while (0U ==
                 (flags & ((uint16_t)kLPI2C_SlaveRxReadyInterruptFlag | (uint16_t)kLPI2C_SlaveStopDetectInterruptFlag |
                           (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag)));
#endif

        /* Receive a byte. */
        if (0U != (flags & (uint16_t)kLPI2C_SlaveRxReadyInterruptFlag))
        {
            *pu8Buf++ = (uint8_t)(base->SRDR & LPI2C_SRDR_DATA_MASK);
            --u16Remaining;
        }

        /* Exit loop if we see a stop or restart */
        if ((0U != (flags & ((uint16_t)kLPI2C_SlaveStopDetectInterruptFlag |
                             (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag))) &&
            (u16Remaining != 0U))
        {
            LPI2C_SlaveClearStatusFlags(base, (uint16_t)kLPI2C_SlaveStopDetectInterruptFlag |
                                                  (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag);
            break;
        }
    }

    if (NULL != pu16ActualRxSize)
    {
        *pu16ActualRxSize = u16RxSize - u16Remaining;
    }

    return kStatus_Success;
}
/* --------------------------------- End of Slave Bus operations Sub-Group -------------------------------- */

/* --------------------------------------- Master Transfer Sub-group -------------------------------------- */
/*!
 * brief Performs a master polling transfer on the I2C bus.
 *
 * note The API does not return until the transfer succeeds or fails due
 * to error happens during transfer.
 *
 * param base The LPI2C peripheral base address.
 * param psTransfer Pointer to the transfer structure.
 * retval #kStatus_Success Data was received successfully.
 * retval #kStatus_LPI2C_Busy Another master is currently utilizing the bus.
 * retval #kStatus_LPI2C_Nak The slave device sent a NAK in response to a byte.
 * retval #kStatus_LPI2C_FifoError FIFO under run or overrun.
 * retval #kStatus_LPI2C_ArbitrationLost Arbitration lost error.
 * retval #kStatus_LPI2C_PinLowTimeout SCL or SDA were held low longer than the timeout.
 */
status_t LPI2C_MasterTransferBlocking(LPI2C_Type *base, lpi2c_master_transfer_t *psTransfer)
{
    status_t result = kStatus_Success;
    uint16_t u16CommandBuffer[7];
    uint8_t u8CmdCount = 0U;
    bool bPecEnable    = false;

    assert(NULL != psTransfer);
    assert(psTransfer->u8CommandSize <= (sizeof(u16CommandBuffer) - 2U));

    /* Return an error if the bus is already in use not by us. */
    result = LPI2C_MasterCheckForBusyBus(base);
    if (kStatus_Success != result)
    {
        return result;
    }

    /* Clear all flags. */
    LPI2C_MasterClearStatusFlags(base, (uint16_t)kLPI2C_MasterClearInterruptFlags);

    /* Turn off auto-stop option. */
    base->MCFGR1 &= ~LPI2C_MCFGR1_AUTOSTOP_MASK;

    lpi2c_data_direction_t eDirection = (0U != psTransfer->u8CommandSize) ? kLPI2C_Write : psTransfer->eDirection;
    if (0U == (psTransfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStartFlag))
    {
        u16CommandBuffer[u8CmdCount++] =
            (uint16_t)kStartCmd |
            (uint16_t)((uint16_t)((uint16_t)psTransfer->u8SlaveAddress << 1U) | (uint16_t)eDirection);

#if I2C_SMBUS_ENABLE
        /* Only reset Crc at the first START */
        if (0U == (psTransfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferRepeatedStartFlag))
        {
            s_u8MasterCrcValue = 0U;
        }
#endif
    }

    /* Command data if needed, MSB first. */
    if (0U != psTransfer->u8CommandSize)
    {
        uint8_t u8CommandRemaining = psTransfer->u8CommandSize;
        uint8_t *pu8Command        = psTransfer->pu8Command;
        while (0U != u8CommandRemaining--)
        {
            uint8_t u8CommandByte          = *pu8Command;
            u16CommandBuffer[u8CmdCount++] = u8CommandByte;
            pu8Command++;
        }
    }

    /* Reads need special handling. */
    if ((0U != psTransfer->u16DataSize) && (psTransfer->eDirection == kLPI2C_Read))
    {
        /* Need to send repeated start if switching directions to read. */
        if (eDirection == kLPI2C_Write)
        {
            u16CommandBuffer[u8CmdCount++] =
                (uint16_t)kStartCmd |
                (uint16_t)((uint16_t)((uint16_t)psTransfer->u8SlaveAddress << 1U) | (uint16_t)kLPI2C_Read);
        }
    }

    /* Send command buffer */
    uint8_t u8Index = 0U;
    while (0U != u8CmdCount--)
    {
        /* Wait until there is room in the fifo. This also checks for errors. */
        result = LPI2C_MasterWaitForTxReady(base);
        if (kStatus_Success != result)
        {
            return result;
        }

        /* Write byte into LPI2C master data register. */
        base->MTDR = u16CommandBuffer[u8Index];
#if I2C_SMBUS_ENABLE
        LPI2C_UpdateCrc8(&s_u8MasterCrcValue, (uint8_t *)&u16CommandBuffer[u8Index], 1);
#endif
        u8Index++;
    }

#if I2C_SMBUS_ENABLE
    if ((psTransfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStopFlag) == 0U)
    {
        bPecEnable = true;
    }
#endif

    /* Transmit data. */
    if ((psTransfer->eDirection == kLPI2C_Write) && (psTransfer->u16DataSize > 0U))
    {
        /* Send Data. */
        result = LPI2C_MasterSend(base, psTransfer->pData, psTransfer->u16DataSize, bPecEnable);
    }

    /* Receive Data. */
    if ((psTransfer->eDirection == kLPI2C_Read) && (psTransfer->u16DataSize > 0U))
    {
        result = LPI2C_MasterReceive(base, psTransfer->pData, psTransfer->u16DataSize, bPecEnable);
    }

    if (kStatus_Success != result)
    {
        return result;
    }

    if ((psTransfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStopFlag) == 0U)
    {
        result = LPI2C_MasterStop(base);
    }

    return result;
}

/*!
 * brief Creates a new handle for the LPI2C master non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the LPI2C_MasterTransferAbort() API shall be called.
 *
 *
 * note The function also enables the NVIC IRQ for the input LPI2C. Need to notice
 * that on some SoCs the LPI2C IRQ is connected to INTMUX, in this case user needs to
 * enable the associated INTMUX IRQ in application.
 *
 * param base The LPI2C peripheral base address.
 * param psHandle Pointer to the LPI2C master driver handle.
 * param pfCallback User provided pointer to the asynchronous callback function.
 * param pUserData User provided pointer to the application callback data.
 */
void LPI2C_MasterTransferCreateHandle(LPI2C_Type *base,
                                      lpi2c_master_transfer_handle_t *psHandle,
                                      lpi2c_master_transfer_callback_t pfCallback,
                                      void *pUserData)
{
    uint32_t u32Instance;

    assert(NULL != psHandle);

    /* Clear out the handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Look up instance number */
    u32Instance = LPI2C_GetInstance(base);

    /* Save base and instance. */
    psHandle->base                 = base;
    psHandle->pfCompletionCallback = pfCallback;
    psHandle->pUserData            = pUserData;

    /* Save this handle for IRQ use. */
    s_psLpi2cMasterHandle[u32Instance] = psHandle;

    /* Set irq handler. */
    s_pfLpi2cMasterIsr = LPI2C_MasterTransferHandleIRQ;

    /* Clear internal IRQ enables and enable NVIC IRQ. */
    LPI2C_MasterDisableInterrupts(base, (uint16_t)kLPI2C_MasterIrqFlags);

    /* Enable NVIC IRQ, this only enables the IRQ directly connected to the NVIC.
     In some cases the LPI2C IRQ is configured through INTMUX, user needs to enable
     INTMUX IRQ in application code. */
    (void)EnableIRQ(s_eLpi2cIrqs[u32Instance]);
}

/*!
 * @brief Prepares the transfer state machine and fills in the command buffer.
 * @param psHandle Master nonblocking driver handle.
 */
static void LPI2C_TransferInitStateMachine(lpi2c_master_transfer_handle_t *psHandle)
{
    lpi2c_master_transfer_t *psXfer = &psHandle->sTransfer;

    /* Handle no start option. */
    if (0U != (psXfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStartFlag))
    {
        if (psXfer->eDirection == kLPI2C_Read)
        {
            /* Need to issue read command first. */
            psHandle->u8State = (uint8_t)kIssueReadCommandState;
        }
        else
        {
            /* Start immediately in the data transfer state. */
            psHandle->u8State = (uint8_t)kTransferDataState;
        }

        psHandle->pu8Buf            = (uint8_t *)psXfer->pData;
        psHandle->u16RemainingBytes = (uint16_t)psXfer->u16DataSize;
    }
    else
    {
        uint16_t *cmd     = (uint16_t *)&psHandle->u16CommandBuffer;
        uint16_t cmdCount = 0U;

        /* Initial direction depends on whether command data was provided, and of course the actual */
        /* data transfer direction. */
        lpi2c_data_direction_t direction = (0U != psXfer->u8CommandSize) ? kLPI2C_Write : psXfer->eDirection;

        /* Start command. */
        cmd[cmdCount++] =
            (uint16_t)kStartCmd | (uint16_t)((uint16_t)((uint16_t)psXfer->u8SlaveAddress << 1U) | (uint16_t)direction);

        /* Command data if needed, MSB first. */
        if (0U != psXfer->u8CommandSize)
        {
            uint8_t u8CommandRemaining = psXfer->u8CommandSize;
            uint8_t *pu8Command        = psXfer->pu8Command;
            while (0U != (u8CommandRemaining--))
            {
                uint8_t u8CommandByte = *pu8Command;
                cmd[cmdCount++]       = u8CommandByte;
                pu8Command++;
            }
        }

        /* Reads need special handling. */
        if ((0U != psXfer->u16DataSize) && (psXfer->eDirection == kLPI2C_Read))
        {
            /* Need to send repeated start if switching directions to read. */
            if (direction == kLPI2C_Write)
            {
                cmd[cmdCount++] = (uint16_t)kStartCmd | (uint16_t)((uint16_t)((uint16_t)psXfer->u8SlaveAddress << 1U) |
                                                                   (uint16_t)kLPI2C_Read);
            }

            /* Read command. */
            cmd[cmdCount++] = (uint16_t)((uint16_t)kRxDataCmd | LPI2C_MTDR_DATA(psXfer->u16DataSize - 1U));
        }

        /* Set up state machine for transferring the commands. */
        psHandle->u8State           = (uint8_t)kSendCommandState;
        psHandle->u16RemainingBytes = (uint16_t)cmdCount;
        psHandle->pu8Buf            = (uint8_t *)&psHandle->u16CommandBuffer;
    }
}

/*!
 * @brief Execute states until FIFOs are exhausted.
 * @param psHandle Master nonblocking driver handle.
 * @param bIsDone Set to true if the transfer has completed.
 * @retval #kStatus_Success
 * @retval #kStatus_LPI2C_PinLowTimeout
 * @retval #kStatus_LPI2C_ArbitrationLost
 * @retval #kStatus_LPI2C_Nak
 * @retval #kStatus_LPI2C_FifoError
 */
static status_t LPI2C_MasterTransferRunStateMachine(lpi2c_master_transfer_handle_t *psHandle, bool *bIsDone)
{
    uint16_t u16Status;
    status_t result = kStatus_Success;
    lpi2c_master_transfer_t *psXfer;
    uint16_t u16TxCount;
    uint16_t u16RxCount;
    uint16_t txFifoSize = (uint16_t)FSL_FEATURE_LPI2C_FIFO_SIZEn(base);
    bool bStateComplete = false;
    uint16_t u16Sendval;
    LPI2C_Type *base = psHandle->base;
#if I2C_SMBUS_ENABLE
    bool bPecAck = true;
#endif

    /* Set default bIsDone return value. */
    *bIsDone = false;

    /* Check for errors. */
    u16Status = LPI2C_MasterGetStatusFlags(base);
    /* For the last byte, nack flag is expected.
       Do not check and clear kLPI2C_MasterNackDetectFlag for the last byte,
       in case FIFO is emptied when stop command has not been sent. */
    if (psHandle->u16RemainingBytes == 0U)
    {
        u16Status &= ~(uint16_t)kLPI2C_MasterNackDetectInterruptFlag;
    }
    result = LPI2C_MasterCheckAndClearError(base, u16Status);
    if (kStatus_Success != result)
    {
        return result;
    }

    /* Get pointer to private data. */
    psXfer = &psHandle->sTransfer;

    /* Get fifo counts and compute room in tx fifo. */
    LPI2C_MasterGetFifoCounts(base, &u16RxCount, &u16TxCount);
    u16TxCount = txFifoSize - u16TxCount;

    while (!bStateComplete)
    {
        /* Execute the state. */
        switch (psHandle->u8State)
        {
            case (uint8_t)kSendCommandState:
                /* Make sure there is room in the tx fifo for the next command. */
                if (0U == u16TxCount--)
                {
                    bStateComplete = true;
                    break;
                }

                /* Issue command. buf is a uint8_t* pointing at the uint16 command array. */
                u16Sendval = ((uint16_t)(*psHandle->pu8Buf)) | ((uint16_t)(*(psHandle->pu8Buf + 1U)) << 8U);
                base->MTDR = u16Sendval;
                psHandle->pu8Buf++;
                psHandle->pu8Buf++;
#if I2C_SMBUS_ENABLE
                if (((u16Sendval >> 8) & 0xFFU) == kTxDataCmd)
                {
                    LPI2C_UpdateCrc8(&s_u8MasterCrcValue, (uint8_t *)&u16Sendval, 1);
                }
#endif
                /* Count down until all commands are sent. */
                if (--psHandle->u16RemainingBytes == 0U)
                {
                    /* Choose next state and set up buffer pointer and count. */
                    if (0U != psXfer->u16DataSize)
                    {
                        /* Either a send or receive transfer is next. */
                        psHandle->u8State           = (uint8_t)kTransferDataState;
                        psHandle->pu8Buf            = (uint8_t *)psXfer->pData;
                        psHandle->u16RemainingBytes = (uint16_t)psXfer->u16DataSize;
                        if (psXfer->eDirection == kLPI2C_Read)
                        {
                            /* Disable TX interrupt */
                            LPI2C_MasterDisableInterrupts(base, (uint16_t)kLPI2C_MasterTxReadyInterruptFlag);
                        }
                    }
                    else
                    {
                        /* No transfer, so move to stop state. */
                        psHandle->u8State = (uint8_t)kStopState;
                    }
                }
                break;

            case (uint8_t)kIssueReadCommandState:
                /* Make sure there is room in the tx fifo for the read command. */
                if (0U == u16TxCount--)
                {
                    bStateComplete = true;
                    break;
                }

                base->MTDR = (uint16_t)kRxDataCmd | LPI2C_MTDR_DATA(psXfer->u16DataSize - 1U);

                /* Move to transfer state. */
                psHandle->u8State = (uint8_t)kTransferDataState;
                if (psXfer->eDirection == kLPI2C_Read)
                {
                    /* Disable TX interrupt */
                    LPI2C_MasterDisableInterrupts(base, (uint16_t)kLPI2C_MasterTxReadyInterruptFlag);
                }
                break;

            case (uint8_t)kTransferDataState:
                if (psXfer->eDirection == kLPI2C_Write)
                {
                    /* Make sure there is room in the tx fifo. */
                    if (0U == u16TxCount--)
                    {
                        bStateComplete = true;
                        break;
                    }

                    /* Put byte to send in fifo. */
                    base->MTDR = *(psHandle->pu8Buf)++;
                }
                else
                {
                    /* XXX handle receive sizes > 256, use kIssueReadCommandState */
                    /* Make sure there is data in the rx fifo. */
                    if (0U == u16RxCount--)
                    {
                        bStateComplete = true;
                        break;
                    }

                    /* Read byte from fifo. */
                    *(psHandle->pu8Buf)++ = (uint8_t)(base->MRDR & LPI2C_MRDR_DATA_MASK);
                }

                /* Move to stop when the transfer is done. */
                if (--psHandle->u16RemainingBytes == 0U)
                {
                    psHandle->u8State = (uint8_t)kStopState;
                    if (psXfer->eDirection == kLPI2C_Write)
                    {
                        bStateComplete = true;
#if I2C_SMBUS_ENABLE
                        /* Let stop state case to deal with NoStopFlag, here just jump to corresponded state. */
                        if ((psXfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStopFlag) == 0U)
                        {
                            psHandle->u8State = (uint8_t)kSendPecState;
                        }
#endif
                    }
#if I2C_SMBUS_ENABLE
                    else
                    {
                        if ((psXfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStopFlag) == 0U)
                        {
                            /* Receive one byte PEC */
                            base->MTDR        = (uint16_t)kRxDataCmd | LPI2C_MTDR_DATA(1);
                            psHandle->u8State = (uint8_t)kReceivePecState;
                            bStateComplete    = true;
                        }
                    }
#endif
                }
                break;

#if I2C_SMBUS_ENABLE
            case (uint8_t)kSendPecState:
                if (psXfer->eDirection == kLPI2C_Write)
                {
                    /* Make sure there is room in the tx fifo. */
                    if (0U == u16TxCount--)
                    {
                        bStateComplete = true;
                        break;
                    }
                    LPI2C_UpdateCrc8(&s_u8MasterCrcValue, (uint8_t *)psXfer->pData, psXfer->u16DataSize);
                    base->MTDR = s_u8MasterCrcValue;
                }
                psHandle->u8State = (uint8_t)kCheckPecAckState;
                bStateComplete    = true;
                break;

            case (uint8_t)kCheckPecAckState:
                if (!bPecAck)
                {
                    result         = kStatus_LPI2C_Pec_Error;
                    bStateComplete = true;
                }
                else
                {
                    /* If status is success, jump to stop handler and needn't break from while. */
                    psHandle->u8State = (uint8_t)kStopState;
                }
                break;

            case (uint8_t)kReceivePecState:
                LPI2C_UpdateCrc8(&s_u8MasterCrcValue, (uint8_t *)psXfer->pData, psXfer->u16DataSize);
                if (s_u8MasterCrcValue != (uint8_t)(base->MRDR & LPI2C_MRDR_DATA_MASK))
                {
                    result = kStatus_LPI2C_Pec_Error;
                }
                psHandle->u8State = (uint8_t)kStopState;
                break;
#endif

            case (uint8_t)kStopState:
                /* Only issue a stop transition if the caller requested it. */
                if ((psXfer->u8ControlFlagMask & (uint8_t)kLPI2C_TransferNoStopFlag) == 0U)
                {
                    /* Make sure there is room in the tx fifo for the stop command. */
                    if (0U == u16TxCount--)
                    {
                        bStateComplete = true;
                        break;
                    }
                    base->MTDR = (uint16_t)kStopCmd;
                }
                else
                {
                    /* Caller doesn't want to send a stop, so we're done now. */
                    *bIsDone       = true;
                    bStateComplete = true;
                    break;
                }
                psHandle->u8State = (uint8_t)kWaitForCompletionState;
                break;

            case (uint8_t)kWaitForCompletionState:
                /* We stay in this state until the stop state is detected. */
                if (0U != (u16Status & (uint16_t)kLPI2C_MasterStopDetectInterruptFlag))
                {
                    *bIsDone = true;
                }
                bStateComplete = true;
                break;
            default:
                assert(false);
                break;
        }
    }
    return result;
}

/*!
 * brief Performs a non-blocking transaction on the I2C bus.
 *
 * param psHandle Pointer to the LPI2C master driver handle.
 * param psTransfer The pointer to the transfer descriptor.
 * retval #kStatus_Success The transaction was started successfully.
 * retval #kStatus_LPI2C_Busy Either another master is currently utilizing the bus, or a non-blocking
 *      transaction is already in progress.
 */
status_t LPI2C_MasterTransferNonBlocking(lpi2c_master_transfer_handle_t *psHandle, lpi2c_master_transfer_t *psTransfer)
{
    status_t result;

    assert(NULL != psHandle);
    assert(NULL != psTransfer);
    assert(psTransfer->u8CommandSize <= (sizeof(psHandle->u16CommandBuffer) - 2U));

    /* Return busy if another transaction is in progress. */
    if (psHandle->u8State != (uint8_t)kIdleState)
    {
        return kStatus_LPI2C_Busy;
    }

    /* Return an error if the bus is already in use not by us. */
    result = LPI2C_MasterCheckForBusyBus(psHandle->base);
    if (kStatus_Success != result)
    {
        return result;
    }

    /* Disable LPI2C IRQ sources while we configure stuff. */
    LPI2C_MasterDisableInterrupts(psHandle->base, (uint16_t)kLPI2C_MasterIrqFlags);

    /* Reset FIFO in case there are data. */
    psHandle->base->MCR |= LPI2C_MCR_RRF_MASK | LPI2C_MCR_RTF_MASK;

    /* Save transfer into handle. */
    psHandle->sTransfer = *psTransfer;

    /* Generate commands to send. */
    LPI2C_TransferInitStateMachine(psHandle);

    /* Clear all flags. */
    LPI2C_MasterClearStatusFlags(psHandle->base, (uint16_t)kLPI2C_MasterClearInterruptFlags);

    /* Turn off auto-stop option. */
    psHandle->base->MCFGR1 &= ~LPI2C_MCFGR1_AUTOSTOP_MASK;

    /* Enable LPI2C internal IRQ sources. NVIC IRQ was enabled in CreateHandle() */
    LPI2C_MasterEnableInterrupts(psHandle->base, (uint16_t)kLPI2C_MasterIrqFlags);

    return result;
}

/*!
 * brief Terminates a non-blocking LPI2C master transmission early.
 *
 * note It is not safe to call this function from an IRQ handler that has a higher priority than the
 *      LPI2C peripheral's IRQ priority.
 *
 * param psHandle Pointer to the LPI2C master driver handle.
 * retval #kStatus_Success A transaction was successfully aborted.
 * retval #kStatus_LPI2C_Idle There is not a non-blocking transaction currently in progress.
 */
void LPI2C_MasterTransferAbort(lpi2c_master_transfer_handle_t *psHandle)
{
    if (psHandle->u8State != (uint8_t)kIdleState)
    {
        /* Disable internal IRQ enables. */
        LPI2C_MasterDisableInterrupts(psHandle->base, (uint16_t)kLPI2C_MasterIrqFlags);

        /* Reset fifos. */
        psHandle->base->MCR |= LPI2C_MCR_RRF_MASK | LPI2C_MCR_RTF_MASK;

        /* Send a stop command to finalize the transfer. */
        psHandle->base->MTDR = (uint16_t)kStopCmd;

        /* Reset handle. */
        psHandle->u8State = (uint8_t)kIdleState;
    }
}

/*!
 * brief Returns number of bytes transferred so far.
 * param psHandle Pointer to the LPI2C master driver handle.
 * param pu16Count Number of bytes transferred so far by the non-blocking transaction.
 * retval #kStatus_Success
 * retval #kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t LPI2C_MasterTransferGetCount(lpi2c_master_transfer_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(NULL != psHandle);

    if (NULL == pu16Count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (psHandle->u8State == (uint8_t)kIdleState)
    {
        *pu16Count = 0;
        return kStatus_NoTransferInProgress;
    }

    uint8_t u8State;
    uint16_t u16RemainingBytes;
    uint16_t u16DataSize;

    /* Cache some fields with IRQs disabled. This ensures all field values */
    /* are synchronized with each other during an ongoing transfer. */
    uint16_t irqs = LPI2C_MasterGetEnabledInterrupts(psHandle->base);
    LPI2C_MasterDisableInterrupts(psHandle->base, irqs);
    u8State           = psHandle->u8State;
    u16RemainingBytes = psHandle->u16RemainingBytes;
    u16DataSize       = psHandle->sTransfer.u16DataSize;
    LPI2C_MasterEnableInterrupts(psHandle->base, irqs);

    /* Get transfer count based on current transfer state. */
    switch (u8State)
    {
        case (uint8_t)kIdleState:
        case (uint8_t)kSendCommandState:
        case (
            uint8_t)kIssueReadCommandState: /* XXX return correct value for this state when >256 reads are supported */
            *pu16Count = 0;
            break;

        case (uint8_t)kTransferDataState:
            *pu16Count = u16DataSize - u16RemainingBytes;
            break;

        case (uint8_t)kStopState:
        case (uint8_t)kWaitForCompletionState:
        default:
            *pu16Count = u16DataSize;
            break;
    }

    return kStatus_Success;
}

/*!
 * brief Reusable routine to handle master interrupts.
 * note This function does not need to be called unless you are reimplementing the
 *  nonblocking API's interrupt handler routines to add special functionality.
 * param psHandle Pointer to the LPI2C master driver handle.
 */
void LPI2C_MasterTransferHandleIRQ(lpi2c_master_transfer_handle_t *psHandle)
{
    bool isDone = false;
    status_t result;
    uint16_t u16TxCount;
    LPI2C_Type *base = psHandle->base;

    /* Don't do anything if we don't have a valid handle. */
    if (NULL == psHandle)
    {
        return;
    }

    if (psHandle->u8State == (uint8_t)kIdleState)
    {
        return;
    }

    result = LPI2C_MasterTransferRunStateMachine(psHandle, &isDone);

    if ((result != kStatus_Success) || isDone)
    {
        /* Handle error, terminate xfer */
        if (result != kStatus_Success)
        {
            LPI2C_MasterTransferAbort(psHandle);
        }
        /* Check whether there is data in tx FIFO not sent out, is there is then the last transfer was NACKed by slave
         */
        LPI2C_MasterGetFifoCounts(base, NULL, &u16TxCount);
        if (u16TxCount != 0U)
        {
            result = kStatus_LPI2C_Nak;
            /* Reset fifos. */
            base->MCR |= LPI2C_MCR_RRF_MASK | LPI2C_MCR_RTF_MASK;
            /* Send a stop command to finalize the transfer. */
            base->MTDR = (uint16_t)kStopCmd;
        }
        /* Disable internal IRQ enables. */
        LPI2C_MasterDisableInterrupts(base, (uint16_t)kLPI2C_MasterIrqFlags);

        /* Set handle to idle state. */
        psHandle->u8State = (uint8_t)kIdleState;

        psHandle->completionStatus = result;
        /* Invoke callback. */
        if (NULL != psHandle->pfCompletionCallback)
        {
            psHandle->pfCompletionCallback(psHandle);
        }
    }
}
/* ----------------------------------- End of Master Transfer Sub-group ---------------------------------- */

/* --------------------------------------- Slave Transfer Sub-group -------------------------------------- */
/*!
 * brief Convert provided flags to status code, and clear any errors if present.
 * param base The LPI2C peripheral base address.
 * param u16Flags Current status flags value that will be checked.
 * retval #kStatus_Success
 * retval #kStatus_LPI2C_BitError
 * retval #kStatus_LPI2C_FifoError
 */
static status_t LPI2C_SlaveCheckAndClearError(LPI2C_Type *base, uint16_t u16Flags)
{
    status_t result = kStatus_Success;

    u16Flags &= (uint16_t)kLPI2C_SlaveErrorInterruptFlags;
    if (0U != u16Flags)
    {
        if (0U != (u16Flags & (uint16_t)kLPI2C_SlaveBitErrInterruptFlag))
        {
            result = kStatus_LPI2C_BitError;
        }
        else if (0U != (u16Flags & (uint16_t)kLPI2C_SlaveFifoErrInterruptFlag))
        {
            result = kStatus_LPI2C_FifoError;
        }
        else
        {
            ; /* Intentional empty */
        }

        /* Clear the errors. */
        LPI2C_SlaveClearStatusFlags(base, u16Flags);
    }
    else
    {
        ; /* Intentional empty */
    }

    return result;
}

/*!
 * brief Creates a new handle for the LPI2C slave non-blocking APIs.
 *
 * The creation of a handle is for use with the non-blocking APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the LPI2C_SlaveTransferAbort() API shall be called.
 *
 * note The function also enables the NVIC IRQ for the input LPI2C. Need to notice
 * that on some SoCs the LPI2C IRQ is connected to INTMUX, in this case user needs to
 * enable the associated INTMUX IRQ in application.

 * param base The LPI2C peripheral base address.
 * param psHandle Pointer to the LPI2C slave driver handle.
 * param pfCallback User provided pointer to the asynchronous callback function.
 * param pUserData User provided pointer to the application callback data.
 */
void LPI2C_SlaveTransferCreateHandle(LPI2C_Type *base,
                                     lpi2c_slave_transfer_handle_t *psHandle,
                                     lpi2c_slave_transfer_callback_t pfCallback,
                                     void *pUserData)
{
    uint32_t u32Instance;

    assert(NULL != psHandle);

    /* Clear out the handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Look up instance number */
    u32Instance = LPI2C_GetInstance(base);

    /* Save base and instance. */
    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    /* Save this handle for IRQ use. */
    s_psLpi2cSlaveHandle[u32Instance] = psHandle;

    /* Set irq handler. */
    s_pfLpi2cSlaveIsr = LPI2C_SlaveTransferHandleIRQ;

    /* Clear internal IRQ enables and enable NVIC IRQ. */
    LPI2C_SlaveDisableInterrupts(base, (uint16_t)kLPI2C_SlaveIrqFlags);
    (void)EnableIRQ(s_eLpi2cIrqs[u32Instance]);

    /* Nack by default. */
    base->STAR = LPI2C_STAR_TXNACK_MASK;
}

/*!
 * brief Starts accepting slave transfers.
 *
 * Call this API after calling I2C_SlaveInit() and LPI2C_SlaveTransferCreateHandle() to start processing
 * transactions driven by an I2C master. The slave monitors the I2C bus and pass events to the
 * callback that was passed into the call to LPI2C_SlaveTransferCreateHandle(). The callback is always invoked
 * from the interrupt context.
 *
 * The set of events received by the callback is customizable. To do so, set the a eventMask parameter to
 * the OR'd combination of #lpi2c_slave_transfer_event_t enumerators for the events you wish to receive.
 * The #kLPI2C_SlaveTransmitEvent and #kLPI2C_SlaveReceiveEvent events are always enabled and do not need
 * to be included in the mask. Alternatively, you can pass 0 to get a default set of only the transmit and
 * receive events that are always enabled. In addition, the #kLPI2C_SlaveAllEvents constant is provided as
 * a convenient way to enable all events.
 *
 * param psHandle Pointer to @ref lpi2c_slave_transfer_handle_t structure which stores the transfer state.
 * param u8EventMask Bit mask formed by OR'ing together #lpi2c_slave_transfer_event_t enumerators to specify
 *      which events to send to the callback. Other accepted values are 0 to get a default set of
 *      only the transmit and receive events, and #kLPI2C_SlaveAllEvents to enable all events.
 *
 * retval #kStatus_Success Slave transfers were successfully started.
 * retval #kStatus_LPI2C_Busy Slave transfers have already been started on this handle.
 */
status_t LPI2C_SlaveTransferNonBlocking(lpi2c_slave_transfer_handle_t *psHandle, uint8_t u8EventMask)
{
    uint16_t u16Status;

    assert(NULL != psHandle);

    /* Return busy if another transaction is in progress. */
    if (psHandle->bIsBusy)
    {
        return kStatus_LPI2C_Busy;
    }

    /* Return an error if the bus is already in use not by us. */
    u16Status = LPI2C_SlaveGetStatusFlags(psHandle->base);
    if ((0U != (u16Status & (uint16_t)kLPI2C_SlaveBusBusyFlag)) && (0U == (u16Status & (uint16_t)kLPI2C_SlaveBusyFlag)))
    {
        return kStatus_LPI2C_Busy;
    }

    /* Disable LPI2C IRQ sources while we configure stuff. */
    LPI2C_SlaveDisableInterrupts(psHandle->base, (uint16_t)kLPI2C_SlaveIrqFlags);

    /* Clear transfer in handle. */
    (void)memset(&psHandle->sTransfer, 0, sizeof(psHandle->sTransfer));

    /* Record that we're busy. */
    psHandle->bIsBusy = true;

    /* Set up event mask. tx and rx are always enabled. */
    psHandle->sTransfer.u8EventMask =
        u8EventMask | (uint8_t)kLPI2C_SlaveTransmitEvent | (uint8_t)kLPI2C_SlaveReceiveEvent;

    /* Ack by default. */
    psHandle->base->STAR = 0U;

    /* Clear all flags. */
    LPI2C_SlaveClearStatusFlags(psHandle->base, (uint16_t)kLPI2C_SlaveClearInterruptFlags);

    /* Enable LPI2C internal IRQ sources. NVIC IRQ was enabled in CreateHandle() */
    LPI2C_SlaveEnableInterrupts(psHandle->base, (uint16_t)kLPI2C_SlaveIrqFlags);

    return kStatus_Success;
}

/*!
 * brief Gets the slave transfer status during a non-blocking transfer.
 *
 * param psHandle Pointer to i2c_slave_handle_t structure.
 * param pu16Count Pointer to a value to hold the number of bytes transferred. May be NULL if the count is not
 *      required.
 * retval #kStatus_Success
 * retval #kStatus_NoTransferInProgress
 */
status_t LPI2C_SlaveTransferGetCount(lpi2c_slave_transfer_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(NULL != psHandle);

    if (pu16Count == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (!psHandle->bIsBusy)
    {
        *pu16Count = 0;
        return kStatus_NoTransferInProgress;
    }

    /* For an active transfer, just return the count from the handle. */
    *pu16Count = psHandle->u16TransferredCount;

    return kStatus_Success;
}

/*!
 * brief Aborts the slave non-blocking transfers.
 * note This API could be called at any time to stop slave for handling the bus events.
 *
 * param psHandle Pointer to @ref lpi2c_slave_transfer_handle_t structure which stores the transfer state.
 * retval #kStatus_Success
 * retval #kStatus_LPI2C_Idle
 */
void LPI2C_SlaveTransferAbort(lpi2c_slave_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    /* Return idle if no transaction is in progress. */
    if (psHandle->bIsBusy)
    {
        /* Disable LPI2C IRQ sources. */
        LPI2C_SlaveDisableInterrupts(psHandle->base, (uint16_t)kLPI2C_SlaveIrqFlags);

        /* Nack by default. */
        psHandle->base->STAR = LPI2C_STAR_TXNACK_MASK;

        /* Reset transfer info. */
        (void)memset(&psHandle->sTransfer, 0, sizeof(psHandle->sTransfer));

        /* We're no longer busy. */
        psHandle->bIsBusy = false;
    }
}

#if I2C_SMBUS_ENABLE
void LPI2C_UpdateCrc8(uint8_t *pu8CrcValue, uint8_t *pu8Data, uint16_t u16ByteCount)
{
    uint8_t u8Crc = *pu8CrcValue;
    uint8_t i;

    while (u16ByteCount--)
    {
        u8Crc ^= *pu8Data++;
        for (i = 0U; i < 8U; ++i)
        {
            if (u8Crc & 0x80U)
            {
                u8Crc = (u8Crc << 1U) ^ 0xE0;
            }
            else
            {
                u8Crc = u8Crc << 1U;
            }
        }
    }
    *pu8CrcValue = u8Crc;
}
#endif

/*!
 * brief Reusable routine to handle slave interrupts.
 * note This function does not need to be called unless you are reimplementing the
 *      non blocking API's interrupt handler routines to add special functionality.
 *
 * param psHandle Pointer to @ref lpi2c_slave_transfer_handle_t structure which stores the transfer state.
 */
void LPI2C_SlaveTransferHandleIRQ(lpi2c_slave_transfer_handle_t *psHandle)
{
    uint16_t u16Flags;
    lpi2c_slave_transfer_t *psXfer;
    LPI2C_Type *base = psHandle->base;

    /* Check for a valid handle in case of a spurious interrupt. */
    if (NULL == psHandle)
    {
        return;
    }

    psXfer = &psHandle->sTransfer;

    /* Get status flags. */
    u16Flags = LPI2C_SlaveGetStatusFlags(base);

    if (0U != (u16Flags & ((uint16_t)kLPI2C_SlaveBitErrInterruptFlag | (uint16_t)kLPI2C_SlaveFifoErrInterruptFlag)))
    {
        psXfer->eEvent           = kLPI2C_SlaveCompletionEvent;
        psXfer->completionStatus = LPI2C_SlaveCheckAndClearError(base, u16Flags);
#if I2C_SMBUS_ENABLE
        s_u8SlaveCrcValue = 0U;
#endif

        if ((0U != (psXfer->u8EventMask & (uint16_t)kLPI2C_SlaveCompletionEvent)) && (NULL != psHandle->pfCallback))
        {
            psHandle->pfCallback(psHandle);
        }
        return;
    }
    if (0U != (u16Flags & (((uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag) |
                           ((uint16_t)kLPI2C_SlaveStopDetectInterruptFlag))))
    {
        psXfer->eEvent = (0U != (u16Flags & (uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag)) ?
                             kLPI2C_SlaveRepeatedStartEvent :
                             kLPI2C_SlaveCompletionEvent;
        psXfer->u16ReceivedAddress  = 0U;
        psXfer->completionStatus    = kStatus_Success;
        psXfer->u16TransferredCount = psHandle->u16TransferredCount;

        if (psXfer->eEvent == kLPI2C_SlaveCompletionEvent)
        {
            psHandle->bIsBusy = false;
#if I2C_SMBUS_ENABLE
            s_u8SlaveCrcValue = 0U;
#endif
        }

        if (psHandle->bWasTransmit)
        {
            /* Subtract one from the transmit count to offset the fact that LPI2C asserts the */
            /* tx flag before it sees the nack from the master-receiver, thus causing one more */
            /* count that the master actually receives. */
            --psXfer->u16TransferredCount;
            psHandle->bWasTransmit = false;
        }

        /* Clear the flag. */
        LPI2C_SlaveClearStatusFlags(base, u16Flags & ((uint16_t)kLPI2C_SlaveRepeatedStartDetectInterruptFlag |
                                                      (uint16_t)kLPI2C_SlaveStopDetectInterruptFlag));

        /* Revert to sending an Ack by default, in case we sent a Nack for receive. */
        base->STAR = 0U;

        if ((0U != (psXfer->u8EventMask & (uint8_t)psXfer->eEvent)) && (NULL != psHandle->pfCallback))
        {
            psHandle->pfCallback(psHandle);
        }

        /* Clean up transfer info on completion, after the callback has been invoked. */
        /* Just need to keep event mask value because it's used until slave transfer is abort */
        /* Clean a part of structure except event mask with an offset address may be concise */
        /* but it has risk for code management, so use temp param copy here */
        uint8_t u8EventMask = psHandle->sTransfer.u8EventMask;
        (void)memset(&psHandle->sTransfer, 0, sizeof(psHandle->sTransfer));
        psHandle->sTransfer.u8EventMask = u8EventMask;
    }
    if (0U != (u16Flags & (uint16_t)kLPI2C_SlaveAddressValidInterruptFlag))
    {
        psXfer->eEvent             = kLPI2C_SlaveAddressMatchEvent;
        psXfer->u16ReceivedAddress = base->SASR & LPI2C_SASR_RADDR_MASK;

#if I2C_SMBUS_ENABLE
        assert(psXfer->u16ReceivedAddress <= 0xFFU);
        LPI2C_UpdateCrc8(&s_u8SlaveCrcValue, (uint8_t *)&psXfer->u16ReceivedAddress, 1);
#endif

        /* Update handle status to busy because slave is addressed. */
        psHandle->bIsBusy = true;
        if ((0U != (psXfer->u8EventMask & (uint16_t)kLPI2C_SlaveAddressMatchEvent)) && (NULL != psHandle->pfCallback))
        {
            psHandle->pfCallback(psHandle);
        }
    }
    if (0U != (u16Flags & (uint16_t)kLPI2C_SlaveTransmitAckInterruptFlag))
    {
        psXfer->eEvent = kLPI2C_SlaveTransmitAckEvent;

        if ((0U != (psXfer->u8EventMask & (uint16_t)kLPI2C_SlaveTransmitAckEvent)) && (NULL != psHandle->pfCallback))
        {
            psHandle->pfCallback(psHandle);
        }
    }

    /* Handle transmit and receive. */
    if (0U != (u16Flags & (uint16_t)kLPI2C_SlaveTxReadyInterruptFlag))
    {
        psHandle->bWasTransmit = true;
#if I2C_SMBUS_ENABLE
        if (psHandle->u8State == kSendPecState)
        {
            base->STDR = s_u8SlaveCrcValue;
            return;
        }
#endif

        /* If we're out of data, invoke callback to get more. */
        if ((NULL == psXfer->pu8Data) || (0U == psXfer->u16DataSize))
        {
            psXfer->eEvent = kLPI2C_SlaveTransmitEvent;
            if (NULL != psHandle->pfCallback)
            {
                psHandle->pfCallback(psHandle);
            }

            /* Clear the transferred count now that we have a new buffer. */
            psHandle->u16TransferredCount = 0U;
        }

        /* Transmit a byte. */
        if ((NULL != psXfer->pu8Data) && (0U != psXfer->u16DataSize))
        {
#if I2C_SMBUS_ENABLE
            LPI2C_UpdateCrc8(&s_u8SlaveCrcValue, psXfer->pu8Data, 1);
            /* If master receives one more byte after last byte data, handler will deal with it as PEC. */
            if (psXfer->u16DataSize == 1U)
            {
                psHandle->u8State = kSendPecState;
            }
#endif
            base->STDR = *psXfer->pu8Data++;
            --psXfer->u16DataSize;
            ++psHandle->u16TransferredCount;
        }
    }
    if (0U != (u16Flags & (uint16_t)kLPI2C_SlaveRxReadyInterruptFlag))
    {
#if I2C_SMBUS_ENABLE
        if (psHandle->u8State == kCheckReceivedPecState)
        {
            uint8_t u8ReadValue = (uint8_t)base->SRDR;
            if (s_u8SlaveCrcValue != u8ReadValue)
            {
                /* Send back NACK if PEC is not matched */
                base->STAR               = LPI2C_STAR_TXNACK_MASK;
                psXfer->eEvent           = kLPI2C_SlaveCompletionEvent;
                psXfer->completionStatus = kStatus_LPI2C_Pec_Error;

                if ((0U != (psXfer->u8EventMask & (uint16_t)kLPI2C_SlaveCompletionEvent)) &&
                    (NULL != psHandle->pfCallback))
                {
                    psHandle->pfCallback(psHandle);
                }
            }
            return;
        }
#endif
        /* If we're out of room in the buffer, invoke callback to get another. */
        if ((NULL == psXfer->pu8Data) || (0U == psXfer->u16DataSize))
        {
            psXfer->eEvent = kLPI2C_SlaveReceiveEvent;
            if (NULL != psHandle->pfCallback)
            {
                psHandle->pfCallback(psHandle);
            }

            /* Clear the transferred count now that we have a new buffer. */
            psHandle->u16TransferredCount = 0U;
        }

        /* Receive a byte. */
        if ((NULL != psXfer->pu8Data) && (0U != psXfer->u16DataSize))
        {
#if I2C_SMBUS_ENABLE
            LPI2C_UpdateCrc8(&s_u8SlaveCrcValue, psXfer->pu8Data, 1);
            /* If master sends PEC after last byte data, handler will deal with it. */
            if (psXfer->u16DataSize == 1U)
            {
                psHandle->u8State = kCheckReceivedPecState;
            }
#endif
            *psXfer->pu8Data++ = (uint8_t)base->SRDR;
            --psXfer->u16DataSize;
            ++psHandle->u16TransferredCount;
        }
        else
        {
            /* We don't have any room to receive more data, so send a nack. */
            base->STAR = LPI2C_STAR_TXNACK_MASK;
        }
    }
}
/* ---------------------------------- End of Slave Transfer Sub-group ---------------------------------- */

#if !(defined(FSL_FEATURE_I2C_HAS_NO_IRQ) && FSL_FEATURE_I2C_HAS_NO_IRQ)
/*!
 * @brief Shared IRQ handler that can call both master and slave ISRs.
 *
 * The master and slave ISRs are called through function pointers in order to decouple
 * this code from the ISR functions. Without this, the linker would always pull in both
 * ISRs and every function they call, even if only the functional API was used.
 *
 * @param u32Instance The LPI2C peripheral instance number.
 */
static void LPI2C_CommonIRQHandler(uint32_t u32Instance)
{
    LPI2C_Type *base;

    /* Check for master IRQ. */
    if (NULL != s_psLpi2cMasterHandle[u32Instance])
    {
        base = s_psLpi2cMasterHandle[u32Instance]->base;
        if ((0U != (base->MCR & LPI2C_MCR_MEN_MASK)) && (NULL != s_pfLpi2cMasterIsr))
        {
            /* Master mode. */
            s_pfLpi2cMasterIsr(s_psLpi2cMasterHandle[u32Instance]);
        }
    }

    /* Check for slave IRQ. */
    if (NULL != s_psLpi2cSlaveHandle[u32Instance])
    {
        base = s_psLpi2cSlaveHandle[u32Instance]->base;
        if ((0U != (base->SCR & LPI2C_SCR_SEN_MASK)) && (NULL != s_pfLpi2cSlaveIsr))
        {
            /* Slave mode. */
            s_pfLpi2cSlaveIsr(s_psLpi2cSlaveHandle[u32Instance]);
        }
    }
}
#endif

#if defined(LPI2C0)
void LPI2C0_DriverIRQHandler(void);
/* Implementation of LPI2C0 handler named in startup code. */
void LPI2C0_DriverIRQHandler(void)
{
    LPI2C_CommonIRQHandler(0U);
}
#endif

#if defined(LPI2C1)
void LPI2C1_DriverIRQHandler(void);
/* Implementation of LPI2C1 handler named in startup code. */
void LPI2C1_DriverIRQHandler(void)
{
    LPI2C_CommonIRQHandler(1U);
}
#endif
