/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spdif.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.spdif_xcvr"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief spdif transfer state. */
enum _spdif_transfer_state
{
    kSPDIF_Busy = 0x0U, /*!< SPDIF is busy */
    kSPDIF_Idle,        /*!< Transfer is done. */
    kSPDIF_Error        /*!< Transfer error occurred. */
};

/*! @brief Typedef for spdif interrupt handler. */
typedef void (*spdif_isr_t)(SPDIF_Type *base, spdif_handle_t *handle);

/*! @brief FIFO addresses */
#define SPDIF_TX_FIFO_ADDR_OFFSET (0xE00U)
#define SPDIF_RX_FIFO_ADDR_OFFSET (0xC00U)

/*! @brief Maximum timeout for reset operations */
#define SPDIF_RESET_TIMEOUT_US (1000U)

/*! @brief Minimum clock frequency for calculations */
#define SPDIF_MIN_CLOCK_FREQ (1000000U) /* 1MHz */

/*! @brief Maximum safe multiplication factor to prevent overflow */
#define SPDIF_MAX_MULT_FACTOR (0x1000000U) /* 16M */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get the SPDIF instance from peripheral base address.
 *
 * @param base SPDIF peripheral base address.
 * @return SPDIF instance.
 */
static uint32_t SPDIF_GetInstance(SPDIF_Type *base);

/*!
 * @brief Validate configuration parameters.
 *
 * @param config SPDIF configuration structure.
 * @return true if valid, false otherwise.
 */
static bool SPDIF_ValidateConfig(const spdif_config_t *config);

/*!
 * @brief Wait for reset completion with timeout.
 *
 * @param base SPDIF base pointer.
 * @param resetMask Reset mask to check.
 * @return kStatus_Success if reset completed, kStatus_Timeout otherwise.
 */
static status_t SPDIF_WaitForReset(SPDIF_Type *base, uint32_t resetMask);

/*!
 * @brief Safely calculate clock divider to prevent overflow.
 *
 * @param sourceFreq Source clock frequency.
 * @param targetFreq Target frequency.
 * @param divider Pointer to store calculated divider.
 * @return kStatus_Success if calculation successful, error otherwise.
 */
static status_t SPDIF_CalculateClockDivider(uint32_t sourceFreq, uint32_t targetFreq, uint32_t *divider);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Base pointer array */
static SPDIF_Type *const s_spdifXcvrBases[] = SPDIF_BASE_PTRS;

/*! @brief SPDIF handle pointer */
static spdif_handle_t *s_spdifXcvrHandle[ARRAY_SIZE(s_spdifXcvrBases)][2];

/* IRQ number array */
static const IRQn_Type s_spdifXcvrIRQ[] = {AUDIO_SPDIF_IRQn};

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Clock name array */
static const clock_ip_name_t s_spdifXcvrClock[] = SPDIF_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Pointer to IRQ handler for each instance. */
static spdif_isr_t s_spdifXcvrTxIsr;
/*! @brief Pointer to IRQ handler for each instance. */
static spdif_isr_t s_spdifXcvrRxIsr;

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t SPDIF_GetInstance(SPDIF_Type *base)
{
    uint32_t instance;

    assert(base != NULL);

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_spdifXcvrBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_spdifXcvrBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_spdifXcvrBases));

    return instance;
}

static bool SPDIF_ValidateConfig(const spdif_config_t *config)
{
    bool isValid = true;

    if (config == NULL)
    {
        isValid = false;
    }
    else
    {
        /* Validate FIFO watermarks */
        if ((config->rxFifoWatermark > SPDIF_MAX_FIFO_WATERMARK) ||
            (config->txFifoWatermark > SPDIF_MAX_FIFO_WATERMARK))
        {
            isValid = false;
        }

        /* Validate clock divider */
        if (config->clockDivider > SPDIF_MAX_CLOCK_DIVIDER)
        {
            isValid = false;
        }

        /* Validate enum values */
        if ((config->rxDataFormat > kSPDIF_DataFormat_16Bit) || (config->txFormat > kSPDIF_TxFormat_16Bit) ||
            (config->rxFsmMode > kSPDIF_FSM_Reserved) || (config->wakeupToggleCount > kSPDIF_WakeupToggle_8))
        {
            isValid = false;
        }
    }

    return isValid;
}

