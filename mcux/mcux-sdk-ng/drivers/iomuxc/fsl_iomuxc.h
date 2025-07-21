/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_IOMUXC_H_
#define FSL_IOMUXC_H_

#include "fsl_common.h"

/*!
 * @addtogroup iomuxc_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*!< Version 2.0.0. */
#define FSL_IOMUXC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief Internal resistor pull feature selection */
enum _iomuxc_pull
{
    kIOMUXC_PullDisable = 0U, /*!< Internal pull-up/down resistor is disabled. */
    kIOMUXC_PullDown    = 2U, /*!< Internal pull-down resistor is enabled. */
    kIOMUXC_PullUp      = 3U, /*!< Internal pull-up resistor is enabled. */
};

/*! @brief Slew rate selection */
enum _iomuxc_slew_rate
{
    kIOMUXC_StandardSlewRate = 0U, /*!< Standard slew rate is configured. */
    kIOMUXC_SlowSlewRate     = 1U, /*!< Slow slew rate is configured. */
};

/*! @brief Internal resistor pull feature enable/disable */
enum _iomuxc_open_drain_enable
{
    kIOMUXC_OpenDrainDisable = 0U, /*!< Internal pull-down resistor is disabled. */
    kIOMUXC_OpenDrainEnable  = 1U, /*!< Internal pull-up resistor is enabled. */
};

/*! @brief Configures the drive strength. */
enum _iomuxc_drive_strength
{
    kIOMUXC_StandardDriveStrength = 0U, /*!< Standard-drive strength is configured. */
    kIOMUXC_HighDriveStrength     = 1U, /*!< High-drive strength is configured. */
};

/*! @brief Pin mux selection */
enum _iomuxc_mux
{
    kIOMUXC_MuxAlt0  = 0U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt1  = 1U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt2  = 2U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt3  = 3U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt4  = 4U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt5  = 5U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt6  = 6U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt7  = 7U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt8  = 8U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt9  = 9U,  /*!< Chip-specific */
    kIOMUXC_MuxAlt10 = 10U, /*!< Chip-specific */
    kIOMUXC_MuxAlt11 = 11U, /*!< Chip-specific */
    kIOMUXC_MuxAlt12 = 12U, /*!< Chip-specific */
    kIOMUXC_MuxAlt13 = 13U, /*!< Chip-specific */
    kIOMUXC_MuxAlt14 = 14U, /*!< Chip-specific */
    kIOMUXC_MuxAlt15 = 15U, /*!< Chip-specific */
};

/*! @brief Unlock/lock the pin control register field[15:0] */
enum _iomuxc_lock_register
{
    kIOMUXC_UnlockRegister = 0U, /*!< Pin Control Register fields [15:0] are not locked. */
    kIOMUXC_LockRegister   = 1U, /*!< Pin Control Register fields [15:0] are locked. */
};

/*! @brief Input buffer feature enable/disable */
enum _iomuxc_input_buffer_enable
{
    kIOMUXC_InputBufferDisable = 0U, /*!< Input buffer is disabled. */
    kIOMUXC_InputBufferEnable  = 1U, /*!< Output buffer is enabled. */
};

/*! @brief output buffer feature enable/disable */
enum _iomuxc_output_buffer_enable
{
    kIOMUXC_outputBufferDisable = 0U, /*!< Output buffer is disabled. */
    kIOMUXC_outputBufferEnable  = 1U, /*!< Output buffer is enabled. */
};

/*! @brief Digital filter clock selection */
typedef enum _iomuxc_digital_filter_clock_select
{
    kIOMUXC_IPGClock  = 0U, /*!< Digital filters are clocked by the IPG clock. */
    kIOMUXC_1KhzClock = 1U, /*!< Digital filters are clocked by the 1kHz clock. */
} iomux_digital_filter_clock_select_t;

/*!
 * @brief IOMUXC pin configuration structure
 * @note for i.MX7ULP, the SW_MUX_CTL_PAD of IOMUXC0 and IOMUXC1 is a little different
 * in the digital filter feature. The SW_MUX_CTL_PAD of IOMUXC1 has no digital filter
 * feature. For this case, just ignore the digital filter fields.
 */
typedef struct _iomuxc_pin_config
{
    uint32_t pullSelect : 2; /*!< No-pull/pull-down/pull-up select */
    uint32_t slewRate : 1;   /*!< Standard/slow slew rate Configure */
    uint32_t : 2;
    uint32_t openDrainEnable : 1; /*!< Open drain enable/disable */
    uint32_t driveStrength : 1;   /*!< Standard/slow drive strength configure */
    uint32_t : 1;
    uint32_t mux : 4; /*!< Pin mux Configure */
    uint32_t : 3;
    uint32_t lockRegister : 1;          /*!< Lock/unlock the PCR field[15:0] */
    uint32_t inputBufferEnable : 1;     /*!< Input buffer is enable/disable. */
    uint32_t outputBufferEnable : 1;    /*!< Output buffer is enable/disable. */
    uint32_t digitalFilterEnable : 1;   /*!< Digital filters are enable/disable. */
    uint32_t digitalFilterSelect : 1;   /*!< Set digital filter clockSource */
    uint32_t digitalFilterDuration : 5; /*!< Set digital filter duration */
    uint32_t : 5;
} iomux_pin_config_t;

