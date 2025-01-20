/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexcan.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_flexcan"
#endif

#if (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032)
#define RXINTERMISSION (CAN_DBG1_CFSM(0x2f))
#define TXINTERMISSION (CAN_DBG1_CFSM(0x14))
#define BUSIDLE        (CAN_DBG1_CFSM(0x02))
#define CBN_VALUE3     (CAN_DBG1_CBN(0x03))
#define DELAY_BUSIDLE  (200)
#endif

/* According to CiA doc 1301 v1.0.0, specified data/nominal phase sample point postion for CAN FD at 80 MHz. */
#define IDEAL_DATA_SP_1  (800UL)
#define IDEAL_DATA_SP_2  (750UL)
#define IDEAL_DATA_SP_3  (700UL)
#define IDEAL_DATA_SP_4  (625UL)
#define IDEAL_NOMINAL_SP (800UL)

/* According to CiA doc 301 v4.2.0 and previous version. */
#define IDEAL_SP_LOW  (750UL)
#define IDEAL_SP_MID  (800UL)
#define IDEAL_SP_HIGH (875UL)

#define IDEAL_SP_FACTOR (1000UL)

/* Define the max value of bit timing segments when use different timing register. */
#define MAX_PROPSEG           ((CAN_CTRL1_PROPSEG_MASK >> CAN_CTRL1_PROPSEG_SHIFT) + 1U)
#define MAX_PSEG1             ((CAN_CTRL1_PSEG1_MASK >> CAN_CTRL1_PSEG1_SHIFT) + 1U)
#define MAX_PSEG2             ((CAN_CTRL1_PSEG2_MASK >> CAN_CTRL1_PSEG2_SHIFT) + 1U)
#define MAX_RJW               ((CAN_CTRL1_RJW_MASK >> CAN_CTRL1_RJW_SHIFT) + 1U)
#define MAX_PRESDIV           ((CAN_CTRL1_PRESDIV_MASK >> CAN_CTRL1_PRESDIV_SHIFT) + 1U)
#define CTRL1_MAX_TIME_QUANTA (1U + MAX_PROPSEG + MAX_PSEG1 + MAX_PSEG2)
#define CTRL1_MIN_TIME_QUANTA (8U)

/* Information Processing Time value. */
#define INFO_PROCESS_TIME (2U)

/* Define maximum classic CAN bit rate supported by FLEXCAN. */
#define MAX_CAN_BAUDRATE (1000000U)

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
#define MAX_EPROPSEG        ((CAN_CBT_EPROPSEG_MASK >> CAN_CBT_EPROPSEG_SHIFT) + 1U)
#define MAX_EPSEG1          ((CAN_CBT_EPSEG1_MASK >> CAN_CBT_EPSEG1_SHIFT) + 1U)
#define MAX_EPSEG2          ((CAN_CBT_EPSEG2_MASK >> CAN_CBT_EPSEG2_SHIFT) + 1U)
#define MAX_ERJW            ((CAN_CBT_ERJW_MASK >> CAN_CBT_ERJW_SHIFT) + 1U)
#define MAX_EPRESDIV        ((CAN_CBT_EPRESDIV_MASK >> CAN_CBT_EPRESDIV_SHIFT) + 1U)
#define CBT_MAX_TIME_QUANTA (1U + MAX_EPROPSEG + MAX_EPSEG1 + MAX_EPSEG2)
#define CBT_MIN_TIME_QUANTA (8U)

#define MAX_PROP(x) ((x) ? (MAX_EPROPSEG) : (MAX_PROPSEG))
#define MAX_SEG1(x) ((x) ? (MAX_EPSEG1) : (MAX_PSEG1))
#define MAX_SEG2(x) ((x) ? (MAX_EPSEG2) : (MAX_PSEG2))
#define MAX_SWJ(x)  ((x) ? (MAX_ERJW) : (MAX_RJW))
#define MAX_DIV(x)  ((x) ? (MAX_EPRESDIV) : (MAX_PRESDIV))

#define MAX_FPROPSEG          (CAN_FDCBT_FPROPSEG_MASK >> CAN_FDCBT_FPROPSEG_SHIFT)
#define MAX_FPSEG1            ((CAN_FDCBT_FPSEG1_MASK >> CAN_FDCBT_FPSEG1_SHIFT) + 1U)
#define MAX_FPSEG2            ((CAN_FDCBT_FPSEG2_MASK >> CAN_FDCBT_FPSEG2_SHIFT) + 1U)
#define MAX_FRJW              ((CAN_FDCBT_FRJW_MASK >> CAN_FDCBT_FRJW_SHIFT) + 1U)
#define MAX_FPRESDIV          ((CAN_FDCBT_FPRESDIV_MASK >> CAN_FDCBT_FPRESDIV_SHIFT) + 1U)
#define FDCBT_MAX_TIME_QUANTA (1U + MAX_FPROPSEG + MAX_FPSEG1 + MAX_FPSEG2)
#define FDCBT_MIN_TIME_QUANTA (5U)

#define MAX_TDCOFF (CAN_FDCTRL_TDCOFF_MASK >> CAN_FDCTRL_TDCOFF_SHIFT)

/* Define maximum CAN FD bit rate supported by FLEXCAN. */
#define MAX_CANFD_BAUDRATE (8000000U)
#else
#define MAX_PROP(x) (MAX_PROPSEG)
#define MAX_SEG1(x) (MAX_PSEG1)
#define MAX_SEG2(x) (MAX_PSEG2)
#define MAX_SWJ(x)  (MAX_RJW)
#define MAX_DIV(x)  (MAX_PRESDIV)
#endif

#if (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_9595) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_9595)
#define CAN_ESR1_FLTCONF_BUSOFF CAN_ESR1_FLTCONF(2U)
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#ifndef CAN_CLOCK_CHECK_NO_AFFECTS
/* If no define such MACRO, it mean that the CAN in current device have no clock affect issue. */
#define CAN_CLOCK_CHECK_NO_AFFECTS (true)
#endif /* CAN_CLOCK_CHECK_NO_AFFECTS */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief FlexCAN Internal State. */
enum _flexcan_state
{
    kFLEXCAN_StateIdle     = 0x0, /*!< MB/RxFIFO idle.*/
    kFLEXCAN_StateRxData   = 0x1, /*!< MB receiving.*/
    kFLEXCAN_StateRxRemote = 0x2, /*!< MB receiving remote reply.*/
    kFLEXCAN_StateTxData   = 0x3, /*!< MB transmitting.*/
    kFLEXCAN_StateTxRemote = 0x4, /*!< MB transmitting remote request.*/
    kFLEXCAN_StateRxFifo   = 0x5, /*!< RxFIFO receiving.*/
};

/*! @brief FlexCAN message buffer CODE for Rx buffers. */
enum _flexcan_mb_code_rx
{
    kFLEXCAN_RxMbInactive = 0x0, /*!< MB is not active.*/
    kFLEXCAN_RxMbFull     = 0x2, /*!< MB is full.*/
    kFLEXCAN_RxMbEmpty    = 0x4, /*!< MB is active and empty.*/
    kFLEXCAN_RxMbOverrun  = 0x6, /*!< MB is overwritten into a full buffer.*/
    kFLEXCAN_RxMbBusy     = 0x8, /*!< FlexCAN is updating the contents of the MB.*/
                                 /*!  The CPU must not access the MB.*/
    kFLEXCAN_RxMbRanswer = 0xA,  /*!< A frame was configured to recognize a Remote Request Frame */
                                 /*!  and transmit a Response Frame in return.*/
    kFLEXCAN_RxMbNotUsed = 0xF,  /*!< Not used.*/
};

/*! @brief FlexCAN message buffer CODE FOR Tx buffers. */
enum _flexcan_mb_code_tx
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
typedef void (*flexcan_isr_t)(flexcan_handle_t *psHandle);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @name Debug Utilities
 * @{
 */
#if !defined(NDEBUG)
/*!
 * @brief Check if Message Buffer is occupied by Rx FIFO.
 *
 * This function check if Message Buffer is occupied by Rx FIFO.
 *
 * @param base FlexCAN peripheral base address.
 * @param u8MsgBufIdx The FlexCAN Message Buffer index.
 */
static bool FLEXCAN_IsMbOccupied(CAN_Type *base, uint8_t u8MsgBufIdx);
#endif

#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
/*!
 * @brief Get the first valid Message buffer ID of give FlexCAN instance.
 *
 * This function is a helper function for Errata 5641 workaround.
 *
 * @param base FlexCAN peripheral base address.
 * @return The first valid Message Buffer Number.
 */
static uint8_t FLEXCAN_GetFirstValidMb(CAN_Type *base);
#endif

/* @} */

/*!
 * @brief Check if Message Buffer interrupt is enabled.
 *
 * This function check if Message Buffer interrupt is enabled.
 *
 * @param base FlexCAN peripheral base address.
 * @param u8MsgBufIdx The FlexCAN Message Buffer index.
 * @return TRUE if the index MB interrupt mask enabled, FALSE if the index MB interrupt mask disabled.
 *
 */
static bool FLEXCAN_IsMbIntEnabled(CAN_Type *base, uint8_t u8MsgBufIdx);

/*!
 * @brief Reset the FlexCAN Instance.
 *
 * Restores the FlexCAN module to reset state, notice that this function
 * will set all the registers to reset state so the FlexCAN module can not work
 * after calling this API.
 *
 * @param base FlexCAN peripheral base address.
 */
static void FLEXCAN_Reset(CAN_Type *base);

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
/*!
 * @brief Get Mailbox offset number by dword.
 *
 * This function gets the offset number of the specified mailbox.
 * Mailbox is not consecutive between memory regions when payload is not 8 bytes
 * so need to calculate the specified mailbox address.
 * For example, in the first memory region, MB[0].CS address is 0x4002_4080. For 32 bytes
 * payload frame, the second mailbox is ((1/12)*512 + 1%12*40)/4 = 10, meaning 10 dword
 * after the 0x4002_4080, which is actually the address of mailbox MB[1].CS.
 *
 * @param base FlexCAN peripheral base address.
 * @param u8MsgBufIdx Mailbox index.
 */
static uint32_t FLEXCAN_GetFDMailboxOffset(CAN_Type *base, uint8_t u8MsgBufIdx);

#endif

/*!
 * @brief Check unhandle interrupt events
 *
 * @param base FlexCAN peripheral base address.
 * @return TRUE if unhandled interrupt action exist, FALSE if no unhandlered interrupt action exist.
 */
static bool FLEXCAN_CheckUnhandleInterruptEvents(CAN_Type *base);

/*!
 * @brief Sub Handler Data Trasfered Events
 *
 * @param base FlexCAN peripheral base address.
 * @param psHandle FlexCAN handle pointer.
 * @param pResult Pointer to the Handle result.
 * @return the status after handle each data transfered event.
 */
static status_t FLEXCAN_SubHandlerForDataTransfered(CAN_Type *base, flexcan_handle_t *psHandle, uint32_t *pResult);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Array of FlexCAN peripheral base address. */
static CAN_Type *const s_flexcanBases[] = CAN_BASE_PTRS;

/* Array of FlexCAN IRQ number. */
static const IRQn_Type s_flexcanRxWarningIRQ[] = CAN_Rx_Warning_IRQS;
static const IRQn_Type s_flexcanTxWarningIRQ[] = CAN_Tx_Warning_IRQS;
static const IRQn_Type s_flexcanWakeUpIRQ[]    = CAN_Wake_Up_IRQS;
static const IRQn_Type s_flexcanErrorIRQ[]     = CAN_Error_IRQS;
static const IRQn_Type s_flexcanBusOffIRQ[]    = CAN_Bus_Off_IRQS;
static const IRQn_Type s_flexcanMbIRQ[]        = CAN_ORed_Message_buffer_IRQS;

/* Array of FlexCAN handle. */
static flexcan_handle_t *s_flexcanHandle[ARRAY_SIZE(s_flexcanBases)];

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Array of FlexCAN clock name. */
static const clock_ip_name_t s_flexcanClock[] = FLEXCAN_CLOCKS;
#if defined(FLEXCAN_PERIPH_CLOCKS)
/* Array of FlexCAN serial clock name. */
static const clock_ip_name_t s_flexcanPeriphClock[] = FLEXCAN_PERIPH_CLOCKS;
#endif /* FLEXCAN_PERIPH_CLOCKS */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/* FlexCAN ISR for transactional APIs. */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
static flexcan_isr_t s_flexcanIsr = (flexcan_isr_t)DefaultISR;
#else
static flexcan_isr_t s_flexcanIsr;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @name Misc Utility
 * @{
 */

uint32_t FLEXCAN_GetInstance(CAN_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_flexcanBases); instance++)
    {
        if (s_flexcanBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_flexcanBases));

    return instance;
}

/* @} */

/*!
 * @name Initialization and deinitialization
 * @{
 */

