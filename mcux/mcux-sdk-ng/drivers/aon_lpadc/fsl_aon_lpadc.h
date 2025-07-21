/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_AON_LPADC_H_
#define FSL_AON_LPADC_H_

#include "fsl_common.h"

/*!
 * @addtogroup aon_lpadc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief AON_LPADC driver version 2.0.1. */
#define FSL_AON_LPADC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! 
 * @brief Trigger priority exception handle policy helper macro
 *
 * tprictrl: ADC Trigger Priority Control.
 *   @b 00b - If a higher priority trigger is detected during command processing,
 *            the current conversion is aborted and the new command specified by
 *            the trigger is started.
 *   @b 01b - If a higher priority trigger is received during command processing,
 *            the current command is stopped after completing the current conversion.
 *            If averaging is enabled, the averaging loop will be completed. However,
 *            CMDHa[LOOP] will be ignored and the higher priority trigger will be
 *            serviced.
 *   @b 10b - If a higher priority trigger is received during command processing,
 *            the current command will be completed (averaging, looping, compare) 
 *            before servicing the higher priority trigger.
 *
 * tres: Trigger Resume Enable.
 *   @b 0b - Trigger sequences interrupted by a high priority trigger exception
 *           are not automatically resumed or restarted.
 *   @b 1b - Trigger sequences interrupted by a high priority trigger exception
 *           are automatically resumed or restarted.
 *
 * tcmdres: Trigger Command Resume, tres must be asserted for tcmdres to be used.
 *   @b 0b - Trigger sequences interrupted by a high priority trigger exception
 *           is automatically restarted.
 *   @b 1b - Trigger sequences interrupted by a high priority trigger exception
 *           is resumed from the command executing before the exception.
 *
 * hpted: High Priority Trigger Exception Disable
 *   @b 0b - High priority trigger exceptions are enabled.
 *   @b 1b - High priority trigger exceptions are disabled.
 */
#define ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(tprictrl, tres, tcmdres, hpted)  \
    (((tprictrl) & 0x3U) |                                                      \
     (((tres) << 2U) & 0x4U) |                                                  \
     (((tcmdres) << 3U) & 0x8U) |                                               \
     (((hpted) << 4U) & 0x10U))

#define ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_DE(policy)  \
    tprictrl    = ((policy) & 0x3U);                    \
    tres        = (((policy) & 0x4U) >> 2U);            \
    tcmdres     = (((policy) & 0x8U) >> 3U);            \
    hpted       = (((policy) & 0x10U) >> 4U);

/*! @brief ADC status flags enumeration. */
enum _adc_status_flags
{
    /*! Indicates when the number of valid datawords in the result FIFO 0 
     *  is greater than the setting watermark level.
     */
    kADC_ResFifo0RdyFlag = LPADC_STAT_RDY0_MASK,

    /*! Indicates that more data has been written to the result FIFO 0 
     *  than it can hold.
     */
    kADC_ResFifo0OverflowFlag = LPADC_STAT_FOF0_MASK,

    /*! Indicates when the number of valid datawords in the result FIFO 1
     *  is greater than the setting watermark level.
     */
    kADC_ResFifo1RdyFlag = LPADC_STAT_RDY1_MASK,
    
     /*! Indicates that more data has been written to the result FIFO 1
      *  than it can hold.
      */
    kADC_ResFifo1OverflowFlag = LPADC_STAT_FOF1_MASK,
    
    /*! Indicates that a high priority trigger exception event has occurred. */
    kADC_TrigExcFlag = LPADC_STAT_TEXC_INT_MASK,

    /*! Indicates that a trigger sequence has occurred. */
    kADC_TrigCompFlag = LPADC_STAT_TCOMP_INT_MASK,
    
    /*! Indicates that the calibration process is done. */
    kADC_CalRdyFlag = LPADC_STAT_CAL_RDY_MASK,
    
     /*! Indicates that the ADC is in active state. */
    kADC_ActFlag = LPADC_STAT_ADC_ACTIVE_MASK,
    
