/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2024 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fsl_os_abstraction.h"

#include "fwk_platform.h"
#include "fwk_config.h"
#include "fwk_platform_ics.h"
#if defined(FPGA_SUPPORT) && (FPGA_SUPPORT == 1)
#include "fwk_platform_fpga.h"
#endif

#include "FunctionLib.h"
#include "fsl_adapter_rpmsg.h"
#include "fsl_ccm32k.h"
#include "fsl_spc.h"

#include "rpmsg_platform.h"

#if defined(gMWS_Enabled_d) && (gMWS_Enabled_d > 0)
#include "fwk_platform_mws.h"
#endif

#include "mcmgr_imu_internal.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/*! @brief XTAL 32Mhz clock source start up timeout */
#ifndef FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT
#define FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT 1000000
#endif /* FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT */

/*! @brief Default load capacitance config for 32KHz crystal,
      can be overidden from board_platform.h,
      user shall define this flag in board_platform.h file to set an other default value
      Values must be adjust to minimize the jitter on the crystal. This is to avoid
      a shift of 31.25us on the link layer timebase in NBU.
*/
#if !defined(BOARD_32KHZ_XTAL_CLOAD_DEFAULT)
#define BOARD_32KHZ_XTAL_CLOAD_DEFAULT 8U
#endif

/*! @brief Default coarse adjustement config for 32KHz crystal,
      can be overidden from board_platform.h,
      user shall define this flag in board_platform.h file to set an other default value
      Values must be adjusted depending the equivalent series resistance (ESR) of the crystal on the board
*/
#if !defined(BOARD_32KHZ_XTAL_COARSE_ADJ_DEFAULT)
#if defined(FWK_KW47_MCXW72_FAMILIES) && (FWK_KW47_MCXW72_FAMILIES == 1)
#define BOARD_32KHZ_XTAL_COARSE_ADJ_DEFAULT 3U
#else
#define BOARD_32KHZ_XTAL_COARSE_ADJ_DEFAULT 1U
#endif
#endif

#if !defined(BOARD_32KHZ_XTAL_CAPACITANCE_MAX_VALUE)
#define BOARD_32KHZ_XTAL_CAPACITANCE_MAX_VALUE (uint8_t) kCCM32K_OscExtal30pFCap
#endif

/*! @brief Delay from the 32MHz wake up of the LL to wake up the radio domain in number of 30.5us period */
#if !defined(BOARD_RADIO_DOMAIN_WAKE_UP_DELAY)
#define BOARD_RADIO_DOMAIN_WAKE_UP_DELAY 0x10U
#endif

#if !defined(TSTMR_CLOCK_FREQUENCY_MHZ) || (TSTMR_CLOCK_FREQUENCY_MHZ != 1U)
#warning "Warning: TSTMR freq is not 1MHz !"
#endif

/*! @brief XTAL 32Khz clock source start up timeout */
#ifndef FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT
#define FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT 10000000
#endif /* FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT */

/*! @brief Remote active request timeout */
#ifndef FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US
#define FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US 10000U
#endif /* FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US */

/* Raise error with status update , shift previous status by 4 bits and OR with new error code.
 * the returned status will be negative  */
#define RAISE_ERROR(__st, __error_code) -(int)((uint32_t)(((uint32_t)(__st) << 4) | (uint32_t)(__error_code)));

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

static volatile int timer_manager_initialized = 0;

static int nbu_init    = 0;
static int nbu_started = 0;

/****************** LOWPOWER ***********************/
/* Number of request for CM3 to remain active */
static int8_t active_request_nb = 0;

extern PLATFORM_ErrorCallback_t pfPlatformErrorCallback;
PLATFORM_ErrorCallback_t        pfPlatformErrorCallback = (void *)0;

/* -------------------------------------------------------------------------- */
/*                              Private functions                              */
/* -------------------------------------------------------------------------- */