static status_t SPDIF_WaitForReset(SPDIF_Type *base, uint32_t resetMask)
{
    uint32_t timeout = SPDIF_RESET_TIMEOUT_US;
    status_t status  = kStatus_Success;

    assert(base != NULL);

    /* Wait for reset to complete with timeout */
    while (((base->EXT_CTRL.RW & resetMask) != 0U) && (timeout > 0U))
    {
        timeout--;
        /* Add small delay - implementation dependent */
        SDK_DelayAtLeastUs(1U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    }

    if (timeout == 0U)
    {
        status = kStatus_Timeout;
    }

    return status;
}

static status_t SPDIF_CalculateClockDivider(uint32_t sourceFreq, uint32_t targetFreq, uint32_t *divider)
{
    status_t status = kStatus_Success;
    uint64_t tempDiv;
    uint64_t tempMod;

    assert(divider != NULL);

    /* Validate input parameters */
    if ((sourceFreq < SPDIF_MIN_CLOCK_FREQ) || (targetFreq == 0U) || (targetFreq > sourceFreq))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        /* Use 64-bit arithmetic to prevent overflow */
        tempDiv = (uint64_t)sourceFreq / ((uint64_t)targetFreq * 64U);
        tempMod = (uint64_t)sourceFreq % ((uint64_t)targetFreq * 64U);

        /* Compute the nearest divider */
        if (tempMod > (((uint64_t)targetFreq * 64U) / 2U))
        {
            /* Check for overflow against our maximum allowed divider */
            if (tempDiv < (uint64_t)SPDIF_MAX_CLOCK_DIVIDER)
            {
                tempDiv += 1U;
            }
        }

        /* Ensure minimum divider value */
        if (tempDiv == 0U)
        {
            tempDiv = 1U;
        }

        /* Check for overflow */
        if (tempDiv > SPDIF_MAX_CLOCK_DIVIDER)
        {
            status = kStatus_InvalidArgument;
        }
        else
        {
            *divider = (uint32_t)tempDiv;
        }
    }

    return status;
}

/*!
 * brief Initializes the SPDIF peripheral.
 */
