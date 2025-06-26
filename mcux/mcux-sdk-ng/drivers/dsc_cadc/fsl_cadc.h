/*
 * Copyright 2020, 2021, 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CADC_H_
#define FSL_CADC_H_

#include "fsl_common.h"

/*!
 * @defgroup cadc CADC: 12-bit Cyclic Analog-to-Digital Converter Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief CADC driver version. */
#define FSL_CADC_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup cadc_driver_log The Driver Change Log
 * @ingroup cadc
 * @{
 * The current CADC driver version is 2.2.0.
 *
 * - 2.2.0
 *     - New Features
 *         - Supported platforms which don't have ANA4 expansion MUX.
 * - 2.1.0
 *     - Improvements
 *         - Added some APIs to support some devices that equipped expansion mux.
 * - 2.0.1
 *     - Bug Fixes
 *         - Fixed the bug that channel mode set to wrong value.
 *         - Fixed the bug that independent parallel mode set to wrong value.
 *         - Fixed violations of the MISRA C-2012 rules.
 * - 2.0.0
 *     - Initial version.
 * @}
 */

/*******************************************************************************
 * Introducation of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup cadc_intro CADC Peripheral and Driver Overview
 * @ingroup cadc
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 * Peripheral features and how this peripheral works
 * ==================================================
 *  The 12-bit Cyclic Analog-to-Digital converter(CADC) is a dual converter 12-bit ADC in which each ADC converter has
 *  its own voltage reference and control block. The two converters are converterA and converterB.
 *
 *  Features
 *  ---------
 *  + Supports up to 16 analog input channels.
 *      - The total 16 analog input channels are subdivided into two sets of eight(ANA[0:7] and ANB[0:7]), each
 *        with their own Sample/Hold unit and converter
 *      - Support single-end or fully differential inputs(So platform also support unipolar differential inputs).
 *          + Single-end
 *              - The analog input directed to the plus terminal of the A/D core, and the minus terminal of the A/D core
 *                is connected to the Vrefl reference. The ADC measures the voltage of the selected analog input and
 *                compares it against the (Vrefh - Vrefl) reference voltage range.
 *                Calculation formula:
 *                      SingleEndedValue = round(((Vin - Vrefl)/(Vrefh - Vrefl)) * 4096) * 8
 *          + Differential
 *              The ADC measures the voltage difference between two analog inputs and compares that value against the
 *              (Vrefh - Vrefl) voltage range.
 *              - Fully differential
 *                  Fully differential conversions can swing both positive and negative.
 *                  Calculation formula:
 *                      FullyDifferentialValue = round((((Vin1 - Vin2) / (Vrefh - Vrefl)) * 2048) + 2048) * 8
 *              - Unipolar differential(Chip specific)
 *                  Unipolar differential conversions are only positive but uses the full code range of the ADC.
 *                  Calculation formula:
 *                      UnipolarDifferentialValue = round(((Vin1 - Vin2) / (Vrefh - Vrefl)) * 4096) * 8
 *      - For some platforms, some channels can also be alternated as internal signal.
 *
 *  + Supports 16 sample slots basically.(There are 4 additional sample slots for some platforms.)
 *      - Sample slot is a virtual concept to describe ADC scan mode. Normally, in sequential scan mode, ADC converts
 *        the channel assigned to sample slot0 firstly, and then the channel assigned to sample slot 1,..., and finally
 *        the channel assigned to sample slot 15. In parallel scan mode, channels assigned to sample slot 0~7 are
 *        converted in order by converterA; meanwhile, channels assigned to sample slot 8~15 are converted in order by
 *        converterB(The details of scan mode will be provided in the following sections).
 *      - Users need to assign ADC channels to each sample slot. Same channel can be assigned to different sample slots.
 *      - Each sample slot has its own result register, offset register. The offset register value is subtracted from
 *        the converted raw result and stored in its corresponding result register.
 *      - Each sample slot has its own high limit and low limit registers. The converted raw result is compared with
 *        this high and low limits, and store the compare results in high and low limit status registers.
 *      - For each sample slot, zero-crossing of the value in result register can be captured and stored in
 *        zero-crossing status register.
 *
 *  + Consists of two separate ADC converters.
 *      - Dual converters can work sequentially or parallel. When work sequentially, the converterA's control setting
 *        is used to control dual converters. When work parallel, based on executing dual converters independently or
 *        not, the control setting for each converter is different. Please read the simultaneous parallel scan mode and
 *        independent parallel scan mode in the next section for details.
 *      - ConverterA converters sample slot0-7, converterB converters sample slot8-15. (If 4 additional sample slots
 *        exist, sample slot16 and sample slot17 added to converterA, sample slot18 and sample slot19 added to
 *        converterB)
 *
 *  + Supports different scan modes and different scan types.
 *      A scan is the process of stepping through a subset of all sample slots, converting the channel indicated by a
 *      sample slot, and storing the result. This CADC supports 3 scan modes, and each scan mode falls into 3 types
 *      based on how they repeat.
 *      - Scan mode:
 *          1. Sequential scan mode
 *             Upon start or when armed with an enabled SYNC signal, the scan executes all sample slots in order. It
 *             means the scan starts from sample slot0, stops at the first disabled sample slot. If no disabled sample
 *             is encountered, conversion shall be concluded after the last sample slot which is sample
 *             slot 15. If the device also supports additional 4 sample slots, after executing the sample slot 15 the
 *             scan will continue until the first disabled sample slot is encountered or when all 4 additional sample
 *             slots are completed.
 *          2. Simultaneous parallel scan mode
 *             Upon start or when armed with an enabled SYNC signal, the converterA scans from sample slot0 to sample
 *             slot7(if the device supports additional 4 sample slots, sample slot 16 and sample slot17 are added to
 *             end of this sequence) and converter B scans from sample slot8 to sample 15(if the device supports
 *             additional 4 sample slots, sample slot 18 and sample slot19 are added to end of this sequence) at the
 *             same time. The control signal of the scan (E.g. Start signal, Stop signal, Sync signal) is the signal of
 *             converterA. The scans in both converters terminate when either of the converters encounters a disabled
 *             sample slot or the last sample slot.
 *          3. Independent parallel scan mode.
 *             In this scan mode, each converter has independent control setting(E.g. Start signal, Stop signal, Sync
 *             signal). The scan for two converters can be executed independently. Upon start or when armed with an
 *             enabled SYNC signal, the converterA scans from sample slot0 to sample slot7(if the device supports
 *             additional 4 sample slots, sample slot16 and sample slot17 are added to the end of this sequence), the
 *             scan of converterA terminates when either encounters a disabled sample slot or the last sample slot.
 *             Upon start or when armed with an enabled SYNC signal, the converterB scans from sample slot8 to sample
 *             slot15(if the device supports additional 4 sample slots, sample slot18 and sample slot19 are added to
 *             the end of this sequence), the scan of converterB terminates when either encounters a disabled sample
 *             slot or the last sample slot.
 *      - Scan type:
 *          1. Once(Single) scan
 *              In this scan type, the module executes a scan only once each time it is started.
 *          2. Loopig scan
 *              Automatically restarts a scan, as soon as the previous scan completes. If the scan mode is selected as
 *              independent parallel mode, then the converterA scan restarts as soon as the converter A scan sequence
 *              completes and the converter B scan restarts as soon as the converterB scan sequence completes. All
 *              subsequent start and sync pulses are ignored after the scan begins unless the scan is set as "Delay
 *              sample until a new sync input occurs". The scan in this type can only be terminated by setting the STOP
 *              signal.
 *          3. Triggered scan
 *              In this scan type, if external sync is enabled, new scans start at each SYNC pulse that does not
 *              overlap with a current scan in progress.
 *
 *  + Supports DMA.
 *      - DMA trigger source can be selected as trigger from end of scan interrupt or sample slot result ready bit.
 *      - Each converter can generate DMA trigger signal.
 *
 *  + Supports Interrupts.
 *      - Threshold interrupts: High limit interrupt, Low limit interrupt, zero crossing interrupt.
 *      - Conversion complete interrupt
 *      - Scan interrupts which are generated when a sample slot is converted.
 *
 *  + Supports Expansion MUX And Auxilary Control(Chip specification).
 *      - Each ADC includes an 8-input expansion MUXs whose output feeds to ANx4 of each ADC. Two anxilary control
 *        signals(AUXx_SEL0 and AUXx_SEL1) provide the ability to control other peripherals that require to synchronize
 *        with ADC conversion.
 *      - The MUX operates in either the manual selected mode or the scan select mode:
 *          + In the manual select mode, \b MUXSEL0 determines which input channel of MUX is fed to ANx4.
 *          + In the scan select mode, after ANx4 or ANx7 or either one is sampled by ADC, a subsequent selected MUX
 *            channel in scan sequence is enabled. The scan sequence goes from \b MUXSEL0 until the first 'MUX Select
 *            Disable'(Disabled mux slot) is encountered, then the subsequent MUX scan stops. If no 'MUX Select Disable'
 *            is encountered, scan concludes after an expansion MUX channel determined by \b MUXSEL7 is sampled, unless
 *            ADC scan is stopped.
 *
 *  How this peripheral works
 *  -------------------------
 *  1. Connects signals to CADC's input channels pin on the board.
 *  2. Sets the scan mode of the cadc.
 *  3. Assigns the channels to sample slots.
 *  4. Upon a software start or external sync trigger, ADC starts to convert from sample slot 0. The conversion result
 *     of each sample slot is placed into the corresponding result register.
 *  5. The scan shall complete upon a disabled sample slot or otherwise upon the last sample slot.
 *
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 *  The cadc driver provides a structure @ref cadc_config_t which contains major options of cadc features. The
 *  CADC_Init() function takes the argument in type of @ref cadc_config_t, and this function can be used to configure
 *  major features of the CADC module except the high limit value, low limit value, offset value and zero crossing mode
 *  of each sample slots. After Invoking the CADC_Init() function with the related converters being powered up, upon
 *  software starting or being armed by the Sync signal, the scan will start based on the options configured. Based on
 *  the behaviour of the cadc module, the cadc driver also is divided into multiple function groups.
 *
 *  + Initialization and deinitialization Interfaces. The APIs in the function group can be used to initialize or
 *    de-initialize the cadc module.
 *  + Scan related Interfaces. The APIs in this funcion group can be used to configure scan related options, including
 *    scan mode and scan control.
 *  + Channel Control Interfaces. The APIs in this function group can be used to configure channel related options,
 *    including channel mode and channel gain.
 *  + Sample Slot Control Interfaces. The APIs in this function group can be used to configure options of sample slots,
 *    including zero crossing mode, high limit value, low limit value and connected channel. The APIs in this function
 *    group take "eSampleIndex" as the parameter, those APIs are designed to set options for each specific sample slot.
 *  + Converters Control Interfaces. The APIs in this function group can be used to configure converters related
 *    options, such as clock divisor, reference voltage source, converters' power, and so on. All APIs in this function
 *    group take "eConverterId" as the parameter.
 *  + Power Control Interfaces. The APIs in this function group can be used to configure the power options of the cadc
 *    module.
 *  + DMA Control Interfaces. The APIs in this function group can be used to set DMA features. Such as select DMA
 *    trigger source, enable/disable DMA.
 *  + Interrupt Control Interfaces. The APIs in this function group can be used to enable/disable interrupts.
 *  + ADC Status Flag Interfaces. The APIs in this function group can be used to get or clear the status flag of the
 *    cadc module or each sample slot.
 *
 *
 *  How to use this driver
 *  =======================
 *  + Sets the Cyclic ADC resources by invoking CADC_Init()
 *     - Defines the variable in type of @ref cadc_config_t. This variable takes 80 Byte space.
 *     - [Optional] Invokes CADC_GetDefaultConfig() function with the pointer of variable which is type of
 *         @ref cadc_config_t to get the default options.
 *     - Sets the member of the variable which is in type of @ref cadc_config_t.
 *         Some members that must be configured to realize a scan are listed below.
 *         - eScanMode: Used to set the scan mode of the converters scan.
 *                       E.g. If users want to set scan mode as sequential scan mode and only scan one time. This member
 *                           can be set as @ref kCADC_ScanModeOnceSequential.
 *         - uDisabledSampleSlot: Used to set the disabled sample slot in the scan.
 *                                 E.g. If users set the scan mode as once sequential mode and want to scan sample slot
 *                                      0~2 only, this member can be configured as the following code shows.
 *                                      @code
 *                                          {INITSTRUCT_NAME}.uDisabledSampleSlot.eSequentialModeDisSample =
 *                                                                                                kCADC_Sample3Disabled;
 *                                      @endcode
 *         - u32ChannelModeMask: The mask of the channel mode, the default value is all channels are set as single-end
 *                                mode.
 *                                 E.g. If users want to set ANA0 and ANA2 as fully differential mode and ANB0 and ANB1
 *                                     as single-end mode. This member can be set as
 *                                     @code
 *                                          {INITSTRUCT_NAME}.u32ChannelModeMask = kCADC_ANA0_1_FullyDifferential |
 *                                          kCADC_ANA2_3_SingleEnd | kCADC_ANB0_1_SingleEnd;
 *                                     @endcode
 *         - eSampleSlot[]: The channel that is routed to each sample slot.
 *                                       E.g. If the users want to route ANA0 to sample slot0, this member can be set as
 *                                             @code
 *                                                {INITSTRUCT_NAME}.eSampleSlot[0] = kCADC_SingleEndANA0_DiffANA0pANA1n;
 *                                             @endcode
 *         - sConverterA.bPowerUp: Used to power up/down the converterA. When converterA is used, it must be powered up.
 *         - sConverterA.u16ClockDivisor: ConverterA clock divisor for the clock source. The Available setting range is
 *           0-63. When the clockDivisor is 0, the divisor is 2. For all other clockDivisor values,
 *           the divisor is 1 more than the decimal value of clockDivisor: clockDivisor + 1.
 *         - sConverterB.bPowerUp: Used to power up/down the converterB. When converterB is used, it must be powered up.
 *         - sConverterB.u16ClockDivisor: ConverterB clock divisor for the clock source. The Available setting range is
 *           0-63. When the clockDivisor is 0, the divisor is 2. For all other clockDivisor values, the divisor is 1
 *           more than the decimal value of clockDivisor: clockDivisor + 1
 *     - Invokes CADC_Init() function to set CADC resources.
 *  + [Optional] Sets sample slots data process related options
 *     - To set low limit value of sample slots, use the CADC_SetSampleSlotLowLimitValue() function.
 *     - To set the offset value of sample slots, use the CADC_SetSampleSlotOffsetValue() function.
 *     - To set the high limit value of sample slots, use the CADC_SetSampleSlotHighLimitValue() function.
 *     - To set the zero crossing mode of sample slots, use the CADC_SetSampleSlotZeroCrossingMode() function.
 *  + Starts the scan
 *     - Sends start command via CADC_DoSoftwareTriggerConverter() or armed the Sync signal to the specific
 *         converter, if the related converter is powered up, then the scan sequence will start from the converter's
 *         first sample slot and the scan sequence will complete at the disabled sample slot or the last sample slot.
 *  + Gets the conversion result
 *     1. In case of enabled sample slot scan interrupts
 *         The interrupt will be generated when the related sample slot's ready flag is set, in the ISR use
 *         CADC_GetSampleResultValue() to get the result.
 *     2. In case of enabled DMA and the DMA trigger source selected as Sample Ready Trigger
 *         The DMA is triggered when the related sample slot's ready flag is asserted.
 *     3. In case of polling sample slot ready flag.
 *          Use the CADC_GetSampleSlotReadyStatusFlags() to poll the ready status flag. If the specific sample slot's
 *          READY flag is asserted, use CADC_GetSampleResultValue() to get the result.
 *     4. In case of enabled end of scan interupts
 *         The interrupt will be generated when the scan sequence is terminated, in the ISR use
 *          CADC_GetSampleResultValue() to get all converted sample slots' result.
 *
 *  Typical Use Case
 *  ================
 *  1. Dual converters scan sample slots sequentially.
 *      In this type of use case, dual converters use the control setting of converterA. The scan mode must be selected
 *      as sequential mode, so dual converters can be executed sequentially. In this type of use case, do remember to
 *      power up the converter which contains the channels to be sampled. If the application wants to use interrupts,
 *      please remember to enable related interrupts except that @ref kCADC_ConversionCompleteInterrupt1Enable
 *      is useless. After started, the scan will execute from sample slot0 and will stop at the first disabled sample
 *      slot. The prototype of this type of use case is shown below.
 *      @code
            cadc_config_t sCadcConfigStruct;
            CADC_GetDefaultConfig(&sCadcConfigStruct);
            sCadcConfigStruct.u32EnabledInterruptMask = kCADC_ConversionCompleteInterrupt0Enable;
            sCadcConfigStruct.eScanMode                                     = kCADC_ScanModeTriggeredSequential;
            sCadcConfigStruct.uDisabledSampleSlot.eSequentialModeDisSample = kCADC_Sample4Disabled;
            sCadcConfigStruct.u32ChannelModeMask = kCADC_ANA4_5_FullyDifferential | kCADC_ANA6_7_FullyDifferential |
                                                    kCADC_ANB0_1_FullyDifferential | kCADC_ANB2_3_FullyDifferential;
            sCadcConfigStruct.eSampleSlot[0]                 = kCADC_SingleEndANA4_DiffANA4pANA5n;
            sCadcConfigStruct.eSampleSlot[1]                 = kCADC_SingleEndANA6_DiffANA6pANA7n;
            sCadcConfigStruct.eSampleSlot[2]                 = kCADC_SingleEndANB0_DiffANB0pANB1n;
            sCadcConfigStruct.eSampleSlot[3]                 = kCADC_SingleEndANB2_DiffANB2pANB3n;
            sCadcConfigStruct.sConverterA.bPowerUp   = true;
            sCadcConfigStruct.sConverterA.u16ClockDivisor = 4U; (So ConverterA clock = (peripheral clock / 5).)
            sCadcConfigStruct.sConverterB.bPowerUp   = true;
            sCadcConfigStruct.sConverterB.u16ClockDivisor = 4U; (So ConverterB clock = (peripheral clock / 5).)
            CADC_Init(ADC, &sCadcConfigStruct);
        @endcode
 *  2. Dual converters scan sample slots parallel independently.
 *      In this type of use case each converter has its own control setting. The scan mode must be selected as
 *      parallel independent mode, so dual converters can work independently. The converter must be powered up if it
 *      is used to convert sample slots. If the application wants to use interrupt, please remember to enable
 *      interrupts. If converterA is started, the scan of converterA will start from sample slot0 and will stop at the
 *      first disabled sample slot. If converterB is started, the scan of converterB will start from sample slot8 and
 *      will stop at the first disabled sample slot. The prototype of this type of use case is shown below.
 *      @code
            cadc_config_t sCadcConfigStruct;
            CADC_GetDefaultConfig(&sCadcConfigStruct);
            sCadcConfigStruct.u32EnabledInterruptMask = kCADC_ConversionCompleteInterrupt0Enable |
                                                kCADC_ConversionCompleteInterrupt1Enable;
            sCadcConfigStruct.u32ChannelModeMask = kCADC_ANA4_5_FullyDifferential | kCADC_ANA6_7_FullyDifferential |
                                                        kCADC_ANB0_1_FullyDifferential | kCADC_ANB2_3_FullyDifferential;
            sCadcConfigStruct.eScanMode = kCADC_ScanModeTriggeredParallelIndependent;
            sCadcConfigStruct.uDisabledSampleSlot.sIndependentParallelModeDisSample.eConverterA =
                                                            kCADC_convASample2Disabled;
            sCadcConfigStruct.uDisabledSampleSlot.sIndependentParallelModeDisSample.eConverterB =
                                                            kCADC_convBSample10Disabled;
            sCadcConfigStruct.eSampleSlot[0] = kCADC_SingleEndANA4_DiffANA4pANA5n;
            sCadcConfigStruct.eSampleSlot[1] = kCADC_SingleEndANA6_DiffANA6pANA7n;
            sCadcConfigStruct.eSampleSlot[8] = kCADC_SingleEndANB0_DiffANB0pANB1n;
            sCadcConfigStruct.eSampleSlot[9] = kCADC_SingleEndANB2_DiffANB2pANB3n;
            sCadcConfigStruct.sConverterA.bPowerUp   = true;
            sCadcConfigStruct.sConverterA.u16ClockDivisor = 4U; (So ConverterA clock = (peripheral clock / 5).)
            sCadcConfigStruct.sConverterB.bPowerUp   = true;
            sCadcConfigStruct.sConverterB.u16ClockDivisor = 4U; (So ConverterB clock = (peripheral clock / 5).)
            CADC_Init(ADC, &sCadcConfigStruct);
        @endcode
 *  3. Dual converters scan sample slots parallel simultaneously.
 *      In this type of use case, dual converters use the control setting of converterA. The scan mode must be selected
 *      as parallel simultaneous mode, so dual converters can work simultaneously. In this type of use case do power up
 *      both the converters. If the application wants to use interrupt, please remember to enable related
 *      interrupts but please note that @ref kCADC_ConverterBEndOfScanFlag is useless in this type of use case. If
 *      started, the scan of converterA and converterB will start from converters' first sample slot at the same time,
 *      and the scan will stop when any converter encounters the first disabled sample slot. The prototype of this type
 *      of use case is shown below.
 *      @code
            cadc_config_t cadcConfigStruct;
            CADC_GetDefaultConfig(&cadcConfigStruct);
            cadcConfigStruct.u32EnabledInterruptMask = kCADC_ConversionCompleteInterrupt0Enable;
            cadcConfigStruct.eScanMode = kCADC_ScanModeTriggeredParallelSimultaneous;
            cadcConfigStruct.uDisabledSampleSlot.eSimultParallelModeDisSample = kCADC_Sample2_10Disabled;
            cadcConfigStruct.u32ChannelModeMask = kCADC_ANA4_5_FullyDifferential | kCADC_ANA6_7_FullyDifferential |
                                                    kCADC_ANB0_1_FullyDifferential | kCADC_ANB2_3_FullyDifferential;
            cadcConfigStruct.eSampleSlot[0] = kCADC_SingleEndANA4_DiffANA4pANA5n;
            cadcConfigStruct.eSampleSlot[1] = kCADC_SingleEndANA6_DiffANA6pANA7n;
            cadcConfigStruct.eSampleSlot[8] = kCADC_SingleEndANB0_DiffANB0pANB1n;
            cadcConfigStruct.eSampleSlot[9] = kCADC_SingleEndANB2_DiffANB2pANB3n;
            sCadcConfigStruct.sConverterA.bPowerUp   = true;
            sCadcConfigStruct.sConverterA.u16ClockDivisor = 4U; (So ConverterA clock = (peripheral clock / 5).)
            sCadcConfigStruct.sConverterB.bPowerUp   = true;
            sCadcConfigStruct.sConverterB.u16ClockDivisor = 4U; (So ConverterB clock = (peripheral clock / 5).)
            CADC_Init(ADC, &sCadcConfigStruct);
        @endcode
 *  @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Macro for CADC sample slot count. */
