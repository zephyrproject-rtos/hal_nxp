/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_i2c"
#endif

/*! brief i2c master transfer state, used in I2C driver internal master transfer state machine. */
enum _i2c_master_transfer_states
{
    kMasterIdleState             = 0x0U, /*!< I2C bus idle. */
    kMasterCheckAddressState     = 0x1U, /*!< 7-bit address check state. */
    kMasterSendCommandState      = 0x2U, /*!< Send command byte phase. */
    kMasterSendDataState         = 0x3U, /*!< Send data transfer phase. */
    kMasterReceiveDataBeginState = 0x4U, /*!< Receive data transfer phase begin. */
    kMasterReceiveDataState      = 0x5U, /*!< Receive data transfer phase. */
#if I2C_SMBUS_ENABLE
    kMasterCheckSentPecResponseState = 0x6U, /*!< Check slave's response to the PEC byte state. */
    kMasterCheckReceivedPecState     = 0x7U, /*!< Check received PEC bytes with the calculated CRC value. */
#endif                                       /* I2C_SMBUS_ENABLE */
};

/*! brief i2c slave transfer state, used in I2C driver internal slave transfer IRQ handler. */
enum _i2c_slave_transfer_states
{
    kSlaveTurnedOffState = 0x0U,
    kSlaveIdleState      = 0x1U, /*!< I2C bus idle, slave ready to process bus events. */
    kSlaveBusyState      = 0x2U, /*!< I2C bus busy, slave has detected bus event(s). */
#if I2C_SMBUS_ENABLE
    kSlaveCheckReceivedPecState = 0x3U, /*!< Check received PEC bytes with the calculated CRC value. */
    kSlaveSendPECState          = 0x4U,
#endif /* I2C_SMBUS_ENABLE */
};

/*! brief Typedef for interrupt handler. */
typedef void (*i2c_isr_t)(void *i2cHandle);

/*! brief static variable to keep current configured baudrate. */
#if (I2C_MASTER_FACK_CONTROL || I2C_SMBUS_ENABLE)
static uint32_t s_u32Baudrate = 100000;
#endif /* I2C_MASTER_FACK_CONTROL/I2C_SMBUS_ENABLE */

/*! brief static variable to keep current configured baudrate. */
#if I2C_SMBUS_ENABLE
static uint8_t s_u8MasterCrcValue = 0U;
static uint8_t s_u8SlaveCrcValue  = 0U;
static bool s_bIsMaster;
#endif /* I2C_SMBUS_ENABLE */

/*******************************************************************************
 * Driver Internal Functions Declaration
 ******************************************************************************/

/*!
 * @brief Sets SCL/SDA hold time for slave.
 *
 * This API receives SCL stop hold time, calculates the closest SCL divider and MULT value for the SDA hold time, SCL
 * start and SCL stop hold time. To reduce the ROM size, SDA/SCL hold value mapping table is not provided,
 * assume SCL divider = SCL stop hold value *2 to get the closest SCL divider value and MULT value, then the related SDA
 * hold time, SCL start and SCL stop hold time is used.
 *
 * @param base I2C base pointer.
 * @param u32SourceClock_Hz I2C functional clock frequency in Hertz.
 * @param u32SclStopHoldTime_ns SCL stop hold time in ns.
 */
static void I2C_SetHoldTime(I2C_Type *base, uint32_t u32SclStopHoldTime_ns, uint32_t u32SourceClock_Hz);

/*!
 * @brief Checks and clears error status during master transfer.
 *
 * @param base I2C base pointer.
 * @param u32Status current i2c hardware status.
 * @retval kStatus_Success No error found.
 * @retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval #kStatus_I2C_Nak Received Nak error.
 */
static status_t I2C_MasterCheckAndClearError(I2C_Type *base, uint16_t u16Status);

/*!
 * @brief Initializes master tranfer software state machine.
 *
 * Sets up master transfer, sends slave address and set the initial transfer state of master software state machine.
 *
 * @param psHandle pointer to i2c_master_transfer_handle_t structure which stores the transfer state.
 * @param psTransferConfig pointer to i2c_master_transfer_t structure.
 */
static status_t I2C_MasterTransferInitStateMachine(i2c_master_transfer_handle_t *psHandle,
                                                   i2c_master_transfer_t *psTransferConfig);

/*!
 * @brief Runs master transfer softerware state machine to perform transfer.
 *
 * Master software state machine controls transfer state, perfroms master data transfer according to user's transfer
 * configuration. For example, if user sets the transfer configuration @ref i2c_master_transfer_t to perform master read
 * with command, after start signal and slave adderss are issued, the proper transfer state should be in such order:
 * kMasterCheckAddressState: Check if master was nacked during slave probing
 * kMasterSendCommandState: Send command data, if it is master read operation, issue re-start and address
 * kMasterReceiveDataBeginState: Set bus direction to receive and send nack signal if only one byte data is to be read.
 * kMasterReceiveDataState: Recieve data. Send stop signal if #kI2C_TransferNoStopFlag is not configured.
 * Master software state machine is designed to check the curent state stored by i2c_master_transfer_handle_t::u8State,
 * performs curent state's transfer process and set the state to the next accordingly. After all the states are
 * executed, bIsDone is set to true to indicate transfer completion.
 *
 * @param psHandle pointer to i2c_master_transfer_handle_t structure which stores the transfer state
 * @param bIsDone input param to get whether transfer is done, true is done
 * @retval kStatus_Success No error found.
 * @retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval #kStatus_I2C_Nak Received Nak error.
 * @retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 */
static status_t I2C_MasterTransferRunStateMachine(i2c_master_transfer_handle_t *psHandle, bool *bIsDone);

/*!
 * @brief Master interrupt handler.
 *
 * @param pI2CHandle pointer to i2c_master_transfer_handle_t structure.
 */
void I2C_MasterTransferHandleIRQ(void *pI2CHandle);

/*!
 * @brief Slave interrupt handler.
 *
 * @param pI2CHandle pointer to i2c_slave_transfer_handle_t structure which stores the transfer state
 */
void I2C_SlaveTransferHandleIRQ(void *pI2CHandle);

#if I2C_SMBUS_ENABLE
/*!
 * @brief Calculate CRC-8 check value for PEC transfer.
 *
 * @param pu8CrcValue Pointer to the calculated CRC value. If several sections of data need to be calculated separately,
 * point this pointer to the previously calculated CRC value
 * @param pu8Data Pointer to the data to be calculated
 * @param u16ByteCount Total byte count for current CRC calculation
 */
void I2C_UpdateCrc8(uint8_t *pu8CrcValue, uint8_t *pu8Data, uint16_t u16ByteCount);
#endif /* I2C_SMBUS_ENABLE */

/*!
 * @brief I2C common interrupt handler.
 *
 * @param pHandle pointer to i2c_master_transfer_handle_t structure which stores the transfer state
 */
static void I2C_TransferCommonIRQHandler(I2C_Type *base, void *pHandle);

#if (I2C_MASTER_FACK_CONTROL || I2C_SMBUS_ENABLE)
static void I2C_AckByte(I2C_Type *base, bool bAck)
{
    /* Issue Acknowledge on read. */
    I2C_SendAck(base, bAck);

    /* Delay at least one bit time */
    SDK_DelayAtLeastUs(1000000 / s_u32Baudrate, SystemCoreClock);

    /* Do dummy read. */
    (void)I2C_ReadByte(base);
}
#endif /* I2C_MASTER_FACK_CONTROL/I2C_SMBUS_ENABLE */

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! brief Pointers to i2c handles for each instance. */
static void *s_pI2cHandles[FSL_FEATURE_SOC_I2C_COUNT];

/*! brief SCL clock divider used for calculating baud rate. */
static const uint16_t s_u16I2cDividerTable[] = {
    20,  22,  24,  26,   28,   30,   34,   40,   28,   32,   36,   40,   44,   48,   56,   68,
    48,  56,  64,  72,   80,   88,   104,  128,  80,   96,   112,  128,  144,  160,  192,  240,
    160, 192, 224, 256,  288,  320,  384,  480,  320,  384,  448,  512,  576,  640,  768,  960,
    640, 768, 896, 1024, 1152, 1280, 1536, 1920, 1280, 1536, 1792, 2048, 2304, 2560, 3072, 3840};

/*! brief Pointers to i2c IRQ number for each instance. */
static const IRQn_Type s_eI2cIrqs[] = I2C_IRQS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! brief Pointers to i2c clocks for each instance. */
static const clock_ip_name_t s_eI2cClocks[] = I2C_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! brief Pointer to master IRQ handler for each instance. */
static i2c_isr_t s_pfI2cMasterIsr;

/*! brief Pointer to slave IRQ handler for each instance. */
static i2c_isr_t s_pfI2cSlaveIsr;

/*! brief Pointers to i2c bases for each instance. */
static I2C_Type *const s_pfI2cBases[] = I2C_BASE_PTRS;

/*******************************************************************************
 * Codes
 ******************************************************************************/

/* =========================================== Functional Group API List ============================================ */
/* ---------------------------------------- Hardware Status Flags Sub-group ----------------------------------------- */
/*!
 * brief Gets the I2C hardware status flags.
 *
 * param base I2C base pointer
 * return the mask of status flags, can be a single flag or several flags in #_i2c_status_flags ORed together.
 */
uint16_t I2C_MasterGetStatusFlags(I2C_Type *base)
{
    uint16_t u16StatusFlags = (uint16_t)base->S;

    /* Look up the SCL/SDA timeout bit from the SMB register. */
    if (0U != (base->SMB & (I2C_SMB_SLTF_MASK)))
    {
        u16StatusFlags |= (uint16_t)kI2C_SclLowTimeoutFlag;
    }
    if (0U != (base->SMB & (I2C_SMB_SHTF2_MASK)))
    {
        u16StatusFlags |= (uint16_t)kI2C_SdaLowTimeoutInterruptFlag;
    }
#ifdef I2C_HAS_STOP_DETECT
    /* Look up the STOPF bit from the filter register. */
    if (0U != (base->FLT & I2C_FLT_STOPF_MASK))
    {
        u16StatusFlags |= (uint16_t)kI2C_StopDetectInterruptFlag;
    }
#endif

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    /* Look up the STARTF bit from the filter register. */
    if (0U != (base->FLT & I2C_FLT_STARTF_MASK))
    {
        u16StatusFlags |= (uint16_t)kI2C_StartDetectInterruptFlag;
    }
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */

    return u16StatusFlags;
}
/* -------------------------------------- End of Hardware Status Flags Sub-group ------------------------------------ */

/* ----------------------------------------------- Interrupt Sub-group ---------------------------------------------- */
/*!
 * brief Enables I2C interrupt source.
 *
 * note Before enabling kI2C_GlobalInterruptEnable, check kI2C_RangeAddressMatchInterruptFlag and
 * kI2C_AddressAsSlaveInterruptFlag first, because any write operation on C1 will clear these 2 bits.
 *
 * param base I2C base pointer
 * param u8Interrupts The interrupt source mask, can be a single source or several sources in #_i2c_interrupt_enable
 * ORed together.
 */
void I2C_EnableInterrupts(I2C_Type *base, uint8_t u8Interrupts)
{
#ifdef I2C_HAS_STOP_DETECT
    uint16_t u16FLTReg;
#endif

    if (0U != (u8Interrupts & (uint8_t)kI2C_GlobalInterruptEnable))
    {
        base->C1 |= I2C_C1_IICIE_MASK;
    }

    if (0U != (u8Interrupts & (uint8_t)kI2C_SdaLowTimeoutInterruptEnable))
    {
        base->SMB |= I2C_SMB_SHTF2IE_MASK;
    }

#if defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT
    if (0U != (u8Interrupts & (uint8_t)kI2C_StopDetectInterruptEnable))
    {
        u16FLTReg = base->FLT;
        /* Avoid writing 1 to STOPF and clears the flag accidentally. */
        u16FLTReg &= ~I2C_FLT_STOPF_MASK;
        /* Enable Stop detect. */
        u16FLTReg |= I2C_FLT_STOPIE_MASK;
        base->FLT = u16FLTReg;
    }
#endif /* FSL_FEATURE_I2C_HAS_STOP_DETECT */

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    if (0U != (u8Interrupts & (uint8_t)kI2C_StartStopDetectInterruptEnable))
    {
        u16FLTReg = base->FLT;
        /* Avoid writing 1 to STOPF/STARTF and clears the flags accidentally. */
        u16FLTReg &= ~(uint8_t)(I2C_FLT_STOPF_MASK | I2C_FLT_STARTF_MASK);
        /* Start and stop detect enable. */
        u16FLTReg |= I2C_FLT_SSIE_MASK;
        base->FLT = u16FLTReg;
    }
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */
}

/*!
 * brief Disables I2C interrupt source.
 *
 * note Before disabling kI2C_GlobalInterruptEnable, check kI2C_RangeAddressMatchInterruptFlag and
 * kI2C_AddressAsSlaveInterruptFlag first, because any write operation on C1 will clear these 2 bits.
 *
 * param base I2C base pointer
 * param u8Interrupts The interrupt source mask, can be a single source or several sources in #_i2c_interrupt_enable
 * ORed together.
 */
void I2C_DisableInterrupts(I2C_Type *base, uint8_t u8Interrupts)
{
    if (0U != (u8Interrupts & (uint8_t)kI2C_GlobalInterruptEnable))
    {
        base->C1 &= ~(uint8_t)I2C_C1_IICIE_MASK;
    }

    if (0U != (u8Interrupts & (uint8_t)kI2C_SdaLowTimeoutInterruptEnable))
    {
        base->SMB &= ~(uint8_t)I2C_SMB_SHTF2IE_MASK;
    }

#if defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT
    if (0U != (u8Interrupts & (uint8_t)kI2C_StopDetectInterruptEnable))
    {
        base->FLT &= ~(I2C_FLT_STOPIE_MASK | I2C_FLT_STOPF_MASK);
    }
#endif /* FSL_FEATURE_I2C_HAS_STOP_DETECT */

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    if (0U != (u8Interrupts & (uint8_t)kI2C_StartStopDetectInterruptEnable))
    {
        base->FLT &= ~(uint8_t)(I2C_FLT_SSIE_MASK | I2C_FLT_STOPF_MASK | I2C_FLT_STARTF_MASK);
    }
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */
}

/*!
 * brief Get all the enabled interrupt sources.
 *
 * param base I2C base pointer
 * return The interrupt source mask, can be a single source or several sources in #_i2c_interrupt_enable ORed
 * together.
 */