status_t SPDIF_Init(SPDIF_Type *base, const spdif_config_t *config)
{
    status_t status = kStatus_Success;

    assert(base != NULL);

    /* Validate configuration */
    if (!SPDIF_ValidateConfig(config))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
        /* Enable the SPDIF clock */
        CLOCK_EnableClock(s_spdifXcvrClock[SPDIF_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

        /* Reset the datapaths */
        base->EXT_CTRL.SET = SPDIF_EXT_CTRL_TX_DPATH_RESET_MASK | SPDIF_EXT_CTRL_RX_DPATH_RESET_MASK;

        /* Wait for reset to complete */
        status = SPDIF_WaitForReset(base, SPDIF_EXT_CTRL_TX_DPATH_RESET_MASK | SPDIF_EXT_CTRL_RX_DPATH_RESET_MASK);

        if (status == kStatus_Success)
        {
            /* Configure clock divider */
            base->CLK_CTRL = SPDIF_CLK_CTRL_CLKDIV(config->clockDivider);

            /* Configure FIFO watermarks */
            base->EXT_CTRL.RW = SPDIF_EXT_CTRL_TX_FIFO_WMARK(config->txFifoWatermark) |
                                SPDIF_EXT_CTRL_RX_FIFO_WMARK(config->rxFifoWatermark);

            /* Configure wakeup functionality */
            if (config->enableWakeup)
            {
                base->EXT_CTRL.SET        = SPDIF_EXT_CTRL_EN_SPDIF_WAKEUP_MASK;
                base->RX_DATAPATH_CTRL.RW = (base->RX_DATAPATH_CTRL.RW & ~SPDIF_RX_DATAPATH_CTRL_SPDIF_TGL_CNT_MASK) |
                                            SPDIF_RX_DATAPATH_CTRL_SPDIF_TGL_CNT((uint32_t)config->wakeupToggleCount);
            }

            /* Configure receiver if enabled */
            if (config->enableRx)
            {
                uint32_t rxCtrl = 0;

                rxCtrl |= SPDIF_RX_DATAPATH_CTRL_RX_DATA_FMT((uint32_t)config->rxDataFormat);
                rxCtrl |= SPDIF_RX_DATAPATH_CTRL_FSM((uint32_t)config->rxFsmMode);

                if (config->rxStoreFormatReverse)
                {
                    rxCtrl |= SPDIF_RX_DATAPATH_CTRL_STORE_FMT_MASK;
                }

                if (config->enableRxParityCheck)
                {
                    rxCtrl |= SPDIF_RX_DATAPATH_CTRL_EN_PARITY_CALC_MASK;
                }

                if (!config->rxMuteHwControl)
                {
                    rxCtrl |= SPDIF_RX_DATAPATH_CTRL_MUTE_MODE_MASK;
                }

                base->RX_DATAPATH_CTRL.RW = rxCtrl;

                /* Release RX datapath from reset */
                base->EXT_CTRL.CLR = SPDIF_EXT_CTRL_RX_DPATH_RESET_MASK;
            }

            /* Configure transmitter if enabled */
            if (config->enableTx)
            {
                uint32_t txCtrl = 0;

                txCtrl |= SPDIF_TX_DATAPATH_CTRL_TX_FORMAT((uint32_t)config->txFormat);

                if (config->txFrameFormatReverse)
                {
                    txCtrl |= SPDIF_TX_DATAPATH_CTRL_FRM_FMT_MASK;
                }

                if (config->enableTxPreamble)
                {
                    txCtrl |= SPDIF_TX_DATAPATH_CTRL_EN_PREAMBLE_MASK;
                }

                if (config->enableTxParity)
                {
                    txCtrl |= SPDIF_TX_DATAPATH_CTRL_EN_PARITY_MASK;
                }

                if (config->enableTxChannelStatus)
                {
                    txCtrl |= SPDIF_TX_DATAPATH_CTRL_CS_MOD_MASK;
                }

                if (config->enableTxUserData)
                {
                    txCtrl |= SPDIF_TX_DATAPATH_CTRL_UD_MOD_MASK;
                }

                if (config->enableTxValidBit)
                {
                    txCtrl |= SPDIF_TX_DATAPATH_CTRL_VLD_MOD_MASK;
                    if (config->txValidBitValue)
                    {
                        txCtrl |= SPDIF_TX_DATAPATH_CTRL_FRM_VLD_MASK;
                    }
                }

                base->TX_DATAPATH_CTRL.RW = txCtrl;

                /* Release TX datapath from reset */
                base->EXT_CTRL.CLR = SPDIF_EXT_CTRL_TX_DPATH_RESET_MASK;
            }

            /* Clear and disable all interrupts */
            base->EXT_ISR.CLR  = kSPDIF_AllInterrupt;
            base->EXT_IER0.CLR = kSPDIF_AllInterrupt;
            base->EXT_IER1.CLR = kSPDIF_AllInterrupt;
        }
    }

    return status;
}

/*!
 * brief De-initializes the SPDIF peripheral.
 */
void SPDIF_Deinit(SPDIF_Type *base)
{
    assert(base != NULL);

    SPDIF_TxEnable(base, false);
    SPDIF_RxEnable(base, false);

    /* Reset the datapaths */
    base->EXT_CTRL.SET = SPDIF_EXT_CTRL_TX_DPATH_RESET_MASK | SPDIF_EXT_CTRL_RX_DPATH_RESET_MASK;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_spdifXcvrClock[SPDIF_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief  Sets the SPDIF configuration structure to default values.
 */
void SPDIF_GetDefaultConfig(spdif_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* Receiver configuration */
    config->enableRx             = true;
    config->rxDataFormat         = kSPDIF_DataFormat_SubFrame;
    config->rxFsmMode            = kSPDIF_FSM_SyncToB;
    config->rxStoreFormatReverse = false;
    config->enableRxParityCheck  = true;
    config->rxMuteHwControl      = true;
    config->rxFifoWatermark      = 64U;

    /* Transmitter configuration */
    config->enableTx              = true;
    config->txFormat              = kSPDIF_TxFormat_SubFrame;
    config->txFrameFormatReverse  = false;
    config->enableTxPreamble      = true;
    config->enableTxParity        = true;
    config->enableTxChannelStatus = false;
    config->enableTxUserData      = false;
    config->enableTxValidBit      = false;
    config->txValidBitValue       = false;
    config->txFifoWatermark       = 64U;

    /* Clock configuration */
    config->clockDivider = 1U;

    /* Wakeup configuration */
    config->enableWakeup      = false;
    config->wakeupToggleCount = kSPDIF_WakeupToggle_4;
}

/*!
 * brief Enables/disables the SPDIF Tx.
 */
void SPDIF_TxEnable(SPDIF_Type *base, bool enable)
{
    assert(base != NULL);

    if (enable)
    {
        /* Start data transmission */
        base->TX_DATAPATH_CTRL.SET = SPDIF_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK;
    }
    else
    {
        /* Stop data transmission */
        base->TX_DATAPATH_CTRL.CLR = SPDIF_TX_DATAPATH_CTRL_STRT_DATA_TX_MASK;
    }
}

/*!
 * brief Enables/disables the SPDIF Rx.
 */
void SPDIF_RxEnable(SPDIF_Type *base, bool enable)
{
    assert(base != NULL);

    if (enable)
    {
        /* Clear RX FIFO */
        base->RX_DATAPATH_CTRL.SET = SPDIF_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK;
        base->RX_DATAPATH_CTRL.CLR = SPDIF_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK;
    }
    else
    {
        /* Clear RX FIFO */
        base->RX_DATAPATH_CTRL.SET = SPDIF_RX_DATAPATH_CTRL_CLR_RX_FIFO_MASK;
    }
}

/*!
 * brief Configures the SPDIF Tx sample rate.
 */
status_t SPDIF_TxSetSampleRate(SPDIF_Type *base, uint32_t sampleRate_Hz, uint32_t sourceClockFreq_Hz)
{
    status_t status;
    uint32_t clkDiv;

    assert(base != NULL);

    /* Validate sample rate range */
    if ((sampleRate_Hz < SPDIF_MIN_SAMPLE_RATE) || (sampleRate_Hz > SPDIF_MAX_SAMPLE_RATE))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        /* Calculate clock divider safely */
        status = SPDIF_CalculateClockDivider(sourceClockFreq_Hz, sampleRate_Hz, &clkDiv);

        if (status == kStatus_Success)
        {
            /* Set clock divider (subtract 1 as hardware expects N-1) */
            if (clkDiv > 0U)
            {
                base->CLK_CTRL = SPDIF_CLK_CTRL_CLKDIV(clkDiv - 1U);
            }
            else
            {
                status = kStatus_InvalidArgument;
            }
        }
    }

    return status;
}

/*!
 * brief Gets the SPDIF Rx sample rate.
 */
uint32_t SPDIF_GetRxSampleRate(SPDIF_Type *base, uint32_t clockSourceFreq_Hz)
{
    uint32_t sampleRate = 0U;
    uint32_t clkDiv;

    assert(base != NULL);

    if (clockSourceFreq_Hz >= SPDIF_MIN_CLOCK_FREQ)
    {
        clkDiv = (base->CLK_CTRL & SPDIF_CLK_CTRL_CLKDIV_MASK) >> SPDIF_CLK_CTRL_CLKDIV_SHIFT;

        /* Avoid division by zero */
        if (clkDiv < SPDIF_MAX_CLOCK_DIVIDER)
        {
            /* Check for potential overflow */
            if (clockSourceFreq_Hz <= (UINT32_MAX / 64U))
            {
                sampleRate = clockSourceFreq_Hz / ((clkDiv + 1U) * 64U);
            }
        }
    }

    return sampleRate;
}

/*!
 * brief Gets the SPDIF TX FIFO address for DMA transfer.
 */
uint32_t SPDIF_GetTxFifoAddress(SPDIF_Type *base)
{
    assert(base != NULL);
    return (uint32_t)base + SPDIF_TX_FIFO_ADDR_OFFSET;
}

/*!
 * brief Gets the SPDIF RX FIFO address for DMA transfer.
 */
uint32_t SPDIF_GetRxFifoAddress(SPDIF_Type *base)
{
    assert(base != NULL);
    return (uint32_t)base + SPDIF_RX_FIFO_ADDR_OFFSET;
}

/*!
 * brief Sends data using a blocking method.
 */
status_t SPDIF_WriteBlocking(SPDIF_Type *base, const uint8_t *buffer, uint32_t size)
{
    status_t status = kStatus_Success;
    const uint32_t *data;
    uint32_t words;
    volatile uint32_t *txFifo;
    uint32_t i;

    assert(base != NULL);

    if ((buffer == NULL) || (size == 0U) || ((size % 4U) != 0U))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        /* MISRA C-2012 Rule 11.3: Cast to uint32_t pointer for word access */
        data  = (const uint32_t *)(const void *)buffer;
        words = size / 4U;
        /* MISRA C-2012 Rule 11.4: Cast base address to access FIFO */
        txFifo = (volatile uint32_t *)((uintptr_t)base + SPDIF_TX_FIFO_ADDR_OFFSET);

        for (i = 0U; i < words; i++)
        {
            /* Wait until TX FIFO has space */
            while ((base->EXT_STATUS.RW & SPDIF_EXT_STATUS_NO_TX_FIFO_ENTRIES_MASK) >= (SPDIF_FIFO_SIZE - 1U))
            {
                /* Polling loop - could add timeout here */
            }

            /* Write data to TX FIFO */
            *txFifo = data[i];
        }
    }

    return status;
}

/*!
 * brief Receives data using a blocking method.
 */
status_t SPDIF_ReadBlocking(SPDIF_Type *base, uint8_t *buffer, uint32_t size)
{
    status_t status = kStatus_Success;
    uint32_t *data;
    uint32_t words;
    volatile uint32_t *rxFifo;
    uint32_t i;

    assert(base != NULL);

    if ((buffer == NULL) || (size == 0U) || ((size % 4U) != 0U))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        /* MISRA C-2012 Rule 11.3: Cast to uint32_t pointer for word access */
        data  = (uint32_t *)(void *)buffer;
        words = size / 4U;
        /* MISRA C-2012 Rule 11.4: Cast base address to access FIFO */
        rxFifo = (volatile uint32_t *)((uintptr_t)base + SPDIF_RX_FIFO_ADDR_OFFSET);

        for (i = 0U; i < words; i++)
        {
            /* Wait until RX FIFO has data */
            while ((base->EXT_STATUS.RW & SPDIF_EXT_STATUS_NO_RX_FIFO_ENTRIES_MASK) == 0U)
            {
                /* Polling loop - could add timeout here */
            }

            /* Read data from RX FIFO */
            data[i] = *rxFifo;
        }
    }

    return status;
}

