/*
 * Copyright 2020-2021, 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_QDC_H_
#define FSL_QDC_H_

#include "fsl_common.h"

/*!
 * @defgroup qdc QDC: Quadrature Decoder Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief QDC driver version. */
#define FSL_QDC_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup driver_log The Driver Change Log
 * @ingroup qdc
 * @{
 * The current QDC driver version is 2.1.0.
 *
 * - 2.1.0
 *   - New Features
 *     - Supported input filter prescaler.
 *     - Supported the feature that the position counter to be initialized by Index Event Edge Mark.
 *
 * - 2.0.1
 *   - Improvements
 *     - Supported MC56F84xxx.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introducation of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup qdc_intro QDC Peripheral and Driver Overview
 * @ingroup qdc
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method.
 * @{
 *
 * Peripheral features and how this peripheral works
 * ==================================================
 *  The Quadrature Decoder module interfaces to position/speed sensors
 *  that are used in industrial motor control applications. It uses 5 input signals
 *  (PHASEA, PHASEB, INDEX, TRIGGER, and HOME) from those position/speed sensors, the
 *  quadrature decoder module decodes shaft position, revolution count, and speed.
 *
 *  Features
 *  ---------
 *  + Support 32-bit position counter
 *    - Capable of modulo counting
 *    - Could be initialized to a predetermined value by one of 3 different methods:
 *      1. Software-triggered event
 *      2. INDEX signal transition
 *      3. HOME signal transition
 *    - When the position counter registers are read, the snapshot of position counter,
 *      revolution count, and position difference counter could be saved to
 *      their respective hold registers.
 *
 *  + Support quadrature decode mode and signal phase count mode.
 *    - With quadrature decode mode, the PHASEA and PHASEB represent a two-phase quadrature signal.
 *    - With signal phase count mode, a positive transition of the PHASEA input generates a count
 *      signal. The PHASEB input controls the counter direction.
 *
 *  + Support revolution counter with or without INDEX signal
 *    - When INDEX signal used, INDEX signal pulse increases/decreases the revolution counter.
 *    - When INDEX signal not used, the configurable modulus counting roll-over/roll-under
 *      is used to increase/decrease revolution counter.
 *
 *  + Support flexible speed measurement.
 *    QDC uses the Position Difference Counter (POSD), Last Edge Time Counter (LASTEDGE),
 *    Position Difference Period Counter (POSDPER), and Position Difference Period Buffer (POSDPERBFR)
 *    to support both high rotation speed measurement and low rotation speed measurement.
 *
 *  + Support position match output pulse
 *    The  position match output pulse could be used to trigger other modules.
 *    It can be configured to occur when:
 *    1. The position counter matches the application defined compare value.
 *    2. Or, the position counter registers (POS, REV or POSD) are read.
 *    Optionally, the position match event triggers interrupt.
 *
 *  + Configurable digital filter for input signals: PHASEA, PHASEB, INDEX, HOME.
 *
 *  + Support watchdog timer
 *    QDC uses a watchdog timer for non rotating shaft detection.
 *    - The watchdog timeout value is configurable.
 *    - The watchdog could be disabled.
 *    - Watchdog timeout could trigger interrupt.
 *
 *  + Supports Interrupts.
 *    - Input signal interrupts: HOME transition interrupt, INDEX pulse interrupt,
 *      PHASEA and PHASEB simultaneous change interrupt.
 *    - Watchdog timeout interrupt
 *    - Position compare event interrupt.
 *    - Position counter interrupts: Roll over interrupt, roll under interrupt.
 *
 *  How this peripheral works
 *  -------------------------
 *  1. Initialize the module clock, configure the input pins (PHASEA, PHASEB, INDEX, HOME)
 *     based on use case, configure the TRIGGER and POSMATCH signal if necessary.
 *  2. After configured, QDC's Revolution Counter, Position Counter,
 *     Position Difference Counter, Last Edge Time Counter, and
 *     Position Difference Period Counter start to work based on configurations.
 *     Input signal PHASEA, PHASEB, INDEX, HOME are filtered by digital glitch filter
 *     before feeding QDC counters. The QDC counters values are saved to each
 *     hold registers at the proper time, taking a snapshot of the counters' values
 *     allows a consistent view of a system's position and the velocity to be attained.
 *
 * How this driver is designed to make this peripheral works
 * ===========================================================
 *  QDC driver's initialize function @ref QDC_Init initializes the QDC based on
 *  configuration structure @ref qdc_config_t. This function convers all the QDC
 *  configurations. Generally QDC is ready to work after calling this function.
 *  The function @ref QDC_GetDefaultConfig helps to fill the @ref qdc_config_t
 *  with default values.
 *
 *  Besides @ref QDC_Init for the whole module configuration, there are smaller
 *  flexible functions used for runtime setting, including:
 *   - Watchdog: @ref QDC_EnableWatchdog, @ref QDC_SetWatchdogTimeout.
 *   - Interrupt and status: @ref QDC_GetStatusFlags, @ref QDC_ClearStatusFlags,
 *     @ref QDC_GetSignalStatusFlags, @ref QDC_EnableInterrupts, and
 *     @ref QDC_DisableInterrupts.
 *   - Counter value: @ref QDC_SetInitialPositionValue, @ref QDC_SetPositionCounterValue,
 *     @ref QDC_SetPositionModulusValue, @ref QDC_SetPositionCompareValue,
 *     and QDC_SetPositionCompare1Value.
 *
 *  When QDC is working, QDC driver provides functions to get the counter registers value,
 *  revolution count value, position difference value, last edge time,
 *  position difference period.
 *
 *  How to use this driver
 *  =======================
 *  1. Prepare the module clock, configure the input pins according to real use case,
 *     configure output pin if it is used.
 *  2. Prepare the configuration @ref qdc_config_t, initialize the QDC using @ref QDC_Init.
 *  3. When QDC started running, call the value get APIs to get the required register
 *     value to calculate position and speed.
 *
 *  @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief W1C bits in QDC CTRL registers. */
#if defined(QDC_CTRL_CMPIRQ_MASK)
#define QDC_CTRL_W1C_FLAGS (QDC_CTRL_HIRQ_MASK | QDC_CTRL_XIRQ_MASK | QDC_CTRL_DIRQ_MASK | QDC_CTRL_CMPIRQ_MASK)
#else
#define QDC_CTRL_W1C_FLAGS (QDC_CTRL_HIRQ_MASK | QDC_CTRL_XIRQ_MASK | QDC_CTRL_DIRQ_MASK)
#endif

/*! @brief W1C bits in QDC CTRL2 registers. */
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD)
#define QDC_CTRL2_W1C_FLAGS (QDC_CTRL2_SABIRQ_MASK | QDC_CTRL2_ROIRQ_MASK | QDC_CTRL2_RUIRQ_MASK)
#else
#define QDC_CTRL2_W1C_FLAGS (QDC_CTRL2_ROIRQ_MASK | QDC_CTRL2_RUIRQ_MASK)
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD */

/*! @brief W1C bits in QDC CTRL3 registers. */
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
#define QDC_CTRL3_W1C_FLAGS (QDC_CTRL3_CMP1IRQ_MASK)
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */

/*! @brief Interrupt enable bits in QDC CTRL registers. */
#if defined(QDC_CTRL_CMPIE_MASK)
#define QDC_CTRL_INT_EN (QDC_CTRL_HIE_MASK | QDC_CTRL_XIE_MASK | QDC_CTRL_DIE_MASK | QDC_CTRL_CMPIE_MASK)
#else
#define QDC_CTRL_INT_EN (QDC_CTRL_HIE_MASK | QDC_CTRL_XIE_MASK | QDC_CTRL_DIE_MASK)
#endif

/*! @brief Interrupt enable bits in QDC CTRL2 registers. */
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD)
#define QDC_CTRL2_INT_EN (QDC_CTRL2_SABIE_MASK | QDC_CTRL2_ROIE_MASK | QDC_CTRL2_RUIE_MASK)
#else
#define QDC_CTRL2_INT_EN (QDC_CTRL2_ROIE_MASK | QDC_CTRL2_RUIE_MASK)
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD */

