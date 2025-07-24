/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_siul2.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.siul2"
#endif

#define PORT_PIN_LEVEL_NOTCHANGED_U8 ((uint8_t)2) /**< @brief Not changed port pin logic. */
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Write to Input Multiplexed Signal Configuration Register
 *
 * This function configures the register with the provided in the
 * given structure.
 *
 * @param config the configuration structure
 */
void SIUL2_WriteIMCRConfiguration(const siul2_pin_settings_t *config)
{
    uint8_t inputMuxIterator;
    uint32_t imcrRegIdx;

    if (kPORT_INPUT_BUFFER_ENABLED == config->inputBuffer)
    {
        for (inputMuxIterator = 0U; inputMuxIterator < FEATURE_SIUL2_MAX_NUMBER_OF_INPUT; inputMuxIterator++)
        {
            /* Write to Input Mux register */
            imcrRegIdx = config->inputMuxReg[inputMuxIterator];
            /* Check if input mux information needs to be configured */
            if (kPORT_INPUT_MUX_NO_INIT != config->inputMux[inputMuxIterator])
            {
                if (imcrRegIdx < SIUL2_IMCR_COUNT)
                {
                    /* Config input signal */
                    config->base->IMCR[imcrRegIdx % SIUL2_IMCR_COUNT] =
                        SIUL2_IMCR_SSS(config->inputMux[inputMuxIterator]);
                }
            }
        }
    }
}

/*!
 * @brief Write to Device configuration module Register
 *
 * This function configures the adc muxing mode with the provided in the
 * given structure.
 *
 * @param config the configuration structure
 */
void SIUL2_WriteDCMConfiguration(const siul2_pin_settings_t *config)
{
    uint32_t dcmrwf4RegValue;
    uint8_t iterator;
    uint32_t adcInterleaves;
    dcmrwf4RegValue = DCM_GPR->DCMRWF4;

    for (iterator = 0; iterator < FEATURE_ADC_INTERLEAVE_MAX_MUX_MODE; iterator++)
    {
        adcInterleaves = (uint32_t)config->adcInterleaves[iterator];
        if ((uint32_t)kMUX_MODE_NOT_AVAILABLE != adcInterleaves)
        {
            if (0U == (adcInterleaves & DCM_DCMRWF4_ADC_INTERLEAVE_MASK))
            {
                /* Clear ADC Interleave bit */
                dcmrwf4RegValue &= ((~DCM_DCMRWF4_ADC_INTERLEAVE_MASK) | adcInterleaves);
            }
            else
            {
                /* Set ADC Interleave bit */
                dcmrwf4RegValue |= adcInterleaves;
            }
        }
    }

    DCM_GPR->DCMRWF4 = dcmrwf4RegValue;
}