/*!
 * brief Initializes the SPDIF Tx handle.
 */
void SPDIF_TransferTxCreateHandle(SPDIF_Type *base,
                                       spdif_handle_t *handle,
                                       spdif_transfer_callback_t callback,
                                       void *userData)
{
    uint32_t instance;

    assert(base != NULL);
    assert(handle != NULL);

    /* Zero the handle */
    (void)memset(handle, 0, sizeof(*handle));

    instance                       = SPDIF_GetInstance(base);
    s_spdifXcvrHandle[instance][0] = handle;

    handle->callback = callback;
    handle->userData = userData;
    handle->watermark =
        (uint8_t)((base->EXT_CTRL.RW & SPDIF_EXT_CTRL_TX_FIFO_WMARK_MASK) >> SPDIF_EXT_CTRL_TX_FIFO_WMARK_SHIFT);

    /* Set the isr pointer */
    s_spdifXcvrTxIsr = SPDIF_TransferTxHandleIRQ;

    /* Enable Tx irq */
    (void)EnableIRQ(s_spdifXcvrIRQ[instance]);
}

/*!
 * brief Initializes the SPDIF Rx handle.
 */
void SPDIF_TransferRxCreateHandle(SPDIF_Type *base,
                                       spdif_handle_t *handle,
                                       spdif_transfer_callback_t callback,
                                       void *userData)
{
    uint32_t instance;

    assert(base != NULL);
    assert(handle != NULL);

    /* Zero the handle */
    (void)memset(handle, 0, sizeof(*handle));

    instance                       = SPDIF_GetInstance(base);
    s_spdifXcvrHandle[instance][1] = handle;

    handle->callback = callback;
    handle->userData = userData;
    handle->watermark =
        (uint8_t)((base->EXT_CTRL.RW & SPDIF_EXT_CTRL_RX_FIFO_WMARK_MASK) >> SPDIF_EXT_CTRL_RX_FIFO_WMARK_SHIFT);

    /* Set the isr pointer */
    s_spdifXcvrRxIsr = SPDIF_TransferRxHandleIRQ;

    /* Enable Rx irq */
    (void)EnableIRQ(s_spdifXcvrIRQ[instance]);
}

