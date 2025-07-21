/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_LCU_H_
#define FSL_LCU_H_

#include "fsl_common.h"

/*!
 * @addtogroup lcu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief LCU driver version 2.0.0. */
#define FSL_LCU_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief Macro used for calculate logic cell value. */
#define FSL_LCU_EACH_LC_IO_NUM           (LCU_LC_LUTCTRL_COUNT)
/*! @brief Macro used for calculate logic cell value. */
#define FSL_LCU_GET_LC_VALUE(io)         ((io) / FSL_LCU_EACH_LC_IO_NUM)
/*! @brief Macro used for calculate which IO used in logic cell. */
#define FSL_LCU_GET_LC_IO_VALUE(io)      ((io) % FSL_LCU_EACH_LC_IO_NUM)
/*! @brief Macro used for calculate mask offset in each logic cell. */
#define FSL_LCU_LC_OFFSET(cell)          ((cell) * FSL_LCU_EACH_LC_IO_NUM)
/*! @brief Macro used for calculate force control offset in each IO. */
#define FSL_LCU_FORCE_CONTROL_OFFSET(io) ((io) * LCU_FCTRL_FORCE_SENSE1_SHIFT)

/*! @brief _lcu_cell LCU logic cell flags. */
typedef enum _lcu_cell
{
    kLCU_Lc0 = 0x0U, /*!< Logic cell 0 */
    kLCU_Lc1,        /*!< Logic cell 1 */
    kLCU_Lc2,        /*!< Logic cell 2*/
} lcu_cell_t;

/*! @brief _lcu_inputs LCU inputs. */
typedef enum _lcu_inputs
{
    kLCU_Lc0Input0 = 0x0U, /*!< LC0 input 0. */
    kLCU_Lc0Input1,        /*!< LC0 input 1. */
    kLCU_Lc0Input2,        /*!< LC0 input 2. */
    kLCU_Lc0Input3,        /*!< LC0 input 3. */
    kLCU_Lc1Input0,        /*!< LC1 input 0. */
    kLCU_Lc1Input1,        /*!< LC1 input 1. */
    kLCU_Lc1Input2,        /*!< LC1 input 2. */
    kLCU_Lc1Input3,        /*!< LC1 input 3. */
    kLCU_Lc2Input0,        /*!< LC2 input 0. */
    kLCU_Lc2Input1,        /*!< LC2 input 1. */
    kLCU_Lc2Input2,        /*!< LC2 input 2. */
    kLCU_Lc2Input3,        /*!< LC2 input 3. */
} lcu_inputs_t;

/*! @brief _lcu_outputs LCU outputs. */
typedef enum _lcu_outputs
{
    kLCU_Lc0Output0 = 0x0U, /*!< LC0 output 0. */
    kLCU_Lc0Output1,        /*!< LC0 output 1. */
    kLCU_Lc0Output2,        /*!< LC0 output 2. */
    kLCU_Lc0Output3,        /*!< LC0 output 3. */
    kLCU_Lc1Output0,        /*!< LC1 output 0. */
    kLCU_Lc1Output1,        /*!< LC1 output 1. */
    kLCU_Lc1Output2,        /*!< LC1 output 2. */
    kLCU_Lc1Output3,        /*!< LC1 output 3. */
    kLCU_Lc2Output0,        /*!< LC2 output 0. */
    kLCU_Lc2Output1,        /*!< LC2 output 1. */
    kLCU_Lc2Output2,        /*!< LC2 output 2. */
    kLCU_Lc2Output3,        /*!< LC2 output 3. */
} lcu_outputs_t;

/*! @brief _lcu_bitfields_map LCU inputs/outputs/states mask. */
typedef enum _lcu_bitfields_map
{
    kLCU_Lc0IO0 = 0x01 << 0U,  /*!< LC0 input0/output0/state0 mask. */
    kLCU_Lc0IO1 = 0x01 << 1U,  /*!< LC0 input1/output1/state1 mask. */
    kLCU_Lc0IO2 = 0x01 << 2U,  /*!< LC0 input2/output2/state2 mask. */
    kLCU_Lc0IO3 = 0x01 << 3U,  /*!< LC0 input3/output3/state3 mask. */
    kLCU_Lc1IO0 = 0x01 << 4U,  /*!< LC1 input0/output0/state0 mask. */
    kLCU_Lc1IO1 = 0x01 << 5U,  /*!< LC1 input1/output1/state1 mask. */
    kLCU_Lc1IO2 = 0x01 << 6U,  /*!< LC1 input2/output2/state2 mask. */
    kLCU_Lc1IO3 = 0x01 << 7U,  /*!< LC1 input3/output3/state3 mask. */
    kLCU_Lc2IO0 = 0x01 << 8U,  /*!< LC2 input0/output0/state0 mask. */
    kLCU_Lc2IO1 = 0x01 << 9U,  /*!< LC2 input1/output1/state1 mask. */
    kLCU_Lc2IO2 = 0x01 << 10U, /*!< LC2 input2/output2/state2 mask. */
    kLCU_Lc2IO3 = 0x01 << 11U, /*!< LC2 input3/output3/state3 mask. */
} lcu_bitfields_map_t;

