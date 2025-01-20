/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spi_gpdma.h"
#include "fsl_common_arm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_spi_gpdma"
#endif

/*<! Structure definition for spi_gpdma_private_handle_t. The structure is private. */
typedef struct _spi_gpdma_private_handle
{
    SPI_Type *base;
    spi_gpdma_handle_t *handle;
} spi_gpdma_private_handle_t;

/*! @brief SPI transfer state, which is used for SPI transactiaonl APIs' internal state. */
enum _spi_gpdma_states_t
{
    kSPI_Idle = 0x0, /*!< SPI is idle state */
    kSPI_Busy        /*!< SPI is busy tranferring data. */
};

typedef struct _spi_gpdma_txdummy
{
    uint32_t lastWord;
    uint32_t word;
} spi_gpdma_txdummy_t;

/*! @brief Array to map SPI instance number to base address. */
static const uint32_t s_spiBaseAddrs[] = SPI_BASE_ADDRS;

/*<! Private handle only used for internally. */
static spi_gpdma_private_handle_t s_gpdmaPrivateHandle[ARRAY_SIZE(s_spiBaseAddrs)];

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief GPDMA callback function for SPI send transfer.
 *
 * @param handle GPDMA handle pointer.
 * @param userData User data for GPDMA callback function.
 */
static void SPI_TxGPDMACallback(gpdma_handle_t *handle, void *userData, uint32_t intmode);

/*!
 * @brief GPDMA callback function for SPI receive transfer.
 *
 * @param handle GPDMA handle pointer.
 * @param userData User data for GPDMA callback function.
 */
static void SPI_RxGPDMACallback(gpdma_handle_t *handle, void *userData, uint32_t intmode);

/*******************************************************************************
 * Variables
 ******************************************************************************/
SDK_ALIGN(static spi_gpdma_txdummy_t s_txDummy[ARRAY_SIZE(s_spiBaseAddrs)], 4);
SDK_ALIGN(static uint16_t s_rxDummy, 4);
SDK_ALIGN(static uint32_t s_txLastWord[ARRAY_SIZE(s_spiBaseAddrs)], 4);
SDK_ALIGN(static gpdma_descriptor_t s_spi_descriptor_table[ARRAY_SIZE(s_spiBaseAddrs)], 16);

/*******************************************************************************
 * Code
 ******************************************************************************/

static void XferToFifoWR(spi_transfer_t *xfer, uint32_t *fifowr)
{
    *fifowr |= ((xfer->configFlags & (uint32_t)kSPI_FrameDelay) != 0U) ? (uint32_t)kSPI_FrameDelay : 0U;
    *fifowr |= ((xfer->configFlags & (uint32_t)kSPI_FrameAssert) != 0U) ? (uint32_t)kSPI_FrameAssert : 0U;
}

static void SpiConfigToFifoWR(spi_config_t *config, uint32_t *fifowr)
{
    *fifowr |= ((uint32_t)SPI_DEASSERT_ALL & (~(uint32_t)SPI_DEASSERTNUM_SSEL((uint32_t)config->sselNum)));
    /* set width of data - range asserted at entry */
    *fifowr |= SPI_FIFOWR_LEN(config->dataWidth);
}

static void PrepareTxLastWord(spi_transfer_t *xfer, uint32_t *txLastWord, spi_config_t *config)
{
    if (config->dataWidth > kSPI_Data8Bits)
    {
        *txLastWord = (((uint32_t)xfer->txData[xfer->dataSize - 1U] << 8U) | (xfer->txData[xfer->dataSize - 2U]));
    }
    else
    {
        *txLastWord = xfer->txData[xfer->dataSize - 1U];
    }
    XferToFifoWR(xfer, txLastWord);
    SpiConfigToFifoWR(config, txLastWord);
}

/*!
 * brief Initialize the SPI master GPDMA handle.
 *
 * This function initializes the SPI master GPDMA handle which can be used for other SPI master transactional APIs.
 * Usually, for a specified SPI instance, user need only call this API once to get the initialized handle.
 *
 * param base SPI peripheral base address.
 * param handle SPI handle pointer.
 * param callback User callback function called at the end of a transfer.
 * param userData User data for callback.
 * param txHandle GPDMA handle pointer for SPI Tx, the handle shall be static allocated by users.
 * param rxHandle GPDMA handle pointer for SPI Rx, the handle shall be static allocated by users.
 */
