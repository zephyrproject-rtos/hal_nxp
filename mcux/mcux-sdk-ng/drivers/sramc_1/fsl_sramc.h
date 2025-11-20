/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SRAMC_H_
#define FSL_SRAMC_H_

#include "fsl_common.h"

/*!
 * @addtogroup sramc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Defines SRAMC driver version. */
#define FSL_SRAMC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief SRAMC address mode.
 */
typedef enum _sramc_address_mode
{
    kSRAMC_AddressDataMux    = 0U, /*!< Address/Data MUX mode (ADMUX) */
    kSRAMC_AddressDataNonMux = 1U  /*!< Address/Data non-MUX mode (Non-ADMUX) */
} sramc_address_mode_t;

/*!
 * @brief SRAMC port size.
 */
typedef enum _sramc_port_size
{
    kSRAMC_PortSize8Bit  = 0U, /*!< 8-bit data port size */
    kSRAMC_PortSize16Bit = 1U  /*!< 16-bit data port size */
} sramc_port_size_t;

/*!
 * @brief SRAMC ADV# polarity.
 */
typedef enum _sramc_adv_polarity
{
    kSRAMC_AdvActiveLow  = 0U, /*!< ADV# signal is active low */
    kSRAMC_AdvActiveHigh = 1U  /*!< ADV# signal is active high */
} sramc_adv_polarity_t;

/*!
 * @brief SRAMC prescaler.
 */
typedef enum _sramc_prescaler
{
    kSRAMC_Prescaler_1 = 0U, /*!< Time granularity is 1 hclk cycle */
    kSRAMC_Prescaler_2 = 1U, /*!< Time granularity is 2 hclk cycles */
    kSRAMC_Prescaler_3 = 2U, /*!< Time granularity is 3 hclk cycles */
    kSRAMC_Prescaler_4 = 3U  /*!< Time granularity is 4 hclk cycles */
} sramc_prescaler_t;

/*!
 * @brief SRAMC wait polarity.
 */
typedef enum _sramc_wait_polarity
{
    kSRAMC_WaitActiveLow  = 0U, /*!< Wait signal is active low */
    kSRAMC_WaitActiveHigh = 1U  /*!< Wait signal is active high */
} sramc_wait_polarity_t;

/*!
 * @brief SRAMC wait pin mux.
 */
typedef enum _sramc_wait_pin_mux
{
    kSRAMC_WaitPinMux_0 = 0U, /*!< Wait pin 0 is muxed */
    kSRAMC_WaitPinMux_1 = 1U, /*!< Wait pin 1 is muxed */
    kSRAMC_WaitPinMux_2 = 2U, /*!< Wait pin 2 is muxed */
    kSRAMC_WaitPinMux_3 = 3U  /*!< Wait pin 3 is muxed */
} sramc_wait_pin_mux_t;

/*!
 * @brief SRAMC wait mode.
 */
typedef enum _sramc_wait_mode
{
    kSRAMC_WaitMode_Level = 0U, /*!< Wait signal is determined by level of wait pin. */
    kSRAMC_WaitMode_LevelAndCounter =
        1U, /*!< Wait signal is determined by both conditions of wait pin level and internal wait counter */
    kSRAMC_WaitMode_LevelOrCounter =
        2U, /*!< Wait signal is determined by any condition of wait pin level and internal wait counter */
    kSRAMC_WaitMode_Edge = 4U, /*!< Wait signal is determined by edge of wait pin */
    kSRAMC_WaitMode_EdgeAndCounter =
        5U, /*!< Wait signal is determined by both conditions of wait pin edge and internal wait counter */
    kSRAMC_WaitMode_EdgeOrCounter =
        6U  /*!< Wait signal is determined by any condition of wait pin edge and internal wait counter. */
} sramc_wait_mode_t;

/*!
 * @brief SRAMC chip select.
 */