#if (defined(ADC_RSLT2_COUNT))
#define CADC_SAMPLE_SLOTS_COUNT (ADC_RSLT_COUNT + ADC_RSLT2_COUNT)
#else
#define CADC_SAMPLE_SLOTS_COUNT (ADC_RSLT_COUNT)
#endif /**/

/*!
 * @brief CADC miscellaneous status flags used to tell peripheral's miscellaneous status, such as zerocrossing, end of
 * scan flags.
 */
enum _cadc_misc_status_flags
{
    kCADC_ZeroCrossingInterruptFlag = ADC_STAT_ZCI_MASK,  /*!< Zero crossing encountered. IRQ pending if
                                                           enabled Zero Crossing Interrupt. */
    kCADC_HighLimitInterruptFlag = ADC_STAT_HLMTI_MASK,   /*!< High limit exceeded flag. IRQ pending if enabled
                                                           high limit interrupt. */
    kCADC_LowLimitInterruptFlag = ADC_STAT_LLMTI_MASK,    /*!< Low limit exceeded flag. IRQ pending if enabled
                                                           low limit interrupt. */
    kCADC_ConverterAInProgressFlag = ADC_STAT_CIP0_MASK,  /*!< Conversion in progress, converter A. */
    kCADC_ConverterBInProgressFlag = ADC_STAT_CIP1_MASK,  /*!< Conversion in progress, converter B. */
    kCADC_ConverterAEndOfScanFlag  = ADC_STAT_EOSI0_MASK, /*!< End of scan, converter A. */
    kCADC_ConverterBEndOfScanFlag  = ADC_STAT_EOSI1_MASK, /*!< End of scan, converter B. */
    kCADC_StatusAllFlags           = kCADC_ZeroCrossingInterruptFlag | kCADC_HighLimitInterruptFlag |
                           kCADC_LowLimitInterruptFlag | kCADC_ConverterAInProgressFlag |
                           kCADC_ConverterBInProgressFlag | kCADC_ConverterAEndOfScanFlag |
                           kCADC_ConverterBEndOfScanFlag,
};

/*!
 * @brief The enumeration of converter power status.
 */
enum _cadc_converter_power_status_flags
{
    kCADC_ConverterAPowerDownFlag = ADC_PWR_PSTS0_MASK, /*!< The converterA is powered down. */
    kCADC_ConverterBPowerDownFlag = ADC_PWR_PSTS1_MASK, /*!< The converterB is powered down. */
};

#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
/*!
 * @brief The enumeration of expansion mux channel scan complete interrupt request status flag.
 */
enum _cadc_expansion_mux_status_flags
{
    kCADC_ANA4ExpMuxAuxScanCompInterruptFlag = ADC_EXPSTAT_MUXAIRQ_MASK, /*!< ANA4 Expansion MUX Channel Scan
                                                                             Complete Interrupt flag. */
    kCADC_ANB4ExpMuxAuxScanCompInterruptFlag = ADC_EXPSTAT_MUXBIRQ_MASK, /*!< ANB4 Expansion MUX Channel Scan
                                                                             Complete Interrupt flag. */
};
#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */

/*!
 * @brief CADC Interrupts enumeration.
 */
enum _cadc_interrupt_enable
{
    kCADC_Sample0ScanInterruptEnable  = 1UL << 0UL,  /*!< If sample0 is converted, generate the scan interrupt. */
    kCADC_Sample1ScanInterruptEnable  = 1UL << 1UL,  /*!< If sample1 is converted, generate the scan interrupt. */
    kCADC_Sample2ScanInterruptEnable  = 1UL << 2UL,  /*!< If sample2 is converted, generate the scan interrupt. */
    kCADC_Sample3ScanInterruptEnable  = 1UL << 3UL,  /*!< If sample3 is converted, generate the scan interrupt. */
    kCADC_Sample4ScanInterruptEnable  = 1UL << 4UL,  /*!< If sample4 is converted, generate the scan interrupt. */
    kCADC_Sample5ScanInterruptEnable  = 1UL << 5UL,  /*!< If sample5 is converted, generate the scan interrupt. */
    kCADC_Sample6ScanInterruptEnable  = 1UL << 6UL,  /*!< If sample6 is converted, generate the scan interrupt. */
    kCADC_Sample7ScanInterruptEnable  = 1UL << 7UL,  /*!< If sample7 is converted, generate the scan interrupt. */
    kCADC_Sample8ScanInterruptEnable  = 1UL << 8UL,  /*!< If sample8 is converted, generate the scan interrupt. */
    kCADC_Sample9ScanInterruptEnable  = 1UL << 9UL,  /*!< If sample9 is converted, generate the scan interrupt. */
    kCADC_Sample10ScanInterruptEnable = 1UL << 10UL, /*!< If sample10 is converted, generate the scan interrupt. */
    kCADC_Sample11ScanInterruptEnable = 1UL << 11UL, /*!< If sample11 is converted, generate the scan interrupt. */
    kCADC_Sample12ScanInterruptEnable = 1UL << 12UL, /*!< If sample12 is converted, generate the scan interrupt. */
    kCADC_Sample13ScanInterruptEnable = 1UL << 13UL, /*!< If sample13 is converted, generate the scan interrupt. */
    kCADC_Sample14ScanInterruptEnable = 1UL << 14UL, /*!< If sample14 is converted, generate the scan interrupt. */
    kCADC_Sample15ScanInterruptEnable = 1UL << 15UL, /*!< If sample15 is converted, generate the scan interrupt. */
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    kCADC_Sample16ScanInterruptEnable = 1UL << 16UL, /*!< If sample16 is converted, generate the scan interrupt. */
    kCADC_Sample17ScanInterruptEnable = 1UL << 17UL, /*!< If sample17 is converted, generate the scan interrupt. */
    kCADC_Sample18ScanInterruptEnable = 1UL << 18UL, /*!< If sample18 is converted, generate the scan interrupt. */
    kCADC_Sample19ScanInterruptEnable = 1UL << 19UL, /*!< If sample19 is converted, generate the scan interrupt. */
#endif                                               /* FSL_FEATURE_CADC_RSLT2_COUNT */
#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
    kCADC_ANA4ExpMuxScanCompleteInterruptEnable = 1UL << 28UL, /*!< If ANA4 expansion MUX channel scan complete,
                                                                   generate the interrupt. */
    kCADC_ANB4ExpMuxScanCompleteInterruptEnable = 1UL << 29UL, /*!< If ANB4 expansion MUX channel scan complete,
                                                                   generate the interrupt. */
#endif /* (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) */

    kCADC_HighLimitInterruptEnable = ((uint32_t)ADC_CTRL1_HLMTIE_MASK << 16UL),  /*!< If the result value
                                                                                         is greater than the high
                                                                                         limit value, generate high
                                                                                         limit interrupt.  */
    kCADC_LowLimitInterruptEnable = ((uint32_t)ADC_CTRL1_LLMTIE_MASK << 16UL),   /*!< If the result value
                                                                                         is less than the low limit
                                                                                         value, generate low limit
                                                                                         interrupt. */
    kCADC_ZeroCrossingInterruptEnable = ((uint32_t)ADC_CTRL1_ZCIE_MASK << 16UL), /*!< If the current value has a sign
                                                                change from  the previous result in the selected zero
                                                                crossing mode, generate the zero crossing mode */

    kCADC_ConversionCompleteInterrupt0Enable = ((uint32_t)ADC_CTRL1_EOSIE0_MASK << 16UL), /*!< Upon the completion of
                                                                              the scan, generate the end of scan
                                                                              interrupt, when the scan mode is selected
                                                                              as sequential mode or simultaneous
                                                                              parallel mode. For looping scan mode, the
                                                                              interrupt will trigger after the
                                                                              completion of each iteration of loop. */
    kCADC_ConversionCompleteInterrupt1Enable = ((uint32_t)ADC_CTRL2_EOSIE1_MASK << 12UL), /*!< When the scan mode is
                                                                              independent parallel mode, up the
                                                                              completion of the converter scan, generate
                                                                              te end of scan interrupt. For looping scan
                                                                              mode, the interrupt will trigger after the
                                                                              completion of each iteration of loop. */
    kCADC_ALLInterruptEnable =
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
        kCADC_Sample16ScanInterruptEnable | kCADC_Sample17ScanInterruptEnable | kCADC_Sample18ScanInterruptEnable |
        kCADC_Sample19ScanInterruptEnable |
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
        kCADC_ANA4ExpMuxScanCompleteInterruptEnable | kCADC_ANB4ExpMuxScanCompleteInterruptEnable |
#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */
        kCADC_Sample0ScanInterruptEnable | kCADC_Sample1ScanInterruptEnable | kCADC_Sample2ScanInterruptEnable |
        kCADC_Sample3ScanInterruptEnable | kCADC_Sample4ScanInterruptEnable | kCADC_Sample5ScanInterruptEnable |
        kCADC_Sample6ScanInterruptEnable | kCADC_Sample7ScanInterruptEnable | kCADC_Sample8ScanInterruptEnable |
        kCADC_Sample9ScanInterruptEnable | kCADC_Sample10ScanInterruptEnable | kCADC_Sample11ScanInterruptEnable |
        kCADC_Sample12ScanInterruptEnable | kCADC_Sample13ScanInterruptEnable | kCADC_Sample14ScanInterruptEnable |
        kCADC_Sample15ScanInterruptEnable | kCADC_HighLimitInterruptEnable | kCADC_LowLimitInterruptEnable |
        kCADC_ZeroCrossingInterruptEnable | kCADC_ConversionCompleteInterrupt0Enable |
        kCADC_ConversionCompleteInterrupt1Enable,
};

/*!
 * @brief CADC Converter identifier.
 */
typedef enum _cadc_converter_id
{
    kCADC_ConverterA = 0x1U, /*!< Converter A. */
    kCADC_ConverterB = 0x2U, /*!< Converter B. */
} cadc_converter_id_t;

/*!
 * @brief The enumeration of work mode when the module is not used.
 */
