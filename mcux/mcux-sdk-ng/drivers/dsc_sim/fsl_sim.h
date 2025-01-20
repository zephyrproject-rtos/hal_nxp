/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SIM_H_
#define FSL_SIM_H_

#include "fsl_common.h"

/*!
 * @defgroup sim SIM: System Integration Module Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief SIM driver version. */
#define FSL_SIM_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*******************************************************************************
 * SIM peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup sim_driver_log The Driver Change Log
 * @ingroup sim
 * @{
 * The current SIM driver version is 2.1.0.
 *
 * - 2.1.0
 *   - Improvements
 *     - Updated support for MC56F82xxx and MC56F84xxx.
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introducation of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup sim_intro SIM Peripheral and Driver Overview
 * @ingroup sim
 * @brief Content including 1) peripheral features and work logic; 2) driver design logic
 * @{
 *
 *
 * Peripheral features and how this peripheral works
 * ==================================================
 * The System Integration Module interacts with a variety of other on-chip resources and provides multiple services.
 *
 *  Features
 *  ---------
 *  + Manages low power mode entry and exit.
 *  + Software on chip peripherals.
 *  + Controls inter-peripheral muxing and signal relationships.
 *  + Control voltage regulators.
 *  + Provides write protection for safety critical memory mapped registers.
 *  + Contains the information of chip's JTAG ID and suggested trim values set at the factory.
 *  + Supports short addressing control.
 *  + Internal Peripheral Extend Control Interfaces
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 *  The SIM interacts with a variety of other on-chip resources, based on the behaviour, this driver is diviced in
 *  several function groups.
 *  + Low Power Mode Control Related Interfaces \n
 *      The APIs in this function group can be used to enter/exit low power mode(including WAIT mode and STOP mode) and
 *      config low power mode operation mode.
 *  + Reset Related Interfaces \n
 *      The APIs in this function group can be used to software reset device and other internal module.
 *  + Peripheral Signal Muxing Control Interfaces \n
 *      The APIs in this function group can be used to set the mux of peripheral signal.
 *  + Voltage Regulators Control Interfaces \n
 *      The APIs in this function group can be used to control the low power mode on-chip regulators, including large
 *      voltage regulator and small voltage regulator.
 *  + Write Protection Interfaces \n
 *      The APIs in this function group can be used to set write protection of some peripherals' registers.
 *  + JTAG ID And Factory Trim Value Interfaces \n
 *      The APIs in this function group can be used to return JTAG ID, PMC bandgap trim value, and 200 khz ROSC
 *      frequency trim value.
 *  + Short Addressing Control Related Interfaces \n
 *      The APIs in this function group can be used to set short address location upper bits.
 *  + Software Control Interfaces \n
 *      The APIs in this function group can be used to set software control registers.
 *  + Internal Peripheral Extend Control Interfaces \n
 *      The APIs in this function group can be used to set other peripherals' extended features.
 *
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_sim"
#endif

#if (defined(FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD) && FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD)
/*! @brief The macro of REST status bit field mask.  */
#define SIM_RESET_STATUS_MASK                                                                        \
    (SIM_RSTAT_COP_WIN_MASK | SIM_RSTAT_SWR_MASK | SIM_RSTAT_COP_CPU_MASK | SIM_RSTAT_COP_LOR_MASK | \
     SIM_RSTAT_EXTR_MASK | SIM_RSTAT_POR_MASK)
#else
#define SIM_RESET_STATUS_MASK \
    (SIM_RSTAT_SWR_MASK | SIM_RSTAT_COP_CPU_MASK | SIM_RSTAT_COP_LOR_MASK | SIM_RSTAT_EXTR_MASK | SIM_RSTAT_POR_MASK)
#endif /* FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD */

/*!
 * @brief The definition of the short regulator control mode bit field mask.
 */
#define SIM_PWR_SR27_CONTROL_MODE_MASK (SIM_PWR_SR27STDBY_MASK | SIM_PWR_SR27PDN_MASK)
/*! @brief The definition of the short regulator control mode bit field shift. */
#define SIM_PWR_SR27_CONTROL_MODE_SHIFT (2U)
/*! @brief The macro that can be used to set the bit field of PWR register's short regulator bit field. */
#define SIM_PWR_SR27_CONTROL_MODE(x) \
    (((uint16_t)(((uint16_t)(x)) << SIM_PWR_SR27_CONTROL_MODE_SHIFT)) & SIM_PWR_SR27_CONTROL_MODE_MASK)

/*! @brief The definition of the PORT register bit filed mask. */
#define SIM_PROT_BIT_FIELD_MASK(moduleName) (((uint16_t)3U << (uint8_t)(moduleName)))
/*! @brief The macro that can be used to set module's protection mode. */
#define SIM_PORT_SET_MODE_PROTECTION_MODE(moduleName, protectionMode) \
    ((uint16_t)(((uint16_t)(protectionMode)) << (uint8_t)(moduleName)))

/*!
 * @brief The enumeration of system reset status flags, such as power on reset, software reset, etc.
 */
enum _sim_reset_status_flags
{
    kSIM_PowerONResetFlag  = SIM_RSTAT_POR_MASK,  /*!< The Power on reset caused the most recent reset. */
    kSIM_ExternalResetFlag = SIM_RSTAT_EXTR_MASK, /*!< The external reset caused the most recent reset, that means
                                                        the external reset pin was asserted or remained asserted
                                                        after the power-on reset de-asserted. */
    kSIM_COPLossOfReferenceResetFlag = SIM_RSTAT_COP_LOR_MASK, /*!< The computer operating properly module signaled a
                                                                    PLL loss of reference clock reset caused the most
                                                                    recent reset. */
    kSIM_COPCPUTimeOutResetFlag = SIM_RSTAT_COP_CPU_MASK,      /*!< The computer operating properly module signaled a
                                                                   CPU time-out reset caused the most recent reset. */
    kSIM_SofwareResetFlag = SIM_RSTAT_SWR_MASK, /*!< The previous system reset occurred as a result of a software
                                                    reset */
#if (defined(FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD) && FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD)
    kSIM_COPWindowTimeOutResetFlag = SIM_RSTAT_COP_WIN_MASK, /*!< The previous system reset occurred as a result of a
                                                                 cop_window reset. */
#endif                                                       /* FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD */
};

/*!
 * @brief The enumeration of stop mode operation can be used to enable/disable stop mode enter.
 */
typedef enum _sim_stop_mode_operation
{
    kSIM_STOPInstrutionEnterStopMode = 0U, /*!< Stop mode is entered when the DSC core executes a STOP instruction. */
    kSIM_STOPInstrutionNotEnterStopMode,   /*!< The DSC core STOP instruction does not cause entry into stop mode. */
    kSIM_STOPInstrutionEnterStopModeWriteProtect,     /*!< Stop mode is entered when the DSC core executes a STOP
                                                           instruction, and the realted register bit field is write
                                                           protected until the next reset. */
    kSIM_STOPInstructionNotEnterStopModeWriteProtect, /*!< The DSC core STOP instruction does not cause entry into
                                                           stop mode, and the related register bit field is write
                                                           protected until the next reset. */
} sim_stop_mode_operation_t;

/*!
 * @brief The enumeration of wait mode operation can be used to enable/disable wait mode enter.
 */
typedef enum _sim_wait_mode_operation
{
    kSIM_WAITInstrutionEnterWaitMode = 0U, /*!< Wait mode is entered when the DSC core executes a WAIT instruction. */
    kSIM_WAITInstrutionNotEnterWaitMode,   /*!< The DSC core WAIT instruction does not cause entry into wait mode. */
    kSIM_WAITInstrutionEnterWaitModeWriteProtect,     /*!< Wait mode is entered when the DSC core executes a WAIT
                                                           instruction, and the realted register bit field is write
                                                           protected until the next reset. */
    kSIM_WAITInstructionNotEnterWaitModeWriteProtect, /*!< The DSC core WAIT instruction does not cause entry into
                                                           wait mode, and the related register bit field is write
                                                           protected until the next reset. */
} sim_wait_mode_operation_t;

/*! @brief The enumeration of OnCE clock operation mode, such as enabled when core TAP is enabled and always enabled */
typedef enum _sim_onceclk_operation_mode
{
    kSIM_OnCEClkEnabledWhenCoreTapEnabled = 0U, /*!< The OnCE clock to the DSC core is enabled when the core
                                                       TAP is enabled. */
    kSIM_OnCEClkAlwaysEnabled = 1U              /*!< The OnCE clock to the DSC core is always enabled. */
} sim_onceclk_operation_mode_t;

/*! @brief The enumeration of dma operation mode, this enumeration can be used to disable/enable DMA module in different
   power modes. */
typedef enum _sim_dma_operation_mode
{
    kSIM_DMADisable = 0U,                        /*!< DMA module is disabled. */
    kSIM_DMAEnableAtRunModeOnly,                 /*!< DMA module is enabled in run mode only. */
    kSIM_DMAEnableAtRunModeWaitMode,             /*!< DMA module is enabled in run and wait modes only. */
    kSIM_DMAEnableAtAllPowerModes,               /*!< DMA module is enabled in all power modes. */
    kSIM_DMADisableWriteProtect,                 /*!< DMA module is disabled and the related register bit field is write
                                                            protected until the next reset. */
    kSIM_DMAEnableAtRunModeOnlyWriteProtect,     /*!< DMA module is enabled in run mode only and the related bit field
                                                        is write protected until the next reset. */
    kSIM_DMAEnableAtRunModeWaitModeWriteProtect, /*!< DMA module is enabled in run and wait modes only and the
                                                        related register bit field is write protected until the next
                                                        reset. */
    kSIM_DMAEnableAtAllPowerModesWriteProtect,   /*!< DMA module is enabled in all low power modes and the related
                                                          register bit field is write protected until the next reset. */
} sim_dma_operation_mode_t;

/*!
 * @brief The enumeration of device's boot mode, including ROM boot and NVM flash boot.
 */
typedef enum _sim_boot_mode
{
    kSIM_BootFromNVMFlash = 0U, /*!< Indicates the chip is boot from NVM Flash. */
    kSIM_BootFromROM      = 1U, /*!< Indicates the chip is boot from ROM. */
} sim_boot_mode_t;

/*!
 * @brief The enumeration of small regualtor 1P2V control mode, such as normal mode and standby mode.
 */
typedef enum _sim_small_regulator_1P2V_control_mode
{
    kSIM_SmallRegulator1P2VInNormalMode = 0U,         /*!< Small regulator 1.2V supply placed in normal mode. */
    kSIM_SmallRegulator1P2VInStandbyMode,             /*!< Small regulator 1.2V supply placed in standby mode. */
    kSIM_SmallRegulator1P2VInNormalModeWriteProtect,  /*!< Small regulator 1.2V supply placed in nomal mode, and the
                                                        related register bit field is write protected until the next
                                                         reset. */
    kSIM_SmallRegulator1P2VInStandbyModeWriteProtect, /*!< Small regulator 1.2V supply placed in standby mode, and the
                                                        related register bit field is write protected until the next
                                                        reset. */
} sim_small_regulator_1P2V_control_mode_t;

/*!
 * @brief The enumeration of small regulator 2P7V control mode, such as normal mode, standby mode, powerdown mode, etc.
 */
typedef enum _sim_small_regulator_2P7V_control_mode
{
    kSIM_SmallRegulator2P7VInNormalMode             = 0U, /*!< Small regulator 2.7V supply placed in normal mode. */
    kSIM_SmallRegulator2P7VInStandbyMode            = 1U, /*!< Small regulator 2.7V supply placed in standby mode. */
    kSIM_SmallRegulator2P7VInPowerdownMode          = 4U, /*!< Small regulator 2.7V supply placed in powerdown mode. */
    kSIM_SmallRegulator2P7VInNormalModeWriteProtect = 2U, /*!< Small regulator 2.7V supply placed in normal mode and the
                                                            related bit field is write protected until chip reset. */
    kSIM_SmallRegulator2P7VInStandbyModeWriteProtect = 3U, /*!< Small regulator 2.7V supply placed in standby mode and
                                                                the related bit field is write protected until chip
                                                                reset. */
    kSIM_SmallRegulator2P7VInPowerdownModeWriteProtect = 0xCU, /*!< Small regulator placed in powerdown mode and the
                                                               related bit field is write protected until chip reset. */
} sim_small_regulator_2P7V_control_mode_t;

/*!
 * @brief The enumeration of large regulator contorl mode, such as normal mode, standby mode.
 */
typedef enum _sim_large_regulator_control_mode
{
    kSIM_LargeRegulatorInNormalMode = 0U,         /*!< Large regulator placed in normal mode. */
    kSIM_LargeRegulatorInStandbyMode,             /*!< Large regulator placed in standby mode. */
    kSIM_LargeRegulatorInNormalModeWriteProtect,  /*!< Large regulator placed in normal mode, and the related register
                                                       bit field is write protected until chip reset. */
    kSIM_LargeRegulatorInStandbyModeWriteProtect, /*!< Large regulator placed in standby mode, and the related register
                                                       bit field is write protected until chip reset. */
} sim_large_regulator_control_mode_t;

/*!
 * @brief The enumeration of modules that support various protection mode.
 */
typedef enum _sim_write_protection_module
{
    kSIM_GPIOInternalPeripheralSelectProtection = 0U, /*!< Used to control the protection mode GPSn and
                                                                    IPSn registers in the SIM, all XBAR, EVTG,
                                                                    GPIOn_PER, GPIOn_PPMODE, GPIOn_DRIVE. */
    kSIM_PeripheralClockEnableProtection = 2U,        /*!< Used to control the protection mode of PCEn, SDn,
                                                                          PSWRn, and PCR register. */
    kSIM_GPIOPortDProtection = 4U,                    /*!< Used to control the protection mode of GPIO_D_PER,
                                                                         GPIO_D_PPMODE, and GPIO_D_DRIVE register. */
    kSIM_PowerModeControlWriteProtection = 6U,        /*!< Used to control the protection mode of the PWRMODE
                                                                           register. */
} sim_write_protection_module_t;

/*! @brief The enumeration of write protection mode, such as write protection off, write protection on, etc. */
typedef enum _sim_write_protection_mode
{
    kSIM_WriteProtectionOff          = 0U, /*!< Write protection off. */
    kSIM_WriteProtectionOn           = 1U, /*!< Write protection on. */
    kSIM_WriteProtectionOffAndLocked = 2U, /*!< Write protection off and locked until chip reset. */
    kSIM_WriteProtectionOnAndLocked  = 3U  /*!< Write protection on and locked until chip reset. */
} sim_write_protection_mode_t;

/*!
 * @brief The enumeration of lpi2c trigger selection, including slave trigger and master trigger.
 */
typedef enum _sim_lpi2c_trigger_selection
{
    kSIM_Lpi2cSlaveTrigger = 0U, /*!< Selects slave trigger. */
    kSIM_Lpi2cMasterTrigger,     /*!< Selects master trigger. */
} sim_lpi2c_trigger_selection_t;

#if (defined(FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD) && FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD)
/*!
 * @brief The enumeration of device operate mode, including normal mode and fast mode.
 */
typedef enum _sim_device_operate_mode
{
    kSIM_NormalOperateMode = 0U, /*!< Device in normal operating mode, core:bus frequency as 1:1 */
    kSIM_FastOperateMode,        /*!< Device in fast operate mode, core:bus frequency as 2:1 */
} sim_device_operate_mode_t;
#endif /* FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD */

/*!
 * @brief The enumeration of master pit.
 */
typedef enum _sim_master_pit_selection
{
    kSIM_PIT0MasterPIT1Slave = 0U, /*!< PIT0 is master PIT and PIT1 is slave PIT. */
    kSIM_PIT1MasterPIT0Slave = 1U, /*!< PIT0 is master PIT and PIT1 is slave PIT. */
} sim_master_pit_selection_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Low Power Mode Control Related Interfaces
 * @{
 */

/*!
 * @brief Sets the operation of wait mode, enable/disable the entry of wait mode.
 *
 * @param base SIM peripheral base address.
 * @param eOperation Used to enable/disable the wait mode, please refer to @ref sim_wait_mode_operation_t.
 */
static inline void SIM_SetWaitModeOperation(SIM_Type *base, sim_wait_mode_operation_t eOperation)
{
    base->CTRL = (base->CTRL & (~SIM_CTRL_WAIT_DISABLE_MASK)) | SIM_CTRL_WAIT_DISABLE(eOperation);
}

/*!
 * @brief Sets the operation of stop mode, enable/disable the entry of stop mode.
 *
 * @param base SIM peripheral base address.
 * @param eOperation Used to enable/disable the stop mode, please refer to @ref sim_stop_mode_operation_t.
 */
static inline void SIM_SetStopModeOperation(SIM_Type *base, sim_stop_mode_operation_t eOperation)
{
    base->CTRL = (base->CTRL & (~SIM_CTRL_STOP_DISABLE_MASK)) | SIM_CTRL_STOP_DISABLE(eOperation);
}

/*!
 * @brief Enters into LPMode when the advanced power mode is enabled(register FOPT[1] bit is set).
 *
 * @note Please make sure the power mode register is not set as write protected before invoking this function.
 * @note This function is useful only when the FTFE module's FOPT[0] bit is set(advanced power mode is enabled).
 *
 * @param base SIM peripheral base address.
 */
static inline void SIM_EnterLPMode(SIM_Type *base)
{
    base->PWRMODE |= SIM_PWRMODE_LPMODE_MASK;
}

/*!
 * @brief Exits from LPMode when the advanced power mode is enabled(register FOPT[1] bit is set).
 *
 * @note Please make sure the power mode register is not set as write protected before invoking this function.
 * @note This function is useful only when the FTFE module's FOPT[0] bit is set(advanced power mode is enabled).
 *
 * @param base SIM peripheral base address.
 */
static inline void SIM_ExitLPMode(SIM_Type *base)
{
    base->PWRMODE &= ~SIM_PWRMODE_LPMODE_MASK;
}

/*!
 * @brief Enters into VLPMode when the advanced power mode is enabled(register FOPT[1] bit is set).
 *
 * @note Please make sure the power mode register is not set as write protected before invoking this function.
 * If both set to enter LPMode and VLPMode, the VLPMode has higher priority.
 * @note This function is useful only when the FTFE module's FOPT[0] bit is set(advanced power mode is enabled).
 *
 * @param base SIM peripheral base address.
 */
static inline void SIM_EnterVLPMode(SIM_Type *base)
{
    base->PWRMODE |= SIM_PWRMODE_VLPMODE_MASK;
}

/*!
 * @brief Exits from VLPMode when the advanced power mode is enabled(register FOPT[1] bit is set).
 *
 * @note Please make sure the power mode register is not set as write protected before invoking this function.
 * @note This function is useful only when the FTFE module's FOPT[0] bit is set(advanced power mode is enabled).
 *
 * @param base SIM peripheral base address.
 */
static inline void SIM_ExitVLPMode(SIM_Type *base)
{
    base->PWRMODE &= ~SIM_PWRMODE_VLPMODE_MASK;
}

/*!
 * @brief Indicates whether the chip is in LPMode when the advanced power mode is enabled(register FOPT[1] bit is set).
 *
 * @note This function is useful only when the FTFE module's FOPT[0] bit is set(advanced power mode is enabled).
 *
 * @param base SIM peripheral base address.
 * @retval true  The chip is in LPMode.
 * @retval false The chip is not in LPMode.
 */
static inline bool SIM_IsInLPMode(SIM_Type *base)
{
    return ((base->PWRMODE & SIM_PWRMODE_LPMS_MASK) == SIM_PWRMODE_LPMS_MASK);
}

/*!
 * @brief Indicates whether the chip is in VLPMode when the advanced power mode is enabled(register FOPT[1] bit is set).
 *
 * @note This function is useful only when the FTFE module's FOPT[0] bit is set(advanced power mode is enabled).
 *
 * @param base SIM peripheral base address.
 * @retval true  The chip is in VLPMode.
 * @retval false The chip is not in VLPMode.
 */
static inline bool SIM_IsInVLPMode(SIM_Type *base)
{
    return ((base->PWRMODE & SIM_PWRMODE_VLPMS_MASK) == SIM_PWRMODE_VLPMS_MASK);
}

/*!
 * @}
 */

/*!
 * @name Reset Related Interfaces
 * @{
 */

/*!
 * @brief Triggers the software reset for device.
 *
 * @param base SIM base address.
 */
static inline void SIM_TriggerSoftwareReset(SIM_Type *base)
{
    base->CTRL |= SIM_CTRL_SWRST_MASK;
}

/*!
 * @brief Gets the cause of the most recent reset.
 *
 * @note At any given time, the only one reset source is indicated. When multiple reset source assert simultaneously,
 * the reset source with the highest precedence is indicated. The precedence from highest to lowest is POR, external
 * reset, COP loss of reference reset, COP CPU time-out reset, software reset, COP window time-out reset. The POR is
 * always set during a power-on reset. However, POR is cleared and the external reset is set if the external reset pin
 * is asserted or remains asserted after the power-on reset has de-asserted.
 *
 * @param base SIM peripheral base address.
 * @return The current reset status flags, should be the OR'ed value of @ref _sim_reset_status_flags.
 */
static inline uint16_t SIM_GetResetStatusFlags(SIM_Type *base)
{
    return (base->RSTAT & SIM_RESET_STATUS_MASK);
}

/*!
 * @brief Triggers the software reset of specific peripheral.
 *
 * @param base SIM peripheral base address.
 * @param ePeriIndex The index of the peripheral to be reset.
 */
static inline void SIM_TriggerPeripheralSoftwareReset(SIM_Type *base, sim_swReset_peri_index_t ePeriIndex)
{
    if ((uint8_t)ePeriIndex < 16U)
    {
        base->PSWR0 |= (((uint16_t)1U) << ((uint8_t)ePeriIndex));
        base->PSWR0 &= (~(((uint16_t)1U) << ((uint8_t)ePeriIndex)));
    }
    else if ((uint8_t)ePeriIndex < 32U)
    {
        base->PSWR1 |= (((uint16_t)1U) << (((uint8_t)ePeriIndex) % 16U));
        base->PSWR1 &= (~(((uint16_t)1U) << ((uint8_t)ePeriIndex) % 16U));
    }
    else if ((uint8_t)ePeriIndex < 48U)
    {
        base->PSWR2 |= (((uint16_t)1U) << (((uint8_t)ePeriIndex) % 16U));
        base->PSWR2 &= (~(((uint16_t)1U) << ((uint8_t)ePeriIndex) % 16U));
    }
    else if ((uint8_t)ePeriIndex < 64U)
    {
        base->PSWR3 |= (((uint16_t)1U) << (((uint8_t)ePeriIndex) % 16U));
        base->PSWR3 &= (~(((uint16_t)1U) << ((uint8_t)ePeriIndex) % 16U));
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

/*!
 * @brief Enables/Disables the input filter on external reset padcell.
 *
 * If the input filter is enabled, the filter will remove transient signals on the input at the expense of an increased
 * input delay.
 *
 * @note If the input filter is enabled, the filter will affect all input functions supported by that padcell, including
 * GPIO.
 *
 * @param base SIM peripheral base address.
 * @param bEnable Used to control the behaviour of input filter.
 *                  - \b true Enable the input filter on external input padcell.
 *                  - \b false Disable the input filter on external input padcell.
 */
static inline void SIM_EnableResetPadCellInputFilter(SIM_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CTRL |= SIM_CTRL_RST_FILT_MASK;
    }
    else
    {
        base->CTRL &= ~SIM_CTRL_RST_FILT_MASK;
    }
}

/*!
 * @}
 */

/*!
 * @name Peripheral Signal Muxing Control Interfaces
 * @{
 */
/*!
 * @brief Sets internal peripheral inputs, some peripheral inputs have the ability to be connected to either XBAR
 * outputs or GPIO.
 *
 * @param base SIM base address.
 * @param eIndex The internal peripherals that supply multi-inputs.
 * @param eInput The specific input that connected to the selected internal peripheral.
 */
static inline void SIM_SetInternalPeriInput(SIM_Type *base,
                                            sim_internal_peri_index_t eIndex,
                                            sim_internal_peri_input_t eInput)
{
#if (defined(FSL_FEATURE_SIM_HAS_IPSN_REGISTER) && FSL_FEATURE_SIM_HAS_IPSN_REGISTER)
    base->IPSN &= (~((uint16_t)1U << (uint8_t)eIndex));
    base->IPSN |= (((uint16_t)eInput) << (uint8_t)eIndex);
#else
    base->IPS0 &= (~((uint16_t)1U << (uint8_t)eIndex));
    base->IPS0 |= (((uint16_t)eInput) << (uint8_t)eIndex);
#endif /* FSL_FEATURE_SIM_HAS_IPSN_REGISTER */
}

#if (defined(FSL_FEATURE_SIM_HAS_PWM_SEL_REGISTER) && FSL_FEATURE_SIM_HAS_PWM_SEL_REGISTER)
/*!
 * @brief Selects the Xbar input from PWMA and PWMB.
 *
 * @param base SIM base address.
 * @param eIndex SIM PWM select register field index.
 * @param eSelection Xbar input pwm selection.
 */
static inline void SIM_SetXbarInputPWMSelection(SIM_Type *base,
                                                sim_xbar_input_pwm_index_t eIndex,
                                                sim_xbar_input_pwm_selection_t eSelection)
{
    base->PWM_SEL &= (~((uint16_t)1U << (uint8_t)eIndex));
    base->PWM_SEL |= (((uint16_t)eSelection) << (uint8_t)eIndex);
}
#endif /* FSL_FEATURE_SIM_HAS_PWM_SEL_REGISTER */

#if (defined(FSL_FEATURE_SIM_HAS_ADC_TMR_SEL_REGISTER) && FSL_FEATURE_SIM_HAS_ADC_TMR_SEL_REGISTER)
/*!
 * @brief Selects the Xbar input from ADC and TMR A/B.
 *
 * @param base SIM base address.
 * @param eIndex SIM ADC and TMR select register field index.
 * @param eSelection Xbar input ADC and TMR selection.
 */
static inline void SIM_SetXbarInputAdcTmrSelection(SIM_Type *base,
                                                   sim_xbar_input_adc_tmr_index_t eIndex,
                                                   sim_xbar_input_adc_tmr_selection_t eSelection)
{
    base->ADC_TMR_SEL &= (~((uint16_t)1U << (uint8_t)eIndex));
    base->ADC_TMR_SEL |= (((uint16_t)eSelection) << (uint8_t)eIndex);
}
#endif /* FSL_FEATURE_SIM_HAS_ADC_TMR_SEL_REGISTER */
/*! @} */

/*!
 * @name Voltage Regulators Control Interfaces
 * @{
 */

/*!
 * @brief Sets the control mode of small regulator 1.2V supply, the available control modes are normal mode, standby
 * mode, etc.
 *
 * @note This function is useful only when the flash module's FOPT[0] bit is 0.
 *
 * @param base SIM peripheral base address.
 * @param eControlMode The control mode to be set, please refer to @ref sim_small_regulator_1P2V_control_mode_t.
 */
static inline void SIM_SetSmallRegulator1P2VControlMode(SIM_Type *base,
                                                        sim_small_regulator_1P2V_control_mode_t eControlMode)
{
    base->PWR = (base->PWR & (~SIM_PWR_SR12STDBY_MASK)) | SIM_PWR_SR12STDBY(eControlMode);
}

/*!
 * @brief Sets the control mode of small regulator 2.7 supply, the available control modes are normal mode, standby
 * mode, etc.
 *
 * @note This function is useful only when the flash module's FOPT[0] bit is 0.
 *
 * @param base SIM peripheral base address.
 * @param eControlMode THe control mode to be set, please refer to @ref sim_small_regulator_2P7V_control_mode_t.
 */
static inline void SIM_SetSmallRegulator2P7VControlMode(SIM_Type *base,
                                                        sim_small_regulator_2P7V_control_mode_t eControlMode)
{
    base->PWR = (base->PWR & (~SIM_PWR_SR27_CONTROL_MODE_MASK)) | SIM_PWR_SR27_CONTROL_MODE(eControlMode);
}

/*!
 * @brief Sets the control mode of large regulator, the available control mode are normal mode, standby mode, etc.
 *
 * @note This function is useful only when the flash module's FOPT[0] bit is 0.
 *
 * @param base SIM peripheral base address.
 * @param eControlMode The control mode to be set, please refer to @ref sim_large_regulator_control_mode_t.
 */
static inline void SIM_SetLargeRegulatorControlMode(SIM_Type *base, sim_large_regulator_control_mode_t eControlMode)
{
    base->PWR = (base->PWR & (~SIM_PWR_LRSTDBY_MASK)) | SIM_PWR_LRSTDBY(eControlMode);
}

/*! @} */

/*!
 * @name Write Protection Interfaces
 * @{
 */

/*!
 * @brief Sets the write protection mode of the selected register.
 *
 * @param base SIM peripheral base address.
 * @param eModule The module to be set, please refer to @ref sim_write_protection_module_t.
 * @param eMode The specific write protection mode to be set, please refer to @ref sim_write_protection_mode_t.
 */
static inline void SIM_SetRegisterProtectionMode(SIM_Type *base,
                                                 sim_write_protection_module_t eModule,
                                                 sim_write_protection_mode_t eMode)
{
    base->PROT = base->PROT & (~SIM_PROT_BIT_FIELD_MASK(eModule)) | SIM_PORT_SET_MODE_PROTECTION_MODE(eModule, eMode);
}

/*! @} */

/*!
 * @name JTAG ID And Factory Trim Value Interfaces
 * @{
 */

/*!
 * @brief Gets JTAG ID, the JTAG ID is 32bits width.
 *
 * @param base SIM base address.
 * @return The 32bits width JTAG ID.
 */
static inline uint32_t SIM_GetJTAGID(SIM_Type *base)
{
    return ((((uint32_t)(base->MSHID)) << 16U) | ((uint32_t)base->LSHID));
}

#if (defined(FSL_FEATURE_SIM_HAS_NVMOPT6_LOW_REGISTER) && FSL_FEATURE_SIM_HAS_NVMOPT6_LOW_REGISTER)
/*!
 * @brief Gets the trim vlaue of the bandgap inside the PMC module, the available range is 0 to 15.
 *
 * @param base SIM peripheral base address.
 * @return The trim value of PMC's bandgap, ranges from 0 to 15.
 */
static inline uint8_t SIM_GetPMCBandgapTrim(SIM_Type *base)
{
    return (uint8_t)((base->NVMOPT6_LOW & SIM_NVMOPT6_LOW_PMC_BGTRIM_MASK) >> SIM_NVMOPT6_LOW_PMC_BGTRIM_SHIFT);
}

/*!
 * @brief Gets the trim value of 200KHz Relaxation Osillator Frequency, the available range is 0 to 511.
 *
 * @param base SIM peripheral base address.
 * @return The trim value of 200 khz Relaxation Oscillator frequency, ranges from 0 to 511.
 */
static inline uint16_t SIM_Get200KHzROSCFreqTrim(SIM_Type *base)
{
    return (uint16_t)(base->NVMOPT6_LOW & SIM_NVMOPT6_LOW_ROSC_200K_FTRIM_MASK);
}
#endif /* FSL_FEATURE_SIM_HAS_NVMOPT6_LOW_REGISTER */

#if (defined(FSL_FEATURE_SIM_HAS_NVMOPT2H_REGISTER) && FSL_FEATURE_SIM_HAS_NVMOPT2H_REGISTER)
/*!
 * @brief Gets the trim value of 8 MHz Relaxation Oscillator Temperature.
 *
 * @param base SIM peripheral base address.
 * @return The trim value of 8 MHz Relaxation Oscillator Temperature.
 */
static inline uint8_t SIM_Get8MHzROSCTempTrim(SIM_Type *base)
{
    return (uint8_t)((base->NVMOPT2H & SIM_NVMOPT2H_ROSC_8M_TTRIM_MASK) >> SIM_NVMOPT2H_ROSC_8M_TTRIM_SHIFT);
}

/*!
 * @brief Gets the trim value of 8 MHz Relaxation Oscillator Frequency Trim.
 *
 * @param base SIM peripheral base address.
 * @return The trim value of 8 MHz Relaxation Oscillator Frequency Trim.
 */
static inline uint16_t SIM_Get8MHzROSCFreqTrim(SIM_Type *base)
{
    return (uint16_t)(base->NVMOPT2H & SIM_NVMOPT2H_ROSC_8M_FTRIM_MASK);
}
#endif /* FSL_FEATURE_SIM_HAS_NVMOPT2H_REGISTER */

#if (defined(FSL_FEATURE_SIM_HAS_NVMOPT2L_REGISTER) && FSL_FEATURE_SIM_HAS_NVMOPT2L_REGISTER)
/*!
 * @brief Gets the trim vlaue of the bandgap inside the PMC module, the available range is 0 to 15.
 *
 * @param base SIM peripheral base address.
 * @return The trim value of PMC's bandgap, ranges from 0 to 15.
 */
static inline uint8_t SIM_GetPMCBandgapTrim(SIM_Type *base)
{
    return (uint8_t)((base->NVMOPT2L & SIM_NVMOPT2L_PMC_BGTRIM_MASK) >> SIM_NVMOPT2L_PMC_BGTRIM_SHIFT);
}

#if (defined(FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_200K) && FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_200K)
/*!
 * @brief Gets the trim value of 200KHz Relaxation Osillator Frequency, the available range is 0 to 511.
 *
 * @param base SIM peripheral base address.
 * @return The trim value of 200 khz Relaxation Oscillator frequency, ranges from 0 to 511.
 */
static inline uint16_t SIM_Get200KHzROSCFreqTrim(SIM_Type *base)
{
    return (uint16_t)(base->NVMOPT2L & SIM_NVMOPT2L_ROSC_200K_FTRIM_MASK);
}
#endif /* FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_200K */

#if (defined(FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_32K) && FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_32K)
/*!
 * @brief Gets the trim value of 32KHz Relaxation Osillator Frequency.
 *
 * @param base SIM peripheral base address.
 * @return The trim value of 32 khz Relaxation Oscillator frequency.
 */
static inline uint16_t SIM_Get32KHzROSCFreqTrim(SIM_Type *base)
{
    return (uint16_t)(base->NVMOPT2L & SIM_NVMOPT2L_ROSC_32K_FTRIM_MASK);
}
#endif /* FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_32K */
#endif /* FSL_FEATURE_SIM_HAS_NVMOPT2L_REGISTER */

#if (defined(FSL_FEATURE_SIM_HAS_NVMOPT3H_REGISTER) && FSL_FEATURE_SIM_HAS_NVMOPT3H_REGISTER)
/*!
 * @brief Gets the SAR ADC Bandgap Reference Capture.
 *
 * @param base SIM peripheral base address.
 * @return The SAR ADC Bandgap Reference Capture.
 */
static inline uint16_t SIM_GetSarAdcBandgapRefCap(SIM_Type *base)
{
    return (uint16_t)(base->NVMOPT3H & SIM_NVMOPT3H_SAR_VREFBG_TRIM_MASK);
}
#endif /* FSL_FEATURE_SIM_HAS_NVMOPT3H_REGISTER */
/*! @} */

/*!
 * @name Short Addressing Control Related Interfaces
 * @{
 */

/*!
 * @brief Sets the I/O short address location value which specifies the memory referenced through the I/O short address
 * mode.
 *
 * The I/O short address mode allows the instrution to specify the lower 6 bits of the address. And the upper 18 bits of
 * the address can be controlled by invoking this function.
 *
 * @note The pipeline delay between setting the related register set and using short I/O addrssing with the new value is
 * five cycles.
 *
 * @param base SIM base address.
 * @param u32IOShortAddressValue The value of I/O short address location, this address value should be 24 bits width.
 */
static inline void SIM_SetIOShortAddressValue(SIM_Type *base, uint32_t u32IOShortAddressValue)
{
    u32IOShortAddressValue >>= 6U;
    base->IOSAHI = (uint16_t)(u32IOShortAddressValue >> 16U) & 0x3U;
    base->IOSALO = (uint16_t)(u32IOShortAddressValue & 0xFFFFU);
}

/*! @} */

/*!
 * @name Software Control Interfaces
 * @{
 */

/*!
 * @brief Gets the software control data by the software control register index.
 *
 * @param base SIM base address.
 * @param eIndex SIM software control register index.
 * @return Software control registers value.
 */
static inline uint16_t SIM_GetSoftwareControlData(SIM_Type *base, sim_software_contrl_register_index_t eIndex)
{
    return (*((volatile uint16_t *)&(base->SCR0) + (uint16_t)eIndex));
}

/*!
 * @brief Sets the software control data by the software contorl register index, the data is for general-purpose use by
 * software.
 *
 * @param base SIM base address.
 * @param eIndex SIM software control register index.
 * @param u16Value Software control registers value.
 */
static inline void SIM_SetSoftwareControlData(SIM_Type *base,
                                              sim_software_contrl_register_index_t eIndex,
                                              uint16_t u16Value)
{
    (*((volatile uint16_t *)&(base->SCR0) + (uint16_t)eIndex)) = u16Value;
}

/*! @} */

/*!
 * @name Internal Peripheral Extend Control Interfaces
 * @{
 */

/*!
 * @brief Sets the operation mode of the OnCE clock, the available operation modes are always enabled and enabled when
 * the core TAP is enabled
 *
 * @param base SIM peripheral base address.
 * @param eOperationMode The operation mode of OnCE clock, please refer to @ref sim_onceclk_operation_mode_t.
 */
static inline void SIM_SetOnCEClockOperationMode(SIM_Type *base, sim_onceclk_operation_mode_t eOperationMode)
{
    if (eOperationMode == kSIM_OnCEClkAlwaysEnabled)
    {
        base->CTRL |= SIM_CTRL_ONCEEBL_MASK;
    }
    else
    {
        base->CTRL &= ~SIM_CTRL_ONCEEBL_MASK;
    }
}

/*!
 * @brief Sets the operation mode of DMA, such as disabled, enabled in run mode only, etc.
 *
 * @param base SIM peripheral base address.
 * @param eOperationMode The operation mode to be set, please refer to @ref sim_dma_operation_mode_t.
 */
static inline void SIM_SetDMAOperationMode(SIM_Type *base, sim_dma_operation_mode_t eOperationMode)
{
    base->CTRL = (base->CTRL & (~SIM_CTRL_DMAEBL_MASK)) | SIM_CTRL_DMAEBL(eOperationMode);
}

#if (defined(FSL_FEATURE_SIM_RSTAT_HAS_BOOT_MODE_STATUS_BIT_FIELD) && \
     FSL_FEATURE_SIM_RSTAT_HAS_BOOT_MODE_STATUS_BIT_FIELD)
/*!
 * @brief Gets the device's boot mode, the available boot modes are ROM boot and NVM flash boot.
 *
 * @param base SIM peripheral base address.
 * @return The device's boot mode, please refer to @ref sim_boot_mode_t.
 */
static inline sim_boot_mode_t SIM_GetBootMode(SIM_Type *base)
{
    sim_boot_mode_t eBootMode;

    if ((base->RSTAT & SIM_RSTAT_BOOT_MODE_STATUS_MASK) == SIM_RSTAT_BOOT_MODE_STATUS_MASK)
    {
        eBootMode = kSIM_BootFromROM;
    }
    else
    {
        eBootMode = kSIM_BootFromNVMFlash;
    }

    return eBootMode;
}
#endif /* FSL_FEATURE_SIM_RSTAT_HAS_BOOT_MODE_STATUS_BIT_FIELD */

#if (defined(FSL_FEATURE_SIM_MISC0_HAS_LPI2C1_TRIG_SEL_BIT_FIELD) && \
     FSL_FEATURE_SIM_MISC0_HAS_LPI2C1_TRIG_SEL_BIT_FIELD)
/*!
 * @brief Sets the trigger selection of lpi2c1, the available selections are master trigger and slave trigger.
 *
 * This function can be used to selection the LPI2C1 output trigger. If selected as master trigger, the LPI2C1 master
 * will generate an output trigger that can be connected to other peripherals on the device. If selected as slave
 * trigger, the LPI2C1 slave will generate an output trigger that can be connected to other peripherals on the device.
 *
 * @param base SIM peripheral base address.
 * @param eTriggerSelection The trigger selection to set, please refer to @ref sim_lpi2c_trigger_selection_t.
 */
static inline void SIM_SetLPI2C1TriggerSelection(SIM_Type *base, sim_lpi2c_trigger_selection_t eTriggerSelection)
{
    if (eTriggerSelection == kSIM_Lpi2cSlaveTrigger)
    {
        base->MISC0 &= ~SIM_MISC0_LPI2C1_TRIG_SEL_MASK;
    }
    else
    {
        base->MISC0 |= SIM_MISC0_LPI2C1_TRIG_SEL_MASK;
    }
}
#endif /* FSL_FEATURE_SIM_MISC0_HAS_LPI2C1_TRIG_SEL_BIT_FIELD */

#if (defined(FSL_FEATURE_SIM_MISC0_HAS_LPI2C0_TRIG_SEL_BIT_FIELD) && \
     FSL_FEATURE_SIM_MISC0_HAS_LPI2C0_TRIG_SEL_BIT_FIELD)
