/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_EMIOS_H_
#define FSL_EMIOS_H_

#include "fsl_common.h"

/*!
 * @addtogroup emios
 * @{
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief eMIOS driver version 2.0.0. */
#define FSL_EMIOS_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief eMIOS Unified Channel (UC) Modulus Counter mode masks */
#define UC_MC_MODE_MASK       (0x7CU)   /*!< Mask for Modulus Counter modes */
#define UC_MC_MODE_MC_UP      (0x10U)   /*!< Modulus Counter Up mode */
#define UC_MC_MODE_MC_UPDOWN  (0x14U)   /*!< Modulus Counter Up/Down mode  */
#define UC_MC_MODE_MCB_UP     (0x50U)   /*!< Modulus Counter Buffered Up mode */
#define UC_MC_MODE_MCB_UPDOWN (0x54U)   /*!< Modulus Counter Buffered Up/Down mode */

/*! @brief eMIOS Unified Channel (UC) PWM mode masks */
#define UC_PWM_MODE_MASK   (0x7CU)      /*!< Mask for PWM modes */
#define UC_PWM_MODE_OPWFMB (0x58U)      /*!< Output Pulse Width and Frequency Modulation Buffered mode */
#define UC_PWM_MODE_OPWMCB (0x5CU)      /*!< Center-aligned Output PWM with Dead Time Insertion Buffered mode */
#define UC_PWM_MODE_OPWMB  (0x60U)      /*!< Output PWM Buffered mode */
#define UC_PWM_MODE_OPWMT  (0x24U)      /*!< Output PWM with Trigger mode */

/*! @brief eMIOS Unified Channel (UC) Output Compare mode masks */
#define UC_OC_MODE_MASK (0x6U)      /*!< Mask for Output Compare modes */
#define UC_OC_MODE_SAOC (0x2U)      /*!< Single Action Output Compare mode */
#define UC_OC_MODE_DAOC (0x6U)      /*!< Double Action Output Compare mode */

/*! @brief eMIOS Unified Channel (UC) Input Capture mode masks */
#define UC_IC_MODE_MASK (0xFU)      /*!< Mask for Input Capture modes */
#define UC_IC_MODE_SAIC (0x2U)      /*!< Single Action Input Capture mode */
#define UC_IC_MODE_IPWM (0x4U)      /*!< Input Pulse Width Measurement mode */
#define UC_IC_MODE_IPM  (0x5U)      /*!< Input Period Measurement mode */
#define UC_IC_MODE_PECC (0xAU)      /*!< Pulse Edge Counting Continuous mode */
#define UC_IC_MODE_PECS (0xBU)      /*!< Pulse Edge Counting Single-shot mode */

/*! @brief eMIOS counter bus definitions */
#define EMIOS_COUNTERBUS_A    (23U)             /*!< Global counter bus A (driven by UC23) */
#define EMIOS_COUNTERBUS_BCD  ((16U) | (8U))    /*!< Local counter buses B, C, D (driven by UC16, UC8, UC0) */
#define EMIOS_COUNTERBUS_F    (22U)             /*!< Second global counter bus F (driven by UC22) */

/*! @brief List of eMIOS UC index used in logic OR. */
typedef enum _emios_uc_index
{
    kEMIOS_UC0_Mask = (1U << 0),    /*!< UC 0 Mask */
    kEMIOS_UC1_Mask = (1U << 1),    /*!< UC 1 Mask */
    kEMIOS_UC2_Mask = (1U << 2),    /*!< UC 2 Mask */
    kEMIOS_UC3_Mask = (1U << 3),    /*!< UC 3 Mask */
    kEMIOS_UC4_Mask = (1U << 4),    /*!< UC 4 Mask */
    kEMIOS_UC5_Mask = (1U << 5),    /*!< UC 5 Mask */
    kEMIOS_UC6_Mask = (1U << 6),    /*!< UC 6 Mask */
    kEMIOS_UC7_Mask = (1U << 7),    /*!< UC 7 Mask */
    kEMIOS_UC8_Mask = (1U << 8),    /*!< UC 8 Mask */
    kEMIOS_UC9_Mask = (1U << 9),    /*!< UC 9 Mask */
    kEMIOS_UC10_Mask = (1U << 10),  /*!< UC 10 Mask */
    kEMIOS_UC11_Mask = (1U << 11),  /*!< UC 11 Mask */
    kEMIOS_UC12_Mask = (1U << 12),  /*!< UC 12 Mask */
    kEMIOS_UC13_Mask = (1U << 13),  /*!< UC 13 Mask */
    kEMIOS_UC14_Mask = (1U << 14),  /*!< UC 14 Mask */
    kEMIOS_UC15_Mask = (1U << 15),  /*!< UC 15 Mask */
    kEMIOS_UC16_Mask = (1U << 16),  /*!< UC 16 Mask */
    kEMIOS_UC17_Mask = (1U << 17),  /*!< UC 17 Mask */
    kEMIOS_UC18_Mask = (1U << 18),  /*!< UC 18 Mask */
    kEMIOS_UC19_Mask = (1U << 19),  /*!< UC 19 Mask */
    kEMIOS_UC20_Mask = (1U << 20),  /*!< UC 20 Mask */
    kEMIOS_UC21_Mask = (1U << 21),  /*!< UC 21 Mask */
    kEMIOS_UC22_Mask = (1U << 22),  /*!< UC 22 Mask */
    kEMIOS_UC23_Mask = (1U << 23),  /*!< UC 23 Mask */
} emios_uc_index_t;