void FLEXCAN_Init(CAN_Type *base, const flexcan_config_t *psConfig)
{
    /* Assertion. */
    assert(NULL != psConfig);
    assert((psConfig->u8MaxMsgBufNum > 0U) &&
           (psConfig->u8MaxMsgBufNum <= (uint8_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base)));

    uint32_t mcrTemp;
    uint32_t ctrl1Temp;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint32_t instance;
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    instance = FLEXCAN_GetInstance(base);
    /* Enable FlexCAN clock. */
    CLOCK_EnableClock(s_flexcanClock[instance]);
    /*
     * Check the CAN clock in this device whether affected by Other clock gate
     * If it affected, we'd better to change other clock source,
     * If user insist on using that clock source, user need open these gate at same time,
     * In this scene, User need to care the power consumption.
     */
    assert(CAN_CLOCK_CHECK_NO_AFFECTS);
#if defined(FLEXCAN_PERIPH_CLOCKS)
    /* Enable FlexCAN serial clock. */
    CLOCK_EnableClock(s_flexcanPeriphClock[instance]);
#endif /* FLEXCAN_PERIPH_CLOCKS */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(CAN_CTRL1_CLKSRC_MASK)
#if (defined(FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE) && FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE)
    if (0 == FSL_FEATURE_FLEXCAN_INSTANCE_SUPPORT_ENGINE_CLK_SEL_REMOVEn(base))
#endif /* FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE */
    {
        /* Disable FlexCAN Module. */
        FLEXCAN_Enable(base, false);

        /* Protocol-Engine clock source selection, This bit must be set
         * when FlexCAN Module in Disable Mode.
         */
        base->CTRL1 = (kFLEXCAN_ClkSrc0 == psConfig->eClkSrc) ? (base->CTRL1 & ~CAN_CTRL1_CLKSRC_MASK) :
                                                                (base->CTRL1 | CAN_CTRL1_CLKSRC_MASK);
    }
#endif /* CAN_CTRL1_CLKSRC_MASK */

    /* Enable FlexCAN Module for configuration. */
    FLEXCAN_Enable(base, true);

    /* Reset to known status. */
    FLEXCAN_Reset(base);

    /* Save current CTRL1 value and enable to enter Freeze mode(enabled by default). */
    ctrl1Temp = base->CTRL1;

    /* Save current MCR value and enable to enter Freeze mode(enabled by default). */
    mcrTemp = base->MCR;

    /* Enable Loop Back Mode? */
    ctrl1Temp = (psConfig->bEnableLoopBack) ? (ctrl1Temp | CAN_CTRL1_LPB_MASK) : (ctrl1Temp & ~CAN_CTRL1_LPB_MASK);

    /* Enable Timer Sync? */
    ctrl1Temp = (psConfig->bEnableTimerSync) ? (ctrl1Temp | CAN_CTRL1_TSYN_MASK) : (ctrl1Temp & ~CAN_CTRL1_TSYN_MASK);

    /* Enable Listen Only Mode? */
    ctrl1Temp = (psConfig->bEnableListenOnlyMode) ? ctrl1Temp | CAN_CTRL1_LOM_MASK : ctrl1Temp & ~CAN_CTRL1_LOM_MASK;

    /* Set the maximum number of Message Buffers */
    mcrTemp = (mcrTemp & ~CAN_MCR_MAXMB_MASK) | CAN_MCR_MAXMB((uint32_t)psConfig->u8MaxMsgBufNum - 1U);

    /* Enable Self Wake Up Mode and configure the wake up source. */
    mcrTemp = (psConfig->bEnableSelfWakeup) ? (mcrTemp | CAN_MCR_SLFWAK_MASK) : (mcrTemp & ~CAN_MCR_SLFWAK_MASK);
    mcrTemp = (kFLEXCAN_WakeupSrcFiltered == psConfig->eWakeupSrc) ? (mcrTemp | CAN_MCR_WAKSRC_MASK) :
                                                                     (mcrTemp & ~CAN_MCR_WAKSRC_MASK);

    /* Enable Individual Rx Masking? */
    mcrTemp = (psConfig->bEnableIndividMask) ? (mcrTemp | CAN_MCR_IRMQ_MASK) : (mcrTemp & ~CAN_MCR_IRMQ_MASK);

    /* Disable Self Reception? */
    mcrTemp = (psConfig->bDisableSelfReception) ? mcrTemp | CAN_MCR_SRXDIS_MASK : mcrTemp & ~CAN_MCR_SRXDIS_MASK;

#if (defined(FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT) && FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT)
    if (0 != FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(base))
    {
        /* Enable Doze Mode? */
        mcrTemp = (psConfig->bEnableDoze) ? (mcrTemp | CAN_MCR_DOZE_MASK) : (mcrTemp & ~CAN_MCR_DOZE_MASK);
    }
#endif

    /* Write back CTRL1 Configuration to register. */
    base->CTRL1 = ctrl1Temp;

#if (defined(FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL) && FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL)
    /* Enable to update in MCER. */
    base->CTRL2 |= CAN_CTRL2_ECRWRE_MASK;
    base->MECR &= ~CAN_MECR_ECRWRDIS_MASK;
#endif

    /* Write back MCR Configuration to register. */
    base->MCR = mcrTemp;

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
    /* Set the CAN FD Part */
    if (psConfig->psFDConfig != NULL)
    {
        uint32_t fdctrl = 0U;

        fdctrl = base->FDCTRL;

        /* Enable FD operation and set bitrate switch. */
        if (psConfig->psFDConfig->bEnableBitRateSwitch)
        {
            fdctrl |= CAN_FDCTRL_FDRATE_MASK;
        }
        else
        {
            fdctrl &= ~CAN_FDCTRL_FDRATE_MASK;
        }

        /* Setup the transmit delay to define a secondary sample point */
        if (psConfig->psFDConfig->bEnableBitRateSwitch && !(psConfig->bEnableLoopBack))
        {
            fdctrl =
                (fdctrl & ~CAN_FDCTRL_TDCEN_MASK) | CAN_FDCTRL_TDCEN(psConfig->psFDConfig->bEnableTxDelayCompensation);
        }

        /* Setup the region size for message buff */
        fdctrl = (fdctrl & ~CAN_FDCTRL_MBDSR0_MASK) | CAN_FDCTRL_MBDSR0(psConfig->psFDConfig->eMsgSize);
#if defined(CAN_FDCTRL_MBDSR1_MASK)
        fdctrl = (fdctrl & ~CAN_FDCTRL_MBDSR1_MASK) | CAN_FDCTRL_MBDSR1(psConfig->psFDConfig->eMsgSize);
#endif
#if defined(CAN_FDCTRL_MBDSR2_MASK)
        fdctrl = (fdctrl & ~CAN_FDCTRL_MBDSR2_MASK) | CAN_FDCTRL_MBDSR2(psConfig->psFDConfig->eMsgSize);
#endif
#if defined(CAN_FDCTRL_MBDSR3_MASK)
        fdctrl = (fdctrl & ~CAN_FDCTRL_MBDSR3_MASK) | CAN_FDCTRL_MBDSR3(psConfig->psFDConfig->eMsgSize);
#endif

        /* Enter Freeze Mode. */
        FLEXCAN_EnterFreezeMode(base);

        /* Enable CAN FD operation. */
        base->MCR |= CAN_MCR_FDEN_MASK;
        /* Clear SMP bit when CAN FD is enabled (CAN FD only can use one regular sample point plus one optional
         * secondary sampling point). */
        base->CTRL1 &= ~CAN_CTRL1_SMP_MASK;

        /* update the FDCTL register. */
        base->FDCTRL = fdctrl;

        /* Enable CAN FD ISO mode by default. */
        base->CTRL2 |= CAN_CTRL2_ISOCANFDEN_MASK;

        /* Exit Freeze Mode. */
        FLEXCAN_ExitFreezeMode(base);

        /* Extra bit timing setting for CANFD. */
        if ((psConfig->psFDConfig->bEnableBitRateSwitch) && (!psConfig->bEnableTimingCalc))
        {
            FLEXCAN_SetFDTimingConfig(base, &psConfig->psFDConfig->sTimingConfig);
        }
    }
#endif

    if (psConfig->bEnableTimingCalc)
    {
        /* Calculate the bit timing. When the clock frequency and bit rate do not match, the
         * FLEXCAN_SetBaudRate/FLEXCAN_SetFDBaudRate APIs will use a default bit timing value (10 Tq with 80% SP for
         * classical CAN or CAN FD nominal phase, 5 Tq with 60% SP for CAN FD data phase), and the final bit rate will
         * have some errors. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
        if (psConfig->psFDConfig != NULL)
        {
            if (psConfig->psFDConfig->bEnableBitRateSwitch)
            {
                (void)FLEXCAN_SetFDBaudRate(base, psConfig->u32ClkFreqHz, psConfig->u32BaudRateBps,
                                            psConfig->psFDConfig->u32BaudRateBps);
            }
            else
            {
                (void)FLEXCAN_SetBaudRate(base, psConfig->u32ClkFreqHz, psConfig->u32BaudRateBps);
            }
        }
        else
        {
            (void)FLEXCAN_SetBaudRate(base, psConfig->u32ClkFreqHz, psConfig->u32BaudRateBps);
        }
#else
        (void)FLEXCAN_SetBaudRate(base, psConfig->u32ClkFreqHz, psConfig->u32BaudRateBps);
#endif
    }
    else
    {
        /* Set classic CAN bit timing characteristic base on user's precise values passed as flexcan_timing_config_t. */
        FLEXCAN_SetTimingConfig(base, &psConfig->sTimingConfig);
    }
}