/*! @brief _lcu_lc_inputs LCU input for ecah LC. */
typedef enum _lcu_lc_inputs
{
    kLCU_LcInput0 = 0x0U, /*!< LCU input 0 for each LC. */
    kLCU_LcInput1,        /*!< LCU input 1 for each LC. */
    kLCU_LcInput2,        /*!< LCU input 2 for each LC. */
    kLCU_LcInput3,        /*!< LCU input 3 for each LC. */
} lcu_lc_inputs_t;

/*! @brief _lcu_muxcel_source LCU MUX selected source. */
typedef enum _lcu_muxcel_source
{
    kLCU_MuxSelLogic0 = 0x0U, /*!< Select the logic0 as LC input. */
    kLCU_MuxSelInput0,        /*!< Select the LCU input0 as LC input. */
    kLCU_MuxSelInput1,        /*!< Select the LCU input1 as LC input. */
    kLCU_MuxSelInput2,        /*!< Select the LCU input2 as LC input. */
    kLCU_MuxSelInput3,        /*!< Select the LCU input3 as LC input. */
    kLCU_MuxSelInput4,        /*!< Select the LCU input4 as LC input. */
    kLCU_MuxSelInput5,        /*!< Select the LCU input5 as LC input. */
    kLCU_MuxSelInput6,        /*!< Select the LCU input6 as LC input. */
    kLCU_MuxSelInput7,        /*!< Select the LCU input7 as LC input. */
    kLCU_MuxSelInput8,        /*!< Select the LCU input8 as LC input. */
    kLCU_MuxSelInput9,        /*!< Select the LCU input9 as LC input. */
    kLCU_MuxSelInput10,       /*!< Select the LCU input10 as LC input.*/
    kLCU_MuxSelInput11,       /*!< Select the LCU input11 as LC input. */
    kLCU_MuxSelOutput0,       /*!< Select the LCU output0 as LC input. */
    kLCU_MuxSelOutput1,       /*!< Select the LCU output1 as LC input. */
    kLCU_MuxSelOutput2,       /*!< Select the LCU output2 as LC input. */
    kLCU_MuxSelOutput3,       /*!< Select the LCU output3 as LC input. */
    kLCU_MuxSelOutput4,       /*!< Select the LCU output4 as LC input. */
    kLCU_MuxSelOutput5,       /*!< Select the LCU output5 as LC input. */
    kLCU_MuxSelOutput6,       /*!< Select the LCU output6 as LC input. */
    kLCU_MuxSelOutput7,       /*!< Select the LCU output7 as LC input. */
    kLCU_MuxSelOutput8,       /*!< Select the LCU output8 as LC input. */
    kLCU_MuxSelOutput9,       /*!< Select the LCU output9 as LC input. */
    kLCU_MuxSelOutput10,      /*!< Select the LCU output10 as LC input. */
    kLCU_MuxSelOutput11,      /*!< Select the LCU output11 as LC input. */
} lcu_muxcel_source_t;

/*! @brief _lcu_force_inputs LCU force input. */
typedef enum _lcu_force_inputs
{
    kLCU_ForceInput0 = 0x0U, /*!< LCU LC0 force inout0. */
    kLCU_ForceInput1,        /*!< LCU LC0 force inout1. */
    kLCU_ForceInput2,        /*!< LCU LC0 force inout2. */
    kLCU_ForceInput3,        /*!< LCU LC0 force inout3. */
    kLCU_ForceInput4,        /*!< LCU LC1 force inout0. */
    kLCU_ForceInput5,        /*!< LCU LC1 force inout1. */
    kLCU_ForceInput6,        /*!< LCU LC1 force inout2. */
    kLCU_ForceInput7,        /*!< LCU LC1 force inout3. */
    kLCU_ForceInput8,        /*!< LCU LC2 force inout0. */
    kLCU_ForceInput9,        /*!< LCU LC2 force inout1. */
    kLCU_ForceInput10,       /*!< LCU LC2 force inout2. */
    kLCU_ForceInput11,       /*!< LCU LC2 force inout3. */
} lcu_force_inputs_t;

