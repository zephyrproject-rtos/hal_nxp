/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PDB_H_
#define FSL_PDB_H_

#include "fsl_common.h"

/*!
 * @defgroup pdb PDB: Programmable Delay Block
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief PDB driver version. */
#define FSL_PDB_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup pdb_driver_log The Driver Change Log
 * @ingroup pdb
 * @{
 * The current Pdb driver version is 2.0.0.
 *
 *   - 2.0.0
 *     - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup pdb_intro PDB Peripheral and Driver Overview
 * @ingroup pdb
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features and how this peripheral works
 * ==================================================.
 * The main function of the Programmable Delay module Block(PDB) mode is only to provide a controllable delay from the
 * PWM SYNC output to the sampling trigger input of the programmable gain amplifier and ADC, as well as a controllable
 * window synchronized with the PWM pulse, which is used in the definition of the analog comparator. Compare the analog
 * signal in the window. Another main function of the PDB is to generate a sampling/filtering clock for the comparator,
 * and another function of the PDB is to generate a PWM pulse synchronized with the PWM timer module.
 *
 *  Features
 *  ---------
 *  + 16-bit resolution with prescaler.
 *
 *  + Positive transition of trigger_in will initiate the counter.
 *
 *  + Supports two trigger_out signals. Each has an independently controlled delay from sync_in.
 *    - Each trigger output is independently enabled.
 *    - Trigger outputs can be ORed together to schedule two conversions from one input trigger event.
 *    - Trigger outputs can be used to schedule precise edge placement for a pulsed output.
 *
 *  + Continuous trigger or single shot mode supported.
 *
 *  + Have faultA and faultC, when a fault input is detected, the appropriate Trigger A or Trigger C output is forced to
 *	  the value defined by CTRLA[AINIT] of CTRLC[CINIT].
 *
 *  + Bypass mode supported.
 *    - The input trigger bypasses the PDB logic entirely. It is possible to bypass any of the trigger outputs or all.
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 * The PDB driver provides a structure @ref pdb_config_t, which contains all the programmable functions of the PDB.
 * The PDB_Init() function configures the PDB function through its parameters. In addition to the initialization
 * ioperation, the PDB driver also provides several function groups for function reconfiguration, such as interrupt
 * enable/disable, bypass mode selection, delay function setting, counting function setting, and status flag acquisition
 * and clearing. The functional groups are briefly described as follows:
 *
 *  + Initialization and deinitialization Interfaces
 *      The APIs in the functional group is used to initialize/deinitialize PDB module.
 *  + PDB operation Interfaces
 *  	The APIs in this functional group allows user Start/Stop and configure the PDB mode.
 *  + Interrupt control interface
 *		The API in this function group can be used to enable/disable PDBinterrupts
 *  + PDB status flag interface
 *		The API in this function group can be used to get/clear the PDB status
 *
 * How to use this driver
 * =======================
 *  + Initialize the PDB function by calling PDB_Init():
 *    - Use the pointer of the variable type to call the PDB_GetDefaultConfig() function @ref pdb_config_t to get the
 *      default options.
 *    - Set the variable member of the @ref pdb_config_t type.
 *    - Call PDB_Init to set the PDB function.
 *
 *  + PDB trigger output logic:
 *    - Set PDB trigger output structure @ref pdb_trigger_output_logic_config_t, each PDB instance has two trigger
 *output logic and each output logic has two output signals.
 *
 *  + The PDB module has five interrupt sources.
 *    - If the PDB_EnableOverflowInterrupts interrupt is enabled, the counter rolls over interrupt is enable.
 *    - PDB delay interrupt has four sources: delayA, delayB, delayC and delayD.
 *      You can select only their delay characteristics, or select their combined functions.
 *
 *  + Set the delay value of the enable trigger:
 *    - There are four PDB delay registers, corresponding to the four trigger output signals, providing them with a
 *      delay trigger.
 *
 *  + Enable the counter, set the maximum count
 *    - Set the maximum value of the count through the function PDB_SetModulusValue.
 *
 * Typical Use Case
 * ================
 * + PDB delay interrupt nitialize,take the enable delayA interrupt as an example:
 *  @code
 *    PDB_GetDefaultConfig(&pdbConfigStruct);
 *    pdbConfigStruct.sPdbTriggerABOutputConfig.bEnableTrigger1 = true;
 *    pdbConfigStruct.u16EnableInterruptMask                    = kPDB_EnableDelayAInterrupt;
 *    pdbConfigStruct.bEnablePDB                                = true;
 *    PDB_Init(DEMO_PDB_BASE, &pdbConfigStruct);
 *  @endcode
 *@}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Clock prescaler select.
 *
 * The prescaler used for counting is selected by dividing the peripheral clock by the divisor.
 */