/*!
 * @brief Input pin mux selection(DAISY).
 * Refer to "Input SSS" column from "Input Mux" IOMUX Sheet.
 */
enum _iomuxc_inputpin_mux
{
    kIOMUXC_InputMuxAlt0 = 0u, /*!< Chip-specific */
    kIOMUXC_InputMuxAlt1 = 1U, /*!< Chip-specific */
    kIOMUXC_InputMuxAlt2 = 2U, /*!< Chip-specific */
    kIOMUXC_InputMuxAlt3 = 3U, /*!< Chip-specific */
};

/*! @brief Input inversion feature enable/disable */
enum _iomuxc_input_inversion_enable
{
    kIOMUXC_InputInversionDisable = 0U, /*!< Input inversion is disabled. */
    kIOMUXC_InputInversionEnable  = 1U, /*!< Output inversion is enabled. */
};

/*! @brief IOMUXC pin configuration and mux for input function */
typedef struct _iomuxc_input_pin_config
{
    uint32_t daisy : 2; /*!< Selects source pad for Module Input Function. Refer to "Input SSS" column from "Input Mux"
IOMUX Sheet. */
    uint32_t : 13;
    uint32_t inversion : 1; /*!< Controls the inversion of the pad->module input to instance */
    uint32_t : 16;
} iomuxc_input_pin_config_t;

/*!@brief IOMUXC pin configuration reset value structure */
typedef struct _iomuxc_pin_reset_config
{
    uint32_t pullSelect : 2; /*!< No-pull/pull-down/pull-up select */
    uint32_t slewRate : 1;   /*!< Standard/slow slew rate Configure */
    uint32_t : 2;
    uint32_t openDrainEnable : 1; /*!< Open drain enable/disable */
    uint32_t driveStrength : 1;   /*!< Standard/slow drive strength configure */
    uint32_t : 8;
    uint32_t lockRegister : 1; /*!< Lock/unlock the PCR field[15:0] */
} iomux_pin_reset_config_t;

/*! @name Configuration */
/*! @{ */

/*!
 * @brief Sets the IOMUXC SW MUX Control Register.
 * @note Uses macro instead of inline function is to avoid the parameter type check,
 * because the IOMUXC0 and IOMUXC1 is differnt.
 *
 * @param instance  IOMUXC instance. It's pointer to IOMUXC0_Type or IOMUXC1_Type in the soc head file.
 * @param iomuxc_port  IOMUXC PORT name, please refer the enum iomuxc0_port_t and iomuxc1_port_t.
 * @param pin      pin number.
 * @param config   structure object of iomux_pin_config_t, not a pointer.
 */
#define IOMUXC_SET_MUX_CONTROL_PAD(instance, iomuxc_port, pin, config) \
    (instance)->SW_MUX_CTL_PAD[(iomuxc_port)*32U + (pin)] = *((const uint32_t *)(&config));

/*!
 * @brief Sets the IOMUXC input function pin configuration: the N_SELECT_INPUT_DAISY_Register.
 *
 * @param instance  IOMUXC instance. It's pointer to IOMUXC0_Type or IOMUXC1_Type in the soc head file.
 * @param index    register index, please refer the iomuxc0_select_input_t and iomuxc1_select_input_t.
 * @param config   structure object of iomuxc_input_pin_config_t, not a pointer.
 */
#define IOMUXC_SET_INPUTPIN_CONFIG(instance, index, config) \
    (instance)->SELECT_INPUT[index] = *((const uint32_t *)(&config));

/*!
 * @brief Sets the reset value for IOMUXC0 SW MUX Control Register.
 *
 * @param instance  IOMUXC instance. It's pointer to IOMUXC0_Type or IOMUXC1_Type in the soc head file.
 * @param config   structure object of iomux_pin_config_t, not a pointer.
 */
#define IOMUXC_SET_MUX_CONTROL_PAD_RESET(instance, config)                                    \
    if ((uint32_t)instance == IOMUXC0_BASE)                                                   \
    {                                                                                         \
        ((IOMUXC0_Type *)instance)->SW_MUX_CTL_PAD_RESET0_b = *((const uint32_t *)(&config)); \
    }                                                                                         \
    else                                                                                      \
    {                                                                                         \
        ((IOMUXC1_Type *)instance)->SW_MUX_CTL_PAD_RESET1_b = *((const uint32_t *)(&config)); \
    }

/*! @} */

/*! @} */

#endif /* FSL_IOMUXC_H_ */
