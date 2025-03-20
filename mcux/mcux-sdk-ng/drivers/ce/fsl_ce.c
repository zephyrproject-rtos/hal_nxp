/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Implementation file for CE wrapper/driver functions on ARM
==========================================================================*/

#include "fsl_clock.h"
#include "fsl_mu.h"
#include "fsl_ce.h"

void CE_Init(ce_copy_image_t *ceCopyImage)
{
    assert(ceCopyImage->destAddr == CE_STCM5_BASE || ceCopyImage->destAddr == CE_STCM6_BASE ||
           ceCopyImage->destAddr == CE_STCM7_BASE);

    CE_InstallFirmware(ceCopyImage);
    CE_InitWithoutFirmware();

    switch (ceCopyImage->destAddr)
    {
        case CE_STCM5_BASE:
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM5);
            break;
        case CE_STCM6_BASE:
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM6);
            break;
        case CE_STCM7_BASE:
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM7);
            break;
        default:
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM5);
            break;
    }
}

void CE_InstallFirmware(ce_copy_image_t *ceCopyImage)
{
    uint32_t dstAddr;
    uint32_t srcAddr;
    uint32_t size;

    assert(ceCopyImage != NULL);
    assert(ceCopyImage->srcAddr != 0U);
    assert(ceCopyImage->destAddr != 0U);
    assert(ceCopyImage->size != 0U);

    dstAddr = ceCopyImage->destAddr;
    srcAddr = ceCopyImage->srcAddr;
    size    = ceCopyImage->size;

    memcpy((void *)(uint32_t *)dstAddr, (const void *)(uint32_t *)srcAddr, size);
}

void CE_InitWithoutFirmware(void)
{
    CLOCK_EnableClock(kCLOCK_DSP0);
    CLOCK_EnableClock(kCLOCK_DSP0_MUA);

    MU_Init(MUA);
}
