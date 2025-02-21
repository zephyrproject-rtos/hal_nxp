/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpuart.h"
#include "PN76_UtilsHelper.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_lpuart"
#endif

/* FIFO depth 8 bytes */
#define LPUART_FIFO_SIZE (8U)

#define PHHAL_HIFLPUART_HIF_SEL_MASK (0x00E00000UL)
#define PHHAL_HIFLPUART_HIF_SEL_POS  (21UL)

#define PHHAL_HIFLPUART_OSR_MASK (0x00020000UL)
#define PHHAL_HIFLPUART_OSR_POS  (17UL)

#define PHHAL_HIFLPUART_SBR_MASK (0x00010000UL)
#define PHHAL_HIFLPUART_SBR_POS  (16UL)

#define PHHAL_HIFLPUART_RTSWATER_MASK (0x0000C000UL)
#define PHHAL_HIFLPUART_RTSWATER_POS  (14UL)

#define PHHAL_HIFLPUART_TXCTSSRC_MASK (0x00002000UL)
#define PHHAL_HIFLPUART_TXCTSSRC_POS  (13UL)

#define PHHAL_HIFLPUART_TXCTSC_MASK (0x00001000UL)
#define PHHAL_HIFLPUART_TXCTSC_POS  (12UL)

#define PHHAL_HIFLPUART_RXRTSE_MASK (0x00000800UL)
#define PHHAL_HIFLPUART_RXRTSE_POS  (11UL)

#define PHHAL_HIFLPUART_TXRTSPOL_MASK (0x00000400UL)
#define PHHAL_HIFLPUART_TXRTSPOL_POS  (10UL)

#define PHHAL_HIFLPUART_TXRTSE_MASK (0x00000200UL)
#define PHHAL_HIFLPUART_TXRTSE_POS  (9UL)

#define PHHAL_HIFLPUART_TXCTSE_MASK (0x00000100UL)
#define PHHAL_HIFLPUART_TXCTSE_POS  (8UL)

#define PHHAL_HIFLPUART_CFG_RFU_MASK (0x000000C0UL)
#define PHHAL_HIFLPUART_CFG_RFU_POS  (6UL)

#define PHHAL_HIFLPUART_STOP_BITS_MASK (0x00000020UL)
#define PHHAL_HIFLPUART_STOP_BITS_POS  (5UL)

#define PHHAL_HIFLPUART_PAR_TYPE_MASK (0x00000010UL)
#define PHHAL_HIFLPUART_PAR_TYPE_POS  (4UL)

#define PHHAL_HIFLPUART_PAR_EN_MASK (0x00000008UL)
#define PHHAL_HIFLPUART_PAR_EN_POS  (3UL)

#define PHHAL_HIFLPUART_BAUDRATE_MASK (0x00000007UL)
#define PHHAL_HIFLPUART_BAUDRATE_POS  (0UL)

/* LPUART baud rate settings */
#define PHHAL_HIFLPUART_BAUD_SBR_MASK (0x1FFFUL)
#define PHHAL_HIFLPUART_BAUD_SBR_POS  (0UL)

#define PHHAL_HIFLPUART_BOTH_EDGE_MASK (0x2000UL)
#define PHHAL_HIFLPUART_BOTH_EDGE_POS  (13UL)

#define PHHAL_HIFLPUART_RFU_MASK (0xC000UL)
#define PHHAL_HIFLPUART_RFU_POS  (14UL)

#define PHHAL_HIFLPUART_BAUD_OSR_MASK (0x1F0000UL)
#define PHHAL_HIFLPUART_BAUD_OSR_POS  (16UL)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Supported uart clk src freq: is SYS CLK 90MHz. fallback is set to 90MHz.
 * Supported BRs:  9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600. Fallback is 115200UL.
 * Supported BRs (Hex): 0x2580, 0x4B00, 0x9600, 0xE100, 0x1C200, 0x38400, 0x70800, 0xE1000
 * */
static const uint32_t lpuartBaudRate[8] = {9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600};

static lpuart_data_t lpuartRx;
static lpuart_data_t lpuartTx;
static uint32_t isrTxLength;

/*******************************************************************************
 * Code
 ******************************************************************************/
