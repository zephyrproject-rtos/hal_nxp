/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_crc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_crc16"
#endif

/*! @brief Pointers to CRC bases for each instance. */
static CRC_Type *const s_CRCBases[] = CRC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map EDMA instance number to clock name. */
static const clock_ip_name_t s_crcClockName[] = CRC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Gets the instance from the base address.
 *
 * param base CRC peripheral base address
 *
 * return The CRC instance
 */
static uint32_t CRC_GetInstance(CRC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_CRCBases); instance++)
    {
        if (s_CRCBases[instance] == base)
        {
            break;
        }
    }
    assert(instance < ARRAY_SIZE(s_CRCBases));

    return instance;
}
/*!
 * brief Enables and configures the CRC peripheral module.
 *
 * This function enables the clock gate in the SIM module for the CRC peripheral.
 * It also configures the CRC module and starts a checksum computation by writing the seed.
 *
 * param base     CRC peripheral address.
 * param psConfig CRC module configuration structure.
 */
void CRC_Init(CRC_Type *base, const crc_config_t *psConfig)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* ungate clock */
    CLOCK_EnableClock(s_crcClockName[CRC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Write the CRC seed value. */
    if (psConfig->bSetSeed)
    {
        CRC_SetSeedValue(base, psConfig->u16CrcSeedValue);
    }
}

/*!
 * brief Disables and configures the CRC peripheral module.
 *
 * This function disables the clock gate in the SIM module for the CRC peripheral.
 * It also configures the CRC module and starts a checksum computation by writing the seed.
 *
 * param base     CRC peripheral address.
 */
void CRC_Deinit(CRC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* gate clock */
    CLOCK_DisableClock(s_crcClockName[CRC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Provide default CRC seed value configuration.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref CRC_Init
 * to use. Provides the configuration of commonly used CRC seed values. refer to @ref _crc_seed_value.
 *
 * param psConfig     CRC seed value configuration structure.
 */
void CRC_GetDefaultConfig(crc_config_t *psConfig)
{
    /* CRC-16-CCITT protocol. */
    psConfig->bSetSeed        = true;
    psConfig->u16CrcSeedValue = (uint16_t)kCRC_Crc16CCITT;
}

/*!
 * brief Set the CRC seed value.
 *
 * This function is help to write a 16 bit CRC seed value.
 *
 * param base            CRC peripheral address.
 * param u16CrcSeedValue The value of seed.
 */
void CRC_SetSeedValue(CRC_Type *base, uint16_t u16CrcSeedValue)
{
    /* Write high byte of initial seed value to CRCH. */
    base->CRCH = (u16CrcSeedValue >> 8U) & 0xFFU;

    /* Write low byte of initial seed value to CRCL. */
    base->CRCL = u16CrcSeedValue & 0xFFU;
}

/*!
 * brief Writes data to the CRC module.
 *
 * Writes input data buffer bytes to the CRC data register.
 * The configured type of transpose is applied.
 *
 * param base        CRC peripheral address.
 * param pu8Data     Input data stream, MSByte in data[0].
 * param u16DataSize Size in bytes of the input data buffer.
 * param bRefin      Invert when input calculations
 */
void CRC_WriteData(CRC_Type *base, const uint8_t *pu8Data, uint16_t u16DataSize, bool bRefin)
{
    uint16_t u16Tmp;
    /* Determine whether to transpose when writing data. */
    if (!bRefin)
    {
        while ((u16DataSize--) > 0U)
        {
            base->CRCL = *pu8Data++;
        }
    }
    else
    {
        while ((u16DataSize--) > 0U)
        {
            base->TRANSPOSE = *pu8Data++;
            u16Tmp          = base->TRANSPOSE;
            base->CRCL      = u16Tmp;
        }
    }
}

/*!
 * brief Reads a 16-bit checksum from the CRC module.
 *
 * Reads the CRC data register (either an intermediate or the final checksum).
 * The configured type of transpose and complement is applied.
 *
 * param base CRC peripheral address.
 * param bRefOut Invert the calculated CRC value as a whole.
 * return A 16-bit checksum with or without transposed configuration.
 */
uint16_t CRC_Get16bitResult(CRC_Type *base, bool bRefOut)
{
    uint16_t u16CrcL, u16CrcH;
    uint16_t u16Crc;

    u16CrcL = base->CRCL;
    u16CrcH = base->CRCH;
    /* Determine whether to transpose when outputting data. */
    if (bRefOut)
    {
        base->TRANSPOSE = u16CrcL;
        u16CrcL         = base->TRANSPOSE;
        base->TRANSPOSE = u16CrcH;
        u16CrcH         = base->TRANSPOSE;

        u16Crc = (u16CrcL << 8U) | u16CrcH;
    }
    else
    {
        u16Crc = (u16CrcH << 8U) | u16CrcL;
    }

    return u16Crc;
}
