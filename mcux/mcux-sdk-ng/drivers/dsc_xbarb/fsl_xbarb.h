/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_XBARB_H_
#define FSL_XBARB_H_

#include "fsl_common.h"

/*!
 * @defgroup xbarb XBARB: Inter-Peripheral Crossbar Switch Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief XBARB driver version. */
#define FSL_XBARB_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup xbarb_driver_log The Driver Change Log
 * @ingroup XBARB
 * @{
 * The current XBARB driver version is 2.0.0.
 *
 *  - 2.0.0
 *    - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup xbarb_intro XBARB Peripheral and Driver Overview
 * @ingroup xbarb
 * @brief Content including 1) features; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Features
 * =======================================
 * Inter Peripheral Crossbar-Switch
 *
 * This XBAR module has only select registers.
 *
 * In the XBAR select registers, the SELn fields select which of the shared inputs
 * (XBAR_IN[*]) is muxed to each mux output (XBAR_OUT[*]). There is one SELn field
 * per mux and therefore one per XBAR_OUT output. Crossbar output XBAR_OUT[n]
 * presents the value of XBAR_IN[SELn]. Each select register contains two SELn fields. In
 * the first select register, the LSBs contain the select field for mux 0, and the MSBs contain
 * the select field for mux 1. The pattern repeats in subsequent select registers.
 * The actual signals connected to XBAR_IN and XBAR_OUT are application specific and
 * are described in the Chip Configuration details.
 *
 * How this driver is designed
 * =======================================
 * The driver is designed around the basic configuration unit of XBARB output and input,
 * and is used to obtain specific application functions connected to AOI.
 *
 * A series of MACRO functions starting with XBAR_ are provided, but there is no need to understand
 * These macro functions when using this driver. Provide these macro functions to find register fields
 * Use the given XBARB output xbar_output_signal_t to operate.
 * Use the given XBARB input xbar_input_signal_t to operate.
 *
 * This driver provide several function group to do with the configuration of output channel.
 * + Initialization and Deinitialization groups
 *  - This group initialize / deinitialize the XBARB module not relevant to specific output signal.
 *
 * + Output configuration Interface
 *  - This group provide configuration API to do functionality configuration for one XBARB output.
 *
 * + Input configuration Interface
 *  - This group provide configuration API to do functionality configuration for one XBARB Input.
 *
 *
 * How to use this driver
 * =======================================
 * + Action needed outside driver
 *
 * + Initialize XBARB module calling XBARB_Init(), Note that this only need be called once.
 * + Configure the signal connection by calling XBAR_SetSignalConnection.
 *
 *
 * Typical use case
 * =======================================
 * N/A
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Macro function to extract the XBAR select register address for a given xbar output signal.
 */
#define XBARB_SELx(base, output) (((volatile uint16_t *)(&((base)->SEL0)))[(uint8_t)(output) >> 0x01U])

/*!
 * @brief Macro function to get SELn field shift in XBARB_SELx register for a given output signal.
 */
#define XBARB_SELx_SELn_SHIFT(output) ((output & 0x01U) ? 8U : 0U)

/*!
 * @brief Macro function to get SELn field mask in XBARB_SELx register for a given output signal.
 */
#define XBARB_SELx_SELn_MASK(output) ((output & 0x01U) ? 0x3F00U : 0x3FU)

/*!
 * @brief Macro function to create SELn field value in XBARB_SELx register for given output signal
 * and input signal value input_signal, see xbar_input_signal_t.
 */
#define XBARB_SELx_SELn(output, input_signal) \
    (((uint16_t)(((uint16_t)(input_signal)) << XBARB_SELx_SELn_SHIFT(output))) & XBARB_SELx_SELn_MASK(output))

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name XBARB functional Operation.
 * @{
 */

/*!
 * @brief Initializes an XBARB instance for operation.
 *
 * Reserved function, enable clock preparation.
 *
 * @param base XBARB peripheral address.
 */
void XBARB_Init(XBARB_Type *base);

/*!
 * @brief Deinitializes an XBARB instance for operation.
 *
 * Reserved function, disable clock preparation.
 *
 * @param  base XBARB peripheral address.
 */
void XBARB_Deinit(XBARB_Type *base);

/*! @}*/
/*!
 * @name XBARB output signal configuration Interfaces
 * @{
 */
/*!
 * brief Configures a connection between the selected XBARB_IN[*] input and the XBARB_OUT[*] output signal.
 *
 * This function configures which XBARB input is connected to the selected XBARB output.
 * If more than one XBARB module is available, only the inputs and outputs from the same module
 * can be connected.
 *
 * param base XBARB peripheral address.
 * param eInput XBARB input signal.
 * param eOutput XBARB output signal.
 */
void XBARB_SetSignalsConnection(XBARB_Type *base, xbar_input_signal_t eInput, xbar_output_signal_t eOutput);

/*! @}*/
#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*!* @} */

#endif /* FSL_XBARB_H_ */