typedef enum _cadc_idle_work_mode
{
    kCADC_IdleKeepNormal = 0U, /*!< Keep normal. */
#if !(defined(FSL_FEATURE_CADC_NO_AUTO_STANDBY) && FSL_FEATURE_CADC_NO_AUTO_STANDBY)
    kCADC_IdleAutoStandby,   /*!< Fall into standby mode automatically. */
#endif                       /* FSL_FEATURE_CADC_NO_AUTO_STANDBY */
    kCADC_IdleAutoPowerDown, /*!< Fall into power down mode automatically. */
} cadc_idle_work_mode_t;

/*!
 * @brief The enumeration of DMA trigger source.
 */
typedef enum _cadc_dma_trigger_source
{
    kCADC_DMATrigSrcEndofScan   = 0U, /*!< DMA trigger source is end of scan interrupt. */
    kCADC_DMATrigSrcSampleReady = 1U, /*!< DMA trigger source is RDY bits. */
} cadc_dma_trigger_source_t;

/*!
 * @brief The enumeration of dual converter's scan mode.
 */
typedef enum _cadc_scan_mode
{
    kCADC_ScanModeOnceSequential                = 0U,       /*!< Once (single) sequential. */
    kCADC_ScanModeOnceParallelIndependent       = 1U,       /*!< Once parallel independently. */
    kCADC_ScanModeLoopSequential                = 2U,       /*!< Loop sequential. */
    kCADC_ScanModeLoopParallelIndependent       = 3U,       /*!< Loop parallel independently. */
    kCADC_ScanModeTriggeredSequential           = 4U,       /*!< Triggered sequential. */
    kCADC_ScanModeTriggeredParallelIndependent  = 5U,       /*!< Triggered parallel independently. */
    kCADC_ScanModeOnceParallelSimultaneous      = 1U << 4U, /*!< Once parallel simultaneously. */
    kCADC_ScanModeLoopParallelSimultaneous      = 3U << 4U, /*!< Loop parallel simultaneously. */
    kCADC_ScanModeTriggeredParallelSimultaneous = 5U << 4U, /*!< Triggered parallel simultaneously. */
} cadc_scan_mode_t;

#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
/*!
 * @brief The enumeration of the converter's speed mode.
 */
typedef enum _cadc_speed_mode
{
    kCADC_SpeedMode0 = 0U, /*!< ADC conversion speed mode 0. */
    kCADC_SpeedMode1 = 1U, /*!< ADC conversion speed mode 1. */
    kCADC_SpeedMode2 = 2U, /*!< ADC conversion speed mode 2. */
    kCADC_SpeedMode3 = 3U, /*!< ADC conversion speed mode 3. */
} cadc_speed_mode_t;
#endif /*FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */

/*!
 * @brief The enumeration of converter's reference voltage source.
 */
typedef enum _cadc_reference_voltage_source
{
    kCADC_ReferenceVoltageVrefPad    = 0U, /*!< VREF pin. */
    kCADC_ReferenceVoltageChannelPad = 1U, /*!< ANx2 or ANx3 pin. */
} cadc_reference_voltage_source_t;

/*!
 * @brief The enumeration of sample slot connected channel gain.
 */
typedef enum _cadc_channel_gain
{
    kCADC_SignalGainX1 = 0U, /*!< Gain x1. */
    kCADC_SignalGainX2 = 1U, /*!< Gain x2. */
    kCADC_SignalGainX4 = 2U, /*!< Gain x4. */
} cadc_channel_gain_t;

/*!
 * @brief The enumeration of all channels' channel mode.
 */