/*! @brief Interrupt enable bits in QDC CTRL3 registers. */
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
#if (defined(FSL_FEATURE_QDC_CTRL3_HAS_CMP1IE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL3_HAS_CMP1IE_BIT_FIELD)
#define QDC_CTRL3_INT_EN (QDC_CTRL3_CMP1IE_MASK)
#else
#define QDC_CTRL3_INT_EN (0U)
#endif
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */

/*! @brief Interrupt flag bits in QDC CTRL registers. */
#if defined(QDC_CTRL_CMPIRQ_MASK)
#define QDC_CTRL_INT_FLAGS (QDC_CTRL_HIRQ_MASK | QDC_CTRL_XIRQ_MASK | QDC_CTRL_DIRQ_MASK | QDC_CTRL_CMPIRQ_MASK)
#else
#define QDC_CTRL_INT_FLAGS (QDC_CTRL_HIRQ_MASK | QDC_CTRL_XIRQ_MASK | QDC_CTRL_DIRQ_MASK)
#endif

/*! @brief Interrupt flag bits in QDC CTRL2 registers. */
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD)
#define QDC_CTRL2_INT_FLAGS (QDC_CTRL2_SABIRQ_MASK | QDC_CTRL2_ROIRQ_MASK | QDC_CTRL2_RUIRQ_MASK)
#else
#define QDC_CTRL2_INT_FLAGS (QDC_CTRL2_ROIRQ_MASK | QDC_CTRL2_RUIRQ_MASK)
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD */

/*! @brief Interrupt flag bits in QDC CTRL3 registers. */
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
#define QDC_CTRL3_INT_FLAGS (QDC_CTRL3_CMP1IRQ_MASK)
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */

/*!
 * @brief QDC status flags, these flags indicate the counter's events.
 * @anchor _qdc_status_flags
 */
enum _qdc_status_flags
{
    kQDC_HomeTransitionFlag  = QDC_CTRL_HIRQ_MASK,   /*!< HOME signal transition occured. */
    kQDC_IndexPulseFlag      = QDC_CTRL_XIRQ_MASK,   /*!< INDEX pulse occured. */
    kQDC_WatchdogTimeoutFlag = QDC_CTRL_DIRQ_MASK,   /*!< Watchdog timeout occured. */
    kQDC_PositionCompareFlag = QDC_CTRL_CMPIRQ_MASK, /*!< Position counter match the COMP value. */
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD)
    kQDC_SimultPhaseChangeFlag = QDC_CTRL2_SABIRQ_MASK, /*!< Simultaneous change of PHASEA and PHASEB occured. */
#endif                                                  /* FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD */
    kQDC_PositionRollOverFlag = QDC_CTRL2_ROIRQ_MASK,   /*!< Position counter rolls over from 0xFFFFFFFF to 0, or
                                                             from MOD value to INIT value. */
    kQDC_PositionRollUnderFlag = QDC_CTRL2_RUIRQ_MASK,  /*!< Position register roll under from 0 to 0xFFFFFFFF, or
                                                             from INIT value to MOD value. */
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
    kQDC_PositionCompare1Flag = QDC_CTRL3_CMP1IRQ_MASK, /*!< Position counter match the COMP1 value. */
#endif                                                  /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
    kQDC_StatusAllFlags = kQDC_HomeTransitionFlag | kQDC_IndexPulseFlag | kQDC_WatchdogTimeoutFlag |
                          kQDC_PositionCompareFlag
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD)
                          | kQDC_SimultPhaseChangeFlag
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD */
                          | kQDC_PositionRollOverFlag | kQDC_PositionRollUnderFlag
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
                          | kQDC_PositionCompare1Flag
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
};

/*!
 * @brief Signal status, these flags indicate the raw and filtered input signal status.
 * @anchor _qdc_signal_status
 */