static uint64_t u64ReadTimeStamp(void)
{
    uint32_t reg_l;
    uint32_t reg_h;
    uint32_t regPrimask = DisableGlobalIRQ();
    /* A complete read operation should include both TSTMR LOW and HIGH reads. If a HIGH read does not follow a LOW
     * read, then any other Time Stamp value read will be locked at a fixed value. The TSTMR LOW read should occur
     * first, followed by the TSTMR HIGH read.
     * */
    reg_l = TSTMR0->L;
    __DMB();
    reg_h = TSTMR0->H;

    EnableGlobalIRQ(regPrimask);

    return (uint64_t)reg_l | (((uint64_t)reg_h) << 32U);
}
/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
int PLATFORM_IsNbuStarted(void)
{
    return nbu_started;
}

int PLATFORM_InitNbu(void)
{
    int status = 0;

    if (nbu_init == 0)
    {
        uint32_t rfmc_ctrl;
        int      cnt = 0;

#if defined(gPlatformNbuDebugGpioDAccessEnabled_d) && (gPlatformNbuDebugGpioDAccessEnabled_d == 1)
        /* Init TRDC for NBU - Allow NBU to access GPIOD*/
        trdc_non_processor_domain_assignment_t domainAssignment;
        TRDC_SetDacGlobalValid(TRDC);
        TRDC_GetDefaultNonProcessorDomainAssignment(&domainAssignment);
        domainAssignment.privilegeAttr = (uint8_t)kTRDC_ForcePrivilege;
        TRDC_SetNonProcessorDomainAssignment(TRDC, (uint8_t)kTRDC_MasterRadioNBU, &domainAssignment);
#endif

        rfmc_ctrl = RFMC->RF2P4GHZ_CTRL;

        /* Enables BLE Power Controller on NBU side AND sets LP mode to DeepSleep */
        rfmc_ctrl &= ~(RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_MASK | RFMC_RF2P4GHZ_CTRL_LP_MODE_MASK);
        rfmc_ctrl |=
            (RFMC_RF2P4GHZ_CTRL_LP_MODE(0x3) | RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY(BOARD_RADIO_DOMAIN_WAKE_UP_DELAY) |
             RFMC_RF2P4GHZ_CTRL_BLE_LP_EN(0x1U) | RFMC_RF2P4GHZ_CTRL_SFA_TRIG_EN(0x7U));

        RFMC->RF2P4GHZ_CTRL = rfmc_ctrl;
        RFMC->RF2P4GHZ_TIMER |= RFMC_RF2P4GHZ_TIMER_TIM_EN(0x1U);

#if defined(FWK_KW47_MCXW72_FAMILIES) && (FWK_KW47_MCXW72_FAMILIES == 1)
        /* Allow the debugger to wakeup the target */
        RFMC->RF2P4GHZ_CFG |= RFMC_RF2P4GHZ_CFG_FORCE_DBG_PWRUP_ACK_MASK;
        CMC0->DBGCTL &= ~CMC_DBGCTL_SOD_MASK;
#endif

        /* Enabling BLE Power Controller (BLE_LP_EN) will automatically start the XTAL
         * According to RM, we need to wait for the XTAL to be ready before accessing
         * Radio domain ressources.
         * Here, we make sure the XTAL is ready before releasing the CM3 from reset
         * it will prevent any access issue when the CM3 is starting up.
         * CM3 is released in HAL_RpmsgMcmgrInit */
        while ((cnt++ < FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT) && ((RFMC->XO_STAT & RFMC_XO_STAT_XTAL_RDY_MASK) == 0U))
        {
            __ASM("NOP");
        }

        if (cnt > FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT)
        {
            status = RAISE_ERROR(0, 1);
        }
        else
        {
            /* nbu initialization completed */
            nbu_init = 1;
        }
    }
    else
    {
        /* Initialization already done */
        status = 1;
    }

    return status;
}