void FLEXCAN_Deinit(CAN_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    uint32_t instance;
#endif
    /* Reset all Register Contents. */
    FLEXCAN_Reset(base);

    /* Disable FlexCAN module. */
    FLEXCAN_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    instance = FLEXCAN_GetInstance(base);
#if defined(FLEXCAN_PERIPH_CLOCKS)
    /* Disable FlexCAN serial clock. */
    CLOCK_DisableClock(s_flexcanPeriphClock[instance]);
#endif /* FLEXCAN_PERIPH_CLOCKS */
    /* Disable FlexCAN clock. */
    CLOCK_DisableClock(s_flexcanClock[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void FLEXCAN_GetDefaultConfig(flexcan_config_t *psConfig, uint32_t u32ClkFreqHz)
{
    /* Assertion. */
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    /* Initialize FlexCAN Module config struct with default value. */
    psConfig->bEnableTimingCalc     = true;
    psConfig->u32ClkFreqHz          = u32ClkFreqHz;
    psConfig->eClkSrc               = kFLEXCAN_ClkSrc0;
    psConfig->u32BaudRateBps        = 500000U;
    psConfig->u8MaxMsgBufNum        = 16;
    psConfig->bEnableLoopBack       = false;
    psConfig->bEnableTimerSync      = true;
    psConfig->bEnableSelfWakeup     = false;
    psConfig->eWakeupSrc            = kFLEXCAN_WakeupSrcUnfiltered;
    psConfig->bEnableIndividMask    = false;
    psConfig->bDisableSelfReception = false;
    psConfig->bEnableListenOnlyMode = false;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT) && FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT)
    psConfig->bEnableDoze = false;
#endif

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
    /* By default not setting the FD Config, Call FLEXCAN_GetFDDefaultConfig for FD Feature */
    psConfig->psFDConfig = NULL;
#endif
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
void FLEXCAN_GetFDDefaultConfig(flexcan_config_t *psConfig, flexcan_fd_config_t *psFDConfig)
{
    /* Assertion. */
    assert((NULL != psConfig) && (NULL != psFDConfig));

    /* Initializes the configure structure to zero. */
    (void)memset(psFDConfig, 0, sizeof(*psFDConfig));
    /* Default Configuration */
    psFDConfig->u32BaudRateBps             = 2000000U;
    psFDConfig->eMsgSize                   = kFLEXCAN_64BperMB;
    psFDConfig->bEnableTxDelayCompensation = true;
    psFDConfig->bEnableBitRateSwitch       = true;
    psConfig->psFDConfig                   = psFDConfig;
}
#endif
/* @} */

/*!
 * @name Freeze Mode Operation
 * @{
 */

#if (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_9595) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_9595)
void FLEXCAN_EnterFreezeMode(CAN_Type *base)
{
    uint32_t u32TimeoutCount = 0U;
    uint32_t u32TempMCR      = 0U;
    uint32_t u32TempIMASK1   = 0U;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint32_t u32TempIMASK2 = 0U;
#endif

    /* Step1: set FRZ enable in MCR. */
    base->MCR |= CAN_MCR_FRZ_MASK;

    /* Step2: to check if MDIS bit set in MCR. if yes, clear it. */
    if (0U != (base->MCR & CAN_MCR_MDIS_MASK))
    {
        base->MCR &= ~CAN_MCR_MDIS_MASK;
    }

    /* Step3: polling LPMACK. */
    u32TimeoutCount = (uint32_t)FLEXCAN_WAIT_TIMEOUT;
    while ((0U == (base->MCR & CAN_MCR_LPMACK_MASK)) && (u32TimeoutCount > 0U))
    {
        u32TimeoutCount--;
    }

    /* Step4: to check FLTCONF in ESR1 register */
    if (0U == (base->ESR1 & CAN_ESR1_FLTCONF_BUSOFF))
    {
        /* Step5B: Set Halt bits. */
        base->MCR |= CAN_MCR_HALT_MASK;

        /* Step6B: Poll the MCR register until the Freeze Acknowledge (FRZACK) bit is set, timeout need more than 178
         * CAN bit length, so 20 multiply timeout is enough. */
        u32TimeoutCount = (uint32_t)FLEXCAN_WAIT_TIMEOUT * 20U;
        while ((0U == (base->MCR & CAN_MCR_FRZACK_MASK)) && (u32TimeoutCount > 0U))
        {
            u32TimeoutCount--;
        }
    }
    else
    {
        /* backup MCR and IMASK register. Errata document not descript it, but we need backup for step 8A and 9A. */
        u32TempMCR    = base->MCR;
        u32TempIMASK1 = base->IMASK1;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        u32TempIMASK2 = base->IMASK2;
#endif

        /* Step5A: Set the Soft Reset bit ((SOFTRST) in the MCR.*/
        base->MCR |= CAN_MCR_SOFTRST_MASK;

        /* Step6A: Poll the MCR register until the Soft Reset (SOFTRST) bit is cleared. */
        u32TimeoutCount = (uint32_t)FLEXCAN_WAIT_TIMEOUT;
        while ((CAN_MCR_SOFTRST_MASK == (base->MCR & CAN_MCR_SOFTRST_MASK)) && (u32TimeoutCount > 0U))
        {
            u32TimeoutCount--;
        }

        /* Step7A: Poll the MCR register until the Freeze Acknowledge (FRZACK) bit is set. */
        u32TimeoutCount = (uint32_t)FLEXCAN_WAIT_TIMEOUT;
        while ((0U == (base->MCR & CAN_MCR_FRZACK_MASK)) && (u32TimeoutCount > 0U))
        {
            u32TimeoutCount--;
        }

        /* Step8A: reconfig MCR. */
        base->MCR = u32TempMCR;

        /* Step9A: reconfig IMASK. */
        base->IMASK1 = u32TempIMASK1;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        base->IMASK2 = u32TempIMASK2;
#endif
    }
}
#elif (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_8341) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_8341)
void FLEXCAN_EnterFreezeMode(CAN_Type *base)
{
    uint32_t u32TimeoutCount = 0U;
    uint32_t u32TempMCR      = 0U;
    uint32_t u32TempIMASK1   = 0U;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint32_t u32TempIMASK2   = 0U;
#endif

    /* Step1: set FRZ and HALT bit enable in MCR. */
    base->MCR |= CAN_MCR_FRZ_MASK;
    base->MCR |= CAN_MCR_HALT_MASK;

    /* Step2: to check if MDIS bit set in MCR. if yes, clear it. */
    if (0U != (base->MCR & CAN_MCR_MDIS_MASK))
    {
        base->MCR &= ~CAN_MCR_MDIS_MASK;
    }

    /* Step3: Poll the MCR register until the Freeze Acknowledge (FRZACK) bit is set. */
    u32TimeoutCount = (uint32_t)FLEXCAN_WAIT_TIMEOUT * 100U;
    while ((0U == (base->MCR & CAN_MCR_FRZACK_MASK)) && (u32TimeoutCount > 0U))
    {
        u32TimeoutCount--;
    }

    /* Step4: check whether the timeout reached. if no skip step5 to step8. */
    if (0U == u32TimeoutCount)
    {
        /* backup MCR and IMASK register. Errata document not descript it, but we need backup for step 8A and 9A. */
        u32TempMCR    = base->MCR;
        u32TempIMASK1 = base->IMASK1;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        u32TempIMASK2 = base->IMASK2;
#endif
        /* Step5: Set the Soft Reset bit ((SOFTRST) in the MCR.*/
        base->MCR |= CAN_MCR_SOFTRST_MASK;

        /* Step6: Poll the MCR register until the Soft Reset (SOFTRST) bit is cleared. */
        while (CAN_MCR_SOFTRST_MASK == (base->MCR & CAN_MCR_SOFTRST_MASK))
        {
        }

        /* Step7: reconfig MCR. */
        base->MCR = u32TempMCR;

        /* Step8: reconfig IMASK. */
        base->IMASK1 = u32TempIMASK1;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        base->IMASK2 = u32TempIMASK2;
#endif
    }
}
#else
void FLEXCAN_EnterFreezeMode(CAN_Type *base)
{
    /* Set Freeze, Halt bits. */
    base->MCR |= CAN_MCR_FRZ_MASK;
    base->MCR |= CAN_MCR_HALT_MASK;
    while (0U == (base->MCR & CAN_MCR_FRZACK_MASK))
    {
    }
}
#endif

void FLEXCAN_ExitFreezeMode(CAN_Type *base)
{
#if (defined(FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL) && FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL)
    /* Enable to update in MCER. */
    base->CTRL2 |= CAN_CTRL2_ECRWRE_MASK;
    base->MECR &= ~CAN_MECR_ECRWRDIS_MASK;
#endif

    /* Clear Freeze, Halt bits. */
    base->MCR &= ~CAN_MCR_HALT_MASK;
    base->MCR &= ~CAN_MCR_FRZ_MASK;

    /* Wait until the FlexCAN Module exit freeze mode. */
    while (0U != (base->MCR & CAN_MCR_FRZACK_MASK))
    {
    }
}
/* @} */

/*!
 * @name Timing Calculation Helper Functions
 * @{
 */
static void FLEXCAN_GetSegments(uint32_t u32IdealSp,
                                uint32_t u32TqNum,
                                flexcan_timing_config_t *psTimingConfig,
                                bool bUseCbt)
{
    uint32_t u32Seg1Temp;

    psTimingConfig->u8PhaseSeg2 = (uint8_t)(u32TqNum - (u32TqNum * u32IdealSp) / IDEAL_SP_FACTOR);

    if (psTimingConfig->u8PhaseSeg2 < INFO_PROCESS_TIME)
    {
        psTimingConfig->u8PhaseSeg2 = INFO_PROCESS_TIME;
    }
    else if (psTimingConfig->u8PhaseSeg2 > MAX_SEG2(bUseCbt))
    {
        psTimingConfig->u8PhaseSeg2 = (uint8_t)MAX_SEG2(bUseCbt);
    }
    else
    {
        ; /* Intentional empty */
    }
    /* Modify u8PhaseSeg2 to avoid out of range. */
    if ((u32TqNum - psTimingConfig->u8PhaseSeg2 - 1U) > (MAX_SEG1(bUseCbt) + MAX_PROP(bUseCbt)))
    {
        u32Seg1Temp                 = MAX_SEG1(bUseCbt) + MAX_PROP(bUseCbt);
        psTimingConfig->u8PhaseSeg2 = (uint8_t)(u32TqNum - 1U - u32Seg1Temp);
    }
    else
    {
        u32Seg1Temp = u32TqNum - psTimingConfig->u8PhaseSeg2 - 1U;
    }

    /* Calculates u8PhaseSeg1 and u8PropSeg, try to make phaseSeg1 equal to phaseSeg2. */
    if (u32Seg1Temp > (psTimingConfig->u8PhaseSeg2 + MAX_PROP(bUseCbt)))
    {
        psTimingConfig->u8PropSeg   = (uint8_t)MAX_PROP(bUseCbt);
        psTimingConfig->u8PhaseSeg1 = (uint8_t)(u32Seg1Temp - MAX_PROP(bUseCbt));
    }
    else
    {
        psTimingConfig->u8PropSeg   = (uint8_t)(u32Seg1Temp - psTimingConfig->u8PhaseSeg2);
        psTimingConfig->u8PhaseSeg1 = psTimingConfig->u8PhaseSeg2;
    }

    /* u8RJumpWidth (sjw) is the minimum value of u8PhaseSeg1 and u8PhaseSeg2. */
    psTimingConfig->u8RJumpWidth = (psTimingConfig->u8PhaseSeg1 > psTimingConfig->u8PhaseSeg2) ?
                                       psTimingConfig->u8PhaseSeg2 :
                                       psTimingConfig->u8PhaseSeg1;
    if (psTimingConfig->u8RJumpWidth > MAX_SWJ(bUseCbt))
    {
        psTimingConfig->u8RJumpWidth = (uint8_t)MAX_SWJ(bUseCbt);
    }
}

bool FLEXCAN_CalculateImprovedTimingValues(flexcan_timing_config_t *psTimingConfig,
                                           uint32_t u32BaudRateBps,
                                           uint32_t u32SrcClkHz)
{
    assert(NULL != psTimingConfig);

    uint32_t u32IdealSp                 = 0U;
    uint32_t u32TqNum                   = CTRL1_MAX_TIME_QUANTA;
    uint32_t u32SpTemp                  = 1000U;
    flexcan_timing_config_t sConfigTemp = {0};
    bool bResult                        = false;

    if (((u32SrcClkHz % u32BaudRateBps) != 0U) || (u32BaudRateBps > MAX_CAN_BAUDRATE))
    {
        return false;
    }
    /* Try to find the ideal sample point, according to CiA 301 doc.*/
    if (u32BaudRateBps == 1000000U)
    {
        u32IdealSp = IDEAL_SP_LOW;
    }
    else if (u32BaudRateBps >= 800000U)
    {
        u32IdealSp = IDEAL_SP_MID;
    }
    else
    {
        u32IdealSp = IDEAL_SP_HIGH;
    }

    do
    {
        if ((u32BaudRateBps * u32TqNum) > u32SrcClkHz)
        {
            continue; /* u32TqNum too large, u32ClkAfterDiv has been exceed u32SrcClkHz. */
        }

        if ((u32SrcClkHz % (u32BaudRateBps * u32TqNum)) != 0U)
        {
            continue; /* The frequency of clock source is not divisible by current u32ClkAfterDiv. */
        }

        sConfigTemp.u16PreDivider = (uint16_t)(u32SrcClkHz / (u32BaudRateBps * u32TqNum));
        if (sConfigTemp.u16PreDivider > MAX_PRESDIV)
        {
            break; /* The frequency of clock source is too large or the bit rate is too small, the pre-divider could
                      not handle it. */
        }

        /* Calculates the best timing configuration under current tqNum. */
        FLEXCAN_GetSegments(u32IdealSp, u32TqNum, &sConfigTemp, false);
        /* Determine whether the calculated timing configuration can get the optimal sampling point. */
        if ((((uint32_t)sConfigTemp.u8PhaseSeg2 * 1000U) / u32TqNum) < u32SpTemp)
        {
            u32SpTemp                     = ((uint32_t)sConfigTemp.u8PhaseSeg2 * 1000U) / u32TqNum;
            psTimingConfig->u16PreDivider = sConfigTemp.u16PreDivider;
            psTimingConfig->u8RJumpWidth  = sConfigTemp.u8RJumpWidth;
            psTimingConfig->u8PhaseSeg1   = sConfigTemp.u8PhaseSeg1;
            psTimingConfig->u8PhaseSeg2   = sConfigTemp.u8PhaseSeg2;
            psTimingConfig->u8PropSeg     = sConfigTemp.u8PropSeg;
        }
        bResult = true;
    } while (--u32TqNum >= CTRL1_MIN_TIME_QUANTA);

    return bResult;
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
static void FLEXCAN_FDGetSegments(uint32_t u32FDBaudRateBps,
                                  uint32_t u32TqNum,
                                  flexcan_timing_config_t *psFDTimingConfig)
{
    uint32_t u32Seg1Temp;

    /* According to CiA doc 1301 v1.0.0, which specified data phase sample point postion for CAN FD at 80 MHz. */
    if (u32FDBaudRateBps == 1000000U)
    {
        psFDTimingConfig->u8PhaseSeg2 = (uint8_t)(u32TqNum - (u32TqNum * IDEAL_DATA_SP_1) / IDEAL_SP_FACTOR);
    }
    else if (u32FDBaudRateBps <= 2000000U)
    {
        psFDTimingConfig->u8PhaseSeg2 = (uint8_t)(u32TqNum - (u32TqNum * IDEAL_DATA_SP_2) / IDEAL_SP_FACTOR);
    }
    else if (u32FDBaudRateBps <= 4000000U)
    {
        psFDTimingConfig->u8PhaseSeg2 = (uint8_t)(u32TqNum - (u32TqNum * IDEAL_DATA_SP_3) / IDEAL_SP_FACTOR);
    }
    else
    {
        psFDTimingConfig->u8PhaseSeg2 = (uint8_t)(u32TqNum - (u32TqNum * IDEAL_DATA_SP_4) / IDEAL_SP_FACTOR);
    }

    if (psFDTimingConfig->u8PhaseSeg2 < INFO_PROCESS_TIME)
    {
        psFDTimingConfig->u8PhaseSeg2 = INFO_PROCESS_TIME;
    }
    else if (psFDTimingConfig->u8PhaseSeg2 > MAX_FPSEG2)
    {
        psFDTimingConfig->u8PhaseSeg2 = (uint8_t)MAX_FPSEG2;
    }
    else
    {
        ; /* Intentional empty */
    }
    /* Modify u8PhaseSeg2 to avoid out of range. */
    if ((u32TqNum - psFDTimingConfig->u8PhaseSeg2 - 1U) > (MAX_FPSEG1 + MAX_FPROPSEG))
    {
        psFDTimingConfig->u8PhaseSeg2 = (uint8_t)(u32TqNum - 1U - MAX_FPSEG1 - MAX_FPROPSEG);
        u32Seg1Temp                   = MAX_FPSEG1 + MAX_FPROPSEG;
    }
    else
    {
        u32Seg1Temp = u32TqNum - psFDTimingConfig->u8PhaseSeg2 - 1U;
    }

    /* Calculates u8PhaseSeg1 and u8PropSeg, try to make phaseSeg1 equal to phaseSeg2. */
    if (u32Seg1Temp > (psFDTimingConfig->u8PhaseSeg2 + MAX_FPROPSEG))
    {
        psFDTimingConfig->u8PropSeg   = (uint8_t)MAX_FPROPSEG;
        psFDTimingConfig->u8PhaseSeg1 = (uint8_t)(u32Seg1Temp - MAX_FPROPSEG);
    }
    else if (u32Seg1Temp > psFDTimingConfig->u8PhaseSeg2)
    {
        psFDTimingConfig->u8PropSeg   = (uint8_t)(u32Seg1Temp - psFDTimingConfig->u8PhaseSeg2);
        psFDTimingConfig->u8PhaseSeg1 = psFDTimingConfig->u8PhaseSeg2;
    }
    else
    {
        psFDTimingConfig->u8PropSeg   = 0U;
        psFDTimingConfig->u8PhaseSeg1 = (uint8_t)u32Seg1Temp;
    }

    /* u8RJumpWidth (sjw) is the minimum value of u8PhaseSeg1 and u8PhaseSeg2. */
    psFDTimingConfig->u8RJumpWidth = (psFDTimingConfig->u8PhaseSeg1 > psFDTimingConfig->u8PhaseSeg2) ?
                                         psFDTimingConfig->u8PhaseSeg2 :
                                         psFDTimingConfig->u8PhaseSeg1;
    if (psFDTimingConfig->u8RJumpWidth > MAX_FRJW)
    {
        psFDTimingConfig->u8RJumpWidth = (uint8_t)MAX_FRJW;
    }
}

bool FLEXCAN_CalculateImprovedTimingValuesWithCBT(flexcan_timing_config_t *psTimingConfig,
                                                  uint32_t u32IdealSp,
                                                  uint32_t u32BaudRateBps,
                                                  uint32_t u32SrcClkHz)
{
    assert(NULL != psTimingConfig);

    uint32_t u32TqNum                   = CBT_MAX_TIME_QUANTA;
    uint32_t u32SpTemp                  = 1000U;
    flexcan_timing_config_t sConfigTemp = {0};
    bool bResult                        = false;

    if (((u32SrcClkHz % u32BaudRateBps) != 0U) || (u32BaudRateBps > MAX_CAN_BAUDRATE))
    {
        return false;
    }

    do
    {
        if ((u32BaudRateBps * u32TqNum) > u32SrcClkHz)
        {
            continue; /* u32TqNum too large, u32ClkAfterDiv has been exceed u32SrcClkHz. */
        }

        if ((u32SrcClkHz % (u32BaudRateBps * u32TqNum)) != 0U)
        {
            continue; /* The frequency of clock source is not divisible by current u32ClkAfterDiv. */
        }

        sConfigTemp.u16PreDivider = (uint16_t)(u32SrcClkHz / (u32BaudRateBps * u32TqNum));
        if (sConfigTemp.u16PreDivider > MAX_PRESDIV)
        {
            break; /* The frequency of clock source is too large or the bit rate is too small, the pre-divider could
                      not handle it. */
        }

        /* Calculates the best timing configuration under current tqNum, the sample point is according to CiA doc 1301
         * v1.0.0. */
        FLEXCAN_GetSegments(u32IdealSp, u32TqNum, &sConfigTemp, true);
        /* Determine whether the calculated timing configuration can get the optimal sampling point. */
        if ((((uint32_t)sConfigTemp.u8PhaseSeg2 * 1000U) / u32TqNum) < u32SpTemp)
        {
            u32SpTemp                     = ((uint32_t)sConfigTemp.u8PhaseSeg2 * 1000U) / u32TqNum;
            psTimingConfig->u16PreDivider = sConfigTemp.u16PreDivider;
            psTimingConfig->u8RJumpWidth  = sConfigTemp.u8RJumpWidth;
            psTimingConfig->u8PhaseSeg1   = sConfigTemp.u8PhaseSeg1;
            psTimingConfig->u8PhaseSeg2   = sConfigTemp.u8PhaseSeg2;
            psTimingConfig->u8PropSeg     = sConfigTemp.u8PropSeg;
        }
        bResult = true;
    } while (--u32TqNum >= CBT_MIN_TIME_QUANTA);

    return bResult;
}

bool FLEXCAN_FDCalculateImprovedTimingValues(flexcan_timing_config_t *psTimingConfig,
                                             flexcan_timing_config_t *psFDTimingConfig,
                                             uint32_t u32BaudRateBps,
                                             uint32_t u32FDBaudRateBps,
                                             uint32_t u32SrcClkHz)
{
    assert(NULL != psTimingConfig);
    assert(NULL != psFDTimingConfig);

    uint32_t u32ClkTemp;
    uint32_t u32TqTemp;
    bool bResult = false;

    if ((u32BaudRateBps > MAX_CAN_BAUDRATE) || (u32FDBaudRateBps > MAX_CANFD_BAUDRATE) ||
        (u32FDBaudRateBps < u32BaudRateBps) || ((u32SrcClkHz % u32FDBaudRateBps) != 0U) ||
        ((u32SrcClkHz % u32BaudRateBps) != 0U))
    {
        return false;
    }

    /*  Auto Improved Protocal timing for FDCBT. */
    if (u32BaudRateBps != u32FDBaudRateBps)
    {
        /* To minimize errors when processing FD frames, try to get the same bit rate prescaler value for nominal phase
           and data phase. */
        u32TqTemp = FDCBT_MAX_TIME_QUANTA;
        do
        {
            u32ClkTemp = u32FDBaudRateBps * u32TqTemp;
            if (u32ClkTemp > u32SrcClkHz)
            {
                continue; /* tqTemp too large, clk x tqTemp has been exceed sourceClock_Hz. */
            }

            if ((u32SrcClkHz / u32ClkTemp * u32ClkTemp) != u32SrcClkHz)
            {
                continue; /*  the frequency of clock source is not divisible by target bit rate. */
            }

            psFDTimingConfig->u16PreDivider = (uint16_t)(u32SrcClkHz / u32ClkTemp);

            if (psFDTimingConfig->u16PreDivider > MAX_FPRESDIV)
            {
                break; /* The frequency of source clock is too large or the bit rate is too small, the pre-divider
                          could not handle it. */
            }

            /* Calculates the best data phase timing configuration. */
            FLEXCAN_FDGetSegments(u32FDBaudRateBps, u32TqTemp, psFDTimingConfig);

            if (FLEXCAN_CalculateImprovedTimingValuesWithCBT(psTimingConfig, IDEAL_NOMINAL_SP, u32BaudRateBps,
                                                             u32SrcClkHz / psFDTimingConfig->u16PreDivider))
            {
                bResult = true;
                if (psTimingConfig->u16PreDivider == 1U)
                {
                    psTimingConfig->u16PreDivider = psFDTimingConfig->u16PreDivider;
                    break;
                }
                else
                {
                    psTimingConfig->u16PreDivider *= psFDTimingConfig->u16PreDivider;
                    continue;
                }
            }
        } while (--u32TqTemp >= FDCBT_MIN_TIME_QUANTA);
    }
    else
    {
        if (FLEXCAN_CalculateImprovedTimingValuesWithCBT(psTimingConfig, IDEAL_NOMINAL_SP, u32BaudRateBps, u32SrcClkHz))
        {
            /* No need data phase timing configuration, data phase rate equal to nominal phase rate, user don't use Brs
               feature. */
            psFDTimingConfig->u16PreDivider = 0U;
            psFDTimingConfig->u8RJumpWidth  = 0U;
            psFDTimingConfig->u8PhaseSeg1   = 0U;
            psFDTimingConfig->u8PhaseSeg2   = 0U;
            psFDTimingConfig->u8PropSeg     = 0U;
            bResult                         = true;
        }
    }
    return bResult;
}
#endif
/* @} */

/*!
 * @name Timing Configuration
 * @{
 */
void FLEXCAN_SetTimingConfig(CAN_Type *base, const flexcan_timing_config_t *psConfig)
{
    /* Assertion. */
    assert(NULL != psConfig);
    assert((0U != psConfig->u16PreDivider) && (0U != psConfig->u8RJumpWidth) && (0U != psConfig->u8PhaseSeg1) &&
           (0U != psConfig->u8PhaseSeg2) && (0U != psConfig->u8PropSeg));

    /* Enter Freeze Mode. */
    FLEXCAN_EnterFreezeMode(base);

    /* Use CBT or CTRL1 depending on whether the instance supports CAN FD mode or not. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
    if (0 != FSL_FEATURE_FLEXCAN_INSTANCE_HAS_FLEXIBLE_DATA_RATEn(base))
    {
        /* Updating CBT Timing Setting according to configuration structure. */
        base->CBT =
            CAN_CBT_BTF_MASK | CAN_CBT_EPRESDIV((uint32_t)psConfig->u16PreDivider - 1U) |
            CAN_CBT_ERJW((uint32_t)psConfig->u8RJumpWidth - 1U) | CAN_CBT_EPSEG1((uint32_t)psConfig->u8PhaseSeg1 - 1U) |
            CAN_CBT_EPSEG2((uint32_t)psConfig->u8PhaseSeg2 - 1U) | CAN_CBT_EPROPSEG((uint32_t)psConfig->u8PropSeg - 1U);
    }
    else
    {
        /* Cleaning previous Timing Setting. */
        base->CTRL1 &= ~(CAN_CTRL1_PRESDIV_MASK | CAN_CTRL1_RJW_MASK | CAN_CTRL1_PSEG1_MASK | CAN_CTRL1_PSEG2_MASK |
                         CAN_CTRL1_PROPSEG_MASK);

        /* Updating CTRL1 Timing Setting according to configuration structure. */
        base->CTRL1 |= (CAN_CTRL1_PRESDIV((uint32_t)psConfig->u16PreDivider - 1U) |
                        CAN_CTRL1_RJW((uint32_t)psConfig->u8RJumpWidth - 1U) |
                        CAN_CTRL1_PSEG1((uint32_t)psConfig->u8PhaseSeg1 - 1U) |
                        CAN_CTRL1_PSEG2((uint32_t)psConfig->u8PhaseSeg2 - 1U) |
                        CAN_CTRL1_PROPSEG((uint32_t)psConfig->u8PropSeg - 1U));
    }
#else
    /* Cleaning previous Timing Setting. */
    base->CTRL1 &= ~(CAN_CTRL1_PRESDIV_MASK | CAN_CTRL1_RJW_MASK | CAN_CTRL1_PSEG1_MASK | CAN_CTRL1_PSEG2_MASK |
                     CAN_CTRL1_PROPSEG_MASK);

    /* Updating CTRL1 Timing Setting according to configuration structure. */
    base->CTRL1 |=
        (CAN_CTRL1_PRESDIV((uint32_t)psConfig->u16PreDivider - 1U) |
         CAN_CTRL1_RJW((uint32_t)psConfig->u8RJumpWidth - 1U) | CAN_CTRL1_PSEG1((uint32_t)psConfig->u8PhaseSeg1 - 1U) |
         CAN_CTRL1_PSEG2((uint32_t)psConfig->u8PhaseSeg2 - 1U) | CAN_CTRL1_PROPSEG((uint32_t)psConfig->u8PropSeg - 1U));
#endif

    /* Exit Freeze Mode. */
    FLEXCAN_ExitFreezeMode(base);
}

status_t FLEXCAN_SetBaudRate(CAN_Type *base, uint32_t u32SrcClkHz, uint32_t u32BaudRateBps)
{
    flexcan_timing_config_t sTimingConfig;
    bool bStatus, bUseCbt;
    /* Calculate timing automatically with given Baud Rate. */
    /* Use CBT or CTRL1 depending on whether the instance supports CAN FD mode or not. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
    if (0 != FSL_FEATURE_FLEXCAN_INSTANCE_HAS_FLEXIBLE_DATA_RATEn(base))
    {
        bUseCbt = true;
        /* Try to find the ideal sample point, according to CiA 301 doc.*/
        if (u32BaudRateBps == 1000000U)
        {
            bStatus =
                FLEXCAN_CalculateImprovedTimingValuesWithCBT(&sTimingConfig, IDEAL_SP_LOW, u32BaudRateBps, u32SrcClkHz);
        }
        else if (u32BaudRateBps >= 800000U)
        {
            bStatus =
                FLEXCAN_CalculateImprovedTimingValuesWithCBT(&sTimingConfig, IDEAL_SP_MID, u32BaudRateBps, u32SrcClkHz);
        }
        else
        {
            bStatus = FLEXCAN_CalculateImprovedTimingValuesWithCBT(&sTimingConfig, IDEAL_SP_HIGH, u32BaudRateBps,
                                                                   u32SrcClkHz);
        }
    }
    else
    {
        bUseCbt = false;
        bStatus = FLEXCAN_CalculateImprovedTimingValues(&sTimingConfig, u32BaudRateBps, u32SrcClkHz);
    }
#else
    bUseCbt = false;
    bStatus = FLEXCAN_CalculateImprovedTimingValues(&sTimingConfig, u32BaudRateBps, u32SrcClkHz);
#endif
    if (bStatus)
    {
        /* Update classic CAN bit or CAN FD nominal phase timing characteristic. */
        FLEXCAN_SetTimingConfig(base, &sTimingConfig);
        return kStatus_Success;
    }
    else
    {
        /* Auto calculate classic CAN bit timing configuration failed! Use the following configuration, the final
         * bit rate will have some errors (10 Tq with 80% SP for classical CAN or CAN FD nominal phase).
         */
        sTimingConfig.u8PropSeg    = 3U;
        sTimingConfig.u8PhaseSeg1  = 4U;
        sTimingConfig.u8PhaseSeg2  = 2U;
        sTimingConfig.u8RJumpWidth = 2U;
        if ((u32SrcClkHz / u32BaudRateBps / 10U) == 0U)
        {
            sTimingConfig.u16PreDivider = 1U;
        }
        else if ((u32SrcClkHz / u32BaudRateBps / 10U) > MAX_DIV(bUseCbt))
        {
            sTimingConfig.u16PreDivider = (uint16_t)MAX_DIV(bUseCbt);
        }
        else
        {
            sTimingConfig.u16PreDivider = (uint16_t)(u32SrcClkHz / u32BaudRateBps / 10U);
        }
        /* Update classic CAN bit or CAN FD nominal phase timing characteristic. */
        FLEXCAN_SetTimingConfig(base, &sTimingConfig);
        return kStatus_Fail;
    }
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
void FLEXCAN_SetFDTimingConfig(CAN_Type *base, const flexcan_timing_config_t *psConfig)
{
    /* Assertion. */
    assert(NULL != psConfig);
    assert((0U != psConfig->u16PreDivider) && (0U != psConfig->u8RJumpWidth) && (0U != psConfig->u8PhaseSeg1) &&
           (0U != psConfig->u8PhaseSeg2));

    /* Enter Freeze Mode. */
    FLEXCAN_EnterFreezeMode(base);

    /* Enable Bit Timing register FDCBT. */
    base->CBT |= CAN_CBT_BTF_MASK;
    /* Cleaning previous Timing Setting. */
    base->FDCBT &= ~(CAN_FDCBT_FPRESDIV_MASK | CAN_FDCBT_FRJW_MASK | CAN_FDCBT_FPSEG1_MASK | CAN_FDCBT_FPSEG2_MASK |
                     CAN_FDCBT_FPROPSEG_MASK);

    /* Updating Timing Setting according to configuration structure. */
    base->FDCBT |= (CAN_FDCBT_FPRESDIV((uint32_t)psConfig->u16PreDivider - 1U) |
                    CAN_FDCBT_FRJW((uint32_t)psConfig->u8RJumpWidth - 1U) |
                    CAN_FDCBT_FPSEG1((uint32_t)psConfig->u8PhaseSeg1 - 1U) |
                    CAN_FDCBT_FPSEG2((uint32_t)psConfig->u8PhaseSeg2 - 1U) | CAN_FDCBT_FPROPSEG(psConfig->u8PropSeg));
    /* Setup the transmit delay to define a secondary sample point */
    if ((base->FDCTRL & CAN_FDCTRL_TDCEN_MASK) != 0U)
    {
        if ((((uint32_t)psConfig->u8PropSeg + psConfig->u8PhaseSeg1 + 1U) * psConfig->u16PreDivider) < MAX_TDCOFF)
        {
            base->FDCTRL = (base->FDCTRL & ~CAN_FDCTRL_TDCOFF_MASK) |
                           CAN_FDCTRL_TDCOFF(((uint32_t)psConfig->u8PropSeg + psConfig->u8PhaseSeg1 + 2U) *
                                             psConfig->u16PreDivider);
        }
        else
        {
            base->FDCTRL = (base->FDCTRL & ~CAN_FDCTRL_TDCOFF_MASK) | CAN_FDCTRL_TDCOFF(MAX_TDCOFF);
        }
    }

    /* Exit Freeze Mode. */
    FLEXCAN_ExitFreezeMode(base);
}

status_t FLEXCAN_SetFDBaudRate(CAN_Type *base, uint32_t u32SrcClkHz, uint32_t u32BaudRateBps, uint32_t u32FDBaudRateBps)
{
    flexcan_timing_config_t sTimingConfig;
    flexcan_timing_config_t sFDTimingConfig = {0};
    /* Calculate timing automatically with given Baud Rate. */
    if (FLEXCAN_FDCalculateImprovedTimingValues(&sTimingConfig, &sFDTimingConfig, u32BaudRateBps, u32FDBaudRateBps,
                                                u32SrcClkHz))
    {
        /* Update CAN FD bit timing characteristic. */
        FLEXCAN_SetTimingConfig(base, &sTimingConfig);
        FLEXCAN_SetFDTimingConfig(base, &sFDTimingConfig);
        return kStatus_Success;
    }
    else
    {
        /* Auto calculate CAN FD bit timing configuration failed! Use the following configuration, the final
         * bit rate will have some errors (10 Tq with 80% SP for CAN FD nominal phase, 5 Tq with 60% SP for CAN FD data
         * phase).
         */
        sTimingConfig.u8PropSeg    = 3U;
        sTimingConfig.u8PhaseSeg1  = 4U;
        sTimingConfig.u8PhaseSeg2  = 2U;
        sTimingConfig.u8RJumpWidth = 2U;
        if ((u32SrcClkHz / u32BaudRateBps / 10U) == 0U)
        {
            sTimingConfig.u16PreDivider = 1U;
        }
        else if ((u32SrcClkHz / u32BaudRateBps / 10U) > MAX_EPRESDIV)
        {
            sTimingConfig.u16PreDivider = (uint16_t)MAX_EPRESDIV;
        }
        else
        {
            sTimingConfig.u16PreDivider = (uint16_t)(u32SrcClkHz / u32BaudRateBps / 10U);
        }
        sFDTimingConfig.u8PropSeg    = 0U;
        sFDTimingConfig.u8PhaseSeg1  = 2U;
        sFDTimingConfig.u8PhaseSeg2  = 2U;
        sFDTimingConfig.u8RJumpWidth = 2U;
        /* Update CAN FD bit timing characteristic. */
        FLEXCAN_SetTimingConfig(base, &sTimingConfig);
        FLEXCAN_SetFDTimingConfig(base, &sFDTimingConfig);
        return kStatus_Fail;
    }
}
#endif
/* @} */

/*!
 * @name Message Buffer Configuration
 * @{
 */

#if !defined(NDEBUG)
static bool FLEXCAN_IsMbOccupied(CAN_Type *base, uint8_t u8MsgBufIdx)
{
    uint8_t u8LastOccupiedMsgBuf;
    bool bFgRet;

    /* Is Rx FIFO enabled? */
    if (0U != (base->MCR & CAN_MCR_RFEN_MASK))
    {
        /* Get RFFN value. */
        u8LastOccupiedMsgBuf = (uint8_t)((base->CTRL2 & CAN_CTRL2_RFFN_MASK) >> CAN_CTRL2_RFFN_SHIFT);
        /* Calculate the number of last Message Buffer occupied by Rx FIFO. */
        u8LastOccupiedMsgBuf = ((u8LastOccupiedMsgBuf + 1U) * 2U) + 5U;

#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
        /* the first valid MB should be occupied by ERRATA 5461 or 5829. */
        u8LastOccupiedMsgBuf += 1U;
#endif
        bFgRet = (u8MsgBufIdx <= u8LastOccupiedMsgBuf);
    }
    else
    {
#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
        if (0U == u8MsgBufIdx)
        {
            bFgRet = true;
        }
        else
#endif
        {
            bFgRet = false;
        }
    }

    return bFgRet;
}
#endif

#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
static uint8_t FLEXCAN_GetFirstValidMb(CAN_Type *base)
{
    uint8_t u8FirstValidMsgBufNum;

    if (0U != (base->MCR & CAN_MCR_RFEN_MASK))
    {
        u8FirstValidMsgBufNum = (uint8_t)((base->CTRL2 & CAN_CTRL2_RFFN_MASK) >> CAN_CTRL2_RFFN_SHIFT);
        u8FirstValidMsgBufNum = ((u8FirstValidMsgBufNum + 1U) * 2U) + 6U;
    }
    else
    {
        u8FirstValidMsgBufNum = 0U;
    }

    return u8FirstValidMsgBufNum;
}
#endif

static bool FLEXCAN_IsMbIntEnabled(CAN_Type *base, uint8_t u8MsgBufIdx)
{
    /* Assertion. */
    assert(u8MsgBufIdx < (uint8_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base));

    uint32_t u32Flag = 1U;
    bool bFgRet      = false;

#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    if (u8MsgBufIdx >= 32U)
    {
        bFgRet = (0U != (base->IMASK2 & (u32Flag << (u8MsgBufIdx - 32U))));
    }
    else
#endif
    {
        bFgRet = (0U != (base->IMASK1 & (u32Flag << u8MsgBufIdx)));
    }

    return bFgRet;
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
static uint32_t FLEXCAN_GetFDMailboxOffset(CAN_Type *base, uint8_t u8MsgBufIdx)
{
    uint32_t offset   = 0;
    uint32_t dataSize = (base->FDCTRL & CAN_FDCTRL_MBDSR0_MASK) >> CAN_FDCTRL_MBDSR0_SHIFT;
    switch (dataSize)
    {
        case (uint32_t)kFLEXCAN_8BperMB:
            offset = (((uint32_t)u8MsgBufIdx / 32U) * 512U + ((uint32_t)u8MsgBufIdx % 32U) * 16U);
            break;
        case (uint32_t)kFLEXCAN_16BperMB:
            offset = (((uint32_t)u8MsgBufIdx / 21U) * 512U + ((uint32_t)u8MsgBufIdx % 21U) * 24U);
            break;
        case (uint32_t)kFLEXCAN_32BperMB:
            offset = (((uint32_t)u8MsgBufIdx / 12U) * 512U + ((uint32_t)u8MsgBufIdx % 12U) * 40U);
            break;
        case (uint32_t)kFLEXCAN_64BperMB:
            offset = (((uint32_t)u8MsgBufIdx / 7U) * 512U + ((uint32_t)u8MsgBufIdx % 7U) * 72U);
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
    /* To get the dword aligned offset, need to divide by 4. */
    offset = offset / 4U;
    return offset;
}

#endif

void FLEXCAN_SetRxMbGlobalMask(CAN_Type *base, uint32_t u32RecMsgBufs)
{
    /* Enter Freeze Mode. */
    FLEXCAN_EnterFreezeMode(base);

    /* Setting Rx Message Buffer Global Mask value. */
    base->RXMGMASK = u32RecMsgBufs;
    base->RX14MASK = u32RecMsgBufs;
    base->RX15MASK = u32RecMsgBufs;

    /* Exit Freeze Mode. */
    FLEXCAN_ExitFreezeMode(base);
}

void FLEXCAN_SetRxFifoGlobalMask(CAN_Type *base, uint32_t u32RecFifos)
{
    /* Enter Freeze Mode. */
    FLEXCAN_EnterFreezeMode(base);

    /* Setting Rx FIFO Global Mask value. */
    base->RXFGMASK = u32RecFifos;

    /* Exit Freeze Mode. */
    FLEXCAN_ExitFreezeMode(base);
}

void FLEXCAN_SetRxIndividualMask(CAN_Type *base, uint8_t u8MaskIdx, uint32_t u32Mask)
{
    assert(u8MaskIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));

    /* Enter Freeze Mode. */
    FLEXCAN_EnterFreezeMode(base);

    /* Setting Rx Individual Mask value. */
    base->RXIMR[u8MaskIdx] = u32Mask;

    /* Exit Freeze Mode. */
    FLEXCAN_ExitFreezeMode(base);
}

void FLEXCAN_SetTxMbConfig(CAN_Type *base, uint8_t u8MsgBufIdx, bool bEnable)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    /* Inactivate Message Buffer. */
    if (bEnable)
    {
        base->MB[u8MsgBufIdx].CS = CAN_CS_CODE(kFLEXCAN_TxMbInactive);
    }
    else
    {
        base->MB[u8MsgBufIdx].CS = 0;
    }

    /* Clean Message Buffer content. */
    base->MB[u8MsgBufIdx].ID    = 0x0;
    base->MB[u8MsgBufIdx].WORD0 = 0x0;
    base->MB[u8MsgBufIdx].WORD1 = 0x0;
}

void FLEXCAN_SetRxMbConfig(CAN_Type *base,
                           uint8_t u8MsgBufIdx,
                           const flexcan_rx_mb_config_t *psRxMsgBufConfig,
                           bool bEnable)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
    assert(((NULL != psRxMsgBufConfig) || (false == bEnable)));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    uint32_t cs_temp = 0;

    /* Inactivate Message Buffer. */
    base->MB[u8MsgBufIdx].CS = 0;

    /* Clean Message Buffer content. */
    base->MB[u8MsgBufIdx].ID    = 0x0;
    base->MB[u8MsgBufIdx].WORD0 = 0x0;
    base->MB[u8MsgBufIdx].WORD1 = 0x0;

    if (bEnable)
    {
        /* Setup Message Buffer ID. */
        base->MB[u8MsgBufIdx].ID = psRxMsgBufConfig->u32Id;

        /* Setup Message Buffer format. */
        if (kFLEXCAN_FrameFormatExtend == psRxMsgBufConfig->eFormat)
        {
            cs_temp |= CAN_CS_IDE_MASK;
        }

        /* Setup Message Buffer type. */
        if (kFLEXCAN_FrameTypeRemote == psRxMsgBufConfig->eType)
        {
            cs_temp |= CAN_CS_RTR_MASK;
        }

        /* Activate Rx Message Buffer. */
        cs_temp |= CAN_CS_CODE(kFLEXCAN_RxMbEmpty);
        base->MB[u8MsgBufIdx].CS = cs_temp;
    }
}

void FLEXCAN_SetRxFifoConfig(CAN_Type *base, const flexcan_rx_fifo_config_t *psRxFifoConfig, bool bEnable)
{
    /* Assertion. */
    assert((NULL != psRxFifoConfig) || (false == bEnable));

    volatile uint32_t *mbAddr;
    uint8_t i, j, k, rffn = 0, numMbOccupy;
    uint32_t setup_mb = 0;

    /* Enter Freeze Mode. */
    FLEXCAN_EnterFreezeMode(base);

    if (bEnable)
    {
        assert(psRxFifoConfig->u8IdFilterNum <= 128U);

        /* Get the setup_mb value. */
        setup_mb = (uint8_t)((base->MCR & CAN_MCR_MAXMB_MASK) >> CAN_MCR_MAXMB_SHIFT);
        setup_mb = (setup_mb < (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base)) ?
                       setup_mb :
                       (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base);

        /* Determine RFFN value. */
        for (i = 0; i <= 0xFU; i++)
        {
            if ((8U * (i + 1U)) >= psRxFifoConfig->u8IdFilterNum)
            {
                rffn = i;
                assert(((setup_mb - 8U) - (2U * rffn)) > 0U);

                base->CTRL2 = (base->CTRL2 & ~CAN_CTRL2_RFFN_MASK) | CAN_CTRL2_RFFN(rffn);
                break;
            }
        }

        /* caculate the Number of Mailboxes occupied by RX Legacy FIFO and the filter. */
        numMbOccupy = 6U + (rffn + 1U) * 2U;

        /* Copy ID filter table to Message Buffer Region (Fix MISRA_C-2012 Rule 18.1). */
        j = 0U;
        for (i = 6U; i < numMbOccupy; i++)
        {
            /* Get address for current mail box.  */
            mbAddr = &(base->MB[i].CS);

            /* One Mail box contain 4U DWORD registers. */
            for (k = 0; k < 4U; k++)
            {
                /* Fill all valid filter in the mail box occupied by filter.
                 * Disable unused Rx FIFO Filter, the other rest of register in the last Mail box occupied by fiter set
                 * as 0xffffffff.
                 */
                mbAddr[k] = (j < psRxFifoConfig->u8IdFilterNum) ? (psRxFifoConfig->pu32IdFilterTable[j]) : 0xFFFFFFFFU;

                /* Try to fill next filter in current Mail Box.  */
                j++;
            }
        }

        /* Setup ID Fitlter Type. */
        switch (psRxFifoConfig->eIdFilterType)
        {
            case kFLEXCAN_RxFifoFilterTypeA:
                base->MCR = (base->MCR & ~CAN_MCR_IDAM_MASK) | CAN_MCR_IDAM(0x0);
                break;
            case kFLEXCAN_RxFifoFilterTypeB:
                base->MCR = (base->MCR & ~CAN_MCR_IDAM_MASK) | CAN_MCR_IDAM(0x1);
                break;
            case kFLEXCAN_RxFifoFilterTypeC:
                base->MCR = (base->MCR & ~CAN_MCR_IDAM_MASK) | CAN_MCR_IDAM(0x2);
                break;
            case kFLEXCAN_RxFifoFilterTypeD:
                /* All frames rejected. */
                base->MCR = (base->MCR & ~CAN_MCR_IDAM_MASK) | CAN_MCR_IDAM(0x3);
                break;
            default:
                /* All the cases have been listed above, the default clause should not be reached. */
                assert(false);
                break;
        }

        /* Setting Message Reception Priority. */
        base->CTRL2 = (psRxFifoConfig->ePriority == kFLEXCAN_RxFifoPriorityHigh) ? (base->CTRL2 & ~CAN_CTRL2_MRP_MASK) :
                                                                                   (base->CTRL2 | CAN_CTRL2_MRP_MASK);

        /* Enable Rx Message FIFO. */
        base->MCR |= CAN_MCR_RFEN_MASK;
    }
    else
    {
        rffn = (uint8_t)((base->CTRL2 & CAN_CTRL2_RFFN_MASK) >> CAN_CTRL2_RFFN_SHIFT);
        /* caculate the Number of Mailboxes occupied by RX Legacy FIFO and the filter. */
        numMbOccupy = 6U + (rffn + 1U) * 2U;

        /* Disable Rx Message FIFO. */
        base->MCR &= ~CAN_MCR_RFEN_MASK;

        /* Clean MB0 ~ MB5 and all MB occupied by ID filters (Fix MISRA_C-2012 Rule 18.1). */

        for (i = 0; i < numMbOccupy; i++)
        {
            FLEXCAN_SetRxMbConfig(base, i, NULL, false);
        }
    }

    /* Exit Freeze Mode. */
    FLEXCAN_ExitFreezeMode(base);
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
void FLEXCAN_SetFDTxMbConfig(CAN_Type *base, uint8_t u8MsgBufIdx, bool bEnable)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    uint8_t cnt           = 0;
    uint8_t payload_dword = 1;
    uint32_t dataSize;
    dataSize                  = (base->FDCTRL & CAN_FDCTRL_MBDSR0_MASK) >> CAN_FDCTRL_MBDSR0_SHIFT;
    volatile uint32_t *mbAddr = &(base->MB[0].CS);
    uint32_t offset           = FLEXCAN_GetFDMailboxOffset(base, u8MsgBufIdx);
#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
    uint32_t availoffset = FLEXCAN_GetFDMailboxOffset(base, FLEXCAN_GetFirstValidMb(base));
#endif

    /* Inactivate Message Buffer. */
    if (bEnable)
    {
        /* Inactivate by writing CS. */
        mbAddr[offset] = CAN_CS_CODE(kFLEXCAN_TxMbInactive);
    }
    else
    {
        mbAddr[offset] = 0x0;
    }

    /* Calculate the DWORD number, dataSize 0/1/2/3 corresponds to 8/16/32/64
       Bytes payload. */
    for (cnt = 0; cnt < (dataSize + 1U); cnt++)
    {
        payload_dword *= 2U;
    }

    /* Clean ID. */
    mbAddr[offset + 1U] = 0x0U;
    /* Clean Message Buffer content, DWORD by DWORD. */
    for (cnt = 0; cnt < payload_dword; cnt++)
    {
        mbAddr[offset + 2U + cnt] = 0x0U;
    }

#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
    mbAddr[availoffset] = CAN_CS_CODE(kFLEXCAN_TxMbInactive);
#endif
}

void FLEXCAN_SetFDRxMbConfig(CAN_Type *base,
                             uint8_t u8MsgBufIdx,
                             const flexcan_rx_mb_config_t *psRxMsgBufConfig,
                             bool bEnable)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
    assert(((NULL != psRxMsgBufConfig) || (false == bEnable)));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    uint32_t cs_temp          = 0;
    uint8_t cnt               = 0;
    volatile uint32_t *mbAddr = &(base->MB[0].CS);
    uint32_t offset           = FLEXCAN_GetFDMailboxOffset(base, u8MsgBufIdx);
    uint8_t payload_dword;
    uint32_t dataSize = (base->FDCTRL & CAN_FDCTRL_MBDSR0_MASK) >> CAN_FDCTRL_MBDSR0_SHIFT;

    /* Inactivate Message Buffer. */
    mbAddr[offset] = 0U;

    /* Clean Message Buffer content. */
    mbAddr[offset + 1U] = 0U;
    /* Calculate the DWORD number, dataSize 0/1/2/3 corresponds to 8/16/32/64
       Bytes payload. */
    payload_dword = (2U << dataSize);
    for (cnt = 0; cnt < payload_dword; cnt++)
    {
        mbAddr[offset + 2U + cnt] = 0x0;
    }

    if (bEnable)
    {
        /* Setup Message Buffer ID. */
        mbAddr[offset + 1U] = psRxMsgBufConfig->u32Id;

        /* Setup Message Buffer format. */
        if (kFLEXCAN_FrameFormatExtend == psRxMsgBufConfig->eFormat)
        {
            cs_temp |= CAN_CS_IDE_MASK;
        }

        /* Setup Message Buffer type. */
        if (kFLEXCAN_FrameTypeRemote == psRxMsgBufConfig->eType)
        {
            cs_temp |= CAN_CS_RTR_MASK;
        }

        /* Activate Rx Message Buffer. */
        cs_temp |= CAN_CS_CODE(kFLEXCAN_RxMbEmpty);
        mbAddr[offset] = cs_temp;
    }
}

