/*
 * Copyright 2022 NXP
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
#define FSL_OPAMP_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup opamp_driver_log The Driver Change Log
 * @ingroup opamp
 * @{
 * The current OPAMP driver version is 2.0.0.
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
 *  + Up to four sets of register configuration.
 *    - OPAMP supports four configuration registers(CFG0 to CFG3), only one of which validates all the time.
 *	  - OPAMP configuartion registers can be either software or other peripherals through inter-module
 *		connections.
 *
 *  + Selectable non-inverting input and inverting input.
 *    Both non-inverting and inverting input the 4-to-1 multiplex which can
 *    can select analog input signals from either pins or internal references.
 *
 *  + Configurable work mode.
 *    OPAMP supports three work modes:
 *    - Buffer mode: In this mode, OPAMP operates as a buffer and gain is 1X.
 *    - Internal gain mode: Based on internal resistance net, this mode supports
 *      non-inverting 2X/4X/8X/16X gain.
 *    - External gain mode: In this mode, amplifier negative input switches to
 *      external resistance net. Flexible gain could be achieved by different
 *      external resistance nets.
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
 *  1. Configure OPAMP output pin and input pin according to use case.
 *  2. Set the control register, the configuration sets to use, power mode,
 *     load mode, and so on.
 *  3. Set the configuartion register, the configuration sets to use, Gain Multiplier,
 *	   inverting and non-inverting input selection, and so on.
 *  4. Enable the configuration load.
 *  5. Enable OPAMP and start work.
 *
 * How this driver is designed to make this peripheral works
 * ===========================================================
 *  With @ref OPAMP_Init, the OPAMP module could be set to a defined state and
 *  starts to work.
 *
 *  OPAMP driver provides methods to configure the OPAMP module:
 *  1. Whole module configuration update by @ref OPAMP_Init. This function
 *     sets all configurations and enables the configuration load, the new configuration
 *     is loaded at the time determined by load mode.
 *
 *  OPAMP driver also provides APIs to get and clear configuration load completion flags.
 *
 *  How to use this driver
 *  =======================
 *  + Configure and enable module clock before calling this driver's API.
 *  + Options to configure OPAMP: software-controlled or peripherals-controlled.
 *  + Enable OPAMP interrupt in system interrupt controller if necessary.
 *  + Configure the output pin and input pin according to use case.
 *  + Prepare the configuration structure @ref opamp_config_t, and call the function
 *    @ref OPAMP_Init. Then the OPAMP starts working. The function @ref OPAMP_GetDefaultConfig
 *    helps filling @ref opamp_config_t with default value which user can modify.
 *
 *  Typical Use Case
 *  ================
 *  + OPAMP_basic peripherals control OPAMP
 *    1. Delayed load mode initialization.
 *    @code
 *   	opamp_config_t sConfig;
 *   	OPAMP_GetDefaultConfig(&sConfig);
 *      sConfig.eConfigRegSel           = kOPAMP_configRegSelB1OrB0;
 *      sConfig.sConfigSet0.eWorkMode   = kOPAMP_WorkModeInternalGain2X;
 *      sConfig.sConfigSet0.ePosChannel = kOPAMP_PosChannel0;
 *      OPAMP_Init(DEMO_OPAMP, &sConfig);
 *    @endcode
 *    2. Immediate load mode initialization.
 *    @code
 *   	opamp_config_t sConfig;
 *   	OPAMP_GetDefaultConfig(&sConfig);
 *    	sConfig.eConfigRegSel           = kOPAMP_configRegSelB1OrB0;
 *   	sConfig.eLoadMode               = kOPAMP_LoadModeImmediatelyLoad;
 *   	sConfig.sConfigSet0.eWorkMode   = kOPAMP_WorkModeInternalGain2X;
 *   	sConfig.sConfigSet0.ePosChannel = kOPAMP_PosChannel0;
 *      OPAMP_Init(DEMO_OPAMP, &sConfig);
 *    @endcode
 *    3. Update initialization configuration.
 *    @code
 *      opamp_config_set_t sConfigSet;
 *      sConfigSet.eNegChannel = kOPAMP_NegChannel0;
 *      sConfigSet.ePosChannel = kOPAMP_PosChannel0;
 *      sConfigSet.eWorkMode   = kOPAMP_WorkModeBufferMode;
 *      OPAMP_SetOneConfigSet(DEMO_OPAMP, kOPAMP_ConfigSet0, &sConfigSet);
 *      OPAMP_EnableConfigLoad(DEMO_OPAMP);
 *      OPAMP_SetConfigSelection(DEMO_OPAMP,kOPAMP_configRegSelB1OrB0);
 *    @endcode
 *    In this type of use case, the initialized configuration shall be updated. The gain will be changed, for example,
 *    while using the peripheral to control the OPAMP in a delayed load mode.
 *    4. Switch OPAMP peripheral control mode to software control mode.
 *    @code
 *      opamp_config_set_t sConfigSet;
 *      sConfigSet.eNegChannel = kOPAMP_NegChannel0;
 *      sConfigSet.ePosChannel = kOPAMP_PosChannel0;
 *      sConfigSet.eWorkMode   = kOPAMP_WorkModeInternalGain2X;
 *      OPAMP_SetOneConfigSet(DEMO_OPAMP, kOPAMP_ConfigSet1, &sConfigSet);
 *      OPAMP_EnableConfigLoad(DEMO_OPAMP);
 *      OPAMP_SetConfigSelection(DEMO_OPAMP,kOPAMP_ConfigRegSelCFG1);
 *    @endcode
 *
 *  + OPAMP_basic software control OPAMP
 * 	  1. Delayed load mode initialization.
 *    @code
 *   	opamp_config_t sConfig;
 *   	OPAMP_GetDefaultConfig(&sConfig);
 *   	sConfig.sConfigSet0.eWorkMode   = kOPAMP_WorkModeBufferMode;
 *   	sConfig.sConfigSet0.ePosChannel = kOPAMP_PosChannel0;
 *   	sConfig.eConfigRegSel           = kOPAMP_ConfigRegSelCFG0;
 *   	OPAMP_Init(DEMO_OPAMP, &sConfig);
 *    @endcode
 * 	  2. Immediate load mode initialization.
 *    @code
 *   	opamp_config_t sConfig;
 *   	OPAMP_GetDefaultConfig(&sConfig);
 *   	sConfig.eConfigRegSel           = kOPAMP_ConfigRegSelCFG0;
 *   	sConfig.sConfigSet0.eWorkMode   = kOPAMP_WorkModeBufferMode;
 *   	sConfig.eLoadMode               = kOPAMP_LoadModeImmediatelyLoad;
 *   	sConfig.sConfigSet0.ePosChannel = kOPAMP_PosChannel0;
 *   	OPAMP_Init(DEMO_OPAMP, &sConfig);
 *    @endcode
 * 	  3. Use new configuration set.
 *    @code
 *   	opamp_config_set_t sConfigSet;
 *   	sConfigSet.eNegChannel = kOPAMP_NegChannel0;
 *   	sConfigSet.ePosChannel = kOPAMP_PosChannel0;
 *   	sConfigSet.eWorkMode   = kOPAMP_WorkModeInternalGain2X;
 *   	OPAMP_SetOneConfigSet(DEMO_OPAMP, kOPAMP_ConfigSet1, &sConfigSet);
 *   	OPAMP_EnableConfigLoad(DEMO_OPAMP);
 *   	OPAMP_SetConfigSelection(DEMO_OPAMP,kOPAMP_ConfigRegSelCFG1);
 *    @endcode
 *    In this type of use case, configuration set would be switched from current one to another one.
 * 	  4. Switch OPAMP software control mode to peripheral control mode.
 *    @code
 *   	opamp_config_set_t sConfigSet;
 *   	sConfigSet.eNegChannel = kOPAMP_NegChannel0;
 *   	sConfigSet.ePosChannel = kOPAMP_PosChannel0;
 *   	sConfigSet.eWorkMode   = kOPAMP_WorkModeBufferMode;
 *   	OPAMP_SetOneConfigSet(DEMO_OPAMP, kOPAMP_ConfigSet0, &sConfigSet);
 *   	OPAMP_EnableConfigLoad(DEMO_OPAMP);
 *   	OPAMP_SetConfigSelection(DEMO_OPAMP,kOPAMP_configRegSelB1OrB0);
 *    @endcode
 *    In this type of use case, from software control mode to external control mode,
 *    and the gain is switched from x1 to X2.
 *  @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The enumeration lists all options for software controlled opamps and other external signal controlled opamps.
 */