    /*! Indicates that the trigger is actively being processed. */
    kADC_TrigAct = LPADC_STAT_TRGACT_MASK,

    /*! Indicates that the command is actively being processed. */
    kADC_CmdAct = LPADC_STAT_CMDACT_MASK,
};

/*! @brief ADC trigger status flags enumeration. */
enum _adc_trig_status_flags
{
    /*! Indicates trigger 0 is interrupted by a high priority exception. */
    kADC_Trig0IntFlag = LPADC_TSTAT_TEXC_NUM(1U << 0U),

    /*! Indicates trigger 1 is interrupted by a high priority exception. */
    kADC_Trig1IntFlag = LPADC_TSTAT_TEXC_NUM(1U << 1U),

    /*! Indicates trigger 2 is interrupted by a high priority exception. */
    kADC_Trig2IntFlag = LPADC_TSTAT_TEXC_NUM(1U << 2U),

    /*! Indicates trigger 3 is interrupted by a high priority exception. */
    kADC_Trig3IntFlag = LPADC_TSTAT_TEXC_NUM(1U << 3U),
    
    /*! Indicates trigger 0 is completed and trigger 0 has enabled
     *  completion interrupts.
     */
    kADC_Trig0CompFlag = LPADC_TSTAT_TCOMP_FLAG(1U << 0U),
    
    /*! Indicates trigger 1 is completed and trigger 1 has enabled completion
     *  interrupts.
     */
    kADC_Trig1CompFlag = LPADC_TSTAT_TCOMP_FLAG(1U << 1U),
    
    /*! Indicates trigger 2 is completed and trigger 2 has enabled completion
     *  interrupts.
     */
    kADC_Trig2CompFlag = LPADC_TSTAT_TCOMP_FLAG(1U << 2U),
    
    /*! Indicates trigger 3 is completed and trigger 3 has enabled completion
     *  interrupts.
     */
    kADC_Trig3CompFlag = LPADC_TSTAT_TCOMP_FLAG(1U << 3U),
};

/*! @brief ADC interrupt enablement mask enumeration. */
enum _adc_int_en
{
    /*! Configures ADC to generate overflow interrupt requests when FIFO0 ready
     *  flag is asserted.
     */
    kADC_ResFifo0WatermarkIntEn = LPADC_IE_FWMIE0_MASK,

    /*! Configures ADC to generate overflow interrupt requests when FIFO0 overflow
     *  flag is asserted.
     */
    kADC_ResFifo0OverflowIntEn = LPADC_IE_FOFIE0_MASK,

    /*! Configures ADC to generate overflow interrupt requests when FIFO1 ready
     *  flag is asserted. 
     */
    kADC_ResFifo1WatermarkIntEn = LPADC_IE_FWMIE1_MASK,

    /*! Configures ADC to generate overflow interrupt requests when FIFO1 overflow
     *  flag is asserted.
     */
    kADC_ResFifo1OverflowIntEn = LPADC_IE_FOFIE1_MASK,

    /*! Configures ADC to generate trigger exception interrupt. */
    kADC_TrigExcIntEn = LPADC_IE_TEXC_IE_MASK,

    /*! Configures ADC to generate interrupt when trigger 0 completion. */
    kADC_Trig0CompIntEn = LPADC_IE_TCOMP_IE(1U << 0U),

    /*! Configures ADC to generate interrupt when trigger 1 completion. */
    kADC_Trig1CompIntEn = LPADC_IE_TCOMP_IE(1U << 1U),

    /*! Configures ADC to generate interrupt when trigger 2 completion. */
    kADC_Trig2CompIntEn = LPADC_IE_TCOMP_IE(1U << 2U),

    /*! Configures ADC to generate interrupt when trigger 3 completion. */
    kADC_Trig3CompIntEn = LPADC_IE_TCOMP_IE(1U << 3U),
};

