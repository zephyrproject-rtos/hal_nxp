/*
 * Copyright 2017-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.vspi"
#endif

/* Convert transfer count to transfer bytes. dataWidth is a
 * range <0,15>. Range <8,15> represents 2B transfer */
#define SPI_COUNT_TO_BYTES(dataWidth, count) ((count) << ((dataWidth) >> 3U))
#define SPI_BYTES_TO_COUNT(dataWidth, bytes) ((bytes) >> ((dataWidth) >> 3U))
#define SPI_SSELPOL_MASK                     ((SPI_CFG_SPOL0_MASK) | (SPI_CFG_SPOL1_MASK) | (SPI_CFG_SPOL2_MASK) | (SPI_CFG_SPOL3_MASK))

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief SPI internal handle pointer array */
static spi_master_handle_t *s_spiHandle[FSL_FEATURE_SOC_SPI_COUNT];

/*! @brief internal SPI config array */
static spi_config_t g_configs[FSL_FEATURE_SOC_SPI_COUNT] = {(spi_data_width_t)0};

/*! @brief Array to map SPI instance number to base address. */
static const uint32_t s_spiBaseAddrs[FSL_FEATURE_SOC_SPI_COUNT] = SPI_BASE_ADDRS;

/*! @brief IRQ name array */
static const IRQn_Type s_spiIRQ[] = SPI_IRQS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* @brief Array to map SPI instance number to CLOCK names */
static const clock_ip_name_t s_spiClock[] = SPI_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
/* @brief Array to map SPI reset. */
static const SYSCON_RSTn_t s_spiReset[2] = {kSPI0_RST_SHIFT_RSTn, kSPI1_RST_SHIFT_RSTn};
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

/*! @brief Typedef for spi master interrupt handler. spi master and slave handle is the same. */
typedef void (*spi_isr_t)(SPI_Type *base, spi_master_handle_t *spiHandle);

/*! @brief Pointer to master IRQ handler for each instance. */
static spi_isr_t s_spiMasterIsr;
static spi_isr_t s_spiSlaveIsr;

/* @brief Dummy data for each instance. This data is used when user's tx buffer is NULL*/
volatile uint8_t s_dummyData[FSL_FEATURE_SOC_SPI_COUNT] = {0};
/*******************************************************************************
 * Code
 ******************************************************************************/

/* Get the index corresponding to the FLEXCOMM */
/*! brief Returns instance number for SPI peripheral base address. */
uint32_t SPI_GetInstance(SPI_Type *base)
{
    assert(NULL != base);

    uint32_t i = 0U;

    for (i = 0; i < (uint32_t)FSL_FEATURE_SOC_SPI_COUNT; i++)
    {
        if (MSDK_REG_SECURE_ADDR((uint32_t)base) == MSDK_REG_SECURE_ADDR(s_spiBaseAddrs[i]))
        {
            break;
        }
    }

    assert(i < FSL_FEATURE_SOC_SPI_COUNT);
    return i;
}

/*!
 * brief Set up the dummy data.
 *
 * param base SPI peripheral address.
 * param dummyData Data to be transferred when tx buffer is NULL.
 */
void SPI_SetDummyData(SPI_Type *base, uint8_t dummyData)
{
    uint32_t instance     = SPI_GetInstance(base);
    s_dummyData[instance] = dummyData;
}

/* Get the information of datawidth and SSEL number. */
/*!
 * brief Returns the configurations.
 *
 * param base SPI peripheral address.
 * return return configurations which contain datawidth and SSEL numbers.
 *         return data type is a pointer of spi_config_t.
 */
void *SPI_GetConfig(SPI_Type *base)
{
    uint32_t instance = SPI_GetInstance(base);

    return &g_configs[instance];
}

/* Get status flags from FIFO status register. */
/*!
 * brief Gets the FIFO status flag for SPI transfer.
 *
 * param base SPI base pointer
 * return SPI Status, use status flag to AND ref _spi_fifo_status_flags could get the related status.
 */
uint32_t SPI_GetFifoStatusFlags(SPI_Type *base)
{
    uint32_t instance = SPI_GetInstance(base);
    return (VFIFO->SPI[instance].STATSPI);
}

/* Clear status flags of FIFO status register. */
/*!
 * brief Clear the FIFO status flag for SPI transfer.
 * Only kSPI_RxFifoTimeOutFlag and kSPI_FifoBusErrorFlag can be cleared.
 * param base SPI base pointer
 * param mask use status flag to AND ref _spi_status_flags could get the related status.
 */
void SPI_ClearFifoStatusFlags(SPI_Type *base, uint32_t mask)
{
    uint32_t instance = SPI_GetInstance(base);
    VFIFO->SPI[instance].STATSPI |= mask;
}

/* Enable FIFO interrupt from FIFO CTLSETSPI register. */
/*!
 * brief Enables the FIFO interrupt for the SPI.
 *
 * param base SPI base pointer
 * param irqs SPI interrupt source. The parameter can be any combination of the following values:
 *        arg kSPI_RxFifoThresholdInterruptEnable
 *        arg kSPI_TxFifoThresholdInterruptEnable
 */
void SPI_EnableFifoInterrupts(SPI_Type *base, uint32_t irqs)
{
    uint32_t instance = SPI_GetInstance(base);
    VFIFO->SPI[instance].CTLSETSPI |= irqs;
}

/* Clear FIFO interrupt from FIFO CTLCLRSPI register. */
/*!
 * brief Disables the FIFO interrupt for the SPI.
 *
 * param base SPI base pointer
 * param irqs SPI interrupt source. The parameter can be any combination of the following values:
 *        arg kSPI_RxFifoThresholdInterruptEnable
 *        arg kSPI_TxFifoThresholdInterruptEnable
 */
void SPI_DisableFifoInterrupts(SPI_Type *base, uint32_t irqs)
{
    uint32_t instance = SPI_GetInstance(base);
    VFIFO->SPI[instance].CTLCLRSPI |= irqs;
}

/* Flush the FIFO for SPI transfer. */
/*!
 * brief Flush the FIFO buffer.
 *
 * This function will Flush tHE fifo buffer.
 *
 * param base SPI peripheral base address.
 * param direction the fifo direction need to flushed, Tx FIFO or Rx FIFO.
 */
void SPI_FifoFlush(SPI_Type *base, uint32_t direction)
{
    uint32_t instance = SPI_GetInstance(base);

    if (((uint32_t)kSPI_FifoTx & direction) != 0U)
    {
        VFIFO->SPI[instance].CTLSETSPI |= VFIFO_SPI_CTLSETSPI_TXFLUSH_MASK;
        VFIFO->SPI[instance].CTLCLRSPI |= VFIFO_SPI_CTLCLRSPI_TXFLUSHCLR_MASK;
    }

    if (((uint32_t)kSPI_FifoRx & direction) != 0U)
    {
        VFIFO->SPI[instance].CTLSETSPI |= VFIFO_SPI_CTLSETSPI_RXFLUSH_MASK;
        VFIFO->SPI[instance].CTLCLRSPI |= VFIFO_SPI_CTLCLRSPI_RXFLUSHCLR_MASK;
    }
}

/* Enable SPI FIFO function. */
/*!
 * brief Enable FIFO for SPI.
 *
 * This function will enable the FIFO for SPI according to pointer of the configure struct.
 * Note: If this API is called, please reset the baudrate to adapt your demand after this API
 * was called.
 *
 * param base SPI peripheral base address.
 * param config pointer to FIFO configuration structure.
 */
