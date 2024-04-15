/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2023 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform.h"
#include "fwk_config.h"
#include "fwk_platform_lowpower.h"
#include "fwk_platform_ble.h"

/* SDK components */
#include "fsl_pm_core.h"
#include "fsl_pm_device.h"
#include "fsl_power.h"
#include "fsl_debug_console.h"
#include "fsl_usart.h"
#include "fsl_rtc.h"
#include "fsl_os_abstraction.h"
#include "fsl_loader.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#define PLATFORM_MAX_WAKE_UP_TIMER_COUNT ((uint64_t)0xFFFFU)

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

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

/*!
 * \brief Initialize RTC to be used as a wake up source
 *
 */
static void PLATFORM_InitRtc(void);

void RTC_IRQHandler(void);

/* -------------------------------------------------------------------------- */
/*                             Private variables                              */
/* -------------------------------------------------------------------------- */

static pm_notify_element_t platformLpNotifyGroup = {
    .notifyCallback = PLATFORM_LowPowerCallback,
    .data           = NULL,
};

static pm_wakeup_source_t bleWakeUpSourceImu;
static pm_wakeup_source_t timerWakeupSource;
static pm_wakeup_source_t wlanWakeupSource;

static uint16_t wakeUpTimerStartCount = 0U;
static uint16_t wakeUpTimerStopCount  = 0U;

static power_init_config_t initCfg = {
    /* VCORE AVDD18 supplied from iBuck on RD board. */
    .iBuck = true,
    /* CAU_SOC_SLP_REF_CLK not needed. */
    .gateCauRefClk = true,
};

static bool wasPowerDown = false;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_LowPowerInit(void)
{
    status_t status;
    uint32_t resetSrc = POWER_GetResetCause();
    POWER_ClearResetCause(resetSrc);
    POWER_InitPowerConfig(&initCfg);

    /* Register the low power Notify callback as high priority (kPM_NotifyGroup2) */
    status = PM_RegisterNotify(kPM_NotifyGroup2, &platformLpNotifyGroup);
    assert(status == kStatus_Success);
    (void)status;

    /* Init mandatory wake up sources such as BLE wake up and RTC */
    PLATFORM_InitWakeUpSources();
}

void PLATFORM_InitWakeUpTimer(void)
{
    /* Init RTC to be used as wake up source */
    PLATFORM_InitRtc();

    /* Init timestamp module to measure low power duration (Only for PM0/1/2) */
    PLATFORM_InitTimeStamp();
}

void PLATFORM_StartWakeUpTimer(uint64_t timeOutUs)
{
    uint64_t timeOutCount = USEC_TO_COUNT(timeOutUs, 1000U);

    /* Wake up count is only coded on 16bits, so we have to be careful and handle any overlap */
    if (timeOutCount >= PLATFORM_MAX_WAKE_UP_TIMER_COUNT)
    {
        timeOutCount = PLATFORM_MAX_WAKE_UP_TIMER_COUNT;
    }

    wakeUpTimerStartCount = (uint16_t)timeOutCount;
    RTC_SetWakeupCount(RTC, wakeUpTimerStartCount);
}

void PLATFORM_StopWakeUpTimer(void)
{
    /* MCRED-99: The RTC wake up count shall always be equal or less than the count value set in
     * PLATFORM_StartWakeUpTimer as the RTC wake up timer is a count-down timer It happens this read is not correct the
     * first time and we get a higher value that the initial count so it corrupts the elapsed time
     * To workaround this, we make sure the count is lower than the initial value, otherwise we read again */
    do
    {
        wakeUpTimerStopCount = RTC_GetWakeupCount(RTC);
    } while (wakeUpTimerStopCount > wakeUpTimerStartCount);

    RTC_EnableWakeupTimer(RTC, false);
    RTC_ClearStatusFlags(RTC, RTC_GetStatusFlags(RTC));
    POWER_ClearWakeupStatus(RTC_IRQn);
    NVIC_ClearPendingIRQ(RTC_IRQn);
}

uint64_t PLATFORM_GetLowPowerTimestampUs(void)
{
    return PLATFORM_GetTimeStamp();
}

uint64_t PLATFORM_GetLowPowerDurationUs(uint64_t enterLowPowerTimestamp, uint64_t exitLowPowerTimestamp)
{
    uint64_t durationUs;

    if (wasPowerDown == true)
    {
        durationUs = (uint64_t)COUNT_TO_USEC((uint64_t)wakeUpTimerStartCount, 1000U) -
                     (uint64_t)COUNT_TO_USEC((uint64_t)wakeUpTimerStopCount, 1000U);
        wasPowerDown = false;
    }
    else if (exitLowPowerTimestamp < enterLowPowerTimestamp)
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
    /* Placeholder RFU */
    ;
}