/*! @brief _lcu_force_input_polarity LCU force input polarity. */
typedef enum _lcu_force_input_polarity
{
    kLCU_ForceInputPolarityNoInverted = 0x0U, /*!< The polarity not inverted to the force input. */
    kLCU_ForceInputPolarityInverted,          /*!< The polarity inverted to the force input. */
} lcu_force_input_polarity_t;

/*! @brief _lcu_sync_select_source LCU sync mode selected source. */
typedef enum _lcu_sync_select_source
{
    kLCU_SyncInput0 = 0x0U, /*!< select LC sync input0 to use for output. */
    kLCU_SyncInput1,        /*!< select LC sync input1 to use for output. */
} lcu_sync_select_source_t;

/*! @brief _lcu_software_sync_mode LCU software sync mode. */
typedef enum _lcu_software_sync_mode
{
    kLCU_SoftwareImmediateSync = 0x0U, /*!< Software sync immediate for the inputs.*/
    kLCU_SoftwareRiseEdgeSync,         /*!< Software sync on rising edge of sync for the inputs. */
} lcu_software_sync_mode_t;

/*! @brief _lcu_force_Input_sensitivity LCU force input Sensitivity. */
typedef enum _lcu_force_input_sensitivity
{
    kLCU_ForceInput0Affect = 0x1U, /*!< Force input0 affect ouput. */
    kLCU_ForceInput1Affect = 0x2U, /*!< Force input1 affect ouput. */
    kLCU_ForceInput2Affect = 0x4U, /*!< Force input2 affect ouput. */
} lcu_force_input_sensitivity_t;

/*! @brief _lcu_force_clearing_mode LCU force clearing mode. */
typedef enum _lcu_force_clearing_mode
{
    kLCU_ClearWithDeassertion = 0x0U,                         /*!< Clear force events on deassertion of force inputs. */
    kLCU_ClearWithRisingSyncAfterDeassertion,                 /*!< Clear force events on rising sync after deassertion of force inputs. */
    kLCU_ClearWithStatusClearedAfterDeassertion,              /*!< Clear force events when clear force event status after deassertion of force inputs. */
    kLCU_ClearWithRisingSyncAfterStatusClearedAndDeassertion, /*!< Clear force events on rising sync Deassertion en clear force event status after deassertion of force inputs.. */
} lcu_force_clearing_mode_t;

/*!@brief _lcu_software_override LCU software override value. */
typedef enum _lcu_software_override
{
    kLCU_SoftwareOverride0 = 0x0U, /*!< LCU software override 0. */
    kLCU_SoftwareOverride1,        /*!< LCU software override 1. */
} lcu_software_override_t;

/*!@brief _lcu_output_polarity LCU output polarity. */
typedef enum _lcu_output_polarity
{
    kLCU_OutputPolarityNotInverted = 0x0U, /*!< The polarity of the outputs not inverted. */
    kLCU_OutputPolarityInverted,           /*!< The polarity of the outputs inverted. */
} lcu_output_polarity_t;

/*! @brief LCU force configuration structure.*/
typedef struct _lcu_force_config
{
    bool CombinationEnable;              /*!< Enable combinational force path. */
    lcu_force_input_polarity_t polarity; /*!< Force input polarity. */
    uint8_t filter;                      /*!< Force filter. */
} lcu_force_config_t;

