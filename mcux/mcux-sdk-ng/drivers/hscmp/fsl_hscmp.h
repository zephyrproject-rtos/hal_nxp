/*
 * Copyright 2021, 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_HSCMP_H_
#define FSL_HSCMP_H_

#include "fsl_common.h"

/*!
 * @addtogroup hscmp
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief HSCMP driver version 2.1.0. */
#define FSL_HSCMP_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

#define HSCMP_RRCR1_RR_CHEN_MASK (HSCMP_RRCR1_RR_CH0EN_MASK | HSCMP_RRCR1_RR_CH1EN_MASK | \
                                  HSCMP_RRCR1_RR_CH2EN_MASK | HSCMP_RRCR1_RR_CH3EN_MASK | \
                                  HSCMP_RRCR1_RR_CH4EN_MASK | HSCMP_RRCR1_RR_CH5EN_MASK | \
                                  HSCMP_RRCR1_RR_CH6EN_MASK | HSCMP_RRCR1_RR_CH7EN_MASK)
#define HSCMP_RRCR1_RR_CHEN_SHIFT (0U)

/*!
 * @brief HSCMP status falgs mask.
 */
enum _hscmp_status_flags
{
    kHSCMP_OutputRisingEventFlag  = HSCMP_CSR_CFR_MASK,  /*!< Rising-edge on the comparison output has occurred. */
    kHSCMP_OutputFallingEventFlag = HSCMP_CSR_CFF_MASK,  /*!< Falling-edge on the comparison output has occurred. */
    kHSCMP_RoundRobinEventFlag    = HSCMP_CSR_RRF_MASK,  /*!< Round-Robin comparison result changed for a channel. */
    kHSCMP_OutputAssertEventFlag  = HSCMP_CSR_COUT_MASK, /*!< Return the current value of the analog comparator output.
                                                              The flag does not support W1C. */
};

/*!
 * @brief HSCMP interrupt enable/disable mask.
 */
enum _hscmp_interrupt_enable
{
    kHSCMP_OutputRisingInterruptEnable  = HSCMP_IER_CFR_IE_MASK, /*!< Comparator interrupt enable rising. */
    kHSCMP_OutputFallingInterruptEnable = HSCMP_IER_CFF_IE_MASK, /*!< Comparator interrupt enable falling. */
    kHSCMP_RoundRobinInterruptEnable    = HSCMP_IER_RRF_IE_MASK, /*!< Round-Robin interrupt enable: assert when comparison
                                                                       result changes for a channel. */
};

/*!
 * @brief HSCMP hysteresis mode. See chip data sheet to get the actual hystersis
 *        value with each level
 */
typedef enum _hscmp_hysteresis_mode
{
    kHSCMP_HysteresisLevel0 = 0U, /*!< The hard block output has level 0 hysteresis internally. */
    kHSCMP_HysteresisLevel1 = 1U, /*!< The hard block output has level 1 hysteresis internally. */
    kHSCMP_HysteresisLevel2 = 2U, /*!< The hard block output has level 2 hysteresis internally. */
    kHSCMP_HysteresisLevel3 = 3U, /*!< The hard block output has level 3 hysteresis internally. */
#if defined(FSL_FEATURE_HSCMP_HAS_HYSTERESIS_LEVEL) && (FSL_FEATURE_HSCMP_HAS_HYSTERESIS_LEVEL == 8)
    kHSCMP_HysteresisLevel4 = 4U, /*!< The hard block output has level 4 hysteresis internally. */
    kHSCMP_HysteresisLevel5 = 5U, /*!< The hard block output has level 5 hysteresis internally. */
    kHSCMP_HysteresisLevel6 = 6U, /*!< The hard block output has level 6 hysteresis internally. */
    kHSCMP_HysteresisLevel7 = 7U, /*!< The hard block output has level 7 hysteresis internally. */
#endif
} hscmp_hysteresis_mode_t;

#if (defined(FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT) && FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT)
/*!
 * @brief HSCMP power mode.
 */
