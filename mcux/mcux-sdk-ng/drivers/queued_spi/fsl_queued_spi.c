/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_queued_spi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.queued_spi"
#endif

/*! @brief Typedef for master interrupt psHandler. */
typedef void (*qspi_master_isr_t)(qspi_master_transfer_handle_t *psHandle);

/*! @brief Typedef for slave interrupt psHandler. */
typedef void (*qspi_slave_isr_t)(qspi_slave_transfer_handle_t *psHandle);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Toggle PCS signal.
 * This is not a public API.
 */
static void QSPI_TogglePCS(QSPI_Type *base);

/*!
 * @brief Read data out of the RX FIFO.
 * This is not a public API.
 */
static void QSPI_TransferReadoutRxFifo(QSPI_Type *base, qspi_master_transfer_handle_t *psHandle);

/*!
 * @brief Fill up the TX FIFO with data.
 * This is not a public API.
 */
static void QSPI_TransferFillUpTxFifo(QSPI_Type *base, qspi_master_transfer_handle_t *psHandle);

/*!
 * @brief Master finishes up a transfer.
 * Calls call back if there is a callback function and set the state to idle.
 * This is not a public API.
 */
static void QSPI_MasterTransferComplete(QSPI_Type *base, qspi_master_transfer_handle_t *psHandle);

/*!
 * @brief Slave finishes up a transfer.
 * Calls call back if there is a callback function and set the state to idle.
 * This is not a public API.
 */
static void QSPI_SlaveTransferComplete(QSPI_Type *base, qspi_slave_transfer_handle_t *psHandle);

/*!
 * @brief QUEUEDSPI common interrupt IRQ psHandler.
 *
 * @param base QUEUEDSPI peripheral address.
 * @param param pointer to s_psQspiHandles which stores the transfer state.
 */
static void QSPI_CommonIRQHandler(QSPI_Type *base, void *param);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to queued_spi bases for each instance. */
static QSPI_Type *const s_psQspiBases[] = QSPI_BASE_PTRS;

/*! @brief Pointers to queued_spi IRQ number for each instance. */
static IRQn_Type const s_eQspiRXIRQs[] = QSPI_RX_IRQS;
static IRQn_Type const s_eQspiTXIRQs[] = QSPI_TX_IRQS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to queued_spi clocks for each instance. */
static clock_ip_name_t const s_eQspiClocks[] = QSPI_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Pointers to queued_spi psHandles for each instance. */
static void *s_psQspiHandles[ARRAY_SIZE(s_psQspiBases)];

/*! @brief Pointer to master IRQ psHandler for each instance. */
static qspi_master_isr_t s_pfQspiMasterIsr;

/*! @brief Pointer to slave IRQ psHandler for each instance. */
static qspi_slave_isr_t s_pfQspiSlaveIsr;

/* @brief Dummy data for each instance. This data is used when user's TX buffer is NULL. */
volatile static uint8_t s_u8DummyDatas[ARRAY_SIZE(s_psQspiBases)] = {0U};
/**********************************************************************************************************************
 * Code
 *********************************************************************************************************************/
/*!
 * brief Get instance number for QUEUEDSPI module.
 *
 * param base QUEUEDSPI peripheral base address.
 */
uint32_t QSPI_GetInstance(QSPI_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0U; instance < ARRAY_SIZE(s_psQspiBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_psQspiBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_psQspiBases));

    return instance;
}

/*!
 * brief Get dummy data for each instance.
 *
 * param base QUEUEDSPI peripheral base address.
 */
uint8_t QSPI_GetDummyData(QSPI_Type *base)
{
    uint8_t instance = s_u8DummyDatas[QSPI_GetInstance(base)];

    return instance;
}

/*!
 * brief Set up the dummy data.
 *
 * param base QUEUEDSPI peripheral address.
 * param u8DummyData Data to be transferred when TX buffer is NULL.
 */
void QSPI_SetDummyData(QSPI_Type *base, uint8_t u8DummyData)
{
    uint32_t instance        = QSPI_GetInstance(base);
    s_u8DummyDatas[instance] = u8DummyData;
}

/*!
 * @brief Toggle the Slave Select signal for master mode
 */
static void QSPI_TogglePCS(QSPI_Type *base)
{
    if (QSPI_MasterGetSlaveSelectLogicLevel(base) == kQSPI_SlaveSelectLogicHigh)
    {
        QSPI_MasterSetSlaveSelectLogicLevel(base, kQSPI_SlaveSelectLogicLow);
    }
    else
    {
        QSPI_MasterSetSlaveSelectLogicLevel(base, kQSPI_SlaveSelectLogicHigh);
    }
}

/*!
 * brief Initializes the QUEUEDSPI master.
 *
 * param base QUEUEDSPI peripheral address.
 * param psConfig Pointer to the structure qspi_master_config_t.
 * param u32SrcClockHz Module source input clock in Hertz.
 */
