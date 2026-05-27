/*
 * Copyright 2024-2026 NXP
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

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.ce"
#endif

/*!
 * brief Initializes the CE.
 *
 * param [in] ceCopyImage The information about the CE image to copy.
 */
void CE_Init(ce_copy_image_t *ceCopyImage)
{
#if (defined(KW47_core0_SERIES) || defined(MCXW72_core0_SERIES))
    assert(ceCopyImage->destAddr == CE_STCM5_BASE || ceCopyImage->destAddr == CE_STCM6_BASE ||
           ceCopyImage->destAddr == CE_STCM7_BASE);

    CE_InstallFirmware(ceCopyImage);
#elif (defined(KW43_core0_SERIES) || defined(MCXW70_core0_SERIES))
    assert(NULL != ceCopyImage);
    assert(0U != ceCopyImage->destAddr);

    CE_InstallFirmware(ceCopyImage);
#endif

    CE_InitWithoutFirmware();

#if (defined(KW47_core0_SERIES) || defined(MCXW72_core0_SERIES))
    /*
     * $Branch Coverage Justification$
     * The CE images released in the SDK use the STCM6 as the stack and the STCM7 as the data RAM.
     * In this case, the CE core cannot boot from the STCM6 and STCM7.
     */
    switch (ceCopyImage->destAddr) /* GCOVR_EXCL_BR_LINE */
    {
        case CE_STCM5_BASE:
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM5);
            break;
        case CE_STCM6_BASE: /* GCOVR_EXCL_START */
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM6);
            break;
        case CE_STCM7_BASE:
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM7);
            break;
        default:
            MU_BootOtherCore(MUA, kMU_CoreBootFromSTCM5);
            break;
    } /* GCOVR_EXCL_STOP */
#elif (defined(KW43_core0_SERIES) || defined(MCXW70_core0_SERIES))
    /* By default, TRDC configuration does not enable the DSP's master permissions.
     * This statement configures the DSP's DID (Domain ID) and its Secure/Non-secure
     * attributes. Additionally, since there is PRESET data, the ROM has already
     * configured SRAM access permissions, but these permissions are mapped to a
     * specific DID. Therefore, it's necessary to configure the DSP's DID in TRDC
     * to match the DID that has SRAM access permissions. */
    TRDC_0_MGR->MDA_DFMT0[6].MDA_W_DFMT0[0] = 0x80000011;
    /* Unlock SYSCON */
    SYSCON->AUTHENTICATE = SYSCON_UNLOCK_CODE;
    /* Set ZENV vector start address */
    SYSCON->ZENV_CTRL = ceCopyImage->destAddr;
    /* Release reset of ZENV CORE */
    SYSCON->ZENV_RESET_CTRL = 0UL;
    /* Lock SYSCON again */
    SYSCON->AUTHENTICATE = 0UL;
#endif
}

/*!
 * brief Installs CE firmware by given image info
 *
 * param [in] ceCopyImage The information about the CE image to copy.
 */
void CE_InstallFirmware(ce_copy_image_t *ceCopyImage)
{
#if (defined(KW47_core0_SERIES) || defined(MCXW72_core0_SERIES) || defined(KW43_core0_SERIES) || defined(MCXW70_core0_SERIES))
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

    (void)memcpy((void *)(uint32_t *)dstAddr, (const void *)(uint32_t *)srcAddr, size);
#endif
}

/*!
 * brief Initializes the CE.
 *
 * details This function is similar to CE_Init, but it does not install
 * the firmware, the firmware can be installed using CE_InstallFirmware.
 */
void CE_InitWithoutFirmware(void)
{
#if (defined(KW47_core0_SERIES) || defined(MCXW72_core0_SERIES))
    CLOCK_EnableClock(kCLOCK_DSP0);
    CLOCK_EnableClock(kCLOCK_DSP0_MUA);

    MU_Init(MUA);
#elif (defined(KW43_core0_SERIES) || defined(MCXW70_core0_SERIES))
    /* Enable DSP RAM clock */
    CLOCK_EnableClock(kCLOCK_Dsp_ramc0);
    /* Enable LCE clock */
    CLOCK_EnableClock(kCLOCK_Zenv_core);
    /*Enable MU clock */
    CLOCK_EnableClock(kCLOCK_Mu1);

    MU_Init(MU1_MUA);
#endif
}
