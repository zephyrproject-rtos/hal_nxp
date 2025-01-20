/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ADC_H_
#define FSL_ADC_H_

#include "fsl_common.h"

/*!
 * @defgroup adc16 ADC16:Combinational logic inputs Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc, each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc, for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief ADC16 driver version. */
#define FSL_ADC16_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup adc16_driver_log The Driver Change Log
 * @ingroup ADC16
 * @{
 * The current ADC16 driver version is 2.0.0.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introducation of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup adc16_intro ADC16 Peripheral and Driver Overview
 * @ingroup adc16
 * @brief Content including 1) features; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features and how this peripheral works
 * =================================================
 *   Analog-to-Digital Converter function
 *
 *   For the chip-specific implementation details of this module's instances see the chip configuration
 *   information.The 16-bit analog-to-digital converter (ADC) is a successive approximation ADC designed
 *   for operation within an integrated microcontroller system-on-chip.For the chip specific modes of
 *   operation, see the power management information of the device.
 *
 * Features
 * ========
 * + Supports up to 24 single-ended analog inputs channels.
 *   - A single-ended input is selected for conversion through the channel select bits,
 *     with their own Sample/Hold unit and converter.
 *
 * + Supports long sample and short sample.(There is an additional 2-cycle adder on any conversion.)
 *   - For long sample,This allows higher impedance inputs to be accurately sampled or to maximize
 *     conversion speed for lower impedance inputs.Longer sample times can also be used to lower
 *     overall power consumption when continuous conversions are enabled if high conversion rates
 *     are not required.Default long sample time 20 extra ADCK cycles;24 ADCK cycles total.
 *   - For short sample,if not need to accurately sample higher impedance inputs.
 *     After the module becomes active, sampling of the input begins.
 *     1. select between sample times based on the conversion mode that is selected.
 *     2. When sampling is completed, the converter is isolated from the input channel and a
 *        successive approximation algorithm is applied to determine the digital value of the analog signal.
 *     3. The result of the conversion is transferred to Rn upon completion of the conversion algorithm.
 *
 * + Supports single or continuous conversion.
 *   - If hardawre average and software enanle,If continuous conversions are also enabled,
 *     a new set of conversions to be averaged are initiated following the last of the
 *     selected number of conversions.
 *
 * + Support power configuration and high-speed conversion.
 *   - Power mode
 *     1.normal power
 *     2.low-power mode
 *       For low-power,the power is reduced at the expense of maximum clock speed.Stop mode is a
 *       low-power consumption Standby mode during which most or all clock sources on the MCU are
 *       disabled.All module registers contain their reset values following exit from Low-Power Stop mode.
 *       Therefore,the module must be re-enabled and re-configured following exit from Low-Power Stop mode.
 *   - Conversion rate
 *     1.high-speed conversion
 *       Nedd 2 additional ADCK cycles to total conversion time.
 *
 * + Support auto Calibration.
 *   The ADC contains a self-calibration function that is required to achieve the specified accuracy.
 *   Calibration must be run, or valid calibration values written, after any reset andbefore a conversion
 *   is initiated.The calibration function sets the offset calibration value and the plus-side calibration
 *   values.The offset calibration value is automatically stored in the ADC offset correction register and
 *   the plus-side calibration values are automatically stored in the ADC plus-side calibration registers.
 *   The user must configure the ADC correctly prior to calibration, and must generate the plus-side gain
 *   calibration results and store them in the ADC plus-side gain register after the calibration function
 *   completes.Prior to calibration, the user must configure the ADC's clock source and frequency, low power
 *   configuration,voltage reference selection, sample time, and high speed configuration according to the
 *   application's clock source availability and needs. If the application uses the ADC in a wide variety
 *   of configurations, the configuration for which the highest accuracy is required should be selected,
 *   or multiple calibrations can be done for the different configurations.For best calibration results:
 *   Set hardware averaging to maximum.
 *
 * + support selectable asynchronous hardware conversion trigger.
 *   The ADC module has a selectable asynchronous hardware conversion trigger, ADHWT, when hardware conversion
 *   enable,ADHWTSn, has occurred. This source is not available on all MCUs. See the Chip Configuration chapter
 *   for information on the ADHWT source and the ADHWTSn configurations specific to this MCU. When an ADHWT
 *   source is available and hardware trigger is enabled, that is when hardware conversion enable, a conversion
 *   is initiated on the rising-edge of ADHWT after a hardware trigger select event, that is, ADHWTSn, has
 *   occurred. If a conversion is in progress when a rising-edge of a trigger occurs, the rising-edge is
 *   ignored. In continuous convert configuration, only the initial rising-edge to launch continuous conversions
 *   is observed, and until conversion is aborted, the ADC continues to do conversions on the same SCn register
 *   that initiated the conversion.
 *
 * + support different clock operation the mcu.
 *   For example,Asynchronous clock (ADACK): This clock is generated from a clock source within the ADC module.
 *   When the ADACK clock source is selected, it is not required to be active prior to conversion start.When
 *   it is selected and it is not active prior to a conversion start , ADACK is activated at the start of a
 *   conversion and deactivated when conversions are terminated. In this case, there is an associated clock
 *   startup delay each time the clock source is re-activated. To avoid the conversion times variability and
 *   latency associated with the ADACK clock startup, enable Asynchronous Clock and wait the worst-case startup
 *   time of 5 μs prior to initiating any conversions using the ADACK clock source. Conversions are possible
 *   using ADACK as the input clock source while the MCU is in Normal Stop mode.See Power Control for more
 *   information.
 *
 * + Supports DMA.
 *   - DMA trigger source can be selected as trigger from end of scan interrupt or sample slot result ready bit.
 *   - Each converter can generate DMA trigger signal.
 *
 * + Supports Interrupts.
 *   - Conversion complete interrupt
 *
 *
 * How does this peripheral work
 * =============================
 *   Before the ADC16 module can be used to complete conversions, an initialization procedure
 *   must be performed. A typical sequence is:
 *   1. Get ADC16 default Configuration.
 *   2. Update select the input clock source and the divide ratio used to generate
 *      ADCK. This register is also used for selecting sample time and low-power configuration.
 *   3. Update select the conversion trigger, hardware or software, and compare
 *      function options, if enabled.
 *   4. Update select whether conversions will be continuous or completed only once
 *      and whether to perform hardware averaging.
 *   5. Update registers to enable or disable conversion complete interrupts.
 *      Also, select the input channel which can be used to perform conversions.
 *   6. Initialization ADC16 Configuration,Calibrate the ADC by following the
 *      calibration instructions in Calibration function.
 *   7. Turn on the ADC16 conversion.
 *
 *
 * How this driver is designed to make this peripheral works
 * =========================================================
 *   The adc16 driver provides a structure @ref adc16_config_t, which contains the main options of the adc16 function.
 *   The ADC16_Init() function uses @ref adc16_config_t type parameters, this function can be used for configuration
 *   In addition to clock selection, frequency setting, sampling time, trigger mode, interrupt enable, DAM enable,
 *   hardware trigger configuration, the main features of the ADC16 module.After the ADC16_Init() function is called
 *   when the relevant converter is powered on,exist The software starts or is triggered by the hardware, and starts
 *   according to the configured options.
 *
 *   + Initialization and deinitialization Interfaces. The APIs in the function group can be used to initialize or
 *     de-initialize the adc16 module.
 *   + Trigger control interface. The API in this function group can be used to configure the trigger mode, with
 *     hardware trigger and software trigger.
 *   + DMA Control Interfaces. The APIs in this function group can be used to set DMA features. Such as select DMA
 *     trigger source, enable/disable DMA.
 *   + Interrupt Control Interfaces. The APIs in this function group can be used to enable/disable interrupts.
 *
 * How to use this driver
 * ======================
 *   + Sets the ADC16 resources by invoking ADC16_Init()
 *     - Defines the variable in type of @ref adc16_config_t.
 *     - [Optional] Invokes ADC16_GetDefaultConfig() function with the pointer of variable which is type of
 *       @ref adc16_config_t to get the default options.
 *     - Sets the member of the variable which is in type of @ref adc16_config_t.
 *       Listed below are some members that must be configured to implement ADC16.
 *       -eReferenceVoltageSource: Used to select the reference voltage source, For external pins pair of VrefH and
 *                                 VrefL,this member defaults to @ref kADC16_ReferenceVoltageSourceVref
 *       - eConversionTrigger: Used to set the trigger mode of the converter trigger
 *                             E.g. If the user wants to set the trigger mode to software trigger mode. This member
 *                             Can be set to @ref kADC16_SoftWareTrigger.
 *       -eChannelInput: Used to set the input channel of the corresponding configuration, the default configuration
 *                       of This member can be set to @ref kADC16_ModuleDisabled.
 *       -u32GroupId:  Used to select the group registers.At any point,for example,the u32GroupId 0 is for Group A
 *                     registers. The u32GroupId 0 is used for both software and hardware trigger modes.
 *     - Invokes ADC16_Init() function to set ADC16 resources.
 *
 * Typical Use Case
 * ================
 *   This function initializes the converter configuration structure with available settings.
 *   The default values are as follows.
 *
 *   1. ADC16_polling initialize
 *   @code
 *     adc16_config_t adc16ConfigStruct;
 *     ADC16_GetDefaultConfig(base,&adc16ConfigStruct);
 *     adc16ConfigStruct.eReferenceVoltageSource                 = kADC16_ReferenceVoltageSourceVref;
 *     adc16ConfigStruct.eChannelInput                           = kADC16_Input17Channel;
 *     adc16ConfigStruct.u32GroupId                              = 0U;
 *     adc16ConfigStruct.bEnableInterruptOnConversionCompleted   = false;
 *     ADC16_Init(base,&adc16ConfigStruct);
 *   @endcode
 *
 *   2. ADC16_interrupt initialize
 *   @code
 *     adc16_config_t adc16ConfigStruct;
 *     ADC16_GetDefaultConfig(base,&adc16ConfigStruct);
 *     adc16ConfigStruct->eReferenceVoltageSource                 = kADC16_ReferenceVoltageSourceVref;
 *     adc16ConfigStruct->eChannelInput                           = kADC16_Input17Channel;
 *     adc16ConfigStruct->u32GroupId                              = 0U;
 *     adc16ConfigStruct.bEnableInterruptOnConversionCompleted    = true;
 *   @endcode
 *
 *   3. ADC16_continuous_dma initialize
 *   In this type of use case. Note the continuous mode must be selected,turn on the dma.If the application wants to use
 *   interrupt, please remember to enable related interrupts.The prototype of this type of use case is shown below.
 *   @code
 *      adc16_config_t adcUserConfig;
 *      ADC16_GetDefaultConfig(&adcUserConfig);
 *      adcUserConfig.eResolution                           = kADC16_Resolution16bit;
 *      adcUserConfig.bEnableContinuousConversion           = true;
 *      adcUserConfig.eClockSource                          = kADC16_ClockSourceAlt1;
 *      adcUserConfig.eSampleMode                           = kADC16_SampleCycle24;
 *      adcUserConfig.bEnableLowPower                       = true;
 *      adcUserConfig.eChannelInput                         = kADC16_Input17Channel;
 *      adcUserConfig.u32GroupId                            = 0U;
 *      adcUserConfig.bEnableInterruptOnConversionCompleted = false;
 *      adcUserConfig.bEnableDMA                            = true;
 *   @endcode
 *
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief The enumeration all of ADC16 Input channels. */
typedef enum _adc16_input_channel
{
    kADC16_Input0Channel  = 0U,  /*!< AD0 is selected as input*/
    kADC16_Input1Channel  = 1U,  /*!< AD1 is selected as input*/
    kADC16_Input2Channel  = 2U,  /*!< AD2 is selected as input*/
    kADC16_Input3Channel  = 3U,  /*!< AD3 is selected as input*/
    kADC16_Input4Channel  = 4U,  /*!< AD4 is selected as input*/
    kADC16_Input5Channel  = 5U,  /*!< AD5 is selected as input*/
    kADC16_Input6Channel  = 6U,  /*!< AD6 is selected as input*/
    kADC16_Input7Channel  = 7U,  /*!< AD7 is selected as input*/
    kADC16_Input8Channel  = 8U,  /*!< AD8 is selected as input*/
    kADC16_Input9Channel  = 9U,  /*!< AD9 is selected as input*/
    kADC16_Input10Channel = 10U, /*!< AD10 is selected as input*/
    kADC16_Input11Channel = 11U, /*!< AD11 is selected as input*/
    kADC16_Input12Channel = 12U, /*!< AD12 is selected as input*/
    kADC16_Input13Channel = 13U, /*!< AD13 is selected as input*/
    kADC16_Input14Channel = 14U, /*!< AD14 is selected as input*/
    kADC16_Input15Channel = 15U, /*!< AD15 is selected as input*/
    kADC16_Input16Channel = 16U, /*!< AD16 is selected as input*/
    kADC16_Input17Channel = 17U, /*!< AD17 is selected as input*/
    kADC16_Input18Channel = 18U, /*!< AD18 is selected as input*/
    kADC16_Input19Channel = 19U, /*!< AD19 is selected as input*/
    kADC16_Input20Channel = 20U, /*!< AD20 is selected as input*/
    kADC16_Input21Channel = 21U, /*!< AD21 is selected as input*/
    kADC16_Input22Channel = 22U, /*!< AD22 is selected as input*/
    kADC16_Input23Channel = 23U, /*!< AD23 is selected as input*/
    kADC16_Reserved1      = 24U, /*!< Reserved */
    kADC16_Reserved2      = 25U, /*!< Reserved */
    kADC16_TempSensor     = 26U, /*!< Temp Sensor (single-ended) is selected as input*/
    kADC16_ABandgap       = 27U, /*!< ABandgap (single-ended) is selected as input*/
    kADC16_Reserved3      = 28U, /*!< Reserved */
    kADC16_VREFSH         = 29U, /*!< High reference voltage is selected as input*/
    kADC16_VREFSL         = 30U, /*!< Low reference voltage is selected as input*/
    kADC16_ModuleDisabled = 31U, /*!< Module is disabled*/
} adc16_input_channel_t;