uint8_t I2C_GetEnabledInterrupts(I2C_Type *base)
{
    uint8_t u8Interrupts = 0U;
    if (0U != (base->C1 & (uint8_t)I2C_C1_IICIE_MASK))
    {
        u8Interrupts |= (uint8_t)kI2C_GlobalInterruptEnable;
    }

    if (0U != (base->SMB & (uint8_t)I2C_SMB_SHTF2IE_MASK))
    {
        u8Interrupts |= (uint8_t)kI2C_SdaLowTimeoutInterruptEnable;
    }
#ifdef I2C_HAS_STOP_DETECT
    if (0U != (base->FLT & (uint8_t)(I2C_FLT_SSIE_MASK)))
    {
#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
        u8Interrupts |= (uint8_t)kI2C_StartStopDetectInterruptEnable;
#elif defined(FSL_FEATURE_I2C_HAS_STOP_DETECT) && FSL_FEATURE_I2C_HAS_STOP_DETECT
        u8Interrupts |= (uint8_t)kI2C_StopDetectInterruptEnable;
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT/FSL_FEATURE_I2C_HAS_STOP_DETECT */
    }
#endif
    return u8Interrupts;
}
/* ------------------------------------------- End of Interrupt Sub-group ------------------------------------------- */

/* ------------------------------------------ Module Init/Deinit Sub-group ------------------------------------------ */
/*!
 * brief Sets the I2C master configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref I2C_MasterInit to use.
 * Use the unchanged structure in @ref I2C_MasterInit or modify the structure before calling @ref I2C_MasterInit.
 * This is an example:
 * code
 *   i2c_master_config_t config;
 *   I2C_MasterGetDefaultConfig(&config, 12000000U);
 *   config.u32BaudRateBps = 100000;
 *   I2C_MasterInit(I2C0, &config);
 * endcode
 *
 * param psMasterConfig Pointer to the master configuration structure.
 * param u32SrcClockHz The clock source frequency for I2C module.
 */
void I2C_MasterGetDefaultConfig(i2c_master_config_t *psMasterConfig, uint32_t u32SrcClockHz)
{
    assert(NULL != psMasterConfig);
    assert(0U != u32SrcClockHz);

    /* Initializes the configure structure to zero. */
    (void)memset(psMasterConfig, 0, sizeof(*psMasterConfig));

    /* Disable the I2C peripheral. */
    psMasterConfig->bEnableModule = false;

    /* Save the module's clock frequency. */
    psMasterConfig->u32SrcClockHz = u32SrcClockHz;

    /* Default disable the I2C high drive. */
    psMasterConfig->bEnableHighDrive = false;

#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    /* Default enable double buffering. */
    psMasterConfig->bEnableDoubleBuffering = true;
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */
#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    /* Default stop hold enable is disabled. */
    psMasterConfig->bEnableStopHold = false;
#endif /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */

    /* Default glitch filter value is 200ns. */
    psMasterConfig->u8GlitchFilterWidth = 200U;

#if I2C_SMBUS_ENABLE
    /* SMBus defines a clock low timeout of 35 ms, use this as default value. */
    psMasterConfig->u16SclTimout_Ms = 35;
#endif /* I2C_SMBUS_ENABLE */

    /* Default do not enable any interrupts. */
    psMasterConfig->u8Interrupts = 0U;
    /* Default baud rate at 100kbps. */
    psMasterConfig->u32BaudRateBps = 100000U;
}

/*!
 * brief Initializes the I2C peripheral to operate as master.
 *
 * This API initialize the I2C module for master operation, including the feature configuration of high drive capacity,
 * doubble buffer, glitch filter, SCL timeout value, stop hold off enable and transfer baudrate. User can also configure
 * whether to enable the module in the function.
 *
 * note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enbaled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the API
 * The configuration structure can be filled manully or be set with default values by calling
 *
 * @ref I2C_MasterGetDefaultConfig. This is an example.
 * code
 *   I2C_MasterGetDefaultConfig(&config, 12000000U);
 *   I2C_MasterInit(I2C0, &config);
 * endcode
 *
 * param base I2C base pointer
 * param psMasterConfig Pointer to the master configuration structure
 */
