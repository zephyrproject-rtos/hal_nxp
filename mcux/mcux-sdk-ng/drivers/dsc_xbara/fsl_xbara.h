/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_XBARA_H_
#define FSL_XBARA_H_

#include "fsl_common.h"

/*!
 * @defgroup xbar XBAR: Inter-Peripheral Crossbar Switch Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief XBAR driver version. */
#define FSL_XBAR_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup xbar_driver_log The Driver Change Log
 * @ingroup xbar
 * @{
 * The current XBAR driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*!
 * @defgroup xbar_intro XBAR Peripheral and Driver Overview
 * @ingroup xbar
 * @brief Content including 1) features; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Features
 * =======================================
 * Inter Peripheral Crossbar-Switch
 *
 * This module implements an array of M N-input combinational muxes. All muxes share
 * the same N inputs in the same order, but each mux has its own independent select field.
 * The intended application of this module is to provide a flexible crossbar switch function
 * that allows any input (typically from external GPIO or internal module outputs) to be
 * connected to any output (typically to external GPIO or internal module inputs) under user
 * control. This is used to allow user configuration of data paths between internal modules
 * and between internal modules and GPIO.
 *
 * A subset of the muxes can be configured to support edge detection and either interrupt or
 * DMA request generation based on detected signal edges on the mux output. This allows
 * signal transitions on the signals feeding the crossbar to trigger interrupts or initiate data
 * transfers via DMA into or out of other system modules.
 *
 * How this driver is designed
 * =======================================
 * This driver is designed around the basic configuration unit of XBAR output which get input signal,
 * edge detection mode and interrupt/dma generation configuration.
 *
 * xbar output signal is defined in SOC header file with enumeration name as
 * xbar_output_signal_t. This enumeration list all available signals with its meaning provided in
 * enumerator. Note that not all XBAR output is able to generate interrupt/DMA according to edge detected
 * in input signal, only xbar_output_signal_t enumerator equal or smaller than
 * kXBAR_OuputMaxInterruptDMASignal can be configurated with edge detection and interrupt/dma request
 * generation.
 *
 * Available xbar input singal is also proivde in SOC header file with enumeration name
 * as xbar_input_signal_t.
 *
 * There are a series of MACRO functions starting with XBAR_ provided but it is not necessary to understand
 * these macro function on using this driver. These macro functions are provided to find the register fields
 * to operate with a given xbar output xbar_output_signal_t.
 *
 * This driver provide several function group to do with the configuration of output channel.
 * + Initialization and Deinitialization groups
 *  - This group initialize / deinitialize the XBAR module not relevant to specific output signal.
 *  - This gorup init a xbar output with all supported configuration.
 *
 * + Output configuration Interface
 *  - This group provide configuration API to do functionality configuration for one XBAR output.
 *
 * + Status Get/Clear Interface
 *  - This group Get/Clear status flags. This peripheral get only one type of status flag.
 *
 * How to use this driver
 * =======================================
 * + Action needed outside driver
 *
 * + Initialize XBAR module calling XBAR_Init(), Note that this only need be called once.
 * + Configure the signal connection by calling XBAR_SetSignalConnection.
 * + [Optional] Configure the edge detection mode @ref xbara_active_edge_t and configure the interrupt/dma
 * request generation when edge detected.
 *
 * Typical use case
 * =======================================
 * NA
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Macro function to extract the XBAR select register address for a given xbar output signal. */
#define XBARA_SELx(base, output) (((volatile uint16_t *)(&((base)->SEL0)))[(uint8_t)(output) >> 0x01U])

/*! @brief Macro function to extract the XBAR Ctrl register address for a given xbar output signal. */
#define XBARA_CTRLx(base, output) (((volatile uint16_t *)(&((base)->CTRL0)))[(uint8_t)(output) >> 0x01U])