/*! @brief ADC calibration conversion averages enumeration. */
typedef enum _adc_cal_conv_avg
{
    kADC_CalConvAvg0    = 0U,         /*!< Single conversion. */
    kADC_CalConvAvg2    = 1U,         /*!< 2 conversions averaged. */
    kADC_CalConvAvg4    = 2U,         /*!< 4 conversions averaged. */
    kADC_CalConvAvg8    = 3U,         /*!< 8 conversions averaged. */
    kADC_CalConvAvg16   = 4U,         /*!< 16 conversions averaged. */
    kADC_CalConvAvg32   = 5U,         /*!< 32 conversions averaged. */
    kADC_CalConvAvg64   = 6U,         /*!< 64 conversions averaged. */
    kADC_CalConvAvg128  = 7U,         /*!< 128 conversions averaged. */
    kADC_CalConvAvg256  = 8U,         /*!< 256 conversions averaged. */
    kADC_CalConvAvg512  = 9U,         /*!< 512 conversions averaged. */
    kADC_CalConvAvg1024 = 10U,        /*!< 1024 conversions averaged. */
} adc_cal_conv_avg_t;

/*! @brief ADC calibration conversion sample time enumeration. */
typedef enum _adc_cal_conv_sample_time
{
    kADC_CalConvSampTime_AdckCycle0 = 0U,  /*!< 1 ADCK cycles sample time. */
    kADC_CalConvSampTime_AdckCycle1 = 1U,  /*!< 2 ADCK cycles sample time. */
    kADC_CalConvSampTime_AdckCycle2 = 2U,  /*!< 3 ADCK cycles sample time. */
    kADC_CalConvSampTime_AdckCycle3 = 3U,  /*!< 4 ADCK cycles sample time. */
    kADC_CalConvSampTime_AdckCycle4 = 4U,  /*!< 5 ADCK cycles sample time. */
    kADC_CalConvSampTime_AdckCycle5 = 5U,  /*!< 6 ADCK cycles sample time. */
    kADC_CalConvSampTime_AdckCycle6 = 6U,  /*!< 7 ADCK cycles sample time. */
    kADC_CalConvSampTime_AdckCycle7 = 7U,  /*!< 8 ADCK cycles sample time. */
} adc_cal_conv_sample_time_t;

/*! @brief ADC FIFO enumeration. */
typedef enum _adc_fifo_index
{
    kADC_Fifo0 = 0U, /*!< FIFO 0. */
    kADC_Fifo1 = 1U, /*!< FIFO 1. */
} adc_fifo_index_t;

/*! @brief ADC trigger enumeration. */
typedef enum _adc_trig_index
{
    kADC_Trig0 = 0U, /*!< Trigger 0. */
    kADC_Trig1 = 1U, /*!< Trigger 1. */
    kADC_Trig2 = 2U, /*!< Trigger 2. */
    kADC_Trig3 = 3U, /*!< Trigger 3. */
} adc_trig_index_t;

/*! @brief ADC trigger command enumeration. */
typedef enum _adc_trig_cmd_index
{
    kADC_CmdNone = 0U, /*!< Not a valid selection from the command buffer, 
                              trigger event is ignored. */
    kADC_Cmd1 = 1U, /*!< Trigger commad 1. */
    kADC_Cmd2 = 2U, /*!< Trigger commad 2. */
    kADC_Cmd3 = 3U, /*!< Trigger commad 3. */
    kADC_Cmd4 = 4U, /*!< Trigger commad 4. */
    kADC_Cmd5 = 5U, /*!< Trigger commad 5. */
    kADC_Cmd6 = 6U, /*!< Trigger commad 6. */
    kADC_Cmd7 = 7U, /*!< Trigger commad 7. */
} adc_cmd_index_t;

