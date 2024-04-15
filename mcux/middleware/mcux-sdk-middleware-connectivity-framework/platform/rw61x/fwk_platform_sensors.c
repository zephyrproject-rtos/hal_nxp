/*!
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_clock.h"
#include "fsl_power.h"
#include "fsl_adc.h"

#include "fwk_platform_sensors.h"
#include "fwk_debug.h"

#define ADC_TS_GAIN   6295U /* 6.295f made integer arithmetics */
#define ADC_TS_OFFSET 305U  /* 305.0f */

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/

static bool          adcInitialized = false;
static volatile bool adcDataReady   = false;

/************************************************************************************
*************************************************************************************
* Private functions prototype
*************************************************************************************
************************************************************************************/

void GAU_GPADC0_INT_FUNC11_IRQHandler(void);

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
bool PLATFORM_IsAdcInitialized(void)
{
    return adcInitialized;
}

void PLATFORM_InitAdc(void)
{
    adc_config_t adcConfig;

    CLOCK_AttachClk(kMAIN_CLK_to_GAU_CLK);
    CLOCK_SetClkDiv(kCLOCK_DivGauClk, 4U);
    CLOCK_EnableClock(kCLOCK_Gau);
    RESET_PeripheralReset(kGAU_RST_SHIFT_RSTn);

    POWER_PowerOnGau();

    /*
     *  config->clockDivider = kADC_ClockDivider1;
     *  config->powerMode = kADC_PowerModeFullBiasingCurrent;
     *  config->resolution = kADC_Resolution12Bit;
     *  config->warmupTime = kADC_WarmUpTime16us;
     *  config->vrefSource = kADC_Vref1P2V;
     *  config->inputMode = kADC_InputSingleEnded;
     *  config->conversionMode = kADC_ConversionContinuous;
     *  config->scanLength = kADC_ScanLength_1;
     *  config->averageLength = kADC_AverageNone;
     *  config->triggerSource = kADC_TriggerSourceSoftware;
     *  config->inputGain = kADC_InputGain1;
     *  config->enableInputGainBuffer = false;
     *  config->resultWidth = kADC_ResultWidth16;
     *  config->fifoThreshold = kADC_FifoThresholdData1;
     *  config->enableInputBufferChop = true;
     *  config->enableDMA = false;
     *  config->enableADC = false;
     */
    ADC_GetDefaultConfig(&adcConfig);
    adcConfig.vrefSource            = kADC_Vref1P2V;
    adcConfig.inputMode             = kADC_InputSingleEnded;
    adcConfig.conversionMode        = kADC_ConversionOneShot;
    adcConfig.inputGain             = kADC_InputGain1;
    adcConfig.resolution            = kADC_Resolution16BitAudio;
    adcConfig.fifoThreshold         = kADC_FifoThresholdData1;
    adcConfig.scanLength            = kADC_ScanLength_1;
    adcConfig.averageLength         = kADC_Average16;
    adcConfig.enableInputGainBuffer = true;
    adcConfig.enableInputBufferChop = false;
    adcConfig.enableADC             = true;
    adcConfig.enableChop            = false;

    ADC_Init(GAU_GPADC0, &adcConfig);
    ADC_EnableTemperatureSensor(GAU_GPADC0, true);
    ADC_SetTemperatureSensorMode(GAU_GPADC0, kADC_TSensorInternal);

    if (ADC_DoAutoCalibration(GAU_GPADC0, kADC_CalibrationVrefInternal) != kStatus_Success)
    {
        assert(0);
    }

    ADC_ClearStatusFlags(GAU_GPADC0, (uint32_t)kADC_DataReadyInterruptFlag);
    ADC_SetScanChannel(GAU_GPADC0, kADC_ScanChannel0, kADC_TEMPP);
    ADC_EnableInterrupts(GAU_GPADC0, (uint32_t)kADC_DataReadyInterruptEnable);
    (void)EnableIRQ(GAU_GPADC0_INT_FUNC11_IRQn); /* MISRA CID 23793822 */
    adcInitialized = true;
}

void PLATFORM_DeinitAdc(void)
{
    adcInitialized = false;
}

void PLATFORM_StartBatteryMonitor(void)
{
    __NOP(); /* placeholder for implemetation */
}

void PLATFORM_GetBatteryLevel(uint8_t *battery_level)
{
    *battery_level = 100U;
}

void PLATFORM_StartTemperatureMonitor(void)
{
    ADC_SetScanChannel(GAU_GPADC0, kADC_ScanChannel0, kADC_TEMPP);
    ADC_DoSoftwareTrigger(GAU_GPADC0);
}

void PLATFORM_GetTemperatureValue(int32_t *temperature_value)
{
    uint32_t temperature = 0U;
    uint32_t conversionResult;

    while (adcDataReady == false)
    {
        __NOP();
    }

    conversionResult = ADC_GetConversionResult(GAU_GPADC0);
    conversionResult &= 0x0000ffffU;
    temperature = conversionResult * 1000u / ADC_TS_GAIN;
    temperature -= ADC_TS_OFFSET;

    adcDataReady = false;
    ADC_StopConversion(GAU_GPADC0);

    *temperature_value = (int32_t)temperature;
}

void GAU_GPADC0_INT_FUNC11_IRQHandler(void)
{
    if ((ADC_GetStatusFlags(GAU_GPADC0) & (uint32_t)kADC_DataReadyInterruptFlag) != 0UL)
    {
        adcDataReady = true;
        ADC_ClearStatusFlags(GAU_GPADC0, (uint32_t)kADC_DataReadyInterruptFlag);
    }
}

/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/
