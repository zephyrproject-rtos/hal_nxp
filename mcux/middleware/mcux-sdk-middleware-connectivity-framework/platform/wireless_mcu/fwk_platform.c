/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2025 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform.h"
#include "fwk_config.h"
#include "fwk_platform_ics.h"
#if defined(FPGA_TARGET) && (FPGA_TARGET == 1)
#include "fwk_platform_fpga.h"
#endif

#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
#include "fsl_spc.h"
#endif

#include "fsl_os_abstraction.h"
#include "fsl_adapter_rpmsg.h"

#include "rpmsg_platform.h"

#include "mcmgr_imu_internal.h"

#include "fwk_platform_definitions.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/*! @brief XTAL 32Mhz clock source start up timeout */
#ifndef FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT
#define FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT 1000000
#endif /* FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT */

/*! @brief Delay from the 32MHz wake up of the LL to wake up the radio domain in number of 30.5us period */
#if !defined(BOARD_RADIO_DOMAIN_WAKE_UP_DELAY)
#define BOARD_RADIO_DOMAIN_WAKE_UP_DELAY 0x10U
#endif

/*! @brief Remote active request timeout */
#ifndef FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US
#define FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US 10000U
#endif /* FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US */

#define FWK_PLATFORM_NBU_WAKE_UP_INTERRUPT_MASK 0x8UL

/* Raise error with status update , shift previous status by 4 bits and OR with new error code.
 * the returned status will be negative  */
#define RAISE_ERROR(__st, __error_code) -(int)((uint32_t)(((uint32_t)(__st) << 4) | (uint32_t)(__error_code)));

#define TSTMR_MAX_VAL ((uint64_t)0x00FFFFFFFFFFFFFFULL)

/* -------------------------------------------------------------------------- */
/*                         Private type definitions                           */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
static int nbu_init    = 0;
static int nbu_started = 0;

/**
 * @brief provide FRO6Mhz ratio compared to required 6MHz frequency
 *
 */
static uint8_t fwk_platform_FRO6MHz_ratio = 1u;

/****************** LOWPOWER ***********************/
/* Number of request for CM3 to remain active */
static int8_t active_request_nb = 0;

extern PLATFORM_ErrorCallback_t pfPlatformErrorCallback;
PLATFORM_ErrorCallback_t        pfPlatformErrorCallback = (void *)0;

/* -------------------------------------------------------------------------- */
/*                              Private functions                              */
/* -------------------------------------------------------------------------- */

static uint64_t u64ReadTimeStamp(TSTMR_Type *base)
{
    uint32_t reg_l;
    uint32_t reg_h;
    uint32_t regPrimask;

    regPrimask = DisableGlobalIRQ();

    /* A complete read operation should include both TSTMR LOW and HIGH reads. If a HIGH read does not follow a LOW
     * read, then any other Time Stamp value read will be locked at a fixed value. The TSTMR LOW read should occur
     * first, followed by the TSTMR HIGH read.
     * */
    reg_l = base->L;
    __DMB();
    reg_h = base->H;

    EnableGlobalIRQ(regPrimask);

    return (uint64_t)reg_l | (((uint64_t)reg_h) << 32U);
}

/*!
 * \brief Compute number of ticks between 2 timestamps expressed in number of TSTMR ticks
 *
 * \param [in] timestamp0 start timestamp.
 * \param [in] timestamp1 end timestamp.
 *
 * \return uint64_t number of TSTMR ticks
 *
 */
static uint64_t GetTimeStampDeltaTicks(uint64_t timestamp0, uint64_t timestamp1)
{
    uint64_t delta_ticks;

    timestamp0 &= TSTMR_MAX_VAL; /* sanitize arguments */
    timestamp1 &= TSTMR_MAX_VAL;

    if (timestamp1 >= timestamp0)
    {
        delta_ticks = timestamp1 - timestamp0;
    }
    else
    {
        /* In case the 56-bit counter has wrapped */
        delta_ticks = TSTMR_MAX_VAL - timestamp0 + timestamp1 + 1ULL;
    }
    return delta_ticks;
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

    return status;
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

    memcpy(aOutUid16B, (uint8_t *)uid, sizeof(uid));
    /* Get the uid length */
    *pOutLen = (uint8_t)sizeof(uid);

    return;
}