typedef enum _opamp_config_reg_sel
{
    kOPAMP_ConfigRegSelCFG0 = 0U, /*!< Software work register select CFG0 (internal signal).*/
    kOPAMP_ConfigRegSelCFG1 = 1U, /*!< Software work register select CFG1 (internal signal).*/
    kOPAMP_ConfigRegSelCFG2 = 2U, /*!< Software work register select CFG2 (internal signal).*/
    kOPAMP_ConfigRegSelCFG3 = 3U, /*!< Software work register select CFG3 (internal signal).*/

    kOPAMP_ConfigRegSelA1OrA0 = 0x28U, /*!< External signal cfg_sel_a1 or cfg_sel_a0 selects configuartion register. */
    kOPAMP_ConfigRegSelA1OrB0 = 0x30U, /*!< External signal cfg_sel_a1 or cfg_sel_b0 selects configuartion register. */
    kOPAMP_ConfigRegSelA1OrC0 = 0x38U, /*!< External signal cfg_sel_a1 or cfg_sel_c0 selects configuartion register. */

    kOPAMP_configRegSelB1OrA0 = 0x48U, /*!< External signal cfg_sel_b1 or cfg_sel_a0 selects configuartion register. */
    kOPAMP_configRegSelB1OrB0 = 0x50U, /*!< External signal cfg_sel_b1 or cfg_sel_b0 selects configuartion register. */
    kOPAMP_configRegSelB1OrC0 = 0x58U, /*!< External signal cfg_sel_b1 or cfg_sel_c0 selects configuartion register. */

    kOPAMP_ConfigRegSelC1OrA0 = 0x68U, /*!< External signal cfg_sel_c1 or cfg_sel_a0 selects configuartion register. */
    kOPAMP_ConfigRegSelC1OrB0 = 0x70U, /*!< External signal cfg_sel_c1 or cfg_sel_b0 selects configuartion register. */
    kOPAMP_ConfigRegSelC1OrC0 = 0x78U, /*!< External signal cfg_sel_c1 or cfg_sel_c0 selects configuartion register. */
} opamp_config_reg_sel_t;