/*! @brief LCU output configuration structure.*/
typedef struct _lcu_output_config
{
    bool outputEnable;                             /*!< Enable LC output. */
    bool softwareOverrideEnable;                   /*!< Enable software override of input. */
    lcu_software_override_t softwareOverridevalue; /*!< Software override value for input. */
    lcu_sync_select_source_t softwareSyncSelect;   /*!< Select sync input for software sync mode. */
    lcu_software_sync_mode_t SyncMode;             /*!< Sync mode for input. */
    lcu_sync_select_source_t syncSelect;           /*!< Select sync input for output. */
    lcu_force_clearing_mode_t forceClearMode;      /*!< Timing for clearing force events for output. */
    lcu_output_polarity_t outputPolarity;          /*!< Polarity of output. */
    uint32_t forceInputSentivity;                  /*!< Mask of force inputs that affect output @lcu_force_input_sensitivity_t */
    uint32_t riseFilter;                           /*!< Rise Filter. */
    uint32_t fallFilter;                           /*!< Fall Filter. */
    uint32_t lutValue;                             /*!< Value of LCU loolup table. */
} lcu_output_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name LCU Initialization and de-initialization
 * @{
 */

/*!
 * @brief Initializes the LCU peripheral.
 *
 * This function ungates the LCU clock.
 *
 * @param base LCU peripheral base address.
 *
 */
void LCU_Init(LCU_Type *base);

/*!
 * @brief Deinitializes the LCU peripheral.
 *
 * This function gates the LCU clock.
 *
 * @param base LCU peripheral base address.
 */
void LCU_Deinit(LCU_Type *base);

/*!
 * @brief Gets the default configuration for LCU force input.
 *
 * This function initializes the LCU force input configuration structure to a default value. The default
 * values are as follows.
 * code
 *   config->CombinationEnable = kLCU_SoftwareOverride0;
 *   config->polarity = kLCU_ForceInputPolarityNoInverted;
 *   config->filter = false;
 * endcode
 * @param config Pointer to the configuration structure.
 */
void LCU_GetForceInputDefaultConfig(lcu_force_config_t *config);

/*!
 * @brief Gets the default configuration for LCU output.
 *
 * This function initializes the LCU output configuration structure to a default value. The default
 * values are as follows.
 * code
 *   config->outputEnable = false;
 *   config->softwareOverrideEnable = false;
 *   config->softwareOverridevalue = kLCU_SoftwareOverride0;
 *   config->softwareSyncSelect = kLCU_SyncInput0;
 *   config->SyncMode = kLCU_SoftwareImmediateSync;
 *   config->syncSelect = kLCU_SyncInput0;
 *   config->forceClearMode = kLCU_ClearWithDeassertion;
 *   config->outputPolarity = kLCU_OutputPolarityNotInverted;
 *   config->forceInputSentivity = 0U;
 *   config->riseFilter = 0U;
 *   config->fallFilter = 0U;
 *   config->lutValue = 0xFFFFU;
 * endcode
 * @param config Pointer to the configuration structure.
 */
void LCU_GetOutputDefaultConfig(lcu_output_config_t *config);

/*!
 * @brief Initializes force input.
 *
 * This function gates the LCU clock.
 *
 * @param base LCU peripheral base address.
 * @param forceInput LCU force input number.
 * @param forceInputConfig  Pointer to the LCU force input configuration structure.
 */
void LCU_ForceInit(LCU_Type *base, lcu_force_inputs_t forceInput, const lcu_force_config_t *forceInputConfig);

/*!
 * @brief Deinitializes the LCU output.
 *
 * This function gates the LCU clock.
 *
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param outputConfig Pointer to the LCU configuration structure.
 */
void LCU_OutputInit(LCU_Type *base, lcu_outputs_t output, const lcu_output_config_t *outputConfig);

/*!
 * @brief Get LC logic inputs.
 *
 * This function Sete lookup table with inputs for LC outputs.
 * When inputs and lutvalue correspond to the table, lut generates lut event and output logic 1
 * The relationship between lut value and input and output will be as follows.
 * -----------------------------------------------------------------------------------------
 * |  input3  |  input2  |  input1  |  input0|  lutvalue mask  | example(lutValue == 0x35) |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     0    |     0    |     0  |       0x01      |             1             |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     0    |     0    |     1  |       0x0002    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     0    |     1    |     0  |       0x0004    |             1             |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     0    |     1    |     1  |       0x0008    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     1    |     0    |     0  |       0x0010    |             1             |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     1    |     0    |     1  |       0x0020    |             1             |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     1    |     1    |     0  |       0x0040    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     0    |     1    |     1    |     1  |       0x0080    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     0    |     0    |     0  |       0x0100    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     0    |     0    |     1  |       0x0200    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     0    |     1    |     0  |       0x0400    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     0    |     1    |     1  |       0x0800    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     1    |     0    |     0  |       0x1000    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     1    |     0    |     1  |       0x2000    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     1    |     1    |     0  |       0x4000    |             0             |
 * |---------------------------------------------------------------------------------------|
 * |     1    |     1    |     1    |     1  |       0x8000    |             0             |
 * -----------------------------------------------------------------------------------------
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param lutValue lut value.
 * 
 */
static inline void LCU_SetLutValue(LCU_Type *base, lcu_outputs_t output, uint32_t lutValue)
{
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);

    base->LC[cell].LUTCTRL[outputBit] = LCU_LUTCTRL_LUTCTRL(lutValue);
}

