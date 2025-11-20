/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_PORT_H_
#define FSL_PORT_H_

#include "fsl_common.h"

/*!
 * @defgroup dsc_port PORT: Port Control
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_port"
#endif

/*! @name Driver version */
/*! @{ */
/*! @brief PORT driver version. */
#define FSL_PORT_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief Internal resistor pull feature selection.
 * @anchor _port_pull
 */
enum _port_pull
{
    kPORT_PullDisable = 0U, /*!< Internal pull-up/down resistor is disabled. */
    kPORT_PullDown    = 2U, /*!< Internal pull-down resistor is enabled. */
    kPORT_PullUp      = 3U, /*!< Internal pull-up resistor is enabled. */
};

/*!
 * @brief Internal resistor pull value selection.
 * @anchor _port_pull_value
 */
enum _port_pull_value
{
    kPORT_LowPullResistor  = 0U, /*!< Low internal pull resistor value is selected. */
    kPORT_HighPullResistor = 1U, /*!< High internal pull resistor value is selected. */
};

/*!
 * @brief Slew rate selection.
 * @anchor _port_slew_rate
 */
enum _port_slew_rate
{
    kPORT_FastSlewRate = 0U, /*!< Fast slew rate is configured. */
    kPORT_SlowSlewRate = 1U, /*!< Slow slew rate is configured. */
};

/*!
 * @brief Passive filter feature enable/disable.
 * @anchor _port_passive_filter_enable
 */
enum _port_passive_filter_enable
{
    kPORT_PassiveFilterDisable = 0U, /*!< Passive input filter is disabled. */
    kPORT_PassiveFilterEnable  = 1U, /*!< Passive input filter is enabled. */
};

/*!
 * @brief Open Drain feature enable/disable.
 * @anchor _port_open_drain_enable
 */
enum _port_open_drain_enable
{
    kPORT_OpenDrainDisable = 0U, /*!< Open drain output is disabled. */
    kPORT_OpenDrainEnable  = 1U, /*!< Open drain output is enabled. */
};

/*!
 * @brief Configures the drive strength.
 * @anchor _port_drive_strength
 */
enum _port_drive_strength
{
    kPORT_LowDriveStrength  = 0U, /*!< Low-drive strength is configured. */
    kPORT_HighDriveStrength = 1U, /*!< High-drive strength is configured. */
};

/*!
 * @brief Configures the drive strength1.
 * @anchor _port_drive_strength1
 */
enum _port_drive_strength1
{
    kPORT_NormalDriveStrength = 0U, /*!< Normal drive strength */
    kPORT_DoubleDriveStrength = 1U, /*!< Double drive strength */
};

/*!
 * @brief Input buffer disable/enable.
 * @anchor _port_input_buffer
 */
enum _port_input_buffer
{
    kPORT_InputBufferDisable = 0U, /*!< Digital input is disabled */
    kPORT_InputBufferEnable  = 1U, /*!< Digital input is enabled */
};

/*!
 * @brief Digital input is not inverted or it is inverted.
 * @anchor _port_invert_input
 */
enum _port_invet_input
{
    kPORT_InputNormal = 0U, /*!< Digital input is not inverted */
    kPORT_InputInvert = 1U, /*!< Digital input is inverted */
};

/*!
 * @brief Unlock/lock the pin control register field[15:0].
 * @anchor _port_lock_register
 */
enum _port_lock_register
{
    kPORT_UnlockRegister = 0U, /*!< Pin Control Register fields [15:0] are not locked. */
    kPORT_LockRegister   = 1U, /*!< Pin Control Register fields [15:0] are locked. */
};

/*!
 * @brief Pin mux selection
 * @anchor _port_mux
 */
typedef enum _port_mux
{
    kPORT_MuxAlt0             = 0U,  /*!< Chip-specific */
    kPORT_MuxAlt1             = 1U,  /*!< Chip-specific */
    kPORT_MuxAlt2             = 2U,  /*!< Chip-specific */
    kPORT_MuxAlt3             = 3U,  /*!< Chip-specific */
    kPORT_MuxAlt4             = 4U,  /*!< Chip-specific */
    kPORT_MuxAlt5             = 5U,  /*!< Chip-specific */
    kPORT_MuxAlt6             = 6U,  /*!< Chip-specific */
    kPORT_MuxAlt7             = 7U,  /*!< Chip-specific */
    kPORT_MuxAlt8             = 8U,  /*!< Chip-specific */
    kPORT_MuxAlt9             = 9U,  /*!< Chip-specific */
    kPORT_MuxAlt10            = 10U, /*!< Chip-specific */
    kPORT_MuxAlt11            = 11U, /*!< Chip-specific */
    kPORT_MuxAlt12            = 12U, /*!< Chip-specific */
    kPORT_MuxAlt13            = 13U, /*!< Chip-specific */
    kPORT_MuxAlt14            = 14U, /*!< Chip-specific */
    kPORT_MuxAlt15            = 15U, /*!< Chip-specific */
} port_mux_t;

