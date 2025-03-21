/*
 * Copyright 2021-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mscan.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_mscan"
#endif

#define MAX_SAMP (CAN_BTR1_SAMP_MASK >> CAN_BTR1_SAMP_SHIFT)
#define MAX_SJW  (CAN_BTR0_SJW_MASK >> CAN_BTR0_SJW_SHIFT)
#define MAX_BRP  (CAN_BTR0_BRP_MASK >> CAN_BTR0_BRP_SHIFT)

#define MAX_TSEG1 (CAN_BTR1_TSEG1_MASK >> CAN_BTR1_TSEG1_SHIFT)
#define MIN_TSEG1 (3U)
#define MAX_TSEG2 (CAN_BTR1_TSEG2_MASK >> CAN_BTR1_TSEG2_SHIFT)
#define MIN_TSEG2 (1U)

/* MsCAN timing setting formula:
 * MSCAN_TIME_QUANTA_NUM = 1 + (TSEG1 + 1) + (TSEG2 + 1);
 */
#define MSCAN_MAX_TIME_QUANTA (1U + MAX_TSEG1 + 1U + MAX_TSEG2 + 1U)
#define MSCAN_MIN_TIME_QUANTA (8U)

#define IDEAL_SP_LOW     (750U)
#define IDEAL_SP_MID     (800U)
#define IDEAL_SP_HIGH    (875U)
#define IDEAL_SP_FACTOR  (1000U)
#define MAX_CAN_BAUDRATE (1000000U)

/* Max length of data length. */
#define MSCAN_DLC_MAX (8U)

/*! @brief MSCAN Internal State. */
enum _mscan_state
{
    kMSCAN_StateIdle     = 0x0, /*!< MB/RxFIFO idle.*/
    kMSCAN_StateRxData   = 0x1, /*!< MB receiving.*/
    kMSCAN_StateRxRemote = 0x2, /*!< MB receiving remote reply.*/
    kMSCAN_StateTxData   = 0x3, /*!< MB transmitting.*/
    kMSCAN_StateTxRemote = 0x4, /*!< MB transmitting remote request.*/
    kMSCAN_StateRxFifo   = 0x5, /*!< RxFIFO receiving.*/
};

/*! @brief MSCAN message buffer CODE for Rx buffers. */
enum _mscan_mb_code_rx
{
    kMSCAN_RxMbInactive = 0x0, /*!< MB is not active.*/
    kMSCAN_RxMbFull     = 0x2, /*!< MB is full.*/
    kMSCAN_RxMbEmpty    = 0x4, /*!< MB is active and empty.*/
    kMSCAN_RxMbOverrun  = 0x6, /*!< MB is overwritten into a full buffer.*/
    kMSCAN_RxMbBusy     = 0x8, /*!< FlexCAN is updating the contents of the MB.*/
                               /*!  The CPU must not access the MB.*/
    kMSCAN_RxMbRanswer = 0xA,  /*!< A frame was configured to recognize a Remote Request Frame */
                               /*!  and transmit a Response Frame in return.*/
    kMSCAN_RxMbNotUsed = 0xF,  /*!< Not used.*/
};

/*! @brief FlexCAN message buffer CODE FOR Tx buffers. */
enum _mscan_mb_code_tx
{
    kFLEXCAN_TxMbInactive     = 0x8, /*!< MB is not active.*/
    kFLEXCAN_TxMbAbort        = 0x9, /*!< MB is aborted.*/
    kFLEXCAN_TxMbDataOrRemote = 0xC, /*!< MB is a TX Data Frame(when MB RTR = 0) or */
                                     /*!< MB is a TX Remote Request Frame (when MB RTR = 1).*/
    kFLEXCAN_TxMbTanswer = 0xE,      /*!< MB is a TX Response Request Frame from */
                                     /*!  an incoming Remote Request Frame.*/
    kFLEXCAN_TxMbNotUsed = 0xF,      /*!< Not used.*/
};

/* Typedef for interrupt handler. */
typedef void (*mscan_isr_t)(CAN_Type *base, mscan_handle_t *handle);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get the MsCAN instance from peripheral base address.
 *
 * @param base MsCAN peripheral base address.
 * @return MsCAN instance.
 */
static uint32_t MSCAN_GetInstance(CAN_Type *base);

/*!
 * @brief Enter MsCAN Initial Mode.
 *
 * This function makes the MsCAN work under Initial Mode.
 *
 * @param base MsCAN peripheral base address.
 */
static void MSCAN_EnterInitMode(CAN_Type *base);

/*!
 * @brief Exit MsCAN Initial Mode.
 *
 * This function makes the MsCAN leave Initial Mode.
 *
 * @param base MsCAN peripheral base address.
 */
static void MSCAN_ExitInitMode(CAN_Type *base);

/*!
 * @brief Calculates the segment values for a single bit time for classical MSCAN
 *
 * @param baudRate The data speed in bps
 * @param tqNum Number of time quantas per bit
 * @param pconfig Pointer to the FlexCAN timing configuration structure.
 *
 * @return TRUE if valid Segments found, FALSE if failed to get valid segments
 */