/*!
 * @brief The enumeration lists the opamp buffer's loading modes, delay loading and immediately loading modes.
 */
typedef enum _opamp_load_mode
{
    kOPAMP_LoadModeDelayLoad = 0U,       /*!< The buffer registers are loaded when the
                                         next configuration is complete, if CTRL[LDOK] is set.*/
    kOPAMP_LoadModeImmediatelyLoad = 1U, /*!< The buffer register shall be loaded immediately after CTRL[LDOK] is set.*/
} opamp_load_mode_t;

/*!
 * @brief The enumeration lists the power modes of the opamp, including low power and high power modes
 */
typedef enum _opamp_power_mode
{
    kOPAMP_PowerModeLowPower = 0U,  /*!< Lower current consumption with slower slew rate
                                    and narrower unity gain bandwidth performance. */
    kOPAMP_PowerModeHighSpeed = 1U, /*!< Higher current consumption with higher slew
                                    rate and wider unity gain bandwidth performance. */
} opamp_power_mode_t;

/*!
 * @brief The enumeration of positive input channel selection.
 */
typedef enum _opamp_positive_channel
{
    kOPAMP_PosChannel0 = 0U, /*!< Positive channel 0.*/
    kOPAMP_PosChannel1 = 1U, /*!< Positive channel 1.*/
    kOPAMP_PosChannel2 = 2U, /*!< Positive channel 2.*/
    kOPAMP_PosChannel3 = 3U, /*!< Positive channel 3.*/
} opamp_positive_channel_t;