typedef enum _hscmp_power_mode
{
    kHSCMP_LowSpeedPowerMode  = 0U, /*!< Low speed comparison mode is selected. */
    kHSCMP_HighSpeedPowerMode = 1U, /*!< High speed comparison mode is selected. */
    kHSCMP_NanoPowerMode      = 2U, /*!< Nano power comparator is enabled. */
} hscmp_power_mode_t;
#endif

#if (defined(FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL) && FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL)
/*!
 * @brief Functional clock source selection for HSCMP.
 */
typedef enum _hscmp_func_clock
{
    kHSCMP_FuncClockSource0 = 0U, /*!< Select functional clock source 0. */
    kHSCMP_FuncClockSource1 = 1U, /*!< Select functional clock source 1. */
    kHSCMP_FuncClockSource2 = 2U, /*!< Select functional clock source 2. */
    kHSCMP_FuncClockSource3 = 3U, /*!< Select functional clock source 3. */
} hscmp_func_clock_t;
#endif

#if (defined(FSL_FEATURE_HSCMP_HAS_DAC_REF_VOL_SELECT) && FSL_FEATURE_HSCMP_HAS_DAC_REF_VOL_SELECT)
/*!
 * @brief Internal DAC reference voltage source.
 */
typedef enum _hscmp_dac_reference_voltage_source
{
    kHSCMP_VrefSourceVin1 = 0U, /*!< vrefh_int is selected as resistor ladder network supply reference Vin. */
    kHSCMP_VrefSourceVin2 = 1U, /*!< vrefh_ext is selected as resistor ladder network supply reference Vin. */
} hscmp_dac_reference_voltage_source_t;
#endif

#if (defined(FSL_FEATURE_HSCMP_HAS_INPUT_SELECT) && FSL_FEATURE_HSCMP_HAS_INPUT_SELECT)
/*!
 * @brief Input Plus/Minus port source selection (CCR2.INPSEL / CCR2.INMSEL).
 *
 * Selects the signal source fed into the comparator's Plus or Minus port before
 * the 8-to-1 analog mux stage (PSEL/MSEL).
 */
typedef enum _hscmp_input
{
    kHSCMP_InputFromDAC       = 0U, /*!< IN0: input driven from the internal 8-bit DAC output. */
    kHSCMP_InputFromAnalogMux = 1U, /*!< IN1: input driven from the analog 8-to-1 mux (selected by PSEL/MSEL). */
} hscmp_input_t;
#endif

/*!
 * @brief HSCMP window COUT event select for closing the window.
 */
typedef enum _hscmp_window_event_select
{
    kHSCMP_WindowEventRisingEdge  = 0U, /*!< Rising edge of COUT can close the window. */
    kHSCMP_WindowEventFallingEdge = 1U, /*!< Falling edge of COUT can close the window. */
    kHSCMP_WindowEventBothEdges   = 2U, /*!< Both edges of COUT can close the window. */
} hscmp_window_event_select_t;

/*!
 * @brief Configures HSCMP window mode.
 */
typedef struct _hscmp_window_config
{
    bool enableWindowMode;        /*!< Enable window mode. When true, COUTA is clocked by bus clock whenever WINDOW=1. */
    bool enableWindowInvert;      /*!< Invert the WINDOW/SAMPLE input signal. */
    bool enableWindowCloseByEvent; /*!< Allow a COUT edge event (selected by windowEventSelect) to close the window. */
    hscmp_window_event_select_t windowEventSelect; /*!< COUT edge event that can close the window. Only effective when
                                                        enableWindowCloseByEvent is true. */
    bool enableCoutaOwenMode;     /*!< Enable COUTA output-override mode: COUTA is defined by coutaOwLevel when window
                                       is closed instead of holding the last sampled value. */
    bool coutaOwLevel;            /*!< COUTA output level while window is closed (when enableCoutaOwenMode is true).
                                       false=0, true=1. */
} hscmp_window_config_t;

/*!
 * @brief Configure the filter.
 */