/*!
 * @brief Get LC logic inputs.
 *
 * @param base LCU peripheral base address.
 * @return The mask of LC inputs status. 
 *         Users can refer to @ref lcu_bitfields_map_t to confirm the meaning of mask
 */
static inline uint32_t LCU_GetInputs(LCU_Type *base)
{
    return base->LCIN;
}

/*!
 * @brief Get software override inputs.
 *
 * @param base LCU peripheral base address.
 * @return The mask of software override inputs status. 
 *         Users can refer to @ref lcu_bitfields_map_t to confirm the meaning of mask
 */
static inline uint32_t LCU_GetSoftwareOverrideInputs(LCU_Type *base)
{
    return base->SWOUT;
}

/*!
 * @brief Get LC logic outputs.
 *
 * @param base LCU peripheral base address.
 * @return The mask of LC outputs status. 
 *         Users can refer to @ref lcu_bitfields_map_t to confirm the meaning of mask
 */
static inline uint32_t LCU_GetOutputs(LCU_Type *base)
{
    return base->LCOUT;
}

/*!
 * @brief Get force sensitivity values.
 *
 * @param base LCU peripheral base address.
 * @return The mask of forced outputs status. 
 *         Users can refer to @ref lcu_bitfields_map_t to confirm the meaning of mask
 */
static inline uint32_t LCU_GetForceSensitivity(LCU_Type *base)
{
    return base->FORCEOUT;
}

/*!
 * @brief Enable lcu debug mode.
 *
 * This function support LCU outputs can continue operation when the chip is in Debug mode.
 * 
 * @param base LCU peripheral base address.
 * @param outputsMask Mask of debug mode for outputs associated with @ref lcu_bitfields_map_t.
 * @param enable Switcher of LCU debug mode feature. "true" means to enable, "false" means not.
 */
static inline void LCU_EnableDebugMode(LCU_Type *base, uint32_t outputsMask, bool enable)
{
    if(enable)
    {
        base->DBGEN |= LCU_DBGEN_DBGEN(outputsMask);
    }
    else
    {
        base->DBGEN &= ~LCU_DBGEN_DBGEN(outputsMask);
    }
}

/*!
 * @brief Enable software override of LC inputs.
 * 
 * @param base LCU peripheral base address.
 * @param inputsMask Mask of inputs which enabl software override associated with @ref lcu_bitfields_map_t.
 * @param enable Switcher of LCU software override feature. "true" means to enable, "false" means not.
 */
static inline void LCU_EnableSoftwareOverride(LCU_Type *base, uint32_t inputsMask, bool enable)
{
    if(enable)
    {
        base->SWEN |= LCU_SWEN_SWEN(inputsMask);
    }
    else
    {
        base->SWEN &= ~LCU_SWEN_SWEN(inputsMask);
    }
}

/*!
 * @brief Set software override value of LC inputs.
 * 
 * This function Specifies the software override value for each LC input.
 * 
 * @param base LCU peripheral base address.
 * @param inputMask Mask of inputs which set software override value associated with @ref lcu_bitfields_map_t.
 * @param value software override value.
 */
static inline void LCU_SetSoftwareOverrideValue(LCU_Type *base, uint32_t inputMask, lcu_software_override_t value)
{
    if (value == kLCU_SoftwareOverride1)
    {
        base->SWVALUE |=  LCU_SWVALUE_SWVALUE(inputMask);
    }
    else
    {
        base->SWVALUE &= ~LCU_SWVALUE_SWVALUE(inputMask);
    }
}

/*!
 * @brief Enable LC outputs.
 * 
 * @param base LCU peripheral base address.
 * @param outputsMask Mask of outputs which enabled output associated with @ref lcu_bitfields_map_t.
 * @param enable Switcher of LCU outputs feature. "true" means to enable, "false" means not.
 */
static inline void LCU_EnableOutput(LCU_Type *base, uint32_t outputsMask, bool enable)
{
    if(enable)
    {
        base->OUTEN |= LCU_OUTEN_OUTEN(outputsMask);
    }
    else
    {
        base->OUTEN &= ~LCU_OUTEN_OUTEN(outputsMask);
    }
}

/*!
 * @brief Set the polarity of the outputs.
 * 
 * This function specifies the polarity of the outputs.
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param polarity The output polarity.
 */
static inline void LCU_SetOutputPolarity(LCU_Type *base, lcu_outputs_t output, lcu_output_polarity_t polarity)
{
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);
    uint32_t outputMask = 1 << outputBit;

    if(polarity == kLCU_OutputPolarityInverted)
    {
        base->LC[cell].OUTPOL |= LCU_OUTPOL_OUTPOL(outputMask);
    }
    else
    {
        base->LC[cell].OUTPOL &= ~LCU_OUTPOL_OUTPOL(outputMask);
    }
}

