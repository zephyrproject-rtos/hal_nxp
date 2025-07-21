/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_virt_wrapper.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.virt_wrapper"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/**
 * @brief Expand 16-bit mask to 32-bit mask.
 *
 * Each bit in mask is expanded to two bits, so 16-bit mask is expanded to 32-bit value
 * 0b0 is expanded to 0b00, 0b1 is expaned to 0b01.
 *
 * @param mask 16-bit mask
 * @return 32-bit mask
 */
static uint32_t VIRT_WRAPPER_ExpandMask(uint16_t mask);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t VIRT_WRAPPER_ExpandMask(uint16_t mask)
{
    uint32_t ret;

    ret = 0U;

    for (uint16_t i = 0U; i < 16U; i++)
    {
        if ((mask & ((uint16_t)1U << i)) != 0U)
        {
            ret |= (1UL << (i * 2U));
        }
    }

    return ret;
}

/*
 * Maps the pins to a specific slot.
 *
 * This function maps the pins of a port to specific slot. This function
 * can map multiple pins at one time, by using a bit mask.
 *
 * param base VIRT_WRAPPER peripheral base address.
 * param port The port index.
 * param pins The pins to be mapped.
 * param slot The slot to map to.
 *
 * return kStatus_Success on success, otherwise returns error code.
 */
status_t VIRT_WRAPPER_MapPins(VIRT_WRAPPER_Type *base, uint16_t port, uint32_t pins, virt_wrapper_slot_t slot)
{
    uint32_t reg0Index, reg1Index;

    reg0Index = ((uint32_t)port) * 2U;
    reg1Index = reg0Index + 1U;

    if (reg1Index >= VIRT_WRAPPER_REG_A_COUNT)
    {
        return kStatus_InvalidArgument;
    }
    else
    {
        uint16_t mask16;
        uint32_t mask32;
        uint32_t slotValue = 0x55555555UL * ((uint32_t)slot & 0x03U);

        /* Low 16 pins */
        mask16 = (uint16_t)(pins & 0xFFFFU);
        if (mask16 != 0U)
        {
            mask32 = VIRT_WRAPPER_ExpandMask(mask16);
            base->REG_A[reg0Index] = (base->REG_A[reg0Index] & ~(mask32 * 0x03U)) | slotValue;
        }

        /* High 16 pins */
        mask16 = (uint16_t)(pins >> 16);
        if (mask16 != 0U)
        {
            mask32 = VIRT_WRAPPER_ExpandMask(mask16);
            base->REG_A[reg1Index] = (base->REG_A[reg1Index] & ~(mask32 * 0x03U)) | slotValue;
        }

        return kStatus_Success;
    }
}

/*
 * Maps the input multiplexer to a specific slot.
 *
 * This function maps the input multiplexer to a specified slot.
 *
 * param base VIRT_WRAPPER peripheral base address.
 * param inputMuxIndex Index of the input multiplexer.
 * param slot The slot to map to.
 *
 * return kStatus_Success on success, otherwise returns error code.
 */
status_t VIRT_WRAPPER_MapInputMux(VIRT_WRAPPER_Type *base, uint32_t inputMuxIndex, virt_wrapper_slot_t slot)
{
    uint32_t regIndex;
    uint32_t bitShift;

    regIndex = inputMuxIndex / 16U;

    if (regIndex >= VIRT_WRAPPER_REG_B_COUNT)
    {
        return kStatus_InvalidArgument;
    }

    bitShift = (inputMuxIndex % 16U) * 2U;

    base->REG_B[regIndex] = (base->REG_B[regIndex] & ~(0x03UL << bitShift)) | ((uint32_t)slot << bitShift);

    return kStatus_Success;
}