#endif
/* @} */

/*!
 * @name General Configuration
 * @{
 */
static void FLEXCAN_Reset(CAN_Type *base)
{
    /* The module must should be first exit from low power
     * mode, and then soft reset can be applied.
     */
    assert(0U == (base->MCR & CAN_MCR_MDIS_MASK));

    uint8_t i;

#if (defined(FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT) && FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT)
    if (0 != (FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(base)))
    {
        /* De-assert DOZE Enable Bit. */
        base->MCR &= ~CAN_MCR_DOZE_MASK;
    }
#endif

    /* Wait until FlexCAN exit from any Low Power Mode. */
    while (0U != (base->MCR & CAN_MCR_LPMACK_MASK))
    {
    }

    /* Assert Soft Reset Signal. */
    base->MCR |= CAN_MCR_SOFTRST_MASK;
    /* Wait until FlexCAN reset completes. */
    while (0U != (base->MCR & CAN_MCR_SOFTRST_MASK))
    {
    }

/* Reset MCR register. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER) && FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER)
    base->MCR |= CAN_MCR_WRNEN_MASK | CAN_MCR_WAKSRC_MASK |
                 CAN_MCR_MAXMB((uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base) - 1U);
#else
    base->MCR |=
        CAN_MCR_WRNEN_MASK | CAN_MCR_MAXMB((uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base) - 1U);
#endif

    /* Reset CTRL1 and CTRL2 register, default to eanble SMP feature which enable three sample point to determine the
     * received bit's value of the. */
    base->CTRL1 = CAN_CTRL1_SMP_MASK;
    base->CTRL2 = CAN_CTRL2_TASD(0x16) | CAN_CTRL2_RRS_MASK | CAN_CTRL2_EACEN_MASK;

    /* Clean all individual Rx Mask of Message Buffers. */
    for (i = 0; i < (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base); i++)
    {
        base->RXIMR[i] = 0x3FFFFFFF;
    }

    /* Clean Global Mask of Message Buffers. */
    base->RXMGMASK = 0x3FFFFFFF;
    /* Clean Global Mask of Message Buffer 14. */
    base->RX14MASK = 0x3FFFFFFF;
    /* Clean Global Mask of Message Buffer 15. */
    base->RX15MASK = 0x3FFFFFFF;
    /* Clean Global Mask of Rx FIFO. */
    base->RXFGMASK = 0x3FFFFFFF;

    /* Clean all Message Buffer memory. */
    for (i = 0; i < (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base); i++)
    {
        base->MB[i].CS    = 0x0;
        base->MB[i].ID    = 0X0;
        base->MB[i].WORD0 = 0X0;
        base->MB[i].WORD1 = 0X0;
    }
}