void PLATFORM_ExitLowPower(void)
{
    /* Placeholder RFU */ /* MISRA CID 28201050 */
    ;
}

void PLATFORM_EnterPowerDown(void)
{
    wasPowerDown = true;
}

void PLATFORM_ExitPowerDown(void)
{
    POWER_InitPowerConfig(&initCfg);
    PLATFORM_TimeStampExitPowerDown();
    RTC_Init(RTC);
}

void PLATFORM_EnterDeepPowerDown(void)
{
    power_off_device(LOAD_BLE_FIRMWARE);
    power_off_device(LOAD_WIFI_FIRMWARE);
}

uint8_t PLATFORM_GetDefaultRamBanksRetained(void)
{
    uint8_t bank_mask = 0xFFU; // Retain everything by default

    return bank_mask;
}

void PLATFORM_SetRamBanksRetained(uint8_t bank_mask)
{
}

void RTC_IRQHandler(void)
{
    RTC_ClearStatusFlags(RTC, RTC_GetStatusFlags(RTC));
    POWER_ClearWakeupStatus(RTC_IRQn);
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static void PLATFORM_InitWakeUpSources(void)
{
    /* Enable wake up source from BLE and WIFI controller (IMU interrupt) */
    PM_InitWakeupSource(&bleWakeUpSourceImu, (uint32_t)BLE_MCI_WAKEUP0_IRQn, NULL, true);
    PM_InitWakeupSource(&wlanWakeupSource, (uint32_t)WL_MCI_WAKEUP0_IRQn, NULL, true);
}

static status_t PLATFORM_LowPowerCallback(pm_event_type_t eventType, uint8_t powerState, void *data)
{
    (void)data;

    /* Nothing to do on Sleep state (WFI) but only Deeper low power mode */
    if (powerState < PLATFORM_DEEP_SLEEP_STATE)
    {
        /* Nothing to do when entering WFI or Sleep low power state
            NVIC fully functionnal to trigger upcoming interrupts */
    }
    else
    {
        if (eventType == kPM_EventEnteringSleep)
        {
            /* Platform module can implement platform specific methods to execute
             * when entering and exiting any low power mode.
             * Those methods should implement only mandatory procedures for the
             * platform, compatible with any connectivity protocol */
            PLATFORM_EnterLowPower();

            if (powerState >= PLATFORM_POWER_DOWN_STATE)
            {
                /* Power gated low power modes often require extra specific
                 * entry/exit low power procedures, those should be implemented
                 * in the following PLATFORM API */
                PLATFORM_EnterPowerDown();
            }

            if (powerState == PLATFORM_DEEP_POWER_DOWN_STATE)
            {
                /* Perform specific procedures when entering RAMOFF such as
                 * powering off the radio domain */
                PLATFORM_EnterDeepPowerDown();
            }
        }
        else
        {
            if (powerState >= PLATFORM_POWER_DOWN_STATE)
            {
                /* Power gated low power modes often require specific
                 * entry/exit low power procedures, those should be implemented
                 * in the following PLATFORM API */
                PLATFORM_ExitPowerDown();
            }

            /* Platform specific procedures to execute when exiting low power mode
             * any low power mode */
            PLATFORM_ExitLowPower();
        }
    }

    return kStatus_Success;
}

static void PLATFORM_InitRtc(void)
{
    (void)DisableIRQ(RTC_IRQn); /* MISRA CID 28201062 */
    POWER_ClearWakeupStatus(RTC_IRQn);
    POWER_DisableWakeup(RTC_IRQn);

#if defined(gBoardUseFro32k_d) && (gBoardUseFro32k_d > 0)
    CLOCK_AttachClk(kRC32K_to_CLK32K);
#else
    CLOCK_EnableXtal32K(true);
    CLOCK_AttachClk(kXTAL32K_to_CLK32K);
#endif

    RTC_Init(RTC);
    RTC_Reset(RTC);
    RTC_StartTimer(RTC);
    RTC_EnableWakeUpTimerInterruptFromDPD(RTC, true);
    NVIC_ClearPendingIRQ(RTC_IRQn);

    /* Enable RTC as wake up source */
    PM_InitWakeupSource(&timerWakeupSource, (uint32_t)RTC_IRQn, NULL, true);
}
