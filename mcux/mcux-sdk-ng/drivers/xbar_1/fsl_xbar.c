/*
 * Copyright 2022, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_xbar.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xbar_1"
#endif

/*
 * kXBAR1_InputLogicLow            = 0|0x10000U = 0x10000
 * 0x1000 = 0b0000 0000 0000 0001            0000 0000 0000 0000
 *            |                 |            |                 |
 *            +-----------------+            +-----------------+
 *                |                                  |
 *        xbar instance index(16bits)      xbar input/output signal index(16bits)
 *
 */
#define XBAR_INST_FROM_INPUT(input)   ((uint16_t)(input >> 16U))
#define XBAR_INST_FROM_OUTPUT(output) ((uint16_t)(output >> 16U))

#define XBAR_EXTRACT_INPUT(input)   ((uint16_t)(input & 0xFFFFU))
#define XBAR_EXTRACT_OUTPUT(output) ((uint16_t)(output& 0xFFFFU))


#define XBAR_CTRL_STAT_SHIFT 4U
#define XBAR_CTRL_STAT_MASK  ((xbar_reg_t)1U << 4U)

#if defined(FSL_FEATURE_XBAR_DSC_REG_WIDTH) && (FSL_FEATURE_XBAR_DSC_REG_WIDTH == 32)
#define XBAR_CTRL_ALL_STAT_MASK (XBAR_CTRL_STAT_MASK)
#define XBAR_SEL_MAX_MASK  (0x1FFU)
#else
#define XBAR_CTRL_ALL_STAT_MASK (XBAR_CTRL_STAT_MASK | (XBAR_CTRL_STAT_MASK << 8U))
#define XBAR_SEL_MAX_MASK  (0xFFU)
#endif

/* Array of XBAR clock name. */
static const clock_ip_name_t s_xbaraClock[] = XBAR_CLOCKS;

static const xbar_info_t s_xbarInfo[] = XBAR_INFO;

#if defined(FSL_FEATURE_XBAR_DSC_REG_WIDTH) && (FSL_FEATURE_XBAR_DSC_REG_WIDTH == 32)
/*!
 * brief Get the XBAR peripheral address CTRL register address.
 *
 * param output XBAR output signal.
 * param ctrlReg Addr XBAR control register address.
 * retval kStatus_Success Signal connection set successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
static status_t XBAR_GetCtrlReg(xbar_output_signal_t output, volatile xbar_reg_t **ctrlRegAddr)
{
    status_t status;
    uint16_t inst        = XBAR_INST_FROM_OUTPUT(output);
    uint16_t outputIndex = XBAR_EXTRACT_OUTPUT(output);

    if ((inst > ARRAY_SIZE(s_xbarInfo)) || (outputIndex > (s_xbarInfo[inst - 1U].regCtrlNum)))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        *ctrlRegAddr = s_xbarInfo[inst - 1U].baseAddr + (s_xbarInfo[inst - 1U].regCtrlOffset / sizeof(xbar_reg_t) + outputIndex);
        status       = kStatus_Success;
    }

    return status;
}
#else
/*!
 * brief Get the XBAR peripheral address and shift.
 *
 * Example:
   code
   XBAR_GetCtrlRegAndShift(kXBAR_DSC1_InputLogicLow, XBAR_DSC1_BASE, 1);
   endcode
 *
 * param output XBAR output signal.
 * param ctrlReg Addr XBAR control register address.
 * param shift Number of XBAR control register.
 * retval kStatus_Success Signal connection set successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
static status_t XBAR_GetCtrlRegAndShift(xbar_output_signal_t output, volatile xbar_reg_t **ctrlRegAddr, uint8_t *shift)
{
    status_t status;
    uint16_t inst        = XBAR_INST_FROM_OUTPUT(output);
    uint16_t outputIndex = XBAR_EXTRACT_OUTPUT(output);

    if ((inst > ARRAY_SIZE(s_xbarInfo)) || (outputIndex > (s_xbarInfo[inst - 1U].regCtrlNum * 2U)))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        *ctrlRegAddr = s_xbarInfo[inst - 1U].baseAddr + ((s_xbarInfo[inst - 1U].regCtrlOffset + outputIndex) / 2U);
        *shift       = (uint8_t)(uint16_t)(8U * (outputIndex % 2U));
        status       = kStatus_Success;
    }

    return status;
}
#endif

/*!
 * brief Initializes the XBAR module.
 *
 * This function un-gates the XBAR clock.
 *
 * param xbarInstance XBAR peripheral address.
 */
