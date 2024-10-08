/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2024 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdarg.h>
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#if defined(FPGA_SUPPORT) && (FPGA_SUPPORT == 1)
#include "fwk_platform_fpga.h"
#endif

#include "fsl_os_abstraction.h"
#include "fsl_adapter_rpmsg.h"
#include "fsl_spc.h"

#include "rpmsg_platform.h"

#include "mcmgr_imu_internal.h"

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

/* Raise error with status update , shift previous status by 4 bits and OR with new error code.
 * the returned status will be negative
 * Note: this macros is defined in sss_crypto.h, we need to undef it to make sure we use our implementation */
#undef RAISE_ERROR
#define RAISE_ERROR(__st, __error_code) -(int)((uint32_t)(((uint32_t)(__st) << 4) | (uint32_t)(__error_code)));

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

static int nbu_init = 0;

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
    return nbu_init;
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
    static bool        first_call = true;
    if (first_call)
    {
        /* Write in SMU2 the static shared memory config that we have for NBU to use it */
        platform_set_static_shmem_config();
    }

    first_call = false;

    /* Start CM3 core and Initializes the RPMSG adapter module for dual core communication */
    rpmsg_status = HAL_RpmsgMcmgrInit();
    if (rpmsg_status != kStatus_HAL_RpmsgSuccess)
    {
        status = RAISE_ERROR(rpmsg_status, 1);
        assert(0);
    }

#if defined(FPGA_SUPPORT) && (FPGA_SUPPORT == 1)
    PLATFORM_InitRadio();
#endif

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

        /* CM3 writes to WKUP_TIME register to notify CM33 it's going to low
         * power, this is a software protocol to sync both cores */
        while ((RFMC->RF2P4GHZ_MAN2 & RFMC_RF2P4GHZ_MAN2_WKUP_TIME_MASK) != 0U)
        {
            /* CM3 started low power entry, to workaround HW issues, we need to
             * wait for the radio to fully enter low power before waking it up */
            if ((RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_BLE_STATE_MASK) == RFMC_RF2P4GHZ_STAT_BLE_STATE(0x2U))
            {
                /* Radio is in low power, we can exit the loop and wake it up */
                remote_in_lp = true;
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