int PLATFORM_InitMulticore(void)
{
    int                status = 0;
    hal_rpmsg_status_t rpmsg_status;

    if (nbu_started == 0)
    {
        /* Write in SMU2 the static shared memory config that we have for NBU to use it */
        platform_set_static_shmem_config();
    }

    /* Start NBU core and Initializes the RPMSG adapter module for dual core communication */
    rpmsg_status = HAL_RpmsgMcmgrInit();
    if (rpmsg_status != kStatus_HAL_RpmsgSuccess)
    {
        status = RAISE_ERROR(rpmsg_status, 1);
        assert(0);
    }
    else
    {
        nbu_started = 1;
    }

#if defined(FPGA_SUPPORT) && (FPGA_SUPPORT == 1)
    PLATFORM_InitRadio();
#endif

    return status;
}

void PLATFORM_LoadHwParams(void)
{
}

/* get 4 words of information that uniquely identifies the MCU */
void PLATFORM_GetMCUUid(uint8_t *aOutUid16B, uint8_t *pOutLen)
{
    uint32_t uid[4] = {0};

    /* Get the MCU uid */
    uid[0] = MSCM->UID[0];
    uid[1] = MSCM->UID[1];
    uid[2] = MSCM->UID[2];
    uid[3] = MSCM->UID[3];

    FLib_MemCpy(aOutUid16B, (uint8_t *)uid, sizeof(uid));
    /* Get the uid length */
    *pOutLen = (uint8_t)sizeof(uid);

    return;
}

int PLATFORM_InitFro32K(void)
{
    /* Enable the fro32k and select it as 32k clock source and disable osc32k
     * The NBU firmware embeds a module capable of trimming the fro32k to get it as close as possible from 32768Hz
     * */
    CCM32K_Enable32kFro(CCM32K, true);
    CCM32K_SelectClockSource(CCM32K, kCCM32K_ClockSourceSelectFro32k);
    while ((CCM32K_GetStatusFlag(CCM32K) & (uint32_t)kCCM32K_32kFroActiveStatusFlag) == 0U)
    {
        /* wait for the switch to fro32k to be effective before disabling osc32k */
    }

    /* Turning off the XTAL32K will indicate to the NBU that the 32K source is from FRO32K */
    CCM32K_Set32kOscConfig(CCM32K, kCCM32K_Disable32kHzCrystalOsc, NULL);

    return 0;
}

int PLATFORM_InitOsc32K(void)
{
    int      status;
    uint32_t osc32k_ctrl;
    uint8_t  xtalCap32K = BOARD_32KHZ_XTAL_CLOAD_DEFAULT;

    status = PLATFORM_GetOscCap32KValue(&xtalCap32K);

    osc32k_ctrl = CCM32K->OSC32K_CTRL;

    /* Clear OSC32K configuration */
    osc32k_ctrl &= ~(CCM32K_OSC32K_CTRL_OSC_EN_MASK | CCM32K_OSC32K_CTRL_SOX_EN_MASK |
                     CCM32K_OSC32K_CTRL_CAP_SEL_EN_MASK | CCM32K_OSC32K_CTRL_XTAL_CAP_SEL_MASK |
                     CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL_MASK | CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN_MASK);

    /* Set Cload and trimming config to achieve 32768 Hz
     * Tests showed about 20 - 70 ppm with this config on EVK boards */
    osc32k_ctrl |= (CCM32K_OSC32K_CTRL_XTAL_CAP_SEL(xtalCap32K) | CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL(xtalCap32K));

    /* Set amplifier gain adjustement to select external crystal ESR range */
    osc32k_ctrl &= ~(CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN_MASK);
    osc32k_ctrl |= CCM32K_OSC32K_CTRL_COARSE_AMP_GAIN(BOARD_32KHZ_XTAL_COARSE_ADJ_DEFAULT);

    /* Enable crystal load capacitance and SOX mode */
    osc32k_ctrl |= CCM32K_OSC32K_CTRL_CAP_SEL_EN(0x1U) | CCM32K_OSC32K_CTRL_SOX_EN(0x1U);

    CCM32K->OSC32K_CTRL = osc32k_ctrl;

    /* Enable OSC32K */
    osc32k_ctrl |= CCM32K_OSC32K_CTRL_OSC_EN(0x1U);
    CCM32K->OSC32K_CTRL = osc32k_ctrl;

    return status;
}

