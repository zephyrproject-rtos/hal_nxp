/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CMP_H_
#define FSL_CMP_H_

#include "fsl_common.h"

/*!
 * @defgroup cmp CMP: Comparator Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief CMP driver version. */
#define FSL_CMP_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * CMP peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup cmp_driver_log The Driver Change Log
 * @ingroup cmp
 * @{
 * The current cmp driver version is 2.0.1.
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
 * CMP peripheral driver overview
 ******************************************************************************/

/*!
 * @defgroup cmp_intro CMP Peripheral and Driver Overview
 * @ingroup cmp
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features and how this peripheral works
 * ==================================================
 *
 * Peripheral features
 * --------------------------------------------------
 *
 * The comparator (CMP) module provides below features:
 *
 * + Support two 8-to-1 input channel
 *   - Inputs may range from rail to rail(the input voltage amplitude can reach the upper and lower limits of the power
 *     supply voltage)
 *   - A 8 bit CMP internal DAC output can be used as comparator's input.
 *     Selectable supply voltage reference source from VN1 or VIN2.
 *
 * + Programmable input hysteresis level of the comparator
 *   Support 0 - 3 hysteresis level
 *
 * + Programmable performance levels of the comparator
 *   - Shorter propagation delay at the expense of higher power
 *   - Low power, with longer propagation delay
 *
 * + Selectable inversion on comparator output
 *
 * + Support below work modes
 *   + The window function is enabled and external sampling mode is disabled
 *     Window function will control the comparator's output by a external WINDOW signal and the bus clocks.
 *     - The comparator output will be sampled on every bus clock when WINDOW = 1
 *     - The sampling doesn't occur when WINDOW = 0
 *     - The output of window function can be last latched value when WINDOW signal changes from 1 to 0
 *     - The output of window function can be forced to zero when WINDOW signal changes from 1 to 0
 *     @note The WINDOW signal should be routed to a source(such as PWM, PIT, etc) by Inter-Peripheral Crossbar
 *   + The window function is disabled and external sampling mode is enabled
 *     - The window function have no functionality in this mode
 *     - A external sample signal will be used to re-sample the comparator's output.
 *       @note The external SAMPLE signal should be routed to a source(such as PWM, PIT, etc) by Inter-Peripheral
 *       Crossbar
 *   + The window function is disabled and external sampling mode is disabled
 *     - Both the window function and external sampling signal has no functionality
 *   @note the window function and external sampling mode are mutually exclusive, since the WINDOW signal and external
 *    SAMPLE signal are comes from the same source.
 *
 * + Support a internal filter
 *   The internal filter function can be used to take several counts(count number is programmable) of samples from
 *   comparator's output in every filter period(period is programmable).
 *   - The internal filter will be enabled if the filter count > 0 and filter period is a nonzero value, otherwise the
 *     filter will be disabled.
 *   - The internal filter can be enabled together with above work modes which external sampling mode is disabled, since
 *     internal filter and the external sampling mode are mutually exclusive.
 *
 * + Selectable interrupt/dma request on rising-edge, falling-edge, or both edges of the comparator output
 *   @note When the DMA and the interrupt are both enabled, the corresponding change on COUT forces a DMA
 *   transfer request rather than a CPU interrupt instead
 *
 * + The CMP module output can be routed to other internal peripherals and a CMP output PAD.
 *   - The CMP output to the PAD is selectable within below sources.
 *     + COUTA
 *       - COUTA can comes from the comparator output directly when the window function is disabled.
 *       - COUTA can comes from the window function output.when the window function is enabled
 *     + COUT
 *       - COUT is COUTA when internal filter is bypassed and external sampling mode disabled.
 *       - COUT can be a output of internal filter which source from COUTA.
 *       - COUT can be a result of COUTA re-sampled by a external sample signal.
 *   - The COUT can be routed to other internal peripherals.
 *
 * How this peripheral works
 * --------------------------------------------------
 * Once the CMP is configured and enabled, the comparator will compare two analog input voltages applied to INP and
 * INM. CMPO is high when the non-inverting input is greater than the inverting input, and is low
 * when the non-inverting input is less than the inverting input.
 *
 * The output of the comparator will be controlled by the window function or external sampling signal or internal filter
 * per different configurations.
 *
 * If there is a change on the COUT,
 * 1. The CMP will generate a interrupt if the interrupt is enabled
 * 2. The CMP will generate a DMA transfer request if the DMA is enabled
 *
 * How this driver is designed to make this peripheral works
 * ===========================================================
 * The CMP driver designed several configuration structures and function groups to help user on enable the module .
 *
 * + CMP driver designed a configuration structure @ref cmp_config_t which cover full configurations of the module.
 *   User need to pay attention to the below items,
 *   - The driver designed three work modes for user selection by configure the member eWorkMode in the structure.
 *   - Since the interrupt and dma request are mutually exclusive, so the configuration structure provide
 *     a union(@ref cmp_dma_interrupt_config_t) member for interrupt and dma request configuration which is named
 *     uDmaInterruptConfig.
 * + CMP driver provide a CMP Initialization and de-initialization interfaces
 *   - User can have all the CMP configuration be configured through this interfaces with a cmp configuration provided
 *     by @ref cmp_config_t..
 *   - The interfaces provide a helper function for the default value of the @ref cmp_config_t.
 *   - It is assumed that the most of the configurations of the CMP is constant during runtime.
 * + CMP driver provided a functional interface which is target for runtime configurations update, such as
 *   the input mux, internal DAC configurations, etc.
 * + The CMP interrupt interfaces
 *   The interface used to enable/disable the interrupt request.
 * + The CMP DMA interfaces
 *   The interfaces used to enable/disable DMA transfer request.
 * + The CMP status interfaces
 *   The interfaces used to get/clear the the comparator status flag.
 *
 * How to use this driver
 * =======================
 * + Configuration option on compiling
 *   - FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL: Defined of this macro means this driver will not handle CMP
 *     peripheral clock. Application code need to handle the CMP clock by itself
 *
 * + User must be aware of below configurations should be done before driver interfaces been invoked.
 *   - The selected input mux pins must be configured properly before start the comparison.
 *   - [Optional]The CMP request source must be configured properly in the Direct Memory Access Multiplexer(DMAMUX) if
 *     application is going to using DMA for reading CMP result
 *   - [Optional]The internal DAC voltage reference source should be configured properly if it is selected as the input
 *     of CMP
 *   - [Optional]The external DAC should be configured properly if it is selected as the input of CMP.
 *   - [Optional]The external WINDOW signal should be configured properly if the window is enabled
 *   - [Optional]The external SAMPLE signal should be configured properly if the external sampling mode is using.
 *
 * + Driver Interface invoking sequence
 *   - Initialize the CMP module
 *     + Using the cmp_config_t for CMP initialization configuration preparation
 *       - Application can call CMP_GetDefaultConfig to get the default configurations
 *       - Application must overwrite the default input plus/minus mux configurations(ePlusInput/eMinusInput in @ref
 *         cmp_config_t) according to the pins selected by application.
 *       - [Optional]If CMP internal DAC is used as input of CMP, please make sure internal DAC configurations is
 *         done by configure member sDacConfig in @ref cmp_config_t.
 *       - User should pay attention to the three work modes provide by CMP driver and make sure proper work mode
 *         is selected by configure the eWorkMode in @ref cmp_config_t.
 *         + kCMP_WorkModeWindowBypassAndNoExternalSample
 *           - The internal filter function can be enabled together with this mode selected,
 *             then application should configure the filter count and period by member eInternalFilterCount
 *             and u8InteralFilterPeriod in @ref cmp_config_t.
 *           - The members eExternalSampleCount and eWindowOutput is ignored when this mode is selected.
 *         + kCMP_WorkModeWindowBypassAndExternalSample
 *           - The sample count should be configured properly by the member eExternalSampleCount(>=1) in cmp_config_t,
 *           - The members eInternalFilterCount/u8InteralFilterPeriod/eWindowOutput are ignored when this mode is
 *             selected.
 *         + kCMP_WorkModeWindowEnabledAndNoExternalSample
 *           - The window output mode should be configured properly by eWindowOutputMode in @ref cmp_config_t
 *           - The internal filter function can be enabled together with this mode selected,
 *             then application should configure the filter count and period by member eInternalFilterCount
 *             and u8InteralFilterPeriod in @ref cmp_config_t.
 *           - The member eExternalSampleCount is ignored when this mode is selected.
 *       - [Optional]Enable DMA or interrupt
 *         The dma/interrupt request can be configured by uDmaInterruptConfig @ref cmp_config_t.
 *     + Call CMP_Init for the CMP module initialization
 *
 *   - [Optional]Enable the CMP module
 *     Once the CMP configuration is done, application can using CMP_Enable to start the comparison anytime if the
 *     CMP is not enabled in CMP_Init by setting bEnableCMP in the @ref cmp_config_t to true.
 *
 *   - [Optional]Runtime configurations update
 *     Once the CMP configuration done, application can using the CMP functional interfaces for the configuration update
 *     runtime, such as the comparator input mux, internal DAC configurations, etc.
 *
 *   - Get comparator output
 *     Application can get the comparator result by calling api CMP_GetComparatorOutput.
 *
 *   - De-initialization
 *     While the CMP module is in idle state, application should call CMP_Deinit to disable the CMP module and gate the
 *     CMP clock(if application handing the CMP clock) for lower power consumption
 *
 * Typical Use Cases
 * ================
 * 1. Work mode kCMP_WorkModeWindowEnabledAndNoExternalSample, the window function is enabled and external sampling mode
 *    is disabled
 *    @code
 *    CMP_GetDefaultConfig(config)
 *    config->ePlusInput = xxx
 *    config->eMinusInput = xxx
 *    config->eWorkMode = kCMP_WorkModeWindowEnabledAndNoExternalSample
 *    config->eWindowOutput = kCMP_WindowOuputLastLatchedValue
 *    CMP_Init(base, config)
 *    CMP_Enable(base)
 *    @endcode
 *
 * 2. Work mode kCMP_WorkModeWindowEnabledAndNoExternalSample, the window function is enabled and external sampling mode
 *    is disabled, internal filter is enabled
 *    @code
 *    CMP_GetDefaultConfig(config)
 *    config->ePlusInput = xxx
 *    config->eMinusInput = xxx
 *    config->eWorkMode = kCMP_WorkModeWindowEnabledAndNoExternalSample
 *    config->eWindowOutput = kCMP_WindowOuputLastLatchedValue
 *    config->eFilterCount = kCMP_FilterCount2
 *    config->u8FilterPeriod = xxx
 *    CMP_Init(base, config)
 *    CMP_Enable(base)
 *    @endcode
 *
 * 3. Work mode kCMP_WorkModeWindowBypassAndExternalSample, the window function is bypassed and external sampling mode
 *    is enabled.
 *    @code
 *    CMP_GetDefaultConfig(config)
 *    config->ePlusInput = xxx
 *    config->eMinusInput = xxx
 *    config->eExternalSampleCount = kCMP_ExternalSampleCount1
 *    config->eWorkMode  = kCMP_WorkModeWindowBypassAndExternalSample;
 *
 *    CMP_Init(base, config)
 *    CMP_Enable(base)
 *    @endcode
 *
 * 4. Work mode kCMP_WorkModeWindowBypassAndNoExternalSample, the window function is disabled and external sampling mode
 *    is disabled bus clock.
 *    @code
 *    CMP_GetDefaultConfig(config)
 *    config->ePlusInput = xxx
 *    config->eMinusInput = xxx
 *    config->eWorkMode  = kCMP_WorkModeWindowBypassAndNoExternalSample;
 *
 *    config->bCMPEnable = true
 *
 *    CMP_Init(base, config)
 *    @endcode
 *
 * 5. Work mode kCMP_WorkModeWindowBypassAndNoExternalSample, the window function is disabled and external sampling mode
 *    is disabled, internal filter is enabled
 *    @code
 *    CMP_GetDefaultConfig(config)
 *    config->ePlusInput = xxx
 *    config->eMinusInput = xxx
 *    config->eFilterCount = kCMP_FilterCount2
 *    config->u8FilterPeriod = xxx
 *    config->eWorkMode  = kCMP_WorkModeWindowBypassAndNoExternalSample;
 *
 *    config->bCMPEnable = true
 *
 *    CMP_Init(base, config)
 *    @endcode
 *
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief CMP Interrupt request type definition */
typedef enum _cmp_interrupt_request
{
    kCMP_InterruptRequestDisabled = 0U, /*!< interrupt disabled */
    kCMP_InterruptRequestEnableOutputRisingEdge =
        CMP_SCR_IER_MASK, /*!< Comparator interrupt request enable rising edge. */
    kCMP_InterruptRequestEnableOutputFallingEdge =
        CMP_SCR_IEF_MASK, /*!< Comparator interrupt request enable falling edge. */
    kCMP_InterrruptRequestEnableAll =
        CMP_SCR_IER_MASK | CMP_SCR_IEF_MASK, /*!< comparator interrupt request enable on rising edge or falling edge */
} cmp_interrupt_request_t;

#if (defined(FSL_FEATURE_CMP_HAS_DMA) && FSL_FEATURE_CMP_HAS_DMA)
/*! @brief CMP DMA request type definition */
typedef enum _cmp_dma_request
{
    kCMP_DMARequestDisabled = 0U, /*!< DMA disabled */
    kCMP_DMARequestEnableOutputRisingEdge =
        CMP_SCR_IER_MASK | CMP_SCR_DMAEN_MASK, /*!< Comparator dma request enable on rising edge. */
    kCMP_DMARequestEnableOutputFallingEdge =
        CMP_SCR_IEF_MASK | CMP_SCR_DMAEN_MASK, /*!< Comparator dnma request enable on falling edge. */
    kCMP_DMARequestEnableAll = CMP_SCR_IER_MASK | CMP_SCR_IEF_MASK |
                               CMP_SCR_DMAEN_MASK, /*!< comparator dma request enable on rising edge or falling edge */
} cmp_dma_request_t;
#endif /* FSL_FEATURE_CMP_HAS_DMA */

/*! @brief CMP output flags' mask */
typedef enum _cmp_output_flag
{
    kCMP_OutputFlagRisingEdge  = CMP_SCR_CFR_MASK, /*!< Rising-edge on the comparison output has occurred. */
    kCMP_OutputFlagFallingEdge = CMP_SCR_CFF_MASK, /*!< Falling-edge on the comparison output has occurred. */
    kCMP_OutputFlagBothEdge =
        CMP_SCR_CFF_MASK | CMP_SCR_CFR_MASK, /*!< Rising-edge and Falling-edge on the comparison output has occurred. */
} cmp_output_flag_t;

/*! @brief CMP Hysteresis level */
typedef enum _cmp_hysteresis_level
{
    kCMP_HysteresisLevel0 = 0U, /*!< Hysteresis level 0. */
    kCMP_HysteresisLevel1 = 1U, /*!< Hysteresis level 1. */
    kCMP_HysteresisLevel2 = 2U, /*!< Hysteresis level 2. */
    kCMP_HysteresisLevel3 = 3U, /*!< Hysteresis level 3. */
} cmp_hysteresis_level_t;

/*! @brief CMP compassion speed mode enumerator */
typedef enum _cmp_comparasion_speed_mode
{
    kCMP_ComparsionModeLowSpeed  = 0U, /*!< Low-Speed Comparison mode has lower current consumption */
    kCMP_ComparsionModeHighSpeed = 1U, /*!< High-Speed Comparison mode has higher current consumption. */
} cmp_comparasion_speed_mode_t;

/*! @brief CMP DAC Voltage Reference source */
typedef enum _cmp_dac_vref_source
{
    kCMP_DACVrefSourceVin1 = 0U, /*!< Vin1 is selected as a resistor ladder network supply reference Vin. */
    kCMP_DACVrefSourceVin2 = 1U, /*!< Vin2 is selected as a resistor ladder network supply reference Vin. */
} cmp_dac_vref_source_t;

/*! @brief CMP output value of window */
typedef enum _cmp_window_output_mode
{
    kCMP_WindowOuputLastLatchedValue =
        0U,                          /*!< When WINDOW signal changes from 1 to 0,
                                       COUTA output holds the last latched value before WINDOW signal falls to 0   */
    kCMP_WindowOutputZeroValue = 1U, /*!< When WINDOW signal changes from 1 to 0, COUTA output is forced to 0*/
} cmp_window_output_mode_t;

/*! @brief CMP filter count */
typedef enum _cmp_filter_count
{
    kCMP_FilterCountDisable = 0U, /*!< filter is disabled */
    kCMP_FilterCount1       = 1U, /*!< 1 sample must agrees, the comparator output is simply sampled */
    kCMP_FilterCount2       = 2U, /*!< 2 consecutive samples must agrees */
    kCMP_FilterCount3       = 3U, /*!< 3 consecutive samples must agrees */
    kCMP_FilterCount4       = 4U, /*!< 4 consecutive samples must agrees */
    kCMP_FilterCount5       = 5U, /*!< 5 consecutive samples must agrees */
    kCMP_FilterCount6       = 6U, /*!< 6 consecutive samples must agrees */
    kCMP_FilterCount7       = 7U, /*!< 7 consecutive samples must agrees */
} cmp_filter_count_t;

/*! @brief CMP external sample count */
typedef enum _cmp_external_sample_count
{
    kCMP_ExternalSampleCount1 = 1U, /*!< 1 sample must agrees, the comparator output is simply sampled */
    kCMP_ExternalSampleCount2 = 2U, /*!< 2 consecutive samples must agrees */
    kCMP_ExternalSampleCount3 = 3U, /*!< 3 consecutive samples must agrees */
    kCMP_ExternalSampleCount4 = 4U, /*!< 4 consecutive samples must agrees */
    kCMP_ExternalSampleCount5 = 5U, /*!< 5 consecutive samples must agrees */
    kCMP_ExternalSampleCount6 = 6U, /*!< 6 consecutive samples must agrees */
    kCMP_ExternalSampleCount7 = 7U, /*!< 7 consecutive samples must agrees */
} cmp_external_sample_count_t;

/*! @brief CMP output source enumerator */
typedef enum _cmp_output_source
{
    kCMP_OutputSourceFromFilterCOUT      = 0U, /*!< Set the filtered comparator output to equal COUT. */
    kCMP_OutputSourceFromUnfilteredCOUTA = 1U, /*!< Set the unfiltered comparator output to equal COUTA. */
} cmp_output_source_t;

/*! @brief CMP work mode definition */
typedef enum _cmp_work_mode
{
    kCMP_WorkModeWindowBypassAndNoExternalSample  = 0U, /*!< window block bypassed, external sampling mode disabled */
    kCMP_WorkModeWindowBypassAndExternalSample    = 1U, /*!< window block bypassed, external SAMPLE mode enable */
    kCMP_WorkModeWindowEnabledAndNoExternalSample = 2U, /*!< window block enabled, external sampling mode disabled */
} cmp_work_mode_t;

/*! @brief CMP internal DAC configuration structure */
typedef struct _cmp_dac_config
{
    cmp_dac_vref_source_t eDACVrefSource; /*!< DAC reference voltage source. */
    uint8_t u8DACOutputVoltageDivider;    /*!< divider Value for the DAC Output Voltage,
                                            DAC output voltage = (VREF / 256) * (u8DACOutputVoltageDivider + 1).*/
    bool bEnableInternalDAC;              /*!< flag to control if the internal DAC need to be enabled */
} cmp_dac_config_t;

/*! @brief CMP dma/interrupt configure union
 *
 * @note, the interrupt request and dma request cannot be used at the same time, that is to say
 * When DMA support is enabled by setting SCR[DMAEN] and the interrupt is enabled by setting
 * SCR[IER], SCR[IEF], or both, the corresponding change on COUT forces a DMA
 * transfer request rather than a CPU interrupt instead
 */
typedef union _cmp_dma_interrupt_config
{
#if (defined(FSL_FEATURE_CMP_HAS_DMA) && FSL_FEATURE_CMP_HAS_DMA)
    cmp_dma_request_t eDMARequest; /*!< dma request type */
#endif
    cmp_interrupt_request_t eInterruptRequest; /*!< interrupt request type */
} cmp_dma_interrupt_config_t;

/*! @brief CMP configuration structure */
typedef struct _cmp_config
{
    cmp_hysteresis_level_t eHysteresisLevel;            /*!< CMP hysteresis leveL */
    cmp_comparasion_speed_mode_t eComparasionSpeedMode; /*!< CMP comparison speed mode */

    cmp_work_mode_t eWorkMode; /*!< CMP work mode */

    cmp_input_mux_t ePlusInput;  /*!< CMP plus input mux, the definition of this enum is in soc header file */
    cmp_input_mux_t eMinusInput; /*!< CMP minus input mux, the definition of this enum is in soc header file */
    cmp_dac_config_t sDacConfig; /*!< CMP internal DAC configuration structure @ref cmp_dac_config_t */

    bool bInvertComparatorOutputPolarity; /*!< Inverted comparator output polarity. */

    cmp_window_output_mode_t
        eWindowOutputMode; /*!< only works when cmp work mode is kCMP_WorkModeWindowEnabledAndNoExternalSample */

    cmp_filter_count_t eFilterCount; /*!< Filter Count.Available range is 0-7, 0 is disable internal filter
                                               can be used in internal sampling mode only.*/
    uint8_t u8FilterPeriod;          /*!< Filter Period. The divider to the bus clock.
                                                               Available range is 0-255, can be used in internal sampling mode.
                                                               When the filter clock from internal divided bus clock,
                                                               setting the sample period to 0 will disable the filter */

    cmp_external_sample_count_t
        eExternalSampleCount; /*!< Available range is 1 - 7, used in external sampling mode only */

    cmp_output_source_t eOutputSource; /*!< cmp output source */
    bool bEnableOutputPin; /*!< the comparator output(CMPO) is driven out on the associated CMPO output pin */

    cmp_dma_interrupt_config_t uDmaInterruptConfig; /*!< CMP interrupt/dma configuration */

    bool bCMPEnable; /*!< flag to control if CMP module start immediately when the configuration is done */
} cmp_config_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name CMP Initialization and de-initialization interfaces
 * @{
 */

/*!
 * @brief Initializes the CMP user configuration structure.
 *
 * This function initializes the user configuration structure to the default values.
 * It is corresponding to the continuous mode configurations.
 *
 * @param psConfig pointer of cmp_config_t.
 */
void CMP_GetDefaultConfig(cmp_config_t *psConfig);

/*!
 * @brief Initializes the CMP.
 *
 * This function initializes the CMP module. The operations included are as follows.
 * - Enable the clock for CMP module.
 * - Configure the comparator according to the CMP configuration structure.
 *
 * @param base   CMP peripheral base address.
 * @param psConfig Pointer to the configuration structure.
 *
 */
void CMP_Init(CMP_Type *base, const cmp_config_t *psConfig);

/*!
 * @brief De-initializes the CMP module.
 *
 * This function de-initializes the CMP module. The operations included are as follows.
 * - Disabling the CMP module.
 * - Disabling the clock for CMP module.
 *
 * @param base CMP peripheral base address.
 */
void CMP_Deinit(CMP_Type *base);

/*! @} */

/*!
 * @name CMP functional interfaces
 * @{
 */

/*!
 * @brief Enables/disables the CMP module.
 *
 * @param base CMP peripheral base address.
 * @param bEnable Enables or disables the module.
 */
static inline void CMP_Enable(CMP_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CR1 |= CMP_CR1_EN_MASK;
    }
    else
    {
        base->CR1 &= ~(uint16_t)CMP_CR1_EN_MASK;
    }
}

/*!
 * @brief  Sets the input channels for the comparator.
 *
 * This function sets the input channels for the comparator.
 * Note that two input channels cannot be set the same way in the application. When the user selects the same input
 * from the analog mux to the positive and negative port, the comparator is disabled automatically.
 *
 * @param  base            CMP peripheral base address.
 * @param  ePlusChannel Plus side input channel number.
 * @param  eMinusChannel Minus side input channel number.
 */
static inline void CMP_SetInputChannel(CMP_Type *base, cmp_input_mux_t ePlusChannel, cmp_input_mux_t eMinusChannel)
{
    uint16_t u16Tmp = base->MUXCR;

    u16Tmp &= ~(uint16_t)((uint16_t)CMP_MUXCR_PSEL_MASK | (uint16_t)CMP_MUXCR_MSEL_MASK);
    u16Tmp |= CMP_MUXCR_PSEL(ePlusChannel) | CMP_MUXCR_MSEL(eMinusChannel);
    base->MUXCR = u16Tmp;
}

/*!
 * @brief Select comparator output source.
 *
 * @param base CMP peripheral base address.
 * @param eOutputSource The output signal to be set, please reference @ref cmp_output_source_t for details.
 */
static inline void CMP_SelectOutputSource(CMP_Type *base, cmp_output_source_t eOutputSource)
{
    if (eOutputSource == kCMP_OutputSourceFromFilterCOUT)
    {
        base->CR1 &= ~(uint16_t)CMP_CR1_COS_MASK;
    }
    else
    {
        base->CR1 |= CMP_CR1_COS_MASK;
    }
}

/*!
 * @brief Enable/Disable Comparator output pin.
 *
 * @param base CMP peripheral base address.
 * @param bEnable Enable/Disable comparator output pin.
 *              true    --    CMPO is available on the associate CMPO output pin.
 *              false    --   CMPO is not available on the associate CMPO output pin.
 */
static inline void CMP_EnableOuputPin(CMP_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CR1 |= CMP_CR1_OPE_MASK;
    }
    else
    {
        base->CR1 &= (uint8_t)(~CMP_CR1_OPE_MASK);
    }
}