/*! @brief ADC hardware conversion averages enumeration. */
typedef enum _adc_conv_avg
{
    kADC_ConvAvg1    = 0U,  /*!< Single conversion. */
    kADC_ConvAvg2    = 1U,  /*!< 2 conversions averaged. */
    kADC_ConvAvg4    = 2U,  /*!< 4 conversions averaged. */
    kADC_ConvAvg8    = 3U,  /*!< 8 conversions averaged. */
    kADC_ConvAvg16   = 4U,  /*!< 16 conversions averaged. */
    kADC_ConvAvg32   = 5U,  /*!< 32 conversions averaged. */
    kADC_ConvAvg64   = 6U,  /*!< 64 conversions averaged. */
    kADC_ConvAvg128  = 7U,  /*!< 128 conversions averaged. */
    kADC_ConvAvg256  = 8U,  /*!< 256 conversions averaged. */
    kADC_ConvAvg512  = 9U,  /*!< 512 conversions averaged. */
    kADC_ConvAvg1024 = 10U, /*!< 1024 conversions averaged. */
} adc_conv_avg_t;

/*! @brief ADC conversion sample time enumeration. */
typedef enum _adc_sample_time
{
    kADC_ConvSampleTime_AdcCycle1    = 0U,   /*!< 1 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle2    = 1U,   /*!< 2 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle3    = 2U,   /*!< 3 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle4    = 3U,   /*!< 4 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle5    = 4U,   /*!< 5 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle6    = 5U,   /*!< 6 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle7    = 6U,   /*!< 7 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle8    = 7U,   /*!< 8 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle10   = 8U,   /*!< 10 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle12   = 9U,   /*!< 12 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle16   = 10U,  /*!< 16 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle24   = 11U,  /*!< 24 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle40   = 12U,  /*!< 40 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle72   = 13U,  /*!< 72 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle136  = 14U,  /*!< 136 ADCK cycles. */
    kADC_ConvSampleTime_AdcCycle264  = 15U,  /*!< 264 ADCK cycles. */
} adc_conv_sample_time_t;

/*!
 * @brief ADC hardware compare mode enumeration.
 *
 * @note After an ADC channel input is sampled and converted and any averaging
 *       iterations are performed, this mode setting guides operation of the 
 *       automatic compare function to optionally only store when the compare
 *       operation is true. When compare is enabled, the conversion result is
 *       compared to the compare values.
 */
typedef enum _adc_comp_mode
{
    kADC_CompareDisabled        = 0U, /*!< Compare disabled. */
    kADC_CompareStoreOnTrue     = 2U, /*!< Compare enabled. Store on true. */
    kADC_CompareRepeatUntilTrue = 3U, /*!< Compare enabled. Repeat channel
                                             acquisition until true. */
} adc_comp_mode_t;

/*! @brief ADC reference voltage source enumeration. */
typedef enum _adc_ref_voltage_src
{
    kADC_RefVoltageAlt1 = 0U, /*!< Option 1 setting. */
    kADC_RefVoltageAlt2 = 1U, /*!< Option 2 setting. */
} adc_ref_voltage_src_t;

/*! @brief ADC DAC settle time enumeration. */
typedef enum _adc_dac_settle_delay
{
    kADC_FastDacSettleTime = 0U, /*!< Fastest settling */
    kADC_SlowDacSettleTime = 1U, /*!< Slowest settling */
} adc_dac_settle_delay_t;

