/*
 * Copyright 2020 NXP
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
#define FSL_COMPONENT_ID "platform.drivers.dsc_crc"
#endif

/*! @internal brief Has data register with name CRC. */
#if defined(FSL_FEATURE_CRC_HAS_CRC_REG) && FSL_FEATURE_CRC_HAS_CRC_REG
#define DATA CRC
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map EDMA instance number to clock name. */
static const clock_ip_name_t s_crcClockName[] = CRC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
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
    CLOCK_EnableClock(s_crcClockName[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Configure CRC type of transpose of write data. */
    CRC_SetWriteTransposeType(base, psConfig->eTransposeIn);

    /* Configure CRC type of transpose of read data.*/
    CRC_SetReadTransposeType(base, psConfig->eTransposeOut);

    /* Configure complement of read CRC checksum. */
    CRC_EnableComplementChecksum(base, psConfig->bEnableComplementChecksum);

    /* Configure bit width of CRC protocol. */
    CRC_SetProtocolWidth(base, psConfig->eCrcBits);

    /* Configure the value of the polynomial for the CRC calculation. */
    CRC_SetPolynomial(base, psConfig->u32CrcPolynomial);

    /* Write the CRC seed value. */
    CRC_SetSeedValue(base, psConfig->u32CrcSeedValue);
}

void CRC_Deinit(CRC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* gate clock */
    CLOCK_DisableClock(s_crcClockName[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
/*!
 * brief Writes data to the CRC module.
 *
 * Writes input data buffer bytes to the CRC data register.
 * The configured type of transpose is applied.
 *
 * param base           CRC peripheral address.
 * param pu8Data        Input data stream, MSByte in data[0].
 * param u32u32DataSize Size in bytes of the input data buffer.
 */
void CRC_WriteData(CRC_Type *base, const uint8_t *pu8Data, uint32_t u32DataSize)
{
    const uint32_t *pu32Data;

    /* 8-bit reads and writes till source address is aligned 4 bytes */
    while ((u32DataSize != 0UL) && (((uint32_t)(const uint8_t *)pu8Data) & 3UL) != 0UL)
    {
#if defined(FSL_FEATURE_CRC_HAS_CRC_REGISTER) && FSL_FEATURE_CRC_HAS_CRC_REGISTER
        base->CRC8 = *pu8Data;
#else
        base->DATA8  = *pu8Data;
#endif
        pu8Data++;
        u32DataSize--;
    }

    /* use 32-bit reads and writes as long as possible */
    pu32Data = (const uint32_t *)(const void *)pu8Data;
    while (u32DataSize >= sizeof(uint32_t))
    {
#if defined(FSL_FEATURE_CRC_HAS_CRC_REGISTER) && FSL_FEATURE_CRC_HAS_CRC_REGISTER
        base->CRC32 = *pu32Data;
#else
        base->DATA32 = *pu32Data;
#endif
        pu32Data++;
        u32DataSize -= sizeof(uint32_t);
    }

    pu8Data = (const uint8_t *)pu32Data;

    /* 8-bit reads and writes till end of data buffer */
    while (u32DataSize != 0U)
    {
#if defined(FSL_FEATURE_CRC_HAS_CRC_REGISTER) && FSL_FEATURE_CRC_HAS_CRC_REGISTER
        base->CRC8 = *pu8Data;
#else
        base->DATA8  = *pu8Data;
#endif
        pu8Data++;
        u32DataSize--;
    }
}

/*!
 * brief Reads a 16-bit checksum from the CRC module.
 *
 * Reads the CRC data register (either an intermediate or the final checksum).
 * The configured type of transpose and complement is applied.
 *
 * param base CRC peripheral address.
 * return An intermediate or the final 16-bit checksum, after transpose and complement operations configured.
 */
uint16_t CRC_Get16bitResult(CRC_Type *base)
{
    uint32_t u32CrcValue;
    uint32_t u32Totr;

#if defined(FSL_FEATURE_CRC_HAS_CRC_REGISTER) && FSL_FEATURE_CRC_HAS_CRC_REGISTER
    u32CrcValue = base->CRC32;
#else
    u32CrcValue = base->DATA32;
#endif

    /* type of transpose read bitfield */
    u32Totr = (base->CTRL & CRC_CTRL_TOTR_MASK) >> CRC_CTRL_TOTR_SHIFT;

    /* check transpose type to get 16-bit out of 32-bit register */
    if ((u32Totr == (uint32_t)kCRC_TransposeBitsAndBytes) || (u32Totr == (uint32_t)kCRC_TransposeBytes))
    {
        /* transpose of bytes for read is set, the result CRC is in CRC_DATA[HU:HL] */
        u32CrcValue &= 0xFFFF0000U;
        u32CrcValue = u32CrcValue >> 16U;
    }
    else
    {
        /* no transpose of bytes for read, the result CRC is in CRC_DATA[LU:LL] */
        u32CrcValue &= 0x0000FFFFU;
    }
    return (uint16_t)u32CrcValue;
}