typedef enum _cadc_channel_mode
{
    /* The following three enumeration members are mutually exclusive */
    kCADC_ANA0_1_SingleEnd         = 1UL << 0UL, /*!< ANA0 and ANA1 both configured as single ended inputs. */
    kCADC_ANA0_1_FullyDifferential = 2UL << 0UL, /*!< ANA0 configured as fully differential positive input,
                                                     ANA1 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANA0_1_UnipolarDifferential = 3UL << 0UL, /*!< ANA0 configured as unipolar differential positive input,
                                                        ANA1 configured as unipolar differential negative input. */
#endif                                              /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */

    /* The following three enumeration members are mutually exclusive */
    kCADC_ANA2_3_SingleEnd         = 1UL << 3UL, /*!< ANA2 and ANA3 both configured as single ended inputs. */
    kCADC_ANA2_3_FullyDifferential = 2UL << 3UL, /*!< ANA2 configured as fully differential positive input,
                                                     ANA3 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANA2_3_UnipolarDifferential = 3UL << 3UL, /*!< ANA2 configured as unipolar differential positive input,
                                                        ANA3 configured as unipolar differential negative input. */
#endif                                              /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */

    /* The following three enumeration members are mutually exclusive */
    kCADC_ANB0_1_SingleEnd         = 1UL << 6UL, /*!< ANB0 and ANB1 both configured as single ended inputs. */
    kCADC_ANB0_1_FullyDifferential = 2UL << 6UL, /*!< ANB0 configured as fully differential positive input,
                                                     ANB1 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANB0_1_UnipolarDifferential = 3UL << 6UL, /*!< ANB0 configured as unipolar differential positive input,
                                                        ANB1 configured as unipolar differential negative input. */
#endif                                              /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */

    /* The following three enumeration members are mutually exclusive */
    kCADC_ANB2_3_SingleEnd         = 1UL << 9UL, /*!< ANB2 and ANB3 both configured as single ended inputs. */
    kCADC_ANB2_3_FullyDifferential = 2UL << 9UL, /*!< ANB2 configured as fully differential positive input,
                                                     ANB3 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANB2_3_UnipolarDifferential = 3UL << 9UL, /*!< ANB2 configured as unipolar differential positive input,
                                                        ANB3 configured as unipolar differential negative input. */
#endif                                              /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */

    /* The following three enumeration members are mutually exclusive */
    kCADC_ANA4_5_SingleEnd         = 1UL << 12UL, /*!< ANA4 and ANA5 both configured as single ended inputs. */
    kCADC_ANA4_5_FullyDifferential = 2UL << 12UL, /*!< ANA4 configured as fully differential positive input,
                                                      ANA5 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANA4_5_UnipolarDifferential = 3UL << 12UL, /*!< ANA4 configured as unipolar differential positive input,
                                                         ANA5 configured as unipolar differential negative input. */
#endif                                               /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */

    /* The following six enumeration members are mutually exclusive */
    kCADC_ANA6_7_SingleEnd         = 1UL << 15UL, /*!< ANA6 and ANA7 both configured as single ended inputs. */
    kCADC_ANA6_7_FullyDifferential = 2UL << 15UL, /*!< ANA6 configured as fully differential positive input,
                                                  ANA7 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANA6_7_UnipolarDifferential = 3UL << 15UL, /*!< ANA6 configured as unipolar differential positive input,
                                                     ANA7 configured as unipolar differential negative input. */
#endif                                               /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_ANA6_InternalTempSensor_ANA7_Normal = 4UL << 15UL,  /*!< ANA6 configured as Internal temperature sensor,
                                                                  ANA7 configured as normal single-end operate mode. */
    kCADC_ANA6_Normal_ANA7_InternalAnalogInput = 5UL << 15UL, /*!< ANA6 configured as normal single-end operate mode,
                                                                  ANA7 configuread as internal analog input */
    kCADC_ANA6_InternalTempSensor_ANA7_InternalAnalogInput = 6UL << 15UL, /*!< ANA6 configured as internal temperature
                                                                    sensor, ANA7 configured as internal analog input. */
#endif                                                                    /* FSL_FEATURE_CADC_RSLT2_COUNT */

    /* The following three enumeration members are mutually exclusive */
    kCADC_ANB4_5_SingleEnd         = 1UL << 18UL, /*!< ANB4 and ANB5 both configured as single ended inputs. */
    kCADC_ANB4_5_FullyDifferential = 2UL << 18UL, /*!< ANB4 configured as fully differential positive input,
                                                  ANB5 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANB4_5_UnipolarDifferential = 3UL << 18UL, /*!< ANB4 configured as unipolar differential positive input,
                                                 ANB5 configured as unipolar differential negative input. */
#endif                                               /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */

    /* The following six enumeration members are mutually exclusive */
    kCADC_ANB6_7_SingleEnd         = 1UL << 21UL, /*!< ANB6 and ANB7 both configured as single ended inputs. */
    kCADC_ANB6_7_FullyDifferential = 2UL << 21UL, /*!< ANB6 configured as fully differential positive input,
                                              ANB7 configured as fully differential negative input. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_ANB6_7_UnipolarDifferential = 3UL << 21UL, /*!< ANB6 configured as unipolar differential positive input,
                                                 ANB7 configured as unipolar differential negative input. */
#endif                                               /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_ANB6_InternalTempSensor_ANB7_Normal = 4UL << 21UL,  /*!< ANB6 configured as internal temperature sensor,
                                                                  ANB7 configured as normal single-end operate mode. */
    kCADC_ANB6_Normal_ANB7_InternalAnalogInput = 5UL << 21UL, /*!< ANB6 configured as normal single-end operate mode,
                                                                  ANB7 configuread as internal analog input */
    kCADC_ANB6_InternalTempSensor_ANB7_InternalAnalogInput = 6UL << 21UL, /*!< ANB6 configured as internal temperature
                                                                    sensor, ANB7 configured as internal analog input. */
#endif                                                                    /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_channel_mode_t;

/*!
 * @brief The enumerator of all channels that can be routed to the specific sample slot.
 */
typedef enum _cadc_channel_number
{
    kCADC_SingleEndANA0_DiffANA0pANA1n = 0U,  /*!< Single Endned ANA0 Signal Or Differential ANA0+, ANA1- signal. */
    kCADC_SingleEndANA1_DiffANA0pANA1n = 1U,  /*!< Single Endned ANA1 Signal Or Differential ANA0+, ANA1- signal. */
    kCADC_SingleEndANA2_DiffANA2pANA3n = 2U,  /*!< Single Endned ANA2 Signal Or Differential ANA2+, ANA3- signal. */
    kCADC_SingleEndANA3_DiffANA2pANA3n = 3U,  /*!< Single Endned ANA3 Signal Or Differential ANA2+, ANA3- signal. */
    kCADC_SingleEndANA4_DiffANA4pANA5n = 4U,  /*!< Single Endned ANA4 Signal Or Differential ANA4+, ANA5- signal. */
    kCADC_SingleEndANA5_DiffANA4pANA5n = 5U,  /*!< Single Endned ANA5 Signal Or Differential ANA4+, ANA5- signal. */
    kCADC_SingleEndANA6_DiffANA6pANA7n = 6U,  /*!< Single Endned ANA6 Signal Or Differential ANA6+, ANA7- signal. */
    kCADC_SingleEndANA7_DiffANA6pANA7n = 7U,  /*!< Single Endned ANA7 Signal Or Differential ANA6+, ANA7- signal. */
    kCADC_SingleEndANB0_DiffANB0pANB1n = 8U,  /*!< Single Endned ANB0 Signal Or Differential ANB0+, ANB1- signal. */
    kCADC_SingleEndANB1_DiffANB0pANB1n = 9U,  /*!< Single Endned ANB1 Signal Or Differential ANB0+, ANB1- signal. */
    kCADC_SingleEndANB2_DiffANB2pANB3n = 10U, /*!< Single Endned ANB2 Signal Or Differential ANB2+, ANB3- signal. */
    kCADC_SingleEndANB3_DiffANB2pANB3n = 11U, /*!< Single Endned ANB3 Signal Or Differential ANB2+, ANB3- signal. */
    kCADC_SingleEndANB4_DiffANB4pANB5n = 12U, /*!< Single Endned ANB4 Signal Or Differential ANB4+, ANB5- signal. */
    kCADC_SingleEndANB5_DiffANB4pANB5n = 13U, /*!< Single Endned ANB5 Signal Or Differential ANB4+, ANB5- signal. */
    kCADC_SingleEndANB6_DiffANB6pANB7n = 14U, /*!< Single Endned ANB6 Signal Or Differential ANB6+, ANB7- signal. */
    kCADC_SingleEndANB7_DiffANB6pANB7n = 15U, /*!< Single Endned ANB7 Signal Or Differential ANB6+, ANB7- signal. */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_ADCATemperatureSensor = 16U, /*!< Single Ended ADCA Temperature sensor. */
    kCADC_ADCAAnalogInput       = 17U, /*!< Single Ended ADCA analog input for on-chip generated signals. */
    kCADC_ADCBTemperatureSensor = 18U, /*!< Single Ended ADCB Temperature sensor. */
    kCADC_ADCBAnalogInput       = 19U, /*!< Single Ended ADCB analog input for on-chip generated signals. */
#endif                                 /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_channel_number_t;

/*!
 * @brief The enumeration of sample slot mask.
 */
typedef enum _cadc_sample_slot_mask
{
    kCADC_NonSampleSlotMask = 0UL,

    kCADC_SampleSlot0Mask  = 1UL << 0UL,  /*!< The mask of sample slot0. */
    kCADC_SampleSlot1Mask  = 1UL << 1UL,  /*!< The mask of sample slot1. */
    kCADC_SampleSlot2Mask  = 1UL << 2UL,  /*!< The mask of sample slot2. */
    kCADC_SampleSlot3Mask  = 1UL << 3UL,  /*!< The mask of sample slot3. */
    kCADC_SampleSlot4Mask  = 1UL << 4UL,  /*!< The mask of sample slot4. */
    kCADC_SampleSlot5Mask  = 1UL << 5UL,  /*!< The mask of sample slot5. */
    kCADC_SampleSlot6Mask  = 1UL << 6UL,  /*!< The mask of sample slot6. */
    kCADC_SampleSlot7Mask  = 1UL << 7UL,  /*!< The mask of sample slot7. */
    kCADC_SampleSlot8Mask  = 1UL << 8UL,  /*!< The mask of sample slot8. */
    kCADC_SampleSlot9Mask  = 1UL << 9UL,  /*!< The mask of sample slot9. */
    kCADC_SampleSlot10Mask = 1UL << 10UL, /*!< The mask of sample slot10. */
    kCADC_SampleSlot11Mask = 1UL << 11UL, /*!< The mask of sample slot11. */
    kCADC_SampleSlot12Mask = 1UL << 12UL, /*!< The mask of sample slot12. */
    kCADC_SampleSlot13Mask = 1UL << 13UL, /*!< The mask of sample slot13. */
    kCADC_SampleSlot14Mask = 1UL << 14UL, /*!< The mask of sample slot14. */
    kCADC_SampleSlot15Mask = 1UL << 15UL, /*!< The mask of sample slot15. */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_SampleSlot16Mask = 1UL << 16UL, /*!< The mask of sample slot16. */
    kCADC_SampleSlot17Mask = 1UL << 17UL, /*!< The mask of sample slot17. */
    kCADC_SampleSlot18Mask = 1UL << 18UL, /*!< The mask of sample slot18. */
    kCADC_SampleSlot19Mask = 1UL << 19UL, /*!< The mask of sample slot19. */
#endif                                    /* FSL_FEATURE_CADC_RSLT2_COUNT */

#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_AllSampleSlotsMask = 0xFFFFFUL, /*!< The mask of all sample slots. */
#else
    kCADC_AllSampleSlotsMask = 0xFFFFUL, /*!< The mask of all sample slots. */
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_sample_slot_mask_t;

/*!
 * @brief The enumeration of sample slot index.
 */
typedef enum _cadc_sample_slot_index
{
    kCADC_SampleSlot0Index  = 0U,  /*!< The index of sample slot0. */
    kCADC_SampleSlot1Index  = 1U,  /*!< The index of sample slot1. */
    kCADC_SampleSlot2Index  = 2U,  /*!< The index of sample slot2. */
    kCADC_SampleSlot3Index  = 3U,  /*!< The index of sample slot3. */
    kCADC_SampleSlot4Index  = 4U,  /*!< The index of sample slot4. */
    kCADC_SampleSlot5Index  = 5U,  /*!< The index of sample slot5. */
    kCADC_SampleSlot6Index  = 6U,  /*!< The index of sample slot6. */
    kCADC_SampleSlot7Index  = 7U,  /*!< The index of sample slot7. */
    kCADC_SampleSlot8Index  = 8U,  /*!< The index of sample slot8. */
    kCADC_SampleSlot9Index  = 9U,  /*!< The index of sample slot9. */
    kCADC_SampleSlot10Index = 10U, /*!< The index of sample slot10. */
    kCADC_SampleSlot11Index = 11U, /*!< The index of sample slot11. */
    kCADC_SampleSlot12Index = 12U, /*!< The index of sample slot12. */
    kCADC_SampleSlot13Index = 13U, /*!< The index of sample slot13. */
    kCADC_SampleSlot14Index = 14U, /*!< The index of sample slot14. */
    kCADC_SampleSlot15Index = 15U, /*!< The index of sample slot15. */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_SampleSlot16Index = 16U, /*!< The index of sample slot16. */
    kCADC_SampleSlot17Index = 17U, /*!< The index of sample slot17. */
    kCADC_SampleSlot18Index = 18U, /*!< The index of sample slot18. */
    kCADC_SampleSlot19Index = 19U, /*!< The index of sample slot19. */
#endif                             /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_sample_slot_index_t;

/*!
 * @brief The enumeration for the sample slot to be disabled in sequential mode.
 */
typedef enum _cadc_sample_slot_sequential_mode_disabled
{
    kCADC_Sample0Disabled = 1UL << 0UL,   /*!< Disable Sample slot0, the scan will stop at sample slot0
                                              in sequential scan mode */
    kCADC_Sample1Disabled = 1UL << 1UL,   /*!< Disable Sample slot1, the scan will stop at sample slot1
                                                in sequential scan mode */
    kCADC_Sample2Disabled = 1UL << 2UL,   /*!< Disable Sample slot2, the scan will stop at sample slot2
                                              in sequential scan mode */
    kCADC_Sample3Disabled = 1UL << 3UL,   /*!< Disable Sample slot3, the scan will stop at sample slot3
                                                in sequential scan mode */
    kCADC_Sample4Disabled = 1UL << 4UL,   /*!< Disable Sample slot4, the scan will stop at sample slot4
                                              in sequential scan mode */
    kCADC_Sample5Disabled = 1UL << 5UL,   /*!< Disable Sample slot5, the scan will stop at sample slot5
                                                in sequential scan mode */
    kCADC_Sample6Disabled = 1UL << 6UL,   /*!< Disable Sample slot6, the scan will stop at sample slot6
                                              in sequential scan mode */
    kCADC_Sample7Disabled = 1UL << 7UL,   /*!< Disable Sample slot7, the scan will stop at sample slot7
                                                in sequential scan mode */
    kCADC_Sample8Disabled = 1UL << 8UL,   /*!< Disable Sample slot8, the scan will stop at sample slot8
                                              in sequential scan mode */
    kCADC_Sample9Disabled = 1UL << 9UL,   /*!< Disable Sample slot9, the scan will stop at sample slot9
                                                in sequential scan mode */
    kCADC_Sample10Disabled = 1UL << 10UL, /*!< Disable Sample slot10, the scan will stop at sample slot10
                                            in sequential scan mode */
    kCADC_Sample11Disabled = 1UL << 11UL, /*!< Disable Sample slot11, the scan will stop at sample slot11
                                              in sequential scan mode */
    kCADC_Sample12Disabled = 1UL << 12UL, /*!< Disable Sample slot12, the scan will stop at sample slot12
                                              in sequential scan mode */
    kCADC_Sample13Disabled = 1UL << 13UL, /*!< Disable Sample slot13, the scan will stop at sample slot13
                                            in sequential scan mode */
    kCADC_Sample14Disabled = 1UL << 14UL, /*!< Disable Sample slot14, the scan will stop at sample slot14
                                              in sequential scan mode */
    kCADC_Sample15Disabled = 1UL << 15UL, /*!< Disable Sample slot15, the scan will stop at sample slot15
                                            in sequential scan mode */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_Sample16Disabled = 1UL << 16UL, /*!< Disable Sample slot16, the scan will stop at sample slot16
                                              in sequential scan mode */
    kCADC_Sample17Disabled = 1UL << 17UL, /*!< Disable Sample slot17, the scan will stop at sample slot17
                                              in sequential scan mode */
    kCADC_Sample18Disabled = 1UL << 18UL, /*!< Disable Sample slot18, the scan will stop at sample slot18
                                              in sequential scan mode */
    kCADC_Sample19Disabled = 1UL << 19UL, /*!< Disable Sample slot19, the scan will stop at sample slot19
                                            in sequential scan mode */
#endif                                    /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_sample_slot_sequential_mode_disabled_t;

/*!
 * @brief The enumeration for the sample slot to be disabled in simultaneous parallel mode.
 */
typedef enum _cadc_sample_slot_simultParallel_mode_disabled
{
    kCADC_Sample0_8Disabled = 1UL << 0UL, /*!< Disable Sample slot0 and Sample Slot 8, in the simultaneous parallel mode
                                         the converter A and converter B will stop at Sample slot0 and Sample slot 8. */
    kCADC_Sample1_9Disabled = 1UL << 1UL, /*!< Disable Sample slot1 and Sample Slot 9, in the simultaneous parallel mode
                                         the converter A and converter B will stop at Sample slot1 and Sample slot 9. */
    kCADC_Sample2_10Disabled = 1UL << 2UL, /*!< Disable Sample slot2 and Sample Slot 10,
                                                in the simultaneous parallel mode the converter A
                                                and converter B will stop at Sample slot2 and Sample slot 10. */
    kCADC_Sample3_11Disabled = 1UL << 3UL, /*!< Disable Sample slot3 and Sample Slot 11,
                                            in the simultaneous parallel mode the converter A
                                            and converter B will stop at Sample slot3 and Sample slot 11. */
    kCADC_Sample4_12Disabled = 1UL << 4UL, /*!< Disable Sample slot4 and Sample Slot 12,
                                                in the simultaneous parallel mode the converter A
                                                and converter B will stop at Sample slot4 and Sample slot 12. */
    kCADC_Sample5_13Disabled = 1UL << 5UL, /*!< Disable Sample slot5 and Sample Slot 13,
                                                in the simultaneous parallel mode the converter A
                                                and converter B will stop at Sample slot5 and Sample slot 13. */
    kCADC_Sample6_14Disabled = 1UL << 6UL, /*!< Disable Sample slot6 and Sample Slot 14,
                                                in the simultaneous parallel mode the converter A
                                                and converter B will stop at Sample slot7 and Sample slot 14. */
    kCADC_Sample7_15Disabled = 1UL << 7UL, /*!< Disable Sample slot7 and Sample Slot 15,
                                                in the simultaneous parallel mode the converter A
                                                and converter B will stop at Sample slot7 and Sample slot 15. */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_Sample16_18Disabled = 1UL << 16UL, /*!< Disable Sample slot16 and Sample Slot 18,
                                                    in the simultaneous parallel mode the converter A
                                                    and converter B will stop at Sample slot16 and Sample slot 18. */
    kCADC_Sample17_19Disabled = 1UL << 17UL, /*!< Disable Sample slot17 and Sample Slot 19,
                                                    in the simultaneous parallel mode the converter A
                                                    and converter B will stop at Sample slot17 and Sample slot 19. */
#endif                                       /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_sample_slot_simultParallel_mode_disabled_t;

/*!
 * @brief The enumeration for the sample slot to be disabled for the converter A in independent parallel mode.
 */
typedef enum _cadc_sample_slot_independentParallel_mode_convA_disabled
{
    kCADC_ConvASample0Disabled = (uint16_t)(1UL << 0UL), /*!< Disable Sample slot0, the scan will stop at sample slot0
                                            in sequential scan mode */
    kCADC_ConvASample1Disabled = (uint16_t)(1UL << 1UL), /*!< Disable Sample slot1, the scan will stop at sample slot1
                                              in sequential scan mode */
    kCADC_ConvASample2Disabled = (uint16_t)(1UL << 2UL), /*!< Disable Sample slot2, the scan will stop at sample slot2
                                            in sequential scan mode */
    kCADC_ConvASample3Disabled = (uint16_t)(1UL << 3UL), /*!< Disable Sample slot3, the scan will stop at sample slot3
                                              in sequential scan mode */
    kCADC_ConvASample4Disabled = (uint16_t)(1UL << 4UL), /*!< Disable Sample slot4, the scan will stop at sample slot4
                                            in sequential scan mode */
    kCADC_ConvASample5Disabled = (uint16_t)(1UL << 5UL), /*!< Disable Sample slot5, the scan will stop at sample slot5
                                              in sequential scan mode */
    kCADC_ConvASample6Disabled = (uint16_t)(1UL << 6UL), /*!< Disable Sample slot6, the scan will stop at sample slot6
                                            in sequential scan mode */
    kCADC_ConvASample7Disabled = (uint16_t)(1UL << 7UL), /*!< Disable Sample slot7, the scan will stop at sample slot7
                                              in sequential scan mode */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_ConvASample16Disabled = (uint16_t)(1U << (16U - 8U)), /*!< Disable Sample slot16, the scan will stop at sample
                                              slot16 in sequential scan mode */
    kCADC_ConvASample17Disabled = (uint16_t)(1U << (17U - 8U)), /*!< Disable Sample slot17, the scan will stop at sample
                                              slot17 in sequential scan mode */
#endif                                                          /* FSL_FEATURE_CADC_RSLT2_COUNT */
    kCADC_ConvASampleReserved = (uint16_t)(1UL << 15UL),        /*!< Reserved */
} cadc_sample_slot_independentParallel_mode_convA_disabled_t;

/*!
 * @brief The enumeration for the sample slot to be disabled for the converter B in independent parallel mode.
 */
typedef enum _cadc_sample_slot_indParallel_mode_convB_disabled
{
    kCADC_ConvBSample8Disabled = (uint16_t)(1UL << (8UL - 8UL)), /*!< Disable Sample slot8, the scan will stop at sample
                                             slot8 in sequential scan mode */
    kCADC_ConvBSample9Disabled = (uint16_t)(1UL << (9UL - 8UL)), /*!< Disable Sample slot9, the scan will stop at sample
                                              slot9 in sequential scan mode */
    kCADC_ConvBSample10Disabled = (uint16_t)(1UL << (10UL - 8UL)), /*!< Disable Sample slot10, the scan will stop at
                                            sample slot10 in sequential scan mode */
    kCADC_ConvBSample11Disabled = (uint16_t)(1UL << (11UL - 8UL)), /*!< Disable Sample slot11, the scan will stop at
                                              sample slot11 in sequential scan mode */
    kCADC_ConvBSample12Disabled = (uint16_t)(1UL << (12UL - 8UL)), /*!< Disable Sample slot12, the scan will stop at
                                              sample slot12 in sequential scan mode */
    kCADC_ConvBSample13Disabled = (uint16_t)(1UL << (13UL - 8UL)), /*!< Disable Sample slot13, the scan will stop at
                                             sample slot13 in sequential scan mode */
    kCADC_ConvBSample14Disabled = (uint16_t)(1UL << (14UL - 8UL)), /*!< Disable Sample slot14, the scan will stop at
                                              sample slot14 in sequential scan mode */
    kCADC_ConvBSample15Disabled = (uint16_t)(1UL << (15UL - 8UL)), /*!< Disable Sample slot15, the scan will stop at
                                            sample slot15 in sequential scan mode */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_ConvBSample18Disabled = (uint16_t)(1UL << (18U - 8U)), /*!< Disable Sample slot18, the scan will stop at
                                              sample slot18 in sequential scan mode */
    kCADC_ConvBSample19Disabled = (uint16_t)(1UL << (19U - 8U)), /*!< Disable Sample slot19, the scan will stop at
                                            sample slot19 in sequential scan mode */
#endif                                                           /* FSL_FEATURE_CADC_RSLT2_COUNT */
    kCADC_ConvBSampleReserved = (uint16_t)(1UL << 15UL),         /*!< Reserved */
} cadc_sample_slot_independentParallel_mode_convB_disabled_t;

/*!
 * @brief The enumeration for the sample slot's zero crossing event.
 */
typedef enum _cadc_sample_slot_zero_crossing_mode
{
    kCADC_ZeroCrossingDisabled          = 0U, /*!< Zero Crossing disabled. */
    kCADC_ZeroCrossingForPtoNSign       = 1U, /*!< Zero Crossing enabled for positive to negative sign change. */
    kCADC_ZeroCrossingForNtoPSign       = 2U, /*!< Zero Crossing enabled for negative to positive sign change. */
    kCADC_ZeroCrossingForAnySignChanged = 3U, /*!< Zero Crossing enabled for any sign change. */
} cadc_sample_slot_zero_crossing_mode_t;

#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
/*!
 * @brief The enumeration for expansion multiplexer.
 */
typedef enum _cadc_expansion_mux_operate_mode
{
    kCADC_ExpMuxManualMode = 0U, /*!< MUX channel feeding to ANA4/ANB4 is selected as MUXSEL0. */
    kCADC_ExpMuxScanMode0,       /*!< The sample completion of ANA4/ANB4 enableds subsequent selected channel. */
    kCADC_ExpMuxScanMode1,       /*!< The sample completion of ANA7/ANB7 enableds subsequent selected channel. */
    kCADC_ExpMuxScanMode2, /*!< The sample completion of ANA4/ANB4 or ANA7/ANB7 enableds subsequent selected channel. */
} cadc_expansion_mux_operate_mode_t;
#endif /* (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) */

/*!
 * @brief The structure of the disabled sample slots in independent parallel mode.
 */
typedef struct _cadc_sample_slot_independentParallel_mode_disabled
{
    cadc_sample_slot_independentParallel_mode_convA_disabled_t eConverterA; /*!< The sample slot to be
                                                                        disabled for the converter A, when the scan mode
                                                                        is set as independent parallel mode. */
    cadc_sample_slot_independentParallel_mode_convB_disabled_t eConverterB; /*!< The sample slot to be
                                                                        disabled for the converter B, when the scan mode
                                                                        is set as independent parallel mode. */
} cadc_sample_slot_independentParallel_mode_disabled_t;

/*!
 * @brief The union of disabled sample slot for each scan mode.
 */
typedef union _cadc_sample_slot_disabled
{
    uint32_t u32SampleDisVal; /*!< The 32 bits width of disabled sample slot value.
                                            This member used to get the disabled sample slot
                                            which sets in different scan modes in word type.
                                            This member is not recommended to be used to set
                                            the disabled sample slot. This member is designed
                                            to be used in driver level only, the application
                                            should not use this member. */
    cadc_sample_slot_sequential_mode_disabled_t eSequentialModeDisSample;         /*!< If the scan mode is selected as
                                                                                sequential mode, the application
                                                                                must use this member to set the disabled
                                                                                sample slot. This member is used to set
                                                                                disabled sample slot when the scan mode is
                                                                                selected as sequential mode. The scan will
                                                                                stop at the first disabled sample slot in
                                                                                that mode. So for the application, this
                                                                                member should be set as one sample slot
                                                                                index that the scan will stop. */
    cadc_sample_slot_simultParallel_mode_disabled_t eSimultParallelModeDisSample; /*!< In simultaneous parallel scan
                                                                        mode, the application must use this member to
                                                                        set the disabled sample slot. In that scan mode,
                                                                        the scan will stop when either converter
                                                                        encounters a disabled sample. */
    cadc_sample_slot_independentParallel_mode_disabled_t sIndependentParallelModeDisSample; /*!< In independent parallel
                                                                    scan mode, the application must use this member to
                                                                    set the disabled sample slot. In that scan mode, the
                                                                    converter will stop scan when it encounters a
                                                                    disabled sample slot. In this mode, the disabled
                                                                    sample slot for converterA and converterB may
                                                                    different.*/
} cadc_sample_slot_disabled_t;

/*!
 * @brief The structure for configuring the sample slot.
 */
typedef struct _cadc_sample_config
{
    cadc_sample_slot_zero_crossing_mode_t eZeroCrossingMode; /*!< Zero crossing mode. */
    uint16_t u16HighLimitValue; /*!< High limit value. Original value formation as hardware register,
                                       with 3-bits left shifted. */
    uint16_t u16LowLimitValue;  /*!< Low limit value. Original value formation as
                                       hardware register, with 3-bits left shifted. */
    uint16_t u16OffsetValue;    /*!< Offset value. Original value formation as hardware register, with
                                       3-bits left shifted. */
} cadc_sample_slot_config_t;

/*!
 * @brief Cadc scan control for sequential scan mode.
 *
 * @note Each member of this structure represent one bit of the word.
 *       Asserted the structure's member means delay sample until a new sync input occurs. Cleared
 *       the structure's member means perform sample immediately after the completion of the current sample.
 *
 */
typedef struct _cadc_scan_ctrl_sequential_mode
{
    uint32_t bitSample0 : 1U;  /*!< Control whether delay sample0 until a new sync input occurs. */
    uint32_t bitSample1 : 1U;  /*!< Control whether delay sample1 until a new sync input occurs. */
    uint32_t bitSample2 : 1U;  /*!< Control whether delay sample2 until a new sync input occurs. */
    uint32_t bitSample3 : 1U;  /*!< Control whether delay sample3 until a new sync input occurs. */
    uint32_t bitSample4 : 1U;  /*!< Control whether delay sample4 until a new sync input occurs. */
    uint32_t bitSample5 : 1U;  /*!< Control whether delay sample5 until a new sync input occurs. */
    uint32_t bitSample6 : 1U;  /*!< Control whether delay sample6 until a new sync input occurs. */
    uint32_t bitSample7 : 1U;  /*!< Control whether delay sample7 until a new sync input occurs. */
    uint32_t bitSample8 : 1U;  /*!< Control whether delay sample8 until a new sync input occurs. */
    uint32_t bitSample9 : 1U;  /*!< Control whether delay sample9 until a new sync input occurs. */
    uint32_t bitSample10 : 1U; /*!< Control whether delay sample10 until a new sync input occurs. */
    uint32_t bitSample11 : 1U; /*!< Control whether delay sample11 until a new sync input occurs. */
    uint32_t bitSample12 : 1U; /*!< Control whether delay sample12 until a new sync input occurs. */
    uint32_t bitSample13 : 1U; /*!< Control whether delay sample13 until a new sync input occurs. */
    uint32_t bitSample14 : 1U; /*!< Control whether delay sample14 until a new sync input occurs. */
    uint32_t bitSample15 : 1U; /*!< Control whether delay sample15 until a new sync input occurs. */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    uint32_t bitSample16 : 1U; /*!< Control whether delay sample16 until a new sync input occurs. */
    uint32_t bitSample17 : 1U; /*!< Control whether delay sample17 until a new sync input occurs. */
    uint32_t bitSample18 : 1U; /*!< Control whether delay sample18 until a new sync input occurs. */
    uint32_t bitSample19 : 1U; /*!< Control whether delay sample19 until a new sync input occurs. */
#endif                         /* FSL_FEATURE_CADC_RSLT2_COUNT */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    uint32_t bitsReserved : 12U; /*!< Reserved 12 bits. */
#else
    uint32_t bitsReserved : 16U;         /*!< Reserved 16 bits. */
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_scan_ctrl_seq_mode_t;

/*!
 * @brief Cadc scan control for simultaneous parallel scan mode.
 *
 * @note Each member of this structure represent one bit of the word.
 *      Asserted the structure's member means delay sample until a new sync input occurs.
 *      Cleared the structure's member means perform sample immediately after the completion
 *      of the current sample.
 *
 */
typedef struct _cadc_scan_ctrl_simultParallel_mode
{
    uint32_t bitSample0_8 : 1U;  /*!< Control whether delay sample0 and sample8 until a new sync input occurs. */
    uint32_t bitSample1_9 : 1U;  /*!< Control whether delay sample1 and sample9 until a new sync input occurs. */
    uint32_t bitSample2_10 : 1U; /*!< Control whether delay sample2 and sample10 until a new sync input occurs. */
    uint32_t bitSample3_11 : 1U; /*!< Control whether delay sample3 and sample11 until a new sync input occurs. */
    uint32_t bitsReserved1 : 4U; /*!< Reserved 4 bits. */
    uint32_t bitSample4_12 : 1U; /*!< Control whether delay sample4 and sample12 until a new sync input occurs. */
    uint32_t bitSample5_13 : 1U; /*!< Control whether delay sample5 and sample13 until a new sync input occurs. */
    uint32_t bitSample6_14 : 1U; /*!< Control whether delay sample6 and sample14 until a new sync input occurs. */
    uint32_t bitSample7_15 : 1U; /*!< Control whether delay sample7 and sample15 until a new sync input occurs. */
    uint32_t bitsReserved2 : 4U; /*!< Reserved 4 bits. */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    uint32_t bitSample16_18 : 1U; /*!< Control whether delay sample16 and sample18 until a new sync input occurs. */
    uint32_t bitSample17_19 : 1U; /*!< Control whether delay sample17 and sample19 until a new sync input occurs. */
#endif                            /* FSL_FEATURE_CADC_RSLT2_COUNT */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    uint32_t bitsReserved3 : 14U; /*!< Reserved 14 bits. */
#else
    uint32_t bitsReserved3 : 16U;        /*!< Reserved 16 bits. */
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_scan_ctrl_simultParallel_mode_t;

/*!
 * @brief The scan ctrl struture for converterA in independent scan mode.
 */
typedef struct _cadc_scan_ctrl_independent_parallel_mode_converterA
{
    uint32_t bitSample0 : 1U;    /*!< Control whether delay converterA's sample0 until
                                     a new sync input occurs. */
    uint32_t bitSample1 : 1U;    /*!< Control whether delay converterA's sample1 until
                                     a new sync input occurs. */
    uint32_t bitSample2 : 1U;    /*!< Control whether delay converterA's sample2 until
                                     a new sync input occurs. */
    uint32_t bitSample3 : 1U;    /*!< Control whether delay converterA's sample3 until
                                                a new sync input occurs. */
    uint32_t bitsReserved1 : 4U; /*!< Reserved 4 bits. */
    uint32_t bitSample4 : 1U;    /*!< Control whether delay converterA's sample4 until
                                     a new sync input occurs. */
    uint32_t bitSample5 : 1U;    /*!< Control whether delay converterA's sample5 until
                                     a new sync input occurs. */
    uint32_t bitSample6 : 1U;    /*!< Control whether delay converterA's sample6 until
                                     a new sync input occurs. */
    uint32_t bitSample7 : 1U;    /*!< Control whether delay converterA's sample7 until
                                                a new sync input occurs. */
    uint32_t bitsReserved2 : 4U; /*!< Reserved 4 bits */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    uint32_t bitSample16 : 1U;    /*!< Control whether delay converterA's sample16 until
                                      a new sync input occurs. */
    uint32_t bitSample17 : 1U;    /*!< Control whether delay converterA's sample17 until
                                                 a new sync input occurs. */
    uint32_t bitsReserved3 : 14U; /*!< Reserved 14 bits. */
#else
    uint32_t bitsReserved3 : 16U;        /*!< Reserved 16 bits. */
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_scan_ctrl_independent_parallel_mode_converterA_t;

/*!
 * @brief The scan ctrl struture for converterB in independent scan mode.
 */
typedef struct _cadc_scan_ctrl_independent_parallel_mode_converterB
{
    uint32_t bitsReserved1 : 4U; /*!< Reserved 4 bits. */
    uint32_t bitSample8 : 1U;    /*!< Control whether delay converterB's sample8 until
                                     a new sync input occurs. */
    uint32_t bitSample9 : 1U;    /*!< Control whether delay converterB's sample9 until
                                     a new sync input occurs. */
    uint32_t bitSample10 : 1U;   /*!< Control whether delay converterB's sample10 until
                                     a new sync input occurs. */
    uint32_t bitSample11 : 1U;   /*!< Control whether delay converterB's sample11 until
                                                a new sync input occurs. */
    uint32_t bitsReserved2 : 4U; /*!< Reserved 4 bits. */
    uint32_t bitSample12 : 1U;   /*!< Control whether delay converterB's sample12 until
                                     a new sync input occurs. */
    uint32_t bitSample13 : 1U;   /*!< Control whether delay converterB's sample13 until
                                     a new sync input occurs. */
    uint32_t bitSample14 : 1U;   /*!< Control whether delay converterB's sample14 until
                                     a new sync input occurs. */
    uint32_t bitSample15 : 1U;   /*!< Control whether delay converterB's sample15 until
                                                a new sync input occurs. */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    uint32_t bitsReserved3 : 2U;  /*!< Reserved 2 bits. */
    uint32_t bitSample18 : 1U;    /*!< Control whether delay converterB's sample18 until
                                      a new sync input occurs. */
    uint32_t bitSample19 : 1U;    /*!< Control whether delay converterB's sample19 until
                                                 a new sync input occurs. */
    uint32_t bitsReserved4 : 12U; /*!< Reserved 12 bits. */
#else
    uint32_t bitsReserved3 : 16U;        /*!< Reserved 16 bits. */
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_scan_ctrl_independent_parallel_mode_converterB_t;

/*!
 * @brief The union for converters in independent parallel mode.
 */
typedef union _cadc_scan_ctrl_independent_parallel_mode
{
    cadc_scan_ctrl_independent_parallel_mode_converterA_t sConverterA; /*!< Scan control for converterA. */
    cadc_scan_ctrl_independent_parallel_mode_converterB_t sConverterB; /*!< Scan control for converterB. */
} cadc_scan_ctrl_independent_parallel_mode_t;

/*!
 * @brief The union of the scan control for each scan mode.
 */
typedef union _cadc_scan_control
{
    uint32_t u32ScanCtrlVal;                              /*!< The 32 bits value of the scan control value. */
    cadc_scan_ctrl_seq_mode_t sSequential;                /*!< Scan control for sequential scan mode. */
    cadc_scan_ctrl_simultParallel_mode_t sSimultParallel; /*!< Scan control for simultaneous parallel scan mode. */
    cadc_scan_ctrl_independent_parallel_mode_t uIndependentParallel; /*!< Scan control for independent scan mode. */
} cadc_scan_control_t;

#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
/*!
 * @brief The enumeration of conveter's auxiliary control.
 */
typedef enum _cadc_auxiliary_control
{
    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel0_Config0 = 0UL << 0UL, /*!< Auxiliary select 0 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel0_Config1 = 1UL << 0UL, /*!< Auxiliary select 0 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel0_Config2 = 2UL << 0UL, /*!< Auxiliary select 0 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel0_Config3 = 3UL << 0UL, /*!< Auxiliary select 0 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */

    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel1_Config0 = 0UL << 2UL, /*!< Auxiliary select 1 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel1_Config1 = 1UL << 2UL, /*!< Auxiliary select 1 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel1_Config2 = 2UL << 2UL, /*!< Auxiliary select 1 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel1_Config3 = 3UL << 2UL, /*!< Auxiliary select 1 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */

    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel2_Config0 = 0UL << 4UL, /*!< Auxiliary select 2 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel2_Config1 = 1UL << 4UL, /*!< Auxiliary select 2 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel2_Config2 = 2UL << 4UL, /*!< Auxiliary select 2 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel2_Config3 = 3UL << 4UL, /*!< Auxiliary select 2 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */

    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel3_Config0 = 0UL << 6UL, /*!< Auxiliary select 3 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel3_Config1 = 1UL << 6UL, /*!< Auxiliary select 3 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel3_Config2 = 2UL << 6UL, /*!< Auxiliary select 3 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel3_Config3 = 3UL << 6UL, /*!< Auxiliary select 3 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */

    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel4_Config0 = 0UL << 8UL, /*!< Auxiliary select 4 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel4_Config1 = 1UL << 8UL, /*!< Auxiliary select 4 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel4_Config2 = 2UL << 8UL, /*!< Auxiliary select 4 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel4_Config3 = 3UL << 8UL, /*!< Auxiliary select 4 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */

    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel5_Config0 = 0UL << 10UL, /*!< Auxiliary select 5 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel5_Config1 = 1UL << 10UL, /*!< Auxiliary select 5 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel5_Config2 = 2UL << 10UL, /*!< Auxiliary select 5 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel5_Config3 = 3UL << 10UL, /*!< Auxiliary select 5 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */

    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel6_Config0 = 0UL << 12UL, /*!< Auxiliary select 6 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel6_Config1 = 1UL << 12UL, /*!< Auxiliary select 6 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel6_Config2 = 2UL << 12UL, /*!< Auxiliary select 6 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel6_Config3 = 3UL << 12UL, /*!< Auxiliary select 6 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */

    /* The following four enumeration members are mutually exclusive. */
    kCADC_AuxSel7_Config0 = 0UL << 14UL, /*!< Auxiliary select 7 controls AUX_SEL0 = 0, AUX_SEL1 = 0. */
    kCADC_AuxSel7_Config1 = 1UL << 14UL, /*!< Auxiliary select 7 controls AUX_SEL0 = 1, AUX_SEL1 = 0. */
    kCADC_AuxSel7_Config2 = 2UL << 14UL, /*!< Auxiliary select 7 controls AUX_SEL0 = 0, AUX_SEL1 = 1. */
    kCADC_AuxSel7_Config3 = 3UL << 14UL, /*!< Auxiliary select 7 controls AUX_SEL0 = 1, AUX_SEL1 = 1. */
} cadc_auxiliary_control_t;

/*!
 * @brief The enumeration for the expansion mux slot to be disabled.
 */
typedef enum _cadc_expansion_disabled_mux_slot
{
    kCADC_ExpaMuxNoDisable = 0U,  /*!< Expansion mux scan not disabled. */
    kCADC_ExpMux0Disable   = 3U,  /*!< Expansion mux slot 0. */
    kCADC_ExpMux1Disable   = 7U,  /*!< Expansion mux slot 1. */
    kCADC_ExpMux2Disable   = 11U, /*!< Expansion mux slot 2. */
    kCADC_ExpMux3Disable   = 15U, /*!< Expansion mux slot 3. */
    kCADC_ExpMux4Disable   = 19U, /*!< Expansion mux slot 4. */
    kCADC_ExpMux5Disable   = 23U, /*!< Expansion mux slot 5. */
    kCADC_ExpMux6Disable   = 27U, /*!< Expansion mux slot 6. */
    kCADC_ExpMux7Disable   = 31U, /*!< Expansion mux slot 7. */
} cadc_expansion_disabled_mux_slot_t;

#if !(defined(FSL_FEATURE_CADC_HAS_EXP_MUX_SEL) && (FSL_FEATURE_CADC_HAS_EXP_MUX_SEL == 0))
/*!
 * @brief The enumeration of expanssion mux selection.
 */
typedef enum _cadc_expansion_mux_selection
{
    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel0_Channel0 = 0UL << 0UL, /*!< MUX's channel 0 for MUXSEL0. */
    kCADC_MuxSel0_Channel1 = 1UL << 0UL, /*!< MUX's channel 1 for MUXSEL0. */
    kCADC_MuxSel0_Channel2 = 2UL << 0UL, /*!< MUX's channel 2 for MUXSEL0. */
    kCADC_MuxSel0_Channel3 = 3UL << 0UL, /*!< MUX's channel 3 for MUXSEL0. */
    kCADC_MuxSel0_Channel4 = 4UL << 0UL, /*!< MUX's channel 4 for MUXSEL0. */
    kCADC_MuxSel0_Channel5 = 5UL << 0UL, /*!< MUX's channel 5 for MUXSEL0. */
    kCADC_MuxSel0_Channel6 = 6UL << 0UL, /*!< MUX's channel 6 for MUXSEL0. */
    kCADC_MuxSel0_Channel7 = 7UL << 0UL, /*!< MUX's channel 7 for MUXSEL0. */

    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel1_Channel0 = 0UL << 4UL, /*!< MUX's channel 0 for MUXSEL1. */
    kCADC_MuxSel1_Channel1 = 1UL << 4UL, /*!< MUX's channel 1 for MUXSEL1. */
    kCADC_MuxSel1_Channel2 = 2UL << 4UL, /*!< MUX's channel 2 for MUXSEL1. */
    kCADC_MuxSel1_Channel3 = 3UL << 4UL, /*!< MUX's channel 3 for MUXSEL1. */
    kCADC_MuxSel1_Channel4 = 4UL << 4UL, /*!< MUX's channel 4 for MUXSEL1. */
    kCADC_MuxSel1_Channel5 = 5UL << 4UL, /*!< MUX's channel 5 for MUXSEL1. */
    kCADC_MuxSel1_Channel6 = 6UL << 4UL, /*!< MUX's channel 6 for MUXSEL1. */
    kCADC_MuxSel1_Channel7 = 7UL << 4UL, /*!< MUX's channel 7 for MUXSEL1. */

    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel2_Channel0 = 0UL << 8UL, /*!< MUX's channel 0 for MUXSEL2. */
    kCADC_MuxSel2_Channel1 = 1UL << 8UL, /*!< MUX's channel 1 for MUXSEL2. */
    kCADC_MuxSel2_Channel2 = 2UL << 8UL, /*!< MUX's channel 2 for MUXSEL2. */
    kCADC_MuxSel2_Channel3 = 3UL << 8UL, /*!< MUX's channel 3 for MUXSEL2. */
    kCADC_MuxSel2_Channel4 = 4UL << 8UL, /*!< MUX's channel 4 for MUXSEL2. */
    kCADC_MuxSel2_Channel5 = 5UL << 8UL, /*!< MUX's channel 5 for MUXSEL2. */
    kCADC_MuxSel2_Channel6 = 6UL << 8UL, /*!< MUX's channel 6 for MUXSEL2. */
    kCADC_MuxSel2_Channel7 = 7UL << 8UL, /*!< MUX's channel 7 for MUXSEL2. */

    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel3_Channel0 = 0UL << 12UL, /*!< MUX's channel 0 for MUXSEL3. */
    kCADC_MuxSel3_Channel1 = 1UL << 12UL, /*!< MUX's channel 1 for MUXSEL3. */
    kCADC_MuxSel3_Channel2 = 2UL << 12UL, /*!< MUX's channel 2 for MUXSEL3. */
    kCADC_MuxSel3_Channel3 = 3UL << 12UL, /*!< MUX's channel 3 for MUXSEL3. */
    kCADC_MuxSel3_Channel4 = 4UL << 12UL, /*!< MUX's channel 4 for MUXSEL3. */
    kCADC_MuxSel3_Channel5 = 5UL << 12UL, /*!< MUX's channel 5 for MUXSEL3. */
    kCADC_MuxSel3_Channel6 = 6UL << 12UL, /*!< MUX's channel 6 for MUXSEL3. */
    kCADC_MuxSel3_Channel7 = 7UL << 12UL, /*!< MUX's channel 7 for MUXSEL3. */

    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel4_Channel0 = 0UL << 16UL, /*!< MUX's channel 0 for MUXSEL4. */
    kCADC_MuxSel4_Channel1 = 1UL << 16UL, /*!< MUX's channel 1 for MUXSEL4. */
    kCADC_MuxSel4_Channel2 = 2UL << 16UL, /*!< MUX's channel 2 for MUXSEL4. */
    kCADC_MuxSel4_Channel3 = 3UL << 16UL, /*!< MUX's channel 3 for MUXSEL4. */
    kCADC_MuxSel4_Channel4 = 4UL << 16UL, /*!< MUX's channel 4 for MUXSEL4. */
    kCADC_MuxSel4_Channel5 = 5UL << 16UL, /*!< MUX's channel 5 for MUXSEL4. */
    kCADC_MuxSel4_Channel6 = 6UL << 16UL, /*!< MUX's channel 6 for MUXSEL4. */
    kCADC_MuxSel4_Channel7 = 7UL << 16UL, /*!< MUX's channel 7 for MUXSEL4. */

    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel5_Channel0 = 0UL << 20UL, /*!< MUX's channel 0 for MUXSEL5. */
    kCADC_MuxSel5_Channel1 = 1UL << 20UL, /*!< MUX's channel 1 for MUXSEL5. */
    kCADC_MuxSel5_Channel2 = 2UL << 20UL, /*!< MUX's channel 2 for MUXSEL5. */
    kCADC_MuxSel5_Channel3 = 3UL << 20UL, /*!< MUX's channel 3 for MUXSEL5. */
    kCADC_MuxSel5_Channel4 = 4UL << 20UL, /*!< MUX's channel 4 for MUXSEL5. */
    kCADC_MuxSel5_Channel5 = 5UL << 20UL, /*!< MUX's channel 5 for MUXSEL5. */
    kCADC_MuxSel5_Channel6 = 6UL << 20UL, /*!< MUX's channel 6 for MUXSEL5. */
    kCADC_MuxSel5_Channel7 = 7UL << 20UL, /*!< MUX's channel 7 for MUXSEL5. */

    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel6_Channel0 = 0UL << 24UL, /*!< MUX's channel 0 for MUXSEL6. */
    kCADC_MuxSel6_Channel1 = 1UL << 24UL, /*!< MUX's channel 1 for MUXSEL6. */
    kCADC_MuxSel6_Channel2 = 2UL << 24UL, /*!< MUX's channel 2 for MUXSEL6. */
    kCADC_MuxSel6_Channel3 = 3UL << 24UL, /*!< MUX's channel 3 for MUXSEL6. */
    kCADC_MuxSel6_Channel4 = 4UL << 24UL, /*!< MUX's channel 4 for MUXSEL6. */
    kCADC_MuxSel6_Channel5 = 5UL << 24UL, /*!< MUX's channel 5 for MUXSEL6. */
    kCADC_MuxSel6_Channel6 = 6UL << 24UL, /*!< MUX's channel 6 for MUXSEL6. */
    kCADC_MuxSel6_Channel7 = 7UL << 24UL, /*!< MUX's channel 7 for MUXSEL6. */

    /* The following 8 enumeration members are mutually exclusive. */
    kCADC_MuxSel7_Channel0 = 0UL << 28UL, /*!< MUX's channel 0 for MUXSEL7. */
    kCADC_MuxSel7_Channel1 = 1UL << 28UL, /*!< MUX's channel 1 for MUXSEL7. */
    kCADC_MuxSel7_Channel2 = 2UL << 28UL, /*!< MUX's channel 2 for MUXSEL7. */
    kCADC_MuxSel7_Channel3 = 3UL << 28UL, /*!< MUX's channel 3 for MUXSEL7. */
    kCADC_MuxSel7_Channel4 = 4UL << 28UL, /*!< MUX's channel 4 for MUXSEL7. */
    kCADC_MuxSel7_Channel5 = 5UL << 28UL, /*!< MUX's channel 5 for MUXSEL7. */
    kCADC_MuxSel7_Channel6 = 6UL << 28UL, /*!< MUX's channel 6 for MUXSEL7. */
    kCADC_MuxSel7_Channel7 = 7UL << 28UL, /*!< MUX's channel 7 for MUXSEL7. */
} cadc_expansion_mux_selection_t;
#endif

/*!
 * @brief The structure for configuring Cyclic ADC's expansion setting.
 */
typedef struct _cadc_exp_mux_aux_config
{
    cadc_expansion_mux_operate_mode_t expMuxOperateMode; /* Specify expansion mux operate mode */
    uint16_t u16AuxControl;                              /*!< The mask of auxiliary control, should be the OR'ed value
                                                             of @ref cadc_auxiliary_control_t.  */

#if !(defined(FSL_FEATURE_CADC_HAS_EXP_MUX_SEL) && (FSL_FEATURE_CADC_HAS_EXP_MUX_SEL == 0))
    uint32_t u32MuxChannelMask; /*!< The mask of mux selection of all mux solts,
                                  should be the OR'ed value of @ref cadc_expansion_mux_selection_t. */
#endif

    cadc_expansion_disabled_mux_slot_t disabledMuxSlot; /*!< mux slot to disabled in the scan. */
} cadc_exp_mux_aux_config_t;

#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */

/*!
 * @brief The structure for configuring each converter.
 */
typedef struct _cadc_converter_config
{
    uint16_t u16ClockDivisor; /*!< Converter's clock divisor for the clock source. Available setting range is 0-63.
                                    - When the clockDivisor is 0, the divisor is 2.
                                    - For all other clockDivisor values, the divisor is 1 more than the decimal value of
                                        clockDivisor: clockDivisor + 1 */
#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
    cadc_speed_mode_t eSpeedMode;                                /*!< Converter's speed mode. */
#endif                                                           /* FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */
    cadc_reference_voltage_source_t eHighReferenceVoltageSource; /*!< High voltage reference source. */
    cadc_reference_voltage_source_t eLowReferenceVoltageSource;  /*!< Low reference voltage source. */
#if !(defined(FSL_FEATURE_CADC_NO_SAMPLE_WINDOW) && FSL_FEATURE_CADC_NO_SAMPLE_WINDOW)
    uint16_t u16SampleWindowCount; /*!< Sample Window Count. Available setting range is 0-7. */
#endif                             /* FSL_FEATURE_CADC_NO_SAMPLE_WINDOW */
    bool bEnableDMA;               /*!< Enable/Disable DMA. */
    bool bPowerUp;                 /*!< Power up or power down the converter. */
    bool bScanInitBySync;          /*!< The member user to control the initiate method of the scan.
                                          - \b true Use a SYNC input pulse or START command to initiate a scan.
                                          - \b false  Scan is initiated by the assertion of START command only. */
#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
    cadc_exp_mux_aux_config_t muxAuxConfig; /*!< Configuration of expansion mux and auxiliary control. */
#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */
} cadc_converter_config_t;

/*!
 * @brief The structure for configuring the Cyclic ADC's setting.
 */
typedef struct _cadc_config
{
    /* Common options. */
    cadc_idle_work_mode_t eIdleWorkMode;         /*!< Idle work mode for the module. */
    cadc_dma_trigger_source_t eDMATriggerSource; /*!<  Selects the dma trigger source for the module. */
    uint16_t u16PowerUpDelay;                    /*!< The number of ADC clocks to power up the converters
                                                      (if powered up), before allowing a scan to start.
                                                      The available range is 0 to 63 . */
    uint32_t u32EnabledInterruptMask;            /*!< The mask of the interrupts to be enabled,
                                                      should be the OR'ed value of @ref _cadc_interrupt_enable. */

    /* The following 3 members define scan related options. */
    cadc_scan_mode_t eScanMode;                      /*!< The scan mode of the module. */
    cadc_sample_slot_disabled_t uDisabledSampleSlot; /*!< The member used to config the which sample slot is disabled
                                                              for the scan. The scan will continue until the first
                                                              disabled sample slot is encountered. */
    cadc_scan_control_t uScanControl;                /*!< Scan control provides the ability to pause and await a new
                                                              sync signal while current sample completed. */

    /* The following 2 members define channel related options. */
    uint32_t u32ChannelModeMask;                               /*!< The mask of each channel's mode, should be the
                                                                        OR'ed value of cadc_channel_mode_t.
                                                                        Each channel supports single-end and
                                                                        differential(Fully differentail and Unipolar
                                                                        differential). Some devices also support alternate
                                                                        source mode.
                                                                         */
    cadc_channel_gain_t eChannelGain[CADC_SAMPLE_SLOTS_COUNT]; /*!< The gain value for each channel. Each element of
                                                                        the array represents the gain of the channel.
                                                                        E.g.  eChannelGain[0] means channel gain of
                                                                         channel0, which is ANA0. */

    /* The following member defines sample Slot related options. */
    cadc_channel_number_t eSampleSlot[CADC_SAMPLE_SLOTS_COUNT]; /*!< The channel assigned to each sample slot. The
                                                                    index of the array represents sample slot index. */

    /* The following 2 members define converters related options. */
    cadc_converter_config_t sConverterA; /*!< The configuration for converterA. */
    cadc_converter_config_t sConverterB; /*!< The configuration for converterB. */
} cadc_config_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization and deinitialization Interfaces
 * @{
 */

/*!
 * @brief Initializes the CADC module, such as scan mode, DMA trigger source, interrupt mask and so on.
 *
 * This function is to make the initialization for using CADC module.
 * The operations are:
 *  - Enable the clock for CADC.
 *  - Set power up delay and Idle work mode.
 *  - Set DMA trigger source.
 *  - Enable the interrupts(Including High/Low limit interrupt, zero crossing interrupt interrupt, end of scan interrupt
 *    and each sample slot's scan interrupt).
 *  - Set scan mode.
 *  - Set disabled sample slot for the scan.
 *  - Set scan control options.
 *  - Set selected channels' mode.
 *  - Set gain for each channel.
 *  - Config conterA and converterB.
 *
 * @note The high limit value, low limit value, offset value and zerocrossing mode of each sample slot
 * will not be configured in this function, to set those options, the APIs in "Sample Slot Control Interfaces"
 * function group can be used.
 *
 * @param base   CADC peripheral base address.
 * @param psConfig Pointer to configuration structure. See @ref cadc_config_t.
 */
void CADC_Init(ADC_Type *base, const cadc_config_t *psConfig);

/*!
 * @brief Gets an available pre-defined options(such as scan mode, DMA trigger source, interrupt mask and so on) for
 * module's configuration.
 *
 * This function initializes the module's configuration structure with an available settings.
 * The default value are:
 *  @code
        psConfig->eDMATriggerSource = kCADC_DMATrigSrcEndofScan;
        psConfig->eIdleWorkMode = kCADC_IdleKeepNormal;
        psConfig-s>u16PowerUpDelay = 26U;
        psConfig->u32EnabledInterruptMask = 0U;
        psConfig->eScanMode = kCADC_ScanModeTriggeredParallelSimultaneous;
        psConfig->uDisabledSampleSlot.u32SampleDisVal = 0xFF0F0UL;
        psConfig->uScanControl.u32ScanCtrlVal         = 0x0UL;
        psConfig->eChannelGain[x] = kCADC_SignalGainX1;
        psConfig->sampleSlotScanInterruptEnableMask = kCADC_NonSampleSlotMask;
        For the default setting of converter, please see CADC_GetConverterDefaultConfig().
    @endcode
 *
 * @param psConfig Pointer to configuration structure. See @ref cadc_config_t.
 */
void CADC_GetDefaultConfig(cadc_config_t *psConfig);

/*!
 * @brief De-initializes the CADC module, including power down both converter and disable the clock(Optional).
 *
 * This function is to make the de-initialization for using CADC module.
 * The operations are:
 *  - Power down both converter.
 *  - Disable the clock for CADC.
 *
 * @param base CADC peripheral base address.
 */
void CADC_Deinit(ADC_Type *base);

/*! @} */

/*!
 * @name Scan related Interfaces
 * @{
 */

/*!
 * @brief Sets the scan mode(such as Sequential scan mode, Simultaneous parallel scan mode, Independent parallel scan
 * mode) of dual converters.
 *
 * @param base CADC peripheral base address.
 * @param eScanMode Dual converters' scan mode, please see @ref cadc_scan_mode_t for details.
 */
static inline void CADC_SetScanMode(ADC_Type *base, cadc_scan_mode_t eScanMode)
{
    if (eScanMode > kCADC_ScanModeTriggeredParallelIndependent)
    {
        base->CTRL1 =
            (((uint16_t)(base->CTRL1 & ~(ADC_CTRL1_SMODE_MASK))) | ADC_CTRL1_SMODE((uint16_t)eScanMode >> 4U));
        base->CTRL2 |= ADC_CTRL2_SIMULT_MASK;
    }
    else
    {
        base->CTRL1 = (((uint16_t)(base->CTRL1 & ~(ADC_CTRL1_SMODE_MASK))) | ADC_CTRL1_SMODE(eScanMode));
        base->CTRL2 &= ~(uint16_t)ADC_CTRL2_SIMULT_MASK;
    }
}

/*!
 * @brief The function provides the ability to pause and await new sync in the conversion sequence.
 *
 * @param base CADC peripheral base address.
 * @param uScanControl The scan control value, please refer to @ref cadc_scan_control_t for details.
 */
static inline void CADC_SetScanControl(ADC_Type *base, cadc_scan_control_t uScanControl)
{
    base->SCTRL = (uint16_t)(uScanControl.u32ScanCtrlVal & 0xFFFFUL);
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    base->SCTRL2 = (uint16_t)((uScanControl.u32ScanCtrlVal & 0xF0000UL) >> 16U);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*! @} */

/*!
 * @name Channel control Interfaces
 * @{
 */

/*!
 * @brief Sets mode for the specific channel(Each channel can be set as single-end, fully differential and unipolar
 * differential(Optional) mode).
 *
 * @param base CADC peripheral base address.
 * @param eChannelMode The channel mode to be set, please refer to @ref cadc_channel_mode_t for details.
 */
void CADC_SetChannelMode(ADC_Type *base, cadc_channel_mode_t eChannelMode);

/*!
 * @brief Sets the gain(Supports X1, X2, X4) of selected channel.
 *
 * @param base CADC peripheral base address.
 * @param eChannelNumber The number of channel, please refer to @ref cadc_channel_number_t.
 * @param eChannelGain The gain amplification, please refer to @ref cadc_channel_gain_t for details.
 */
void CADC_SetChannelGain(ADC_Type *base, cadc_channel_number_t eChannelNumber, cadc_channel_gain_t eChannelGain);

/*! @} */

/*!
 * @name Sample Slot Control Interfaces
 * @{
 */

/*!
 * @brief Gets sample slot default configuration including zero crossing mode, high limit value, low limit value and
 * offset value.
 *
 * @code
        psConfig->eZeroCrossingMode = kCADC_ZeroCrossingDisabled;
        psConfig->u16HighLimitValue  = 0x7FF8U;
        psConfig->u16LowLimitValue   = 0x0U;
        psConfig->u16OffsetValue     = 0x0U;
    @endcode
 *
 * @param psConfig      Pointer to configuration structure. See @ref cadc_sample_slot_config_t.
 */
void CADC_GetSampleSlotDefaultConfig(cadc_sample_slot_config_t *psConfig);

/*!
 * @brief Configures the options(including zero crossing mode, high limit value, low limit value and offset value) for
 * sample slot.
 *
 * @note This function can be used to set high limit value, low limit value,
 * offset value and zerocrossing mode of the sample slot.
 *
 * @param base        CADC peripheral base address.
 * @param eSampleIndex Index of sample slot in conversion sequence. Please refer to @ref cadc_sample_slot_index_t.
 * @param psConfig      Pointer to configuration structure. See @ref cadc_sample_slot_config_t.
 */
void CADC_SetSampleSlotConfig(ADC_Type *base,
                              cadc_sample_slot_index_t eSampleIndex,
                              const cadc_sample_slot_config_t *psConfig);

/*!
 * @brief Sets zero-crossing mode for the selected sample slot.
 *
 * @param base CADC peripheral base address.
 * @param eSampleIndex The index of sample slot. Please refer to @ref cadc_sample_slot_index_t for details.
 * @param eZeroCrossingMode Zero crossing mode, please refer to @ref cadc_sample_slot_zero_crossing_mode_t for details.
 */
void CADC_SetSampleSlotZeroCrossingMode(ADC_Type *base,
                                        cadc_sample_slot_index_t eSampleIndex,
                                        cadc_sample_slot_zero_crossing_mode_t eZeroCrossingMode);

/*!
 * @brief Routes the channel to the sample slot.
 *
 * @param base CADC peripheral base address.
 * @param eSampleIndex The index of sample slot, please refer to @ref cadc_sample_slot_index_t for details.
 * @param eChannelNumber Sample channel number, please refer to @ref cadc_channel_number_t for details.
 */
void CADC_RouteChannelToSampleSlot(ADC_Type *base,
                                   cadc_sample_slot_index_t eSampleIndex,
                                   cadc_channel_number_t eChannelNumber);

/*!
 * @brief Sets the low limit value(-32768 ~ 32767 with lower three bits of fixed value 0) for the specific sample slot.
 *
 * @param base CADC peripheral base address.
 * @param eSampleIndex The index of sample slot. Please refer to @ref cadc_sample_slot_index_t for details.
 * @param u16LowLimitValue Low limit value(-32768 ~ 32767 with lower three bits of fixed value 0). Original value
 * formation as hardware register, with 3-bits left shifted.
 */
static inline void CADC_SetSampleSlotLowLimitValue(ADC_Type *base,
                                                   cadc_sample_slot_index_t eSampleIndex,
                                                   uint16_t u16LowLimitValue)
{
    if ((uint16_t)eSampleIndex < ADC_RSLT_COUNT)
    {
        base->LOLIM[(uint16_t)eSampleIndex] = u16LowLimitValue;
    }
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    else
    {
        base->LOLIM2[(uint16_t)eSampleIndex - ADC_RSLT_COUNT] = u16LowLimitValue;
    }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Sets the high limit value(-32768 ~ 32767 with lower three bits of fixed value 0) for the specific sample slot.
 *
 * @param base CADC peripheral base address.
 * @param eSampleIndex The index of sample slot. Please refer to @ref cadc_sample_slot_index_t for details.
 * @param u16HighLimitValue High limit value(-32768 ~ 32767 with lower three bits of fixed value 0). Original value
 * formation as hardware register, with 3-bits left shifted.
 */
static inline void CADC_SetSampleSlotHighLimitValue(ADC_Type *base,
                                                    cadc_sample_slot_index_t eSampleIndex,
                                                    uint16_t u16HighLimitValue)
{
    if ((uint16_t)eSampleIndex < ADC_RSLT_COUNT)
    {
        base->HILIM[(uint16_t)eSampleIndex] = u16HighLimitValue;
    }
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    else
    {
        base->HILIM2[(uint16_t)eSampleIndex - ADC_RSLT_COUNT] = u16HighLimitValue;
    }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Sets the offset value(-32768 ~ 32767 with lower three bits of fixed value 0) for the specific sample slot.
 *
 * @param base CADC peripheral base address.
 * @param eSampleIndex The index of sample slot. Please refer to @ref cadc_sample_slot_index_t for details.
 * @param u16OffsetValue Offset value(-32768 ~ 32767 with lower three bits of fixed value 0). Original value formation
 * as hardware register, with 3-bits left shifted.
 */
static inline void CADC_SetSampleSlotOffsetValue(ADC_Type *base,
                                                 cadc_sample_slot_index_t eSampleIndex,
                                                 uint16_t u16OffsetValue)
{
    if ((uint16_t)eSampleIndex < ADC_RSLT_COUNT)
    {
        base->OFFST[(uint16_t)eSampleIndex] = u16OffsetValue;
    }
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    else
    {
        base->OFFST2[(uint16_t)eSampleIndex - ADC_RSLT_COUNT] = u16OffsetValue;
    }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Gets the sample result value.
 *
 * This function is to get the sample result value. The returned value keeps it original formation just like in
 * hardware result register. It includes the sign bit as the MSB and 3-bit left shifted value.
 *
 * @param  base        CADC peripheral base address.
 * @param  eSampleIndex Index of sample slot. For the counts of sample slots,
 *                     please refer to @ref cadc_sample_slot_index_t for details.
 * @return Sample's conversion value.
 */
static inline uint16_t CADC_GetSampleSlotResultValue(ADC_Type *base, cadc_sample_slot_index_t eSampleIndex)
{
    uint16_t u16Ret = 0U;

    if ((uint16_t)eSampleIndex < ADC_RSLT_COUNT)
    {
        u16Ret = (uint16_t)(base->RSLT[(uint16_t)eSampleIndex]);
    }
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    else
    {
        u16Ret = (uint16_t)(base->RSLT2[((uint16_t)eSampleIndex - ADC_RSLT_COUNT)]);
    }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
    return u16Ret;
}
/*! @} */

/*!
 * @name Converters Control Interfaces
 * @{
 */

/*!
 * @brief Gets available pre-defined settings(such as clock divisor, reference voltage source, and so on) for each
 * converter's configuration.
 *
 * This function initializes each converter's configuration structure with an available settings.
 * The default value are:
 * @code
        psConfig->u16ClockDivisor = 4U;(ADC clock = Peripheral clock / 5)
        psConfig->eSpeedMode = kCADC_SpeedMode0; (Chip specific)
        psConfig->eHighReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
        psConfig->eLowReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
        psConfig->u16SampleWindowCount = 0U; (Chip specific)
        psConfig->bEnableDMA         = false;
        psConfig->bPowerUp   = false;
        psConfig->bScanInitBySync  = true;
    @endcode
 * @param psConfig Pointer to configuration structure. See @ref cadc_converter_config_t.
 */
void CADC_GetConverterDefaultConfig(cadc_converter_config_t *psConfig);

/*!
 * @brief Configures the options(such as clock divisor, reference voltage source, and so on) for the converter.
 *
 * This function can be used to configure the converter
 * The operations are:
 *  - Set clock divisor;
 *  - Set reference voltage source
 *  - Enable/Disable DMA
 *  - Power-up/power-down converter
 *
 * @param base          CADC peripheral base address.
 * @param eConverterId The converter Id. See @ref cadc_converter_id_t.
 * @param psConfig        Pointer to configuration structure. See @ref cadc_converter_config_t.
 */
void CADC_SetConverterConfig(ADC_Type *base, cadc_converter_id_t eConverterId, const cadc_converter_config_t *psConfig);

/*!
 * @brief Changes the converter to stop mode or normal mode.
 *
 * The conversion should only be launched after the converter is in normal mode. When in stop mode, the current scan is
 * stopped and no further scans can start. All the software trigger and hardware trigger are ignored.
 *
 * @param base          CADC peripheral base address.
 * @param eConverterId The converter Id. See @ref cadc_converter_id_t.
 * @param bEnable       Used to change the operation mode.
 *                      - \b true Changed to normal mode.
 *                      - \b false Changed to stop mode
 */
static inline void CADC_EnableConverter(ADC_Type *base, cadc_converter_id_t eConverterId, bool bEnable)
{
    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        if (bEnable)
        {
            base->CTRL1 &= ~(uint16_t)ADC_CTRL1_STOP0_MASK; /* Clear STOP to enable. */
        }
        else
        {
            base->CTRL1 |= ADC_CTRL1_STOP0_MASK;
        }
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        if (bEnable)
        {
            base->CTRL2 &= ~(uint16_t)ADC_CTRL2_STOP1_MASK; /* Clear STOP to enable. */
        }
        else
        {
            base->CTRL2 |= ADC_CTRL2_STOP1_MASK;
        }
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

/*!
 * @brief Enables/Disables the external sync input pulse to initiate a scan.
 *
 * @note When in "Once" scan mode, this gate would be off automatically after an available sync is received. User needs
 * to enable the input again manually if another sync signal is wanted.
 *
 * @param base          CADC peripheral base address.
 * @param eConverterId The converter Id. See @ref cadc_converter_id_t.
 * @param bEnable        Enable the feature or not.
 *                      - \b true Used a SYNC input pulse or START command to initiate a scan.
 *                      - \b false Only use the START command to initiate a scan.
 */
static inline void CADC_EnableConverterSyncInput(ADC_Type *base, cadc_converter_id_t eConverterId, bool bEnable)
{
    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        if (bEnable)
        {
            base->CTRL1 |= ADC_CTRL1_SYNC0_MASK;
        }
        else
        {
            base->CTRL1 &= ~(uint16_t)ADC_CTRL1_SYNC0_MASK;
        }
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        if (bEnable)
        {
            base->CTRL2 |= ADC_CTRL2_SYNC1_MASK;
        }
        else
        {
            base->CTRL2 &= ~(uint16_t)ADC_CTRL2_SYNC1_MASK;
        }
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

/*!
 * @brief Uses software trigger to start a conversion sequence.
 *
 * This function is to do the software trigger to the converter. The software trigger can used to start a conversion
 * sequence.
 *
 * @param base          CADC peripheral base address.
 * @param eConverterId The ID of the converter to be started. See @ref cadc_converter_id_t.
 */
static inline void CADC_DoSoftwareTriggerConverter(ADC_Type *base, cadc_converter_id_t eConverterId)
{
    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        base->CTRL1 |= ADC_CTRL1_START0_MASK;
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        base->CTRL2 |= ADC_CTRL2_START1_MASK;
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

/*!
 * @brief Sets clock divisor(Range from 0 to 63) for converterA and conveter B.
 *
 * @param base CADC peripheral base address.
 * @param eConverterId The converter Id. See @ref cadc_converter_id_t.
 * @param u16ClockDivisor Converter's clock divisor for the clock source.Available setting range is 0-63.
 *                           - When the clockDivisor is 0, the divisor is 2.
 *                           - For all other clockDivisor values, the divisor is 1 more than the decimal value of
 *                               clockDivisor: clockDivisor + 1
 */
static inline void CADC_SetConverterClockDivisor(ADC_Type *base,
                                                 cadc_converter_id_t eConverterId,
                                                 uint16_t u16ClockDivisor)
{
    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        base->CTRL2 = ((base->CTRL2 & (~(uint16_t)ADC_CTRL2_DIV0_MASK)) | ADC_CTRL2_DIV0(u16ClockDivisor));
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        base->PWR2 = (base->PWR2 & (uint16_t)(~ADC_PWR2_DIV1_MASK)) | ADC_PWR2_DIV1(u16ClockDivisor);
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

/*!
 * @brief Sets converter's reference voltage source(Including high reference voltage source and low reference voltage
 * source).
 *
 * @param base CADC peripheral base address.
 * @param eConverterId The converter Id. See @ref cadc_converter_id_t.
 * @param eHighReferenceVoltage High voltage reference source, please refer to @ref cadc_reference_voltage_source_t.
 * @param eLowReferenceVoltage  Low voltage reference source, please refer to @ref cadc_reference_voltage_source_t.
 */
void CADC_SetConverterReferenceVoltageSource(ADC_Type *base,
                                             cadc_converter_id_t eConverterId,
                                             cadc_reference_voltage_source_t eHighReferenceVoltage,
                                             cadc_reference_voltage_source_t eLowReferenceVoltage);

/*!
 * @brief Powers up/down the specific converter.
 *
 * This function is to enable the power for the converter. The converter should be powered up before the conversion.
 * Once this API is called to power up the converter, the converter would be powered on after a few moment (so-called
 * power up delay, the function CADC_SetPowerUpDelay() can be used to set the power up delay), so that the power would
 * be stable.
 *
 * @param base          CADC peripheral base address.
 * @param eConverterId The converter to be powered. See @ref cadc_converter_id_t.
 * @param bEnable       Powers up/down the converter.
 *                      - \b true Power up the specific converter.
 *                      - \b false Power down the specific converter.
 */
void CADC_EnableConverterPower(ADC_Type *base, cadc_converter_id_t eConverterId, bool bEnable);

/*!
 * @brief Enables/Disables the converter's DMA feature.
 *
 * @param base          CADC peripheral base address.
 * @param eConverterId  The converter id. See @ref cadc_converter_id_t.
 * @param bEnable        Enables/Disables the DMA.
 *                       - \b true Enable the converter's DMA.
 *                       - \b false Disable the converter's DMA.
 */
static inline void CADC_EnableConverterDMA(ADC_Type *base, cadc_converter_id_t eConverterId, bool bEnable)
{
    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        if (bEnable)
        {
            base->CTRL1 |= ADC_CTRL1_DMAEN0_MASK;
        }
        else
        {
            base->CTRL1 &= ~(uint16_t)ADC_CTRL1_DMAEN0_MASK;
        }
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        if (bEnable)
        {
            base->CTRL2 |= ADC_CTRL2_DMAEN1_MASK;
        }
        else
        {
            base->CTRL2 &= ~(uint16_t)ADC_CTRL2_DMAEN1_MASK;
        }
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
/*!
 * @brief Configures selected converter's expansion mux and aux settings.
 *
 * @param base ADC peripheral base address.
 * @param eConverterId The converter id, see @ref cadc_converter_id_t.
 * @param psMuxAuxConfig Pointer to @ref cadc_exp_mux_aux_config_t structure.
 */
void CADC_SetConverterMuxAuxConfig(ADC_Type *base,
                                   cadc_converter_id_t eConverterId,
                                   const cadc_exp_mux_aux_config_t *psMuxAuxConfig);

/*!
 * @brief Resets selected converter's expansion mux scan.
 *
 * @param base ADC peripheral base address.
 * @param eConverterId The converter id, see @ref cadc_converter_id_t.
 */
static inline void CADC_ResetConverterExpMuxScan(ADC_Type *base, cadc_converter_id_t eConverterId)
{
    if (eConverterId == kCADC_ConverterA)
    {
        base->EXPCFG |= ADC_EXPCFG_MUXARST_MASK;
        base->EXPCFG &= ~ADC_EXPCFG_MUXARST_MASK;
    }
    else
    {
        base->EXPCFG |= ADC_EXPCFG_MUXBRST_MASK;
        base->EXPCFG &= ~ADC_EXPCFG_MUXBRST_MASK;
    }
}

/*!
 * @brief Sets selected converter's expansion mux operate mode.
 *
 * @param base ADC peripheral base address.
 * @param eConverterId The converter id, see @ref cadc_converter_id_t.
 * @param eOperateMode Used to set expansion mux operate mode.
 */
static inline void CADC_SetConverterExpansionMuxOperateMode(ADC_Type *base,
                                                            cadc_converter_id_t eConverterId,
                                                            cadc_expansion_mux_operate_mode_t eOperateMode)
{
    uint16_t u16Tmp;

    if (eConverterId == kCADC_ConverterA)
    {
        u16Tmp = (base->EXPCFG) & ~(ADC_EXPCFG_MUXSCTR4A_MASK);
        u16Tmp |= ADC_EXPCFG_MUXSCTR4A(eOperateMode);
        base->EXPCFG = u16Tmp;
    }
    else
    {
        u16Tmp = (base->EXPCFG) & ~(ADC_EXPCFG_MUXSCTR4B_MASK);
        u16Tmp |= ADC_EXPCFG_MUXSCTR4B(eOperateMode);
        base->EXPCFG = u16Tmp;
    }
}

/*!
 * @brief Sets selected converter's auxiliary control set.
 *
 * @param base ADC peripheral base address.
 * @param eConverterId The converter id, see @ref cadc_converter_id_t.
 * @param u16AuxControl The mask of auxiliary control, should be the OR'ed value of @ref cadc_auxiliary_control_t.
 */
static inline void CADC_SetConverterAuxiliaryControl(ADC_Type *base,
                                                     cadc_converter_id_t eConverterId,
                                                     uint16_t u16AuxControl)
{
    if (eConverterId == kCADC_ConverterA)
    {
        base->EXPAUX4A = u16AuxControl;
    }
    else
    {
        base->EXPAUX4B = u16AuxControl;
    }
}

#if !(defined(FSL_FEATURE_CADC_HAS_EXP_MUX_SEL) && (FSL_FEATURE_CADC_HAS_EXP_MUX_SEL == 0))
/*!
 * @brief Sets selected converter's mux channels.
 *
 * @param base ADC peripheral base address.
 * @param eConverterId The converter id, see @ref cadc_converter_id_t.
 * @param u32MuxChannelMask The mask of mux selection of all mux solts, should be
 *                          the OR'ed value of @ref cadc_expansion_mux_selection_t.
 */
static inline void CADC_SetConverterMuxChannels(ADC_Type *base,
                                                cadc_converter_id_t eConverterId,
                                                uint32_t u32MuxChannelMask)
{
    uint16_t u16Tmp;

    if (eConverterId == kCADC_ConverterA)
    {
        u16Tmp = (base->EXPMUX4A0) & (uint16_t)(0x8888U);
        u16Tmp |= (uint16_t)(u32MuxChannelMask & 0xFFFFU);
        base->EXPMUX4A0 = u16Tmp;
        u16Tmp          = (base->EXPMUX4A1) & (uint16_t)(0x8888U);
        u16Tmp |= (uint16_t)((u32MuxChannelMask & 0xFFFF0000U) >> 16U);
        base->EXPMUX4A1 = u16Tmp;
    }
    else
    {
        u16Tmp = (base->EXPMUX4B0) & (uint16_t)(0x8888U);
        u16Tmp |= (uint16_t)(u32MuxChannelMask & 0xFFFFU);
        base->EXPMUX4B0 = u16Tmp;
        u16Tmp          = (base->EXPMUX4B1) & (uint16_t)(0x8888U);
        u16Tmp |= (uint16_t)((u32MuxChannelMask & 0xFFFF0000U) >> 16U);
        base->EXPMUX4B1 = u16Tmp;
    }
}
#endif /* FSL_FEATURE_CADC_HAS_EXP_MUX_SEL */

/*!
 * @brief Set selected converter's mux and aux disabled slot.
 *
 * @param base ADC peripheral base address.
 * @param eConverterId The converter id, see @ref cadc_converter_id_t.
 * @param eDisabledMuxSlot The mux slot to disabled, please refer to @ref cadc_expansion_disabled_mux_slot_t.
 */
static inline void CADC_SetExpansionMuxAuxDisabledSlot(ADC_Type *base,
                                                       cadc_converter_id_t eConverterId,
                                                       cadc_expansion_disabled_mux_slot_t eDisabledMuxSlot)
{
    if (eConverterId == kCADC_ConverterA)
    {
        if (eDisabledMuxSlot <= kCADC_ExpMux3Disable)
        {
            base->EXPMUX4A0 = ((base->EXPMUX4A0 & 0x7777U) | (uint16_t)(1UL << ((uint16_t)eDisabledMuxSlot)));
        }
        else
        {
            base->EXPMUX4A1 = ((base->EXPMUX4A1 & 0x7777U) | (uint16_t)(1UL << (((uint16_t)eDisabledMuxSlot) - 16U)));
        }
    }
    else
    {
        if (eDisabledMuxSlot <= kCADC_ExpMux3Disable)
        {
            base->EXPMUX4B0 = ((base->EXPMUX4B0 & 0x7777U) | (uint16_t)(1UL << ((uint16_t)eDisabledMuxSlot)));
        }
        else
        {
            base->EXPMUX4B1 = ((base->EXPMUX4B1 & 0x7777U) | (uint16_t)(1UL << (((uint16_t)eDisabledMuxSlot) - 16U)));
        }
    }
}
#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */
/*! @} */

/*!
 * @name Power Control Interfaces
 * @{
 */

/*!
 * @brief Sets power up delay(The number of ADC clocks to power up the converters before allowing a scan to start).
 *
 * @param base CADC peripheral base address.
 * @param u16PowerUpDelay The number of ADC clocks to power up an ADC converter. Ranges from 0 to 63.
 */
static inline void CADC_SetPowerUpDelay(ADC_Type *base, uint16_t u16PowerUpDelay)
{
    base->PWR = ((base->PWR & (uint16_t)(~ADC_PWR_PUDELAY_MASK)) | ADC_PWR_PUDELAY(u16PowerUpDelay));
}

/*!
 * @brief Enables/Disables auto-powerdown converters when the module is not in use for a scan.
 *
 * @param base CADC peripheral base address.
 * @param bEnable Enable/Disable auto-powerdown mode.
 *                - \b true Enable auto-powerdown mode, so when the module is not in use, it will auto-powerdown.
 *                - \b false Disable auto-powerdown mode, so when the module is not in use, the power will still on.
 */
static inline void CADC_EnableAutoPowerDownMode(ADC_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->PWR |= ADC_PWR_APD_MASK;
    }
    else
    {
        base->PWR &= (~(uint16_t)ADC_PWR_APD_MASK);
    }
}

/*! @} */

/*!
 * @name DMA Control Interfaces
 * @{
 */

/*!
 * @brief Sets DMA trigger source(available selections are "End of scan" and "Sample Ready").
 *
 * @param base CADC peripheral base address.
 * @param eDMATriggerSource DMA trigger source. Please refer to @ref cadc_dma_trigger_source_t for details.
 */
static inline void CADC_SetDMATriggerSource(ADC_Type *base, cadc_dma_trigger_source_t eDMATriggerSource)
{
    if (kCADC_DMATrigSrcSampleReady == eDMATriggerSource)
    {
        base->CTRL3 |= ADC_CTRL3_DMASRC_MASK;
    }
    else /* kCADCDmaTriggerSourceAsEndOfScan. */
    {
        base->CTRL3 &= ~(uint16_t)ADC_CTRL3_DMASRC_MASK;
    }
}

/*! @} */

/*!
 * @name Interrupt Control Interfaces
 * @{
 */

/*!
 * @brief Enables the interrupts(such as high/low limit interrupts, end of scan interrupts, and so on).
 *
 * @param base CADC peripheral base address.
 * @param u32Mask Mask value for converters interrupt events. Should be the OR'ed value of @ref _cadc_interrupt_enable.
 */
static inline void CADC_EnableInterrupts(ADC_Type *base, uint32_t u32Mask)
{
    if ((u32Mask & 0xFFFFUL) != 0UL)
    {
        base->SCHLTEN |= (uint16_t)(u32Mask & 0xFFFFUL);
    }
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    if ((u32Mask & 0xF0000UL) != 0UL)
    {
        base->SCHLTEN2 |= (uint16_t)((u32Mask & 0xF0000UL) >> 16UL);
    }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
    if ((u32Mask & 0xF000000UL) != 0UL)
    {
        base->CTRL1 |= (uint16_t)((u32Mask & 0xF000000UL) >> 16UL);
    }
    if ((u32Mask & 0xF00000UL) != 0UL)
    {
        base->CTRL2 |= (uint16_t)((u32Mask & 0xF00000UL) >> 12UL);
    }
#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
    if ((u32Mask & 0x30000000UL) != 0UL)
    {
        base->EXPCFG |= (uint16_t)((u32Mask & 0x30000000UL) >> 28UL);
    }
#endif /* (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) */
}

/*!
 * @brief Disables the interrupts(such as high/low limit interrupts, end of scan interrupts, and so on).
 *
 * @param base CADC peripheral base address.
 * @param u32Mask Mask value for converts interrupt events. Should be the OR'ed value of @ref _cadc_interrupt_enable.
 */
static inline void CADC_DisableInterrupts(ADC_Type *base, uint32_t u32Mask)
{
    if ((u32Mask & 0xFFFFUL) != 0UL)
    {
        base->SCHLTEN &= (uint16_t) ~(u32Mask & 0xFFFFUL);
    }
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    if ((u32Mask & 0xF0000UL) != 0UL)
    {
        base->SCHLTEN2 &= (uint16_t) ~((u32Mask & 0xF0000UL) >> 16UL);
    }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
    if ((u32Mask & 0xF000000UL) != 0UL)
    {
        base->CTRL1 &= (uint16_t) ~((u32Mask & 0xF000000UL) >> 16UL);
    }
    if ((u32Mask & 0xF00000UL) != 0UL)
    {
        base->CTRL2 &= (uint16_t) ~((u32Mask & 0xF00000UL) >> 12UL);
    }
#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
    if ((u32Mask & 0x30000000UL) != 0UL)
    {
        base->EXPCFG &= (uint16_t) ~((u32Mask & 0x30000000UL) >> 28UL);
    }
#endif /* (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) */
}

/*! @} */

/*!
 * @name ADC Status Flag Interfaces
 * @{
 */
/*!
 * @brief  Gets Miscellaneous status flags, such as end of scan status flag, high/low limit interrupt flags and so on.
 *
 * @note This API will return the current status of the ADC module, including high limit interrupt status,
 * low limit status flag, zero crossing interrupt status, End of scan interrupt status, conversion in progress status.
 * But some status flags are not included in this function. To get sample slot ready status flag, please invoking
 * CADC_GetSampleSlotReadyStatusFlags(), to get sample slot limit violations status please invoking
 * CADC_ClearSampleSlotLowLimitStatusFlags() and CADC_GetSampleSlotHighLimitStatusFlags(), to get zerocrossing status
 * please invoking CADC_GetSampleSlotZeroCrossingStatusFlags(). To get converters' power status please invoke
 * CADC_GetPowerStatusFlag().
 *
 * @param  base CADC peripheral base address.
 * @return Mask value for the event flags. See @ref _cadc_misc_status_flags.
 */
static inline uint16_t CADC_GetMiscStatusFlags(ADC_Type *base)
{
    return ((base->STAT) & 0xFF00U);
}

/*!
 * @brief Clears Miscellaneous status flags(Only for "end of scan" status flags).
 *
 * @note Only kCADC_ConverterAEndOfScanFlag and kCADC_ConverterBEndOfScanFlag can be cleared. And sample slot related
 * status flags can not be cleared in this function. To clear the status flags of limit violations, please invoking
 * CADC_ClearSampleSlotLowLimitStatusFlags() and CADC_ClearSampleSlotHighLimitStatusFlags(), to clear the status flags
 * of zero crossing mode, please invoking CADC_ClearSampleSlotZeroCrossingStatusFlags().
 *
 * @param base  CADC peripheral base address.
 * @param u16Flags Mask value for the event flags to be cleared. See @ref _cadc_misc_status_flags.
 *              Only the enumeration @ref kCADC_ConverterAEndOfScanFlag and @ref kCADC_ConverterBEndOfScanFlag are
 *              useful.
 */
static inline void CADC_ClearMiscStatusFlags(ADC_Type *base, uint16_t u16Flags)
{
    base->STAT = (u16Flags & 0x1800U);
}

/*!
 * @brief Gets sample slots ready status flag, those status flags are cleared by reading the corresponding sample slots'
 *  result.
 *
 * @param base CADC peripheral base address.
 */
static inline uint32_t CADC_GetSampleSlotReadyStatusFlags(ADC_Type *base)
{
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && FSL_FEATURE_CADC_RSLT2_COUNT)
    return (((uint32_t)((uint32_t)ADC_RDY_RDY_MASK & base->RDY)) |
            ((((base->RDY2 & (uint32_t)ADC_RDY2_RDY_MASK)) << 16UL)));
#else
    return ((uint32_t)ADC_RDY_RDY_MASK & base->RDY);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Gets sample slot low limit status flags(Each bit represents one sample slot).
 *
 * @param base CADC peripheral base address.
 * @return The value of all sample slots' low limit status. Each bit represents one sample slot.
 */
static inline uint32_t CADC_GetSampleSlotLowLimitStatusFlags(ADC_Type *base)
{
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    return (((uint32_t)((uint32_t)ADC_LOLIMSTAT_LLS_MASK & base->LOLIMSTAT)) |
            ((((base->LOLIMSTAT2 & (uint32_t)ADC_LOLIMSTAT2_LLS_MASK)) << ADC_RSLT_COUNT)));
#else
    return ((uint32_t)ADC_LOLIMSTAT_LLS_MASK & base->LOLIMSTAT);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Clears sample slot's low limit status flags(Each bit represents one sample slot).
 *
 * @param base CADC peripheral base address.
 * @param u32SampleMask Mask value of sample slots. This parameter should be the OR'ed value of @ref
 * cadc_sample_slot_mask_t.
 */
static inline void CADC_ClearSampleSlotLowLimitStatusFlags(ADC_Type *base, uint32_t u32SampleMask)
{
    base->LOLIMSTAT = ADC_LOLIMSTAT_LLS(u32SampleMask & 0xFFFFU);
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    base->LOLIMSTAT2 = ADC_LOLIMSTAT2_LLS((u32SampleMask >> ADC_RSLT_COUNT) & 0xFFFFU);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Gets sample slot high limit status flags(Each bit represents one sample slot).
 *
 * @param base CADC peripheral base address.
 * @return The value of all sample slots' high limit status. Each bit represents each sample slot.
 */
static inline uint32_t CADC_GetSampleSlotHighLimitStatusFlags(ADC_Type *base)
{
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    return (((uint32_t)((uint32_t)ADC_HILIMSTAT_HLS_MASK & base->HILIMSTAT)) |
            ((((base->HILIMSTAT2 & (uint32_t)ADC_HILIMSTAT2_HLS_MASK)) << ADC_RSLT_COUNT)));
#else
    return ((uint32_t)ADC_HILIMSTAT_HLS_MASK & base->HILIMSTAT);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Clears sample slot's high limit status flags(Each bit represents one sample slot).
 *
 * @param base CADC peripheral base address.
 * @param u32SampleMask Mask value of sample slots. This parameter should be the OR'ed value of @ref
 * cadc_sample_slot_mask_t.
 */
static inline void CADC_ClearSampleSlotHighLimitStatusFlags(ADC_Type *base, uint32_t u32SampleMask)
{
    base->HILIMSTAT = ADC_HILIMSTAT_HLS(u32SampleMask & 0xFFFFU);
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    base->HILIMSTAT2 = ADC_HILIMSTAT2_HLS((u32SampleMask >> ADC_RSLT_COUNT) & 0xFFFFU);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Gets sample slot zero crossing status flags(Each bit represents one sample slot).
 *
 * @param base CADC peripheral base address.
 * @return The value of all sample slots' zero crossing status. Each bit represents each sample slot.
 */
static inline uint32_t CADC_GetSampleSlotZeroCrossingStatusFlags(ADC_Type *base)
{
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    return (((uint32_t)((uint32_t)ADC_ZXSTAT_ZCS_MASK & base->ZXSTAT)) |
            ((((base->ZXSTAT2 & (uint32_t)ADC_ZXSTAT2_ZCS_MASK)) << ADC_RSLT_COUNT)));
#else
    return ((uint32_t)ADC_ZXSTAT_ZCS_MASK & base->ZXSTAT);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Clears sample slot's zero crossing status flags(Each bit represents one sample slot).
 *
 * @param base CADC peripheral base address.
 * @param u32SampleMask Mask value of sample slots. This parameter should be the OR'ed value of @ref
 * cadc_sample_slot_mask_t.
 */
static inline void CADC_ClearSampleSlotZeroCrossingStatusFlags(ADC_Type *base, uint32_t u32SampleMask)
{
    base->ZXSTAT = ADC_ZXSTAT_ZCS(u32SampleMask & 0xFFFFU);
#if ((defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U)))
    base->ZXSTAT2 = ADC_ZXSTAT2_ZCS((u32SampleMask >> ADC_RSLT_COUNT) & 0xFFFFU);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
}

/*!
 * @brief Gets converters power status(Those power status can not be cleared).
 *
 * @param base CADC peripheral base address.
 * @return The mask value of the converters' power status flag, see @ref _cadc_converter_power_status_flags.
 */
static inline uint16_t CADC_GetPowerStatusFlags(ADC_Type *base)
{
    return (base->PWR & (ADC_PWR_PSTS0_MASK | ADC_PWR_PSTS1_MASK));
}

#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
/*!
 * @brief Gets converter's expansion mux channel scan complete status flags.
 *
 * @param base CADC peripheral base address.
 * @return uint16_t The mask value of converters' expansion mux channel scan status flags,
 *          see @ref _cadc_expansion_mux_status_flags.
 */
static inline uint16_t CADC_GetConverterExpMuxChannelScanCompStatusFlags(ADC_Type *base)
{
    return base->EXPSTAT;
}

/*!
 * @brief Clears converter's expansion mux channel scan complete status flags.
 *
 * @param base CADC peripheral base address.
 * @param u16FlagMask The mask value of @ref _cadc_expansion_mux_status_flags.
 */
static inline void CADC_ClearConverterExpMuxChannelScanCompStatusFlags(ADC_Type *base, uint16_t u16FlagMask)
{
    base->EXPSTAT = u16FlagMask;
}

#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */

/*! @} */

#if defined(__cplusplus)
}
#endif
/*!
 * @}
 */
#endif /* FSL_CADC_H_ */
