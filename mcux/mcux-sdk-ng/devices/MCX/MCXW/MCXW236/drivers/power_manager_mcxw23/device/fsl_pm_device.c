/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2025 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fsl_pm_device.h"
#include "fsl_pm_core.h"
#include "fsl_pm_board.h"
#include "fsl_power.h"
#include "fsl_component_timer_manager.h"
#ifdef TIMER_PORT_TYPE_CTIMER
#include "fsl_ctimer.h"
#else
#include "fsl_ostimer.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BITMASK_0(x) (1 << (x))
#define BITMASK_1(x) (1 << (x - 32))

/** The time it takes to exit deep sleep. This depends on the used compiler,
 * flavor (release, debug) and the effort spent in application specific
 * callbacks (see PM_RegisterNotify). This value can be profiled and redefined
 * per application */
#ifndef DEEP_SLEEP_EXIT_LATENCY_IN_US
#define DEEP_SLEEP_EXIT_LATENCY_IN_US (749)
#endif /* DEEP_SLEEP_EXIT_LATENCY_IN_US */

/** The time it takes to exit power down. This depends on the used compiler,
 * flavor (release, debug) and the effort spent in application specific
 * callbacks (see PM_RegisterNotify). This value can be profiled and redefined
 * per application */
#ifndef POWER_DOWN_WITH_CPU_RETENTION_EXIT_LATENCY_IN_US
#define POWER_DOWN_WITH_CPU_RETENTION_EXIT_LATENCY_IN_US (918)
#endif /* POWER_DOWN_WITH_CPU_RETENTION_EXIT_LATENCY_IN_US */

/** The resolution of the wakeup timer */
#ifndef WAKEUP_TIMER_RESOLUTION_IN_US
#define WAKEUP_TIMER_RESOLUTION_IN_US (30)
#endif /* WAKEUP_TIMER_RESOLUTION_IN_US */

/** The minimum idle before low power mode is considered */
#ifndef MIN_LOW_POWER_TIME_IN_US
#define MIN_LOW_POWER_TIME_IN_US (500)
#endif /* MIN_LOW_POWER_TIME_IN_US */

/** Time it takes for DCDC to restart after low power mode without DCDC enabled */
#define DCDC_STARTUP_TIME (640)

/* CTIMER is not supported in power down mode */
#ifdef TIMER_PORT_TYPE_CTIMER
#undef DISABLE_POWER_DOWN_CPU
#define DISABLE_POWER_DOWN_CPU
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void EnterSleep(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources);
static void EnterDeepSleep(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources);
#ifndef DISABLE_POWER_DOWN_CPU
static void EnterPowerDownWithCpuRetention(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources);
#endif /* DISABLE_POWER_DOWN_CPU */
static void EnterPowerOff(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources);
static void RequiredResourcesChanged(pm_board_resource_mask_t requiredResources,
                                     pm_board_resource_mask_t changedResources);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/** Holds the resources that are controlled by the PMC and are set as required resource */
static uint32_t s_pmcEnabledResources = 0;
/** Holds the wake up sources that are controlled by the PMC */
static uint64_t s_pmcEnabledWakeupSources = 0;

/** Sleep power state including its properties */
static const pm_state_t s_StateSleep = {
    /* Instant wakeup in sleep mode */
    .minimumResidencyInUs = 0,
    .mode                 = kPM_Mode_Sleep,
    /* In sleep mode, all resources are available */
    .availableResourcesMask = ((pm_board_resource_mask_t){0xffffffff, 0xffffffff}),
    .enterFunc              = EnterSleep};

