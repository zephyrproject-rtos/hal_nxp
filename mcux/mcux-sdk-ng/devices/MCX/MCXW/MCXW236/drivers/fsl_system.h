/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_SYSTEM_H_
#define _FSL_SYSTEM_H_

#include "fsl_common.h"

/*!
 * @addtogroup system
 * @{
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

 /*! @name Driver version */
/*@{*/
/*! @brief SYSTEM driver version 2.0.0. */
#define FSL_SYSTEM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

typedef enum chip_version_s
{
    kCHIPVERSION_UNKNOWN = 0x00U,
    kCHIPVERSION_A3      = 0xA3U,
    kCHIPVERSION_A4      = 0xA4U,
    kCHIPVERSION_A5      = 0xA5U
} chip_version_t;

typedef enum chip_package_s
{
    kCHIPPACKAGETYPE_UNKNOWN = 0x00U,
    kCHIPPACKAGETYPE_QFN     = 0x2U,
    kCHIPPACKAGETYPE_VBGA    = 0x4U,
    kCHIPPACKAGETYPE_WLCSP   = 0x8U
} chip_package_type_t;

typedef enum freq_meas_target_clock_s /* values must match with INPUTMUX_FREQMEAS_TARGET_CLKIN */
{
    kFREQMEAS_target_clock_12_24_32MHz_FRO = 1U,
    kFREQMEAS_target_clock_1MHz_FRO        = 3U,
    kFREQMEAS_target_clock_32kHz_FRO       = 4U
} freq_meas_target_clock_t;

typedef enum freq_meas_ref_time_exponent_s
{
    /*                                            duration us       ppm for measuring 32768Hz   ppm 12MHz  ppm 1 MHz */
    /*                                                              (approximation)                                  */
    kFREQMEAS_ref_time_exp_7  = 7U,  /*                 4                                       20833      250000    */
    kFREQMEAS_ref_time_exp_8  = 8U,  /*                 8                                       10417      125000    */
    kFREQMEAS_ref_time_exp_9  = 9U,  /*                 16                                      5208       62500     */
    kFREQMEAS_ref_time_exp_10 = 10U, /*                 32            953674                    2604       31250     */
    kFREQMEAS_ref_time_exp_11 = 11U, /*                 64            476837                    1302       15625     */
    kFREQMEAS_ref_time_exp_12 = 12U, /*                 128           238419                    651        7813      */
    kFREQMEAS_ref_time_exp_13 = 13U, /*                 256           119209                    326        3906      */
    kFREQMEAS_ref_time_exp_14 = 14U, /*                 512           59605                     163        1953      */
    kFREQMEAS_ref_time_exp_15 = 15U, /*                 1024          29802                     81         977       */
    kFREQMEAS_ref_time_exp_16 = 16U, /*                 2048          14901                     41         488       */
    kFREQMEAS_ref_time_exp_17 = 17U, /*                 4096          7451                      20         244       */
    kFREQMEAS_ref_time_exp_18 = 18U, /*                 8192          3725                      10         122       */
    kFREQMEAS_ref_time_exp_19 = 19U, /*                 16384         1863                      5          61        */
    kFREQMEAS_ref_time_exp_20 = 20U, /*                 32768         931                       3          31        */
    kFREQMEAS_ref_time_exp_21 = 21U, /*                 65536         466                       1          15        */
    kFREQMEAS_ref_time_exp_22 = 22U, /*                 131072        233                       1          8         */
    kFREQMEAS_ref_time_exp_23 = 23U, /*                 262144        116                       0          4         */
    kFREQMEAS_ref_time_exp_24 = 24U, /*                 524288        58                        0          2         */
    kFREQMEAS_ref_time_exp_25 = 25U, /*                 1048576       29                        0          1         */
    kFREQMEAS_ref_time_exp_26 = 26U, /*                 2097152       15                        0          0         */
    kFREQMEAS_ref_time_exp_27 = 27U, /*                 4194304       7                         0          0         */
    kFREQMEAS_ref_time_exp_28 = 28U, /*                 8388608       4                         0          0         */
    kFREQMEAS_ref_time_exp_29 = 29U, /*                 16777216      2                         0          0         */
    kFREQMEAS_ref_time_exp_30 = 30U, /*                 33554432      1                         0          0         */
    kFREQMEAS_ref_time_exp_31 = 31U, /*hw limit         67108864      0                         0          0         */
    kFREQMEAS_count = 32U
} freq_meas_ref_time_exponent_t;

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief Assembles chip version from Flash and/or hardware registers
 *
 * @return chip version.
 */
chip_version_t SYSTEM_GetChipVersion(void);

/*!
 * @brief Assembles device type from Flash NMPA.
 * @param typeNr  Pointer to store device type number. This is a 16bit value holding the type numbers in hexadecimal
 * value (e.g. 5204)
 * @param securityEnabled  Pointer to store security enablement.
 *  @li true Security is enabled on this device (secure boot and PUF available)
 *  @li false Security is disabled on this device (no secure boot and no PUF available)
 * @param packageType  Pointer to store package type of this device. See @ref chip_package_type_t
 * @param nrOfPins  Pointer to store number of pins that this device contains.
 */
void SYSTEM_GetDeviceType(uint16_t *typeNr, bool *securityEnabled, chip_package_type_t *packageType, uint8_t *nrOfPins);

/*!
 * @brief accurate Measurement of 32kHz Frequency
 *
 * This function measures the 32kHz frequency referenced to an accurate 32MHz (BLE) XTAL.
 * The formula is: Ftarget = (Count * Freference) / ((1<<SCALE)-1)
 *
 * @refClockPowerOf2Cycles Define the power of 2 count that ref counter counts to during measurement.
 * @return measured frequency of the target clock in mHz.
 *
 * @Note the minimum count (scale) is 2.
 */
uint32_t SYSTEM_MeasureFrequency32kHzAccurate(freq_meas_ref_time_exponent_t refClockPowerOf2Cycles);

/*!
 * @brief Measure Frequency
 *
 * This function measures target frequency referenced to an accurate 32MHz (BLE) XTAL.
 * The formula is: Ftarget = (Count * Freference) / ((1<<SCALE)-1)
 *
 * @targetClock target clock.
 * @refClockPowerOf2Cycles Define the power of 2 count that ref counter counts to during measurement.
 * @return measured frequency of the target clock.
 *
 * @Note the minimum count (scale) is 2.
 */
uint32_t SYSTEM_MeasureFrequency(freq_meas_target_clock_t targetClock,
                                 freq_meas_ref_time_exponent_t refClockPowerOf2Cycles);
/* @} */

/*!
 * @brief Calibrates clock referenced to 32MHz XTAL oscillator using a successive calibration algorithm for large
 * deviations.
 *
 * @param targetClk  Clock to calibrate.
 */
void SYSTEM_CalibrateClock(freq_meas_target_clock_t targetClock);

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief Calibrates clock referenced to 32MHz XTAL oscillator for small deviations.
 *
 * @param targetClock  Clock to calibrate.
 */
void SYSTEM_CalibrateClockFine(freq_meas_target_clock_t targetClock);

/*!
 * @brief Calibrates RTC clock dividers referenced to 32MHz XTAL oscillator
 *
 * @param None
 */
void SYSTEM_CalibrateRTCClockDividers(void);

/**
 * @}
 */

#endif /* _FSL_SYSTEM_H_ */