int PLATFORM_GetOscCap32KValue(uint8_t *xtalCap32K)
{
    return -1;
}

int PLATFORM_SetOscCap32KValue(uint8_t xtalCap32K)
{
    return -1;
}

int PLATFORM_SwitchToOsc32k(void)
{
    int status = 0;
    int cnt    = 0;

    assert((CCM32K->OSC32K_CTRL & CCM32K_OSC32K_CTRL_OSC_EN_MASK) != 0);

    do
    {
        /* wait for the 32k OSC to be ready */
        while ((cnt++ < FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT) &&
               ((CCM32K->STATUS & CCM32K_STATUS_OSC32K_RDY_MASK) == 0U))
        {
        }
        if (cnt > FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT)
        {
            status = RAISE_ERROR(status, 1);
            break;
        }

        CCM32K_SelectClockSource(CCM32K, kCCM32K_ClockSourceSelectOsc32k);

        /* Disable FRO32K (to save some power) */
        CCM32K->FRO32K_CTRL &= ~(CCM32K_FRO32K_CTRL_FRO_EN_MASK);

#if 0
        /* Debug only : output 32k clock on ptc7 for frequency measurement
         * (need to include fsl_port.h) */
        CLOCK_EnableClock(kCLOCK_PortC);
        PORT_SetPinMux(PORTC, 7u, kPORT_MuxAlt7);
        SCG0->CLKOUTCNFG = SCG_CLKOUTCNFG_CLKOUTSEL(0x4);
#endif
    } while (false);

    return status;
}

void PLATFORM_UninitOsc32K(void)
{
    ccm32k_state_t osc32k_state = CCM32K_GetCurrentState(CCM32K);

    if ((osc32k_state == kCCM32K_Only32kOscEnabled) || (osc32k_state == kCCM32K_Both32kFro32kOscEnabled))
    {
        /* Disable 32k OSC */
        CCM32K->OSC32K_CTRL &= ~(CCM32K_OSC32K_CTRL_OSC_EN_MASK);
    }
}

uint8_t PLATFORM_GetXtal32MhzTrim(bool_t regRead)
{
    uint8_t xtal32MhzTrim;
    xtal32MhzTrim = (uint8_t)((RFMC->XO_TEST & RFMC_XO_TEST_CDAC_MASK) >> RFMC_XO_TEST_CDAC_SHIFT);
    return xtal32MhzTrim;
}

/* Calling this function assumes HWParameters in flash have been read */
void PLATFORM_SetXtal32MhzTrim(uint8_t trimValue, bool_t saveToHwParams)
{
}

int PLATFORM_InitTimerManager(void)
{
    return -1;
}

void PLATFORM_DeinitTimerManager(void)
{
}

uint64_t PLATFORM_GetTimeStamp(void)
{
    /* u64ReadTimeStamp mimics TSTMR_ReadTimeStamp(TSTMR0) but copied to avoid dependency
     * with fsl_tstmr.h not present in include path
     */
    return u64ReadTimeStamp();
}

uint64_t PLATFORM_GetMaxTimeStamp(void)
{
    /* Max timestamp counter value (56 bits)
     * No conversion to us is needed since the timestamp timer runs off the 1 MHz clock*/
    return ((uint64_t)0xFFFFFFFFFFFFFFU);
}

bool PLATFORM_IsTimeoutExpired(uint64_t timestamp, uint64_t delayUs)
{
    uint64_t now, duration;

    now = PLATFORM_GetTimeStamp();

    if (now < timestamp)
    {
        /* Handle counter wrapping */
        duration = PLATFORM_GetMaxTimeStamp() - timestamp + now;
    }
    else
    {
        duration = now - timestamp;
    }
    return (duration >= delayUs);
}