/** Deep sleep power state including its properties */
static const pm_state_t s_StateDeepSleep = {
    .minimumResidencyInUs   = DEEP_SLEEP_EXIT_LATENCY_IN_US + WAKEUP_TIMER_RESOLUTION_IN_US + MIN_LOW_POWER_TIME_IN_US,
    .mode                   = kPM_Mode_DeepSleep,
    .availableResourcesMask = ((pm_board_resource_mask_t){
        BITMASK_0(kResource_Dcdc) | BITMASK_0(kResource_Bod1) | BITMASK_0(kResource_Bod2) |
            BITMASK_0(kResource_Fro192m) | BITMASK_0(kResource_Fro32k) | BITMASK_0(kResource_Xtal32k) |
            BITMASK_0(kResource_Fro1m) | BITMASK_0(kResource_Trng) | BITMASK_0(kResource_DcdcBypass) |
            BITMASK_0(kResource_BleWup) | BITMASK_0(kResource_Hfdsm) | BITMASK_0(kResource_WakeupSys) |
            BITMASK_0(kResource_WakeupDma0) | BITMASK_0(kResource_WakeupGint0) | BITMASK_0(kResource_WakeupPinInt0) |
            BITMASK_0(kResource_WakeupPinInt1) | BITMASK_0(kResource_WakeupPinInt2) |
            BITMASK_0(kResource_WakeupPinInt3) | BITMASK_0(kResource_WakeupUtick) | BITMASK_0(kResource_WakeupMrt) |
            BITMASK_0(kResource_WakeupCtimer0) | BITMASK_0(kResource_WakeupCtimer1) | BITMASK_0(kResource_WakeupSct) |
            BITMASK_0(kResource_WakeupCtimer3) | BITMASK_0(kResource_WakeupFlexcomm0) |
            BITMASK_0(kResource_WakeupFlexcomm1) | BITMASK_0(kResource_WakeupFlexcomm2) |
            BITMASK_0(kResource_WakeupBleLl) | BITMASK_0(kResource_WakeupBleSlpTmr) | BITMASK_0(kResource_WakeupWdt) |
            BITMASK_0(kResource_WakeupBod1) | BITMASK_0(kResource_WakeupBod2),
        BITMASK_1(kResource_WakeupRtc) | BITMASK_1(kResource_WakeupWakeDslp) | BITMASK_1(kResource_WakeupPinInt4) |
            BITMASK_1(kResource_WakeupPinInt5) | BITMASK_1(kResource_WakeupPinInt6) |
            BITMASK_1(kResource_WakeupPinInt7) | BITMASK_1(kResource_WakeupCtimer2) |
            BITMASK_1(kResource_WakeupCtimer4) | BITMASK_1(kResource_WakeupOsEvent) | BITMASK_1(kResource_WakeupSpifi) |
            BITMASK_1(kResource_WakeupSecGpioInt0Irq0) | BITMASK_1(kResource_WakeupSecGpioInt0Irq1) |
            BITMASK_1(kResource_WakeupPlu) | BITMASK_1(kResource_WakeupSecVio) | BITMASK_1(kResource_WakeupTrng) |
            BITMASK_1(kResource_WakeupDma1) | BITMASK_1(kResource_WakeupWakePad)}),
    .enterFunc              = EnterDeepSleep};

#ifndef DISABLE_POWER_DOWN_CPU
/** Power down with CPU retention power state including its properties */
static const pm_state_t s_StatePowerDownWithCpuRetention = {
    .minimumResidencyInUs =
        POWER_DOWN_WITH_CPU_RETENTION_EXIT_LATENCY_IN_US + WAKEUP_TIMER_RESOLUTION_IN_US + MIN_LOW_POWER_TIME_IN_US,
    .mode                   = kPM_Mode_PowerDownWithCpuRetention,
    .availableResourcesMask = ((pm_board_resource_mask_t){
        BITMASK_0(kResource_Dcdc) | BITMASK_0(kResource_Bod1) | BITMASK_0(kResource_Bod2) |
            BITMASK_0(kResource_Fro32k) | BITMASK_0(kResource_Xtal32k) | BITMASK_0(kResource_Fro1m) |
            BITMASK_0(kResource_Trng) | BITMASK_0(kResource_DcdcBypass) | BITMASK_0(kResource_BleWup) |
            BITMASK_0(kResource_WakeupGint0) | BITMASK_0(kResource_WakeupFlexcomm0) |
            BITMASK_0(kResource_WakeupBleSlpTmr),
        BITMASK_1(kResource_WakeupRtc) | BITMASK_1(kResource_WakeupOsEvent)}),
    .enterFunc              = EnterPowerDownWithCpuRetention};
#endif /* DISABLE_POWER_DOWN_CPU */

/** Power off power state including its properties */
static const pm_state_t s_StatePowerOff = {
    .minimumResidencyInUs = 0,
    .mode                 = kPM_Mode_PowerOff,
    /* The only available resource is the wakeup pad */
    .availableResourcesMask = ((pm_board_resource_mask_t){
            BITMASK_0(kResource_DcdcBypass), BITMASK_1(kResource_WakeupWakePad)}),
    .enterFunc              = EnterPowerOff
};

/** All supported power states */
static const pm_state_t *s_lowPowerStates[] = {&s_StateSleep, &s_StateDeepSleep,
#ifndef DISABLE_POWER_DOWN_CPU
                                               &s_StatePowerDownWithCpuRetention,
#endif /* DISABLE_POWER_DOWN_CPU */
                                               &s_StatePowerOff};

/** Power manager device options */
static const pm_device_option_t s_devicePmOption = {.states                   = s_lowPowerStates,
                                                    .stateCount               = ARRAY_SIZE(s_lowPowerStates),
                                                    .resourcesChangedCallback = RequiredResourcesChanged};