/*!
 * @brief Set the LUT DMA requests generation.
 *
 * This function enables the generation of a DMA request when an LUT event occurs 
 * 
 * @param base LCU peripheral base address.
 * @param lutMask Mask of LUT event associated with @ref lcu_bitfields_map_t.
 * @param enable Switcher of DMA request by LUT event feature. "true" means to enable, "false" means not.
 */
static inline void LCU_SetLutDma(LCU_Type *base, uint32_t lutMask, bool enable)
{
    if(enable)
    {
        base->LC[kLCU_Lc0].INTDMAEN |= LCU_INTDMAEN_LUT_DMA_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0)));
        base->LC[kLCU_Lc1].INTDMAEN |= LCU_INTDMAEN_LUT_DMA_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1)));
        base->LC[kLCU_Lc2].INTDMAEN |= LCU_INTDMAEN_LUT_DMA_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2)));
    }
    else
    {
        base->LC[kLCU_Lc0].INTDMAEN &= ~(LCU_INTDMAEN_LUT_DMA_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0))));
        base->LC[kLCU_Lc1].INTDMAEN &= ~(LCU_INTDMAEN_LUT_DMA_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1))));
        base->LC[kLCU_Lc2].INTDMAEN &= ~(LCU_INTDMAEN_LUT_DMA_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2))));
    }
}

/*!
 * @brief Set the force DMA requests generation.
 *
 * This function enables the generation of a DMA request when an force event occurs 
 * 
 * @param base LCU peripheral base address.
 * @param forceMask Mask of force event associated with @ref lcu_bitfields_map_t.
 * @param enable Switcher of DMA request by force event feature. "true" means to enable, "false" means not.
 */
static inline void LCU_SetForceDma(LCU_Type *base, uint32_t forceMask, bool enable)
{
    if(enable)
    {
        base->LC[kLCU_Lc0].INTDMAEN |= LCU_INTDMAEN_FORCE_DMA_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0)));
        base->LC[kLCU_Lc1].INTDMAEN |= LCU_INTDMAEN_FORCE_DMA_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1)));
        base->LC[kLCU_Lc2].INTDMAEN |= LCU_INTDMAEN_FORCE_DMA_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2)));
    }
    else
    {
        base->LC[kLCU_Lc0].INTDMAEN &= ~(LCU_INTDMAEN_FORCE_DMA_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0))));
        base->LC[kLCU_Lc1].INTDMAEN &= ~(LCU_INTDMAEN_FORCE_DMA_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1))));
        base->LC[kLCU_Lc2].INTDMAEN &= ~(LCU_INTDMAEN_FORCE_DMA_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2))));
    }
}

/*!
 * @brief Set the LUT interrupt requests generation.
 *
 * This function enables the generation of a interrupt request when an LUT event occurs 
 * 
 * @param base LCU peripheral base address.
 * @param lutMask Mask of LUT event associated with @ref lcu_bitfields_map_t.
 * @param enable Switcher of interrupt request by LUT event feature. "true" means to enable, "false" means not.
 */
static inline void LCU_SetLutInterrupt(LCU_Type *base, uint32_t lutMask, bool enable)
{
    if(enable)
    {
        base->LC[kLCU_Lc0].INTDMAEN |= LCU_INTDMAEN_LUT_INT_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0)));
        base->LC[kLCU_Lc1].INTDMAEN |= LCU_INTDMAEN_LUT_INT_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1)));
        base->LC[kLCU_Lc2].INTDMAEN |= LCU_INTDMAEN_LUT_INT_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2)));
    }
    else
    {
        base->LC[kLCU_Lc0].INTDMAEN &= ~(LCU_INTDMAEN_LUT_INT_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0))));
        base->LC[kLCU_Lc1].INTDMAEN &= ~(LCU_INTDMAEN_LUT_INT_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1))));
        base->LC[kLCU_Lc2].INTDMAEN &= ~(LCU_INTDMAEN_LUT_INT_EN((lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2))));
    }
}

/*!
 * @brief Set the force interupt.
 *
 * This function enables the generation of a interrupt request when an force event occurs 
 * 
 * @param base LCU peripheral base address.
 * @param forceMask Mask of force event associated with @ref lcu_bitfields_map_t.
 * @param enable Switcher of interrupt request by force event feature. "true" means to enable, "false" means not.
 */
