/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpadc.h"
#include "Pcrm_Lp_Reg.h"
#include "PN76_Reg_Interface.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_gpadc"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define GPADC_CH_NUM 8U /* Totally 8 channels. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static const uint8_t s_gpadcChIntFlagPos[GPADC_CH_NUM] = {
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_0_IRQ_STATUS_POS, /* CH 0 */
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_1_IRQ_STATUS_POS, /* CH 1 */
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_2_IRQ_STATUS_POS, /* CH 2 */
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_3_IRQ_STATUS_POS, /* CH 3 */
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_4_IRQ_STATUS_POS, /* CH 4 */
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_5_IRQ_STATUS_POS, /* CH 5 */
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_6_IRQ_STATUS_POS, /* CH 6 */
    (uint8_t)PCRM_INT_STATUS_ADC_DATA_7_IRQ_STATUS_POS, /* CH 7 */
};

static const struct
{
    gpadc_sensor_t sensor;
    uint8_t ch;
} s_gpadcSensorMap[] = {
    {kGPADC_SensorReserved, 2},    /* Reserved sensor */
    {kGPADC_SensorRSSI, 1},        /* RX RSSI output sense */
    {kGPADC_SensorBandgap, 7},     /* Trimmed Bandgap 0.9V */
    {kGPADC_SensorTempPmu, 4},     /* Temperature sense PMU (in Celcius degrees) */
    {kGPADC_SensorTempClif, 5},    /* Temperature sense CLIF */
    {kGPADC_SensorVBAT_ExtPin, 6}, /* Battery voltage (in mV) */
    {kGPADC_SensorVDDPA, 3},       /* VDDPA voltage  */
};

static gpadc_callback_t s_gpadcChCallback[GPADC_CH_NUM] = {NULL};

/*******************************************************************************
 * Code
 ******************************************************************************/

/*
 * @brief This function returns the requested sensor value.
 *
 * This API reads the requested sensor value based on the value type.
 *
 * @note   If the MUX is enabled for measuring the external pin value (\ref GPADC_ExtPin_GetEnableStatus()),
 *         then this function returns the external pin voltage, but not VBAT voltage, when \ref eSensor
 *         is \ref kGPADC_SensorVBAT_ExtPin.
 *
 * @param  eSensor: Sensor used to get General Purpose Analog to Digital Converter (GPADC) value.
 * @param  eType: Type of acquisition (either gross value or real scale value).
 * @param  *milliVolt: Voltage.
 *
 * @retval  kStatus_PN_Success On Success.
 * @retval  kStatus_PN_InternalError On wrong sensor acquisition request.
 */
pn_status_t GPADC_ReadSensor(gpadc_sensor_t eSensor, gpadc_value_type_t eType, int32_t *milliVolt)
{
    int16_t dwRawData;
    PN76_Status_t estatus = PN76_STATUS_SUCCESS;
    uint8_t bIsADCEnabled, bIsGpadcEnabled;

    bIsGpadcEnabled = PN76_Sys_Hal_PCRM_Is_Gpadc_Enabled();
    bIsADCEnabled   = PN76_Sys_PCRM_Get_EnableStatus_ExtAnalog_ADC();
    if (bIsGpadcEnabled == 0x01U)
    {
        if ((bIsADCEnabled == 0x01U) && (eSensor == kGPADC_SensorVBAT_ExtPin))
        {
            estatus    = PN76_Sys_PCRM_Read_OneShot_ExtAnalog_ADC(&dwRawData);
            *milliVolt = ((((int32_t)dwRawData)*1800) / 1023);
        }
        else
        {
            estatus    = PN76_Sys_Hal_PCRM_GpadcGetValue((PN76_PCRM_GpadcSensor_t)eSensor,
                                                      (PN76_PCRM_GpadcValueType_t)eType, &dwRawData);
            *milliVolt = dwRawData;
        }
    }
    else
    {
        estatus = PN76_STATUS_GPADC_ERROR;
    }

    return (pn_status_t)estatus;
}

/*
 * @brief This function returns the instant value of requested sensor.
 *
 * This API reads the sensor once and returns the value.(if required).
 *
 * @note   If the MUX is enabled for measuring the external pin value (\ref GPADC_ExtPin_GetEnableStatus()),
 *         then this function returns the external pin voltage, but not VBAT voltage, when \ref eSensor
 *         is \ref kGPADC_SensorVBAT_ExtPin.
 *
 * @param  eSensor: Sensor used to get General Purpose Analog to Digital Converter (GPADC) value.
 * @param  eType: Type of acquisition (either gross value or real scale value).
 * @param  *milliVolt: Voltage.
 *
 * @retval  kStatus_PN_Success On Success.
 * @retval  kStatus_PN_InternalError on wrong sensor acquisition request.
 */