/*! @brief eMIOS Unified Channel (UC) status flags */
enum _emios_uc_status_flags
{
    kEMIOS_EventFlag = EMIOS_S_FLAG_MASK,       /*!< A match or capture event occurred */
    kEMIOS_OverflowFlag = EMIOS_S_OVFL_MASK,    /*!< Counter overflow occurred */
    kEMIOS_OverrunFlag = EMIOS_S_OVR_MASK,      /*!< New event occurred before previous was serviced */
};

/*! @brief eMIOS GPIO modes */
typedef enum _emios_uc_gpio_mode
{
    kEMIOS_GPIO_Input  = 0x0U,  /*!< GPIO input mode. */
    kEMIOS_GPIO_Output = 0x1U,  /*!< GPIO output mode. */
} emios_uc_gpio_mode_t;

/*! @brief eMIOS Modulus Counter (MC) modes */
typedef enum _emios_uc_mc_mode
{
    kEMIOS_MC_UpCount               = 0x10U,    /*!< Modulus Counter Up mode */
    kEMIOS_MC_UpDownCount           = 0x14U,    /*!< Modulus Counter Up/Down mode */
    kEMIOS_MCB_UpCount              = 0x50U,    /*!< Modulus Counter Buffered Up mode */
    kEMIOS_MCB_UpDownCount_Flag     = 0x54U,    /*!< Modulus Counter Buffered Up/Down mode with flag on match start */
    kEMIOS_MCB_UpDownCount_FlagBoth = 0x56U,    /*!< Modulus Counter Buffered Up/Down mode with flag on both edges */
} emios_uc_mc_mode_t;

/*! @brief eMIOS PWM modes */
typedef enum _emios_uc_pwm_mode
{
    kEMIOS_OPWFMB_Flag               = 0x58U,   /*!< OPWFMB mode with flag on BS1 match */
    kEMIOS_OPWFMB_FlagBoth           = 0x5AU,   /*!< OPWFMB mode with flags on both matches */
    kEMIOS_OPWMCB_TrailEdge_Flag     = 0x5CU,   /*!< OPWMCB mode with trailing edge dead time and flag */
    kEMIOS_OPWMCB_TrailEdge_FlagBoth = 0x5EU,   /*!< OPWMCB mode with trailing edge dead time and flag on both edges */
    kEMIOS_OPWMCB_LeadEdge_Flag      = 0x5DU,   /*!< OPWMCB mode with leading edge dead time and flag */
    kEMIOS_OPWMCB_LeadEdge_FlagBoth  = 0x5FU,   /*!< OPWMCB mode with leading edge dead time and flag on both edges */
    kEMIOS_OPWMB_Flag                = 0x60U,   /*!< OPWMB mode with flag on BS1 match */
    kEMIOS_OPWMB_FlagBoth            = 0x62U,   /*!< OPWMB mode with flag on both matches */
    kEMIOS_OPWMT                     = 0x26U,   /*!< OPWMT mode with trigger generation */
} emios_uc_pwm_mode_t;

/*! @brief eMIOS Output Compare (OC) modes */
typedef enum _emios_uc_oc_mode
{
    kEMIOS_SAOC          = 0x3U,    /*!< Single Action Output Compare mode */
    kEMIOS_DAOC_Flag     = 0x6U,    /*!< Double Action Output Compare mode with flag on B match */
    kEMIOS_DAOC_FlagBoth = 0x7U,    /*!< Double Action Output Compare mode with flag on both matches */
} emios_uc_oc_mode_t;