/*!
 * @brief Get Comparator output.
 *
 * @param base CMP peripheral base address.
 * @retval current analog comparator output 0 or 1
 */
static inline uint8_t CMP_GetComparatorOutput(CMP_Type *base)
{
    return (uint8_t)(base->SCR & CMP_SCR_COUT_MASK);
}

/*!
 * @brief Sets hysteresis level.
 *
 * @param base CMP peripheral base address.
 * @param eHysteresisLevel The programmable hysteresis level to be set, please refer to @ref cmp_hysteresis_level_t for
 * details.
 */
static inline void CMP_SetHysteresisLevel(CMP_Type *base, cmp_hysteresis_level_t eHysteresisLevel)
{
    base->CR0 = ((base->CR0) & (uint8_t)(~CMP_CR0_HYSTCTR_MASK)) | CMP_CR0_HYSTCTR(eHysteresisLevel);
}

/*!
 * @brief Sets comparison speed mode.
 *
 * @param base CMP peripheral base address.
 * @param eComparatorSpeedMode The comparison speed mode, please reference @ref cmp_comparasion_speed_mode_t for
 * details.
 */
static inline void CMP_SetComparasionSpeedMode(CMP_Type *base, cmp_comparasion_speed_mode_t eComparatorSpeedMode)
{
    if (eComparatorSpeedMode == kCMP_ComparsionModeLowSpeed)
    {
        base->CR1 &= (uint8_t)(~CMP_CR1_PMODE_MASK);
    }
    else
    {
        base->CR1 |= CMP_CR1_PMODE_MASK;
    }
}