/*! @brief Macro function to get SELn field shift in XBARA_SELx register for a given output signal. */
#define XBARA_SELx_SELn_SHIFT(output) ((((uint8_t)(output)&0x01U) != 0U) ? 8U : 0U)

/*! @brief Macro function to get SELn field mask in XBARA_SELx register for a given output signal. */
#define XBARA_SELx_SELn_MASK(output) ((((uint8_t)(output)&0x01U) != 0U) ? 0x3F00U : 0x003FU)

/*! @brief Macro function to create SELn field value in XBARA_SELx register for given output signal
 *         and input signal value input_signal, see xbar_input_signal_t. */
#define XBARA_SELx_SELn(output, input_signal) \
    (((uint16_t)(((uint16_t)(input_signal)) << XBARA_SELx_SELn_SHIFT(output))) & XBARA_SELx_SELn_MASK(output))

/*! @brief Macro function to get DIENn field mask in XBARA_CTRLx register for a given output signal. */
#define XBARA_CTRLx_DIENn_MASK(output) ((((uint8_t)(output)&0x01U) != 0U) ? 0x0300U : 0x0003U)

/*! @brief Macro function to get DIENn field shift in XBARA_CTRLx register for a given output signal. */
#define XBARA_CTRLx_DIENn_SHIFT(output) ((((uint8_t)(output)&0x01U) != 0U) ? 8U : 0U)

/*! @brief Macro function to create DIENn field value in XBARA_CTRLx register for given output signal
 * and DMA/Interrupt mode x, see @ref xbara_request_t. */
#define XBARA_CTRLx_DIENn(output, x) \
    (((uint16_t)(((uint16_t)(x)) << XBARA_CTRLx_DIENn_SHIFT(output))) & XBARA_CTRLx_DIENn_MASK(output))

/*! @brief Macro function to get EDGEn field mask in XBARA_CTRLx register for a given output signal. */
#define XBARA_CTRLx_EDGEn_MASK(output) ((((uint8_t)(output)&0x01U) != 0U) ? 0x0C00U : 0x000CU)

/*! @brief Macro function to get EDGEn field shift in XBARA_CTRLx register for a given output signal. */
#define XBARA_CTRLx_EDGEn_SHIFT(output) ((((uint8_t)(output)&0x01U) != 0U) ? 10U : 2U)

/*! @brief Macro function to create EDGEn field value in XBARA_CTRLx register for given output signal
 *         and edge mode x, see @ref xbara_active_edge_t. */
#define XBARA_CTRLx_EDGEn(output, x) \
    (((uint16_t)(((uint16_t)(x)) << XBARA_CTRLx_EDGEn_SHIFT(output))) & XBARA_CTRLx_EDGEn_MASK(output))

/*! @brief Macro value for the Status bits in CTRL register. */
#define XBARA_CTRLx_STS_MASK (0x1010U)

/*!
 * @brief XBARA active edge for detection
 */
typedef enum _xbara_active_edge
{
    kXBARA_EdgeNone             = 0U, /*!< Edge detection status bit never asserts. */
    kXBARA_EdgeRising           = 1U, /*!< Edge detection status bit asserts on rising edges. */
    kXBARA_EdgeFalling          = 2U, /*!< Edge detection status bit asserts on falling edges. */
    kXBARA_EdgeRisingAndFalling = 3U  /*!< Edge detection status bit asserts on rising and falling edges. */
} xbara_active_edge_t;

/*!
 * @brief XBARA DMA and interrupt configurations. Note it only apply for a subset of XBARA output signal.
 */
typedef enum _xbara_request
{
    kXBARA_RequestDisable         = 0U, /*!< Interrupt and DMA are disabled. */
    kXBARA_RequestDMAEnable       = 1U, /*!< DMA enabled, interrupt disabled. */
    kXBARA_RequestInterruptEnable = 2U  /*!< Interrupt enabled, DMA disabled. */
} xbara_request_t;