/*! @brief eMIOS Input Capture (IC) modes */
typedef enum _emios_uc_ic_mode
{
    kEMIOS_SAIC            = 0x2U,  /*!< Single Action Input Capture mode */
    kEMIOS_SAIC_InputLevel = 0x42U, /*!< Single Action Input Capture mode with input level indication */
    kEMIOS_IPWM            = 0x4U,  /*!< Input Pulse Width Measurement mode */
    kEMIOS_IPM             = 0x5U,  /*!< Input Period Measurement mode */
    kEMIOS_PEC_Continuous  = 0xAU,  /*!< Pulse Edge Counting mode (continuous) */
    kEMIOS_PEC_SingleShot  = 0xBU,  /*!< Pulse Edge Counting mode (single shot) */
} emios_uc_ic_mode_t;

/*! @brief eMIOS clock source selection */
typedef enum _emios_clock_source
{
    kEMIOS_ClkSrcInternal = 0x0U,     /*!< Use internal clock source (prescaled system clock) */
    kEMIOS_ClkSrcExternal = 0x1U,     /*!< Use external clock source */
} emios_clock_source_t;

/*! @brief eMIOS counter reset timing */
typedef enum _emios_counter_reset
{
    kEMIOS_ResetMatchStart = 0x0U,  /*!< Reset counter at match start */
    kEMIOS_ResetMatchEnd   = 0x2U,  /*!< Reset counter at match end */
} emios_counter_reset_t;

/*! @brief eMIOS prescaler clock source */
typedef enum _emios_prescaler_source
{
    kEMIOS_Prescaler_PrescaledClock = 0x0U, /*!< Use prescaled clock (from global prescaler) */
    kEMIOS_Prescaler_ModuleClock    = 0x1U, /*!< Use module clock (eMIOS module clock) */
} emios_prescaler_source_t;

/*! @brief eMIOS output polarity */
typedef enum _emios_output_polarity
{
    kEMIOS_Output_ActiveHigh = 0x0U,    /*!< Active high output polarity */
    kEMIOS_Output_ActiveLow  = 0x1U,    /*!< Active low output polarity */
} emios_output_polarity_t;

/*! @brief eMIOS counter bus selection */
typedef enum _emios_counterbus
{
    kEMIOS_CounterBus_A         = 0x00U,    /*!< Use global counter bus A (UC23) */
    kEMIOS_CounterBus_BCD       = 0x01U,    /*!< Use local counter bus B, C, or D (based on channel) */
    kEMIOS_CounterBus_F         = 0x02U,    /*!< Use global counter bus F (UC22) */
    kEMIOS_CounterBus_Internal  = 0x03U,    /*!< Use internal counter (channel's own counter) */
} emios_counterbus_t;

/*! @brief eMIOS output disable source selection */
typedef enum _emios_output_disable_source
{
    kEMIOS_OutputDisable_Source_0 = 0x0U,       /*!< Use output disable source 0 */
    kEMIOS_OutputDisable_Source_1 = 0x1U,       /*!< Use output disable source 1 */
    kEMIOS_OutputDisable_Source_2 = 0x2U,       /*!< Use output disable source 2 */
    kEMIOS_OutputDisable_Source_3 = 0x3U,       /*!< Use output disable source 3 */
    kEMIOS_OutputDisable_Source_None = 0xFU,    /*!< No output disable source selected */
} emios_output_disable_source_t;

/*! @brief eMIOS output compare behavior */
typedef enum _emios_oc_behavior
{
    kEMIOS_OC_Set    = 0x0U,    /*!< Set output on match (to EDPOL value) */
    kEMIOS_OC_Toggle = 0x1U,    /*!< Toggle output on match */
} emios_oc_behavior_t;

/*! @brief eMIOS input capture edge selection */
typedef enum _emios_ic_edge_select
{
    kEMIOS_IC_SingleEdge = 0x0U,    /*!< Capture on single edge (rising or falling) */
    kEMIOS_IC_BothEdge   = 0x1U,    /*!< Capture on both edges */
} emios_ic_edge_select_t;

/*! @brief eMIOS input capture edge polarity */
typedef enum _emios_ic_edge_polarity
{
    kEMIOS_IC_FallingEdge = 0x0U,   /*!< Capture on falling edges */
    kEMIOS_IC_RisingEdge  = 0x1U,   /*!< Capture on rising edges */
} emios_ic_edge_polarity_t;

/*! @brief eMIOS input filter clock source */
typedef enum _emios_filter_source
{
    kEMIOS_Filter_PrescaledClock = 0x0U,    /*!< Use prescaled clock for input filter */
    kEMIOS_Filter_ModuleClock    = 0x1U,    /*!< Use module clock for input filter */
} emios_filter_source_t;