/*!
 * @brief Enable/Disable comparator invert feature.
 *
 * @param base CMP peripheral base address.
 * @param bEnable Enable/Disable comparator invert feature.
 *              true    --    Inverts the comparator output.
 *              false   --    Does not invert the comparator output.
 */
static inline void CMP_EnableInvertOutput(CMP_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CR1 |= CMP_CR1_INV_MASK;
    }
    else
    {
        base->CR1 &= (uint8_t)(~CMP_CR1_INV_MASK);
    }
}

/*!
 * @brief Enable the window function.
 *
 * @param base CMP peripheral base address.
 * @param bEnable true is enable, false is disable.
 */
static inline void CMP_EnableWindow(CMP_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CR1 |= CMP_CR1_WE_MASK;
    }
    else
    {
        base->CR1 &= ~CMP_CR1_WE_MASK;
    }
}

#if (defined(FSL_FEATURE_CMP_HAS_COWZ_BIT_FIELD) && FSL_FEATURE_CMP_HAS_COWZ_BIT_FIELD)
/*!
 * @brief Set the window output mode.
 *
 * @param base CMP peripheral base address.
 * @param eWindowOutputMode @ref cmp_window_output_mode_t.
 */
static inline void CMP_SetWindowOutputMode(CMP_Type *base, cmp_window_output_mode_t eWindowOutputMode)
{
    if (eWindowOutputMode == kCMP_WindowOutputZeroValue)
    {
        base->CR1 |= CMP_CR1_COWZ_MASK;
    }
    else
    {
        base->CR1 &= ~CMP_CR1_COWZ_MASK;
    }
}
#endif /* FSL_FEATURE_CMP_HAS_COWZ_BIT_FIELD */