static status_t LPUART_GetBRSettings(
    uint32_t srcClock_Hz, uint32_t baudRate_Bps, uint16_t *optionSbr, uint32_t *optionOsr, uint32_t *optionBothEdge)
{
    uint16_t sbr, sbrTemp;
    uint32_t osr, osrTemp, tempDiff, calculatedBaud, baudDiff;

    /* clear all, before setting actual values. */
    *optionSbr      = 0x0U;
    *optionOsr      = 0x0U;
    *optionBothEdge = 0x0U;

    /* This LPUART instantiation uses a slightly different baud rate calculation
     * The idea is to use the best OSR (over-sampling rate) possible
     * Note, OSR is typically hard-set to 16 in other LPUART instantiations
     * loop to find the best OSR value possible, one that generates minimum baudDiff
     * iterate through the rest of the supported values of OSR */

    baudDiff = baudRate_Bps;
    osr      = 0U;
    sbr      = 0U;
    for (osrTemp = 4U; osrTemp <= 32U; osrTemp++)
    {
        /* calculate the temporary sbr value   */
        sbrTemp = (uint16_t)(srcClock_Hz / (baudRate_Bps * osrTemp));
        /*set sbrTemp to 1 if the sourceClockInHz can not satisfy the desired baud rate*/
        if (sbrTemp == 0U)
        {
            sbrTemp = 1U;
        }
        /* Calculate the baud rate based on the temporary OSR and SBR values */
        calculatedBaud = (srcClock_Hz / (osrTemp * sbrTemp));

        tempDiff = calculatedBaud - baudRate_Bps;

        /* Select the better value between srb and (sbr + 1) */
        if (tempDiff > (baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1UL)))))
        {
            tempDiff = baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1UL)));
            sbrTemp++;
        }

        if (tempDiff <= baudDiff)
        {
            baudDiff = tempDiff;
            osr      = osrTemp; /* update and store the best OSR value calculated */
            sbr      = sbrTemp; /* update store the best SBR value calculated */
        }
    }

    /* Check to see if actual baud rate is within 3% of desired baud rate
     * based on the best calculate OSR value */
    if (baudDiff < ((baudRate_Bps / 100U) * 3U))
    {
        /* Acceptable baud rate, check if OSR is between 4x and 7x oversampling.
         * If so, then "BOTHEDGE" sampling must be turned on */
        if ((osr > 3U) && (osr < 8U))
        {
            *optionBothEdge = 1U;
        }

        /* program the osr value (bit value is one less than actual value) */
        *optionOsr = (osr - 1U);

        *optionSbr = sbr;
        return kStatus_Success;
    }
    else
    {
        /* Unacceptable baud rate difference of more than 3%*/
        return kStatus_InvalidArgument;
    }
}

/*!
 * brief Initializes an LPUART instance with the user configuration structure and the peripheral clock.
 *
 * This function configures the LPUART module with user-defined settings, see the @ref LPUART_CTRL_t.
 *
 * param base LPUART peripheral base address.
 * param lpuartConfig LPUART configuration pointer.
 * param sourceClock LPUART source clock frequency.
 * return kStatus_Success         LPUART initialize succeed
 */