typedef enum _pdb_prescaler_divider
{
    kPDB_PrescalerDivider1 = 0U, /*!< Divider /1. */
    kPDB_PrescalerDivider2,      /*!< Divider /2. */
    kPDB_PrescalerDivider4,      /*!< Divider /4. */
    kPDB_PrescalerDivider8,      /*!< Divider /8. */
    kPDB_PrescalerDivider16,     /*!< Divider /16. */
    kPDB_PrescalerDivider32,     /*!< Divider /32. */
    kPDB_PrescalerDivider64,     /*!< Divider /64. */
    kPDB_PrescalerDivider128     /*!< Divider /128.*/
} pdb_prescaler_divider_t;

/*!
 * @brief PDB load mode select.
 *
 * Choose to load the DELAY and MOD registers into a set of buffers to take effect immediately or
 * take effect after the counter is reversed and a trigger signal is received.
 */
typedef enum _pdb_load_value_mode
{
    kPDB_LoadValueImmediately = 0U, /*!< Load immediately after 1 is written to LDOK. */
    kPDB_LoadValueAfterEvent        /*!< Load when the PDB counter  rolls over or a
                     trigger signal is received after 1 is written to LDOK. */
} pdb_load_value_mode_t;

/*!
 * @brief Trigger Input Source Select
 *
 * Selects the trigger input source for the PDB. The trigger input source can be internal or the software trigger.
 * When select kPDB_TriggerSoftware  and the module is enabled, writing a one to MCTRL[SWTRIG] will trigger and software
 * trigger. See chip configuration details for the actual PDB input trigger connections.
 */
typedef enum _pdb_input_trigger
{
    kPDB_TriggerInput0 = 0U, /*!< PDB input trigger 0. */
    kPDB_TriggerInput1,      /*!< PDB input trigger 1. */
    kPDB_TriggerInput2,      /*!< PDB input trigger 2. */
    kPDB_TriggerInput3,      /*!< PDB input trigger 3. */
    kPDB_TriggerInput4,      /*!< PDB input trigger 4. */
    kPDB_TriggerInput5,      /*!< PDB input trigger 5. */
    kPDB_TriggerInput6,      /*!< PDB input trigger 6. */
    kPDB_TriggerSoftware     /*!< Software Trigger. */
} pdb_input_trigger_t;

/*!
 * @brief PDB fault length.
 *
 * This bit is used to determine the minimum width requirement of the input fault for it to be recognized as a
 * valid fault condition.
 */
typedef enum _pdb_fault_length
{
    kPDB_2IPBusClockCycles = 0U, /*!< Fault input must be active at least 2 IPBus clock cycles.*/
    kPDB_4IPBusClockCycles       /*!< Fault input must be active at least 4 IPBus clock cycles. */
} pdb_fault_length_t;

/*!
 * @brief PDB fault polarity
 */
typedef enum _pdb_fault_polarity
{
    kPDB_FaultPolarity0 = 0U, /*!< A logic 0 on Fault pin indicates a fault condition.*/
    kPDB_FaultPolarity1       /*!< A logic 1 on Fault pin indicates a fault condition. */
} pdb_fault_polarity_t;

/*!
 * @brief PDB trigger output signals
 */
typedef enum _pdb_trigger_output
{
    kPDB_TriggerA = 0U, /*!< Trigger A. */
    kPDB_TriggerB,      /*!< Trigger B. */
    kPDB_TriggerC,      /*!< Trigger C. */
    kPDB_TriggerD       /*!< Trigger D. */
} pdb_trigger_output_t;

/*!
 * @brief PDB trigger logic enumeration
 *
 * Each PDB instance has two trigger output logic and each output logic has two output signals.
 */
typedef enum _pdb_logic
{
    kPDB_LogicA = 0U, /*!< PDB trigger output logic A, has two output signals: triggerA and triggerB. */
    kPDB_LogicC       /*!< PDB trigger output logic C, has two output signals: triggerC and triggerD. */
} pdb_logic_t;