/*!
 * @brief Enable/Disable external Sample mode.
 *
 * @param base CMP peripheral base address.
 * @param bEnable true is using external sample mode, false is using interface sample mode.
 */
static inline void CMP_EnableExternalSampleMode(CMP_Type *base, bool bEnable)
{
    base->CR1 = (base->CR1 & (uint8_t)(~CMP_CR1_SE_MASK)) | (CMP_CR1_SE(bEnable));
}

/*!
 * @brief Sets external sample count.
 *
 * @param base CMP peripheral base address.
 * @param eSampleCount The number of consecutive samples that must agree prior to the comparator output
 *              filter accepting a new output state, @ref cmp_external_sample_count_t.
 */
static inline void CMP_SetExternalSampleCount(CMP_Type *base, cmp_external_sample_count_t eSampleCount)
{
    base->CR0 = (base->CR0 & ((uint8_t)~CMP_CR0_FILTER_CNT_MASK)) | CMP_CR0_FILTER_CNT(eSampleCount);
}

/*!
 * @brief Sets internal filter count.
 *
 * @param base CMP peripheral base address.
 * @param eFilterCount The number of consecutive samples that must agree prior to the comparator output
 *              filter accepting a new output state, @ref cmp_filter_count_t.
 */
static inline void CMP_SetInternalFilterCount(CMP_Type *base, cmp_filter_count_t eFilterCount)
{
    base->CR0 = (base->CR0 & ((uint8_t)~CMP_CR0_FILTER_CNT_MASK)) | CMP_CR0_FILTER_CNT(eFilterCount);
}