/** Wakeup timer handle */
static TIMER_MANAGER_HANDLE_DEFINE(s_wakeupTimerHandle);

/** Indicates whether internal DCDC is used in selected supply mode */
static bool s_dcdcUsed;

RAMFUNCTION_SECTION_CODE(static void WfiWithFlashDisabled())
{
    SYSCON->AHBCLKCTRLCLR[0] = SYSCON_AHBCLKCTRL0_FLASH_MASK;
    __WFI();
    SYSCON->AHBCLKCTRLSET[0] = SYSCON_AHBCLKCTRL0_FLASH_MASK;
}

/**
 * Starts and configures the wake up timer to wake up the system after @c sleepTimeInUs time
 *
 * @param sleepTimeInUs The time in microseconds before interrupting
 * @return kStatus_Success in case of success. An error code otherwise.
 */
static status_t StartWakeupTimer(uint32_t sleepTimeInUs)
{
    status_t status = TM_Start(s_wakeupTimerHandle, kTimerModeSingleShot | kTimerModeSetMicrosTimer, sleepTimeInUs);
    (void)status;
    assert(status == kStatus_Success);
    return status;
}

/**
 * Stops the wake up timer
 */
static void StopWakeupTimer(void)
{
    /* ostimer must not be stopped as it is also used for fsl_component_timer_manager */
}

/**
 * Puts the system in sleep mode.
 *
 * @param wakeupTime The time at which the system must be fully operational again
 * @param requiredResources The resources that must remain enabled in deep sleep
 */
static void EnterSleep(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources)
{
    /* No wake-up timer needed as the system remains fully operational in sleep mode */
    /* No need to configure the requiredResources as all resources remain active in sleep mode */
    /* An interrupt will force the power lib to exit below function */
    uint32_t primask                = DisableGlobalIRQ();
    clock_attach_id_t previousClock = CLOCK_GetClockAttachId(kFRO12M_to_MAIN_CLK);
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);
    WfiWithFlashDisabled();
    CLOCK_AttachClk(previousClock);
    EnableGlobalIRQ(primask);
}

/**
 * Puts the system in deep sleep mode. Ensures that the required resources are enabled and the
 * wake up timer is programmed to wake up at wakeup time.
 *
 * @param wakeupTime The time at which the system must be fully operational again
 * @param requiredResources The resources that must remain enabled in deep sleep
 */
static void EnterDeepSleep(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources)
{
    uint32_t exitLatencyInUs = DEEP_SLEEP_EXIT_LATENCY_IN_US +
                               (s_pmcEnabledResources & kLOWPOWERCFG_DCDC ? 0 : (s_dcdcUsed ? DCDC_STARTUP_TIME : 0));
    int32_t sleepTimeInUs = (int32_t)((int64_t)wakeupTime - (int64_t)PMDEVICE_GetSleepTimer() - exitLatencyInUs);
    if (sleepTimeInUs > MIN_LOW_POWER_TIME_IN_US)
    {
        /* Start the timer to wake up the system */
        (void)StartWakeupTimer(sleepTimeInUs);

        /* Enter deep sleep mode with OSTIMER wake up source enabled */
        status_t status = POWER_EnterDeepSleep(s_pmcEnabledResources, s_pmcEnabledWakeupSources |
#ifdef TIMER_PORT_TYPE_CTIMER
                                                                          kWAKEUP_CTIMER0
#else
                                                                          kWAKEUP_OS_EVENT
#endif /* TIMER_PORT_TYPE_CTIMER */
        );
        (void)status;
        assert(status == kStatus_Success);

        /* Stop the timer */
        StopWakeupTimer();
    }
}

#ifndef DISABLE_POWER_DOWN_CPU
/**
 * Puts the system in power down with CPU retention. Ensures that the required resources are enabled and the
 * wake up timer is programmed to wake up at wakeup time.
 *
 * @param wakeupTime The time at which the system must be fully operational again
 * @param requiredResources The resources that must remain enabled in power down with CPU retention
 */