status_t LPUART_Init(LPUART_Type *base, const lpuart_config_t *lpuartConfig, uint32_t sourceClock)
{
    uint32_t regValue;
    uint16_t optionSbr;
    uint32_t optionOsr;
    uint32_t optionBothEdge;
    uint8_t parType, parEnable, stopBit;
    status_t status;

    /* NOTE: Do not set both RXRTSE and TXRTSE */
    if ((lpuartConfig->b.RXRTSE == 1U) && (lpuartConfig->b.TXRTSE == 1U))
    {
        return kStatus_InvalidArgument;
    }

    /* Initialize UART clk */
    CLOCK_EnableClock(kCLOCK_Hostif);

    LPUART_SET_REG((uint32_t)&base->GLOBAL, LPUART_GLOBAL_RST_MASK);
    LPUART_SET_REG((uint32_t)&base->GLOBAL, 0x0U);

    /* Clear all status flags */
    regValue = LPUART_GET_REG((uint32_t)&base->STAT);
    regValue |= (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK);
    LPUART_SET_REG((uint32_t)&base->STAT, regValue);

    /* Deafult LPUART Configurations: Parity disabled. Even parity is used. 0- Even parity 1- Odd parity.
     * 1 stop bit. 0 -> 1 stop bit, 1 -> 2 stop bits
     * Receiver enable by default. DMA disabled. NO full duplex.
     *  */
    parEnable = (uint8_t)((lpuartConfig->dW & PHHAL_HIFLPUART_PAR_EN_MASK) >> PHHAL_HIFLPUART_PAR_EN_POS);
    parType   = (uint8_t)((lpuartConfig->dW & PHHAL_HIFLPUART_PAR_TYPE_MASK) >> PHHAL_HIFLPUART_PAR_TYPE_POS);
    stopBit   = (uint8_t)((lpuartConfig->dW & PHHAL_HIFLPUART_STOP_BITS_MASK) >> PHHAL_HIFLPUART_STOP_BITS_POS);

    /* Calculate the SBR & OSR settings based on baud rate selected. */
    status = LPUART_GetBRSettings(sourceClock, lpuartBaudRate[lpuartConfig->b.BaudRate], &optionSbr, &optionOsr,
                                  &optionBothEdge);

    if (kStatus_Success != status)
    {
        return status;
    }

    /* Map HW flow settings from lpuartConfig to LPUART_MODIR register settings. */
    regValue = (lpuartConfig->dW &
                 (PHHAL_HIFLPUART_TXCTSE_MASK | PHHAL_HIFLPUART_TXRTSE_MASK | PHHAL_HIFLPUART_TXRTSPOL_MASK |
                  PHHAL_HIFLPUART_RXRTSE_MASK | PHHAL_HIFLPUART_TXCTSC_MASK | PHHAL_HIFLPUART_TXCTSSRC_MASK)) >>
               8UL;
    regValue = regValue | (uint32_t)((lpuartConfig->dW & PHHAL_HIFLPUART_RTSWATER_MASK) >> 6UL);
    LPUART_SET_REG((uint32_t)&base->MODIR, regValue);

    /* Set parity, Idle settings & enable reception */
    LPUART_SET_REG((uint32_t)&base->CTRL, ((LPUART_CTRL_PT_MASK & ((uint32_t)parType << LPUART_CTRL_PT_SHIFT)) |
                                           (LPUART_CTRL_PE_MASK & ((uint32_t)parEnable << LPUART_CTRL_PE_SHIFT)) |
                                           (LPUART_CTRL_M_MASK & ((uint32_t)parEnable << LPUART_CTRL_M_SHIFT)) |
                                           LPUART_CTRL_RE_MASK | LPUART_CTRL_ILT_MASK | LPUART_CTRL_IDLECFG_MASK));

    /* LPUART BAUD settings */
    LPUART_SET_REG((uint32_t)&base->BAUD, ((LPUART_BAUD_SBR_MASK & ((uint32_t)optionSbr << LPUART_BAUD_SBR_SHIFT)) |
                                           (LPUART_BAUD_OSR_MASK & (optionOsr << LPUART_BAUD_OSR_SHIFT)) |
                                           (LPUART_BAUD_BOTHEDGE_MASK & (optionBothEdge << LPUART_BAUD_BOTHEDGE_SHIFT)) |
                                           (LPUART_BAUD_SBNS_MASK & ((uint32_t)stopBit << LPUART_BAUD_SBNS_SHIFT))));

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
    /* configure LPUART FIFO */
    LPUART_SET_REG((uint32_t)&base->FIFO,
                   (((uint32_t)LPUART_FIFO_RXFE_MASK) | ((uint32_t)LPUART_FIFO_TXFE_MASK) | ((uint32_t)LPUART_FIFO_RXIDEN_MASK) |
                    ((uint32_t)LPUART_FIFO_RXFLUSH_MASK) | ((uint32_t)LPUART_FIFO_TXFLUSH_MASK)));

    /* Set TX & RX water marks. */
    LPUART_SET_REG((uint32_t)&base->WATER,
                   ((LPUART_WATER_TXWATER_MASK & ((uint32_t)lpuartConfig->b.TxWaterMark << LPUART_WATER_TXWATER_SHIFT)) |
                    (LPUART_WATER_RXWATER_MASK & ((uint32_t)lpuartConfig->b.RxWaterMark << LPUART_WATER_RXWATER_SHIFT))));
#endif

    /* Wait for the settings to complete. */
    PN76_Common_Wait(50);

    /* Select the LPUART Host Interface */
    PN76_Sys_PCRM_HifSelect(E_PN76_PCRM_HIF_SEL_HSU);

    NVIC_ClearPendingIRQ(LPUART_RX_IRQn);
    NVIC_EnableIRQ(LPUART_RX_IRQn);

    NVIC_ClearPendingIRQ(LPUART_TX_IRQn);
    NVIC_EnableIRQ(LPUART_TX_IRQn);

    return kStatus_Success;
}

/*!
 * brief Deinitializes a LPUART instance.
 *
 * This function waits for transmit to complete, disables TX and RX, and disables the LPUART clock.
 *
 * param base LPUART peripheral base address.
 */
void LPUART_DeInit(LPUART_Type *base)
{
    uint32_t regValue;

    /* Clear all status flags */
    regValue = LPUART_GET_REG((uint32_t)&base->STAT);
    regValue |= (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK);
    LPUART_SET_REG((uint32_t)&base->STAT, regValue);

    /* Disable the module. */
    LPUART_SET_REG((uint32_t)&base->CTRL, 0U);

    /* Reset LPUART */
    LPUART_SET_REG((uint32_t)&base->GLOBAL, LPUART_GLOBAL_RST_MASK);
    LPUART_SET_REG((uint32_t)&base->GLOBAL, 0x0U);

    /* Clear NVIC related to LPUART. */
    NVIC_ClearPendingIRQ(LPUART_RX_IRQn);
    NVIC_DisableIRQ(LPUART_RX_IRQn);

    NVIC_ClearPendingIRQ(LPUART_TX_IRQn);
    NVIC_DisableIRQ(LPUART_TX_IRQn);

    /* Disable clock for the lpuart module. */
    PN76_Sys_PCRM_ClockDisable(E_PN76_PCRM_LP_UART_CLK);
}

/*!
 * brief Enable Lpuart Receive operation in interrupt mode with callback registered.
 *
 * This function is non-blocking call, clears error flags, enables reception with FIFO enabled in half duplex mode.
 *
 * param data Pointer to memory to store received Lpuart data.
 * param length Pointer to memory to store length of received Lpuart data.
 * param bufferSize Size of the Rx buffer Pointer. Data received beyond this size will lead to loss of data and
 * overflow error.
 * param rxCallBack Pointer to callback function on completion/error during Lpuart communication.
 * return kStatus_Success         LPUART receive succeed
 */