void SIUL2_PinInit(const siul2_pin_settings_t *config)
{
    uint32_t pinsValues = 0U;

    assert(config != 0U);
    assert(config->pinPortIdx < SIUL2_MSCR_COUNT);

    if (config->pullConfig != kPORT_INTERNAL_PULL_NOT_ENABLED)
    {
        pinsValues |= SIUL2_MSCR_PUE(1);
        pinsValues |= SIUL2_MSCR_PUS(config->pullConfig);
    }

    if (kPORT_OUTPUT_BUFFER_NOT_AVAILABLE != config->outputBuffer)
    {
        pinsValues |= SIUL2_MSCR_OBE(config->outputBuffer);
    }

    if (kPORT_INVERT_NOT_AVAILABLE != config->invert)
    {
        pinsValues |= SIUL2_MSCR_INV(config->invert);
    }

    if (kPORT_PULL_KEEP_NOT_AVAILABLE != config->pullKeep)
    {
        pinsValues |= SIUL2_MSCR_PKE(config->pullKeep);
    }

    if (kPORT_DRIVE_STRENTGTH_NOT_AVAILABLE != config->driveStrength)
    {
        pinsValues |= SIUL2_MSCR_DSE(config->driveStrength);
    }

    if (kPORT_INPUT_FILTER_NOT_AVAILABLE != config->inputFilter)
    {
        pinsValues |= SIUL2_MSCR_IFE(config->inputFilter);
    }

    if (kPORT_INPUT_BUFFER_NOT_AVAILABLE != config->inputBuffer)
    {
        pinsValues |= SIUL2_MSCR_IBE(config->inputBuffer);
    }
    if (kPORT_SLEW_RATE_NOT_AVAILABLE != config->slewRateCtrlSel)
    {
        pinsValues |= SIUL2_MSCR_SRC(config->slewRateCtrlSel);
    }
    if (kPORT_SAFE_MODE_NOT_AVAILABLE != config->safeMode)
    {
        pinsValues |= SIUL2_MSCR_SMC(config->safeMode);
    }
    pinsValues |= SIUL2_MSCR_SSS(config->mux);

    /* Configure initial value for GPIO pin in GPIO mux */
    if ((kPORT_MUX_AS_GPIO == config->mux) && (kPORT_OUTPUT_BUFFER_ENABLED == config->outputBuffer))
    {
        /* If the value is low or high */
        if (config->initValue != PORT_PIN_LEVEL_NOTCHANGED_U8)
        {
            /* Write the value into GPDO register */
            SIUL2_PORT_WRITE8(SIUL2_GPDO_ADDR(config->base, (uint16_t)config->pinPortIdx), config->initValue);
        }
    }

    /* Write to Multiplexed Signal Configuration Register */
    config->base->MSCR[config->pinPortIdx] = pinsValues;

    /* Write to Input Multiplexed Signal Configuration Register */
    SIUL2_WriteIMCRConfiguration(config);

    /* Write to DCM GPR Register to config adc interleave mux mode */
    SIUL2_WriteDCMConfiguration(config);
}

/* Reverse bit order in each halfword independently */
static uint16_t SIUL2_Reverse_Bit_16(uint16_t value)
{
    uint8_t i;
    uint16_t ret  = 0U;
    uint32_t temp = 0U;

    for (i = 0U; i < 8U; i++)
    {
        temp = (((value >> i) & 1U) << (15U - i)) | (((value << i) & 0x8000U) >> (15U - i));
        ret |= (uint16_t)(temp & 0xFFFFU); 
    }

    return ret;
}

void SIUL2_SetPinInputBuffer(SIUL2_Type *base, uint32_t pin, bool enable, uint32_t inputMuxReg, siul2_port_inputmux_t inputMux)
{
    uint32_t imcrRegIdx = inputMuxReg;
    uint32_t imcrVal;
    /* Enable/disable input buffer for input signal */
    base->MSCR[pin] &= ~SIUL2_MSCR_IBE_MASK;
    base->MSCR[pin] |= SIUL2_MSCR_IBE(enable ? 1UL : 0UL);

    imcrVal  = base->IMCR[imcrRegIdx % SIUL2_IMCR_COUNT];
    imcrVal &= ~SIUL2_IMCR_SSS_MASK;

    /* Check input mux to configure input signal */
    if (inputMux != kPORT_INPUT_MUX_NO_INIT)
    {
        if (imcrRegIdx < SIUL2_IMCR_COUNT)
        {
            /* Configure input mux */
            imcrVal |= SIUL2_IMCR_SSS(inputMux);
            base->IMCR[imcrRegIdx % SIUL2_IMCR_COUNT] = imcrVal;
        }
    }
    else
    {
        if (imcrRegIdx < SIUL2_IMCR_COUNT)
        {
            /* Configure input mux */
            base->IMCR[imcrRegIdx % SIUL2_IMCR_COUNT] = imcrVal;
        }
    }
}

void SIUL2_SetPinOutputBuffer(SIUL2_Type *base, uint32_t pin, bool enable, siul2_port_mux_t mux)
{
    /* Clear the OBE bit field */
    base->MSCR[pin] &= ~SIUL2_MSCR_OBE_MASK;
    /* Write the OBE bit field with enable */
    base->MSCR[pin] |= SIUL2_MSCR_OBE(enable ? 1UL : 0UL);

    /* Clear the SSS bit field */
    base->MSCR[pin] &= ~SIUL2_MSCR_SSS_MASK;
    /* Write the SSS bit field with mux */
    base->MSCR[pin] |= SIUL2_MSCR_SSS(mux);
}