/*!
 * @brief The enumeration of negative input channel selection.
 */
typedef enum _opamp_negative_channel
{
    kOPAMP_NegChannel0 = 0U, /*!< Negative channel 0.*/
    kOPAMP_NegChannel1 = 1U, /*!< Negative channel 1.*/
    kOPAMP_NegChannel2 = 2U, /*!< Negative channel 2.*/
    kOPAMP_NegChannel3 = 3U, /*!< Negative channel 3.*/
} opamp_negative_channel_t;

/*!
 * @brief The enumeration of configuration set index.
 */
typedef enum _opamp_config_set_index
{
    kOPAMP_ConfigSet0 = 0U, /*!< Configuration set 0. */
    kOPAMP_ConfigSet1,      /*!< Configuration set 1. */
    kOPAMP_ConfigSet2,      /*!< Configuration set 2. */
    kOPAMP_ConfigSet3,      /*!< Configuration set 3. */
} opamp_config_set_index_t;

/*!
 * @brief The enumeration lists the operating modes of the opamp, including buffer mode, internal gain and external gain
 * mode.
 */
typedef enum _opamp_work_mode
{
    kOPAMP_WorkModeBufferMode      = 0U,                                             /*!< Buffer mode. */
    kOPAMP_WorkModeInternalGain2X  = OPAMP_CFG_GAIN_EN_MASK | OPAMP_CFG_GAIN_SEL(0), /*!< Internal gain 2X mode. */
    kOPAMP_WorkModeInternalGain4X  = OPAMP_CFG_GAIN_EN_MASK | OPAMP_CFG_GAIN_SEL(1), /*!< Internal gain 4X mode. */
    kOPAMP_WorkModeInternalGain8X  = OPAMP_CFG_GAIN_EN_MASK | OPAMP_CFG_GAIN_SEL(2), /*!< Internal gain 8X mode. */
    kOPAMP_WorkModeInternalGain16X = OPAMP_CFG_GAIN_EN_MASK | OPAMP_CFG_GAIN_SEL(3), /*!< Internal gain 16X mode. */
    kOPAMP_WorkModeExternalGain    = OPAMP_CFG_VNEG_EN_MASK,                         /*!< External gain mode. */
} opamp_work_mode_t;

/*!
 * @brief Configuration set information.
 */
typedef struct _opamp_config_set
{
    opamp_work_mode_t eWorkMode;          /*!< Opamp work mode. */
    opamp_negative_channel_t eNegChannel; /*!< Negative channel selection. */
    opamp_positive_channel_t ePosChannel; /*!< Positive channel selection. */
} opamp_config_set_t;

/*!
 * @brief Configuration structure.
 */