status_t LPUART_Receive(LPUART_Type *base, uint8_t *data, uint32_t bufferSize, lpuartCallBack rxCallBack)
{
    uint32_t regValue;

    if ((data == NULL) || (rxCallBack == NULL) || (bufferSize == 0U))
    {
        return kStatus_InvalidArgument;
    }

    lpuartRx.data       = data;
    lpuartRx.length     = 0;
    lpuartRx.callBack   = rxCallBack;
    lpuartRx.bufferSize = bufferSize;

    /* Supported only half duplex mode. Perform settings as per that. */
    /* Clear all status flags */
    regValue = LPUART_GET_REG((uint32_t)&base->STAT);
    regValue |= (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK);
    LPUART_SET_REG((uint32_t)&base->STAT, regValue);

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
    /* Flush FIFOs, clear underflow flags. */
    LPUART_SET_FIELD((uint32_t)&base->FIFO, (LPUART_FIFO_RXFLUSH_MASK | LPUART_FIFO_RXUF_MASK),
                     (LPUART_FIFO_RXFLUSH_MASK | LPUART_FIFO_RXUF_MASK));

    /* Enable RX relevant FIFO interrupts. */
    LPUART_SET_BITN((uint32_t)&base->FIFO, LPUART_FIFO_RXUFE_SHIFT);
#endif
    /* Enable Rx and interrupts. */
    LPUART_SET_FIELD((uint32_t)&base->CTRL,
                     (LPUART_CTRL_RE_MASK | LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK),
                     (LPUART_CTRL_RE_MASK | LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK));

    return kStatus_Success;
}

/*!
 * brief Perform Lpuart Transmit operation in interrupt mode with callback registered.
 *
 * This function is non-blocking call, clears error flags, enable FIFO, kisk start Transmit in half duplex mode.
 *
 * param data Pointer to memory to store received Lpuart data.
 * param length Pointer to memory to store length of received Lpuart data.
 * param bufferSize Size of the Rx buffer Pointer. Data received beyond this size will lead to loss of data and
 * overflow error.
 * param rxCallBack Pointer to callback function on completion/error during Lpuart communication.
 * return kStatus_InvalidArgument    Parameter error
 * return kStatus_Success            LPUART receive succeed
 */
status_t LPUART_Transmit(LPUART_Type *base, uint8_t *data, uint32_t length, lpuartCallBack txCallBack)
{
    uint32_t regValue;

    if ((data == NULL) || (txCallBack == NULL) || (length == 0U))
    {
        return kStatus_InvalidArgument;
    }

    lpuartTx.data       = data;
    lpuartTx.length     = length;
    lpuartTx.callBack   = txCallBack;
    lpuartTx.bufferSize = length;
    isrTxLength         = 0;

    /* Supported only half duplex mode. Perform settings as per that. */
    /* Clear all status flags */
    regValue = LPUART_GET_REG((uint32_t)&base->STAT);
    regValue |= (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK);
    LPUART_SET_REG((uint32_t)&base->STAT, regValue);

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
    /* Flush FIFOs, clear overflow flags. */
    LPUART_SET_FIELD((uint32_t)&base->FIFO, (LPUART_FIFO_TXFLUSH_MASK | LPUART_FIFO_TXOF_MASK),
                     (LPUART_FIFO_TXFLUSH_MASK | LPUART_FIFO_TXOF_MASK));

    /* Enable TX relevant FIFO interrupts. */
    LPUART_SET_BITN((uint32_t)&base->FIFO, LPUART_FIFO_TXOFE_SHIFT);
#endif

    /* Enable Transmission & its corresponding interrupts. */
    LPUART_SET_FIELD((uint32_t)&base->CTRL, (LPUART_CTRL_TE_MASK | LPUART_CTRL_TIE_MASK | LPUART_CTRL_TCIE_MASK),
                     (LPUART_CTRL_TE_MASK | LPUART_CTRL_TIE_MASK | LPUART_CTRL_TCIE_MASK));

    return kStatus_Success;
}

/*!
 * brief Enable Lpuart Receive operation in polling mode.
 *
 * This function is blocking call, clears error flags, enables reception with FIFO enabled in half duplex mode.
 *
 * param data Pointer to memory to store received Lpuart data.
 * param length Pointer to memory to store length of received Lpuart data.
 * return kStatus_Success         LPUART receive succeed
 */
