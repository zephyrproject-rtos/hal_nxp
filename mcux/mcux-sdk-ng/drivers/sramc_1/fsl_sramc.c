/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sramc.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.sramc_1"
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
 * endcode
 *
 * param config Pointer to the sramc_config_t structure to be initialized.
 */
void SRAMC_GetDefaultConfig(sramc_config_t *config)
{
    assert(config != NULL);

    config->chipSelect = (sramc_chip_select_t)(((uint8_t)kSRAMC_ChipSelect0) | ((uint8_t)kSRAMC_ChipSelect1));
    /* SRAMC settings */
    config->funcClkAlwaysOn   = true;
    config->busTimeoutCounter = 0U;
    config->busTimeoutEnable  = false;
    config->advPolarity       = kSRAMC_AdvActiveLow;
    config->addressMode       = kSRAMC_AddressDataMux;
    config->portSize          = kSRAMC_PortSize16Bit;

    /* Access timing setting */
    config->prescaler           = kSRAMC_Prescaler_4;
    config->turnaroundTime      = 1U;
    config->addressHoldTime     = 1U;
    config->addressSetupTime    = 4U;
    config->ceHoldTime          = 1U;
    config->ceSetupTime         = 1U;
    config->readEnableHighTime  = 9U;
    config->readEnableLowTime   = 0x10U;
    config->writeEnableHighTime = 0xAU;
    config->writeEnableLowTime  = 0x1FU;

    /* wait mode setting*/
    config->waitModeEnable = true;
    config->waitPolarity   = kSRAMC_WaitActiveLow;
    config->waitPinMux     = kSRAMC_WaitPinMux_0;
    config->waitMode       = kSRAMC_WaitMode_Edge;
}

/*!
 * brief Initializes the SRAMC peripheral.
 *
 * This function configures the SRAMC controller based on the provided configuration.
 *
 * param base Pointer to the AHB SRMAC module instance structure.
 * param config Pointer to the SRAMC configuration structure (sramc_config_t).
 */
void SRAMC_Init(AHB_SRAMC_Type *base, const sramc_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    uint8_t i;

    SRAMC_LockRegisters(base, false); /* Unlock registers for configuration */

    /* Config SRAMC module access setting*/
    base->MCR = AHB_SRAMC_MCR_CG_DIS(config->funcClkAlwaysOn ? 1U : 0U) | AHB_SRAMC_MCR_BTO(config->busTimeoutCounter) |
                AHB_SRAMC_MCR_BTOEN(config->busTimeoutEnable ? 1U : 0U) | AHB_SRAMC_MCR_ADVP(config->advPolarity) |
                AHB_SRAMC_MCR_AM(config->addressMode) | AHB_SRAMC_MCR_PS(config->portSize);

    /* configures access timing and wait mode settings */
    for (i = 0; i < AHB_SRAMC_CFG0_CS_COUNT; i++)
    {
        if (((uint8_t)config->chipSelect & (1U << i)) != 0U)
        {
            base->CFG0_CS[i].CFG0_CS =
                AHB_SRAMC_CFG0_CS_PRE(config->prescaler) | AHB_SRAMC_CFG0_CS_TA(config->turnaroundTime) |
                AHB_SRAMC_CFG0_CS_AH(config->addressHoldTime) | AHB_SRAMC_CFG0_CS_AS(config->addressSetupTime) |
                AHB_SRAMC_CFG0_CS_CEH(config->ceHoldTime) | AHB_SRAMC_CFG0_CS_CES(config->ceSetupTime) |
                AHB_SRAMC_CFG0_CS_WP_POL(config->waitPolarity) | AHB_SRAMC_CFG0_CS_WP_MUX(config->waitPinMux) |
                AHB_SRAMC_CFG0_CS_WM_SEL(config->waitMode) | AHB_SRAMC_CFG0_CS_WM_EN(config->waitModeEnable ? 1U : 0U);

            base->CFG0_CS[i].CFG1_CS =
                AHB_SRAMC_CFG1_CS_REH(config->readEnableHighTime) | AHB_SRAMC_CFG1_CS_REL(config->readEnableLowTime) |
                AHB_SRAMC_CFG1_CS_WEH(config->writeEnableHighTime) | AHB_SRAMC_CFG1_CS_WEL(config->writeEnableLowTime);
        }
    }

    SRAMC_LockRegisters(base, true); /* lock configuration */
}

/*!
 * brief De-initializes the SRAMC peripheral.
 *
 * This function resets the SRAMC configuration registers to their reset values.
 *
 * param base Pointer to the AHB SRMAC module instance structure.
 */
void SRAMC_Deinit(AHB_SRAMC_Type *base)
{
    assert(base != NULL);

    SRAMC_LockRegisters(base, false);
    base->MCR |= AHB_SRAMC_MCR_SW_RST_MASK;
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
 * param prescalerValue The value written to the SRAMCR1[PRE] field (0=1 cycle, 1=2 cycles, 2=3 cycles, 3=4 cycles
 * granularity). param addOneCycle   Set to `true` if the register field represents (N+1) * granularity (e.g., for REL,
 * REH, etc.), `false` otherwise (e.g., for CES, CEH). param fieldWidth    The number of bits available for the target
 * register field (e.g., 6 for WEL, 4 for CEH). param result        Pointer to store the calculated register field.
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

    uint32_t cycleTime_ns = 1000000000U / hclkFreqHz; /* Clock cycle time in nanoseconds */
    assert(cycleTime_ns > 0U);
    assert(prescalerValue < UINT32_MAX - 1U);
    assert(prescalerValue + 1U < UINT32_MAX / cycleTime_ns);
    uint32_t granularity = (prescalerValue + 1U) * cycleTime_ns; /* Time granularity in nanoseconds */
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