/*! @brief ADC trigger priority exception handle policy enumeration. */
typedef enum _adc_trig_priority_policy
{
    /*! If a higher priority trigger is detected during command processing,
     *  the current conversion is aborted and the new command specified by
     *  the trigger is started, when higher priority conversion finishes,
     *  the preempted conversion is not automatically resumed or restarted.
     */
    kADC_ConvPreemptImmedNotAutoResumed = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 0U, 0U, 0U),

    /*! If a higher priority trigger is received during command processing,
     *  the current conversion is completed (including averaging iterations
     *  and compare function if enabled) and stored to the result FIFO before
     *  the higher priority trigger/command is initiated, when higher priority
     *  conversion finishes, the preempted conversion is not resumed or restarted.
     */
    kADC_ConvPreemptSoftlyNotAutoResumed = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 0U, 0U, 1U),

    /*! If a higher priority trigger is detected during command processing,
     *  the current conversion is aborted and the new command specified by
     *  the trigger is started, when higher priority conversion finishes,
     *  the preempted conversion will automatically be restarted.
     */
    kADC_ConvPreemptImmedAutoRestarted = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 0U, 1U, 0U),

    /*! If a higher priority trigger is received during command processing,
     *  the current conversion is completed (including averaging iterations
     *  and compare function if enabled) and stored to the result FIFO before
     *  the higher priority trigger/command is initiated, when higher priority
     *  conversion finishes, the preempted conversion will automatically be restarted.
     */
    kADC_ConvPreemptSoftlyAutoRestarted = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 0U, 1U, 1U),

    /*! If a higher priority trigger is detected during command processing,
     *  the current conversion is aborted and the new command specified by
     *  the trigger is started, when higher priority conversion finishes,
     *  the preempted conversion will automatically be resumed.
     */
    kADC_ConvPreemptImmedAutoResumed = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 1U, 1U, 0U),

    /*! If a higher priority trigger is received during command processing,
     *  the current conversion is completed (including averaging iterations
     *  and compare function if enabled) and stored to the result FIFO before
     *  the higher priority trigger/command is initiated,  when higher priority
     *  conversion finishes, the preempted conversion will be automatically be resumed.
     */
    kADC_ConvPreemptSoftlyAutoResumed = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 1U, 1U, 1U),

    /*! If a higher priority trigger is received during command processing,
     *  the current command will be completed (averaging, looping, compare) before
     *  servicing the higher priority trigger, when higher priority conversion finishes,
     *  the preempted conversion will not automatically be restarted or resumed.
     */
    kADC_ConvPreemptSubsequentlyNotAutoResumed = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 0U, 0U, 2U),

    /*! If a higher priority trigger is received during command processing,
     *  the current command will be completed (averaging, looping, compare) before
     *  servicing the higher priority trigger, when higher priority conversion finishes,
     *  the preempted conversion will be automatically restarted.
     */
    kADC_ConvPreemptSubsequentlyAutoRestarted = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 0U, 1U, 2U),

    /*! If a higher priority trigger is received during command processing,
     *  the current command will be completed (averaging, looping, compare) before
     *  servicing the higher priority trigger, when higher priority conversion finishes,
     *  the preempted conversion will be automatically resumed.
     */
    kADC_ConvPreemptSubsequentlyAutoResumed = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(0U, 1U, 1U, 2U),

    /*! High priority trigger exception disabled. */
    kADC_TriggerPriorityExceptionDisabled = ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_EN(1U, 0U, 0U, 0U),
} adc_trig_priority_policy_t;

/*! @brief ADC conversion result structure. */
typedef struct _adc_conv_res
{
    uint8_t trigSrc;    /*!< Indicate the trigger source that initiated a conversion
                             and generated this result. */
    uint8_t cmdSrc;     /*!< Indicate the command buffer being executed that generated
                             this result. */
    uint8_t loopCnt;    /*!< Indicate the loop count value during command execution
                             that generated this result. */
    uint16_t convVal;   /*!< ADC conversion result. */
} adc_conv_res_t;

/*! @brief ADC trigger configuration structure. */
typedef struct _adc_trig_config
{
    bool trigEn;        /*!< Controls hardware trigger source to initiate conversion
                             on the rising edge of the input trigger source. */
    uint8_t trigDelay;  /*!< Sets the trigger delay duration to wait at the start
                             of servicing a trigger event. */
    uint8_t trigPriority;       /*!< Sets the priority of the associated trigger source. */
    adc_fifo_index_t resFifo; /*!< Selects the FIFO to store the conversion result. */
    adc_cmd_index_t cmdIndex; /*!< Selects the trigger command from command buffer to 
                                     execute upon detect of the associated trigger event. */
} adc_trig_config_t;