typedef struct _hscmp_filter_config
{
    bool enableSample;          /*!< Decide whether to use the external SAMPLE as a sampling clock input. */
    uint8_t filterSampleCount;  /*!< Filter Sample Count. Available range is 1-7; 0 disables the filter. */
    uint8_t filterSamplePeriod; /*!< Filter Sample Period. The divider to the bus clock. Available range is 0-255. The
                                sampling clock must be at least 4 times slower than the system clock to the comparator.
                                So if enableSample is "false", filterSamplePeriod should be set greater than 4.*/
} hscmp_filter_config_t;

/*!
 * @brief configure the internal DAC.
 */
typedef struct _hscmp_dac_config
{
#if (defined(FSL_FEATURE_HSCMP_HAS_DAC_PWR_MODE_SELECT) && FSL_FEATURE_HSCMP_HAS_DAC_PWR_MODE_SELECT)
    bool enableLowPowerMode;  /*!< Decide whether to enable DAC low power mode. */
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_DAC_REF_VOL_SELECT) && FSL_FEATURE_HSCMP_HAS_DAC_REF_VOL_SELECT)
    hscmp_dac_reference_voltage_source_t referenceVoltageSource; /*!< Internal DAC supply voltage reference source. */
#endif
    uint8_t DACValue;         /*!< Value for the DAC Output Voltage. Available range is 0-63.*/
    bool enableDacOutput;     /*!< Enables the DAC output to be available for other on-chip peripherals. */
#if (defined(FSL_FEATURE_HSCMP_HAS_DAC_STOP_EN) && FSL_FEATURE_HSCMP_HAS_DAC_STOP_EN)
    bool enableDacStopMode;   /*!< Allow DAC_EN to enable the DAC in stop mode. */
#endif
} hscmp_dac_config_t;

/*!
 * @brief Configures the comparator.
 */
typedef struct _hscmp_config
{
    bool enableComparator;    /*!< Decide whether to enable the comparator. */
    bool enableStopMode;      /*!< Decide whether to enable the comparator when in STOP modes. */
    bool enableOutputPin;     /*!< Decide whether to enable the comparator is available in selected pin. */
    bool useUnfilteredOutput; /*!< Decide whether to use unfiltered output. */
    bool enableInvertOutput;  /*!< Decide whether to inverts the comparator output. */
    hscmp_hysteresis_mode_t hysteresisMode; /*!< HSCMP hysteresis mode. */
#if (defined(FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT) && FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT)
    hscmp_power_mode_t powerMode;           /*!< HSCMP power mode. */
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_LINKEN) && FSL_FEATURE_HSCMP_HAS_LINKEN)
    bool enableDacLink; /*!< CMP-to-DAC link enable: when true the DAC is enabled/disabled by CMP_EN instead of
                             DCR[DAC_EN]. */
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_OFFSET) && FSL_FEATURE_HSCMP_HAS_OFFSET)
    bool enableOffset;  /*!< Comparator offset control: when true, hysteresis is asymmetric — does not apply when
                             INP crosses INM rising or INM crosses INP falling. */
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL) && FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL)
    hscmp_func_clock_t funcClockSel; /*!< Functional clock source for the comparator core. */
#endif
} hscmp_config_t;

/*!
 * @brief Round-Robin fixed port selection (RRCR1.FIXP).
 */
typedef enum _hscmp_roundrobin_fixed_port
{
    kHSCMP_RoundRobinFixedPlusPort  = 0U, /*!< Fix the Plus port; sweep only the Minus port inputs. */
    kHSCMP_RoundRobinFixedMinusPort = 1U, /*!< Fix the Minus port; sweep only the Plus port inputs. */
} hscmp_roundrobin_fixed_port_t;

/*!
 * @brief Round-Robin channel bitmask.
 *
 * Use OR combinations of these values for:
 * - @ref hscmp_roundrobin_config_t::channelEnableMask (RRCR1 channel enables)
 * - @ref HSCMP_SetRoundRobinPresetState  (RRCSR preset comparison results)
 * - @ref HSCMP_GetRoundRobinLastResult   (RRCSR last comparison results)
 * - @ref HSCMP_GetRoundRobinChannelFlags (RRSR channel-changed flags)
 * - @ref HSCMP_ClearRoundRobinChannelFlags (RRSR clear flags)
 */
