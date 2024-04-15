/* -------------------------------------------------------------------------- */
/*                           Copyright 2023 NXP                               */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform.h"
#include "fwk_platform_lowpower.h"

/* SDK components */
#include "fsl_pm_core.h"
#include "fsl_pm_device.h"
#include "fsl_power.h"
#include "fsl_debug_console.h"
#include "fsl_usart.h"
#include "fsl_rtc.h"
#include "board.h"
#include "fsl_os_abstraction.h"
#include "pmic_support.h"
#include "controller_low_power.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
static USART_Type *const s_HciUsartBase[] = USART_BASE_PTRS;
/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize RTC to be used as a wake up source
 *
 */
static void PLATFORM_InitRtc(void);

/*!
 * \brief Initialize Pmic
 *
 */
static void PLATFORM_InitPmic(void);
static void PLATFORM_ConfigPMICMode(pca9420_modecfg_t *cfg);

/*!
 * \brief Initializes wake up sources
 *
 */
static void PLATFORM_InitWakeUpSources(void);

/*!
 * \brief Callback registered to SDK Power Manager to get notified of entry/exit of low power modes
 *
 * \param[in] eventType event specifying if we entered or exited from low power mode
 * \param[in] powerState low power mode used during low power period
 * \param[in] data Optional data passed when the callback got registered (not used currently)
 * \return status_t
 */
static status_t PLATFORM_LowPowerCallback(pm_event_type_t eventType, uint8_t powerState, void *data);

void RTC_IRQHandler(void);
/* -------------------------------------------------------------------------- */
/*                             Private variables                              */
/* -------------------------------------------------------------------------- */

static pm_notify_element_t platformLpNotifyGroup = {
    .notifyCallback = PLATFORM_LowPowerCallback,
    .data           = NULL,
};

static pm_wakeup_source_t C2HWakeupSource;
static pm_wakeup_source_t timerWakeupSource;

static uint16_t wakeUpTimerStartCount = 0U;
static uint16_t wakeUpTimerStopCount  = 0U;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_LowPowerInit(void)
{
    status_t status;

    POWER_ClearEventFlags(POWER_GetEventFlags());

    /* Init Pmic */
    PLATFORM_InitPmic();

    /* Register the low power Notify callback as high priority. */
    status = PM_RegisterNotify(kPM_NotifyGroup2, &platformLpNotifyGroup);
    assert(status == kStatus_Success);
    (void)status;

    /* Init mandatory wake up sources such as BLE wake up. */
    PLATFORM_InitWakeUpSources();
}

void PLATFORM_InitWakeUpTimer(void)
{
    /* Init RTC to be used as wake up source. */
    PLATFORM_InitRtc();

    /* Init timestamp module to measure low power duration. */
    PLATFORM_InitTimeStamp();
}

uint8_t PLATFORM_ControllerLowPowerInit(void)
{
    return controller_low_power_init();
}

void PLATFORM_StartWakeUpTimer(uint64_t timeOutUs)
{
    RTC_EnableTimer(RTC, false);
    /* clockFreqInHz shoule be equal to configTICK_RATE_HZ. */
    wakeUpTimerStartCount = (uint16_t)USEC_TO_COUNT(timeOutUs, 1000U);
    RTC_SetWakeupCount(RTC, wakeUpTimerStartCount);
    RTC_EnableWakeupTimer(RTC, true);
    RTC_EnableTimer(RTC, true);
}

void PLATFORM_StopWakeUpTimer(void)
{
    do
    {
        wakeUpTimerStopCount = RTC_GetWakeupCount(RTC);
    } while (wakeUpTimerStopCount > wakeUpTimerStartCount);

    RTC_ClearStatusFlags(RTC, RTC_GetStatusFlags(RTC));
    /* Clear all FLAGS. */
    POWER_ClearEventFlags(POWER_GetEventFlags());
    NVIC_ClearPendingIRQ(RTC_IRQn);
    RTC_EnableWakeupTimer(RTC, false);
    RTC_EnableTimer(RTC, false);
}

uint64_t PLATFORM_GetLowPowerTimestampUs(void)
{
    return PLATFORM_GetTimeStamp();
}

uint64_t PLATFORM_GetLowPowerDurationUs(uint64_t enterLowPowerTimestamp, uint64_t exitLowPowerTimestamp)
{
    uint64_t durationUs;

    if (exitLowPowerTimestamp < enterLowPowerTimestamp)
    {
        durationUs = PLATFORM_GetMaxTimeStamp() - enterLowPowerTimestamp + exitLowPowerTimestamp;
    }
    else
    {
        durationUs = exitLowPowerTimestamp - enterLowPowerTimestamp;
    }

    return durationUs;
}

void PLATFORM_EnterLowPower(void)
{
    /* If do not disable BT UART, host RTS will stay low even when enters low power mode.
     * There might be a risk that controller will send data to host even when host is not totally waken up. */
    s_HciUsartBase[BOARD_BT_UART_INSTANCE]->CFG &= ~((uint32_t)USART_CFG_ENABLE_MASK);
    controller_enter_low_power();
}

void PLATFORM_ExitLowPower(void)
{
    controller_exit_low_power();
    for (uint32_t i = 0; i < 2000; i++)
    {
        __NOP();
    }
    s_HciUsartBase[BOARD_BT_UART_INSTANCE]->CFG |= ((uint32_t)USART_CFG_ENABLE_MASK);
}