/*! @brief ADC command configuration structure. */
typedef struct _adc_cmd_config
{
    bool waitTrigEn;    /*!< Controls whether commands are automatically executed
                             or a trigger must be received before execution. */
    bool autoChanIncEn;  /*!< Controls whether enable automatic channel incrementing. */
    uint8_t loopCnt;    /*!< Sets how many times this command executes (and stores 
                             conversion result to RESFIFO) before finish and  transition
                             to the next command or Idle state. */
    uint8_t chanIndex;                  /*!< Sets conversion channel. */
    uint16_t compValLow;                /*!< Sets compare low value. */
    uint16_t compValHigh;               /*!< Sets compare high value. */
    adc_conv_avg_t convAvg;             /*!< Selects hardware average value. */
    adc_comp_mode_t compMode;           /*!< Selects hardware compare mode. */
    adc_cmd_index_t nextCmdIndex;       /*!< Selects the next command to execute
                                             after this command completes. */
    adc_conv_sample_time_t convSampleTime; /*!< Selects sample time value. */
} adc_cmd_config_t;

/*! @brief ADC configuration structure. */
typedef struct _adc_config
{
    bool dozeModeEn; /*!< Controls system transition to low power modes 
                          while ADC is converting. */
    bool convPauseEn; /*!< Controls whether to enable the ADC pause function. */
    bool dynamicEleMatchEn; /*!< Controls whether to enable dynamic element match. */
    uint8_t compTime; /*!< Sets a configurable number of ADCK cycles to
                           complete the compare phase of a conversion. */
    uint8_t convPauseDelay; /*!< Sets the duration of pausing during command
                                 execution sequencing. */
    uint8_t fifo0Watermark; /*!< Sets FIFO 0 watermark value. */
    adc_cal_conv_avg_t calConvAvg; /*!< Selects calibration conversion averages. */
    adc_ref_voltage_src_t refVoltageSrc; /*!< Selects the reference voltage source.*/
    adc_dac_settle_delay_t dacSettleTime; /*!< Selects DAC settle delay. */
    adc_cal_conv_sample_time_t calConvSampTime; /*!< Selects calibration conversion sample time. */
    adc_trig_priority_policy_t trigPriorityPolicy; /*!< Selects trigger priority exception handle policy. */
} adc_config_t;