void I2C_MasterInit(I2C_Type *base, const i2c_master_config_t *psMasterConfig)
{
    assert(NULL != psMasterConfig);
    assert(0U != psMasterConfig->u32SrcClockHz);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable I2C clock. */
    CLOCK_EnableClock(s_eI2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Set the I2C register value to reset value. */
    I2C_Reset(base);

    /* Clear all flags. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StatusAllFlags);
    /* Configure high drive. */
    I2C_EnableHighDrive(base, psMasterConfig->bEnableHighDrive);
    /* Enable/Disable double buffering. */
#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    I2C_EnableDoubleBuffer(base, psMasterConfig->bEnableDoubleBuffering);
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */
    /* Configure the glitch filter value. */
    I2C_SetGlitchFilter(base, (uint16_t)psMasterConfig->u8GlitchFilterWidth, psMasterConfig->u32SrcClockHz);
#if I2C_SMBUS_ENABLE
    /* Configure timeout value. */
    I2C_SetSclTimeoutValue(base, psMasterConfig->u16SclTimout_Ms, psMasterConfig->u32SrcClockHz);
#endif /* I2C_SMBUS_ENABLE */

#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    I2C_EnableStopHold(base, psMasterConfig->bEnableStopHold);
#endif /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */
    /* Configure baud rate. */
    I2C_MasterSetBaudRate(base, psMasterConfig->u32BaudRateBps, psMasterConfig->u32SrcClockHz);

    /* Enable the I2C peripheral based on the configuration. */
    I2C_Enable(base, psMasterConfig->bEnableModule);

    I2C_EnableInterrupts(base, (uint8_t)psMasterConfig->u8Interrupts);
}

/*!
 * brief De-initializes the I2C peripheral. Call this API to disable the I2C module.
 *
 * param base I2C base pointer
 */
void I2C_MasterDeinit(I2C_Type *base)
{
    /* Disable I2C module. */
    I2C_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable I2C clock. */
    CLOCK_DisableClock(s_eI2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets the I2C slave configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure for @ref I2C_SlaveInit to use. Use the unchanged
 * initialized structure in @ref I2C_SlaveInit or modify the structure before calling @ref I2C_SlaveInit.
 * This is an example.
 * code
 *   i2c_slave_config_t config;
 *   I2C_SlaveGetDefaultConfig(&config, 0x23U, 12000000U);
 * endcode
 *
 * param psSlaveConfig Pointer to the slave configuration structure.
 * param u16PrimaryAddress slave address. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * param u32SrcClockHz The clock source frequency for I2C module.
 */
void I2C_SlaveGetDefaultConfig(i2c_slave_config_t *psSlaveConfig, uint16_t u16PrimaryAddress, uint32_t u32SrcClockHz)
{
    assert(NULL != psSlaveConfig);
    assert(0U != u32SrcClockHz);

    /* Initializes the configure structure to zero. */
    (void)memset(psSlaveConfig, 0, sizeof(*psSlaveConfig));

    /* Save the module's clock frequency. */
    psSlaveConfig->u32SrcClockHz = u32SrcClockHz;

    /* Disable the I2C peripheral. */
    psSlaveConfig->bEnableModule = false;

    /* Default disable the I2C high drive. */
    psSlaveConfig->bEnableHighDrive = false;

#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    /* Default enable double buffering. */
    psSlaveConfig->bEnableDoubleBuffering = true;
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */
#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    /* Default stop hold enable is disabled. */
    psSlaveConfig->bEnableStopHold = false;
#endif /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */
    /* Default glitch filter value is 200ns. */
    psSlaveConfig->u8GlitchFilterWidth = 200U;

    /* Slave address match waking up MCU from low power mode is disabled. */
    psSlaveConfig->bEnableWakeUp = false;

#if !(defined(FSL_FEATURE_I2C_NO_SBRC) && FSL_FEATURE_I2C_NO_SBRC)
    /* Independent slave mode baud rate at maximum frequency is disabled. */
    psSlaveConfig->bEnableBaudRateCtl = false;
#endif /* FSL_FEATURE_I2C_NO_SBRC */

    /* General call mode is enabled by default. */
    psSlaveConfig->bEnableGeneralCall = true;

    /* By default slave is addressed with 7-bit single address. */
    psSlaveConfig->eAddressingMode = kI2C_AddressMatch;

    psSlaveConfig->bitsPrimaryAddress = u16PrimaryAddress;

#if I2C_SMBUS_ENABLE
    /* SMBus defines a clock low timeout of 35 ms, use this as default value. */
    psSlaveConfig->u16SclTimout_Ms = 35;
    /* Alert response is enabled by default. */
    psSlaveConfig->bEnableAlertResponse = true;
    /* Secondary address is disabled by default. */
    psSlaveConfig->bEnableSecondaryAddress = false;
#endif /* I2C_SMBUS_ENABLE */
    /* Default do not enable any interrupts. */
    psSlaveConfig->u8Interrupts = 0U;
    /* Set default SCL stop hold time to 4us which is minimum requirement in I2C spec. */
    psSlaveConfig->u32SclStopHoldTime_ns = 4000U;
}

/*!
 * brief Initializes the I2C peripheral to operate as slave.
 *
 * This API initialize the I2C module for slave operation, including the feature configuration of high drive capacity,
 * doubble buffer, glitch filter, SCL timeout value, stop hold off enable, addressing mode, alert response/general call
 * minitoring, auto baudrate control, low power mode wake up, SCL/SDA setup and hold time. User can also configure
 * whether to enable the module in the function.
 *
 * note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enbaled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the API
 *
 * The configuration structure can be filled manully or be set with default values by calling
 * @ref I2C_SlaveGetDefaultConfig. This is an example.
 * code
 *    i2c_slave_config_t sConfig;
 *    I2C_SlaveGetDefaultConfig(&sConfig, 0x2AU, 12000000U);
 *    I2C_SlaveInit(I2C0, &sConfig);
 * endcode
 *
 * param base I2C base pointer
 * param psSlaveConfig Pointer to the slave configuration structure
 */
void I2C_SlaveInit(I2C_Type *base, const i2c_slave_config_t *psSlaveConfig)
{
    assert(NULL != psSlaveConfig);
    assert(psSlaveConfig->bitsPrimaryAddress != 0U);
    assert(0U != psSlaveConfig->u32SrcClockHz);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_eI2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    uint16_t u16tmpReg;
    /* Reset the module. */
    I2C_Reset(base);

    /* Set hold time. */
    I2C_SetHoldTime(base, psSlaveConfig->u32SclStopHoldTime_ns, psSlaveConfig->u32SrcClockHz);

    /* Configure the glitch filter value. */
    I2C_SetGlitchFilter(base, (uint16_t)psSlaveConfig->u8GlitchFilterWidth, psSlaveConfig->u32SrcClockHz);

#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    /* Configure the stop / hold enable. */
    I2C_EnableStopHold(base, psSlaveConfig->bEnableStopHold);
#endif /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */
    /* Configure addressing mode. */
    I2C_SlaveSetAddressingMode(base, (i2c_slave_address_mode_t)psSlaveConfig->eAddressingMode,
                               (uint16_t)psSlaveConfig->bitsPrimaryAddress, (uint8_t)psSlaveConfig->bitsMaxAddress);

#if I2C_SMBUS_ENABLE
    /* Configure SMBus feature, including alert response, secondary address and SCL timeout value. */
    u16tmpReg = base->SMB;
    u16tmpReg &= ~(uint16_t)(I2C_SMB_ALERTEN_MASK | I2C_SMB_SIICAEN_MASK);
    base->SMB = u16tmpReg | I2C_SMB_ALERTEN(psSlaveConfig->bEnableAlertResponse) |
                I2C_SMB_SIICAEN(psSlaveConfig->bEnableSecondaryAddress);
    base->A2 = (uint8_t)((psSlaveConfig->bitsSecondaryAddress) << 1U);
    I2C_SetSclTimeoutValue(base, psSlaveConfig->u16SclTimout_Ms, psSlaveConfig->u32SrcClockHz);
#endif /* I2C_SMBUS_ENABLE */

    /* Configure general call, high drive and auto baud rate control. */
    u16tmpReg = (uint16_t)base->C2;
#if !(defined(FSL_FEATURE_I2C_NO_SBRC) && FSL_FEATURE_I2C_NO_SBRC)
    u16tmpReg &= ~((uint16_t)I2C_C2_SBRC_MASK | I2C_C2_GCAEN_MASK | I2C_C2_HDRS_MASK);
    u16tmpReg |=
        (uint16_t)(I2C_C2_SBRC(psSlaveConfig->bEnableBaudRateCtl) | I2C_C2_GCAEN(psSlaveConfig->bEnableGeneralCall) |
                   I2C_C2_HDRS(psSlaveConfig->bEnableHighDrive));
#else
    u16tmpReg &= ~((uint16_t)I2C_C2_GCAEN_MASK | I2C_C2_HDRS_MASK);
    u16tmpReg |=
        (uint16_t)(I2C_C2_GCAEN(psSlaveConfig->bEnableGeneralCall) | I2C_C2_HDRS(psSlaveConfig->bEnableHighDrive));
#endif /* FSL_FEATURE_I2C_NO_SBRC */
    base->C2 = u16tmpReg;

#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    /* Enable/Disable double buffering. */
    I2C_EnableDoubleBuffer(base, psMasterConfig->bEnableDoubleBuffering);
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */

    /* Configure low power wake up feature and enable module. */
    u16tmpReg = (uint16_t)base->C1;
    u16tmpReg &= ~(uint16_t)I2C_C1_WUEN_MASK;
    base->C1 = u16tmpReg | I2C_C1_WUEN(psSlaveConfig->bEnableWakeUp) | I2C_C1_IICEN(psSlaveConfig->bEnableModule);

    I2C_EnableInterrupts(base, (uint8_t)psSlaveConfig->u8Interrupts);
}

/*!
 * brief Sets the I2C configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure for @ref I2C_Init to use. Use the unchanged
 * initialized structure in @ref I2C_Init or modify the structure before calling @ref I2C_Init.
 * This is an example.
 * code
 *   i2c_config_t config;
 *   I2C_GetDefaultConfig(&config, 0x23U, 12000000U);
 * endcode
 *
 * param psConfig Pointer to the slave configuration structure.
 * param u16PrimaryAddress slave address. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * param u32SrcClockHz The clock source frequency for I2C module.
 */
void I2C_GetDefaultConfig(i2c_config_t *psConfig, uint16_t u16PrimaryAddress, uint32_t u32SrcClockHz)
{
    assert(NULL != psConfig);
    assert(0U != u32SrcClockHz);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    /* Default disable high drive. */
    psConfig->bEnableHighDrive = false;
#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    /* Default disable double buffering. */
    psConfig->bEnableDoubleBuffering = false;
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */
#if I2C_SMBUS_ENABLE
    /* SMBus defines a clock low timeout of 35 ms, use this as default value. */
    psConfig->u16SclTimout_Ms = 35;
    /* Alert response is enabled by default. */
    psConfig->bEnableAlertResponse = true;
    /* Secondary address is disabled by default. */
    psConfig->bEnableSecondaryAddress = false;
#endif /* I2C_SMBUS_ENABLE */
    /* Slave address match waking up MCU from low power mode is disabled. */
    psConfig->bEnableWakeUp = false;
#if !(defined(FSL_FEATURE_I2C_NO_SBRC) && FSL_FEATURE_I2C_NO_SBRC)
    /* Independent slave mode baud rate at maximum frequency is disabled. */
    psConfig->bEnableBaudRateCtl = false;
#endif /* FSL_FEATURE_I2C_NO_SBRC */
    /* General call mode is enabled by default. */
    psConfig->bEnableGeneralCall = true;
    /* By default slave is addressed with 7-bit single address. */
    psConfig->eAddressingMode = kI2C_AddressMatch;

    /* Default baud rate at 100kbps. */
    psConfig->u32BaudRateBps = 100000U;
#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    /* Default stop hold enable is disabled. */
    psConfig->bEnableStopHold = false;
#endif /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */
    /* Default glitch filter value is no filter. */
    psConfig->u8GlitchFilterWidth = 200U;

    psConfig->bitsPrimaryAddress = u16PrimaryAddress;

    /* Disable the I2C peripheral. */
    psConfig->bEnableModule = false;
    /* Default do not enable any interrupts. */
    psConfig->u8Interrupts = 0U;
    /* Save the module's clock frequency. */
    psConfig->u32SrcClockHz = u32SrcClockHz;
}

/*!
 * brief Initializes the I2C peripheral.
 *
 * This API initialize the I2C module, including the feature configuration of high drive capacity, doubble buffer,
 * glitch filter, SCL timeout value, stop hold off enable, addressing mode, alert response/general call minitoring, auto
 * baudrate control, low power mode wake up and baudrate. User can also configure whether to enable the module in the
 * function.
 *
 * note If FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is enbaled by user, the init function will not ungate I2C clock source
 * before initialization, to avoid hardfault, user has to manually enable ungate the clock source before calling the API
 *
 * The configuration structure can be filled manully or be set with default values by calling @ref I2C_GetDefaultConfig.
 * This is an example.
 * code
 *   i2c_config_t sConfig;
 *   I2C_GetDefaultConfig(&sConfig, 0x23U, 12000000U);
 *   I2C_Init(I2C0, &sConfig);
 * endcode
 *
 * param base I2C base pointer
 * param psConfig Pointer to the I2C configuration structure
 */
void I2C_Init(I2C_Type *base, const i2c_config_t *psConfig)
{
    assert(NULL != psConfig);
    assert(psConfig->bitsPrimaryAddress != 0U);
    assert(0U != psConfig->u32SrcClockHz);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_eI2cClocks[I2C_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    uint16_t u16tmpReg;
    /* Reset the module. */
    I2C_Reset(base);

    /* Configure the glitch filter value. */
    I2C_SetGlitchFilter(base, (uint16_t)psConfig->u8GlitchFilterWidth, psConfig->u32SrcClockHz);

#if defined(FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF) && FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF
    /* Configure the stop / hold enable. */
    I2C_EnableStopHold(base, psConfig->bEnableStopHold);
#endif /* FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF */

    /* Configure the glitch filter value. */
    I2C_SetGlitchFilter(base, (uint16_t)psConfig->u8GlitchFilterWidth, psConfig->u32SrcClockHz);

    /* Configure addressing mode. */
    I2C_SlaveSetAddressingMode(base, (i2c_slave_address_mode_t)psConfig->eAddressingMode,
                               (uint16_t)psConfig->bitsPrimaryAddress, (uint8_t)psConfig->bitsMaxAddress);

#if I2C_SMBUS_ENABLE
    /* Configure SMBus feature, including alert response, secondary address and SCL timeout value. */
    u16tmpReg = base->SMB;
    u16tmpReg &= ~(uint16_t)(I2C_SMB_ALERTEN_MASK | I2C_SMB_SIICAEN_MASK);
    base->SMB = u16tmpReg | I2C_SMB_ALERTEN(psConfig->bEnableAlertResponse) |
                I2C_SMB_SIICAEN(psConfig->bEnableSecondaryAddress);
    base->A2 = (uint8_t)((psConfig->bitsSecondaryAddress) << 1U);
    I2C_SetSclTimeoutValue(base, psConfig->u16SclTimout_Ms, psConfig->u32SrcClockHz);
#endif /* I2C_SMBUS_ENABLE */

    /* Configure general call, high drive and auto baud rate control. */
    u16tmpReg = base->C2;
#if !(defined(FSL_FEATURE_I2C_NO_SBRC) && FSL_FEATURE_I2C_NO_SBRC)
    u16tmpReg &= ~((uint16_t)I2C_C2_SBRC_MASK | I2C_C2_GCAEN_MASK | I2C_C2_HDRS_MASK);
    u16tmpReg |= (uint16_t)(I2C_C2_SBRC(psConfig->bEnableBaudRateCtl) | I2C_C2_GCAEN(psConfig->bEnableGeneralCall) |
                            I2C_C2_HDRS(psConfig->bEnableHighDrive));
#else
    u16tmpReg &= (uint16_t) ~(I2C_C2_GCAEN_MASK | I2C_C2_HDRS_MASK);
    u16tmpReg |= I2C_C2_GCAEN(psConfig->bEnableGeneralCall) | I2C_C2_HDRS(psConfig->bEnableHighDrive);
#endif /* FSL_FEATURE_I2C_NO_SBRC */
    base->C2 = u16tmpReg;

#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE
    /* Enable/Disable double buffering. */
    I2C_EnableDoubleBuffer(base, psConfig->bEnableDoubleBuffering);
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE */

    /* Configure baudrate. */
    I2C_MasterSetBaudRate(base, psConfig->u32BaudRateBps, psConfig->u32SrcClockHz);
    /* Configure low power wake up feature and enable module. */
    u16tmpReg = base->C1;
    u16tmpReg &= ~(uint16_t)I2C_C1_WUEN_MASK;
    base->C1 = u16tmpReg | I2C_C1_WUEN(psConfig->bEnableWakeUp) | I2C_C1_IICEN(psConfig->bEnableModule);

    I2C_EnableInterrupts(base, (uint8_t)psConfig->u8Interrupts);
}
/* --------------------------------------- End of Module Init/Deinit Sub-group -------------------------------------- */

/* ---------------------------------------- Peripheral Configuration Sub-group -------------------------------------- */
/*!
 * brief Sets the I2C SCL timeout value.
 *
 * After the I2C module is initialized, user can call this function to change the timeout value.
 *
 * param base I2C base pointer.
 * param u16SclTimout_Ms The SCL timeout value in ms.
 * param u32SrcClockHz I2C peripheral clock frequency in Hz
 */
void I2C_SetSclTimeoutValue(I2C_Type *base, uint16_t u16SclTimout_Ms, uint32_t u32SrcClockHz)
{
    /* Calculate timeout value. */
    uint32_t u32SclTimeoutValue = (uint32_t)u16SclTimout_Ms * 512U * u32SrcClockHz / 1000U;

    /* If u32SclTimeoutValue exceeds the max boundary, use u32SrcClockHz/64 as counter. */
    if (u32SclTimeoutValue > (uint32_t)UINT16_MAX)
    {
        u32SclTimeoutValue = MIN((uint32_t)UINT16_MAX, u32SclTimeoutValue / 64U);
        base->SMB &= ~I2C_SMB_TCKSEL_MASK;
    }
    base->SMB |= I2C_SMB_TCKSEL_MASK;

    base->SLTL = (uint8_t)u32SclTimeoutValue;
    base->SLTH = (uint8_t)(u32SclTimeoutValue >> 8U);
}

/*!
 * brief Sets the I2C master glitch filter width.
 *
 * After the I2C module is initialized as master, user can call this function to change the glitch filter width.
 *
 * param base I2C base pointer.
 * param u16GlitchFilter_Ns The GLitch filter length in nano seconds.
 * param u32SrcClockHz I2C peripheral clock frequency in Hz
 */
void I2C_SetGlitchFilter(I2C_Type *base, uint16_t u16GlitchFilter_Ns, uint32_t u32SrcClockHz)
{
    /* Calculate filter width. */
    uint32_t u32FilterWidth = u16GlitchFilter_Ns * u32SrcClockHz / 1000000000U;
    /* The maximum supported filter width is 15 I2C clock cycle. */
    u32FilterWidth = MIN(15U, u32FilterWidth);

    base->FLT &= ~(uint8_t)(I2C_FLT_FLT_MASK);
    base->FLT |= I2C_FLT_FLT(u32FilterWidth);
}

/*!
 * brief Sets the I2C master transfer baud rate.
 *
 * After the I2C module is initialized as master, user can call this function to change the transfer baud rate.
 *
 * param base I2C base pointer.
 * param u32BaudRateBps the baud rate value in bits-per-second.
 * param u32SrcClockHz I2C peripheral clock frequency in Hz
 */
void I2C_MasterSetBaudRate(I2C_Type *base, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz)
{
    uint32_t u32Multiplier;
    uint32_t u32ComputedRate;
    uint32_t u32AbsError;
    uint32_t u32BestError = UINT32_MAX;
    uint32_t u32BestMult  = 0u;
    uint32_t u32BestIcr   = 0u;
    uint32_t u32Flag      = 1u;
    uint8_t u8Mult;
    uint8_t i;

    /* Search for the settings with the lowest error. Mult is the MULT field of the I2C_F register,
     * and ranges from 0-2. It selects the u32Multiplier factor for the divider. */
    for (u8Mult = 0u; u8Mult <= 2u; ++u8Mult)
    {
        if (u32BestError == 0u)
        {
            break;
        }

        u32Multiplier = u32Flag << u8Mult;

        /* Scan table to find best match. */
        for (i = 0u; i < sizeof(s_u16I2cDividerTable) / sizeof(uint16_t); ++i)
        {
            u32ComputedRate = u32SrcClockHz / (u32Multiplier * s_u16I2cDividerTable[i]);
            u32AbsError     = u32BaudRateBps > u32ComputedRate ? (u32BaudRateBps - u32ComputedRate) :
                                                             (u32ComputedRate - u32BaudRateBps);

            if (u32AbsError < u32BestError)
            {
                u32BestMult  = u8Mult;
                u32BestIcr   = i;
                u32BestError = u32AbsError;

                /* If the error is 0, then we can stop searching because we won't find a better match. */
                if (u32AbsError == 0u)
                {
                    break;
                }
            }
        }
    }

#if (I2C_MASTER_FACK_CONTROL || I2C_SMBUS_ENABLE)
    s_u32Baudrate = u32BaudRateBps;
#endif /* I2C_MASTER_FACK_CONTROL/I2C_SMBUS_ENABLE */
    /* Set frequency register based on best settings. */
    base->F = I2C_F_MULT(u32BestMult) | I2C_F_ICR(u32BestIcr);
}

/*!
 * brief Configure the slave addressing mode.
 *
 * After the I2C module is initialized as slave, user can call this function to change the configuration of slave
 * addressing mode.
 *
 * param base I2C base pointer.
 * param eAddressingMode The slave addressing mode, single address or range address.
 * param u16Address I2C slave address. For 7-bit address low 7-bit is used, for 10-bit address low 10-bit is used.
 * param u8MaxAddress The maximum boundary of slave address used in a range address match.
 */
void I2C_SlaveSetAddressingMode(I2C_Type *base,
                                i2c_slave_address_mode_t eAddressingMode,
                                uint16_t u16Address,
                                uint8_t u8MaxAddress)
{
    assert(base != NULL);
    uint16_t u16TmpReg = 0;
    switch (eAddressingMode)
    {
        case kI2C_AddressMatch:
            base->A1 = u16Address << 1U;
            base->C2 &= ~I2C_C2_RMEN_MASK;
            break;

        case kI2C_AddressRangeMatch:
            assert(u16Address < u8MaxAddress);
            base->A1 = u16Address << 1U;
            base->RA = (((uint16_t)(u8MaxAddress)) << 1U);
            base->C2 |= I2C_C2_RMEN_MASK;
            break;

        case kI2C_AddressMatch10bit:
            base->A1  = u16Address << 1U;
            u16TmpReg = base->C2;
            u16TmpReg &= ~((uint16_t)I2C_C2_RMEN_MASK | I2C_C2_AD_MASK);
            u16TmpReg |= I2C_C2_AD(u16Address >> 7U) | I2C_C2_ADEXT_MASK;
            base->C2 = u16TmpReg;
            break;

        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}
/* ------------------------------------ End of Peripheral Configuration Sub-group ----------------------------------- */

/* --------------------------------------------- Bus Operation Sub-group -------------------------------------------- */
/*!
 * brief Sends a START signal on the I2C bus then the 7-bit slave address with transmit/receive bit
 *
 * This function is used to initiate a new transfer in master mode, by sending a START signal, then the slave address
 * with transmit/receive bit to I2C bus.
 *
 * note The return value of this API only indicates whether the start signal is sent to bus, user has to check
 * #kI2C_ArbitrationLostInterruptFlag and #kI2C_ArbitrationLostInterruptFlag using @ref I2C_MasterClearStatusFlags to
 * see if valid slave device is avaliable or the aribitration is lost.
 *
 * param base I2C base pointer
 * param u8Address 7-bit slave device address.
 * param eDirection Master transfer directions(transmit/receive).
 * retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 * retval kStatus_Success Successfully send the start signal.
 * retval kStatus_I2C_Busy Current bus is busy.
 */
status_t I2C_MasterStart(I2C_Type *base, uint8_t u8Address, i2c_master_transfer_direction_t eDirection)
{
    status_t result         = kStatus_Success;
    uint16_t u16StatusFlags = I2C_MasterGetStatusFlags(base);

    /* Return an error if the bus is already in use. */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_BusBusyFlag))
    {
        result = kStatus_I2C_Busy;
    }
    else
    {
        /* Send the START signal. */
        base->C1 |= I2C_C1_MST_MASK | I2C_C1_TX_MASK;

#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING
#if (I2C_RETRY_TIMES > 0U)
        uint32_t u32WaitTimes = I2C_RETRY_TIMES;
        while (0U == (base->S2 & I2C_S2_EMPTY_MASK))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        while (0U == (base->S2 & I2C_S2_EMPTY_MASK))
        {
        }
#endif
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING */
        uint8_t u8StartByte = (uint8_t)(((uint32_t)u8Address) << 1U | ((eDirection == kI2C_MasterReceive) ? 1U : 0U));
        /* Send slave address + write/read bit. */
        I2C_WriteByte(base, u8StartByte);
#if I2C_SMBUS_ENABLE
        /* Set CRC to 0 only on start signal. */
        s_u8MasterCrcValue = 0U;
        I2C_UpdateCrc8(&s_u8MasterCrcValue, &u8StartByte, 1U);
#endif /* I2C_SMBUS_ENABLE */
    }

    return result;
}

/*!
 * brief Sends a repeated START signal, then the 7-bit slave address with transmit/receive bit to I2C bus.
 *
 * param base I2C peripheral base pointer
 * param u8Address 7-bit slave device address.
 * param eDirection Master transfer directions(transmit/receive).
 * retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 * retval kStatus_Success Successfully send the start signal.
 * retval kStatus_I2C_Busy Current bus is busy but not occupied by current I2C master.
 */
status_t I2C_MasterRepeatedStart(I2C_Type *base, uint8_t u8Address, i2c_master_transfer_direction_t eDirection)
{
    status_t result = kStatus_Success;
    uint16_t u16SavedMult;
    uint16_t u16StatusFlags = I2C_MasterGetStatusFlags(base);
    uint8_t u8TimeDelay     = 6;

    /* Return an error if the bus is already in use, but not by us. */
    if ((0U == (base->C1 & I2C_C1_MST_MASK)) && (0U != (u16StatusFlags & (uint16_t)kI2C_BusBusyFlag)))
    {
        result = kStatus_I2C_Busy;
    }
    else
    {
        u16SavedMult = base->F;
        base->F      = u16SavedMult & (~I2C_F_MULT_MASK);
        /* We are already in a transfer, so send a repeated start. */
        base->C1 |= I2C_C1_RSTA_MASK | I2C_C1_TX_MASK;
        /* Restore the u32Multiplier factor. */
        base->F = u16SavedMult;

        /* Add some delay to wait for the Re-Start signal to be sent. */
        while (0U != (u8TimeDelay--))
        {
            __NOP();
        }

#if defined(FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING) && FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING
#if (I2C_RETRY_TIMES > 0U)
        uint32_t u32WaitTimes = I2C_RETRY_TIMES;
        while (0U == (base->S2 & I2C_S2_EMPTY_MASK))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        while (0U == (base->S2 & I2C_S2_EMPTY_MASK))
        {
        }
#endif
#endif /* FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING */
        uint8_t u8StartByte = (uint8_t)(((uint32_t)u8Address) << 1U | ((eDirection == kI2C_MasterReceive) ? 1U : 0U));
        /* Send slave address + write/read bit. */
        I2C_WriteByte(base, u8StartByte);
#if I2C_SMBUS_ENABLE
        I2C_UpdateCrc8(&s_u8MasterCrcValue, &u8StartByte, 1U);
#endif /* I2C_SMBUS_ENABLE */
    }

    return result;
}

/*!
 * brief Sends a STOP signal on the I2C bus.
 *
 * param base I2C base pointer
 * retval kStatus_Success Successfully send the stop signal.
 * retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterStop(I2C_Type *base)
{
    status_t result = kStatus_Success;

    /* Issue the STOP command on the bus. */
    base->C1 &= ~(uint8_t)(I2C_C1_MST_MASK | I2C_C1_TX_MASK | I2C_C1_TXAK_MASK);

#if (I2C_RETRY_TIMES > 0U)
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
    /* Wait until bus not busy. */
    while (0U != (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_BusBusyFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }

#else
    /* Wait until data transfer complete. */
    while (0U != (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_BusBusyFlag))
    {
    }
#endif
    return result;
}

/*!
 * brief Sends a piece of data to I2C bus in master mode in blocking way.
 *
 * Call this function when using I2C as master to send certain bytes of data to bus when start signal is already sent.
 * User can specify whether to send a stop siganl after the data. This function uses the blocking way, which means it
 * does not return until all the data is sent to bus and stop signal is successfully issued(if user configures the stop
 * signal).
 *
 * note If I2C_SMBUS_ENABLE is enabled, an PEC byte will be sent after all the data bytes, and API will return
 * #kStatus_I2C_Pec_Error if slave nack the PEC.
 *
 * param base I2C base pointer.
 * param pu8Data The pointer to the data to be transmitted.
 * param txSize The length in bytes of the data to be transmitted.
 * param bSendStop Whether to send stop signal after the data transfer.
 * retval #kStatus_Success Successfully complete the data transmission.
 * retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * retval #kStatus_I2C_Nak Transfer error, receive NAK during transfer.
 * retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 */
status_t I2C_MasterWriteBlocking(I2C_Type *base, const uint8_t *pu8Data, uint16_t txSize, bool bSendStop)
{
    status_t result         = kStatus_Success;
    uint16_t u16StatusFlags = 0;
    uint8_t u8Data;

#if (I2C_RETRY_TIMES > 0U)
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
    /* Wait until the data register is ready for transmit. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }
#else
    /* Wait until the data register is ready for transmit. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
    {
    }
#endif

    /* Clear the IICIF flag. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

    /* Setup the I2C peripheral to transmit data. */
    I2C_SetTransferDirection(base, kI2C_Write);

    while (0U != (txSize--))
    {
        u8Data = *pu8Data++;
        /* Send a byte of data. */
        I2C_WriteByte(base, u8Data);
#if I2C_SMBUS_ENABLE
        I2C_UpdateCrc8(&s_u8MasterCrcValue, &u8Data, 1U);
#endif /* I2C_SMBUS_ENABLE */

#if (I2C_RETRY_TIMES > 0U)
        u32WaitTimes = I2C_RETRY_TIMES;
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif
        u16StatusFlags = I2C_MasterGetStatusFlags(base);

        /* Clear the IICIF flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

        /* Check if arbitration lost or no acknowledgement (NAK), return failure status. */
        if (0U != (u16StatusFlags & (uint16_t)kI2C_ArbitrationLostInterruptFlag))
        {
            I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_ArbitrationLostInterruptFlag);
            result = kStatus_I2C_ArbitrationLost;
        }
#if I2C_SMBUS_ENABLE
        /* For SMBus there is still a PEC byte following the last byte of data, cannot ignore the NACK. */
        if (0U != (u16StatusFlags & (uint16_t)kI2C_ReceiveNakFlag))
#else  /* I2C_SMBUS_ENABLE */
        /* If the last byte was nack, ignore */
        if ((0U != (u16StatusFlags & (uint16_t)kI2C_ReceiveNakFlag)) && (0U != txSize))
#endif /* I2C_SMBUS_ENABLE */
        {
            result = kStatus_I2C_Nak;
        }

        if (result != kStatus_Success)
        {
            /* Breaking out of the send loop. */
            break;
        }
    }

#if I2C_SMBUS_ENABLE
    /* Only send the PEC byte when stop signal is requested by user. */
    if (bSendStop)
    {
        I2C_WriteByte(base, s_u8MasterCrcValue);
    }
#if (I2C_RETRY_TIMES > 0U)
    u32WaitTimes = I2C_RETRY_TIMES;
    /* Wait until data transfer complete. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }
#else
    /* Wait until data transfer complete. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
    {
    }
#endif
    u16StatusFlags = I2C_MasterGetStatusFlags(base);
    result         = I2C_MasterCheckAndClearError(base, u16StatusFlags);
    /* If the PEC byte received with a NACK, set the transfer result to PEC error. */
    if (result == kStatus_I2C_Nak)
    {
        result = kStatus_I2C_Pec_Error;
    }
#endif /* I2C_SMBUS_ENABLE */

    /* If the transfer status is success and user required to send stop signal,
       or master was previously nacked by slave, send stop signal to finish the transfer. */
    if (((result == kStatus_Success) && (bSendStop)) || (result == kStatus_I2C_Nak)
#if I2C_SMBUS_ENABLE
        || (result == kStatus_I2C_Pec_Error)
#endif /* I2C_SMBUS_ENABLE */
    )
    {
        /* Clear the IICIF flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

        /* Send stop. */
        result = I2C_MasterStop(base);
    }

    return result;
}

/*!
 * brief Receives a piece of data from I2C bus in master mode in blocking way.
 *
 * Call this function when using I2C as master to receive certain bytes of data from bus when start signal is already
 * sent. User can specify whether to send a stop siganl after the data. This function uses the blocking way, which means
 * it does not return until all the data has been received and stop signal is successfully issued(if user configures the
 * stop signal).
 *
 * note If user configures to send stop signal after the data, this function stops the bus before reading the final
 * byte from data register. Without stopping the bus prior to the final read, the bus will issue another read, resulting
 * in garbage data being read into the data register.
 *
 * note If I2C_SMBUS_ENABLE is enabled, an PEC byte will be received after all the data bytes, and API will return
 * #kStatus_I2C_Pec_Error if the PEC does not match the calculation.
 *
 * param base I2C base pointer.
 * param pu8RxBuff The pointer to the data to store the received data.
 * param rxSize The length in bytes of the data to be received.
 * param bSendStop Whether to send stop signal after the data transfer.
 * retval kStatus_Success Successfully complete the data transmission.
 * retval kStatus_I2C_Timeout Send stop signal failed, timeout.
 */
status_t I2C_MasterReadBlocking(I2C_Type *base, uint8_t *pu8RxBuff, uint16_t rxSize, bool bSendStop)
{
    status_t result = kStatus_Success;
    uint8_t u8Data;

#if (I2C_RETRY_TIMES > 0U)
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
    /* Wait until the data register is ready for transmit. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }
#else
    /* Wait until the data register is ready for transmit. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
    {
    }
#endif

    /* Clear the IICIF flag. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

#if I2C_MASTER_FACK_CONTROL
    I2C_EnableFastAck(base, true);
#endif

    /* Setup the I2C peripheral to receive data. */
    I2C_SetTransferDirection(base, kI2C_Read);

    /* Do dummy read. */
    (void)I2C_ReadByte(base);

#if (!I2C_SMBUS_ENABLE)
    if (rxSize == 1U)
    {
        /* Issue NACK on read. */
        I2C_SendAck(base, false);
#if I2C_MASTER_FACK_CONTROL
        I2C_EnableFastAck(base, false);
#endif
    }
#endif /* I2C_SMBUS_ENABLE */

    while (0U != (rxSize--))
    {
#if (I2C_RETRY_TIMES > 0U)
        u32WaitTimes = I2C_RETRY_TIMES;
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif

        if (rxSize == 0U)
        {
            if (bSendStop)
            {
#if I2C_SMBUS_ENABLE
                /* Check the PEC byte */
                I2C_SendAck(base, false);
#else
                /* Issue STOP command before reading last byte. */
                result = I2C_MasterStop(base);
#endif /* I2C_SMBUS_ENABLE */
            }
            else
            {
                /* Change direction to transmit to avoid extra clocks. */
                I2C_SetTransferDirection(base, kI2C_Write);
            }
        }

        /* Clear the IICIF flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

        /* Read from the data register. */
        u8Data       = I2C_ReadByte(base);
        *pu8RxBuff++ = u8Data;

#if I2C_SMBUS_ENABLE
        I2C_UpdateCrc8(&s_u8MasterCrcValue, &u8Data, 1U);
#else
#if I2C_MASTER_FACK_CONTROL
        if (rxSize != 0U)
        {
            I2C_AckByte(base, true);
        }
#endif

        if (rxSize == 1U)
        {
            I2C_SendAck(base, false);
#if I2C_MASTER_FACK_CONTROL
            /* Issue NACK on read. */
            I2C_EnableFastAck(base, false);
#endif
        }
#endif /* I2C_SMBUS_ENABLE */
    }

#if I2C_SMBUS_ENABLE
    /* Only check the PEC when stop signal should be sent to finish the transfer. */
    if (bSendStop)
    {
#if (I2C_RETRY_TIMES > 0U)
        u32WaitTimes = I2C_RETRY_TIMES;
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif
        /* Issue STOP command before reading last PEC byte. */
        result = I2C_MasterStop(base);
        /* Clear the IICIF flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);
        /* Read PEC byte from the data register and check with calculation. */
        if (I2C_ReadByte(base) != s_u8MasterCrcValue)
        {
            result = kStatus_I2C_Pec_Error;
        }
    }
#endif /* I2C_SMBUS_ENABLE */

    return result;
}

/*!
 * brief Sends a piece of data to I2C bus in slave mode in blocking way.
 *
 * Call this funtion to let I2C slave poll register status until it is addressed, then slave sends txSize of data to bus
 * until all the data has been sent to bus or untill it is nacked.
 *
 * param base I2C base pointer.
 * param pu8TxBuff The pointer to the data to be transferred.
 * param txSize The length in bytes of the data to be transferred.
 * retval #kStatus_Success Successfully complete the data transmission.
 * retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * retval #kStatus_I2C_Nak Transfer error, receive NAK during transfer.
 * retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 */
status_t I2C_SlaveWriteBlocking(I2C_Type *base, const uint8_t *pu8TxBuff, uint16_t txSize)
{
    status_t result = kStatus_Success;

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    /* Check start flag. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_StartDetectInterruptFlag))
    {
    }
    /* Clear the start detect and interrupt flag. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StartDetectInterruptFlag | (uint16_t)kI2C_InterruptPendingFlag);
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */

#if (I2C_RETRY_TIMES > 0U)
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
    /* Slave only transfer data when it is addressed by master. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_AddressAsSlaveInterruptFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }
#else
    /* Slave only transfer data when it is addressed by master. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_AddressAsSlaveInterruptFlag))
    {
    }
#endif
    /* Read dummy to release bus. */
    (void)I2C_ReadByte(base);

    /* Send data to master, re-use I2C_MasterWriteBlocking with the send stop flag set to false. */
    result = I2C_MasterWriteBlocking(base, pu8TxBuff, txSize, false);

    /* Switch to receive mode at the end of the transfer. */
    I2C_SetTransferDirection(base, kI2C_Read);

    /* Read dummy to release bus. */
    (void)I2C_ReadByte(base);

    return result;
}

/*!
 * brief Receives a piece of data from I2C bus in slave mode in blocking way.
 *
 * Call this funtion to let I2C slave poll register status until it is addressed, then slave receives rxSize of data
 * until all the data has been received.
 *
 * param base I2C base pointer.
 * param pu8RxBuff The pointer to the data to store the received data.
 * param rxSize The length in bytes of the data to be received.
 * retval kStatus_Success Successfully complete data receive.
 * retval kStatus_I2C_Timeout Wait status flag timeout.
 */
status_t I2C_SlaveReadBlocking(I2C_Type *base, uint8_t *pu8RxBuff, uint16_t rxSize)
{
    status_t result = kStatus_Success;

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    /* Check start flag. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_StartDetectInterruptFlag))
    {
    }
    /* Clear start detect flag and interrupt pending flag. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StartDetectInterruptFlag | (uint16_t)kI2C_InterruptPendingFlag);
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */

#if (I2C_RETRY_TIMES > 0U)
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
    /* Slave only transfer data when it is addressed by master. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_AddressAsSlaveInterruptFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }

    u32WaitTimes = I2C_RETRY_TIMES;
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }
#else
    /* Slave only transfer data when it is addressed by master. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_AddressAsSlaveInterruptFlag))
    {
    }
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
    {
    }
#endif

    /* Read dummy to release bus. */
    (void)I2C_ReadByte(base);

    /* Clear the IICIF flag. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

    /* Setup the I2C peripheral to receive data. */
    I2C_SetTransferDirection(base, kI2C_Read);

    while (0U != (rxSize--))
    {
#if (I2C_RETRY_TIMES > 0U)
        u32WaitTimes = I2C_RETRY_TIMES;
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif
        /* Clear the IICIF flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

        /* Read from the data register. */
        *pu8RxBuff++ = I2C_ReadByte(base);
    }

    return result;
}
/* ----------------------------------------- End of Bus Operation Sub-group ----------------------------------------- */

/* ========================================== Transactional Group API List ========================================== */
/* ------------------------------------------- Master Transfer Sub-group -------------------------------------------- */
/*!
 * brief Performs a master polling transfer on the I2C bus.
 *
 * note The API does not return until the transfer succeeds or fails due to arbitration lost or receiving a NAK or PEC
 * error.
 *
 * param base I2C peripheral base address.
 * param psTransferConfig Pointer to the transfer configuration structure.
 * retval kStatus_Success Successfully complete the data transmission.
 * retval #kStatus_I2C_Busy Previous transmission still not finished.
 * retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 * retval #kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * retval #kStatus_I2C_Nak Transfer error, receive NAK during transfer.
 */
status_t I2C_MasterTransferBlocking(I2C_Type *base, i2c_master_transfer_t *psTransferConfig)
{
    assert(NULL != psTransferConfig);

    i2c_master_transfer_direction_t eDirection = psTransferConfig->eDirection;
    status_t result                            = kStatus_Success;

    I2C_Enable(base, true);
    /* Clear all status before transfer. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StatusAllFlags);

#if (I2C_RETRY_TIMES > 0U)
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
    /* Wait until the data register is ready for transmit. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
    {
        if (0U == (--u32WaitTimes))
        {
            return kStatus_I2C_Timeout;
        }
    }
#else
    /* Wait until the data register is ready for transmit. */
    while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
    {
    }
#endif

    /* Change direction to write if it's a master receive operation with command code. */
    if ((psTransferConfig->u8CommandSize > 0U) && (psTransferConfig->eDirection == kI2C_MasterReceive))
    {
        eDirection = kI2C_MasterTransmit;
    }

    /* Handle transfer with no start signal, according to I2C protocol, only support write with no start signal. */
    if (0U != (psTransferConfig->u8ControlFlagMask & (uint8_t)kI2C_TransferNoStartFlag))
    {
        if (eDirection == kI2C_MasterReceive)
        {
            return kStatus_InvalidArgument;
        }
    }
    /* If repeated start is requested, send repeated start. */
    else if (0U != (psTransferConfig->u8ControlFlagMask & (uint8_t)kI2C_TransferRepeatedStartFlag))
    {
        result = I2C_MasterRepeatedStart(base, psTransferConfig->u8SlaveAddress, eDirection);
    }
    else /* For normal transfer, send start. */
    {
        result = I2C_MasterStart(base, psTransferConfig->u8SlaveAddress, eDirection);
    }

    /* If start signal and slave address was sent, check bus status to see if master is nacked or lost arbitration. */
    if (0U == (psTransferConfig->u8ControlFlagMask & (uint8_t)kI2C_TransferNoStartFlag))
    {
        /* Return if error. */
        if (kStatus_Success != result)
        {
            return result;
        }

#if (I2C_RETRY_TIMES > 0U)
        u32WaitTimes = I2C_RETRY_TIMES;
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif
        /* Check if there's transfer error. */
        result = I2C_MasterCheckAndClearError(base, I2C_MasterGetStatusFlags(base));

        /* Return if error. */
        if (kStatus_Success != result)
        {
            if (result == kStatus_I2C_Nak)
            {
                result = kStatus_I2C_Addr_Nak;

                (void)I2C_MasterStop(base);
            }

            return result;
        }
    }

    /* Send command. */
    if (0U != (psTransferConfig->u8CommandSize))
    {
#if I2C_SMBUS_ENABLE
        I2C_UpdateCrc8(&s_u8MasterCrcValue, psTransferConfig->pu8Command, psTransferConfig->u8CommandSize);
#endif
        do
        {
            /* Clear interrupt pending flag. */
            I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

            psTransferConfig->u8CommandSize--;
            I2C_WriteByte(base, *psTransferConfig->pu8Command++);

#if (I2C_RETRY_TIMES > 0U)
            u32WaitTimes = I2C_RETRY_TIMES;
            /* Wait until data transfer complete. */
            while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
            {
                if (0U == (--u32WaitTimes))
                {
                    return kStatus_I2C_Timeout;
                }
            }
#else
            /* Wait until data transfer complete. */
            while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
            {
            }
#endif

            /* Check if there's transfer error. */
            result = I2C_MasterCheckAndClearError(base, I2C_MasterGetStatusFlags(base));

            if (0 != result)
            {
                if (result == kStatus_I2C_Nak)
                {
                    (void)I2C_MasterStop(base);
                }

                return result;
            }

        } while (psTransferConfig->u8CommandSize > 0U);

        /* If it is master read operation, issue repeated start is required. */
        if (psTransferConfig->eDirection == kI2C_MasterReceive)
        {
            /* Clear pending flag. */
            I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

            /* Send repeated start and slave address. */
            result = I2C_MasterRepeatedStart(base, psTransferConfig->u8SlaveAddress, kI2C_MasterReceive);

            /* Return if error. */
            if (kStatus_Success != result)
            {
                return result;
            }

#if (I2C_RETRY_TIMES > 0U)
            u32WaitTimes = I2C_RETRY_TIMES;
            /* Wait until data transfer complete. */
            while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
            {
                if (0U == (--u32WaitTimes))
                {
                    return kStatus_I2C_Timeout;
                }
            }
#else
            /* Wait until data transfer complete. */
            while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_InterruptPendingFlag))
            {
            }
#endif

            /* Check if master is nacked by slave or lost arbitration. */
            result = I2C_MasterCheckAndClearError(base, I2C_MasterGetStatusFlags(base));

            if (kStatus_Success != result)
            {
                if (result == kStatus_I2C_Nak)
                {
                    result = kStatus_I2C_Addr_Nak;

                    (void)I2C_MasterStop(base);
                }

                return result;
            }
        }
    }

    /* Transmit data. */
    if (psTransferConfig->eDirection == kI2C_MasterTransmit)
    {
        if (psTransferConfig->u16DataSize > 0U)
        {
            uint8_t *u8Tmpdata     = psTransferConfig->pu8Data;
            uint16_t u8TmpdataSize = psTransferConfig->u16DataSize;
            bool bSendStop         = ((psTransferConfig->u8ControlFlagMask & (uint8_t)kI2C_TransferNoStopFlag) == 0U);
            /* Send Data. */
            result = I2C_MasterWriteBlocking(base, u8Tmpdata, u8TmpdataSize, bSendStop);
        }
        else if (0U == (psTransferConfig->u8ControlFlagMask & (uint8_t)kI2C_TransferNoStopFlag))
        {
            /* Send stop. */
            result = I2C_MasterStop(base);
        }
        else
        {
            /* Add this to fix MISRA C2012 rule15.7 issue: Empty else without comment. */
        }
    }

    /* Receive Data. */
    if ((psTransferConfig->u16DataSize > 0U) && (psTransferConfig->eDirection == kI2C_MasterReceive))
    {
        uint8_t *u8Tmpdata     = psTransferConfig->pu8Data;
        uint16_t u8TmpdataSize = psTransferConfig->u16DataSize;
        bool bSendStop         = ((psTransferConfig->u8ControlFlagMask & (uint8_t)kI2C_TransferNoStopFlag) == 0U);
        result                 = I2C_MasterReadBlocking(base, u8Tmpdata, u8TmpdataSize, bSendStop);
    }

    return result;
}