status_t LPUART_PollReceive(LPUART_Type *base, uint8_t *data, uint32_t *length)
{
    uint32_t i, rxCount;
    volatile uint32_t statusValue;

    if ((data == NULL) || (length == NULL))
    {
        return kStatus_InvalidArgument;
    }

    *length = 0U;
    LPUART_EnableRx(base, true);

    /* Clear the previous idle status. */
    LPUART_SET_REG((uint32_t)&base->STAT, LPUART_STAT_IDLE_MASK);

    /* RAF is set when the receiver detects the beginning of a valid start bit */
    do
    {
        statusValue = LPUART_GET_REG((uint32_t)&base->STAT);
        if (0UL != (statusValue & (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK)))
        {
            /* Clear the error flags. */
            LPUART_SET_FIELD((uint32_t)&base->STAT,
                             (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK),
                             statusValue);
            LPUART_EnableRx(base, false);
            return kStatus_Fail;
        }
    } while ((statusValue & LPUART_STAT_RAF_MASK) != LPUART_STAT_RAF_MASK);

    /* IDLE is set when the LPUART receive line becomes idle */
    statusValue = LPUART_GET_REG((uint32_t)&base->STAT);
    while ((statusValue & LPUART_STAT_IDLE_MASK) != LPUART_STAT_IDLE_MASK)
    {
        statusValue = LPUART_GET_REG((uint32_t)&base->STAT);
        if (0UL != (statusValue & (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK)))
        {
            /* Clear the error flags. */
            LPUART_SET_FIELD((uint32_t)&base->STAT,
                             (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK),
                             statusValue);
            LPUART_EnableRx(base, false);
            return kStatus_Fail;
        }
        else if ((statusValue & LPUART_STAT_RDRF_MASK) == LPUART_STAT_RDRF_MASK)
        {
#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
            /* Number of bytes to be read from 8 bytes FIFO */
            rxCount = ((uint8_t)((LPUART_GET_REG((uint32_t)&base->WATER) & LPUART_WATER_RXCOUNT_MASK) >>
                                 LPUART_WATER_RXCOUNT_SHIFT));

            /* Check the RX Data */
            for (i = 0U; i < rxCount; i++)
            {
                data[*length] = (uint8_t)LPUART_GET_REG((uint32_t)&base->DATA);
                *length       = *length + 1U;
            }
#else
            data[*length] = (uint8_t)LPUART_GET_REG((uint32_t)&base->DATA);
            *length       = *length + 1U;
#endif
        }
        else
        {
            /* Empty for MISRA */
        }
    }

    LPUART_EnableRx(base, false);

    return kStatus_Success;
}

/*!
 * brief Enable Lpuart transmit operation in polling mode.
 *
 * This function is blocking call, clears error flags, enables transmission with FIFO enabled in half duplex mode.
 *
 * param data Pointer to memory to store received Lpuart data.
 * param length Pointer to memory to store length of received Lpuart data.
 * return kStatus_Success         LPUART transmit succeed
 */
status_t LPUART_PollTransmit(LPUART_Type *base, uint8_t *data, uint32_t length)
{
    uint32_t regValue, i;
    uint32_t txCount = 0U, count;

    if ((data == NULL) || (length == 0U))
    {
        return kStatus_InvalidArgument;
    }

    LPUART_EnableTx(base, true);

    while (txCount < length)
    {
        regValue = LPUART_GET_REG((uint32_t)&base->STAT);
        if ((regValue & LPUART_STAT_TDRE_MASK) == LPUART_STAT_TDRE_MASK)
        {
#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
            count = LPUART_FIFO_SIZE - ((LPUART_GET_REG((uint32_t)&base->WATER) & LPUART_WATER_TXCOUNT_MASK) >>
                                        LPUART_WATER_TXCOUNT_SHIFT);

            for (i = 0U; i < count; i++)
            {
                if (txCount >= length)
                {
                    break;
                }

                LPUART_SET_REG((uint32_t)&base->DATA, data[txCount]);
                txCount = txCount + 1U;
            }
#else
            LPUART_SET_REG((uint32_t)&base->DATA, data[txCount]);
            txCount = txCount + 1U;
#endif
        }
    }

    /* Wait for the transmission to complete. */
    while ((LPUART_GET_REG((uint32_t)&base->STAT) & LPUART_STAT_TC_MASK) != LPUART_STAT_TC_MASK)
    {
    }

    LPUART_EnableTx(base, false);

    return kStatus_Success;
}

/*!
 * brief Clears LPUART TX interrupt flags.
 *
 * param base LPUART peripheral base address.
 */
void LPUART_ClearTxFlagsInterrupts(LPUART_Type *base)
{
    uint32_t regValue;

    /* Clear all status flags */
    regValue = LPUART_GET_REG((uint32_t)&base->STAT);
    regValue |= (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK);
    LPUART_SET_REG((uint32_t)&base->STAT, regValue);

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
    /* Flush FIFOs, clear overflow flags. */
    LPUART_SET_FIELD((uint32_t)&base->FIFO, (LPUART_FIFO_TXFLUSH_MASK | LPUART_FIFO_TXOF_MASK),
                     (LPUART_FIFO_TXFLUSH_MASK | LPUART_FIFO_TXOF_MASK));

    /* Disable overflow interrupts. */
    LPUART_CLEAR_BITN((uint32_t)&base->FIFO, LPUART_FIFO_TXOFE_SHIFT);
#endif

    /* Disable Tx interrupts. */
    LPUART_SET_FIELD((uint32_t)&base->CTRL, (LPUART_CTRL_TIE_MASK | LPUART_CTRL_TCIE_MASK | LPUART_CTRL_ORIE_MASK),
                     0x0);
}

/*!
 * brief Clears LPUART RX interrupt flags.
 *
 * param base LPUART peripheral base address.
 */