/*!
 * brief Performs an interrupt non-blocking send transfer on SPDIF.
 */
status_t SPDIF_TransferSendNonBlocking(SPDIF_Type *base,
                                            spdif_handle_t *handle,
                                            const spdif_transfer_t *xfer)
{
    status_t status = kStatus_Success;

    assert(base != NULL);
    assert(handle != NULL);
    assert(xfer != NULL);

    /* Validate transfer parameters */
    if ((xfer->data == NULL) || (xfer->dataSize == 0U) || ((xfer->dataSize % 4U) != 0U))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        /* Check if the queue is full */
        if (handle->spdifQueue[handle->queueUser].data != NULL)
        {
            status = kStatus_SPDIF_QueueFull;
        }
        else
        {
            /* Add into queue */
            handle->transferSize[handle->queueUser]             = xfer->dataSize;
            handle->spdifQueue[handle->queueUser].data          = xfer->data;
            handle->spdifQueue[handle->queueUser].dataSize      = xfer->dataSize;
            handle->spdifQueue[handle->queueUser].channelStatus = xfer->channelStatus;
            handle->spdifQueue[handle->queueUser].userData      = xfer->userData;
            handle->queueUser = (uint8_t)((handle->queueUser + 1U) % SPDIF_XFER_QUEUE_SIZE);

            /* Set the state to busy */
            handle->state = kSPDIF_Busy;

            /* Enable interrupt */
            SPDIF_EnableInterrupts(base, kSPDIF_DmaWriteRequestInterrupt);

            /* Enable Tx transfer */
            SPDIF_TxEnable(base, true);
        }
    }

    return status;
}

/*!
 * brief Performs an interrupt non-blocking receive transfer on SPDIF.
 */
status_t SPDIF_TransferReceiveNonBlocking(SPDIF_Type *base,
                                               spdif_handle_t *handle,
                                               const spdif_transfer_t *xfer)
{
    status_t status = kStatus_Success;
    uint32_t enableInterrupts;

    assert(base != NULL);
    assert(handle != NULL);
    assert(xfer != NULL);

    /* Validate transfer parameters */
    if ((xfer->data == NULL) || (xfer->dataSize == 0U) || ((xfer->dataSize % 4U) != 0U))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        /* Check if the queue is full */
        if (handle->spdifQueue[handle->queueUser].data != NULL)
        {
            status = kStatus_SPDIF_QueueFull;
        }
        else
        {
            enableInterrupts = kSPDIF_DmaReadRequestInterrupt;

            /* Add into queue */
            handle->transferSize[handle->queueUser]             = xfer->dataSize;
            handle->spdifQueue[handle->queueUser].data          = xfer->data;
            handle->spdifQueue[handle->queueUser].dataSize      = xfer->dataSize;
            handle->spdifQueue[handle->queueUser].channelStatus = xfer->channelStatus;
            handle->spdifQueue[handle->queueUser].userData      = xfer->userData;
            handle->queueUser = (uint8_t)((handle->queueUser + 1U) % SPDIF_XFER_QUEUE_SIZE);

            /* Set state to busy */
            handle->state = kSPDIF_Busy;

            if (xfer->channelStatus != NULL)
            {
                enableInterrupts |= kSPDIF_NewChannelStatusInterrupt;
            }

            if (xfer->userData != NULL)
            {
                enableInterrupts |= kSPDIF_UserDataInterrupt;
            }

            /* Enable interrupt */
            SPDIF_EnableInterrupts(base, enableInterrupts);

            /* Enable Rx transfer */
            SPDIF_RxEnable(base, true);
        }
    }

    return status;
}

/*!
 * brief Gets a sent byte count.
 */