/*!
 * brief Initializes the I2C master transfer in interrupt way.
 *
 * This function is responsible for initializig master transfer handle, installing user Callback, registering master
 * IRQ handling function and opening global interrupt.
 *
 * param base I2C base pointer.
 * param psHandle pointer to i2c_master_transfer_handle_t structure to store the transfer state.
 * param pfCallback pointer to user pfCallback function.
 * param pUserData User configurable pointer to any data, function, structure etc that user wish to use in the callback
 */
void I2C_MasterTransferCreateHandle(I2C_Type *base,
                                    i2c_master_transfer_handle_t *psHandle,
                                    i2c_master_transfer_callback_t pfCallback,
                                    void *pUserData)
{
    assert(NULL != psHandle);

    uint32_t instance = I2C_GetInstance(base);

    /* Zero handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Register pfCallback and pUserData. */
    psHandle->pfCompletionCallback = pfCallback;
    psHandle->pUserData            = pUserData;
    psHandle->base                 = base;
    psHandle->u8State              = (uint8_t)kMasterIdleState;

    /* Save the context in global variables to support the double weak mechanism. */
    s_pI2cHandles[instance] = psHandle;

    /* Register master interrupt service routine. */
    s_pfI2cMasterIsr = I2C_MasterTransferHandleIRQ;

    /* Enable I2C global IRQ. */
    (void)EnableIRQ(s_eI2cIrqs[instance]);
}