/*!
 * @brief Sets the trigger selection of lpi2c0, the available selections are master trigger and slave trigger.
 *
 * This function can be used to selection the LPI2C0 output trigger. If selected as master trigger, the LPI2C0 master
 * will generate an output trigger that can be connected to other peripherals on the device. If selected as slave
 * trigger, the LPI2C0 slave will generate an output trigger that can be connected to other peripherals on the device.
 *
 * @param base SIM peripheral base address.
 * @param eTriggerSelection The trigger selection to set, please refer to @ref sim_lpi2c_trigger_selection_t.
 */

static inline void SIM_SetLPI2C0TriggerSelection(SIM_Type *base, sim_lpi2c_trigger_selection_t eTriggerSelection)
{
    if (eTriggerSelection == kSIM_Lpi2cSlaveTrigger)
    {
        base->MISC0 &= ~SIM_MISC0_LPI2C0_TRIG_SEL_MASK;
    }
    else
    {
        base->MISC0 |= SIM_MISC0_LPI2C0_TRIG_SEL_MASK;
    }
}
#endif /* FSL_FEATURE_SIM_MISC0_HAS_LPI2C0_TRIG_SEL_BIT_FIELD */

#if (defined(FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD) && FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD)
/*!
 * @brief Gets device currently operate mode, the possible result is normal operate mode or fast operate mode.
 *
 * @param base SIM peripheral base address.
 * @return Current device's operate mode.
 */