/*! @brief The enumeration ADC16 clock divider. */
typedef enum _adc16_clock_divider
{
    kADC16_ClockDivider1 = 0U, /*!< For divider 1 from the input clock to the module. */
    kADC16_ClockDivider2 = 1U, /*!< For divider 2 from the input clock to the module. */
    kADC16_ClockDivider4 = 2U, /*!< For divider 4 from the input clock to the module. */
    kADC16_ClockDivider8 = 3U, /*!< For divider 8 from the input clock to the module. */
} adc16_clock_divider_t;

/*! @brief The enumeration ADC16 Conversion resolution mode. */
typedef enum _adc16_resolution
{
    kADC16_Resolution8bit  = 0U, /*!< single-ended 8-bit conversion */
    kADC16_Resolution12bit = 1U, /*!< single-ended 12-bit conversion */
    kADC16_Resolution10bit = 2U, /*!< single-ended 10-bit conversion */
    kADC16_Resolution16bit = 3U, /*!< single-ended 16-bit conversion */
} adc16_resolution_t;

/*! @brief  The enumeration of ADC16 clock source. */
typedef enum _adc16_clock_source
{
    kADC16_ClockSourceAlt0 = 0U, /*!< Selection Bus clock. */
    kADC16_ClockSourceAlt1 = 1U, /*!< Selection (Bus clock)/2. */
    kADC16_ClockSourceAlt2 = 2U, /*!< Selection Alternate clock (ALTCLK). */
    kADC16_ClockSourceAlt3 = 3U, /*!< Selection Asynchronous clock (ADACK). */

    /* Chip defined clock source */
    kADC16_ClockSourceAsynchronousClock = kADC16_ClockSourceAlt3, /*!< Using internal asynchronous clock. */
} adc16_clock_source_t;