/*! @brief eMIOS input filter width */
typedef enum _emios_filter_width
{
    kEMIOS_Filter_Bypassed = 0x0U,      /*!< Input filter bypassed */
    kEMIOS_Filter_2_Cycle  = 0x1U,      /*!< Minimum 2 clock cycles pulse width */
    kEMIOS_Filter_4_Cycle  = 0x2U,      /*!< Minimum 4 clock cycles pulse width */
    kEMIOS_Filter_8_Cycle  = 0x4U,      /*!< Minimum 8 clock cycles pulse width */
    kEMIOS_Filter_16_Cycle = 0x8U,      /*!< Minimum 16 clock cycles pulse width */
} emios_filter_width_t;

/*! @brief eMIOS module configuration structure. */
typedef struct _emios_config
{
    uint8_t prescale;       /*!< Global prescaler value from 1 (0) to 256 (0xFF). */
    bool allowFreezeUC;     /*!< Allow all UCs enter Freeze state when chip is in Debug mode. */
    bool useGlobalTimeBase; /*!< Enable global timebase or disable. */
} emios_config_t;

/*!
 * @brief Modulus Counter (MC) configuration structure.
 * Configures channels in Modulus Counter or Modulus Counter Buffered modes.
 */
typedef struct _emios_uc_mc_config
{
    uint32_t period;                /*!< Counter period value written to register An directly. */
    uint8_t prescale;               /*!< Channel prescaler value 1 (0) to 16 (0xF) */
    uint8_t reloadOutputDelay;      /*!< Delay between reload signal assertions 1 (0) to 32 (0x1F) */
    emios_uc_mc_mode_t ucMode;                  /*!< Counter mode */
    emios_clock_source_t clockSource;           /*!< Internal or external clock source. */
    emios_counter_reset_t counterResetTiming;   /*!< Reset counter at match start or end */
    emios_prescaler_source_t prescalerSource;   /*!< Clock source for prescaler. */
    emios_ic_edge_select_t edgeSelect;          /*!< Edge selection for external clock */
    emios_ic_edge_polarity_t edgePolarity;      /*!< Edge polarity for external clock */
    bool enableFreeze;                          /*!< Allow channel to freeze in debug mode */
} emios_uc_mc_config_t;

/*!
 * @brief PWM configuration structure.
 * Configures channels in various PWM output modes.
 */
typedef struct _emios_uc_pwm_config
{
    uint32_t period;                /*!< PWM period in ticks */
    uint32_t dutyCycle;             /*!< PWM duty cycle in ticks */
    uint32_t deadTime;              /*!< Dead time insertion value in ticks (for OPWMCB mode) */
    uint32_t phaseShift;            /*!< Phase shift value in ticks (for OPWMB OPWMT mode) */
    uint32_t triggerPosition;       /*!< Trigger position in ticks (for OPWMT mode) */
    uint8_t prescale;               /*!< Channel prescaler value 1 (0) to 16 (0xF) (for OPWFMB OPWMCB mode) */
    emios_uc_pwm_mode_t ucMode;                 /*!< PWM mode */
    emios_counterbus_t counterBus;              /*!< Counter bus selection (A, BCD, F) */
    emios_output_polarity_t polarity;           /*!< Output active high or low */
    emios_prescaler_source_t prescalerSource;   /*!< Clock source for prescaler (for OPWFMB OPWMCB mode) */
    emios_output_disable_source_t outputDisableSource;  /*!< Output disable source */
    bool enableFreeze;      /*!< Allow channel to freeze in debug mode */
} emios_uc_pwm_config_t;

/*!
 * @brief Output Compare configuration structure.
 * Configures channels in Single Action or Double Action Output Compare modes.
 */
typedef struct _emios_uc_oc_config
{
    uint32_t leadingEdge;           /*!< Leading edge position in ticks */
    uint32_t trailingEdge;          /*!< Trailing edge position in ticks (DAOC only) */
    emios_uc_oc_mode_t ucMode;      /*!< Output Compare mode (SAOC, DAOC) */
    emios_counterbus_t counterBus;  /*!< Counter bus selection (A, BCD, F) */
    emios_oc_behavior_t ocBehavior; /*!< Output behavior on match (Set or Toggle) */
    emios_output_polarity_t polarity;   /*!< Output active high or low */
    bool enableFreeze;      /*!< Allow channel to freeze in debug mode */
} emios_uc_oc_config_t;

/*!
 * @brief Input Capture configuration structure.
 * Configures channels in various input capture modes.
 */