static void EnterPowerDownWithCpuRetention(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources)
{
    uint32_t exitLatencyInUs = POWER_DOWN_WITH_CPU_RETENTION_EXIT_LATENCY_IN_US +
                               (s_pmcEnabledResources & kLOWPOWERCFG_DCDC ? 0 : (s_dcdcUsed ? DCDC_STARTUP_TIME : 0));
    int32_t sleepTimeInUs = (int32_t)((int64_t)wakeupTime - (int64_t)PMDEVICE_GetSleepTimer() - exitLatencyInUs);
    if (sleepTimeInUs > MIN_LOW_POWER_TIME_IN_US)
    {
        uint32_t enabledResources;
        /* Start the timer to wake up the system */
        (void)StartWakeupTimer(sleepTimeInUs);

        /* SRAM_X2 is used to store cpu state */
        POWER_EnableSRAM(POWER_GetSRAMConfig() | kSRAM_CTRL_RAMX2);
        enabledResources = s_pmcEnabledResources;
        if (enabledResources & kPOWERCFG_DCDC)
        {
            /* BOD1 is required in power down mode when DCDC is enabled. */
            enabledResources |= kPOWERCFG_BOD1;
        }

        /* Enter deep sleep mode with OSTIMER wake up source enabled */
        status_t status = POWER_EnterPowerDown(enabledResources, s_pmcEnabledWakeupSources | kWAKEUP_OS_EVENT, 1);
        (void)status;
        assert(status == kStatus_Success);

        /* Stop the timer */
        StopWakeupTimer();
    }
}
#endif /* DISABLE_POWER_DOWN_CPU */

/**
 * Puts the system in power off. Ensures that the required resources are enabled
 *
 * @param wakeupTime Not used in this mode
 * @param requiredResources The resources that must remain enabled in power off
 */
static void EnterPowerOff(uint64_t wakeupTime, pm_board_resource_mask_t requiredResources)
{
    status_t status =
        POWER_EnterPowerOff(s_pmcEnabledResources, BITMASK_ISSET(requiredResources, kResource_WakeupWakePad) ?
                                                       kWAKEUP_PIN_ENABLE | kWAKEUP_PIN_PUP_EN | kWAKEUP_PIN_PDN_DIS |
                                                           kWAKEUP_PIN_WAKEUP_LOW_LVL :
                                                       0);

    (void)status;
    /* Below code will never be executed if previous call is successful */
    assert(status == kStatus_Success);
}

/**
 * Function called when the required resources changes. This function will calculate the masks
 * needed for the different powerlib functions.
 *
 * @param requiredResources All required resources
 * @param changedResources The resources that changed compared to last invocation
 */
