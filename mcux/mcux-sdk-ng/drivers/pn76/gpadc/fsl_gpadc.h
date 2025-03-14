/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_GPADC_H_
#define FSL_GPADC_H_

#include "fsl_common.h"
#include "fsl_pn_wrapper.h"

/*!
 * @addtogroup gpadc
 * @{
 *
 * ADC driver supports read voltage for internal sensor for external pin.
 * The typical workflow:
 *
 * - Read voltage of external pin
 *   1. Call GPADC_ExtPin_Init() to initialize the GPADC for external pin read.
 *   2. Call GPADC_ExtPin_Read() to read the external pin voltage.
 *   3. Call GPADC_ExtPin_DeInit() to de-initialize the GPADC.
 *
 * - Read voltage of sensor
 *   1. Call GPADC_Init() to initialize the GPADC for sensor voltage read.
 *   2. Call GPADC_ReadSensor(), or GPADC_ReadSensorOneShot() to get sensor voltage.
 *   3. Call GPADC_Deinit() to de-initialize the GPADC.
 *
 * Optionally, GPADC_SetThreshold can be called to set the threshold for each sensor,
 * meanwhile, GPADC_RegisterCallback can register the callback when voltage out of
 * threshold range. the external pin shares the same threshold with kGPADC_SensorVBAT_ExtPin.
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @brief GPADC driver version. */
#define FSL_GPADC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))

/*!
 * @brief GPADC sensor selection.
 */
typedef enum
{
    kGPADC_SensorReserved    = E_PN76_PCRM_GPADC_SENSOR_RESERVED,  /**< Reserved sensor */
    kGPADC_SensorRSSI        = E_PN76_PCRM_GPADC_SENSOR_RSSI_OUT,  /**< RX RSSI output sense */
    kGPADC_SensorBandgap     = E_PN76_PCRM_GPADC_SENSOR_VBG_SNS,   /**< Trimmed Bandgap 0.9V */
    kGPADC_SensorTempPmu     = E_PN76_PCRM_GPADC_SENSOR_TEMP_PMU,  /**< Temperature sense PMU (in Celcius degrees) */
    kGPADC_SensorTempClif    = E_PN76_PCRM_GPADC_SENSOR_TEMP_CLIF, /**< Temperature sense CLIF */
    kGPADC_SensorXtalPeakDet = E_PN76_PCRM_GPADC_SENSOR_XTAL_PEAK_DET, /**< XTAL peak detector */
    kGPADC_SensorVBAT_ExtPin = E_PN76_PCRM_GPADC_SENSOR_VBAT,          /**< Battery voltage (in mV) or external pin. */
    kGPADC_SensorGround      = E_PN76_PCRM_GPADC_SENSOR_GROUND,        /**< Ground */
    kGPADC_SensorVDDPA       = E_PN76_PCRM_GPADC_SENSOR_VDDPA,         /**< VDDPA voltage  */
} gpadc_sensor_t;

/*!
 * @brief Enum for Different General Purpose Analog to Digital Converter (GPADC) value types.
 */
