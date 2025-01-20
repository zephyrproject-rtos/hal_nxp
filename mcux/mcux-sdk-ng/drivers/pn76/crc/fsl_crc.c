/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_crc.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_crc"
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*!
 * brief   Enables the CRC peripheral module.
 *
 * This function enables the clock gate for the CRC peripheral.
 * param base     CRC peripheral address.
 */
void CRC_Init(CRC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* ungate clock */
    CLOCK_EnableClock(kCLOCK_Crc);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Disables the CRC peripheral module.
 *
 * This function disables the clock gate for the CRC peripheral.
 * param base     CRC peripheral address.
 */
void CRC_Deinit(CRC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* gate clock */
    CLOCK_DisableClock(kCLOCK_Crc);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Provide default CRC protocol configuration.
 *
 * The purpose of this API is to initialize the configuration structure to default value for
 * CRC_SetConfig to use. Provides the configuration of commonly used CRC protocols. refer to
 * crc_type_t.
 *
 * param config     CRC protocol configuration structure.
 */
void CRC_GetDefaultConfig(crc_config_t *config)
{
    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));
    config->crcEnable = true;
    config->crcMode   = kCRC_Crc16;
    config->crcEndian = kCRC_LsbFirst;
}

/*!
 * brief Configures the CRC peripheral module.
 *
 * This function configures the CRC module and starts a checksum computation by writing the seed.
 *
 * param base     CRC peripheral address.
 * param config   CRC module configuration structure.
 */
void CRC_SetConfig(CRC_Type *base, const crc_config_t *config)
{
    if (config->crcEnable == true)
    {
        base->CONTROL = (uint32_t)config->crcMode | (uint32_t)config->crcEndian | (uint32_t)config->crcEnable;
    }
    else
    {
        base->CONTROL = 0UL;
    }
}

/*!
 * brief Set CRC type of transpose of write data.
 *
 * This function writes data to CRC.
 *
 * param base      CRC peripheral address.
 * param buffer    data message to be checked.
 * param len       length of buffer.
 */
void CRC_WriteData(CRC_Type *base, const uint8_t *buffer, uint32_t len)
{
    const uint8_t *bufEnd = buffer + len;
    if ((base->CONTROL & CRC_CONTROL_CRCINV_MASK) != 0U)
    {
        while (len > 0U)
        {
            if ((((uint32_t)buffer & 3U) == 0U) && (len >= (uint32_t)sizeof(uint32_t)))
            {
                /* uint32_t word aligned data goes here... */
                base->DAT32 = *(const uint32_t *)(const void *)buffer;
                buffer += sizeof(uint32_t);
                len -= sizeof(uint32_t);
            }
            else
            {
                /* ... unaligned data or remaining 1-3 bytes here */
                base->DAT8 = *buffer;
                buffer++;
                len--;
            }
        }
    }
    else
    {
        while (buffer < bufEnd)
        {
            base->DAT8 = *buffer;
            buffer++;
        }
    }
}
