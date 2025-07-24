/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pvts.h"
#if defined(PVTS0)
#include "fsl_romapi_otp.h"
#endif

/*******************************************************************************
 * Defines
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pvts"
#endif

#define PVTS_NUM_OF_SP           3U  /* Sum of setpoints. */
#define PVTS_DELAY_MAX_CTRL_WORD 0x3FFU
#define PVTS_DELAY_MAX           62U /* Delay 0 -> 31, Delay 1 -> 31*/
#define PVTS_DELAY_MIN           2U  /* Delay 0 -> 1, Delay 1 -> 1*/
#define PVTS_DELAY_OFF           0U
#define IS_DELAY_VALID(del)      ((del >= PVTS_DELAY_MIN) && (del <= PVTS_DELAY_MAX))
#define OTP_FUSE_ADDR_NOT_FOUND  0U

#if defined(PVTS0)
#define PVTS PVTS0
#elif defined(PVTS1)
#define PVTS PVTS1
#else
#error "Unsupported core or soc header!"
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint32_t delay_to_control_word(uint8_t delay_value);

#if defined(PVTS0)
const uint32_t cpu_freq[PVTS_PVT_COUNT][PVTS_NUM_OF_SP]   = {{110000000U, 192000000U, 325000000U},
                                                             {100000000U, 160000000U, 250000000U}};
const uint32_t fuse_index[PVTS_PVT_COUNT][PVTS_NUM_OF_SP] = {{487U, 485U, 483U}, {486U, 484U, 482U}};
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
static pvts_delay_t delay[PVTS_PVT_COUNT];
/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(PVTS0)
static uint32_t PVTS_GetFuseAddrIndex(uint32_t cpu_frequency, uint32_t pvts)
{
    uint32_t i;

    for (i = 0U; i < PVTS_NUM_OF_SP; i++)
    {
        if (cpu_frequency == cpu_freq[pvts][i])
        {
            return fuse_index[pvts][i];
        }
    }

    return OTP_FUSE_ADDR_NOT_FOUND;
}

/* This API is to get cpu delay value from fuses
   But now it does not have delay vaule, so just return the preset value
   Input - Freq, Output - Delay value*/

status_t PVTS_ReadDelayFromOTP(bool otp_initialized,
                               pvts_instance_t instance,
                               uint32_t core_freq_hz,
                               uint32_t *delayValues)
{
    uint32_t new_delay;
    int32_t pvts_fuse_addr_index;

    if (!otp_initialized)
    {
        otp_init();
    }

    pvts_fuse_addr_index = PVTS_GetFuseAddrIndex(core_freq_hz, (uint32_t)instance);
    if (pvts_fuse_addr_index == OTP_FUSE_ADDR_NOT_FOUND)
    {
        return kStatus_InvalidArgument;
    }

    if (kStatus_Success != otp_fuse_read(pvts_fuse_addr_index, &new_delay))
    {
        return kStatus_Fail;
    }

    if (!otp_initialized)
    {
        otp_deinit();
    }

    if (!IS_DELAY_VALID(PVTS_GET_DELAY0_FROM_FUSE_VALUE(new_delay)))
    {
        return kStatus_Fail;
    }
    if (!IS_DELAY_VALID(PVTS_GET_DELAY1_FROM_FUSE_VALUE(new_delay)))
    {
        return kStatus_Fail;
    }

    *delayValues = new_delay;

    return kStatus_Success;
}
#endif

/*!
 * This function converts number of delays to the hex value for writing to the
 * PVTS sensor control reg.
 * input - delay value, output - value needs set to register
 */
static uint32_t delay_to_control_word(pvts_delay_t delay_value)
{
    uint32_t delay1, delay0;

    if (delay_value >= PVTS_DELAY_MAX)
    {
        return PVTS_DELAY_MAX_CTRL_WORD;
    }

    delay1 = delay_value >> 1U;
    delay0 = delay_value - delay1;
    return PVTS_DEL_CTRL_DELAY1(delay1) | PVTS_DEL_CTRL_DELAY0(delay0);
};

void PVTS_Init(void)
{
#if defined(PVTS0)
    /* Enable clock */
    CLOCK_EnableClock(kCLOCK_Pvts0);
#else
    CLOCK_EnableClock(kCLOCK_Pvts1);
    RESET_ClearPeripheralReset(kPVTS1_RST_SHIFT_RSTn);
#endif
    /* Initialize the delay to off */
    delay[0] = PVTS_DELAY_OFF;
    delay[1] = PVTS_DELAY_OFF;
}

void PVTS_Deinit(void)
{
    PVTS_DisableAlertCount(kPVTS_Sensor0);
    PVTS_ClearAlertCount(kPVTS_Sensor0);

    PVTS_DisableAlertCount(kPVTS_Sensor1);
    PVTS_ClearAlertCount(kPVTS_Sensor1);

    PVTS_Stop(kPVTS_Sensor0);
    PVTS_Stop(kPVTS_Sensor1);
    delay[0] = PVTS_DELAY_OFF;
    delay[1] = PVTS_DELAY_OFF;
#if defined(PVTS0)
    CLOCK_DisableClock(kCLOCK_Pvts0);
#else
    CLOCK_DisableClock(kCLOCK_Pvts1);
    RESET_SetPeripheralReset(kPVTS1_RST_SHIFT_RSTn);
#endif
}

void PVTS_Start(pvts_sensor_t sensor)
{
    PVTS->PVT[(uint32_t)sensor].DEL_CTRL = delay_to_control_word(delay[(uint32_t)sensor]);
}

void PVTS_Stop(pvts_sensor_t sensor)
{
    PVTS->PVT[(uint32_t)sensor].DEL_CTRL = PVTS_DELAY_OFF;
}

status_t PVTS_GetDelay(pvts_sensor_t sensor, pvts_delay_t *delay_value)
{
    if (delay_value == NULL)
    {
        return kStatus_Fail;
    }

    *delay_value = delay[(uint32_t)sensor];

    return kStatus_Success;
}

status_t PVTS_SetDelay(pvts_sensor_t sensor, pvts_delay_t value)
{
    if (!IS_DELAY_VALID(value))
    {
        return kStatus_InvalidArgument;
    }

    delay[(uint32_t)sensor] = value;

    return kStatus_Success;
}

void PVTS_EnableAlertCount(pvts_sensor_t sensor)
{
    PVTS->PVT[(uint32_t)sensor].ALERT_CNT_CTRL = PVTS_ALERT_CNT_CTRL_CNTEN(1);
}

void PVTS_DisableAlertCount(pvts_sensor_t sensor)
{
    PVTS->PVT[(uint32_t)sensor].ALERT_CNT_CTRL = PVTS_ALERT_CNT_CTRL_CNTEN(0);
}

uint32_t PVTS_GetAlertCount(pvts_sensor_t sensor)
{
    return ((PVTS->PVT[(uint32_t)sensor].ALERT_CNT & PVTS_ALERT_CNT_CNT_MASK) >> PVTS_ALERT_CNT_CNT_SHIFT);
}

void PVTS_ClearAlertCount(pvts_sensor_t sensor)
{
    PVTS->PVT[(uint32_t)sensor].ALERT_CNT = 0U;
}