status_t SPDIF_TransferGetSendCount(SPDIF_Type *base, spdif_handle_t *handle, size_t *count)
{
    status_t status = kStatus_Success;
    uint8_t queueDriver;

    assert(base != NULL);
    assert(handle != NULL);
    assert(count != NULL);

    if (handle->state != kSPDIF_Busy)
    {
        status = kStatus_NoTransferInProgress;
    }
    else
    {
        queueDriver = handle->queueDriver;

        /* Check for valid queue index to prevent buffer overflow */
        if (queueDriver < SPDIF_XFER_QUEUE_SIZE)
        {
            *count = (handle->transferSize[queueDriver] - handle->spdifQueue[queueDriver].dataSize);
        }
        else
        {
            status = kStatus_InvalidArgument;
            *count = 0U;
        }
    }

    return status;
}

/*!
 * brief Gets a received byte count.
 */
status_t SPDIF_TransferGetReceiveCount(SPDIF_Type *base, spdif_handle_t *handle, size_t *count)
{
    status_t status = kStatus_Success;
    uint8_t queueDriver;

    assert(base != NULL);
    assert(handle != NULL);
    assert(count != NULL);

    if (handle->state != kSPDIF_Busy)
    {
        status = kStatus_NoTransferInProgress;
    }
    else
    {
        queueDriver = handle->queueDriver;

        /* Check for valid queue index to prevent buffer overflow */
        if (queueDriver < SPDIF_XFER_QUEUE_SIZE)
        {
            *count = (handle->transferSize[queueDriver] - handle->spdifQueue[queueDriver].dataSize);
        }
        else
        {
            status = kStatus_InvalidArgument;
            *count = 0U;
        }
    }

    return status;
}

/*!
 * brief Aborts the current send.
 */
void SPDIF_TransferAbortSend(SPDIF_Type *base, spdif_handle_t *handle)
{
    assert(base != NULL);
    assert(handle != NULL);

    /* Disable interrupt */
    SPDIF_DisableInterrupts(base, kSPDIF_DmaWriteRequestInterrupt);

    handle->state = kSPDIF_Idle;

    /* Clear the queue */
    (void)memset(handle->spdifQueue, 0, sizeof(spdif_transfer_t) * SPDIF_XFER_QUEUE_SIZE);
    handle->queueDriver = 0U;
    handle->queueUser   = 0U;
}

/*!
 * brief Aborts the current IRQ receive.
 */
void SPDIF_TransferAbortReceive(SPDIF_Type *base, spdif_handle_t *handle)
{
    assert(base != NULL);
    assert(handle != NULL);

    /* Disable interrupt */
    SPDIF_DisableInterrupts(base, kSPDIF_UserDataInterrupt | kSPDIF_NewChannelStatusInterrupt |
                                           kSPDIF_DmaReadRequestInterrupt);

    handle->state = kSPDIF_Idle;

    /* Clear the queue */
    (void)memset(handle->spdifQueue, 0, sizeof(spdif_transfer_t) * SPDIF_XFER_QUEUE_SIZE);
    handle->queueDriver = 0U;
    handle->queueUser   = 0U;
}

/*!
 * brief Tx interrupt handler.
 */
void SPDIF_TransferTxHandleIRQ(SPDIF_Type *base, spdif_handle_t *handle)
{
    uint8_t *buffer;
    uint32_t dataSize;
    uint32_t i;
    volatile uint32_t *txFifo;
    uint32_t remainingBytes;
    uint32_t wordsToTransfer;
    const uint32_t *data;
    uint8_t queueDriver;

    assert(base != NULL);
    assert(handle != NULL);

    queueDriver = handle->queueDriver;

    /* Validate queue index */
    if (queueDriver >= SPDIF_XFER_QUEUE_SIZE)
    {
        return;
    }

    buffer = handle->spdifQueue[queueDriver].data;

    /* Check for valid buffer pointer */
    if (buffer == NULL)
    {
        return;
    }

    /* Handle DMA write request */
    if (((SPDIF_GetStatusFlags(base) & kSPDIF_DmaWriteRequest) != 0U) &&
        ((base->EXT_IER0.RW & kSPDIF_DmaWriteRequestInterrupt) != 0U))
    {
        dataSize = (uint32_t)handle->watermark;

        /* Calculate how much data we can actually transfer */
        remainingBytes = handle->spdifQueue[queueDriver].dataSize;

        /* Prevent division by zero and overflow */
        if ((dataSize > 0U) && (remainingBytes > 0U))
        {
            wordsToTransfer = (remainingBytes < (dataSize * 4U)) ? (remainingBytes / 4U) : dataSize;

            /* MISRA C-2012 Rule 11.4: Cast base address to access FIFO */
            txFifo = (volatile uint32_t *)((uintptr_t)base + SPDIF_TX_FIFO_ADDR_OFFSET);

            /* MISRA C-2012 Rule 11.3: Cast to uint32_t pointer for word access */
            data = (const uint32_t *)(const void *)buffer;

            /* Transfer data to FIFO */
            for (i = 0U; i < wordsToTransfer; i++)
            {
                *txFifo = data[i];
            }

            /* Update transfer state */
            handle->spdifQueue[queueDriver].dataSize -= wordsToTransfer * 4U;
            /* MISRA C-2012 Rule 18.4: Pointer arithmetic within bounds */
            handle->spdifQueue[queueDriver].data = &handle->spdifQueue[queueDriver].data[wordsToTransfer * 4U];

            /* If finished a block, call the callback function */
            if (handle->spdifQueue[queueDriver].dataSize == 0U)
            {
                (void)memset(&handle->spdifQueue[queueDriver], 0, sizeof(spdif_transfer_t));
                handle->queueDriver = (uint8_t)((handle->queueDriver + 1U) % SPDIF_XFER_QUEUE_SIZE);

                if (handle->callback != NULL)
                {
                    (handle->callback)(base, handle, kStatus_SPDIF_TxIdle, handle->userData);
                }
            }

            /* If all data finished, just stop the transfer */
            if (handle->spdifQueue[handle->queueDriver].data == NULL)
            {
                SPDIF_TransferAbortSend(base, handle);
            }
        }
    }
}