void PLATFORM_EnterDeepSleep(void)
{
}

void PLATFORM_ExitDeepSleep(void)
{
}

void PLATFORM_EnterPowerDown(void)
{
}

void PLATFORM_ExitPowerDown(void)
{
    /* Note that this code is never reached,
     * because device re-boot according to power driver. */
}

void PLATFORM_EnterDeepPowerDown(void)
{
    /* Note that this code is never reached,
     * because device re-boot according to power driver. */
}

uint32_t PLATFORM_GetDefaultRamBanksRetained(void)
{
    /* Retain everything by default. */
    uint8_t bank_mask = 0xFFU;
    return bank_mask;
}

void PLATFORM_SetRamBanksRetained(uint32_t bank_mask)
{
}

uint8_t PLATFORM_AllowEnterLowPower(void)
{
    return controller_power_state();
}

void RTC_IRQHandler(void)
{
    RTC_ClearStatusFlags(RTC, RTC_GetStatusFlags(RTC));
    SDK_ISR_EXIT_BARRIER;
}
/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static void PLATFORM_InitWakeUpSources(void)
{
    /* Enable wake up source from BLE controller to wake up the device. */
    PM_InitWakeupSource(&C2HWakeupSource, (uint32_t)GPIO_INTA_IRQn, NULL, true);
}

static void PLATFORM_InitRtc(void)
{
    RTC_Init(RTC);
    RTC_EnableTimer(RTC, false);
    EnableIRQ(RTC_IRQn);
    RTC_EnableWakeUpTimerInterruptFromDPD(RTC, true);
    NVIC_ClearPendingIRQ(RTC_IRQn);

    /* Enable RTC as wakeup source. */
    PM_InitWakeupSource(&timerWakeupSource, (uint32_t)RTC_IRQn, NULL, true);
}

static void PLATFORM_InitPmic(void)
{
    /* PMIC PCA9420 */
    pca9420_modecfg_t pca9420ModeCfg[4];
    uint32_t          i;

    /* BE CAUTIOUS TO SET CORRECT VOLTAGE RANGE ACCORDING TO YOUR BOARD/APPLICATION. PAD SUPPLY BEYOND THE RANGE DO
    HARM TO THE SILICON. */
    power_pad_vrange_t vrange = {.Vdde0Range = kPadVol_171_198,
                                 .Vdde1Range = kPadVol_171_198,
                                 .Vdde2Range = kPadVol_171_198,
                                 .Vdde3Range = kPadVol_300_360,
                                 .Vdde4Range = kPadVol_171_198};

    /* Initialize the PMIC. */
    BOARD_InitPmic();

    /* Indicate to power library that an external PMIC is used. */
    POWER_UpdatePmicRecoveryTime(1);

    /* Set PMIC configurations. */
    for (i = 0; i < ARRAY_SIZE(pca9420ModeCfg); i++)
    {
        PCA9420_GetDefaultModeConfig(&pca9420ModeCfg[i]);
    }
    PLATFORM_ConfigPMICMode(pca9420ModeCfg);

    /* Send new configuration to PMIC. */
    PCA9420_WriteModeConfigs(&pca9420Handle, kPCA9420_Mode0, &pca9420ModeCfg[0], ARRAY_SIZE(pca9420ModeCfg));

    /* Configure PMIC Vddcore value according to CM33 clock. */
    BOARD_SetPmicVoltageForFreq(CLOCK_GetFreq(kCLOCK_CoreSysClk), 0U);

    /* Configure pads voltage ranges according to PMIC settings. */
    POWER_SetPadVolRange(&vrange);

    RESET_SetPeripheralReset(kFC15_RST_SHIFT_RSTn);
    CLOCK_AttachClk(kNONE_to_FLEXCOMM15);
}

static void PLATFORM_ConfigPMICMode(pca9420_modecfg_t *cfg)
{
    assert(cfg);

    /* Configuration PMIC mode to align with power lib like below:
     *  0b00    active mode                vddcore 0.9V
     *  0b01    deep sleep mode            vddcore 0.6V
     *  0b10    deep powerdown mode        vddcore power off
     *  0b11    full deep powerdown mode   power off */

    /* Mode 0: VDDCORE 0.9V. */
    cfg[0].sw1OutVolt = kPCA9420_Sw1OutVolt0V900;
    /* Mode 1: VDDCORE 0.6V. */
    cfg[1].sw1OutVolt = kPCA9420_Sw1OutVolt0V600;
    /* Mode 2: VDDCORE off. */
    cfg[2].enableSw1Out = false;
    /* Mode 3: VDDCORE, VDD1V8 and VDDIO off. */
    cfg[3].enableSw1Out  = false;
    cfg[3].enableSw2Out  = false;
    cfg[3].enableLdo2Out = false;
}

static status_t PLATFORM_LowPowerCallback(pm_event_type_t eventType, uint8_t powerState, void *data)
{
    (void)data;

    if (eventType == kPM_EventEnteringSleep)
    {
        PLATFORM_EnterLowPower();
    }
    else
    {
        PLATFORM_ExitLowPower();
    }

    return kStatus_Success;
}
