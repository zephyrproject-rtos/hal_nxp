/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_xbarb.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_xbarb"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Initializes an XBARB instance for operation.
 *
 * This function is to make the initialization for using XBARB module.
 *
 * Reserved function, enable clock preparation.
 *
 * param base XBARB peripheral address.
 */
void XBARB_Init(XBARB_Type *base)
{
}

/*!
 *@brief De-initializes an XBARB instance for operation.
 *
 * This function shutdowns XBARB module.
 *
 * Reserved function, disable clock preparation.
 *
 * param  base XBARB peripheral address.
 */
void XBARB_Deinit(XBARB_Type *base)
{
}

/*!
 * @brief Sets a connection between the selected XBARB_IN[*] input and the XBARB_OUT[*] output signal.
 *
 * This function connects the XBARB input to the selected XBARB output.
 * If more than one XBARB module is available, only the inputs and outputs from the same module
 * can be connected.
 *
 * Example:
   code

   XBARB_SetSignalsConnection(XBARB, kXBARB_InputPIT_TRG0, kXBARB_OutputDMAMUX18);

   endcode
 *
 * @param base XBARB peripheral address.
 * @param eInput XBARB input signal.
 * @param eOutput XBARB output signal.
 */
void XBARB_SetSignalsConnection(XBARB_Type *base, xbar_input_signal_t eInput, xbar_output_signal_t eOutput)
{
    XBARB_SELx(base, eOutput) =
        XBARB_SELx(base, eOutput) & ~(XBARB_SELx_SELn_MASK(eOutput)) | XBARB_SELx_SELn(eOutput, eInput);
}