void SPI_EnableFifo(SPI_Type *base, const spi_fifo_config_t *config)
{
    uint32_t instance = 0U;
    assert((config->enableRxFifo) || (config->enableTxFifo));

    instance = SPI_GetInstance(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Fifo);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Configure the FIFOCTRL register to enable the SPI TX/RX FIFO . */
    switch (instance)
    {
        case 0:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_SPI0TXFIFOEN_MASK | SYSCON_FIFOCTRL_SPI0RXFIFOEN_MASK);
            SYSCON->FIFOCTRL |=
                SYSCON_FIFOCTRL_SPI0TXFIFOEN(config->enableTxFifo) | SYSCON_FIFOCTRL_SPI0RXFIFOEN(config->enableRxFifo);
            break;
        case 1:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_SPI1TXFIFOEN_MASK | SYSCON_FIFOCTRL_SPI1RXFIFOEN_MASK);
            SYSCON->FIFOCTRL |=
                SYSCON_FIFOCTRL_SPI1TXFIFOEN(config->enableTxFifo) | SYSCON_FIFOCTRL_SPI1RXFIFOEN(config->enableRxFifo);
            break;
        default:
            assert(false);
            break;
    }
    /* Pause the SPI FIFO for setting. */
    while (!(((VFIFO->FIFOCTLSPI & VFIFO_FIFOCTLSPI_RXPAUSED_MASK) != 0U) &&
             ((VFIFO->FIFOCTLSPI & VFIFO_FIFOCTLSPI_TXPAUSED_MASK) != 0U)))
    {
        VFIFO->FIFOCTLSPI |= (VFIFO_FIFOCTLSPI_RXPAUSE_MASK | VFIFO_FIFOCTLSPI_TXPAUSE_MASK);
    }
    /* Flush the  TX and RX FIFO buffer. */
    SPI_FifoFlush(base, (uint32_t)kSPI_FifoTx | (uint32_t)kSPI_FifoRx);
    /* Set the TX and RX FIFO size. */
    VFIFO->FIFOCFGSPI[instance] =
        VFIFO_FIFOCFGSPI_RXSIZE(config->rxFifoSize) | VFIFO_FIFOCFGSPI_TXSIZE(config->txFifoSize);
    /* Update all the SPI FIFO size. */
    VFIFO->FIFOUPDATESPI |= VFIFO_FIFOUPDATESPI_SPI0RXUPDATESIZE_MASK | VFIFO_FIFOUPDATESPI_SPI0TXUPDATESIZE_MASK |
                            VFIFO_FIFOUPDATESPI_SPI1RXUPDATESIZE_MASK | VFIFO_FIFOUPDATESPI_SPI1TXUPDATESIZE_MASK;
    /* Set the TX and RX FIFO threshold size. */
    VFIFO->SPI[instance].CFGSPI &= ~(VFIFO_SPI_CFGSPI_RXTHRESHOLD_MASK | VFIFO_SPI_CFGSPI_TXTHRESHOLD_MASK);
    VFIFO->SPI[instance].CFGSPI |=
        VFIFO_SPI_CFGSPI_RXTHRESHOLD(config->rxFifoThreshold) | VFIFO_SPI_CFGSPI_TXTHRESHOLD(config->txFifoThreshold);
    /* Unpause the system FIFO for transfer. */
    VFIFO->FIFOCTLSPI &= ~(VFIFO_FIFOCTLSPI_RXPAUSE_MASK | VFIFO_FIFOCTLSPI_TXPAUSE_MASK);
}

/* Disable system FIFO. */
/*!
 * brief Disable FIFO for SPI.
 *
 * This function will Disable the FIFO for SPI transfer.
 * disable interrupts, clear status flags, disable the TX/RX FIFO, set fifo size to zero.
 * But will not disable the system FIFO, because other instance like USART may using the FIFO.
 *
 * param base SPI peripheral base address.
 * param config pointer to FIFO configuration structure.
 */
void SPI_DisableFifo(SPI_Type *base)
{
    assert(NULL != base);
    uint32_t instance = SPI_GetInstance(base);

    /* Pause the SPI FIFO for setting. */
    while (!(((VFIFO->FIFOCTLSPI & VFIFO_FIFOCTLSPI_RXPAUSED_MASK) != 0U) &&
             ((VFIFO->FIFOCTLSPI & VFIFO_FIFOCTLSPI_TXPAUSED_MASK) != 0U)))
    {
        VFIFO->FIFOCTLSPI |= (VFIFO_FIFOCTLSPI_RXPAUSE_MASK | VFIFO_FIFOCTLSPI_TXPAUSE_MASK);
    }

    /* Flush the  TX and RX FIFO buffer. */
    SPI_FifoFlush(base, (uint32_t)kSPI_FifoTx | (uint32_t)kSPI_FifoRx);
    /* Set the TX and RX FIFO size to zero. */
    VFIFO->FIFOCFGSPI[instance] = VFIFO_FIFOCFGSPI_RXSIZE(0U) | VFIFO_FIFOCFGSPI_TXSIZE(0U);
    /* Update all the SPI FIFO size. */
    VFIFO->FIFOUPDATESPI |= VFIFO_FIFOUPDATESPI_SPI0RXUPDATESIZE_MASK | VFIFO_FIFOUPDATESPI_SPI0TXUPDATESIZE_MASK |
                            VFIFO_FIFOUPDATESPI_SPI1RXUPDATESIZE_MASK | VFIFO_FIFOUPDATESPI_SPI1TXUPDATESIZE_MASK;
    /* Disable all FIFO interrupts. */
    SPI_DisableFifoInterrupts(base, (uint32_t)kSPI_AllFifoInterruptEnable);
    /* Clear all FIFO status flags, only receive timeout and bus error flag can be cleared. */
    SPI_ClearFifoStatusFlags(base, (uint32_t)kSPI_RxFifoTimeOutFlag | (uint32_t)kSPI_FifoBusErrorFlag);
    /* Unpause the system FIFO for transfer. */
    VFIFO->FIFOCTLSPI &= ~(VFIFO_FIFOCTLSPI_RXPAUSE_MASK | VFIFO_FIFOCTLSPI_TXPAUSE_MASK);

    /* Disable the TX/RX FIFO for tansfer. */
    switch (instance)
    {
        case 0:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_SPI0TXFIFOEN_MASK | SYSCON_FIFOCTRL_SPI0RXFIFOEN_MASK);
            break;
        case 1:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_SPI1TXFIFOEN_MASK | SYSCON_FIFOCTRL_SPI1RXFIFOEN_MASK);
            break;
        default:
            assert(false);
            break;
    }
}
/* Check if TX FIFO enabled. */
/*!
 * brief Is TX FIFO enabled.
 *
 * This function will return status if the transmit fifo is enabled. true for enabled and false for not enabled.
 *
 * param base SPI peripheral base address.
 * return true for enabled and false for not enabled.
 */
bool SPI_IsTxFifoEnabled(SPI_Type *base)
{
    uint32_t instance = SPI_GetInstance(base);
    uint32_t fifosize = VFIFO->FIFOCFGSPI[instance];
    bool status       = false;

    /* Check if system FIFO control TX is enabled. */
    switch (instance)
    {
        case 0:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_SPI0TXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 1:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_SPI1TXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        default:
            assert(false);
            break;
    }

    if (status != true)
    {
        return status;
    }
    /* Check if TX FIFO size is available. */
    return ((fifosize & VFIFO_FIFOCFGSPI_TXSIZE_MASK) != 0U) ? (true) : (false);
}

/* Check if RX FIFO enabled. */
/*!
 * brief Is RX FIFO enabled.
 *
 * This function will return status if the receive fifo is enabled. true for enabled and false for not enabled.
 *
 * param base SPI peripheral base address.
 * return true for enabled and false for not enabled.
 */
bool SPI_IsRxFifoEnabled(SPI_Type *base)
{
    uint32_t instance = SPI_GetInstance(base);
    uint32_t fifosize = VFIFO->FIFOCFGSPI[instance];
    bool status       = false;

    /* Check if system FIFO control RX is enabled. */
    switch (instance)
    {
        case 0:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_SPI0RXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 1:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_SPI1RXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        default:
            assert(false);
            break;
    }

    if (status != true)
    {
        return status;
    }

    /* Check if RX FIFO size is available. */
    return ((fifosize & VFIFO_FIFOCFGSPI_RXSIZE_MASK) != 0U) ? (true) : (false);
}