static inline sim_device_operate_mode_t SIM_GetDeviceOperateMode(SIM_Type *base)
{
    return (sim_device_operate_mode_t)(uint16_t)((base->MISC0 & SIM_MISC0_MODE_STAT_MASK) >> SIM_MISC0_MODE_STAT_SHIFT);
}

/*!
 * @brief Sets device operate mode, including normal operate mode and fast operate mode.
 *
 * @note The setting by invoking this function is valid after executing the software reset. To change the device
 * operation mode, the clock-related settings also need to be changed. Please use this API with caution.
 *
 * @param base SIM peripheral base address.
 * @param eOperateMode The operate mode to be set, please refer to @ref sim_device_operate_mode_t.
 */
static inline void SIM_SetDeviceOperateMode(SIM_Type *base, sim_device_operate_mode_t eOperateMode)
{
    if (eOperateMode == kSIM_NormalOperateMode)
    {
        base->MISC0 &= ~SIM_MISC0_FAST_MODE_MASK;
    }
    else
    {
        base->MISC0 |= SIM_MISC0_FAST_MODE_MASK;
    }
}
#endif /* FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD */

#if (defined(FSL_FEATURE_SIM_MISC0_HAS_SCTRL_REORDER_BIT_FIELD) && FSL_FEATURE_SIM_MISC0_HAS_SCTRL_REORDER_BIT_FIELD)
/*!
 * @brief Enables/Disables the ADC scan control register reorder feature.
 *
 * @param base SIM peripheral base address.
 * @param bEnable Used to control the ADC scan control register reorder feature.
 *              - \b true Enable the re-ordering of ADC scan control bits.
 *              - \b false ADC scan control register works in normal order.
 */