void LPUART_ClearRxFlagsInterrupts(LPUART_Type *base)
{
    volatile uint32_t ReadData;

    /* Clear all status flags */
    ReadData = LPUART_GET_REG((uint32_t)&base->STAT);
    ReadData |= (LPUART_STAT_OR_MASK | LPUART_STAT_NF_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK);
    LPUART_SET_REG((uint32_t)&base->STAT, ReadData);

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
    /* Flush FIFOs, clear underflow flags. */
    LPUART_SET_FIELD((uint32_t)&base->FIFO, (LPUART_FIFO_RXFLUSH_MASK | LPUART_FIFO_RXUF_MASK),
                     (LPUART_FIFO_RXFLUSH_MASK | LPUART_FIFO_RXUF_MASK));

    /* Disable underflow interrupts. */
    LPUART_CLEAR_BITN((uint32_t)&base->FIFO, LPUART_FIFO_RXUFE_SHIFT);
#endif

    /* Disable rx interrupts. */
    LPUART_SET_FIELD((uint32_t)&base->CTRL, (LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK),
                     0x0);
}

void LPUART_TxHandleIRQ(LPUART_Type *base);
void LPUART_TxHandleIRQ(LPUART_Type *base)
{
    uint32_t isr_rd_data;
    uint32_t i, count;
    uint32_t enabledInt;

    enabledInt  = base->CTRL;
    isr_rd_data = base->STAT;

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
    /* OR can happen when unexpected data received seen during Tx operation. */
    if (0UL != (LPUART_GET_REG((uint32_t)&base->FIFO) & LPUART_FIFO_TXOF_MASK))
    {
        /* Clear overrun flag, otherwise the RX does not work. */
        base->FIFO |= 1UL << LPUART_FIFO_TXOF_SHIFT;
        LPUART_SET_BITN((uint32_t)&base->FIFO, LPUART_FIFO_TXOF_SHIFT);

        /* Disable Transmission & its corresponding interrupts. */
        LPUART_CLEAR_BITN((uint32_t)&base->FIFO, LPUART_FIFO_TXOF_SHIFT);

        LPUART_SET_FIELD((uint32_t)&base->CTRL, (LPUART_CTRL_TE_MASK | LPUART_CTRL_TIE_MASK | LPUART_CTRL_TCIE_MASK),
                         0x0U);

        /* Trigger callback. */
        if (lpuartTx.callBack != NULL)
        {
            lpuartTx.callBack(lpuartTx.data, lpuartTx.length, kStatus_Fail);
        }

        return;
    }
#endif

    /* Check the TC flag & remaining Tx bytes first.
     * This will ensure the TE is not disabled while transmitting the last 8 bytes. */
    if ((isrTxLength == (lpuartTx.length)) && (((isr_rd_data & LPUART_STAT_TC_MASK) == LPUART_STAT_TC_MASK)) \
            && ((enabledInt & LPUART_CTRL_TCIE_MASK) != 0UL))
    {
        /* Disable TX interuupts after completion. */
        LPUART_SET_FIELD((uint32_t)&base->CTRL, (LPUART_CTRL_TIE_MASK | LPUART_CTRL_TCIE_MASK), 0x0U);

        if (lpuartTx.callBack != NULL)
        {
            lpuartTx.callBack(lpuartTx.data, lpuartTx.length, kStatus_Success);
        }
    }

    if (((isr_rd_data & LPUART_STAT_TDRE_MASK) == LPUART_STAT_TDRE_MASK) && ((enabledInt & LPUART_CTRL_TIE_MASK) != 0UL))
    {
#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
        count = LPUART_FIFO_SIZE -
                ((LPUART_GET_REG((uint32_t)&base->WATER) & LPUART_WATER_TXCOUNT_MASK) >> LPUART_WATER_TXCOUNT_SHIFT);

        for (i = 0U; i < count; i++)
        {
            if (isrTxLength >= lpuartTx.length)
            {
                break;
            }

            LPUART_SET_REG((uint32_t)&base->DATA, lpuartTx.data[isrTxLength]);
            isrTxLength = isrTxLength + 1U;

        }
#else
        if (isrTxLength < (lpuartTx.length))
        {
            LPUART_SET_REG((uint32_t)&base->DATA, lpuartTx.data[isrTxLength]);
            isrTxLength = isrTxLength + 1U;
        }
#endif
    }
}

