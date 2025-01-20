/*
 * The Clear BSD License
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2021 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_mpu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t MPU_Deinit(MPU_Type *base)
{
    uint32_t regionCount = MpuRegionCount(base);
    uint32_t regionNum;

    /* Disable MPU. */
    base->CTRL = 0;
    for (regionNum = 0; regionNum < regionCount; regionNum++)
    {
        /* Clear all configurations*/
        base->RNR  = regionNum;
        base->RBAR = 0;
        base->RLAR = 0;
    }
    base->RNR   = 0;
    base->MAIR0 = 0;
    return kStatus_Success;
}

status_t MPU_Init(MPU_Type *base, const mpu_region_config_t config[], uint32_t regionCount, uint32_t control)
{
    status_t result = kStatus_Fail;

    if (control > 7U)
    {
        /* Wrong control word for MPU_CTRL register (PRIVDEFENA, HFNMIENA, ENABLE bits). */
        return kStatus_InvalidArgument;
    }
    /* Force any outstanding transfers to complete before disabling MPU */
    __DMB();
    if (config != NULL)
    {
        if ((regionCount == 0) || (regionCount > MpuRegionCount(base)))
        {
            /* Regions not defined or more regions than allowed by MPU. */
            return kStatus_InvalidArgument;
        }

        /* Disable MPU. */
        base->CTRL  = 0U;
        base->MAIR0 = /* MAIR0.Attr0 = kMPU_NormalMemory_WTTRA, (Recommended settings for MCU Internal Memory) */
            ((((kMPU_NormalMemory_WTTRA << MPU_MAIR_OuterAttr_Pos) |
               (kMPU_NormalMemory_WTTRA << MPU_MAIR_InnerAttr_Pos))
              << MPU_MAIR0_Attr0_Pos) &
             MPU_MAIR0_Attr0_Msk) |
            /* MAIR0.Attr1 = kMPU_DeviceMemory_nGnRnE, (Peripheral Internal Memory) */
            ((kMPU_DeviceMemory_nGnRnE << MPU_MAIR0_Attr1_Pos) & MPU_MAIR0_Attr1_Msk);
        for (uint32_t i = 0U; i < regionCount; i++)
        {
            if (config[i].regionNum >= MpuRegionCount(base))
            {
                /* MPU region index should not over the regions count. */
                return kStatus_InvalidArgument;
            }
            /* Select the MPU region. */
            base->RNR = config[i].regionNum;

            if ((config[i].sizeInBytes < kMPU_MinRegionSizeInBytesARMv8m) |
                (config[i].sizeInBytes % kMPU_MinRegionSizeInBytesARMv8m))
            {
                /* The smallest permitted region size is 32B and region must be 32B aligned */
                return kStatus_InvalidArgument;
            }
            if (config[i].baseAddress % kMPU_MinRegionSizeInBytesARMv8m)
            {
                /* The base address must be aligned to the minimal size of the region */
                return kStatus_InvalidArgument;
            }
            /* Region base address */
            base->RBAR = (config[i].baseAddress & MPU_RBAR_BASE_Msk) |
                         /* Access attribute */
                         (config[i].accessAttribute & ~MPU_RBAR_BASE_Msk);
            /* Region end address */
            base->RLAR = ((config[i].baseAddress + config[i].sizeInBytes - 1) & MPU_RLAR_LIMIT_Msk) |
                         /* Region memory attribute index */
                         ((config[i].regionAttributeIndex << MPU_RLAR_AttrIndx_Pos) & MPU_RLAR_AttrIndx_Msk) |
                         /* Enable region */
                         ((1U << MPU_RLAR_EN_Pos) & MPU_RLAR_EN_Msk);
        }
        result = kStatus_Success;
    }
    /* Set control word. */
    base->CTRL = control;
    /* Force memory writes before continuing */
    __DSB();
    /* Flush and refill pipeline with updated permissions */
    __ISB();
    return result;
}
