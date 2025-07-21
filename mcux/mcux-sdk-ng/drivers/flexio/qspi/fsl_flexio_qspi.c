/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020, 2022-2023, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexio_qspi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexio_qspi"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Send a piece of data for SPI.
 *
 * This function computes the number of data to be written into D register or Tx FIFO,
 * and write the data into it. At the same time, this function updates the values in
 * master handle structure.
 *
 * @param base pointer to FLEXIO_QSPI_Type structure
 * @param handle Pointer to SPI master handle structure.
 */
static void FLEXIO_QSPI_TransferSendTransaction(FLEXIO_QSPI_Type *base, flexio_qspi_master_handle_t *handle);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Codes
 ******************************************************************************/

static void FLEXIO_QSPI_TransferSendTransaction(FLEXIO_QSPI_Type *base, flexio_qspi_master_handle_t *handle)
{
    uint32_t tmpData;

    if (handle->txData != NULL)
    {
        /* Transmit data and update tx size/buff. */
        tmpData = *(uint32_t *)handle->txData;
        handle->txData += 4;
    }
    else
    {
        tmpData = FLEXIO_SPI_DUMMYDATA;
    }

    handle->txRemainingBytes -= 1;

    FLEXIO_QSPI_WriteData(base, tmpData);

    if (0U == handle->txRemainingBytes)
    {
        if(handle->current_buffer == (FLEXIO_QSPI_BUF_MAX-1) || handle->bufs[handle->current_buffer+1].dataSize == 0)
        {
            FLEXIO_QSPI_DisableInterrupts(base, (uint32_t)kFLEXIO_SPI_TxEmptyInterruptEnable);
        }
        else
        {
            handle->current_buffer += 1;
            handle->txData = handle->bufs[handle->current_buffer].txData;
            handle->transferSize = handle->bufs[handle->current_buffer].dataSize;
            handle->txRemainingBytes = handle->transferSize;
        }
    }
}