pn_status_t GPADC_ReadSensorOneShot(gpadc_sensor_t eSensor, gpadc_value_type_t eType, int32_t *milliVolt)
{
    int16_t dwRawData;
    PN76_Status_t estatus = PN76_STATUS_SUCCESS;
    uint8_t bIsADCEnabled, bIsGpadcEnabled;

    bIsGpadcEnabled = PN76_Sys_Hal_PCRM_Is_Gpadc_Enabled();
    bIsADCEnabled   = PN76_Sys_PCRM_Get_EnableStatus_ExtAnalog_ADC();

    if (bIsGpadcEnabled == 0x01U)
    {
        if ((bIsADCEnabled == 0x01U) && (eSensor == kGPADC_SensorVBAT_ExtPin))
        {
            estatus = PN76_Sys_PCRM_Read_OneShot_ExtAnalog_ADC(&dwRawData);
            *milliVolt = (((int32_t)(dwRawData)*1800) / 1023);
        }
        else
        {
            estatus    = PN76_Sys_Hal_PCRM_GpadcGetValueOneShot((PN76_PCRM_GpadcSensor_t)eSensor,
                                                             (PN76_PCRM_GpadcValueType_t)eType, &dwRawData);
            *milliVolt = dwRawData;
        }
    }
    else
    {
        estatus = PN76_STATUS_GPADC_ERROR;
    }

    return (pn_status_t)estatus;
}

/*
 * @brief This API reads the voltage from external pin.
 *
 * @note  This API must be called only after the \ref GPADC_ExtPin_Init() API.
 *
 * @param  *milliVolt : Voltage read from the ADC. Only valid if return value is \ref kStatus_PN_Success.
 *
 * @retval  kStatus_PN_Success:  GPADC One Shot mode is executed successfully and read data is stored in the parameter.
 * @retval  Other values Indicates an error occured. Please refer to \ref pn_status_t enum.
 */
pn_status_t GPADC_ExtPin_Read(int32_t *milliVolt)
{
    int16_t dwRawData;
    pn_status_t estatus;
    uint8_t bIsADCEnabled;

    bIsADCEnabled = PN76_Sys_PCRM_Get_EnableStatus_ExtAnalog_ADC();
    estatus       = GPADC_ExtPin_ReadRawData(&dwRawData);

    if ((estatus == kStatus_PN_Success) && (0U != bIsADCEnabled))
    {
        *milliVolt = ((((int32_t)dwRawData)*1800) / 1023);
    }
    else
    {
        *milliVolt = 0;
    }

    return estatus;
}

/* Function to handle the GPADC IRQ. */
pn_status_t GPADC_RegisterCallback(gpadc_sensor_t sensor, gpadc_callback_t callback)
{
    uint8_t i;
    pn_status_t pnStatus;

    for (i = 0; i < ARRAY_SIZE(s_gpadcSensorMap); i++)
    {
        if (s_gpadcSensorMap[i].sensor == sensor)
        {
            break;
        }
    }

    if (i < ARRAY_SIZE(s_gpadcSensorMap))
    {
        if (s_gpadcSensorMap[i].ch < GPADC_CH_NUM)
        {
            s_gpadcChCallback[s_gpadcSensorMap[i].ch] = callback;
            pnStatus                                  = kStatus_PN_Success;
        }
        else
        {
            pnStatus = kStatus_PN_InternalError;
        }
    }
    else
    {
        pnStatus = kStatus_PN_ParameterError;
    }

    return pnStatus;
}

/* Function to handle the GPADC IRQ. */
void GPADC_HandleIRQ(void)
{
    uint8_t i;
    uint32_t intFlag;
    uint32_t dwIrqStatus = PN76_Sys_ReadRegister(PCRM_INT_STATUS);

    for (i = 0U; i < GPADC_CH_NUM; i++)
    {
        intFlag = 1UL << s_gpadcChIntFlagPos[i];

        if (0UL != (intFlag & dwIrqStatus))
        {
            (void)PN76_Sys_WriteRegister(PCRM_INT_CLR_STATUS, intFlag);

            if (NULL != s_gpadcChCallback[i])
            {
                s_gpadcChCallback[i]();
            }
        }
    }
}
