/*
 * Copyright 2019-2021, 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexio_qspi_smartdma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexio_qspi_smartdma"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Callback function registered to SMARTDMA driver.
 */
static void FLEXIO_QSPI_SMARTDMA_Callback(void *param);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initializes the FLEXO QSPI master SMARTDMA handle.
 *
 * This function initializes the FLEXO QSPI master SMARTDMA handle which can be
 * used for other FLEXO QSPI transactional APIs. For a specified FLEXO QSPI
 * instance, call this API once to get the initialized handle.
 *
 * param base Pointer to FLEXIO_QSPI_Type structure.
 * param handle Pointer to flexio_qspi_smartdma_handle_t structure to store the
 * transfer state.
 * param config Pointer to the configuration.
 * param callback QSPI transfer complete callback, NULL means no callback.
 * param userData callback function parameter.
 * retval kStatus_Success Successfully create the handle.
 */
status_t FLEXIO_QSPI_TransferCreateHandleSMARTDMA(FLEXIO_QSPI_Type *base,
                                                    flexio_qspi_smartdma_handle_t *handle,
                                                    flexio_qspi_smartdma_transfer_callback_t callback,
                                                    void *userData)
{
    assert(handle != NULL);

    IRQn_Type flexio_irqs[] = FLEXIO_IRQS;

    /* Zero the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    handle->smartdmaApi = kSMARTDMA_FLEXIO_QSPI_DMA_NIBBLE_BYTE_SWAP;

    /* Initialize the state. */
    handle->state = (uint32_t)kFLEXIO_QSPI_Idle;

    /* Register callback and userData. */
    handle->callback = callback;
    handle->userData = userData;
    handle->base     = base;

    SMARTDMA_InstallFirmware(SMARTDMA_QSPI_MEM_ADDR, s_smartdmaQspiFirmware, SMARTDMA_QSPI_FIRMWARE_SIZE);

    SMARTDMA_InstallCallback(FLEXIO_QSPI_SMARTDMA_Callback, handle);

    /* Clear pending NVIC IRQ before enable NVIC IRQ. */
    NVIC_ClearPendingIRQ(flexio_irqs[FLEXIO_QSPI_GetInstance(base)]);
    /* Disable interrupt in NVIC. */
    (void)DisableIRQ(flexio_irqs[FLEXIO_QSPI_GetInstance(base)]);

    return kStatus_Success;
}

/*!
 * brief Performs a non-blocking FlexIO QSPI transfer using SMARTDMA.
 *
 * This function returns immediately after transfer initiates. Use the callback
 * function to check whether the transfer is completed.
 *
 * param base pointer to FLEXIO_QSPI_Type structure.
 * param handle pointer to flexio_qspi_smartdma_handle_t structure to store the
 * transfer state.
 * param xfer Pointer to FlexIO QSPI transfer structure.
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_FLEXIO_SPI_Busy FlexIO QSPI is not idle, it is running another
 * transfer.
 */
status_t FLEXIO_QSPI_TransferSMARTDMA(FLEXIO_QSPI_Type *base,
                                        flexio_qspi_smartdma_handle_t *handle,
                                        flexio_qspi_transfer_t *xfer)
{
    assert(handle != NULL);
    assert(xfer != NULL);

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

    for(uint32_t i = 0; i < FLEXIO_QSPI_BUF_MAX; i++)
    {
        if ((uint32_t)xfer->bufs[i].txData & 0x3U) {
            return kStatus_InvalidArgument;
        }
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
    handle->current_buffer = 0;
    
    for(uint32_t i = 0; i < FLEXIO_QSPI_BUF_MAX; i++)
    {
        handle->bufs[i] = xfer->bufs[i];
    }

    handle->smartdmaParam.txRemainingBytes = (uint32_t *)&(handle->txRemainingBytes);
    handle->smartdmaParam.current_buffer   = (uint32_t *)&(handle->current_buffer);
    handle->smartdmaParam.buf_num          = FLEXIO_QSPI_BUF_MAX;
    handle->smartdmaParam.bufs             = handle->bufs;
    
    SMARTDMA_Reset();
    SMARTDMA_Boot(handle->smartdmaApi, &(handle->smartdmaParam), 0);

    /* The shifter interrupt is used by the SMARTDMA. */
    FLEXIO_QSPI_EnableInterrupts(base, (uint32_t)kFLEXIO_SPI_TxEmptyInterruptEnable);

    return kStatus_Success;
}

/*!
 * brief Aborts a FlexIO QSPI transfer using SMARTDMA.
 *
 * param base pointer to FLEXIO_QSPI_Type structure.
 * param handle FlexIO QSPI SMARTDMA handle pointer.
 */
void FLEXIO_QSPI_TransferAbortSMARTDMA(FLEXIO_QSPI_Type *base, flexio_qspi_smartdma_handle_t *handle)
{
    assert(handle != NULL);

    SMARTDMA_Reset();

    /* Set the handle state. */
    handle->state     = (uint32_t)kFLEXIO_QSPI_Idle;
    handle->current_buffer = 0;
    handle->txRemainingBytes = 0;
}

static void FLEXIO_QSPI_SMARTDMA_Callback(void *param)
{
    flexio_qspi_smartdma_handle_t *handle = (flexio_qspi_smartdma_handle_t *)param;
    FLEXIO_QSPI_Type *base = handle->base;

    /* No need to wait for DMA access to complete because DMA firmware confirms SHIFTSTAT */

    FLEXIO_QSPI_TransferAbortSMARTDMA(base, handle);
    
    if (handle->callback != NULL)
    {
        (handle->callback)(base, handle, kStatus_FLEXIO_SPI_Idle, handle->userData);
    }
}