typedef struct _emios_uc_ic_config
{
    uint32_t startTime;         /*!< Start time for measurement window (PEC mode) */
    uint32_t endTime;           /*!< End time for measurement window (PEC mode) */
    emios_uc_ic_mode_t ucMode;              /*!< Input Capture mode */
    emios_counterbus_t counterBus;          /*!< Counter bus selection (A, BCD, F) */
    emios_ic_edge_select_t edgeSelect;      /*!< Single or both edges trigger */
    emios_ic_edge_polarity_t edgePolarity;  /*!< Edge polarity for trigger */
    emios_filter_source_t filterClock;      /*!< Clock source for input filter */
    emios_filter_width_t filterWidth;       /*!< Input filter width (bypass to 16 cycles) */
    bool enableFreeze;      /*!< Allow channel to freeze in debug mode */
} emios_uc_ic_config_t;

/*!
 * @brief GPIO configuration structure.
 * Configures channels in General Purpose Input/Output mode.
 */
typedef struct _emios_uc_gpio_config
{
    emios_uc_gpio_mode_t ucMode;            /*!< GPIO mode (Input or Output) */
    emios_ic_edge_polarity_t edgePolarity;  /*!< Edge polarity for input mode */
    bool enableCaptureFlag;                 /*!< Enable capture flag generation in input mode */
} emios_uc_gpio_config_t;

/******************************************************************************
 * API
 *****************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Get the eMIOS instance from peripheral base address.
 *
 * @param base eMIOS peripheral base address.
 * @return eMIOS instance.
 */
uint32_t EMIOS_GetInstance(EMIOS_Type *base);

/*!
 * @brief Initialize eMIOS instance.
 *
 * @param base   eMIOS peripheral base address.
 * @param config Pointer to user's eMIOS config structure.
 */
void EMIOS_Init(EMIOS_Type *base, const emios_config_t *config);

/*!
 * @brief Disable eMIOS module and gate eMIOS clock.
 * 
 * @param base eMIOS peripheral base address
 */
void EMIOS_Deinit(EMIOS_Type *base);

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the eMIOS configuration structure to default values. The default
 * values are as follows.
 *   config->prescale = 0U;
 *   config->allowFreezeUC = false;
 *   config->useGlobalTimeBase = false;
 * 
 * @param config Pointer to the eMIOS configuration structure.
 */
void EMIOS_GetDefaultConfig(emios_config_t *config);

/*! @} */

/*!
 * @name Configuration.
 * @{
 */

/*!
 * @brief Configure Unified Channel (UC) as Modulus Counter.
 *
 * This function configures a channel to operate in Modulus Counter (MC) or
 * Modulus Counter Buffered (MCB) mode. The counter can be configured for:
 * - Up count or Up/Down count modes
 * - Internal or external clock source
 * - Various reset timing options
 *
 * @param base    eMIOS peripheral base address.
 * @param config  Pointer to Modulus Counter configuration structure.
 * @param channel Channel number to configure.
 */
void EMIOS_ConfigModulusCounter(EMIOS_Type *base, const emios_uc_mc_config_t *config, uint8_t channel);

/*!
 * @brief Configure Unified Channel (UC) for PWM operation.
 *
 * This function configures a channel for various PWM modes:
 * - OPWFMB: Output Pulse Width and Frequency Modulation Buffered
 * - OPWMCB: Center Aligned Output PWM with Dead Time Insertion Buffered
 * - OPWMB: Output PWM Buffered
 * - OPWMT: Output PWM with Trigger
 *
 * @param base    eMIOS peripheral base address.
 * @param config  Pointer to PWM configuration structure.
 * @param channel Channel number to configure.
 */
void EMIOS_ConfigPWM(EMIOS_Type *base, const emios_uc_pwm_config_t *config, uint8_t channel);

/*!
 * @brief Configure Unified Channel (UC) for Output Compare operation.
 *
 * This function configures a channel for:
 * - SAOC: Single Action Output Compare
 * - DAOC: Double Action Output Compare
 *
 * @param base    eMIOS peripheral base address.
 * @param config  Pointer to Output Compare configuration structure.
 * @param channel Channel number to configure.
 */
void EMIOS_ConfigOutputCompare(EMIOS_Type *base, const emios_uc_oc_config_t *config, uint8_t channel);

/*!
 * @brief Configure Unified Channel (UC) for Input Capture operation.
 *
 * This function configures a channel for various input capture modes:
 * - SAIC: Single Action Input Capture
 * - IPWM: Input Pulse Width Measurement
 * - IPM: Input Period Measurement
 * - PEC: Pulse Edge Counting
 *
 * @param base    eMIOS peripheral base address.
 * @param config  Pointer to Input Capture configuration structure.
 * @param channel Channel number to configure.
 */