/* @} */

/*!
 * @name DMA Configuration
 * @{
 */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA) && FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA)
void FLEXCAN_EnableRxFifoDMA(CAN_Type *base, bool bEnable)
{
    if (bEnable)
    {
        /* Enter Freeze Mode. */
        FLEXCAN_EnterFreezeMode(base);

        /* Enable FlexCAN DMA. */
        base->MCR |= CAN_MCR_DMA_MASK;

        /* Exit Freeze Mode. */
        FLEXCAN_ExitFreezeMode(base);
    }
    else
    {
        /* Enter Freeze Mode. */
        FLEXCAN_EnterFreezeMode(base);

        /* Disable FlexCAN DMA. */
        base->MCR &= ~CAN_MCR_DMA_MASK;

        /* Exit Freeze Mode. */
        FLEXCAN_ExitFreezeMode(base);
    }
}
#endif /* FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA */

/* @} */

/*!
 * @name Bus Operation
 * @{
 */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032)
static void FLEXCAN_ERRATA_6032(CAN_Type *base, volatile uint32_t *pu32MsgBufCSAddr)
{
    uint32_t dbg_temp      = 0U;
    uint32_t u32TempCS     = 0U;
    uint32_t u32Timeout    = DELAY_BUSIDLE;
    uint32_t u32TempIMASK1 = base->IMASK1;
/*after backup all interruption, disable ALL interruption*/
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint32_t u32TempIMASK2 = base->IMASK2;
    base->IMASK2           = 0;
#endif
    base->IMASK1 = 0;
    dbg_temp     = (uint32_t)(base->DBG1);
    switch (dbg_temp & CAN_DBG1_CFSM_MASK)
    {
        case RXINTERMISSION:
            if (CBN_VALUE3 == (dbg_temp & CAN_DBG1_CBN_MASK))
            {
                /*wait until CFSM is different from RXINTERMISSION */
                while (RXINTERMISSION == (base->DBG1 & CAN_DBG1_CFSM_MASK))
                {
                    __NOP();
                }
            }
            break;
        case TXINTERMISSION:
            if (CBN_VALUE3 == (dbg_temp & CAN_DBG1_CBN_MASK))
            {
                /*wait until CFSM is different from TXINTERMISSION*/
                while (TXINTERMISSION == (base->DBG1 & CAN_DBG1_CFSM_MASK))
                {
                    __NOP();
                }
            }
            break;
        default:
            /* To avoid MISRA-C 2012 rule 16.4 issue. */
            break;
    }
    /*Anyway, BUSIDLE need to delay*/
    if (BUSIDLE == (base->DBG1 & CAN_DBG1_CFSM_MASK))
    {
        while (u32Timeout-- > 0U)
        {
            __NOP();
        }

        /*Write 0x0 into Code field of CS word.*/
        u32TempCS = (uint32_t)(*pu32MsgBufCSAddr);
        u32TempCS &= ~CAN_CS_CODE_MASK;
        *pu32MsgBufCSAddr = u32TempCS;
    }
    /*restore interruption*/
    base->IMASK1 = u32TempIMASK1;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    base->IMASK2 = u32TempIMASK2;
#endif
}
#endif