enum _qdc_signal_status
{
    kQDC_SignalStatusRawHome        = QDC_IMR_HOME_MASK,  /*!< Raw HOME input. */
    kQDC_SignalStatusRawIndex       = QDC_IMR_INDEX_MASK, /*!< Raw INDEX input. */
    kQDC_SignalStatusRawPhaseB      = QDC_IMR_PHB_MASK,   /*!< Raw PHASEB input. */
    kQDC_SignalStatusRawPhaseA      = QDC_IMR_PHA_MASK,   /*!< Raw PHASEA input. */
    kQDC_SignalStatusFilteredHome   = QDC_IMR_FHOM_MASK,  /*!< The filtered HOME input. */
    kQDC_SignalStatusFilteredIndex  = QDC_IMR_FIND_MASK,  /*!< The filtered INDEX input. */
    kQDC_SignalStatusFilteredPhaseB = QDC_IMR_FPHB_MASK,  /*!< The filtered PHASEB input. */
    kQDC_SignalStatusFilteredPhaseA = QDC_IMR_FPHA_MASK,  /*!< The filtered PHASEA input. */

    kQDC_SignalStatusAllFlags = kQDC_SignalStatusRawHome | kQDC_SignalStatusRawIndex | kQDC_SignalStatusRawPhaseB |
                                kQDC_SignalStatusRawPhaseA | kQDC_SignalStatusFilteredHome |
                                kQDC_SignalStatusFilteredIndex | kQDC_SignalStatusFilteredPhaseB |
                                kQDC_SignalStatusFilteredPhaseA,
};

/*!
 * @brief Interrupt enable/disable mask.
 * @anchor _qdc_interrupt_enable
 */
enum _qdc_interrupt_enable
{
    kQDC_HomeTransitionInterruptEnable  = QDC_CTRL_HIE_MASK,   /*!< HOME signal transition interrupt enable. */
    kQDC_IndexPulseInterruptEnable      = QDC_CTRL_XIE_MASK,   /*!< INDEX pulse interrupt enable. */
    kQDC_WatchdogTimeoutInterruptEnable = QDC_CTRL_DIE_MASK,   /*!< Watchdog timeout interrupt enable. */
#if (defined(FSL_FEATURE_QDC_CTRL_HAS_CMPIE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL_HAS_CMPIE_BIT_FIELD)
    kQDC_PositionCompareInerruptEnable  = QDC_CTRL_CMPIE_MASK, /*!< Position compare interrupt enable. */
#endif
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD)
    kQDC_SimultPhaseChangeInterruptEnable =
        QDC_CTRL2_SABIE_MASK, /*!< Simultaneous PHASEA and PHASEB change interrupt enable. */
#endif                        /* FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD */
    kQDC_PositionRollOverInterruptEnable  = QDC_CTRL2_ROIE_MASK, /*!< Roll-over interrupt enable. */
    kQDC_PositionRollUnderInterruptEnable = QDC_CTRL2_RUIE_MASK, /*!< Roll-under interrupt enable. */
#if (defined(FSL_FEATURE_QDC_CTRL3_HAS_CMP1IE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL3_HAS_CMP1IE_BIT_FIELD)
    kQDC_PositionCompare1InerruptEnable = QDC_CTRL3_CMP1IE_MASK, /*!< Position compare 1 interrupt enable. */
#endif                                                           /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
    kQDC_AllInterruptEnable = kQDC_HomeTransitionInterruptEnable | kQDC_IndexPulseInterruptEnable |
                              kQDC_WatchdogTimeoutInterruptEnable 
#if (defined(FSL_FEATURE_QDC_CTRL_HAS_CMPIE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL_HAS_CMPIE_BIT_FIELD)
                              | kQDC_PositionCompareInerruptEnable
#endif
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD)
                              | kQDC_SimultPhaseChangeInterruptEnable
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD */
                              | kQDC_PositionRollOverInterruptEnable | kQDC_PositionRollUnderInterruptEnable
#if (defined(FSL_FEATURE_QDC_CTRL3_HAS_CMP1IE_BIT_FIELD) && FSL_FEATURE_QDC_CTRL3_HAS_CMP1IE_BIT_FIELD)
                              | kQDC_PositionCompare1InerruptEnable
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
};

/*!
 * @brief Define HOME signal's trigger mode.
 */
typedef enum _qdc_home_init_pos_counter_mode
{
    /*! Don't use HOME signal to initialize the position counter. */
    kQDC_HomeInitPosCounterDisabled = 0U,

    /*! Use positive going edge to trigger initialization of position counters. */
    kQDC_HomeInitPosCounterOnRisingEdge = QDC_CTRL_HIP_MASK,

    /*! Use negative going edge to trigger initialization of position counters. */
    kQDC_HomeInitPosCounterOnFallingEdge = QDC_CTRL_HIP_MASK | QDC_CTRL_HNE_MASK,
} qdc_home_init_pos_counter_mode_t;

/*!
 * @brief Define INDEX signal's trigger mode.
 */
typedef enum _qdc_index_init_pos_counter_mode
{
    /*! INDEX pulse does not initialize the position counter. */
    kQDC_IndexInitPosCounterDisabled = 0U,

    /*! Use INDEX pulse rising edge to initialize position counter. */
    kQDC_IndexInitPosCounterOnRisingEdge = QDC_CTRL_XIP_MASK,

    /*! Use INDEX pulse falling edge to initialize position counter. */
    kQDC_IndexInitPosCounterOnFallingEdge = QDC_CTRL_XIP_MASK | QDC_CTRL_XNE_MASK,
} qdc_index_init_pos_counter_mode_t;

/*!
 * @brief Define type for decoder work mode.
 *
 * In normal work mode uses the standard quadrature decoder with PHASEA and PHASEB.
 * In signal phase count mode, a positive transition of the PHASEA input generates
 * a count signal while the PHASEB input and the reverse direction control the
 * counter direction. If the reverse direction is not enabled, PHASEB = 0 means
 * counting up and PHASEB = 1 means counting down. If the reverse direction is enabled,
 * PHASEB = 0 means counting down and PHASEB = 1 means counting up.
 */