void LPUART_RxHandleIRQ(LPUART_Type *base);
void LPUART_RxHandleIRQ(LPUART_Type *base)
{
    uint32_t statusValue;
    uint32_t enabledInt;
    uint32_t i;
    uint32_t rxCount;

    enabledInt = base->CTRL;

    /* Read the status & Clear interrupts*/
    statusValue = LPUART_GET_REG((uint32_t)&base->STAT);
    LPUART_SET_REG((uint32_t)&base->STAT, (LPUART_STAT_IDLE_MASK | LPUART_STAT_OR_MASK | LPUART_STAT_FE_MASK |
                                           LPUART_STAT_PF_MASK | LPUART_STAT_NF_MASK) &
                                              statusValue);

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
    if (0UL != (LPUART_GET_REG((uint32_t)&base->FIFO) & LPUART_FIFO_RXUF_MASK))
    {
        /* Clear interrupts */
        LPUART_SET_BITN((uint32_t)&base->FIFO, LPUART_FIFO_RXUF_SHIFT);

        /* Disable rx interrupts. */
        LPUART_SET_FIELD((uint32_t)&base->CTRL, (LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK),
                         0x0U);

        if (lpuartRx.callBack != NULL)
        {
            lpuartRx.callBack(lpuartRx.data, lpuartRx.length, kStatus_Fail);
        }

        return;
    }
#endif

    if (0UL != ((LPUART_STAT_OR_MASK | LPUART_STAT_FE_MASK | LPUART_STAT_PF_MASK | LPUART_STAT_NF_MASK) & statusValue))
    {
        /* Disable rx interrupts. */
        LPUART_SET_FIELD((uint32_t)&base->CTRL, (LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK),
                         0x0U);

        if (lpuartRx.callBack != NULL)
        {
            lpuartRx.callBack(lpuartRx.data, lpuartRx.length, kStatus_Fail);
        }

        return;
    }

    /* Receive data register full flag */
    if (((statusValue & LPUART_STAT_RDRF_MASK) == LPUART_STAT_RDRF_MASK) && ((enabledInt & LPUART_CTRL_RIE_MASK) != 0U))
    {
        statusValue = statusValue & (~LPUART_STAT_RDRF_MASK);

#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
        /* Number of bytes to be read from 8 bytes FIFO */
        rxCount = ((uint8_t)((LPUART_GET_REG((uint32_t)&base->WATER) & LPUART_WATER_RXCOUNT_MASK) >>
                             LPUART_WATER_RXCOUNT_SHIFT));
        for (i = 0U; i < rxCount; i++)
#endif
        {
            lpuartRx.data[lpuartRx.length] = (uint8_t)LPUART_GET_REG((uint32_t)&base->DATA);
            lpuartRx.length                = (lpuartRx.length) + 1U;
            if (lpuartRx.length >= lpuartRx.bufferSize)
            {
                /* Rx Buffer overflows. */
                LPUART_SET_FIELD((uint32_t)&base->CTRL,
                                 (LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK), 0x0U);
                if (lpuartRx.callBack != NULL)
                {
                    lpuartRx.callBack(lpuartRx.data, lpuartRx.length, kStatus_OutOfRange);
                }
                return;
            }
        }
    }

    if (((statusValue & LPUART_STAT_IDLE_MASK) == LPUART_STAT_IDLE_MASK) && ((enabledInt & LPUART_CTRL_ILIE_MASK) != 0U))
    {
#if FSL_FEATURE_LPUART_MODULE_FIFO_SUPPORT
        /* Number of bytes to be read from 8 bytes FIFO */
        rxCount = ((LPUART_GET_REG((uint32_t)&base->WATER) & LPUART_WATER_RXCOUNT_MASK) >> LPUART_WATER_RXCOUNT_SHIFT);
        for (i = 0U; i < rxCount; i++)
        {
            lpuartRx.data[lpuartRx.length] = (uint8_t)LPUART_GET_REG((uint32_t)&base->DATA);
            lpuartRx.length                = (lpuartRx.length) + 1U;
            if (lpuartRx.length >= lpuartRx.bufferSize)
            {
                /* Rx Buffer overflows. */
                LPUART_SET_FIELD((uint32_t)&base->CTRL,
                                 (LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK), 0x0U);
                if (lpuartRx.callBack != NULL)
                {
                    lpuartRx.callBack(lpuartRx.data, lpuartRx.length, kStatus_OutOfRange);
                }
                return;
            }
        }
#endif

        if (0UL != lpuartRx.length)
        {
            /* Disable reception and its interrupts. */
            LPUART_SET_FIELD((uint32_t)&base->CTRL,
                             (LPUART_CTRL_RIE_MASK | LPUART_CTRL_ILIE_MASK | LPUART_CTRL_ORIE_MASK), 0x0U);

            if (lpuartRx.callBack != NULL)
            {
                lpuartRx.callBack(lpuartRx.data, lpuartRx.length, kStatus_Success);
            }
        }
    }
}

/*!
 * brief Enables LPUART interrupts according to a provided mask.
 *
 * This function enables the LPUART interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See the ref _lpuart_interrupt_enable.
 *
 * param base LPUART peripheral base address.
 * param mask The interrupts to enable. Logical OR of ref _lpuart_interrupt_enable.
 */
void LPUART_EnableInterrupts(LPUART_Type *base, uint32_t mask)
{
    /* Only consider the real interrupt enable bits. */
    mask &= (uint32_t)kLPUART_AllInterruptEnable;

    /* Check int enable bits in base->BAUD */
    uint32_t tempReg = base->BAUD;
#if defined(FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT
    tempReg |= ((mask << 8U) & LPUART_BAUD_LBKDIE_MASK);
    /* Clear bit 7 from mask */
    mask &= ~(uint32_t)kLPUART_LinBreakInterruptEnable;
#endif
    tempReg |= ((mask << 8U) & LPUART_BAUD_RXEDGIE_MASK);
    /* Clear bit 6 from mask */
    mask &= ~(uint32_t)kLPUART_RxActiveEdgeInterruptEnable;
    base->BAUD = tempReg;

#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
    /* Check int enable bits in base->FIFO */
    base->FIFO = (base->FIFO & ~(LPUART_FIFO_TXOF_MASK | LPUART_FIFO_RXUF_MASK)) |
                 (mask & (LPUART_FIFO_TXOFE_MASK | LPUART_FIFO_RXUFE_MASK));
    /* Clear bit 9 and bit 8 from mask */
    mask &= ~((uint32_t)kLPUART_TxFifoOverflowInterruptEnable | (uint32_t)kLPUART_RxFifoUnderflowInterruptEnable);
#endif

    /* Set int enable bits in base->CTRL */
    base->CTRL |= mask;
}