uint64_t PLATFORM_GetTimeStamp(void)
{
    /* u64ReadTimeStamp mimics TSTMR_ReadTimeStamp(TSTMR0) but copied to avoid dependency
     * with fsl_tstmr.h not present in include path
     */
    return u64ReadTimeStamp(TSTMR0);
}

uint64_t PLATFORM_GetMaxTimeStamp(void)
{
    /* Max timestamp counter value (56 bits) */
    return TSTMR_MAX_VAL;
}

/*!
 * \brief Compute number of microseconds between 2 timestamps expressed in number of TSTM ticks
 *
 * \param [in] timestamp0 start timestamp from which duration is assessed.
 * \param [in] timestamp1 end timestamp till which duration is assessed.
 *
 * \return uint64_t number of microseconds
 *
 */
uint64_t PLATFORM_GetTimeStampDeltaUs(uint64_t timestamp0, uint64_t timestamp1)
{
    uint64_t duration_us;

    duration_us = GetTimeStampDeltaTicks(timestamp0, timestamp1);

    if (fwk_platform_FRO6MHz_ratio > 1U)
    {
        uint64_t val;
        /* In a normal situation, the ratio is equal to 1. However in extremely rare cases FRO-6MHz oscillates at
         *  2MHz instead of 6MHz. A post wakeup calibration is executed to monitor such situation.
         */
        assert(fwk_platform_FRO6MHz_ratio == 3U);
        val = (duration_us & TSTMR_MAX_VAL); /* cannot exceed 2^56 so guaranteed to be smaller than 2^64*/
        val *= 3U;                           /* Guaranteed to be smaller than 2^58 */
        duration_us = val;
    }
    return duration_us;
}

/*!
 * \brief Check if a number of microseconds have elapsed since initial times stamp
 *
 * \param [in] initial_timestamp start time stamp from which duration is assessed.
 * \param [in] delayUs number of microseconds to expire.
 *
 */
bool PLATFORM_IsTimeoutExpired(uint64_t initial_timestamp, uint64_t delayUs)
{
    uint64_t duration;
    uint64_t now = PLATFORM_GetTimeStamp();
    /* Compute number of microseconds since timestamp till now */
    duration = PLATFORM_GetTimeStampDeltaUs(initial_timestamp, now);

    return (duration >= delayUs);
}

/*!
 * \brief Actively wait a number of microseconds to have elapsed since initial times stamp
 *
 * \param [in] timestamp start time stamp from which duration is assessed.
 * \param [in] delayUs number of microseconds to wait
 *
 * see PLATFORM_IsTimeoutExpired
 */
void PLATFORM_WaitTimeout(uint64_t timestamp, uint64_t delayUs)
{
    /* Wait until the number of microseconds elapsed since timestamp */
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
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
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
#endif
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
#if defined(gPlatformNbuWakeUpInterruptAddr)
        /* Enable an interrupt on NBU, ensure we execute code on NBU each time we access to its power domain. To do so a
         * dummy interrupt is used */
        *(uint32_t *)gPlatformNbuWakeUpInterruptAddr |= FWK_PLATFORM_NBU_WAKE_UP_INTERRUPT_MASK;
#endif
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

    CMC0->SSRS = 0xFFFFFFFFU; /* clear SSRS register */
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
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    if ((SPC_CheckPowerDomainLowPowerRequest(SPC0, kSPC_PowerDomain0) == true) &&
        (SPC_GetPowerDomainLowPowerMode(SPC0, kSPC_PowerDomain0) >= kSPC_PowerDownWithSysClockOff))
    {
        /* We need to release IO isolation when exiting from Power Down mode
         * This is done here after all peripherals have been reinitialized, to
         * avoid any glitch on IOs */
        SPC_ClearPeriphIOIsolationFlag(SPC0);

        ret = 1;
    }
#endif
    return ret;
}