typedef enum _qdc_decoder_work_mode
{
    kQDC_DecoderQuadratureMode = 0U,  /*!< Use standard quadrature decoder with PHASEA and PHASEB. */
    kQDC_DecoderSignalPhaseCountMode, /*!< PHASEA input generates a count signal while PHASEB input control the
                                           direction. */
} qdc_decoder_work_mode_t;

/*!
 * @brief Define type for the condition of POSMATCH pulses.
 */
typedef enum _qdc_output_pulse_mode
{
    kQDC_OutputPulseOnCounterEqualCompare = 0U, /*!< POSMATCH pulses when a match occurs between the
                                                       position counters (POS) and the compare value (COMP, COMP1). */
    kQDC_OutputPulseOnReadingPositionCounter,   /*!< POSMATCH pulses when reading position counter(POS), revolution
                                                     counter(REV),   position difference counter(POSD). */
} qdc_output_pulse_mode_t;

/*!
 * @brief Define type for determining how the revolution counter (REV) is incremented/decremented.
 */
typedef enum _qdc_revolution_count_condition
{
    kQDC_RevolutionCountOnIndexPulse = 0U, /*!< Use INDEX pulse to increment/decrement revolution counter. */
    kQDC_RevolutionCountOnRollOverModulus, /*!< Use modulus counting roll-over/under to increment/decrement revolution
                                              counter. */
} qdc_revolution_count_condition_t;

/*!
 * @brief Input Filter Sample Count
 *
 * The Input Filter Sample Count represents the number of consecutive samples
 * that must agree, before the input filter accepts an input transition
 */
typedef enum _qdc_filter_sample_count
{
    kQDC_Filter3Samples  = 0U, /*!< 3  samples. */
    kQDC_Filter4Samples  = 1U, /*!< 4  samples. */
    kQDC_Filter5Samples  = 2U, /*!< 5  samples. */
    kQDC_Filter6Samples  = 3U, /*!< 6  samples. */
    kQDC_Filter7Samples  = 4U, /*!< 7  samples. */
    kQDC_Filter8Samples  = 5U, /*!< 8  samples. */
    kQDC_Filter9Samples  = 6U, /*!< 9  samples. */
    kQDC_Filter10Samples = 7U, /*!< 10 samples. */
} qdc_filter_sample_count_t;

#if (defined(FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD) && FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD)
/*!
 * @brief Prescaler Divide IPBus Clock to filter Clock
 */
typedef enum _qdc_filter_prescaler
{
    kQDC_FilterPrescaler1   = 0U, /*!< Prescaler value 1. */
    kQDC_FilterPrescaler2   = 1U, /*!< Prescaler value 2. */
    kQDC_FilterPrescaler4   = 2U, /*!< Prescaler value 4. */
    kQDC_FilterPrescaler8   = 3U, /*!< Prescaler value 8. */
    kQDC_FilterPrescaler16  = 4U, /*!< Prescaler value 16. */
    kQDC_FilterPrescaler32  = 5U, /*!< Prescaler value 32. */
    kQDC_FilterPrescaler64  = 6U, /*!< Prescaler value 64. */
    kQDC_FilterPrescaler128 = 7U, /*!< Prescaler value 128. */
} qdc_filter_prescaler_t;
#endif /* FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD */

/*!
 * @brief Count direction.
 */
typedef enum _qdc_count_direction_flag
{
    kQDC_CountDirectionDown = 0U, /*!< Last count was in down direction. */
    kQDC_CountDirectionUp,        /*!< Last count was in up direction. */
} qdc_count_direction_flag_t;

/*!
 * @brief Prescaler used by Last Edge Time (LASTEDGE) and
 * Position Difference Period Counter (POSDPER).
 */
typedef enum _qdc_prescaler
{
    kQDC_Prescaler1     = 0U,  /*!< Prescaler value 1. */
    kQDC_Prescaler2     = 1U,  /*!< Prescaler value 2. */
    kQDC_Prescaler4     = 2U,  /*!< Prescaler value 4. */
    kQDC_Prescaler8     = 3U,  /*!< Prescaler value 8. */
    kQDC_Prescaler16    = 4U,  /*!< Prescaler value 16. */
    kQDC_Prescaler32    = 5U,  /*!< Prescaler value 32. */
    kQDC_Prescaler64    = 6U,  /*!< Prescaler value 64. */
    kQDC_Prescaler128   = 7U,  /*!< Prescaler value 128. */
    kQDC_Prescaler256   = 8U,  /*!< Prescaler value 256. */
    kQDC_Prescaler512   = 9U,  /*!< Prescaler value 512. */
    kQDC_Prescaler1024  = 10U, /*!< Prescaler value 1024. */
    kQDC_Prescaler2048  = 11U, /*!< Prescaler value 2048. */
    kQDC_Prescaler4096  = 12U, /*!< Prescaler value 4096. */
    kQDC_Prescaler8192  = 13U, /*!< Prescaler value 8192. */
    kQDC_Prescaler16384 = 14U, /*!< Prescaler value 16384. */
    kQDC_Prescaler32768 = 15U, /*!< Prescaler value 32768. */
} qdc_prescaler_t;

/*!
 * @brief Define user configuration structure for QDC module.
 */
