/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_ieer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.ieer"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Clears the IEER Memory Region Descriptors.
 *
 * This function clears IEER Memory Region Descriptors to reset values.
 *
 * param base IEER peripheral address.
 */
void IEER_Init(IEER_Type *base)
{
    ieer_config_t ieerConfig;

    IEER_GetDefaultConfig(&ieerConfig);

    for (ieer_region_t region = kIEER_Region0; region <= kIEER_Region3; region++)
    {
        IEER_SetRegionConfig(base, region, &ieerConfig);
    }
}

/*!
 * brief Sets the IEER Memory Region Descriptors.
 *
 * This function configures IEER Memory Region Descriptor according to region configuration structure.
 *
 * param base IEER peripheral address.
 * param region Selection of the IEER region to be configured.
 * param config Configuration for the selected IEER region.
 */
void IEER_SetRegionConfig(IEER_Type *base, ieer_region_t region, ieer_config_t *config)
{
    base->MRGDJ[region].MRGD_W0 = IEER_MRGD_W0_SRTADDR(config->startaddr);
    base->MRGDJ[region].MRGD_W2 = IEER_MRGD_W2_ENDADDR(config->endaddr);
    base->MRGDJ[region].MRGD_W4 = IEER_MRGD_W4_VLD(config->valid) | IEER_MRGD_W4_RMSG(config->rmsg);
}

/*!
 * brief Loads default values to the IEER memory region configuration structure.
 *
 * Loads default values to the IEER memory region configuration structure. The default values are as follows.
 * code
 *   config->startaddr = 0;
 *   config->endaddr = 0x00000FFFU;
 *   config->rmsg = 0;
 *   config->valid = false;
 * endcode
 *
 * param config Configuration for the selected IEER region.
 */
void IEER_GetDefaultConfig(ieer_config_t *config)
{
    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    static const ieer_config_t myConfig = {0, 0x00000FFFU, 0, false};

    *config = myConfig;
}
