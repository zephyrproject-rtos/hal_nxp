/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_lpsci.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpsci"
#endif

/* LPSCI transfer state. */
enum _lpsci_tansfer_state
{
    kLPSCI_TxIdle,         /*!< TX idle. */
    kLPSCI_TxBusy,         /*!< TX busy. */
    kLPSCI_RxIdle,         /*!< RX idle. */
    kLPSCI_RxBusy,         /*!< RX busy. */
    kLPSCI_RxFramingError, /* Rx framing error */
    kLPSCI_RxParityError   /* Rx parity error */
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Check whether the RX ring buffer is full.
 *
 * @parram handle LPSCI handle pointer.
 * @retval true  RX ring buffer is full.
 * @retval false RX ring buffer is not full.
 */
static bool LPSCI_TransferIsRxRingBufferFull(lpsci_handle_t *handle);

/*!
 * @brief Write to TX register using non-blocking method.
 *
 * This function writes data to the TX register directly, upper layer must make
 * sure the TX register is empty before calling this function.
 *
 * @note This function does not check whether all the data has been sent out to bus,
 * so before disable TX, check kLPSCI_TransmissionCompleteFlag to ensure the TX is
 * finished.
 *
 * @param base LPSCI peripheral base address.
 * @param data Start address of the data to write.
 * @param length Size of the buffer to be sent.
 */
static void LPSCI_WriteNonBlocking(UART0_Type *base, const uint8_t *data, size_t length);

/*!
 * @brief Read RX data register using blocking method.
 *
 * This function polls the RX register, waits for the RX register full
 * then read data from TX register.
 *
 * @param base LPSCI peripheral base address.
 * @param data Start address of the buffer to store the received data.
 * @param length Size of the buffer.
 */
static void LPSCI_ReadNonBlocking(UART0_Type *base, uint8_t *data, size_t length);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Array of LPSCI handle. */
void *s_lpsciHandle[FSL_FEATURE_SOC_LPSCI_COUNT];

/* Array of LPSCI peripheral base address. */
static UART0_Type *const s_lpsciBases[] = UART0_BASE_PTRS;

/* Array of LPSCI IRQ number. */
const IRQn_Type s_lpsciIRQ[] = UART0_RX_TX_IRQS;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Array of LPSCI clock name. */
static const clock_ip_name_t s_lpsciClock[] = UART0_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/* LPSCI ISR for transactional APIs. */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
lpsci_isr_t s_lpsciIsr = (lpsci_isr_t)DefaultISR;
#else
lpsci_isr_t s_lpsciIsr;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Get the LPSCI instance from peripheral base address.
 *
 * param base LPSCI peripheral base address.
 * return LPSCI instance.
 */
uint32_t LPSCI_GetInstance(UART0_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_lpsciBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_lpsciBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_lpsciBases));

    return instance;
}

/*!
 * brief Get the length of received data in RX ring buffer.
 *
 * userData handle LPSCI handle pointer.
 * return Length of received data in RX ring buffer.
 */
size_t LPSCI_TransferGetRxRingBufferLength(lpsci_handle_t *handle)
{
    assert(handle != NULL);

    size_t size;
    uint16_t tmprxRingBufferHead = handle->rxRingBufferHead;
    uint16_t tmprxRingBufferTail = handle->rxRingBufferTail;

    if (tmprxRingBufferTail > tmprxRingBufferHead)
    {
        size = (size_t)(tmprxRingBufferHead + (uint16_t)handle->rxRingBufferSize - tmprxRingBufferTail);
    }
    else
    {
        size = (size_t)(tmprxRingBufferHead - tmprxRingBufferTail);
    }

    return size;
}

static bool LPSCI_TransferIsRxRingBufferFull(lpsci_handle_t *handle)
{
    assert(handle != NULL);

    bool full;

    if (LPSCI_TransferGetRxRingBufferLength(handle) == (handle->rxRingBufferSize - 1U))
    {
        full = true;
    }
    else
    {
        full = false;
    }

    return full;
}

static void LPSCI_ReadNonBlocking(UART0_Type *base, uint8_t *data, size_t length)
{
    assert(data != NULL);

    /* The Non Blocking read data API assume user have ensured there is enough space in
    peripheral to write. */
    size_t i;

    for (i = 0; i < length; i++)
    {
        data[i] = base->D;
    }
}

static void LPSCI_WriteNonBlocking(UART0_Type *base, const uint8_t *data, size_t length)
{
    assert(data != NULL);

    /* The Non Blocking write data API assume user have ensured there is enough space in
    peripheral to write. */
    size_t i;

    for (i = 0; i < length; i++)
    {
        base->D = data[i];
    }
}

/*!
 * brief Initializes an LPSCI instance with the user configuration structure and the peripheral clock.
 *
 * This function configures the LPSCI module with user-defined settings. The user can configure the configuration
 * structure and can also get the default configuration by calling the LPSCI_GetDefaultConfig() function.
 * Example below shows how to use this API to configure the LPSCI.
 *  code
 *   lpsci_config_t lpsciConfig;
 *   lpsciConfig.baudRate_Bps = 115200U;
 *   lpsciConfig.parityMode = kLPSCI_ParityDisabled;
 *   lpsciConfig.stopBitCount = kLPSCI_OneStopBit;
 *   LPSCI_Init(UART0, &lpsciConfig, 20000000U);
 *   endcode
 *
 * param base LPSCI peripheral base address.
 * param config Pointer to user-defined configuration structure.
 * param srcClock_Hz LPSCI clock source frequency in HZ.
 * retval kStatus_LPSCI_BaudrateNotSupport Baudrate is not support in current clock source.
 * retval kStatus_Success LPSCI initialize succeed
 */