typedef struct _opamp_config
{
    bool bEnableLoadCompletionInterrupt;  /*!< Enable load completion interrupt */
    bool bEnableWriteProtection;          /*!< Enable write protection. */
    opamp_load_mode_t eLoadMode;          /*!< Configuration load mode.*/
    opamp_power_mode_t ePowerMode;        /*!< Configuration Power mode.*/
    opamp_config_reg_sel_t eConfigRegSel; /*!< Selects configuration register.*/
    opamp_config_set_t sConfigSet0;       /*!< Configuration register set 0.*/
    opamp_config_set_t sConfigSet1;       /*!< Configuration register set 1.*/
    opamp_config_set_t sConfigSet2;       /*!< Configuration register set 2.*/
    opamp_config_set_t sConfigSet3;       /*!< Configuration register set 3.*/
} opamp_config_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Initialization And De-initialization Interfaces
 * @{
 */

/*!
 * @brief Initializes the OPAMP module.
 *
 * This function does initialization when using OPAMP module.
 * The operations are:
 *  - Enable the clock for OPAMP.
 *  - Enable the write protection.
 *  - Enable the load completion interrupt.
 *  - Set configuration register for OPAMP.
 *  - Set Positive channel and Negative channel.
 *  - Set the power mode.
 *  - Set the gain value.
 *  - Set the load mode.
 *  - Enable the OPAMP.
 *
 * @param base   OPAMP peripheral base address.
 * @param psConfig Pointer to configuration structure.See @ref opamp_config_t.
 */
void OPAMP_Init(OPAMP_Type *base, const opamp_config_t *psConfig);

/*!
 * @brief Gets default configuration for OPAMP.
 *
 * The default value:
 * @code
    psConfig->bEnableLoadCompletionInterrupt = false;
    psConfig->bEnableWriteProtection = false;
    psConfig->eLoadMode = kOPAMP_LoadModeDelayLoad;
    psConfig->ePowerMode = kOPAMP_PowerModeLowPower;
    psConfig->eConfigRegSel  = kOPAMP_ConfigRegSelCFG0;

    psConfig->sConfigSet0.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet0.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet0.ePosChannel = kOPAMP_PosChannel0;

    psConfig->sConfigSet1.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet1.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet1.ePosChannel = kOPAMP_PosChannel0;

    psConfig->sConfigSet2.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet2.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet2.ePosChannel = kOPAMP_PosChannel0;

    psConfig->sConfigSet3.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet3.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet3.ePosChannel = kOPAMP_PosChannel0;
    @endcode
 *
 * @param psConfig Pointer to configuration structure.
 */
void OPAMP_GetDefaultConfig(opamp_config_t *psConfig);

/*!
 * @brief De-initializes the OPAMP module.
 *
 * This function does de-initialization when using OPAMP module.
 * The operations are:
 *  - Disable the OPAMP.
 *  - Disable the clock for OPAMP.
 *
 * @param base OPAMP peripheral base address.
 */
void OPAMP_Deinit(OPAMP_Type *base);

/*! @} */

/*!
 * @name Configuration Interfaces
 * @{
 */

/*!
 * @brief Sets configuration set.
 *
 * This function only sets the configuration set, application should
 * call @ref OPAMP_EnableConfigLoad to enable the load after setting all desired configuration sets.
 *
 * @param base OPAMP peripheral base address.
 * @param eIndex Index of configuration set,please see @ref opamp_config_set_index_t for details.
 * @param psConfigSet Pointer to the configure structure,please see @ref opamp_config_set_t for details.
 */
void OPAMP_SetOneConfigSet(OPAMP_Type *base, opamp_config_set_index_t eIndex, const opamp_config_set_t *psConfigSet);

/*!
 * @brief Changes configuration register selection.
 *
 * This function can configure the working registers of the software and external signal. When the
 * configuration set is updated using @ref OPAMP_SetOneConfigSet and the external signal is not used, the software
 * working register should also select the corresponding software working register according to the update of the
 * configuration set.
 *
 * @param base OPAMP peripheral base address.
 * @param eConfigRegSel configuration register selection, please see @ref opamp_config_reg_sel_t for details.
 */
void OPAMP_SetConfigSelection(OPAMP_Type *base, opamp_config_reg_sel_t eConfigRegSel);

/*!
 * @brief Enables the OPAMP.
 *
 * @note Please use function @ref OPAMP_EnableOPAMP to re-enable the OPAMP if it is disabled.
 * Then load it with function @ref OPAMP_EnableConfigLoad.
 *
 * @param base OPAMP peripheral base address.
 * @param bEnable Enables/disables the module.
 */
static inline void OPAMP_EnableOPAMP(OPAMP_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL |= OPAMP_CTRL_EN_MASK;
    }
    else
    {
        base->CTRL &= ~(uint16_t)OPAMP_CTRL_EN_MASK;
    }
}