typedef struct _qdc_config
{
    /* Basic counter. */
    bool bEnableReverseDirection;             /*!< Enable reverse direction counting. */
    qdc_decoder_work_mode_t eDecoderWorkMode; /*!< Use standard quadrature decoder mode or signal phase count mode. */

    /* Signal detection. */
    qdc_home_init_pos_counter_mode_t eHomeInitPosCounterMode;   /*!< Select how HOME signal used to
                                                                  initialize position counters. */
    qdc_index_init_pos_counter_mode_t eIndexInitPosCounterMode; /*!< Select how INDEX signal used to
                                                                  initialize position counters. */
    bool bEnableTriggerInitPositionCounter; /*!< Initialize position counter with initial register(UINIT, LINIT) value
                                               on TRIGGER's rising edge. */
    bool bEnableTriggerClearPositionRegisters; /*!< Clear position counter(POS), revolution counter(REV), position
                                                difference counter (POSD) on TRIGGER's rising edge. */
    bool bEnableTriggerHoldPositionRegisters;  /*!< Load position counter(POS), revolution counter(REV), position
                                                difference counter (POSD) values to hold registers  on TRIGGER's rising
                                                edge. */

#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD)
    /*!
     * Enables the feature that the position counter to be initialized by Index Event Edge Mark.
     *
     * This option works together with @ref eIndexInitPosCounterMode and @ref bEnableReverseDirection.
     * If enabled, the behavior is like this:
     *
     * When PHA leads PHB (Clockwise):
     *   If @ref eIndexInitPosCounterMode is @ref kQDC_IndexInitPosCounterOnRisingEdge,
     *   then INDEX rising edge reset position counter.
     *   If @ref eIndexInitPosCounterMode is @ref kQDC_IndexInitPosCounterOnFallingEdge,
     *   then INDEX falling edge reset position counter.
     *   If @ref bEnableReverseDirection is false, then Reset position counter to initial value.
     *   If @ref bEnableReverseDirection is true, then reset position counter to modulus value.
     *
     * When PHA lags PHB (Counter Clockwise):
     *   If @ref eIndexInitPosCounterMode is @ref kQDC_IndexInitPosCounterOnRisingEdge,
     *   then INDEX falling edge reset position counter.
     *   If @ref eIndexInitPosCounterMode is @ref kQDC_IndexInitPosCounterOnFallingEdge,
     *   then INDEX rising edge reset position counter.
     *   If @ref bEnableReverseDirection is false, then Reset position counter to modulus value.
     *   If @ref bEnableReverseDirection is true, then reset position counter to initial value.
     */
    bool bEnableIndexInitPositionCounter;
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD */

    /* Watchdog. */
    bool bEnableWatchdog;             /*!< Enable the watchdog to detect if the target is moving or not. */
    uint16_t u16WatchdogTimeoutValue; /*!< Watchdog timeout count value. It stores the timeout count for the quadrature
                                        decoder module watchdog timer. */

    /* Filter for input signals: PHASEA, PHASEB, INDEX and HOME. */
#if (defined(FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD) && FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD)
    qdc_filter_prescaler_t eFilterPrescaler; /*!< Input signal filter prescaler. */
#endif                                            /* FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD */
    qdc_filter_sample_count_t eFilterSampleCount; /*!< Input Filter Sample Count. This value should be chosen to reduce
                               the probability of noisy samples causing an incorrect transition to be recognized. The
                               value represent the number of consecutive samples that must agree prior to the input
                               filter accepting an input transition. */
    uint8_t u8FilterSamplePeriod; /*!< Input Filter Sample Period. This value should be set such that the sampling
                                     period is larger than the period of the expected noise. This value represents the
                                      sampling period (in IPBus clock cycles) of the decoder input signals.
                                      The available range is 0 - 255. */

    /* Position compare. */
    qdc_output_pulse_mode_t eOutputPulseMode; /*!< The condition of POSMATCH pulses. */
    uint32_t u32PositionCompareValue;         /*!< Position compare value. The available value is a 32-bit number.*/
    uint32_t u32PositionCompare1Value;        /*!< Position compare 1 value. The available value is a 32-bit number.*/

    /* Modulus counting. */
    qdc_revolution_count_condition_t eRevolutionCountCondition; /*!< Revolution Counter Modulus Enable. */
    bool bEnableModuloCountMode;                                /*!< Enable Modulo Counting. */
    uint32_t u32PositionModulusValue; /*!< Position modulus value. Only used when @ref bEnableModuloCountMode is true.
                                           The available value is a 32-bit number. */
    uint32_t u32PositionInitialValue; /*!< Position initial value. The available value is a 32-bit number. */
    uint32_t u32PositionCounterValue; /*!< Position counter value. When Modulo mode enabled, the u32PositionCounterValue
                                           should be in the range of @ref u32PositionInitialValue and
                                           @ref u32PositionModulusValue. */

    /* Period measurement. */
    bool bEnablePeriodMeasurement; /*!< Enable period measurement. When enabled, the position difference hold register
                                      (POSDH) is only updated when position difference register (POSD) is read. */
    qdc_prescaler_t ePrescaler;    /*!< Prescaler. */

    /* Interrupts. */
    uint16_t u16EnabledInterruptsMask; /*!< Mask of interrupts to be enabled, should be OR'ed value of @ref
                                          _qdc_interrupt_enable. */
} qdc_config_t;

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
 * @brief Initializes the QDC module.
 *
 * This function initializes the QDC by:
 * 1. Enable the IP bus clock (optional).
 * 2. Configure module based on the configuration structure.
 *
 * @param base   QDC peripheral base address.
 * @param psConfig Pointer to configuration structure.
 */
void QDC_Init(QDC_Type *base, const qdc_config_t *psConfig);