/*! @brief The enumeration of ADC16 sample mode. */
typedef enum _adc16_sample_mode
{
    kADC16_SampleCycle24  = 0U, /*!< 20 extra ADCK cycles, 24 ADCK cycles total. */
    kADC16_SampleCycle16  = 1U, /*!< 12 extra ADCK cycles, 16 ADCK cycles total. */
    kADC16_SampleCycle10  = 2U, /*!< 6 extra ADCK cycles, 10 ADCK cycles total. */
    kADC16_SampleCycle6   = 3U, /*!< 2 extra ADCK cycles, 6 ADCK cycles total. */
    kADC16_SampleDisabled = 4U, /*!< Disable the sample feature. */
} adc16_sample_mode_t;

/*! @brief The enumeration ADC16 Automatic compare mode. */
typedef enum _adc16_compare_mode
{
    kADC16_LessThanThreshold               = 0U, /*!< Less than threshold */
    kADC16_GreaterThanOrEqualThreshold     = 1U, /*!< Greater than or equal to threshold */
    kADC16_TriggerOutsideCompareRangeMode1 = 2U, /*!<  Compare true if the result is less than CV1
                                                    Or the result is greater than CV2. */
    kADC16_TriggerInsideCompareRangeMode1 = 3U,  /*!< Compare true if the result is less than CV1
                                                    And the result is greater than CV2. */
    kADC16_TriggerInsideCompareRangeMode2 = 4U,  /*!< Compare true if the result is greater than or
                                                    equal to CV1 And the result is less than or
                                                    equal to CV2. */
    kADC16_TriggerOutsideCompareRangeMode2 = 5U, /*!< Compare true if the result is greater than or
                                                    equal to CV1 Or the result is less than or
                                                    equal to CV2. */
} adc16_compare_mode;

