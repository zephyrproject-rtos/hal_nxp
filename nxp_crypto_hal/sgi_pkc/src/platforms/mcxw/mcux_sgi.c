/*
 *     Copyright 2026 NXP
 *     All rights reserved.
 *
 *     SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_sgi.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief SGI Init after power down.
 *
 * This function enable all SGI related clocks, enable SGI and enables other needed HW used by SGI crypto library.
 *
 * param base SGI peripheral address.
 *
 * return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t SGI_PowerDownWakeupInit(SGI_Type *base)
{
    status_t status = kStatus_Fail;

    /* Enable SGI and TRNG clock */
    CLOCK_EnableClock(kCLOCK_Sgi0);

    /* Initialiaze TRNG which is used by SGI PKC crypto library */
    trng_config_t trngcon;
    status = TRNG_GetDefaultConfig(&trngcon);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = TRNG_Init(TRNG0, &trngcon);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Initialiaze CRC which is used by SGI PKC crypto library */
    crc_config_t config;
    CRC_GetDefaultConfig(&config);
    CRC_Init(CRC0, &config);

    return status;
}