static void RequiredResourcesChanged(pm_board_resource_mask_t requiredResources,
                                     pm_board_resource_mask_t changedResources)
{
    uint32_t i;
    /* Holds the list of resources controlled by the PMC */
    const uint8_t pmcResources[] = {kResource_Xtal32k, kResource_Fro32k,     kResource_Fro1m, kResource_BleWup,
                                    kResource_Dcdc,    kResource_DcdcBypass, kResource_Hfdsm, kResource_Bod1,
                                    kResource_Bod2,    kResource_Fro192m,    kResource_Trng};
    /* Holds the masks for the pmcResources, this list must match the pmcResources */
    const uint32_t pmcResourceFlags[] = {kLOWPOWERCFG_XTAL32K, kLOWPOWERCFG_FRO32K, kLOWPOWERCFG_FRO1M,
                                         kLOWPOWERCFG_BLE_WUP, kLOWPOWERCFG_DCDC,   kLOWPOWERCFG_DCDC_BYPASS,
                                         kLOWPOWERCFG_HFDSM,   kLOWPOWERCFG_BOD1,   kLOWPOWERCFG_BOD2,
                                         kLOWPOWERCFG_FRO192M, kLOWPOWERCFG_TRNG};
    /* Holds the list of wake up sources controlled by the PMC */
    const uint8_t pmcWakeupSources[] = {kResource_WakeupSys,
                                        kResource_WakeupDma0,
                                        kResource_WakeupGint0,
                                        kResource_WakeupPinInt0,
                                        kResource_WakeupPinInt1,
                                        kResource_WakeupPinInt2,
                                        kResource_WakeupPinInt3,
                                        kResource_WakeupUtick,
                                        kResource_WakeupMrt,
                                        kResource_WakeupCtimer0,
                                        kResource_WakeupCtimer1,
                                        kResource_WakeupSct,
                                        kResource_WakeupCtimer3,
                                        kResource_WakeupFlexcomm0,
                                        kResource_WakeupFlexcomm1,
                                        kResource_WakeupFlexcomm2,
                                        kResource_WakeupBleLl,
                                        kResource_WakeupBleSlpTmr,
                                        kResource_WakeupWdt,
                                        kResource_WakeupBod1,
                                        kResource_WakeupBod2,
                                        kResource_WakeupRtc,
                                        kResource_WakeupWakeDslp,
                                        kResource_WakeupPinInt4,
                                        kResource_WakeupPinInt5,
                                        kResource_WakeupPinInt6,
                                        kResource_WakeupPinInt7,
                                        kResource_WakeupCtimer2,
                                        kResource_WakeupCtimer4,
                                        kResource_WakeupOsEvent,
                                        kResource_WakeupSpifi,
                                        kResource_WakeupSecGpioInt0Irq0,
                                        kResource_WakeupSecGpioInt0Irq1,
                                        kResource_WakeupPlu,
                                        kResource_WakeupSecVio,
                                        kResource_WakeupTrng,
                                        kResource_WakeupDma1,
                                        kResource_WakeupWakePad};
    /* Holds the masks for the pmc wakeup sources, this list must match the pmcWakeupSources */
    const uint64_t pmcWakeupFlags[] = {kWAKEUP_SYS,
                                       kWAKEUP_DMA0,
                                       kWAKEUP_GINT0,
                                       kWAKEUP_PIN_INT0,
                                       kWAKEUP_PIN_INT1,
                                       kWAKEUP_PIN_INT2,
                                       kWAKEUP_PIN_INT3,
                                       kWAKEUP_UTICK,
                                       kWAKEUP_MRT,
                                       kWAKEUP_CTIMER0,
                                       kWAKEUP_CTIMER1,
                                       kWAKEUP_SCT,
                                       kWAKEUP_CTIMER3,
                                       kWAKEUP_FLEXCOMM0,
                                       kWAKEUP_FLEXCOMM1,
                                       kWAKEUP_FLEXCOMM2,
                                       kWAKEUP_BLE_LL,
                                       kWAKEUP_BLE_SLP_TMR,
                                       kWAKEUP_WDT,
                                       kWAKEUP_BOD1,
                                       kWAKEUP_BOD2,
                                       kWAKEUP_RTC,
                                       kWAKEUP_WAKE_DSLP,
                                       kWAKEUP_PIN_INT4,
                                       kWAKEUP_PIN_INT5,
                                       kWAKEUP_PIN_INT6,
                                       kWAKEUP_PIN_INT7,
                                       kWAKEUP_CTIMER2,
                                       kWAKEUP_CTIMER4,
                                       kWAKEUP_OS_EVENT,
                                       kWAKEUP_SPIFI,
                                       kWAKEUP_SEC_GPIO_INT0_IRQ0,
                                       kWAKEUP_SEC_GPIO_INT0_IRQ1,
                                       kWAKEUP_PLU,
                                       kWAKEUP_SEC_VIO,
                                       kWAKEUP_TRNG,
                                       kWAKEUP_DMA1,
                                       kWAKEUP_WAKE_PAD};

    /* Each time the required resources change, the pmc mask is calculated and cached
     * to improve time to low power.
     */
    s_pmcEnabledResources = 0;
    for (i = 0; i < ARRAY_SIZE(pmcResources); i++)
    {
        if (BITMASK_ISSET(requiredResources, pmcResources[i]))
        {
            s_pmcEnabledResources |= pmcResourceFlags[i];
        }
    }

    /* Each time the required resources change, the PMC wake up sources mask is calculated and cached
     * to improve time to low power.
     */
    s_pmcEnabledWakeupSources = 0;
    for (i = 0; i < ARRAY_SIZE(pmcWakeupSources); i++)
    {
        if (BITMASK_ISSET(requiredResources, pmcWakeupSources[i]))
        {
            s_pmcEnabledWakeupSources |= pmcWakeupFlags[i];
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
void PMDEVICE_Init(void)
{
    TM_Open(&s_wakeupTimerHandle);
    dcdc_mode_t mode = POWER_DCDC_GetSupplyMode();
    /* DCDC is not used in XR modes */
    s_dcdcUsed = (mode != kDCDC_MODE_XR_SM_SS) && (mode != kDCDC_MODE_XR_SM_DS);
}

const pm_device_option_t *PMDEVICE_GetDeviceOption(void)
{
    return &s_devicePmOption;
}

void PMDEVICE_StartSleepTimer(void)
{
    /* No need to start ostimer, is already on */
}

void PMDEVICE_StopSleepTimer(void)
{
    /* ostimer must remain on */
}

uint64_t PMDEVICE_GetSleepTimer(void)
{
#ifdef TIMER_PORT_TYPE_CTIMER
    return (uint64_t)(CTIMER_GetTimerCountValue(CTIMER0) * 1e6 / CLOCK_GetCTimerClkFreq(0));
#else
    return (uint64_t)(OSTIMER_GetCurrentTimerValue(OSTIMER) * 1e6 / CLOCK_GetOSTimerClkFreq());
#endif /* TIMER_PORT_TYPE_CTIMER */
}