static inline void LCU_SetForceInterrupt(LCU_Type *base, uint32_t forceMask, bool enable)
{
    if(enable)
    {
        base->LC[kLCU_Lc0].INTDMAEN |= LCU_INTDMAEN_FORCE_INT_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0)));
        base->LC[kLCU_Lc1].INTDMAEN |= LCU_INTDMAEN_FORCE_INT_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1)));
        base->LC[kLCU_Lc2].INTDMAEN |= LCU_INTDMAEN_FORCE_INT_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2)));
    }
    else
    {
        base->LC[kLCU_Lc0].INTDMAEN &= ~(LCU_INTDMAEN_FORCE_INT_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0))));
        base->LC[kLCU_Lc1].INTDMAEN &= ~(LCU_INTDMAEN_FORCE_INT_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1))));
        base->LC[kLCU_Lc2].INTDMAEN &= ~(LCU_INTDMAEN_FORCE_INT_EN((forceMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2))));
    }
}

/*!
 * @brief Get LUT interrupt status.
 * 
 * @param base LCU peripheral base address.
 * @return The mask of LUT interrupt status. 
 *         Users can refer to @ref lcu_bitfields_map_t to confirm the meaning of mask
 */
static inline uint32_t LCU_GetLutInterruptStatus(LCU_Type *base)
{
    uint32_t lutMask;

    lutMask = (((base->LC[kLCU_Lc0].STS & LCU_STS_LUT_STS_MASK) << FSL_LCU_LC_OFFSET(kLCU_Lc0)) | \
             ((base->LC[kLCU_Lc1].STS & LCU_STS_LUT_STS_MASK) << FSL_LCU_LC_OFFSET(kLCU_Lc1)) | \
             ((base->LC[kLCU_Lc2].STS & LCU_STS_LUT_STS_MASK) << FSL_LCU_LC_OFFSET(kLCU_Lc2)));

    return lutMask;
}

/*!
 * @brief Get force interrupt status.
 * 
 * @param base LCU peripheral base address.
 * @return The mask of force interrupt status. 
 *         Users can refer to @ref lcu_bitfields_map_t to confirm the meaning of mask
 */
static inline uint32_t LCU_GetForceInterruptStatus(LCU_Type *base)
{
    return base->FORCESTS;
}

/*!
 * @brief Clear the LUT interupt status.
 *
 * This function Clear the LUT interupt status.
 * 
 * @param base LCU peripheral base address.
 * @param lutMask Mask of LUT interrupt status associated with @ref lcu_bitfields_map_t.
 */
static inline void LCU_ClearLutInterruptStatus(LCU_Type *base, uint32_t lutMask)
{
    base->LC[kLCU_Lc0].STS &= LCU_STS_LUT_STS(lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc0));
    base->LC[kLCU_Lc1].STS &= LCU_STS_LUT_STS(lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc1));
    base->LC[kLCU_Lc2].STS &= LCU_STS_LUT_STS(lutMask >> FSL_LCU_LC_OFFSET(kLCU_Lc2));
}

/*!
 * @brief Clears force interrupt status.
 *
 * @param base LCU peripheral base address.
 * @param mask Mask of force interrupt flags associated with @ref lcu_bitfields_map_t.
 */
static inline void LCU_ClearForceInterruptStatus(LCU_Type *base, uint32_t forceMask)
{
    base->FORCESTS = LCU_FORCESTS_FORCESTS(forceMask);
}

/*!
 * @brief Selects the source of the LC input.
 * 
 * @param base LCU peripheral base address.
 * @param input LCU input number.
 * @param source The source source of the LC input.
 */
static inline void LCU_MuxSelect(LCU_Type *base, lcu_inputs_t input, lcu_muxcel_source_t source)
{
    base->MUXSEL[input] = source;
}

/*!
 * @brief Set LCU rise filter.
 * 
 * This function specifies the number of consecutive clock cycles the filter 
 * output must be logic 1 before the output signal goes high.
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param value The value of rise filter.
 */
static inline void LCU_SetRiseFilter(LCU_Type *base, lcu_outputs_t output, uint32_t value)
{
    uint32_t tmpreg;
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);

    tmpreg = base->LC[cell].FILT[outputBit];
    tmpreg &= ~(LCU_FILT_LUT_RISE_FILT_MASK);
    tmpreg |= LCU_FILT_LUT_RISE_FILT(value);
    base->LC[cell].FILT[outputBit] = tmpreg;
}

/*!
 * @brief Set LCU fall filter.
 * 
 * This function specifies the number of consecutive clock cycles the filter 
 * output must be logic 0 before the output signal goes low
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param value The value of fall filter.
 */
