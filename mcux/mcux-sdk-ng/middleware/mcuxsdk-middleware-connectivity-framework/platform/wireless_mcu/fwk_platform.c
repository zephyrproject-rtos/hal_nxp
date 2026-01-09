/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2025 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

/* Get some BOARD_***_DEFAULT macro values if defined in board.h for 32kHz settings */
#include "board_platform.h"
#include "fwk_platform_definitions.h"
#include "fwk_platform.h"
#include "fwk_config.h"
#include "fwk_platform_ics.h"
#if defined(FPGA_TARGET) && (FPGA_TARGET == 1)
#include "fwk_platform_fpga.h"
#endif

#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
#include "fsl_ccm32k.h"
#include "fsl_spc.h"
#include "fsl_trdc.h"
#endif

#include "FunctionLib.h"
#include "fsl_component_timer_manager.h"
#include "fsl_os_abstraction.h"
#include "fsl_adapter_rpmsg.h"

#include "rpmsg_platform.h"

#if defined(gPlatformUseHwParameter_d) && (gPlatformUseHwParameter_d > 0)
#include "HWParameter.h"
#endif

#if defined(gMWS_Enabled_d) && (gMWS_Enabled_d > 0)
#include "fwk_platform_mws.h"
#endif

#include "fwk_debug.h"
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

/*! @brief Default coarse adjustment config for 32KHz crystal,
      can be overridden from board_platform.h,
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
/* This value is incompatible with delayLpoCycle set to 2. Refer to BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT to check if the
 * value has been overridden */
#define BOARD_RADIO_DOMAIN_WAKE_UP_DELAY 0x10U
#endif

/*! @brief XTAL 32Khz clock source start up timeout */
#ifndef FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT
#define FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT 10000000
#endif /* FWK_PLATFORM_XTAL32K_STARTUP_TIMEOUT */

/*! @brief Remote active request timeout */
#ifndef FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US
#define FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US 10000U
#endif /* FWK_PLATFORM_ACTIVE_REQ_TIMEOUT_US */

#define FWK_PLATFORM_NBU_WAKE_UP_INTERRUPT_MASK 0x8UL

/* Raise error with status update , shift previous status by 4 bits and OR with new error code.
 * the returned status will be negative  */
#define RAISE_ERROR(__st, __error_code) -(int)((uint32_t)(((uint32_t)(__st) << 4) | (uint32_t)(__error_code)));

#define TSTMR_MAX_VAL ((uint64_t)0x00FFFFFFFFFFFFFFULL)

#define MRCC_TSTMR_CLK_DIS                   0x00u
#define MRCC_TSTMR_CLK_EN_NO_LP_STALL        0x01u
#define MRCC_TSTMR_CLK_EN_LP_STALL_IDLE      0x02u
#define MRCC_TSTMR_CLK_EN_LP_STALL_DEEPSLEEP 0x03u

#if (defined FSL_FEATURE_SOC_TSTMR_COUNT && (FSL_FEATURE_SOC_TSTMR_COUNT > 1))
#define gPlatformHasTstmr32K_d 1
#endif

/* -------------------------------------------------------------------------- */
/*                         Private type definitions                           */
/* -------------------------------------------------------------------------- */

/**
 * @brief FRO6M calibration context
 *
 */
typedef struct
{
    uint64_t initial_ts;      /*< Timestamp Read from TSTMR L and H */
    uint32_t core_cycles_1us; /*< Number of cycles per microsecond */
    uint8_t  ratio;           /*< result of calibration : normally 1 may be 3 if FRO is beating at 2MHz */
    bool     started;         /*< true if calibration initiated */
    bool     trcena_state;    /*< tells whether trace was enabled or not */
    bool     dwt_state;       /*< true whether DWT was enabled already or not */
} Platform_Fro6MCalCtx_t;

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

static volatile int timer_manager_initialized = 0;

static int nbu_init    = 0;
static int nbu_started = 0;

/**
 * @brief provide FRO6Mhz ratio compared to required 6MHz frequency
 *
 */
static uint8_t fwk_platform_FRO6MHz_ratio = 1u;

static const xtal_temp_comp_lut_t *pXtal32MTempCompLut = NULL;

/****************** LOWPOWER ***********************/
/* Number of request for CM3 to remain active */
static int8_t active_request_nb = 0;