/*!
 * brief Initiates a master transfer on the I2C bus in interrupt way.
 *
 * note Transfer in interrupt way is non-blocking which means this API returns immediately after transfer initiates.
 * User can call @ref I2C_MasterTransferGetCount to get the count of data that master has transmitted/received and check
 * transfer status. If the return status is kStatus_NoTransferInProgress, the transfer is finished. Also if user
 * installs a user pfCallback when calling @ref I2C_MasterTransferCreateHandle before, the pfCallback will be invoked
 * when transfer finishes.
 *
 * param psHandle pointer to i2c_master_transfer_handle_t structure which stores the transfer state.
 * param psTransferConfig Pointer to the transfer configuration structure.
 * retval kStatus_Success Successfully start the data transmission.
 * retval #kStatus_I2C_Busy Previous transmission still not finished.
 * retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flagsto change.
 */
status_t I2C_MasterTransferNonBlocking(i2c_master_transfer_handle_t *psHandle, i2c_master_transfer_t *psTransferConfig)
{
    assert(NULL != psHandle);
    assert(NULL != psTransferConfig);

    status_t result = kStatus_Success;

    /* Check if the I2C bus is idle, if not return busy status. */
    if (psHandle->u8State != (uint8_t)kMasterIdleState)
    {
        result = kStatus_I2C_Busy;
    }
    else
    {
        /* Enable module */
        I2C_Enable(psHandle->base, true);
        /* Initialize the driver's master software transfer state machine. */
        result = I2C_MasterTransferInitStateMachine(psHandle, psTransferConfig);
#if I2C_SMBUS_ENABLE
        s_bIsMaster = true;
#endif /* I2C_SMBUS_ENABLE */

        if (result == kStatus_Success)
        {
            /* Enable the I2C interrupts. */
            I2C_EnableInterrupts(psHandle->base, (uint8_t)kI2C_GlobalInterruptEnable);
        }
    }

    return result;
}

/*!
 * brief Gets the master transfer count and status during a interrupt transfer.
 *
 * param psHandle pointer to i2c_master_transfer_handle_t structure which stores the transfer state.
 * param count Pointer to number of bytes transferred so far by the non-blocking transaction.
 * retval kStatus_InvalidArgument count is Invalid.
 * retval kStatus_NoTransferInProgress Curent no transfer is in progress.
 * retval kStatus_Success Successfully obtained the count.
 */