/*!
 * brief Ungates the FlexIO clock, resets the FlexIO module, configures the FlexIO SPI master hardware,
 * and configures the FlexIO SPI with FlexIO SPI master configuration. The
 * configuration structure can be filled by the user, or be set with default values
 * by the FLEXIO_QSPI_MasterGetDefaultConfig().
 *
 * note 1.FlexIO SPI master only support CPOL = 0, which means clock inactive low.
 *      2.For FlexIO SPI master, the input valid time is 1.5 clock cycles, for slave the output valid time
 *        is 2.5 clock cycles. So if FlexIO SPI master communicates with other spi IPs, the maximum baud
 *        rate is FlexIO clock frequency divided by 2*2=4. If FlexIO SPI master communicates with FlexIO
 *        SPI slave, the maximum baud rate is FlexIO clock frequency divided by (1.5+2.5)*2=8.
 *
 * Example
   code
   FLEXIO_QSPI_Type spiDev = {
   .flexioBase = FLEXIO,
   .SDOPinIndex = 0,
   .SDIPinIndex = 1,
   .SCKPinIndex = 2,
   .CSnPinIndex = 3,
   };
   flexio_spi_master_config_t config = {
   .enableMaster = true,
   .enableInDoze = false,
   .enableInDebug = true,
   .enableFastAccess = false,
   .baudRate_Bps = 500000,
   .phase = kFLEXIO_SPI_ClockPhaseFirstEdge,
   .dataMode = kFLEXIO_SPI_8BitMode
   };
   FLEXIO_QSPI_MasterInit(&spiDev, &config, srcClock_Hz);
   endcode
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param masterConfig Pointer to the flexio_spi_master_config_t structure.
 * param srcClock_Hz FlexIO source clock in Hz.
*/
void FLEXIO_QSPI_MasterInit(FLEXIO_QSPI_Type *base, flexio_spi_master_config_t *masterConfig, uint32_t srcClock_Hz)
{
    assert(base != NULL);
    assert(masterConfig != NULL);

    flexio_shifter_config_t shifterConfig;
    flexio_timer_config_t timerConfig;
    uint32_t ctrlReg  = 0;
    uint16_t timerDiv = 0;
    uint16_t timerCmp = 0;

    /* Clear the shifterConfig & timerConfig struct. */
    (void)memset(&shifterConfig, 0, sizeof(shifterConfig));
    (void)memset(&timerConfig, 0, sizeof(timerConfig));

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate flexio clock. */
    CLOCK_EnableClock(s_flexioClocks[FLEXIO_QSPI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Configure FLEXIO SPI Master */
    ctrlReg = base->flexioBase->CTRL;
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    ctrlReg &= ~(FLEXIO_CTRL_DOZEN_MASK | FLEXIO_CTRL_DBGE_MASK | FLEXIO_CTRL_FASTACC_MASK | FLEXIO_CTRL_FLEXEN_MASK);
#else
    ctrlReg &= ~(FLEXIO_CTRL_DBGE_MASK | FLEXIO_CTRL_FASTACC_MASK | FLEXIO_CTRL_FLEXEN_MASK);
#endif
    ctrlReg |= (FLEXIO_CTRL_DBGE(masterConfig->enableInDebug) | FLEXIO_CTRL_FASTACC(masterConfig->enableFastAccess) |
                FLEXIO_CTRL_FLEXEN(masterConfig->enableMaster));
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    if (!masterConfig->enableInDoze)
    {
        ctrlReg |= FLEXIO_CTRL_DOZEN_MASK;
    }
#endif

    base->flexioBase->CTRL = ctrlReg;

    /* Do hardware configuration. */
    /* 1. Configure the shifter 0 for tx. */
    shifterConfig.timerSelect = kFLEXIO_QSPI_TIMER0;
    shifterConfig.pinConfig   = kFLEXIO_PinConfigOutput;
    shifterConfig.pinSelect   = base->SDOPinIndex;
    shifterConfig.pinPolarity = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode = kFLEXIO_ShifterModeTransmit;
    shifterConfig.inputSource = kFLEXIO_ShifterInputFromPin;
    shifterConfig.parallelWidth = 3;
    if (masterConfig->phase == kFLEXIO_SPI_ClockPhaseFirstEdge)
    {
        shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnNegitive;
        shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitDisable;
        shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitDisabledLoadDataOnEnable;
    }
    else
    {
        shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnPositive;
        shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitLow;
        shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitDisabledLoadDataOnShift;
    }

    FLEXIO_SetShifterConfig(base->flexioBase, kFLEXIO_QSPI_SHIFTBUF0, &shifterConfig);

    /*3. Configure the timer 0 for SCK. */
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(kFLEXIO_QSPI_SHIFTBUF0);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutput;
    timerConfig.pinSelect       = base->SCKPinIndex;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode       = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputZeroNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerHigh;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitEnableOnTimerDisable;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitEnabled;
    /* Low 8-bits are used to configure baudrate. */
    timerDiv = (uint16_t)(srcClock_Hz / masterConfig->baudRate_Bps);
    timerDiv = timerDiv / 2U - 1U;
    /* High 8-bits are used to configure shift clock edges(transfer width). */
    timerCmp = ((uint16_t)masterConfig->dataMode * 2U - 1U) << 8U;
    timerCmp |= timerDiv;

    timerConfig.timerCompare = timerCmp;

    FLEXIO_SetTimerConfig(base->flexioBase, kFLEXIO_QSPI_TIMER0, &timerConfig);

    /* 4. Configure the timer 1 for CSn. */
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_TIMn(kFLEXIO_QSPI_TIMER0);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutput;
    timerConfig.pinSelect       = base->CSnPinIndex;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveLow;
    timerConfig.timerMode       = kFLEXIO_TimerModeSingle16Bit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnPreTimerDisable;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnPrevTimerEnable;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;

    timerConfig.timerCompare = 0xFFFFU; /* Never compare. */

    FLEXIO_SetTimerConfig(base->flexioBase, kFLEXIO_QSPI_TIMER1, &timerConfig);
}

/*!
 * brief Gets the default configuration to configure the FlexIO SPI master. The configuration
 * can be used directly by calling the FLEXIO_QSPI_MasterConfigure().
 * Example:
   code
   flexio_spi_master_config_t masterConfig;
   FLEXIO_QSPI_MasterGetDefaultConfig(&masterConfig);
   endcode
 * param masterConfig Pointer to the flexio_spi_master_config_t structure.
*/
void FLEXIO_QSPI_MasterGetDefaultConfig(flexio_spi_master_config_t *masterConfig)
{
    FLEXIO_SPI_MasterGetDefaultConfig(masterConfig);
}

/*!
 * brief Enables the FlexIO SPI interrupt.
 *
 * This function enables the FlexIO SPI interrupt.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param mask interrupt source. The parameter can be any combination of the following values:
 *        arg kFLEXIO_SPI_TxEmptyInterruptEnable
 */
void FLEXIO_QSPI_EnableInterrupts(FLEXIO_QSPI_Type *base, uint32_t mask)
{
    if ((mask & (uint32_t)kFLEXIO_SPI_TxEmptyInterruptEnable) != 0U)
    {
        FLEXIO_EnableShifterStatusInterrupts(base->flexioBase, 1UL << kFLEXIO_QSPI_SHIFTBUF0);
    }
}

/*!
 * brief Disables the FlexIO SPI interrupt.
 *
 * This function disables the FlexIO SPI interrupt.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param mask interrupt source The parameter can be any combination of the following values:
 *        arg kFLEXIO_SPI_TxEmptyInterruptEnable
 */
void FLEXIO_QSPI_DisableInterrupts(FLEXIO_QSPI_Type *base, uint32_t mask)
{
    if ((mask & (uint32_t)kFLEXIO_SPI_TxEmptyInterruptEnable) != 0U)
    {
        FLEXIO_DisableShifterStatusInterrupts(base->flexioBase, 1UL << kFLEXIO_QSPI_SHIFTBUF0);
    }
}


/*!
 * brief Gets FlexIO SPI status flags.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * return status flag; Use the status flag to AND the following flag mask and get the status.
 *          arg kFLEXIO_SPI_TxEmptyFlag
 */

uint32_t FLEXIO_QSPI_GetStatusFlags(FLEXIO_QSPI_Type *base)
{
    uint32_t shifterStatus = FLEXIO_GetShifterStatusFlags(base->flexioBase);
    uint32_t status        = 0;

    status = ((shifterStatus & (1UL << kFLEXIO_QSPI_SHIFTBUF0)) >> kFLEXIO_QSPI_SHIFTBUF0);

    return status;
}

/*!
 * brief Clears FlexIO SPI status flags.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param mask status flag
 *      The parameter can be any combination of the following values:
 *          arg kFLEXIO_SPI_TxEmptyFlag
 */

void FLEXIO_QSPI_ClearStatusFlags(FLEXIO_QSPI_Type *base, uint32_t mask)
{
    if ((mask & (uint32_t)kFLEXIO_SPI_TxBufferEmptyFlag) != 0U)
    {
        FLEXIO_ClearShifterStatusFlags(base->flexioBase, 1UL << kFLEXIO_QSPI_SHIFTBUF0);
    }
}

/*!
 * brief Sets baud rate for the FlexIO SPI transfer, which is only used for the master.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param baudRate_Bps Baud Rate needed in Hz.
 * param srcClockHz SPI source clock frequency in Hz.
 */
void FLEXIO_QSPI_MasterSetBaudRate(FLEXIO_QSPI_Type *base, uint32_t baudRate_Bps, uint32_t srcClockHz)
{
    uint16_t timerDiv       = 0;
    uint16_t timerCmp       = 0;
    FLEXIO_Type *flexioBase = base->flexioBase;

    /* Set TIMCMP[7:0] = (baud rate divider / 2) - 1.*/
    timerDiv = (uint16_t)(srcClockHz / baudRate_Bps);
    timerDiv = timerDiv / 2U - 1U;

    timerCmp = (uint16_t)(flexioBase->TIMCMP[kFLEXIO_QSPI_TIMER0]);
    timerCmp &= 0xFF00U;
    timerCmp |= timerDiv;

    flexioBase->TIMCMP[kFLEXIO_QSPI_TIMER0] = timerCmp;
}

/*!
 * brief Initializes the FlexIO SPI Master handle, which is used in transactional functions.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param handle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 * param callback The callback function.
 * param userData The parameter of the callback function.
 * retval kStatus_Success Successfully create the handle.
 * retval kStatus_OutOfRange The FlexIO type/handle/ISR table out of range.
 */
status_t FLEXIO_QSPI_MasterTransferCreateHandle(FLEXIO_QSPI_Type *base,
                                               flexio_qspi_master_handle_t *handle,
                                               flexio_qspi_master_transfer_callback_t callback,
                                               void *userData)
{
    assert(handle != NULL);

    IRQn_Type flexio_irqs[] = FLEXIO_IRQS;

    /* Zero the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Register callback and userData. */
    handle->callback = callback;
    handle->userData = userData;

    /* Clear pending NVIC IRQ before enable NVIC IRQ. */
    NVIC_ClearPendingIRQ(flexio_irqs[FLEXIO_QSPI_GetInstance(base)]);
    /* Enable interrupt in NVIC. */
    (void)EnableIRQ(flexio_irqs[FLEXIO_QSPI_GetInstance(base)]);

    /* Save the context in global variables to support the double weak mechanism. */
    return FLEXIO_RegisterHandleIRQ(base, handle, FLEXIO_QSPI_MasterTransferHandleIRQ);
}

/*!
 * brief Master transfer data using IRQ.
 *
 * This function sends data using IRQ. This is a non-blocking function, which returns
 * right away. When all data is sent out/received, the callback function is called.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param handle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 * param xfer FlexIO SPI transfer structure. See #flexio_qspi_transfer_t.
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_FLEXIO_QSPI_Busy SPI is not idle, is running another transfer.
 */
status_t FLEXIO_QSPI_MasterTransferNonBlocking(FLEXIO_QSPI_Type *base,
                                              flexio_qspi_master_handle_t *handle,
                                              flexio_qspi_transfer_t *xfer)
{
    assert(handle != NULL);
    assert(xfer != NULL);

    uint32_t tmpData;

    /* Check if SPI is busy. */
    if (handle->state == (uint32_t)kFLEXIO_QSPI_Busy)
    {
        return kStatus_FLEXIO_SPI_Busy;
    }

    /* Check if the argument is legal. */
    if (xfer->bufs[0].txData == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /* Timer1 controls the CS signal which enables/disables(asserts/deasserts) when timer0 enable/disable. Timer0
       enables when tx shifter is written and disables when timer compare. The timer compare event causes the
       transmit shift registers to load which generates a tx register empty event. Since when timer stop bit is
       disabled, a timer enable condition can be detected in the same cycle as a timer disable condition, so if
       software writes the tx register upon the detection of tx register empty event, the timer enable condition
       is triggered again, then the CS signal can remain low until software no longer writes the tx register. */
    if ((xfer->flags & (uint8_t)kFLEXIO_SPI_csContinuous) != 0U)
    {
        base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] =
            (base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] & ~FLEXIO_TIMCFG_TSTOP_MASK) |
            FLEXIO_TIMCFG_TSTOP(kFLEXIO_TimerStopBitDisabled);
    }
    else
    {
        base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] =
            (base->flexioBase->TIMCFG[kFLEXIO_QSPI_TIMER0] & ~FLEXIO_TIMCFG_TSTOP_MASK) |
            FLEXIO_TIMCFG_TSTOP(kFLEXIO_TimerStopBitEnableOnTimerDisable);
    }

    handle->state            = (uint32_t)kFLEXIO_QSPI_Busy;
    handle->txData           = xfer->bufs[0].txData;
    handle->current_buffer = 0;
    
    for(uint32_t i = 0; i < FLEXIO_QSPI_BUF_MAX; i++)
    {
        handle->bufs[i] = xfer->bufs[i];
    }

    /* Save total transfer size. */
    handle->transferSize = xfer->bufs[0].dataSize;

    /* Send first byte of data to trigger the rx interrupt. */
    if (handle->txData != NULL)
    {
        tmpData = *(uint32_t *)handle->txData;
        handle->txData += 4;
    }
    else
    {
        tmpData = FLEXIO_SPI_DUMMYDATA;
    }

    handle->txRemainingBytes = handle->transferSize - 1;

    FLEXIO_QSPI_WriteData(base, tmpData);

    /* Enable transmit and receive interrupt to handle rx. */
    FLEXIO_QSPI_EnableInterrupts(base, (uint32_t)kFLEXIO_SPI_TxEmptyInterruptEnable);

    return kStatus_Success;
}

