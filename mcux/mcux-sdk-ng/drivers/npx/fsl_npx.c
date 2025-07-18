/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_npx.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.npx"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint64_t npx_find_subregions_for_range(uint32_t startAddr, uint32_t endAddr)
{
    uint64_t srEnableRegister = 0;

    /* Align startAddr down to 32k */
    startAddr &= 0xFFFF8000u;

    for (uint32_t i = 0u; i<64u; i++)
    {
        if ((startAddr >= (NPX_SUBREGION_SIZE_IN_BYTES * i)) && (startAddr < (NPX_SUBREGION_SIZE_IN_BYTES * (i + 1U))))
        {
            srEnableRegister |= ((uint64_t)1u << i);
            startAddr += NPX_SUBREGION_SIZE_IN_BYTES;
        }
        if (startAddr > endAddr)
        {
            break;
        }
    }

    return srEnableRegister;
}
/*!
 * brief Returns the NPX region context status.
 *
 * This function returns status of NPX region.
 *
 * param base NPX peripheral address.
 * param region Selection of the NPX region to check the status.
 */
status_t NPX_GetContextStatus(NPX_Type *base, npx_region_t region)
{
    status_t retVal = kStatus_Fail;

    if ((base->NPXSR & (NPX_NPXSR_V0_MASK << region)) != 0u)
    {
        retVal = kStatus_Success;
    }

    return retVal;
}

/*!
 * brief Sets the NPX Region.
 *
 * This function configures NPX region.
 *
 * param base NPX peripheral address.
 * param region Selection of the NPX region to be configured.
 * param config Configuration structure for NPX.
 */
status_t NPX_SetRegion(NPX_Type *base, npx_region_t region, npx_region_config_t config)
{
    status_t status = kStatus_Fail;
    
    /* Check for correct regionNumber */
    if (region > kNPX_Region3)
    {
        return kStatus_InvalidArgument;
    }

    size_t regionLength = (config.endAddress - config.startAddress) + 1u;
    
    /* Check validity of startAddress and endAddress */
    if ((config.startAddress > config.endAddress) || (regionLength > NPX_MAX_REGION_SIZE_IN_BYTES) || (regionLength < NPX_SUBREGION_SIZE_IN_BYTES))
     {
     return kStatus_Fail;
    }

    /* Check if startAddress and endAddress is aligned to 32k - startAddr must be always 0xx000 and endAddress 0xxFFF */
   if (((config.startAddress & (NPX_SUBREGION_SIZE_IN_BYTES - 1u)) > 0u) || (((config.endAddress + 1u) & (NPX_SUBREGION_SIZE_IN_BYTES - 1u)) > 0u))
      {
      return kStatus_Fail;
     }
    
    /* Generate sub-region enable register value */
    uint64_t srEnableRegister = npx_find_subregions_for_range(config.startAddress, config.endAddress);
    
    /* Make sure that NPX region is not locked before writing to VMAPCTX_WD registers */
    if ((base->NPXCR & (NPX_NPXCR_CTX0LK_MASK << (region * 2u))) != 0u)
    {
        status = kStatus_NPX_RegionIsLocked;
    }
    else
    {
        base->CTX_VALID_IV_ARRAY[region].VMAPCTX_WD[0] = srEnableRegister & 0xffffffffu;
        base->CTX_VALID_IV_ARRAY[region].VMAPCTX_WD[1] = srEnableRegister >> 32u;
        config.subRegionEnable = srEnableRegister;
        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Sets the NPX Sub-Region Enable register.
 *
 * This function configures NPX SR_ENABLE register.
 *
 * param base NPX peripheral address.
 * param region Selection of the NPX region to be configured.
 * param sr_enable Sub-Region Enable register value.
 */
status_t NPX_SetRegionSREnable(NPX_Type *base, npx_region_t region, uint64_t sr_enable)
{
    status_t status = kStatus_Fail;

    if (region > kNPX_Region3)
    {
        return kStatus_InvalidArgument;
    }
    /* Make sure that NPX region is not locked before writing to VMAPCTX_WD registers */
    else if ((base->NPXCR & (NPX_NPXCR_CTX0LK_MASK << (region * 2u))) != 0u)
    {
        status = kStatus_NPX_RegionIsLocked;
    }
    else
    {
        base->CTX_VALID_IV_ARRAY[region].VMAPCTX_WD[0] = sr_enable & 0xffffffffu;
        base->CTX_VALID_IV_ARRAY[region].VMAPCTX_WD[1] = sr_enable >> 32u;
        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Gets the NPX Sub-Region Enable register.
 *
 * This function gets NPX SR_ENABLE register.
 *
 * param base NPX peripheral address.
 * param region Selection of the NPX region.
 * param sr_enable Sub-Region Enable register pointer.
 */
status_t NPX_GetRegionSREnable(NPX_Type *base, npx_region_t region, uint64_t *sr_enable)
{
    status_t status = kStatus_Fail;

    if (region > kNPX_Region3)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        *sr_enable = base->CTX_VALID_IV_ARRAY[region].VMAPCTX_WD[0];
        *sr_enable |= (uint64_t)(base->CTX_VALID_IV_ARRAY[region].VMAPCTX_WD[1]) << 32u;
        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Sets the NPX region IV.
 *
 * This function sets specified AES IV for the given region.
 *
 * param base NPX peripheral address.
 * param region Selection of the NPX region to be configured.
 * param iv 64-bit AES IV in little-endian byte order.
 */
status_t NPX_SetRegionIV(NPX_Type *base, npx_region_t region, const uint8_t iv[8])
{
    status_t status = kStatus_Fail;

    if (region > kNPX_Region3)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        base->CTX_VALID_IV_ARRAY[region].BIVCTX_WD[0] = ((uint32_t *)(uintptr_t)iv)[0];
        base->CTX_VALID_IV_ARRAY[region].BIVCTX_WD[1] = ((uint32_t *)(uintptr_t)iv)[1];
        status = kStatus_Success;
    }

    return status;
}
