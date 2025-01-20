/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_DAC_H_
#define FSL_DAC_H_

#include "fsl_common.h"

/*!
 * @defgroup dac DAC: 12-bit Digital-to-Analog Converter Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief DAC driver version. */
#define FSL_DAC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * DAC peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup dac_driver_log The Driver Change Log
 * @ingroup dac
 * @{
 * The current DAC driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Improvements
 *     - Supported MC56F82xxx and MC56F84xxx.
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/

/*!
 * @defgroup dac_intro DAC Peripheral and Driver Overview
 * @ingroup dac
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features and how this peripheral works
 * ==================================================
 *  The 12-bit digital-to-analog converter(DAC) provides a voltage reference to on-chip modules or a package pin. It can
 *  also be used as a waveform generator to generate triangle and sawtooth waveforms. The DAC module has two different
 *  operation modes, they are Normal Mode and Automatic mode. In the Normal mode, the DAC is used to convert the digital
 *  value to analog voltage, the input data is held in a data FIFO(8 words depth), the value in data FIFO is pushed to
 *  DAC analog portion for conversion on a selected edge of an input SYNC signal. In the Automatic mode, the DAC is used
 *  to generate different types of waveforms, data FIFO is disconnected from DAC analog portion in this mode, DAC output
 *  is determined by buffered STEP, MIN and MAX value registers. The SYNC signal is used to updated STEP, MIN and MAX
 *  registers from their buffers and reset the output wavefrom as well. A fast refresh signals(generated within DAC) is
 *  used to update DAC output based on STEP, MIN and MAX. The details of those operation modes will be provided in
 *  the following sections.
 *
 *  Features
 *  ---------
 *  + Supports two different types of SYNC signals.
 *      The SYNC signal is used to push the data in data FIFO to analog portion of DAC for conversion in normal mode,
 *      or update STEP, MIN, MAX registers from their buffers and reset output waveform in automatic mode. The SYNC
 *      signal can be selected from internal CLOCK signal(bus clock) or SYNC_IN signal. The SYNC_IN signal is the signal
 *      that comes from other peripherals(timers, comparators, pins, or other peripherals).
 *      - Clock Signal selected as SYNC signal
 *          SYNC signal is set as clock signal, so the SYNC_IN signal is useless. The value in DATA FIFO is pushed to
 *          DAC output on the next clock cycle, which means DAC output is updated almost immediately after DATA FIFO is
 *          written into. It is not recommended to use clock signal as SYNC signal in automatic mode, because it is too
 *          fast.
 *
 *      - External SYNC_IN signal selected as SYNC signal
 *          SYNC_IN signal usually comes from crossbar output, which means it can be from various peripheral outputs or
 *          even pin through crossbar. SYNC_IN is often used in automatic mode, where the selected edge of SYNC_IN
 *          updates STEP, MIN and MAX registers from their buffers and also reset the output waveform to its start point
 *          defined by the new minimum and maximum value.
 *
 *  + Data FIFO
 *      Data written to DATA register is held in a FIFO. Based on the SYNC signal, upon the active edge of the
 *      signal(clock signal or SYNC_IN signal), the digital data contained in the FIFO is presented to the analog
 *      DAC for conversion. Reading this register returns the value of data presented to the analog DAC at that time.
 *
 *  + Buffered step size/minimum value/maximum value register
 *      STEP, MIN and MAX registers are buffered, and only useful in the automatic operation mode. The values written to
 *      these three registers are stored in their buffers, and the buffer values are updated to their registers at the
 *      active edge of the SYNC signal.
 *
 *  + Supports two different operation modes.
 *      - Normal operation mode to generate a voltage output
 *          In normal operation mode, the DAC receives data words via software writes or via DMA writes. The DMA is only
 *          useful in this mode.
 *
 *      - Automatic operation mode to generate triangle, and sawtooth waveforms
 *          In automatic operation mode, the internal waveform generation logic will be used to generate sawtooth,
 *          triangle waveforms. In this operation mode, all waveform related options are programmable.
 *          1. Maximum Value
 *             The MAX register defines the upper range limit of the waveform. If the DAC input data is greater than
 *             the maximum value, the DAC's output is limited to the maximum value during automatic waveform generation.
 *          2. Minimum Value
 *             The MIN register defines the lower range limit of the waveform. If the DAC input data is less than the
 *             minimum value, the DAC's output is limited to the minimum value during automatic waveform generation.
 *          3. Step Size
 *             The STEP register value will be added or subtracted from the DAC's current data value at the rising edge
 *             of the REFRESH signal, which is to create the next value presented to the DAC inputs.
 *          4. REFRESH signal
 *             The REFRESH signal is used to update the internal Automatic waveform generation logic. The STEP value is
 *             added to/subtracted from the current output value every REFRESH cycle. The compare register can be
 *             used to set the frequency of REFERSH signal. If the compare value is 0, then the REFRESH signal's
 *             frequency is equal to clock's frequency which is the bus clock and the generated waveform will be updated
 *             every clock cycle. If the compare value is N, then the REFRESH signal's frequency is equal to clock's
 *             frequency divided by N+1 and the generated waveform will be updated every N+1 clock cycles.
 *          5. Sawtooth waveform generation.
 *             To generate the sawtooth waveform which likes @ref kDAC_RepeatSawtoothWaveform0, the CTRL0[UP] should be
 *              set with the CTRL0[DOWN] be cleared.
 *              To generate the sawtooth waveform which likes @ref kDAC_RepeatSawtoothWaveform1, the CTRL0[DOWN] should
 *              be set with the CTRL0[UP] be cleared.
 *              To generate the sawtooth waveform which likes @ref kDAC_OneShotSawtoothWaveform0, the CTRL0[UP] should
 *              be set with the CTRL0[DOWN] be cleared. CTRL0[ONESHOT] should be set.
 *              To generate the sawtooth waveform which likes @ref kDAC_OneShotSawtoothWaveform1, the CTRL0[DOWN] should
 *              be set with the CTRL0[UP] be cleared. CTRL0[ONESHOT] should be set.
 *              Usually, SYNC signal defines the period of this waveform, while REFRESH signal defines the slope of the
 *              waveform. When oneshot is enabled, the output waveform holds the value when it reaches MAX or MIN value
 *              before the occurrence of the next SYNC signal.
 *          6. Triangle waveform generation.
 *              To generate the triangle waveform which likes @ref kDAC_RepeatTriangleWaveform0, the CTRL0[DOWN] should
 *              be set firstly then the CTRL0[UP] should be set. In this way, the generated waveform will rise from the
 *              starting value firstly then drop down upon reaching the maximum value.
 *              To generate the triangle waveform which likes @ref kDAC_RepeatTriangleWaveform1, the CTRL[UP] should be
 *              set firstly then the CTRL[DOWN] should be set. In this way, the generated waveform will drop down from
 *              the starting value firstly then rise up upon reaching the minimum value.
 *          7. Starting value
 *             The starting value of the generated waveform is programmable. Before entering Automatic operation mode,
 *             set the DAC module as Normal mode and set SYNC as clock signal, choose the active edge of SYNC signal,
 *             write the starting value to DATA register, then enter automatic mode.
 *          All the above options can be realized by invoking the DAC_Init() function.
 *          8. LDOK feature
 *             STEP, MIN, and MAX registers are updated when LDOK bit equals to 1 upon the active edge of SYNC signal,
 *             and then LDOK bit is cleared automatically. This is to make sure these 3 registers are updated
 *             simultaneously.
 *
 *  + Supports DMA
 *      - When the level of FIFO is less than or equal to the watermark level value, the DMA request will be sent(if the
 *        DMA feature is enabled). And please note that the DMA is only useful when the operation mode is selected as
 *        Normal mode.
 *
 *  How this peripheral works
 *  -------------------------
 *  + Normal operation mode
 *    In this mode, the DAC is used to convert the digital value to analog voltage, the input data is held in a data
 *    FIFO(8 words depth), the value in data FIFO is pushed to DAC analog portion for conversion on a selected edge of
 *    an input SYNC signal.
 *
 *  + Automatic operation mode
 *    In this mode the internal waveform generator logic is used.
 *    The Triangle waveform example is shown below:
 *     @verbatim
            Triangle Waveform:

                                  ____                          ____
                             ____|    |____                ____|    |____
                        ____|              |____      ____|              |
                    ___|                        |____|

                        _    _    _    _    _    _    _    _    _    _    _
            REFRESH:  _| |__| |__| |__| |__| |__| |__| |__| |__| |__| |__|
        @endverbatim
 *      As shown above, at the rising edge of REFRESH signal, the step size is added to the current value till the
 *      maximum value is reached, then the step size is substracted from the current value till the minimum value
 *      is reached.
 *
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 *	This driver is designed with one DAC_Init() function and multiple register access level APIs. DAC_Init() can realize
 *  all the possible DAC configurations. Users need to invoke DAC_Init() firstly and then use other functions such as
 *  DAC_WriteDataFIFO() in the runtime.
 *
 *
 * How to use this driver
 * =======================
 *  For initialization:
 *  + Set the pin mux of the DAC output pin.
 *  + [Optional] On some platforms the macro \b FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL may be defined as 1, so the DAC
 *    clock gate will not be handled in the driver. The users must make sure to enable the clock of DAC instance before
 *    using this DAC driver.
 *  + Define a @ref cadc_config_t type variable, such as
 *                      @code
                        dac_config_t sDacConfig;
                        @endcode
 *  + Invoke DAC_GetDefaultConfig(&sDacConfig) to set some default value to sDacConfig, where normal mode is enabled,
 *    SYNC signal is set as bus clock, data FIFO is set as 0.
 *  + Configure the members in sDacConfig as desired.
 *  + Invoke DAC_Init(DAC_BASE, &sDacConfig) to make the configuration take effect.
 *
 *  For runtime DAC update:
 *  + Update DAC output.
 *      - Normal operation mode
 *          - Update the DAC output by invoking DAC_WriteDataFIFO().
 *      - Automatic operation mode
 *          - [Optional] Update the step size by invoking DAC_WriteStepSize().
 *          - [Optional] Update the minimum value by invoking DAC_WriteMinValue().
 *          - [Optional] Update the maximum value by invoking DAC_WriteMaxValue().
 *          - If any of these 3 registers are modified, invoke DAC_SetLDOK() to make sure buffered values of
 *            STEP/MIN/MAX are updated and used at the next active edge of SYNC signal.
 *
 *
 * Typical Use Case
 * ================
 *  1. Normal operation mode + Clock selected as SYNC signal.
 *      In this type of use case, the DAC is used to generate voltage output, and when the data is written to the DAC's
 *      DATA FIFO, the data can be almost immediately presented to the DAC output.
 *      The template of this type of use case is shown below.
 *      @code
            dac_config_t sDacConfig;
            DAC_GetDefaultConfig(&sDacConfig);
            sDacConfig.eOperationMode = kDAC_NormalMode;
            sDacConfig.uOperationConfig.sNormalModeConfig.u16DataFIFO = 4095;   (Each DAC LSB represent 0.806mV)
            sDacConfig.eSyncSignal = kDAC_InternalClockSignal;
            sDacConfig.bEnableAnalogPortion = true;
            DAC_Init(DACA, &sDacConfig);
        @endcode
 *      In this template, the 3.3V voltage will be generated on the DAC output pin. During runtime, invoke
 *      DAC_WriteDataFIFO() to change DAC output, such as DAC_WriteDataFIFO(DAC_BASE, 2048), where DAC outputs 1.65V.
 *
 *  2. Automatic operation mode + External SYNC_IN signal selected as SYNC signal.
 *      In this type of use case, the DAC is used to generate a waveform, and the SYNC_IN signal controls when the
 *      values of the buffered registers are updated. The update occurs on the active edge of the SYNC_IN signal if
 *      DAC_SetLDOK() function is invoked. The active edge of SYNC_IN will also cause the automatic waveform to be reset
 *      to its start point as defined by the new minimum value and maximum value. The SYNC_IN signal can come from a
 *      timer, comparator, pins, or other sources through the crossbar.
 *      The template of this type of use case is shown below.
 *          1. Initialize the DAC module with automatic operation mode and SYNC_IN signal.
 *              @code
                    dac_config_t sDacConfig;
                    DAC_GetDefaultConfig(&sDacConfig);
                    sDacConfig.eOperationMode = kDAC_AutomaticOperationMode;
                    sDacConfig.eSyncSignal = kDAC_ExternalSyncInSignal;
                    sDacConfig.eSyncInputEdge = kDAC_RisingEdge;
                    sDacConfig.uOperationConfig.sAutomaticModeConfig.eWaveformType = kDAC_OneShotSawtoothWaveform1;
                    sDacConfig.uOperationConfig.sAutomaticModeConfig.u16MaxValue = 3000;
                    sDacConfig.uOperationConfig.sAutomaticModeConfig.u16MinValue = 1000;
                    sDacConfig.uOperationConfig.sAutomaticModeConfig.u16StepSize = 50;
                    sDacConfig.uOperationConfig.sAutomaticModeConfig.u16StartValue = 3000;
                    sDacConfig.uOperationConfig.sAutomaticModeConfig.u16CompareValue = 200U;
                    sDacConfig.bEnableAnalogPortion = true;
                    DAC_Init(DACA, &sDacConfig);
                @endcode
 *              After this initialization, a ramping down sawtooth waveform will be generated on the DAC output pin.
 *              Supposes SYNC_IN signal is 10kHz, because REFERSH signal is configured as 500kHz(bus clock is 100MHz),
 *              the sawtooth waveform will be similar as the one shown in @ref kDAC_OneShotSawtoothWaveform1.
 *          2. Update waveform(maximum value/minimum value/step size)during runtime.
 *              @code
                    DAC_WriteStepSize(DACA, 10);
                    DAC_WriteMinValue(DACA, 800);
                    DAC_WriteMaxValue(DACA, 2000);
                    DAC_SetLDOK(DACA);
                @endcode
 *              When the active edge of SYNC_IN signal occurs, a new sawtooth waveform will be generated on the DAC
 *              output pin.
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The enumeration of DAC status flags, including FIFO full status flag and FIFO empty status flag.
 */
enum _dac_fifo_status_flags
{
    kDAC_FIFOFullStatusFlag  = DAC_STATUS_FULL_MASK,  /*!< Indicate the FIFO is full. */
    kDAC_FIFOEmptyStatusFlag = DAC_STATUS_EMPTY_MASK, /*!< Indicate the FIFO is empty. */
};

/*!
 *@brief The enumeration of DAC operation mode, including normal operation mode and automatic operation mode.
 */
typedef enum _dac_operation_mode
{
    kDAC_NormalOperationMode    = 0U, /*!< Normal Mode to generate an analog representation of digital words. */
    kDAC_AutomaticOperationMode = 1U, /*!< Automatic Mode to generate waveform without
                                            requiring CPU or core assistance. */
} dac_operation_mode_t;

/*!
 * @brief The enumeration of DAC sync signal mode, including internal clock signal and external SYNC_IN signal.
 */
typedef enum _dac_sync_signal_selection
{
    kDAC_InternalClockSignal = 0U,  /*!< Internal Clock signal is selected as SYNC signal, data written to the buffered
                                        registers is used on the next clock cycle */
    kDAC_ExternalSyncInSignal = 1U, /*!< Peripheral external signal is selected as SYNC signal, the update occurs on the
                                        active edge of SYNC_IN signal. */
} dac_sync_signal_selection_t;

/*!
 * @brief The enumeration of waveform type, such as square waveform, triangle waveform, etc.
 */
typedef enum _dac_waveform_type
{
    kDAC_RepeatSawtoothWaveform0 = 0U, /*!< DAC generates repeated sawtooth waveform0. The automatic waveform generation
                                          logic will create a repeated sawtooth waveform0 upon receiving an active SYNC
                                          edge, and the waveform repeats when it reaches its minimum and maximum value.
                                          The waveform increases from starting value to max value firstly.
                                          Like this following shown:
                                          @verbatim
                                                 /|   /|   /|   /|
                                                / |  / |  / |  / |
                                                  | /  | /  | /  |
                                                  |/   |/   |/   |
                                          @endverbatim     */
    kDAC_RepeatSawtoothWaveform1 = 1U, /*!< DAC generates sawtooth waveform1. The automatic waveform generation
                                          logic will create a repeated sawtooth waveform1 upon receiving an active SYNC
                                          edge, and the waveform repeats when it reaches its minimum and maximum value.
                                          The waveform decreases from starting value to min value firstly.
                                          Like this following shown:
                                          @verbatim
                                                       |\   |\   |\   |\
                                                       | \  | \  | \  | \
                                                     \ |  \ |  \ |  \ |  \
                                                      \|   \|   \|   \|   \
                                          @endverbatim    */
    kDAC_RepeatTriangleWaveform0 = 2U, /*!< The automatic waveform generation logic will create a repeated triangle
                                          waveform0 upon receiving an active SYNC edge, and the waveform repeats when
                                          it reaches its minimum and maximum value. In this type the generated triangle
                                          waveform rises from the starting value.
                                          Like this following shown:
                                          @verbatim
                                                  /\      /\      /\
                                                 /  \    /  \    /  \    /
                                                /    \  /    \  /    \  /
                                                      \/      \/      \/
                                          @endverbatim   */
    kDAC_RepeatTriangleWaveform1 = 3U, /*!< The automatic waveform generation logic will create a repeated triangle
                                          waveform1 upon receiving an active SYNC edge, and the waveform repeats when
                                          it reaches its minimum and maximum value. In this type the generated triangle
                                          waveform drops from the starting value. Like this
                                          following shown:
                                          @verbatim
                                                    /\      /\      /\
                                              \    /  \    /  \    /  \
                                               \  /    \  /    \  /
                                                \/      \/      \/
                                          @endverbatim    */
    kDAC_OneShotSawtoothWaveform0 = 4U, /*!< Automatic waveform generation logic will create a single
                                           pattern and stop at the final value. It will remain at the finial
                                           value until a new active edge occurs on the SYNC input, and then
                                           the waveform will be repeated. Like this following shown:
                                           @verbatim
                                                              /|       /|
                                                             / |      / |
                                                            /  |     /  |
                                                       ____/   |____/   |___
                                           @endverbatim */
    kDAC_OneShotSawtoothWaveform1 = 5U, /*!< Automatic waveform generation logic will create a single
                                           pattern and stop at the final value. It will remain at the finial
                                           value until a new active edge occurs on the SYNC input, and then
                                           the waveform will be repeated. Like this following shown:
                                           @verbatim:
                                                    |\      |\
                                                    | \     | \
                                                    |  \    |  \
                                                ____|   \___|   \__
                                           @endverbatim */
} dac_waveform_type_t;

#if (defined(FSL_FEATURE_DAC_HAS_SYNC_EDGE) && FSL_FEATURE_DAC_HAS_SYNC_EDGE)
/*!
 * @brief The enumeration of sync input edge that used for updates buffered registers, such as Falling edge, etc.
 */
typedef enum _dac_sync_input_edge
{
    kDAC_NoActiveEdge = 0U, /*!< No active edge is selected, it means the SYNC input is ignored. */
    kDAC_FallingEdge  = 1U, /*!< Updates occur on the falling edge of the SYNC input. */
    kDAC_RisingEdge   = 2U, /*!< Updates occur on the rising edge of the SYNC input. */
    kDAC_BothEdges    = 3U, /*!< Updates occur on both edges of the SYNC input. */
} dac_sync_input_edge_t;
#endif

/*!
 * @brief The enumeration of DAC speed mode, including high speed mode and low speed mode.
 */
typedef enum _dac_speed_mode
{
    kDAC_HighSpeedMode = 0U, /*!< In High Speed Mode, the setting time of the DAC module is 1us,
                                    but the DAC module uses more power. */
    kDAC_LowSpeedMode = 1U,  /*!< In Low Speed Mode, the DAC module uses less power but takes more time to settle. */
} dac_speed_mode_t;

/*!
 * @brief The enumeration of FIFO watermark level.
 */
typedef enum _dac_watermark_level
{
    kDAC_WatermarkValue0 = 0U, /*!< Watermark value is 0.*/
    kDAC_WatermarkValue2 = 1U, /*!< Watermark value is 2. */
    kDAC_WatermarkValue4 = 2U, /*!< Watermark value is 4. */
    kDAC_WatermarkValue6 = 3U, /*!< Watermark value is 6 */
} dac_watermark_level_t;

/*!
 * @brief The enumeration of DAC data format, inclding right right-justified and left-justified.
 */
typedef enum _dac_data_format
{
    kDAC_DataWordRightJustified = 0U, /*!< The 12 bits data is right-justified. */
    kDAC_DataWordLeftJustified  = 1U, /*!< The 12 bits data iss left-justified. */
} dac_data_format_t;

/*!
 * @brief The structure of configuration when the operation mode is selected are normal operation mode.
 */
typedef struct _dac_normal_mode_config
{
    bool bEnableDMA;                       /*!< Enable/Disable DMA support.
                                               - \b true Enable DMA support.
                                               - \b false Disable DMA support. */
    dac_watermark_level_t eWatermarkLevel; /*! The FIFO watermark level, if the level of FIFO is less than or
                                               equal to the watermark level field, a DMA request should be sent. */
    uint16_t u16DataFIFO;                  /*!< The DAC data to be converted to analog. If the data format is set as
                                                @ref kDAC_DataWordRightJustified then u16DataFIFO should range from 0 to
                                                4095, which means the higher 4 bits is useless. If the data format is
                                                set as @ref kDAC_DataWordLeftJustified, then the u16DataFIFO should
                                                range from 16 to 65520, which means the lower 4 bits is useless. */
} dac_normal_mode_config_t;

/*!
 * @brief The structure of configuration when the operation mode is selected as automatic operation mode.
 */
typedef struct _dac_automatic_mode_config
{
    dac_waveform_type_t eWaveformType; /*!< The type of waveform to be generated. */
    uint16_t u16StepSize;              /*! The step size to be added to or subtracted from the current value.
                                            If the data format is set as @ref kDAC_DataWordRightJustified then
                                            u16StepSize should range from 0 to 4095, which means the higher 4 bits is
                                            useless. If the data format is set as @ref kDAC_DataWordLeftJustified, then
                                            the u16StepSize should range from 16 to 65520, which means the lower 4 bits
                                            is useless.  */
    uint16_t u16MinValue;              /*!< The minimum value is the lower range limit during automatic waveform
                                            generation. If the data format is set as @ref kDAC_DataWordRightJustified
                                            then u16MinValue should range from 0 to 4095, which means the higher 4 bits
                                            is useless. If the data format is set as @ref kDAC_DataWordLeftJustified,
                                            then the u16MinValue should range from 16 to 65520, which means the lower 4
                                            bits is useless. */
    uint16_t u16MaxValue;              /*!< The maximum value is the upper range limit during automatic waveform
                                            generation. If the data format is set as @ref kDAC_DataWordRightJustified
                                            then u16MaxValue should range from 0 to 4095, which means the higher 4 bits
                                            is useless. If the data format is set as @ref kDAC_DataWordLeftJustified,
                                            then the u16MaxValue should range from 16 to 65520, which means the lower 4
                                            bits is useless. */
    uint16_t u16StartValue;            /*!< The start value of the wavefrom, should larger than the minium value and
                                        smaller than the maximum value. */
#if (defined(FSL_FEATURE_DAC_HAS_COMPARE_VAL) && FSL_FEATURE_DAC_HAS_COMPARE_VAL)
    uint16_t u16CompareValue; /*!< The compare value that used to decide the frequency of REFRESH signal.
                                   The available range is 0 ~ 65535.
                                   - \b u16CompareValue=0 The REFRESH signal's frequency is equal to the clock's
                                       frequency so that the generated waveform will be updated every clock cycle.
                                   - \b u16CompareValue=N(N!=0) The REFRESH signal's frequency is equal to
                                       clock's frequency divided N+1 so that the generated waveform will be
                                       updated every N+1 clock cycles */
#endif
} dac_automatic_mode_config_t;

/*!
 * @brief The union of operation modes' configuration.
 */
typedef union _dac_operation_config
{
    dac_normal_mode_config_t sNormalModeConfig;       /*!< The configuration of normal operation mode, such as
                                                            buffered data, watermark level, etc. */
    dac_automatic_mode_config_t sAutomaticModeConfig; /*!< The configuration of automatic operation mode, such as step
                                                            size, minimum value, maximum value, etc. */
} dac_operation_config_u;

/*!
 * @brief The structure for configuring the DAC.
 *
 * This structure is used to config the DAC module, to initialize the DAC module, user must
 * set the member of this structure. This structure will cost 20 Byte memory space.
 */
typedef struct _dac_config
{
    dac_operation_mode_t eOperationMode;     /*!< The operation mode. The available selections are @ref
                                             kDAC_NormalOperationMode and @ref kDAC_AutomaticOperationMode. */
    dac_sync_signal_selection_t eSyncSignal; /*!< The selected sync signal that used to update buffered data, the
                                                   available selections are @ref kDAC_InternalClockSignal and
                                                   @ref kDAC_ExternalSyncInSignal */
#if (defined(FSL_FEATURE_DAC_HAS_SYNC_EDGE) && FSL_FEATURE_DAC_HAS_SYNC_EDGE)
    dac_sync_input_edge_t eSyncInputEdge; /*!< The SYNC input edge used to update buffered registers. The
                                              buffered value will be updated at the selected active edge of
                                              SYNC_IN signal. */
#endif
    dac_data_format_t eDataFormat;           /*!< The data format of DAC instance. The available selections are
                                                 @ref kDAC_DataWordRightJustified and @ref kDAC_DataWordLeftJustified */
    dac_operation_config_u uOperationConfig; /*!< The configuration of operation mode. */
    bool bEnableGlitchFilter;                /*!< Enable/Disable glitch suppression filter.
                                                 - \b true Enable glitch filter.
                                                 - \b false Disable glitch filter. */
    uint8_t u8GlitchFilterCount;             /*!< The count(ranges from 0 to 63) represents the number of clock
                                                 cycles for which the DAC output is held unchanged after new data
                                                 is presented to the analog DAC's inputs. */

    dac_speed_mode_t eSpeedMode; /*!< The speed mode of DAC instance. The available selections are
                                     @ref kDAC_HighSpeedMode and @ref kDAC_LowSpeedMode. */
    bool bEnableAnalogPortion;   /*!< Power up/down the analog portion.
                                     - \b true Power up the analog portion of the DAC, and the DAC will
                                         output the value currently presented to its inputs.
                                     - \b false Power down the analog portion of the DAC, and its
                                         output will be pulled down. */
} dac_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization And De-initialization Interfaces
 * @{
 */

/*!
 * @brief Initializes the DAC resource, including data format, sync signal, operation mode, etc.
 *
 * @param base DAC peripheral base address.
 * @param psConfig The pointer to @ref dac_config_t.
 */
void DAC_Init(DAC_Type *base, const dac_config_t *psConfig);

/*!
 * @brief  De-initializes the DAC resource, the clock and power will be gated off.
 *
 * Invoking this function to power down the analog portion of DAC and disable the DAC clock.
 *
 * @param base DAC peripheral base address.
 */
void DAC_Deinit(DAC_Type *base);

/*!
 * @brief Gets the default DAC configs, such as operation mode, watermark level, sync signal, etc.
 *
 * @code
        psConfig->eOperationMode = kDAC_NormalOperationMode;
        psConfig->uOperationConfig.sNormalModeConfig.u16DataFIFO   = 0U;
        psConfig->bEnableDMA                                       = false;
        psConfig->eWatermarkLevel = kDAC_WatermarkValue2;
        psConfig->eSyncInputEdge                                   = kDAC_RisingEdge;
        psConfig->eSpeedMode                                       = kDAC_HighSpeedMode;
        psConfig->eDataFormat                                      = kDAC_DataWordRightJustified;
        psConfig->eSyncSignal                                      = kDAC_InternalClockSignal;
        psConfig->bEnableAnalogPortion                             = false;
        psConfig->bEnableGlitchFilter                              = true;
        psConfig->u8GlitchFilterCount                              = 29U;
    @endcode
 *
 * @param psConfig The pointer to @ref dac_config_t.
 */
void DAC_GetDefaultConfig(dac_config_t *psConfig);

/*! @} */

/*!
 * @name Conversion Modes Related Interfaces
 * @{
 */

#if (defined(FSL_FEATURE_DAC_HAS_SYNC_EDGE) && FSL_FEATURE_DAC_HAS_SYNC_EDGE)
/*!
 * @brief Selects which SYNC input edge is used for updates, available selections are "no active edge", "falling edge",
 * "rising edge", "both edge".
 *
 * @param base DAC peripheral base address.
 * @param eSyncEdge The input edge to be set, please refer to @ref dac_sync_input_edge_t for details.
 */
static inline void DAC_SetSyncEdge(DAC_Type *base, dac_sync_input_edge_t eSyncEdge)
{
    uint16_t tmp16;

    tmp16 = base->CTRL0;
    tmp16 &= ~DAC_CTRL0_SYNCEDGE_MASK;
    tmp16 |= DAC_CTRL0_SYNCEDGE(eSyncEdge);

    base->CTRL0 = tmp16;
}
#endif

#if (defined(FSL_FEATURE_DAC_HAS_LOAD_OK) && FSL_FEATURE_DAC_HAS_LOAD_OK)
/*!
 * @brief Updates the buffered value of stepSize, minValue ,and maxValue at the active edge of the SYNC_IN signal.
 *
 * @note Allows new values of minimum, maximum, and step value to be updated by active edge of SYNC_IN. This function
 * should be invoked once new values of these buffered registers have been written by software. The LDOK bit will be
 * cleared by an active edge of SYNC_IN.
 * @note This function is only useful when the operation mode is selected as Automatic operation mode.
 *
 * @param base DAC peripheral base address.
 */
static inline void DAC_SetLDOK(DAC_Type *base)
{
    base->CTRL0 |= DAC_CTRL0_LDOK_MASK;
}
#endif

#if (defined(FSL_FEATURE_DAC_HAS_LOAD_OK) && FSL_FEATURE_DAC_HAS_LOAD_OK)
/*!
 * @brief Gets the value of load Okay bit field.
 *
 * @note When the SYNC signal is selected as external SYNC_IN signal, the load okay bit will be cleared by an active
 * edge of the SYNC_IN signal. This function can be used to check whether the active edge of the SYNC_IN signal has
 * reached.
 * @note This function is only useful when the operation mode is selected as Automatic operation mode.
 *
 * @param base DAC peripheral base address.
 * @return
 *      - \b true The active edge of SYNC_IN signal has not reached when the SYNC signal is selected as external
 *                SYNC_IN signal.
 *      - \b false The active edge of SYNC_IN signal has reached when the SYNC signal is selected as external
 *                SYNC_IN signal
 */
static inline bool DAC_GetLDOKValue(DAC_Type *base)
{
    return ((base->CTRL0 & DAC_CTRL0_LDOK_MASK) == DAC_CTRL0_LDOK_MASK);
}
#endif

/*! @} */

/*!
 * @name Operation Modes Related Interfaces
 * @{
 */

#if (defined(FSL_FEATURE_DAC_HAS_ONE_SHOT) && FSL_FEATURE_DAC_HAS_ONE_SHOT)
/*!
 * @brief Enables/Disables Oneshot feature, oneshot feature used to determines whether automatic waveform generation
 * creates one waveform or a repeated waveform within the period defined by the active SYNC edges.
 *
 * @note This function only useful when the operation mode is selected as automatic operation mode.
 *
 * @param base DAC peripheral base address.
 * @param bEnable Enable/Disable oneshot feature.
 *              - \b true Automatic waveform generation logic will create a single pattern and stop at the final value.
 *              - \b false Automatic waveform generation logic will create a repeated (continuous) waveform upon
 *                          receiving an active SYNC edge.
 */
static inline void DAC_EnableOneShot(DAC_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL0 |= DAC_CTRL0_ONESHOT_MASK;
    }
    else
    {
        base->CTRL0 &= ~DAC_CTRL0_ONESHOT_MASK;
    }
}
#endif

/*!
 * @brief Writes DAC buffered data value based on the data format when the DAC is in normal
 * operation mode.
 *
 * @param base DAC peripheral base address.
 * @param u16Data The DAC data to be converted to analog. If the data format is set as @ref kDAC_DataWordRightJustified
 *                then u16Data should range from 0 to 4095, which means the higher 4 bits is useless. If the data format
 *                is set as @ref kDAC_DataWordLeftJustified, then the u16Data should range from 16 to 65520, which means
 *                the lower 4 bits is useless.
 */
static inline void DAC_WriteDataFIFO(DAC_Type *base, uint16_t u16Data)
{
    base->FMT0.DATAREG_FMT0 = u16Data;
}

/*!
 * @brief Writes Step size based on the data format when the DAC is in automatic operation mode.
 *
 * @note This function only useful when the operation mode is selected as automatic operation mode.
 *
 * @param base DAC peripheral base address.
 * @param u16StepSize The step value to be added to or subtracted from the current value. If the data format is set as
 *                    @ref kDAC_DataWordRightJustified then u16StepSize should range from 0 to 4095, which means the
 *                    higher 4 bits is useless. If the data format is set as @ref kDAC_DataWordLeftJustified, then the
 *                    u16StepSize should range from 16 to 65520, which means the lower 4 bits is useless.
 */
static inline void DAC_WriteStepSize(DAC_Type *base, uint16_t u16StepSize)
{
    base->FMT0.STEPVAL_FMT0 = u16StepSize;
}

/*!
 * @brief Writes the minium value based on the data format when the DAC is in automatic
 * operation mode.
 *
 * @note This function only useful when the operation mode is selected as automatic operation mode. If DAC input data is
 * less than the minium value, output is limited to the minium value during automatic waveform generation.
 *
 * @param base DAC peripheral base address.
 * @param u16MinValue The lower range limit during automatic waveform generation. If the data format is set as
 *                    @ref kDAC_DataWordRightJustified then u16MinValue should range from 0 to 4095, which means the
 *                    higher 4 bits is useless. If the data format is set as @ref kDAC_DataWordLeftJustified, then the
 *                    u16MinValue should range from 16 to 65520, which means the lower 4 bits is useless.
 */
static inline void DAC_WriteMinValue(DAC_Type *base, uint16_t u16MinValue)
{
    base->FMT0.MINVAL_FMT0 = u16MinValue;
}

/*!
 * @brief Writes the maximum value based on the data format when the DAC is in automatic
 * operation mode.
 *
 * @note This function only useful when the operation mode is selected as automatic operation mode. If DAC input data is
 * greater than maximum value, output is limited to maximum value during automatic waveform generation.
 *
 * @param base DAC peripheral base address.
 * @param u16MaxValue The upper range limit during automatic waveform generation. If the data format is set as
 *                    @ref kDAC_DataWordRightJustified then u16MaxValue should range from 0 to 4095, which means the
 *                    higher 4 bits is useless. If the data format is set as @ref kDAC_DataWordLeftJustified, then the
 *                    u16MaxValue should range from 16 to 65520, which means the lower 4 bits is useless.
 */
static inline void DAC_WriteMaxValue(DAC_Type *base, uint16_t u16MaxValue)
{
    base->FMT0.MAXVAL_FMT0 = u16MaxValue;
}

#if (defined(FSL_FEATURE_DAC_HAS_COMPARE_VAL) && FSL_FEATURE_DAC_HAS_COMPARE_VAL)
/*!
 * @brief Sets refresh frequency that used to decide when the automatically generated waveform value is updated.
 *
 * @note This function only useful when the operation mode is selected as automatic operation mode.
 *
 * @param base DAC peripheral base address.
 * @param u16CompareValue The compare value(0~65535).
 *                        - \b u16CompareValue=0 The generated waveform will be updated every clock cycle.
 *                        - \b u16CompareValue=N(N!=0) The generated waveform will be updated every N+1 clock cycles.
 */
static inline void DAC_ConfigRefreshFrequency(DAC_Type *base, uint16_t u16CompareValue)
{
    base->COMPARE = DAC_COMPARE_COMPARE(u16CompareValue);
}
#endif

/*! @} */

/*!
 * @name DMA Control Related Interfaces
 * @{
 */

/*!
 * @brief Enables/Disables DMA request that to be generated when the FIFO is below the watermark level.
 *
 * @note This function is only useful when the operation mode is selected as Normal mode.
 *
 * @param base DAC peripheral base address.
 * @param bEnable Enable/Disable DMA support.
 *              - \b true Enable DMA support.
 *              - \b false Disable DMA support.
 */
static inline void DAC_EnableDMA(DAC_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL0 |= DAC_CTRL0_DMA_EN_MASK;
    }
    else
    {
        base->CTRL0 &= ~DAC_CTRL0_DMA_EN_MASK;
    }
}