void EMIOS_ConfigInputCapture(EMIOS_Type *base, const emios_uc_ic_config_t *config, uint8_t channel);

/*!
 * @brief Configure Unified Channel (UC) for GPIO operation.
 *
 * This function configures a channel for:
 * - GPIO Input or output mode
 * - Edge polarity for input mode
 * - Capture flag enable/disable
 *
 * @param base    eMIOS peripheral base address.
 * @param config  Pointer to GPIO configuration structure.
 * @param channel Channel number to configure.
 */
void EMIOS_ConfigGPIO(EMIOS_Type *base, const emios_uc_gpio_config_t *config, uint8_t channel);

/*!
 * @brief Update PWM configuration for a channel.
 *
 * This function updates the PWM parameters (duty cycle, period, etc.) for already configured PWM channel.
 *
 * @param base    eMIOS peripheral base address.
 * @param config  Pointer to PWM configuration structure.
 * @param channel Channel number to update.
 */
void EMIOS_UpdatePWM(EMIOS_Type *base, const emios_uc_pwm_config_t *config, uint8_t channel);

/*! @} */

/*!
 * @name Misc operation.
 * @{
 */

/*!
 * @brief Set Unified Channel (UC) A register value.
 *
 * This function writes a value to the A register of a specified eMIOS channel.
 * The A register is used for various purposes depending on the channel mode:
 * - In PWM modes: Stores duty cycle or leading edge position
 * - In input capture modes: Stores captured values
 * - In modulus counter modes: Stores period value
 *
 * @param base    eMIOS peripheral base address.
 * @param value   Value to write to the A register.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_SetAn(EMIOS_Type *base, uint32_t value, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].A = value;
}

/*!
 * @brief Set Unified Channel (UC) B register value.
 *
 * This function writes a value to the B register of a specified eMIOS channel.
 * The B register is used for various purposes depending on the channel mode:
 * - In PWM modes: Stores period, dead time value or trailing edge position
 * - In input capture modes: Stores captured values
 *
 * @param base    eMIOS peripheral base address.
 * @param value   Value to write to the B register.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_SetBn(EMIOS_Type *base, uint32_t value, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].B = value;
}

/*!
 * @brief Set Unified Channel (UC) Alternate A register value.
 *
 * This function writes a value to the ALTA register of a specified eMIOS channel.
 * The ALTA register is primarily used in PWM with Trigger (OPWMT) mode to store
 * the trigger position value.
 *
 * @param base    eMIOS peripheral base address.
 * @param value   Value to write to the ALTA register.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_SetALTAn(EMIOS_Type *base, uint32_t value, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].ALTA = value;
}

/*!
 * @brief Set Unified Channel (UC) counter value.
 *
 * This function writes a value to the internal counter of a specified eMIOS channel.
 * The counter is used as a timebase in various modes. In modulus counter modes,
 * writing to the counter can be used to initialize or reset the counting sequence.
 *
 * @param base    eMIOS peripheral base address.
 * @param value   Value to write to the counter.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_SetCNTn(EMIOS_Type *base, uint32_t value, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].CNT = value;
}

/*!
 * @brief Get Unified Channel (UC) A register value.
 *
 * This function reads the current value from the A register of a specified eMIOS channel.
 * The value returned depends on the channel's current mode of operation.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to read.
 * @return Current value of the A register (16-bit value).
 */
static inline uint32_t EMIOS_GetAn(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    return (base->UC[channel].A & EMIOS_A_A_MASK);
}

/*!
 * @brief Get Unified Channel (UC) B register value.
 *
 * This function reads the current value from the B register of a specified eMIOS channel.
 * The value returned depends on the channel's current mode of operation.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to read.
 * @return Current value of the B register (16-bit value).
 */
static inline uint32_t EMIOS_GetBn(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    return (base->UC[channel].B & EMIOS_B_B_MASK);
}

/*!
 * @brief Get Unified Channel (UC) Alternate A register value.
 *
 * This function reads the current value from the ALTA register of a specified eMIOS channel.
 * In Pulse Edge Counting mode, this returns number of detected pulses.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to read.
 * @return Current value of the ALTA register (16-bit value).
 */
static inline uint32_t EMIOS_GetALTAn(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    return (base->UC[channel].ALTA & EMIOS_ALTA_ALTA_MASK);
}