/*! @brief PORT pin configuration structure */
typedef struct _port_pin_config
{
    uint16_t pullSelect : 2; /*!< No-pull/pull-down/pull-up select, see @ref _port_pull. */
    uint16_t pullValueSelect : 1; /*!< Pull value select, see @ref _port_pull_value. */
    uint16_t slewRate : 1; /*!< Fast/slow slew rate configure, see @ref _port_slew_rate. */
    uint16_t passiveFilterEnable : 1; /*!< Passive filter enable/disable, see @ref _port_passive_filter_enable. */
    uint16_t openDrainEnable : 1; /*!< Open drain enable/disable, see @ref _port_open_drain_enable. */
    uint16_t driveStrength : 1; /*!< Fast/slow drive strength configure, see @ref _port_drive_strength. */
    uint16_t driveStrength1 : 1; /*!< Normal/Double drive strength enable/disable, see @ref _port_drive_strength1. */
    uint16_t mux : 4; /*!< Pin mux configure, see @ref _port_mux. */
    uint16_t inputBuffer : 1; /*!< Input buffer configure, see @ref _port_input_buffer. */
    uint16_t invertInput : 1; /*!< Invert input configure, see @ref _port_invet_input. */
    uint16_t : 1;
    uint16_t lockRegister : 1; /*!< Lock/unlock the PCR field[15:0], see @ref _port_lock_register. */
} port_pin_config_t;

/*! @brief PORT voltage range. */
typedef enum _port_voltage_range
{
    kPORT_VoltageRange1Dot71V_3Dot6V = 0x0U, /*!< Port voltage range is 1.71 V - 3.6 V. */
    kPORT_VoltageRange2Dot70V_3Dot6V = 0x1U, /*!< Port voltage range is 2.70 V - 3.6 V. */
} port_voltage_range_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*! @name Configuration */
/*! @{ */

/*!
 * @brief Sets the port PCR register.
 *
 * @param base   PORT peripheral base pointer.
 * @param pin    PORT pin number.
 * @param config PORT PCR register configuration structure.
 */
static inline void PORT_SetPinConfig(PORT_Type *base, uint8_t pin, const port_pin_config_t *config)
{
    assert(NULL != config);
    base->PCR[pin] = *((const uint16_t *)(const void *)config);
}

/*!
 * @brief Sets the port PCR register for multiple pins.
 *
 * @param base   PORT peripheral base pointer.
 * @param mask   The pins to be configured. For example, for pin 0 and pin 1, mask = (1<<0) | (1<<1)
 * @param config PORT PCR register configuration structure.
 */
static inline void PORT_SetMultiplePinsConfig(PORT_Type *base, uint32_t mask, const port_pin_config_t *config)
{
    assert(config);

    uint16_t pcrl = *((const uint16_t *)(const void *)config);

    if (0U != (mask & 0xffffU))
    {
        base->GPCLR = ((mask & 0xffffU) << 16) | pcrl;
    }
    if (0U != (mask >> 16))
    {
        base->GPCHR = (mask & 0xffff0000U) | pcrl;
    }
}

/*!
 * @brief Configures the port voltage range.
 *
 * @param base PORT peripheral base pointer
 * @param range port voltage range
 */
static inline void PORT_SecletPortVoltageRange(PORT_Type *base, port_voltage_range_t range)
{
    base->CONFIG = (uint32_t)range;
}

/*!
 * @brief Configures the pin muxing.
 *
 * @param base  PORT peripheral base pointer.
 * @param pin   PORT pin number.
 * @param mux   pin muxing slot selection.
 */