status_t LPSCI_Init(UART0_Type *base, const lpsci_config_t *config, uint32_t srcClock_Hz)
{
    assert(config != NULL);
    assert(config->baudRate_Bps != 0U);

    uint8_t temp;
    uint16_t sbr = 0;
    uint16_t sbrTemp;
    uint32_t osr = 0;
    uint32_t osrTemp;
    uint32_t tempDiff, calculatedBaud, baudDiff;

    /* This LPSCI instantiation uses a slightly different baud rate calculation
     * The idea is to use the best OSR (over-sampling rate) possible
     * Note, OSR is typically hard-set to 16 in other LPSCI instantiations
     * loop to find the best OSR value possible, one that generates minimum baudDiff
     * iterate through the rest of the supported values of OSR */

    baudDiff = config->baudRate_Bps;
    for (osrTemp = 4; osrTemp <= 32; osrTemp++)
    {
        /* calculate the temporary sbr value   */
        sbrTemp = (srcClock_Hz / (config->baudRate_Bps * osrTemp));
        /* set sbrTemp to 1 if the sourceClockInHz can not satisfy the desired baud rate */
        if (sbrTemp == 0)
        {
            sbrTemp = 1;
        }
        /* Calculate the baud rate based on the temporary OSR and SBR values */
        calculatedBaud = (srcClock_Hz / (osrTemp * sbrTemp));

        tempDiff = calculatedBaud - config->baudRate_Bps;

        /* Select the better value between srb and (sbr + 1) */
        if (tempDiff > (config->baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1)))))
        {
            tempDiff = config->baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1)));
            sbrTemp++;
        }

        if (tempDiff <= baudDiff)
        {
            baudDiff = tempDiff;
            osr      = osrTemp; /* update and store the best OSR value calculated*/
            sbr      = sbrTemp; /* update store the best SBR value calculated*/
        }
    }

    /* next, check to see if actual baud rate is within 3% of desired baud rate
     * based on the best calculate OSR value */
    if (baudDiff > ((config->baudRate_Bps / 100) * 3))
    {
        /* Unacceptable baud rate difference of more than 3%*/
        return kStatus_LPSCI_BaudrateNotSupport;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable LPSCI clock */
    CLOCK_EnableClock(s_lpsciClock[LPSCI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Disable TX RX before setting. */
    base->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);

    /* Acceptable baud rate */
    /* Check if OSR is between 4x and 7x oversampling*/
    /* If so, then "BOTHEDGE" sampling must be turned on*/
    if ((osr > 3) && (osr < 8))
    {
        base->C5 |= UART0_C5_BOTHEDGE_MASK;
    }

    /* program the osr value (bit value is one less than actual value)*/
    base->C4 = ((base->C4 & ~UART0_C4_OSR_MASK) | (osr - 1));

    /* program the sbr (divider) value obtained above*/
    base->BDH = ((base->C4 & ~UART0_BDH_SBR_MASK) | (uint8_t)(sbr >> 8));
    base->BDL = (uint8_t)sbr;

    /* set parity mode and idle line type*/
    temp = base->C1 & ~(UART0_C1_PE_MASK | UART0_C1_PT_MASK | UART0_C1_M_MASK | UART0_C1_ILT_MASK);

    temp |= UART0_C1_ILT(config->idleLineType);

    if (kLPSCI_ParityDisabled != config->parityMode)
    {
        temp |= (uint8_t)config->parityMode | UART0_C1_M_MASK;
    }

    base->C1 = temp;

#if defined(FSL_FEATURE_LPSCI_HAS_STOP_BIT_CONFIG_SUPPORT) && FSL_FEATURE_LPSCI_HAS_STOP_BIT_CONFIG_SUPPORT
    /* set stop bit per char */
    base->BDH &= ~UART0_BDH_SBNS_MASK;
    base->BDH |= UART0_BDH_SBNS((uint8_t)config->stopBitCount);
#endif

    /* Enable TX/RX base on configure structure. */
    temp = base->C2;

    if (config->enableTx)
    {
        temp |= UART0_C2_TE_MASK;
    }

    if (config->enableRx)
    {
        temp |= UART0_C2_RE_MASK;
    }

    base->C2 = temp;

    return kStatus_Success;
}

/*!
 * brief Deinitializes an LPSCI instance.
 *
 * This function waits for TX complete, disables TX and RX, and disables the LPSCI clock.
 *
 * param base LPSCI peripheral base address.
 */
void LPSCI_Deinit(UART0_Type *base)
{
    /* Wait last char out */
    while (0 == (base->S1 & UART0_S1_TC_MASK))
    {
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable LPSCI clock */
    CLOCK_DisableClock(s_lpsciClock[LPSCI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration structure and saves the configuration to a user-provided pointer.
 *
 * This function initializes the LPSCI configure structure to default value. the default
 * value are:
 *   lpsciConfig->baudRate_Bps = 115200U;
 *   lpsciConfig->parityMode = kLPSCI_ParityDisabled;
 *   lpsciConfig->stopBitCount = kLPSCI_OneStopBit;
 *   lpsciConfig->idleLineType = kLPSCI_IdleLineStartBit;
 *   lpsciConfig->enableTx = false;
 *   lpsciConfig->enableRx = false;
 *
 * param config Pointer to configuration structure.
 */
void LPSCI_GetDefaultConfig(lpsci_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->baudRate_Bps = 115200U;
    config->parityMode   = kLPSCI_ParityDisabled;
    config->stopBitCount = kLPSCI_OneStopBit;
    config->idleLineType = kLPSCI_IdleLineStartBit;
    config->enableTx     = false;
    config->enableRx     = false;
}

/*!
 * brief Sets the LPSCI instance baudrate.
 *
 * This function configures the LPSCI module baudrate. This function is used to update
 * the LPSCI module baudrate after the LPSCI module is initialized with the LPSCI_Init.
 * code
 *  LPSCI_SetBaudRate(UART0, 115200U, 20000000U);
 * endcode
 *
 * param base LPSCI peripheral base address.
 * param baudRate_Bps LPSCI baudrate to be set.
 * param srcClock_Hz LPSCI clock source frequency in HZ.
 * retval kStatus_LPSCI_BaudrateNotSupport Baudrate is not supported in the current clock source.
 * retval kStatus_Success Set baudrate succeed
 */
status_t LPSCI_SetBaudRate(UART0_Type *base, uint32_t baudRate_Bps, uint32_t srcClock_Hz)
{
    assert(baudRate_Bps != 0U);

    uint16_t sbrTemp;
    uint32_t osr = 0, sbr = 0;
    uint8_t osrTemp;
    uint32_t tempDiff, calculatedBaud, baudDiff;
    uint8_t oldCtrl;

    /* This LPSCI instantiation uses a slightly different baud rate calculation
     * The idea is to use the best OSR (over-sampling rate) possible
     * Note, OSR is typically hard-set to 16 in other LPSCI instantiations
     * First calculate the baud rate using the minimum OSR possible (4). */
    baudDiff = baudRate_Bps;
    for (osrTemp = 4; osrTemp <= 32; osrTemp++)
    {
        /* calculate the temporary sbr value   */
        sbrTemp = (srcClock_Hz / (baudRate_Bps * osrTemp));
        /* set sbrTemp to 1 if the sourceClockInHz can not satisfy the desired baud rate */
        if (sbrTemp == 0)
        {
            sbrTemp = 1;
        }
        /* Calculate the baud rate based on the temporary OSR and SBR values */
        calculatedBaud = (srcClock_Hz / (osrTemp * sbrTemp));

        tempDiff = calculatedBaud - baudRate_Bps;

        /* Select the better value between srb and (sbr + 1) */
        if (tempDiff > (baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1)))))
        {
            tempDiff = baudRate_Bps - (srcClock_Hz / (osrTemp * (sbrTemp + 1)));
            sbrTemp++;
        }

        if (tempDiff <= baudDiff)
        {
            baudDiff = tempDiff;
            osr      = osrTemp; /* update and store the best OSR value calculated*/
            sbr      = sbrTemp; /* update store the best SBR value calculated*/
        }
    }

    /* next, check to see if actual baud rate is within 3% of desired baud rate
     * based on the best calculate OSR value */
    if (baudDiff < ((baudRate_Bps / 100) * 3))
    {
        /* Store C2 before disable Tx and Rx */
        oldCtrl = base->C2;

        /* Disable LPSCI TX RX before setting. */
        base->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);

        /* Acceptable baud rate */
        /* Check if OSR is between 4x and 7x oversampling*/
        /* If so, then "BOTHEDGE" sampling must be turned on*/
        if ((osr > 3) && (osr < 8))
        {
            base->C5 |= UART0_C5_BOTHEDGE_MASK;
        }

        /* program the osr value (bit value is one less than actual value)*/
        base->C4 = ((base->C4 & ~UART0_C4_OSR_MASK) | (osr - 1));

        /* program the sbr (divider) value obtained above*/
        base->BDH = ((base->C4 & ~UART0_BDH_SBR_MASK) | (uint8_t)(sbr >> 8));
        base->BDL = (uint8_t)sbr;

        /* Restore C2. */
        base->C2 = oldCtrl;

        return kStatus_Success;
    }
    else
    {
        /* Unacceptable baud rate difference of more than 3%*/
        return kStatus_LPSCI_BaudrateNotSupport;
    }
}

/*!
 * brief Enables an LPSCI interrupt according to a provided mask.
 *
 * This function enables the LPSCI interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See ref _lpsci_interrupt_enable.
 * For example, to enable the TX empty interrupt and RX full interrupt:
 * code
 *     LPSCI_EnableInterrupts(UART0,kLPSCI_TxDataRegEmptyInterruptEnable | kLPSCI_RxDataRegFullInterruptEnable);
 * endcode
 *
 * param base LPSCI peripheral base address.
 * param mask The interrupts to enable. Logical OR of ref _lpsci_interrupt_enable.
 */
void LPSCI_EnableInterrupts(UART0_Type *base, uint32_t mask)
{
    mask &= kLPSCI_AllInterruptsEnable;

    /* The interrupt mask is combined by control bits from several register: ((C3<<16) | (C2<<8) |(BDH))
     */
    base->BDH |= mask;
    base->C2 |= (mask >> 8);
    base->C3 |= (mask >> 16);
}

/*!
 * brief Disables the LPSCI interrupt according to a provided mask.
 *
 * This function disables the LPSCI interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See ref _lpsci_interrupt_enable.
 * For example, to disable TX empty interrupt and RX full interrupt:
 * code
 *     LPSCI_DisableInterrupts(UART0,kLPSCI_TxDataRegEmptyInterruptEnable | kLPSCI_RxDataRegFullInterruptEnable);
 * endcode
 *
 * param base LPSCI peripheral base address.
 * param mask The interrupts to disable. Logical OR of ref _LPSCI_interrupt_enable.
 */
void LPSCI_DisableInterrupts(UART0_Type *base, uint32_t mask)
{
    mask &= kLPSCI_AllInterruptsEnable;

    /* The interrupt mask is combined by control bits from several register: ((C3<<16) | (C2<<8) |(BDH))
     */
    base->BDH &= ~mask;
    base->C2 &= ~(mask >> 8);
    base->C3 &= ~(mask >> 16);
}

/*!
 * brief Gets the enabled LPSCI interrupts.
 *
 * This function gets the enabled LPSCI interrupts, which are returned
 * as the logical OR value of the enumerators ref _lpsci_interrupt_enable. To check
 * a specific interrupts enable status, compare the return value to the enumerators
 * in ref _LPSCI_interrupt_enable.
 * For example, to check whether TX empty interrupt is enabled:
 * code
 *     uint32_t enabledInterrupts = LPSCI_GetEnabledInterrupts(UART0);
 *
 *     if (kLPSCI_TxDataRegEmptyInterruptEnable & enabledInterrupts)
 *     {
 *         ...
 *     }
 * endcode
 *
 * param base LPSCI peripheral base address.
 * return LPSCI interrupt flags which are logical OR of the enumerators in ref _LPSCI_interrupt_enable.
 */
uint32_t LPSCI_GetEnabledInterrupts(UART0_Type *base)
{
    uint32_t temp;
    temp = (uint32_t)base->BDH;
    temp |= ((uint32_t)(base->C2) << 8);
    temp |= ((uint32_t)(base->C3) << 16);

    return temp & kLPSCI_AllInterruptsEnable;
}

/*!
 * brief Gets LPSCI status flags.
 *
 * This function gets all LPSCI status flags. The flags are returned as the logical
 * OR value of the enumerators ref _lpsci_flags. To check a specific status,
 * compare the return value to the enumerators in ref _LPSCI_flags.
 * For example, to check whether the TX is empty:
 * code
 *     if (kLPSCI_TxDataRegEmptyFlag | LPSCI_GetStatusFlags(UART0))
 *     {
 *         ...
 *     }
 * endcode
 *
 * param base LPSCI peripheral base address.
 * return LPSCI status flags which are ORed by the enumerators in the _lpsci_flags.
 */
uint32_t LPSCI_GetStatusFlags(UART0_Type *base)
{
    uint32_t status_flag;
    status_flag = (uint32_t)base->S1;
    status_flag |= ((uint32_t)(base->S2) << 8);

#if defined(FSL_FEATURE_LPSCI_HAS_EXTENDED_DATA_REGISTER_FLAGS) && FSL_FEATURE_LPSCI_HAS_EXTENDED_DATA_REGISTER_FLAGS
    status_flag |= ((uint32_t)(base->ED) << 16);
#endif

    return status_flag;
}

/* brief Clears status flags with a provided mask.
 *
 * This function clears the LPSCI status flags with a provided mask. Automatically cleared flag
 * can't be cleared by this function.
 * Some flags can only be cleared or set by hardware. These flags are:
 *    kLPSCI_TxDataRegEmptyFlag,kLPSCI_TransmissionCompleteFlag,kLPSCI_RxDataRegFullFlag,kLPSCI_RxActiveFlag,kLPSCI_NoiseErrorInRxDataRegFlag
 *    kLPSCI_ParityErrorInRxDataRegFlag,kLPSCI_TxFifoEmptyFlag,kLPSCI_RxFifoEmptyFlag
 * Note: This API should be called when the Tx/Rx is idle, otherwise it takes no effects.
 *
 * param base LPSCI peripheral base address.
 * param mask The status flags to be cleared, it is logical OR value of ref _LPSCI_flagss.
 * retval kStatus_LPSCI_FlagCannotClearManually  can't be cleared by this function but it is cleared
 * automatically by hardware.
 * retval kStatus_Success Status in the mask are cleared.
 */
status_t LPSCI_ClearStatusFlags(UART0_Type *base, uint32_t mask)
{
    volatile uint8_t dummy = 0;
    status_t status;
    dummy++; /* For unused variable warning */

#if defined(FSL_FEATURE_LPSCI_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPSCI_HAS_LIN_BREAK_DETECT
    if (mask & kLPSCI_LinBreakFlag)
    {
        base->S2 = UART0_S2_LBKDIF_MASK;
        mask &= ~(uint32_t)kLPSCI_LinBreakFlag;
    }
#endif

    if (mask & kLPSCI_RxActiveEdgeFlag)
    {
        base->S2 = UART0_S2_RXEDGIF_MASK;
        mask &= ~(uint32_t)kLPSCI_RxActiveEdgeFlag;
    }

    if ((mask & (kLPSCI_IdleLineFlag | kLPSCI_RxOverrunFlag | kLPSCI_NoiseErrorFlag | kLPSCI_FramingErrorFlag |
                 kLPSCI_ParityErrorFlag)))
    {
        base->S1 = (mask & (kLPSCI_IdleLineFlag | kLPSCI_RxOverrunFlag | kLPSCI_NoiseErrorFlag |
                            kLPSCI_FramingErrorFlag | kLPSCI_ParityErrorFlag));
        mask &= ~(uint32_t)(kLPSCI_IdleLineFlag | kLPSCI_RxOverrunFlag | kLPSCI_NoiseErrorFlag |
                            kLPSCI_FramingErrorFlag | kLPSCI_ParityErrorFlag);
    }

    if (mask)
    {
        /* Some flags can only clear or set by the hardware itself, these flags are: kLPSCI_TxDataRegEmptyFlag,
        kLPSCI_TransmissionCompleteFlag, kLPSCI_RxDataRegFullFlag, kLPSCI_RxActiveFlag,
        kLPSCI_NoiseErrorInRxDataRegFlag,
        kLPSCI_ParityErrorInRxDataRegFlag*/

        status = kStatus_LPSCI_FlagCannotClearManually;
    }
    else
    {
        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Writes to the TX register using a blocking method.
 *
 * This function polls the TX register, waits for the TX register empty, and
 * writes data to the TX buffer.
 *
 * param base LPSCI peripheral base address.
 * param data Start address of the data to write.
 * param length Size of the data to write.
 */
void LPSCI_WriteBlocking(UART0_Type *base, const uint8_t *data, size_t length)
{
    assert(data != NULL);

    while (length--)
    {
        while (!(base->S1 & UART0_S1_TDRE_MASK))
        {
        }
        base->D = *(data++);
    }
    /* Ensure all the data in the transmit buffer are sent out to bus. */
    while (0U == (base->S1 & (uint32_t)kLPSCI_TransmissionCompleteFlag))
    {
    }
}

/*!
 * brief Reads the RX register using a blocking method.
 *
 * This function polls the RX register, waits for the RX register to be full, and
 * reads data from the RX register.
 *
 * param base LPSCI peripheral base address.
 * param data Start address of the buffer to store the received data.
 * param length Size of the buffer.
 * retval kStatus_LPSCI_RxHardwareOverrun Receiver overrun happened while receiving data.
 * retval kStatus_LPSCI_NoiseError Noise error happened while receiving data.
 * retval kStatus_LPSCI_FramingError Framing error happened while receiving data.
 * retval kStatus_LPSCI_ParityError Parity error happened while receiving data.
 * retval kStatus_Success Successfully received all data.
 */
status_t LPSCI_ReadBlocking(UART0_Type *base, uint8_t *data, size_t length)
{
    assert(data != NULL);

    uint32_t statusFlag;
    status_t status = kStatus_Success;

    while (length-- != 0U)
    {
        while ((base->S1 & UART0_S1_RDRF_MASK) == 0U)
        {
            statusFlag = LPSCI_GetStatusFlags(base);

            if ((statusFlag & (uint32_t)kLPSCI_RxOverrunFlag) != 0U)
            {
                status = ((kStatus_Success == LPSCI_ClearStatusFlags(base, kLPSCI_RxOverrunFlag)) ?
                              (status_t)(kStatus_LPSCI_RxHardwareOverrun) :
                              (status_t)(kStatus_LPSCI_FlagCannotClearManually));
                break;
            }

            if ((statusFlag & (uint32_t)kLPSCI_ParityErrorFlag) != 0U)
            {
                status = ((kStatus_Success == LPSCI_ClearStatusFlags(base, kLPSCI_ParityErrorFlag)) ?
                              (status_t)(kStatus_LPSCI_ParityError) :
                              (status_t)(kStatus_LPSCI_FlagCannotClearManually));
            }

            if ((statusFlag & (uint32_t)kLPSCI_FramingErrorFlag) != 0U)
            {
                status = ((kStatus_Success == LPSCI_ClearStatusFlags(base, kLPSCI_FramingErrorFlag)) ?
                              (status_t)(kStatus_LPSCI_FramingError) :
                              (status_t)(kStatus_LPSCI_FlagCannotClearManually));
            }

            if ((statusFlag & (uint32_t)kLPSCI_NoiseErrorFlag) != 0U)
            {
                status = ((kStatus_Success == LPSCI_ClearStatusFlags(base, kLPSCI_NoiseErrorFlag)) ?
                              (status_t)(kStatus_LPSCI_NoiseError) :
                              (status_t)(kStatus_LPSCI_FlagCannotClearManually));
            }

            if (status != kStatus_Success)
            {
                break;
            }
        }
        if (kStatus_Success == status)
        {
            *(data++) = base->D;
        }
        else
        {
            break;
        }
    }

    return kStatus_Success;
}

/*!
 * brief Initializes the LPSCI handle.
 *
 * This function initializes the LPSCI handle, which can be used for other LPSCI
 * transactional APIs. Usually, for a specified LPSCI instance,
 * call this API once to get the initialized handle.
 *
 * LPSCI driver supports the "background" receiving, which means that the user can set up
 * an RX ring buffer optionally. Data received are stored into the ring buffer even when the
 * user doesn't call the LPSCI_TransferReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, get the received data from the ring buffer directly.
 * The ring buffer is disabled if pass NULL as p ringBuffer.
 *
 * param handle LPSCI handle pointer.
 * param base LPSCI peripheral base address.
 * param ringBuffer Start address of ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * param ringBufferSize size of the ring buffer.
 */
void LPSCI_TransferCreateHandle(UART0_Type *base,
                                lpsci_handle_t *handle,
                                lpsci_transfer_callback_t callback,
                                void *userData)
{
    assert(handle != NULL);

    uint32_t instance;

    /* Zero the handle. */
    memset(handle, 0, sizeof(lpsci_handle_t));

    /* Set the TX/RX state. */
    handle->rxState = kLPSCI_RxIdle;
    handle->txState = kLPSCI_TxIdle;

    /* Set the callback and user data. */
    handle->callback = callback;
    handle->userData = userData;

    /* Get instance from peripheral base address. */
    instance = LPSCI_GetInstance(base);

    /* Save the handle in global variables to support the double weak mechanism. */
    s_lpsciHandle[instance] = handle;

    s_lpsciIsr = LPSCI_TransferHandleIRQ;

    /* Enable interrupt in NVIC. */
    EnableIRQ(s_lpsciIRQ[instance]);
}

/*!
 * brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific LPSCI handle.
 *
 * When the RX ring buffer is used, data received is stored into the ring buffer even when
 * the user doesn't call the LPSCI_TransferReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 *
 * note When using the RX ring buffer, one byte is reserved for internal use. In other
 * words, if p ringBufferSize is 32, only 31 bytes are used for saving data.
 *
 * param base LPSCI peripheral base address.
 * param handle LPSCI handle pointer.
 * param ringBuffer Start address of ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * param ringBufferSize size of the ring buffer.
 */
void LPSCI_TransferStartRingBuffer(UART0_Type *base, lpsci_handle_t *handle, uint8_t *ringBuffer, size_t ringBufferSize)
{
    assert(handle != NULL);
    assert(ringBuffer != NULL);

    /* Setup the ringbuffer address */
    handle->rxRingBuffer     = ringBuffer;
    handle->rxRingBufferSize = ringBufferSize;
    handle->rxRingBufferHead = 0U;
    handle->rxRingBufferTail = 0U;

    /* Disable and re-enable the global interrupt to protect the interrupt enable register during read-modify-wrte. */
    uint32_t irqMask = DisableGlobalIRQ();
    /* Enable the interrupt to accept the data when user need the ring buffer. */
    base->C2 |= UART0_C2_RIE_MASK;
    base->C3 |= (UART0_C3_ORIE_MASK | UART0_C3_FEIE_MASK);

    /* Enable parity error interrupt when parity mode is enable*/
    if ((UART0_C1_PE_MASK & base->C1) != 0U)
    {
        base->C3 |= UART0_C3_PEIE_MASK;
    }
    EnableGlobalIRQ(irqMask);
}

/*!
 * brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ringbuffer.
 *
 * param base LPSCI peripheral base address.
 * param handle LPSCI handle pointer.
 */
void LPSCI_TransferStopRingBuffer(UART0_Type *base, lpsci_handle_t *handle)
{
    assert(handle != NULL);

    if (handle->rxState == kLPSCI_RxIdle)
    {
        /* Disable and re-enable the global interrupt to protect the interrupt enable register during read-modify-wrte.
         */
        uint32_t irqMask = DisableGlobalIRQ();
        base->C2 &= ~UART0_C2_RIE_MASK;
        base->C3 &= ~(UART0_C3_ORIE_MASK | UART0_C3_FEIE_MASK);

        /* Disable parity error interrupt when parity mode is enabled */
        if ((UART0_C1_PE_MASK & base->C1) != 0U)
        {
            base->C3 &= ~UART0_C3_PEIE_MASK;
        }
        EnableGlobalIRQ(irqMask);
    }

    handle->rxRingBuffer     = NULL;
    handle->rxRingBufferSize = 0U;
    handle->rxRingBufferHead = 0U;
    handle->rxRingBufferTail = 0U;
}

/*!
 * brief Transmits a buffer of data using the interrupt method.
 *
 * This function sends data using the interrupt method. This is a non-blocking function, which
 * returns directly without waiting for all data to be written to the TX register. When
 * all data is written to the TX register in ISR, LPSCI driver calls the callback
 * function and passes the ref kStatus_LPSCI_TxIdle as status parameter.
 *
 * note The kStatus_LPSCI_TxIdle is passed to the upper layer when all data is written
 * to the TX register. However, it does not ensure that all data is sent out. Before disabling the TX,
 * check the kLPSCI_TransmissionCompleteFlag to ensure that the TX is complete.
 *
 * param handle LPSCI handle pointer.
 * param xfer LPSCI transfer structure, refer to #LPSCI_transfer_t.
 * retval kStatus_Success Successfully start the data transmission.
 * retval kStatus_LPSCI_TxBusy Previous transmission still not finished, data not all written to the TX register.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPSCI_TransferSendNonBlocking(UART0_Type *base, lpsci_handle_t *handle, lpsci_transfer_t *xfer)
{
    assert(handle != NULL);
    assert(xfer != NULL);
    assert(xfer->dataSize != 0U);
    assert(xfer->txData != NULL);

    status_t status;

    /* Return error if current TX busy. */
    if (kLPSCI_TxBusy == handle->txState)
    {
        status = kStatus_LPSCI_TxBusy;
    }
    else
    {
        handle->txData        = xfer->txData;
        handle->txDataSize    = xfer->dataSize;
        handle->txDataSizeAll = xfer->dataSize;
        handle->txState       = kLPSCI_TxBusy;

        /* Disable and re-enable the global interrupt to protect the interrupt enable register during read-modify-wrte.
         */
        uint32_t irqMask = DisableGlobalIRQ();
        /* Enable transmiter interrupt. */
        base->C2 |= UART0_C2_TIE_MASK;
        EnableGlobalIRQ(irqMask);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt driven data send.
 *
 * param handle LPSCI handle pointer.
 */
void LPSCI_TransferAbortSend(UART0_Type *base, lpsci_handle_t *handle)
{
    assert(handle != NULL);

    /* Disable and re-enable the global interrupt to protect the interrupt enable register during read-modify-wrte. */
    uint32_t irqMask = DisableGlobalIRQ();
    base->C2 &= ~(UART0_C2_TIE_MASK | UART0_C2_TCIE_MASK);
    EnableGlobalIRQ(irqMask);

    handle->txDataSize = 0;
    handle->txState    = kLPSCI_TxIdle;
}

/*!
 * brief Get the number of bytes that have been sent out to bus.
 *
 * This function gets the number of bytes that have been sent out to bus by interrupt method.
 *
 * param base LPSCI peripheral base address.
 * param handle LPSCI handle pointer.
 * param count Send bytes count.
 * retval kStatus_NoTransferInProgress No send in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPSCI_TransferGetSendCount(UART0_Type *base, lpsci_handle_t *handle, uint32_t *count)
{
    assert(handle != NULL);
    assert(count != NULL);

    if (kLPSCI_TxIdle == handle->txState)
    {
        return kStatus_NoTransferInProgress;
    }
#if defined(FSL_FEATURE_LPSCI_HAS_FIFO) && FSL_FEATURE_LPSCI_HAS_FIFO
    *count = handle->txDataSizeAll - handle->txDataSize - base->TCFIFO;
#else
    if ((base->S1 & (uint8_t)kLPSCI_TxDataRegEmptyFlag) != 0U)
    {
        *count = handle->txDataSizeAll - handle->txDataSize;
    }
    else
    {
        *count = handle->txDataSizeAll - handle->txDataSize - 1U;
    }
#endif /* FSL_FEATURE_LPSCI_HAS_FIFO */

    return kStatus_Success;
}

/*!
 * brief Receives buffer of data using the interrupt method.
 *
 * This function receives data using the interrupt method. This is a non-blocking function
 * which returns without waiting for all data to be received.
 * If the RX ring buffer is used and not empty, the data in ring buffer is copied and
 * the parameter p receivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in ring buffer is not enough to read, the receive
 * request is saved by the LPSCI driver. When new data arrives, the receive request
 * is serviced first. When all data is received, the LPSCI driver notifies the upper layer
 * through a callback function and passes the status parameter ref kStatus_LPSCI_RxIdle.
 * For example, the upper layer needs 10 bytes but there are only 5 bytes in the ring buffer.
 * The 5 bytes are copied to the xfer->data and the function returns with the
 * parameter p receivedBytes set to 5. For the remaining 5 bytes, newly arrived data is
 * saved from the xfer->data[5]. When 5 bytes are received, the LPSCI driver notifies the upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to the xfer->data. When all data is received, the upper layer is notified.
 *
 * param handle LPSCI handle pointer.
 * param xfer lpsci transfer structure. See #lpsci_transfer_t.
 * param receivedBytes Bytes received from the ring buffer directly.
 * retval kStatus_Success Successfully queue the transfer into transmit queue.
 * retval kStatus_LPSCI_RxBusy Previous receive request is not finished.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t LPSCI_TransferReceiveNonBlocking(UART0_Type *base,
                                          lpsci_handle_t *handle,
                                          lpsci_transfer_t *xfer,
                                          size_t *receivedBytes)
{
    assert(handle != NULL);
    assert(xfer != NULL);
    assert(xfer->dataSize != 0U);
    assert(xfer->rxData != NULL);

    uint32_t i;
    status_t status;
    /* How many bytes to copy from ring buffer to user memory. */
    size_t bytesToCopy = 0U;
    /* How many bytes to receive. */
    size_t bytesToReceive;
    /* How many bytes currently have received. */
    size_t bytesCurrentReceived;
    uint32_t irqMask;

    /* How to get data:
       1. If RX ring buffer is not enabled, then save xfer->data and xfer->dataSize
          to lpsci handle, enable interrupt to store received data to xfer->data. When
          all data received, trigger callback.
       2. If RX ring buffer is enabled and not empty, get data from ring buffer first.
          If there are enough data in ring buffer, copy them to xfer->data and return.
          If there are not enough data in ring buffer, copy all of them to xfer->data,
          save the xfer->data remained empty space to lpsci handle, receive data
          to this empty space and trigger callback when finished. */

    if (kLPSCI_RxBusy == handle->rxState)
    {
        status = kStatus_LPSCI_RxBusy;
    }
    else
    {
        bytesToReceive       = xfer->dataSize;
        bytesCurrentReceived = 0U;

        /* If RX ring buffer is used. */
        if (handle->rxRingBuffer)
        {
            /* Disable and re-enable the global interrupt to protect the interrupt enable register during
             * read-modify-wrte. */
            irqMask = DisableGlobalIRQ();
            /* Disable LPSCI RX IRQ, protect ring buffer. */
            base->C2 &= ~UART0_C2_RIE_MASK;
            EnableGlobalIRQ(irqMask);

            /* How many bytes in RX ring buffer currently. */
            bytesToCopy = LPSCI_TransferGetRxRingBufferLength(handle);

            if (bytesToCopy)
            {
                bytesToCopy = MIN(bytesToReceive, bytesToCopy);

                bytesToReceive -= bytesToCopy;

                /* Copy data from ring buffer to user memory. */
                for (i = 0U; i < bytesToCopy; i++)
                {
                    xfer->rxData[bytesCurrentReceived++] = handle->rxRingBuffer[handle->rxRingBufferTail];

                    /* Wrap to 0. Not use modulo (%) because it might be large and slow. */
                    if (handle->rxRingBufferTail + 1U == handle->rxRingBufferSize)
                    {
                        handle->rxRingBufferTail = 0U;
                    }
                    else
                    {
                        handle->rxRingBufferTail++;
                    }
                }
            }

            /* If ring buffer does not have enough data, still need to read more data. */
            if (bytesToReceive)
            {
                /* No data in ring buffer, save the request to lpsci handle. */
                handle->rxData        = xfer->rxData + bytesCurrentReceived;
                handle->rxDataSize    = bytesToReceive;
                handle->rxDataSizeAll = bytesToReceive;
                handle->rxState       = kLPSCI_RxBusy;
            }

            /* Disable and re-enable the global interrupt to protect the interrupt enable register during
             * read-modify-wrte. */
            irqMask = DisableGlobalIRQ();
            /* Enable LPSCI RX IRQ if previously enabled. */
            base->C2 |= UART0_C2_RIE_MASK;
            EnableGlobalIRQ(irqMask);

            /* Call user callback since all data are received. */
            if (0 == bytesToReceive)
            {
                if (handle->callback)
                {
                    handle->callback(base, handle, kStatus_LPSCI_RxIdle, handle->userData);
                }
            }
        }
        /* Ring buffer not used. */
        else
        {
            handle->rxData        = xfer->rxData + bytesCurrentReceived;
            handle->rxDataSize    = bytesToReceive;
            handle->rxDataSizeAll = bytesToReceive;
            handle->rxState       = kLPSCI_RxBusy;

            /* Disable and re-enable the global interrupt to protect the interrupt enable register during
             * read-modify-wrte. */
            irqMask = DisableGlobalIRQ();
            /* Enable RX interrupt. */
            base->C2 |= (UART0_C2_RIE_MASK | UART0_C2_ILIE_MASK);
            base->C3 |= (UART0_C3_ORIE_MASK | UART0_C3_FEIE_MASK);

            /* Enable parity error interrupt when parity mode is enable*/
            if ((UART0_C1_PE_MASK & base->C1) != 0U)
            {
                base->C3 |= UART0_C3_PEIE_MASK;
            }
            EnableGlobalIRQ(irqMask);
        }

        /* Return the how many bytes have read. */
        if (receivedBytes)
        {
            *receivedBytes = bytesCurrentReceived;
        }

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts interrupt driven data receiving.
 *
 * This function aborts interrupt driven data receiving.
 *
 * param handle LPSCI handle pointer.
 */
void LPSCI_TransferAbortReceive(UART0_Type *base, lpsci_handle_t *handle)
{
    assert(handle != NULL);

    /* Only abort the receive to handle->rxData, the RX ring buffer is still working. */
    if (!handle->rxRingBuffer)
    {
        /* Disable RX interrupt. */
        LPSCI_DisableInterrupts(base, kLPSCI_RxDataRegFullInterruptEnable | kLPSCI_RxOverrunInterruptEnable |
                                          kLPSCI_FramingErrorInterruptEnable | kLPSCI_IdleLineInterruptEnable);
        /* Disable parity error interrupt when parity mode is enabled */
        if (UART0_C1_PE_MASK & base->C1)
        {
            LPSCI_DisableInterrupts(base, kLPSCI_ParityErrorInterruptEnable);
        }
    }

    handle->rxDataSize = 0U;
    handle->rxState    = kLPSCI_RxIdle;
}

/*!
 * brief Get the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * param base LPSCI peripheral base address.
 * param handle LPSCI handle pointer.
 * param count Receive bytes count.
 * retval kStatus_NoTransferInProgress No receive in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t LPSCI_TransferGetReceiveCount(UART0_Type *base, lpsci_handle_t *handle, uint32_t *count)
{
    assert(handle != NULL);
    assert(count != NULL);

    if (kLPSCI_RxIdle == handle->rxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *count = handle->rxDataSizeAll - handle->rxDataSize;

    return kStatus_Success;
}

/*!
 * brief LPSCI IRQ handle function.
 *
 * This function handles the LPSCI transmit and receive IRQ request.
 *
 * param base LPSCI peripheral base address.
 * param irqHandle LPSCI handle pointer.
 */
void LPSCI_TransferHandleIRQ(UART0_Type *base, void *irqHandle)
{
    assert(irqHandle != NULL);

    uint8_t count;
    uint8_t tempCount;
    uint32_t status            = LPSCI_GetStatusFlags(base);
    uint32_t enabledInterrupts = LPSCI_GetEnabledInterrupts(base);
    uint8_t tmpdata;
    uint32_t irqMask;
    lpsci_handle_t *handle = (lpsci_handle_t *)irqHandle;

    /* If RX parity error */
    if (kLPSCI_ParityErrorFlag & status)
    {
        handle->rxState = kLPSCI_RxParityError;

        LPSCI_ClearStatusFlags(base, kLPSCI_ParityErrorFlag);
        /* Trigger callback. */
        if (handle->callback)
        {
            handle->callback(base, handle, kStatus_LPSCI_ParityError, handle->userData);
        }
    }

    /* If RX framing error */
    if (kLPSCI_FramingErrorFlag & status)
    {
        handle->rxState = kLPSCI_RxFramingError;

        LPSCI_ClearStatusFlags(base, kLPSCI_FramingErrorFlag);
        /* Trigger callback. */
        if (handle->callback)
        {
            handle->callback(base, handle, kStatus_LPSCI_FramingError, handle->userData);
        }
    }
    /* If RX overrun. */
    if (kLPSCI_RxOverrunFlag & status)
    {
        while (UART0_S1_RDRF_MASK & base->S1)
        {
            (void)base->D;
        }

        LPSCI_ClearStatusFlags(base, kLPSCI_RxOverrunFlag);
        /* Trigger callback. */
        if (handle->callback)
        {
            handle->callback(base, handle, kStatus_LPSCI_RxHardwareOverrun, handle->userData);
        }
    }

    /* If idle line detected and idle line interrupt enabled. */
    if ((kLPSCI_IdleLineFlag & status) && (kLPSCI_IdleLineInterruptEnable & enabledInterrupts))
    {
#if defined(FSL_FEATURE_LPSCI_HAS_FIFO) && FSL_FEATURE_LPSCI_HAS_FIFO
        count = base->RCFIFO;

        /* If handle->rxDataSize is not 0, first save data to handle->rxData. */
        while ((count) && (handle->rxDataSize))
        {
            tempCount = MIN(handle->rxDataSize, count);

            /* Using non block API to read the data from the registers. */
            LPSCI_ReadNonBlocking(base, handle->rxData, tempCount);
            handle->rxData += tempCount;
            handle->rxDataSize -= tempCount;
            count -= tempCount;

            /* If all the data required for upper layer is ready, trigger callback. */
            if (!handle->rxDataSize)
            {
                handle->rxState = kLPSCI_RxIdle;

                /* Disable and re-enable the global interrupt to protect the interrupt enable register during
                 * read-modify-wrte. */
                irqMask = DisableGlobalIRQ();
                base->C2 &= ~UART0_C2_RIE_MASK;
                base->C3 &= ~(UART0_C3_ORIE_MASK | UART0_C3_FEIE_MASK);

                /* Disable parity error interrupt when parity mode is enabled */
                if ((UART0_C1_PE_MASK & base->C1) != 0U)
                {
                    base->C3 &= ~UART0_C3_PEIE_MASK;
                }
                EnableGlobalIRQ(irqMask);

                if (handle->callback)
                {
                    handle->callback(base, handle, kStatus_LPSCI_RxIdle, handle->userData);
                }
            }
        }
#endif
        /* Clear the idle line flag. */
        LPSCI_ClearStatusFlags(base, kLPSCI_IdleLineFlag);

        /* Disable idle line interrupt when trasnfer size is 0 */
        if (handle->rxDataSize == 0U)
        {
            /* Disable and re-enable the global interrupt to protect the interrupt enable register during
             * read-modify-wrte. */
            irqMask = DisableGlobalIRQ();
            base->C2 &= ~UART0_C2_ILIE_MASK;
            EnableGlobalIRQ(irqMask);
        }
        /* Trigger callback. */
        if (handle->callback)
        {
            handle->callback(base, handle, kStatus_LPSCI_IdleLineDetected, handle->userData);
        }
    }
    /* Receive data register full */
    if ((kLPSCI_RxDataRegFullFlag & status) && (kLPSCI_RxDataRegFullInterruptEnable & enabledInterrupts))
    {
/* Get the size that can be stored into buffer for this interrupt. */
#if defined(FSL_FEATURE_LPSCI_HAS_FIFO) && FSL_FEATURE_LPSCI_HAS_FIFO
        count = base->RCFIFO;
#else
        count = 1;
#endif

        /* If handle->rxDataSize is not 0, first save data to handle->rxData. */
        while ((count) && (handle->rxDataSize))
        {
#if defined(FSL_FEATURE_LPSCI_HAS_FIFO) && FSL_FEATURE_LPSCI_HAS_FIFO
            tempCount = MIN(handle->rxDataSize, count);
#else
            tempCount = 1;
#endif

            /* Using non block API to read the data from the registers. */
            LPSCI_ReadNonBlocking(base, handle->rxData, tempCount);
            handle->rxData += tempCount;
            handle->rxDataSize -= tempCount;
            count -= tempCount;

            /* If all the data required for upper layer is ready, trigger callback. */
            if (!handle->rxDataSize)
            {
                handle->rxState = kLPSCI_RxIdle;

                if (handle->callback)
                {
                    handle->callback(base, handle, kStatus_LPSCI_RxIdle, handle->userData);
                }
            }
        }

        /* If use RX ring buffer, receive data to ring buffer. */
        if (handle->rxRingBuffer)
        {
            while (count--)
            {
                /* If RX ring buffer is full, trigger callback to notify over run. */
                if (LPSCI_TransferIsRxRingBufferFull(handle))
                {
                    if (handle->callback)
                    {
                        handle->callback(base, handle, kStatus_LPSCI_RxRingBufferOverrun, handle->userData);
                    }
                }

                /* If ring buffer is still full after callback function, the oldest data is overridden. */
                if (LPSCI_TransferIsRxRingBufferFull(handle))
                {
                    /* Increase handle->rxRingBufferTail to make room for new data. */
                    if (handle->rxRingBufferTail + 1U == handle->rxRingBufferSize)
                    {
                        handle->rxRingBufferTail = 0U;
                    }
                    else
                    {
                        handle->rxRingBufferTail++;
                    }
                }

                /* Read data. */
                tmpdata                                        = base->D;
                handle->rxRingBuffer[handle->rxRingBufferHead] = tmpdata;

                /* Increase handle->rxRingBufferHead. */
                if (handle->rxRingBufferHead + 1U == handle->rxRingBufferSize)
                {
                    handle->rxRingBufferHead = 0U;
                }
                else
                {
                    handle->rxRingBufferHead++;
                }
            }
        }
        /* If no receive requst pending, stop RX interrupt. */
        else if (!handle->rxDataSize)
        {
            /* Disable and re-enable the global interrupt to protect the interrupt enable register during
             * read-modify-wrte. */
            irqMask = DisableGlobalIRQ();
            base->C2 &= ~UART0_C2_RIE_MASK;
            base->C3 &= ~(UART0_C3_ORIE_MASK | UART0_C3_FEIE_MASK);

            /* Disable parity error interrupt when parity mode is enabled */
            if ((UART0_C1_PE_MASK & base->C1) != 0U)
            {
                base->C3 &= ~UART0_C3_PEIE_MASK;
            }
            EnableGlobalIRQ(irqMask);
        }
        else
        {
        }
    }
    /* If framing error or parity error happened, stop the RX interrupt when use no ring buffer */
    if (((handle->rxState == kLPSCI_RxFramingError) || (handle->rxState == kLPSCI_RxParityError)) &&
        (!handle->rxRingBuffer))
    {
        /* Disable and re-enable the global interrupt to protect the interrupt enable register during read-modify-wrte.
         */
        irqMask = DisableGlobalIRQ();
        base->C2 &= ~UART0_C2_RIE_MASK;
        base->C3 &= ~(UART0_C3_ORIE_MASK | UART0_C3_FEIE_MASK);

        /* Disable parity error interrupt when parity mode is enabled */
        if ((UART0_C1_PE_MASK & base->C1) != 0U)
        {
            base->C3 &= ~UART0_C3_PEIE_MASK;
        }
        EnableGlobalIRQ(irqMask);
    }

    /* Send data register empty and the interrupt is enabled. */
    if ((kLPSCI_TxDataRegEmptyFlag & status) && (kLPSCI_TxDataRegEmptyInterruptEnable & enabledInterrupts))
    {
/* Get the bytes that available at this moment. */
#if defined(FSL_FEATURE_LPSCI_HAS_FIFO) && FSL_FEATURE_LPSCI_HAS_FIFO
        count = FSL_FEATURE_LPSCI_FIFO_SIZEn(base) - base->TCFIFO;
#else
        count = 1;
#endif

        while ((count) && (handle->txDataSize))
        {
#if defined(FSL_FEATURE_LPSCI_HAS_FIFO) && FSL_FEATURE_LPSCI_HAS_FIFO
            tempCount = MIN(handle->txDataSize, count);
#else
            tempCount = 1;
#endif

            /* Using non block API to write the data to the registers. */
            LPSCI_WriteNonBlocking(base, handle->txData, tempCount);
            handle->txData += tempCount;
            handle->txDataSize -= tempCount;
            count -= tempCount;

            /* If all the data are written to data register, enable TX complete interrupt. */
            if (!handle->txDataSize)
            {
                /* Disable and re-enable the global interrupt to protect the interrupt enable register during
                 * read-modify-wrte. */
                irqMask = DisableGlobalIRQ();
                /* Disable TX register empty interrupt and enable transmission complete interrupt. */
                base->C2 = (base->C2 & ~UART0_C2_TIE_MASK) | UART0_C2_TCIE_MASK;
                EnableGlobalIRQ(irqMask);
            }
        }
    }

    /* Transmission complete and the interrupt is enabled. */
    if ((0U != ((uint32_t)kLPSCI_TransmissionCompleteFlag & status)) &&
        (0U != ((uint32_t)kLPSCI_TransmissionCompleteInterruptEnable & enabledInterrupts)))
    {
        /* Set txState to idle only when all data has been sent out to bus. */
        handle->txState = kLPSCI_TxIdle;

        /* Disable and re-enable the global interrupt to protect the interrupt enable register during read-modify-wrte.
         */
        irqMask = DisableGlobalIRQ();
        /* Disable transmission complete interrupt. */
        base->C2 &= ~UART0_C2_TCIE_MASK;
        EnableGlobalIRQ(irqMask);

        /* Trigger callback. */
        if (handle->callback)
        {
            handle->callback(base, handle, kStatus_LPSCI_TxIdle, handle->userData);
        }
    }
}

/*!
 * brief LPSCI Error IRQ handle function.
 *
 * This function handle the LPSCI error IRQ request.
 *
 * param base LPSCI peripheral base address.
 * param handle LPSCI handle pointer.
 */
void LPSCI_TransferHandleErrorIRQ(UART0_Type *base, void *handle)
{
    /* To be implemented by User. */
}

#if defined(UART0)
void UART0_DriverIRQHandler(void);
void UART0_DriverIRQHandler(void)
{
    s_lpsciIsr(UART0, s_lpsciHandle[0]);
    SDK_ISR_EXIT_BARRIER;
}

#endif