void SIUL2_SetPinPullSel(SIUL2_Type *base, uint32_t pin, siul2_port_pull_config_t pullConfig)
{
    uint32_t regVal;

    switch (pullConfig)
    {
        case kPORT_INTERNAL_PULL_NOT_ENABLED:
        {
            /* Clear the Pull Enable bit field */
            base->MSCR[pin] &= ~SIUL2_MSCR_PUE_MASK;
            break;
        }

        case kPORT_INTERNAL_PULL_DOWN_ENABLED:
        {
            regVal = base->MSCR[pin];
            /* Set the Pull Enable bit field */
            regVal |= SIUL2_MSCR_PUE_MASK;
            /* Clear the Pull Select bit field */
            regVal &= ~SIUL2_MSCR_PUS_MASK;
            base->MSCR[pin] = regVal;
            break;
        }
        case kPORT_INTERNAL_PULL_UP_ENABLED:
        {
            regVal = base->MSCR[pin];
            /* Set the Pull Enable bit field */
            regVal |= SIUL2_MSCR_PUE_MASK;
            /* Set the Pull Select bit field */
            regVal |= SIUL2_MSCR_PUS_MASK;
            base->MSCR[pin] = regVal;
            break;
        }

        default:
            /* Invalid command */
            break;
    }
}

void SIUL2_SetPinDirection(SIUL2_Type *base, uint32_t pin, siul2_port_direction_t direction)
{
    switch (direction)
    {
        /* Direction pin IN */
        case kPORT_IN:
            base->MSCR[pin] &= ~SIUL2_MSCR_OBE_MASK;
            base->MSCR[pin] |= SIUL2_MSCR_IBE(1UL);
            break;
        /* Direction pin OUT */
        case kPORT_OUT:
            base->MSCR[pin] &= ~SIUL2_MSCR_IBE_MASK;
            base->MSCR[pin] |= SIUL2_MSCR_OBE(1UL);
            break;
        /* Direction pin IN OUT */
        case kPORT_IN_OUT:
            base->MSCR[pin] |= (SIUL2_MSCR_IBE_MASK | SIUL2_MSCR_OBE_MASK);
            break;
        /* Direction pin HI_Z */
        case kPORT_HI_Z:
            base->MSCR[pin] &= ~(SIUL2_MSCR_IBE_MASK | SIUL2_MSCR_OBE_MASK);
            break;
        default:
            /* Do nothing */
            break;
    }
}

void SIUL2_PortMaskWrite(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins, uint32_t mask)
{
    uint32_t maskRevL, pinsRevL;
    uint32_t maskRevH, pinsRevH;
    maskRevL = SIUL2_Reverse_Bit_16((uint16_t)(mask & 0x0000FFFFU));
    pinsRevL = SIUL2_Reverse_Bit_16((uint16_t)(pins & 0x0000FFFFU));
    maskRevH = SIUL2_Reverse_Bit_16((uint16_t)((mask & 0xFFFF0000U) >> 16U));
    pinsRevH = SIUL2_Reverse_Bit_16((uint16_t)((pins & 0xFFFF0000U) >> 16U));

    base->MPGPDO[(uint8_t)port * 2U] = (maskRevL << (uint32_t)16U) | pinsRevL;
    base->MPGPDO[(uint8_t)port * 2U + 1U]      = (maskRevH << (uint32_t)16U) | pinsRevH;
}

void SIUL2_PortSet(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins)
{
    SIUL2_PGPDO_REG_16_31(base, (uint8_t)port) |= SIUL2_Reverse_Bit_16((uint16_t)((pins & 0xFFFF0000U) >> 16U));
    SIUL2_PGPDO_REG_0_15(base, (uint8_t)port) |= SIUL2_Reverse_Bit_16((uint16_t)(pins & 0x0000FFFFU));
}