typedef enum _sramc_chip_select
{
    kSRAMC_ChipSelect0 = 1U << 0, /*!< Chip Select 0 */
    kSRAMC_ChipSelect1 = 1U << 1  /*!< Chip Select 1 */
} sramc_chip_select_t;

/*!
 * @brief SRAMC configuration structure.
 */
typedef struct _sramc_config
{
    sramc_chip_select_t chipSelect; /*!< Chip select to configure. Use bitwise OR to combine multiple chip selects. */
    /* SRAMC settings */
    bool funcClkAlwaysOn;      /*!< If true, functional clock is always enabled, otherwise the clock is off when no
                                * access.
                                */
    uint8_t busTimeoutCounter; /*!< AHB Bus Timeout Wait Cycle (BTO). Timeout = BTO * 1024 hclk cycles. Range: 0-255. */
    bool busTimeoutEnable;     /*!< AHB Bus Timeout Enable (BTOEN). */
    sramc_adv_polarity_t advPolarity; /*!< ADV# polarity (ADVP). */
    sramc_address_mode_t addressMode; /*!< Address mode (AM). ADMUX or Non-ADMUX. */
    sramc_port_size_t portSize;       /*!< Port Size (PS). 8-bit or 16-bit. */

    /* Access timing setting */
    sramc_prescaler_t prescaler; /*!< Prescaler timer (PRE). Sets time granularity for timing parameters. */
    uint8_t turnaroundTime;      /*!< Turnaround time (TA). Actual time is (TA+1) * granularity. Range: 0-15. */
    uint8_t addressHoldTime;     /*!< Address hold time (AH). Actual time is (AH+1) * granularity. Range: 0-15. */
    uint8_t addressSetupTime;    /*!< Address setup time (AS). Actual time is AS * granularity (min 1 cycle in ADMUX).
                                    Range: 0-15. */
    uint8_t ceHoldTime;          /*!< Chip Enable hold time (CEH). Actual time is CEH * granularity. Range: 0-15. */
    uint8_t ceSetupTime;         /*!< Chip Enable setup time (CES). Actual time is CES * granularity. Range: 0-15. */
    uint8_t readEnableHighTime;  /*!< Read Enable high time (REH). Actual time is (REH+1) * granularity. Range: 0-15. */
    uint8_t readEnableLowTime;   /*!< Read Enable low time (REL). Actual time is (REL+1) * granularity. Range: 0-63. */
    uint8_t writeEnableHighTime; /*!< Write Enable high time (WEH). Actual time is (WEH+1) * granularity. Range: 0-15.*/
    uint8_t writeEnableLowTime;  /*!< Write Enable low time (WEL). Actual time is (WEL+1) * granularity. Range: 0-63.*/

    /* wait mode setting*/
    bool waitModeEnable;                /*!< Wait mode enable (WM_EN). If true, SRAM access need to monitor wait pin. */
    sramc_wait_polarity_t waitPolarity; /*!< Wait pin polarity selection.  (WP_POL). */
    sramc_wait_pin_mux_t waitPinMux;    /*!< Wait pin mux selection. (WP_MUX). */
    sramc_wait_mode_t waitMode;         /*!< Wait mode selection (WM_SEL). */
} sramc_config_t;

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Gets the default configuration for the SRAMC.
 *
 * This function initializes the sramc_config_t structure with default values.
 * The default value are:
 * @code
 *   config->chipSelect = kSRAMC_ChipSelect0 | kSRAMC_ChipSelect1;
 *   config->funcClkAlwaysOn = true;
 *   config->busTimeoutCounter = 0U;
 *   config->busTimeoutEnable  = false;
 *   config->advPolarity       = kSRAMC_AdvActiveLow;
 *   config->addressMode       = kSRAMC_AddressDataMux;
 *   config->portSize          = kSRAMC_PortSize16Bit;
 *   config->prescaler         = kSRAMC_Prescaler_4;
 *   config->turnaroundTime   = 1U;
 *   config->addressHoldTime  = 1U;
 *   config->addressSetupTime = 4U;
 *   config->ceHoldTime        = 1U;
 *   config->ceSetupTime       = 1U;
 *   config->readEnableHighTime = 9U;
 *   config->readEnableLowTime   = 0x10U;
 *   config->writeEnableHighTime = 0xAU;
 *   config->writeEnableLowTime  = 0x1FU;
 *   config->waitModeEnable = true;
 *   config->waitPolarity = kSRAMC_WaitActiveLow;
 *   config->waitPinMux = kSRAMC_WaitPinMux_0;
 *   config->waitMode = kSRAMC_WaitMode_Edge;
 * @endcode
 *
 * @param config Pointer to the sramc_config_t structure to be initialized.
 */