/*!
 * @brief XBARA status flags.
 *
 * This provides constants for the XBARA status flags for use in the XBARA functions.
 * The enumerator value is designed to make sure Flags in same register can be created
 * with register value to write/read register.
 */
typedef enum _xbara_status_flag
{
    kXBARA_EdgeDetectionOut0Flag =
        (1U << 0U), /*!< XBAR_OUT0 active edge interrupt flag, sets when active edge detected. */
    kXBARA_EdgeDetectionOut1Flag =
        (1U << 8U), /*!< XBAR_OUT1 active edge interrupt flag, sets when active edge detected. */
    kXBARA_EdgeDetectionOut2Flag =
        (1U << 1U), /*!< XBAR_OUT2 active edge interrupt flag, sets when active edge detected. */
    kXBARA_EdgeDetectionOut3Flag =
        (1U << 9U), /*!< XBAR_OUT3 active edge interrupt flag, sets when active edge detected. */
    kXBARA_AllStatusFlags = kXBARA_EdgeDetectionOut0Flag | kXBARA_EdgeDetectionOut1Flag | kXBARA_EdgeDetectionOut2Flag |
                            kXBARA_EdgeDetectionOut3Flag /*! All status falgs. */
} xbara_status_flag_t;

/*!
 * @brief Defines the configuration structure of the XBARA control register.
 *
 * This structure keeps the configuration of XBARA control register for one output.
 * Control registers are available only for a few outputs. Not every XBARA module has
 * control registers.
 */
