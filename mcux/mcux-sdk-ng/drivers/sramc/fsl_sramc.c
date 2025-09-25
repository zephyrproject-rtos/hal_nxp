/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sramc.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.sramc"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Gets the default configuration for the SRAMC.
 *
 * This function initializes the sramc_config_t structure with default values.
 * The default value are:
 * code
 *   config->turnaroundTime = 1U;
 *   config->addressHoldTime = 1U;
 *   config->addressSetupTime = 4U;
 *   config->ceHoldTime = 1U;
 *   config->ceSetupTime = 1U;
 *   config->advPolarity = kSRAMC_AdvActiveLow;
 *   config->addressMode = kSRAMC_AddressDataNonMux;
 *   config->portSize = kSRAMC_PortSize16Bit;
 *   config->busTimeoutEnable = false;
 *   config->busTimeoutCounter = 0U;
 *   config->prescaler = kSRAMC_Prescaler_4;
 *   config->readEnableHighTime = 9U;
 *   config->readEnableLowTime = 0X10U;
 *   config->writeEnableHighTime = 0xAU;
 *   config->writeEnableLowTime = 0x1FU;
 * endcode
 *
 * param config Pointer to the sramc_config_t structure to be initialized.
 */
void SRAMC_GetDefaultConfig(sramc_config_t *config)
{
    /* Initializes the configure structure to zero. */
    assert(config != NULL);

    config->turnaroundTime   = 1U;
    config->addressHoldTime  = 1U;
    config->addressSetupTime = 4U;
    config->ceHoldTime        = 1U;
    config->ceSetupTime       = 1U;
    config->advPolarity       = kSRAMC_AdvActiveLow;
    config->addressMode       = kSRAMC_AddressDataMux;
    config->portSize          = kSRAMC_PortSize16Bit;
    config->busTimeoutEnable  = false;
    config->busTimeoutCounter = 0U;
    config->prescaler         = kSRAMC_Prescaler_4;
    config->readEnableHighTime = 9U;
    config->readEnableLowTime   = 0x10U;
    config->writeEnableHighTime = 0xAU;
    config->writeEnableLowTime  = 0X1FU;
    
}

/*!
 * brief Initializes the SRAMC peripheral.
 *
 * This function configures the SRAMC controller based on the provided configuration.
 *
 * param base Pointer to the  WAKEUP Domain Block Control module instance structure.
 * param config Pointer to the SRAMC configuration structure (sramc_config_t).
 */
void SRAMC_Init(BLK_CTRL_WAKEUPMIX_Type *base, const sramc_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint32_t sramcr0 = 0U;
    uint32_t sramcr1 = 0U;

    /* Configure SRAMCR0 register */
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_TA(config->turnaroundTime);
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_AH(config->addressHoldTime);
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_AS(config->addressSetupTime);
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_CEH(config->ceHoldTime);
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_CES(config->ceSetupTime);
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_ADVP(config->advPolarity);
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_AM(config->addressMode);
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_PS(config->portSize);
    sramcr0 |= config->busTimeoutEnable ? BLK_CTRL_WAKEUPMIX_SRAMCR0_BTOEN(1U) : 0U;
    sramcr0 |= BLK_CTRL_WAKEUPMIX_SRAMCR0_BTO(config->busTimeoutCounter);

    /* Configure SRAMCR1 register */
    sramcr1 |= BLK_CTRL_WAKEUPMIX_SRAMCR1_PRE(config->prescaler);
    sramcr1 |= BLK_CTRL_WAKEUPMIX_SRAMCR1_REH(config->readEnableHighTime);
    sramcr1 |= BLK_CTRL_WAKEUPMIX_SRAMCR1_REL(config->readEnableLowTime);
    sramcr1 |= BLK_CTRL_WAKEUPMIX_SRAMCR1_WEH(config->writeEnableHighTime);
    sramcr1 |= BLK_CTRL_WAKEUPMIX_SRAMCR1_WEL(config->writeEnableLowTime);

    /* Write to registers */
    base->SRAMCR0 = sramcr0;
    base->SRAMCR1 = sramcr1;
}

/*!
 * brief De-initializes the SRAMC peripheral.
 *
 * This function resets the SRAMC configuration registers to their reset values.
 *
 * param base Pointer to the  WAKEUP Domain Block Control module instance structure.
 */
void SRAMC_Deinit(BLK_CTRL_WAKEUPMIX_Type *base)
{
    assert(base != NULL);

    /* Reset SRAMCR0 and SRAMCR1 registers */
    base->SRAMCR0 = 0U; /* Default value after reset */
    base->SRAMCR1 = 0U; /* Default value after reset */
}

/*!
 * brief Calculates the SRAMC register timing field value from nanoseconds.
 *
 * This helper function converts a time duration specified in nanoseconds (`time_ns`) into the corresponding register
 * field value based on the SRAMC functional clock frequency (`hclkFreqHz`) and the selected prescaler
 * (`prescalerValue`, corresponding to SRAMCR1[PRE] setting 0-3). It accounts for the '+1' logic required by some timing
 * fields (e.g., REL, REH, WEL, WEH, AH, TA) as specified in the reference manual. It also checks if the calculated
 * value fits within the specified bit-width of the target register field.
 *
 * param hclkFreqHz  Frequency of the hclk clock source for SRAMC in Hz.
 * param time_ns     Desired time duration in nanoseconds.
 * param prescalerValue The value written to the SRAMCR1[PRE] field (0=1 cycle, 1=2 cycles, 2=3 cycles, 3=4 cycles granularity).
 * param addOneCycle   Set to `true` if the register field represents (N+1) * granularity (e.g., for REL, REH, etc.), `false` otherwise (e.g., for CES, CEH).
 * param fieldWidth    The number of bits available for the target register field (e.g., 6 for WEL, 4 for CEH).
 * param result        Pointer to store the calculated register field.
 * value.
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
                                    uint32_t *result)
{
    assert(result != NULL);

    if (hclkFreqHz == 0U)
    {
        return kStatus_InvalidArgument;
    }

    uint32_t cycleTime_ns = 1000000000U / hclkFreqHz;             /* Clock cycle time in nanoseconds */
    assert(cycleTime_ns > 0U);
    assert(prescalerValue < UINT32_MAX -1U);
    assert(prescalerValue + 1U < UINT32_MAX / cycleTime_ns);
    uint32_t granularity  = (prescalerValue + 1U) * cycleTime_ns; /* Time granularity in nanoseconds */
    uint32_t calculatedValue;

    /* Add one clock cycle if required */
    assert(time_ns < UINT32_MAX - granularity);
    if (addOneCycle)
    {
        calculatedValue = (time_ns + granularity - 1U) / granularity - 1U;
    }
    else
    {
        calculatedValue = (time_ns + granularity - 1U) / granularity;
    }

    /* Check if the calculated value exceeds the field width */
    if (calculatedValue >= (1UL << fieldWidth))
    {
        return kStatus_InvalidArgument;
    }

    *result = calculatedValue;
    return kStatus_Success;
}