static void MSCAN_GetSegments(uint32_t baudRate, uint32_t tqNum, mscan_timing_config_t *pconfig);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Array of MsCAN peripheral base address. */
static CAN_Type *const s_mscanBases[] = CAN_BASE_PTRS;

/* Array of MSCAN IRQ number. */
static const IRQn_Type s_mscanRxWarningIRQ[] = {CAN_RX_WARN_IRQn};
static const IRQn_Type s_mscanTxWarningIRQ[] = {CAN_TX_WARN_IRQn};
static const IRQn_Type s_mscanWakeUpIRQ[]    = {CAN_WAKEUP_IRQn};
static const IRQn_Type s_mscanErrorIRQ[]     = {CAN_ERROR_IRQn};

/* Array of MsCAN handle. */
static mscan_handle_t *s_mscanHandle[ARRAY_SIZE(s_mscanBases)];

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Array of MsCAN clock name. */
static const clock_ip_name_t s_mscanClock[] = MSCAN_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/* MsCAN ISR for transactional APIs. */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
static mscan_isr_t s_mscanIsr = (mscan_isr_t)DefaultISR;
#else
static mscan_isr_t s_mscanIsr;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t MSCAN_GetInstance(CAN_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_mscanBases); instance++)
    {
        if (s_mscanBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_mscanBases));

    return instance;
}

static void MSCAN_EnterInitMode(CAN_Type *base)
{
    /* Set initial request bit. */
    base->CTL0 |= CAN_CTL0_INITRQ_MASK;

    /* Wait until the MsCAN Module enters initial mode. */
    while (0U == (base->CTL1 & CAN_CTL1_INITAK_MASK))
    {
    }
}

static void MSCAN_ExitInitMode(CAN_Type *base)
{
    /* Clear initial request bit. */
    base->CTL0 &= ~((uint16_t)CAN_CTL0_INITRQ_MASK);

    /* Wait until the MsCAN Module exits initial mode. */
    while (0U != (base->CTL1 & CAN_CTL1_INITAK_MASK))
    {
    }
}

/*!
 * @brief Calculates the segment values for a single bit time for classical CAN
 *
 * @param baudRate The data speed in bps
 * @param tqNum Number of time quantas per bit
 * @param pconfig Pointer to the FlexCAN timing configuration structure.
 */
static void MSCAN_GetSegments(uint32_t baudRate, uint32_t tqNum, mscan_timing_config_t *pconfig)
{
    uint32_t ideal_sp;

    /* Try to find the ideal sample point, according to CiA 301 doc.*/
    if (baudRate == 1000000U)
    {
        ideal_sp = IDEAL_SP_LOW;
    }
    else if (baudRate >= 800000U)
    {
        ideal_sp = IDEAL_SP_MID;
    }
    else
    {
        ideal_sp = IDEAL_SP_HIGH;
    }
    /* Calculates timeSeg2. */
    pconfig->timeSeg2 = (uint8_t)(tqNum - (tqNum * ideal_sp) / (uint32_t)IDEAL_SP_FACTOR) - 1U;
    if (pconfig->timeSeg2 < MIN_TSEG2)
    {
        pconfig->timeSeg2 = (uint8_t)MIN_TSEG2;
    }

    /* Readjusts timeSeg1 to avoid overflow. */
    pconfig->timeSeg1 = (uint8_t)(tqNum - pconfig->timeSeg2 - 3U);
    if (pconfig->timeSeg1 >= MAX_TSEG1)
    {
        pconfig->timeSeg1 = (uint8_t)MAX_TSEG1;
        pconfig->timeSeg2 = (uint8_t)(tqNum - pconfig->timeSeg1 - 3U);
    }

    /* sJumpwidth (sjw) is the minimum value of timeSeg1 and timeSeg2. */
    pconfig->sJumpwidth = (pconfig->timeSeg1 > pconfig->timeSeg2) ? pconfig->timeSeg2 : pconfig->timeSeg1;
    if (pconfig->sJumpwidth > MAX_SJW)
    {
        pconfig->sJumpwidth = (uint8_t)MAX_SJW;
    }
}

/*!
 * brief Calculates the improved timing values by specific baudrates for classical MSCAN
 *
 * param baudRate  The classical MSCAN speed in bps defined by user
 * param sourceClock_Hz The Source clock frequency in Hz.
 * param pconfig Pointer to the MSCAN timing configuration structure.
 *
 * return TRUE if timing configuration found, FALSE if failed to find configuration
 */