/*!
 * @brief Sets the internal filter period. It is used as the divider to bus clock.
 *
 * @param base CMP peripheral base address.
 * @param u8FilterPeriod Filter Period. The divider to the bus clock. Available range is 0-255.
 */
static inline void CMP_SetInternalFilterPeriod(CMP_Type *base, uint8_t u8FilterPeriod)
{
    base->FPR = CMP_FPR_FILT_PER(u8FilterPeriod);
}

/*!
 * @brief Configures the internal DAC.
 *
 * @param base   CMP peripheral base address.
 * @param psConfig Pointer to the configuration structure.
 */
void CMP_SetDACConfig(CMP_Type *base, const cmp_dac_config_t *psConfig);

/*!
 * @brief Sets DAC output voltage.
 *
 * @param base CMP peripheral base address.
 * @param u8OutputVoltageDivider The digital value which is related to the desired DAC output voltage,
 */
static inline void CMP_SetDACOutputVoltage(CMP_Type *base, uint8_t u8OutputVoltageDivider)
{
    base->DACCR = CMP_DACCR_VOSEL(u8OutputVoltageDivider);
}

/*!
 * @brief Enable/Disable internal DAC.
 *
 * @param base CMP peripheral base address.
 * @param bEnable Enable/Disable internal DAC.
 *              true    --    Enable internal DAC.
 *              false   --    Disable internal DAC.
 */