status_t SPI_MasterTransferCreateHandleGPDMA(SPI_Type *base,
                                             spi_gpdma_handle_t *handle,
                                             spi_gpdma_callback_t callback,
                                             void *userData,
                                             gpdma_handle_t *txHandle,
                                             gpdma_handle_t *rxHandle)
{
    uint32_t instance;

    /* check 'base' */
    assert(!(NULL == base));
    if (NULL == base)
    {
        return kStatus_InvalidArgument;
    }
    /* check 'handle' */
    assert(!(NULL == handle));
    if (NULL == handle)
    {
        return kStatus_InvalidArgument;
    }

    instance = SPI_GetInstance(base);

    (void)memset(handle, 0, sizeof(*handle));
    /* Set spi base to handle */
    handle->txHandle = txHandle;
    handle->rxHandle = rxHandle;
    handle->callback = callback;
    handle->userData = userData;

    /* Set SPI state to idle */
    handle->state = (uint8_t)kSPI_Idle;

    /* Set handle to global state */
    s_gpdmaPrivateHandle[instance].base   = base;
    s_gpdmaPrivateHandle[instance].handle = handle;

    /* Install callback for Tx gpdma channel */
    GPDMA_SetCallback(handle->txHandle, SPI_TxGPDMACallback, &s_gpdmaPrivateHandle[instance]);
    GPDMA_SetCallback(handle->rxHandle, SPI_RxGPDMACallback, &s_gpdmaPrivateHandle[instance]);

    return kStatus_Success;
}