/*!
 * @brief Set Unified Channel (UC) edge polarity.
 *
 * This function configures the edge polarity for a specified eMIOS channel.
 * The edge polarity determines:
 * - For input modes: Which edge(s) trigger captures
 * - For output modes: Selects the logic level on the output pin
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 * @param value   Edge polarity value depends on mode.
 */
static inline void EMIOS_SetUCEdgePolarity(EMIOS_Type *base, uint8_t channel, uint32_t value)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].C = (base->UC[channel].C & ~(EMIOS_C_EDPOL_MASK)) | EMIOS_C_EDPOL(value);
}

/*!
 * @brief Set Unified Channel (UC) edge selection.
 *
 * This function configures the edge selection for a specified eMIOS channel.
 * The edge selection determines:
 * - For input modes: Whether single or both edges trigger captures
 * - For SAOC mode: Selects the behavior of the output flip-flop at each match
 * - For GPIO in mode: Selects whether an edge asserts the input capture flag
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 * @param value   Edge selection value depends on mode.
 */
static inline void EMIOS_SetUCEdgeSelection(EMIOS_Type *base, uint8_t channel, uint32_t value)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].C = (base->UC[channel].C & ~(EMIOS_C_EDSEL_MASK)) | EMIOS_C_EDSEL(value); 
}

/*!
 * @brief Set Unified Channel (UC) force match A control.
 *
 * This function forces a match on comparator A for the specified channel.
 * When forced, the output behaves as if a match occurred on comparator A.
 * This is useful for manually controlling output states in output modes.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 * @param value   true to force match, false to clear force match.
 */
static inline void EMIOS_SetUCForceMatchA(EMIOS_Type *base, uint8_t channel, bool value)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint8_t boolConvert = (value == false) ? 0U : 1U;
    base->UC[channel].C = (base->UC[channel].C & ~(EMIOS_C_FORCMA_MASK)) | EMIOS_C_FORCMA(boolConvert);
}

/*!
 * @brief Set Unified Channel (UC) force match B control.
 *
 * This function forces a match on comparator B for the specified channel.
 * When forced, the output behaves as if a match occurred on comparator B.
 * This is useful for manually controlling output states in output modes.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 * @param value   true to force match, false to clear force match.
 */
static inline void EMIOS_SetUCForceMatchB(EMIOS_Type *base, uint8_t channel, bool value)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint8_t boolConvert = (value == false) ? 0U : 1U;
    base->UC[channel].C = (base->UC[channel].C & ~(EMIOS_C_FORCMB_MASK)) | EMIOS_C_FORCMB(boolConvert);
}

/*!
 * @brief Enable Unified Channel (UC) prescaler.
 *
 * This function enables the channel's clock prescaler. The prescaler divides
 * the global clock to provide the channel's timebase clock.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_EnableUCPrescaler(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].C |= EMIOS_C_UCPREN_MASK;
}

/*!
 * @brief Disable Unified Channel (UC) prescaler.
 *
 * This function disables the channel's clock prescaler, stopping the channel's
 * timebase clock.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_DisableUCPrescaler(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].C &= ~EMIOS_C_UCPREN_MASK;
}

/*!
 * @brief Enable eMIOS global prescaler.
 *
 * This function enables the global clock prescaler that provides the base clock
 * for all channels' prescalers.
 *
 * @param base eMIOS peripheral base address.
 */
static inline void EMIOS_EnableGlobalPrescaler(EMIOS_Type *base)
{
    base->MCR |= EMIOS_MCR_GPREN_MASK;
}

/*!
 * @brief Disable eMIOS global prescaler.
 *
 * This function disables the global clock prescaler, stopping the base clock
 * for all channels.
 *
 * @param base eMIOS peripheral base address.
 */
static inline void EMIOS_DisableGlobalPrescaler(EMIOS_Type *base)
{
    base->MCR &= ~EMIOS_MCR_GPREN_MASK;
}

/*!
 * @brief Set channel output update control.
 *
 * This function enables or disables output updates for the specified channels.
 * When disabled, writes to channel registers don't affect the outputs until
 * updates are re-enabled, allowing synchronized updates of multiple channels.
 *
 * @param base   eMIOS peripheral base address.
 * @param mask   Bitmask of channels to configure @ref _emios_uc_index enumerations.
 * @param enable true to enable output updates, false to disable.
 */
static inline void EMIOS_SetChannelOutputUpdate(EMIOS_Type *base, uint32_t mask, bool enable)
{
    if (enable)
    {
        base->OUDIS &= ~mask;
    }
    else
    {
        base->OUDIS |= mask;
    }
}