/*!
 * @brief Gets an available pre-defined configuration.
 *
 * The default value are:
 * @code
    psConfig->bEnableReverseDirection              = false;
    psConfig->eDecoderWorkMode                     = kQDC_DecoderQuadratureMode;
    psConfig->eHomeInitPosCounterMode              = kQDC_HomeInitPosCounterDisabled;
    psConfig->eIndexInitPosCounterMode             = kQDC_IndexInitPosCounterDisabled;
    psConfig->bEnableTriggerInitPositionCounter    = false;
    psConfig->bEnableTriggerClearPositionRegisters = false;
    psConfig->bEnableTriggerHoldPositionRegisters  = false;
    psConfig->bEnableWatchdog                      = false;
    psConfig->u16WatchdogTimeoutValue              = 0xFFFFU;
    psConfig->eFilterSampleCount                   = kQDC_Filter3Samples;
    psConfig->u8FilterSamplePeriod                 = 0U;
    psConfig->eOutputPulseMode                     = kQDC_OutputPulseOnCounterEqualCompare;
    psConfig->u32PositionCompareValue              = 0xFFFFFFFFU;
    psConfig->u32PositionCompare1Value             = 0xFFFFFFFFU;
    psConfig->eRevolutionCountCondition            = kQDC_RevolutionCountOnIndexPulse;
    psConfig->bEnableModuloCountMode               = false;
    psConfig->u32PositionModulusValue              = 0U;
    psConfig->u32PositionInitialValue              = 0U;
    psConfig->u32PositionCounterValue              = 0U;
    psConfig->bEnablePeriodMeasurement             = false;
    psConfig->ePrescaler                           = kQDC_Prescaler1;
    psConfig->u16EnabledInterruptsMask             = 0U;
   @endcode
 *
 * @param psConfig Pointer to configuration structure.
 */
void QDC_GetDefaultConfig(qdc_config_t *psConfig);

/*!
 * @brief De-initializes the QDC module.
 *
 * This function deinitializes the QDC by:
 * 1. Disables the IP bus clock (optional).
 *
 * @param base QDC peripheral base address.
 */
void QDC_Deinit(QDC_Type *base);

/*! @} */

/*!
 * @name Watchdog
 * @{
 */

/*!
 * @brief Enable watchdog for QDC module.
 *
 * @param base QDC peripheral base address
 * @param bEnable Enables or disables the watchdog
 */
static inline void QDC_EnableWatchdog(QDC_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL = (base->CTRL & (~QDC_CTRL_W1C_FLAGS)) | QDC_CTRL_WDE_MASK;
    }
    else
    {
        base->CTRL = (base->CTRL & (~(QDC_CTRL_W1C_FLAGS | QDC_CTRL_WDE_MASK)));
    }
}

/*!
 * @brief Set watchdog timeout value.
 *
 * @param base QDC peripheral base address
 * @param u16Timeout Number of clock cycles, plus one clock cycle that the
 * watchdog timer counts before timing out
 */
static inline void QDC_SetWatchdogTimeout(QDC_Type *base, uint16_t u16Timeout)
{
    base->WTR = u16Timeout;
}

/*! @} */

/*!
 * @name Status
 * @{
 */
/*!
 * @brief  Get the status flags.
 *
 * @param  base QDC peripheral base address.
 *
 * @return  Logical OR'ed value of the status flags, @ref _qdc_status_flags.
 */
static inline uint16_t QDC_GetStatusFlags(QDC_Type *base)
{
    uint16_t u16Flags = 0U;

    u16Flags = (base->CTRL & QDC_CTRL_INT_FLAGS);

    u16Flags |= (base->CTRL2 & QDC_CTRL2_INT_FLAGS);
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
    u16Flags |= (base->CTRL3 & QDC_CTRL3_INT_FLAGS);
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
    return u16Flags;
}

/*!
 * @brief Clear the status flags.
 *
 * @param base QDC peripheral base address.
 * @param u16Flags Logical OR'ed value of the flags to clear, @ref _qdc_status_flags.
 */
static inline void QDC_ClearStatusFlags(QDC_Type *base, uint16_t u16Flags)
{
    if (0U != (u16Flags & QDC_CTRL_INT_FLAGS))
    {
        base->CTRL = (base->CTRL & (~QDC_CTRL_W1C_FLAGS)) | (u16Flags & QDC_CTRL_INT_FLAGS);
    }

    if (0U != (u16Flags & QDC_CTRL2_INT_FLAGS))
    {
        base->CTRL2 = (base->CTRL2 & (~QDC_CTRL2_W1C_FLAGS)) | (u16Flags & QDC_CTRL2_INT_FLAGS);
    }
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
    if (0U != (u16Flags & QDC_CTRL3_INT_FLAGS))
    {
        base->CTRL3 = (base->CTRL3 & ((uint16_t)(~QDC_CTRL3_W1C_FLAGS))) | (u16Flags & QDC_CTRL3_INT_FLAGS);
    }
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
}

/*!
 * @brief  Get the signals' real-time status.
 *
 * @param  base QDC peripheral base address.
 * @return Logical OR'ed value of the real-time signal status, @ref _qdc_signal_status.
 */
static inline uint16_t QDC_GetSignalStatusFlags(QDC_Type *base)
{
    return base->IMR;
}

/*!
 * @brief Get the direction of the last count.
 *
 * @param  base QDC peripheral base address.
 * @return Direction of the last count.
 */
static inline qdc_count_direction_flag_t QDC_GetLastCountDirection(QDC_Type *base)
{
    return ((0U != (base->CTRL2 & QDC_CTRL2_DIR_MASK)) ? kQDC_CountDirectionUp : kQDC_CountDirectionDown);
}
/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enable the interrupts.
 *
 * @param base QDC peripheral base address.
 * @param u16Interrupts Logical OR'ed value of the interrupts, @ref _qdc_interrupt_enable.
 */
static inline void QDC_EnableInterrupts(QDC_Type *base, uint16_t u16Interrupts)
{
    if (0U != (u16Interrupts & QDC_CTRL_INT_EN))
    {
        base->CTRL = (base->CTRL & (~QDC_CTRL_W1C_FLAGS)) | (u16Interrupts & QDC_CTRL_INT_EN);
    }

    if (0U != (u16Interrupts & QDC_CTRL2_INT_EN))
    {
        base->CTRL2 = (base->CTRL2 & (~QDC_CTRL2_W1C_FLAGS)) | (u16Interrupts & QDC_CTRL2_INT_EN);
    }
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
#if (QDC_CTRL3_INT_EN != 0U)
    if (0U != (u16Interrupts & QDC_CTRL3_INT_EN))
    {
        base->CTRL3 = (base->CTRL3 & (~QDC_CTRL3_W1C_FLAGS)) | (u16Interrupts & QDC_CTRL3_INT_EN);
    }
#endif
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
}