static inline void CMP_EnableInternalDAC(CMP_Type *base, bool bEnable)
{
#if defined(CMP_MUXCR_DACEN_MASK)
    if (bEnable)
    {
        base->MUXCR |= CMP_MUXCR_DACEN_MASK;
    }
    else
    {
        base->MUXCR &= (uint8_t)(~CMP_MUXCR_DACEN_MASK);
    }
#else
    if (bEnable)
    {
        base->DACCR |= CMP_DACCR_DACEN_MASK;
    }
    else
    {
        base->DACCR &= (uint8_t)(~CMP_DACCR_DACEN_MASK);
    }
#endif
}

/*!
 * @brief Sets internal DAC's reference voltage source.
 *
 * @param base CMP peripheral base address.
 * @param eDACVrefSource reference voltage source, please @ref cmp_dac_vref_source_t
 */
static inline void CMP_SetDACReferenceVoltageSource(CMP_Type *base, cmp_dac_vref_source_t eDACVrefSource)
{
#if defined(CMP_MUXCR_VRSEL_MASK)
    if (eDACVrefSource == kCMP_DACVrefSourceVin1)
    {
        base->MUXCR &= ~CMP_MUXCR_VRSEL_MASK;
    }
    else
    {
        base->MUXCR |= CMP_MUXCR_VRSEL_MASK;
    }
#else
    if (eDACVrefSource == kCMP_DACVrefSourceVin1)
    {
        base->DACCR &= ~CMP_DACCR_VRSEL_MASK;
    }
    else
    {
        base->DACCR |= CMP_DACCR_VRSEL_MASK;
    }
#endif
}