/*!
 * brief Handle new channel status interrupt.
 */
static void SPDIF_HandleRxChannelStatus(SPDIF_Type *base, spdif_handle_t *handle)
{
    uint8_t *buffer;
    uint32_t i;
    uint8_t queueDriver = handle->queueDriver;

    assert(base != NULL);
    assert(handle != NULL);

    /* Validate queue index */
    if (queueDriver >= SPDIF_XFER_QUEUE_SIZE)
    {
        return;
    }

    /* Clear the interrupt flag */
    SPDIF_ClearStatusFlags(base, kSPDIF_RxNewChannelStatus);

    /* Copy channel status data if buffer is provided */
    buffer = handle->spdifQueue[queueDriver].channelStatus;
    if (buffer != NULL)
    {
        for (i = 0U; i < SPDIF_RX_CS_DATA_BITS_COUNT; i++)
        {
            uint32_t csData  = base->RX_CS_DATA_BITS[i];
            size_t baseIndex = (size_t)i * 4U;

            /* Bounds check to prevent buffer overflow */
            if ((baseIndex + 3U) < (SPDIF_RX_CS_DATA_BITS_COUNT * 4U))
            {
                buffer[baseIndex]      = (uint8_t)(csData & 0xFFU);
                buffer[baseIndex + 1U] = (uint8_t)((csData >> 8U) & 0xFFU);
                buffer[baseIndex + 2U] = (uint8_t)((csData >> 16U) & 0xFFU);
                buffer[baseIndex + 3U] = (uint8_t)((csData >> 24U) & 0xFFU);
            }
        }
        /* Acknowledge channel status */
        base->RX_DATAPATH_CTRL.SET = SPDIF_RX_DATAPATH_CTRL_CSA_MASK;
    }

    if (handle->callback != NULL)
    {
        (handle->callback)(base, handle, kStatus_SPDIF_RxCnew, handle->userData);
    }
}

/*!
 * brief Handle user data interrupt.
 */
static void SPDIF_HandleRxUserData(SPDIF_Type *base, spdif_handle_t *handle)
{
    uint8_t *buffer;
    uint32_t i;
    uint8_t queueDriver = handle->queueDriver;

    assert(base != NULL);
    assert(handle != NULL);

    /* Validate queue index */
    if (queueDriver >= SPDIF_XFER_QUEUE_SIZE)
    {
        return;
    }

    /* Clear the interrupt flag */
    SPDIF_ClearStatusFlags(base, kSPDIF_RxUserData);

    /* Copy user data if buffer is provided */
    buffer = handle->spdifQueue[queueDriver].userData;
    if (buffer != NULL)
    {
        for (i = 0U; i < SPDIF_RX_USER_DATA_BITS_COUNT; i++)
        {
            uint32_t userData = base->RX_USER_DATA_BITS[i];
            size_t baseIndex  = (size_t)i * 4U;

            /* Bounds check to prevent buffer overflow */
            if ((baseIndex + 3U) < (SPDIF_RX_USER_DATA_BITS_COUNT * 4U))
            {
                buffer[baseIndex]      = (uint8_t)(userData & 0xFFU);
                buffer[baseIndex + 1U] = (uint8_t)((userData >> 8U) & 0xFFU);
                buffer[baseIndex + 2U] = (uint8_t)((userData >> 16U) & 0xFFU);
                buffer[baseIndex + 3U] = (uint8_t)((userData >> 24U) & 0xFFU);
            }
        }
        /* Acknowledge user data */
        base->RX_DATAPATH_CTRL.SET = SPDIF_RX_DATAPATH_CTRL_UDA_MASK;
    }

    if (handle->callback != NULL)
    {
        (handle->callback)(base, handle, kStatus_SPDIF_RxUserData, handle->userData);
    }
}

/*!
 * brief Handle FIFO error interrupt.
 */
static void SPDIF_HandleRxFifoError(SPDIF_Type *base, spdif_handle_t *handle)
{
    assert(base != NULL);
    assert(handle != NULL);

    SPDIF_ClearStatusFlags(base, kSPDIF_FifoOverflowUnderflow);

    if (handle->callback != NULL)
    {
        (handle->callback)(base, handle, kStatus_SPDIF_RxFIFOError, handle->userData);
    }
}