extern PLATFORM_ErrorCallback_t pfPlatformErrorCallback;
PLATFORM_ErrorCallback_t        pfPlatformErrorCallback = (void *)0;

/* Used and instantiated only if FRO6M calibration is linked */
static Platform_Fro6MCalCtx_t fro6M_calibration_ctx = {
    .ratio = 1U, .started = false, .dwt_state = false, .trcena_state = false};

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

static int PLATFORM_SetXtalTempComp(const xtal_temp_comp_lut_t *lut, int16_t temperature)
{
    int     ret = 0;
    uint8_t cdac_trim_val;

    do
    {
        if (lut == NULL)
        {
            ret = -1;
            break;
        }

        /* if input temperature is below min_temp in the LUT, use a default trim below min temp */
        if (temperature < lut->min_temp_degc)
        {
            cdac_trim_val = lut->trim_below_min_temp;
        }
        else
        {
            /* if input temperature is above max_temp in the LUT, use a default trim above max temp */
            if (temperature > lut->max_temp_degc)
            {
                cdac_trim_val = lut->trim_above_max_temp;
            }
            else
            {
                /* calculate index in the LUT to use based in the min_temp and temp_step */
                int index = ((int)temperature - (int)lut->min_temp_degc) / (int)lut->temp_step_degc;
                if ((index < PLATFORM_XTAL_TEMP_COMP_LUT_SIZE) && (index >= 0))
                {
                    cdac_trim_val = lut->xtal_trim_lut[index];
                }
                else
                {
                    ret = -1;
                    break;
                }
            }
        }

        /* Send the new trimming value to the NBU
         * The NBU will perform the update at the most optimal time, if possible.
         * Depending on the radio activity, this update can happen late or never.
         * This is a suggestion to the NBU to replace the trimming value, not a guarantee. */
        ret = PLATFORM_SendNBUXtal32MTrim(cdac_trim_val);
    } while (false);

    return ret;
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
int PLATFORM_IsNbuStarted(void)
{
    return nbu_started;
}

void PLATFORM_SetLowPowerFlag(bool PwrDownOngoing)
{
    uint32_t           val = 0UL;
    extern uint32_t    m_lowpower_flag_start[]; /* defined by linker */
    volatile uint32_t *p_lp_flag = (volatile uint32_t *)(uint32_t)m_lowpower_flag_start;

    /* if called with */
    if (PwrDownOngoing)
    {
        val = PLATFORM_HOST_USE_POWER_DOWN;
    }
    *p_lp_flag = val;
}

int PLATFORM_InitNbu(void)
{
    int status = 0;

    if (nbu_init == 0)
    {
        uint32_t rfmc_ctrl;
        int      cnt = 0;

#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
#if defined(gPlatformNbuDebugGpioDAccessEnabled_d) && (gPlatformNbuDebugGpioDAccessEnabled_d == 1)
        /* Init TRDC for NBU - Allow NBU to access GPIOD*/
        trdc_non_processor_domain_assignment_t domainAssignment;
        TRDC_SetDacGlobalValid(TRDC);
        TRDC_GetDefaultNonProcessorDomainAssignment(&domainAssignment);
        domainAssignment.privilegeAttr = (uint8_t)kTRDC_ForcePrivilege;
        TRDC_SetNonProcessorDomainAssignment(TRDC, (uint8_t)kTRDC_MasterRadioNBU, &domainAssignment);
#endif

        /* Initialize a memory zone of the shared memory that will be used to transmit a message later */
        PLATFORM_SetLowPowerFlag(false);
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
        BOARD_DBGLPIOSET(2, 1);
        while ((cnt++ < FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT) && ((RFMC->XO_STAT & RFMC_XO_STAT_XTAL_RDY_MASK) == 0U))
        {
            BOARD_DBGLPIOSET(2, 0);
            __ASM("NOP");
            BOARD_DBGLPIOSET(2, 1);
        }
        BOARD_DBGLPIOSET(2, 0);

        if (cnt > FWK_PLATFORM_XTAL32M_STARTUP_TIMEOUT)
        {
            status = RAISE_ERROR(0, 1);
        }
        else
        {
            DBG_NBU_GPIOD_ACCESS();

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

void PLATFORM_LoadHwParams(void)
{
#if defined(gPlatformUseHwParameter_d) && (gPlatformUseHwParameter_d > 0)
    uint8_t               xtal_32m_trim;
    hardwareParameters_t *pHWParams = NULL;
    uint32_t              status;

    /* Load the HW parameters from Flash to RAM */
    status = NV_ReadHWParameters(&pHWParams);
    if ((status == 0U) && (pHWParams->xtalTrim != 0xFFU))
    {
        /* There is an existing trim value */
        xtal_32m_trim = pHWParams->xtalTrim;
        /* Set value to RFMC */
        PLATFORM_SetXtal32MhzTrim(xtal_32m_trim, FALSE);
    }
#endif
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

#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
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
    hardwareParameters_t *pHWParams = NULL;
    int                   status;

    status = (int)NV_ReadHWParameters(&pHWParams);

    if ((status == 0) && (pHWParams->xtalCap32K != 0xFFU))
    {
        uint32_t regPrimask;
        regPrimask  = DisableGlobalIRQ();
        *xtalCap32K = pHWParams->xtalCap32K;
        EnableGlobalIRQ(regPrimask);
    }
    else
    {
        *xtalCap32K = BOARD_32KHZ_XTAL_CLOAD_DEFAULT;
    }
    /* If the HWParameter are not set it will keep the value chosen by default so do nothing here */
    return status;
}

int PLATFORM_SetOscCap32KValue(uint8_t xtalCap32K)
{
    hardwareParameters_t *pHWParams = NULL;
    int                   status;
    ccm32k_osc_config_t   osc32k_config;

    do
    {
        uint32_t regPrimask;
        if (xtalCap32K > BOARD_32KHZ_XTAL_CAPACITANCE_MAX_VALUE)
        {
            status = -1;
            break;
        }

        status = (int)NV_ReadHWParameters(&pHWParams);
        if (status != 0)
        {
            break;
        }

        regPrimask            = DisableGlobalIRQ();
        pHWParams->xtalCap32K = xtalCap32K;
        (void)NV_WriteHWParameters();
        EnableGlobalIRQ(regPrimask);

        osc32k_config.enableInternalCapBank = true;
        osc32k_config.coarseAdjustment      = (ccm32k_osc_coarse_adjustment_value_t)BOARD_32KHZ_XTAL_COARSE_ADJ_DEFAULT;

        osc32k_config.extalCap = (ccm32k_osc_extal_cap_t)xtalCap32K;
        osc32k_config.xtalCap  = (ccm32k_osc_xtal_cap_t)xtalCap32K;

        CCM32K_Set32kOscConfig(CCM32K, kCCM32K_Enable32kHzCrystalOsc, &osc32k_config);

    } while (false);

    return status;
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
    uint32_t              status;
    uint32_t              rfmc_xo;
    hardwareParameters_t *pHWParams = NULL;
    status                          = NV_ReadHWParameters(&pHWParams);
    if ((TRUE == saveToHwParams) && (status == 0U))
    {
        /* update value only if it changed */
        pHWParams->xtalTrim = trimValue;
        (void)NV_WriteHWParameters();
    }

    /* Apply a trim value to the crystal oscillator */
    rfmc_xo = RFMC->XO_TEST;

    rfmc_xo &= ~(RFMC_XO_TEST_CDAC_MASK);
    rfmc_xo |= RFMC_XO_TEST_CDAC(trimValue);

    RFMC->XO_TEST = rfmc_xo;
}
#endif

int PLATFORM_InitTimerManager(void)
{
    int status = 0;

    if (timer_manager_initialized == 0)
    {
        timer_status_t tm_st;
        timer_config_t timerConfig;

        timerConfig.instance       = PLATFORM_TM_INSTANCE;
        timerConfig.srcClock_Hz    = PLATFORM_TM_CLK_FREQ;
        timerConfig.clockSrcSelect = PLATFORM_TM_CLK_SELECT;

#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
        timerConfig.timeStampSrcClock_Hz    = PLATFORM_TM_STAMP_CLK_FREQ;
        timerConfig.timeStampInstance       = PLATFORM_TM_STAMP_INSTANCE;
        timerConfig.timeStampClockSrcSelect = PLATFORM_TM_STAMP_CLK_SELECT;
#endif

        tm_st = TM_Init(&timerConfig);
        if (tm_st != kStatus_TimerSuccess)
        {
            status = RAISE_ERROR(tm_st, 1);
            assert(0);
        }
        else
        {
            /* Timer Manager initialization completed */
            timer_manager_initialized = 1;
        }
    }
    else
    {
        /* Timer Manager already initialized */
        status = 1;
    }
    return status;
}

void PLATFORM_DeinitTimerManager(void)
{
    if (timer_manager_initialized == 1)
    {
        TM_Deinit();
        timer_manager_initialized = 0;
    }
}

uint64_t PLATFORM_GetTimeStamp(void)
{
    /* u64ReadTimeStamp mimics TSTMR_ReadTimeStamp(TSTMR0) but copied to avoid dependency
     * with fsl_tstmr.h not present in include path
     */
    return u64ReadTimeStamp(TSTMR0);
}

uint64_t PLATFORM_Get32KTimeStamp(void)
{
#if defined gPlatformHasTstmr32K_d && (gPlatformHasTstmr32K_d > 0)
    /* u64ReadTimeStamp mimics TSTMR_ReadTimeStamp(TSTMR0) but copied to avoid dependency
     * with fsl_tstmr.h not present in include path
     */
    return u64ReadTimeStamp(TSTMR1_0);
#else
    return 0ULL;
#endif
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
 * \brief Compute number of microseconds between 2 timestamps expressed in number of TSTM 32kHz ticks
 *
 * \param [in] timestamp0 start timestamp from which duration is assessed.
 * \param [in] timestamp1 end timestamp till which duration is assessed.
 *
 * \return uint64_t number of microseconds
 *
 */
uint64_t PLATFORM_Get32kTimeStampDeltaUs(uint64_t timestamp0, uint64_t timestamp1)
{
#if defined gPlatformHasTstmr32K_d && (gPlatformHasTstmr32K_d > 0)
    uint64_t duration_us;

    duration_us = GetTimeStampDeltaTicks(timestamp0, timestamp1);
    /* Prevent overflow */
    duration_us &= TSTMR_MAX_VAL;
    /* Normally useless but let Coverity know that the input is necessarily less than 2^56 */
    /* Multiply by 1000000 (2^6 * 5^6) and divide by 32768 (2^15) can be be simplified to Multiplication by 125*125 and
     * division by 512 */
    /* Multiply by 125, inserting the division by 64 and then multiply again by 125 and finally divide by 8 prevents the
     * overflow considering the argument is smaller than 2^56
     */
    duration_us *= 125ULL; /* Since timestamps are no more than 56 bit wide, multiplying by 125 is smaller than 2^63 */
    duration_us >>= 6;     /* Dividing by 64 (2^6) yields a result strictly smaller than 2^57 */
    duration_us *= 125ULL; /* Multiplying by 125 is necessarily strictly smaller than 2^64-1 */
    duration_us >>= 3;     /* Divide by 8 (2^3)  */

    return duration_us;
#else
    return ~0ULL;
#endif
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
    BOARD_DBGLPIOSET(1, 1);
    BOARD_DBGLPIOSET(0, 1);

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
            BOARD_DBGLPIOSET(0, 1);
            __ASM("NOP");
            BOARD_DBGLPIOSET(0, 0);
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

    BOARD_DBGLPIOSET(0, 0);
}

void PLATFORM_RemoteActiveRel(void)
{
    BOARD_DBGLPIOSET(0, 1);

    OSA_InterruptDisable();

    if (active_request_nb > 0)
    {
        active_request_nb--;

        if (active_request_nb == 0)
        {
            uint32_t rfmc_ctrl;
            rfmc_ctrl = RFMC->RF2P4GHZ_CTRL;
            rfmc_ctrl &= ~RFMC_RF2P4GHZ_CTRL_BLE_WKUP_MASK;
            RFMC->RF2P4GHZ_CTRL = rfmc_ctrl;
            BOARD_DBGLPIOSET(1, 0);
        }
    }
    else
    {
        assert(0);
    }

    OSA_InterruptEnable();

    BOARD_DBGLPIOSET(0, 0);
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

void PLATFORM_SetLdoCoreNormalDriveVoltage(void)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    spc_active_mode_core_ldo_option_t ldoOption;
    ldoOption.CoreLDOVoltage       = kSPC_CoreLDO_NormalVoltage;
    ldoOption.CoreLDODriveStrength = kSPC_CoreLDO_NormalDriveStrength;
    (void)SPC_SetActiveModeCoreLDORegulatorConfig(SPC0, &ldoOption);
#endif /* !defined(FPGA_TARGET) || (FPGA_TARGET == 0) */
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

int PLATFORM_StartFro6MCalibration(void)
{
    Platform_Fro6MCalCtx_t *ctx = &fro6M_calibration_ctx;
    /* Remember initial state to be able to restore as was */
    ctx->trcena_state = (bool)((CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk) != 0U);
    ctx->dwt_state    = (bool)((DWT->CTRL & 1U) != 0U);

    MRCC_TSTMR0_REG = MRCC_MRCC_TSTMR0_CLKSEL_CC(MRCC_TSTMR_CLK_EN_LP_STALL_IDLE);

    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    ctx->initial_ts = PLATFORM_GetTimeStamp();

    DWT->CYCCNT = 0U;                                   /* Reset cycle counter */
    DWT->CTRL |= 1U;                                    /* enable cycle counter */
    ctx->core_cycles_1us = SystemCoreClock / 1000000UL; /* after the start of CYCCNT to consume time */

    ctx->started = true;
    return 0;
}

int PLATFORM_EndFro6MCalibration(void)
{
    int                     st;
    Platform_Fro6MCalCtx_t *ctx = &fro6M_calibration_ctx;
    volatile uint32_t       cyc;
    uint64_t                now;
    uint64_t                tstmr_ticks_delta;
    uint32_t                cyc_for_6us;
    uint32_t                nb_usec_core;
    uint32_t                nb_usec_tstmr;
    uint32_t                ratio;
    if (ctx->started)
    {
        cyc_for_6us = 6u * ctx->core_cycles_1us;
        do
        {
            /* spin here until 6us have elapsed since the DWT->CYCNT reset in PLATFORM_StartFro6MCalibration() */
            cyc = DWT->CYCCNT;
        } while (cyc < cyc_for_6us);

        /* Read current TSTMR value */
        now = PLATFORM_GetTimeStamp();

        /* tstmr_tick_diff should be a number of microseconds if FRO6M has correctly locked */
        tstmr_ticks_delta = GetTimeStampDeltaTicks(ctx->initial_ts, now);

        if (tstmr_ticks_delta < (uint64_t)UINT32_MAX)
        {
            nb_usec_core  = cyc / ctx->core_cycles_1us;
            nb_usec_tstmr = (uint32_t)tstmr_ticks_delta;

            /* Multiply nb_usec_core by 10 so as to avoid loss of precision when dividing */
            ratio = (10u * nb_usec_core) / nb_usec_tstmr;

            /* FRO-6M is supposed to oscillate at 6MHz as its name hints : if by lack of luck it has locked on 2MHz,
             * the actual ratio between the clocks is 6MHz/2MHz i.e. 3.
             * In the worst case, having waited for a duration of 6us guarantees to have nb_usec_core >= 6.
             * tstmr_ticks_delta is guaranteed to be greater than 4 if the clock was actually 6MHz.
             * In the 2MHz case, tstmr_ticks_delta will be comprised between 1 and 3.
             * Hence the comparison of the ratio with 20.
             *
             */
            if (ratio < 20U)
            {
                ctx->ratio = 1U; /* 6MHz Ok */
            }
            else
            {
                ctx->ratio = 3U; /* 2MHz detected */
            }

            st = 0;
        }
        else
        {
            /* Error case the tick difference ought to remain relatively small and remain much smaller than UINT32_MAX
             */
            ctx->ratio = 1u; /* 6MHz Ok */
            st         = 2;
            assert(tstmr_ticks_delta < (uint64_t)UINT32_MAX);
        }
        fwk_platform_FRO6MHz_ratio = ctx->ratio;
        if (!ctx->trcena_state)
        {
            CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk;
            ctx->trcena_state = false;
        }
        if (!ctx->dwt_state)
        {
            DWT->CTRL &= ~1U;
        }
        ctx->started = false;
    }
    else
    {
        st = 1; /* was not started */
    }
    return st;
}

void PLATFORM_RegisterXtal32MTempCompLut(const xtal_temp_comp_lut_t *lut)
{
    pXtal32MTempCompLut = lut;
}

int PLATFORM_CalibrateXtal32M(int16_t temperature)
{
    int ret = 0;

    do
    {
        if (pXtal32MTempCompLut == NULL)
        {
            ret = 1;
            break;
        }

        if (PLATFORM_SetXtalTempComp(pXtal32MTempCompLut, temperature) < 0)
        {
            ret = -1;
        }
    } while (false);

    return ret;
}