enum _hscmp_roundrobin_channel_mask
{
    kHSCMP_RoundRobinChannel0Mask  = (1U << 0U), /*!< Channel 0 mask. */
    kHSCMP_RoundRobinChannel1Mask  = (1U << 1U), /*!< Channel 1 mask. */
    kHSCMP_RoundRobinChannel2Mask  = (1U << 2U), /*!< Channel 2 mask. */
    kHSCMP_RoundRobinChannel3Mask  = (1U << 3U), /*!< Channel 3 mask. */
    kHSCMP_RoundRobinChannel4Mask  = (1U << 4U), /*!< Channel 4 mask. */
    kHSCMP_RoundRobinChannel5Mask  = (1U << 5U), /*!< Channel 5 mask. */
    kHSCMP_RoundRobinChannel6Mask  = (1U << 6U), /*!< Channel 6 mask. */
    kHSCMP_RoundRobinChannel7Mask  = (1U << 7U), /*!< Channel 7 mask. */
};

#if (defined(FSL_FEATURE_HSCMP_HAS_RR_TRG_SEL) && FSL_FEATURE_HSCMP_HAS_RR_TRG_SEL)
/*!
 * @brief Round-Robin trigger source selection.
 */
typedef enum _hscmp_roundrobin_trig_sel
{
    kHSCMP_RoundRobinExternalTrigger = 0U, /*!< External trigger drives round-robin scanning. */
    kHSCMP_RoundRobinInternalTrigger = 1U, /*!< Internal trigger drives round-robin scanning. */
} hscmp_roundrobin_trig_sel_t;
#endif

#if (defined(FSL_FEATURE_HSCMP_HAS_RR_CLK_SEL) && FSL_FEATURE_HSCMP_HAS_RR_CLK_SEL)
/*!
 * @brief Round-Robin sampling clock source selection.
 */
typedef enum _hscmp_roundrobin_clk_sel
{
    kHSCMP_RoundRobinClockSource0 = 0U, /*!< Round-Robin clock source 0. */
    kHSCMP_RoundRobinClockSource1 = 1U, /*!< Round-Robin clock source 1. */
    kHSCMP_RoundRobinClockSource2 = 2U, /*!< Round-Robin clock source 2. */
    kHSCMP_RoundRobinClockSource3 = 3U, /*!< Round-Robin clock source 3. */
} hscmp_roundrobin_clk_sel_t;
#endif

/*!
 * @brief Configures the round-robin comparison mode.
 */
typedef struct _hscmp_roundrobin_config
{
    bool enableRoundRobin;       /*!< Enable round-robin mode. */
    uint8_t sampleClockCount;    /*!< Number of sample clocks after mux switch before sampling (0-3). */
    uint8_t initDelayModulus;    /*!< Initialization delay modulus in bus clock cycles (1-63; 0 means 63). */
    hscmp_roundrobin_fixed_port_t fixedPort; /*!< Fixed port select: sweeps Minus inputs or Plus inputs. */
    uint8_t fixedChannel;        /*!< Fixed channel select (0-7). */
    uint32_t channelEnableMask;  /*!< Bitmask of channels enabled for round-robin scanning.
                                      Use OR combinations of @ref _hscmp_roundrobin_channel_mask values. */
    bool enableRRTimer;          /*!< Enable the round-robin internal timer to auto-trigger scanning (RRCR2). */
    uint32_t timerReloadValue;   /*!< Timer reload value in bus clock cycles (28-bit, valid range 0-0x0FFFFFFFU). */
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_TRG_SEL) && FSL_FEATURE_HSCMP_HAS_RR_TRG_SEL)
    hscmp_roundrobin_trig_sel_t triggerSelect; /*!< Round-Robin trigger source select. */
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_CLK_SEL) && FSL_FEATURE_HSCMP_HAS_RR_CLK_SEL)
    hscmp_roundrobin_clk_sel_t rrClockSel;     /*!< Round-Robin sampling clock source select. */
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_CNT) && FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_CNT)
    uint8_t sampleCount;         /*!< Number of samples for one channel. */
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_THRESHOLD) && FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_THRESHOLD)
    uint8_t sampleThreshold;     /*!< For one channel, when (RR_SAMPLE_THRESHOLD+1) sample results are "1",
                                      the final result is "1"; otherwise the final result is "0".
                                      This value must not be larger than sampleCount. */