bool MSCAN_CalculateImprovedTimingValues(uint32_t baudRate, uint32_t sourceClock_Hz, mscan_timing_config_t *pconfig)
{
    uint32_t clk;   /* the clock is tqNumb x baudRateFD. */
    uint32_t tqNum; /* Numbers of TQ. */
    bool fgRet                       = false;
    uint32_t spTemp                  = 1000U;
    mscan_timing_config_t configTemp = {0};

    /*  Auto Improved Protocal timing for CBT. */
    for (tqNum = MSCAN_MAX_TIME_QUANTA; tqNum >= MSCAN_MIN_TIME_QUANTA; tqNum--)
    {
        clk = baudRate * tqNum;
        if (clk > sourceClock_Hz)
        {
            continue; /* tqNum too large, clk has been exceed sourceClock_Hz. */
        }

        if ((sourceClock_Hz / clk * clk) != sourceClock_Hz)
        {
            continue; /*  Non-supporting: the frequency of clock source is not divisible by target baud rate, the user
                      should change a divisible baud rate. */
        }

        if ((sourceClock_Hz / clk - 1U) > MAX_BRP)
        {
            break; /* The frequency of source clock is too large or the baud rate is too small, the pre-divider could
                      not handle it. */
        }
        else
        {
            configTemp.priDiv = (uint8_t)(sourceClock_Hz / clk - 1U);
        }

        MSCAN_GetSegments(baudRate, tqNum, &configTemp);
        /* Determine whether the calculated timing configuration can get the optimal sampling point. */
        if (((((uint32_t)configTemp.timeSeg2 + 1U) * 1000U) / tqNum) < spTemp)
        {
            spTemp              = (((uint32_t)configTemp.timeSeg2 + 1U) * 1000U) / tqNum;
            pconfig->priDiv     = configTemp.priDiv;
            pconfig->sJumpwidth = configTemp.sJumpwidth;
            pconfig->timeSeg1   = configTemp.timeSeg1;
            pconfig->timeSeg2   = configTemp.timeSeg2;
        }
        fgRet = true;
    }
    if (fgRet)
    {
        pconfig->samp = 0U;
    }

    return fgRet;
}

status_t MSCAN_SetBaudRate(CAN_Type *base, uint32_t sourceClock_Hz, uint32_t baudRate_Bps)
{
    mscan_timing_config_t timingConfig = {0};

    /* Assertion: Desired baud rate is too high or two low. */
    assert((baudRate_Bps <= 1000000U) && (baudRate_Bps != 0U));
    /* Assertion: Source clock should greater than baud rate * MSCAN_MIN_TIME_QUANTA. */
    assert((baudRate_Bps * MSCAN_MIN_TIME_QUANTA) <= sourceClock_Hz);

    /* Calculate timing automatically with given Baud Rate. */
    if (MSCAN_CalculateImprovedTimingValues(baudRate_Bps, sourceClock_Hz, &timingConfig))

    {
        /* Update classic CAN timing characteristic. */
        MSCAN_SetTimingConfig(base, &timingConfig);
        return kStatus_Success;
    }
    else
    {
        /* Auto calculate classic CAN bit timing configuration failed! Use the following configuration, the final
         * bit rate will have some errors (10 Tq with 80% SP). */
        timingConfig.sJumpwidth = 1U;
        timingConfig.timeSeg1   = 6U;
        timingConfig.timeSeg2   = 1U;
        if ((sourceClock_Hz / 10U / baudRate_Bps) == 0U)
        {
            timingConfig.priDiv = 0U;
        }
        else if ((sourceClock_Hz / 10U / baudRate_Bps) > 64U)
        {
            timingConfig.priDiv = 0U;
        }
        else
        {
            timingConfig.priDiv = (uint8_t)(sourceClock_Hz / 10U / baudRate_Bps - 1U);
        }
        /* Update classic CAN timing characteristic. */
        MSCAN_SetTimingConfig(base, &timingConfig);
        return kStatus_Fail;
    }
}

/*!
 * brief Initializes a MsCAN instance.
 *
 * This function initializes the MsCAN module with user-defined settings. This example shows how to set up the
 * mscan_config_t parameters and how to call the MSCAN_Init function by passing in these parameters.When
 * mscanConfig.enableTimingCalc is true and the clock and baudrate parameters are not completely matched, there will be
 * a certain error in the automatically calculated bit timing value. The user can know whether the clock and baudrate
 * match by calling MSCAN_CalculateImprovedTimingValues() API, and get the calculated bit timing.
 *  code
 *   mscan_config_t mscanConfig;
 *   mscanConfig.clkSrc            = kMSCAN_ClkSrcBus;
 *   mscanConfig.sourceClock       = 40000000U;
 *   mscanConfig.baudRate          = 500000U;
 *   mscanConfig.enableTimingCalc  = true;
 *   mscanConfig.enableTimer       = false;
 *   mscanConfig.enableLoopBack    = false;
 *   mscanConfig.enableWakeup      = false;
 *   mscanConfig.enableListen      = false;
 *   mscanConfig.busoffrecMode     = kMSCAN_BusoffrecAuto;
 *   mscanConfig.filterConfig.filterMode = kMSCAN_Filter32Bit;
 *   MSCAN_Init(MSCAN, &mscanConfig);
 *  endcode
 *
 * param base MsCAN peripheral base address.
 * param config Pointer to the user-defined configuration structure.
 */