typedef enum
{
    /* Type selection. */
    kGPADC_TypeVal = E_PN76_PCRM_GPADC_TYPE_VAL, /**< Current value  */
    kGPADC_TypeMin = E_PN76_PCRM_GPADC_TYPE_MIN, /**< Min value */
    kGPADC_TypeMax = E_PN76_PCRM_GPADC_TYPE_MAX, /**< Max value */
    kGPADC_TypeIIR = E_PN76_PCRM_GPADC_TYPE_IIR, /**< IIR filtered value */
    kGPADC_TypeAvg = E_PN76_PCRM_GPADC_TYPE_AVG, /**< Average filtered value */

    /* Use converted data or not. */
    kGPADC_TypeConv  = E_PN76_PCRM_GPADC_TYPE_CONV,  /**< Select converted values (with conversion to physical scale) */
    kGPADC_TypeGross = E_PN76_PCRM_GPADC_TYPE_GROSS, /**< Select gross values (no conversion to physical scale) */

    /* Single end or differential measurement. */
    kGPADC_TypeSingleEnd    = E_PN76_PCRM_GPADC_TYPE_SINGLE_ENDED, /**< Single ended measurement */
    kGPADC_TypeDifferential = E_PN76_PCRM_GPADC_TYPE_DIFFERENTIAL, /**< Differential measurement */

    /* Mask for measurement options. */
    kGPADC_TypeConvGrossMask = E_PN76_PCRM_GPADC_TYPE_CONV_GROSS_MASK, /**< Mask for the converted/gross option. */
    kGPADC_TypeValMask = E_PN76_PCRM_GPADC_TYPE_VAL_MASK, /**< Mask for value type, current value/min/max/iir/avg. */
    kGPADC_TypeMeasureTypeMask =
        E_PN76_PCRM_GPADC_TYPE_MEASURE_TYPE_MASK, /**< Mask for measurement type, single end or differential. */

    /*
     * These are the combination of value type option, convert/gross option, singleend/differential option,
     * Recommond to use these directly instead of constructing like kGPADC_TypeVal | kGPADC_TypeConv.
     */
    kGPADC_TypeValConv     = E_PN76_PCRM_GPADC_TYPE_VAL_CONV,      /**< Converted current value */
    kGPADC_TypeMinConv     = E_PN76_PCRM_GPADC_TYPE_MIN_CONV,      /**< Converted Min value */
    kGPADC_TypeMaxConv     = E_PN76_PCRM_GPADC_TYPE_MAX_CONV,      /**< Converted Max value */
    kGPADC_TypeIIRConv     = E_PN76_PCRM_GPADC_TYPE_IIR_CONV,      /**< Converted IIR filtered value */
    kGPADC_TypeAvgConv     = E_PN76_PCRM_GPADC_TYPE_AVG_CONV,      /**< Converted average filtered value */
    kGPADC_TypeValGross    = E_PN76_PCRM_GPADC_TYPE_VAL_GROSS,     /**< Gross current value */
    kGPADC_TypeMinGross    = E_PN76_PCRM_GPADC_TYPE_MIN_GROSS,     /**< Gross Min value */
    kGPADC_TypeMaxGross    = E_PN76_PCRM_GPADC_TYPE_MAX_GROSS,     /**< Gross Max value */
    kGPADC_TypeIIRGross    = E_PN76_PCRM_GPADC_TYPE_IIR_GROSS,     /**< Gross IIR filtered value */
    kGPADC_TypeAvgGross    = E_PN76_PCRM_GPADC_TYPE_AVG_GROSS,     /**< Gross average filtered value */
    kGPADC_TypeValConvDiff = E_PN76_PCRM_GPADC_TYPE_VAL_CONV_DIFF, /**< Differential Converted current value */
    kGPADC_TypeMinConvDiff = E_PN76_PCRM_GPADC_TYPE_MIN_CONV_DIFF, /**< Differential Converted Min value */
    kGPADC_TypeMaxConvDiff = E_PN76_PCRM_GPADC_TYPE_MAX_CONV_DIFF, /**< Differential Converted Max value */
    kGPADC_TypeIIRConvDiff = E_PN76_PCRM_GPADC_TYPE_IIR_CONV_DIFF, /**< Differential Converted IIR filtered value */
    kGPADC_TypeAvgConvDiff = E_PN76_PCRM_GPADC_TYPE_AVG_CONV_DIFF, /**< Differential Converted average filtered value */
    kGPADC_TypeValGrossDiff = E_PN76_PCRM_GPADC_TYPE_VAL_GROSS_DIFF, /**< Differential Gross current value */
    kGPADC_TypeMinGrossDiff = E_PN76_PCRM_GPADC_TYPE_MIN_GROSS_DIFF, /**< Differential Gross Min value */
    kGPADC_TypeMaxGrossDiff = E_PN76_PCRM_GPADC_TYPE_MAX_GROSS_DIFF, /**< Differential Gross Max value */
    kGPADC_TypeIIRGrossDiff = E_PN76_PCRM_GPADC_TYPE_IIR_GROSS_DIFF, /**< Differential Gross IIR filtered value */
    kGPADC_TypeAvgGrossDiff = E_PN76_PCRM_GPADC_TYPE_AVG_GROSS_DIFF, /**< Differential Gross average filtered value */
} gpadc_value_type_t;

/*! @brief GPADC callback. */
typedef void (*gpadc_callback_t)(void);

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Performs GPADC Initialization.
 *
 * This function Initialized the GPADC by mapping the channels and performing calibration.
 *
 * @return Returns kStatus_PN_Success no error occurred, return any other value if an error occurred.
 */
static inline pn_status_t GPADC_Init(void)
{
    return (pn_status_t)PN76_Sys_Hal_PCRM_Gpadc_Init();
}

