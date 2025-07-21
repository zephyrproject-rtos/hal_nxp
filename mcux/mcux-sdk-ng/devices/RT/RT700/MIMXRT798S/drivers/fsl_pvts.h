/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PVTS_H_
#define FSL_PVTS_H_

#include <stdint.h>
#include <stdbool.h>
#include "fsl_common.h"

/*!
 * @addtogroup pvts
 * @{
 */

/*******************************************************************************
 * Defines
 ******************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief pvts driver version 2.0.0. */
#define FSL_PVTS_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define PVTS_GET_DELAY0_FROM_FUSE_VALUE(fuse) ((pvts_delay_t)(fuse & 0x00FFU))         /*!< Calculate delay0 value from fuse word. */
#define PVTS_GET_DELAY1_FROM_FUSE_VALUE(fuse) ((pvts_delay_t)((fuse & 0xFF00U) >> 8U)) /*!< Calculate delay1 value from fuse word. */  

/*!
 * @brief PVTS sensors, each PVTS provides 2 sets of sensors to monitor 2 CPUs in same power domain.
 */
typedef enum pvts_sensor
{
    kPVTS_Sensor0, /*!< Sensor 0 for ARM core. */
    kPVTS_Sensor1, /*!< Sensor 1 for HiFi core. */
} pvts_sensor_t;

#if defined(PVTS0)
/*!
 * @brief PVTS instance. Only CPU0 can read fuse, so only supported for CPU0.
 */
typedef enum pvts_instance
{
    kPVTS_Vdd2Com   = 0U, /*!< PVTS0 for VDD2_COM domain */
    kPVTS_Vdd1Sense = 1U, /*!< PVTS1 for VDD1_SENSE domain */
} pvts_instance_t;
#endif

/*!
 * @brief PVTS delay type.
 */
typedef uint8_t pvts_delay_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes the PVTS peripheral.
 * @note The complete initialization should look like below.
 *
 * @code
 * uint32_t delay;
 * PVTS_ReadDelayFromOTP(false, kPVTS_Vdd2Com, CLOCK_GetFreq(kCLOCK_CoreSysClk),  &delay);
 * PVTS_Init();
 * EnableIRQ((IRQn_Type) PVTS0_IRQn);
 * PVTS_EnableAlertCount(kPVTS_Sensor0);
 * PVTS_SetDelay(kPVTS_Sensor0, PVTS_GET_DELAY0_FROM_FUSE_VALUE(delay));
 * PVTS_Start(kPVTS_Sensor0);
 * @endcode
 */
void PVTS_Init(void);

/*!
 * @brief De-initializes the PVTS peripheral.
 */
void PVTS_Deinit(void);

/*!
 * @brief Enables PVTS sensing.
 * @param sensor the sensor to start.
 */
void PVTS_Start(pvts_sensor_t sensor);

/*!
 * @brief Disables PVTS sensing.
 * @param sensor the sensor to stop.
 */
void PVTS_Stop(pvts_sensor_t sensor);

#if defined(PVTS0)
/*!
 * @brief Reads the PVTS delay value from OTP. Can only be called by CPU0(CM33 core0).
 *
 * @param otp_initialized Specifies whether the OTP is already initialized or not.
 * false: The driver will initialize the OTP, read the delay value, and then de-initialize the OTP.
 * true: OTP initialized by the calling app. driver will read the delay value from OTP and return.
 * @param instance PVTS instance or power domain.
 * @param core_freq_hz Core clock frequency in hertz.
 * @param delayValues Pointer to a uint32_t where the PVT delay values will be returned. 
 *        Use PVTS_GET_DELAY0_FROM_FUSE_VALUE to get delay value for ARM core, 
 *        PVTS_GET_DELAY1_FROM_FUSE_VALUE for HiFi DSP core.
 * @retval kStatus_Success Successfully read the delay from OTP.
 * @retval kStatus_Fail Failed to read delay from OTP.
 */
status_t PVTS_ReadDelayFromOTP(bool otp_initialized,
                               pvts_instance_t instance,
                               uint32_t core_freq_hz,
                               uint32_t *delayValues);
#endif

/*!
 * @brief Reads the current PVTS delay value.
 *
 * @param sensor the sensor to read.
 * @param delay_value Pointer to a pvts_delay_t where the PVT delay value will be placed.
 * @retval kStatus_Success Successfully read the delay.
 * @retval kStatus_Fail Failed to read delay because it has not been set.
 */
status_t PVTS_GetDelay(pvts_sensor_t sensor, pvts_delay_t *delay_value);

/*!
 * @brief Sets the delay value for the PVTS.
 *
 * @note Must call PVTS_Start() to start sensing.
 *
 * @param sensor the sensor to configure.
 * @param delay value read using PVTS_ReadDelayFromOTP().
 * @retval kStatus_Success Successfully sets the delay.
 * @retval kStatus_InvalidArgument Failed to set delay. Invalid parameter passed in.
 */
status_t PVTS_SetDelay(pvts_sensor_t sensor, pvts_delay_t delay);

/*!
 * @brief Enables the 20-bit PVT alert counter.
 *
 * Enables counting the amount of times the PVTS interrupt has triggered.
 *
 * @param sensor the sensor to configure.
 * @note It is up to the user to clear the counter.
 */
void PVTS_EnableAlertCount(pvts_sensor_t sensor);

/*!
 * @brief Disables the 20-bit PVTS alert counter.
 * @param sensor the sensor to set.
 */
void PVTS_DisableAlertCount(pvts_sensor_t sensor);

/*!
 * @brief Reads the 20-bit PVTS alert counter.
 *
 * @param sensor the sensor to read.
 * @return 20-bit PVT alert counter value.
 */
uint32_t PVTS_GetAlertCount(pvts_sensor_t sensor);

/*!
 * @brief Resets the 20-bit PVTS alert counter.
 * @param sensor the sensor to clear.
 */
void PVTS_ClearAlertCount(pvts_sensor_t sensor);

/*@}*/

#if defined(__cplusplus)
}
#endif

#endif /* _PVT_H_ */