#if defined(__cplusplus)
extern "C" {
#endif
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @name ADC initialization, de-initialization, and configuration.
 * @{
 */
/*!
 * @brief Gets an available pre-defined settings for ADC configuration.
 *
 * @param config Pointer to ADC configuration structure, @ref adc_config_t.
 */
void ADC_GetDefaultConfig(adc_config_t *config);

/*!
 * @brief Initializes the ADC module.
 *
 * @param base   ADC peripheral base address.
 * @param config Pointer to configuration structure, @ref adc_config_t.
 */
void ADC_Init(LPADC_Type *base, const adc_config_t *config);

/*!
 * @brief De-initializes the ADC module.
 *
 * @param base ADC peripheral base address.
 */
void ADC_Deinit(LPADC_Type *base);

/*!
 * @brief Enable/disable the ADC module.
 *
 * @param base ADC peripheral base address.
 * @param enable Indicates whether to enable the ADC module.
 *   @b - true Enable the ADC module.
 *   @b - false Disable the ADC module.
 */
static inline void ADC_Enable(LPADC_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= LPADC_CTRL_ADCEN_MASK;
    }
    else
    {
        base->CTRL &= ~LPADC_CTRL_ADCEN_MASK;
    }
}

/*!
 * @brief Reset ADC FIFO.
 *
 * @param base ADC peripheral base address.
 * @param index ADC FIFO index, @ref adc_fifo_index_t
 */
static inline void ADC_DoFifoRst(LPADC_Type *base, adc_fifo_index_t index)
{
    if(index == kADC_Fifo0)
    {
        base->CTRL |= LPADC_CTRL_RSTFIFO0_MASK;
    }
    else
    {
        base->CTRL |= LPADC_CTRL_RSTFIFO1_MASK;
    }
}

/*!
 * @brief Software reset ADC module.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_DoSoftWareRst(LPADC_Type *base)
{
    base->CTRL |= LPADC_CTRL_RST_MASK;
    while((base->CTRL & LPADC_CTRL_RST_MASK) != LPADC_CTRL_RST_MASK);

    base->CTRL &= ~LPADC_CTRL_RST_MASK;
}
/*! @} */

/*!
 * @name ADC status
 * @{
 */
/*!
 * @brief Get ADC status flags.
 *
 * @param base ADC peripheral base address.
 * @return Mask value for ADC status flags to be got, should be the OR'ed value
 *         of @ref _adc_status_flags.
 */
static inline uint32_t ADC_GetStatusFlags(LPADC_Type *base)
{
    return base->STAT;
}

/*!
 * @brief Clear ADC status flags.
 *
 * @note Only the flags can be cleared by writing ADCx_STATUS register would 
 *       be cleared by this API.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for ADC status flags to be cleared, should be the OR'ed 
 *        value of @ref _adc_status_flags.
 */
static inline void ADC_ClearStatusFlags(LPADC_Type *base, uint32_t mask)
{
    base->STAT = mask;
}

/*!
 * @brief Get ADC trigger status flags.
 *
 * @param base ADC peripheral base address.
 * @return Mask value for ADC trigger status flags to be got, should be the OR'ed 
 *         value of @ref _adc_trig_status_flags.
 */
static inline uint32_t ADC_GetTriggerStatusFlags(LPADC_Type *base)
{
    return base->TSTAT;
}

/*!
 * @brief Clear ADC trigger status flags.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for ADC trigger status flags to be cleared, should be
 *        the OR'ed value of @ref _adc_trig_status_flags.
 */
static inline void ADC_ClearTriggerStatusFlags(LPADC_Type *base, uint32_t mask)
{
    base->TSTAT = mask;
}
/*! @} */

/*!
 * @name ADC Interrupts
 * @{
 */
/*!
 * @brief Enable interrupts.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for interrupt events to be enabled, should be the OR'ed
 *        value of @ref _adc_int_en.
 */
static inline void ADC_EnableInt(LPADC_Type *base, uint32_t mask)
{
    base->IE |= mask;
}

/*!
 * @brief Disable interrupts.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for interrupt events to be disabled, should be the OR'ed
 *        value of @ref _adc_int_en.
 */
static inline void ADC_DisableInt(LPADC_Type *base, uint32_t mask)
{
    base->IE &= ~mask;
}
/*! @} */

/*!
 * @name AON_DMA control
 * @{
 */
/*!
 * @brief Enable/disable the specified ADC FIFO watermark DAM transfer.
 *
 * @param base ADC peripheral base address.
 * @param index ADC FIFO index, @ref adc_fifo_index_t
 * @param enable Indicates whether to enable the specified ADC FIFO watermark DAM transfer.
 *   @b true Enable the specified ADC FIFO watermark DMA transfer.
 *   @b false Disable the specified ADC FIFO watermark DMA transfer.
 */
static inline void ADC_EnableFifoWatermarkDma(LPADC_Type *base, adc_fifo_index_t index, bool enable)
{
    if (enable)
    {
        if (index == kADC_Fifo0)
        {
            base->DE |= LPADC_DE_FWMDE0_MASK;
        }
        else
        {
            base->DE |= LPADC_DE_FWMDE1_MASK;
        }
    }
    else
    {
        if (index == kADC_Fifo0)
        {
            base->DE &= ~LPADC_DE_FWMDE0_MASK;
        }
        else
        {
            base->DE &= ~LPADC_DE_FWMDE1_MASK;
        }
    }
}
/*! @} */

/*!
 * @name ADC trigger, FIFO, and conversion result.
 * @{
 */
/*!
 * @brief Gets an available pre-defined settings for ADC trigger's configuration.
 *
 * @param config Pointer to ADC trigger configuration structure, @ref adc_trig_config_t.
 */
void ADC_GetDefaultTrigConfig(adc_trig_config_t *config);

/*!
 * @brief Configure the ADC trigger source.
 *
 * @param base ADC peripheral base address.
 * @param index ADC trigger index, @ref adc_trig_index_t.
 * @param config Pointer to ADC trigger configuration structure, @ref adc_trig_config_t.
 */
void ADC_SetTrigConfig(LPADC_Type *base, adc_trig_index_t index, const adc_trig_config_t *config);

/*!
 * @brief Do software trigger.
 *
 * @param base ADC peripheral base address.
 * @param index ADC trigger index, @ref adc_trig_index_t.
 */
static inline void ADC_DoSoftwareTrig(LPADC_Type *base, adc_trig_index_t index)
{
    base->SWTRIG |= 1U << index;
}

/*!
 * @brief Get the count of result kept in specified ADC conversion result FIFO.
 *
 * @param base ADC peripheral base address.
 * @param index ADC FIFO index, @ref adc_fifo_index_t
 *
 * @return The count of result kept in specified ADC conversion result FIFO.
 */
static inline uint32_t ADC_GetResFifoCnt(LPADC_Type *base, adc_fifo_index_t index)
{
    if (index == kADC_Fifo0)
    {
        return ((base->FCTRL0 & LPADC_FCTRL0_FCOUNT_MASK) >> LPADC_FCTRL0_FCOUNT_SHIFT);
    }
    else
    {
        return ((base->FCTRL1 & LPADC_FCTRL1_FCOUNT_MASK) >> LPADC_FCTRL1_FCOUNT_SHIFT);
    }
}

/*!
 * @brief Get the result in specified conversion FIFO.
 *
 * @param base ADC peripheral base address.
 * @param result Pointer to ADC result structure, @ref adc_conv_res_t.
 * @param index ADC FIFO index, @ref adc_fifo_index_t
 *
 * @return Status whether FIFO entry is valid.
 *   @b - true Conversion FIFO result is valid.
 *   @b - false Conversion FIFO result is invalid.
 */
bool ADC_GetConvRes(LPADC_Type *base, adc_conv_res_t *result, adc_fifo_index_t index);
/*! @} */

/*!
 * @name ADC command.
 * @{
 */
/*!
 * @brief Gets an available pre-defined settings for ADC command's configuration.
 *
 * @param config Pointer to ADC command configuration structure, @ref adc_cmd_config_t.
 */
void ADC_GetDefaultCmdConfig(adc_cmd_config_t *config);

/*!
 * @brief Do ADC command configuration.
 *
 * @param base ADC peripheral base address.
 * @param index ADC command index, @ref adc_cmd_index_t.
 * @param config Pointer to ADC commad configuration structure, @ref adc_cmd_config_t.
 */
void ADC_SetCmdConfig(LPADC_Type *base, adc_cmd_index_t index, const adc_cmd_config_t *config);

/*!
 * @name ADC calibration.
 * @{
 */
/*!
 * @brief Set trim value for offset.
 *
 * @param base ADC peripheral base address.
 * @param value 8-bit unsigned value that should be limited to values between 0h to A0h, with
 * a nominal value of 50h.
 */
static inline void ADC_SetOffsetTrimVal(LPADC_Type *base, uint8_t value)
{
    base->OFSTRIM = ((base->OFSTRIM & ~LPADC_OFSTRIM_OFSTRIM_MASK) | LPADC_OFSTRIM_OFSTRIM(value));
}

/*!
 * @brief Get trim value of offset.
 *
 * @param base ADC peripheral base address.
 * @param pValue Pointer to the variable in type of uint8_t to store offset value.
 */
static inline void ADC_GetOffsetTrimVal(LPADC_Type *base, uint8_t *pValue)
{
    assert(pValue != NULL);

    *pValue = (uint8_t)((base->OFSTRIM & (LPADC_OFSTRIM_OFSTRIM_MASK)) >> LPADC_OFSTRIM_OFSTRIM_SHIFT);
}

/*!
 * @brief Do offset calibration.
 *
 * @param base ADC peripheral base address.
 */
void ADC_DoOffsetCal(LPADC_Type *base);
/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_AON_LPADC_H_ */