/*!
 * @brief Sets watermark level which is used for asserting a DMA request.
 *
 * @note When the level of FIFO is less than or equal to the Watermark level, a DMA
 *      request will be sent. This function is only  useful when the operation mode is selected as Normal mode.
 *
 * @param base DAC peripheral base address.
 * @param eWatermarkLevel The watermark level of FIFO, please refer to @ref dac_watermark_level_t for details.
 */
static inline void DAC_SetWatermarkLevel(DAC_Type *base, dac_watermark_level_t eWatermarkLevel)
{
    uint16_t tmp16;

    tmp16 = base->CTRL0;
    tmp16 &= ~DAC_CTRL0_WTMK_LVL_MASK;
    tmp16 |= DAC_CTRL0_WTMK_LVL(eWatermarkLevel);

    base->CTRL0 = tmp16;
}

/*! @} */

/*!
 * @name Glitch Filter Related Interfaces
 * @{
 */

/*!
 * @brief Enables/Disables Glitch filter.
 *
 * @param base DAC peripheral base address.
 * @param bEnable Enable/Disable Glitch filter.
 *          - \b true Enable glitch filter.
 *          - \b false Disable glitch filter.
 */
static inline void DAC_EnableGlitchFilter(DAC_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL0 |= DAC_CTRL0_FILT_EN_MASK;
    }
    else
    {
        base->CTRL0 &= ~DAC_CTRL0_FILT_EN_MASK;
    }
}