void QSPI_MasterInit(QSPI_Type *base, const qspi_master_config_t *psConfig)
{
    assert(NULL != psConfig);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable queued_spi clock */
    CLOCK_EnableClock(s_eQspiClocks[QSPI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Disable module before configuring. */
    QSPI_Enable(base, false);

    /* Set module as master. */
    QSPI_SetMasterSlaveMode(base, kQSPI_Master);

    /* Set CPHA, CPOL and date shift order. */
    QSPI_SetClockPolarity(base, psConfig->eClkPolarity);
    QSPI_SetClockPhase(base, psConfig->eClkPhase);
    QSPI_SetDataShiftOrder(base, psConfig->eShiftDirection);
    QSPI_EnableModeFault(base, psConfig->bEnableModeFault);

    /* Calculate baudrate devider. */
    if (0U == QSPI_MasterSetBaudRate(base, psConfig->u32BaudRateBps, psConfig->u32ClockFrequencyHz))
    {
        assert(false);
    }

    /* Set wired-or mode, PCS polarity and data width. */
    QSPI_EnableWiredORMode(base, psConfig->bEnableWiredOrMode);
    QSPI_EnableDMA(base, psConfig->u8DmaEnableFlags);

    /* Slave Select Signal Configuration */
    QSPI_MasterEnableSlaveSelectOpenDrainMode(base, psConfig->bEnableSlaveSelOpenDrain);

    /* Do not Enable auto Slave Select if mode default is enabled */
    if (psConfig->bEnableModeFault && psConfig->bEnableSlaveSelAutoMode)
    {
        /* Automatic mode shall not be used when Mode Fault detect is enabled. */
        assert(false);
    }
    else
    {
        QSPI_MasterEnableSlaveSelectAutomaticMode(base, psConfig->bEnableSlaveSelAutoMode);
    }

    /* Configure the Slave Select direction according to mode fault */
    if (psConfig->bEnableModeFault)
    {
        QSPI_SetSlaveSelectDirection(base, kQSPI_SlaveSelectDirectionInput);
    }
    else
    {
        QSPI_SetSlaveSelectDirection(base, kQSPI_SlaveSelectDIrectionOutput);
    }

    /* Do not Enable strobe if mode default is enabled */
    if (psConfig->bEnableModeFault && psConfig->bEnableStrobe)
    {
        /* Strobe mode shall not be used when Mode Fault detect is enabled. */
        assert(false);
    }
    else
    {
        QSPI_MasterEnableSlaveSelectStrobe(base, psConfig->bEnableStrobe);
    }

    /* Configure the Width of data */
    QSPI_SetTransactionDataSize(base, psConfig->eDataWidth);

    /* FIFO Configuration */
    QSPI_EnableFifo(base, psConfig->bEnableFIFO);
    if (psConfig->bEnableFIFO)
    {
        QSPI_SetFifoWatermarks(base, (uint16_t)psConfig->eTxFIFOWatermark, (uint16_t)psConfig->eRxFIFOWatermark);
    }

    /* Set delay between Data width */
    QSPI_MasterSetWaitDelay(base, psConfig->u16DelayBetweenFrameInCLK);

    QSPI_EnableStopModeHoldOff(base, psConfig->bEnableStopModeHoldOff);

    /* Enable interrupts if requested */
    QSPI_EnableInterrupts(base, psConfig->u8Interrupts);

    if (psConfig->bEnableModule)
    {
        QSPI_Enable(base, true);
    }
}

/*!
 * brief Set the qspi_master_config_t structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for the QSPI_MasterInit.
 * Users may use the initialized structure unchanged in the QSPI_MasterInit or modify the structure
 * before calling the QSPI_MasterInit.
 * Example:
 * code
 *  qspi_master_config_t psConfig;
 *  QSPI_MasterGetDefaultConfig(&psConfig);
 * endcode
 * The default values are:
 * Example:
 * @code
 *  psConfig->baudRate               = 500000U;
 *  psConfig->dataWidth              = (uint16_t)kSPI_Data8Bits;
 *  psConfig->cpol                   = kQSPI_ClockPolarityActiveHigh;
 *  psConfig->cpha                   = kQSPI_ClockPhaseSecondEdge;
 *  psConfig->direction              = kQSPI_MsbFirst;
 *  psConfig->delayBetweenFrameInCLK = 1U;
 *  psConfig->wiredOrMode            = false;
 * @endcode
 *
 * param psConfig pointer to qspi_master_config_t structure.
 * param u32ClockFreqHz Peripheral clock frequency in Hz
 */
void QSPI_MasterGetDefaultConfig(qspi_master_config_t *psConfig, uint32_t u32ClockFreqHz)
{
    assert(NULL != psConfig);

    /* Initialize the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    /* Parameter provided by user */
    psConfig->u32ClockFrequencyHz = u32ClockFreqHz;

    /* Default configuration */
    psConfig->u32BaudRateBps            = 500000UL;
    psConfig->eDataWidth                = kQSPI_Data8Bits;
    psConfig->eClkPolarity              = kQSPI_ClockPolarityActiveRisingEdge;
    psConfig->eClkPhase                 = kQSPI_ClockPhaseSlaveSelectLowBetweenWords;
    psConfig->eShiftDirection           = kQSPI_MsbFirst;
    psConfig->u16DelayBetweenFrameInCLK = 1U;
    psConfig->bEnableWiredOrMode        = false;
    psConfig->bEnableModeFault          = false;
    psConfig->u8DmaEnableFlags          = 0U; /* Disable all DMA */
    psConfig->bEnableFIFO               = false;
    psConfig->bEnableStopModeHoldOff    = false;
    psConfig->u8Interrupts              = 0U;
    psConfig->bEnableModule             = false;
}

/*!
 * brief Initializes the QUEUEDSPI slave.
 *
 * param base QUEUEDSPI peripheral address.
 * param psConfig Pointer to the structure qspi_slave_config_t.
 */
void QSPI_SlaveInit(QSPI_Type *base, const qspi_slave_config_t *psConfig)
{
    assert(NULL != psConfig);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable queued_spi clock */
    CLOCK_EnableClock(s_eQspiClocks[QSPI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Disable module before configuring. */
    QSPI_Enable(base, false);

    /* Set module as slave. */
    QSPI_SetMasterSlaveMode(base, kQSPI_Slave);

    /* Set CPHA, CPOL and date shift order. */
    QSPI_SetClockPolarity(base, psConfig->eClkPolarity);
    QSPI_SetClockPhase(base, psConfig->eClkPhase);
    QSPI_SetDataShiftOrder(base, psConfig->eShiftDirection);

    /* TODO Mode Fault Detect */
    QSPI_EnableModeFault(base, psConfig->bEnableModeFault);

    /* Set Wired-OR mode*/
    QSPI_EnableWiredORMode(base, psConfig->bEnableWiredOrMode);

    /* Set Data Width */
    QSPI_SetTransactionDataSize(base, psConfig->eDataWidth);

    /* Enable DMA */
    QSPI_EnableDMA(base, psConfig->u8DmaEnableFlags);

    /* Slave Select Signal Config */
    QSPI_SetSlaveSelectDirection(base, kQSPI_SlaveSelectDirectionInput);
    QSPI_EnableSlaveSelectOverride(base, psConfig->bEnableSlaveSelOverride);

    /* Set data width */
    QSPI_SetTransactionDataSize(base, psConfig->eDataWidth);

    /* FIFO Configuration */
    QSPI_EnableFifo(base, psConfig->bEnableFIFO);
    if (psConfig->bEnableFIFO)
    {
        QSPI_SetFifoWatermarks(base, (uint16_t)psConfig->eTxFIFOWatermark, (uint16_t)psConfig->eRxFIFOWatermark);
    }

    QSPI_EnableStopModeHoldOff(base, psConfig->bEnableStopModeHoldOff);

    /* Enable interrupts if requested */
    QSPI_EnableInterrupts(base, psConfig->u8Interrupts);

    if (psConfig->bEnableModule)
    {
        QSPI_Enable(base, true);
    }
}

/*!
 * brief Set the qspi_slave_config_t structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for the QSPI_SlaveInit.
 * Users may use the initialized structure unchanged in the QSPI_SlaveInit or modify the structure
 * before calling the QSPI_SlaveInit.
 * Example:
 * code
 *  qspi_slave_config_t slaveConfig;
 *  QSPI_SlaveGetDefaultConfig(&slaveConfig);
 * endcode
 * The default values are:
 * Example:
 * code
 *  slaveConfig->dataWidth   = (uint16_t)kSPI_Data8Bits;
 *  slaveConfig->cpol        = kQSPI_ClockPolarityActiveHigh;
 *  slaveConfig->cpha        = kQSPI_ClockPhaseSecondEdge;
 *  slaveConfig->direction   = kQSPI_MsbFirst;
 *  slaveConfig->wiredOrMode = false;
 * endcode
 *
 * param slaveConfig Pointer to the qspi_slave_config_t structure.
 */
void QSPI_SlaveGetDefaultConfig(qspi_slave_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initialize the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    /* User provided parameter */

    /* Default parameter */
    psConfig->eDataWidth              = kQSPI_Data8Bits;
    psConfig->eClkPolarity            = kQSPI_ClockPolarityActiveRisingEdge;
    psConfig->eClkPhase               = kQSPI_ClockPhaseSlaveSelectLowBetweenWords;
    psConfig->eShiftDirection         = kQSPI_MsbFirst;
    psConfig->bEnableWiredOrMode      = false;
    psConfig->u8DmaEnableFlags        = 0U; /* Disable TX/RX Dma */
    psConfig->bEnableSlaveSelOverride = false;
    psConfig->bEnableFIFO             = false;
    psConfig->bEnableStopModeHoldOff  = false;
    psConfig->u8Interrupts            = 0U;
    psConfig->bEnableModule           = false;
}

/*!
 * brief De-initialize the QUEUEDSPI peripheral.
 * param base QUEUEDSPI peripheral address.
 */
void QSPI_Deinit(QSPI_Type *base)
{
    /* Disable all interrupts. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);

    /* Disable DMA requests. */
    QSPI_DisableDMA(base, (uint8_t)kQSPI_DmaTx | (uint8_t)kQSPI_DmaRx);

    QSPI_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable queued_spi clock */
    CLOCK_DisableClock(s_eQspiClocks[QSPI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Set the QUEUEDSPI baud rate in bits-per-second.
 *
 * This function takes in the desired baud rate, calculates the nearest possible baud rate,
 * and returns the calculated baud rate in bits-per-second.
 *
 * param base QUEUEDSPI peripheral address.
 * param u32BaudRateBsp The desired baud rate in bits-per-second.
 * param u32SrcClockHz Module source input clock in Hertz.
 * return The actual calculated baud rate.
 */
uint32_t QSPI_MasterSetBaudRate(QSPI_Type *base, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz)
{
    /* Baudrate configuration is only supported for master, if slave mode is detected, return 0. */
    if (!QSPI_IsMaster(base))
    {
        return 0U;
    }

    bool div3 = false;
    uint8_t div1;
    uint16_t temp;

    uint8_t tempDiv;
    uint8_t bestDiv    = 0U;
    uint32_t prescaler = 1U;
    uint32_t realBaudrate;
    uint32_t bestBaudrate = 0UL;
    uint32_t diff, min_diff;

    min_diff = 0xFFFFFFFFUL;
    /* Enter for loops, if min_diff == 0, then exit for loop. */
    for (tempDiv = 0U; tempDiv <= 13U; tempDiv++)
    {
        prescaler *= 2U;
        realBaudrate = u32SrcClockHz / prescaler;

        if (realBaudrate > u32BaudRateBps)
        {
            continue;
        }
        /* Calculate the baud rate difference. */
        diff = u32BaudRateBps - realBaudrate;
        if (diff < min_diff)
        {
            /* A better match is found. */
            min_diff     = diff;
            bestDiv      = tempDiv;
            bestBaudrate = realBaudrate;
        }
        if (0U == min_diff)
        {
            break;
        }
    }

    /* Calculate div1 and div3. The formula is bestDiv = div1 | (doubleDiv << 3U) */
    div1 = (bestDiv & 0x7FU);
    if (bestDiv >= 8U)
    {
        div3 = true;
    }

    /* Write the best div1, div3 and doubelDiv. */
    temp        = base->SPSCR & ~QSPI_SPSCR_SPR_MASK;
    base->SPSCR = temp | QSPI_SPSCR_SPR((uint16_t)div1);

    temp        = base->SPDSR & ~(QSPI_SPDSR_BD2X_MASK | QSPI_SPDSR_SPR3_MASK);
    base->SPDSR = temp | QSPI_SPDSR_SPR3((uint16_t)div3);

    /* Return the actual calculated baud rate. */
    return bestBaudrate;
}

/*Transactional APIs -- Master*/

/*!
 * @brief Initialize the QUEUEDSPI master psHandle.
 *
 * This function initializes the QUEUEDSPI psHandle, which can be used for other QUEUEDSPI transactional APIs. Usually,
 * for a specified QUEUEDSPI instance, call this API once to get the initialized psHandle.
 *
 * @note If only use the QSPI_MasterTransferBlocking, this API is not necessary be called.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psHandle QUEUEDSPI psHandle pointer to qspi_master_transfer_handle_t.
 * @param pfCallback QUEUEDSPI callback.
 * @param pUserData Callback function parameter.
 */
void QSPI_MasterTransferCreateHandle(QSPI_Type *base,
                                     qspi_master_transfer_handle_t *psHandle,
                                     qspi_master_transfer_callback_t pfCallback,
                                     void *pUserData)
{
    assert(NULL != psHandle);

    /* Zero the psHandle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    s_psQspiHandles[QSPI_GetInstance(base)] = (void *)psHandle;

    /* Set irq psHandler. */
    s_pfQspiMasterIsr = QSPI_MasterTransferHandleIRQ;

    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;
}

/*!
 * @brief Polling method of QUEUEDSPI master transfer.
 *
 * This function transfers data using a polling method for master. This is a blocking function,
 * which does not return until all transfers have been completed.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psXfer Pointer to the qspi_transfer_t structure.
 * @return status of status_t.
 */
status_t QSPI_MasterTransferBlocking(QSPI_Type *base, qspi_transfer_t *psXfer)
{
    assert(NULL != psXfer);

    uint16_t fifoSize        = 4U;
    uint16_t wordToSend      = 0;
    uint16_t u16WordReceived = 0;

    uint8_t *txData = (uint8_t *)(psXfer->pTxData);
    uint8_t *rxData = (uint8_t *)(psXfer->pRxData);

    uint16_t u16RemainingSendByteCount    = psXfer->u16DataSize;
    uint16_t u16RemainingReceiveByteCount = psXfer->u16DataSize;
    /* Calculate the data width. */
    uint8_t dataWidth = (uint8_t)((base->SPDSR & QSPI_SPDSR_DS_MASK) >> QSPI_SPDSR_DS_SHIFT);
    uint8_t dummyData = QSPI_GetDummyData(base);

    /* Parameter Check */
    if ((psXfer == NULL) || ((psXfer->pTxData == NULL) && (psXfer->pRxData == NULL)) || (psXfer->u16DataSize == 0U))
    {
        return (status_t)kStatus_InvalidArgument;
    }

    /* Disable all interrupts in blocking method. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);

    /* Read out any possible data in the RX FIFO. */
    QSPI_EmptyRxFifo(base);

    /* Enable TX and RX FIFO. */
    QSPI_EnableFifo(base, true);

    /* Enable QSPI Module */
    QSPI_Enable(base, true);

    /* Check transfer flags. */
    if ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterPCSContinous) != 0U)
    {
        /* Before changing the SPDSR register, disable the module. */
        QSPI_Enable(base, false);

        uint16_t temp = base->SPDSR & ~(QSPI_SPDSR_SSB_STRB_MASK | QSPI_SPDSR_SSB_AUTO_MASK);

        bool PCSmanual = false;
        /* If currently the PCS is active or the PCS should stay active after current transfer, then the PCS signal must
         * be manually changed. */
        if (((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) ||
            ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterActiveAfterTransfer) != 0U))
        {
            PCSmanual = true;
        }

        temp |= (QSPI_SPDSR_SSB_STRB(0U) | QSPI_SPDSR_SSB_AUTO(!PCSmanual));

        base->SPDSR = temp;

        /* Re-enable the module to have the new value take effect. */
        QSPI_Enable(base, true);
    }

    /* If SSB_AUTO are not set, it means the PCS signal is in manual state. */
    /* Assert the PSC signal if PCS signal is current not in active state. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) != 0U))
    {
        QSPI_TogglePCS(base);
    }

    /* Calculate dummy data to send. */
    if (txData == NULL)
    {
        wordToSend = (uint16_t)dummyData | ((uint16_t)dummyData << 8U);
    }

    if (dataWidth <= (uint8_t)kQSPI_Data8Bits)
    {
        while ((u16RemainingSendByteCount > 0U) || (u16RemainingReceiveByteCount > 0U))
        {
            /* Push data to transmit data register if it is not full and make sure the difference
             * in remaining TX and RX byte counts does not exceed FIFO depth. */
            while ((fifoSize != QSPI_GetTxFIFOCount(base)) && (u16RemainingSendByteCount != 0U) &&
                   ((u16RemainingReceiveByteCount - u16RemainingSendByteCount) < (uint32_t)fifoSize))
            {
                if (txData != NULL)
                {
                    base->SPDTR = (uint16_t)(*txData);
                    txData++;
                }
                else
                {
                    base->SPDTR = wordToSend;
                }
                u16RemainingSendByteCount--;
            }

            /* Read data out of receive data register if it is not empty. */
            while ((0U != QSPI_GetRxFIFOCount(base)) && (u16RemainingReceiveByteCount != 0U))
            {
                if (rxData != NULL)
                {
                    *rxData = (uint8_t)QSPI_ReadData(base);
                    rxData++;
                }
                else
                {
                    (void)QSPI_ReadData(base);
                }
                u16RemainingReceiveByteCount--;
            }
        }
    }
    else
    {
        while ((u16RemainingSendByteCount > 0U) || (u16RemainingReceiveByteCount > 0U))
        {
            /* Push data to transmit data register if it is not full and make sure the difference
             * in remaining TX and RX byte counts does not exceed FIFO depth. */
            while ((fifoSize != QSPI_GetTxFIFOCount(base)) && (u16RemainingSendByteCount != 0U) &&
                   (((u16RemainingReceiveByteCount - u16RemainingSendByteCount) / 2U) < fifoSize))
            {
                if (u16RemainingSendByteCount > 1U)
                {
                    if (txData != NULL)
                    {
                        wordToSend = (uint16_t)(*txData);
                        ++txData;
                        wordToSend |= ((uint16_t)(*txData)) << 8U;
                        ++txData;
                    }
                    u16RemainingSendByteCount -= 2U;
                }
                else
                {
                    if (txData != NULL)
                    {
                        wordToSend = (uint16_t)(*txData);
                        ++txData;
                    }
                    u16RemainingSendByteCount--;
                }
                QSPI_WriteData(base, wordToSend);
            }

            /* Read data out of receive data register if it is not empty. */
            while ((0U != QSPI_GetRxFIFOCount(base)) && (u16RemainingReceiveByteCount != 0U))
            {
                u16WordReceived = QSPI_ReadData(base);

                if (u16RemainingReceiveByteCount > 1U)
                {
                    if (rxData != NULL)
                    {
                        *rxData = (uint8_t)u16WordReceived;
                        ++rxData;
                        *rxData = (uint8_t)(u16WordReceived >> 8U);
                        ++rxData;
                    }
                    u16RemainingReceiveByteCount -= 2U;
                }
                else
                {
                    if (rxData != NULL)
                    {
                        *rxData = (uint8_t)u16WordReceived;
                        ++rxData;
                    }
                    u16RemainingReceiveByteCount--;
                }
            }
        }
    }

    /* Wait until all data are transfered out to bus. */
    while (0U != QSPI_GetTxFIFOCount(base))
    {
    }

    /* If SSB_AUTO are not set, it means the PCS signal is in manual state. */
    /* De-assert PSC signal if kQSPI_MasterActiveAfterTransfer is not set. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U) &&
        ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterActiveAfterTransfer) == 0U))
    {
        QSPI_TogglePCS(base);
    }

    return kStatus_Success;
}

/*!
 * brief Interrupt method of QUEUEDSPI master transfer.
 *
 * This function transfers data using interrupts for master. This is a non-blocking function,
 * which returns right away. When all data is transferred, the callback function is called.
 *
 * param base QUEUEDSPI peripheral base address.
 * param psHandle Pointer to the qspi_master_transfer_handle_t structure which stores the transfer state.
 * param psXfer Pointer to the qspi_transfer_t structure.
 * return status of status_t.
 */
status_t QSPI_MasterTransferNonBlocking(qspi_master_transfer_handle_t *psHandle, qspi_transfer_t *psXfer)
{
    assert(NULL != psHandle);
    assert(NULL != psXfer);
    assert((psXfer->pRxData != NULL) || (psXfer->pTxData != NULL));

    QSPI_Type *base = psHandle->base;

    /* If the transfer count is zero, then return immediately.*/
    if (psXfer->u16DataSize == 0U)
    {
        return kStatus_InvalidArgument;
    }

    /* Check that we're not busy. */
    if (psHandle->u8State == (uint8_t)kQSPI_Busy)
    {
        return kStatus_QSPI_Busy;
    }

    /* Set transfer state to busy. */
    psHandle->u8State = (uint8_t)kQSPI_Busy;

    /* Disable all interrupts. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);
    /* Read out any possible data in the RX FIFO. */
    QSPI_EmptyRxFifo(base);
    /* Enable TX and RX FIFO. */
    QSPI_EnableFifo(base, true);

    /* Prepare transfer. */
    uint16_t data_width  = (base->SPDSR & QSPI_SPDSR_DS_MASK) >> QSPI_SPDSR_DS_SHIFT;
    psHandle->eDataWidth = (qspi_data_width_t)data_width;

    psHandle->bIsPcsActiveAfterTransfer = ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterActiveAfterTransfer) != 0U);

    psHandle->pu8TxData                    = (uint8_t *)(psXfer->pTxData);
    psHandle->pu8RxData                    = (uint8_t *)(psXfer->pRxData);
    psHandle->u16RemainingSendByteCount    = psXfer->u16DataSize;
    psHandle->u16RemainingReceiveByteCount = psXfer->u16DataSize;
    psHandle->u16TotalByteCount            = psXfer->u16DataSize;

    /* Set proper warter marks. */
    QSPI_SetFifoWatermarks(base, (uint16_t)kQSPI_TxFifoWatermarkThreeWord, (uint16_t)kQSPI_RxFifoWatermarkOneWord);

    /* Check transfer flags. */
    if ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterPCSContinous) != 0U)
    {
        /* Before changing the SPDSR register, disable the module. */
        QSPI_Enable(base, false);

        uint16_t temp = base->SPDSR & ~(QSPI_SPDSR_SSB_STRB_MASK | QSPI_SPDSR_SSB_AUTO_MASK);

        bool PCSmanual = false;
        /* If currently the PCS is active or the PCS should stay active after current transfer, then the PCS signal must
         * be manully changed. */
        if (((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) ||
            ((psXfer->u8ConfigFlags & (uint8_t)kQSPI_MasterActiveAfterTransfer) != 0U))
        {
            PCSmanual = true;
        }

        temp |= (QSPI_SPDSR_SSB_STRB(0U) | QSPI_SPDSR_SSB_AUTO((uint16_t)!PCSmanual));

        base->SPDSR = temp;

        /* Re-enable the module to have the new value take effect. */
        QSPI_Enable(base, true);
    }

    /* If SSB_AUTO are not set, it means the PCS signal is in manual state. */
    /* Assert the PSC signal if PCS signal is current not in active state. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) != 0U))
    {
        QSPI_TogglePCS(base);
    }

    /* Since SPI is a synchronous interface, we only need to enable the RX interrupt if there is RX data. */
    if (psHandle->pu8RxData != NULL)
    {
        QSPI_EnableInterrupts(base, (uint8_t)kQSPI_RxInterruptEnable);
        (void)EnableIRQ(s_eQspiRXIRQs[QSPI_GetInstance(base)]);
    }
    else
    {
        QSPI_EnableInterrupts(base, (uint8_t)kQSPI_TxInterruptEnable);
        (void)EnableIRQ(s_eQspiTXIRQs[QSPI_GetInstance(base)]);
    }

    QSPI_Enable(base, true);

    /* Fill up the TX FIFO to trigger the transfer. */
    QSPI_TransferFillUpTxFifo(base, psHandle);

    return kStatus_Success;
}

/*!
 * brief Get the master transfer count.
 *
 * param base QUEUEDSPI peripheral base address.
 * param psHandle Pointer to the qspi_master_transfer_handle_t structure which stores the transfer state.
 * param pu16Count The number of bytes transferred by using the non-blocking transaction.
 * return status of status_t.
 */
status_t QSPI_MasterTransferGetCount(qspi_master_transfer_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(NULL != psHandle);

    if (NULL == pu16Count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (psHandle->u8State != (uint8_t)kQSPI_Busy)
    {
        *pu16Count = 0;
        return kStatus_NoTransferInProgress;
    }

    if (psHandle->pu8RxData != NULL)
    {
        *pu16Count = psHandle->u16TotalByteCount - psHandle->u16RemainingReceiveByteCount;
    }
    else
    {
        *pu16Count = psHandle->u16TotalByteCount - psHandle->u16RemainingSendByteCount;
    }

    return kStatus_Success;
}

/*!
 * brief Abort a transfer that uses interrupts for master.
 *
 * param base QUEUEDSPI peripheral base address.
 * param psHandle Pointer to the qspi_master_transfer_handle_t structure which stores the transfer state.
 */
void QSPI_MasterTransferAbort(qspi_master_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    QSPI_Type *base = psHandle->base;

    /* Disable interrupt requests. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);

    /* De-assert the PSC signal if PCS signal is current in active state and the PCS signal is in manual mode. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U))
    {
        QSPI_TogglePCS(base);
    }

    psHandle->u8State                      = (uint8_t)kQSPI_Idle;
    psHandle->u16RemainingSendByteCount    = 0U;
    psHandle->u16RemainingReceiveByteCount = 0U;
}

/*!
 * brief QUEUEDSPI Master IRQ psHandler function.
 *
 * This function processes the QUEUEDSPI transmit and receive IRQ.
 *
 * param base QUEUEDSPI peripheral base address.
 * param psHandle Pointer to the qspi_master_transfer_handle_t structure which stores the transfer state.
 */
void QSPI_MasterTransferHandleIRQ(qspi_master_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    QSPI_Type *base = psHandle->base;

    /* Check receive register if there are remaining bytes to read. */
    if (0U != (psHandle->u16RemainingReceiveByteCount))
    {
        QSPI_TransferReadoutRxFifo(base, psHandle);
    }

    /* Write transmit register. We always have to send a word in order to keep the transfer
     * moving. If the caller didn't provide a send buffer, just send dummydata.
     */
    if (0U != (psHandle->u16RemainingSendByteCount))
    {
        QSPI_TransferFillUpTxFifo(base, psHandle);
    }

    /* Check if we're done with this transfer. */
    size_t tempRemainingSendByteCount    = (size_t)(psHandle->u16RemainingSendByteCount);
    size_t tempRemainingReceiveByteCount = (size_t)(psHandle->u16RemainingReceiveByteCount);
    if ((tempRemainingSendByteCount == 0U) && (tempRemainingReceiveByteCount == 0U))
    {
        /* Complete the transfer and disable the interrupts. */
        QSPI_MasterTransferComplete(base, psHandle);
    }
}

static void QSPI_TransferReadoutRxFifo(QSPI_Type *base, qspi_master_transfer_handle_t *psHandle)
{
    uint16_t u16WordReceived;

    /* If bits-per-frame is greater than one byte. */
    if (psHandle->eDataWidth > kQSPI_Data8Bits)
    {
        while ((0U != QSPI_GetRxFIFOCount(base)) && (psHandle->u16RemainingReceiveByteCount != 0U))
        {
            u16WordReceived = QSPI_ReadData(base);
            if (psHandle->u16RemainingReceiveByteCount == 1U)
            {
                /* Store read bytes into rx buffer only if a buffer pointer is provided. */

                /* For the last word received, if there is an extra byte due to the odd transfer
                 * byte count, only save the last byte and discard the upper byte. */
                if (NULL != psHandle->pu8RxData)
                {
                    *(psHandle->pu8RxData) = (uint8_t)u16WordReceived;
                }
                --psHandle->u16RemainingReceiveByteCount;
            }
            else
            {
                /* Store read bytes into rx buffer only if a buffer pointer is provided. */
                if (NULL != psHandle->pu8RxData)
                {
                    *(psHandle->pu8RxData) = (uint8_t)u16WordReceived;
                    ++psHandle->pu8RxData;
                    *(psHandle->pu8RxData) = (uint8_t)(u16WordReceived >> 8U);
                    ++psHandle->pu8RxData;
                }
                psHandle->u16RemainingReceiveByteCount -= 2U;
            }
        } /* End of RX FIFO drain while loop. */
    }
    else
    {
        while ((0U != QSPI_GetRxFIFOCount(base)) && (psHandle->u16RemainingReceiveByteCount != 0U))
        {
            u16WordReceived = QSPI_ReadData(base);

            /* Store read bytes into rx buffer only if a buffer pointer is provided. */
            if (NULL != psHandle->pu8RxData)
            {
                *(psHandle->pu8RxData) = (uint8_t)u16WordReceived;
                ++psHandle->pu8RxData;
            }
            --psHandle->u16RemainingReceiveByteCount;
        } /* End of RX FIFO drain while loop. */
    }
}

static void QSPI_TransferFillUpTxFifo(QSPI_Type *base, qspi_master_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    uint16_t wordToSend                 = 0U;
    uint8_t dummyData                   = QSPI_GetDummyData(base);
    size_t tmpRemainingSendByteCount    = (size_t)(psHandle->u16RemainingSendByteCount);
    size_t tmpRemainingReceiveByteCount = (size_t)(psHandle->u16RemainingReceiveByteCount);
    size_t fifoSize                     = 4U;

    if (NULL == psHandle->pu8TxData)
    {
        wordToSend = (uint16_t)dummyData | (((uint16_t)dummyData) << 8U);
    }
    /* If dataWidth is greater than one byte. */
    if (psHandle->eDataWidth > kQSPI_Data8Bits)
    {
        /* Make sure the difference in remaining TX and RX byte counts does not exceed FIFO depth,
         * unless there is no rxData.
         */
        while (((((tmpRemainingReceiveByteCount - tmpRemainingSendByteCount) / 2U) < fifoSize) ||
                (psHandle->pu8RxData == NULL)) &&
               (tmpRemainingSendByteCount != 0U))
        {
            if (psHandle->u16RemainingSendByteCount == 1U)
            {
                if (NULL != psHandle->pu8TxData)
                {
                    wordToSend = (uint16_t) * (psHandle->pu8TxData);
                }
                psHandle->u16RemainingSendByteCount = 0;
            }
            else
            {
                if (NULL != psHandle->pu8TxData)
                {
                    wordToSend = (uint16_t) * (psHandle->pu8TxData);
                    ++psHandle->pu8TxData;
                    wordToSend |= ((uint16_t)(*(psHandle->pu8TxData))) << 8U;
                    ++psHandle->pu8TxData;
                }
                psHandle->u16RemainingSendByteCount -= 2U;
            }
            QSPI_WriteData(base, wordToSend);

            /* Update the temp data. */
            tmpRemainingSendByteCount    = psHandle->u16RemainingSendByteCount;
            tmpRemainingReceiveByteCount = psHandle->u16RemainingReceiveByteCount;
        } /* End of TX FIFO fill while loop. */
    }
    else
    {
        /* Make sure the difference in remaining TX and RX byte counts does not exceed FIFO depth,
         * unless there is no rxData. */
        while ((((tmpRemainingReceiveByteCount - tmpRemainingSendByteCount) < fifoSize) ||
                (psHandle->pu8RxData == NULL)) &&
               (tmpRemainingSendByteCount != 0U))
        {
            if (NULL != psHandle->pu8TxData)
            {
                wordToSend = (uint16_t) * (psHandle->pu8TxData);
                ++psHandle->pu8TxData;
            }
            --psHandle->u16RemainingSendByteCount;

            QSPI_WriteData(base, wordToSend);
            /* Update the temp data. */
            tmpRemainingReceiveByteCount = psHandle->u16RemainingReceiveByteCount;
            tmpRemainingSendByteCount    = psHandle->u16RemainingSendByteCount;
        }
    }
}

static void QSPI_MasterTransferComplete(QSPI_Type *base, qspi_master_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    psHandle->u8State   = (uint8_t)kQSPI_Idle;
    psHandle->pu8TxData = NULL;
    psHandle->pu8RxData = NULL;

    /* Disable interrupt requests. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);

    /* If SSB_AUTO are not set, it means the PCS signal is in manual state. */
    /* De-assert the PSC signal if PCS signal is current in active state and the PCS should not stay active after
     * transfer. */
    if (((base->SPDSR & QSPI_SPDSR_SSB_AUTO_MASK) == 0U) && ((base->SPDSR & QSPI_SPDSR_SSB_DATA_MASK) == 0U) &&
        (!psHandle->bIsPcsActiveAfterTransfer))
    {
        QSPI_TogglePCS(base);
    }

    if (NULL != psHandle->pfCallback)
    {
        psHandle->pfCallback(psHandle, kStatus_Success, psHandle->pUserData);
    }
}

/*Transactional APIs -- Slave*/

/*!
 * @brief Initialize the QUEUEDSPI slave handle.
 *
 * This function initializes the QUEUEDSPI handle, which can be used for other QUEUEDSPI transactional APIs. Usually,
 * for a specified QUEUEDSPI instance, call this API once to get the initialized handle.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psHandle QUEUEDSPI handle pointer to the qspi_slave_transfer_handle_t.
 * @param pfCallback QUEUEDSPI callback.
 * @param pUserData Callback function parameter.
 */
void QSPI_SlaveTransferCreateHandle(QSPI_Type *base,
                                    qspi_slave_transfer_handle_t *psHandle,
                                    qspi_slave_transfer_callback_t pfCallback,
                                    void *pUserData)
{
    assert(NULL != psHandle);

    /* Zero the psHandle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    s_psQspiHandles[QSPI_GetInstance(base)] = (void *)psHandle;

    /* Set IRQ psHandler. */
    s_pfQspiSlaveIsr = QSPI_SlaveTransferHandleIRQ;

    psHandle->base       = base;
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;
}

/*!
 * brief Interrupt method of QUEUEDSPI slave transfer.
 *
 * This function transfers data using interrupts for slave. This is a non-blocking function,
 * which returns right away. When all data is transferred, the callback function is called.
 *
 * param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 * param psXfer Pointer to the qspi_transfer_t structure.
 * return status of status_t.
 */
status_t QSPI_SlaveTransferNonBlocking(qspi_slave_transfer_handle_t *psHandle, qspi_transfer_t *psXfer)
{
    assert(NULL != psHandle);
    assert(NULL != psXfer);
    assert((psXfer->pRxData != NULL) || (psXfer->pTxData != NULL));

    QSPI_Type *base = psHandle->base;

    /* If the transfer count is zero, then return immediately. */
    if (psXfer->u16DataSize == 0U)
    {
        return kStatus_InvalidArgument;
    }

    /* Check that we're not busy. */
    if (psHandle->u8State == (uint8_t)kQSPI_Busy)
    {
        return kStatus_QSPI_Busy;
    }

    /* Set transfer state to busy. */
    psHandle->u8State = (uint8_t)kQSPI_Busy;

    /* Disable all interrupts. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);
    /* Read out any possible data in the RX FIFO */
    QSPI_EmptyRxFifo(base);
    /* Enable TX and RX FIFO. */
    QSPI_EnableFifo(base, true);

    /* Prepare transfer. */
    uint16_t data_width  = (base->SPDSR & QSPI_SPDSR_DS_MASK) >> QSPI_SPDSR_DS_SHIFT;
    psHandle->eDataWidth = (qspi_data_width_t)data_width;

    psHandle->pu8TxData                    = (uint8_t *)(psXfer->pTxData);
    psHandle->pu8RxData                    = (uint8_t *)(psXfer->pRxData);
    psHandle->u16RemainingSendByteCount    = psXfer->u16DataSize;
    psHandle->u16RemainingReceiveByteCount = psXfer->u16DataSize;
    psHandle->u16TotalByteCount            = psXfer->u16DataSize;

    /* Set proper warter marks. */
    QSPI_SetFifoWatermarks(base, (uint16_t)kQSPI_TxFifoWatermarkThreeWord, (uint16_t)kQSPI_RxFifoWatermarkOneWord);

    /* Enable the IRQ for QUEUEDSPI peripheral. */
    QSPI_EnableInterrupts(base, (uint8_t)kQSPI_RxInterruptEnable);
    (void)EnableIRQ(s_eQspiRXIRQs[QSPI_GetInstance(base)]);
    if (psHandle->pu8RxData != NULL)
    {
        QSPI_EnableInterrupts(base, (uint8_t)kQSPI_RxOverFlowInterruptEnable);
    }
    if (psHandle->pu8TxData != NULL)
    {
        QSPI_EnableInterrupts(base, (uint8_t)kQSPI_TxInterruptEnable);
        (void)EnableIRQ(s_eQspiTXIRQs[QSPI_GetInstance(base)]);
    }

    /* Ensure the QSPI is enabled before Fill up FIFO */
    QSPI_Enable(base, true);

    /* Fill up the TX FIFO to trigger the transfer. */
    QSPI_TransferFillUpTxFifo(base, psHandle);

    return kStatus_Success;
}

/*!
 * @brief Get the slave transfer count already transmitted/received.
 *
 * @param base QUEUEDSPI peripheral base address.
 * @param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 * @param pu16Count The number of bytes transferred by using the non-blocking transaction.
 * @return status of status_t.
 */
status_t QSPI_SlaveTransferGetCount(qspi_slave_transfer_handle_t *psHandle, uint16_t *pu16Count)
{
    assert(NULL != psHandle);

    if (NULL == pu16Count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (psHandle->u8State != (uint8_t)kQSPI_Busy)
    {
        *pu16Count = 0;
        return kStatus_NoTransferInProgress;
    }

    if (psHandle->pu8RxData != NULL)
    {
        *pu16Count = psHandle->u16TotalByteCount - psHandle->u16RemainingReceiveByteCount;
    }
    else
    {
        *pu16Count = psHandle->u16TotalByteCount - psHandle->u16RemainingSendByteCount;
    }

    return kStatus_Success;
}

static void QSPI_SlaveTransferComplete(QSPI_Type *base, qspi_slave_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    status_t eStatus = kStatus_Success;

    /* Disable interrupt requests. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);

    /* The transfer is complete. */
    psHandle->pu8TxData                    = NULL;
    psHandle->pu8RxData                    = NULL;
    psHandle->u16RemainingReceiveByteCount = 0U;
    psHandle->u16RemainingSendByteCount    = 0U;

    if (psHandle->u8State == (uint8_t)kQSPI_Error)
    {
        eStatus = kStatus_QSPI_Error;
    }
    else
    {
        eStatus = kStatus_Success;
    }

    psHandle->u8State = (uint8_t)kQSPI_Idle;

    if (NULL != psHandle->pfCallback)
    {
        psHandle->pfCallback(psHandle, eStatus, psHandle->pUserData);
    }
}

/*!
 * brief Abort a transfer that uses interrupts for slave.
 *
 * param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 */
void QSPI_SlaveTransferAbort(qspi_slave_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    QSPI_Type *base = psHandle->base;

    /* Disable interrupt requests. */
    QSPI_DisableInterrupts(base, (uint8_t)kQSPI_AllInterrupts);

    psHandle->u8State                      = (uint8_t)kQSPI_Idle;
    psHandle->u16RemainingSendByteCount    = 0U;
    psHandle->u16RemainingReceiveByteCount = 0U;
}

/*!
 * brief QUEUEDSPI slave IRQ psHandler function.
 *
 * This function processes the QUEUEDSPI transmit and receive IRQ.
 *
 * param base QUEUEDSPI peripheral base address.
 * param psHandle Pointer to the qspi_slave_transfer_handle_t structure which stores the transfer state.
 */
void QSPI_SlaveTransferHandleIRQ(qspi_slave_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    QSPI_Type *base = psHandle->base;

    /* Check receive register if there are remaining bytes to be read. */
    if (0U != (psHandle->u16RemainingReceiveByteCount))
    {
        QSPI_TransferReadoutRxFifo(base, psHandle);
    }

    /* Write transmit register. If the caller doesn't provide a send buffer, just send dummydata. */
    if (0U != (psHandle->u16RemainingSendByteCount))
    {
        QSPI_TransferFillUpTxFifo(base, psHandle);
    }

    /* Check if transfer complete or error occured. */
    size_t tempRemainingSendByteCount    = (size_t)(psHandle->u16RemainingSendByteCount);
    size_t tempRemainingReceiveByteCount = (size_t)(psHandle->u16RemainingReceiveByteCount);
    if ((psHandle->u8State == (uint8_t)kQSPI_Error) ||
        ((tempRemainingSendByteCount == 0U) && (tempRemainingReceiveByteCount == 0U)))
    {
        QSPI_SlaveTransferComplete(base, psHandle);
        return;
    }

    /* Catch RX fifo overflow error, only if RX overflow interrupt is enabled. */
    if (0U != (QSPI_GetStatusFlags(base) & (uint16_t)kQSPI_RxOverflowFlag))
    {
        /* Change state to error if receive data is not NULL. */
        if (NULL != psHandle->pu8RxData)
        {
            psHandle->u8State = (uint8_t)kQSPI_Error;
        }
    }
}

static void QSPI_CommonIRQHandler(QSPI_Type *base, void *param)
{
    if (QSPI_IsMaster(base))
    {
        s_pfQspiMasterIsr((qspi_master_transfer_handle_t *)param);
    }
    else
    {
        s_pfQspiSlaveIsr((qspi_slave_transfer_handle_t *)param);
    }
/* Added for ARM errata 838869, affects Cortex-M4, Cortex-M4F. */
    SDK_ISR_EXIT_BARRIER;
}

#if defined(QSPI0)
void QSPI0_XMIT_DriverIRQHandler(void);
void QSPI0_RCV_DriverIRQHandler(void);
void QSPI0_XMIT_DriverIRQHandler(void)
{
    assert(s_psQspiHandles[0]);
    QSPI_CommonIRQHandler(QSPI0, s_psQspiHandles[0]);
}
void QSPI0_RCV_DriverIRQHandler(void)
{
    assert(s_psQspiHandles[0]);
    QSPI_CommonIRQHandler(QSPI0, s_psQspiHandles[0]);
}
#endif

#if defined(QSPI1)
void QSPI1_XMIT_DriverIRQHandler(void);
void QSPI1_RCV_DriverIRQHandler(void);
void QSPI1_XMIT_DriverIRQHandler(void)
{
    assert(s_psQspiHandles[1]);
    QSPI_CommonIRQHandler(QSPI1, s_psQspiHandles[1]);
}
void QSPI1_RCV_DriverIRQHandler(void)
{
    assert(s_psQspiHandles[1]);
    QSPI_CommonIRQHandler(QSPI1, s_psQspiHandles[1]);
}
#endif