/*!
 * brief Disables  LPUART interrupts according to a provided mask.
 *
 * This function disables the LPUART interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See ref _lpuart_interrupt_enable.
 *
 * param base LPUART peripheral base address.
 * param mask The interrupts to disable. Logical OR of ref _lpuart_interrupt_enable.
 */
void LPUART_DisableInterrupts(LPUART_Type *base, uint32_t mask)
{
    /* Only consider the real interrupt enable bits. */
    mask &= (uint32_t)kLPUART_AllInterruptEnable;
    /* Check int enable bits in base->BAUD */
    uint32_t tempReg = base->BAUD;
#if defined(FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT
    tempReg &= ~((mask << 8U) & LPUART_BAUD_LBKDIE_MASK);
    /* Clear bit 7 from mask */
    mask &= ~(uint32_t)kLPUART_LinBreakInterruptEnable;
#endif
    tempReg &= ~((mask << 8U) & LPUART_BAUD_RXEDGIE_MASK);
    /* Clear bit 6 from mask */
    mask &= ~(uint32_t)kLPUART_RxActiveEdgeInterruptEnable;
    base->BAUD = tempReg;

#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
    /* Check int enable bits in base->FIFO */
    base->FIFO = (base->FIFO & ~(LPUART_FIFO_TXOF_MASK | LPUART_FIFO_RXUF_MASK)) &
                 ~(mask & (LPUART_FIFO_TXOFE_MASK | LPUART_FIFO_RXUFE_MASK));
    /* Clear bit 9 and bit 8 from mask */
    mask &= ~((uint32_t)kLPUART_TxFifoOverflowInterruptEnable | (uint32_t)kLPUART_RxFifoUnderflowInterruptEnable);
#endif

    /* Check int enable bits in base->CTRL */
    base->CTRL &= ~mask;
}

/*!
 * brief Gets LPUART status flags.
 *
 * This function gets all LPUART status flags. The flags are returned as the logical
 * OR value of the enumerators ref _lpuart_flags. To check for a specific status,
 * compare the return value with enumerators in the ref _lpuart_flags.
 *
 * param base LPUART peripheral base address.
 * return LPUART status flags which are ORed by the enumerators in the _lpuart_flags.
 */
uint32_t LPUART_GetStatusFlags(LPUART_Type *base)
{
    uint32_t temp;
    temp = base->STAT;
#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
    temp |= (base->FIFO &
             (LPUART_FIFO_TXEMPT_MASK | LPUART_FIFO_RXEMPT_MASK | LPUART_FIFO_TXOF_MASK | LPUART_FIFO_RXUF_MASK)) >>
            16U;
#endif
    /* Only keeps the status bits */
    temp &= (uint32_t)kLPUART_AllFlags;
    return temp;
}

/*
 * brief Register the RX callback.
 *
 * This function can be used to monitor the error status during DMA transfer, note that
 * in this case, the callback parameter data and length are invalid.
 *
 * param base LPUART peripheral base address.
 * param rxCallBack Callback to register.
 * retval kStatus_Success Register succeed.
 * retval kStatus_InvalidArgument Invalid parameter.
 */
status_t LPUART_RegisterRXCallBack(LPUART_Type *base, lpuartCallBack rxCallBack)
{
    status_t status;

    if (rxCallBack == NULL)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        lpuartRx.callBack   = rxCallBack;
        status = kStatus_Success;
    }

    return status;
}

/*
 * brief Register the TX callback.
 *
 * This function can be used to monitor the error status during DMA transfer.
 *
 * param base LPUART peripheral base address.
 * param txCallBack Callback to register.
 * retval kStatus_Success Register succeed.
 * retval kStatus_InvalidArgument Invalid parameter.
 */
status_t LPUART_RegisterTXCallBack(LPUART_Type *base, lpuartCallBack txCallBack)
{
    status_t status;

    if (txCallBack == NULL)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        lpuartTx.callBack   = txCallBack;
        status = kStatus_Success;
    }

    return status;
}

void LPUART_TX_DriverIRQHandler(void);
void LPUART_TX_DriverIRQHandler(void)
{
    LPUART_TxHandleIRQ(LPUART);

    SDK_ISR_EXIT_BARRIER;
}

void LPUART_RX_DriverIRQHandler(void);
void LPUART_RX_DriverIRQHandler(void)
{
    LPUART_RxHandleIRQ(LPUART);

    SDK_ISR_EXIT_BARRIER;
}