/*!
 * @brief Sets glitch filter count value(ranges from 0 to 63) that represents the number of clock cycles for which the
 * DAC output is held unchanged after new data is presented to the analog DAC's inputs.
 *
 * @param base DAC peripheral base address.
 * @param u8FilterCount The count of glitch filter. This count represents the number of clock cycles for which the DAC
 *                      output is held unchanged after new data is presented to the analog DAC's inputs.
 */
static inline void DAC_SetGlitchFilterCount(DAC_Type *base, uint8_t u8FilterCount)
{
    base->CTRL1 = DAC_CTRL1_FILT_CNT(u8FilterCount);
}

/*! @} */

/*!
 * @name Power And Speed Related Interface
 * @{
 */

/*!
 * @brief Selects speed mode, high speed mode uses more power and low speed mode saves power.
 *
 * @param base DAC peripheral base address.
 * @param eSpeedMode The speedMode to be set, please refer to @ref dac_speed_mode_t for details.
 */
static inline void DAC_SetSpeedMode(DAC_Type *base, dac_speed_mode_t eSpeedMode)
{
    if (eSpeedMode == kDAC_HighSpeedMode)
    {
        base->CTRL0 &= ~DAC_CTRL0_HSLS_MASK;
    }
    else
    {
        base->CTRL0 |= DAC_CTRL0_HSLS_MASK;
    }
}