/*! @} */

/*!
 * @name CMP interrupt interfaces
 * @{
 */

/*!
 * @brief Interrupt request to enable.
 *
 * @param base    CMP peripheral base address.
 * @param eInterruptRequest    Mask value for interrupts. See @ref cmp_interrupt_request_t.
 */
static inline void CMP_EnableInterrupt(CMP_Type *base, cmp_interrupt_request_t eInterruptRequest)
{
#if (defined(FSL_FEATURE_CMP_HAS_DMA) && FSL_FEATURE_CMP_HAS_DMA)
    base->SCR =
        (base->SCR & (~(CMP_SCR_IER_MASK | CMP_SCR_IEF_MASK | CMP_SCR_DMAEN_MASK))) | (uint16_t)eInterruptRequest;
#else
    base->SCR = (base->SCR & (~(CMP_SCR_IER_MASK | CMP_SCR_IEF_MASK))) | (uint16_t)eInterruptRequest;
#endif
}
/*! @} */

/*!
 * @name CMP status interfaces
 * @{
 */

/*!
 * @brief  Gets the status flags.
 *
 * @param  base     CMP peripheral base address.
 *
 * @retval          Mask value for the asserted flags. @ref cmp_output_flag_t.
 */
static inline cmp_output_flag_t CMP_GetStatusFlags(CMP_Type *base)
{
    return (cmp_output_flag_t)(uint16_t)((base->SCR) & (CMP_SCR_CFR_MASK | CMP_SCR_CFF_MASK));
}