/*!
 * brief Aborts the master data transfer, which used IRQ.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param handle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 */
void FLEXIO_QSPI_MasterTransferAbort(FLEXIO_QSPI_Type *base, flexio_qspi_master_handle_t *handle)
{
    assert(handle != NULL);

    FLEXIO_QSPI_DisableInterrupts(base, (uint32_t)kFLEXIO_SPI_TxEmptyInterruptEnable);

    /* Transfer finished, set the state to idle. */
    handle->state = (uint32_t)kFLEXIO_QSPI_Idle;

    /* Clear the internal state. */
    handle->txRemainingBytes = 0;
}

/*!
 * brief FlexIO SPI master IRQ handler function.
 *
 * param spiType Pointer to the FLEXIO_QSPI_Type structure.
 * param spiHandle Pointer to the flexio_qspi_master_handle_t structure to store the transfer state.
 */
void FLEXIO_QSPI_MasterTransferHandleIRQ(void *spiType, void *spiHandle)
{
    assert(spiHandle != NULL);

    flexio_qspi_master_handle_t *handle = (flexio_qspi_master_handle_t *)spiHandle;
    FLEXIO_QSPI_Type *base;
    uint32_t status;

    if (handle->state == (uint32_t)kFLEXIO_QSPI_Idle)
    {
        return;
    }

    base   = (FLEXIO_QSPI_Type *)spiType;
    status = FLEXIO_QSPI_GetStatusFlags(base);

    /* Handle tx. */
    if (((status & (uint32_t)kFLEXIO_SPI_TxBufferEmptyFlag) != 0U) && (handle->txRemainingBytes != 0U))
    {
        FLEXIO_QSPI_TransferSendTransaction(base, handle);
    }

    /* All the transfer finished. */
    if (handle->txRemainingBytes == 0U)
    {
        FLEXIO_QSPI_MasterTransferAbort(base, handle);
        if (handle->callback != NULL)
        {
            (handle->callback)(base, handle, kStatus_FLEXIO_SPI_Idle, handle->userData);
        }
    }
}