static inline void SIM_EnableADCScanControlReorder(SIM_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->MISC0 |= SIM_MISC0_SCTRL_REORDER_MASK;
    }
    else
    {
        base->MISC0 &= ~SIM_MISC0_SCTRL_REORDER_MASK;
    }
}
#endif /* FSL_FEATURE_SIM_MISC0_HAS_SCTRL_REORDER_BIT_FIELD */

/*!
 * @brief Sets master programmable interval timer
 *
 * @param base SIM peripheral base address.
 * @param eMasterPit The master PIT to be selected, please refer to @ref sim_master_pit_selection_t.
 */
static inline void SIM_SetMasterPIT(SIM_Type *base, sim_master_pit_selection_t eMasterPit)
{
    if (eMasterPit == kSIM_PIT0MasterPIT1Slave)
    {
        base->MISC0 &= ~SIM_MISC0_PIT_MSTR_MASK;
    }
    else
    {
        base->MISC0 |= SIM_MISC0_PIT_MSTR_MASK;
    }
}

#if (defined(FSL_FEATURE_SIM_HAS_BOOT_MODE_OVERRIDE_REGISTER) && FSL_FEATURE_SIM_HAS_BOOT_MODE_OVERRIDE_REGISTER)
/*!
 * @brief Sets the boot over ride mode, this API can be used to determine the boot option in the next reset excluding
 * POR.
 *
 * @param base SIM peripheral base address.
 * @param eMode THe boot over ride mode.
 */
static inline void SIM_SetBootOverRide(SIM_Type *base, sim_boot_override_mode_t eMode)
{
    base->BOOT_MODE_OVERRIDE = (base->BOOT_MODE_OVERRIDE & (~SIM_BOOT_MODE_OVERRIDE_BOOT_OVERRIDE_MASK)) |
                               SIM_BOOT_MODE_OVERRIDE_BOOT_OVERRIDE(eMode);
}
#endif /* FSL_FEATURE_SIM_HAS_BOOT_MODE_OVERRIDE_REGISTER */
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_SIM_H_*/