/*!
 * @brief Clears the status flags.
 *
 * @param base     CMP peripheral base address.
 * @param eOutputFlag     Mask value for the output flags, @ref cmp_output_flag_t
 */
static inline void CMP_ClearStatusFlags(CMP_Type *base, cmp_output_flag_t eOutputFlag)
{
    base->SCR = (((base->SCR) & (~(CMP_SCR_CFR_MASK | CMP_SCR_CFF_MASK))) | (uint16_t)eOutputFlag);
}

/*! @} */

/*!
 * @name CMP DMA interfaces
 * @{
 */

#if (defined(FSL_FEATURE_CMP_HAS_DMA) && FSL_FEATURE_CMP_HAS_DMA)
/*!
 * @brief Enables CMP DMA request.
 *
 * @param base    CMP peripheral base address.
 * @param eDMARequestType eDMA request type, @ref cmp_dma_request_t
 */
static inline void CMP_EnableDMA(CMP_Type *base, cmp_dma_request_t eDMARequestType)
{
    base->SCR = (base->SCR & (~(CMP_SCR_IER_MASK | CMP_SCR_IEF_MASK | CMP_SCR_DMAEN_MASK))) | (uint16_t)eDMARequestType;
}
#endif

/*!
 * @brief Get CMP result register address for DMA access.
 *
 * @param base    CMP peripheral base address.
 * @return The CMP result register address.
 */
static inline uint32_t CMP_GetComparatorResultRegisterAddress(CMP_Type *base)
{
    return SDK_GET_REGISTER_BYTE_ADDR(CMP_Type, base, SCR);
}
/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* FSL_CMP_H_ */