/*!
 * @brief This function returns the requested sensor value.
 *
 * This API reads the requested sensor value based on the value type.
 *
 * When calling this API, each sensor is fixed mapped to seperate channel, the channels can work
 * simultaneously, the ADC value type can be averaged, minimum, maximum.
 *
 * @note   If the MUX is enabled for measuring the external pin value (\ref GPADC_ExtPin_GetEnableStatus()),
 *         then this function returns the external pin voltage, but not VBAT voltage, when \ref gpadc_sensor_t eSensor.
 *         is \ref kGPADC_SensorVBAT_ExtPin.
 *
 * @param  eSensor: Sensor used to get General Purpose Analog to Digital Converter (GPADC) value.
 * @param  eType: Type of acquisition (either gross value or real scale value).
 * @param  *milliVolt: Voltage.
 *
 * @retval  kStatus_PN_Success On Success.
 * @retval  kStatus_PN_InternalError On wrong sensor acquisition request.
 */
pn_status_t GPADC_ReadSensor(gpadc_sensor_t eSensor, gpadc_value_type_t eType, int32_t *milliVolt);

/*!
 * @brief This function returns the instant value of requested sensor.
 *
 * This API reads the sensor once and returns the value.
 *
 * When calling this API, there is only one ADC channel used, it is mapped to
 * desired sensor dynamically on request.
 *
 * @note   If the MUX is enabled for measuring the external pin value (\ref GPADC_ExtPin_GetEnableStatus()),
 *         then this function returns the external pin voltage, but not VBAT voltage, when \ref gpadc_sensor_t eSensor.
 *         is \ref kGPADC_SensorVBAT_ExtPin.
 *
 * @param  eSensor: Sensor used to get General Purpose Analog to Digital Converter (GPADC) value.
 * @param  eType: Type of acquisition (either gross value or real scale value).
 * @param  *milliVolt: Voltage.
 *
 * @retval  kStatus_PN_Success On Success.
 * @retval  kStatus_PN_InternalError on wrong sensor acquisition request.
 */
pn_status_t GPADC_ReadSensorOneShot(gpadc_sensor_t eSensor, gpadc_value_type_t eType, int32_t *milliVolt);

/*!
 * @brief This function Sets the thresholds for requested sensor. It configures both high and low thresholds.
 *
 * @param  eSensor: Sensor whose threshold is to be configured, \ref gpadc_sensor_t.
 * @param  eType: type of threshold (either gross value or real scale value) \ref gpadc_value_type_t values.
 * @param  wLowThreshold: Low threshold below which an interrupt will be triggered
 * @param  wHighThreshold: High threshold above which an interrupt will be triggered
 *
 * @retval  kStatus_PN_Success On Success.
 * @retval  kStatus_PN_InternalError if the sensor is not mapped on any of the channels.
 * @retval  kStatus_PN_ParameterError If kGPADC_SensorReserved sensor is requested.
 * @retval  kStatus_PN_ParameterError if kGPADC_SensorAny sensor is requested, since kGPADC_SensorAny has no support of
 * real scale threshold
 *
 * @note    kGPADC_SensorAny Sensor to be used only to get One Shot value with GPADC_ReadSensorOneShot.
 */
 

static inline pn_status_t GPADC_SetThreshold(gpadc_sensor_t eSensor,
                                             gpadc_value_type_t eType,
                                             int16_t wLowThreshold,
                                             int16_t wHighThreshold)
{
    return (pn_status_t)PN76_Sys_Hal_PCRM_GpadcSetThreshold(
        (PN76_PCRM_GpadcSensor_t)eSensor, (PN76_PCRM_GpadcValueType_t)eType, wLowThreshold, wHighThreshold);
}

/*!
 * @brief This function Reads the thresholds of requested sensor. It returns both high and low thresholds.
 *
 * @param  eSensor: Sensor whose threshold is to be acquired, \ref gpadc_sensor_t eSensor.
 * @param  eType: type of threshold (either gross value or real scale value) \ref gpadc_value_type_t eType values
 * @param  *wLowThreshold: Low threshold below which an interrupt will be triggered
 * @param  *wHighThreshold: High threshold above which an interrupt will be triggered
 *
 * @retval  kStatus_PN_Success On Success.
 * @retval  kStatus_PN_InternalError if the sensor is not mapped on any of the channels.
 * @retval  kStatus_PN_ParameterError if kGPADC_SensorAny sensor selected, since kGPADC_SensorAny has no support of real
 * scale threshold
 *
 * @note    kGPADC_SensorAny Sensor to be used only to get One Shot value with GPADC_ReadSensorOneShot.
 */