/*!
 * @brief Enables/Disables the operation of the analog portion of the DAC.
 *
 * The function controls the power-up of the analog portion of the DAC. If powered up the analog portion, the DAC module
 * will output the value currently presented to the Data register. The analog portion should be powered up when the DAC
 * is in use. If power down the analog portion, the output of the DAC module will be pulled low. The analog portion
 * should be powered down when the DAC is not in use.
 *
 * @param base DAC peripheral base address.
 * @param bEnable Power up/down the analog portion of the DAC.
 *          - \b true Power up the analog portion of the DAC, and the DAC will output the value currently presented to
 *                    its inputs.
 *          - \b false Power down the analog portion of the DAC, and its output will be pulled down.
 */
static inline void DAC_EnableAnalogPortion(DAC_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL0 &= ~DAC_CTRL0_PDN_MASK;
    }
    else
    {
        base->CTRL0 |= DAC_CTRL0_PDN_MASK;
    }
}

/*! @} */

/*!
 * @name Status Flags Interface
 * @{
 */

/*!
 * @brief Gets the fifo status flag of selected DAC instance.
 *
 * @param base DAC peripheral base address.
 * @return The status flags of DAC module, should be the OR'ed value of @ref _dac_fifo_status_flags.
 */
static inline uint16_t DAC_GetFIFOStatusFlags(DAC_Type *base)
{
    return base->STATUS;
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_DAC_H_ */