void MSCAN_Init(CAN_Type *base, const mscan_config_t *config)
{
    uint8_t ctl0Temp, ctl1Temp;
    uint32_t u4temp;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint32_t instance;
#endif

    /* Assertion. */
    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    instance = MSCAN_GetInstance(base);
    /* Enable MsCAN clock. */
    CLOCK_EnableClock(s_mscanClock[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Enable MsCAN Module for configuartion. */
    MSCAN_Enable(base, true);

    /* Enter initialization mode for MSCAN configuration. */
    MSCAN_EnterInitMode(base);

    ctl0Temp = (uint8_t)base->CTL0;
    ctl1Temp = (uint8_t)base->CTL1;

    /* Enable Self Wake Up Mode. */
    ctl0Temp =
        (config->enableWakeup) ? ctl0Temp | (uint8_t)CAN_CTL0_WUPE_MASK : ctl0Temp & ~((uint8_t)CAN_CTL0_WUPE_MASK);
    /* Enable Loop Back Mode. */
    ctl1Temp =
        (config->enableLoopBack) ? ctl1Temp | (uint8_t)CAN_CTL1_LOOPB_MASK : ctl1Temp & ~((uint8_t)CAN_CTL1_LOOPB_MASK);
    /* Enable Listen Mode. */
    ctl1Temp =
        (config->enableListen) ? ctl1Temp | (uint8_t)CAN_CTL1_LISTEN_MASK : ctl1Temp & ~((uint8_t)CAN_CTL1_LISTEN_MASK);
    /* Clock source selection. */
    ctl1Temp = (kMSCAN_ClkSrcBus == config->clkSrc) ? ctl1Temp | (uint8_t)CAN_CTL1_CLKSRC_MASK :
                                                      ctl1Temp & ~((uint8_t)CAN_CTL1_CLKSRC_MASK);

    /* Save CTLx Configuation. */
    base->CTL0 = ctl0Temp;
    base->CTL1 = ctl1Temp;

    /* Configure ID acceptance filter setting. */
    MSCAN_SetIDFilterMode(base, config->filterConfig.filterMode);
    u4temp = config->filterConfig.u32IDAR0; /* To fix MISRA-C 2012 Rule 11.8 issue. */
    MSCAN_WriteIDAR0(base, (uint8_t *)(&u4temp));
    u4temp = config->filterConfig.u32IDMR0;
    MSCAN_WriteIDMR0(base, (uint8_t *)(&u4temp));
    u4temp = config->filterConfig.u32IDAR1;
    MSCAN_WriteIDAR1(base, (uint8_t *)(&u4temp));
    u4temp = config->filterConfig.u32IDMR1;
    MSCAN_WriteIDMR1(base, (uint8_t *)(&u4temp));

    if (config->enableTimingCalc)
    {
        /* Calculate the bit timing, when the clock frequency and bit rate do not match, the MSCAN_SetBaudRate API will
         * use a default bit timing value (10 Tq with 80% SP), and the final bit rate will have some errors. */
        (void)MSCAN_SetBaudRate(base, config->sourceClock, config->baudRate);
    }
    else
    {
        /* Set bit timing characteristic base on user's precise values passed as mscan_timing_config_t. */
        MSCAN_SetTimingConfig(base, &config->timingConfig);
    }
    /* Enter normal mode. */
    MSCAN_ExitInitMode(base);

    /* Enable Timer. */
    base->CTL0 =
        (config->enableTimer) ? base->CTL0 | (uint8_t)CAN_CTL0_TIME_MASK : base->CTL0 & ~((uint8_t)CAN_CTL0_TIME_MASK);
}

/*!
 * brief De-initializes a MsCAN instance.
 *
 * This function disables the MsCAN module clock and sets all register values
 * to the reset value.
 *
 * param base MsCAN peripheral base address.
 */
void MSCAN_Deinit(CAN_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint32_t instance;
#endif

    /* Disable MsCAN module. */
    MSCAN_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    instance = MSCAN_GetInstance(base);
    /* Disable MsCAN clock. */
    CLOCK_DisableClock(s_mscanClock[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the MsCAN configuration structure to default values. User is requested to provide the clock
 * frequency for the peripheral.
 *
 * param config Pointer to the MsCAN configuration structure.
 * param sourceClock_Hz MsCAN peripheral clock
 */
void MSCAN_GetDefaultConfig(mscan_config_t *config, uint32_t sourceClock_Hz)
{
    /* Assertion. */
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* Initialize MsCAN Module config struct with default value. */
    config->enableTimer             = false;
    config->enableWakeup            = false;
    config->clkSrc                  = kMSCAN_ClkSrcBus;
    config->enableLoopBack          = false;
    config->enableListen            = false;
    config->busoffrecMode           = kMSCAN_BusoffrecAuto;
    config->filterConfig.filterMode = kMSCAN_Filter32Bit;
    config->enableTimingCalc        = true;
    config->baudRate                = 500000U;
    config->sourceClock             = sourceClock_Hz;
}

/*!
 * brief Sets the MsCAN protocol timing characteristic.
 *
 * This function gives user settings to CAN bus timing characteristic.
 * The function is for an experienced user. For less experienced users, call
 * the MSCAN_Init() and fill the baud rate field with a desired value.
 * This provides the default timing characteristics to the module.
 *
 * Note that calling MSCAN_SetTimingConfig() overrides the baud rate set
 * in MSCAN_Init().
 *
 * param base MsCAN peripheral base address.
 * param config Pointer to the timing configuration structure.
 */
void MSCAN_SetTimingConfig(CAN_Type *base, const mscan_timing_config_t *config)
{
    /* Assertion. */
    assert(NULL != config);

    /* Enter Inialization Mode. */
    MSCAN_EnterInitMode(base);

    /* Cleaning previous Timing Setting. */
    base->BTR0 &= (uint8_t)(~(CAN_BTR0_BRP_MASK | CAN_BTR0_SJW_MASK));
    base->BTR1 &= (uint8_t)(~(CAN_BTR1_TSEG1_MASK | CAN_BTR1_TSEG2_MASK | CAN_BTR1_SAMP_MASK));

    /* Updating Timing Setting according to configuration structure. */
    base->BTR0 |= (CAN_BTR0_BRP(config->priDiv) | CAN_BTR0_SJW(config->sJumpwidth));
    base->BTR1 |= (CAN_BTR1_TSEG1(config->timeSeg1) | CAN_BTR1_TSEG2(config->timeSeg2) | CAN_BTR1_SAMP(config->samp));

    /* Exit Inialization Mode. */
    MSCAN_ExitInitMode(base);
}

/*!
 * brief Writes a MsCAN Message to the Transmit Message Buffer.
 *
 * This function writes a CAN Message to the specified Transmit Message Buffer
 * and changes the Message Buffer state to start CAN Message transmit. After
 * that the function returns immediately.
 *
 * param base MsCAN peripheral base address.
 * param pTxFrame Pointer to CAN message frame to be sent.
 * retval kStatus_Success - Write Tx Message Buffer Successfully.
 * retval kStatus_Fail    - Tx Message Buffer is currently in use.
 * retval kStatus_MSCAN_DataLengthError - Tx Message Buffer data length is wrong.
 */
status_t MSCAN_WriteTxMb(CAN_Type *base, mscan_frame_t *pTxFrame)
{
    uint8_t txEmptyFlag;
    mscan_mb_t mb      = {0};
    IDR1_3_UNION sIDR1 = {0}, sIDR3 = {0};
    status_t status;
    uint8_t i;

    if (pTxFrame->DLR > MSCAN_DLC_MAX)
    {
        return kStatus_MSCAN_DataLengthError;
    }

    /* Write IDR. */
    if (kMSCAN_FrameFormatExtend == pTxFrame->format)
    {
        /* Deal with Extended frame. */
        sIDR1.IDR1.EID20_18_OR_SID2_0 = (uint8_t)pTxFrame->ID_Type.ExtID.EID20_18;
        sIDR1.IDR1.R_TSRR             = MSCAN_R_TSRR;
        sIDR1.IDR1.R_TEIDE            = MSCAN_R_TEIDE;
        sIDR1.IDR1.EID17_15           = (uint8_t)pTxFrame->ID_Type.ExtID.EID17_15;
        sIDR3.IDR3.EID6_0             = (uint8_t)pTxFrame->ID_Type.ExtID.EID6_0;
        sIDR3.IDR3.ERTR               = (kMSCAN_FrameTypeRemote == pTxFrame->type) ? 1U : 0U;
        /* Write into MB structure. */
        mb.EIDR0 = (uint8_t)pTxFrame->ID_Type.ExtID.EID28_21;
        mb.EIDR1 = sIDR1.Bytes;
        mb.EIDR2 = (uint8_t)pTxFrame->ID_Type.ExtID.EID14_7;
        mb.EIDR3 = sIDR3.Bytes;
    }
    else
    {
        /* Deal with Standard frame. */
        sIDR1.IDR1.EID20_18_OR_SID2_0 = (uint8_t)pTxFrame->ID_Type.StdID.EID2_0;
        sIDR1.IDR1.R_TSRR             = 0U;
        sIDR1.IDR1.R_TEIDE            = 0U;
        sIDR1.IDR1.EID17_15           = 0U; /* Reserved for Standard frame*/
        /* Write into MB structure. */
        mb.EIDR0 = (uint8_t)pTxFrame->ID_Type.StdID.EID10_3;
        mb.EIDR1 = sIDR1.Bytes;
    }
    /* Write DLR, BPR */
    mb.DLR = pTxFrame->DLR;
    mb.BPR = pTxFrame->BPR;

    /* Write DSR */
    for (i = 0U; i < mb.DLR; i++)
    {
        mb.EDSR[i] = pTxFrame->DSR[i];
    }

    /* 1.Read TFLG to get the empty transmitter buffers. */
    txEmptyFlag = MSCAN_GetTxBufferEmptyFlag(base);

    if ((uint8_t)kMSCAN_TxBufFull != txEmptyFlag)
    {
        /* 2.Write TFLG value back. */
        MSCAN_TxBufferSelect(base, txEmptyFlag);
        /* Push contents of mb structure into hardware register. */
        base->TXFG_IDR0_EXT = mb.EIDR0;
        base->TXFG_IDR1_EXT = mb.EIDR1;
        base->TXFG_IDR2_EXT = mb.EIDR2;
        base->TXFG_IDR3_EXT = mb.EIDR3;
        for (i = 0U; i < mb.DLR; i++)
        {
            base->TXFG_DSR[i] = mb.EDSR[i];
        }
        base->TXFG_DLR  = mb.DLR;
        base->TXFG_TBPR = mb.BPR;

        /* 3.Read TBSEL again to get lowest tx buffer, then write 1 to clear
        the corresponding bit to schedule transmission. */
        MSCAN_TxBufferLaunch(base, MSCAN_GetTxBufferSelect(base));

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }
    return status;
}

/*!
 * brief Reads a MsCAN Message from Receive Message Buffer.
 *
 * This function reads a CAN message from a specified Receive Message Buffer.
 * The function fills a receive CAN message frame structure with
 * just received data and activates the Message Buffer again.
 * The function returns immediately.
 *
 * param base MsCAN peripheral base address.
 * param pRxFrame Pointer to CAN message frame structure for reception.
 * retval kStatus_Success            - Rx Message Buffer is full and has been read successfully.
 * retval kStatus_Fail               - Rx Message Buffer is empty.
 * retval kStatus_MSCAN_DataLengthError - Rx Message data length is wrong.
 */
status_t MSCAN_ReadRxMb(CAN_Type *base, mscan_frame_t *pRxFrame)
{
    IDR1_3_UNION sIDR1 = {0};
    IDR1_3_UNION sIDR3 = {0};
    uint8_t i;
    status_t status;

    if (0U != MSCAN_GetRxBufferFullFlag(base))
    {
        status = kStatus_Success;

        sIDR1.Bytes      = MSCAN_ReadRIDR1(base);
        sIDR3.Bytes      = MSCAN_ReadRIDR3(base);
        pRxFrame->format = (mscan_frame_format_t)(sIDR1.IDR1.R_TEIDE);

        if (kMSCAN_FrameFormatExtend == pRxFrame->format) /* Extended frame. */
        {
            pRxFrame->type                   = (mscan_frame_type_t)(sIDR3.IDR3.ERTR);
            pRxFrame->ID_Type.ExtID.EID28_21 = MSCAN_ReadRIDR0(base);
            pRxFrame->ID_Type.ExtID.EID20_18 = sIDR1.IDR1.EID20_18_OR_SID2_0;
            pRxFrame->ID_Type.ExtID.EID17_15 = sIDR1.IDR1.EID17_15;
            pRxFrame->ID_Type.ExtID.EID14_7  = MSCAN_ReadRIDR2(base);
            pRxFrame->ID_Type.ExtID.EID6_0   = sIDR3.IDR3.EID6_0;
        }
        else /* Standard frame. */
        {
            pRxFrame->type                  = (mscan_frame_type_t)(sIDR1.IDR1.R_TSRR);
            pRxFrame->ID_Type.StdID.EID10_3 = MSCAN_ReadRIDR0(base);
            pRxFrame->ID_Type.StdID.EID2_0  = sIDR1.IDR1.EID20_18_OR_SID2_0;
        }

        pRxFrame->DLR = (uint8_t)(base->RXFG_DLR & 0x0FU);

        if (pRxFrame->DLR > MSCAN_DLC_MAX)
        {
            pRxFrame->DLR = MSCAN_DLC_MAX;
            status        = kStatus_MSCAN_DataLengthError;
        }

        for (i = 0; i < pRxFrame->DLR; i++)
        {
            pRxFrame->DSR[i] = (uint8_t)base->RXFG_DSR[i];
        }

        pRxFrame->TSRH = (uint8_t)base->TXFG_TSRH;
        pRxFrame->TSRL = (uint8_t)base->TXFG_TSRL;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

/*!
 * brief Performs a polling send transaction on the CAN bus.
 *
 * Note that a transfer handle does not need to be created before calling this API.
 *
 * param base MsCAN peripheral base pointer.
 * param pTxFrame Pointer to CAN message frame to be sent.
 * retval kStatus_Success - Write Tx Message Buffer Successfully.
 * retval kStatus_Fail    - Tx Message Buffer is currently in use.
 * retval kStatus_MSCAN_DataLengthError - Tx Message Buffer data length is wrong.
 */
status_t MSCAN_TransferSendBlocking(CAN_Type *base, mscan_frame_t *pTxFrame)
{
    status_t status;

    /* Write Tx Message Buffer to initiate a data sending. */
    status = MSCAN_WriteTxMb(base, pTxFrame);

    if (kStatus_Success == status)
    {
        /* Wait until CAN Message send out. */
        while (0U == MSCAN_GetTxBufferStatusFlags(base, MSCAN_GetTxBufferSelect(base)))
        {
        }
    }

    return status;
}

/*!
 * brief Performs a polling receive transaction on the CAN bus.
 *
 * Note that a transfer handle does not need to be created before calling this API.
 *
 * param base MsCAN peripheral base pointer.
 * param pRxFrame Pointer to CAN message frame to be received.
 * retval kStatus_Success - Read Rx Message Buffer Successfully.
 * retval kStatus_Fail    - Tx Message Buffer is currently in use.
 * retval kStatus_MSCAN_DataLengthError - Rx Message data length is wrong.
 */
status_t MSCAN_TransferReceiveBlocking(CAN_Type *base, mscan_frame_t *pRxFrame)
{
    status_t status;

    /* Wait until a new message is available in Rx Message Buffer. */
    while (0U == MSCAN_GetRxBufferFullFlag(base))
    {
    }

    /* Read Received CAN Message. */
    status = MSCAN_ReadRxMb(base, pRxFrame);
    if (kStatus_Success == status)
    {
        /* Clear RXF flag to release the buffer. */
        MSCAN_ClearRxBufferFullFlag(base);
    }

    return status;
}

/*!
 * brief Initializes the MsCAN handle.
 *
 * This function initializes the MsCAN handle, which can be used for other MsCAN
 * transactional APIs. Usually, for a specified MsCAN instance,
 * call this API once to get the initialized handle.
 *
 * param base MsCAN peripheral base address.
 * param handle MsCAN handle pointer.
 * param callback The callback function.
 * param userData The parameter of the callback function.
 */
void MSCAN_TransferCreateHandle(CAN_Type *base,
                                mscan_handle_t *handle,
                                mscan_transfer_callback_t callback,
                                void *userData)
{
    assert(NULL != handle);

    uint8_t instance;

    /* Clean MSCAN transfer handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Get instance from peripheral base address. */
    instance = (uint8_t)MSCAN_GetInstance(base);

    /* Save the context in global variables to support the double weak mechanism. */
    s_mscanHandle[instance] = handle;

    /* Register Callback function. */
    handle->callback = callback;
    handle->userData = userData;

    s_mscanIsr = MSCAN_TransferHandleIRQ;

    /* We Enable Error & Status interrupt here, because this interrupt just
     * report current status of MSCAN module through Callback function.
     * It is insignificance without a available callback function.
     */
    if (handle->callback != NULL)
    {
        MSCAN_EnableRxInterrupts(base,
                                 (uint8_t)kMSCAN_StatusChangeInterruptEnable | (uint8_t)kMSCAN_WakeUpInterruptEnable);
    }
    else
    {
        MSCAN_DisableRxInterrupts(base,
                                  (uint8_t)kMSCAN_StatusChangeInterruptEnable | (uint8_t)kMSCAN_WakeUpInterruptEnable);
    }

    /* Enable interrupts in NVIC. */
    (void)EnableIRQ((IRQn_Type)(s_mscanRxWarningIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_mscanTxWarningIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_mscanWakeUpIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_mscanErrorIRQ[instance]));
}

/*!
 * brief Sends a message using IRQ.
 *
 * This function sends a message using IRQ. This is a non-blocking function, which returns
 * right away. When messages have been sent out, the send callback function is called.
 *
 * param base MsCAN peripheral base address.
 * param handle MsCAN handle pointer.
 * param xfer MsCAN Message Buffer transfer structure. See the #mscan_mb_transfer_t.
 * retval kStatus_Success        Start Tx Message Buffer sending process successfully.
 * retval kStatus_Fail           Write Tx Message Buffer failed.
 * retval kStatus_MSCAN_DataLengthError - Tx Message Buffer data length is wrong.
 */
status_t MSCAN_TransferSendNonBlocking(CAN_Type *base, mscan_handle_t *handle, mscan_mb_transfer_t *xfer)
{
    /* Assertion. */
    assert(NULL != handle);
    assert(NULL != xfer);

    status_t status;

    /* Check if Message Buffer is idle. */

    /* Distinguish transmit type. */
    if (kMSCAN_FrameTypeRemote == xfer->frame->type)
    {
        handle->mbStateTx = (uint8_t)kMSCAN_StateTxRemote;

        /* Register user Frame buffer to receive remote Frame. */
        handle->mbFrameBuf = xfer->frame;
    }
    else
    {
        handle->mbStateTx = (uint8_t)kMSCAN_StateTxData;
    }

    status = MSCAN_WriteTxMb(base, xfer->frame);

    if (kStatus_Success == status)
    {
        /* Enable Message Buffer Interrupt. */
        MSCAN_EnableTxInterrupts(base, xfer->mask);
    }
    else
    {
        handle->mbStateTx = (uint8_t)kMSCAN_StateIdle;
    }

    return status;
}

/*!
 * brief Receives a message using IRQ.
 *
 * This function receives a message using IRQ. This is non-blocking function, which returns
 * right away. When the message has been received, the receive callback function is called.
 *
 * param base MsCAN peripheral base address.
 * param handle MsCAN handle pointer.
 * param xfer MsCAN Message Buffer transfer structure. See the #mscan_mb_transfer_t.
 * retval kStatus_Success        - Start Rx Message Buffer receiving process successfully.
 * retval kStatus_MSCAN_RxBusy - Rx Message Buffer is in use.
 */
status_t MSCAN_TransferReceiveNonBlocking(CAN_Type *base, mscan_handle_t *handle, mscan_mb_transfer_t *xfer)
{
    /* Assertion. */
    assert(NULL != handle);
    assert(NULL != xfer);

    status_t status;

    /* Check if Message Buffer is idle. */
    if ((uint8_t)kMSCAN_StateIdle == handle->mbStateRx)
    {
        handle->mbStateRx = (uint8_t)kMSCAN_StateRxData;

        /* Register Message Buffer. */
        handle->mbFrameBuf = xfer->frame;

        /* Enable Message Buffer Interrupt. */
        MSCAN_EnableRxInterrupts(base, xfer->mask);

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_MSCAN_RxBusy;
    }

    return status;
}

/*!
 * brief Aborts the interrupt driven message send process.
 *
 * This function aborts the interrupt driven message send process.
 *
 * param base MsCAN peripheral base address.
 * param handle MsCAN handle pointer.
 * param mask The MsCAN Tx Message Buffer mask.
 */
void MSCAN_TransferAbortSend(CAN_Type *base, mscan_handle_t *handle, uint8_t mask)
{
    /* Assertion. */
    assert(NULL != handle);

    /* Abort Tx request. */
    MSCAN_AbortTxRequest(base, mask);

    /* Clean Message Buffer. */
    MSCAN_DisableTxInterrupts(base, mask);

    handle->mbStateTx = (uint8_t)kMSCAN_StateIdle;
}

/*!
 * brief Aborts the interrupt driven message receive process.
 *
 * This function aborts the interrupt driven message receive process.
 *
 * param base MsCAN peripheral base address.
 * param handle MsCAN handle pointer.
 * param mask The MsCAN Rx Message Buffer mask.
 */
void MSCAN_TransferAbortReceive(CAN_Type *base, mscan_handle_t *handle, uint8_t mask)
{
    /* Assertion. */
    assert(NULL != handle);

    /* Disable Message Buffer Interrupt. */
    MSCAN_DisableRxInterrupts(base, mask);

    /* Un-register handle. */
    handle->mbStateRx = (uint8_t)kMSCAN_StateIdle;
}

/*!
 * brief MSCAN IRQ handle function.
 *
 * This function handles the MSCAN Error, the Message Buffer, and the Rx FIFO IRQ request.
 *
 * param base MSCAN peripheral base address.
 * param handle MSCAN handle pointer.
 */
void MSCAN_TransferHandleIRQ(CAN_Type *base, mscan_handle_t *handle)
{
    /* Assertion. */
    assert(NULL != handle);

    status_t status = kStatus_MSCAN_UnHandled;

    /* Get current State of Message Buffer. */
    if (0U != MSCAN_GetRxBufferFullFlag(base))
    {
        switch (handle->mbStateRx)
        {
            /* Solve Rx Data Frame. */
            case (uint8_t)kMSCAN_StateRxData:
                status = MSCAN_ReadRxMb(base, handle->mbFrameBuf);
                if (kStatus_Success == status)
                {
                    status = kStatus_MSCAN_RxIdle;
                }
                MSCAN_TransferAbortReceive(base, handle, (uint8_t)kMSCAN_RxFullInterruptEnable);
                break;

            /* Solve Rx Remote Frame. */
            case (uint8_t)kMSCAN_StateRxRemote:
                status = MSCAN_ReadRxMb(base, handle->mbFrameBuf);
                if (kStatus_Success == status)
                {
                    status = kStatus_MSCAN_RxIdle;
                }
                MSCAN_TransferAbortReceive(base, handle, (uint8_t)kMSCAN_RxFullInterruptEnable);
                break;

            default:
                /* To avoid MISRA-C 2012 rule 16.4 issue. */
                break;
        }
        MSCAN_ClearRxBufferFullFlag(base);
    }
    else
    {
        switch (handle->mbStateTx)
        {
            /* Solve Tx Data Frame. */
            case (uint8_t)kMSCAN_StateTxData:
                status = kStatus_MSCAN_TxIdle;
                MSCAN_TransferAbortSend(base, handle, (uint8_t)kMSCAN_TxEmptyInterruptEnable);
                break;

            /* Solve Tx Remote Frame. */
            case (uint8_t)kMSCAN_StateTxRemote:
                handle->mbStateRx = (uint8_t)kMSCAN_StateRxRemote;
                status            = kStatus_MSCAN_TxSwitchToRx;
                break;

            default:
                status = kStatus_MSCAN_UnHandled;
                break;
        }
    }

    handle->callback(base, handle, status, handle->userData);
}

void CAN0_DriverIRQHandler(void);
void CAN0_DriverIRQHandler(void)
{
    assert(NULL != s_mscanHandle[0]);

    s_mscanIsr(CAN0, s_mscanHandle[0]);
}