/*!
 * @brief PDB init value enumeration
 */
typedef enum _pdb_init_value
{
    kPDB_InitValue0 = 0U, /*!< PDB init value 0. */
    kPDB_InitValue1       /*!< PDB init value 1. */
} pdb_init_value_t;

/*!
 * @brief The enumeration for PDB interrupt enable.
 */
enum _pdb_interrupt_enable
{
    kPDB_EnableOverflowInterrupt = PDB_MCTRL_COIE_MASK, /*!< PDB overflow interrupt. */
    kPDB_EnableDelayAInterrupt   = PDB_CTRLA_DAIE_MASK, /*!< PDB delayA interrupt. */
    kPDB_EnableDelayBInterrupt   = PDB_CTRLA_DBIE_MASK, /*!< PDB delayB interrupt. */
    kPDB_EnableDelayCInterrupt   = PDB_CTRLC_DCF_MASK,  /*!< PDB delayC interrupt. */
    kPDB_EnableDelayDInterrupt   = PDB_CTRLC_DDF_MASK,  /*!< PDB delayD interrupt. */
    kPDB_ALLInterruptEnable = (kPDB_EnableOverflowInterrupt | kPDB_EnableDelayAInterrupt | kPDB_EnableDelayBInterrupt |
                               kPDB_EnableDelayCInterrupt | kPDB_EnableDelayDInterrupt)
};

/*!
 * @brief The enumeration for PDB status flags.
 */
enum _pdb_status_flags
{
    kPDB_OverflowStatusFlag = PDB_MCTRL_COF_MASK,  /*!< PDB overflow interrupt. */
    kPDB_DelayAStatusFlag   = PDB_CTRLA_DAF_MASK,  /*!< PDB delayA interrupt. */
    kPDB_DelayBStatusFlag   = PDB_CTRLA_DBF_MASK,  /*!< PDB delayB interrupt. */
    kPDB_DelayCStatusFlag   = PDB_CTRLC_DCIE_MASK, /*!< PDB delayC interrupt. */
    kPDB_DelayDStatusFlag   = PDB_CTRLC_DDIE_MASK, /*!< PDB delayD interrupt. */
    kPDB_ALLStatusFlags     = (kPDB_OverflowStatusFlag | kPDB_DelayAStatusFlag | kPDB_DelayBStatusFlag |
                           kPDB_DelayCStatusFlag | kPDB_DelayDStatusFlag)
};

/*!
 * @brief configuring PDB trigger output logic.
 *
 * PDB has two output logic and each output logic has two output trigger signals: trigger1 and trigger2.
 */
typedef struct _pdb_trigger_output_logic_config
{
    bool bFaultEnable : 1U; /*!< Set PDB fault input bit, true: PDB fault is enable; false: PDB fault is disable. */
    pdb_fault_polarity_t eFaultPolarity : 1U; /*!< Selected the PDB fault polarity 0 or 1. */
    pdb_fault_length_t
        eFaultLength : 1U; /*!< Selected the PDB fault length, 0: 2 IP bus clock cycles; 1: 4 IP bus clock cycles. */
    pdb_init_value_t eTriggerInitValue : 1U; /*!< Set fault bit forces the output from trigger logic : fault bit is
              enabled or trigger logic output is set and the counter is reloaded. */
    bool bEnbleTriggerCombineOutput : 1U;    /*!< Trigger output select. true: Trigger1 and trigger2 Combine Output;
                 false: Trigger1 and trigger2 function is only delay. */
    bool bEnableTrigger1 : 1U; /*!< Set trigger1 in each trigger output logic of PDB. true: PDB trigger1 is enable;
                  false: PDB trigger1 is disable. */
    bool bEnableTrigger2 : 1U; /*!< Set trigger2 in each trigger output logic of PDB. true: PDB trigger2 is enable;
                  false: PDB trigger2 is disable. */
    bool bBypassTrigger1 : 1U; /*!< Set bypass trigger1 in each trigger output logic of PDB. true: PDB bypass trigger is
                    enable; false: PDB bypass trigger is disable.*/
    bool bBypassTrigger2 : 1U; /*!< Set bypass trigger2 in each trigger output logic of PDB. true: PDB bypass trigger is
                    enable; false: PDB bypass trigger is disable.*/
    uint16_t uDelay1;          /*!< Set the delay of trigger1 in each trigger output logic of the PDB.*/
    uint16_t uDelay2;          /*!< Set the delay of trigger2 in each trigger output logic of the PDB.*/
} pdb_trigger_output_logic_config_t;