void SRAMC_GetDefaultConfig(sramc_config_t *config);

/*!
 * @brief Initializes the SRAMC peripheral.
 *
 * This function configures the SRAMC controller based on the provided configuration.
 *
 * @param base Pointer to the AHB SRMAC module instance structure.
 * @param config Pointer to the SRAMC configuration structure (sramc_config_t).
 */
void SRAMC_Init(AHB_SRAMC_Type *base, const sramc_config_t *config);

/*!
 * @brief De-initializes the SRAMC peripheral.
 *
 * This function resets the SRAMC configuration registers to their reset values.
 *
 * @param base Pointer to the AHB SRMAC module instance structure.
 */
void SRAMC_Deinit(AHB_SRAMC_Type *base);

/*! @}*/

/*!
 * @name Register Locking
 * @{
 */

/*!
 * @brief Lock SRAMC registers.
 *
 * @param base AHB SRMAC module instance structure.
 * @param locked If true, all the SRAMC registers are not allowed to write except Lock register. If false, all the SRAMC
 * registers are allowed to write.
 */
static inline void SRAMC_LockRegisters(AHB_SRAMC_Type *base, bool locked)
{
    assert(base != NULL);

    if (locked)
    {
        base->LR |= AHB_SRAMC_LR_LOCK_MASK;
    }
    else
    {
        base->LR &= ~AHB_SRAMC_LR_LOCK_MASK;
    }
}

/*! @}*/

/*!
 * @name SRAMC timing paramters calculation
 * @{
 */

/*!
 * @brief Calculates the SRAMC register timing field value from nanoseconds.
 *
 * This helper function converts a time duration specified in nanoseconds (`time_ns`) into the corresponding register
 * field value based on the SRAMC functional clock frequency (`hclkFreqHz`) and the selected prescaler
 * (`prescalerValue`, corresponding to SRAMCR1[PRE] setting 0-3). It accounts for the '+1' logic required by some timing
 * fields (e.g., REL, REH, WEL, WEH, AH, TA) as specified in the reference manual. It also checks if the calculated
 * value fits within the specified bit-width of the target register field.
 *
 * @param hclkFreqHz  Frequency of the hclk clock source for SRAMC in Hz.
 * @param time_ns     Desired time duration in nanoseconds.
 * @param prescalerValue The value written to the SRAMCR1[PRE] field (0=1 cycle, 1=2 cycles, 2=3 cycles, 3=4 cycles
 * granularity).
 * @param addOneCycle   Set to `true` if the register field represents (N+1) * granularity (e.g., for REL, REH, etc.),
 * `false` otherwise (e.g., for CES, CEH).
 * @param fieldWidth    The number of bits available for the target register field (e.g., 6 for WEL, 4 for CEH).
 * @param result        Pointer to store the calculated register field value.
 *
 * @return
 *  - `kStatus_Success`: Calculation successful.
 *  - `kStatus_InvalidArgument`: If `hclkFreqHz` is 0, or if the calculated value exceeds the capacity of the
 * `fieldWidth`.
 */
status_t SRAMC_CalculateTimingValue(uint32_t hclkFreqHz,
                                    uint32_t time_ns,
                                    uint32_t prescalerValue,
                                    bool addOneCycle,
                                    uint8_t fieldWidth,
                                    uint32_t *result);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_SRAMC_H_ */