static void SPI_SendTransfer(SPI_Type *base, spi_master_handle_t *handle)
{
    uint32_t tmp32    = 0U;
    uint32_t instance = SPI_GetInstance(base);

    if (handle->isTxFifoEnabled)
    {
        /* Fill data to tx fifo buffer until the data in FIFO reach the TX threshold or no data to be sent. */
        while (((VFIFO->SPI[instance].STATSPI & VFIFO_SPI_STATSPI_TXTH_MASK) != 0U) && (handle->txRemainingBytes != 0U))
        {
            if ((handle->txData) != NULL)
            {
                tmp32 = *(handle->txData++);
                handle->txRemainingBytes--;
                if (handle->dataWidth > 7U)
                {
                    tmp32 |= ((uint32_t)(*(handle->txData++)) << 8U);
                    handle->txRemainingBytes--;
                }
            }
            else
            {
                tmp32 = s_dummyData[instance];
                handle->txRemainingBytes--;
                if (handle->dataWidth > 7U)
                {
                    tmp32 |= ((uint32_t)s_dummyData[instance] << 8U);
                    handle->txRemainingBytes--;
                }
            }
            /* If this transmit is the last to send, Set the control bits and disable Tx interrupt. */
            if (handle->txRemainingBytes == 0U)
            {
                VFIFO->SPI[instance].TXDATSPI = (tmp32 | handle->lastCommand);
            }
            else
            {
                VFIFO->SPI[instance].TXDATSPI = (tmp32 | handle->commonCommand);
            }
        }
    }
    else
    {
        /* If transmit is ready, write data once to TXDATCTL register. */
        if ((((uint32_t)kSPI_TxReadyFlag & SPI_GetStatusFlags(base)) != 0U) && (handle->txRemainingBytes != 0U))
        {
            if ((handle->txData) != NULL)
            {
                tmp32 = *(handle->txData++);
                handle->txRemainingBytes--;
                if (handle->dataWidth > 7U)
                {
                    tmp32 |= ((uint32_t)(*(handle->txData++)) << 8U);
                    handle->txRemainingBytes--;
                }
            }
            else
            {
                tmp32 = (uint32_t)s_dummyData[instance];
                tmp32 |= ((uint32_t)s_dummyData[instance] << 8U);
                handle->txRemainingBytes--;
                if (handle->dataWidth > 7U)
                {
                    handle->txRemainingBytes--;
                }
            }
            /* If this transmit is the last to send, Set the control bits and disable Tx interrupt. */
            if (handle->txRemainingBytes == 0U)
            {
                base->TXDATCTL = (tmp32 | handle->lastCommand);
            }
            else
            {
                base->TXDATCTL = (tmp32 | handle->commonCommand);
            }
        }
    }
}

static void SPI_ReceiveTransfer(SPI_Type *base, spi_master_handle_t *handle)
{
    uint32_t tmp32    = 0U;
    uint32_t instance = SPI_GetInstance(base);

    if (handle->isRxFifoEnabled)
    {
        /* Read data from fifo buffer until the rx fifo is empty or to receive bytes is zero. */
        while ((0U == (VFIFO->SPI[instance].STATSPI & VFIFO_SPI_STATSPI_RXEMPTY_MASK)) &&
               (handle->rxRemainingBytes != 0U))
        {
            tmp32 = VFIFO->SPI[instance].RXDATSPI;
            /* Check If receive buffer is NULL. */
            if ((handle->rxData) != NULL)
            {
                *(handle->rxData++) = (uint8_t)tmp32;
                handle->rxRemainingBytes--;
                if (handle->dataWidth > 7U)
                {
                    *(handle->rxData++) = (uint8_t)(tmp32 >> 8U);
                    handle->rxRemainingBytes--;
                }
            }
        }
    }
    else
    {
        /* If receive is ready, read data from RXDAT register. */
        if ((((uint32_t)kSPI_RxReadyFlag & SPI_GetStatusFlags(base)) != 0U) && (handle->rxRemainingBytes != 0U))
        {
            tmp32 = (base->RXDAT & 0x0000FFFFU);
            /* Check If receive buffer is NULL. */
            if (handle->rxData != NULL)
            {
                *(handle->rxData++) = (uint8_t)tmp32;
                handle->rxRemainingBytes--;
                if (handle->dataWidth > 7U)
                {
                    *(handle->rxData++) = (uint8_t)(tmp32 >> 8U);
                    handle->rxRemainingBytes--;
                }
            }
        }
    }
}

/* Set delay time for SPI transfer. */
/*!
 * brief Set delay time for transfer.
 *        the delay uint is SPI clock time, maximum value is 0xF.
 * param base SPI base pointer
 * param config configuration for delay option ref spi_delay_config_t.
 */
void SPI_SetTransferDelay(SPI_Type *base, const spi_delay_config_t *config)
{
    assert(NULL != config);
    /* Clear the DLY register. */
    base->DLY &=
        ~(SPI_DLY_PRE_DELAY_MASK | SPI_DLY_POST_DELAY_MASK | SPI_DLY_FRAME_DELAY_MASK | SPI_DLY_TRANSFER_DELAY_MASK);
    /* Set the delay configuration. */
    base->DLY |= (SPI_DLY_PRE_DELAY(config->preDelay) | SPI_DLY_POST_DELAY(config->postDelay) |
                  SPI_DLY_FRAME_DELAY(config->frameDelay) | SPI_DLY_TRANSFER_DELAY(config->transferDelay));
}
/*!
 * brief  Sets the SPI master configuration structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for use in SPI_MasterInit().
 * User may use the initialized structure unchanged in SPI_MasterInit(), or modify
 * some fields of the structure before calling SPI_MasterInit(). After calling this API,
 * the master is ready to transfer.
 * Example:
   code
   spi_master_config_t config;
   SPI_MasterGetDefaultConfig(&config);
   endcode
 *
 * param config pointer to master config structure
 */
void SPI_MasterGetDefaultConfig(spi_master_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableLoopback             = false;
    config->enableMaster               = true;
    config->polarity                   = kSPI_ClockPolarityActiveHigh;
    config->phase                      = kSPI_ClockPhaseFirstEdge;
    config->direction                  = kSPI_MsbFirst;
    config->baudRate_Bps               = 500000U;
    config->dataWidth                  = kSPI_Data8Bits;
    config->sselNum                    = kSPI_Ssel0;
    config->sselPol                    = kSPI_SpolActiveAllLow;
    config->fifoConfig.enableRxFifo    = false;
    config->fifoConfig.enableTxFifo    = false;
    config->fifoConfig.rxFifoSize      = 0U;
    config->fifoConfig.txFifoSize      = 0U;
    config->fifoConfig.rxFifoThreshold = 0U;
    config->fifoConfig.txFifoThreshold = 1U;
    config->delayConfig.frameDelay     = 0U;
    config->delayConfig.postDelay      = 0U;
    config->delayConfig.preDelay       = 0U;
    config->delayConfig.transferDelay  = 0U;
}

/*!
 * brief Initializes the SPI with master configuration.
 *
 * The configuration structure can be filled by user from scratch, or be set with default
 * values by SPI_MasterGetDefaultConfig(). After calling this API, the slave is ready to transfer.
 * Example
   code
   spi_master_config_t config = {
   .baudRate_Bps = 500000,
   ...
   };
   SPI_MasterInit(SPI0, &config);
   endcode
 *
 * param base SPI base pointer
 * param config pointer to master configuration structure
 * param srcClock_Hz Source clock frequency.
 */