/*! @brief The enumeration ADC16 Reference voltage source. */
typedef enum _adc16_reference_voltage_source
{
    kADC16_ReferenceVoltageSourceVref    = 0U, /*!< For external pins pair of VrefH and VrefL. */
    kADC16_ReferenceVoltageSourceValt    = 1U, /*!< For alternate reference pair of ValtH and ValtL. */
    kADC16_ReferenceVoltageSourceBandgap = 2U, /*!< For bandgap voltage from V BGH and V BGL. */
} adc16_reference_voltage_source_t;

/*! @brief The enumeration ADC16's Hardware average mode. */
typedef enum _adc16_hardware_average_mode
{
    kADC16_HardwareAverageCount4   = 0U, /*!< For hardware average with 4 samples. */
    kADC16_HardwareAverageCount8   = 1U, /*!< For hardware average with 8 samples. */
    kADC16_HardwareAverageCount16  = 2U, /*!< For hardware average with 16 samples. */
    kADC16_HardwareAverageCount32  = 3U, /*!< For hardware average with 32 samples. */
    kADC16_HardwareAverageDisabled = 4U, /*!< Disable the hardware average feature.*/
} adc16_hardware_average_mode_t;

/*! @brief The enumeration ADC16’s conversion trigger source. */
typedef enum _adc16_trigger_source
{
    kADC16_SoftWareTrigger = 0U, /*!< Software trigger Conversion*/
    kADC16_HardWareTrigger = 1U, /*!< Hardware trigger Conversion*/
} adc16_trigger_source_t;