/*!
 * @brief PDB module config structure.
 */
typedef struct _pdb_config
{
    bool bEnableContinuousMode : 1U; /*!< true: Module is in one-shot mode; false: Module is in continuous mode.*/
    pdb_load_value_mode_t eLoadValueMode : 1U; /*!< Configures PDB load value mode.0: load immediately; 1: load after
                                                  the PDB counter rolls over or receives a trigger signal. */
    pdb_prescaler_divider_t ePrescalerDivider : 3U;              /*!< Configures PDB counter clock source prescaler. */
    pdb_input_trigger_t eInputTrigger : 3U;                      /*!< Configures PDB trigger input source. */
    pdb_trigger_output_logic_config_t sPdbTriggerABOutputConfig; /*!< Configure PDB trigger output logic A .*/
    pdb_trigger_output_logic_config_t sPdbTriggerCDOutputConfig; /*!< Configure PDB trigger output logic C.*/
    uint16_t u16PeriodCount;         /*!< The period of the counter in terms of peripheral bus cycles. */
    bool bEnablePDB;                 /*!< true: PDB module id enable; false: PDB module id disable. */
    uint16_t u16EnableInterruptMask; /*!< PDB interrupt enable mask, logic OR of @ref _pdb_interrupt_enable. */
} pdb_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization Interfaces
 * @{
 */

/*!
 * @brief Initializes the PDB module.
 *
 * This function initializes the PDB module. The operations included are as follows.
 *  - Enable the clock for PDB instance.
 *  - Configure the PDB module.
 *  - Enable the PDB module.
 *
 * @param base PDB peripheral base address.
 * @param psConfig Pointer to the configuration structure. See @ref pdb_config_t.
 */
void PDB_Init(PDB_Type *base, const pdb_config_t *psConfig);

/*!
 * @brief De-initializes the PDB module.
 *
 * @param base PDB peripheral base address.
 */
void PDB_Deinit(PDB_Type *base);

/*!
 * @brief Initializes the PDB user configuration structure.
 *
 * This function initializes the user configuration structure to a default value. The default values are as follows.
 * @code
 *   psConfig->bEnableContinuousMode                                = false;
 *   psConfig->eInputTrigger                                        = kPDB_TriggerInput0;
 *   psConfig->eLoadValueMode                                       = kPDB_LoadValueImmediately;
 *   psConfig->ePrescalerDivider                                    = kPDB_PrescalerDivider1;
 *   psConfig->sPdbTriggerABOutputConfig.bBypassTrigger1            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bBypassTrigger2            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bEnableTrigger1            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bEnableTrigger2            = false;
 *   psConfig->sPdbTriggerABOutputConfig.bEnbleTriggerCombineOutput = false;
 *   psConfig->sPdbTriggerABOutputConfig.eTriggerInitValue          = kPDB_InitValue0;
 *   psConfig->sPdbTriggerABOutputConfig.eFaultLength               = kPDB_2IPBusClockCycles;
 *   psConfig->sPdbTriggerABOutputConfig.eFaultPolarity             = kPDB_FaultPolarity0;
 *   psConfig->sPdbTriggerABOutputConfig.bFaultEnable               = false;
 *   psConfig->sPdbTriggerABOutputConfig.uDelay1                    = 0xFFFFU;
 *   psConfig->sPdbTriggerABOutputConfig.uDelay2                    = 0xFFFFU;
 *   psConfig->sPdbTriggerCDOutputConfig.bBypassTrigger1            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bBypassTrigger2            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bEnableTrigger1            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bEnableTrigger2            = false;
 *   psConfig->sPdbTriggerCDOutputConfig.bEnbleTriggerCombineOutput = false;
 *   psConfig->sPdbTriggerCDOutputConfig.eTriggerInitValue          = kPDB_InitValue0;
 *   psConfig->sPdbTriggerCDOutputConfig.eFaultLength               = kPDB_2IPBusClockCycles;
 *   psConfig->sPdbTriggerCDOutputConfig.eFaultPolarity             = kPDB_FaultPolarity0;
 *   psConfig->sPdbTriggerCDOutputConfig.bFaultEnable               = false;
 *   psConfig->sPdbTriggerCDOutputConfig.uDelay1                    = 0xFFFFU;
 *   psConfig->sPdbTriggerCDOutputConfig.uDelay2                    = 0xFFFFU;
 *   psConfig->u16PeriodCount                                       = 0xFFFFU;
 *   psConfig->u16EnableInterruptMask                               = 0x0u;
 *   psConfig->bEnablePDB                                           = false;
 * @endcode
 * @param psConfig Pointer to configuration structure. See @ref pdb_config_t.
 */
void PDB_GetDefaultConfig(pdb_config_t *psConfig);

/*!
 * @brief Set the PDB trigger output logic.
 *
 * @param base PDB peripheral base address.
 * @param eLogic index for PDB trigger output logic instance. See @ref pdb_logic_t.
 * @param psConfig Pointer to the configuration structure. See @ref pdb_trigger_output_logic_config_t.
 */
void PDB_SetTriggerOutputLogicConfig(PDB_Type *base,
                                     pdb_logic_t eLogic,
                                     const pdb_trigger_output_logic_config_t *psConfig);

/*! @} */

/*!
 * @name Basic Counter
 * @{
 */
/*!
 * @brief Enable the PDB module.
 *
 * @param base PDB peripheral base address.
 * @param bEnablePDBMode Enable the module or not.
 */
static inline void PDB_EnableModule(PDB_Type *base, bool bEnablePDBMode)
{
    if (bEnablePDBMode)
    {
        base->MCTRL |= PDB_MCTRL_PDBEN_MASK;
    }
    else
    {
        base->MCTRL &= ~PDB_MCTRL_PDBEN_MASK;
    }
}

/*!
 * @brief Enables the PDB continuous mode.
 *
 * @param base PDB peripheral base address.
 * @param bEnableContinuousMode Enable the module or not.
 */
static inline void PDB_EnableContinuousMode(PDB_Type *base, bool bEnableContinuousMode)
{
    if (bEnableContinuousMode)
    {
        base->MCTRL |= PDB_MCTRL_CONT_MASK;
    }
    else
    {
        base->MCTRL &= ~PDB_MCTRL_CONT_MASK;
    }
}

/*!
 * @brief Triggers the PDB counter by software.
 *
 * @param base PDB peripheral base address.
 */
static inline void PDB_DoSoftwareTrigger(PDB_Type *base)
{
    base->MCTRL |= PDB_MCTRL_SWTRIG_MASK;
}

/*!
 * @brief Loads the counter values.
 *
 * This function loads the counter values from the internal buffer.
 *
 * @param base PDB peripheral base address.
 */
static inline void PDB_SetLoadOk(PDB_Type *base)
{
    base->MCTRL |= PDB_MCTRL_LDOK_MASK;
}

/*!
 * @brief  Get the PDB LDOK bit status.
 *
 * @param  base PDB peripheral base address.
 *
 * @return      Mask value for asserted flags. true: LDOK is set; false: LDOK is cleared.
 */
static inline bool PDB_GetPdbLdOk(PDB_Type *base)
{
    return (((base->MCTRL & PDB_MCTRL_LDOK_MASK) >> PDB_MCTRL_LDOK_SHIFT) != 0U);
}

/*!
 * @brief Enable the PDB trigger output.
 *
 * When disabled, trigger output will be forced to 0.
 *
 * @param base PDB peripheral base address.
 * @param eTrigger index for trigger instance. See @ref pdb_trigger_output_t.
 * @param bEnable bEnable the triggers or not.
 */
static inline void PDB_EnableTriggerOutput(PDB_Type *base, pdb_trigger_output_t eTrigger, bool bEnable)
{
    switch (eTrigger)
    {
        case kPDB_TriggerA:
        case kPDB_TriggerB:
            if (bEnable)
            {
                base->CTRLA |= ((uint16_t)PDB_CTRLA_ENA_MASK >> (uint16_t)eTrigger);
            }
            else
            {
                base->CTRLA &= ~((uint16_t)PDB_CTRLA_ENA_MASK >> (uint16_t)eTrigger);
            }
            break;
        case kPDB_TriggerC:
        case kPDB_TriggerD:
            if (bEnable)
            {
                base->CTRLC |= ((uint16_t)PDB_CTRLC_ENC_MASK >> ((uint16_t)eTrigger - (uint16_t)kPDB_TriggerC));
            }
            else
            {
                base->CTRLC &= ~((uint16_t)PDB_CTRLC_ENC_MASK >> ((uint16_t)eTrigger - (uint16_t)kPDB_TriggerC));
            }
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}

/*!
 * @brief Bypass the PDB trigger output.
 *
 * When bypass enabled, Trigger output is a single pulse created by the selected trigger source.
 *
 * @param base PDB peripheral base address.
 * @param eTrigger index for trigger instance. See @ref pdb_trigger_output_t.
 * @param bValue The PDB bypassA mode enable or not.
 */
static inline void PDB_BypassTrigger(PDB_Type *base, pdb_trigger_output_t eTrigger, bool bValue)
{
    switch (eTrigger)
    {
        case kPDB_TriggerA:
        case kPDB_TriggerB:
            if (!bValue)
            {
                base->CTRLA &= ~((uint16_t)PDB_CTRLA_BYPA_MASK >> (uint16_t)eTrigger);
            }
            else
            {
                base->CTRLA |= ((uint16_t)PDB_CTRLA_BYPA_MASK >> (uint16_t)eTrigger);
            }
            break;
        case kPDB_TriggerC:
        case kPDB_TriggerD:
            if (!bValue)
            {
                base->CTRLC &= ~((uint16_t)PDB_CTRLC_BYPC_MASK >> ((uint16_t)eTrigger - (uint16_t)kPDB_TriggerC));
            }
            else
            {
                base->CTRLC |= ((uint16_t)PDB_CTRLC_BYPC_MASK >> ((uint16_t)eTrigger - (uint16_t)kPDB_TriggerC));
            }
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}

/*!
 * @brief Enable Trigger output A & B combined mode.
 *
 * When enabled, Trigger A and Trigger B outputs are a function of combined DELAYA and DELAYB. Trigger A is an
 * extended pulse and Trigger B is a dual pulse.
 * When disabled, Trigger A is a function of DELAYA only. Trigger B is a function of DELAYB only.
 *
 * @param base  PDB peripheral base address.
 * @param eLogic index for PDB trigger output logic instance. See @ref pdb_logic_t.
 * @param bMode The trigger A output mode select.
 */
static inline void PDB_EnableTriggerConbineMode(PDB_Type *base, pdb_logic_t eLogic, bool bMode)
{
    if (eLogic == kPDB_LogicA)
    {
        if (bMode)
        {
            base->CTRLA |= PDB_CTRLA_ABSEL_MASK;
        }
        else
        {
            base->CTRLA &= ~PDB_CTRLA_ABSEL_MASK;
        }
    }
    if (eLogic == kPDB_LogicC)
    {
        if (bMode)
        {
            base->CTRLC |= PDB_CTRLC_CDSEL_MASK;
        }
        else
        {
            base->CTRLC &= ~PDB_CTRLC_CDSEL_MASK;
        }
    }
}

/*!
 * @brief Initial trigger Value
 *
 * @param base PDB peripheral base address.
 * @param eTrigger index for trigger instance. See @ref pdb_trigger_output_t.
 * @param eInitValue set trigger init value. See @ref pdb_init_value_t.
 */
static inline void PDB_SetTriggerInitValue(PDB_Type *base, pdb_trigger_output_t eTrigger, pdb_init_value_t eInitValue)
{
    if (eTrigger == kPDB_TriggerA)
    {
        base->CTRLA = (base->CTRLA & ~PDB_CTRLA_AINIT_MASK) | PDB_CTRLA_AINIT(eInitValue);
    }
    if (eTrigger == kPDB_TriggerC)
    {
        base->CTRLC = (base->CTRLC & ~PDB_CTRLC_CINIT_MASK) | PDB_CTRLC_CINIT(eInitValue);
    }
}

/*!
 * @brief Enable PDB fault feature.
 *
 * @param base PDB peripheral base address.
 * @param eLogic index for PDB trigger output logic instance. See @ref pdb_logic_t.
 * @param bEnable Enable the interrupts or not.
 */
static inline void PDB_EnableFault(PDB_Type *base, pdb_logic_t eLogic, bool bEnable)
{
    if (eLogic == kPDB_LogicA)
    {
        if (bEnable)
        {
            base->CTRLA |= PDB_CTRLA_FLTAEN_MASK;
        }
        else
        {
            base->CTRLA &= ~PDB_CTRLA_FLTAEN_MASK;
        }
    }
    else
    {
        if (bEnable)
        {
            base->CTRLC |= PDB_CTRLC_FLTCEN_MASK;
        }
        else
        {
            base->CTRLC &= ~PDB_CTRLC_FLTCEN_MASK;
        }
    }
}

/*!
 * @brief Set the PDB fault length feature.
 *
 * This bit is used to determine the minimum width requirement of the input fault for it to be recognized as a valid
 * fault condition.
 *
 * @param base PDB peripheral base address.
 * @param eLogic index for PDB trigger output logic instance. See @ref pdb_logic_t.
 * @param ePdbFaultLength Set the PDB fault length. See @ref pdb_fault_length_t.
 */
static inline void PDB_FaultLength(PDB_Type *base, pdb_logic_t eLogic, pdb_fault_length_t ePdbFaultLength)
{
    if (eLogic == kPDB_LogicA)
    {
        if (ePdbFaultLength == kPDB_2IPBusClockCycles)
        {
            base->CTRLA &= ~PDB_CTRLA_FLENA_MASK;
        }
        else
        {
            base->CTRLA |= PDB_CTRLA_FLENA_MASK;
        }
    }
    else
    {
        if (ePdbFaultLength == kPDB_2IPBusClockCycles)
        {
            base->CTRLC &= ~PDB_CTRLC_FLENC_MASK;
        }
        else
        {
            base->CTRLC |= PDB_CTRLC_FLENC_MASK;
        }
    }
}

/*!
 * @brief Set fault input polarity.
 *
 * @param base PDB peripheral base address.
 * @param eLogic index for PDB trigger output logic instance. See @ref pdb_logic_t.
 * @param ePolarity Set the PDB fault polarity. See @ref pdb_fault_polarity_t.
 */
static inline void PDB_SetFaultPolarity(PDB_Type *base, pdb_logic_t eLogic, pdb_fault_polarity_t ePolarity)
{
    if (eLogic == kPDB_LogicA)
    {
        if (ePolarity == kPDB_FaultPolarity0)
        {
            base->CTRLA |= PDB_CTRLA_FPOLA_MASK;
        }
        else
        {
            base->CTRLA &= ~PDB_CTRLA_FPOLA_MASK;
        }
    }
    else
    {
        if (ePolarity == kPDB_FaultPolarity0)
        {
            base->CTRLC |= PDB_CTRLC_FPOLC_MASK;
        }
        else
        {
            base->CTRLC &= ~PDB_CTRLC_FPOLC_MASK;
        }
    }
}

/*!
 * @brief The PDB interrupt is enabled according to the provided mask.
 *
 * @param base PDB peripheral base address.
 * @param u16Mask The PDB interrupts to enable. Logical OR of @ref _pdb_interrupt_enable.
 */
static inline void PDB_EnableInterrupts(PDB_Type *base, uint16_t u16Mask)
{
    if ((u16Mask & (uint16_t)kPDB_EnableOverflowInterrupt) != 0U)
    {
        base->MCTRL |= PDB_MCTRL_COIE_MASK;
    }
    if ((u16Mask & ((uint16_t)kPDB_EnableDelayAInterrupt | (uint16_t)kPDB_EnableDelayBInterrupt)) != 0U)
    {
        base->CTRLA |= (u16Mask & (PDB_CTRLA_DAIE_MASK | PDB_CTRLA_DBIE_MASK));
    }
    if ((u16Mask & ((uint16_t)kPDB_EnableDelayCInterrupt | (uint16_t)kPDB_EnableDelayDInterrupt)) != 0U)
    {
        base->CTRLC |= ((u16Mask >> 1) & (PDB_CTRLC_DCIE_MASK | PDB_CTRLC_DDIE_MASK));
    }
}

/*!
 * @brief The PDB interrupt is disabled according to the provided mask.
 *
 * @param base PDB peripheral base address.
 * @param u16Mask The PDB interrupts to disable. Logical OR of @ref _pdb_interrupt_enable.
 */
static inline void PDB_DisableInterrupts(PDB_Type *base, uint16_t u16Mask)
{
    if ((u16Mask & (uint16_t)kPDB_EnableOverflowInterrupt) != 0U)
    {
        base->MCTRL &= ~PDB_MCTRL_COIE_MASK;
    }
    if ((u16Mask & ((uint16_t)kPDB_EnableDelayAInterrupt | (uint16_t)kPDB_EnableDelayBInterrupt)) != 0U)
    {
        base->CTRLA &= ~(u16Mask & (PDB_CTRLA_DAIE_MASK | PDB_CTRLA_DBIE_MASK));
    }
    if ((u16Mask & ((uint16_t)kPDB_EnableDelayCInterrupt | (uint16_t)kPDB_EnableDelayDInterrupt)) != 0U)
    {
        base->CTRLC &= ~((u16Mask >> 1) & (PDB_CTRLC_DCIE_MASK | PDB_CTRLC_DDIE_MASK));
    }
}

/*!
 * @brief Clears the PDB status flags.
 *
 * @param base PDB peripheral base address.
 * @param u16Mask The status flags to clear. This is the logical OR of @ref _pdb_status_flags.
 */
static inline void PDB_ClearStatusFlags(PDB_Type *base, uint16_t u16Mask)
{
    if ((u16Mask & (uint16_t)kPDB_OverflowStatusFlag) != 0U)
    {
        base->MCTRL |= PDB_MCTRL_COF_MASK;
    }
    if ((u16Mask & ((uint16_t)kPDB_DelayAStatusFlag | (uint16_t)kPDB_DelayBStatusFlag)) != 0U)
    {
        base->CTRLA |= (u16Mask & (PDB_CTRLA_DAF_MASK | PDB_CTRLA_DBF_MASK));
    }
    if ((u16Mask & ((uint16_t)kPDB_DelayCStatusFlag | (uint16_t)kPDB_DelayDStatusFlag)) != 0U)
    {
        base->CTRLC |= ((u16Mask << 1) & (PDB_CTRLC_DCIE_MASK | PDB_CTRLC_DDIE_MASK));
    }
}

/*!
 * @brief  Gets the status flags of the PDB module.
 *
 * @param  base PDB peripheral base address.
 *
 * @return      Mask value for asserted flags.
 */
static inline uint16_t PDB_GetStatusFlags(PDB_Type *base)
{
    return ((base->MCTRL & PDB_MCTRL_COF_MASK) >> PDB_MCTRL_COF_SHIFT);
}

/*!
 * @brief Sets the PDB trigger delay.
 *
 * Write logic 1 to the MCTRL[LDMOD] bit, any value written to the DELAY register will be ignored until the value in
 * these registers is loaded into the buffer; and this bit is 0, we need to manually set it to 1.
 *
 * @param base  PDB peripheral base address.
 * @param eTrigger index for trigger instance. See @ref pdb_trigger_output_t.
 * @param u16DelayValue Setting value for PDB counter delay event. 16-bit is available.
 */
static inline void PDB_SetTriggerDelay(PDB_Type *base, pdb_trigger_output_t eTrigger, uint16_t u16DelayValue)
{
    while (PDB_GetPdbLdOk(base))
    {
    }
    switch (eTrigger)
    {
        case kPDB_TriggerA:
            base->DELAYA = u16DelayValue;
            break;
        case kPDB_TriggerB:
            base->DELAYB = u16DelayValue;
            break;
        case kPDB_TriggerC:
            base->DELAYC = u16DelayValue;
            break;
        case kPDB_TriggerD:
            base->DELAYD = u16DelayValue;
            break;
        default:
            assert(false);
            break;
    }
    PDB_SetLoadOk(base);
}

/*!
 * @brief  Specifies the counter period.
 *
 * Write logic 1 to the MCTRL[LDMOD] bit, any value written to the MOD register will be ignored until the value in these
 * registers is loaded into the buffer; and this bit is 0, we need to manually set it to 1.
 *
 * @param  base  PDB peripheral base address.
 * @param  u16PeriodCount Setting value for the modulus. 16-bit is available.
 */
static inline void PDB_SetModulusValue(PDB_Type *base, uint16_t u16PeriodCount)
{
    while (PDB_GetPdbLdOk(base))
    {
    }
    base->MOD = u16PeriodCount;
    PDB_SetLoadOk(base);
}

/*!
 * @brief  Gets the PDB counter's current value.
 *
 * @param  base PDB peripheral base address.
 *
 * @return      PDB counter's current value.
 */
static inline uint16_t PDB_GetCounterValue(PDB_Type *base)
{
    return base->CNTR;
}

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_PDB_H_ */
