/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_OPAMP_H_
#define FSL_OPAMP_H_

#include "fsl_common.h"

/*!
 * @defgroup opamp OPAMP: Operational Amplifier Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief OPAMP driver version. */
#define FSL_OPAMP_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup opamp_driver_log The Driver Change Log
 * @ingroup opamp
 * @{
 * The current OPAMP driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed MISRA C-2012 violations.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introducation of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup opamp_intro OPAMP Peripheral and Driver Overview
 * @ingroup opamp
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method.
 * @{
 *
 * Peripheral features and how this peripheral works
 * ==================================================
 *  The Operational Amplifier (OPAMP) module supports flexible amplifier
 *  application.
 *
 *  Features
 *  ---------
 *  + Up to four sets of rotation configuration.
 *    - OPAMP supports rotation configuration mechanism configured by software
 *      depending on the application requirements.
 *    - By the optimized design scheme of time-sharing multiplexing, the rotation
 *      configuration sets take effect one by one. After a rotation loop, it restarts
 *      from the first configuration set.
 *    - How many configuration sets are involved in rotation is configurable.
 *    - Time window is used to control each configuration set duration. The 4-bit window
 *      counter's clock is from XBAR. Window duration for each configuration set
 *      could be different.
 *
 *  + Selectable non-inverting input and inverting input.
 *    Both the non inverting input and inverting input have 4-to-1 multiplex,
 *    the multiplex can select analog input signals from either pins or
 *    internal references. Each rotation configuration set has its own multiplex
 *    value to support flexible use case.
 *
 *  + Configurable work mode.
 *    Each rotation configuration set uses its own work mode, OPAMP supports three work modes:
 *    - Buffer mode: In this mode, OPAMP operates as a buffer and gain is 1X.
 *    - Internal gain mode: Based on internal resistance net, this mode supports
 *      non-inverting 2X/4X/8X/16X gain.
 *    - External gain mode: In this mode, amplifier negative input switches to
 *      external resistance net. Flexible gain could be achieved by different
 *      external resistance net.
 *
 *  + Double buffer scheme.
 *    To avoid current working configuration data changing during rotation configuration,
 *    OPAMP uses double-buffer scheme. New configurations are written to OPAMP register
 *    buffers, when all configurations are written, application can write CTRL[CONFIG_LOAD]
 *    to enable load new configuration.
 *    - OPAMP supports two load modes to load new configuration at different time points.
 *      1. Delay load mode, also named as loop load mode. The new configuration loading
 *         happens on a rotation loop completion.
 *      2. Real time load mode, also named as fast load mode. The new configuration loading
 *         happens on any configuration set completion.
 *    - There is status flag and interrupt to notify user that the new configuration has
 *      been loaded.
 *
 *  + Different power modes.
 *    OPAMP supports high speed mode and low power mode.
 *    - High speed mode means higher current consumption with faster slew rate,
 *       and wider unity gain bandwidth performance.
 *    - Low power mode means lower current consumption with slower slew rate,
 *       and narrower unity gain bandwidth performance.
 *
 *  How this peripheral works
 *  -------------------------
 *  1. Configure the module clock to equal or less than 50MHz.
 *  2. Configure XBAR for the 4-bit window counter clock. When the counter clock is
 *     synchronized with the module clock, the frequency of the counter clock must be
 *     less than or equal to module clock frequency. When the counter clock is
 *     asynchronous with the module clock, the frequency of the counter clock must be
 *     less than half of module clock frequency.
 *  3. Configure OPAMP output pin and input pin according to use case.
 *  4. Set the rotation configuration sets, the configuration sets to use, power mode,
 *     load mode, and so on.
 *  5. Enable the configuration load, then OPAMP starts to work.
 *  6. After the configuration has been loaded, user could set new configuration and
 *     enable the load if necessary.
 *
 * How this driver is designed to make this peripheral works
 * ===========================================================
 *  With @ref OPAMP_Init, the OPAMP module could be set to a defined state and
 *  starts to work.
 *
 *  For runtime change, OPAMP driver provides two methods to configure the OPAMP module:
 *  1. Whole module configuration update by @ref OPAMP_UpdateModuleConfig. This function
 *     sets all configurations and enables the configuration load, the new configuration
 *     is loaded at the time determined by load mode.
 *  2. Update specific rotation configuration sets by @ref OPAMP_SetOneConfigSet.
 *     Application could call this function multiple times to configure different sets.
 *     After all desired sets configured, call @ref OPAMP_EnableConfigLoad to load
 *     at proper time.
 *
 *  OPAMP driver also provides APIs to get and clear configuration load completion flags.
 *
 *  How to use this driver
 *  =======================
 *  + Configure and enable module clock before calling this driver's API.
 *  + Configure XBAR for the window counter clock.
 *  + Enable OPAMP interrupt in system interrupt controller if necessary.
 *  + Configure the output pin and input pin according to use case.
 *  + Prepare the configuration structure @ref opamp_config_t, and call the function
 *    @ref OPAMP_Init. Then the OPAMP starts working. The function @ref OPAMP_GetDefaultConfig
 *    helps filling @ref opamp_config_t with default value, user can modify
 *    based on the default value.
 *  + Use @ref OPAMP_GetLoadCompletionFlag to get the configuration load completion status.
 *  + When the older configuration loaded, user could set new configuration using
 *    function @ref OPAMP_UpdateModuleConfig or @ref OPAMP_SetOneConfigSet.
 *
 *  @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Load mode definition.
 */
typedef enum _opamp_load_mode
{
    kOPAMP_LoadModeDelayLoad = 0U,    /*!< Or named loop load mode. Loading happens
                                           on every loop configuration completion. */
    kOPAMP_LoadModeRealTimeLoad = 1U, /*!< Or named fast load mode. Loading happens
                                           on any configuration completion. */
} opamp_load_mode_t;

/*!
 * @brief Power mode definition.
 */
typedef enum _opamp_power_mode
{
    kOPAMP_PowerModeLowPower = 0U,  /*!< Lower current consumption with slower slew rate
                                         and narrower unity gain bandwidth performance. */
    kOPAMP_PowerModeHighSpeed = 1U, /*!< Higher current consumption with higher slew rate
                                         and wider unity gain bandwidth performance. */
} opamp_power_mode_t;

/*!
 * @brief Rotation number definition.
 */
typedef enum _opamp_rotate_number
{
    kOPAMP_RotateConfigSet0 = 0U, /*!< Only configuration set 0 participates in the rotation configuration mechanism */
    kOPAMP_RotateConfigSet0_1,    /*!< Configuration sets 0 and 1 participate in the rotation configuration mechanism */
    kOPAMP_RotateConfigSet0_2,    /*!< Configuration sets 0 to 2 participate in the rotation configuration mechanism */
    kOPAMP_RotateConfigSet0_3,    /*!< Configuration sets 0 to 3 participate in the rotation configuration mechanism */
} opamp_rotate_number_t;

/*!
 * @brief OPAMP work mode.
 */
typedef enum _opamp_work_mode
{
    kOPAMP_WorkModeBufferMode = 0U, /*!< Buffer mode. */
    kOPAMP_WorkModeInternalGain2X =
        OPAMP_OPAMP_CONFIG_SET0_GAIN_EN_MASK | OPAMP_OPAMP_CONFIG_SET0_GAIN_EN(0), /*!< Internal gain 2X mode. */
    kOPAMP_WorkModeInternalGain4X =
        OPAMP_OPAMP_CONFIG_SET0_GAIN_EN_MASK | OPAMP_OPAMP_CONFIG_SET0_GAIN_EN(1), /*!< Internal gain 4X mode. */
    kOPAMP_WorkModeInternalGain8X =
        OPAMP_OPAMP_CONFIG_SET0_GAIN_EN_MASK | OPAMP_OPAMP_CONFIG_SET0_GAIN_EN(2), /*!< Internal gain 8X mode. */
    kOPAMP_WorkModeInternalGain16X =
        OPAMP_OPAMP_CONFIG_SET0_GAIN_EN_MASK | OPAMP_OPAMP_CONFIG_SET0_GAIN_EN(3), /*!< Internal gain 16X mode. */
    kOPAMP_WorkModeExternalGain = OPAMP_OPAMP_CONFIG_SET0_VNEG_EN_MASK,            /*!< External gain mode. */
} opamp_work_mode_t;

/*!
 * @brief VNEG input selection
 */
typedef enum _opamp_vneg
{
    kOPAMP_VNEG0 = 0U, /*!< Select VNEG0 */
    kOPAMP_VNEG1 = 1U, /*!< Select VNEG1 */
    kOPAMP_VNEG2 = 2U, /*!< Select VNEG2 */
    kOPAMP_VNEG3 = 3U, /*!< Select VNEG3 */
} opamp_vneg_t;

/*!
 * @brief VPOS input selection
 */
typedef enum _opamp_vpos
{
    kOPAMP_VPOS0 = 0U, /*!< Select VPOS0 */
    kOPAMP_VPOS1 = 1U, /*!< Select VPOS1 */
    kOPAMP_VPOS2 = 2U, /*!< Select VPOS2 */
    kOPAMP_VPOS3 = 3U, /*!< Select VPOS3 */
} opamp_vpos_t;

/*!
 * @brief Configuration set index.
 */
typedef enum _opamp_config_set_index
{
    kOPAMP_ConfigSet0 = 0U, /*!< Configuration set 0. */
    kOPAMP_ConfigSet1,      /*!< Configuration set 1. */
    kOPAMP_ConfigSet2,      /*!< Configuration set 2. */
    kOPAMP_ConfigSet3,      /*!< Configuration set 3. */
} opamp_config_set_index_t;

/*!
 * @brief Configuration set information.
 */
typedef struct _opamp_config_set
{
    opamp_work_mode_t eWorkMode;       /*!< Work mode. */
    opamp_vneg_t eVNEG;                /*!< VNEG pin selection, not used in buffer mode. */
    opamp_vpos_t eVPOS;                /*!< VPOS pin selection. */
    uint8_t u8PreviousConfigSetWindow; /*!< How many clock counts the previous configuration set
                                             affects the amplifier, allowed region 0~15. */
} opamp_config_set_t;

/*!
 * @brief Configuration structure.
 */
typedef struct _opamp_config
{
    bool bEnableLoadCompletionInterrupt; /*!< Set @b true to enable load completion interrupt. */
    bool bEnableWriteProtection;         /*!< Set @b true to lock configuration registers. */
    opamp_load_mode_t eLoadMode;         /*!< Configuration load mode. */
    opamp_power_mode_t ePowerMode;       /*!< Power mode. */
    opamp_rotate_number_t eRotateNumber; /*!< How many configuration sets are involved in rotation. */
    opamp_config_set_t sConfigSet0;      /*!< Rotation configuration set 0. */
    opamp_config_set_t sConfigSet1;      /*!< Rotation configuration set 1. */
    opamp_config_set_t sConfigSet2;      /*!< Rotation configuration set 2. */
    opamp_config_set_t sConfigSet3;      /*!< Rotation configuration set 3. */
} opamp_config_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization and configuration.
 * @{
 */

/*!
 * @brief Initializes the OPAMP module.
 *
 * This function enables the OPAMP IP bus clock (optional, controlled by
 * macro FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL), sets the configuration to
 * OPAMP and enables the load.
 *
 * @param base   OPAMP peripheral base address.
 * @param psConfig Pointer to configuration structure.
 */
void OPAMP_Init(OPAMP_Type *base, const opamp_config_t *psConfig);

/*!
 * @brief Get default configuration for OPAMP.
 *
 * The default value:
 * @code
    psConfig->bEnableLoadCompletionInterrupt = false;
    psConfig->bEnableWriteProtection = false;
    psConfig->eLoadMode = kOPAMP_LoadModeDelayLoad;
    psConfig->ePowerMode = kOPAMP_PowerModeLowPower;
    psConfig->eRotateNumber = kOPAMP_RotateConfigSet0;

    psConfig->sConfigSet0.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet0.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet0.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet0.u8PreviousConfigSetWindow = 15;

    psConfig->sConfigSet1.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet1.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet1.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet1.u8PreviousConfigSetWindow = 15;

    psConfig->sConfigSet2.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet2.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet2.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet2.u8PreviousConfigSetWindow = 15;

    psConfig->sConfigSet3.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet3.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet3.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet3.u8PreviousConfigSetWindow = 15;
   @endcode
 *
 * @param psConfig Pointer to configuration structure.
 */
void OPAMP_GetDefaultConfig(opamp_config_t *psConfig);

/*!
 * @brief De-initializes the OPAMP module.
 *
 * This function only disables the OPAMP IP bus clock (optional, controlled by
 * the macro FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL).
 *
 * @param base OPAMP peripheral base address.
 */
void OPAMP_Deinit(OPAMP_Type *base);

/*! @} */

/*!
 * @name Configuration
 * @{
 */

/*!
 * @brief Configure the OPAMP module and enable the configuration load.
 *
 * This function sets the new configuration, and enables the configuration load.
 * If previous old configuration has not been loaded, this function returns
 * @ref kStatus_Fail. Application could use @ref OPAMP_GetLoadCompletionFlag
 * to check whether the old configuration has been loaded.
 *
 * After calling this function, the new configuration will be loaed at the
 * time decided by ::opamp_config_t::eLoadMode.
 *
 * @param base OPAMP peripheral base address.
 * @param psConfig Pointer to the configuration.
 * @retval kStatus_Success The configuration is set.
 * @retval kStatus_Fail Could not set configuration because old configuration
 * has not been loaded.
 */
status_t OPAMP_UpdateModuleConfig(OPAMP_Type *base, const opamp_config_t *psConfig);

/*!
 * @brief Set the rotation configuration set.
 *
 * This function only sets the rotation configuration set, application should
 * call @ref OPAMP_EnableConfigLoad to enable the load after set all desired configuration sets.
 *
 * @param base OPAMP peripheral base address.
 * @param eIndex Index of configuration set.
 * @param psConfigSet Pointer to the configure structure.
 */
void OPAMP_SetOneConfigSet(OPAMP_Type *base, opamp_config_set_index_t eIndex, const opamp_config_set_t *psConfigSet);

/*!
 * @brief Enable the new configuration load.
 *
 * After configuration load enabled, the new set configuration will be loaded
 * at the time determined by load mode. Application could monitor the load completion
 * by @ref OPAMP_GetLoadCompletionFlag or the interrupt. When load finished,
 * the configuration load is disabled automatically.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_EnableConfigLoad(OPAMP_Type *base)
{
    base->OPAMP_CTR |= OPAMP_OPAMP_CTR_CONFIG_LOAD_MASK;
}

/*! @} */

/*!
 * @name Status and flags
 * @{
 */

/*!
 * @brief Get the configuration load completion flag status.
 *
 * @param base OPAMP peripheral base address.
 * @return Return true if the flag is set, otherwise return false.
 */
static inline bool OPAMP_GetLoadCompletionFlag(OPAMP_Type *base)
{
    return (0U != (base->OPAMP_STATUS & OPAMP_OPAMP_STATUS_LDCMF_MASK));
}

/*!
 * @brief Clear the configuration load completion flag.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_ClearLoadCompletionFlag(OPAMP_Type *base)
{
    base->OPAMP_STATUS = OPAMP_OPAMP_STATUS_LDCMF_MASK;
}

/*!
 * @brief Get current 4-bit window counter value.
 *
 * @param base OPAMP peripheral base address.
 * @return Current counter value.
 */
static inline uint8_t OPAMP_GetCurrentCounterValue(OPAMP_Type *base)
{
    return (uint8_t)(uint16_t)((base->OPAMP_STATUS & OPAMP_OPAMP_STATUS_WINDOW_CNT_MASK) >>
                               OPAMP_OPAMP_STATUS_WINDOW_CNT_SHIFT);
}

/*!
 * @brief Get current working rotation configuration set.
 *
 * @param base OPAMP peripheral base address.
 * @return Index of current working configuration set.
 */
static inline opamp_config_set_index_t OPAMP_GetCurrentConfigSet(OPAMP_Type *base)
{
    return (opamp_config_set_index_t)(uint16_t)((base->OPAMP_STATUS & OPAMP_OPAMP_STATUS_CURRENT_CONFIG_SET_MASK) >>
                                                OPAMP_OPAMP_STATUS_CURRENT_CONFIG_SET_SHIFT);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* FSL_OPAMP_H_ */