/*!
 * brief Handle audio data transfer from RX FIFO.
 */
static void SPDIF_HandleRxDataTransfer(SPDIF_Type *base, spdif_handle_t *handle)
{
    uint8_t *buffer;
    uint32_t dataSize;
    uint32_t i;
    volatile uint32_t *rxFifo;
    uint32_t remainingBytes;
    uint32_t wordsToTransfer;
    uint32_t *data;
    uint8_t queueDriver = handle->queueDriver;

    assert(base != NULL);
    assert(handle != NULL);

    /* Validate queue index */
    if (queueDriver >= SPDIF_XFER_QUEUE_SIZE)
    {
        return;
    }

    dataSize = (uint32_t)handle->watermark;
    buffer   = handle->spdifQueue[queueDriver].data;

    /* Check for valid buffer pointer */
    if (buffer == NULL)
    {
        return;
    }

    /* Calculate how much data we can actually transfer */
    remainingBytes = handle->spdifQueue[queueDriver].dataSize;

    /* Prevent division by zero and overflow */
    if ((dataSize == 0U) || (remainingBytes == 0U))
    {
        return;
    }

    wordsToTransfer = (remainingBytes < (dataSize * 4U)) ? (remainingBytes / 4U) : dataSize;

    /* MISRA C-2012 Rule 11.4: Cast base address to access FIFO */
    rxFifo = (volatile uint32_t *)((uintptr_t)base + SPDIF_RX_FIFO_ADDR_OFFSET);

    /* MISRA C-2012 Rule 11.3: Cast to uint32_t pointer for word access */
    data = (uint32_t *)(void *)buffer;

    /* Transfer data from FIFO */
    for (i = 0U; i < wordsToTransfer; i++)
    {
        data[i] = *rxFifo;
    }

    /* Update transfer state */
    handle->spdifQueue[queueDriver].dataSize -= wordsToTransfer * 4U;
    /* MISRA C-2012 Rule 18.4: Pointer arithmetic within bounds */
    handle->spdifQueue[queueDriver].data = &handle->spdifQueue[queueDriver].data[wordsToTransfer * 4U];

    /* If finished a block, call the callback function */
    if (handle->spdifQueue[queueDriver].dataSize == 0U)
    {
        (void)memset(&handle->spdifQueue[queueDriver], 0, sizeof(spdif_transfer_t));
        handle->queueDriver = (uint8_t)((handle->queueDriver + 1U) % SPDIF_XFER_QUEUE_SIZE);

        if (handle->callback != NULL)
        {
            (handle->callback)(base, handle, kStatus_SPDIF_RxIdle, handle->userData);
        }
    }

    /* If all data finished, just stop the transfer */
    if (handle->spdifQueue[handle->queueDriver].data == NULL)
    {
        SPDIF_TransferAbortReceive(base, handle);
    }
}

/*!
 * brief Rx interrupt handler.
 */
void SPDIF_TransferRxHandleIRQ(SPDIF_Type *base, spdif_handle_t *handle)
{
    uint32_t statusFlags;

    assert(base != NULL);
    assert(handle != NULL);

    statusFlags = SPDIF_GetStatusFlags(base);

    /* Handle new channel status */
    if ((statusFlags & kSPDIF_RxNewChannelStatus) != 0U)
    {
        SPDIF_HandleRxChannelStatus(base, handle);
    }

    /* Handle user data */
    if ((statusFlags & kSPDIF_RxUserData) != 0U)
    {
        SPDIF_HandleRxUserData(base, handle);
    }

    /* Handle FIFO overflow/underflow error */
    if ((statusFlags & kSPDIF_FifoOverflowUnderflow) != 0U)
    {
        SPDIF_HandleRxFifoError(base, handle);
    }

    /* Handle audio data transfer */
    if (((statusFlags & kSPDIF_DmaReadRequest) != 0U) &&
        ((base->EXT_IER0.RW & kSPDIF_DmaReadRequestInterrupt) != 0U))
    {
        SPDIF_HandleRxDataTransfer(base, handle);
    }
}

void SPDIF_DriverIRQHandler(uint32_t instance);
void SPDIF_DriverIRQHandler(uint32_t instance)
{
    if (instance >= ARRAY_SIZE(s_spdifXcvrBases))
    {
        return;
    }
    SPDIF_Type *base = s_spdifXcvrBases[instance];
    if ((s_spdifXcvrHandle[instance][0] != NULL) && (s_spdifXcvrTxIsr != NULL))
    {
        s_spdifXcvrTxIsr(base, s_spdifXcvrHandle[instance][0]);
    }

    if ((s_spdifXcvrHandle[instance][1] != NULL) && (s_spdifXcvrRxIsr != NULL))
    {
        s_spdifXcvrRxIsr(base, s_spdifXcvrHandle[instance][1]);
    }
    SDK_ISR_EXIT_BARRIER;
}