/*! @brief The structure for configuration the ADC16's hardware compare setting. */
typedef struct _adc16_hardware_compare
{
    adc16_compare_mode eCompareMode; /*!< Select the compare mode.
                                             See @ref adc16_compare_mode. */
    int16_t i16Value1;               /*!< Setting i16Value1 for hardware compare mode. */
    int16_t i16Value2;               /*!< Setting i16Value2 for hardware compare mode. */
} adc16_hardware_compare_t;

/*! @brief The structure for configuration the ADC16's setting. */
typedef struct _adc16_config
{
    adc16_reference_voltage_source_t eReferenceVoltageSource : 2; /*!< Select the reference voltage source. */
    adc16_clock_source_t eClockSource : 3;                        /*!< Select the input clock source to converter. */
    bool bEnableAsynchronousClock : 1;                            /*!< Enable the asynchronous clock output. */
    adc16_clock_divider_t eClockDivider : 3;                      /*!< Select the divider of input clock source. */
    adc16_resolution_t eResolution : 3;                           /*!< Select the sample resolution mode. */
    adc16_sample_mode_t eSampleMode;                              /*!< Select the sample mode. */
    bool bEnableHighSpeed : 1;                                    /*!< Enable the high-speed mode. */
    bool bEnableLowPower : 1;                                     /*!< Enable low power. */
    adc16_input_channel_t eChannelInput;                          /*!< Select input channel*/
    uint32_t u32GroupId;                                          /*!< Set group identification,
                                                                        u32GroupId is for Group registers.*/
    bool bEnableInterruptOnConversionCompleted : 1;               /*!< Generate an interrupt request once the
                                                                          conversion is completed.*/
    adc16_trigger_source_t eConversionTrigger : 2;                /*!< Select Conversion Trigger mode. */
    bool bEnableDMA : 1;                                          /*!< Enable adc DMA function*/
    bool bEnableContinuousConversion : 1;                         /*!< Enable continuous conversion mode.*/
    adc16_hardware_average_mode_t eHardwareAverageMode;           /*!< Set hardware average mode. */
    adc16_hardware_compare_t *psHardwareCompare;                  /*!< Set hardware compare mode*/
} adc16_config_t;

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @name Initialization
 * @{
 */

/*!
 * @brief Initializes the ADC16 module.
 *
 * @param base        ADC16 peripheral base address.
 * @param psConfig    Pointer to configuration structure.
 */
void ADC16_Init(SADC_Type *base, const adc16_config_t *psConfig);

/*!
 * @brief Gets an available pre-defined settings for the converter's configuration.
 *
 * This function initializes the converter configuration structure with available settings. The default values are as
 * follows.
 * @code
 *
 *     psConfig->eReferenceVoltageSource                 = kADC16_ReferenceVoltageSourceVref;
 *     psConfig->eClockSource                            = kADC16_ClockSourceAsynchronousClock;
 *     psConfig->bEnableAsynchronousClock                = true;
 *     psConfig->eClockDivider                           = kADC16_ClockDivider8;
 *     psConfig->eResolution                             = KADC16_Resolution12bit;
 *     psConfig->eLongSampleMode                         = kADC16_LongSampleDisabled;
 *     psConfig->bEnableHighSpeed                        = false;
 *     psConfig->bEnableLowPower                         = false;
 *     psConfig->eChannelInput                           = kADC16_ModuleDisabled;
 *     psConfig->u32GroupId                              = 0U;
 *     psConfig->bEnableInterruptOnConversionCompleted   = false;
 *     psConfig->bEnableDMA                              = false;
 *     psConfig->eConversionTrigger                      = kADC16_SoftWareTrigger;
 *     psConfig->eHardwareAverageMode                    = kADC16_HardwareAverageDisabled;
 *     psConfig->bEnableContinuousConversion             = false;
 *     psConfig->psHardwareCompare                       = NULL;
 * @endcode
 *
 * @param psConfig Pointer to the configuration structure. See @ref adc16_config_t.
 */
void ADC16_GetDefaultConfig(adc16_config_t *psConfig);

/*!
 * @brief De-initializes the ADC16 module.
 *
 * @param base ADC16 peripheral base address
 */
void ADC16_Deinit(SADC_Type *base);

/*!
 * @brief  Automates the hardware calibration.
 *
 * This auto calibration helps to adjust the plus/minus side gain automatically.
 * Execute the calibration before using the converter. Note that the hardware trigger
 * should be used during the calibration.
 *
 * @param  base ADC16 peripheral base address.
 *
 * @return                 Execution status.
 * @retval kStatus_Success Calibration is done successfully.
 * @retval kStatus_Fail    Calibration has failed.
 */
status_t ADC16_DoAutoCalibration(SADC_Type *base);

/*!
 * @brief Sets the offset value for the conversion result.
 *
 * This offset value takes effect on the conversion result. If the offset value is not zero, the reading result
 * is subtracted by it. Note, the hardware calibration fills the offset value automatically.
 *
 * @param base       ADC16 peripheral base address.
 * @param i16Value   Setting offset value.
 */
static inline void ADC16_SetOffsetValue(SADC_Type *base, int16_t i16Value)
{
    base->OFS = (uint32_t)(i16Value);
}

/*! @} */

/*!
 * @name Advanced Features
 * @{
 */

/*!
 * @brief Enables assist trigger.
 *
 * This ASSITRGEN register is used to help correctly generate the conversion type. When ASSITRGEN is set,
 * the write to the ADCSC1 COCO bit will be reflected in the ADTRG register, and the operation of ADCSC1
 * will be delayed by 1/2 cycle.When ASSITRGEN is set, the user must ensure that no hardware trigger
 * occurs when writing ADCSC1 COCO,so that the correct conversion type can be generated when the value
 * of the ADTRG register changes.
 *
 * @param base    ADC16 peripheral base address.
 * @param enable  Switcher of the assist trigger feature. "true" means enabled, "false" means not enabled.
 */
static inline void ADC16_EnableAssisTrrigger(SADC_Type *base, bool enable)
{
    if (enable)
    {
        base->SC3 |= SADC_SC3_ASSITRGEN_MASK;
    }
    else
    {
        base->SC3 &= ~SADC_SC3_ASSITRGEN_MASK;
    }
}

/*!
 * @brief Enables generating the DMA trigger when the conversion is complete.
 *
 * @param base   ADC16 peripheral base address.
 * @param enable Switcher of the DMA feature. "true" means enabled, "false" means not enabled.
 */
static inline void ADC16_EnableDMA(SADC_Type *base, bool enable)
{
    if (enable)
    {
        base->SC2 |= SADC_SC2_DMAEN_MASK;
    }
    else
    {
        base->SC2 &= ~SADC_SC2_DMAEN_MASK;
    }
}

/*!
 * @brief Enables the conversion interrupt .
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param base        ADC16 peripheral base address.
 * @param u32GroupId  group identification.
 */
static inline void ADC16_EnableInterrupt(SADC_Type *base, uint32_t u32GroupId)
{
    base->SC1[u32GroupId] |= SADC_SC1_AIEN_MASK;
}

/*!
 * @brief Disables the conversion interrupt .
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param base         ADC16 peripheral base address.
 * @param u32GroupId   group identification.
 */
static inline void ADC16_DisableInterrupt(SADC_Type *base, uint32_t u32GroupId)
{
    base->SC1[u32GroupId] &= ~SADC_SC1_AIEN_MASK;
}

/*!
 * @brief Settings ADC16 trigger mode.
 *
 * @param base            ADC16 peripheral base address.
 * @param eTriggerSource  Setting the trigger conversion mode. See @ref adc16_trigger_source_t.
 */
void ADC16_SetTriggerSource(SADC_Type *base, adc16_trigger_source_t eTriggerSource);

/*!
 * @brief Turns on the ADC16 conversion .
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param base            ADC16 peripheral base address.
 * @param u32GroupId      group identification.
 */
void Adc16_DoSoftwareTrigger(SADC_Type *base, uint32_t u32GroupId);

/*!
 * @brief Aborts the ADC16 conversion.
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param base            ADC16 peripheral base address.
 * @param u32GroupId      group identification.
 */
void Adc16_AbortSoftwareTrigger(SADC_Type *base, uint32_t u32GroupId);

/*!
 * @brief Configures the hardware compare mode.
 *
 * The hardware compare mode provides a way to process the conversion result automatically by using hardware. Only the
 * result in the compare range is available. To compare the range, see "adc16_hardware_compare_mode_t" or the appopriate
 * reference manual for more information.
 *
 * @param base       ADC16 peripheral base address.
 * @param psConfig   Pointer to the "adc16_hardware_compare_config_t" structure. Passing "NULL" disables the feature.
 */
void ADC16_SetHardwareCompareConfig(SADC_Type *base, const adc16_hardware_compare_t *psConfig);

/*!
 * @brief Sets the hardware average mode.
 *
 * The hardware average mode provides a way to process the conversion result automatically by using hardware. The
 * multiple conversion results are accumulated and averaged internally making them easier to read.
 *
 * @param base                  ADC16 peripheral base address.
 * @param eHardwareAverageMode  Setting the hardware average mode. See @ref adc16_hardware_average_mode_t.
 */
void ADC16_SetHardwareAverage(SADC_Type *base, adc16_hardware_average_mode_t eHardwareAverageMode);

/*!
 * @brief  Clears calibration completed flag .
 *
 * @param  base ADC16 peripheral base address.
 */
void ADC16_ClearCalibrationCompletedFlag(SADC_Type *base);

/*! @} */

/*!
 * @name Conversion Channel
 * @{
 */

/*!
 * @brief Configures the conversion Group channel.
 *
 * This operation triggers the conversion when in software trigger mode. When in hardware trigger mode, this API
 * configures the channel while the external trigger source helps to trigger the conversion.
 *
 * @note that the " u32GroupId " has a detailed description. one for each conversion.
 * The u32GroupId parameter indicates which group of registers are used, for example,
 * u32GroupId 0 is for Group A registers. At any point, only one of ,the u32GroupId is actively
 * controlling ADC conversions.The u32GroupId 0 is used for both software and hardware trigger modes.
 * See the chip configuration information in the appropriate MCU reference manual for
 * the number of SC1n registers (u32GroupId) specific to this device. Therefore, writing to these u32GroupId does
 * not initiate a new conversion. Writing any of the u32GroupId registers while that specific u32GroupId
 * is actively controlling a conversion aborts the current conversion.
 *
 * @param base          ADC16 peripheral base address.
 * @param u32GroupId    group identification. u32GroupId is for Group registers.
 * @param eChannel      Setting the conversion channel . See @ref adc16_input_channel_t.
 */
void ADC16_AssginChannelToGroup(SADC_Type *base, uint32_t u32GroupId, adc16_input_channel_t eChannel);

/*!
 * @brief  Gets the group conversion value.
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param  base         ADC16 peripheral base address.
 * @param  u32GroupId   group identification.
 *
 * @return              Conversion value.
 */
static inline uint32_t ADC16_GetGroupConversionValue(SADC_Type *base, uint32_t u32GroupId)
{
    return base->R[u32GroupId];
}

/*!
 * @brief  Checks the status of group conversion
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param  base         ADC16 peripheral base address.
 * @param  u32GroupId   group identification.
 */
bool ADC16_IsGroupConversionCompleted(SADC_Type *base, uint32_t u32GroupId);

/*! @}*/
#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_ADC_H_ */