/*!
 * @brief Disable the interrupts.
 *
 * @param base QDC peripheral base address.
 * @param u16Interrupts Logical OR'ed value of the interrupts, @ref _qdc_interrupt_enable.
 */
static inline void QDC_DisableInterrupts(QDC_Type *base, uint16_t u16Interrupts)
{
    if (0U != (u16Interrupts & QDC_CTRL_INT_EN))
    {
        base->CTRL = (base->CTRL & (~QDC_CTRL_W1C_FLAGS)) & (~(u16Interrupts & QDC_CTRL_INT_EN));
    }

    if (0U != (u16Interrupts & QDC_CTRL2_INT_EN))
    {
        base->CTRL2 = (base->CTRL2 & (~QDC_CTRL2_W1C_FLAGS)) & (~(u16Interrupts & QDC_CTRL2_INT_EN));
    }
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
#if (QDC_CTRL3_INT_EN != 0U)
    if (0U != (u16Interrupts & QDC_CTRL3_INT_EN))
    {
        base->CTRL3 = (base->CTRL3 & (~QDC_CTRL3_W1C_FLAGS)) & (~(u16Interrupts & QDC_CTRL3_INT_EN));
    }
#endif
#endif /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */
}

/*! @} */

/*!
 * @name Counter Operation
 * @{
 */

/*!
 * @brief Load the initial position value to position counter.
 *
 * Software trigger to load the initial position value (UINIT and LINIT) contents
 * to position counter (UPOS and LPOS), so that to provide the consistent
 * operation the position counter registers.
 *
 * @param base QDC peripheral base address.
 */
static inline void QDC_DoSoftwareLoadInitialPositionValue(QDC_Type *base)
{
    base->CTRL = (base->CTRL & (~QDC_CTRL_W1C_FLAGS)) | QDC_CTRL_SWIP_MASK;
}

/*!
 * @brief Set initial position value for QDC module.
 *
 * Set the position counter initial value (INIT or UINIT, LINIT).
 *
 * @param base QDC peripheral base address
 * @param u32PositionInitValue Position initial value
 */
static inline void QDC_SetInitialPositionValue(QDC_Type *base, uint32_t u32PositionInitValue)
{
    base->UINIT = (uint16_t)(u32PositionInitValue >> 16U);
    base->LINIT = (uint16_t)(u32PositionInitValue);
}

/*!
 * @brief Set position counter value.
 *
 * Set the position counter value (POS or UPOS, LPOS).
 *
 * @param base QDC peripheral base address
 * @param u32PositionCounterValue Position counter value
 */
static inline void QDC_SetPositionCounterValue(QDC_Type *base, uint32_t u32PositionCounterValue)
{
    base->UPOS = (uint16_t)(u32PositionCounterValue >> 16U);
    base->LPOS = (uint16_t)(u32PositionCounterValue);
}

/*!
 * @brief Set position counter modulus value.
 *
 * Set the position counter modulus value (MOD or UMOD, LMOD).
 *
 * @param base QDC peripheral base address
 * @param u32PositionModulusValue Position modulus value
 */
static inline void QDC_SetPositionModulusValue(QDC_Type *base, uint32_t u32PositionModulusValue)
{
    base->UMOD = (uint16_t)(u32PositionModulusValue >> 16U);
    base->LMOD = (uint16_t)(u32PositionModulusValue);
}

/*!
 * @brief Set position counter compare value.
 *
 * Set the position counter compare value (COMP or UCOMP, LCOMP).
 *
 * @param base QDC peripheral base address
 * @param u32PositionCompValue Position modulus value
 */
static inline void QDC_SetPositionCompareValue(QDC_Type *base, uint32_t u32PositionCompValue)
{
    base->UCOMP = (uint16_t)(u32PositionCompValue >> 16U);
    base->LCOMP = (uint16_t)(u32PositionCompValue);
}
#if (defined(FSL_FEATURE_QDC_HAS_UCOMP1_REGISTER) && FSL_FEATURE_QDC_HAS_UCOMP1_REGISTER)
/*!
 * @brief Set position counter compare 1 value.
 *
 * Set the position counter compare 1 value (COMP1 or UCOMP1, LCOMP1).
 *
 * @param base QDC peripheral base address
 * @param u32PositionComp1Value Position modulus value
 */
static inline void QDC_SetPositionCompare1Value(QDC_Type *base, uint32_t u32PositionComp1Value)
{
    base->UCOMP1 = (uint16_t)(u32PositionComp1Value >> 16U);
    base->LCOMP1 = (uint16_t)(u32PositionComp1Value);
}
#endif /* FSL_FEATURE_QDC_HAS_UCOMP1_REGISTER */
/*!
 * @brief  Get the current position counter's value.
 *
 * @param  base QDC peripheral base address.
 *
 * @return     Current position counter's value.
 */
static inline uint32_t QDC_GetPosition(QDC_Type *base)
{
    uint32_t u32Pos;

    u32Pos = base->UPOS; /* Get upper 16 bits and make a snapshot. */
    u32Pos <<= 16U;
    u32Pos |= base->LPOSH; /* Get lower 16 bits from hold register. */

    return u32Pos;
}

/*!
 * @brief  Get the hold position counter's value.
 *
 * The position counter (POS or UPOS, LPOS) value is loaded to hold position (POSH or UPOSH, LPOSH)
 * when:
 * 1. Position register (POS or UPOS, LPOS), or position difference register (POSD),
 * or revolution register (REV) is read.
 * 2. TRIGGER happens and TRIGGER is enabled to update the hold registers.
 *
 * @param  base QDC peripheral base address.
 * @return  Hold position counter's value.
 */
static inline uint32_t QDC_GetHoldPosition(QDC_Type *base)
{
    uint32_t u32Pos;

    u32Pos = base->UPOSH;
    u32Pos <<= 16U;
    u32Pos |= base->LPOSH;

    return u32Pos;
}