status_t I2C_MasterTransferGetCount(i2c_master_transfer_handle_t *psHandle, uint16_t *count)
{
    assert(NULL != psHandle);

    if (NULL == count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (psHandle->u8State == (uint8_t)kMasterIdleState)
    {
        return kStatus_NoTransferInProgress;
    }

    /* Calculate transfer count. */
    *count = psHandle->u16TransferSize - psHandle->sTransfer.u16DataSize;

    return kStatus_Success;
}

/*!
 * brief Aborts an in-process transfer in interrupt way.
 *
 * note This API can be called at any time after a transfer of interrupt way initiates and before it finishes to abort
 * the transfer early.
 *
 * param psHandle pointer to i2c_master_transfer_handle_t structure which stores the transfer state
 * retval #kStatus_I2C_Busy Master lost arbitration, bus is in use by other master.
 * retval #kStatus_I2C_Timeout Transfer error, timeout happens when waiting for status flags to change.
 * retval kStatus_Success Successfully abort the transfer.
 */
status_t I2C_MasterTransferAbort(i2c_master_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);
    status_t result = kStatus_Success;

#if (I2C_RETRY_TIMES > 0U)
    uint32_t u32WaitTimes = I2C_RETRY_TIMES;
#endif

    /* Disable interrupt. */
    I2C_DisableInterrupts(psHandle->base, (uint8_t)kI2C_GlobalInterruptEnable);

    /* Reset the state to idle. */
    psHandle->u8State = (uint8_t)kMasterIdleState;

    /* If the bus is already in use, but not by us */
    if (false == I2C_IsMaster(psHandle->base))
    {
        return kStatus_I2C_Busy;
    }

    /* Send STOP signal. */
    if (psHandle->sTransfer.eDirection == kI2C_MasterReceive)
    {
        I2C_SendAck(psHandle->base, false);

#if (I2C_RETRY_TIMES > 0U)
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(psHandle->base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(psHandle->base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif
        I2C_MasterClearStatusFlags(psHandle->base, (uint16_t)kI2C_InterruptPendingFlag);

        result = I2C_MasterStop(psHandle->base);
        /* Do dummy read */
        (void)I2C_ReadByte(psHandle->base);
    }
    else
    {
#if (I2C_RETRY_TIMES > 0U)
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(psHandle->base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        /* Wait until data transfer complete. */
        while (0U == (I2C_MasterGetStatusFlags(psHandle->base) & (uint16_t)kI2C_InterruptPendingFlag))
        {
        }
#endif
        I2C_MasterClearStatusFlags(psHandle->base, (uint16_t)kI2C_InterruptPendingFlag);
        result = I2C_MasterStop(psHandle->base);
    }
    /* Disable module */
    I2C_Enable(psHandle->base, false);
#if I2C_SMBUS_ENABLE
    s_bIsMaster = false;
#endif /* I2C_SMBUS_ENABLE */
    return result;
}
/* ---------------------------------------- End of Master Transfer Sub-group ---------------------------------------- */

/* ------------------------------------------- Slave Transfer Sub-group --------------------------------------------- */
/*!
 * brief Initializes the I2C slave transfer in interrupt way.
 *
 * This function is responsible for initializig slave transfer handle, installing user callback, registering slave IRQ
 * handling function and opening global interrupt.
 *
 * param base I2C base pointer.
 * param psHandle pointer to i2c_slave_transfer_handle_t structure to store the transfer state.
 * param pfCallback pointer to user pfCallback function.
 * param pUserData User configurable pointer to any data, function, structure etc that user wish to use in the callback
 */
void I2C_SlaveTransferCreateHandle(I2C_Type *base,
                                   i2c_slave_transfer_handle_t *psHandle,
                                   i2c_slave_transfer_callback_t pfCallback,
                                   void *pUserData)
{
    assert(NULL != psHandle);

    uint32_t instance = I2C_GetInstance(base);

    /* Zero handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Register pfCallback and pUserData. */
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;
    psHandle->base       = base;
    psHandle->u8State    = (uint8_t)kSlaveTurnedOffState;
    /* Save the context in global variables to support the double weak mechanism. */
    s_pI2cHandles[instance] = psHandle;

    /* Register slave interrupt service routine. */
    s_pfI2cSlaveIsr = I2C_SlaveTransferHandleIRQ;

    /* Enable I2C global IRQ. */
    (void)EnableIRQ(s_eI2cIrqs[instance]);
}

/*!
 * brief Sets I2C slave ready to process bus events.
 *
 * Call this API to let I2C start monitoring bus events driven by I2C master on bus. When user specified event occurs,
 * callback will be invoked passes event information to the callback.
 *
 * note When #kI2C_SlaveOutofTransmitDataEvent and #kI2C_SlaveOutofReceiveSpaceEvent occured, slave callback will
 * always be revoked regardless which events user choose to enable. This means user need not configure them in the
 * psTransferConfig. If user wants to enable all the events, use #kI2C_SlaveAllEvents for convenience.
 *
 * param psHandle Pointer to i2c_slave_transfer_handle_t structure which stores the transfer state.
 * param psTransferConfig I2C transfer configuration.
 * retval kStatus_Success I2C slave set to standby state successfully and ready to process events.
 * retval kStatus_I2C_Busy I2C slave has already been started on this handle.
 */
status_t I2C_SlaveTransferNonBlocking(i2c_slave_transfer_handle_t *psHandle, i2c_slave_transfer_t *psTransferConfig)
{
    assert(NULL != psHandle);
    /* Transactional layer does not support slave 10-bit address. */
    assert((psHandle->base->C2 & I2C_C2_ADEXT_MASK) == 0U);

    /* Check if I2C bus is already in an active transfer. */
    if ((uint8_t)kSlaveBusyState == psHandle->u8State)
    {
        return kStatus_I2C_Busy;
    }
    else
    {
        I2C_Enable(psHandle->base, true);
        /* Disable I2C IRQ sources when configuring. */
        I2C_DisableInterrupts(psHandle->base, (uint8_t)kI2C_AllInterruptEnable);

        /* Zero transfer in handle. */
        (void)memset(&psHandle->sTransfer, 0, sizeof(psHandle->sTransfer));
        /* Initialize the handle's transfer information. */
        /* Set up event mask. tx and rx are always enabled. */
        psHandle->sTransfer.u8EventMask = psTransferConfig->u8EventMask | (uint8_t)kI2C_SlaveOutofTransmitDataEvent |
                                          (uint8_t)kI2C_SlaveOutofReceiveSpaceEvent;
        psHandle->sTransfer.pu8Data     = psTransferConfig->pu8Data;
        psHandle->sTransfer.u16DataSize = psTransferConfig->u16DataSize;

        /* Change to idle state to indicate this I2C slave is ready to monitor and process bus events. */
        psHandle->u8State = (uint8_t)kSlaveIdleState;

        /* Clear all status flags. */
        I2C_SlaveClearStatusFlags(psHandle->base, (uint16_t)kI2C_StatusAllFlags);

#if I2C_SMBUS_ENABLE
        s_bIsMaster = false;
#endif /* I2C_SMBUS_ENABLE */

        /* Enable I2C internal IRQ sources. */
        I2C_EnableInterrupts(psHandle->base, (uint8_t)kI2C_AllInterruptEnable);
    }

    return kStatus_Success;
}

/*!
 * brief Gets how many bytes slave have transferred after the last start/repeated start signal.
 *
 * param psHandle pointer to i2c_slave_transfer_handle_t structure.
 * param count Number of bytes slave have transferred after the last start/repeated start.
 * retval kStatus_InvalidArgument count is Invalid.
 * retval kStatus_NoTransferInProgress Curent no transfer is in progress.
 * retval kStatus_Success Successfully obtained the count.
 */
status_t I2C_SlaveTransferGetCount(i2c_slave_transfer_handle_t *psHandle, uint16_t *count)
{
    assert(NULL != psHandle);

    if (NULL == count)
    {
        return kStatus_InvalidArgument;
    }

    /* Check whether I2C bus is in active transfer, that is whether start signal is detected. */
    if ((uint8_t)kSlaveBusyState != psHandle->u8State)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    /* Calculate transfer count. */
    *count = psHandle->u16TransferredCount;

    return kStatus_Success;
}

/*!
 * brief Aborts the slave transfer.
 *
 * note This API can be called at any time to stop slave for handling further bus events.
 *
 * param psHandle pointer to i2c_slave_transfer_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferAbort(i2c_slave_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    /* If this I2C instance has not been set up to process I2C event, no need to abort transfer, */
    if ((uint8_t)kSlaveTurnedOffState != psHandle->u8State)
    {
        /* Disable interrupts. */
        I2C_DisableInterrupts(psHandle->base, (uint8_t)kI2C_AllInterruptEnable);

        /* Zero transfer infomation in handle. */
        (void)memset(&psHandle->sTransfer, 0, sizeof(psHandle->sTransfer));

        /* Reset the state to turned off. */
        psHandle->u8State = (uint8_t)kSlaveTurnedOffState;

        /* Disable module */
        I2C_Enable(psHandle->base, false);
    }
}
/* ---------------------------------------- End of SLave Transfer Sub-group ----------------------------------------- */
/* ========================================= End of Transactional API Group ========================================= */

/* ============================================ Driver Internal Functions =========================================== */
static void I2C_SetHoldTime(I2C_Type *base, uint32_t u32SclStopHoldTime_ns, uint32_t u32SourceClock_Hz)
{
    uint32_t u32Multiplier;
    uint32_t u32ComputedSclHoldTime;
    uint32_t u32AbsError;
    uint32_t u32BestError = UINT32_MAX;
    uint32_t u32BestMult  = 0u;
    uint32_t u32BestIcr   = 0u;
    uint32_t u32Flag      = 1u;
    uint8_t u8Mult;
    uint8_t i;

    /* Search for the settings with the lowest error. Mult is the MULT field of the I2C_F register,
     * and ranges from 0-2. It selects the u32Multiplier factor for the divider. */
    /* SDA hold time = bus period (s) * mul * SDA hold value. */
    /* SCL start hold time = bus period (s) * mul * SCL start hold value. */
    /* SCL stop hold time = bus period (s) * mul * SCL stop hold value. */

    for (u8Mult = 0u; u8Mult <= 2u; ++u8Mult)
    {
        if (u32BestError == 0u)
        {
            break;
        }

        u32Multiplier = u32Flag << u8Mult;

        /* Scan table to find best match. */
        for (i = 0u; i < sizeof(s_u16I2cDividerTable) / sizeof(s_u16I2cDividerTable[0]); ++i)
        {
            /* Assume SCL hold(stop) value = s_u16I2cDividerTable[i]/2. */
            u32ComputedSclHoldTime =
                ((u32Multiplier * s_u16I2cDividerTable[i]) * 500000U) / (u32SourceClock_Hz / 1000U);
            u32AbsError = u32SclStopHoldTime_ns > u32ComputedSclHoldTime ?
                              (u32SclStopHoldTime_ns - u32ComputedSclHoldTime) :
                              (u32ComputedSclHoldTime - u32SclStopHoldTime_ns);

            if (u32AbsError < u32BestError)
            {
                u32BestMult  = u8Mult;
                u32BestIcr   = i;
                u32BestError = u32AbsError;

                /* If the error is 0, then we can stop searching because we won't find a better match. */
                if (u32AbsError == 0u)
                {
                    break;
                }
            }
        }
    }

    /* Set frequency register based on best settings. */
    base->F = I2C_F_MULT(u32BestMult) | I2C_F_ICR(u32BestIcr);
}

static status_t I2C_MasterCheckAndClearError(I2C_Type *base, uint16_t u16Status)
{
    status_t result = kStatus_Success;

    /* Check arbitration lost. */
    if (0U != (u16Status & (uint16_t)kI2C_ArbitrationLostInterruptFlag))
    {
        /* Clear arbitration lost flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_ArbitrationLostInterruptFlag);
        result = kStatus_I2C_ArbitrationLost;
    }
    /* Check NAK */
    else if (0U != (u16Status & (uint16_t)kI2C_ReceiveNakFlag))
    {
        result = kStatus_I2C_Nak;
    }
    else
    {
        /* Add this to fix MISRA C2012 rule15.7 issue: Empty else without comment. */
    }

    return result;
}

static status_t I2C_MasterTransferInitStateMachine(i2c_master_transfer_handle_t *psHandle,
                                                   i2c_master_transfer_t *psTransferConfig)
{
    I2C_Type *base                            = psHandle->base;
    status_t result                           = kStatus_Success;
    i2c_master_transfer_direction_t direction = psTransferConfig->eDirection;

    /* Initialize the handle transfer information. */
    psHandle->sTransfer = *psTransferConfig;

    /* Save total transfer size. */
    psHandle->u16TransferSize = psTransferConfig->u16DataSize;

    /* Set transfer direction to write if there is command. */
    if (psHandle->sTransfer.u8CommandSize > 0u)
    {
        if (psTransferConfig->eDirection == kI2C_MasterReceive)
        {
            direction = kI2C_MasterTransmit;
        }
    }

    /* Initialize transfer state. */
    psHandle->u8State = (uint8_t)kMasterCheckAddressState;

    /* Clear all status before transfer. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StatusAllFlags);

    /* Handle no start option. */
    if (0U != (psHandle->sTransfer.u8ControlFlagMask & (uint8_t)kI2C_TransferNoStartFlag))
    {
        /* No need to send start flag, go to send command or data phase directly. */
        if (psHandle->sTransfer.u8CommandSize > 0u)
        {
            psHandle->u8State = (uint8_t)kMasterSendCommandState;
        }
        else
        {
            if (direction == kI2C_MasterTransmit)
            {
                /* Next state, send data. */
                psHandle->u8State = (uint8_t)kMasterSendDataState;
            }
            else
            {
                /* According to I2C protocol, do not read with no start signal. */
                return kStatus_InvalidArgument;
            }
        }

        /* Wait for transfer complete bit and manually trigger tx interrupt. */
#if (I2C_RETRY_TIMES > 0U)
        uint32_t u32WaitTimes = I2C_RETRY_TIMES;
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
        {
            if (0U == (--u32WaitTimes))
            {
                return kStatus_I2C_Timeout;
            }
        }
#else
        while (0U == (I2C_MasterGetStatusFlags(base) & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
        {
        }
#endif
        I2C_MasterTransferHandleIRQ(psHandle);
    }
    /* If repeated start is requested, send repeated start. */
    else if (0U != (psHandle->sTransfer.u8ControlFlagMask & (uint8_t)kI2C_TransferRepeatedStartFlag))
    {
        result = I2C_MasterRepeatedStart(base, psHandle->sTransfer.u8SlaveAddress, direction);
    }
    else /* For normal transfer, send start. */
    {
        result = I2C_MasterStart(base, psHandle->sTransfer.u8SlaveAddress, direction);
    }

    return result;
}

static status_t I2C_MasterTransferRunStateMachine(i2c_master_transfer_handle_t *psHandle, bool *bIsDone)
{
    uint8_t u8Tmpdata;
    I2C_Type *base  = psHandle->base;
    *bIsDone        = false;
    bool bSendStop  = ((psHandle->sTransfer.u8ControlFlagMask & (uint8_t)kI2C_TransferNoStopFlag) == 0U);
    status_t result = I2C_MasterCheckAndClearError(base, I2C_MasterGetStatusFlags(base));
#if (!I2C_SMBUS_ENABLE)
    uint16_t u16TmpdataSize = psHandle->sTransfer.u16DataSize;
    bool bIgnoreNak         = ((psHandle->u8State == (uint8_t)kMasterSendDataState) && (u16TmpdataSize == 0U)) ||
                      ((psHandle->u8State == (uint8_t)kMasterReceiveDataState) && (u16TmpdataSize == 1U));
    /* Check & clear error flags. */
    /* Ignore Nak when it's for the last byte. */
    if ((result == kStatus_I2C_Nak) && bIgnoreNak)
    {
        result = kStatus_Success;
    }
#endif

    /* Handle Check address state to check whether the slave address is nacked during slave probing. */
    if (psHandle->u8State == (uint8_t)kMasterCheckAddressState)
    {
        if (result == kStatus_I2C_Nak)
        {
            result = kStatus_I2C_Addr_Nak;
        }
        else
        {
            /* Next state, send command. */
            if (psHandle->sTransfer.u8CommandSize > 0U)
            {
                psHandle->u8State = (uint8_t)kMasterSendCommandState;
            }
            else
            {
                if (psHandle->sTransfer.eDirection == kI2C_MasterTransmit)
                {
                    /* Next state, send data. */
                    psHandle->u8State = (uint8_t)kMasterSendDataState;
                }
                else
                {
                    /* Next state, receive data begin. */
                    psHandle->u8State = (uint8_t)kMasterReceiveDataBeginState;
                }
            }
        }
    }

#if I2C_SMBUS_ENABLE
    if ((kStatus_Success != result) & (psHandle->u8State != (uint8_t)kMasterCheckSentPecResponseState))
#else
    if (kStatus_Success != result)
#endif /* I2C_SMBUS_ENABLE */
    {
        return result;
    }

    /* Run state machine. */
    switch (psHandle->u8State)
    {
        /* Send I2C command. */
        case (uint8_t)kMasterSendCommandState:
            if (0U != (psHandle->sTransfer.u8CommandSize))
            {
                psHandle->sTransfer.u8CommandSize--;
#if I2C_SMBUS_ENABLE
                I2C_UpdateCrc8(&s_u8MasterCrcValue, psHandle->sTransfer.pu8Command, 1U);
#endif /* I2C_SMBUS_ENABLE */
                /* Send I2C command byte by byte. */
                I2C_WriteByte(base, *psHandle->sTransfer.pu8Command++);
            }
            else
            {
                if (psHandle->sTransfer.eDirection == kI2C_MasterTransmit)
                {
                    /* Send first byte of data. */
                    if (psHandle->sTransfer.u16DataSize > 0U)
                    {
                        /* Next state, send data. */
                        psHandle->u8State = (uint8_t)kMasterSendDataState;
#if I2C_SMBUS_ENABLE
                        I2C_UpdateCrc8(&s_u8MasterCrcValue, psHandle->sTransfer.pu8Data, 1U);
#endif /* I2C_SMBUS_ENABLE */
                        I2C_WriteByte(base, *psHandle->sTransfer.pu8Data);
                        psHandle->sTransfer.pu8Data++;
                        psHandle->sTransfer.u16DataSize--;
                    }
                    else
                    {
#if I2C_SMBUS_ENABLE
                        if (bSendStop)
                        {
                            /* Send calculated PEC. */
                            I2C_WriteByte(base, s_u8MasterCrcValue);
                            /* Next state, check how slave response to PEC byte. */
                            psHandle->u8State = (uint8_t)kMasterCheckSentPecResponseState;
                        }
#else  /* I2C_SMBUS_ENABLE */
                        /* When data size is zero, transfer is done. */
                        *bIsDone = true;
#endif /* I2C_SMBUS_ENABLE */
                    }
                }
                else
                {
                    /* Send repeated start and slave address. */
                    result = I2C_MasterRepeatedStart(base, psHandle->sTransfer.u8SlaveAddress, kI2C_MasterReceive);
                    /* Next state, receive data begin. */
                    psHandle->u8State = (uint8_t)kMasterReceiveDataBeginState;
                }
            }
            break;

        /* Send I2C data. */
        case (uint8_t)kMasterSendDataState:
            /* Send one byte of data. */
            if (psHandle->sTransfer.u16DataSize > 0U)
            {
#if I2C_SMBUS_ENABLE
                I2C_UpdateCrc8(&s_u8MasterCrcValue, psHandle->sTransfer.pu8Data, 1U);
#endif /* I2C_SMBUS_ENABLE */
                I2C_WriteByte(base, *psHandle->sTransfer.pu8Data);
                psHandle->sTransfer.pu8Data++;
                psHandle->sTransfer.u16DataSize--;
            }
            else
            {
#if I2C_SMBUS_ENABLE
                if (bSendStop)
                {
                    /* Send calculated PEC. */
                    I2C_WriteByte(base, s_u8MasterCrcValue);
                    /* Next state, check how slave response to PEC byte. */
                    psHandle->u8State = (uint8_t)kMasterCheckSentPecResponseState;
                }
                else
                {
#endif /* I2C_SMBUS_ENABLE */
                    /* When data size is zero, transfer is done. */
                    *bIsDone = true;
#if I2C_SMBUS_ENABLE
                }
#endif /* I2C_SMBUS_ENABLE */
            }
            break;

#if I2C_SMBUS_ENABLE
        case (uint8_t)kMasterCheckSentPecResponseState:
            if (kStatus_I2C_Nak == result)
            {
                result = kStatus_I2C_Pec_Error;
            }
            else
            {
                /* Transfer done after checking PEC */
                *bIsDone = true;
            }
            break;
#endif /* I2C_SMBUS_ENABLE */

        /* Start I2C data receive. This state is used to check if the transfer size is 1 if not using SMBus mode.
           If so, the nack signal should be issued before receiving the last byte. */
        case (uint8_t)kMasterReceiveDataBeginState:

#if I2C_MASTER_FACK_CONTROL
            I2C_EnableFastAck(base, true);
#endif /* I2C_MASTER_FACK_CONTROL */
            /* Setup the I2C peripheral to receive data. */
            I2C_SetTransferDirection(base, kI2C_Read);

            /* Do dummy read to release the bus. */
            (void)I2C_ReadByte(base);

#if (!I2C_SMBUS_ENABLE)
            if (psHandle->sTransfer.u16DataSize == 1U)
            {
                /* Send an non-acknowledge signal to the bus on the following receiving byte. */
                I2C_SendAck(base, false);
#if I2C_MASTER_FACK_CONTROL
                /* Disable fast ACK for the last receving byte. */
                I2C_EnableFastAck(base, false);
#endif /* I2C_MASTER_FACK_CONTROL */
            }
#endif /* I2C_SMBUS_ENABLE */

            /* Next state, receive data. */
            psHandle->u8State = (uint8_t)kMasterReceiveDataState;
            break;

        /* Receive I2C data. */
        case (uint8_t)kMasterReceiveDataState:

            /* Receive one byte of data. */
            if (0U != (psHandle->sTransfer.u16DataSize--))
            {
                if (psHandle->sTransfer.u16DataSize == 0U)
                {
                    /* Only check received PEC when stop signal should be issued. */
                    if (bSendStop)
                    {
#if (!I2C_SMBUS_ENABLE)
                        result   = I2C_MasterStop(base);
                        *bIsDone = true;
#endif /* I2C_SMBUS_ENABLE */
                    }
                    else /* Otherwise curent process is done. */
                    {
                        I2C_SetTransferDirection(base, kI2C_Write);
                        *bIsDone = true;
                    }
                }

                /* Read the data byte into the transfer buffer. */
                u8Tmpdata                    = I2C_ReadByte(base);
                *psHandle->sTransfer.pu8Data = u8Tmpdata;
                psHandle->sTransfer.pu8Data++;
#if I2C_SMBUS_ENABLE
                I2C_UpdateCrc8(&s_u8MasterCrcValue, &u8Tmpdata, 1U);
                if ((psHandle->sTransfer.u16DataSize == 0U) && (bSendStop))
                {
                    I2C_SendAck(base, false);
                    psHandle->u8State = (uint8_t)kMasterCheckReceivedPecState;
                }
#else /* I2C_SMBUS_ENABLE */
#if I2C_MASTER_FACK_CONTROL
                if (psHandle->sTransfer.u16DataSize != 0U)
                {
                    I2C_AckByte(base, true);
                }
#endif
                if (psHandle->sTransfer.u16DataSize == 1U)
                {
                    /* Issue NACK on read. */
                    I2C_SendAck(base, false);
#if I2C_MASTER_FACK_CONTROL
                    I2C_EnableFastAck(base, false);
#endif
                }
#endif /* I2C_SMBUS_ENABLE */
            }
            break;

#if I2C_SMBUS_ENABLE
        case (uint8_t)kMasterCheckReceivedPecState:
            /* Issue STOP command before reading last PEC byte. */
            result = I2C_MasterStop(base);
            /* Read PEC byte from the data register and check with calculation. */
            if (I2C_ReadByte(base) == s_u8MasterCrcValue)
            {
                *bIsDone = true;
            }
            else
            {
                result = kStatus_I2C_Pec_Error;
            }
            break;
#endif /* I2C_SMBUS_ENABLE */

        default:
            /* Add this to fix MISRA C2012 rule 16.4 issue: Empty default. */
            assert(false);
            break;
    }

    return result;
}

void I2C_MasterTransferHandleIRQ(void *pI2CHandle)
{
    assert(NULL != pI2CHandle);

    i2c_master_transfer_handle_t *psHandle = (i2c_master_transfer_handle_t *)pI2CHandle;
    I2C_Type *base                         = psHandle->base;
    status_t result                        = kStatus_Success;
    /* When bIsDone is true, it means all the data is transferred. */
    bool bIsDone;

    /* Clear the interrupt flag. */
    I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_InterruptPendingFlag);

    /* Check transfer complete flag. */
    result = I2C_MasterTransferRunStateMachine(psHandle, &bIsDone);
#if I2C_SMBUS_ENABLE
    if (result == kStatus_I2C_ArbitrationLost)
    {
        i2c_master_transfer_direction_t direction = psHandle->sTransfer.eDirection;
        if (psHandle->sTransfer.u8CommandSize > 0u)
        {
            direction = kI2C_MasterTransmit;
        }
        while (psHandle->sTransfer.u8RetryTimes--)
        {
            if (I2C_MasterStart(base, psHandle->sTransfer.u8SlaveAddress, direction) == 0)
            {
                /* Break if start signal is successfully isued. */
                break;
            }
        }
    }
#endif /* I2C_SMBUS_ENABLE */

    /* Stop the transfer, if all the data is transferred,
       or the transfer result indicate error due slave nack or arbitration lost. */
    if ((true == bIsDone) || (0 != result))
    {
        /* Send stop command if stop signal is requested, or nacked by slave. */
        if ((0U == (psHandle->sTransfer.u8ControlFlagMask & (uint8_t)kI2C_TransferNoStopFlag)) ||
            (result == kStatus_I2C_Nak) || (result == kStatus_I2C_Addr_Nak))
        {
            /* If arbitration is lost, I2C loses master state, no need to issue stop. */
            if (I2C_IsMaster(base))
            {
                (void)I2C_MasterStop(base);
            }
        }

        /* Restore handle to idle state. */
        psHandle->u8State = (uint8_t)kMasterIdleState;

        /* Disable interrupt. */
        I2C_DisableInterrupts(base, (uint8_t)kI2C_GlobalInterruptEnable);

#if I2C_SMBUS_ENABLE
        s_bIsMaster = false;
#endif /* I2C_SMBUS_ENABLE */

        psHandle->completionStatus = result;
        /* Call the Callback function after the function has completed. */
        if (NULL != (psHandle->pfCompletionCallback))
        {
            psHandle->pfCompletionCallback(psHandle);
        }
    }
}

void I2C_SlaveTransferHandleIRQ(void *pI2CHandle)
{
    assert(NULL != pI2CHandle);
    /* Save address byte */
    uint8_t address;
    bool bDoTransmit                      = false;
    i2c_slave_transfer_handle_t *psHandle = (i2c_slave_transfer_handle_t *)pI2CHandle;
    I2C_Type *base                        = psHandle->base;
    i2c_slave_transfer_t *psTransfer;
    uint16_t u8TmpdataSize = 0;

    uint16_t u16StatusFlags = I2C_SlaveGetStatusFlags(base);
    psTransfer              = &(psHandle->sTransfer);

#ifdef I2C_HAS_STOP_DETECT
    /* Check stop flag. */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_StopDetectInterruptFlag))
    {
#if I2C_SMBUS_ENABLE
        /* Reset CRC value when stop signal */
        s_u8SlaveCrcValue = 0U;
        I2C_EnableFastAck(base, false);
#endif /* I2C_SMBUS_ENABLE */
        /* Clear the stop detect and interrupt flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StopDetectInterruptFlag | (uint16_t)kI2C_InterruptPendingFlag);

        /* Bus state u8State is set to kSlaveBusyState after slave address match, and is set to kSlaveIdleState after
           slave detects nack or stop or all the user configured data is transferred. If master nacks slave, stop signal
           follows, in this case u8State is already set to kSlaveIdleState and callback invoked, so have a check of the
           state here in case before this stop detected the state is already idle. */
        if ((uint8_t)kSlaveBusyState == psHandle->u8State)
        {
            psHandle->u8State          = (uint8_t)kSlaveIdleState;
            psTransfer->eEvent         = kI2C_SlaveCompletionEvent;
            psHandle->completionStatus = kStatus_Success;

            /* If user configured to invoke call back when stop is detected and Callback is properly installed before
             */
            if ((0U != (psHandle->sTransfer.u8EventMask & (uint8_t)kI2C_SlaveCompletionEvent)) &&
                (NULL != psHandle->pfCallback))
            {
                psHandle->pfCallback(psHandle);
            }
        }

        if (0U == (u16StatusFlags & (uint16_t)kI2C_AddressAsSlaveInterruptFlag))
        {
            return;
        }
    }
#endif /* I2C_HAS_STOP_DETECT */

#if defined(FSL_FEATURE_I2C_HAS_START_STOP_DETECT) && FSL_FEATURE_I2C_HAS_START_STOP_DETECT
    /* Check start flag, repeated start can also set this flag. */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_StartDetectInterruptFlag))
    {
#if I2C_SMBUS_ENABLE
        I2C_EnableFastAck(base, false);
#endif /* I2C_SMBUS_ENABLE */
        /* Clear the start detect and interrupt flag. */
        I2C_MasterClearStatusFlags(base, (uint16_t)kI2C_StartDetectInterruptFlag | (uint16_t)kI2C_InterruptPendingFlag);

        psHandle->u8State          = (uint8_t)kSlaveBusyState;
        psTransfer->eEvent         = kI2C_SlaveStartEvent;
        psHandle->completionStatus = kStatus_Success;

        /* If user configured to invoke call back when start is detected and Callback is properly installed before */
        if ((0U != (psHandle->sTransfer.u8EventMask & (uint8_t)kI2C_SlaveStartEvent)) && (NULL != psHandle->pfCallback))
        {
            psHandle->pfCallback(psHandle);
        }

        if (0U == (u16StatusFlags & (uint16_t)kI2C_AddressAsSlaveInterruptFlag))
        {
            return;
        }
    }
#endif /* FSL_FEATURE_I2C_HAS_START_STOP_DETECT */

    /* Clear the interrupt flag. */
    I2C_MasterClearStatusFlags(base, u16StatusFlags);

#if I2C_SMBUS_ENABLE
    /* Check arbitrtion lost, slave can lost arbitrtion to alert response address. */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_ArbitrationLostInterruptFlag))
    {
        /* If lost arbitration to alert response, set state to idle and invoke callback with
         * kStatus_I2C_ArbitrationLost.
         */
        psHandle->u8State          = kSlaveIdleState;
        psTransfer->eEvent         = kI2C_SlaveCompletionEvent;
        psHandle->completionStatus = kStatus_I2C_ArbitrationLost;

        if ((0U != (psHandle->sTransfer.u8EventMask & (uint8_t)kI2C_SlaveCompletionEvent)) &&
            (NULL != psHandle->pfCallback))
        {
            psHandle->pfCallback(psHandle);
        }
    }