status_t FLEXCAN_WriteTxMb(CAN_Type *base, uint8_t u8MsgBufIdx, const flexcan_frame_t *psTxFrame)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
    assert(NULL != psTxFrame);
    assert(psTxFrame->bitsLength <= 8U);
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    uint32_t cs_temp = 0;
    status_t status;

#if (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032)
    FLEXCAN_ERRATA_6032(base, &(base->MB[u8MsgBufIdx].CS));
#endif
    /* Check if Message Buffer is available. */
    if (CAN_CS_CODE(kFLEXCAN_TxMbDataOrRemote) != (base->MB[u8MsgBufIdx].CS & CAN_CS_CODE_MASK))
    {
        /* Inactive Tx Message Buffer. */
        base->MB[u8MsgBufIdx].CS = (base->MB[u8MsgBufIdx].CS & ~CAN_CS_CODE_MASK) | CAN_CS_CODE(kFLEXCAN_TxMbInactive);

        /* Fill Message ID field. */
        base->MB[u8MsgBufIdx].ID = psTxFrame->bitsId;

        /* Fill Message Format field. */
        if ((uint32_t)kFLEXCAN_FrameFormatExtend == psTxFrame->bitFormat)
        {
            cs_temp |= CAN_CS_SRR_MASK | CAN_CS_IDE_MASK;
        }

        /* Fill Message Type field. */
        if ((uint32_t)kFLEXCAN_FrameTypeRemote == psTxFrame->bitType)
        {
            cs_temp |= CAN_CS_RTR_MASK;
        }

        cs_temp |= CAN_CS_CODE(kFLEXCAN_TxMbDataOrRemote) | CAN_CS_DLC(psTxFrame->bitsLength);

        /* Load Message Payload. */
        base->MB[u8MsgBufIdx].WORD0 = psTxFrame->u32DataWord0;
        base->MB[u8MsgBufIdx].WORD1 = psTxFrame->u32DataWord1;

        /* Activate Tx Message Buffer. */
        base->MB[u8MsgBufIdx].CS = cs_temp;

#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
        base->MB[FLEXCAN_GetFirstValidMb(base)].CS = CAN_CS_CODE(kFLEXCAN_TxMbInactive);
        base->MB[FLEXCAN_GetFirstValidMb(base)].CS = CAN_CS_CODE(kFLEXCAN_TxMbInactive);
#endif

        status = kStatus_Success;
    }
    else
    {
        /* Tx Message Buffer is activated, return immediately. */
        status = kStatus_Fail;
    }

    return status;
}

status_t FLEXCAN_ReadRxMb(CAN_Type *base, uint8_t u8MsgBufIdx, flexcan_frame_t *psRxFrame)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
    assert(NULL != psRxFrame);
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    uint32_t cs_temp;
    uint32_t rx_code;
    status_t status;

    /* Read CS field of Rx Message Buffer to lock Message Buffer. */
    cs_temp = base->MB[u8MsgBufIdx].CS;
    /* Get Rx Message Buffer Code field. */
    rx_code = (cs_temp & CAN_CS_CODE_MASK) >> CAN_CS_CODE_SHIFT;

    /* Check to see if Rx Message Buffer is full. */
    if (((uint32_t)kFLEXCAN_RxMbFull == rx_code) || ((uint32_t)kFLEXCAN_RxMbOverrun == rx_code))
    {
        /* Store Message ID. */
        psRxFrame->bitsId = base->MB[u8MsgBufIdx].ID & (CAN_ID_EXT_MASK | CAN_ID_STD_MASK);

        /* Get the message ID and format. */
        psRxFrame->bitFormat = (cs_temp & CAN_CS_IDE_MASK) != 0U ? (uint8_t)kFLEXCAN_FrameFormatExtend :
                                                                   (uint8_t)kFLEXCAN_FrameFormatStandard;

        /* Get the message type. */
        psRxFrame->bitType =
            (cs_temp & CAN_CS_RTR_MASK) != 0U ? (uint8_t)kFLEXCAN_FrameTypeRemote : (uint8_t)kFLEXCAN_FrameTypeData;

        /* Get the message length. */
        psRxFrame->bitsLength = (uint8_t)((cs_temp & CAN_CS_DLC_MASK) >> CAN_CS_DLC_SHIFT);

        /* Get the time stamp. */
        psRxFrame->bitsTimestamp = (uint16_t)((cs_temp & CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT);

        /* Store Message Payload. */
        psRxFrame->u32DataWord0 = base->MB[u8MsgBufIdx].WORD0;
        psRxFrame->u32DataWord1 = base->MB[u8MsgBufIdx].WORD1;

        /* Read free-running timer to unlock Rx Message Buffer. */
        (void)base->TIMER;

        if ((uint32_t)kFLEXCAN_RxMbFull == rx_code)
        {
            status = kStatus_Success;
        }
        else
        {
            status = kStatus_FLEXCAN_RxOverflow;
        }
    }
    else
    {
        /* Read free-running timer to unlock Rx Message Buffer. */
        (void)base->TIMER;

        status = kStatus_Fail;
    }

    return status;
}