/*!
 * @brief  Get the position difference counter's value.
 *
 * @param  base QDC peripheral base address.
 * @return The position difference counter's value.
 */
static inline uint16_t QDC_GetPositionDifference(QDC_Type *base)
{
    return base->POSD;
}

/*!
 * @brief  Get the hold position difference counter's value.
 *
 * The position difference (POSD) value is loaded to hold position difference (POSDH)
 * when:
 * 1. Position register (POS or UPOS, LPOS), or position difference register (POSD),
 * or revolution register (REV) is read. When Period Measurement is enabled (CTRL3[PMEN] = 1),
 * POSDH will only be udpated when reading POSD.
 * 2. TRIGGER happens and TRIGGER is enabled to update the hold registers.
 *
 * @param  base QDC peripheral base address.
 * @return  Hold position difference counter's value.
 */
static inline uint16_t QDC_GetHoldPositionDifference(QDC_Type *base)
{
    return base->POSDH;
}

/*!
 * @brief  Get the revolution counter's value.
 *
 * Get the revolution counter (REV) value.
 *
 * @param  base QDC peripheral base address.
 * @return  The revolution counter's value.
 */
static inline uint16_t QDC_GetRevolution(QDC_Type *base)
{
    return base->REV;
}

/*!
 * @brief  Get the hold revolution counter's value.
 *
 * The revolution counter (REV) value is loaded to hold revolution (REVH)
 * when:
 * 1. Position register (POS or UPOS, LPOS), or position difference register (POSD),
 * or revolution register (REV) is read.
 * 2. TRIGGER happens and TRIGGER is enabled to update the hold registers.
 *
 * @param  base QDC peripheral base address.
 * @return Hold position revolution counter's value.
 */
static inline uint16_t QDC_GetHoldRevolution(QDC_Type *base)
{
    return base->REVH;
}

#if (defined(FSL_FEATURE_QDC_HAS_LASTEDGE_REGISTER) && FSL_FEATURE_QDC_HAS_LASTEDGE_REGISTER)
/*!
 * @brief  Get the last edge time.
 *
 * Last edge time (LASTEDGE) is the time since the last edge occurred on PHASEA or PHASEB.
 * The last edge time register counts up using the peripheral clock after prescaler.
 * Any edge on PHASEA or PHASEB will reset this register to 0 and start counting.
 * If the last edge timer count reaches 0xffff, the counting will stop in order to
 * prevent an overflow.
 *
 * @param  base QDC peripheral base address.
 *
 * @return The last edge time.
 */
static inline uint16_t QDC_GetLastEdgeTime(QDC_Type *base)
{
    return base->LASTEDGE;
}
#endif /* FSL_FEATURE_QDC_HAS_LASTEDGE_REGISTER */

#if (defined(FSL_FEATURE_QDC_HAS_LASTEDGEH_REGISTER) && FSL_FEATURE_QDC_HAS_LASTEDGEH_REGISTER)
/*!
 * @brief  Get the hold last edge time.
 *
 * The hold of last edge time(LASTEDGEH) is update to last edge time(LASTEDGE)
 * when the position difference register register (POSD) is read.
 *
 * @param  base QDC peripheral base address.
 * @return Hold of last edge time.
 */
static inline uint16_t QDC_GetHoldLastEdgeTime(QDC_Type *base)
{
    return base->LASTEDGEH;
}
#endif /* FSL_FEATURE_QDC_HAS_LASTEDGEH_REGISTER */

#if (defined(FSL_FEATURE_QDC_HAS_POSDPER_REGISTER) && FSL_FEATURE_QDC_HAS_POSDPER_REGISTER)
/*!
 * @brief Get the Position Difference Period counter value
 *
 * The Position Difference Period counter (POSDPER) counts up using the
 * prescaled peripheral clock.  When reading the position difference register(POSD),
 * the last edge time (LASTEDGE) will be loaded to position difference period counter(POSDPER).
 * If the POSDPER count reaches 0xffff, the counting will stop in order to prevent an
 * overflow. Counting will continue when an edge occurs on PHASEA or PHASEB.
 *
 * @param  base QDC peripheral base address.
 * @return The position difference period counter value.
 */
static inline uint16_t QDC_GetPositionDifferencePeriod(QDC_Type *base)
{
    return base->POSDPER;
}
#endif /* FSL_FEATURE_QDC_HAS_POSDPER_REGISTER */

#if (defined(FSL_FEATURE_QDC_HAS_POSDPERBFR_REGISTER) && FSL_FEATURE_QDC_HAS_POSDPERBFR_REGISTER)
/*!
 * @brief Get buffered Position Difference Period counter value
 *
 * The Bufferd Position Difference Period (POSDPERBFR) value is updated with
 * the position difference period counter(POSDPER) when any edge occurs
 * on PHASEA or PHASEB.
 *
 * @param  base QDC peripheral base address.
 * @return The buffered position difference period counter value.
 */
static inline uint16_t QDC_GetBufferedPositionDifferencePeriod(QDC_Type *base)
{
    return base->POSDPERBFR;
}
#endif /* FSL_FEATURE_QDC_HAS_POSDPERBFR_REGISTER */

#if (defined(FSL_FEATURE_QDC_HAS_POSDPERH_REGISTER) && FSL_FEATURE_QDC_HAS_POSDPERH_REGISTER)
/*!
 * @brief Get Hold Position Difference Period counter value
 *
 * The hold position difference period(POSDPERH) is updated with the value of
 * buffered position difference period(POSDPERBFR) when the
 * position difference(POSD) register is read.
 *
 * @param  base QDC peripheral base address.
 * @return The hold position difference period counter value.
 */
static inline uint16_t QDC_GetHoldPositionDifferencePeriod(QDC_Type *base)
{
    return base->POSDPERH;
}
#endif /* FSL_FEATURE_QDC_HAS_POSDPERH_REGISTER */

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* FSL_QDC_H_ */