#endif /* I2C_SMBUS_ENABLE */

    /* Check address match. */
    if (0U != (u16StatusFlags & (uint16_t)kI2C_AddressAsSlaveInterruptFlag))
    {
#if I2C_SMBUS_ENABLE
        I2C_EnableFastAck(base, false);
#endif /* I2C_SMBUS_ENABLE */
        /* Set transfer state to busy to indicate that a transfer is in process. */
        psHandle->u8State          = (uint8_t)kSlaveBusyState;
        psHandle->completionStatus = kStatus_Success;
        /* Save the address match event. */
        psTransfer->eEvent = kI2C_SlaveAddressMatchEvent;
        /* Slave transmit, master reading from slave. */
        if (0U != (u16StatusFlags & (uint16_t)kI2C_SlaveTransmitFlag))
        {
            /* Change direction to send data. */
            bDoTransmit = true;
            I2C_SetTransferDirection(base, kI2C_Write);
#if I2C_SMBUS_ENABLE
            address = I2C_ReadByte(base);
            if (address == 0x19U)
            {
                /* Data read out is 0x19, indicates this is a alert response, change the event to alert response. */
                psTransfer->eEvent = kI2C_SlaveAlertResponseEvent;
                /* Send back slave's own address immediately to response. */
                I2C_WriteByte(base, (uint8_t)((base->A1 & I2C_A1_AD_MASK) >> 1U));
            }
            I2C_UpdateCrc8(&s_u8SlaveCrcValue, &address, 1U);
#endif /* I2C_SMBUS_ENABLE */
        }
        else
        {
            /* Slave receive, master writing to slave. */
            I2C_SetTransferDirection(base, kI2C_Read);
            address = I2C_ReadByte(base);
            if (address == 0U)
            {
                /* Data read out is 0x00, indicates this is a general call, change the event to general call. */
                psTransfer->eEvent = kI2C_SlaveGenaralcallEvent;
            }
#if I2C_SMBUS_ENABLE
            I2C_UpdateCrc8(&s_u8SlaveCrcValue, &address, 1U);
#endif /* I2C_SMBUS_ENABLE */
        }

        if ((0U != (psHandle->sTransfer.u8EventMask & (uint8_t)psTransfer->eEvent)) && (NULL != psHandle->pfCallback))
        {
            psHandle->pfCallback(psHandle);
        }
    }
    /* Check NAK */
    else if (0U != (u16StatusFlags & (uint16_t)kI2C_ReceiveNakFlag))
    {
        /* Change direction to receive. */
        I2C_SetTransferDirection(base, kI2C_Read);

        /* Read dummy data to release bus. */
        (void)I2C_ReadByte(base);
#if I2C_SMBUS_ENABLE
        if ((psHandle->sTransfer.u16DataSize == 0U) && (psHandle->u8State == (uint8_t)kSlaveSendPECState))
#else
        if (psHandle->sTransfer.u16DataSize == 0U)
#endif /* I2C_SMBUS_ENABLE */
        {
#ifndef I2C_HAS_STOP_DETECT
            /* When nacked by master at the last byte,
            set event to slave complete, status to kStatus_Success and set state to idle. */
            psHandle->u8State          = kSlaveIdleState;
            psTransfer->eEvent         = kI2C_SlaveCompletionEvent;
            psHandle->completionStatus = kStatus_Success;

            if ((0U != (psHandle->sTransfer.u8EventMask & (uint8_t)kI2C_SlaveCompletionEvent)) &&
                (NULL != psHandle->pfCallback))
            {
                psHandle->pfCallback(psHandle);
            }
#endif /* I2C_HAS_STOP_DETECT */
        }
        else
        {
            /* When nacked by master before all the data finished transfer,
               set event to slave complete, status to kStatus_I2C_Nak and set stste back to idle. */
            psHandle->u8State          = (uint8_t)kSlaveIdleState;
            psTransfer->eEvent         = kI2C_SlaveCompletionEvent;
            psHandle->completionStatus = kStatus_I2C_Nak;

            if ((0U != (psHandle->sTransfer.u8EventMask & (uint8_t)kI2C_SlaveCompletionEvent)) &&
                (NULL != psHandle->pfCallback))
            {
                psHandle->pfCallback(psHandle);
            }
        }
    }
    /* Check byte transfer complete flag. */
    else if (0U != (u16StatusFlags & (uint16_t)kI2C_ByteTransferCompleteInterruptFlag))
    {
        /* Slave transmit, master reading from slave. */
        if (0U != (u16StatusFlags & (uint16_t)kI2C_SlaveTransmitFlag))
        {
            bDoTransmit = true;
        }
        else /* Slave receive, master sending to slave. */
        {
#if I2C_SMBUS_ENABLE
            if (psHandle->u8State == (uint8_t)kSlaveCheckReceivedPecState)
            {
                psHandle->completionStatus = kStatus_Success;
                if (I2C_ReadByte(base) == s_u8SlaveCrcValue)
                {
                    I2C_AckByte(base, true);
                }
                else
                {
                    I2C_AckByte(base, false);
                    psHandle->completionStatus = kStatus_I2C_Pec_Error;
                }
                I2C_EnableFastAck(base, false);
                /* Reset CRC value after calculation. */
                s_u8SlaveCrcValue  = 0U;
                psHandle->u8State  = kSlaveIdleState;
                psTransfer->eEvent = kI2C_SlaveCompletionEvent;

                if (NULL != psHandle->pfCallback)
                {
                    psHandle->pfCallback(psHandle);
                }
            }
            else
            {
#endif /* I2C_SMBUS_ENABLE */
                u8TmpdataSize = psTransfer->u16DataSize;
                /* If we're out of space to store data, invoke pfCallback to get more. */
                if ((NULL == psTransfer->pu8Data) || (0U == u8TmpdataSize))
                {
                    psTransfer->eEvent         = kI2C_SlaveOutofReceiveSpaceEvent;
                    psHandle->completionStatus = kStatus_Success;

                    if (NULL != psHandle->pfCallback)
                    {
                        psHandle->pfCallback(psHandle);
                    }

                    /* Clear the transferred count now that we have a new buffer. */
                    psHandle->u16TransferredCount = 0;
                }

                /* Slave receive, master writing to slave. */
                uint8_t data = I2C_ReadByte(base);
#if I2C_SMBUS_ENABLE
                I2C_UpdateCrc8(&s_u8SlaveCrcValue, &data, 1U);
#endif /* I2C_SMBUS_ENABLE */

                if (0U != (psHandle->sTransfer.u16DataSize))
                {
                    /* Receive data. */
                    *psHandle->sTransfer.pu8Data++ = data;
                    psHandle->sTransfer.u16DataSize--;
                    psHandle->u16TransferredCount++;
                    if (0U == psHandle->sTransfer.u16DataSize)
                    {
#if I2C_SMBUS_ENABLE
                        psHandle->u8State = (uint8_t)kSlaveCheckReceivedPecState;
                        I2C_EnableFastAck(base, true);
#else /* I2C_SMBUS_ENABLE */
#ifndef I2C_HAS_STOP_DETECT
                    /* When finishes transfer, set event to slave complete, status to kStatus_Success
                       and set state back to idle. */
                    psHandle->u8State          = kSlaveIdleState;
                    psTransfer->eEvent         = kI2C_SlaveCompletionEvent;
                    psHandle->completionStatus = kStatus_Success;

                    /* Proceed receive complete event. */
                    if (((psHandle->u8EventMask & (uint8_t)kI2C_SlaveCompletionEvent) != 0U) &&
                        (psHandle->pfCallback != NULL))
                    {
                        psHandle->pfCallback(psHandle);
                    }
#endif /* I2C_HAS_STOP_DETECT */
#endif /* I2C_SMBUS_ENABLE */
                    }
                }
#if I2C_SMBUS_ENABLE
            }
#endif /* I2C_SMBUS_ENABLE */
        }
    }
    else
    {
        /* Read dummy to release bus. */
        (void)I2C_ReadByte(base);
    }

    /* Send data if there is the need. */
    if (bDoTransmit)
    {
        uint8_t _u8TmpdataSize = (uint8_t)psTransfer->u16DataSize;

        /* If we're out of data to send, invoke pfCallback to get more. */
#if I2C_SMBUS_ENABLE
        if (((NULL == psTransfer->pu8Data) || (0U == _u8TmpdataSize)) &&
            (psHandle->u8State != (uint8_t)kSlaveSendPECState))
#else
        if ((NULL == psTransfer->pu8Data) || (0U == _u8TmpdataSize))
#endif
        {
            psTransfer->eEvent         = kI2C_SlaveOutofTransmitDataEvent;
            psHandle->completionStatus = kStatus_Success;

            if (NULL != psHandle->pfCallback)
            {
                psHandle->pfCallback(psHandle);
            }

            /* Clear the transferred count now that we have a new buffer. */
            psHandle->u16TransferredCount = 0;
        }
#if (!I2C_SMBUS_ENABLE)
        if (0U != (psHandle->sTransfer.u16DataSize))
        {
#else
        if ((0U != (psHandle->sTransfer.u16DataSize)) || (psHandle->u8State == (uint8_t)kSlaveSendPECState))
        {
            if (psHandle->u8State == (uint8_t)kSlaveSendPECState)
            {
                I2C_WriteByte(base, s_u8SlaveCrcValue);
                psHandle->u8State = kSlaveIdleState;
            }
            else
            {
                I2C_UpdateCrc8(&s_u8SlaveCrcValue, psHandle->sTransfer.pu8Data, 1U);
#endif
            /* Send data. */
            I2C_WriteByte(base, *psHandle->sTransfer.pu8Data++);
            psHandle->sTransfer.u16DataSize--;
            psHandle->u16TransferredCount++;
#if I2C_SMBUS_ENABLE
            if (psHandle->sTransfer.u16DataSize == 0U)
            {
                psHandle->u8State = (uint8_t)kSlaveSendPECState;
            }
        }
#endif /* I2C_SMBUS_ENABLE */
    }
    else
    {
        /* Switch to receive mode. */
        I2C_SetTransferDirection(base, kI2C_Read);

        /* Read dummy to release bus. */
        (void)I2C_ReadByte(base);

#if (!I2C_SMBUS_ENABLE)
#ifndef I2C_HAS_STOP_DETECT
        /* When finishes transfer, set event to slave complete, status to kStatus_Success
           and set state back to idle. */
        psHandle->u8State  = kSlaveIdleState;
        psTransfer->eEvent = kI2C_SlaveCompletionEvent;

        /* Proceed transmit done event. */
        if (((psHandle->u8EventMask & (uint8_t)kI2C_SlaveCompletionEvent) != 0U) && (psHandle->pfCallback != NULL))
        {
            psHandle->pfCallback(psHandle);
        }
#endif /* !FSL_FEATURE_I2C_HAS_START_STOP_DETECT or !FSL_FEATURE_I2C_HAS_STOP_DETECT */
#endif /* I2C_SMBUS_ENABLE */
    }
}
}