#endif
} hscmp_roundrobin_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization
 * @{
 */
/*!
 * @brief Get instance number for HSCMP module.
 *
 * @param base HSCMP peripheral base address
 * @return Instance number if valid base address is provided, otherwise returns 0xFFFFFFFF
 */
uint32_t HSCMP_GetInstance(HSCMP_Type *base);

/*!
 * @brief Initialize the HSCMP
 *
 * This function initializes the HSCMP module. The operations included are:
 * - Enabling the clock for HSCMP module.
 * - Configuring the comparator.
 * - Enabling the HSCMP module optionally.
 * @note For some devices, multiple HSCMP instance share the same clock gate. In this case, to enable the clock for
 * any instance enables all the HSCMPs. Check the chip reference manual for the clock assignment of the HSCMP.
 *
 * @param base HSCMP peripheral base address.
 * @param config Pointer to "hscmp_config_t" structure.
 */
void HSCMP_Init(HSCMP_Type *base, const hscmp_config_t *config);

/*!
 * @brief De-initializes the HSCMP module.
 *
 * This function de-initializes the HSCMP module. The operations included are:
 * - Disabling the HSCMP module.
 * - Disabling the clock for HSCMP module.
 *
 * This function disables the clock for the HSCMP.
 * @note For some devices, multiple HSCMP instance shares the same clock gate. In this case, before disabling the
 * clock for the HSCMP, ensure that all the HSCMP instances are not used.
 *
 * @param base HSCMP peripheral base address.
 */
void HSCMP_Deinit(HSCMP_Type *base);

/*!
 * @brief Gets an available pre-defined settings for the comparator's configuration.
 *
 * This function initializes the comparator configuration structure to these default values:
 * @code
 *   config->enableComparator    = true;
 *   config->enableStopMode      = false;
 *   config->enableOutputPin     = false;
 *   config->useUnfilteredOutput = false;
 *   config->enableInvertOutput  = false;
 *   config->hysteresisMode      = kHSCMP_HysteresisLevel0;
 *   config->powerMode           = kHSCMP_LowSpeedPowerMode;
 * @endcode
 * @param config Pointer to "hscmp_config_t" structure.
 */
void HSCMP_GetDefaultConfig(hscmp_config_t *config);

/*!
 * @brief Enable/Disable HSCMP module.
 *
 * @param base HSCMP peripheral base address.
 * @param enable "true" means enable the module, and "false" means disable the module.
 */
static inline void HSCMP_Enable(HSCMP_Type *base, bool enable)
{
    if (enable)
    {
        base->CCR0 |= HSCMP_CCR0_CMP_EN_MASK;
    }
    else
    {
        base->CCR0 &= ~HSCMP_CCR0_CMP_EN_MASK;
    }
}

/*!
 * @brief Select the input channels for HSCMP. This function determines which input
 *        is selected for the negative and positive Analog Mux.
 *
 * @param base HSCMP peripheral base address.
 * @param positiveChannel Positive side Analog Mux input channel number. Available range is 0-7.
 * @param negativeChannel Negative side Analog Mux input channel number. Available range is 0-7.
 */
void HSCMP_SetInputChannels(HSCMP_Type *base, uint32_t positiveChannel, uint32_t negativeChannel);

#if (defined(FSL_FEATURE_HSCMP_HAS_INPUT_SELECT) && FSL_FEATURE_HSCMP_HAS_INPUT_SELECT)
/*!
 * @brief Select the high-level input source for the Plus and Minus comparator ports.
 *
 * Configures CCR2.INPSEL and CCR2.INMSEL to choose between the internal DAC output
 * (IN0) and the analog 8-to-1 mux path (IN1, whose channel is selected by PSEL/MSEL).
 * Call @ref HSCMP_SetInputChannels to set the PSEL/MSEL channel when using
 * @ref kHSCMP_InputFromAnalogMux.
 *
 * @param base  HSCMP peripheral base address.
 * @param plus  Plus input of the comparator. See @ref hscmp_input_t.
 * @param minus Minus input of the comparator. See @ref hscmp_input_t.
 */
void HSCMP_SetInputMux(HSCMP_Type *base, hscmp_input_t plus, hscmp_input_t minus);
#endif

/*!
 * @brief Enables/disables the DMA request for rising/falling events.
 *        Normally, the HSCMP generates a CPU interrupt if there is a rising/falling event. When
 *        DMA support is enabled and the rising/falling interrupt is enabled , the rising/falling
 *        event forces a DMA transfer request rather than a CPU interrupt instead.
 *
 * @param base HSCMP peripheral base address.
 * @param enable "true" means enable DMA support, and "false" means disable DMA support.
 */
static inline void HSCMP_EnableDMA(HSCMP_Type *base, bool enable)
{
    if (enable)
    {
        base->CCR1 |= HSCMP_CCR1_DMA_EN_MASK;
    }
    else
    {
        base->CCR1 &= ~HSCMP_CCR1_DMA_EN_MASK;
    }
}

/*!
 * @brief Enable/Disable window mode.When any windowed mode is active, COUTA is clocked by
 *        the bus clock whenever WINDOW = 1. The last latched value is held when WINDOW = 0.
 *        The optionally inverted comparator output COUT_RAW is sampled on every bus clock
 *        when WINDOW=1 to generate COUTA.
 *
 * @param base HSCMP peripheral base address.
 * @param enable "true" means enable window mode, and "false" means disable window mode.
 */
static inline void HSCMP_EnableWindowMode(HSCMP_Type *base, bool enable)
{
    if (enable)
    {
        base->CCR1 |= HSCMP_CCR1_WINDOW_EN_MASK;
    }
    else
    {
        base->CCR1 &= ~HSCMP_CCR1_WINDOW_EN_MASK;
    }
}

/*!
 * @brief Configure the window mode with full control over all window-related options.
 *
 * This function configures CCR1 window-related bits: WINDOW_EN, WINDOW_INV, WINDOW_CLS,
 * EVT_SEL, COUTA_OWEN, and COUTA_OW.
 *
 * @param base   HSCMP peripheral base address.
 * @param config Pointer to @ref hscmp_window_config_t structure.
 */
void HSCMP_SetWindowConfig(HSCMP_Type *base, const hscmp_window_config_t *config);

/*!
 * @brief Configures the filter.
 *
 * @param base HSCMP peripheral base address.
 * @param config Pointer to "hscmp_filter_config_t" structure.
 */
void HSCMP_SetFilterConfig(HSCMP_Type *base, const hscmp_filter_config_t *config);

/*!
 * @brief Configure the internal DAC module.
 *
 * @param base HSCMP peripheral base address.
 * @param config Pointer to "hscmp_dac_config_t" structure. If config is "NULL", disable internal DAC.
 */
void HSCMP_SetDACConfig(HSCMP_Type *base, const hscmp_dac_config_t *config);

/*!
 * @brief Dynamically update the DAC output voltage.
 *
 * @param base  HSCMP peripheral base address.
 * @param value New DAC output voltage code.
 */
static inline void HSCMP_SetDACValue(HSCMP_Type *base, uint8_t value)
{
    uint32_t tmp32 = base->DCR;
    tmp32 &= ~HSCMP_DCR_DAC_DATA_MASK;
    tmp32 |= HSCMP_DCR_DAC_DATA(value);
    base->DCR = tmp32;
}

/*! @name Round Robin
 * @{
 */

/*!
 * @brief Configure the round-robin comparison mode.
 *
 * This function configures RRCR0, RRCR1, and RRCR2 registers.
 *
 * @param base   HSCMP peripheral base address.
 * @param config Pointer to @ref hscmp_roundrobin_config_t structure.
 */
void HSCMP_SetRoundRobinConfig(HSCMP_Type *base, const hscmp_roundrobin_config_t *config);

/*!
 * @brief Get the round-robin last comparison results for each channel.
 *
 * Returns the RRCSR register. Each bit[n] reflects the latest comparison output for channel n
 * after the round-robin sweep. Use @ref _hscmp_roundrobin_channel_mask to decode the result.
 *
 * @param base HSCMP peripheral base address.
 * @return Bitmask of last comparison results. See @ref _hscmp_roundrobin_channel_mask.
 */
static inline uint32_t HSCMP_GetRoundRobinLastResult(HSCMP_Type *base)
{
    return base->RRCSR;
}

/*!
 * @brief Set the round-robin preset comparison state for each channel.
 *
 * Writes the RRCSR register to set the reference comparison results. The hardware compares each
 * new sweep result against this preset; if a channel result differs, the corresponding flag in
 * RRSR is set. Call this before enabling round-robin to establish the initial reference state.
 * Use @ref _hscmp_roundrobin_channel_mask values.
 *
 * @param base HSCMP peripheral base address.
 * @param mask Bitmask of channels whose preset comparison output is high (1).
 *             See @ref _hscmp_roundrobin_channel_mask.
 */
static inline void HSCMP_SetRoundRobinPresetState(HSCMP_Type *base, uint32_t mask)
{
    base->RRCSR = mask & 0xFFU;
}

/*!
 * @brief Get the round-robin channel changed flags.
 *
 * Returns the RRSR register. A flag bit is set when the comparison result for that channel
 * differs from the previous round. Use @ref _hscmp_roundrobin_channel_mask to decode.
 *
 * @param base HSCMP peripheral base address.
 * @return Bitmask of channel-changed flags. See @ref _hscmp_roundrobin_channel_mask.
 */
static inline uint32_t HSCMP_GetRoundRobinChannelFlags(HSCMP_Type *base)
{
    return base->RRSR;
}

/*!
 * @brief Clear the round-robin channel changed flags.
 *
 * @param base HSCMP peripheral base address.
 * @param mask Bitmask of flags to clear. See @ref _hscmp_roundrobin_channel_mask.
 */
static inline void HSCMP_ClearRoundRobinChannelFlags(HSCMP_Type *base, uint32_t mask)
{
    base->RRSR = mask;
}

/*! @} */

/*!
 * @brief Enable the interrupts.
 *
 * @param base HSCMP peripheral base address.
 * @param mask Mask value for interrupts. See "_hscmp_interrupt_enable".
 */
static inline void HSCMP_EnableInterrupts(HSCMP_Type *base, uint32_t mask)
{
    base->IER |= mask;
}

/*!
 * @brief Disable the interrupts.
 *
 * @param base HSCMP peripheral base address.
 * @param mask Mask value for interrupts. See "_hscmp_interrupt_enable".
 */
static inline void HSCMP_DisableInterrupts(HSCMP_Type *base, uint32_t mask)
{
    base->IER &= ~mask;
}

/*!
 * @brief Get the HSCMP status flags.
 *
 * @param base HSCMP peripheral base address.
 *
 * @return Mask value for the asserted flags. See "_hscmp_status_flags".
 */
static inline uint32_t HSCMP_GetStatusFlags(HSCMP_Type *base)
{
    return base->CSR;
}

/*!
 * @brief Clear the HSCMP status flags
 *
 * @param base HSCMP peripheral base address.
 * @param mask Mask value for the flags. See "_hscmp_status_flags".
 */
static inline void HSCMP_ClearStatusFlags(HSCMP_Type *base, uint32_t mask)
{
    base->CSR = mask;
}

/*! @} */

/*! @} */

#endif /* FSL_HSCMP_H_ */