void PLATFORM_WaitTimeout(uint64_t timestamp, uint64_t delayUs)
{
    while (!(PLATFORM_IsTimeoutExpired(timestamp, delayUs)))
    {
    }
}

void PLATFORM_Delay(uint64_t delayUs)
{
    /* PLATFORM_Delay() is similar to PLATFORM_WaitTimeout() but timestamp is taken right now */
    PLATFORM_WaitTimeout(PLATFORM_GetTimeStamp(), delayUs);
}

void PLATFORM_DisableControllerLowPower(void)
{
    /* Increase active request number so it is always asserted while Controller
     * is not allowed to go to low power
     * This will avoid going through the wake up procedure each time
     * PLATFORM_RemoteActiveReq is called
     * Note: this must be called before accessing RF_CMC, as it is in NBU domain
     */
    PLATFORM_RemoteActiveReq();

    /* Disallow NBU to go to low power
     * NBU FW will check this bit before going to low power
     * if it is set, NBU will go to WFI only
     * Note: If NBU is already in low power, this will apply to next Idle period
     */
    RF_CMC1->RADIO_LP |= RF_CMC1_RADIO_LP_BLE_WKUP_MASK;
}

void PLATFORM_RemoteActiveReq(void)
{
    OSA_InterruptDisable();

    if (active_request_nb == 0)
    {
        uint32_t rfmc_ctrl    = RFMC->RF2P4GHZ_CTRL;
        bool     remote_in_lp = false;
        uint64_t timestamp    = PLATFORM_GetTimeStamp();

        /* Set lp wakeup delay to 0 to reduce time of execution on host side, NBU will wait XTAL to be ready before
         * starting execution */
        uint32_t lp_wakeup_delay;
        lp_wakeup_delay = (rfmc_ctrl & RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_MASK) >> RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_SHIFT;
        rfmc_ctrl &= ~(RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY_MASK);
        rfmc_ctrl |= RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY(0U);
        RFMC->RF2P4GHZ_CTRL = rfmc_ctrl;

        /* NBU writes to WKUP_TIME register to notify application core it's going to low
         * power, this is a software protocol to sync both cores */
        while ((RFMC->RF2P4GHZ_MAN2 & RFMC_RF2P4GHZ_MAN2_WKUP_TIME_MASK) != 0U)
        {
            /* NBU started low power entry, to workaround HW issues, we need to
             * wait for the radio to fully enter low power before waking it up */
            if ((RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_BLE_STATE_MASK) == RFMC_RF2P4GHZ_STAT_BLE_STATE(0x2U))
            {
                /* Radio is in low power, we can exit the loop and wake it up */
                remote_in_lp = true;
                break;
            }
            if (((RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_BLE_STATE_MASK) == RFMC_RF2P4GHZ_STAT_BLE_STATE(0x3U)) ||
                /* Radio is currently waking up*/
                ((RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_BLE_WKUP_STAT_MASK) != 0U))
            /* Radio will exit lowpower or will not be able to enter lowpower because a BLE event will soon expire */
            {
                /* We can exit the loop without waiting for the NBU to re-write WKUP_TIME register, as the radio will
                 * not enter lowpower or is already in the wakeup procedure */
                break;
            }
            /* Error callback set by PLATFORM_RegisterBleErrorCallback() */
            if (PLATFORM_IsTimeoutExpired(timestamp, FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US) &&
                (pfPlatformErrorCallback != NULL))
            {
                pfPlatformErrorCallback(PLATFORM_REMOTE_ACTIVE_REQ_ID, -1);
                break;
            }
        }

        rfmc_ctrl |= RFMC_RF2P4GHZ_CTRL_BLE_WKUP(0x1U);
        RFMC->RF2P4GHZ_CTRL = rfmc_ctrl;

        __DSB();

        if (remote_in_lp == true)
        {
            /* Wake up time is around 5 periods of 32khz clock (160us)
             * Adding a delay of 120us shouldn't impact waiting time, and will
             * make sure the BLE_STATE is reliable */
            PLATFORM_Delay(120U);
        }

        timestamp = PLATFORM_GetTimeStamp();
        /* Wait for the NBU to become active */
        while ((RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_BLE_STATE_MASK) != RFMC_RF2P4GHZ_STAT_BLE_STATE(0x1U))
        {
            __ASM("NOP");
            /* Error callback set by PLATFORM_RegisterBleErrorCallback() */
            if (PLATFORM_IsTimeoutExpired(timestamp, FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US) &&
                (pfPlatformErrorCallback != NULL))
            {
                pfPlatformErrorCallback(PLATFORM_REMOTE_ACTIVE_REQ_ID, -2);
                break;
            }
        }
        rfmc_ctrl |= RFMC_RF2P4GHZ_CTRL_LP_WKUP_DLY(lp_wakeup_delay);
        RFMC->RF2P4GHZ_CTRL = rfmc_ctrl;
    }
    else
    {
        ;
    }

    active_request_nb++;

    OSA_InterruptEnable();
}