#if I2C_SMBUS_ENABLE
void I2C_UpdateCrc8(uint8_t *pu8CrcValue, uint8_t *pu8Data, uint16_t u16ByteCount)
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
                u8Crc = (u8Crc << 1) ^ 0xE0;
            }
            else
            {
                u8Crc = u8Crc << 1;
            }
        }
    }

    *pu8CrcValue = u8Crc;
}
#endif /* I2C_SMBUS_ENABLE */

static void I2C_TransferCommonIRQHandler(I2C_Type *base, void *pHandle)
{
#if I2C_SMBUS_ENABLE
    /* Check if I2C is in master state, when in SMBus mode the arbitration lost can also happen when slave react to
     * alert response. */
    if (I2C_IsMaster(base) || (s_bIsMaster))
#else  /* I2C_SMBUS_ENABLE */
        uint16_t u16TmpS = I2C_MasterGetStatusFlags(base);
        /* Check if I2C is in master state, when arbitration lost master state will switch to slave state. */
        if (I2C_IsMaster(base) || (0U != (u16TmpS & (uint16_t)kI2C_ArbitrationLostInterruptFlag)))
#endif /* I2C_SMBUS_ENABLE */
    {
        s_pfI2cMasterIsr(pHandle);
    }
    else
    {
        s_pfI2cSlaveIsr(pHandle);
    }
    SDK_ISR_EXIT_BARRIER;
}
/* ======================================== End of Driver Internal Functions ======================================== */

/*!
 * brief Gets instance number for I2C module.
 *
 * param base I2C base pointer.
 * retval The number of the instance.
 */
uint32_t I2C_GetInstance(I2C_Type *base)
{
    uint32_t u32Instance;

    /* Find the instance index from base address mappings. */
    for (u32Instance = 0; u32Instance < ARRAY_SIZE(s_pfI2cBases); u32Instance++)
    {
        if (s_pfI2cBases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_pfI2cBases));

    return u32Instance;
}

/* ======================================= Second Layer IRQhandler defintion ======================================== */
#if defined(FSL_FEATURE_I2C_HAS_SHARED_IRQ0_IRQ1) && FSL_FEATURE_I2C_HAS_SHARED_IRQ0_IRQ1
void I2C0_I2C1_DriverIRQHandler(void);
void I2C0_I2C1_DriverIRQHandler(void)
{
    for (uint32_t instance = 0U; instance < 2U; instance++)
    {
        if (s_pI2cHandles[instance] != NULL)
        {
            I2C_TransferCommonIRQHandler(s_pfI2cBases[instance], s_pI2cHandles[instance]);
        }
    }
}
#else
#if defined(I2C0)
    void I2C0_DriverIRQHandler(void);
    void I2C0_DriverIRQHandler(void)
    {
        I2C_TransferCommonIRQHandler(I2C0, s_pI2cHandles[0]);
    }
#endif

#if defined(I2C1)
    void I2C1_DriverIRQHandler(void);
    void I2C1_DriverIRQHandler(void)
    {
        I2C_TransferCommonIRQHandler(I2C1, s_pI2cHandles[1]);
    }
#endif
#endif

#if defined(I2C2)
void I2C2_DriverIRQHandler(void);
void I2C2_DriverIRQHandler(void)
{
    I2C_TransferCommonIRQHandler(I2C2, s_pI2cHandles[2]);
}
#endif

#if defined(I2C3)
void I2C3_DriverIRQHandler(void);
void I2C3_DriverIRQHandler(void)
{
    I2C_TransferCommonIRQHandler(I2C3, s_pI2cHandles[3]);
}
#endif
/* =================================== End of Second Layer IRQhandler definition ==================================== */