status_t SPI_MasterInit(SPI_Type *base, const spi_master_config_t *config, uint32_t srcClock_Hz)
{
    uint32_t instance = 0;
    status_t result   = 0;
    uint32_t tmp      = 0U;

    /* assert params */
    assert(!((NULL == base) || (NULL == config) || (0U == srcClock_Hz)));

    /* Get instance number */
    instance = SPI_GetInstance(base);

    /* Config FIFOs if the system FIFO is enabled.
     * Note: The FIFO should be enabled before the baudrate has been configured.
     */
    if ((config->fifoConfig.enableRxFifo) || (config->fifoConfig.enableTxFifo))
    {
        SPI_EnableFifo(base, &(config->fifoConfig));
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_spiClock[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
    /* Reset the module. */
    RESET_PeripheralReset(s_spiReset[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

    /* set divider */
    result = SPI_MasterSetBaud(base, config->baudRate_Bps, srcClock_Hz);
    if (kStatus_Success != result)
    {
        return result;
    }

    /* configure SPI mode */
    tmp &= ~(SPI_CFG_MASTER_MASK | SPI_CFG_LSBF_MASK | SPI_CFG_CPHA_MASK | SPI_CFG_CPOL_MASK | SPI_CFG_LOOP_MASK |
             SPI_CFG_ENABLE_MASK | SPI_SSELPOL_MASK);
    /* Setup configuration. */
    tmp |= SPI_CFG_CPHA(config->phase) | SPI_CFG_CPOL(config->polarity) | SPI_CFG_LSBF(config->direction) |
           SPI_CFG_MASTER(1) | SPI_CFG_LOOP(config->enableLoopback) | ((uint32_t)config->sselPol & (SPI_SSELPOL_MASK));
    base->CFG = tmp;

    /* Set delay configuration. */
    SPI_SetTransferDelay(base, &(config->delayConfig));

    /* store configuration */
    g_configs[instance].dataWidth = config->dataWidth;
    g_configs[instance].sselNum   = config->sselNum;

    SPI_SetDummyData(base, (uint8_t)SPI_DUMMYDATA);

    /* Enable the SPI module. */
    SPI_Enable(base, config->enableMaster);
    return kStatus_Success;
}

/*!
 * brief  Sets the SPI slave configuration structure to default values.
 *
 * The purpose of this API is to get the configuration structure initialized for use in SPI_SlaveInit().
 * Modify some fields of the structure before calling SPI_SlaveInit().
 * Example:
   code
   spi_slave_config_t config;
   SPI_SlaveGetDefaultConfig(&config);
   endcode
 *
 * param config pointer to slave configuration structure
 */
void SPI_SlaveGetDefaultConfig(spi_slave_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableSlave                = true;
    config->polarity                   = kSPI_ClockPolarityActiveHigh;
    config->phase                      = kSPI_ClockPhaseFirstEdge;
    config->direction                  = kSPI_MsbFirst;
    config->dataWidth                  = kSPI_Data8Bits;
    config->sselPol                    = kSPI_SpolActiveAllLow;
    config->fifoConfig.enableRxFifo    = false;
    config->fifoConfig.enableTxFifo    = false;
    config->fifoConfig.rxFifoSize      = 0U;
    config->fifoConfig.txFifoSize      = 0U;
    config->fifoConfig.rxFifoThreshold = 0U;
    config->fifoConfig.txFifoThreshold = 0U;
}

/*!
 * brief Initializes the SPI with slave configuration.
 *
 * The configuration structure can be filled by user from scratch or be set with
 * default values by SPI_SlaveGetDefaultConfig().
 * After calling this API, the slave is ready to transfer.
 * Example
   code
    spi_slave_config_t config = {
    .polarity = kSPI_ClockPolarityActiveHigh;
    .phase = kSPI_ClockPhaseFirstEdge;
    .direction = kSPI_MsbFirst;
    ...
    };
    SPI_SlaveInit(SPI0, &config);
   endcode
 *
 * param base SPI base pointer
 * param config pointer to slave configuration structure
 */
status_t SPI_SlaveInit(SPI_Type *base, const spi_slave_config_t *config)
{
    uint32_t instance = 0U;
    uint32_t tmp      = 0U;

    /* assert params */
    assert(!((NULL == base) || (NULL == config)));

    /* Get the instance of SPI. */
    instance = SPI_GetInstance(base);

    /* Config FIFOs if the system FIFO is enabled. */
    if ((config->fifoConfig.enableRxFifo) || (config->fifoConfig.enableTxFifo))
    {
        SPI_EnableFifo(base, &(config->fifoConfig));
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_spiClock[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
    /* Reset the module. */
    RESET_PeripheralReset(s_spiReset[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

    /* configure SPI mode */
    tmp &= ~(SPI_CFG_MASTER_MASK | SPI_CFG_LSBF_MASK | SPI_CFG_CPHA_MASK | SPI_CFG_CPOL_MASK | SPI_CFG_ENABLE_MASK |
             SPI_SSELPOL_MASK);
    /* Configure clock phase, clock polarity, shift direction and active level for SSEL pin. */
    tmp |= SPI_CFG_CPHA(config->phase) | SPI_CFG_CPOL(config->polarity) | SPI_CFG_LSBF(config->direction) |
           ((uint32_t)config->sselPol & (SPI_SSELPOL_MASK));
    /* Write configuration to register. */
    base->CFG = tmp;

    /* store configuration */
    g_configs[instance].dataWidth = config->dataWidth;

    SPI_SetDummyData(base, (uint8_t)SPI_DUMMYDATA);

    /* Enable the SPI module. */
    SPI_Enable(base, config->enableSlave);
    return kStatus_Success;
}

/*!
 * brief De-initializes the SPI.
 *
 * Calling this API resets the SPI module, gates the SPI clock.
 * Disable the fifo if enabled.
 * The SPI module can't work unless calling the SPI_MasterInit/SPI_SlaveInit to initialize module.
 *
 * param base SPI base pointer
 */
void SPI_Deinit(SPI_Type *base)
{
    /* Assert arguments */
    assert(NULL != base);
    uint32_t instance = SPI_GetInstance(base);

    /* Disable FIFO if enabled. */
    if ((SPI_IsTxFifoEnabled(base)) || (SPI_IsTxFifoEnabled(base)))
    {
        SPI_DisableFifo(base);
    }

    /* Disable SPI module before shutting down the clock. */
    SPI_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_spiClock[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets the baud rate for SPI transfer. This is only used in master.
 *
 * param base SPI base pointer
 * param baudrate_Bps baud rate needed in Hz.
 * param srcClock_Hz SPI source clock frequency in Hz.
 */
status_t SPI_MasterSetBaud(SPI_Type *base, uint32_t baudrate_Bps, uint32_t srcClock_Hz)
{
    uint32_t tmp;

    /* assert params */
    assert(!((NULL == base) || (0U == baudrate_Bps) || (0U == srcClock_Hz)));

    /* calculate baudrate */
    tmp = (srcClock_Hz / baudrate_Bps) - 1U;
    if (tmp > 0xFFFFU)
    {
        return kStatus_SPI_BaudrateNotSupport;
    }
    base->DIV &= ~SPI_DIV_DIVVAL_MASK;
    base->DIV |= SPI_DIV_DIVVAL(tmp);
    return kStatus_Success;
}

/*!
 * brief Writes a data into the SPI data register.
 *
 * param base SPI base pointer
 * param data needs to be write.
 * param configFlags transfer configuration options ref spi_xfer_option_t
 */
void SPI_WriteData(SPI_Type *base, uint16_t data, uint32_t configFlags)
{
    uint32_t control = 0;
    uint32_t instance;

    /* check params */
    assert(NULL != base);
    /* get and check instance */
    instance = SPI_GetInstance(base);

    /* Set data width */
    control |= SPI_TXDATCTL_LEN(g_configs[instance].dataWidth);
    /* Set sssel */
    control |= (SPI_DEASSERT_ALL & (~SPI_DEASSERT_SSELNUM((uint32_t)g_configs[instance].sselNum)));
    /* Mask configFlags */
    control |= (configFlags & (SPI_TXDATCTL_EOT_MASK | SPI_TXDATCTL_EOF_MASK | SPI_TXDATCTL_RXIGNORE_MASK));
    /* Control should not affect lower 16 bits */
    assert((control & 0xFFFFU) == 0U);

    if (SPI_IsTxFifoEnabled(base))
    {
        VFIFO->SPI[instance].TXDATSPI = data | control;
    }
    else
    {
        base->TXDATCTL = (data | control);
    }
}

/*!
 * brief Gets a data from the SPI data register.
 *
 * param base SPI base pointer
 * return Data in the register.
 */
uint32_t SPI_ReadData(SPI_Type *base)
{
    assert(NULL != base);
    uint32_t data;
    uint32_t instance = SPI_GetInstance(base);

    if (SPI_IsRxFifoEnabled(base))
    {
        data = (VFIFO->SPI[instance].RXDATSPI);
    }
    else
    {
        data = (base->RXDAT & 0x0000FFFFU);
    }
    return data;
}
/*!
 * brief Initializes the SPI master handle.
 *
 * This function initializes the SPI master handle which can be used for other SPI master transactional APIs. Usually,
 * for a specified SPI instance, call this API once to get the initialized handle.
 *
 * param base SPI peripheral base address.
 * param handle SPI handle pointer.
 * param callback Callback function.
 * param userData User data.
 */
status_t SPI_MasterTransferCreateHandle(SPI_Type *base,
                                        spi_master_handle_t *handle,
                                        spi_master_callback_t callback,
                                        void *userData)
{
    uint32_t instance = 0;

    /* check 'base' */
    assert(!(NULL == base));
    /* check 'handle' */
    assert(!(NULL == handle));
    /* Get SPI instance by 'base' param */
    instance = SPI_GetInstance(base);

    (void)memset(handle, 0, sizeof(*handle));

    handle->dataWidth = (uint8_t)g_configs[instance].dataWidth;
    /* in slave mode, the sselNum is not important */
    handle->sselNum         = (uint8_t)g_configs[instance].sselNum;
    handle->isRxFifoEnabled = SPI_IsRxFifoEnabled(base);
    handle->isTxFifoEnabled = SPI_IsTxFifoEnabled(base);
    if (handle->isRxFifoEnabled)
    {
        handle->rxFifoThreshold = (uint8_t)SPI_FIFO_GETRXTHRESHOLD(base);
        handle->rxFIFOSize =
            (uint8_t)((VFIFO->FIFOCFGSPI[instance] & VFIFO_FIFOCFGSPI_RXSIZE_MASK) >> VFIFO_FIFOCFGSPI_RXSIZE_SHIFT);
    }
    if (handle->isTxFifoEnabled)
    {
        handle->txFifoThreshold = (uint8_t)SPI_FIFO_GETTXTHRESHOLD(base);
    }

    handle->callback = callback;
    handle->userData = userData;

    s_spiHandle[instance] = handle;
    s_spiMasterIsr        = SPI_MasterTransferHandleIRQ;
    /* Enable SPI NVIC */
    (void)EnableIRQ(s_spiIRQ[instance]);

    return kStatus_Success;
}

/*!
 * brief Initializes the SPI slave handle.
 *
 * This function initializes the SPI slave handle which can be used for other SPI slave transactional APIs. Usually,
 * for a specified SPI instance, call this API once to get the initialized handle.
 *
 * param base SPI peripheral base address.
 * param handle SPI handle pointer.
 * param callback Callback function.
 * param userData User data.
 */
status_t SPI_SlaveTransferCreateHandle(SPI_Type *base,
                                       spi_slave_handle_t *handle,
                                       spi_slave_callback_t callback,
                                       void *userData)
{
    (void)SPI_MasterTransferCreateHandle(base, handle, callback, userData);
    s_spiSlaveIsr = SPI_SlaveTransferHandleIRQ;
    return kStatus_Success;
}

/*!
 * brief Transfers a block of data using a polling method.
 *
 * param base SPI base pointer
 * param xfer pointer to spi_xfer_config_t structure
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Timeout The transfer timed out and was aborted.
 */
status_t SPI_MasterTransferBlocking(SPI_Type *base, spi_transfer_t *xfer)
{
    /* Check params */
    assert(!((NULL == base) || (NULL == xfer) || ((NULL == xfer->txData) && (NULL == xfer->rxData))));

    uint32_t instance = SPI_GetInstance(base);
    uint32_t tx_ctrl = 0, last_ctrl = 0;
    uint32_t tmp32 = 0, dataWidth = 0, dummyData = 0;
    uint32_t txRemainingBytes = 0, rxRemainingBytes = 0, rxFIFOSize = 0, txFIFOSize = 0;
#if SPI_RETRY_TIMES
    uint32_t waitTimes;
#endif

    /* Check if the FIFO is used. */
    bool isTxFifoEnabled = SPI_IsTxFifoEnabled(base);

    if ((xfer->rxData == NULL) || ((xfer->configFlags & (uint32_t)SPI_TXDATCTL_RXIGNORE_MASK) != 0U))
    {
        rxRemainingBytes = 0U;
        last_ctrl |= SPI_TXDATCTL_RXIGNORE_MASK;
    }
    else
    {
        rxRemainingBytes = xfer->dataSize;
    }
    txRemainingBytes = xfer->dataSize;
    rxFIFOSize       = ((VFIFO->SPI->STATSPI & VFIFO_SPI_STATSPI_RXCOUNT_MASK) >> VFIFO_SPI_STATSPI_RXCOUNT_SHIFT);
    txFIFOSize       = ((VFIFO->SPI->STATSPI & VFIFO_SPI_STATSPI_TXCOUNT_MASK) >> VFIFO_SPI_STATSPI_TXCOUNT_SHIFT);
    dataWidth        = (uint32_t)g_configs[instance].dataWidth;
    dummyData        = (uint32_t)s_dummyData[instance];
    dummyData |= ((uint32_t)s_dummyData[instance] << 8U);

    /* Set the configuration of last command. */
    last_ctrl |= ((uint32_t)SPI_DEASSERT_ALL & (~SPI_DEASSERT_SSELNUM((uint32_t)g_configs[instance].sselNum))) |
                 SPI_TXDATCTL_LEN(dataWidth) | (xfer->configFlags);

    /* Set the configuration of command, no need to set EOT bit. */
    tx_ctrl = last_ctrl & (~SPI_TXDATCTL_EOT_MASK);

    /* Due to the SPI is duplex transfer, to take full advantage of VFIFO, it is better
     * to make the RX FIFO equals to TX FIFO, so only check tx FIFO here.
     */
    if (isTxFifoEnabled)
    {
        /* Index of loop */
        while ((txRemainingBytes != 0U) || (rxRemainingBytes != 0U))
        {
            tmp32 = 0U;
            /* If the FIFO is not full and still has data to be written. */
#if SPI_RETRY_TIMES
            waitTimes = SPI_RETRY_TIMES;
            while (((VFIFO->SPI[instance].STATSPI & VFIFO_SPI_STATSPI_TXCOUNT_MASK) != 0U) &&
                   (txRemainingBytes != 0U) && (--waitTimes != 0U))
#else
            while (((VFIFO->SPI[instance].STATSPI & VFIFO_SPI_STATSPI_TXCOUNT_MASK) != 0U) && (txRemainingBytes != 0U))
#endif
            {
                if (xfer->txData != NULL)
                {
                    tmp32 = *(xfer->txData++);
                    if (dataWidth > 7U)
                    {
                        tmp32 |= ((uint32_t)(*(xfer->txData++))) << 8U;
                    }
                }
                else
                {
                    tmp32 = dummyData;
                }

                /* Count TX remaining bytes. */
                txRemainingBytes--;
                if (dataWidth > 7U)
                {
                    txRemainingBytes--;
                }

                /* Write data to TX register. */
                if (txRemainingBytes == 0U)
                {
                    VFIFO->SPI[instance].TXDATSPI = (tmp32 | last_ctrl);
                }
                else
                {
                    VFIFO->SPI[instance].TXDATSPI = (tmp32 | tx_ctrl);
                }

                /* Ensure the receive FIFO will not overflow. */
                if (rxRemainingBytes - txRemainingBytes == rxFIFOSize)
                {
                    break;
                }
            }
#if SPI_RETRY_TIMES
            if (waitTimes == 0U)
            {
                return kStatus_SPI_Timeout;
            }
#endif

            /* Read data from the receive register. */
#if SPI_RETRY_TIMES
            waitTimes = SPI_RETRY_TIMES;
            while (((VFIFO->SPI[instance].STATSPI & VFIFO_SPI_STATSPI_RXCOUNT_MASK) != 0U) &&
                   (rxRemainingBytes != 0U) && (--waitTimes != 0U))
#else
            while (((VFIFO->SPI[instance].STATSPI & VFIFO_SPI_STATSPI_RXCOUNT_MASK) != 0U) && (rxRemainingBytes != 0U))
#endif
            {
                tmp32 = VFIFO->SPI[instance].RXDATSPI;
                /* If receive buffer is NULL. */
                if (xfer->rxData != NULL)
                {
                    *(xfer->rxData++) = (uint8_t)tmp32;
                    rxRemainingBytes--;
                    if (dataWidth > 7U)
                    {
                        *(xfer->rxData++) = (uint8_t)(tmp32 >> 8U);
                        rxRemainingBytes--;
                    }
                }
            }
#if SPI_RETRY_TIMES
            if (waitTimes == 0U)
            {
                return kStatus_SPI_Timeout;
            }
#endif
        }

        /* Waiting for the data in FIFO is all sent out. */
#if SPI_RETRY_TIMES
        waitTimes = SPI_RETRY_TIMES;
        while ((!(txFIFOSize ==
                  ((VFIFO->SPI->STATSPI & VFIFO_SPI_STATSPI_TXCOUNT_MASK) >> VFIFO_SPI_STATSPI_TXCOUNT_SHIFT))) &&
               (--waitTimes != 0U))
#else
        while (!(txFIFOSize ==
                 ((VFIFO->SPI->STATSPI & VFIFO_SPI_STATSPI_TXCOUNT_MASK) >> VFIFO_SPI_STATSPI_TXCOUNT_SHIFT)))
#endif
        {
        }

#if SPI_RETRY_TIMES
        if (waitTimes == 0U)
        {
            return kStatus_SPI_Timeout;
        }
#endif
    }
    else
    {
        /* Write the TX control command first. */
        base->TXCTL = tx_ctrl;

        /* Index of loop */
        while (txRemainingBytes != 0U)
        {
            tmp32 = 0U;
            /* Wait for Transmit is ready. */
#if SPI_RETRY_TIMES
            waitTimes = SPI_RETRY_TIMES;
            while (((base->STAT & SPI_STAT_TXRDY_MASK) == 0U) && (--waitTimes != 0U))
#else
            while ((base->STAT & SPI_STAT_TXRDY_MASK) == 0U)
#endif
            {
            }

#if SPI_RETRY_TIMES
            if (waitTimes == 0U)
            {
                return kStatus_SPI_Timeout;
            }
#endif

            /* If txdata is not NULL. */
            if (xfer->txData != NULL)
            {
                tmp32 = *(xfer->txData++);
                if (dataWidth > 7U)
                {
                    tmp32 |= ((uint32_t)(*(xfer->txData++))) << 8U;
                }
            }
            else
            {
                tmp32 = dummyData;
            }

            /* Count the TX remaining bytes. */
            txRemainingBytes--;
            if (dataWidth > 7U)
            {
                txRemainingBytes--;
            }

            /* Write data to the register. */
            if (txRemainingBytes == 0U)
            {
                base->TXDATCTL = (tmp32 | last_ctrl);
            }
            else
            {
                base->TXDAT = tmp32;
            }

            /* If the receive ignore feature is not used, read the data from register. */
            if (0U == (tx_ctrl & SPI_TXDATCTL_RXIGNORE_MASK))
            {
                /* If RX register is ready. */
#if SPI_RETRY_TIMES
                waitTimes = SPI_RETRY_TIMES;
                while (((base->STAT & SPI_STAT_RXRDY_MASK) == 0U) && (--waitTimes != 0U))
#else
                while ((base->STAT & SPI_STAT_RXRDY_MASK) == 0U)
#endif
                {
                }

#if SPI_RETRY_TIMES
                if (waitTimes == 0U)
                {
                    return kStatus_SPI_Timeout;
                }
#endif

                tmp32 = base->RXDAT;

                /* If receive buffer is not NULL. */
                if (xfer->rxData != NULL)
                {
                    *(xfer->rxData++) = (uint8_t)tmp32;
                    if (dataWidth > 7U)
                    {
                        *(xfer->rxData++) = (uint8_t)(tmp32 >> 8U);
                    }
                }
            }
        }
    }

    /* Note that: the MSTIDLE status is related to the EOT bit, if the EOT is not set, the MSTIDLE bit will never be set
     * even though there is no data in the FIFO and no data will be shifted by the bus line. so, please don't check the
     * MSTIDLE status if the EOT bit is not set.
     */
    if ((xfer->configFlags & (uint32_t)kSPI_FrameAssert) != 0U)
    {
#if SPI_RETRY_TIMES
        waitTimes = SPI_RETRY_TIMES;
        while (((base->STAT & SPI_STAT_MSTIDLE_MASK) == 0U) && (--waitTimes != 0U))
#else
        while ((base->STAT & SPI_STAT_MSTIDLE_MASK) == 0U)
#endif
        {
        }

#if SPI_RETRY_TIMES
        if (waitTimes == 0U)
        {
            return kStatus_SPI_Timeout;
        }
#endif
    }
    return kStatus_Success;
}

/*!
 * brief Performs a non-blocking SPI interrupt transfer.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_master_handle_t structure which stores the transfer state
 * param xfer pointer to spi_xfer_config_t structure
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_MasterTransferNonBlocking(SPI_Type *base, spi_master_handle_t *handle, spi_transfer_t *xfer)
{
    /* check params */
    assert(
        !((NULL == base) || (NULL == handle) || (NULL == xfer) || ((NULL == xfer->txData) && (NULL == xfer->rxData))));

    uint32_t instance = SPI_GetInstance(base);
    /* dataSize (in bytes) is not aligned to 16bit (2B) transfer */
    if ((handle->dataWidth > (uint8_t)kSPI_Data8Bits) && ((xfer->dataSize & 0x1U) != 0U))
    {
        return kStatus_InvalidArgument;
    }

    /* Check if SPI is busy */
    if (handle->state == (uint32_t)kStatus_SPI_Busy)
    {
        return kStatus_SPI_Busy;
    }

    /* Clear commom command and last command. */
    handle->commonCommand = 0U;
    handle->lastCommand   = 0U;
    /* Set the handle information */
    handle->txData = xfer->txData;
    handle->rxData = xfer->rxData;
    /* Set count */
    handle->txRemainingBytes = xfer->dataSize;
    /* If the receive data buffer is NULL or receive ignore feature is selected. */
    if ((xfer->rxData == NULL) || ((xfer->configFlags & SPI_TXDATCTL_RXIGNORE_MASK) != 0U))
    {
        handle->rxRemainingBytes = 0U;
        handle->lastCommand |= SPI_TXDATCTL_RXIGNORE_MASK;
    }
    else
    {
        handle->rxRemainingBytes = xfer->dataSize;
    }
    handle->totalByteCount = xfer->dataSize;

    /* Set the last command according to the configuration. */
    handle->lastCommand |=
        ((uint32_t)SPI_DEASSERT_ALL & (~SPI_DEASSERT_SSELNUM((uint32_t)g_configs[instance].sselNum))) |
        SPI_TXDATCTL_LEN(handle->dataWidth) | xfer->configFlags;
    /* Common command no need to set the EOT bit. */
    handle->commonCommand = (handle->lastCommand & ~SPI_TXDATCTL_EOT_MASK);

    /* Set the SPI state to busy */
    handle->state = (uint32_t)kStatus_SPI_Busy;

    /* FIFO options. */
    if (SPI_IsTxFifoEnabled(base))
    {
        SPI_EnableFifoInterrupts(base, (uint32_t)kSPI_TxFifoThresholdInterruptEnable);
    }
    else
    {
        /* Enable generating txIRQ, first transfer is fired by TX ready interrupt. */
        SPI_EnableInterrupts(base, (uint32_t)kSPI_TxReadyInterruptEnable);
    }
    if (SPI_IsRxFifoEnabled(base))
    {
        SPI_EnableFifoInterrupts(base, (uint32_t)kSPI_RxFifoThresholdInterruptEnable);
    }
    else
    {
        /* Enable generating rxIRQ. */
        SPI_EnableInterrupts(base, (uint32_t)kSPI_RxReadyInterruptEnable);
    }
    return kStatus_Success;
}

/*!
 * brief Transfers a block of data using a polling method.
 *
 * This function will do a half-duplex transfer for SPI master, This is a blocking function,
 * which does not retuen until all transfer have been completed. And data transfer will be half-duplex,
 * users can set transmit first or receive first.
 *
 * param base SPI base pointer
 * param xfer pointer to spi_half_duplex_transfer_t structure
 * return status of status_t.
 */
status_t SPI_MasterHalfDuplexTransferBlocking(SPI_Type *base, spi_half_duplex_transfer_t *xfer)
{
    assert(xfer != NULL);

    spi_transfer_t tempXfer = {0};
    status_t status;

    if (xfer->isTransmitFirst)
    {
        tempXfer.txData   = xfer->txData;
        tempXfer.rxData   = NULL;
        tempXfer.dataSize = xfer->txDataSize;
    }
    else
    {
        tempXfer.txData   = NULL;
        tempXfer.rxData   = xfer->rxData;
        tempXfer.dataSize = xfer->rxDataSize;
    }
    /* If the pcs pin keep assert between transmit and receive. */
    if (xfer->isPcsAssertInTransfer)
    {
        tempXfer.configFlags = (xfer->configFlags) & (~(uint32_t)kSPI_FrameAssert);
    }
    else
    {
        tempXfer.configFlags = (xfer->configFlags) | (uint32_t)kSPI_FrameAssert;
    }

    status = SPI_MasterTransferBlocking(base, &tempXfer);

    if (status != kStatus_Success)
    {
        return status;
    }

    if (xfer->isTransmitFirst)
    {
        tempXfer.txData   = NULL;
        tempXfer.rxData   = xfer->rxData;
        tempXfer.dataSize = xfer->rxDataSize;
    }
    else
    {
        tempXfer.txData   = xfer->txData;
        tempXfer.rxData   = NULL;
        tempXfer.dataSize = xfer->txDataSize;
    }
    tempXfer.configFlags = xfer->configFlags;

    /* SPI transfer blocking. */
    status = SPI_MasterTransferBlocking(base, &tempXfer);

    return status;
}

/*!
 * brief Performs a non-blocking SPI interrupt transfer.
 *
 * This function using polling way to do the first half transimission and using interrupts to
 * do the srcond half transimission, the transfer mechanism is half-duplex.
 * When do the second half transimission, code will return right away. When all data is transferred,
 * the callback function is called.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_master_handle_t structure which stores the transfer state
 * param xfer pointer to spi_half_duplex_transfer_t structure
 * return status of status_t.
 */
status_t SPI_MasterHalfDuplexTransferNonBlocking(SPI_Type *base,
                                                 spi_master_handle_t *handle,
                                                 spi_half_duplex_transfer_t *xfer)
{
    assert(xfer != NULL);
    assert(handle != NULL);
    spi_transfer_t tempXfer = {0};
    status_t status;

    if (xfer->isTransmitFirst)
    {
        tempXfer.txData   = xfer->txData;
        tempXfer.rxData   = NULL;
        tempXfer.dataSize = xfer->txDataSize;
    }
    else
    {
        tempXfer.txData   = NULL;
        tempXfer.rxData   = xfer->rxData;
        tempXfer.dataSize = xfer->rxDataSize;
    }
    /* If the pcs pin keep assert between transmit and receive. */
    if (xfer->isPcsAssertInTransfer)
    {
        tempXfer.configFlags = (xfer->configFlags) & (~(uint32_t)kSPI_FrameAssert);
    }
    else
    {
        tempXfer.configFlags = (xfer->configFlags) | (uint32_t)kSPI_FrameAssert;
    }

    status = SPI_MasterTransferBlocking(base, &tempXfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (xfer->isTransmitFirst)
    {
        tempXfer.txData   = NULL;
        tempXfer.rxData   = xfer->rxData;
        tempXfer.dataSize = xfer->rxDataSize;
    }
    else
    {
        tempXfer.txData   = xfer->txData;
        tempXfer.rxData   = NULL;
        tempXfer.dataSize = xfer->txDataSize;
    }
    tempXfer.configFlags = xfer->configFlags;

    status = SPI_MasterTransferNonBlocking(base, handle, &tempXfer);

    return status;
}

/*!
 * brief Performs a non-blocking SPI slave interrupt transfer.
 *
 * note The API returns immediately after the transfer initialization is finished.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_master_handle_t structure which stores the transfer state
 * param xfer pointer to spi_xfer_config_t structure
 * retval kStatus_Success Successfully start a transfer.
 * retval kStatus_InvalidArgument Input argument is invalid.
 * retval kStatus_SPI_Busy SPI is not idle, is running another transfer.
 */
status_t SPI_SlaveTransferNonBlocking(SPI_Type *base, spi_slave_handle_t *handle, spi_transfer_t *xfer)
{
    status_t status;

    status = SPI_MasterTransferNonBlocking(base, handle, xfer);
    if (kStatus_Success != status)
    {
        return status;
    }
    s_spiSlaveIsr = SPI_SlaveTransferHandleIRQ;

    return kStatus_Success;
}
/*!
 * brief Gets the master transfer count.
 *
 * This function gets the master transfer count.
 *
 * param base SPI peripheral base address.
 * param handle Pointer to the spi_master_handle_t structure which stores the transfer state.
 * param count The number of bytes transferred by using the non-blocking transaction.
 * return status of status_t.
 */
status_t SPI_MasterTransferGetCount(SPI_Type *base, spi_master_handle_t *handle, size_t *count)
{
    assert(NULL != handle);

    if (NULL == count)
    {
        return kStatus_InvalidArgument;
    }

    /* Catch when there is not an active transfer. */
    if (handle->state != (uint32_t)kStatus_SPI_Busy)
    {
        *count = 0;
        return kStatus_NoTransferInProgress;
    }

    *count = handle->totalByteCount - handle->rxRemainingBytes;
    return kStatus_Success;
}

/*!
 * brief SPI master aborts a transfer using an interrupt.
 *
 * This function aborts a transfer using an interrupt.
 *
 * param base SPI peripheral base address.
 * param handle Pointer to the spi_master_handle_t structure which stores the transfer state.
 */
void SPI_MasterTransferAbort(SPI_Type *base, spi_master_handle_t *handle)
{
    assert(NULL != handle);

    /* Disable interrupt requests*/
    if (SPI_IsTxFifoEnabled(base))
    {
        SPI_DisableFifoInterrupts(base, (uint32_t)kSPI_TxFifoThresholdInterruptEnable);
    }
    else
    {
        SPI_DisableInterrupts(base, (uint32_t)kSPI_TxReadyInterruptEnable);
    }
    if (SPI_IsRxFifoEnabled(base))
    {
        SPI_DisableFifoInterrupts(base, (uint32_t)kSPI_RxFifoThresholdInterruptEnable);
    }
    else
    {
        SPI_DisableInterrupts(base, (uint32_t)kSPI_RxReadyInterruptEnable);
    }

    handle->state            = (uint32_t)kStatus_SPI_Idle;
    handle->txRemainingBytes = 0;
    handle->rxRemainingBytes = 0;
}

/*!
 * brief Interrupts the handler for the SPI.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_master_handle_t structure which stores the transfer state.
 */
void SPI_MasterTransferHandleIRQ(SPI_Type *base, spi_master_handle_t *handle)
{
    assert((NULL != base) && (NULL != handle));
    uint32_t instance = SPI_GetInstance(base);
    uint32_t tmprxRemainingBytes;

    /* IRQ behaviour:
     * - first interrupt is triggered by transmit ready interrupt or tx threshold reached if
     *   FIFO is enabled. The transfer function then tries read data and transmit data
     *   interleaved that results to strategy to process as many items as possible.
     * - last interrupt is triggered by receive data ready. The last state is
     *   known by empty rxBuffer and txBuffer. If there is nothing to receive
     *   or send - both operations have been finished and interrupts can be disabled.
     * - Note(case with the fifo used): Because the SPI0 and SPI1 share the same tx buffer and
     *   rx buffer, So the threshold interrupt may occurred but the data in the buffer
     *   for SPIx may not reach the threshold separately if SPI0 and SPI1 are receiving
     *   data at the same time. The similar issue may happen when SPI0 and SPI1 are sending
     *   data at the same time with the FIFO used.
     */

    /* Data to send or read or expected to receive */
    if (handle->rxRemainingBytes != 0U)
    {
        SPI_ReceiveTransfer(base, handle);
    }
    if (handle->txRemainingBytes != 0U)
    {
        SPI_SendTransfer(base, handle);
    }

    do
    {
        if ((0U == handle->txRemainingBytes) && (0U == handle->rxRemainingBytes))
        {
            /* Check Tx FIFO or SPI status to ensure callback is invoked after Tx data is totally sent out in
             * half-duplex transfer */
            if (SPI_IsTxFifoEnabled(base))
            {
                if (0U == (SPI_GetFifoStatusFlags(base) & (uint32_t)kSPI_TxFifoEmptyFlag))
                {
                    break;
                }
                SPI_DisableFifoInterrupts(base, (uint32_t)kSPI_TxFifoThresholdInterruptEnable);
            }
            else
            {
                if (0U == (SPI_GetStatusFlags(base) & (uint32_t)kSPI_TxReadyFlag))
                {
                    break;
                }
                SPI_DisableInterrupts(base, (uint32_t)kSPI_TxReadyInterruptEnable);
            }

            if (SPI_IsRxFifoEnabled(base))
            {
                SPI_EnableFifoInterrupts(base, (uint32_t)kSPI_RxFifoThresholdInterruptEnable);
            }
            else
            {
                /* Disable TX and RX interrupt. */
                SPI_DisableInterrupts(base, (uint32_t)kSPI_RxReadyInterruptEnable);
            }
            /* Set transfer state to idle. */
            handle->state = (uint32_t)kStatus_SPI_Idle;
            /* If callback is not NULL, call this function. */
            if (handle->callback != NULL)
            {
                (handle->callback)(base, handle, handle->state, handle->userData);
            }
        }
    } while (false);

    /* Check when the last receive, if the rx threshold can be triggered with the fifo enabled. */
    if (SPI_IsRxFifoEnabled(base))
    {
        /* If the bytes to receive is not larger then the rx threshold, the interrupt will not be triggerred.
         * So need to reload the rx threshold value to trigger the last receive.
         */
        if ((handle->rxRemainingBytes != 0U) && (handle->rxRemainingBytes <= handle->rxFifoThreshold))
        {
            tmprxRemainingBytes         = (uint32_t)(handle->rxRemainingBytes);
            VFIFO->SPI[instance].CFGSPI = ((VFIFO->SPI[instance].CFGSPI & ~VFIFO_SPI_CFGSPI_RXTHRESHOLD_MASK) |
                                           VFIFO_SPI_CFGSPI_RXTHRESHOLD(tmprxRemainingBytes - 1U));
        }
        /* If the rx threshold value in the register is not the default value in handle. Reload it to default value. */
        if ((handle->rxRemainingBytes == 0U) && (SPI_FIFO_GETRXTHRESHOLD(base) != handle->rxFifoThreshold))
        {
            VFIFO->SPI[instance].CFGSPI = ((VFIFO->SPI[instance].CFGSPI & ~VFIFO_SPI_CFGSPI_RXTHRESHOLD_MASK) |
                                           VFIFO_SPI_CFGSPI_RXTHRESHOLD(handle->rxFifoThreshold));
        }
    }
}

/*!
 * brief Interrupts a handler for the SPI slave.
 *
 * param base SPI peripheral base address.
 * param handle pointer to spi_slave_handle_t structure which stores the transfer state
 */
void SPI_SlaveTransferHandleIRQ(SPI_Type *base, spi_slave_handle_t *handle)
{
    assert((NULL != base) && (NULL != handle));
    uint32_t instance = SPI_GetInstance(base);
    uint32_t tmprxRemainingBytes;

    /* IRQ behaviour:
     * - first interrupt is triggered by transmit ready interrupt or tx threshold reached if
     *   FIFO is enabled. The transfer function then tries read data and transmit data
     *   interleaved that results to strategy to process as many items as possible.
     * - last interrupt is triggered by receive data ready. The last state is
     *   known by empty rxBuffer and txBuffer. If there is nothing to receive
     *   or send - both operations have been finished and interrupts can be disabled.
     * - Note(case with the fifo used): Because the SPI0 and SPI1 share the same tx buffer and
     *   rx buffer, So the threshold interrupt may occurred but the data in the buffer
     *   for SPIx may not reach the threshold separately if SPI0 and SPI1 are receiving
     *   data at the same time. The similar issue may happen when SPI0 and SPI1 are sending
     *   data at the same time with the FIFO used.
     */

    /* Data to send or read or expected to receive */
    if (handle->rxRemainingBytes != 0U)
    {
        SPI_ReceiveTransfer(base, handle);
    }
    if (handle->txRemainingBytes != 0U)
    {
        SPI_SendTransfer(base, handle);
    }

    do
    {
        if ((0U == handle->txRemainingBytes) && (0U == handle->rxRemainingBytes))
        {
            /* Check Tx FIFO or SPI status to ensure callback is invoked after Tx data is totally sent out in
             * half-duplex transfer */
            if (SPI_IsTxFifoEnabled(base))
            {
                if (0U == (SPI_GetFifoStatusFlags(base) & (uint32_t)kSPI_TxFifoEmptyFlag))
                {
                    break;
                }
                SPI_DisableFifoInterrupts(base, (uint32_t)kSPI_TxFifoThresholdInterruptEnable);
            }
            else
            {
                if (0U == (SPI_GetStatusFlags(base) & (uint32_t)kSPI_TxReadyFlag))
                {
                    break;
                }
                SPI_DisableInterrupts(base, (uint32_t)kSPI_TxReadyInterruptEnable);
            }

            if (SPI_IsRxFifoEnabled(base))
            {
                SPI_DisableFifoInterrupts(base, (uint32_t)kSPI_RxFifoThresholdInterruptEnable);
            }
            else
            {
                /* Disable TX and RX interrupt. */
                SPI_DisableInterrupts(base, (uint32_t)kSPI_RxReadyInterruptEnable);
            }
            /* Set transfer state to idle. */
            handle->state = (uint32_t)kStatus_SPI_Idle;
            /* If callback is not NULL, call this function. */
            if (handle->callback != NULL)
            {
                (handle->callback)(base, handle, handle->state, handle->userData);
            }
        }
    } while (false);

    /* Check when the last receive, if the rx threshold can be triggered with the fifo enabled. */
    if (SPI_IsRxFifoEnabled(base))
    {
        /* If the bytes to receive is not larger then the rx threshold, the interrupt will not be triggerred.
         * So need to reload the rx threshold value to trigger the last receive.
         */
        if ((handle->rxRemainingBytes != 0U) && (handle->rxRemainingBytes <= handle->rxFifoThreshold))
        {
            tmprxRemainingBytes         = (uint32_t)(handle->rxRemainingBytes);
            VFIFO->SPI[instance].CFGSPI = ((VFIFO->SPI[instance].CFGSPI & ~VFIFO_SPI_CFGSPI_RXTHRESHOLD_MASK) |
                                           VFIFO_SPI_CFGSPI_RXTHRESHOLD(tmprxRemainingBytes - 1U));
        }
        /* If the rx threshold value in the register is not the default value in handle. Reload it to default value. */
        if ((handle->rxRemainingBytes == 0U) && (SPI_FIFO_GETRXTHRESHOLD(base) != handle->rxFifoThreshold))
        {
            VFIFO->SPI[instance].CFGSPI = ((VFIFO->SPI[instance].CFGSPI & ~VFIFO_SPI_CFGSPI_RXTHRESHOLD_MASK) |
                                           VFIFO_SPI_CFGSPI_RXTHRESHOLD(handle->rxFifoThreshold));
        }
    }
}

static void SPI_CommonIRQHandler(SPI_Type *base, void *param)
{
    if (SPI_IsMaster(base))
    {
        s_spiMasterIsr(base, (spi_master_handle_t *)param);
    }
    else
    {
        s_spiSlaveIsr(base, (spi_slave_handle_t *)param);
    }
    SDK_ISR_EXIT_BARRIER;
}

#if defined(SPI0)
void SPI0_DriverIRQHandler(void);
void SPI0_DriverIRQHandler(void)
{
    assert(s_spiHandle[0] != NULL);
    SPI_CommonIRQHandler(SPI0, s_spiHandle[0]);
}
#endif

#if defined(SPI1)
void SPI1_DriverIRQHandler(void);
void SPI1_DriverIRQHandler(void)
{
    assert(s_spiHandle[1] != NULL);
    SPI_CommonIRQHandler(SPI1, s_spiHandle[1]);
}
#endif