void PLATFORM_RemoteActiveRel(void)
{
    OSA_InterruptDisable();

    assert(active_request_nb > 0);
    active_request_nb--;

    if (active_request_nb == 0)
    {
        uint32_t rfmc_ctrl;
        rfmc_ctrl = RFMC->RF2P4GHZ_CTRL;
        rfmc_ctrl &= ~RFMC_RF2P4GHZ_CTRL_BLE_WKUP_MASK;
        RFMC->RF2P4GHZ_CTRL = rfmc_ctrl;
    }

    OSA_InterruptEnable();
}

void PLATFORM_GetResetCause(PLATFORM_ResetStatus_t *reset_status)
{
    uint32_t SSRS_value;
    SSRS_value = CMC0->SSRS;

    if (((SSRS_value & CMC_SSRS_WAKEUP_MASK) == CMC_SSRS_WAKEUP_MASK) &&
        !((SSRS_value & CMC_SSRS_PIN_MASK) == CMC_SSRS_PIN_MASK) &&
        !((SSRS_value & CMC_SSRS_DAP_MASK) == CMC_SSRS_DAP_MASK))
    {
        *reset_status = PLATFORM_LowPowerWakeup;
    }
    else
    {
        *reset_status = PLATFORM_DeviceReset;
    }

    CMC0->SSRS = 0xFFFFFFFFu; /* clear SSRS register */
}

void mcmgr_imu_remote_active_rel(void)
{
    PLATFORM_RemoteActiveRel();
}

void mcmgr_imu_remote_active_req(void)
{
    PLATFORM_RemoteActiveReq();
}

void PLATFORM_SetNbuConstraintFrequency(PLATFORM_NbuConstraintFrequency_t freq_constraint)
{
    (void)PLATFORM_FwkSrvSendPacket(gFwkSrvNbuUpdateFrequencyConstraintFromHost, &freq_constraint,
                                    (uint16_t)sizeof(freq_constraint));
}

void PLATFORM_RegisterErrorCallback(PLATFORM_ErrorCallback_t cb)
{
    pfPlatformErrorCallback = cb;
}

int PLATFORM_ClearIoIsolationFromLowPower(void)
{
    int ret = 0;
    if ((SPC_CheckPowerDomainLowPowerRequest(SPC0, kSPC_PowerDomain0) == true) &&
        (SPC_GetPowerDomainLowPowerMode(SPC0, kSPC_PowerDomain0) >= kSPC_PowerDownWithSysClockOff))
    {
        /* We need to release IO isolation when exiting from Power Down mode
         * This is done here after all peripherals have been reinitialized, to
         * avoid any glitch on IOs */
        SPC_ClearPeriphIOIsolationFlag(SPC0);

        ret = 1;
    }
    return ret;
}