/*!
 * @brief Enables the new configuration load.
 *
 * After configuration load enabled, the new set configuration will be loaded
 * at the time determined by load mode. Application could monitor the load completion
 * by @ref OPAMP_CheckLoadCompletionFlag or the interrupt. When the load finishes,
 * the configuration load shall be disabled automatically.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_EnableConfigLoad(OPAMP_Type *base)
{
    base->CTRL |= OPAMP_CTRL_LDOK_MASK;
}

/*! @} */

/*!
 * @name Disables Write Protection Control Interfaces
 * @{
 */

/*!
 * @brief Disables write protection.
 *
 * Write 10b to this field to disable the write protection.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_DisableWriteProtection(OPAMP_Type *base)
{
    base->STAT = 0x08U;
}

/*! @} */

/*!
 * @name Power Control Interfaces
 * @{
 */

/*!
 * @brief Changes the power mode.
 *
 * @param base OPAMP peripheral base address.
 * @param ePowerMode  Power mode, please see @ref opamp_power_mode_t for details.
 */
static inline void OPAMP_SetPowerMode(OPAMP_Type *base, opamp_power_mode_t ePowerMode)
{
    if (kOPAMP_PowerModeHighSpeed == ePowerMode)
    {
        base->CTRL |= OPAMP_CTRL_PMOD_MASK;
    }
    else
    {
        base->CTRL &= ~(uint16_t)OPAMP_CTRL_PMOD_MASK;
    }
}

/*! @} */

/*!
 * @name Load Mode Control Interfaces
 * @{
 */

/*!
 * @brief Changes the load mode.
 *
 * @param base OPAMP peripheral base address.
 * @param eLoadMode  load mode, please see @ref opamp_load_mode_t for details.
 */
static inline void OPAMP_SetLoadMode(OPAMP_Type *base, opamp_load_mode_t eLoadMode)
{
    if (kOPAMP_LoadModeImmediatelyLoad == eLoadMode)
    {
        base->CTRL |= OPAMP_CTRL_LDMOD_MASK;
    }
    else
    {
        base->CTRL &= ~(uint16_t)OPAMP_CTRL_LDMOD_MASK;
    }
}

/*! @} */

/*!
 * @name Interrupt Control Interfaces
 * @{
 */

/*!
 * @brief Enables load completion interrupt.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_EnableLoadCompletionInterrupt(OPAMP_Type *base)
{
    base->CTRL |= OPAMP_CTRL_LDCMIE_MASK;
}

/*!
 * @brief Disables load completion interrupt.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_DisableLoadCompletionInterrupt(OPAMP_Type *base)
{
    base->CTRL &= ~(uint16_t)OPAMP_CTRL_LDCMIE_MASK;
}

/*! @} */

/*!
 * @name Status Flag Interface
 * @{
 */

/*!
 * @brief Checks the configuration load completion flag status.
 *
 * @param base OPAMP peripheral base address.
 * @return Return true if the flag is set, otherwise return false.
 */
static inline bool OPAMP_CheckLoadCompletionFlag(OPAMP_Type *base)
{
    return (0U != (base->STAT & OPAMP_STAT_LDCMF_MASK));
}

/*!
 * @brief Clears the configuration load completion flag.
 *
 * @param base OPAMP peripheral base address.
 */
static inline void OPAMP_ClearLoadCompletionFlag(OPAMP_Type *base)
{
    base->STAT |= OPAMP_STAT_LDCMF_MASK;
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* FSL_OPAMP_H_ */