static inline void LCU_SetFallFilter(LCU_Type *base, lcu_outputs_t output, uint32_t value)
{
    uint32_t tmpreg;
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);

    tmpreg = base->LC[cell].FILT[outputBit];
    tmpreg &= ~(LCU_FILT_LUT_FALL_FILT_MASK);
    tmpreg |= LCU_FILT_LUT_FALL_FILT(value);
    base->LC[cell].FILT[outputBit] = tmpreg;
}

/*!
 * @brief Select software sync input.
 * 
 * This function selects which sync input to use for software synced mode.
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param source The sync source for the software synced mode of this LC.
 */
static inline void LCU_SoftwareSyncSelect(LCU_Type *base, lcu_outputs_t output, lcu_sync_select_source_t source)
{
    uint32_t tmpreg;
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);

    tmpreg = base->LC[cell].SCTRL;
    tmpreg &= ~(LCU_SCTRL_SW_SYNC_SEL_MASK);
    tmpreg |= LCU_SCTRL_SW_SYNC_SEL(source);
    base->LC[cell].SCTRL = tmpreg;
}

/*!
 * @brief Select sync input.
 * 
 * This function selects which sync input to use for synced mode.
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param source The sync source for the output of LCU.
 */
static inline void LCU_SyncSelect(LCU_Type *base, lcu_outputs_t output, lcu_sync_select_source_t source)
{
    uint32_t tmpreg;
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);

    tmpreg = base->LC[cell].FCTRL;
    tmpreg &= ~(LCU_FCTRL_SYNC_SEL0_MASK << FSL_LCU_FORCE_CONTROL_OFFSET(outputBit));
    tmpreg |= (LCU_FCTRL_SYNC_SEL0(source) << FSL_LCU_FORCE_CONTROL_OFFSET(outputBit));
    base->LC[cell].FCTRL = tmpreg;
}

/*!
 * @brief Set force clearing mode.
 * 
 * This function specifies the timing for clearing force events for output.
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param mode The mode of which timing to clear force events.
 */
static inline void LCU_SetForceClearMode(LCU_Type *base, lcu_outputs_t output, lcu_force_clearing_mode_t mode)
{
    uint32_t tmpreg;
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);

    tmpreg = base->LC[cell].FCTRL;
    tmpreg &= ~(LCU_FCTRL_FORCE_MODE0_MASK << FSL_LCU_FORCE_CONTROL_OFFSET(outputBit));
    tmpreg |= (LCU_FCTRL_FORCE_MODE0(mode) << FSL_LCU_FORCE_CONTROL_OFFSET(outputBit));
    base->LC[cell].FCTRL = tmpreg;
}

/*!
 * @brief Set force input Sensitivity.
 * 
 * Selects which force inputs affect specified output.
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param inputsMask The mask of input in one LC, reference to @ref lcu_force_input_sensitivity_t.
 */
static inline void LCU_ForceInputSensitivity(LCU_Type *base, lcu_outputs_t output, uint32_t inputsMask)
{
    uint32_t tmpreg;
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);

    tmpreg = base->LC[cell].FCTRL;
    tmpreg &= ~(LCU_FCTRL_FORCE_SENSE0_MASK << FSL_LCU_FORCE_CONTROL_OFFSET(outputBit));
    tmpreg |= (LCU_FCTRL_FORCE_SENSE0(inputsMask) << FSL_LCU_FORCE_CONTROL_OFFSET(outputBit));
    base->LC[cell].FCTRL = tmpreg;
}

/*!
 * @brief Set force clearing mode.
 * 
 * This function specifies the software sync mode for the inputs.
 * 
 * @param base LCU peripheral base address.
 * @param output LCU output number.
 * @param mode The mode of software sync for the output.
 */
static inline void LCU_SetSoftwareSyncMode(LCU_Type *base, lcu_outputs_t output, lcu_software_sync_mode_t mode)
{
    uint32_t cell = FSL_LCU_GET_LC_VALUE(output);
    uint32_t outputBit = FSL_LCU_GET_LC_IO_VALUE(output);
    uint32_t outputMask = 1U << outputBit;

    if(mode == kLCU_SoftwareRiseEdgeSync)
    {
        base->LC[cell].SCTRL |= LCU_SCTRL_SW_MODE(outputMask);
    }
    else
    {
        base->LC[cell].SCTRL &= ~LCU_SCTRL_SW_MODE(outputMask);
    }
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_LCU_H_ */