static inline pn_status_t GPADC_GetThreshold(gpadc_sensor_t eSensor,
                                             gpadc_value_type_t eType,
                                             int16_t *wLowThreshold,
                                             int16_t *wHighThreshold)
{
    return (pn_status_t)PN76_Sys_Hal_PCRM_GpadcGetThreshold(
        (PN76_PCRM_GpadcSensor_t)eSensor, (PN76_PCRM_GpadcValueType_t)eType, wLowThreshold, wHighThreshold);
}

/*!
 * @brief Performs GPADC De-Initialization. This function disabled the GPADC module.
 *
 * @note If this API is called, RF will not work.
 */
static inline void GPADC_Deinit(void)
{
    /* Perform De-Initialization of GPADC */
	PN76_Sys_Hal_PCRM_Gpadc_DeInit();
}

/*!
 * @brief   This API will initialize for the MUX that was enabled to measure the voltage on external ADC pin AD1.
 *
 * @retval  kStatus_PN_Success :  Initialization of MUX for measurement on AD1 pin is successfull.
 * @retval  Other values Indicates an error occured. Please refer to \ref pn_status_t.
 *
 */
static inline pn_status_t GPADC_ExtPin_Init(void)
{
    return (pn_status_t)PN76_Sys_PCRM_Init_ExtAnalog_ADC();
}

/*!
 * @brief De-Initialize the GPADC after disabling measurement for external Analog signal
 *
 * @note If this API is called, RF will not work.
 */
static inline void GPADC_ExtPin_DeInit(void)
{
    /* Perform De-Initialize of the GPADC after Disabling AD1 measurement for external Analog signal of GPADC */
    PN76_Sys_PCRM_DeInit_ExtAnalog_ADC();
}

/**
 * @brief This API reads the raw data from external pin.
 *
 * @note  This API must be called only after the \ref GPADC_ExtPin_Init() API.
 * @note  Only digital equivalent to the external pin value is provided. The caller must convert this to absolute value.
 *
 * @param  *pwValue : Raw Data that is being read from the ADC. Only valid if return value is \ref kStatus_PN_Success.
 *
 * @retval  kStatus_PN_Success:  GPADC One Shot mode is executed successfully and read data is stored in the parameter.
 * @retval  Other values Indicates an error occured. Please refer to \ref pn_status_t enum.
 */
static inline pn_status_t GPADC_ExtPin_ReadRawData(int16_t *pwValue)
{
    return (pn_status_t)PN76_Sys_PCRM_Read_OneShot_ExtAnalog_ADC(pwValue);
}

/*!
 * @brief This API reads the voltage from external pin.
 *
 * @note  This API must be called only after the \ref GPADC_ExtPin_Init() API.
 *
 * @param  *milliVolt : Voltage read from the ADC. Only valid if return value is \ref kStatus_PN_Success.
 *
 * @retval  kStatus_PN_Success:  GPADC One Shot mode is executed successfully and read data is stored in the parameter.
 * @retval  Other values Indicates an error occured. Please refer to \ref pn_status_t enum.
 */
pn_status_t GPADC_ExtPin_Read(int32_t *milliVolt);

/*!
 * @brief   This API will return the status of whether the MUX is enabled for measuring the
 *          external ADC pin.
 *
 * @retval  true Indicates that MUX is enabled to measure the voltage on external pin.
 * @retval  false Indicates that MUX is disabled to measure the voltage on external pin.
 */
static inline bool GPADC_ExtPin_GetEnableStatus(void)
{
    return (PN76_Sys_PCRM_Get_EnableStatus_ExtAnalog_ADC() != 0U);
}

/*!
 * @brief Regsiter GPADC IRQ callback.
 *
 * @param sensor Which sensor to register.
 * @param callback The callback to register.
 * @retval kStatus_PN_Success Register succeed.
 * @retval kStatus_PN_InternalError Register failed because of internal error.
 * @retval kStatus_PN_ParameterError Register failed because of wrong parameter.
 */
pn_status_t GPADC_RegisterCallback(gpadc_sensor_t sensor, gpadc_callback_t callback);

/*!
 * @brief Function to handle the GPADC IRQ.
 */
void GPADC_HandleIRQ(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_GPADC_H_ */