/*!
 * @brief Enable or disable channels.
 *
 * This function enables or disables the specified channels by stopping its clock.
 *
 * @param base   eMIOS peripheral base address.
 * @param mask   Bitmask of channels to configure @ref _emios_uc_index enumerations.
 * @param enable true to enable channels, false to disable.
 */
static inline void EMIOS_SetChannelStatus(EMIOS_Type *base, uint32_t mask, bool enable)
{
    if (enable)
    {
        base->UCDIS &= ~mask;
    }
    else
    {
        base->UCDIS |= mask;
    }
}

/*!
 * @brief Get Unified Channel (UC) counter bus period.
 *
 * @param base    eMIOS peripheral base address.
 * @param source  Counter bus to query (A, BCD, or F).
 * @param channel Channel number associated with the counter bus.
 * @return Period value of the UC counter bus.
 */
uint32_t EMIOS_GetCounterBusPeriod(EMIOS_Type *base, emios_counterbus_t source, uint8_t channel);

/*!
 * @brief Get Unified Channel (UC) counter bus mode.
 *
 * @param base    eMIOS peripheral base address.
 * @param source  Counter bus to query (A, BCD, or F).
 * @param channel Channel number associated with the counter bus.
 * @return Mode of the UC counter bus (MC or MCB mode).
 */
uint32_t EMIOS_GetCounterBusMode(EMIOS_Type *base, emios_counterbus_t source, uint8_t channel);

/*! @} */

/*!
 * @name Interrupts and DMA Interface
 * @{
 */

/*!
 * @brief Enable Unified Channel (UC) interrupt.
 *
 * This function enables the interrupt generation for the specified channel.
 * When enabled, the channel will generate interrupts on flag events (captures,
 * compares, etc.) according to its configured mode.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_EnableUCInterrupt(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].C &= ~EMIOS_C_DMA_MASK;
    base->UC[channel].C |= EMIOS_C_FEN_MASK;
}

/*!
 * @brief Enable Unified Channel (UC) DMA request.
 *
 * This function enables DMA request generation for the specified channel.
 * When enabled, the channel will generate DMA requests on flag events (captures,
 * compares, etc.) according to its configured mode.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_EnableUCDMA(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].C |= (EMIOS_C_FEN_MASK | EMIOS_C_DMA_MASK);
}

/*!
 * @brief Disable Unified Channel (UC) interrupt and DMA request.
 *
 * This function disables both interrupt and DMA request generation for the
 * specified channel.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to configure.
 */
static inline void EMIOS_DisableUCInterruptAndDMA(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].C &= ~(EMIOS_C_FEN_MASK | EMIOS_C_DMA_MASK);
}

/*! @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Get Unified Channel (UC) status flags.
 *
 * This function returns the current status flags for the specified channel.
 * The flags indicate events such as captures, compares, overflows, etc.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to read.
 * @return Current status flags (combination of kEMIOS_EventFlag, kEMIOS_OverflowFlag,
 *         and kEMIOS_OverrunFlag).
 */
static inline uint32_t EMIOS_GetUCStatusFlag(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    return base->UC[channel].S;
}

/*!
 * @brief Clear Unified Channel (UC) status flags.
 *
 * This function clears the specified status flags for the given channel.
 * Flags must be cleared to detect new events.
 *
 * @param base    eMIOS peripheral base address.
 * @param mask    Bitmask of flags to clear (combination of kEMIOS_EventFlag,
 *                kEMIOS_OverflowFlag, and kEMIOS_OverrunFlag).
 * @param channel Channel number to configure.
 */
static inline void EMIOS_ClearUCStatusFlag(EMIOS_Type *base, uint32_t mask, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    base->UC[channel].S = mask;
}

/*!
 * @brief Get Unified Channel (UC) output pin status.
 *
 * This function returns the current state of the channel's output pin.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to read.
 * @return Current output pin state (0 = Negated, 1 = Asserted).
 */
static inline uint32_t EMIOS_GetUCOutputPinStatus(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    return (base->UC[channel].S & EMIOS_S_UCOUT_MASK) >> EMIOS_S_UCOUT_SHIFT;
}

/*!
 * @brief Get Unified Channel (UC) input pin status.
 *
 * This function returns the current state of the channel's input pin.
 *
 * @param base    eMIOS peripheral base address.
 * @param channel Channel number to read.
 * @return Current input pin state (0 = Negated, 1 = Asserted).
 */
static inline uint32_t EMIOS_GetUCInputPinStatus(EMIOS_Type *base, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    return (base->UC[channel].S & EMIOS_S_UCIN_MASK) >> EMIOS_S_UCIN_SHIFT;
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_EMIOS_H_ */