void SIUL2_PortClear(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins)
{
    SIUL2_PGPDO_REG_16_31(base, (uint8_t)port) &= ~SIUL2_Reverse_Bit_16((uint16_t)((pins & 0xFFFF0000U) >> 16U));
    SIUL2_PGPDO_REG_0_15(base, (uint8_t)port) &= ~SIUL2_Reverse_Bit_16((uint16_t)(pins & 0x0000FFFFU));
}

void SIUL2_PortToggle(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins)
{
    SIUL2_PGPDO_REG_16_31(base, (uint8_t)port) ^= SIUL2_Reverse_Bit_16((uint16_t)((pins & 0xFFFF0000U) >> 16U));
    SIUL2_PGPDO_REG_0_15(base, (uint8_t)port) ^= SIUL2_Reverse_Bit_16((uint16_t)(pins & 0x0000FFFFU));
}

void SIUL2_SetDmaInterruptConfig(SIUL2_Type *base, uint32_t req, siul2_interrupt_config_t config)
{
    /*Configure edge*/
    switch (config)
    {
        case kSIUL2_InterruptStatusFlagDisabled:
            base->IREER0 &= ~(1U << req);
            base->IFEER0 &= ~(1U << req);
            break;
        case kSIUL2_InterruptRisingEdge:
            base->IREER0 |= 1U << req;
            base->IFEER0 &= ~(1U << req);
            break;
        case kSIUL2_InterruptFallingEdge:
            base->IREER0 &= ~(1U << req);
            base->IFEER0 |= 1U << req;
            break;
        case kSIUL2_InterruptBothEdge:
            base->IREER0 |= 1U << req;
            base->IFEER0 |= 1U << req;
            break;
        default:
            break;
    }
}

void SIUL2_EnableExtInterrupt(SIUL2_Type *base, uint32_t req, siul2_interrupt_config_t config, int8_t filterCount)
{
    base->DIRER0 |= (1U << req);  /* Enable Int/DMA request. */
    base->DIRSR0 &= ~(1U << req); /* Select interrupt. */

    SIUL2_SetDmaInterruptConfig(base, req, config);

    SIUL2_SetGlitchFilterMaxCount(base, req, filterCount);
}

void SIUL2_EnableExtDma(SIUL2_Type *base, uint32_t req, siul2_interrupt_config_t config, int8_t filterCount)
{
    base->DIRER0 |= (1U << req); /* Enable Int/DMA request. */
    base->DIRSR0 |= (1U << req); /* Select DMA. */

    SIUL2_SetDmaInterruptConfig(base, req, config);

    SIUL2_SetGlitchFilterMaxCount(base, req, filterCount);
}

void SIUL2_EnableExtInterrupts(SIUL2_Type *base, uint32_t mask, siul2_interrupt_config_t config, int8_t filterCount)
{
    uint32_t i = 0U;
    base->DIRER0 |= mask;  /* Enable Int/DMA request. */
    base->DIRSR0 &= ~mask; /* Select interrupt. */

    for (; i < 32U; i++)
    {
        if ((mask & (1U << i)) != 0U)
        {
            SIUL2_SetDmaInterruptConfig(base, i, config);
            SIUL2_SetGlitchFilterMaxCount(base, i, filterCount);
        }
    }
}

void SIUL2_EnableExtDmaRequests(SIUL2_Type *base, uint32_t mask, siul2_interrupt_config_t config, int8_t filterCount)
{
    uint32_t i = 0U;
    base->DIRER0 |= mask; /* Enable Int/DMA request. */
    base->DIRSR0 |= mask; /* Select interrupt. */

    for (; i < 32U; i++)
    {
        if ((mask & (1U << i)) != 0U)
        {
            SIUL2_SetDmaInterruptConfig(base, i, config);
            SIUL2_SetGlitchFilterMaxCount(base, i, filterCount);
        }
    }
}