void XBAR_Init(xbar_instance_t xbarInstance)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable XBARA module clock. */
    (void)CLOCK_EnableClock(s_xbaraClock[xbarInstance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Shuts down the XBAR module.
 *
 * This function disables XBAR clock.
 *
 * param xbarInstance XBAR peripheral address.
 */
void XBAR_Deinit(xbar_instance_t xbarInstance)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable XBARA module clock. */
    (void)CLOCK_DisableClock(s_xbaraClock[xbarInstance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets a connection between the selected XBAR_IN[*] input and the XBAR_OUT[*] output signal.
 *
 * This function connects the XBAR input to the selected XBAR output.
 * If more than one XBAR module is available, only the inputs and outputs from the same module
 * can be connected.
 *
 * Example:
   code
   XBAR_SetSignalsConnection(kXBAR_DSC1_InputLogicLow, kXBAR_DSC1_OutputTriggerSyncIn0);
   endcode
 *
 * param input XBAR input signal.
 * param output XBAR output signal.
 * retval kStatus_Success Signal connection set successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t XBAR_SetSignalsConnection(xbar_input_signal_t input, xbar_output_signal_t output)
{
    status_t status;
    uint16_t inst        = XBAR_INST_FROM_OUTPUT(output);
    uint16_t outputIndex = XBAR_EXTRACT_OUTPUT(output);
    uint16_t inputIndex  = XBAR_EXTRACT_INPUT(input);
    volatile xbar_reg_t *selRegAddr;

#if defined(FSL_FEATURE_XBAR_DSC_REG_WIDTH) && (FSL_FEATURE_XBAR_DSC_REG_WIDTH == 32)
    if ((inst > ARRAY_SIZE(s_xbarInfo)) || (outputIndex > (s_xbarInfo[inst - 1U].regSelNum)))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        selRegAddr  = s_xbarInfo[inst - 1U].baseAddr + ((s_xbarInfo[inst - 1U].regSelOffset + outputIndex));
        *selRegAddr = (*selRegAddr & ~((xbar_reg_t)XBAR_SEL_MAX_MASK)) | (inputIndex);
        status      = kStatus_Success;
    }
#else
    uint8_t shiftInReg;

    if ((inst > ARRAY_SIZE(s_xbarInfo)) || (outputIndex > (s_xbarInfo[inst - 1U].regSelNum * 2U)))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        selRegAddr  = s_xbarInfo[inst - 1U].baseAddr + ((s_xbarInfo[inst - 1U].regSelOffset + outputIndex) / 2U);
        shiftInReg  = (uint8_t)(uint16_t)(8U * (outputIndex % 2U));
        *selRegAddr = (*selRegAddr & ~((xbar_reg_t)XBAR_SEL_MAX_MASK << shiftInReg)) | (inputIndex << shiftInReg);
        status      = kStatus_Success;
    }
#endif

    return status;
}

/*!
 * brief Clears the edge detection status flags.
 *
 * param output XBAR output signal.
 * retval kStatus_Success Signal connection set successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t XBAR_ClearOutputStatusFlag(xbar_output_signal_t output)
{
    status_t status;
    volatile xbar_reg_t *ctrlRegAddr;

#if defined(FSL_FEATURE_XBAR_DSC_REG_WIDTH) && (FSL_FEATURE_XBAR_DSC_REG_WIDTH == 32)
    status = XBAR_GetCtrlReg(output, &ctrlRegAddr);

    if (status == kStatus_Success)
    {
        *ctrlRegAddr |= XBAR_CTRL_STAT_MASK;
    }
#else
    uint8_t shiftInReg;

    status = XBAR_GetCtrlRegAndShift(output, &ctrlRegAddr, &shiftInReg);

    if (status == kStatus_Success)
    {
        *ctrlRegAddr = (*ctrlRegAddr & (~XBAR_CTRL_ALL_STAT_MASK)) | (XBAR_CTRL_STAT_MASK << shiftInReg);
    }
#endif

    return status;
}

/*!
 * brief Gets the active edge detection status.
 *
 * This function gets the active edge detect status of all XBAR_OUTs. If the
 * active edge occurs, the return value is asserted. When the interrupt or the DMA
 * functionality is enabled for the XBAR_OUTx, this field is 1 when the interrupt
 * or DMA request is asserted and 0 when the interrupt or DMA request has been
 * cleared.
 *
 * param output XBAR output signal.
 * param flag get XBAR output status flag.
 * retval kStatus_Success Signal connection set successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t XBAR_GetOutputStatusFlag(xbar_output_signal_t output, bool *flag)
{
    status_t status;
    volatile xbar_reg_t *ctrlRegAddr;
#if defined(FSL_FEATURE_XBAR_DSC_REG_WIDTH) && (FSL_FEATURE_XBAR_DSC_REG_WIDTH == 32)
    status = XBAR_GetCtrlReg(output, &ctrlRegAddr);

    if (status == kStatus_Success)
    {
        *flag = (0U != (*ctrlRegAddr & ((xbar_reg_t)XBAR_CTRL_STAT_MASK)));
    }
#else
    uint8_t shiftInReg;

    status = XBAR_GetCtrlRegAndShift(output, &ctrlRegAddr, &shiftInReg);

    if (status == kStatus_Success)
    {
        *flag = (0U != (*ctrlRegAddr & ((xbar_reg_t)XBAR_CTRL_STAT_MASK << shiftInReg)));
    }
#endif

    return status;
}

/*!
 * brief Configures the XBAR control register.
 *
 * This function configures an XBAR control register. The active edge detection
 * and the DMA/IRQ function on the corresponding XBAR output can be set.
 *
 * Example:
   code
   xbar_control_config_t userConfig;
   userConfig.activeEdge = kXBAR_EdgeRising;
   userConfig.requestType = kXBAR_RequestInterruptEnable;
   XBAR_SetOutputSignalConfig(kXBAR_DSC1_OutputTriggerSyncIn0, &userConfig);
   endcode
 *
 * param output XBAR output signal.
 * param controlConfig Pointer to structure that keeps configuration of control register.
 * retval kStatus_Success Signal connection set successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t XBAR_SetOutputSignalConfig(xbar_output_signal_t output, const xbar_control_config_t *controlConfig)
{
    status_t status;
    volatile xbar_reg_t *ctrlRegAddr;
#if defined(FSL_FEATURE_XBAR_DSC_REG_WIDTH) && (FSL_FEATURE_XBAR_DSC_REG_WIDTH == 32)
    status = XBAR_GetCtrlReg(output, &ctrlRegAddr);

    if (status == kStatus_Success)
    {
        *ctrlRegAddr |= ((((xbar_reg_t)controlConfig->activeEdge)) << 2) |
                        (((xbar_reg_t)controlConfig->requestType));
    }
#else
    uint8_t shiftInReg;

    status = XBAR_GetCtrlRegAndShift(output, &ctrlRegAddr, &shiftInReg);

    if (status == kStatus_Success)
    {
        *ctrlRegAddr |= ((((xbar_reg_t)controlConfig->activeEdge) << shiftInReg) << 2) |
                        (((xbar_reg_t)controlConfig->requestType) << shiftInReg);
    }
#endif

    return status;
}