typedef struct _xbara_control_config
{
    xbara_active_edge_t eActiveEdge; /*!< Active edge to be detected. */
    xbara_request_t eRequestType;    /*!< Selects DMA/Interrupt request. */
} xbara_control_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Initialization and Deinitialization Interfaces
 * @{
 */
/*!
 * @brief Initializes the XBARA module.
 *
 * This function un-gates the XBARA clock.
 *
 * @param base XBARA peripheral address.
 */
void XBARA_Init(XBARA_Type *base);

/*!
 * @brief Shuts down the XBARA module.
 *
 * This function disables XBARA clock.
 *
 * @param base XBARA peripheral address.
 */
void XBARA_Deinit(XBARA_Type *base);

/*! @}*/
/*!
 * @name XBARA output signal configuration Interfaces
 * @{
 */

/*!
 * @brief Sets a connection between the selected XBARA_IN[*] input and the XBARA_OUT[*] output signal.
 *
 * This function connects the XBARA input to the selected XBARA output.
 * If more than one XBARA module is available, only the inputs and outputs from the same module
 * can be connected.
 *
 * Example:
   @code
   XBARA_SetSignalsConnection(XBARA, kXBARA_InputPIT_TRG0, kXBARA_OutputDMAMUX18);
   @endcode
 *
 * @param base XBARA peripheral address.
 * @param eInput XBARA input signal.
 * @param eOutput XBARA output signal.
 */
static inline void XBARA_SetSignalsConnection(XBARA_Type *base,
                                              xbar_input_signal_t eInput,
                                              xbar_output_signal_t eOutput)
{
    XBARA_SELx(base, eOutput) =
        XBARA_SELx(base, eOutput) & ~(XBARA_SELx_SELn_MASK(eOutput)) | XBARA_SELx_SELn(eOutput, eInput);
}

/*!
 * @brief Sets active edge detection mode for the XBARA_OUT[*] output signal.
 *
 * @param base XBARA peripheral address.
 * @param eOutput XBARA output signal.
 * @param eActiveEdgeMode Active edge mode.
 */
static inline void XBARA_SetActiveEdgeDetectMode(XBARA_Type *base,
                                                 xbar_output_signal_t eOutput,
                                                 xbara_active_edge_t eActiveEdgeMode)
{
    XBARA_CTRLx(base, eOutput) =
        XBARA_CTRLx(base, eOutput) & ~(XBARA_CTRLx_EDGEn_MASK(eOutput)) | XBARA_CTRLx_EDGEn(eOutput, eActiveEdgeMode);
}

/*!
 * @brief Sets DMA, Interrupt or disabled request generation mode for the XBARA_OUT[*] output signal.
 *
 * @param base XBARA peripheral address.
 * @param eOutput XBARA output signal.
 * @param eRequest Request type.
 */
static inline void XBARA_SetInterruptDMARequestMode(XBARA_Type *base,
                                                    xbar_output_signal_t eOutput,
                                                    xbara_request_t eRequest)
{
    assert((uint8_t)eOutput < (uint8_t)FSL_FEATURE_XBARA_INTERRUPT_COUNT);
    XBARA_CTRLx(base, eOutput) =
        XBARA_CTRLx(base, eOutput) & ~(XBARA_CTRLx_DIENn_MASK(eOutput)) | XBARA_CTRLx_DIENn(eOutput, eRequest);
}

/*!
 * @brief Configures the XBARA output signal edge detection and interrupt/dma featues
 *
 * This function configures an XBARA control register. The active edge detection
 * and the DMA/IRQ function on the corresponding XBARA output can be set.
 *
 * @note Only a subset of the XBARA output signal can be called with this API. On debug mode
 * code will check whether the output signal eOutput satisfy the requirement.
 *
 * Example:
   @code
   xbara_control_config_t userConfig;
   userConfig.activeEdge = kXBARA_EdgeRising;
   userConfig.requestType = kXBARA_RequestInterruptEnable;
   XBARA_SetOutputSignalConfig(XBARA, kXBARA_OutputDMAMUX18, &userConfig);
   @endcode
 *
 * @param base XBARA peripheral address.
 * @param eOutput XBARA output number.
 * @param psControlConfig Pointer to structure that keeps configuration of control register.
 */
void XBARA_SetOutputSignalConfig(XBARA_Type *base,
                                 xbar_output_signal_t eOutput,
                                 const xbara_control_config_t *psControlConfig);
/*! @}*/

/*!
 * @name Status Get/Clear Interfaces
 * @{
 */

/*!
 * @brief Gets the active edge detection status for all XBAR output signal supporting this feature.
 *
 * This function gets the active edge detect status of all XBARA_OUTs. If the
 * active edge occurs, the return value is asserted. When the interrupt or the DMA
 * functionality is enabled for the XBARA_OUTx, this field is 1 when the interrupt
 * or DMA request is asserted and 0 when the interrupt or DMA request has been
 * cleared.
 *
 * @param base      XBARA peripheral address.
 * @return ORed value from all status flag from @ref xbara_status_flag_t.
 */
uint16_t XBARA_GetStatusFlags(XBARA_Type *base);
/*!
 * @brief Clear the edge detection status flags of relative mask.
 *
 * @param base      XBARA peripheral address.
 * @param u16Flags  status flags composed from ORed @ref xbara_status_flag_t indicating
 *                  flags to be cleared.
 */
static inline void XBARA_ClearStatusFlags(XBARA_Type *base, uint16_t u16Flags)
{
    uint16_t mask;

    /* Clear the status flags in CTRL0 if applicable */
    mask = (u16Flags << 4U) & XBARA_CTRLx_STS_MASK;
    if (mask != 0U)
    {
        base->CTRL0 = (base->CTRL0 & (~XBARA_CTRLx_STS_MASK)) | mask;
    }
    else
    {
        /* MISRA Compiliance*/
    }

    /* Clear the status flags in CTRL1 if applicable */
    mask = (u16Flags << 3U) & XBARA_CTRLx_STS_MASK;
    if (mask != 0U)
    {
        base->CTRL1 = (base->CTRL1 & (~XBARA_CTRLx_STS_MASK)) | mask;
    }
    else
    {
        /* MISRA Compiliance*/
    }
}

/*! @}*/

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*!* @} */

#endif /* FSL_XBARA_H_ */