status_t FLEXCAN_ReadRxFifo(CAN_Type *base, flexcan_frame_t *psRxFrame)
{
    /* Assertion. */
    assert(NULL != psRxFrame);

    uint32_t cs_temp;
    status_t status;

    /* Check if Rx FIFO is Enabled. */
    if (0U != (base->MCR & CAN_MCR_RFEN_MASK))
    {
        /* Read CS field of Rx Message Buffer to lock Message Buffer. */
        cs_temp = base->MB[0].CS;

        /* Read data from Rx FIFO output port. */
        /* Store Message ID. */
        psRxFrame->bitsId = base->MB[0].ID & (CAN_ID_EXT_MASK | CAN_ID_STD_MASK);

        /* Get the message ID and format. */
        psRxFrame->bitFormat = (cs_temp & CAN_CS_IDE_MASK) != 0U ? (uint8_t)kFLEXCAN_FrameFormatExtend :
                                                                   (uint8_t)kFLEXCAN_FrameFormatStandard;

        /* Get the message type. */
        psRxFrame->bitType =
            (cs_temp & CAN_CS_RTR_MASK) != 0U ? (uint8_t)kFLEXCAN_FrameTypeRemote : (uint8_t)kFLEXCAN_FrameTypeData;

        /* Get the message length. */
        psRxFrame->bitsLength = (uint8_t)((cs_temp & CAN_CS_DLC_MASK) >> CAN_CS_DLC_SHIFT);

        /* Get the time stamp. */
        psRxFrame->bitsTimestamp = (uint16_t)((cs_temp & CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT);

        /* Store Message Payload. */
        psRxFrame->u32DataWord0 = base->MB[0].WORD0;
        psRxFrame->u32DataWord1 = base->MB[0].WORD1;

        /* Store ID Filter Hit Index. */
        psRxFrame->bitsIdHit = (uint16_t)(base->RXFIR & CAN_RXFIR_IDHIT_MASK);

        /* Read free-running timer to unlock Rx Message Buffer. */
        (void)base->TIMER;

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
status_t FLEXCAN_WriteFDTxMb(CAN_Type *base, uint8_t u8MsgBufIdx, const flexcan_fd_frame_t *psTxFrame)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
    assert(NULL != psTxFrame);
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    status_t status;
    uint32_t cs_temp      = 0;
    uint8_t cnt           = 0;
    uint32_t can_cs       = 0;
    uint8_t payload_dword = 1;
    uint32_t dataSize     = (base->FDCTRL & CAN_FDCTRL_MBDSR0_MASK) >> CAN_FDCTRL_MBDSR0_SHIFT;
#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
    uint32_t availoffset = FLEXCAN_GetFDMailboxOffset(base, FLEXCAN_GetFirstValidMb(base));
#endif
    volatile uint32_t *mbAddr = &(base->MB[0].CS);
    uint32_t offset           = FLEXCAN_GetFDMailboxOffset(base, u8MsgBufIdx);

#if (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032)
    FLEXCAN_ERRATA_6032(base, &(mbAddr[offset]));
#endif

    can_cs = mbAddr[offset];
    /* Check if Message Buffer is available. */
    if (CAN_CS_CODE(kFLEXCAN_TxMbDataOrRemote) != (can_cs & CAN_CS_CODE_MASK))
    {
        /* Inactive Tx Message Buffer and Fill Message ID field. */
        mbAddr[offset]      = (can_cs & ~CAN_CS_CODE_MASK) | CAN_CS_CODE(kFLEXCAN_TxMbInactive);
        mbAddr[offset + 1U] = psTxFrame->bitsId;

        /* Fill Message Format field. */
        if ((uint32_t)kFLEXCAN_FrameFormatExtend == psTxFrame->bitFormat)
        {
            cs_temp |= CAN_CS_SRR_MASK | CAN_CS_IDE_MASK;
        }

        /* Fill Message Type field. */
        if ((uint32_t)kFLEXCAN_FrameTypeRemote == psTxFrame->bitType)
        {
            cs_temp |= CAN_CS_RTR_MASK;
        }

        cs_temp |= CAN_CS_CODE(kFLEXCAN_TxMbDataOrRemote) | CAN_CS_DLC(psTxFrame->bitsLength) |
                   CAN_CS_EDL(psTxFrame->bitEdl) | CAN_CS_BRS(psTxFrame->bitBrs);

        /* Calculate the DWORD number, dataSize 0/1/2/3 corresponds to 8/16/32/64
           Bytes payload. */
        for (cnt = 0; cnt < (dataSize + 1U); cnt++)
        {
            payload_dword *= 2U;
        }

        /* Load Message Payload and Activate Tx Message Buffer. */
        for (cnt = 0; cnt < payload_dword; cnt++)
        {
            mbAddr[offset + 2U + cnt] = psTxFrame->u32DataWord[cnt];
        }
        mbAddr[offset] = cs_temp;

#if ((defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641) || \
     (defined(FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829) && FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829))
        mbAddr[availoffset] = CAN_CS_CODE(kFLEXCAN_TxMbInactive);
        mbAddr[availoffset] = CAN_CS_CODE(kFLEXCAN_TxMbInactive);
#endif

        status = kStatus_Success;
    }
    else
    {
        /* Tx Message Buffer is activated, return immediately. */
        status = kStatus_Fail;
    }

    return status;
}

status_t FLEXCAN_ReadFDRxMb(CAN_Type *base, uint8_t u8MsgBufIdx, flexcan_fd_frame_t *psRxFrame)
{
    /* Assertion. */
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
    assert(NULL != psRxFrame);
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

    status_t status;
    uint32_t cs_temp;
    uint8_t rx_code;
    uint8_t cnt     = 0;
    uint32_t can_id = 0;
    uint32_t dataSize;
    dataSize                  = (base->FDCTRL & CAN_FDCTRL_MBDSR0_MASK) >> CAN_FDCTRL_MBDSR0_SHIFT;
    uint8_t payload_dword     = 1;
    volatile uint32_t *mbAddr = &(base->MB[0].CS);
    uint32_t offset           = FLEXCAN_GetFDMailboxOffset(base, u8MsgBufIdx);

    /* Read CS field of Rx Message Buffer to lock Message Buffer. */
    cs_temp = mbAddr[offset];
    can_id  = mbAddr[offset + 1U];

    /* Get Rx Message Buffer Code field. */
    rx_code = (uint8_t)((cs_temp & CAN_CS_CODE_MASK) >> CAN_CS_CODE_SHIFT);

    /* Check to see if Rx Message Buffer is full. */
    if (((uint8_t)kFLEXCAN_RxMbFull == rx_code) || ((uint8_t)kFLEXCAN_RxMbOverrun == rx_code))
    {
        /* Store Message ID. */
        psRxFrame->bitsId = can_id & (CAN_ID_EXT_MASK | CAN_ID_STD_MASK);

        /* Get the message ID and format. */
        psRxFrame->bitFormat = (cs_temp & CAN_CS_IDE_MASK) != 0U ? (uint8_t)kFLEXCAN_FrameFormatExtend :
                                                                   (uint8_t)kFLEXCAN_FrameFormatStandard;

        /* Get the message type. */
        psRxFrame->bitType =
            (cs_temp & CAN_CS_RTR_MASK) != 0U ? (uint8_t)kFLEXCAN_FrameTypeRemote : (uint8_t)kFLEXCAN_FrameTypeData;

        /* Get the message length. */
        psRxFrame->bitsLength = (uint8_t)((cs_temp & CAN_CS_DLC_MASK) >> CAN_CS_DLC_SHIFT);

        /* Get the time stamp. */
        psRxFrame->bitsTimestamp = (uint16_t)((cs_temp & CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT);

        /* Calculate the DWORD number, dataSize 0/1/2/3 corresponds to 8/16/32/64
           Bytes payload. */
        for (cnt = 0; cnt < (dataSize + 1U); cnt++)
        {
            payload_dword *= 2U;
        }

        /* Store Message Payload. */
        for (cnt = 0; cnt < payload_dword; cnt++)
        {
            psRxFrame->u32DataWord[cnt] = mbAddr[offset + 2U + cnt];
        }

        /* Read free-running timer to unlock Rx Message Buffer. */
        (void)base->TIMER;

        if ((uint32_t)kFLEXCAN_RxMbFull == rx_code)
        {
            status = kStatus_Success;
        }
        else
        {
            status = kStatus_FLEXCAN_RxOverflow;
        }
    }
    else
    {
        /* Read free-running timer to unlock Rx Message Buffer. */
        (void)base->TIMER;

        status = kStatus_Fail;
    }

    return status;
}
#endif
/* @} */

/*!
 * @name Transactional Blocking Interface
 * @{
 */

status_t FLEXCAN_TransferSendBlocking(CAN_Type *base, uint8_t u8MsgBufIdx, flexcan_frame_t *psTxFrame)
{
    status_t status;

    /* Write Tx Message Buffer to initiate a data sending. */
    if (kStatus_Success == FLEXCAN_WriteTxMb(base, u8MsgBufIdx, (const flexcan_frame_t *)(uint32_t)psTxFrame))
    {
/* Wait until CAN Message send out. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        uint64_t u64flag = 1;
        while (0U == FLEXCAN_GetMbStatusFlags(base, u64flag << u8MsgBufIdx))
#else
        uint32_t u32flag = 1;
        while (0U == FLEXCAN_GetMbStatusFlags(base, u32flag << u8MsgBufIdx))
#endif
        {
        }

/* Clean Tx Message Buffer Flag. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        FLEXCAN_ClearMbStatusFlags(base, u64flag << u8MsgBufIdx);
#else
        FLEXCAN_ClearMbStatusFlags(base, u32flag << u8MsgBufIdx);
#endif
        /*After TX MB tranfered success, update the Timestamp from MB[u8MsgBufIdx].CS register*/
        psTxFrame->bitsTimestamp =
            (uint16_t)((base->MB[u8MsgBufIdx].CS & CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT);

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

status_t FLEXCAN_TransferReceiveBlocking(CAN_Type *base, uint8_t u8MsgBufIdx, flexcan_frame_t *psRxFrame)
{
/* Wait until Rx Message Buffer non-empty. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t u64flag = 1;
    while (0U == FLEXCAN_GetMbStatusFlags(base, u64flag << u8MsgBufIdx))
#else
    uint32_t u32flag = 1;
    while (0U == FLEXCAN_GetMbStatusFlags(base, u32flag << u8MsgBufIdx))
#endif
    {
    }

/* Clean Rx Message Buffer Flag. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    FLEXCAN_ClearMbStatusFlags(base, u64flag << u8MsgBufIdx);
#else
    FLEXCAN_ClearMbStatusFlags(base, u32flag << u8MsgBufIdx);
#endif

    /* Read Received CAN Message. */
    return FLEXCAN_ReadRxMb(base, u8MsgBufIdx, psRxFrame);
}

status_t FLEXCAN_TransferReceiveFifoBlocking(CAN_Type *base, flexcan_frame_t *psRxFrame)
{
    status_t rxFifoStatus;

    /* Wait until Rx FIFO non-empty. */
    while (0U == FLEXCAN_GetMbStatusFlags(base, (uint32_t)kFLEXCAN_RxFifoFrameAvlFlag))
    {
    }

    /*  */
    rxFifoStatus = FLEXCAN_ReadRxFifo(base, psRxFrame);

    /* Clean Rx Fifo available flag. */
    FLEXCAN_ClearMbStatusFlags(base, (uint32_t)kFLEXCAN_RxFifoFrameAvlFlag);

    return rxFifoStatus;
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
status_t FLEXCAN_TransferFDSendBlocking(CAN_Type *base, uint8_t u8MsgBufIdx, flexcan_fd_frame_t *psTxFrame)
{
    status_t status;

    /* Write Tx Message Buffer to initiate a data sending. */
    if (kStatus_Success == FLEXCAN_WriteFDTxMb(base, u8MsgBufIdx, (const flexcan_fd_frame_t *)(uint32_t)psTxFrame))
    {
/* Wait until CAN Message send out. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        uint64_t u64flag = 1;
        while (0U == FLEXCAN_GetMbStatusFlags(base, u64flag << u8MsgBufIdx))
#else
        uint32_t u32flag = 1;
        while (0U == FLEXCAN_GetMbStatusFlags(base, u32flag << u8MsgBufIdx))
#endif
        {
        }

/* Clean Tx Message Buffer Flag. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        FLEXCAN_ClearMbStatusFlags(base, u64flag << u8MsgBufIdx);
#else
        FLEXCAN_ClearMbStatusFlags(base, u32flag << u8MsgBufIdx);
#endif
        /*After TX MB tranfered success, update the Timestamp from base->MB[offset for CANFD].CS register*/
        volatile uint32_t *mbAddr = &(base->MB[0].CS);
        uint32_t offset           = FLEXCAN_GetFDMailboxOffset(base, u8MsgBufIdx);
        psTxFrame->bitsTimestamp  = (uint16_t)((mbAddr[offset] & CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT);

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_Fail;
    }

    return status;
}

status_t FLEXCAN_TransferFDReceiveBlocking(CAN_Type *base, uint8_t u8MsgBufIdx, flexcan_fd_frame_t *psRxFrame)
{
/* Wait until Rx Message Buffer non-empty. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t u64flag = 1;
    while (0U == FLEXCAN_GetMbStatusFlags(base, u64flag << u8MsgBufIdx))
#else
    uint32_t u32flag = 1;
    while (0U == FLEXCAN_GetMbStatusFlags(base, u32flag << u8MsgBufIdx))
#endif
    {
    }

/* Clean Rx Message Buffer Flag. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    FLEXCAN_ClearMbStatusFlags(base, u64flag << u8MsgBufIdx);
#else
    FLEXCAN_ClearMbStatusFlags(base, u32flag << u8MsgBufIdx);
#endif

    /* Read Received CAN Message. */
    return FLEXCAN_ReadFDRxMb(base, u8MsgBufIdx, psRxFrame);
}

#endif

/* @} */

/*!
 * @name Transactional Non-Blocking Interfaces
 * @{
 */

uint32_t FLEXCAN_GetTimeStamp(flexcan_handle_t *psHandle, uint8_t u8MsgBufIdx)
{
    /* Assertion. */
    assert(NULL != psHandle);

    return (uint32_t)(psHandle->u32TimeStamps[u8MsgBufIdx]);
}

void FLEXCAN_TransferCreateHandle(CAN_Type *base,
                                  flexcan_handle_t *psHandle,
                                  flexcan_transfer_callback_t pfCallback,
                                  void *pUserData)
{
    assert(NULL != psHandle);

    uint8_t instance;

    /* Clean FlexCAN transfer handle. */
    (void)memset(psHandle, 0, sizeof(*psHandle));

    /* Store the base address */
    psHandle->base = base;

    /* Get instance from peripheral base address. */
    instance = (uint8_t)FLEXCAN_GetInstance(base);

    /* Save the context in global variables to support the double weak mechanism. */
    s_flexcanHandle[instance] = psHandle;

    /* Register Callback function. */
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;

    s_flexcanIsr = FLEXCAN_TransferHandleIRQ;

    /* We Enable Error & Status interrupt here, because this interrupt just
     * report current status of FlexCAN module through Callback function.
     * It is insignificance without a available pfCallback function.
     */
    if (psHandle->pfCallback != NULL)
    {
        FLEXCAN_EnableInterrupts(
            base, (uint32_t)kFLEXCAN_BusOffInterruptEnable | (uint32_t)kFLEXCAN_ErrorInterruptEnable |
                      (uint32_t)kFLEXCAN_RxWarningInterruptEnable | (uint32_t)kFLEXCAN_TxWarningInterruptEnable |
                      (uint32_t)kFLEXCAN_WakeUpInterruptEnable);
    }
    else
    {
        FLEXCAN_DisableInterrupts(
            base, (uint32_t)kFLEXCAN_BusOffInterruptEnable | (uint32_t)kFLEXCAN_ErrorInterruptEnable |
                      (uint32_t)kFLEXCAN_RxWarningInterruptEnable | (uint32_t)kFLEXCAN_TxWarningInterruptEnable |
                      (uint32_t)kFLEXCAN_WakeUpInterruptEnable);
    }

    /* Enable interrupts in NVIC. */
    (void)EnableIRQ((IRQn_Type)(s_flexcanRxWarningIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_flexcanTxWarningIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_flexcanWakeUpIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_flexcanErrorIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_flexcanBusOffIRQ[instance]));
    (void)EnableIRQ((IRQn_Type)(s_flexcanMbIRQ[instance]));
}

status_t FLEXCAN_TransferSendNonBlocking(flexcan_handle_t *psHandle, flexcan_mb_transfer_t *psMsgBufXfer)
{
    /* Assertion. */
    assert(NULL != psHandle);
    assert(NULL != psMsgBufXfer);

    CAN_Type *base = psHandle->base;
    status_t status;

    assert(psMsgBufXfer->u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, psMsgBufXfer->u8MsgBufIdx));
#endif

    /* Check if Message Buffer is idle. */
    if ((uint8_t)kFLEXCAN_StateIdle == psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx])
    {
        /* Distinguish transmit type. */
        if ((uint32_t)kFLEXCAN_FrameTypeRemote == psMsgBufXfer->psFrame->bitType)
        {
            psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateTxRemote;
        }
        else
        {
            psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateTxData;
        }

        if (kStatus_Success == FLEXCAN_WriteTxMb(base, psMsgBufXfer->u8MsgBufIdx,
                                                 (const flexcan_frame_t *)(uint32_t)psMsgBufXfer->psFrame))
        {
/* Enable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
            uint64_t u64mask = 1;
            FLEXCAN_EnableMbInterrupts(base, u64mask << psMsgBufXfer->u8MsgBufIdx);
#else
            uint32_t u32mask = 1;
            FLEXCAN_EnableMbInterrupts(base, u32mask << psMsgBufXfer->u8MsgBufIdx);
#endif
            status = kStatus_Success;
        }
        else
        {
            psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateIdle;
            status                                              = kStatus_Fail;
        }
    }
    else
    {
        status = kStatus_FLEXCAN_TxBusy;
    }

    return status;
}

status_t FLEXCAN_TransferReceiveNonBlocking(flexcan_handle_t *psHandle, flexcan_mb_transfer_t *psMsgBufXfer)
{
    status_t status;

    /* Assertion. */
    assert(NULL != psHandle);
    assert(NULL != psMsgBufXfer);

    CAN_Type *base = psHandle->base;

    assert(psMsgBufXfer->u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, psMsgBufXfer->u8MsgBufIdx));
#endif

    /* Check if Message Buffer is idle. */
    if ((uint8_t)kFLEXCAN_StateIdle == psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx])
    {
        psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateRxData;

        /* Register Message Buffer. */
        psHandle->psMbFrameBufs[psMsgBufXfer->u8MsgBufIdx] = psMsgBufXfer->psFrame;

/* Enable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        uint64_t u64mask = 1;
        FLEXCAN_EnableMbInterrupts(base, u64mask << psMsgBufXfer->u8MsgBufIdx);
#else
        uint32_t u32mask = 1;
        FLEXCAN_EnableMbInterrupts(base, u32mask << psMsgBufXfer->u8MsgBufIdx);
#endif

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_FLEXCAN_RxBusy;
    }

    return status;
}

status_t FLEXCAN_TransferReceiveFifoNonBlocking(flexcan_handle_t *psHandle, flexcan_fifo_transfer_t *psFifoXfer)
{
    /* Assertion. */
    assert(NULL != psHandle);
    assert(NULL != psFifoXfer);

    status_t status;
    CAN_Type *base = psHandle->base;

    /* Check if Message Buffer is idle. */
    if ((uint8_t)kFLEXCAN_StateIdle == psHandle->u8RxFifoState)
    {
        psHandle->u8RxFifoState = (uint8_t)kFLEXCAN_StateRxFifo;

        /* Register Message Buffer. */
        psHandle->psRxFifoFrameBuf = psFifoXfer->psFrame;

        /* Enable Message Buffer Interrupt. */
        FLEXCAN_EnableMbInterrupts(base, (uint32_t)kFLEXCAN_RxFifoOverflowFlag | (uint32_t)kFLEXCAN_RxFifoWarningFlag |
                                             (uint32_t)kFLEXCAN_RxFifoFrameAvlFlag);

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_FLEXCAN_RxFifoBusy;
    }

    return status;
}

void FLEXCAN_TransferAbortSend(flexcan_handle_t *psHandle, uint8_t u8MsgBufIdx)
{
    uint16_t timestamp;
    CAN_Type *base = psHandle->base;

    /* Assertion. */
    assert(NULL != psHandle);
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

/* Disable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t u64mask = 1;
    FLEXCAN_DisableMbInterrupts(base, u64mask << u8MsgBufIdx);
#else
    uint32_t u32mask = 1;
    FLEXCAN_DisableMbInterrupts(base, u32mask << u8MsgBufIdx);
#endif

    /* Update the TX frame 's time stamp by MB[u8MsgBufIdx].cs. */
    timestamp = (uint16_t)((base->MB[u8MsgBufIdx].CS & CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT);
    psHandle->u32TimeStamps[u8MsgBufIdx] = timestamp;

    /* Clean Message Buffer. */
    FLEXCAN_SetTxMbConfig(base, u8MsgBufIdx, true);

    psHandle->u8MsgBufStates[u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateIdle;
}

void FLEXCAN_TransferAbortReceive(flexcan_handle_t *psHandle, uint8_t u8MsgBufIdx)
{
    CAN_Type *base = psHandle->base;

    /* Assertion. */
    assert(NULL != psHandle);
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

/* Disable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t u64mask = 1;
    FLEXCAN_DisableMbInterrupts(base, (u64mask << u8MsgBufIdx));
#else
    uint32_t u32mask = 1;
    FLEXCAN_DisableMbInterrupts(base, (u32mask << u8MsgBufIdx));
#endif

    /* Un-register psHandle. */
    psHandle->psMbFrameBufs[u8MsgBufIdx]  = NULL;
    psHandle->u8MsgBufStates[u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateIdle;
}

void FLEXCAN_TransferAbortReceiveFifo(flexcan_handle_t *psHandle)
{
    /* Assertion. */
    assert(NULL != psHandle);

    CAN_Type *base = psHandle->base;

    /* Check if Rx FIFO is enabled. */
    if (0U != (base->MCR & CAN_MCR_RFEN_MASK))
    {
        /* Disable Rx Message FIFO Interrupts. */
        FLEXCAN_DisableMbInterrupts(base, (uint32_t)kFLEXCAN_RxFifoOverflowFlag | (uint32_t)kFLEXCAN_RxFifoWarningFlag |
                                              (uint32_t)kFLEXCAN_RxFifoFrameAvlFlag);

        /* Un-register psHandle. */
        psHandle->psRxFifoFrameBuf = NULL;
    }

    psHandle->u8RxFifoState = (uint8_t)kFLEXCAN_StateIdle;
}

#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
status_t FLEXCAN_TransferFDSendNonBlocking(flexcan_handle_t *psHandle, flexcan_mb_transfer_t *psMsgBufXfer)
{
    /* Assertion. */
    assert(NULL != psHandle);
    assert(NULL != psMsgBufXfer);

    status_t status;
    CAN_Type *base = psHandle->base;
    assert(psMsgBufXfer->u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, psMsgBufXfer->u8MsgBufIdx));
#endif

    /* Check if Message Buffer is idle. */
    if ((uint8_t)kFLEXCAN_StateIdle == psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx])
    {
        /* Distinguish transmit type. */
        if ((uint32_t)kFLEXCAN_FrameTypeRemote == psMsgBufXfer->psFrameFD->bitType)
        {
            psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateTxRemote;
        }
        else
        {
            psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateTxData;
        }

        if (kStatus_Success == FLEXCAN_WriteFDTxMb(base, psMsgBufXfer->u8MsgBufIdx,
                                                   (const flexcan_fd_frame_t *)(uint32_t)psMsgBufXfer->psFrameFD))
        {
/* Enable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
            uint64_t u64mask = 1;
            FLEXCAN_EnableMbInterrupts(base, u64mask << psMsgBufXfer->u8MsgBufIdx);
#else
            uint32_t u32mask = 1;
            FLEXCAN_EnableMbInterrupts(base, u32mask << psMsgBufXfer->u8MsgBufIdx);
#endif

            status = kStatus_Success;
        }
        else
        {
            psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateIdle;
            status                                              = kStatus_Fail;
        }
    }
    else
    {
        status = kStatus_FLEXCAN_TxBusy;
    }

    return status;
}

status_t FLEXCAN_TransferFDReceiveNonBlocking(flexcan_handle_t *psHandle, flexcan_mb_transfer_t *psMsgBufXfer)
{
    /* Assertion. */
    assert(NULL != psHandle);
    assert(NULL != psMsgBufXfer);

    CAN_Type *base = psHandle->base;
    status_t status;
    assert(psMsgBufXfer->u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, psMsgBufXfer->u8MsgBufIdx));
#endif

    /* Check if Message Buffer is idle. */
    if ((uint8_t)kFLEXCAN_StateIdle == psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx])
    {
        psHandle->u8MsgBufStates[psMsgBufXfer->u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateRxData;

        /* Register Message Buffer. */
        psHandle->psFDMbFrameBufs[psMsgBufXfer->u8MsgBufIdx] = psMsgBufXfer->psFrameFD;

/* Enable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        uint64_t u64mask = 1;
        FLEXCAN_EnableMbInterrupts(base, u64mask << psMsgBufXfer->u8MsgBufIdx);
#else
        uint32_t u32mask = 1;
        FLEXCAN_EnableMbInterrupts(base, u32mask << psMsgBufXfer->u8MsgBufIdx);
#endif

        status = kStatus_Success;
    }
    else
    {
        status = kStatus_FLEXCAN_RxBusy;
    }

    return status;
}

void FLEXCAN_TransferFDAbortSend(flexcan_handle_t *psHandle, uint8_t u8MsgBufIdx)
{
    volatile uint32_t *mbAddr;
    uint32_t offset;
    uint16_t timestamp;
    CAN_Type *base = psHandle->base;

    /* Assertion. */
    assert(NULL != psHandle);
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

/* Disable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t u64mask = 1;
    FLEXCAN_DisableMbInterrupts(base, u64mask << u8MsgBufIdx);
#else
    uint32_t u32mask = 1;
    FLEXCAN_DisableMbInterrupts(base, u32mask << u8MsgBufIdx);
#endif

    /* Update the TX frame 's time stamp by base->MB[offset for CANFD].CS. */
    mbAddr    = &(base->MB[0].CS);
    offset    = FLEXCAN_GetFDMailboxOffset(base, u8MsgBufIdx);
    timestamp = (uint16_t)((mbAddr[offset] & CAN_CS_TIME_STAMP_MASK) >> CAN_CS_TIME_STAMP_SHIFT);
    psHandle->u32TimeStamps[u8MsgBufIdx] = timestamp;

    /* Clean Message Buffer. */
    FLEXCAN_SetFDTxMbConfig(base, u8MsgBufIdx, true);

    psHandle->u8MsgBufStates[u8MsgBufIdx] = (uint8_t)kFLEXCAN_StateIdle;
}

void FLEXCAN_TransferFDAbortReceive(flexcan_handle_t *psHandle, uint8_t u8MsgBufIdx)
{
    /* Assertion. */
    assert(NULL != psHandle);

    CAN_Type *base = psHandle->base;
    assert(u8MsgBufIdx <= (base->MCR & CAN_MCR_MAXMB_MASK));
#if !defined(NDEBUG)
    assert(!FLEXCAN_IsMbOccupied(base, u8MsgBufIdx));
#endif

/* Disable Message Buffer Interrupt. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t u64mask = 1;
    FLEXCAN_DisableMbInterrupts(base, u64mask << u8MsgBufIdx);
#else
    uint32_t u32mask = 1;
    FLEXCAN_DisableMbInterrupts(base, u32mask << u8MsgBufIdx);
#endif

    /* Un-register psHandle. */
    psHandle->psFDMbFrameBufs[u8MsgBufIdx] = NULL;
    psHandle->u8MsgBufStates[u8MsgBufIdx]  = (uint8_t)kFLEXCAN_StateIdle;
}

#endif

/* @} */

/*!
 * @name Transactional Interrupt handler
 * @{
 */

static bool FLEXCAN_CheckUnhandleInterruptEvents(CAN_Type *base)
{
    uint32_t tempmask[2] = {0};
    uint32_t tempflag[2] = {0};
    bool bFgRet          = false;

    /* Checking exist error flag. */
    if (0U == (FLEXCAN_GetStatusFlags(base) &
               ((uint32_t)kFLEXCAN_TxWarningIntFlag | (uint32_t)kFLEXCAN_RxWarningIntFlag |
                (uint32_t)kFLEXCAN_BusOffIntFlag | (uint32_t)kFLEXCAN_ErrorIntFlag | (uint32_t)kFLEXCAN_WakeUpIntFlag)))
    {
        tempmask[0] = base->IMASK1;
        tempflag[0] = base->IFLAG1;

#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        /* Checking whether exist MB interrupt status and legacy RX FIFO interrupt status. */
        tempmask[1] = base->IMASK2;
        tempflag[1] = base->IFLAG2;
#endif
        bFgRet = (0U != ((tempmask[0] & tempflag[0]) | (tempmask[1] & tempflag[1])));
    }
    else
    {
        bFgRet = true;
    }

    return bFgRet;
}

static status_t FLEXCAN_SubHandlerForDataTransfered(CAN_Type *base, flexcan_handle_t *psHandle, uint32_t *pResult)
{
    status_t status = kStatus_FLEXCAN_UnHandled;
    uint32_t result = 0xFFU;

    /* For this implementation, we solve the Message with lowest MB index first. */
    for (result = 0U; result < (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base); result++)
    {
        /* Get the lowest unhandled Message Buffer */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        uint64_t u64flag = 1;
        if (0U != FLEXCAN_GetMbStatusFlags(base, u64flag << result))
#else
        uint32_t u32flag = 1;
        if (0U != FLEXCAN_GetMbStatusFlags(base, u32flag << result))
#endif
        {
            if (FLEXCAN_IsMbIntEnabled(base, (uint8_t)result))
            {
                break;
            }
        }
    }

    /* find Message to deal with. */
    if (result < (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(base))
    {
        /* Solve Legacy Rx FIFO interrupt. */
        if (((uint8_t)kFLEXCAN_StateIdle != psHandle->u8RxFifoState) && (result <= (uint32_t)CAN_IFLAG1_BUF7I_SHIFT))
        {
            uint32_t u32mask = 1UL << result;
            if (0U != (u32mask & (uint32_t)kFLEXCAN_RxFifoOverflowFlag))
            {
                status = kStatus_FLEXCAN_RxFifoOverflow;
            }
            else if (0U != (u32mask & (uint32_t)kFLEXCAN_RxFifoWarningFlag))
            {
                status = kStatus_FLEXCAN_RxFifoWarning;
            }
            else if (0U != (u32mask & (uint32_t)kFLEXCAN_RxFifoFrameAvlFlag))
            {
                status = FLEXCAN_ReadRxFifo(base, psHandle->psRxFifoFrameBuf);
                if (kStatus_Success == status)
                {
                    /* Align the current (index 0) rxfifo timestamp to the timestamp array by psHandle. */
                    psHandle->u32TimeStamps[0] = psHandle->psRxFifoFrameBuf->bitsTimestamp;
                    status                     = kStatus_FLEXCAN_RxFifoIdle;
                }
                FLEXCAN_TransferAbortReceiveFifo(psHandle);
            }
            else
            {
                status = kStatus_FLEXCAN_UnHandled;
            }
        }
        else
        {
            /* Get current State of Message Buffer. */
            switch (psHandle->u8MsgBufStates[result])
            {
                /* Solve Rx Data Frame. */
                case (uint8_t)kFLEXCAN_StateRxData:
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
                    if (0U != (base->MCR & CAN_MCR_FDEN_MASK))
                    {
                        status = FLEXCAN_ReadFDRxMb(base, (uint8_t)result, psHandle->psFDMbFrameBufs[result]);
                        if (kStatus_Success == status)
                        {
                            /* Align the current index of RX MB timestamp to the timestamp array by psHandle. */
                            psHandle->u32TimeStamps[result] = psHandle->psFDMbFrameBufs[result]->bitsTimestamp;
                            status                          = kStatus_FLEXCAN_RxIdle;
                        }
                    }
                    else
#endif
                    {
                        status = FLEXCAN_ReadRxMb(base, (uint8_t)result, psHandle->psMbFrameBufs[result]);
                        if (kStatus_Success == status)
                        {
                            /* Align the current index of RX MB timestamp to the timestamp array by psHandle. */
                            psHandle->u32TimeStamps[result] = psHandle->psMbFrameBufs[result]->bitsTimestamp;
                            status                          = kStatus_FLEXCAN_RxIdle;
                        }
                    }
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
                    if (0U != (base->MCR & CAN_MCR_FDEN_MASK))
                    {
                        FLEXCAN_TransferFDAbortReceive(psHandle, (uint8_t)result);
                    }
                    else
#endif
                    {
                        FLEXCAN_TransferAbortReceive(psHandle, (uint8_t)result);
                    }
                    break;

                /* Sove Rx Remote Frame.  User need to Read the frame in Mail box in time by Read from MB API. */
                case (uint8_t)kFLEXCAN_StateRxRemote:
                    status = kStatus_FLEXCAN_RxRemote;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
                    if (0U != (base->MCR & CAN_MCR_FDEN_MASK))
                    {
                        FLEXCAN_TransferFDAbortReceive(psHandle, (uint8_t)result);
                    }
                    else
#endif
                    {
                        FLEXCAN_TransferAbortReceive(psHandle, (uint8_t)result);
                    }
                    break;

                /* Solve Tx Data Frame. */
                case (uint8_t)kFLEXCAN_StateTxData:
                    status = kStatus_FLEXCAN_TxIdle;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
                    if (0U != (base->MCR & CAN_MCR_FDEN_MASK))
                    {
                        FLEXCAN_TransferFDAbortSend(psHandle, (uint8_t)result);
                    }
                    else
#endif
                    {
                        FLEXCAN_TransferAbortSend(psHandle, (uint8_t)result);
                    }
                    break;

                /* Solve Tx Remote Frame. */
                case (uint8_t)kFLEXCAN_StateTxRemote:
                    psHandle->u8MsgBufStates[result] = (uint8_t)kFLEXCAN_StateRxRemote;
                    status                           = kStatus_FLEXCAN_TxSwitchToRx;
                    break;

                default:
                    status = kStatus_FLEXCAN_UnHandled;
                    break;
            }
        }

        /* Clear resolved Message Buffer IRQ. */
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
        uint64_t u64flag = 1;
        FLEXCAN_ClearMbStatusFlags(base, u64flag << result);
#else
        uint32_t u32flag = 1;
        FLEXCAN_ClearMbStatusFlags(base, u32flag << result);
#endif
    }

    *pResult = result;

    return status;
}

void FLEXCAN_TransferHandleIRQ(flexcan_handle_t *psHandle)
{
    /* Assertion. */
    assert(NULL != psHandle);

    status_t status;
    uint32_t result    = 0xFFU;
    uint32_t EsrStatus = 0U;
    CAN_Type *base     = psHandle->base;
    do
    {
        /* Get Current FlexCAN Module Error and Status. */
        EsrStatus = FLEXCAN_GetStatusFlags(base);

        /* To psHandle FlexCAN Error and Status Interrupt first. */
        if (0U != (EsrStatus & ((uint32_t)kFLEXCAN_TxWarningIntFlag | (uint32_t)kFLEXCAN_RxWarningIntFlag |
                                (uint32_t)kFLEXCAN_BusOffIntFlag | (uint32_t)kFLEXCAN_ErrorIntFlag)))
        {
            status = kStatus_FLEXCAN_ErrorStatus;
            /* Clear FlexCAN Error and Status Interrupt. */
            FLEXCAN_ClearStatusFlags(base, (uint32_t)kFLEXCAN_TxWarningIntFlag | (uint32_t)kFLEXCAN_RxWarningIntFlag |
                                               (uint32_t)kFLEXCAN_BusOffIntFlag | (uint32_t)kFLEXCAN_ErrorIntFlag);
        }
        else if (0U != (EsrStatus & (uint32_t)kFLEXCAN_WakeUpIntFlag))
        {
            status = kStatus_FLEXCAN_WakeUp;
            FLEXCAN_ClearStatusFlags(base, (uint32_t)kFLEXCAN_WakeUpIntFlag);
        }
        else
        {
            /* to psHandle real data transfer. */
            status = FLEXCAN_SubHandlerForDataTransfered(base, psHandle, &result);
        }

        /* Calling Callback Function if has one. */
        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle, status, result, psHandle->pUserData);
        }
    } while (FLEXCAN_CheckUnhandleInterruptEvents(base));
}

/* @} */

/*!
 * @name Transactional Prepared Interrupt Entry
 * @{
 */

#if defined(CAN0) || defined(CAN)
void CAN0_DriverIRQHandler(void);
void CAN0_DriverIRQHandler(void)
{
    assert(NULL != s_flexcanHandle[0]);

    s_flexcanIsr(s_flexcanHandle[0]);
/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(CAN1)
void CAN1_DriverIRQHandler(void);
void CAN1_DriverIRQHandler(void)
{
    assert(NULL != s_flexcanHandle[1]);

    s_flexcanIsr(s_flexcanHandle[1]);
/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(CAN2)
void CAN2_DriverIRQHandler(void);
void CAN2_DriverIRQHandler(void)
{
    assert(NULL != s_flexcanHandle[2]);

    s_flexcanIsr(s_flexcanHandle[2]);
/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(CAN3)
void CAN3_DriverIRQHandler(void);
void CAN3_DriverIRQHandler(void)
{
    assert(NULL != s_flexcanHandle[3]);

    s_flexcanIsr(s_flexcanHandle[3]);
/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(CAN4)
void CAN4_DriverIRQHandler(void);
void CAN4_DriverIRQHandler(void)
{
    assert(NULL != s_flexcanHandle[4]);

    s_flexcanIsr(s_flexcanHandle[4]);
/* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
  exception return operation might vector to incorrect interrupt */
    SDK_ISR_EXIT_BARRIER;
}
#endif

/* @} */