/*!
 * brief Flush tx/rx shifters.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 */
void FLEXIO_QSPI_FlushShifters(FLEXIO_QSPI_Type *base)
{
    /* Disable then re-enable to flush the tx shifter. */
    base->flexioBase->SHIFTCTL[kFLEXIO_QSPI_SHIFTBUF0] &= ~FLEXIO_SHIFTCTL_SMOD_MASK;
    base->flexioBase->SHIFTCTL[kFLEXIO_QSPI_SHIFTBUF0] |= FLEXIO_SHIFTCTL_SMOD(kFLEXIO_ShifterModeTransmit);
}

/*!
 * brief Enables/disables the FlexIO QSPI transmit DMA. This function enables/disables the FlexIO QSPI Tx DMA,
 * which means that asserting the kFLEXIO_QSPI_TxEmptyFlag does/doesn't trigger the DMA request.
 *
 * param base Pointer to the FLEXIO_QSPI_Type structure.
 * param mask SPI DMA source.
 * param enable True means enable DMA, false means disable DMA.
 */
void FLEXIO_QSPI_EnableDMA(FLEXIO_QSPI_Type *base, uint32_t mask, bool enable)
{
    if ((mask & (uint32_t)kFLEXIO_QSPI_TxDmaEnable) != 0U)
    {
        FLEXIO_EnableShifterStatusDMA(base->flexioBase, 1UL << kFLEXIO_QSPI_SHIFTBUF0, enable);
    }
}