static inline void PORT_SetPinMux(PORT_Type *base, uint8_t pin, port_mux_t mux)
{
    base->PCR[pin] = (base->PCR[pin] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(mux);
}

/*!
 * @brief Configures the port pin drive strength.
 *
 * @param base      PORT peripheral base pointer.
 * @param pin       PORT pin number.
 * @param strength  PORT pin drive strength
 *        - #kPORT_LowDriveStrength = 0U - Low-drive strength is configured.
 *        - #kPORT_HighDriveStrength = 1U - High-drive strength is configured.
 */
static inline void PORT_SetPinDriveStrength(PORT_Type *base, uint8_t pin, uint8_t strength)
{
    base->PCR[pin] = (base->PCR[pin] & ~PORT_PCR_DSE_MASK) | PORT_PCR_DSE(strength);
}

/*!
 * @brief Enables the port pin double drive strength.
 *
 * @param base      PORT peripheral base pointer.
 * @param pin       PORT pin number.
 * @param enable  PORT pin drive strength configuration.
 */
static inline void PORT_EnablePinDoubleDriveStrength(PORT_Type *base, uint8_t pin, bool enable)
{
    if (enable)
    {
        base->PCR[pin] |= PORT_PCR_DSE1_MASK;
    }
    else
    {
        base->PCR[pin] &= ~PORT_PCR_DSE1_MASK;
    }
}

/*!
 * @brief Configures the port pin pull value.
 *
 * @param base      PORT peripheral base pointer.
 * @param pin       PORT pin number.
 * @param value  PORT pin pull value
 *        - #kPORT_LowPullResistor = 0U - Low internal pull resistor value is selected.
 *        - #kPORT_HighPullResistor = 1U - High internal pull resistor value is selected.
 */
static inline void PORT_SetPinPullValue(PORT_Type *base, uint8_t pin, uint8_t value)
{
    base->PCR[pin] = (base->PCR[pin] & ~PORT_PCR_PV_MASK) | PORT_PCR_PV(value);
}
/*! @}*/

/*!
 * @name EFT
 * {
 */

/*!
 * @brief Get EFT detect flags.
 *
 * @param base PORT peripheral base pointer
 * @return EFT detect flags
 */
static inline uint32_t PORT_GetEFTDetectFlags(PORT_Type *base)
{
    return base->EDFR;
}

/*!
 * @brief Enable EFT detect interrupts.
 *
 * @param base PORT peripheral base pointer
 * @param interrupt EFT detect interrupt
 */
static inline void PORT_EnableEFTDetectInterrupts(PORT_Type *base, uint32_t interrupt)
{
    base->EDIER |= interrupt;
}

/*!
 * @brief Disable EFT detect interrupts.
 *
 * @param base PORT peripheral base pointer
 * @param interrupt EFT detect interrupt
 */
static inline void PORT_DisableEFTDetectInterrupts(PORT_Type *base, uint32_t interrupt)
{
    base->EDIER &= ~interrupt;
}

/*!
 * @brief Clear all low EFT detector.
 *
 * @note : Port B and Port C pins share the same EFT detector clear control from PORTC_EDCR register. Any write to the
 * PORTB_EDCR does not take effect.
 * @param base PORT peripheral base pointer
 * @param interrupt EFT detect interrupt
 */
static inline void PORT_ClearAllLowEFTDetectors(PORT_Type *base)
{
    base->EDCR |= PORT_EDCR_EDLC_MASK;
    base->EDCR &= ~PORT_EDCR_EDLC_MASK;
}

/*!
 * @brief Clear all high EFT detector.
 *
 * @param base PORT peripheral base pointer
 * @param interrupt EFT detect interrupt
 */
static inline void PORT_ClearAllHighEFTDetectors(PORT_Type *base)
{
    base->EDCR |= PORT_EDCR_EDHC_MASK;
    base->EDCR &= ~PORT_EDCR_EDHC_MASK;
}

/*! @}*/

/*!
 * @name Calibration
 * {
 */

/*!
 * @brief Set calibration values when low drive strength is configured
 *
 * Set calibration values for the PMOS and NMOS output drivers when
 * low drive strength is configured.
 *
 * @param base PORT peripheral base pointer
 * @param pcal Calibration value for PMOS output driver
 * @param ncal Calibration value for NMOS output driver
 */
static inline void PORT_SetLowDriveStrengthCalibration(PORT_Type *base, uint8_t pcal, uint8_t ncal)
{
    base->CALIB0 = PORT_CALIB0_PCAL(pcal) | PORT_CALIB0_NCAL(ncal);
}

/*!
 * @brief Set calibration values when high drive strength is configured
 *
 * Set calibration values for the PMOS and NMOS output drivers when
 * high drive strength is configured.
 *
 * @param base PORT peripheral base pointer
 * @param pcal Calibration value for PMOS output driver
 * @param ncal Calibration value for NMOS output driver
 */
static inline void PORT_SetHighDriveStrengthCalibration(PORT_Type *base, uint8_t pcal, uint8_t ncal)
{
    base->CALIB1 = PORT_CALIB1_PCAL(pcal) | PORT_CALIB1_NCAL(ncal);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_PORT_H_ */