/*!
 * brief Perform a non-blocking SPI transfer using GPDMA.
 *
 * note This interface returned immediately after transfer initiates, users should call
 * SPI_GetTransferStatus to poll the transfer status to check whether SPI transfer finished.
 *
 * param base SPI peripheral base address.
 * param handle SPI GPDMA handle pointer.
 * param xfer Pointer to gpdma transfer structure.
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_MasterTransferGPDMA(SPI_Type *base, spi_gpdma_handle_t *handle, spi_transfer_t *xfer)
{
    assert(!((NULL == handle) || (NULL == xfer)));

    uint32_t instance;
    status_t result = kStatus_Success;
    spi_config_t *spi_config_p;
    uint32_t address;

    if ((NULL == handle) || (NULL == xfer))
    {
        return kStatus_InvalidArgument;
    }

    /* Byte size is zero. */
    if (xfer->dataSize == 0U)
    {
        return kStatus_InvalidArgument;
    }
    /* cannot get instance from base address */
    instance = SPI_GetInstance(base);

    /* Check if the device is busy */
    if (handle->state == (uint8_t)kSPI_Busy)
    {
        return kStatus_SPI_Busy;
    }
    else
    {
        /* Clear FIFOs before transfer. */
        base->FIFOCFG |= SPI_FIFOCFG_EMPTYTX_MASK | SPI_FIFOCFG_EMPTYRX_MASK;
        base->FIFOSTAT |= SPI_FIFOSTAT_TXERR_MASK | SPI_FIFOSTAT_RXERR_MASK;

        gpdma_transfer_config_t xferConfig = {0};
        spi_config_p                       = (spi_config_t *)SPI_GetConfig(base);

        handle->state        = (uint8_t)kSPI_Busy;
        handle->transferSize = xfer->dataSize;

        /* receive */
        SPI_EnableRxDMA(base, true);
        address = (uint32_t)&base->FIFORD;
        if (xfer->rxData != NULL)
        {
            GPDMA_PrepareTransferConfig(&xferConfig, (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                        xfer->rxData, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes, xfer->dataSize,
                                        kGPDMA_TransferP2MControllerDma, 0UL);
        }
        else
        {
            GPDMA_PrepareTransferConfig(&xferConfig, (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                        &s_rxDummy, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes, xfer->dataSize,
                                        kGPDMA_TransferP2PControllerDestPeripheral, 0UL);
        }
        (void)GPDMA_SubmitTransfer(handle->rxHandle, &xferConfig);
        handle->rxInProgress = true;
        GPDMA_StartTransfer(handle->rxHandle);

        /* transmit */
        SPI_EnableTxDMA(base, true);
        address = (uint32_t)&base->FIFOWR;
        if (xfer->txData != NULL)
        {
            if ((xfer->configFlags & (uint32_t)kSPI_FrameAssert) != 0U)
            {
                PrepareTxLastWord(xfer, &s_txLastWord[instance], spi_config_p);
            }
            /* If end of tranfer function is enabled and data transfer frame is bigger then 1, use gpdma
             * descriptor to send the last data.
             */
            if (((xfer->configFlags & (uint32_t)kSPI_FrameAssert) != 0U) &&
                ((spi_config_p->dataWidth > kSPI_Data8Bits) ? (xfer->dataSize > 2U) : (xfer->dataSize > 1U)))
            {
                (void)GPDMA_PrepareDescriptor(&s_spi_descriptor_table[instance], &s_txLastWord[instance],
                                              kGPDMA_BurstSize1, kGPDMA_TransferWidth4Bytes, (uint32_t *)address,
                                              kGPDMA_BurstSize1, kGPDMA_TransferWidth4Bytes, (4U),
                                              kGPDMA_TransferM2PControllerDma, 0UL);
                GPDMA_PrepareTransferConfig(&xferConfig, xfer->txData, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                            (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                            (xfer->dataSize - 1U), kGPDMA_TransferM2PControllerDma,
                                            (uint32_t)&s_spi_descriptor_table[instance]);
                (void)GPDMA_SubmitTransfer(handle->txHandle, &xferConfig);
            }
            else
            {
                GPDMA_PrepareTransferConfig(&xferConfig, &s_txDummy, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                            (uint32_t *)address, kGPDMA_BurstSize1, kGPDMA_TransferWidth1Bytes,
                                            xfer->dataSize, kGPDMA_TransferM2PControllerDma, 0UL);
                (void)GPDMA_SubmitTransfer(handle->txHandle, &xferConfig);
            }
        }

        handle->txInProgress  = true;
        uint32_t tmpData      = 0U;
        uint32_t writeAddress = (uint32_t) & (base->FIFOWR) + 2UL;
        XferToFifoWR(xfer, &tmpData);
        SpiConfigToFifoWR(spi_config_p, &tmpData);

        /* Setup the control info.
         * Halfword writes to just the control bits (offset 0xE22) doesn't push anything into the FIFO.
         * And the data access type of control bits must be uint16_t, byte writes or halfword writes to FIFOWR
         * will push the data and the current control bits into the FIFO.
         */
        if (((xfer->configFlags & (uint32_t)kSPI_FrameAssert) != 0U) &&
            ((spi_config_p->dataWidth > kSPI_Data8Bits) ? (xfer->dataSize == 2U) : (xfer->dataSize == 1U)))
        {
            *(uint16_t *)writeAddress = (uint16_t)(tmpData >> 16U);
        }
        else
        {
            /* Clear the SPI_FIFOWR_EOT_MASK bit when data is not the last. */
            tmpData &= (~(uint32_t)kSPI_FrameAssert);
            *(uint16_t *)writeAddress = (uint16_t)(tmpData >> 16U);
        }

        GPDMA_StartTransfer(handle->txHandle);
    }
    return result;
}

static void SPI_RxGPDMACallback(gpdma_handle_t *handle, void *userData, uint32_t intmode)
{
    spi_gpdma_private_handle_t *privHandle = (spi_gpdma_private_handle_t *)userData;
    spi_gpdma_handle_t *spiHandle          = privHandle->handle;
    SPI_Type *base                         = privHandle->base;

    /* change the state */
    spiHandle->rxInProgress = false;

    /* All finished, call the callback */
    if ((spiHandle->txInProgress == false) && (spiHandle->rxInProgress == false))
    {
        spiHandle->state = (uint8_t)kSPI_Idle;

        if (spiHandle->callback != NULL)
        {
            (spiHandle->callback)(base, spiHandle, kStatus_Success, spiHandle->userData);
        }
    }
}

static void SPI_TxGPDMACallback(gpdma_handle_t *handle, void *userData, uint32_t intmode)
{
    spi_gpdma_private_handle_t *privHandle = (spi_gpdma_private_handle_t *)userData;
    spi_gpdma_handle_t *spiHandle          = privHandle->handle;
    SPI_Type *base                         = privHandle->base;

    /* change the state */
    spiHandle->txInProgress = false;
    /* All finished, call the callback */
    if ((spiHandle->txInProgress == false) && (spiHandle->rxInProgress == false))
    {
        spiHandle->state = (uint8_t)kSPI_Idle;
        if (spiHandle->callback != NULL)
        {
            (spiHandle->callback)(base, spiHandle, kStatus_Success, spiHandle->userData);
        }
    }
}

/*!
 * brief Abort a SPI transfer using GPDMA.
 *
 * param base SPI peripheral base address.
 * param handle SPI GPDMA handle pointer.
 */
void SPI_MasterTransferAbortGPDMA(SPI_Type *base, spi_gpdma_handle_t *handle)
{
    assert(NULL != handle);

    /* Stop tx transfer first */
    GPDMA_AbortTransfer(handle->txHandle);
    /* Then rx transfer */
    GPDMA_AbortTransfer(handle->rxHandle);

    /* Set the handle state */
    handle->txInProgress = false;
    handle->rxInProgress = false;
    handle->state        = (uint8_t)kSPI_Idle;
}
